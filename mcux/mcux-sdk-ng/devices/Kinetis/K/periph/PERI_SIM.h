/*
** ###################################################################
**     Processors:          MK02FN128VFM10
**                          MK02FN128VLF10
**                          MK02FN128VLH10
**                          MK02FN64VFM10
**                          MK02FN64VLF10
**                          MK02FN64VLH10
**
**     Version:             rev. 0.5, 2015-02-19
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2014-02-24)
**         Initial version
**     - rev. 0.2 (2014-07-15)
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**         Update of system and startup files.
**     - rev. 0.3 (2014-08-28)
**         Update of system files - default clock configuration changed.
**         Update of startup files - possibility to override DefaultISR added.
**     - rev. 0.4 (2014-10-14)
**         Interrupt INT_LPTimer renamed to INT_LPTMR0, interrupt INT_Watchdog renamed to INT_WDOG_EWM.
**     - rev. 0.5 (2015-02-19)
**         Renamed interrupt vector LLW to LLWU.
**
** ###################################################################
*/

/*!
 * @file SIM.h
 * @version 0.5
 * @date 2015-02-19
 * @brief CMSIS Peripheral Access Layer for SIM
 *
 * CMSIS Peripheral Access Layer for SIM
 */

#if !defined(SIM_H_)
#define SIM_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MK02FN128VFM10) || defined(CPU_MK02FN128VLF10) || defined(CPU_MK02FN128VLH10) || defined(CPU_MK02FN64VFM10) || defined(CPU_MK02FN64VLF10) || defined(CPU_MK02FN64VLH10))
#include "MK02F12810_COMMON.h"
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
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SOPT1;                             /**< System Options Register 1, offset: 0x0 */
       uint32_t SOPT1CFG;                          /**< SOPT1 Configuration Register, offset: 0x4 */
       uint8_t RESERVED_0[4092];
  __IO uint32_t SOPT2;                             /**< System Options Register 2, offset: 0x1004 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SOPT4;                             /**< System Options Register 4, offset: 0x100C */
  __IO uint32_t SOPT5;                             /**< System Options Register 5, offset: 0x1010 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SOPT7;                             /**< System Options Register 7, offset: 0x1018 */
  __IO uint32_t SOPT8;                             /**< System Options Register 8, offset: 0x101C */
       uint8_t RESERVED_3[4];
  __I  uint32_t SDID;                              /**< System Device Identification Register, offset: 0x1024 */
       uint8_t RESERVED_4[12];
  __IO uint32_t SCGC4;                             /**< System Clock Gating Control Register 4, offset: 0x1034 */
  __IO uint32_t SCGC5;                             /**< System Clock Gating Control Register 5, offset: 0x1038 */
  __IO uint32_t SCGC6;                             /**< System Clock Gating Control Register 6, offset: 0x103C */
  __IO uint32_t SCGC7;                             /**< System Clock Gating Control Register 7, offset: 0x1040 */
  __IO uint32_t CLKDIV1;                           /**< System Clock Divider Register 1, offset: 0x1044 */
       uint8_t RESERVED_5[4];
  __IO uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x104C */
  __I  uint32_t FCFG2;                             /**< Flash Configuration Register 2, offset: 0x1050 */
  __I  uint32_t UIDH;                              /**< Unique Identification Register High, offset: 0x1054 */
  __I  uint32_t UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x1058 */
  __I  uint32_t UIDML;                             /**< Unique Identification Register Mid Low, offset: 0x105C */
  __I  uint32_t UIDL;                              /**< Unique Identification Register Low, offset: 0x1060 */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/*! @name SOPT1 - System Options Register 1 */
/*! @{ */

#define SIM_SOPT1_RAMSIZE_MASK                   (0xF000U)
#define SIM_SOPT1_RAMSIZE_SHIFT                  (12U)
/*! RAMSIZE - RAM size
 *  0b0001..8 KB
 *  0b0011..16 KB
 *  0b0100..24 KB
 *  0b0101..32 KB
 *  0b0110..48 KB
 *  0b0111..64 KB
 *  0b1000..96 KB
 *  0b1001..128 KB
 *  0b1011..256 KB
 */
#define SIM_SOPT1_RAMSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_RAMSIZE_SHIFT)) & SIM_SOPT1_RAMSIZE_MASK)

#define SIM_SOPT1_OSC32KOUT_MASK                 (0x30000U)
#define SIM_SOPT1_OSC32KOUT_SHIFT                (16U)
/*! OSC32KOUT - 32K Oscillator Clock Output
 *  0b00..ERCLK32K is not output.
 *  0b01..ERCLK32K is output on PTE0.
 *  0b10..ERCLK32K is output on PTE26.
 *  0b11..Reserved.
 */
#define SIM_SOPT1_OSC32KOUT(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_OSC32KOUT_SHIFT)) & SIM_SOPT1_OSC32KOUT_MASK)

#define SIM_SOPT1_OSC32KSEL_MASK                 (0xC0000U)
#define SIM_SOPT1_OSC32KSEL_SHIFT                (18U)
/*! OSC32KSEL - 32K oscillator clock select
 *  0b00..System oscillator (OSC32KCLK)
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..LPO 1 kHz
 */
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_OSC32KSEL_SHIFT)) & SIM_SOPT1_OSC32KSEL_MASK)
/*! @} */

/*! @name SOPT2 - System Options Register 2 */
/*! @{ */

#define SIM_SOPT2_CLKOUTSEL_MASK                 (0xE0U)
#define SIM_SOPT2_CLKOUTSEL_SHIFT                (5U)
/*! CLKOUTSEL - CLKOUT select
 *  0b000..Reserved
 *  0b001..Reserved
 *  0b010..Flash clock
 *  0b011..LPO clock (1 kHz)
 *  0b100..MCGIRCLK
 *  0b101..Reserved
 *  0b110..OSCERCLK0
 *  0b111..IRC 48 MHz clock
 */
#define SIM_SOPT2_CLKOUTSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_CLKOUTSEL_SHIFT)) & SIM_SOPT2_CLKOUTSEL_MASK)

#define SIM_SOPT2_TRACECLKSEL_MASK               (0x1000U)
#define SIM_SOPT2_TRACECLKSEL_SHIFT              (12U)
/*! TRACECLKSEL - Debug trace clock select
 *  0b0..MCGOUTCLK
 *  0b1..Core/system clock
 */
#define SIM_SOPT2_TRACECLKSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_TRACECLKSEL_SHIFT)) & SIM_SOPT2_TRACECLKSEL_MASK)

#define SIM_SOPT2_PLLFLLSEL_MASK                 (0x30000U)
#define SIM_SOPT2_PLLFLLSEL_SHIFT                (16U)
/*! PLLFLLSEL - PLL/FLL clock select
 *  0b00..MCGFLLCLK clock
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..IRC48 MHz clock
 */
#define SIM_SOPT2_PLLFLLSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_PLLFLLSEL_SHIFT)) & SIM_SOPT2_PLLFLLSEL_MASK)
/*! @} */

/*! @name SOPT4 - System Options Register 4 */
/*! @{ */

#define SIM_SOPT4_FTM0FLT0_MASK                  (0x1U)
#define SIM_SOPT4_FTM0FLT0_SHIFT                 (0U)
/*! FTM0FLT0 - FTM0 Fault 0 Select
 *  0b0..FTM0_FLT0 pin
 *  0b1..CMP0 out
 */
#define SIM_SOPT4_FTM0FLT0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM0FLT0_SHIFT)) & SIM_SOPT4_FTM0FLT0_MASK)

#define SIM_SOPT4_FTM0FLT1_MASK                  (0x2U)
#define SIM_SOPT4_FTM0FLT1_SHIFT                 (1U)
/*! FTM0FLT1 - FTM0 Fault 1 Select
 *  0b0..FTM0_FLT1 pin
 *  0b1..CMP1 out
 */
#define SIM_SOPT4_FTM0FLT1(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM0FLT1_SHIFT)) & SIM_SOPT4_FTM0FLT1_MASK)

#define SIM_SOPT4_FTM1FLT0_MASK                  (0x10U)
#define SIM_SOPT4_FTM1FLT0_SHIFT                 (4U)
/*! FTM1FLT0 - FTM1 Fault 0 Select
 *  0b0..FTM1_FLT0 pin
 *  0b1..CMP0 out
 */
#define SIM_SOPT4_FTM1FLT0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM1FLT0_SHIFT)) & SIM_SOPT4_FTM1FLT0_MASK)

#define SIM_SOPT4_FTM2FLT0_MASK                  (0x100U)
#define SIM_SOPT4_FTM2FLT0_SHIFT                 (8U)
/*! FTM2FLT0 - FTM2 Fault 0 Select
 *  0b0..FTM2_FLT0 pin
 *  0b1..CMP0 out
 */
#define SIM_SOPT4_FTM2FLT0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM2FLT0_SHIFT)) & SIM_SOPT4_FTM2FLT0_MASK)

#define SIM_SOPT4_FTM1CH0SRC_MASK                (0xC0000U)
#define SIM_SOPT4_FTM1CH0SRC_SHIFT               (18U)
/*! FTM1CH0SRC - FTM1 channel 0 input capture source select
 *  0b00..FTM1_CH0 signal
 *  0b01..CMP0 output
 *  0b10..CMP1 output
 *  0b11..Reserved
 */
#define SIM_SOPT4_FTM1CH0SRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM1CH0SRC_SHIFT)) & SIM_SOPT4_FTM1CH0SRC_MASK)

#define SIM_SOPT4_FTM2CH0SRC_MASK                (0x300000U)
#define SIM_SOPT4_FTM2CH0SRC_SHIFT               (20U)
/*! FTM2CH0SRC - FTM2 channel 0 input capture source select
 *  0b00..FTM2_CH0 signal
 *  0b01..CMP0 output
 *  0b10..CMP1 output
 *  0b11..Reserved
 */
#define SIM_SOPT4_FTM2CH0SRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM2CH0SRC_SHIFT)) & SIM_SOPT4_FTM2CH0SRC_MASK)

#define SIM_SOPT4_FTM2CH1SRC_MASK                (0x400000U)
#define SIM_SOPT4_FTM2CH1SRC_SHIFT               (22U)
/*! FTM2CH1SRC - FTM2 channel 1 input capture source select
 *  0b0..FTM2_CH1 signal
 *  0b1..Exclusive OR of FTM2_CH1, FTM2_CH0 and FTM1_CH1.
 */
#define SIM_SOPT4_FTM2CH1SRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM2CH1SRC_SHIFT)) & SIM_SOPT4_FTM2CH1SRC_MASK)

#define SIM_SOPT4_FTM0CLKSEL_MASK                (0x1000000U)
#define SIM_SOPT4_FTM0CLKSEL_SHIFT               (24U)
/*! FTM0CLKSEL - FlexTimer 0 External Clock Pin Select
 *  0b0..FTM_CLK0 pin
 *  0b1..FTM_CLK1 pin
 */
#define SIM_SOPT4_FTM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM0CLKSEL_SHIFT)) & SIM_SOPT4_FTM0CLKSEL_MASK)

#define SIM_SOPT4_FTM1CLKSEL_MASK                (0x2000000U)
#define SIM_SOPT4_FTM1CLKSEL_SHIFT               (25U)
/*! FTM1CLKSEL - FTM1 External Clock Pin Select
 *  0b0..FTM_CLK0 pin
 *  0b1..FTM_CLK1 pin
 */
#define SIM_SOPT4_FTM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM1CLKSEL_SHIFT)) & SIM_SOPT4_FTM1CLKSEL_MASK)

#define SIM_SOPT4_FTM2CLKSEL_MASK                (0x4000000U)
#define SIM_SOPT4_FTM2CLKSEL_SHIFT               (26U)
/*! FTM2CLKSEL - FlexTimer 2 External Clock Pin Select
 *  0b0..FTM2 external clock driven by FTM_CLK0 pin.
 *  0b1..FTM2 external clock driven by FTM_CLK1 pin.
 */
#define SIM_SOPT4_FTM2CLKSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM2CLKSEL_SHIFT)) & SIM_SOPT4_FTM2CLKSEL_MASK)

#define SIM_SOPT4_FTM0TRG0SRC_MASK               (0x10000000U)
#define SIM_SOPT4_FTM0TRG0SRC_SHIFT              (28U)
/*! FTM0TRG0SRC - FlexTimer 0 Hardware Trigger 0 Source Select
 *  0b0..HSCMP0 output drives FTM0 hardware trigger 0
 *  0b1..FTM1 channel match drives FTM0 hardware trigger 0
 */
#define SIM_SOPT4_FTM0TRG0SRC(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM0TRG0SRC_SHIFT)) & SIM_SOPT4_FTM0TRG0SRC_MASK)

#define SIM_SOPT4_FTM0TRG1SRC_MASK               (0x20000000U)
#define SIM_SOPT4_FTM0TRG1SRC_SHIFT              (29U)
/*! FTM0TRG1SRC - FlexTimer 0 Hardware Trigger 1 Source Select
 *  0b0..PDB output trigger 1 drives FTM0 hardware trigger 1
 *  0b1..FTM2 channel match drives FTM0 hardware trigger 1
 */
#define SIM_SOPT4_FTM0TRG1SRC(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT4_FTM0TRG1SRC_SHIFT)) & SIM_SOPT4_FTM0TRG1SRC_MASK)
/*! @} */

/*! @name SOPT5 - System Options Register 5 */
/*! @{ */

#define SIM_SOPT5_UART0TXSRC_MASK                (0x3U)
#define SIM_SOPT5_UART0TXSRC_SHIFT               (0U)
/*! UART0TXSRC - UART 0 transmit data source select
 *  0b00..UART0_TX pin
 *  0b01..UART0_TX pin modulated with FTM1 channel 0 output
 *  0b10..UART0_TX pin modulated with FTM2 channel 0 output
 *  0b11..Reserved
 */
#define SIM_SOPT5_UART0TXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART0TXSRC_SHIFT)) & SIM_SOPT5_UART0TXSRC_MASK)

#define SIM_SOPT5_UART0RXSRC_MASK                (0xCU)
#define SIM_SOPT5_UART0RXSRC_SHIFT               (2U)
/*! UART0RXSRC - UART 0 receive data source select
 *  0b00..UART0_RX pin
 *  0b01..CMP0
 *  0b10..CMP1
 *  0b11..Reserved
 */
#define SIM_SOPT5_UART0RXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART0RXSRC_SHIFT)) & SIM_SOPT5_UART0RXSRC_MASK)

#define SIM_SOPT5_UART1TXSRC_MASK                (0x30U)
#define SIM_SOPT5_UART1TXSRC_SHIFT               (4U)
/*! UART1TXSRC - UART 1 transmit data source select
 *  0b00..UART1_TX pin
 *  0b01..UART1_TX pin modulated with FTM1 channel 0 output
 *  0b10..UART1_TX pin modulated with FTM2 channel 0 output
 *  0b11..Reserved
 */
#define SIM_SOPT5_UART1TXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART1TXSRC_SHIFT)) & SIM_SOPT5_UART1TXSRC_MASK)

#define SIM_SOPT5_UART1RXSRC_MASK                (0xC0U)
#define SIM_SOPT5_UART1RXSRC_SHIFT               (6U)
/*! UART1RXSRC - UART 1 receive data source select
 *  0b00..UART1_RX pin
 *  0b01..CMP0
 *  0b10..CMP1
 *  0b11..Reserved
 */
#define SIM_SOPT5_UART1RXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART1RXSRC_SHIFT)) & SIM_SOPT5_UART1RXSRC_MASK)
/*! @} */

/*! @name SOPT7 - System Options Register 7 */
/*! @{ */

#define SIM_SOPT7_ADC0TRGSEL_MASK                (0xFU)
#define SIM_SOPT7_ADC0TRGSEL_SHIFT               (0U)
/*! ADC0TRGSEL - ADC0 trigger select
 *  0b0000..PDB external trigger pin input (PDB0_EXTRG)
 *  0b0001..High speed comparator 0 output
 *  0b0010..High speed comparator 1 output
 *  0b0011..Reserved
 *  0b0100..PIT trigger 0
 *  0b0101..PIT trigger 1
 *  0b0110..PIT trigger 2
 *  0b0111..PIT trigger 3
 *  0b1000..FTM0 trigger
 *  0b1001..FTM1 trigger
 *  0b1010..FTM2 trigger
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Low-power timer (LPTMR) trigger
 *  0b1111..Reserved
 */
#define SIM_SOPT7_ADC0TRGSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0TRGSEL_SHIFT)) & SIM_SOPT7_ADC0TRGSEL_MASK)

#define SIM_SOPT7_ADC0PRETRGSEL_MASK             (0x10U)
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT            (4U)
/*! ADC0PRETRGSEL - ADC0 pretrigger select
 *  0b0..Pre-trigger A
 *  0b1..Pre-trigger B
 */
#define SIM_SOPT7_ADC0PRETRGSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0PRETRGSEL_SHIFT)) & SIM_SOPT7_ADC0PRETRGSEL_MASK)

#define SIM_SOPT7_ADC0ALTTRGEN_MASK              (0x80U)
#define SIM_SOPT7_ADC0ALTTRGEN_SHIFT             (7U)
/*! ADC0ALTTRGEN - ADC0 alternate trigger enable
 *  0b0..PDB trigger selected for ADC0.
 *  0b1..Alternate trigger selected for ADC0.
 */
#define SIM_SOPT7_ADC0ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0ALTTRGEN_SHIFT)) & SIM_SOPT7_ADC0ALTTRGEN_MASK)
/*! @} */

/*! @name SOPT8 - System Options Register 8 */
/*! @{ */

#define SIM_SOPT8_FTM0SYNCBIT_MASK               (0x1U)
#define SIM_SOPT8_FTM0SYNCBIT_SHIFT              (0U)
/*! FTM0SYNCBIT - FTM0 Hardware Trigger 0 Software Synchronization
 *  0b0..No effect
 *  0b1..Write 1 to assert the TRIG0 input to FTM0, software must clear this bit to allow other trigger sources to assert.
 */
#define SIM_SOPT8_FTM0SYNCBIT(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT8_FTM0SYNCBIT_SHIFT)) & SIM_SOPT8_FTM0SYNCBIT_MASK)

#define SIM_SOPT8_FTM1SYNCBIT_MASK               (0x2U)
#define SIM_SOPT8_FTM1SYNCBIT_SHIFT              (1U)
/*! FTM1SYNCBIT - FTM1 Hardware Trigger 0 Software Synchronization
 *  0b0..No effect.
 *  0b1..Write 1 to assert the TRIG0 input to FTM1, software must clear this bit to allow other trigger sources to assert.
 */
#define SIM_SOPT8_FTM1SYNCBIT(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT8_FTM1SYNCBIT_SHIFT)) & SIM_SOPT8_FTM1SYNCBIT_MASK)

#define SIM_SOPT8_FTM2SYNCBIT_MASK               (0x4U)
#define SIM_SOPT8_FTM2SYNCBIT_SHIFT              (2U)
/*! FTM2SYNCBIT - FTM2 Hardware Trigger 0 Software Synchronization
 *  0b0..No effect.
 *  0b1..Write 1 to assert the TRIG0 input to FTM2, software must clear this bit to allow other trigger sources to assert.
 */
#define SIM_SOPT8_FTM2SYNCBIT(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT8_FTM2SYNCBIT_SHIFT)) & SIM_SOPT8_FTM2SYNCBIT_MASK)

#define SIM_SOPT8_FTM0OCH0SRC_MASK               (0x10000U)
#define SIM_SOPT8_FTM0OCH0SRC_SHIFT              (16U)
/*! FTM0OCH0SRC - FTM0 channel 0 output source
 *  0b0..FTM0_CH0 pin is output of FTM0 channel 0 output
 *  0b1..FTM0_CH0 pin is output of FTM0 channel 0 output, modulated by FTM1 channel 1 output
 */
#define SIM_SOPT8_FTM0OCH0SRC(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT8_FTM0OCH0SRC_SHIFT)) & SIM_SOPT8_FTM0OCH0SRC_MASK)

#define SIM_SOPT8_FTM0OCH1SRC_MASK               (0x20000U)
#define SIM_SOPT8_FTM0OCH1SRC_SHIFT              (17U)
/*! FTM0OCH1SRC - FTM0 channel 1 output source
 *  0b0..FTM0_CH1 pin is output of FTM0 channel 1 output
 *  0b1..FTM0_CH1 pin is output of FTM0 channel 1 output, modulated by FTM1 channel 1 output
 */
#define SIM_SOPT8_FTM0OCH1SRC(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT8_FTM0OCH1SRC_SHIFT)) & SIM_SOPT8_FTM0OCH1SRC_MASK)

#define SIM_SOPT8_FTM0OCH2SRC_MASK               (0x40000U)
#define SIM_SOPT8_FTM0OCH2SRC_SHIFT              (18U)
/*! FTM0OCH2SRC - FTM0 channel 2 output source
 *  0b0..FTM0_CH2 pin is output of FTM0 channel 2 output
 *  0b1..FTM0_CH2 pin is output of FTM0 channel 2 output, modulated by FTM1 channel 1 output
 */
#define SIM_SOPT8_FTM0OCH2SRC(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT8_FTM0OCH2SRC_SHIFT)) & SIM_SOPT8_FTM0OCH2SRC_MASK)

#define SIM_SOPT8_FTM0OCH3SRC_MASK               (0x80000U)
#define SIM_SOPT8_FTM0OCH3SRC_SHIFT              (19U)
/*! FTM0OCH3SRC - FTM0 channel 3 output source
 *  0b0..FTM0_CH3 pin is output of FTM0 channel 3 output
 *  0b1..FTM0_CH3 pin is output of FTM0 channel 3 output, modulated by FTM1 channel 1 output
 */
#define SIM_SOPT8_FTM0OCH3SRC(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT8_FTM0OCH3SRC_SHIFT)) & SIM_SOPT8_FTM0OCH3SRC_MASK)

#define SIM_SOPT8_FTM0OCH4SRC_MASK               (0x100000U)
#define SIM_SOPT8_FTM0OCH4SRC_SHIFT              (20U)
/*! FTM0OCH4SRC - FTM0 channel 4 output source
 *  0b0..FTM0_CH4 pin is output of FTM0 channel 4 output
 *  0b1..FTM0_CH4 pin is output of FTM0 channel 4 output, modulated by FTM1 channel 1 output
 */
#define SIM_SOPT8_FTM0OCH4SRC(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT8_FTM0OCH4SRC_SHIFT)) & SIM_SOPT8_FTM0OCH4SRC_MASK)

#define SIM_SOPT8_FTM0OCH5SRC_MASK               (0x200000U)
#define SIM_SOPT8_FTM0OCH5SRC_SHIFT              (21U)
/*! FTM0OCH5SRC - FTM0 channel 5 output source
 *  0b0..FTM0_CH5 pin is output of FTM0 channel 5 output
 *  0b1..FTM0_CH5 pin is output of FTM0 channel 5 output, modulated by FTM1 channel 1 output
 */
#define SIM_SOPT8_FTM0OCH5SRC(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT8_FTM0OCH5SRC_SHIFT)) & SIM_SOPT8_FTM0OCH5SRC_MASK)
/*! @} */

/*! @name SDID - System Device Identification Register */
/*! @{ */

#define SIM_SDID_PINID_MASK                      (0xFU)
#define SIM_SDID_PINID_SHIFT                     (0U)
/*! PINID - Pincount identification
 *  0b0000..Reserved
 *  0b0001..Reserved
 *  0b0010..32-pin
 *  0b0011..Reserved
 *  0b0100..48-pin
 *  0b0101..64-pin
 *  0b0110..80-pin
 *  0b0111..81-pin or 121-pin
 *  0b1000..100-pin
 *  0b1001..121-pin
 *  0b1010..144-pin
 *  0b1011..Custom pinout (WLCSP)
 *  0b1100..169-pin
 *  0b1101..Reserved
 *  0b1110..256-pin
 *  0b1111..Reserved
 */
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_PINID_SHIFT)) & SIM_SDID_PINID_MASK)

#define SIM_SDID_FAMID_MASK                      (0x70U)
#define SIM_SDID_FAMID_SHIFT                     (4U)
/*! FAMID - Kinetis family identification
 *  0b000..K1x Family (without tamper)
 *  0b001..K2x Family (without tamper)
 *  0b010..K3x Family or K1x/K6x Family (with tamper)
 *  0b011..K4x Family or K2x Family (with tamper)
 *  0b100..K6x Family (without tamper)
 *  0b101..K7x Family
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_FAMID_SHIFT)) & SIM_SDID_FAMID_MASK)

#define SIM_SDID_DIEID_MASK                      (0xF80U)
#define SIM_SDID_DIEID_SHIFT                     (7U)
/*! DIEID - Device Die ID */
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_DIEID_SHIFT)) & SIM_SDID_DIEID_MASK)

#define SIM_SDID_REVID_MASK                      (0xF000U)
#define SIM_SDID_REVID_SHIFT                     (12U)
/*! REVID - Device revision number */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_REVID_SHIFT)) & SIM_SDID_REVID_MASK)

#define SIM_SDID_SERIESID_MASK                   (0xF00000U)
#define SIM_SDID_SERIESID_SHIFT                  (20U)
/*! SERIESID - Kinetis Series ID
 *  0b0000..Kinetis K series
 *  0b0001..Kinetis L series
 *  0b0101..Kinetis W series
 *  0b0110..Kinetis V series
 */
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SERIESID_SHIFT)) & SIM_SDID_SERIESID_MASK)

#define SIM_SDID_SUBFAMID_MASK                   (0xF000000U)
#define SIM_SDID_SUBFAMID_SHIFT                  (24U)
/*! SUBFAMID - Kinetis Sub-Family ID
 *  0b0000..Kx0 Subfamily
 *  0b0001..Kx1 Subfamily (tamper detect)
 *  0b0010..Kx2 Subfamily
 *  0b0011..Kx3 Subfamily (tamper detect)
 *  0b0100..Kx4 Subfamily
 *  0b0101..Kx5 Subfamily (tamper detect)
 *  0b0110..Kx6 Subfamily
 */
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SUBFAMID_SHIFT)) & SIM_SDID_SUBFAMID_MASK)

#define SIM_SDID_FAMILYID_MASK                   (0xF0000000U)
#define SIM_SDID_FAMILYID_SHIFT                  (28U)
/*! FAMILYID - Kinetis Family ID
 *  0b0000..K0x Family
 *  0b0001..K1x Family
 *  0b0010..K2x Family
 *  0b0011..K3x Family
 *  0b0100..K4x Family
 *  0b0110..K6x Family
 *  0b0111..K7x Family
 */
#define SIM_SDID_FAMILYID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_FAMILYID_SHIFT)) & SIM_SDID_FAMILYID_MASK)
/*! @} */

/*! @name SCGC4 - System Clock Gating Control Register 4 */
/*! @{ */

#define SIM_SCGC4_EWM_MASK                       (0x2U)
#define SIM_SCGC4_EWM_SHIFT                      (1U)
/*! EWM - EWM Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_EWM(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_EWM_SHIFT)) & SIM_SCGC4_EWM_MASK)

#define SIM_SCGC4_I2C0_MASK                      (0x40U)
#define SIM_SCGC4_I2C0_SHIFT                     (6U)
/*! I2C0 - I2C0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_I2C0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_I2C0_SHIFT)) & SIM_SCGC4_I2C0_MASK)

#define SIM_SCGC4_UART0_MASK                     (0x400U)
#define SIM_SCGC4_UART0_SHIFT                    (10U)
/*! UART0 - UART0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_UART0(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART0_SHIFT)) & SIM_SCGC4_UART0_MASK)

#define SIM_SCGC4_UART1_MASK                     (0x800U)
#define SIM_SCGC4_UART1_SHIFT                    (11U)
/*! UART1 - UART1 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_UART1(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART1_SHIFT)) & SIM_SCGC4_UART1_MASK)

#define SIM_SCGC4_CMP_MASK                       (0x80000U)
#define SIM_SCGC4_CMP_SHIFT                      (19U)
/*! CMP - Comparator Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_CMP(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_CMP_SHIFT)) & SIM_SCGC4_CMP_MASK)

#define SIM_SCGC4_VREF_MASK                      (0x100000U)
#define SIM_SCGC4_VREF_SHIFT                     (20U)
/*! VREF - VREF Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC4_VREF(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_VREF_SHIFT)) & SIM_SCGC4_VREF_MASK)
/*! @} */

/*! @name SCGC5 - System Clock Gating Control Register 5 */
/*! @{ */

#define SIM_SCGC5_LPTMR_MASK                     (0x1U)
#define SIM_SCGC5_LPTMR_SHIFT                    (0U)
/*! LPTMR - Low Power Timer Access Control
 *  0b0..Access disabled
 *  0b1..Access enabled
 */
#define SIM_SCGC5_LPTMR(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_LPTMR_SHIFT)) & SIM_SCGC5_LPTMR_MASK)

#define SIM_SCGC5_PORTA_MASK                     (0x200U)
#define SIM_SCGC5_PORTA_SHIFT                    (9U)
/*! PORTA - Port A Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTA_SHIFT)) & SIM_SCGC5_PORTA_MASK)

#define SIM_SCGC5_PORTB_MASK                     (0x400U)
#define SIM_SCGC5_PORTB_SHIFT                    (10U)
/*! PORTB - Port B Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTB_SHIFT)) & SIM_SCGC5_PORTB_MASK)

#define SIM_SCGC5_PORTC_MASK                     (0x800U)
#define SIM_SCGC5_PORTC_SHIFT                    (11U)
/*! PORTC - Port C Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTC_SHIFT)) & SIM_SCGC5_PORTC_MASK)

#define SIM_SCGC5_PORTD_MASK                     (0x1000U)
#define SIM_SCGC5_PORTD_SHIFT                    (12U)
/*! PORTD - Port D Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTD_SHIFT)) & SIM_SCGC5_PORTD_MASK)

#define SIM_SCGC5_PORTE_MASK                     (0x2000U)
#define SIM_SCGC5_PORTE_SHIFT                    (13U)
/*! PORTE - Port E Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTE_SHIFT)) & SIM_SCGC5_PORTE_MASK)
/*! @} */

/*! @name SCGC6 - System Clock Gating Control Register 6 */
/*! @{ */

#define SIM_SCGC6_FTF_MASK                       (0x1U)
#define SIM_SCGC6_FTF_SHIFT                      (0U)
/*! FTF - Flash Memory Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_FTF(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_FTF_SHIFT)) & SIM_SCGC6_FTF_MASK)

#define SIM_SCGC6_DMAMUX_MASK                    (0x2U)
#define SIM_SCGC6_DMAMUX_SHIFT                   (1U)
/*! DMAMUX - DMA Mux Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_DMAMUX(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DMAMUX_SHIFT)) & SIM_SCGC6_DMAMUX_MASK)

#define SIM_SCGC6_SPI0_MASK                      (0x1000U)
#define SIM_SCGC6_SPI0_SHIFT                     (12U)
/*! SPI0 - SPI0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_SPI0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_SPI0_SHIFT)) & SIM_SCGC6_SPI0_MASK)

#define SIM_SCGC6_CRC_MASK                       (0x40000U)
#define SIM_SCGC6_CRC_SHIFT                      (18U)
/*! CRC - CRC Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_CRC(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_CRC_SHIFT)) & SIM_SCGC6_CRC_MASK)

#define SIM_SCGC6_PDB_MASK                       (0x400000U)
#define SIM_SCGC6_PDB_SHIFT                      (22U)
/*! PDB - PDB Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_PDB(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PDB_SHIFT)) & SIM_SCGC6_PDB_MASK)

#define SIM_SCGC6_PIT_MASK                       (0x800000U)
#define SIM_SCGC6_PIT_SHIFT                      (23U)
/*! PIT - PIT Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_PIT(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PIT_SHIFT)) & SIM_SCGC6_PIT_MASK)

#define SIM_SCGC6_FTM0_MASK                      (0x1000000U)
#define SIM_SCGC6_FTM0_SHIFT                     (24U)
/*! FTM0 - FTM0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_FTM0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_FTM0_SHIFT)) & SIM_SCGC6_FTM0_MASK)

#define SIM_SCGC6_FTM1_MASK                      (0x2000000U)
#define SIM_SCGC6_FTM1_SHIFT                     (25U)
/*! FTM1 - FTM1 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_FTM1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_FTM1_SHIFT)) & SIM_SCGC6_FTM1_MASK)

#define SIM_SCGC6_FTM2_MASK                      (0x4000000U)
#define SIM_SCGC6_FTM2_SHIFT                     (26U)
/*! FTM2 - FTM2 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_FTM2(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_FTM2_SHIFT)) & SIM_SCGC6_FTM2_MASK)

#define SIM_SCGC6_ADC0_MASK                      (0x8000000U)
#define SIM_SCGC6_ADC0_SHIFT                     (27U)
/*! ADC0 - ADC0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_ADC0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_ADC0_SHIFT)) & SIM_SCGC6_ADC0_MASK)

#define SIM_SCGC6_DAC0_MASK                      (0x80000000U)
#define SIM_SCGC6_DAC0_SHIFT                     (31U)
/*! DAC0 - DAC0 Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC6_DAC0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DAC0_SHIFT)) & SIM_SCGC6_DAC0_MASK)
/*! @} */

/*! @name SCGC7 - System Clock Gating Control Register 7 */
/*! @{ */

#define SIM_SCGC7_DMA_MASK                       (0x2U)
#define SIM_SCGC7_DMA_SHIFT                      (1U)
/*! DMA - DMA Clock Gate Control
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define SIM_SCGC7_DMA(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC7_DMA_SHIFT)) & SIM_SCGC7_DMA_MASK)
/*! @} */

/*! @name CLKDIV1 - System Clock Divider Register 1 */
/*! @{ */

#define SIM_CLKDIV1_OUTDIV4_MASK                 (0xF0000U)
#define SIM_CLKDIV1_OUTDIV4_SHIFT                (16U)
/*! OUTDIV4 - Clock 4 output divider value
 *  0b0000..Divide-by-1.
 *  0b0001..Divide-by-2.
 *  0b0010..Divide-by-3.
 *  0b0011..Divide-by-4.
 *  0b0100..Divide-by-5.
 *  0b0101..Divide-by-6.
 *  0b0110..Divide-by-7.
 *  0b0111..Divide-by-8.
 *  0b1000..Divide-by-9.
 *  0b1001..Divide-by-10.
 *  0b1010..Divide-by-11.
 *  0b1011..Divide-by-12.
 *  0b1100..Divide-by-13.
 *  0b1101..Divide-by-14.
 *  0b1110..Divide-by-15.
 *  0b1111..Divide-by-16.
 */
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV4_SHIFT)) & SIM_CLKDIV1_OUTDIV4_MASK)

#define SIM_CLKDIV1_OUTDIV2_MASK                 (0xF000000U)
#define SIM_CLKDIV1_OUTDIV2_SHIFT                (24U)
/*! OUTDIV2 - Clock 2 output divider value
 *  0b0000..Divide-by-1.
 *  0b0001..Divide-by-2.
 *  0b0010..Divide-by-3.
 *  0b0011..Divide-by-4.
 *  0b0100..Divide-by-5.
 *  0b0101..Divide-by-6.
 *  0b0110..Divide-by-7.
 *  0b0111..Divide-by-8.
 *  0b1000..Divide-by-9.
 *  0b1001..Divide-by-10.
 *  0b1010..Divide-by-11.
 *  0b1011..Divide-by-12.
 *  0b1100..Divide-by-13.
 *  0b1101..Divide-by-14.
 *  0b1110..Divide-by-15.
 *  0b1111..Divide-by-16.
 */
#define SIM_CLKDIV1_OUTDIV2(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV2_SHIFT)) & SIM_CLKDIV1_OUTDIV2_MASK)

#define SIM_CLKDIV1_OUTDIV1_MASK                 (0xF0000000U)
#define SIM_CLKDIV1_OUTDIV1_SHIFT                (28U)
/*! OUTDIV1 - Clock 1 output divider value
 *  0b0000..Divide-by-1.
 *  0b0001..Divide-by-2.
 *  0b0010..Divide-by-3.
 *  0b0011..Divide-by-4.
 *  0b0100..Divide-by-5.
 *  0b0101..Divide-by-6.
 *  0b0110..Divide-by-7.
 *  0b0111..Divide-by-8.
 *  0b1000..Divide-by-9.
 *  0b1001..Divide-by-10.
 *  0b1010..Divide-by-11.
 *  0b1011..Divide-by-12.
 *  0b1100..Divide-by-13.
 *  0b1101..Divide-by-14.
 *  0b1110..Divide-by-15.
 *  0b1111..Divide-by-16.
 */
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV1_SHIFT)) & SIM_CLKDIV1_OUTDIV1_MASK)
/*! @} */

/*! @name FCFG1 - Flash Configuration Register 1 */
/*! @{ */

#define SIM_FCFG1_FLASHDIS_MASK                  (0x1U)
#define SIM_FCFG1_FLASHDIS_SHIFT                 (0U)
/*! FLASHDIS - Flash Disable
 *  0b0..Flash is enabled
 *  0b1..Flash is disabled
 */
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDIS_SHIFT)) & SIM_FCFG1_FLASHDIS_MASK)

#define SIM_FCFG1_FLASHDOZE_MASK                 (0x2U)
#define SIM_FCFG1_FLASHDOZE_SHIFT                (1U)
/*! FLASHDOZE - Flash Doze
 *  0b0..Flash remains enabled during Wait mode
 *  0b1..Flash is disabled for the duration of Wait mode
 */
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDOZE_SHIFT)) & SIM_FCFG1_FLASHDOZE_MASK)

#define SIM_FCFG1_PFSIZE_MASK                    (0xF000000U)
#define SIM_FCFG1_PFSIZE_SHIFT                   (24U)
/*! PFSIZE - Program flash size
 *  0b0011..32 KB of program flash memory
 *  0b0101..64 KB of program flash memory
 *  0b0111..128 KB of program flash memory
 *  0b1001..256 KB of program flash memory
 *  0b1011..512 KB of program flash memory
 *  0b1101..1024 KB of program flash memory
 *  0b1111..128 KB of program flash memory
 */
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_PFSIZE_SHIFT)) & SIM_FCFG1_PFSIZE_MASK)
/*! @} */

/*! @name FCFG2 - Flash Configuration Register 2 */
/*! @{ */

#define SIM_FCFG2_MAXADDR0_MASK                  (0x7F000000U)
#define SIM_FCFG2_MAXADDR0_SHIFT                 (24U)
/*! MAXADDR0 - Max address block 0 */
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_MAXADDR0_SHIFT)) & SIM_FCFG2_MAXADDR0_MASK)
/*! @} */

/*! @name UIDH - Unique Identification Register High */
/*! @{ */

#define SIM_UIDH_UID_MASK                        (0xFFFFFFFFU)
#define SIM_UIDH_UID_SHIFT                       (0U)
/*! UID - Unique Identification */
#define SIM_UIDH_UID(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_UIDH_UID_SHIFT)) & SIM_UIDH_UID_MASK)
/*! @} */

/*! @name UIDMH - Unique Identification Register Mid-High */
/*! @{ */

#define SIM_UIDMH_UID_MASK                       (0xFFFFFFFFU)
#define SIM_UIDMH_UID_SHIFT                      (0U)
/*! UID - Unique Identification */
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_UIDMH_UID_SHIFT)) & SIM_UIDMH_UID_MASK)
/*! @} */

/*! @name UIDML - Unique Identification Register Mid Low */
/*! @{ */

#define SIM_UIDML_UID_MASK                       (0xFFFFFFFFU)
#define SIM_UIDML_UID_SHIFT                      (0U)
/*! UID - Unique Identification */
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_UIDML_UID_SHIFT)) & SIM_UIDML_UID_MASK)
/*! @} */

/*! @name UIDL - Unique Identification Register Low */
/*! @{ */

#define SIM_UIDL_UID_MASK                        (0xFFFFFFFFU)
#define SIM_UIDL_UID_SHIFT                       (0U)
/*! UID - Unique Identification */
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_UIDL_UID_SHIFT)) & SIM_UIDL_UID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


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


#endif  /* SIM_H_ */

