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
**         CMSIS Peripheral Access Layer for locald59
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
 * @file PERI_locald59.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald59
 *
 * CMSIS Peripheral Access Layer for locald59
 */

#if !defined(PERI_LOCALD59_H_)
#define PERI_LOCALD59_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald59 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald59_Peripheral_Access_Layer locald59 Peripheral Access Layer
 * @{
 */

/** locald59 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR400;                          /**< ldprofilereg400, offset: 0x0 */
  __IO uint32_t LDPRR401;                          /**< ldprofilereg401, offset: 0x4 */
  __IO uint32_t LDPRR402;                          /**< ldprofilereg402, offset: 0x8 */
  __IO uint32_t LDPRR403;                          /**< ldprofilereg403, offset: 0xC */
  __IO uint32_t LDPRR404;                          /**< ldprofilereg404, offset: 0x10 */
  __IO uint32_t LDPRR405;                          /**< ldprofilereg405, offset: 0x14 */
  __IO uint32_t LDPRR406;                          /**< ldprofilereg406, offset: 0x18 */
  __IO uint32_t LDPRR407;                          /**< ldprofilereg407, offset: 0x1C */
  __IO uint32_t LDPRR408;                          /**< ldprofilereg408, offset: 0x20 */
  __IO uint32_t LDPRR409;                          /**< ldprofilereg409, offset: 0x24 */
  __IO uint32_t LDPRR40A;                          /**< ldprofilereg40a, offset: 0x28 */
  __IO uint32_t LDPRR40B;                          /**< ldprofilereg40b, offset: 0x2C */
  __IO uint32_t LDPRR40C;                          /**< ldprofilereg40c, offset: 0x30 */
  __IO uint32_t LDPRR40D;                          /**< ldprofilereg40d, offset: 0x34 */
  __IO uint32_t LDPRR40E;                          /**< ldprofilereg40e, offset: 0x38 */
  __IO uint32_t LDPRR40F;                          /**< ldprofilereg40f, offset: 0x3C */
  __IO uint32_t LDPRR410;                          /**< ldprofilereg410, offset: 0x40 */
  __IO uint32_t LDPRR411;                          /**< ldprofilereg411, offset: 0x44 */
  __IO uint32_t LDPRR412;                          /**< ldprofilereg412, offset: 0x48 */
  __IO uint32_t LDPRR413;                          /**< ldprofilereg413, offset: 0x4C */
  __IO uint32_t LDPRR414;                          /**< ldprofilereg414, offset: 0x50 */
  __IO uint32_t LDPRR415;                          /**< ldprofilereg415, offset: 0x54 */
  __IO uint32_t LDPRR416;                          /**< ldprofilereg416, offset: 0x58 */
  __IO uint32_t LDPRR417;                          /**< ldprofilereg417, offset: 0x5C */
} locald59_Type;

/* ----------------------------------------------------------------------------
   -- locald59 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald59_Register_Masks locald59 Register Masks
 * @{
 */

/*! @name LDPRR400 - ldprofilereg400 */
/*! @{ */

#define locald59_LDPRR400_lumd1537_MASK          (0x3FFU)
#define locald59_LDPRR400_lumd1537_SHIFT         (0U)
/*! lumd1537 - lumdat_1537 */
#define locald59_LDPRR400_lumd1537(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR400_lumd1537_SHIFT)) & locald59_LDPRR400_lumd1537_MASK)

#define locald59_LDPRR400_lumd1536_MASK          (0x3FF0000U)
#define locald59_LDPRR400_lumd1536_SHIFT         (16U)
/*! lumd1536 - lumdat_1536 */
#define locald59_LDPRR400_lumd1536(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR400_lumd1536_SHIFT)) & locald59_LDPRR400_lumd1536_MASK)
/*! @} */

/*! @name LDPRR401 - ldprofilereg401 */
/*! @{ */

#define locald59_LDPRR401_lumd1539_MASK          (0x3FFU)
#define locald59_LDPRR401_lumd1539_SHIFT         (0U)
/*! lumd1539 - lumdat_1539 */
#define locald59_LDPRR401_lumd1539(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR401_lumd1539_SHIFT)) & locald59_LDPRR401_lumd1539_MASK)

#define locald59_LDPRR401_lumd1538_MASK          (0x3FF0000U)
#define locald59_LDPRR401_lumd1538_SHIFT         (16U)
/*! lumd1538 - lumdat_1538 */
#define locald59_LDPRR401_lumd1538(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR401_lumd1538_SHIFT)) & locald59_LDPRR401_lumd1538_MASK)
/*! @} */

/*! @name LDPRR402 - ldprofilereg402 */
/*! @{ */

#define locald59_LDPRR402_lumd1541_MASK          (0x3FFU)
#define locald59_LDPRR402_lumd1541_SHIFT         (0U)
/*! lumd1541 - lumdat_1541 */
#define locald59_LDPRR402_lumd1541(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR402_lumd1541_SHIFT)) & locald59_LDPRR402_lumd1541_MASK)

#define locald59_LDPRR402_lumd1540_MASK          (0x3FF0000U)
#define locald59_LDPRR402_lumd1540_SHIFT         (16U)
/*! lumd1540 - lumdat_1540 */
#define locald59_LDPRR402_lumd1540(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR402_lumd1540_SHIFT)) & locald59_LDPRR402_lumd1540_MASK)
/*! @} */

/*! @name LDPRR403 - ldprofilereg403 */
/*! @{ */

#define locald59_LDPRR403_lumd1543_MASK          (0x3FFU)
#define locald59_LDPRR403_lumd1543_SHIFT         (0U)
/*! lumd1543 - lumdat_1543 */
#define locald59_LDPRR403_lumd1543(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR403_lumd1543_SHIFT)) & locald59_LDPRR403_lumd1543_MASK)

#define locald59_LDPRR403_lumd1542_MASK          (0x3FF0000U)
#define locald59_LDPRR403_lumd1542_SHIFT         (16U)
/*! lumd1542 - lumdat_1542 */
#define locald59_LDPRR403_lumd1542(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR403_lumd1542_SHIFT)) & locald59_LDPRR403_lumd1542_MASK)
/*! @} */

/*! @name LDPRR404 - ldprofilereg404 */
/*! @{ */

#define locald59_LDPRR404_lumd1545_MASK          (0x3FFU)
#define locald59_LDPRR404_lumd1545_SHIFT         (0U)
/*! lumd1545 - lumdat_1545 */
#define locald59_LDPRR404_lumd1545(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR404_lumd1545_SHIFT)) & locald59_LDPRR404_lumd1545_MASK)

#define locald59_LDPRR404_lumd1544_MASK          (0x3FF0000U)
#define locald59_LDPRR404_lumd1544_SHIFT         (16U)
/*! lumd1544 - lumdat_1544 */
#define locald59_LDPRR404_lumd1544(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR404_lumd1544_SHIFT)) & locald59_LDPRR404_lumd1544_MASK)
/*! @} */

/*! @name LDPRR405 - ldprofilereg405 */
/*! @{ */

#define locald59_LDPRR405_lumd1547_MASK          (0x3FFU)
#define locald59_LDPRR405_lumd1547_SHIFT         (0U)
/*! lumd1547 - lumdat_1547 */
#define locald59_LDPRR405_lumd1547(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR405_lumd1547_SHIFT)) & locald59_LDPRR405_lumd1547_MASK)

#define locald59_LDPRR405_lumd1546_MASK          (0x3FF0000U)
#define locald59_LDPRR405_lumd1546_SHIFT         (16U)
/*! lumd1546 - lumdat_1546 */
#define locald59_LDPRR405_lumd1546(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR405_lumd1546_SHIFT)) & locald59_LDPRR405_lumd1546_MASK)
/*! @} */

/*! @name LDPRR406 - ldprofilereg406 */
/*! @{ */

#define locald59_LDPRR406_lumd1549_MASK          (0x3FFU)
#define locald59_LDPRR406_lumd1549_SHIFT         (0U)
/*! lumd1549 - lumdat_1549 */
#define locald59_LDPRR406_lumd1549(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR406_lumd1549_SHIFT)) & locald59_LDPRR406_lumd1549_MASK)

#define locald59_LDPRR406_lumd1548_MASK          (0x3FF0000U)
#define locald59_LDPRR406_lumd1548_SHIFT         (16U)
/*! lumd1548 - lumdat_1548 */
#define locald59_LDPRR406_lumd1548(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR406_lumd1548_SHIFT)) & locald59_LDPRR406_lumd1548_MASK)
/*! @} */

/*! @name LDPRR407 - ldprofilereg407 */
/*! @{ */

#define locald59_LDPRR407_lumd1551_MASK          (0x3FFU)
#define locald59_LDPRR407_lumd1551_SHIFT         (0U)
/*! lumd1551 - lumdat_1551 */
#define locald59_LDPRR407_lumd1551(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR407_lumd1551_SHIFT)) & locald59_LDPRR407_lumd1551_MASK)

#define locald59_LDPRR407_lumd1550_MASK          (0x3FF0000U)
#define locald59_LDPRR407_lumd1550_SHIFT         (16U)
/*! lumd1550 - lumdat_1550 */
#define locald59_LDPRR407_lumd1550(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR407_lumd1550_SHIFT)) & locald59_LDPRR407_lumd1550_MASK)
/*! @} */

/*! @name LDPRR408 - ldprofilereg408 */
/*! @{ */

#define locald59_LDPRR408_lumd1553_MASK          (0x3FFU)
#define locald59_LDPRR408_lumd1553_SHIFT         (0U)
/*! lumd1553 - lumdat_1553 */
#define locald59_LDPRR408_lumd1553(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR408_lumd1553_SHIFT)) & locald59_LDPRR408_lumd1553_MASK)

#define locald59_LDPRR408_lumd1552_MASK          (0x3FF0000U)
#define locald59_LDPRR408_lumd1552_SHIFT         (16U)
/*! lumd1552 - lumdat_1552 */
#define locald59_LDPRR408_lumd1552(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR408_lumd1552_SHIFT)) & locald59_LDPRR408_lumd1552_MASK)
/*! @} */

/*! @name LDPRR409 - ldprofilereg409 */
/*! @{ */

#define locald59_LDPRR409_lumd1555_MASK          (0x3FFU)
#define locald59_LDPRR409_lumd1555_SHIFT         (0U)
/*! lumd1555 - lumdat_1555 */
#define locald59_LDPRR409_lumd1555(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR409_lumd1555_SHIFT)) & locald59_LDPRR409_lumd1555_MASK)

#define locald59_LDPRR409_lumd1554_MASK          (0x3FF0000U)
#define locald59_LDPRR409_lumd1554_SHIFT         (16U)
/*! lumd1554 - lumdat_1554 */
#define locald59_LDPRR409_lumd1554(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR409_lumd1554_SHIFT)) & locald59_LDPRR409_lumd1554_MASK)
/*! @} */

/*! @name LDPRR40A - ldprofilereg40a */
/*! @{ */

#define locald59_LDPRR40A_lumd1557_MASK          (0x3FFU)
#define locald59_LDPRR40A_lumd1557_SHIFT         (0U)
/*! lumd1557 - lumdat_1557 */
#define locald59_LDPRR40A_lumd1557(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40A_lumd1557_SHIFT)) & locald59_LDPRR40A_lumd1557_MASK)

#define locald59_LDPRR40A_lumd1556_MASK          (0x3FF0000U)
#define locald59_LDPRR40A_lumd1556_SHIFT         (16U)
/*! lumd1556 - lumdat_1556 */
#define locald59_LDPRR40A_lumd1556(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40A_lumd1556_SHIFT)) & locald59_LDPRR40A_lumd1556_MASK)
/*! @} */

/*! @name LDPRR40B - ldprofilereg40b */
/*! @{ */

#define locald59_LDPRR40B_lumd1559_MASK          (0x3FFU)
#define locald59_LDPRR40B_lumd1559_SHIFT         (0U)
/*! lumd1559 - lumdat_1559 */
#define locald59_LDPRR40B_lumd1559(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40B_lumd1559_SHIFT)) & locald59_LDPRR40B_lumd1559_MASK)

#define locald59_LDPRR40B_lumd1558_MASK          (0x3FF0000U)
#define locald59_LDPRR40B_lumd1558_SHIFT         (16U)
/*! lumd1558 - lumdat_1558 */
#define locald59_LDPRR40B_lumd1558(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40B_lumd1558_SHIFT)) & locald59_LDPRR40B_lumd1558_MASK)
/*! @} */

/*! @name LDPRR40C - ldprofilereg40c */
/*! @{ */

#define locald59_LDPRR40C_lumd1561_MASK          (0x3FFU)
#define locald59_LDPRR40C_lumd1561_SHIFT         (0U)
/*! lumd1561 - lumdat_1561 */
#define locald59_LDPRR40C_lumd1561(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40C_lumd1561_SHIFT)) & locald59_LDPRR40C_lumd1561_MASK)

#define locald59_LDPRR40C_lumd1560_MASK          (0x3FF0000U)
#define locald59_LDPRR40C_lumd1560_SHIFT         (16U)
/*! lumd1560 - lumdat_1560 */
#define locald59_LDPRR40C_lumd1560(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40C_lumd1560_SHIFT)) & locald59_LDPRR40C_lumd1560_MASK)
/*! @} */

/*! @name LDPRR40D - ldprofilereg40d */
/*! @{ */

#define locald59_LDPRR40D_lumd1563_MASK          (0x3FFU)
#define locald59_LDPRR40D_lumd1563_SHIFT         (0U)
/*! lumd1563 - lumdat_1563 */
#define locald59_LDPRR40D_lumd1563(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40D_lumd1563_SHIFT)) & locald59_LDPRR40D_lumd1563_MASK)

#define locald59_LDPRR40D_lumd1562_MASK          (0x3FF0000U)
#define locald59_LDPRR40D_lumd1562_SHIFT         (16U)
/*! lumd1562 - lumdat_1562 */
#define locald59_LDPRR40D_lumd1562(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40D_lumd1562_SHIFT)) & locald59_LDPRR40D_lumd1562_MASK)
/*! @} */

/*! @name LDPRR40E - ldprofilereg40e */
/*! @{ */

#define locald59_LDPRR40E_lumd1565_MASK          (0x3FFU)
#define locald59_LDPRR40E_lumd1565_SHIFT         (0U)
/*! lumd1565 - lumdat_1565 */
#define locald59_LDPRR40E_lumd1565(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40E_lumd1565_SHIFT)) & locald59_LDPRR40E_lumd1565_MASK)

#define locald59_LDPRR40E_lumd1564_MASK          (0x3FF0000U)
#define locald59_LDPRR40E_lumd1564_SHIFT         (16U)
/*! lumd1564 - lumdat_1564 */
#define locald59_LDPRR40E_lumd1564(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40E_lumd1564_SHIFT)) & locald59_LDPRR40E_lumd1564_MASK)
/*! @} */

/*! @name LDPRR40F - ldprofilereg40f */
/*! @{ */

#define locald59_LDPRR40F_lumd1567_MASK          (0x3FFU)
#define locald59_LDPRR40F_lumd1567_SHIFT         (0U)
/*! lumd1567 - lumdat_1567 */
#define locald59_LDPRR40F_lumd1567(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40F_lumd1567_SHIFT)) & locald59_LDPRR40F_lumd1567_MASK)

#define locald59_LDPRR40F_lumd1566_MASK          (0x3FF0000U)
#define locald59_LDPRR40F_lumd1566_SHIFT         (16U)
/*! lumd1566 - lumdat_1566 */
#define locald59_LDPRR40F_lumd1566(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR40F_lumd1566_SHIFT)) & locald59_LDPRR40F_lumd1566_MASK)
/*! @} */

/*! @name LDPRR410 - ldprofilereg410 */
/*! @{ */

#define locald59_LDPRR410_lumd1569_MASK          (0x3FFU)
#define locald59_LDPRR410_lumd1569_SHIFT         (0U)
/*! lumd1569 - lumdat_1569 */
#define locald59_LDPRR410_lumd1569(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR410_lumd1569_SHIFT)) & locald59_LDPRR410_lumd1569_MASK)

#define locald59_LDPRR410_lumd1568_MASK          (0x3FF0000U)
#define locald59_LDPRR410_lumd1568_SHIFT         (16U)
/*! lumd1568 - lumdat_1568 */
#define locald59_LDPRR410_lumd1568(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR410_lumd1568_SHIFT)) & locald59_LDPRR410_lumd1568_MASK)
/*! @} */

/*! @name LDPRR411 - ldprofilereg411 */
/*! @{ */

#define locald59_LDPRR411_lumd1571_MASK          (0x3FFU)
#define locald59_LDPRR411_lumd1571_SHIFT         (0U)
/*! lumd1571 - lumdat_1571 */
#define locald59_LDPRR411_lumd1571(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR411_lumd1571_SHIFT)) & locald59_LDPRR411_lumd1571_MASK)

#define locald59_LDPRR411_lumd1570_MASK          (0x3FF0000U)
#define locald59_LDPRR411_lumd1570_SHIFT         (16U)
/*! lumd1570 - lumdat_1570 */
#define locald59_LDPRR411_lumd1570(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR411_lumd1570_SHIFT)) & locald59_LDPRR411_lumd1570_MASK)
/*! @} */

/*! @name LDPRR412 - ldprofilereg412 */
/*! @{ */

#define locald59_LDPRR412_lumd1573_MASK          (0x3FFU)
#define locald59_LDPRR412_lumd1573_SHIFT         (0U)
/*! lumd1573 - lumdat_1573 */
#define locald59_LDPRR412_lumd1573(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR412_lumd1573_SHIFT)) & locald59_LDPRR412_lumd1573_MASK)

#define locald59_LDPRR412_lumd1572_MASK          (0x3FF0000U)
#define locald59_LDPRR412_lumd1572_SHIFT         (16U)
/*! lumd1572 - lumdat_1572 */
#define locald59_LDPRR412_lumd1572(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR412_lumd1572_SHIFT)) & locald59_LDPRR412_lumd1572_MASK)
/*! @} */

/*! @name LDPRR413 - ldprofilereg413 */
/*! @{ */

#define locald59_LDPRR413_lumd1575_MASK          (0x3FFU)
#define locald59_LDPRR413_lumd1575_SHIFT         (0U)
/*! lumd1575 - lumdat_1575 */
#define locald59_LDPRR413_lumd1575(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR413_lumd1575_SHIFT)) & locald59_LDPRR413_lumd1575_MASK)

#define locald59_LDPRR413_lumd1574_MASK          (0x3FF0000U)
#define locald59_LDPRR413_lumd1574_SHIFT         (16U)
/*! lumd1574 - lumdat_1574 */
#define locald59_LDPRR413_lumd1574(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR413_lumd1574_SHIFT)) & locald59_LDPRR413_lumd1574_MASK)
/*! @} */

/*! @name LDPRR414 - ldprofilereg414 */
/*! @{ */

#define locald59_LDPRR414_lumd1577_MASK          (0x3FFU)
#define locald59_LDPRR414_lumd1577_SHIFT         (0U)
/*! lumd1577 - lumdat_1577 */
#define locald59_LDPRR414_lumd1577(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR414_lumd1577_SHIFT)) & locald59_LDPRR414_lumd1577_MASK)

#define locald59_LDPRR414_lumd1576_MASK          (0x3FF0000U)
#define locald59_LDPRR414_lumd1576_SHIFT         (16U)
/*! lumd1576 - lumdat_1576 */
#define locald59_LDPRR414_lumd1576(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR414_lumd1576_SHIFT)) & locald59_LDPRR414_lumd1576_MASK)
/*! @} */

/*! @name LDPRR415 - ldprofilereg415 */
/*! @{ */

#define locald59_LDPRR415_lumd1579_MASK          (0x3FFU)
#define locald59_LDPRR415_lumd1579_SHIFT         (0U)
/*! lumd1579 - lumdat_1579 */
#define locald59_LDPRR415_lumd1579(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR415_lumd1579_SHIFT)) & locald59_LDPRR415_lumd1579_MASK)

#define locald59_LDPRR415_lumd1578_MASK          (0x3FF0000U)
#define locald59_LDPRR415_lumd1578_SHIFT         (16U)
/*! lumd1578 - lumdat_1578 */
#define locald59_LDPRR415_lumd1578(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR415_lumd1578_SHIFT)) & locald59_LDPRR415_lumd1578_MASK)
/*! @} */

/*! @name LDPRR416 - ldprofilereg416 */
/*! @{ */

#define locald59_LDPRR416_lumd1581_MASK          (0x3FFU)
#define locald59_LDPRR416_lumd1581_SHIFT         (0U)
/*! lumd1581 - lumdat_1581 */
#define locald59_LDPRR416_lumd1581(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR416_lumd1581_SHIFT)) & locald59_LDPRR416_lumd1581_MASK)

#define locald59_LDPRR416_lumd1580_MASK          (0x3FF0000U)
#define locald59_LDPRR416_lumd1580_SHIFT         (16U)
/*! lumd1580 - lumdat_1580 */
#define locald59_LDPRR416_lumd1580(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR416_lumd1580_SHIFT)) & locald59_LDPRR416_lumd1580_MASK)
/*! @} */

/*! @name LDPRR417 - ldprofilereg417 */
/*! @{ */

#define locald59_LDPRR417_lumd1583_MASK          (0x3FFU)
#define locald59_LDPRR417_lumd1583_SHIFT         (0U)
/*! lumd1583 - lumdat_1583 */
#define locald59_LDPRR417_lumd1583(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR417_lumd1583_SHIFT)) & locald59_LDPRR417_lumd1583_MASK)

#define locald59_LDPRR417_lumd1582_MASK          (0x3FF0000U)
#define locald59_LDPRR417_lumd1582_SHIFT         (16U)
/*! lumd1582 - lumdat_1582 */
#define locald59_LDPRR417_lumd1582(x)            (((uint32_t)(((uint32_t)(x)) << locald59_LDPRR417_lumd1582_SHIFT)) & locald59_LDPRR417_lumd1582_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald59_Register_Masks */


/*!
 * @}
 */ /* end of group locald59_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD59_H_ */

