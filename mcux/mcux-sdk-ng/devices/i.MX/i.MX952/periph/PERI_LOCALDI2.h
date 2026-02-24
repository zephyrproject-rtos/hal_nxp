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
**         CMSIS Peripheral Access Layer for localdi2
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
 * @file PERI_localdi2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for localdi2
 *
 * CMSIS Peripheral Access Layer for localdi2
 */

#if !defined(PERI_LOCALDI2_H_)
#define PERI_LOCALDI2_H_                         /**< Symbol preventing repeated inclusion */

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
   -- localdi2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi2_Peripheral_Access_Layer localdi2 Peripheral Access Layer
 * @{
 */

/** localdi2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDFRG000;                          /**< ldhifreg000, offset: 0x0 */
  __IO uint32_t LDFRG001;                          /**< ldhifreg001, offset: 0x4 */
} localdi2_Type;

/* ----------------------------------------------------------------------------
   -- localdi2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup localdi2_Register_Masks localdi2 Register Masks
 * @{
 */

/*! @name LDFRG000 - ldhifreg000 */
/*! @{ */

#define localdi2_LDFRG000_ldon_MASK              (0x1U)
#define localdi2_LDFRG000_ldon_SHIFT             (0U)
/*! ldon - ldon */
#define localdi2_LDFRG000_ldon(x)                (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_ldon_SHIFT)) & localdi2_LDFRG000_ldon_MASK)

#define localdi2_LDFRG000_hlpfon_MASK            (0x10U)
#define localdi2_LDFRG000_hlpfon_SHIFT           (4U)
/*! hlpfon - hlpfon */
#define localdi2_LDFRG000_hlpfon(x)              (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_hlpfon_SHIFT)) & localdi2_LDFRG000_hlpfon_MASK)

#define localdi2_LDFRG000_sfon_MASK              (0x100U)
#define localdi2_LDFRG000_sfon_SHIFT             (8U)
/*! sfon - sfon */
#define localdi2_LDFRG000_sfon(x)                (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_sfon_SHIFT)) & localdi2_LDFRG000_sfon_MASK)

#define localdi2_LDFRG000_tfon_MASK              (0x400U)
#define localdi2_LDFRG000_tfon_SHIFT             (10U)
/*! tfon - tfon */
#define localdi2_LDFRG000_tfon(x)                (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_tfon_SHIFT)) & localdi2_LDFRG000_tfon_MASK)

#define localdi2_LDFRG000_bleoon_MASK            (0x10000U)
#define localdi2_LDFRG000_bleoon_SHIFT           (16U)
/*! bleoon - bleoon */
#define localdi2_LDFRG000_bleoon(x)              (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_bleoon_SHIFT)) & localdi2_LDFRG000_bleoon_MASK)

#define localdi2_LDFRG000_pwon_MASK              (0x20000U)
#define localdi2_LDFRG000_pwon_SHIFT             (17U)
/*! pwon - pwon */
#define localdi2_LDFRG000_pwon(x)                (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_pwon_SHIFT)) & localdi2_LDFRG000_pwon_MASK)

#define localdi2_LDFRG000_cntbrton_MASK          (0x40000U)
#define localdi2_LDFRG000_cntbrton_SHIFT         (18U)
/*! cntbrton - cntbrton */
#define localdi2_LDFRG000_cntbrton(x)            (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_cntbrton_SHIFT)) & localdi2_LDFRG000_cntbrton_MASK)

#define localdi2_LDFRG000_vaon_MASK              (0x80000U)
#define localdi2_LDFRG000_vaon_SHIFT             (19U)
/*! vaon - vaon */
#define localdi2_LDFRG000_vaon(x)                (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_vaon_SHIFT)) & localdi2_LDFRG000_vaon_MASK)

#define localdi2_LDFRG000_eoon_MASK              (0x1000000U)
#define localdi2_LDFRG000_eoon_SHIFT             (24U)
/*! eoon - eoon */
#define localdi2_LDFRG000_eoon(x)                (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_eoon_SHIFT)) & localdi2_LDFRG000_eoon_MASK)

#define localdi2_LDFRG000_psfon_MASK             (0x2000000U)
#define localdi2_LDFRG000_psfon_SHIFT            (25U)
/*! psfon - psfon */
#define localdi2_LDFRG000_psfon(x)               (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_psfon_SHIFT)) & localdi2_LDFRG000_psfon_MASK)

#define localdi2_LDFRG000_ooon_MASK              (0x4000000U)
#define localdi2_LDFRG000_ooon_SHIFT             (26U)
/*! ooon - ooon */
#define localdi2_LDFRG000_ooon(x)                (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_ooon_SHIFT)) & localdi2_LDFRG000_ooon_MASK)

#define localdi2_LDFRG000_oeon_MASK              (0x8000000U)
#define localdi2_LDFRG000_oeon_SHIFT             (27U)
/*! oeon - oeon */
#define localdi2_LDFRG000_oeon(x)                (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_oeon_SHIFT)) & localdi2_LDFRG000_oeon_MASK)

#define localdi2_LDFRG000_rgbunion_MASK          (0x10000000U)
#define localdi2_LDFRG000_rgbunion_SHIFT         (28U)
/*! rgbunion - rgbunion */
#define localdi2_LDFRG000_rgbunion(x)            (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG000_rgbunion_SHIFT)) & localdi2_LDFRG000_rgbunion_MASK)
/*! @} */

/*! @name LDFRG001 - ldhifreg001 */
/*! @{ */

#define localdi2_LDFRG001_ldpass_MASK            (0x10000U)
#define localdi2_LDFRG001_ldpass_SHIFT           (16U)
/*! ldpass - ldpass */
#define localdi2_LDFRG001_ldpass(x)              (((uint32_t)(((uint32_t)(x)) << localdi2_LDFRG001_ldpass_SHIFT)) & localdi2_LDFRG001_ldpass_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group localdi2_Register_Masks */


/*!
 * @}
 */ /* end of group localdi2_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALDI2_H_ */

