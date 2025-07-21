/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CMU_FC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_CMU_FC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for CMU_FC
 *
 * CMSIS Peripheral Access Layer for CMU_FC
 */

#if !defined(PERI_CMU_FC_H_)
#define PERI_CMU_FC_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
   -- CMU_FC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMU_FC_Peripheral_Access_Layer CMU_FC Peripheral Access Layer
 * @{
 */

/** CMU_FC - Register Layout Typedef */
typedef struct {
  __IO uint32_t GCR;                               /**< Global Configuration Register, offset: 0x0 */
  __IO uint32_t RCCR;                              /**< Reference Count Configuration Register, offset: 0x4 */
  __IO uint32_t HTCR;                              /**< High Threshold Configuration Register, offset: 0x8 */
  __IO uint32_t LTCR;                              /**< Low Threshold Configuration Register, offset: 0xC */
  __IO uint32_t SR;                                /**< Status Register, offset: 0x10 */
  __IO uint32_t IER;                               /**< Interrupt Enable Register, offset: 0x14 */
} CMU_FC_Type;

/* ----------------------------------------------------------------------------
   -- CMU_FC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMU_FC_Register_Masks CMU_FC Register Masks
 * @{
 */

/*! @name GCR - Global Configuration Register */
/*! @{ */

#define CMU_FC_GCR_FCE_MASK                      (0x1U)
#define CMU_FC_GCR_FCE_SHIFT                     (0U)
/*! FCE - Frequency Check Enable
 *  0b0..Stops frequency checking
 *  0b1..Starts frequency checking
 */
#define CMU_FC_GCR_FCE(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_FC_GCR_FCE_SHIFT)) & CMU_FC_GCR_FCE_MASK)
/*! @} */

/*! @name RCCR - Reference Count Configuration Register */
/*! @{ */

#define CMU_FC_RCCR_REF_CNT_MASK                 (0xFFFFU)
#define CMU_FC_RCCR_REF_CNT_SHIFT                (0U)
/*! REF_CNT - Reference clock count */
#define CMU_FC_RCCR_REF_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << CMU_FC_RCCR_REF_CNT_SHIFT)) & CMU_FC_RCCR_REF_CNT_MASK)
/*! @} */

/*! @name HTCR - High Threshold Configuration Register */
/*! @{ */

#define CMU_FC_HTCR_HFREF_MASK                   (0xFFFFFFU)
#define CMU_FC_HTCR_HFREF_SHIFT                  (0U)
/*! HFREF - High frequency reference threshold */
#define CMU_FC_HTCR_HFREF(x)                     (((uint32_t)(((uint32_t)(x)) << CMU_FC_HTCR_HFREF_SHIFT)) & CMU_FC_HTCR_HFREF_MASK)
/*! @} */

/*! @name LTCR - Low Threshold Configuration Register */
/*! @{ */

#define CMU_FC_LTCR_LFREF_MASK                   (0xFFFFFFU)
#define CMU_FC_LTCR_LFREF_SHIFT                  (0U)
/*! LFREF - Low Frequency Reference Threshold */
#define CMU_FC_LTCR_LFREF(x)                     (((uint32_t)(((uint32_t)(x)) << CMU_FC_LTCR_LFREF_SHIFT)) & CMU_FC_LTCR_LFREF_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define CMU_FC_SR_FLL_MASK                       (0x1U)
#define CMU_FC_SR_FLL_SHIFT                      (0U)
/*! FLL - Frequency lower than low frequency reference threshold event status
 *  0b0..No FLL event
 *  0b1..FLL event occurred
 */
#define CMU_FC_SR_FLL(x)                         (((uint32_t)(((uint32_t)(x)) << CMU_FC_SR_FLL_SHIFT)) & CMU_FC_SR_FLL_MASK)

#define CMU_FC_SR_FHH_MASK                       (0x2U)
#define CMU_FC_SR_FHH_SHIFT                      (1U)
/*! FHH - Frequency higher than high frequency reference threshold event status
 *  0b0..No FHH event
 *  0b1..FHH event occurred
 */
#define CMU_FC_SR_FHH(x)                         (((uint32_t)(((uint32_t)(x)) << CMU_FC_SR_FHH_SHIFT)) & CMU_FC_SR_FHH_MASK)

#define CMU_FC_SR_RS_MASK                        (0x10U)
#define CMU_FC_SR_RS_SHIFT                       (4U)
/*! RS - Run Status
 *  0b0..Frequency check stopped
 *  0b1..Frequency check running
 */
#define CMU_FC_SR_RS(x)                          (((uint32_t)(((uint32_t)(x)) << CMU_FC_SR_RS_SHIFT)) & CMU_FC_SR_RS_MASK)
/*! @} */

/*! @name IER - Interrupt Enable Register */
/*! @{ */

#define CMU_FC_IER_FLLIE_MASK                    (0x1U)
#define CMU_FC_IER_FLLIE_SHIFT                   (0U)
/*! FLLIE - Frequency Lower than Low Frequency Reference Threshold Synchronous Interrupt Enable
 *  0b0..Synchronous FLL event interrupt disabled
 *  0b1..Synchronous FLL event interrupt enabled
 */
#define CMU_FC_IER_FLLIE(x)                      (((uint32_t)(((uint32_t)(x)) << CMU_FC_IER_FLLIE_SHIFT)) & CMU_FC_IER_FLLIE_MASK)

#define CMU_FC_IER_FHHIE_MASK                    (0x2U)
#define CMU_FC_IER_FHHIE_SHIFT                   (1U)
/*! FHHIE - Frequency Higher than High Frequency Reference Threshold Synchronous Interrupt Enable
 *  0b0..Synchronous FHH event interrupt disabled
 *  0b1..Synchronous FHH event interrupt enabled
 */
#define CMU_FC_IER_FHHIE(x)                      (((uint32_t)(((uint32_t)(x)) << CMU_FC_IER_FHHIE_SHIFT)) & CMU_FC_IER_FHHIE_MASK)

#define CMU_FC_IER_FLLAIE_MASK                   (0x4U)
#define CMU_FC_IER_FLLAIE_SHIFT                  (2U)
/*! FLLAIE - Frequency Lower than Low Frequency Reference Threshold Asynchronous Interrupt Enable
 *  0b0..Asynchronous FLL event interrupt disabled
 *  0b1..Asynchronous FLL event interrupt enabled
 */
#define CMU_FC_IER_FLLAIE(x)                     (((uint32_t)(((uint32_t)(x)) << CMU_FC_IER_FLLAIE_SHIFT)) & CMU_FC_IER_FLLAIE_MASK)

#define CMU_FC_IER_FHHAIE_MASK                   (0x8U)
#define CMU_FC_IER_FHHAIE_SHIFT                  (3U)
/*! FHHAIE - Frequency Higher than High Frequency Reference Threshold Asynchronous Interrupt Enable
 *  0b0..Asynchronous FHH event interrupt disabled
 *  0b1..Asynchronous FHH event interrupt enabled
 */
#define CMU_FC_IER_FHHAIE(x)                     (((uint32_t)(((uint32_t)(x)) << CMU_FC_IER_FHHAIE_SHIFT)) & CMU_FC_IER_FHHAIE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CMU_FC_Register_Masks */


/*!
 * @}
 */ /* end of group CMU_FC_Peripheral_Access_Layer */


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


#endif  /* PERI_CMU_FC_H_ */

