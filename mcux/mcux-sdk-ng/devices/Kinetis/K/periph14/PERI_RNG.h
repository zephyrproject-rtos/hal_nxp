/*
** ###################################################################
**     Processors:          MK22FN128CAH12
**                          MK22FN256CAH12
**                          MK22FN256VDC12
**                          MK22FN256VLH12
**                          MK22FN256VLL12
**                          MK22FN256VMP12
**
**     Version:             rev. 1.8, 2015-02-19
**     Build:               b240709
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
**     - rev. 1.0 (2013-09-17)
**         Initial version.
**     - rev. 1.1 (2013-10-29)
**         Definition of BITBAND macros updated to support peripherals with 32-bit acces disabled.
**     - rev. 1.2 (2013-12-20)
**         Update according to reference manual rev. 0.6,
**     - rev. 1.3 (2014-02-06)
**         Update according to reference manual rev. 0.61,
**     - rev. 1.4 (2014-02-10)
**         The declaration of clock configurations has been moved to separate header file system_MK22F25612.h
**     - rev. 1.5 (2014-04-30)
**         Update of MCM and USB modules according to the RM rev. 1.
**         Update of system and startup files.
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**     - rev. 1.6 (2014-08-28)
**         Update of system files - default clock configuration changed.
**         Update of startup files - possibility to override DefaultISR added.
**     - rev. 1.7 (2014-10-14)
**         Interrupt INT_LPTimer renamed to INT_LPTMR0, interrupt INT_Watchdog renamed to INT_WDOG_EWM.
**     - rev. 1.8 (2015-02-19)
**         Renamed interrupt vector LLW to LLWU.
**
** ###################################################################
*/

/*!
 * @file RNG.h
 * @version 1.8
 * @date 2015-02-19
 * @brief CMSIS Peripheral Access Layer for RNG
 *
 * CMSIS Peripheral Access Layer for RNG
 */

#if !defined(RNG_H_)
#define RNG_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MK22FN128CAH12) || defined(CPU_MK22FN256CAH12) || defined(CPU_MK22FN256VDC12) || defined(CPU_MK22FN256VLH12) || defined(CPU_MK22FN256VLL12) || defined(CPU_MK22FN256VMP12))
#include "MK22F25612_COMMON.h"
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
/*! GO - Go
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define RNG_CR_GO(x)                             (((uint32_t)(((uint32_t)(x)) << RNG_CR_GO_SHIFT)) & RNG_CR_GO_MASK)

#define RNG_CR_HA_MASK                           (0x2U)
#define RNG_CR_HA_SHIFT                          (1U)
/*! HA - High Assurance
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define RNG_CR_HA(x)                             (((uint32_t)(((uint32_t)(x)) << RNG_CR_HA_SHIFT)) & RNG_CR_HA_MASK)

#define RNG_CR_INTM_MASK                         (0x4U)
#define RNG_CR_INTM_SHIFT                        (2U)
/*! INTM - Interrupt Mask
 *  0b0..Not masked
 *  0b1..Masked
 */
#define RNG_CR_INTM(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_CR_INTM_SHIFT)) & RNG_CR_INTM_MASK)

#define RNG_CR_CLRI_MASK                         (0x8U)
#define RNG_CR_CLRI_SHIFT                        (3U)
/*! CLRI - Clear Interrupt
 *  0b0..Do not clear the interrupt.
 *  0b1..Clear the interrupt. When you write 1 to this field, RNGA then resets the error-interrupt indicator (SR[ERRI]). This bit always reads as 0.
 */
#define RNG_CR_CLRI(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_CR_CLRI_SHIFT)) & RNG_CR_CLRI_MASK)

#define RNG_CR_SLP_MASK                          (0x10U)
#define RNG_CR_SLP_SHIFT                         (4U)
/*! SLP - Sleep
 *  0b0..Normal mode
 *  0b1..Sleep (low-power) mode
 */
#define RNG_CR_SLP(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_CR_SLP_SHIFT)) & RNG_CR_SLP_MASK)
/*! @} */

/*! @name SR - RNGA Status Register */
/*! @{ */

#define RNG_SR_SECV_MASK                         (0x1U)
#define RNG_SR_SECV_SHIFT                        (0U)
/*! SECV - Security Violation
 *  0b0..No security violation
 *  0b1..Security violation
 */
#define RNG_SR_SECV(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_SR_SECV_SHIFT)) & RNG_SR_SECV_MASK)

#define RNG_SR_LRS_MASK                          (0x2U)
#define RNG_SR_LRS_SHIFT                         (1U)
/*! LRS - Last Read Status
 *  0b0..No underflow
 *  0b1..Underflow
 */
#define RNG_SR_LRS(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_SR_LRS_SHIFT)) & RNG_SR_LRS_MASK)

#define RNG_SR_ORU_MASK                          (0x4U)
#define RNG_SR_ORU_SHIFT                         (2U)
/*! ORU - Output Register Underflow
 *  0b0..No underflow
 *  0b1..Underflow
 */
#define RNG_SR_ORU(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_SR_ORU_SHIFT)) & RNG_SR_ORU_MASK)

#define RNG_SR_ERRI_MASK                         (0x8U)
#define RNG_SR_ERRI_SHIFT                        (3U)
/*! ERRI - Error Interrupt
 *  0b0..No underflow
 *  0b1..Underflow
 */
#define RNG_SR_ERRI(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_SR_ERRI_SHIFT)) & RNG_SR_ERRI_MASK)

#define RNG_SR_SLP_MASK                          (0x10U)
#define RNG_SR_SLP_SHIFT                         (4U)
/*! SLP - Sleep
 *  0b0..Normal mode
 *  0b1..Sleep (low-power) mode
 */
#define RNG_SR_SLP(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_SR_SLP_SHIFT)) & RNG_SR_SLP_MASK)

#define RNG_SR_OREG_LVL_MASK                     (0xFF00U)
#define RNG_SR_OREG_LVL_SHIFT                    (8U)
/*! OREG_LVL - Output Register Level
 *  0b00000000..No words (empty)
 *  0b00000001..One word (valid)
 */
#define RNG_SR_OREG_LVL(x)                       (((uint32_t)(((uint32_t)(x)) << RNG_SR_OREG_LVL_SHIFT)) & RNG_SR_OREG_LVL_MASK)

#define RNG_SR_OREG_SIZE_MASK                    (0xFF0000U)
#define RNG_SR_OREG_SIZE_SHIFT                   (16U)
/*! OREG_SIZE - Output Register Size
 *  0b00000001..One word (this value is fixed)
 */
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
/*! RANDOUT - Random Output
 *  0b00000000000000000000000000000000..Invalid data (if you read this field when it is 0 and SR[OREG_LVL] is 0,
 *                                      RNGA then writes 1 to SR[ERRI], SR[ORU], and SR[LRS]; when the error
 *                                      interrupt is not masked (CR[INTM]=0), RNGA also asserts an error interrupt request
 *                                      to the interrupt controller).
 */
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

