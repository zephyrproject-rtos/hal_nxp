/*
** ###################################################################
**     Processor:           K32L3A60VPJ1A_cm0plus
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    K32L3ARM, Rev. 0 , 05/2019
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for K32L3A60_cm0plus
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
 * @file K32L3A60_cm0plus_COMMON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for K32L3A60_cm0plus
 *
 * CMSIS Peripheral Access Layer for K32L3A60_cm0plus
 */

#if !defined(K32L3A60_CM0PLUS_COMMON_H_)
#define K32L3A60_CM0PLUS_COMMON_H_               /**< Symbol preventing repeated inclusion */

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
  CTI1_IRQn                    = 0,                /**< Cross Trigger Interface 1 */
  DMA1_04_IRQn                 = 1,                /**< DMA1 channel 0/4 transfer complete */
  DMA1_15_IRQn                 = 2,                /**< DMA1 channel 1/5 transfer complete */
  DMA1_26_IRQn                 = 3,                /**< DMA1 channel 2/6 transfer complete */
  DMA1_37_IRQn                 = 4,                /**< DMA1 channel 3/7 transfer complete */
  DMA1_Error_IRQn              = 5,                /**< DMA1 channel 0-7 error interrupt */
  MSMC_IRQn                    = 6,                /**< MSMC (SMC1) interrupt */
  LLWU1_IRQn                   = 7,                /**< Low leakage wakeup 1 */
  MUB_IRQn                     = 8,                /**< MU Side B interrupt */
  WDOG1_IRQn                   = 9,                /**< WDOG1 interrupt */
  CAU3_Task_Complete_IRQn      = 10,               /**< Cryptographic Acceleration Unit version 3 Task Complete */
  CAU3_Security_Violation_IRQn = 11,               /**< Cryptographic Acceleration Unit version 3 Security Violation */
  TRNG_IRQn                    = 12,               /**< TRNG interrupt */
  LPIT1_IRQn                   = 13,               /**< LPIT1 interrupt */
  LPTMR2_IRQn                  = 14,               /**< LPTMR2 interrupt */
  TPM3_IRQn                    = 15,               /**< TPM3 single interrupt vector for all sources */
  LPI2C3_IRQn                  = 16,               /**< LPI2C3 interrupt */
  Reserved33_IRQn              = 17,               /**< Reserved interrupt */
  Reserved34_IRQn              = 18,               /**< Reserved interrupt */
  LPSPI3_IRQn                  = 19,               /**< LPSPI3 single interrupt vector for all sources */
  LPUART3_IRQn                 = 20,               /**< LPUART3 status and error */
  PORTE_IRQn                   = 21,               /**< PORTE Pin detect */
  LPCMP1_IRQn                  = 22,               /**< LPCMP1 interrupt */
  RTC_IRQn                     = 23,               /**< RTC */
  INTMUX1_0_IRQn               = 24,               /**< INTMUX1 channel0 interrupt */
  INTMUX1_1_IRQn               = 25,               /**< INTMUX1 channel1 interrupt */
  INTMUX1_2_IRQn               = 26,               /**< INTMUX1 channel2 interrupt */
  INTMUX1_3_IRQn               = 27,               /**< INTMUX1 channel3 interrupt */
  INTMUX1_4_IRQn               = 28,               /**< INTMUX1 channel4 interrupt */
  INTMUX1_5_IRQn               = 29,               /**< INTMUX1 channel5 interrupt */
  INTMUX1_6_IRQn               = 30,               /**< INTMUX1 channel6 interrupt */
  INTMUX1_7_IRQn               = 31,               /**< INTMUX1 channel7 interrupt */
  EWM_IRQn                     = 32,               /**< EWM interrupt  (INTMUX1 source IRQ0) */
  FTFE_Command_Complete_IRQn   = 33,               /**< FTFE interrupt  (INTMUX1 source IRQ1) */
  FTFE_Read_Collision_IRQn     = 34,               /**< FTFE interrupt  (INTMUX1 source IRQ2) */
  SPM_IRQn                     = 35,               /**< SPM (INTMUX1 source IRQ3) */
  SCG_IRQn                     = 36,               /**< SCG interrupt (INTMUX1 source IRQ4) */
  LPIT0_IRQn                   = 37,               /**< LPIT0 interrupt (INTMUX1 source IRQ5) */
  LPTMR0_IRQn                  = 38,               /**< LPTMR0 interrupt (INTMUX1 source IRQ6) */
  LPTMR1_IRQn                  = 39,               /**< LPTMR1 interrupt (INTMUX1 source IRQ7) */
  TPM0_IRQn                    = 40,               /**< TPM0 single interrupt vector for all sources (INTMUX1 source IRQ8) */
  TPM1_IRQn                    = 41,               /**< TPM1 single interrupt vector for all sources (INTMUX1 source IRQ9) */
  TPM2_IRQn                    = 42,               /**< TPM2 single interrupt vector for all sources (INTMUX1 source IRQ10) */
  EMVSIM0_IRQn                 = 43,               /**< EMVSIM0 interrupt (INTMUX1 source IRQ11) */
  FLEXIO0_IRQn                 = 44,               /**< FLEXIO0 (INTMUX1 source IRQ12) */
  LPI2C0_IRQn                  = 45,               /**< LPI2C0 interrupt (INTMUX1 source IRQ13) */
  LPI2C1_IRQn                  = 46,               /**< LPI2C1 interrupt (INTMUX1 source IRQ14) */
  LPI2C2_IRQn                  = 47,               /**< LPI2C2 interrupt (INTMUX1 source IRQ15) */
  I2S0_IRQn                    = 48,               /**< I2S0 interrupt (INTMUX1 source IRQ16) */
  USDHC0_IRQn                  = 49,               /**< SDHC0 interrupt (INTMUX1 source IRQ17) */
  LPSPI0_IRQn                  = 50,               /**< LPSPI0 single interrupt vector for all sources (INTMUX1 source IRQ18) */
  LPSPI1_IRQn                  = 51,               /**< LPSPI1 single interrupt vector for all sources (INTMUX1 source IRQ19) */
  LPSPI2_IRQn                  = 52,               /**< LPSPI2 single interrupt vector for all sources (INTMUX1 source IRQ20) */
  LPUART0_IRQn                 = 53,               /**< LPUART0 status and error (INTMUX1 source IRQ21) */
  LPUART1_IRQn                 = 54,               /**< LPUART1 status and error (INTMUX1 source IRQ22) */
  LPUART2_IRQn                 = 55,               /**< LPUART2 status and error (INTMUX1 source IRQ23) */
  USB0_IRQn                    = 56,               /**< USB0 interrupt (INTMUX1 source IRQ24) */
  PORTA_IRQn                   = 57,               /**< PORTA Pin detect (INTMUX1 source IRQ25) */
  PORTB_IRQn                   = 58,               /**< PORTB Pin detect (INTMUX1 source IRQ26) */
  PORTC_IRQn                   = 59,               /**< PORTC Pin detect (INTMUX1 source IRQ27) */
  PORTD_IRQn                   = 60,               /**< PORTD Pin detect (INTMUX1 source IRQ28) */
  LPADC0_IRQn                  = 61,               /**< LPADC0 interrupt (INTMUX1 source IRQ29) */
  LPCMP0_IRQn                  = 62,               /**< LPCMP0 interrupt (INTMUX1 source IRQ30) */
  LPDAC0_IRQn                  = 63                /**< LPDAC0 interrupt (INTMUX1 source IRQ31) */
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
#include "system_K32L3A60_cm0plus.h"   /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef K32L3A60_cm0plus_SERIES
#define K32L3A60_cm0plus_SERIES
#endif
/* CPU specific feature definitions */
#include "K32L3A60_cm0plus_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral LPADC0 base address */
#define LPADC0_BASE                              (0x4004A000u)
/** Peripheral LPADC0 base pointer */
#define LPADC0                                   ((ADC_Type *)LPADC0_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { LPADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { LPADC0 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { LPADC0_IRQn }

/* CAU3 - Peripheral instance base addresses */
/** Peripheral CAU3 base address */
#define CAU3_BASE                                (0x41028000u)
/** Peripheral CAU3 base pointer */
#define CAU3                                     ((CAU3_Type *)CAU3_BASE)
/** Array initializer of CAU3 peripheral base addresses */
#define CAU3_BASE_ADDRS                          { CAU3_BASE }
/** Array initializer of CAU3 peripheral base pointers */
#define CAU3_BASE_PTRS                           { CAU3 }
/** Interrupt vectors for the CAU3 peripheral type */
#define CAU3_TASK_COMPLETE_IRQS                  { CAU3_Task_Complete_IRQn }
#define CAU3_SECURITY_VIOLATION_IRQS             { CAU3_Security_Violation_IRQn }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base address */
#define CRC_BASE                                 (0x4002F000u)
/** Peripheral CRC base pointer */
#define CRC0                                     ((CRC_Type *)CRC_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC0 }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA1 base address */
#define DMA1_BASE                                (0x41008000u)
/** Peripheral DMA1 base pointer */
#define DMA1                                     ((DMA_Type *)DMA1_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { 0u, DMA1_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { (DMA_Type *)0u, DMA1 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_CHN_IRQS                             { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { DMA1_04_IRQn, DMA1_15_IRQn, DMA1_26_IRQn, DMA1_37_IRQn, DMA1_04_IRQn, DMA1_15_IRQn, DMA1_26_IRQn, DMA1_37_IRQn } }
#define DMA_ERROR_IRQS                           { NotAvail_IRQn, DMA1_Error_IRQn }

/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX1 base address */
#define DMAMUX1_BASE                             (0x41021000u)
/** Peripheral DMAMUX1 base pointer */
#define DMAMUX1                                  ((DMAMUX_Type *)DMAMUX1_BASE)
/** Array initializer of DMAMUX peripheral base addresses */
#define DMAMUX_BASE_ADDRS                        { 0u, DMAMUX1_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { (DMAMUX_Type *)0u, DMAMUX1 }

/* EMVSIM - Peripheral instance base addresses */
/** Peripheral EMVSIM0 base address */
#define EMVSIM0_BASE                             (0x40038000u)
/** Peripheral EMVSIM0 base pointer */
#define EMVSIM0                                  ((EMVSIM_Type *)EMVSIM0_BASE)
/** Array initializer of EMVSIM peripheral base addresses */
#define EMVSIM_BASE_ADDRS                        { EMVSIM0_BASE }
/** Array initializer of EMVSIM peripheral base pointers */
#define EMVSIM_BASE_PTRS                         { EMVSIM0 }
/** Interrupt vectors for the EMVSIM peripheral type */
#define EMVSIM_IRQS                              { EMVSIM0_IRQn }

/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base address */
#define EWM_BASE                                 (0x40022000u)
/** Peripheral EWM base pointer */
#define EWM                                      ((EWM_Type *)EWM_BASE)
/** Array initializer of EWM peripheral base addresses */
#define EWM_BASE_ADDRS                           { EWM_BASE }
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASE_PTRS                            { EWM }
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { EWM_IRQn }

/* FB - Peripheral instance base addresses */
/** Peripheral FB base address */
#define FB_BASE                                  (0x4000C000u)
/** Peripheral FB base pointer */
#define FB                                       ((FB_Type *)FB_BASE)
/** Array initializer of FB peripheral base addresses */
#define FB_BASE_ADDRS                            { FB_BASE }
/** Array initializer of FB peripheral base pointers */
#define FB_BASE_PTRS                             { FB }

/* FGPIO - Peripheral instance base addresses */
/** Peripheral FGPIOE base address */
#define FGPIOE_BASE                              (0xF8000000u)
/** Peripheral FGPIOE base pointer */
#define FGPIOE                                   ((FGPIO_Type *)FGPIOE_BASE)
/** Array initializer of FGPIO peripheral base addresses */
#define FGPIO_BASE_ADDRS                         { 0u, 0u, 0u, 0u, FGPIOE_BASE }
/** Array initializer of FGPIO peripheral base pointers */
#define FGPIO_BASE_PTRS                          { (FGPIO_Type *)0u, (FGPIO_Type *)0u, (FGPIO_Type *)0u, (FGPIO_Type *)0u, FGPIOE }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO0 base address */
#define FLEXIO0_BASE                             (0x40039000u)
/** Peripheral FLEXIO0 base pointer */
#define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { FLEXIO0 }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { FLEXIO0_IRQn }

/* FTFE - Peripheral instance base addresses */
/** Peripheral FTFE base address */
#define FTFE_BASE                                (0x40023000u)
/** Peripheral FTFE base pointer */
#define FTFE                                     ((FTFE_Type *)FTFE_BASE)
/** Array initializer of FTFE peripheral base addresses */
#define FTFE_BASE_ADDRS                          { FTFE_BASE }
/** Array initializer of FTFE peripheral base pointers */
#define FTFE_BASE_PTRS                           { FTFE }
/** Interrupt vectors for the FTFE peripheral type */
#define FTFE_COMMAND_COMPLETE_IRQS               { FTFE_Command_Complete_IRQn }
#define FTFE_READ_COLLISION_IRQS                 { FTFE_Read_Collision_IRQn }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                               (0x48020000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                    ((GPIO_Type *)GPIOA_BASE)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                               (0x48020040u)
/** Peripheral GPIOB base pointer */
#define GPIOB                                    ((GPIO_Type *)GPIOB_BASE)
/** Peripheral GPIOC base address */
#define GPIOC_BASE                               (0x48020080u)
/** Peripheral GPIOC base pointer */
#define GPIOC                                    ((GPIO_Type *)GPIOC_BASE)
/** Peripheral GPIOD base address */
#define GPIOD_BASE                               (0x480200C0u)
/** Peripheral GPIOD base pointer */
#define GPIOD                                    ((GPIO_Type *)GPIOD_BASE)
/** Peripheral GPIOE base address */
#define GPIOE_BASE                               (0x4100F000u)
/** Peripheral GPIOE base pointer */
#define GPIOE                                    ((GPIO_Type *)GPIOE_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE }

/* I2S - Peripheral instance base addresses */
/** Peripheral I2S0 base address */
#define I2S0_BASE                                (0x4003D000u)
/** Peripheral I2S0 base pointer */
#define I2S0                                     ((I2S_Type *)I2S0_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { I2S0_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { I2S0 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { I2S0_IRQn }
#define I2S_TX_IRQS                              { I2S0_IRQn }

/* INTMUX - Peripheral instance base addresses */
/** Peripheral INTMUX1 base address */
#define INTMUX1_BASE                             (0x41022000u)
/** Peripheral INTMUX1 base pointer */
#define INTMUX1                                  ((INTMUX_Type *)INTMUX1_BASE)
/** Array initializer of INTMUX peripheral base addresses */
#define INTMUX_BASE_ADDRS                        { 0u, INTMUX1_BASE }
/** Array initializer of INTMUX peripheral base pointers */
#define INTMUX_BASE_PTRS                         { (INTMUX_Type *)0u, INTMUX1 }
/** Interrupt vectors for the INTMUX peripheral type */
#define INTMUX_IRQS                              { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { INTMUX1_0_IRQn, INTMUX1_1_IRQn, INTMUX1_2_IRQn, INTMUX1_3_IRQn, INTMUX1_4_IRQn, INTMUX1_5_IRQn, INTMUX1_6_IRQn, INTMUX1_7_IRQn } }

/* LLWU - Peripheral instance base addresses */
/** Peripheral LLWU0 base address */
#define LLWU0_BASE                               (0x40024000u)
/** Peripheral LLWU0 base pointer */
#define LLWU0                                    ((LLWU_Type *)LLWU0_BASE)
/** Peripheral LLWU1 base address */
#define LLWU1_BASE                               (0x41023000u)
/** Peripheral LLWU1 base pointer */
#define LLWU1                                    ((LLWU_Type *)LLWU1_BASE)
/** Array initializer of LLWU peripheral base addresses */
#define LLWU_BASE_ADDRS                          { LLWU0_BASE, LLWU1_BASE }
/** Array initializer of LLWU peripheral base pointers */
#define LLWU_BASE_PTRS                           { LLWU0, LLWU1 }
/** Interrupt vectors for the LLWU peripheral type */
#define LLWU_IRQS                                { NotAvail_IRQn, LLWU1_IRQn }

/* LPCMP - Peripheral instance base addresses */
/** Peripheral LPCMP0 base address */
#define LPCMP0_BASE                              (0x4004B000u)
/** Peripheral LPCMP0 base pointer */
#define LPCMP0                                   ((LPCMP_Type *)LPCMP0_BASE)
/** Peripheral LPCMP1 base address */
#define LPCMP1_BASE                              (0x41038000u)
/** Peripheral LPCMP1 base pointer */
#define LPCMP1                                   ((LPCMP_Type *)LPCMP1_BASE)
/** Array initializer of LPCMP peripheral base addresses */
#define LPCMP_BASE_ADDRS                         { LPCMP0_BASE, LPCMP1_BASE }
/** Array initializer of LPCMP peripheral base pointers */
#define LPCMP_BASE_PTRS                          { LPCMP0, LPCMP1 }
/** Interrupt vectors for the LPCMP peripheral type */
#define LPCMP_IRQS                               { LPCMP0_IRQn, LPCMP1_IRQn }

/* LPDAC - Peripheral instance base addresses */
/** Peripheral LPDAC0 base address */
#define LPDAC0_BASE                              (0x4004C000u)
/** Peripheral LPDAC0 base pointer */
#define LPDAC0                                   ((LPDAC_Type *)LPDAC0_BASE)
/** Array initializer of LPDAC peripheral base addresses */
#define LPDAC_BASE_ADDRS                         { LPDAC0_BASE }
/** Array initializer of LPDAC peripheral base pointers */
#define LPDAC_BASE_PTRS                          { LPDAC0 }
/** Interrupt vectors for the LPDAC peripheral type */
#define LPDAC_IRQS                               { LPDAC0_IRQn }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x4003A000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x4003B000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x4003C000u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
/** Peripheral LPI2C3 base address */
#define LPI2C3_BASE                              (0x4102E000u)
/** Peripheral LPI2C3 base pointer */
#define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2, LPI2C3 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn }

/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT0 base address */
#define LPIT0_BASE                               (0x40030000u)
/** Peripheral LPIT0 base pointer */
#define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
/** Peripheral LPIT1 base address */
#define LPIT1_BASE                               (0x4102A000u)
/** Peripheral LPIT1 base pointer */
#define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { LPIT0_BASE, LPIT1_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { LPIT0, LPIT1 }
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { { LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn }, { LPIT1_IRQn, LPIT1_IRQn, LPIT1_IRQn, LPIT1_IRQn } }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x4003F000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x40040000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x40041000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Peripheral LPSPI3 base address */
#define LPSPI3_BASE                              (0x41035000u)
/** Peripheral LPSPI3 base pointer */
#define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2, LPSPI3 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn }

/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0x40032000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
/** Peripheral LPTMR1 base address */
#define LPTMR1_BASE                              (0x40033000u)
/** Peripheral LPTMR1 base pointer */
#define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
/** Peripheral LPTMR2 base address */
#define LPTMR2_BASE                              (0x4102B000u)
/** Peripheral LPTMR2 base pointer */
#define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR0_BASE, LPTMR1_BASE, LPTMR2_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0, LPTMR1, LPTMR2 }
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn, LPTMR1_IRQn, LPTMR2_IRQn }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x40042000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x40043000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x40044000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Peripheral LPUART3 base address */
#define LPUART3_BASE                             (0x41036000u)
/** Peripheral LPUART3 base pointer */
#define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn }

/* MCM - Peripheral instance base addresses */
/** Peripheral MCM1 base address */
#define MCM1_BASE                                (0xF0003000u)
/** Peripheral MCM1 base pointer */
#define MCM1                                     ((MCM_Type *)MCM1_BASE)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS                           { 0u, MCM1_BASE }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { (MCM_Type *)0u, MCM1 }
/* MCM compatibility definitions */
#define MCM_BASE                  MCM1_BASE
#define MCM                       MCM1


/* MMDVSQ - Peripheral instance base addresses */
/** Peripheral MMDVSQ1 base address */
#define MMDVSQ1_BASE                             (0xF0004000u)
/** Peripheral MMDVSQ1 base pointer */
#define MMDVSQ1                                  ((MMDVSQ_Type *)MMDVSQ1_BASE)
/** Array initializer of MMDVSQ peripheral base addresses */
#define MMDVSQ_BASE_ADDRS                        { 0u, MMDVSQ1_BASE }
/** Array initializer of MMDVSQ peripheral base pointers */
#define MMDVSQ_BASE_PTRS                         { (MMDVSQ_Type *)0u, MMDVSQ1 }

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
/** Peripheral MTB base address */
#define MTB_BASE                                 (0xF0000000u)
/** Peripheral MTB base pointer */
#define MTB                                      ((MTB_Type *)MTB_BASE)
/** Array initializer of MTB peripheral base addresses */
#define MTB_BASE_ADDRS                           { MTB_BASE }
/** Array initializer of MTB peripheral base pointers */
#define MTB_BASE_PTRS                            { MTB }

/* MTBDWT - Peripheral instance base addresses */
/** Peripheral MTBDWT base address */
#define MTBDWT_BASE                              (0xF0001000u)
/** Peripheral MTBDWT base pointer */
#define MTBDWT                                   ((MTBDWT_Type *)MTBDWT_BASE)
/** Array initializer of MTBDWT peripheral base addresses */
#define MTBDWT_BASE_ADDRS                        { MTBDWT_BASE }
/** Array initializer of MTBDWT peripheral base pointers */
#define MTBDWT_BASE_PTRS                         { MTBDWT }
/*!
 * @brief Core boot mode.
 */
typedef enum _mu_core_boot_mode
{
    kMU_CoreBootFromPflashBase = 0x00U, /*!< Boot from pflash base.  */
    kMU_CoreBootFromCM4RamBase = 0x02U, /*!< Boot from CM4 RAM base. */
} mu_core_boot_mode_t;
/*!
 * @brief Power mode on the other side definition.
 */
typedef enum _mu_power_mode
{
    kMU_PowerModeRun = 0x00U,  /*!< Run mode.           */
    kMU_PowerModeCoo = 0x01U,  /*!< COO mode.           */
    kMU_PowerModeWait = 0x02U, /*!< WAIT mode.          */
    kMU_PowerModeStop = 0x03U, /*!< STOP/VLPS mode.     */
    kMU_PowerModeDsm = 0x04U   /*!< DSM: LLS/VLLS mode. */
} mu_power_mode_t;


/* MU - Peripheral instance base addresses */
/** Peripheral MUB base address */
#define MUB_BASE                                 (0x41024000u)
/** Peripheral MUB base pointer */
#define MUB                                      ((MU_Type *)MUB_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MUB_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MUB }
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MUB_IRQn }

/* PCC - Peripheral instance base addresses */
/** Peripheral PCC0 base address */
#define PCC0_BASE                                (0x4002B000u)
/** Peripheral PCC0 base pointer */
#define PCC0                                     ((PCC_Type *)PCC0_BASE)
/** Peripheral PCC1 base address */
#define PCC1_BASE                                (0x41027000u)
/** Peripheral PCC1 base pointer */
#define PCC1                                     ((PCC_Type *)PCC1_BASE)
/** Array initializer of PCC peripheral base addresses */
#define PCC_BASE_ADDRS                           { PCC0_BASE, PCC1_BASE }
/** Array initializer of PCC peripheral base pointers */
#define PCC_BASE_PTRS                            { PCC0, PCC1 }

/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x40046000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x40047000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x40048000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x40049000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)
/** Peripheral PORTE base address */
#define PORTE_BASE                               (0x41037000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD, PORTE }
/** Interrupt vectors for the PORT peripheral type */
#define PORT_IRQS                                { PORTA_IRQn, PORTB_IRQn, PORTC_IRQn, PORTD_IRQn, PORTE_IRQn }

/* ROM - Peripheral instance base addresses */
/** Peripheral ROM base address */
#define ROM_BASE                                 (0xF0002000u)
/** Peripheral ROM base pointer */
#define ROM                                      ((ROM_Type *)ROM_BASE)
/** Array initializer of ROM peripheral base addresses */
#define ROM_BASE_ADDRS                           { ROM_BASE }
/** Array initializer of ROM peripheral base pointers */
#define ROM_BASE_PTRS                            { ROM }

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x40031000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }

/* SCG - Peripheral instance base addresses */
/** Peripheral SCG base address */
#define SCG_BASE                                 (0x4002C000u)
/** Peripheral SCG base pointer */
#define SCG                                      ((SCG_Type *)SCG_BASE)
/** Array initializer of SCG peripheral base addresses */
#define SCG_BASE_ADDRS                           { SCG_BASE }
/** Array initializer of SCG peripheral base pointers */
#define SCG_BASE_PTRS                            { SCG }
/** Interrupt vectors for the SCG peripheral type */
#define SCG_IRQS                                 { SCG_IRQn }

/* SEMA42 - Peripheral instance base addresses */
/** Peripheral SEMA420 base address */
#define SEMA420_BASE                             (0x4001B000u)
/** Peripheral SEMA420 base pointer */
#define SEMA420                                  ((SEMA42_Type *)SEMA420_BASE)
/** Peripheral SEMA421 base address */
#define SEMA421_BASE                             (0x4101B000u)
/** Peripheral SEMA421 base pointer */
#define SEMA421                                  ((SEMA42_Type *)SEMA421_BASE)
/** Array initializer of SEMA42 peripheral base addresses */
#define SEMA42_BASE_ADDRS                        { SEMA420_BASE, SEMA421_BASE }
/** Array initializer of SEMA42 peripheral base pointers */
#define SEMA42_BASE_PTRS                         { SEMA420, SEMA421 }

/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x40026000u)
/** Peripheral SIM base pointer */
#define SIM                                      ((SIM_Type *)SIM_BASE)
/** Array initializer of SIM peripheral base addresses */
#define SIM_BASE_ADDRS                           { SIM_BASE }
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM }

/* SMC - Peripheral instance base addresses */
/** Peripheral SMC0 base address */
#define SMC0_BASE                                (0x40020000u)
/** Peripheral SMC0 base pointer */
#define SMC0                                     ((SMC_Type *)SMC0_BASE)
/** Peripheral SMC1 base address */
#define SMC1_BASE                                (0x41020000u)
/** Peripheral SMC1 base pointer */
#define SMC1                                     ((SMC_Type *)SMC1_BASE)
/** Array initializer of SMC peripheral base addresses */
#define SMC_BASE_ADDRS                           { SMC0_BASE, SMC1_BASE }
/** Array initializer of SMC peripheral base pointers */
#define SMC_BASE_PTRS                            { SMC0, SMC1 }
/** Interrupt vectors for the SMC peripheral type */
#define SMC_IRQS                                 { NotAvail_IRQn, MSMC_IRQn }

/* SPM - Peripheral instance base addresses */
/** Peripheral SPM base address */
#define SPM_BASE                                 (0x40028000u)
/** Peripheral SPM base pointer */
#define SPM                                      ((SPM_Type *)SPM_BASE)
/** Array initializer of SPM peripheral base addresses */
#define SPM_BASE_ADDRS                           { SPM_BASE }
/** Array initializer of SPM peripheral base pointers */
#define SPM_BASE_PTRS                            { SPM }
/** Interrupt vectors for the SPM peripheral type */
#define SPM_IRQS                                 { SPM_IRQn }

/* TPM - Peripheral instance base addresses */
/** Peripheral TPM0 base address */
#define TPM0_BASE                                (0x40035000u)
/** Peripheral TPM0 base pointer */
#define TPM0                                     ((TPM_Type *)TPM0_BASE)
/** Peripheral TPM1 base address */
#define TPM1_BASE                                (0x40036000u)
/** Peripheral TPM1 base pointer */
#define TPM1                                     ((TPM_Type *)TPM1_BASE)
/** Peripheral TPM2 base address */
#define TPM2_BASE                                (0x40037000u)
/** Peripheral TPM2 base pointer */
#define TPM2                                     ((TPM_Type *)TPM2_BASE)
/** Peripheral TPM3 base address */
#define TPM3_BASE                                (0x4102D000u)
/** Peripheral TPM3 base pointer */
#define TPM3                                     ((TPM_Type *)TPM3_BASE)
/** Array initializer of TPM peripheral base addresses */
#define TPM_BASE_ADDRS                           { TPM0_BASE, TPM1_BASE, TPM2_BASE, TPM3_BASE }
/** Array initializer of TPM peripheral base pointers */
#define TPM_BASE_PTRS                            { TPM0, TPM1, TPM2, TPM3 }
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { TPM0_IRQn, TPM1_IRQn, TPM2_IRQn, TPM3_IRQn }

/* TRGMUX - Peripheral instance base addresses */
/** Peripheral TRGMUX0 base address */
#define TRGMUX0_BASE                             (0x40029000u)
/** Peripheral TRGMUX0 base pointer */
#define TRGMUX0                                  ((TRGMUX_Type *)TRGMUX0_BASE)
/** Peripheral TRGMUX1 base address */
#define TRGMUX1_BASE                             (0x41025000u)
/** Peripheral TRGMUX1 base pointer */
#define TRGMUX1                                  ((TRGMUX_Type *)TRGMUX1_BASE)
/** Array initializer of TRGMUX peripheral base addresses */
#define TRGMUX_BASE_ADDRS                        { TRGMUX0_BASE, TRGMUX1_BASE }
/** Array initializer of TRGMUX peripheral base pointers */
#define TRGMUX_BASE_PTRS                         { TRGMUX0, TRGMUX1 }

/* TRNG - Peripheral instance base addresses */
/** Peripheral TRNG base address */
#define TRNG_BASE                                (0x41029000u)
/** Peripheral TRNG base pointer */
#define TRNG                                     ((TRNG_Type *)TRNG_BASE)
/** Array initializer of TRNG peripheral base addresses */
#define TRNG_BASE_ADDRS                          { TRNG_BASE }
/** Array initializer of TRNG peripheral base pointers */
#define TRNG_BASE_PTRS                           { TRNG }
/** Interrupt vectors for the TRNG peripheral type */
#define TRNG_IRQS                                { TRNG_IRQn }

/* TSTMR - Peripheral instance base addresses */
/** Peripheral TSTMRB base address */
#define TSTMRB_BASE                              (0x4102C000u)
/** Peripheral TSTMRB base pointer */
#define TSTMRB                                   ((TSTMR_Type *)TSTMRB_BASE)
/** Array initializer of TSTMR peripheral base addresses */
#define TSTMR_BASE_ADDRS                         { TSTMRB_BASE }
/** Array initializer of TSTMR peripheral base pointers */
#define TSTMR_BASE_PTRS                          { TSTMRB }

/* USB - Peripheral instance base addresses */
/** Peripheral USB0 base address */
#define USB0_BASE                                (0x40045000u)
/** Peripheral USB0 base pointer */
#define USB0                                     ((USB_Type *)USB0_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB0_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB0 }
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { USB0_IRQn }

/* USBVREG - Peripheral instance base addresses */
/** Peripheral USBVREG base address */
#define USBVREG_BASE                             (0x40027000u)
/** Peripheral USBVREG base pointer */
#define USBVREG                                  ((USBVREG_Type *)USBVREG_BASE)
/** Array initializer of USBVREG peripheral base addresses */
#define USBVREG_BASE_ADDRS                       { USBVREG_BASE }
/** Array initializer of USBVREG peripheral base pointers */
#define USBVREG_BASE_PTRS                        { USBVREG }

/* USDHC - Peripheral instance base addresses */
/** Peripheral USDHC0 base address */
#define USDHC0_BASE                              (0x4003E000u)
/** Peripheral USDHC0 base pointer */
#define USDHC0                                   ((USDHC_Type *)USDHC0_BASE)
/** Array initializer of USDHC peripheral base addresses */
#define USDHC_BASE_ADDRS                         { USDHC0_BASE }
/** Array initializer of USDHC peripheral base pointers */
#define USDHC_BASE_PTRS                          { USDHC0 }
/** Interrupt vectors for the USDHC peripheral type */
#define USDHC_IRQS                               { USDHC0_IRQn }

/* VREF - Peripheral instance base addresses */
/** Peripheral VREF base address */
#define VREF_BASE                                (0x4004D000u)
/** Peripheral VREF base pointer */
#define VREF                                     ((VREF_Type *)VREF_BASE)
/** Array initializer of VREF peripheral base addresses */
#define VREF_BASE_ADDRS                          { VREF_BASE }
/** Array initializer of VREF peripheral base pointers */
#define VREF_BASE_PTRS                           { VREF }

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG0 base address */
#define WDOG0_BASE                               (0x4002A000u)
/** Peripheral WDOG0 base pointer */
#define WDOG0                                    ((WDOG_Type *)WDOG0_BASE)
/** Peripheral WDOG1 base address */
#define WDOG1_BASE                               (0x41026000u)
/** Peripheral WDOG1 base pointer */
#define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG0_BASE, WDOG1_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG0, WDOG1 }
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { NotAvail_IRQn, WDOG1_IRQn }

/* XRDC - Peripheral instance base addresses */
/** Peripheral XRDC base address */
#define XRDC_BASE                                (0x40014000u)
/** Peripheral XRDC base pointer */
#define XRDC                                     ((XRDC_Type *)XRDC_BASE)
/** Array initializer of XRDC peripheral base addresses */
#define XRDC_BASE_ADDRS                          { XRDC_BASE }
/** Array initializer of XRDC peripheral base pointers */
#define XRDC_BASE_PTRS                           { XRDC }

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

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* K32L3A60_CM0PLUS_COMMON_H_ */

