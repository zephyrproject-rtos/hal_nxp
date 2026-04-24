/*
** ###################################################################
**     Processors:          MIMX9522xxVTx_ca55
**                          MIMX9522xxVTx_cm33
**                          MIMX9522xxVTx_cm7
**                          MIMX9522xxVZx_ca55
**                          MIMX9522xxVZx_cm33
**                          MIMX9522xxVZx_cm7
**                          MIMX9523xxVTx_ca55
**                          MIMX9523xxVTx_cm33
**                          MIMX9523xxVTx_cm7
**                          MIMX9523xxVZx_ca55
**                          MIMX9523xxVZx_cm33
**                          MIMX9523xxVZx_cm7
**                          MIMX9524xxVTx_ca55
**                          MIMX9524xxVTx_cm33
**                          MIMX9524xxVTx_cm7
**                          MIMX9524xxVZx_ca55
**                          MIMX9524xxVZx_cm33
**                          MIMX9524xxVZx_cm7
**                          MIMX9525xxVTx_ca55
**                          MIMX9525xxVTx_cm33
**                          MIMX9525xxVTx_cm7
**                          MIMX9525xxVZx_ca55
**                          MIMX9525xxVZx_cm33
**                          MIMX9525xxVZx_cm7
**                          MIMX9528xxVTx_ca55
**                          MIMX9528xxVTx_cm33
**                          MIMX9528xxVTx_cm7
**                          MIMX9528xxVZx_ca55
**                          MIMX9528xxVZx_cm33
**                          MIMX9528xxVZx_cm7
**                          MIMX9529xxVTx_ca55
**                          MIMX9529xxVTx_cm33
**                          MIMX9529xxVTx_cm7
**                          MIMX9529xxVZx_ca55
**                          MIMX9529xxVZx_cm33
**                          MIMX9529xxVZx_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260324
**
**     Abstract:
**         CMSIS Peripheral Access Layer for fetchec4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
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
 * @file PERI_fetchec4.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for fetchec4
 *
 * CMSIS Peripheral Access Layer for fetchec4
 */

#if !defined(PERI_FETCHEC4_H_)
#define PERI_FETCHEC4_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9522xxVTx_ca55) || defined(CPU_MIMX9522xxVZx_ca55))
#include "MIMX9522_ca55_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm33) || defined(CPU_MIMX9522xxVZx_cm33))
#include "MIMX9522_cm33_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm7) || defined(CPU_MIMX9522xxVZx_cm7))
#include "MIMX9522_cm7_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_ca55) || defined(CPU_MIMX9523xxVZx_ca55))
#include "MIMX9523_ca55_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm33) || defined(CPU_MIMX9523xxVZx_cm33))
#include "MIMX9523_cm33_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm7) || defined(CPU_MIMX9523xxVZx_cm7))
#include "MIMX9523_cm7_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_ca55) || defined(CPU_MIMX9524xxVZx_ca55))
#include "MIMX9524_ca55_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm33) || defined(CPU_MIMX9524xxVZx_cm33))
#include "MIMX9524_cm33_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm7) || defined(CPU_MIMX9524xxVZx_cm7))
#include "MIMX9524_cm7_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_ca55) || defined(CPU_MIMX9525xxVZx_ca55))
#include "MIMX9525_ca55_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm33) || defined(CPU_MIMX9525xxVZx_cm33))
#include "MIMX9525_cm33_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm7) || defined(CPU_MIMX9525xxVZx_cm7))
#include "MIMX9525_cm7_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_ca55) || defined(CPU_MIMX9528xxVZx_ca55))
#include "MIMX9528_ca55_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm33) || defined(CPU_MIMX9528xxVZx_cm33))
#include "MIMX9528_cm33_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm7) || defined(CPU_MIMX9528xxVZx_cm7))
#include "MIMX9528_cm7_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_ca55) || defined(CPU_MIMX9529xxVZx_ca55))
#include "MIMX9529_ca55_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm33) || defined(CPU_MIMX9529xxVZx_cm33))
#include "MIMX9529_cm33_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm7) || defined(CPU_MIMX9529xxVZx_cm7))
#include "MIMX9529_cm7_COMMON.h"
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
   -- fetchec4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchec4_Peripheral_Access_Layer fetchec4 Peripheral Access Layer
 * @{
 */

/** fetchec4 - Register Layout Typedef */
typedef struct {
  __I  uint32_t CURBA0;                            /**< CurBaseAddress0, offset: 0x0 */
  __I  uint32_t CURBAMS0;                          /**< CurBaseAddressMSB0, offset: 0x4 */
  __I  uint32_t HIDSTA;                            /**< HiddenStatus, offset: 0x8 */
} fetchec4_Type;

/* ----------------------------------------------------------------------------
   -- fetchec4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchec4_Register_Masks fetchec4 Register Masks
 * @{
 */

/*! @name CURBA0 - CurBaseAddress0 */
/*! @{ */

#define fetchec4_CURBA0_CurBA0_MASK              (0xFFFFFFFFU)
#define fetchec4_CURBA0_CurBA0_SHIFT             (0U)
/*! CurBA0 - CurBaseAddress0 */
#define fetchec4_CURBA0_CurBA0(x)                (((uint32_t)(((uint32_t)(x)) << fetchec4_CURBA0_CurBA0_SHIFT)) & fetchec4_CURBA0_CurBA0_MASK)
/*! @} */

/*! @name CURBAMS0 - CurBaseAddressMSB0 */
/*! @{ */

#define fetchec4_CURBAMS0_CurBAMS0_MASK          (0xFFU)
#define fetchec4_CURBAMS0_CurBAMS0_SHIFT         (0U)
/*! CurBAMS0 - CurBaseAddressMSB0 */
#define fetchec4_CURBAMS0_CurBAMS0(x)            (((uint32_t)(((uint32_t)(x)) << fetchec4_CURBAMS0_CurBAMS0_SHIFT)) & fetchec4_CURBAMS0_CurBAMS0_MASK)
/*! @} */

/*! @name HIDSTA - HiddenStatus */
/*! @{ */

#define fetchec4_HIDSTA_StBusy_MASK              (0x1U)
#define fetchec4_HIDSTA_StBusy_SHIFT             (0U)
/*! StBusy - StatusBusy */
#define fetchec4_HIDSTA_StBusy(x)                (((uint32_t)(((uint32_t)(x)) << fetchec4_HIDSTA_StBusy_SHIFT)) & fetchec4_HIDSTA_StBusy_MASK)

#define fetchec4_HIDSTA_StBuIdle_MASK            (0x10U)
#define fetchec4_HIDSTA_StBuIdle_SHIFT           (4U)
/*! StBuIdle - StatusBuffersIdle */
#define fetchec4_HIDSTA_StBuIdle(x)              (((uint32_t)(((uint32_t)(x)) << fetchec4_HIDSTA_StBuIdle_SHIFT)) & fetchec4_HIDSTA_StBuIdle_MASK)

#define fetchec4_HIDSTA_StReq_MASK               (0x20U)
#define fetchec4_HIDSTA_StReq_SHIFT              (5U)
/*! StReq - StatusRequest */
#define fetchec4_HIDSTA_StReq(x)                 (((uint32_t)(((uint32_t)(x)) << fetchec4_HIDSTA_StReq_SHIFT)) & fetchec4_HIDSTA_StReq_MASK)

#define fetchec4_HIDSTA_StCom_MASK               (0x40U)
#define fetchec4_HIDSTA_StCom_SHIFT              (6U)
/*! StCom - StatusComplete */
#define fetchec4_HIDSTA_StCom(x)                 (((uint32_t)(((uint32_t)(x)) << fetchec4_HIDSTA_StCom_SHIFT)) & fetchec4_HIDSTA_StCom_MASK)

#define fetchec4_HIDSTA_ShadowS0_MASK            (0x100U)
#define fetchec4_HIDSTA_ShadowS0_SHIFT           (8U)
/*! ShadowS0 - ShadowStatus0 */
#define fetchec4_HIDSTA_ShadowS0(x)              (((uint32_t)(((uint32_t)(x)) << fetchec4_HIDSTA_ShadowS0_SHIFT)) & fetchec4_HIDSTA_ShadowS0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchec4_Register_Masks */


/*!
 * @}
 */ /* end of group fetchec4_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHEC4_H_ */

