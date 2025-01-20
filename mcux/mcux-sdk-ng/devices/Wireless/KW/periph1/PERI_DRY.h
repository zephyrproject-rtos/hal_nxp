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
**         CMSIS Peripheral Access Layer for DRY
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
 * @file DRY.h
 * @version 2.0
 * @date 2015-01-06
 * @brief CMSIS Peripheral Access Layer for DRY
 *
 * CMSIS Peripheral Access Layer for DRY
 */

#if !defined(DRY_H_)
#define DRY_H_                                   /**< Symbol preventing repeated inclusion */

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
   -- DRY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DRY_Peripheral_Access_Layer DRY Peripheral Access Layer
 * @{
 */

/** DRY - Size of Registers Arrays */
#define DRY_ATR_COUNT                             2u
#define DRY_PGFR_COUNT                            1u
#define DRY_SKR_COUNT                             8u

/** DRY - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t SKVR;                              /**< DryIce Secure Key Valid Register, offset: 0x4 */
  __IO uint32_t SKWLR;                             /**< DryIce Secure Key Write Lock Register, offset: 0x8 */
  __IO uint32_t SKRLR;                             /**< DryIce Secure Key Read Lock Register, offset: 0xC */
  __IO uint32_t CR;                                /**< DryIce Control Register, offset: 0x10 */
  __IO uint32_t SR;                                /**< DryIce Status Register, offset: 0x14 */
  __IO uint32_t LR;                                /**< DryIce Lock Register, offset: 0x18 */
  __IO uint32_t IER;                               /**< DryIce Interrupt Enable Register, offset: 0x1C */
  __IO uint32_t TSR;                               /**< DryIce Tamper Seconds Register, offset: 0x20 */
  __IO uint32_t TER;                               /**< DryIce Tamper Enable Register, offset: 0x24 */
  __IO uint32_t PDR;                               /**< DryIce Pin Direction Register, offset: 0x28 */
  __IO uint32_t PPR;                               /**< DryIce Pin Polarity Register, offset: 0x2C */
  __IO uint32_t ATR[DRY_ATR_COUNT];                /**< DryIce Active Tamper Register, array offset: 0x30, array step: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t PGFR[DRY_PGFR_COUNT];              /**< DryIce Pin Glitch Filter Register, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_2[1980];
  __IO uint32_t WAC;                               /**< DryIce Write Access Control Register, offset: 0x800 */
  __IO uint32_t RAC;                               /**< DryIce Read Access Control Register, offset: 0x804 */
       uint8_t RESERVED_3[2040];
  __IO uint32_t SKR[DRY_SKR_COUNT];                /**< Secure Key Register, array offset: 0x1000, array step: 0x4 */
       uint8_t RESERVED_4[2016];
  __IO uint32_t SWAC;                              /**< Secure Write Access Control, offset: 0x1800 */
  __IO uint32_t SRAC;                              /**< Secure Read Access Control, offset: 0x1804 */
} DRY_Type;

/* ----------------------------------------------------------------------------
   -- DRY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DRY_Register_Masks DRY Register Masks
 * @{
 */

/*! @name SKVR - DryIce Secure Key Valid Register */
/*! @{ */

#define DRY_SKVR_SKV_MASK                        (0xFFU)
#define DRY_SKVR_SKV_SHIFT                       (0U)
/*! SKV - Secure Key Valid
 *  0b00000000..Corresponding Secure Key Register has not been initialized since last invalidation, tamper or reset.
 *  0b00000001..Corresponding Secure Key Register has been initialized since last invalidation, tamper or reset.
 */
#define DRY_SKVR_SKV(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_SKVR_SKV_SHIFT)) & DRY_SKVR_SKV_MASK)
/*! @} */

/*! @name SKWLR - DryIce Secure Key Write Lock Register */
/*! @{ */

#define DRY_SKWLR_SKWL_MASK                      (0xFFU)
#define DRY_SKWLR_SKWL_SHIFT                     (0U)
/*! SKWL - Secure Key Write Lock
 *  0b00000000..Corresponding Secure Key Register is locked and cannot be written by software.
 *  0b00000001..Corresponding Secure Key Register can be written by software.
 */
#define DRY_SKWLR_SKWL(x)                        (((uint32_t)(((uint32_t)(x)) << DRY_SKWLR_SKWL_SHIFT)) & DRY_SKWLR_SKWL_MASK)
/*! @} */

/*! @name SKRLR - DryIce Secure Key Read Lock Register */
/*! @{ */

#define DRY_SKRLR_SKRL_MASK                      (0xFFU)
#define DRY_SKRLR_SKRL_SHIFT                     (0U)
/*! SKRL - Secure Key Read Lock
 *  0b00000000..Corresponding Secure Key Register is locked and cannot be read by software.
 *  0b00000001..Corresponding Secure Key Register can be read by software.
 */
#define DRY_SKRLR_SKRL(x)                        (((uint32_t)(((uint32_t)(x)) << DRY_SKRLR_SKRL_SHIFT)) & DRY_SKRLR_SKRL_MASK)
/*! @} */

/*! @name CR - DryIce Control Register */
/*! @{ */

#define DRY_CR_SWR_MASK                          (0x1U)
#define DRY_CR_SWR_SHIFT                         (0U)
/*! SWR - Software Reset
 *  0b0..No effect.
 *  0b1..Perform a software reset.
 */
#define DRY_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_CR_SWR_SHIFT)) & DRY_CR_SWR_MASK)

#define DRY_CR_DEN_MASK                          (0x2U)
#define DRY_CR_DEN_SHIFT                         (1U)
/*! DEN - DryIce Enable
 *  0b0..DryIce clock and prescaler are disabled.
 *  0b1..DryIce clock and prescaler are enabled.
 */
#define DRY_CR_DEN(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_CR_DEN_SHIFT)) & DRY_CR_DEN_MASK)

#define DRY_CR_TFSR_MASK                         (0x4U)
#define DRY_CR_TFSR_SHIFT                        (2U)
/*! TFSR - Tamper Force System Reset
 *  0b0..Do not force chip reset when tampering is detected.
 *  0b1..Force chip reset when tampering is detected.
 */
#define DRY_CR_TFSR(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_CR_TFSR_SHIFT)) & DRY_CR_TFSR_MASK)

#define DRY_CR_UM_MASK                           (0x8U)
#define DRY_CR_UM_SHIFT                          (3U)
/*! UM - Update Mode
 *  0b0..DryIce Status Register cannot be written when the Status Register Lock bit within the Lock Register (LR[SRL]) is clear.
 *  0b1..DryIce Status Register cannot be written when the Status Register Lock bit within the Lock Register
 *       (LR[SRL]) is clear and DryIce Tamper Flag (SR[DTF]) is set.
 */
#define DRY_CR_UM(x)                             (((uint32_t)(((uint32_t)(x)) << DRY_CR_UM_SHIFT)) & DRY_CR_UM_MASK)

#define DRY_CR_THYS_MASK                         (0x100U)
#define DRY_CR_THYS_SHIFT                        (8U)
/*! THYS - Tamper Hysteresis Select
 *  0b0..Hysteresis is set to a range of 305 mV to 440 mV.
 *  0b1..Hysteresis is set to a range of 490 mV to 705 mV.
 */
#define DRY_CR_THYS(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_CR_THYS_SHIFT)) & DRY_CR_THYS_MASK)

#define DRY_CR_TPFE_MASK                         (0x200U)
#define DRY_CR_TPFE_SHIFT                        (9U)
/*! TPFE - Tamper Passive Filter Enable
 *  0b0..Tamper pins are configured with passive input filter disabled
 *  0b1..Tamper pins are configured with passive input filter enabled
 */
#define DRY_CR_TPFE(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_CR_TPFE_SHIFT)) & DRY_CR_TPFE_MASK)

#define DRY_CR_TDSE_MASK                         (0x400U)
#define DRY_CR_TDSE_SHIFT                        (10U)
/*! TDSE - Tamper Drive Strength Enable
 *  0b0..Tamper pins are configured for low drive strength
 *  0b1..Tamper pins are configured for high drive strength
 */
#define DRY_CR_TDSE(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_CR_TDSE_SHIFT)) & DRY_CR_TDSE_MASK)

#define DRY_CR_TSRE_MASK                         (0x800U)
#define DRY_CR_TSRE_SHIFT                        (11U)
/*! TSRE - Tamper Slew Rate Enable
 *  0b0..Tamper pins are configured for slow slew rate.
 *  0b1..Tamper pins are configured for fast slew rate.
 */
#define DRY_CR_TSRE(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_CR_TSRE_SHIFT)) & DRY_CR_TSRE_MASK)

#define DRY_CR_DPR_MASK                          (0xFFFE0000U)
#define DRY_CR_DPR_SHIFT                         (17U)
/*! DPR - DryIce Prescaler Register */
#define DRY_CR_DPR(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_CR_DPR_SHIFT)) & DRY_CR_DPR_MASK)
/*! @} */

/*! @name SR - DryIce Status Register */
/*! @{ */

#define DRY_SR_DTF_MASK                          (0x1U)
#define DRY_SR_DTF_SHIFT                         (0U)
/*! DTF - DryIce Tamper Flag
 *  0b0..DryIce tampering not detected.
 *  0b1..DryIce tampering detected.
 */
#define DRY_SR_DTF(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SR_DTF_SHIFT)) & DRY_SR_DTF_MASK)

#define DRY_SR_TAF_MASK                          (0x2U)
#define DRY_SR_TAF_SHIFT                         (1U)
/*! TAF - Tamper Acknowledge Flag
 *  0b0..DryIce Tamper Flag (SR[DTF]) is clear or chip reset has not occurred after DryIce Tamper Flag (SR[DTF]) was set.
 *  0b1..Chip reset has occurred after DryIce Tamper Flag (SR[DTF]) was set.
 */
#define DRY_SR_TAF(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SR_TAF_SHIFT)) & DRY_SR_TAF_MASK)

#define DRY_SR_TOF_MASK                          (0x4U)
#define DRY_SR_TOF_SHIFT                         (2U)
/*! TOF - Time Overflow Flag
 *  0b0..Tamper not detected.
 *  0b1..RTC time overflow tamper detected.
 */
#define DRY_SR_TOF(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SR_TOF_SHIFT)) & DRY_SR_TOF_MASK)

#define DRY_SR_MOF_MASK                          (0x8U)
#define DRY_SR_MOF_SHIFT                         (3U)
/*! MOF - Monotonic Overflow Flag
 *  0b0..Tamper not detected.
 *  0b1..RTC monotonic overflow tamper detected.
 */
#define DRY_SR_MOF(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SR_MOF_SHIFT)) & DRY_SR_MOF_MASK)

#define DRY_SR_VTF_MASK                          (0x10U)
#define DRY_SR_VTF_SHIFT                         (4U)
/*! VTF - Voltage Tamper Flag
 *  0b0..Tamper not detected.
 *  0b1..Voltage tampering detected.
 */
#define DRY_SR_VTF(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SR_VTF_SHIFT)) & DRY_SR_VTF_MASK)

#define DRY_SR_CTF_MASK                          (0x20U)
#define DRY_SR_CTF_SHIFT                         (5U)
/*! CTF - Clock Tamper Flag
 *  0b0..Tamper not detected.
 *  0b1..Clock tampering detected.
 */
#define DRY_SR_CTF(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SR_CTF_SHIFT)) & DRY_SR_CTF_MASK)

#define DRY_SR_TTF_MASK                          (0x40U)
#define DRY_SR_TTF_SHIFT                         (6U)
/*! TTF - Temperature Tamper Flag
 *  0b0..Tamper not detected.
 *  0b1..Temperature tampering detected.
 */
#define DRY_SR_TTF(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SR_TTF_SHIFT)) & DRY_SR_TTF_MASK)

#define DRY_SR_STF_MASK                          (0x80U)
#define DRY_SR_STF_SHIFT                         (7U)
/*! STF - Security Tamper Flag
 *  0b0..Tamper not detected.
 *  0b1..Security module tamper detected.
 */
#define DRY_SR_STF(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SR_STF_SHIFT)) & DRY_SR_STF_MASK)

#define DRY_SR_FSF_MASK                          (0x100U)
#define DRY_SR_FSF_SHIFT                         (8U)
/*! FSF - Flash Security Flag
 *  0b0..Tamper not detected.
 *  0b1..Flash security tamper detected.
 */
#define DRY_SR_FSF(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SR_FSF_SHIFT)) & DRY_SR_FSF_MASK)

#define DRY_SR_TMF_MASK                          (0x200U)
#define DRY_SR_TMF_SHIFT                         (9U)
/*! TMF - Test Mode Flag
 *  0b0..Tamper not detected.
 *  0b1..Test mode tamper detected.
 */
#define DRY_SR_TMF(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SR_TMF_SHIFT)) & DRY_SR_TMF_MASK)

#define DRY_SR_TPF_MASK                          (0xFF0000U)
#define DRY_SR_TPF_SHIFT                         (16U)
/*! TPF - Tamper Pin Flag
 *  0b00000000..Tamper not detected.
 *  0b00000001..Tamper pin tamper detected.
 */
#define DRY_SR_TPF(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SR_TPF_SHIFT)) & DRY_SR_TPF_MASK)
/*! @} */

/*! @name LR - DryIce Lock Register */
/*! @{ */

#define DRY_LR_KVL_MASK                          (0x2U)
#define DRY_LR_KVL_SHIFT                         (1U)
/*! KVL - Key Valid Lock
 *  0b0..Secure key valid register is locked and writes are ignored.
 *  0b1..Secure key valid register is not locked and writes complete as normal.
 */
#define DRY_LR_KVL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_KVL_SHIFT)) & DRY_LR_KVL_MASK)

#define DRY_LR_KWL_MASK                          (0x4U)
#define DRY_LR_KWL_SHIFT                         (2U)
/*! KWL - Key Write Lock
 *  0b0..Secure Key Write Lock Register is locked and writes are ignored.
 *  0b1..Secure Key Write Lock Register is not locked and writes complete as normal.
 */
#define DRY_LR_KWL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_KWL_SHIFT)) & DRY_LR_KWL_MASK)

#define DRY_LR_KRL_MASK                          (0x8U)
#define DRY_LR_KRL_SHIFT                         (3U)
/*! KRL - Key Read Lock
 *  0b0..Secure Key Read Lock Register is locked and writes are ignored.
 *  0b1..Secure Key Read Lock Register is not locked and writes complete as normal.
 */
#define DRY_LR_KRL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_KRL_SHIFT)) & DRY_LR_KRL_MASK)

#define DRY_LR_CRL_MASK                          (0x10U)
#define DRY_LR_CRL_SHIFT                         (4U)
/*! CRL - Control Register Lock
 *  0b0..Control register is locked and writes are ignored.
 *  0b1..Control register is not locked and writes complete as normal.
 */
#define DRY_LR_CRL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_CRL_SHIFT)) & DRY_LR_CRL_MASK)

#define DRY_LR_SRL_MASK                          (0x20U)
#define DRY_LR_SRL_SHIFT                         (5U)
/*! SRL - Status Register Lock
 *  0b0..Status Register is locked and writes are ignored.
 *  0b1..Status Register is not locked and writes complete as normal.
 */
#define DRY_LR_SRL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_SRL_SHIFT)) & DRY_LR_SRL_MASK)

#define DRY_LR_LRL_MASK                          (0x40U)
#define DRY_LR_LRL_SHIFT                         (6U)
/*! LRL - Lock Register Lock
 *  0b0..Lock register is locked and writes are ignored.
 *  0b1..Lock register is not locked and writes complete as normal.
 */
#define DRY_LR_LRL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_LRL_SHIFT)) & DRY_LR_LRL_MASK)

#define DRY_LR_IEL_MASK                          (0x80U)
#define DRY_LR_IEL_SHIFT                         (7U)
/*! IEL - Interrupt Enable Lock
 *  0b0..Interrupt enable register is locked and writes are ignored.
 *  0b1..Interrupt enable register is not locked and writes complete as normal.
 */
#define DRY_LR_IEL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_IEL_SHIFT)) & DRY_LR_IEL_MASK)

#define DRY_LR_TSL_MASK                          (0x100U)
#define DRY_LR_TSL_SHIFT                         (8U)
/*! TSL - Tamper Seconds Lock
 *  0b0..Tamper seconds register is locked and writes are ignored.
 *  0b1..Tamper seconds register is not locked and writes complete as normal.
 */
#define DRY_LR_TSL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_TSL_SHIFT)) & DRY_LR_TSL_MASK)

#define DRY_LR_TEL_MASK                          (0x200U)
#define DRY_LR_TEL_SHIFT                         (9U)
/*! TEL - Tamper Enable Lock
 *  0b0..Tamper enable register is locked and writes are ignored.
 *  0b1..Tamper enable register is not locked and writes complete as normal.
 */
#define DRY_LR_TEL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_TEL_SHIFT)) & DRY_LR_TEL_MASK)

#define DRY_LR_PDL_MASK                          (0x400U)
#define DRY_LR_PDL_SHIFT                         (10U)
/*! PDL - Pin Direction Lock
 *  0b0..Pin direction register is locked and writes are ignored.
 *  0b1..Pin direction register is not locked and writes complete as normal.
 */
#define DRY_LR_PDL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_PDL_SHIFT)) & DRY_LR_PDL_MASK)

#define DRY_LR_PPL_MASK                          (0x800U)
#define DRY_LR_PPL_SHIFT                         (11U)
/*! PPL - Pin Polarity Lock
 *  0b0..Pin polarity register is locked and writes are ignored.
 *  0b1..Pin polarity register is not locked and writes complete as normal.
 */
#define DRY_LR_PPL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_PPL_SHIFT)) & DRY_LR_PPL_MASK)

#define DRY_LR_ATL_MASK                          (0x3000U)
#define DRY_LR_ATL_SHIFT                         (12U)
/*! ATL - Active Tamper Lock
 *  0b00..Active tamper register is locked and writes are ignored.
 *  0b01..Active tamper register is not locked and writes complete as normal.
 */
#define DRY_LR_ATL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_ATL_SHIFT)) & DRY_LR_ATL_MASK)

#define DRY_LR_GFL_MASK                          (0xFF0000U)
#define DRY_LR_GFL_SHIFT                         (16U)
/*! GFL - Glitch Filter Lock
 *  0b00000000..Pin glitch filter register is locked and writes are ignored.
 *  0b00000001..Pin glitch filter register is not locked and writes complete as normal.
 */
#define DRY_LR_GFL(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_LR_GFL_SHIFT)) & DRY_LR_GFL_MASK)
/*! @} */

/*! @name IER - DryIce Interrupt Enable Register */
/*! @{ */

#define DRY_IER_DTIE_MASK                        (0x1U)
#define DRY_IER_DTIE_SHIFT                       (0U)
/*! DTIE - DryIce Tamper Interrupt Enable
 *  0b0..When DryIce Tamper Flag (SR[DTF]) is set, an interrupt is not generated.
 *  0b1..When DryIce Tamper Flag (SR[DTF]) is set, an interrupt is generated.
 */
#define DRY_IER_DTIE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_IER_DTIE_SHIFT)) & DRY_IER_DTIE_MASK)

#define DRY_IER_TOIE_MASK                        (0x4U)
#define DRY_IER_TOIE_SHIFT                       (2U)
/*! TOIE - Time Overflow Interrupt Enable
 *  0b0..When time overflow flag is set, an interrupt is not generated.
 *  0b1..When time overflow flag is set, an interrupt is generated.
 */
#define DRY_IER_TOIE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_IER_TOIE_SHIFT)) & DRY_IER_TOIE_MASK)

#define DRY_IER_MOIE_MASK                        (0x8U)
#define DRY_IER_MOIE_SHIFT                       (3U)
/*! MOIE - Monotonic Overflow Interrupt Enable
 *  0b0..When monotonic overflow flag is set, an interrupt is not generated.
 *  0b1..When monotonic overflow flag is set, an interrupt is generated.
 */
#define DRY_IER_MOIE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_IER_MOIE_SHIFT)) & DRY_IER_MOIE_MASK)

#define DRY_IER_VTIE_MASK                        (0x10U)
#define DRY_IER_VTIE_SHIFT                       (4U)
/*! VTIE - Voltage Tamper Interrupt Enable
 *  0b0..When voltage tamper flag is set, an interrupt is not generated.
 *  0b1..When voltage tamper flag is set, an interrupt is generated.
 */
#define DRY_IER_VTIE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_IER_VTIE_SHIFT)) & DRY_IER_VTIE_MASK)

#define DRY_IER_CTIE_MASK                        (0x20U)
#define DRY_IER_CTIE_SHIFT                       (5U)
/*! CTIE - Clock Tamper Interrupt Enable
 *  0b0..When clock tamper flag is set, an interrupt is not generated.
 *  0b1..When clock tamper flag is set, an interrupt is generated.
 */
#define DRY_IER_CTIE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_IER_CTIE_SHIFT)) & DRY_IER_CTIE_MASK)

#define DRY_IER_TTIE_MASK                        (0x40U)
#define DRY_IER_TTIE_SHIFT                       (6U)
/*! TTIE - Temperature Tamper Interrupt Enable
 *  0b0..When temperature tamper flag is set, an interrupt is not generated.
 *  0b1..When temperature tamper flag is set, an interrupt is generated.
 */
#define DRY_IER_TTIE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_IER_TTIE_SHIFT)) & DRY_IER_TTIE_MASK)

#define DRY_IER_STIE_MASK                        (0x80U)
#define DRY_IER_STIE_SHIFT                       (7U)
/*! STIE - Security Tamper Interrupt Enable
 *  0b0..When security tamper flag is set, an interrupt is not generated.
 *  0b1..When security tamper flag is set, an interrupt is generated.
 */
#define DRY_IER_STIE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_IER_STIE_SHIFT)) & DRY_IER_STIE_MASK)

#define DRY_IER_FSIE_MASK                        (0x100U)
#define DRY_IER_FSIE_SHIFT                       (8U)
/*! FSIE - Flash Security Interrupt Enable
 *  0b0..When flash security flag is set, an interrupt is not generated.
 *  0b1..When flash security flag is set, an interrupt is generated.
 */
#define DRY_IER_FSIE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_IER_FSIE_SHIFT)) & DRY_IER_FSIE_MASK)

#define DRY_IER_TMIE_MASK                        (0x200U)
#define DRY_IER_TMIE_SHIFT                       (9U)
/*! TMIE - Test Mode Interrupt Enable
 *  0b0..When test mode flag is set, an interrupt is not generated.
 *  0b1..When test mode flag is set, an interrupt is generated.
 */
#define DRY_IER_TMIE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_IER_TMIE_SHIFT)) & DRY_IER_TMIE_MASK)

#define DRY_IER_TPIE_MASK                        (0xFF0000U)
#define DRY_IER_TPIE_SHIFT                       (16U)
/*! TPIE - Tamper Pin Interrupt Enable
 *  0b00000000..When corresponding tamper pin flag is set, an interrupt is not generated.
 *  0b00000001..When corresponding tamper pin flag is set, an interrupt is generated.
 */
#define DRY_IER_TPIE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_IER_TPIE_SHIFT)) & DRY_IER_TPIE_MASK)
/*! @} */

/*! @name TSR - DryIce Tamper Seconds Register */
/*! @{ */

#define DRY_TSR_TTS_MASK                         (0xFFFFFFFFU)
#define DRY_TSR_TTS_SHIFT                        (0U)
/*! TTS - Tamper Time Seconds */
#define DRY_TSR_TTS(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_TSR_TTS_SHIFT)) & DRY_TSR_TTS_MASK)
/*! @} */

/*! @name TER - DryIce Tamper Enable Register */
/*! @{ */

#define DRY_TER_TOE_MASK                         (0x4U)
#define DRY_TER_TOE_SHIFT                        (2U)
/*! TOE - Time Overflow Enable
 *  0b0..When time overflow flag is set, tampering is not detected.
 *  0b1..When time overflow flag is set, tampering is detected.
 */
#define DRY_TER_TOE(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_TER_TOE_SHIFT)) & DRY_TER_TOE_MASK)

#define DRY_TER_MOE_MASK                         (0x8U)
#define DRY_TER_MOE_SHIFT                        (3U)
/*! MOE - Monotonic Overflow Enable
 *  0b0..When monotonic overflow flag is set, tampering is not detected.
 *  0b1..When monotonic overflow flag is set, tampering is detected.
 */
#define DRY_TER_MOE(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_TER_MOE_SHIFT)) & DRY_TER_MOE_MASK)

#define DRY_TER_VTE_MASK                         (0x10U)
#define DRY_TER_VTE_SHIFT                        (4U)
/*! VTE - Voltage Tamper Enable
 *  0b0..When voltage tamper flag is set, tampering is not detected.
 *  0b1..When voltage tamper flag is set, tampering is detected.
 */
#define DRY_TER_VTE(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_TER_VTE_SHIFT)) & DRY_TER_VTE_MASK)

#define DRY_TER_CTE_MASK                         (0x20U)
#define DRY_TER_CTE_SHIFT                        (5U)
/*! CTE - Clock Tamper Enable
 *  0b0..When clock tamper flag is set, tampering is not detected.
 *  0b1..When clock tamper flag is set, tampering is detected.
 */
#define DRY_TER_CTE(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_TER_CTE_SHIFT)) & DRY_TER_CTE_MASK)

#define DRY_TER_TTE_MASK                         (0x40U)
#define DRY_TER_TTE_SHIFT                        (6U)
/*! TTE - Temperature Tamper Enable
 *  0b0..When temperature tamper flag is set, tampering is not detected.
 *  0b1..When temperature tamper flag is set, tampering is detected.
 */
#define DRY_TER_TTE(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_TER_TTE_SHIFT)) & DRY_TER_TTE_MASK)

#define DRY_TER_STE_MASK                         (0x80U)
#define DRY_TER_STE_SHIFT                        (7U)
/*! STE - Security Tamper Enable
 *  0b0..When security tamper flag is set, tampering is not detected.
 *  0b1..When security tamper flag is set, tampering is detected.
 */
#define DRY_TER_STE(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_TER_STE_SHIFT)) & DRY_TER_STE_MASK)

#define DRY_TER_FSE_MASK                         (0x100U)
#define DRY_TER_FSE_SHIFT                        (8U)
/*! FSE - Flash Security Enable
 *  0b0..When flash security flag is set, tampering is not detected.
 *  0b1..When flash security flag is set, tampering is detected.
 */
#define DRY_TER_FSE(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_TER_FSE_SHIFT)) & DRY_TER_FSE_MASK)

#define DRY_TER_TME_MASK                         (0x200U)
#define DRY_TER_TME_SHIFT                        (9U)
/*! TME - Test Mode Enable
 *  0b0..When test mode flag is set, tampering is not detected.
 *  0b1..When test mode flag is set, tampering is detected.
 */
#define DRY_TER_TME(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_TER_TME_SHIFT)) & DRY_TER_TME_MASK)

#define DRY_TER_TPE_MASK                         (0xFF0000U)
#define DRY_TER_TPE_SHIFT                        (16U)
/*! TPE - Tamper Pin Enable
 *  0b00000000..When corresponding tamper pin flag is set, tampering is not detected.
 *  0b00000001..When corresponding tamper pin flag is set, tampering is detected.
 */
#define DRY_TER_TPE(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_TER_TPE_SHIFT)) & DRY_TER_TPE_MASK)
/*! @} */

/*! @name PDR - DryIce Pin Direction Register */
/*! @{ */

#define DRY_PDR_TPD_MASK                         (0xFFU)
#define DRY_PDR_TPD_SHIFT                        (0U)
/*! TPD - Tamper Pin Direction
 *  0b00000000..Tamper pin is input
 *  0b00000001..Tamper pin is output and drives inverse of expected value (tamper pin is asserted)
 */
#define DRY_PDR_TPD(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_PDR_TPD_SHIFT)) & DRY_PDR_TPD_MASK)

#define DRY_PDR_TPOD_MASK                        (0xFF0000U)
#define DRY_PDR_TPOD_SHIFT                       (16U)
/*! TPOD - Tamper Pin Output Data
 *  0b00000000..Tamper pin output data is logic zero.
 *  0b00000001..Tamper pin output data is logic one.
 */
#define DRY_PDR_TPOD(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_PDR_TPOD_SHIFT)) & DRY_PDR_TPOD_MASK)
/*! @} */

/*! @name PPR - DryIce Pin Polarity Register */
/*! @{ */

#define DRY_PPR_TPP_MASK                         (0xFFU)
#define DRY_PPR_TPP_SHIFT                        (0U)
/*! TPP - Tamper Pin Polarity
 *  0b00000000..Tamper pin expected value is not inverted.
 *  0b00000001..Tamper pin expected value is inverted.
 */
#define DRY_PPR_TPP(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_PPR_TPP_SHIFT)) & DRY_PPR_TPP_MASK)

#define DRY_PPR_TPID_MASK                        (0xFF0000U)
#define DRY_PPR_TPID_SHIFT                       (16U)
/*! TPID - Tamper Pin Input Data
 *  0b00000000..Tamper pin input data (before glitch filter) is logic zero.
 *  0b00000001..Tamper pin input data (before glitch filter) is logic one.
 */
#define DRY_PPR_TPID(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_PPR_TPID_SHIFT)) & DRY_PPR_TPID_MASK)
/*! @} */

/*! @name ATR - DryIce Active Tamper Register */
/*! @{ */

#define DRY_ATR_ATSR_MASK                        (0xFFFFU)
#define DRY_ATR_ATSR_SHIFT                       (0U)
/*! ATSR - Active Tamper Shift Register */
#define DRY_ATR_ATSR(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_ATR_ATSR_SHIFT)) & DRY_ATR_ATSR_MASK)

#define DRY_ATR_ATP_MASK                         (0xFFFF0000U)
#define DRY_ATR_ATP_SHIFT                        (16U)
/*! ATP - Active Tamper Polynomial */
#define DRY_ATR_ATP(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_ATR_ATP_SHIFT)) & DRY_ATR_ATP_MASK)
/*! @} */

/*! @name PGFR - DryIce Pin Glitch Filter Register */
/*! @{ */

#define DRY_PGFR_GFW_MASK                        (0x3FU)
#define DRY_PGFR_GFW_SHIFT                       (0U)
/*! GFW - Glitch Filter Width */
#define DRY_PGFR_GFW(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_PGFR_GFW_SHIFT)) & DRY_PGFR_GFW_MASK)

#define DRY_PGFR_GFP_MASK                        (0x40U)
#define DRY_PGFR_GFP_SHIFT                       (6U)
/*! GFP - Glitch Filter Prescaler
 *  0b0..The glitch filter on tamper pin is clocked by the 512 Hz prescaler clock.
 *  0b1..The glitch filter on tamper pin is clocked by the 32.768 kHz clock.
 */
#define DRY_PGFR_GFP(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_PGFR_GFP_SHIFT)) & DRY_PGFR_GFP_MASK)

#define DRY_PGFR_GFE_MASK                        (0x80U)
#define DRY_PGFR_GFE_SHIFT                       (7U)
/*! GFE - Glitch Filter Enable
 *  0b0..The glitch filter on tamper pin is bypassed.
 *  0b1..The glitch filter on tamper pin is enabled.
 */
#define DRY_PGFR_GFE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_PGFR_GFE_SHIFT)) & DRY_PGFR_GFE_MASK)

#define DRY_PGFR_TPEX_MASK                       (0x30000U)
#define DRY_PGFR_TPEX_SHIFT                      (16U)
/*! TPEX - Tamper Pin Expected
 *  0b00..Tamper pin expected value is logic zero.
 *  0b01..Tamper pin expected value is active tamper 0 output.
 *  0b10..Tamper pin expected value is active tamper 1 output.
 *  0b11..Tamper pin 0 expected value is active tamper 0 output XORed with active tamper 1 output.
 */
#define DRY_PGFR_TPEX(x)                         (((uint32_t)(((uint32_t)(x)) << DRY_PGFR_TPEX_SHIFT)) & DRY_PGFR_TPEX_MASK)

#define DRY_PGFR_TPE_MASK                        (0x1000000U)
#define DRY_PGFR_TPE_SHIFT                       (24U)
/*! TPE - Tamper Pull Enable
 *  0b0..Pull resistor is disabled on tamper pin.
 *  0b1..Pull resistor is enabled on tamper pin.
 */
#define DRY_PGFR_TPE(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_PGFR_TPE_SHIFT)) & DRY_PGFR_TPE_MASK)
/*! @} */

/*! @name WAC - DryIce Write Access Control Register */
/*! @{ */

#define DRY_WAC_SKVW_MASK                        (0x2U)
#define DRY_WAC_SKVW_SHIFT                       (1U)
/*! SKVW - Secure Key Valid Write
 *  0b0..Writes to the secure key valid register are ignored.
 *  0b1..Writes to the secure key valid register complete as normal.
 */
#define DRY_WAC_SKVW(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_WAC_SKVW_SHIFT)) & DRY_WAC_SKVW_MASK)

#define DRY_WAC_SKWRW_MASK                       (0x4U)
#define DRY_WAC_SKWRW_SHIFT                      (2U)
/*! SKWRW - Secure Key Write Lock Register Write
 *  0b0..Writes to the Secure Key Write Lock Register are ignored.
 *  0b1..Writes to the Secure Key Write Lock Register complete as normal.
 */
#define DRY_WAC_SKWRW(x)                         (((uint32_t)(((uint32_t)(x)) << DRY_WAC_SKWRW_SHIFT)) & DRY_WAC_SKWRW_MASK)

#define DRY_WAC_SKRRW_MASK                       (0x8U)
#define DRY_WAC_SKRRW_SHIFT                      (3U)
/*! SKRRW - Secure Key Read Lock Register Write
 *  0b0..Writes to the Secure Key Read Lock Register are ignored.
 *  0b1..Writes to the Secure Key Read Lock Register complete as normal.
 */
#define DRY_WAC_SKRRW(x)                         (((uint32_t)(((uint32_t)(x)) << DRY_WAC_SKRRW_SHIFT)) & DRY_WAC_SKRRW_MASK)

#define DRY_WAC_CRW_MASK                         (0x10U)
#define DRY_WAC_CRW_SHIFT                        (4U)
/*! CRW - Control Register Write
 *  0b0..Writes to the Control register are ignored.
 *  0b1..Writes to the Control register complete as normal.
 */
#define DRY_WAC_CRW(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_WAC_CRW_SHIFT)) & DRY_WAC_CRW_MASK)

#define DRY_WAC_SRW_MASK                         (0x20U)
#define DRY_WAC_SRW_SHIFT                        (5U)
/*! SRW - Status Register Write
 *  0b0..Writes to the Status Register are ignored.
 *  0b1..Writes to the Status Register complete as normal.
 */
#define DRY_WAC_SRW(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_WAC_SRW_SHIFT)) & DRY_WAC_SRW_MASK)

#define DRY_WAC_LRW_MASK                         (0x40U)
#define DRY_WAC_LRW_SHIFT                        (6U)
/*! LRW - Lock Register Write
 *  0b0..Writes to the Lock register are ignored.
 *  0b1..Writes to the Lock register complete as normal.
 */
#define DRY_WAC_LRW(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_WAC_LRW_SHIFT)) & DRY_WAC_LRW_MASK)

#define DRY_WAC_IEW_MASK                         (0x80U)
#define DRY_WAC_IEW_SHIFT                        (7U)
/*! IEW - Interrupt Enable Write
 *  0b0..Writes to the Interrupt enable register are ignored.
 *  0b1..Writes to the Interrupt enable register complete as normal.
 */
#define DRY_WAC_IEW(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_WAC_IEW_SHIFT)) & DRY_WAC_IEW_MASK)

#define DRY_WAC_TSRW_MASK                        (0x100U)
#define DRY_WAC_TSRW_SHIFT                       (8U)
/*! TSRW - Tamper Seconds Register Write
 *  0b0..Writes to the Tamper Seconds register are ignored.
 *  0b1..Writes to the Tamper Seconds register complete as normal.
 */
#define DRY_WAC_TSRW(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_WAC_TSRW_SHIFT)) & DRY_WAC_TSRW_MASK)

#define DRY_WAC_TEW_MASK                         (0x200U)
#define DRY_WAC_TEW_SHIFT                        (9U)
/*! TEW - Tamper Enable Write
 *  0b0..Writes to the tamper enable register are ignored.
 *  0b1..Writes to the tamper enable register complete as normal.
 */
#define DRY_WAC_TEW(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_WAC_TEW_SHIFT)) & DRY_WAC_TEW_MASK)

#define DRY_WAC_PDW_MASK                         (0x400U)
#define DRY_WAC_PDW_SHIFT                        (10U)
/*! PDW - Pin Direction Write
 *  0b0..Writes to the pin direction register are ignored.
 *  0b1..Writes to the pin direction register complete as normal.
 */
#define DRY_WAC_PDW(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_WAC_PDW_SHIFT)) & DRY_WAC_PDW_MASK)

#define DRY_WAC_PPW_MASK                         (0x800U)
#define DRY_WAC_PPW_SHIFT                        (11U)
/*! PPW - Pin Polarity Write
 *  0b0..Writes to the pin polarity register are ignored.
 *  0b1..Writes to the pin polarity register complete as normal.
 */
#define DRY_WAC_PPW(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_WAC_PPW_SHIFT)) & DRY_WAC_PPW_MASK)

#define DRY_WAC_ATW_MASK                         (0x3000U)
#define DRY_WAC_ATW_SHIFT                        (12U)
/*! ATW - Active Tamper Write
 *  0b00..Writes to the active tamper register are ignored.
 *  0b01..Writes to the active tamper register complete as normal.
 */
#define DRY_WAC_ATW(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_WAC_ATW_SHIFT)) & DRY_WAC_ATW_MASK)

#define DRY_WAC_GFW_MASK                         (0xFF0000U)
#define DRY_WAC_GFW_SHIFT                        (16U)
/*! GFW - Glitch Filter Write
 *  0b00000000..Writes to the pin glitch filter register are ignored.
 *  0b00000001..Writes to the pin glitch filter register complete as normal.
 */
#define DRY_WAC_GFW(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_WAC_GFW_SHIFT)) & DRY_WAC_GFW_MASK)
/*! @} */

/*! @name RAC - DryIce Read Access Control Register */
/*! @{ */

#define DRY_RAC_SKVR_MASK                        (0x2U)
#define DRY_RAC_SKVR_SHIFT                       (1U)
/*! SKVR - Secure Key Valid Read
 *  0b0..Reads to the secure key valid register are ignored.
 *  0b1..Reads to the secure key valid register complete as normal.
 */
#define DRY_RAC_SKVR(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_RAC_SKVR_SHIFT)) & DRY_RAC_SKVR_MASK)

#define DRY_RAC_SKWRR_MASK                       (0x4U)
#define DRY_RAC_SKWRR_SHIFT                      (2U)
/*! SKWRR - Secure Key Write Lock Register Read
 *  0b0..Reads to the Secure Key Write Lock Register are ignored.
 *  0b1..Reads to the Secure Key Write Lock Register complete as normal.
 */
#define DRY_RAC_SKWRR(x)                         (((uint32_t)(((uint32_t)(x)) << DRY_RAC_SKWRR_SHIFT)) & DRY_RAC_SKWRR_MASK)

#define DRY_RAC_SKRRR_MASK                       (0x8U)
#define DRY_RAC_SKRRR_SHIFT                      (3U)
/*! SKRRR - Secure Key Read Lock Register Read
 *  0b0..Reads to the Secure Key Read Lock Register are ignored.
 *  0b1..Reads to the Secure Key Read Lock Register complete as normal.
 */
#define DRY_RAC_SKRRR(x)                         (((uint32_t)(((uint32_t)(x)) << DRY_RAC_SKRRR_SHIFT)) & DRY_RAC_SKRRR_MASK)

#define DRY_RAC_CRR_MASK                         (0x10U)
#define DRY_RAC_CRR_SHIFT                        (4U)
/*! CRR - Control Register Read
 *  0b0..Reads to the Control register are ignored.
 *  0b1..Reads to the Control register complete as normal.
 */
#define DRY_RAC_CRR(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_RAC_CRR_SHIFT)) & DRY_RAC_CRR_MASK)

#define DRY_RAC_SRR_MASK                         (0x20U)
#define DRY_RAC_SRR_SHIFT                        (5U)
/*! SRR - Status Register Read
 *  0b0..Reads to the Status Register are ignored.
 *  0b1..Reads to the Status Register complete as normal.
 */
#define DRY_RAC_SRR(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_RAC_SRR_SHIFT)) & DRY_RAC_SRR_MASK)

#define DRY_RAC_LRR_MASK                         (0x40U)
#define DRY_RAC_LRR_SHIFT                        (6U)
/*! LRR - Lock Register Read
 *  0b0..Reads to the Lock register are ignored.
 *  0b1..Reads to the Lock register complete as normal.
 */
#define DRY_RAC_LRR(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_RAC_LRR_SHIFT)) & DRY_RAC_LRR_MASK)

#define DRY_RAC_IER_MASK                         (0x80U)
#define DRY_RAC_IER_SHIFT                        (7U)
/*! IER - Interrupt Enable Read
 *  0b0..Reads to the Interrupt enable register are ignored.
 *  0b1..Reads to the Interrupt enable register complete as normal.
 */
#define DRY_RAC_IER(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_RAC_IER_SHIFT)) & DRY_RAC_IER_MASK)

#define DRY_RAC_TSRR_MASK                        (0x100U)
#define DRY_RAC_TSRR_SHIFT                       (8U)
/*! TSRR - Tamper Seconds Register Read
 *  0b0..Reads to the tamper seconds register are ignored.
 *  0b1..Reads to the tamper seconds register complete as normal.
 */
#define DRY_RAC_TSRR(x)                          (((uint32_t)(((uint32_t)(x)) << DRY_RAC_TSRR_SHIFT)) & DRY_RAC_TSRR_MASK)

#define DRY_RAC_TER_MASK                         (0x200U)
#define DRY_RAC_TER_SHIFT                        (9U)
/*! TER - Tamper Enable Read
 *  0b0..Reads to the tamper enable register are ignored.
 *  0b1..Reads to the tamper enable register complete as normal.
 */
#define DRY_RAC_TER(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_RAC_TER_SHIFT)) & DRY_RAC_TER_MASK)

#define DRY_RAC_PDR_MASK                         (0x400U)
#define DRY_RAC_PDR_SHIFT                        (10U)
/*! PDR - Pin Direction Read
 *  0b0..Reads to the pin direction register are ignored.
 *  0b1..Reads to the pin direction register complete as normal.
 */
#define DRY_RAC_PDR(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_RAC_PDR_SHIFT)) & DRY_RAC_PDR_MASK)

#define DRY_RAC_PPR_MASK                         (0x800U)
#define DRY_RAC_PPR_SHIFT                        (11U)
/*! PPR - Pin Polarity Read
 *  0b0..Reads to the pin polarity register are ignored.
 *  0b1..Reads to the pin polarity register complete as normal.
 */
#define DRY_RAC_PPR(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_RAC_PPR_SHIFT)) & DRY_RAC_PPR_MASK)

#define DRY_RAC_ATR_MASK                         (0x3000U)
#define DRY_RAC_ATR_SHIFT                        (12U)
/*! ATR - Active Tamper Read
 *  0b00..Reads to the active tamper register are ignored.
 *  0b01..Reads to the active tamper register complete as normal.
 */
#define DRY_RAC_ATR(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_RAC_ATR_SHIFT)) & DRY_RAC_ATR_MASK)

#define DRY_RAC_GFR_MASK                         (0xFF0000U)
#define DRY_RAC_GFR_SHIFT                        (16U)
/*! GFR - Glitch Filter Read
 *  0b00000000..Reads to the pin glitch filter register are ignored.
 *  0b00000001..Reads to the pin glitch filter register complete as normal.
 */
#define DRY_RAC_GFR(x)                           (((uint32_t)(((uint32_t)(x)) << DRY_RAC_GFR_SHIFT)) & DRY_RAC_GFR_MASK)
/*! @} */

/*! @name SKR - Secure Key Register */
/*! @{ */

#define DRY_SKR_SK_MASK                          (0xFFFFFFFFU)
#define DRY_SKR_SK_SHIFT                         (0U)
/*! SK - Secure Key */
#define DRY_SKR_SK(x)                            (((uint32_t)(((uint32_t)(x)) << DRY_SKR_SK_SHIFT)) & DRY_SKR_SK_MASK)
/*! @} */

/*! @name SWAC - Secure Write Access Control */
/*! @{ */

#define DRY_SWAC_SKRW_MASK                       (0xFFU)
#define DRY_SWAC_SKRW_SHIFT                      (0U)
/*! SKRW - Secure Key Register Write
 *  0b00000000..Writes to the corresponding Secure Key Register are ignored.
 *  0b00000001..Writes to the correspondingSecure Key Register complete as normal.
 */
#define DRY_SWAC_SKRW(x)                         (((uint32_t)(((uint32_t)(x)) << DRY_SWAC_SKRW_SHIFT)) & DRY_SWAC_SKRW_MASK)
/*! @} */

/*! @name SRAC - Secure Read Access Control */
/*! @{ */

#define DRY_SRAC_SKRR_MASK                       (0xFFU)
#define DRY_SRAC_SKRR_SHIFT                      (0U)
/*! SKRR - Secure Key Register Read
 *  0b00000000..Reads to the corresponding Secure Key Register are ignored.
 *  0b00000001..Reads to the corresponding Secure Key Register complete as normal.
 */
#define DRY_SRAC_SKRR(x)                         (((uint32_t)(((uint32_t)(x)) << DRY_SRAC_SKRR_SHIFT)) & DRY_SRAC_SKRR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DRY_Register_Masks */


/*!
 * @}
 */ /* end of group DRY_Peripheral_Access_Layer */


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


#endif  /* DRY_H_ */

