/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SFA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SFA.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SFA
 *
 * CMSIS Peripheral Access Layer for SFA
 */

#if !defined(PERI_SFA_H_)
#define PERI_SFA_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- SFA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SFA_Peripheral_Access_Layer SFA Peripheral Access Layer
 * @{
 */

/** SFA - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Signal Frequency Analyser (SFA) Control, offset: 0x0 */
  __IO uint32_t CTRL_EXT;                          /**< Signal Frequency Analyser (SFA) Control Extended, offset: 0x4 */
  __IO uint32_t CNT_STAT;                          /**< Signal Frequency Analyser Count Status Register, offset: 0x8 */
  __I  uint32_t CUT_CNT;                           /**< Signal Frequency Analyser Clock Under Test Counter, offset: 0xC */
  __I  uint32_t REF_CNT;                           /**< Signal Frequency Analyser Reference Clock Counter, offset: 0x10 */
  __IO uint32_t CUT_TARGET;                        /**< Signal Frequency Analyser Clock Under Test Target Count, offset: 0x14 */
  __IO uint32_t REF_TARGET;                        /**< Signal Frequency Analyser Reference Clock Target Count, offset: 0x18 */
  __I  uint32_t REF_CNT_ST_SAVED;                  /**< Signal Frequency Analyser Reference Clock Count Start Saved Register, offset: 0x1C */
  __I  uint32_t REF_CNT_END_SAVED;                 /**< Signal Frequency Analyser Reference Clock Count End Saved Register, offset: 0x20 */
} SFA_Type;

/* ----------------------------------------------------------------------------
   -- SFA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SFA_Register_Masks SFA Register Masks
 * @{
 */

/*! @name CTRL - Signal Frequency Analyser (SFA) Control */
/*! @{ */

#define SFA_CTRL_MODE_MASK                       (0x3U)
#define SFA_CTRL_MODE_SHIFT                      (0U)
/*! MODE - MEASUREMENT MODE
 *  0b00..Frequency measurement performed with REF frequency > CUT Frequency.
 *  0b01..Frequency measurement performed with REF frequency < CUT Frequency.
 *  0b10..CUT period measurement performed.
 *  0b11..Trigger based measurement performed. Note, each trigger pulse must be held for at least 2 ref_clk cycles.
 */
#define SFA_CTRL_MODE(x)                         (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_MODE_SHIFT)) & SFA_CTRL_MODE_MASK)

#define SFA_CTRL_TRIG_START_POL_MASK             (0x4U)
#define SFA_CTRL_TRIG_START_POL_SHIFT            (2U)
/*! TRIG_START_POL - Trigger Start Polarity
 *  0b0..Rising edge of TRIGGER[TRIG_START_SEL] will begin the measurement sequence.
 *  0b1..Falling edge of TRIGGER[TRIG_START_SEL] will begin the measurement sequence.
 */
#define SFA_CTRL_TRIG_START_POL(x)               (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_TRIG_START_POL_SHIFT)) & SFA_CTRL_TRIG_START_POL_MASK)

#define SFA_CTRL_TRIG_END_POL_MASK               (0x8U)
#define SFA_CTRL_TRIG_END_POL_SHIFT              (3U)
/*! TRIG_END_POL - Trigger End Polarity
 *  0b0..Rising edge of TRIGER[TRIG_END_SEL] will end the measurement sequence.
 *  0b1..Falling edge of TRIGGER[TRIG_END_SEL] will end the measurement sequence.
 */
#define SFA_CTRL_TRIG_END_POL(x)                 (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_TRIG_END_POL_SHIFT)) & SFA_CTRL_TRIG_END_POL_MASK)

#define SFA_CTRL_SFA_TRIG_MEAS_EN_MASK           (0x10U)
#define SFA_CTRL_SFA_TRIG_MEAS_EN_SHIFT          (4U)
/*! SFA_TRIG_MEAS_EN - SFA Triggered Measurement Enable
 *  0b0..The measurement will start by default with a dummy write to the REF and CUT counters.
 *  0b1..The measurement will start after receiging a dummy write to the REF_CNT followed by receiving the trigger
 *       edge selected by TRIG_START_SEL and TRIG_START_POL.
 */
#define SFA_CTRL_SFA_TRIG_MEAS_EN(x)             (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_SFA_TRIG_MEAS_EN_SHIFT)) & SFA_CTRL_SFA_TRIG_MEAS_EN_MASK)

#define SFA_CTRL_SFA_IRQ_EN_MASK                 (0x20U)
#define SFA_CTRL_SFA_IRQ_EN_SHIFT                (5U)
/*! SFA_IRQ_EN - SFA Interrupt Enable
 *  0b0..Interrupts are disabled.
 *  0b1..Interrupts are enabled.
 */
#define SFA_CTRL_SFA_IRQ_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_SFA_IRQ_EN_SHIFT)) & SFA_CTRL_SFA_IRQ_EN_MASK)

#define SFA_CTRL_SFA_EN_MASK                     (0x40U)
#define SFA_CTRL_SFA_EN_SHIFT                    (6U)
/*! SFA_EN - SFA Enable
 *  0b0..The SFA is disabled.
 *  0b1..The SFA is enabled.
 */
#define SFA_CTRL_SFA_EN(x)                       (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_SFA_EN_SHIFT)) & SFA_CTRL_SFA_EN_MASK)

#define SFA_CTRL_TRIG_START_SEL_MASK             (0x300U)
#define SFA_CTRL_TRIG_START_SEL_SHIFT            (8U)
/*! TRIG_START_SEL - Signal MUX For Trigger Based Measurement Start */
#define SFA_CTRL_TRIG_START_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_TRIG_START_SEL_SHIFT)) & SFA_CTRL_TRIG_START_SEL_MASK)

#define SFA_CTRL_TRIG_END_SEL_MASK               (0x3000U)
#define SFA_CTRL_TRIG_END_SEL_SHIFT              (12U)
/*! TRIG_END_SEL - Signal MUX For Trigger Based Measurement End */
#define SFA_CTRL_TRIG_END_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_TRIG_END_SEL_SHIFT)) & SFA_CTRL_TRIG_END_SEL_MASK)

#define SFA_CTRL_CUT_PREDIV_MASK                 (0xFF0000U)
#define SFA_CTRL_CUT_PREDIV_SHIFT                (16U)
/*! CUT_PREDIV - CUT_PREDIV
 *  0b00000000..No Divide
 *  0b00000001..No Divide
 *  0b00000010..Divide by 2
 *  0b00000011..Divide by 2
 *  0b00000100..Divide by 4
 *  0b00000101..Divide by 4
 *  0b00000110..Divide by 6
 *  0b00000111..Divide by 6
 *  0b00001000..Divide by 8
 *  0b00001001..Divide by 8
 *  0b00001010-0b11111101..Divide by CUT_PREDIV - CUT_PREDIV%2
 *  0b11111110..Divide by 254
 *  0b11111111..Divide by 254
 */
#define SFA_CTRL_CUT_PREDIV(x)                   (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_CUT_PREDIV_SHIFT)) & SFA_CTRL_CUT_PREDIV_MASK)

#define SFA_CTRL_CUT_SEL_MASK                    (0xF000000U)
#define SFA_CTRL_CUT_SEL_SHIFT                   (24U)
/*! CUT_SEL - CUT_SEL */
#define SFA_CTRL_CUT_SEL(x)                      (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_CUT_SEL_SHIFT)) & SFA_CTRL_CUT_SEL_MASK)
/*! @} */

/*! @name CTRL_EXT - Signal Frequency Analyser (SFA) Control Extended */
/*! @{ */

#define SFA_CTRL_EXT_CUT_CLK_EN_MASK             (0xFFFFU)
#define SFA_CTRL_EXT_CUT_CLK_EN_SHIFT            (0U)
/*! CUT_CLK_EN - CUT_CLK_EN */
#define SFA_CTRL_EXT_CUT_CLK_EN(x)               (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_EXT_CUT_CLK_EN_SHIFT)) & SFA_CTRL_EXT_CUT_CLK_EN_MASK)

#define SFA_CTRL_EXT_CUT_PIN_EN_MASK             (0x10000U)
#define SFA_CTRL_EXT_CUT_PIN_EN_SHIFT            (16U)
/*! CUT_PIN_EN - CUT_PIN_EN */
#define SFA_CTRL_EXT_CUT_PIN_EN(x)               (((uint32_t)(((uint32_t)(x)) << SFA_CTRL_EXT_CUT_PIN_EN_SHIFT)) & SFA_CTRL_EXT_CUT_PIN_EN_MASK)
/*! @} */

/*! @name CNT_STAT - Signal Frequency Analyser Count Status Register */
/*! @{ */

#define SFA_CNT_STAT_REF_STOPPED_MASK            (0x1U)
#define SFA_CNT_STAT_REF_STOPPED_SHIFT           (0U)
/*! REF_STOPPED - REF_STOPPED */
#define SFA_CNT_STAT_REF_STOPPED(x)              (((uint32_t)(((uint32_t)(x)) << SFA_CNT_STAT_REF_STOPPED_SHIFT)) & SFA_CNT_STAT_REF_STOPPED_MASK)

#define SFA_CNT_STAT_CUT_STOPPED_MASK            (0x2U)
#define SFA_CNT_STAT_CUT_STOPPED_SHIFT           (1U)
/*! CUT_STOPPED - CUT_STOPPED */
#define SFA_CNT_STAT_CUT_STOPPED(x)              (((uint32_t)(((uint32_t)(x)) << SFA_CNT_STAT_CUT_STOPPED_SHIFT)) & SFA_CNT_STAT_CUT_STOPPED_MASK)

#define SFA_CNT_STAT_MEAS_STARTED_MASK           (0x4U)
#define SFA_CNT_STAT_MEAS_STARTED_SHIFT          (2U)
/*! MEAS_STARTED - Measurement Started Flag */
#define SFA_CNT_STAT_MEAS_STARTED(x)             (((uint32_t)(((uint32_t)(x)) << SFA_CNT_STAT_MEAS_STARTED_SHIFT)) & SFA_CNT_STAT_MEAS_STARTED_MASK)

#define SFA_CNT_STAT_REF_CNT_TIMEOUT_MASK        (0x8U)
#define SFA_CNT_STAT_REF_CNT_TIMEOUT_SHIFT       (3U)
/*! REF_CNT_TIMEOUT - Reference Counter Time Out */
#define SFA_CNT_STAT_REF_CNT_TIMEOUT(x)          (((uint32_t)(((uint32_t)(x)) << SFA_CNT_STAT_REF_CNT_TIMEOUT_SHIFT)) & SFA_CNT_STAT_REF_CNT_TIMEOUT_MASK)

#define SFA_CNT_STAT_SFA_IRQ_MASK                (0x10U)
#define SFA_CNT_STAT_SFA_IRQ_SHIFT               (4U)
/*! SFA_IRQ - SFA Interrupt Request */
#define SFA_CNT_STAT_SFA_IRQ(x)                  (((uint32_t)(((uint32_t)(x)) << SFA_CNT_STAT_SFA_IRQ_SHIFT)) & SFA_CNT_STAT_SFA_IRQ_MASK)
/*! @} */

/*! @name CUT_CNT - Signal Frequency Analyser Clock Under Test Counter */
/*! @{ */

#define SFA_CUT_CNT_CUT_CNT_MASK                 (0xFFFFFFFFU)
#define SFA_CUT_CNT_CUT_CNT_SHIFT                (0U)
/*! CUT_CNT - CUT_CNT */
#define SFA_CUT_CNT_CUT_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << SFA_CUT_CNT_CUT_CNT_SHIFT)) & SFA_CUT_CNT_CUT_CNT_MASK)
/*! @} */

/*! @name REF_CNT - Signal Frequency Analyser Reference Clock Counter */
/*! @{ */

#define SFA_REF_CNT_REF_CNT_MASK                 (0xFFFFFFFFU)
#define SFA_REF_CNT_REF_CNT_SHIFT                (0U)
/*! REF_CNT - REF_CNT */
#define SFA_REF_CNT_REF_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << SFA_REF_CNT_REF_CNT_SHIFT)) & SFA_REF_CNT_REF_CNT_MASK)
/*! @} */

/*! @name CUT_TARGET - Signal Frequency Analyser Clock Under Test Target Count */
/*! @{ */

#define SFA_CUT_TARGET_CUT_TARGET_MASK           (0xFFFFFFFFU)
#define SFA_CUT_TARGET_CUT_TARGET_SHIFT          (0U)
/*! CUT_TARGET - CUT_TARGET */
#define SFA_CUT_TARGET_CUT_TARGET(x)             (((uint32_t)(((uint32_t)(x)) << SFA_CUT_TARGET_CUT_TARGET_SHIFT)) & SFA_CUT_TARGET_CUT_TARGET_MASK)
/*! @} */

/*! @name REF_TARGET - Signal Frequency Analyser Reference Clock Target Count */
/*! @{ */

#define SFA_REF_TARGET_REF_TARGET_MASK           (0xFFFFFFFFU)
#define SFA_REF_TARGET_REF_TARGET_SHIFT          (0U)
/*! REF_TARGET - REF_TARGET */
#define SFA_REF_TARGET_REF_TARGET(x)             (((uint32_t)(((uint32_t)(x)) << SFA_REF_TARGET_REF_TARGET_SHIFT)) & SFA_REF_TARGET_REF_TARGET_MASK)
/*! @} */

/*! @name REF_CNT_ST_SAVED - Signal Frequency Analyser Reference Clock Count Start Saved Register */
/*! @{ */

#define SFA_REF_CNT_ST_SAVED_REF_CNT_ST_SAVED_MASK (0xFFFFFFFFU)
#define SFA_REF_CNT_ST_SAVED_REF_CNT_ST_SAVED_SHIFT (0U)
/*! REF_CNT_ST_SAVED - REF_CNT_ST_SAVED */
#define SFA_REF_CNT_ST_SAVED_REF_CNT_ST_SAVED(x) (((uint32_t)(((uint32_t)(x)) << SFA_REF_CNT_ST_SAVED_REF_CNT_ST_SAVED_SHIFT)) & SFA_REF_CNT_ST_SAVED_REF_CNT_ST_SAVED_MASK)
/*! @} */

/*! @name REF_CNT_END_SAVED - Signal Frequency Analyser Reference Clock Count End Saved Register */
/*! @{ */

#define SFA_REF_CNT_END_SAVED_REF_CNT_END_SAVED_MASK (0xFFFFFFFFU)
#define SFA_REF_CNT_END_SAVED_REF_CNT_END_SAVED_SHIFT (0U)
/*! REF_CNT_END_SAVED - REF_CNT_END_SAVED */
#define SFA_REF_CNT_END_SAVED_REF_CNT_END_SAVED(x) (((uint32_t)(((uint32_t)(x)) << SFA_REF_CNT_END_SAVED_REF_CNT_END_SAVED_SHIFT)) & SFA_REF_CNT_END_SAVED_REF_CNT_END_SAVED_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SFA_Register_Masks */


/*!
 * @}
 */ /* end of group SFA_Peripheral_Access_Layer */


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


#endif  /* PERI_SFA_H_ */

