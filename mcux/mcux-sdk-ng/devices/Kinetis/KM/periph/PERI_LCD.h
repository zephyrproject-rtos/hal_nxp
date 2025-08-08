/*
** ###################################################################
**     Processors:          MKM14Z128ACHH5
**                          MKM14Z64ACHH5
**                          MKM33Z128ACLH5
**                          MKM33Z128ACLL5
**                          MKM33Z64ACLH5
**                          MKM33Z64ACLL5
**                          MKM34Z128ACLL5
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LCD
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2014-07-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LCD.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LCD
 *
 * CMSIS Peripheral Access Layer for LCD
 */

#if !defined(PERI_LCD_H_)
#define PERI_LCD_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKM14Z128ACHH5) || defined(CPU_MKM14Z64ACHH5))
#include "MKM14ZA5_COMMON.h"
#elif (defined(CPU_MKM33Z128ACLH5) || defined(CPU_MKM33Z128ACLL5) || defined(CPU_MKM33Z64ACLH5) || defined(CPU_MKM33Z64ACLL5))
#include "MKM33ZA5_COMMON.h"
#elif (defined(CPU_MKM34Z128ACLL5))
#include "MKM34ZA5_COMMON.h"
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
   -- LCD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCD_Peripheral_Access_Layer LCD Peripheral Access Layer
 * @{
 */

/** LCD - Size of Registers Arrays */
#define LCD_PEN_COUNT                             2u
#define LCD_BPEN_COUNT                            2u
#define LCD_WFOVERLAY_WFACCESS8BIT_WF8B_COUNT     64u
#define LCD_WFOVERLAY_WFACCESS32BIT_WF_COUNT      16u

/** LCD - Register Layout Typedef */
typedef struct {
  __IO uint32_t GCR;                               /**< LCD General Control Register, offset: 0x0 */
  __IO uint32_t AR;                                /**< LCD Auxiliary Register, offset: 0x4 */
  __IO uint32_t FDCR;                              /**< LCD Fault Detect Control Register, offset: 0x8 */
  __IO uint32_t FDSR;                              /**< LCD Fault Detect Status Register, offset: 0xC */
  __IO uint32_t PEN[LCD_PEN_COUNT];                /**< LCD Pin Enable register, array offset: 0x10, array step: 0x4 */
  __IO uint32_t BPEN[LCD_BPEN_COUNT];              /**< LCD Back Plane Enable register, array offset: 0x18, array step: 0x4 */
  union {                                          /* offset: 0x20 */
    __IO uint8_t WF8B[LCD_WFOVERLAY_WFACCESS8BIT_WF8B_COUNT];   /**< LCD Waveform Register 0...LCD Waveform Register 63., array offset: 0x20, array step: 0x1 */
    __IO uint32_t WF[LCD_WFOVERLAY_WFACCESS32BIT_WF_COUNT];   /**< LCD Waveform register, array offset: 0x20, array step: 0x4 */
  };
} LCD_Type;

/* ----------------------------------------------------------------------------
   -- LCD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCD_Register_Masks LCD Register Masks
 * @{
 */

/*! @name GCR - LCD General Control Register */
/*! @{ */

#define LCD_GCR_DUTY_MASK                        (0x7U)
#define LCD_GCR_DUTY_SHIFT                       (0U)
/*! DUTY - LCD duty select
 *  0b000..Use 1 BP (1/1 duty cycle).
 *  0b001..Use 2 BP (1/2 duty cycle).
 *  0b010..Use 3 BP (1/3 duty cycle).
 *  0b011..Use 4 BP (1/4 duty cycle). (Default)
 *  0b100..Use 5 BP (1/5 duty cycle).
 *  0b101..Use 6 BP (1/6 duty cycle).
 *  0b110..Use 7 BP (1/7 duty cycle).
 *  0b111..Use 8 BP (1/8 duty cycle).
 */
#define LCD_GCR_DUTY(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_GCR_DUTY_SHIFT)) & LCD_GCR_DUTY_MASK)

#define LCD_GCR_LCLK_MASK                        (0x38U)
#define LCD_GCR_LCLK_SHIFT                       (3U)
/*! LCLK - LCD Clock Prescaler */
#define LCD_GCR_LCLK(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_GCR_LCLK_SHIFT)) & LCD_GCR_LCLK_MASK)

#define LCD_GCR_SOURCE_MASK                      (0x40U)
#define LCD_GCR_SOURCE_SHIFT                     (6U)
/*! SOURCE - LCD Clock Source Select
 *  0b0..Selects the default clock as the LCD clock source.
 *  0b1..Selects the alternate clock as the LCD clock source.
 */
#define LCD_GCR_SOURCE(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_GCR_SOURCE_SHIFT)) & LCD_GCR_SOURCE_MASK)

#define LCD_GCR_LCDEN_MASK                       (0x80U)
#define LCD_GCR_LCDEN_SHIFT                      (7U)
/*! LCDEN - LCD Driver Enable
 *  0b0..All front plane and back plane pins are disabled. The LCD controller system is also disabled, and all LCD
 *       waveform generation clocks are stopped. V LL3 is connected to V DD internally.
 *  0b1..LCD controller driver system is enabled, and front plane and back plane waveforms are generated. All LCD
 *       pins, LCD_Pn, enabled using the LCD Pin Enable register, output an LCD driver waveform. The back plane
 *       pins output an LCD driver back plane waveform based on the settings of DUTY[2:0]. Charge pump or resistor
 *       bias is enabled.
 */
#define LCD_GCR_LCDEN(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_GCR_LCDEN_SHIFT)) & LCD_GCR_LCDEN_MASK)

#define LCD_GCR_LCDSTP_MASK                      (0x100U)
#define LCD_GCR_LCDSTP_SHIFT                     (8U)
/*! LCDSTP - LCD Stop
 *  0b0..Allows the LCD driver, charge pump, resistor bias network, and voltage regulator to continue running during Stop mode.
 *  0b1..Disables the LCD driver, charge pump, resistor bias network, and voltage regulator when MCU enters Stop mode.
 */
#define LCD_GCR_LCDSTP(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_GCR_LCDSTP_SHIFT)) & LCD_GCR_LCDSTP_MASK)

#define LCD_GCR_LCDDOZE_MASK                     (0x200U)
#define LCD_GCR_LCDDOZE_SHIFT                    (9U)
/*! LCDDOZE - LCD Doze enable
 *  0b0..Allows the LCD driver, charge pump, resistor bias network, and voltage regulator to continue running during Doze mode.
 *  0b1..Disables the LCD driver, charge pump, resistor bias network, and voltage regulator when MCU enters Doze mode.
 */
#define LCD_GCR_LCDDOZE(x)                       (((uint32_t)(((uint32_t)(x)) << LCD_GCR_LCDDOZE_SHIFT)) & LCD_GCR_LCDDOZE_MASK)

#define LCD_GCR_ALTDIV_MASK                      (0x3000U)
#define LCD_GCR_ALTDIV_SHIFT                     (12U)
/*! ALTDIV - LCD Alternate Clock Divider
 *  0b00..Divide factor = 1 (No divide)
 *  0b01..Divide factor = 64
 *  0b10..Divide factor = 256
 *  0b11..Divide factor = 512
 */
#define LCD_GCR_ALTDIV(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_GCR_ALTDIV_SHIFT)) & LCD_GCR_ALTDIV_MASK)

#define LCD_GCR_FDCIEN_MASK                      (0x4000U)
#define LCD_GCR_FDCIEN_SHIFT                     (14U)
/*! FDCIEN - LCD Fault Detection Complete Interrupt Enable
 *  0b0..No interrupt request is generated by this event.
 *  0b1..When a fault is detected and FDCF bit is set, this event causes an interrupt request.
 */
#define LCD_GCR_FDCIEN(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_GCR_FDCIEN_SHIFT)) & LCD_GCR_FDCIEN_MASK)

#define LCD_GCR_LCDIEN_MASK                      (0x8000U)
#define LCD_GCR_LCDIEN_SHIFT                     (15U)
/*! LCDIEN - LCD Frame Frequency Interrupt Enable
 *  0b0..No interrupt request is generated by this event.
 *  0b1..When LCDIF bit is set, this event causes an interrupt request.
 */
#define LCD_GCR_LCDIEN(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_GCR_LCDIEN_SHIFT)) & LCD_GCR_LCDIEN_MASK)

#define LCD_GCR_VSUPPLY_MASK                     (0x20000U)
#define LCD_GCR_VSUPPLY_SHIFT                    (17U)
/*! VSUPPLY - Voltage Supply Control
 *  0b0..Drive VLL3 internally from VDD
 *  0b1..Drive VLL3 externally from VDD or drive VLL1 internally from vIREG
 */
#define LCD_GCR_VSUPPLY(x)                       (((uint32_t)(((uint32_t)(x)) << LCD_GCR_VSUPPLY_SHIFT)) & LCD_GCR_VSUPPLY_MASK)

#define LCD_GCR_LADJ_MASK                        (0x300000U)
#define LCD_GCR_LADJ_SHIFT                       (20U)
/*! LADJ - Load Adjust */
#define LCD_GCR_LADJ(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_GCR_LADJ_SHIFT)) & LCD_GCR_LADJ_MASK)

#define LCD_GCR_CPSEL_MASK                       (0x800000U)
#define LCD_GCR_CPSEL_SHIFT                      (23U)
/*! CPSEL - Charge Pump or Resistor Bias Select
 *  0b0..LCD charge pump is disabled. Resistor network selected. (The internal 1/3-bias is forced.)
 *  0b1..LCD charge pump is selected. Resistor network disabled. (The internal 1/3-bias is forced.)
 */
#define LCD_GCR_CPSEL(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_GCR_CPSEL_SHIFT)) & LCD_GCR_CPSEL_MASK)

#define LCD_GCR_RVTRIM_MASK                      (0xF000000U)
#define LCD_GCR_RVTRIM_SHIFT                     (24U)
/*! RVTRIM - Regulated Voltage Trim */
#define LCD_GCR_RVTRIM(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_GCR_RVTRIM_SHIFT)) & LCD_GCR_RVTRIM_MASK)

#define LCD_GCR_RVEN_MASK                        (0x80000000U)
#define LCD_GCR_RVEN_SHIFT                       (31U)
/*! RVEN - Regulated Voltage Enable
 *  0b0..Regulated voltage disabled.
 *  0b1..Regulated voltage enabled.
 */
#define LCD_GCR_RVEN(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_GCR_RVEN_SHIFT)) & LCD_GCR_RVEN_MASK)
/*! @} */

/*! @name AR - LCD Auxiliary Register */
/*! @{ */

#define LCD_AR_BRATE_MASK                        (0x7U)
#define LCD_AR_BRATE_SHIFT                       (0U)
/*! BRATE - Blink-rate configuration */
#define LCD_AR_BRATE(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_AR_BRATE_SHIFT)) & LCD_AR_BRATE_MASK)

#define LCD_AR_BMODE_MASK                        (0x8U)
#define LCD_AR_BMODE_SHIFT                       (3U)
/*! BMODE - Blink mode
 *  0b0..Display blank during the blink period.
 *  0b1..Display alternate display during blink period (Ignored if duty is 5 or greater).
 */
#define LCD_AR_BMODE(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_AR_BMODE_SHIFT)) & LCD_AR_BMODE_MASK)

#define LCD_AR_BLANK_MASK                        (0x20U)
#define LCD_AR_BLANK_SHIFT                       (5U)
/*! BLANK - Blank display mode
 *  0b0..Normal or alternate display mode.
 *  0b1..Blank display mode.
 */
#define LCD_AR_BLANK(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_AR_BLANK_SHIFT)) & LCD_AR_BLANK_MASK)

#define LCD_AR_ALT_MASK                          (0x40U)
#define LCD_AR_ALT_SHIFT                         (6U)
/*! ALT - Alternate display mode
 *  0b0..Normal display mode.
 *  0b1..Alternate display mode.
 */
#define LCD_AR_ALT(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_AR_ALT_SHIFT)) & LCD_AR_ALT_MASK)

#define LCD_AR_BLINK_MASK                        (0x80U)
#define LCD_AR_BLINK_SHIFT                       (7U)
/*! BLINK - Blink command
 *  0b0..Disables blinking.
 *  0b1..Starts blinking at blinking frequency specified by LCD blink rate calculation.
 */
#define LCD_AR_BLINK(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_AR_BLINK_SHIFT)) & LCD_AR_BLINK_MASK)

#define LCD_AR_LCDIF_MASK                        (0x8000U)
#define LCD_AR_LCDIF_SHIFT                       (15U)
/*! LCDIF - LCD Frame Frequency Interrupt flag
 *  0b0..Frame frequency interrupt condition has not occurred.
 *  0b1..Start of SLCD frame has occurred.
 */
#define LCD_AR_LCDIF(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_AR_LCDIF_SHIFT)) & LCD_AR_LCDIF_MASK)
/*! @} */

/*! @name FDCR - LCD Fault Detect Control Register */
/*! @{ */

#define LCD_FDCR_FDPINID_MASK                    (0x3FU)
#define LCD_FDCR_FDPINID_SHIFT                   (0U)
/*! FDPINID - Fault Detect Pin ID
 *  0b000000..Fault detection for LCD_P0 pin.
 *  0b000001..Fault detection for LCD_P1 pin.
 *  0b111111..Fault detection for LCD_P63 pin.
 */
#define LCD_FDCR_FDPINID(x)                      (((uint32_t)(((uint32_t)(x)) << LCD_FDCR_FDPINID_SHIFT)) & LCD_FDCR_FDPINID_MASK)

#define LCD_FDCR_FDBPEN_MASK                     (0x40U)
#define LCD_FDCR_FDBPEN_SHIFT                    (6U)
/*! FDBPEN - Fault Detect Back Plane Enable
 *  0b0..Type of the selected pin under fault detect test is front plane.
 *  0b1..Type of the selected pin under fault detect test is back plane.
 */
#define LCD_FDCR_FDBPEN(x)                       (((uint32_t)(((uint32_t)(x)) << LCD_FDCR_FDBPEN_SHIFT)) & LCD_FDCR_FDBPEN_MASK)

#define LCD_FDCR_FDEN_MASK                       (0x80U)
#define LCD_FDCR_FDEN_SHIFT                      (7U)
/*! FDEN - Fault Detect Enable
 *  0b0..Disable fault detection.
 *  0b1..Enable fault detection.
 */
#define LCD_FDCR_FDEN(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_FDCR_FDEN_SHIFT)) & LCD_FDCR_FDEN_MASK)

#define LCD_FDCR_FDSWW_MASK                      (0xE00U)
#define LCD_FDCR_FDSWW_SHIFT                     (9U)
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
#define LCD_FDCR_FDSWW(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_FDCR_FDSWW_SHIFT)) & LCD_FDCR_FDSWW_MASK)

#define LCD_FDCR_FDPRS_MASK                      (0x7000U)
#define LCD_FDCR_FDPRS_SHIFT                     (12U)
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
#define LCD_FDCR_FDPRS(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_FDCR_FDPRS_SHIFT)) & LCD_FDCR_FDPRS_MASK)
/*! @} */

/*! @name FDSR - LCD Fault Detect Status Register */
/*! @{ */

#define LCD_FDSR_FDCNT_MASK                      (0xFFU)
#define LCD_FDSR_FDCNT_SHIFT                     (0U)
/*! FDCNT - Fault Detect Counter
 *  0b00000000..No "one" samples.
 *  0b00000001..1 "one" samples.
 *  0b00000010..2 "one" samples.
 *  0b11111110..254 "one" samples.
 *  0b11111111..255 or more "one" samples. The FDCNT can overflow. Therefore, FDSWW and FDPRS must be reconfigured for proper sampling.
 */
#define LCD_FDSR_FDCNT(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_FDSR_FDCNT_SHIFT)) & LCD_FDSR_FDCNT_MASK)

#define LCD_FDSR_FDCF_MASK                       (0x8000U)
#define LCD_FDSR_FDCF_SHIFT                      (15U)
/*! FDCF - Fault Detection Complete Flag
 *  0b0..Fault detection is not completed.
 *  0b1..Fault detection is completed.
 */
#define LCD_FDSR_FDCF(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_FDSR_FDCF_SHIFT)) & LCD_FDSR_FDCF_MASK)
/*! @} */

/*! @name PEN - LCD Pin Enable register */
/*! @{ */

#define LCD_PEN_PEN_MASK                         (0xFFFFFFFFU)
#define LCD_PEN_PEN_SHIFT                        (0U)
/*! PEN - LCD Pin Enable
 *  0b00000000000000000000000000000000..LCD operation disabled on LCD_Pn.
 *  0b00000000000000000000000000000001..LCD operation enabled on LCD_Pn.
 */
#define LCD_PEN_PEN(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_PEN_PEN_SHIFT)) & LCD_PEN_PEN_MASK)
/*! @} */

/*! @name BPEN - LCD Back Plane Enable register */
/*! @{ */

#define LCD_BPEN_BPEN_MASK                       (0xFFFFFFFFU)
#define LCD_BPEN_BPEN_SHIFT                      (0U)
/*! BPEN - Back Plane Enable
 *  0b00000000000000000000000000000000..Front plane operation enabled on LCD_Pn.
 *  0b00000000000000000000000000000001..Back plane operation enabled on LCD_Pn.
 */
#define LCD_BPEN_BPEN(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_BPEN_BPEN_SHIFT)) & LCD_BPEN_BPEN_MASK)
/*! @} */

/*! @name WF8B - LCD Waveform Register 0...LCD Waveform Register 63. */
/*! @{ */

#define LCD_WF8B_BPALCD0_MASK                    (0x1U)
#define LCD_WF8B_BPALCD0_SHIFT                   (0U)
/*! BPALCD0
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD0(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD0_SHIFT)) & LCD_WF8B_BPALCD0_MASK)

#define LCD_WF8B_BPALCD1_MASK                    (0x1U)
#define LCD_WF8B_BPALCD1_SHIFT                   (0U)
/*! BPALCD1
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD1(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD1_SHIFT)) & LCD_WF8B_BPALCD1_MASK)

#define LCD_WF8B_BPALCD2_MASK                    (0x1U)
#define LCD_WF8B_BPALCD2_SHIFT                   (0U)
/*! BPALCD2
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD2(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD2_SHIFT)) & LCD_WF8B_BPALCD2_MASK)

#define LCD_WF8B_BPALCD3_MASK                    (0x1U)
#define LCD_WF8B_BPALCD3_SHIFT                   (0U)
/*! BPALCD3
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD3(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD3_SHIFT)) & LCD_WF8B_BPALCD3_MASK)

#define LCD_WF8B_BPALCD4_MASK                    (0x1U)
#define LCD_WF8B_BPALCD4_SHIFT                   (0U)
/*! BPALCD4
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD4(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD4_SHIFT)) & LCD_WF8B_BPALCD4_MASK)

#define LCD_WF8B_BPALCD5_MASK                    (0x1U)
#define LCD_WF8B_BPALCD5_SHIFT                   (0U)
/*! BPALCD5
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD5(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD5_SHIFT)) & LCD_WF8B_BPALCD5_MASK)

#define LCD_WF8B_BPALCD6_MASK                    (0x1U)
#define LCD_WF8B_BPALCD6_SHIFT                   (0U)
/*! BPALCD6
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD6(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD6_SHIFT)) & LCD_WF8B_BPALCD6_MASK)

#define LCD_WF8B_BPALCD7_MASK                    (0x1U)
#define LCD_WF8B_BPALCD7_SHIFT                   (0U)
/*! BPALCD7
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD7(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD7_SHIFT)) & LCD_WF8B_BPALCD7_MASK)

#define LCD_WF8B_BPALCD8_MASK                    (0x1U)
#define LCD_WF8B_BPALCD8_SHIFT                   (0U)
/*! BPALCD8
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD8(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD8_SHIFT)) & LCD_WF8B_BPALCD8_MASK)

#define LCD_WF8B_BPALCD9_MASK                    (0x1U)
#define LCD_WF8B_BPALCD9_SHIFT                   (0U)
/*! BPALCD9
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD9(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD9_SHIFT)) & LCD_WF8B_BPALCD9_MASK)

#define LCD_WF8B_BPALCD10_MASK                   (0x1U)
#define LCD_WF8B_BPALCD10_SHIFT                  (0U)
/*! BPALCD10
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD10(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD10_SHIFT)) & LCD_WF8B_BPALCD10_MASK)

#define LCD_WF8B_BPALCD11_MASK                   (0x1U)
#define LCD_WF8B_BPALCD11_SHIFT                  (0U)
/*! BPALCD11
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD11(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD11_SHIFT)) & LCD_WF8B_BPALCD11_MASK)

#define LCD_WF8B_BPALCD12_MASK                   (0x1U)
#define LCD_WF8B_BPALCD12_SHIFT                  (0U)
/*! BPALCD12
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD12(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD12_SHIFT)) & LCD_WF8B_BPALCD12_MASK)

#define LCD_WF8B_BPALCD13_MASK                   (0x1U)
#define LCD_WF8B_BPALCD13_SHIFT                  (0U)
/*! BPALCD13
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD13(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD13_SHIFT)) & LCD_WF8B_BPALCD13_MASK)

#define LCD_WF8B_BPALCD14_MASK                   (0x1U)
#define LCD_WF8B_BPALCD14_SHIFT                  (0U)
/*! BPALCD14
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD14(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD14_SHIFT)) & LCD_WF8B_BPALCD14_MASK)

#define LCD_WF8B_BPALCD15_MASK                   (0x1U)
#define LCD_WF8B_BPALCD15_SHIFT                  (0U)
/*! BPALCD15
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD15(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD15_SHIFT)) & LCD_WF8B_BPALCD15_MASK)

#define LCD_WF8B_BPALCD16_MASK                   (0x1U)
#define LCD_WF8B_BPALCD16_SHIFT                  (0U)
/*! BPALCD16
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD16(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD16_SHIFT)) & LCD_WF8B_BPALCD16_MASK)

#define LCD_WF8B_BPALCD17_MASK                   (0x1U)
#define LCD_WF8B_BPALCD17_SHIFT                  (0U)
/*! BPALCD17
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD17(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD17_SHIFT)) & LCD_WF8B_BPALCD17_MASK)

#define LCD_WF8B_BPALCD18_MASK                   (0x1U)
#define LCD_WF8B_BPALCD18_SHIFT                  (0U)
/*! BPALCD18
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD18(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD18_SHIFT)) & LCD_WF8B_BPALCD18_MASK)

#define LCD_WF8B_BPALCD19_MASK                   (0x1U)
#define LCD_WF8B_BPALCD19_SHIFT                  (0U)
/*! BPALCD19
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD19(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD19_SHIFT)) & LCD_WF8B_BPALCD19_MASK)

#define LCD_WF8B_BPALCD20_MASK                   (0x1U)
#define LCD_WF8B_BPALCD20_SHIFT                  (0U)
/*! BPALCD20
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD20(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD20_SHIFT)) & LCD_WF8B_BPALCD20_MASK)

#define LCD_WF8B_BPALCD21_MASK                   (0x1U)
#define LCD_WF8B_BPALCD21_SHIFT                  (0U)
/*! BPALCD21
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD21(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD21_SHIFT)) & LCD_WF8B_BPALCD21_MASK)

#define LCD_WF8B_BPALCD22_MASK                   (0x1U)
#define LCD_WF8B_BPALCD22_SHIFT                  (0U)
/*! BPALCD22
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD22(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD22_SHIFT)) & LCD_WF8B_BPALCD22_MASK)

#define LCD_WF8B_BPALCD23_MASK                   (0x1U)
#define LCD_WF8B_BPALCD23_SHIFT                  (0U)
/*! BPALCD23
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD23(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD23_SHIFT)) & LCD_WF8B_BPALCD23_MASK)

#define LCD_WF8B_BPALCD24_MASK                   (0x1U)
#define LCD_WF8B_BPALCD24_SHIFT                  (0U)
/*! BPALCD24
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD24(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD24_SHIFT)) & LCD_WF8B_BPALCD24_MASK)

#define LCD_WF8B_BPALCD25_MASK                   (0x1U)
#define LCD_WF8B_BPALCD25_SHIFT                  (0U)
/*! BPALCD25
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD25(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD25_SHIFT)) & LCD_WF8B_BPALCD25_MASK)

#define LCD_WF8B_BPALCD26_MASK                   (0x1U)
#define LCD_WF8B_BPALCD26_SHIFT                  (0U)
/*! BPALCD26
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD26(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD26_SHIFT)) & LCD_WF8B_BPALCD26_MASK)

#define LCD_WF8B_BPALCD27_MASK                   (0x1U)
#define LCD_WF8B_BPALCD27_SHIFT                  (0U)
/*! BPALCD27
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD27(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD27_SHIFT)) & LCD_WF8B_BPALCD27_MASK)

#define LCD_WF8B_BPALCD28_MASK                   (0x1U)
#define LCD_WF8B_BPALCD28_SHIFT                  (0U)
/*! BPALCD28
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD28(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD28_SHIFT)) & LCD_WF8B_BPALCD28_MASK)

#define LCD_WF8B_BPALCD29_MASK                   (0x1U)
#define LCD_WF8B_BPALCD29_SHIFT                  (0U)
/*! BPALCD29
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD29(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD29_SHIFT)) & LCD_WF8B_BPALCD29_MASK)

#define LCD_WF8B_BPALCD30_MASK                   (0x1U)
#define LCD_WF8B_BPALCD30_SHIFT                  (0U)
/*! BPALCD30
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD30(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD30_SHIFT)) & LCD_WF8B_BPALCD30_MASK)

#define LCD_WF8B_BPALCD31_MASK                   (0x1U)
#define LCD_WF8B_BPALCD31_SHIFT                  (0U)
/*! BPALCD31
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD31(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD31_SHIFT)) & LCD_WF8B_BPALCD31_MASK)

#define LCD_WF8B_BPALCD32_MASK                   (0x1U)
#define LCD_WF8B_BPALCD32_SHIFT                  (0U)
/*! BPALCD32
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD32(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD32_SHIFT)) & LCD_WF8B_BPALCD32_MASK)

#define LCD_WF8B_BPALCD33_MASK                   (0x1U)
#define LCD_WF8B_BPALCD33_SHIFT                  (0U)
/*! BPALCD33
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD33(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD33_SHIFT)) & LCD_WF8B_BPALCD33_MASK)

#define LCD_WF8B_BPALCD34_MASK                   (0x1U)
#define LCD_WF8B_BPALCD34_SHIFT                  (0U)
/*! BPALCD34
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD34(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD34_SHIFT)) & LCD_WF8B_BPALCD34_MASK)

#define LCD_WF8B_BPALCD35_MASK                   (0x1U)
#define LCD_WF8B_BPALCD35_SHIFT                  (0U)
/*! BPALCD35
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD35(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD35_SHIFT)) & LCD_WF8B_BPALCD35_MASK)

#define LCD_WF8B_BPALCD36_MASK                   (0x1U)
#define LCD_WF8B_BPALCD36_SHIFT                  (0U)
/*! BPALCD36
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD36(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD36_SHIFT)) & LCD_WF8B_BPALCD36_MASK)

#define LCD_WF8B_BPALCD37_MASK                   (0x1U)
#define LCD_WF8B_BPALCD37_SHIFT                  (0U)
/*! BPALCD37
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD37(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD37_SHIFT)) & LCD_WF8B_BPALCD37_MASK)

#define LCD_WF8B_BPALCD38_MASK                   (0x1U)
#define LCD_WF8B_BPALCD38_SHIFT                  (0U)
/*! BPALCD38
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD38(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD38_SHIFT)) & LCD_WF8B_BPALCD38_MASK)

#define LCD_WF8B_BPALCD39_MASK                   (0x1U)
#define LCD_WF8B_BPALCD39_SHIFT                  (0U)
/*! BPALCD39
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD39(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD39_SHIFT)) & LCD_WF8B_BPALCD39_MASK)

#define LCD_WF8B_BPALCD40_MASK                   (0x1U)
#define LCD_WF8B_BPALCD40_SHIFT                  (0U)
/*! BPALCD40
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD40(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD40_SHIFT)) & LCD_WF8B_BPALCD40_MASK)

#define LCD_WF8B_BPALCD41_MASK                   (0x1U)
#define LCD_WF8B_BPALCD41_SHIFT                  (0U)
/*! BPALCD41
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD41(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD41_SHIFT)) & LCD_WF8B_BPALCD41_MASK)

#define LCD_WF8B_BPALCD42_MASK                   (0x1U)
#define LCD_WF8B_BPALCD42_SHIFT                  (0U)
/*! BPALCD42
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD42(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD42_SHIFT)) & LCD_WF8B_BPALCD42_MASK)

#define LCD_WF8B_BPALCD43_MASK                   (0x1U)
#define LCD_WF8B_BPALCD43_SHIFT                  (0U)
/*! BPALCD43
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD43(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD43_SHIFT)) & LCD_WF8B_BPALCD43_MASK)

#define LCD_WF8B_BPALCD44_MASK                   (0x1U)
#define LCD_WF8B_BPALCD44_SHIFT                  (0U)
/*! BPALCD44
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD44(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD44_SHIFT)) & LCD_WF8B_BPALCD44_MASK)

#define LCD_WF8B_BPALCD45_MASK                   (0x1U)
#define LCD_WF8B_BPALCD45_SHIFT                  (0U)
/*! BPALCD45
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD45(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD45_SHIFT)) & LCD_WF8B_BPALCD45_MASK)

#define LCD_WF8B_BPALCD46_MASK                   (0x1U)
#define LCD_WF8B_BPALCD46_SHIFT                  (0U)
/*! BPALCD46
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD46(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD46_SHIFT)) & LCD_WF8B_BPALCD46_MASK)

#define LCD_WF8B_BPALCD47_MASK                   (0x1U)
#define LCD_WF8B_BPALCD47_SHIFT                  (0U)
/*! BPALCD47
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD47(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD47_SHIFT)) & LCD_WF8B_BPALCD47_MASK)

#define LCD_WF8B_BPALCD48_MASK                   (0x1U)
#define LCD_WF8B_BPALCD48_SHIFT                  (0U)
/*! BPALCD48
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD48(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD48_SHIFT)) & LCD_WF8B_BPALCD48_MASK)

#define LCD_WF8B_BPALCD49_MASK                   (0x1U)
#define LCD_WF8B_BPALCD49_SHIFT                  (0U)
/*! BPALCD49
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD49(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD49_SHIFT)) & LCD_WF8B_BPALCD49_MASK)

#define LCD_WF8B_BPALCD50_MASK                   (0x1U)
#define LCD_WF8B_BPALCD50_SHIFT                  (0U)
/*! BPALCD50
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD50(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD50_SHIFT)) & LCD_WF8B_BPALCD50_MASK)

#define LCD_WF8B_BPALCD51_MASK                   (0x1U)
#define LCD_WF8B_BPALCD51_SHIFT                  (0U)
/*! BPALCD51
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD51(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD51_SHIFT)) & LCD_WF8B_BPALCD51_MASK)

#define LCD_WF8B_BPALCD52_MASK                   (0x1U)
#define LCD_WF8B_BPALCD52_SHIFT                  (0U)
/*! BPALCD52
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD52(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD52_SHIFT)) & LCD_WF8B_BPALCD52_MASK)

#define LCD_WF8B_BPALCD53_MASK                   (0x1U)
#define LCD_WF8B_BPALCD53_SHIFT                  (0U)
/*! BPALCD53
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD53(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD53_SHIFT)) & LCD_WF8B_BPALCD53_MASK)

#define LCD_WF8B_BPALCD54_MASK                   (0x1U)
#define LCD_WF8B_BPALCD54_SHIFT                  (0U)
/*! BPALCD54
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD54(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD54_SHIFT)) & LCD_WF8B_BPALCD54_MASK)

#define LCD_WF8B_BPALCD55_MASK                   (0x1U)
#define LCD_WF8B_BPALCD55_SHIFT                  (0U)
/*! BPALCD55
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD55(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD55_SHIFT)) & LCD_WF8B_BPALCD55_MASK)

#define LCD_WF8B_BPALCD56_MASK                   (0x1U)
#define LCD_WF8B_BPALCD56_SHIFT                  (0U)
/*! BPALCD56
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD56(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD56_SHIFT)) & LCD_WF8B_BPALCD56_MASK)

#define LCD_WF8B_BPALCD57_MASK                   (0x1U)
#define LCD_WF8B_BPALCD57_SHIFT                  (0U)
/*! BPALCD57
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD57(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD57_SHIFT)) & LCD_WF8B_BPALCD57_MASK)

#define LCD_WF8B_BPALCD58_MASK                   (0x1U)
#define LCD_WF8B_BPALCD58_SHIFT                  (0U)
/*! BPALCD58
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD58(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD58_SHIFT)) & LCD_WF8B_BPALCD58_MASK)

#define LCD_WF8B_BPALCD59_MASK                   (0x1U)
#define LCD_WF8B_BPALCD59_SHIFT                  (0U)
/*! BPALCD59
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD59(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD59_SHIFT)) & LCD_WF8B_BPALCD59_MASK)

#define LCD_WF8B_BPALCD60_MASK                   (0x1U)
#define LCD_WF8B_BPALCD60_SHIFT                  (0U)
/*! BPALCD60
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD60(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD60_SHIFT)) & LCD_WF8B_BPALCD60_MASK)

#define LCD_WF8B_BPALCD61_MASK                   (0x1U)
#define LCD_WF8B_BPALCD61_SHIFT                  (0U)
/*! BPALCD61
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD61(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD61_SHIFT)) & LCD_WF8B_BPALCD61_MASK)

#define LCD_WF8B_BPALCD62_MASK                   (0x1U)
#define LCD_WF8B_BPALCD62_SHIFT                  (0U)
/*! BPALCD62
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD62(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD62_SHIFT)) & LCD_WF8B_BPALCD62_MASK)

#define LCD_WF8B_BPALCD63_MASK                   (0x1U)
#define LCD_WF8B_BPALCD63_SHIFT                  (0U)
/*! BPALCD63
 *  0b0..LCD segment off or LCD backplane inactive for phase A
 *  0b1..LCD segment on or LCD backplane active for phase A
 */
#define LCD_WF8B_BPALCD63(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPALCD63_SHIFT)) & LCD_WF8B_BPALCD63_MASK)

#define LCD_WF8B_BPBLCD0_MASK                    (0x2U)
#define LCD_WF8B_BPBLCD0_SHIFT                   (1U)
/*! BPBLCD0
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD0(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD0_SHIFT)) & LCD_WF8B_BPBLCD0_MASK)

#define LCD_WF8B_BPBLCD1_MASK                    (0x2U)
#define LCD_WF8B_BPBLCD1_SHIFT                   (1U)
/*! BPBLCD1
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD1(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD1_SHIFT)) & LCD_WF8B_BPBLCD1_MASK)

#define LCD_WF8B_BPBLCD2_MASK                    (0x2U)
#define LCD_WF8B_BPBLCD2_SHIFT                   (1U)
/*! BPBLCD2
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD2(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD2_SHIFT)) & LCD_WF8B_BPBLCD2_MASK)

#define LCD_WF8B_BPBLCD3_MASK                    (0x2U)
#define LCD_WF8B_BPBLCD3_SHIFT                   (1U)
/*! BPBLCD3
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD3(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD3_SHIFT)) & LCD_WF8B_BPBLCD3_MASK)

#define LCD_WF8B_BPBLCD4_MASK                    (0x2U)
#define LCD_WF8B_BPBLCD4_SHIFT                   (1U)
/*! BPBLCD4
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD4(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD4_SHIFT)) & LCD_WF8B_BPBLCD4_MASK)

#define LCD_WF8B_BPBLCD5_MASK                    (0x2U)
#define LCD_WF8B_BPBLCD5_SHIFT                   (1U)
/*! BPBLCD5
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD5(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD5_SHIFT)) & LCD_WF8B_BPBLCD5_MASK)

#define LCD_WF8B_BPBLCD6_MASK                    (0x2U)
#define LCD_WF8B_BPBLCD6_SHIFT                   (1U)
/*! BPBLCD6
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD6(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD6_SHIFT)) & LCD_WF8B_BPBLCD6_MASK)

#define LCD_WF8B_BPBLCD7_MASK                    (0x2U)
#define LCD_WF8B_BPBLCD7_SHIFT                   (1U)
/*! BPBLCD7
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD7(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD7_SHIFT)) & LCD_WF8B_BPBLCD7_MASK)

#define LCD_WF8B_BPBLCD8_MASK                    (0x2U)
#define LCD_WF8B_BPBLCD8_SHIFT                   (1U)
/*! BPBLCD8
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD8(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD8_SHIFT)) & LCD_WF8B_BPBLCD8_MASK)

#define LCD_WF8B_BPBLCD9_MASK                    (0x2U)
#define LCD_WF8B_BPBLCD9_SHIFT                   (1U)
/*! BPBLCD9
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD9(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD9_SHIFT)) & LCD_WF8B_BPBLCD9_MASK)

#define LCD_WF8B_BPBLCD10_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD10_SHIFT                  (1U)
/*! BPBLCD10
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD10(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD10_SHIFT)) & LCD_WF8B_BPBLCD10_MASK)

#define LCD_WF8B_BPBLCD11_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD11_SHIFT                  (1U)
/*! BPBLCD11
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD11(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD11_SHIFT)) & LCD_WF8B_BPBLCD11_MASK)

#define LCD_WF8B_BPBLCD12_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD12_SHIFT                  (1U)
/*! BPBLCD12
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD12(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD12_SHIFT)) & LCD_WF8B_BPBLCD12_MASK)

#define LCD_WF8B_BPBLCD13_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD13_SHIFT                  (1U)
/*! BPBLCD13
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD13(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD13_SHIFT)) & LCD_WF8B_BPBLCD13_MASK)

#define LCD_WF8B_BPBLCD14_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD14_SHIFT                  (1U)
/*! BPBLCD14
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD14(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD14_SHIFT)) & LCD_WF8B_BPBLCD14_MASK)

#define LCD_WF8B_BPBLCD15_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD15_SHIFT                  (1U)
/*! BPBLCD15
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD15(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD15_SHIFT)) & LCD_WF8B_BPBLCD15_MASK)

#define LCD_WF8B_BPBLCD16_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD16_SHIFT                  (1U)
/*! BPBLCD16
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD16(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD16_SHIFT)) & LCD_WF8B_BPBLCD16_MASK)

#define LCD_WF8B_BPBLCD17_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD17_SHIFT                  (1U)
/*! BPBLCD17
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD17(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD17_SHIFT)) & LCD_WF8B_BPBLCD17_MASK)

#define LCD_WF8B_BPBLCD18_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD18_SHIFT                  (1U)
/*! BPBLCD18
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD18(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD18_SHIFT)) & LCD_WF8B_BPBLCD18_MASK)

#define LCD_WF8B_BPBLCD19_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD19_SHIFT                  (1U)
/*! BPBLCD19
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD19(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD19_SHIFT)) & LCD_WF8B_BPBLCD19_MASK)

#define LCD_WF8B_BPBLCD20_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD20_SHIFT                  (1U)
/*! BPBLCD20
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD20(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD20_SHIFT)) & LCD_WF8B_BPBLCD20_MASK)

#define LCD_WF8B_BPBLCD21_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD21_SHIFT                  (1U)
/*! BPBLCD21
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD21(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD21_SHIFT)) & LCD_WF8B_BPBLCD21_MASK)

#define LCD_WF8B_BPBLCD22_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD22_SHIFT                  (1U)
/*! BPBLCD22
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD22(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD22_SHIFT)) & LCD_WF8B_BPBLCD22_MASK)

#define LCD_WF8B_BPBLCD23_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD23_SHIFT                  (1U)
/*! BPBLCD23
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD23(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD23_SHIFT)) & LCD_WF8B_BPBLCD23_MASK)

#define LCD_WF8B_BPBLCD24_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD24_SHIFT                  (1U)
/*! BPBLCD24
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD24(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD24_SHIFT)) & LCD_WF8B_BPBLCD24_MASK)

#define LCD_WF8B_BPBLCD25_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD25_SHIFT                  (1U)
/*! BPBLCD25
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD25(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD25_SHIFT)) & LCD_WF8B_BPBLCD25_MASK)

#define LCD_WF8B_BPBLCD26_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD26_SHIFT                  (1U)
/*! BPBLCD26
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD26(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD26_SHIFT)) & LCD_WF8B_BPBLCD26_MASK)

#define LCD_WF8B_BPBLCD27_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD27_SHIFT                  (1U)
/*! BPBLCD27
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD27(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD27_SHIFT)) & LCD_WF8B_BPBLCD27_MASK)

#define LCD_WF8B_BPBLCD28_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD28_SHIFT                  (1U)
/*! BPBLCD28
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD28(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD28_SHIFT)) & LCD_WF8B_BPBLCD28_MASK)

#define LCD_WF8B_BPBLCD29_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD29_SHIFT                  (1U)
/*! BPBLCD29
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD29(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD29_SHIFT)) & LCD_WF8B_BPBLCD29_MASK)

#define LCD_WF8B_BPBLCD30_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD30_SHIFT                  (1U)
/*! BPBLCD30
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD30(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD30_SHIFT)) & LCD_WF8B_BPBLCD30_MASK)

#define LCD_WF8B_BPBLCD31_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD31_SHIFT                  (1U)
/*! BPBLCD31
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD31(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD31_SHIFT)) & LCD_WF8B_BPBLCD31_MASK)

#define LCD_WF8B_BPBLCD32_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD32_SHIFT                  (1U)
/*! BPBLCD32
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD32(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD32_SHIFT)) & LCD_WF8B_BPBLCD32_MASK)

#define LCD_WF8B_BPBLCD33_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD33_SHIFT                  (1U)
/*! BPBLCD33
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD33(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD33_SHIFT)) & LCD_WF8B_BPBLCD33_MASK)

#define LCD_WF8B_BPBLCD34_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD34_SHIFT                  (1U)
/*! BPBLCD34
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD34(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD34_SHIFT)) & LCD_WF8B_BPBLCD34_MASK)

#define LCD_WF8B_BPBLCD35_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD35_SHIFT                  (1U)
/*! BPBLCD35
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD35(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD35_SHIFT)) & LCD_WF8B_BPBLCD35_MASK)

#define LCD_WF8B_BPBLCD36_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD36_SHIFT                  (1U)
/*! BPBLCD36
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD36(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD36_SHIFT)) & LCD_WF8B_BPBLCD36_MASK)

#define LCD_WF8B_BPBLCD37_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD37_SHIFT                  (1U)
/*! BPBLCD37
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD37(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD37_SHIFT)) & LCD_WF8B_BPBLCD37_MASK)

#define LCD_WF8B_BPBLCD38_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD38_SHIFT                  (1U)
/*! BPBLCD38
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD38(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD38_SHIFT)) & LCD_WF8B_BPBLCD38_MASK)

#define LCD_WF8B_BPBLCD39_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD39_SHIFT                  (1U)
/*! BPBLCD39
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD39(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD39_SHIFT)) & LCD_WF8B_BPBLCD39_MASK)

#define LCD_WF8B_BPBLCD40_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD40_SHIFT                  (1U)
/*! BPBLCD40
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD40(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD40_SHIFT)) & LCD_WF8B_BPBLCD40_MASK)

#define LCD_WF8B_BPBLCD41_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD41_SHIFT                  (1U)
/*! BPBLCD41
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD41(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD41_SHIFT)) & LCD_WF8B_BPBLCD41_MASK)

#define LCD_WF8B_BPBLCD42_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD42_SHIFT                  (1U)
/*! BPBLCD42
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD42(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD42_SHIFT)) & LCD_WF8B_BPBLCD42_MASK)

#define LCD_WF8B_BPBLCD43_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD43_SHIFT                  (1U)
/*! BPBLCD43
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD43(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD43_SHIFT)) & LCD_WF8B_BPBLCD43_MASK)

#define LCD_WF8B_BPBLCD44_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD44_SHIFT                  (1U)
/*! BPBLCD44
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD44(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD44_SHIFT)) & LCD_WF8B_BPBLCD44_MASK)

#define LCD_WF8B_BPBLCD45_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD45_SHIFT                  (1U)
/*! BPBLCD45
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD45(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD45_SHIFT)) & LCD_WF8B_BPBLCD45_MASK)

#define LCD_WF8B_BPBLCD46_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD46_SHIFT                  (1U)
/*! BPBLCD46
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD46(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD46_SHIFT)) & LCD_WF8B_BPBLCD46_MASK)

#define LCD_WF8B_BPBLCD47_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD47_SHIFT                  (1U)
/*! BPBLCD47
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD47(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD47_SHIFT)) & LCD_WF8B_BPBLCD47_MASK)

#define LCD_WF8B_BPBLCD48_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD48_SHIFT                  (1U)
/*! BPBLCD48
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD48(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD48_SHIFT)) & LCD_WF8B_BPBLCD48_MASK)

#define LCD_WF8B_BPBLCD49_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD49_SHIFT                  (1U)
/*! BPBLCD49
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD49(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD49_SHIFT)) & LCD_WF8B_BPBLCD49_MASK)

#define LCD_WF8B_BPBLCD50_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD50_SHIFT                  (1U)
/*! BPBLCD50
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD50(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD50_SHIFT)) & LCD_WF8B_BPBLCD50_MASK)

#define LCD_WF8B_BPBLCD51_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD51_SHIFT                  (1U)
/*! BPBLCD51
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD51(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD51_SHIFT)) & LCD_WF8B_BPBLCD51_MASK)

#define LCD_WF8B_BPBLCD52_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD52_SHIFT                  (1U)
/*! BPBLCD52
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD52(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD52_SHIFT)) & LCD_WF8B_BPBLCD52_MASK)

#define LCD_WF8B_BPBLCD53_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD53_SHIFT                  (1U)
/*! BPBLCD53
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD53(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD53_SHIFT)) & LCD_WF8B_BPBLCD53_MASK)

#define LCD_WF8B_BPBLCD54_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD54_SHIFT                  (1U)
/*! BPBLCD54
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD54(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD54_SHIFT)) & LCD_WF8B_BPBLCD54_MASK)

#define LCD_WF8B_BPBLCD55_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD55_SHIFT                  (1U)
/*! BPBLCD55
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD55(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD55_SHIFT)) & LCD_WF8B_BPBLCD55_MASK)

#define LCD_WF8B_BPBLCD56_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD56_SHIFT                  (1U)
/*! BPBLCD56
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD56(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD56_SHIFT)) & LCD_WF8B_BPBLCD56_MASK)

#define LCD_WF8B_BPBLCD57_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD57_SHIFT                  (1U)
/*! BPBLCD57
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD57(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD57_SHIFT)) & LCD_WF8B_BPBLCD57_MASK)

#define LCD_WF8B_BPBLCD58_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD58_SHIFT                  (1U)
/*! BPBLCD58
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD58(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD58_SHIFT)) & LCD_WF8B_BPBLCD58_MASK)

#define LCD_WF8B_BPBLCD59_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD59_SHIFT                  (1U)
/*! BPBLCD59
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD59(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD59_SHIFT)) & LCD_WF8B_BPBLCD59_MASK)

#define LCD_WF8B_BPBLCD60_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD60_SHIFT                  (1U)
/*! BPBLCD60
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD60(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD60_SHIFT)) & LCD_WF8B_BPBLCD60_MASK)

#define LCD_WF8B_BPBLCD61_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD61_SHIFT                  (1U)
/*! BPBLCD61
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD61(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD61_SHIFT)) & LCD_WF8B_BPBLCD61_MASK)

#define LCD_WF8B_BPBLCD62_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD62_SHIFT                  (1U)
/*! BPBLCD62
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD62(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD62_SHIFT)) & LCD_WF8B_BPBLCD62_MASK)

#define LCD_WF8B_BPBLCD63_MASK                   (0x2U)
#define LCD_WF8B_BPBLCD63_SHIFT                  (1U)
/*! BPBLCD63
 *  0b0..LCD segment off or LCD backplane inactive for phase B
 *  0b1..LCD segment on or LCD backplane active for phase B
 */
#define LCD_WF8B_BPBLCD63(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPBLCD63_SHIFT)) & LCD_WF8B_BPBLCD63_MASK)

#define LCD_WF8B_BPCLCD0_MASK                    (0x4U)
#define LCD_WF8B_BPCLCD0_SHIFT                   (2U)
/*! BPCLCD0
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD0(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD0_SHIFT)) & LCD_WF8B_BPCLCD0_MASK)

#define LCD_WF8B_BPCLCD1_MASK                    (0x4U)
#define LCD_WF8B_BPCLCD1_SHIFT                   (2U)
/*! BPCLCD1
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD1(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD1_SHIFT)) & LCD_WF8B_BPCLCD1_MASK)

#define LCD_WF8B_BPCLCD2_MASK                    (0x4U)
#define LCD_WF8B_BPCLCD2_SHIFT                   (2U)
/*! BPCLCD2
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD2(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD2_SHIFT)) & LCD_WF8B_BPCLCD2_MASK)

#define LCD_WF8B_BPCLCD3_MASK                    (0x4U)
#define LCD_WF8B_BPCLCD3_SHIFT                   (2U)
/*! BPCLCD3
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD3(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD3_SHIFT)) & LCD_WF8B_BPCLCD3_MASK)

#define LCD_WF8B_BPCLCD4_MASK                    (0x4U)
#define LCD_WF8B_BPCLCD4_SHIFT                   (2U)
/*! BPCLCD4
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD4(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD4_SHIFT)) & LCD_WF8B_BPCLCD4_MASK)

#define LCD_WF8B_BPCLCD5_MASK                    (0x4U)
#define LCD_WF8B_BPCLCD5_SHIFT                   (2U)
/*! BPCLCD5
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD5(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD5_SHIFT)) & LCD_WF8B_BPCLCD5_MASK)

#define LCD_WF8B_BPCLCD6_MASK                    (0x4U)
#define LCD_WF8B_BPCLCD6_SHIFT                   (2U)
/*! BPCLCD6
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD6(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD6_SHIFT)) & LCD_WF8B_BPCLCD6_MASK)

#define LCD_WF8B_BPCLCD7_MASK                    (0x4U)
#define LCD_WF8B_BPCLCD7_SHIFT                   (2U)
/*! BPCLCD7
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD7(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD7_SHIFT)) & LCD_WF8B_BPCLCD7_MASK)

#define LCD_WF8B_BPCLCD8_MASK                    (0x4U)
#define LCD_WF8B_BPCLCD8_SHIFT                   (2U)
/*! BPCLCD8
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD8(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD8_SHIFT)) & LCD_WF8B_BPCLCD8_MASK)

#define LCD_WF8B_BPCLCD9_MASK                    (0x4U)
#define LCD_WF8B_BPCLCD9_SHIFT                   (2U)
/*! BPCLCD9
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD9(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD9_SHIFT)) & LCD_WF8B_BPCLCD9_MASK)

#define LCD_WF8B_BPCLCD10_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD10_SHIFT                  (2U)
/*! BPCLCD10
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD10(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD10_SHIFT)) & LCD_WF8B_BPCLCD10_MASK)

#define LCD_WF8B_BPCLCD11_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD11_SHIFT                  (2U)
/*! BPCLCD11
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD11(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD11_SHIFT)) & LCD_WF8B_BPCLCD11_MASK)

#define LCD_WF8B_BPCLCD12_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD12_SHIFT                  (2U)
/*! BPCLCD12
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD12(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD12_SHIFT)) & LCD_WF8B_BPCLCD12_MASK)

#define LCD_WF8B_BPCLCD13_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD13_SHIFT                  (2U)
/*! BPCLCD13
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD13(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD13_SHIFT)) & LCD_WF8B_BPCLCD13_MASK)

#define LCD_WF8B_BPCLCD14_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD14_SHIFT                  (2U)
/*! BPCLCD14
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD14(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD14_SHIFT)) & LCD_WF8B_BPCLCD14_MASK)

#define LCD_WF8B_BPCLCD15_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD15_SHIFT                  (2U)
/*! BPCLCD15
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD15(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD15_SHIFT)) & LCD_WF8B_BPCLCD15_MASK)

#define LCD_WF8B_BPCLCD16_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD16_SHIFT                  (2U)
/*! BPCLCD16
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD16(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD16_SHIFT)) & LCD_WF8B_BPCLCD16_MASK)

#define LCD_WF8B_BPCLCD17_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD17_SHIFT                  (2U)
/*! BPCLCD17
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD17(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD17_SHIFT)) & LCD_WF8B_BPCLCD17_MASK)

#define LCD_WF8B_BPCLCD18_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD18_SHIFT                  (2U)
/*! BPCLCD18
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD18(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD18_SHIFT)) & LCD_WF8B_BPCLCD18_MASK)

#define LCD_WF8B_BPCLCD19_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD19_SHIFT                  (2U)
/*! BPCLCD19
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD19(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD19_SHIFT)) & LCD_WF8B_BPCLCD19_MASK)

#define LCD_WF8B_BPCLCD20_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD20_SHIFT                  (2U)
/*! BPCLCD20
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD20(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD20_SHIFT)) & LCD_WF8B_BPCLCD20_MASK)

#define LCD_WF8B_BPCLCD21_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD21_SHIFT                  (2U)
/*! BPCLCD21
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD21(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD21_SHIFT)) & LCD_WF8B_BPCLCD21_MASK)

#define LCD_WF8B_BPCLCD22_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD22_SHIFT                  (2U)
/*! BPCLCD22
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD22(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD22_SHIFT)) & LCD_WF8B_BPCLCD22_MASK)

#define LCD_WF8B_BPCLCD23_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD23_SHIFT                  (2U)
/*! BPCLCD23
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD23(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD23_SHIFT)) & LCD_WF8B_BPCLCD23_MASK)

#define LCD_WF8B_BPCLCD24_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD24_SHIFT                  (2U)
/*! BPCLCD24
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD24(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD24_SHIFT)) & LCD_WF8B_BPCLCD24_MASK)

#define LCD_WF8B_BPCLCD25_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD25_SHIFT                  (2U)
/*! BPCLCD25
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD25(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD25_SHIFT)) & LCD_WF8B_BPCLCD25_MASK)

#define LCD_WF8B_BPCLCD26_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD26_SHIFT                  (2U)
/*! BPCLCD26
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD26(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD26_SHIFT)) & LCD_WF8B_BPCLCD26_MASK)

#define LCD_WF8B_BPCLCD27_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD27_SHIFT                  (2U)
/*! BPCLCD27
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD27(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD27_SHIFT)) & LCD_WF8B_BPCLCD27_MASK)

#define LCD_WF8B_BPCLCD28_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD28_SHIFT                  (2U)
/*! BPCLCD28
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD28(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD28_SHIFT)) & LCD_WF8B_BPCLCD28_MASK)

#define LCD_WF8B_BPCLCD29_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD29_SHIFT                  (2U)
/*! BPCLCD29
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD29(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD29_SHIFT)) & LCD_WF8B_BPCLCD29_MASK)

#define LCD_WF8B_BPCLCD30_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD30_SHIFT                  (2U)
/*! BPCLCD30
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD30(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD30_SHIFT)) & LCD_WF8B_BPCLCD30_MASK)

#define LCD_WF8B_BPCLCD31_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD31_SHIFT                  (2U)
/*! BPCLCD31
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD31(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD31_SHIFT)) & LCD_WF8B_BPCLCD31_MASK)

#define LCD_WF8B_BPCLCD32_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD32_SHIFT                  (2U)
/*! BPCLCD32
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD32(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD32_SHIFT)) & LCD_WF8B_BPCLCD32_MASK)

#define LCD_WF8B_BPCLCD33_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD33_SHIFT                  (2U)
/*! BPCLCD33
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD33(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD33_SHIFT)) & LCD_WF8B_BPCLCD33_MASK)

#define LCD_WF8B_BPCLCD34_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD34_SHIFT                  (2U)
/*! BPCLCD34
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD34(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD34_SHIFT)) & LCD_WF8B_BPCLCD34_MASK)

#define LCD_WF8B_BPCLCD35_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD35_SHIFT                  (2U)
/*! BPCLCD35
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD35(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD35_SHIFT)) & LCD_WF8B_BPCLCD35_MASK)

#define LCD_WF8B_BPCLCD36_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD36_SHIFT                  (2U)
/*! BPCLCD36
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD36(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD36_SHIFT)) & LCD_WF8B_BPCLCD36_MASK)

#define LCD_WF8B_BPCLCD37_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD37_SHIFT                  (2U)
/*! BPCLCD37
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD37(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD37_SHIFT)) & LCD_WF8B_BPCLCD37_MASK)

#define LCD_WF8B_BPCLCD38_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD38_SHIFT                  (2U)
/*! BPCLCD38
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD38(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD38_SHIFT)) & LCD_WF8B_BPCLCD38_MASK)

#define LCD_WF8B_BPCLCD39_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD39_SHIFT                  (2U)
/*! BPCLCD39
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD39(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD39_SHIFT)) & LCD_WF8B_BPCLCD39_MASK)

#define LCD_WF8B_BPCLCD40_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD40_SHIFT                  (2U)
/*! BPCLCD40
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD40(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD40_SHIFT)) & LCD_WF8B_BPCLCD40_MASK)

#define LCD_WF8B_BPCLCD41_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD41_SHIFT                  (2U)
/*! BPCLCD41
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD41(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD41_SHIFT)) & LCD_WF8B_BPCLCD41_MASK)

#define LCD_WF8B_BPCLCD42_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD42_SHIFT                  (2U)
/*! BPCLCD42
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD42(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD42_SHIFT)) & LCD_WF8B_BPCLCD42_MASK)

#define LCD_WF8B_BPCLCD43_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD43_SHIFT                  (2U)
/*! BPCLCD43
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD43(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD43_SHIFT)) & LCD_WF8B_BPCLCD43_MASK)

#define LCD_WF8B_BPCLCD44_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD44_SHIFT                  (2U)
/*! BPCLCD44
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD44(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD44_SHIFT)) & LCD_WF8B_BPCLCD44_MASK)

#define LCD_WF8B_BPCLCD45_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD45_SHIFT                  (2U)
/*! BPCLCD45
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD45(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD45_SHIFT)) & LCD_WF8B_BPCLCD45_MASK)

#define LCD_WF8B_BPCLCD46_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD46_SHIFT                  (2U)
/*! BPCLCD46
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD46(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD46_SHIFT)) & LCD_WF8B_BPCLCD46_MASK)

#define LCD_WF8B_BPCLCD47_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD47_SHIFT                  (2U)
/*! BPCLCD47
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD47(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD47_SHIFT)) & LCD_WF8B_BPCLCD47_MASK)

#define LCD_WF8B_BPCLCD48_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD48_SHIFT                  (2U)
/*! BPCLCD48
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD48(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD48_SHIFT)) & LCD_WF8B_BPCLCD48_MASK)

#define LCD_WF8B_BPCLCD49_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD49_SHIFT                  (2U)
/*! BPCLCD49
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD49(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD49_SHIFT)) & LCD_WF8B_BPCLCD49_MASK)

#define LCD_WF8B_BPCLCD50_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD50_SHIFT                  (2U)
/*! BPCLCD50
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD50(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD50_SHIFT)) & LCD_WF8B_BPCLCD50_MASK)

#define LCD_WF8B_BPCLCD51_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD51_SHIFT                  (2U)
/*! BPCLCD51
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD51(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD51_SHIFT)) & LCD_WF8B_BPCLCD51_MASK)

#define LCD_WF8B_BPCLCD52_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD52_SHIFT                  (2U)
/*! BPCLCD52
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD52(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD52_SHIFT)) & LCD_WF8B_BPCLCD52_MASK)

#define LCD_WF8B_BPCLCD53_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD53_SHIFT                  (2U)
/*! BPCLCD53
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD53(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD53_SHIFT)) & LCD_WF8B_BPCLCD53_MASK)

#define LCD_WF8B_BPCLCD54_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD54_SHIFT                  (2U)
/*! BPCLCD54
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD54(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD54_SHIFT)) & LCD_WF8B_BPCLCD54_MASK)

#define LCD_WF8B_BPCLCD55_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD55_SHIFT                  (2U)
/*! BPCLCD55
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD55(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD55_SHIFT)) & LCD_WF8B_BPCLCD55_MASK)

#define LCD_WF8B_BPCLCD56_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD56_SHIFT                  (2U)
/*! BPCLCD56
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD56(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD56_SHIFT)) & LCD_WF8B_BPCLCD56_MASK)

#define LCD_WF8B_BPCLCD57_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD57_SHIFT                  (2U)
/*! BPCLCD57
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD57(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD57_SHIFT)) & LCD_WF8B_BPCLCD57_MASK)

#define LCD_WF8B_BPCLCD58_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD58_SHIFT                  (2U)
/*! BPCLCD58
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD58(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD58_SHIFT)) & LCD_WF8B_BPCLCD58_MASK)

#define LCD_WF8B_BPCLCD59_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD59_SHIFT                  (2U)
/*! BPCLCD59
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD59(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD59_SHIFT)) & LCD_WF8B_BPCLCD59_MASK)

#define LCD_WF8B_BPCLCD60_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD60_SHIFT                  (2U)
/*! BPCLCD60
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD60(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD60_SHIFT)) & LCD_WF8B_BPCLCD60_MASK)

#define LCD_WF8B_BPCLCD61_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD61_SHIFT                  (2U)
/*! BPCLCD61
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD61(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD61_SHIFT)) & LCD_WF8B_BPCLCD61_MASK)

#define LCD_WF8B_BPCLCD62_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD62_SHIFT                  (2U)
/*! BPCLCD62
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD62(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD62_SHIFT)) & LCD_WF8B_BPCLCD62_MASK)

#define LCD_WF8B_BPCLCD63_MASK                   (0x4U)
#define LCD_WF8B_BPCLCD63_SHIFT                  (2U)
/*! BPCLCD63
 *  0b0..LCD segment off or LCD backplane inactive for phase C
 *  0b1..LCD segment on or LCD backplane active for phase C
 */
#define LCD_WF8B_BPCLCD63(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPCLCD63_SHIFT)) & LCD_WF8B_BPCLCD63_MASK)

#define LCD_WF8B_BPDLCD0_MASK                    (0x8U)
#define LCD_WF8B_BPDLCD0_SHIFT                   (3U)
/*! BPDLCD0
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD0(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD0_SHIFT)) & LCD_WF8B_BPDLCD0_MASK)

#define LCD_WF8B_BPDLCD1_MASK                    (0x8U)
#define LCD_WF8B_BPDLCD1_SHIFT                   (3U)
/*! BPDLCD1
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD1(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD1_SHIFT)) & LCD_WF8B_BPDLCD1_MASK)

#define LCD_WF8B_BPDLCD2_MASK                    (0x8U)
#define LCD_WF8B_BPDLCD2_SHIFT                   (3U)
/*! BPDLCD2
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD2(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD2_SHIFT)) & LCD_WF8B_BPDLCD2_MASK)

#define LCD_WF8B_BPDLCD3_MASK                    (0x8U)
#define LCD_WF8B_BPDLCD3_SHIFT                   (3U)
/*! BPDLCD3
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD3(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD3_SHIFT)) & LCD_WF8B_BPDLCD3_MASK)

#define LCD_WF8B_BPDLCD4_MASK                    (0x8U)
#define LCD_WF8B_BPDLCD4_SHIFT                   (3U)
/*! BPDLCD4
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD4(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD4_SHIFT)) & LCD_WF8B_BPDLCD4_MASK)

#define LCD_WF8B_BPDLCD5_MASK                    (0x8U)
#define LCD_WF8B_BPDLCD5_SHIFT                   (3U)
/*! BPDLCD5
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD5(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD5_SHIFT)) & LCD_WF8B_BPDLCD5_MASK)

#define LCD_WF8B_BPDLCD6_MASK                    (0x8U)
#define LCD_WF8B_BPDLCD6_SHIFT                   (3U)
/*! BPDLCD6
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD6(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD6_SHIFT)) & LCD_WF8B_BPDLCD6_MASK)

#define LCD_WF8B_BPDLCD7_MASK                    (0x8U)
#define LCD_WF8B_BPDLCD7_SHIFT                   (3U)
/*! BPDLCD7
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD7(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD7_SHIFT)) & LCD_WF8B_BPDLCD7_MASK)

#define LCD_WF8B_BPDLCD8_MASK                    (0x8U)
#define LCD_WF8B_BPDLCD8_SHIFT                   (3U)
/*! BPDLCD8
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD8(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD8_SHIFT)) & LCD_WF8B_BPDLCD8_MASK)

#define LCD_WF8B_BPDLCD9_MASK                    (0x8U)
#define LCD_WF8B_BPDLCD9_SHIFT                   (3U)
/*! BPDLCD9
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD9(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD9_SHIFT)) & LCD_WF8B_BPDLCD9_MASK)

#define LCD_WF8B_BPDLCD10_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD10_SHIFT                  (3U)
/*! BPDLCD10
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD10(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD10_SHIFT)) & LCD_WF8B_BPDLCD10_MASK)

#define LCD_WF8B_BPDLCD11_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD11_SHIFT                  (3U)
/*! BPDLCD11
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD11(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD11_SHIFT)) & LCD_WF8B_BPDLCD11_MASK)

#define LCD_WF8B_BPDLCD12_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD12_SHIFT                  (3U)
/*! BPDLCD12
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD12(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD12_SHIFT)) & LCD_WF8B_BPDLCD12_MASK)

#define LCD_WF8B_BPDLCD13_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD13_SHIFT                  (3U)
/*! BPDLCD13
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD13(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD13_SHIFT)) & LCD_WF8B_BPDLCD13_MASK)

#define LCD_WF8B_BPDLCD14_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD14_SHIFT                  (3U)
/*! BPDLCD14
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD14(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD14_SHIFT)) & LCD_WF8B_BPDLCD14_MASK)

#define LCD_WF8B_BPDLCD15_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD15_SHIFT                  (3U)
/*! BPDLCD15
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD15(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD15_SHIFT)) & LCD_WF8B_BPDLCD15_MASK)

#define LCD_WF8B_BPDLCD16_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD16_SHIFT                  (3U)
/*! BPDLCD16
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD16(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD16_SHIFT)) & LCD_WF8B_BPDLCD16_MASK)

#define LCD_WF8B_BPDLCD17_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD17_SHIFT                  (3U)
/*! BPDLCD17
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD17(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD17_SHIFT)) & LCD_WF8B_BPDLCD17_MASK)

#define LCD_WF8B_BPDLCD18_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD18_SHIFT                  (3U)
/*! BPDLCD18
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD18(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD18_SHIFT)) & LCD_WF8B_BPDLCD18_MASK)

#define LCD_WF8B_BPDLCD19_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD19_SHIFT                  (3U)
/*! BPDLCD19
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD19(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD19_SHIFT)) & LCD_WF8B_BPDLCD19_MASK)

#define LCD_WF8B_BPDLCD20_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD20_SHIFT                  (3U)
/*! BPDLCD20
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD20(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD20_SHIFT)) & LCD_WF8B_BPDLCD20_MASK)

#define LCD_WF8B_BPDLCD21_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD21_SHIFT                  (3U)
/*! BPDLCD21
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD21(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD21_SHIFT)) & LCD_WF8B_BPDLCD21_MASK)

#define LCD_WF8B_BPDLCD22_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD22_SHIFT                  (3U)
/*! BPDLCD22
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD22(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD22_SHIFT)) & LCD_WF8B_BPDLCD22_MASK)

#define LCD_WF8B_BPDLCD23_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD23_SHIFT                  (3U)
/*! BPDLCD23
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD23(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD23_SHIFT)) & LCD_WF8B_BPDLCD23_MASK)

#define LCD_WF8B_BPDLCD24_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD24_SHIFT                  (3U)
/*! BPDLCD24
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD24(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD24_SHIFT)) & LCD_WF8B_BPDLCD24_MASK)

#define LCD_WF8B_BPDLCD25_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD25_SHIFT                  (3U)
/*! BPDLCD25
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD25(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD25_SHIFT)) & LCD_WF8B_BPDLCD25_MASK)

#define LCD_WF8B_BPDLCD26_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD26_SHIFT                  (3U)
/*! BPDLCD26
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD26(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD26_SHIFT)) & LCD_WF8B_BPDLCD26_MASK)

#define LCD_WF8B_BPDLCD27_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD27_SHIFT                  (3U)
/*! BPDLCD27
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD27(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD27_SHIFT)) & LCD_WF8B_BPDLCD27_MASK)

#define LCD_WF8B_BPDLCD28_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD28_SHIFT                  (3U)
/*! BPDLCD28
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD28(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD28_SHIFT)) & LCD_WF8B_BPDLCD28_MASK)

#define LCD_WF8B_BPDLCD29_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD29_SHIFT                  (3U)
/*! BPDLCD29
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD29(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD29_SHIFT)) & LCD_WF8B_BPDLCD29_MASK)

#define LCD_WF8B_BPDLCD30_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD30_SHIFT                  (3U)
/*! BPDLCD30
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD30(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD30_SHIFT)) & LCD_WF8B_BPDLCD30_MASK)

#define LCD_WF8B_BPDLCD31_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD31_SHIFT                  (3U)
/*! BPDLCD31
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD31(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD31_SHIFT)) & LCD_WF8B_BPDLCD31_MASK)

#define LCD_WF8B_BPDLCD32_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD32_SHIFT                  (3U)
/*! BPDLCD32
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD32(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD32_SHIFT)) & LCD_WF8B_BPDLCD32_MASK)

#define LCD_WF8B_BPDLCD33_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD33_SHIFT                  (3U)
/*! BPDLCD33
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD33(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD33_SHIFT)) & LCD_WF8B_BPDLCD33_MASK)

#define LCD_WF8B_BPDLCD34_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD34_SHIFT                  (3U)
/*! BPDLCD34
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD34(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD34_SHIFT)) & LCD_WF8B_BPDLCD34_MASK)

#define LCD_WF8B_BPDLCD35_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD35_SHIFT                  (3U)
/*! BPDLCD35
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD35(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD35_SHIFT)) & LCD_WF8B_BPDLCD35_MASK)

#define LCD_WF8B_BPDLCD36_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD36_SHIFT                  (3U)
/*! BPDLCD36
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD36(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD36_SHIFT)) & LCD_WF8B_BPDLCD36_MASK)

#define LCD_WF8B_BPDLCD37_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD37_SHIFT                  (3U)
/*! BPDLCD37
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD37(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD37_SHIFT)) & LCD_WF8B_BPDLCD37_MASK)

#define LCD_WF8B_BPDLCD38_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD38_SHIFT                  (3U)
/*! BPDLCD38
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD38(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD38_SHIFT)) & LCD_WF8B_BPDLCD38_MASK)

#define LCD_WF8B_BPDLCD39_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD39_SHIFT                  (3U)
/*! BPDLCD39
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD39(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD39_SHIFT)) & LCD_WF8B_BPDLCD39_MASK)

#define LCD_WF8B_BPDLCD40_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD40_SHIFT                  (3U)
/*! BPDLCD40
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD40(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD40_SHIFT)) & LCD_WF8B_BPDLCD40_MASK)

#define LCD_WF8B_BPDLCD41_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD41_SHIFT                  (3U)
/*! BPDLCD41
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD41(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD41_SHIFT)) & LCD_WF8B_BPDLCD41_MASK)

#define LCD_WF8B_BPDLCD42_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD42_SHIFT                  (3U)
/*! BPDLCD42
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD42(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD42_SHIFT)) & LCD_WF8B_BPDLCD42_MASK)

#define LCD_WF8B_BPDLCD43_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD43_SHIFT                  (3U)
/*! BPDLCD43
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD43(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD43_SHIFT)) & LCD_WF8B_BPDLCD43_MASK)

#define LCD_WF8B_BPDLCD44_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD44_SHIFT                  (3U)
/*! BPDLCD44
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD44(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD44_SHIFT)) & LCD_WF8B_BPDLCD44_MASK)

#define LCD_WF8B_BPDLCD45_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD45_SHIFT                  (3U)
/*! BPDLCD45
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD45(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD45_SHIFT)) & LCD_WF8B_BPDLCD45_MASK)

#define LCD_WF8B_BPDLCD46_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD46_SHIFT                  (3U)
/*! BPDLCD46
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD46(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD46_SHIFT)) & LCD_WF8B_BPDLCD46_MASK)

#define LCD_WF8B_BPDLCD47_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD47_SHIFT                  (3U)
/*! BPDLCD47
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD47(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD47_SHIFT)) & LCD_WF8B_BPDLCD47_MASK)

#define LCD_WF8B_BPDLCD48_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD48_SHIFT                  (3U)
/*! BPDLCD48
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD48(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD48_SHIFT)) & LCD_WF8B_BPDLCD48_MASK)

#define LCD_WF8B_BPDLCD49_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD49_SHIFT                  (3U)
/*! BPDLCD49
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD49(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD49_SHIFT)) & LCD_WF8B_BPDLCD49_MASK)

#define LCD_WF8B_BPDLCD50_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD50_SHIFT                  (3U)
/*! BPDLCD50
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD50(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD50_SHIFT)) & LCD_WF8B_BPDLCD50_MASK)

#define LCD_WF8B_BPDLCD51_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD51_SHIFT                  (3U)
/*! BPDLCD51
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD51(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD51_SHIFT)) & LCD_WF8B_BPDLCD51_MASK)

#define LCD_WF8B_BPDLCD52_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD52_SHIFT                  (3U)
/*! BPDLCD52
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD52(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD52_SHIFT)) & LCD_WF8B_BPDLCD52_MASK)

#define LCD_WF8B_BPDLCD53_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD53_SHIFT                  (3U)
/*! BPDLCD53
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD53(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD53_SHIFT)) & LCD_WF8B_BPDLCD53_MASK)

#define LCD_WF8B_BPDLCD54_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD54_SHIFT                  (3U)
/*! BPDLCD54
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD54(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD54_SHIFT)) & LCD_WF8B_BPDLCD54_MASK)

#define LCD_WF8B_BPDLCD55_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD55_SHIFT                  (3U)
/*! BPDLCD55
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD55(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD55_SHIFT)) & LCD_WF8B_BPDLCD55_MASK)

#define LCD_WF8B_BPDLCD56_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD56_SHIFT                  (3U)
/*! BPDLCD56
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD56(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD56_SHIFT)) & LCD_WF8B_BPDLCD56_MASK)

#define LCD_WF8B_BPDLCD57_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD57_SHIFT                  (3U)
/*! BPDLCD57
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD57(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD57_SHIFT)) & LCD_WF8B_BPDLCD57_MASK)

#define LCD_WF8B_BPDLCD58_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD58_SHIFT                  (3U)
/*! BPDLCD58
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD58(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD58_SHIFT)) & LCD_WF8B_BPDLCD58_MASK)

#define LCD_WF8B_BPDLCD59_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD59_SHIFT                  (3U)
/*! BPDLCD59
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD59(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD59_SHIFT)) & LCD_WF8B_BPDLCD59_MASK)

#define LCD_WF8B_BPDLCD60_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD60_SHIFT                  (3U)
/*! BPDLCD60
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD60(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD60_SHIFT)) & LCD_WF8B_BPDLCD60_MASK)

#define LCD_WF8B_BPDLCD61_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD61_SHIFT                  (3U)
/*! BPDLCD61
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD61(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD61_SHIFT)) & LCD_WF8B_BPDLCD61_MASK)

#define LCD_WF8B_BPDLCD62_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD62_SHIFT                  (3U)
/*! BPDLCD62
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD62(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD62_SHIFT)) & LCD_WF8B_BPDLCD62_MASK)

#define LCD_WF8B_BPDLCD63_MASK                   (0x8U)
#define LCD_WF8B_BPDLCD63_SHIFT                  (3U)
/*! BPDLCD63
 *  0b0..LCD segment off or LCD backplane inactive for phase D
 *  0b1..LCD segment on or LCD backplane active for phase D
 */
#define LCD_WF8B_BPDLCD63(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPDLCD63_SHIFT)) & LCD_WF8B_BPDLCD63_MASK)

#define LCD_WF8B_BPELCD0_MASK                    (0x10U)
#define LCD_WF8B_BPELCD0_SHIFT                   (4U)
/*! BPELCD0
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD0(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD0_SHIFT)) & LCD_WF8B_BPELCD0_MASK)

#define LCD_WF8B_BPELCD1_MASK                    (0x10U)
#define LCD_WF8B_BPELCD1_SHIFT                   (4U)
/*! BPELCD1
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD1(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD1_SHIFT)) & LCD_WF8B_BPELCD1_MASK)

#define LCD_WF8B_BPELCD2_MASK                    (0x10U)
#define LCD_WF8B_BPELCD2_SHIFT                   (4U)
/*! BPELCD2
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD2(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD2_SHIFT)) & LCD_WF8B_BPELCD2_MASK)

#define LCD_WF8B_BPELCD3_MASK                    (0x10U)
#define LCD_WF8B_BPELCD3_SHIFT                   (4U)
/*! BPELCD3
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD3(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD3_SHIFT)) & LCD_WF8B_BPELCD3_MASK)

#define LCD_WF8B_BPELCD4_MASK                    (0x10U)
#define LCD_WF8B_BPELCD4_SHIFT                   (4U)
/*! BPELCD4
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD4(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD4_SHIFT)) & LCD_WF8B_BPELCD4_MASK)

#define LCD_WF8B_BPELCD5_MASK                    (0x10U)
#define LCD_WF8B_BPELCD5_SHIFT                   (4U)
/*! BPELCD5
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD5(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD5_SHIFT)) & LCD_WF8B_BPELCD5_MASK)

#define LCD_WF8B_BPELCD6_MASK                    (0x10U)
#define LCD_WF8B_BPELCD6_SHIFT                   (4U)
/*! BPELCD6
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD6(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD6_SHIFT)) & LCD_WF8B_BPELCD6_MASK)

#define LCD_WF8B_BPELCD7_MASK                    (0x10U)
#define LCD_WF8B_BPELCD7_SHIFT                   (4U)
/*! BPELCD7
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD7(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD7_SHIFT)) & LCD_WF8B_BPELCD7_MASK)

#define LCD_WF8B_BPELCD8_MASK                    (0x10U)
#define LCD_WF8B_BPELCD8_SHIFT                   (4U)
/*! BPELCD8
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD8(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD8_SHIFT)) & LCD_WF8B_BPELCD8_MASK)

#define LCD_WF8B_BPELCD9_MASK                    (0x10U)
#define LCD_WF8B_BPELCD9_SHIFT                   (4U)
/*! BPELCD9
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD9(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD9_SHIFT)) & LCD_WF8B_BPELCD9_MASK)

#define LCD_WF8B_BPELCD10_MASK                   (0x10U)
#define LCD_WF8B_BPELCD10_SHIFT                  (4U)
/*! BPELCD10
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD10(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD10_SHIFT)) & LCD_WF8B_BPELCD10_MASK)

#define LCD_WF8B_BPELCD11_MASK                   (0x10U)
#define LCD_WF8B_BPELCD11_SHIFT                  (4U)
/*! BPELCD11
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD11(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD11_SHIFT)) & LCD_WF8B_BPELCD11_MASK)

#define LCD_WF8B_BPELCD12_MASK                   (0x10U)
#define LCD_WF8B_BPELCD12_SHIFT                  (4U)
/*! BPELCD12
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD12(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD12_SHIFT)) & LCD_WF8B_BPELCD12_MASK)

#define LCD_WF8B_BPELCD13_MASK                   (0x10U)
#define LCD_WF8B_BPELCD13_SHIFT                  (4U)
/*! BPELCD13
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD13(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD13_SHIFT)) & LCD_WF8B_BPELCD13_MASK)

#define LCD_WF8B_BPELCD14_MASK                   (0x10U)
#define LCD_WF8B_BPELCD14_SHIFT                  (4U)
/*! BPELCD14
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD14(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD14_SHIFT)) & LCD_WF8B_BPELCD14_MASK)

#define LCD_WF8B_BPELCD15_MASK                   (0x10U)
#define LCD_WF8B_BPELCD15_SHIFT                  (4U)
/*! BPELCD15
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD15(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD15_SHIFT)) & LCD_WF8B_BPELCD15_MASK)

#define LCD_WF8B_BPELCD16_MASK                   (0x10U)
#define LCD_WF8B_BPELCD16_SHIFT                  (4U)
/*! BPELCD16
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD16(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD16_SHIFT)) & LCD_WF8B_BPELCD16_MASK)

#define LCD_WF8B_BPELCD17_MASK                   (0x10U)
#define LCD_WF8B_BPELCD17_SHIFT                  (4U)
/*! BPELCD17
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD17(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD17_SHIFT)) & LCD_WF8B_BPELCD17_MASK)

#define LCD_WF8B_BPELCD18_MASK                   (0x10U)
#define LCD_WF8B_BPELCD18_SHIFT                  (4U)
/*! BPELCD18
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD18(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD18_SHIFT)) & LCD_WF8B_BPELCD18_MASK)

#define LCD_WF8B_BPELCD19_MASK                   (0x10U)
#define LCD_WF8B_BPELCD19_SHIFT                  (4U)
/*! BPELCD19
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD19(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD19_SHIFT)) & LCD_WF8B_BPELCD19_MASK)

#define LCD_WF8B_BPELCD20_MASK                   (0x10U)
#define LCD_WF8B_BPELCD20_SHIFT                  (4U)
/*! BPELCD20
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD20(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD20_SHIFT)) & LCD_WF8B_BPELCD20_MASK)

#define LCD_WF8B_BPELCD21_MASK                   (0x10U)
#define LCD_WF8B_BPELCD21_SHIFT                  (4U)
/*! BPELCD21
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD21(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD21_SHIFT)) & LCD_WF8B_BPELCD21_MASK)

#define LCD_WF8B_BPELCD22_MASK                   (0x10U)
#define LCD_WF8B_BPELCD22_SHIFT                  (4U)
/*! BPELCD22
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD22(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD22_SHIFT)) & LCD_WF8B_BPELCD22_MASK)

#define LCD_WF8B_BPELCD23_MASK                   (0x10U)
#define LCD_WF8B_BPELCD23_SHIFT                  (4U)
/*! BPELCD23
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD23(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD23_SHIFT)) & LCD_WF8B_BPELCD23_MASK)

#define LCD_WF8B_BPELCD24_MASK                   (0x10U)
#define LCD_WF8B_BPELCD24_SHIFT                  (4U)
/*! BPELCD24
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD24(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD24_SHIFT)) & LCD_WF8B_BPELCD24_MASK)

#define LCD_WF8B_BPELCD25_MASK                   (0x10U)
#define LCD_WF8B_BPELCD25_SHIFT                  (4U)
/*! BPELCD25
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD25(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD25_SHIFT)) & LCD_WF8B_BPELCD25_MASK)

#define LCD_WF8B_BPELCD26_MASK                   (0x10U)
#define LCD_WF8B_BPELCD26_SHIFT                  (4U)
/*! BPELCD26
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD26(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD26_SHIFT)) & LCD_WF8B_BPELCD26_MASK)

#define LCD_WF8B_BPELCD27_MASK                   (0x10U)
#define LCD_WF8B_BPELCD27_SHIFT                  (4U)
/*! BPELCD27
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD27(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD27_SHIFT)) & LCD_WF8B_BPELCD27_MASK)

#define LCD_WF8B_BPELCD28_MASK                   (0x10U)
#define LCD_WF8B_BPELCD28_SHIFT                  (4U)
/*! BPELCD28
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD28(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD28_SHIFT)) & LCD_WF8B_BPELCD28_MASK)

#define LCD_WF8B_BPELCD29_MASK                   (0x10U)
#define LCD_WF8B_BPELCD29_SHIFT                  (4U)
/*! BPELCD29
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD29(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD29_SHIFT)) & LCD_WF8B_BPELCD29_MASK)

#define LCD_WF8B_BPELCD30_MASK                   (0x10U)
#define LCD_WF8B_BPELCD30_SHIFT                  (4U)
/*! BPELCD30
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD30(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD30_SHIFT)) & LCD_WF8B_BPELCD30_MASK)

#define LCD_WF8B_BPELCD31_MASK                   (0x10U)
#define LCD_WF8B_BPELCD31_SHIFT                  (4U)
/*! BPELCD31
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD31(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD31_SHIFT)) & LCD_WF8B_BPELCD31_MASK)

#define LCD_WF8B_BPELCD32_MASK                   (0x10U)
#define LCD_WF8B_BPELCD32_SHIFT                  (4U)
/*! BPELCD32
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD32(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD32_SHIFT)) & LCD_WF8B_BPELCD32_MASK)

#define LCD_WF8B_BPELCD33_MASK                   (0x10U)
#define LCD_WF8B_BPELCD33_SHIFT                  (4U)
/*! BPELCD33
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD33(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD33_SHIFT)) & LCD_WF8B_BPELCD33_MASK)

#define LCD_WF8B_BPELCD34_MASK                   (0x10U)
#define LCD_WF8B_BPELCD34_SHIFT                  (4U)
/*! BPELCD34
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD34(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD34_SHIFT)) & LCD_WF8B_BPELCD34_MASK)

#define LCD_WF8B_BPELCD35_MASK                   (0x10U)
#define LCD_WF8B_BPELCD35_SHIFT                  (4U)
/*! BPELCD35
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD35(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD35_SHIFT)) & LCD_WF8B_BPELCD35_MASK)

#define LCD_WF8B_BPELCD36_MASK                   (0x10U)
#define LCD_WF8B_BPELCD36_SHIFT                  (4U)
/*! BPELCD36
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD36(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD36_SHIFT)) & LCD_WF8B_BPELCD36_MASK)

#define LCD_WF8B_BPELCD37_MASK                   (0x10U)
#define LCD_WF8B_BPELCD37_SHIFT                  (4U)
/*! BPELCD37
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD37(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD37_SHIFT)) & LCD_WF8B_BPELCD37_MASK)

#define LCD_WF8B_BPELCD38_MASK                   (0x10U)
#define LCD_WF8B_BPELCD38_SHIFT                  (4U)
/*! BPELCD38
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD38(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD38_SHIFT)) & LCD_WF8B_BPELCD38_MASK)

#define LCD_WF8B_BPELCD39_MASK                   (0x10U)
#define LCD_WF8B_BPELCD39_SHIFT                  (4U)
/*! BPELCD39
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD39(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD39_SHIFT)) & LCD_WF8B_BPELCD39_MASK)

#define LCD_WF8B_BPELCD40_MASK                   (0x10U)
#define LCD_WF8B_BPELCD40_SHIFT                  (4U)
/*! BPELCD40
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD40(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD40_SHIFT)) & LCD_WF8B_BPELCD40_MASK)

#define LCD_WF8B_BPELCD41_MASK                   (0x10U)
#define LCD_WF8B_BPELCD41_SHIFT                  (4U)
/*! BPELCD41
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD41(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD41_SHIFT)) & LCD_WF8B_BPELCD41_MASK)

#define LCD_WF8B_BPELCD42_MASK                   (0x10U)
#define LCD_WF8B_BPELCD42_SHIFT                  (4U)
/*! BPELCD42
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD42(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD42_SHIFT)) & LCD_WF8B_BPELCD42_MASK)

#define LCD_WF8B_BPELCD43_MASK                   (0x10U)
#define LCD_WF8B_BPELCD43_SHIFT                  (4U)
/*! BPELCD43
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD43(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD43_SHIFT)) & LCD_WF8B_BPELCD43_MASK)

#define LCD_WF8B_BPELCD44_MASK                   (0x10U)
#define LCD_WF8B_BPELCD44_SHIFT                  (4U)
/*! BPELCD44
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD44(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD44_SHIFT)) & LCD_WF8B_BPELCD44_MASK)

#define LCD_WF8B_BPELCD45_MASK                   (0x10U)
#define LCD_WF8B_BPELCD45_SHIFT                  (4U)
/*! BPELCD45
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD45(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD45_SHIFT)) & LCD_WF8B_BPELCD45_MASK)

#define LCD_WF8B_BPELCD46_MASK                   (0x10U)
#define LCD_WF8B_BPELCD46_SHIFT                  (4U)
/*! BPELCD46
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD46(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD46_SHIFT)) & LCD_WF8B_BPELCD46_MASK)

#define LCD_WF8B_BPELCD47_MASK                   (0x10U)
#define LCD_WF8B_BPELCD47_SHIFT                  (4U)
/*! BPELCD47
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD47(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD47_SHIFT)) & LCD_WF8B_BPELCD47_MASK)

#define LCD_WF8B_BPELCD48_MASK                   (0x10U)
#define LCD_WF8B_BPELCD48_SHIFT                  (4U)
/*! BPELCD48
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD48(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD48_SHIFT)) & LCD_WF8B_BPELCD48_MASK)

#define LCD_WF8B_BPELCD49_MASK                   (0x10U)
#define LCD_WF8B_BPELCD49_SHIFT                  (4U)
/*! BPELCD49
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD49(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD49_SHIFT)) & LCD_WF8B_BPELCD49_MASK)

#define LCD_WF8B_BPELCD50_MASK                   (0x10U)
#define LCD_WF8B_BPELCD50_SHIFT                  (4U)
/*! BPELCD50
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD50(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD50_SHIFT)) & LCD_WF8B_BPELCD50_MASK)

#define LCD_WF8B_BPELCD51_MASK                   (0x10U)
#define LCD_WF8B_BPELCD51_SHIFT                  (4U)
/*! BPELCD51
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD51(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD51_SHIFT)) & LCD_WF8B_BPELCD51_MASK)

#define LCD_WF8B_BPELCD52_MASK                   (0x10U)
#define LCD_WF8B_BPELCD52_SHIFT                  (4U)
/*! BPELCD52
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD52(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD52_SHIFT)) & LCD_WF8B_BPELCD52_MASK)

#define LCD_WF8B_BPELCD53_MASK                   (0x10U)
#define LCD_WF8B_BPELCD53_SHIFT                  (4U)
/*! BPELCD53
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD53(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD53_SHIFT)) & LCD_WF8B_BPELCD53_MASK)

#define LCD_WF8B_BPELCD54_MASK                   (0x10U)
#define LCD_WF8B_BPELCD54_SHIFT                  (4U)
/*! BPELCD54
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD54(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD54_SHIFT)) & LCD_WF8B_BPELCD54_MASK)

#define LCD_WF8B_BPELCD55_MASK                   (0x10U)
#define LCD_WF8B_BPELCD55_SHIFT                  (4U)
/*! BPELCD55
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD55(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD55_SHIFT)) & LCD_WF8B_BPELCD55_MASK)

#define LCD_WF8B_BPELCD56_MASK                   (0x10U)
#define LCD_WF8B_BPELCD56_SHIFT                  (4U)
/*! BPELCD56
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD56(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD56_SHIFT)) & LCD_WF8B_BPELCD56_MASK)

#define LCD_WF8B_BPELCD57_MASK                   (0x10U)
#define LCD_WF8B_BPELCD57_SHIFT                  (4U)
/*! BPELCD57
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD57(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD57_SHIFT)) & LCD_WF8B_BPELCD57_MASK)

#define LCD_WF8B_BPELCD58_MASK                   (0x10U)
#define LCD_WF8B_BPELCD58_SHIFT                  (4U)
/*! BPELCD58
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD58(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD58_SHIFT)) & LCD_WF8B_BPELCD58_MASK)

#define LCD_WF8B_BPELCD59_MASK                   (0x10U)
#define LCD_WF8B_BPELCD59_SHIFT                  (4U)
/*! BPELCD59
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD59(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD59_SHIFT)) & LCD_WF8B_BPELCD59_MASK)

#define LCD_WF8B_BPELCD60_MASK                   (0x10U)
#define LCD_WF8B_BPELCD60_SHIFT                  (4U)
/*! BPELCD60
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD60(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD60_SHIFT)) & LCD_WF8B_BPELCD60_MASK)

#define LCD_WF8B_BPELCD61_MASK                   (0x10U)
#define LCD_WF8B_BPELCD61_SHIFT                  (4U)
/*! BPELCD61
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD61(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD61_SHIFT)) & LCD_WF8B_BPELCD61_MASK)

#define LCD_WF8B_BPELCD62_MASK                   (0x10U)
#define LCD_WF8B_BPELCD62_SHIFT                  (4U)
/*! BPELCD62
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD62(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD62_SHIFT)) & LCD_WF8B_BPELCD62_MASK)

#define LCD_WF8B_BPELCD63_MASK                   (0x10U)
#define LCD_WF8B_BPELCD63_SHIFT                  (4U)
/*! BPELCD63
 *  0b0..LCD segment off or LCD backplane inactive for phase E
 *  0b1..LCD segment on or LCD backplane active for phase E
 */
#define LCD_WF8B_BPELCD63(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPELCD63_SHIFT)) & LCD_WF8B_BPELCD63_MASK)

#define LCD_WF8B_BPFLCD0_MASK                    (0x20U)
#define LCD_WF8B_BPFLCD0_SHIFT                   (5U)
/*! BPFLCD0
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD0(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD0_SHIFT)) & LCD_WF8B_BPFLCD0_MASK)

#define LCD_WF8B_BPFLCD1_MASK                    (0x20U)
#define LCD_WF8B_BPFLCD1_SHIFT                   (5U)
/*! BPFLCD1
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD1(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD1_SHIFT)) & LCD_WF8B_BPFLCD1_MASK)

#define LCD_WF8B_BPFLCD2_MASK                    (0x20U)
#define LCD_WF8B_BPFLCD2_SHIFT                   (5U)
/*! BPFLCD2
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD2(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD2_SHIFT)) & LCD_WF8B_BPFLCD2_MASK)

#define LCD_WF8B_BPFLCD3_MASK                    (0x20U)
#define LCD_WF8B_BPFLCD3_SHIFT                   (5U)
/*! BPFLCD3
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD3(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD3_SHIFT)) & LCD_WF8B_BPFLCD3_MASK)

#define LCD_WF8B_BPFLCD4_MASK                    (0x20U)
#define LCD_WF8B_BPFLCD4_SHIFT                   (5U)
/*! BPFLCD4
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD4(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD4_SHIFT)) & LCD_WF8B_BPFLCD4_MASK)

#define LCD_WF8B_BPFLCD5_MASK                    (0x20U)
#define LCD_WF8B_BPFLCD5_SHIFT                   (5U)
/*! BPFLCD5
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD5(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD5_SHIFT)) & LCD_WF8B_BPFLCD5_MASK)

#define LCD_WF8B_BPFLCD6_MASK                    (0x20U)
#define LCD_WF8B_BPFLCD6_SHIFT                   (5U)
/*! BPFLCD6
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD6(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD6_SHIFT)) & LCD_WF8B_BPFLCD6_MASK)

#define LCD_WF8B_BPFLCD7_MASK                    (0x20U)
#define LCD_WF8B_BPFLCD7_SHIFT                   (5U)
/*! BPFLCD7
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD7(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD7_SHIFT)) & LCD_WF8B_BPFLCD7_MASK)

#define LCD_WF8B_BPFLCD8_MASK                    (0x20U)
#define LCD_WF8B_BPFLCD8_SHIFT                   (5U)
/*! BPFLCD8
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD8(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD8_SHIFT)) & LCD_WF8B_BPFLCD8_MASK)

#define LCD_WF8B_BPFLCD9_MASK                    (0x20U)
#define LCD_WF8B_BPFLCD9_SHIFT                   (5U)
/*! BPFLCD9
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD9(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD9_SHIFT)) & LCD_WF8B_BPFLCD9_MASK)

#define LCD_WF8B_BPFLCD10_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD10_SHIFT                  (5U)
/*! BPFLCD10
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD10(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD10_SHIFT)) & LCD_WF8B_BPFLCD10_MASK)

#define LCD_WF8B_BPFLCD11_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD11_SHIFT                  (5U)
/*! BPFLCD11
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD11(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD11_SHIFT)) & LCD_WF8B_BPFLCD11_MASK)

#define LCD_WF8B_BPFLCD12_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD12_SHIFT                  (5U)
/*! BPFLCD12
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD12(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD12_SHIFT)) & LCD_WF8B_BPFLCD12_MASK)

#define LCD_WF8B_BPFLCD13_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD13_SHIFT                  (5U)
/*! BPFLCD13
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD13(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD13_SHIFT)) & LCD_WF8B_BPFLCD13_MASK)

#define LCD_WF8B_BPFLCD14_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD14_SHIFT                  (5U)
/*! BPFLCD14
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD14(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD14_SHIFT)) & LCD_WF8B_BPFLCD14_MASK)

#define LCD_WF8B_BPFLCD15_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD15_SHIFT                  (5U)
/*! BPFLCD15
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD15(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD15_SHIFT)) & LCD_WF8B_BPFLCD15_MASK)

#define LCD_WF8B_BPFLCD16_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD16_SHIFT                  (5U)
/*! BPFLCD16
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD16(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD16_SHIFT)) & LCD_WF8B_BPFLCD16_MASK)

#define LCD_WF8B_BPFLCD17_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD17_SHIFT                  (5U)
/*! BPFLCD17
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD17(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD17_SHIFT)) & LCD_WF8B_BPFLCD17_MASK)

#define LCD_WF8B_BPFLCD18_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD18_SHIFT                  (5U)
/*! BPFLCD18
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD18(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD18_SHIFT)) & LCD_WF8B_BPFLCD18_MASK)

#define LCD_WF8B_BPFLCD19_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD19_SHIFT                  (5U)
/*! BPFLCD19
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD19(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD19_SHIFT)) & LCD_WF8B_BPFLCD19_MASK)

#define LCD_WF8B_BPFLCD20_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD20_SHIFT                  (5U)
/*! BPFLCD20
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD20(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD20_SHIFT)) & LCD_WF8B_BPFLCD20_MASK)

#define LCD_WF8B_BPFLCD21_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD21_SHIFT                  (5U)
/*! BPFLCD21
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD21(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD21_SHIFT)) & LCD_WF8B_BPFLCD21_MASK)

#define LCD_WF8B_BPFLCD22_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD22_SHIFT                  (5U)
/*! BPFLCD22
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD22(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD22_SHIFT)) & LCD_WF8B_BPFLCD22_MASK)

#define LCD_WF8B_BPFLCD23_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD23_SHIFT                  (5U)
/*! BPFLCD23
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD23(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD23_SHIFT)) & LCD_WF8B_BPFLCD23_MASK)

#define LCD_WF8B_BPFLCD24_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD24_SHIFT                  (5U)
/*! BPFLCD24
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD24(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD24_SHIFT)) & LCD_WF8B_BPFLCD24_MASK)

#define LCD_WF8B_BPFLCD25_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD25_SHIFT                  (5U)
/*! BPFLCD25
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD25(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD25_SHIFT)) & LCD_WF8B_BPFLCD25_MASK)

#define LCD_WF8B_BPFLCD26_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD26_SHIFT                  (5U)
/*! BPFLCD26
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD26(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD26_SHIFT)) & LCD_WF8B_BPFLCD26_MASK)

#define LCD_WF8B_BPFLCD27_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD27_SHIFT                  (5U)
/*! BPFLCD27
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD27(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD27_SHIFT)) & LCD_WF8B_BPFLCD27_MASK)

#define LCD_WF8B_BPFLCD28_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD28_SHIFT                  (5U)
/*! BPFLCD28
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD28(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD28_SHIFT)) & LCD_WF8B_BPFLCD28_MASK)

#define LCD_WF8B_BPFLCD29_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD29_SHIFT                  (5U)
/*! BPFLCD29
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD29(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD29_SHIFT)) & LCD_WF8B_BPFLCD29_MASK)

#define LCD_WF8B_BPFLCD30_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD30_SHIFT                  (5U)
/*! BPFLCD30
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD30(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD30_SHIFT)) & LCD_WF8B_BPFLCD30_MASK)

#define LCD_WF8B_BPFLCD31_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD31_SHIFT                  (5U)
/*! BPFLCD31
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD31(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD31_SHIFT)) & LCD_WF8B_BPFLCD31_MASK)

#define LCD_WF8B_BPFLCD32_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD32_SHIFT                  (5U)
/*! BPFLCD32
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD32(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD32_SHIFT)) & LCD_WF8B_BPFLCD32_MASK)

#define LCD_WF8B_BPFLCD33_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD33_SHIFT                  (5U)
/*! BPFLCD33
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD33(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD33_SHIFT)) & LCD_WF8B_BPFLCD33_MASK)

#define LCD_WF8B_BPFLCD34_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD34_SHIFT                  (5U)
/*! BPFLCD34
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD34(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD34_SHIFT)) & LCD_WF8B_BPFLCD34_MASK)

#define LCD_WF8B_BPFLCD35_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD35_SHIFT                  (5U)
/*! BPFLCD35
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD35(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD35_SHIFT)) & LCD_WF8B_BPFLCD35_MASK)

#define LCD_WF8B_BPFLCD36_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD36_SHIFT                  (5U)
/*! BPFLCD36
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD36(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD36_SHIFT)) & LCD_WF8B_BPFLCD36_MASK)

#define LCD_WF8B_BPFLCD37_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD37_SHIFT                  (5U)
/*! BPFLCD37
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD37(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD37_SHIFT)) & LCD_WF8B_BPFLCD37_MASK)

#define LCD_WF8B_BPFLCD38_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD38_SHIFT                  (5U)
/*! BPFLCD38
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD38(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD38_SHIFT)) & LCD_WF8B_BPFLCD38_MASK)

#define LCD_WF8B_BPFLCD39_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD39_SHIFT                  (5U)
/*! BPFLCD39
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD39(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD39_SHIFT)) & LCD_WF8B_BPFLCD39_MASK)

#define LCD_WF8B_BPFLCD40_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD40_SHIFT                  (5U)
/*! BPFLCD40
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD40(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD40_SHIFT)) & LCD_WF8B_BPFLCD40_MASK)

#define LCD_WF8B_BPFLCD41_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD41_SHIFT                  (5U)
/*! BPFLCD41
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD41(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD41_SHIFT)) & LCD_WF8B_BPFLCD41_MASK)

#define LCD_WF8B_BPFLCD42_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD42_SHIFT                  (5U)
/*! BPFLCD42
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD42(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD42_SHIFT)) & LCD_WF8B_BPFLCD42_MASK)

#define LCD_WF8B_BPFLCD43_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD43_SHIFT                  (5U)
/*! BPFLCD43
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD43(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD43_SHIFT)) & LCD_WF8B_BPFLCD43_MASK)

#define LCD_WF8B_BPFLCD44_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD44_SHIFT                  (5U)
/*! BPFLCD44
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD44(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD44_SHIFT)) & LCD_WF8B_BPFLCD44_MASK)

#define LCD_WF8B_BPFLCD45_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD45_SHIFT                  (5U)
/*! BPFLCD45
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD45(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD45_SHIFT)) & LCD_WF8B_BPFLCD45_MASK)

#define LCD_WF8B_BPFLCD46_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD46_SHIFT                  (5U)
/*! BPFLCD46
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD46(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD46_SHIFT)) & LCD_WF8B_BPFLCD46_MASK)

#define LCD_WF8B_BPFLCD47_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD47_SHIFT                  (5U)
/*! BPFLCD47
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD47(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD47_SHIFT)) & LCD_WF8B_BPFLCD47_MASK)

#define LCD_WF8B_BPFLCD48_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD48_SHIFT                  (5U)
/*! BPFLCD48
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD48(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD48_SHIFT)) & LCD_WF8B_BPFLCD48_MASK)

#define LCD_WF8B_BPFLCD49_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD49_SHIFT                  (5U)
/*! BPFLCD49
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD49(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD49_SHIFT)) & LCD_WF8B_BPFLCD49_MASK)

#define LCD_WF8B_BPFLCD50_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD50_SHIFT                  (5U)
/*! BPFLCD50
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD50(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD50_SHIFT)) & LCD_WF8B_BPFLCD50_MASK)

#define LCD_WF8B_BPFLCD51_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD51_SHIFT                  (5U)
/*! BPFLCD51
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD51(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD51_SHIFT)) & LCD_WF8B_BPFLCD51_MASK)

#define LCD_WF8B_BPFLCD52_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD52_SHIFT                  (5U)
/*! BPFLCD52
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD52(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD52_SHIFT)) & LCD_WF8B_BPFLCD52_MASK)

#define LCD_WF8B_BPFLCD53_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD53_SHIFT                  (5U)
/*! BPFLCD53
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD53(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD53_SHIFT)) & LCD_WF8B_BPFLCD53_MASK)

#define LCD_WF8B_BPFLCD54_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD54_SHIFT                  (5U)
/*! BPFLCD54
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD54(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD54_SHIFT)) & LCD_WF8B_BPFLCD54_MASK)

#define LCD_WF8B_BPFLCD55_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD55_SHIFT                  (5U)
/*! BPFLCD55
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD55(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD55_SHIFT)) & LCD_WF8B_BPFLCD55_MASK)

#define LCD_WF8B_BPFLCD56_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD56_SHIFT                  (5U)
/*! BPFLCD56
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD56(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD56_SHIFT)) & LCD_WF8B_BPFLCD56_MASK)

#define LCD_WF8B_BPFLCD57_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD57_SHIFT                  (5U)
/*! BPFLCD57
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD57(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD57_SHIFT)) & LCD_WF8B_BPFLCD57_MASK)

#define LCD_WF8B_BPFLCD58_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD58_SHIFT                  (5U)
/*! BPFLCD58
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD58(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD58_SHIFT)) & LCD_WF8B_BPFLCD58_MASK)

#define LCD_WF8B_BPFLCD59_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD59_SHIFT                  (5U)
/*! BPFLCD59
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD59(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD59_SHIFT)) & LCD_WF8B_BPFLCD59_MASK)

#define LCD_WF8B_BPFLCD60_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD60_SHIFT                  (5U)
/*! BPFLCD60
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD60(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD60_SHIFT)) & LCD_WF8B_BPFLCD60_MASK)

#define LCD_WF8B_BPFLCD61_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD61_SHIFT                  (5U)
/*! BPFLCD61
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD61(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD61_SHIFT)) & LCD_WF8B_BPFLCD61_MASK)

#define LCD_WF8B_BPFLCD62_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD62_SHIFT                  (5U)
/*! BPFLCD62
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD62(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD62_SHIFT)) & LCD_WF8B_BPFLCD62_MASK)

#define LCD_WF8B_BPFLCD63_MASK                   (0x20U)
#define LCD_WF8B_BPFLCD63_SHIFT                  (5U)
/*! BPFLCD63
 *  0b0..LCD segment off or LCD backplane inactive for phase F
 *  0b1..LCD segment on or LCD backplane active for phase F
 */
#define LCD_WF8B_BPFLCD63(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPFLCD63_SHIFT)) & LCD_WF8B_BPFLCD63_MASK)

#define LCD_WF8B_BPGLCD0_MASK                    (0x40U)
#define LCD_WF8B_BPGLCD0_SHIFT                   (6U)
/*! BPGLCD0
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD0(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD0_SHIFT)) & LCD_WF8B_BPGLCD0_MASK)

#define LCD_WF8B_BPGLCD1_MASK                    (0x40U)
#define LCD_WF8B_BPGLCD1_SHIFT                   (6U)
/*! BPGLCD1
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD1(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD1_SHIFT)) & LCD_WF8B_BPGLCD1_MASK)

#define LCD_WF8B_BPGLCD2_MASK                    (0x40U)
#define LCD_WF8B_BPGLCD2_SHIFT                   (6U)
/*! BPGLCD2
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD2(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD2_SHIFT)) & LCD_WF8B_BPGLCD2_MASK)

#define LCD_WF8B_BPGLCD3_MASK                    (0x40U)
#define LCD_WF8B_BPGLCD3_SHIFT                   (6U)
/*! BPGLCD3
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD3(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD3_SHIFT)) & LCD_WF8B_BPGLCD3_MASK)

#define LCD_WF8B_BPGLCD4_MASK                    (0x40U)
#define LCD_WF8B_BPGLCD4_SHIFT                   (6U)
/*! BPGLCD4
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD4(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD4_SHIFT)) & LCD_WF8B_BPGLCD4_MASK)

#define LCD_WF8B_BPGLCD5_MASK                    (0x40U)
#define LCD_WF8B_BPGLCD5_SHIFT                   (6U)
/*! BPGLCD5
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD5(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD5_SHIFT)) & LCD_WF8B_BPGLCD5_MASK)

#define LCD_WF8B_BPGLCD6_MASK                    (0x40U)
#define LCD_WF8B_BPGLCD6_SHIFT                   (6U)
/*! BPGLCD6
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD6(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD6_SHIFT)) & LCD_WF8B_BPGLCD6_MASK)

#define LCD_WF8B_BPGLCD7_MASK                    (0x40U)
#define LCD_WF8B_BPGLCD7_SHIFT                   (6U)
/*! BPGLCD7
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD7(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD7_SHIFT)) & LCD_WF8B_BPGLCD7_MASK)

#define LCD_WF8B_BPGLCD8_MASK                    (0x40U)
#define LCD_WF8B_BPGLCD8_SHIFT                   (6U)
/*! BPGLCD8
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD8(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD8_SHIFT)) & LCD_WF8B_BPGLCD8_MASK)

#define LCD_WF8B_BPGLCD9_MASK                    (0x40U)
#define LCD_WF8B_BPGLCD9_SHIFT                   (6U)
/*! BPGLCD9
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD9(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD9_SHIFT)) & LCD_WF8B_BPGLCD9_MASK)

#define LCD_WF8B_BPGLCD10_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD10_SHIFT                  (6U)
/*! BPGLCD10
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD10(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD10_SHIFT)) & LCD_WF8B_BPGLCD10_MASK)

#define LCD_WF8B_BPGLCD11_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD11_SHIFT                  (6U)
/*! BPGLCD11
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD11(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD11_SHIFT)) & LCD_WF8B_BPGLCD11_MASK)

#define LCD_WF8B_BPGLCD12_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD12_SHIFT                  (6U)
/*! BPGLCD12
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD12(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD12_SHIFT)) & LCD_WF8B_BPGLCD12_MASK)

#define LCD_WF8B_BPGLCD13_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD13_SHIFT                  (6U)
/*! BPGLCD13
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD13(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD13_SHIFT)) & LCD_WF8B_BPGLCD13_MASK)

#define LCD_WF8B_BPGLCD14_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD14_SHIFT                  (6U)
/*! BPGLCD14
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD14(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD14_SHIFT)) & LCD_WF8B_BPGLCD14_MASK)

#define LCD_WF8B_BPGLCD15_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD15_SHIFT                  (6U)
/*! BPGLCD15
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD15(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD15_SHIFT)) & LCD_WF8B_BPGLCD15_MASK)

#define LCD_WF8B_BPGLCD16_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD16_SHIFT                  (6U)
/*! BPGLCD16
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD16(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD16_SHIFT)) & LCD_WF8B_BPGLCD16_MASK)

#define LCD_WF8B_BPGLCD17_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD17_SHIFT                  (6U)
/*! BPGLCD17
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD17(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD17_SHIFT)) & LCD_WF8B_BPGLCD17_MASK)

#define LCD_WF8B_BPGLCD18_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD18_SHIFT                  (6U)
/*! BPGLCD18
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD18(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD18_SHIFT)) & LCD_WF8B_BPGLCD18_MASK)

#define LCD_WF8B_BPGLCD19_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD19_SHIFT                  (6U)
/*! BPGLCD19
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD19(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD19_SHIFT)) & LCD_WF8B_BPGLCD19_MASK)

#define LCD_WF8B_BPGLCD20_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD20_SHIFT                  (6U)
/*! BPGLCD20
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD20(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD20_SHIFT)) & LCD_WF8B_BPGLCD20_MASK)

#define LCD_WF8B_BPGLCD21_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD21_SHIFT                  (6U)
/*! BPGLCD21
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD21(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD21_SHIFT)) & LCD_WF8B_BPGLCD21_MASK)

#define LCD_WF8B_BPGLCD22_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD22_SHIFT                  (6U)
/*! BPGLCD22
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD22(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD22_SHIFT)) & LCD_WF8B_BPGLCD22_MASK)

#define LCD_WF8B_BPGLCD23_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD23_SHIFT                  (6U)
/*! BPGLCD23
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD23(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD23_SHIFT)) & LCD_WF8B_BPGLCD23_MASK)

#define LCD_WF8B_BPGLCD24_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD24_SHIFT                  (6U)
/*! BPGLCD24
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD24(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD24_SHIFT)) & LCD_WF8B_BPGLCD24_MASK)

#define LCD_WF8B_BPGLCD25_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD25_SHIFT                  (6U)
/*! BPGLCD25
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD25(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD25_SHIFT)) & LCD_WF8B_BPGLCD25_MASK)

#define LCD_WF8B_BPGLCD26_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD26_SHIFT                  (6U)
/*! BPGLCD26
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD26(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD26_SHIFT)) & LCD_WF8B_BPGLCD26_MASK)

#define LCD_WF8B_BPGLCD27_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD27_SHIFT                  (6U)
/*! BPGLCD27
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD27(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD27_SHIFT)) & LCD_WF8B_BPGLCD27_MASK)

#define LCD_WF8B_BPGLCD28_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD28_SHIFT                  (6U)
/*! BPGLCD28
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD28(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD28_SHIFT)) & LCD_WF8B_BPGLCD28_MASK)

#define LCD_WF8B_BPGLCD29_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD29_SHIFT                  (6U)
/*! BPGLCD29
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD29(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD29_SHIFT)) & LCD_WF8B_BPGLCD29_MASK)

#define LCD_WF8B_BPGLCD30_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD30_SHIFT                  (6U)
/*! BPGLCD30
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD30(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD30_SHIFT)) & LCD_WF8B_BPGLCD30_MASK)

#define LCD_WF8B_BPGLCD31_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD31_SHIFT                  (6U)
/*! BPGLCD31
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD31(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD31_SHIFT)) & LCD_WF8B_BPGLCD31_MASK)

#define LCD_WF8B_BPGLCD32_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD32_SHIFT                  (6U)
/*! BPGLCD32
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD32(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD32_SHIFT)) & LCD_WF8B_BPGLCD32_MASK)

#define LCD_WF8B_BPGLCD33_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD33_SHIFT                  (6U)
/*! BPGLCD33
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD33(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD33_SHIFT)) & LCD_WF8B_BPGLCD33_MASK)

#define LCD_WF8B_BPGLCD34_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD34_SHIFT                  (6U)
/*! BPGLCD34
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD34(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD34_SHIFT)) & LCD_WF8B_BPGLCD34_MASK)

#define LCD_WF8B_BPGLCD35_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD35_SHIFT                  (6U)
/*! BPGLCD35
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD35(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD35_SHIFT)) & LCD_WF8B_BPGLCD35_MASK)

#define LCD_WF8B_BPGLCD36_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD36_SHIFT                  (6U)
/*! BPGLCD36
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD36(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD36_SHIFT)) & LCD_WF8B_BPGLCD36_MASK)

#define LCD_WF8B_BPGLCD37_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD37_SHIFT                  (6U)
/*! BPGLCD37
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD37(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD37_SHIFT)) & LCD_WF8B_BPGLCD37_MASK)

#define LCD_WF8B_BPGLCD38_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD38_SHIFT                  (6U)
/*! BPGLCD38
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD38(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD38_SHIFT)) & LCD_WF8B_BPGLCD38_MASK)

#define LCD_WF8B_BPGLCD39_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD39_SHIFT                  (6U)
/*! BPGLCD39
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD39(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD39_SHIFT)) & LCD_WF8B_BPGLCD39_MASK)

#define LCD_WF8B_BPGLCD40_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD40_SHIFT                  (6U)
/*! BPGLCD40
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD40(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD40_SHIFT)) & LCD_WF8B_BPGLCD40_MASK)

#define LCD_WF8B_BPGLCD41_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD41_SHIFT                  (6U)
/*! BPGLCD41
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD41(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD41_SHIFT)) & LCD_WF8B_BPGLCD41_MASK)

#define LCD_WF8B_BPGLCD42_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD42_SHIFT                  (6U)
/*! BPGLCD42
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD42(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD42_SHIFT)) & LCD_WF8B_BPGLCD42_MASK)

#define LCD_WF8B_BPGLCD43_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD43_SHIFT                  (6U)
/*! BPGLCD43
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD43(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD43_SHIFT)) & LCD_WF8B_BPGLCD43_MASK)

#define LCD_WF8B_BPGLCD44_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD44_SHIFT                  (6U)
/*! BPGLCD44
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD44(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD44_SHIFT)) & LCD_WF8B_BPGLCD44_MASK)

#define LCD_WF8B_BPGLCD45_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD45_SHIFT                  (6U)
/*! BPGLCD45
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD45(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD45_SHIFT)) & LCD_WF8B_BPGLCD45_MASK)

#define LCD_WF8B_BPGLCD46_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD46_SHIFT                  (6U)
/*! BPGLCD46
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD46(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD46_SHIFT)) & LCD_WF8B_BPGLCD46_MASK)

#define LCD_WF8B_BPGLCD47_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD47_SHIFT                  (6U)
/*! BPGLCD47
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD47(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD47_SHIFT)) & LCD_WF8B_BPGLCD47_MASK)

#define LCD_WF8B_BPGLCD48_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD48_SHIFT                  (6U)
/*! BPGLCD48
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD48(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD48_SHIFT)) & LCD_WF8B_BPGLCD48_MASK)

#define LCD_WF8B_BPGLCD49_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD49_SHIFT                  (6U)
/*! BPGLCD49
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD49(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD49_SHIFT)) & LCD_WF8B_BPGLCD49_MASK)

#define LCD_WF8B_BPGLCD50_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD50_SHIFT                  (6U)
/*! BPGLCD50
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD50(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD50_SHIFT)) & LCD_WF8B_BPGLCD50_MASK)

#define LCD_WF8B_BPGLCD51_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD51_SHIFT                  (6U)
/*! BPGLCD51
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD51(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD51_SHIFT)) & LCD_WF8B_BPGLCD51_MASK)

#define LCD_WF8B_BPGLCD52_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD52_SHIFT                  (6U)
/*! BPGLCD52
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD52(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD52_SHIFT)) & LCD_WF8B_BPGLCD52_MASK)

#define LCD_WF8B_BPGLCD53_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD53_SHIFT                  (6U)
/*! BPGLCD53
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD53(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD53_SHIFT)) & LCD_WF8B_BPGLCD53_MASK)

#define LCD_WF8B_BPGLCD54_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD54_SHIFT                  (6U)
/*! BPGLCD54
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD54(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD54_SHIFT)) & LCD_WF8B_BPGLCD54_MASK)

#define LCD_WF8B_BPGLCD55_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD55_SHIFT                  (6U)
/*! BPGLCD55
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD55(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD55_SHIFT)) & LCD_WF8B_BPGLCD55_MASK)

#define LCD_WF8B_BPGLCD56_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD56_SHIFT                  (6U)
/*! BPGLCD56
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD56(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD56_SHIFT)) & LCD_WF8B_BPGLCD56_MASK)

#define LCD_WF8B_BPGLCD57_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD57_SHIFT                  (6U)
/*! BPGLCD57
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD57(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD57_SHIFT)) & LCD_WF8B_BPGLCD57_MASK)

#define LCD_WF8B_BPGLCD58_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD58_SHIFT                  (6U)
/*! BPGLCD58
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD58(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD58_SHIFT)) & LCD_WF8B_BPGLCD58_MASK)

#define LCD_WF8B_BPGLCD59_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD59_SHIFT                  (6U)
/*! BPGLCD59
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD59(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD59_SHIFT)) & LCD_WF8B_BPGLCD59_MASK)

#define LCD_WF8B_BPGLCD60_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD60_SHIFT                  (6U)
/*! BPGLCD60
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD60(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD60_SHIFT)) & LCD_WF8B_BPGLCD60_MASK)

#define LCD_WF8B_BPGLCD61_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD61_SHIFT                  (6U)
/*! BPGLCD61
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD61(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD61_SHIFT)) & LCD_WF8B_BPGLCD61_MASK)

#define LCD_WF8B_BPGLCD62_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD62_SHIFT                  (6U)
/*! BPGLCD62
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD62(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD62_SHIFT)) & LCD_WF8B_BPGLCD62_MASK)

#define LCD_WF8B_BPGLCD63_MASK                   (0x40U)
#define LCD_WF8B_BPGLCD63_SHIFT                  (6U)
/*! BPGLCD63
 *  0b0..LCD segment off or LCD backplane inactive for phase G
 *  0b1..LCD segment on or LCD backplane active for phase G
 */
#define LCD_WF8B_BPGLCD63(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPGLCD63_SHIFT)) & LCD_WF8B_BPGLCD63_MASK)

#define LCD_WF8B_BPHLCD0_MASK                    (0x80U)
#define LCD_WF8B_BPHLCD0_SHIFT                   (7U)
/*! BPHLCD0
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD0(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD0_SHIFT)) & LCD_WF8B_BPHLCD0_MASK)

#define LCD_WF8B_BPHLCD1_MASK                    (0x80U)
#define LCD_WF8B_BPHLCD1_SHIFT                   (7U)
/*! BPHLCD1
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD1(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD1_SHIFT)) & LCD_WF8B_BPHLCD1_MASK)

#define LCD_WF8B_BPHLCD2_MASK                    (0x80U)
#define LCD_WF8B_BPHLCD2_SHIFT                   (7U)
/*! BPHLCD2
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD2(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD2_SHIFT)) & LCD_WF8B_BPHLCD2_MASK)

#define LCD_WF8B_BPHLCD3_MASK                    (0x80U)
#define LCD_WF8B_BPHLCD3_SHIFT                   (7U)
/*! BPHLCD3
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD3(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD3_SHIFT)) & LCD_WF8B_BPHLCD3_MASK)

#define LCD_WF8B_BPHLCD4_MASK                    (0x80U)
#define LCD_WF8B_BPHLCD4_SHIFT                   (7U)
/*! BPHLCD4
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD4(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD4_SHIFT)) & LCD_WF8B_BPHLCD4_MASK)

#define LCD_WF8B_BPHLCD5_MASK                    (0x80U)
#define LCD_WF8B_BPHLCD5_SHIFT                   (7U)
/*! BPHLCD5
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD5(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD5_SHIFT)) & LCD_WF8B_BPHLCD5_MASK)

#define LCD_WF8B_BPHLCD6_MASK                    (0x80U)
#define LCD_WF8B_BPHLCD6_SHIFT                   (7U)
/*! BPHLCD6
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD6(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD6_SHIFT)) & LCD_WF8B_BPHLCD6_MASK)

#define LCD_WF8B_BPHLCD7_MASK                    (0x80U)
#define LCD_WF8B_BPHLCD7_SHIFT                   (7U)
/*! BPHLCD7
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD7(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD7_SHIFT)) & LCD_WF8B_BPHLCD7_MASK)

#define LCD_WF8B_BPHLCD8_MASK                    (0x80U)
#define LCD_WF8B_BPHLCD8_SHIFT                   (7U)
/*! BPHLCD8
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD8(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD8_SHIFT)) & LCD_WF8B_BPHLCD8_MASK)

#define LCD_WF8B_BPHLCD9_MASK                    (0x80U)
#define LCD_WF8B_BPHLCD9_SHIFT                   (7U)
/*! BPHLCD9
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD9(x)                      (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD9_SHIFT)) & LCD_WF8B_BPHLCD9_MASK)

#define LCD_WF8B_BPHLCD10_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD10_SHIFT                  (7U)
/*! BPHLCD10
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD10(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD10_SHIFT)) & LCD_WF8B_BPHLCD10_MASK)

#define LCD_WF8B_BPHLCD11_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD11_SHIFT                  (7U)
/*! BPHLCD11
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD11(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD11_SHIFT)) & LCD_WF8B_BPHLCD11_MASK)

#define LCD_WF8B_BPHLCD12_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD12_SHIFT                  (7U)
/*! BPHLCD12
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD12(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD12_SHIFT)) & LCD_WF8B_BPHLCD12_MASK)

#define LCD_WF8B_BPHLCD13_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD13_SHIFT                  (7U)
/*! BPHLCD13
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD13(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD13_SHIFT)) & LCD_WF8B_BPHLCD13_MASK)

#define LCD_WF8B_BPHLCD14_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD14_SHIFT                  (7U)
/*! BPHLCD14
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD14(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD14_SHIFT)) & LCD_WF8B_BPHLCD14_MASK)

#define LCD_WF8B_BPHLCD15_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD15_SHIFT                  (7U)
/*! BPHLCD15
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD15(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD15_SHIFT)) & LCD_WF8B_BPHLCD15_MASK)

#define LCD_WF8B_BPHLCD16_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD16_SHIFT                  (7U)
/*! BPHLCD16
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD16(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD16_SHIFT)) & LCD_WF8B_BPHLCD16_MASK)

#define LCD_WF8B_BPHLCD17_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD17_SHIFT                  (7U)
/*! BPHLCD17
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD17(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD17_SHIFT)) & LCD_WF8B_BPHLCD17_MASK)

#define LCD_WF8B_BPHLCD18_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD18_SHIFT                  (7U)
/*! BPHLCD18
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD18(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD18_SHIFT)) & LCD_WF8B_BPHLCD18_MASK)

#define LCD_WF8B_BPHLCD19_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD19_SHIFT                  (7U)
/*! BPHLCD19
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD19(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD19_SHIFT)) & LCD_WF8B_BPHLCD19_MASK)

#define LCD_WF8B_BPHLCD20_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD20_SHIFT                  (7U)
/*! BPHLCD20
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD20(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD20_SHIFT)) & LCD_WF8B_BPHLCD20_MASK)

#define LCD_WF8B_BPHLCD21_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD21_SHIFT                  (7U)
/*! BPHLCD21
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD21(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD21_SHIFT)) & LCD_WF8B_BPHLCD21_MASK)

#define LCD_WF8B_BPHLCD22_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD22_SHIFT                  (7U)
/*! BPHLCD22
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD22(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD22_SHIFT)) & LCD_WF8B_BPHLCD22_MASK)

#define LCD_WF8B_BPHLCD23_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD23_SHIFT                  (7U)
/*! BPHLCD23
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD23(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD23_SHIFT)) & LCD_WF8B_BPHLCD23_MASK)

#define LCD_WF8B_BPHLCD24_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD24_SHIFT                  (7U)
/*! BPHLCD24
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD24(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD24_SHIFT)) & LCD_WF8B_BPHLCD24_MASK)

#define LCD_WF8B_BPHLCD25_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD25_SHIFT                  (7U)
/*! BPHLCD25
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD25(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD25_SHIFT)) & LCD_WF8B_BPHLCD25_MASK)

#define LCD_WF8B_BPHLCD26_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD26_SHIFT                  (7U)
/*! BPHLCD26
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD26(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD26_SHIFT)) & LCD_WF8B_BPHLCD26_MASK)

#define LCD_WF8B_BPHLCD27_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD27_SHIFT                  (7U)
/*! BPHLCD27
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD27(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD27_SHIFT)) & LCD_WF8B_BPHLCD27_MASK)

#define LCD_WF8B_BPHLCD28_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD28_SHIFT                  (7U)
/*! BPHLCD28
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD28(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD28_SHIFT)) & LCD_WF8B_BPHLCD28_MASK)

#define LCD_WF8B_BPHLCD29_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD29_SHIFT                  (7U)
/*! BPHLCD29
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD29(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD29_SHIFT)) & LCD_WF8B_BPHLCD29_MASK)

#define LCD_WF8B_BPHLCD30_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD30_SHIFT                  (7U)
/*! BPHLCD30
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD30(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD30_SHIFT)) & LCD_WF8B_BPHLCD30_MASK)

#define LCD_WF8B_BPHLCD31_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD31_SHIFT                  (7U)
/*! BPHLCD31
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD31(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD31_SHIFT)) & LCD_WF8B_BPHLCD31_MASK)

#define LCD_WF8B_BPHLCD32_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD32_SHIFT                  (7U)
/*! BPHLCD32
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD32(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD32_SHIFT)) & LCD_WF8B_BPHLCD32_MASK)

#define LCD_WF8B_BPHLCD33_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD33_SHIFT                  (7U)
/*! BPHLCD33
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD33(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD33_SHIFT)) & LCD_WF8B_BPHLCD33_MASK)

#define LCD_WF8B_BPHLCD34_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD34_SHIFT                  (7U)
/*! BPHLCD34
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD34(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD34_SHIFT)) & LCD_WF8B_BPHLCD34_MASK)

#define LCD_WF8B_BPHLCD35_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD35_SHIFT                  (7U)
/*! BPHLCD35
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD35(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD35_SHIFT)) & LCD_WF8B_BPHLCD35_MASK)

#define LCD_WF8B_BPHLCD36_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD36_SHIFT                  (7U)
/*! BPHLCD36
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD36(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD36_SHIFT)) & LCD_WF8B_BPHLCD36_MASK)

#define LCD_WF8B_BPHLCD37_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD37_SHIFT                  (7U)
/*! BPHLCD37
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD37(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD37_SHIFT)) & LCD_WF8B_BPHLCD37_MASK)

#define LCD_WF8B_BPHLCD38_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD38_SHIFT                  (7U)
/*! BPHLCD38
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD38(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD38_SHIFT)) & LCD_WF8B_BPHLCD38_MASK)

#define LCD_WF8B_BPHLCD39_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD39_SHIFT                  (7U)
/*! BPHLCD39
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD39(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD39_SHIFT)) & LCD_WF8B_BPHLCD39_MASK)

#define LCD_WF8B_BPHLCD40_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD40_SHIFT                  (7U)
/*! BPHLCD40
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD40(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD40_SHIFT)) & LCD_WF8B_BPHLCD40_MASK)

#define LCD_WF8B_BPHLCD41_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD41_SHIFT                  (7U)
/*! BPHLCD41
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD41(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD41_SHIFT)) & LCD_WF8B_BPHLCD41_MASK)

#define LCD_WF8B_BPHLCD42_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD42_SHIFT                  (7U)
/*! BPHLCD42
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD42(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD42_SHIFT)) & LCD_WF8B_BPHLCD42_MASK)

#define LCD_WF8B_BPHLCD43_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD43_SHIFT                  (7U)
/*! BPHLCD43
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD43(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD43_SHIFT)) & LCD_WF8B_BPHLCD43_MASK)

#define LCD_WF8B_BPHLCD44_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD44_SHIFT                  (7U)
/*! BPHLCD44
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD44(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD44_SHIFT)) & LCD_WF8B_BPHLCD44_MASK)

#define LCD_WF8B_BPHLCD45_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD45_SHIFT                  (7U)
/*! BPHLCD45
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD45(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD45_SHIFT)) & LCD_WF8B_BPHLCD45_MASK)

#define LCD_WF8B_BPHLCD46_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD46_SHIFT                  (7U)
/*! BPHLCD46
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD46(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD46_SHIFT)) & LCD_WF8B_BPHLCD46_MASK)

#define LCD_WF8B_BPHLCD47_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD47_SHIFT                  (7U)
/*! BPHLCD47
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD47(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD47_SHIFT)) & LCD_WF8B_BPHLCD47_MASK)

#define LCD_WF8B_BPHLCD48_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD48_SHIFT                  (7U)
/*! BPHLCD48
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD48(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD48_SHIFT)) & LCD_WF8B_BPHLCD48_MASK)

#define LCD_WF8B_BPHLCD49_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD49_SHIFT                  (7U)
/*! BPHLCD49
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD49(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD49_SHIFT)) & LCD_WF8B_BPHLCD49_MASK)

#define LCD_WF8B_BPHLCD50_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD50_SHIFT                  (7U)
/*! BPHLCD50
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD50(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD50_SHIFT)) & LCD_WF8B_BPHLCD50_MASK)

#define LCD_WF8B_BPHLCD51_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD51_SHIFT                  (7U)
/*! BPHLCD51
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD51(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD51_SHIFT)) & LCD_WF8B_BPHLCD51_MASK)

#define LCD_WF8B_BPHLCD52_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD52_SHIFT                  (7U)
/*! BPHLCD52
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD52(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD52_SHIFT)) & LCD_WF8B_BPHLCD52_MASK)

#define LCD_WF8B_BPHLCD53_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD53_SHIFT                  (7U)
/*! BPHLCD53
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD53(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD53_SHIFT)) & LCD_WF8B_BPHLCD53_MASK)

#define LCD_WF8B_BPHLCD54_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD54_SHIFT                  (7U)
/*! BPHLCD54
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD54(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD54_SHIFT)) & LCD_WF8B_BPHLCD54_MASK)

#define LCD_WF8B_BPHLCD55_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD55_SHIFT                  (7U)
/*! BPHLCD55
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD55(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD55_SHIFT)) & LCD_WF8B_BPHLCD55_MASK)

#define LCD_WF8B_BPHLCD56_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD56_SHIFT                  (7U)
/*! BPHLCD56
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD56(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD56_SHIFT)) & LCD_WF8B_BPHLCD56_MASK)

#define LCD_WF8B_BPHLCD57_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD57_SHIFT                  (7U)
/*! BPHLCD57
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD57(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD57_SHIFT)) & LCD_WF8B_BPHLCD57_MASK)

#define LCD_WF8B_BPHLCD58_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD58_SHIFT                  (7U)
/*! BPHLCD58
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD58(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD58_SHIFT)) & LCD_WF8B_BPHLCD58_MASK)

#define LCD_WF8B_BPHLCD59_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD59_SHIFT                  (7U)
/*! BPHLCD59
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD59(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD59_SHIFT)) & LCD_WF8B_BPHLCD59_MASK)

#define LCD_WF8B_BPHLCD60_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD60_SHIFT                  (7U)
/*! BPHLCD60
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD60(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD60_SHIFT)) & LCD_WF8B_BPHLCD60_MASK)

#define LCD_WF8B_BPHLCD61_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD61_SHIFT                  (7U)
/*! BPHLCD61
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD61(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD61_SHIFT)) & LCD_WF8B_BPHLCD61_MASK)

#define LCD_WF8B_BPHLCD62_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD62_SHIFT                  (7U)
/*! BPHLCD62
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD62(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD62_SHIFT)) & LCD_WF8B_BPHLCD62_MASK)

#define LCD_WF8B_BPHLCD63_MASK                   (0x80U)
#define LCD_WF8B_BPHLCD63_SHIFT                  (7U)
/*! BPHLCD63
 *  0b0..LCD segment off or LCD backplane inactive for phase H
 *  0b1..LCD segment on or LCD backplane active for phase H
 */
#define LCD_WF8B_BPHLCD63(x)                     (((uint8_t)(((uint8_t)(x)) << LCD_WF8B_BPHLCD63_SHIFT)) & LCD_WF8B_BPHLCD63_MASK)
/*! @} */

/* The count of LCD_WF8B */
#define LCD_WF8B_COUNT                           (64U)

/*! @name WF - LCD Waveform register */
/*! @{ */

#define LCD_WF_WF0_MASK                          (0xFFU)
#define LCD_WF_WF0_SHIFT                         (0U)
#define LCD_WF_WF0(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF0_SHIFT)) & LCD_WF_WF0_MASK)

#define LCD_WF_WF4_MASK                          (0xFFU)
#define LCD_WF_WF4_SHIFT                         (0U)
#define LCD_WF_WF4(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF4_SHIFT)) & LCD_WF_WF4_MASK)

#define LCD_WF_WF8_MASK                          (0xFFU)
#define LCD_WF_WF8_SHIFT                         (0U)
#define LCD_WF_WF8(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF8_SHIFT)) & LCD_WF_WF8_MASK)

#define LCD_WF_WF12_MASK                         (0xFFU)
#define LCD_WF_WF12_SHIFT                        (0U)
#define LCD_WF_WF12(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF12_SHIFT)) & LCD_WF_WF12_MASK)

#define LCD_WF_WF16_MASK                         (0xFFU)
#define LCD_WF_WF16_SHIFT                        (0U)
#define LCD_WF_WF16(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF16_SHIFT)) & LCD_WF_WF16_MASK)

#define LCD_WF_WF20_MASK                         (0xFFU)
#define LCD_WF_WF20_SHIFT                        (0U)
#define LCD_WF_WF20(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF20_SHIFT)) & LCD_WF_WF20_MASK)

#define LCD_WF_WF24_MASK                         (0xFFU)
#define LCD_WF_WF24_SHIFT                        (0U)
#define LCD_WF_WF24(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF24_SHIFT)) & LCD_WF_WF24_MASK)

#define LCD_WF_WF28_MASK                         (0xFFU)
#define LCD_WF_WF28_SHIFT                        (0U)
#define LCD_WF_WF28(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF28_SHIFT)) & LCD_WF_WF28_MASK)

#define LCD_WF_WF32_MASK                         (0xFFU)
#define LCD_WF_WF32_SHIFT                        (0U)
#define LCD_WF_WF32(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF32_SHIFT)) & LCD_WF_WF32_MASK)

#define LCD_WF_WF36_MASK                         (0xFFU)
#define LCD_WF_WF36_SHIFT                        (0U)
#define LCD_WF_WF36(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF36_SHIFT)) & LCD_WF_WF36_MASK)

#define LCD_WF_WF40_MASK                         (0xFFU)
#define LCD_WF_WF40_SHIFT                        (0U)
#define LCD_WF_WF40(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF40_SHIFT)) & LCD_WF_WF40_MASK)

#define LCD_WF_WF44_MASK                         (0xFFU)
#define LCD_WF_WF44_SHIFT                        (0U)
#define LCD_WF_WF44(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF44_SHIFT)) & LCD_WF_WF44_MASK)

#define LCD_WF_WF48_MASK                         (0xFFU)
#define LCD_WF_WF48_SHIFT                        (0U)
#define LCD_WF_WF48(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF48_SHIFT)) & LCD_WF_WF48_MASK)

#define LCD_WF_WF52_MASK                         (0xFFU)
#define LCD_WF_WF52_SHIFT                        (0U)
#define LCD_WF_WF52(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF52_SHIFT)) & LCD_WF_WF52_MASK)

#define LCD_WF_WF56_MASK                         (0xFFU)
#define LCD_WF_WF56_SHIFT                        (0U)
#define LCD_WF_WF56(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF56_SHIFT)) & LCD_WF_WF56_MASK)

#define LCD_WF_WF60_MASK                         (0xFFU)
#define LCD_WF_WF60_SHIFT                        (0U)
#define LCD_WF_WF60(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF60_SHIFT)) & LCD_WF_WF60_MASK)

#define LCD_WF_WF1_MASK                          (0xFF00U)
#define LCD_WF_WF1_SHIFT                         (8U)
#define LCD_WF_WF1(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF1_SHIFT)) & LCD_WF_WF1_MASK)

#define LCD_WF_WF5_MASK                          (0xFF00U)
#define LCD_WF_WF5_SHIFT                         (8U)
#define LCD_WF_WF5(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF5_SHIFT)) & LCD_WF_WF5_MASK)

#define LCD_WF_WF9_MASK                          (0xFF00U)
#define LCD_WF_WF9_SHIFT                         (8U)
#define LCD_WF_WF9(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF9_SHIFT)) & LCD_WF_WF9_MASK)

#define LCD_WF_WF13_MASK                         (0xFF00U)
#define LCD_WF_WF13_SHIFT                        (8U)
#define LCD_WF_WF13(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF13_SHIFT)) & LCD_WF_WF13_MASK)

#define LCD_WF_WF17_MASK                         (0xFF00U)
#define LCD_WF_WF17_SHIFT                        (8U)
#define LCD_WF_WF17(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF17_SHIFT)) & LCD_WF_WF17_MASK)

#define LCD_WF_WF21_MASK                         (0xFF00U)
#define LCD_WF_WF21_SHIFT                        (8U)
#define LCD_WF_WF21(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF21_SHIFT)) & LCD_WF_WF21_MASK)

#define LCD_WF_WF25_MASK                         (0xFF00U)
#define LCD_WF_WF25_SHIFT                        (8U)
#define LCD_WF_WF25(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF25_SHIFT)) & LCD_WF_WF25_MASK)

#define LCD_WF_WF29_MASK                         (0xFF00U)
#define LCD_WF_WF29_SHIFT                        (8U)
#define LCD_WF_WF29(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF29_SHIFT)) & LCD_WF_WF29_MASK)

#define LCD_WF_WF33_MASK                         (0xFF00U)
#define LCD_WF_WF33_SHIFT                        (8U)
#define LCD_WF_WF33(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF33_SHIFT)) & LCD_WF_WF33_MASK)

#define LCD_WF_WF37_MASK                         (0xFF00U)
#define LCD_WF_WF37_SHIFT                        (8U)
#define LCD_WF_WF37(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF37_SHIFT)) & LCD_WF_WF37_MASK)

#define LCD_WF_WF41_MASK                         (0xFF00U)
#define LCD_WF_WF41_SHIFT                        (8U)
#define LCD_WF_WF41(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF41_SHIFT)) & LCD_WF_WF41_MASK)

#define LCD_WF_WF45_MASK                         (0xFF00U)
#define LCD_WF_WF45_SHIFT                        (8U)
#define LCD_WF_WF45(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF45_SHIFT)) & LCD_WF_WF45_MASK)

#define LCD_WF_WF49_MASK                         (0xFF00U)
#define LCD_WF_WF49_SHIFT                        (8U)
#define LCD_WF_WF49(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF49_SHIFT)) & LCD_WF_WF49_MASK)

#define LCD_WF_WF53_MASK                         (0xFF00U)
#define LCD_WF_WF53_SHIFT                        (8U)
#define LCD_WF_WF53(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF53_SHIFT)) & LCD_WF_WF53_MASK)

#define LCD_WF_WF57_MASK                         (0xFF00U)
#define LCD_WF_WF57_SHIFT                        (8U)
#define LCD_WF_WF57(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF57_SHIFT)) & LCD_WF_WF57_MASK)

#define LCD_WF_WF61_MASK                         (0xFF00U)
#define LCD_WF_WF61_SHIFT                        (8U)
#define LCD_WF_WF61(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF61_SHIFT)) & LCD_WF_WF61_MASK)

#define LCD_WF_WF2_MASK                          (0xFF0000U)
#define LCD_WF_WF2_SHIFT                         (16U)
#define LCD_WF_WF2(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF2_SHIFT)) & LCD_WF_WF2_MASK)

#define LCD_WF_WF6_MASK                          (0xFF0000U)
#define LCD_WF_WF6_SHIFT                         (16U)
#define LCD_WF_WF6(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF6_SHIFT)) & LCD_WF_WF6_MASK)

#define LCD_WF_WF10_MASK                         (0xFF0000U)
#define LCD_WF_WF10_SHIFT                        (16U)
#define LCD_WF_WF10(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF10_SHIFT)) & LCD_WF_WF10_MASK)

#define LCD_WF_WF14_MASK                         (0xFF0000U)
#define LCD_WF_WF14_SHIFT                        (16U)
#define LCD_WF_WF14(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF14_SHIFT)) & LCD_WF_WF14_MASK)

#define LCD_WF_WF18_MASK                         (0xFF0000U)
#define LCD_WF_WF18_SHIFT                        (16U)
#define LCD_WF_WF18(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF18_SHIFT)) & LCD_WF_WF18_MASK)

#define LCD_WF_WF22_MASK                         (0xFF0000U)
#define LCD_WF_WF22_SHIFT                        (16U)
#define LCD_WF_WF22(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF22_SHIFT)) & LCD_WF_WF22_MASK)

#define LCD_WF_WF26_MASK                         (0xFF0000U)
#define LCD_WF_WF26_SHIFT                        (16U)
#define LCD_WF_WF26(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF26_SHIFT)) & LCD_WF_WF26_MASK)

#define LCD_WF_WF30_MASK                         (0xFF0000U)
#define LCD_WF_WF30_SHIFT                        (16U)
#define LCD_WF_WF30(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF30_SHIFT)) & LCD_WF_WF30_MASK)

#define LCD_WF_WF34_MASK                         (0xFF0000U)
#define LCD_WF_WF34_SHIFT                        (16U)
#define LCD_WF_WF34(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF34_SHIFT)) & LCD_WF_WF34_MASK)

#define LCD_WF_WF38_MASK                         (0xFF0000U)
#define LCD_WF_WF38_SHIFT                        (16U)
#define LCD_WF_WF38(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF38_SHIFT)) & LCD_WF_WF38_MASK)

#define LCD_WF_WF42_MASK                         (0xFF0000U)
#define LCD_WF_WF42_SHIFT                        (16U)
#define LCD_WF_WF42(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF42_SHIFT)) & LCD_WF_WF42_MASK)

#define LCD_WF_WF46_MASK                         (0xFF0000U)
#define LCD_WF_WF46_SHIFT                        (16U)
#define LCD_WF_WF46(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF46_SHIFT)) & LCD_WF_WF46_MASK)

#define LCD_WF_WF50_MASK                         (0xFF0000U)
#define LCD_WF_WF50_SHIFT                        (16U)
#define LCD_WF_WF50(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF50_SHIFT)) & LCD_WF_WF50_MASK)

#define LCD_WF_WF54_MASK                         (0xFF0000U)
#define LCD_WF_WF54_SHIFT                        (16U)
#define LCD_WF_WF54(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF54_SHIFT)) & LCD_WF_WF54_MASK)

#define LCD_WF_WF58_MASK                         (0xFF0000U)
#define LCD_WF_WF58_SHIFT                        (16U)
#define LCD_WF_WF58(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF58_SHIFT)) & LCD_WF_WF58_MASK)

#define LCD_WF_WF62_MASK                         (0xFF0000U)
#define LCD_WF_WF62_SHIFT                        (16U)
#define LCD_WF_WF62(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF62_SHIFT)) & LCD_WF_WF62_MASK)

#define LCD_WF_WF3_MASK                          (0xFF000000U)
#define LCD_WF_WF3_SHIFT                         (24U)
#define LCD_WF_WF3(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF3_SHIFT)) & LCD_WF_WF3_MASK)

#define LCD_WF_WF7_MASK                          (0xFF000000U)
#define LCD_WF_WF7_SHIFT                         (24U)
#define LCD_WF_WF7(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF7_SHIFT)) & LCD_WF_WF7_MASK)

#define LCD_WF_WF11_MASK                         (0xFF000000U)
#define LCD_WF_WF11_SHIFT                        (24U)
#define LCD_WF_WF11(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF11_SHIFT)) & LCD_WF_WF11_MASK)

#define LCD_WF_WF15_MASK                         (0xFF000000U)
#define LCD_WF_WF15_SHIFT                        (24U)
#define LCD_WF_WF15(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF15_SHIFT)) & LCD_WF_WF15_MASK)

#define LCD_WF_WF19_MASK                         (0xFF000000U)
#define LCD_WF_WF19_SHIFT                        (24U)
#define LCD_WF_WF19(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF19_SHIFT)) & LCD_WF_WF19_MASK)

#define LCD_WF_WF23_MASK                         (0xFF000000U)
#define LCD_WF_WF23_SHIFT                        (24U)
#define LCD_WF_WF23(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF23_SHIFT)) & LCD_WF_WF23_MASK)

#define LCD_WF_WF27_MASK                         (0xFF000000U)
#define LCD_WF_WF27_SHIFT                        (24U)
#define LCD_WF_WF27(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF27_SHIFT)) & LCD_WF_WF27_MASK)

#define LCD_WF_WF31_MASK                         (0xFF000000U)
#define LCD_WF_WF31_SHIFT                        (24U)
#define LCD_WF_WF31(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF31_SHIFT)) & LCD_WF_WF31_MASK)

#define LCD_WF_WF35_MASK                         (0xFF000000U)
#define LCD_WF_WF35_SHIFT                        (24U)
#define LCD_WF_WF35(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF35_SHIFT)) & LCD_WF_WF35_MASK)

#define LCD_WF_WF39_MASK                         (0xFF000000U)
#define LCD_WF_WF39_SHIFT                        (24U)
#define LCD_WF_WF39(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF39_SHIFT)) & LCD_WF_WF39_MASK)

#define LCD_WF_WF43_MASK                         (0xFF000000U)
#define LCD_WF_WF43_SHIFT                        (24U)
#define LCD_WF_WF43(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF43_SHIFT)) & LCD_WF_WF43_MASK)

#define LCD_WF_WF47_MASK                         (0xFF000000U)
#define LCD_WF_WF47_SHIFT                        (24U)
#define LCD_WF_WF47(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF47_SHIFT)) & LCD_WF_WF47_MASK)

#define LCD_WF_WF51_MASK                         (0xFF000000U)
#define LCD_WF_WF51_SHIFT                        (24U)
#define LCD_WF_WF51(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF51_SHIFT)) & LCD_WF_WF51_MASK)

#define LCD_WF_WF55_MASK                         (0xFF000000U)
#define LCD_WF_WF55_SHIFT                        (24U)
#define LCD_WF_WF55(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF55_SHIFT)) & LCD_WF_WF55_MASK)

#define LCD_WF_WF59_MASK                         (0xFF000000U)
#define LCD_WF_WF59_SHIFT                        (24U)
#define LCD_WF_WF59(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF59_SHIFT)) & LCD_WF_WF59_MASK)

#define LCD_WF_WF63_MASK                         (0xFF000000U)
#define LCD_WF_WF63_SHIFT                        (24U)
#define LCD_WF_WF63(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_WF_WF63_SHIFT)) & LCD_WF_WF63_MASK)
/*! @} */

/* The count of LCD_WF */
#define LCD_WF_COUNT                             (16U)


/*!
 * @}
 */ /* end of group LCD_Register_Masks */


/*!
 * @}
 */ /* end of group LCD_Peripheral_Access_Layer */


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


#endif  /* PERI_LCD_H_ */

