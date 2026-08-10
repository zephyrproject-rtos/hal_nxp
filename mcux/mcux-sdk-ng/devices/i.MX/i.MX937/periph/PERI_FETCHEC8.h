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
**         CMSIS Peripheral Access Layer for fetchec8
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
 * @file PERI_fetchec8.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for fetchec8
 *
 * CMSIS Peripheral Access Layer for fetchec8
 */

#if !defined(PERI_FETCHEC8_H_)
#define PERI_FETCHEC8_H_                         /**< Symbol preventing repeated inclusion */

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
   -- fetchec8 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchec8_Peripheral_Access_Layer fetchec8 Peripheral Access Layer
 * @{
 */

/** fetchec8 - Register Layout Typedef */
typedef struct {
  __I  uint32_t BURBUFPR;                          /**< BurstBufferProperties, offset: 0x0 */
} fetchec8_Type;

/* ----------------------------------------------------------------------------
   -- fetchec8 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup fetchec8_Register_Masks fetchec8 Register Masks
 * @{
 */

/*! @name BURBUFPR - BurstBufferProperties */
/*! @{ */

#define fetchec8_BURBUFPR_MndBstBf_MASK          (0xFFU)
#define fetchec8_BURBUFPR_MndBstBf_SHIFT         (0U)
/*! MndBstBf - ManagedBurstBuffers */
#define fetchec8_BURBUFPR_MndBstBf(x)            (((uint32_t)(((uint32_t)(x)) << fetchec8_BURBUFPR_MndBstBf_SHIFT)) & fetchec8_BURBUFPR_MndBstBf_MASK)

#define fetchec8_BURBUFPR_BurLFMBu_MASK          (0x1F00U)
#define fetchec8_BURBUFPR_BurLFMBu_SHIFT         (8U)
/*! BurLFMBu - BurstLengthForMaxBuffers */
#define fetchec8_BURBUFPR_BurLFMBu(x)            (((uint32_t)(((uint32_t)(x)) << fetchec8_BURBUFPR_BurLFMBu_SHIFT)) & fetchec8_BURBUFPR_BurLFMBu_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group fetchec8_Register_Masks */


/*!
 * @}
 */ /* end of group fetchec8_Peripheral_Access_Layer */


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


#endif  /* PERI_FETCHEC8_H_ */

