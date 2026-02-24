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
**         CMSIS Peripheral Access Layer for locald62
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
 * @file PERI_locald62.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald62
 *
 * CMSIS Peripheral Access Layer for locald62
 */

#if !defined(PERI_LOCALD62_H_)
#define PERI_LOCALD62_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald62 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald62_Peripheral_Access_Layer locald62 Peripheral Access Layer
 * @{
 */

/** locald62 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR460;                          /**< ldprofilereg460, offset: 0x0 */
  __IO uint32_t LDPRR461;                          /**< ldprofilereg461, offset: 0x4 */
  __IO uint32_t LDPRR462;                          /**< ldprofilereg462, offset: 0x8 */
  __IO uint32_t LDPRR463;                          /**< ldprofilereg463, offset: 0xC */
  __IO uint32_t LDPRR464;                          /**< ldprofilereg464, offset: 0x10 */
  __IO uint32_t LDPRR465;                          /**< ldprofilereg465, offset: 0x14 */
  __IO uint32_t LDPRR466;                          /**< ldprofilereg466, offset: 0x18 */
  __IO uint32_t LDPRR467;                          /**< ldprofilereg467, offset: 0x1C */
  __IO uint32_t LDPRR468;                          /**< ldprofilereg468, offset: 0x20 */
  __IO uint32_t LDPRR469;                          /**< ldprofilereg469, offset: 0x24 */
  __IO uint32_t LDPRR46A;                          /**< ldprofilereg46a, offset: 0x28 */
  __IO uint32_t LDPRR46B;                          /**< ldprofilereg46b, offset: 0x2C */
  __IO uint32_t LDPRR46C;                          /**< ldprofilereg46c, offset: 0x30 */
  __IO uint32_t LDPRR46D;                          /**< ldprofilereg46d, offset: 0x34 */
  __IO uint32_t LDPRR46E;                          /**< ldprofilereg46e, offset: 0x38 */
  __IO uint32_t LDPRR46F;                          /**< ldprofilereg46f, offset: 0x3C */
  __IO uint32_t LDPRR470;                          /**< ldprofilereg470, offset: 0x40 */
  __IO uint32_t LDPRR471;                          /**< ldprofilereg471, offset: 0x44 */
  __IO uint32_t LDPRR472;                          /**< ldprofilereg472, offset: 0x48 */
  __IO uint32_t LDPRR473;                          /**< ldprofilereg473, offset: 0x4C */
  __IO uint32_t LDPRR474;                          /**< ldprofilereg474, offset: 0x50 */
  __IO uint32_t LDPRR475;                          /**< ldprofilereg475, offset: 0x54 */
  __IO uint32_t LDPRR476;                          /**< ldprofilereg476, offset: 0x58 */
  __IO uint32_t LDPRR477;                          /**< ldprofilereg477, offset: 0x5C */
} locald62_Type;

/* ----------------------------------------------------------------------------
   -- locald62 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald62_Register_Masks locald62 Register Masks
 * @{
 */

/*! @name LDPRR460 - ldprofilereg460 */
/*! @{ */

#define locald62_LDPRR460_lumd1681_MASK          (0x3FFU)
#define locald62_LDPRR460_lumd1681_SHIFT         (0U)
/*! lumd1681 - lumdat_1681 */
#define locald62_LDPRR460_lumd1681(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR460_lumd1681_SHIFT)) & locald62_LDPRR460_lumd1681_MASK)

#define locald62_LDPRR460_lumd1680_MASK          (0x3FF0000U)
#define locald62_LDPRR460_lumd1680_SHIFT         (16U)
/*! lumd1680 - lumdat_1680 */
#define locald62_LDPRR460_lumd1680(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR460_lumd1680_SHIFT)) & locald62_LDPRR460_lumd1680_MASK)
/*! @} */

/*! @name LDPRR461 - ldprofilereg461 */
/*! @{ */

#define locald62_LDPRR461_lumd1683_MASK          (0x3FFU)
#define locald62_LDPRR461_lumd1683_SHIFT         (0U)
/*! lumd1683 - lumdat_1683 */
#define locald62_LDPRR461_lumd1683(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR461_lumd1683_SHIFT)) & locald62_LDPRR461_lumd1683_MASK)

#define locald62_LDPRR461_lumd1682_MASK          (0x3FF0000U)
#define locald62_LDPRR461_lumd1682_SHIFT         (16U)
/*! lumd1682 - lumdat_1682 */
#define locald62_LDPRR461_lumd1682(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR461_lumd1682_SHIFT)) & locald62_LDPRR461_lumd1682_MASK)
/*! @} */

/*! @name LDPRR462 - ldprofilereg462 */
/*! @{ */

#define locald62_LDPRR462_lumd1685_MASK          (0x3FFU)
#define locald62_LDPRR462_lumd1685_SHIFT         (0U)
/*! lumd1685 - lumdat_1685 */
#define locald62_LDPRR462_lumd1685(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR462_lumd1685_SHIFT)) & locald62_LDPRR462_lumd1685_MASK)

#define locald62_LDPRR462_lumd1684_MASK          (0x3FF0000U)
#define locald62_LDPRR462_lumd1684_SHIFT         (16U)
/*! lumd1684 - lumdat_1684 */
#define locald62_LDPRR462_lumd1684(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR462_lumd1684_SHIFT)) & locald62_LDPRR462_lumd1684_MASK)
/*! @} */

/*! @name LDPRR463 - ldprofilereg463 */
/*! @{ */

#define locald62_LDPRR463_lumd1687_MASK          (0x3FFU)
#define locald62_LDPRR463_lumd1687_SHIFT         (0U)
/*! lumd1687 - lumdat_1687 */
#define locald62_LDPRR463_lumd1687(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR463_lumd1687_SHIFT)) & locald62_LDPRR463_lumd1687_MASK)

#define locald62_LDPRR463_lumd1686_MASK          (0x3FF0000U)
#define locald62_LDPRR463_lumd1686_SHIFT         (16U)
/*! lumd1686 - lumdat_1686 */
#define locald62_LDPRR463_lumd1686(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR463_lumd1686_SHIFT)) & locald62_LDPRR463_lumd1686_MASK)
/*! @} */

/*! @name LDPRR464 - ldprofilereg464 */
/*! @{ */

#define locald62_LDPRR464_lumd1689_MASK          (0x3FFU)
#define locald62_LDPRR464_lumd1689_SHIFT         (0U)
/*! lumd1689 - lumdat_1689 */
#define locald62_LDPRR464_lumd1689(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR464_lumd1689_SHIFT)) & locald62_LDPRR464_lumd1689_MASK)

#define locald62_LDPRR464_lumd1688_MASK          (0x3FF0000U)
#define locald62_LDPRR464_lumd1688_SHIFT         (16U)
/*! lumd1688 - lumdat_1688 */
#define locald62_LDPRR464_lumd1688(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR464_lumd1688_SHIFT)) & locald62_LDPRR464_lumd1688_MASK)
/*! @} */

/*! @name LDPRR465 - ldprofilereg465 */
/*! @{ */

#define locald62_LDPRR465_lumd1691_MASK          (0x3FFU)
#define locald62_LDPRR465_lumd1691_SHIFT         (0U)
/*! lumd1691 - lumdat_1691 */
#define locald62_LDPRR465_lumd1691(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR465_lumd1691_SHIFT)) & locald62_LDPRR465_lumd1691_MASK)

#define locald62_LDPRR465_lumd1690_MASK          (0x3FF0000U)
#define locald62_LDPRR465_lumd1690_SHIFT         (16U)
/*! lumd1690 - lumdat_1690 */
#define locald62_LDPRR465_lumd1690(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR465_lumd1690_SHIFT)) & locald62_LDPRR465_lumd1690_MASK)
/*! @} */

/*! @name LDPRR466 - ldprofilereg466 */
/*! @{ */

#define locald62_LDPRR466_lumd1693_MASK          (0x3FFU)
#define locald62_LDPRR466_lumd1693_SHIFT         (0U)
/*! lumd1693 - lumdat_1693 */
#define locald62_LDPRR466_lumd1693(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR466_lumd1693_SHIFT)) & locald62_LDPRR466_lumd1693_MASK)

#define locald62_LDPRR466_lumd1692_MASK          (0x3FF0000U)
#define locald62_LDPRR466_lumd1692_SHIFT         (16U)
/*! lumd1692 - lumdat_1692 */
#define locald62_LDPRR466_lumd1692(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR466_lumd1692_SHIFT)) & locald62_LDPRR466_lumd1692_MASK)
/*! @} */

/*! @name LDPRR467 - ldprofilereg467 */
/*! @{ */

#define locald62_LDPRR467_lumd1695_MASK          (0x3FFU)
#define locald62_LDPRR467_lumd1695_SHIFT         (0U)
/*! lumd1695 - lumdat_1695 */
#define locald62_LDPRR467_lumd1695(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR467_lumd1695_SHIFT)) & locald62_LDPRR467_lumd1695_MASK)

#define locald62_LDPRR467_lumd1694_MASK          (0x3FF0000U)
#define locald62_LDPRR467_lumd1694_SHIFT         (16U)
/*! lumd1694 - lumdat_1694 */
#define locald62_LDPRR467_lumd1694(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR467_lumd1694_SHIFT)) & locald62_LDPRR467_lumd1694_MASK)
/*! @} */

/*! @name LDPRR468 - ldprofilereg468 */
/*! @{ */

#define locald62_LDPRR468_lumd1697_MASK          (0x3FFU)
#define locald62_LDPRR468_lumd1697_SHIFT         (0U)
/*! lumd1697 - lumdat_1697 */
#define locald62_LDPRR468_lumd1697(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR468_lumd1697_SHIFT)) & locald62_LDPRR468_lumd1697_MASK)

#define locald62_LDPRR468_lumd1696_MASK          (0x3FF0000U)
#define locald62_LDPRR468_lumd1696_SHIFT         (16U)
/*! lumd1696 - lumdat_1696 */
#define locald62_LDPRR468_lumd1696(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR468_lumd1696_SHIFT)) & locald62_LDPRR468_lumd1696_MASK)
/*! @} */

/*! @name LDPRR469 - ldprofilereg469 */
/*! @{ */

#define locald62_LDPRR469_lumd1699_MASK          (0x3FFU)
#define locald62_LDPRR469_lumd1699_SHIFT         (0U)
/*! lumd1699 - lumdat_1699 */
#define locald62_LDPRR469_lumd1699(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR469_lumd1699_SHIFT)) & locald62_LDPRR469_lumd1699_MASK)

#define locald62_LDPRR469_lumd1698_MASK          (0x3FF0000U)
#define locald62_LDPRR469_lumd1698_SHIFT         (16U)
/*! lumd1698 - lumdat_1698 */
#define locald62_LDPRR469_lumd1698(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR469_lumd1698_SHIFT)) & locald62_LDPRR469_lumd1698_MASK)
/*! @} */

/*! @name LDPRR46A - ldprofilereg46a */
/*! @{ */

#define locald62_LDPRR46A_lumd1701_MASK          (0x3FFU)
#define locald62_LDPRR46A_lumd1701_SHIFT         (0U)
/*! lumd1701 - lumdat_1701 */
#define locald62_LDPRR46A_lumd1701(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46A_lumd1701_SHIFT)) & locald62_LDPRR46A_lumd1701_MASK)

#define locald62_LDPRR46A_lumd1700_MASK          (0x3FF0000U)
#define locald62_LDPRR46A_lumd1700_SHIFT         (16U)
/*! lumd1700 - lumdat_1700 */
#define locald62_LDPRR46A_lumd1700(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46A_lumd1700_SHIFT)) & locald62_LDPRR46A_lumd1700_MASK)
/*! @} */

/*! @name LDPRR46B - ldprofilereg46b */
/*! @{ */

#define locald62_LDPRR46B_lumd1703_MASK          (0x3FFU)
#define locald62_LDPRR46B_lumd1703_SHIFT         (0U)
/*! lumd1703 - lumdat_1703 */
#define locald62_LDPRR46B_lumd1703(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46B_lumd1703_SHIFT)) & locald62_LDPRR46B_lumd1703_MASK)

#define locald62_LDPRR46B_lumd1702_MASK          (0x3FF0000U)
#define locald62_LDPRR46B_lumd1702_SHIFT         (16U)
/*! lumd1702 - lumdat_1702 */
#define locald62_LDPRR46B_lumd1702(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46B_lumd1702_SHIFT)) & locald62_LDPRR46B_lumd1702_MASK)
/*! @} */

/*! @name LDPRR46C - ldprofilereg46c */
/*! @{ */

#define locald62_LDPRR46C_lumd1705_MASK          (0x3FFU)
#define locald62_LDPRR46C_lumd1705_SHIFT         (0U)
/*! lumd1705 - lumdat_1705 */
#define locald62_LDPRR46C_lumd1705(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46C_lumd1705_SHIFT)) & locald62_LDPRR46C_lumd1705_MASK)

#define locald62_LDPRR46C_lumd1704_MASK          (0x3FF0000U)
#define locald62_LDPRR46C_lumd1704_SHIFT         (16U)
/*! lumd1704 - lumdat_1704 */
#define locald62_LDPRR46C_lumd1704(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46C_lumd1704_SHIFT)) & locald62_LDPRR46C_lumd1704_MASK)
/*! @} */

/*! @name LDPRR46D - ldprofilereg46d */
/*! @{ */

#define locald62_LDPRR46D_lumd1707_MASK          (0x3FFU)
#define locald62_LDPRR46D_lumd1707_SHIFT         (0U)
/*! lumd1707 - lumdat_1707 */
#define locald62_LDPRR46D_lumd1707(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46D_lumd1707_SHIFT)) & locald62_LDPRR46D_lumd1707_MASK)

#define locald62_LDPRR46D_lumd1706_MASK          (0x3FF0000U)
#define locald62_LDPRR46D_lumd1706_SHIFT         (16U)
/*! lumd1706 - lumdat_1706 */
#define locald62_LDPRR46D_lumd1706(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46D_lumd1706_SHIFT)) & locald62_LDPRR46D_lumd1706_MASK)
/*! @} */

/*! @name LDPRR46E - ldprofilereg46e */
/*! @{ */

#define locald62_LDPRR46E_lumd1709_MASK          (0x3FFU)
#define locald62_LDPRR46E_lumd1709_SHIFT         (0U)
/*! lumd1709 - lumdat_1709 */
#define locald62_LDPRR46E_lumd1709(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46E_lumd1709_SHIFT)) & locald62_LDPRR46E_lumd1709_MASK)

#define locald62_LDPRR46E_lumd1708_MASK          (0x3FF0000U)
#define locald62_LDPRR46E_lumd1708_SHIFT         (16U)
/*! lumd1708 - lumdat_1708 */
#define locald62_LDPRR46E_lumd1708(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46E_lumd1708_SHIFT)) & locald62_LDPRR46E_lumd1708_MASK)
/*! @} */

/*! @name LDPRR46F - ldprofilereg46f */
/*! @{ */

#define locald62_LDPRR46F_lumd1711_MASK          (0x3FFU)
#define locald62_LDPRR46F_lumd1711_SHIFT         (0U)
/*! lumd1711 - lumdat_1711 */
#define locald62_LDPRR46F_lumd1711(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46F_lumd1711_SHIFT)) & locald62_LDPRR46F_lumd1711_MASK)

#define locald62_LDPRR46F_lumd1710_MASK          (0x3FF0000U)
#define locald62_LDPRR46F_lumd1710_SHIFT         (16U)
/*! lumd1710 - lumdat_1710 */
#define locald62_LDPRR46F_lumd1710(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR46F_lumd1710_SHIFT)) & locald62_LDPRR46F_lumd1710_MASK)
/*! @} */

/*! @name LDPRR470 - ldprofilereg470 */
/*! @{ */

#define locald62_LDPRR470_lumd1713_MASK          (0x3FFU)
#define locald62_LDPRR470_lumd1713_SHIFT         (0U)
/*! lumd1713 - lumdat_1713 */
#define locald62_LDPRR470_lumd1713(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR470_lumd1713_SHIFT)) & locald62_LDPRR470_lumd1713_MASK)

#define locald62_LDPRR470_lumd1712_MASK          (0x3FF0000U)
#define locald62_LDPRR470_lumd1712_SHIFT         (16U)
/*! lumd1712 - lumdat_1712 */
#define locald62_LDPRR470_lumd1712(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR470_lumd1712_SHIFT)) & locald62_LDPRR470_lumd1712_MASK)
/*! @} */

/*! @name LDPRR471 - ldprofilereg471 */
/*! @{ */

#define locald62_LDPRR471_lumd1715_MASK          (0x3FFU)
#define locald62_LDPRR471_lumd1715_SHIFT         (0U)
/*! lumd1715 - lumdat_1715 */
#define locald62_LDPRR471_lumd1715(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR471_lumd1715_SHIFT)) & locald62_LDPRR471_lumd1715_MASK)

#define locald62_LDPRR471_lumd1714_MASK          (0x3FF0000U)
#define locald62_LDPRR471_lumd1714_SHIFT         (16U)
/*! lumd1714 - lumdat_1714 */
#define locald62_LDPRR471_lumd1714(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR471_lumd1714_SHIFT)) & locald62_LDPRR471_lumd1714_MASK)
/*! @} */

/*! @name LDPRR472 - ldprofilereg472 */
/*! @{ */

#define locald62_LDPRR472_lumd1717_MASK          (0x3FFU)
#define locald62_LDPRR472_lumd1717_SHIFT         (0U)
/*! lumd1717 - lumdat_1717 */
#define locald62_LDPRR472_lumd1717(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR472_lumd1717_SHIFT)) & locald62_LDPRR472_lumd1717_MASK)

#define locald62_LDPRR472_lumd1716_MASK          (0x3FF0000U)
#define locald62_LDPRR472_lumd1716_SHIFT         (16U)
/*! lumd1716 - lumdat_1716 */
#define locald62_LDPRR472_lumd1716(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR472_lumd1716_SHIFT)) & locald62_LDPRR472_lumd1716_MASK)
/*! @} */

/*! @name LDPRR473 - ldprofilereg473 */
/*! @{ */

#define locald62_LDPRR473_lumd1719_MASK          (0x3FFU)
#define locald62_LDPRR473_lumd1719_SHIFT         (0U)
/*! lumd1719 - lumdat_1719 */
#define locald62_LDPRR473_lumd1719(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR473_lumd1719_SHIFT)) & locald62_LDPRR473_lumd1719_MASK)

#define locald62_LDPRR473_lumd1718_MASK          (0x3FF0000U)
#define locald62_LDPRR473_lumd1718_SHIFT         (16U)
/*! lumd1718 - lumdat_1718 */
#define locald62_LDPRR473_lumd1718(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR473_lumd1718_SHIFT)) & locald62_LDPRR473_lumd1718_MASK)
/*! @} */

/*! @name LDPRR474 - ldprofilereg474 */
/*! @{ */

#define locald62_LDPRR474_lumd1721_MASK          (0x3FFU)
#define locald62_LDPRR474_lumd1721_SHIFT         (0U)
/*! lumd1721 - lumdat_1721 */
#define locald62_LDPRR474_lumd1721(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR474_lumd1721_SHIFT)) & locald62_LDPRR474_lumd1721_MASK)

#define locald62_LDPRR474_lumd1720_MASK          (0x3FF0000U)
#define locald62_LDPRR474_lumd1720_SHIFT         (16U)
/*! lumd1720 - lumdat_1720 */
#define locald62_LDPRR474_lumd1720(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR474_lumd1720_SHIFT)) & locald62_LDPRR474_lumd1720_MASK)
/*! @} */

/*! @name LDPRR475 - ldprofilereg475 */
/*! @{ */

#define locald62_LDPRR475_lumd1723_MASK          (0x3FFU)
#define locald62_LDPRR475_lumd1723_SHIFT         (0U)
/*! lumd1723 - lumdat_1723 */
#define locald62_LDPRR475_lumd1723(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR475_lumd1723_SHIFT)) & locald62_LDPRR475_lumd1723_MASK)

#define locald62_LDPRR475_lumd1722_MASK          (0x3FF0000U)
#define locald62_LDPRR475_lumd1722_SHIFT         (16U)
/*! lumd1722 - lumdat_1722 */
#define locald62_LDPRR475_lumd1722(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR475_lumd1722_SHIFT)) & locald62_LDPRR475_lumd1722_MASK)
/*! @} */

/*! @name LDPRR476 - ldprofilereg476 */
/*! @{ */

#define locald62_LDPRR476_lumd1725_MASK          (0x3FFU)
#define locald62_LDPRR476_lumd1725_SHIFT         (0U)
/*! lumd1725 - lumdat_1725 */
#define locald62_LDPRR476_lumd1725(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR476_lumd1725_SHIFT)) & locald62_LDPRR476_lumd1725_MASK)

#define locald62_LDPRR476_lumd1724_MASK          (0x3FF0000U)
#define locald62_LDPRR476_lumd1724_SHIFT         (16U)
/*! lumd1724 - lumdat_1724 */
#define locald62_LDPRR476_lumd1724(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR476_lumd1724_SHIFT)) & locald62_LDPRR476_lumd1724_MASK)
/*! @} */

/*! @name LDPRR477 - ldprofilereg477 */
/*! @{ */

#define locald62_LDPRR477_lumd1727_MASK          (0x3FFU)
#define locald62_LDPRR477_lumd1727_SHIFT         (0U)
/*! lumd1727 - lumdat_1727 */
#define locald62_LDPRR477_lumd1727(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR477_lumd1727_SHIFT)) & locald62_LDPRR477_lumd1727_MASK)

#define locald62_LDPRR477_lumd1726_MASK          (0x3FF0000U)
#define locald62_LDPRR477_lumd1726_SHIFT         (16U)
/*! lumd1726 - lumdat_1726 */
#define locald62_LDPRR477_lumd1726(x)            (((uint32_t)(((uint32_t)(x)) << locald62_LDPRR477_lumd1726_SHIFT)) & locald62_LDPRR477_lumd1726_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald62_Register_Masks */


/*!
 * @}
 */ /* end of group locald62_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD62_H_ */

