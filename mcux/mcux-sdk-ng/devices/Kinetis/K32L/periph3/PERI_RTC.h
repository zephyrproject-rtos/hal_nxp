/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RTC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RTC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RTC
 *
 * CMSIS Peripheral Access Layer for RTC
 */

#if !defined(PERI_RTC_H_)
#define PERI_RTC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Size of Registers Arrays */
#define RTC_PCR_COUNT                             4u

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
       uint8_t RESERVED_0[4];
  __IO uint32_t TDR;                               /**< RTC Tamper Detect Register, offset: 0x34 */
       uint8_t RESERVED_1[4];
  __IO uint32_t TIR;                               /**< RTC Tamper Interrupt Register, offset: 0x3C */
  __IO uint32_t PCR[RTC_PCR_COUNT];                /**< RTC Pin Configuration Register, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_2[1968];
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
 *  0b00000000..Time Prescaler Register overflows every 32768 clock cycles.
 *  0b00000001..Time Prescaler Register overflows every 32767 clock cycles.
 *  0b01111110..Time Prescaler Register overflows every 32642 clock cycles.
 *  0b01111111..Time Prescaler Register overflows every 32641 clock cycles.
 *  0b10000000..Time Prescaler Register overflows every 32896 clock cycles.
 *  0b10000001..Time Prescaler Register overflows every 32895 clock cycles.
 *  0b11111111..Time Prescaler Register overflows every 32769 clock cycles.
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
 *       cleared by VBAT POR and by software explicitly clearing it.
 */
#define RTC_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_SWR_SHIFT)) & RTC_CR_SWR_MASK)

#define RTC_CR_WPE_MASK                          (0x2U)
#define RTC_CR_WPE_SHIFT                         (1U)
/*! WPE - Wakeup Pin Enable
 *  0b0..RTC_WAKEUP pin is disabled.
 *  0b1..RTC_WAKEUP pin is enabled and asserts if the RTC interrupt asserts or if the wakeup pin is forced on.
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
/*! WPS - Wakeup Pin Select
 *  0b0..RTC_WAKEUP pin asserts (active low, open drain) if the RTC interrupt asserts or the wakeup pin is turned on.
 *  0b1..RTC_WAKEUP pin outputs the RTC 32kHz clock, provided the wakeup pin is turned on and the 32kHz clock is output to other peripherals.
 */
#define RTC_CR_WPS(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_WPS_SHIFT)) & RTC_CR_WPS_MASK)

#define RTC_CR_CPS_MASK                          (0x20U)
#define RTC_CR_CPS_SHIFT                         (5U)
/*! CPS - Clock Pin Select
 *  0b0..The prescaler output clock (as configured by TSIC) is output on RTC_CLKOUT.
 *  0b1..The RTC 32.768 kHz clock is output on RTC_CLKOUT, provided it is output to other peripherals.
 */
#define RTC_CR_CPS(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_CPS_SHIFT)) & RTC_CR_CPS_MASK)

#define RTC_CR_LPOS_MASK                         (0x80U)
#define RTC_CR_LPOS_SHIFT                        (7U)
/*! LPOS - LPO Select
 *  0b0..RTC prescaler increments using 32.768 kHz clock.
 *  0b1..RTC prescaler increments using 1 kHz LPO, bits [4:0] of the prescaler are ignored.
 */
#define RTC_CR_LPOS(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_LPOS_SHIFT)) & RTC_CR_LPOS_MASK)

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

#define RTC_CR_OSCM_MASK                         (0x8000U)
#define RTC_CR_OSCM_SHIFT                        (15U)
/*! OSCM - Oscillator Mode Select
 *  0b0..Configures the 32.768kHz crystal oscillator for robust operation supporting a wide range of crystals.
 *  0b1..Configures the 32.768kHz crystal oscillator for low power operation supporting a more limited range of crystals.
 */
#define RTC_CR_OSCM(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_OSCM_SHIFT)) & RTC_CR_OSCM_MASK)

#define RTC_CR_PORS_MASK                         (0x30000U)
#define RTC_CR_PORS_SHIFT                        (16U)
/*! PORS - POR Select
 *  0b00..POR brownout enabled for 120us every 128ms.
 *  0b01..POR brownout enabled for 120us every 64ms.
 *  0b10..POR brownout enabled for 120us every 32ms.
 *  0b11..POR brownout always enabled.
 */
#define RTC_CR_PORS(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_PORS_SHIFT)) & RTC_CR_PORS_MASK)

#define RTC_CR_CPE_MASK                          (0x3000000U)
#define RTC_CR_CPE_SHIFT                         (24U)
/*! CPE - Clock Pin Enable
 *  0b00..The RTC_CLKOUT function is disabled.
 *  0b01..Enable RTC_CLKOUT pin on pin 1.
 *  0b10..Enable RTC_CLKOUT pin on pin 2.
 *  0b11..Enable RTC_CLKOUT pin on pin 3.
 */
#define RTC_CR_CPE(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_CPE_SHIFT)) & RTC_CR_CPE_MASK)
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

#define RTC_SR_TIDF_MASK                         (0x80U)
#define RTC_SR_TIDF_SHIFT                        (7U)
/*! TIDF - Tamper Interrupt Detect Flag
 *  0b0..Tamper interrupt has not asserted.
 *  0b1..Tamper interrupt has asserted.
 */
#define RTC_SR_TIDF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_SR_TIDF_SHIFT)) & RTC_SR_TIDF_MASK)
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

#define RTC_LR_TDL_MASK                          (0x2000U)
#define RTC_LR_TDL_SHIFT                         (13U)
/*! TDL - Tamper Detect Lock
 *  0b0..Tamper Detect Register is locked and writes are ignored.
 *  0b1..Tamper Detect Register is not locked and writes complete as normal.
 */
#define RTC_LR_TDL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_TDL_SHIFT)) & RTC_LR_TDL_MASK)

#define RTC_LR_TIL_MASK                          (0x8000U)
#define RTC_LR_TIL_SHIFT                         (15U)
/*! TIL - Tamper Interrupt Lock
 *  0b0..Tamper Interrupt Register is locked and writes are ignored.
 *  0b1..Tamper Interrupt Register is not locked and writes complete as normal.
 */
#define RTC_LR_TIL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_TIL_SHIFT)) & RTC_LR_TIL_MASK)

#define RTC_LR_PCL_MASK                          (0xF0000U)
#define RTC_LR_PCL_SHIFT                         (16U)
/*! PCL - Pin Configuration Lock */
#define RTC_LR_PCL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_PCL_SHIFT)) & RTC_LR_PCL_MASK)
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
 *  0b1..If the RTC_WAKEUP pin is enabled, then the pin will assert.
 */
#define RTC_IER_WPON(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_WPON_SHIFT)) & RTC_IER_WPON_MASK)

#define RTC_IER_TSIC_MASK                        (0x70000U)
#define RTC_IER_TSIC_SHIFT                       (16U)
/*! TSIC - Timer Seconds Interrupt Configuration
 *  0b000..1 Hz.
 *  0b001..2 Hz.
 *  0b010..4 Hz.
 *  0b011..8 Hz.
 *  0b100..16 Hz.
 *  0b101..32 Hz.
 *  0b110..64 Hz.
 *  0b111..128 Hz.
 */
#define RTC_IER_TSIC(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_TSIC_SHIFT)) & RTC_IER_TSIC_MASK)
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

/*! @name TDR - RTC Tamper Detect Register */
/*! @{ */

#define RTC_TDR_LCTF_MASK                        (0x10U)
#define RTC_TDR_LCTF_SHIFT                       (4U)
/*! LCTF - Loss of Clock Tamper Flag
 *  0b0..Tamper not detected.
 *  0b1..Loss of Clock tamper detected.
 */
#define RTC_TDR_LCTF(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TDR_LCTF_SHIFT)) & RTC_TDR_LCTF_MASK)

#define RTC_TDR_STF_MASK                         (0x20U)
#define RTC_TDR_STF_SHIFT                        (5U)
/*! STF - Security Tamper Flag
 *  0b0..Tamper not detected.
 *  0b1..Security module tamper detected.
 */
#define RTC_TDR_STF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TDR_STF_SHIFT)) & RTC_TDR_STF_MASK)

#define RTC_TDR_FSF_MASK                         (0x40U)
#define RTC_TDR_FSF_SHIFT                        (6U)
/*! FSF - Flash Security Flag
 *  0b0..Tamper not detected.
 *  0b1..Flash security tamper detected.
 */
#define RTC_TDR_FSF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TDR_FSF_SHIFT)) & RTC_TDR_FSF_MASK)

#define RTC_TDR_TMF_MASK                         (0x80U)
#define RTC_TDR_TMF_SHIFT                        (7U)
/*! TMF - Test Mode Flag
 *  0b0..Tamper not detected.
 *  0b1..Test mode tamper detected.
 */
#define RTC_TDR_TMF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TDR_TMF_SHIFT)) & RTC_TDR_TMF_MASK)

#define RTC_TDR_TPF_MASK                         (0xF0000U)
#define RTC_TDR_TPF_SHIFT                        (16U)
/*! TPF - Tamper Pin Flag */
#define RTC_TDR_TPF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TDR_TPF_SHIFT)) & RTC_TDR_TPF_MASK)
/*! @} */

/*! @name TIR - RTC Tamper Interrupt Register */
/*! @{ */

#define RTC_TIR_LCIE_MASK                        (0x10U)
#define RTC_TIR_LCIE_SHIFT                       (4U)
/*! LCIE - Loss of Clock Interrupt Enable
 *  0b0..Interupt disabled.
 *  0b1..An interrupt is generated when the loss of clock flag is set.
 */
#define RTC_TIR_LCIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TIR_LCIE_SHIFT)) & RTC_TIR_LCIE_MASK)

#define RTC_TIR_SIE_MASK                         (0x20U)
#define RTC_TIR_SIE_SHIFT                        (5U)
/*! SIE - Security Module Interrupt Enable
 *  0b0..Interupt disabled.
 *  0b1..An interrupt is generated when the security module flag is set.
 */
#define RTC_TIR_SIE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TIR_SIE_SHIFT)) & RTC_TIR_SIE_MASK)

#define RTC_TIR_FSIE_MASK                        (0x40U)
#define RTC_TIR_FSIE_SHIFT                       (6U)
/*! FSIE - Flash Security Interrupt Enable
 *  0b0..Interupt disabled.
 *  0b1..An interrupt is generated when the flash security flag is set.
 */
#define RTC_TIR_FSIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TIR_FSIE_SHIFT)) & RTC_TIR_FSIE_MASK)

#define RTC_TIR_TMIE_MASK                        (0x80U)
#define RTC_TIR_TMIE_SHIFT                       (7U)
/*! TMIE - Test Mode Interrupt Enable
 *  0b0..Interupt disabled.
 *  0b1..An interrupt is generated when the test mode flag is set.
 */
#define RTC_TIR_TMIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TIR_TMIE_SHIFT)) & RTC_TIR_TMIE_MASK)

#define RTC_TIR_TPIE_MASK                        (0xF0000U)
#define RTC_TIR_TPIE_SHIFT                       (16U)
/*! TPIE - Tamper Pin Interrupt Enable */
#define RTC_TIR_TPIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_TIR_TPIE_SHIFT)) & RTC_TIR_TPIE_MASK)
/*! @} */

/*! @name PCR - RTC Pin Configuration Register */
/*! @{ */

#define RTC_PCR_TPE_MASK                         (0x1000000U)
#define RTC_PCR_TPE_SHIFT                        (24U)
/*! TPE - Tamper Pull Enable
 *  0b0..Pull resistor is disabled on tamper pin.
 *  0b1..Pull resistor is enabled on tamper pin.
 */
#define RTC_PCR_TPE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_PCR_TPE_SHIFT)) & RTC_PCR_TPE_MASK)

#define RTC_PCR_TPS_MASK                         (0x2000000U)
#define RTC_PCR_TPS_SHIFT                        (25U)
/*! TPS - Tamper Pull Select
 *  0b0..Tamper pin pull resistor direction will assert the tamper pin.
 *  0b1..Tamper pin pull resistor direction will negate the tamper pin.
 */
#define RTC_PCR_TPS(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_PCR_TPS_SHIFT)) & RTC_PCR_TPS_MASK)

#define RTC_PCR_TFE_MASK                         (0x4000000U)
#define RTC_PCR_TFE_SHIFT                        (26U)
/*! TFE - Tamper Filter Enable
 *  0b0..Input filter is disabled on the tamper pin.
 *  0b1..Input filter is enabled on the tamper pin.
 */
#define RTC_PCR_TFE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_PCR_TFE_SHIFT)) & RTC_PCR_TFE_MASK)

#define RTC_PCR_TPP_MASK                         (0x8000000U)
#define RTC_PCR_TPP_SHIFT                        (27U)
/*! TPP - Tamper Pin Polarity
 *  0b0..Tamper pin is active high.
 *  0b1..Tamper pin is active low.
 */
#define RTC_PCR_TPP(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_PCR_TPP_SHIFT)) & RTC_PCR_TPP_MASK)

#define RTC_PCR_TPID_MASK                        (0x80000000U)
#define RTC_PCR_TPID_SHIFT                       (31U)
/*! TPID - Tamper Pin Input Data
 *  0b0..Tamper pin input data is logic zero.
 *  0b1..Tamper pin input data is logic one.
 */
#define RTC_PCR_TPID(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_PCR_TPID_SHIFT)) & RTC_PCR_TPID_MASK)
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

#define RTC_WAR_TDRW_MASK                        (0x2000U)
#define RTC_WAR_TDRW_SHIFT                       (13U)
/*! TDRW - Tamper Detect Register Write
 *  0b0..Writes to the Tamper Detect Register are ignored.
 *  0b1..Writes to the Tamper Detect Register complete as normal.
 */
#define RTC_WAR_TDRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TDRW_SHIFT)) & RTC_WAR_TDRW_MASK)

#define RTC_WAR_TIRW_MASK                        (0x8000U)
#define RTC_WAR_TIRW_SHIFT                       (15U)
/*! TIRW - Tamper Interrupt Register Write
 *  0b0..Writes to the Tamper Interrupt Register are ignored.
 *  0b1..Writes to the Tamper Interrupt Register complete as normal.
 */
#define RTC_WAR_TIRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TIRW_SHIFT)) & RTC_WAR_TIRW_MASK)

#define RTC_WAR_PCRW_MASK                        (0xF0000U)
#define RTC_WAR_PCRW_SHIFT                       (16U)
/*! PCRW - Pin Configuration Register Write */
#define RTC_WAR_PCRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_PCRW_SHIFT)) & RTC_WAR_PCRW_MASK)
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

#define RTC_RAR_TDRR_MASK                        (0x2000U)
#define RTC_RAR_TDRR_SHIFT                       (13U)
/*! TDRR - Tamper Detect Register Read
 *  0b0..Reads to the Tamper Detect Register are ignored.
 *  0b1..Reads to the Tamper Detect Register complete as normal.
 */
#define RTC_RAR_TDRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TDRR_SHIFT)) & RTC_RAR_TDRR_MASK)

#define RTC_RAR_TIRR_MASK                        (0x8000U)
#define RTC_RAR_TIRR_SHIFT                       (15U)
/*! TIRR - Tamper Interrupt Register Read
 *  0b0..Reads to the Tamper Interrupt Register are ignored.
 *  0b1..Reads to the Tamper Interrupt Register complete as normal.
 */
#define RTC_RAR_TIRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TIRR_SHIFT)) & RTC_RAR_TIRR_MASK)

#define RTC_RAR_PCRR_MASK                        (0xF0000U)
#define RTC_RAR_PCRR_SHIFT                       (16U)
/*! PCRR - Pin Configuration Register Read */
#define RTC_RAR_PCRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_PCRR_SHIFT)) & RTC_RAR_PCRR_MASK)
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


#endif  /* PERI_RTC_H_ */

