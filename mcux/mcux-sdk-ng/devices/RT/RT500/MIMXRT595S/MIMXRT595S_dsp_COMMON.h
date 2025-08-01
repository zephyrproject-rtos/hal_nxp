/*
** ###################################################################
**     Processors:          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_dsp
**
**     Compiler:            Xtensa Compiler
**     Reference manual:    iMXRT500RM Rev.1, 07/2022
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         Peripheral Access Layer for MIMXRT595S_dsp
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMXRT595S_dsp_COMMON.h
 * @version 6.0
 * @date 2024-10-29
 * @brief Peripheral Access Layer for MIMXRT595S_dsp
 *
 * Peripheral Access Layer for MIMXRT595S_dsp
 */

#if !defined(MIMXRT595S_DSP_COMMON_H_)
#define MIMXRT595S_DSP_COMMON_H_                 /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0600U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U

/* ----------------------------------------------------------------------------
   --
   ---------------------------------------------------------------------------- */

/* IO definitions (access restrictions to peripheral registers) */
/**
    \defgroup CMSIS_glob_defs CMSIS Global Defines
    <strong>IO Type Qualifiers</strong> are used
    \li to specify the access to peripheral variables.
    \li for automatic generation of peripheral register debug information.
*/
#define     __I     volatile const       /*!< Defines 'read only' permissions */
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

#define __STATIC_INLINE static inline

#define __BKPT(value) do {} while(0)
#define __NOP() do {} while(0)

#include "system_MIMXRT595S_dsp.h"     /* Device specific configuration file */



/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 73                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = 0,                /**< SysIRQ, Non Maskable Interrupt */
  Software_IRQn                = 1,                /**< Software triggered Interrupt */
  RtosTimer0_IRQn              = 2,                /**< Internal RTOS Timer0 Interrupt */
  RtosTimer1_IRQn              = 3,                /**< Internal RTOS Timer1 Interrupt */
  Profiling_IRQn               = 4,                /**< Profiling Interrupt */

  /* Device specific interrupts */
  DSP_INT0_SEL0_IRQn           = 5,                /**< Interrupt selected by DSP_INT0_SEL0 */
  DSP_INT0_SEL1_IRQn           = 6,                /**< Interrupt selected by DSP_INT0_SEL1 */
  DSP_INT0_SEL2_IRQn           = 7,                /**< Interrupt selected by DSP_INT0_SEL2 */
  DSP_INT0_SEL3_IRQn           = 8,                /**< Interrupt selected by DSP_INT0_SEL3 */
  DSP_INT0_SEL4_IRQn           = 9,                /**< Interrupt selected by DSP_INT0_SEL4 */
  DSP_INT0_SEL5_IRQn           = 10,               /**< Interrupt selected by DSP_INT0_SEL5 */
  DSP_INT0_SEL6_IRQn           = 11,               /**< Interrupt selected by DSP_INT0_SEL6 */
  DSP_INT0_SEL7_IRQn           = 12,               /**< Interrupt selected by DSP_INT0_SEL7 */
  DSP_INT0_SEL8_IRQn           = 13,               /**< Interrupt selected by DSP_INT0_SEL8 */
  DSP_INT0_SEL9_IRQn           = 14,               /**< Interrupt selected by DSP_INT0_SEL9 */
  DSP_INT0_SEL10_IRQn          = 15,               /**< Interrupt selected by DSP_INT0_SEL10 */
  DSP_INT0_SEL11_IRQn          = 16,               /**< Interrupt selected by DSP_INT0_SEL11 */
  DSP_INT0_SEL12_IRQn          = 17,               /**< Interrupt selected by DSP_INT0_SEL12 */
  DSP_INT0_SEL13_IRQn          = 18,               /**< Interrupt selected by DSP_INT0_SEL13 */
  DSP_INT0_SEL14_IRQn          = 19,               /**< Interrupt selected by DSP_INT0_SEL14 */
  DSP_INT0_SEL15_IRQn          = 20,               /**< Interrupt selected by DSP_INT0_SEL15 */
  DSP_INT0_SEL16_IRQn          = 21,               /**< Interrupt selected by DSP_INT0_SEL16 */
  DSP_INT0_SEL17_IRQn          = 22,               /**< Interrupt selected by DSP_INT0_SEL17 */
  DSP_INT0_SEL18_IRQn          = 23,               /**< Interrupt selected by DSP_INT0_SEL18 */
  DSP_INT0_SEL19_IRQn          = 24,               /**< Interrupt selected by DSP_INT0_SEL19 */
  DSP_INT0_SEL20_IRQn          = 25,               /**< Interrupt selected by DSP_INT0_SEL20 */
  DSP_INT0_SEL21_IRQn          = 26,               /**< Interrupt selected by DSP_INT0_SEL21 */
  DSP_INT0_SEL22_IRQn          = 27,               /**< Interrupt selected by DSP_INT0_SEL22 */
  DSP_INT0_SEL23_IRQn          = 28,               /**< Interrupt selected by DSP_INT0_SEL23 */
  DSP_INT0_SEL24_IRQn          = 29,               /**< Interrupt selected by DSP_INT0_SEL24 */
  DSP_INT0_SEL25_IRQn          = 30,               /**< Interrupt selected by DSP_INT0_SEL25 */
  DSP_INT0_SEL26_IRQn          = 31,               /**< Interrupt selected by DSP_INT0_SEL26 */
  FLEXCOMM0_IRQn               = 32,               /**< Flexcomm Interface 0 (USART, SPI, I2C, I2S)(DSP_INT_SELn source IRQ0) */
  FLEXCOMM1_IRQn               = 33,               /**< Flexcomm Interface 1 (USART, SPI, I2C, I2S)(DSP_INT_SELn source IRQ1) */
  FLEXCOMM2_IRQn               = 34,               /**< Flexcomm Interface 2 (USART, SPI, I2C, I2S)(DSP_INT_SELn source IRQ2) */
  FLEXCOMM3_IRQn               = 35,               /**< Flexcomm Interface 3 (USART, SPI, I2C, I2S)(DSP_INT_SELn source IRQ3) */
  FLEXCOMM4_IRQn               = 36,               /**< Flexcomm Interface 4 (USART, SPI, I2C, I2S)(DSP_INT_SELn source IRQ4) */
  FLEXCOMM5_IRQn               = 37,               /**< Flexcomm Interface 5 (USART, SPI, I2C, I2S)(DSP_INT_SELn source IRQ5) */
  FLEXCOMM6_IRQn               = 38,               /**< Flexcomm Interface 6 (USART, SPI, I2C, I3S)(DSP_INT_SELn source IRQ6) */
  FLEXCOMM7_IRQn               = 39,               /**< Flexcomm Interface 7 (USART, SPI, I2C, I4S)(DSP_INT_SELn source IRQ7) */
  FLEXCOMM14_IRQn              = 40,               /**< Flexcomm Interface 14 (USART, SPI, I2C, I5S)(DSP_INT_SELn source IRQ8) */
  FLEXCOMM16_IRQn              = 41,               /**< Flexcomm Interface 16 (USART, SPI, I2C, I6S)(DSP_INT_SELn source IRQ9) */
  PIN_INT0_IRQn                = 42,               /**< Pin interrupt 0 or pattern match engine slice 0 int(DSP_INT_SELn source IRQ10) */
  PIN_INT1_IRQn                = 43,               /**< Pin interrupt 1 or pattern match engine slice 1 int(DSP_INT_SELn source IRQ11) */
  PIN_INT2_IRQn                = 44,               /**< Pin interrupt 2 or pattern match engine slice 2 int(DSP_INT_SELn source IRQ12) */
  PIN_INT3_IRQn                = 45,               /**< Pin interrupt 3 or pattern match engine slice 3 int(DSP_INT_SELn source IRQ13) */
  PIN_INT4_IRQn                = 46,               /**< Pin interrupt 4 or pattern match engine slice 4 int(DSP_INT_SELn source IRQ14) */
  PIN_INT5_IRQn                = 47,               /**< Pin interrupt 5 or pattern match engine slice 5 int(DSP_INT_SELn source IRQ15) */
  PIN_INT6_IRQn                = 48,               /**< Pin interrupt 6 or pattern match engine slice 6 int(DSP_INT_SELn source IRQ16) */
  PIN_INT7_IRQn                = 49,               /**< Pin interrupt 7 or pattern match engine slice 7 int(DSP_INT_SELn source IRQ17) */
  GPIO_INTA_IRQn               = 50,               /**< GPIO interrupt A(DSP_INT_SELn source IRQ18) */
  GPIO_INTB_IRQn               = 51,               /**< GPIO interrupt B(DSP_INT_SELn source IRQ19) */
  WDT1_IRQn                    = 52,               /**< Windowed watchdog timer 1(DSP_INT_SELn source IRQ20) */
  DMA0_IRQn                    = 53,               /**< DMA controller 0 (secure or CM33 DMA)(DSP_INT_SELn source IRQ21) */
  DMA1_IRQn                    = 54,               /**< DMA controller 1 (non-secure or DSP DMA)(DSP_INT_SELn source IRQ22) */
  MU_B_IRQn                    = 55,               /**< Messaging Unit interrupt(DSP_INT_SELn source IRQ23) */
  UTICK0_IRQn                  = 56,               /**< Micro-tick Timer(DSP_INT_SELn source IRQ24) */
  MRT0_IRQn                    = 57,               /**< Multi-Rate Timer(DSP_INT_SELn source IRQ25) */
  OS_EVENT_IRQn                = 58,               /**< OS event timer(DSP_INT_SELn source IRQ26) */
  CTIMER0_IRQn                 = 59,               /**< Standard counter/timer CTIMER0(DSP_INT_SELn source IRQ27) */
  CTIMER1_IRQn                 = 60,               /**< Standard counter/timer CTIMER1(DSP_INT_SELn source IRQ28) */
  CTIMER2_IRQn                 = 61,               /**< Standard counter/timer CTIMER2(DSP_INT_SELn source IRQ29) */
  CTIMER3_IRQn                 = 62,               /**< Standard counter/timer CTIMER3(DSP_INT_SELn source IRQ30) */
  CTIMER4_IRQn                 = 63,               /**< Standard counter/timer CTIMER4(DSP_INT_SELn source IRQ31) */
  RTC_IRQn                     = 64,               /**< RTC alarm and wake-up(DSP_INT_SELn source IRQ32) */
  I3C0_IRQn                    = 65,               /**< I3C interface 0(DSP_INT_SELn source IRQ33) */
  I3C1_IRQn                    = 66,               /**< I3C interface 1(DSP_INT_SELn source IRQ34) */
  DMIC0_IRQn                   = 67,               /**< Digital microphone and DMIC subsystem(DSP_INT_SELn source IRQ35) */
  HWVAD0_IRQn                  = 68,               /**< Hardware Voice Activity Detector(DSP_INT_SELn source IRQ36) */
  LCDIF_IRQn                   = 69,               /**< Liquid Crystal Display Interface interrupt(DSP_INT_SELn source IRQ37) */
  GPU_IRQn                     = 70,               /**< Graphics Processor Unit interrupt(DSP_INT_SELn source IRQ38) */
  SDMA_IRQn                    = 71,               /**< Smart DMA Controller interrupt(DSP_INT_SELn source IRQ39) */
  FLEXIO_IRQn                  = 72                /**< Flexible IO interrupt(DSP_INT_SELn source IRQ40) */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


#ifndef MIMXRT595S_dsp_SERIES
#define MIMXRT595S_dsp_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMXRT595S_dsp_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x4013A000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0 }

/* AXI_SWITCH_AMIB - Peripheral instance base addresses */
/** Peripheral AXI_SWITCH_AMIB base address */
#define AXI_SWITCH_AMIB_BASE                     (0x40282000u)
/** Peripheral AXI_SWITCH_AMIB base pointer */
#define AXI_SWITCH_AMIB                          ((AXI_SWITCH_AMIB_Type *)AXI_SWITCH_AMIB_BASE)
/** Array initializer of AXI_SWITCH_AMIB peripheral base addresses */
#define AXI_SWITCH_AMIB_BASE_ADDRS               { AXI_SWITCH_AMIB_BASE }
/** Array initializer of AXI_SWITCH_AMIB peripheral base pointers */
#define AXI_SWITCH_AMIB_BASE_PTRS                { AXI_SWITCH_AMIB }

/* AXI_SWITCH_ASIB - Peripheral instance base addresses */
/** Peripheral AXI_SWITCH_ASIB base address */
#define AXI_SWITCH_ASIB_BASE                     (0x402C2000u)
/** Peripheral AXI_SWITCH_ASIB base pointer */
#define AXI_SWITCH_ASIB                          ((AXI_SWITCH_ASIB_Type *)AXI_SWITCH_ASIB_BASE)
/** Array initializer of AXI_SWITCH_ASIB peripheral base addresses */
#define AXI_SWITCH_ASIB_BASE_ADDRS               { AXI_SWITCH_ASIB_BASE }
/** Array initializer of AXI_SWITCH_ASIB peripheral base pointers */
#define AXI_SWITCH_ASIB_BASE_PTRS                { AXI_SWITCH_ASIB }

/* CACHE64_CTRL - Peripheral instance base addresses */
/** Peripheral CACHE64_CTRL0 base address */
#define CACHE64_CTRL0_BASE                       (0x40033000u)
/** Peripheral CACHE64_CTRL0 base pointer */
#define CACHE64_CTRL0                            ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE)
/** Peripheral CACHE64_CTRL1 base address */
#define CACHE64_CTRL1_BASE                       (0x40034000u)
/** Peripheral CACHE64_CTRL1 base pointer */
#define CACHE64_CTRL1                            ((CACHE64_CTRL_Type *)CACHE64_CTRL1_BASE)
/** Array initializer of CACHE64_CTRL peripheral base addresses */
#define CACHE64_CTRL_BASE_ADDRS                  { CACHE64_CTRL0_BASE, CACHE64_CTRL1_BASE }
/** Array initializer of CACHE64_CTRL peripheral base pointers */
#define CACHE64_CTRL_BASE_PTRS                   { CACHE64_CTRL0, CACHE64_CTRL1 }
/* Backward compatibility */
#define CACHE64_CTRL_CSAR_PHYADDR_MASK (CACHE64_CTRL_CSAR_PHYADDR27_1_MASK | CACHE64_CTRL_CSAR_PHYADDR31_29_MASK)


/* CACHE64_POLSEL - Peripheral instance base addresses */
/** Peripheral CACHE64_POLSEL0 base address */
#define CACHE64_POLSEL0_BASE                     (0x40033000u)
/** Peripheral CACHE64_POLSEL0 base pointer */
#define CACHE64_POLSEL0                          ((CACHE64_POLSEL_Type *)CACHE64_POLSEL0_BASE)
/** Peripheral CACHE64_POLSEL1 base address */
#define CACHE64_POLSEL1_BASE                     (0x40034000u)
/** Peripheral CACHE64_POLSEL1 base pointer */
#define CACHE64_POLSEL1                          ((CACHE64_POLSEL_Type *)CACHE64_POLSEL1_BASE)
/** Array initializer of CACHE64_POLSEL peripheral base addresses */
#define CACHE64_POLSEL_BASE_ADDRS                { CACHE64_POLSEL0_BASE, CACHE64_POLSEL1_BASE }
/** Array initializer of CACHE64_POLSEL peripheral base pointers */
#define CACHE64_POLSEL_BASE_PTRS                 { CACHE64_POLSEL0, CACHE64_POLSEL1 }

/* CASPER - Peripheral instance base addresses */
/** Peripheral CASPER base address */
#define CASPER_BASE                              (0x40201000u)
/** Peripheral CASPER base pointer */
#define CASPER                                   ((CASPER_Type *)CASPER_BASE)
/** Array initializer of CASPER peripheral base addresses */
#define CASPER_BASE_ADDRS                        { CASPER_BASE }
/** Array initializer of CASPER peripheral base pointers */
#define CASPER_BASE_PTRS                         { CASPER }

/* CLKCTL0 - Peripheral instance base addresses */
/** Peripheral CLKCTL0 base address */
#define CLKCTL0_BASE                             (0x40001000u)
/** Peripheral CLKCTL0 base pointer */
#define CLKCTL0                                  ((CLKCTL0_Type *)CLKCTL0_BASE)
/** Array initializer of CLKCTL0 peripheral base addresses */
#define CLKCTL0_BASE_ADDRS                       { CLKCTL0_BASE }
/** Array initializer of CLKCTL0 peripheral base pointers */
#define CLKCTL0_BASE_PTRS                        { CLKCTL0 }

/* CLKCTL1 - Peripheral instance base addresses */
/** Peripheral CLKCTL1 base address */
#define CLKCTL1_BASE                             (0x40021000u)
/** Peripheral CLKCTL1 base pointer */
#define CLKCTL1                                  ((CLKCTL1_Type *)CLKCTL1_BASE)
/** Array initializer of CLKCTL1 peripheral base addresses */
#define CLKCTL1_BASE_ADDRS                       { CLKCTL1_BASE }
/** Array initializer of CLKCTL1 peripheral base pointers */
#define CLKCTL1_BASE_PTRS                        { CLKCTL1 }

/* CMP - Peripheral instance base addresses */
/** Peripheral ACMP0 base address */
#define ACMP0_BASE                               (0x40139000u)
/** Peripheral ACMP0 base pointer */
#define ACMP0                                    ((CMP_Type *)ACMP0_BASE)
/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           { ACMP0_BASE }
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { ACMP0 }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC_ENGINE base address */
#define CRC_ENGINE_BASE                          (0x40120000u)
/** Peripheral CRC_ENGINE base pointer */
#define CRC_ENGINE                               ((CRC_Type *)CRC_ENGINE_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_ENGINE_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC_ENGINE }

/* CTIMER - Peripheral instance base addresses */
/** Peripheral CTIMER0 base address */
#define CTIMER0_BASE                             (0x40028000u)
/** Peripheral CTIMER0 base pointer */
#define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
/** Peripheral CTIMER1 base address */
#define CTIMER1_BASE                             (0x40029000u)
/** Peripheral CTIMER1 base pointer */
#define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
/** Peripheral CTIMER2 base address */
#define CTIMER2_BASE                             (0x4002A000u)
/** Peripheral CTIMER2 base pointer */
#define CTIMER2                                  ((CTIMER_Type *)CTIMER2_BASE)
/** Peripheral CTIMER3 base address */
#define CTIMER3_BASE                             (0x4002B000u)
/** Peripheral CTIMER3 base pointer */
#define CTIMER3                                  ((CTIMER_Type *)CTIMER3_BASE)
/** Peripheral CTIMER4 base address */
#define CTIMER4_BASE                             (0x4002C000u)
/** Peripheral CTIMER4 base pointer */
#define CTIMER4                                  ((CTIMER_Type *)CTIMER4_BASE)
/** Array initializer of CTIMER peripheral base addresses */
#define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE, CTIMER2_BASE, CTIMER3_BASE, CTIMER4_BASE }
/** Array initializer of CTIMER peripheral base pointers */
#define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1, CTIMER2, CTIMER3, CTIMER4 }
/** Interrupt vectors for the CTIMER peripheral type */
#define CTIMER_IRQS                              { CTIMER0_IRQn, CTIMER1_IRQn, CTIMER2_IRQn, CTIMER3_IRQn, CTIMER4_IRQn }

/* DEBUGGER_MAILBOX - Peripheral instance base addresses */
/** Peripheral DEBUGGER_MAILBOX base address */
#define DEBUGGER_MAILBOX_BASE                    (0x4010F000u)
/** Peripheral DEBUGGER_MAILBOX base pointer */
#define DEBUGGER_MAILBOX                         ((DEBUGGER_MAILBOX_Type *)DEBUGGER_MAILBOX_BASE)
/** Array initializer of DEBUGGER_MAILBOX peripheral base addresses */
#define DEBUGGER_MAILBOX_BASE_ADDRS              { DEBUGGER_MAILBOX_BASE }
/** Array initializer of DEBUGGER_MAILBOX peripheral base pointers */
#define DEBUGGER_MAILBOX_BASE_PTRS               { DEBUGGER_MAILBOX }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x40104000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Peripheral DMA1 base address */
#define DMA1_BASE                                (0x40105000u)
/** Peripheral DMA1 base pointer */
#define DMA1                                     ((DMA_Type *)DMA1_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE, DMA1_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0, DMA1 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { DMA0_IRQn, DMA1_IRQn }

/* DMIC - Peripheral instance base addresses */
/** Peripheral DMIC0 base address */
#define DMIC0_BASE                               (0x40121000u)
/** Peripheral DMIC0 base pointer */
#define DMIC0                                    ((DMIC_Type *)DMIC0_BASE)
/** Array initializer of DMIC peripheral base addresses */
#define DMIC_BASE_ADDRS                          { DMIC0_BASE }
/** Array initializer of DMIC peripheral base pointers */
#define DMIC_BASE_PTRS                           { DMIC0 }
/** Interrupt vectors for the DMIC peripheral type */
#define DMIC_IRQS                                { DMIC0_IRQn }
#define DMIC_HWVAD_IRQS                          { HWVAD0_IRQn }

/* FLEXCOMM - Peripheral instance base addresses */
/** Peripheral FLEXCOMM0 base address */
#define FLEXCOMM0_BASE                           (0x40106000u)
/** Peripheral FLEXCOMM0 base pointer */
#define FLEXCOMM0                                ((FLEXCOMM_Type *)FLEXCOMM0_BASE)
/** Peripheral FLEXCOMM1 base address */
#define FLEXCOMM1_BASE                           (0x40107000u)
/** Peripheral FLEXCOMM1 base pointer */
#define FLEXCOMM1                                ((FLEXCOMM_Type *)FLEXCOMM1_BASE)
/** Peripheral FLEXCOMM2 base address */
#define FLEXCOMM2_BASE                           (0x40108000u)
/** Peripheral FLEXCOMM2 base pointer */
#define FLEXCOMM2                                ((FLEXCOMM_Type *)FLEXCOMM2_BASE)
/** Peripheral FLEXCOMM3 base address */
#define FLEXCOMM3_BASE                           (0x40109000u)
/** Peripheral FLEXCOMM3 base pointer */
#define FLEXCOMM3                                ((FLEXCOMM_Type *)FLEXCOMM3_BASE)
/** Peripheral FLEXCOMM4 base address */
#define FLEXCOMM4_BASE                           (0x40122000u)
/** Peripheral FLEXCOMM4 base pointer */
#define FLEXCOMM4                                ((FLEXCOMM_Type *)FLEXCOMM4_BASE)
/** Peripheral FLEXCOMM5 base address */
#define FLEXCOMM5_BASE                           (0x40123000u)
/** Peripheral FLEXCOMM5 base pointer */
#define FLEXCOMM5                                ((FLEXCOMM_Type *)FLEXCOMM5_BASE)
/** Peripheral FLEXCOMM6 base address */
#define FLEXCOMM6_BASE                           (0x40124000u)
/** Peripheral FLEXCOMM6 base pointer */
#define FLEXCOMM6                                ((FLEXCOMM_Type *)FLEXCOMM6_BASE)
/** Peripheral FLEXCOMM7 base address */
#define FLEXCOMM7_BASE                           (0x40125000u)
/** Peripheral FLEXCOMM7 base pointer */
#define FLEXCOMM7                                ((FLEXCOMM_Type *)FLEXCOMM7_BASE)
/** Peripheral FLEXCOMM8 base address */
#define FLEXCOMM8_BASE                           (0x40209000u)
/** Peripheral FLEXCOMM8 base pointer */
#define FLEXCOMM8                                ((FLEXCOMM_Type *)FLEXCOMM8_BASE)
/** Peripheral FLEXCOMM9 base address */
#define FLEXCOMM9_BASE                           (0x4020A000u)
/** Peripheral FLEXCOMM9 base pointer */
#define FLEXCOMM9                                ((FLEXCOMM_Type *)FLEXCOMM9_BASE)
/** Peripheral FLEXCOMM10 base address */
#define FLEXCOMM10_BASE                          (0x4020B000u)
/** Peripheral FLEXCOMM10 base pointer */
#define FLEXCOMM10                               ((FLEXCOMM_Type *)FLEXCOMM10_BASE)
/** Peripheral FLEXCOMM11 base address */
#define FLEXCOMM11_BASE                          (0x4020C000u)
/** Peripheral FLEXCOMM11 base pointer */
#define FLEXCOMM11                               ((FLEXCOMM_Type *)FLEXCOMM11_BASE)
/** Peripheral FLEXCOMM12 base address */
#define FLEXCOMM12_BASE                          (0x4020D000u)
/** Peripheral FLEXCOMM12 base pointer */
#define FLEXCOMM12                               ((FLEXCOMM_Type *)FLEXCOMM12_BASE)
/** Peripheral FLEXCOMM13 base address */
#define FLEXCOMM13_BASE                          (0x4020E000u)
/** Peripheral FLEXCOMM13 base pointer */
#define FLEXCOMM13                               ((FLEXCOMM_Type *)FLEXCOMM13_BASE)
/** Peripheral FLEXCOMM14 base address */
#define FLEXCOMM14_BASE                          (0x40126000u)
/** Peripheral FLEXCOMM14 base pointer */
#define FLEXCOMM14                               ((FLEXCOMM_Type *)FLEXCOMM14_BASE)
/** Peripheral FLEXCOMM15 base address */
#define FLEXCOMM15_BASE                          (0x40127000u)
/** Peripheral FLEXCOMM15 base pointer */
#define FLEXCOMM15                               ((FLEXCOMM_Type *)FLEXCOMM15_BASE)
/** Peripheral FLEXCOMM16 base address */
#define FLEXCOMM16_BASE                          (0x40128000u)
/** Peripheral FLEXCOMM16 base pointer */
#define FLEXCOMM16                               ((FLEXCOMM_Type *)FLEXCOMM16_BASE)
/** Array initializer of FLEXCOMM peripheral base addresses */
#define FLEXCOMM_BASE_ADDRS                      { FLEXCOMM0_BASE, FLEXCOMM1_BASE, FLEXCOMM2_BASE, FLEXCOMM3_BASE, FLEXCOMM4_BASE, FLEXCOMM5_BASE, FLEXCOMM6_BASE, FLEXCOMM7_BASE, FLEXCOMM8_BASE, FLEXCOMM9_BASE, FLEXCOMM10_BASE, FLEXCOMM11_BASE, FLEXCOMM12_BASE, FLEXCOMM13_BASE, FLEXCOMM14_BASE, FLEXCOMM15_BASE, FLEXCOMM16_BASE }
/** Array initializer of FLEXCOMM peripheral base pointers */
#define FLEXCOMM_BASE_PTRS                       { FLEXCOMM0, FLEXCOMM1, FLEXCOMM2, FLEXCOMM3, FLEXCOMM4, FLEXCOMM5, FLEXCOMM6, FLEXCOMM7, FLEXCOMM8, FLEXCOMM9, FLEXCOMM10, FLEXCOMM11, FLEXCOMM12, FLEXCOMM13, FLEXCOMM14, FLEXCOMM15, FLEXCOMM16 }
/** Interrupt vectors for the FLEXCOMM peripheral type */
#define FLEXCOMM_IRQS                            { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, FLEXCOMM14_IRQn, NotAvail_IRQn, FLEXCOMM16_IRQn }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO0 base address */
#define FLEXIO0_BASE                             (0x40032000u)
/** Peripheral FLEXIO0 base pointer */
#define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { FLEXIO0 }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { FLEXIO_IRQn }

/* FLEXSPI - Peripheral instance base addresses */
/** Peripheral FLEXSPI0 base address */
#define FLEXSPI0_BASE                            (0x40134000u)
/** Peripheral FLEXSPI0 base pointer */
#define FLEXSPI0                                 ((FLEXSPI_Type *)FLEXSPI0_BASE)
/** Peripheral FLEXSPI1 base address */
#define FLEXSPI1_BASE                            (0x4013C000u)
/** Peripheral FLEXSPI1 base pointer */
#define FLEXSPI1                                 ((FLEXSPI_Type *)FLEXSPI1_BASE)
/** Array initializer of FLEXSPI peripheral base addresses */
#define FLEXSPI_BASE_ADDRS                       { FLEXSPI0_BASE, FLEXSPI1_BASE }
/** Array initializer of FLEXSPI peripheral base pointers */
#define FLEXSPI_BASE_PTRS                        { FLEXSPI0, FLEXSPI1 }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (1)
/* FlexSPI AMBA base address array. */
#define FlexSPI_AMBA_BASE_ARRAY                  { {0x08000000u}, {0x28000000u} }
/* FlexSPI AMBA end address array. */
#define FlexSPI_AMBA_END_ARRAY                   { {0x0FFFFFFFu}, {0x2FFFFFFFu} }
/* FlexSPI0 AMBA address. */
#define FlexSPI0_AMBA_BASE                       (0x08000000u)
/* FlexSPI1 AMBA address. */
#define FlexSPI1_AMBA_BASE                       (0x28000000u)


/* FREQME - Peripheral instance base addresses */
/** Peripheral FREQME base address */
#define FREQME_BASE                              (0x4002F000u)
/** Peripheral FREQME base pointer */
#define FREQME                                   ((FREQME_Type *)FREQME_BASE)
/** Array initializer of FREQME peripheral base addresses */
#define FREQME_BASE_ADDRS                        { FREQME_BASE }
/** Array initializer of FREQME peripheral base pointers */
#define FREQME_BASE_PTRS                         { FREQME }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO base address */
#define GPIO_BASE                                (0x40100000u)
/** Peripheral GPIO base pointer */
#define GPIO                                     ((GPIO_Type *)GPIO_BASE)
/** Peripheral SECGPIO base address */
#define SECGPIO_BASE                             (0x40204000u)
/** Peripheral SECGPIO base pointer */
#define SECGPIO                                  ((GPIO_Type *)SECGPIO_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIO_BASE, SECGPIO_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIO, SECGPIO }

/* HASHCRYPT - Peripheral instance base addresses */
/** Peripheral HASHCRYPT base address */
#define HASHCRYPT_BASE                           (0x40208000u)
/** Peripheral HASHCRYPT base pointer */
#define HASHCRYPT                                ((HASHCRYPT_Type *)HASHCRYPT_BASE)
/** Array initializer of HASHCRYPT peripheral base addresses */
#define HASHCRYPT_BASE_ADDRS                     { HASHCRYPT_BASE }
/** Array initializer of HASHCRYPT peripheral base pointers */
#define HASHCRYPT_BASE_PTRS                      { HASHCRYPT }

/* I2C - Peripheral instance base addresses */
/** Peripheral I2C0 base address */
#define I2C0_BASE                                (0x40106000u)
/** Peripheral I2C0 base pointer */
#define I2C0                                     ((I2C_Type *)I2C0_BASE)
/** Peripheral I2C1 base address */
#define I2C1_BASE                                (0x40107000u)
/** Peripheral I2C1 base pointer */
#define I2C1                                     ((I2C_Type *)I2C1_BASE)
/** Peripheral I2C2 base address */
#define I2C2_BASE                                (0x40108000u)
/** Peripheral I2C2 base pointer */
#define I2C2                                     ((I2C_Type *)I2C2_BASE)
/** Peripheral I2C3 base address */
#define I2C3_BASE                                (0x40109000u)
/** Peripheral I2C3 base pointer */
#define I2C3                                     ((I2C_Type *)I2C3_BASE)
/** Peripheral I2C4 base address */
#define I2C4_BASE                                (0x40122000u)
/** Peripheral I2C4 base pointer */
#define I2C4                                     ((I2C_Type *)I2C4_BASE)
/** Peripheral I2C5 base address */
#define I2C5_BASE                                (0x40123000u)
/** Peripheral I2C5 base pointer */
#define I2C5                                     ((I2C_Type *)I2C5_BASE)
/** Peripheral I2C6 base address */
#define I2C6_BASE                                (0x40124000u)
/** Peripheral I2C6 base pointer */
#define I2C6                                     ((I2C_Type *)I2C6_BASE)
/** Peripheral I2C7 base address */
#define I2C7_BASE                                (0x40125000u)
/** Peripheral I2C7 base pointer */
#define I2C7                                     ((I2C_Type *)I2C7_BASE)
/** Peripheral I2C8 base address */
#define I2C8_BASE                                (0x40209000u)
/** Peripheral I2C8 base pointer */
#define I2C8                                     ((I2C_Type *)I2C8_BASE)
/** Peripheral I2C9 base address */
#define I2C9_BASE                                (0x4020A000u)
/** Peripheral I2C9 base pointer */
#define I2C9                                     ((I2C_Type *)I2C9_BASE)
/** Peripheral I2C10 base address */
#define I2C10_BASE                               (0x4020B000u)
/** Peripheral I2C10 base pointer */
#define I2C10                                    ((I2C_Type *)I2C10_BASE)
/** Peripheral I2C11 base address */
#define I2C11_BASE                               (0x4020C000u)
/** Peripheral I2C11 base pointer */
#define I2C11                                    ((I2C_Type *)I2C11_BASE)
/** Peripheral I2C12 base address */
#define I2C12_BASE                               (0x4020D000u)
/** Peripheral I2C12 base pointer */
#define I2C12                                    ((I2C_Type *)I2C12_BASE)
/** Peripheral I2C13 base address */
#define I2C13_BASE                               (0x4020E000u)
/** Peripheral I2C13 base pointer */
#define I2C13                                    ((I2C_Type *)I2C13_BASE)
/** Peripheral I2C15 base address */
#define I2C15_BASE                               (0x40127000u)
/** Peripheral I2C15 base pointer */
#define I2C15                                    ((I2C_Type *)I2C15_BASE)
/** Array initializer of I2C peripheral base addresses */
#define I2C_BASE_ADDRS                           { I2C0_BASE, I2C1_BASE, I2C2_BASE, I2C3_BASE, I2C4_BASE, I2C5_BASE, I2C6_BASE, I2C7_BASE, I2C8_BASE, I2C9_BASE, I2C10_BASE, I2C11_BASE, I2C12_BASE, I2C13_BASE, I2C15_BASE }
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { I2C0, I2C1, I2C2, I2C3, I2C4, I2C5, I2C6, I2C7, I2C8, I2C9, I2C10, I2C11, I2C12, I2C13, I2C15 }
/** Interrupt vectors for the I2C peripheral type */
#define I2C_IRQS                                 { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* I2S - Peripheral instance base addresses */
/** Peripheral I2S0 base address */
#define I2S0_BASE                                (0x40106000u)
/** Peripheral I2S0 base pointer */
#define I2S0                                     ((I2S_Type *)I2S0_BASE)
/** Peripheral I2S1 base address */
#define I2S1_BASE                                (0x40107000u)
/** Peripheral I2S1 base pointer */
#define I2S1                                     ((I2S_Type *)I2S1_BASE)
/** Peripheral I2S2 base address */
#define I2S2_BASE                                (0x40108000u)
/** Peripheral I2S2 base pointer */
#define I2S2                                     ((I2S_Type *)I2S2_BASE)
/** Peripheral I2S3 base address */
#define I2S3_BASE                                (0x40109000u)
/** Peripheral I2S3 base pointer */
#define I2S3                                     ((I2S_Type *)I2S3_BASE)
/** Peripheral I2S4 base address */
#define I2S4_BASE                                (0x40122000u)
/** Peripheral I2S4 base pointer */
#define I2S4                                     ((I2S_Type *)I2S4_BASE)
/** Peripheral I2S5 base address */
#define I2S5_BASE                                (0x40123000u)
/** Peripheral I2S5 base pointer */
#define I2S5                                     ((I2S_Type *)I2S5_BASE)
/** Peripheral I2S6 base address */
#define I2S6_BASE                                (0x40124000u)
/** Peripheral I2S6 base pointer */
#define I2S6                                     ((I2S_Type *)I2S6_BASE)
/** Peripheral I2S7 base address */
#define I2S7_BASE                                (0x40125000u)
/** Peripheral I2S7 base pointer */
#define I2S7                                     ((I2S_Type *)I2S7_BASE)
/** Peripheral I2S8 base address */
#define I2S8_BASE                                (0x40209000u)
/** Peripheral I2S8 base pointer */
#define I2S8                                     ((I2S_Type *)I2S8_BASE)
/** Peripheral I2S9 base address */
#define I2S9_BASE                                (0x4020A000u)
/** Peripheral I2S9 base pointer */
#define I2S9                                     ((I2S_Type *)I2S9_BASE)
/** Peripheral I2S10 base address */
#define I2S10_BASE                               (0x4020B000u)
/** Peripheral I2S10 base pointer */
#define I2S10                                    ((I2S_Type *)I2S10_BASE)
/** Peripheral I2S11 base address */
#define I2S11_BASE                               (0x4020C000u)
/** Peripheral I2S11 base pointer */
#define I2S11                                    ((I2S_Type *)I2S11_BASE)
/** Peripheral I2S12 base address */
#define I2S12_BASE                               (0x4020D000u)
/** Peripheral I2S12 base pointer */
#define I2S12                                    ((I2S_Type *)I2S12_BASE)
/** Peripheral I2S13 base address */
#define I2S13_BASE                               (0x4020E000u)
/** Peripheral I2S13 base pointer */
#define I2S13                                    ((I2S_Type *)I2S13_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { I2S0_BASE, I2S1_BASE, I2S2_BASE, I2S3_BASE, I2S4_BASE, I2S5_BASE, I2S6_BASE, I2S7_BASE, I2S8_BASE, I2S9_BASE, I2S10_BASE, I2S11_BASE, I2S12_BASE, I2S13_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { I2S0, I2S1, I2S2, I2S3, I2S4, I2S5, I2S6, I2S7, I2S8, I2S9, I2S10, I2S11, I2S12, I2S13 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_IRQS                                 { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* I3C - Peripheral instance base addresses */
/** Peripheral I3C0 base address */
#define I3C0_BASE                                (0x40036000u)
/** Peripheral I3C0 base pointer */
#define I3C0                                     ((I3C_Type *)I3C0_BASE)
/** Peripheral I3C1 base address */
#define I3C1_BASE                                (0x40037000u)
/** Peripheral I3C1 base pointer */
#define I3C1                                     ((I3C_Type *)I3C1_BASE)
/** Array initializer of I3C peripheral base addresses */
#define I3C_BASE_ADDRS                           { I3C0_BASE, I3C1_BASE }
/** Array initializer of I3C peripheral base pointers */
#define I3C_BASE_PTRS                            { I3C0, I3C1 }
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { I3C0_IRQn, I3C1_IRQn }

/* INPUTMUX - Peripheral instance base addresses */
/** Peripheral INPUTMUX base address */
#define INPUTMUX_BASE                            (0x40026000u)
/** Peripheral INPUTMUX base pointer */
#define INPUTMUX                                 ((INPUTMUX_Type *)INPUTMUX_BASE)
/** Array initializer of INPUTMUX peripheral base addresses */
#define INPUTMUX_BASE_ADDRS                      { INPUTMUX_BASE }
/** Array initializer of INPUTMUX peripheral base pointers */
#define INPUTMUX_BASE_PTRS                       { INPUTMUX }

/* IOPCTL - Peripheral instance base addresses */
/** Peripheral IOPCTL base address */
#define IOPCTL_BASE                              (0x40004000u)
/** Peripheral IOPCTL base pointer */
#define IOPCTL                                   ((IOPCTL_Type *)IOPCTL_BASE)
/** Array initializer of IOPCTL peripheral base addresses */
#define IOPCTL_BASE_ADDRS                        { IOPCTL_BASE }
/** Array initializer of IOPCTL peripheral base pointers */
#define IOPCTL_BASE_PTRS                         { IOPCTL }

/* LCDIF - Peripheral instance base addresses */
/** Peripheral LCDIF base address */
#define LCDIF_BASE                               (0x40210000u)
/** Peripheral LCDIF base pointer */
#define LCDIF                                    ((LCDIF_Type *)LCDIF_BASE)
/** Array initializer of LCDIF peripheral base addresses */
#define LCDIF_BASE_ADDRS                         { LCDIF_BASE }
/** Array initializer of LCDIF peripheral base pointers */
#define LCDIF_BASE_PTRS                          { LCDIF }
/** Interrupt vectors for the LCDIF peripheral type */
#define LCDIF_IRQ0_IRQS                          { LCDIF_IRQn }

/* MIPI_DSI_HOST - Peripheral instance base addresses */
/** Peripheral MIPI_DSI_HOST base address */
#define MIPI_DSI_HOST_BASE                       (0x40031000u)
/** Peripheral MIPI_DSI_HOST base pointer */
#define MIPI_DSI_HOST                            ((MIPI_DSI_HOST_Type *)MIPI_DSI_HOST_BASE)
/** Array initializer of MIPI_DSI_HOST peripheral base addresses */
#define MIPI_DSI_HOST_BASE_ADDRS                 { MIPI_DSI_HOST_BASE }
/** Array initializer of MIPI_DSI_HOST peripheral base pointers */
#define MIPI_DSI_HOST_BASE_PTRS                  { MIPI_DSI_HOST }

/* MRT - Peripheral instance base addresses */
/** Peripheral MRT0 base address */
#define MRT0_BASE                                (0x4002D000u)
/** Peripheral MRT0 base pointer */
#define MRT0                                     ((MRT_Type *)MRT0_BASE)
/** Array initializer of MRT peripheral base addresses */
#define MRT_BASE_ADDRS                           { MRT0_BASE }
/** Array initializer of MRT peripheral base pointers */
#define MRT_BASE_PTRS                            { MRT0 }
/** Interrupt vectors for the MRT peripheral type */
#define MRT_IRQS                                 { MRT0_IRQn }

/* MU - Peripheral instance base addresses */
/** Peripheral MUB base address */
#define MUB_BASE                                 (0x40111000u)
/** Peripheral MUB base pointer */
#define MUB                                      ((MU_Type *)MUB_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MUB_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MUB }
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU_B_IRQn }

/* OCOTP - Peripheral instance base addresses */
/** Peripheral OCOTP0 base address */
#define OCOTP0_BASE                              (0x40130000u)
/** Peripheral OCOTP0 base pointer */
#define OCOTP0                                   ((OCOTP_Type *)OCOTP0_BASE)
/** Array initializer of OCOTP peripheral base addresses */
#define OCOTP_BASE_ADDRS                         { OCOTP0_BASE }
/** Array initializer of OCOTP peripheral base pointers */
#define OCOTP_BASE_PTRS                          { OCOTP0 }

/* OSTIMER - Peripheral instance base addresses */
/** Peripheral OSTIMER1 base address */
#define OSTIMER1_BASE                            (0x40114000u)
/** Peripheral OSTIMER1 base pointer */
#define OSTIMER1                                 ((OSTIMER_Type *)OSTIMER1_BASE)
/** Array initializer of OSTIMER peripheral base addresses */
#define OSTIMER_BASE_ADDRS                       { OSTIMER1_BASE }
/** Array initializer of OSTIMER peripheral base pointers */
#define OSTIMER_BASE_PTRS                        { OSTIMER1 }
/** Interrupt vectors for the OSTIMER peripheral type */
#define OSTIMER_IRQS                             { OS_EVENT_IRQn }

/* OTFAD - Peripheral instance base addresses */
/** Peripheral OTFAD0 base address */
#define OTFAD0_BASE                              (0x40134000u)
/** Peripheral OTFAD0 base pointer */
#define OTFAD0                                   ((OTFAD_Type *)OTFAD0_BASE)
/** Array initializer of OTFAD peripheral base addresses */
#define OTFAD_BASE_ADDRS                         { OTFAD0_BASE }
/** Array initializer of OTFAD peripheral base pointers */
#define OTFAD_BASE_PTRS                          { OTFAD0 }

/* PINT - Peripheral instance base addresses */
/** Peripheral PINT base address */
#define PINT_BASE                                (0x40025000u)
/** Peripheral PINT base pointer */
#define PINT                                     ((PINT_Type *)PINT_BASE)
/** Array initializer of PINT peripheral base addresses */
#define PINT_BASE_ADDRS                          { PINT_BASE }
/** Array initializer of PINT peripheral base pointers */
#define PINT_BASE_PTRS                           { PINT }
/** Interrupt vectors for the PINT peripheral type */
#define PINT_IRQS                                { PIN_INT0_IRQn, PIN_INT1_IRQn, PIN_INT2_IRQn, PIN_INT3_IRQn, PIN_INT4_IRQn, PIN_INT5_IRQn, PIN_INT6_IRQn, PIN_INT7_IRQn }

/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base address */
#define PMC_BASE                                 (0x40135000u)
/** Peripheral PMC base pointer */
#define PMC                                      ((PMC_Type *)PMC_BASE)
/** Array initializer of PMC peripheral base addresses */
#define PMC_BASE_ADDRS                           { PMC_BASE }
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASE_PTRS                            { PMC }

/* POWERQUAD - Peripheral instance base addresses */
/** Peripheral POWERQUAD base address */
#define POWERQUAD_BASE                           (0x40200000u)
/** Peripheral POWERQUAD base pointer */
#define POWERQUAD                                ((POWERQUAD_Type *)POWERQUAD_BASE)
/** Array initializer of POWERQUAD peripheral base addresses */
#define POWERQUAD_BASE_ADDRS                     { POWERQUAD_BASE }
/** Array initializer of POWERQUAD peripheral base pointers */
#define POWERQUAD_BASE_PTRS                      { POWERQUAD }

/* PUF - Peripheral instance base addresses */
/** Peripheral PUF base address */
#define PUF_BASE                                 (0x40006000u)
/** Peripheral PUF base pointer */
#define PUF                                      ((PUF_Type *)PUF_BASE)
/** Array initializer of PUF peripheral base addresses */
#define PUF_BASE_ADDRS                           { PUF_BASE }
/** Array initializer of PUF peripheral base pointers */
#define PUF_BASE_PTRS                            { PUF }

/* RSTCTL0 - Peripheral instance base addresses */
/** Peripheral RSTCTL0 base address */
#define RSTCTL0_BASE                             (0x40000000u)
/** Peripheral RSTCTL0 base pointer */
#define RSTCTL0                                  ((RSTCTL0_Type *)RSTCTL0_BASE)
/** Array initializer of RSTCTL0 peripheral base addresses */
#define RSTCTL0_BASE_ADDRS                       { RSTCTL0_BASE }
/** Array initializer of RSTCTL0 peripheral base pointers */
#define RSTCTL0_BASE_PTRS                        { RSTCTL0 }

/* RSTCTL1 - Peripheral instance base addresses */
/** Peripheral RSTCTL1 base address */
#define RSTCTL1_BASE                             (0x40020000u)
/** Peripheral RSTCTL1 base pointer */
#define RSTCTL1                                  ((RSTCTL1_Type *)RSTCTL1_BASE)
/** Array initializer of RSTCTL1 peripheral base addresses */
#define RSTCTL1_BASE_ADDRS                       { RSTCTL1_BASE }
/** Array initializer of RSTCTL1 peripheral base pointers */
#define RSTCTL1_BASE_PTRS                        { RSTCTL1 }

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x40030000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }

/* SEMA42 - Peripheral instance base addresses */
/** Peripheral SEMA42 base address */
#define SEMA42_BASE                              (0x40112000u)
/** Peripheral SEMA42 base pointer */
#define SEMA42                                   ((SEMA42_Type *)SEMA42_BASE)
/** Array initializer of SEMA42 peripheral base addresses */
#define SEMA42_BASE_ADDRS                        { SEMA42_BASE }
/** Array initializer of SEMA42 peripheral base pointers */
#define SEMA42_BASE_PTRS                         { SEMA42 }

/* SPI - Peripheral instance base addresses */
/** Peripheral SPI0 base address */
#define SPI0_BASE                                (0x40106000u)
/** Peripheral SPI0 base pointer */
#define SPI0                                     ((SPI_Type *)SPI0_BASE)
/** Peripheral SPI1 base address */
#define SPI1_BASE                                (0x40107000u)
/** Peripheral SPI1 base pointer */
#define SPI1                                     ((SPI_Type *)SPI1_BASE)
/** Peripheral SPI2 base address */
#define SPI2_BASE                                (0x40108000u)
/** Peripheral SPI2 base pointer */
#define SPI2                                     ((SPI_Type *)SPI2_BASE)
/** Peripheral SPI3 base address */
#define SPI3_BASE                                (0x40109000u)
/** Peripheral SPI3 base pointer */
#define SPI3                                     ((SPI_Type *)SPI3_BASE)
/** Peripheral SPI4 base address */
#define SPI4_BASE                                (0x40122000u)
/** Peripheral SPI4 base pointer */
#define SPI4                                     ((SPI_Type *)SPI4_BASE)
/** Peripheral SPI5 base address */
#define SPI5_BASE                                (0x40123000u)
/** Peripheral SPI5 base pointer */
#define SPI5                                     ((SPI_Type *)SPI5_BASE)
/** Peripheral SPI6 base address */
#define SPI6_BASE                                (0x40124000u)
/** Peripheral SPI6 base pointer */
#define SPI6                                     ((SPI_Type *)SPI6_BASE)
/** Peripheral SPI7 base address */
#define SPI7_BASE                                (0x40125000u)
/** Peripheral SPI7 base pointer */
#define SPI7                                     ((SPI_Type *)SPI7_BASE)
/** Peripheral SPI8 base address */
#define SPI8_BASE                                (0x40209000u)
/** Peripheral SPI8 base pointer */
#define SPI8                                     ((SPI_Type *)SPI8_BASE)
/** Peripheral SPI9 base address */
#define SPI9_BASE                                (0x4020A000u)
/** Peripheral SPI9 base pointer */
#define SPI9                                     ((SPI_Type *)SPI9_BASE)
/** Peripheral SPI10 base address */
#define SPI10_BASE                               (0x4020B000u)
/** Peripheral SPI10 base pointer */
#define SPI10                                    ((SPI_Type *)SPI10_BASE)
/** Peripheral SPI11 base address */
#define SPI11_BASE                               (0x4020C000u)
/** Peripheral SPI11 base pointer */
#define SPI11                                    ((SPI_Type *)SPI11_BASE)
/** Peripheral SPI12 base address */
#define SPI12_BASE                               (0x4020D000u)
/** Peripheral SPI12 base pointer */
#define SPI12                                    ((SPI_Type *)SPI12_BASE)
/** Peripheral SPI13 base address */
#define SPI13_BASE                               (0x4020E000u)
/** Peripheral SPI13 base pointer */
#define SPI13                                    ((SPI_Type *)SPI13_BASE)
/** Peripheral SPI14 base address */
#define SPI14_BASE                               (0x40126000u)
/** Peripheral SPI14 base pointer */
#define SPI14                                    ((SPI_Type *)SPI14_BASE)
/** Peripheral SPI16 base address */
#define SPI16_BASE                               (0x40128000u)
/** Peripheral SPI16 base pointer */
#define SPI16                                    ((SPI_Type *)SPI16_BASE)
/** Array initializer of SPI peripheral base addresses */
#define SPI_BASE_ADDRS                           { SPI0_BASE, SPI1_BASE, SPI2_BASE, SPI3_BASE, SPI4_BASE, SPI5_BASE, SPI6_BASE, SPI7_BASE, SPI8_BASE, SPI9_BASE, SPI10_BASE, SPI11_BASE, SPI12_BASE, SPI13_BASE, SPI14_BASE, SPI16_BASE }
/** Array initializer of SPI peripheral base pointers */
#define SPI_BASE_PTRS                            { SPI0, SPI1, SPI2, SPI3, SPI4, SPI5, SPI6, SPI7, SPI8, SPI9, SPI10, SPI11, SPI12, SPI13, SPI14, SPI16 }
/** Interrupt vectors for the SPI peripheral type */
#define SPI_IRQS                                 { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, FLEXCOMM14_IRQn, FLEXCOMM16_IRQn }

/* SYSCTL0 - Peripheral instance base addresses */
/** Peripheral SYSCTL0 base address */
#define SYSCTL0_BASE                             (0x40002000u)
/** Peripheral SYSCTL0 base pointer */
#define SYSCTL0                                  ((SYSCTL0_Type *)SYSCTL0_BASE)
/** Array initializer of SYSCTL0 peripheral base addresses */
#define SYSCTL0_BASE_ADDRS                       { SYSCTL0_BASE }
/** Array initializer of SYSCTL0 peripheral base pointers */
#define SYSCTL0_BASE_PTRS                        { SYSCTL0 }

/* SYSCTL1 - Peripheral instance base addresses */
/** Peripheral SYSCTL1 base address */
#define SYSCTL1_BASE                             (0x40022000u)
/** Peripheral SYSCTL1 base pointer */
#define SYSCTL1                                  ((SYSCTL1_Type *)SYSCTL1_BASE)
/** Array initializer of SYSCTL1 peripheral base addresses */
#define SYSCTL1_BASE_ADDRS                       { SYSCTL1_BASE }
/** Array initializer of SYSCTL1 peripheral base pointers */
#define SYSCTL1_BASE_PTRS                        { SYSCTL1 }

/* TRNG - Peripheral instance base addresses */
/** Peripheral TRNG base address */
#define TRNG_BASE                                (0x40138000u)
/** Peripheral TRNG base pointer */
#define TRNG                                     ((TRNG_Type *)TRNG_BASE)
/** Array initializer of TRNG peripheral base addresses */
#define TRNG_BASE_ADDRS                          { TRNG_BASE }
/** Array initializer of TRNG peripheral base pointers */
#define TRNG_BASE_PTRS                           { TRNG }

/* USART - Peripheral instance base addresses */
/** Peripheral USART0 base address */
#define USART0_BASE                              (0x40106000u)
/** Peripheral USART0 base pointer */
#define USART0                                   ((USART_Type *)USART0_BASE)
/** Peripheral USART1 base address */
#define USART1_BASE                              (0x40107000u)
/** Peripheral USART1 base pointer */
#define USART1                                   ((USART_Type *)USART1_BASE)
/** Peripheral USART2 base address */
#define USART2_BASE                              (0x40108000u)
/** Peripheral USART2 base pointer */
#define USART2                                   ((USART_Type *)USART2_BASE)
/** Peripheral USART3 base address */
#define USART3_BASE                              (0x40109000u)
/** Peripheral USART3 base pointer */
#define USART3                                   ((USART_Type *)USART3_BASE)
/** Peripheral USART4 base address */
#define USART4_BASE                              (0x40122000u)
/** Peripheral USART4 base pointer */
#define USART4                                   ((USART_Type *)USART4_BASE)
/** Peripheral USART5 base address */
#define USART5_BASE                              (0x40123000u)
/** Peripheral USART5 base pointer */
#define USART5                                   ((USART_Type *)USART5_BASE)
/** Peripheral USART6 base address */
#define USART6_BASE                              (0x40124000u)
/** Peripheral USART6 base pointer */
#define USART6                                   ((USART_Type *)USART6_BASE)
/** Peripheral USART7 base address */
#define USART7_BASE                              (0x40125000u)
/** Peripheral USART7 base pointer */
#define USART7                                   ((USART_Type *)USART7_BASE)
/** Peripheral USART8 base address */
#define USART8_BASE                              (0x40209000u)
/** Peripheral USART8 base pointer */
#define USART8                                   ((USART_Type *)USART8_BASE)
/** Peripheral USART9 base address */
#define USART9_BASE                              (0x4020A000u)
/** Peripheral USART9 base pointer */
#define USART9                                   ((USART_Type *)USART9_BASE)
/** Peripheral USART10 base address */
#define USART10_BASE                             (0x4020B000u)
/** Peripheral USART10 base pointer */
#define USART10                                  ((USART_Type *)USART10_BASE)
/** Peripheral USART11 base address */
#define USART11_BASE                             (0x4020C000u)
/** Peripheral USART11 base pointer */
#define USART11                                  ((USART_Type *)USART11_BASE)
/** Peripheral USART12 base address */
#define USART12_BASE                             (0x4020D000u)
/** Peripheral USART12 base pointer */
#define USART12                                  ((USART_Type *)USART12_BASE)
/** Peripheral USART13 base address */
#define USART13_BASE                             (0x4020E000u)
/** Peripheral USART13 base pointer */
#define USART13                                  ((USART_Type *)USART13_BASE)
/** Array initializer of USART peripheral base addresses */
#define USART_BASE_ADDRS                         { USART0_BASE, USART1_BASE, USART2_BASE, USART3_BASE, USART4_BASE, USART5_BASE, USART6_BASE, USART7_BASE, USART8_BASE, USART9_BASE, USART10_BASE, USART11_BASE, USART12_BASE, USART13_BASE }
/** Array initializer of USART peripheral base pointers */
#define USART_BASE_PTRS                          { USART0, USART1, USART2, USART3, USART4, USART5, USART6, USART7, USART8, USART9, USART10, USART11, USART12, USART13 }
/** Interrupt vectors for the USART peripheral type */
#define USART_IRQS                               { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* USBHSDCD - Peripheral instance base addresses */
/** Peripheral USBHSDCD base address */
#define USBHSDCD_BASE                            (0x4013B800u)
/** Peripheral USBHSDCD base pointer */
#define USBHSDCD                                 ((USBHSDCD_Type *)USBHSDCD_BASE)
/** Array initializer of USBHSDCD peripheral base addresses */
#define USBHSDCD_BASE_ADDRS                      { USBHSDCD_BASE }
/** Array initializer of USBHSDCD peripheral base pointers */
#define USBHSDCD_BASE_PTRS                       { USBHSDCD }

/* USBPHY - Peripheral instance base addresses */
/** Peripheral USBPHY base address */
#define USBPHY_BASE                              (0x4013B000u)
/** Peripheral USBPHY base pointer */
#define USBPHY                                   ((USBPHY_Type *)USBPHY_BASE)
/** Array initializer of USBPHY peripheral base addresses */
#define USBPHY_BASE_ADDRS                        { USBPHY_BASE }
/** Array initializer of USBPHY peripheral base pointers */
#define USBPHY_BASE_PTRS                         { USBPHY }

/* USDHC - Peripheral instance base addresses */
/** Peripheral USDHC0 base address */
#define USDHC0_BASE                              (0x40136000u)
/** Peripheral USDHC0 base pointer */
#define USDHC0                                   ((USDHC_Type *)USDHC0_BASE)
/** Peripheral USDHC1 base address */
#define USDHC1_BASE                              (0x40137000u)
/** Peripheral USDHC1 base pointer */
#define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
/** Array initializer of USDHC peripheral base addresses */
#define USDHC_BASE_ADDRS                         { USDHC0_BASE, USDHC1_BASE }
/** Array initializer of USDHC peripheral base pointers */
#define USDHC_BASE_PTRS                          { USDHC0, USDHC1 }

/* UTICK - Peripheral instance base addresses */
/** Peripheral UTICK0 base address */
#define UTICK0_BASE                              (0x4000F000u)
/** Peripheral UTICK0 base pointer */
#define UTICK0                                   ((UTICK_Type *)UTICK0_BASE)
/** Array initializer of UTICK peripheral base addresses */
#define UTICK_BASE_ADDRS                         { UTICK0_BASE }
/** Array initializer of UTICK peripheral base pointers */
#define UTICK_BASE_PTRS                          { UTICK0 }
/** Interrupt vectors for the UTICK peripheral type */
#define UTICK_IRQS                               { UTICK0_IRQn }

/* WWDT - Peripheral instance base addresses */
/** Peripheral WWDT0 base address */
#define WWDT0_BASE                               (0x4000E000u)
/** Peripheral WWDT0 base pointer */
#define WWDT0                                    ((WWDT_Type *)WWDT0_BASE)
/** Peripheral WWDT1 base address */
#define WWDT1_BASE                               (0x4002E000u)
/** Peripheral WWDT1 base pointer */
#define WWDT1                                    ((WWDT_Type *)WWDT1_BASE)
/** Array initializer of WWDT peripheral base addresses */
#define WWDT_BASE_ADDRS                          { WWDT0_BASE, WWDT1_BASE }
/** Array initializer of WWDT peripheral base pointers */
#define WWDT_BASE_PTRS                           { WWDT0, WWDT1 }
/** Interrupt vectors for the WWDT peripheral type */
#define WWDT_IRQS                                { NotAvail_IRQn, WDT1_IRQn }

/* ----------------------------------------------------------------------------
   -- Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Bit_Field_Generic_Macros Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
 * @{
 */

/**
 * @brief Mask and left-shift a bit field value for use in a register bit range.
 * @param field Name of the register bit field.
 * @param value Value of the bit field.
 * @return Masked and shifted value.
 */
#define NXP_VAL2FLD(field, value)    (((value) << (field ## _SHIFT)) & (field ## _MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field ## _MASK)) >> (field ## _SHIFT))

/*!
 * @}
 */ /* end of group Bit_Field_Generic_Macros */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/**  Used for get the base address of ROM API */
#define FSL_ROM_API_BASE_ADDR 0x1302F000U

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* MIMXRT595S_DSP_COMMON_H_ */

