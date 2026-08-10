/*
** ###################################################################
**     Processors:          MIMX9371xxVTx_ca55
**                          MIMX9371xxVTx_cm33
**                          MIMX9371xxVTx_cm7
**                          MIMX9373xxVTx_ca55
**                          MIMX9373xxVTx_cm33
**                          MIMX9373xxVTx_cm7
**                          MIMX9373xxVZx_ca55
**                          MIMX9373xxVZx_cm33
**                          MIMX9373xxVZx_cm7
**                          MIMX9375xxVTx_ca55
**                          MIMX9375xxVTx_cm33
**                          MIMX9375xxVTx_cm7
**                          MIMX9375xxVZx_ca55
**                          MIMX9375xxVZx_cm33
**                          MIMX9375xxVZx_cm7
**
**     Version:             rev. 1.0, 2026-04-09
**     Build:               b260624
**
**     Abstract:
**         CMSIS Peripheral Access Layer for fetchyu4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026-04-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_fetchyu4.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for fetchyu4
 *
 * CMSIS Peripheral Access Layer for fetchyu4
 */

#if !defined(PERI_FETCHYU4_H_)
#define PERI_FETCHYU4_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9371xxVTx_ca55))
#include "MIMX9371_ca55_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm33))
#include "MIMX9371_cm33_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm7))
#include "MIMX9371_cm7_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_ca55) || defined(CPU_MIMX9373xxVZx_ca55))
#include "MIMX9373_ca55_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm33) || defined(CPU_MIMX9373xxVZx_cm33))
#include "MIMX9373_cm33_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm7) || defined(CPU_MIMX9373xxVZx_cm7))
#include "MIMX9373_cm7_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_ca55) || defined(CPU_MIMX9375xxVZx_ca55))
#include "MIMX9375_ca55_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm33) || defined(CPU_MIMX9375xxVZx_cm33))
#include "MIMX9375_cm33_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm7) || defined(CPU_MIMX9375xxVZx_cm7))
#include "MIMX9375_cm7_COMMON.h"
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
   -- fetchyu4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchyu4_Peripheral_Access_Layer fetchyu4 Peripheral Access Layer
 * @{
 */

/** fetchyu4 - Register Layout Typedef */
typedef struct {
  __I  uint32_t CURBA0;                            /**< CurBaseAddress0, offset: 0x0 */
  __I  uint32_t CURBAMS0;                          /**< CurBaseAddressMSB0, offset: 0x4 */
  __I  uint32_t HIDSTA;                            /**< HiddenStatus, offset: 0x8 */
} fetchyu4_Type;

/* ----------------------------------------------------------------------------
   -- fetchyu4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchyu4_Register_Masks fetchyu4 Register Masks
 * @{
 */

/*! @name CURBA0 - CurBaseAddress0 */
/*! @{ */

#define fetchyu4_CURBA0_CurBA0_MASK              (0xFFFFFFFFU)
#define fetchyu4_CURBA0_CurBA0_SHIFT             (0U)
/*! CurBA0 - CurBaseAddress0 */
#define fetchyu4_CURBA0_CurBA0(x)                (((uint32_t)(((uint32_t)(x)) << fetchyu4_CURBA0_CurBA0_SHIFT)) & fetchyu4_CURBA0_CurBA0_MASK)
/*! @} */

/*! @name CURBAMS0 - CurBaseAddressMSB0 */
/*! @{ */

#define fetchyu4_CURBAMS0_CurBAMS0_MASK          (0xFFU)
#define fetchyu4_CURBAMS0_CurBAMS0_SHIFT         (0U)
/*! CurBAMS0 - CurBaseAddressMSB0 */
#define fetchyu4_CURBAMS0_CurBAMS0(x)            (((uint32_t)(((uint32_t)(x)) << fetchyu4_CURBAMS0_CurBAMS0_SHIFT)) & fetchyu4_CURBAMS0_CurBAMS0_MASK)
/*! @} */

/*! @name HIDSTA - HiddenStatus */
/*! @{ */

#define fetchyu4_HIDSTA_StBusy_MASK              (0x1U)
#define fetchyu4_HIDSTA_StBusy_SHIFT             (0U)
/*! StBusy - StatusBusy */
#define fetchyu4_HIDSTA_StBusy(x)                (((uint32_t)(((uint32_t)(x)) << fetchyu4_HIDSTA_StBusy_SHIFT)) & fetchyu4_HIDSTA_StBusy_MASK)

#define fetchyu4_HIDSTA_StBuIdle_MASK            (0x10U)
#define fetchyu4_HIDSTA_StBuIdle_SHIFT           (4U)
/*! StBuIdle - StatusBuffersIdle */
#define fetchyu4_HIDSTA_StBuIdle(x)              (((uint32_t)(((uint32_t)(x)) << fetchyu4_HIDSTA_StBuIdle_SHIFT)) & fetchyu4_HIDSTA_StBuIdle_MASK)

#define fetchyu4_HIDSTA_StReq_MASK               (0x20U)
#define fetchyu4_HIDSTA_StReq_SHIFT              (5U)
/*! StReq - StatusRequest */
#define fetchyu4_HIDSTA_StReq(x)                 (((uint32_t)(((uint32_t)(x)) << fetchyu4_HIDSTA_StReq_SHIFT)) & fetchyu4_HIDSTA_StReq_MASK)

#define fetchyu4_HIDSTA_StCom_MASK               (0x40U)
#define fetchyu4_HIDSTA_StCom_SHIFT              (6U)
/*! StCom - StatusComplete */
#define fetchyu4_HIDSTA_StCom(x)                 (((uint32_t)(((uint32_t)(x)) << fetchyu4_HIDSTA_StCom_SHIFT)) & fetchyu4_HIDSTA_StCom_MASK)

#define fetchyu4_HIDSTA_ShadowS0_MASK            (0x100U)
#define fetchyu4_HIDSTA_ShadowS0_SHIFT           (8U)
/*! ShadowS0 - ShadowStatus0 */
#define fetchyu4_HIDSTA_ShadowS0(x)              (((uint32_t)(((uint32_t)(x)) << fetchyu4_HIDSTA_ShadowS0_SHIFT)) & fetchyu4_HIDSTA_ShadowS0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchyu4_Register_Masks */


/*!
 * @}
 */ /* end of group fetchyu4_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHYU4_H_ */

