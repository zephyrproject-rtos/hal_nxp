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
**         CMSIS Peripheral Access Layer for USBDCD
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
 * @file USBDCD.h
 * @version 2.0
 * @date 2015-01-06
 * @brief CMSIS Peripheral Access Layer for USBDCD
 *
 * CMSIS Peripheral Access Layer for USBDCD
 */

#if !defined(USBDCD_H_)
#define USBDCD_H_                                /**< Symbol preventing repeated inclusion */

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
   -- USBDCD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBDCD_Peripheral_Access_Layer USBDCD Peripheral Access Layer
 * @{
 */

/** USBDCD - Register Layout Typedef */
typedef struct {
  __IO uint32_t CONTROL;                           /**< Control register, offset: 0x0 */
  __IO uint32_t CLOCK;                             /**< Clock register, offset: 0x4 */
  __I  uint32_t STATUS;                            /**< Status register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t TIMER0;                            /**< TIMER0 register, offset: 0x10 */
  __IO uint32_t TIMER1;                            /**< TIMER1 register, offset: 0x14 */
  __IO uint32_t TIMER2;                            /**< TIMER2 register, offset: 0x18 */
} USBDCD_Type;

/* ----------------------------------------------------------------------------
   -- USBDCD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBDCD_Register_Masks USBDCD Register Masks
 * @{
 */

/*! @name CONTROL - Control register */
/*! @{ */

#define USBDCD_CONTROL_IACK_MASK                 (0x1U)
#define USBDCD_CONTROL_IACK_SHIFT                (0U)
/*! IACK - Interrupt Acknowledge
 *  0b0..Do not clear the interrupt.
 *  0b1..Clear the IF bit (interrupt flag).
 */
#define USBDCD_CONTROL_IACK(x)                   (((uint32_t)(((uint32_t)(x)) << USBDCD_CONTROL_IACK_SHIFT)) & USBDCD_CONTROL_IACK_MASK)

#define USBDCD_CONTROL_IF_MASK                   (0x100U)
#define USBDCD_CONTROL_IF_SHIFT                  (8U)
/*! IF - Interrupt Flag
 *  0b0..No interrupt is pending.
 *  0b1..An interrupt is pending.
 */
#define USBDCD_CONTROL_IF(x)                     (((uint32_t)(((uint32_t)(x)) << USBDCD_CONTROL_IF_SHIFT)) & USBDCD_CONTROL_IF_MASK)

#define USBDCD_CONTROL_IE_MASK                   (0x10000U)
#define USBDCD_CONTROL_IE_SHIFT                  (16U)
/*! IE - Interrupt Enable
 *  0b0..Disable interrupts to the system.
 *  0b1..Enable interrupts to the system.
 */
#define USBDCD_CONTROL_IE(x)                     (((uint32_t)(((uint32_t)(x)) << USBDCD_CONTROL_IE_SHIFT)) & USBDCD_CONTROL_IE_MASK)

#define USBDCD_CONTROL_START_MASK                (0x1000000U)
#define USBDCD_CONTROL_START_SHIFT               (24U)
/*! START - Start Change Detection Sequence
 *  0b0..Do not start the sequence. Writes of this value have no effect.
 *  0b1..Initiate the charger detection sequence. If the sequence is already running, writes of this value have no effect.
 */
#define USBDCD_CONTROL_START(x)                  (((uint32_t)(((uint32_t)(x)) << USBDCD_CONTROL_START_SHIFT)) & USBDCD_CONTROL_START_MASK)

#define USBDCD_CONTROL_SR_MASK                   (0x2000000U)
#define USBDCD_CONTROL_SR_SHIFT                  (25U)
/*! SR - Software Reset
 *  0b0..Do not perform a software reset.
 *  0b1..Perform a software reset.
 */
#define USBDCD_CONTROL_SR(x)                     (((uint32_t)(((uint32_t)(x)) << USBDCD_CONTROL_SR_SHIFT)) & USBDCD_CONTROL_SR_MASK)
/*! @} */

/*! @name CLOCK - Clock register */
/*! @{ */

#define USBDCD_CLOCK_CLOCK_UNIT_MASK             (0x1U)
#define USBDCD_CLOCK_CLOCK_UNIT_SHIFT            (0U)
/*! CLOCK_UNIT - Unit of Measurement Encoding for Clock Speed
 *  0b0..kHz Speed (between 1 kHz and 1023 kHz)
 *  0b1..MHz Speed (between 1 MHz and 1023 MHz)
 */
#define USBDCD_CLOCK_CLOCK_UNIT(x)               (((uint32_t)(((uint32_t)(x)) << USBDCD_CLOCK_CLOCK_UNIT_SHIFT)) & USBDCD_CLOCK_CLOCK_UNIT_MASK)

#define USBDCD_CLOCK_CLOCK_SPEED_MASK            (0xFFCU)
#define USBDCD_CLOCK_CLOCK_SPEED_SHIFT           (2U)
/*! CLOCK_SPEED - Numerical Value of Clock Speed in Binary */
#define USBDCD_CLOCK_CLOCK_SPEED(x)              (((uint32_t)(((uint32_t)(x)) << USBDCD_CLOCK_CLOCK_SPEED_SHIFT)) & USBDCD_CLOCK_CLOCK_SPEED_MASK)
/*! @} */

/*! @name STATUS - Status register */
/*! @{ */

#define USBDCD_STATUS_SEQ_RES_MASK               (0x30000U)
#define USBDCD_STATUS_SEQ_RES_SHIFT              (16U)
/*! SEQ_RES - Charger Detection Sequence Results
 *  0b00..No results to report.
 *  0b01..Attached to a standard host. Must comply with USB 2.0 by drawing only 2.5 mA (max) until connected.
 *  0b10..Attached to a charging port. The exact meaning depends on bit 18: 0: Attached to either a charging host
 *        or a dedicated charger. The charger type detection has not completed. 1: Attached to a charging host. The
 *        charger type detection has completed.
 *  0b11..Attached to a dedicated charger.
 */
#define USBDCD_STATUS_SEQ_RES(x)                 (((uint32_t)(((uint32_t)(x)) << USBDCD_STATUS_SEQ_RES_SHIFT)) & USBDCD_STATUS_SEQ_RES_MASK)

#define USBDCD_STATUS_SEQ_STAT_MASK              (0xC0000U)
#define USBDCD_STATUS_SEQ_STAT_SHIFT             (18U)
/*! SEQ_STAT - Charger Detection Sequence Status
 *  0b00..The module is either not enabled, or the module is enabled but the data pins have not yet been detected.
 *  0b01..Data pin contact detection is complete.
 *  0b10..Charging port detection is complete.
 *  0b11..Charger type detection is complete.
 */
#define USBDCD_STATUS_SEQ_STAT(x)                (((uint32_t)(((uint32_t)(x)) << USBDCD_STATUS_SEQ_STAT_SHIFT)) & USBDCD_STATUS_SEQ_STAT_MASK)

#define USBDCD_STATUS_ERR_MASK                   (0x100000U)
#define USBDCD_STATUS_ERR_SHIFT                  (20U)
/*! ERR - Error Flag
 *  0b0..No sequence errors.
 *  0b1..Error in the detection sequence. See the SEQ_STAT field to determine the phase in which the error occurred.
 */
#define USBDCD_STATUS_ERR(x)                     (((uint32_t)(((uint32_t)(x)) << USBDCD_STATUS_ERR_SHIFT)) & USBDCD_STATUS_ERR_MASK)

#define USBDCD_STATUS_TO_MASK                    (0x200000U)
#define USBDCD_STATUS_TO_SHIFT                   (21U)
/*! TO - Timeout Flag
 *  0b0..The detection sequence has not been running for over 1 s.
 *  0b1..It has been over 1 s since the data pin contact was detected and debounced.
 */
#define USBDCD_STATUS_TO(x)                      (((uint32_t)(((uint32_t)(x)) << USBDCD_STATUS_TO_SHIFT)) & USBDCD_STATUS_TO_MASK)

#define USBDCD_STATUS_ACTIVE_MASK                (0x400000U)
#define USBDCD_STATUS_ACTIVE_SHIFT               (22U)
/*! ACTIVE - Active Status Indicator
 *  0b0..The sequence is not running.
 *  0b1..The sequence is running.
 */
#define USBDCD_STATUS_ACTIVE(x)                  (((uint32_t)(((uint32_t)(x)) << USBDCD_STATUS_ACTIVE_SHIFT)) & USBDCD_STATUS_ACTIVE_MASK)
/*! @} */

/*! @name TIMER0 - TIMER0 register */
/*! @{ */

#define USBDCD_TIMER0_TUNITCON_MASK              (0xFFFU)
#define USBDCD_TIMER0_TUNITCON_SHIFT             (0U)
/*! TUNITCON - Unit Connection Timer Elapse (in ms) */
#define USBDCD_TIMER0_TUNITCON(x)                (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER0_TUNITCON_SHIFT)) & USBDCD_TIMER0_TUNITCON_MASK)

#define USBDCD_TIMER0_TSEQ_INIT_MASK             (0x3FF0000U)
#define USBDCD_TIMER0_TSEQ_INIT_SHIFT            (16U)
/*! TSEQ_INIT - Sequence Initiation Time */
#define USBDCD_TIMER0_TSEQ_INIT(x)               (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER0_TSEQ_INIT_SHIFT)) & USBDCD_TIMER0_TSEQ_INIT_MASK)
/*! @} */

/*! @name TIMER1 - TIMER1 register */
/*! @{ */

#define USBDCD_TIMER1_TVDPSRC_ON_MASK            (0x3FFU)
#define USBDCD_TIMER1_TVDPSRC_ON_SHIFT           (0U)
/*! TVDPSRC_ON - Time Period Comparator Enabled */
#define USBDCD_TIMER1_TVDPSRC_ON(x)              (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER1_TVDPSRC_ON_SHIFT)) & USBDCD_TIMER1_TVDPSRC_ON_MASK)

#define USBDCD_TIMER1_TDCD_DBNC_MASK             (0x3FF0000U)
#define USBDCD_TIMER1_TDCD_DBNC_SHIFT            (16U)
/*! TDCD_DBNC - Time Period to Debounce D+ Signal */
#define USBDCD_TIMER1_TDCD_DBNC(x)               (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER1_TDCD_DBNC_SHIFT)) & USBDCD_TIMER1_TDCD_DBNC_MASK)
/*! @} */

/*! @name TIMER2 - TIMER2 register */
/*! @{ */

#define USBDCD_TIMER2_CHECK_DM_MASK              (0xFU)
#define USBDCD_TIMER2_CHECK_DM_SHIFT             (0U)
/*! CHECK_DM - Time Before Check of D- Line */
#define USBDCD_TIMER2_CHECK_DM(x)                (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER2_CHECK_DM_SHIFT)) & USBDCD_TIMER2_CHECK_DM_MASK)

#define USBDCD_TIMER2_TVDPSRC_CON_MASK           (0x3FF0000U)
#define USBDCD_TIMER2_TVDPSRC_CON_SHIFT          (16U)
/*! TVDPSRC_CON - Time Period Before Enabling D+ Pullup */
#define USBDCD_TIMER2_TVDPSRC_CON(x)             (((uint32_t)(((uint32_t)(x)) << USBDCD_TIMER2_TVDPSRC_CON_SHIFT)) & USBDCD_TIMER2_TVDPSRC_CON_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBDCD_Register_Masks */


/*!
 * @}
 */ /* end of group USBDCD_Peripheral_Access_Layer */


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


#endif  /* USBDCD_H_ */

