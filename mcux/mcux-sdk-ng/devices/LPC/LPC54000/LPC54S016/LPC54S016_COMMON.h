/*
** ###################################################################
**     Processors:          LPC54S016JBD100
**                          LPC54S016JBD208
**                          LPC54S016JET100
**                          LPC54S016JET180
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC540xx/LPC54S0xx User manual Rev.0.8 5 June 2018
**     Version:             rev. 1.2, 2017-06-08
**     Build:               b240704
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPC54S016
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**
** ###################################################################
*/

/*!
 * @file LPC54S016_COMMON.h
 * @version 1.2
 * @date 2017-06-08
 * @brief CMSIS Peripheral Access Layer for LPC54S016
 *
 * CMSIS Peripheral Access Layer for LPC54S016
 */

#if !defined(LPC54S016_COMMON_H_)
#define LPC54S016_COMMON_H_                      /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0002U


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 75                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M4 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M4 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M4 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M4 Usage Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M4 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M4 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M4 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M4 System Tick Interrupt */

  /* Device specific interrupts */
  WDT_BOD_IRQn                 = 0,                /**< Windowed watchdog timer, Brownout detect */
  DMA0_IRQn                    = 1,                /**< DMA controller */
  GINT0_IRQn                   = 2,                /**< GPIO group 0 */
  GINT1_IRQn                   = 3,                /**< GPIO group 1 */
  PIN_INT0_IRQn                = 4,                /**< Pin interrupt 0 or pattern match engine slice 0 */
  PIN_INT1_IRQn                = 5,                /**< Pin interrupt 1or pattern match engine slice 1 */
  PIN_INT2_IRQn                = 6,                /**< Pin interrupt 2 or pattern match engine slice 2 */
  PIN_INT3_IRQn                = 7,                /**< Pin interrupt 3 or pattern match engine slice 3 */
  UTICK0_IRQn                  = 8,                /**< Micro-tick Timer */
  MRT0_IRQn                    = 9,                /**< Multi-rate timer */
  CTIMER0_IRQn                 = 10,               /**< Standard counter/timer CTIMER0 */
  CTIMER1_IRQn                 = 11,               /**< Standard counter/timer CTIMER1 */
  SCT0_IRQn                    = 12,               /**< SCTimer/PWM */
  CTIMER3_IRQn                 = 13,               /**< Standard counter/timer CTIMER3 */
  FLEXCOMM0_IRQn               = 14,               /**< Flexcomm Interface 0 (USART, SPI, I2C, FLEXCOMM) */
  FLEXCOMM1_IRQn               = 15,               /**< Flexcomm Interface 1 (USART, SPI, I2C, FLEXCOMM) */
  FLEXCOMM2_IRQn               = 16,               /**< Flexcomm Interface 2 (USART, SPI, I2C, FLEXCOMM) */
  FLEXCOMM3_IRQn               = 17,               /**< Flexcomm Interface 3 (USART, SPI, I2C, FLEXCOMM) */
  FLEXCOMM4_IRQn               = 18,               /**< Flexcomm Interface 4 (USART, SPI, I2C, FLEXCOMM) */
  FLEXCOMM5_IRQn               = 19,               /**< Flexcomm Interface 5 (USART, SPI, I2C,, FLEXCOMM) */
  FLEXCOMM6_IRQn               = 20,               /**< Flexcomm Interface 6 (USART, SPI, I2C, I2S,, FLEXCOMM) */
  FLEXCOMM7_IRQn               = 21,               /**< Flexcomm Interface 7 (USART, SPI, I2C, I2S,, FLEXCOMM) */
  ADC0_SEQA_IRQn               = 22,               /**< ADC0 sequence A completion. */
  ADC0_SEQB_IRQn               = 23,               /**< ADC0 sequence B completion. */
  ADC0_THCMP_IRQn              = 24,               /**< ADC0 threshold compare and error. */
  DMIC0_IRQn                   = 25,               /**< Digital microphone and DMIC subsystem */
  HWVAD0_IRQn                  = 26,               /**< Hardware Voice Activity Detector */
  USB0_NEEDCLK_IRQn            = 27,               /**< USB Activity Wake-up Interrupt */
  USB0_IRQn                    = 28,               /**< USB device */
  RTC_IRQn                     = 29,               /**< RTC alarm and wake-up interrupts */
  FLEXCOMM10_IRQn              = 30,               /**< Flexcomm Interface 10 (SPI, FLEXCOMM) */
  Reserved47_IRQn              = 31,               /**< Reserved interrupt */
  PIN_INT4_IRQn                = 32,               /**< Pin interrupt 4 or pattern match engine slice 4 int */
  PIN_INT5_IRQn                = 33,               /**< Pin interrupt 5 or pattern match engine slice 5 int */
  PIN_INT6_IRQn                = 34,               /**< Pin interrupt 6 or pattern match engine slice 6 int */
  PIN_INT7_IRQn                = 35,               /**< Pin interrupt 7 or pattern match engine slice 7 int */
  CTIMER2_IRQn                 = 36,               /**< Standard counter/timer CTIMER2 */
  CTIMER4_IRQn                 = 37,               /**< Standard counter/timer CTIMER4 */
  RIT_IRQn                     = 38,               /**< Repetitive Interrupt Timer */
  SPIFI0_IRQn                  = 39,               /**< SPI flash interface */
  FLEXCOMM8_IRQn               = 40,               /**< Flexcomm Interface 8 (USART, SPI, I2C, FLEXCOMM) */
  FLEXCOMM9_IRQn               = 41,               /**< Flexcomm Interface 9 (USART, SPI, I2C, FLEXCOMM) */
  SDIO_IRQn                    = 42,               /**< SD/MMC  */
  CAN0_IRQ0_IRQn               = 43,               /**< CAN0 interrupt0 */
  CAN0_IRQ1_IRQn               = 44,               /**< CAN0 interrupt1 */
  CAN1_IRQ0_IRQn               = 45,               /**< CAN1 interrupt0 */
  CAN1_IRQ1_IRQn               = 46,               /**< CAN1 interrupt1 */
  USB1_IRQn                    = 47,               /**< USB1 interrupt */
  USB1_NEEDCLK_IRQn            = 48,               /**< USB1 activity */
  ETHERNET_IRQn                = 49,               /**< Ethernet */
  ETHERNET_PMT_IRQn            = 50,               /**< Ethernet power management interrupt */
  ETHERNET_MACLP_IRQn          = 51,               /**< Ethernet MAC interrupt */
  Reserved68_IRQn              = 52,               /**< Reserved interrupt */
  LCD_IRQn                     = 53,               /**< LCD interrupt */
  SHA_IRQn                     = 54,               /**< SHA interrupt */
  SMARTCARD0_IRQn              = 55,               /**< Smart card 0 interrupt */
  SMARTCARD1_IRQn              = 56,               /**< Smart card 1 interrupt */
  Reserved73_IRQn              = 57,               /**< Reserved interrupt */
  PUF_IRQn                     = 58                /**< PUF interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M4 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M4 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               3         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */

#include "core_cm4.h"                  /* Core Peripheral Access Layer */
#include "system_LPC54S016.h"          /* Device specific configuration file */

#define LPC54S016_SERIES
/* CPU specific feature definitions */
#include "LPC54S016_features.h"

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x400A0000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_SEQ_IRQS                             { ADC0_SEQA_IRQn, ADC0_SEQB_IRQn }
#define ADC_THCMP_IRQS                           { ADC0_THCMP_IRQn }

/* AES - Peripheral instance base addresses */
/** Peripheral AES0 base address */
#define AES0_BASE                                (0x400A1000u)
/** Peripheral AES0 base pointer */
#define AES0                                     ((AES_Type *)AES0_BASE)
/** Array initializer of AES peripheral base addresses */
#define AES_BASE_ADDRS                           { AES0_BASE }
/** Array initializer of AES peripheral base pointers */
#define AES_BASE_PTRS                            { AES0 }

/* ASYNC_SYSCON - Peripheral instance base addresses */
/** Peripheral ASYNC_SYSCON base address */
#define ASYNC_SYSCON_BASE                        (0x40040000u)
/** Peripheral ASYNC_SYSCON base pointer */
#define ASYNC_SYSCON                             ((ASYNC_SYSCON_Type *)ASYNC_SYSCON_BASE)
/** Array initializer of ASYNC_SYSCON peripheral base addresses */
#define ASYNC_SYSCON_BASE_ADDRS                  { ASYNC_SYSCON_BASE }
/** Array initializer of ASYNC_SYSCON peripheral base pointers */
#define ASYNC_SYSCON_BASE_PTRS                   { ASYNC_SYSCON }

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base address */
#define CAN0_BASE                                (0x4009D000u)
/** Peripheral CAN0 base pointer */
#define CAN0                                     ((CAN_Type *)CAN0_BASE)
/** Peripheral CAN1 base address */
#define CAN1_BASE                                (0x4009E000u)
/** Peripheral CAN1 base pointer */
#define CAN1                                     ((CAN_Type *)CAN1_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { CAN0_BASE, CAN1_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { CAN0, CAN1 }
/** Interrupt vectors for the CAN peripheral type */
#define CAN_IRQS                                 { { CAN0_IRQ0_IRQn, CAN0_IRQ1_IRQn }, { CAN1_IRQ0_IRQn, CAN1_IRQ1_IRQn } }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC_ENGINE base address */
#define CRC_ENGINE_BASE                          (0x40095000u)
/** Peripheral CRC_ENGINE base pointer */
#define CRC_ENGINE                               ((CRC_Type *)CRC_ENGINE_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_ENGINE_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC_ENGINE }

/* CTIMER - Peripheral instance base addresses */
/** Peripheral CTIMER0 base address */
#define CTIMER0_BASE                             (0x40008000u)
/** Peripheral CTIMER0 base pointer */
#define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
/** Peripheral CTIMER1 base address */
#define CTIMER1_BASE                             (0x40009000u)
/** Peripheral CTIMER1 base pointer */
#define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
/** Peripheral CTIMER2 base address */
#define CTIMER2_BASE                             (0x40028000u)
/** Peripheral CTIMER2 base pointer */
#define CTIMER2                                  ((CTIMER_Type *)CTIMER2_BASE)
/** Peripheral CTIMER3 base address */
#define CTIMER3_BASE                             (0x40048000u)
/** Peripheral CTIMER3 base pointer */
#define CTIMER3                                  ((CTIMER_Type *)CTIMER3_BASE)
/** Peripheral CTIMER4 base address */
#define CTIMER4_BASE                             (0x40049000u)
/** Peripheral CTIMER4 base pointer */
#define CTIMER4                                  ((CTIMER_Type *)CTIMER4_BASE)
/** Array initializer of CTIMER peripheral base addresses */
#define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE, CTIMER2_BASE, CTIMER3_BASE, CTIMER4_BASE }
/** Array initializer of CTIMER peripheral base pointers */
#define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1, CTIMER2, CTIMER3, CTIMER4 }
/** Interrupt vectors for the CTIMER peripheral type */
#define CTIMER_IRQS                              { CTIMER0_IRQn, CTIMER1_IRQn, CTIMER2_IRQn, CTIMER3_IRQn, CTIMER4_IRQn }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x40082000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { DMA0_IRQn }

/* DMIC - Peripheral instance base addresses */
/** Peripheral DMIC0 base address */
#define DMIC0_BASE                               (0x40090000u)
/** Peripheral DMIC0 base pointer */
#define DMIC0                                    ((DMIC_Type *)DMIC0_BASE)
/** Array initializer of DMIC peripheral base addresses */
#define DMIC_BASE_ADDRS                          { DMIC0_BASE }
/** Array initializer of DMIC peripheral base pointers */
#define DMIC_BASE_PTRS                           { DMIC0 }
/** Interrupt vectors for the DMIC peripheral type */
#define DMIC_IRQS                                { DMIC0_IRQn }
#define DMIC_HWVAD_IRQS                          { HWVAD0_IRQn }

/* EMC - Peripheral instance base addresses */
/** Peripheral EMC base address */
#define EMC_BASE                                 (0x40081000u)
/** Peripheral EMC base pointer */
#define EMC                                      ((EMC_Type *)EMC_BASE)
/** Array initializer of EMC peripheral base addresses */
#define EMC_BASE_ADDRS                           { EMC_BASE }
/** Array initializer of EMC peripheral base pointers */
#define EMC_BASE_PTRS                            { EMC }

/* ENET - Peripheral instance base addresses */
/** Peripheral ENET base address */
#define ENET_BASE                                (0x40092000u)
/** Peripheral ENET base pointer */
#define ENET                                     ((ENET_Type *)ENET_BASE)
/** Array initializer of ENET peripheral base addresses */
#define ENET_BASE_ADDRS                          { ENET_BASE }
/** Array initializer of ENET peripheral base pointers */
#define ENET_BASE_PTRS                           { ENET }
/** Interrupt vectors for the ENET peripheral type */
#define ENET_IRQS                                { ETHERNET_IRQn }
#define ENET_PMT_IRQS                            { ETHERNET_PMT_IRQn }
#define ENET_MACLP_IRQS                          { ETHERNET_MACLP_IRQn }

/* FLEXCOMM - Peripheral instance base addresses */
/** Peripheral FLEXCOMM0 base address */
#define FLEXCOMM0_BASE                           (0x40086000u)
/** Peripheral FLEXCOMM0 base pointer */
#define FLEXCOMM0                                ((FLEXCOMM_Type *)FLEXCOMM0_BASE)
/** Peripheral FLEXCOMM1 base address */
#define FLEXCOMM1_BASE                           (0x40087000u)
/** Peripheral FLEXCOMM1 base pointer */
#define FLEXCOMM1                                ((FLEXCOMM_Type *)FLEXCOMM1_BASE)
/** Peripheral FLEXCOMM2 base address */
#define FLEXCOMM2_BASE                           (0x40088000u)
/** Peripheral FLEXCOMM2 base pointer */
#define FLEXCOMM2                                ((FLEXCOMM_Type *)FLEXCOMM2_BASE)
/** Peripheral FLEXCOMM3 base address */
#define FLEXCOMM3_BASE                           (0x40089000u)
/** Peripheral FLEXCOMM3 base pointer */
#define FLEXCOMM3                                ((FLEXCOMM_Type *)FLEXCOMM3_BASE)
/** Peripheral FLEXCOMM4 base address */
#define FLEXCOMM4_BASE                           (0x4008A000u)
/** Peripheral FLEXCOMM4 base pointer */
#define FLEXCOMM4                                ((FLEXCOMM_Type *)FLEXCOMM4_BASE)
/** Peripheral FLEXCOMM5 base address */
#define FLEXCOMM5_BASE                           (0x40096000u)
/** Peripheral FLEXCOMM5 base pointer */
#define FLEXCOMM5                                ((FLEXCOMM_Type *)FLEXCOMM5_BASE)
/** Peripheral FLEXCOMM6 base address */
#define FLEXCOMM6_BASE                           (0x40097000u)
/** Peripheral FLEXCOMM6 base pointer */
#define FLEXCOMM6                                ((FLEXCOMM_Type *)FLEXCOMM6_BASE)
/** Peripheral FLEXCOMM7 base address */
#define FLEXCOMM7_BASE                           (0x40098000u)
/** Peripheral FLEXCOMM7 base pointer */
#define FLEXCOMM7                                ((FLEXCOMM_Type *)FLEXCOMM7_BASE)
/** Peripheral FLEXCOMM8 base address */
#define FLEXCOMM8_BASE                           (0x40099000u)
/** Peripheral FLEXCOMM8 base pointer */
#define FLEXCOMM8                                ((FLEXCOMM_Type *)FLEXCOMM8_BASE)
/** Peripheral FLEXCOMM9 base address */
#define FLEXCOMM9_BASE                           (0x4009A000u)
/** Peripheral FLEXCOMM9 base pointer */
#define FLEXCOMM9                                ((FLEXCOMM_Type *)FLEXCOMM9_BASE)
/** Peripheral FLEXCOMM10 base address */
#define FLEXCOMM10_BASE                          (0x4009F000u)
/** Peripheral FLEXCOMM10 base pointer */
#define FLEXCOMM10                               ((FLEXCOMM_Type *)FLEXCOMM10_BASE)
/** Array initializer of FLEXCOMM peripheral base addresses */
#define FLEXCOMM_BASE_ADDRS                      { FLEXCOMM0_BASE, FLEXCOMM1_BASE, FLEXCOMM2_BASE, FLEXCOMM3_BASE, FLEXCOMM4_BASE, FLEXCOMM5_BASE, FLEXCOMM6_BASE, FLEXCOMM7_BASE, FLEXCOMM8_BASE, FLEXCOMM9_BASE, FLEXCOMM10_BASE }
/** Array initializer of FLEXCOMM peripheral base pointers */
#define FLEXCOMM_BASE_PTRS                       { FLEXCOMM0, FLEXCOMM1, FLEXCOMM2, FLEXCOMM3, FLEXCOMM4, FLEXCOMM5, FLEXCOMM6, FLEXCOMM7, FLEXCOMM8, FLEXCOMM9, FLEXCOMM10 }
/** Interrupt vectors for the FLEXCOMM peripheral type */
#define FLEXCOMM_IRQS                            { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, FLEXCOMM8_IRQn, FLEXCOMM9_IRQn, FLEXCOMM10_IRQn }

/* GINT - Peripheral instance base addresses */
/** Peripheral GINT0 base address */
#define GINT0_BASE                               (0x40002000u)
/** Peripheral GINT0 base pointer */
#define GINT0                                    ((GINT_Type *)GINT0_BASE)
/** Peripheral GINT1 base address */
#define GINT1_BASE                               (0x40003000u)
/** Peripheral GINT1 base pointer */
#define GINT1                                    ((GINT_Type *)GINT1_BASE)
/** Array initializer of GINT peripheral base addresses */
#define GINT_BASE_ADDRS                          { GINT0_BASE, GINT1_BASE }
/** Array initializer of GINT peripheral base pointers */
#define GINT_BASE_PTRS                           { GINT0, GINT1 }
/** Interrupt vectors for the GINT peripheral type */
#define GINT_IRQS                                { GINT0_IRQn, GINT1_IRQn }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO base address */
#define GPIO_BASE                                (0x4008C000u)
/** Peripheral GPIO base pointer */
#define GPIO                                     ((GPIO_Type *)GPIO_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIO_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIO }

/* I2C - Peripheral instance base addresses */
/** Peripheral I2C0 base address */
#define I2C0_BASE                                (0x40086000u)
/** Peripheral I2C0 base pointer */
#define I2C0                                     ((I2C_Type *)I2C0_BASE)
/** Peripheral I2C1 base address */
#define I2C1_BASE                                (0x40087000u)
/** Peripheral I2C1 base pointer */
#define I2C1                                     ((I2C_Type *)I2C1_BASE)
/** Peripheral I2C2 base address */
#define I2C2_BASE                                (0x40088000u)
/** Peripheral I2C2 base pointer */
#define I2C2                                     ((I2C_Type *)I2C2_BASE)
/** Peripheral I2C3 base address */
#define I2C3_BASE                                (0x40089000u)
/** Peripheral I2C3 base pointer */
#define I2C3                                     ((I2C_Type *)I2C3_BASE)
/** Peripheral I2C4 base address */
#define I2C4_BASE                                (0x4008A000u)
/** Peripheral I2C4 base pointer */
#define I2C4                                     ((I2C_Type *)I2C4_BASE)
/** Peripheral I2C5 base address */
#define I2C5_BASE                                (0x40096000u)
/** Peripheral I2C5 base pointer */
#define I2C5                                     ((I2C_Type *)I2C5_BASE)
/** Peripheral I2C6 base address */
#define I2C6_BASE                                (0x40097000u)
/** Peripheral I2C6 base pointer */
#define I2C6                                     ((I2C_Type *)I2C6_BASE)
/** Peripheral I2C7 base address */
#define I2C7_BASE                                (0x40098000u)
/** Peripheral I2C7 base pointer */
#define I2C7                                     ((I2C_Type *)I2C7_BASE)
/** Peripheral I2C8 base address */
#define I2C8_BASE                                (0x40099000u)
/** Peripheral I2C8 base pointer */
#define I2C8                                     ((I2C_Type *)I2C8_BASE)
/** Peripheral I2C9 base address */
#define I2C9_BASE                                (0x4009A000u)
/** Peripheral I2C9 base pointer */
#define I2C9                                     ((I2C_Type *)I2C9_BASE)
/** Array initializer of I2C peripheral base addresses */
#define I2C_BASE_ADDRS                           { I2C0_BASE, I2C1_BASE, I2C2_BASE, I2C3_BASE, I2C4_BASE, I2C5_BASE, I2C6_BASE, I2C7_BASE, I2C8_BASE, I2C9_BASE }
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { I2C0, I2C1, I2C2, I2C3, I2C4, I2C5, I2C6, I2C7, I2C8, I2C9 }
/** Interrupt vectors for the I2C peripheral type */
#define I2C_IRQS                                 { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, FLEXCOMM8_IRQn, FLEXCOMM9_IRQn }

/* I2S - Peripheral instance base addresses */
/** Peripheral I2S0 base address */
#define I2S0_BASE                                (0x40097000u)
/** Peripheral I2S0 base pointer */
#define I2S0                                     ((I2S_Type *)I2S0_BASE)
/** Peripheral I2S1 base address */
#define I2S1_BASE                                (0x40098000u)
/** Peripheral I2S1 base pointer */
#define I2S1                                     ((I2S_Type *)I2S1_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { I2S0_BASE, I2S1_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { I2S0, I2S1 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_IRQS                                 { FLEXCOMM6_IRQn, FLEXCOMM7_IRQn }

/* INPUTMUX - Peripheral instance base addresses */
/** Peripheral INPUTMUX base address */
#define INPUTMUX_BASE                            (0x40005000u)
/** Peripheral INPUTMUX base pointer */
#define INPUTMUX                                 ((INPUTMUX_Type *)INPUTMUX_BASE)
/** Array initializer of INPUTMUX peripheral base addresses */
#define INPUTMUX_BASE_ADDRS                      { INPUTMUX_BASE }
/** Array initializer of INPUTMUX peripheral base pointers */
#define INPUTMUX_BASE_PTRS                       { INPUTMUX }

/* IOCON - Peripheral instance base addresses */
/** Peripheral IOCON base address */
#define IOCON_BASE                               (0x40001000u)
/** Peripheral IOCON base pointer */
#define IOCON                                    ((IOCON_Type *)IOCON_BASE)
/** Array initializer of IOCON peripheral base addresses */
#define IOCON_BASE_ADDRS                         { IOCON_BASE }
/** Array initializer of IOCON peripheral base pointers */
#define IOCON_BASE_PTRS                          { IOCON }

/* MRT - Peripheral instance base addresses */
/** Peripheral MRT0 base address */
#define MRT0_BASE                                (0x4000D000u)
/** Peripheral MRT0 base pointer */
#define MRT0                                     ((MRT_Type *)MRT0_BASE)
/** Array initializer of MRT peripheral base addresses */
#define MRT_BASE_ADDRS                           { MRT0_BASE }
/** Array initializer of MRT peripheral base pointers */
#define MRT_BASE_PTRS                            { MRT0 }
/** Interrupt vectors for the MRT peripheral type */
#define MRT_IRQS                                 { MRT0_IRQn }

/* OTPC - Peripheral instance base addresses */
/** Peripheral OTPC base address */
#define OTPC_BASE                                (0x40015000u)
/** Peripheral OTPC base pointer */
#define OTPC                                     ((OTPC_Type *)OTPC_BASE)
/** Array initializer of OTPC peripheral base addresses */
#define OTPC_BASE_ADDRS                          { OTPC_BASE }
/** Array initializer of OTPC peripheral base pointers */
#define OTPC_BASE_PTRS                           { OTPC }

/* PINT - Peripheral instance base addresses */
/** Peripheral PINT base address */
#define PINT_BASE                                (0x40004000u)
/** Peripheral PINT base pointer */
#define PINT                                     ((PINT_Type *)PINT_BASE)
/** Array initializer of PINT peripheral base addresses */
#define PINT_BASE_ADDRS                          { PINT_BASE }
/** Array initializer of PINT peripheral base pointers */
#define PINT_BASE_PTRS                           { PINT }
/** Interrupt vectors for the PINT peripheral type */
#define PINT_IRQS                                { PIN_INT0_IRQn, PIN_INT1_IRQn, PIN_INT2_IRQn, PIN_INT3_IRQn, PIN_INT4_IRQn, PIN_INT5_IRQn, PIN_INT6_IRQn, PIN_INT7_IRQn }

/* PUF - Peripheral instance base addresses */
/** Peripheral PUF base address */
#define PUF_BASE                                 (0x4003B000u)
/** Peripheral PUF base pointer */
#define PUF                                      ((PUF_Type *)PUF_BASE)
/** Array initializer of PUF peripheral base addresses */
#define PUF_BASE_ADDRS                           { PUF_BASE }
/** Array initializer of PUF peripheral base pointers */
#define PUF_BASE_PTRS                            { PUF }
/** Interrupt vectors for the PUF peripheral type */
#define PUF_IRQS                                 { PUF_IRQn }

/* RIT - Peripheral instance base addresses */
/** Peripheral RIT base address */
#define RIT_BASE                                 (0x4002D000u)
/** Peripheral RIT base pointer */
#define RIT                                      ((RIT_Type *)RIT_BASE)
/** Array initializer of RIT peripheral base addresses */
#define RIT_BASE_ADDRS                           { RIT_BASE }
/** Array initializer of RIT peripheral base pointers */
#define RIT_BASE_PTRS                            { RIT }
/** Interrupt vectors for the RIT peripheral type */
#define RIT_IRQS                                 { RIT_IRQn }

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x4002C000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }

/* SCT - Peripheral instance base addresses */
/** Peripheral SCT0 base address */
#define SCT0_BASE                                (0x40085000u)
/** Peripheral SCT0 base pointer */
#define SCT0                                     ((SCT_Type *)SCT0_BASE)
/** Array initializer of SCT peripheral base addresses */
#define SCT_BASE_ADDRS                           { SCT0_BASE }
/** Array initializer of SCT peripheral base pointers */
#define SCT_BASE_PTRS                            { SCT0 }
/** Interrupt vectors for the SCT peripheral type */
#define SCT_IRQS                                 { SCT0_IRQn }

/* SDIF - Peripheral instance base addresses */
/** Peripheral SDIF base address */
#define SDIF_BASE                                (0x4009B000u)
/** Peripheral SDIF base pointer */
#define SDIF                                     ((SDIF_Type *)SDIF_BASE)
/** Array initializer of SDIF peripheral base addresses */
#define SDIF_BASE_ADDRS                          { SDIF_BASE }
/** Array initializer of SDIF peripheral base pointers */
#define SDIF_BASE_PTRS                           { SDIF }
/** Interrupt vectors for the SDIF peripheral type */
#define SDIF_IRQS                                { SDIO_IRQn }

/* SHA - Peripheral instance base addresses */
/** Peripheral SHA0 base address */
#define SHA0_BASE                                (0x400A4000u)
/** Peripheral SHA0 base pointer */
#define SHA0                                     ((SHA_Type *)SHA0_BASE)
/** Array initializer of SHA peripheral base addresses */
#define SHA_BASE_ADDRS                           { SHA0_BASE }
/** Array initializer of SHA peripheral base pointers */
#define SHA_BASE_PTRS                            { SHA0 }

/* SMARTCARD - Peripheral instance base addresses */
/** Peripheral SMARTCARD0 base address */
#define SMARTCARD0_BASE                          (0x40036000u)
/** Peripheral SMARTCARD0 base pointer */
#define SMARTCARD0                               ((SMARTCARD_Type *)SMARTCARD0_BASE)
/** Peripheral SMARTCARD1 base address */
#define SMARTCARD1_BASE                          (0x40037000u)
/** Peripheral SMARTCARD1 base pointer */
#define SMARTCARD1                               ((SMARTCARD_Type *)SMARTCARD1_BASE)
/** Array initializer of SMARTCARD peripheral base addresses */
#define SMARTCARD_BASE_ADDRS                     { SMARTCARD0_BASE, SMARTCARD1_BASE }
/** Array initializer of SMARTCARD peripheral base pointers */
#define SMARTCARD_BASE_PTRS                      { SMARTCARD0, SMARTCARD1 }
/** Interrupt vectors for the SMARTCARD peripheral type */
#define SMARTCARD_IRQS                           { SMARTCARD0_IRQn, SMARTCARD1_IRQn }

/* SPI - Peripheral instance base addresses */
/** Peripheral SPI0 base address */
#define SPI0_BASE                                (0x40086000u)
/** Peripheral SPI0 base pointer */
#define SPI0                                     ((SPI_Type *)SPI0_BASE)
/** Peripheral SPI1 base address */
#define SPI1_BASE                                (0x40087000u)
/** Peripheral SPI1 base pointer */
#define SPI1                                     ((SPI_Type *)SPI1_BASE)
/** Peripheral SPI2 base address */
#define SPI2_BASE                                (0x40088000u)
/** Peripheral SPI2 base pointer */
#define SPI2                                     ((SPI_Type *)SPI2_BASE)
/** Peripheral SPI3 base address */
#define SPI3_BASE                                (0x40089000u)
/** Peripheral SPI3 base pointer */
#define SPI3                                     ((SPI_Type *)SPI3_BASE)
/** Peripheral SPI4 base address */
#define SPI4_BASE                                (0x4008A000u)
/** Peripheral SPI4 base pointer */
#define SPI4                                     ((SPI_Type *)SPI4_BASE)
/** Peripheral SPI5 base address */
#define SPI5_BASE                                (0x40096000u)
/** Peripheral SPI5 base pointer */
#define SPI5                                     ((SPI_Type *)SPI5_BASE)
/** Peripheral SPI6 base address */
#define SPI6_BASE                                (0x40097000u)
/** Peripheral SPI6 base pointer */
#define SPI6                                     ((SPI_Type *)SPI6_BASE)
/** Peripheral SPI7 base address */
#define SPI7_BASE                                (0x40098000u)
/** Peripheral SPI7 base pointer */
#define SPI7                                     ((SPI_Type *)SPI7_BASE)
/** Peripheral SPI8 base address */
#define SPI8_BASE                                (0x40099000u)
/** Peripheral SPI8 base pointer */
#define SPI8                                     ((SPI_Type *)SPI8_BASE)
/** Peripheral SPI9 base address */
#define SPI9_BASE                                (0x4009A000u)
/** Peripheral SPI9 base pointer */
#define SPI9                                     ((SPI_Type *)SPI9_BASE)
/** Peripheral SPI10 base address */
#define SPI10_BASE                               (0x4009F000u)
/** Peripheral SPI10 base pointer */
#define SPI10                                    ((SPI_Type *)SPI10_BASE)
/** Array initializer of SPI peripheral base addresses */
#define SPI_BASE_ADDRS                           { SPI0_BASE, SPI1_BASE, SPI2_BASE, SPI3_BASE, SPI4_BASE, SPI5_BASE, SPI6_BASE, SPI7_BASE, SPI8_BASE, SPI9_BASE, SPI10_BASE }
/** Array initializer of SPI peripheral base pointers */
#define SPI_BASE_PTRS                            { SPI0, SPI1, SPI2, SPI3, SPI4, SPI5, SPI6, SPI7, SPI8, SPI9, SPI10 }
/** Interrupt vectors for the SPI peripheral type */
#define SPI_IRQS                                 { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, FLEXCOMM8_IRQn, FLEXCOMM9_IRQn, FLEXCOMM10_IRQn }

/* SPIFI - Peripheral instance base addresses */
/** Peripheral SPIFI0 base address */
#define SPIFI0_BASE                              (0x40080000u)
/** Peripheral SPIFI0 base pointer */
#define SPIFI0                                   ((SPIFI_Type *)SPIFI0_BASE)
/** Array initializer of SPIFI peripheral base addresses */
#define SPIFI_BASE_ADDRS                         { SPIFI0_BASE }
/** Array initializer of SPIFI peripheral base pointers */
#define SPIFI_BASE_PTRS                          { SPIFI0 }
/** Interrupt vectors for the SPIFI peripheral type */
#define SPIFI_IRQS                               { SPIFI0_IRQn }

/* SYSCON - Peripheral instance base addresses */
/** Peripheral SYSCON base address */
#define SYSCON_BASE                              (0x40000000u)
/** Peripheral SYSCON base pointer */
#define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
/** Array initializer of SYSCON peripheral base addresses */
#define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
/** Array initializer of SYSCON peripheral base pointers */
#define SYSCON_BASE_PTRS                         { SYSCON }

/* USART - Peripheral instance base addresses */
/** Peripheral USART0 base address */
#define USART0_BASE                              (0x40086000u)
/** Peripheral USART0 base pointer */
#define USART0                                   ((USART_Type *)USART0_BASE)
/** Peripheral USART1 base address */
#define USART1_BASE                              (0x40087000u)
/** Peripheral USART1 base pointer */
#define USART1                                   ((USART_Type *)USART1_BASE)
/** Peripheral USART2 base address */
#define USART2_BASE                              (0x40088000u)
/** Peripheral USART2 base pointer */
#define USART2                                   ((USART_Type *)USART2_BASE)
/** Peripheral USART3 base address */
#define USART3_BASE                              (0x40089000u)
/** Peripheral USART3 base pointer */
#define USART3                                   ((USART_Type *)USART3_BASE)
/** Peripheral USART4 base address */
#define USART4_BASE                              (0x4008A000u)
/** Peripheral USART4 base pointer */
#define USART4                                   ((USART_Type *)USART4_BASE)
/** Peripheral USART5 base address */
#define USART5_BASE                              (0x40096000u)
/** Peripheral USART5 base pointer */
#define USART5                                   ((USART_Type *)USART5_BASE)
/** Peripheral USART6 base address */
#define USART6_BASE                              (0x40097000u)
/** Peripheral USART6 base pointer */
#define USART6                                   ((USART_Type *)USART6_BASE)
/** Peripheral USART7 base address */
#define USART7_BASE                              (0x40098000u)
/** Peripheral USART7 base pointer */
#define USART7                                   ((USART_Type *)USART7_BASE)
/** Peripheral USART8 base address */
#define USART8_BASE                              (0x40099000u)
/** Peripheral USART8 base pointer */
#define USART8                                   ((USART_Type *)USART8_BASE)
/** Peripheral USART9 base address */
#define USART9_BASE                              (0x4009A000u)
/** Peripheral USART9 base pointer */
#define USART9                                   ((USART_Type *)USART9_BASE)
/** Array initializer of USART peripheral base addresses */
#define USART_BASE_ADDRS                         { USART0_BASE, USART1_BASE, USART2_BASE, USART3_BASE, USART4_BASE, USART5_BASE, USART6_BASE, USART7_BASE, USART8_BASE, USART9_BASE }
/** Array initializer of USART peripheral base pointers */
#define USART_BASE_PTRS                          { USART0, USART1, USART2, USART3, USART4, USART5, USART6, USART7, USART8, USART9 }
/** Interrupt vectors for the USART peripheral type */
#define USART_IRQS                               { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, FLEXCOMM8_IRQn, FLEXCOMM9_IRQn }

/* USB - Peripheral instance base addresses */
/** Peripheral USB0 base address */
#define USB0_BASE                                (0x40084000u)
/** Peripheral USB0 base pointer */
#define USB0                                     ((USB_Type *)USB0_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB0_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB0 }
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { USB0_IRQn }
#define USB_NEEDCLK_IRQS                         { USB0_NEEDCLK_IRQn }

/* USBFSH - Peripheral instance base addresses */
/** Peripheral USBFSH base address */
#define USBFSH_BASE                              (0x400A2000u)
/** Peripheral USBFSH base pointer */
#define USBFSH                                   ((USBFSH_Type *)USBFSH_BASE)
/** Array initializer of USBFSH peripheral base addresses */
#define USBFSH_BASE_ADDRS                        { USBFSH_BASE }
/** Array initializer of USBFSH peripheral base pointers */
#define USBFSH_BASE_PTRS                         { USBFSH }
/** Interrupt vectors for the USBFSH peripheral type */
#define USBFSH_IRQS                              { USB0_IRQn }
#define USBFSH_NEEDCLK_IRQS                      { USB0_NEEDCLK_IRQn }

/* USBHSD - Peripheral instance base addresses */
/** Peripheral USBHSD base address */
#define USBHSD_BASE                              (0x40094000u)
/** Peripheral USBHSD base pointer */
#define USBHSD                                   ((USBHSD_Type *)USBHSD_BASE)
/** Array initializer of USBHSD peripheral base addresses */
#define USBHSD_BASE_ADDRS                        { USBHSD_BASE }
/** Array initializer of USBHSD peripheral base pointers */
#define USBHSD_BASE_PTRS                         { USBHSD }
/** Interrupt vectors for the USBHSD peripheral type */
#define USBHSD_IRQS                              { USB1_IRQn }
#define USBHSD_NEEDCLK_IRQS                      { USB1_NEEDCLK_IRQn }

/* USBHSH - Peripheral instance base addresses */
/** Peripheral USBHSH base address */
#define USBHSH_BASE                              (0x400A3000u)
/** Peripheral USBHSH base pointer */
#define USBHSH                                   ((USBHSH_Type *)USBHSH_BASE)
/** Array initializer of USBHSH peripheral base addresses */
#define USBHSH_BASE_ADDRS                        { USBHSH_BASE }
/** Array initializer of USBHSH peripheral base pointers */
#define USBHSH_BASE_PTRS                         { USBHSH }
/** Interrupt vectors for the USBHSH peripheral type */
#define USBHSH_IRQS                              { USB1_IRQn }
#define USBHSH_NEEDCLK_IRQS                      { USB1_NEEDCLK_IRQn }

/* UTICK - Peripheral instance base addresses */
/** Peripheral UTICK0 base address */
#define UTICK0_BASE                              (0x4000E000u)
/** Peripheral UTICK0 base pointer */
#define UTICK0                                   ((UTICK_Type *)UTICK0_BASE)
/** Array initializer of UTICK peripheral base addresses */
#define UTICK_BASE_ADDRS                         { UTICK0_BASE }
/** Array initializer of UTICK peripheral base pointers */
#define UTICK_BASE_PTRS                          { UTICK0 }
/** Interrupt vectors for the UTICK peripheral type */
#define UTICK_IRQS                               { UTICK0_IRQn }

/* WWDT - Peripheral instance base addresses */
/** Peripheral WWDT base address */
#define WWDT_BASE                                (0x4000C000u)
/** Peripheral WWDT base pointer */
#define WWDT                                     ((WWDT_Type *)WWDT_BASE)
/** Array initializer of WWDT peripheral base addresses */
#define WWDT_BASE_ADDRS                          { WWDT_BASE }
/** Array initializer of WWDT peripheral base pointers */
#define WWDT_BASE_PTRS                           { WWDT }
/** Interrupt vectors for the WWDT peripheral type */
#define WWDT_IRQS                                { WDT_BOD_IRQn }

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

/** EMC CS base address */
#define EMC_CS0_BASE                                (0x80000000u)
#define EMC_CS1_BASE                                (0x88000000u)
#define EMC_CS2_BASE                                (0x90000000u)
#define EMC_CS3_BASE                                (0x98000000u)
#define EMC_DYCS0_BASE                              (0xA0000000u)
#define EMC_DYCS1_BASE                              (0xA8000000u)
#define EMC_DYCS2_BASE                              (0xB0000000u)
#define EMC_DYCS3_BASE                              (0xB8000000u)
#define EMC_CS_ADDRESS                              {EMC_CS0_BASE, EMC_CS1_BASE, EMC_CS2_BASE, EMC_CS3_BASE}
#define EMC_DYCS_ADDRESS                            {EMC_DYCS0_BASE, EMC_DYCS1_BASE, EMC_DYCS2_BASE, EMC_DYCS3_BASE}

/** OTP API */
typedef struct {
  uint32_t (*otpInit)(void);                                    /** Initializes OTP controller */
  uint32_t (*otpEnableBankWriteMask)(uint32_t bankMask);        /** Unlock one or more OTP banks for write access */
  uint32_t (*otpDisableBankWriteMask)(uint32_t bankMask);       /** Lock one or more OTP banks for write access */
  uint32_t (*otpEnableBankWriteLock)(uint32_t bankIndex, uint32_t regEnableMask, uint32_t regDisableMask,
                                          uint32_t lockWrite);  /** Locks or unlocks write access to a register of an OTP bank and the write lock */
  uint32_t (*otpEnableBankReadLock)(uint32_t bankIndex, uint32_t regEnableMask, uint32_t regDisableMask,
                                         uint32_t lockWrite);   /** Locks or unlocks read access to a register of an OTP bank and the write lock */
  uint32_t (*otpProgramReg)(uint32_t bankIndex, uint32_t regIndex, uint32_t value);  /** Program a single register in an OTP bank */
  uint32_t RESERVED_0[5];
  uint32_t (*rngRead)(void);                                    /** Returns 32-bit number from hardware random number generator */
  uint32_t (*otpGetDriverVersion)(void);                        /** Returns the version of the OTP driver in ROM */
} OTP_API_Type;

#if defined(LPC54S005_H_) || defined(LPC54S016_H_) || defined(LPC54S018_H_)
/** AES API */
typedef struct {
      uint32_t (*aesInit)(void);
      uint32_t  RESERVED_0[3];
      uint32_t (*aesLoadKeyFromSW)(uint32_t keySize, uint32_t *key);
      uint32_t (*aesLoadKeyFromOTP)(uint32_t keysize);    /** Loads a key into the AES block from the OTP block. */
      uint32_t (*aesProgramKeyToOTP)(void);               /** Programs the current key in the AES block to the OTP block (i.e. the key will be stored in OTP).*/
      uint32_t  RESERVED_1[5];
      uint32_t (*aesLoadKeyFromPUF)(uint32_t keysize);    /** Loads the key from the PUF block to the AES block */
      uint32_t  RESERVED_2[2];
} AES_API_Type;
#endif

/** SRAMX and SRAM0 base address */
#define SRAMX_BASE                                (0x00000000u)
#define SRAMX_SIZE                                (0x00030000u)
#define SRAM0_BASE                                (0x20000000u)
#define SRAM0_SIZE                                (0x00010000u)

/** ROM API */
typedef struct {
  __I uint32_t usbdApiBase;                      /** USB API Base */
      uint32_t RESERVED_0[13];
  __I OTP_API_Type *otpApiBase;                  /** OTP API Base */
#if defined(LPC54S005_H_) || defined(LPC54S016_H_) || defined(LPC54S018_H_)
  __I AES_API_Type *aesApiBase;                  /** AES API Base */
#else
  __I uint32_t aesApiBase;                       /** AES API Base */
#endif
  __I uint32_t secureApiBase;                    /** Secure API Base */
} ROM_API_Type;

/** ROM API base address */
#define ROM_API_BASE                             (0x03000200u)
/** ROM API base pointer */
#define ROM_API                                  (*(ROM_API_Type**) ROM_API_BASE)
/** OTP API base pointer */
#define OTP_API                                  (ROM_API->otpApiBase)
#if defined(LPC54S005_H_) || defined(LPC54S016_H_) || defined(LPC54S018_H_)
/** AES API base pointer */
#define AES_API                                  (ROM_API->aesApiBase)
#endif

/** Used for selecting the address of FROHF setting API in ROM */
#define FSL_FROHF_SETTING_API_ADDRESS_DETERMINE_BY_ROM_VERSION 1U
#define FSL_ROM_VERSION_0A 0U
#define FSL_ROM_VERSION_1B 1U
#define FSL_ROM_VERSION_0A_FRO_SETTING_ADDR 0x03007933U
#define FSL_ROM_VERSION_1B_FRO_SETTING_ADDR 0x03008D9BU

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* LPC54S016_COMMON_H_ */

