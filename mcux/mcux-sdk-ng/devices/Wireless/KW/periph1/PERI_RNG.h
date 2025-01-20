/*
** ###################################################################
**     Processors:          MKW21D256VHA5
**                          MKW21D512VHA5
**                          MKW22D512VHA5
**                          MKW24D512VHA5
**
**     Version:             rev. 2.0, 2015-01-06
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RNG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2013-11-22)
**         Initial version.
**     - rev. 2.0 (2015-01-06)
**         update of SystemInit() imlementation
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**         Register accessor macros added to the memory map.
**         MCG - bit LOLS in MCG_S register renamed to LOLS0.
**         DAC0 registers removed.
**
** ###################################################################
*/

/*!
 * @file RNG.h
 * @version 2.0
 * @date 2015-01-06
 * @brief CMSIS Peripheral Access Layer for RNG
 *
 * CMSIS Peripheral Access Layer for RNG
 */

#if !defined(RNG_H_)
#define RNG_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21D256VHA5) || defined(CPU_MKW21D512VHA5))
#include "MKW21D5_COMMON.h"
#elif (defined(CPU_MKW21D256VHA5) || defined(CPU_MKW21D512VHA5))
#include "MKW21D5WS_COMMON.h"
#elif (defined(CPU_MKW22D512VHA5))
#include "MKW22D5_COMMON.h"
#elif (defined(CPU_MKW22D512VHA5))
#include "MKW22D5WS_COMMON.h"
#elif (defined(CPU_MKW24D512VHA5))
#include "MKW24D5_COMMON.h"
#elif (defined(CPU_MKW24D512VHA5))
#include "MKW24D5WS_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- RNG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RNG_Peripheral_Access_Layer RNG Peripheral Access Layer
 * @{
 */

/** RNG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< RNGA Control Register, offset: 0x0 */
  __I  uint32_t SR;                                /**< RNGA Status Register, offset: 0x4 */
  __O  uint32_t ER;                                /**< RNGA Entropy Register, offset: 0x8 */
  __I  uint32_t OR;                                /**< RNGA Output Register, offset: 0xC */
} RNG_Type;

/* ----------------------------------------------------------------------------
   -- RNG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RNG_Register_Masks RNG Register Masks
 * @{
 */

/*! @name CR - RNGA Control Register */
/*! @{ */

#define RNG_CR_GO_MASK                           (0x1U)
#define RNG_CR_GO_SHIFT                          (0U)
/*! GO
 *  0b0..RNGA Output Register is not loaded with random data.
 *  0b1..RNGA Output Register is loaded with random data.
 */
#define RNG_CR_GO(x)                             (((uint32_t)(((uint32_t)(x)) << RNG_CR_GO_SHIFT)) & RNG_CR_GO_MASK)

#define RNG_CR_HA_MASK                           (0x2U)
#define RNG_CR_HA_SHIFT                          (1U)
/*! HA - High Assurance
 *  0b0..Notification of security violations is enabled.
 *  0b1..Notification of security violations is masked.
 */
#define RNG_CR_HA(x)                             (((uint32_t)(((uint32_t)(x)) << RNG_CR_HA_SHIFT)) & RNG_CR_HA_MASK)

#define RNG_CR_INTM_MASK                         (0x4U)
#define RNG_CR_INTM_SHIFT                        (2U)
/*! INTM - Interrupt Mask
 *  0b0..Interrupt is enabled.
 *  0b1..Interrupt is masked.
 */
#define RNG_CR_INTM(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_CR_INTM_SHIFT)) & RNG_CR_INTM_MASK)

#define RNG_CR_CLRI_MASK                         (0x8U)
#define RNG_CR_CLRI_SHIFT                        (3U)
/*! CLRI - Clear Interrupt
 *  0b0..Do not clear the interrupt.
 *  0b1..Clear the interrupt.
 */
#define RNG_CR_CLRI(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_CR_CLRI_SHIFT)) & RNG_CR_CLRI_MASK)

#define RNG_CR_SLP_MASK                          (0x10U)
#define RNG_CR_SLP_SHIFT                         (4U)
/*! SLP - Sleep
 *  0b0..RNGA is not in Sleep mode.
 *  0b1..RNGA is in Sleep mode.
 */
#define RNG_CR_SLP(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_CR_SLP_SHIFT)) & RNG_CR_SLP_MASK)
/*! @} */

/*! @name SR - RNGA Status Register */
/*! @{ */

#define RNG_SR_SECV_MASK                         (0x1U)
#define RNG_SR_SECV_SHIFT                        (0U)
/*! SECV - Security Violation
 *  0b0..No security violations have occured or the High Assurance bit (HA) in the RNGA Control Register is not set.
 *  0b1..A security violation has occurred.
 */
#define RNG_SR_SECV(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_SR_SECV_SHIFT)) & RNG_SR_SECV_MASK)

#define RNG_SR_LRS_MASK                          (0x2U)
#define RNG_SR_LRS_SHIFT                         (1U)
/*! LRS - Last Read Status
 *  0b0..Last read was performed while the RNGA Output Register was not empty.
 *  0b1..Last read was performed while the RNGA Output Register was empty (underflow condition).
 */
#define RNG_SR_LRS(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_SR_LRS_SHIFT)) & RNG_SR_LRS_MASK)

#define RNG_SR_ORU_MASK                          (0x4U)
#define RNG_SR_ORU_SHIFT                         (2U)
/*! ORU - Output Register Underflow
 *  0b0..The RNGA Output Register has not been read while empty since last read of the RNGA Status Register.
 *  0b1..The RNGA Output Register has been read while empty since last read of the RNGA Status Register.
 */
#define RNG_SR_ORU(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_SR_ORU_SHIFT)) & RNG_SR_ORU_MASK)

#define RNG_SR_ERRI_MASK                         (0x8U)
#define RNG_SR_ERRI_SHIFT                        (3U)
/*! ERRI - Error Interrupt
 *  0b0..The RNGA Output Register has not been read while empty.
 *  0b1..The RNGA Output Register has been read while empty.
 */
#define RNG_SR_ERRI(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_SR_ERRI_SHIFT)) & RNG_SR_ERRI_MASK)

#define RNG_SR_SLP_MASK                          (0x10U)
#define RNG_SR_SLP_SHIFT                         (4U)
/*! SLP - Sleep
 *  0b0..The RNGA is not in Sleep mode.
 *  0b1..The RNGA is in Sleep mode.
 */
#define RNG_SR_SLP(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_SR_SLP_SHIFT)) & RNG_SR_SLP_MASK)

#define RNG_SR_OREG_LVL_MASK                     (0xFF00U)
#define RNG_SR_OREG_LVL_SHIFT                    (8U)
/*! OREG_LVL - Output Register Level */
#define RNG_SR_OREG_LVL(x)                       (((uint32_t)(((uint32_t)(x)) << RNG_SR_OREG_LVL_SHIFT)) & RNG_SR_OREG_LVL_MASK)

#define RNG_SR_OREG_SIZE_MASK                    (0xFF0000U)
#define RNG_SR_OREG_SIZE_SHIFT                   (16U)
/*! OREG_SIZE - Output Register Size */
#define RNG_SR_OREG_SIZE(x)                      (((uint32_t)(((uint32_t)(x)) << RNG_SR_OREG_SIZE_SHIFT)) & RNG_SR_OREG_SIZE_MASK)
/*! @} */

/*! @name ER - RNGA Entropy Register */
/*! @{ */

#define RNG_ER_EXT_ENT_MASK                      (0xFFFFFFFFU)
#define RNG_ER_EXT_ENT_SHIFT                     (0U)
/*! EXT_ENT - External Entropy */
#define RNG_ER_EXT_ENT(x)                        (((uint32_t)(((uint32_t)(x)) << RNG_ER_EXT_ENT_SHIFT)) & RNG_ER_EXT_ENT_MASK)
/*! @} */

/*! @name OR - RNGA Output Register */
/*! @{ */

#define RNG_OR_RANDOUT_MASK                      (0xFFFFFFFFU)
#define RNG_OR_RANDOUT_SHIFT                     (0U)
/*! RANDOUT - Random Output */
#define RNG_OR_RANDOUT(x)                        (((uint32_t)(((uint32_t)(x)) << RNG_OR_RANDOUT_SHIFT)) & RNG_OR_RANDOUT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RNG_Register_Masks */


/*!
 * @}
 */ /* end of group RNG_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* RNG_H_ */

