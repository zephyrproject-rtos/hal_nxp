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
**         CMSIS Peripheral Access Layer for CMU
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
 * @file PERI_CMU.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for CMU
 *
 * CMSIS Peripheral Access Layer for CMU
 */

#if !defined(PERI_CMU_H_)
#define PERI_CMU_H_                              /**< Symbol preventing repeated inclusion */

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
   -- CMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMU_Peripheral_Access_Layer CMU Peripheral Access Layer
 * @{
 */

/** CMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t GCR;                               /**< Global Configuration Register, offset: 0x0 */
  __IO uint32_t RCCR;                              /**< Reference Count Configuration Register, offset: 0x4 */
  __IO uint32_t HTCR;                              /**< High Threshold Configuration Register, offset: 0x8 */
  __IO uint32_t LTCR;                              /**< Low Threshold Configuration Register, offset: 0xC */
  __IO uint32_t SR;                                /**< Status Register, offset: 0x10 */
  __IO uint32_t IER;                               /**< Interrupt Enable Register, offset: 0x14 */
} CMU_Type;

/* ----------------------------------------------------------------------------
   -- CMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMU_Register_Masks CMU Register Masks
 * @{
 */

/*! @name GCR - Global Configuration Register */
/*! @{ */

#define CMU_GCR_FCE_MASK                         (0x1U)
#define CMU_GCR_FCE_SHIFT                        (0U)
/*! FCE - Frequency Check Enable
 *  0b0..Stops frequency checking
 *  0b1..Starts frequency checking
 */
#define CMU_GCR_FCE(x)                           (((uint32_t)(((uint32_t)(x)) << CMU_GCR_FCE_SHIFT)) & CMU_GCR_FCE_MASK)
/*! @} */

/*! @name RCCR - Reference Count Configuration Register */
/*! @{ */

#define CMU_RCCR_REF_CNT_MASK                    (0xFFFFU)
#define CMU_RCCR_REF_CNT_SHIFT                   (0U)
/*! REF_CNT - Reference clock count */
#define CMU_RCCR_REF_CNT(x)                      (((uint32_t)(((uint32_t)(x)) << CMU_RCCR_REF_CNT_SHIFT)) & CMU_RCCR_REF_CNT_MASK)
/*! @} */

/*! @name HTCR - High Threshold Configuration Register */
/*! @{ */

#define CMU_HTCR_HFREF_MASK                      (0xFFFFFFU)
#define CMU_HTCR_HFREF_SHIFT                     (0U)
/*! HFREF - High frequency reference threshold */
#define CMU_HTCR_HFREF(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_HTCR_HFREF_SHIFT)) & CMU_HTCR_HFREF_MASK)
/*! @} */

/*! @name LTCR - Low Threshold Configuration Register */
/*! @{ */

#define CMU_LTCR_LFREF_MASK                      (0xFFFFFFU)
#define CMU_LTCR_LFREF_SHIFT                     (0U)
/*! LFREF - Low Frequency Reference Threshold */
#define CMU_LTCR_LFREF(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_LTCR_LFREF_SHIFT)) & CMU_LTCR_LFREF_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define CMU_SR_FLL_MASK                          (0x1U)
#define CMU_SR_FLL_SHIFT                         (0U)
/*! FLL - Frequency lower than low frequency reference threshold event status
 *  0b0..No FLL event
 *  0b1..FLL event occurred
 */
#define CMU_SR_FLL(x)                            (((uint32_t)(((uint32_t)(x)) << CMU_SR_FLL_SHIFT)) & CMU_SR_FLL_MASK)

#define CMU_SR_FHH_MASK                          (0x2U)
#define CMU_SR_FHH_SHIFT                         (1U)
/*! FHH - Frequency higher than high frequency reference threshold event status
 *  0b0..No FHH event
 *  0b1..FHH event occurred
 */
#define CMU_SR_FHH(x)                            (((uint32_t)(((uint32_t)(x)) << CMU_SR_FHH_SHIFT)) & CMU_SR_FHH_MASK)

#define CMU_SR_RS_MASK                           (0x10U)
#define CMU_SR_RS_SHIFT                          (4U)
/*! RS - Run Status
 *  0b0..Frequency check stopped
 *  0b1..Frequency check running
 */
#define CMU_SR_RS(x)                             (((uint32_t)(((uint32_t)(x)) << CMU_SR_RS_SHIFT)) & CMU_SR_RS_MASK)
/*! @} */

/*! @name IER - Interrupt Enable Register */
/*! @{ */

#define CMU_IER_FLLAIE_MASK                      (0x4U)
#define CMU_IER_FLLAIE_SHIFT                     (2U)
/*! FLLAIE - Frequency Lower than Low Frequency Reference Threshold Asynchronous Interrupt Enable
 *  0b0..Asynchronous FLL event interrupt disabled
 *  0b1..Asynchronous FLL event interrupt enabled
 */
#define CMU_IER_FLLAIE(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_IER_FLLAIE_SHIFT)) & CMU_IER_FLLAIE_MASK)

#define CMU_IER_FHHAIE_MASK                      (0x8U)
#define CMU_IER_FHHAIE_SHIFT                     (3U)
/*! FHHAIE - Frequency Higher than High Frequency Reference Threshold Asynchronous Interrupt Enable
 *  0b0..Asynchronous FHH event interrupt disabled
 *  0b1..Asynchronous FHH event interrupt enabled
 */
#define CMU_IER_FHHAIE(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_IER_FHHAIE_SHIFT)) & CMU_IER_FHHAIE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CMU_Register_Masks */


/*!
 * @}
 */ /* end of group CMU_Peripheral_Access_Layer */


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


#endif  /* PERI_CMU_H_ */

