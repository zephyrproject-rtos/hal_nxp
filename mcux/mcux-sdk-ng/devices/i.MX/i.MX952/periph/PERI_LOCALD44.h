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
**         CMSIS Peripheral Access Layer for locald44
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
 * @file PERI_locald44.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald44
 *
 * CMSIS Peripheral Access Layer for locald44
 */

#if !defined(PERI_LOCALD44_H_)
#define PERI_LOCALD44_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald44 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald44_Peripheral_Access_Layer locald44 Peripheral Access Layer
 * @{
 */

/** locald44 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR220;                          /**< ldprofilereg220, offset: 0x0 */
  __IO uint32_t LDPRR221;                          /**< ldprofilereg221, offset: 0x4 */
  __IO uint32_t LDPRR222;                          /**< ldprofilereg222, offset: 0x8 */
  __IO uint32_t LDPRR223;                          /**< ldprofilereg223, offset: 0xC */
  __IO uint32_t LDPRR224;                          /**< ldprofilereg224, offset: 0x10 */
  __IO uint32_t LDPRR225;                          /**< ldprofilereg225, offset: 0x14 */
  __IO uint32_t LDPRR226;                          /**< ldprofilereg226, offset: 0x18 */
  __IO uint32_t LDPRR227;                          /**< ldprofilereg227, offset: 0x1C */
  __IO uint32_t LDPRR228;                          /**< ldprofilereg228, offset: 0x20 */
  __IO uint32_t LDPRR229;                          /**< ldprofilereg229, offset: 0x24 */
  __IO uint32_t LDPRR22A;                          /**< ldprofilereg22a, offset: 0x28 */
  __IO uint32_t LDPRR22B;                          /**< ldprofilereg22b, offset: 0x2C */
  __IO uint32_t LDPRR22C;                          /**< ldprofilereg22c, offset: 0x30 */
  __IO uint32_t LDPRR22D;                          /**< ldprofilereg22d, offset: 0x34 */
  __IO uint32_t LDPRR22E;                          /**< ldprofilereg22e, offset: 0x38 */
  __IO uint32_t LDPRR22F;                          /**< ldprofilereg22f, offset: 0x3C */
  __IO uint32_t LDPRR230;                          /**< ldprofilereg230, offset: 0x40 */
  __IO uint32_t LDPRR231;                          /**< ldprofilereg231, offset: 0x44 */
  __IO uint32_t LDPRR232;                          /**< ldprofilereg232, offset: 0x48 */
  __IO uint32_t LDPRR233;                          /**< ldprofilereg233, offset: 0x4C */
  __IO uint32_t LDPRR234;                          /**< ldprofilereg234, offset: 0x50 */
  __IO uint32_t LDPRR235;                          /**< ldprofilereg235, offset: 0x54 */
  __IO uint32_t LDPRR236;                          /**< ldprofilereg236, offset: 0x58 */
  __IO uint32_t LDPRR237;                          /**< ldprofilereg237, offset: 0x5C */
} locald44_Type;

/* ----------------------------------------------------------------------------
   -- locald44 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald44_Register_Masks locald44 Register Masks
 * @{
 */

/*! @name LDPRR220 - ldprofilereg220 */
/*! @{ */

#define locald44_LDPRR220_lumd817_MASK           (0x3FFU)
#define locald44_LDPRR220_lumd817_SHIFT          (0U)
/*! lumd817 - lumdat_817 */
#define locald44_LDPRR220_lumd817(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR220_lumd817_SHIFT)) & locald44_LDPRR220_lumd817_MASK)

#define locald44_LDPRR220_lumd816_MASK           (0x3FF0000U)
#define locald44_LDPRR220_lumd816_SHIFT          (16U)
/*! lumd816 - lumdat_816 */
#define locald44_LDPRR220_lumd816(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR220_lumd816_SHIFT)) & locald44_LDPRR220_lumd816_MASK)
/*! @} */

/*! @name LDPRR221 - ldprofilereg221 */
/*! @{ */

#define locald44_LDPRR221_lumd819_MASK           (0x3FFU)
#define locald44_LDPRR221_lumd819_SHIFT          (0U)
/*! lumd819 - lumdat_819 */
#define locald44_LDPRR221_lumd819(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR221_lumd819_SHIFT)) & locald44_LDPRR221_lumd819_MASK)

#define locald44_LDPRR221_lumd818_MASK           (0x3FF0000U)
#define locald44_LDPRR221_lumd818_SHIFT          (16U)
/*! lumd818 - lumdat_818 */
#define locald44_LDPRR221_lumd818(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR221_lumd818_SHIFT)) & locald44_LDPRR221_lumd818_MASK)
/*! @} */

/*! @name LDPRR222 - ldprofilereg222 */
/*! @{ */

#define locald44_LDPRR222_lumd821_MASK           (0x3FFU)
#define locald44_LDPRR222_lumd821_SHIFT          (0U)
/*! lumd821 - lumdat_821 */
#define locald44_LDPRR222_lumd821(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR222_lumd821_SHIFT)) & locald44_LDPRR222_lumd821_MASK)

#define locald44_LDPRR222_lumd820_MASK           (0x3FF0000U)
#define locald44_LDPRR222_lumd820_SHIFT          (16U)
/*! lumd820 - lumdat_820 */
#define locald44_LDPRR222_lumd820(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR222_lumd820_SHIFT)) & locald44_LDPRR222_lumd820_MASK)
/*! @} */

/*! @name LDPRR223 - ldprofilereg223 */
/*! @{ */

#define locald44_LDPRR223_lumd823_MASK           (0x3FFU)
#define locald44_LDPRR223_lumd823_SHIFT          (0U)
/*! lumd823 - lumdat_823 */
#define locald44_LDPRR223_lumd823(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR223_lumd823_SHIFT)) & locald44_LDPRR223_lumd823_MASK)

#define locald44_LDPRR223_lumd822_MASK           (0x3FF0000U)
#define locald44_LDPRR223_lumd822_SHIFT          (16U)
/*! lumd822 - lumdat_822 */
#define locald44_LDPRR223_lumd822(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR223_lumd822_SHIFT)) & locald44_LDPRR223_lumd822_MASK)
/*! @} */

/*! @name LDPRR224 - ldprofilereg224 */
/*! @{ */

#define locald44_LDPRR224_lumd825_MASK           (0x3FFU)
#define locald44_LDPRR224_lumd825_SHIFT          (0U)
/*! lumd825 - lumdat_825 */
#define locald44_LDPRR224_lumd825(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR224_lumd825_SHIFT)) & locald44_LDPRR224_lumd825_MASK)

#define locald44_LDPRR224_lumd824_MASK           (0x3FF0000U)
#define locald44_LDPRR224_lumd824_SHIFT          (16U)
/*! lumd824 - lumdat_824 */
#define locald44_LDPRR224_lumd824(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR224_lumd824_SHIFT)) & locald44_LDPRR224_lumd824_MASK)
/*! @} */

/*! @name LDPRR225 - ldprofilereg225 */
/*! @{ */

#define locald44_LDPRR225_lumd827_MASK           (0x3FFU)
#define locald44_LDPRR225_lumd827_SHIFT          (0U)
/*! lumd827 - lumdat_827 */
#define locald44_LDPRR225_lumd827(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR225_lumd827_SHIFT)) & locald44_LDPRR225_lumd827_MASK)

#define locald44_LDPRR225_lumd826_MASK           (0x3FF0000U)
#define locald44_LDPRR225_lumd826_SHIFT          (16U)
/*! lumd826 - lumdat_826 */
#define locald44_LDPRR225_lumd826(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR225_lumd826_SHIFT)) & locald44_LDPRR225_lumd826_MASK)
/*! @} */

/*! @name LDPRR226 - ldprofilereg226 */
/*! @{ */

#define locald44_LDPRR226_lumd829_MASK           (0x3FFU)
#define locald44_LDPRR226_lumd829_SHIFT          (0U)
/*! lumd829 - lumdat_829 */
#define locald44_LDPRR226_lumd829(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR226_lumd829_SHIFT)) & locald44_LDPRR226_lumd829_MASK)

#define locald44_LDPRR226_lumd828_MASK           (0x3FF0000U)
#define locald44_LDPRR226_lumd828_SHIFT          (16U)
/*! lumd828 - lumdat_828 */
#define locald44_LDPRR226_lumd828(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR226_lumd828_SHIFT)) & locald44_LDPRR226_lumd828_MASK)
/*! @} */

/*! @name LDPRR227 - ldprofilereg227 */
/*! @{ */

#define locald44_LDPRR227_lumd831_MASK           (0x3FFU)
#define locald44_LDPRR227_lumd831_SHIFT          (0U)
/*! lumd831 - lumdat_831 */
#define locald44_LDPRR227_lumd831(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR227_lumd831_SHIFT)) & locald44_LDPRR227_lumd831_MASK)

#define locald44_LDPRR227_lumd830_MASK           (0x3FF0000U)
#define locald44_LDPRR227_lumd830_SHIFT          (16U)
/*! lumd830 - lumdat_830 */
#define locald44_LDPRR227_lumd830(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR227_lumd830_SHIFT)) & locald44_LDPRR227_lumd830_MASK)
/*! @} */

/*! @name LDPRR228 - ldprofilereg228 */
/*! @{ */

#define locald44_LDPRR228_lumd833_MASK           (0x3FFU)
#define locald44_LDPRR228_lumd833_SHIFT          (0U)
/*! lumd833 - lumdat_833 */
#define locald44_LDPRR228_lumd833(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR228_lumd833_SHIFT)) & locald44_LDPRR228_lumd833_MASK)

#define locald44_LDPRR228_lumd832_MASK           (0x3FF0000U)
#define locald44_LDPRR228_lumd832_SHIFT          (16U)
/*! lumd832 - lumdat_832 */
#define locald44_LDPRR228_lumd832(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR228_lumd832_SHIFT)) & locald44_LDPRR228_lumd832_MASK)
/*! @} */

/*! @name LDPRR229 - ldprofilereg229 */
/*! @{ */

#define locald44_LDPRR229_lumd835_MASK           (0x3FFU)
#define locald44_LDPRR229_lumd835_SHIFT          (0U)
/*! lumd835 - lumdat_835 */
#define locald44_LDPRR229_lumd835(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR229_lumd835_SHIFT)) & locald44_LDPRR229_lumd835_MASK)

#define locald44_LDPRR229_lumd834_MASK           (0x3FF0000U)
#define locald44_LDPRR229_lumd834_SHIFT          (16U)
/*! lumd834 - lumdat_834 */
#define locald44_LDPRR229_lumd834(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR229_lumd834_SHIFT)) & locald44_LDPRR229_lumd834_MASK)
/*! @} */

/*! @name LDPRR22A - ldprofilereg22a */
/*! @{ */

#define locald44_LDPRR22A_lumd837_MASK           (0x3FFU)
#define locald44_LDPRR22A_lumd837_SHIFT          (0U)
/*! lumd837 - lumdat_837 */
#define locald44_LDPRR22A_lumd837(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22A_lumd837_SHIFT)) & locald44_LDPRR22A_lumd837_MASK)

#define locald44_LDPRR22A_lumd836_MASK           (0x3FF0000U)
#define locald44_LDPRR22A_lumd836_SHIFT          (16U)
/*! lumd836 - lumdat_836 */
#define locald44_LDPRR22A_lumd836(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22A_lumd836_SHIFT)) & locald44_LDPRR22A_lumd836_MASK)
/*! @} */

/*! @name LDPRR22B - ldprofilereg22b */
/*! @{ */

#define locald44_LDPRR22B_lumd839_MASK           (0x3FFU)
#define locald44_LDPRR22B_lumd839_SHIFT          (0U)
/*! lumd839 - lumdat_839 */
#define locald44_LDPRR22B_lumd839(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22B_lumd839_SHIFT)) & locald44_LDPRR22B_lumd839_MASK)

#define locald44_LDPRR22B_lumd838_MASK           (0x3FF0000U)
#define locald44_LDPRR22B_lumd838_SHIFT          (16U)
/*! lumd838 - lumdat_838 */
#define locald44_LDPRR22B_lumd838(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22B_lumd838_SHIFT)) & locald44_LDPRR22B_lumd838_MASK)
/*! @} */

/*! @name LDPRR22C - ldprofilereg22c */
/*! @{ */

#define locald44_LDPRR22C_lumd841_MASK           (0x3FFU)
#define locald44_LDPRR22C_lumd841_SHIFT          (0U)
/*! lumd841 - lumdat_841 */
#define locald44_LDPRR22C_lumd841(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22C_lumd841_SHIFT)) & locald44_LDPRR22C_lumd841_MASK)

#define locald44_LDPRR22C_lumd840_MASK           (0x3FF0000U)
#define locald44_LDPRR22C_lumd840_SHIFT          (16U)
/*! lumd840 - lumdat_840 */
#define locald44_LDPRR22C_lumd840(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22C_lumd840_SHIFT)) & locald44_LDPRR22C_lumd840_MASK)
/*! @} */

/*! @name LDPRR22D - ldprofilereg22d */
/*! @{ */

#define locald44_LDPRR22D_lumd843_MASK           (0x3FFU)
#define locald44_LDPRR22D_lumd843_SHIFT          (0U)
/*! lumd843 - lumdat_843 */
#define locald44_LDPRR22D_lumd843(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22D_lumd843_SHIFT)) & locald44_LDPRR22D_lumd843_MASK)

#define locald44_LDPRR22D_lumd842_MASK           (0x3FF0000U)
#define locald44_LDPRR22D_lumd842_SHIFT          (16U)
/*! lumd842 - lumdat_842 */
#define locald44_LDPRR22D_lumd842(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22D_lumd842_SHIFT)) & locald44_LDPRR22D_lumd842_MASK)
/*! @} */

/*! @name LDPRR22E - ldprofilereg22e */
/*! @{ */

#define locald44_LDPRR22E_lumd845_MASK           (0x3FFU)
#define locald44_LDPRR22E_lumd845_SHIFT          (0U)
/*! lumd845 - lumdat_845 */
#define locald44_LDPRR22E_lumd845(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22E_lumd845_SHIFT)) & locald44_LDPRR22E_lumd845_MASK)

#define locald44_LDPRR22E_lumd844_MASK           (0x3FF0000U)
#define locald44_LDPRR22E_lumd844_SHIFT          (16U)
/*! lumd844 - lumdat_844 */
#define locald44_LDPRR22E_lumd844(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22E_lumd844_SHIFT)) & locald44_LDPRR22E_lumd844_MASK)
/*! @} */

/*! @name LDPRR22F - ldprofilereg22f */
/*! @{ */

#define locald44_LDPRR22F_lumd847_MASK           (0x3FFU)
#define locald44_LDPRR22F_lumd847_SHIFT          (0U)
/*! lumd847 - lumdat_847 */
#define locald44_LDPRR22F_lumd847(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22F_lumd847_SHIFT)) & locald44_LDPRR22F_lumd847_MASK)

#define locald44_LDPRR22F_lumd846_MASK           (0x3FF0000U)
#define locald44_LDPRR22F_lumd846_SHIFT          (16U)
/*! lumd846 - lumdat_846 */
#define locald44_LDPRR22F_lumd846(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR22F_lumd846_SHIFT)) & locald44_LDPRR22F_lumd846_MASK)
/*! @} */

/*! @name LDPRR230 - ldprofilereg230 */
/*! @{ */

#define locald44_LDPRR230_lumd849_MASK           (0x3FFU)
#define locald44_LDPRR230_lumd849_SHIFT          (0U)
/*! lumd849 - lumdat_849 */
#define locald44_LDPRR230_lumd849(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR230_lumd849_SHIFT)) & locald44_LDPRR230_lumd849_MASK)

#define locald44_LDPRR230_lumd848_MASK           (0x3FF0000U)
#define locald44_LDPRR230_lumd848_SHIFT          (16U)
/*! lumd848 - lumdat_848 */
#define locald44_LDPRR230_lumd848(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR230_lumd848_SHIFT)) & locald44_LDPRR230_lumd848_MASK)
/*! @} */

/*! @name LDPRR231 - ldprofilereg231 */
/*! @{ */

#define locald44_LDPRR231_lumd851_MASK           (0x3FFU)
#define locald44_LDPRR231_lumd851_SHIFT          (0U)
/*! lumd851 - lumdat_851 */
#define locald44_LDPRR231_lumd851(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR231_lumd851_SHIFT)) & locald44_LDPRR231_lumd851_MASK)

#define locald44_LDPRR231_lumd850_MASK           (0x3FF0000U)
#define locald44_LDPRR231_lumd850_SHIFT          (16U)
/*! lumd850 - lumdat_850 */
#define locald44_LDPRR231_lumd850(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR231_lumd850_SHIFT)) & locald44_LDPRR231_lumd850_MASK)
/*! @} */

/*! @name LDPRR232 - ldprofilereg232 */
/*! @{ */

#define locald44_LDPRR232_lumd853_MASK           (0x3FFU)
#define locald44_LDPRR232_lumd853_SHIFT          (0U)
/*! lumd853 - lumdat_853 */
#define locald44_LDPRR232_lumd853(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR232_lumd853_SHIFT)) & locald44_LDPRR232_lumd853_MASK)

#define locald44_LDPRR232_lumd852_MASK           (0x3FF0000U)
#define locald44_LDPRR232_lumd852_SHIFT          (16U)
/*! lumd852 - lumdat_852 */
#define locald44_LDPRR232_lumd852(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR232_lumd852_SHIFT)) & locald44_LDPRR232_lumd852_MASK)
/*! @} */

/*! @name LDPRR233 - ldprofilereg233 */
/*! @{ */

#define locald44_LDPRR233_lumd855_MASK           (0x3FFU)
#define locald44_LDPRR233_lumd855_SHIFT          (0U)
/*! lumd855 - lumdat_855 */
#define locald44_LDPRR233_lumd855(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR233_lumd855_SHIFT)) & locald44_LDPRR233_lumd855_MASK)

#define locald44_LDPRR233_lumd854_MASK           (0x3FF0000U)
#define locald44_LDPRR233_lumd854_SHIFT          (16U)
/*! lumd854 - lumdat_854 */
#define locald44_LDPRR233_lumd854(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR233_lumd854_SHIFT)) & locald44_LDPRR233_lumd854_MASK)
/*! @} */

/*! @name LDPRR234 - ldprofilereg234 */
/*! @{ */

#define locald44_LDPRR234_lumd857_MASK           (0x3FFU)
#define locald44_LDPRR234_lumd857_SHIFT          (0U)
/*! lumd857 - lumdat_857 */
#define locald44_LDPRR234_lumd857(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR234_lumd857_SHIFT)) & locald44_LDPRR234_lumd857_MASK)

#define locald44_LDPRR234_lumd856_MASK           (0x3FF0000U)
#define locald44_LDPRR234_lumd856_SHIFT          (16U)
/*! lumd856 - lumdat_856 */
#define locald44_LDPRR234_lumd856(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR234_lumd856_SHIFT)) & locald44_LDPRR234_lumd856_MASK)
/*! @} */

/*! @name LDPRR235 - ldprofilereg235 */
/*! @{ */

#define locald44_LDPRR235_lumd859_MASK           (0x3FFU)
#define locald44_LDPRR235_lumd859_SHIFT          (0U)
/*! lumd859 - lumdat_859 */
#define locald44_LDPRR235_lumd859(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR235_lumd859_SHIFT)) & locald44_LDPRR235_lumd859_MASK)

#define locald44_LDPRR235_lumd858_MASK           (0x3FF0000U)
#define locald44_LDPRR235_lumd858_SHIFT          (16U)
/*! lumd858 - lumdat_858 */
#define locald44_LDPRR235_lumd858(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR235_lumd858_SHIFT)) & locald44_LDPRR235_lumd858_MASK)
/*! @} */

/*! @name LDPRR236 - ldprofilereg236 */
/*! @{ */

#define locald44_LDPRR236_lumd861_MASK           (0x3FFU)
#define locald44_LDPRR236_lumd861_SHIFT          (0U)
/*! lumd861 - lumdat_861 */
#define locald44_LDPRR236_lumd861(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR236_lumd861_SHIFT)) & locald44_LDPRR236_lumd861_MASK)

#define locald44_LDPRR236_lumd860_MASK           (0x3FF0000U)
#define locald44_LDPRR236_lumd860_SHIFT          (16U)
/*! lumd860 - lumdat_860 */
#define locald44_LDPRR236_lumd860(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR236_lumd860_SHIFT)) & locald44_LDPRR236_lumd860_MASK)
/*! @} */

/*! @name LDPRR237 - ldprofilereg237 */
/*! @{ */

#define locald44_LDPRR237_lumd863_MASK           (0x3FFU)
#define locald44_LDPRR237_lumd863_SHIFT          (0U)
/*! lumd863 - lumdat_863 */
#define locald44_LDPRR237_lumd863(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR237_lumd863_SHIFT)) & locald44_LDPRR237_lumd863_MASK)

#define locald44_LDPRR237_lumd862_MASK           (0x3FF0000U)
#define locald44_LDPRR237_lumd862_SHIFT          (16U)
/*! lumd862 - lumdat_862 */
#define locald44_LDPRR237_lumd862(x)             (((uint32_t)(((uint32_t)(x)) << locald44_LDPRR237_lumd862_SHIFT)) & locald44_LDPRR237_lumd862_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald44_Register_Masks */


/*!
 * @}
 */ /* end of group locald44_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD44_H_ */

