/*
** ###################################################################
**     Processors:          MCXA345VLH
**                          MCXA345VLL
**                          MCXA345VLQ
**                          MCXA345VPN
**
**     Compilers:
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXAP144M180FS6_RM_Rev.1
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCXA345
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-21)
**         Initial version based on Rev1 RM
**
** ###################################################################
*/

/*!
 * @file MCXA345_COMMON.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for MCXA345
 *
 * CMSIS Peripheral Access Layer for MCXA345
 */

#if !defined(MCXA345_COMMON_H_)
#define MCXA345_COMMON_H_                        /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 138                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M33 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M33 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M33 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M33 Usage Fault Interrupt */
  SecureFault_IRQn             = -9,               /**< Cortex-M33 Secure Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M33 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M33 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M33 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M33 System Tick Interrupt */

  /* Device specific interrupts */
  Reserved16_IRQn              = 0,                /**< OR IRQ1 to IRQ53 */
  CMC_IRQn                     = 1,                /**< Core Mode Controller interrupt */
  DMA_CH0_IRQn                 = 2,                /**< DMA3_0_CH0 error or transfer complete */
  DMA_CH1_IRQn                 = 3,                /**< DMA3_0_CH1 error or transfer complete */
  DMA_CH2_IRQn                 = 4,                /**< DMA3_0_CH2 error or transfer complete */
  DMA_CH3_IRQn                 = 5,                /**< DMA3_0_CH3 error or transfer complete */
  DMA_CH4_IRQn                 = 6,                /**< DMA3_0_CH4 error or transfer complete */
  DMA_CH5_IRQn                 = 7,                /**< DMA3_0_CH5 error or transfer complete */
  DMA_CH6_IRQn                 = 8,                /**< DMA3_0_CH6 error or transfer complete */
  DMA_CH7_IRQn                 = 9,                /**< DMA3_0_CH7 error or transfer complete */
  ERM0_SINGLE_BIT_IRQn         = 10,               /**< ERM Single Bit error interrupt */
  ERM0_MULTI_BIT_IRQn          = 11,               /**< ERM Multi Bit error interrupt */
  FMU0_IRQn                    = 12,               /**< Flash Management Unit interrupt */
  GLIKEY0_IRQn                 = 13,               /**< GLIKEY Interrupt  */
  MBC0_IRQn                    = 14,               /**< MBC secure violation interrupt */
  SCG0_IRQn                    = 15,               /**< System Clock Generator interrupt */
  SPC0_IRQn                    = 16,               /**< System Power Controller interrupt */
  Reserved33_IRQn              = 17,               /**< Reserved interrupt */
  WUU0_IRQn                    = 18,               /**< Wake Up Unit interrupt */
  CAN0_IRQn                    = 19,               /**< Controller Area Network 0 interrupt */
  Reserved36_IRQn              = 20,               /**< Reserved interrupt */
  Reserved39_IRQn              = 23,               /**< Reserved interrupt */
  Reserved40_IRQn              = 24,               /**< Reserved interrupt */
  LPI2C0_IRQn                  = 26,               /**< Low-Power Inter Integrated Circuit 0 interrupt */
  LPI2C1_IRQn                  = 27,               /**< Low-Power Inter Integrated Circuit 1 interrupt */
  LPSPI0_IRQn                  = 28,               /**< Low-Power Serial Peripheral Interface 0 interrupt */
  LPSPI1_IRQn                  = 29,               /**< Low-Power Serial Peripheral Interface 1 interrupt */
  LPUART0_IRQn                 = 31,               /**< Low-Power Universal Asynchronous Receive/Transmit 0 interrupt */
  LPUART1_IRQn                 = 32,               /**< Low-Power Universal Asynchronous Receive/Transmit 1 interrupt */
  LPUART2_IRQn                 = 33,               /**< Low-Power Universal Asynchronous Receive/Transmit 2 interrupt */
  LPUART3_IRQn                 = 34,               /**< Low-Power Universal Asynchronous Receive/Transmit 3 interrupt */
  LPUART4_IRQn                 = 35,               /**< Low-Power Universal Asynchronous Receive/Transmit 4 interrupt */
  Reserved52_IRQn              = 36,               /**< Reserved interrupt */
  CDOG0_IRQn                   = 38,               /**< Code Watchdog Timer 0 interrupt */
  CTIMER0_IRQn                 = 39,               /**< Standard counter/timer 0 interrupt */
  CTIMER1_IRQn                 = 40,               /**< Standard counter/timer 1 interrupt */
  CTIMER2_IRQn                 = 41,               /**< Standard counter/timer 2 interrupt */
  CTIMER3_IRQn                 = 42,               /**< Standard counter/timer 3 interrupt */
  CTIMER4_IRQn                 = 43,               /**< Standard counter/timer 4 interrupt */
  FLEXPWM0_RELOAD_ERROR_IRQn   = 44,               /**< FlexPWM0_reload_error interrupt */
  FLEXPWM0_FAULT_IRQn          = 45,               /**< FlexPWM0_fault interrupt */
  FLEXPWM0_SUBMODULE0_IRQn     = 46,               /**< FlexPWM0 Submodule 0 capture/compare/reload interrupt */
  FLEXPWM0_SUBMODULE1_IRQn     = 47,               /**< FlexPWM0 Submodule 1 capture/compare/reload interrupt */
  FLEXPWM0_SUBMODULE2_IRQn     = 48,               /**< FlexPWM0 Submodule 2 capture/compare/reload interrupt */
  FLEXPWM0_SUBMODULE3_IRQn     = 49,               /**< FlexPWM0 Submodule 3 capture/compare/reload interrupt */
  EQDC0_COMPARE_IRQn           = 50,               /**< Compare */
  EQDC0_HOME_IRQn              = 51,               /**< Home */
  EQDC0_WATCHDOG_IRQn          = 52,               /**< Watchdog / Simultaneous A and B Change */
  EQDC0_INDEX_IRQn             = 53,               /**< Index / Roll Over / Roll Under */
  FREQME0_IRQn                 = 54,               /**< Frequency Measurement interrupt */
  LPTMR0_IRQn                  = 55,               /**< Low Power Timer 0 interrupt */
  OS_EVENT_IRQn                = 57,               /**< OS event timer interrupt */
  WAKETIMER0_IRQn              = 58,               /**< Wake Timer Interrupt */
  UTICK0_IRQn                  = 59,               /**< Micro-Tick Timer interrupt */
  WWDT0_IRQn                   = 60,               /**< Windowed Watchdog Timer 0 interrupt */
  ADC0_IRQn                    = 62,               /**< Analog-to-Digital Converter 0 interrupt */
  ADC1_IRQn                    = 63,               /**< Analog-to-Digital Converter 1 interrupt */
  CMP0_IRQn                    = 64,               /**< Comparator 0 interrupt */
  CMP1_IRQn                    = 65,               /**< Comparator 1 interrupt */
  CMP2_IRQn                    = 66,               /**< Comparator 2 interrupt */
  DAC0_IRQn                    = 67,               /**< Digital-to-Analog Converter 0 - General Purpose interrupt */
  GPIO0_IRQn                   = 71,               /**< General Purpose Input/Output interrupt 0 */
  GPIO1_IRQn                   = 72,               /**< General Purpose Input/Output interrupt 1 */
  GPIO2_IRQn                   = 73,               /**< General Purpose Input/Output interrupt 2 */
  GPIO3_IRQn                   = 74,               /**< General Purpose Input/Output interrupt 3 */
  GPIO4_IRQn                   = 75,               /**< General Purpose Input/Output interrupt 4 */
  LPI2C2_IRQn                  = 77,               /**< Low-Power Inter Integrated Circuit 2 interrupt */
  LPI2C3_IRQn                  = 78,               /**< Low-Power Inter Integrated Circuit 3 interrupt */
  FLEXPWM1_RELOAD_ERROR_IRQn   = 79,               /**< FlexPWM1_reload_error interrupt */
  FLEXPWM1_FAULT_IRQn          = 80,               /**< FlexPWM1_fault interrupt */
  FLEXPWM1_SUBMODULE0_IRQn     = 81,               /**< FlexPWM1 Submodule 0 capture/compare/reload interrupt */
  FLEXPWM1_SUBMODULE1_IRQn     = 82,               /**< FlexPWM1 Submodule 1 capture/compare/reload interrupt */
  FLEXPWM1_SUBMODULE2_IRQn     = 83,               /**< FlexPWM1 Submodule 2 capture/compare/reload interrupt */
  FLEXPWM1_SUBMODULE3_IRQn     = 84,               /**< FlexPWM1 Submodule 3 capture/compare/reload interrupt */
  EQDC1_COMPARE_IRQn           = 85,               /**< Compare */
  EQDC1_HOME_IRQn              = 86,               /**< Home */
  EQDC1_WATCHDOG_IRQn          = 87,               /**< Watchdog / Simultaneous A and B Change */
  EQDC1_INDEX_IRQn             = 88,               /**< Index / Roll Over / Roll Under */
  LPUART5_IRQn                 = 95,               /**< Low-Power Universal Asynchronous Receive/Transmit interrupt */
  MAU_IRQn                     = 107,              /**< MAU interrupt */
  SMARTDMA_IRQn                = 108,              /**< SmartDMA interrupt */
  Reserved125_IRQn             = 109,              /**< Reserved interrupt */
  Reserved126_IRQn             = 110,              /**< Reserved interrupt */
  Reserved127_IRQn             = 111,              /**< Reserved interrupt */
  Reserved129_IRQn             = 113,              /**< Reserved interrupt */
  Reserved130_IRQn             = 114,              /**< Reserved interrupt */
  ADC2_IRQn                    = 116,              /**< Analog-to-Digital Converter 2 interrupt */
  ADC3_IRQn                    = 117,              /**< Analog-to-Digital Converter 3 interrupt */
  RTC_IRQn                     = 119,              /**< RTC alarm interrupt */
  RTC_1HZ_IRQn                 = 120,              /**< RTC 1Hz interrupt */
  Reserved137_IRQn             = 121               /**< Reserved interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M33 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M33 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               3         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */
#define __DSP_PRESENT                  1         /**< Defines if Armv8-M Mainline core supports DSP instructions */
#define __SAUREGION_PRESENT            0         /**< Defines if an SAU is present or not */

#include "core_cm33.h"                 /* Core Peripheral Access Layer */
#include "system_MCXA345.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MCXA345_SERIES
#define MCXA345_SERIES
#endif
/* CPU specific feature definitions */
#include "MCXA345_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x400AF000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Peripheral ADC1 base address */
#define ADC1_BASE                                (0x400B0000u)
/** Peripheral ADC1 base pointer */
#define ADC1                                     ((ADC_Type *)ADC1_BASE)
/** Peripheral ADC2 base address */
#define ADC2_BASE                                (0x400F0000u)
/** Peripheral ADC2 base pointer */
#define ADC2                                     ((ADC_Type *)ADC2_BASE)
/** Peripheral ADC3 base address */
#define ADC3_BASE                                (0x400F1000u)
/** Peripheral ADC3 base pointer */
#define ADC3                                     ((ADC_Type *)ADC3_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE, ADC1_BASE, ADC2_BASE, ADC3_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0, ADC1, ADC2, ADC3 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn, ADC1_IRQn, ADC2_IRQn, ADC3_IRQn }

/* AOI - Peripheral instance base addresses */
/** Peripheral AOI0 base address */
#define AOI0_BASE                                (0x40089000u)
/** Peripheral AOI0 base pointer */
#define AOI0                                     ((AOI_Type *)AOI0_BASE)
/** Peripheral AOI1 base address */
#define AOI1_BASE                                (0x40097000u)
/** Peripheral AOI1 base pointer */
#define AOI1                                     ((AOI_Type *)AOI1_BASE)
/** Array initializer of AOI peripheral base addresses */
#define AOI_BASE_ADDRS                           { AOI0_BASE, AOI1_BASE }
/** Array initializer of AOI peripheral base pointers */
#define AOI_BASE_PTRS                            { AOI0, AOI1 }

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base address */
#define CAN0_BASE                                (0x400CC000u)
/** Peripheral CAN0 base pointer */
#define CAN0                                     ((CAN_Type *)CAN0_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { CAN0_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { CAN0 }
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { CAN0_IRQn }
#define CAN_Tx_Warning_IRQS                      { CAN0_IRQn }
#define CAN_Wake_Up_IRQS                         { CAN0_IRQn }
#define CAN_Error_IRQS                           { CAN0_IRQn }
#define CAN_Bus_Off_IRQS                         { CAN0_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { CAN0_IRQn }

/* CDOG - Peripheral instance base addresses */
/** Peripheral CDOG0 base address */
#define CDOG0_BASE                               (0x40100000u)
/** Peripheral CDOG0 base pointer */
#define CDOG0                                    ((CDOG_Type *)CDOG0_BASE)
/** Array initializer of CDOG peripheral base addresses */
#define CDOG_BASE_ADDRS                          { CDOG0_BASE }
/** Array initializer of CDOG peripheral base pointers */
#define CDOG_BASE_PTRS                           { CDOG0 }
/** Interrupt vectors for the CDOG peripheral type */
#define CDOG_IRQS                                { CDOG0_IRQn }

/* CMC - Peripheral instance base addresses */
/** Peripheral CMC base address */
#define CMC_BASE                                 (0x4008B000u)
/** Peripheral CMC base pointer */
#define CMC                                      ((CMC_Type *)CMC_BASE)
/** Array initializer of CMC peripheral base addresses */
#define CMC_BASE_ADDRS                           { CMC_BASE }
/** Array initializer of CMC peripheral base pointers */
#define CMC_BASE_PTRS                            { CMC }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC0 base address */
#define CRC0_BASE                                (0x4008A000u)
/** Peripheral CRC0 base pointer */
#define CRC0                                     ((CRC_Type *)CRC0_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC0_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC0 }

/* CTIMER - Peripheral instance base addresses */
/** Peripheral CTIMER0 base address */
#define CTIMER0_BASE                             (0x40004000u)
/** Peripheral CTIMER0 base pointer */
#define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
/** Peripheral CTIMER1 base address */
#define CTIMER1_BASE                             (0x40005000u)
/** Peripheral CTIMER1 base pointer */
#define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
/** Peripheral CTIMER2 base address */
#define CTIMER2_BASE                             (0x40006000u)
/** Peripheral CTIMER2 base pointer */
#define CTIMER2                                  ((CTIMER_Type *)CTIMER2_BASE)
/** Peripheral CTIMER3 base address */
#define CTIMER3_BASE                             (0x40007000u)
/** Peripheral CTIMER3 base pointer */
#define CTIMER3                                  ((CTIMER_Type *)CTIMER3_BASE)
/** Peripheral CTIMER4 base address */
#define CTIMER4_BASE                             (0x40008000u)
/** Peripheral CTIMER4 base pointer */
#define CTIMER4                                  ((CTIMER_Type *)CTIMER4_BASE)
/** Array initializer of CTIMER peripheral base addresses */
#define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE, CTIMER2_BASE, CTIMER3_BASE, CTIMER4_BASE }
/** Array initializer of CTIMER peripheral base pointers */
#define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1, CTIMER2, CTIMER3, CTIMER4 }
/** Interrupt vectors for the CTIMER peripheral type */
#define CTIMER_IRQS                              { CTIMER0_IRQn, CTIMER1_IRQn, CTIMER2_IRQn, CTIMER3_IRQn, CTIMER4_IRQn }

/* DEBUGMAILBOX - Peripheral instance base addresses */
/** Peripheral DBGMAILBOX base address */
#define DBGMAILBOX_BASE                          (0x40101000u)
/** Peripheral DBGMAILBOX base pointer */
#define DBGMAILBOX                               ((DEBUGMAILBOX_Type *)DBGMAILBOX_BASE)
/** Array initializer of DEBUGMAILBOX peripheral base addresses */
#define DEBUGMAILBOX_BASE_ADDRS                  { DBGMAILBOX_BASE }
/** Array initializer of DEBUGMAILBOX peripheral base pointers */
#define DEBUGMAILBOX_BASE_PTRS                   { DBGMAILBOX }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x40080000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0 }

/* EIM - Peripheral instance base addresses */
/** Peripheral EIM0 base address */
#define EIM0_BASE                                (0x4008C000u)
/** Peripheral EIM0 base pointer */
#define EIM0                                     ((EIM_Type *)EIM0_BASE)
/** Array initializer of EIM peripheral base addresses */
#define EIM_BASE_ADDRS                           { EIM0_BASE }
/** Array initializer of EIM peripheral base pointers */
#define EIM_BASE_PTRS                            { EIM0 }

/* EQDC - Peripheral instance base addresses */
/** Peripheral EQDC0 base address */
#define EQDC0_BASE                               (0x400A7000u)
/** Peripheral EQDC0 base pointer */
#define EQDC0                                    ((EQDC_Type *)EQDC0_BASE)
/** Peripheral EQDC1 base address */
#define EQDC1_BASE                               (0x400A8000u)
/** Peripheral EQDC1 base pointer */
#define EQDC1                                    ((EQDC_Type *)EQDC1_BASE)
/** Array initializer of EQDC peripheral base addresses */
#define EQDC_BASE_ADDRS                          { EQDC0_BASE, EQDC1_BASE }
/** Array initializer of EQDC peripheral base pointers */
#define EQDC_BASE_PTRS                           { EQDC0, EQDC1 }
/** Interrupt vectors for the EQDC peripheral type */
#define EQDC_COMPARE_IRQS                        { EQDC0_COMPARE_IRQn, EQDC1_COMPARE_IRQn }
#define EQDC_HOME_IRQS                           { EQDC0_HOME_IRQn, EQDC1_HOME_IRQn }
#define EQDC_WDOG_IRQS                           { EQDC0_WATCHDOG_IRQn, EQDC1_WATCHDOG_IRQn }
#define EQDC_INDEX_IRQS                          { EQDC0_INDEX_IRQn, EQDC1_INDEX_IRQn }
#define EQDC_INPUT_SWITCH_IRQS                   { EQDC0_WATCHDOG_IRQn, EQDC1_WATCHDOG_IRQn }

/* ERM - Peripheral instance base addresses */
/** Peripheral ERM0 base address */
#define ERM0_BASE                                (0x4008D000u)
/** Peripheral ERM0 base pointer */
#define ERM0                                     ((ERM_Type *)ERM0_BASE)
/** Array initializer of ERM peripheral base addresses */
#define ERM_BASE_ADDRS                           { ERM0_BASE }
/** Array initializer of ERM peripheral base pointers */
#define ERM_BASE_PTRS                            { ERM0 }

/* FMC - Peripheral instance base addresses */
/** Peripheral FMC0 base address */
#define FMC0_BASE                                (0x40094000u)
/** Peripheral FMC0 base pointer */
#define FMC0                                     ((FMC_Type *)FMC0_BASE)
/** Array initializer of FMC peripheral base addresses */
#define FMC_BASE_ADDRS                           { FMC0_BASE }
/** Array initializer of FMC peripheral base pointers */
#define FMC_BASE_PTRS                            { FMC0 }

/* FMU - Peripheral instance base addresses */
/** Peripheral FMU0 base address */
#define FMU0_BASE                                (0x40095000u)
/** Peripheral FMU0 base pointer */
#define FMU0                                     ((FMU_Type *)FMU0_BASE)
/** Array initializer of FMU peripheral base addresses */
#define FMU_BASE_ADDRS                           { FMU0_BASE }
/** Array initializer of FMU peripheral base pointers */
#define FMU_BASE_PTRS                            { FMU0 }

/* FREQME - Peripheral instance base addresses */
/** Peripheral FREQME0 base address */
#define FREQME0_BASE                             (0x40009000u)
/** Peripheral FREQME0 base pointer */
#define FREQME0                                  ((FREQME_Type *)FREQME0_BASE)
/** Array initializer of FREQME peripheral base addresses */
#define FREQME_BASE_ADDRS                        { FREQME0_BASE }
/** Array initializer of FREQME peripheral base pointers */
#define FREQME_BASE_PTRS                         { FREQME0 }

/* GLIKEY - Peripheral instance base addresses */
/** Peripheral GLIKEY0 base address */
#define GLIKEY0_BASE                             (0x40091D00u)
/** Peripheral GLIKEY0 base pointer */
#define GLIKEY0                                  ((GLIKEY_Type *)GLIKEY0_BASE)
/** Array initializer of GLIKEY peripheral base addresses */
#define GLIKEY_BASE_ADDRS                        { GLIKEY0_BASE }
/** Array initializer of GLIKEY peripheral base pointers */
#define GLIKEY_BASE_PTRS                         { GLIKEY0 }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO0 base address */
#define GPIO0_BASE                               (0x40102000u)
/** Peripheral GPIO0 base pointer */
#define GPIO0                                    ((GPIO_Type *)GPIO0_BASE)
/** Peripheral GPIO1 base address */
#define GPIO1_BASE                               (0x40103000u)
/** Peripheral GPIO1 base pointer */
#define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
/** Peripheral GPIO2 base address */
#define GPIO2_BASE                               (0x40104000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO3 base address */
#define GPIO3_BASE                               (0x40105000u)
/** Peripheral GPIO3 base pointer */
#define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
/** Peripheral GPIO4 base address */
#define GPIO4_BASE                               (0x40106000u)
/** Peripheral GPIO4 base pointer */
#define GPIO4                                    ((GPIO_Type *)GPIO4_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIO0_BASE, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIO0, GPIO1, GPIO2, GPIO3, GPIO4 }
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS                                { GPIO0_IRQn, GPIO1_IRQn, GPIO2_IRQn, GPIO3_IRQn, GPIO4_IRQn }

/* INPUTMUX - Peripheral instance base addresses */
/** Peripheral INPUTMUX0 base address */
#define INPUTMUX0_BASE                           (0x40001000u)
/** Peripheral INPUTMUX0 base pointer */
#define INPUTMUX0                                ((INPUTMUX_Type *)INPUTMUX0_BASE)
/** Array initializer of INPUTMUX peripheral base addresses */
#define INPUTMUX_BASE_ADDRS                      { INPUTMUX0_BASE }
/** Array initializer of INPUTMUX peripheral base pointers */
#define INPUTMUX_BASE_PTRS                       { INPUTMUX0 }

/* LPCMP - Peripheral instance base addresses */
/** Peripheral CMP0 base address */
#define CMP0_BASE                                (0x400B1000u)
/** Peripheral CMP0 base pointer */
#define CMP0                                     ((LPCMP_Type *)CMP0_BASE)
/** Peripheral CMP1 base address */
#define CMP1_BASE                                (0x400B2000u)
/** Peripheral CMP1 base pointer */
#define CMP1                                     ((LPCMP_Type *)CMP1_BASE)
/** Peripheral CMP2 base address */
#define CMP2_BASE                                (0x400B3000u)
/** Peripheral CMP2 base pointer */
#define CMP2                                     ((LPCMP_Type *)CMP2_BASE)
/** Array initializer of LPCMP peripheral base addresses */
#define LPCMP_BASE_ADDRS                         { CMP0_BASE, CMP1_BASE, CMP2_BASE }
/** Array initializer of LPCMP peripheral base pointers */
#define LPCMP_BASE_PTRS                          { CMP0, CMP1, CMP2 }

/* LPDAC - Peripheral instance base addresses */
/** Peripheral DAC0 base address */
#define DAC0_BASE                                (0x400B4000u)
/** Peripheral DAC0 base pointer */
#define DAC0                                     ((LPDAC_Type *)DAC0_BASE)
/** Array initializer of LPDAC peripheral base addresses */
#define LPDAC_BASE_ADDRS                         { DAC0_BASE }
/** Array initializer of LPDAC peripheral base pointers */
#define LPDAC_BASE_PTRS                          { DAC0 }
/** Interrupt vectors for the LPDAC peripheral type */
#define LPDAC_IRQS                               { DAC0_IRQn }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x4009A000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x4009B000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x400D4000u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
/** Peripheral LPI2C3 base address */
#define LPI2C3_BASE                              (0x400D5000u)
/** Peripheral LPI2C3 base pointer */
#define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2, LPI2C3 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x4009C000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x4009D000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn }

/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0x400AB000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR0_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0 }
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x4009F000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x400A0000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x400A1000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Peripheral LPUART3 base address */
#define LPUART3_BASE                             (0x400A2000u)
/** Peripheral LPUART3 base pointer */
#define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
/** Peripheral LPUART4 base address */
#define LPUART4_BASE                             (0x400A3000u)
/** Peripheral LPUART4 base pointer */
#define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
/** Peripheral LPUART5 base address */
#define LPUART5_BASE                             (0x400DA000u)
/** Peripheral LPUART5 base pointer */
#define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn }

/* MAU - Peripheral instance base addresses */
/** Peripheral MAU0 base address */
#define MAU0_BASE                                (0x40108000u)
/** Peripheral MAU0 base pointer */
#define MAU0                                     ((MAU_Type *)MAU0_BASE)
/** Array initializer of MAU peripheral base addresses */
#define MAU_BASE_ADDRS                           { MAU0_BASE }
/** Array initializer of MAU peripheral base pointers */
#define MAU_BASE_PTRS                            { MAU0 }
/** Interrupt vectors for the MAU peripheral type */
#define MAU_IRQS                                 { MAU_IRQn }

/* MRCC - Peripheral instance base addresses */
/** Peripheral MRCC0 base address */
#define MRCC0_BASE                               (0x40091000u)
/** Peripheral MRCC0 base pointer */
#define MRCC0                                    ((MRCC_Type *)MRCC0_BASE)
/** Array initializer of MRCC peripheral base addresses */
#define MRCC_BASE_ADDRS                          { MRCC0_BASE }
/** Array initializer of MRCC peripheral base pointers */
#define MRCC_BASE_PTRS                           { MRCC0 }

/* OPAMP - Peripheral instance base addresses */
/** Peripheral OPAMP0 base address */
#define OPAMP0_BASE                              (0x400B7000u)
/** Peripheral OPAMP0 base pointer */
#define OPAMP0                                   ((OPAMP_Type *)OPAMP0_BASE)
/** Peripheral OPAMP1 base address */
#define OPAMP1_BASE                              (0x400B8000u)
/** Peripheral OPAMP1 base pointer */
#define OPAMP1                                   ((OPAMP_Type *)OPAMP1_BASE)
/** Peripheral OPAMP2 base address */
#define OPAMP2_BASE                              (0x400B9000u)
/** Peripheral OPAMP2 base pointer */
#define OPAMP2                                   ((OPAMP_Type *)OPAMP2_BASE)
/** Peripheral OPAMP3 base address */
#define OPAMP3_BASE                              (0x400BA000u)
/** Peripheral OPAMP3 base pointer */
#define OPAMP3                                   ((OPAMP_Type *)OPAMP3_BASE)
/** Array initializer of OPAMP peripheral base addresses */
#define OPAMP_BASE_ADDRS                         { OPAMP0_BASE, OPAMP1_BASE, OPAMP2_BASE, OPAMP3_BASE }
/** Array initializer of OPAMP peripheral base pointers */
#define OPAMP_BASE_PTRS                          { OPAMP0, OPAMP1, OPAMP2, OPAMP3 }

/* OSTIMER - Peripheral instance base addresses */
/** Peripheral OSTIMER0 base address */
#define OSTIMER0_BASE                            (0x400AD000u)
/** Peripheral OSTIMER0 base pointer */
#define OSTIMER0                                 ((OSTIMER_Type *)OSTIMER0_BASE)
/** Array initializer of OSTIMER peripheral base addresses */
#define OSTIMER_BASE_ADDRS                       { OSTIMER0_BASE }
/** Array initializer of OSTIMER peripheral base pointers */
#define OSTIMER_BASE_PTRS                        { OSTIMER0 }
/** Interrupt vectors for the OSTIMER peripheral type */
#define OSTIMER_IRQS                             { OS_EVENT_IRQn }

/* PORT - Peripheral instance base addresses */
/** Peripheral PORT0 base address */
#define PORT0_BASE                               (0x400BC000u)
/** Peripheral PORT0 base pointer */
#define PORT0                                    ((PORT_Type *)PORT0_BASE)
/** Peripheral PORT1 base address */
#define PORT1_BASE                               (0x400BD000u)
/** Peripheral PORT1 base pointer */
#define PORT1                                    ((PORT_Type *)PORT1_BASE)
/** Peripheral PORT2 base address */
#define PORT2_BASE                               (0x400BE000u)
/** Peripheral PORT2 base pointer */
#define PORT2                                    ((PORT_Type *)PORT2_BASE)
/** Peripheral PORT3 base address */
#define PORT3_BASE                               (0x400BF000u)
/** Peripheral PORT3 base pointer */
#define PORT3                                    ((PORT_Type *)PORT3_BASE)
/** Peripheral PORT4 base address */
#define PORT4_BASE                               (0x400C0000u)
/** Peripheral PORT4 base pointer */
#define PORT4                                    ((PORT_Type *)PORT4_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORT0_BASE, PORT1_BASE, PORT2_BASE, PORT3_BASE, PORT4_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORT0, PORT1, PORT2, PORT3, PORT4 }

/* PWM - Peripheral instance base addresses */
/** Peripheral FLEXPWM0 base address */
#define FLEXPWM0_BASE                            (0x400A9000u)
/** Peripheral FLEXPWM0 base pointer */
#define FLEXPWM0                                 ((PWM_Type *)FLEXPWM0_BASE)
/** Peripheral FLEXPWM1 base address */
#define FLEXPWM1_BASE                            (0x400AA000u)
/** Peripheral FLEXPWM1 base pointer */
#define FLEXPWM1                                 ((PWM_Type *)FLEXPWM1_BASE)
/** Array initializer of PWM peripheral base addresses */
#define PWM_BASE_ADDRS                           { FLEXPWM0_BASE, FLEXPWM1_BASE }
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASE_PTRS                            { FLEXPWM0, FLEXPWM1 }
/** Interrupt vectors for the PWM peripheral type */
#define PWM_CMP_IRQS                             { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn, FLEXPWM0_SUBMODULE3_IRQn }, { FLEXPWM1_SUBMODULE0_IRQn, FLEXPWM1_SUBMODULE1_IRQn, FLEXPWM1_SUBMODULE2_IRQn, FLEXPWM1_SUBMODULE3_IRQn } }
#define PWM_RELOAD_IRQS                          { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn, FLEXPWM0_SUBMODULE3_IRQn }, { FLEXPWM1_SUBMODULE0_IRQn, FLEXPWM1_SUBMODULE1_IRQn, FLEXPWM1_SUBMODULE2_IRQn, FLEXPWM1_SUBMODULE3_IRQn } }
#define PWM_CAPTURE_IRQS                         { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn, FLEXPWM0_SUBMODULE3_IRQn }, { FLEXPWM1_SUBMODULE0_IRQn, FLEXPWM1_SUBMODULE1_IRQn, FLEXPWM1_SUBMODULE2_IRQn, FLEXPWM1_SUBMODULE3_IRQn } }
#define PWM_FAULT_IRQS                           { FLEXPWM0_FAULT_IRQn, FLEXPWM1_FAULT_IRQn }
#define PWM_RELOAD_ERROR_IRQS                    { FLEXPWM0_RELOAD_ERROR_IRQn, FLEXPWM1_RELOAD_ERROR_IRQn }

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC0 base address */
#define RTC0_BASE                                (0x400EE000u)
/** Peripheral RTC0 base pointer */
#define RTC0                                     ((RTC_Type *)RTC0_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC0_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC0 }

/* SCG - Peripheral instance base addresses */
/** Peripheral SCG0 base address */
#define SCG0_BASE                                (0x4008F000u)
/** Peripheral SCG0 base pointer */
#define SCG0                                     ((SCG_Type *)SCG0_BASE)
/** Array initializer of SCG peripheral base addresses */
#define SCG_BASE_ADDRS                           { SCG0_BASE }
/** Array initializer of SCG peripheral base pointers */
#define SCG_BASE_PTRS                            { SCG0 }

/* SMARTDMA - Peripheral instance base addresses */
/** Peripheral SMARTDMA0 base address */
#define SMARTDMA0_BASE                           (0x4000E000u)
/** Peripheral SMARTDMA0 base pointer */
#define SMARTDMA0                                ((SMARTDMA_Type *)SMARTDMA0_BASE)
/** Array initializer of SMARTDMA peripheral base addresses */
#define SMARTDMA_BASE_ADDRS                      { SMARTDMA0_BASE }
/** Array initializer of SMARTDMA peripheral base pointers */
#define SMARTDMA_BASE_PTRS                       { SMARTDMA0 }

/* SPC - Peripheral instance base addresses */
/** Peripheral SPC0 base address */
#define SPC0_BASE                                (0x40090000u)
/** Peripheral SPC0 base pointer */
#define SPC0                                     ((SPC_Type *)SPC0_BASE)
/** Array initializer of SPC peripheral base addresses */
#define SPC_BASE_ADDRS                           { SPC0_BASE }
/** Array initializer of SPC peripheral base pointers */
#define SPC_BASE_PTRS                            { SPC0 }

/* SYSCON - Peripheral instance base addresses */
/** Peripheral SYSCON base address */
#define SYSCON_BASE                              (0x40091000u)
/** Peripheral SYSCON base pointer */
#define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
/** Array initializer of SYSCON peripheral base addresses */
#define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
/** Array initializer of SYSCON peripheral base pointers */
#define SYSCON_BASE_PTRS                         { SYSCON }

/* TRDC - Peripheral instance base addresses */
/** Peripheral MBC0 base address */
#define MBC0_BASE                                (0x4008E000u)
/** Peripheral MBC0 base pointer */
#define MBC0                                     ((TRDC_Type *)MBC0_BASE)
/** Array initializer of TRDC peripheral base addresses */
#define TRDC_BASE_ADDRS                          { MBC0_BASE }
/** Array initializer of TRDC peripheral base pointers */
#define TRDC_BASE_PTRS                           { MBC0 }
#define MBC0_MEMORY_CFG_WORD_COUNT {1,2,4,1}
#define MBC1_MEMORY_CFG_WORD_COUNT {1,1,1,1}
#define MBC2_MEMORY_CFG_WORD_COUNT {9,6,1,1}
#define MBC3_MEMORY_CFG_WORD_COUNT {3,0,0,0}
#define MBC_MEMORY_CFG_WORD_COUNT {MBC0_MEMORY_CFG_WORD_COUNT , MBC1_MEMORY_CFG_WORD_COUNT, MBC2_MEMORY_CFG_WORD_COUNT, MBC3_MEMORY_CFG_WORD_COUNT}
#define MBC0_MEMORY_NSE_WORD_COUNT {1,1,1,1}
#define MBC1_MEMORY_NSE_WORD_COUNT {1,1,1,1}
#define MBC2_MEMORY_NSE_WORD_COUNT {3,2,1,1}
#define MBC3_MEMORY_NSE_WORD_COUNT {1,0,0,0}
#define MBC_MEMORY_NSE_WORD_COUNT {MBC0_MEMORY_NSE_WORD_COUNT , MBC1_MEMORY_NSE_WORD_COUNT, MBC2_MEMORY_NSE_WORD_COUNT, MBC3_MEMORY_NSE_WORD_COUNT}


/* UDF - Peripheral instance base addresses */
/** Peripheral UDF0 base address */
#define UDF0_BASE                                (0x400ED000u)
/** Peripheral UDF0 base pointer */
#define UDF0                                     ((UDF_Type *)UDF0_BASE)
/** Array initializer of UDF peripheral base addresses */
#define UDF_BASE_ADDRS                           { UDF0_BASE }
/** Array initializer of UDF peripheral base pointers */
#define UDF_BASE_PTRS                            { UDF0 }

/* UTICK - Peripheral instance base addresses */
/** Peripheral UTICK0 base address */
#define UTICK0_BASE                              (0x4000B000u)
/** Peripheral UTICK0 base pointer */
#define UTICK0                                   ((UTICK_Type *)UTICK0_BASE)
/** Array initializer of UTICK peripheral base addresses */
#define UTICK_BASE_ADDRS                         { UTICK0_BASE }
/** Array initializer of UTICK peripheral base pointers */
#define UTICK_BASE_PTRS                          { UTICK0 }
/** Interrupt vectors for the UTICK peripheral type */
#define UTICK_IRQS                               { UTICK0_IRQn }

/* VBAT - Peripheral instance base addresses */
/** Peripheral VBAT0 base address */
#define VBAT0_BASE                               (0x40093000u)
/** Peripheral VBAT0 base pointer */
#define VBAT0                                    ((VBAT_Type *)VBAT0_BASE)
/** Array initializer of VBAT peripheral base addresses */
#define VBAT_BASE_ADDRS                          { VBAT0_BASE }
/** Array initializer of VBAT peripheral base pointers */
#define VBAT_BASE_PTRS                           { VBAT0 }

/* WAKETIMER - Peripheral instance base addresses */
/** Peripheral WAKETIMER0 base address */
#define WAKETIMER0_BASE                          (0x400AE000u)
/** Peripheral WAKETIMER0 base pointer */
#define WAKETIMER0                               ((WAKETIMER_Type *)WAKETIMER0_BASE)
/** Array initializer of WAKETIMER peripheral base addresses */
#define WAKETIMER_BASE_ADDRS                     { WAKETIMER0_BASE }
/** Array initializer of WAKETIMER peripheral base pointers */
#define WAKETIMER_BASE_PTRS                      { WAKETIMER0 }
/** Interrupt vectors for the WAKETIMER peripheral type */
#define WAKETIMER_IRQS                           { WAKETIMER0_IRQn }

/* WUU - Peripheral instance base addresses */
/** Peripheral WUU0 base address */
#define WUU0_BASE                                (0x40092000u)
/** Peripheral WUU0 base pointer */
#define WUU0                                     ((WUU_Type *)WUU0_BASE)
/** Array initializer of WUU peripheral base addresses */
#define WUU_BASE_ADDRS                           { WUU0_BASE }
/** Array initializer of WUU peripheral base pointers */
#define WUU_BASE_PTRS                            { WUU0 }

/* WWDT - Peripheral instance base addresses */
/** Peripheral WWDT0 base address */
#define WWDT0_BASE                               (0x4000C000u)
/** Peripheral WWDT0 base pointer */
#define WWDT0                                    ((WWDT_Type *)WWDT0_BASE)
/** Array initializer of WWDT peripheral base addresses */
#define WWDT_BASE_ADDRS                          { WWDT0_BASE }
/** Array initializer of WWDT peripheral base pointers */
#define WWDT_BASE_PTRS                           { WWDT0 }

/* ----------------------------------------------------------------------------
   -- Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Bit_Field_Generic_Macros Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
 * @{
 */

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang system_header
  #endif
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma system_include
#endif

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



/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* MCXA345_COMMON_H_ */

