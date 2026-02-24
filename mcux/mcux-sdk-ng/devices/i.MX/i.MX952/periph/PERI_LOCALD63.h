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
**         CMSIS Peripheral Access Layer for locald63
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
 * @file PERI_locald63.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald63
 *
 * CMSIS Peripheral Access Layer for locald63
 */

#if !defined(PERI_LOCALD63_H_)
#define PERI_LOCALD63_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald63 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald63_Peripheral_Access_Layer locald63 Peripheral Access Layer
 * @{
 */

/** locald63 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR480;                          /**< ldprofilereg480, offset: 0x0 */
  __IO uint32_t LDPRR481;                          /**< ldprofilereg481, offset: 0x4 */
  __IO uint32_t LDPRR482;                          /**< ldprofilereg482, offset: 0x8 */
  __IO uint32_t LDPRR483;                          /**< ldprofilereg483, offset: 0xC */
  __IO uint32_t LDPRR484;                          /**< ldprofilereg484, offset: 0x10 */
  __IO uint32_t LDPRR485;                          /**< ldprofilereg485, offset: 0x14 */
  __IO uint32_t LDPRR486;                          /**< ldprofilereg486, offset: 0x18 */
  __IO uint32_t LDPRR487;                          /**< ldprofilereg487, offset: 0x1C */
  __IO uint32_t LDPRR488;                          /**< ldprofilereg488, offset: 0x20 */
  __IO uint32_t LDPRR489;                          /**< ldprofilereg489, offset: 0x24 */
  __IO uint32_t LDPRR48A;                          /**< ldprofilereg48a, offset: 0x28 */
  __IO uint32_t LDPRR48B;                          /**< ldprofilereg48b, offset: 0x2C */
  __IO uint32_t LDPRR48C;                          /**< ldprofilereg48c, offset: 0x30 */
  __IO uint32_t LDPRR48D;                          /**< ldprofilereg48d, offset: 0x34 */
  __IO uint32_t LDPRR48E;                          /**< ldprofilereg48e, offset: 0x38 */
  __IO uint32_t LDPRR48F;                          /**< ldprofilereg48f, offset: 0x3C */
  __IO uint32_t LDPRR490;                          /**< ldprofilereg490, offset: 0x40 */
  __IO uint32_t LDPRR491;                          /**< ldprofilereg491, offset: 0x44 */
  __IO uint32_t LDPRR492;                          /**< ldprofilereg492, offset: 0x48 */
  __IO uint32_t LDPRR493;                          /**< ldprofilereg493, offset: 0x4C */
  __IO uint32_t LDPRR494;                          /**< ldprofilereg494, offset: 0x50 */
  __IO uint32_t LDPRR495;                          /**< ldprofilereg495, offset: 0x54 */
  __IO uint32_t LDPRR496;                          /**< ldprofilereg496, offset: 0x58 */
  __IO uint32_t LDPRR497;                          /**< ldprofilereg497, offset: 0x5C */
} locald63_Type;

/* ----------------------------------------------------------------------------
   -- locald63 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald63_Register_Masks locald63 Register Masks
 * @{
 */

/*! @name LDPRR480 - ldprofilereg480 */
/*! @{ */

#define locald63_LDPRR480_lumd1729_MASK          (0x3FFU)
#define locald63_LDPRR480_lumd1729_SHIFT         (0U)
/*! lumd1729 - lumdat_1729 */
#define locald63_LDPRR480_lumd1729(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR480_lumd1729_SHIFT)) & locald63_LDPRR480_lumd1729_MASK)

#define locald63_LDPRR480_lumd1728_MASK          (0x3FF0000U)
#define locald63_LDPRR480_lumd1728_SHIFT         (16U)
/*! lumd1728 - lumdat_1728 */
#define locald63_LDPRR480_lumd1728(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR480_lumd1728_SHIFT)) & locald63_LDPRR480_lumd1728_MASK)
/*! @} */

/*! @name LDPRR481 - ldprofilereg481 */
/*! @{ */

#define locald63_LDPRR481_lumd1731_MASK          (0x3FFU)
#define locald63_LDPRR481_lumd1731_SHIFT         (0U)
/*! lumd1731 - lumdat_1731 */
#define locald63_LDPRR481_lumd1731(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR481_lumd1731_SHIFT)) & locald63_LDPRR481_lumd1731_MASK)

#define locald63_LDPRR481_lumd1730_MASK          (0x3FF0000U)
#define locald63_LDPRR481_lumd1730_SHIFT         (16U)
/*! lumd1730 - lumdat_1730 */
#define locald63_LDPRR481_lumd1730(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR481_lumd1730_SHIFT)) & locald63_LDPRR481_lumd1730_MASK)
/*! @} */

/*! @name LDPRR482 - ldprofilereg482 */
/*! @{ */

#define locald63_LDPRR482_lumd1733_MASK          (0x3FFU)
#define locald63_LDPRR482_lumd1733_SHIFT         (0U)
/*! lumd1733 - lumdat_1733 */
#define locald63_LDPRR482_lumd1733(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR482_lumd1733_SHIFT)) & locald63_LDPRR482_lumd1733_MASK)

#define locald63_LDPRR482_lumd1732_MASK          (0x3FF0000U)
#define locald63_LDPRR482_lumd1732_SHIFT         (16U)
/*! lumd1732 - lumdat_1732 */
#define locald63_LDPRR482_lumd1732(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR482_lumd1732_SHIFT)) & locald63_LDPRR482_lumd1732_MASK)
/*! @} */

/*! @name LDPRR483 - ldprofilereg483 */
/*! @{ */

#define locald63_LDPRR483_lumd1735_MASK          (0x3FFU)
#define locald63_LDPRR483_lumd1735_SHIFT         (0U)
/*! lumd1735 - lumdat_1735 */
#define locald63_LDPRR483_lumd1735(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR483_lumd1735_SHIFT)) & locald63_LDPRR483_lumd1735_MASK)

#define locald63_LDPRR483_lumd1734_MASK          (0x3FF0000U)
#define locald63_LDPRR483_lumd1734_SHIFT         (16U)
/*! lumd1734 - lumdat_1734 */
#define locald63_LDPRR483_lumd1734(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR483_lumd1734_SHIFT)) & locald63_LDPRR483_lumd1734_MASK)
/*! @} */

/*! @name LDPRR484 - ldprofilereg484 */
/*! @{ */

#define locald63_LDPRR484_lumd1737_MASK          (0x3FFU)
#define locald63_LDPRR484_lumd1737_SHIFT         (0U)
/*! lumd1737 - lumdat_1737 */
#define locald63_LDPRR484_lumd1737(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR484_lumd1737_SHIFT)) & locald63_LDPRR484_lumd1737_MASK)

#define locald63_LDPRR484_lumd1736_MASK          (0x3FF0000U)
#define locald63_LDPRR484_lumd1736_SHIFT         (16U)
/*! lumd1736 - lumdat_1736 */
#define locald63_LDPRR484_lumd1736(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR484_lumd1736_SHIFT)) & locald63_LDPRR484_lumd1736_MASK)
/*! @} */

/*! @name LDPRR485 - ldprofilereg485 */
/*! @{ */

#define locald63_LDPRR485_lumd1739_MASK          (0x3FFU)
#define locald63_LDPRR485_lumd1739_SHIFT         (0U)
/*! lumd1739 - lumdat_1739 */
#define locald63_LDPRR485_lumd1739(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR485_lumd1739_SHIFT)) & locald63_LDPRR485_lumd1739_MASK)

#define locald63_LDPRR485_lumd1738_MASK          (0x3FF0000U)
#define locald63_LDPRR485_lumd1738_SHIFT         (16U)
/*! lumd1738 - lumdat_1738 */
#define locald63_LDPRR485_lumd1738(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR485_lumd1738_SHIFT)) & locald63_LDPRR485_lumd1738_MASK)
/*! @} */

/*! @name LDPRR486 - ldprofilereg486 */
/*! @{ */

#define locald63_LDPRR486_lumd1741_MASK          (0x3FFU)
#define locald63_LDPRR486_lumd1741_SHIFT         (0U)
/*! lumd1741 - lumdat_1741 */
#define locald63_LDPRR486_lumd1741(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR486_lumd1741_SHIFT)) & locald63_LDPRR486_lumd1741_MASK)

#define locald63_LDPRR486_lumd1740_MASK          (0x3FF0000U)
#define locald63_LDPRR486_lumd1740_SHIFT         (16U)
/*! lumd1740 - lumdat_1740 */
#define locald63_LDPRR486_lumd1740(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR486_lumd1740_SHIFT)) & locald63_LDPRR486_lumd1740_MASK)
/*! @} */

/*! @name LDPRR487 - ldprofilereg487 */
/*! @{ */

#define locald63_LDPRR487_lumd1743_MASK          (0x3FFU)
#define locald63_LDPRR487_lumd1743_SHIFT         (0U)
/*! lumd1743 - lumdat_1743 */
#define locald63_LDPRR487_lumd1743(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR487_lumd1743_SHIFT)) & locald63_LDPRR487_lumd1743_MASK)

#define locald63_LDPRR487_lumd1742_MASK          (0x3FF0000U)
#define locald63_LDPRR487_lumd1742_SHIFT         (16U)
/*! lumd1742 - lumdat_1742 */
#define locald63_LDPRR487_lumd1742(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR487_lumd1742_SHIFT)) & locald63_LDPRR487_lumd1742_MASK)
/*! @} */

/*! @name LDPRR488 - ldprofilereg488 */
/*! @{ */

#define locald63_LDPRR488_lumd1745_MASK          (0x3FFU)
#define locald63_LDPRR488_lumd1745_SHIFT         (0U)
/*! lumd1745 - lumdat_1745 */
#define locald63_LDPRR488_lumd1745(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR488_lumd1745_SHIFT)) & locald63_LDPRR488_lumd1745_MASK)

#define locald63_LDPRR488_lumd1744_MASK          (0x3FF0000U)
#define locald63_LDPRR488_lumd1744_SHIFT         (16U)
/*! lumd1744 - lumdat_1744 */
#define locald63_LDPRR488_lumd1744(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR488_lumd1744_SHIFT)) & locald63_LDPRR488_lumd1744_MASK)
/*! @} */

/*! @name LDPRR489 - ldprofilereg489 */
/*! @{ */

#define locald63_LDPRR489_lumd1747_MASK          (0x3FFU)
#define locald63_LDPRR489_lumd1747_SHIFT         (0U)
/*! lumd1747 - lumdat_1747 */
#define locald63_LDPRR489_lumd1747(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR489_lumd1747_SHIFT)) & locald63_LDPRR489_lumd1747_MASK)

#define locald63_LDPRR489_lumd1746_MASK          (0x3FF0000U)
#define locald63_LDPRR489_lumd1746_SHIFT         (16U)
/*! lumd1746 - lumdat_1746 */
#define locald63_LDPRR489_lumd1746(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR489_lumd1746_SHIFT)) & locald63_LDPRR489_lumd1746_MASK)
/*! @} */

/*! @name LDPRR48A - ldprofilereg48a */
/*! @{ */

#define locald63_LDPRR48A_lumd1749_MASK          (0x3FFU)
#define locald63_LDPRR48A_lumd1749_SHIFT         (0U)
/*! lumd1749 - lumdat_1749 */
#define locald63_LDPRR48A_lumd1749(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48A_lumd1749_SHIFT)) & locald63_LDPRR48A_lumd1749_MASK)

#define locald63_LDPRR48A_lumd1748_MASK          (0x3FF0000U)
#define locald63_LDPRR48A_lumd1748_SHIFT         (16U)
/*! lumd1748 - lumdat_1748 */
#define locald63_LDPRR48A_lumd1748(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48A_lumd1748_SHIFT)) & locald63_LDPRR48A_lumd1748_MASK)
/*! @} */

/*! @name LDPRR48B - ldprofilereg48b */
/*! @{ */

#define locald63_LDPRR48B_lumd1751_MASK          (0x3FFU)
#define locald63_LDPRR48B_lumd1751_SHIFT         (0U)
/*! lumd1751 - lumdat_1751 */
#define locald63_LDPRR48B_lumd1751(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48B_lumd1751_SHIFT)) & locald63_LDPRR48B_lumd1751_MASK)

#define locald63_LDPRR48B_lumd1750_MASK          (0x3FF0000U)
#define locald63_LDPRR48B_lumd1750_SHIFT         (16U)
/*! lumd1750 - lumdat_1750 */
#define locald63_LDPRR48B_lumd1750(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48B_lumd1750_SHIFT)) & locald63_LDPRR48B_lumd1750_MASK)
/*! @} */

/*! @name LDPRR48C - ldprofilereg48c */
/*! @{ */

#define locald63_LDPRR48C_lumd1753_MASK          (0x3FFU)
#define locald63_LDPRR48C_lumd1753_SHIFT         (0U)
/*! lumd1753 - lumdat_1753 */
#define locald63_LDPRR48C_lumd1753(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48C_lumd1753_SHIFT)) & locald63_LDPRR48C_lumd1753_MASK)

#define locald63_LDPRR48C_lumd1752_MASK          (0x3FF0000U)
#define locald63_LDPRR48C_lumd1752_SHIFT         (16U)
/*! lumd1752 - lumdat_1752 */
#define locald63_LDPRR48C_lumd1752(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48C_lumd1752_SHIFT)) & locald63_LDPRR48C_lumd1752_MASK)
/*! @} */

/*! @name LDPRR48D - ldprofilereg48d */
/*! @{ */

#define locald63_LDPRR48D_lumd1755_MASK          (0x3FFU)
#define locald63_LDPRR48D_lumd1755_SHIFT         (0U)
/*! lumd1755 - lumdat_1755 */
#define locald63_LDPRR48D_lumd1755(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48D_lumd1755_SHIFT)) & locald63_LDPRR48D_lumd1755_MASK)

#define locald63_LDPRR48D_lumd1754_MASK          (0x3FF0000U)
#define locald63_LDPRR48D_lumd1754_SHIFT         (16U)
/*! lumd1754 - lumdat_1754 */
#define locald63_LDPRR48D_lumd1754(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48D_lumd1754_SHIFT)) & locald63_LDPRR48D_lumd1754_MASK)
/*! @} */

/*! @name LDPRR48E - ldprofilereg48e */
/*! @{ */

#define locald63_LDPRR48E_lumd1757_MASK          (0x3FFU)
#define locald63_LDPRR48E_lumd1757_SHIFT         (0U)
/*! lumd1757 - lumdat_1757 */
#define locald63_LDPRR48E_lumd1757(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48E_lumd1757_SHIFT)) & locald63_LDPRR48E_lumd1757_MASK)

#define locald63_LDPRR48E_lumd1756_MASK          (0x3FF0000U)
#define locald63_LDPRR48E_lumd1756_SHIFT         (16U)
/*! lumd1756 - lumdat_1756 */
#define locald63_LDPRR48E_lumd1756(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48E_lumd1756_SHIFT)) & locald63_LDPRR48E_lumd1756_MASK)
/*! @} */

/*! @name LDPRR48F - ldprofilereg48f */
/*! @{ */

#define locald63_LDPRR48F_lumd1759_MASK          (0x3FFU)
#define locald63_LDPRR48F_lumd1759_SHIFT         (0U)
/*! lumd1759 - lumdat_1759 */
#define locald63_LDPRR48F_lumd1759(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48F_lumd1759_SHIFT)) & locald63_LDPRR48F_lumd1759_MASK)

#define locald63_LDPRR48F_lumd1758_MASK          (0x3FF0000U)
#define locald63_LDPRR48F_lumd1758_SHIFT         (16U)
/*! lumd1758 - lumdat_1758 */
#define locald63_LDPRR48F_lumd1758(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR48F_lumd1758_SHIFT)) & locald63_LDPRR48F_lumd1758_MASK)
/*! @} */

/*! @name LDPRR490 - ldprofilereg490 */
/*! @{ */

#define locald63_LDPRR490_lumd1761_MASK          (0x3FFU)
#define locald63_LDPRR490_lumd1761_SHIFT         (0U)
/*! lumd1761 - lumdat_1761 */
#define locald63_LDPRR490_lumd1761(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR490_lumd1761_SHIFT)) & locald63_LDPRR490_lumd1761_MASK)

#define locald63_LDPRR490_lumd1760_MASK          (0x3FF0000U)
#define locald63_LDPRR490_lumd1760_SHIFT         (16U)
/*! lumd1760 - lumdat_1760 */
#define locald63_LDPRR490_lumd1760(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR490_lumd1760_SHIFT)) & locald63_LDPRR490_lumd1760_MASK)
/*! @} */

/*! @name LDPRR491 - ldprofilereg491 */
/*! @{ */

#define locald63_LDPRR491_lumd1763_MASK          (0x3FFU)
#define locald63_LDPRR491_lumd1763_SHIFT         (0U)
/*! lumd1763 - lumdat_1763 */
#define locald63_LDPRR491_lumd1763(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR491_lumd1763_SHIFT)) & locald63_LDPRR491_lumd1763_MASK)

#define locald63_LDPRR491_lumd1762_MASK          (0x3FF0000U)
#define locald63_LDPRR491_lumd1762_SHIFT         (16U)
/*! lumd1762 - lumdat_1762 */
#define locald63_LDPRR491_lumd1762(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR491_lumd1762_SHIFT)) & locald63_LDPRR491_lumd1762_MASK)
/*! @} */

/*! @name LDPRR492 - ldprofilereg492 */
/*! @{ */

#define locald63_LDPRR492_lumd1765_MASK          (0x3FFU)
#define locald63_LDPRR492_lumd1765_SHIFT         (0U)
/*! lumd1765 - lumdat_1765 */
#define locald63_LDPRR492_lumd1765(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR492_lumd1765_SHIFT)) & locald63_LDPRR492_lumd1765_MASK)

#define locald63_LDPRR492_lumd1764_MASK          (0x3FF0000U)
#define locald63_LDPRR492_lumd1764_SHIFT         (16U)
/*! lumd1764 - lumdat_1764 */
#define locald63_LDPRR492_lumd1764(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR492_lumd1764_SHIFT)) & locald63_LDPRR492_lumd1764_MASK)
/*! @} */

/*! @name LDPRR493 - ldprofilereg493 */
/*! @{ */

#define locald63_LDPRR493_lumd1767_MASK          (0x3FFU)
#define locald63_LDPRR493_lumd1767_SHIFT         (0U)
/*! lumd1767 - lumdat_1767 */
#define locald63_LDPRR493_lumd1767(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR493_lumd1767_SHIFT)) & locald63_LDPRR493_lumd1767_MASK)

#define locald63_LDPRR493_lumd1766_MASK          (0x3FF0000U)
#define locald63_LDPRR493_lumd1766_SHIFT         (16U)
/*! lumd1766 - lumdat_1766 */
#define locald63_LDPRR493_lumd1766(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR493_lumd1766_SHIFT)) & locald63_LDPRR493_lumd1766_MASK)
/*! @} */

/*! @name LDPRR494 - ldprofilereg494 */
/*! @{ */

#define locald63_LDPRR494_lumd1769_MASK          (0x3FFU)
#define locald63_LDPRR494_lumd1769_SHIFT         (0U)
/*! lumd1769 - lumdat_1769 */
#define locald63_LDPRR494_lumd1769(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR494_lumd1769_SHIFT)) & locald63_LDPRR494_lumd1769_MASK)

#define locald63_LDPRR494_lumd1768_MASK          (0x3FF0000U)
#define locald63_LDPRR494_lumd1768_SHIFT         (16U)
/*! lumd1768 - lumdat_1768 */
#define locald63_LDPRR494_lumd1768(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR494_lumd1768_SHIFT)) & locald63_LDPRR494_lumd1768_MASK)
/*! @} */

/*! @name LDPRR495 - ldprofilereg495 */
/*! @{ */

#define locald63_LDPRR495_lumd1771_MASK          (0x3FFU)
#define locald63_LDPRR495_lumd1771_SHIFT         (0U)
/*! lumd1771 - lumdat_1771 */
#define locald63_LDPRR495_lumd1771(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR495_lumd1771_SHIFT)) & locald63_LDPRR495_lumd1771_MASK)

#define locald63_LDPRR495_lumd1770_MASK          (0x3FF0000U)
#define locald63_LDPRR495_lumd1770_SHIFT         (16U)
/*! lumd1770 - lumdat_1770 */
#define locald63_LDPRR495_lumd1770(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR495_lumd1770_SHIFT)) & locald63_LDPRR495_lumd1770_MASK)
/*! @} */

/*! @name LDPRR496 - ldprofilereg496 */
/*! @{ */

#define locald63_LDPRR496_lumd1773_MASK          (0x3FFU)
#define locald63_LDPRR496_lumd1773_SHIFT         (0U)
/*! lumd1773 - lumdat_1773 */
#define locald63_LDPRR496_lumd1773(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR496_lumd1773_SHIFT)) & locald63_LDPRR496_lumd1773_MASK)

#define locald63_LDPRR496_lumd1772_MASK          (0x3FF0000U)
#define locald63_LDPRR496_lumd1772_SHIFT         (16U)
/*! lumd1772 - lumdat_1772 */
#define locald63_LDPRR496_lumd1772(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR496_lumd1772_SHIFT)) & locald63_LDPRR496_lumd1772_MASK)
/*! @} */

/*! @name LDPRR497 - ldprofilereg497 */
/*! @{ */

#define locald63_LDPRR497_lumd1775_MASK          (0x3FFU)
#define locald63_LDPRR497_lumd1775_SHIFT         (0U)
/*! lumd1775 - lumdat_1775 */
#define locald63_LDPRR497_lumd1775(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR497_lumd1775_SHIFT)) & locald63_LDPRR497_lumd1775_MASK)

#define locald63_LDPRR497_lumd1774_MASK          (0x3FF0000U)
#define locald63_LDPRR497_lumd1774_SHIFT         (16U)
/*! lumd1774 - lumdat_1774 */
#define locald63_LDPRR497_lumd1774(x)            (((uint32_t)(((uint32_t)(x)) << locald63_LDPRR497_lumd1774_SHIFT)) & locald63_LDPRR497_lumd1774_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald63_Register_Masks */


/*!
 * @}
 */ /* end of group locald63_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD63_H_ */

