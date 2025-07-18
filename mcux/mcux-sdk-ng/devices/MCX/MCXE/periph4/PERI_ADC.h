/*
** ###################################################################
**     Processors:          MCXE317MPA
**                          MCXE317MPB
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ADC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_ADC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for ADC
 *
 * CMSIS Peripheral Access Layer for ADC
 */

#if !defined(PERI_ADC_H_)
#define PERI_ADC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE317MPA) || defined(CPU_MCXE317MPB))
#include "MCXE317_COMMON.h"
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
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Size of Registers Arrays */
#define ADC_THRHLR_COUNT                          4u
#define ADC_CDR1_COUNT                            8u
#define ADC_CDR2_COUNT                            24u
#define ADC_CDR3_COUNT                            32u
#define ADC_CWSELRPI_COUNT                        2u
#define ADC_CWSELRSI_COUNT                        3u
#define ADC_CWSELREI_COUNT                        4u

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Main Configuration, offset: 0x0 */
  __I  uint32_t MSR;                               /**< Main Status, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t ISR;                               /**< Interrupt Status, offset: 0x10 */
  __IO uint32_t CEOCFR0;                           /**< Channel End Of Conversion Flag For Precision Inputs, offset: 0x14 */
  __IO uint32_t CEOCFR1;                           /**< Channel End Of Conversion Flag For Standard Inputs, offset: 0x18 */
  __IO uint32_t CEOCFR2;                           /**< Channel End Of Conversion Flag For External Inputs, offset: 0x1C */
  __IO uint32_t IMR;                               /**< Interrupt Mask, offset: 0x20 */
  __IO uint32_t CIMR0;                             /**< EOC Interrupt Enable For Precision Inputs, offset: 0x24 */
  __IO uint32_t CIMR1;                             /**< EOC Interrupt Enable For Standard Inputs, offset: 0x28 */
  __IO uint32_t CIMR2;                             /**< EOC Interrupt Enable For External Inputs, offset: 0x2C */
  __IO uint32_t WTISR;                             /**< Analog Watchdog Threshold Interrupt Status, offset: 0x30 */
  __IO uint32_t WTIMR;                             /**< Analog Watchdog Threshold Interrupt Enable, offset: 0x34 */
       uint8_t RESERVED_1[8];
  __IO uint32_t DMAE;                              /**< Direct Memory Access Configuration, offset: 0x40 */
  __IO uint32_t DMAR0;                             /**< DMA Request Enable For Precision Inputs, offset: 0x44 */
  __IO uint32_t DMAR1;                             /**< DMA Request Enable For Standard Inputs, offset: 0x48 */
  __IO uint32_t DMAR2;                             /**< DMA Request Enable For External Inputs, offset: 0x4C */
       uint8_t RESERVED_2[16];
  __IO uint32_t THRHLR[ADC_THRHLR_COUNT];          /**< Analog Watchdog Threshold Values, array offset: 0x60, array step: 0x4 */
       uint8_t RESERVED_3[16];
  __IO uint32_t PSCR;                              /**< Presampling Control, offset: 0x80 */
  __IO uint32_t PSR0;                              /**< Presampling Enable For Precision Inputs, offset: 0x84 */
  __IO uint32_t PSR1;                              /**< Presampling Enable For Standard Inputs, offset: 0x88 */
  __IO uint32_t PSR2;                              /**< Presampling Enable For External Inputs, offset: 0x8C */
       uint8_t RESERVED_4[4];
  __IO uint32_t CTR0;                              /**< Conversion Timing For Precision Inputs, offset: 0x94 */
  __IO uint32_t CTR1;                              /**< Conversion Timing For Standard Inputs, offset: 0x98 */
  __IO uint32_t CTR2;                              /**< Conversion Timing For External Inputs, offset: 0x9C */
       uint8_t RESERVED_5[4];
  __IO uint32_t NCMR0;                             /**< Normal Conversion Enable For Precision Inputs, offset: 0xA4 */
  __IO uint32_t NCMR1;                             /**< Normal Conversion Enable For Standard Inputs, offset: 0xA8 */
  __IO uint32_t NCMR2;                             /**< Normal Conversion Enable For External Inputs, offset: 0xAC */
       uint8_t RESERVED_6[4];
  __IO uint32_t JCMR0;                             /**< Injected Conversion Enable For Precision Inputs, offset: 0xB4 */
  __IO uint32_t JCMR1;                             /**< Injected Conversion Enable For Standard Inputs, offset: 0xB8 */
  __IO uint32_t JCMR2;                             /**< Injected Conversion Enable For External Inputs, offset: 0xBC */
       uint8_t RESERVED_7[4];
  __IO uint32_t DSDR;                              /**< Delay Start Of Data Conversion, offset: 0xC4 */
  __IO uint32_t PDEDR;                             /**< Power Down Exit Delay, offset: 0xC8 */
       uint8_t RESERVED_8[52];
  __I  uint32_t PCDR[ADC_CDR1_COUNT];              /**< Precision Input n Conversion Data, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_9[96];
  __I  uint32_t ICDR[ADC_CDR2_COUNT];              /**< Standard Input n Conversion Data, array offset: 0x180, array step: 0x4 */
       uint8_t RESERVED_10[32];
  __I  uint32_t ECDR[ADC_CDR3_COUNT];              /**< External Input n Conversion Data, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_11[48];
  __IO uint32_t CWSELRPI[ADC_CWSELRPI_COUNT];      /**< Channel Analog Watchdog Select For Precision Inputs, array offset: 0x2B0, array step: 0x4 */
       uint8_t RESERVED_12[8];
  __IO uint32_t CWSELRSI[ADC_CWSELRSI_COUNT];      /**< Channel Analog Watchdog Select For Standard Inputs, array offset: 0x2C0, array step: 0x4 */
       uint8_t RESERVED_13[4];
  __IO uint32_t CWSELREI[ADC_CWSELREI_COUNT];      /**< Channel Analog Watchdog Select For External inputs, array offset: 0x2D0, array step: 0x4 */
  __IO uint32_t CWENR0;                            /**< Channel Watchdog Enable For Precision Inputs, offset: 0x2E0 */
  __IO uint32_t CWENR1;                            /**< Channel Watchdog Enable For Standard Inputs, offset: 0x2E4 */
  __IO uint32_t CWENR2;                            /**< Channel Watchdog Enable For External Inputs, offset: 0x2E8 */
       uint8_t RESERVED_14[4];
  __IO uint32_t AWORR0;                            /**< Analog Watchdog Out Of Range For Precision Inputs, offset: 0x2F0 */
  __IO uint32_t AWORR1;                            /**< Analog Watchdog Out Of Range For Standard Inputs, offset: 0x2F4 */
  __IO uint32_t AWORR2;                            /**< Analog Watchdog Out Of Range For External Inputs, offset: 0x2F8 */
       uint8_t RESERVED_15[68];
  __IO uint32_t STCR1;                             /**< Self-Test Configuration 1, offset: 0x340 */
  __IO uint32_t STCR2;                             /**< Self-Test Configuration 2, offset: 0x344 */
  __IO uint32_t STCR3;                             /**< Self-Test Configuration 3, offset: 0x348 */
  __IO uint32_t STBRR;                             /**< Self-Test Baud Rate, offset: 0x34C */
  __IO uint32_t STSR1;                             /**< Self-Test Status 1, offset: 0x350 */
  __I  uint32_t STSR2;                             /**< Self-Test Status 2, offset: 0x354 */
  __I  uint32_t STSR3;                             /**< Self-Test Status 3, offset: 0x358 */
  __I  uint32_t STSR4;                             /**< Self-Test Status 4, offset: 0x35C */
       uint8_t RESERVED_16[16];
  __I  uint32_t STDR1;                             /**< Self-Test Conversion Data 1, offset: 0x370 */
       uint8_t RESERVED_17[12];
  __IO uint32_t STAW0R;                            /**< Self-Test Analog Watchdog S0, offset: 0x380 */
       uint8_t RESERVED_18[4];
  __IO uint32_t STAW1R;                            /**< Self-Test Analog Watchdog S1, offset: 0x388 */
  __IO uint32_t STAW2R;                            /**< Self-Test Analog Watchdog S2, offset: 0x38C */
       uint8_t RESERVED_19[4];
  __IO uint32_t STAW4R;                            /**< Self-Test Analog Watchdog C0, offset: 0x394 */
  __IO uint32_t STAW5R;                            /**< Self-Test Analog Watchdog C, offset: 0x398 */
  __IO uint32_t AMSIO;                             /**< Analog Miscellaneous In/Out register, offset: 0x39C */
  __IO uint32_t CALBISTREG;                        /**< Control And Calibration Status, offset: 0x3A0 */
       uint8_t RESERVED_20[4];
  __IO uint32_t OFSGNUSR;                          /**< Offset And Gain User, offset: 0x3A8 */
       uint8_t RESERVED_21[8];
  __IO uint32_t CAL2;                              /**< Calibration Value 2, offset: 0x3B4 */
} ADC_Type;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/*! @name MCR - Main Configuration */
/*! @{ */

#define ADC_MCR_PWDN_MASK                        (0x1U)
#define ADC_MCR_PWDN_SHIFT                       (0U)
/*! PWDN - Power Down
 *  0b0..ADC enters a functional state
 *  0b1..ADC enters Power Down state
 */
#define ADC_MCR_PWDN(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MCR_PWDN_SHIFT)) & ADC_MCR_PWDN_MASK)

#define ADC_MCR_ADCLKSEL_MASK                    (0x6U)
#define ADC_MCR_ADCLKSEL_SHIFT                   (1U)
/*! ADCLKSEL - Conversion Clock (AD_clk) Frequency Selection
 *  0b00..Module clock frequency
 *  0b01..Module clock frequency / 2
 *  0b10..Module clock frequency / 4
 */
#define ADC_MCR_ADCLKSEL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_MCR_ADCLKSEL_SHIFT)) & ADC_MCR_ADCLKSEL_MASK)

#define ADC_MCR_ACKO_MASK                        (0x20U)
#define ADC_MCR_ACKO_SHIFT                       (5U)
/*! ACKO - Auto Clock Off
 *  0b0..Clock always active
 *  0b1..Clock gated
 */
#define ADC_MCR_ACKO(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MCR_ACKO_SHIFT)) & ADC_MCR_ACKO_MASK)

#define ADC_MCR_ABORT_MASK                       (0x40U)
#define ADC_MCR_ABORT_SHIFT                      (6U)
/*! ABORT - Abort Conversion
 *  0b0..Conversion continues
 *  0b0..Undefined
 *  0b1..Conversion aborted
 */
#define ADC_MCR_ABORT(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_MCR_ABORT_SHIFT)) & ADC_MCR_ABORT_MASK)

#define ADC_MCR_ABORTCHAIN_MASK                  (0x80U)
#define ADC_MCR_ABORTCHAIN_SHIFT                 (7U)
/*! ABORTCHAIN - Abort Chain
 *  0b0..Conversion continues
 *  0b0..Undefined
 *  0b1..Conversion aborted
 */
#define ADC_MCR_ABORTCHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_MCR_ABORTCHAIN_SHIFT)) & ADC_MCR_ABORTCHAIN_MASK)

#define ADC_MCR_AVGS_MASK                        (0x600U)
#define ADC_MCR_AVGS_SHIFT                       (9U)
/*! AVGS - Averaging Select
 *  0b00..4 conversions
 *  0b01..8 conversions
 *  0b10..16 conversions
 *  0b11..32 conversions
 */
#define ADC_MCR_AVGS(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MCR_AVGS_SHIFT)) & ADC_MCR_AVGS_MASK)

#define ADC_MCR_AVGEN_MASK                       (0x800U)
#define ADC_MCR_AVGEN_SHIFT                      (11U)
/*! AVGEN - Averaging Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_MCR_AVGEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_MCR_AVGEN_SHIFT)) & ADC_MCR_AVGEN_MASK)

#define ADC_MCR_STCL_MASK                        (0x8000U)
#define ADC_MCR_STCL_SHIFT                       (15U)
/*! STCL - Self-Test Configuration Lock
 *  0b0..Registers are writeable
 *  0b1..Registers are read-only
 */
#define ADC_MCR_STCL(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MCR_STCL_SHIFT)) & ADC_MCR_STCL_MASK)

#define ADC_MCR_BCTU_MODE_MASK                   (0x10000U)
#define ADC_MCR_BCTU_MODE_SHIFT                  (16U)
/*! BCTU_MODE - Body Cross Trigger Unit Mode Select
 *  0b0..Only BCTU can trigger conversion
 *  0b1..All trigger sources can trigger conversion
 */
#define ADC_MCR_BCTU_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_MCR_BCTU_MODE_SHIFT)) & ADC_MCR_BCTU_MODE_MASK)

#define ADC_MCR_BCTUEN_MASK                      (0x20000U)
#define ADC_MCR_BCTUEN_SHIFT                     (17U)
/*! BCTUEN - Body Cross Trigger Unit Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_MCR_BCTUEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MCR_BCTUEN_SHIFT)) & ADC_MCR_BCTUEN_MASK)

#define ADC_MCR_JSTART_MASK                      (0x100000U)
#define ADC_MCR_JSTART_SHIFT                     (20U)
/*! JSTART - Injected Start
 *  0b0..Injected conversion can be started
 *  0b1..Starts an injected conversion
 */
#define ADC_MCR_JSTART(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MCR_JSTART_SHIFT)) & ADC_MCR_JSTART_MASK)

#define ADC_MCR_JEDGE_MASK                       (0x200000U)
#define ADC_MCR_JEDGE_SHIFT                      (21U)
/*! JEDGE - Injected Trigger Edge Selection
 *  0b0..Falling edge
 *  0b1..Rising edge
 */
#define ADC_MCR_JEDGE(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_MCR_JEDGE_SHIFT)) & ADC_MCR_JEDGE_MASK)

#define ADC_MCR_JTRGEN_MASK                      (0x400000U)
#define ADC_MCR_JTRGEN_SHIFT                     (22U)
/*! JTRGEN - Injection Trigger Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_MCR_JTRGEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MCR_JTRGEN_SHIFT)) & ADC_MCR_JTRGEN_MASK)

#define ADC_MCR_NSTART_MASK                      (0x1000000U)
#define ADC_MCR_NSTART_SHIFT                     (24U)
/*! NSTART - Start Normal Conversion
 *  0b0..No effect
 *  0b1..Starts conversion
 */
#define ADC_MCR_NSTART(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MCR_NSTART_SHIFT)) & ADC_MCR_NSTART_MASK)

#define ADC_MCR_XSTRTEN_MASK                     (0x2000000U)
#define ADC_MCR_XSTRTEN_SHIFT                    (25U)
/*! XSTRTEN - Auxiliary External Start Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_MCR_XSTRTEN(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_MCR_XSTRTEN_SHIFT)) & ADC_MCR_XSTRTEN_MASK)

#define ADC_MCR_EDGE_MASK                        (0x4000000U)
#define ADC_MCR_EDGE_SHIFT                       (26U)
/*! EDGE - External Trigger Edge Selection
 *  0b0..Falling edge
 *  0b1..Rising edge
 */
#define ADC_MCR_EDGE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MCR_EDGE_SHIFT)) & ADC_MCR_EDGE_MASK)

#define ADC_MCR_TRGEN_MASK                       (0x8000000U)
#define ADC_MCR_TRGEN_SHIFT                      (27U)
/*! TRGEN - External Trigger Enable
 *  0b0..Normal trigger input does not start a conversion
 *  0b1..Normal trigger input starts a conversion
 */
#define ADC_MCR_TRGEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_MCR_TRGEN_SHIFT)) & ADC_MCR_TRGEN_MASK)

#define ADC_MCR_MODE_MASK                        (0x20000000U)
#define ADC_MCR_MODE_SHIFT                       (29U)
/*! MODE - Normal Conversion Mode
 *  0b0..Single conversion
 *  0b1..Continuous conversion
 */
#define ADC_MCR_MODE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MCR_MODE_SHIFT)) & ADC_MCR_MODE_MASK)

#define ADC_MCR_WLSIDE_MASK                      (0x40000000U)
#define ADC_MCR_WLSIDE_SHIFT                     (30U)
/*! WLSIDE - Write Left-Aligned
 *  0b0..Right aligned
 *  0b1..Left-aligned
 */
#define ADC_MCR_WLSIDE(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MCR_WLSIDE_SHIFT)) & ADC_MCR_WLSIDE_MASK)

#define ADC_MCR_OWREN_MASK                       (0x80000000U)
#define ADC_MCR_OWREN_SHIFT                      (31U)
/*! OWREN - Overwrite Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_MCR_OWREN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_MCR_OWREN_SHIFT)) & ADC_MCR_OWREN_MASK)
/*! @} */

/*! @name MSR - Main Status */
/*! @{ */

#define ADC_MSR_ADCSTATUS_MASK                   (0x7U)
#define ADC_MSR_ADCSTATUS_SHIFT                  (0U)
/*! ADCSTATUS - ADC State
 *  0b000..Idle
 *  0b001..Power Down
 *  0b010..Wait
 *  0b011..Calibrate
 *  0b100..Convert
 *  0b110..Done
 */
#define ADC_MSR_ADCSTATUS(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_MSR_ADCSTATUS_SHIFT)) & ADC_MSR_ADCSTATUS_MASK)

#define ADC_MSR_ACKO_MASK                        (0x20U)
#define ADC_MSR_ACKO_SHIFT                       (5U)
/*! ACKO - Auto Clock-Off On
 *  0b0..Inactive
 *  0b1..Active
 */
#define ADC_MSR_ACKO(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_MSR_ACKO_SHIFT)) & ADC_MSR_ACKO_MASK)

#define ADC_MSR_CHADDR_MASK                      (0xFE00U)
#define ADC_MSR_CHADDR_SHIFT                     (9U)
/*! CHADDR - Input Under Measure
 *  0b0000000-0b0111111..Input number
 */
#define ADC_MSR_CHADDR(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MSR_CHADDR_SHIFT)) & ADC_MSR_CHADDR_MASK)

#define ADC_MSR_BCTUSTART_MASK                   (0x10000U)
#define ADC_MSR_BCTUSTART_SHIFT                  (16U)
/*! BCTUSTART - BCTU Conversion Started
 *  0b0..Conversion was not triggered by BCTU
 *  0b1..Ongoing conversion was triggered by BCTU
 */
#define ADC_MSR_BCTUSTART(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_MSR_BCTUSTART_SHIFT)) & ADC_MSR_BCTUSTART_MASK)

#define ADC_MSR_SELF_TEST_S_MASK                 (0x40000U)
#define ADC_MSR_SELF_TEST_S_SHIFT                (18U)
/*! SELF_TEST_S
 *  0b0..Not self-test
 *  0b1..Self-test
 */
#define ADC_MSR_SELF_TEST_S(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_MSR_SELF_TEST_S_SHIFT)) & ADC_MSR_SELF_TEST_S_MASK)

#define ADC_MSR_JSTART_MASK                      (0x100000U)
#define ADC_MSR_JSTART_SHIFT                     (20U)
/*! JSTART - Injected Conversion Started
 *  0b0..Not an injected conversion
 *  0b1..Injected conversion
 */
#define ADC_MSR_JSTART(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MSR_JSTART_SHIFT)) & ADC_MSR_JSTART_MASK)

#define ADC_MSR_JABORT_MASK                      (0x800000U)
#define ADC_MSR_JABORT_SHIFT                     (23U)
/*! JABORT - Injected Conversion Aborted
 *  0b0..Not aborted
 *  0b1..Aborted
 */
#define ADC_MSR_JABORT(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MSR_JABORT_SHIFT)) & ADC_MSR_JABORT_MASK)

#define ADC_MSR_NSTART_MASK                      (0x1000000U)
#define ADC_MSR_NSTART_SHIFT                     (24U)
/*! NSTART - Normal Conversion Started
 *  0b0..Not in progress
 *  0b1..In progress
 */
#define ADC_MSR_NSTART(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_MSR_NSTART_SHIFT)) & ADC_MSR_NSTART_MASK)

#define ADC_MSR_CALIBRTD_MASK                    (0x80000000U)
#define ADC_MSR_CALIBRTD_SHIFT                   (31U)
/*! CALIBRTD - Calibration Status
 *  0b0..Uncalibrated or calibration unsuccessful
 *  0b1..Calibrated
 */
#define ADC_MSR_CALIBRTD(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_MSR_CALIBRTD_SHIFT)) & ADC_MSR_CALIBRTD_MASK)
/*! @} */

/*! @name ISR - Interrupt Status */
/*! @{ */

#define ADC_ISR_ECH_MASK                         (0x1U)
#define ADC_ISR_ECH_SHIFT                        (0U)
/*! ECH - End Of Chain Conversion
 *  0b0..Indicates no ECH interrupt generated
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Indicates an ECH interrupt has been generated
 */
#define ADC_ISR_ECH(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_ISR_ECH_SHIFT)) & ADC_ISR_ECH_MASK)

#define ADC_ISR_EOC_MASK                         (0x2U)
#define ADC_ISR_EOC_SHIFT                        (1U)
/*! EOC - End Of Conversion
 *  0b0..No EOC interrupt generated
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Interrupt generated
 */
#define ADC_ISR_EOC(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_ISR_EOC_SHIFT)) & ADC_ISR_EOC_MASK)

#define ADC_ISR_JECH_MASK                        (0x4U)
#define ADC_ISR_JECH_SHIFT                       (2U)
/*! JECH - End Of Injected Chain Conversion
 *  0b0..No JECH interrupt generated
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..JECH interrupt generated
 */
#define ADC_ISR_JECH(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_ISR_JECH_SHIFT)) & ADC_ISR_JECH_MASK)

#define ADC_ISR_JEOC_MASK                        (0x8U)
#define ADC_ISR_JEOC_SHIFT                       (3U)
/*! JEOC - End Of Injected Conversion
 *  0b0..No JEOC interrupt generated
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..JEOC interrupt generated
 */
#define ADC_ISR_JEOC(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_ISR_JEOC_SHIFT)) & ADC_ISR_JEOC_MASK)

#define ADC_ISR_EOBCTU_MASK                      (0x10U)
#define ADC_ISR_EOBCTU_SHIFT                     (4U)
/*! EOBCTU - End Of BCTU Conversion
 *  0b0..No EOBCTU interrupt generated
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..EOBCTU interrupt generated
 */
#define ADC_ISR_EOBCTU(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ISR_EOBCTU_SHIFT)) & ADC_ISR_EOBCTU_MASK)
/*! @} */

/*! @name CEOCFR0 - Channel End Of Conversion Flag For Precision Inputs */
/*! @{ */

#define ADC_CEOCFR0_PIEOCF0_MASK                 (0x1U)
#define ADC_CEOCFR0_PIEOCF0_SHIFT                (0U)
/*! PIEOCF0 - Precision Input End Of Conversion Flag 0
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_PIEOCF0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_PIEOCF0_SHIFT)) & ADC_CEOCFR0_PIEOCF0_MASK)

#define ADC_CEOCFR0_PIEOCF1_MASK                 (0x2U)
#define ADC_CEOCFR0_PIEOCF1_SHIFT                (1U)
/*! PIEOCF1 - Precision Input End Of Conversion Flag 1
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_PIEOCF1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_PIEOCF1_SHIFT)) & ADC_CEOCFR0_PIEOCF1_MASK)

#define ADC_CEOCFR0_PIEOCF2_MASK                 (0x4U)
#define ADC_CEOCFR0_PIEOCF2_SHIFT                (2U)
/*! PIEOCF2 - Precision Input End Of Conversion Flag 2
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_PIEOCF2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_PIEOCF2_SHIFT)) & ADC_CEOCFR0_PIEOCF2_MASK)

#define ADC_CEOCFR0_PIEOCF3_MASK                 (0x8U)
#define ADC_CEOCFR0_PIEOCF3_SHIFT                (3U)
/*! PIEOCF3 - Precision Input End Of Conversion Flag 3
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_PIEOCF3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_PIEOCF3_SHIFT)) & ADC_CEOCFR0_PIEOCF3_MASK)

#define ADC_CEOCFR0_PIEOCF4_MASK                 (0x10U)
#define ADC_CEOCFR0_PIEOCF4_SHIFT                (4U)
/*! PIEOCF4 - Precision Input End Of Conversion Flag 4
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_PIEOCF4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_PIEOCF4_SHIFT)) & ADC_CEOCFR0_PIEOCF4_MASK)

#define ADC_CEOCFR0_PIEOCF5_MASK                 (0x20U)
#define ADC_CEOCFR0_PIEOCF5_SHIFT                (5U)
/*! PIEOCF5 - Precision Input End Of Conversion Flag 5
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_PIEOCF5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_PIEOCF5_SHIFT)) & ADC_CEOCFR0_PIEOCF5_MASK)

#define ADC_CEOCFR0_PIEOCF6_MASK                 (0x40U)
#define ADC_CEOCFR0_PIEOCF6_SHIFT                (6U)
/*! PIEOCF6 - Precision Input End Of Conversion Flag 6
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_PIEOCF6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_PIEOCF6_SHIFT)) & ADC_CEOCFR0_PIEOCF6_MASK)

#define ADC_CEOCFR0_PIEOCF7_MASK                 (0x80U)
#define ADC_CEOCFR0_PIEOCF7_SHIFT                (7U)
/*! PIEOCF7 - Precision Input End Of Conversion Flag 7
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR0_PIEOCF7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR0_PIEOCF7_SHIFT)) & ADC_CEOCFR0_PIEOCF7_MASK)
/*! @} */

/*! @name CEOCFR1 - Channel End Of Conversion Flag For Standard Inputs */
/*! @{ */

#define ADC_CEOCFR1_SIEOCF0_MASK                 (0x1U)
#define ADC_CEOCFR1_SIEOCF0_SHIFT                (0U)
/*! SIEOCF0 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF0_SHIFT)) & ADC_CEOCFR1_SIEOCF0_MASK)

#define ADC_CEOCFR1_SIEOCF1_MASK                 (0x2U)
#define ADC_CEOCFR1_SIEOCF1_SHIFT                (1U)
/*! SIEOCF1 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF1_SHIFT)) & ADC_CEOCFR1_SIEOCF1_MASK)

#define ADC_CEOCFR1_SIEOCF2_MASK                 (0x4U)
#define ADC_CEOCFR1_SIEOCF2_SHIFT                (2U)
/*! SIEOCF2 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF2_SHIFT)) & ADC_CEOCFR1_SIEOCF2_MASK)

#define ADC_CEOCFR1_SIEOCF3_MASK                 (0x8U)
#define ADC_CEOCFR1_SIEOCF3_SHIFT                (3U)
/*! SIEOCF3 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF3_SHIFT)) & ADC_CEOCFR1_SIEOCF3_MASK)

#define ADC_CEOCFR1_SIEOCF4_MASK                 (0x10U)
#define ADC_CEOCFR1_SIEOCF4_SHIFT                (4U)
/*! SIEOCF4 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF4_SHIFT)) & ADC_CEOCFR1_SIEOCF4_MASK)

#define ADC_CEOCFR1_SIEOCF5_MASK                 (0x20U)
#define ADC_CEOCFR1_SIEOCF5_SHIFT                (5U)
/*! SIEOCF5 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF5_SHIFT)) & ADC_CEOCFR1_SIEOCF5_MASK)

#define ADC_CEOCFR1_SIEOCF6_MASK                 (0x40U)
#define ADC_CEOCFR1_SIEOCF6_SHIFT                (6U)
/*! SIEOCF6 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF6_SHIFT)) & ADC_CEOCFR1_SIEOCF6_MASK)

#define ADC_CEOCFR1_SIEOCF7_MASK                 (0x80U)
#define ADC_CEOCFR1_SIEOCF7_SHIFT                (7U)
/*! SIEOCF7 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF7_SHIFT)) & ADC_CEOCFR1_SIEOCF7_MASK)

#define ADC_CEOCFR1_SIEOCF8_MASK                 (0x100U)
#define ADC_CEOCFR1_SIEOCF8_SHIFT                (8U)
/*! SIEOCF8 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF8(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF8_SHIFT)) & ADC_CEOCFR1_SIEOCF8_MASK)

#define ADC_CEOCFR1_SIEOCF9_MASK                 (0x200U)
#define ADC_CEOCFR1_SIEOCF9_SHIFT                (9U)
/*! SIEOCF9 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF9(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF9_SHIFT)) & ADC_CEOCFR1_SIEOCF9_MASK)

#define ADC_CEOCFR1_SIEOCF10_MASK                (0x400U)
#define ADC_CEOCFR1_SIEOCF10_SHIFT               (10U)
/*! SIEOCF10 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF10(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF10_SHIFT)) & ADC_CEOCFR1_SIEOCF10_MASK)

#define ADC_CEOCFR1_SIEOCF11_MASK                (0x800U)
#define ADC_CEOCFR1_SIEOCF11_SHIFT               (11U)
/*! SIEOCF11 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF11(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF11_SHIFT)) & ADC_CEOCFR1_SIEOCF11_MASK)

#define ADC_CEOCFR1_SIEOCF12_MASK                (0x1000U)
#define ADC_CEOCFR1_SIEOCF12_SHIFT               (12U)
/*! SIEOCF12 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF12(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF12_SHIFT)) & ADC_CEOCFR1_SIEOCF12_MASK)

#define ADC_CEOCFR1_SIEOCF13_MASK                (0x2000U)
#define ADC_CEOCFR1_SIEOCF13_SHIFT               (13U)
/*! SIEOCF13 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF13(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF13_SHIFT)) & ADC_CEOCFR1_SIEOCF13_MASK)

#define ADC_CEOCFR1_SIEOCF14_MASK                (0x4000U)
#define ADC_CEOCFR1_SIEOCF14_SHIFT               (14U)
/*! SIEOCF14 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF14(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF14_SHIFT)) & ADC_CEOCFR1_SIEOCF14_MASK)

#define ADC_CEOCFR1_SIEOCF15_MASK                (0x8000U)
#define ADC_CEOCFR1_SIEOCF15_SHIFT               (15U)
/*! SIEOCF15 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF15(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF15_SHIFT)) & ADC_CEOCFR1_SIEOCF15_MASK)

#define ADC_CEOCFR1_SIEOCF16_MASK                (0x10000U)
#define ADC_CEOCFR1_SIEOCF16_SHIFT               (16U)
/*! SIEOCF16 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF16(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF16_SHIFT)) & ADC_CEOCFR1_SIEOCF16_MASK)

#define ADC_CEOCFR1_SIEOCF17_MASK                (0x20000U)
#define ADC_CEOCFR1_SIEOCF17_SHIFT               (17U)
/*! SIEOCF17 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF17(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF17_SHIFT)) & ADC_CEOCFR1_SIEOCF17_MASK)

#define ADC_CEOCFR1_SIEOCF18_MASK                (0x40000U)
#define ADC_CEOCFR1_SIEOCF18_SHIFT               (18U)
/*! SIEOCF18 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF18(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF18_SHIFT)) & ADC_CEOCFR1_SIEOCF18_MASK)

#define ADC_CEOCFR1_SIEOCF19_MASK                (0x80000U)
#define ADC_CEOCFR1_SIEOCF19_SHIFT               (19U)
/*! SIEOCF19 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF19(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF19_SHIFT)) & ADC_CEOCFR1_SIEOCF19_MASK)

#define ADC_CEOCFR1_SIEOCF20_MASK                (0x100000U)
#define ADC_CEOCFR1_SIEOCF20_SHIFT               (20U)
/*! SIEOCF20 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF20(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF20_SHIFT)) & ADC_CEOCFR1_SIEOCF20_MASK)

#define ADC_CEOCFR1_SIEOCF21_MASK                (0x200000U)
#define ADC_CEOCFR1_SIEOCF21_SHIFT               (21U)
/*! SIEOCF21 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF21(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF21_SHIFT)) & ADC_CEOCFR1_SIEOCF21_MASK)

#define ADC_CEOCFR1_SIEOCF22_MASK                (0x400000U)
#define ADC_CEOCFR1_SIEOCF22_SHIFT               (22U)
/*! SIEOCF22 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF22(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF22_SHIFT)) & ADC_CEOCFR1_SIEOCF22_MASK)

#define ADC_CEOCFR1_SIEOCF23_MASK                (0x800000U)
#define ADC_CEOCFR1_SIEOCF23_SHIFT               (23U)
/*! SIEOCF23 - Standard Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR1_SIEOCF23(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR1_SIEOCF23_SHIFT)) & ADC_CEOCFR1_SIEOCF23_MASK)
/*! @} */

/*! @name CEOCFR2 - Channel End Of Conversion Flag For External Inputs */
/*! @{ */

#define ADC_CEOCFR2_EIEOCF0_MASK                 (0x1U)
#define ADC_CEOCFR2_EIEOCF0_SHIFT                (0U)
/*! EIEOCF0 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF0_SHIFT)) & ADC_CEOCFR2_EIEOCF0_MASK)

#define ADC_CEOCFR2_EIEOCF1_MASK                 (0x2U)
#define ADC_CEOCFR2_EIEOCF1_SHIFT                (1U)
/*! EIEOCF1 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF1_SHIFT)) & ADC_CEOCFR2_EIEOCF1_MASK)

#define ADC_CEOCFR2_EIEOCF2_MASK                 (0x4U)
#define ADC_CEOCFR2_EIEOCF2_SHIFT                (2U)
/*! EIEOCF2 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF2_SHIFT)) & ADC_CEOCFR2_EIEOCF2_MASK)

#define ADC_CEOCFR2_EIEOCF3_MASK                 (0x8U)
#define ADC_CEOCFR2_EIEOCF3_SHIFT                (3U)
/*! EIEOCF3 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF3_SHIFT)) & ADC_CEOCFR2_EIEOCF3_MASK)

#define ADC_CEOCFR2_EIEOCF4_MASK                 (0x10U)
#define ADC_CEOCFR2_EIEOCF4_SHIFT                (4U)
/*! EIEOCF4 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF4_SHIFT)) & ADC_CEOCFR2_EIEOCF4_MASK)

#define ADC_CEOCFR2_EIEOCF5_MASK                 (0x20U)
#define ADC_CEOCFR2_EIEOCF5_SHIFT                (5U)
/*! EIEOCF5 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF5_SHIFT)) & ADC_CEOCFR2_EIEOCF5_MASK)

#define ADC_CEOCFR2_EIEOCF6_MASK                 (0x40U)
#define ADC_CEOCFR2_EIEOCF6_SHIFT                (6U)
/*! EIEOCF6 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF6_SHIFT)) & ADC_CEOCFR2_EIEOCF6_MASK)

#define ADC_CEOCFR2_EIEOCF7_MASK                 (0x80U)
#define ADC_CEOCFR2_EIEOCF7_SHIFT                (7U)
/*! EIEOCF7 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF7_SHIFT)) & ADC_CEOCFR2_EIEOCF7_MASK)

#define ADC_CEOCFR2_EIEOCF8_MASK                 (0x100U)
#define ADC_CEOCFR2_EIEOCF8_SHIFT                (8U)
/*! EIEOCF8 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF8(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF8_SHIFT)) & ADC_CEOCFR2_EIEOCF8_MASK)

#define ADC_CEOCFR2_EIEOCF9_MASK                 (0x200U)
#define ADC_CEOCFR2_EIEOCF9_SHIFT                (9U)
/*! EIEOCF9 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF9(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF9_SHIFT)) & ADC_CEOCFR2_EIEOCF9_MASK)

#define ADC_CEOCFR2_EIEOCF10_MASK                (0x400U)
#define ADC_CEOCFR2_EIEOCF10_SHIFT               (10U)
/*! EIEOCF10 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF10(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF10_SHIFT)) & ADC_CEOCFR2_EIEOCF10_MASK)

#define ADC_CEOCFR2_EIEOCF11_MASK                (0x800U)
#define ADC_CEOCFR2_EIEOCF11_SHIFT               (11U)
/*! EIEOCF11 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF11(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF11_SHIFT)) & ADC_CEOCFR2_EIEOCF11_MASK)

#define ADC_CEOCFR2_EIEOCF12_MASK                (0x1000U)
#define ADC_CEOCFR2_EIEOCF12_SHIFT               (12U)
/*! EIEOCF12 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF12(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF12_SHIFT)) & ADC_CEOCFR2_EIEOCF12_MASK)

#define ADC_CEOCFR2_EIEOCF13_MASK                (0x2000U)
#define ADC_CEOCFR2_EIEOCF13_SHIFT               (13U)
/*! EIEOCF13 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF13(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF13_SHIFT)) & ADC_CEOCFR2_EIEOCF13_MASK)

#define ADC_CEOCFR2_EIEOCF14_MASK                (0x4000U)
#define ADC_CEOCFR2_EIEOCF14_SHIFT               (14U)
/*! EIEOCF14 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF14(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF14_SHIFT)) & ADC_CEOCFR2_EIEOCF14_MASK)

#define ADC_CEOCFR2_EIEOCF15_MASK                (0x8000U)
#define ADC_CEOCFR2_EIEOCF15_SHIFT               (15U)
/*! EIEOCF15 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF15(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF15_SHIFT)) & ADC_CEOCFR2_EIEOCF15_MASK)

#define ADC_CEOCFR2_EIEOCF16_MASK                (0x10000U)
#define ADC_CEOCFR2_EIEOCF16_SHIFT               (16U)
/*! EIEOCF16 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF16(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF16_SHIFT)) & ADC_CEOCFR2_EIEOCF16_MASK)

#define ADC_CEOCFR2_EIEOCF17_MASK                (0x20000U)
#define ADC_CEOCFR2_EIEOCF17_SHIFT               (17U)
/*! EIEOCF17 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF17(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF17_SHIFT)) & ADC_CEOCFR2_EIEOCF17_MASK)

#define ADC_CEOCFR2_EIEOCF18_MASK                (0x40000U)
#define ADC_CEOCFR2_EIEOCF18_SHIFT               (18U)
/*! EIEOCF18 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF18(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF18_SHIFT)) & ADC_CEOCFR2_EIEOCF18_MASK)

#define ADC_CEOCFR2_EIEOCF19_MASK                (0x80000U)
#define ADC_CEOCFR2_EIEOCF19_SHIFT               (19U)
/*! EIEOCF19 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF19(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF19_SHIFT)) & ADC_CEOCFR2_EIEOCF19_MASK)

#define ADC_CEOCFR2_EIEOCF20_MASK                (0x100000U)
#define ADC_CEOCFR2_EIEOCF20_SHIFT               (20U)
/*! EIEOCF20 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF20(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF20_SHIFT)) & ADC_CEOCFR2_EIEOCF20_MASK)

#define ADC_CEOCFR2_EIEOCF21_MASK                (0x200000U)
#define ADC_CEOCFR2_EIEOCF21_SHIFT               (21U)
/*! EIEOCF21 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF21(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF21_SHIFT)) & ADC_CEOCFR2_EIEOCF21_MASK)

#define ADC_CEOCFR2_EIEOCF22_MASK                (0x400000U)
#define ADC_CEOCFR2_EIEOCF22_SHIFT               (22U)
/*! EIEOCF22 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF22(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF22_SHIFT)) & ADC_CEOCFR2_EIEOCF22_MASK)

#define ADC_CEOCFR2_EIEOCF23_MASK                (0x800000U)
#define ADC_CEOCFR2_EIEOCF23_SHIFT               (23U)
/*! EIEOCF23 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF23(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF23_SHIFT)) & ADC_CEOCFR2_EIEOCF23_MASK)

#define ADC_CEOCFR2_EIEOCF24_MASK                (0x1000000U)
#define ADC_CEOCFR2_EIEOCF24_SHIFT               (24U)
/*! EIEOCF24 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF24(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF24_SHIFT)) & ADC_CEOCFR2_EIEOCF24_MASK)

#define ADC_CEOCFR2_EIEOCF25_MASK                (0x2000000U)
#define ADC_CEOCFR2_EIEOCF25_SHIFT               (25U)
/*! EIEOCF25 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF25(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF25_SHIFT)) & ADC_CEOCFR2_EIEOCF25_MASK)

#define ADC_CEOCFR2_EIEOCF26_MASK                (0x4000000U)
#define ADC_CEOCFR2_EIEOCF26_SHIFT               (26U)
/*! EIEOCF26 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF26(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF26_SHIFT)) & ADC_CEOCFR2_EIEOCF26_MASK)

#define ADC_CEOCFR2_EIEOCF27_MASK                (0x8000000U)
#define ADC_CEOCFR2_EIEOCF27_SHIFT               (27U)
/*! EIEOCF27 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF27(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF27_SHIFT)) & ADC_CEOCFR2_EIEOCF27_MASK)

#define ADC_CEOCFR2_EIEOCF28_MASK                (0x10000000U)
#define ADC_CEOCFR2_EIEOCF28_SHIFT               (28U)
/*! EIEOCF28 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF28(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF28_SHIFT)) & ADC_CEOCFR2_EIEOCF28_MASK)

#define ADC_CEOCFR2_EIEOCF29_MASK                (0x20000000U)
#define ADC_CEOCFR2_EIEOCF29_SHIFT               (29U)
/*! EIEOCF29 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF29(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF29_SHIFT)) & ADC_CEOCFR2_EIEOCF29_MASK)

#define ADC_CEOCFR2_EIEOCF30_MASK                (0x40000000U)
#define ADC_CEOCFR2_EIEOCF30_SHIFT               (30U)
/*! EIEOCF30 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF30(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF30_SHIFT)) & ADC_CEOCFR2_EIEOCF30_MASK)

#define ADC_CEOCFR2_EIEOCF31_MASK                (0x80000000U)
#define ADC_CEOCFR2_EIEOCF31_SHIFT               (31U)
/*! EIEOCF31 - External Input End Of Conversion Flag
 *  0b0..Conversion not complete
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion complete
 */
#define ADC_CEOCFR2_EIEOCF31(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CEOCFR2_EIEOCF31_SHIFT)) & ADC_CEOCFR2_EIEOCF31_MASK)
/*! @} */

/*! @name IMR - Interrupt Mask */
/*! @{ */

#define ADC_IMR_MSKECH_MASK                      (0x1U)
#define ADC_IMR_MSKECH_SHIFT                     (0U)
/*! MSKECH - ECH Interrupt Flag Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_IMR_MSKECH(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_IMR_MSKECH_SHIFT)) & ADC_IMR_MSKECH_MASK)

#define ADC_IMR_MSKEOC_MASK                      (0x2U)
#define ADC_IMR_MSKEOC_SHIFT                     (1U)
/*! MSKEOC - EOC Interrupt Flag Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_IMR_MSKEOC(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_IMR_MSKEOC_SHIFT)) & ADC_IMR_MSKEOC_MASK)

#define ADC_IMR_MSKJECH_MASK                     (0x4U)
#define ADC_IMR_MSKJECH_SHIFT                    (2U)
/*! MSKJECH - JECH Interrupt Flag Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_IMR_MSKJECH(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_IMR_MSKJECH_SHIFT)) & ADC_IMR_MSKJECH_MASK)

#define ADC_IMR_MSKJEOC_MASK                     (0x8U)
#define ADC_IMR_MSKJEOC_SHIFT                    (3U)
/*! MSKJEOC - JEOC Interrupt Flag Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_IMR_MSKJEOC(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_IMR_MSKJEOC_SHIFT)) & ADC_IMR_MSKJEOC_MASK)

#define ADC_IMR_MSKEOBCTU_MASK                   (0x10U)
#define ADC_IMR_MSKEOBCTU_SHIFT                  (4U)
/*! MSKEOBCTU - EOBCTU Interrupt Flag Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_IMR_MSKEOBCTU(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_IMR_MSKEOBCTU_SHIFT)) & ADC_IMR_MSKEOBCTU_MASK)
/*! @} */

/*! @name CIMR0 - EOC Interrupt Enable For Precision Inputs */
/*! @{ */

#define ADC_CIMR0_PIEOCIEN0_MASK                 (0x1U)
#define ADC_CIMR0_PIEOCIEN0_SHIFT                (0U)
/*! PIEOCIEN0 - Precision Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR0_PIEOCIEN0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_PIEOCIEN0_SHIFT)) & ADC_CIMR0_PIEOCIEN0_MASK)

#define ADC_CIMR0_PIEOCIEN1_MASK                 (0x2U)
#define ADC_CIMR0_PIEOCIEN1_SHIFT                (1U)
/*! PIEOCIEN1 - Precision Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR0_PIEOCIEN1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_PIEOCIEN1_SHIFT)) & ADC_CIMR0_PIEOCIEN1_MASK)

#define ADC_CIMR0_PIEOCIEN2_MASK                 (0x4U)
#define ADC_CIMR0_PIEOCIEN2_SHIFT                (2U)
/*! PIEOCIEN2 - Precision Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR0_PIEOCIEN2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_PIEOCIEN2_SHIFT)) & ADC_CIMR0_PIEOCIEN2_MASK)

#define ADC_CIMR0_PIEOCIEN3_MASK                 (0x8U)
#define ADC_CIMR0_PIEOCIEN3_SHIFT                (3U)
/*! PIEOCIEN3 - Precision Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR0_PIEOCIEN3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_PIEOCIEN3_SHIFT)) & ADC_CIMR0_PIEOCIEN3_MASK)

#define ADC_CIMR0_PIEOCIEN4_MASK                 (0x10U)
#define ADC_CIMR0_PIEOCIEN4_SHIFT                (4U)
/*! PIEOCIEN4 - Precision Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR0_PIEOCIEN4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_PIEOCIEN4_SHIFT)) & ADC_CIMR0_PIEOCIEN4_MASK)

#define ADC_CIMR0_PIEOCIEN5_MASK                 (0x20U)
#define ADC_CIMR0_PIEOCIEN5_SHIFT                (5U)
/*! PIEOCIEN5 - Precision Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR0_PIEOCIEN5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_PIEOCIEN5_SHIFT)) & ADC_CIMR0_PIEOCIEN5_MASK)

#define ADC_CIMR0_PIEOCIEN6_MASK                 (0x40U)
#define ADC_CIMR0_PIEOCIEN6_SHIFT                (6U)
/*! PIEOCIEN6 - Precision Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR0_PIEOCIEN6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_PIEOCIEN6_SHIFT)) & ADC_CIMR0_PIEOCIEN6_MASK)

#define ADC_CIMR0_PIEOCIEN7_MASK                 (0x80U)
#define ADC_CIMR0_PIEOCIEN7_SHIFT                (7U)
/*! PIEOCIEN7 - Precision Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR0_PIEOCIEN7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR0_PIEOCIEN7_SHIFT)) & ADC_CIMR0_PIEOCIEN7_MASK)
/*! @} */

/*! @name CIMR1 - EOC Interrupt Enable For Standard Inputs */
/*! @{ */

#define ADC_CIMR1_SIEOCIEN0_MASK                 (0x1U)
#define ADC_CIMR1_SIEOCIEN0_SHIFT                (0U)
/*! SIEOCIEN0 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN0_SHIFT)) & ADC_CIMR1_SIEOCIEN0_MASK)

#define ADC_CIMR1_SIEOCIEN1_MASK                 (0x2U)
#define ADC_CIMR1_SIEOCIEN1_SHIFT                (1U)
/*! SIEOCIEN1 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN1_SHIFT)) & ADC_CIMR1_SIEOCIEN1_MASK)

#define ADC_CIMR1_SIEOCIEN2_MASK                 (0x4U)
#define ADC_CIMR1_SIEOCIEN2_SHIFT                (2U)
/*! SIEOCIEN2 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN2_SHIFT)) & ADC_CIMR1_SIEOCIEN2_MASK)

#define ADC_CIMR1_SIEOCIEN3_MASK                 (0x8U)
#define ADC_CIMR1_SIEOCIEN3_SHIFT                (3U)
/*! SIEOCIEN3 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN3_SHIFT)) & ADC_CIMR1_SIEOCIEN3_MASK)

#define ADC_CIMR1_SIEOCIEN4_MASK                 (0x10U)
#define ADC_CIMR1_SIEOCIEN4_SHIFT                (4U)
/*! SIEOCIEN4 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN4_SHIFT)) & ADC_CIMR1_SIEOCIEN4_MASK)

#define ADC_CIMR1_SIEOCIEN5_MASK                 (0x20U)
#define ADC_CIMR1_SIEOCIEN5_SHIFT                (5U)
/*! SIEOCIEN5 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN5_SHIFT)) & ADC_CIMR1_SIEOCIEN5_MASK)

#define ADC_CIMR1_SIEOCIEN6_MASK                 (0x40U)
#define ADC_CIMR1_SIEOCIEN6_SHIFT                (6U)
/*! SIEOCIEN6 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN6_SHIFT)) & ADC_CIMR1_SIEOCIEN6_MASK)

#define ADC_CIMR1_SIEOCIEN7_MASK                 (0x80U)
#define ADC_CIMR1_SIEOCIEN7_SHIFT                (7U)
/*! SIEOCIEN7 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN7_SHIFT)) & ADC_CIMR1_SIEOCIEN7_MASK)

#define ADC_CIMR1_SIEOCIEN8_MASK                 (0x100U)
#define ADC_CIMR1_SIEOCIEN8_SHIFT                (8U)
/*! SIEOCIEN8 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN8(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN8_SHIFT)) & ADC_CIMR1_SIEOCIEN8_MASK)

#define ADC_CIMR1_SIEOCIEN9_MASK                 (0x200U)
#define ADC_CIMR1_SIEOCIEN9_SHIFT                (9U)
/*! SIEOCIEN9 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN9(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN9_SHIFT)) & ADC_CIMR1_SIEOCIEN9_MASK)

#define ADC_CIMR1_SIEOCIEN10_MASK                (0x400U)
#define ADC_CIMR1_SIEOCIEN10_SHIFT               (10U)
/*! SIEOCIEN10 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN10(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN10_SHIFT)) & ADC_CIMR1_SIEOCIEN10_MASK)

#define ADC_CIMR1_SIEOCIEN11_MASK                (0x800U)
#define ADC_CIMR1_SIEOCIEN11_SHIFT               (11U)
/*! SIEOCIEN11 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN11(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN11_SHIFT)) & ADC_CIMR1_SIEOCIEN11_MASK)

#define ADC_CIMR1_SIEOCIEN12_MASK                (0x1000U)
#define ADC_CIMR1_SIEOCIEN12_SHIFT               (12U)
/*! SIEOCIEN12 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN12(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN12_SHIFT)) & ADC_CIMR1_SIEOCIEN12_MASK)

#define ADC_CIMR1_SIEOCIEN13_MASK                (0x2000U)
#define ADC_CIMR1_SIEOCIEN13_SHIFT               (13U)
/*! SIEOCIEN13 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN13(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN13_SHIFT)) & ADC_CIMR1_SIEOCIEN13_MASK)

#define ADC_CIMR1_SIEOCIEN14_MASK                (0x4000U)
#define ADC_CIMR1_SIEOCIEN14_SHIFT               (14U)
/*! SIEOCIEN14 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN14(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN14_SHIFT)) & ADC_CIMR1_SIEOCIEN14_MASK)

#define ADC_CIMR1_SIEOCIEN15_MASK                (0x8000U)
#define ADC_CIMR1_SIEOCIEN15_SHIFT               (15U)
/*! SIEOCIEN15 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN15(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN15_SHIFT)) & ADC_CIMR1_SIEOCIEN15_MASK)

#define ADC_CIMR1_SIEOCIEN16_MASK                (0x10000U)
#define ADC_CIMR1_SIEOCIEN16_SHIFT               (16U)
/*! SIEOCIEN16 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN16(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN16_SHIFT)) & ADC_CIMR1_SIEOCIEN16_MASK)

#define ADC_CIMR1_SIEOCIEN17_MASK                (0x20000U)
#define ADC_CIMR1_SIEOCIEN17_SHIFT               (17U)
/*! SIEOCIEN17 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN17(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN17_SHIFT)) & ADC_CIMR1_SIEOCIEN17_MASK)

#define ADC_CIMR1_SIEOCIEN18_MASK                (0x40000U)
#define ADC_CIMR1_SIEOCIEN18_SHIFT               (18U)
/*! SIEOCIEN18 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN18(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN18_SHIFT)) & ADC_CIMR1_SIEOCIEN18_MASK)

#define ADC_CIMR1_SIEOCIEN19_MASK                (0x80000U)
#define ADC_CIMR1_SIEOCIEN19_SHIFT               (19U)
/*! SIEOCIEN19 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN19(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN19_SHIFT)) & ADC_CIMR1_SIEOCIEN19_MASK)

#define ADC_CIMR1_SIEOCIEN20_MASK                (0x100000U)
#define ADC_CIMR1_SIEOCIEN20_SHIFT               (20U)
/*! SIEOCIEN20 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN20(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN20_SHIFT)) & ADC_CIMR1_SIEOCIEN20_MASK)

#define ADC_CIMR1_SIEOCIEN21_MASK                (0x200000U)
#define ADC_CIMR1_SIEOCIEN21_SHIFT               (21U)
/*! SIEOCIEN21 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN21(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN21_SHIFT)) & ADC_CIMR1_SIEOCIEN21_MASK)

#define ADC_CIMR1_SIEOCIEN22_MASK                (0x400000U)
#define ADC_CIMR1_SIEOCIEN22_SHIFT               (22U)
/*! SIEOCIEN22 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN22(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN22_SHIFT)) & ADC_CIMR1_SIEOCIEN22_MASK)

#define ADC_CIMR1_SIEOCIEN23_MASK                (0x800000U)
#define ADC_CIMR1_SIEOCIEN23_SHIFT               (23U)
/*! SIEOCIEN23 - Standard Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR1_SIEOCIEN23(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR1_SIEOCIEN23_SHIFT)) & ADC_CIMR1_SIEOCIEN23_MASK)
/*! @} */

/*! @name CIMR2 - EOC Interrupt Enable For External Inputs */
/*! @{ */

#define ADC_CIMR2_EIEOCIEN0_MASK                 (0x1U)
#define ADC_CIMR2_EIEOCIEN0_SHIFT                (0U)
/*! EIEOCIEN0 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN0_SHIFT)) & ADC_CIMR2_EIEOCIEN0_MASK)

#define ADC_CIMR2_EIEOCIEN1_MASK                 (0x2U)
#define ADC_CIMR2_EIEOCIEN1_SHIFT                (1U)
/*! EIEOCIEN1 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN1_SHIFT)) & ADC_CIMR2_EIEOCIEN1_MASK)

#define ADC_CIMR2_EIEOCIEN2_MASK                 (0x4U)
#define ADC_CIMR2_EIEOCIEN2_SHIFT                (2U)
/*! EIEOCIEN2 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN2_SHIFT)) & ADC_CIMR2_EIEOCIEN2_MASK)

#define ADC_CIMR2_EIEOCIEN3_MASK                 (0x8U)
#define ADC_CIMR2_EIEOCIEN3_SHIFT                (3U)
/*! EIEOCIEN3 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN3_SHIFT)) & ADC_CIMR2_EIEOCIEN3_MASK)

#define ADC_CIMR2_EIEOCIEN4_MASK                 (0x10U)
#define ADC_CIMR2_EIEOCIEN4_SHIFT                (4U)
/*! EIEOCIEN4 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN4_SHIFT)) & ADC_CIMR2_EIEOCIEN4_MASK)

#define ADC_CIMR2_EIEOCIEN5_MASK                 (0x20U)
#define ADC_CIMR2_EIEOCIEN5_SHIFT                (5U)
/*! EIEOCIEN5 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN5_SHIFT)) & ADC_CIMR2_EIEOCIEN5_MASK)

#define ADC_CIMR2_EIEOCIEN6_MASK                 (0x40U)
#define ADC_CIMR2_EIEOCIEN6_SHIFT                (6U)
/*! EIEOCIEN6 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN6_SHIFT)) & ADC_CIMR2_EIEOCIEN6_MASK)

#define ADC_CIMR2_EIEOCIEN7_MASK                 (0x80U)
#define ADC_CIMR2_EIEOCIEN7_SHIFT                (7U)
/*! EIEOCIEN7 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN7_SHIFT)) & ADC_CIMR2_EIEOCIEN7_MASK)

#define ADC_CIMR2_EIEOCIEN8_MASK                 (0x100U)
#define ADC_CIMR2_EIEOCIEN8_SHIFT                (8U)
/*! EIEOCIEN8 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN8(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN8_SHIFT)) & ADC_CIMR2_EIEOCIEN8_MASK)

#define ADC_CIMR2_EIEOCIEN9_MASK                 (0x200U)
#define ADC_CIMR2_EIEOCIEN9_SHIFT                (9U)
/*! EIEOCIEN9 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN9(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN9_SHIFT)) & ADC_CIMR2_EIEOCIEN9_MASK)

#define ADC_CIMR2_EIEOCIEN10_MASK                (0x400U)
#define ADC_CIMR2_EIEOCIEN10_SHIFT               (10U)
/*! EIEOCIEN10 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN10(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN10_SHIFT)) & ADC_CIMR2_EIEOCIEN10_MASK)

#define ADC_CIMR2_EIEOCIEN11_MASK                (0x800U)
#define ADC_CIMR2_EIEOCIEN11_SHIFT               (11U)
/*! EIEOCIEN11 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN11(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN11_SHIFT)) & ADC_CIMR2_EIEOCIEN11_MASK)

#define ADC_CIMR2_EIEOCIEN12_MASK                (0x1000U)
#define ADC_CIMR2_EIEOCIEN12_SHIFT               (12U)
/*! EIEOCIEN12 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN12(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN12_SHIFT)) & ADC_CIMR2_EIEOCIEN12_MASK)

#define ADC_CIMR2_EIEOCIEN13_MASK                (0x2000U)
#define ADC_CIMR2_EIEOCIEN13_SHIFT               (13U)
/*! EIEOCIEN13 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN13(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN13_SHIFT)) & ADC_CIMR2_EIEOCIEN13_MASK)

#define ADC_CIMR2_EIEOCIEN14_MASK                (0x4000U)
#define ADC_CIMR2_EIEOCIEN14_SHIFT               (14U)
/*! EIEOCIEN14 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN14(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN14_SHIFT)) & ADC_CIMR2_EIEOCIEN14_MASK)

#define ADC_CIMR2_EIEOCIEN15_MASK                (0x8000U)
#define ADC_CIMR2_EIEOCIEN15_SHIFT               (15U)
/*! EIEOCIEN15 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN15(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN15_SHIFT)) & ADC_CIMR2_EIEOCIEN15_MASK)

#define ADC_CIMR2_EIEOCIEN16_MASK                (0x10000U)
#define ADC_CIMR2_EIEOCIEN16_SHIFT               (16U)
/*! EIEOCIEN16 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN16(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN16_SHIFT)) & ADC_CIMR2_EIEOCIEN16_MASK)

#define ADC_CIMR2_EIEOCIEN17_MASK                (0x20000U)
#define ADC_CIMR2_EIEOCIEN17_SHIFT               (17U)
/*! EIEOCIEN17 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN17(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN17_SHIFT)) & ADC_CIMR2_EIEOCIEN17_MASK)

#define ADC_CIMR2_EIEOCIEN18_MASK                (0x40000U)
#define ADC_CIMR2_EIEOCIEN18_SHIFT               (18U)
/*! EIEOCIEN18 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN18(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN18_SHIFT)) & ADC_CIMR2_EIEOCIEN18_MASK)

#define ADC_CIMR2_EIEOCIEN19_MASK                (0x80000U)
#define ADC_CIMR2_EIEOCIEN19_SHIFT               (19U)
/*! EIEOCIEN19 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN19(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN19_SHIFT)) & ADC_CIMR2_EIEOCIEN19_MASK)

#define ADC_CIMR2_EIEOCIEN20_MASK                (0x100000U)
#define ADC_CIMR2_EIEOCIEN20_SHIFT               (20U)
/*! EIEOCIEN20 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN20(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN20_SHIFT)) & ADC_CIMR2_EIEOCIEN20_MASK)

#define ADC_CIMR2_EIEOCIEN21_MASK                (0x200000U)
#define ADC_CIMR2_EIEOCIEN21_SHIFT               (21U)
/*! EIEOCIEN21 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN21(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN21_SHIFT)) & ADC_CIMR2_EIEOCIEN21_MASK)

#define ADC_CIMR2_EIEOCIEN22_MASK                (0x400000U)
#define ADC_CIMR2_EIEOCIEN22_SHIFT               (22U)
/*! EIEOCIEN22 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN22(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN22_SHIFT)) & ADC_CIMR2_EIEOCIEN22_MASK)

#define ADC_CIMR2_EIEOCIEN23_MASK                (0x800000U)
#define ADC_CIMR2_EIEOCIEN23_SHIFT               (23U)
/*! EIEOCIEN23 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN23(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN23_SHIFT)) & ADC_CIMR2_EIEOCIEN23_MASK)

#define ADC_CIMR2_EIEOCIEN24_MASK                (0x1000000U)
#define ADC_CIMR2_EIEOCIEN24_SHIFT               (24U)
/*! EIEOCIEN24 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN24(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN24_SHIFT)) & ADC_CIMR2_EIEOCIEN24_MASK)

#define ADC_CIMR2_EIEOCIEN25_MASK                (0x2000000U)
#define ADC_CIMR2_EIEOCIEN25_SHIFT               (25U)
/*! EIEOCIEN25 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN25(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN25_SHIFT)) & ADC_CIMR2_EIEOCIEN25_MASK)

#define ADC_CIMR2_EIEOCIEN26_MASK                (0x4000000U)
#define ADC_CIMR2_EIEOCIEN26_SHIFT               (26U)
/*! EIEOCIEN26 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN26(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN26_SHIFT)) & ADC_CIMR2_EIEOCIEN26_MASK)

#define ADC_CIMR2_EIEOCIEN27_MASK                (0x8000000U)
#define ADC_CIMR2_EIEOCIEN27_SHIFT               (27U)
/*! EIEOCIEN27 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN27(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN27_SHIFT)) & ADC_CIMR2_EIEOCIEN27_MASK)

#define ADC_CIMR2_EIEOCIEN28_MASK                (0x10000000U)
#define ADC_CIMR2_EIEOCIEN28_SHIFT               (28U)
/*! EIEOCIEN28 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN28(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN28_SHIFT)) & ADC_CIMR2_EIEOCIEN28_MASK)

#define ADC_CIMR2_EIEOCIEN29_MASK                (0x20000000U)
#define ADC_CIMR2_EIEOCIEN29_SHIFT               (29U)
/*! EIEOCIEN29 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN29(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN29_SHIFT)) & ADC_CIMR2_EIEOCIEN29_MASK)

#define ADC_CIMR2_EIEOCIEN30_MASK                (0x40000000U)
#define ADC_CIMR2_EIEOCIEN30_SHIFT               (30U)
/*! EIEOCIEN30 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN30(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN30_SHIFT)) & ADC_CIMR2_EIEOCIEN30_MASK)

#define ADC_CIMR2_EIEOCIEN31_MASK                (0x80000000U)
#define ADC_CIMR2_EIEOCIEN31_SHIFT               (31U)
/*! EIEOCIEN31 - External Input EOC Interrupt Enable
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_CIMR2_EIEOCIEN31(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CIMR2_EIEOCIEN31_SHIFT)) & ADC_CIMR2_EIEOCIEN31_MASK)
/*! @} */

/*! @name WTISR - Analog Watchdog Threshold Interrupt Status */
/*! @{ */

#define ADC_WTISR_LAWIF1_MASK                    (0x1U)
#define ADC_WTISR_LAWIF1_SHIFT                   (0U)
/*! LAWIF1 - Low Analog Watchdog Interrupt Flag 1
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF1_SHIFT)) & ADC_WTISR_LAWIF1_MASK)

#define ADC_WTISR_HAWIF1_MASK                    (0x2U)
#define ADC_WTISR_HAWIF1_SHIFT                   (1U)
/*! HAWIF1 - High Analog Watchdog Interrupt Flag 1
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF1_SHIFT)) & ADC_WTISR_HAWIF1_MASK)

#define ADC_WTISR_LAWIF2_MASK                    (0x4U)
#define ADC_WTISR_LAWIF2_SHIFT                   (2U)
/*! LAWIF2 - Low Analog Watchdog Interrupt Flag 2
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF2(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF2_SHIFT)) & ADC_WTISR_LAWIF2_MASK)

#define ADC_WTISR_HAWIF2_MASK                    (0x8U)
#define ADC_WTISR_HAWIF2_SHIFT                   (3U)
/*! HAWIF2 - High Analog Watchdog Interrupt Flag 2
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF2(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF2_SHIFT)) & ADC_WTISR_HAWIF2_MASK)

#define ADC_WTISR_LAWIF3_MASK                    (0x10U)
#define ADC_WTISR_LAWIF3_SHIFT                   (4U)
/*! LAWIF3 - Low Analog Watchdog Interrupt Flag 3
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF3(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF3_SHIFT)) & ADC_WTISR_LAWIF3_MASK)

#define ADC_WTISR_HAWIF3_MASK                    (0x20U)
#define ADC_WTISR_HAWIF3_SHIFT                   (5U)
/*! HAWIF3 - High Analog Watchdog Interrupt Flag 3
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF3(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF3_SHIFT)) & ADC_WTISR_HAWIF3_MASK)

#define ADC_WTISR_LAWIF4_MASK                    (0x40U)
#define ADC_WTISR_LAWIF4_SHIFT                   (6U)
/*! LAWIF4 - Low Analog Watchdog Interrupt Flag 4
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF4(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF4_SHIFT)) & ADC_WTISR_LAWIF4_MASK)

#define ADC_WTISR_HAWIF4_MASK                    (0x80U)
#define ADC_WTISR_HAWIF4_SHIFT                   (7U)
/*! HAWIF4 - High Analog Watchdog Interrupt Flag 4
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF4(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF4_SHIFT)) & ADC_WTISR_HAWIF4_MASK)

#define ADC_WTISR_LAWIF5_MASK                    (0x100U)
#define ADC_WTISR_LAWIF5_SHIFT                   (8U)
/*! LAWIF5 - Low Analog Watchdog Interrupt Flag 5
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF5(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF5_SHIFT)) & ADC_WTISR_LAWIF5_MASK)

#define ADC_WTISR_HAWIF5_MASK                    (0x200U)
#define ADC_WTISR_HAWIF5_SHIFT                   (9U)
/*! HAWIF5 - High Analog Watchdog Interrupt Flag 5
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF5(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF5_SHIFT)) & ADC_WTISR_HAWIF5_MASK)

#define ADC_WTISR_LAWIF6_MASK                    (0x400U)
#define ADC_WTISR_LAWIF6_SHIFT                   (10U)
/*! LAWIF6 - Low Analog Watchdog Interrupt Flag 6
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF6(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF6_SHIFT)) & ADC_WTISR_LAWIF6_MASK)

#define ADC_WTISR_HAWIF6_MASK                    (0x800U)
#define ADC_WTISR_HAWIF6_SHIFT                   (11U)
/*! HAWIF6 - High Analog Watchdog Interrupt Flag 6
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF6(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF6_SHIFT)) & ADC_WTISR_HAWIF6_MASK)

#define ADC_WTISR_LAWIF7_MASK                    (0x1000U)
#define ADC_WTISR_LAWIF7_SHIFT                   (12U)
/*! LAWIF7 - Low Analog Watchdog Interrupt Flag 7
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF7(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF7_SHIFT)) & ADC_WTISR_LAWIF7_MASK)

#define ADC_WTISR_HAWIF7_MASK                    (0x2000U)
#define ADC_WTISR_HAWIF7_SHIFT                   (13U)
/*! HAWIF7 - High Analog Watchdog Interrupt Flag 7
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF7(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF7_SHIFT)) & ADC_WTISR_HAWIF7_MASK)

#define ADC_WTISR_LAWIF8_MASK                    (0x4000U)
#define ADC_WTISR_LAWIF8_SHIFT                   (14U)
/*! LAWIF8 - Low Analog Watchdog Interrupt Flag 8
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF8(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF8_SHIFT)) & ADC_WTISR_LAWIF8_MASK)

#define ADC_WTISR_HAWIF8_MASK                    (0x8000U)
#define ADC_WTISR_HAWIF8_SHIFT                   (15U)
/*! HAWIF8 - High Analog Watchdog Interrupt Flag 8
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF8(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF8_SHIFT)) & ADC_WTISR_HAWIF8_MASK)

#define ADC_WTISR_LAWIF9_MASK                    (0x10000U)
#define ADC_WTISR_LAWIF9_SHIFT                   (16U)
/*! LAWIF9 - Low Analog Watchdog Interrupt Flag 9
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF9(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF9_SHIFT)) & ADC_WTISR_LAWIF9_MASK)

#define ADC_WTISR_HAWIF9_MASK                    (0x20000U)
#define ADC_WTISR_HAWIF9_SHIFT                   (17U)
/*! HAWIF9 - High Analog Watchdog Interrupt Flag 9
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF9(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF9_SHIFT)) & ADC_WTISR_HAWIF9_MASK)

#define ADC_WTISR_LAWIF10_MASK                   (0x40000U)
#define ADC_WTISR_LAWIF10_SHIFT                  (18U)
/*! LAWIF10 - Low Analog Watchdog Interrupt Flag 10
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF10(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF10_SHIFT)) & ADC_WTISR_LAWIF10_MASK)

#define ADC_WTISR_HAWIF10_MASK                   (0x80000U)
#define ADC_WTISR_HAWIF10_SHIFT                  (19U)
/*! HAWIF10 - High Analog Watchdog Interrupt Flag 10
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF10(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF10_SHIFT)) & ADC_WTISR_HAWIF10_MASK)

#define ADC_WTISR_LAWIF11_MASK                   (0x100000U)
#define ADC_WTISR_LAWIF11_SHIFT                  (20U)
/*! LAWIF11 - Low Analog Watchdog Interrupt Flag 11
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF11(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF11_SHIFT)) & ADC_WTISR_LAWIF11_MASK)

#define ADC_WTISR_HAWIF11_MASK                   (0x200000U)
#define ADC_WTISR_HAWIF11_SHIFT                  (21U)
/*! HAWIF11 - High Analog Watchdog Interrupt Flag 11
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF11(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF11_SHIFT)) & ADC_WTISR_HAWIF11_MASK)

#define ADC_WTISR_LAWIF12_MASK                   (0x400000U)
#define ADC_WTISR_LAWIF12_SHIFT                  (22U)
/*! LAWIF12 - Low Analog Watchdog Interrupt Flag 12
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF12(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF12_SHIFT)) & ADC_WTISR_LAWIF12_MASK)

#define ADC_WTISR_HAWIF12_MASK                   (0x800000U)
#define ADC_WTISR_HAWIF12_SHIFT                  (23U)
/*! HAWIF12 - High Analog Watchdog Interrupt Flag 12
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF12(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF12_SHIFT)) & ADC_WTISR_HAWIF12_MASK)

#define ADC_WTISR_LAWIF13_MASK                   (0x1000000U)
#define ADC_WTISR_LAWIF13_SHIFT                  (24U)
/*! LAWIF13 - Low Analog Watchdog Interrupt Flag 13
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF13(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF13_SHIFT)) & ADC_WTISR_LAWIF13_MASK)

#define ADC_WTISR_HAWIF13_MASK                   (0x2000000U)
#define ADC_WTISR_HAWIF13_SHIFT                  (25U)
/*! HAWIF13 - High Analog Watchdog Interrupt Flag 13
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF13(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF13_SHIFT)) & ADC_WTISR_HAWIF13_MASK)

#define ADC_WTISR_LAWIF14_MASK                   (0x4000000U)
#define ADC_WTISR_LAWIF14_SHIFT                  (26U)
/*! LAWIF14 - Low Analog Watchdog Interrupt Flag 14
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF14(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF14_SHIFT)) & ADC_WTISR_LAWIF14_MASK)

#define ADC_WTISR_HAWIF14_MASK                   (0x8000000U)
#define ADC_WTISR_HAWIF14_SHIFT                  (27U)
/*! HAWIF14 - High Analog Watchdog Interrupt Flag 14
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF14(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF14_SHIFT)) & ADC_WTISR_HAWIF14_MASK)

#define ADC_WTISR_LAWIF15_MASK                   (0x10000000U)
#define ADC_WTISR_LAWIF15_SHIFT                  (28U)
/*! LAWIF15 - Low Analog Watchdog Interrupt Flag 15
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF15(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF15_SHIFT)) & ADC_WTISR_LAWIF15_MASK)

#define ADC_WTISR_HAWIF15_MASK                   (0x20000000U)
#define ADC_WTISR_HAWIF15_SHIFT                  (29U)
/*! HAWIF15 - High Analog Watchdog Interrupt Flag 15
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF15(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF15_SHIFT)) & ADC_WTISR_HAWIF15_MASK)

#define ADC_WTISR_LAWIF16_MASK                   (0x40000000U)
#define ADC_WTISR_LAWIF16_SHIFT                  (30U)
/*! LAWIF16 - Low Analog Watchdog Interrupt Flag 16
 *  0b0..Conversion result is greater than the specified low threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is lower than the specified low threshold
 */
#define ADC_WTISR_LAWIF16(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_LAWIF16_SHIFT)) & ADC_WTISR_LAWIF16_MASK)

#define ADC_WTISR_HAWIF16_MASK                   (0x80000000U)
#define ADC_WTISR_HAWIF16_SHIFT                  (31U)
/*! HAWIF16 - High Analog Watchdog Interrupt Flag 16
 *  0b0..Conversion result is lower than the specified high threshold
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion result is higher than the specified high threshold
 */
#define ADC_WTISR_HAWIF16(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_WTISR_HAWIF16_SHIFT)) & ADC_WTISR_HAWIF16_MASK)
/*! @} */

/*! @name WTIMR - Analog Watchdog Threshold Interrupt Enable */
/*! @{ */

#define ADC_WTIMR_LAWIFEN1_MASK                  (0x1U)
#define ADC_WTIMR_LAWIFEN1_SHIFT                 (0U)
/*! LAWIFEN1 - Low Analog Watchdog Interrupt Flag Enable n
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_WTIMR_LAWIFEN1(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_LAWIFEN1_SHIFT)) & ADC_WTIMR_LAWIFEN1_MASK)

#define ADC_WTIMR_HDWIFEN1_MASK                  (0x2U)
#define ADC_WTIMR_HDWIFEN1_SHIFT                 (1U)
/*! HDWIFEN1 - High Data Watchdog Interrupt Flag Enable n
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_WTIMR_HDWIFEN1(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_HDWIFEN1_SHIFT)) & ADC_WTIMR_HDWIFEN1_MASK)

#define ADC_WTIMR_LAWIFEN2_MASK                  (0x4U)
#define ADC_WTIMR_LAWIFEN2_SHIFT                 (2U)
/*! LAWIFEN2 - Low Analog Watchdog Interrupt Flag Enable n
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_WTIMR_LAWIFEN2(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_LAWIFEN2_SHIFT)) & ADC_WTIMR_LAWIFEN2_MASK)

#define ADC_WTIMR_HDWIFEN2_MASK                  (0x8U)
#define ADC_WTIMR_HDWIFEN2_SHIFT                 (3U)
/*! HDWIFEN2 - High Data Watchdog Interrupt Flag Enable n
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_WTIMR_HDWIFEN2(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_HDWIFEN2_SHIFT)) & ADC_WTIMR_HDWIFEN2_MASK)

#define ADC_WTIMR_LAWIFEN3_MASK                  (0x10U)
#define ADC_WTIMR_LAWIFEN3_SHIFT                 (4U)
/*! LAWIFEN3 - Low Analog Watchdog Interrupt Flag Enable n
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_WTIMR_LAWIFEN3(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_LAWIFEN3_SHIFT)) & ADC_WTIMR_LAWIFEN3_MASK)

#define ADC_WTIMR_HDWIFEN3_MASK                  (0x20U)
#define ADC_WTIMR_HDWIFEN3_SHIFT                 (5U)
/*! HDWIFEN3 - High Data Watchdog Interrupt Flag Enable n
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_WTIMR_HDWIFEN3(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_HDWIFEN3_SHIFT)) & ADC_WTIMR_HDWIFEN3_MASK)

#define ADC_WTIMR_LAWIFEN4_MASK                  (0x40U)
#define ADC_WTIMR_LAWIFEN4_SHIFT                 (6U)
/*! LAWIFEN4 - Low Analog Watchdog Interrupt Flag Enable n
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_WTIMR_LAWIFEN4(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_LAWIFEN4_SHIFT)) & ADC_WTIMR_LAWIFEN4_MASK)

#define ADC_WTIMR_HDWIFEN4_MASK                  (0x80U)
#define ADC_WTIMR_HDWIFEN4_SHIFT                 (7U)
/*! HDWIFEN4 - High Data Watchdog Interrupt Flag Enable n
 *  0b0..Interrupt is not flagged
 *  0b1..Interrupt is flagged
 */
#define ADC_WTIMR_HDWIFEN4(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_WTIMR_HDWIFEN4_SHIFT)) & ADC_WTIMR_HDWIFEN4_MASK)
/*! @} */

/*! @name DMAE - Direct Memory Access Configuration */
/*! @{ */

#define ADC_DMAE_DMAEN_MASK                      (0x1U)
#define ADC_DMAE_DMAEN_SHIFT                     (0U)
/*! DMAEN - DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_DMAE_DMAEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DMAE_DMAEN_SHIFT)) & ADC_DMAE_DMAEN_MASK)

#define ADC_DMAE_DCLR_MASK                       (0x2U)
#define ADC_DMAE_DCLR_SHIFT                      (1U)
/*! DCLR - DMA Clear Request
 *  0b0..DMA controller acknowledges the request
 *  0b1..Conversion data register is read
 */
#define ADC_DMAE_DCLR(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_DMAE_DCLR_SHIFT)) & ADC_DMAE_DCLR_MASK)
/*! @} */

/*! @name DMAR0 - DMA Request Enable For Precision Inputs */
/*! @{ */

#define ADC_DMAR0_PIDMAREN0_MASK                 (0x1U)
#define ADC_DMAR0_PIDMAREN0_SHIFT                (0U)
/*! PIDMAREN0 - Precision Input DMA Request Enable 0
 *  0b0..Not triggered
 *  0b1..Triggered
 */
#define ADC_DMAR0_PIDMAREN0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_PIDMAREN0_SHIFT)) & ADC_DMAR0_PIDMAREN0_MASK)

#define ADC_DMAR0_PIDMAREN1_MASK                 (0x2U)
#define ADC_DMAR0_PIDMAREN1_SHIFT                (1U)
/*! PIDMAREN1 - Precision Input DMA Request Enable 1
 *  0b0..Not triggered
 *  0b1..Triggered
 */
#define ADC_DMAR0_PIDMAREN1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_PIDMAREN1_SHIFT)) & ADC_DMAR0_PIDMAREN1_MASK)

#define ADC_DMAR0_PIDMAREN2_MASK                 (0x4U)
#define ADC_DMAR0_PIDMAREN2_SHIFT                (2U)
/*! PIDMAREN2 - Precision Input DMA Request Enable 2
 *  0b0..Not triggered
 *  0b1..Triggered
 */
#define ADC_DMAR0_PIDMAREN2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_PIDMAREN2_SHIFT)) & ADC_DMAR0_PIDMAREN2_MASK)

#define ADC_DMAR0_PIDMAREN3_MASK                 (0x8U)
#define ADC_DMAR0_PIDMAREN3_SHIFT                (3U)
/*! PIDMAREN3 - Precision Input DMA Request Enable 3
 *  0b0..Not triggered
 *  0b1..Triggered
 */
#define ADC_DMAR0_PIDMAREN3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_PIDMAREN3_SHIFT)) & ADC_DMAR0_PIDMAREN3_MASK)

#define ADC_DMAR0_PIDMAREN4_MASK                 (0x10U)
#define ADC_DMAR0_PIDMAREN4_SHIFT                (4U)
/*! PIDMAREN4 - Precision Input DMA Request Enable 4
 *  0b0..Not triggered
 *  0b1..Triggered
 */
#define ADC_DMAR0_PIDMAREN4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_PIDMAREN4_SHIFT)) & ADC_DMAR0_PIDMAREN4_MASK)

#define ADC_DMAR0_PIDMAREN5_MASK                 (0x20U)
#define ADC_DMAR0_PIDMAREN5_SHIFT                (5U)
/*! PIDMAREN5 - Precision Input DMA Request Enable 5
 *  0b0..Not triggered
 *  0b1..Triggered
 */
#define ADC_DMAR0_PIDMAREN5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_PIDMAREN5_SHIFT)) & ADC_DMAR0_PIDMAREN5_MASK)

#define ADC_DMAR0_PIDMAREN6_MASK                 (0x40U)
#define ADC_DMAR0_PIDMAREN6_SHIFT                (6U)
/*! PIDMAREN6 - Precision Input DMA Request Enable 6
 *  0b0..Not triggered
 *  0b1..Triggered
 */
#define ADC_DMAR0_PIDMAREN6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_PIDMAREN6_SHIFT)) & ADC_DMAR0_PIDMAREN6_MASK)

#define ADC_DMAR0_PIDMAREN7_MASK                 (0x80U)
#define ADC_DMAR0_PIDMAREN7_SHIFT                (7U)
/*! PIDMAREN7 - Precision Input DMA Request Enable 7
 *  0b0..Not triggered
 *  0b1..Triggered
 */
#define ADC_DMAR0_PIDMAREN7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR0_PIDMAREN7_SHIFT)) & ADC_DMAR0_PIDMAREN7_MASK)
/*! @} */

/*! @name DMAR1 - DMA Request Enable For Standard Inputs */
/*! @{ */

#define ADC_DMAR1_SIDMAREN0_MASK                 (0x1U)
#define ADC_DMAR1_SIDMAREN0_SHIFT                (0U)
/*! SIDMAREN0 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN0_SHIFT)) & ADC_DMAR1_SIDMAREN0_MASK)

#define ADC_DMAR1_SIDMAREN1_MASK                 (0x2U)
#define ADC_DMAR1_SIDMAREN1_SHIFT                (1U)
/*! SIDMAREN1 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN1_SHIFT)) & ADC_DMAR1_SIDMAREN1_MASK)

#define ADC_DMAR1_SIDMAREN2_MASK                 (0x4U)
#define ADC_DMAR1_SIDMAREN2_SHIFT                (2U)
/*! SIDMAREN2 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN2_SHIFT)) & ADC_DMAR1_SIDMAREN2_MASK)

#define ADC_DMAR1_SIDMAREN3_MASK                 (0x8U)
#define ADC_DMAR1_SIDMAREN3_SHIFT                (3U)
/*! SIDMAREN3 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN3_SHIFT)) & ADC_DMAR1_SIDMAREN3_MASK)

#define ADC_DMAR1_SIDMAREN4_MASK                 (0x10U)
#define ADC_DMAR1_SIDMAREN4_SHIFT                (4U)
/*! SIDMAREN4 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN4_SHIFT)) & ADC_DMAR1_SIDMAREN4_MASK)

#define ADC_DMAR1_SIDMAREN5_MASK                 (0x20U)
#define ADC_DMAR1_SIDMAREN5_SHIFT                (5U)
/*! SIDMAREN5 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN5_SHIFT)) & ADC_DMAR1_SIDMAREN5_MASK)

#define ADC_DMAR1_SIDMAREN6_MASK                 (0x40U)
#define ADC_DMAR1_SIDMAREN6_SHIFT                (6U)
/*! SIDMAREN6 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN6_SHIFT)) & ADC_DMAR1_SIDMAREN6_MASK)

#define ADC_DMAR1_SIDMAREN7_MASK                 (0x80U)
#define ADC_DMAR1_SIDMAREN7_SHIFT                (7U)
/*! SIDMAREN7 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN7_SHIFT)) & ADC_DMAR1_SIDMAREN7_MASK)

#define ADC_DMAR1_SIDMAREN8_MASK                 (0x100U)
#define ADC_DMAR1_SIDMAREN8_SHIFT                (8U)
/*! SIDMAREN8 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN8(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN8_SHIFT)) & ADC_DMAR1_SIDMAREN8_MASK)

#define ADC_DMAR1_SIDMAREN9_MASK                 (0x200U)
#define ADC_DMAR1_SIDMAREN9_SHIFT                (9U)
/*! SIDMAREN9 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN9(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN9_SHIFT)) & ADC_DMAR1_SIDMAREN9_MASK)

#define ADC_DMAR1_SIDMAREN10_MASK                (0x400U)
#define ADC_DMAR1_SIDMAREN10_SHIFT               (10U)
/*! SIDMAREN10 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN10(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN10_SHIFT)) & ADC_DMAR1_SIDMAREN10_MASK)

#define ADC_DMAR1_SIDMAREN11_MASK                (0x800U)
#define ADC_DMAR1_SIDMAREN11_SHIFT               (11U)
/*! SIDMAREN11 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN11(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN11_SHIFT)) & ADC_DMAR1_SIDMAREN11_MASK)

#define ADC_DMAR1_SIDMAREN12_MASK                (0x1000U)
#define ADC_DMAR1_SIDMAREN12_SHIFT               (12U)
/*! SIDMAREN12 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN12(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN12_SHIFT)) & ADC_DMAR1_SIDMAREN12_MASK)

#define ADC_DMAR1_SIDMAREN13_MASK                (0x2000U)
#define ADC_DMAR1_SIDMAREN13_SHIFT               (13U)
/*! SIDMAREN13 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN13(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN13_SHIFT)) & ADC_DMAR1_SIDMAREN13_MASK)

#define ADC_DMAR1_SIDMAREN14_MASK                (0x4000U)
#define ADC_DMAR1_SIDMAREN14_SHIFT               (14U)
/*! SIDMAREN14 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN14(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN14_SHIFT)) & ADC_DMAR1_SIDMAREN14_MASK)

#define ADC_DMAR1_SIDMAREN15_MASK                (0x8000U)
#define ADC_DMAR1_SIDMAREN15_SHIFT               (15U)
/*! SIDMAREN15 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN15(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN15_SHIFT)) & ADC_DMAR1_SIDMAREN15_MASK)

#define ADC_DMAR1_SIDMAREN16_MASK                (0x10000U)
#define ADC_DMAR1_SIDMAREN16_SHIFT               (16U)
/*! SIDMAREN16 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN16(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN16_SHIFT)) & ADC_DMAR1_SIDMAREN16_MASK)

#define ADC_DMAR1_SIDMAREN17_MASK                (0x20000U)
#define ADC_DMAR1_SIDMAREN17_SHIFT               (17U)
/*! SIDMAREN17 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN17(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN17_SHIFT)) & ADC_DMAR1_SIDMAREN17_MASK)

#define ADC_DMAR1_SIDMAREN18_MASK                (0x40000U)
#define ADC_DMAR1_SIDMAREN18_SHIFT               (18U)
/*! SIDMAREN18 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN18(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN18_SHIFT)) & ADC_DMAR1_SIDMAREN18_MASK)

#define ADC_DMAR1_SIDMAREN19_MASK                (0x80000U)
#define ADC_DMAR1_SIDMAREN19_SHIFT               (19U)
/*! SIDMAREN19 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN19(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN19_SHIFT)) & ADC_DMAR1_SIDMAREN19_MASK)

#define ADC_DMAR1_SIDMAREN20_MASK                (0x100000U)
#define ADC_DMAR1_SIDMAREN20_SHIFT               (20U)
/*! SIDMAREN20 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN20(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN20_SHIFT)) & ADC_DMAR1_SIDMAREN20_MASK)

#define ADC_DMAR1_SIDMAREN21_MASK                (0x200000U)
#define ADC_DMAR1_SIDMAREN21_SHIFT               (21U)
/*! SIDMAREN21 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN21(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN21_SHIFT)) & ADC_DMAR1_SIDMAREN21_MASK)

#define ADC_DMAR1_SIDMAREN22_MASK                (0x400000U)
#define ADC_DMAR1_SIDMAREN22_SHIFT               (22U)
/*! SIDMAREN22 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN22(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN22_SHIFT)) & ADC_DMAR1_SIDMAREN22_MASK)

#define ADC_DMAR1_SIDMAREN23_MASK                (0x800000U)
#define ADC_DMAR1_SIDMAREN23_SHIFT               (23U)
/*! SIDMAREN23 - Standard Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA is request triggered
 */
#define ADC_DMAR1_SIDMAREN23(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR1_SIDMAREN23_SHIFT)) & ADC_DMAR1_SIDMAREN23_MASK)
/*! @} */

/*! @name DMAR2 - DMA Request Enable For External Inputs */
/*! @{ */

#define ADC_DMAR2_EIDMAREN0_MASK                 (0x1U)
#define ADC_DMAR2_EIDMAREN0_SHIFT                (0U)
/*! EIDMAREN0 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN0_SHIFT)) & ADC_DMAR2_EIDMAREN0_MASK)

#define ADC_DMAR2_EIDMAREN1_MASK                 (0x2U)
#define ADC_DMAR2_EIDMAREN1_SHIFT                (1U)
/*! EIDMAREN1 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN1_SHIFT)) & ADC_DMAR2_EIDMAREN1_MASK)

#define ADC_DMAR2_EIDMAREN2_MASK                 (0x4U)
#define ADC_DMAR2_EIDMAREN2_SHIFT                (2U)
/*! EIDMAREN2 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN2_SHIFT)) & ADC_DMAR2_EIDMAREN2_MASK)

#define ADC_DMAR2_EIDMAREN3_MASK                 (0x8U)
#define ADC_DMAR2_EIDMAREN3_SHIFT                (3U)
/*! EIDMAREN3 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN3_SHIFT)) & ADC_DMAR2_EIDMAREN3_MASK)

#define ADC_DMAR2_EIDMAREN4_MASK                 (0x10U)
#define ADC_DMAR2_EIDMAREN4_SHIFT                (4U)
/*! EIDMAREN4 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN4_SHIFT)) & ADC_DMAR2_EIDMAREN4_MASK)

#define ADC_DMAR2_EIDMAREN5_MASK                 (0x20U)
#define ADC_DMAR2_EIDMAREN5_SHIFT                (5U)
/*! EIDMAREN5 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN5_SHIFT)) & ADC_DMAR2_EIDMAREN5_MASK)

#define ADC_DMAR2_EIDMAREN6_MASK                 (0x40U)
#define ADC_DMAR2_EIDMAREN6_SHIFT                (6U)
/*! EIDMAREN6 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN6_SHIFT)) & ADC_DMAR2_EIDMAREN6_MASK)

#define ADC_DMAR2_EIDMAREN7_MASK                 (0x80U)
#define ADC_DMAR2_EIDMAREN7_SHIFT                (7U)
/*! EIDMAREN7 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN7_SHIFT)) & ADC_DMAR2_EIDMAREN7_MASK)

#define ADC_DMAR2_EIDMAREN8_MASK                 (0x100U)
#define ADC_DMAR2_EIDMAREN8_SHIFT                (8U)
/*! EIDMAREN8 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN8(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN8_SHIFT)) & ADC_DMAR2_EIDMAREN8_MASK)

#define ADC_DMAR2_EIDMAREN9_MASK                 (0x200U)
#define ADC_DMAR2_EIDMAREN9_SHIFT                (9U)
/*! EIDMAREN9 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN9(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN9_SHIFT)) & ADC_DMAR2_EIDMAREN9_MASK)

#define ADC_DMAR2_EIDMAREN10_MASK                (0x400U)
#define ADC_DMAR2_EIDMAREN10_SHIFT               (10U)
/*! EIDMAREN10 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN10(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN10_SHIFT)) & ADC_DMAR2_EIDMAREN10_MASK)

#define ADC_DMAR2_EIDMAREN11_MASK                (0x800U)
#define ADC_DMAR2_EIDMAREN11_SHIFT               (11U)
/*! EIDMAREN11 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN11(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN11_SHIFT)) & ADC_DMAR2_EIDMAREN11_MASK)

#define ADC_DMAR2_EIDMAREN12_MASK                (0x1000U)
#define ADC_DMAR2_EIDMAREN12_SHIFT               (12U)
/*! EIDMAREN12 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN12(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN12_SHIFT)) & ADC_DMAR2_EIDMAREN12_MASK)

#define ADC_DMAR2_EIDMAREN13_MASK                (0x2000U)
#define ADC_DMAR2_EIDMAREN13_SHIFT               (13U)
/*! EIDMAREN13 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN13(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN13_SHIFT)) & ADC_DMAR2_EIDMAREN13_MASK)

#define ADC_DMAR2_EIDMAREN14_MASK                (0x4000U)
#define ADC_DMAR2_EIDMAREN14_SHIFT               (14U)
/*! EIDMAREN14 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN14(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN14_SHIFT)) & ADC_DMAR2_EIDMAREN14_MASK)

#define ADC_DMAR2_EIDMAREN15_MASK                (0x8000U)
#define ADC_DMAR2_EIDMAREN15_SHIFT               (15U)
/*! EIDMAREN15 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN15(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN15_SHIFT)) & ADC_DMAR2_EIDMAREN15_MASK)

#define ADC_DMAR2_EIDMAREN16_MASK                (0x10000U)
#define ADC_DMAR2_EIDMAREN16_SHIFT               (16U)
/*! EIDMAREN16 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN16(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN16_SHIFT)) & ADC_DMAR2_EIDMAREN16_MASK)

#define ADC_DMAR2_EIDMAREN17_MASK                (0x20000U)
#define ADC_DMAR2_EIDMAREN17_SHIFT               (17U)
/*! EIDMAREN17 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN17(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN17_SHIFT)) & ADC_DMAR2_EIDMAREN17_MASK)

#define ADC_DMAR2_EIDMAREN18_MASK                (0x40000U)
#define ADC_DMAR2_EIDMAREN18_SHIFT               (18U)
/*! EIDMAREN18 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN18(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN18_SHIFT)) & ADC_DMAR2_EIDMAREN18_MASK)

#define ADC_DMAR2_EIDMAREN19_MASK                (0x80000U)
#define ADC_DMAR2_EIDMAREN19_SHIFT               (19U)
/*! EIDMAREN19 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN19(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN19_SHIFT)) & ADC_DMAR2_EIDMAREN19_MASK)

#define ADC_DMAR2_EIDMAREN20_MASK                (0x100000U)
#define ADC_DMAR2_EIDMAREN20_SHIFT               (20U)
/*! EIDMAREN20 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN20(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN20_SHIFT)) & ADC_DMAR2_EIDMAREN20_MASK)

#define ADC_DMAR2_EIDMAREN21_MASK                (0x200000U)
#define ADC_DMAR2_EIDMAREN21_SHIFT               (21U)
/*! EIDMAREN21 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN21(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN21_SHIFT)) & ADC_DMAR2_EIDMAREN21_MASK)

#define ADC_DMAR2_EIDMAREN22_MASK                (0x400000U)
#define ADC_DMAR2_EIDMAREN22_SHIFT               (22U)
/*! EIDMAREN22 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN22(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN22_SHIFT)) & ADC_DMAR2_EIDMAREN22_MASK)

#define ADC_DMAR2_EIDMAREN23_MASK                (0x800000U)
#define ADC_DMAR2_EIDMAREN23_SHIFT               (23U)
/*! EIDMAREN23 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN23(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN23_SHIFT)) & ADC_DMAR2_EIDMAREN23_MASK)

#define ADC_DMAR2_EIDMAREN24_MASK                (0x1000000U)
#define ADC_DMAR2_EIDMAREN24_SHIFT               (24U)
/*! EIDMAREN24 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN24(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN24_SHIFT)) & ADC_DMAR2_EIDMAREN24_MASK)

#define ADC_DMAR2_EIDMAREN25_MASK                (0x2000000U)
#define ADC_DMAR2_EIDMAREN25_SHIFT               (25U)
/*! EIDMAREN25 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN25(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN25_SHIFT)) & ADC_DMAR2_EIDMAREN25_MASK)

#define ADC_DMAR2_EIDMAREN26_MASK                (0x4000000U)
#define ADC_DMAR2_EIDMAREN26_SHIFT               (26U)
/*! EIDMAREN26 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN26(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN26_SHIFT)) & ADC_DMAR2_EIDMAREN26_MASK)

#define ADC_DMAR2_EIDMAREN27_MASK                (0x8000000U)
#define ADC_DMAR2_EIDMAREN27_SHIFT               (27U)
/*! EIDMAREN27 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN27(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN27_SHIFT)) & ADC_DMAR2_EIDMAREN27_MASK)

#define ADC_DMAR2_EIDMAREN28_MASK                (0x10000000U)
#define ADC_DMAR2_EIDMAREN28_SHIFT               (28U)
/*! EIDMAREN28 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN28(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN28_SHIFT)) & ADC_DMAR2_EIDMAREN28_MASK)

#define ADC_DMAR2_EIDMAREN29_MASK                (0x20000000U)
#define ADC_DMAR2_EIDMAREN29_SHIFT               (29U)
/*! EIDMAREN29 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN29(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN29_SHIFT)) & ADC_DMAR2_EIDMAREN29_MASK)

#define ADC_DMAR2_EIDMAREN30_MASK                (0x40000000U)
#define ADC_DMAR2_EIDMAREN30_SHIFT               (30U)
/*! EIDMAREN30 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN30(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN30_SHIFT)) & ADC_DMAR2_EIDMAREN30_MASK)

#define ADC_DMAR2_EIDMAREN31_MASK                (0x80000000U)
#define ADC_DMAR2_EIDMAREN31_SHIFT               (31U)
/*! EIDMAREN31 - External Input DMA Request Enable n
 *  0b0..DMA request is not triggered
 *  0b1..DMA request is triggered
 */
#define ADC_DMAR2_EIDMAREN31(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_DMAR2_EIDMAREN31_SHIFT)) & ADC_DMAR2_EIDMAREN31_MASK)
/*! @} */

/*! @name THRHLR - Analog Watchdog Threshold Values */
/*! @{ */

#define ADC_THRHLR_THRL_MASK                     (0x7FFFU)
#define ADC_THRHLR_THRL_SHIFT                    (0U)
/*! THRL - Low Threshold Value */
#define ADC_THRHLR_THRL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR_THRL_SHIFT)) & ADC_THRHLR_THRL_MASK)

#define ADC_THRHLR_THRH_MASK                     (0x7FFF0000U)
#define ADC_THRHLR_THRH_SHIFT                    (16U)
/*! THRH - High Threshold Value */
#define ADC_THRHLR_THRH(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_THRHLR_THRH_SHIFT)) & ADC_THRHLR_THRH_MASK)
/*! @} */

/*! @name PSCR - Presampling Control */
/*! @{ */

#define ADC_PSCR_PRECONV_MASK                    (0x1U)
#define ADC_PSCR_PRECONV_SHIFT                   (0U)
/*! PRECONV - Convert Presampled Value
 *  0b0..No conversion after presampling
 *  0b1..Presampling is followed by conversion
 */
#define ADC_PSCR_PRECONV(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_PSCR_PRECONV_SHIFT)) & ADC_PSCR_PRECONV_MASK)

#define ADC_PSCR_PREVAL0_MASK                    (0x2U)
#define ADC_PSCR_PREVAL0_SHIFT                   (1U)
/*! PREVAL0 - Presampling Voltage Select For Precision Inputs
 *  0b0..VREFL
 *  0b1..VREFH
 */
#define ADC_PSCR_PREVAL0(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_PSCR_PREVAL0_SHIFT)) & ADC_PSCR_PREVAL0_MASK)

#define ADC_PSCR_PREVAL1_MASK                    (0x8U)
#define ADC_PSCR_PREVAL1_SHIFT                   (3U)
/*! PREVAL1 - Presampling Voltage Select For Standard Inputs
 *  0b0..VREFL
 *  0b1..VREFH
 */
#define ADC_PSCR_PREVAL1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_PSCR_PREVAL1_SHIFT)) & ADC_PSCR_PREVAL1_MASK)

#define ADC_PSCR_PREVAL2_MASK                    (0x20U)
#define ADC_PSCR_PREVAL2_SHIFT                   (5U)
/*! PREVAL2 - Presampling Voltage Select For External Inputs
 *  0b0..VREFL
 *  0b1..VREFH
 */
#define ADC_PSCR_PREVAL2(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_PSCR_PREVAL2_SHIFT)) & ADC_PSCR_PREVAL2_MASK)
/*! @} */

/*! @name PSR0 - Presampling Enable For Precision Inputs */
/*! @{ */

#define ADC_PSR0_PRES0_MASK                      (0x1U)
#define ADC_PSR0_PRES0_SHIFT                     (0U)
/*! PRES0 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR0_PRES0(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES0_SHIFT)) & ADC_PSR0_PRES0_MASK)

#define ADC_PSR0_PRES1_MASK                      (0x2U)
#define ADC_PSR0_PRES1_SHIFT                     (1U)
/*! PRES1 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR0_PRES1(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES1_SHIFT)) & ADC_PSR0_PRES1_MASK)

#define ADC_PSR0_PRES2_MASK                      (0x4U)
#define ADC_PSR0_PRES2_SHIFT                     (2U)
/*! PRES2 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR0_PRES2(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES2_SHIFT)) & ADC_PSR0_PRES2_MASK)

#define ADC_PSR0_PRES3_MASK                      (0x8U)
#define ADC_PSR0_PRES3_SHIFT                     (3U)
/*! PRES3 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR0_PRES3(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES3_SHIFT)) & ADC_PSR0_PRES3_MASK)

#define ADC_PSR0_PRES4_MASK                      (0x10U)
#define ADC_PSR0_PRES4_SHIFT                     (4U)
/*! PRES4 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR0_PRES4(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES4_SHIFT)) & ADC_PSR0_PRES4_MASK)

#define ADC_PSR0_PRES5_MASK                      (0x20U)
#define ADC_PSR0_PRES5_SHIFT                     (5U)
/*! PRES5 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR0_PRES5(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES5_SHIFT)) & ADC_PSR0_PRES5_MASK)

#define ADC_PSR0_PRES6_MASK                      (0x40U)
#define ADC_PSR0_PRES6_SHIFT                     (6U)
/*! PRES6 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR0_PRES6(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES6_SHIFT)) & ADC_PSR0_PRES6_MASK)

#define ADC_PSR0_PRES7_MASK                      (0x80U)
#define ADC_PSR0_PRES7_SHIFT                     (7U)
/*! PRES7 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR0_PRES7(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR0_PRES7_SHIFT)) & ADC_PSR0_PRES7_MASK)
/*! @} */

/*! @name PSR1 - Presampling Enable For Standard Inputs */
/*! @{ */

#define ADC_PSR1_PRES0_MASK                      (0x1U)
#define ADC_PSR1_PRES0_SHIFT                     (0U)
/*! PRES0 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES0(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES0_SHIFT)) & ADC_PSR1_PRES0_MASK)

#define ADC_PSR1_PRES1_MASK                      (0x2U)
#define ADC_PSR1_PRES1_SHIFT                     (1U)
/*! PRES1 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES1(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES1_SHIFT)) & ADC_PSR1_PRES1_MASK)

#define ADC_PSR1_PRES2_MASK                      (0x4U)
#define ADC_PSR1_PRES2_SHIFT                     (2U)
/*! PRES2 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES2(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES2_SHIFT)) & ADC_PSR1_PRES2_MASK)

#define ADC_PSR1_PRES3_MASK                      (0x8U)
#define ADC_PSR1_PRES3_SHIFT                     (3U)
/*! PRES3 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES3(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES3_SHIFT)) & ADC_PSR1_PRES3_MASK)

#define ADC_PSR1_PRES4_MASK                      (0x10U)
#define ADC_PSR1_PRES4_SHIFT                     (4U)
/*! PRES4 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES4(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES4_SHIFT)) & ADC_PSR1_PRES4_MASK)

#define ADC_PSR1_PRES5_MASK                      (0x20U)
#define ADC_PSR1_PRES5_SHIFT                     (5U)
/*! PRES5 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES5(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES5_SHIFT)) & ADC_PSR1_PRES5_MASK)

#define ADC_PSR1_PRES6_MASK                      (0x40U)
#define ADC_PSR1_PRES6_SHIFT                     (6U)
/*! PRES6 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES6(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES6_SHIFT)) & ADC_PSR1_PRES6_MASK)

#define ADC_PSR1_PRES7_MASK                      (0x80U)
#define ADC_PSR1_PRES7_SHIFT                     (7U)
/*! PRES7 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES7(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES7_SHIFT)) & ADC_PSR1_PRES7_MASK)

#define ADC_PSR1_PRES8_MASK                      (0x100U)
#define ADC_PSR1_PRES8_SHIFT                     (8U)
/*! PRES8 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES8(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES8_SHIFT)) & ADC_PSR1_PRES8_MASK)

#define ADC_PSR1_PRES9_MASK                      (0x200U)
#define ADC_PSR1_PRES9_SHIFT                     (9U)
/*! PRES9 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES9(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES9_SHIFT)) & ADC_PSR1_PRES9_MASK)

#define ADC_PSR1_PRES10_MASK                     (0x400U)
#define ADC_PSR1_PRES10_SHIFT                    (10U)
/*! PRES10 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES10(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES10_SHIFT)) & ADC_PSR1_PRES10_MASK)

#define ADC_PSR1_PRES11_MASK                     (0x800U)
#define ADC_PSR1_PRES11_SHIFT                    (11U)
/*! PRES11 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES11(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES11_SHIFT)) & ADC_PSR1_PRES11_MASK)

#define ADC_PSR1_PRES12_MASK                     (0x1000U)
#define ADC_PSR1_PRES12_SHIFT                    (12U)
/*! PRES12 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES12(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES12_SHIFT)) & ADC_PSR1_PRES12_MASK)

#define ADC_PSR1_PRES13_MASK                     (0x2000U)
#define ADC_PSR1_PRES13_SHIFT                    (13U)
/*! PRES13 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES13(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES13_SHIFT)) & ADC_PSR1_PRES13_MASK)

#define ADC_PSR1_PRES14_MASK                     (0x4000U)
#define ADC_PSR1_PRES14_SHIFT                    (14U)
/*! PRES14 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES14(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES14_SHIFT)) & ADC_PSR1_PRES14_MASK)

#define ADC_PSR1_PRES15_MASK                     (0x8000U)
#define ADC_PSR1_PRES15_SHIFT                    (15U)
/*! PRES15 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES15(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES15_SHIFT)) & ADC_PSR1_PRES15_MASK)

#define ADC_PSR1_PRES16_MASK                     (0x10000U)
#define ADC_PSR1_PRES16_SHIFT                    (16U)
/*! PRES16 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES16(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES16_SHIFT)) & ADC_PSR1_PRES16_MASK)

#define ADC_PSR1_PRES17_MASK                     (0x20000U)
#define ADC_PSR1_PRES17_SHIFT                    (17U)
/*! PRES17 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES17(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES17_SHIFT)) & ADC_PSR1_PRES17_MASK)

#define ADC_PSR1_PRES18_MASK                     (0x40000U)
#define ADC_PSR1_PRES18_SHIFT                    (18U)
/*! PRES18 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES18(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES18_SHIFT)) & ADC_PSR1_PRES18_MASK)

#define ADC_PSR1_PRES19_MASK                     (0x80000U)
#define ADC_PSR1_PRES19_SHIFT                    (19U)
/*! PRES19 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES19(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES19_SHIFT)) & ADC_PSR1_PRES19_MASK)

#define ADC_PSR1_PRES20_MASK                     (0x100000U)
#define ADC_PSR1_PRES20_SHIFT                    (20U)
/*! PRES20 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES20(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES20_SHIFT)) & ADC_PSR1_PRES20_MASK)

#define ADC_PSR1_PRES21_MASK                     (0x200000U)
#define ADC_PSR1_PRES21_SHIFT                    (21U)
/*! PRES21 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES21(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES21_SHIFT)) & ADC_PSR1_PRES21_MASK)

#define ADC_PSR1_PRES22_MASK                     (0x400000U)
#define ADC_PSR1_PRES22_SHIFT                    (22U)
/*! PRES22 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES22(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES22_SHIFT)) & ADC_PSR1_PRES22_MASK)

#define ADC_PSR1_PRES23_MASK                     (0x800000U)
#define ADC_PSR1_PRES23_SHIFT                    (23U)
/*! PRES23 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR1_PRES23(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR1_PRES23_SHIFT)) & ADC_PSR1_PRES23_MASK)
/*! @} */

/*! @name PSR2 - Presampling Enable For External Inputs */
/*! @{ */

#define ADC_PSR2_PRES0_MASK                      (0x1U)
#define ADC_PSR2_PRES0_SHIFT                     (0U)
/*! PRES0 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES0(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES0_SHIFT)) & ADC_PSR2_PRES0_MASK)

#define ADC_PSR2_PRES1_MASK                      (0x2U)
#define ADC_PSR2_PRES1_SHIFT                     (1U)
/*! PRES1 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES1(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES1_SHIFT)) & ADC_PSR2_PRES1_MASK)

#define ADC_PSR2_PRES2_MASK                      (0x4U)
#define ADC_PSR2_PRES2_SHIFT                     (2U)
/*! PRES2 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES2(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES2_SHIFT)) & ADC_PSR2_PRES2_MASK)

#define ADC_PSR2_PRES3_MASK                      (0x8U)
#define ADC_PSR2_PRES3_SHIFT                     (3U)
/*! PRES3 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES3(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES3_SHIFT)) & ADC_PSR2_PRES3_MASK)

#define ADC_PSR2_PRES4_MASK                      (0x10U)
#define ADC_PSR2_PRES4_SHIFT                     (4U)
/*! PRES4 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES4(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES4_SHIFT)) & ADC_PSR2_PRES4_MASK)

#define ADC_PSR2_PRES5_MASK                      (0x20U)
#define ADC_PSR2_PRES5_SHIFT                     (5U)
/*! PRES5 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES5(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES5_SHIFT)) & ADC_PSR2_PRES5_MASK)

#define ADC_PSR2_PRES6_MASK                      (0x40U)
#define ADC_PSR2_PRES6_SHIFT                     (6U)
/*! PRES6 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES6(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES6_SHIFT)) & ADC_PSR2_PRES6_MASK)

#define ADC_PSR2_PRES7_MASK                      (0x80U)
#define ADC_PSR2_PRES7_SHIFT                     (7U)
/*! PRES7 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES7(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES7_SHIFT)) & ADC_PSR2_PRES7_MASK)

#define ADC_PSR2_PRES8_MASK                      (0x100U)
#define ADC_PSR2_PRES8_SHIFT                     (8U)
/*! PRES8 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES8(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES8_SHIFT)) & ADC_PSR2_PRES8_MASK)

#define ADC_PSR2_PRES9_MASK                      (0x200U)
#define ADC_PSR2_PRES9_SHIFT                     (9U)
/*! PRES9 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES9(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES9_SHIFT)) & ADC_PSR2_PRES9_MASK)

#define ADC_PSR2_PRES10_MASK                     (0x400U)
#define ADC_PSR2_PRES10_SHIFT                    (10U)
/*! PRES10 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES10(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES10_SHIFT)) & ADC_PSR2_PRES10_MASK)

#define ADC_PSR2_PRES11_MASK                     (0x800U)
#define ADC_PSR2_PRES11_SHIFT                    (11U)
/*! PRES11 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES11(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES11_SHIFT)) & ADC_PSR2_PRES11_MASK)

#define ADC_PSR2_PRES12_MASK                     (0x1000U)
#define ADC_PSR2_PRES12_SHIFT                    (12U)
/*! PRES12 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES12(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES12_SHIFT)) & ADC_PSR2_PRES12_MASK)

#define ADC_PSR2_PRES13_MASK                     (0x2000U)
#define ADC_PSR2_PRES13_SHIFT                    (13U)
/*! PRES13 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES13(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES13_SHIFT)) & ADC_PSR2_PRES13_MASK)

#define ADC_PSR2_PRES14_MASK                     (0x4000U)
#define ADC_PSR2_PRES14_SHIFT                    (14U)
/*! PRES14 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES14(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES14_SHIFT)) & ADC_PSR2_PRES14_MASK)

#define ADC_PSR2_PRES15_MASK                     (0x8000U)
#define ADC_PSR2_PRES15_SHIFT                    (15U)
/*! PRES15 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES15(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES15_SHIFT)) & ADC_PSR2_PRES15_MASK)

#define ADC_PSR2_PRES16_MASK                     (0x10000U)
#define ADC_PSR2_PRES16_SHIFT                    (16U)
/*! PRES16 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES16(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES16_SHIFT)) & ADC_PSR2_PRES16_MASK)

#define ADC_PSR2_PRES17_MASK                     (0x20000U)
#define ADC_PSR2_PRES17_SHIFT                    (17U)
/*! PRES17 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES17(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES17_SHIFT)) & ADC_PSR2_PRES17_MASK)

#define ADC_PSR2_PRES18_MASK                     (0x40000U)
#define ADC_PSR2_PRES18_SHIFT                    (18U)
/*! PRES18 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES18(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES18_SHIFT)) & ADC_PSR2_PRES18_MASK)

#define ADC_PSR2_PRES19_MASK                     (0x80000U)
#define ADC_PSR2_PRES19_SHIFT                    (19U)
/*! PRES19 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES19(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES19_SHIFT)) & ADC_PSR2_PRES19_MASK)

#define ADC_PSR2_PRES20_MASK                     (0x100000U)
#define ADC_PSR2_PRES20_SHIFT                    (20U)
/*! PRES20 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES20(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES20_SHIFT)) & ADC_PSR2_PRES20_MASK)

#define ADC_PSR2_PRES21_MASK                     (0x200000U)
#define ADC_PSR2_PRES21_SHIFT                    (21U)
/*! PRES21 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES21(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES21_SHIFT)) & ADC_PSR2_PRES21_MASK)

#define ADC_PSR2_PRES22_MASK                     (0x400000U)
#define ADC_PSR2_PRES22_SHIFT                    (22U)
/*! PRES22 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES22(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES22_SHIFT)) & ADC_PSR2_PRES22_MASK)

#define ADC_PSR2_PRES23_MASK                     (0x800000U)
#define ADC_PSR2_PRES23_SHIFT                    (23U)
/*! PRES23 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES23(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES23_SHIFT)) & ADC_PSR2_PRES23_MASK)

#define ADC_PSR2_PRES24_MASK                     (0x1000000U)
#define ADC_PSR2_PRES24_SHIFT                    (24U)
/*! PRES24 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES24(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES24_SHIFT)) & ADC_PSR2_PRES24_MASK)

#define ADC_PSR2_PRES25_MASK                     (0x2000000U)
#define ADC_PSR2_PRES25_SHIFT                    (25U)
/*! PRES25 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES25(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES25_SHIFT)) & ADC_PSR2_PRES25_MASK)

#define ADC_PSR2_PRES26_MASK                     (0x4000000U)
#define ADC_PSR2_PRES26_SHIFT                    (26U)
/*! PRES26 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES26(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES26_SHIFT)) & ADC_PSR2_PRES26_MASK)

#define ADC_PSR2_PRES27_MASK                     (0x8000000U)
#define ADC_PSR2_PRES27_SHIFT                    (27U)
/*! PRES27 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES27(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES27_SHIFT)) & ADC_PSR2_PRES27_MASK)

#define ADC_PSR2_PRES28_MASK                     (0x10000000U)
#define ADC_PSR2_PRES28_SHIFT                    (28U)
/*! PRES28 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES28(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES28_SHIFT)) & ADC_PSR2_PRES28_MASK)

#define ADC_PSR2_PRES29_MASK                     (0x20000000U)
#define ADC_PSR2_PRES29_SHIFT                    (29U)
/*! PRES29 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES29(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES29_SHIFT)) & ADC_PSR2_PRES29_MASK)

#define ADC_PSR2_PRES30_MASK                     (0x40000000U)
#define ADC_PSR2_PRES30_SHIFT                    (30U)
/*! PRES30 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES30(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES30_SHIFT)) & ADC_PSR2_PRES30_MASK)

#define ADC_PSR2_PRES31_MASK                     (0x80000000U)
#define ADC_PSR2_PRES31_SHIFT                    (31U)
/*! PRES31 - Presampling Enable n
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_PSR2_PRES31(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PSR2_PRES31_SHIFT)) & ADC_PSR2_PRES31_MASK)
/*! @} */

/*! @name CTR0 - Conversion Timing For Precision Inputs */
/*! @{ */

#define ADC_CTR0_INPSAMP_MASK                    (0xFFU)
#define ADC_CTR0_INPSAMP_SHIFT                   (0U)
/*! INPSAMP - Input Sample Cycles */
#define ADC_CTR0_INPSAMP(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CTR0_INPSAMP_SHIFT)) & ADC_CTR0_INPSAMP_MASK)
/*! @} */

/*! @name CTR1 - Conversion Timing For Standard Inputs */
/*! @{ */

#define ADC_CTR1_INPSAMP_MASK                    (0xFFU)
#define ADC_CTR1_INPSAMP_SHIFT                   (0U)
/*! INPSAMP - Input Sample Cycles */
#define ADC_CTR1_INPSAMP(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CTR1_INPSAMP_SHIFT)) & ADC_CTR1_INPSAMP_MASK)
/*! @} */

/*! @name CTR2 - Conversion Timing For External Inputs */
/*! @{ */

#define ADC_CTR2_INPSAMP_MASK                    (0xFFU)
#define ADC_CTR2_INPSAMP_SHIFT                   (0U)
/*! INPSAMP - Input Sample Cycles */
#define ADC_CTR2_INPSAMP(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CTR2_INPSAMP_SHIFT)) & ADC_CTR2_INPSAMP_MASK)
/*! @} */

/*! @name NCMR0 - Normal Conversion Enable For Precision Inputs */
/*! @{ */

#define ADC_NCMR0_CH0_MASK                       (0x1U)
#define ADC_NCMR0_CH0_SHIFT                      (0U)
/*! CH0 - Precision Input To Be Converted
 *  0b0..Input is not selected
 *  0b1..Input is selected
 */
#define ADC_NCMR0_CH0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH0_SHIFT)) & ADC_NCMR0_CH0_MASK)

#define ADC_NCMR0_CH1_MASK                       (0x2U)
#define ADC_NCMR0_CH1_SHIFT                      (1U)
/*! CH1 - Precision Input To Be Converted
 *  0b0..Input is not selected
 *  0b1..Input is selected
 */
#define ADC_NCMR0_CH1(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH1_SHIFT)) & ADC_NCMR0_CH1_MASK)

#define ADC_NCMR0_CH2_MASK                       (0x4U)
#define ADC_NCMR0_CH2_SHIFT                      (2U)
/*! CH2 - Precision Input To Be Converted
 *  0b0..Input is not selected
 *  0b1..Input is selected
 */
#define ADC_NCMR0_CH2(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH2_SHIFT)) & ADC_NCMR0_CH2_MASK)

#define ADC_NCMR0_CH3_MASK                       (0x8U)
#define ADC_NCMR0_CH3_SHIFT                      (3U)
/*! CH3 - Precision Input To Be Converted
 *  0b0..Input is not selected
 *  0b1..Input is selected
 */
#define ADC_NCMR0_CH3(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH3_SHIFT)) & ADC_NCMR0_CH3_MASK)

#define ADC_NCMR0_CH4_MASK                       (0x10U)
#define ADC_NCMR0_CH4_SHIFT                      (4U)
/*! CH4 - Precision Input To Be Converted
 *  0b0..Input is not selected
 *  0b1..Input is selected
 */
#define ADC_NCMR0_CH4(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH4_SHIFT)) & ADC_NCMR0_CH4_MASK)

#define ADC_NCMR0_CH5_MASK                       (0x20U)
#define ADC_NCMR0_CH5_SHIFT                      (5U)
/*! CH5 - Precision Input To Be Converted
 *  0b0..Input is not selected
 *  0b1..Input is selected
 */
#define ADC_NCMR0_CH5(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH5_SHIFT)) & ADC_NCMR0_CH5_MASK)

#define ADC_NCMR0_CH6_MASK                       (0x40U)
#define ADC_NCMR0_CH6_SHIFT                      (6U)
/*! CH6 - Precision Input To Be Converted
 *  0b0..Input is not selected
 *  0b1..Input is selected
 */
#define ADC_NCMR0_CH6(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH6_SHIFT)) & ADC_NCMR0_CH6_MASK)

#define ADC_NCMR0_CH7_MASK                       (0x80U)
#define ADC_NCMR0_CH7_SHIFT                      (7U)
/*! CH7 - Precision Input To Be Converted
 *  0b0..Input is not selected
 *  0b1..Input is selected
 */
#define ADC_NCMR0_CH7(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_NCMR0_CH7_SHIFT)) & ADC_NCMR0_CH7_MASK)
/*! @} */

/*! @name NCMR1 - Normal Conversion Enable For Standard Inputs */
/*! @{ */

#define ADC_NCMR1_CH32_MASK                      (0x1U)
#define ADC_NCMR1_CH32_SHIFT                     (0U)
/*! CH32 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH32(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH32_SHIFT)) & ADC_NCMR1_CH32_MASK)

#define ADC_NCMR1_CH33_MASK                      (0x2U)
#define ADC_NCMR1_CH33_SHIFT                     (1U)
/*! CH33 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH33(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH33_SHIFT)) & ADC_NCMR1_CH33_MASK)

#define ADC_NCMR1_CH34_MASK                      (0x4U)
#define ADC_NCMR1_CH34_SHIFT                     (2U)
/*! CH34 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH34(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH34_SHIFT)) & ADC_NCMR1_CH34_MASK)

#define ADC_NCMR1_CH35_MASK                      (0x8U)
#define ADC_NCMR1_CH35_SHIFT                     (3U)
/*! CH35 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH35(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH35_SHIFT)) & ADC_NCMR1_CH35_MASK)

#define ADC_NCMR1_CH36_MASK                      (0x10U)
#define ADC_NCMR1_CH36_SHIFT                     (4U)
/*! CH36 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH36(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH36_SHIFT)) & ADC_NCMR1_CH36_MASK)

#define ADC_NCMR1_CH37_MASK                      (0x20U)
#define ADC_NCMR1_CH37_SHIFT                     (5U)
/*! CH37 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH37(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH37_SHIFT)) & ADC_NCMR1_CH37_MASK)

#define ADC_NCMR1_CH38_MASK                      (0x40U)
#define ADC_NCMR1_CH38_SHIFT                     (6U)
/*! CH38 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH38(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH38_SHIFT)) & ADC_NCMR1_CH38_MASK)

#define ADC_NCMR1_CH39_MASK                      (0x80U)
#define ADC_NCMR1_CH39_SHIFT                     (7U)
/*! CH39 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH39(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH39_SHIFT)) & ADC_NCMR1_CH39_MASK)

#define ADC_NCMR1_CH40_MASK                      (0x100U)
#define ADC_NCMR1_CH40_SHIFT                     (8U)
/*! CH40 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH40(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH40_SHIFT)) & ADC_NCMR1_CH40_MASK)

#define ADC_NCMR1_CH41_MASK                      (0x200U)
#define ADC_NCMR1_CH41_SHIFT                     (9U)
/*! CH41 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH41(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH41_SHIFT)) & ADC_NCMR1_CH41_MASK)

#define ADC_NCMR1_CH42_MASK                      (0x400U)
#define ADC_NCMR1_CH42_SHIFT                     (10U)
/*! CH42 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH42(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH42_SHIFT)) & ADC_NCMR1_CH42_MASK)

#define ADC_NCMR1_CH43_MASK                      (0x800U)
#define ADC_NCMR1_CH43_SHIFT                     (11U)
/*! CH43 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH43(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH43_SHIFT)) & ADC_NCMR1_CH43_MASK)

#define ADC_NCMR1_CH44_MASK                      (0x1000U)
#define ADC_NCMR1_CH44_SHIFT                     (12U)
/*! CH44 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH44(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH44_SHIFT)) & ADC_NCMR1_CH44_MASK)

#define ADC_NCMR1_CH45_MASK                      (0x2000U)
#define ADC_NCMR1_CH45_SHIFT                     (13U)
/*! CH45 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH45(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH45_SHIFT)) & ADC_NCMR1_CH45_MASK)

#define ADC_NCMR1_CH46_MASK                      (0x4000U)
#define ADC_NCMR1_CH46_SHIFT                     (14U)
/*! CH46 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH46(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH46_SHIFT)) & ADC_NCMR1_CH46_MASK)

#define ADC_NCMR1_CH47_MASK                      (0x8000U)
#define ADC_NCMR1_CH47_SHIFT                     (15U)
/*! CH47 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH47(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH47_SHIFT)) & ADC_NCMR1_CH47_MASK)

#define ADC_NCMR1_CH48_MASK                      (0x10000U)
#define ADC_NCMR1_CH48_SHIFT                     (16U)
/*! CH48 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH48(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH48_SHIFT)) & ADC_NCMR1_CH48_MASK)

#define ADC_NCMR1_CH49_MASK                      (0x20000U)
#define ADC_NCMR1_CH49_SHIFT                     (17U)
/*! CH49 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH49(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH49_SHIFT)) & ADC_NCMR1_CH49_MASK)

#define ADC_NCMR1_CH50_MASK                      (0x40000U)
#define ADC_NCMR1_CH50_SHIFT                     (18U)
/*! CH50 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH50(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH50_SHIFT)) & ADC_NCMR1_CH50_MASK)

#define ADC_NCMR1_CH51_MASK                      (0x80000U)
#define ADC_NCMR1_CH51_SHIFT                     (19U)
/*! CH51 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH51(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH51_SHIFT)) & ADC_NCMR1_CH51_MASK)

#define ADC_NCMR1_CH52_MASK                      (0x100000U)
#define ADC_NCMR1_CH52_SHIFT                     (20U)
/*! CH52 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH52(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH52_SHIFT)) & ADC_NCMR1_CH52_MASK)

#define ADC_NCMR1_CH53_MASK                      (0x200000U)
#define ADC_NCMR1_CH53_SHIFT                     (21U)
/*! CH53 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH53(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH53_SHIFT)) & ADC_NCMR1_CH53_MASK)

#define ADC_NCMR1_CH54_MASK                      (0x400000U)
#define ADC_NCMR1_CH54_SHIFT                     (22U)
/*! CH54 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH54(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH54_SHIFT)) & ADC_NCMR1_CH54_MASK)

#define ADC_NCMR1_CH55_MASK                      (0x800000U)
#define ADC_NCMR1_CH55_SHIFT                     (23U)
/*! CH55 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR1_CH55(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR1_CH55_SHIFT)) & ADC_NCMR1_CH55_MASK)
/*! @} */

/*! @name NCMR2 - Normal Conversion Enable For External Inputs */
/*! @{ */

#define ADC_NCMR2_CH64_MASK                      (0x1U)
#define ADC_NCMR2_CH64_SHIFT                     (0U)
/*! CH64 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH64(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH64_SHIFT)) & ADC_NCMR2_CH64_MASK)

#define ADC_NCMR2_CH65_MASK                      (0x2U)
#define ADC_NCMR2_CH65_SHIFT                     (1U)
/*! CH65 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH65(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH65_SHIFT)) & ADC_NCMR2_CH65_MASK)

#define ADC_NCMR2_CH66_MASK                      (0x4U)
#define ADC_NCMR2_CH66_SHIFT                     (2U)
/*! CH66 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH66(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH66_SHIFT)) & ADC_NCMR2_CH66_MASK)

#define ADC_NCMR2_CH67_MASK                      (0x8U)
#define ADC_NCMR2_CH67_SHIFT                     (3U)
/*! CH67 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH67(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH67_SHIFT)) & ADC_NCMR2_CH67_MASK)

#define ADC_NCMR2_CH68_MASK                      (0x10U)
#define ADC_NCMR2_CH68_SHIFT                     (4U)
/*! CH68 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH68(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH68_SHIFT)) & ADC_NCMR2_CH68_MASK)

#define ADC_NCMR2_CH69_MASK                      (0x20U)
#define ADC_NCMR2_CH69_SHIFT                     (5U)
/*! CH69 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH69(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH69_SHIFT)) & ADC_NCMR2_CH69_MASK)

#define ADC_NCMR2_CH70_MASK                      (0x40U)
#define ADC_NCMR2_CH70_SHIFT                     (6U)
/*! CH70 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH70(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH70_SHIFT)) & ADC_NCMR2_CH70_MASK)

#define ADC_NCMR2_CH71_MASK                      (0x80U)
#define ADC_NCMR2_CH71_SHIFT                     (7U)
/*! CH71 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH71(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH71_SHIFT)) & ADC_NCMR2_CH71_MASK)

#define ADC_NCMR2_CH72_MASK                      (0x100U)
#define ADC_NCMR2_CH72_SHIFT                     (8U)
/*! CH72 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH72(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH72_SHIFT)) & ADC_NCMR2_CH72_MASK)

#define ADC_NCMR2_CH73_MASK                      (0x200U)
#define ADC_NCMR2_CH73_SHIFT                     (9U)
/*! CH73 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH73(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH73_SHIFT)) & ADC_NCMR2_CH73_MASK)

#define ADC_NCMR2_CH74_MASK                      (0x400U)
#define ADC_NCMR2_CH74_SHIFT                     (10U)
/*! CH74 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH74(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH74_SHIFT)) & ADC_NCMR2_CH74_MASK)

#define ADC_NCMR2_CH75_MASK                      (0x800U)
#define ADC_NCMR2_CH75_SHIFT                     (11U)
/*! CH75 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH75(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH75_SHIFT)) & ADC_NCMR2_CH75_MASK)

#define ADC_NCMR2_CH76_MASK                      (0x1000U)
#define ADC_NCMR2_CH76_SHIFT                     (12U)
/*! CH76 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH76(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH76_SHIFT)) & ADC_NCMR2_CH76_MASK)

#define ADC_NCMR2_CH77_MASK                      (0x2000U)
#define ADC_NCMR2_CH77_SHIFT                     (13U)
/*! CH77 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH77(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH77_SHIFT)) & ADC_NCMR2_CH77_MASK)

#define ADC_NCMR2_CH78_MASK                      (0x4000U)
#define ADC_NCMR2_CH78_SHIFT                     (14U)
/*! CH78 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH78(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH78_SHIFT)) & ADC_NCMR2_CH78_MASK)

#define ADC_NCMR2_CH79_MASK                      (0x8000U)
#define ADC_NCMR2_CH79_SHIFT                     (15U)
/*! CH79 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH79(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH79_SHIFT)) & ADC_NCMR2_CH79_MASK)

#define ADC_NCMR2_CH80_MASK                      (0x10000U)
#define ADC_NCMR2_CH80_SHIFT                     (16U)
/*! CH80 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH80(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH80_SHIFT)) & ADC_NCMR2_CH80_MASK)

#define ADC_NCMR2_CH81_MASK                      (0x20000U)
#define ADC_NCMR2_CH81_SHIFT                     (17U)
/*! CH81 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH81(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH81_SHIFT)) & ADC_NCMR2_CH81_MASK)

#define ADC_NCMR2_CH82_MASK                      (0x40000U)
#define ADC_NCMR2_CH82_SHIFT                     (18U)
/*! CH82 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH82(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH82_SHIFT)) & ADC_NCMR2_CH82_MASK)

#define ADC_NCMR2_CH83_MASK                      (0x80000U)
#define ADC_NCMR2_CH83_SHIFT                     (19U)
/*! CH83 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH83(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH83_SHIFT)) & ADC_NCMR2_CH83_MASK)

#define ADC_NCMR2_CH84_MASK                      (0x100000U)
#define ADC_NCMR2_CH84_SHIFT                     (20U)
/*! CH84 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH84(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH84_SHIFT)) & ADC_NCMR2_CH84_MASK)

#define ADC_NCMR2_CH85_MASK                      (0x200000U)
#define ADC_NCMR2_CH85_SHIFT                     (21U)
/*! CH85 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH85(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH85_SHIFT)) & ADC_NCMR2_CH85_MASK)

#define ADC_NCMR2_CH86_MASK                      (0x400000U)
#define ADC_NCMR2_CH86_SHIFT                     (22U)
/*! CH86 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH86(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH86_SHIFT)) & ADC_NCMR2_CH86_MASK)

#define ADC_NCMR2_CH87_MASK                      (0x800000U)
#define ADC_NCMR2_CH87_SHIFT                     (23U)
/*! CH87 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH87(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH87_SHIFT)) & ADC_NCMR2_CH87_MASK)

#define ADC_NCMR2_CH88_MASK                      (0x1000000U)
#define ADC_NCMR2_CH88_SHIFT                     (24U)
/*! CH88 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH88(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH88_SHIFT)) & ADC_NCMR2_CH88_MASK)

#define ADC_NCMR2_CH89_MASK                      (0x2000000U)
#define ADC_NCMR2_CH89_SHIFT                     (25U)
/*! CH89 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH89(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH89_SHIFT)) & ADC_NCMR2_CH89_MASK)

#define ADC_NCMR2_CH90_MASK                      (0x4000000U)
#define ADC_NCMR2_CH90_SHIFT                     (26U)
/*! CH90 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH90(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH90_SHIFT)) & ADC_NCMR2_CH90_MASK)

#define ADC_NCMR2_CH91_MASK                      (0x8000000U)
#define ADC_NCMR2_CH91_SHIFT                     (27U)
/*! CH91 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH91(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH91_SHIFT)) & ADC_NCMR2_CH91_MASK)

#define ADC_NCMR2_CH92_MASK                      (0x10000000U)
#define ADC_NCMR2_CH92_SHIFT                     (28U)
/*! CH92 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH92(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH92_SHIFT)) & ADC_NCMR2_CH92_MASK)

#define ADC_NCMR2_CH93_MASK                      (0x20000000U)
#define ADC_NCMR2_CH93_SHIFT                     (29U)
/*! CH93 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH93(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH93_SHIFT)) & ADC_NCMR2_CH93_MASK)

#define ADC_NCMR2_CH94_MASK                      (0x40000000U)
#define ADC_NCMR2_CH94_SHIFT                     (30U)
/*! CH94 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH94(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH94_SHIFT)) & ADC_NCMR2_CH94_MASK)

#define ADC_NCMR2_CH95_MASK                      (0x80000000U)
#define ADC_NCMR2_CH95_SHIFT                     (31U)
/*! CH95 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_NCMR2_CH95(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_NCMR2_CH95_SHIFT)) & ADC_NCMR2_CH95_MASK)
/*! @} */

/*! @name JCMR0 - Injected Conversion Enable For Precision Inputs */
/*! @{ */

#define ADC_JCMR0_CH0_MASK                       (0x1U)
#define ADC_JCMR0_CH0_SHIFT                      (0U)
/*! CH0 - Precision Input To Be Converted
 *  0b0..Input 0 is not selected
 *  0b1..Input 0 is selected
 */
#define ADC_JCMR0_CH0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH0_SHIFT)) & ADC_JCMR0_CH0_MASK)

#define ADC_JCMR0_CH1_MASK                       (0x2U)
#define ADC_JCMR0_CH1_SHIFT                      (1U)
/*! CH1 - Precision Input To Be Converted
 *  0b0..Input 1 is not selected
 *  0b1..Input 1 is selected
 */
#define ADC_JCMR0_CH1(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH1_SHIFT)) & ADC_JCMR0_CH1_MASK)

#define ADC_JCMR0_CH2_MASK                       (0x4U)
#define ADC_JCMR0_CH2_SHIFT                      (2U)
/*! CH2 - Precision Input To Be Converted
 *  0b0..Input 2 is not selected
 *  0b1..Input 2 is selected
 */
#define ADC_JCMR0_CH2(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH2_SHIFT)) & ADC_JCMR0_CH2_MASK)

#define ADC_JCMR0_CH3_MASK                       (0x8U)
#define ADC_JCMR0_CH3_SHIFT                      (3U)
/*! CH3 - Precision Input To Be Converted
 *  0b0..Input 3 is not selected
 *  0b1..Input 3 is selected
 */
#define ADC_JCMR0_CH3(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH3_SHIFT)) & ADC_JCMR0_CH3_MASK)

#define ADC_JCMR0_CH4_MASK                       (0x10U)
#define ADC_JCMR0_CH4_SHIFT                      (4U)
/*! CH4 - Precision Input To Be Converted
 *  0b0..Input 4 is not selected
 *  0b1..Input 4 is selected
 */
#define ADC_JCMR0_CH4(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH4_SHIFT)) & ADC_JCMR0_CH4_MASK)

#define ADC_JCMR0_CH5_MASK                       (0x20U)
#define ADC_JCMR0_CH5_SHIFT                      (5U)
/*! CH5 - Precision Input To Be Converted
 *  0b0..Input 5 is not selected
 *  0b1..Input 5 is selected
 */
#define ADC_JCMR0_CH5(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH5_SHIFT)) & ADC_JCMR0_CH5_MASK)

#define ADC_JCMR0_CH6_MASK                       (0x40U)
#define ADC_JCMR0_CH6_SHIFT                      (6U)
/*! CH6 - Precision Input To Be Converted
 *  0b0..Input 6 is not selected
 *  0b1..Input 6 is selected
 */
#define ADC_JCMR0_CH6(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH6_SHIFT)) & ADC_JCMR0_CH6_MASK)

#define ADC_JCMR0_CH7_MASK                       (0x80U)
#define ADC_JCMR0_CH7_SHIFT                      (7U)
/*! CH7 - Precision Input To Be Converted
 *  0b0..Input 7 is not selected
 *  0b1..Input 7 is selected
 */
#define ADC_JCMR0_CH7(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_JCMR0_CH7_SHIFT)) & ADC_JCMR0_CH7_MASK)
/*! @} */

/*! @name JCMR1 - Injected Conversion Enable For Standard Inputs */
/*! @{ */

#define ADC_JCMR1_CH32_MASK                      (0x1U)
#define ADC_JCMR1_CH32_SHIFT                     (0U)
/*! CH32 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH32(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH32_SHIFT)) & ADC_JCMR1_CH32_MASK)

#define ADC_JCMR1_CH33_MASK                      (0x2U)
#define ADC_JCMR1_CH33_SHIFT                     (1U)
/*! CH33 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH33(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH33_SHIFT)) & ADC_JCMR1_CH33_MASK)

#define ADC_JCMR1_CH34_MASK                      (0x4U)
#define ADC_JCMR1_CH34_SHIFT                     (2U)
/*! CH34 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH34(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH34_SHIFT)) & ADC_JCMR1_CH34_MASK)

#define ADC_JCMR1_CH35_MASK                      (0x8U)
#define ADC_JCMR1_CH35_SHIFT                     (3U)
/*! CH35 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH35(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH35_SHIFT)) & ADC_JCMR1_CH35_MASK)

#define ADC_JCMR1_CH36_MASK                      (0x10U)
#define ADC_JCMR1_CH36_SHIFT                     (4U)
/*! CH36 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH36(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH36_SHIFT)) & ADC_JCMR1_CH36_MASK)

#define ADC_JCMR1_CH37_MASK                      (0x20U)
#define ADC_JCMR1_CH37_SHIFT                     (5U)
/*! CH37 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH37(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH37_SHIFT)) & ADC_JCMR1_CH37_MASK)

#define ADC_JCMR1_CH38_MASK                      (0x40U)
#define ADC_JCMR1_CH38_SHIFT                     (6U)
/*! CH38 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH38(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH38_SHIFT)) & ADC_JCMR1_CH38_MASK)

#define ADC_JCMR1_CH39_MASK                      (0x80U)
#define ADC_JCMR1_CH39_SHIFT                     (7U)
/*! CH39 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH39(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH39_SHIFT)) & ADC_JCMR1_CH39_MASK)

#define ADC_JCMR1_CH40_MASK                      (0x100U)
#define ADC_JCMR1_CH40_SHIFT                     (8U)
/*! CH40 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH40(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH40_SHIFT)) & ADC_JCMR1_CH40_MASK)

#define ADC_JCMR1_CH41_MASK                      (0x200U)
#define ADC_JCMR1_CH41_SHIFT                     (9U)
/*! CH41 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH41(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH41_SHIFT)) & ADC_JCMR1_CH41_MASK)

#define ADC_JCMR1_CH42_MASK                      (0x400U)
#define ADC_JCMR1_CH42_SHIFT                     (10U)
/*! CH42 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH42(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH42_SHIFT)) & ADC_JCMR1_CH42_MASK)

#define ADC_JCMR1_CH43_MASK                      (0x800U)
#define ADC_JCMR1_CH43_SHIFT                     (11U)
/*! CH43 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH43(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH43_SHIFT)) & ADC_JCMR1_CH43_MASK)

#define ADC_JCMR1_CH44_MASK                      (0x1000U)
#define ADC_JCMR1_CH44_SHIFT                     (12U)
/*! CH44 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH44(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH44_SHIFT)) & ADC_JCMR1_CH44_MASK)

#define ADC_JCMR1_CH45_MASK                      (0x2000U)
#define ADC_JCMR1_CH45_SHIFT                     (13U)
/*! CH45 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH45(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH45_SHIFT)) & ADC_JCMR1_CH45_MASK)

#define ADC_JCMR1_CH46_MASK                      (0x4000U)
#define ADC_JCMR1_CH46_SHIFT                     (14U)
/*! CH46 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH46(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH46_SHIFT)) & ADC_JCMR1_CH46_MASK)

#define ADC_JCMR1_CH47_MASK                      (0x8000U)
#define ADC_JCMR1_CH47_SHIFT                     (15U)
/*! CH47 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH47(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH47_SHIFT)) & ADC_JCMR1_CH47_MASK)

#define ADC_JCMR1_CH48_MASK                      (0x10000U)
#define ADC_JCMR1_CH48_SHIFT                     (16U)
/*! CH48 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH48(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH48_SHIFT)) & ADC_JCMR1_CH48_MASK)

#define ADC_JCMR1_CH49_MASK                      (0x20000U)
#define ADC_JCMR1_CH49_SHIFT                     (17U)
/*! CH49 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH49(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH49_SHIFT)) & ADC_JCMR1_CH49_MASK)

#define ADC_JCMR1_CH50_MASK                      (0x40000U)
#define ADC_JCMR1_CH50_SHIFT                     (18U)
/*! CH50 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH50(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH50_SHIFT)) & ADC_JCMR1_CH50_MASK)

#define ADC_JCMR1_CH51_MASK                      (0x80000U)
#define ADC_JCMR1_CH51_SHIFT                     (19U)
/*! CH51 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH51(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH51_SHIFT)) & ADC_JCMR1_CH51_MASK)

#define ADC_JCMR1_CH52_MASK                      (0x100000U)
#define ADC_JCMR1_CH52_SHIFT                     (20U)
/*! CH52 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH52(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH52_SHIFT)) & ADC_JCMR1_CH52_MASK)

#define ADC_JCMR1_CH53_MASK                      (0x200000U)
#define ADC_JCMR1_CH53_SHIFT                     (21U)
/*! CH53 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH53(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH53_SHIFT)) & ADC_JCMR1_CH53_MASK)

#define ADC_JCMR1_CH54_MASK                      (0x400000U)
#define ADC_JCMR1_CH54_SHIFT                     (22U)
/*! CH54 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH54(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH54_SHIFT)) & ADC_JCMR1_CH54_MASK)

#define ADC_JCMR1_CH55_MASK                      (0x800000U)
#define ADC_JCMR1_CH55_SHIFT                     (23U)
/*! CH55 - Standard Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR1_CH55(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR1_CH55_SHIFT)) & ADC_JCMR1_CH55_MASK)
/*! @} */

/*! @name JCMR2 - Injected Conversion Enable For External Inputs */
/*! @{ */

#define ADC_JCMR2_CH64_MASK                      (0x1U)
#define ADC_JCMR2_CH64_SHIFT                     (0U)
/*! CH64 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH64(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH64_SHIFT)) & ADC_JCMR2_CH64_MASK)

#define ADC_JCMR2_CH65_MASK                      (0x2U)
#define ADC_JCMR2_CH65_SHIFT                     (1U)
/*! CH65 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH65(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH65_SHIFT)) & ADC_JCMR2_CH65_MASK)

#define ADC_JCMR2_CH66_MASK                      (0x4U)
#define ADC_JCMR2_CH66_SHIFT                     (2U)
/*! CH66 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH66(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH66_SHIFT)) & ADC_JCMR2_CH66_MASK)

#define ADC_JCMR2_CH67_MASK                      (0x8U)
#define ADC_JCMR2_CH67_SHIFT                     (3U)
/*! CH67 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH67(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH67_SHIFT)) & ADC_JCMR2_CH67_MASK)

#define ADC_JCMR2_CH68_MASK                      (0x10U)
#define ADC_JCMR2_CH68_SHIFT                     (4U)
/*! CH68 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH68(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH68_SHIFT)) & ADC_JCMR2_CH68_MASK)

#define ADC_JCMR2_CH69_MASK                      (0x20U)
#define ADC_JCMR2_CH69_SHIFT                     (5U)
/*! CH69 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH69(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH69_SHIFT)) & ADC_JCMR2_CH69_MASK)

#define ADC_JCMR2_CH70_MASK                      (0x40U)
#define ADC_JCMR2_CH70_SHIFT                     (6U)
/*! CH70 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH70(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH70_SHIFT)) & ADC_JCMR2_CH70_MASK)

#define ADC_JCMR2_CH71_MASK                      (0x80U)
#define ADC_JCMR2_CH71_SHIFT                     (7U)
/*! CH71 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH71(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH71_SHIFT)) & ADC_JCMR2_CH71_MASK)

#define ADC_JCMR2_CH72_MASK                      (0x100U)
#define ADC_JCMR2_CH72_SHIFT                     (8U)
/*! CH72 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH72(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH72_SHIFT)) & ADC_JCMR2_CH72_MASK)

#define ADC_JCMR2_CH73_MASK                      (0x200U)
#define ADC_JCMR2_CH73_SHIFT                     (9U)
/*! CH73 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH73(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH73_SHIFT)) & ADC_JCMR2_CH73_MASK)

#define ADC_JCMR2_CH74_MASK                      (0x400U)
#define ADC_JCMR2_CH74_SHIFT                     (10U)
/*! CH74 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH74(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH74_SHIFT)) & ADC_JCMR2_CH74_MASK)

#define ADC_JCMR2_CH75_MASK                      (0x800U)
#define ADC_JCMR2_CH75_SHIFT                     (11U)
/*! CH75 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH75(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH75_SHIFT)) & ADC_JCMR2_CH75_MASK)

#define ADC_JCMR2_CH76_MASK                      (0x1000U)
#define ADC_JCMR2_CH76_SHIFT                     (12U)
/*! CH76 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH76(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH76_SHIFT)) & ADC_JCMR2_CH76_MASK)

#define ADC_JCMR2_CH77_MASK                      (0x2000U)
#define ADC_JCMR2_CH77_SHIFT                     (13U)
/*! CH77 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH77(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH77_SHIFT)) & ADC_JCMR2_CH77_MASK)

#define ADC_JCMR2_CH78_MASK                      (0x4000U)
#define ADC_JCMR2_CH78_SHIFT                     (14U)
/*! CH78 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH78(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH78_SHIFT)) & ADC_JCMR2_CH78_MASK)

#define ADC_JCMR2_CH79_MASK                      (0x8000U)
#define ADC_JCMR2_CH79_SHIFT                     (15U)
/*! CH79 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH79(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH79_SHIFT)) & ADC_JCMR2_CH79_MASK)

#define ADC_JCMR2_CH80_MASK                      (0x10000U)
#define ADC_JCMR2_CH80_SHIFT                     (16U)
/*! CH80 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH80(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH80_SHIFT)) & ADC_JCMR2_CH80_MASK)

#define ADC_JCMR2_CH81_MASK                      (0x20000U)
#define ADC_JCMR2_CH81_SHIFT                     (17U)
/*! CH81 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH81(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH81_SHIFT)) & ADC_JCMR2_CH81_MASK)

#define ADC_JCMR2_CH82_MASK                      (0x40000U)
#define ADC_JCMR2_CH82_SHIFT                     (18U)
/*! CH82 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH82(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH82_SHIFT)) & ADC_JCMR2_CH82_MASK)

#define ADC_JCMR2_CH83_MASK                      (0x80000U)
#define ADC_JCMR2_CH83_SHIFT                     (19U)
/*! CH83 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH83(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH83_SHIFT)) & ADC_JCMR2_CH83_MASK)

#define ADC_JCMR2_CH84_MASK                      (0x100000U)
#define ADC_JCMR2_CH84_SHIFT                     (20U)
/*! CH84 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH84(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH84_SHIFT)) & ADC_JCMR2_CH84_MASK)

#define ADC_JCMR2_CH85_MASK                      (0x200000U)
#define ADC_JCMR2_CH85_SHIFT                     (21U)
/*! CH85 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH85(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH85_SHIFT)) & ADC_JCMR2_CH85_MASK)

#define ADC_JCMR2_CH86_MASK                      (0x400000U)
#define ADC_JCMR2_CH86_SHIFT                     (22U)
/*! CH86 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH86(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH86_SHIFT)) & ADC_JCMR2_CH86_MASK)

#define ADC_JCMR2_CH87_MASK                      (0x800000U)
#define ADC_JCMR2_CH87_SHIFT                     (23U)
/*! CH87 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH87(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH87_SHIFT)) & ADC_JCMR2_CH87_MASK)

#define ADC_JCMR2_CH88_MASK                      (0x1000000U)
#define ADC_JCMR2_CH88_SHIFT                     (24U)
/*! CH88 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH88(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH88_SHIFT)) & ADC_JCMR2_CH88_MASK)

#define ADC_JCMR2_CH89_MASK                      (0x2000000U)
#define ADC_JCMR2_CH89_SHIFT                     (25U)
/*! CH89 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH89(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH89_SHIFT)) & ADC_JCMR2_CH89_MASK)

#define ADC_JCMR2_CH90_MASK                      (0x4000000U)
#define ADC_JCMR2_CH90_SHIFT                     (26U)
/*! CH90 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH90(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH90_SHIFT)) & ADC_JCMR2_CH90_MASK)

#define ADC_JCMR2_CH91_MASK                      (0x8000000U)
#define ADC_JCMR2_CH91_SHIFT                     (27U)
/*! CH91 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH91(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH91_SHIFT)) & ADC_JCMR2_CH91_MASK)

#define ADC_JCMR2_CH92_MASK                      (0x10000000U)
#define ADC_JCMR2_CH92_SHIFT                     (28U)
/*! CH92 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH92(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH92_SHIFT)) & ADC_JCMR2_CH92_MASK)

#define ADC_JCMR2_CH93_MASK                      (0x20000000U)
#define ADC_JCMR2_CH93_SHIFT                     (29U)
/*! CH93 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH93(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH93_SHIFT)) & ADC_JCMR2_CH93_MASK)

#define ADC_JCMR2_CH94_MASK                      (0x40000000U)
#define ADC_JCMR2_CH94_SHIFT                     (30U)
/*! CH94 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH94(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH94_SHIFT)) & ADC_JCMR2_CH94_MASK)

#define ADC_JCMR2_CH95_MASK                      (0x80000000U)
#define ADC_JCMR2_CH95_SHIFT                     (31U)
/*! CH95 - External Input To Be Converted
 *  0b0..Input n is not selected
 *  0b1..Input n is selected
 */
#define ADC_JCMR2_CH95(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_JCMR2_CH95_SHIFT)) & ADC_JCMR2_CH95_MASK)
/*! @} */

/*! @name DSDR - Delay Start Of Data Conversion */
/*! @{ */

#define ADC_DSDR_DSD_MASK                        (0xFFFFU)
#define ADC_DSDR_DSD_SHIFT                       (0U)
/*! DSD - Delay */
#define ADC_DSDR_DSD(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_DSDR_DSD_SHIFT)) & ADC_DSDR_DSD_MASK)
/*! @} */

/*! @name PDEDR - Power Down Exit Delay */
/*! @{ */

#define ADC_PDEDR_PDED_MASK                      (0xFFU)
#define ADC_PDEDR_PDED_SHIFT                     (0U)
/*! PDED - Delay */
#define ADC_PDEDR_PDED(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PDEDR_PDED_SHIFT)) & ADC_PDEDR_PDED_MASK)
/*! @} */

/*! @name PCDR - Precision Input n Conversion Data */
/*! @{ */

#define ADC_PCDR_CDATA_MASK                      (0xFFFFU)
#define ADC_PCDR_CDATA_SHIFT                     (0U)
/*! CDATA - Conversion Data */
#define ADC_PCDR_CDATA(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PCDR_CDATA_SHIFT)) & ADC_PCDR_CDATA_MASK)

#define ADC_PCDR_RESULT_MASK                     (0x30000U)
#define ADC_PCDR_RESULT_SHIFT                    (16U)
/*! RESULT - Conversion Data Type
 *  0b00..Normal trigger
 *  0b01..Injected trigger
 *  0b10..BCTU trigger
 */
#define ADC_PCDR_RESULT(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_PCDR_RESULT_SHIFT)) & ADC_PCDR_RESULT_MASK)

#define ADC_PCDR_OVERW_MASK                      (0x40000U)
#define ADC_PCDR_OVERW_SHIFT                     (18U)
/*! OVERW - Overwrite Status Flag
 *  0b0..No unread data is overwritten
 *  0b1..Unread data is overwritten
 */
#define ADC_PCDR_OVERW(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PCDR_OVERW_SHIFT)) & ADC_PCDR_OVERW_MASK)

#define ADC_PCDR_VALID_MASK                      (0x80000U)
#define ADC_PCDR_VALID_SHIFT                     (19U)
/*! VALID - Conversion Data Available
 *  0b0..No unread conversion data
 *  0b1..Unread conversion data is available
 */
#define ADC_PCDR_VALID(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_PCDR_VALID_SHIFT)) & ADC_PCDR_VALID_MASK)
/*! @} */

/* The count of ADC_PCDR */
#define ADC_PCDR_COUNT                           (8U)

/*! @name ICDR - Standard Input n Conversion Data */
/*! @{ */

#define ADC_ICDR_CDATA_MASK                      (0xFFFFU)
#define ADC_ICDR_CDATA_SHIFT                     (0U)
/*! CDATA - Conversion Data */
#define ADC_ICDR_CDATA(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ICDR_CDATA_SHIFT)) & ADC_ICDR_CDATA_MASK)

#define ADC_ICDR_RESULT_MASK                     (0x30000U)
#define ADC_ICDR_RESULT_SHIFT                    (16U)
/*! RESULT - Conversion Data Type
 *  0b00..Normal trigger
 *  0b01..Injected trigger
 *  0b10..BCTU trigger
 */
#define ADC_ICDR_RESULT(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ICDR_RESULT_SHIFT)) & ADC_ICDR_RESULT_MASK)

#define ADC_ICDR_OVERW_MASK                      (0x40000U)
#define ADC_ICDR_OVERW_SHIFT                     (18U)
/*! OVERW - Overwrite Status Flag
 *  0b0..No unread data is overwritten
 *  0b1..Unread data is overwritten
 */
#define ADC_ICDR_OVERW(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ICDR_OVERW_SHIFT)) & ADC_ICDR_OVERW_MASK)

#define ADC_ICDR_VALID_MASK                      (0x80000U)
#define ADC_ICDR_VALID_SHIFT                     (19U)
/*! VALID - Conversion Data Available
 *  0b0..No unread conversion data
 *  0b1..Unread conversion data is available
 */
#define ADC_ICDR_VALID(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ICDR_VALID_SHIFT)) & ADC_ICDR_VALID_MASK)
/*! @} */

/* The count of ADC_ICDR */
#define ADC_ICDR_COUNT                           (24U)

/*! @name ECDR - External Input n Conversion Data */
/*! @{ */

#define ADC_ECDR_CDATA_MASK                      (0xFFFFU)
#define ADC_ECDR_CDATA_SHIFT                     (0U)
/*! CDATA - Conversion Data */
#define ADC_ECDR_CDATA(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ECDR_CDATA_SHIFT)) & ADC_ECDR_CDATA_MASK)

#define ADC_ECDR_RESULT_MASK                     (0x30000U)
#define ADC_ECDR_RESULT_SHIFT                    (16U)
/*! RESULT - Conversion Data Type
 *  0b00..Normal trigger
 *  0b01..Injected trigger
 *  0b10..BCTU trigger
 */
#define ADC_ECDR_RESULT(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_ECDR_RESULT_SHIFT)) & ADC_ECDR_RESULT_MASK)

#define ADC_ECDR_OVERW_MASK                      (0x40000U)
#define ADC_ECDR_OVERW_SHIFT                     (18U)
/*! OVERW - Overwrite Status Flag
 *  0b0..No unread data is overwritten
 *  0b1..Unread data is overwritten
 */
#define ADC_ECDR_OVERW(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ECDR_OVERW_SHIFT)) & ADC_ECDR_OVERW_MASK)

#define ADC_ECDR_VALID_MASK                      (0x80000U)
#define ADC_ECDR_VALID_SHIFT                     (19U)
/*! VALID - Conversion Data Available
 *  0b0..No unread conversion data
 *  0b1..Unread conversion data is available
 */
#define ADC_ECDR_VALID(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_ECDR_VALID_SHIFT)) & ADC_ECDR_VALID_MASK)
/*! @} */

/* The count of ADC_ECDR */
#define ADC_ECDR_COUNT                           (32U)

/*! @name CWSELRPI - Channel Analog Watchdog Select For Precision Inputs */
/*! @{ */

#define ADC_CWSELRPI_WSEL_SI0_0_MASK             (0x3U)
#define ADC_CWSELRPI_WSEL_SI0_0_SHIFT            (0U)
/*! WSEL_SI0_0 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRPI_WSEL_SI0_0(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRPI_WSEL_SI0_0_SHIFT)) & ADC_CWSELRPI_WSEL_SI0_0_MASK)

#define ADC_CWSELRPI_WSEL_SI0_1_MASK             (0x30U)
#define ADC_CWSELRPI_WSEL_SI0_1_SHIFT            (4U)
/*! WSEL_SI0_1 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRPI_WSEL_SI0_1(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRPI_WSEL_SI0_1_SHIFT)) & ADC_CWSELRPI_WSEL_SI0_1_MASK)

#define ADC_CWSELRPI_WSEL_SI0_2_MASK             (0x300U)
#define ADC_CWSELRPI_WSEL_SI0_2_SHIFT            (8U)
/*! WSEL_SI0_2 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRPI_WSEL_SI0_2(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRPI_WSEL_SI0_2_SHIFT)) & ADC_CWSELRPI_WSEL_SI0_2_MASK)

#define ADC_CWSELRPI_WSEL_SI0_3_MASK             (0x3000U)
#define ADC_CWSELRPI_WSEL_SI0_3_SHIFT            (12U)
/*! WSEL_SI0_3 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRPI_WSEL_SI0_3(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRPI_WSEL_SI0_3_SHIFT)) & ADC_CWSELRPI_WSEL_SI0_3_MASK)

#define ADC_CWSELRPI_WSEL_SI0_4_MASK             (0x30000U)
#define ADC_CWSELRPI_WSEL_SI0_4_SHIFT            (16U)
/*! WSEL_SI0_4 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRPI_WSEL_SI0_4(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRPI_WSEL_SI0_4_SHIFT)) & ADC_CWSELRPI_WSEL_SI0_4_MASK)

#define ADC_CWSELRPI_WSEL_SI0_5_MASK             (0x300000U)
#define ADC_CWSELRPI_WSEL_SI0_5_SHIFT            (20U)
/*! WSEL_SI0_5 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRPI_WSEL_SI0_5(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRPI_WSEL_SI0_5_SHIFT)) & ADC_CWSELRPI_WSEL_SI0_5_MASK)

#define ADC_CWSELRPI_WSEL_SI0_6_MASK             (0x3000000U)
#define ADC_CWSELRPI_WSEL_SI0_6_SHIFT            (24U)
/*! WSEL_SI0_6 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRPI_WSEL_SI0_6(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRPI_WSEL_SI0_6_SHIFT)) & ADC_CWSELRPI_WSEL_SI0_6_MASK)

#define ADC_CWSELRPI_WSEL_SI0_7_MASK             (0x30000000U)
#define ADC_CWSELRPI_WSEL_SI0_7_SHIFT            (28U)
/*! WSEL_SI0_7 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRPI_WSEL_SI0_7(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRPI_WSEL_SI0_7_SHIFT)) & ADC_CWSELRPI_WSEL_SI0_7_MASK)
/*! @} */

/*! @name CWSELRSI - Channel Analog Watchdog Select For Standard Inputs */
/*! @{ */

#define ADC_CWSELRSI_WSEL_SI0_0_MASK             (0x3U)
#define ADC_CWSELRSI_WSEL_SI0_0_SHIFT            (0U)
/*! WSEL_SI0_0 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI0_0(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI0_0_SHIFT)) & ADC_CWSELRSI_WSEL_SI0_0_MASK)

#define ADC_CWSELRSI_WSEL_SI0_1_MASK             (0x3U)
#define ADC_CWSELRSI_WSEL_SI0_1_SHIFT            (0U)
/*! WSEL_SI0_1 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI0_1(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI0_1_SHIFT)) & ADC_CWSELRSI_WSEL_SI0_1_MASK)

#define ADC_CWSELRSI_WSEL_SI0_2_MASK             (0x3U)
#define ADC_CWSELRSI_WSEL_SI0_2_SHIFT            (0U)
/*! WSEL_SI0_2 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI0_2(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI0_2_SHIFT)) & ADC_CWSELRSI_WSEL_SI0_2_MASK)

#define ADC_CWSELRSI_WSEL_SI1_0_MASK             (0x30U)
#define ADC_CWSELRSI_WSEL_SI1_0_SHIFT            (4U)
/*! WSEL_SI1_0 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI1_0(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI1_0_SHIFT)) & ADC_CWSELRSI_WSEL_SI1_0_MASK)

#define ADC_CWSELRSI_WSEL_SI1_1_MASK             (0x30U)
#define ADC_CWSELRSI_WSEL_SI1_1_SHIFT            (4U)
/*! WSEL_SI1_1 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI1_1(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI1_1_SHIFT)) & ADC_CWSELRSI_WSEL_SI1_1_MASK)

#define ADC_CWSELRSI_WSEL_SI1_2_MASK             (0x30U)
#define ADC_CWSELRSI_WSEL_SI1_2_SHIFT            (4U)
/*! WSEL_SI1_2 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI1_2(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI1_2_SHIFT)) & ADC_CWSELRSI_WSEL_SI1_2_MASK)

#define ADC_CWSELRSI_WSEL_SI2_0_MASK             (0x300U)
#define ADC_CWSELRSI_WSEL_SI2_0_SHIFT            (8U)
/*! WSEL_SI2_0 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI2_0(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI2_0_SHIFT)) & ADC_CWSELRSI_WSEL_SI2_0_MASK)

#define ADC_CWSELRSI_WSEL_SI2_1_MASK             (0x300U)
#define ADC_CWSELRSI_WSEL_SI2_1_SHIFT            (8U)
/*! WSEL_SI2_1 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI2_1(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI2_1_SHIFT)) & ADC_CWSELRSI_WSEL_SI2_1_MASK)

#define ADC_CWSELRSI_WSEL_SI2_2_MASK             (0x300U)
#define ADC_CWSELRSI_WSEL_SI2_2_SHIFT            (8U)
/*! WSEL_SI2_2 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI2_2(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI2_2_SHIFT)) & ADC_CWSELRSI_WSEL_SI2_2_MASK)

#define ADC_CWSELRSI_WSEL_SI3_0_MASK             (0x3000U)
#define ADC_CWSELRSI_WSEL_SI3_0_SHIFT            (12U)
/*! WSEL_SI3_0 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI3_0(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI3_0_SHIFT)) & ADC_CWSELRSI_WSEL_SI3_0_MASK)

#define ADC_CWSELRSI_WSEL_SI3_1_MASK             (0x3000U)
#define ADC_CWSELRSI_WSEL_SI3_1_SHIFT            (12U)
/*! WSEL_SI3_1 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI3_1(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI3_1_SHIFT)) & ADC_CWSELRSI_WSEL_SI3_1_MASK)

#define ADC_CWSELRSI_WSEL_SI3_2_MASK             (0x3000U)
#define ADC_CWSELRSI_WSEL_SI3_2_SHIFT            (12U)
/*! WSEL_SI3_2 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI3_2(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI3_2_SHIFT)) & ADC_CWSELRSI_WSEL_SI3_2_MASK)

#define ADC_CWSELRSI_WSEL_SI4_0_MASK             (0x30000U)
#define ADC_CWSELRSI_WSEL_SI4_0_SHIFT            (16U)
/*! WSEL_SI4_0 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI4_0(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI4_0_SHIFT)) & ADC_CWSELRSI_WSEL_SI4_0_MASK)

#define ADC_CWSELRSI_WSEL_SI4_1_MASK             (0x30000U)
#define ADC_CWSELRSI_WSEL_SI4_1_SHIFT            (16U)
/*! WSEL_SI4_1 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI4_1(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI4_1_SHIFT)) & ADC_CWSELRSI_WSEL_SI4_1_MASK)

#define ADC_CWSELRSI_WSEL_SI4_2_MASK             (0x30000U)
#define ADC_CWSELRSI_WSEL_SI4_2_SHIFT            (16U)
/*! WSEL_SI4_2 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI4_2(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI4_2_SHIFT)) & ADC_CWSELRSI_WSEL_SI4_2_MASK)

#define ADC_CWSELRSI_WSEL_SI5_0_MASK             (0x300000U)
#define ADC_CWSELRSI_WSEL_SI5_0_SHIFT            (20U)
/*! WSEL_SI5_0 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI5_0(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI5_0_SHIFT)) & ADC_CWSELRSI_WSEL_SI5_0_MASK)

#define ADC_CWSELRSI_WSEL_SI5_1_MASK             (0x300000U)
#define ADC_CWSELRSI_WSEL_SI5_1_SHIFT            (20U)
/*! WSEL_SI5_1 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI5_1(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI5_1_SHIFT)) & ADC_CWSELRSI_WSEL_SI5_1_MASK)

#define ADC_CWSELRSI_WSEL_SI5_2_MASK             (0x300000U)
#define ADC_CWSELRSI_WSEL_SI5_2_SHIFT            (20U)
/*! WSEL_SI5_2 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI5_2(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI5_2_SHIFT)) & ADC_CWSELRSI_WSEL_SI5_2_MASK)

#define ADC_CWSELRSI_WSEL_SI6_0_MASK             (0x3000000U)
#define ADC_CWSELRSI_WSEL_SI6_0_SHIFT            (24U)
/*! WSEL_SI6_0 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI6_0(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI6_0_SHIFT)) & ADC_CWSELRSI_WSEL_SI6_0_MASK)

#define ADC_CWSELRSI_WSEL_SI6_1_MASK             (0x3000000U)
#define ADC_CWSELRSI_WSEL_SI6_1_SHIFT            (24U)
/*! WSEL_SI6_1 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI6_1(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI6_1_SHIFT)) & ADC_CWSELRSI_WSEL_SI6_1_MASK)

#define ADC_CWSELRSI_WSEL_SI6_2_MASK             (0x3000000U)
#define ADC_CWSELRSI_WSEL_SI6_2_SHIFT            (24U)
/*! WSEL_SI6_2 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI6_2(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI6_2_SHIFT)) & ADC_CWSELRSI_WSEL_SI6_2_MASK)

#define ADC_CWSELRSI_WSEL_SI7_0_MASK             (0x30000000U)
#define ADC_CWSELRSI_WSEL_SI7_0_SHIFT            (28U)
/*! WSEL_SI7_0 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI7_0(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI7_0_SHIFT)) & ADC_CWSELRSI_WSEL_SI7_0_MASK)

#define ADC_CWSELRSI_WSEL_SI7_1_MASK             (0x30000000U)
#define ADC_CWSELRSI_WSEL_SI7_1_SHIFT            (28U)
/*! WSEL_SI7_1 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI7_1(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI7_1_SHIFT)) & ADC_CWSELRSI_WSEL_SI7_1_MASK)

#define ADC_CWSELRSI_WSEL_SI7_2_MASK             (0x30000000U)
#define ADC_CWSELRSI_WSEL_SI7_2_SHIFT            (28U)
/*! WSEL_SI7_2 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELRSI_WSEL_SI7_2(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELRSI_WSEL_SI7_2_SHIFT)) & ADC_CWSELRSI_WSEL_SI7_2_MASK)
/*! @} */

/*! @name CWSELREI - Channel Analog Watchdog Select For External inputs */
/*! @{ */

#define ADC_CWSELREI_WSEL_SI0_0_MASK             (0x3U)
#define ADC_CWSELREI_WSEL_SI0_0_SHIFT            (0U)
/*! WSEL_SI0_0 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI0_0(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI0_0_SHIFT)) & ADC_CWSELREI_WSEL_SI0_0_MASK)

#define ADC_CWSELREI_WSEL_SI1_8_MASK             (0x3U)
#define ADC_CWSELREI_WSEL_SI1_8_SHIFT            (0U)
/*! WSEL_SI1_8 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI1_8(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI1_8_SHIFT)) & ADC_CWSELREI_WSEL_SI1_8_MASK)

#define ADC_CWSELREI_WSEL_SI2_16_MASK            (0x3U)
#define ADC_CWSELREI_WSEL_SI2_16_SHIFT           (0U)
/*! WSEL_SI2_16 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI2_16(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI2_16_SHIFT)) & ADC_CWSELREI_WSEL_SI2_16_MASK)

#define ADC_CWSELREI_WSEL_SI3_24_MASK            (0x3U)
#define ADC_CWSELREI_WSEL_SI3_24_SHIFT           (0U)
/*! WSEL_SI3_24 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI3_24(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI3_24_SHIFT)) & ADC_CWSELREI_WSEL_SI3_24_MASK)

#define ADC_CWSELREI_WSEL_SI0_1_MASK             (0x30U)
#define ADC_CWSELREI_WSEL_SI0_1_SHIFT            (4U)
/*! WSEL_SI0_1 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI0_1(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI0_1_SHIFT)) & ADC_CWSELREI_WSEL_SI0_1_MASK)

#define ADC_CWSELREI_WSEL_SI1_9_MASK             (0x30U)
#define ADC_CWSELREI_WSEL_SI1_9_SHIFT            (4U)
/*! WSEL_SI1_9 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI1_9(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI1_9_SHIFT)) & ADC_CWSELREI_WSEL_SI1_9_MASK)

#define ADC_CWSELREI_WSEL_SI2_17_MASK            (0x30U)
#define ADC_CWSELREI_WSEL_SI2_17_SHIFT           (4U)
/*! WSEL_SI2_17 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI2_17(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI2_17_SHIFT)) & ADC_CWSELREI_WSEL_SI2_17_MASK)

#define ADC_CWSELREI_WSEL_SI3_25_MASK            (0x30U)
#define ADC_CWSELREI_WSEL_SI3_25_SHIFT           (4U)
/*! WSEL_SI3_25 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI3_25(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI3_25_SHIFT)) & ADC_CWSELREI_WSEL_SI3_25_MASK)

#define ADC_CWSELREI_WSEL_SI0_2_MASK             (0x300U)
#define ADC_CWSELREI_WSEL_SI0_2_SHIFT            (8U)
/*! WSEL_SI0_2 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI0_2(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI0_2_SHIFT)) & ADC_CWSELREI_WSEL_SI0_2_MASK)

#define ADC_CWSELREI_WSEL_SI1_10_MASK            (0x300U)
#define ADC_CWSELREI_WSEL_SI1_10_SHIFT           (8U)
/*! WSEL_SI1_10 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI1_10(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI1_10_SHIFT)) & ADC_CWSELREI_WSEL_SI1_10_MASK)

#define ADC_CWSELREI_WSEL_SI2_18_MASK            (0x300U)
#define ADC_CWSELREI_WSEL_SI2_18_SHIFT           (8U)
/*! WSEL_SI2_18 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI2_18(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI2_18_SHIFT)) & ADC_CWSELREI_WSEL_SI2_18_MASK)

#define ADC_CWSELREI_WSEL_SI3_26_MASK            (0x300U)
#define ADC_CWSELREI_WSEL_SI3_26_SHIFT           (8U)
/*! WSEL_SI3_26 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI3_26(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI3_26_SHIFT)) & ADC_CWSELREI_WSEL_SI3_26_MASK)

#define ADC_CWSELREI_WSEL_SI0_3_MASK             (0x3000U)
#define ADC_CWSELREI_WSEL_SI0_3_SHIFT            (12U)
/*! WSEL_SI0_3 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI0_3(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI0_3_SHIFT)) & ADC_CWSELREI_WSEL_SI0_3_MASK)

#define ADC_CWSELREI_WSEL_SI1_11_MASK            (0x3000U)
#define ADC_CWSELREI_WSEL_SI1_11_SHIFT           (12U)
/*! WSEL_SI1_11 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI1_11(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI1_11_SHIFT)) & ADC_CWSELREI_WSEL_SI1_11_MASK)

#define ADC_CWSELREI_WSEL_SI2_19_MASK            (0x3000U)
#define ADC_CWSELREI_WSEL_SI2_19_SHIFT           (12U)
/*! WSEL_SI2_19 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI2_19(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI2_19_SHIFT)) & ADC_CWSELREI_WSEL_SI2_19_MASK)

#define ADC_CWSELREI_WSEL_SI3_27_MASK            (0x3000U)
#define ADC_CWSELREI_WSEL_SI3_27_SHIFT           (12U)
/*! WSEL_SI3_27 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI3_27(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI3_27_SHIFT)) & ADC_CWSELREI_WSEL_SI3_27_MASK)

#define ADC_CWSELREI_WSEL_SI0_4_MASK             (0x30000U)
#define ADC_CWSELREI_WSEL_SI0_4_SHIFT            (16U)
/*! WSEL_SI0_4 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI0_4(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI0_4_SHIFT)) & ADC_CWSELREI_WSEL_SI0_4_MASK)

#define ADC_CWSELREI_WSEL_SI1_12_MASK            (0x30000U)
#define ADC_CWSELREI_WSEL_SI1_12_SHIFT           (16U)
/*! WSEL_SI1_12 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI1_12(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI1_12_SHIFT)) & ADC_CWSELREI_WSEL_SI1_12_MASK)

#define ADC_CWSELREI_WSEL_SI2_20_MASK            (0x30000U)
#define ADC_CWSELREI_WSEL_SI2_20_SHIFT           (16U)
/*! WSEL_SI2_20 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI2_20(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI2_20_SHIFT)) & ADC_CWSELREI_WSEL_SI2_20_MASK)

#define ADC_CWSELREI_WSEL_SI3_28_MASK            (0x30000U)
#define ADC_CWSELREI_WSEL_SI3_28_SHIFT           (16U)
/*! WSEL_SI3_28 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI3_28(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI3_28_SHIFT)) & ADC_CWSELREI_WSEL_SI3_28_MASK)

#define ADC_CWSELREI_WSEL_SI0_5_MASK             (0x300000U)
#define ADC_CWSELREI_WSEL_SI0_5_SHIFT            (20U)
/*! WSEL_SI0_5 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI0_5(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI0_5_SHIFT)) & ADC_CWSELREI_WSEL_SI0_5_MASK)

#define ADC_CWSELREI_WSEL_SI1_13_MASK            (0x300000U)
#define ADC_CWSELREI_WSEL_SI1_13_SHIFT           (20U)
/*! WSEL_SI1_13 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI1_13(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI1_13_SHIFT)) & ADC_CWSELREI_WSEL_SI1_13_MASK)

#define ADC_CWSELREI_WSEL_SI2_21_MASK            (0x300000U)
#define ADC_CWSELREI_WSEL_SI2_21_SHIFT           (20U)
/*! WSEL_SI2_21 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI2_21(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI2_21_SHIFT)) & ADC_CWSELREI_WSEL_SI2_21_MASK)

#define ADC_CWSELREI_WSEL_SI3_29_MASK            (0x300000U)
#define ADC_CWSELREI_WSEL_SI3_29_SHIFT           (20U)
/*! WSEL_SI3_29 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI3_29(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI3_29_SHIFT)) & ADC_CWSELREI_WSEL_SI3_29_MASK)

#define ADC_CWSELREI_WSEL_SI0_6_MASK             (0x3000000U)
#define ADC_CWSELREI_WSEL_SI0_6_SHIFT            (24U)
/*! WSEL_SI0_6 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI0_6(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI0_6_SHIFT)) & ADC_CWSELREI_WSEL_SI0_6_MASK)

#define ADC_CWSELREI_WSEL_SI1_14_MASK            (0x3000000U)
#define ADC_CWSELREI_WSEL_SI1_14_SHIFT           (24U)
/*! WSEL_SI1_14 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI1_14(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI1_14_SHIFT)) & ADC_CWSELREI_WSEL_SI1_14_MASK)

#define ADC_CWSELREI_WSEL_SI2_22_MASK            (0x3000000U)
#define ADC_CWSELREI_WSEL_SI2_22_SHIFT           (24U)
/*! WSEL_SI2_22 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI2_22(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI2_22_SHIFT)) & ADC_CWSELREI_WSEL_SI2_22_MASK)

#define ADC_CWSELREI_WSEL_SI3_30_MASK            (0x3000000U)
#define ADC_CWSELREI_WSEL_SI3_30_SHIFT           (24U)
/*! WSEL_SI3_30 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI3_30(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI3_30_SHIFT)) & ADC_CWSELREI_WSEL_SI3_30_MASK)

#define ADC_CWSELREI_WSEL_SI0_7_MASK             (0x30000000U)
#define ADC_CWSELREI_WSEL_SI0_7_SHIFT            (28U)
/*! WSEL_SI0_7 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI0_7(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI0_7_SHIFT)) & ADC_CWSELREI_WSEL_SI0_7_MASK)

#define ADC_CWSELREI_WSEL_SI1_15_MASK            (0x30000000U)
#define ADC_CWSELREI_WSEL_SI1_15_SHIFT           (28U)
/*! WSEL_SI1_15 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI1_15(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI1_15_SHIFT)) & ADC_CWSELREI_WSEL_SI1_15_MASK)

#define ADC_CWSELREI_WSEL_SI2_23_MASK            (0x30000000U)
#define ADC_CWSELREI_WSEL_SI2_23_SHIFT           (28U)
/*! WSEL_SI2_23 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI2_23(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI2_23_SHIFT)) & ADC_CWSELREI_WSEL_SI2_23_MASK)

#define ADC_CWSELREI_WSEL_SI3_31_MASK            (0x30000000U)
#define ADC_CWSELREI_WSEL_SI3_31_SHIFT           (28U)
/*! WSEL_SI3_31 - Analog Watchdog Selection
 *  0b00..Analog watchdog THRHLR0
 *  0b01..Analog watchdog THRHLR1
 *  0b10..Analog watchdog THRHLR2
 *  0b11..Analog watchdog THRHLR3
 */
#define ADC_CWSELREI_WSEL_SI3_31(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CWSELREI_WSEL_SI3_31_SHIFT)) & ADC_CWSELREI_WSEL_SI3_31_MASK)
/*! @} */

/*! @name CWENR0 - Channel Watchdog Enable For Precision Inputs */
/*! @{ */

#define ADC_CWENR0_CWEN0_MASK                    (0x1U)
#define ADC_CWENR0_CWEN0_SHIFT                   (0U)
/*! CWEN0 - Channel Analog Watchdog Enable 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR0_CWEN0(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN0_SHIFT)) & ADC_CWENR0_CWEN0_MASK)

#define ADC_CWENR0_CWEN1_MASK                    (0x2U)
#define ADC_CWENR0_CWEN1_SHIFT                   (1U)
/*! CWEN1 - Channel Analog Watchdog Enable 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR0_CWEN1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN1_SHIFT)) & ADC_CWENR0_CWEN1_MASK)

#define ADC_CWENR0_CWEN2_MASK                    (0x4U)
#define ADC_CWENR0_CWEN2_SHIFT                   (2U)
/*! CWEN2 - Channel Analog Watchdog Enable 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR0_CWEN2(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN2_SHIFT)) & ADC_CWENR0_CWEN2_MASK)

#define ADC_CWENR0_CWEN3_MASK                    (0x8U)
#define ADC_CWENR0_CWEN3_SHIFT                   (3U)
/*! CWEN3 - Channel Analog Watchdog Enable 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR0_CWEN3(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN3_SHIFT)) & ADC_CWENR0_CWEN3_MASK)

#define ADC_CWENR0_CWEN4_MASK                    (0x10U)
#define ADC_CWENR0_CWEN4_SHIFT                   (4U)
/*! CWEN4 - Channel Analog Watchdog Enable 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR0_CWEN4(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN4_SHIFT)) & ADC_CWENR0_CWEN4_MASK)

#define ADC_CWENR0_CWEN5_MASK                    (0x20U)
#define ADC_CWENR0_CWEN5_SHIFT                   (5U)
/*! CWEN5 - Channel Analog Watchdog Enable 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR0_CWEN5(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN5_SHIFT)) & ADC_CWENR0_CWEN5_MASK)

#define ADC_CWENR0_CWEN6_MASK                    (0x40U)
#define ADC_CWENR0_CWEN6_SHIFT                   (6U)
/*! CWEN6 - Channel Analog Watchdog Enable 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR0_CWEN6(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN6_SHIFT)) & ADC_CWENR0_CWEN6_MASK)

#define ADC_CWENR0_CWEN7_MASK                    (0x80U)
#define ADC_CWENR0_CWEN7_SHIFT                   (7U)
/*! CWEN7 - Channel Analog Watchdog Enable 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR0_CWEN7(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CWENR0_CWEN7_SHIFT)) & ADC_CWENR0_CWEN7_MASK)
/*! @} */

/*! @name CWENR1 - Channel Watchdog Enable For Standard Inputs */
/*! @{ */

#define ADC_CWENR1_CWEN32_MASK                   (0x1U)
#define ADC_CWENR1_CWEN32_SHIFT                  (0U)
/*! CWEN32 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN32(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN32_SHIFT)) & ADC_CWENR1_CWEN32_MASK)

#define ADC_CWENR1_CWEN33_MASK                   (0x2U)
#define ADC_CWENR1_CWEN33_SHIFT                  (1U)
/*! CWEN33 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN33(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN33_SHIFT)) & ADC_CWENR1_CWEN33_MASK)

#define ADC_CWENR1_CWEN34_MASK                   (0x4U)
#define ADC_CWENR1_CWEN34_SHIFT                  (2U)
/*! CWEN34 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN34(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN34_SHIFT)) & ADC_CWENR1_CWEN34_MASK)

#define ADC_CWENR1_CWEN35_MASK                   (0x8U)
#define ADC_CWENR1_CWEN35_SHIFT                  (3U)
/*! CWEN35 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN35(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN35_SHIFT)) & ADC_CWENR1_CWEN35_MASK)

#define ADC_CWENR1_CWEN36_MASK                   (0x10U)
#define ADC_CWENR1_CWEN36_SHIFT                  (4U)
/*! CWEN36 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN36(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN36_SHIFT)) & ADC_CWENR1_CWEN36_MASK)

#define ADC_CWENR1_CWEN37_MASK                   (0x20U)
#define ADC_CWENR1_CWEN37_SHIFT                  (5U)
/*! CWEN37 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN37(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN37_SHIFT)) & ADC_CWENR1_CWEN37_MASK)

#define ADC_CWENR1_CWEN38_MASK                   (0x40U)
#define ADC_CWENR1_CWEN38_SHIFT                  (6U)
/*! CWEN38 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN38(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN38_SHIFT)) & ADC_CWENR1_CWEN38_MASK)

#define ADC_CWENR1_CWEN39_MASK                   (0x80U)
#define ADC_CWENR1_CWEN39_SHIFT                  (7U)
/*! CWEN39 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN39(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN39_SHIFT)) & ADC_CWENR1_CWEN39_MASK)

#define ADC_CWENR1_CWEN40_MASK                   (0x100U)
#define ADC_CWENR1_CWEN40_SHIFT                  (8U)
/*! CWEN40 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN40(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN40_SHIFT)) & ADC_CWENR1_CWEN40_MASK)

#define ADC_CWENR1_CWEN41_MASK                   (0x200U)
#define ADC_CWENR1_CWEN41_SHIFT                  (9U)
/*! CWEN41 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN41(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN41_SHIFT)) & ADC_CWENR1_CWEN41_MASK)

#define ADC_CWENR1_CWEN42_MASK                   (0x400U)
#define ADC_CWENR1_CWEN42_SHIFT                  (10U)
/*! CWEN42 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN42(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN42_SHIFT)) & ADC_CWENR1_CWEN42_MASK)

#define ADC_CWENR1_CWEN43_MASK                   (0x800U)
#define ADC_CWENR1_CWEN43_SHIFT                  (11U)
/*! CWEN43 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN43(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN43_SHIFT)) & ADC_CWENR1_CWEN43_MASK)

#define ADC_CWENR1_CWEN44_MASK                   (0x1000U)
#define ADC_CWENR1_CWEN44_SHIFT                  (12U)
/*! CWEN44 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN44(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN44_SHIFT)) & ADC_CWENR1_CWEN44_MASK)

#define ADC_CWENR1_CWEN45_MASK                   (0x2000U)
#define ADC_CWENR1_CWEN45_SHIFT                  (13U)
/*! CWEN45 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN45(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN45_SHIFT)) & ADC_CWENR1_CWEN45_MASK)

#define ADC_CWENR1_CWEN46_MASK                   (0x4000U)
#define ADC_CWENR1_CWEN46_SHIFT                  (14U)
/*! CWEN46 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN46(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN46_SHIFT)) & ADC_CWENR1_CWEN46_MASK)

#define ADC_CWENR1_CWEN47_MASK                   (0x8000U)
#define ADC_CWENR1_CWEN47_SHIFT                  (15U)
/*! CWEN47 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN47(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN47_SHIFT)) & ADC_CWENR1_CWEN47_MASK)

#define ADC_CWENR1_CWEN48_MASK                   (0x10000U)
#define ADC_CWENR1_CWEN48_SHIFT                  (16U)
/*! CWEN48 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN48(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN48_SHIFT)) & ADC_CWENR1_CWEN48_MASK)

#define ADC_CWENR1_CWEN49_MASK                   (0x20000U)
#define ADC_CWENR1_CWEN49_SHIFT                  (17U)
/*! CWEN49 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN49(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN49_SHIFT)) & ADC_CWENR1_CWEN49_MASK)

#define ADC_CWENR1_CWEN50_MASK                   (0x40000U)
#define ADC_CWENR1_CWEN50_SHIFT                  (18U)
/*! CWEN50 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN50(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN50_SHIFT)) & ADC_CWENR1_CWEN50_MASK)

#define ADC_CWENR1_CWEN51_MASK                   (0x80000U)
#define ADC_CWENR1_CWEN51_SHIFT                  (19U)
/*! CWEN51 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN51(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN51_SHIFT)) & ADC_CWENR1_CWEN51_MASK)

#define ADC_CWENR1_CWEN52_MASK                   (0x100000U)
#define ADC_CWENR1_CWEN52_SHIFT                  (20U)
/*! CWEN52 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN52(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN52_SHIFT)) & ADC_CWENR1_CWEN52_MASK)

#define ADC_CWENR1_CWEN53_MASK                   (0x200000U)
#define ADC_CWENR1_CWEN53_SHIFT                  (21U)
/*! CWEN53 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN53(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN53_SHIFT)) & ADC_CWENR1_CWEN53_MASK)

#define ADC_CWENR1_CWEN54_MASK                   (0x400000U)
#define ADC_CWENR1_CWEN54_SHIFT                  (22U)
/*! CWEN54 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN54(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN54_SHIFT)) & ADC_CWENR1_CWEN54_MASK)

#define ADC_CWENR1_CWEN55_MASK                   (0x800000U)
#define ADC_CWENR1_CWEN55_SHIFT                  (23U)
/*! CWEN55 - Channel Analog Watchdog Enable For Standard Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR1_CWEN55(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR1_CWEN55_SHIFT)) & ADC_CWENR1_CWEN55_MASK)
/*! @} */

/*! @name CWENR2 - Channel Watchdog Enable For External Inputs */
/*! @{ */

#define ADC_CWENR2_CWEN64_MASK                   (0x1U)
#define ADC_CWENR2_CWEN64_SHIFT                  (0U)
/*! CWEN64 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN64(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN64_SHIFT)) & ADC_CWENR2_CWEN64_MASK)

#define ADC_CWENR2_CWEN65_MASK                   (0x2U)
#define ADC_CWENR2_CWEN65_SHIFT                  (1U)
/*! CWEN65 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN65(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN65_SHIFT)) & ADC_CWENR2_CWEN65_MASK)

#define ADC_CWENR2_CWEN66_MASK                   (0x4U)
#define ADC_CWENR2_CWEN66_SHIFT                  (2U)
/*! CWEN66 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN66(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN66_SHIFT)) & ADC_CWENR2_CWEN66_MASK)

#define ADC_CWENR2_CWEN67_MASK                   (0x8U)
#define ADC_CWENR2_CWEN67_SHIFT                  (3U)
/*! CWEN67 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN67(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN67_SHIFT)) & ADC_CWENR2_CWEN67_MASK)

#define ADC_CWENR2_CWEN68_MASK                   (0x10U)
#define ADC_CWENR2_CWEN68_SHIFT                  (4U)
/*! CWEN68 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN68(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN68_SHIFT)) & ADC_CWENR2_CWEN68_MASK)

#define ADC_CWENR2_CWEN69_MASK                   (0x20U)
#define ADC_CWENR2_CWEN69_SHIFT                  (5U)
/*! CWEN69 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN69(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN69_SHIFT)) & ADC_CWENR2_CWEN69_MASK)

#define ADC_CWENR2_CWEN70_MASK                   (0x40U)
#define ADC_CWENR2_CWEN70_SHIFT                  (6U)
/*! CWEN70 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN70(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN70_SHIFT)) & ADC_CWENR2_CWEN70_MASK)

#define ADC_CWENR2_CWEN71_MASK                   (0x80U)
#define ADC_CWENR2_CWEN71_SHIFT                  (7U)
/*! CWEN71 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN71(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN71_SHIFT)) & ADC_CWENR2_CWEN71_MASK)

#define ADC_CWENR2_CWEN72_MASK                   (0x100U)
#define ADC_CWENR2_CWEN72_SHIFT                  (8U)
/*! CWEN72 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN72(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN72_SHIFT)) & ADC_CWENR2_CWEN72_MASK)

#define ADC_CWENR2_CWEN73_MASK                   (0x200U)
#define ADC_CWENR2_CWEN73_SHIFT                  (9U)
/*! CWEN73 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN73(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN73_SHIFT)) & ADC_CWENR2_CWEN73_MASK)

#define ADC_CWENR2_CWEN74_MASK                   (0x400U)
#define ADC_CWENR2_CWEN74_SHIFT                  (10U)
/*! CWEN74 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN74(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN74_SHIFT)) & ADC_CWENR2_CWEN74_MASK)

#define ADC_CWENR2_CWEN75_MASK                   (0x800U)
#define ADC_CWENR2_CWEN75_SHIFT                  (11U)
/*! CWEN75 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN75(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN75_SHIFT)) & ADC_CWENR2_CWEN75_MASK)

#define ADC_CWENR2_CWEN76_MASK                   (0x1000U)
#define ADC_CWENR2_CWEN76_SHIFT                  (12U)
/*! CWEN76 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN76(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN76_SHIFT)) & ADC_CWENR2_CWEN76_MASK)

#define ADC_CWENR2_CWEN77_MASK                   (0x2000U)
#define ADC_CWENR2_CWEN77_SHIFT                  (13U)
/*! CWEN77 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN77(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN77_SHIFT)) & ADC_CWENR2_CWEN77_MASK)

#define ADC_CWENR2_CWEN78_MASK                   (0x4000U)
#define ADC_CWENR2_CWEN78_SHIFT                  (14U)
/*! CWEN78 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN78(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN78_SHIFT)) & ADC_CWENR2_CWEN78_MASK)

#define ADC_CWENR2_CWEN79_MASK                   (0x8000U)
#define ADC_CWENR2_CWEN79_SHIFT                  (15U)
/*! CWEN79 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN79(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN79_SHIFT)) & ADC_CWENR2_CWEN79_MASK)

#define ADC_CWENR2_CWEN80_MASK                   (0x10000U)
#define ADC_CWENR2_CWEN80_SHIFT                  (16U)
/*! CWEN80 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN80(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN80_SHIFT)) & ADC_CWENR2_CWEN80_MASK)

#define ADC_CWENR2_CWEN81_MASK                   (0x20000U)
#define ADC_CWENR2_CWEN81_SHIFT                  (17U)
/*! CWEN81 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN81(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN81_SHIFT)) & ADC_CWENR2_CWEN81_MASK)

#define ADC_CWENR2_CWEN82_MASK                   (0x40000U)
#define ADC_CWENR2_CWEN82_SHIFT                  (18U)
/*! CWEN82 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN82(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN82_SHIFT)) & ADC_CWENR2_CWEN82_MASK)

#define ADC_CWENR2_CWEN83_MASK                   (0x80000U)
#define ADC_CWENR2_CWEN83_SHIFT                  (19U)
/*! CWEN83 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN83(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN83_SHIFT)) & ADC_CWENR2_CWEN83_MASK)

#define ADC_CWENR2_CWEN84_MASK                   (0x100000U)
#define ADC_CWENR2_CWEN84_SHIFT                  (20U)
/*! CWEN84 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN84(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN84_SHIFT)) & ADC_CWENR2_CWEN84_MASK)

#define ADC_CWENR2_CWEN85_MASK                   (0x200000U)
#define ADC_CWENR2_CWEN85_SHIFT                  (21U)
/*! CWEN85 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN85(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN85_SHIFT)) & ADC_CWENR2_CWEN85_MASK)

#define ADC_CWENR2_CWEN86_MASK                   (0x400000U)
#define ADC_CWENR2_CWEN86_SHIFT                  (22U)
/*! CWEN86 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN86(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN86_SHIFT)) & ADC_CWENR2_CWEN86_MASK)

#define ADC_CWENR2_CWEN87_MASK                   (0x800000U)
#define ADC_CWENR2_CWEN87_SHIFT                  (23U)
/*! CWEN87 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN87(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN87_SHIFT)) & ADC_CWENR2_CWEN87_MASK)

#define ADC_CWENR2_CWEN88_MASK                   (0x1000000U)
#define ADC_CWENR2_CWEN88_SHIFT                  (24U)
/*! CWEN88 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN88(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN88_SHIFT)) & ADC_CWENR2_CWEN88_MASK)

#define ADC_CWENR2_CWEN89_MASK                   (0x2000000U)
#define ADC_CWENR2_CWEN89_SHIFT                  (25U)
/*! CWEN89 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN89(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN89_SHIFT)) & ADC_CWENR2_CWEN89_MASK)

#define ADC_CWENR2_CWEN90_MASK                   (0x4000000U)
#define ADC_CWENR2_CWEN90_SHIFT                  (26U)
/*! CWEN90 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN90(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN90_SHIFT)) & ADC_CWENR2_CWEN90_MASK)

#define ADC_CWENR2_CWEN91_MASK                   (0x8000000U)
#define ADC_CWENR2_CWEN91_SHIFT                  (27U)
/*! CWEN91 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN91(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN91_SHIFT)) & ADC_CWENR2_CWEN91_MASK)

#define ADC_CWENR2_CWEN92_MASK                   (0x10000000U)
#define ADC_CWENR2_CWEN92_SHIFT                  (28U)
/*! CWEN92 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN92(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN92_SHIFT)) & ADC_CWENR2_CWEN92_MASK)

#define ADC_CWENR2_CWEN93_MASK                   (0x20000000U)
#define ADC_CWENR2_CWEN93_SHIFT                  (29U)
/*! CWEN93 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN93(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN93_SHIFT)) & ADC_CWENR2_CWEN93_MASK)

#define ADC_CWENR2_CWEN94_MASK                   (0x40000000U)
#define ADC_CWENR2_CWEN94_SHIFT                  (30U)
/*! CWEN94 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN94(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN94_SHIFT)) & ADC_CWENR2_CWEN94_MASK)

#define ADC_CWENR2_CWEN95_MASK                   (0x80000000U)
#define ADC_CWENR2_CWEN95_SHIFT                  (31U)
/*! CWEN95 - Channel Analog Watchdog Enable For External Inputs
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CWENR2_CWEN95(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CWENR2_CWEN95_SHIFT)) & ADC_CWENR2_CWEN95_MASK)
/*! @} */

/*! @name AWORR0 - Analog Watchdog Out Of Range For Precision Inputs */
/*! @{ */

#define ADC_AWORR0_AWOR_CH0_MASK                 (0x1U)
#define ADC_AWORR0_AWOR_CH0_SHIFT                (0U)
/*! AWOR_CH0 - Analog Watchdog Out Of Range For Precision Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR0_AWOR_CH0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH0_SHIFT)) & ADC_AWORR0_AWOR_CH0_MASK)

#define ADC_AWORR0_AWOR_CH1_MASK                 (0x2U)
#define ADC_AWORR0_AWOR_CH1_SHIFT                (1U)
/*! AWOR_CH1 - Analog Watchdog Out Of Range For Precision Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR0_AWOR_CH1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH1_SHIFT)) & ADC_AWORR0_AWOR_CH1_MASK)

#define ADC_AWORR0_AWOR_CH2_MASK                 (0x4U)
#define ADC_AWORR0_AWOR_CH2_SHIFT                (2U)
/*! AWOR_CH2 - Analog Watchdog Out Of Range For Precision Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR0_AWOR_CH2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH2_SHIFT)) & ADC_AWORR0_AWOR_CH2_MASK)

#define ADC_AWORR0_AWOR_CH3_MASK                 (0x8U)
#define ADC_AWORR0_AWOR_CH3_SHIFT                (3U)
/*! AWOR_CH3 - Analog Watchdog Out Of Range For Precision Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR0_AWOR_CH3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH3_SHIFT)) & ADC_AWORR0_AWOR_CH3_MASK)

#define ADC_AWORR0_AWOR_CH4_MASK                 (0x10U)
#define ADC_AWORR0_AWOR_CH4_SHIFT                (4U)
/*! AWOR_CH4 - Analog Watchdog Out Of Range For Precision Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR0_AWOR_CH4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH4_SHIFT)) & ADC_AWORR0_AWOR_CH4_MASK)

#define ADC_AWORR0_AWOR_CH5_MASK                 (0x20U)
#define ADC_AWORR0_AWOR_CH5_SHIFT                (5U)
/*! AWOR_CH5 - Analog Watchdog Out Of Range For Precision Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR0_AWOR_CH5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH5_SHIFT)) & ADC_AWORR0_AWOR_CH5_MASK)

#define ADC_AWORR0_AWOR_CH6_MASK                 (0x40U)
#define ADC_AWORR0_AWOR_CH6_SHIFT                (6U)
/*! AWOR_CH6 - Analog Watchdog Out Of Range For Precision Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR0_AWOR_CH6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH6_SHIFT)) & ADC_AWORR0_AWOR_CH6_MASK)

#define ADC_AWORR0_AWOR_CH7_MASK                 (0x80U)
#define ADC_AWORR0_AWOR_CH7_SHIFT                (7U)
/*! AWOR_CH7 - Analog Watchdog Out Of Range For Precision Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR0_AWOR_CH7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR0_AWOR_CH7_SHIFT)) & ADC_AWORR0_AWOR_CH7_MASK)
/*! @} */

/*! @name AWORR1 - Analog Watchdog Out Of Range For Standard Inputs */
/*! @{ */

#define ADC_AWORR1_AWOR_CH0_MASK                 (0x1U)
#define ADC_AWORR1_AWOR_CH0_SHIFT                (0U)
/*! AWOR_CH0 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH0_SHIFT)) & ADC_AWORR1_AWOR_CH0_MASK)

#define ADC_AWORR1_AWOR_CH1_MASK                 (0x2U)
#define ADC_AWORR1_AWOR_CH1_SHIFT                (1U)
/*! AWOR_CH1 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH1_SHIFT)) & ADC_AWORR1_AWOR_CH1_MASK)

#define ADC_AWORR1_AWOR_CH2_MASK                 (0x4U)
#define ADC_AWORR1_AWOR_CH2_SHIFT                (2U)
/*! AWOR_CH2 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH2_SHIFT)) & ADC_AWORR1_AWOR_CH2_MASK)

#define ADC_AWORR1_AWOR_CH3_MASK                 (0x8U)
#define ADC_AWORR1_AWOR_CH3_SHIFT                (3U)
/*! AWOR_CH3 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH3_SHIFT)) & ADC_AWORR1_AWOR_CH3_MASK)

#define ADC_AWORR1_AWOR_CH4_MASK                 (0x10U)
#define ADC_AWORR1_AWOR_CH4_SHIFT                (4U)
/*! AWOR_CH4 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH4_SHIFT)) & ADC_AWORR1_AWOR_CH4_MASK)

#define ADC_AWORR1_AWOR_CH5_MASK                 (0x20U)
#define ADC_AWORR1_AWOR_CH5_SHIFT                (5U)
/*! AWOR_CH5 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH5_SHIFT)) & ADC_AWORR1_AWOR_CH5_MASK)

#define ADC_AWORR1_AWOR_CH6_MASK                 (0x40U)
#define ADC_AWORR1_AWOR_CH6_SHIFT                (6U)
/*! AWOR_CH6 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH6_SHIFT)) & ADC_AWORR1_AWOR_CH6_MASK)

#define ADC_AWORR1_AWOR_CH7_MASK                 (0x80U)
#define ADC_AWORR1_AWOR_CH7_SHIFT                (7U)
/*! AWOR_CH7 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH7_SHIFT)) & ADC_AWORR1_AWOR_CH7_MASK)

#define ADC_AWORR1_AWOR_CH8_MASK                 (0x100U)
#define ADC_AWORR1_AWOR_CH8_SHIFT                (8U)
/*! AWOR_CH8 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH8(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH8_SHIFT)) & ADC_AWORR1_AWOR_CH8_MASK)

#define ADC_AWORR1_AWOR_CH9_MASK                 (0x200U)
#define ADC_AWORR1_AWOR_CH9_SHIFT                (9U)
/*! AWOR_CH9 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH9(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH9_SHIFT)) & ADC_AWORR1_AWOR_CH9_MASK)

#define ADC_AWORR1_AWOR_CH10_MASK                (0x400U)
#define ADC_AWORR1_AWOR_CH10_SHIFT               (10U)
/*! AWOR_CH10 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH10(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH10_SHIFT)) & ADC_AWORR1_AWOR_CH10_MASK)

#define ADC_AWORR1_AWOR_CH11_MASK                (0x800U)
#define ADC_AWORR1_AWOR_CH11_SHIFT               (11U)
/*! AWOR_CH11 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH11(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH11_SHIFT)) & ADC_AWORR1_AWOR_CH11_MASK)

#define ADC_AWORR1_AWOR_CH12_MASK                (0x1000U)
#define ADC_AWORR1_AWOR_CH12_SHIFT               (12U)
/*! AWOR_CH12 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH12(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH12_SHIFT)) & ADC_AWORR1_AWOR_CH12_MASK)

#define ADC_AWORR1_AWOR_CH13_MASK                (0x2000U)
#define ADC_AWORR1_AWOR_CH13_SHIFT               (13U)
/*! AWOR_CH13 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH13(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH13_SHIFT)) & ADC_AWORR1_AWOR_CH13_MASK)

#define ADC_AWORR1_AWOR_CH14_MASK                (0x4000U)
#define ADC_AWORR1_AWOR_CH14_SHIFT               (14U)
/*! AWOR_CH14 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH14(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH14_SHIFT)) & ADC_AWORR1_AWOR_CH14_MASK)

#define ADC_AWORR1_AWOR_CH15_MASK                (0x8000U)
#define ADC_AWORR1_AWOR_CH15_SHIFT               (15U)
/*! AWOR_CH15 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH15(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH15_SHIFT)) & ADC_AWORR1_AWOR_CH15_MASK)

#define ADC_AWORR1_AWOR_CH16_MASK                (0x10000U)
#define ADC_AWORR1_AWOR_CH16_SHIFT               (16U)
/*! AWOR_CH16 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH16(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH16_SHIFT)) & ADC_AWORR1_AWOR_CH16_MASK)

#define ADC_AWORR1_AWOR_CH17_MASK                (0x20000U)
#define ADC_AWORR1_AWOR_CH17_SHIFT               (17U)
/*! AWOR_CH17 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH17(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH17_SHIFT)) & ADC_AWORR1_AWOR_CH17_MASK)

#define ADC_AWORR1_AWOR_CH18_MASK                (0x40000U)
#define ADC_AWORR1_AWOR_CH18_SHIFT               (18U)
/*! AWOR_CH18 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH18(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH18_SHIFT)) & ADC_AWORR1_AWOR_CH18_MASK)

#define ADC_AWORR1_AWOR_CH19_MASK                (0x80000U)
#define ADC_AWORR1_AWOR_CH19_SHIFT               (19U)
/*! AWOR_CH19 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH19(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH19_SHIFT)) & ADC_AWORR1_AWOR_CH19_MASK)

#define ADC_AWORR1_AWOR_CH20_MASK                (0x100000U)
#define ADC_AWORR1_AWOR_CH20_SHIFT               (20U)
/*! AWOR_CH20 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH20(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH20_SHIFT)) & ADC_AWORR1_AWOR_CH20_MASK)

#define ADC_AWORR1_AWOR_CH21_MASK                (0x200000U)
#define ADC_AWORR1_AWOR_CH21_SHIFT               (21U)
/*! AWOR_CH21 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH21(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH21_SHIFT)) & ADC_AWORR1_AWOR_CH21_MASK)

#define ADC_AWORR1_AWOR_CH22_MASK                (0x400000U)
#define ADC_AWORR1_AWOR_CH22_SHIFT               (22U)
/*! AWOR_CH22 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH22(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH22_SHIFT)) & ADC_AWORR1_AWOR_CH22_MASK)

#define ADC_AWORR1_AWOR_CH23_MASK                (0x800000U)
#define ADC_AWORR1_AWOR_CH23_SHIFT               (23U)
/*! AWOR_CH23 - Analog Watchdog Out Of Range For Standard Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR1_AWOR_CH23(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR1_AWOR_CH23_SHIFT)) & ADC_AWORR1_AWOR_CH23_MASK)
/*! @} */

/*! @name AWORR2 - Analog Watchdog Out Of Range For External Inputs */
/*! @{ */

#define ADC_AWORR2_AWOR_CH0_MASK                 (0x1U)
#define ADC_AWORR2_AWOR_CH0_SHIFT                (0U)
/*! AWOR_CH0 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH0_SHIFT)) & ADC_AWORR2_AWOR_CH0_MASK)

#define ADC_AWORR2_AWOR_CH1_MASK                 (0x2U)
#define ADC_AWORR2_AWOR_CH1_SHIFT                (1U)
/*! AWOR_CH1 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH1_SHIFT)) & ADC_AWORR2_AWOR_CH1_MASK)

#define ADC_AWORR2_AWOR_CH2_MASK                 (0x4U)
#define ADC_AWORR2_AWOR_CH2_SHIFT                (2U)
/*! AWOR_CH2 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH2_SHIFT)) & ADC_AWORR2_AWOR_CH2_MASK)

#define ADC_AWORR2_AWOR_CH3_MASK                 (0x8U)
#define ADC_AWORR2_AWOR_CH3_SHIFT                (3U)
/*! AWOR_CH3 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH3(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH3_SHIFT)) & ADC_AWORR2_AWOR_CH3_MASK)

#define ADC_AWORR2_AWOR_CH4_MASK                 (0x10U)
#define ADC_AWORR2_AWOR_CH4_SHIFT                (4U)
/*! AWOR_CH4 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH4(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH4_SHIFT)) & ADC_AWORR2_AWOR_CH4_MASK)

#define ADC_AWORR2_AWOR_CH5_MASK                 (0x20U)
#define ADC_AWORR2_AWOR_CH5_SHIFT                (5U)
/*! AWOR_CH5 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH5(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH5_SHIFT)) & ADC_AWORR2_AWOR_CH5_MASK)

#define ADC_AWORR2_AWOR_CH6_MASK                 (0x40U)
#define ADC_AWORR2_AWOR_CH6_SHIFT                (6U)
/*! AWOR_CH6 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH6(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH6_SHIFT)) & ADC_AWORR2_AWOR_CH6_MASK)

#define ADC_AWORR2_AWOR_CH7_MASK                 (0x80U)
#define ADC_AWORR2_AWOR_CH7_SHIFT                (7U)
/*! AWOR_CH7 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH7(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH7_SHIFT)) & ADC_AWORR2_AWOR_CH7_MASK)

#define ADC_AWORR2_AWOR_CH8_MASK                 (0x100U)
#define ADC_AWORR2_AWOR_CH8_SHIFT                (8U)
/*! AWOR_CH8 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH8(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH8_SHIFT)) & ADC_AWORR2_AWOR_CH8_MASK)

#define ADC_AWORR2_AWOR_CH9_MASK                 (0x200U)
#define ADC_AWORR2_AWOR_CH9_SHIFT                (9U)
/*! AWOR_CH9 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH9(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH9_SHIFT)) & ADC_AWORR2_AWOR_CH9_MASK)

#define ADC_AWORR2_AWOR_CH10_MASK                (0x400U)
#define ADC_AWORR2_AWOR_CH10_SHIFT               (10U)
/*! AWOR_CH10 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH10(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH10_SHIFT)) & ADC_AWORR2_AWOR_CH10_MASK)

#define ADC_AWORR2_AWOR_CH11_MASK                (0x800U)
#define ADC_AWORR2_AWOR_CH11_SHIFT               (11U)
/*! AWOR_CH11 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH11(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH11_SHIFT)) & ADC_AWORR2_AWOR_CH11_MASK)

#define ADC_AWORR2_AWOR_CH12_MASK                (0x1000U)
#define ADC_AWORR2_AWOR_CH12_SHIFT               (12U)
/*! AWOR_CH12 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH12(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH12_SHIFT)) & ADC_AWORR2_AWOR_CH12_MASK)

#define ADC_AWORR2_AWOR_CH13_MASK                (0x2000U)
#define ADC_AWORR2_AWOR_CH13_SHIFT               (13U)
/*! AWOR_CH13 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH13(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH13_SHIFT)) & ADC_AWORR2_AWOR_CH13_MASK)

#define ADC_AWORR2_AWOR_CH14_MASK                (0x4000U)
#define ADC_AWORR2_AWOR_CH14_SHIFT               (14U)
/*! AWOR_CH14 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH14(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH14_SHIFT)) & ADC_AWORR2_AWOR_CH14_MASK)

#define ADC_AWORR2_AWOR_CH15_MASK                (0x8000U)
#define ADC_AWORR2_AWOR_CH15_SHIFT               (15U)
/*! AWOR_CH15 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH15(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH15_SHIFT)) & ADC_AWORR2_AWOR_CH15_MASK)

#define ADC_AWORR2_AWOR_CH16_MASK                (0x10000U)
#define ADC_AWORR2_AWOR_CH16_SHIFT               (16U)
/*! AWOR_CH16 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH16(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH16_SHIFT)) & ADC_AWORR2_AWOR_CH16_MASK)

#define ADC_AWORR2_AWOR_CH17_MASK                (0x20000U)
#define ADC_AWORR2_AWOR_CH17_SHIFT               (17U)
/*! AWOR_CH17 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH17(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH17_SHIFT)) & ADC_AWORR2_AWOR_CH17_MASK)

#define ADC_AWORR2_AWOR_CH18_MASK                (0x40000U)
#define ADC_AWORR2_AWOR_CH18_SHIFT               (18U)
/*! AWOR_CH18 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH18(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH18_SHIFT)) & ADC_AWORR2_AWOR_CH18_MASK)

#define ADC_AWORR2_AWOR_CH19_MASK                (0x80000U)
#define ADC_AWORR2_AWOR_CH19_SHIFT               (19U)
/*! AWOR_CH19 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH19(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH19_SHIFT)) & ADC_AWORR2_AWOR_CH19_MASK)

#define ADC_AWORR2_AWOR_CH20_MASK                (0x100000U)
#define ADC_AWORR2_AWOR_CH20_SHIFT               (20U)
/*! AWOR_CH20 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH20(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH20_SHIFT)) & ADC_AWORR2_AWOR_CH20_MASK)

#define ADC_AWORR2_AWOR_CH21_MASK                (0x200000U)
#define ADC_AWORR2_AWOR_CH21_SHIFT               (21U)
/*! AWOR_CH21 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH21(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH21_SHIFT)) & ADC_AWORR2_AWOR_CH21_MASK)

#define ADC_AWORR2_AWOR_CH22_MASK                (0x400000U)
#define ADC_AWORR2_AWOR_CH22_SHIFT               (22U)
/*! AWOR_CH22 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH22(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH22_SHIFT)) & ADC_AWORR2_AWOR_CH22_MASK)

#define ADC_AWORR2_AWOR_CH23_MASK                (0x800000U)
#define ADC_AWORR2_AWOR_CH23_SHIFT               (23U)
/*! AWOR_CH23 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH23(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH23_SHIFT)) & ADC_AWORR2_AWOR_CH23_MASK)

#define ADC_AWORR2_AWOR_CH24_MASK                (0x1000000U)
#define ADC_AWORR2_AWOR_CH24_SHIFT               (24U)
/*! AWOR_CH24 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH24(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH24_SHIFT)) & ADC_AWORR2_AWOR_CH24_MASK)

#define ADC_AWORR2_AWOR_CH25_MASK                (0x2000000U)
#define ADC_AWORR2_AWOR_CH25_SHIFT               (25U)
/*! AWOR_CH25 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH25(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH25_SHIFT)) & ADC_AWORR2_AWOR_CH25_MASK)

#define ADC_AWORR2_AWOR_CH26_MASK                (0x4000000U)
#define ADC_AWORR2_AWOR_CH26_SHIFT               (26U)
/*! AWOR_CH26 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH26(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH26_SHIFT)) & ADC_AWORR2_AWOR_CH26_MASK)

#define ADC_AWORR2_AWOR_CH27_MASK                (0x8000000U)
#define ADC_AWORR2_AWOR_CH27_SHIFT               (27U)
/*! AWOR_CH27 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH27(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH27_SHIFT)) & ADC_AWORR2_AWOR_CH27_MASK)

#define ADC_AWORR2_AWOR_CH28_MASK                (0x10000000U)
#define ADC_AWORR2_AWOR_CH28_SHIFT               (28U)
/*! AWOR_CH28 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH28(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH28_SHIFT)) & ADC_AWORR2_AWOR_CH28_MASK)

#define ADC_AWORR2_AWOR_CH29_MASK                (0x20000000U)
#define ADC_AWORR2_AWOR_CH29_SHIFT               (29U)
/*! AWOR_CH29 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH29(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH29_SHIFT)) & ADC_AWORR2_AWOR_CH29_MASK)

#define ADC_AWORR2_AWOR_CH30_MASK                (0x40000000U)
#define ADC_AWORR2_AWOR_CH30_SHIFT               (30U)
/*! AWOR_CH30 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH30(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH30_SHIFT)) & ADC_AWORR2_AWOR_CH30_MASK)

#define ADC_AWORR2_AWOR_CH31_MASK                (0x80000000U)
#define ADC_AWORR2_AWOR_CH31_SHIFT               (31U)
/*! AWOR_CH31 - Analog Watchdog Out Of Range For External Inputs
 *  0b0..Conversion is within limits
 *  0b0..No effect
 *  0b1..Clears flag
 *  0b1..Conversion is not within limits
 */
#define ADC_AWORR2_AWOR_CH31(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_AWORR2_AWOR_CH31_SHIFT)) & ADC_AWORR2_AWOR_CH31_MASK)
/*! @} */

/*! @name STCR1 - Self-Test Configuration 1 */
/*! @{ */

#define ADC_STCR1_INPSAMP_S_MASK                 (0xFF00U)
#define ADC_STCR1_INPSAMP_S_SHIFT                (8U)
/*! INPSAMP_S - Input Sampling Time Algorithm S */
#define ADC_STCR1_INPSAMP_S(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR1_INPSAMP_S_SHIFT)) & ADC_STCR1_INPSAMP_S_MASK)

#define ADC_STCR1_INPSAMP_C_MASK                 (0xFF000000U)
#define ADC_STCR1_INPSAMP_C_SHIFT                (24U)
/*! INPSAMP_C - Input Sampling Time Algorithm C */
#define ADC_STCR1_INPSAMP_C(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR1_INPSAMP_C_SHIFT)) & ADC_STCR1_INPSAMP_C_MASK)
/*! @} */

/*! @name STCR2 - Self-Test Configuration 2 */
/*! @{ */

#define ADC_STCR2_FMA_S_MASK                     (0x1U)
#define ADC_STCR2_FMA_S_SHIFT                    (0U)
/*! FMA_S - Fault Mapping Algorithm S
 *  0b0..Noncritical fault line
 *  0b1..Critical fault line
 */
#define ADC_STCR2_FMA_S(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_FMA_S_SHIFT)) & ADC_STCR2_FMA_S_MASK)

#define ADC_STCR2_FMA_C_MASK                     (0x4U)
#define ADC_STCR2_FMA_C_SHIFT                    (2U)
/*! FMA_C - Fault Mapping Algorithm C
 *  0b0..Noncritical fault line
 *  0b1..Critical fault line
 */
#define ADC_STCR2_FMA_C(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_FMA_C_SHIFT)) & ADC_STCR2_FMA_C_MASK)

#define ADC_STCR2_FMA_WDTERR_MASK                (0x8U)
#define ADC_STCR2_FMA_WDTERR_SHIFT               (3U)
/*! FMA_WDTERR - Fault Mapping Self-Test Watchdog Timer Error
 *  0b0..Noncritical fault line
 *  0b1..Critical fault line
 */
#define ADC_STCR2_FMA_WDTERR(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_FMA_WDTERR_SHIFT)) & ADC_STCR2_FMA_WDTERR_MASK)

#define ADC_STCR2_FMA_WDSERR_MASK                (0x10U)
#define ADC_STCR2_FMA_WDSERR_SHIFT               (4U)
/*! FMA_WDSERR - Fault Mapping Self-Test Watchdog Sequence Error
 *  0b0..Noncritical fault line
 *  0b1..Critical fault line
 */
#define ADC_STCR2_FMA_WDSERR(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_FMA_WDSERR_SHIFT)) & ADC_STCR2_FMA_WDSERR_MASK)

#define ADC_STCR2_EN_MASK                        (0x80U)
#define ADC_STCR2_EN_SHIFT                       (7U)
/*! EN - Self-Test Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_STCR2_EN(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_EN_SHIFT)) & ADC_STCR2_EN_MASK)

#define ADC_STCR2_MSKERR_S0_MASK                 (0x800U)
#define ADC_STCR2_MSKERR_S0_SHIFT                (11U)
/*! MSKERR_S0 - Mask Error Interrupt Algorithm S0
 *  0b0..No interrupt is generated
 *  0b1..Interrupt is generated
 */
#define ADC_STCR2_MSKERR_S0(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKERR_S0_SHIFT)) & ADC_STCR2_MSKERR_S0_MASK)

#define ADC_STCR2_MSKERR_S1_MASK                 (0x1000U)
#define ADC_STCR2_MSKERR_S1_SHIFT                (12U)
/*! MSKERR_S1 - Mask Error Interrupt Algorithm S1
 *  0b0..No interrupt is generated
 *  0b1..Interrupt is generated
 */
#define ADC_STCR2_MSKERR_S1(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKERR_S1_SHIFT)) & ADC_STCR2_MSKERR_S1_MASK)

#define ADC_STCR2_MSKERR_S2_MASK                 (0x2000U)
#define ADC_STCR2_MSKERR_S2_SHIFT                (13U)
/*! MSKERR_S2 - Mask Error Interrupt Algorithm S2
 *  0b0..No interrupt is generated
 *  0b1..Interrupt is generated
 */
#define ADC_STCR2_MSKERR_S2(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKERR_S2_SHIFT)) & ADC_STCR2_MSKERR_S2_MASK)

#define ADC_STCR2_MSKERR_C_MASK                  (0x8000U)
#define ADC_STCR2_MSKERR_C_SHIFT                 (15U)
/*! MSKERR_C - Mask Error Interrupt Algorithm C
 *  0b0..No interrupt is generated
 *  0b1..Interrupt is generated
 */
#define ADC_STCR2_MSKERR_C(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKERR_C_SHIFT)) & ADC_STCR2_MSKERR_C_MASK)

#define ADC_STCR2_MSKWDG_EOA_S_MASK              (0x10000U)
#define ADC_STCR2_MSKWDG_EOA_S_SHIFT             (16U)
/*! MSKWDG_EOA_S - Mask Error Interrupt End Of Algorithm S
 *  0b0..No interrupt is generated
 *  0b1..Interrupt is generated
 */
#define ADC_STCR2_MSKWDG_EOA_S(x)                (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKWDG_EOA_S_SHIFT)) & ADC_STCR2_MSKWDG_EOA_S_MASK)

#define ADC_STCR2_MSKWDG_EOA_C_MASK              (0x40000U)
#define ADC_STCR2_MSKWDG_EOA_C_SHIFT             (18U)
/*! MSKWDG_EOA_C - Mask Error Interrupt End Of Algorithm C
 *  0b0..No interrupt is generated
 *  0b1..Interrupt is generated
 */
#define ADC_STCR2_MSKWDG_EOA_C(x)                (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKWDG_EOA_C_SHIFT)) & ADC_STCR2_MSKWDG_EOA_C_MASK)

#define ADC_STCR2_MSKST_EOC_MASK                 (0x800000U)
#define ADC_STCR2_MSKST_EOC_SHIFT                (23U)
/*! MSKST_EOC - Mask Interrupt Self-Test End Of Conversion
 *  0b0..No interrupt is generated
 *  0b1..Interrupt is generated
 */
#define ADC_STCR2_MSKST_EOC(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKST_EOC_SHIFT)) & ADC_STCR2_MSKST_EOC_MASK)

#define ADC_STCR2_MSKWDTERR_MASK                 (0x2000000U)
#define ADC_STCR2_MSKWDTERR_SHIFT                (25U)
/*! MSKWDTERR - Mask Interrupt Self-Test Watchdog Timer Error
 *  0b0..No interrupt is generated
 *  0b1..Interrupt is generated
 */
#define ADC_STCR2_MSKWDTERR(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKWDTERR_SHIFT)) & ADC_STCR2_MSKWDTERR_MASK)

#define ADC_STCR2_SERR_MASK                      (0x4000000U)
#define ADC_STCR2_SERR_SHIFT                     (26U)
/*! SERR - Self-Test Error Injection
 *  0b0..Error can be injected
 *  0b0..No effect
 *  0b1..Error is being injected
 *  0b1..Injects a self-test error
 */
#define ADC_STCR2_SERR(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_SERR_SHIFT)) & ADC_STCR2_SERR_MASK)

#define ADC_STCR2_MSKWDSERR_MASK                 (0x8000000U)
#define ADC_STCR2_MSKWDSERR_SHIFT                (27U)
/*! MSKWDSERR - Mask Interrupt Self-Test Watchdog Sequence Error
 *  0b0..No interrupt is generated
 *  0b1..Interrupt is generated
 */
#define ADC_STCR2_MSKWDSERR(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STCR2_MSKWDSERR_SHIFT)) & ADC_STCR2_MSKWDSERR_MASK)
/*! @} */

/*! @name STCR3 - Self-Test Configuration 3 */
/*! @{ */

#define ADC_STCR3_MSTEP_MASK                     (0x1FU)
#define ADC_STCR3_MSTEP_SHIFT                    (0U)
/*! MSTEP - Algorithm Step */
#define ADC_STCR3_MSTEP(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STCR3_MSTEP_SHIFT)) & ADC_STCR3_MSTEP_MASK)

#define ADC_STCR3_ALG_MASK                       (0x300U)
#define ADC_STCR3_ALG_SHIFT                      (8U)
/*! ALG - Algorithm Selection */
#define ADC_STCR3_ALG(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_STCR3_ALG_SHIFT)) & ADC_STCR3_ALG_MASK)
/*! @} */

/*! @name STBRR - Self-Test Baud Rate */
/*! @{ */

#define ADC_STBRR_BR_MASK                        (0xFFU)
#define ADC_STBRR_BR_SHIFT                       (0U)
/*! BR - Baud Rate
 *  0b00000000..A step of the selected self-test algorithm is executed every time after the set of selected inputs has been converted.
 *  0b11111111..A step of the selected self-test algorithm is executed after the set of selected inputs has been converted 256 times.
 */
#define ADC_STBRR_BR(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_STBRR_BR_SHIFT)) & ADC_STBRR_BR_MASK)

#define ADC_STBRR_WDT_MASK                       (0x70000U)
#define ADC_STBRR_WDT_SHIFT                      (16U)
/*! WDT - Self-Test Watchdog Timer
 *  0b000..8192 conversion clock cycles (~0.1 ms at 80 MHz)
 *  0b001..39,936 conversion clock cycles (~0.5 ms at 80 MHz)
 *  0b010..79,872 conversion clock cycles (~1 ms at 80 MHz)
 *  0b011..159,744 conversion clock cycles (~2 ms at 80 MHz)
 *  0b100..400,384 conversion clock cycles (~5 ms at 80 MHz)
 *  0b101..799,744 conversion clock cycles (~10 ms at 80 MHz)
 *  0b110..‭1,599,488‬ conversion clock cycles (~20 ms at 80 MHz)
 *  0b111..‭3,999,744‬‬ conversion clock cycles (~50 ms at 80 MHz)
 */
#define ADC_STBRR_WDT(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_STBRR_WDT_SHIFT)) & ADC_STBRR_WDT_MASK)
/*! @} */

/*! @name STSR1 - Self-Test Status 1 */
/*! @{ */

#define ADC_STSR1_STEP_C_MASK                    (0x3E0U)
#define ADC_STSR1_STEP_C_SHIFT                   (5U)
/*! STEP_C - Step Of Algorithm C */
#define ADC_STSR1_STEP_C(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_STEP_C_SHIFT)) & ADC_STSR1_STEP_C_MASK)

#define ADC_STSR1_ERR_S0_MASK                    (0x800U)
#define ADC_STSR1_ERR_S0_SHIFT                   (11U)
/*! ERR_S0 - Error Algorithm S Step 0
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clears flag
 *  0b1..Error
 */
#define ADC_STSR1_ERR_S0(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_ERR_S0_SHIFT)) & ADC_STSR1_ERR_S0_MASK)

#define ADC_STSR1_ERR_S1_MASK                    (0x1000U)
#define ADC_STSR1_ERR_S1_SHIFT                   (12U)
/*! ERR_S1 - Error Algorithm S Step 1
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clears flag
 *  0b1..Error
 */
#define ADC_STSR1_ERR_S1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_ERR_S1_SHIFT)) & ADC_STSR1_ERR_S1_MASK)

#define ADC_STSR1_ERR_S2_MASK                    (0x2000U)
#define ADC_STSR1_ERR_S2_SHIFT                   (13U)
/*! ERR_S2 - Error Algorithm S Step 2
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clears flag
 *  0b1..Error
 */
#define ADC_STSR1_ERR_S2(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_ERR_S2_SHIFT)) & ADC_STSR1_ERR_S2_MASK)

#define ADC_STSR1_ERR_C_MASK                     (0x8000U)
#define ADC_STSR1_ERR_C_SHIFT                    (15U)
/*! ERR_C - Error Algorithm C
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clears flag
 *  0b1..Error
 */
#define ADC_STSR1_ERR_C(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_ERR_C_SHIFT)) & ADC_STSR1_ERR_C_MASK)

#define ADC_STSR1_WDG_EOA_S_MASK                 (0x10000U)
#define ADC_STSR1_WDG_EOA_S_SHIFT                (16U)
/*! WDG_EOA_S - Self-Test Watchdog End Of Algorithm S
 *  0b0..No effect
 *  0b0..Not complete
 *  0b1..Clears flag
 *  0b1..Complete
 */
#define ADC_STSR1_WDG_EOA_S(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_WDG_EOA_S_SHIFT)) & ADC_STSR1_WDG_EOA_S_MASK)

#define ADC_STSR1_WDG_EOA_C_MASK                 (0x40000U)
#define ADC_STSR1_WDG_EOA_C_SHIFT                (18U)
/*! WDG_EOA_C - Self-Test Watchdog End Of Algorithm C
 *  0b0..No effect
 *  0b0..Not complete
 *  0b1..Clears flag
 *  0b1..Complete
 */
#define ADC_STSR1_WDG_EOA_C(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_WDG_EOA_C_SHIFT)) & ADC_STSR1_WDG_EOA_C_MASK)

#define ADC_STSR1_ST_EOC_MASK                    (0x800000U)
#define ADC_STSR1_ST_EOC_SHIFT                   (23U)
/*! ST_EOC - Self-Test End Of Conversion
 *  0b0..No effect
 *  0b0..Not complete
 *  0b1..Clears flag
 *  0b1..Complete
 */
#define ADC_STSR1_ST_EOC(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_ST_EOC_SHIFT)) & ADC_STSR1_ST_EOC_MASK)

#define ADC_STSR1_OVERWR_MASK                    (0x1000000U)
#define ADC_STSR1_OVERWR_SHIFT                   (24U)
/*! OVERWR - Self-Test Error Status Overwrite
 *  0b0..No effect
 *  0b0..No self-test error status flag overwritten
 *  0b1..Clears flag
 *  0b1..Self-test error status flag overwritten
 */
#define ADC_STSR1_OVERWR(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_OVERWR_SHIFT)) & ADC_STSR1_OVERWR_MASK)

#define ADC_STSR1_WDTERR_MASK                    (0x2000000U)
#define ADC_STSR1_WDTERR_SHIFT                   (25U)
/*! WDTERR - Self-Test Watchdog Timer Error
 *  0b0..Algorithm finished within the safe time period (or safe time period not yet elapsed).
 *  0b0..No effect
 *  0b1..Algorithm did not finish within safe time period.
 *  0b1..Clears flag
 */
#define ADC_STSR1_WDTERR(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_WDTERR_SHIFT)) & ADC_STSR1_WDTERR_MASK)

#define ADC_STSR1_WDSERR_MASK                    (0x8000000U)
#define ADC_STSR1_WDSERR_SHIFT                   (27U)
/*! WDSERR - Self-Test Watchdog Sequence Error
 *  0b0..Algorithm executed in correct sequence
 *  0b0..No effect
 *  0b1..Algorithm did not execute in correct sequence
 *  0b1..Clears flag
 */
#define ADC_STSR1_WDSERR(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STSR1_WDSERR_SHIFT)) & ADC_STSR1_WDSERR_MASK)
/*! @} */

/*! @name STSR2 - Self-Test Status 2 */
/*! @{ */

#define ADC_STSR2_DATA0_MASK                     (0x7FFFU)
#define ADC_STSR2_DATA0_SHIFT                    (0U)
/*! DATA0 - Conversion Data ERR_S1 */
#define ADC_STSR2_DATA0(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STSR2_DATA0_SHIFT)) & ADC_STSR2_DATA0_MASK)
/*! @} */

/*! @name STSR3 - Self-Test Status 3 */
/*! @{ */

#define ADC_STSR3_DATA0_MASK                     (0x7FFFU)
#define ADC_STSR3_DATA0_SHIFT                    (0U)
/*! DATA0 - Conversion Data ERR_S0 */
#define ADC_STSR3_DATA0(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STSR3_DATA0_SHIFT)) & ADC_STSR3_DATA0_MASK)

#define ADC_STSR3_DATA1_MASK                     (0x7FFF0000U)
#define ADC_STSR3_DATA1_SHIFT                    (16U)
/*! DATA1 - Conversion Data ERR_S2 */
#define ADC_STSR3_DATA1(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STSR3_DATA1_SHIFT)) & ADC_STSR3_DATA1_MASK)
/*! @} */

/*! @name STSR4 - Self-Test Status 4 */
/*! @{ */

#define ADC_STSR4_DATA1_MASK                     (0x7FFF0000U)
#define ADC_STSR4_DATA1_SHIFT                    (16U)
/*! DATA1 - Conversion Data ERR_C */
#define ADC_STSR4_DATA1(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STSR4_DATA1_SHIFT)) & ADC_STSR4_DATA1_MASK)
/*! @} */

/*! @name STDR1 - Self-Test Conversion Data 1 */
/*! @{ */

#define ADC_STDR1_TCDATA_MASK                    (0x7FFFU)
#define ADC_STDR1_TCDATA_SHIFT                   (0U)
/*! TCDATA - Test Channel Conversion Data */
#define ADC_STDR1_TCDATA(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STDR1_TCDATA_SHIFT)) & ADC_STDR1_TCDATA_MASK)

#define ADC_STDR1_OWERWR_MASK                    (0x40000U)
#define ADC_STDR1_OWERWR_SHIFT                   (18U)
/*! OWERWR - Conversion Data Overwrite Status
 *  0b0..Current conversion data not overwritten
 *  0b1..Current conversion data was overwritten
 */
#define ADC_STDR1_OWERWR(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_STDR1_OWERWR_SHIFT)) & ADC_STDR1_OWERWR_MASK)

#define ADC_STDR1_VALID_MASK                     (0x80000U)
#define ADC_STDR1_VALID_SHIFT                    (19U)
/*! VALID - Valid Conversion Data
 *  0b0..No unread conversion data
 *  0b1..Unread conversion data is available
 */
#define ADC_STDR1_VALID(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STDR1_VALID_SHIFT)) & ADC_STDR1_VALID_MASK)
/*! @} */

/*! @name STAW0R - Self-Test Analog Watchdog S0 */
/*! @{ */

#define ADC_STAW0R_THRL_MASK                     (0x7FFFU)
#define ADC_STAW0R_THRL_SHIFT                    (0U)
/*! THRL - Lower Threshold Value */
#define ADC_STAW0R_THRL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW0R_THRL_SHIFT)) & ADC_STAW0R_THRL_MASK)

#define ADC_STAW0R_THRH_MASK                     (0x3FFF0000U)
#define ADC_STAW0R_THRH_SHIFT                    (16U)
/*! THRH - Higher Threshold Value */
#define ADC_STAW0R_THRH(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW0R_THRH_SHIFT)) & ADC_STAW0R_THRH_MASK)

#define ADC_STAW0R_WDTE_MASK                     (0x40000000U)
#define ADC_STAW0R_WDTE_SHIFT                    (30U)
/*! WDTE - Self-Test Watchdog Timer Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_STAW0R_WDTE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW0R_WDTE_SHIFT)) & ADC_STAW0R_WDTE_MASK)

#define ADC_STAW0R_AWDE_MASK                     (0x80000000U)
#define ADC_STAW0R_AWDE_SHIFT                    (31U)
/*! AWDE - Self-Test Watchdog Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_STAW0R_AWDE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW0R_AWDE_SHIFT)) & ADC_STAW0R_AWDE_MASK)
/*! @} */

/*! @name STAW1R - Self-Test Analog Watchdog S1 */
/*! @{ */

#define ADC_STAW1R_THRL_MASK                     (0x7FFFU)
#define ADC_STAW1R_THRL_SHIFT                    (0U)
/*! THRL - Lower Threshold Value */
#define ADC_STAW1R_THRL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW1R_THRL_SHIFT)) & ADC_STAW1R_THRL_MASK)

#define ADC_STAW1R_AWDE_MASK                     (0x80000000U)
#define ADC_STAW1R_AWDE_SHIFT                    (31U)
/*! AWDE - Self-Test Watchdog Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_STAW1R_AWDE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW1R_AWDE_SHIFT)) & ADC_STAW1R_AWDE_MASK)
/*! @} */

/*! @name STAW2R - Self-Test Analog Watchdog S2 */
/*! @{ */

#define ADC_STAW2R_THRL_MASK                     (0x7FFFU)
#define ADC_STAW2R_THRL_SHIFT                    (0U)
/*! THRL - Lower Threshold Value */
#define ADC_STAW2R_THRL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW2R_THRL_SHIFT)) & ADC_STAW2R_THRL_MASK)

#define ADC_STAW2R_AWDE_MASK                     (0x80000000U)
#define ADC_STAW2R_AWDE_SHIFT                    (31U)
/*! AWDE - Self-Test Watchdog Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_STAW2R_AWDE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW2R_AWDE_SHIFT)) & ADC_STAW2R_AWDE_MASK)
/*! @} */

/*! @name STAW4R - Self-Test Analog Watchdog C0 */
/*! @{ */

#define ADC_STAW4R_THRL_MASK                     (0x7FFFU)
#define ADC_STAW4R_THRL_SHIFT                    (0U)
/*! THRL - Lower Threshold Value */
#define ADC_STAW4R_THRL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW4R_THRL_SHIFT)) & ADC_STAW4R_THRL_MASK)

#define ADC_STAW4R_THRH_MASK                     (0x3FFF0000U)
#define ADC_STAW4R_THRH_SHIFT                    (16U)
/*! THRH - Higher Threshold Value */
#define ADC_STAW4R_THRH(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW4R_THRH_SHIFT)) & ADC_STAW4R_THRH_MASK)

#define ADC_STAW4R_WDTE_MASK                     (0x40000000U)
#define ADC_STAW4R_WDTE_SHIFT                    (30U)
/*! WDTE - Self-Test Watchdog Timer Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_STAW4R_WDTE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW4R_WDTE_SHIFT)) & ADC_STAW4R_WDTE_MASK)

#define ADC_STAW4R_AWDE_MASK                     (0x80000000U)
#define ADC_STAW4R_AWDE_SHIFT                    (31U)
/*! AWDE - Self-Test Watchdog Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_STAW4R_AWDE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW4R_AWDE_SHIFT)) & ADC_STAW4R_AWDE_MASK)
/*! @} */

/*! @name STAW5R - Self-Test Analog Watchdog C */
/*! @{ */

#define ADC_STAW5R_THRL_MASK                     (0x7FFFU)
#define ADC_STAW5R_THRL_SHIFT                    (0U)
/*! THRL - Lower Threshold Value */
#define ADC_STAW5R_THRL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW5R_THRL_SHIFT)) & ADC_STAW5R_THRL_MASK)

#define ADC_STAW5R_THRH_MASK                     (0x7FFF0000U)
#define ADC_STAW5R_THRH_SHIFT                    (16U)
/*! THRH - Higher Threshold Value */
#define ADC_STAW5R_THRH(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAW5R_THRH_SHIFT)) & ADC_STAW5R_THRH_MASK)
/*! @} */

/*! @name AMSIO - Analog Miscellaneous In/Out register */
/*! @{ */

#define ADC_AMSIO_HSEN_MASK                      (0x60000U)
#define ADC_AMSIO_HSEN_SHIFT                     (17U)
/*! HSEN - High-Speed Enable
 *  0b00..Normal conversion speed
 *  0b11..High-speed conversion
 *  *..reserved
 */
#define ADC_AMSIO_HSEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_AMSIO_HSEN_SHIFT)) & ADC_AMSIO_HSEN_MASK)
/*! @} */

/*! @name CALBISTREG - Control And Calibration Status */
/*! @{ */

#define ADC_CALBISTREG_TEST_EN_MASK              (0x1U)
#define ADC_CALBISTREG_TEST_EN_SHIFT             (0U)
/*! TEST_EN - Calibration Enable
 *  0b0..Wait to start a calibration
 *  0b1..Start calibration
 */
#define ADC_CALBISTREG_TEST_EN(x)                (((uint32_t)(((uint32_t)(x)) << ADC_CALBISTREG_TEST_EN_SHIFT)) & ADC_CALBISTREG_TEST_EN_MASK)

#define ADC_CALBISTREG_TEST_FAIL_MASK            (0x8U)
#define ADC_CALBISTREG_TEST_FAIL_SHIFT           (3U)
/*! TEST_FAIL - Calibration Status
 *  0b0..Calibration finished successfully or has not been run since the last reset
 *  0b0..No effect
 *  0b1..Calibration did not finish successfully
 *  0b1..Clears flag
 */
#define ADC_CALBISTREG_TEST_FAIL(x)              (((uint32_t)(((uint32_t)(x)) << ADC_CALBISTREG_TEST_FAIL_SHIFT)) & ADC_CALBISTREG_TEST_FAIL_MASK)

#define ADC_CALBISTREG_AVG_EN_MASK               (0x10U)
#define ADC_CALBISTREG_AVG_EN_SHIFT              (4U)
/*! AVG_EN - Calibration Averaging Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CALBISTREG_AVG_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_CALBISTREG_AVG_EN_SHIFT)) & ADC_CALBISTREG_AVG_EN_MASK)

#define ADC_CALBISTREG_NR_SMPL_MASK              (0x60U)
#define ADC_CALBISTREG_NR_SMPL_SHIFT             (5U)
/*! NR_SMPL - Calibration Averaging Number
 *  0b00..4 samples
 *  0b01..8 samples
 *  0b10..16 samples
 *  0b11..32 samples
 */
#define ADC_CALBISTREG_NR_SMPL(x)                (((uint32_t)(((uint32_t)(x)) << ADC_CALBISTREG_NR_SMPL_SHIFT)) & ADC_CALBISTREG_NR_SMPL_MASK)

#define ADC_CALBISTREG_CALSTFUL_MASK             (0x4000U)
#define ADC_CALBISTREG_CALSTFUL_SHIFT            (14U)
/*! CALSTFUL - Calibration And Self-Test Full Range Comparison
 *  0b0..Lowest 11 bits are compared.
 *  0b1..All 15 bits are compared.
 */
#define ADC_CALBISTREG_CALSTFUL(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CALBISTREG_CALSTFUL_SHIFT)) & ADC_CALBISTREG_CALSTFUL_MASK)

#define ADC_CALBISTREG_C_T_BUSY_MASK             (0x8000U)
#define ADC_CALBISTREG_C_T_BUSY_SHIFT            (15U)
/*! C_T_BUSY - Calibration Busy
 *  0b0..Calibration can be started
 *  0b1..Calibration is in progress
 */
#define ADC_CALBISTREG_C_T_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << ADC_CALBISTREG_C_T_BUSY_SHIFT)) & ADC_CALBISTREG_C_T_BUSY_MASK)

#define ADC_CALBISTREG_TSAMP_MASK                (0x18000000U)
#define ADC_CALBISTREG_TSAMP_SHIFT               (27U)
/*! TSAMP - Sample Period In Calibration
 *  0b00..22 conversion clock cycles
 *  0b01..8 conversion clock cycles
 *  0b10..16 conversion clock cycles
 *  0b11..32 conversion clock cycles
 */
#define ADC_CALBISTREG_TSAMP(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_CALBISTREG_TSAMP_SHIFT)) & ADC_CALBISTREG_TSAMP_MASK)

#define ADC_CALBISTREG_RESN_MASK                 (0xE0000000U)
#define ADC_CALBISTREG_RESN_SHIFT                (29U)
/*! RESN - Conversion Resolution
 *  0b000..14-bit resolution
 *  0b001..12-bit resolution
 *  0b010..10-bit resolution
 *  0b011..8-bit resolution
 */
#define ADC_CALBISTREG_RESN(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_CALBISTREG_RESN_SHIFT)) & ADC_CALBISTREG_RESN_MASK)
/*! @} */

/*! @name OFSGNUSR - Offset And Gain User */
/*! @{ */

#define ADC_OFSGNUSR_OFFSET_USER_MASK            (0xFFU)
#define ADC_OFSGNUSR_OFFSET_USER_SHIFT           (0U)
/*! OFFSET_USER - Offset User */
#define ADC_OFSGNUSR_OFFSET_USER(x)              (((uint32_t)(((uint32_t)(x)) << ADC_OFSGNUSR_OFFSET_USER_SHIFT)) & ADC_OFSGNUSR_OFFSET_USER_MASK)

#define ADC_OFSGNUSR_GAIN_USER_MASK              (0x3FF0000U)
#define ADC_OFSGNUSR_GAIN_USER_SHIFT             (16U)
/*! GAIN_USER - Gain User */
#define ADC_OFSGNUSR_GAIN_USER(x)                (((uint32_t)(((uint32_t)(x)) << ADC_OFSGNUSR_GAIN_USER_SHIFT)) & ADC_OFSGNUSR_GAIN_USER_MASK)
/*! @} */

/*! @name CAL2 - Calibration Value 2 */
/*! @{ */

#define ADC_CAL2_ENX_MASK                        (0x8000U)
#define ADC_CAL2_ENX_SHIFT                       (15U)
/*! ENX - Enable X
 *  0b0..Disable
 *  0b1..Enable
 */
#define ADC_CAL2_ENX(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_CAL2_ENX_SHIFT)) & ADC_CAL2_ENX_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


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


#endif  /* PERI_ADC_H_ */

