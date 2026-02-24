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
**         CMSIS Peripheral Access Layer for locald43
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
 * @file PERI_locald43.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald43
 *
 * CMSIS Peripheral Access Layer for locald43
 */

#if !defined(PERI_LOCALD43_H_)
#define PERI_LOCALD43_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald43 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald43_Peripheral_Access_Layer locald43 Peripheral Access Layer
 * @{
 */

/** locald43 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR200;                          /**< ldprofilereg200, offset: 0x0 */
  __IO uint32_t LDPRR201;                          /**< ldprofilereg201, offset: 0x4 */
  __IO uint32_t LDPRR202;                          /**< ldprofilereg202, offset: 0x8 */
  __IO uint32_t LDPRR203;                          /**< ldprofilereg203, offset: 0xC */
  __IO uint32_t LDPRR204;                          /**< ldprofilereg204, offset: 0x10 */
  __IO uint32_t LDPRR205;                          /**< ldprofilereg205, offset: 0x14 */
  __IO uint32_t LDPRR206;                          /**< ldprofilereg206, offset: 0x18 */
  __IO uint32_t LDPRR207;                          /**< ldprofilereg207, offset: 0x1C */
  __IO uint32_t LDPRR208;                          /**< ldprofilereg208, offset: 0x20 */
  __IO uint32_t LDPRR209;                          /**< ldprofilereg209, offset: 0x24 */
  __IO uint32_t LDPRR20A;                          /**< ldprofilereg20a, offset: 0x28 */
  __IO uint32_t LDPRR20B;                          /**< ldprofilereg20b, offset: 0x2C */
  __IO uint32_t LDPRR20C;                          /**< ldprofilereg20c, offset: 0x30 */
  __IO uint32_t LDPRR20D;                          /**< ldprofilereg20d, offset: 0x34 */
  __IO uint32_t LDPRR20E;                          /**< ldprofilereg20e, offset: 0x38 */
  __IO uint32_t LDPRR20F;                          /**< ldprofilereg20f, offset: 0x3C */
  __IO uint32_t LDPRR210;                          /**< ldprofilereg210, offset: 0x40 */
  __IO uint32_t LDPRR211;                          /**< ldprofilereg211, offset: 0x44 */
  __IO uint32_t LDPRR212;                          /**< ldprofilereg212, offset: 0x48 */
  __IO uint32_t LDPRR213;                          /**< ldprofilereg213, offset: 0x4C */
  __IO uint32_t LDPRR214;                          /**< ldprofilereg214, offset: 0x50 */
  __IO uint32_t LDPRR215;                          /**< ldprofilereg215, offset: 0x54 */
  __IO uint32_t LDPRR216;                          /**< ldprofilereg216, offset: 0x58 */
  __IO uint32_t LDPRR217;                          /**< ldprofilereg217, offset: 0x5C */
} locald43_Type;

/* ----------------------------------------------------------------------------
   -- locald43 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald43_Register_Masks locald43 Register Masks
 * @{
 */

/*! @name LDPRR200 - ldprofilereg200 */
/*! @{ */

#define locald43_LDPRR200_lumd769_MASK           (0x3FFU)
#define locald43_LDPRR200_lumd769_SHIFT          (0U)
/*! lumd769 - lumdat_769 */
#define locald43_LDPRR200_lumd769(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR200_lumd769_SHIFT)) & locald43_LDPRR200_lumd769_MASK)

#define locald43_LDPRR200_lumd768_MASK           (0x3FF0000U)
#define locald43_LDPRR200_lumd768_SHIFT          (16U)
/*! lumd768 - lumdat_768 */
#define locald43_LDPRR200_lumd768(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR200_lumd768_SHIFT)) & locald43_LDPRR200_lumd768_MASK)
/*! @} */

/*! @name LDPRR201 - ldprofilereg201 */
/*! @{ */

#define locald43_LDPRR201_lumd771_MASK           (0x3FFU)
#define locald43_LDPRR201_lumd771_SHIFT          (0U)
/*! lumd771 - lumdat_771 */
#define locald43_LDPRR201_lumd771(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR201_lumd771_SHIFT)) & locald43_LDPRR201_lumd771_MASK)

#define locald43_LDPRR201_lumd770_MASK           (0x3FF0000U)
#define locald43_LDPRR201_lumd770_SHIFT          (16U)
/*! lumd770 - lumdat_770 */
#define locald43_LDPRR201_lumd770(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR201_lumd770_SHIFT)) & locald43_LDPRR201_lumd770_MASK)
/*! @} */

/*! @name LDPRR202 - ldprofilereg202 */
/*! @{ */

#define locald43_LDPRR202_lumd773_MASK           (0x3FFU)
#define locald43_LDPRR202_lumd773_SHIFT          (0U)
/*! lumd773 - lumdat_773 */
#define locald43_LDPRR202_lumd773(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR202_lumd773_SHIFT)) & locald43_LDPRR202_lumd773_MASK)

#define locald43_LDPRR202_lumd772_MASK           (0x3FF0000U)
#define locald43_LDPRR202_lumd772_SHIFT          (16U)
/*! lumd772 - lumdat_772 */
#define locald43_LDPRR202_lumd772(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR202_lumd772_SHIFT)) & locald43_LDPRR202_lumd772_MASK)
/*! @} */

/*! @name LDPRR203 - ldprofilereg203 */
/*! @{ */

#define locald43_LDPRR203_lumd775_MASK           (0x3FFU)
#define locald43_LDPRR203_lumd775_SHIFT          (0U)
/*! lumd775 - lumdat_775 */
#define locald43_LDPRR203_lumd775(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR203_lumd775_SHIFT)) & locald43_LDPRR203_lumd775_MASK)

#define locald43_LDPRR203_lumd774_MASK           (0x3FF0000U)
#define locald43_LDPRR203_lumd774_SHIFT          (16U)
/*! lumd774 - lumdat_774 */
#define locald43_LDPRR203_lumd774(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR203_lumd774_SHIFT)) & locald43_LDPRR203_lumd774_MASK)
/*! @} */

/*! @name LDPRR204 - ldprofilereg204 */
/*! @{ */

#define locald43_LDPRR204_lumd777_MASK           (0x3FFU)
#define locald43_LDPRR204_lumd777_SHIFT          (0U)
/*! lumd777 - lumdat_777 */
#define locald43_LDPRR204_lumd777(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR204_lumd777_SHIFT)) & locald43_LDPRR204_lumd777_MASK)

#define locald43_LDPRR204_lumd776_MASK           (0x3FF0000U)
#define locald43_LDPRR204_lumd776_SHIFT          (16U)
/*! lumd776 - lumdat_776 */
#define locald43_LDPRR204_lumd776(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR204_lumd776_SHIFT)) & locald43_LDPRR204_lumd776_MASK)
/*! @} */

/*! @name LDPRR205 - ldprofilereg205 */
/*! @{ */

#define locald43_LDPRR205_lumd779_MASK           (0x3FFU)
#define locald43_LDPRR205_lumd779_SHIFT          (0U)
/*! lumd779 - lumdat_779 */
#define locald43_LDPRR205_lumd779(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR205_lumd779_SHIFT)) & locald43_LDPRR205_lumd779_MASK)

#define locald43_LDPRR205_lumd778_MASK           (0x3FF0000U)
#define locald43_LDPRR205_lumd778_SHIFT          (16U)
/*! lumd778 - lumdat_778 */
#define locald43_LDPRR205_lumd778(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR205_lumd778_SHIFT)) & locald43_LDPRR205_lumd778_MASK)
/*! @} */

/*! @name LDPRR206 - ldprofilereg206 */
/*! @{ */

#define locald43_LDPRR206_lumd781_MASK           (0x3FFU)
#define locald43_LDPRR206_lumd781_SHIFT          (0U)
/*! lumd781 - lumdat_781 */
#define locald43_LDPRR206_lumd781(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR206_lumd781_SHIFT)) & locald43_LDPRR206_lumd781_MASK)

#define locald43_LDPRR206_lumd780_MASK           (0x3FF0000U)
#define locald43_LDPRR206_lumd780_SHIFT          (16U)
/*! lumd780 - lumdat_780 */
#define locald43_LDPRR206_lumd780(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR206_lumd780_SHIFT)) & locald43_LDPRR206_lumd780_MASK)
/*! @} */

/*! @name LDPRR207 - ldprofilereg207 */
/*! @{ */

#define locald43_LDPRR207_lumd783_MASK           (0x3FFU)
#define locald43_LDPRR207_lumd783_SHIFT          (0U)
/*! lumd783 - lumdat_783 */
#define locald43_LDPRR207_lumd783(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR207_lumd783_SHIFT)) & locald43_LDPRR207_lumd783_MASK)

#define locald43_LDPRR207_lumd782_MASK           (0x3FF0000U)
#define locald43_LDPRR207_lumd782_SHIFT          (16U)
/*! lumd782 - lumdat_782 */
#define locald43_LDPRR207_lumd782(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR207_lumd782_SHIFT)) & locald43_LDPRR207_lumd782_MASK)
/*! @} */

/*! @name LDPRR208 - ldprofilereg208 */
/*! @{ */

#define locald43_LDPRR208_lumd785_MASK           (0x3FFU)
#define locald43_LDPRR208_lumd785_SHIFT          (0U)
/*! lumd785 - lumdat_785 */
#define locald43_LDPRR208_lumd785(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR208_lumd785_SHIFT)) & locald43_LDPRR208_lumd785_MASK)

#define locald43_LDPRR208_lumd784_MASK           (0x3FF0000U)
#define locald43_LDPRR208_lumd784_SHIFT          (16U)
/*! lumd784 - lumdat_784 */
#define locald43_LDPRR208_lumd784(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR208_lumd784_SHIFT)) & locald43_LDPRR208_lumd784_MASK)
/*! @} */

/*! @name LDPRR209 - ldprofilereg209 */
/*! @{ */

#define locald43_LDPRR209_lumd787_MASK           (0x3FFU)
#define locald43_LDPRR209_lumd787_SHIFT          (0U)
/*! lumd787 - lumdat_787 */
#define locald43_LDPRR209_lumd787(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR209_lumd787_SHIFT)) & locald43_LDPRR209_lumd787_MASK)

#define locald43_LDPRR209_lumd786_MASK           (0x3FF0000U)
#define locald43_LDPRR209_lumd786_SHIFT          (16U)
/*! lumd786 - lumdat_786 */
#define locald43_LDPRR209_lumd786(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR209_lumd786_SHIFT)) & locald43_LDPRR209_lumd786_MASK)
/*! @} */

/*! @name LDPRR20A - ldprofilereg20a */
/*! @{ */

#define locald43_LDPRR20A_lumd789_MASK           (0x3FFU)
#define locald43_LDPRR20A_lumd789_SHIFT          (0U)
/*! lumd789 - lumdat_789 */
#define locald43_LDPRR20A_lumd789(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20A_lumd789_SHIFT)) & locald43_LDPRR20A_lumd789_MASK)

#define locald43_LDPRR20A_lumd788_MASK           (0x3FF0000U)
#define locald43_LDPRR20A_lumd788_SHIFT          (16U)
/*! lumd788 - lumdat_788 */
#define locald43_LDPRR20A_lumd788(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20A_lumd788_SHIFT)) & locald43_LDPRR20A_lumd788_MASK)
/*! @} */

/*! @name LDPRR20B - ldprofilereg20b */
/*! @{ */

#define locald43_LDPRR20B_lumd791_MASK           (0x3FFU)
#define locald43_LDPRR20B_lumd791_SHIFT          (0U)
/*! lumd791 - lumdat_791 */
#define locald43_LDPRR20B_lumd791(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20B_lumd791_SHIFT)) & locald43_LDPRR20B_lumd791_MASK)

#define locald43_LDPRR20B_lumd790_MASK           (0x3FF0000U)
#define locald43_LDPRR20B_lumd790_SHIFT          (16U)
/*! lumd790 - lumdat_790 */
#define locald43_LDPRR20B_lumd790(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20B_lumd790_SHIFT)) & locald43_LDPRR20B_lumd790_MASK)
/*! @} */

/*! @name LDPRR20C - ldprofilereg20c */
/*! @{ */

#define locald43_LDPRR20C_lumd793_MASK           (0x3FFU)
#define locald43_LDPRR20C_lumd793_SHIFT          (0U)
/*! lumd793 - lumdat_793 */
#define locald43_LDPRR20C_lumd793(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20C_lumd793_SHIFT)) & locald43_LDPRR20C_lumd793_MASK)

#define locald43_LDPRR20C_lumd792_MASK           (0x3FF0000U)
#define locald43_LDPRR20C_lumd792_SHIFT          (16U)
/*! lumd792 - lumdat_792 */
#define locald43_LDPRR20C_lumd792(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20C_lumd792_SHIFT)) & locald43_LDPRR20C_lumd792_MASK)
/*! @} */

/*! @name LDPRR20D - ldprofilereg20d */
/*! @{ */

#define locald43_LDPRR20D_lumd795_MASK           (0x3FFU)
#define locald43_LDPRR20D_lumd795_SHIFT          (0U)
/*! lumd795 - lumdat_795 */
#define locald43_LDPRR20D_lumd795(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20D_lumd795_SHIFT)) & locald43_LDPRR20D_lumd795_MASK)

#define locald43_LDPRR20D_lumd794_MASK           (0x3FF0000U)
#define locald43_LDPRR20D_lumd794_SHIFT          (16U)
/*! lumd794 - lumdat_794 */
#define locald43_LDPRR20D_lumd794(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20D_lumd794_SHIFT)) & locald43_LDPRR20D_lumd794_MASK)
/*! @} */

/*! @name LDPRR20E - ldprofilereg20e */
/*! @{ */

#define locald43_LDPRR20E_lumd797_MASK           (0x3FFU)
#define locald43_LDPRR20E_lumd797_SHIFT          (0U)
/*! lumd797 - lumdat_797 */
#define locald43_LDPRR20E_lumd797(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20E_lumd797_SHIFT)) & locald43_LDPRR20E_lumd797_MASK)

#define locald43_LDPRR20E_lumd796_MASK           (0x3FF0000U)
#define locald43_LDPRR20E_lumd796_SHIFT          (16U)
/*! lumd796 - lumdat_796 */
#define locald43_LDPRR20E_lumd796(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20E_lumd796_SHIFT)) & locald43_LDPRR20E_lumd796_MASK)
/*! @} */

/*! @name LDPRR20F - ldprofilereg20f */
/*! @{ */

#define locald43_LDPRR20F_lumd799_MASK           (0x3FFU)
#define locald43_LDPRR20F_lumd799_SHIFT          (0U)
/*! lumd799 - lumdat_799 */
#define locald43_LDPRR20F_lumd799(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20F_lumd799_SHIFT)) & locald43_LDPRR20F_lumd799_MASK)

#define locald43_LDPRR20F_lumd798_MASK           (0x3FF0000U)
#define locald43_LDPRR20F_lumd798_SHIFT          (16U)
/*! lumd798 - lumdat_798 */
#define locald43_LDPRR20F_lumd798(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR20F_lumd798_SHIFT)) & locald43_LDPRR20F_lumd798_MASK)
/*! @} */

/*! @name LDPRR210 - ldprofilereg210 */
/*! @{ */

#define locald43_LDPRR210_lumd801_MASK           (0x3FFU)
#define locald43_LDPRR210_lumd801_SHIFT          (0U)
/*! lumd801 - lumdat_801 */
#define locald43_LDPRR210_lumd801(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR210_lumd801_SHIFT)) & locald43_LDPRR210_lumd801_MASK)

#define locald43_LDPRR210_lumd800_MASK           (0x3FF0000U)
#define locald43_LDPRR210_lumd800_SHIFT          (16U)
/*! lumd800 - lumdat_800 */
#define locald43_LDPRR210_lumd800(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR210_lumd800_SHIFT)) & locald43_LDPRR210_lumd800_MASK)
/*! @} */

/*! @name LDPRR211 - ldprofilereg211 */
/*! @{ */

#define locald43_LDPRR211_lumd803_MASK           (0x3FFU)
#define locald43_LDPRR211_lumd803_SHIFT          (0U)
/*! lumd803 - lumdat_803 */
#define locald43_LDPRR211_lumd803(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR211_lumd803_SHIFT)) & locald43_LDPRR211_lumd803_MASK)

#define locald43_LDPRR211_lumd802_MASK           (0x3FF0000U)
#define locald43_LDPRR211_lumd802_SHIFT          (16U)
/*! lumd802 - lumdat_802 */
#define locald43_LDPRR211_lumd802(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR211_lumd802_SHIFT)) & locald43_LDPRR211_lumd802_MASK)
/*! @} */

/*! @name LDPRR212 - ldprofilereg212 */
/*! @{ */

#define locald43_LDPRR212_lumd805_MASK           (0x3FFU)
#define locald43_LDPRR212_lumd805_SHIFT          (0U)
/*! lumd805 - lumdat_805 */
#define locald43_LDPRR212_lumd805(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR212_lumd805_SHIFT)) & locald43_LDPRR212_lumd805_MASK)

#define locald43_LDPRR212_lumd804_MASK           (0x3FF0000U)
#define locald43_LDPRR212_lumd804_SHIFT          (16U)
/*! lumd804 - lumdat_804 */
#define locald43_LDPRR212_lumd804(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR212_lumd804_SHIFT)) & locald43_LDPRR212_lumd804_MASK)
/*! @} */

/*! @name LDPRR213 - ldprofilereg213 */
/*! @{ */

#define locald43_LDPRR213_lumd807_MASK           (0x3FFU)
#define locald43_LDPRR213_lumd807_SHIFT          (0U)
/*! lumd807 - lumdat_807 */
#define locald43_LDPRR213_lumd807(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR213_lumd807_SHIFT)) & locald43_LDPRR213_lumd807_MASK)

#define locald43_LDPRR213_lumd806_MASK           (0x3FF0000U)
#define locald43_LDPRR213_lumd806_SHIFT          (16U)
/*! lumd806 - lumdat_806 */
#define locald43_LDPRR213_lumd806(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR213_lumd806_SHIFT)) & locald43_LDPRR213_lumd806_MASK)
/*! @} */

/*! @name LDPRR214 - ldprofilereg214 */
/*! @{ */

#define locald43_LDPRR214_lumd809_MASK           (0x3FFU)
#define locald43_LDPRR214_lumd809_SHIFT          (0U)
/*! lumd809 - lumdat_809 */
#define locald43_LDPRR214_lumd809(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR214_lumd809_SHIFT)) & locald43_LDPRR214_lumd809_MASK)

#define locald43_LDPRR214_lumd808_MASK           (0x3FF0000U)
#define locald43_LDPRR214_lumd808_SHIFT          (16U)
/*! lumd808 - lumdat_808 */
#define locald43_LDPRR214_lumd808(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR214_lumd808_SHIFT)) & locald43_LDPRR214_lumd808_MASK)
/*! @} */

/*! @name LDPRR215 - ldprofilereg215 */
/*! @{ */

#define locald43_LDPRR215_lumd811_MASK           (0x3FFU)
#define locald43_LDPRR215_lumd811_SHIFT          (0U)
/*! lumd811 - lumdat_811 */
#define locald43_LDPRR215_lumd811(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR215_lumd811_SHIFT)) & locald43_LDPRR215_lumd811_MASK)

#define locald43_LDPRR215_lumd810_MASK           (0x3FF0000U)
#define locald43_LDPRR215_lumd810_SHIFT          (16U)
/*! lumd810 - lumdat_810 */
#define locald43_LDPRR215_lumd810(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR215_lumd810_SHIFT)) & locald43_LDPRR215_lumd810_MASK)
/*! @} */

/*! @name LDPRR216 - ldprofilereg216 */
/*! @{ */

#define locald43_LDPRR216_lumd813_MASK           (0x3FFU)
#define locald43_LDPRR216_lumd813_SHIFT          (0U)
/*! lumd813 - lumdat_813 */
#define locald43_LDPRR216_lumd813(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR216_lumd813_SHIFT)) & locald43_LDPRR216_lumd813_MASK)

#define locald43_LDPRR216_lumd812_MASK           (0x3FF0000U)
#define locald43_LDPRR216_lumd812_SHIFT          (16U)
/*! lumd812 - lumdat_812 */
#define locald43_LDPRR216_lumd812(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR216_lumd812_SHIFT)) & locald43_LDPRR216_lumd812_MASK)
/*! @} */

/*! @name LDPRR217 - ldprofilereg217 */
/*! @{ */

#define locald43_LDPRR217_lumd815_MASK           (0x3FFU)
#define locald43_LDPRR217_lumd815_SHIFT          (0U)
/*! lumd815 - lumdat_815 */
#define locald43_LDPRR217_lumd815(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR217_lumd815_SHIFT)) & locald43_LDPRR217_lumd815_MASK)

#define locald43_LDPRR217_lumd814_MASK           (0x3FF0000U)
#define locald43_LDPRR217_lumd814_SHIFT          (16U)
/*! lumd814 - lumdat_814 */
#define locald43_LDPRR217_lumd814(x)             (((uint32_t)(((uint32_t)(x)) << locald43_LDPRR217_lumd814_SHIFT)) & locald43_LDPRR217_lumd814_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald43_Register_Masks */


/*!
 * @}
 */ /* end of group locald43_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD43_H_ */

