/*
** ###################################################################
**     Processors:          LPC54101J256BD64
**                          LPC54101J256UK49
**                          LPC54101J512BD64
**                          LPC54101J512UK49
**                          LPC54102J256BD64_cm0plus
**                          LPC54102J256BD64_cm4
**                          LPC54102J256UK49_cm0plus
**                          LPC54102J256UK49_cm4
**                          LPC54102J512BD64_cm0plus
**                          LPC54102J512BD64_cm4
**                          LPC54102J512UK49_cm0plus
**                          LPC54102J512UK49_cm4
**
**     Version:             rev. 1.0, 2016-04-29
**     Build:               b240704
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RIT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-29)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file RIT.h
 * @version 1.0
 * @date 2016-04-29
 * @brief CMSIS Peripheral Access Layer for RIT
 *
 * CMSIS Peripheral Access Layer for RIT
 */

#if !defined(RIT_H_)
#define RIT_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54101J256BD64) || defined(CPU_LPC54101J256UK49) || defined(CPU_LPC54101J512BD64) || defined(CPU_LPC54101J512UK49))
#include "LPC54101_COMMON.h"
#elif (defined(CPU_LPC54102J256BD64_cm0plus) || defined(CPU_LPC54102J256UK49_cm0plus) || defined(CPU_LPC54102J512BD64_cm0plus) || defined(CPU_LPC54102J512UK49_cm0plus))
#include "LPC54102_cm0plus_COMMON.h"
#elif (defined(CPU_LPC54102J256BD64_cm4) || defined(CPU_LPC54102J256UK49_cm4) || defined(CPU_LPC54102J512BD64_cm4) || defined(CPU_LPC54102J512UK49_cm4))
#include "LPC54102_cm4_COMMON.h"
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
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- RIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RIT_Peripheral_Access_Layer RIT Peripheral Access Layer
 * @{
 */

/** RIT - Register Layout Typedef */
typedef struct {
  __IO uint32_t COMPVAL;                           /**< Compare value LSB register. Holds the 32 LSBs of the compare value., offset: 0x0 */
  __IO uint32_t MASK;                              /**< Mask LSB register. This register holds the 32 LSB s of the mask value. A 1 written to any bit will force the compare to be true for the corresponding bit of the counter and compare register., offset: 0x4 */
  __IO uint32_t CTRL;                              /**< Control register., offset: 0x8 */
  __IO uint32_t COUNTER;                           /**< Counter LSB register. 32 LSBs of the counter., offset: 0xC */
  __IO uint32_t COMPVAL_H;                         /**< Compare value MSB register. Holds the 16 MSBs of the compare value., offset: 0x10 */
  __IO uint32_t MASK_H;                            /**< Mask MSB register. This register holds the 16 MSBs of the mask value. A 1 written to any bit will force a compare on the corresponding bit of the counter and compare register., offset: 0x14 */
       uint8_t RESERVED_0[4];
  __IO uint32_t COUNTER_H;                         /**< Counter MSB register. 16 MSBs of the counter., offset: 0x1C */
} RIT_Type;

/* ----------------------------------------------------------------------------
   -- RIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RIT_Register_Masks RIT Register Masks
 * @{
 */

/*! @name COMPVAL - Compare value LSB register. Holds the 32 LSBs of the compare value. */
/*! @{ */

#define RIT_COMPVAL_RICOMP_MASK                  (0xFFFFFFFFU)
#define RIT_COMPVAL_RICOMP_SHIFT                 (0U)
/*! RICOMP - Compare register. Holds the 32 LSBs of the value which is compared to the counter. */
#define RIT_COMPVAL_RICOMP(x)                    (((uint32_t)(((uint32_t)(x)) << RIT_COMPVAL_RICOMP_SHIFT)) & RIT_COMPVAL_RICOMP_MASK)
/*! @} */

/*! @name MASK - Mask LSB register. This register holds the 32 LSB s of the mask value. A 1 written to any bit will force the compare to be true for the corresponding bit of the counter and compare register. */
/*! @{ */

#define RIT_MASK_RIMASK_MASK                     (0xFFFFFFFFU)
#define RIT_MASK_RIMASK_SHIFT                    (0U)
/*! RIMASK - Mask register. This register holds the 32 LSBs of the mask value. A one written to any
 *    bit overrides the result of the comparison for the corresponding bit of the counter and
 *    compare register (causes the comparison of the register bits to be always true).
 */
#define RIT_MASK_RIMASK(x)                       (((uint32_t)(((uint32_t)(x)) << RIT_MASK_RIMASK_SHIFT)) & RIT_MASK_RIMASK_MASK)
/*! @} */

/*! @name CTRL - Control register. */
/*! @{ */

#define RIT_CTRL_RITINT_MASK                     (0x1U)
#define RIT_CTRL_RITINT_SHIFT                    (0U)
/*! RITINT - Interrupt flag
 *  0b1..This bit is set to 1 by hardware whenever the counter value equals the masked compare value specified by
 *       the contents of RICOMPVAL and RIMASK registers. Writing a 1 to this bit will clear it to 0. Writing a 0
 *       has no effect.
 *  0b0..The counter value does not equal the masked compare value.
 */
#define RIT_CTRL_RITINT(x)                       (((uint32_t)(((uint32_t)(x)) << RIT_CTRL_RITINT_SHIFT)) & RIT_CTRL_RITINT_MASK)

#define RIT_CTRL_RITENCLR_MASK                   (0x2U)
#define RIT_CTRL_RITENCLR_SHIFT                  (1U)
/*! RITENCLR - Timer enable clear
 *  0b1..The timer will be cleared to 0 whenever the counter value equals the masked compare value specified by
 *       the contents of COMPVAL/COMPVAL_H and MASK/MASK_H registers. This will occur on the same clock that sets the
 *       interrupt flag.
 *  0b0..The timer will not be cleared to 0.
 */
#define RIT_CTRL_RITENCLR(x)                     (((uint32_t)(((uint32_t)(x)) << RIT_CTRL_RITENCLR_SHIFT)) & RIT_CTRL_RITENCLR_MASK)

#define RIT_CTRL_RITENBR_MASK                    (0x4U)
#define RIT_CTRL_RITENBR_SHIFT                   (2U)
/*! RITENBR - Timer enable for debug
 *  0b1..The timer is halted when the processor is halted for debugging.
 *  0b0..Debug has no effect on the timer operation.
 */
#define RIT_CTRL_RITENBR(x)                      (((uint32_t)(((uint32_t)(x)) << RIT_CTRL_RITENBR_SHIFT)) & RIT_CTRL_RITENBR_MASK)

#define RIT_CTRL_RITEN_MASK                      (0x8U)
#define RIT_CTRL_RITEN_SHIFT                     (3U)
/*! RITEN - Timer enable.
 *  0b1..Timer enabled. This can be overruled by a debug halt if enabled in bit 2.
 *  0b0..Timer disabled.
 */
#define RIT_CTRL_RITEN(x)                        (((uint32_t)(((uint32_t)(x)) << RIT_CTRL_RITEN_SHIFT)) & RIT_CTRL_RITEN_MASK)
/*! @} */

/*! @name COUNTER - Counter LSB register. 32 LSBs of the counter. */
/*! @{ */

#define RIT_COUNTER_RICOUNTER_MASK               (0xFFFFFFFFU)
#define RIT_COUNTER_RICOUNTER_SHIFT              (0U)
/*! RICOUNTER - 32 LSBs of the up counter. Counts continuously unless RITEN bit in CTRL register is
 *    cleared or debug mode is entered (if enabled by the RITNEBR bit in RICTRL). Can be loaded to
 *    any value in software.
 */
#define RIT_COUNTER_RICOUNTER(x)                 (((uint32_t)(((uint32_t)(x)) << RIT_COUNTER_RICOUNTER_SHIFT)) & RIT_COUNTER_RICOUNTER_MASK)
/*! @} */

/*! @name COMPVAL_H - Compare value MSB register. Holds the 16 MSBs of the compare value. */
/*! @{ */

#define RIT_COMPVAL_H_RICOMP_MASK                (0xFFFFU)
#define RIT_COMPVAL_H_RICOMP_SHIFT               (0U)
/*! RICOMP - Compare value MSB register. Holds the 16 MSBs of the value which is compared to the counter. */
#define RIT_COMPVAL_H_RICOMP(x)                  (((uint32_t)(((uint32_t)(x)) << RIT_COMPVAL_H_RICOMP_SHIFT)) & RIT_COMPVAL_H_RICOMP_MASK)
/*! @} */

/*! @name MASK_H - Mask MSB register. This register holds the 16 MSBs of the mask value. A 1 written to any bit will force a compare on the corresponding bit of the counter and compare register. */
/*! @{ */

#define RIT_MASK_H_RIMASK_MASK                   (0xFFFFU)
#define RIT_MASK_H_RIMASK_SHIFT                  (0U)
/*! RIMASK - Mask register. This register holds the 16 MSBs of the mask value. A one written to any
 *    bit overrides the result of the comparison for the corresponding bit of the counter and
 *    compare register (causes the comparison of the register bits to be always true).
 */
#define RIT_MASK_H_RIMASK(x)                     (((uint32_t)(((uint32_t)(x)) << RIT_MASK_H_RIMASK_SHIFT)) & RIT_MASK_H_RIMASK_MASK)
/*! @} */

/*! @name COUNTER_H - Counter MSB register. 16 MSBs of the counter. */
/*! @{ */

#define RIT_COUNTER_H_RICOUNTER_MASK             (0xFFFFU)
#define RIT_COUNTER_H_RICOUNTER_SHIFT            (0U)
/*! RICOUNTER - 16 LSBs of the up counter. Counts continuously unless RITEN bit in RICTRL register
 *    is cleared or debug mode is entered (if enabled by the RITNEBR bit in RICTRL). Can be loaded to
 *    any value in software.
 */
#define RIT_COUNTER_H_RICOUNTER(x)               (((uint32_t)(((uint32_t)(x)) << RIT_COUNTER_H_RICOUNTER_SHIFT)) & RIT_COUNTER_H_RICOUNTER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RIT_Register_Masks */


/*!
 * @}
 */ /* end of group RIT_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* RIT_H_ */

