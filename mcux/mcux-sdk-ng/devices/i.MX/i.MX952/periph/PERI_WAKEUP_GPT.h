/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WAKEUP_GPT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_WAKEUP_GPT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for WAKEUP_GPT
 *
 * CMSIS Peripheral Access Layer for WAKEUP_GPT
 */

#if !defined(PERI_WAKEUP_GPT_H_)
#define PERI_WAKEUP_GPT_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- WAKEUP_GPT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_GPT_Peripheral_Access_Layer WAKEUP_GPT Peripheral Access Layer
 * @{
 */

/** WAKEUP_GPT - Size of Registers Arrays */
#define WAKEUP_GPT_OCR_COUNT                      3u
#define WAKEUP_GPT_ICR_COUNT                      2u

/** WAKEUP_GPT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  __IO uint32_t PR;                                /**< Prescaler, offset: 0x4 */
  __IO uint32_t SR;                                /**< Status, offset: 0x8 */
  __IO uint32_t IR;                                /**< Interrupt, offset: 0xC */
  __IO uint32_t OCR[WAKEUP_GPT_OCR_COUNT];         /**< Output Compare, array offset: 0x10, array step: 0x4 */
  __I  uint32_t ICR[WAKEUP_GPT_ICR_COUNT];         /**< Input Capture, array offset: 0x1C, array step: 0x4 */
  __I  uint32_t CNT;                               /**< Counter, offset: 0x24 */
} WAKEUP_GPT_Type;

/* ----------------------------------------------------------------------------
   -- WAKEUP_GPT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_GPT_Register_Masks WAKEUP_GPT Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define WAKEUP_GPT_CR_EN_MASK                    (0x1U)
#define WAKEUP_GPT_CR_EN_SHIFT                   (0U)
/*! EN - GPT Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WAKEUP_GPT_CR_EN(x)                      (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_EN_SHIFT)) & WAKEUP_GPT_CR_EN_MASK)

#define WAKEUP_GPT_CR_ENMOD_MASK                 (0x2U)
#define WAKEUP_GPT_CR_ENMOD_SHIFT                (1U)
/*! ENMOD - GPT Enable Mode
 *  0b0..Restart counting from frozen values after GPT is enabled (EN=1).
 *  0b1..Reset counting from 0 after GPT is enabled (EN=1).
 */
#define WAKEUP_GPT_CR_ENMOD(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_ENMOD_SHIFT)) & WAKEUP_GPT_CR_ENMOD_MASK)

#define WAKEUP_GPT_CR_DBGEN_MASK                 (0x4U)
#define WAKEUP_GPT_CR_DBGEN_SHIFT                (2U)
/*! DBGEN - GPT Debug Mode Enable
 *  0b0..Disable in Debug mode
 *  0b1..Enable in Debug mode
 */
#define WAKEUP_GPT_CR_DBGEN(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_DBGEN_SHIFT)) & WAKEUP_GPT_CR_DBGEN_MASK)

#define WAKEUP_GPT_CR_WAITEN_MASK                (0x8U)
#define WAKEUP_GPT_CR_WAITEN_SHIFT               (3U)
/*! WAITEN - GPT Wait Mode Enable
 *  0b0..Disable in Wait mode
 *  0b1..Enable in Wait mode
 */
#define WAKEUP_GPT_CR_WAITEN(x)                  (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_WAITEN_SHIFT)) & WAKEUP_GPT_CR_WAITEN_MASK)

#define WAKEUP_GPT_CR_DOZEEN_MASK                (0x10U)
#define WAKEUP_GPT_CR_DOZEEN_SHIFT               (4U)
/*! DOZEEN - GPT Doze Mode Enable
 *  0b0..Disable in Doze mode
 *  0b1..Enable in Doze mode
 */
#define WAKEUP_GPT_CR_DOZEEN(x)                  (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_DOZEEN_SHIFT)) & WAKEUP_GPT_CR_DOZEEN_MASK)

#define WAKEUP_GPT_CR_STOPEN_MASK                (0x20U)
#define WAKEUP_GPT_CR_STOPEN_SHIFT               (5U)
/*! STOPEN - GPT Stop Mode Enable
 *  0b0..Disable in Stop mode
 *  0b1..Enable in Stop mode
 */
#define WAKEUP_GPT_CR_STOPEN(x)                  (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_STOPEN_SHIFT)) & WAKEUP_GPT_CR_STOPEN_MASK)

#define WAKEUP_GPT_CR_CLKSRC_MASK                (0x1C0U)
#define WAKEUP_GPT_CR_CLKSRC_SHIFT               (6U)
/*! CLKSRC - Clock Source Select
 *  0b000..No clock
 *  0b001..Peripheral clock (MODULE_CLK)
 *  0b010..High-frequency reference clock (ipg_clk_highfreq)
 *  0b011..External clock
 *  0b100..Low-frequency reference clock (ipg_clk_32k)
 */
#define WAKEUP_GPT_CR_CLKSRC(x)                  (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_CLKSRC_SHIFT)) & WAKEUP_GPT_CR_CLKSRC_MASK)

#define WAKEUP_GPT_CR_FRR_MASK                   (0x200U)
#define WAKEUP_GPT_CR_FRR_SHIFT                  (9U)
/*! FRR - Free-Run or Restart Mode
 *  0b0..Restart mode. After a compare event, the counter resets to 0000_0000h and resumes counting.
 *  0b1..Free-Run mode. After a compare event, the counter continues counting until FFFF_FFFFh and then rolls over to 0.
 */
#define WAKEUP_GPT_CR_FRR(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_FRR_SHIFT)) & WAKEUP_GPT_CR_FRR_MASK)

#define WAKEUP_GPT_CR_EN_24M_MASK                (0x400U)
#define WAKEUP_GPT_CR_EN_24M_SHIFT               (10U)
/*! EN_24M - Enable Oscillator Clock Input
 *  0b0..Disable
 *  0b1..Enable
 */
#define WAKEUP_GPT_CR_EN_24M(x)                  (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_EN_24M_SHIFT)) & WAKEUP_GPT_CR_EN_24M_MASK)

#define WAKEUP_GPT_CR_SWR_MASK                   (0x8000U)
#define WAKEUP_GPT_CR_SWR_SHIFT                  (15U)
/*! SWR - Software Reset
 *  0b0..GPT is not in software reset state
 *  0b1..GPT is in software reset state
 */
#define WAKEUP_GPT_CR_SWR(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_SWR_SHIFT)) & WAKEUP_GPT_CR_SWR_MASK)

#define WAKEUP_GPT_CR_IM1_MASK                   (0x30000U)
#define WAKEUP_GPT_CR_IM1_SHIFT                  (16U)
/*! IM1 - Input Capture Operating Mode for Channel 1
 *  0b00..Capture disabled
 *  0b01..Capture on rising edge only
 *  0b10..Capture on falling edge only
 *  0b11..Capture on both edges
 */
#define WAKEUP_GPT_CR_IM1(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_IM1_SHIFT)) & WAKEUP_GPT_CR_IM1_MASK)

#define WAKEUP_GPT_CR_IM2_MASK                   (0xC0000U)
#define WAKEUP_GPT_CR_IM2_SHIFT                  (18U)
/*! IM2 - Input Capture Operating Mode for Channel 2
 *  0b00..Capture disabled
 *  0b01..Capture on rising edge only
 *  0b10..Capture on falling edge only
 *  0b11..Capture on both edges
 */
#define WAKEUP_GPT_CR_IM2(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_IM2_SHIFT)) & WAKEUP_GPT_CR_IM2_MASK)

#define WAKEUP_GPT_CR_OM1_MASK                   (0x700000U)
#define WAKEUP_GPT_CR_OM1_SHIFT                  (20U)
/*! OM1 - Output Compare Operating Mode for Channel 1
 *  0b000..Output disabled. No response on the signal.
 *  0b001..Toggle output
 *  0b010..Clear output
 *  0b011..Set output
 *  0b1xx..Generate a low pulse that is one input clock cycle wide on the output signal. When OMn is first
 *         programmed as 1xx, the output is set to one immediately on the next input clock (if it was not already). The
 *         input clock here refers to the clock selected by the CLKSRC field of this register.
 */
#define WAKEUP_GPT_CR_OM1(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_OM1_SHIFT)) & WAKEUP_GPT_CR_OM1_MASK)

#define WAKEUP_GPT_CR_OM2_MASK                   (0x3800000U)
#define WAKEUP_GPT_CR_OM2_SHIFT                  (23U)
/*! OM2 - Output Compare Operating Mode for Channel 2
 *  0b000..Output disabled. No response on the signal.
 *  0b001..Toggle output
 *  0b010..Clear output
 *  0b011..Set output
 *  0b1xx..Generate a low pulse that is one input clock cycle wide on the output signal. When OMn is first
 *         programmed as 1xx, the output is set to one immediately on the next input clock (if it was not already). The
 *         input clock here refers to the clock selected by the CLKSRC field of this register.
 */
#define WAKEUP_GPT_CR_OM2(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_OM2_SHIFT)) & WAKEUP_GPT_CR_OM2_MASK)

#define WAKEUP_GPT_CR_OM3_MASK                   (0x1C000000U)
#define WAKEUP_GPT_CR_OM3_SHIFT                  (26U)
/*! OM3 - Output Compare Operating Mode for Channel 3
 *  0b000..Output disabled. No response on the signal.
 *  0b001..Toggle output
 *  0b010..Clear output
 *  0b011..Set output
 *  0b1xx..Generate a low pulse that is one input clock cycle wide on the output signal. When OMn is first
 *         programmed as 1xx, the output is set to one immediately on the next input clock (if it was not already). The
 *         input clock here refers to the clock selected by the CLKSRC field of this register.
 */
#define WAKEUP_GPT_CR_OM3(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_OM3_SHIFT)) & WAKEUP_GPT_CR_OM3_MASK)

#define WAKEUP_GPT_CR_FO1_MASK                   (0x20000000U)
#define WAKEUP_GPT_CR_FO1_SHIFT                  (29U)
/*! FO1 - Force Output Compare for Channel 1
 *  0b0..No effect
 *  0b1..Trigger the programmed response on the output signal
 */
#define WAKEUP_GPT_CR_FO1(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_FO1_SHIFT)) & WAKEUP_GPT_CR_FO1_MASK)

#define WAKEUP_GPT_CR_FO2_MASK                   (0x40000000U)
#define WAKEUP_GPT_CR_FO2_SHIFT                  (30U)
/*! FO2 - Force Output Compare for Channel 2
 *  0b0..No effect
 *  0b1..Trigger the programmed response on the output signal
 */
#define WAKEUP_GPT_CR_FO2(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_FO2_SHIFT)) & WAKEUP_GPT_CR_FO2_MASK)

#define WAKEUP_GPT_CR_FO3_MASK                   (0x80000000U)
#define WAKEUP_GPT_CR_FO3_SHIFT                  (31U)
/*! FO3 - Force Output Compare for Channel 3
 *  0b0..No effect
 *  0b1..Trigger the programmed response on the output signal
 */
#define WAKEUP_GPT_CR_FO3(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CR_FO3_SHIFT)) & WAKEUP_GPT_CR_FO3_MASK)
/*! @} */

/*! @name PR - Prescaler */
/*! @{ */

#define WAKEUP_GPT_PR_PRESCALER_MASK             (0xFFFU)
#define WAKEUP_GPT_PR_PRESCALER_SHIFT            (0U)
/*! PRESCALER - Prescaler Divide Value
 *  0b000000000000..Divide by 1
 *  0b000000000001..Divide by 2
 *  0b111111111111..Divide by 4096
 */
#define WAKEUP_GPT_PR_PRESCALER(x)               (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_PR_PRESCALER_SHIFT)) & WAKEUP_GPT_PR_PRESCALER_MASK)

#define WAKEUP_GPT_PR_PRESCALER24M_MASK          (0xF000U)
#define WAKEUP_GPT_PR_PRESCALER24M_SHIFT         (12U)
/*! PRESCALER24M - Prescaler Divide Value for the Oscillator Clock
 *  0b0000..Divide by 1
 *  0b0001..Divide by 2
 *  0b1111..Divide by 16
 */
#define WAKEUP_GPT_PR_PRESCALER24M(x)            (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_PR_PRESCALER24M_SHIFT)) & WAKEUP_GPT_PR_PRESCALER24M_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define WAKEUP_GPT_SR_OF1_MASK                   (0x1U)
#define WAKEUP_GPT_SR_OF1_SHIFT                  (0U)
/*! OF1 - Output Compare Flag for Channel 1
 *  0b0..Compare event has not occurred.
 *  0b1..Compare event has occurred.
 */
#define WAKEUP_GPT_SR_OF1(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_SR_OF1_SHIFT)) & WAKEUP_GPT_SR_OF1_MASK)

#define WAKEUP_GPT_SR_OF2_MASK                   (0x2U)
#define WAKEUP_GPT_SR_OF2_SHIFT                  (1U)
/*! OF2 - Output Compare Flag for Channel 2
 *  0b0..Compare event has not occurred.
 *  0b1..Compare event has occurred.
 */
#define WAKEUP_GPT_SR_OF2(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_SR_OF2_SHIFT)) & WAKEUP_GPT_SR_OF2_MASK)

#define WAKEUP_GPT_SR_OF3_MASK                   (0x4U)
#define WAKEUP_GPT_SR_OF3_SHIFT                  (2U)
/*! OF3 - Output Compare Flag for Channel 3
 *  0b0..Compare event has not occurred.
 *  0b1..Compare event has occurred.
 */
#define WAKEUP_GPT_SR_OF3(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_SR_OF3_SHIFT)) & WAKEUP_GPT_SR_OF3_MASK)

#define WAKEUP_GPT_SR_IF1_MASK                   (0x8U)
#define WAKEUP_GPT_SR_IF1_SHIFT                  (3U)
/*! IF1 - Input Capture Flag for Channel 1
 *  0b0..Capture event has not occurred.
 *  0b1..Capture event has occurred.
 */
#define WAKEUP_GPT_SR_IF1(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_SR_IF1_SHIFT)) & WAKEUP_GPT_SR_IF1_MASK)

#define WAKEUP_GPT_SR_IF2_MASK                   (0x10U)
#define WAKEUP_GPT_SR_IF2_SHIFT                  (4U)
/*! IF2 - Input Capture Flag for Channel 2
 *  0b0..Capture event has not occurred.
 *  0b1..Capture event has occurred.
 */
#define WAKEUP_GPT_SR_IF2(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_SR_IF2_SHIFT)) & WAKEUP_GPT_SR_IF2_MASK)

#define WAKEUP_GPT_SR_ROV_MASK                   (0x20U)
#define WAKEUP_GPT_SR_ROV_SHIFT                  (5U)
/*! ROV - Rollover Flag
 *  0b0..Rollover has not occurred.
 *  0b1..Rollover has occurred.
 */
#define WAKEUP_GPT_SR_ROV(x)                     (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_SR_ROV_SHIFT)) & WAKEUP_GPT_SR_ROV_MASK)
/*! @} */

/*! @name IR - Interrupt */
/*! @{ */

#define WAKEUP_GPT_IR_OF1IE_MASK                 (0x1U)
#define WAKEUP_GPT_IR_OF1IE_SHIFT                (0U)
/*! OF1IE - Output Compare Flag for Channel 1 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WAKEUP_GPT_IR_OF1IE(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_IR_OF1IE_SHIFT)) & WAKEUP_GPT_IR_OF1IE_MASK)

#define WAKEUP_GPT_IR_OF2IE_MASK                 (0x2U)
#define WAKEUP_GPT_IR_OF2IE_SHIFT                (1U)
/*! OF2IE - Output Compare Flag for Channel 2 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WAKEUP_GPT_IR_OF2IE(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_IR_OF2IE_SHIFT)) & WAKEUP_GPT_IR_OF2IE_MASK)

#define WAKEUP_GPT_IR_OF3IE_MASK                 (0x4U)
#define WAKEUP_GPT_IR_OF3IE_SHIFT                (2U)
/*! OF3IE - Output Compare Flag for Channel 3 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WAKEUP_GPT_IR_OF3IE(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_IR_OF3IE_SHIFT)) & WAKEUP_GPT_IR_OF3IE_MASK)

#define WAKEUP_GPT_IR_IF1IE_MASK                 (0x8U)
#define WAKEUP_GPT_IR_IF1IE_SHIFT                (3U)
/*! IF1IE - Input Capture Flag for Channel 1 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WAKEUP_GPT_IR_IF1IE(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_IR_IF1IE_SHIFT)) & WAKEUP_GPT_IR_IF1IE_MASK)

#define WAKEUP_GPT_IR_IF2IE_MASK                 (0x10U)
#define WAKEUP_GPT_IR_IF2IE_SHIFT                (4U)
/*! IF2IE - Input Capture Flag for Channel 2 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WAKEUP_GPT_IR_IF2IE(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_IR_IF2IE_SHIFT)) & WAKEUP_GPT_IR_IF2IE_MASK)

#define WAKEUP_GPT_IR_ROVIE_MASK                 (0x20U)
#define WAKEUP_GPT_IR_ROVIE_SHIFT                (5U)
/*! ROVIE - Rollover Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define WAKEUP_GPT_IR_ROVIE(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_IR_ROVIE_SHIFT)) & WAKEUP_GPT_IR_ROVIE_MASK)
/*! @} */

/*! @name OCR - Output Compare */
/*! @{ */

#define WAKEUP_GPT_OCR_COMP_MASK                 (0xFFFFFFFFU)
#define WAKEUP_GPT_OCR_COMP_SHIFT                (0U)
/*! COMP - Compare Value */
#define WAKEUP_GPT_OCR_COMP(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_OCR_COMP_SHIFT)) & WAKEUP_GPT_OCR_COMP_MASK)
/*! @} */

/*! @name ICR - Input Capture */
/*! @{ */

#define WAKEUP_GPT_ICR_CAPT_MASK                 (0xFFFFFFFFU)
#define WAKEUP_GPT_ICR_CAPT_SHIFT                (0U)
/*! CAPT - Capture Value */
#define WAKEUP_GPT_ICR_CAPT(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_ICR_CAPT_SHIFT)) & WAKEUP_GPT_ICR_CAPT_MASK)
/*! @} */

/*! @name CNT - Counter */
/*! @{ */

#define WAKEUP_GPT_CNT_COUNT_MASK                (0xFFFFFFFFU)
#define WAKEUP_GPT_CNT_COUNT_SHIFT               (0U)
/*! COUNT - Counter Value */
#define WAKEUP_GPT_CNT_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << WAKEUP_GPT_CNT_COUNT_SHIFT)) & WAKEUP_GPT_CNT_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WAKEUP_GPT_Register_Masks */


/*!
 * @}
 */ /* end of group WAKEUP_GPT_Peripheral_Access_Layer */


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


#endif  /* PERI_WAKEUP_GPT_H_ */

