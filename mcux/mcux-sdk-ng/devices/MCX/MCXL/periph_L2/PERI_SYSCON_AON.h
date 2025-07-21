/*
** ###################################################################
**     Processors:          MCXL253VDF_cm0plus
**                          MCXL253VDF_cm33
**                          MCXL253VLL_cm0plus
**                          MCXL253VLL_cm33
**                          MCXL254VDF_cm0plus
**                          MCXL254VDF_cm33
**                          MCXL254VLL_cm0plus
**                          MCXL254VLL_cm33
**                          MCXL255VDF_cm0plus
**                          MCXL255VDF_cm33
**                          MCXL255VLL_cm0plus
**                          MCXL255VLL_cm33
**
**     Version:             rev. 1.0, 2023-01-09
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSCON_AON
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSCON_AON.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for SYSCON_AON
 *
 * CMSIS Peripheral Access Layer for SYSCON_AON
 */

#if !defined(PERI_SYSCON_AON_H_)
#define PERI_SYSCON_AON_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL253VDF_cm0plus) || defined(CPU_MCXL253VLL_cm0plus))
#include "MCXL253_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL253VDF_cm33) || defined(CPU_MCXL253VLL_cm33))
#include "MCXL253_cm33_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm0plus) || defined(CPU_MCXL254VLL_cm0plus))
#include "MCXL254_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm33) || defined(CPU_MCXL254VLL_cm33))
#include "MCXL254_cm33_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm0plus) || defined(CPU_MCXL255VLL_cm0plus))
#include "MCXL255_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm33) || defined(CPU_MCXL255VLL_cm33))
#include "MCXL255_cm33_COMMON.h"
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
   -- SYSCON_AON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_AON_Peripheral_Access_Layer SYSCON_AON Peripheral Access Layer
 * @{
 */

/** SYSCON_AON - Register Layout Typedef */
typedef struct {
  __IO uint32_t SEQUENCE_TICK;                     /**< LC Sense sequence tick, offset: 0x0 */
  __IO uint32_t LC_ROT_LOGIC;                      /**< LC Rotating Logic, offset: 0x4 */
  __IO uint32_t POLARITY_CONTROL;                  /**< Polarity Control, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t INTR_MASK;                         /**< LCD Interrupt Mask, offset: 0x10 */
  __IO uint32_t LPTMR_CTRL;                        /**< LPTMR Source Control, offset: 0x14 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CPU_SLEEP_SELECT;                  /**< CPU Sleep Select, offset: 0x1C */
  __IO uint32_t PULSE_CAP_ACMP_CLK_MUXSEL;         /**< CMP Pulse Capture Clock MUXSEL, offset: 0x20 */
  __IO uint32_t PINMUXCLKCTRL;                     /**< Pinmux Clock Control, offset: 0x24 */
  __IO uint32_t SYNC_EN_INPUTMUX_AON;              /**< Synchronization Enable INPUTMUX, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t IPG_DEBUG_ENABLE;                  /**< IPG Debug Enable, offset: 0x30 */
  __IO uint32_t XTAL_32K_CLKCTRL;                  /**< offset: 0x34 */
  __IO uint32_t TAMPER_FLT_STAT;                   /**< Tamper Fault Status, offset: 0x38 */
  __IO uint32_t TAMPER_FLT_EN;                     /**< Tamper Fault Enable, offset: 0x3C */
  __IO uint32_t SECURITY_GLITCH_DETECT_ENABLE;     /**< Security Glitch Detect Enable, offset: 0x40 */
} SYSCON_AON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON_AON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_AON_Register_Masks SYSCON_AON Register Masks
 * @{
 */

/*! @name SEQUENCE_TICK - LC Sense sequence tick */
/*! @{ */

#define SYSCON_AON_SEQUENCE_TICK_SW_OVERRIDE_SEQ_CTRL_MASK (0x1U)
#define SYSCON_AON_SEQUENCE_TICK_SW_OVERRIDE_SEQ_CTRL_SHIFT (0U)
/*! SW_OVERRIDE_SEQ_CTRL - SW_OVERRIDE_SEQ_CTRL
 *  0b0..Sequence value is not overridden. Default LC Sense design configuration is observed.
 *  0b1..Sequence values can be overridden by software.
 */
#define SYSCON_AON_SEQUENCE_TICK_SW_OVERRIDE_SEQ_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SEQUENCE_TICK_SW_OVERRIDE_SEQ_CTRL_SHIFT)) & SYSCON_AON_SEQUENCE_TICK_SW_OVERRIDE_SEQ_CTRL_MASK)

#define SYSCON_AON_SEQUENCE_TICK_SW_PARKED_MASK  (0x2U)
#define SYSCON_AON_SEQUENCE_TICK_SW_PARKED_SHIFT (1U)
/*! SW_PARKED - SW_PARKED */
#define SYSCON_AON_SEQUENCE_TICK_SW_PARKED(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SEQUENCE_TICK_SW_PARKED_SHIFT)) & SYSCON_AON_SEQUENCE_TICK_SW_PARKED_MASK)

#define SYSCON_AON_SEQUENCE_TICK_SW_OVERRIDE_MASK (0x3CU)
#define SYSCON_AON_SEQUENCE_TICK_SW_OVERRIDE_SHIFT (2U)
/*! SW_OVERRIDE - SW OVERRIDE SEQUENCE CONTROL */
#define SYSCON_AON_SEQUENCE_TICK_SW_OVERRIDE(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SEQUENCE_TICK_SW_OVERRIDE_SHIFT)) & SYSCON_AON_SEQUENCE_TICK_SW_OVERRIDE_MASK)

#define SYSCON_AON_SEQUENCE_TICK_SW_CHANNEL_EN_MASK (0x1C0U)
#define SYSCON_AON_SEQUENCE_TICK_SW_CHANNEL_EN_SHIFT (6U)
/*! SW_CHANNEL_EN - SW_CHANNEL_EN_SEQ
 *  0b000..Channel is disabled
 *  0b001..Channel is enabled
 */
#define SYSCON_AON_SEQUENCE_TICK_SW_CHANNEL_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SEQUENCE_TICK_SW_CHANNEL_EN_SHIFT)) & SYSCON_AON_SEQUENCE_TICK_SW_CHANNEL_EN_MASK)
/*! @} */

/*! @name LC_ROT_LOGIC - LC Rotating Logic */
/*! @{ */

#define SYSCON_AON_LC_ROT_LOGIC_SW_OVERRIDE_ACMP_OUT_MASK (0x1U)
#define SYSCON_AON_LC_ROT_LOGIC_SW_OVERRIDE_ACMP_OUT_SHIFT (0U)
/*! SW_OVERRIDE_ACMP_OUT - SW_OVERRIDE_ACMP_OUT
 *  0b0..SW override is disabled
 *  0b1..SW override is enabled
 */
#define SYSCON_AON_LC_ROT_LOGIC_SW_OVERRIDE_ACMP_OUT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_LC_ROT_LOGIC_SW_OVERRIDE_ACMP_OUT_SHIFT)) & SYSCON_AON_LC_ROT_LOGIC_SW_OVERRIDE_ACMP_OUT_MASK)

#define SYSCON_AON_LC_ROT_LOGIC_SW_OVERRIDE_VALUE_MASK (0x1EU)
#define SYSCON_AON_LC_ROT_LOGIC_SW_OVERRIDE_VALUE_SHIFT (1U)
/*! SW_OVERRIDE_VALUE - SW_OVERRIDE_VALUE */
#define SYSCON_AON_LC_ROT_LOGIC_SW_OVERRIDE_VALUE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_LC_ROT_LOGIC_SW_OVERRIDE_VALUE_SHIFT)) & SYSCON_AON_LC_ROT_LOGIC_SW_OVERRIDE_VALUE_MASK)

#define SYSCON_AON_LC_ROT_LOGIC_CH_COMP_OUT_MASK (0x1E0U)
#define SYSCON_AON_LC_ROT_LOGIC_CH_COMP_OUT_SHIFT (5U)
/*! CH_COMP_OUT - CH_COMP_OUT */
#define SYSCON_AON_LC_ROT_LOGIC_CH_COMP_OUT(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_LC_ROT_LOGIC_CH_COMP_OUT_SHIFT)) & SYSCON_AON_LC_ROT_LOGIC_CH_COMP_OUT_MASK)

#define SYSCON_AON_LC_ROT_LOGIC_QTMR0_CTR0_OUT_MASK (0x200U)
#define SYSCON_AON_LC_ROT_LOGIC_QTMR0_CTR0_OUT_SHIFT (9U)
#define SYSCON_AON_LC_ROT_LOGIC_QTMR0_CTR0_OUT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_LC_ROT_LOGIC_QTMR0_CTR0_OUT_SHIFT)) & SYSCON_AON_LC_ROT_LOGIC_QTMR0_CTR0_OUT_MASK)
/*! @} */

/*! @name POLARITY_CONTROL - Polarity Control */
/*! @{ */

#define SYSCON_AON_POLARITY_CONTROL_CONTROL_PADS_POLARITY_CTRL_MASK (0x1U)
#define SYSCON_AON_POLARITY_CONTROL_CONTROL_PADS_POLARITY_CTRL_SHIFT (0U)
/*! CONTROL_PADS_POLARITY_CTRL - CONTROL_PADS_POLARITY_CTRL */
#define SYSCON_AON_POLARITY_CONTROL_CONTROL_PADS_POLARITY_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_POLARITY_CONTROL_CONTROL_PADS_POLARITY_CTRL_SHIFT)) & SYSCON_AON_POLARITY_CONTROL_CONTROL_PADS_POLARITY_CTRL_MASK)

#define SYSCON_AON_POLARITY_CONTROL_CTRL_PADS_VALUE_CTRL_MASK (0x2U)
#define SYSCON_AON_POLARITY_CONTROL_CTRL_PADS_VALUE_CTRL_SHIFT (1U)
/*! CTRL_PADS_VALUE_CTRL - CTRL_PADS_VALUE_CTRL
 *  0b0..Drives low during non-tristate duration
 *  0b1..Drives high during non-tristate duration
 */
#define SYSCON_AON_POLARITY_CONTROL_CTRL_PADS_VALUE_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_POLARITY_CONTROL_CTRL_PADS_VALUE_CTRL_SHIFT)) & SYSCON_AON_POLARITY_CONTROL_CTRL_PADS_VALUE_CTRL_MASK)

#define SYSCON_AON_POLARITY_CONTROL_CMP_PADS_DIG_CTRL_EN_MASK (0x4U)
#define SYSCON_AON_POLARITY_CONTROL_CMP_PADS_DIG_CTRL_EN_SHIFT (2U)
/*! CMP_PADS_DIG_CTRL_EN - CMP_PADS_DIG_CTRL_EN
 *  0b0..Disables the drive path
 *  0b1..Enables the drive path
 */
#define SYSCON_AON_POLARITY_CONTROL_CMP_PADS_DIG_CTRL_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_POLARITY_CONTROL_CMP_PADS_DIG_CTRL_EN_SHIFT)) & SYSCON_AON_POLARITY_CONTROL_CMP_PADS_DIG_CTRL_EN_MASK)

#define SYSCON_AON_POLARITY_CONTROL_CMP_PADS_VALUE_CTRL_MASK (0x8U)
#define SYSCON_AON_POLARITY_CONTROL_CMP_PADS_VALUE_CTRL_SHIFT (3U)
/*! CMP_PADS_VALUE_CTRL - CMP_PADS_VALUE_CTRL */
#define SYSCON_AON_POLARITY_CONTROL_CMP_PADS_VALUE_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_POLARITY_CONTROL_CMP_PADS_VALUE_CTRL_SHIFT)) & SYSCON_AON_POLARITY_CONTROL_CMP_PADS_VALUE_CTRL_MASK)

#define SYSCON_AON_POLARITY_CONTROL_CMP_PADS_POLARITY_CTRL_MASK (0x10U)
#define SYSCON_AON_POLARITY_CONTROL_CMP_PADS_POLARITY_CTRL_SHIFT (4U)
/*! CMP_PADS_POLARITY_CTRL - CMP_PADS_POLARITY_CTRL
 *  0b0..No change in polarity
 *  0b1..Inverts the polarity
 */
#define SYSCON_AON_POLARITY_CONTROL_CMP_PADS_POLARITY_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_POLARITY_CONTROL_CMP_PADS_POLARITY_CTRL_SHIFT)) & SYSCON_AON_POLARITY_CONTROL_CMP_PADS_POLARITY_CTRL_MASK)
/*! @} */

/*! @name INTR_MASK - LCD Interrupt Mask */
/*! @{ */

#define SYSCON_AON_INTR_MASK_LCD_MAIN_INTR_MASK_MASK (0x1U)
#define SYSCON_AON_INTR_MASK_LCD_MAIN_INTR_MASK_SHIFT (0U)
/*! LCD_MAIN_INTR_MASK - LCD_MAIN_INTR_MASK
 *  0b0..Masking is disabled
 *  0b1..Masking is enabled
 */
#define SYSCON_AON_INTR_MASK_LCD_MAIN_INTR_MASK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_INTR_MASK_LCD_MAIN_INTR_MASK_SHIFT)) & SYSCON_AON_INTR_MASK_LCD_MAIN_INTR_MASK_MASK)
/*! @} */

/*! @name LPTMR_CTRL - LPTMR Source Control */
/*! @{ */

#define SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_0_MASK  (0x1U)
#define SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_0_SHIFT (0U)
/*! LPTMR_CTRL_0 - Selects 0th pulse counter input of LPTMR
 *  0b0..Selects input from CMP0
 *  0b1..Selects input from PAD P0_4/P0_14 ALT4 MODE (LPTMRn_ALT0)
 */
#define SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_0(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_0_SHIFT)) & SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_0_MASK)

#define SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_1_MASK  (0x2U)
#define SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_1_SHIFT (1U)
/*! LPTMR_CTRL_1 - Selects 1st pulse counter input of LPTMR
 *  0b0..Selects input from AON.ACMP0
 *  0b1..Selects input from Pad P0_3/P0_5/P0_15 ALT4 MODE (LPTMRn_ALT1)
 */
#define SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_1(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_1_SHIFT)) & SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_1_MASK)

#define SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_2_MASK  (0x4U)
#define SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_2_SHIFT (2U)
/*! LPTMR_CTRL_2 - Used to select 2nd pulse counter input of LPTMR
 *  0b0..Choose Input from AON.LPCMP
 *  0b1..Choose Input from PAD P0_2/P0_12/P0_16 ALT4 MODE (LPTMRn_ALT2)
 */
#define SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_2(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_2_SHIFT)) & SYSCON_AON_LPTMR_CTRL_LPTMR_CTRL_2_MASK)
/*! @} */

/*! @name CPU_SLEEP_SELECT - CPU Sleep Select */
/*! @{ */

#define SYSCON_AON_CPU_SLEEP_SELECT_IPG_DOZE_CM0_SEL_MASK (0x1U)
#define SYSCON_AON_CPU_SLEEP_SELECT_IPG_DOZE_CM0_SEL_SHIFT (0U)
/*! IPG_DOZE_CM0_SEL
 *  0b0..Sleep not selected for IPG_DOZE
 *  0b1..Sleep selected for IPG_DOZE
 */
#define SYSCON_AON_CPU_SLEEP_SELECT_IPG_DOZE_CM0_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_CPU_SLEEP_SELECT_IPG_DOZE_CM0_SEL_SHIFT)) & SYSCON_AON_CPU_SLEEP_SELECT_IPG_DOZE_CM0_SEL_MASK)
/*! @} */

/*! @name PULSE_CAP_ACMP_CLK_MUXSEL - CMP Pulse Capture Clock MUXSEL */
/*! @{ */

#define SYSCON_AON_PULSE_CAP_ACMP_CLK_MUXSEL_ACMP0_PULSE_CAP_SYNC_CLK_MUX_SEL_MASK (0x3U)
#define SYSCON_AON_PULSE_CAP_ACMP_CLK_MUXSEL_ACMP0_PULSE_CAP_SYNC_CLK_MUX_SEL_SHIFT (0U)
/*! ACMP0_PULSE_CAP_SYNC_CLK_MUX_SEL - Clock source select for ACMP0
 *  0b00..ACMP0 Functional clock[0]
 *  0b01..ACMP0 Functional clock[1]
 *  0b10..ACMP0 Functional clock[2]
 *  0b11..ACMP0 Functional clock[3]
 */
#define SYSCON_AON_PULSE_CAP_ACMP_CLK_MUXSEL_ACMP0_PULSE_CAP_SYNC_CLK_MUX_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_PULSE_CAP_ACMP_CLK_MUXSEL_ACMP0_PULSE_CAP_SYNC_CLK_MUX_SEL_SHIFT)) & SYSCON_AON_PULSE_CAP_ACMP_CLK_MUXSEL_ACMP0_PULSE_CAP_SYNC_CLK_MUX_SEL_MASK)
/*! @} */

/*! @name PINMUXCLKCTRL - Pinmux Clock Control */
/*! @{ */

#define SYSCON_AON_PINMUXCLKCTRL_PINMUX_CLK_CTRL_MASK (0x1U)
#define SYSCON_AON_PINMUXCLKCTRL_PINMUX_CLK_CTRL_SHIFT (0U)
/*! PINMUX_CLK_CTRL - This signal acts as a clock disable signal for pinmux clock
 *  0b0..Clock is not disabled
 *  0b1..Clock is disabled
 */
#define SYSCON_AON_PINMUXCLKCTRL_PINMUX_CLK_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_PINMUXCLKCTRL_PINMUX_CLK_CTRL_SHIFT)) & SYSCON_AON_PINMUXCLKCTRL_PINMUX_CLK_CTRL_MASK)
/*! @} */

/*! @name SYNC_EN_INPUTMUX_AON - Synchronization Enable INPUTMUX */
/*! @{ */

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR1_AON_TMR3_PIN_SYNC_EN_MASK (0x1U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR1_AON_TMR3_PIN_SYNC_EN_SHIFT (0U)
/*! QTMR1_AON_TMR3_PIN_SYNC_EN - Enable or bypass synchronization for AON.QTMR1 timer 3 pin.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR1_AON_TMR3_PIN_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR1_AON_TMR3_PIN_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR1_AON_TMR3_PIN_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR2_PIN_SYNC_EN_MASK (0x2U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR2_PIN_SYNC_EN_SHIFT (1U)
/*! QMTR1_AON_TMR2_PIN_SYNC_EN - Enable or bypass synchronization for AON.QTMR1 timer 2 pin.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR2_PIN_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR2_PIN_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR2_PIN_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR1_PIN_SYNC_EN_MASK (0x4U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR1_PIN_SYNC_EN_SHIFT (2U)
/*! QMTR1_AON_TMR1_PIN_SYNC_EN - Enable or bypass synchronization for AON.QTMR1 timer 1 pin.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR1_PIN_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR1_PIN_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR1_PIN_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR0_PIN_SYNC_EN_MASK (0x8U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR0_PIN_SYNC_EN_SHIFT (3U)
/*! QMTR1_AON_TMR0_PIN_SYNC_EN - Enable or bypass synchronization for AON.QTMR1 timer 0 pin.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR0_PIN_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR0_PIN_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR1_AON_TMR0_PIN_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR0_AON_TMR3_PIN_SYNC_EN_MASK (0x10U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR0_AON_TMR3_PIN_SYNC_EN_SHIFT (4U)
/*! QTMR0_AON_TMR3_PIN_SYNC_EN - Enable or bypass synchronization for AON.QTMR0 timer 3 pin.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR0_AON_TMR3_PIN_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR0_AON_TMR3_PIN_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR0_AON_TMR3_PIN_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR0_AON_TMR2_PIN_SYNC_EN_MASK (0x20U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR0_AON_TMR2_PIN_SYNC_EN_SHIFT (5U)
/*! QMTR0_AON_TMR2_PIN_SYNC_EN - Enable or bypass synchronization for AON.QTMR0 timer 2 pin.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR0_AON_TMR2_PIN_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR0_AON_TMR2_PIN_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_QMTR0_AON_TMR2_PIN_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR_AON_TMR1_PIN_SYNC_EN_MASK (0x40U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR_AON_TMR1_PIN_SYNC_EN_SHIFT (6U)
/*! QTMR_AON_TMR1_PIN_SYNC_EN - Enable or bypass synchronization for AON.QTMR0 timer 1 pin.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR_AON_TMR1_PIN_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR_AON_TMR1_PIN_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR_AON_TMR1_PIN_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR0_AON_TMR0_PIN_SYNC_EN_MASK (0x80U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR0_AON_TMR0_PIN_SYNC_EN_SHIFT (7U)
/*! QTMR0_AON_TMR0_PIN_SYNC_EN - Enable or bypass synchronization for AON.QTMR0 timer 0 pin.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR0_AON_TMR0_PIN_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR0_AON_TMR0_PIN_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_QTMR0_AON_TMR0_PIN_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPUART0_AON_TRIG_SYNC_EN_MASK (0x100U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPUART0_AON_TRIG_SYNC_EN_SHIFT (8U)
/*! LPUART0_AON_TRIG_SYNC_EN - Enable or bypass synchronization for AON.LPUART0 trigger.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPUART0_AON_TRIG_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPUART0_AON_TRIG_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPUART0_AON_TRIG_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPTMR0_AON_DMA_DONE_TRIG_SYNC_EN_MASK (0x200U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPTMR0_AON_DMA_DONE_TRIG_SYNC_EN_SHIFT (9U)
/*! LPTMR0_AON_DMA_DONE_TRIG_SYNC_EN - Enable or bypass synchronization for AON.LPTMR0 DMA done trigger.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPTMR0_AON_DMA_DONE_TRIG_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPTMR0_AON_DMA_DONE_TRIG_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPTMR0_AON_DMA_DONE_TRIG_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG3_SYNC_EN_MASK (0x400U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG3_SYNC_EN_SHIFT (10U)
/*! LPACMP_TRIG3_SYNC_EN - Enable or bypass synchronization for AON.LPACMP0 trigger 3.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG3_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG3_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG3_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG2_SYNC_EN_MASK (0x800U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG2_SYNC_EN_SHIFT (11U)
/*! LPACMP_TRIG2_SYNC_EN - Enable or bypass synchronization for AON.LPACMP0 trigger 2.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG2_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG2_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG2_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG1_SYNC_EN_MASK (0x1000U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG1_SYNC_EN_SHIFT (12U)
/*! LPACMP_TRIG1_SYNC_EN - Enable or bypass synchronization for AON.LPACMP0 trigger 1.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG1_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG1_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG1_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG0_SYNC_EN_MASK (0x2000U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG0_SYNC_EN_SHIFT (13U)
/*! LPACMP_TRIG0_SYNC_EN
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG0_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG0_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_LPACMP_TRIG0_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LC_SENSE_SYNC_EN_MASK (0x4000U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LC_SENSE_SYNC_EN_SHIFT (14U)
/*! LC_SENSE_SYNC_EN - Enable or bypass synchronization for LC Sense glue logic.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_LC_SENSE_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_LC_SENSE_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_LC_SENSE_SYNC_EN_MASK)

#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_ACMP0_AON_SAMPLE_SYNC_EN_MASK (0x8000U)
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_ACMP0_AON_SAMPLE_SYNC_EN_SHIFT (15U)
/*! ACMP0_AON_SAMPLE_SYNC_EN - Enable or bypass synchronization for AON.ACMP0.
 *  0b0..Synchronization is bypassed
 *  0b1..Synchronization is enabled
 */
#define SYSCON_AON_SYNC_EN_INPUTMUX_AON_ACMP0_AON_SAMPLE_SYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SYNC_EN_INPUTMUX_AON_ACMP0_AON_SAMPLE_SYNC_EN_SHIFT)) & SYSCON_AON_SYNC_EN_INPUTMUX_AON_ACMP0_AON_SAMPLE_SYNC_EN_MASK)
/*! @} */

/*! @name IPG_DEBUG_ENABLE - IPG Debug Enable */
/*! @{ */

#define SYSCON_AON_IPG_DEBUG_ENABLE_IPG_DEBUGEN_CM0_SEL_MASK (0x1U)
#define SYSCON_AON_IPG_DEBUG_ENABLE_IPG_DEBUGEN_CM0_SEL_SHIFT (0U)
/*! IPG_DEBUGEN_CM0_SEL - IPG Debug enable for CM0+
 *  0b0..If disabled do not allow AON-debug on CM0+ debug request
 *  0b1..If enabled allow AON-debug on CM0+ debug request
 */
#define SYSCON_AON_IPG_DEBUG_ENABLE_IPG_DEBUGEN_CM0_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_IPG_DEBUG_ENABLE_IPG_DEBUGEN_CM0_SEL_SHIFT)) & SYSCON_AON_IPG_DEBUG_ENABLE_IPG_DEBUGEN_CM0_SEL_MASK)

#define SYSCON_AON_IPG_DEBUG_ENABLE_IPG_DEBUGEN_CM33_SEL_MASK (0x2U)
#define SYSCON_AON_IPG_DEBUG_ENABLE_IPG_DEBUGEN_CM33_SEL_SHIFT (1U)
/*! IPG_DEBUGEN_CM33_SEL - IPG Debug Enable for CM33
 *  0b0..If disabled, do not allow AON-debug on CM33 debug request
 *  0b1..If enabled, allow AON-debug on CM33 debug request
 */
#define SYSCON_AON_IPG_DEBUG_ENABLE_IPG_DEBUGEN_CM33_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_IPG_DEBUG_ENABLE_IPG_DEBUGEN_CM33_SEL_SHIFT)) & SYSCON_AON_IPG_DEBUG_ENABLE_IPG_DEBUGEN_CM33_SEL_MASK)
/*! @} */

/*! @name XTAL_32K_CLKCTRL -  */
/*! @{ */

#define SYSCON_AON_XTAL_32K_CLKCTRL_XTAL_32K_CLK_CTRL_MASK (0x1U)
#define SYSCON_AON_XTAL_32K_CLKCTRL_XTAL_32K_CLK_CTRL_SHIFT (0U)
/*! XTAL_32K_CLK_CTRL - This signal acts as a clock enable/disable signal for XTAL 32k clock
 *  0b0..Clock is enabled
 *  0b1..Clock is disabled
 */
#define SYSCON_AON_XTAL_32K_CLKCTRL_XTAL_32K_CLK_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_XTAL_32K_CLKCTRL_XTAL_32K_CLK_CTRL_SHIFT)) & SYSCON_AON_XTAL_32K_CLKCTRL_XTAL_32K_CLK_CTRL_MASK)
/*! @} */

/*! @name TAMPER_FLT_STAT - Tamper Fault Status */
/*! @{ */

#define SYSCON_AON_TAMPER_FLT_STAT_LC_TAMPER_FAULT_MASK (0x1U)
#define SYSCON_AON_TAMPER_FLT_STAT_LC_TAMPER_FAULT_SHIFT (0U)
/*! LC_TAMPER_FAULT - LC Tamper Fault */
#define SYSCON_AON_TAMPER_FLT_STAT_LC_TAMPER_FAULT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_TAMPER_FLT_STAT_LC_TAMPER_FAULT_SHIFT)) & SYSCON_AON_TAMPER_FLT_STAT_LC_TAMPER_FAULT_MASK)
/*! @} */

/*! @name TAMPER_FLT_EN - Tamper Fault Enable */
/*! @{ */

#define SYSCON_AON_TAMPER_FLT_EN_LC_TAMPER_FAULT_ENABLE_MASK (0x1U)
#define SYSCON_AON_TAMPER_FLT_EN_LC_TAMPER_FAULT_ENABLE_SHIFT (0U)
/*! LC_TAMPER_FAULT_ENABLE - Enables an interrupt to be generated when a LC sense tamper/fault is detected.
 *  0b0..Disables interrupt
 *  0b1..Enables interrupt
 */
#define SYSCON_AON_TAMPER_FLT_EN_LC_TAMPER_FAULT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_TAMPER_FLT_EN_LC_TAMPER_FAULT_ENABLE_SHIFT)) & SYSCON_AON_TAMPER_FLT_EN_LC_TAMPER_FAULT_ENABLE_MASK)
/*! @} */

/*! @name SECURITY_GLITCH_DETECT_ENABLE - Security Glitch Detect Enable */
/*! @{ */

#define SYSCON_AON_SECURITY_GLITCH_DETECT_ENABLE_SEC_GLITCH_DET_EN_MASK (0x1U)
#define SYSCON_AON_SECURITY_GLITCH_DETECT_ENABLE_SEC_GLITCH_DET_EN_SHIFT (0U)
/*! SEC_GLITCH_DET_EN
 *  0b0..Disables security glitch detect
 *  0b1..Enables security glitch detect
 */
#define SYSCON_AON_SECURITY_GLITCH_DETECT_ENABLE_SEC_GLITCH_DET_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AON_SECURITY_GLITCH_DETECT_ENABLE_SEC_GLITCH_DET_EN_SHIFT)) & SYSCON_AON_SECURITY_GLITCH_DETECT_ENABLE_SEC_GLITCH_DET_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON_AON_Register_Masks */


/*!
 * @}
 */ /* end of group SYSCON_AON_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSCON_AON_H_ */

