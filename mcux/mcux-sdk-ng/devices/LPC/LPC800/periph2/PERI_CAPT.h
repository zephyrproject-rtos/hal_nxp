/*
** ###################################################################
**     Processors:          LPC844M201JBD48
**                          LPC844M201JBD64
**                          LPC844M201JHI33
**                          LPC844M201JHI48
**                          LPC845M301JBD48
**                          LPC845M301JBD64
**                          LPC845M301JHI33
**                          LPC845M301JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CAPT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CAPT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CAPT
 *
 * CMSIS Peripheral Access Layer for CAPT
 */

#if !defined(PERI_CAPT_H_)
#define PERI_CAPT_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC844M201JBD48) || defined(CPU_LPC844M201JBD64) || defined(CPU_LPC844M201JHI33) || defined(CPU_LPC844M201JHI48))
#include "LPC844_COMMON.h"
#elif (defined(CPU_LPC845M301JBD48) || defined(CPU_LPC845M301JBD64) || defined(CPU_LPC845M301JHI33) || defined(CPU_LPC845M301JHI48))
#include "LPC845_COMMON.h"
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
   -- CAPT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAPT_Peripheral_Access_Layer CAPT Peripheral Access Layer
 * @{
 */

/** CAPT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Configuration and control to setup the functional clock, the rules, and the pin selections and rules., offset: 0x0 */
  __IO uint32_t STATUS;                            /**< Status from triggers and time-outs including if in a poll now. Some are used for interrupts., offset: 0x4 */
  __IO uint32_t POLL_TCNT;                         /**< This sets up the polling counter and measurement counter rules., offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t INTENSET;                          /**< Interrupt enable, offset: 0x10 */
  __IO uint32_t INTENCLR;                          /**< Interrupt enable clear, offset: 0x14 */
  __I  uint32_t INTSTAT;                           /**< Interrupt status (mask of STATUS and INTEN), offset: 0x18 */
       uint8_t RESERVED_1[4];
  __I  uint32_t TOUCH;                             /**< Last touch event (touch or no-touch) in context., offset: 0x20 */
       uint8_t RESERVED_2[4056];
  __I  uint32_t ID;                                /**< Block ID, offset: 0xFFC */
} CAPT_Type;

/* ----------------------------------------------------------------------------
   -- CAPT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAPT_Register_Masks CAPT Register Masks
 * @{
 */

/*! @name CTRL - Configuration and control to setup the functional clock, the rules, and the pin selections and rules. */
/*! @{ */

#define CAPT_CTRL_POLLMODE_MASK                  (0x3U)
#define CAPT_CTRL_POLLMODE_SHIFT                 (0U)
/*! POLLMODE - Mode of operation. May only change from 0 to another value. So, if 2 or 3, must be
 *    changed to 0 1st. Any attempt to go from non-0 to non-0 will result in 0 anyway.
 *  0b00..None, inactive. Poll and time counters are turned off. Writing this will reset state and stop any
 *        collection in progress. Note: this has no effect on STATUS - those must be cleared manually.
 *  0b01..Poll now - forces a manual poll to be started immediately, using XPINSEL X pin(s) to activate in the
 *        integration loop (all pins set together). Self clears - clear is not indication it is done (see STATUS).
 *  0b10..Normal polling using poll delay from POLL_TCNT register. This will start with the poll delay (which can be 0).
 *  0b11..The CAPT block will operate in low-power mode. This means it will use GPIO as input, use combination
 *        touch measurements, and assume it is to wake the system. This will use the POLL_TCNT poll delay, and start
 *        with the delay.
 */
#define CAPT_CTRL_POLLMODE(x)                    (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_POLLMODE_SHIFT)) & CAPT_CTRL_POLLMODE_MASK)

#define CAPT_CTRL_TYPE_MASK                      (0xCU)
#define CAPT_CTRL_TYPE_SHIFT                     (2U)
/*! TYPE - Selects type of Touch arrangement to use and so how to handle XPINSEL bits
 *  0b00..Normal - all X elements are treated as normal, such as buttons and sliders.
 *  0b01..3x3 grid using NXP Complementary measurements. The 1st 9 Xs are assumed to be the 3x3 grid. After that
 *        would be normal X elements. This will also allow 3x1 and 3x2 Note: Only possible if XMAX in STATUS is >=8
 *  0b10..5 Sensors interleaved to act as 3x3 touch area using NXP Complementary measurements. 1st 5 Xs used for
 *        this, all remaining are treated as normal. Note that if 16 X pins allowed, the 16th will not be usable
 *        when TYPE=1. (use TYPE=0 and select 1 smaller than 15 ( and any others from 1 smaller than 5 on up in
 *        XPINSEL).
 *  0b11..9 Sensors interleaved to act as 5x5 touch area using NXP Complementary measurements. 1st 9 Xs used for
 *        this, all remaining are treated as normal. Note: Only possible if XMAX in STATUS is >=8
 */
#define CAPT_CTRL_TYPE(x)                        (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_TYPE_SHIFT)) & CAPT_CTRL_TYPE_MASK)

#define CAPT_CTRL_TRIGGER_MASK                   (0x10U)
#define CAPT_CTRL_TRIGGER_SHIFT                  (4U)
/*! TRIGGER - This selects what is being used as the trigger
 *  0b0..Uses YH GPIO. This is not normally used except in Low-power mode. But, it can be used with POLLNOW to baseline that measurement.
 *  0b1..ACMP (if fitted). This assumes the ACMP state is fed in asynchronously and it will sample.
 */
#define CAPT_CTRL_TRIGGER(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_TRIGGER_SHIFT)) & CAPT_CTRL_TRIGGER_MASK)

#define CAPT_CTRL_WAIT_MASK                      (0x20U)
#define CAPT_CTRL_WAIT_SHIFT                     (5U)
/*! WAIT - If 0, the block will continue its X based measurements, even if the TOUCH register has
 *    not been read (and so could OVERRUN). If 1, it will wait until read when a touch (TOUCH's
 *    ISTOUCH bit is set) before starting the next. This should not normally be needed.
 */
#define CAPT_CTRL_WAIT(x)                        (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_WAIT_SHIFT)) & CAPT_CTRL_WAIT_MASK)

#define CAPT_CTRL_DMA_MASK                       (0xC0U)
#define CAPT_CTRL_DMA_SHIFT                      (6U)
/*! DMA - If not 0, will use the DMA to read out touch events from TOUCH register. The values are
 *    shown below. This may be changed while active.
 *  0b00..No DMA. Application will use ISRs to read out data
 *  0b01..Trigger DMA on Touch events
 *  0b10..Trigger DMA on both Touch and No-Touch events
 *  0b11..Trigger DMA on both plus Timeout.
 */
#define CAPT_CTRL_DMA(x)                         (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_DMA_SHIFT)) & CAPT_CTRL_DMA_MASK)

#define CAPT_CTRL_FDIV_MASK                      (0xF00U)
#define CAPT_CTRL_FDIV_SHIFT                     (8U)
/*! FDIV - Functional clock divider, or 0 if no divide. The term "clocks" in this spec then refer to
 *    divided clocks. For a 12MHz input (e.g. FRO 12MHz), this would normally be set to generate a
 *    4MHz output (so, 2). For a 1MHz input, it should be 0. Note for internal use: this does not
 *    produce a 50/50 duty cycle when non even divide.
 *  0b0000..No divide
 *  0b0001../2
 *  0b0010../3
 *  0b0011../4
 *  0b0100../5
 *  0b0101../6
 *  0b0111../(FDIV+1)
 *  0b1000../(FDIV+1)
 *  0b1001../(FDIV+1)
 *  0b1010../(FDIV+1)
 *  0b1011../(FDIV+1)
 *  0b1100../(FDIV+1)
 *  0b1101../(FDIV+1)
 *  0b1110../(FDIV+1)
 *  0b1111../(FDIV+1)
 */
#define CAPT_CTRL_FDIV(x)                        (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_FDIV_SHIFT)) & CAPT_CTRL_FDIV_MASK)

#define CAPT_CTRL_XPINUSE_MASK                   (0x3000U)
#define CAPT_CTRL_XPINUSE_SHIFT                  (12U)
/*! XPINUSE - Controls how X pins selected in XPINSEL are used when not active in the current polling round.
 *  0b00..Normal mode. Each inactive X pin is Hi-Z.
 *  0b01..Ground mode. Each inactive X pin is Low
 */
#define CAPT_CTRL_XPINUSE(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_XPINUSE_SHIFT)) & CAPT_CTRL_XPINUSE_MASK)

#define CAPT_CTRL_INCHANGE_MASK                  (0x8000U)
#define CAPT_CTRL_INCHANGE_SHIFT                 (15U)
/*! INCHANGE - If 1, do not attempt to write to this register again. This means the last change has
 *    not been propagated. This can only happen after changing POLLMODE and DMA. Worse case time
 *    would be based on divided FCLK.
 */
#define CAPT_CTRL_INCHANGE(x)                    (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_INCHANGE_SHIFT)) & CAPT_CTRL_INCHANGE_MASK)

#define CAPT_CTRL_XPINSEL_MASK                   (0xFFFF0000U)
#define CAPT_CTRL_XPINSEL_SHIFT                  (16U)
/*! XPINSEL - Selects which of the X pins are to be used within the allowed pins - see XMAX in
 *    STATUS. The X pins are mapped via the IOCON (as are the YH and YL pins) to physical pads. So, this
 *    only selects which are to be used as the X half of the touch element. Note: when polling,
 *    these are "walked" (active) one at a time. When using POLLNOW, the 1 or more selected are used at
 *    the same time. Likewise, when in low-power mode, they are used at the same time (or small
 *    groups). X pads not selected by XPINSEL are kept at High-Z if they are connected to a pad. This
 *    allows using controlled sets for touch detection based on context.
 */
#define CAPT_CTRL_XPINSEL(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_CTRL_XPINSEL_SHIFT)) & CAPT_CTRL_XPINSEL_MASK)
/*! @} */

/*! @name STATUS - Status from triggers and time-outs including if in a poll now. Some are used for interrupts. */
/*! @{ */

#define CAPT_STATUS_YESTOUCH_MASK                (0x1U)
#define CAPT_STATUS_YESTOUCH_SHIFT               (0U)
/*! YESTOUCH - Is 1 if a touch has been detected, including a wakeup from low-power mode. */
#define CAPT_STATUS_YESTOUCH(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_YESTOUCH_SHIFT)) & CAPT_STATUS_YESTOUCH_MASK)

#define CAPT_STATUS_NOTOUCH_MASK                 (0x2U)
#define CAPT_STATUS_NOTOUCH_SHIFT                (1U)
/*! NOTOUCH - Is 1 if a no-touch has been detected (ie. completed an integration cycle and found
 *    no-touch). This is not set when in low-power mode.
 */
#define CAPT_STATUS_NOTOUCH(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_NOTOUCH_SHIFT)) & CAPT_STATUS_NOTOUCH_MASK)

#define CAPT_STATUS_POLLDONE_MASK                (0x4U)
#define CAPT_STATUS_POLLDONE_SHIFT               (2U)
/*! POLLDONE - Is 1 if a poll or POLLNOW is complete. */
#define CAPT_STATUS_POLLDONE(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_POLLDONE_SHIFT)) & CAPT_STATUS_POLLDONE_MASK)

#define CAPT_STATUS_TIMEOUT_MASK                 (0x8U)
#define CAPT_STATUS_TIMEOUT_SHIFT                (3U)
/*! TIMEOUT - Is 1 if an integration cycle ended with a timeout (should not happen). */
#define CAPT_STATUS_TIMEOUT(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_TIMEOUT_SHIFT)) & CAPT_STATUS_TIMEOUT_MASK)

#define CAPT_STATUS_OVERUN_MASK                  (0x10U)
#define CAPT_STATUS_OVERUN_SHIFT                 (4U)
/*! OVERUN - Is 1 if new data was collected before application read out previous ISTOUCH. No-touch
 *    (ISTOUCH==0) data will be silently overrun. Is not possible if WAIT=1.
 */
#define CAPT_STATUS_OVERUN(x)                    (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_OVERUN_SHIFT)) & CAPT_STATUS_OVERUN_MASK)

#define CAPT_STATUS_BUSY_MASK                    (0x100U)
#define CAPT_STATUS_BUSY_SHIFT                   (8U)
/*! BUSY - In a poll now. */
#define CAPT_STATUS_BUSY(x)                      (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_BUSY_SHIFT)) & CAPT_STATUS_BUSY_MASK)

#define CAPT_STATUS_XMAX_MASK                    (0xF0000U)
#define CAPT_STATUS_XMAX_SHIFT                   (16U)
/*! XMAX - Indicates the maximum number of X pins allowed 0-relative. So, 15 means there are pins 0
 *    to 15, or 16 total X pins. INTERNAL note: this may be setup to be written by ROM boot.
 */
#define CAPT_STATUS_XMAX(x)                      (((uint32_t)(((uint32_t)(x)) << CAPT_STATUS_XMAX_SHIFT)) & CAPT_STATUS_XMAX_MASK)
/*! @} */

/*! @name POLL_TCNT - This sets up the polling counter and measurement counter rules. */
/*! @{ */

#define CAPT_POLL_TCNT_TCNT_MASK                 (0xFFFU)
#define CAPT_POLL_TCNT_TCNT_SHIFT                (0U)
/*! TCNT - Sets the threshold between touch and no-touch count. If not used, then the block will
 *    treat all events as touch or no-touch, depending whether at max or min. This is in terms of
 *    divided FCLK. If the comparator triggers it is no-touch; if bigger than TCNT counts, it is a touch
 *    event.
 */
#define CAPT_POLL_TCNT_TCNT(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_TCNT_SHIFT)) & CAPT_POLL_TCNT_TCNT_MASK)

#define CAPT_POLL_TCNT_TOUT_MASK                 (0xF000U)
#define CAPT_POLL_TCNT_TOUT_SHIFT                (12U)
/*! TOUT - Time-out count expressed as 1 is smaller than TOUT, allowing for up to 12 bits. Must be
 *    less than 13. So, for example, 1 is smaller than 12=4096 counts; if TOUT=12, then if 4096
 *    counts occur without a trigger, it is a time-out. This should be set to be large enough above TCNT
 *    to prevent timeout invalidly.
 */
#define CAPT_POLL_TCNT_TOUT(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_TOUT_SHIFT)) & CAPT_POLL_TCNT_TOUT_MASK)

#define CAPT_POLL_TCNT_POLL_MASK                 (0xFF0000U)
#define CAPT_POLL_TCNT_POLL_SHIFT                (16U)
/*! POLL - Poll counter in (internal) 12-bit counter wraparounds (loosely 1msec), so related to
 *    divided FCLK. This expresses time delay between measurement cycles (ie. after one set of X
 *    measurements, time before starting next). This count is used to delay before the next set of
 *    measurements. Measuring too often wastes power and does not add value since movement of fingers is
 *    relatively slow. For low power mode, this must allow for the clock being used (e.g. a 1MHz osc)
 *    so 12 bit count will be potentially much longer. That means, lowering the count to get the
 *    reasonable delay period.
 */
#define CAPT_POLL_TCNT_POLL(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_POLL_SHIFT)) & CAPT_POLL_TCNT_POLL_MASK)

#define CAPT_POLL_TCNT_MDELAY_MASK               (0x3000000U)
#define CAPT_POLL_TCNT_MDELAY_SHIFT              (24U)
/*! MDELAY - If not 0, this selects the number of divided FCLKs to wait after entry of measurement
 *    mode before deciding if has triggered. This gives the ACMP time to react to the transferred
 *    charge. It is used as 1+(1 smaller than MDELAY), , so between 2 and 8 ticks of the divided FCLK
 *    added during the measurement.
 */
#define CAPT_POLL_TCNT_MDELAY(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_MDELAY_SHIFT)) & CAPT_POLL_TCNT_MDELAY_MASK)

#define CAPT_POLL_TCNT_RDELAY_MASK               (0xC000000U)
#define CAPT_POLL_TCNT_RDELAY_SHIFT              (26U)
/*! RDELAY - If not 0, this is the number of divided FCLKs to hold in Step 0 'Reset' state (draining
 *    capacitance). It is used as (1 is smaller than RDELAY), so between 2 and 8 ticks of the
 *    divided FCLK added to the 'Reset' state.
 */
#define CAPT_POLL_TCNT_RDELAY(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_RDELAY_SHIFT)) & CAPT_POLL_TCNT_RDELAY_MASK)

#define CAPT_POLL_TCNT_TCHLOW_ER_MASK            (0x80000000U)
#define CAPT_POLL_TCNT_TCHLOW_ER_SHIFT           (31U)
/*! TCHLOW_ER - If 1, then the touch/no-touch boundary of TCNT is reversed. In a floating system
 *    (most common), the no-touch case triggers at a lower count vs. touch; this is due to touch
 *    drawing off charge. In a grounded system, the reverse is true and the touch adds to the charge and
 *    so touch is a lower count. In a system which can switch between grounded and non-grounded, the
 *    SW will check for all of the Xs looking like they have been touched and reverse the setting of
 *    this bit. This should only be changed between polls.
 */
#define CAPT_POLL_TCNT_TCHLOW_ER(x)              (((uint32_t)(((uint32_t)(x)) << CAPT_POLL_TCNT_TCHLOW_ER_SHIFT)) & CAPT_POLL_TCNT_TCHLOW_ER_MASK)
/*! @} */

/*! @name INTENSET - Interrupt enable */
/*! @{ */

#define CAPT_INTENSET_YESTOUCH_MASK              (0x1U)
#define CAPT_INTENSET_YESTOUCH_SHIFT             (0U)
/*! YESTOUCH - Is 1 if a touch detected should interrupt. This includes wake from low-power mode. */
#define CAPT_INTENSET_YESTOUCH(x)                (((uint32_t)(((uint32_t)(x)) << CAPT_INTENSET_YESTOUCH_SHIFT)) & CAPT_INTENSET_YESTOUCH_MASK)

#define CAPT_INTENSET_NOTOUCH_MASK               (0x2U)
#define CAPT_INTENSET_NOTOUCH_SHIFT              (1U)
/*! NOTOUCH - Is 1 if a no-touch detected should interrupt */
#define CAPT_INTENSET_NOTOUCH(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTENSET_NOTOUCH_SHIFT)) & CAPT_INTENSET_NOTOUCH_MASK)

#define CAPT_INTENSET_POLLDONE_MASK              (0x4U)
#define CAPT_INTENSET_POLLDONE_SHIFT             (2U)
/*! POLLDONE - Is 1 if a poll or POLLNOW completing should interrupt */
#define CAPT_INTENSET_POLLDONE(x)                (((uint32_t)(((uint32_t)(x)) << CAPT_INTENSET_POLLDONE_SHIFT)) & CAPT_INTENSET_POLLDONE_MASK)

#define CAPT_INTENSET_TIMEOUT_MASK               (0x8U)
#define CAPT_INTENSET_TIMEOUT_SHIFT              (3U)
/*! TIMEOUT - Is 1 if an integration cycle ending with timeout should interrupt */
#define CAPT_INTENSET_TIMEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTENSET_TIMEOUT_SHIFT)) & CAPT_INTENSET_TIMEOUT_MASK)

#define CAPT_INTENSET_OVERUN_MASK                (0x10U)
#define CAPT_INTENSET_OVERUN_SHIFT               (4U)
/*! OVERUN - Is 1 if an overrun should interrupt. */
#define CAPT_INTENSET_OVERUN(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_INTENSET_OVERUN_SHIFT)) & CAPT_INTENSET_OVERUN_MASK)
/*! @} */

/*! @name INTENCLR - Interrupt enable clear */
/*! @{ */

#define CAPT_INTENCLR_YESTOUCH_MASK              (0x1U)
#define CAPT_INTENCLR_YESTOUCH_SHIFT             (0U)
/*! YESTOUCH - clear the touch interrupt */
#define CAPT_INTENCLR_YESTOUCH(x)                (((uint32_t)(((uint32_t)(x)) << CAPT_INTENCLR_YESTOUCH_SHIFT)) & CAPT_INTENCLR_YESTOUCH_MASK)

#define CAPT_INTENCLR_NOTOUCH_MASK               (0x2U)
#define CAPT_INTENCLR_NOTOUCH_SHIFT              (1U)
/*! NOTOUCH - clear the no-touch interrupt */
#define CAPT_INTENCLR_NOTOUCH(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTENCLR_NOTOUCH_SHIFT)) & CAPT_INTENCLR_NOTOUCH_MASK)

#define CAPT_INTENCLR_POLLDONE_MASK              (0x4U)
#define CAPT_INTENCLR_POLLDONE_SHIFT             (2U)
/*! POLLDONE - clear the poll or POLLNOW completing interrupt */
#define CAPT_INTENCLR_POLLDONE(x)                (((uint32_t)(((uint32_t)(x)) << CAPT_INTENCLR_POLLDONE_SHIFT)) & CAPT_INTENCLR_POLLDONE_MASK)

#define CAPT_INTENCLR_TIMEOUT_MASK               (0x8U)
#define CAPT_INTENCLR_TIMEOUT_SHIFT              (3U)
/*! TIMEOUT - clear the timeout interrupt */
#define CAPT_INTENCLR_TIMEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTENCLR_TIMEOUT_SHIFT)) & CAPT_INTENCLR_TIMEOUT_MASK)

#define CAPT_INTENCLR_OVERUN_MASK                (0x10U)
#define CAPT_INTENCLR_OVERUN_SHIFT               (4U)
/*! OVERUN - clear the overrun interrupt */
#define CAPT_INTENCLR_OVERUN(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_INTENCLR_OVERUN_SHIFT)) & CAPT_INTENCLR_OVERUN_MASK)
/*! @} */

/*! @name INTSTAT - Interrupt status (mask of STATUS and INTEN) */
/*! @{ */

#define CAPT_INTSTAT_YESTOUCH_MASK               (0x1U)
#define CAPT_INTSTAT_YESTOUCH_SHIFT              (0U)
/*! YESTOUCH - the status of touch interrrupt */
#define CAPT_INTSTAT_YESTOUCH(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTSTAT_YESTOUCH_SHIFT)) & CAPT_INTSTAT_YESTOUCH_MASK)

#define CAPT_INTSTAT_NOTOUCH_MASK                (0x2U)
#define CAPT_INTSTAT_NOTOUCH_SHIFT               (1U)
/*! NOTOUCH - the status of no-touch interrrupt */
#define CAPT_INTSTAT_NOTOUCH(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_INTSTAT_NOTOUCH_SHIFT)) & CAPT_INTSTAT_NOTOUCH_MASK)

#define CAPT_INTSTAT_POLLDONE_MASK               (0x4U)
#define CAPT_INTSTAT_POLLDONE_SHIFT              (2U)
/*! POLLDONE - the status of poll or pollnow completing interrupt */
#define CAPT_INTSTAT_POLLDONE(x)                 (((uint32_t)(((uint32_t)(x)) << CAPT_INTSTAT_POLLDONE_SHIFT)) & CAPT_INTSTAT_POLLDONE_MASK)

#define CAPT_INTSTAT_TIMEOUT_MASK                (0x8U)
#define CAPT_INTSTAT_TIMEOUT_SHIFT               (3U)
/*! TIMEOUT - the status of timeout interrupt */
#define CAPT_INTSTAT_TIMEOUT(x)                  (((uint32_t)(((uint32_t)(x)) << CAPT_INTSTAT_TIMEOUT_SHIFT)) & CAPT_INTSTAT_TIMEOUT_MASK)

#define CAPT_INTSTAT_OVERUN_MASK                 (0x10U)
#define CAPT_INTSTAT_OVERUN_SHIFT                (4U)
/*! OVERUN - the status of overrun interrupt */
#define CAPT_INTSTAT_OVERUN(x)                   (((uint32_t)(((uint32_t)(x)) << CAPT_INTSTAT_OVERUN_SHIFT)) & CAPT_INTSTAT_OVERUN_MASK)
/*! @} */

/*! @name TOUCH - Last touch event (touch or no-touch) in context. */
/*! @{ */

#define CAPT_TOUCH_COUNT_MASK                    (0xFFFU)
#define CAPT_TOUCH_COUNT_SHIFT                   (0U)
/*! COUNT - Count value reached at trigger. If timeout, will be (1 bigger than TOUT)-1; e.g. if TOUT=12, then 0xFFF. */
#define CAPT_TOUCH_COUNT(x)                      (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_COUNT_SHIFT)) & CAPT_TOUCH_COUNT_MASK)

#define CAPT_TOUCH_XVAL_MASK                     (0xF000U)
#define CAPT_TOUCH_XVAL_SHIFT                    (12U)
/*! XVAL - Is the X that triggered this, or lowest X if more than one. */
#define CAPT_TOUCH_XVAL(x)                       (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_XVAL_SHIFT)) & CAPT_TOUCH_XVAL_MASK)

#define CAPT_TOUCH_ISTOUCH_MASK                  (0x10000U)
#define CAPT_TOUCH_ISTOUCH_SHIFT                 (16U)
/*! ISTOUCH - 1 if is Touch (by count) or 0 if is no-touch. */
#define CAPT_TOUCH_ISTOUCH(x)                    (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_ISTOUCH_SHIFT)) & CAPT_TOUCH_ISTOUCH_MASK)

#define CAPT_TOUCH_ISTO_MASK                     (0x20000U)
#define CAPT_TOUCH_ISTO_SHIFT                    (17U)
/*! ISTO - 1 if is Timeout. */
#define CAPT_TOUCH_ISTO(x)                       (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_ISTO_SHIFT)) & CAPT_TOUCH_ISTO_MASK)

#define CAPT_TOUCH_SEQ_MASK                      (0xF00000U)
#define CAPT_TOUCH_SEQ_SHIFT                     (20U)
/*! SEQ - Sequence number - rolling counter of polls. Changes after all selected Xs per poll (so, 0
 *    for 1st set of Xs, then 1 for next set, etc).
 */
#define CAPT_TOUCH_SEQ(x)                        (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_SEQ_SHIFT)) & CAPT_TOUCH_SEQ_MASK)

#define CAPT_TOUCH_CHANGE_MASK                   (0x80000000U)
#define CAPT_TOUCH_CHANGE_SHIFT                  (31U)
/*! CHANGE - If 1, the rest of the register is 0 because the data is changing. This will only happen
 *    for 1 cycle and would never happen if using interrupts to read, unless took so long as to
 *    overrun.
 */
#define CAPT_TOUCH_CHANGE(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_TOUCH_CHANGE_SHIFT)) & CAPT_TOUCH_CHANGE_MASK)
/*! @} */

/*! @name ID - Block ID */
/*! @{ */

#define CAPT_ID_APERTURE_MASK                    (0xFFU)
#define CAPT_ID_APERTURE_SHIFT                   (0U)
/*! APERTURE - Aperture: encoded as (aperture size/4K) -1, so 0x00 is a 4 K aperture. */
#define CAPT_ID_APERTURE(x)                      (((uint32_t)(((uint32_t)(x)) << CAPT_ID_APERTURE_SHIFT)) & CAPT_ID_APERTURE_MASK)

#define CAPT_ID_MINOR_REV_MASK                   (0xF00U)
#define CAPT_ID_MINOR_REV_SHIFT                  (8U)
/*! MINOR_REV - Minor revision of module implementation, starting at 0. Software compatibility is expected between minor revisions. */
#define CAPT_ID_MINOR_REV(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_ID_MINOR_REV_SHIFT)) & CAPT_ID_MINOR_REV_MASK)

#define CAPT_ID_MAJOR_REV_MASK                   (0xF000U)
#define CAPT_ID_MAJOR_REV_SHIFT                  (12U)
/*! MAJOR_REV - Major revision of module implementation, starting at 0. There may not be software compatibility between major revisions. */
#define CAPT_ID_MAJOR_REV(x)                     (((uint32_t)(((uint32_t)(x)) << CAPT_ID_MAJOR_REV_SHIFT)) & CAPT_ID_MAJOR_REV_MASK)

#define CAPT_ID_ID_MASK                          (0xFFFF0000U)
#define CAPT_ID_ID_SHIFT                         (16U)
/*! ID - 1 if is Timeout. */
#define CAPT_ID_ID(x)                            (((uint32_t)(((uint32_t)(x)) << CAPT_ID_ID_SHIFT)) & CAPT_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAPT_Register_Masks */


/*!
 * @}
 */ /* end of group CAPT_Peripheral_Access_Layer */


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


#endif  /* PERI_CAPT_H_ */

