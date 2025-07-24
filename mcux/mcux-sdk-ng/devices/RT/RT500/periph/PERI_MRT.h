/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MRT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MRT.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MRT
 *
 * CMSIS Peripheral Access Layer for MRT
 */

#if !defined(PERI_MRT_H_)
#define PERI_MRT_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- MRT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRT_Peripheral_Access_Layer MRT Peripheral Access Layer
 * @{
 */

/** MRT - Size of Registers Arrays */
#define MRT_CHANNEL_COUNT                         4u

/** MRT - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10 */
    __IO uint32_t INTVAL;                            /**< Time Interval Value, array offset: 0x0, array step: 0x10 */
    __I  uint32_t TIMER;                             /**< Timer, array offset: 0x4, array step: 0x10 */
    __IO uint32_t CTRL;                              /**< Control, array offset: 0x8, array step: 0x10 */
    __IO uint32_t STAT;                              /**< Status, array offset: 0xC, array step: 0x10 */
  } CHANNEL[MRT_CHANNEL_COUNT];
       uint8_t RESERVED_0[176];
  __IO uint32_t MODCFG;                            /**< Module Configuration, offset: 0xF0 */
  __I  uint32_t IDLE_CH;                           /**< Idle Channel, offset: 0xF4 */
  __IO uint32_t IRQ_FLAG;                          /**< Global Interrupt Flag, offset: 0xF8 */
} MRT_Type;

/* ----------------------------------------------------------------------------
   -- MRT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRT_Register_Masks MRT Register Masks
 * @{
 */

/*! @name CHANNEL_INTVAL - Time Interval Value */
/*! @{ */

#define MRT_CHANNEL_INTVAL_IVALUE_MASK           (0xFFFFFFU)
#define MRT_CHANNEL_INTVAL_IVALUE_SHIFT          (0U)
/*! IVALUE - Time Interval Load Value. */
#define MRT_CHANNEL_INTVAL_IVALUE(x)             (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_INTVAL_IVALUE_SHIFT)) & MRT_CHANNEL_INTVAL_IVALUE_MASK)

#define MRT_CHANNEL_INTVAL_LOAD_MASK             (0x80000000U)
#define MRT_CHANNEL_INTVAL_LOAD_SHIFT            (31U)
/*! LOAD - Force Load Enable
 *  0b0..No force load
 *  0b1..Force load
 */
#define MRT_CHANNEL_INTVAL_LOAD(x)               (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_INTVAL_LOAD_SHIFT)) & MRT_CHANNEL_INTVAL_LOAD_MASK)
/*! @} */

/* The count of MRT_CHANNEL_INTVAL */
#define MRT_CHANNEL_INTVAL_COUNT                 (4U)

/*! @name CHANNEL_TIMER - Timer */
/*! @{ */

#define MRT_CHANNEL_TIMER_VALUE_MASK             (0xFFFFFFU)
#define MRT_CHANNEL_TIMER_VALUE_SHIFT            (0U)
/*! VALUE - Current Timer Value */
#define MRT_CHANNEL_TIMER_VALUE(x)               (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_TIMER_VALUE_SHIFT)) & MRT_CHANNEL_TIMER_VALUE_MASK)
/*! @} */

/* The count of MRT_CHANNEL_TIMER */
#define MRT_CHANNEL_TIMER_COUNT                  (4U)

/*! @name CHANNEL_CTRL - Control */
/*! @{ */

#define MRT_CHANNEL_CTRL_INTEN_MASK              (0x1U)
#define MRT_CHANNEL_CTRL_INTEN_SHIFT             (0U)
/*! INTEN - Interrupt request
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MRT_CHANNEL_CTRL_INTEN(x)                (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_CTRL_INTEN_SHIFT)) & MRT_CHANNEL_CTRL_INTEN_MASK)

#define MRT_CHANNEL_CTRL_MODE_MASK               (0x6U)
#define MRT_CHANNEL_CTRL_MODE_SHIFT              (1U)
/*! MODE - MRT Operating mode
 *  0b00..Repeat Interrupt mode
 *  0b01..One-Shot Interrupt mode
 *  0b10..One-Shot Stall mode
 *  0b11..Reserved
 */
#define MRT_CHANNEL_CTRL_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_CTRL_MODE_SHIFT)) & MRT_CHANNEL_CTRL_MODE_MASK)
/*! @} */

/* The count of MRT_CHANNEL_CTRL */
#define MRT_CHANNEL_CTRL_COUNT                   (4U)

/*! @name CHANNEL_STAT - Status */
/*! @{ */

#define MRT_CHANNEL_STAT_INTFLAG_MASK            (0x1U)
#define MRT_CHANNEL_STAT_INTFLAG_SHIFT           (0U)
/*! INTFLAG - Monitors the interrupt flag. Writing 0 indicates no pending interrupt or no operation.
 *    Writing 1 indicates pending interrupt, because TIMERn has reached the end of the time
 *    interval. If CTRLn[INTEN] in the CONTROLn also gets 1, then the interrupt for timer channel n and the
 *    global interrupt are generated. Writing 1 to this field bit clears the interrupt request.
 *  0b0..No pending interrupt.
 *  0b1..Pending interrupt.
 */
#define MRT_CHANNEL_STAT_INTFLAG(x)              (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_STAT_INTFLAG_SHIFT)) & MRT_CHANNEL_STAT_INTFLAG_MASK)

#define MRT_CHANNEL_STAT_RUN_MASK                (0x2U)
#define MRT_CHANNEL_STAT_RUN_SHIFT               (1U)
/*! RUN - Timer n State
 *  0b0..Idle state.
 *  0b1..Running.
 */
#define MRT_CHANNEL_STAT_RUN(x)                  (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_STAT_RUN_SHIFT)) & MRT_CHANNEL_STAT_RUN_MASK)

#define MRT_CHANNEL_STAT_INUSE_MASK              (0x4U)
#define MRT_CHANNEL_STAT_INUSE_SHIFT             (2U)
/*! INUSE - Channel-In-Use flag
 *  0b0..This timer channel is not in use.
 *  0b1..This timer channel is in use.
 */
#define MRT_CHANNEL_STAT_INUSE(x)                (((uint32_t)(((uint32_t)(x)) << MRT_CHANNEL_STAT_INUSE_SHIFT)) & MRT_CHANNEL_STAT_INUSE_MASK)
/*! @} */

/* The count of MRT_CHANNEL_STAT */
#define MRT_CHANNEL_STAT_COUNT                   (4U)

/*! @name MODCFG - Module Configuration */
/*! @{ */

#define MRT_MODCFG_NOC_MASK                      (0xFU)
#define MRT_MODCFG_NOC_SHIFT                     (0U)
/*! NOC - Number of Channels */
#define MRT_MODCFG_NOC(x)                        (((uint32_t)(((uint32_t)(x)) << MRT_MODCFG_NOC_SHIFT)) & MRT_MODCFG_NOC_MASK)

#define MRT_MODCFG_NOB_MASK                      (0x1F0U)
#define MRT_MODCFG_NOB_SHIFT                     (4U)
/*! NOB - Number of Bits */
#define MRT_MODCFG_NOB(x)                        (((uint32_t)(((uint32_t)(x)) << MRT_MODCFG_NOB_SHIFT)) & MRT_MODCFG_NOB_MASK)

#define MRT_MODCFG_MULTITASK_MASK                (0x80000000U)
#define MRT_MODCFG_MULTITASK_SHIFT               (31U)
/*! MULTITASK - MULTITASK
 *  0b0..Hardware status mode.
 *  0b1..Multitask mode
 */
#define MRT_MODCFG_MULTITASK(x)                  (((uint32_t)(((uint32_t)(x)) << MRT_MODCFG_MULTITASK_SHIFT)) & MRT_MODCFG_MULTITASK_MASK)
/*! @} */

/*! @name IDLE_CH - Idle Channel */
/*! @{ */

#define MRT_IDLE_CH_CHAN_MASK                    (0xF0U)
#define MRT_IDLE_CH_CHAN_SHIFT                   (4U)
/*! CHAN - Idle Channel */
#define MRT_IDLE_CH_CHAN(x)                      (((uint32_t)(((uint32_t)(x)) << MRT_IDLE_CH_CHAN_SHIFT)) & MRT_IDLE_CH_CHAN_MASK)
/*! @} */

/*! @name IRQ_FLAG - Global Interrupt Flag */
/*! @{ */

#define MRT_IRQ_FLAG_GFLAG0_MASK                 (0x1U)
#define MRT_IRQ_FLAG_GFLAG0_SHIFT                (0U)
/*! GFLAG0 - Interrupt Flag
 *  0b0..No pending interrupt.
 *  0b1..Pending interrupt
 */
#define MRT_IRQ_FLAG_GFLAG0(x)                   (((uint32_t)(((uint32_t)(x)) << MRT_IRQ_FLAG_GFLAG0_SHIFT)) & MRT_IRQ_FLAG_GFLAG0_MASK)

#define MRT_IRQ_FLAG_GFLAG1_MASK                 (0x2U)
#define MRT_IRQ_FLAG_GFLAG1_SHIFT                (1U)
/*! GFLAG1 - Interrupt Flag */
#define MRT_IRQ_FLAG_GFLAG1(x)                   (((uint32_t)(((uint32_t)(x)) << MRT_IRQ_FLAG_GFLAG1_SHIFT)) & MRT_IRQ_FLAG_GFLAG1_MASK)

#define MRT_IRQ_FLAG_GFLAG2_MASK                 (0x4U)
#define MRT_IRQ_FLAG_GFLAG2_SHIFT                (2U)
/*! GFLAG2 - Interrupt Flag */
#define MRT_IRQ_FLAG_GFLAG2(x)                   (((uint32_t)(((uint32_t)(x)) << MRT_IRQ_FLAG_GFLAG2_SHIFT)) & MRT_IRQ_FLAG_GFLAG2_MASK)

#define MRT_IRQ_FLAG_GFLAG3_MASK                 (0x8U)
#define MRT_IRQ_FLAG_GFLAG3_SHIFT                (3U)
/*! GFLAG3 - Interrupt Flag */
#define MRT_IRQ_FLAG_GFLAG3(x)                   (((uint32_t)(((uint32_t)(x)) << MRT_IRQ_FLAG_GFLAG3_SHIFT)) & MRT_IRQ_FLAG_GFLAG3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MRT_Register_Masks */


/*!
 * @}
 */ /* end of group MRT_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_MRT_H_ */

