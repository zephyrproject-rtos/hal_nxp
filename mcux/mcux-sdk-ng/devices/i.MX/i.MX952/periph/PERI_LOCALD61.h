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
**         CMSIS Peripheral Access Layer for locald61
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
 * @file PERI_locald61.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald61
 *
 * CMSIS Peripheral Access Layer for locald61
 */

#if !defined(PERI_LOCALD61_H_)
#define PERI_LOCALD61_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald61 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald61_Peripheral_Access_Layer locald61 Peripheral Access Layer
 * @{
 */

/** locald61 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR440;                          /**< ldprofilereg440, offset: 0x0 */
  __IO uint32_t LDPRR441;                          /**< ldprofilereg441, offset: 0x4 */
  __IO uint32_t LDPRR442;                          /**< ldprofilereg442, offset: 0x8 */
  __IO uint32_t LDPRR443;                          /**< ldprofilereg443, offset: 0xC */
  __IO uint32_t LDPRR444;                          /**< ldprofilereg444, offset: 0x10 */
  __IO uint32_t LDPRR445;                          /**< ldprofilereg445, offset: 0x14 */
  __IO uint32_t LDPRR446;                          /**< ldprofilereg446, offset: 0x18 */
  __IO uint32_t LDPRR447;                          /**< ldprofilereg447, offset: 0x1C */
  __IO uint32_t LDPRR448;                          /**< ldprofilereg448, offset: 0x20 */
  __IO uint32_t LDPRR449;                          /**< ldprofilereg449, offset: 0x24 */
  __IO uint32_t LDPRR44A;                          /**< ldprofilereg44a, offset: 0x28 */
  __IO uint32_t LDPRR44B;                          /**< ldprofilereg44b, offset: 0x2C */
  __IO uint32_t LDPRR44C;                          /**< ldprofilereg44c, offset: 0x30 */
  __IO uint32_t LDPRR44D;                          /**< ldprofilereg44d, offset: 0x34 */
  __IO uint32_t LDPRR44E;                          /**< ldprofilereg44e, offset: 0x38 */
  __IO uint32_t LDPRR44F;                          /**< ldprofilereg44f, offset: 0x3C */
  __IO uint32_t LDPRR450;                          /**< ldprofilereg450, offset: 0x40 */
  __IO uint32_t LDPRR451;                          /**< ldprofilereg451, offset: 0x44 */
  __IO uint32_t LDPRR452;                          /**< ldprofilereg452, offset: 0x48 */
  __IO uint32_t LDPRR453;                          /**< ldprofilereg453, offset: 0x4C */
  __IO uint32_t LDPRR454;                          /**< ldprofilereg454, offset: 0x50 */
  __IO uint32_t LDPRR455;                          /**< ldprofilereg455, offset: 0x54 */
  __IO uint32_t LDPRR456;                          /**< ldprofilereg456, offset: 0x58 */
  __IO uint32_t LDPRR457;                          /**< ldprofilereg457, offset: 0x5C */
} locald61_Type;

/* ----------------------------------------------------------------------------
   -- locald61 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald61_Register_Masks locald61 Register Masks
 * @{
 */

/*! @name LDPRR440 - ldprofilereg440 */
/*! @{ */

#define locald61_LDPRR440_lumd1633_MASK          (0x3FFU)
#define locald61_LDPRR440_lumd1633_SHIFT         (0U)
/*! lumd1633 - lumdat_1633 */
#define locald61_LDPRR440_lumd1633(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR440_lumd1633_SHIFT)) & locald61_LDPRR440_lumd1633_MASK)

#define locald61_LDPRR440_lumd1632_MASK          (0x3FF0000U)
#define locald61_LDPRR440_lumd1632_SHIFT         (16U)
/*! lumd1632 - lumdat_1632 */
#define locald61_LDPRR440_lumd1632(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR440_lumd1632_SHIFT)) & locald61_LDPRR440_lumd1632_MASK)
/*! @} */

/*! @name LDPRR441 - ldprofilereg441 */
/*! @{ */

#define locald61_LDPRR441_lumd1635_MASK          (0x3FFU)
#define locald61_LDPRR441_lumd1635_SHIFT         (0U)
/*! lumd1635 - lumdat_1635 */
#define locald61_LDPRR441_lumd1635(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR441_lumd1635_SHIFT)) & locald61_LDPRR441_lumd1635_MASK)

#define locald61_LDPRR441_lumd1634_MASK          (0x3FF0000U)
#define locald61_LDPRR441_lumd1634_SHIFT         (16U)
/*! lumd1634 - lumdat_1634 */
#define locald61_LDPRR441_lumd1634(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR441_lumd1634_SHIFT)) & locald61_LDPRR441_lumd1634_MASK)
/*! @} */

/*! @name LDPRR442 - ldprofilereg442 */
/*! @{ */

#define locald61_LDPRR442_lumd1637_MASK          (0x3FFU)
#define locald61_LDPRR442_lumd1637_SHIFT         (0U)
/*! lumd1637 - lumdat_1637 */
#define locald61_LDPRR442_lumd1637(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR442_lumd1637_SHIFT)) & locald61_LDPRR442_lumd1637_MASK)

#define locald61_LDPRR442_lumd1636_MASK          (0x3FF0000U)
#define locald61_LDPRR442_lumd1636_SHIFT         (16U)
/*! lumd1636 - lumdat_1636 */
#define locald61_LDPRR442_lumd1636(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR442_lumd1636_SHIFT)) & locald61_LDPRR442_lumd1636_MASK)
/*! @} */

/*! @name LDPRR443 - ldprofilereg443 */
/*! @{ */

#define locald61_LDPRR443_lumd1639_MASK          (0x3FFU)
#define locald61_LDPRR443_lumd1639_SHIFT         (0U)
/*! lumd1639 - lumdat_1639 */
#define locald61_LDPRR443_lumd1639(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR443_lumd1639_SHIFT)) & locald61_LDPRR443_lumd1639_MASK)

#define locald61_LDPRR443_lumd1638_MASK          (0x3FF0000U)
#define locald61_LDPRR443_lumd1638_SHIFT         (16U)
/*! lumd1638 - lumdat_1638 */
#define locald61_LDPRR443_lumd1638(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR443_lumd1638_SHIFT)) & locald61_LDPRR443_lumd1638_MASK)
/*! @} */

/*! @name LDPRR444 - ldprofilereg444 */
/*! @{ */

#define locald61_LDPRR444_lumd1641_MASK          (0x3FFU)
#define locald61_LDPRR444_lumd1641_SHIFT         (0U)
/*! lumd1641 - lumdat_1641 */
#define locald61_LDPRR444_lumd1641(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR444_lumd1641_SHIFT)) & locald61_LDPRR444_lumd1641_MASK)

#define locald61_LDPRR444_lumd1640_MASK          (0x3FF0000U)
#define locald61_LDPRR444_lumd1640_SHIFT         (16U)
/*! lumd1640 - lumdat_1640 */
#define locald61_LDPRR444_lumd1640(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR444_lumd1640_SHIFT)) & locald61_LDPRR444_lumd1640_MASK)
/*! @} */

/*! @name LDPRR445 - ldprofilereg445 */
/*! @{ */

#define locald61_LDPRR445_lumd1643_MASK          (0x3FFU)
#define locald61_LDPRR445_lumd1643_SHIFT         (0U)
/*! lumd1643 - lumdat_1643 */
#define locald61_LDPRR445_lumd1643(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR445_lumd1643_SHIFT)) & locald61_LDPRR445_lumd1643_MASK)

#define locald61_LDPRR445_lumd1642_MASK          (0x3FF0000U)
#define locald61_LDPRR445_lumd1642_SHIFT         (16U)
/*! lumd1642 - lumdat_1642 */
#define locald61_LDPRR445_lumd1642(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR445_lumd1642_SHIFT)) & locald61_LDPRR445_lumd1642_MASK)
/*! @} */

/*! @name LDPRR446 - ldprofilereg446 */
/*! @{ */

#define locald61_LDPRR446_lumd1645_MASK          (0x3FFU)
#define locald61_LDPRR446_lumd1645_SHIFT         (0U)
/*! lumd1645 - lumdat_1645 */
#define locald61_LDPRR446_lumd1645(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR446_lumd1645_SHIFT)) & locald61_LDPRR446_lumd1645_MASK)

#define locald61_LDPRR446_lumd1644_MASK          (0x3FF0000U)
#define locald61_LDPRR446_lumd1644_SHIFT         (16U)
/*! lumd1644 - lumdat_1644 */
#define locald61_LDPRR446_lumd1644(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR446_lumd1644_SHIFT)) & locald61_LDPRR446_lumd1644_MASK)
/*! @} */

/*! @name LDPRR447 - ldprofilereg447 */
/*! @{ */

#define locald61_LDPRR447_lumd1647_MASK          (0x3FFU)
#define locald61_LDPRR447_lumd1647_SHIFT         (0U)
/*! lumd1647 - lumdat_1647 */
#define locald61_LDPRR447_lumd1647(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR447_lumd1647_SHIFT)) & locald61_LDPRR447_lumd1647_MASK)

#define locald61_LDPRR447_lumd1646_MASK          (0x3FF0000U)
#define locald61_LDPRR447_lumd1646_SHIFT         (16U)
/*! lumd1646 - lumdat_1646 */
#define locald61_LDPRR447_lumd1646(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR447_lumd1646_SHIFT)) & locald61_LDPRR447_lumd1646_MASK)
/*! @} */

/*! @name LDPRR448 - ldprofilereg448 */
/*! @{ */

#define locald61_LDPRR448_lumd1649_MASK          (0x3FFU)
#define locald61_LDPRR448_lumd1649_SHIFT         (0U)
/*! lumd1649 - lumdat_1649 */
#define locald61_LDPRR448_lumd1649(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR448_lumd1649_SHIFT)) & locald61_LDPRR448_lumd1649_MASK)

#define locald61_LDPRR448_lumd1648_MASK          (0x3FF0000U)
#define locald61_LDPRR448_lumd1648_SHIFT         (16U)
/*! lumd1648 - lumdat_1648 */
#define locald61_LDPRR448_lumd1648(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR448_lumd1648_SHIFT)) & locald61_LDPRR448_lumd1648_MASK)
/*! @} */

/*! @name LDPRR449 - ldprofilereg449 */
/*! @{ */

#define locald61_LDPRR449_lumd1651_MASK          (0x3FFU)
#define locald61_LDPRR449_lumd1651_SHIFT         (0U)
/*! lumd1651 - lumdat_1651 */
#define locald61_LDPRR449_lumd1651(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR449_lumd1651_SHIFT)) & locald61_LDPRR449_lumd1651_MASK)

#define locald61_LDPRR449_lumd1650_MASK          (0x3FF0000U)
#define locald61_LDPRR449_lumd1650_SHIFT         (16U)
/*! lumd1650 - lumdat_1650 */
#define locald61_LDPRR449_lumd1650(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR449_lumd1650_SHIFT)) & locald61_LDPRR449_lumd1650_MASK)
/*! @} */

/*! @name LDPRR44A - ldprofilereg44a */
/*! @{ */

#define locald61_LDPRR44A_lumd1653_MASK          (0x3FFU)
#define locald61_LDPRR44A_lumd1653_SHIFT         (0U)
/*! lumd1653 - lumdat_1653 */
#define locald61_LDPRR44A_lumd1653(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44A_lumd1653_SHIFT)) & locald61_LDPRR44A_lumd1653_MASK)

#define locald61_LDPRR44A_lumd1652_MASK          (0x3FF0000U)
#define locald61_LDPRR44A_lumd1652_SHIFT         (16U)
/*! lumd1652 - lumdat_1652 */
#define locald61_LDPRR44A_lumd1652(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44A_lumd1652_SHIFT)) & locald61_LDPRR44A_lumd1652_MASK)
/*! @} */

/*! @name LDPRR44B - ldprofilereg44b */
/*! @{ */

#define locald61_LDPRR44B_lumd1655_MASK          (0x3FFU)
#define locald61_LDPRR44B_lumd1655_SHIFT         (0U)
/*! lumd1655 - lumdat_1655 */
#define locald61_LDPRR44B_lumd1655(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44B_lumd1655_SHIFT)) & locald61_LDPRR44B_lumd1655_MASK)

#define locald61_LDPRR44B_lumd1654_MASK          (0x3FF0000U)
#define locald61_LDPRR44B_lumd1654_SHIFT         (16U)
/*! lumd1654 - lumdat_1654 */
#define locald61_LDPRR44B_lumd1654(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44B_lumd1654_SHIFT)) & locald61_LDPRR44B_lumd1654_MASK)
/*! @} */

/*! @name LDPRR44C - ldprofilereg44c */
/*! @{ */

#define locald61_LDPRR44C_lumd1657_MASK          (0x3FFU)
#define locald61_LDPRR44C_lumd1657_SHIFT         (0U)
/*! lumd1657 - lumdat_1657 */
#define locald61_LDPRR44C_lumd1657(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44C_lumd1657_SHIFT)) & locald61_LDPRR44C_lumd1657_MASK)

#define locald61_LDPRR44C_lumd1656_MASK          (0x3FF0000U)
#define locald61_LDPRR44C_lumd1656_SHIFT         (16U)
/*! lumd1656 - lumdat_1656 */
#define locald61_LDPRR44C_lumd1656(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44C_lumd1656_SHIFT)) & locald61_LDPRR44C_lumd1656_MASK)
/*! @} */

/*! @name LDPRR44D - ldprofilereg44d */
/*! @{ */

#define locald61_LDPRR44D_lumd1659_MASK          (0x3FFU)
#define locald61_LDPRR44D_lumd1659_SHIFT         (0U)
/*! lumd1659 - lumdat_1659 */
#define locald61_LDPRR44D_lumd1659(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44D_lumd1659_SHIFT)) & locald61_LDPRR44D_lumd1659_MASK)

#define locald61_LDPRR44D_lumd1658_MASK          (0x3FF0000U)
#define locald61_LDPRR44D_lumd1658_SHIFT         (16U)
/*! lumd1658 - lumdat_1658 */
#define locald61_LDPRR44D_lumd1658(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44D_lumd1658_SHIFT)) & locald61_LDPRR44D_lumd1658_MASK)
/*! @} */

/*! @name LDPRR44E - ldprofilereg44e */
/*! @{ */

#define locald61_LDPRR44E_lumd1661_MASK          (0x3FFU)
#define locald61_LDPRR44E_lumd1661_SHIFT         (0U)
/*! lumd1661 - lumdat_1661 */
#define locald61_LDPRR44E_lumd1661(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44E_lumd1661_SHIFT)) & locald61_LDPRR44E_lumd1661_MASK)

#define locald61_LDPRR44E_lumd1660_MASK          (0x3FF0000U)
#define locald61_LDPRR44E_lumd1660_SHIFT         (16U)
/*! lumd1660 - lumdat_1660 */
#define locald61_LDPRR44E_lumd1660(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44E_lumd1660_SHIFT)) & locald61_LDPRR44E_lumd1660_MASK)
/*! @} */

/*! @name LDPRR44F - ldprofilereg44f */
/*! @{ */

#define locald61_LDPRR44F_lumd1663_MASK          (0x3FFU)
#define locald61_LDPRR44F_lumd1663_SHIFT         (0U)
/*! lumd1663 - lumdat_1663 */
#define locald61_LDPRR44F_lumd1663(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44F_lumd1663_SHIFT)) & locald61_LDPRR44F_lumd1663_MASK)

#define locald61_LDPRR44F_lumd1662_MASK          (0x3FF0000U)
#define locald61_LDPRR44F_lumd1662_SHIFT         (16U)
/*! lumd1662 - lumdat_1662 */
#define locald61_LDPRR44F_lumd1662(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR44F_lumd1662_SHIFT)) & locald61_LDPRR44F_lumd1662_MASK)
/*! @} */

/*! @name LDPRR450 - ldprofilereg450 */
/*! @{ */

#define locald61_LDPRR450_lumd1665_MASK          (0x3FFU)
#define locald61_LDPRR450_lumd1665_SHIFT         (0U)
/*! lumd1665 - lumdat_1665 */
#define locald61_LDPRR450_lumd1665(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR450_lumd1665_SHIFT)) & locald61_LDPRR450_lumd1665_MASK)

#define locald61_LDPRR450_lumd1664_MASK          (0x3FF0000U)
#define locald61_LDPRR450_lumd1664_SHIFT         (16U)
/*! lumd1664 - lumdat_1664 */
#define locald61_LDPRR450_lumd1664(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR450_lumd1664_SHIFT)) & locald61_LDPRR450_lumd1664_MASK)
/*! @} */

/*! @name LDPRR451 - ldprofilereg451 */
/*! @{ */

#define locald61_LDPRR451_lumd1667_MASK          (0x3FFU)
#define locald61_LDPRR451_lumd1667_SHIFT         (0U)
/*! lumd1667 - lumdat_1667 */
#define locald61_LDPRR451_lumd1667(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR451_lumd1667_SHIFT)) & locald61_LDPRR451_lumd1667_MASK)

#define locald61_LDPRR451_lumd1666_MASK          (0x3FF0000U)
#define locald61_LDPRR451_lumd1666_SHIFT         (16U)
/*! lumd1666 - lumdat_1666 */
#define locald61_LDPRR451_lumd1666(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR451_lumd1666_SHIFT)) & locald61_LDPRR451_lumd1666_MASK)
/*! @} */

/*! @name LDPRR452 - ldprofilereg452 */
/*! @{ */

#define locald61_LDPRR452_lumd1669_MASK          (0x3FFU)
#define locald61_LDPRR452_lumd1669_SHIFT         (0U)
/*! lumd1669 - lumdat_1669 */
#define locald61_LDPRR452_lumd1669(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR452_lumd1669_SHIFT)) & locald61_LDPRR452_lumd1669_MASK)

#define locald61_LDPRR452_lumd1668_MASK          (0x3FF0000U)
#define locald61_LDPRR452_lumd1668_SHIFT         (16U)
/*! lumd1668 - lumdat_1668 */
#define locald61_LDPRR452_lumd1668(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR452_lumd1668_SHIFT)) & locald61_LDPRR452_lumd1668_MASK)
/*! @} */

/*! @name LDPRR453 - ldprofilereg453 */
/*! @{ */

#define locald61_LDPRR453_lumd1671_MASK          (0x3FFU)
#define locald61_LDPRR453_lumd1671_SHIFT         (0U)
/*! lumd1671 - lumdat_1671 */
#define locald61_LDPRR453_lumd1671(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR453_lumd1671_SHIFT)) & locald61_LDPRR453_lumd1671_MASK)

#define locald61_LDPRR453_lumd1670_MASK          (0x3FF0000U)
#define locald61_LDPRR453_lumd1670_SHIFT         (16U)
/*! lumd1670 - lumdat_1670 */
#define locald61_LDPRR453_lumd1670(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR453_lumd1670_SHIFT)) & locald61_LDPRR453_lumd1670_MASK)
/*! @} */

/*! @name LDPRR454 - ldprofilereg454 */
/*! @{ */

#define locald61_LDPRR454_lumd1673_MASK          (0x3FFU)
#define locald61_LDPRR454_lumd1673_SHIFT         (0U)
/*! lumd1673 - lumdat_1673 */
#define locald61_LDPRR454_lumd1673(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR454_lumd1673_SHIFT)) & locald61_LDPRR454_lumd1673_MASK)

#define locald61_LDPRR454_lumd1672_MASK          (0x3FF0000U)
#define locald61_LDPRR454_lumd1672_SHIFT         (16U)
/*! lumd1672 - lumdat_1672 */
#define locald61_LDPRR454_lumd1672(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR454_lumd1672_SHIFT)) & locald61_LDPRR454_lumd1672_MASK)
/*! @} */

/*! @name LDPRR455 - ldprofilereg455 */
/*! @{ */

#define locald61_LDPRR455_lumd1675_MASK          (0x3FFU)
#define locald61_LDPRR455_lumd1675_SHIFT         (0U)
/*! lumd1675 - lumdat_1675 */
#define locald61_LDPRR455_lumd1675(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR455_lumd1675_SHIFT)) & locald61_LDPRR455_lumd1675_MASK)

#define locald61_LDPRR455_lumd1674_MASK          (0x3FF0000U)
#define locald61_LDPRR455_lumd1674_SHIFT         (16U)
/*! lumd1674 - lumdat_1674 */
#define locald61_LDPRR455_lumd1674(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR455_lumd1674_SHIFT)) & locald61_LDPRR455_lumd1674_MASK)
/*! @} */

/*! @name LDPRR456 - ldprofilereg456 */
/*! @{ */

#define locald61_LDPRR456_lumd1677_MASK          (0x3FFU)
#define locald61_LDPRR456_lumd1677_SHIFT         (0U)
/*! lumd1677 - lumdat_1677 */
#define locald61_LDPRR456_lumd1677(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR456_lumd1677_SHIFT)) & locald61_LDPRR456_lumd1677_MASK)

#define locald61_LDPRR456_lumd1676_MASK          (0x3FF0000U)
#define locald61_LDPRR456_lumd1676_SHIFT         (16U)
/*! lumd1676 - lumdat_1676 */
#define locald61_LDPRR456_lumd1676(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR456_lumd1676_SHIFT)) & locald61_LDPRR456_lumd1676_MASK)
/*! @} */

/*! @name LDPRR457 - ldprofilereg457 */
/*! @{ */

#define locald61_LDPRR457_lumd1679_MASK          (0x3FFU)
#define locald61_LDPRR457_lumd1679_SHIFT         (0U)
/*! lumd1679 - lumdat_1679 */
#define locald61_LDPRR457_lumd1679(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR457_lumd1679_SHIFT)) & locald61_LDPRR457_lumd1679_MASK)

#define locald61_LDPRR457_lumd1678_MASK          (0x3FF0000U)
#define locald61_LDPRR457_lumd1678_SHIFT         (16U)
/*! lumd1678 - lumdat_1678 */
#define locald61_LDPRR457_lumd1678(x)            (((uint32_t)(((uint32_t)(x)) << locald61_LDPRR457_lumd1678_SHIFT)) & locald61_LDPRR457_lumd1678_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald61_Register_Masks */


/*!
 * @}
 */ /* end of group locald61_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD61_H_ */

