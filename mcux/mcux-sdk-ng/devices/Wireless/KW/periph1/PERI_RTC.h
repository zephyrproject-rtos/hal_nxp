/*
** ###################################################################
**     Processors:          MKW21D256VHA5
**                          MKW21D512VHA5
**                          MKW22D512VHA5
**                          MKW24D512VHA5
**
**     Version:             rev. 2.0, 2015-01-06
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RTC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2013-11-22)
**         Initial version.
**     - rev. 2.0 (2015-01-06)
**         update of SystemInit() imlementation
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**         Register accessor macros added to the memory map.
**         MCG - bit LOLS in MCG_S register renamed to LOLS0.
**         DAC0 registers removed.
**
** ###################################################################
*/

/*!
 * @file RTC.h
 * @version 2.0
 * @date 2015-01-06
 * @brief CMSIS Peripheral Access Layer for RTC
 *
 * CMSIS Peripheral Access Layer for RTC
 */

#if !defined(RTC_H_)
#define RTC_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21D256VHA5) || defined(CPU_MKW21D512VHA5))
#include "MKW21D5_COMMON.h"
#elif (defined(CPU_MKW21D256VHA5) || defined(CPU_MKW21D512VHA5))
#include "MKW21D5WS_COMMON.h"
#elif (defined(CPU_MKW22D512VHA5))
#include "MKW22D5_COMMON.h"
#elif (defined(CPU_MKW22D512VHA5))
#include "MKW22D5WS_COMMON.h"
#elif (defined(CPU_MKW24D512VHA5))
#include "MKW24D5_COMMON.h"
#elif (defined(CPU_MKW24D512VHA5))
#include "MKW24D5WS_COMMON.h"
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
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint32_t TSR;                               /**< RTC Time Seconds Register, offset: 0x0 */
  __IO uint32_t TPR;                               /**< RTC Time Prescaler Register, offset: 0x4 */
  __IO uint32_t TAR;                               /**< RTC Time Alarm Register, offset: 0x8 */
  __IO uint32_t TCR;                               /**< RTC Time Compensation Register, offset: 0xC */
  __IO uint32_t CR;                                /**< RTC Control Register, offset: 0x10 */
  __IO uint32_t SR;                                /**< RTC Status Register, offset: 0x14 */
  __IO uint32_t LR;                                /**< RTC Lock Register, offset: 0x18 */
  __IO uint32_t IER;                               /**< RTC Interrupt Enable Register, offset: 0x1C */
  __I  uint32_t TTSR;                              /**< RTC Tamper Time Seconds Register, offset: 0x20 */
  __IO uint32_t MER;                               /**< RTC Monotonic Enable Register, offset: 0x24 */
  __IO uint32_t MCLR;                              /**< RTC Monotonic Counter Low Register, offset: 0x28 */
  __IO uint32_t MCHR;                              /**< RTC Monotonic Counter High Register, offset: 0x2C */
  __IO uint32_t TER;                               /**< RTC Tamper Enable Register, offset: 0x30, available only on: MKW21D256VHA5WS, MKW21D512VHA5WS, MKW22D512VHA5WS, MKW24D512VHA5WS */
  __IO uint32_t TDR;                               /**< RTC Tamper Detect Register, offset: 0x34, available only on: MKW21D256VHA5WS, MKW21D512VHA5WS, MKW22D512VHA5WS, MKW24D512VHA5WS */
  __IO uint32_t TTR;                               /**< RTC Tamper Trim Register, offset: 0x38, available only on: MKW21D256VHA5WS, MKW21D512VHA5WS, MKW22D512VHA5WS, MKW24D512VHA5WS */
  __IO uint32_t TIR;                               /**< RTC Tamper Interrupt Register, offset: 0x3C, available only on: MKW21D256VHA5WS, MKW21D512VHA5WS, MKW22D512VHA5WS, MKW24D512VHA5WS */
       uint8_t RESERVED_0[1984];
  __IO uint32_t WAR;                               /**< RTC Write Access Register, offset: 0x800 */
  __IO uint32_t RAR;                               /**< RTC Read Access Register, offset: 0x804 */
} RTC_Type;

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/*! @name TSR - RTC Time Seconds Register */
/*! @{ */

#define RTC_TSR_TSR_MASK                         (0xFFFFFFFFU)
#define RTC_TSR_TSR_SHIFT                        (0U)
/*! TSR - Time Seconds Register */
#define RTC_TSR_TSR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TSR_TSR_SHIFT)) & RTC_TSR_TSR_MASK)
/*! @} */

/*! @name TPR - RTC Time Prescaler Register */
/*! @{ */

#define RTC_TPR_TPR_MASK                         (0xFFFFU)
#define RTC_TPR_TPR_SHIFT                        (0U)
/*! TPR - Time Prescaler Register */
#define RTC_TPR_TPR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TPR_TPR_SHIFT)) & RTC_TPR_TPR_MASK)
/*! @} */

/*! @name TAR - RTC Time Alarm Register */
/*! @{ */

#define RTC_TAR_TAR_MASK                         (0xFFFFFFFFU)
#define RTC_TAR_TAR_SHIFT                        (0U)
/*! TAR - Time Alarm Register */
#define RTC_TAR_TAR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TAR_TAR_SHIFT)) & RTC_TAR_TAR_MASK)
/*! @} */

/*! @name TCR - RTC Time Compensation Register */
/*! @{ */

#define RTC_TCR_TCR_MASK                         (0xFFU)
#define RTC_TCR_TCR_SHIFT                        (0U)
/*! TCR - Time Compensation Register
 *  0b10000000..Time Prescaler Register overflows every 32896 clock cycles.
 *  0b11111111..Time Prescaler Register overflows every 32769 clock cycles.
 *  0b00000000..Time Prescaler Register overflows every 32768 clock cycles.
 *  0b00000001..Time Prescaler Register overflows every 32767 clock cycles.
 *  0b01111111..Time Prescaler Register overflows every 32641 clock cycles.
 */
#define RTC_TCR_TCR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TCR_TCR_SHIFT)) & RTC_TCR_TCR_MASK)

#define RTC_TCR_CIR_MASK                         (0xFF00U)
#define RTC_TCR_CIR_SHIFT                        (8U)
/*! CIR - Compensation Interval Register */
#define RTC_TCR_CIR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TCR_CIR_SHIFT)) & RTC_TCR_CIR_MASK)

#define RTC_TCR_TCV_MASK                         (0xFF0000U)
#define RTC_TCR_TCV_SHIFT                        (16U)
/*! TCV - Time Compensation Value */
#define RTC_TCR_TCV(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TCR_TCV_SHIFT)) & RTC_TCR_TCV_MASK)

#define RTC_TCR_CIC_MASK                         (0xFF000000U)
#define RTC_TCR_CIC_SHIFT                        (24U)
/*! CIC - Compensation Interval Counter */
#define RTC_TCR_CIC(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TCR_CIC_SHIFT)) & RTC_TCR_CIC_MASK)
/*! @} */

/*! @name CR - RTC Control Register */
/*! @{ */

#define RTC_CR_SWR_MASK                          (0x1U)
#define RTC_CR_SWR_SHIFT                         (0U)
/*! SWR - Software Reset
 *  0b0..No effect.
 *  0b1..Resets all RTC registers except for the SWR bit and the RTC_WAR and RTC_RAR registers . The SWR bit is
 *       cleared by POR and by software explicitly clearing it.
 */
#define RTC_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_SWR_SHIFT)) & RTC_CR_SWR_MASK)

#define RTC_CR_WPE_MASK                          (0x2U)
#define RTC_CR_WPE_SHIFT                         (1U)
/*! WPE - Wakeup Pin Enable
 *  0b0..Wakeup pin is disabled.
 *  0b1..Wakeup pin is enabled and wakeup pin asserts if the RTC interrupt asserts or the wakeup pin is turned on.
 */
#define RTC_CR_WPE(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_WPE_SHIFT)) & RTC_CR_WPE_MASK)

#define RTC_CR_SUP_MASK                          (0x4U)
#define RTC_CR_SUP_SHIFT                         (2U)
/*! SUP - Supervisor Access
 *  0b0..Non-supervisor mode write accesses are not supported and generate a bus error.
 *  0b1..Non-supervisor mode write accesses are supported.
 */
#define RTC_CR_SUP(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_SUP_SHIFT)) & RTC_CR_SUP_MASK)

#define RTC_CR_UM_MASK                           (0x8U)
#define RTC_CR_UM_SHIFT                          (3U)
/*! UM - Update Mode
 *  0b0..Registers cannot be written when locked.
 *  0b1..Registers can be written when locked under limited conditions.
 */
#define RTC_CR_UM(x)                             (((uint32_t)(((uint32_t)(x)) << RTC_CR_UM_SHIFT)) & RTC_CR_UM_MASK)

#define RTC_CR_WPS_MASK                          (0x10U)
#define RTC_CR_WPS_SHIFT                         (4U)
/*! WPS - Wakeup Pin Select */
#define RTC_CR_WPS(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_WPS_SHIFT)) & RTC_CR_WPS_MASK)

#define RTC_CR_OSCE_MASK                         (0x100U)
#define RTC_CR_OSCE_SHIFT                        (8U)
/*! OSCE - Oscillator Enable
 *  0b0..32.768 kHz oscillator is disabled.
 *  0b1..32.768 kHz oscillator is enabled. After setting this bit, wait the oscillator startup time before
 *       enabling the time counter to allow the 32.768 kHz clock time to stabilize.
 */
#define RTC_CR_OSCE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_OSCE_SHIFT)) & RTC_CR_OSCE_MASK)

#define RTC_CR_CLKO_MASK                         (0x200U)
#define RTC_CR_CLKO_SHIFT                        (9U)
/*! CLKO - Clock Output
 *  0b0..The 32 kHz clock is output to other peripherals.
 *  0b1..The 32 kHz clock is not output to other peripherals.
 */
#define RTC_CR_CLKO(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_CLKO_SHIFT)) & RTC_CR_CLKO_MASK)

#define RTC_CR_SC16P_MASK                        (0x400U)
#define RTC_CR_SC16P_SHIFT                       (10U)
/*! SC16P - Oscillator 16pF Load Configure
 *  0b0..Disable the load.
 *  0b1..Enable the additional load.
 */
#define RTC_CR_SC16P(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_CR_SC16P_SHIFT)) & RTC_CR_SC16P_MASK)

#define RTC_CR_SC8P_MASK                         (0x800U)
#define RTC_CR_SC8P_SHIFT                        (11U)
/*! SC8P - Oscillator 8pF Load Configure
 *  0b0..Disable the load.
 *  0b1..Enable the additional load.
 */
#define RTC_CR_SC8P(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_SC8P_SHIFT)) & RTC_CR_SC8P_MASK)

#define RTC_CR_SC4P_MASK                         (0x1000U)
#define RTC_CR_SC4P_SHIFT                        (12U)
/*! SC4P - Oscillator 4pF Load Configure
 *  0b0..Disable the load.
 *  0b1..Enable the additional load.
 */
#define RTC_CR_SC4P(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_SC4P_SHIFT)) & RTC_CR_SC4P_MASK)

#define RTC_CR_SC2P_MASK                         (0x2000U)
#define RTC_CR_SC2P_SHIFT                        (13U)
/*! SC2P - Oscillator 2pF Load Configure
 *  0b0..Disable the load.
 *  0b1..Enable the additional load.
 */
#define RTC_CR_SC2P(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_SC2P_SHIFT)) & RTC_CR_SC2P_MASK)
/*! @} */

/*! @name SR - RTC Status Register */
/*! @{ */

#define RTC_SR_TIF_MASK                          (0x1U)
#define RTC_SR_TIF_SHIFT                         (0U)
/*! TIF - Time Invalid Flag
 *  0b0..Time is valid.
 *  0b1..Time is invalid and time counter is read as zero.
 */
#define RTC_SR_TIF(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_SR_TIF_SHIFT)) & RTC_SR_TIF_MASK)

#define RTC_SR_TOF_MASK                          (0x2U)
#define RTC_SR_TOF_SHIFT                         (1U)
/*! TOF - Time Overflow Flag
 *  0b0..Time overflow has not occurred.
 *  0b1..Time overflow has occurred and time counter is read as zero.
 */
#define RTC_SR_TOF(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_SR_TOF_SHIFT)) & RTC_SR_TOF_MASK)

#define RTC_SR_TAF_MASK                          (0x4U)
#define RTC_SR_TAF_SHIFT                         (2U)
/*! TAF - Time Alarm Flag
 *  0b0..Time alarm has not occurred.
 *  0b1..Time alarm has occurred.
 */
#define RTC_SR_TAF(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_SR_TAF_SHIFT)) & RTC_SR_TAF_MASK)

#define RTC_SR_MOF_MASK                          (0x8U)
#define RTC_SR_MOF_SHIFT                         (3U)
/*! MOF - Monotonic Overflow Flag
 *  0b0..Monotonic counter overflow has not occurred.
 *  0b1..Monotonic counter overflow has occurred and monotonic counter is read as zero.
 */
#define RTC_SR_MOF(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_SR_MOF_SHIFT)) & RTC_SR_MOF_MASK)

#define RTC_SR_TCE_MASK                          (0x10U)
#define RTC_SR_TCE_SHIFT                         (4U)
/*! TCE - Time Counter Enable
 *  0b0..Time counter is disabled.
 *  0b1..Time counter is enabled.
 */
#define RTC_SR_TCE(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_SR_TCE_SHIFT)) & RTC_SR_TCE_MASK)
/*! @} */

/*! @name LR - RTC Lock Register */
/*! @{ */

#define RTC_LR_TCL_MASK                          (0x8U)
#define RTC_LR_TCL_SHIFT                         (3U)
/*! TCL - Time Compensation Lock
 *  0b0..Time Compensation Register is locked and writes are ignored.
 *  0b1..Time Compensation Register is not locked and writes complete as normal.
 */
#define RTC_LR_TCL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_TCL_SHIFT)) & RTC_LR_TCL_MASK)

#define RTC_LR_CRL_MASK                          (0x10U)
#define RTC_LR_CRL_SHIFT                         (4U)
/*! CRL - Control Register Lock
 *  0b0..Control Register is locked and writes are ignored.
 *  0b1..Control Register is not locked and writes complete as normal.
 */
#define RTC_LR_CRL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_CRL_SHIFT)) & RTC_LR_CRL_MASK)

#define RTC_LR_SRL_MASK                          (0x20U)
#define RTC_LR_SRL_SHIFT                         (5U)
/*! SRL - Status Register Lock
 *  0b0..Status Register is locked and writes are ignored.
 *  0b1..Status Register is not locked and writes complete as normal.
 */
#define RTC_LR_SRL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_SRL_SHIFT)) & RTC_LR_SRL_MASK)

#define RTC_LR_LRL_MASK                          (0x40U)
#define RTC_LR_LRL_SHIFT                         (6U)
/*! LRL - Lock Register Lock
 *  0b0..Lock Register is locked and writes are ignored.
 *  0b1..Lock Register is not locked and writes complete as normal.
 */
#define RTC_LR_LRL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_LRL_SHIFT)) & RTC_LR_LRL_MASK)

#define RTC_LR_TTSL_MASK                         (0x100U)
#define RTC_LR_TTSL_SHIFT                        (8U)
/*! TTSL - Tamper Time Seconds Lock
 *  0b0..Tamper Time Seconds Register is locked and writes are ignored.
 *  0b1..Tamper Time Seconds Register is not locked and writes complete as normal.
 */
#define RTC_LR_TTSL(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_LR_TTSL_SHIFT)) & RTC_LR_TTSL_MASK)

#define RTC_LR_MEL_MASK                          (0x200U)
#define RTC_LR_MEL_SHIFT                         (9U)
/*! MEL - Monotonic Enable Lock
 *  0b0..Monotonic Enable Register is locked and writes are ignored.
 *  0b1..Monotonic Enable Register is not locked and writes complete as normal.
 */
#define RTC_LR_MEL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_MEL_SHIFT)) & RTC_LR_MEL_MASK)

#define RTC_LR_MCLL_MASK                         (0x400U)
#define RTC_LR_MCLL_SHIFT                        (10U)
/*! MCLL - Monotonic Counter Low Lock
 *  0b0..Monotonic Counter Low Register is locked and writes are ignored.
 *  0b1..Monotonic Counter Low Register is not locked and writes complete as normal.
 */
#define RTC_LR_MCLL(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_LR_MCLL_SHIFT)) & RTC_LR_MCLL_MASK)

#define RTC_LR_MCHL_MASK                         (0x800U)
#define RTC_LR_MCHL_SHIFT                        (11U)
/*! MCHL - Monotonic Counter High Lock
 *  0b0..Monotonic Counter High Register is locked and writes are ignored.
 *  0b1..Monotonic Counter High Register is not locked and writes complete as normal.
 */
#define RTC_LR_MCHL(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_LR_MCHL_SHIFT)) & RTC_LR_MCHL_MASK)

#define RTC_LR_TEL_MASK                          (0x1000U)
#define RTC_LR_TEL_SHIFT                         (12U)
/*! TEL - Tamper Enable Lock
 *  0b0..Tamper Enable Register is locked and writes are ignored.
 *  0b1..Tamper Enable Register is not locked and writes complete as normal.
 */
#define RTC_LR_TEL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_TEL_SHIFT)) & RTC_LR_TEL_MASK)

#define RTC_LR_TDL_MASK                          (0x2000U)
#define RTC_LR_TDL_SHIFT                         (13U)
/*! TDL - Tamper Detect Lock
 *  0b0..Tamper Detect Register is locked and writes are ignored.
 *  0b1..Tamper Detect Register is not locked and writes complete as normal.
 */
#define RTC_LR_TDL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_TDL_SHIFT)) & RTC_LR_TDL_MASK)

#define RTC_LR_TTL_MASK                          (0x4000U)
#define RTC_LR_TTL_SHIFT                         (14U)
/*! TTL - Tamper Trim Lock
 *  0b0..Tamper Trim Register is locked and writes are ignored.
 *  0b1..Tamper Trim Register is not locked and writes complete as normal.
 */
#define RTC_LR_TTL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_TTL_SHIFT)) & RTC_LR_TTL_MASK)

#define RTC_LR_TIL_MASK                          (0x8000U)
#define RTC_LR_TIL_SHIFT                         (15U)
/*! TIL - Tamper Interrupt Lock
 *  0b0..Tamper Interrupt Register is locked and writes are ignored.
 *  0b1..Tamper Interrupt Register is not locked and writes complete as normal.
 */
#define RTC_LR_TIL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_TIL_SHIFT)) & RTC_LR_TIL_MASK)
/*! @} */

/*! @name IER - RTC Interrupt Enable Register */
/*! @{ */

#define RTC_IER_TIIE_MASK                        (0x1U)
#define RTC_IER_TIIE_SHIFT                       (0U)
/*! TIIE - Time Invalid Interrupt Enable
 *  0b0..Time invalid flag does not generate an interrupt.
 *  0b1..Time invalid flag does generate an interrupt.
 */
#define RTC_IER_TIIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_TIIE_SHIFT)) & RTC_IER_TIIE_MASK)

#define RTC_IER_TOIE_MASK                        (0x2U)
#define RTC_IER_TOIE_SHIFT                       (1U)
/*! TOIE - Time Overflow Interrupt Enable
 *  0b0..Time overflow flag does not generate an interrupt.
 *  0b1..Time overflow flag does generate an interrupt.
 */
#define RTC_IER_TOIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_TOIE_SHIFT)) & RTC_IER_TOIE_MASK)

#define RTC_IER_TAIE_MASK                        (0x4U)
#define RTC_IER_TAIE_SHIFT                       (2U)
/*! TAIE - Time Alarm Interrupt Enable
 *  0b0..Time alarm flag does not generate an interrupt.
 *  0b1..Time alarm flag does generate an interrupt.
 */
#define RTC_IER_TAIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_TAIE_SHIFT)) & RTC_IER_TAIE_MASK)

#define RTC_IER_MOIE_MASK                        (0x8U)
#define RTC_IER_MOIE_SHIFT                       (3U)
/*! MOIE - Monotonic Overflow Interrupt Enable
 *  0b0..Monotonic overflow flag does not generate an interrupt.
 *  0b1..Monotonic overflow flag does generate an interrupt.
 */
#define RTC_IER_MOIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_MOIE_SHIFT)) & RTC_IER_MOIE_MASK)

#define RTC_IER_TSIE_MASK                        (0x10U)
#define RTC_IER_TSIE_SHIFT                       (4U)
/*! TSIE - Time Seconds Interrupt Enable
 *  0b0..Seconds interrupt is disabled.
 *  0b1..Seconds interrupt is enabled.
 */
#define RTC_IER_TSIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_TSIE_SHIFT)) & RTC_IER_TSIE_MASK)

#define RTC_IER_WPON_MASK                        (0x80U)
#define RTC_IER_WPON_SHIFT                       (7U)
/*! WPON - Wakeup Pin On
 *  0b0..No effect.
 *  0b1..If the wakeup pin is enabled, then the wakeup pin will assert.
 */
#define RTC_IER_WPON(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_WPON_SHIFT)) & RTC_IER_WPON_MASK)
/*! @} */

/*! @name TTSR - RTC Tamper Time Seconds Register */
/*! @{ */

#define RTC_TTSR_TTS_MASK                        (0xFFFFFFFFU)
#define RTC_TTSR_TTS_SHIFT                       (0U)
/*! TTS - Tamper Time Seconds */
#define RTC_TTSR_TTS(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TTSR_TTS_SHIFT)) & RTC_TTSR_TTS_MASK)
/*! @} */

/*! @name MER - RTC Monotonic Enable Register */
/*! @{ */

#define RTC_MER_MCE_MASK                         (0x10U)
#define RTC_MER_MCE_SHIFT                        (4U)
/*! MCE - Monotonic Counter Enable
 *  0b0..Writes to the monotonic counter load the counter with the value written.
 *  0b1..Writes to the monotonic counter increment the counter.
 */
#define RTC_MER_MCE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_MER_MCE_SHIFT)) & RTC_MER_MCE_MASK)
/*! @} */

/*! @name MCLR - RTC Monotonic Counter Low Register */
/*! @{ */

#define RTC_MCLR_MCL_MASK                        (0xFFFFFFFFU)
#define RTC_MCLR_MCL_SHIFT                       (0U)
/*! MCL - Monotonic Counter Low */
#define RTC_MCLR_MCL(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_MCLR_MCL_SHIFT)) & RTC_MCLR_MCL_MASK)
/*! @} */

/*! @name MCHR - RTC Monotonic Counter High Register */
/*! @{ */

#define RTC_MCHR_MCH_MASK                        (0xFFFFFFFFU)
#define RTC_MCHR_MCH_SHIFT                       (0U)
/*! MCH - Monotonic Counter High */
#define RTC_MCHR_MCH(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_MCHR_MCH_SHIFT)) & RTC_MCHR_MCH_MASK)
/*! @} */

/*! @name TER - RTC Tamper Enable Register */
/*! @{ */

#define RTC_TER_DTE_MASK                         (0x1U)
#define RTC_TER_DTE_SHIFT                        (0U)
/*! DTE - DryIce Tamper Enable
 *  0b0..Tamper source disabled.
 *  0b1..Set the time invalid flag if the DryIce tamper flag is set.
 */
#define RTC_TER_DTE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TER_DTE_SHIFT)) & RTC_TER_DTE_MASK)

#define RTC_TER_VTE_MASK                         (0x2U)
#define RTC_TER_VTE_SHIFT                        (1U)
/*! VTE - Voltage Tamper Enable
 *  0b0..Tamper source disabled.
 *  0b1..Set the time invalid flag if the voltage tamper flag is set.
 */
#define RTC_TER_VTE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TER_VTE_SHIFT)) & RTC_TER_VTE_MASK)

#define RTC_TER_CTE_MASK                         (0x4U)
#define RTC_TER_CTE_SHIFT                        (2U)
/*! CTE - Clock Tamper Enable
 *  0b0..Tamper source disabled.
 *  0b1..Set the time invalid flag if the clock tamper flag is set.
 */
#define RTC_TER_CTE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TER_CTE_SHIFT)) & RTC_TER_CTE_MASK)

#define RTC_TER_TTE_MASK                         (0x8U)
#define RTC_TER_TTE_SHIFT                        (3U)
/*! TTE - Temperature Tamper Enable
 *  0b0..Tamper source disabled.
 *  0b1..Set the time invalid flag if the temperature tamper flag is set.
 */
#define RTC_TER_TTE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TER_TTE_SHIFT)) & RTC_TER_TTE_MASK)

#define RTC_TER_FSE_MASK                         (0x10U)
#define RTC_TER_FSE_SHIFT                        (4U)
/*! FSE - Flash Security Enable
 *  0b0..Tamper source disabled.
 *  0b1..Set the time invalid flag if the flash security flag is set.
 */
#define RTC_TER_FSE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TER_FSE_SHIFT)) & RTC_TER_FSE_MASK)

#define RTC_TER_TME_MASK                         (0x20U)
#define RTC_TER_TME_SHIFT                        (5U)
/*! TME - Test Mode Enable
 *  0b0..Tamper source disabled.
 *  0b1..Set the time invalid flag if the test mode flag is set.
 */
#define RTC_TER_TME(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TER_TME_SHIFT)) & RTC_TER_TME_MASK)
/*! @} */

/*! @name TDR - RTC Tamper Detect Register */
/*! @{ */

#define RTC_TDR_DTF_MASK                         (0x1U)
#define RTC_TDR_DTF_SHIFT                        (0U)
/*! DTF - DryIce Tamper Flag
 *  0b0..Tamper not detected.
 *  0b1..DryIce tamper detected.
 */
#define RTC_TDR_DTF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TDR_DTF_SHIFT)) & RTC_TDR_DTF_MASK)

#define RTC_TDR_VTF_MASK                         (0x2U)
#define RTC_TDR_VTF_SHIFT                        (1U)
/*! VTF - Voltage Tamper Flag
 *  0b0..Tamper not detected.
 *  0b1..Voltage tampering detected.
 */
#define RTC_TDR_VTF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TDR_VTF_SHIFT)) & RTC_TDR_VTF_MASK)

#define RTC_TDR_CTF_MASK                         (0x4U)
#define RTC_TDR_CTF_SHIFT                        (2U)
/*! CTF - Clock Tamper Flag
 *  0b0..Tamper not detected.
 *  0b1..Clock tampering detected.
 */
#define RTC_TDR_CTF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TDR_CTF_SHIFT)) & RTC_TDR_CTF_MASK)

#define RTC_TDR_TTF_MASK                         (0x8U)
#define RTC_TDR_TTF_SHIFT                        (3U)
/*! TTF - Temperature Tamper Flag
 *  0b0..Tamper not detected.
 *  0b1..Temperature tampering detected.
 */
#define RTC_TDR_TTF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TDR_TTF_SHIFT)) & RTC_TDR_TTF_MASK)

#define RTC_TDR_FSF_MASK                         (0x10U)
#define RTC_TDR_FSF_SHIFT                        (4U)
/*! FSF - Flash Security Flag
 *  0b0..Tamper not detected.
 *  0b1..Flash security tamper detected.
 */
#define RTC_TDR_FSF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TDR_FSF_SHIFT)) & RTC_TDR_FSF_MASK)

#define RTC_TDR_TMF_MASK                         (0x20U)
#define RTC_TDR_TMF_SHIFT                        (5U)
/*! TMF - Test Mode Flag
 *  0b0..Tamper not detected.
 *  0b1..Test mode tamper detected.
 */
#define RTC_TDR_TMF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TDR_TMF_SHIFT)) & RTC_TDR_TMF_MASK)
/*! @} */

/*! @name TTR - RTC Tamper Trim Register */
/*! @{ */

#define RTC_TTR_VDTL_MASK                        (0x7U)
#define RTC_TTR_VDTL_SHIFT                       (0U)
/*! VDTL - Voltage Detect Trim Low */
#define RTC_TTR_VDTL(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TTR_VDTL_SHIFT)) & RTC_TTR_VDTL_MASK)

#define RTC_TTR_VDTH_MASK                        (0x38U)
#define RTC_TTR_VDTH_SHIFT                       (3U)
/*! VDTH - Voltage Detect Trim High */
#define RTC_TTR_VDTH(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TTR_VDTH_SHIFT)) & RTC_TTR_VDTH_MASK)

#define RTC_TTR_CDTL_MASK                        (0x1C0U)
#define RTC_TTR_CDTL_SHIFT                       (6U)
/*! CDTL - Clock Detect Trim Low */
#define RTC_TTR_CDTL(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TTR_CDTL_SHIFT)) & RTC_TTR_CDTL_MASK)

#define RTC_TTR_CDTH_MASK                        (0xE00U)
#define RTC_TTR_CDTH_SHIFT                       (9U)
/*! CDTH - Clock Detect Trim High */
#define RTC_TTR_CDTH(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TTR_CDTH_SHIFT)) & RTC_TTR_CDTH_MASK)

#define RTC_TTR_TDTH_MASK                        (0x7000U)
#define RTC_TTR_TDTH_SHIFT                       (12U)
/*! TDTH - Temperature Detect Trim High */
#define RTC_TTR_TDTH(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TTR_TDTH_SHIFT)) & RTC_TTR_TDTH_MASK)

#define RTC_TTR_TDTL_MASK                        (0x38000U)
#define RTC_TTR_TDTL_SHIFT                       (15U)
/*! TDTL - Temperature Detect Trim Low */
#define RTC_TTR_TDTL(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TTR_TDTL_SHIFT)) & RTC_TTR_TDTL_MASK)
/*! @} */

/*! @name TIR - RTC Tamper Interrupt Register */
/*! @{ */

#define RTC_TIR_DTIE_MASK                        (0x1U)
#define RTC_TIR_DTIE_SHIFT                       (0U)
/*! DTIE - DryIce Tamper Interrupt Enable
 *  0b0..Interupt disabled.
 *  0b1..An interrupt is generated when DryIce tamper flag is set.
 */
#define RTC_TIR_DTIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TIR_DTIE_SHIFT)) & RTC_TIR_DTIE_MASK)

#define RTC_TIR_VTIE_MASK                        (0x2U)
#define RTC_TIR_VTIE_SHIFT                       (1U)
/*! VTIE - Voltage Tamper Interrupt Enable
 *  0b0..Interupt disabled.
 *  0b1..An interrupt is generated when the voltage tamper flag is set.
 */
#define RTC_TIR_VTIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TIR_VTIE_SHIFT)) & RTC_TIR_VTIE_MASK)

#define RTC_TIR_CTIE_MASK                        (0x4U)
#define RTC_TIR_CTIE_SHIFT                       (2U)
/*! CTIE - Clock Tamper Interrupt Enable
 *  0b0..Interupt disabled.
 *  0b1..An interrupt is generated when the clock tamper flag is set.
 */
#define RTC_TIR_CTIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TIR_CTIE_SHIFT)) & RTC_TIR_CTIE_MASK)

#define RTC_TIR_TTIE_MASK                        (0x8U)
#define RTC_TIR_TTIE_SHIFT                       (3U)
/*! TTIE - Temperature Tamper Interrupt Enable
 *  0b0..Interupt disabled.
 *  0b1..An interrupt is generated when the temperature tamper flag is set.
 */
#define RTC_TIR_TTIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TIR_TTIE_SHIFT)) & RTC_TIR_TTIE_MASK)

#define RTC_TIR_FSIE_MASK                        (0x10U)
#define RTC_TIR_FSIE_SHIFT                       (4U)
/*! FSIE - Flash Security Interrupt Enable
 *  0b0..Interupt disabled.
 *  0b1..An interrupt is generated when the flash security flag is set.
 */
#define RTC_TIR_FSIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TIR_FSIE_SHIFT)) & RTC_TIR_FSIE_MASK)

#define RTC_TIR_TMIE_MASK                        (0x20U)
#define RTC_TIR_TMIE_SHIFT                       (5U)
/*! TMIE - Test Mode Interrupt Enable
 *  0b0..Interupt disabled.
 *  0b1..An interrupt is generated when the test mode flag is set.
 */
#define RTC_TIR_TMIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TIR_TMIE_SHIFT)) & RTC_TIR_TMIE_MASK)
/*! @} */

/*! @name WAR - RTC Write Access Register */
/*! @{ */

#define RTC_WAR_TSRW_MASK                        (0x1U)
#define RTC_WAR_TSRW_SHIFT                       (0U)
/*! TSRW - Time Seconds Register Write
 *  0b0..Writes to the Time Seconds Register are ignored.
 *  0b1..Writes to the Time Seconds Register complete as normal.
 */
#define RTC_WAR_TSRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TSRW_SHIFT)) & RTC_WAR_TSRW_MASK)

#define RTC_WAR_TPRW_MASK                        (0x2U)
#define RTC_WAR_TPRW_SHIFT                       (1U)
/*! TPRW - Time Prescaler Register Write
 *  0b0..Writes to the Time Prescaler Register are ignored.
 *  0b1..Writes to the Time Prescaler Register complete as normal.
 */
#define RTC_WAR_TPRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TPRW_SHIFT)) & RTC_WAR_TPRW_MASK)

#define RTC_WAR_TARW_MASK                        (0x4U)
#define RTC_WAR_TARW_SHIFT                       (2U)
/*! TARW - Time Alarm Register Write
 *  0b0..Writes to the Time Alarm Register are ignored.
 *  0b1..Writes to the Time Alarm Register complete as normal.
 */
#define RTC_WAR_TARW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TARW_SHIFT)) & RTC_WAR_TARW_MASK)

#define RTC_WAR_TCRW_MASK                        (0x8U)
#define RTC_WAR_TCRW_SHIFT                       (3U)
/*! TCRW - Time Compensation Register Write
 *  0b0..Writes to the Time Compensation Register are ignored.
 *  0b1..Writes to the Time Compensation Register complete as normal.
 */
#define RTC_WAR_TCRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TCRW_SHIFT)) & RTC_WAR_TCRW_MASK)

#define RTC_WAR_CRW_MASK                         (0x10U)
#define RTC_WAR_CRW_SHIFT                        (4U)
/*! CRW - Control Register Write
 *  0b0..Writes to the Control Register are ignored.
 *  0b1..Writes to the Control Register complete as normal.
 */
#define RTC_WAR_CRW(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_WAR_CRW_SHIFT)) & RTC_WAR_CRW_MASK)

#define RTC_WAR_SRW_MASK                         (0x20U)
#define RTC_WAR_SRW_SHIFT                        (5U)
/*! SRW - Status Register Write
 *  0b0..Writes to the Status Register are ignored.
 *  0b1..Writes to the Status Register complete as normal.
 */
#define RTC_WAR_SRW(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_WAR_SRW_SHIFT)) & RTC_WAR_SRW_MASK)

#define RTC_WAR_LRW_MASK                         (0x40U)
#define RTC_WAR_LRW_SHIFT                        (6U)
/*! LRW - Lock Register Write
 *  0b0..Writes to the Lock Register are ignored.
 *  0b1..Writes to the Lock Register complete as normal.
 */
#define RTC_WAR_LRW(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_WAR_LRW_SHIFT)) & RTC_WAR_LRW_MASK)

#define RTC_WAR_IERW_MASK                        (0x80U)
#define RTC_WAR_IERW_SHIFT                       (7U)
/*! IERW - Interrupt Enable Register Write
 *  0b0..Writes to the Interupt Enable Register are ignored.
 *  0b1..Writes to the Interrupt Enable Register complete as normal.
 */
#define RTC_WAR_IERW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_IERW_SHIFT)) & RTC_WAR_IERW_MASK)

#define RTC_WAR_TTSW_MASK                        (0x100U)
#define RTC_WAR_TTSW_SHIFT                       (8U)
/*! TTSW - Tamper Time Seconds Write
 *  0b0..Writes to the Tamper Time Seconds Register are ignored.
 *  0b1..Writes to the Tamper Time Seconds Register complete as normal.
 */
#define RTC_WAR_TTSW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TTSW_SHIFT)) & RTC_WAR_TTSW_MASK)

#define RTC_WAR_MERW_MASK                        (0x200U)
#define RTC_WAR_MERW_SHIFT                       (9U)
/*! MERW - Monotonic Enable Register Write
 *  0b0..Writes to the Monotonic Enable Register are ignored.
 *  0b1..Writes to the Monotonic Enable Register complete as normal.
 */
#define RTC_WAR_MERW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_MERW_SHIFT)) & RTC_WAR_MERW_MASK)

#define RTC_WAR_MCLW_MASK                        (0x400U)
#define RTC_WAR_MCLW_SHIFT                       (10U)
/*! MCLW - Monotonic Counter Low Write
 *  0b0..Writes to the Monotonic Counter Low Register are ignored.
 *  0b1..Writes to the Monotonic Counter Low Register complete as normal.
 */
#define RTC_WAR_MCLW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_MCLW_SHIFT)) & RTC_WAR_MCLW_MASK)

#define RTC_WAR_MCHW_MASK                        (0x800U)
#define RTC_WAR_MCHW_SHIFT                       (11U)
/*! MCHW - Monotonic Counter High Write
 *  0b0..Writes to the Monotonic Counter High Register are ignored.
 *  0b1..Writes to the Monotonic Counter High Register complete as normal.
 */
#define RTC_WAR_MCHW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_MCHW_SHIFT)) & RTC_WAR_MCHW_MASK)

#define RTC_WAR_TERW_MASK                        (0x1000U)
#define RTC_WAR_TERW_SHIFT                       (12U)
/*! TERW - Tamper Enable Register Write
 *  0b0..Writes to the Tamper Enable Register are ignored.
 *  0b1..Writes to the Tamper Enable Register complete as normal.
 */
#define RTC_WAR_TERW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TERW_SHIFT)) & RTC_WAR_TERW_MASK)

#define RTC_WAR_TDRW_MASK                        (0x2000U)
#define RTC_WAR_TDRW_SHIFT                       (13U)
/*! TDRW - Tamper Detect Register Write
 *  0b0..Writes to the Tamper Detect Register are ignored.
 *  0b1..Writes to the Tamper Detect Register complete as normal.
 */
#define RTC_WAR_TDRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TDRW_SHIFT)) & RTC_WAR_TDRW_MASK)

#define RTC_WAR_TTRW_MASK                        (0x4000U)
#define RTC_WAR_TTRW_SHIFT                       (14U)
/*! TTRW - Tamper Trim Register Write
 *  0b0..Writes to the Tamper Trim Register are ignored.
 *  0b1..Writes to the Tamper Trim Register complete as normal.
 */
#define RTC_WAR_TTRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TTRW_SHIFT)) & RTC_WAR_TTRW_MASK)

#define RTC_WAR_TIRW_MASK                        (0x8000U)
#define RTC_WAR_TIRW_SHIFT                       (15U)
/*! TIRW - Tamper Interrupt Register Write
 *  0b0..Writes to the Tamper Interrupt Register are ignored.
 *  0b1..Writes to the Tamper Interrupt Register complete as normal.
 */
#define RTC_WAR_TIRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TIRW_SHIFT)) & RTC_WAR_TIRW_MASK)
/*! @} */

/*! @name RAR - RTC Read Access Register */
/*! @{ */

#define RTC_RAR_TSRR_MASK                        (0x1U)
#define RTC_RAR_TSRR_SHIFT                       (0U)
/*! TSRR - Time Seconds Register Read
 *  0b0..Reads to the Time Seconds Register are ignored.
 *  0b1..Reads to the Time Seconds Register complete as normal.
 */
#define RTC_RAR_TSRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TSRR_SHIFT)) & RTC_RAR_TSRR_MASK)

#define RTC_RAR_TPRR_MASK                        (0x2U)
#define RTC_RAR_TPRR_SHIFT                       (1U)
/*! TPRR - Time Prescaler Register Read
 *  0b0..Reads to the Time Pprescaler Register are ignored.
 *  0b1..Reads to the Time Prescaler Register complete as normal.
 */
#define RTC_RAR_TPRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TPRR_SHIFT)) & RTC_RAR_TPRR_MASK)

#define RTC_RAR_TARR_MASK                        (0x4U)
#define RTC_RAR_TARR_SHIFT                       (2U)
/*! TARR - Time Alarm Register Read
 *  0b0..Reads to the Time Alarm Register are ignored.
 *  0b1..Reads to the Time Alarm Register complete as normal.
 */
#define RTC_RAR_TARR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TARR_SHIFT)) & RTC_RAR_TARR_MASK)

#define RTC_RAR_TCRR_MASK                        (0x8U)
#define RTC_RAR_TCRR_SHIFT                       (3U)
/*! TCRR - Time Compensation Register Read
 *  0b0..Reads to the Time Compensation Register are ignored.
 *  0b1..Reads to the Time Compensation Register complete as normal.
 */
#define RTC_RAR_TCRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TCRR_SHIFT)) & RTC_RAR_TCRR_MASK)

#define RTC_RAR_CRR_MASK                         (0x10U)
#define RTC_RAR_CRR_SHIFT                        (4U)
/*! CRR - Control Register Read
 *  0b0..Reads to the Control Register are ignored.
 *  0b1..Reads to the Control Register complete as normal.
 */
#define RTC_RAR_CRR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_RAR_CRR_SHIFT)) & RTC_RAR_CRR_MASK)

#define RTC_RAR_SRR_MASK                         (0x20U)
#define RTC_RAR_SRR_SHIFT                        (5U)
/*! SRR - Status Register Read
 *  0b0..Reads to the Status Register are ignored.
 *  0b1..Reads to the Status Register complete as normal.
 */
#define RTC_RAR_SRR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_RAR_SRR_SHIFT)) & RTC_RAR_SRR_MASK)

#define RTC_RAR_LRR_MASK                         (0x40U)
#define RTC_RAR_LRR_SHIFT                        (6U)
/*! LRR - Lock Register Read
 *  0b0..Reads to the Lock Register are ignored.
 *  0b1..Reads to the Lock Register complete as normal.
 */
#define RTC_RAR_LRR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_RAR_LRR_SHIFT)) & RTC_RAR_LRR_MASK)

#define RTC_RAR_IERR_MASK                        (0x80U)
#define RTC_RAR_IERR_SHIFT                       (7U)
/*! IERR - Interrupt Enable Register Read
 *  0b0..Reads to the Interrupt Enable Register are ignored.
 *  0b1..Reads to the Interrupt Enable Register complete as normal.
 */
#define RTC_RAR_IERR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_IERR_SHIFT)) & RTC_RAR_IERR_MASK)

#define RTC_RAR_TTSR_MASK                        (0x100U)
#define RTC_RAR_TTSR_SHIFT                       (8U)
/*! TTSR - Tamper Time Seconds Read
 *  0b0..Reads to the Tamper Time Seconds Register are ignored.
 *  0b1..Reads to the Tamper Time Seconds Register complete as normal.
 */
#define RTC_RAR_TTSR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TTSR_SHIFT)) & RTC_RAR_TTSR_MASK)

#define RTC_RAR_MERR_MASK                        (0x200U)
#define RTC_RAR_MERR_SHIFT                       (9U)
/*! MERR - Monotonic Enable Register Read
 *  0b0..Reads to the Monotonic Enable Register are ignored.
 *  0b1..Reads to the Monotonic Enable Register complete as normal.
 */
#define RTC_RAR_MERR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_MERR_SHIFT)) & RTC_RAR_MERR_MASK)

#define RTC_RAR_MCLR_MASK                        (0x400U)
#define RTC_RAR_MCLR_SHIFT                       (10U)
/*! MCLR - Monotonic Counter Low Read
 *  0b0..Reads to the Monotonic Counter Low Register are ignored.
 *  0b1..Reads to the Monotonic Counter Low Register complete as normal.
 */
#define RTC_RAR_MCLR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_MCLR_SHIFT)) & RTC_RAR_MCLR_MASK)

#define RTC_RAR_MCHR_MASK                        (0x800U)
#define RTC_RAR_MCHR_SHIFT                       (11U)
/*! MCHR - Monotonic Counter High Read
 *  0b0..Reads to the Monotonic Counter High Register are ignored.
 *  0b1..Reads to the Monotonic Counter High Register complete as normal.
 */
#define RTC_RAR_MCHR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_MCHR_SHIFT)) & RTC_RAR_MCHR_MASK)

#define RTC_RAR_TERR_MASK                        (0x1000U)
#define RTC_RAR_TERR_SHIFT                       (12U)
/*! TERR - Tamper Enable Register Read
 *  0b0..Reads to the Tamper Enable Register are ignored.
 *  0b1..Reads to the Tamper Enable Register complete as normal.
 */
#define RTC_RAR_TERR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TERR_SHIFT)) & RTC_RAR_TERR_MASK)

#define RTC_RAR_TDRR_MASK                        (0x2000U)
#define RTC_RAR_TDRR_SHIFT                       (13U)
/*! TDRR - Tamper Detect Register Read
 *  0b0..Reads to the Tamper Detect Register are ignored.
 *  0b1..Reads to the Tamper Detect Register complete as normal.
 */
#define RTC_RAR_TDRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TDRR_SHIFT)) & RTC_RAR_TDRR_MASK)

#define RTC_RAR_TTRR_MASK                        (0x4000U)
#define RTC_RAR_TTRR_SHIFT                       (14U)
/*! TTRR - Tamper Trim Register Read
 *  0b0..Reads to the Tamper Trim Register are ignored.
 *  0b1..Reads to the Tamper Trim Register complete as normal.
 */
#define RTC_RAR_TTRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TTRR_SHIFT)) & RTC_RAR_TTRR_MASK)

#define RTC_RAR_TIRR_MASK                        (0x8000U)
#define RTC_RAR_TIRR_SHIFT                       (15U)
/*! TIRR - Tamper Interrupt Register Read
 *  0b0..Reads to the Tamper Interrupt Register are ignored.
 *  0b1..Reads to the Tamper Interrupt Register complete as normal.
 */
#define RTC_RAR_TIRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TIRR_SHIFT)) & RTC_RAR_TIRR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RTC_Register_Masks */


/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */


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


#endif  /* RTC_H_ */

