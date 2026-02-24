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
**         CMSIS Peripheral Access Layer for locald60
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
 * @file PERI_locald60.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald60
 *
 * CMSIS Peripheral Access Layer for locald60
 */

#if !defined(PERI_LOCALD60_H_)
#define PERI_LOCALD60_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald60 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald60_Peripheral_Access_Layer locald60 Peripheral Access Layer
 * @{
 */

/** locald60 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR420;                          /**< ldprofilereg420, offset: 0x0 */
  __IO uint32_t LDPRR421;                          /**< ldprofilereg421, offset: 0x4 */
  __IO uint32_t LDPRR422;                          /**< ldprofilereg422, offset: 0x8 */
  __IO uint32_t LDPRR423;                          /**< ldprofilereg423, offset: 0xC */
  __IO uint32_t LDPRR424;                          /**< ldprofilereg424, offset: 0x10 */
  __IO uint32_t LDPRR425;                          /**< ldprofilereg425, offset: 0x14 */
  __IO uint32_t LDPRR426;                          /**< ldprofilereg426, offset: 0x18 */
  __IO uint32_t LDPRR427;                          /**< ldprofilereg427, offset: 0x1C */
  __IO uint32_t LDPRR428;                          /**< ldprofilereg428, offset: 0x20 */
  __IO uint32_t LDPRR429;                          /**< ldprofilereg429, offset: 0x24 */
  __IO uint32_t LDPRR42A;                          /**< ldprofilereg42a, offset: 0x28 */
  __IO uint32_t LDPRR42B;                          /**< ldprofilereg42b, offset: 0x2C */
  __IO uint32_t LDPRR42C;                          /**< ldprofilereg42c, offset: 0x30 */
  __IO uint32_t LDPRR42D;                          /**< ldprofilereg42d, offset: 0x34 */
  __IO uint32_t LDPRR42E;                          /**< ldprofilereg42e, offset: 0x38 */
  __IO uint32_t LDPRR42F;                          /**< ldprofilereg42f, offset: 0x3C */
  __IO uint32_t LDPRR430;                          /**< ldprofilereg430, offset: 0x40 */
  __IO uint32_t LDPRR431;                          /**< ldprofilereg431, offset: 0x44 */
  __IO uint32_t LDPRR432;                          /**< ldprofilereg432, offset: 0x48 */
  __IO uint32_t LDPRR433;                          /**< ldprofilereg433, offset: 0x4C */
  __IO uint32_t LDPRR434;                          /**< ldprofilereg434, offset: 0x50 */
  __IO uint32_t LDPRR435;                          /**< ldprofilereg435, offset: 0x54 */
  __IO uint32_t LDPRR436;                          /**< ldprofilereg436, offset: 0x58 */
  __IO uint32_t LDPRR437;                          /**< ldprofilereg437, offset: 0x5C */
} locald60_Type;

/* ----------------------------------------------------------------------------
   -- locald60 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald60_Register_Masks locald60 Register Masks
 * @{
 */

/*! @name LDPRR420 - ldprofilereg420 */
/*! @{ */

#define locald60_LDPRR420_lumd1585_MASK          (0x3FFU)
#define locald60_LDPRR420_lumd1585_SHIFT         (0U)
/*! lumd1585 - lumdat_1585 */
#define locald60_LDPRR420_lumd1585(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR420_lumd1585_SHIFT)) & locald60_LDPRR420_lumd1585_MASK)

#define locald60_LDPRR420_lumd1584_MASK          (0x3FF0000U)
#define locald60_LDPRR420_lumd1584_SHIFT         (16U)
/*! lumd1584 - lumdat_1584 */
#define locald60_LDPRR420_lumd1584(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR420_lumd1584_SHIFT)) & locald60_LDPRR420_lumd1584_MASK)
/*! @} */

/*! @name LDPRR421 - ldprofilereg421 */
/*! @{ */

#define locald60_LDPRR421_lumd1587_MASK          (0x3FFU)
#define locald60_LDPRR421_lumd1587_SHIFT         (0U)
/*! lumd1587 - lumdat_1587 */
#define locald60_LDPRR421_lumd1587(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR421_lumd1587_SHIFT)) & locald60_LDPRR421_lumd1587_MASK)

#define locald60_LDPRR421_lumd1586_MASK          (0x3FF0000U)
#define locald60_LDPRR421_lumd1586_SHIFT         (16U)
/*! lumd1586 - lumdat_1586 */
#define locald60_LDPRR421_lumd1586(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR421_lumd1586_SHIFT)) & locald60_LDPRR421_lumd1586_MASK)
/*! @} */

/*! @name LDPRR422 - ldprofilereg422 */
/*! @{ */

#define locald60_LDPRR422_lumd1589_MASK          (0x3FFU)
#define locald60_LDPRR422_lumd1589_SHIFT         (0U)
/*! lumd1589 - lumdat_1589 */
#define locald60_LDPRR422_lumd1589(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR422_lumd1589_SHIFT)) & locald60_LDPRR422_lumd1589_MASK)

#define locald60_LDPRR422_lumd1588_MASK          (0x3FF0000U)
#define locald60_LDPRR422_lumd1588_SHIFT         (16U)
/*! lumd1588 - lumdat_1588 */
#define locald60_LDPRR422_lumd1588(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR422_lumd1588_SHIFT)) & locald60_LDPRR422_lumd1588_MASK)
/*! @} */

/*! @name LDPRR423 - ldprofilereg423 */
/*! @{ */

#define locald60_LDPRR423_lumd1591_MASK          (0x3FFU)
#define locald60_LDPRR423_lumd1591_SHIFT         (0U)
/*! lumd1591 - lumdat_1591 */
#define locald60_LDPRR423_lumd1591(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR423_lumd1591_SHIFT)) & locald60_LDPRR423_lumd1591_MASK)

#define locald60_LDPRR423_lumd1590_MASK          (0x3FF0000U)
#define locald60_LDPRR423_lumd1590_SHIFT         (16U)
/*! lumd1590 - lumdat_1590 */
#define locald60_LDPRR423_lumd1590(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR423_lumd1590_SHIFT)) & locald60_LDPRR423_lumd1590_MASK)
/*! @} */

/*! @name LDPRR424 - ldprofilereg424 */
/*! @{ */

#define locald60_LDPRR424_lumd1593_MASK          (0x3FFU)
#define locald60_LDPRR424_lumd1593_SHIFT         (0U)
/*! lumd1593 - lumdat_1593 */
#define locald60_LDPRR424_lumd1593(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR424_lumd1593_SHIFT)) & locald60_LDPRR424_lumd1593_MASK)

#define locald60_LDPRR424_lumd1592_MASK          (0x3FF0000U)
#define locald60_LDPRR424_lumd1592_SHIFT         (16U)
/*! lumd1592 - lumdat_1592 */
#define locald60_LDPRR424_lumd1592(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR424_lumd1592_SHIFT)) & locald60_LDPRR424_lumd1592_MASK)
/*! @} */

/*! @name LDPRR425 - ldprofilereg425 */
/*! @{ */

#define locald60_LDPRR425_lumd1595_MASK          (0x3FFU)
#define locald60_LDPRR425_lumd1595_SHIFT         (0U)
/*! lumd1595 - lumdat_1595 */
#define locald60_LDPRR425_lumd1595(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR425_lumd1595_SHIFT)) & locald60_LDPRR425_lumd1595_MASK)

#define locald60_LDPRR425_lumd1594_MASK          (0x3FF0000U)
#define locald60_LDPRR425_lumd1594_SHIFT         (16U)
/*! lumd1594 - lumdat_1594 */
#define locald60_LDPRR425_lumd1594(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR425_lumd1594_SHIFT)) & locald60_LDPRR425_lumd1594_MASK)
/*! @} */

/*! @name LDPRR426 - ldprofilereg426 */
/*! @{ */

#define locald60_LDPRR426_lumd1597_MASK          (0x3FFU)
#define locald60_LDPRR426_lumd1597_SHIFT         (0U)
/*! lumd1597 - lumdat_1597 */
#define locald60_LDPRR426_lumd1597(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR426_lumd1597_SHIFT)) & locald60_LDPRR426_lumd1597_MASK)

#define locald60_LDPRR426_lumd1596_MASK          (0x3FF0000U)
#define locald60_LDPRR426_lumd1596_SHIFT         (16U)
/*! lumd1596 - lumdat_1596 */
#define locald60_LDPRR426_lumd1596(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR426_lumd1596_SHIFT)) & locald60_LDPRR426_lumd1596_MASK)
/*! @} */

/*! @name LDPRR427 - ldprofilereg427 */
/*! @{ */

#define locald60_LDPRR427_lumd1599_MASK          (0x3FFU)
#define locald60_LDPRR427_lumd1599_SHIFT         (0U)
/*! lumd1599 - lumdat_1599 */
#define locald60_LDPRR427_lumd1599(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR427_lumd1599_SHIFT)) & locald60_LDPRR427_lumd1599_MASK)

#define locald60_LDPRR427_lumd1598_MASK          (0x3FF0000U)
#define locald60_LDPRR427_lumd1598_SHIFT         (16U)
/*! lumd1598 - lumdat_1598 */
#define locald60_LDPRR427_lumd1598(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR427_lumd1598_SHIFT)) & locald60_LDPRR427_lumd1598_MASK)
/*! @} */

/*! @name LDPRR428 - ldprofilereg428 */
/*! @{ */

#define locald60_LDPRR428_lumd1601_MASK          (0x3FFU)
#define locald60_LDPRR428_lumd1601_SHIFT         (0U)
/*! lumd1601 - lumdat_1601 */
#define locald60_LDPRR428_lumd1601(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR428_lumd1601_SHIFT)) & locald60_LDPRR428_lumd1601_MASK)

#define locald60_LDPRR428_lumd1600_MASK          (0x3FF0000U)
#define locald60_LDPRR428_lumd1600_SHIFT         (16U)
/*! lumd1600 - lumdat_1600 */
#define locald60_LDPRR428_lumd1600(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR428_lumd1600_SHIFT)) & locald60_LDPRR428_lumd1600_MASK)
/*! @} */

/*! @name LDPRR429 - ldprofilereg429 */
/*! @{ */

#define locald60_LDPRR429_lumd1603_MASK          (0x3FFU)
#define locald60_LDPRR429_lumd1603_SHIFT         (0U)
/*! lumd1603 - lumdat_1603 */
#define locald60_LDPRR429_lumd1603(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR429_lumd1603_SHIFT)) & locald60_LDPRR429_lumd1603_MASK)

#define locald60_LDPRR429_lumd1602_MASK          (0x3FF0000U)
#define locald60_LDPRR429_lumd1602_SHIFT         (16U)
/*! lumd1602 - lumdat_1602 */
#define locald60_LDPRR429_lumd1602(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR429_lumd1602_SHIFT)) & locald60_LDPRR429_lumd1602_MASK)
/*! @} */

/*! @name LDPRR42A - ldprofilereg42a */
/*! @{ */

#define locald60_LDPRR42A_lumd1605_MASK          (0x3FFU)
#define locald60_LDPRR42A_lumd1605_SHIFT         (0U)
/*! lumd1605 - lumdat_1605 */
#define locald60_LDPRR42A_lumd1605(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42A_lumd1605_SHIFT)) & locald60_LDPRR42A_lumd1605_MASK)

#define locald60_LDPRR42A_lumd1604_MASK          (0x3FF0000U)
#define locald60_LDPRR42A_lumd1604_SHIFT         (16U)
/*! lumd1604 - lumdat_1604 */
#define locald60_LDPRR42A_lumd1604(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42A_lumd1604_SHIFT)) & locald60_LDPRR42A_lumd1604_MASK)
/*! @} */

/*! @name LDPRR42B - ldprofilereg42b */
/*! @{ */

#define locald60_LDPRR42B_lumd1607_MASK          (0x3FFU)
#define locald60_LDPRR42B_lumd1607_SHIFT         (0U)
/*! lumd1607 - lumdat_1607 */
#define locald60_LDPRR42B_lumd1607(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42B_lumd1607_SHIFT)) & locald60_LDPRR42B_lumd1607_MASK)

#define locald60_LDPRR42B_lumd1606_MASK          (0x3FF0000U)
#define locald60_LDPRR42B_lumd1606_SHIFT         (16U)
/*! lumd1606 - lumdat_1606 */
#define locald60_LDPRR42B_lumd1606(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42B_lumd1606_SHIFT)) & locald60_LDPRR42B_lumd1606_MASK)
/*! @} */

/*! @name LDPRR42C - ldprofilereg42c */
/*! @{ */

#define locald60_LDPRR42C_lumd1609_MASK          (0x3FFU)
#define locald60_LDPRR42C_lumd1609_SHIFT         (0U)
/*! lumd1609 - lumdat_1609 */
#define locald60_LDPRR42C_lumd1609(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42C_lumd1609_SHIFT)) & locald60_LDPRR42C_lumd1609_MASK)

#define locald60_LDPRR42C_lumd1608_MASK          (0x3FF0000U)
#define locald60_LDPRR42C_lumd1608_SHIFT         (16U)
/*! lumd1608 - lumdat_1608 */
#define locald60_LDPRR42C_lumd1608(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42C_lumd1608_SHIFT)) & locald60_LDPRR42C_lumd1608_MASK)
/*! @} */

/*! @name LDPRR42D - ldprofilereg42d */
/*! @{ */

#define locald60_LDPRR42D_lumd1611_MASK          (0x3FFU)
#define locald60_LDPRR42D_lumd1611_SHIFT         (0U)
/*! lumd1611 - lumdat_1611 */
#define locald60_LDPRR42D_lumd1611(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42D_lumd1611_SHIFT)) & locald60_LDPRR42D_lumd1611_MASK)

#define locald60_LDPRR42D_lumd1610_MASK          (0x3FF0000U)
#define locald60_LDPRR42D_lumd1610_SHIFT         (16U)
/*! lumd1610 - lumdat_1610 */
#define locald60_LDPRR42D_lumd1610(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42D_lumd1610_SHIFT)) & locald60_LDPRR42D_lumd1610_MASK)
/*! @} */

/*! @name LDPRR42E - ldprofilereg42e */
/*! @{ */

#define locald60_LDPRR42E_lumd1613_MASK          (0x3FFU)
#define locald60_LDPRR42E_lumd1613_SHIFT         (0U)
/*! lumd1613 - lumdat_1613 */
#define locald60_LDPRR42E_lumd1613(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42E_lumd1613_SHIFT)) & locald60_LDPRR42E_lumd1613_MASK)

#define locald60_LDPRR42E_lumd1612_MASK          (0x3FF0000U)
#define locald60_LDPRR42E_lumd1612_SHIFT         (16U)
/*! lumd1612 - lumdat_1612 */
#define locald60_LDPRR42E_lumd1612(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42E_lumd1612_SHIFT)) & locald60_LDPRR42E_lumd1612_MASK)
/*! @} */

/*! @name LDPRR42F - ldprofilereg42f */
/*! @{ */

#define locald60_LDPRR42F_lumd1615_MASK          (0x3FFU)
#define locald60_LDPRR42F_lumd1615_SHIFT         (0U)
/*! lumd1615 - lumdat_1615 */
#define locald60_LDPRR42F_lumd1615(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42F_lumd1615_SHIFT)) & locald60_LDPRR42F_lumd1615_MASK)

#define locald60_LDPRR42F_lumd1614_MASK          (0x3FF0000U)
#define locald60_LDPRR42F_lumd1614_SHIFT         (16U)
/*! lumd1614 - lumdat_1614 */
#define locald60_LDPRR42F_lumd1614(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR42F_lumd1614_SHIFT)) & locald60_LDPRR42F_lumd1614_MASK)
/*! @} */

/*! @name LDPRR430 - ldprofilereg430 */
/*! @{ */

#define locald60_LDPRR430_lumd1617_MASK          (0x3FFU)
#define locald60_LDPRR430_lumd1617_SHIFT         (0U)
/*! lumd1617 - lumdat_1617 */
#define locald60_LDPRR430_lumd1617(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR430_lumd1617_SHIFT)) & locald60_LDPRR430_lumd1617_MASK)

#define locald60_LDPRR430_lumd1616_MASK          (0x3FF0000U)
#define locald60_LDPRR430_lumd1616_SHIFT         (16U)
/*! lumd1616 - lumdat_1616 */
#define locald60_LDPRR430_lumd1616(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR430_lumd1616_SHIFT)) & locald60_LDPRR430_lumd1616_MASK)
/*! @} */

/*! @name LDPRR431 - ldprofilereg431 */
/*! @{ */

#define locald60_LDPRR431_lumd1619_MASK          (0x3FFU)
#define locald60_LDPRR431_lumd1619_SHIFT         (0U)
/*! lumd1619 - lumdat_1619 */
#define locald60_LDPRR431_lumd1619(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR431_lumd1619_SHIFT)) & locald60_LDPRR431_lumd1619_MASK)

#define locald60_LDPRR431_lumd1618_MASK          (0x3FF0000U)
#define locald60_LDPRR431_lumd1618_SHIFT         (16U)
/*! lumd1618 - lumdat_1618 */
#define locald60_LDPRR431_lumd1618(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR431_lumd1618_SHIFT)) & locald60_LDPRR431_lumd1618_MASK)
/*! @} */

/*! @name LDPRR432 - ldprofilereg432 */
/*! @{ */

#define locald60_LDPRR432_lumd1621_MASK          (0x3FFU)
#define locald60_LDPRR432_lumd1621_SHIFT         (0U)
/*! lumd1621 - lumdat_1621 */
#define locald60_LDPRR432_lumd1621(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR432_lumd1621_SHIFT)) & locald60_LDPRR432_lumd1621_MASK)

#define locald60_LDPRR432_lumd1620_MASK          (0x3FF0000U)
#define locald60_LDPRR432_lumd1620_SHIFT         (16U)
/*! lumd1620 - lumdat_1620 */
#define locald60_LDPRR432_lumd1620(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR432_lumd1620_SHIFT)) & locald60_LDPRR432_lumd1620_MASK)
/*! @} */

/*! @name LDPRR433 - ldprofilereg433 */
/*! @{ */

#define locald60_LDPRR433_lumd1623_MASK          (0x3FFU)
#define locald60_LDPRR433_lumd1623_SHIFT         (0U)
/*! lumd1623 - lumdat_1623 */
#define locald60_LDPRR433_lumd1623(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR433_lumd1623_SHIFT)) & locald60_LDPRR433_lumd1623_MASK)

#define locald60_LDPRR433_lumd1622_MASK          (0x3FF0000U)
#define locald60_LDPRR433_lumd1622_SHIFT         (16U)
/*! lumd1622 - lumdat_1622 */
#define locald60_LDPRR433_lumd1622(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR433_lumd1622_SHIFT)) & locald60_LDPRR433_lumd1622_MASK)
/*! @} */

/*! @name LDPRR434 - ldprofilereg434 */
/*! @{ */

#define locald60_LDPRR434_lumd1625_MASK          (0x3FFU)
#define locald60_LDPRR434_lumd1625_SHIFT         (0U)
/*! lumd1625 - lumdat_1625 */
#define locald60_LDPRR434_lumd1625(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR434_lumd1625_SHIFT)) & locald60_LDPRR434_lumd1625_MASK)

#define locald60_LDPRR434_lumd1624_MASK          (0x3FF0000U)
#define locald60_LDPRR434_lumd1624_SHIFT         (16U)
/*! lumd1624 - lumdat_1624 */
#define locald60_LDPRR434_lumd1624(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR434_lumd1624_SHIFT)) & locald60_LDPRR434_lumd1624_MASK)
/*! @} */

/*! @name LDPRR435 - ldprofilereg435 */
/*! @{ */

#define locald60_LDPRR435_lumd1627_MASK          (0x3FFU)
#define locald60_LDPRR435_lumd1627_SHIFT         (0U)
/*! lumd1627 - lumdat_1627 */
#define locald60_LDPRR435_lumd1627(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR435_lumd1627_SHIFT)) & locald60_LDPRR435_lumd1627_MASK)

#define locald60_LDPRR435_lumd1626_MASK          (0x3FF0000U)
#define locald60_LDPRR435_lumd1626_SHIFT         (16U)
/*! lumd1626 - lumdat_1626 */
#define locald60_LDPRR435_lumd1626(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR435_lumd1626_SHIFT)) & locald60_LDPRR435_lumd1626_MASK)
/*! @} */

/*! @name LDPRR436 - ldprofilereg436 */
/*! @{ */

#define locald60_LDPRR436_lumd1629_MASK          (0x3FFU)
#define locald60_LDPRR436_lumd1629_SHIFT         (0U)
/*! lumd1629 - lumdat_1629 */
#define locald60_LDPRR436_lumd1629(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR436_lumd1629_SHIFT)) & locald60_LDPRR436_lumd1629_MASK)

#define locald60_LDPRR436_lumd1628_MASK          (0x3FF0000U)
#define locald60_LDPRR436_lumd1628_SHIFT         (16U)
/*! lumd1628 - lumdat_1628 */
#define locald60_LDPRR436_lumd1628(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR436_lumd1628_SHIFT)) & locald60_LDPRR436_lumd1628_MASK)
/*! @} */

/*! @name LDPRR437 - ldprofilereg437 */
/*! @{ */

#define locald60_LDPRR437_lumd1631_MASK          (0x3FFU)
#define locald60_LDPRR437_lumd1631_SHIFT         (0U)
/*! lumd1631 - lumdat_1631 */
#define locald60_LDPRR437_lumd1631(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR437_lumd1631_SHIFT)) & locald60_LDPRR437_lumd1631_MASK)

#define locald60_LDPRR437_lumd1630_MASK          (0x3FF0000U)
#define locald60_LDPRR437_lumd1630_SHIFT         (16U)
/*! lumd1630 - lumdat_1630 */
#define locald60_LDPRR437_lumd1630(x)            (((uint32_t)(((uint32_t)(x)) << locald60_LDPRR437_lumd1630_SHIFT)) & locald60_LDPRR437_lumd1630_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald60_Register_Masks */


/*!
 * @}
 */ /* end of group locald60_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD60_H_ */

