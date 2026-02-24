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
**         CMSIS Peripheral Access Layer for locald10
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
 * @file PERI_locald10.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald10
 *
 * CMSIS Peripheral Access Layer for locald10
 */

#if !defined(PERI_LOCALD10_H_)
#define PERI_LOCALD10_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald10 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald10_Peripheral_Access_Layer locald10 Peripheral Access Layer
 * @{
 */

/** locald10 - Register Layout Typedef */
typedef struct {
  __I  uint32_t LDFRD000;                          /**< ldhifread000, offset: 0x0 */
  __I  uint32_t LDFRD001;                          /**< ldhifread001, offset: 0x4 */
  __I  uint32_t LDFRD002;                          /**< ldhifread002, offset: 0x8 */
  __I  uint32_t LDFRD003;                          /**< ldhifread003, offset: 0xC */
  __I  uint32_t LDFRD004;                          /**< ldhifread004, offset: 0x10 */
  __I  uint32_t LDFRD005;                          /**< ldhifread005, offset: 0x14 */
  __I  uint32_t LDFRD006;                          /**< ldhifread006, offset: 0x18 */
  __I  uint32_t LDFRD007;                          /**< ldhifread007, offset: 0x1C */
  __I  uint32_t LDFRD008;                          /**< ldhifread008, offset: 0x20 */
  __I  uint32_t LDFRD009;                          /**< ldhifread009, offset: 0x24 */
} locald10_Type;

/* ----------------------------------------------------------------------------
   -- locald10 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald10_Register_Masks locald10 Register Masks
 * @{
 */

/*! @name LDFRD000 - ldhifread000 */
/*! @{ */

#define locald10_LDFRD000_minorver_MASK          (0xFFU)
#define locald10_LDFRD000_minorver_SHIFT         (0U)
/*! minorver - minorversion */
#define locald10_LDFRD000_minorver(x)            (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD000_minorver_SHIFT)) & locald10_LDFRD000_minorver_MASK)

#define locald10_LDFRD000_majorver_MASK          (0xFF00U)
#define locald10_LDFRD000_majorver_SHIFT         (8U)
/*! majorver - majorversion */
#define locald10_LDFRD000_majorver(x)            (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD000_majorver_SHIFT)) & locald10_LDFRD000_majorver_MASK)

#define locald10_LDFRD000_socvers_MASK           (0xFF0000U)
#define locald10_LDFRD000_socvers_SHIFT          (16U)
/*! socvers - socversion */
#define locald10_LDFRD000_socvers(x)             (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD000_socvers_SHIFT)) & locald10_LDFRD000_socvers_MASK)
/*! @} */

/*! @name LDFRD001 - ldhifread001 */
/*! @{ */

#define locald10_LDFRD001_apl1vr_MASK            (0xFFFU)
#define locald10_LDFRD001_apl1vr_SHIFT           (0U)
/*! apl1vr - apl1vr */
#define locald10_LDFRD001_apl1vr(x)              (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD001_apl1vr_SHIFT)) & locald10_LDFRD001_apl1vr_MASK)

#define locald10_LDFRD001_apl0vr_MASK            (0xFFF0000U)
#define locald10_LDFRD001_apl0vr_SHIFT           (16U)
/*! apl0vr - apl0vr */
#define locald10_LDFRD001_apl0vr(x)              (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD001_apl0vr_SHIFT)) & locald10_LDFRD001_apl0vr_MASK)
/*! @} */

/*! @name LDFRD002 - ldhifread002 */
/*! @{ */

#define locald10_LDFRD002_maxlvf_MASK            (0xFFFFFFU)
#define locald10_LDFRD002_maxlvf_SHIFT           (0U)
/*! maxlvf - maxlvf */
#define locald10_LDFRD002_maxlvf(x)              (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD002_maxlvf_SHIFT)) & locald10_LDFRD002_maxlvf_MASK)
/*! @} */

/*! @name LDFRD003 - ldhifread003 */
/*! @{ */

#define locald10_LDFRD003_sgain_MASK             (0x1FFFFFFU)
#define locald10_LDFRD003_sgain_SHIFT            (0U)
/*! sgain - sgain */
#define locald10_LDFRD003_sgain(x)               (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD003_sgain_SHIFT)) & locald10_LDFRD003_sgain_MASK)
/*! @} */

/*! @name LDFRD004 - ldhifread004 */
/*! @{ */

#define locald10_LDFRD004_maxcnt_MASK            (0xFFFFFFFFU)
#define locald10_LDFRD004_maxcnt_SHIFT           (0U)
/*! maxcnt - maxcnt */
#define locald10_LDFRD004_maxcnt(x)              (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD004_maxcnt_SHIFT)) & locald10_LDFRD004_maxcnt_MASK)
/*! @} */

/*! @name LDFRD005 - ldhifread005 */
/*! @{ */

#define locald10_LDFRD005_pcnt_MASK              (0xFFFFFFU)
#define locald10_LDFRD005_pcnt_SHIFT             (0U)
/*! pcnt - pcnt */
#define locald10_LDFRD005_pcnt(x)                (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD005_pcnt_SHIFT)) & locald10_LDFRD005_pcnt_MASK)
/*! @} */

/*! @name LDFRD006 - ldhifread006 */
/*! @{ */

#define locald10_LDFRD006_gopr_MASK              (0xFFFU)
#define locald10_LDFRD006_gopr_SHIFT             (0U)
/*! gopr - gopr */
#define locald10_LDFRD006_gopr(x)                (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD006_gopr_SHIFT)) & locald10_LDFRD006_gopr_MASK)
/*! @} */

/*! @name LDFRD007 - ldhifread007 */
/*! @{ */

#define locald10_LDFRD007_satesum_MASK           (0xFFFFFFU)
#define locald10_LDFRD007_satesum_SHIFT          (0U)
/*! satesum - satesum */
#define locald10_LDFRD007_satesum(x)             (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD007_satesum_SHIFT)) & locald10_LDFRD007_satesum_MASK)

#define locald10_LDFRD007_satcmp_MASK            (0x10000000U)
#define locald10_LDFRD007_satcmp_SHIFT           (28U)
/*! satcmp - satcmp */
#define locald10_LDFRD007_satcmp(x)              (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD007_satcmp_SHIFT)) & locald10_LDFRD007_satcmp_MASK)
/*! @} */

/*! @name LDFRD008 - ldhifread008 */
/*! @{ */

#define locald10_LDFRD008_blrchks_MASK           (0xFFFFU)
#define locald10_LDFRD008_blrchks_SHIFT          (0U)
/*! blrchks - blrchksum */
#define locald10_LDFRD008_blrchks(x)             (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD008_blrchks_SHIFT)) & locald10_LDFRD008_blrchks_MASK)

#define locald10_LDFRD008_blrcrc_MASK            (0xFFFF0000U)
#define locald10_LDFRD008_blrcrc_SHIFT           (16U)
/*! blrcrc - blrcrc */
#define locald10_LDFRD008_blrcrc(x)              (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD008_blrcrc_SHIFT)) & locald10_LDFRD008_blrcrc_MASK)
/*! @} */

/*! @name LDFRD009 - ldhifread009 */
/*! @{ */

#define locald10_LDFRD009_bkrater_MASK           (0xFFFU)
#define locald10_LDFRD009_bkrater_SHIFT          (0U)
/*! bkrater - bkrater */
#define locald10_LDFRD009_bkrater(x)             (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD009_bkrater_SHIFT)) & locald10_LDFRD009_bkrater_MASK)

#define locald10_LDFRD009_maxdiffr_MASK          (0xFFF0000U)
#define locald10_LDFRD009_maxdiffr_SHIFT         (16U)
/*! maxdiffr - maxdiffr */
#define locald10_LDFRD009_maxdiffr(x)            (((uint32_t)(((uint32_t)(x)) << locald10_LDFRD009_maxdiffr_SHIFT)) & locald10_LDFRD009_maxdiffr_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald10_Register_Masks */


/*!
 * @}
 */ /* end of group locald10_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD10_H_ */

