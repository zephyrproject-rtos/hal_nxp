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
**         CMSIS Peripheral Access Layer for ieprc_prb
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
 * @file PERI_ieprc_prb.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for ieprc_prb
 *
 * CMSIS Peripheral Access Layer for ieprc_prb
 */

#if !defined(PERI_IEPRC_PRB_H_)
#define PERI_IEPRC_PRB_H_                        /**< Symbol preventing repeated inclusion */

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
   -- ieprc_prb Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ieprc_prb_Peripheral_Access_Layer ieprc_prb Peripheral Access Layer
 * @{
 */

/** ieprc_prb - Size of Registers Arrays */
#define ieprc_prb_BUSX_COUNT                      2u

/** ieprc_prb - Register Layout Typedef */
typedef struct {
  __IO uint32_t RR;                                /**< Reset register, offset: 0x0 */
       uint8_t RESERVED_0[252];
  __IO uint32_t EC_RR[ieprc_prb_BUSX_COUNT];       /**< EC Reset register, array offset: 0x100, array step: 0x4 */
} ieprc_prb_Type;

/* ----------------------------------------------------------------------------
   -- ieprc_prb Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ieprc_prb_Register_Masks ieprc_prb Register Masks
 * @{
 */

/*! @name RR - Reset register */
/*! @{ */

#define ieprc_prb_RR_SR_MASK                     (0x1U)
#define ieprc_prb_RR_SR_SHIFT                    (0U)
/*! SR - Soft reset */
#define ieprc_prb_RR_SR(x)                       (((uint32_t)(((uint32_t)(x)) << ieprc_prb_RR_SR_SHIFT)) & ieprc_prb_RR_SR_MASK)

#define ieprc_prb_RR_LOCK_MASK                   (0x2U)
#define ieprc_prb_RR_LOCK_SHIFT                  (1U)
/*! LOCK - Lock */
#define ieprc_prb_RR_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << ieprc_prb_RR_LOCK_SHIFT)) & ieprc_prb_RR_LOCK_MASK)
/*! @} */

/*! @name EC_RR - EC Reset register */
/*! @{ */

#define ieprc_prb_EC_RR_ECSR_MASK                (0x1U)
#define ieprc_prb_EC_RR_ECSR_SHIFT               (0U)
/*! ECSR - EC Soft reset */
#define ieprc_prb_EC_RR_ECSR(x)                  (((uint32_t)(((uint32_t)(x)) << ieprc_prb_EC_RR_ECSR_SHIFT)) & ieprc_prb_EC_RR_ECSR_MASK)
/*! @} */

/* The count of ieprc_prb_EC_RR */
#define ieprc_prb_EC_RR_COUNT                    (2U)


/*!
 * @}
 */ /* end of group ieprc_prb_Register_Masks */


/*!
 * @}
 */ /* end of group ieprc_prb_Peripheral_Access_Layer */


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


#endif  /* PERI_IEPRC_PRB_H_ */

