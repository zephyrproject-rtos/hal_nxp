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
**         CMSIS Peripheral Access Layer for fetche14
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
 * @file PERI_fetche14.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetche14
 *
 * CMSIS Peripheral Access Layer for fetche14
 */

#if !defined(PERI_FETCHE14_H_)
#define PERI_FETCHE14_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetche14 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetche14_Peripheral_Access_Layer fetche14 Peripheral Access Layer
 * @{
 */

/** fetche14 - Register Layout Typedef */
typedef struct {
  __I  uint32_t CURBA0;                            /**< CurBaseAddress0, offset: 0x0 */
  __I  uint32_t CURBAMS0;                          /**< CurBaseAddressMSB0, offset: 0x4 */
  __I  uint32_t HIDSTA;                            /**< HiddenStatus, offset: 0x8 */
} fetche14_Type;

/* ----------------------------------------------------------------------------
   -- fetche14 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetche14_Register_Masks fetche14 Register Masks
 * @{
 */

/*! @name CURBA0 - CurBaseAddress0 */
/*! @{ */

#define fetche14_CURBA0_CurBA0_MASK              (0xFFFFFFFFU)
#define fetche14_CURBA0_CurBA0_SHIFT             (0U)
/*! CurBA0 - CurBaseAddress0 */
#define fetche14_CURBA0_CurBA0(x)                (((uint32_t)(((uint32_t)(x)) << fetche14_CURBA0_CurBA0_SHIFT)) & fetche14_CURBA0_CurBA0_MASK)
/*! @} */

/*! @name CURBAMS0 - CurBaseAddressMSB0 */
/*! @{ */

#define fetche14_CURBAMS0_CurBAMS0_MASK          (0xFFU)
#define fetche14_CURBAMS0_CurBAMS0_SHIFT         (0U)
/*! CurBAMS0 - CurBaseAddressMSB0 */
#define fetche14_CURBAMS0_CurBAMS0(x)            (((uint32_t)(((uint32_t)(x)) << fetche14_CURBAMS0_CurBAMS0_SHIFT)) & fetche14_CURBAMS0_CurBAMS0_MASK)
/*! @} */

/*! @name HIDSTA - HiddenStatus */
/*! @{ */

#define fetche14_HIDSTA_StBusy_MASK              (0x1U)
#define fetche14_HIDSTA_StBusy_SHIFT             (0U)
/*! StBusy - StatusBusy */
#define fetche14_HIDSTA_StBusy(x)                (((uint32_t)(((uint32_t)(x)) << fetche14_HIDSTA_StBusy_SHIFT)) & fetche14_HIDSTA_StBusy_MASK)

#define fetche14_HIDSTA_StBuIdle_MASK            (0x10U)
#define fetche14_HIDSTA_StBuIdle_SHIFT           (4U)
/*! StBuIdle - StatusBuffersIdle */
#define fetche14_HIDSTA_StBuIdle(x)              (((uint32_t)(((uint32_t)(x)) << fetche14_HIDSTA_StBuIdle_SHIFT)) & fetche14_HIDSTA_StBuIdle_MASK)

#define fetche14_HIDSTA_StReq_MASK               (0x20U)
#define fetche14_HIDSTA_StReq_SHIFT              (5U)
/*! StReq - StatusRequest */
#define fetche14_HIDSTA_StReq(x)                 (((uint32_t)(((uint32_t)(x)) << fetche14_HIDSTA_StReq_SHIFT)) & fetche14_HIDSTA_StReq_MASK)

#define fetche14_HIDSTA_StCom_MASK               (0x40U)
#define fetche14_HIDSTA_StCom_SHIFT              (6U)
/*! StCom - StatusComplete */
#define fetche14_HIDSTA_StCom(x)                 (((uint32_t)(((uint32_t)(x)) << fetche14_HIDSTA_StCom_SHIFT)) & fetche14_HIDSTA_StCom_MASK)

#define fetche14_HIDSTA_ShadowS0_MASK            (0x100U)
#define fetche14_HIDSTA_ShadowS0_SHIFT           (8U)
/*! ShadowS0 - ShadowStatus0 */
#define fetche14_HIDSTA_ShadowS0(x)              (((uint32_t)(((uint32_t)(x)) << fetche14_HIDSTA_ShadowS0_SHIFT)) & fetche14_HIDSTA_ShadowS0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetche14_Register_Masks */


/*!
 * @}
 */ /* end of group fetche14_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHE14_H_ */

