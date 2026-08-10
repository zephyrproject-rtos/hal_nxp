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
**         CMSIS Peripheral Access Layer for fetchy13
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
 * @file PERI_fetchy13.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for fetchy13
 *
 * CMSIS Peripheral Access Layer for fetchy13
 */

#if !defined(PERI_FETCHY13_H_)
#define PERI_FETCHY13_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchy13 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchy13_Peripheral_Access_Layer fetchy13 Peripheral Access Layer
 * @{
 */

/** fetchy13 - Register Layout Typedef */
typedef struct {
  __I  uint32_t READAD0;                           /**< ReadAddress0, offset: 0x0 */
  __I  uint32_t READADM0;                          /**< ReadAddressMSB0, offset: 0x4 */
  __I  uint32_t BURBUFPR;                          /**< BurstBufferProperties, offset: 0x8 */
  __IO uint32_t STATUS;                            /**< Status, offset: 0xC */
} fetchy13_Type;

/* ----------------------------------------------------------------------------
   -- fetchy13 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchy13_Register_Masks fetchy13 Register Masks
 * @{
 */

/*! @name READAD0 - ReadAddress0 */
/*! @{ */

#define fetchy13_READAD0_RdAddr0_MASK            (0xFFFFFFFFU)
#define fetchy13_READAD0_RdAddr0_SHIFT           (0U)
/*! RdAddr0 - ReadAddress0 */
#define fetchy13_READAD0_RdAddr0(x)              (((uint32_t)(((uint32_t)(x)) << fetchy13_READAD0_RdAddr0_SHIFT)) & fetchy13_READAD0_RdAddr0_MASK)
/*! @} */

/*! @name READADM0 - ReadAddressMSB0 */
/*! @{ */

#define fetchy13_READADM0_RdAddrM0_MASK          (0xFFU)
#define fetchy13_READADM0_RdAddrM0_SHIFT         (0U)
/*! RdAddrM0 - ReadAddressMSB0 */
#define fetchy13_READADM0_RdAddrM0(x)            (((uint32_t)(((uint32_t)(x)) << fetchy13_READADM0_RdAddrM0_SHIFT)) & fetchy13_READADM0_RdAddrM0_MASK)
/*! @} */

/*! @name BURBUFPR - BurstBufferProperties */
/*! @{ */

#define fetchy13_BURBUFPR_MndBstBf_MASK          (0xFFU)
#define fetchy13_BURBUFPR_MndBstBf_SHIFT         (0U)
/*! MndBstBf - ManagedBurstBuffers */
#define fetchy13_BURBUFPR_MndBstBf(x)            (((uint32_t)(((uint32_t)(x)) << fetchy13_BURBUFPR_MndBstBf_SHIFT)) & fetchy13_BURBUFPR_MndBstBf_MASK)

#define fetchy13_BURBUFPR_BurLFMBu_MASK          (0x1F00U)
#define fetchy13_BURBUFPR_BurLFMBu_SHIFT         (8U)
/*! BurLFMBu - BurstLengthForMaxBuffers */
#define fetchy13_BURBUFPR_BurLFMBu(x)            (((uint32_t)(((uint32_t)(x)) << fetchy13_BURBUFPR_BurLFMBu_SHIFT)) & fetchy13_BURBUFPR_BurLFMBu_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define fetchy13_STATUS_WrtTout_MASK             (0x1U)
#define fetchy13_STATUS_WrtTout_SHIFT            (0U)
/*! WrtTout - WriteTimeout */
#define fetchy13_STATUS_WrtTout(x)               (((uint32_t)(((uint32_t)(x)) << fetchy13_STATUS_WrtTout_SHIFT)) & fetchy13_STATUS_WrtTout_MASK)

#define fetchy13_STATUS_ReadTiou_MASK            (0x10U)
#define fetchy13_STATUS_ReadTiou_SHIFT           (4U)
/*! ReadTiou - ReadTimeout */
#define fetchy13_STATUS_ReadTiou(x)              (((uint32_t)(((uint32_t)(x)) << fetchy13_STATUS_ReadTiou_SHIFT)) & fetchy13_STATUS_ReadTiou_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchy13_Register_Masks */


/*!
 * @}
 */ /* end of group fetchy13_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHY13_H_ */

