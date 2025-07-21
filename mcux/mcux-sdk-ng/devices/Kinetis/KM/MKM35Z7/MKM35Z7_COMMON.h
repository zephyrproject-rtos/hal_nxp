/*
** ###################################################################
**     Processors:          MKM35Z256VLL7
**                          MKM35Z256VLL7R
**                          MKM35Z256VLQ7
**                          MKM35Z256VLQ7R
**                          MKM35Z512VLL7
**                          MKM35Z512VLL7R
**                          MKM35Z512VLQ7
**                          MKM35Z512VLQ7R
**
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    KM35P144M75SF0RM, Rev.1, Dec 2019
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MKM35Z7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-08-01)
**         Initial version.
**     - rev. 2.0 (2019-12-20)
**         Based on RM Rev.1.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MKM35Z7_COMMON.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MKM35Z7
 *
 * CMSIS Peripheral Access Layer for MKM35Z7
 */

#if !defined(MKM35Z7_COMMON_H_)
#define MKM35Z7_COMMON_H_                        /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0300U
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
#define NUMBER_OF_INT_VECTORS 48                 /**< Number of interrupts in the Vector table */

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
  DMA0_IRQn                    = 0,                /**< DMA channel 0 transfer complete */
  DMA1_IRQn                    = 1,                /**< DMA channel 1 transfer complete */
  DMA2_IRQn                    = 2,                /**< DMA channel 2 transfer complete */
  DMA3_IRQn                    = 3,                /**< DMA channel 3 transfer complete */
  SPI0_SPI1_SPI2_IRQn          = 4,                /**< SPI0/SPI1/SPI2 ORed interrupt */
  PDB0_IRQn                    = 5,                /**< PDB0 ORed interrupt */
  PMC_IRQn                     = 6,                /**< Low-voltage detect, low-voltage warning */
  TMR0_IRQn                    = 7,                /**< Quad Timer Channel 0 */
  TMR1_IRQn                    = 8,                /**< Quad Timer Channel 1 */
  TMR2_IRQn                    = 9,                /**< Quad Timer Channel 2 */
  TMR3_IRQn                    = 10,               /**< Quad Timer Channel 3 */
  PIT0_PIT1_IRQn               = 11,               /**< PIT0/PIT1 ORed interrupt */
  LLWU_IRQn                    = 12,               /**< Low Leakage Wakeup */
  FTFA_IRQn                    = 13,               /**< Command complete and read collision */
  CMP0_CMP1_CMP2_IRQn          = 14,               /**< CMP0/CMP1/CMP2 ORed interrupt */
  LCD_IRQn                     = 15,               /**< LCD interrupt */
  ADC0_IRQn                    = 16,               /**< ADC0 interrupt */
  PTx_IRQn                     = 17,               /**< Single interrupt vector for GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH,GPIOI,GPIOJ,GPIOK,GPIOL,GPIOM */
  RNGA_IRQn                    = 18,               /**< RNGA interrupt */
  UART0_UART1_UART2_UART3_IRQn = 19,               /**< UART0/UART1/UART2/UART3 ORed interrupt */
  MMAU_IRQn                    = 20,               /**< Memory Mapped Arithmetic Unit interrupt */
  AFE_CH0_IRQn                 = 21,               /**< AFE Channel 0 */
  AFE_CH1_IRQn                 = 22,               /**< AFE Channel 1 */
  AFE_CH2_IRQn                 = 23,               /**< AFE Channel 2 */
  AFE_CH3_IRQn                 = 24,               /**< AFE Channel 3 */
  RTC_IRQn                     = 25,               /**< IRTC interrupt */
  I2C0_I2C1_IRQn               = 26,               /**< I2C0/I2C1 ORed interrupt */
  LPUART0_IRQn                 = 27,               /**< LPUART0 status and error interrupt */
  MCG_IRQn                     = 28,               /**< MCG interrupt */
  WDOG_EWM_IRQn                = 29,               /**< WDOG/EWM ORed interrupt */
  LPTMR0_LPTMR1_IRQn           = 30,               /**< LPTMR0/LPTMR1 interrupt */
  XBAR_IRQn                    = 31                /**< XBAR interrupt */
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
#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if VTOR is present or not */
#define __NVIC_PRIO_BITS               2         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */

#include "core_cm0plus.h"              /* Core Peripheral Access Layer */
#include "system_MKM35Z7.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MKM35Z7_SERIES
#define MKM35Z7_SERIES
#endif
/* CPU specific feature definitions */
#include "MKM35Z7_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x4002B000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn }

/* AFE - Peripheral instance base addresses */
/** Peripheral AFE base address */
#define AFE_BASE                                 (0x40030000u)
/** Peripheral AFE base pointer */
#define AFE                                      ((AFE_Type *)AFE_BASE)
/** Array initializer of AFE peripheral base addresses */
#define AFE_BASE_ADDRS                           { AFE_BASE }
/** Array initializer of AFE peripheral base pointers */
#define AFE_BASE_PTRS                            { AFE }
/** Interrupt vectors for the AFE peripheral type */
#define AFE_IRQS                                 { { AFE_CH0_IRQn, AFE_CH1_IRQn, AFE_CH2_IRQn, AFE_CH3_IRQn } }

/* AIPS - Peripheral instance base addresses */
/** Peripheral AIPS base address */
#define AIPS_BASE                                (0x40000000u)
/** Peripheral AIPS base pointer */
#define AIPS                                     ((AIPS_Type *)AIPS_BASE)
/** Array initializer of AIPS peripheral base addresses */
#define AIPS_BASE_ADDRS                          { AIPS_BASE }
/** Array initializer of AIPS peripheral base pointers */
#define AIPS_BASE_PTRS                           { AIPS }

/* CAU - Peripheral instance base addresses */
/** Peripheral CAU base address */
#define CAU_BASE                                 (0xF0005000u)
/** Peripheral CAU base pointer */
#define CAU                                      ((CAU_Type *)CAU_BASE)
/** Array initializer of CAU peripheral base addresses */
#define CAU_BASE_ADDRS                           { CAU_BASE }
/** Array initializer of CAU peripheral base pointers */
#define CAU_BASE_PTRS                            { CAU }

/* CMP - Peripheral instance base addresses */
/** Peripheral CMP0 base address */
#define CMP0_BASE                                (0x40072000u)
/** Peripheral CMP0 base pointer */
#define CMP0                                     ((CMP_Type *)CMP0_BASE)
/** Peripheral CMP1 base address */
#define CMP1_BASE                                (0x40072008u)
/** Peripheral CMP1 base pointer */
#define CMP1                                     ((CMP_Type *)CMP1_BASE)
/** Peripheral CMP2 base address */
#define CMP2_BASE                                (0x40072010u)
/** Peripheral CMP2 base pointer */
#define CMP2                                     ((CMP_Type *)CMP2_BASE)
/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           { CMP0_BASE, CMP1_BASE, CMP2_BASE }
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { CMP0, CMP1, CMP2 }
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { CMP0_CMP1_CMP2_IRQn, CMP0_CMP1_CMP2_IRQn, CMP0_CMP1_CMP2_IRQn }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base address */
#define CRC_BASE                                 (0x40034000u)
/** Peripheral CRC base pointer */
#define CRC0                                     ((CRC_Type *)CRC_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC0 }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA base address */
#define DMA_BASE                                 (0x40008000u)
/** Peripheral DMA base pointer */
#define DMA0                                     ((DMA_Type *)DMA_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_CHN_IRQS                             { { DMA0_IRQn, DMA1_IRQn, DMA2_IRQn, DMA3_IRQn } }

/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX base address */
#define DMAMUX_BASE                              (0x40021000u)
/** Peripheral DMAMUX base pointer */
#define DMAMUX                                   ((DMAMUX_Type *)DMAMUX_BASE)
/** Array initializer of DMAMUX peripheral base addresses */
#define DMAMUX_BASE_ADDRS                        { DMAMUX_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { DMAMUX }

/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base address */
#define EWM_BASE                                 (0x40061000u)
/** Peripheral EWM base pointer */
#define EWM                                      ((EWM_Type *)EWM_BASE)
/** Array initializer of EWM peripheral base addresses */
#define EWM_BASE_ADDRS                           { EWM_BASE }
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASE_PTRS                            { EWM }
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { WDOG_EWM_IRQn }

/* FGPIO - Peripheral instance base addresses */
/** Peripheral FGPIOA base address */
#define FGPIOA_BASE                              (0xF8000000u)
/** Peripheral FGPIOA base pointer */
#define FGPIOA                                   ((FGPIO_Type *)FGPIOA_BASE)
/** Peripheral FGPIOB base address */
#define FGPIOB_BASE                              (0xF8000001u)
/** Peripheral FGPIOB base pointer */
#define FGPIOB                                   ((FGPIO_Type *)FGPIOB_BASE)
/** Peripheral FGPIOC base address */
#define FGPIOC_BASE                              (0xF8000002u)
/** Peripheral FGPIOC base pointer */
#define FGPIOC                                   ((FGPIO_Type *)FGPIOC_BASE)
/** Peripheral FGPIOD base address */
#define FGPIOD_BASE                              (0xF8000003u)
/** Peripheral FGPIOD base pointer */
#define FGPIOD                                   ((FGPIO_Type *)FGPIOD_BASE)
/** Peripheral FGPIOE base address */
#define FGPIOE_BASE                              (0xF8000040u)
/** Peripheral FGPIOE base pointer */
#define FGPIOE                                   ((FGPIO_Type *)FGPIOE_BASE)
/** Peripheral FGPIOF base address */
#define FGPIOF_BASE                              (0xF8000041u)
/** Peripheral FGPIOF base pointer */
#define FGPIOF                                   ((FGPIO_Type *)FGPIOF_BASE)
/** Peripheral FGPIOG base address */
#define FGPIOG_BASE                              (0xF8000042u)
/** Peripheral FGPIOG base pointer */
#define FGPIOG                                   ((FGPIO_Type *)FGPIOG_BASE)
/** Peripheral FGPIOH base address */
#define FGPIOH_BASE                              (0xF8000043u)
/** Peripheral FGPIOH base pointer */
#define FGPIOH                                   ((FGPIO_Type *)FGPIOH_BASE)
/** Peripheral FGPIOI base address */
#define FGPIOI_BASE                              (0xF8000080u)
/** Peripheral FGPIOI base pointer */
#define FGPIOI                                   ((FGPIO_Type *)FGPIOI_BASE)
/** Peripheral FGPIOJ base address */
#define FGPIOJ_BASE                              (0xF8000081u)
/** Peripheral FGPIOJ base pointer */
#define FGPIOJ                                   ((FGPIO_Type *)FGPIOJ_BASE)
/** Peripheral FGPIOK base address */
#define FGPIOK_BASE                              (0xF8000082u)
/** Peripheral FGPIOK base pointer */
#define FGPIOK                                   ((FGPIO_Type *)FGPIOK_BASE)
/** Peripheral FGPIOL base address */
#define FGPIOL_BASE                              (0xF8000083u)
/** Peripheral FGPIOL base pointer */
#define FGPIOL                                   ((FGPIO_Type *)FGPIOL_BASE)
/** Peripheral FGPIOM base address */
#define FGPIOM_BASE                              (0xF80000C0u)
/** Peripheral FGPIOM base pointer */
#define FGPIOM                                   ((FGPIO_Type *)FGPIOM_BASE)
/** Array initializer of FGPIO peripheral base addresses */
#define FGPIO_BASE_ADDRS                         { FGPIOA_BASE, FGPIOB_BASE, FGPIOC_BASE, FGPIOD_BASE, FGPIOE_BASE, FGPIOF_BASE, FGPIOG_BASE, FGPIOH_BASE, FGPIOI_BASE, FGPIOJ_BASE, FGPIOK_BASE, FGPIOL_BASE, FGPIOM_BASE }
/** Array initializer of FGPIO peripheral base pointers */
#define FGPIO_BASE_PTRS                          { FGPIOA, FGPIOB, FGPIOC, FGPIOD, FGPIOE, FGPIOF, FGPIOG, FGPIOH, FGPIOI, FGPIOJ, FGPIOK, FGPIOL, FGPIOM }

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
#define GPIOA_BASE                               (0x400FF000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                    ((GPIO_Type *)GPIOA_BASE)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                               (0x400FF001u)
/** Peripheral GPIOB base pointer */
#define GPIOB                                    ((GPIO_Type *)GPIOB_BASE)
/** Peripheral GPIOC base address */
#define GPIOC_BASE                               (0x400FF002u)
/** Peripheral GPIOC base pointer */
#define GPIOC                                    ((GPIO_Type *)GPIOC_BASE)
/** Peripheral GPIOD base address */
#define GPIOD_BASE                               (0x400FF003u)
/** Peripheral GPIOD base pointer */
#define GPIOD                                    ((GPIO_Type *)GPIOD_BASE)
/** Peripheral GPIOE base address */
#define GPIOE_BASE                               (0x400FF040u)
/** Peripheral GPIOE base pointer */
#define GPIOE                                    ((GPIO_Type *)GPIOE_BASE)
/** Peripheral GPIOF base address */
#define GPIOF_BASE                               (0x400FF041u)
/** Peripheral GPIOF base pointer */
#define GPIOF                                    ((GPIO_Type *)GPIOF_BASE)
/** Peripheral GPIOG base address */
#define GPIOG_BASE                               (0x400FF042u)
/** Peripheral GPIOG base pointer */
#define GPIOG                                    ((GPIO_Type *)GPIOG_BASE)
/** Peripheral GPIOH base address */
#define GPIOH_BASE                               (0x400FF043u)
/** Peripheral GPIOH base pointer */
#define GPIOH                                    ((GPIO_Type *)GPIOH_BASE)
/** Peripheral GPIOI base address */
#define GPIOI_BASE                               (0x400FF080u)
/** Peripheral GPIOI base pointer */
#define GPIOI                                    ((GPIO_Type *)GPIOI_BASE)
/** Peripheral GPIOJ base address */
#define GPIOJ_BASE                               (0x400FF081u)
/** Peripheral GPIOJ base pointer */
#define GPIOJ                                    ((GPIO_Type *)GPIOJ_BASE)
/** Peripheral GPIOK base address */
#define GPIOK_BASE                               (0x400FF082u)
/** Peripheral GPIOK base pointer */
#define GPIOK                                    ((GPIO_Type *)GPIOK_BASE)
/** Peripheral GPIOL base address */
#define GPIOL_BASE                               (0x400FF083u)
/** Peripheral GPIOL base pointer */
#define GPIOL                                    ((GPIO_Type *)GPIOL_BASE)
/** Peripheral GPIOM base address */
#define GPIOM_BASE                               (0x400FF0C0u)
/** Peripheral GPIOM base pointer */
#define GPIOM                                    ((GPIO_Type *)GPIOM_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE, GPIOF_BASE, GPIOG_BASE, GPIOH_BASE, GPIOI_BASE, GPIOJ_BASE, GPIOK_BASE, GPIOL_BASE, GPIOM_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH, GPIOI, GPIOJ, GPIOK, GPIOL, GPIOM }

/* I2C - Peripheral instance base addresses */
/** Peripheral I2C0 base address */
#define I2C0_BASE                                (0x40067000u)
/** Peripheral I2C0 base pointer */
#define I2C0                                     ((I2C_Type *)I2C0_BASE)
/** Peripheral I2C1 base address */
#define I2C1_BASE                                (0x40068000u)
/** Peripheral I2C1 base pointer */
#define I2C1                                     ((I2C_Type *)I2C1_BASE)
/** Array initializer of I2C peripheral base addresses */
#define I2C_BASE_ADDRS                           { I2C0_BASE, I2C1_BASE }
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { I2C0, I2C1 }
/** Interrupt vectors for the I2C peripheral type */
#define I2C_IRQS                                 { I2C0_I2C1_IRQn, I2C0_I2C1_IRQn }

/* LCD - Peripheral instance base addresses */
/** Peripheral LCD base address */
#define LCD_BASE                                 (0x40043000u)
/** Peripheral LCD base pointer */
#define LCD                                      ((LCD_Type *)LCD_BASE)
/** Array initializer of LCD peripheral base addresses */
#define LCD_BASE_ADDRS                           { LCD_BASE }
/** Array initializer of LCD peripheral base pointers */
#define LCD_BASE_PTRS                            { LCD }
/** Interrupt vectors for the LCD peripheral type */
#define LCD_LCD_IRQS                             { LCD_IRQn }

/* LLWU - Peripheral instance base addresses */
/** Peripheral LLWU base address */
#define LLWU_BASE                                (0x4007C000u)
/** Peripheral LLWU base pointer */
#define LLWU                                     ((LLWU_Type *)LLWU_BASE)
/** Array initializer of LLWU peripheral base addresses */
#define LLWU_BASE_ADDRS                          { LLWU_BASE }
/** Array initializer of LLWU peripheral base pointers */
#define LLWU_BASE_PTRS                           { LLWU }
/** Interrupt vectors for the LLWU peripheral type */
#define LLWU_IRQS                                { LLWU_IRQn }

/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0x4003C000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
/** Peripheral LPTMR1 base address */
#define LPTMR1_BASE                              (0x4003D000u)
/** Peripheral LPTMR1 base pointer */
#define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR0_BASE, LPTMR1_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0, LPTMR1 }
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_LPTMR1_IRQn, LPTMR0_LPTMR1_IRQn }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x4002A000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_IRQn }

/* MCG - Peripheral instance base addresses */
/** Peripheral MCG base address */
#define MCG_BASE                                 (0x40064000u)
/** Peripheral MCG base pointer */
#define MCG                                      ((MCG_Type *)MCG_BASE)
/** Array initializer of MCG peripheral base addresses */
#define MCG_BASE_ADDRS                           { MCG_BASE }
/** Array initializer of MCG peripheral base pointers */
#define MCG_BASE_PTRS                            { MCG }
/** Interrupt vectors for the MCG peripheral type */
#define MCG_IRQS                                 { MCG_IRQn }

/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base address */
#define MCM_BASE                                 (0xF0003000u)
/** Peripheral MCM base pointer */
#define MCM                                      ((MCM_Type *)MCM_BASE)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS                           { MCM_BASE }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM }

/* MMAU - Peripheral instance base addresses */
/** Peripheral MMAU base address */
#define MMAU_BASE                                (0xF0004000u)
/** Peripheral MMAU base pointer */
#define MMAU                                     ((MMAU_Type *)MMAU_BASE)
/** Array initializer of MMAU peripheral base addresses */
#define MMAU_BASE_ADDRS                          { MMAU_BASE }
/** Array initializer of MMAU peripheral base pointers */
#define MMAU_BASE_PTRS                           { MMAU }
/** Interrupt vectors for the MMAU peripheral type */
#define MMAU_IRQS                                { MMAU_IRQn }

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

/* NV - Peripheral instance base addresses */
/** Peripheral FTFA_FlashConfig base address */
#define FTFA_FlashConfig_BASE                    (0x400u)
/** Peripheral FTFA_FlashConfig base pointer */
#define FTFA_FlashConfig                         ((NV_Type *)FTFA_FlashConfig_BASE)
/** Array initializer of NV peripheral base addresses */
#define NV_BASE_ADDRS                            { FTFA_FlashConfig_BASE }
/** Array initializer of NV peripheral base pointers */
#define NV_BASE_PTRS                             { FTFA_FlashConfig }

/* OSC - Peripheral instance base addresses */
/** Peripheral OSC base address */
#define OSC_BASE                                 (0x40066000u)
/** Peripheral OSC base pointer */
#define OSC                                      ((OSC_Type *)OSC_BASE)
/** Array initializer of OSC peripheral base addresses */
#define OSC_BASE_ADDRS                           { OSC_BASE }
/** Array initializer of OSC peripheral base pointers */
#define OSC_BASE_PTRS                            { OSC }

/* PDB - Peripheral instance base addresses */
/** Peripheral PDB0 base address */
#define PDB0_BASE                                (0x40036000u)
/** Peripheral PDB0 base pointer */
#define PDB0                                     ((PDB_Type *)PDB0_BASE)
/** Array initializer of PDB peripheral base addresses */
#define PDB_BASE_ADDRS                           { PDB0_BASE }
/** Array initializer of PDB peripheral base pointers */
#define PDB_BASE_PTRS                            { PDB0 }
/** Interrupt vectors for the PDB peripheral type */
#define PDB_IRQS                                 { PDB0_IRQn }

/* PIT - Peripheral instance base addresses */
/** Peripheral PIT0 base address */
#define PIT0_BASE                                (0x4002D000u)
/** Peripheral PIT0 base pointer */
#define PIT0                                     ((PIT_Type *)PIT0_BASE)
/** Peripheral PIT1 base address */
#define PIT1_BASE                                (0x4002E000u)
/** Peripheral PIT1 base pointer */
#define PIT1                                     ((PIT_Type *)PIT1_BASE)
/** Array initializer of PIT peripheral base addresses */
#define PIT_BASE_ADDRS                           { PIT0_BASE, PIT1_BASE }
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            { PIT0, PIT1 }
/** Interrupt vectors for the PIT peripheral type */
#define PIT_IRQS                                 { { PIT0_PIT1_IRQn, PIT0_PIT1_IRQn }, { PIT0_PIT1_IRQn, PIT0_PIT1_IRQn } }

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
#define PORTE_BASE                               (0x4004A000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)
/** Peripheral PORTF base address */
#define PORTF_BASE                               (0x4004B000u)
/** Peripheral PORTF base pointer */
#define PORTF                                    ((PORT_Type *)PORTF_BASE)
/** Peripheral PORTG base address */
#define PORTG_BASE                               (0x4004C000u)
/** Peripheral PORTG base pointer */
#define PORTG                                    ((PORT_Type *)PORTG_BASE)
/** Peripheral PORTH base address */
#define PORTH_BASE                               (0x4004D000u)
/** Peripheral PORTH base pointer */
#define PORTH                                    ((PORT_Type *)PORTH_BASE)
/** Peripheral PORTI base address */
#define PORTI_BASE                               (0x4004E000u)
/** Peripheral PORTI base pointer */
#define PORTI                                    ((PORT_Type *)PORTI_BASE)
/** Peripheral PORTJ base address */
#define PORTJ_BASE                               (0x40037000u)
/** Peripheral PORTJ base pointer */
#define PORTJ                                    ((PORT_Type *)PORTJ_BASE)
/** Peripheral PORTK base address */
#define PORTK_BASE                               (0x40038000u)
/** Peripheral PORTK base pointer */
#define PORTK                                    ((PORT_Type *)PORTK_BASE)
/** Peripheral PORTL base address */
#define PORTL_BASE                               (0x40039000u)
/** Peripheral PORTL base pointer */
#define PORTL                                    ((PORT_Type *)PORTL_BASE)
/** Peripheral PORTM base address */
#define PORTM_BASE                               (0x4003A000u)
/** Peripheral PORTM base pointer */
#define PORTM                                    ((PORT_Type *)PORTM_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE, PORTF_BASE, PORTG_BASE, PORTH_BASE, PORTI_BASE, PORTJ_BASE, PORTK_BASE, PORTL_BASE, PORTM_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG, PORTH, PORTI, PORTJ, PORTK, PORTL, PORTM }
/** Interrupt vectors for the PORT peripheral type */
#define PORT_IRQS                                { PTx_IRQn, PTx_IRQn, PTx_IRQn, PTx_IRQn, PTx_IRQn, PTx_IRQn, PTx_IRQn, PTx_IRQn, PTx_IRQn, PTx_IRQn, PTx_IRQn, PTx_IRQn, PTx_IRQn }

/* RCM - Peripheral instance base addresses */
/** Peripheral RCM base address */
#define RCM_BASE                                 (0x4007B000u)
/** Peripheral RCM base pointer */
#define RCM                                      ((RCM_Type *)RCM_BASE)
/** Array initializer of RCM peripheral base addresses */
#define RCM_BASE_ADDRS                           { RCM_BASE }
/** Array initializer of RCM peripheral base pointers */
#define RCM_BASE_PTRS                            { RCM }

/* RNG - Peripheral instance base addresses */
/** Peripheral RNG base address */
#define RNG_BASE                                 (0x40029000u)
/** Peripheral RNG base pointer */
#define RNG                                      ((RNG_Type *)RNG_BASE)
/** Array initializer of RNG peripheral base addresses */
#define RNG_BASE_ADDRS                           { RNG_BASE }
/** Array initializer of RNG peripheral base pointers */
#define RNG_BASE_PTRS                            { RNG }
/** Interrupt vectors for the RNG peripheral type */
#define RNG_IRQS                                 { RNGA_IRQn }

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
#define RTC_BASE                                 (0x40050000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }

/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x4003E000u)
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

/* SPI - Peripheral instance base addresses */
/** Peripheral SPI0 base address */
#define SPI0_BASE                                (0x40075000u)
/** Peripheral SPI0 base pointer */
#define SPI0                                     ((SPI_Type *)SPI0_BASE)
/** Peripheral SPI1 base address */
#define SPI1_BASE                                (0x40076000u)
/** Peripheral SPI1 base pointer */
#define SPI1                                     ((SPI_Type *)SPI1_BASE)
/** Peripheral SPI2 base address */
#define SPI2_BASE                                (0x40077000u)
/** Peripheral SPI2 base pointer */
#define SPI2                                     ((SPI_Type *)SPI2_BASE)
/** Array initializer of SPI peripheral base addresses */
#define SPI_BASE_ADDRS                           { SPI0_BASE, SPI1_BASE, SPI2_BASE }
/** Array initializer of SPI peripheral base pointers */
#define SPI_BASE_PTRS                            { SPI0, SPI1, SPI2 }
/** Interrupt vectors for the SPI peripheral type */
#define SPI_IRQS                                 { SPI0_SPI1_SPI2_IRQn, SPI0_SPI1_SPI2_IRQn, SPI0_SPI1_SPI2_IRQn }

/* SYSMPU - Peripheral instance base addresses */
/** Peripheral SYSMPU base address */
#define SYSMPU_BASE                              (0x4000A000u)
/** Peripheral SYSMPU base pointer */
#define SYSMPU                                   ((SYSMPU_Type *)SYSMPU_BASE)
/** Array initializer of SYSMPU peripheral base addresses */
#define SYSMPU_BASE_ADDRS                        { SYSMPU_BASE }
/** Array initializer of SYSMPU peripheral base pointers */
#define SYSMPU_BASE_PTRS                         { SYSMPU }

/* TMR - Peripheral instance base addresses */
/** Peripheral TMR0 base address */
#define TMR0_BASE                                (0x40057000u)
/** Peripheral TMR0 base pointer */
#define TMR0                                     ((TMR_Type *)TMR0_BASE)
/** Peripheral TMR1 base address */
#define TMR1_BASE                                (0x40058000u)
/** Peripheral TMR1 base pointer */
#define TMR1                                     ((TMR_Type *)TMR1_BASE)
/** Peripheral TMR2 base address */
#define TMR2_BASE                                (0x40059000u)
/** Peripheral TMR2 base pointer */
#define TMR2                                     ((TMR_Type *)TMR2_BASE)
/** Peripheral TMR3 base address */
#define TMR3_BASE                                (0x4005A000u)
/** Peripheral TMR3 base pointer */
#define TMR3                                     ((TMR_Type *)TMR3_BASE)
/** Array initializer of TMR peripheral base addresses */
#define TMR_BASE_ADDRS                           { TMR0_BASE, TMR1_BASE, TMR2_BASE, TMR3_BASE }
/** Array initializer of TMR peripheral base pointers */
#define TMR_BASE_PTRS                            { TMR0, TMR1, TMR2, TMR3 }
/** Interrupt vectors for the TMR peripheral type */
#define TMR_IRQS                                 { TMR0_IRQn, TMR1_IRQn, TMR2_IRQn, TMR3_IRQn }

/* UART - Peripheral instance base addresses */
/** Peripheral UART0 base address */
#define UART0_BASE                               (0x4006A000u)
/** Peripheral UART0 base pointer */
#define UART0                                    ((UART_Type *)UART0_BASE)
/** Peripheral UART1 base address */
#define UART1_BASE                               (0x4006B000u)
/** Peripheral UART1 base pointer */
#define UART1                                    ((UART_Type *)UART1_BASE)
/** Peripheral UART2 base address */
#define UART2_BASE                               (0x4006C000u)
/** Peripheral UART2 base pointer */
#define UART2                                    ((UART_Type *)UART2_BASE)
/** Peripheral UART3 base address */
#define UART3_BASE                               (0x4006D000u)
/** Peripheral UART3 base pointer */
#define UART3                                    ((UART_Type *)UART3_BASE)
/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS                          { UART0_BASE, UART1_BASE, UART2_BASE, UART3_BASE }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                           { UART0, UART1, UART2, UART3 }
/** Interrupt vectors for the UART peripheral type */
#define UART_RX_TX_IRQS                          { UART0_UART1_UART2_UART3_IRQn, UART0_UART1_UART2_UART3_IRQn, UART0_UART1_UART2_UART3_IRQn, UART0_UART1_UART2_UART3_IRQn }
#define UART_ERR_IRQS                            { UART0_UART1_UART2_UART3_IRQn, UART0_UART1_UART2_UART3_IRQn, UART0_UART1_UART2_UART3_IRQn, UART0_UART1_UART2_UART3_IRQn }

/* VREF - Peripheral instance base addresses */
/** Peripheral VREF base address */
#define VREF_BASE                                (0x4006F000u)
/** Peripheral VREF base pointer */
#define VREF                                     ((VREF_Type *)VREF_BASE)
/** Array initializer of VREF peripheral base addresses */
#define VREF_BASE_ADDRS                          { VREF_BASE }
/** Array initializer of VREF peripheral base pointers */
#define VREF_BASE_PTRS                           { VREF }

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base address */
#define WDOG_BASE                                (0x40053000u)
/** Peripheral WDOG base pointer */
#define WDOG                                     ((WDOG_Type *)WDOG_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG }
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { WDOG_EWM_IRQn }

/* XBAR - Peripheral instance base addresses */
/** Peripheral XBAR base address */
#define XBAR_BASE                                (0x40055000u)
/** Peripheral XBAR base pointer */
#define XBAR                                     ((XBAR_Type *)XBAR_BASE)
/** Array initializer of XBAR peripheral base addresses */
#define XBAR_BASE_ADDRS                          { XBAR_BASE }
/** Array initializer of XBAR peripheral base pointers */
#define XBAR_BASE_PTRS                           { XBAR }
/** Interrupt vectors for the XBAR peripheral type */
#define XBAR_IRQS                                { XBAR_IRQn }

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


#endif  /* MKM35Z7_COMMON_H_ */

