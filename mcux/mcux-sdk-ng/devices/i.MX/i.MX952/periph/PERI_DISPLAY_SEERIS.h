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
**         CMSIS Peripheral Access Layer for DISPLAY_SEERIS
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
 * @file PERI_DISPLAY_SEERIS.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DISPLAY_SEERIS
 *
 * CMSIS Peripheral Access Layer for DISPLAY_SEERIS
 */

#if !defined(PERI_DISPLAY_SEERIS_H_)
#define PERI_DISPLAY_SEERIS_H_                   /**< Symbol preventing repeated inclusion */

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
   -- DISPLAY_SEERIS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_SEERIS_Peripheral_Access_Layer DISPLAY_SEERIS Peripheral Access Layer
 * @{
 */

/** DISPLAY_SEERIS - Register Layout Typedef */
typedef struct {
  __IO uint32_t IPIDENT;                           /**< IPIdentifier, offset: 0x0 */
} DISPLAY_SEERIS_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_SEERIS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_SEERIS_Register_Masks DISPLAY_SEERIS Register Masks
 * @{
 */

/*! @name IPIDENT - IPIdentifier */
/*! @{ */

#define DISPLAY_SEERIS_IPIDENT_DesDeID_MASK      (0xF0U)
#define DISPLAY_SEERIS_IPIDENT_DesDeID_SHIFT     (4U)
/*! DesDeID - DesignDeliveryID */
#define DISPLAY_SEERIS_IPIDENT_DesDeID(x)        (((uint32_t)(((uint32_t)(x)) << DISPLAY_SEERIS_IPIDENT_DesDeID_SHIFT)) & DISPLAY_SEERIS_IPIDENT_DesDeID_MASK)

#define DISPLAY_SEERIS_IPIDENT_DesMaLe_MASK      (0xF00U)
#define DISPLAY_SEERIS_IPIDENT_DesMaLe_SHIFT     (8U)
/*! DesMaLe - DesignMaturityLevel
 *  0b0001..Pre feasibility study.
 *  0b0010..Feasibility study.
 *  0b0011..Functionality complete.
 *  0b0100..Verification complete.
 */
#define DISPLAY_SEERIS_IPIDENT_DesMaLe(x)        (((uint32_t)(((uint32_t)(x)) << DISPLAY_SEERIS_IPIDENT_DesMaLe_SHIFT)) & DISPLAY_SEERIS_IPIDENT_DesMaLe_MASK)

#define DISPLAY_SEERIS_IPIDENT_IPEvol_MASK       (0x7000U)
#define DISPLAY_SEERIS_IPIDENT_IPEvol_SHIFT      (12U)
/*! IPEvol - IPEvolution
 *  0b000..MDR5
 *  0b001..MDR7
 */
#define DISPLAY_SEERIS_IPIDENT_IPEvol(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_SEERIS_IPIDENT_IPEvol_SHIFT)) & DISPLAY_SEERIS_IPIDENT_IPEvol_MASK)

#define DISPLAY_SEERIS_IPIDENT_LD_MASK           (0x8000U)
#define DISPLAY_SEERIS_IPIDENT_LD_SHIFT          (15U)
/*! LD - LD
 *  0b0..Local Dimming endabled
 *  0b1..Local Dimming disabled
 */
#define DISPLAY_SEERIS_IPIDENT_LD(x)             (((uint32_t)(((uint32_t)(x)) << DISPLAY_SEERIS_IPIDENT_LD_SHIFT)) & DISPLAY_SEERIS_IPIDENT_LD_MASK)

#define DISPLAY_SEERIS_IPIDENT_IPFeatuS_MASK     (0xF0000U)
#define DISPLAY_SEERIS_IPIDENT_IPFeatuS_SHIFT    (16U)
/*! IPFeatuS - IPFeatureSet
 *  0b0001..Minimal functionality (Eco).
 *  0b0010..Reduced functionality (Light).
 *  0b0100..Advanced functionality (Plus).
 *  0b0101..Extensive functionality (eXtensive).
 *  0b0110..Standard functionality (Regular).
 */
#define DISPLAY_SEERIS_IPIDENT_IPFeatuS(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_SEERIS_IPIDENT_IPFeatuS_SHIFT)) & DISPLAY_SEERIS_IPIDENT_IPFeatuS_MASK)

#define DISPLAY_SEERIS_IPIDENT_IPAppl_MASK       (0xF00000U)
#define DISPLAY_SEERIS_IPIDENT_IPAppl_SHIFT      (20U)
/*! IPAppl - IPApplication
 *  0b0001..Blit Engine only.
 *  0b0010..Blit Engine and Display Controller.
 *  0b0011..Display Controller only (with direct capture).
 *  0b0100..Blit Engine, Display Controller (with direct capture), Capture Controller (buffered capture) and Drawing Engine.
 *  0b0101..Display Controller only.
 *  0b0110..Capture Controller only.
 */
#define DISPLAY_SEERIS_IPIDENT_IPAppl(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_SEERIS_IPIDENT_IPAppl_SHIFT)) & DISPLAY_SEERIS_IPIDENT_IPAppl_MASK)

#define DISPLAY_SEERIS_IPIDENT_IPConf_MASK       (0xF000000U)
#define DISPLAY_SEERIS_IPIDENT_IPConf_SHIFT      (24U)
/*! IPConf - IPConfiguration
 *  0b0001..Graphics core only (Module).
 *  0b0010..Subsystem including a graphics core (System).
 */
#define DISPLAY_SEERIS_IPIDENT_IPConf(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_SEERIS_IPIDENT_IPConf_SHIFT)) & DISPLAY_SEERIS_IPIDENT_IPConf_MASK)

#define DISPLAY_SEERIS_IPIDENT_IPFamily_MASK     (0xF0000000U)
#define DISPLAY_SEERIS_IPIDENT_IPFamily_SHIFT    (28U)
/*! IPFamily - IPFamily
 *  0b0000..SEERIS building block generation 2010.
 *  0b0001..SEERIS building block generation 2012.
 *  0b0010..SEERIS building block generation 2013.
 */
#define DISPLAY_SEERIS_IPIDENT_IPFamily(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_SEERIS_IPIDENT_IPFamily_SHIFT)) & DISPLAY_SEERIS_IPIDENT_IPFamily_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DISPLAY_SEERIS_Register_Masks */


/*!
 * @}
 */ /* end of group DISPLAY_SEERIS_Peripheral_Access_Layer */


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


#endif  /* PERI_DISPLAY_SEERIS_H_ */

