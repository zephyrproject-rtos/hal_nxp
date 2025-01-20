/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ANALOG_SFA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file ANALOG_SFA.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ANALOG_SFA
 *
 * CMSIS Peripheral Access Layer for ANALOG_SFA
 */

#if !defined(ANALOG_SFA_H_)
#define ANALOG_SFA_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- ANALOG_SFA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANALOG_SFA_Peripheral_Access_Layer ANALOG_SFA Peripheral Access Layer
 * @{
 */

/** ANALOG_SFA - Register Layout Typedef */
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
} ANALOG_SFA_Type;

/* ----------------------------------------------------------------------------
   -- ANALOG_SFA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANALOG_SFA_Register_Masks ANALOG_SFA Register Masks
 * @{
 */

/*! @name CTRL - Signal Frequency Analyser (SFA) Control */
/*! @{ */

#define ANALOG_SFA_CTRL_MODE_MASK                (0x3U)
#define ANALOG_SFA_CTRL_MODE_SHIFT               (0U)
/*! MODE - MEASUREMENT MODE
 *  0b00..Frequency measurement performed with REF frequency > CUT Frequency.
 *  0b01..Frequency measurement performed with REF frequency < CUT Frequency.
 *  0b10..CUT period measurement performed.
 *  0b11..Trigger based measurement performed. Note, each trigger pulse must be held for at least 2 ref_clk cycles.
 */
#define ANALOG_SFA_CTRL_MODE(x)                  (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_MODE_SHIFT)) & ANALOG_SFA_CTRL_MODE_MASK)

#define ANALOG_SFA_CTRL_TRIG_START_POL_MASK      (0x4U)
#define ANALOG_SFA_CTRL_TRIG_START_POL_SHIFT     (2U)
/*! TRIG_START_POL - Trigger Start Polarity
 *  0b0..Rising edge of TRIGGER[TRIG_START_SEL] will begin the measurement sequence.
 *  0b1..Falling edge of TRIGGER[TRIG_START_SEL] will begin the measurement sequence.
 */
#define ANALOG_SFA_CTRL_TRIG_START_POL(x)        (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_TRIG_START_POL_SHIFT)) & ANALOG_SFA_CTRL_TRIG_START_POL_MASK)

#define ANALOG_SFA_CTRL_TRIG_END_POL_MASK        (0x8U)
#define ANALOG_SFA_CTRL_TRIG_END_POL_SHIFT       (3U)
/*! TRIG_END_POL - Trigger End Polarity
 *  0b0..Rising edge of TRIGER[TRIG_END_SEL] will end the measurement sequence.
 *  0b1..Falling edge of TRIGGER[TRIG_END_SEL] will end the measurement sequence.
 */
#define ANALOG_SFA_CTRL_TRIG_END_POL(x)          (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_TRIG_END_POL_SHIFT)) & ANALOG_SFA_CTRL_TRIG_END_POL_MASK)

#define ANALOG_SFA_CTRL_SFA_TRIG_MEAS_EN_MASK    (0x10U)
#define ANALOG_SFA_CTRL_SFA_TRIG_MEAS_EN_SHIFT   (4U)
/*! SFA_TRIG_MEAS_EN - SFA Triggered Measurement Enable
 *  0b0..The measurement will start by default with a dummy write to the REF and CUT counters.
 *  0b1..The measurement will start after receiging a dummy write to the REF_CNT followed by receiving the trigger
 *       edge selected by TRIG_START_SEL and TRIG_START_POL.
 */
#define ANALOG_SFA_CTRL_SFA_TRIG_MEAS_EN(x)      (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_SFA_TRIG_MEAS_EN_SHIFT)) & ANALOG_SFA_CTRL_SFA_TRIG_MEAS_EN_MASK)

#define ANALOG_SFA_CTRL_SFA_IRQ_EN_MASK          (0x20U)
#define ANALOG_SFA_CTRL_SFA_IRQ_EN_SHIFT         (5U)
/*! SFA_IRQ_EN - SFA Interrupt Enable
 *  0b0..Interrupts are disabled.
 *  0b1..Interrupts are enabled.
 */
#define ANALOG_SFA_CTRL_SFA_IRQ_EN(x)            (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_SFA_IRQ_EN_SHIFT)) & ANALOG_SFA_CTRL_SFA_IRQ_EN_MASK)

#define ANALOG_SFA_CTRL_SFA_EN_MASK              (0x40U)
#define ANALOG_SFA_CTRL_SFA_EN_SHIFT             (6U)
/*! SFA_EN - SFA Enable
 *  0b0..The SFA is disabled.
 *  0b1..The SFA is enabled.
 */
#define ANALOG_SFA_CTRL_SFA_EN(x)                (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_SFA_EN_SHIFT)) & ANALOG_SFA_CTRL_SFA_EN_MASK)

#define ANALOG_SFA_CTRL_TRIG_START_SEL_MASK      (0x100U)
#define ANALOG_SFA_CTRL_TRIG_START_SEL_SHIFT     (8U)
/*! TRIG_START_SEL - Signal MUX For Trigger Based Measurement Start */
#define ANALOG_SFA_CTRL_TRIG_START_SEL(x)        (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_TRIG_START_SEL_SHIFT)) & ANALOG_SFA_CTRL_TRIG_START_SEL_MASK)

#define ANALOG_SFA_CTRL_TRIG_END_SEL_MASK        (0x1000U)
#define ANALOG_SFA_CTRL_TRIG_END_SEL_SHIFT       (12U)
/*! TRIG_END_SEL - Signal MUX For Trigger Based Measurement End */
#define ANALOG_SFA_CTRL_TRIG_END_SEL(x)          (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_TRIG_END_SEL_SHIFT)) & ANALOG_SFA_CTRL_TRIG_END_SEL_MASK)

#define ANALOG_SFA_CTRL_CUT_PREDIV_MASK          (0xFF0000U)
#define ANALOG_SFA_CTRL_CUT_PREDIV_SHIFT         (16U)
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
#define ANALOG_SFA_CTRL_CUT_PREDIV(x)            (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_CUT_PREDIV_SHIFT)) & ANALOG_SFA_CTRL_CUT_PREDIV_MASK)

#define ANALOG_SFA_CTRL_CUT_SEL_MASK             (0x1000000U)
#define ANALOG_SFA_CTRL_CUT_SEL_SHIFT            (24U)
/*! CUT_SEL - CUT_SEL */
#define ANALOG_SFA_CTRL_CUT_SEL(x)               (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_CUT_SEL_SHIFT)) & ANALOG_SFA_CTRL_CUT_SEL_MASK)
/*! @} */

/*! @name CTRL_EXT - Signal Frequency Analyser (SFA) Control Extended */
/*! @{ */

#define ANALOG_SFA_CTRL_EXT_CUT_CLK_EN_MASK      (0x1U)
#define ANALOG_SFA_CTRL_EXT_CUT_CLK_EN_SHIFT     (0U)
/*! CUT_CLK_EN - CUT_CLK_EN */
#define ANALOG_SFA_CTRL_EXT_CUT_CLK_EN(x)        (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_EXT_CUT_CLK_EN_SHIFT)) & ANALOG_SFA_CTRL_EXT_CUT_CLK_EN_MASK)

#define ANALOG_SFA_CTRL_EXT_CUT_PIN_EN_MASK      (0x10000U)
#define ANALOG_SFA_CTRL_EXT_CUT_PIN_EN_SHIFT     (16U)
/*! CUT_PIN_EN - CUT_PIN_EN */
#define ANALOG_SFA_CTRL_EXT_CUT_PIN_EN(x)        (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CTRL_EXT_CUT_PIN_EN_SHIFT)) & ANALOG_SFA_CTRL_EXT_CUT_PIN_EN_MASK)
/*! @} */

/*! @name CNT_STAT - Signal Frequency Analyser Count Status Register */
/*! @{ */

#define ANALOG_SFA_CNT_STAT_REF_STOPPED_MASK     (0x1U)
#define ANALOG_SFA_CNT_STAT_REF_STOPPED_SHIFT    (0U)
/*! REF_STOPPED - REF_STOPPED */
#define ANALOG_SFA_CNT_STAT_REF_STOPPED(x)       (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CNT_STAT_REF_STOPPED_SHIFT)) & ANALOG_SFA_CNT_STAT_REF_STOPPED_MASK)

#define ANALOG_SFA_CNT_STAT_CUT_STOPPED_MASK     (0x2U)
#define ANALOG_SFA_CNT_STAT_CUT_STOPPED_SHIFT    (1U)
/*! CUT_STOPPED - CUT_STOPPED */
#define ANALOG_SFA_CNT_STAT_CUT_STOPPED(x)       (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CNT_STAT_CUT_STOPPED_SHIFT)) & ANALOG_SFA_CNT_STAT_CUT_STOPPED_MASK)

#define ANALOG_SFA_CNT_STAT_MEAS_STARTED_MASK    (0x4U)
#define ANALOG_SFA_CNT_STAT_MEAS_STARTED_SHIFT   (2U)
/*! MEAS_STARTED - Measurement Started Flag */
#define ANALOG_SFA_CNT_STAT_MEAS_STARTED(x)      (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CNT_STAT_MEAS_STARTED_SHIFT)) & ANALOG_SFA_CNT_STAT_MEAS_STARTED_MASK)

#define ANALOG_SFA_CNT_STAT_REF_CNT_TIMEOUT_MASK (0x8U)
#define ANALOG_SFA_CNT_STAT_REF_CNT_TIMEOUT_SHIFT (3U)
/*! REF_CNT_TIMEOUT - Reference Counter Time Out */
#define ANALOG_SFA_CNT_STAT_REF_CNT_TIMEOUT(x)   (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CNT_STAT_REF_CNT_TIMEOUT_SHIFT)) & ANALOG_SFA_CNT_STAT_REF_CNT_TIMEOUT_MASK)

#define ANALOG_SFA_CNT_STAT_SFA_IRQ_MASK         (0x10U)
#define ANALOG_SFA_CNT_STAT_SFA_IRQ_SHIFT        (4U)
/*! SFA_IRQ - SFA Interrupt Request */
#define ANALOG_SFA_CNT_STAT_SFA_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CNT_STAT_SFA_IRQ_SHIFT)) & ANALOG_SFA_CNT_STAT_SFA_IRQ_MASK)
/*! @} */

/*! @name CUT_CNT - Signal Frequency Analyser Clock Under Test Counter */
/*! @{ */

#define ANALOG_SFA_CUT_CNT_CUT_CNT_MASK          (0xFFFFFFFFU)
#define ANALOG_SFA_CUT_CNT_CUT_CNT_SHIFT         (0U)
/*! CUT_CNT - CUT_CNT */
#define ANALOG_SFA_CUT_CNT_CUT_CNT(x)            (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CUT_CNT_CUT_CNT_SHIFT)) & ANALOG_SFA_CUT_CNT_CUT_CNT_MASK)
/*! @} */

/*! @name REF_CNT - Signal Frequency Analyser Reference Clock Counter */
/*! @{ */

#define ANALOG_SFA_REF_CNT_REF_CNT_MASK          (0xFFFFFFFFU)
#define ANALOG_SFA_REF_CNT_REF_CNT_SHIFT         (0U)
/*! REF_CNT - REF_CNT */
#define ANALOG_SFA_REF_CNT_REF_CNT(x)            (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_REF_CNT_REF_CNT_SHIFT)) & ANALOG_SFA_REF_CNT_REF_CNT_MASK)
/*! @} */

/*! @name CUT_TARGET - Signal Frequency Analyser Clock Under Test Target Count */
/*! @{ */

#define ANALOG_SFA_CUT_TARGET_CUT_TARGET_MASK    (0xFFFFFFFFU)
#define ANALOG_SFA_CUT_TARGET_CUT_TARGET_SHIFT   (0U)
/*! CUT_TARGET - CUT_TARGET */
#define ANALOG_SFA_CUT_TARGET_CUT_TARGET(x)      (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_CUT_TARGET_CUT_TARGET_SHIFT)) & ANALOG_SFA_CUT_TARGET_CUT_TARGET_MASK)
/*! @} */

/*! @name REF_TARGET - Signal Frequency Analyser Reference Clock Target Count */
/*! @{ */

#define ANALOG_SFA_REF_TARGET_REF_TARGET_MASK    (0xFFFFFFFFU)
#define ANALOG_SFA_REF_TARGET_REF_TARGET_SHIFT   (0U)
/*! REF_TARGET - REF_TARGET */
#define ANALOG_SFA_REF_TARGET_REF_TARGET(x)      (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_REF_TARGET_REF_TARGET_SHIFT)) & ANALOG_SFA_REF_TARGET_REF_TARGET_MASK)
/*! @} */

/*! @name REF_CNT_ST_SAVED - Signal Frequency Analyser Reference Clock Count Start Saved Register */
/*! @{ */

#define ANALOG_SFA_REF_CNT_ST_SAVED_REF_CNT_ST_SAVED_MASK (0xFFFFFFFFU)
#define ANALOG_SFA_REF_CNT_ST_SAVED_REF_CNT_ST_SAVED_SHIFT (0U)
/*! REF_CNT_ST_SAVED - REF_CNT_ST_SAVED */
#define ANALOG_SFA_REF_CNT_ST_SAVED_REF_CNT_ST_SAVED(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_REF_CNT_ST_SAVED_REF_CNT_ST_SAVED_SHIFT)) & ANALOG_SFA_REF_CNT_ST_SAVED_REF_CNT_ST_SAVED_MASK)
/*! @} */

/*! @name REF_CNT_END_SAVED - Signal Frequency Analyser Reference Clock Count End Saved Register */
/*! @{ */

#define ANALOG_SFA_REF_CNT_END_SAVED_REF_CNT_END_SAVED_MASK (0xFFFFFFFFU)
#define ANALOG_SFA_REF_CNT_END_SAVED_REF_CNT_END_SAVED_SHIFT (0U)
/*! REF_CNT_END_SAVED - REF_CNT_END_SAVED */
#define ANALOG_SFA_REF_CNT_END_SAVED_REF_CNT_END_SAVED(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_SFA_REF_CNT_END_SAVED_REF_CNT_END_SAVED_SHIFT)) & ANALOG_SFA_REF_CNT_END_SAVED_REF_CNT_END_SAVED_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANALOG_SFA_Register_Masks */


/*!
 * @}
 */ /* end of group ANALOG_SFA_Peripheral_Access_Layer */


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


#endif  /* ANALOG_SFA_H_ */

