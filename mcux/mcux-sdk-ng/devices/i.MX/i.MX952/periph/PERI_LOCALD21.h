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
**         CMSIS Peripheral Access Layer for locald21
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
 * @file PERI_locald21.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald21
 *
 * CMSIS Peripheral Access Layer for locald21
 */

#if !defined(PERI_LOCALD21_H_)
#define PERI_LOCALD21_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald21 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald21_Peripheral_Access_Layer locald21 Peripheral Access Layer
 * @{
 */

/** locald21 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDRG011;                           /**< ldrgbreg011, offset: 0x0 */
  __IO uint32_t LDRG012;                           /**< ldrgbreg012, offset: 0x4 */
  __IO uint32_t LDRG013;                           /**< ldrgbreg013, offset: 0x8 */
  __IO uint32_t LDRG014;                           /**< ldrgbreg014, offset: 0xC */
  __IO uint32_t LDRG015;                           /**< ldrgbreg015, offset: 0x10 */
  __IO uint32_t LDRG016;                           /**< ldrgbreg016, offset: 0x14 */
  __IO uint32_t LDRG017;                           /**< ldrgbreg017, offset: 0x18 */
  __IO uint32_t LDRG018;                           /**< ldrgbreg018, offset: 0x1C */
  __IO uint32_t LDRG019;                           /**< ldrgbreg019, offset: 0x20 */
  __IO uint32_t LDRG01A;                           /**< ldrgbreg01a, offset: 0x24 */
  __IO uint32_t LDRG01B;                           /**< ldrgbreg01b, offset: 0x28 */
  __IO uint32_t LDRG01C;                           /**< ldrgbreg01c, offset: 0x2C */
} locald21_Type;

/* ----------------------------------------------------------------------------
   -- locald21 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald21_Register_Masks locald21 Register Masks
 * @{
 */

/*! @name LDRG011 - ldrgbreg011 */
/*! @{ */

#define locald21_LDRG011_vcomp_MASK              (0x1FFFFFFU)
#define locald21_LDRG011_vcomp_SHIFT             (0U)
/*! vcomp - vcomp */
#define locald21_LDRG011_vcomp(x)                (((uint32_t)(((uint32_t)(x)) << locald21_LDRG011_vcomp_SHIFT)) & locald21_LDRG011_vcomp_MASK)
/*! @} */

/*! @name LDRG012 - ldrgbreg012 */
/*! @{ */

#define locald21_LDRG012_py_MASK                 (0x3FFFFFFU)
#define locald21_LDRG012_py_SHIFT                (0U)
/*! py - py */
#define locald21_LDRG012_py(x)                   (((uint32_t)(((uint32_t)(x)) << locald21_LDRG012_py_SHIFT)) & locald21_LDRG012_py_MASK)
/*! @} */

/*! @name LDRG013 - ldrgbreg013 */
/*! @{ */

#define locald21_LDRG013_vstart_MASK             (0x1FFFU)
#define locald21_LDRG013_vstart_SHIFT            (0U)
/*! vstart - vstart */
#define locald21_LDRG013_vstart(x)               (((uint32_t)(((uint32_t)(x)) << locald21_LDRG013_vstart_SHIFT)) & locald21_LDRG013_vstart_MASK)

#define locald21_LDRG013_vsize_MASK              (0x1FFF0000U)
#define locald21_LDRG013_vsize_SHIFT             (16U)
/*! vsize - vsize */
#define locald21_LDRG013_vsize(x)                (((uint32_t)(((uint32_t)(x)) << locald21_LDRG013_vsize_SHIFT)) & locald21_LDRG013_vsize_MASK)
/*! @} */

/*! @name LDRG014 - ldrgbreg014 */
/*! @{ */

#define locald21_LDRG014_hcomp_MASK              (0x1FFFFFFU)
#define locald21_LDRG014_hcomp_SHIFT             (0U)
/*! hcomp - hcomp */
#define locald21_LDRG014_hcomp(x)                (((uint32_t)(((uint32_t)(x)) << locald21_LDRG014_hcomp_SHIFT)) & locald21_LDRG014_hcomp_MASK)
/*! @} */

/*! @name LDRG015 - ldrgbreg015 */
/*! @{ */

#define locald21_LDRG015_px_MASK                 (0x3FFFFFFU)
#define locald21_LDRG015_px_SHIFT                (0U)
/*! px - px */
#define locald21_LDRG015_px(x)                   (((uint32_t)(((uint32_t)(x)) << locald21_LDRG015_px_SHIFT)) & locald21_LDRG015_px_MASK)
/*! @} */

/*! @name LDRG016 - ldrgbreg016 */
/*! @{ */

#define locald21_LDRG016_hstart_MASK             (0x1FFFU)
#define locald21_LDRG016_hstart_SHIFT            (0U)
/*! hstart - hstart */
#define locald21_LDRG016_hstart(x)               (((uint32_t)(((uint32_t)(x)) << locald21_LDRG016_hstart_SHIFT)) & locald21_LDRG016_hstart_MASK)

#define locald21_LDRG016_hsize_MASK              (0x1FFF0000U)
#define locald21_LDRG016_hsize_SHIFT             (16U)
/*! hsize - hsize */
#define locald21_LDRG016_hsize(x)                (((uint32_t)(((uint32_t)(x)) << locald21_LDRG016_hsize_SHIFT)) & locald21_LDRG016_hsize_MASK)
/*! @} */

/*! @name LDRG017 - ldrgbreg017 */
/*! @{ */

#define locald21_LDRG017_hstarti_MASK            (0x1FFFU)
#define locald21_LDRG017_hstarti_SHIFT           (0U)
/*! hstarti - hstarti */
#define locald21_LDRG017_hstarti(x)              (((uint32_t)(((uint32_t)(x)) << locald21_LDRG017_hstarti_SHIFT)) & locald21_LDRG017_hstarti_MASK)

#define locald21_LDRG017_hsizei_MASK             (0x1FFF0000U)
#define locald21_LDRG017_hsizei_SHIFT            (16U)
/*! hsizei - hsizei */
#define locald21_LDRG017_hsizei(x)               (((uint32_t)(((uint32_t)(x)) << locald21_LDRG017_hsizei_SHIFT)) & locald21_LDRG017_hsizei_MASK)
/*! @} */

/*! @name LDRG018 - ldrgbreg018 */
/*! @{ */

#define locald21_LDRG018_pipe2mo_MASK            (0x8U)
#define locald21_LDRG018_pipe2mo_SHIFT           (3U)
/*! pipe2mo - pipe2mode */
#define locald21_LDRG018_pipe2mo(x)              (((uint32_t)(((uint32_t)(x)) << locald21_LDRG018_pipe2mo_SHIFT)) & locald21_LDRG018_pipe2mo_MASK)

#define locald21_LDRG018_psfrmod_MASK            (0x30U)
#define locald21_LDRG018_psfrmod_SHIFT           (4U)
/*! psfrmod - psframmode */
#define locald21_LDRG018_psfrmod(x)              (((uint32_t)(((uint32_t)(x)) << locald21_LDRG018_psfrmod_SHIFT)) & locald21_LDRG018_psfrmod_MASK)
/*! @} */

/*! @name LDRG019 - ldrgbreg019 */
/*! @{ */

#define locald21_LDRG019_core_MASK               (0xFFU)
#define locald21_LDRG019_core_SHIFT              (0U)
/*! core - core */
#define locald21_LDRG019_core(x)                 (((uint32_t)(((uint32_t)(x)) << locald21_LDRG019_core_SHIFT)) & locald21_LDRG019_core_MASK)

#define locald21_LDRG019_gainm_MASK              (0xFF00U)
#define locald21_LDRG019_gainm_SHIFT             (8U)
/*! gainm - gainm */
#define locald21_LDRG019_gainm(x)                (((uint32_t)(((uint32_t)(x)) << locald21_LDRG019_gainm_SHIFT)) & locald21_LDRG019_gainm_MASK)

#define locald21_LDRG019_gainp_MASK              (0xFF0000U)
#define locald21_LDRG019_gainp_SHIFT             (16U)
/*! gainp - gainp */
#define locald21_LDRG019_gainp(x)                (((uint32_t)(((uint32_t)(x)) << locald21_LDRG019_gainp_SHIFT)) & locald21_LDRG019_gainp_MASK)
/*! @} */

/*! @name LDRG01A - ldrgbreg01a */
/*! @{ */

#define locald21_LDRG01A_startm_MASK             (0xFFU)
#define locald21_LDRG01A_startm_SHIFT            (0U)
/*! startm - startm */
#define locald21_LDRG01A_startm(x)               (((uint32_t)(((uint32_t)(x)) << locald21_LDRG01A_startm_SHIFT)) & locald21_LDRG01A_startm_MASK)

#define locald21_LDRG01A_sgainm_MASK             (0xF00U)
#define locald21_LDRG01A_sgainm_SHIFT            (8U)
/*! sgainm - sgainm */
#define locald21_LDRG01A_sgainm(x)               (((uint32_t)(((uint32_t)(x)) << locald21_LDRG01A_sgainm_SHIFT)) & locald21_LDRG01A_sgainm_MASK)

#define locald21_LDRG01A_startp_MASK             (0xFF0000U)
#define locald21_LDRG01A_startp_SHIFT            (16U)
/*! startp - startp */
#define locald21_LDRG01A_startp(x)               (((uint32_t)(((uint32_t)(x)) << locald21_LDRG01A_startp_SHIFT)) & locald21_LDRG01A_startp_MASK)

#define locald21_LDRG01A_sgainp_MASK             (0xF000000U)
#define locald21_LDRG01A_sgainp_SHIFT            (24U)
/*! sgainp - sgainp */
#define locald21_LDRG01A_sgainp(x)               (((uint32_t)(((uint32_t)(x)) << locald21_LDRG01A_sgainp_SHIFT)) & locald21_LDRG01A_sgainp_MASK)
/*! @} */

/*! @name LDRG01B - ldrgbreg01b */
/*! @{ */

#define locald21_LDRG01B_rgblimil_MASK           (0xFFFFFFU)
#define locald21_LDRG01B_rgblimil_SHIFT          (0U)
/*! rgblimil - rgblimit_l */
#define locald21_LDRG01B_rgblimil(x)             (((uint32_t)(((uint32_t)(x)) << locald21_LDRG01B_rgblimil_SHIFT)) & locald21_LDRG01B_rgblimil_MASK)
/*! @} */

/*! @name LDRG01C - ldrgbreg01c */
/*! @{ */

#define locald21_LDRG01C_rgblimih_MASK           (0xFFFFFFU)
#define locald21_LDRG01C_rgblimih_SHIFT          (0U)
/*! rgblimih - rgblimit_h */
#define locald21_LDRG01C_rgblimih(x)             (((uint32_t)(((uint32_t)(x)) << locald21_LDRG01C_rgblimih_SHIFT)) & locald21_LDRG01C_rgblimih_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald21_Register_Masks */


/*!
 * @}
 */ /* end of group locald21_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD21_H_ */

