/*
** ###################################################################
**     Processors:          MCXC161VFG
**                          MCXC161VFK
**                          MCXC161VFM
**                          MCXC161VFT
**                          MCXC161VLF
**
**     Compilers:
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXAP144M180FS6_RM_Rev.1
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b260303
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCXC161
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
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
 * @file MCXC161_COMMON.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for MCXC161
 *
 * CMSIS Peripheral Access Layer for MCXC161
 */

#if !defined(MCXC161_COMMON_H_)
#define MCXC161_COMMON_H_                        /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 91                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M23 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M23 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M23 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M23 System Tick Interrupt */

  /* Device specific interrupts */
  Reserved16_IRQn              = 0,                /**< OR IRQ1 to IRQ53 */
  CMC_IRQn                     = 1,                /**< Core Mode Controller interrupt */
  DMA_CH0_IRQn                 = 2,                /**< DMA3_0_CH0 error or transfer complete */
  DMA_CH1_IRQn                 = 3,                /**< DMA3_0_CH1 error or transfer complete */
  DMA_CH2_IRQn                 = 4,                /**< DMA3_0_CH2 error or transfer complete */
  DMA_CH3_IRQn                 = 5,                /**< DMA3_0_CH3 error or transfer complete */
  ERM0_SINGLE_BIT_IRQn         = 10,               /**< ERM Single Bit error interrupt */
  ERM0_MULTI_BIT_IRQn          = 11,               /**< ERM Multi Bit error interrupt */
  FMU0_IRQn                    = 12,               /**< Flash Management Unit interrupt */
  MBC0_IRQn                    = 14,               /**< MBC secure violation interrupt */
  SCG0_IRQn                    = 15,               /**< System Clock Generator interrupt */
  SPC0_IRQn                    = 16,               /**< System Power Controller interrupt */
  Reserved33_IRQn              = 17,               /**< Reserved interrupt */
  WUU0_IRQn                    = 18,               /**< Wake Up Unit interrupt */
  LPI2C0_IRQn                  = 26,               /**< Low-Power Inter Integrated Circuit 0 interrupt */
  LPSPI0_IRQn                  = 28,               /**< Low-Power Serial Peripheral Interface 0 interrupt */
  LPUART0_IRQn                 = 31,               /**< Low-Power Universal Asynchronous Receive/Transmit 0 interrupt */
  LPUART1_IRQn                 = 32,               /**< Low-Power Universal Asynchronous Receive/Transmit 1 interrupt */
  LPUART2_IRQn                 = 33,               /**< Low-Power Universal Asynchronous Receive/Transmit 2 interrupt */
  LPUART3_IRQn                 = 34,               /**< Low-Power Universal Asynchronous Receive/Transmit 3 interrupt */
  LPUART4_IRQn                 = 35,               /**< Low-Power Universal Asynchronous Receive/Transmit 4 interrupt */
  CTIMER0_IRQn                 = 39,               /**< Standard counter/timer 0 interrupt */
  CTIMER1_IRQn                 = 40,               /**< Standard counter/timer 1 interrupt */
  FLEXPWM0_RELOAD_ERROR_IRQn   = 44,               /**< FlexPWM0_reload_error interrupt */
  FLEXPWM0_FAULT_IRQn          = 45,               /**< FlexPWM0_fault interrupt */
  FLEXPWM0_SUBMODULE0_IRQn     = 46,               /**< FlexPWM0 Submodule 0 capture/compare/reload interrupt */
  FLEXPWM0_SUBMODULE1_IRQn     = 47,               /**< FlexPWM0 Submodule 1 capture/compare/reload interrupt */
  FLEXPWM0_SUBMODULE2_IRQn     = 48,               /**< FlexPWM0 Submodule 2 capture/compare/reload interrupt */
  EQDC0_COMPARE_IRQn           = 50,               /**< Compare */
  EQDC0_HOME_IRQn              = 51,               /**< Home */
  EQDC0_WATCHDOG_IRQn          = 52,               /**< Watchdog / Simultaneous A and B Change */
  EQDC0_INDEX_IRQn             = 53,               /**< Index / Roll Over / Roll Under */
  FREQME0_IRQn                 = 54,               /**< Frequency Measurement interrupt */
  LPTMR0_IRQn                  = 55,               /**< Low Power Timer 0 interrupt */
  RTC_IRQn                     = 58,               /**< RTC alarm interrupt */
  RTC_1HZ_IRQn                 = 59,               /**< RTC 1Hz interrupt */
  WWDT0_IRQn                   = 60,               /**< Windowed Watchdog Timer 0 interrupt */
  WWDT1_IRQn                   = 61,               /**< Windowed Watchdog Timer 1 interrupt */
  ADC0_IRQn                    = 62,               /**< Analog-to-Digital Converter 0 interrupt */
  CMP0_IRQn                    = 64,               /**< Comparator 0 interrupt */
  GPIO0_IRQn                   = 71,               /**< General Purpose Input/Output interrupt 0 */
  GPIO1_IRQn                   = 72,               /**< General Purpose Input/Output interrupt 1 */
  GPIO2_IRQn                   = 73,               /**< General Purpose Input/Output interrupt 2 */
  GPIO3_IRQn                   = 74                /**< General Purpose Input/Output interrupt 3 */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M23 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M23 Core Configuration
 * @{
 */

#define __CM23_REV                     0x0100    /**< Core revision r1p0 */
#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if VTOR is present or not */
#define __NVIC_PRIO_BITS               2         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __SAUREGION_PRESENT            0         /**< Defines if an SAU is present or not */

#include "core_cm23.h"                 /* Core Peripheral Access Layer */
#include "system_MCXC161.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MCXC161_SERIES
#define MCXC161_SERIES
#endif
/* CPU specific feature definitions */
#include "MCXC161_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x400AF000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn }

/* CMC - Peripheral instance base addresses */
/** Peripheral CMC base address */
#define CMC_BASE                                 (0x4008B000u)
/** Peripheral CMC base pointer */
#define CMC                                      ((CMC_Type *)CMC_BASE)
/** Array initializer of CMC peripheral base addresses */
#define CMC_BASE_ADDRS                           { CMC_BASE }
/** Array initializer of CMC peripheral base pointers */
#define CMC_BASE_PTRS                            { CMC }
/** Interrupt vectors for the CMC peripheral type */
#define CMC_IRQS                                 { CMC_IRQn }

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
/** Array initializer of CTIMER peripheral base addresses */
#define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE }
/** Array initializer of CTIMER peripheral base pointers */
#define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1 }
/** Interrupt vectors for the CTIMER peripheral type */
#define CTIMER_IRQS                              { CTIMER0_IRQn, CTIMER1_IRQn }

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

/* ERM - Peripheral instance base addresses */
/** Peripheral ERM0 base address */
#define ERM0_BASE                                (0x4008D000u)
/** Peripheral ERM0 base pointer */
#define ERM0                                     ((ERM_Type *)ERM0_BASE)
/** Array initializer of ERM peripheral base addresses */
#define ERM_BASE_ADDRS                           { ERM0_BASE }
/** Array initializer of ERM peripheral base pointers */
#define ERM_BASE_PTRS                            { ERM0 }

/* FMU - Peripheral instance base addresses */
/** Peripheral FMU0 base address */
#define FMU0_BASE                                (0x40095000u)
/** Peripheral FMU0 base pointer */
#define FMU0                                     ((FMU_Type *)FMU0_BASE)
/** Array initializer of FMU peripheral base addresses */
#define FMU_BASE_ADDRS                           { FMU0_BASE }
/** Array initializer of FMU peripheral base pointers */
#define FMU_BASE_PTRS                            { FMU0 }

/* FMUTEST - Peripheral instance base addresses */
/** Peripheral FMU0TEST base address */
#define FMU0TEST_BASE                            (0x40096000u)
/** Peripheral FMU0TEST base pointer */
#define FMU0TEST                                 ((FMUTEST_Type *)FMU0TEST_BASE)
/** Array initializer of FMUTEST peripheral base addresses */
#define FMUTEST_BASE_ADDRS                       { FMU0TEST_BASE }
/** Array initializer of FMUTEST peripheral base pointers */
#define FMUTEST_BASE_PTRS                        { FMU0TEST }

/* FREQME - Peripheral instance base addresses */
/** Peripheral FREQME0 base address */
#define FREQME0_BASE                             (0x40009000u)
/** Peripheral FREQME0 base pointer */
#define FREQME0                                  ((FREQME_Type *)FREQME0_BASE)
/** Array initializer of FREQME peripheral base addresses */
#define FREQME_BASE_ADDRS                        { FREQME0_BASE }
/** Array initializer of FREQME peripheral base pointers */
#define FREQME_BASE_PTRS                         { FREQME0 }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO0 base address */
#define GPIO0_BASE                               (0x400F3000u)
/** Peripheral GPIO0 base pointer */
#define GPIO0                                    ((GPIO_Type *)GPIO0_BASE)
/** Peripheral GPIO1 base address */
#define GPIO1_BASE                               (0x400F4000u)
/** Peripheral GPIO1 base pointer */
#define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
/** Peripheral GPIO2 base address */
#define GPIO2_BASE                               (0x400F5000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO3 base address */
#define GPIO3_BASE                               (0x400F6000u)
/** Peripheral GPIO3 base pointer */
#define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIO0_BASE, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIO0, GPIO1, GPIO2, GPIO3 }
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS                                { GPIO0_IRQn, GPIO1_IRQn, GPIO2_IRQn, GPIO3_IRQn }

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
/** Array initializer of LPCMP peripheral base addresses */
#define LPCMP_BASE_ADDRS                         { CMP0_BASE }
/** Array initializer of LPCMP peripheral base pointers */
#define LPCMP_BASE_PTRS                          { CMP0 }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x4009A000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x4009C000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn }

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
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn }

/* MRCC - Peripheral instance base addresses */
/** Peripheral MRCC0 base address */
#define MRCC0_BASE                               (0x40091800u)
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
/** Array initializer of OPAMP peripheral base addresses */
#define OPAMP_BASE_ADDRS                         { OPAMP0_BASE }
/** Array initializer of OPAMP peripheral base pointers */
#define OPAMP_BASE_PTRS                          { OPAMP0 }

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
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORT0_BASE, PORT1_BASE, PORT2_BASE, PORT3_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORT0, PORT1, PORT2, PORT3 }

/* PWM - Peripheral instance base addresses */
/** Peripheral FLEXPWM0 base address */
#define FLEXPWM0_BASE                            (0x400A9000u)
/** Peripheral FLEXPWM0 base pointer */
#define FLEXPWM0                                 ((PWM_Type *)FLEXPWM0_BASE)
/** Array initializer of PWM peripheral base addresses */
#define PWM_BASE_ADDRS                           { FLEXPWM0_BASE }
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASE_PTRS                            { FLEXPWM0 }
/** Interrupt vectors for the PWM peripheral type */
#define PWM_CMP_IRQS                             { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn } }
#define PWM_RELOAD_IRQS                          { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn } }
#define PWM_CAPTURE_IRQS                         { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn } }
#define PWM_FAULT_IRQS                           { FLEXPWM0_FAULT_IRQn }
#define PWM_RELOAD_ERROR_IRQS                    { FLEXPWM0_RELOAD_ERROR_IRQn }

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC0 base address */
#define RTC0_BASE                                (0x400EE000u)
/** Peripheral RTC0 base pointer */
#define RTC0                                     ((RTC_Type *)RTC0_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC0_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC0 }
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }
#define RTC_SECONDS_IRQS                         { RTC_1HZ_IRQn }

/* SCG - Peripheral instance base addresses */
/** Peripheral SCG0 base address */
#define SCG0_BASE                                (0x4008F000u)
/** Peripheral SCG0 base pointer */
#define SCG0                                     ((SCG_Type *)SCG0_BASE)
/** Array initializer of SCG peripheral base addresses */
#define SCG_BASE_ADDRS                           { SCG0_BASE }
/** Array initializer of SCG peripheral base pointers */
#define SCG_BASE_PTRS                            { SCG0 }

/* SECCON - Peripheral instance base addresses */
/** Peripheral SECCON base address */
#define SECCON_BASE                              (0x400E8000u)
/** Peripheral SECCON base pointer */
#define SECCON                                   ((SECCON_Type *)SECCON_BASE)
/** Array initializer of SECCON peripheral base addresses */
#define SECCON_BASE_ADDRS                        { SECCON_BASE }
/** Array initializer of SECCON peripheral base pointers */
#define SECCON_BASE_PTRS                         { SECCON }

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
/** Peripheral MBC base address */
#define MBC_BASE                                 (0x4008E000u)
/** Peripheral MBC base pointer */
#define MBC                                      ((TRDC_Type *)MBC_BASE)
/** Array initializer of TRDC peripheral base addresses */
#define TRDC_BASE_ADDRS                          { MBC_BASE }
/** Array initializer of TRDC peripheral base pointers */
#define TRDC_BASE_PTRS                           { MBC }

/* TRNG - Peripheral instance base addresses */
/** Peripheral TRNG0 base address */
#define TRNG0_BASE                               (0x400EC000u)
/** Peripheral TRNG0 base pointer */
#define TRNG0                                    ((TRNG_Type *)TRNG0_BASE)
/** Array initializer of TRNG peripheral base addresses */
#define TRNG_BASE_ADDRS                          { TRNG0_BASE }
/** Array initializer of TRNG peripheral base pointers */
#define TRNG_BASE_PTRS                           { TRNG0 }

/* VBAT - Peripheral instance base addresses */
/** Peripheral VBAT0 base address */
#define VBAT0_BASE                               (0x40093000u)
/** Peripheral VBAT0 base pointer */
#define VBAT0                                    ((VBAT_Type *)VBAT0_BASE)
/** Array initializer of VBAT peripheral base addresses */
#define VBAT_BASE_ADDRS                          { VBAT0_BASE }
/** Array initializer of VBAT peripheral base pointers */
#define VBAT_BASE_PTRS                           { VBAT0 }

/* WUU - Peripheral instance base addresses */
/** Peripheral WUU0 base address */
#define WUU0_BASE                                (0x40092000u)
/** Peripheral WUU0 base pointer */
#define WUU0                                     ((WUU_Type *)WUU0_BASE)
/** Array initializer of WUU peripheral base addresses */
#define WUU_BASE_ADDRS                           { WUU0_BASE }
/** Array initializer of WUU peripheral base pointers */
#define WUU_BASE_PTRS                            { WUU0 }
/** Interrupt vectors for the WUU peripheral type */
#define WUU_IRQS                                 { WUU0_IRQn }

/* WWDT - Peripheral instance base addresses */
/** Peripheral WWDT0 base address */
#define WWDT0_BASE                               (0x4000C000u)
/** Peripheral WWDT0 base pointer */
#define WWDT0                                    ((WWDT_Type *)WWDT0_BASE)
/** Peripheral WWDT1 base address */
#define WWDT1_BASE                               (0x4000D000u)
/** Peripheral WWDT1 base pointer */
#define WWDT1                                    ((WWDT_Type *)WWDT1_BASE)
/** Array initializer of WWDT peripheral base addresses */
#define WWDT_BASE_ADDRS                          { WWDT0_BASE, WWDT1_BASE }
/** Array initializer of WWDT peripheral base pointers */
#define WWDT_BASE_PTRS                           { WWDT0, WWDT1 }

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

#define FGPIO0_BASE                               (0xF8001000u)
/** Peripheral GPIO0 base pointer */
#define FGPIO0                                    ((GPIO_Type *)FGPIO0_BASE)
/** Peripheral GPIO1 base address */
#define FGPIO1_BASE                               (0xF8002000u)
/** Peripheral GPIO1 base pointer */
#define FGPIO1                                    ((GPIO_Type *)FGPIO1_BASE)
/** Peripheral GPIO2 base address */
#define FGPIO2_BASE                               (0xF8003000u)
/** Peripheral GPIO2 base pointer */
#define FGPIO2                                    ((GPIO_Type *)FGPIO2_BASE)
/** Peripheral GPIO3 base address */
#define FGPIO3_BASE                               (0xF8004000u)
/** Peripheral GPIO3 base pointer */
#define FGPIO3                                    ((GPIO_Type *)FGPIO3_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define FGPIO_BASE_ADDRS                          { FGPIO0_BASE, FGPIO1_BASE, FGPIO2_BASE, FGPIO3_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define FGPIO_BASE_PTRS                           { FGPIO0, FGPIO1, FGPIO2, FGPIO3 }
/** Interrupt vectors for the GPIO peripheral type */
#define FGPIO_IRQS                                { GPIO0_IRQn, GPIO1_IRQn, GPIO2_IRQn, GPIO3_IRQn }

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* MCXC161_COMMON_H_ */

