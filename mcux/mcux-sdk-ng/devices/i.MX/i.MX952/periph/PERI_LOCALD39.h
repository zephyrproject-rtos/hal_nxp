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
**         CMSIS Peripheral Access Layer for locald39
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
 * @file PERI_locald39.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald39
 *
 * CMSIS Peripheral Access Layer for locald39
 */

#if !defined(PERI_LOCALD39_H_)
#define PERI_LOCALD39_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald39 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald39_Peripheral_Access_Layer locald39 Peripheral Access Layer
 * @{
 */

/** locald39 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR180;                          /**< ldprofilereg180, offset: 0x0 */
  __IO uint32_t LDPRR181;                          /**< ldprofilereg181, offset: 0x4 */
  __IO uint32_t LDPRR182;                          /**< ldprofilereg182, offset: 0x8 */
  __IO uint32_t LDPRR183;                          /**< ldprofilereg183, offset: 0xC */
  __IO uint32_t LDPRR184;                          /**< ldprofilereg184, offset: 0x10 */
  __IO uint32_t LDPRR185;                          /**< ldprofilereg185, offset: 0x14 */
  __IO uint32_t LDPRR186;                          /**< ldprofilereg186, offset: 0x18 */
  __IO uint32_t LDPRR187;                          /**< ldprofilereg187, offset: 0x1C */
  __IO uint32_t LDPRR188;                          /**< ldprofilereg188, offset: 0x20 */
  __IO uint32_t LDPRR189;                          /**< ldprofilereg189, offset: 0x24 */
  __IO uint32_t LDPRR18A;                          /**< ldprofilereg18a, offset: 0x28 */
  __IO uint32_t LDPRR18B;                          /**< ldprofilereg18b, offset: 0x2C */
  __IO uint32_t LDPRR18C;                          /**< ldprofilereg18c, offset: 0x30 */
  __IO uint32_t LDPRR18D;                          /**< ldprofilereg18d, offset: 0x34 */
  __IO uint32_t LDPRR18E;                          /**< ldprofilereg18e, offset: 0x38 */
  __IO uint32_t LDPRR18F;                          /**< ldprofilereg18f, offset: 0x3C */
  __IO uint32_t LDPRR190;                          /**< ldprofilereg190, offset: 0x40 */
  __IO uint32_t LDPRR191;                          /**< ldprofilereg191, offset: 0x44 */
  __IO uint32_t LDPRR192;                          /**< ldprofilereg192, offset: 0x48 */
  __IO uint32_t LDPRR193;                          /**< ldprofilereg193, offset: 0x4C */
  __IO uint32_t LDPRR194;                          /**< ldprofilereg194, offset: 0x50 */
  __IO uint32_t LDPRR195;                          /**< ldprofilereg195, offset: 0x54 */
  __IO uint32_t LDPRR196;                          /**< ldprofilereg196, offset: 0x58 */
  __IO uint32_t LDPRR197;                          /**< ldprofilereg197, offset: 0x5C */
} locald39_Type;

/* ----------------------------------------------------------------------------
   -- locald39 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald39_Register_Masks locald39 Register Masks
 * @{
 */

/*! @name LDPRR180 - ldprofilereg180 */
/*! @{ */

#define locald39_LDPRR180_lumd577_MASK           (0x3FFU)
#define locald39_LDPRR180_lumd577_SHIFT          (0U)
/*! lumd577 - lumdat_577 */
#define locald39_LDPRR180_lumd577(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR180_lumd577_SHIFT)) & locald39_LDPRR180_lumd577_MASK)

#define locald39_LDPRR180_lumd576_MASK           (0x3FF0000U)
#define locald39_LDPRR180_lumd576_SHIFT          (16U)
/*! lumd576 - lumdat_576 */
#define locald39_LDPRR180_lumd576(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR180_lumd576_SHIFT)) & locald39_LDPRR180_lumd576_MASK)
/*! @} */

/*! @name LDPRR181 - ldprofilereg181 */
/*! @{ */

#define locald39_LDPRR181_lumd579_MASK           (0x3FFU)
#define locald39_LDPRR181_lumd579_SHIFT          (0U)
/*! lumd579 - lumdat_579 */
#define locald39_LDPRR181_lumd579(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR181_lumd579_SHIFT)) & locald39_LDPRR181_lumd579_MASK)

#define locald39_LDPRR181_lumd578_MASK           (0x3FF0000U)
#define locald39_LDPRR181_lumd578_SHIFT          (16U)
/*! lumd578 - lumdat_578 */
#define locald39_LDPRR181_lumd578(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR181_lumd578_SHIFT)) & locald39_LDPRR181_lumd578_MASK)
/*! @} */

/*! @name LDPRR182 - ldprofilereg182 */
/*! @{ */

#define locald39_LDPRR182_lumd581_MASK           (0x3FFU)
#define locald39_LDPRR182_lumd581_SHIFT          (0U)
/*! lumd581 - lumdat_581 */
#define locald39_LDPRR182_lumd581(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR182_lumd581_SHIFT)) & locald39_LDPRR182_lumd581_MASK)

#define locald39_LDPRR182_lumd580_MASK           (0x3FF0000U)
#define locald39_LDPRR182_lumd580_SHIFT          (16U)
/*! lumd580 - lumdat_580 */
#define locald39_LDPRR182_lumd580(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR182_lumd580_SHIFT)) & locald39_LDPRR182_lumd580_MASK)
/*! @} */

/*! @name LDPRR183 - ldprofilereg183 */
/*! @{ */

#define locald39_LDPRR183_lumd583_MASK           (0x3FFU)
#define locald39_LDPRR183_lumd583_SHIFT          (0U)
/*! lumd583 - lumdat_583 */
#define locald39_LDPRR183_lumd583(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR183_lumd583_SHIFT)) & locald39_LDPRR183_lumd583_MASK)

#define locald39_LDPRR183_lumd582_MASK           (0x3FF0000U)
#define locald39_LDPRR183_lumd582_SHIFT          (16U)
/*! lumd582 - lumdat_582 */
#define locald39_LDPRR183_lumd582(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR183_lumd582_SHIFT)) & locald39_LDPRR183_lumd582_MASK)
/*! @} */

/*! @name LDPRR184 - ldprofilereg184 */
/*! @{ */

#define locald39_LDPRR184_lumd585_MASK           (0x3FFU)
#define locald39_LDPRR184_lumd585_SHIFT          (0U)
/*! lumd585 - lumdat_585 */
#define locald39_LDPRR184_lumd585(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR184_lumd585_SHIFT)) & locald39_LDPRR184_lumd585_MASK)

#define locald39_LDPRR184_lumd584_MASK           (0x3FF0000U)
#define locald39_LDPRR184_lumd584_SHIFT          (16U)
/*! lumd584 - lumdat_584 */
#define locald39_LDPRR184_lumd584(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR184_lumd584_SHIFT)) & locald39_LDPRR184_lumd584_MASK)
/*! @} */

/*! @name LDPRR185 - ldprofilereg185 */
/*! @{ */

#define locald39_LDPRR185_lumd587_MASK           (0x3FFU)
#define locald39_LDPRR185_lumd587_SHIFT          (0U)
/*! lumd587 - lumdat_587 */
#define locald39_LDPRR185_lumd587(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR185_lumd587_SHIFT)) & locald39_LDPRR185_lumd587_MASK)

#define locald39_LDPRR185_lumd586_MASK           (0x3FF0000U)
#define locald39_LDPRR185_lumd586_SHIFT          (16U)
/*! lumd586 - lumdat_586 */
#define locald39_LDPRR185_lumd586(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR185_lumd586_SHIFT)) & locald39_LDPRR185_lumd586_MASK)
/*! @} */

/*! @name LDPRR186 - ldprofilereg186 */
/*! @{ */

#define locald39_LDPRR186_lumd589_MASK           (0x3FFU)
#define locald39_LDPRR186_lumd589_SHIFT          (0U)
/*! lumd589 - lumdat_589 */
#define locald39_LDPRR186_lumd589(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR186_lumd589_SHIFT)) & locald39_LDPRR186_lumd589_MASK)

#define locald39_LDPRR186_lumd588_MASK           (0x3FF0000U)
#define locald39_LDPRR186_lumd588_SHIFT          (16U)
/*! lumd588 - lumdat_588 */
#define locald39_LDPRR186_lumd588(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR186_lumd588_SHIFT)) & locald39_LDPRR186_lumd588_MASK)
/*! @} */

/*! @name LDPRR187 - ldprofilereg187 */
/*! @{ */

#define locald39_LDPRR187_lumd591_MASK           (0x3FFU)
#define locald39_LDPRR187_lumd591_SHIFT          (0U)
/*! lumd591 - lumdat_591 */
#define locald39_LDPRR187_lumd591(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR187_lumd591_SHIFT)) & locald39_LDPRR187_lumd591_MASK)

#define locald39_LDPRR187_lumd590_MASK           (0x3FF0000U)
#define locald39_LDPRR187_lumd590_SHIFT          (16U)
/*! lumd590 - lumdat_590 */
#define locald39_LDPRR187_lumd590(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR187_lumd590_SHIFT)) & locald39_LDPRR187_lumd590_MASK)
/*! @} */

/*! @name LDPRR188 - ldprofilereg188 */
/*! @{ */

#define locald39_LDPRR188_lumd593_MASK           (0x3FFU)
#define locald39_LDPRR188_lumd593_SHIFT          (0U)
/*! lumd593 - lumdat_593 */
#define locald39_LDPRR188_lumd593(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR188_lumd593_SHIFT)) & locald39_LDPRR188_lumd593_MASK)

#define locald39_LDPRR188_lumd592_MASK           (0x3FF0000U)
#define locald39_LDPRR188_lumd592_SHIFT          (16U)
/*! lumd592 - lumdat_592 */
#define locald39_LDPRR188_lumd592(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR188_lumd592_SHIFT)) & locald39_LDPRR188_lumd592_MASK)
/*! @} */

/*! @name LDPRR189 - ldprofilereg189 */
/*! @{ */

#define locald39_LDPRR189_lumd595_MASK           (0x3FFU)
#define locald39_LDPRR189_lumd595_SHIFT          (0U)
/*! lumd595 - lumdat_595 */
#define locald39_LDPRR189_lumd595(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR189_lumd595_SHIFT)) & locald39_LDPRR189_lumd595_MASK)

#define locald39_LDPRR189_lumd594_MASK           (0x3FF0000U)
#define locald39_LDPRR189_lumd594_SHIFT          (16U)
/*! lumd594 - lumdat_594 */
#define locald39_LDPRR189_lumd594(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR189_lumd594_SHIFT)) & locald39_LDPRR189_lumd594_MASK)
/*! @} */

/*! @name LDPRR18A - ldprofilereg18a */
/*! @{ */

#define locald39_LDPRR18A_lumd597_MASK           (0x3FFU)
#define locald39_LDPRR18A_lumd597_SHIFT          (0U)
/*! lumd597 - lumdat_597 */
#define locald39_LDPRR18A_lumd597(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18A_lumd597_SHIFT)) & locald39_LDPRR18A_lumd597_MASK)

#define locald39_LDPRR18A_lumd596_MASK           (0x3FF0000U)
#define locald39_LDPRR18A_lumd596_SHIFT          (16U)
/*! lumd596 - lumdat_596 */
#define locald39_LDPRR18A_lumd596(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18A_lumd596_SHIFT)) & locald39_LDPRR18A_lumd596_MASK)
/*! @} */

/*! @name LDPRR18B - ldprofilereg18b */
/*! @{ */

#define locald39_LDPRR18B_lumd599_MASK           (0x3FFU)
#define locald39_LDPRR18B_lumd599_SHIFT          (0U)
/*! lumd599 - lumdat_599 */
#define locald39_LDPRR18B_lumd599(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18B_lumd599_SHIFT)) & locald39_LDPRR18B_lumd599_MASK)

#define locald39_LDPRR18B_lumd598_MASK           (0x3FF0000U)
#define locald39_LDPRR18B_lumd598_SHIFT          (16U)
/*! lumd598 - lumdat_598 */
#define locald39_LDPRR18B_lumd598(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18B_lumd598_SHIFT)) & locald39_LDPRR18B_lumd598_MASK)
/*! @} */

/*! @name LDPRR18C - ldprofilereg18c */
/*! @{ */

#define locald39_LDPRR18C_lumd601_MASK           (0x3FFU)
#define locald39_LDPRR18C_lumd601_SHIFT          (0U)
/*! lumd601 - lumdat_601 */
#define locald39_LDPRR18C_lumd601(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18C_lumd601_SHIFT)) & locald39_LDPRR18C_lumd601_MASK)

#define locald39_LDPRR18C_lumd600_MASK           (0x3FF0000U)
#define locald39_LDPRR18C_lumd600_SHIFT          (16U)
/*! lumd600 - lumdat_600 */
#define locald39_LDPRR18C_lumd600(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18C_lumd600_SHIFT)) & locald39_LDPRR18C_lumd600_MASK)
/*! @} */

/*! @name LDPRR18D - ldprofilereg18d */
/*! @{ */

#define locald39_LDPRR18D_lumd603_MASK           (0x3FFU)
#define locald39_LDPRR18D_lumd603_SHIFT          (0U)
/*! lumd603 - lumdat_603 */
#define locald39_LDPRR18D_lumd603(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18D_lumd603_SHIFT)) & locald39_LDPRR18D_lumd603_MASK)

#define locald39_LDPRR18D_lumd602_MASK           (0x3FF0000U)
#define locald39_LDPRR18D_lumd602_SHIFT          (16U)
/*! lumd602 - lumdat_602 */
#define locald39_LDPRR18D_lumd602(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18D_lumd602_SHIFT)) & locald39_LDPRR18D_lumd602_MASK)
/*! @} */

/*! @name LDPRR18E - ldprofilereg18e */
/*! @{ */

#define locald39_LDPRR18E_lumd605_MASK           (0x3FFU)
#define locald39_LDPRR18E_lumd605_SHIFT          (0U)
/*! lumd605 - lumdat_605 */
#define locald39_LDPRR18E_lumd605(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18E_lumd605_SHIFT)) & locald39_LDPRR18E_lumd605_MASK)

#define locald39_LDPRR18E_lumd604_MASK           (0x3FF0000U)
#define locald39_LDPRR18E_lumd604_SHIFT          (16U)
/*! lumd604 - lumdat_604 */
#define locald39_LDPRR18E_lumd604(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18E_lumd604_SHIFT)) & locald39_LDPRR18E_lumd604_MASK)
/*! @} */

/*! @name LDPRR18F - ldprofilereg18f */
/*! @{ */

#define locald39_LDPRR18F_lumd607_MASK           (0x3FFU)
#define locald39_LDPRR18F_lumd607_SHIFT          (0U)
/*! lumd607 - lumdat_607 */
#define locald39_LDPRR18F_lumd607(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18F_lumd607_SHIFT)) & locald39_LDPRR18F_lumd607_MASK)

#define locald39_LDPRR18F_lumd606_MASK           (0x3FF0000U)
#define locald39_LDPRR18F_lumd606_SHIFT          (16U)
/*! lumd606 - lumdat_606 */
#define locald39_LDPRR18F_lumd606(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR18F_lumd606_SHIFT)) & locald39_LDPRR18F_lumd606_MASK)
/*! @} */

/*! @name LDPRR190 - ldprofilereg190 */
/*! @{ */

#define locald39_LDPRR190_lumd609_MASK           (0x3FFU)
#define locald39_LDPRR190_lumd609_SHIFT          (0U)
/*! lumd609 - lumdat_609 */
#define locald39_LDPRR190_lumd609(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR190_lumd609_SHIFT)) & locald39_LDPRR190_lumd609_MASK)

#define locald39_LDPRR190_lumd608_MASK           (0x3FF0000U)
#define locald39_LDPRR190_lumd608_SHIFT          (16U)
/*! lumd608 - lumdat_608 */
#define locald39_LDPRR190_lumd608(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR190_lumd608_SHIFT)) & locald39_LDPRR190_lumd608_MASK)
/*! @} */

/*! @name LDPRR191 - ldprofilereg191 */
/*! @{ */

#define locald39_LDPRR191_lumd611_MASK           (0x3FFU)
#define locald39_LDPRR191_lumd611_SHIFT          (0U)
/*! lumd611 - lumdat_611 */
#define locald39_LDPRR191_lumd611(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR191_lumd611_SHIFT)) & locald39_LDPRR191_lumd611_MASK)

#define locald39_LDPRR191_lumd610_MASK           (0x3FF0000U)
#define locald39_LDPRR191_lumd610_SHIFT          (16U)
/*! lumd610 - lumdat_610 */
#define locald39_LDPRR191_lumd610(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR191_lumd610_SHIFT)) & locald39_LDPRR191_lumd610_MASK)
/*! @} */

/*! @name LDPRR192 - ldprofilereg192 */
/*! @{ */

#define locald39_LDPRR192_lumd613_MASK           (0x3FFU)
#define locald39_LDPRR192_lumd613_SHIFT          (0U)
/*! lumd613 - lumdat_613 */
#define locald39_LDPRR192_lumd613(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR192_lumd613_SHIFT)) & locald39_LDPRR192_lumd613_MASK)

#define locald39_LDPRR192_lumd612_MASK           (0x3FF0000U)
#define locald39_LDPRR192_lumd612_SHIFT          (16U)
/*! lumd612 - lumdat_612 */
#define locald39_LDPRR192_lumd612(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR192_lumd612_SHIFT)) & locald39_LDPRR192_lumd612_MASK)
/*! @} */

/*! @name LDPRR193 - ldprofilereg193 */
/*! @{ */

#define locald39_LDPRR193_lumd615_MASK           (0x3FFU)
#define locald39_LDPRR193_lumd615_SHIFT          (0U)
/*! lumd615 - lumdat_615 */
#define locald39_LDPRR193_lumd615(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR193_lumd615_SHIFT)) & locald39_LDPRR193_lumd615_MASK)

#define locald39_LDPRR193_lumd614_MASK           (0x3FF0000U)
#define locald39_LDPRR193_lumd614_SHIFT          (16U)
/*! lumd614 - lumdat_614 */
#define locald39_LDPRR193_lumd614(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR193_lumd614_SHIFT)) & locald39_LDPRR193_lumd614_MASK)
/*! @} */

/*! @name LDPRR194 - ldprofilereg194 */
/*! @{ */

#define locald39_LDPRR194_lumd617_MASK           (0x3FFU)
#define locald39_LDPRR194_lumd617_SHIFT          (0U)
/*! lumd617 - lumdat_617 */
#define locald39_LDPRR194_lumd617(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR194_lumd617_SHIFT)) & locald39_LDPRR194_lumd617_MASK)

#define locald39_LDPRR194_lumd616_MASK           (0x3FF0000U)
#define locald39_LDPRR194_lumd616_SHIFT          (16U)
/*! lumd616 - lumdat_616 */
#define locald39_LDPRR194_lumd616(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR194_lumd616_SHIFT)) & locald39_LDPRR194_lumd616_MASK)
/*! @} */

/*! @name LDPRR195 - ldprofilereg195 */
/*! @{ */

#define locald39_LDPRR195_lumd619_MASK           (0x3FFU)
#define locald39_LDPRR195_lumd619_SHIFT          (0U)
/*! lumd619 - lumdat_619 */
#define locald39_LDPRR195_lumd619(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR195_lumd619_SHIFT)) & locald39_LDPRR195_lumd619_MASK)

#define locald39_LDPRR195_lumd618_MASK           (0x3FF0000U)
#define locald39_LDPRR195_lumd618_SHIFT          (16U)
/*! lumd618 - lumdat_618 */
#define locald39_LDPRR195_lumd618(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR195_lumd618_SHIFT)) & locald39_LDPRR195_lumd618_MASK)
/*! @} */

/*! @name LDPRR196 - ldprofilereg196 */
/*! @{ */

#define locald39_LDPRR196_lumd621_MASK           (0x3FFU)
#define locald39_LDPRR196_lumd621_SHIFT          (0U)
/*! lumd621 - lumdat_621 */
#define locald39_LDPRR196_lumd621(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR196_lumd621_SHIFT)) & locald39_LDPRR196_lumd621_MASK)

#define locald39_LDPRR196_lumd620_MASK           (0x3FF0000U)
#define locald39_LDPRR196_lumd620_SHIFT          (16U)
/*! lumd620 - lumdat_620 */
#define locald39_LDPRR196_lumd620(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR196_lumd620_SHIFT)) & locald39_LDPRR196_lumd620_MASK)
/*! @} */

/*! @name LDPRR197 - ldprofilereg197 */
/*! @{ */

#define locald39_LDPRR197_lumd623_MASK           (0x3FFU)
#define locald39_LDPRR197_lumd623_SHIFT          (0U)
/*! lumd623 - lumdat_623 */
#define locald39_LDPRR197_lumd623(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR197_lumd623_SHIFT)) & locald39_LDPRR197_lumd623_MASK)

#define locald39_LDPRR197_lumd622_MASK           (0x3FF0000U)
#define locald39_LDPRR197_lumd622_SHIFT          (16U)
/*! lumd622 - lumdat_622 */
#define locald39_LDPRR197_lumd622(x)             (((uint32_t)(((uint32_t)(x)) << locald39_LDPRR197_lumd622_SHIFT)) & locald39_LDPRR197_lumd622_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald39_Register_Masks */


/*!
 * @}
 */ /* end of group locald39_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD39_H_ */

