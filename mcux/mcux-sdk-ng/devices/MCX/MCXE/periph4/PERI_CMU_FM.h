/*
** ###################################################################
**     Processors:          MCXE317MPA
**                          MCXE317MPB
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CMU_FM
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
 * @file PERI_CMU_FM.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for CMU_FM
 *
 * CMSIS Peripheral Access Layer for CMU_FM
 */

#if !defined(PERI_CMU_FM_H_)
#define PERI_CMU_FM_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE317MPA) || defined(CPU_MCXE317MPB))
#include "MCXE317_COMMON.h"
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
   -- CMU_FM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMU_FM_Peripheral_Access_Layer CMU_FM Peripheral Access Layer
 * @{
 */

/** CMU_FM - Register Layout Typedef */
typedef struct {
  __IO uint32_t GCR;                               /**< Global Configuration Register, offset: 0x0 */
  __IO uint32_t RCCR;                              /**< Reference Count Configuration Register, offset: 0x4 */
  __IO uint32_t SR;                                /**< Status Register, offset: 0x8 */
  __IO uint32_t IER;                               /**< Interrupt Enable Register, offset: 0xC */
} CMU_FM_Type;

/* ----------------------------------------------------------------------------
   -- CMU_FM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMU_FM_Register_Masks CMU_FM Register Masks
 * @{
 */

/*! @name GCR - Global Configuration Register */
/*! @{ */

#define CMU_FM_GCR_FME_MASK                      (0x1U)
#define CMU_FM_GCR_FME_SHIFT                     (0U)
/*! FME - Frequency Meter Enable
 *  0b0..Stops frequency metering
 *  0b1..Starts frequency metering
 */
#define CMU_FM_GCR_FME(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_FM_GCR_FME_SHIFT)) & CMU_FM_GCR_FME_MASK)
/*! @} */

/*! @name RCCR - Reference Count Configuration Register */
/*! @{ */

#define CMU_FM_RCCR_REF_CNT_MASK                 (0xFFFFU)
#define CMU_FM_RCCR_REF_CNT_SHIFT                (0U)
/*! REF_CNT - Reference Clock Count */
#define CMU_FM_RCCR_REF_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << CMU_FM_RCCR_REF_CNT_SHIFT)) & CMU_FM_RCCR_REF_CNT_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define CMU_FM_SR_FMC_MASK                       (0x1U)
#define CMU_FM_SR_FMC_SHIFT                      (0U)
/*! FMC - Frequency Meter Operation Complete */
#define CMU_FM_SR_FMC(x)                         (((uint32_t)(((uint32_t)(x)) << CMU_FM_SR_FMC_SHIFT)) & CMU_FM_SR_FMC_MASK)

#define CMU_FM_SR_FMTO_MASK                      (0x2U)
#define CMU_FM_SR_FMTO_SHIFT                     (1U)
/*! FMTO - Frequency Meter Time Out */
#define CMU_FM_SR_FMTO(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_FM_SR_FMTO_SHIFT)) & CMU_FM_SR_FMTO_MASK)

#define CMU_FM_SR_RS_MASK                        (0x10U)
#define CMU_FM_SR_RS_SHIFT                       (4U)
/*! RS - Run Status
 *  0b0..Frequency meter stopped
 *  0b1..Frequency meter running
 */
#define CMU_FM_SR_RS(x)                          (((uint32_t)(((uint32_t)(x)) << CMU_FM_SR_RS_SHIFT)) & CMU_FM_SR_RS_MASK)

#define CMU_FM_SR_MET_CNT_MASK                   (0xFFFFFF00U)
#define CMU_FM_SR_MET_CNT_SHIFT                  (8U)
/*! MET_CNT - Meter Clock Count */
#define CMU_FM_SR_MET_CNT(x)                     (((uint32_t)(((uint32_t)(x)) << CMU_FM_SR_MET_CNT_SHIFT)) & CMU_FM_SR_MET_CNT_MASK)
/*! @} */

/*! @name IER - Interrupt Enable Register */
/*! @{ */

#define CMU_FM_IER_FMCIE_MASK                    (0x1U)
#define CMU_FM_IER_FMCIE_SHIFT                   (0U)
/*! FMCIE - Frequency Meter Complete Interrupt Enable
 *  0b0..Frequency Meter complete interrupt is disabled
 *  0b1..Frequency Meter complete interrupt is enabled
 */
#define CMU_FM_IER_FMCIE(x)                      (((uint32_t)(((uint32_t)(x)) << CMU_FM_IER_FMCIE_SHIFT)) & CMU_FM_IER_FMCIE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CMU_FM_Register_Masks */


/*!
 * @}
 */ /* end of group CMU_FM_Peripheral_Access_Layer */


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


#endif  /* PERI_CMU_FM_H_ */

