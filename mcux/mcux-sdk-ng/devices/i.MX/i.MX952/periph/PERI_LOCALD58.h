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
**         CMSIS Peripheral Access Layer for locald58
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
 * @file PERI_locald58.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald58
 *
 * CMSIS Peripheral Access Layer for locald58
 */

#if !defined(PERI_LOCALD58_H_)
#define PERI_LOCALD58_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald58 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald58_Peripheral_Access_Layer locald58 Peripheral Access Layer
 * @{
 */

/** locald58 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR3E0;                          /**< ldprofilereg3e0, offset: 0x0 */
  __IO uint32_t LDPRR3E1;                          /**< ldprofilereg3e1, offset: 0x4 */
  __IO uint32_t LDPRR3E2;                          /**< ldprofilereg3e2, offset: 0x8 */
  __IO uint32_t LDPRR3E3;                          /**< ldprofilereg3e3, offset: 0xC */
  __IO uint32_t LDPRR3E4;                          /**< ldprofilereg3e4, offset: 0x10 */
  __IO uint32_t LDPRR3E5;                          /**< ldprofilereg3e5, offset: 0x14 */
  __IO uint32_t LDPRR3E6;                          /**< ldprofilereg3e6, offset: 0x18 */
  __IO uint32_t LDPRR3E7;                          /**< ldprofilereg3e7, offset: 0x1C */
  __IO uint32_t LDPRR3E8;                          /**< ldprofilereg3e8, offset: 0x20 */
  __IO uint32_t LDPRR3E9;                          /**< ldprofilereg3e9, offset: 0x24 */
  __IO uint32_t LDPRR3EA;                          /**< ldprofilereg3ea, offset: 0x28 */
  __IO uint32_t LDPRR3EB;                          /**< ldprofilereg3eb, offset: 0x2C */
  __IO uint32_t LDPRR3EC;                          /**< ldprofilereg3ec, offset: 0x30 */
  __IO uint32_t LDPRR3ED;                          /**< ldprofilereg3ed, offset: 0x34 */
  __IO uint32_t LDPRR3EE;                          /**< ldprofilereg3ee, offset: 0x38 */
  __IO uint32_t LDPRR3EF;                          /**< ldprofilereg3ef, offset: 0x3C */
  __IO uint32_t LDPRR3F0;                          /**< ldprofilereg3f0, offset: 0x40 */
  __IO uint32_t LDPRR3F1;                          /**< ldprofilereg3f1, offset: 0x44 */
  __IO uint32_t LDPRR3F2;                          /**< ldprofilereg3f2, offset: 0x48 */
  __IO uint32_t LDPRR3F3;                          /**< ldprofilereg3f3, offset: 0x4C */
  __IO uint32_t LDPRR3F4;                          /**< ldprofilereg3f4, offset: 0x50 */
  __IO uint32_t LDPRR3F5;                          /**< ldprofilereg3f5, offset: 0x54 */
  __IO uint32_t LDPRR3F6;                          /**< ldprofilereg3f6, offset: 0x58 */
  __IO uint32_t LDPRR3F7;                          /**< ldprofilereg3f7, offset: 0x5C */
} locald58_Type;

/* ----------------------------------------------------------------------------
   -- locald58 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald58_Register_Masks locald58 Register Masks
 * @{
 */

/*! @name LDPRR3E0 - ldprofilereg3e0 */
/*! @{ */

#define locald58_LDPRR3E0_lumd1489_MASK          (0x3FFU)
#define locald58_LDPRR3E0_lumd1489_SHIFT         (0U)
/*! lumd1489 - lumdat_1489 */
#define locald58_LDPRR3E0_lumd1489(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E0_lumd1489_SHIFT)) & locald58_LDPRR3E0_lumd1489_MASK)

#define locald58_LDPRR3E0_lumd1488_MASK          (0x3FF0000U)
#define locald58_LDPRR3E0_lumd1488_SHIFT         (16U)
/*! lumd1488 - lumdat_1488 */
#define locald58_LDPRR3E0_lumd1488(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E0_lumd1488_SHIFT)) & locald58_LDPRR3E0_lumd1488_MASK)
/*! @} */

/*! @name LDPRR3E1 - ldprofilereg3e1 */
/*! @{ */

#define locald58_LDPRR3E1_lumd1491_MASK          (0x3FFU)
#define locald58_LDPRR3E1_lumd1491_SHIFT         (0U)
/*! lumd1491 - lumdat_1491 */
#define locald58_LDPRR3E1_lumd1491(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E1_lumd1491_SHIFT)) & locald58_LDPRR3E1_lumd1491_MASK)

#define locald58_LDPRR3E1_lumd1490_MASK          (0x3FF0000U)
#define locald58_LDPRR3E1_lumd1490_SHIFT         (16U)
/*! lumd1490 - lumdat_1490 */
#define locald58_LDPRR3E1_lumd1490(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E1_lumd1490_SHIFT)) & locald58_LDPRR3E1_lumd1490_MASK)
/*! @} */

/*! @name LDPRR3E2 - ldprofilereg3e2 */
/*! @{ */

#define locald58_LDPRR3E2_lumd1493_MASK          (0x3FFU)
#define locald58_LDPRR3E2_lumd1493_SHIFT         (0U)
/*! lumd1493 - lumdat_1493 */
#define locald58_LDPRR3E2_lumd1493(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E2_lumd1493_SHIFT)) & locald58_LDPRR3E2_lumd1493_MASK)

#define locald58_LDPRR3E2_lumd1492_MASK          (0x3FF0000U)
#define locald58_LDPRR3E2_lumd1492_SHIFT         (16U)
/*! lumd1492 - lumdat_1492 */
#define locald58_LDPRR3E2_lumd1492(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E2_lumd1492_SHIFT)) & locald58_LDPRR3E2_lumd1492_MASK)
/*! @} */

/*! @name LDPRR3E3 - ldprofilereg3e3 */
/*! @{ */

#define locald58_LDPRR3E3_lumd1495_MASK          (0x3FFU)
#define locald58_LDPRR3E3_lumd1495_SHIFT         (0U)
/*! lumd1495 - lumdat_1495 */
#define locald58_LDPRR3E3_lumd1495(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E3_lumd1495_SHIFT)) & locald58_LDPRR3E3_lumd1495_MASK)

#define locald58_LDPRR3E3_lumd1494_MASK          (0x3FF0000U)
#define locald58_LDPRR3E3_lumd1494_SHIFT         (16U)
/*! lumd1494 - lumdat_1494 */
#define locald58_LDPRR3E3_lumd1494(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E3_lumd1494_SHIFT)) & locald58_LDPRR3E3_lumd1494_MASK)
/*! @} */

/*! @name LDPRR3E4 - ldprofilereg3e4 */
/*! @{ */

#define locald58_LDPRR3E4_lumd1497_MASK          (0x3FFU)
#define locald58_LDPRR3E4_lumd1497_SHIFT         (0U)
/*! lumd1497 - lumdat_1497 */
#define locald58_LDPRR3E4_lumd1497(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E4_lumd1497_SHIFT)) & locald58_LDPRR3E4_lumd1497_MASK)

#define locald58_LDPRR3E4_lumd1496_MASK          (0x3FF0000U)
#define locald58_LDPRR3E4_lumd1496_SHIFT         (16U)
/*! lumd1496 - lumdat_1496 */
#define locald58_LDPRR3E4_lumd1496(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E4_lumd1496_SHIFT)) & locald58_LDPRR3E4_lumd1496_MASK)
/*! @} */

/*! @name LDPRR3E5 - ldprofilereg3e5 */
/*! @{ */

#define locald58_LDPRR3E5_lumd1499_MASK          (0x3FFU)
#define locald58_LDPRR3E5_lumd1499_SHIFT         (0U)
/*! lumd1499 - lumdat_1499 */
#define locald58_LDPRR3E5_lumd1499(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E5_lumd1499_SHIFT)) & locald58_LDPRR3E5_lumd1499_MASK)

#define locald58_LDPRR3E5_lumd1498_MASK          (0x3FF0000U)
#define locald58_LDPRR3E5_lumd1498_SHIFT         (16U)
/*! lumd1498 - lumdat_1498 */
#define locald58_LDPRR3E5_lumd1498(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E5_lumd1498_SHIFT)) & locald58_LDPRR3E5_lumd1498_MASK)
/*! @} */

/*! @name LDPRR3E6 - ldprofilereg3e6 */
/*! @{ */

#define locald58_LDPRR3E6_lumd1501_MASK          (0x3FFU)
#define locald58_LDPRR3E6_lumd1501_SHIFT         (0U)
/*! lumd1501 - lumdat_1501 */
#define locald58_LDPRR3E6_lumd1501(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E6_lumd1501_SHIFT)) & locald58_LDPRR3E6_lumd1501_MASK)

#define locald58_LDPRR3E6_lumd1500_MASK          (0x3FF0000U)
#define locald58_LDPRR3E6_lumd1500_SHIFT         (16U)
/*! lumd1500 - lumdat_1500 */
#define locald58_LDPRR3E6_lumd1500(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E6_lumd1500_SHIFT)) & locald58_LDPRR3E6_lumd1500_MASK)
/*! @} */

/*! @name LDPRR3E7 - ldprofilereg3e7 */
/*! @{ */

#define locald58_LDPRR3E7_lumd1503_MASK          (0x3FFU)
#define locald58_LDPRR3E7_lumd1503_SHIFT         (0U)
/*! lumd1503 - lumdat_1503 */
#define locald58_LDPRR3E7_lumd1503(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E7_lumd1503_SHIFT)) & locald58_LDPRR3E7_lumd1503_MASK)

#define locald58_LDPRR3E7_lumd1502_MASK          (0x3FF0000U)
#define locald58_LDPRR3E7_lumd1502_SHIFT         (16U)
/*! lumd1502 - lumdat_1502 */
#define locald58_LDPRR3E7_lumd1502(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E7_lumd1502_SHIFT)) & locald58_LDPRR3E7_lumd1502_MASK)
/*! @} */

/*! @name LDPRR3E8 - ldprofilereg3e8 */
/*! @{ */

#define locald58_LDPRR3E8_lumd1505_MASK          (0x3FFU)
#define locald58_LDPRR3E8_lumd1505_SHIFT         (0U)
/*! lumd1505 - lumdat_1505 */
#define locald58_LDPRR3E8_lumd1505(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E8_lumd1505_SHIFT)) & locald58_LDPRR3E8_lumd1505_MASK)

#define locald58_LDPRR3E8_lumd1504_MASK          (0x3FF0000U)
#define locald58_LDPRR3E8_lumd1504_SHIFT         (16U)
/*! lumd1504 - lumdat_1504 */
#define locald58_LDPRR3E8_lumd1504(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E8_lumd1504_SHIFT)) & locald58_LDPRR3E8_lumd1504_MASK)
/*! @} */

/*! @name LDPRR3E9 - ldprofilereg3e9 */
/*! @{ */

#define locald58_LDPRR3E9_lumd1507_MASK          (0x3FFU)
#define locald58_LDPRR3E9_lumd1507_SHIFT         (0U)
/*! lumd1507 - lumdat_1507 */
#define locald58_LDPRR3E9_lumd1507(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E9_lumd1507_SHIFT)) & locald58_LDPRR3E9_lumd1507_MASK)

#define locald58_LDPRR3E9_lumd1506_MASK          (0x3FF0000U)
#define locald58_LDPRR3E9_lumd1506_SHIFT         (16U)
/*! lumd1506 - lumdat_1506 */
#define locald58_LDPRR3E9_lumd1506(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3E9_lumd1506_SHIFT)) & locald58_LDPRR3E9_lumd1506_MASK)
/*! @} */

/*! @name LDPRR3EA - ldprofilereg3ea */
/*! @{ */

#define locald58_LDPRR3EA_lumd1509_MASK          (0x3FFU)
#define locald58_LDPRR3EA_lumd1509_SHIFT         (0U)
/*! lumd1509 - lumdat_1509 */
#define locald58_LDPRR3EA_lumd1509(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3EA_lumd1509_SHIFT)) & locald58_LDPRR3EA_lumd1509_MASK)

#define locald58_LDPRR3EA_lumd1508_MASK          (0x3FF0000U)
#define locald58_LDPRR3EA_lumd1508_SHIFT         (16U)
/*! lumd1508 - lumdat_1508 */
#define locald58_LDPRR3EA_lumd1508(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3EA_lumd1508_SHIFT)) & locald58_LDPRR3EA_lumd1508_MASK)
/*! @} */

/*! @name LDPRR3EB - ldprofilereg3eb */
/*! @{ */

#define locald58_LDPRR3EB_lumd1511_MASK          (0x3FFU)
#define locald58_LDPRR3EB_lumd1511_SHIFT         (0U)
/*! lumd1511 - lumdat_1511 */
#define locald58_LDPRR3EB_lumd1511(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3EB_lumd1511_SHIFT)) & locald58_LDPRR3EB_lumd1511_MASK)

#define locald58_LDPRR3EB_lumd1510_MASK          (0x3FF0000U)
#define locald58_LDPRR3EB_lumd1510_SHIFT         (16U)
/*! lumd1510 - lumdat_1510 */
#define locald58_LDPRR3EB_lumd1510(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3EB_lumd1510_SHIFT)) & locald58_LDPRR3EB_lumd1510_MASK)
/*! @} */

/*! @name LDPRR3EC - ldprofilereg3ec */
/*! @{ */

#define locald58_LDPRR3EC_lumd1513_MASK          (0x3FFU)
#define locald58_LDPRR3EC_lumd1513_SHIFT         (0U)
/*! lumd1513 - lumdat_1513 */
#define locald58_LDPRR3EC_lumd1513(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3EC_lumd1513_SHIFT)) & locald58_LDPRR3EC_lumd1513_MASK)

#define locald58_LDPRR3EC_lumd1512_MASK          (0x3FF0000U)
#define locald58_LDPRR3EC_lumd1512_SHIFT         (16U)
/*! lumd1512 - lumdat_1512 */
#define locald58_LDPRR3EC_lumd1512(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3EC_lumd1512_SHIFT)) & locald58_LDPRR3EC_lumd1512_MASK)
/*! @} */

/*! @name LDPRR3ED - ldprofilereg3ed */
/*! @{ */

#define locald58_LDPRR3ED_lumd1515_MASK          (0x3FFU)
#define locald58_LDPRR3ED_lumd1515_SHIFT         (0U)
/*! lumd1515 - lumdat_1515 */
#define locald58_LDPRR3ED_lumd1515(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3ED_lumd1515_SHIFT)) & locald58_LDPRR3ED_lumd1515_MASK)

#define locald58_LDPRR3ED_lumd1514_MASK          (0x3FF0000U)
#define locald58_LDPRR3ED_lumd1514_SHIFT         (16U)
/*! lumd1514 - lumdat_1514 */
#define locald58_LDPRR3ED_lumd1514(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3ED_lumd1514_SHIFT)) & locald58_LDPRR3ED_lumd1514_MASK)
/*! @} */

/*! @name LDPRR3EE - ldprofilereg3ee */
/*! @{ */

#define locald58_LDPRR3EE_lumd1517_MASK          (0x3FFU)
#define locald58_LDPRR3EE_lumd1517_SHIFT         (0U)
/*! lumd1517 - lumdat_1517 */
#define locald58_LDPRR3EE_lumd1517(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3EE_lumd1517_SHIFT)) & locald58_LDPRR3EE_lumd1517_MASK)

#define locald58_LDPRR3EE_lumd1516_MASK          (0x3FF0000U)
#define locald58_LDPRR3EE_lumd1516_SHIFT         (16U)
/*! lumd1516 - lumdat_1516 */
#define locald58_LDPRR3EE_lumd1516(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3EE_lumd1516_SHIFT)) & locald58_LDPRR3EE_lumd1516_MASK)
/*! @} */

/*! @name LDPRR3EF - ldprofilereg3ef */
/*! @{ */

#define locald58_LDPRR3EF_lumd1519_MASK          (0x3FFU)
#define locald58_LDPRR3EF_lumd1519_SHIFT         (0U)
/*! lumd1519 - lumdat_1519 */
#define locald58_LDPRR3EF_lumd1519(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3EF_lumd1519_SHIFT)) & locald58_LDPRR3EF_lumd1519_MASK)

#define locald58_LDPRR3EF_lumd1518_MASK          (0x3FF0000U)
#define locald58_LDPRR3EF_lumd1518_SHIFT         (16U)
/*! lumd1518 - lumdat_1518 */
#define locald58_LDPRR3EF_lumd1518(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3EF_lumd1518_SHIFT)) & locald58_LDPRR3EF_lumd1518_MASK)
/*! @} */

/*! @name LDPRR3F0 - ldprofilereg3f0 */
/*! @{ */

#define locald58_LDPRR3F0_lumd1521_MASK          (0x3FFU)
#define locald58_LDPRR3F0_lumd1521_SHIFT         (0U)
/*! lumd1521 - lumdat_1521 */
#define locald58_LDPRR3F0_lumd1521(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F0_lumd1521_SHIFT)) & locald58_LDPRR3F0_lumd1521_MASK)

#define locald58_LDPRR3F0_lumd1520_MASK          (0x3FF0000U)
#define locald58_LDPRR3F0_lumd1520_SHIFT         (16U)
/*! lumd1520 - lumdat_1520 */
#define locald58_LDPRR3F0_lumd1520(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F0_lumd1520_SHIFT)) & locald58_LDPRR3F0_lumd1520_MASK)
/*! @} */

/*! @name LDPRR3F1 - ldprofilereg3f1 */
/*! @{ */

#define locald58_LDPRR3F1_lumd1523_MASK          (0x3FFU)
#define locald58_LDPRR3F1_lumd1523_SHIFT         (0U)
/*! lumd1523 - lumdat_1523 */
#define locald58_LDPRR3F1_lumd1523(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F1_lumd1523_SHIFT)) & locald58_LDPRR3F1_lumd1523_MASK)

#define locald58_LDPRR3F1_lumd1522_MASK          (0x3FF0000U)
#define locald58_LDPRR3F1_lumd1522_SHIFT         (16U)
/*! lumd1522 - lumdat_1522 */
#define locald58_LDPRR3F1_lumd1522(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F1_lumd1522_SHIFT)) & locald58_LDPRR3F1_lumd1522_MASK)
/*! @} */

/*! @name LDPRR3F2 - ldprofilereg3f2 */
/*! @{ */

#define locald58_LDPRR3F2_lumd1525_MASK          (0x3FFU)
#define locald58_LDPRR3F2_lumd1525_SHIFT         (0U)
/*! lumd1525 - lumdat_1525 */
#define locald58_LDPRR3F2_lumd1525(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F2_lumd1525_SHIFT)) & locald58_LDPRR3F2_lumd1525_MASK)

#define locald58_LDPRR3F2_lumd1524_MASK          (0x3FF0000U)
#define locald58_LDPRR3F2_lumd1524_SHIFT         (16U)
/*! lumd1524 - lumdat_1524 */
#define locald58_LDPRR3F2_lumd1524(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F2_lumd1524_SHIFT)) & locald58_LDPRR3F2_lumd1524_MASK)
/*! @} */

/*! @name LDPRR3F3 - ldprofilereg3f3 */
/*! @{ */

#define locald58_LDPRR3F3_lumd1527_MASK          (0x3FFU)
#define locald58_LDPRR3F3_lumd1527_SHIFT         (0U)
/*! lumd1527 - lumdat_1527 */
#define locald58_LDPRR3F3_lumd1527(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F3_lumd1527_SHIFT)) & locald58_LDPRR3F3_lumd1527_MASK)

#define locald58_LDPRR3F3_lumd1526_MASK          (0x3FF0000U)
#define locald58_LDPRR3F3_lumd1526_SHIFT         (16U)
/*! lumd1526 - lumdat_1526 */
#define locald58_LDPRR3F3_lumd1526(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F3_lumd1526_SHIFT)) & locald58_LDPRR3F3_lumd1526_MASK)
/*! @} */

/*! @name LDPRR3F4 - ldprofilereg3f4 */
/*! @{ */

#define locald58_LDPRR3F4_lumd1529_MASK          (0x3FFU)
#define locald58_LDPRR3F4_lumd1529_SHIFT         (0U)
/*! lumd1529 - lumdat_1529 */
#define locald58_LDPRR3F4_lumd1529(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F4_lumd1529_SHIFT)) & locald58_LDPRR3F4_lumd1529_MASK)

#define locald58_LDPRR3F4_lumd1528_MASK          (0x3FF0000U)
#define locald58_LDPRR3F4_lumd1528_SHIFT         (16U)
/*! lumd1528 - lumdat_1528 */
#define locald58_LDPRR3F4_lumd1528(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F4_lumd1528_SHIFT)) & locald58_LDPRR3F4_lumd1528_MASK)
/*! @} */

/*! @name LDPRR3F5 - ldprofilereg3f5 */
/*! @{ */

#define locald58_LDPRR3F5_lumd1531_MASK          (0x3FFU)
#define locald58_LDPRR3F5_lumd1531_SHIFT         (0U)
/*! lumd1531 - lumdat_1531 */
#define locald58_LDPRR3F5_lumd1531(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F5_lumd1531_SHIFT)) & locald58_LDPRR3F5_lumd1531_MASK)

#define locald58_LDPRR3F5_lumd1530_MASK          (0x3FF0000U)
#define locald58_LDPRR3F5_lumd1530_SHIFT         (16U)
/*! lumd1530 - lumdat_1530 */
#define locald58_LDPRR3F5_lumd1530(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F5_lumd1530_SHIFT)) & locald58_LDPRR3F5_lumd1530_MASK)
/*! @} */

/*! @name LDPRR3F6 - ldprofilereg3f6 */
/*! @{ */

#define locald58_LDPRR3F6_lumd1533_MASK          (0x3FFU)
#define locald58_LDPRR3F6_lumd1533_SHIFT         (0U)
/*! lumd1533 - lumdat_1533 */
#define locald58_LDPRR3F6_lumd1533(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F6_lumd1533_SHIFT)) & locald58_LDPRR3F6_lumd1533_MASK)

#define locald58_LDPRR3F6_lumd1532_MASK          (0x3FF0000U)
#define locald58_LDPRR3F6_lumd1532_SHIFT         (16U)
/*! lumd1532 - lumdat_1532 */
#define locald58_LDPRR3F6_lumd1532(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F6_lumd1532_SHIFT)) & locald58_LDPRR3F6_lumd1532_MASK)
/*! @} */

/*! @name LDPRR3F7 - ldprofilereg3f7 */
/*! @{ */

#define locald58_LDPRR3F7_lumd1535_MASK          (0x3FFU)
#define locald58_LDPRR3F7_lumd1535_SHIFT         (0U)
/*! lumd1535 - lumdat_1535 */
#define locald58_LDPRR3F7_lumd1535(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F7_lumd1535_SHIFT)) & locald58_LDPRR3F7_lumd1535_MASK)

#define locald58_LDPRR3F7_lumd1534_MASK          (0x3FF0000U)
#define locald58_LDPRR3F7_lumd1534_SHIFT         (16U)
/*! lumd1534 - lumdat_1534 */
#define locald58_LDPRR3F7_lumd1534(x)            (((uint32_t)(((uint32_t)(x)) << locald58_LDPRR3F7_lumd1534_SHIFT)) & locald58_LDPRR3F7_lumd1534_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald58_Register_Masks */


/*!
 * @}
 */ /* end of group locald58_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD58_H_ */

