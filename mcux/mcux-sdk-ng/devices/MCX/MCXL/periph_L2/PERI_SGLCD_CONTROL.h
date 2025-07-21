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
**         CMSIS Peripheral Access Layer for SGLCD_CONTROL
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
 * @file PERI_SGLCD_CONTROL.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for SGLCD_CONTROL
 *
 * CMSIS Peripheral Access Layer for SGLCD_CONTROL
 */

#if !defined(PERI_SGLCD_CONTROL_H_)
#define PERI_SGLCD_CONTROL_H_                    /**< Symbol preventing repeated inclusion */

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
   -- SGLCD_CONTROL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SGLCD_CONTROL_Peripheral_Access_Layer SGLCD_CONTROL Peripheral Access Layer
 * @{
 */

/** SGLCD_CONTROL - Size of Registers Arrays */
#define SGLCD_CONTROL_PEN_COUNT                   2u
#define SGLCD_CONTROL_BPEN_COUNT                  2u
#define SGLCD_CONTROL_WF_ACCESS_WF8BIT_WF8B_COUNT 56u
#define SGLCD_CONTROL_WF_ACCESS_WF32BIT_WF_COUNT  14u

/** SGLCD_CONTROL - Register Layout Typedef */
typedef struct {
  __IO uint32_t GCR;                               /**< LCD General Control Register, offset: 0x0 */
  __IO uint32_t AR;                                /**< LCD Auxiliary Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t PEN[SGLCD_CONTROL_PEN_COUNT];      /**< LCD Pin Enable register 0..LCD Pin Enable register 1, array offset: 0x10, array step: 0x4 */
  __IO uint32_t BPEN[SGLCD_CONTROL_BPEN_COUNT];    /**< LCD Back Plane Enable register 0..LCD Back Plane Enable register 1, array offset: 0x18, array step: 0x4 */
  union {                                          /* offset: 0x20 */
    __IO uint8_t WF8B[SGLCD_CONTROL_WF_ACCESS_WF8BIT_WF8B_COUNT];   /**< LCD Waveform 0 Register..LCD Waveform 55 Register, array offset: 0x20, array step: 0x1 */
    __IO uint32_t WF[SGLCD_CONTROL_WF_ACCESS_WF32BIT_WF_COUNT];   /**< LCD Waveform 3 to 0 Register..LCD Waveform 55 to 52 Register, array offset: 0x20, array step: 0x4 */
  };
} SGLCD_CONTROL_Type;

/* ----------------------------------------------------------------------------
   -- SGLCD_CONTROL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SGLCD_CONTROL_Register_Masks SGLCD_CONTROL Register Masks
 * @{
 */

/*! @name GCR - LCD General Control Register */
/*! @{ */

#define SGLCD_CONTROL_GCR_DUTY_MASK              (0x3U)
#define SGLCD_CONTROL_GCR_DUTY_SHIFT             (0U)
/*! DUTY - LCD duty select
 *  0b00..Use 1 BP (1/1 duty cycle).
 *  0b01..Use 2 BP (1/2 duty cycle).
 *  0b10..Use 3 BP (1/3 duty cycle).
 *  0b11..Use 4 BP (1/4 duty cycle).(Default)
 */
#define SGLCD_CONTROL_GCR_DUTY(x)                (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_DUTY_SHIFT)) & SGLCD_CONTROL_GCR_DUTY_MASK)

#define SGLCD_CONTROL_GCR_FCLK_FREQ_MASK         (0x4U)
#define SGLCD_CONTROL_GCR_FCLK_FREQ_SHIFT        (2U)
/*! FCLK_FREQ - LCD Functional Clock Frequency Select
 *  0b0..LCD functional clock is 16kHz.
 *  0b1..LCD functional clock is 8kHz.
 */
#define SGLCD_CONTROL_GCR_FCLK_FREQ(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_FCLK_FREQ_SHIFT)) & SGLCD_CONTROL_GCR_FCLK_FREQ_MASK)

#define SGLCD_CONTROL_GCR_LCLK_MASK              (0x38U)
#define SGLCD_CONTROL_GCR_LCLK_SHIFT             (3U)
/*! LCLK - LCD Clock Prescaler */
#define SGLCD_CONTROL_GCR_LCLK(x)                (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_LCLK_SHIFT)) & SGLCD_CONTROL_GCR_LCLK_MASK)

#define SGLCD_CONTROL_GCR_LCDLP_MASK             (0x40U)
#define SGLCD_CONTROL_GCR_LCDLP_SHIFT            (6U)
/*! LCDLP - LCD Low Power Waveform
 *  0b0..LCD driver drives standard waveforms.
 *  0b1..LCD driver drives low-power waveforms.
 */
#define SGLCD_CONTROL_GCR_LCDLP(x)               (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_LCDLP_SHIFT)) & SGLCD_CONTROL_GCR_LCDLP_MASK)

#define SGLCD_CONTROL_GCR_LCDEN_MASK             (0x80U)
#define SGLCD_CONTROL_GCR_LCDEN_SHIFT            (7U)
/*! LCDEN - LCD Driver Enable */
#define SGLCD_CONTROL_GCR_LCDEN(x)               (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_LCDEN_SHIFT)) & SGLCD_CONTROL_GCR_LCDEN_MASK)

#define SGLCD_CONTROL_GCR_LCDSTP_MASK            (0x100U)
#define SGLCD_CONTROL_GCR_LCDSTP_SHIFT           (8U)
/*! LCDSTP - LCD Stop
 *  0b0..Allows the LCD driver to continue running during Stop mode.
 *  0b1..Disables the LCD driver when MCU enters Stop mode.
 */
#define SGLCD_CONTROL_GCR_LCDSTP(x)              (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_LCDSTP_SHIFT)) & SGLCD_CONTROL_GCR_LCDSTP_MASK)

#define SGLCD_CONTROL_GCR_LCDDOZE_MASK           (0x200U)
#define SGLCD_CONTROL_GCR_LCDDOZE_SHIFT          (9U)
/*! LCDDOZE - LCD Doze enable
 *  0b0..Allows the LCD driver to continue running during Doze mode.
 *  0b1..Disables the LCD driver when MCU enters Doze mode.
 */
#define SGLCD_CONTROL_GCR_LCDDOZE(x)             (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_LCDDOZE_SHIFT)) & SGLCD_CONTROL_GCR_LCDDOZE_MASK)

#define SGLCD_CONTROL_GCR_LCDIEN_MASK            (0x8000U)
#define SGLCD_CONTROL_GCR_LCDIEN_SHIFT           (15U)
/*! LCDIEN - LCD Frame Frequency Interrupt Enable
 *  0b0..No interrupt request is generated by this event.
 *  0b1..When LCDIF bit is set, this event causes an interrupt request.
 */
#define SGLCD_CONTROL_GCR_LCDIEN(x)              (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_LCDIEN_SHIFT)) & SGLCD_CONTROL_GCR_LCDIEN_MASK)

#define SGLCD_CONTROL_GCR_SHCYCLE_MASK           (0x10000U)
#define SGLCD_CONTROL_GCR_SHCYCLE_SHIFT          (16U)
/*! SHCYCLE - Sample & Hold Cycle Select
 *  0b0..Sample & hold phase clock period is 64 LCD clock (16kHz) period / 32 LCD clock (8kHz) period.
 *  0b1..Sample & hold phase clock period is 128 LCD clk (16kHz) period / 64 LCD clock (8kHz) period.
 */
#define SGLCD_CONTROL_GCR_SHCYCLE(x)             (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_SHCYCLE_SHIFT)) & SGLCD_CONTROL_GCR_SHCYCLE_MASK)

#define SGLCD_CONTROL_GCR_SHEN_MASK              (0x800000U)
#define SGLCD_CONTROL_GCR_SHEN_SHIFT             (23U)
/*! SHEN - Sample & Hold Mode Enable
 *  0b0..Sample & hold is disabled.
 *  0b1..Sample & hold is enabled.
 */
#define SGLCD_CONTROL_GCR_SHEN(x)                (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_SHEN_SHIFT)) & SGLCD_CONTROL_GCR_SHEN_MASK)

#define SGLCD_CONTROL_GCR_VLL1TRIM_MASK          (0xF000000U)
#define SGLCD_CONTROL_GCR_VLL1TRIM_SHIFT         (24U)
/*! VLL1TRIM - Level 1 Voltage Trim */
#define SGLCD_CONTROL_GCR_VLL1TRIM(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_VLL1TRIM_SHIFT)) & SGLCD_CONTROL_GCR_VLL1TRIM_MASK)

#define SGLCD_CONTROL_GCR_VLL2TRIM_MASK          (0xF0000000U)
#define SGLCD_CONTROL_GCR_VLL2TRIM_SHIFT         (28U)
/*! VLL2TRIM - Level 2 Voltage Trim */
#define SGLCD_CONTROL_GCR_VLL2TRIM(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_GCR_VLL2TRIM_SHIFT)) & SGLCD_CONTROL_GCR_VLL2TRIM_MASK)
/*! @} */

/*! @name AR - LCD Auxiliary Register */
/*! @{ */

#define SGLCD_CONTROL_AR_BRATE_MASK              (0x7U)
#define SGLCD_CONTROL_AR_BRATE_SHIFT             (0U)
/*! BRATE - Blink-rate configuration */
#define SGLCD_CONTROL_AR_BRATE(x)                (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_AR_BRATE_SHIFT)) & SGLCD_CONTROL_AR_BRATE_MASK)

#define SGLCD_CONTROL_AR_BMODE_MASK              (0x8U)
#define SGLCD_CONTROL_AR_BMODE_SHIFT             (3U)
/*! BMODE - Blink mode
 *  0b0..Display blank during the blink period.
 *  0b1..Display alternate display during blink period.
 */
#define SGLCD_CONTROL_AR_BMODE(x)                (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_AR_BMODE_SHIFT)) & SGLCD_CONTROL_AR_BMODE_MASK)

#define SGLCD_CONTROL_AR_BLANK_MASK              (0x20U)
#define SGLCD_CONTROL_AR_BLANK_SHIFT             (5U)
/*! BLANK - Blank display mode
 *  0b0..Normal or alternate display mode.
 *  0b1..Blank display mode.
 */
#define SGLCD_CONTROL_AR_BLANK(x)                (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_AR_BLANK_SHIFT)) & SGLCD_CONTROL_AR_BLANK_MASK)

#define SGLCD_CONTROL_AR_ALT_MASK                (0x40U)
#define SGLCD_CONTROL_AR_ALT_SHIFT               (6U)
/*! ALT - Alternate display mode
 *  0b0..Normal display mode.
 *  0b1..Alternate display mode.
 */
#define SGLCD_CONTROL_AR_ALT(x)                  (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_AR_ALT_SHIFT)) & SGLCD_CONTROL_AR_ALT_MASK)

#define SGLCD_CONTROL_AR_BLINK_MASK              (0x80U)
#define SGLCD_CONTROL_AR_BLINK_SHIFT             (7U)
/*! BLINK - Blink command
 *  0b0..Disables blinking.
 *  0b1..Starts blinking at blinking frequency specified by LCD blink rate calculation.
 */
#define SGLCD_CONTROL_AR_BLINK(x)                (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_AR_BLINK_SHIFT)) & SGLCD_CONTROL_AR_BLINK_MASK)

#define SGLCD_CONTROL_AR_LCDIF_MASK              (0x8000U)
#define SGLCD_CONTROL_AR_LCDIF_SHIFT             (15U)
/*! LCDIF - LCD Frame Frequency Interrupt flag
 *  0b0..Frame frequency interrupt condition has not occurred.
 *  0b1..Start of SLCD frame has occurred.
 */
#define SGLCD_CONTROL_AR_LCDIF(x)                (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_AR_LCDIF_SHIFT)) & SGLCD_CONTROL_AR_LCDIF_MASK)
/*! @} */

/*! @name PEN - LCD Pin Enable register 0..LCD Pin Enable register 1 */
/*! @{ */

#define SGLCD_CONTROL_PEN_PIN_0_EN_MASK          (0x1U)
#define SGLCD_CONTROL_PEN_PIN_0_EN_SHIFT         (0U)
/*! PIN_0_EN - LCD Pin 0 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_0_EN(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_0_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_0_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_32_EN_MASK         (0x1U)
#define SGLCD_CONTROL_PEN_PIN_32_EN_SHIFT        (0U)
/*! PIN_32_EN - LCD Pin 32 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_32_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_32_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_32_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_1_EN_MASK          (0x2U)
#define SGLCD_CONTROL_PEN_PIN_1_EN_SHIFT         (1U)
/*! PIN_1_EN - LCD Pin 1 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_1_EN(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_1_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_1_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_33_EN_MASK         (0x2U)
#define SGLCD_CONTROL_PEN_PIN_33_EN_SHIFT        (1U)
/*! PIN_33_EN - LCD Pin 33 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_33_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_33_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_33_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_2_EN_MASK          (0x4U)
#define SGLCD_CONTROL_PEN_PIN_2_EN_SHIFT         (2U)
/*! PIN_2_EN - LCD Pin 2 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_2_EN(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_2_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_2_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_34_EN_MASK         (0x4U)
#define SGLCD_CONTROL_PEN_PIN_34_EN_SHIFT        (2U)
/*! PIN_34_EN - LCD Pin 34 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_34_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_34_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_34_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_3_EN_MASK          (0x8U)
#define SGLCD_CONTROL_PEN_PIN_3_EN_SHIFT         (3U)
/*! PIN_3_EN - LCD Pin 3 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_3_EN(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_3_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_3_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_35_EN_MASK         (0x8U)
#define SGLCD_CONTROL_PEN_PIN_35_EN_SHIFT        (3U)
/*! PIN_35_EN - LCD Pin 35 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_35_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_35_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_35_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_4_EN_MASK          (0x10U)
#define SGLCD_CONTROL_PEN_PIN_4_EN_SHIFT         (4U)
/*! PIN_4_EN - LCD Pin 4 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_4_EN(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_4_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_4_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_36_EN_MASK         (0x10U)
#define SGLCD_CONTROL_PEN_PIN_36_EN_SHIFT        (4U)
/*! PIN_36_EN - LCD Pin 36 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_36_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_36_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_36_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_5_EN_MASK          (0x20U)
#define SGLCD_CONTROL_PEN_PIN_5_EN_SHIFT         (5U)
/*! PIN_5_EN - LCD Pin 5 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_5_EN(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_5_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_5_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_37_EN_MASK         (0x20U)
#define SGLCD_CONTROL_PEN_PIN_37_EN_SHIFT        (5U)
/*! PIN_37_EN - LCD Pin 37 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_37_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_37_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_37_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_6_EN_MASK          (0x40U)
#define SGLCD_CONTROL_PEN_PIN_6_EN_SHIFT         (6U)
/*! PIN_6_EN - LCD Pin 6 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_6_EN(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_6_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_6_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_38_EN_MASK         (0x40U)
#define SGLCD_CONTROL_PEN_PIN_38_EN_SHIFT        (6U)
/*! PIN_38_EN - LCD Pin 38 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_38_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_38_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_38_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_7_EN_MASK          (0x80U)
#define SGLCD_CONTROL_PEN_PIN_7_EN_SHIFT         (7U)
/*! PIN_7_EN - LCD Pin 7 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_7_EN(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_7_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_7_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_39_EN_MASK         (0x80U)
#define SGLCD_CONTROL_PEN_PIN_39_EN_SHIFT        (7U)
/*! PIN_39_EN - LCD Pin 39 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_39_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_39_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_39_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_8_EN_MASK          (0x100U)
#define SGLCD_CONTROL_PEN_PIN_8_EN_SHIFT         (8U)
/*! PIN_8_EN - LCD Pin 8 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_8_EN(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_8_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_8_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_40_EN_MASK         (0x100U)
#define SGLCD_CONTROL_PEN_PIN_40_EN_SHIFT        (8U)
/*! PIN_40_EN - LCD Pin 40 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_40_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_40_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_40_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_9_EN_MASK          (0x200U)
#define SGLCD_CONTROL_PEN_PIN_9_EN_SHIFT         (9U)
/*! PIN_9_EN - LCD Pin 9 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_9_EN(x)            (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_9_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_9_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_41_EN_MASK         (0x200U)
#define SGLCD_CONTROL_PEN_PIN_41_EN_SHIFT        (9U)
/*! PIN_41_EN - LCD Pin 41 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_41_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_41_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_41_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_10_EN_MASK         (0x400U)
#define SGLCD_CONTROL_PEN_PIN_10_EN_SHIFT        (10U)
/*! PIN_10_EN - LCD Pin 10 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_10_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_10_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_10_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_42_EN_MASK         (0x400U)
#define SGLCD_CONTROL_PEN_PIN_42_EN_SHIFT        (10U)
/*! PIN_42_EN - LCD Pin 42 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_42_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_42_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_42_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_11_EN_MASK         (0x800U)
#define SGLCD_CONTROL_PEN_PIN_11_EN_SHIFT        (11U)
/*! PIN_11_EN - LCD Pin 11 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_11_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_11_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_11_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_43_EN_MASK         (0x800U)
#define SGLCD_CONTROL_PEN_PIN_43_EN_SHIFT        (11U)
/*! PIN_43_EN - LCD Pin 43 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_43_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_43_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_43_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_12_EN_MASK         (0x1000U)
#define SGLCD_CONTROL_PEN_PIN_12_EN_SHIFT        (12U)
/*! PIN_12_EN - LCD Pin 12 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_12_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_12_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_12_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_44_EN_MASK         (0x1000U)
#define SGLCD_CONTROL_PEN_PIN_44_EN_SHIFT        (12U)
/*! PIN_44_EN - LCD Pin 44 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_44_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_44_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_44_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_13_EN_MASK         (0x2000U)
#define SGLCD_CONTROL_PEN_PIN_13_EN_SHIFT        (13U)
/*! PIN_13_EN - LCD Pin 13 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_13_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_13_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_13_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_45_EN_MASK         (0x2000U)
#define SGLCD_CONTROL_PEN_PIN_45_EN_SHIFT        (13U)
/*! PIN_45_EN - LCD Pin 45 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_45_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_45_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_45_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_14_EN_MASK         (0x4000U)
#define SGLCD_CONTROL_PEN_PIN_14_EN_SHIFT        (14U)
/*! PIN_14_EN - LCD Pin 14 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_14_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_14_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_14_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_46_EN_MASK         (0x4000U)
#define SGLCD_CONTROL_PEN_PIN_46_EN_SHIFT        (14U)
/*! PIN_46_EN - LCD Pin 46 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_46_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_46_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_46_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_15_EN_MASK         (0x8000U)
#define SGLCD_CONTROL_PEN_PIN_15_EN_SHIFT        (15U)
/*! PIN_15_EN - LCD Pin 15 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_15_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_15_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_15_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_47_EN_MASK         (0x8000U)
#define SGLCD_CONTROL_PEN_PIN_47_EN_SHIFT        (15U)
/*! PIN_47_EN - LCD Pin 47 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_47_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_47_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_47_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_16_EN_MASK         (0x10000U)
#define SGLCD_CONTROL_PEN_PIN_16_EN_SHIFT        (16U)
/*! PIN_16_EN - LCD Pin 16 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_16_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_16_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_16_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_48_EN_MASK         (0x10000U)
#define SGLCD_CONTROL_PEN_PIN_48_EN_SHIFT        (16U)
/*! PIN_48_EN - LCD Pin 48 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_48_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_48_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_48_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_17_EN_MASK         (0x20000U)
#define SGLCD_CONTROL_PEN_PIN_17_EN_SHIFT        (17U)
/*! PIN_17_EN - LCD Pin 17 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_17_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_17_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_17_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_49_EN_MASK         (0x20000U)
#define SGLCD_CONTROL_PEN_PIN_49_EN_SHIFT        (17U)
/*! PIN_49_EN - LCD Pin 49 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_49_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_49_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_49_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_18_EN_MASK         (0x40000U)
#define SGLCD_CONTROL_PEN_PIN_18_EN_SHIFT        (18U)
/*! PIN_18_EN - LCD Pin 18 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_18_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_18_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_18_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_50_EN_MASK         (0x40000U)
#define SGLCD_CONTROL_PEN_PIN_50_EN_SHIFT        (18U)
/*! PIN_50_EN - LCD Pin 50 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_50_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_50_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_50_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_19_EN_MASK         (0x80000U)
#define SGLCD_CONTROL_PEN_PIN_19_EN_SHIFT        (19U)
/*! PIN_19_EN - LCD Pin 19 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_19_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_19_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_19_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_51_EN_MASK         (0x80000U)
#define SGLCD_CONTROL_PEN_PIN_51_EN_SHIFT        (19U)
/*! PIN_51_EN - LCD Pin 51 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_51_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_51_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_51_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_20_EN_MASK         (0x100000U)
#define SGLCD_CONTROL_PEN_PIN_20_EN_SHIFT        (20U)
/*! PIN_20_EN - LCD Pin 20 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_20_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_20_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_20_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_52_EN_MASK         (0x100000U)
#define SGLCD_CONTROL_PEN_PIN_52_EN_SHIFT        (20U)
/*! PIN_52_EN - LCD Pin 52 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_52_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_52_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_52_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_21_EN_MASK         (0x200000U)
#define SGLCD_CONTROL_PEN_PIN_21_EN_SHIFT        (21U)
/*! PIN_21_EN - LCD Pin 21 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_21_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_21_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_21_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_53_EN_MASK         (0x200000U)
#define SGLCD_CONTROL_PEN_PIN_53_EN_SHIFT        (21U)
/*! PIN_53_EN - LCD Pin 53 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_53_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_53_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_53_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_22_EN_MASK         (0x400000U)
#define SGLCD_CONTROL_PEN_PIN_22_EN_SHIFT        (22U)
/*! PIN_22_EN - LCD Pin 22 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_22_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_22_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_22_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_54_EN_MASK         (0x400000U)
#define SGLCD_CONTROL_PEN_PIN_54_EN_SHIFT        (22U)
/*! PIN_54_EN - LCD Pin 54 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_54_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_54_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_54_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_23_EN_MASK         (0x800000U)
#define SGLCD_CONTROL_PEN_PIN_23_EN_SHIFT        (23U)
/*! PIN_23_EN - LCD Pin 23 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_23_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_23_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_23_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_55_EN_MASK         (0x800000U)
#define SGLCD_CONTROL_PEN_PIN_55_EN_SHIFT        (23U)
/*! PIN_55_EN - LCD Pin 55 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_55_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_55_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_55_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_24_EN_MASK         (0x1000000U)
#define SGLCD_CONTROL_PEN_PIN_24_EN_SHIFT        (24U)
/*! PIN_24_EN - LCD Pin 24 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_24_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_24_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_24_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_25_EN_MASK         (0x2000000U)
#define SGLCD_CONTROL_PEN_PIN_25_EN_SHIFT        (25U)
/*! PIN_25_EN - LCD Pin 25 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_25_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_25_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_25_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_26_EN_MASK         (0x4000000U)
#define SGLCD_CONTROL_PEN_PIN_26_EN_SHIFT        (26U)
/*! PIN_26_EN - LCD Pin 26 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_26_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_26_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_26_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_27_EN_MASK         (0x8000000U)
#define SGLCD_CONTROL_PEN_PIN_27_EN_SHIFT        (27U)
/*! PIN_27_EN - LCD Pin 27 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_27_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_27_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_27_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_28_EN_MASK         (0x10000000U)
#define SGLCD_CONTROL_PEN_PIN_28_EN_SHIFT        (28U)
/*! PIN_28_EN - LCD Pin 28 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_28_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_28_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_28_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_29_EN_MASK         (0x20000000U)
#define SGLCD_CONTROL_PEN_PIN_29_EN_SHIFT        (29U)
/*! PIN_29_EN - LCD Pin 29 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_29_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_29_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_29_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_30_EN_MASK         (0x40000000U)
#define SGLCD_CONTROL_PEN_PIN_30_EN_SHIFT        (30U)
/*! PIN_30_EN - LCD Pin 30 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_30_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_30_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_30_EN_MASK)

#define SGLCD_CONTROL_PEN_PIN_31_EN_MASK         (0x80000000U)
#define SGLCD_CONTROL_PEN_PIN_31_EN_SHIFT        (31U)
/*! PIN_31_EN - LCD Pin 31 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_CONTROL_PEN_PIN_31_EN(x)           (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_PEN_PIN_31_EN_SHIFT)) & SGLCD_CONTROL_PEN_PIN_31_EN_MASK)
/*! @} */

/*! @name BPEN - LCD Back Plane Enable register 0..LCD Back Plane Enable register 1 */
/*! @{ */

#define SGLCD_CONTROL_BPEN_PIN_0_BPEN_MASK       (0x1U)
#define SGLCD_CONTROL_BPEN_PIN_0_BPEN_SHIFT      (0U)
/*! PIN_0_BPEN - LCD Pin 0 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_0_BPEN(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_0_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_0_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_32_BPEN_MASK      (0x1U)
#define SGLCD_CONTROL_BPEN_PIN_32_BPEN_SHIFT     (0U)
/*! PIN_32_BPEN - LCD Pin 32 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_32_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_32_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_32_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_1_BPEN_MASK       (0x2U)
#define SGLCD_CONTROL_BPEN_PIN_1_BPEN_SHIFT      (1U)
/*! PIN_1_BPEN - LCD Pin 1 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_1_BPEN(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_1_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_1_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_33_BPEN_MASK      (0x2U)
#define SGLCD_CONTROL_BPEN_PIN_33_BPEN_SHIFT     (1U)
/*! PIN_33_BPEN - LCD Pin 33 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_33_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_33_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_33_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_2_BPEN_MASK       (0x4U)
#define SGLCD_CONTROL_BPEN_PIN_2_BPEN_SHIFT      (2U)
/*! PIN_2_BPEN - LCD Pin 2 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_2_BPEN(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_2_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_2_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_34_BPEN_MASK      (0x4U)
#define SGLCD_CONTROL_BPEN_PIN_34_BPEN_SHIFT     (2U)
/*! PIN_34_BPEN - LCD Pin 34 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_34_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_34_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_34_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_3_BPEN_MASK       (0x8U)
#define SGLCD_CONTROL_BPEN_PIN_3_BPEN_SHIFT      (3U)
/*! PIN_3_BPEN - LCD Pin 3 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_3_BPEN(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_3_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_3_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_35_BPEN_MASK      (0x8U)
#define SGLCD_CONTROL_BPEN_PIN_35_BPEN_SHIFT     (3U)
/*! PIN_35_BPEN - LCD Pin 35 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_35_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_35_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_35_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_4_BPEN_MASK       (0x10U)
#define SGLCD_CONTROL_BPEN_PIN_4_BPEN_SHIFT      (4U)
/*! PIN_4_BPEN - LCD Pin 4 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_4_BPEN(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_4_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_4_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_36_BPEN_MASK      (0x10U)
#define SGLCD_CONTROL_BPEN_PIN_36_BPEN_SHIFT     (4U)
/*! PIN_36_BPEN - LCD Pin 36 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_36_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_36_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_36_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_5_BPEN_MASK       (0x20U)
#define SGLCD_CONTROL_BPEN_PIN_5_BPEN_SHIFT      (5U)
/*! PIN_5_BPEN - LCD Pin 5 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_5_BPEN(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_5_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_5_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_37_BPEN_MASK      (0x20U)
#define SGLCD_CONTROL_BPEN_PIN_37_BPEN_SHIFT     (5U)
/*! PIN_37_BPEN - LCD Pin 37 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_37_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_37_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_37_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_6_BPEN_MASK       (0x40U)
#define SGLCD_CONTROL_BPEN_PIN_6_BPEN_SHIFT      (6U)
/*! PIN_6_BPEN - LCD Pin 6 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_6_BPEN(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_6_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_6_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_38_BPEN_MASK      (0x40U)
#define SGLCD_CONTROL_BPEN_PIN_38_BPEN_SHIFT     (6U)
/*! PIN_38_BPEN - LCD Pin 38 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_38_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_38_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_38_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_7_BPEN_MASK       (0x80U)
#define SGLCD_CONTROL_BPEN_PIN_7_BPEN_SHIFT      (7U)
/*! PIN_7_BPEN - LCD Pin 7 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_7_BPEN(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_7_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_7_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_39_BPEN_MASK      (0x80U)
#define SGLCD_CONTROL_BPEN_PIN_39_BPEN_SHIFT     (7U)
/*! PIN_39_BPEN - LCD Pin 39 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_39_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_39_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_39_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_8_BPEN_MASK       (0x100U)
#define SGLCD_CONTROL_BPEN_PIN_8_BPEN_SHIFT      (8U)
/*! PIN_8_BPEN - LCD Pin 8 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_8_BPEN(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_8_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_8_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_40_BPEN_MASK      (0x100U)
#define SGLCD_CONTROL_BPEN_PIN_40_BPEN_SHIFT     (8U)
/*! PIN_40_BPEN - LCD Pin 40 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_40_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_40_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_40_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_9_BPEN_MASK       (0x200U)
#define SGLCD_CONTROL_BPEN_PIN_9_BPEN_SHIFT      (9U)
/*! PIN_9_BPEN - LCD Pin 9 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_9_BPEN(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_9_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_9_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_41_BPEN_MASK      (0x200U)
#define SGLCD_CONTROL_BPEN_PIN_41_BPEN_SHIFT     (9U)
/*! PIN_41_BPEN - LCD Pin 41 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_41_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_41_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_41_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_10_BPEN_MASK      (0x400U)
#define SGLCD_CONTROL_BPEN_PIN_10_BPEN_SHIFT     (10U)
/*! PIN_10_BPEN - LCD Pin 10 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_10_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_10_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_10_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_42_BPEN_MASK      (0x400U)
#define SGLCD_CONTROL_BPEN_PIN_42_BPEN_SHIFT     (10U)
/*! PIN_42_BPEN - LCD Pin 42 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_42_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_42_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_42_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_11_BPEN_MASK      (0x800U)
#define SGLCD_CONTROL_BPEN_PIN_11_BPEN_SHIFT     (11U)
/*! PIN_11_BPEN - LCD Pin 11 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_11_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_11_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_11_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_43_BPEN_MASK      (0x800U)
#define SGLCD_CONTROL_BPEN_PIN_43_BPEN_SHIFT     (11U)
/*! PIN_43_BPEN - LCD Pin 43 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_43_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_43_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_43_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_12_BPEN_MASK      (0x1000U)
#define SGLCD_CONTROL_BPEN_PIN_12_BPEN_SHIFT     (12U)
/*! PIN_12_BPEN - LCD Pin 12 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_12_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_12_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_12_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_44_BPEN_MASK      (0x1000U)
#define SGLCD_CONTROL_BPEN_PIN_44_BPEN_SHIFT     (12U)
/*! PIN_44_BPEN - LCD Pin 44 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_44_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_44_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_44_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_13_BPEN_MASK      (0x2000U)
#define SGLCD_CONTROL_BPEN_PIN_13_BPEN_SHIFT     (13U)
/*! PIN_13_BPEN - LCD Pin 13 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_13_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_13_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_13_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_45_BPEN_MASK      (0x2000U)
#define SGLCD_CONTROL_BPEN_PIN_45_BPEN_SHIFT     (13U)
/*! PIN_45_BPEN - LCD Pin 45 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_45_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_45_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_45_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_14_BPEN_MASK      (0x4000U)
#define SGLCD_CONTROL_BPEN_PIN_14_BPEN_SHIFT     (14U)
/*! PIN_14_BPEN - LCD Pin 14 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_14_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_14_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_14_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_46_BPEN_MASK      (0x4000U)
#define SGLCD_CONTROL_BPEN_PIN_46_BPEN_SHIFT     (14U)
/*! PIN_46_BPEN - LCD Pin 46 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_46_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_46_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_46_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_15_BPEN_MASK      (0x8000U)
#define SGLCD_CONTROL_BPEN_PIN_15_BPEN_SHIFT     (15U)
/*! PIN_15_BPEN - LCD Pin 15 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_15_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_15_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_15_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_47_BPEN_MASK      (0x8000U)
#define SGLCD_CONTROL_BPEN_PIN_47_BPEN_SHIFT     (15U)
/*! PIN_47_BPEN - LCD Pin 47 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_47_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_47_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_47_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_16_BPEN_MASK      (0x10000U)
#define SGLCD_CONTROL_BPEN_PIN_16_BPEN_SHIFT     (16U)
/*! PIN_16_BPEN - LCD Pin 16 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_16_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_16_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_16_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_48_BPEN_MASK      (0x10000U)
#define SGLCD_CONTROL_BPEN_PIN_48_BPEN_SHIFT     (16U)
/*! PIN_48_BPEN - LCD Pin 48 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_48_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_48_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_48_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_17_BPEN_MASK      (0x20000U)
#define SGLCD_CONTROL_BPEN_PIN_17_BPEN_SHIFT     (17U)
/*! PIN_17_BPEN - LCD Pin 17 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_17_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_17_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_17_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_49_BPEN_MASK      (0x20000U)
#define SGLCD_CONTROL_BPEN_PIN_49_BPEN_SHIFT     (17U)
/*! PIN_49_BPEN - LCD Pin 49 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_49_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_49_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_49_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_18_BPEN_MASK      (0x40000U)
#define SGLCD_CONTROL_BPEN_PIN_18_BPEN_SHIFT     (18U)
/*! PIN_18_BPEN - LCD Pin 18 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_18_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_18_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_18_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_50_BPEN_MASK      (0x40000U)
#define SGLCD_CONTROL_BPEN_PIN_50_BPEN_SHIFT     (18U)
/*! PIN_50_BPEN - LCD Pin 50 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_50_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_50_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_50_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_19_BPEN_MASK      (0x80000U)
#define SGLCD_CONTROL_BPEN_PIN_19_BPEN_SHIFT     (19U)
/*! PIN_19_BPEN - LCD Pin 19 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_19_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_19_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_19_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_51_BPEN_MASK      (0x80000U)
#define SGLCD_CONTROL_BPEN_PIN_51_BPEN_SHIFT     (19U)
/*! PIN_51_BPEN - LCD Pin 51 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_51_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_51_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_51_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_20_BPEN_MASK      (0x100000U)
#define SGLCD_CONTROL_BPEN_PIN_20_BPEN_SHIFT     (20U)
/*! PIN_20_BPEN - LCD Pin 20 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_20_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_20_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_20_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_52_BPEN_MASK      (0x100000U)
#define SGLCD_CONTROL_BPEN_PIN_52_BPEN_SHIFT     (20U)
/*! PIN_52_BPEN - LCD Pin 52 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_52_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_52_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_52_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_21_BPEN_MASK      (0x200000U)
#define SGLCD_CONTROL_BPEN_PIN_21_BPEN_SHIFT     (21U)
/*! PIN_21_BPEN - LCD Pin 21 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_21_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_21_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_21_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_53_BPEN_MASK      (0x200000U)
#define SGLCD_CONTROL_BPEN_PIN_53_BPEN_SHIFT     (21U)
/*! PIN_53_BPEN - LCD Pin 53 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_53_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_53_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_53_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_22_BPEN_MASK      (0x400000U)
#define SGLCD_CONTROL_BPEN_PIN_22_BPEN_SHIFT     (22U)
/*! PIN_22_BPEN - LCD Pin 22 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_22_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_22_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_22_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_54_BPEN_MASK      (0x400000U)
#define SGLCD_CONTROL_BPEN_PIN_54_BPEN_SHIFT     (22U)
/*! PIN_54_BPEN - LCD Pin 54 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_54_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_54_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_54_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_23_BPEN_MASK      (0x800000U)
#define SGLCD_CONTROL_BPEN_PIN_23_BPEN_SHIFT     (23U)
/*! PIN_23_BPEN - LCD Pin 23 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_23_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_23_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_23_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_55_BPEN_MASK      (0x800000U)
#define SGLCD_CONTROL_BPEN_PIN_55_BPEN_SHIFT     (23U)
/*! PIN_55_BPEN - LCD Pin 55 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_55_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_55_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_55_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_24_BPEN_MASK      (0x1000000U)
#define SGLCD_CONTROL_BPEN_PIN_24_BPEN_SHIFT     (24U)
/*! PIN_24_BPEN - LCD Pin 24 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_24_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_24_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_24_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_25_BPEN_MASK      (0x2000000U)
#define SGLCD_CONTROL_BPEN_PIN_25_BPEN_SHIFT     (25U)
/*! PIN_25_BPEN - LCD Pin 25 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_25_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_25_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_25_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_26_BPEN_MASK      (0x4000000U)
#define SGLCD_CONTROL_BPEN_PIN_26_BPEN_SHIFT     (26U)
/*! PIN_26_BPEN - LCD Pin 26 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_26_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_26_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_26_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_27_BPEN_MASK      (0x8000000U)
#define SGLCD_CONTROL_BPEN_PIN_27_BPEN_SHIFT     (27U)
/*! PIN_27_BPEN - LCD Pin 27 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_27_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_27_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_27_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_28_BPEN_MASK      (0x10000000U)
#define SGLCD_CONTROL_BPEN_PIN_28_BPEN_SHIFT     (28U)
/*! PIN_28_BPEN - LCD Pin 28 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_28_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_28_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_28_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_29_BPEN_MASK      (0x20000000U)
#define SGLCD_CONTROL_BPEN_PIN_29_BPEN_SHIFT     (29U)
/*! PIN_29_BPEN - LCD Pin 29 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_29_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_29_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_29_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_30_BPEN_MASK      (0x40000000U)
#define SGLCD_CONTROL_BPEN_PIN_30_BPEN_SHIFT     (30U)
/*! PIN_30_BPEN - LCD Pin 30 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_30_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_30_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_30_BPEN_MASK)

#define SGLCD_CONTROL_BPEN_PIN_31_BPEN_MASK      (0x80000000U)
#define SGLCD_CONTROL_BPEN_PIN_31_BPEN_SHIFT     (31U)
/*! PIN_31_BPEN - LCD Pin 31 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_CONTROL_BPEN_PIN_31_BPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_BPEN_PIN_31_BPEN_SHIFT)) & SGLCD_CONTROL_BPEN_PIN_31_BPEN_MASK)
/*! @} */

/*! @name WF8B - LCD Waveform 0 Register..LCD Waveform 55 Register */
/*! @{ */

#define SGLCD_CONTROL_WF8B_WF_MASK               (0xFFU)
#define SGLCD_CONTROL_WF8B_WF_SHIFT              (0U)
/*! WF - Pin Waveform */
#define SGLCD_CONTROL_WF8B_WF(x)                 (((uint8_t)(((uint8_t)(x)) << SGLCD_CONTROL_WF8B_WF_SHIFT)) & SGLCD_CONTROL_WF8B_WF_MASK)
/*! @} */

/* The count of SGLCD_CONTROL_WF8B */
#define SGLCD_CONTROL_WF8B_COUNT                 (56U)

/*! @name WF - LCD Waveform 3 to 0 Register..LCD Waveform 55 to 52 Register */
/*! @{ */

#define SGLCD_CONTROL_WF_WF0_MASK                (0xFFU)
#define SGLCD_CONTROL_WF_WF0_SHIFT               (0U)
/*! WF0 - Waveform Pin 0 */
#define SGLCD_CONTROL_WF_WF0(x)                  (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF0_SHIFT)) & SGLCD_CONTROL_WF_WF0_MASK)

#define SGLCD_CONTROL_WF_WF4_MASK                (0xFFU)
#define SGLCD_CONTROL_WF_WF4_SHIFT               (0U)
/*! WF4 - Waveform Pin 4 */
#define SGLCD_CONTROL_WF_WF4(x)                  (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF4_SHIFT)) & SGLCD_CONTROL_WF_WF4_MASK)

#define SGLCD_CONTROL_WF_WF8_MASK                (0xFFU)
#define SGLCD_CONTROL_WF_WF8_SHIFT               (0U)
/*! WF8 - Waveform Pin 8 */
#define SGLCD_CONTROL_WF_WF8(x)                  (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF8_SHIFT)) & SGLCD_CONTROL_WF_WF8_MASK)

#define SGLCD_CONTROL_WF_WF12_MASK               (0xFFU)
#define SGLCD_CONTROL_WF_WF12_SHIFT              (0U)
/*! WF12 - Waveform Pin 12 */
#define SGLCD_CONTROL_WF_WF12(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF12_SHIFT)) & SGLCD_CONTROL_WF_WF12_MASK)

#define SGLCD_CONTROL_WF_WF16_MASK               (0xFFU)
#define SGLCD_CONTROL_WF_WF16_SHIFT              (0U)
/*! WF16 - Waveform Pin 16 */
#define SGLCD_CONTROL_WF_WF16(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF16_SHIFT)) & SGLCD_CONTROL_WF_WF16_MASK)

#define SGLCD_CONTROL_WF_WF20_MASK               (0xFFU)
#define SGLCD_CONTROL_WF_WF20_SHIFT              (0U)
/*! WF20 - Waveform Pin 20 */
#define SGLCD_CONTROL_WF_WF20(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF20_SHIFT)) & SGLCD_CONTROL_WF_WF20_MASK)

#define SGLCD_CONTROL_WF_WF24_MASK               (0xFFU)
#define SGLCD_CONTROL_WF_WF24_SHIFT              (0U)
/*! WF24 - Waveform Pin 24 */
#define SGLCD_CONTROL_WF_WF24(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF24_SHIFT)) & SGLCD_CONTROL_WF_WF24_MASK)

#define SGLCD_CONTROL_WF_WF28_MASK               (0xFFU)
#define SGLCD_CONTROL_WF_WF28_SHIFT              (0U)
/*! WF28 - Waveform Pin 28 */
#define SGLCD_CONTROL_WF_WF28(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF28_SHIFT)) & SGLCD_CONTROL_WF_WF28_MASK)

#define SGLCD_CONTROL_WF_WF32_MASK               (0xFFU)
#define SGLCD_CONTROL_WF_WF32_SHIFT              (0U)
/*! WF32 - Waveform Pin 32 */
#define SGLCD_CONTROL_WF_WF32(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF32_SHIFT)) & SGLCD_CONTROL_WF_WF32_MASK)

#define SGLCD_CONTROL_WF_WF36_MASK               (0xFFU)
#define SGLCD_CONTROL_WF_WF36_SHIFT              (0U)
/*! WF36 - Waveform Pin 36 */
#define SGLCD_CONTROL_WF_WF36(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF36_SHIFT)) & SGLCD_CONTROL_WF_WF36_MASK)

#define SGLCD_CONTROL_WF_WF40_MASK               (0xFFU)
#define SGLCD_CONTROL_WF_WF40_SHIFT              (0U)
/*! WF40 - Waveform Pin 40 */
#define SGLCD_CONTROL_WF_WF40(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF40_SHIFT)) & SGLCD_CONTROL_WF_WF40_MASK)

#define SGLCD_CONTROL_WF_WF44_MASK               (0xFFU)
#define SGLCD_CONTROL_WF_WF44_SHIFT              (0U)
/*! WF44 - Waveform Pin 44 */
#define SGLCD_CONTROL_WF_WF44(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF44_SHIFT)) & SGLCD_CONTROL_WF_WF44_MASK)

#define SGLCD_CONTROL_WF_WF48_MASK               (0xFFU)
#define SGLCD_CONTROL_WF_WF48_SHIFT              (0U)
/*! WF48 - Waveform Pin 48 */
#define SGLCD_CONTROL_WF_WF48(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF48_SHIFT)) & SGLCD_CONTROL_WF_WF48_MASK)

#define SGLCD_CONTROL_WF_WF52_MASK               (0xFFU)
#define SGLCD_CONTROL_WF_WF52_SHIFT              (0U)
/*! WF52 - Waveform Pin 52 */
#define SGLCD_CONTROL_WF_WF52(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF52_SHIFT)) & SGLCD_CONTROL_WF_WF52_MASK)

#define SGLCD_CONTROL_WF_WF1_MASK                (0xFF00U)
#define SGLCD_CONTROL_WF_WF1_SHIFT               (8U)
/*! WF1 - Waveform Pin 1 */
#define SGLCD_CONTROL_WF_WF1(x)                  (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF1_SHIFT)) & SGLCD_CONTROL_WF_WF1_MASK)

#define SGLCD_CONTROL_WF_WF5_MASK                (0xFF00U)
#define SGLCD_CONTROL_WF_WF5_SHIFT               (8U)
/*! WF5 - Waveform Pin 5 */
#define SGLCD_CONTROL_WF_WF5(x)                  (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF5_SHIFT)) & SGLCD_CONTROL_WF_WF5_MASK)

#define SGLCD_CONTROL_WF_WF9_MASK                (0xFF00U)
#define SGLCD_CONTROL_WF_WF9_SHIFT               (8U)
/*! WF9 - Waveform Pin 9 */
#define SGLCD_CONTROL_WF_WF9(x)                  (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF9_SHIFT)) & SGLCD_CONTROL_WF_WF9_MASK)

#define SGLCD_CONTROL_WF_WF13_MASK               (0xFF00U)
#define SGLCD_CONTROL_WF_WF13_SHIFT              (8U)
/*! WF13 - Waveform Pin 13 */
#define SGLCD_CONTROL_WF_WF13(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF13_SHIFT)) & SGLCD_CONTROL_WF_WF13_MASK)

#define SGLCD_CONTROL_WF_WF17_MASK               (0xFF00U)
#define SGLCD_CONTROL_WF_WF17_SHIFT              (8U)
/*! WF17 - Waveform Pin 17 */
#define SGLCD_CONTROL_WF_WF17(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF17_SHIFT)) & SGLCD_CONTROL_WF_WF17_MASK)

#define SGLCD_CONTROL_WF_WF21_MASK               (0xFF00U)
#define SGLCD_CONTROL_WF_WF21_SHIFT              (8U)
/*! WF21 - Waveform Pin 21 */
#define SGLCD_CONTROL_WF_WF21(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF21_SHIFT)) & SGLCD_CONTROL_WF_WF21_MASK)

#define SGLCD_CONTROL_WF_WF25_MASK               (0xFF00U)
#define SGLCD_CONTROL_WF_WF25_SHIFT              (8U)
/*! WF25 - Waveform Pin 25 */
#define SGLCD_CONTROL_WF_WF25(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF25_SHIFT)) & SGLCD_CONTROL_WF_WF25_MASK)

#define SGLCD_CONTROL_WF_WF29_MASK               (0xFF00U)
#define SGLCD_CONTROL_WF_WF29_SHIFT              (8U)
/*! WF29 - Waveform Pin 29 */
#define SGLCD_CONTROL_WF_WF29(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF29_SHIFT)) & SGLCD_CONTROL_WF_WF29_MASK)

#define SGLCD_CONTROL_WF_WF33_MASK               (0xFF00U)
#define SGLCD_CONTROL_WF_WF33_SHIFT              (8U)
/*! WF33 - Waveform Pin 33 */
#define SGLCD_CONTROL_WF_WF33(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF33_SHIFT)) & SGLCD_CONTROL_WF_WF33_MASK)

#define SGLCD_CONTROL_WF_WF37_MASK               (0xFF00U)
#define SGLCD_CONTROL_WF_WF37_SHIFT              (8U)
/*! WF37 - Waveform Pin 37 */
#define SGLCD_CONTROL_WF_WF37(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF37_SHIFT)) & SGLCD_CONTROL_WF_WF37_MASK)

#define SGLCD_CONTROL_WF_WF41_MASK               (0xFF00U)
#define SGLCD_CONTROL_WF_WF41_SHIFT              (8U)
/*! WF41 - Waveform Pin 41 */
#define SGLCD_CONTROL_WF_WF41(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF41_SHIFT)) & SGLCD_CONTROL_WF_WF41_MASK)

#define SGLCD_CONTROL_WF_WF45_MASK               (0xFF00U)
#define SGLCD_CONTROL_WF_WF45_SHIFT              (8U)
/*! WF45 - Waveform Pin 45 */
#define SGLCD_CONTROL_WF_WF45(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF45_SHIFT)) & SGLCD_CONTROL_WF_WF45_MASK)

#define SGLCD_CONTROL_WF_WF49_MASK               (0xFF00U)
#define SGLCD_CONTROL_WF_WF49_SHIFT              (8U)
/*! WF49 - Waveform Pin 49 */
#define SGLCD_CONTROL_WF_WF49(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF49_SHIFT)) & SGLCD_CONTROL_WF_WF49_MASK)

#define SGLCD_CONTROL_WF_WF53_MASK               (0xFF00U)
#define SGLCD_CONTROL_WF_WF53_SHIFT              (8U)
/*! WF53 - Waveform Pin 53 */
#define SGLCD_CONTROL_WF_WF53(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF53_SHIFT)) & SGLCD_CONTROL_WF_WF53_MASK)

#define SGLCD_CONTROL_WF_WF2_MASK                (0xFF0000U)
#define SGLCD_CONTROL_WF_WF2_SHIFT               (16U)
/*! WF2 - Waveform Pin 2 */
#define SGLCD_CONTROL_WF_WF2(x)                  (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF2_SHIFT)) & SGLCD_CONTROL_WF_WF2_MASK)

#define SGLCD_CONTROL_WF_WF6_MASK                (0xFF0000U)
#define SGLCD_CONTROL_WF_WF6_SHIFT               (16U)
/*! WF6 - Waveform Pin 6 */
#define SGLCD_CONTROL_WF_WF6(x)                  (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF6_SHIFT)) & SGLCD_CONTROL_WF_WF6_MASK)

#define SGLCD_CONTROL_WF_WF10_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF10_SHIFT              (16U)
/*! WF10 - Waveform Pin 10 */
#define SGLCD_CONTROL_WF_WF10(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF10_SHIFT)) & SGLCD_CONTROL_WF_WF10_MASK)

#define SGLCD_CONTROL_WF_WF14_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF14_SHIFT              (16U)
/*! WF14 - Waveform Pin 14 */
#define SGLCD_CONTROL_WF_WF14(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF14_SHIFT)) & SGLCD_CONTROL_WF_WF14_MASK)

#define SGLCD_CONTROL_WF_WF18_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF18_SHIFT              (16U)
/*! WF18 - Waveform Pin 18 */
#define SGLCD_CONTROL_WF_WF18(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF18_SHIFT)) & SGLCD_CONTROL_WF_WF18_MASK)

#define SGLCD_CONTROL_WF_WF22_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF22_SHIFT              (16U)
/*! WF22 - Waveform Pin 22 */
#define SGLCD_CONTROL_WF_WF22(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF22_SHIFT)) & SGLCD_CONTROL_WF_WF22_MASK)

#define SGLCD_CONTROL_WF_WF26_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF26_SHIFT              (16U)
/*! WF26 - Waveform Pin 26 */
#define SGLCD_CONTROL_WF_WF26(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF26_SHIFT)) & SGLCD_CONTROL_WF_WF26_MASK)

#define SGLCD_CONTROL_WF_WF30_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF30_SHIFT              (16U)
/*! WF30 - Waveform Pin 30 */
#define SGLCD_CONTROL_WF_WF30(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF30_SHIFT)) & SGLCD_CONTROL_WF_WF30_MASK)

#define SGLCD_CONTROL_WF_WF34_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF34_SHIFT              (16U)
/*! WF34 - Waveform Pin 34 */
#define SGLCD_CONTROL_WF_WF34(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF34_SHIFT)) & SGLCD_CONTROL_WF_WF34_MASK)

#define SGLCD_CONTROL_WF_WF38_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF38_SHIFT              (16U)
/*! WF38 - Waveform Pin 38 */
#define SGLCD_CONTROL_WF_WF38(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF38_SHIFT)) & SGLCD_CONTROL_WF_WF38_MASK)

#define SGLCD_CONTROL_WF_WF42_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF42_SHIFT              (16U)
/*! WF42 - Waveform Pin 42 */
#define SGLCD_CONTROL_WF_WF42(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF42_SHIFT)) & SGLCD_CONTROL_WF_WF42_MASK)

#define SGLCD_CONTROL_WF_WF46_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF46_SHIFT              (16U)
/*! WF46 - Waveform Pin 46 */
#define SGLCD_CONTROL_WF_WF46(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF46_SHIFT)) & SGLCD_CONTROL_WF_WF46_MASK)

#define SGLCD_CONTROL_WF_WF50_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF50_SHIFT              (16U)
/*! WF50 - Waveform Pin 50 */
#define SGLCD_CONTROL_WF_WF50(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF50_SHIFT)) & SGLCD_CONTROL_WF_WF50_MASK)

#define SGLCD_CONTROL_WF_WF54_MASK               (0xFF0000U)
#define SGLCD_CONTROL_WF_WF54_SHIFT              (16U)
/*! WF54 - Waveform Pin 54 */
#define SGLCD_CONTROL_WF_WF54(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF54_SHIFT)) & SGLCD_CONTROL_WF_WF54_MASK)

#define SGLCD_CONTROL_WF_WF3_MASK                (0xFF000000U)
#define SGLCD_CONTROL_WF_WF3_SHIFT               (24U)
/*! WF3 - Waveform Pin 3 */
#define SGLCD_CONTROL_WF_WF3(x)                  (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF3_SHIFT)) & SGLCD_CONTROL_WF_WF3_MASK)

#define SGLCD_CONTROL_WF_WF7_MASK                (0xFF000000U)
#define SGLCD_CONTROL_WF_WF7_SHIFT               (24U)
/*! WF7 - Waveform Pin 7 */
#define SGLCD_CONTROL_WF_WF7(x)                  (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF7_SHIFT)) & SGLCD_CONTROL_WF_WF7_MASK)

#define SGLCD_CONTROL_WF_WF11_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF11_SHIFT              (24U)
/*! WF11 - Waveform Pin 11 */
#define SGLCD_CONTROL_WF_WF11(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF11_SHIFT)) & SGLCD_CONTROL_WF_WF11_MASK)

#define SGLCD_CONTROL_WF_WF15_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF15_SHIFT              (24U)
/*! WF15 - Waveform Pin 15 */
#define SGLCD_CONTROL_WF_WF15(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF15_SHIFT)) & SGLCD_CONTROL_WF_WF15_MASK)

#define SGLCD_CONTROL_WF_WF19_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF19_SHIFT              (24U)
/*! WF19 - Waveform Pin 19 */
#define SGLCD_CONTROL_WF_WF19(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF19_SHIFT)) & SGLCD_CONTROL_WF_WF19_MASK)

#define SGLCD_CONTROL_WF_WF23_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF23_SHIFT              (24U)
/*! WF23 - Waveform Pin 23 */
#define SGLCD_CONTROL_WF_WF23(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF23_SHIFT)) & SGLCD_CONTROL_WF_WF23_MASK)

#define SGLCD_CONTROL_WF_WF27_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF27_SHIFT              (24U)
/*! WF27 - Waveform Pin 27 */
#define SGLCD_CONTROL_WF_WF27(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF27_SHIFT)) & SGLCD_CONTROL_WF_WF27_MASK)

#define SGLCD_CONTROL_WF_WF31_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF31_SHIFT              (24U)
/*! WF31 - Waveform Pin 31 */
#define SGLCD_CONTROL_WF_WF31(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF31_SHIFT)) & SGLCD_CONTROL_WF_WF31_MASK)

#define SGLCD_CONTROL_WF_WF35_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF35_SHIFT              (24U)
/*! WF35 - Waveform Pin 35 */
#define SGLCD_CONTROL_WF_WF35(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF35_SHIFT)) & SGLCD_CONTROL_WF_WF35_MASK)

#define SGLCD_CONTROL_WF_WF39_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF39_SHIFT              (24U)
/*! WF39 - Waveform Pin 39 */
#define SGLCD_CONTROL_WF_WF39(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF39_SHIFT)) & SGLCD_CONTROL_WF_WF39_MASK)

#define SGLCD_CONTROL_WF_WF43_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF43_SHIFT              (24U)
/*! WF43 - Waveform Pin 43 */
#define SGLCD_CONTROL_WF_WF43(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF43_SHIFT)) & SGLCD_CONTROL_WF_WF43_MASK)

#define SGLCD_CONTROL_WF_WF47_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF47_SHIFT              (24U)
/*! WF47 - Waveform Pin 47 */
#define SGLCD_CONTROL_WF_WF47(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF47_SHIFT)) & SGLCD_CONTROL_WF_WF47_MASK)

#define SGLCD_CONTROL_WF_WF51_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF51_SHIFT              (24U)
/*! WF51 - Waveform Pin 51 */
#define SGLCD_CONTROL_WF_WF51(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF51_SHIFT)) & SGLCD_CONTROL_WF_WF51_MASK)

#define SGLCD_CONTROL_WF_WF55_MASK               (0xFF000000U)
#define SGLCD_CONTROL_WF_WF55_SHIFT              (24U)
/*! WF55 - Waveform Pin 55 */
#define SGLCD_CONTROL_WF_WF55(x)                 (((uint32_t)(((uint32_t)(x)) << SGLCD_CONTROL_WF_WF55_SHIFT)) & SGLCD_CONTROL_WF_WF55_MASK)
/*! @} */

/* The count of SGLCD_CONTROL_WF */
#define SGLCD_CONTROL_WF_COUNT                   (14U)


/*!
 * @}
 */ /* end of group SGLCD_CONTROL_Register_Masks */


/*!
 * @}
 */ /* end of group SGLCD_CONTROL_Peripheral_Access_Layer */


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


#endif  /* PERI_SGLCD_CONTROL_H_ */

