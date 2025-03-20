/*
** ###################################################################
**     Processors:          MCXA165VLH
**                          MCXA165VLL
**                          MCXA165VLQ
**                          MCXA165VPN
**                          MCXA166VLH
**                          MCXA166VLL
**                          MCXA166VLQ
**                          MCXA166VPN
**                          MCXA175VLH
**                          MCXA175VLL
**                          MCXA175VLQ
**                          MCXA175VPN
**                          MCXA176VLH
**                          MCXA176VLL
**                          MCXA176VLQ
**                          MCXA176VPN
**                          MCXA275VLH
**                          MCXA275VLL
**                          MCXA275VLQ
**                          MCXA275VPN
**                          MCXA276VLH
**                          MCXA276VLL
**                          MCXA276VLQ
**                          MCXA276VPN
**
**     Version:             rev. 1.0, 2024-03-26
**     Build:               b241120
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SLCD
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**
** ###################################################################
*/

/*!
 * @file SLCD.h
 * @version 1.0
 * @date 2024-03-26
 * @brief CMSIS Peripheral Access Layer for SLCD
 *
 * CMSIS Peripheral Access Layer for SLCD
 */

#if !defined(SLCD_H_)
#define SLCD_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA165VLH) || defined(CPU_MCXA165VLL) || defined(CPU_MCXA165VLQ) || defined(CPU_MCXA165VPN))
#include "MCXA165_COMMON.h"
#elif (defined(CPU_MCXA166VLH) || defined(CPU_MCXA166VLL) || defined(CPU_MCXA166VLQ) || defined(CPU_MCXA166VPN))
#include "MCXA166_COMMON.h"
#elif (defined(CPU_MCXA175VLH) || defined(CPU_MCXA175VLL) || defined(CPU_MCXA175VLQ) || defined(CPU_MCXA175VPN))
#include "MCXA175_COMMON.h"
#elif (defined(CPU_MCXA176VLH) || defined(CPU_MCXA176VLL) || defined(CPU_MCXA176VLQ) || defined(CPU_MCXA176VPN))
#include "MCXA176_COMMON.h"
#elif (defined(CPU_MCXA275VLH) || defined(CPU_MCXA275VLL) || defined(CPU_MCXA275VLQ) || defined(CPU_MCXA275VPN))
#include "MCXA275_COMMON.h"
#elif (defined(CPU_MCXA276VLH) || defined(CPU_MCXA276VLL) || defined(CPU_MCXA276VLQ) || defined(CPU_MCXA276VPN))
#include "MCXA276_COMMON.h"
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
   -- SLCD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SLCD_Peripheral_Access_Layer SLCD Peripheral Access Layer
 * @{
 */

/** SLCD - Size of Registers Arrays */
#define SLCD_LCDWFN_COUNT                         12u

/** SLCD - Register Layout Typedef */
typedef struct {
  __IO uint32_t LCD_GCR;                           /**< LCD General Control Register, offset: 0x0 */
  __IO uint32_t LCD_AR;                            /**< LCD Auxiliary Register, offset: 0x4 */
  __IO uint32_t LCD_FDCR;                          /**< LCD Fault Detect Control Register, offset: 0x8 */
  __IO uint32_t LCD_FDSR;                          /**< LCD Fault Detect Status Register, offset: 0xC */
  __IO uint32_t LCD_PEN0;                          /**< LCD Pin Enable Register 0, offset: 0x10 */
  __IO uint32_t LCD_PEN1;                          /**< LCD Pin Enable Register 1, offset: 0x14 */
  __IO uint32_t LCD_BPEN0;                         /**< LCD Back Plane Enable Register 0, offset: 0x18 */
  __IO uint32_t LCD_BPEN1;                         /**< LCD Back Plane Enable Register 1, offset: 0x1C */
  __IO uint32_t LCD_WFTO[SLCD_LCDWFN_COUNT];       /**< LCD Waveform 3 to 0 Register..LCD Waveform 47 to 44 Register, array offset: 0x20, array step: 0x4 */
} SLCD_Type;

/* ----------------------------------------------------------------------------
   -- SLCD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SLCD_Register_Masks SLCD Register Masks
 * @{
 */

/*! @name LCD_GCR - LCD General Control Register */
/*! @{ */

#define SLCD_LCD_GCR_DUTY_MASK                   (0x3U)
#define SLCD_LCD_GCR_DUTY_SHIFT                  (0U)
/*! DUTY - LCD duty select
 *  0b00..Use 1 BP (1/1 duty cycle).
 *  0b01..Use 2 BP (1/2 duty cycle).
 *  0b10..Use 3 BP (1/3 duty cycle).
 *  0b11..Use 4 BP (1/4 duty cycle).(Default)
 */
#define SLCD_LCD_GCR_DUTY(x)                     (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_DUTY_SHIFT)) & SLCD_LCD_GCR_DUTY_MASK)

#define SLCD_LCD_GCR_LCLK_MASK                   (0x38U)
#define SLCD_LCD_GCR_LCLK_SHIFT                  (3U)
/*! LCLK - LCD Clock Prescaler */
#define SLCD_LCD_GCR_LCLK(x)                     (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_LCLK_SHIFT)) & SLCD_LCD_GCR_LCLK_MASK)

#define SLCD_LCD_GCR_LCDLP_MASK                  (0x40U)
#define SLCD_LCD_GCR_LCDLP_SHIFT                 (6U)
/*! LCDLP - LCD Low Power Waveform
 *  0b0..LCD driver drives standard waveforms.
 *  0b1..LCD driver drives low-power waveforms.
 */
#define SLCD_LCD_GCR_LCDLP(x)                    (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_LCDLP_SHIFT)) & SLCD_LCD_GCR_LCDLP_MASK)

#define SLCD_LCD_GCR_LCDEN_MASK                  (0x80U)
#define SLCD_LCD_GCR_LCDEN_SHIFT                 (7U)
/*! LCDEN - LCD Driver Enable */
#define SLCD_LCD_GCR_LCDEN(x)                    (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_LCDEN_SHIFT)) & SLCD_LCD_GCR_LCDEN_MASK)

#define SLCD_LCD_GCR_LCDSTP_MASK                 (0x100U)
#define SLCD_LCD_GCR_LCDSTP_SHIFT                (8U)
/*! LCDSTP - LCD Stop
 *  0b0..Allows the LCD driver to continue running during Stop mode.
 *  0b1..Disables the LCD driver when MCU enters Stop mode.
 */
#define SLCD_LCD_GCR_LCDSTP(x)                   (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_LCDSTP_SHIFT)) & SLCD_LCD_GCR_LCDSTP_MASK)

#define SLCD_LCD_GCR_LCDDOZE_MASK                (0x200U)
#define SLCD_LCD_GCR_LCDDOZE_SHIFT               (9U)
/*! LCDDOZE - LCD Doze enable
 *  0b0..Allows the LCD driver to continue running during Doze mode.
 *  0b1..Disables the LCD driver when MCU enters Doze mode.
 */
#define SLCD_LCD_GCR_LCDDOZE(x)                  (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_LCDDOZE_SHIFT)) & SLCD_LCD_GCR_LCDDOZE_MASK)

#define SLCD_LCD_GCR_FDCIEN_MASK                 (0x4000U)
#define SLCD_LCD_GCR_FDCIEN_SHIFT                (14U)
/*! FDCIEN - LCD Fault Detection Complete Interrupt Enable
 *  0b0..No interrupt request is generated by this event.
 *  0b1..When a fault is detected and FDCF bit is set, this event causes an interrupt request.
 */
#define SLCD_LCD_GCR_FDCIEN(x)                   (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_FDCIEN_SHIFT)) & SLCD_LCD_GCR_FDCIEN_MASK)

#define SLCD_LCD_GCR_LCDIEN_MASK                 (0x8000U)
#define SLCD_LCD_GCR_LCDIEN_SHIFT                (15U)
/*! LCDIEN - LCD Frame Frequency Interrupt Enable
 *  0b0..No interrupt request is generated by this event.
 *  0b1..When LCDIF bit is set, this event causes an interrupt request.
 */
#define SLCD_LCD_GCR_LCDIEN(x)                   (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_LCDIEN_SHIFT)) & SLCD_LCD_GCR_LCDIEN_MASK)

#define SLCD_LCD_GCR_SHCYCLE_MASK                (0x10000U)
#define SLCD_LCD_GCR_SHCYCLE_SHIFT               (16U)
/*! SHCYCLE - Sample & Hold Cycle Select
 *  0b0..Sample & hold phase clock period is 64 LCD clock (16kHz) period / 32 LCD clock (8kHz) period.
 *  0b1..Sample & hold phase clock period is 128 LCD clk (16kHz) period / 64 LCD clock (8kHz) period.
 */
#define SLCD_LCD_GCR_SHCYCLE(x)                  (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_SHCYCLE_SHIFT)) & SLCD_LCD_GCR_SHCYCLE_MASK)

#define SLCD_LCD_GCR_SHEN_MASK                   (0x800000U)
#define SLCD_LCD_GCR_SHEN_SHIFT                  (23U)
/*! SHEN - Sample & Hold Mode Enable
 *  0b0..Sample & hold is disabled.
 *  0b1..Sample & hold is enabled.
 */
#define SLCD_LCD_GCR_SHEN(x)                     (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_SHEN_SHIFT)) & SLCD_LCD_GCR_SHEN_MASK)

#define SLCD_LCD_GCR_VLL1TRIM_MASK               (0xF000000U)
#define SLCD_LCD_GCR_VLL1TRIM_SHIFT              (24U)
/*! VLL1TRIM - Level 1 Voltage Trim */
#define SLCD_LCD_GCR_VLL1TRIM(x)                 (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_VLL1TRIM_SHIFT)) & SLCD_LCD_GCR_VLL1TRIM_MASK)

#define SLCD_LCD_GCR_VLL2TRIM_MASK               (0xF0000000U)
#define SLCD_LCD_GCR_VLL2TRIM_SHIFT              (28U)
/*! VLL2TRIM - Level 2 Voltage Trim */
#define SLCD_LCD_GCR_VLL2TRIM(x)                 (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_GCR_VLL2TRIM_SHIFT)) & SLCD_LCD_GCR_VLL2TRIM_MASK)
/*! @} */

/*! @name LCD_AR - LCD Auxiliary Register */
/*! @{ */

#define SLCD_LCD_AR_BRATE_MASK                   (0x7U)
#define SLCD_LCD_AR_BRATE_SHIFT                  (0U)
/*! BRATE - Blink-rate configuration */
#define SLCD_LCD_AR_BRATE(x)                     (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_AR_BRATE_SHIFT)) & SLCD_LCD_AR_BRATE_MASK)

#define SLCD_LCD_AR_BMODE_MASK                   (0x8U)
#define SLCD_LCD_AR_BMODE_SHIFT                  (3U)
/*! BMODE - Blink mode
 *  0b0..Display blank during the blink period.
 *  0b1..Display alternate display during blink period.
 */
#define SLCD_LCD_AR_BMODE(x)                     (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_AR_BMODE_SHIFT)) & SLCD_LCD_AR_BMODE_MASK)

#define SLCD_LCD_AR_BLANK_MASK                   (0x20U)
#define SLCD_LCD_AR_BLANK_SHIFT                  (5U)
/*! BLANK - Blank display mode
 *  0b0..Normal or alternate display mode.
 *  0b1..Blank display mode.
 */
#define SLCD_LCD_AR_BLANK(x)                     (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_AR_BLANK_SHIFT)) & SLCD_LCD_AR_BLANK_MASK)

#define SLCD_LCD_AR_ALT_MASK                     (0x40U)
#define SLCD_LCD_AR_ALT_SHIFT                    (6U)
/*! ALT - Alternate display mode
 *  0b0..Normal display mode.
 *  0b1..Alternate display mode.
 */
#define SLCD_LCD_AR_ALT(x)                       (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_AR_ALT_SHIFT)) & SLCD_LCD_AR_ALT_MASK)

#define SLCD_LCD_AR_BLINK_MASK                   (0x80U)
#define SLCD_LCD_AR_BLINK_SHIFT                  (7U)
/*! BLINK - Blink command
 *  0b0..Disables blinking.
 *  0b1..Starts blinking at blinking frequency specified by LCD blink rate calculation.
 */
#define SLCD_LCD_AR_BLINK(x)                     (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_AR_BLINK_SHIFT)) & SLCD_LCD_AR_BLINK_MASK)

#define SLCD_LCD_AR_LCDIF_MASK                   (0x8000U)
#define SLCD_LCD_AR_LCDIF_SHIFT                  (15U)
/*! LCDIF - LCD Frame Frequency Interrupt flag
 *  0b0..Frame frequency interrupt condition has not occurred.
 *  0b1..Start of SLCD frame has occurred.
 */
#define SLCD_LCD_AR_LCDIF(x)                     (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_AR_LCDIF_SHIFT)) & SLCD_LCD_AR_LCDIF_MASK)
/*! @} */

/*! @name LCD_FDCR - LCD Fault Detect Control Register */
/*! @{ */

#define SLCD_LCD_FDCR_FDPINID_MASK               (0x3FU)
#define SLCD_LCD_FDCR_FDPINID_SHIFT              (0U)
/*! FDPINID - Fault Detect Pin ID */
#define SLCD_LCD_FDCR_FDPINID(x)                 (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_FDCR_FDPINID_SHIFT)) & SLCD_LCD_FDCR_FDPINID_MASK)

#define SLCD_LCD_FDCR_FDBPEN_MASK                (0x40U)
#define SLCD_LCD_FDCR_FDBPEN_SHIFT               (6U)
/*! FDBPEN - Fault Detect Back Plane Enable
 *  0b0..Type of the selected pin under fault detect test is front plane.
 *  0b1..Type of the selected pin under fault detect test is back plane.
 */
#define SLCD_LCD_FDCR_FDBPEN(x)                  (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_FDCR_FDBPEN_SHIFT)) & SLCD_LCD_FDCR_FDBPEN_MASK)

#define SLCD_LCD_FDCR_FDEN_MASK                  (0x80U)
#define SLCD_LCD_FDCR_FDEN_SHIFT                 (7U)
/*! FDEN - Fault Detect Enable
 *  0b0..Disable fault detection.
 *  0b1..Enable fault detection.
 */
#define SLCD_LCD_FDCR_FDEN(x)                    (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_FDCR_FDEN_SHIFT)) & SLCD_LCD_FDCR_FDEN_MASK)

#define SLCD_LCD_FDCR_FDSWW_MASK                 (0xE00U)
#define SLCD_LCD_FDCR_FDSWW_SHIFT                (9U)
/*! FDSWW - Fault Detect Sample Window Width
 *  0b000..Sample window width is 4 sample clock cycles.
 *  0b001..Sample window width is 8 sample clock cycles.
 *  0b010..Sample window width is 16 sample clock cycles.
 *  0b011..Sample window width is 32 sample clock cycles.
 *  0b100..Sample window width is 64 sample clock cycles.
 *  0b101..Sample window width is 128 sample clock cycles.
 *  0b110..Sample window width is 256 sample clock cycles.
 *  0b111..Sample window width is 512 sample clock cycles.
 */
#define SLCD_LCD_FDCR_FDSWW(x)                   (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_FDCR_FDSWW_SHIFT)) & SLCD_LCD_FDCR_FDSWW_MASK)

#define SLCD_LCD_FDCR_FDPRS_MASK                 (0x7000U)
#define SLCD_LCD_FDCR_FDPRS_SHIFT                (12U)
/*! FDPRS - Fault Detect Clock Prescaler
 *  0b000..1/1 bus clock.
 *  0b001..1/2 bus clock.
 *  0b010..1/4 bus clock.
 *  0b011..1/8 bus clock.
 *  0b100..1/16 bus clock.
 *  0b101..1/32 bus clock.
 *  0b110..1/64 bus clock.
 *  0b111..1/128 bus clock.
 */
#define SLCD_LCD_FDCR_FDPRS(x)                   (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_FDCR_FDPRS_SHIFT)) & SLCD_LCD_FDCR_FDPRS_MASK)
/*! @} */

/*! @name LCD_FDSR - LCD Fault Detect Status Register */
/*! @{ */

#define SLCD_LCD_FDSR_FDCNT_MASK                 (0xFFU)
#define SLCD_LCD_FDSR_FDCNT_SHIFT                (0U)
/*! FDCNT - Fault Detect Counter */
#define SLCD_LCD_FDSR_FDCNT(x)                   (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_FDSR_FDCNT_SHIFT)) & SLCD_LCD_FDSR_FDCNT_MASK)

#define SLCD_LCD_FDSR_FDCF_MASK                  (0x8000U)
#define SLCD_LCD_FDSR_FDCF_SHIFT                 (15U)
/*! FDCF - Fault Detection Complete Flag
 *  0b0..Fault detection is not completed.
 *  0b1..Fault detection is completed.
 */
#define SLCD_LCD_FDSR_FDCF(x)                    (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_FDSR_FDCF_SHIFT)) & SLCD_LCD_FDSR_FDCF_MASK)
/*! @} */

/*! @name LCD_PEN0 - LCD Pin Enable Register 0 */
/*! @{ */

#define SLCD_LCD_PEN0_PIN_0_EN_MASK              (0x1U)
#define SLCD_LCD_PEN0_PIN_0_EN_SHIFT             (0U)
/*! PIN_0_EN - LCD Pin 0 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_0_EN(x)                (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_0_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_0_EN_MASK)

#define SLCD_LCD_PEN0_PIN_1_EN_MASK              (0x2U)
#define SLCD_LCD_PEN0_PIN_1_EN_SHIFT             (1U)
/*! PIN_1_EN - LCD Pin 1 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_1_EN(x)                (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_1_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_1_EN_MASK)

#define SLCD_LCD_PEN0_PIN_2_EN_MASK              (0x4U)
#define SLCD_LCD_PEN0_PIN_2_EN_SHIFT             (2U)
/*! PIN_2_EN - LCD Pin 2 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_2_EN(x)                (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_2_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_2_EN_MASK)

#define SLCD_LCD_PEN0_PIN_3_EN_MASK              (0x8U)
#define SLCD_LCD_PEN0_PIN_3_EN_SHIFT             (3U)
/*! PIN_3_EN - LCD Pin 3 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_3_EN(x)                (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_3_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_3_EN_MASK)

#define SLCD_LCD_PEN0_PIN_4_EN_MASK              (0x10U)
#define SLCD_LCD_PEN0_PIN_4_EN_SHIFT             (4U)
/*! PIN_4_EN - LCD Pin 4 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_4_EN(x)                (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_4_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_4_EN_MASK)

#define SLCD_LCD_PEN0_PIN_5_EN_MASK              (0x20U)
#define SLCD_LCD_PEN0_PIN_5_EN_SHIFT             (5U)
/*! PIN_5_EN - LCD Pin 5 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_5_EN(x)                (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_5_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_5_EN_MASK)

#define SLCD_LCD_PEN0_PIN_6_EN_MASK              (0x40U)
#define SLCD_LCD_PEN0_PIN_6_EN_SHIFT             (6U)
/*! PIN_6_EN - LCD Pin 6 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_6_EN(x)                (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_6_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_6_EN_MASK)

#define SLCD_LCD_PEN0_PIN_7_EN_MASK              (0x80U)
#define SLCD_LCD_PEN0_PIN_7_EN_SHIFT             (7U)
/*! PIN_7_EN - LCD Pin 7 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_7_EN(x)                (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_7_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_7_EN_MASK)

#define SLCD_LCD_PEN0_PIN_8_EN_MASK              (0x100U)
#define SLCD_LCD_PEN0_PIN_8_EN_SHIFT             (8U)
/*! PIN_8_EN - LCD Pin 8 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_8_EN(x)                (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_8_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_8_EN_MASK)

#define SLCD_LCD_PEN0_PIN_9_EN_MASK              (0x200U)
#define SLCD_LCD_PEN0_PIN_9_EN_SHIFT             (9U)
/*! PIN_9_EN - LCD Pin 9 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_9_EN(x)                (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_9_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_9_EN_MASK)

#define SLCD_LCD_PEN0_PIN_10_EN_MASK             (0x400U)
#define SLCD_LCD_PEN0_PIN_10_EN_SHIFT            (10U)
/*! PIN_10_EN - LCD Pin 10 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_10_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_10_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_10_EN_MASK)

#define SLCD_LCD_PEN0_PIN_11_EN_MASK             (0x800U)
#define SLCD_LCD_PEN0_PIN_11_EN_SHIFT            (11U)
/*! PIN_11_EN - LCD Pin 11 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_11_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_11_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_11_EN_MASK)

#define SLCD_LCD_PEN0_PIN_12_EN_MASK             (0x1000U)
#define SLCD_LCD_PEN0_PIN_12_EN_SHIFT            (12U)
/*! PIN_12_EN - LCD Pin 12 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_12_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_12_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_12_EN_MASK)

#define SLCD_LCD_PEN0_PIN_13_EN_MASK             (0x2000U)
#define SLCD_LCD_PEN0_PIN_13_EN_SHIFT            (13U)
/*! PIN_13_EN - LCD Pin 13 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_13_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_13_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_13_EN_MASK)

#define SLCD_LCD_PEN0_PIN_14_EN_MASK             (0x4000U)
#define SLCD_LCD_PEN0_PIN_14_EN_SHIFT            (14U)
/*! PIN_14_EN - LCD Pin 14 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_14_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_14_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_14_EN_MASK)

#define SLCD_LCD_PEN0_PIN_15_EN_MASK             (0x8000U)
#define SLCD_LCD_PEN0_PIN_15_EN_SHIFT            (15U)
/*! PIN_15_EN - LCD Pin 15 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_15_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_15_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_15_EN_MASK)

#define SLCD_LCD_PEN0_PIN_16_EN_MASK             (0x10000U)
#define SLCD_LCD_PEN0_PIN_16_EN_SHIFT            (16U)
/*! PIN_16_EN - LCD Pin 16 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_16_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_16_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_16_EN_MASK)

#define SLCD_LCD_PEN0_PIN_17_EN_MASK             (0x20000U)
#define SLCD_LCD_PEN0_PIN_17_EN_SHIFT            (17U)
/*! PIN_17_EN - LCD Pin 17 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_17_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_17_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_17_EN_MASK)

#define SLCD_LCD_PEN0_PIN_18_EN_MASK             (0x40000U)
#define SLCD_LCD_PEN0_PIN_18_EN_SHIFT            (18U)
/*! PIN_18_EN - LCD Pin 18 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_18_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_18_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_18_EN_MASK)

#define SLCD_LCD_PEN0_PIN_19_EN_MASK             (0x80000U)
#define SLCD_LCD_PEN0_PIN_19_EN_SHIFT            (19U)
/*! PIN_19_EN - LCD Pin 19 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_19_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_19_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_19_EN_MASK)

#define SLCD_LCD_PEN0_PIN_20_EN_MASK             (0x100000U)
#define SLCD_LCD_PEN0_PIN_20_EN_SHIFT            (20U)
/*! PIN_20_EN - LCD Pin 20 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_20_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_20_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_20_EN_MASK)

#define SLCD_LCD_PEN0_PIN_21_EN_MASK             (0x200000U)
#define SLCD_LCD_PEN0_PIN_21_EN_SHIFT            (21U)
/*! PIN_21_EN - LCD Pin 21 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_21_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_21_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_21_EN_MASK)

#define SLCD_LCD_PEN0_PIN_22_EN_MASK             (0x400000U)
#define SLCD_LCD_PEN0_PIN_22_EN_SHIFT            (22U)
/*! PIN_22_EN - LCD Pin 22 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_22_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_22_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_22_EN_MASK)

#define SLCD_LCD_PEN0_PIN_23_EN_MASK             (0x800000U)
#define SLCD_LCD_PEN0_PIN_23_EN_SHIFT            (23U)
/*! PIN_23_EN - LCD Pin 23 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_23_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_23_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_23_EN_MASK)

#define SLCD_LCD_PEN0_PIN_24_EN_MASK             (0x1000000U)
#define SLCD_LCD_PEN0_PIN_24_EN_SHIFT            (24U)
/*! PIN_24_EN - LCD Pin 24 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_24_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_24_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_24_EN_MASK)

#define SLCD_LCD_PEN0_PIN_25_EN_MASK             (0x2000000U)
#define SLCD_LCD_PEN0_PIN_25_EN_SHIFT            (25U)
/*! PIN_25_EN - LCD Pin 25 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_25_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_25_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_25_EN_MASK)

#define SLCD_LCD_PEN0_PIN_26_EN_MASK             (0x4000000U)
#define SLCD_LCD_PEN0_PIN_26_EN_SHIFT            (26U)
/*! PIN_26_EN - LCD Pin 26 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_26_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_26_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_26_EN_MASK)

#define SLCD_LCD_PEN0_PIN_27_EN_MASK             (0x8000000U)
#define SLCD_LCD_PEN0_PIN_27_EN_SHIFT            (27U)
/*! PIN_27_EN - LCD Pin 27 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_27_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_27_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_27_EN_MASK)

#define SLCD_LCD_PEN0_PIN_28_EN_MASK             (0x10000000U)
#define SLCD_LCD_PEN0_PIN_28_EN_SHIFT            (28U)
/*! PIN_28_EN - LCD Pin 28 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_28_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_28_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_28_EN_MASK)

#define SLCD_LCD_PEN0_PIN_29_EN_MASK             (0x20000000U)
#define SLCD_LCD_PEN0_PIN_29_EN_SHIFT            (29U)
/*! PIN_29_EN - LCD Pin 29 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_29_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_29_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_29_EN_MASK)

#define SLCD_LCD_PEN0_PIN_30_EN_MASK             (0x40000000U)
#define SLCD_LCD_PEN0_PIN_30_EN_SHIFT            (30U)
/*! PIN_30_EN - LCD Pin 30 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_30_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_30_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_30_EN_MASK)

#define SLCD_LCD_PEN0_PIN_31_EN_MASK             (0x80000000U)
#define SLCD_LCD_PEN0_PIN_31_EN_SHIFT            (31U)
/*! PIN_31_EN - LCD Pin 31 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN0_PIN_31_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN0_PIN_31_EN_SHIFT)) & SLCD_LCD_PEN0_PIN_31_EN_MASK)
/*! @} */

/*! @name LCD_PEN1 - LCD Pin Enable Register 1 */
/*! @{ */

#define SLCD_LCD_PEN1_PIN_32_EN_MASK             (0x1U)
#define SLCD_LCD_PEN1_PIN_32_EN_SHIFT            (0U)
/*! PIN_32_EN - LCD Pin 32 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_32_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_32_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_32_EN_MASK)

#define SLCD_LCD_PEN1_PIN_33_EN_MASK             (0x2U)
#define SLCD_LCD_PEN1_PIN_33_EN_SHIFT            (1U)
/*! PIN_33_EN - LCD Pin 33 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_33_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_33_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_33_EN_MASK)

#define SLCD_LCD_PEN1_PIN_34_EN_MASK             (0x4U)
#define SLCD_LCD_PEN1_PIN_34_EN_SHIFT            (2U)
/*! PIN_34_EN - LCD Pin 34 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_34_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_34_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_34_EN_MASK)

#define SLCD_LCD_PEN1_PIN_35_EN_MASK             (0x8U)
#define SLCD_LCD_PEN1_PIN_35_EN_SHIFT            (3U)
/*! PIN_35_EN - LCD Pin 35 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_35_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_35_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_35_EN_MASK)

#define SLCD_LCD_PEN1_PIN_36_EN_MASK             (0x10U)
#define SLCD_LCD_PEN1_PIN_36_EN_SHIFT            (4U)
/*! PIN_36_EN - LCD Pin 36 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_36_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_36_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_36_EN_MASK)

#define SLCD_LCD_PEN1_PIN_37_EN_MASK             (0x20U)
#define SLCD_LCD_PEN1_PIN_37_EN_SHIFT            (5U)
/*! PIN_37_EN - LCD Pin 37 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_37_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_37_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_37_EN_MASK)

#define SLCD_LCD_PEN1_PIN_38_EN_MASK             (0x40U)
#define SLCD_LCD_PEN1_PIN_38_EN_SHIFT            (6U)
/*! PIN_38_EN - LCD Pin 38 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_38_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_38_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_38_EN_MASK)

#define SLCD_LCD_PEN1_PIN_39_EN_MASK             (0x80U)
#define SLCD_LCD_PEN1_PIN_39_EN_SHIFT            (7U)
/*! PIN_39_EN - LCD Pin 39 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_39_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_39_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_39_EN_MASK)

#define SLCD_LCD_PEN1_PIN_40_EN_MASK             (0x100U)
#define SLCD_LCD_PEN1_PIN_40_EN_SHIFT            (8U)
/*! PIN_40_EN - LCD Pin 40 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_40_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_40_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_40_EN_MASK)

#define SLCD_LCD_PEN1_PIN_41_EN_MASK             (0x200U)
#define SLCD_LCD_PEN1_PIN_41_EN_SHIFT            (9U)
/*! PIN_41_EN - LCD Pin 41 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_41_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_41_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_41_EN_MASK)

#define SLCD_LCD_PEN1_PIN_42_EN_MASK             (0x400U)
#define SLCD_LCD_PEN1_PIN_42_EN_SHIFT            (10U)
/*! PIN_42_EN - LCD Pin 42 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_42_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_42_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_42_EN_MASK)

#define SLCD_LCD_PEN1_PIN_43_EN_MASK             (0x800U)
#define SLCD_LCD_PEN1_PIN_43_EN_SHIFT            (11U)
/*! PIN_43_EN - LCD Pin 43 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_43_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_43_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_43_EN_MASK)

#define SLCD_LCD_PEN1_PIN_44_EN_MASK             (0x1000U)
#define SLCD_LCD_PEN1_PIN_44_EN_SHIFT            (12U)
/*! PIN_44_EN - LCD Pin 44 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_44_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_44_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_44_EN_MASK)

#define SLCD_LCD_PEN1_PIN_45_EN_MASK             (0x2000U)
#define SLCD_LCD_PEN1_PIN_45_EN_SHIFT            (13U)
/*! PIN_45_EN - LCD Pin 45 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_45_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_45_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_45_EN_MASK)

#define SLCD_LCD_PEN1_PIN_46_EN_MASK             (0x4000U)
#define SLCD_LCD_PEN1_PIN_46_EN_SHIFT            (14U)
/*! PIN_46_EN - LCD Pin 46 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_46_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_46_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_46_EN_MASK)

#define SLCD_LCD_PEN1_PIN_47_EN_MASK             (0x8000U)
#define SLCD_LCD_PEN1_PIN_47_EN_SHIFT            (15U)
/*! PIN_47_EN - LCD Pin 47 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SLCD_LCD_PEN1_PIN_47_EN(x)               (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_PEN1_PIN_47_EN_SHIFT)) & SLCD_LCD_PEN1_PIN_47_EN_MASK)
/*! @} */

/*! @name LCD_BPEN0 - LCD Back Plane Enable Register 0 */
/*! @{ */

#define SLCD_LCD_BPEN0_PIN_0_BPEN_MASK           (0x1U)
#define SLCD_LCD_BPEN0_PIN_0_BPEN_SHIFT          (0U)
/*! PIN_0_BPEN - LCD Pin 0 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_0_BPEN(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_0_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_0_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_1_BPEN_MASK           (0x2U)
#define SLCD_LCD_BPEN0_PIN_1_BPEN_SHIFT          (1U)
/*! PIN_1_BPEN - LCD Pin 1 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_1_BPEN(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_1_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_1_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_2_BPEN_MASK           (0x4U)
#define SLCD_LCD_BPEN0_PIN_2_BPEN_SHIFT          (2U)
/*! PIN_2_BPEN - LCD Pin 2 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_2_BPEN(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_2_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_2_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_3_BPEN_MASK           (0x8U)
#define SLCD_LCD_BPEN0_PIN_3_BPEN_SHIFT          (3U)
/*! PIN_3_BPEN - LCD Pin 3 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_3_BPEN(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_3_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_3_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_4_BPEN_MASK           (0x10U)
#define SLCD_LCD_BPEN0_PIN_4_BPEN_SHIFT          (4U)
/*! PIN_4_BPEN - LCD Pin 4 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_4_BPEN(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_4_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_4_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_5_BPEN_MASK           (0x20U)
#define SLCD_LCD_BPEN0_PIN_5_BPEN_SHIFT          (5U)
/*! PIN_5_BPEN - LCD Pin 5 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_5_BPEN(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_5_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_5_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_6_BPEN_MASK           (0x40U)
#define SLCD_LCD_BPEN0_PIN_6_BPEN_SHIFT          (6U)
/*! PIN_6_BPEN - LCD Pin 6 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_6_BPEN(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_6_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_6_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_7_BPEN_MASK           (0x80U)
#define SLCD_LCD_BPEN0_PIN_7_BPEN_SHIFT          (7U)
/*! PIN_7_BPEN - LCD Pin 7 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_7_BPEN(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_7_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_7_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_8_BPEN_MASK           (0x100U)
#define SLCD_LCD_BPEN0_PIN_8_BPEN_SHIFT          (8U)
/*! PIN_8_BPEN - LCD Pin 8 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_8_BPEN(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_8_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_8_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_9_BPEN_MASK           (0x200U)
#define SLCD_LCD_BPEN0_PIN_9_BPEN_SHIFT          (9U)
/*! PIN_9_BPEN - LCD Pin 9 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_9_BPEN(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_9_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_9_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_10_BPEN_MASK          (0x400U)
#define SLCD_LCD_BPEN0_PIN_10_BPEN_SHIFT         (10U)
/*! PIN_10_BPEN - LCD Pin 10 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_10_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_10_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_10_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_11_BPEN_MASK          (0x800U)
#define SLCD_LCD_BPEN0_PIN_11_BPEN_SHIFT         (11U)
/*! PIN_11_BPEN - LCD Pin 11 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_11_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_11_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_11_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_12_BPEN_MASK          (0x1000U)
#define SLCD_LCD_BPEN0_PIN_12_BPEN_SHIFT         (12U)
/*! PIN_12_BPEN - LCD Pin 12 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_12_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_12_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_12_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_13_BPEN_MASK          (0x2000U)
#define SLCD_LCD_BPEN0_PIN_13_BPEN_SHIFT         (13U)
/*! PIN_13_BPEN - LCD Pin 13 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_13_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_13_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_13_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_14_BPEN_MASK          (0x4000U)
#define SLCD_LCD_BPEN0_PIN_14_BPEN_SHIFT         (14U)
/*! PIN_14_BPEN - LCD Pin 14 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_14_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_14_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_14_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_15_BPEN_MASK          (0x8000U)
#define SLCD_LCD_BPEN0_PIN_15_BPEN_SHIFT         (15U)
/*! PIN_15_BPEN - LCD Pin 15 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_15_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_15_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_15_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_16_BPEN_MASK          (0x10000U)
#define SLCD_LCD_BPEN0_PIN_16_BPEN_SHIFT         (16U)
/*! PIN_16_BPEN - LCD Pin 16 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_16_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_16_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_16_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_17_BPEN_MASK          (0x20000U)
#define SLCD_LCD_BPEN0_PIN_17_BPEN_SHIFT         (17U)
/*! PIN_17_BPEN - LCD Pin 17 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_17_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_17_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_17_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_18_BPEN_MASK          (0x40000U)
#define SLCD_LCD_BPEN0_PIN_18_BPEN_SHIFT         (18U)
/*! PIN_18_BPEN - LCD Pin 18 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_18_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_18_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_18_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_19_BPEN_MASK          (0x80000U)
#define SLCD_LCD_BPEN0_PIN_19_BPEN_SHIFT         (19U)
/*! PIN_19_BPEN - LCD Pin 19 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_19_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_19_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_19_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_20_BPEN_MASK          (0x100000U)
#define SLCD_LCD_BPEN0_PIN_20_BPEN_SHIFT         (20U)
/*! PIN_20_BPEN - LCD Pin 20 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_20_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_20_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_20_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_21_BPEN_MASK          (0x200000U)
#define SLCD_LCD_BPEN0_PIN_21_BPEN_SHIFT         (21U)
/*! PIN_21_BPEN - LCD Pin 21 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_21_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_21_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_21_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_22_BPEN_MASK          (0x400000U)
#define SLCD_LCD_BPEN0_PIN_22_BPEN_SHIFT         (22U)
/*! PIN_22_BPEN - LCD Pin 22 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_22_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_22_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_22_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_23_BPEN_MASK          (0x800000U)
#define SLCD_LCD_BPEN0_PIN_23_BPEN_SHIFT         (23U)
/*! PIN_23_BPEN - LCD Pin 23 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_23_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_23_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_23_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_24_BPEN_MASK          (0x1000000U)
#define SLCD_LCD_BPEN0_PIN_24_BPEN_SHIFT         (24U)
/*! PIN_24_BPEN - LCD Pin 24 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_24_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_24_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_24_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_25_BPEN_MASK          (0x2000000U)
#define SLCD_LCD_BPEN0_PIN_25_BPEN_SHIFT         (25U)
/*! PIN_25_BPEN - LCD Pin 25 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_25_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_25_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_25_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_26_BPEN_MASK          (0x4000000U)
#define SLCD_LCD_BPEN0_PIN_26_BPEN_SHIFT         (26U)
/*! PIN_26_BPEN - LCD Pin 26 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_26_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_26_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_26_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_27_BPEN_MASK          (0x8000000U)
#define SLCD_LCD_BPEN0_PIN_27_BPEN_SHIFT         (27U)
/*! PIN_27_BPEN - LCD Pin 27 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_27_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_27_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_27_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_28_BPEN_MASK          (0x10000000U)
#define SLCD_LCD_BPEN0_PIN_28_BPEN_SHIFT         (28U)
/*! PIN_28_BPEN - LCD Pin 28 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_28_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_28_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_28_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_29_BPEN_MASK          (0x20000000U)
#define SLCD_LCD_BPEN0_PIN_29_BPEN_SHIFT         (29U)
/*! PIN_29_BPEN - LCD Pin 29 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_29_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_29_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_29_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_30_BPEN_MASK          (0x40000000U)
#define SLCD_LCD_BPEN0_PIN_30_BPEN_SHIFT         (30U)
/*! PIN_30_BPEN - LCD Pin 30 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_30_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_30_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_30_BPEN_MASK)

#define SLCD_LCD_BPEN0_PIN_31_BPEN_MASK          (0x80000000U)
#define SLCD_LCD_BPEN0_PIN_31_BPEN_SHIFT         (31U)
/*! PIN_31_BPEN - LCD Pin 31 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN0_PIN_31_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN0_PIN_31_BPEN_SHIFT)) & SLCD_LCD_BPEN0_PIN_31_BPEN_MASK)
/*! @} */

/*! @name LCD_BPEN1 - LCD Back Plane Enable Register 1 */
/*! @{ */

#define SLCD_LCD_BPEN1_PIN_32_BPEN_MASK          (0x1U)
#define SLCD_LCD_BPEN1_PIN_32_BPEN_SHIFT         (0U)
/*! PIN_32_BPEN - LCD Pin 32 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_32_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_32_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_32_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_33_BPEN_MASK          (0x2U)
#define SLCD_LCD_BPEN1_PIN_33_BPEN_SHIFT         (1U)
/*! PIN_33_BPEN - LCD Pin 33 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_33_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_33_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_33_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_34_BPEN_MASK          (0x4U)
#define SLCD_LCD_BPEN1_PIN_34_BPEN_SHIFT         (2U)
/*! PIN_34_BPEN - LCD Pin 34 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_34_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_34_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_34_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_35_BPEN_MASK          (0x8U)
#define SLCD_LCD_BPEN1_PIN_35_BPEN_SHIFT         (3U)
/*! PIN_35_BPEN - LCD Pin 35 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_35_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_35_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_35_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_36_BPEN_MASK          (0x10U)
#define SLCD_LCD_BPEN1_PIN_36_BPEN_SHIFT         (4U)
/*! PIN_36_BPEN - LCD Pin 36 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_36_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_36_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_36_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_37_BPEN_MASK          (0x20U)
#define SLCD_LCD_BPEN1_PIN_37_BPEN_SHIFT         (5U)
/*! PIN_37_BPEN - LCD Pin 37 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_37_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_37_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_37_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_38_BPEN_MASK          (0x40U)
#define SLCD_LCD_BPEN1_PIN_38_BPEN_SHIFT         (6U)
/*! PIN_38_BPEN - LCD Pin 38 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_38_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_38_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_38_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_39_BPEN_MASK          (0x80U)
#define SLCD_LCD_BPEN1_PIN_39_BPEN_SHIFT         (7U)
/*! PIN_39_BPEN - LCD Pin 39 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_39_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_39_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_39_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_40_BPEN_MASK          (0x100U)
#define SLCD_LCD_BPEN1_PIN_40_BPEN_SHIFT         (8U)
/*! PIN_40_BPEN - LCD Pin 40 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_40_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_40_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_40_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_41_BPEN_MASK          (0x200U)
#define SLCD_LCD_BPEN1_PIN_41_BPEN_SHIFT         (9U)
/*! PIN_41_BPEN - LCD Pin 41 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_41_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_41_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_41_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_42_BPEN_MASK          (0x400U)
#define SLCD_LCD_BPEN1_PIN_42_BPEN_SHIFT         (10U)
/*! PIN_42_BPEN - LCD Pin 42 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_42_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_42_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_42_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_43_BPEN_MASK          (0x800U)
#define SLCD_LCD_BPEN1_PIN_43_BPEN_SHIFT         (11U)
/*! PIN_43_BPEN - LCD Pin 43 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_43_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_43_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_43_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_44_BPEN_MASK          (0x1000U)
#define SLCD_LCD_BPEN1_PIN_44_BPEN_SHIFT         (12U)
/*! PIN_44_BPEN - LCD Pin 44 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_44_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_44_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_44_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_45_BPEN_MASK          (0x2000U)
#define SLCD_LCD_BPEN1_PIN_45_BPEN_SHIFT         (13U)
/*! PIN_45_BPEN - LCD Pin 45 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_45_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_45_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_45_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_46_BPEN_MASK          (0x4000U)
#define SLCD_LCD_BPEN1_PIN_46_BPEN_SHIFT         (14U)
/*! PIN_46_BPEN - LCD Pin 46 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_46_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_46_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_46_BPEN_MASK)

#define SLCD_LCD_BPEN1_PIN_47_BPEN_MASK          (0x8000U)
#define SLCD_LCD_BPEN1_PIN_47_BPEN_SHIFT         (15U)
/*! PIN_47_BPEN - LCD Pin 47 Back Plane Enable
 *  0b0..Pin as front plane.
 *  0b1..Pin as back plane.
 */
#define SLCD_LCD_BPEN1_PIN_47_BPEN(x)            (((uint32_t)(((uint32_t)(x)) << SLCD_LCD_BPEN1_PIN_47_BPEN_SHIFT)) & SLCD_LCD_BPEN1_PIN_47_BPEN_MASK)
/*! @} */

/*! @name LCDWFN_LCD_WFTO - LCD Waveform 3 to 0 Register..LCD Waveform 47 to 44 Register */
/*! @{ */

#define SLCD_LCDWFN_LCD_WFTO_WF0_MASK            (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF0_SHIFT           (0U)
/*! WF0 - Waveform Pin 0 */
#define SLCD_LCDWFN_LCD_WFTO_WF0(x)              (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF0_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF0_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF4_MASK            (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF4_SHIFT           (0U)
/*! WF4 - Waveform Pin 4 */
#define SLCD_LCDWFN_LCD_WFTO_WF4(x)              (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF4_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF4_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF8_MASK            (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF8_SHIFT           (0U)
/*! WF8 - Waveform Pin 8 */
#define SLCD_LCDWFN_LCD_WFTO_WF8(x)              (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF8_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF8_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF12_MASK           (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF12_SHIFT          (0U)
/*! WF12 - Waveform Pin 12 */
#define SLCD_LCDWFN_LCD_WFTO_WF12(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF12_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF12_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF16_MASK           (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF16_SHIFT          (0U)
/*! WF16 - Waveform Pin 16 */
#define SLCD_LCDWFN_LCD_WFTO_WF16(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF16_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF16_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF20_MASK           (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF20_SHIFT          (0U)
/*! WF20 - Waveform Pin 20 */
#define SLCD_LCDWFN_LCD_WFTO_WF20(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF20_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF20_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF24_MASK           (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF24_SHIFT          (0U)
/*! WF24 - Waveform Pin 24 */
#define SLCD_LCDWFN_LCD_WFTO_WF24(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF24_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF24_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF28_MASK           (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF28_SHIFT          (0U)
/*! WF28 - Waveform Pin 28 */
#define SLCD_LCDWFN_LCD_WFTO_WF28(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF28_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF28_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF32_MASK           (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF32_SHIFT          (0U)
/*! WF32 - Waveform Pin 32 */
#define SLCD_LCDWFN_LCD_WFTO_WF32(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF32_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF32_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF36_MASK           (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF36_SHIFT          (0U)
/*! WF36 - Waveform Pin 36 */
#define SLCD_LCDWFN_LCD_WFTO_WF36(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF36_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF36_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF40_MASK           (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF40_SHIFT          (0U)
/*! WF40 - Waveform Pin 40 */
#define SLCD_LCDWFN_LCD_WFTO_WF40(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF40_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF40_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF44_MASK           (0xFFU)
#define SLCD_LCDWFN_LCD_WFTO_WF44_SHIFT          (0U)
/*! WF44 - Waveform Pin 44 */
#define SLCD_LCDWFN_LCD_WFTO_WF44(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF44_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF44_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF1_MASK            (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF1_SHIFT           (8U)
/*! WF1 - Waveform Pin 1 */
#define SLCD_LCDWFN_LCD_WFTO_WF1(x)              (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF1_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF1_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF5_MASK            (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF5_SHIFT           (8U)
/*! WF5 - Waveform Pin 5 */
#define SLCD_LCDWFN_LCD_WFTO_WF5(x)              (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF5_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF5_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF9_MASK            (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF9_SHIFT           (8U)
/*! WF9 - Waveform Pin 9 */
#define SLCD_LCDWFN_LCD_WFTO_WF9(x)              (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF9_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF9_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF13_MASK           (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF13_SHIFT          (8U)
/*! WF13 - Waveform Pin 13 */
#define SLCD_LCDWFN_LCD_WFTO_WF13(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF13_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF13_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF17_MASK           (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF17_SHIFT          (8U)
/*! WF17 - Waveform Pin 17 */
#define SLCD_LCDWFN_LCD_WFTO_WF17(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF17_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF17_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF21_MASK           (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF21_SHIFT          (8U)
/*! WF21 - Waveform Pin 21 */
#define SLCD_LCDWFN_LCD_WFTO_WF21(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF21_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF21_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF25_MASK           (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF25_SHIFT          (8U)
/*! WF25 - Waveform Pin 25 */
#define SLCD_LCDWFN_LCD_WFTO_WF25(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF25_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF25_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF29_MASK           (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF29_SHIFT          (8U)
/*! WF29 - Waveform Pin 29 */
#define SLCD_LCDWFN_LCD_WFTO_WF29(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF29_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF29_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF33_MASK           (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF33_SHIFT          (8U)
/*! WF33 - Waveform Pin 33 */
#define SLCD_LCDWFN_LCD_WFTO_WF33(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF33_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF33_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF37_MASK           (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF37_SHIFT          (8U)
/*! WF37 - Waveform Pin 37 */
#define SLCD_LCDWFN_LCD_WFTO_WF37(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF37_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF37_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF41_MASK           (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF41_SHIFT          (8U)
/*! WF41 - Waveform Pin 41 */
#define SLCD_LCDWFN_LCD_WFTO_WF41(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF41_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF41_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF45_MASK           (0xFF00U)
#define SLCD_LCDWFN_LCD_WFTO_WF45_SHIFT          (8U)
/*! WF45 - Waveform Pin 45 */
#define SLCD_LCDWFN_LCD_WFTO_WF45(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF45_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF45_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF2_MASK            (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF2_SHIFT           (16U)
/*! WF2 - Waveform Pin 2 */
#define SLCD_LCDWFN_LCD_WFTO_WF2(x)              (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF2_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF2_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF6_MASK            (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF6_SHIFT           (16U)
/*! WF6 - Waveform Pin 6 */
#define SLCD_LCDWFN_LCD_WFTO_WF6(x)              (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF6_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF6_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF10_MASK           (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF10_SHIFT          (16U)
/*! WF10 - Waveform Pin 10 */
#define SLCD_LCDWFN_LCD_WFTO_WF10(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF10_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF10_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF14_MASK           (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF14_SHIFT          (16U)
/*! WF14 - Waveform Pin 14 */
#define SLCD_LCDWFN_LCD_WFTO_WF14(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF14_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF14_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF18_MASK           (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF18_SHIFT          (16U)
/*! WF18 - Waveform Pin 18 */
#define SLCD_LCDWFN_LCD_WFTO_WF18(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF18_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF18_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF22_MASK           (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF22_SHIFT          (16U)
/*! WF22 - Waveform Pin 22 */
#define SLCD_LCDWFN_LCD_WFTO_WF22(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF22_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF22_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF26_MASK           (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF26_SHIFT          (16U)
/*! WF26 - Waveform Pin 26 */
#define SLCD_LCDWFN_LCD_WFTO_WF26(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF26_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF26_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF30_MASK           (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF30_SHIFT          (16U)
/*! WF30 - Waveform Pin 30 */
#define SLCD_LCDWFN_LCD_WFTO_WF30(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF30_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF30_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF34_MASK           (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF34_SHIFT          (16U)
/*! WF34 - Waveform Pin 34 */
#define SLCD_LCDWFN_LCD_WFTO_WF34(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF34_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF34_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF38_MASK           (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF38_SHIFT          (16U)
/*! WF38 - Waveform Pin 38 */
#define SLCD_LCDWFN_LCD_WFTO_WF38(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF38_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF38_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF42_MASK           (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF42_SHIFT          (16U)
/*! WF42 - Waveform Pin 42 */
#define SLCD_LCDWFN_LCD_WFTO_WF42(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF42_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF42_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF46_MASK           (0xFF0000U)
#define SLCD_LCDWFN_LCD_WFTO_WF46_SHIFT          (16U)
/*! WF46 - Waveform Pin 46 */
#define SLCD_LCDWFN_LCD_WFTO_WF46(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF46_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF46_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF3_MASK            (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF3_SHIFT           (24U)
/*! WF3 - Waveform Pin 3 */
#define SLCD_LCDWFN_LCD_WFTO_WF3(x)              (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF3_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF3_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF7_MASK            (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF7_SHIFT           (24U)
/*! WF7 - Waveform Pin 7 */
#define SLCD_LCDWFN_LCD_WFTO_WF7(x)              (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF7_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF7_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF11_MASK           (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF11_SHIFT          (24U)
/*! WF11 - Waveform Pin 11 */
#define SLCD_LCDWFN_LCD_WFTO_WF11(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF11_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF11_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF15_MASK           (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF15_SHIFT          (24U)
/*! WF15 - Waveform Pin 15 */
#define SLCD_LCDWFN_LCD_WFTO_WF15(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF15_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF15_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF19_MASK           (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF19_SHIFT          (24U)
/*! WF19 - Waveform Pin 19 */
#define SLCD_LCDWFN_LCD_WFTO_WF19(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF19_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF19_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF23_MASK           (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF23_SHIFT          (24U)
/*! WF23 - Waveform Pin 23 */
#define SLCD_LCDWFN_LCD_WFTO_WF23(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF23_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF23_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF27_MASK           (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF27_SHIFT          (24U)
/*! WF27 - Waveform Pin 27 */
#define SLCD_LCDWFN_LCD_WFTO_WF27(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF27_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF27_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF31_MASK           (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF31_SHIFT          (24U)
/*! WF31 - Waveform Pin 31 */
#define SLCD_LCDWFN_LCD_WFTO_WF31(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF31_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF31_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF35_MASK           (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF35_SHIFT          (24U)
/*! WF35 - Waveform Pin 35 */
#define SLCD_LCDWFN_LCD_WFTO_WF35(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF35_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF35_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF39_MASK           (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF39_SHIFT          (24U)
/*! WF39 - Waveform Pin 39 */
#define SLCD_LCDWFN_LCD_WFTO_WF39(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF39_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF39_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF43_MASK           (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF43_SHIFT          (24U)
/*! WF43 - Waveform Pin 43 */
#define SLCD_LCDWFN_LCD_WFTO_WF43(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF43_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF43_MASK)

#define SLCD_LCDWFN_LCD_WFTO_WF47_MASK           (0xFF000000U)
#define SLCD_LCDWFN_LCD_WFTO_WF47_SHIFT          (24U)
/*! WF47 - Waveform Pin 47 */
#define SLCD_LCDWFN_LCD_WFTO_WF47(x)             (((uint32_t)(((uint32_t)(x)) << SLCD_LCDWFN_LCD_WFTO_WF47_SHIFT)) & SLCD_LCDWFN_LCD_WFTO_WF47_MASK)
/*! @} */

/* The count of SLCD_LCDWFN_LCD_WFTO */
#define SLCD_LCDWFN_LCD_WFTO_COUNT               (12U)


/*!
 * @}
 */ /* end of group SLCD_Register_Masks */


/*!
 * @}
 */ /* end of group SLCD_Peripheral_Access_Layer */


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


#endif  /* SLCD_H_ */

