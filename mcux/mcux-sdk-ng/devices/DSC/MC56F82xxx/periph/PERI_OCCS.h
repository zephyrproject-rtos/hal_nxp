/*
** ###################################################################
**     Processors:          MC56F82313VLC
**                          MC56F82316VLF
**                          MC56F82323VFM
**                          MC56F82623VLC
**                          MC56F82643VLC
**                          MC56F82646VLF
**                          MC56F82723VFM
**                          MC56F82723VLC
**                          MC56F82726VLF
**                          MC56F82728VLH
**                          MC56F82733MFM
**                          MC56F82733VFM
**                          MC56F82733VLC
**                          MC56F82736VLF
**                          MC56F82738VLH
**                          MC56F82743VFM
**                          MC56F82743VLC
**                          MC56F82746MLF
**                          MC56F82746VLF
**                          MC56F82748MLH
**                          MC56F82748VLH
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OCCS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-11)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OCCS.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OCCS
 *
 * CMSIS Peripheral Access Layer for OCCS
 */

#if !defined(PERI_OCCS_H_)
#define PERI_OCCS_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F82313VLC))
#include "MC56F82313_COMMON.h"
#elif (defined(CPU_MC56F82316VLF))
#include "MC56F82316_COMMON.h"
#elif (defined(CPU_MC56F82323VFM))
#include "MC56F82323_COMMON.h"
#elif (defined(CPU_MC56F82623VLC))
#include "MC56F82623_COMMON.h"
#elif (defined(CPU_MC56F82643VLC))
#include "MC56F82643_COMMON.h"
#elif (defined(CPU_MC56F82646VLF))
#include "MC56F82646_COMMON.h"
#elif (defined(CPU_MC56F82723VFM) || defined(CPU_MC56F82723VLC))
#include "MC56F82723_COMMON.h"
#elif (defined(CPU_MC56F82726VLF))
#include "MC56F82726_COMMON.h"
#elif (defined(CPU_MC56F82728VLH))
#include "MC56F82728_COMMON.h"
#elif (defined(CPU_MC56F82733MFM) || defined(CPU_MC56F82733VFM) || defined(CPU_MC56F82733VLC))
#include "MC56F82733_COMMON.h"
#elif (defined(CPU_MC56F82736VLF))
#include "MC56F82736_COMMON.h"
#elif (defined(CPU_MC56F82738VLH))
#include "MC56F82738_COMMON.h"
#elif (defined(CPU_MC56F82743VFM) || defined(CPU_MC56F82743VLC))
#include "MC56F82743_COMMON.h"
#elif (defined(CPU_MC56F82746MLF) || defined(CPU_MC56F82746VLF))
#include "MC56F82746_COMMON.h"
#elif (defined(CPU_MC56F82748MLH) || defined(CPU_MC56F82748VLH))
#include "MC56F82748_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- OCCS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCCS_Peripheral_Access_Layer OCCS Peripheral Access Layer
 * @{
 */

/** OCCS - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL;                              /**< PLL Control Register, offset: 0x0 */
  __IO uint16_t DIVBY;                             /**< PLL Divide-By Register, offset: 0x1 */
  __IO uint16_t STAT;                              /**< OCCS Status Register, offset: 0x2 */
       uint16_t RESERVED_0[1];
  __IO uint16_t OSCTL1;                            /**< Oscillator Control Register 1, offset: 0x4 */
  __IO uint16_t OSCTL2;                            /**< Oscillator Control Register 2, offset: 0x5 */
  __IO uint16_t CLKCHKR;                           /**< External Clock Check Reference, offset: 0x6 */
  __I  uint16_t CLKCHKT;                           /**< External Clock Check Target, offset: 0x7 */
  __IO uint16_t PROT;                              /**< Protection Register, offset: 0x8 */
} OCCS_Type;

/* ----------------------------------------------------------------------------
   -- OCCS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCCS_Register_Masks OCCS Register Masks
 * @{
 */

/*! @name CTRL - PLL Control Register */
/*! @{ */

#define OCCS_CTRL_ZSRC_MASK                      (0x1U)
#define OCCS_CTRL_ZSRC_SHIFT                     (0U)
/*! ZSRC - CLOCK Source
 *  0b0..MSTR_OSC
 *  0b1..PLL output divided by 2
 */
#define OCCS_CTRL_ZSRC(x)                        (((uint16_t)(((uint16_t)(x)) << OCCS_CTRL_ZSRC_SHIFT)) & OCCS_CTRL_ZSRC_MASK)

#define OCCS_CTRL_PRECS_MASK                     (0xCU)
#define OCCS_CTRL_PRECS_SHIFT                    (2U)
/*! PRECS - Prescaler Clock Select
 *  0b00..8 MHz relaxation oscillator selected (reset value)
 *  0b01..External reference selected
 *  0b10..200 kHz relaxation oscillator selected
 *  0b11..Reserved
 */
#define OCCS_CTRL_PRECS(x)                       (((uint16_t)(((uint16_t)(x)) << OCCS_CTRL_PRECS_SHIFT)) & OCCS_CTRL_PRECS_MASK)

#define OCCS_CTRL_PLLPD_MASK                     (0x10U)
#define OCCS_CTRL_PLLPD_SHIFT                    (4U)
/*! PLLPD - PLL Power Down
 *  0b0..PLL enabled
 *  0b1..PLL powered down
 */
#define OCCS_CTRL_PLLPD(x)                       (((uint16_t)(((uint16_t)(x)) << OCCS_CTRL_PLLPD_SHIFT)) & OCCS_CTRL_PLLPD_MASK)

#define OCCS_CTRL_LCKON_MASK                     (0x80U)
#define OCCS_CTRL_LCKON_SHIFT                    (7U)
/*! LCKON - Lock Detector On
 *  0b0..Lock detector disabled
 *  0b1..Lock detector enabled
 */
#define OCCS_CTRL_LCKON(x)                       (((uint16_t)(((uint16_t)(x)) << OCCS_CTRL_LCKON_SHIFT)) & OCCS_CTRL_LCKON_MASK)

#define OCCS_CTRL_LOCIE_MASK                     (0x800U)
#define OCCS_CTRL_LOCIE_SHIFT                    (11U)
/*! LOCIE - Loss of Reference Clock Interrupt Enable
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define OCCS_CTRL_LOCIE(x)                       (((uint16_t)(((uint16_t)(x)) << OCCS_CTRL_LOCIE_SHIFT)) & OCCS_CTRL_LOCIE_MASK)

#define OCCS_CTRL_PLLIE0_MASK                    (0x3000U)
#define OCCS_CTRL_PLLIE0_SHIFT                   (12U)
/*! PLLIE0 - PLL Interrupt Enable 0
 *  0b00..Disable interrupt.
 *  0b01..Enable interrupt on any rising edge of LCK0.
 *  0b10..Enable interrupt on falling edge of LCK0.
 *  0b11..Enable interrupt on any edge change of LCK0.
 */
#define OCCS_CTRL_PLLIE0(x)                      (((uint16_t)(((uint16_t)(x)) << OCCS_CTRL_PLLIE0_SHIFT)) & OCCS_CTRL_PLLIE0_MASK)

#define OCCS_CTRL_PLLIE1_MASK                    (0xC000U)
#define OCCS_CTRL_PLLIE1_SHIFT                   (14U)
/*! PLLIE1 - PLL Interrupt Enable 1
 *  0b00..Disable interrupt.
 *  0b01..Enable interrupt on any rising edge of LCK1.
 *  0b10..Enable interrupt on falling edge of LCK1.
 *  0b11..Enable interrupt on any edge change of LCK1.
 */
#define OCCS_CTRL_PLLIE1(x)                      (((uint16_t)(((uint16_t)(x)) << OCCS_CTRL_PLLIE1_SHIFT)) & OCCS_CTRL_PLLIE1_MASK)
/*! @} */

/*! @name DIVBY - PLL Divide-By Register */
/*! @{ */

#define OCCS_DIVBY_PLLDB_MASK                    (0x3FU)
#define OCCS_DIVBY_PLLDB_SHIFT                   (0U)
/*! PLLDB - PLL Divide By */
#define OCCS_DIVBY_PLLDB(x)                      (((uint16_t)(((uint16_t)(x)) << OCCS_DIVBY_PLLDB_SHIFT)) & OCCS_DIVBY_PLLDB_MASK)

#define OCCS_DIVBY_PWM_DIV2_MASK                 (0x40U)
#define OCCS_DIVBY_PWM_DIV2_SHIFT                (6U)
/*! PWM_DIV2
 *  0b0..Raw PLL output selected as PWM_2X clock if PLL output is 200MHz
 *  0b1..PLL DIV2 Clock Selected as PWM 2X clock if PLL output is 400 MHz. This is recommended setting.
 */
#define OCCS_DIVBY_PWM_DIV2(x)                   (((uint16_t)(((uint16_t)(x)) << OCCS_DIVBY_PWM_DIV2_SHIFT)) & OCCS_DIVBY_PWM_DIV2_MASK)

#define OCCS_DIVBY_COD_MASK                      (0xF00U)
#define OCCS_DIVBY_COD_SHIFT                     (8U)
/*! COD - Clock Output Divide or Postscaler
 *  0b0000..Divide clock output by 1.
 *  0b0001..Divide clock output by 2.
 *  0b0010..Divide clock output by 4.
 *  0b0011..Divide clock output by 8.
 *  0b0100..Divide clock output by 16.
 *  0b0101..Divide clock output by 32.
 *  0b0110..Divide clock output by 64.
 *  0b0111..Divide clock output by 128.
 *  0b1xxx..Divide clock output by 256.
 */
#define OCCS_DIVBY_COD(x)                        (((uint16_t)(((uint16_t)(x)) << OCCS_DIVBY_COD_SHIFT)) & OCCS_DIVBY_COD_MASK)

#define OCCS_DIVBY_LORTP_MASK                    (0xF000U)
#define OCCS_DIVBY_LORTP_SHIFT                   (12U)
/*! LORTP - Loss of Reference Clock Trip Point */
#define OCCS_DIVBY_LORTP(x)                      (((uint16_t)(((uint16_t)(x)) << OCCS_DIVBY_LORTP_SHIFT)) & OCCS_DIVBY_LORTP_MASK)
/*! @} */

/*! @name STAT - OCCS Status Register */
/*! @{ */

#define OCCS_STAT_ZSRCS_MASK                     (0x3U)
#define OCCS_STAT_ZSRCS_SHIFT                    (0U)
/*! ZSRCS - CLOCK Source Status
 *  0b00..MSTR_OSC
 *  0b01..PLL output divided by 2
 *  0b1x..Synchronization in progress
 */
#define OCCS_STAT_ZSRCS(x)                       (((uint16_t)(((uint16_t)(x)) << OCCS_STAT_ZSRCS_SHIFT)) & OCCS_STAT_ZSRCS_MASK)

#define OCCS_STAT_PLLPDN_MASK                    (0x10U)
#define OCCS_STAT_PLLPDN_SHIFT                   (4U)
/*! PLLPDN - PLL Power Down
 *  0b0..PLL not powered down.
 *  0b1..PLL powered down.
 */
#define OCCS_STAT_PLLPDN(x)                      (((uint16_t)(((uint16_t)(x)) << OCCS_STAT_PLLPDN_SHIFT)) & OCCS_STAT_PLLPDN_MASK)

#define OCCS_STAT_LCK0_MASK                      (0x20U)
#define OCCS_STAT_LCK0_SHIFT                     (5U)
/*! LCK0 - PLL Lock 0 Status
 *  0b0..PLL is unlocked.
 *  0b1..PLL is locked (coarse).
 */
#define OCCS_STAT_LCK0(x)                        (((uint16_t)(((uint16_t)(x)) << OCCS_STAT_LCK0_SHIFT)) & OCCS_STAT_LCK0_MASK)

#define OCCS_STAT_LCK1_MASK                      (0x40U)
#define OCCS_STAT_LCK1_SHIFT                     (6U)
/*! LCK1 - PLL Lock 1 Status
 *  0b0..PLL is unlocked.
 *  0b1..PLL is locked (fine).
 */
#define OCCS_STAT_LCK1(x)                        (((uint16_t)(((uint16_t)(x)) << OCCS_STAT_LCK1_SHIFT)) & OCCS_STAT_LCK1_MASK)

#define OCCS_STAT_OSC_OK_MASK                    (0x80U)
#define OCCS_STAT_OSC_OK_SHIFT                   (7U)
/*! OSC_OK - OSC_OK Indicator from XOSC
 *  0b0..Oscillator clock is still not stable, or XOSC is disabled.
 *  0b1..XOSC OK indicator after crystal oscillator startup.
 */
#define OCCS_STAT_OSC_OK(x)                      (((uint16_t)(((uint16_t)(x)) << OCCS_STAT_OSC_OK_SHIFT)) & OCCS_STAT_OSC_OK_MASK)

#define OCCS_STAT_MON_FAILURE_MASK               (0x100U)
#define OCCS_STAT_MON_FAILURE_SHIFT              (8U)
/*! MON_FAILURE - XOSC Clock Monitor Failure Indicator
 *  0b0..No clock failure, or clock monitor is disabled.
 *  0b1..Clock failure detected on XOSC reference clock when clock monitor is enabled.
 */
#define OCCS_STAT_MON_FAILURE(x)                 (((uint16_t)(((uint16_t)(x)) << OCCS_STAT_MON_FAILURE_SHIFT)) & OCCS_STAT_MON_FAILURE_MASK)

#define OCCS_STAT_LOCI_MASK                      (0x2000U)
#define OCCS_STAT_LOCI_SHIFT                     (13U)
/*! LOCI - Loss of Reference Clock Interrupt
 *  0b0..Oscillator clock normal.
 *  0b1..Loss of oscillator clock detected.
 */
#define OCCS_STAT_LOCI(x)                        (((uint16_t)(((uint16_t)(x)) << OCCS_STAT_LOCI_SHIFT)) & OCCS_STAT_LOCI_MASK)

#define OCCS_STAT_LOLI0_MASK                     (0x4000U)
#define OCCS_STAT_LOLI0_SHIFT                    (14U)
/*! LOLI0 - PLL Lock or Loss of Lock Interrupt 0
 *  0b0..No lock or loss of lock event has occurred.
 *  0b1..PLL lock status based on PLLIE0.
 */
#define OCCS_STAT_LOLI0(x)                       (((uint16_t)(((uint16_t)(x)) << OCCS_STAT_LOLI0_SHIFT)) & OCCS_STAT_LOLI0_MASK)

#define OCCS_STAT_LOLI1_MASK                     (0x8000U)
#define OCCS_STAT_LOLI1_SHIFT                    (15U)
/*! LOLI1 - PLL Lock or Loss of Lock Interrupt 1
 *  0b0..No lock or loss of lock event has occurred.
 *  0b1..PLL lock status based on PLLIE1.
 */
#define OCCS_STAT_LOLI1(x)                       (((uint16_t)(((uint16_t)(x)) << OCCS_STAT_LOLI1_SHIFT)) & OCCS_STAT_LOLI1_MASK)
/*! @} */

/*! @name OSCTL1 - Oscillator Control Register 1 */
/*! @{ */

#define OCCS_OSCTL1_FREQ_TRIM8M_MASK             (0x3FFU)
#define OCCS_OSCTL1_FREQ_TRIM8M_SHIFT            (0U)
/*! FREQ_TRIM8M - 8 MHz Relaxation Oscillator Frequency Trim */
#define OCCS_OSCTL1_FREQ_TRIM8M(x)               (((uint16_t)(((uint16_t)(x)) << OCCS_OSCTL1_FREQ_TRIM8M_SHIFT)) & OCCS_OSCTL1_FREQ_TRIM8M_MASK)

#define OCCS_OSCTL1_EXT_SEL_MASK                 (0x400U)
#define OCCS_OSCTL1_EXT_SEL_SHIFT                (10U)
/*! EXT_SEL - External Clock In Select
 *  0b0..Use the output of the crystal oscillator as the external clock input.
 *  0b1..Use CLKIN as the external clock input.
 */
#define OCCS_OSCTL1_EXT_SEL(x)                   (((uint16_t)(((uint16_t)(x)) << OCCS_OSCTL1_EXT_SEL_SHIFT)) & OCCS_OSCTL1_EXT_SEL_MASK)

#define OCCS_OSCTL1_CLK_MODE_MASK                (0x1000U)
#define OCCS_OSCTL1_CLK_MODE_SHIFT               (12U)
/*! CLK_MODE - Crystal Oscillator Clock Mode
 *  0b0..Crystal oscillator enabled.
 *  0b1..External clock bypass mode. This enables the crystal oscillator's external clock bypass mode and allows
 *       an external clock source on the EXTAL input of the oscillator to propagate directly to the oscillator's
 *       clock output.
 */
#define OCCS_OSCTL1_CLK_MODE(x)                  (((uint16_t)(((uint16_t)(x)) << OCCS_OSCTL1_CLK_MODE_SHIFT)) & OCCS_OSCTL1_CLK_MODE_MASK)

#define OCCS_OSCTL1_COHL_MASK                    (0x2000U)
#define OCCS_OSCTL1_COHL_SHIFT                   (13U)
/*! COHL - Crystal Oscillator High/Low Power Level
 *  0b0..High power mode.
 *  0b1..Low power mode.
 */
#define OCCS_OSCTL1_COHL(x)                      (((uint16_t)(((uint16_t)(x)) << OCCS_OSCTL1_COHL_SHIFT)) & OCCS_OSCTL1_COHL_MASK)

#define OCCS_OSCTL1_ROSB_MASK                    (0x4000U)
#define OCCS_OSCTL1_ROSB_SHIFT                   (14U)
/*! ROSB - 8 MHz Relaxation Oscillator Standby
 *  0b0..Normal mode. The relaxation oscillator output frequency is 8 MHz.
 *  0b1..Standby mode. The relaxation oscillator output frequency is reduced to 400 kHz (+/-50%). The PLL should
 *       be disabled in this mode and MSTR_OSC should be selected as the output clock.
 */
#define OCCS_OSCTL1_ROSB(x)                      (((uint16_t)(((uint16_t)(x)) << OCCS_OSCTL1_ROSB_SHIFT)) & OCCS_OSCTL1_ROSB_MASK)

#define OCCS_OSCTL1_ROPD_MASK                    (0x8000U)
#define OCCS_OSCTL1_ROPD_SHIFT                   (15U)
/*! ROPD - 8 MHz Relaxation Oscillator Power Down
 *  0b0..Relaxation oscillator enabled.
 *  0b1..Relaxation oscillator powered down.
 */
#define OCCS_OSCTL1_ROPD(x)                      (((uint16_t)(((uint16_t)(x)) << OCCS_OSCTL1_ROPD_SHIFT)) & OCCS_OSCTL1_ROPD_MASK)
/*! @} */

/*! @name OSCTL2 - Oscillator Control Register 2 */
/*! @{ */

#define OCCS_OSCTL2_FREQ_TRIM200K_MASK           (0x1FFU)
#define OCCS_OSCTL2_FREQ_TRIM200K_SHIFT          (0U)
/*! FREQ_TRIM200K - 200 kHz Internal RC Oscillator Frequency Trim */
#define OCCS_OSCTL2_FREQ_TRIM200K(x)             (((uint16_t)(((uint16_t)(x)) << OCCS_OSCTL2_FREQ_TRIM200K_SHIFT)) & OCCS_OSCTL2_FREQ_TRIM200K_MASK)

#define OCCS_OSCTL2_MON_ENABLE_MASK              (0x200U)
#define OCCS_OSCTL2_MON_ENABLE_SHIFT             (9U)
/*! MON_ENABLE - XOSC Clock Monitor Enable Control */
#define OCCS_OSCTL2_MON_ENABLE(x)                (((uint16_t)(((uint16_t)(x)) << OCCS_OSCTL2_MON_ENABLE_SHIFT)) & OCCS_OSCTL2_MON_ENABLE_MASK)

#define OCCS_OSCTL2_TEMP_TRIM8M_MASK             (0x3C00U)
#define OCCS_OSCTL2_TEMP_TRIM8M_SHIFT            (10U)
/*! TEMP_TRIM8M - 8 MHz Internal Relaxation Oscillator Temperature Trim */
#define OCCS_OSCTL2_TEMP_TRIM8M(x)               (((uint16_t)(((uint16_t)(x)) << OCCS_OSCTL2_TEMP_TRIM8M_SHIFT)) & OCCS_OSCTL2_TEMP_TRIM8M_MASK)

#define OCCS_OSCTL2_COPD_MASK                    (0x4000U)
#define OCCS_OSCTL2_COPD_SHIFT                   (14U)
/*! COPD - Crystal Oscillator Power Down
 *  0b0..Crystal oscillator enabled.
 *  0b1..Crystal oscillator powered down.
 */
#define OCCS_OSCTL2_COPD(x)                      (((uint16_t)(((uint16_t)(x)) << OCCS_OSCTL2_COPD_SHIFT)) & OCCS_OSCTL2_COPD_MASK)

#define OCCS_OSCTL2_ROPD200K_MASK                (0x8000U)
#define OCCS_OSCTL2_ROPD200K_SHIFT               (15U)
/*! ROPD200K - 200 kHz RC Oscillator Power Down */
#define OCCS_OSCTL2_ROPD200K(x)                  (((uint16_t)(((uint16_t)(x)) << OCCS_OSCTL2_ROPD200K_SHIFT)) & OCCS_OSCTL2_ROPD200K_MASK)
/*! @} */

/*! @name CLKCHKR - External Clock Check Reference */
/*! @{ */

#define OCCS_CLKCHKR_REF_CNT_MASK                (0x7FU)
#define OCCS_CLKCHKR_REF_CNT_SHIFT               (0U)
/*! REF_CNT - Reference Count */
#define OCCS_CLKCHKR_REF_CNT(x)                  (((uint16_t)(((uint16_t)(x)) << OCCS_CLKCHKR_REF_CNT_SHIFT)) & OCCS_CLKCHKR_REF_CNT_MASK)

#define OCCS_CLKCHKR_CHK_ENA_MASK                (0x8000U)
#define OCCS_CLKCHKR_CHK_ENA_SHIFT               (15U)
/*! CHK_ENA - Check Enable
 *  0b0..Writing a low while the clock checking operation is in progress stops the check in its current state.
 *       Reading a low after a check has been started indicates that the check operation is complete and the final
 *       values are valid in the REF_CNT and TARGET_CNT fields.
 *  0b1..Writing a one clears the REF_CNT and TARGET_CNT fields and starts the clock checking function. The
 *       CLK_ENA bit remains high while the operation is in progress.
 */
#define OCCS_CLKCHKR_CHK_ENA(x)                  (((uint16_t)(((uint16_t)(x)) << OCCS_CLKCHKR_CHK_ENA_SHIFT)) & OCCS_CLKCHKR_CHK_ENA_MASK)
/*! @} */

/*! @name CLKCHKT - External Clock Check Target */
/*! @{ */

#define OCCS_CLKCHKT_TARGET_CNT_MASK             (0x7FFU)
#define OCCS_CLKCHKT_TARGET_CNT_SHIFT            (0U)
/*! TARGET_CNT - CLKCHKT Target Count */
#define OCCS_CLKCHKT_TARGET_CNT(x)               (((uint16_t)(((uint16_t)(x)) << OCCS_CLKCHKT_TARGET_CNT_SHIFT)) & OCCS_CLKCHKT_TARGET_CNT_MASK)
/*! @} */

/*! @name PROT - Protection Register */
/*! @{ */

#define OCCS_PROT_PLLEP_MASK                     (0x3U)
#define OCCS_PROT_PLLEP_SHIFT                    (0U)
/*! PLLEP - PLL Enable Protection
 *  0b00..Write protection off (default).
 *  0b01..Write protection on.
 *  0b10..Write protection off and locked until chip reset.
 *  0b11..Write protection on and locked until chip reset.
 */
#define OCCS_PROT_PLLEP(x)                       (((uint16_t)(((uint16_t)(x)) << OCCS_PROT_PLLEP_SHIFT)) & OCCS_PROT_PLLEP_MASK)

#define OCCS_PROT_OSCEP_MASK                     (0xCU)
#define OCCS_PROT_OSCEP_SHIFT                    (2U)
/*! OSCEP - Oscillator Enable Protection
 *  0b00..Write protection off (default).
 *  0b01..Write protection on.
 *  0b10..Write protection off and locked until chip reset.
 *  0b11..Write protection on and locked until chip reset.
 */
#define OCCS_PROT_OSCEP(x)                       (((uint16_t)(((uint16_t)(x)) << OCCS_PROT_OSCEP_SHIFT)) & OCCS_PROT_OSCEP_MASK)

#define OCCS_PROT_FRQEP_MASK                     (0x30U)
#define OCCS_PROT_FRQEP_SHIFT                    (4U)
/*! FRQEP - Frequency Enable Protection
 *  0b00..Write protection off (default).
 *  0b01..Write protection on.
 *  0b10..Write protection off and locked until chip reset.
 *  0b11..Write protection on and locked until chip reset.
 */
#define OCCS_PROT_FRQEP(x)                       (((uint16_t)(((uint16_t)(x)) << OCCS_PROT_FRQEP_SHIFT)) & OCCS_PROT_FRQEP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OCCS_Register_Masks */


/*!
 * @}
 */ /* end of group OCCS_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_OCCS_H_ */

