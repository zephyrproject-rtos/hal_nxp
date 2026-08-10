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
**         CMSIS Peripheral Access Layer for fetchl10
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
 * @file PERI_fetchl10.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for fetchl10
 *
 * CMSIS Peripheral Access Layer for fetchl10
 */

#if !defined(PERI_FETCHL10_H_)
#define PERI_FETCHL10_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchl10 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl10_Peripheral_Access_Layer fetchl10 Peripheral Access Layer
 * @{
 */

/** fetchl10 - Register Layout Typedef */
typedef struct {
  __I  uint32_t BURBUFPR;                          /**< BurstBufferProperties, offset: 0x0 */
  __IO uint32_t STATUS;                            /**< Status, offset: 0x4 */
} fetchl10_Type;

/* ----------------------------------------------------------------------------
   -- fetchl10 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchl10_Register_Masks fetchl10 Register Masks
 * @{
 */

/*! @name BURBUFPR - BurstBufferProperties */
/*! @{ */

#define fetchl10_BURBUFPR_MndBstBf_MASK          (0xFFU)
#define fetchl10_BURBUFPR_MndBstBf_SHIFT         (0U)
/*! MndBstBf - ManagedBurstBuffers */
#define fetchl10_BURBUFPR_MndBstBf(x)            (((uint32_t)(((uint32_t)(x)) << fetchl10_BURBUFPR_MndBstBf_SHIFT)) & fetchl10_BURBUFPR_MndBstBf_MASK)

#define fetchl10_BURBUFPR_BurLFMBu_MASK          (0x1F00U)
#define fetchl10_BURBUFPR_BurLFMBu_SHIFT         (8U)
/*! BurLFMBu - BurstLengthForMaxBuffers */
#define fetchl10_BURBUFPR_BurLFMBu(x)            (((uint32_t)(((uint32_t)(x)) << fetchl10_BURBUFPR_BurLFMBu_SHIFT)) & fetchl10_BURBUFPR_BurLFMBu_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define fetchl10_STATUS_WrtTout_MASK             (0x1U)
#define fetchl10_STATUS_WrtTout_SHIFT            (0U)
/*! WrtTout - WriteTimeout */
#define fetchl10_STATUS_WrtTout(x)               (((uint32_t)(((uint32_t)(x)) << fetchl10_STATUS_WrtTout_SHIFT)) & fetchl10_STATUS_WrtTout_MASK)

#define fetchl10_STATUS_ReadTiou_MASK            (0x10U)
#define fetchl10_STATUS_ReadTiou_SHIFT           (4U)
/*! ReadTiou - ReadTimeout */
#define fetchl10_STATUS_ReadTiou(x)              (((uint32_t)(((uint32_t)(x)) << fetchl10_STATUS_ReadTiou_SHIFT)) & fetchl10_STATUS_ReadTiou_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchl10_Register_Masks */


/*!
 * @}
 */ /* end of group fetchl10_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHL10_H_ */

