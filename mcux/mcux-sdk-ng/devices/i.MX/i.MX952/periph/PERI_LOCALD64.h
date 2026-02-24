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
**         CMSIS Peripheral Access Layer for locald64
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
 * @file PERI_locald64.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald64
 *
 * CMSIS Peripheral Access Layer for locald64
 */

#if !defined(PERI_LOCALD64_H_)
#define PERI_LOCALD64_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald64 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald64_Peripheral_Access_Layer locald64 Peripheral Access Layer
 * @{
 */

/** locald64 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR4A0;                          /**< ldprofilereg4a0, offset: 0x0 */
  __IO uint32_t LDPRR4A1;                          /**< ldprofilereg4a1, offset: 0x4 */
  __IO uint32_t LDPRR4A2;                          /**< ldprofilereg4a2, offset: 0x8 */
  __IO uint32_t LDPRR4A3;                          /**< ldprofilereg4a3, offset: 0xC */
  __IO uint32_t LDPRR4A4;                          /**< ldprofilereg4a4, offset: 0x10 */
  __IO uint32_t LDPRR4A5;                          /**< ldprofilereg4a5, offset: 0x14 */
  __IO uint32_t LDPRR4A6;                          /**< ldprofilereg4a6, offset: 0x18 */
  __IO uint32_t LDPRR4A7;                          /**< ldprofilereg4a7, offset: 0x1C */
  __IO uint32_t LDPRR4A8;                          /**< ldprofilereg4a8, offset: 0x20 */
  __IO uint32_t LDPRR4A9;                          /**< ldprofilereg4a9, offset: 0x24 */
  __IO uint32_t LDPRR4AA;                          /**< ldprofilereg4aa, offset: 0x28 */
  __IO uint32_t LDPRR4AB;                          /**< ldprofilereg4ab, offset: 0x2C */
  __IO uint32_t LDPRR4AC;                          /**< ldprofilereg4ac, offset: 0x30 */
  __IO uint32_t LDPRR4AD;                          /**< ldprofilereg4ad, offset: 0x34 */
  __IO uint32_t LDPRR4AE;                          /**< ldprofilereg4ae, offset: 0x38 */
  __IO uint32_t LDPRR4AF;                          /**< ldprofilereg4af, offset: 0x3C */
  __IO uint32_t LDPRR4B0;                          /**< ldprofilereg4b0, offset: 0x40 */
  __IO uint32_t LDPRR4B1;                          /**< ldprofilereg4b1, offset: 0x44 */
  __IO uint32_t LDPRR4B2;                          /**< ldprofilereg4b2, offset: 0x48 */
  __IO uint32_t LDPRR4B3;                          /**< ldprofilereg4b3, offset: 0x4C */
  __IO uint32_t LDPRR4B4;                          /**< ldprofilereg4b4, offset: 0x50 */
  __IO uint32_t LDPRR4B5;                          /**< ldprofilereg4b5, offset: 0x54 */
  __IO uint32_t LDPRR4B6;                          /**< ldprofilereg4b6, offset: 0x58 */
  __IO uint32_t LDPRR4B7;                          /**< ldprofilereg4b7, offset: 0x5C */
} locald64_Type;

/* ----------------------------------------------------------------------------
   -- locald64 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald64_Register_Masks locald64 Register Masks
 * @{
 */

/*! @name LDPRR4A0 - ldprofilereg4a0 */
/*! @{ */

#define locald64_LDPRR4A0_lumd1777_MASK          (0x3FFU)
#define locald64_LDPRR4A0_lumd1777_SHIFT         (0U)
/*! lumd1777 - lumdat_1777 */
#define locald64_LDPRR4A0_lumd1777(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A0_lumd1777_SHIFT)) & locald64_LDPRR4A0_lumd1777_MASK)

#define locald64_LDPRR4A0_lumd1776_MASK          (0x3FF0000U)
#define locald64_LDPRR4A0_lumd1776_SHIFT         (16U)
/*! lumd1776 - lumdat_1776 */
#define locald64_LDPRR4A0_lumd1776(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A0_lumd1776_SHIFT)) & locald64_LDPRR4A0_lumd1776_MASK)
/*! @} */

/*! @name LDPRR4A1 - ldprofilereg4a1 */
/*! @{ */

#define locald64_LDPRR4A1_lumd1779_MASK          (0x3FFU)
#define locald64_LDPRR4A1_lumd1779_SHIFT         (0U)
/*! lumd1779 - lumdat_1779 */
#define locald64_LDPRR4A1_lumd1779(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A1_lumd1779_SHIFT)) & locald64_LDPRR4A1_lumd1779_MASK)

#define locald64_LDPRR4A1_lumd1778_MASK          (0x3FF0000U)
#define locald64_LDPRR4A1_lumd1778_SHIFT         (16U)
/*! lumd1778 - lumdat_1778 */
#define locald64_LDPRR4A1_lumd1778(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A1_lumd1778_SHIFT)) & locald64_LDPRR4A1_lumd1778_MASK)
/*! @} */

/*! @name LDPRR4A2 - ldprofilereg4a2 */
/*! @{ */

#define locald64_LDPRR4A2_lumd1781_MASK          (0x3FFU)
#define locald64_LDPRR4A2_lumd1781_SHIFT         (0U)
/*! lumd1781 - lumdat_1781 */
#define locald64_LDPRR4A2_lumd1781(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A2_lumd1781_SHIFT)) & locald64_LDPRR4A2_lumd1781_MASK)

#define locald64_LDPRR4A2_lumd1780_MASK          (0x3FF0000U)
#define locald64_LDPRR4A2_lumd1780_SHIFT         (16U)
/*! lumd1780 - lumdat_1780 */
#define locald64_LDPRR4A2_lumd1780(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A2_lumd1780_SHIFT)) & locald64_LDPRR4A2_lumd1780_MASK)
/*! @} */

/*! @name LDPRR4A3 - ldprofilereg4a3 */
/*! @{ */

#define locald64_LDPRR4A3_lumd1783_MASK          (0x3FFU)
#define locald64_LDPRR4A3_lumd1783_SHIFT         (0U)
/*! lumd1783 - lumdat_1783 */
#define locald64_LDPRR4A3_lumd1783(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A3_lumd1783_SHIFT)) & locald64_LDPRR4A3_lumd1783_MASK)

#define locald64_LDPRR4A3_lumd1782_MASK          (0x3FF0000U)
#define locald64_LDPRR4A3_lumd1782_SHIFT         (16U)
/*! lumd1782 - lumdat_1782 */
#define locald64_LDPRR4A3_lumd1782(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A3_lumd1782_SHIFT)) & locald64_LDPRR4A3_lumd1782_MASK)
/*! @} */

/*! @name LDPRR4A4 - ldprofilereg4a4 */
/*! @{ */

#define locald64_LDPRR4A4_lumd1785_MASK          (0x3FFU)
#define locald64_LDPRR4A4_lumd1785_SHIFT         (0U)
/*! lumd1785 - lumdat_1785 */
#define locald64_LDPRR4A4_lumd1785(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A4_lumd1785_SHIFT)) & locald64_LDPRR4A4_lumd1785_MASK)

#define locald64_LDPRR4A4_lumd1784_MASK          (0x3FF0000U)
#define locald64_LDPRR4A4_lumd1784_SHIFT         (16U)
/*! lumd1784 - lumdat_1784 */
#define locald64_LDPRR4A4_lumd1784(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A4_lumd1784_SHIFT)) & locald64_LDPRR4A4_lumd1784_MASK)
/*! @} */

/*! @name LDPRR4A5 - ldprofilereg4a5 */
/*! @{ */

#define locald64_LDPRR4A5_lumd1787_MASK          (0x3FFU)
#define locald64_LDPRR4A5_lumd1787_SHIFT         (0U)
/*! lumd1787 - lumdat_1787 */
#define locald64_LDPRR4A5_lumd1787(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A5_lumd1787_SHIFT)) & locald64_LDPRR4A5_lumd1787_MASK)

#define locald64_LDPRR4A5_lumd1786_MASK          (0x3FF0000U)
#define locald64_LDPRR4A5_lumd1786_SHIFT         (16U)
/*! lumd1786 - lumdat_1786 */
#define locald64_LDPRR4A5_lumd1786(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A5_lumd1786_SHIFT)) & locald64_LDPRR4A5_lumd1786_MASK)
/*! @} */

/*! @name LDPRR4A6 - ldprofilereg4a6 */
/*! @{ */

#define locald64_LDPRR4A6_lumd1789_MASK          (0x3FFU)
#define locald64_LDPRR4A6_lumd1789_SHIFT         (0U)
/*! lumd1789 - lumdat_1789 */
#define locald64_LDPRR4A6_lumd1789(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A6_lumd1789_SHIFT)) & locald64_LDPRR4A6_lumd1789_MASK)

#define locald64_LDPRR4A6_lumd1788_MASK          (0x3FF0000U)
#define locald64_LDPRR4A6_lumd1788_SHIFT         (16U)
/*! lumd1788 - lumdat_1788 */
#define locald64_LDPRR4A6_lumd1788(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A6_lumd1788_SHIFT)) & locald64_LDPRR4A6_lumd1788_MASK)
/*! @} */

/*! @name LDPRR4A7 - ldprofilereg4a7 */
/*! @{ */

#define locald64_LDPRR4A7_lumd1791_MASK          (0x3FFU)
#define locald64_LDPRR4A7_lumd1791_SHIFT         (0U)
/*! lumd1791 - lumdat_1791 */
#define locald64_LDPRR4A7_lumd1791(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A7_lumd1791_SHIFT)) & locald64_LDPRR4A7_lumd1791_MASK)

#define locald64_LDPRR4A7_lumd1790_MASK          (0x3FF0000U)
#define locald64_LDPRR4A7_lumd1790_SHIFT         (16U)
/*! lumd1790 - lumdat_1790 */
#define locald64_LDPRR4A7_lumd1790(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A7_lumd1790_SHIFT)) & locald64_LDPRR4A7_lumd1790_MASK)
/*! @} */

/*! @name LDPRR4A8 - ldprofilereg4a8 */
/*! @{ */

#define locald64_LDPRR4A8_lumd1793_MASK          (0x3FFU)
#define locald64_LDPRR4A8_lumd1793_SHIFT         (0U)
/*! lumd1793 - lumdat_1793 */
#define locald64_LDPRR4A8_lumd1793(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A8_lumd1793_SHIFT)) & locald64_LDPRR4A8_lumd1793_MASK)

#define locald64_LDPRR4A8_lumd1792_MASK          (0x3FF0000U)
#define locald64_LDPRR4A8_lumd1792_SHIFT         (16U)
/*! lumd1792 - lumdat_1792 */
#define locald64_LDPRR4A8_lumd1792(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A8_lumd1792_SHIFT)) & locald64_LDPRR4A8_lumd1792_MASK)
/*! @} */

/*! @name LDPRR4A9 - ldprofilereg4a9 */
/*! @{ */

#define locald64_LDPRR4A9_lumd1795_MASK          (0x3FFU)
#define locald64_LDPRR4A9_lumd1795_SHIFT         (0U)
/*! lumd1795 - lumdat_1795 */
#define locald64_LDPRR4A9_lumd1795(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A9_lumd1795_SHIFT)) & locald64_LDPRR4A9_lumd1795_MASK)

#define locald64_LDPRR4A9_lumd1794_MASK          (0x3FF0000U)
#define locald64_LDPRR4A9_lumd1794_SHIFT         (16U)
/*! lumd1794 - lumdat_1794 */
#define locald64_LDPRR4A9_lumd1794(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4A9_lumd1794_SHIFT)) & locald64_LDPRR4A9_lumd1794_MASK)
/*! @} */

/*! @name LDPRR4AA - ldprofilereg4aa */
/*! @{ */

#define locald64_LDPRR4AA_lumd1797_MASK          (0x3FFU)
#define locald64_LDPRR4AA_lumd1797_SHIFT         (0U)
/*! lumd1797 - lumdat_1797 */
#define locald64_LDPRR4AA_lumd1797(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AA_lumd1797_SHIFT)) & locald64_LDPRR4AA_lumd1797_MASK)

#define locald64_LDPRR4AA_lumd1796_MASK          (0x3FF0000U)
#define locald64_LDPRR4AA_lumd1796_SHIFT         (16U)
/*! lumd1796 - lumdat_1796 */
#define locald64_LDPRR4AA_lumd1796(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AA_lumd1796_SHIFT)) & locald64_LDPRR4AA_lumd1796_MASK)
/*! @} */

/*! @name LDPRR4AB - ldprofilereg4ab */
/*! @{ */

#define locald64_LDPRR4AB_lumd1799_MASK          (0x3FFU)
#define locald64_LDPRR4AB_lumd1799_SHIFT         (0U)
/*! lumd1799 - lumdat_1799 */
#define locald64_LDPRR4AB_lumd1799(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AB_lumd1799_SHIFT)) & locald64_LDPRR4AB_lumd1799_MASK)

#define locald64_LDPRR4AB_lumd1798_MASK          (0x3FF0000U)
#define locald64_LDPRR4AB_lumd1798_SHIFT         (16U)
/*! lumd1798 - lumdat_1798 */
#define locald64_LDPRR4AB_lumd1798(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AB_lumd1798_SHIFT)) & locald64_LDPRR4AB_lumd1798_MASK)
/*! @} */

/*! @name LDPRR4AC - ldprofilereg4ac */
/*! @{ */

#define locald64_LDPRR4AC_lumd1801_MASK          (0x3FFU)
#define locald64_LDPRR4AC_lumd1801_SHIFT         (0U)
/*! lumd1801 - lumdat_1801 */
#define locald64_LDPRR4AC_lumd1801(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AC_lumd1801_SHIFT)) & locald64_LDPRR4AC_lumd1801_MASK)

#define locald64_LDPRR4AC_lumd1800_MASK          (0x3FF0000U)
#define locald64_LDPRR4AC_lumd1800_SHIFT         (16U)
/*! lumd1800 - lumdat_1800 */
#define locald64_LDPRR4AC_lumd1800(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AC_lumd1800_SHIFT)) & locald64_LDPRR4AC_lumd1800_MASK)
/*! @} */

/*! @name LDPRR4AD - ldprofilereg4ad */
/*! @{ */

#define locald64_LDPRR4AD_lumd1803_MASK          (0x3FFU)
#define locald64_LDPRR4AD_lumd1803_SHIFT         (0U)
/*! lumd1803 - lumdat_1803 */
#define locald64_LDPRR4AD_lumd1803(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AD_lumd1803_SHIFT)) & locald64_LDPRR4AD_lumd1803_MASK)

#define locald64_LDPRR4AD_lumd1802_MASK          (0x3FF0000U)
#define locald64_LDPRR4AD_lumd1802_SHIFT         (16U)
/*! lumd1802 - lumdat_1802 */
#define locald64_LDPRR4AD_lumd1802(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AD_lumd1802_SHIFT)) & locald64_LDPRR4AD_lumd1802_MASK)
/*! @} */

/*! @name LDPRR4AE - ldprofilereg4ae */
/*! @{ */

#define locald64_LDPRR4AE_lumd1805_MASK          (0x3FFU)
#define locald64_LDPRR4AE_lumd1805_SHIFT         (0U)
/*! lumd1805 - lumdat_1805 */
#define locald64_LDPRR4AE_lumd1805(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AE_lumd1805_SHIFT)) & locald64_LDPRR4AE_lumd1805_MASK)

#define locald64_LDPRR4AE_lumd1804_MASK          (0x3FF0000U)
#define locald64_LDPRR4AE_lumd1804_SHIFT         (16U)
/*! lumd1804 - lumdat_1804 */
#define locald64_LDPRR4AE_lumd1804(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AE_lumd1804_SHIFT)) & locald64_LDPRR4AE_lumd1804_MASK)
/*! @} */

/*! @name LDPRR4AF - ldprofilereg4af */
/*! @{ */

#define locald64_LDPRR4AF_lumd1807_MASK          (0x3FFU)
#define locald64_LDPRR4AF_lumd1807_SHIFT         (0U)
/*! lumd1807 - lumdat_1807 */
#define locald64_LDPRR4AF_lumd1807(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AF_lumd1807_SHIFT)) & locald64_LDPRR4AF_lumd1807_MASK)

#define locald64_LDPRR4AF_lumd1806_MASK          (0x3FF0000U)
#define locald64_LDPRR4AF_lumd1806_SHIFT         (16U)
/*! lumd1806 - lumdat_1806 */
#define locald64_LDPRR4AF_lumd1806(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4AF_lumd1806_SHIFT)) & locald64_LDPRR4AF_lumd1806_MASK)
/*! @} */

/*! @name LDPRR4B0 - ldprofilereg4b0 */
/*! @{ */

#define locald64_LDPRR4B0_lumd1809_MASK          (0x3FFU)
#define locald64_LDPRR4B0_lumd1809_SHIFT         (0U)
/*! lumd1809 - lumdat_1809 */
#define locald64_LDPRR4B0_lumd1809(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B0_lumd1809_SHIFT)) & locald64_LDPRR4B0_lumd1809_MASK)

#define locald64_LDPRR4B0_lumd1808_MASK          (0x3FF0000U)
#define locald64_LDPRR4B0_lumd1808_SHIFT         (16U)
/*! lumd1808 - lumdat_1808 */
#define locald64_LDPRR4B0_lumd1808(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B0_lumd1808_SHIFT)) & locald64_LDPRR4B0_lumd1808_MASK)
/*! @} */

/*! @name LDPRR4B1 - ldprofilereg4b1 */
/*! @{ */

#define locald64_LDPRR4B1_lumd1811_MASK          (0x3FFU)
#define locald64_LDPRR4B1_lumd1811_SHIFT         (0U)
/*! lumd1811 - lumdat_1811 */
#define locald64_LDPRR4B1_lumd1811(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B1_lumd1811_SHIFT)) & locald64_LDPRR4B1_lumd1811_MASK)

#define locald64_LDPRR4B1_lumd1810_MASK          (0x3FF0000U)
#define locald64_LDPRR4B1_lumd1810_SHIFT         (16U)
/*! lumd1810 - lumdat_1810 */
#define locald64_LDPRR4B1_lumd1810(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B1_lumd1810_SHIFT)) & locald64_LDPRR4B1_lumd1810_MASK)
/*! @} */

/*! @name LDPRR4B2 - ldprofilereg4b2 */
/*! @{ */

#define locald64_LDPRR4B2_lumd1813_MASK          (0x3FFU)
#define locald64_LDPRR4B2_lumd1813_SHIFT         (0U)
/*! lumd1813 - lumdat_1813 */
#define locald64_LDPRR4B2_lumd1813(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B2_lumd1813_SHIFT)) & locald64_LDPRR4B2_lumd1813_MASK)

#define locald64_LDPRR4B2_lumd1812_MASK          (0x3FF0000U)
#define locald64_LDPRR4B2_lumd1812_SHIFT         (16U)
/*! lumd1812 - lumdat_1812 */
#define locald64_LDPRR4B2_lumd1812(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B2_lumd1812_SHIFT)) & locald64_LDPRR4B2_lumd1812_MASK)
/*! @} */

/*! @name LDPRR4B3 - ldprofilereg4b3 */
/*! @{ */

#define locald64_LDPRR4B3_lumd1815_MASK          (0x3FFU)
#define locald64_LDPRR4B3_lumd1815_SHIFT         (0U)
/*! lumd1815 - lumdat_1815 */
#define locald64_LDPRR4B3_lumd1815(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B3_lumd1815_SHIFT)) & locald64_LDPRR4B3_lumd1815_MASK)

#define locald64_LDPRR4B3_lumd1814_MASK          (0x3FF0000U)
#define locald64_LDPRR4B3_lumd1814_SHIFT         (16U)
/*! lumd1814 - lumdat_1814 */
#define locald64_LDPRR4B3_lumd1814(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B3_lumd1814_SHIFT)) & locald64_LDPRR4B3_lumd1814_MASK)
/*! @} */

/*! @name LDPRR4B4 - ldprofilereg4b4 */
/*! @{ */

#define locald64_LDPRR4B4_lumd1817_MASK          (0x3FFU)
#define locald64_LDPRR4B4_lumd1817_SHIFT         (0U)
/*! lumd1817 - lumdat_1817 */
#define locald64_LDPRR4B4_lumd1817(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B4_lumd1817_SHIFT)) & locald64_LDPRR4B4_lumd1817_MASK)

#define locald64_LDPRR4B4_lumd1816_MASK          (0x3FF0000U)
#define locald64_LDPRR4B4_lumd1816_SHIFT         (16U)
/*! lumd1816 - lumdat_1816 */
#define locald64_LDPRR4B4_lumd1816(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B4_lumd1816_SHIFT)) & locald64_LDPRR4B4_lumd1816_MASK)
/*! @} */

/*! @name LDPRR4B5 - ldprofilereg4b5 */
/*! @{ */

#define locald64_LDPRR4B5_lumd1819_MASK          (0x3FFU)
#define locald64_LDPRR4B5_lumd1819_SHIFT         (0U)
/*! lumd1819 - lumdat_1819 */
#define locald64_LDPRR4B5_lumd1819(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B5_lumd1819_SHIFT)) & locald64_LDPRR4B5_lumd1819_MASK)

#define locald64_LDPRR4B5_lumd1818_MASK          (0x3FF0000U)
#define locald64_LDPRR4B5_lumd1818_SHIFT         (16U)
/*! lumd1818 - lumdat_1818 */
#define locald64_LDPRR4B5_lumd1818(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B5_lumd1818_SHIFT)) & locald64_LDPRR4B5_lumd1818_MASK)
/*! @} */

/*! @name LDPRR4B6 - ldprofilereg4b6 */
/*! @{ */

#define locald64_LDPRR4B6_lumd1821_MASK          (0x3FFU)
#define locald64_LDPRR4B6_lumd1821_SHIFT         (0U)
/*! lumd1821 - lumdat_1821 */
#define locald64_LDPRR4B6_lumd1821(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B6_lumd1821_SHIFT)) & locald64_LDPRR4B6_lumd1821_MASK)

#define locald64_LDPRR4B6_lumd1820_MASK          (0x3FF0000U)
#define locald64_LDPRR4B6_lumd1820_SHIFT         (16U)
/*! lumd1820 - lumdat_1820 */
#define locald64_LDPRR4B6_lumd1820(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B6_lumd1820_SHIFT)) & locald64_LDPRR4B6_lumd1820_MASK)
/*! @} */

/*! @name LDPRR4B7 - ldprofilereg4b7 */
/*! @{ */

#define locald64_LDPRR4B7_lumd1823_MASK          (0x3FFU)
#define locald64_LDPRR4B7_lumd1823_SHIFT         (0U)
/*! lumd1823 - lumdat_1823 */
#define locald64_LDPRR4B7_lumd1823(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B7_lumd1823_SHIFT)) & locald64_LDPRR4B7_lumd1823_MASK)

#define locald64_LDPRR4B7_lumd1822_MASK          (0x3FF0000U)
#define locald64_LDPRR4B7_lumd1822_SHIFT         (16U)
/*! lumd1822 - lumdat_1822 */
#define locald64_LDPRR4B7_lumd1822(x)            (((uint32_t)(((uint32_t)(x)) << locald64_LDPRR4B7_lumd1822_SHIFT)) & locald64_LDPRR4B7_lumd1822_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald64_Register_Masks */


/*!
 * @}
 */ /* end of group locald64_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD64_H_ */

