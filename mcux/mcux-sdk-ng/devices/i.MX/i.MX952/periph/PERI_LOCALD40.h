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
**         CMSIS Peripheral Access Layer for locald40
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
 * @file PERI_locald40.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald40
 *
 * CMSIS Peripheral Access Layer for locald40
 */

#if !defined(PERI_LOCALD40_H_)
#define PERI_LOCALD40_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald40 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald40_Peripheral_Access_Layer locald40 Peripheral Access Layer
 * @{
 */

/** locald40 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR1A0;                          /**< ldprofilereg1a0, offset: 0x0 */
  __IO uint32_t LDPRR1A1;                          /**< ldprofilereg1a1, offset: 0x4 */
  __IO uint32_t LDPRR1A2;                          /**< ldprofilereg1a2, offset: 0x8 */
  __IO uint32_t LDPRR1A3;                          /**< ldprofilereg1a3, offset: 0xC */
  __IO uint32_t LDPRR1A4;                          /**< ldprofilereg1a4, offset: 0x10 */
  __IO uint32_t LDPRR1A5;                          /**< ldprofilereg1a5, offset: 0x14 */
  __IO uint32_t LDPRR1A6;                          /**< ldprofilereg1a6, offset: 0x18 */
  __IO uint32_t LDPRR1A7;                          /**< ldprofilereg1a7, offset: 0x1C */
  __IO uint32_t LDPRR1A8;                          /**< ldprofilereg1a8, offset: 0x20 */
  __IO uint32_t LDPRR1A9;                          /**< ldprofilereg1a9, offset: 0x24 */
  __IO uint32_t LDPRR1AA;                          /**< ldprofilereg1aa, offset: 0x28 */
  __IO uint32_t LDPRR1AB;                          /**< ldprofilereg1ab, offset: 0x2C */
  __IO uint32_t LDPRR1AC;                          /**< ldprofilereg1ac, offset: 0x30 */
  __IO uint32_t LDPRR1AD;                          /**< ldprofilereg1ad, offset: 0x34 */
  __IO uint32_t LDPRR1AE;                          /**< ldprofilereg1ae, offset: 0x38 */
  __IO uint32_t LDPRR1AF;                          /**< ldprofilereg1af, offset: 0x3C */
  __IO uint32_t LDPRR1B0;                          /**< ldprofilereg1b0, offset: 0x40 */
  __IO uint32_t LDPRR1B1;                          /**< ldprofilereg1b1, offset: 0x44 */
  __IO uint32_t LDPRR1B2;                          /**< ldprofilereg1b2, offset: 0x48 */
  __IO uint32_t LDPRR1B3;                          /**< ldprofilereg1b3, offset: 0x4C */
  __IO uint32_t LDPRR1B4;                          /**< ldprofilereg1b4, offset: 0x50 */
  __IO uint32_t LDPRR1B5;                          /**< ldprofilereg1b5, offset: 0x54 */
  __IO uint32_t LDPRR1B6;                          /**< ldprofilereg1b6, offset: 0x58 */
  __IO uint32_t LDPRR1B7;                          /**< ldprofilereg1b7, offset: 0x5C */
} locald40_Type;

/* ----------------------------------------------------------------------------
   -- locald40 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald40_Register_Masks locald40 Register Masks
 * @{
 */

/*! @name LDPRR1A0 - ldprofilereg1a0 */
/*! @{ */

#define locald40_LDPRR1A0_lumd625_MASK           (0x3FFU)
#define locald40_LDPRR1A0_lumd625_SHIFT          (0U)
/*! lumd625 - lumdat_625 */
#define locald40_LDPRR1A0_lumd625(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A0_lumd625_SHIFT)) & locald40_LDPRR1A0_lumd625_MASK)

#define locald40_LDPRR1A0_lumd624_MASK           (0x3FF0000U)
#define locald40_LDPRR1A0_lumd624_SHIFT          (16U)
/*! lumd624 - lumdat_624 */
#define locald40_LDPRR1A0_lumd624(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A0_lumd624_SHIFT)) & locald40_LDPRR1A0_lumd624_MASK)
/*! @} */

/*! @name LDPRR1A1 - ldprofilereg1a1 */
/*! @{ */

#define locald40_LDPRR1A1_lumd627_MASK           (0x3FFU)
#define locald40_LDPRR1A1_lumd627_SHIFT          (0U)
/*! lumd627 - lumdat_627 */
#define locald40_LDPRR1A1_lumd627(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A1_lumd627_SHIFT)) & locald40_LDPRR1A1_lumd627_MASK)

#define locald40_LDPRR1A1_lumd626_MASK           (0x3FF0000U)
#define locald40_LDPRR1A1_lumd626_SHIFT          (16U)
/*! lumd626 - lumdat_626 */
#define locald40_LDPRR1A1_lumd626(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A1_lumd626_SHIFT)) & locald40_LDPRR1A1_lumd626_MASK)
/*! @} */

/*! @name LDPRR1A2 - ldprofilereg1a2 */
/*! @{ */

#define locald40_LDPRR1A2_lumd629_MASK           (0x3FFU)
#define locald40_LDPRR1A2_lumd629_SHIFT          (0U)
/*! lumd629 - lumdat_629 */
#define locald40_LDPRR1A2_lumd629(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A2_lumd629_SHIFT)) & locald40_LDPRR1A2_lumd629_MASK)

#define locald40_LDPRR1A2_lumd628_MASK           (0x3FF0000U)
#define locald40_LDPRR1A2_lumd628_SHIFT          (16U)
/*! lumd628 - lumdat_628 */
#define locald40_LDPRR1A2_lumd628(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A2_lumd628_SHIFT)) & locald40_LDPRR1A2_lumd628_MASK)
/*! @} */

/*! @name LDPRR1A3 - ldprofilereg1a3 */
/*! @{ */

#define locald40_LDPRR1A3_lumd631_MASK           (0x3FFU)
#define locald40_LDPRR1A3_lumd631_SHIFT          (0U)
/*! lumd631 - lumdat_631 */
#define locald40_LDPRR1A3_lumd631(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A3_lumd631_SHIFT)) & locald40_LDPRR1A3_lumd631_MASK)

#define locald40_LDPRR1A3_lumd630_MASK           (0x3FF0000U)
#define locald40_LDPRR1A3_lumd630_SHIFT          (16U)
/*! lumd630 - lumdat_630 */
#define locald40_LDPRR1A3_lumd630(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A3_lumd630_SHIFT)) & locald40_LDPRR1A3_lumd630_MASK)
/*! @} */

/*! @name LDPRR1A4 - ldprofilereg1a4 */
/*! @{ */

#define locald40_LDPRR1A4_lumd633_MASK           (0x3FFU)
#define locald40_LDPRR1A4_lumd633_SHIFT          (0U)
/*! lumd633 - lumdat_633 */
#define locald40_LDPRR1A4_lumd633(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A4_lumd633_SHIFT)) & locald40_LDPRR1A4_lumd633_MASK)

#define locald40_LDPRR1A4_lumd632_MASK           (0x3FF0000U)
#define locald40_LDPRR1A4_lumd632_SHIFT          (16U)
/*! lumd632 - lumdat_632 */
#define locald40_LDPRR1A4_lumd632(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A4_lumd632_SHIFT)) & locald40_LDPRR1A4_lumd632_MASK)
/*! @} */

/*! @name LDPRR1A5 - ldprofilereg1a5 */
/*! @{ */

#define locald40_LDPRR1A5_lumd635_MASK           (0x3FFU)
#define locald40_LDPRR1A5_lumd635_SHIFT          (0U)
/*! lumd635 - lumdat_635 */
#define locald40_LDPRR1A5_lumd635(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A5_lumd635_SHIFT)) & locald40_LDPRR1A5_lumd635_MASK)

#define locald40_LDPRR1A5_lumd634_MASK           (0x3FF0000U)
#define locald40_LDPRR1A5_lumd634_SHIFT          (16U)
/*! lumd634 - lumdat_634 */
#define locald40_LDPRR1A5_lumd634(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A5_lumd634_SHIFT)) & locald40_LDPRR1A5_lumd634_MASK)
/*! @} */

/*! @name LDPRR1A6 - ldprofilereg1a6 */
/*! @{ */

#define locald40_LDPRR1A6_lumd637_MASK           (0x3FFU)
#define locald40_LDPRR1A6_lumd637_SHIFT          (0U)
/*! lumd637 - lumdat_637 */
#define locald40_LDPRR1A6_lumd637(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A6_lumd637_SHIFT)) & locald40_LDPRR1A6_lumd637_MASK)

#define locald40_LDPRR1A6_lumd636_MASK           (0x3FF0000U)
#define locald40_LDPRR1A6_lumd636_SHIFT          (16U)
/*! lumd636 - lumdat_636 */
#define locald40_LDPRR1A6_lumd636(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A6_lumd636_SHIFT)) & locald40_LDPRR1A6_lumd636_MASK)
/*! @} */

/*! @name LDPRR1A7 - ldprofilereg1a7 */
/*! @{ */

#define locald40_LDPRR1A7_lumd639_MASK           (0x3FFU)
#define locald40_LDPRR1A7_lumd639_SHIFT          (0U)
/*! lumd639 - lumdat_639 */
#define locald40_LDPRR1A7_lumd639(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A7_lumd639_SHIFT)) & locald40_LDPRR1A7_lumd639_MASK)

#define locald40_LDPRR1A7_lumd638_MASK           (0x3FF0000U)
#define locald40_LDPRR1A7_lumd638_SHIFT          (16U)
/*! lumd638 - lumdat_638 */
#define locald40_LDPRR1A7_lumd638(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A7_lumd638_SHIFT)) & locald40_LDPRR1A7_lumd638_MASK)
/*! @} */

/*! @name LDPRR1A8 - ldprofilereg1a8 */
/*! @{ */

#define locald40_LDPRR1A8_lumd641_MASK           (0x3FFU)
#define locald40_LDPRR1A8_lumd641_SHIFT          (0U)
/*! lumd641 - lumdat_641 */
#define locald40_LDPRR1A8_lumd641(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A8_lumd641_SHIFT)) & locald40_LDPRR1A8_lumd641_MASK)

#define locald40_LDPRR1A8_lumd640_MASK           (0x3FF0000U)
#define locald40_LDPRR1A8_lumd640_SHIFT          (16U)
/*! lumd640 - lumdat_640 */
#define locald40_LDPRR1A8_lumd640(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A8_lumd640_SHIFT)) & locald40_LDPRR1A8_lumd640_MASK)
/*! @} */

/*! @name LDPRR1A9 - ldprofilereg1a9 */
/*! @{ */

#define locald40_LDPRR1A9_lumd643_MASK           (0x3FFU)
#define locald40_LDPRR1A9_lumd643_SHIFT          (0U)
/*! lumd643 - lumdat_643 */
#define locald40_LDPRR1A9_lumd643(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A9_lumd643_SHIFT)) & locald40_LDPRR1A9_lumd643_MASK)

#define locald40_LDPRR1A9_lumd642_MASK           (0x3FF0000U)
#define locald40_LDPRR1A9_lumd642_SHIFT          (16U)
/*! lumd642 - lumdat_642 */
#define locald40_LDPRR1A9_lumd642(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1A9_lumd642_SHIFT)) & locald40_LDPRR1A9_lumd642_MASK)
/*! @} */

/*! @name LDPRR1AA - ldprofilereg1aa */
/*! @{ */

#define locald40_LDPRR1AA_lumd645_MASK           (0x3FFU)
#define locald40_LDPRR1AA_lumd645_SHIFT          (0U)
/*! lumd645 - lumdat_645 */
#define locald40_LDPRR1AA_lumd645(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AA_lumd645_SHIFT)) & locald40_LDPRR1AA_lumd645_MASK)

#define locald40_LDPRR1AA_lumd644_MASK           (0x3FF0000U)
#define locald40_LDPRR1AA_lumd644_SHIFT          (16U)
/*! lumd644 - lumdat_644 */
#define locald40_LDPRR1AA_lumd644(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AA_lumd644_SHIFT)) & locald40_LDPRR1AA_lumd644_MASK)
/*! @} */

/*! @name LDPRR1AB - ldprofilereg1ab */
/*! @{ */

#define locald40_LDPRR1AB_lumd647_MASK           (0x3FFU)
#define locald40_LDPRR1AB_lumd647_SHIFT          (0U)
/*! lumd647 - lumdat_647 */
#define locald40_LDPRR1AB_lumd647(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AB_lumd647_SHIFT)) & locald40_LDPRR1AB_lumd647_MASK)

#define locald40_LDPRR1AB_lumd646_MASK           (0x3FF0000U)
#define locald40_LDPRR1AB_lumd646_SHIFT          (16U)
/*! lumd646 - lumdat_646 */
#define locald40_LDPRR1AB_lumd646(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AB_lumd646_SHIFT)) & locald40_LDPRR1AB_lumd646_MASK)
/*! @} */

/*! @name LDPRR1AC - ldprofilereg1ac */
/*! @{ */

#define locald40_LDPRR1AC_lumd649_MASK           (0x3FFU)
#define locald40_LDPRR1AC_lumd649_SHIFT          (0U)
/*! lumd649 - lumdat_649 */
#define locald40_LDPRR1AC_lumd649(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AC_lumd649_SHIFT)) & locald40_LDPRR1AC_lumd649_MASK)

#define locald40_LDPRR1AC_lumd648_MASK           (0x3FF0000U)
#define locald40_LDPRR1AC_lumd648_SHIFT          (16U)
/*! lumd648 - lumdat_648 */
#define locald40_LDPRR1AC_lumd648(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AC_lumd648_SHIFT)) & locald40_LDPRR1AC_lumd648_MASK)
/*! @} */

/*! @name LDPRR1AD - ldprofilereg1ad */
/*! @{ */

#define locald40_LDPRR1AD_lumd651_MASK           (0x3FFU)
#define locald40_LDPRR1AD_lumd651_SHIFT          (0U)
/*! lumd651 - lumdat_651 */
#define locald40_LDPRR1AD_lumd651(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AD_lumd651_SHIFT)) & locald40_LDPRR1AD_lumd651_MASK)

#define locald40_LDPRR1AD_lumd650_MASK           (0x3FF0000U)
#define locald40_LDPRR1AD_lumd650_SHIFT          (16U)
/*! lumd650 - lumdat_650 */
#define locald40_LDPRR1AD_lumd650(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AD_lumd650_SHIFT)) & locald40_LDPRR1AD_lumd650_MASK)
/*! @} */

/*! @name LDPRR1AE - ldprofilereg1ae */
/*! @{ */

#define locald40_LDPRR1AE_lumd653_MASK           (0x3FFU)
#define locald40_LDPRR1AE_lumd653_SHIFT          (0U)
/*! lumd653 - lumdat_653 */
#define locald40_LDPRR1AE_lumd653(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AE_lumd653_SHIFT)) & locald40_LDPRR1AE_lumd653_MASK)

#define locald40_LDPRR1AE_lumd652_MASK           (0x3FF0000U)
#define locald40_LDPRR1AE_lumd652_SHIFT          (16U)
/*! lumd652 - lumdat_652 */
#define locald40_LDPRR1AE_lumd652(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AE_lumd652_SHIFT)) & locald40_LDPRR1AE_lumd652_MASK)
/*! @} */

/*! @name LDPRR1AF - ldprofilereg1af */
/*! @{ */

#define locald40_LDPRR1AF_lumd655_MASK           (0x3FFU)
#define locald40_LDPRR1AF_lumd655_SHIFT          (0U)
/*! lumd655 - lumdat_655 */
#define locald40_LDPRR1AF_lumd655(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AF_lumd655_SHIFT)) & locald40_LDPRR1AF_lumd655_MASK)

#define locald40_LDPRR1AF_lumd654_MASK           (0x3FF0000U)
#define locald40_LDPRR1AF_lumd654_SHIFT          (16U)
/*! lumd654 - lumdat_654 */
#define locald40_LDPRR1AF_lumd654(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1AF_lumd654_SHIFT)) & locald40_LDPRR1AF_lumd654_MASK)
/*! @} */

/*! @name LDPRR1B0 - ldprofilereg1b0 */
/*! @{ */

#define locald40_LDPRR1B0_lumd657_MASK           (0x3FFU)
#define locald40_LDPRR1B0_lumd657_SHIFT          (0U)
/*! lumd657 - lumdat_657 */
#define locald40_LDPRR1B0_lumd657(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B0_lumd657_SHIFT)) & locald40_LDPRR1B0_lumd657_MASK)

#define locald40_LDPRR1B0_lumd656_MASK           (0x3FF0000U)
#define locald40_LDPRR1B0_lumd656_SHIFT          (16U)
/*! lumd656 - lumdat_656 */
#define locald40_LDPRR1B0_lumd656(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B0_lumd656_SHIFT)) & locald40_LDPRR1B0_lumd656_MASK)
/*! @} */

/*! @name LDPRR1B1 - ldprofilereg1b1 */
/*! @{ */

#define locald40_LDPRR1B1_lumd659_MASK           (0x3FFU)
#define locald40_LDPRR1B1_lumd659_SHIFT          (0U)
/*! lumd659 - lumdat_659 */
#define locald40_LDPRR1B1_lumd659(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B1_lumd659_SHIFT)) & locald40_LDPRR1B1_lumd659_MASK)

#define locald40_LDPRR1B1_lumd658_MASK           (0x3FF0000U)
#define locald40_LDPRR1B1_lumd658_SHIFT          (16U)
/*! lumd658 - lumdat_658 */
#define locald40_LDPRR1B1_lumd658(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B1_lumd658_SHIFT)) & locald40_LDPRR1B1_lumd658_MASK)
/*! @} */

/*! @name LDPRR1B2 - ldprofilereg1b2 */
/*! @{ */

#define locald40_LDPRR1B2_lumd661_MASK           (0x3FFU)
#define locald40_LDPRR1B2_lumd661_SHIFT          (0U)
/*! lumd661 - lumdat_661 */
#define locald40_LDPRR1B2_lumd661(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B2_lumd661_SHIFT)) & locald40_LDPRR1B2_lumd661_MASK)

#define locald40_LDPRR1B2_lumd660_MASK           (0x3FF0000U)
#define locald40_LDPRR1B2_lumd660_SHIFT          (16U)
/*! lumd660 - lumdat_660 */
#define locald40_LDPRR1B2_lumd660(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B2_lumd660_SHIFT)) & locald40_LDPRR1B2_lumd660_MASK)
/*! @} */

/*! @name LDPRR1B3 - ldprofilereg1b3 */
/*! @{ */

#define locald40_LDPRR1B3_lumd663_MASK           (0x3FFU)
#define locald40_LDPRR1B3_lumd663_SHIFT          (0U)
/*! lumd663 - lumdat_663 */
#define locald40_LDPRR1B3_lumd663(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B3_lumd663_SHIFT)) & locald40_LDPRR1B3_lumd663_MASK)

#define locald40_LDPRR1B3_lumd662_MASK           (0x3FF0000U)
#define locald40_LDPRR1B3_lumd662_SHIFT          (16U)
/*! lumd662 - lumdat_662 */
#define locald40_LDPRR1B3_lumd662(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B3_lumd662_SHIFT)) & locald40_LDPRR1B3_lumd662_MASK)
/*! @} */

/*! @name LDPRR1B4 - ldprofilereg1b4 */
/*! @{ */

#define locald40_LDPRR1B4_lumd665_MASK           (0x3FFU)
#define locald40_LDPRR1B4_lumd665_SHIFT          (0U)
/*! lumd665 - lumdat_665 */
#define locald40_LDPRR1B4_lumd665(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B4_lumd665_SHIFT)) & locald40_LDPRR1B4_lumd665_MASK)

#define locald40_LDPRR1B4_lumd664_MASK           (0x3FF0000U)
#define locald40_LDPRR1B4_lumd664_SHIFT          (16U)
/*! lumd664 - lumdat_664 */
#define locald40_LDPRR1B4_lumd664(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B4_lumd664_SHIFT)) & locald40_LDPRR1B4_lumd664_MASK)
/*! @} */

/*! @name LDPRR1B5 - ldprofilereg1b5 */
/*! @{ */

#define locald40_LDPRR1B5_lumd667_MASK           (0x3FFU)
#define locald40_LDPRR1B5_lumd667_SHIFT          (0U)
/*! lumd667 - lumdat_667 */
#define locald40_LDPRR1B5_lumd667(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B5_lumd667_SHIFT)) & locald40_LDPRR1B5_lumd667_MASK)

#define locald40_LDPRR1B5_lumd666_MASK           (0x3FF0000U)
#define locald40_LDPRR1B5_lumd666_SHIFT          (16U)
/*! lumd666 - lumdat_666 */
#define locald40_LDPRR1B5_lumd666(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B5_lumd666_SHIFT)) & locald40_LDPRR1B5_lumd666_MASK)
/*! @} */

/*! @name LDPRR1B6 - ldprofilereg1b6 */
/*! @{ */

#define locald40_LDPRR1B6_lumd669_MASK           (0x3FFU)
#define locald40_LDPRR1B6_lumd669_SHIFT          (0U)
/*! lumd669 - lumdat_669 */
#define locald40_LDPRR1B6_lumd669(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B6_lumd669_SHIFT)) & locald40_LDPRR1B6_lumd669_MASK)

#define locald40_LDPRR1B6_lumd668_MASK           (0x3FF0000U)
#define locald40_LDPRR1B6_lumd668_SHIFT          (16U)
/*! lumd668 - lumdat_668 */
#define locald40_LDPRR1B6_lumd668(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B6_lumd668_SHIFT)) & locald40_LDPRR1B6_lumd668_MASK)
/*! @} */

/*! @name LDPRR1B7 - ldprofilereg1b7 */
/*! @{ */

#define locald40_LDPRR1B7_lumd671_MASK           (0x3FFU)
#define locald40_LDPRR1B7_lumd671_SHIFT          (0U)
/*! lumd671 - lumdat_671 */
#define locald40_LDPRR1B7_lumd671(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B7_lumd671_SHIFT)) & locald40_LDPRR1B7_lumd671_MASK)

#define locald40_LDPRR1B7_lumd670_MASK           (0x3FF0000U)
#define locald40_LDPRR1B7_lumd670_SHIFT          (16U)
/*! lumd670 - lumdat_670 */
#define locald40_LDPRR1B7_lumd670(x)             (((uint32_t)(((uint32_t)(x)) << locald40_LDPRR1B7_lumd670_SHIFT)) & locald40_LDPRR1B7_lumd670_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald40_Register_Masks */


/*!
 * @}
 */ /* end of group locald40_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD40_H_ */

