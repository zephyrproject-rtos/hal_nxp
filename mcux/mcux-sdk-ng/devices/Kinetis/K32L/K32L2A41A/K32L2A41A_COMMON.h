/*
** ###################################################################
**     Processors:          K32L2A41VLH1A
**                          K32L2A41VLL1A
**
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    K32L2AxRM, Rev. 1, 12/2019
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for K32L2A41A
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-30)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file K32L2A41A_COMMON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for K32L2A41A
 *
 * CMSIS Peripheral Access Layer for K32L2A41A
 */

#if !defined(K32L2A41A_COMMON_H_)
#define K32L2A41A_COMMON_H_                      /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0200U
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
#define NUMBER_OF_INT_VECTORS 80                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_04_IRQn                 = 0,                /**< DMA0 channel 0/4 transfer complete */
  DMA0_15_IRQn                 = 1,                /**< DMA0 channel 1/5 transfer complete */
  DMA0_26_IRQn                 = 2,                /**< DMA0 channel 2/6 transfer complete */
  DMA0_37_IRQn                 = 3,                /**< DMA0 channel 3/7 transfer complete */
  CTI0_DMA0_Error_IRQn         = 4,                /**< CTI0 or DMA0 error */
  FLEXIO0_IRQn                 = 5,                /**< FLEXIO0 */
  TPM0_IRQn                    = 6,                /**< TPM0 single interrupt vector for all sources */
  TPM1_IRQn                    = 7,                /**< TPM1 single interrupt vector for all sources */
  TPM2_IRQn                    = 8,                /**< TPM2 single interrupt vector for all sources */
  LPIT0_IRQn                   = 9,                /**< LPIT0 interrupt */
  LPSPI0_IRQn                  = 10,               /**< LPSPI0 single interrupt vector for all sources */
  LPSPI1_IRQn                  = 11,               /**< LPSPI1 single interrupt vector for all sources */
  LPUART0_IRQn                 = 12,               /**< LPUART0 status and error */
  LPUART1_IRQn                 = 13,               /**< LPUART1 status and error */
  LPI2C0_IRQn                  = 14,               /**< LPI2C0 interrupt */
  LPI2C1_IRQn                  = 15,               /**< LPI2C1 interrupt */
  Reserved32_IRQn              = 16,               /**< Reserved interrupt */
  PORTA_IRQn                   = 17,               /**< PORTA Pin detect */
  PORTB_IRQn                   = 18,               /**< PORTB Pin detect */
  PORTC_IRQn                   = 19,               /**< PORTC Pin detect */
  PORTD_IRQn                   = 20,               /**< PORTD Pin detect */
  PORTE_IRQn                   = 21,               /**< PORTE Pin detect */
  LLWU_IRQn                    = 22,               /**< Low leakage wakeup  */
  Reserved39_IRQn              = 23,               /**< Reserved interrupt */
  USB0_IRQn                    = 24,               /**< USB0 interrupt */
  ADC0_IRQn                    = 25,               /**< ADC0 interrupt */
  LPTMR0_IRQn                  = 26,               /**< LPTMR0 interrupt */
  RTC_Seconds_IRQn             = 27,               /**< RTC seconds */
  INTMUX0_0_IRQn               = 28,               /**< INTMUX0 channel 0 interrupt */
  INTMUX0_1_IRQn               = 29,               /**< INTMUX0 channel 1 interrupt */
  INTMUX0_2_IRQn               = 30,               /**< INTMUX0 channel 2 interrupt */
  INTMUX0_3_IRQn               = 31,               /**< INTMUX0 channel 3 interrupt */
  LPTMR1_IRQn                  = 32,               /**< LPTMR1 interrupt  (INTMUX source IRQ0) */
  Reserved49_IRQn              = 33,               /**< Reserved interrupt */
  Reserved50_IRQn              = 34,               /**< Reserved interrupt */
  Reserved51_IRQn              = 35,               /**< Reserved interrupt */
  LPSPI2_IRQn                  = 36,               /**< LPSPI2 single interrupt vector for all sources (INTMUX source IRQ4) */
  LPUART2_IRQn                 = 37,               /**< LPUART2 status and error (INTMUX source IRQ5) */
  EMVSIM0_IRQn                 = 38,               /**< EMVSIM0 interrupt (INTMUX source IRQ6) */
  LPI2C2_IRQn                  = 39,               /**< LPI2C2 interrupt (INTMUX source IRQ7) */
  TSI0_IRQn                    = 40,               /**< TSI0 interrupt (INTMUX source IRQ8) */
  PMC_IRQn                     = 41,               /**< PMC interrupt (INTMUX source IRQ9) */
  FTFA_IRQn                    = 42,               /**< FTFA interrupt (INTMUX source IRQ10) */
  SCG_IRQn                     = 43,               /**< SCG interrupt (INTMUX source IRQ11) */
  WDOG0_IRQn                   = 44,               /**< WDOG0 interrupt (INTMUX source IRQ12) */
  DAC0_IRQn                    = 45,               /**< DAC0 interrupt (INTMUX source IRQ13) */
  TRNG_IRQn                    = 46,               /**< TRNG interrupt (INTMUX source IRQ14) */
  RCM_IRQn                     = 47,               /**< RCM interrupt (INTMUX source IRQ15) */
  CMP0_IRQn                    = 48,               /**< CMP0 interrupt (INTMUX source IRQ16) */
  CMP1_IRQn                    = 49,               /**< CMP1 interrupt (INTMUX source IRQ17) */
  RTC_IRQn                     = 50,               /**< RTC Alarm interrupt (INTMUX source IRQ18) */
  Reserved67_IRQn              = 51,               /**< Reserved interrupt */
  Reserved68_IRQn              = 52,               /**< Reserved interrupt */
  Reserved69_IRQn              = 53,               /**< Reserved interrupt */
  Reserved70_IRQn              = 54,               /**< Reserved interrupt */
  Reserved71_IRQn              = 55,               /**< Reserved interrupt */
  Reserved72_IRQn              = 56,               /**< Reserved interrupt */
  Reserved73_IRQn              = 57,               /**< Reserved interrupt */
  Reserved74_IRQn              = 58,               /**< Reserved interrupt */
  Reserved75_IRQn              = 59,               /**< Reserved interrupt */
  Reserved76_IRQn              = 60,               /**< Reserved interrupt */
  Reserved77_IRQn              = 61,               /**< Reserved interrupt */
  Reserved78_IRQn              = 62,               /**< Reserved interrupt */
  Reserved79_IRQn              = 63                /**< Reserved interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M0 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M0 Core Configuration
 * @{
 */

#define __CM0PLUS_REV                  0x0000    /**< Core revision r0p0 */
#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if VTOR is present or not */
#define __NVIC_PRIO_BITS               2         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */

#include "core_cm0plus.h"              /* Core Peripheral Access Layer */
#include "system_K32L2A41A.h"          /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef K32L2A41A_SERIES
#define K32L2A41A_SERIES
#endif
/* CPU specific feature definitions */
#include "K32L2A41A_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x40066000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn }

/* CAU - Peripheral instance base addresses */
/** Peripheral CAU0 base address */
#define CAU0_BASE                                (0xF0005000u)
/** Peripheral CAU0 base pointer */
#define CAU0                                     ((CAU_Type *)CAU0_BASE)
/** Array initializer of CAU peripheral base addresses */
#define CAU_BASE_ADDRS                           { CAU0_BASE }
/** Array initializer of CAU peripheral base pointers */
#define CAU_BASE_PTRS                            { CAU0 }

/* CMP - Peripheral instance base addresses */
/** Peripheral CMP0 base address */
#define CMP0_BASE                                (0x4006E000u)
/** Peripheral CMP0 base pointer */
#define CMP0                                     ((CMP_Type *)CMP0_BASE)
/** Peripheral CMP1 base address */
#define CMP1_BASE                                (0x400EF000u)
/** Peripheral CMP1 base pointer */
#define CMP1                                     ((CMP_Type *)CMP1_BASE)
/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           { CMP0_BASE, CMP1_BASE }
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { CMP0, CMP1 }
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { CMP0_IRQn, CMP1_IRQn }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base address */
#define CRC_BASE                                 (0x40078000u)
/** Peripheral CRC base pointer */
#define CRC0                                     ((CRC_Type *)CRC_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC0 }

/* DAC - Peripheral instance base addresses */
/** Peripheral DAC0 base address */
#define DAC0_BASE                                (0x4006A000u)
/** Peripheral DAC0 base pointer */
#define DAC0                                     ((DAC_Type *)DAC0_BASE)
/** Array initializer of DAC peripheral base addresses */
#define DAC_BASE_ADDRS                           { DAC0_BASE }
/** Array initializer of DAC peripheral base pointers */
#define DAC_BASE_PTRS                            { DAC0 }
/** Interrupt vectors for the DAC peripheral type */
#define DAC_IRQS                                 { DAC0_IRQn }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x40008000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_CHN_IRQS                             { { DMA0_04_IRQn, DMA0_15_IRQn, DMA0_26_IRQn, DMA0_37_IRQn, DMA0_04_IRQn, DMA0_15_IRQn, DMA0_26_IRQn, DMA0_37_IRQn } }
#define DMA_ERROR_IRQS                           { CTI0_DMA0_Error_IRQn }

/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX0 base address */
#define DMAMUX0_BASE                             (0x40021000u)
/** Peripheral DMAMUX0 base pointer */
#define DMAMUX0                                  ((DMAMUX_Type *)DMAMUX0_BASE)
/** Array initializer of DMAMUX peripheral base addresses */
#define DMAMUX_BASE_ADDRS                        { DMAMUX0_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { DMAMUX0 }

/* EMVSIM - Peripheral instance base addresses */
/** Peripheral EMVSIM0 base address */
#define EMVSIM0_BASE                             (0x4004E000u)
/** Peripheral EMVSIM0 base pointer */
#define EMVSIM0                                  ((EMVSIM_Type *)EMVSIM0_BASE)
/** Array initializer of EMVSIM peripheral base addresses */
#define EMVSIM_BASE_ADDRS                        { EMVSIM0_BASE }
/** Array initializer of EMVSIM peripheral base pointers */
#define EMVSIM_BASE_PTRS                         { EMVSIM0 }
/** Interrupt vectors for the EMVSIM peripheral type */
#define EMVSIM_IRQS                              { EMVSIM0_IRQn }

/* FGPIO - Peripheral instance base addresses */
/** Peripheral FGPIOA base address */
#define FGPIOA_BASE                              (0xF8000000u)
/** Peripheral FGPIOA base pointer */
#define FGPIOA                                   ((FGPIO_Type *)FGPIOA_BASE)
/** Array initializer of FGPIO peripheral base addresses */
#define FGPIO_BASE_ADDRS                         { FGPIOA_BASE }
/** Array initializer of FGPIO peripheral base pointers */
#define FGPIO_BASE_PTRS                          { FGPIOA }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO0 base address */
#define FLEXIO0_BASE                             (0x400CA000u)
/** Peripheral FLEXIO0 base pointer */
#define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { FLEXIO0 }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { FLEXIO0_IRQn }

/* FTFA - Peripheral instance base addresses */
/** Peripheral FTFA base address */
#define FTFA_BASE                                (0x40020000u)
/** Peripheral FTFA base pointer */
#define FTFA                                     ((FTFA_Type *)FTFA_BASE)
/** Array initializer of FTFA peripheral base addresses */
#define FTFA_BASE_ADDRS                          { FTFA_BASE }
/** Array initializer of FTFA peripheral base pointers */
#define FTFA_BASE_PTRS                           { FTFA }
/** Interrupt vectors for the FTFA peripheral type */
#define FTFA_COMMAND_COMPLETE_IRQS               { FTFA_IRQn }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                               (0x4000F000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                    ((GPIO_Type *)GPIOA_BASE)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                               (0x4000F040u)
/** Peripheral GPIOB base pointer */
#define GPIOB                                    ((GPIO_Type *)GPIOB_BASE)
/** Peripheral GPIOC base address */
#define GPIOC_BASE                               (0x4000F080u)
/** Peripheral GPIOC base pointer */
#define GPIOC                                    ((GPIO_Type *)GPIOC_BASE)
/** Peripheral GPIOD base address */
#define GPIOD_BASE                               (0x4000F0C0u)
/** Peripheral GPIOD base pointer */
#define GPIOD                                    ((GPIO_Type *)GPIOD_BASE)
/** Peripheral GPIOE base address */
#define GPIOE_BASE                               (0x4000F100u)
/** Peripheral GPIOE base pointer */
#define GPIOE                                    ((GPIO_Type *)GPIOE_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE }

/* INTMUX - Peripheral instance base addresses */
/** Peripheral INTMUX0 base address */
#define INTMUX0_BASE                             (0x40024000u)
/** Peripheral INTMUX0 base pointer */
#define INTMUX0                                  ((INTMUX_Type *)INTMUX0_BASE)
/** Array initializer of INTMUX peripheral base addresses */
#define INTMUX_BASE_ADDRS                        { INTMUX0_BASE }
/** Array initializer of INTMUX peripheral base pointers */
#define INTMUX_BASE_PTRS                         { INTMUX0 }
/** Interrupt vectors for the INTMUX peripheral type */
#define INTMUX_IRQS                              { { INTMUX0_0_IRQn, INTMUX0_1_IRQn, INTMUX0_2_IRQn, INTMUX0_3_IRQn } }

/* LLWU - Peripheral instance base addresses */
/** Peripheral LLWU base address */
#define LLWU_BASE                                (0x40061000u)
/** Peripheral LLWU base pointer */
#define LLWU                                     ((LLWU_Type *)LLWU_BASE)
/** Array initializer of LLWU peripheral base addresses */
#define LLWU_BASE_ADDRS                          { LLWU_BASE }
/** Array initializer of LLWU peripheral base pointers */
#define LLWU_BASE_PTRS                           { LLWU }
/** Interrupt vectors for the LLWU peripheral type */
#define LLWU_IRQS                                { LLWU_IRQn }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x400C0000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x400C1000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x40042000u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn, LPI2C2_IRQn }

/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT0 base address */
#define LPIT0_BASE                               (0x40030000u)
/** Peripheral LPIT0 base pointer */
#define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { LPIT0_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { LPIT0 }
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { { LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn } }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x400BC000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x400BD000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x4003E000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn, LPSPI2_IRQn }

/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0x40034000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
/** Peripheral LPTMR1 base address */
#define LPTMR1_BASE                              (0x400B5000u)
/** Peripheral LPTMR1 base pointer */
#define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR0_BASE, LPTMR1_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0, LPTMR1 }
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn, LPTMR1_IRQn }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x400C4000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x400C5000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x40046000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn }

/* MCM - Peripheral instance base addresses */
/** Peripheral MCM0 base address */
#define MCM0_BASE                                (0xF0003008u)
/** Peripheral MCM0 base pointer */
#define MCM0                                     ((MCM_Type *)MCM0_BASE)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS                           { MCM0_BASE }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM0 }

/* MMDVSQ - Peripheral instance base addresses */
/** Peripheral MMDVSQ0 base address */
#define MMDVSQ0_BASE                             (0xF0004000u)
/** Peripheral MMDVSQ0 base pointer */
#define MMDVSQ0                                  ((MMDVSQ_Type *)MMDVSQ0_BASE)
/** Array initializer of MMDVSQ peripheral base addresses */
#define MMDVSQ_BASE_ADDRS                        { MMDVSQ0_BASE }
/** Array initializer of MMDVSQ peripheral base pointers */
#define MMDVSQ_BASE_PTRS                         { MMDVSQ0 }

/* MSCM - Peripheral instance base addresses */
/** Peripheral MSCM base address */
#define MSCM_BASE                                (0x40001000u)
/** Peripheral MSCM base pointer */
#define MSCM                                     ((MSCM_Type *)MSCM_BASE)
/** Array initializer of MSCM peripheral base addresses */
#define MSCM_BASE_ADDRS                          { MSCM_BASE }
/** Array initializer of MSCM peripheral base pointers */
#define MSCM_BASE_PTRS                           { MSCM }

/* MTB - Peripheral instance base addresses */
/** Peripheral MTB0 base address */
#define MTB0_BASE                                (0xF0000000u)
/** Peripheral MTB0 base pointer */
#define MTB0                                     ((MTB_Type *)MTB0_BASE)
/** Array initializer of MTB peripheral base addresses */
#define MTB_BASE_ADDRS                           { MTB0_BASE }
/** Array initializer of MTB peripheral base pointers */
#define MTB_BASE_PTRS                            { MTB0 }

/* MTB_DWT - Peripheral instance base addresses */
/** Peripheral MTB0_DWT base address */
#define MTB0_DWT_BASE                            (0xF0001000u)
/** Peripheral MTB0_DWT base pointer */
#define MTB0_DWT                                 ((MTB_DWT_Type *)MTB0_DWT_BASE)
/** Array initializer of MTB_DWT peripheral base addresses */
#define MTB_DWT_BASE_ADDRS                       { MTB0_DWT_BASE }
/** Array initializer of MTB_DWT peripheral base pointers */
#define MTB_DWT_BASE_PTRS                        { MTB0_DWT }

/* MTB_ROM - Peripheral instance base addresses */
/** Peripheral MTB0_ROM base address */
#define MTB0_ROM_BASE                            (0xF0002000u)
/** Peripheral MTB0_ROM base pointer */
#define MTB0_ROM                                 ((MTB_ROM_Type *)MTB0_ROM_BASE)
/** Array initializer of MTB_ROM peripheral base addresses */
#define MTB_ROM_BASE_ADDRS                       { MTB0_ROM_BASE }
/** Array initializer of MTB_ROM peripheral base pointers */
#define MTB_ROM_BASE_PTRS                        { MTB0_ROM }

/* NV - Peripheral instance base addresses */
/** Peripheral FTFA_FlashConfig base address */
#define FTFA_FlashConfig_BASE                    (0x400u)
/** Peripheral FTFA_FlashConfig base pointer */
#define FTFA_FlashConfig                         ((NV_Type *)FTFA_FlashConfig_BASE)
/** Array initializer of NV peripheral base addresses */
#define NV_BASE_ADDRS                            { FTFA_FlashConfig_BASE }
/** Array initializer of NV peripheral base pointers */
#define NV_BASE_PTRS                             { FTFA_FlashConfig }

/* PCC - Peripheral instance base addresses */
/** Peripheral PCC0 base address */
#define PCC0_BASE                                (0x4007A000u)
/** Peripheral PCC0 base pointer */
#define PCC0                                     ((PCC_Type *)PCC0_BASE)
/** Peripheral PCC1 base address */
#define PCC1_BASE                                (0x400FA000u)
/** Peripheral PCC1 base pointer */
#define PCC1                                     ((PCC_Type *)PCC1_BASE)
/** Array initializer of PCC peripheral base addresses */
#define PCC_BASE_ADDRS                           { PCC0_BASE, PCC1_BASE }
/** Array initializer of PCC peripheral base pointers */
#define PCC_BASE_PTRS                            { PCC0, PCC1 }

/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base address */
#define PMC_BASE                                 (0x4007D000u)
/** Peripheral PMC base pointer */
#define PMC                                      ((PMC_Type *)PMC_BASE)
/** Array initializer of PMC peripheral base addresses */
#define PMC_BASE_ADDRS                           { PMC_BASE }
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASE_PTRS                            { PMC }
/** Interrupt vectors for the PMC peripheral type */
#define PMC_IRQS                                 { PMC_IRQn }

/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x4005A000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x4005B000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x4005C000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x4005D000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)
/** Peripheral PORTE base address */
#define PORTE_BASE                               (0x4005E000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD, PORTE }
/** Interrupt vectors for the PORT peripheral type */
#define PORT_IRQS                                { PORTA_IRQn, PORTB_IRQn, PORTC_IRQn, PORTD_IRQn, PORTE_IRQn }

/* RCM - Peripheral instance base addresses */
/** Peripheral RCM base address */
#define RCM_BASE                                 (0x4007F000u)
/** Peripheral RCM base pointer */
#define RCM                                      ((RCM_Type *)RCM_BASE)
/** Array initializer of RCM peripheral base addresses */
#define RCM_BASE_ADDRS                           { RCM_BASE }
/** Array initializer of RCM peripheral base pointers */
#define RCM_BASE_PTRS                            { RCM }
/** Interrupt vectors for the RCM peripheral type */
#define RCM_IRQS                                 { RCM_IRQn }

/* RFSYS - Peripheral instance base addresses */
/** Peripheral RFSYS base address */
#define RFSYS_BASE                               (0x4007C000u)
/** Peripheral RFSYS base pointer */
#define RFSYS                                    ((RFSYS_Type *)RFSYS_BASE)
/** Array initializer of RFSYS peripheral base addresses */
#define RFSYS_BASE_ADDRS                         { RFSYS_BASE }
/** Array initializer of RFSYS peripheral base pointers */
#define RFSYS_BASE_PTRS                          { RFSYS }

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x40038000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }
#define RTC_SECONDS_IRQS                         { RTC_Seconds_IRQn }

/* SCG - Peripheral instance base addresses */
/** Peripheral SCG base address */
#define SCG_BASE                                 (0x4007B000u)
/** Peripheral SCG base pointer */
#define SCG                                      ((SCG_Type *)SCG_BASE)
/** Array initializer of SCG peripheral base addresses */
#define SCG_BASE_ADDRS                           { SCG_BASE }
/** Array initializer of SCG peripheral base pointers */
#define SCG_BASE_PTRS                            { SCG }
/** Interrupt vectors for the SCG peripheral type */
#define SCG_IRQS                                 { SCG_IRQn }

/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x40074000u)
/** Peripheral SIM base pointer */
#define SIM                                      ((SIM_Type *)SIM_BASE)
/** Array initializer of SIM peripheral base addresses */
#define SIM_BASE_ADDRS                           { SIM_BASE }
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM }

/* SMC - Peripheral instance base addresses */
/** Peripheral SMC base address */
#define SMC_BASE                                 (0x4007E000u)
/** Peripheral SMC base pointer */
#define SMC                                      ((SMC_Type *)SMC_BASE)
/** Array initializer of SMC peripheral base addresses */
#define SMC_BASE_ADDRS                           { SMC_BASE }
/** Array initializer of SMC peripheral base pointers */
#define SMC_BASE_PTRS                            { SMC }

/* TPM - Peripheral instance base addresses */
/** Peripheral TPM0 base address */
#define TPM0_BASE                                (0x400AC000u)
/** Peripheral TPM0 base pointer */
#define TPM0                                     ((TPM_Type *)TPM0_BASE)
/** Peripheral TPM1 base address */
#define TPM1_BASE                                (0x400AD000u)
/** Peripheral TPM1 base pointer */
#define TPM1                                     ((TPM_Type *)TPM1_BASE)
/** Peripheral TPM2 base address */
#define TPM2_BASE                                (0x4002E000u)
/** Peripheral TPM2 base pointer */
#define TPM2                                     ((TPM_Type *)TPM2_BASE)
/** Array initializer of TPM peripheral base addresses */
#define TPM_BASE_ADDRS                           { TPM0_BASE, TPM1_BASE, TPM2_BASE }
/** Array initializer of TPM peripheral base pointers */
#define TPM_BASE_PTRS                            { TPM0, TPM1, TPM2 }
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { TPM0_IRQn, TPM1_IRQn, TPM2_IRQn }

/* TRGMUX - Peripheral instance base addresses */
/** Peripheral TRGMUX0 base address */
#define TRGMUX0_BASE                             (0x40027000u)
/** Peripheral TRGMUX0 base pointer */
#define TRGMUX0                                  ((TRGMUX_Type *)TRGMUX0_BASE)
/** Peripheral TRGMUX1 base address */
#define TRGMUX1_BASE                             (0x400A7000u)
/** Peripheral TRGMUX1 base pointer */
#define TRGMUX1                                  ((TRGMUX_Type *)TRGMUX1_BASE)
/** Array initializer of TRGMUX peripheral base addresses */
#define TRGMUX_BASE_ADDRS                        { TRGMUX0_BASE, TRGMUX1_BASE }
/** Array initializer of TRGMUX peripheral base pointers */
#define TRGMUX_BASE_PTRS                         { TRGMUX0, TRGMUX1 }

/* TRNG - Peripheral instance base addresses */
/** Peripheral TRNG base address */
#define TRNG_BASE                                (0x400A5000u)
/** Peripheral TRNG base pointer */
#define TRNG                                     ((TRNG_Type *)TRNG_BASE)
/** Array initializer of TRNG peripheral base addresses */
#define TRNG_BASE_ADDRS                          { TRNG_BASE }
/** Array initializer of TRNG peripheral base pointers */
#define TRNG_BASE_PTRS                           { TRNG }
/** Interrupt vectors for the TRNG peripheral type */
#define TRNG_IRQS                                { TRNG_IRQn }

/* TSI - Peripheral instance base addresses */
/** Peripheral TSI0 base address */
#define TSI0_BASE                                (0x40062000u)
/** Peripheral TSI0 base pointer */
#define TSI0                                     ((TSI_Type *)TSI0_BASE)
/** Array initializer of TSI peripheral base addresses */
#define TSI_BASE_ADDRS                           { TSI0_BASE }
/** Array initializer of TSI peripheral base pointers */
#define TSI_BASE_PTRS                            { TSI0 }
/** Interrupt vectors for the TSI peripheral type */
#define TSI_IRQS                                 { TSI0_IRQn }

/* TSTMR - Peripheral instance base addresses */
/** Peripheral TSTMR0 base address */
#define TSTMR0_BASE                              (0x400750F0u)
/** Peripheral TSTMR0 base pointer */
#define TSTMR0                                   ((TSTMR_Type *)TSTMR0_BASE)
/** Array initializer of TSTMR peripheral base addresses */
#define TSTMR_BASE_ADDRS                         { TSTMR0_BASE }
/** Array initializer of TSTMR peripheral base pointers */
#define TSTMR_BASE_PTRS                          { TSTMR0 }

/* USB - Peripheral instance base addresses */
/** Peripheral USB0 base address */
#define USB0_BASE                                (0x40055000u)
/** Peripheral USB0 base pointer */
#define USB0                                     ((USB_Type *)USB0_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB0_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB0 }
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { USB0_IRQn }

/* VREF - Peripheral instance base addresses */
/** Peripheral VREF base address */
#define VREF_BASE                                (0x40072000u)
/** Peripheral VREF base pointer */
#define VREF                                     ((VREF_Type *)VREF_BASE)
/** Array initializer of VREF peripheral base addresses */
#define VREF_BASE_ADDRS                          { VREF_BASE }
/** Array initializer of VREF peripheral base pointers */
#define VREF_BASE_PTRS                           { VREF }

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG0 base address */
#define WDOG0_BASE                               (0x40076000u)
/** Peripheral WDOG0 base pointer */
#define WDOG0                                    ((WDOG_Type *)WDOG0_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG0_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG0 }
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { WDOG0_IRQn }

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

#define FPTA_BASE                                FGPIOA_BASE
#define FPTA                                     FGPIOA
#define PTA_BASE                                 GPIOA_BASE
#define PTA                                      GPIOA
#define PTB_BASE                                 GPIOB_BASE
#define PTB                                      GPIOB
#define PTC_BASE                                 GPIOC_BASE
#define PTC                                      GPIOC
#define PTD_BASE                                 GPIOD_BASE
#define PTD                                      GPIOD
#define PTE_BASE                                 GPIOE_BASE
#define PTE                                      GPIOE
#define LPTimer_IRQn                             LPTMR0_IRQn
#define LPTimer_IRQHandler                       LPTMR0_IRQHandler
#define TRNG0                                    TRNG
#define CAU                                      CAU0
#define CAU_BASE                                 CAU0_BASE

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* K32L2A41A_COMMON_H_ */

