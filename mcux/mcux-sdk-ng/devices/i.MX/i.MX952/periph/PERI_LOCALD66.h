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
**         CMSIS Peripheral Access Layer for locald66
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
 * @file PERI_locald66.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald66
 *
 * CMSIS Peripheral Access Layer for locald66
 */

#if !defined(PERI_LOCALD66_H_)
#define PERI_LOCALD66_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald66 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald66_Peripheral_Access_Layer locald66 Peripheral Access Layer
 * @{
 */

/** locald66 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR4E0;                          /**< ldprofilereg4e0, offset: 0x0 */
  __IO uint32_t LDPRR4E1;                          /**< ldprofilereg4e1, offset: 0x4 */
  __IO uint32_t LDPRR4E2;                          /**< ldprofilereg4e2, offset: 0x8 */
  __IO uint32_t LDPRR4E3;                          /**< ldprofilereg4e3, offset: 0xC */
  __IO uint32_t LDPRR4E4;                          /**< ldprofilereg4e4, offset: 0x10 */
  __IO uint32_t LDPRR4E5;                          /**< ldprofilereg4e5, offset: 0x14 */
  __IO uint32_t LDPRR4E6;                          /**< ldprofilereg4e6, offset: 0x18 */
  __IO uint32_t LDPRR4E7;                          /**< ldprofilereg4e7, offset: 0x1C */
  __IO uint32_t LDPRR4E8;                          /**< ldprofilereg4e8, offset: 0x20 */
  __IO uint32_t LDPRR4E9;                          /**< ldprofilereg4e9, offset: 0x24 */
  __IO uint32_t LDPRR4EA;                          /**< ldprofilereg4ea, offset: 0x28 */
  __IO uint32_t LDPRR4EB;                          /**< ldprofilereg4eb, offset: 0x2C */
  __IO uint32_t LDPRR4EC;                          /**< ldprofilereg4ec, offset: 0x30 */
  __IO uint32_t LDPRR4ED;                          /**< ldprofilereg4ed, offset: 0x34 */
  __IO uint32_t LDPRR4EE;                          /**< ldprofilereg4ee, offset: 0x38 */
  __IO uint32_t LDPRR4EF;                          /**< ldprofilereg4ef, offset: 0x3C */
  __IO uint32_t LDPRR4F0;                          /**< ldprofilereg4f0, offset: 0x40 */
  __IO uint32_t LDPRR4F1;                          /**< ldprofilereg4f1, offset: 0x44 */
  __IO uint32_t LDPRR4F2;                          /**< ldprofilereg4f2, offset: 0x48 */
  __IO uint32_t LDPRR4F3;                          /**< ldprofilereg4f3, offset: 0x4C */
  __IO uint32_t LDPRR4F4;                          /**< ldprofilereg4f4, offset: 0x50 */
  __IO uint32_t LDPRR4F5;                          /**< ldprofilereg4f5, offset: 0x54 */
  __IO uint32_t LDPRR4F6;                          /**< ldprofilereg4f6, offset: 0x58 */
  __IO uint32_t LDPRR4F7;                          /**< ldprofilereg4f7, offset: 0x5C */
} locald66_Type;

/* ----------------------------------------------------------------------------
   -- locald66 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald66_Register_Masks locald66 Register Masks
 * @{
 */

/*! @name LDPRR4E0 - ldprofilereg4e0 */
/*! @{ */

#define locald66_LDPRR4E0_lumd1873_MASK          (0x3FFU)
#define locald66_LDPRR4E0_lumd1873_SHIFT         (0U)
/*! lumd1873 - lumdat_1873 */
#define locald66_LDPRR4E0_lumd1873(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E0_lumd1873_SHIFT)) & locald66_LDPRR4E0_lumd1873_MASK)

#define locald66_LDPRR4E0_lumd1872_MASK          (0x3FF0000U)
#define locald66_LDPRR4E0_lumd1872_SHIFT         (16U)
/*! lumd1872 - lumdat_1872 */
#define locald66_LDPRR4E0_lumd1872(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E0_lumd1872_SHIFT)) & locald66_LDPRR4E0_lumd1872_MASK)
/*! @} */

/*! @name LDPRR4E1 - ldprofilereg4e1 */
/*! @{ */

#define locald66_LDPRR4E1_lumd1875_MASK          (0x3FFU)
#define locald66_LDPRR4E1_lumd1875_SHIFT         (0U)
/*! lumd1875 - lumdat_1875 */
#define locald66_LDPRR4E1_lumd1875(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E1_lumd1875_SHIFT)) & locald66_LDPRR4E1_lumd1875_MASK)

#define locald66_LDPRR4E1_lumd1874_MASK          (0x3FF0000U)
#define locald66_LDPRR4E1_lumd1874_SHIFT         (16U)
/*! lumd1874 - lumdat_1874 */
#define locald66_LDPRR4E1_lumd1874(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E1_lumd1874_SHIFT)) & locald66_LDPRR4E1_lumd1874_MASK)
/*! @} */

/*! @name LDPRR4E2 - ldprofilereg4e2 */
/*! @{ */

#define locald66_LDPRR4E2_lumd1877_MASK          (0x3FFU)
#define locald66_LDPRR4E2_lumd1877_SHIFT         (0U)
/*! lumd1877 - lumdat_1877 */
#define locald66_LDPRR4E2_lumd1877(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E2_lumd1877_SHIFT)) & locald66_LDPRR4E2_lumd1877_MASK)

#define locald66_LDPRR4E2_lumd1876_MASK          (0x3FF0000U)
#define locald66_LDPRR4E2_lumd1876_SHIFT         (16U)
/*! lumd1876 - lumdat_1876 */
#define locald66_LDPRR4E2_lumd1876(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E2_lumd1876_SHIFT)) & locald66_LDPRR4E2_lumd1876_MASK)
/*! @} */

/*! @name LDPRR4E3 - ldprofilereg4e3 */
/*! @{ */

#define locald66_LDPRR4E3_lumd1879_MASK          (0x3FFU)
#define locald66_LDPRR4E3_lumd1879_SHIFT         (0U)
/*! lumd1879 - lumdat_1879 */
#define locald66_LDPRR4E3_lumd1879(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E3_lumd1879_SHIFT)) & locald66_LDPRR4E3_lumd1879_MASK)

#define locald66_LDPRR4E3_lumd1878_MASK          (0x3FF0000U)
#define locald66_LDPRR4E3_lumd1878_SHIFT         (16U)
/*! lumd1878 - lumdat_1878 */
#define locald66_LDPRR4E3_lumd1878(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E3_lumd1878_SHIFT)) & locald66_LDPRR4E3_lumd1878_MASK)
/*! @} */

/*! @name LDPRR4E4 - ldprofilereg4e4 */
/*! @{ */

#define locald66_LDPRR4E4_lumd1881_MASK          (0x3FFU)
#define locald66_LDPRR4E4_lumd1881_SHIFT         (0U)
/*! lumd1881 - lumdat_1881 */
#define locald66_LDPRR4E4_lumd1881(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E4_lumd1881_SHIFT)) & locald66_LDPRR4E4_lumd1881_MASK)

#define locald66_LDPRR4E4_lumd1880_MASK          (0x3FF0000U)
#define locald66_LDPRR4E4_lumd1880_SHIFT         (16U)
/*! lumd1880 - lumdat_1880 */
#define locald66_LDPRR4E4_lumd1880(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E4_lumd1880_SHIFT)) & locald66_LDPRR4E4_lumd1880_MASK)
/*! @} */

/*! @name LDPRR4E5 - ldprofilereg4e5 */
/*! @{ */

#define locald66_LDPRR4E5_lumd1883_MASK          (0x3FFU)
#define locald66_LDPRR4E5_lumd1883_SHIFT         (0U)
/*! lumd1883 - lumdat_1883 */
#define locald66_LDPRR4E5_lumd1883(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E5_lumd1883_SHIFT)) & locald66_LDPRR4E5_lumd1883_MASK)

#define locald66_LDPRR4E5_lumd1882_MASK          (0x3FF0000U)
#define locald66_LDPRR4E5_lumd1882_SHIFT         (16U)
/*! lumd1882 - lumdat_1882 */
#define locald66_LDPRR4E5_lumd1882(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E5_lumd1882_SHIFT)) & locald66_LDPRR4E5_lumd1882_MASK)
/*! @} */

/*! @name LDPRR4E6 - ldprofilereg4e6 */
/*! @{ */

#define locald66_LDPRR4E6_lumd1885_MASK          (0x3FFU)
#define locald66_LDPRR4E6_lumd1885_SHIFT         (0U)
/*! lumd1885 - lumdat_1885 */
#define locald66_LDPRR4E6_lumd1885(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E6_lumd1885_SHIFT)) & locald66_LDPRR4E6_lumd1885_MASK)

#define locald66_LDPRR4E6_lumd1884_MASK          (0x3FF0000U)
#define locald66_LDPRR4E6_lumd1884_SHIFT         (16U)
/*! lumd1884 - lumdat_1884 */
#define locald66_LDPRR4E6_lumd1884(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E6_lumd1884_SHIFT)) & locald66_LDPRR4E6_lumd1884_MASK)
/*! @} */

/*! @name LDPRR4E7 - ldprofilereg4e7 */
/*! @{ */

#define locald66_LDPRR4E7_lumd1887_MASK          (0x3FFU)
#define locald66_LDPRR4E7_lumd1887_SHIFT         (0U)
/*! lumd1887 - lumdat_1887 */
#define locald66_LDPRR4E7_lumd1887(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E7_lumd1887_SHIFT)) & locald66_LDPRR4E7_lumd1887_MASK)

#define locald66_LDPRR4E7_lumd1886_MASK          (0x3FF0000U)
#define locald66_LDPRR4E7_lumd1886_SHIFT         (16U)
/*! lumd1886 - lumdat_1886 */
#define locald66_LDPRR4E7_lumd1886(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E7_lumd1886_SHIFT)) & locald66_LDPRR4E7_lumd1886_MASK)
/*! @} */

/*! @name LDPRR4E8 - ldprofilereg4e8 */
/*! @{ */

#define locald66_LDPRR4E8_lumd1889_MASK          (0x3FFU)
#define locald66_LDPRR4E8_lumd1889_SHIFT         (0U)
/*! lumd1889 - lumdat_1889 */
#define locald66_LDPRR4E8_lumd1889(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E8_lumd1889_SHIFT)) & locald66_LDPRR4E8_lumd1889_MASK)

#define locald66_LDPRR4E8_lumd1888_MASK          (0x3FF0000U)
#define locald66_LDPRR4E8_lumd1888_SHIFT         (16U)
/*! lumd1888 - lumdat_1888 */
#define locald66_LDPRR4E8_lumd1888(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E8_lumd1888_SHIFT)) & locald66_LDPRR4E8_lumd1888_MASK)
/*! @} */

/*! @name LDPRR4E9 - ldprofilereg4e9 */
/*! @{ */

#define locald66_LDPRR4E9_lumd1891_MASK          (0x3FFU)
#define locald66_LDPRR4E9_lumd1891_SHIFT         (0U)
/*! lumd1891 - lumdat_1891 */
#define locald66_LDPRR4E9_lumd1891(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E9_lumd1891_SHIFT)) & locald66_LDPRR4E9_lumd1891_MASK)

#define locald66_LDPRR4E9_lumd1890_MASK          (0x3FF0000U)
#define locald66_LDPRR4E9_lumd1890_SHIFT         (16U)
/*! lumd1890 - lumdat_1890 */
#define locald66_LDPRR4E9_lumd1890(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4E9_lumd1890_SHIFT)) & locald66_LDPRR4E9_lumd1890_MASK)
/*! @} */

/*! @name LDPRR4EA - ldprofilereg4ea */
/*! @{ */

#define locald66_LDPRR4EA_lumd1893_MASK          (0x3FFU)
#define locald66_LDPRR4EA_lumd1893_SHIFT         (0U)
/*! lumd1893 - lumdat_1893 */
#define locald66_LDPRR4EA_lumd1893(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4EA_lumd1893_SHIFT)) & locald66_LDPRR4EA_lumd1893_MASK)

#define locald66_LDPRR4EA_lumd1892_MASK          (0x3FF0000U)
#define locald66_LDPRR4EA_lumd1892_SHIFT         (16U)
/*! lumd1892 - lumdat_1892 */
#define locald66_LDPRR4EA_lumd1892(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4EA_lumd1892_SHIFT)) & locald66_LDPRR4EA_lumd1892_MASK)
/*! @} */

/*! @name LDPRR4EB - ldprofilereg4eb */
/*! @{ */

#define locald66_LDPRR4EB_lumd1895_MASK          (0x3FFU)
#define locald66_LDPRR4EB_lumd1895_SHIFT         (0U)
/*! lumd1895 - lumdat_1895 */
#define locald66_LDPRR4EB_lumd1895(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4EB_lumd1895_SHIFT)) & locald66_LDPRR4EB_lumd1895_MASK)

#define locald66_LDPRR4EB_lumd1894_MASK          (0x3FF0000U)
#define locald66_LDPRR4EB_lumd1894_SHIFT         (16U)
/*! lumd1894 - lumdat_1894 */
#define locald66_LDPRR4EB_lumd1894(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4EB_lumd1894_SHIFT)) & locald66_LDPRR4EB_lumd1894_MASK)
/*! @} */

/*! @name LDPRR4EC - ldprofilereg4ec */
/*! @{ */

#define locald66_LDPRR4EC_lumd1897_MASK          (0x3FFU)
#define locald66_LDPRR4EC_lumd1897_SHIFT         (0U)
/*! lumd1897 - lumdat_1897 */
#define locald66_LDPRR4EC_lumd1897(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4EC_lumd1897_SHIFT)) & locald66_LDPRR4EC_lumd1897_MASK)

#define locald66_LDPRR4EC_lumd1896_MASK          (0x3FF0000U)
#define locald66_LDPRR4EC_lumd1896_SHIFT         (16U)
/*! lumd1896 - lumdat_1896 */
#define locald66_LDPRR4EC_lumd1896(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4EC_lumd1896_SHIFT)) & locald66_LDPRR4EC_lumd1896_MASK)
/*! @} */

/*! @name LDPRR4ED - ldprofilereg4ed */
/*! @{ */

#define locald66_LDPRR4ED_lumd1899_MASK          (0x3FFU)
#define locald66_LDPRR4ED_lumd1899_SHIFT         (0U)
/*! lumd1899 - lumdat_1899 */
#define locald66_LDPRR4ED_lumd1899(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4ED_lumd1899_SHIFT)) & locald66_LDPRR4ED_lumd1899_MASK)

#define locald66_LDPRR4ED_lumd1898_MASK          (0x3FF0000U)
#define locald66_LDPRR4ED_lumd1898_SHIFT         (16U)
/*! lumd1898 - lumdat_1898 */
#define locald66_LDPRR4ED_lumd1898(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4ED_lumd1898_SHIFT)) & locald66_LDPRR4ED_lumd1898_MASK)
/*! @} */

/*! @name LDPRR4EE - ldprofilereg4ee */
/*! @{ */

#define locald66_LDPRR4EE_lumd1901_MASK          (0x3FFU)
#define locald66_LDPRR4EE_lumd1901_SHIFT         (0U)
/*! lumd1901 - lumdat_1901 */
#define locald66_LDPRR4EE_lumd1901(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4EE_lumd1901_SHIFT)) & locald66_LDPRR4EE_lumd1901_MASK)

#define locald66_LDPRR4EE_lumd1900_MASK          (0x3FF0000U)
#define locald66_LDPRR4EE_lumd1900_SHIFT         (16U)
/*! lumd1900 - lumdat_1900 */
#define locald66_LDPRR4EE_lumd1900(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4EE_lumd1900_SHIFT)) & locald66_LDPRR4EE_lumd1900_MASK)
/*! @} */

/*! @name LDPRR4EF - ldprofilereg4ef */
/*! @{ */

#define locald66_LDPRR4EF_lumd1903_MASK          (0x3FFU)
#define locald66_LDPRR4EF_lumd1903_SHIFT         (0U)
/*! lumd1903 - lumdat_1903 */
#define locald66_LDPRR4EF_lumd1903(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4EF_lumd1903_SHIFT)) & locald66_LDPRR4EF_lumd1903_MASK)

#define locald66_LDPRR4EF_lumd1902_MASK          (0x3FF0000U)
#define locald66_LDPRR4EF_lumd1902_SHIFT         (16U)
/*! lumd1902 - lumdat_1902 */
#define locald66_LDPRR4EF_lumd1902(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4EF_lumd1902_SHIFT)) & locald66_LDPRR4EF_lumd1902_MASK)
/*! @} */

/*! @name LDPRR4F0 - ldprofilereg4f0 */
/*! @{ */

#define locald66_LDPRR4F0_lumd1905_MASK          (0x3FFU)
#define locald66_LDPRR4F0_lumd1905_SHIFT         (0U)
/*! lumd1905 - lumdat_1905 */
#define locald66_LDPRR4F0_lumd1905(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F0_lumd1905_SHIFT)) & locald66_LDPRR4F0_lumd1905_MASK)

#define locald66_LDPRR4F0_lumd1904_MASK          (0x3FF0000U)
#define locald66_LDPRR4F0_lumd1904_SHIFT         (16U)
/*! lumd1904 - lumdat_1904 */
#define locald66_LDPRR4F0_lumd1904(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F0_lumd1904_SHIFT)) & locald66_LDPRR4F0_lumd1904_MASK)
/*! @} */

/*! @name LDPRR4F1 - ldprofilereg4f1 */
/*! @{ */

#define locald66_LDPRR4F1_lumd1907_MASK          (0x3FFU)
#define locald66_LDPRR4F1_lumd1907_SHIFT         (0U)
/*! lumd1907 - lumdat_1907 */
#define locald66_LDPRR4F1_lumd1907(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F1_lumd1907_SHIFT)) & locald66_LDPRR4F1_lumd1907_MASK)

#define locald66_LDPRR4F1_lumd1906_MASK          (0x3FF0000U)
#define locald66_LDPRR4F1_lumd1906_SHIFT         (16U)
/*! lumd1906 - lumdat_1906 */
#define locald66_LDPRR4F1_lumd1906(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F1_lumd1906_SHIFT)) & locald66_LDPRR4F1_lumd1906_MASK)
/*! @} */

/*! @name LDPRR4F2 - ldprofilereg4f2 */
/*! @{ */

#define locald66_LDPRR4F2_lumd1909_MASK          (0x3FFU)
#define locald66_LDPRR4F2_lumd1909_SHIFT         (0U)
/*! lumd1909 - lumdat_1909 */
#define locald66_LDPRR4F2_lumd1909(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F2_lumd1909_SHIFT)) & locald66_LDPRR4F2_lumd1909_MASK)

#define locald66_LDPRR4F2_lumd1908_MASK          (0x3FF0000U)
#define locald66_LDPRR4F2_lumd1908_SHIFT         (16U)
/*! lumd1908 - lumdat_1908 */
#define locald66_LDPRR4F2_lumd1908(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F2_lumd1908_SHIFT)) & locald66_LDPRR4F2_lumd1908_MASK)
/*! @} */

/*! @name LDPRR4F3 - ldprofilereg4f3 */
/*! @{ */

#define locald66_LDPRR4F3_lumd1911_MASK          (0x3FFU)
#define locald66_LDPRR4F3_lumd1911_SHIFT         (0U)
/*! lumd1911 - lumdat_1911 */
#define locald66_LDPRR4F3_lumd1911(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F3_lumd1911_SHIFT)) & locald66_LDPRR4F3_lumd1911_MASK)

#define locald66_LDPRR4F3_lumd1910_MASK          (0x3FF0000U)
#define locald66_LDPRR4F3_lumd1910_SHIFT         (16U)
/*! lumd1910 - lumdat_1910 */
#define locald66_LDPRR4F3_lumd1910(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F3_lumd1910_SHIFT)) & locald66_LDPRR4F3_lumd1910_MASK)
/*! @} */

/*! @name LDPRR4F4 - ldprofilereg4f4 */
/*! @{ */

#define locald66_LDPRR4F4_lumd1913_MASK          (0x3FFU)
#define locald66_LDPRR4F4_lumd1913_SHIFT         (0U)
/*! lumd1913 - lumdat_1913 */
#define locald66_LDPRR4F4_lumd1913(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F4_lumd1913_SHIFT)) & locald66_LDPRR4F4_lumd1913_MASK)

#define locald66_LDPRR4F4_lumd1912_MASK          (0x3FF0000U)
#define locald66_LDPRR4F4_lumd1912_SHIFT         (16U)
/*! lumd1912 - lumdat_1912 */
#define locald66_LDPRR4F4_lumd1912(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F4_lumd1912_SHIFT)) & locald66_LDPRR4F4_lumd1912_MASK)
/*! @} */

/*! @name LDPRR4F5 - ldprofilereg4f5 */
/*! @{ */

#define locald66_LDPRR4F5_lumd1915_MASK          (0x3FFU)
#define locald66_LDPRR4F5_lumd1915_SHIFT         (0U)
/*! lumd1915 - lumdat_1915 */
#define locald66_LDPRR4F5_lumd1915(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F5_lumd1915_SHIFT)) & locald66_LDPRR4F5_lumd1915_MASK)

#define locald66_LDPRR4F5_lumd1914_MASK          (0x3FF0000U)
#define locald66_LDPRR4F5_lumd1914_SHIFT         (16U)
/*! lumd1914 - lumdat_1914 */
#define locald66_LDPRR4F5_lumd1914(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F5_lumd1914_SHIFT)) & locald66_LDPRR4F5_lumd1914_MASK)
/*! @} */

/*! @name LDPRR4F6 - ldprofilereg4f6 */
/*! @{ */

#define locald66_LDPRR4F6_lumd1917_MASK          (0x3FFU)
#define locald66_LDPRR4F6_lumd1917_SHIFT         (0U)
/*! lumd1917 - lumdat_1917 */
#define locald66_LDPRR4F6_lumd1917(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F6_lumd1917_SHIFT)) & locald66_LDPRR4F6_lumd1917_MASK)

#define locald66_LDPRR4F6_lumd1916_MASK          (0x3FF0000U)
#define locald66_LDPRR4F6_lumd1916_SHIFT         (16U)
/*! lumd1916 - lumdat_1916 */
#define locald66_LDPRR4F6_lumd1916(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F6_lumd1916_SHIFT)) & locald66_LDPRR4F6_lumd1916_MASK)
/*! @} */

/*! @name LDPRR4F7 - ldprofilereg4f7 */
/*! @{ */

#define locald66_LDPRR4F7_lumd1919_MASK          (0x3FFU)
#define locald66_LDPRR4F7_lumd1919_SHIFT         (0U)
/*! lumd1919 - lumdat_1919 */
#define locald66_LDPRR4F7_lumd1919(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F7_lumd1919_SHIFT)) & locald66_LDPRR4F7_lumd1919_MASK)

#define locald66_LDPRR4F7_lumd1918_MASK          (0x3FF0000U)
#define locald66_LDPRR4F7_lumd1918_SHIFT         (16U)
/*! lumd1918 - lumdat_1918 */
#define locald66_LDPRR4F7_lumd1918(x)            (((uint32_t)(((uint32_t)(x)) << locald66_LDPRR4F7_lumd1918_SHIFT)) & locald66_LDPRR4F7_lumd1918_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald66_Register_Masks */


/*!
 * @}
 */ /* end of group locald66_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD66_H_ */

