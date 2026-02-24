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
**         CMSIS Peripheral Access Layer for locald65
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
 * @file PERI_locald65.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald65
 *
 * CMSIS Peripheral Access Layer for locald65
 */

#if !defined(PERI_LOCALD65_H_)
#define PERI_LOCALD65_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald65 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald65_Peripheral_Access_Layer locald65 Peripheral Access Layer
 * @{
 */

/** locald65 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR4C0;                          /**< ldprofilereg4c0, offset: 0x0 */
  __IO uint32_t LDPRR4C1;                          /**< ldprofilereg4c1, offset: 0x4 */
  __IO uint32_t LDPRR4C2;                          /**< ldprofilereg4c2, offset: 0x8 */
  __IO uint32_t LDPRR4C3;                          /**< ldprofilereg4c3, offset: 0xC */
  __IO uint32_t LDPRR4C4;                          /**< ldprofilereg4c4, offset: 0x10 */
  __IO uint32_t LDPRR4C5;                          /**< ldprofilereg4c5, offset: 0x14 */
  __IO uint32_t LDPRR4C6;                          /**< ldprofilereg4c6, offset: 0x18 */
  __IO uint32_t LDPRR4C7;                          /**< ldprofilereg4c7, offset: 0x1C */
  __IO uint32_t LDPRR4C8;                          /**< ldprofilereg4c8, offset: 0x20 */
  __IO uint32_t LDPRR4C9;                          /**< ldprofilereg4c9, offset: 0x24 */
  __IO uint32_t LDPRR4CA;                          /**< ldprofilereg4ca, offset: 0x28 */
  __IO uint32_t LDPRR4CB;                          /**< ldprofilereg4cb, offset: 0x2C */
  __IO uint32_t LDPRR4CC;                          /**< ldprofilereg4cc, offset: 0x30 */
  __IO uint32_t LDPRR4CD;                          /**< ldprofilereg4cd, offset: 0x34 */
  __IO uint32_t LDPRR4CE;                          /**< ldprofilereg4ce, offset: 0x38 */
  __IO uint32_t LDPRR4CF;                          /**< ldprofilereg4cf, offset: 0x3C */
  __IO uint32_t LDPRR4D0;                          /**< ldprofilereg4d0, offset: 0x40 */
  __IO uint32_t LDPRR4D1;                          /**< ldprofilereg4d1, offset: 0x44 */
  __IO uint32_t LDPRR4D2;                          /**< ldprofilereg4d2, offset: 0x48 */
  __IO uint32_t LDPRR4D3;                          /**< ldprofilereg4d3, offset: 0x4C */
  __IO uint32_t LDPRR4D4;                          /**< ldprofilereg4d4, offset: 0x50 */
  __IO uint32_t LDPRR4D5;                          /**< ldprofilereg4d5, offset: 0x54 */
  __IO uint32_t LDPRR4D6;                          /**< ldprofilereg4d6, offset: 0x58 */
  __IO uint32_t LDPRR4D7;                          /**< ldprofilereg4d7, offset: 0x5C */
} locald65_Type;

/* ----------------------------------------------------------------------------
   -- locald65 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald65_Register_Masks locald65 Register Masks
 * @{
 */

/*! @name LDPRR4C0 - ldprofilereg4c0 */
/*! @{ */

#define locald65_LDPRR4C0_lumd1825_MASK          (0x3FFU)
#define locald65_LDPRR4C0_lumd1825_SHIFT         (0U)
/*! lumd1825 - lumdat_1825 */
#define locald65_LDPRR4C0_lumd1825(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C0_lumd1825_SHIFT)) & locald65_LDPRR4C0_lumd1825_MASK)

#define locald65_LDPRR4C0_lumd1824_MASK          (0x3FF0000U)
#define locald65_LDPRR4C0_lumd1824_SHIFT         (16U)
/*! lumd1824 - lumdat_1824 */
#define locald65_LDPRR4C0_lumd1824(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C0_lumd1824_SHIFT)) & locald65_LDPRR4C0_lumd1824_MASK)
/*! @} */

/*! @name LDPRR4C1 - ldprofilereg4c1 */
/*! @{ */

#define locald65_LDPRR4C1_lumd1827_MASK          (0x3FFU)
#define locald65_LDPRR4C1_lumd1827_SHIFT         (0U)
/*! lumd1827 - lumdat_1827 */
#define locald65_LDPRR4C1_lumd1827(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C1_lumd1827_SHIFT)) & locald65_LDPRR4C1_lumd1827_MASK)

#define locald65_LDPRR4C1_lumd1826_MASK          (0x3FF0000U)
#define locald65_LDPRR4C1_lumd1826_SHIFT         (16U)
/*! lumd1826 - lumdat_1826 */
#define locald65_LDPRR4C1_lumd1826(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C1_lumd1826_SHIFT)) & locald65_LDPRR4C1_lumd1826_MASK)
/*! @} */

/*! @name LDPRR4C2 - ldprofilereg4c2 */
/*! @{ */

#define locald65_LDPRR4C2_lumd1829_MASK          (0x3FFU)
#define locald65_LDPRR4C2_lumd1829_SHIFT         (0U)
/*! lumd1829 - lumdat_1829 */
#define locald65_LDPRR4C2_lumd1829(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C2_lumd1829_SHIFT)) & locald65_LDPRR4C2_lumd1829_MASK)

#define locald65_LDPRR4C2_lumd1828_MASK          (0x3FF0000U)
#define locald65_LDPRR4C2_lumd1828_SHIFT         (16U)
/*! lumd1828 - lumdat_1828 */
#define locald65_LDPRR4C2_lumd1828(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C2_lumd1828_SHIFT)) & locald65_LDPRR4C2_lumd1828_MASK)
/*! @} */

/*! @name LDPRR4C3 - ldprofilereg4c3 */
/*! @{ */

#define locald65_LDPRR4C3_lumd1831_MASK          (0x3FFU)
#define locald65_LDPRR4C3_lumd1831_SHIFT         (0U)
/*! lumd1831 - lumdat_1831 */
#define locald65_LDPRR4C3_lumd1831(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C3_lumd1831_SHIFT)) & locald65_LDPRR4C3_lumd1831_MASK)

#define locald65_LDPRR4C3_lumd1830_MASK          (0x3FF0000U)
#define locald65_LDPRR4C3_lumd1830_SHIFT         (16U)
/*! lumd1830 - lumdat_1830 */
#define locald65_LDPRR4C3_lumd1830(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C3_lumd1830_SHIFT)) & locald65_LDPRR4C3_lumd1830_MASK)
/*! @} */

/*! @name LDPRR4C4 - ldprofilereg4c4 */
/*! @{ */

#define locald65_LDPRR4C4_lumd1833_MASK          (0x3FFU)
#define locald65_LDPRR4C4_lumd1833_SHIFT         (0U)
/*! lumd1833 - lumdat_1833 */
#define locald65_LDPRR4C4_lumd1833(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C4_lumd1833_SHIFT)) & locald65_LDPRR4C4_lumd1833_MASK)

#define locald65_LDPRR4C4_lumd1832_MASK          (0x3FF0000U)
#define locald65_LDPRR4C4_lumd1832_SHIFT         (16U)
/*! lumd1832 - lumdat_1832 */
#define locald65_LDPRR4C4_lumd1832(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C4_lumd1832_SHIFT)) & locald65_LDPRR4C4_lumd1832_MASK)
/*! @} */

/*! @name LDPRR4C5 - ldprofilereg4c5 */
/*! @{ */

#define locald65_LDPRR4C5_lumd1835_MASK          (0x3FFU)
#define locald65_LDPRR4C5_lumd1835_SHIFT         (0U)
/*! lumd1835 - lumdat_1835 */
#define locald65_LDPRR4C5_lumd1835(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C5_lumd1835_SHIFT)) & locald65_LDPRR4C5_lumd1835_MASK)

#define locald65_LDPRR4C5_lumd1834_MASK          (0x3FF0000U)
#define locald65_LDPRR4C5_lumd1834_SHIFT         (16U)
/*! lumd1834 - lumdat_1834 */
#define locald65_LDPRR4C5_lumd1834(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C5_lumd1834_SHIFT)) & locald65_LDPRR4C5_lumd1834_MASK)
/*! @} */

/*! @name LDPRR4C6 - ldprofilereg4c6 */
/*! @{ */

#define locald65_LDPRR4C6_lumd1837_MASK          (0x3FFU)
#define locald65_LDPRR4C6_lumd1837_SHIFT         (0U)
/*! lumd1837 - lumdat_1837 */
#define locald65_LDPRR4C6_lumd1837(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C6_lumd1837_SHIFT)) & locald65_LDPRR4C6_lumd1837_MASK)

#define locald65_LDPRR4C6_lumd1836_MASK          (0x3FF0000U)
#define locald65_LDPRR4C6_lumd1836_SHIFT         (16U)
/*! lumd1836 - lumdat_1836 */
#define locald65_LDPRR4C6_lumd1836(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C6_lumd1836_SHIFT)) & locald65_LDPRR4C6_lumd1836_MASK)
/*! @} */

/*! @name LDPRR4C7 - ldprofilereg4c7 */
/*! @{ */

#define locald65_LDPRR4C7_lumd1839_MASK          (0x3FFU)
#define locald65_LDPRR4C7_lumd1839_SHIFT         (0U)
/*! lumd1839 - lumdat_1839 */
#define locald65_LDPRR4C7_lumd1839(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C7_lumd1839_SHIFT)) & locald65_LDPRR4C7_lumd1839_MASK)

#define locald65_LDPRR4C7_lumd1838_MASK          (0x3FF0000U)
#define locald65_LDPRR4C7_lumd1838_SHIFT         (16U)
/*! lumd1838 - lumdat_1838 */
#define locald65_LDPRR4C7_lumd1838(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C7_lumd1838_SHIFT)) & locald65_LDPRR4C7_lumd1838_MASK)
/*! @} */

/*! @name LDPRR4C8 - ldprofilereg4c8 */
/*! @{ */

#define locald65_LDPRR4C8_lumd1841_MASK          (0x3FFU)
#define locald65_LDPRR4C8_lumd1841_SHIFT         (0U)
/*! lumd1841 - lumdat_1841 */
#define locald65_LDPRR4C8_lumd1841(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C8_lumd1841_SHIFT)) & locald65_LDPRR4C8_lumd1841_MASK)

#define locald65_LDPRR4C8_lumd1840_MASK          (0x3FF0000U)
#define locald65_LDPRR4C8_lumd1840_SHIFT         (16U)
/*! lumd1840 - lumdat_1840 */
#define locald65_LDPRR4C8_lumd1840(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C8_lumd1840_SHIFT)) & locald65_LDPRR4C8_lumd1840_MASK)
/*! @} */

/*! @name LDPRR4C9 - ldprofilereg4c9 */
/*! @{ */

#define locald65_LDPRR4C9_lumd1843_MASK          (0x3FFU)
#define locald65_LDPRR4C9_lumd1843_SHIFT         (0U)
/*! lumd1843 - lumdat_1843 */
#define locald65_LDPRR4C9_lumd1843(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C9_lumd1843_SHIFT)) & locald65_LDPRR4C9_lumd1843_MASK)

#define locald65_LDPRR4C9_lumd1842_MASK          (0x3FF0000U)
#define locald65_LDPRR4C9_lumd1842_SHIFT         (16U)
/*! lumd1842 - lumdat_1842 */
#define locald65_LDPRR4C9_lumd1842(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4C9_lumd1842_SHIFT)) & locald65_LDPRR4C9_lumd1842_MASK)
/*! @} */

/*! @name LDPRR4CA - ldprofilereg4ca */
/*! @{ */

#define locald65_LDPRR4CA_lumd1845_MASK          (0x3FFU)
#define locald65_LDPRR4CA_lumd1845_SHIFT         (0U)
/*! lumd1845 - lumdat_1845 */
#define locald65_LDPRR4CA_lumd1845(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CA_lumd1845_SHIFT)) & locald65_LDPRR4CA_lumd1845_MASK)

#define locald65_LDPRR4CA_lumd1844_MASK          (0x3FF0000U)
#define locald65_LDPRR4CA_lumd1844_SHIFT         (16U)
/*! lumd1844 - lumdat_1844 */
#define locald65_LDPRR4CA_lumd1844(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CA_lumd1844_SHIFT)) & locald65_LDPRR4CA_lumd1844_MASK)
/*! @} */

/*! @name LDPRR4CB - ldprofilereg4cb */
/*! @{ */

#define locald65_LDPRR4CB_lumd1847_MASK          (0x3FFU)
#define locald65_LDPRR4CB_lumd1847_SHIFT         (0U)
/*! lumd1847 - lumdat_1847 */
#define locald65_LDPRR4CB_lumd1847(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CB_lumd1847_SHIFT)) & locald65_LDPRR4CB_lumd1847_MASK)

#define locald65_LDPRR4CB_lumd1846_MASK          (0x3FF0000U)
#define locald65_LDPRR4CB_lumd1846_SHIFT         (16U)
/*! lumd1846 - lumdat_1846 */
#define locald65_LDPRR4CB_lumd1846(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CB_lumd1846_SHIFT)) & locald65_LDPRR4CB_lumd1846_MASK)
/*! @} */

/*! @name LDPRR4CC - ldprofilereg4cc */
/*! @{ */

#define locald65_LDPRR4CC_lumd1849_MASK          (0x3FFU)
#define locald65_LDPRR4CC_lumd1849_SHIFT         (0U)
/*! lumd1849 - lumdat_1849 */
#define locald65_LDPRR4CC_lumd1849(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CC_lumd1849_SHIFT)) & locald65_LDPRR4CC_lumd1849_MASK)

#define locald65_LDPRR4CC_lumd1848_MASK          (0x3FF0000U)
#define locald65_LDPRR4CC_lumd1848_SHIFT         (16U)
/*! lumd1848 - lumdat_1848 */
#define locald65_LDPRR4CC_lumd1848(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CC_lumd1848_SHIFT)) & locald65_LDPRR4CC_lumd1848_MASK)
/*! @} */

/*! @name LDPRR4CD - ldprofilereg4cd */
/*! @{ */

#define locald65_LDPRR4CD_lumd1851_MASK          (0x3FFU)
#define locald65_LDPRR4CD_lumd1851_SHIFT         (0U)
/*! lumd1851 - lumdat_1851 */
#define locald65_LDPRR4CD_lumd1851(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CD_lumd1851_SHIFT)) & locald65_LDPRR4CD_lumd1851_MASK)

#define locald65_LDPRR4CD_lumd1850_MASK          (0x3FF0000U)
#define locald65_LDPRR4CD_lumd1850_SHIFT         (16U)
/*! lumd1850 - lumdat_1850 */
#define locald65_LDPRR4CD_lumd1850(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CD_lumd1850_SHIFT)) & locald65_LDPRR4CD_lumd1850_MASK)
/*! @} */

/*! @name LDPRR4CE - ldprofilereg4ce */
/*! @{ */

#define locald65_LDPRR4CE_lumd1853_MASK          (0x3FFU)
#define locald65_LDPRR4CE_lumd1853_SHIFT         (0U)
/*! lumd1853 - lumdat_1853 */
#define locald65_LDPRR4CE_lumd1853(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CE_lumd1853_SHIFT)) & locald65_LDPRR4CE_lumd1853_MASK)

#define locald65_LDPRR4CE_lumd1852_MASK          (0x3FF0000U)
#define locald65_LDPRR4CE_lumd1852_SHIFT         (16U)
/*! lumd1852 - lumdat_1852 */
#define locald65_LDPRR4CE_lumd1852(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CE_lumd1852_SHIFT)) & locald65_LDPRR4CE_lumd1852_MASK)
/*! @} */

/*! @name LDPRR4CF - ldprofilereg4cf */
/*! @{ */

#define locald65_LDPRR4CF_lumd1855_MASK          (0x3FFU)
#define locald65_LDPRR4CF_lumd1855_SHIFT         (0U)
/*! lumd1855 - lumdat_1855 */
#define locald65_LDPRR4CF_lumd1855(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CF_lumd1855_SHIFT)) & locald65_LDPRR4CF_lumd1855_MASK)

#define locald65_LDPRR4CF_lumd1854_MASK          (0x3FF0000U)
#define locald65_LDPRR4CF_lumd1854_SHIFT         (16U)
/*! lumd1854 - lumdat_1854 */
#define locald65_LDPRR4CF_lumd1854(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4CF_lumd1854_SHIFT)) & locald65_LDPRR4CF_lumd1854_MASK)
/*! @} */

/*! @name LDPRR4D0 - ldprofilereg4d0 */
/*! @{ */

#define locald65_LDPRR4D0_lumd1857_MASK          (0x3FFU)
#define locald65_LDPRR4D0_lumd1857_SHIFT         (0U)
/*! lumd1857 - lumdat_1857 */
#define locald65_LDPRR4D0_lumd1857(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D0_lumd1857_SHIFT)) & locald65_LDPRR4D0_lumd1857_MASK)

#define locald65_LDPRR4D0_lumd1856_MASK          (0x3FF0000U)
#define locald65_LDPRR4D0_lumd1856_SHIFT         (16U)
/*! lumd1856 - lumdat_1856 */
#define locald65_LDPRR4D0_lumd1856(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D0_lumd1856_SHIFT)) & locald65_LDPRR4D0_lumd1856_MASK)
/*! @} */

/*! @name LDPRR4D1 - ldprofilereg4d1 */
/*! @{ */

#define locald65_LDPRR4D1_lumd1859_MASK          (0x3FFU)
#define locald65_LDPRR4D1_lumd1859_SHIFT         (0U)
/*! lumd1859 - lumdat_1859 */
#define locald65_LDPRR4D1_lumd1859(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D1_lumd1859_SHIFT)) & locald65_LDPRR4D1_lumd1859_MASK)

#define locald65_LDPRR4D1_lumd1858_MASK          (0x3FF0000U)
#define locald65_LDPRR4D1_lumd1858_SHIFT         (16U)
/*! lumd1858 - lumdat_1858 */
#define locald65_LDPRR4D1_lumd1858(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D1_lumd1858_SHIFT)) & locald65_LDPRR4D1_lumd1858_MASK)
/*! @} */

/*! @name LDPRR4D2 - ldprofilereg4d2 */
/*! @{ */

#define locald65_LDPRR4D2_lumd1861_MASK          (0x3FFU)
#define locald65_LDPRR4D2_lumd1861_SHIFT         (0U)
/*! lumd1861 - lumdat_1861 */
#define locald65_LDPRR4D2_lumd1861(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D2_lumd1861_SHIFT)) & locald65_LDPRR4D2_lumd1861_MASK)

#define locald65_LDPRR4D2_lumd1860_MASK          (0x3FF0000U)
#define locald65_LDPRR4D2_lumd1860_SHIFT         (16U)
/*! lumd1860 - lumdat_1860 */
#define locald65_LDPRR4D2_lumd1860(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D2_lumd1860_SHIFT)) & locald65_LDPRR4D2_lumd1860_MASK)
/*! @} */

/*! @name LDPRR4D3 - ldprofilereg4d3 */
/*! @{ */

#define locald65_LDPRR4D3_lumd1863_MASK          (0x3FFU)
#define locald65_LDPRR4D3_lumd1863_SHIFT         (0U)
/*! lumd1863 - lumdat_1863 */
#define locald65_LDPRR4D3_lumd1863(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D3_lumd1863_SHIFT)) & locald65_LDPRR4D3_lumd1863_MASK)

#define locald65_LDPRR4D3_lumd1862_MASK          (0x3FF0000U)
#define locald65_LDPRR4D3_lumd1862_SHIFT         (16U)
/*! lumd1862 - lumdat_1862 */
#define locald65_LDPRR4D3_lumd1862(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D3_lumd1862_SHIFT)) & locald65_LDPRR4D3_lumd1862_MASK)
/*! @} */

/*! @name LDPRR4D4 - ldprofilereg4d4 */
/*! @{ */

#define locald65_LDPRR4D4_lumd1865_MASK          (0x3FFU)
#define locald65_LDPRR4D4_lumd1865_SHIFT         (0U)
/*! lumd1865 - lumdat_1865 */
#define locald65_LDPRR4D4_lumd1865(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D4_lumd1865_SHIFT)) & locald65_LDPRR4D4_lumd1865_MASK)

#define locald65_LDPRR4D4_lumd1864_MASK          (0x3FF0000U)
#define locald65_LDPRR4D4_lumd1864_SHIFT         (16U)
/*! lumd1864 - lumdat_1864 */
#define locald65_LDPRR4D4_lumd1864(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D4_lumd1864_SHIFT)) & locald65_LDPRR4D4_lumd1864_MASK)
/*! @} */

/*! @name LDPRR4D5 - ldprofilereg4d5 */
/*! @{ */

#define locald65_LDPRR4D5_lumd1867_MASK          (0x3FFU)
#define locald65_LDPRR4D5_lumd1867_SHIFT         (0U)
/*! lumd1867 - lumdat_1867 */
#define locald65_LDPRR4D5_lumd1867(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D5_lumd1867_SHIFT)) & locald65_LDPRR4D5_lumd1867_MASK)

#define locald65_LDPRR4D5_lumd1866_MASK          (0x3FF0000U)
#define locald65_LDPRR4D5_lumd1866_SHIFT         (16U)
/*! lumd1866 - lumdat_1866 */
#define locald65_LDPRR4D5_lumd1866(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D5_lumd1866_SHIFT)) & locald65_LDPRR4D5_lumd1866_MASK)
/*! @} */

/*! @name LDPRR4D6 - ldprofilereg4d6 */
/*! @{ */

#define locald65_LDPRR4D6_lumd1869_MASK          (0x3FFU)
#define locald65_LDPRR4D6_lumd1869_SHIFT         (0U)
/*! lumd1869 - lumdat_1869 */
#define locald65_LDPRR4D6_lumd1869(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D6_lumd1869_SHIFT)) & locald65_LDPRR4D6_lumd1869_MASK)

#define locald65_LDPRR4D6_lumd1868_MASK          (0x3FF0000U)
#define locald65_LDPRR4D6_lumd1868_SHIFT         (16U)
/*! lumd1868 - lumdat_1868 */
#define locald65_LDPRR4D6_lumd1868(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D6_lumd1868_SHIFT)) & locald65_LDPRR4D6_lumd1868_MASK)
/*! @} */

/*! @name LDPRR4D7 - ldprofilereg4d7 */
/*! @{ */

#define locald65_LDPRR4D7_lumd1871_MASK          (0x3FFU)
#define locald65_LDPRR4D7_lumd1871_SHIFT         (0U)
/*! lumd1871 - lumdat_1871 */
#define locald65_LDPRR4D7_lumd1871(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D7_lumd1871_SHIFT)) & locald65_LDPRR4D7_lumd1871_MASK)

#define locald65_LDPRR4D7_lumd1870_MASK          (0x3FF0000U)
#define locald65_LDPRR4D7_lumd1870_SHIFT         (16U)
/*! lumd1870 - lumdat_1870 */
#define locald65_LDPRR4D7_lumd1870(x)            (((uint32_t)(((uint32_t)(x)) << locald65_LDPRR4D7_lumd1870_SHIFT)) & locald65_LDPRR4D7_lumd1870_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald65_Register_Masks */


/*!
 * @}
 */ /* end of group locald65_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD65_H_ */

