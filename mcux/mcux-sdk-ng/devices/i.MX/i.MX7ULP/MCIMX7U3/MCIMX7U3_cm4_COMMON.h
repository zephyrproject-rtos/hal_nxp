/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX7ULPRM, Rev. 0, Nov. 2018
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCIMX7U3_cm4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MCIMX7U3_cm4_COMMON.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCIMX7U3_cm4
 *
 * CMSIS Peripheral Access Layer for MCIMX7U3_cm4
 */

#if !defined(MCIMX7U3_CM4_COMMON_H_)
#define MCIMX7U3_CM4_COMMON_H_                   /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0800U
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
#define NUMBER_OF_INT_VECTORS 144                /**< Number of interrupts in the Vector table */

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
  CTI0_IRQn                    = 0,                /**< Cross Trigger Interface for CM4 */
  DMA0_0_4_IRQn                = 1,                /**< DMA Channel 0, 4 Transfer Complete */
  DMA0_1_5_IRQn                = 2,                /**< DMA Channel 1, 5 Transfer Complete */
  DMA0_2_6_IRQn                = 3,                /**< DMA Channel 2, 6 Transfer Complete */
  DMA0_3_7_IRQn                = 4,                /**< DMA Channel 3, 7 Transfer Complete */
  DMA0_8_12_IRQn               = 5,                /**< DMA Channel 8, 12 Transfer Complete */
  DMA0_9_13_IRQn               = 6,                /**< DMA Channel 9, 13 Transfer Complete */
  DMA0_10_14_IRQn              = 7,                /**< DMA Channel 10, 14 Transfer Complete */
  DMA0_11_15_IRQn              = 8,                /**< DMA Channel 11, 15 Transfer Complete */
  DMA0_16_20_IRQn              = 9,                /**< DMA Channel 16, 20 Transfer Complete */
  DMA0_17_21_IRQn              = 10,               /**< DMA Channel 17, 21 Transfer Complete */
  DMA0_18_22_IRQn              = 11,               /**< DMA Channel 18, 22 Transfer Complete */
  DMA0_19_23_IRQn              = 12,               /**< DMA Channel 19, 23 Transfer Complete */
  DMA0_24_28_IRQn              = 13,               /**< DMA Channel 24, 28 Transfer Complete */
  DMA0_25_29_IRQn              = 14,               /**< DMA Channel 25, 29 Transfer Complete */
  DMA0_26_30_IRQn              = 15,               /**< DMA Channel 26, 30 Transfer Complete */
  DMA0_27_31_IRQn              = 16,               /**< DMA Channel 27, 31 Transfer Complete */
  DMA0_Error_IRQn              = 17,               /**< DMA Error Interrupt - All Channels */
  MCM0_IRQn                    = 18,               /**< MCM Interrupt */
  EWM_IRQn                     = 19,               /**< External Watchdog Monitor Interrupt */
  LLWU0_IRQn                   = 20,               /**< Low Leakage Wake Up */
  SIM_IRQn                     = 21,               /**< System Integation Module */
  MU_A_IRQn                    = 22,               /**< Messaging Unit - Side A */
  Reserved39_IRQn              = 23,               /**< Secured JTAG Controller */
  Software1_IRQn               = 24,               /**< Software Interrupt */
  Software2_IRQn               = 25,               /**< Software Interrupt */
  WDOG0_IRQn                   = 26,               /**< Watchdog Interrupt */
  SCG0_IRQn                    = 27,               /**< System Clock Generator for M4 domain */
  QSPI_IRQn                    = 28,               /**< Quad Serial Peripheral Interface */
  LTC_IRQn                     = 29,               /**< Low Power Trusted Cryptography */
  XRDC_IRQn                    = 30,               /**< Extended Domain Resource Controller */
  SNVS_IRQn                    = 31,               /**< Secure Non-Volatile Storage Consolidated Interrupt */
  TRNG0_IRQn                   = 32,               /**< Random Number Generator */
  LPIT0_IRQn                   = 33,               /**< Low Power Periodic Interrupt Timer */
  PMC0_IRQn                    = 34,               /**< Power Management  Control interrupts for M4 domain */
  CMC0_IRQn                    = 35,               /**< Core Mode Controller interrupts for M4 domain */
  LPTMR0_IRQn                  = 36,               /**< Low Power Timer */
  LPTMR1_IRQn                  = 37,               /**< Low Power Timer */
  TPM0_IRQn                    = 38,               /**< Timer PWM module */
  TPM1_IRQn                    = 39,               /**< Timer PWM module */
  TPM2_IRQn                    = 40,               /**< Timer PWM module */
  TPM3_IRQn                    = 41,               /**< Timer PWM module */
  FLEXIO0_IRQn                 = 42,               /**< Flexible IO */
  LPI2C0_IRQn                  = 43,               /**< Inter-integrated circuit 0 */
  LPI2C1_IRQn                  = 44,               /**< Inter-integrated circuit 1 */
  LPI2C2_IRQn                  = 45,               /**< Inter-integrated circuit 2 */
  LPI2C3_IRQn                  = 46,               /**< Inter-integrated circuit 3 */
  I2S0_IRQn                    = 47,               /**< Serial Audio Interface 0 */
  I2S1_IRQn                    = 48,               /**< Serial Audio Interface 1 */
  LPSPI0_IRQn                  = 49,               /**< Low Power Serial Peripheral Interface */
  LPSPI1_IRQn                  = 50,               /**< Low Power Serial Peripheral Interface */
  LPUART0_IRQn                 = 51,               /**< Low Power UART */
  LPUART1_IRQn                 = 52,               /**< Low Power UART */
  LPUART2_IRQn                 = 53,               /**< Low Power UART */
  LPUART3_IRQn                 = 54,               /**< Low Power UART */
  DPM_IRQn                     = 55,               /**< Dynamic Process Monitor */
  PCTLA_IRQn                   = 56,               /**< Port A pin interrupt */
  PCTLB_IRQn                   = 57,               /**< Port B pin interrupt */
  ADC0_IRQn                    = 58,               /**< Analog to Digital Convertor */
  ADC1_IRQn                    = 59,               /**< Analog to Digital Convertor */
  CMP0_IRQn                    = 60,               /**< Comparator */
  CMP1_IRQn                    = 61,               /**< Comparator */
  DAC0_IRQn                    = 62,               /**< Digital to Analog Convertor */
  DAC1_IRQn                    = 63,               /**< Digital to Analog Convertor */
  WDOG1_IRQn                   = 64,               /**< Watchdog Interrupt from A7 subsystem */
  USB0_IRQn                    = 65,               /**< USB 0 Interrupt from A7 subsystem */
  USB1_IRQn                    = 66,               /**< USB 1 Interrupt from A7 subsystem */
  Reserved83_IRQn              = 67,
  WDOG2_IRQn                   = 68,               /**< Watchdog Interrupt from A7 subsystem */
  USBPHY_IRQn                  = 69,               /**< USB PHY (used in conjunction with USBOTG1) */
  CMC1_IRQn                    = 70,               /**< A7 resets */
  Reserved87_IRQn              = 71,               /**< Reserved interrupt */
  Reserved88_IRQn              = 72,               /**< Reserved interrupt */
  Reserved89_IRQn              = 73,               /**< Reserved interrupt */
  Reserved90_IRQn              = 74,               /**< Reserved interrupt */
  Reserved91_IRQn              = 75,               /**< Reserved interrupt */
  Reserved92_IRQn              = 76,               /**< Reserved interrupt */
  Reserved93_IRQn              = 77,               /**< Reserved interrupt */
  Reserved94_IRQn              = 78,               /**< Reserved interrupt */
  Reserved95_IRQn              = 79,               /**< Reserved interrupt */
  Reserved96_IRQn              = 80,               /**< Reserved interrupt */
  Reserved97_IRQn              = 81,               /**< Reserved interrupt */
  Reserved98_IRQn              = 82,               /**< Reserved interrupt */
  Reserved99_IRQn              = 83,               /**< Reserved interrupt */
  Reserved100_IRQn             = 84,               /**< Reserved interrupt */
  Reserved101_IRQn             = 85,               /**< Reserved interrupt */
  Reserved102_IRQn             = 86,               /**< Reserved interrupt */
  Reserved103_IRQn             = 87,               /**< Reserved interrupt */
  Reserved104_IRQn             = 88,               /**< Reserved interrupt */
  Reserved105_IRQn             = 89,               /**< Reserved interrupt */
  Reserved106_IRQn             = 90,               /**< Reserved interrupt */
  Reserved107_IRQn             = 91,               /**< Reserved interrupt */
  Reserved108_IRQn             = 92,               /**< Reserved interrupt */
  Reserved109_IRQn             = 93,               /**< Reserved interrupt */
  Reserved110_IRQn             = 94,               /**< Reserved interrupt */
  Reserved111_IRQn             = 95,               /**< Reserved interrupt */
  Reserved112_IRQn             = 96,               /**< Reserved interrupt */
  Reserved113_IRQn             = 97,               /**< Reserved interrupt */
  Reserved114_IRQn             = 98,               /**< Reserved interrupt */
  Reserved115_IRQn             = 99,               /**< Reserved interrupt */
  Reserved116_IRQn             = 100,              /**< Reserved interrupt */
  Reserved117_IRQn             = 101,              /**< Reserved interrupt */
  Reserved118_IRQn             = 102,              /**< Reserved interrupt */
  Reserved119_IRQn             = 103,              /**< Reserved interrupt */
  Reserved120_IRQn             = 104,              /**< Reserved interrupt */
  Reserved121_IRQn             = 105,              /**< Reserved interrupt */
  Reserved122_IRQn             = 106,              /**< Reserved interrupt */
  Reserved123_IRQn             = 107,              /**< Reserved interrupt */
  Reserved124_IRQn             = 108,              /**< Reserved interrupt */
  Reserved125_IRQn             = 109,              /**< Reserved interrupt */
  Reserved126_IRQn             = 110,              /**< Reserved interrupt */
  Reserved127_IRQn             = 111,              /**< Reserved interrupt */
  Reserved128_IRQn             = 112,              /**< Reserved interrupt */
  Reserved129_IRQn             = 113,              /**< Reserved interrupt */
  Reserved130_IRQn             = 114,              /**< Reserved interrupt */
  Reserved131_IRQn             = 115,              /**< Reserved interrupt */
  Reserved132_IRQn             = 116,              /**< Reserved interrupt */
  Reserved133_IRQn             = 117,              /**< Reserved interrupt */
  Reserved134_IRQn             = 118,              /**< Reserved interrupt */
  Reserved135_IRQn             = 119,              /**< Reserved interrupt */
  Reserved136_IRQn             = 120,              /**< Reserved interrupt */
  Reserved137_IRQn             = 121,              /**< Reserved interrupt */
  Reserved138_IRQn             = 122,              /**< Reserved interrupt */
  Reserved139_IRQn             = 123,              /**< Reserved interrupt */
  Reserved140_IRQn             = 124,              /**< Reserved interrupt */
  Reserved141_IRQn             = 125,              /**< Reserved interrupt */
  Reserved142_IRQn             = 126,              /**< Reserved interrupt */
  Reserved143_IRQn             = 127               /**< Reserved interrupt */
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

#define __CM4_REV                      0x0001    /**< Core revision r0p1 */
#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */

#include "core_cm4.h"                  /* Core Peripheral Access Layer */
#include "system_MCIMX7U3_cm4.h"       /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MCIMX7U3_cm4_SERIES
#define MCIMX7U3_cm4_SERIES
#endif
/* CPU specific feature definitions */
#include "MCIMX7U3_cm4_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x41041000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Peripheral ADC1 base address */
#define ADC1_BASE                                (0x410AD000u)
/** Peripheral ADC1 base pointer */
#define ADC1                                     ((ADC_Type *)ADC1_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE, ADC1_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0, ADC1 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn, ADC1_IRQn }

/* CMP - Peripheral instance base addresses */
/** Peripheral CMP0 base address */
#define CMP0_BASE                                (0x41042000u)
/** Peripheral CMP0 base pointer */
#define CMP0                                     ((CMP_Type *)CMP0_BASE)
/** Peripheral CMP1 base address */
#define CMP1_BASE                                (0x41043000u)
/** Peripheral CMP1 base pointer */
#define CMP1                                     ((CMP_Type *)CMP1_BASE)
/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           { CMP0_BASE, CMP1_BASE }
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { CMP0, CMP1 }
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { CMP0_IRQn, CMP1_IRQn }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC0 base address */
#define CRC0_BASE                                (0x41029000u)
/** Peripheral CRC0 base pointer */
#define CRC0                                     ((CRC_Type *)CRC0_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC0_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC0 }

/* DAC - Peripheral instance base addresses */
/** Peripheral DAC0 base address */
#define DAC0_BASE                                (0x41044000u)
/** Peripheral DAC0 base pointer */
#define DAC0                                     ((DAC_Type *)DAC0_BASE)
/** Peripheral DAC1 base address */
#define DAC1_BASE                                (0x41045000u)
/** Peripheral DAC1 base pointer */
#define DAC1                                     ((DAC_Type *)DAC1_BASE)
/** Array initializer of DAC peripheral base addresses */
#define DAC_BASE_ADDRS                           { DAC0_BASE, DAC1_BASE }
/** Array initializer of DAC peripheral base pointers */
#define DAC_BASE_PTRS                            { DAC0, DAC1 }
/** Interrupt vectors for the DAC peripheral type */
#define DAC_IRQS                                 { DAC0_IRQn, DAC1_IRQn }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x41008000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Peripheral DMA1 base address */
#define DMA1_BASE                                (0x40080000u)
/** Peripheral DMA1 base pointer */
#define DMA1                                     ((DMA_Type *)DMA1_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE, DMA1_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0, DMA1 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_CHN_IRQS                             { { DMA0_0_4_IRQn, DMA0_1_5_IRQn, DMA0_2_6_IRQn, DMA0_3_7_IRQn, DMA0_0_4_IRQn, DMA0_1_5_IRQn, DMA0_2_6_IRQn, DMA0_3_7_IRQn, DMA0_8_12_IRQn, DMA0_9_13_IRQn, DMA0_10_14_IRQn, DMA0_11_15_IRQn, DMA0_8_12_IRQn, DMA0_9_13_IRQn, DMA0_10_14_IRQn, DMA0_11_15_IRQn, DMA0_16_20_IRQn, DMA0_17_21_IRQn, DMA0_18_22_IRQn, DMA0_19_23_IRQn, DMA0_16_20_IRQn, DMA0_17_21_IRQn, DMA0_18_22_IRQn, DMA0_19_23_IRQn, DMA0_24_28_IRQn, DMA0_25_29_IRQn, DMA0_26_30_IRQn, DMA0_27_31_IRQn, DMA0_24_28_IRQn, DMA0_25_29_IRQn, DMA0_26_30_IRQn, DMA0_27_31_IRQn }, \
                                                   { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn } }
#define DMA_ERROR_IRQS                           { DMA0_Error_IRQn, NotAvail_IRQn }

/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMA_CH_MUX0 base address */
#define DMA_CH_MUX0_BASE                         (0x41020000u)
/** Peripheral DMA_CH_MUX0 base pointer */
#define DMA_CH_MUX0                              ((DMAMUX_Type *)DMA_CH_MUX0_BASE)
/** Peripheral DMA_CH_MUX1 base address */
#define DMA_CH_MUX1_BASE                         (0x40210000u)
/** Peripheral DMA_CH_MUX1 base pointer */
#define DMA_CH_MUX1                              ((DMAMUX_Type *)DMA_CH_MUX1_BASE)
/** Array initializer of DMAMUX peripheral base addresses */
#define DMAMUX_BASE_ADDRS                        { DMA_CH_MUX0_BASE, DMA_CH_MUX1_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { DMA_CH_MUX0, DMA_CH_MUX1 }

/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base address */
#define EWM_BASE                                 (0x410A0000u)
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
#define FB_BASE                                  (0x40100000u)
/** Peripheral FB base pointer */
#define FB                                       ((FB_Type *)FB_BASE)
/** Array initializer of FB peripheral base addresses */
#define FB_BASE_ADDRS                            { FB_BASE }
/** Array initializer of FB peripheral base pointers */
#define FB_BASE_PTRS                             { FB }

/* FGPIO - Peripheral instance base addresses */
/** Peripheral FGPIOA base address */
#define FGPIOA_BASE                              (0xF9000000u)
/** Peripheral FGPIOA base pointer */
#define FGPIOA                                   ((FGPIO_Type *)FGPIOA_BASE)
/** Peripheral FGPIOB base address */
#define FGPIOB_BASE                              (0xF9000040u)
/** Peripheral FGPIOB base pointer */
#define FGPIOB                                   ((FGPIO_Type *)FGPIOB_BASE)
/** Array initializer of FGPIO peripheral base addresses */
#define FGPIO_BASE_ADDRS                         { FGPIOA_BASE, FGPIOB_BASE }
/** Array initializer of FGPIO peripheral base pointers */
#define FGPIO_BASE_PTRS                          { FGPIOA, FGPIOB }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO0 base address */
#define FLEXIO0_BASE                             (0x41032000u)
/** Peripheral FLEXIO0 base pointer */
#define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
/** Peripheral FLEXIO1 base address */
#define FLEXIO1_BASE                             (0x40310000u)
/** Peripheral FLEXIO1 base pointer */
#define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE, FLEXIO1_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { FLEXIO0, FLEXIO1 }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { FLEXIO0_IRQn, NotAvail_IRQn }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                               (0x4100F000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                    ((GPIO_Type *)GPIOA_BASE)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                               (0x4100F040u)
/** Peripheral GPIOB base pointer */
#define GPIOB                                    ((GPIO_Type *)GPIOB_BASE)
/** Peripheral GPIOC base address */
#define GPIOC_BASE                               (0x400F0000u)
/** Peripheral GPIOC base pointer */
#define GPIOC                                    ((GPIO_Type *)GPIOC_BASE)
/** Peripheral GPIOD base address */
#define GPIOD_BASE                               (0x400F0040u)
/** Peripheral GPIOD base pointer */
#define GPIOD                                    ((GPIO_Type *)GPIOD_BASE)
/** Peripheral GPIOE base address */
#define GPIOE_BASE                               (0x400F0080u)
/** Peripheral GPIOE base pointer */
#define GPIOE                                    ((GPIO_Type *)GPIOE_BASE)
/** Peripheral GPIOF base address */
#define GPIOF_BASE                               (0x400F00C0u)
/** Peripheral GPIOF base pointer */
#define GPIOF                                    ((GPIO_Type *)GPIOF_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE, GPIOF_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF }

/* I2S - Peripheral instance base addresses */
/** Peripheral I2S0 base address */
#define I2S0_BASE                                (0x41037000u)
/** Peripheral I2S0 base pointer */
#define I2S0                                     ((I2S_Type *)I2S0_BASE)
/** Peripheral I2S1 base address */
#define I2S1_BASE                                (0x410AA000u)
/** Peripheral I2S1 base pointer */
#define I2S1                                     ((I2S_Type *)I2S1_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { I2S0_BASE, I2S1_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { I2S0, I2S1 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { I2S0_IRQn, I2S1_IRQn }
#define I2S_TX_IRQS                              { I2S0_IRQn, I2S1_IRQn }

/* IOMUXC0 - Peripheral instance base addresses */
/** Peripheral IOMUXC0 base address */
#define IOMUXC0_BASE                             (0x4103D000u)
/** Peripheral IOMUXC0 base pointer */
#define IOMUXC0                                  ((IOMUXC0_Type *)IOMUXC0_BASE)
/** Array initializer of IOMUXC0 peripheral base addresses */
#define IOMUXC0_BASE_ADDRS                       { IOMUXC0_BASE }
/** Array initializer of IOMUXC0 peripheral base pointers */
#define IOMUXC0_BASE_PTRS                        { IOMUXC0 }

/* IOMUXC1 - Peripheral instance base addresses */
/** Peripheral IOMUXC1 base address */
#define IOMUXC1_BASE                             (0x40AC0000u)
/** Peripheral IOMUXC1 base pointer */
#define IOMUXC1                                  ((IOMUXC1_Type *)IOMUXC1_BASE)
/** Array initializer of IOMUXC1 peripheral base addresses */
#define IOMUXC1_BASE_ADDRS                       { IOMUXC1_BASE }
/** Array initializer of IOMUXC1 peripheral base pointers */
#define IOMUXC1_BASE_PTRS                        { IOMUXC1 }

/* IOMUXC1_DDR - Peripheral instance base addresses */
/** Peripheral IOMUXC1_DDR base address */
#define IOMUXC1_DDR_BASE                         (0x40AD0000u)
/** Peripheral IOMUXC1_DDR base pointer */
#define IOMUXC1_DDR                              ((IOMUXC1_DDR_Type *)IOMUXC1_DDR_BASE)
/** Array initializer of IOMUXC1_DDR peripheral base addresses */
#define IOMUXC1_DDR_BASE_ADDRS                   { IOMUXC1_DDR_BASE }
/** Array initializer of IOMUXC1_DDR peripheral base pointers */
#define IOMUXC1_DDR_BASE_PTRS                    { IOMUXC1_DDR }

/* LCDIF - Peripheral instance base addresses */
/** Peripheral LCDIF0 base address */
#define LCDIF0_BASE                              (0x40AA0000u)
/** Peripheral LCDIF0 base pointer */
#define LCDIF0                                   ((LCDIF_Type *)LCDIF0_BASE)
/** Array initializer of LCDIF peripheral base addresses */
#define LCDIF_BASE_ADDRS                         { LCDIF0_BASE }
/** Array initializer of LCDIF peripheral base pointers */
#define LCDIF_BASE_PTRS                          { LCDIF0 }

/* LLWU - Peripheral instance base addresses */
/** Peripheral LLWU base address */
#define LLWU_BASE                                (0x41021000u)
/** Peripheral LLWU base pointer */
#define LLWU                                     ((LLWU_Type *)LLWU_BASE)
/** Array initializer of LLWU peripheral base addresses */
#define LLWU_BASE_ADDRS                          { LLWU_BASE }
/** Array initializer of LLWU peripheral base pointers */
#define LLWU_BASE_PTRS                           { LLWU }
/** Interrupt vectors for the LLWU peripheral type */
#define LLWU_IRQS                                { LLWU0_IRQn }

/* LMEM - Peripheral instance base addresses */
/** Peripheral LMEM base address */
#define LMEM_BASE                                (0xE0082000u)
/** Peripheral LMEM base pointer */
#define LMEM                                     ((LMEM_Type *)LMEM_BASE)
/** Array initializer of LMEM peripheral base addresses */
#define LMEM_BASE_ADDRS                          { LMEM_BASE }
/** Array initializer of LMEM peripheral base pointers */
#define LMEM_BASE_PTRS                           { LMEM }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x41033000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x41034000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x41035000u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
/** Peripheral LPI2C3 base address */
#define LPI2C3_BASE                              (0x41036000u)
/** Peripheral LPI2C3 base pointer */
#define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
/** Peripheral LPI2C4 base address */
#define LPI2C4_BASE                              (0x402B0000u)
/** Peripheral LPI2C4 base pointer */
#define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
/** Peripheral LPI2C5 base address */
#define LPI2C5_BASE                              (0x402C0000u)
/** Peripheral LPI2C5 base pointer */
#define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
/** Peripheral LPI2C6 base address */
#define LPI2C6_BASE                              (0x40A40000u)
/** Peripheral LPI2C6 base pointer */
#define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
/** Peripheral LPI2C7 base address */
#define LPI2C7_BASE                              (0x40A50000u)
/** Peripheral LPI2C7 base pointer */
#define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT0 base address */
#define LPIT0_BASE                               (0x4102D000u)
/** Peripheral LPIT0 base pointer */
#define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
/** Peripheral LPIT1 base address */
#define LPIT1_BASE                               (0x40270000u)
/** Peripheral LPIT1 base pointer */
#define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { LPIT0_BASE, LPIT1_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { LPIT0, LPIT1 }
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { { LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn }, { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn } }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x41038000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x41039000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x40290000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Peripheral LPSPI3 base address */
#define LPSPI3_BASE                              (0x402A0000u)
/** Peripheral LPSPI3 base pointer */
#define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2, LPSPI3 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0x4102E000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
/** Peripheral LPTMR1 base address */
#define LPTMR1_BASE                              (0x4102F000u)
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
#define LPUART0_BASE                             (0x4103A000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x4103B000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x410AB000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Peripheral LPUART3 base address */
#define LPUART3_BASE                             (0x410AC000u)
/** Peripheral LPUART3 base pointer */
#define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
/** Peripheral LPUART4 base address */
#define LPUART4_BASE                             (0x402D0000u)
/** Peripheral LPUART4 base pointer */
#define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
/** Peripheral LPUART5 base address */
#define LPUART5_BASE                             (0x402E0000u)
/** Peripheral LPUART5 base pointer */
#define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
/** Peripheral LPUART6 base address */
#define LPUART6_BASE                             (0x40A60000u)
/** Peripheral LPUART6 base pointer */
#define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
/** Peripheral LPUART7 base address */
#define LPUART7_BASE                             (0x40A70000u)
/** Peripheral LPUART7 base pointer */
#define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* LTC - Peripheral instance base addresses */
/** Peripheral LTC0 base address */
#define LTC0_BASE                                (0x4102A000u)
/** Peripheral LTC0 base pointer */
#define LTC0                                     ((LTC_Type *)LTC0_BASE)
/** Array initializer of LTC peripheral base addresses */
#define LTC_BASE_ADDRS                           { LTC0_BASE }
/** Array initializer of LTC peripheral base pointers */
#define LTC_BASE_PTRS                            { LTC0 }
/** Interrupt vectors for the LTC peripheral type */
#define LTC_IRQS                                 { LTC_IRQn }

/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base address */
#define MCM_BASE                                 (0xE0080000u)
/** Peripheral MCM base pointer */
#define MCM                                      ((MCM_Type *)MCM_BASE)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS                           { MCM_BASE }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM }
/** Interrupt vectors for the MCM peripheral type */
#define MCM_IRQS                                 { MCM0_IRQn }

/* MIPI_DSI_HOST - Peripheral instance base addresses */
/** Peripheral MIPI_DSI_HOST0 base address */
#define MIPI_DSI_HOST0_BASE                      (0x40A90000u)
/** Peripheral MIPI_DSI_HOST0 base pointer */
#define MIPI_DSI_HOST0                           ((MIPI_DSI_HOST_Type *)MIPI_DSI_HOST0_BASE)
/** Array initializer of MIPI_DSI_HOST peripheral base addresses */
#define MIPI_DSI_HOST_BASE_ADDRS                 { MIPI_DSI_HOST0_BASE }
/** Array initializer of MIPI_DSI_HOST peripheral base pointers */
#define MIPI_DSI_HOST_BASE_PTRS                  { MIPI_DSI_HOST0 }

/* MIPI_DSI_HOST_APB_PKT_IF - Peripheral instance base addresses */
/** Peripheral MIPI_DSI_HOST_APB_PKT_IF0 base address */
#define MIPI_DSI_HOST_APB_PKT_IF0_BASE           (0x40A90280u)
/** Peripheral MIPI_DSI_HOST_APB_PKT_IF0 base pointer */
#define MIPI_DSI_HOST_APB_PKT_IF0                ((MIPI_DSI_HOST_APB_PKT_IF_Type *)MIPI_DSI_HOST_APB_PKT_IF0_BASE)
/** Array initializer of MIPI_DSI_HOST_APB_PKT_IF peripheral base addresses */
#define MIPI_DSI_HOST_APB_PKT_IF_BASE_ADDRS      { MIPI_DSI_HOST_APB_PKT_IF0_BASE }
/** Array initializer of MIPI_DSI_HOST_APB_PKT_IF peripheral base pointers */
#define MIPI_DSI_HOST_APB_PKT_IF_BASE_PTRS       { MIPI_DSI_HOST_APB_PKT_IF0 }

/* MIPI_DSI_HOST_DPI_INTFC - Peripheral instance base addresses */
/** Peripheral MIPI_DSI_HOST_DPI_INTFC0 base address */
#define MIPI_DSI_HOST_DPI_INTFC0_BASE            (0x40A90200u)
/** Peripheral MIPI_DSI_HOST_DPI_INTFC0 base pointer */
#define MIPI_DSI_HOST_DPI_INTFC0                 ((MIPI_DSI_HOST_DPI_INTFC_Type *)MIPI_DSI_HOST_DPI_INTFC0_BASE)
/** Array initializer of MIPI_DSI_HOST_DPI_INTFC peripheral base addresses */
#define MIPI_DSI_HOST_DPI_INTFC_BASE_ADDRS       { MIPI_DSI_HOST_DPI_INTFC0_BASE }
/** Array initializer of MIPI_DSI_HOST_DPI_INTFC peripheral base pointers */
#define MIPI_DSI_HOST_DPI_INTFC_BASE_PTRS        { MIPI_DSI_HOST_DPI_INTFC0 }

/* MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC - Peripheral instance base addresses */
/** Peripheral MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC0 base address */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC0_BASE   (0x40A90300u)
/** Peripheral MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC0 base pointer */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC0        ((MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_Type *)MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC0_BASE)
/** Array initializer of MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC peripheral base
 * addresses */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_BASE_ADDRS { MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC0_BASE }
/** Array initializer of MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC peripheral base
 * pointers */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_BASE_PTRS { MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC0 }

/* MMCAU - Peripheral instance base addresses */
/** Peripheral MMCAU base address */
#define MMCAU_BASE                               (0xE0081000u)
/** Peripheral MMCAU base pointer */
#define MMCAU                                    ((MMCAU_Type *)MMCAU_BASE)
/** Array initializer of MMCAU peripheral base addresses */
#define MMCAU_BASE_ADDRS                         { MMCAU_BASE }
/** Array initializer of MMCAU peripheral base pointers */
#define MMCAU_BASE_PTRS                          { MMCAU }

/* MMDC - Peripheral instance base addresses */
/** Peripheral MMDC0 base address */
#define MMDC0_BASE                               (0x40AB0000u)
/** Peripheral MMDC0 base pointer */
#define MMDC0                                    ((MMDC_Type *)MMDC0_BASE)
/** Array initializer of MMDC peripheral base addresses */
#define MMDC_BASE_ADDRS                          { MMDC0_BASE }
/** Array initializer of MMDC peripheral base pointers */
#define MMDC_BASE_PTRS                           { MMDC0 }

/* MU - Peripheral instance base addresses */
/** Peripheral MUA base address */
#define MUA_BASE                                 (0x41022000u)
/** Peripheral MUA base pointer */
#define MUA                                      ((MU_Type *)MUA_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MUA_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MUA }
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU_A_IRQn }

/* OCOTP_CTRL - Peripheral instance base addresses */
/** Peripheral OCOTP_CTRL base address */
#define OCOTP_CTRL_BASE                          (0x410A6000u)
/** Peripheral OCOTP_CTRL base pointer */
#define OCOTP_CTRL                               ((OCOTP_CTRL_Type *)OCOTP_CTRL_BASE)
/** Array initializer of OCOTP_CTRL peripheral base addresses */
#define OCOTP_CTRL_BASE_ADDRS                    { OCOTP_CTRL_BASE }
/** Array initializer of OCOTP_CTRL peripheral base pointers */
#define OCOTP_CTRL_BASE_PTRS                     { OCOTP_CTRL }

/* OTFAD - Peripheral instance base addresses */
/** Peripheral OTFAD base address */
#define OTFAD_BASE                               (0x410A5C00u)
/** Peripheral OTFAD base pointer */
#define OTFAD                                    ((OTFAD_Type *)OTFAD_BASE)
/** Array initializer of OTFAD peripheral base addresses */
#define OTFAD_BASE_ADDRS                         { OTFAD_BASE }
/** Array initializer of OTFAD peripheral base pointers */
#define OTFAD_BASE_PTRS                          { OTFAD }

/* PCC0 - Peripheral instance base addresses */
/** Peripheral PCC0 base address */
#define PCC0_BASE                                (0x41026000u)
/** Peripheral PCC0 base pointer */
#define PCC0                                     ((PCC0_Type *)PCC0_BASE)
/** Array initializer of PCC0 peripheral base addresses */
#define PCC0_BASE_ADDRS                          { PCC0_BASE }
/** Array initializer of PCC0 peripheral base pointers */
#define PCC0_BASE_PTRS                           { PCC0 }

/* PCC1 - Peripheral instance base addresses */
/** Peripheral PCC1 base address */
#define PCC1_BASE                                (0x410B2000u)
/** Peripheral PCC1 base pointer */
#define PCC1                                     ((PCC1_Type *)PCC1_BASE)
/** Array initializer of PCC1 peripheral base addresses */
#define PCC1_BASE_ADDRS                          { PCC1_BASE }
/** Array initializer of PCC1 peripheral base pointers */
#define PCC1_BASE_PTRS                           { PCC1 }

/* PCC2 - Peripheral instance base addresses */
/** Peripheral PCC2 base address */
#define PCC2_BASE                                (0x403F0000u)
/** Peripheral PCC2 base pointer */
#define PCC2                                     ((PCC2_Type *)PCC2_BASE)
/** Array initializer of PCC2 peripheral base addresses */
#define PCC2_BASE_ADDRS                          { PCC2_BASE }
/** Array initializer of PCC2 peripheral base pointers */
#define PCC2_BASE_PTRS                           { PCC2 }

/* PCC3 - Peripheral instance base addresses */
/** Peripheral PCC3 base address */
#define PCC3_BASE                                (0x40B30000u)
/** Peripheral PCC3 base pointer */
#define PCC3                                     ((PCC3_Type *)PCC3_BASE)
/** Array initializer of PCC3 peripheral base addresses */
#define PCC3_BASE_ADDRS                          { PCC3_BASE }
/** Array initializer of PCC3 peripheral base pointers */
#define PCC3_BASE_PTRS                           { PCC3 }

/* PMC0 - Peripheral instance base addresses */
/** Peripheral PMC0 base address */
#define PMC0_BASE                                (0x410A1000u)
/** Peripheral PMC0 base pointer */
#define PMC0                                     ((PMC0_Type *)PMC0_BASE)
/** Array initializer of PMC0 peripheral base addresses */
#define PMC0_BASE_ADDRS                          { PMC0_BASE }
/** Array initializer of PMC0 peripheral base pointers */
#define PMC0_BASE_PTRS                           { PMC0 }
/** Interrupt vectors for the PMC0 peripheral type */
#define PMC0_IRQS                                { PMC0_IRQn }

/* PMC1 - Peripheral instance base addresses */
/** Peripheral PMC1 base address */
#define PMC1_BASE                                (0x40400000u)
/** Peripheral PMC1 base pointer */
#define PMC1                                     ((PMC1_Type *)PMC1_BASE)
/** Array initializer of PMC1 peripheral base addresses */
#define PMC1_BASE_ADDRS                          { PMC1_BASE }
/** Array initializer of PMC1 peripheral base pointers */
#define PMC1_BASE_PTRS                           { PMC1 }

/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x4103F000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x41040000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x40AE0000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x40AF0000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)
/** Peripheral PORTE base address */
#define PORTE_BASE                               (0x40B00000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)
/** Peripheral PORTF base address */
#define PORTF_BASE                               (0x40B10000u)
/** Peripheral PORTF base pointer */
#define PORTF                                    ((PORT_Type *)PORTF_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE, PORTF_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD, PORTE, PORTF }
/** Interrupt vectors for the PORT peripheral type */
#define PORT_IRQS                                { PCTLA_IRQn, PCTLB_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* QuadSPI - Peripheral instance base addresses */
/** Peripheral QuadSPI0 base address */
#define QuadSPI0_BASE                            (0x410A5000u)
/** Peripheral QuadSPI0 base pointer */
#define QuadSPI0                                 ((QuadSPI_Type *)QuadSPI0_BASE)
/** Array initializer of QuadSPI peripheral base addresses */
#define QuadSPI_BASE_ADDRS                       { QuadSPI0_BASE }
/** Array initializer of QuadSPI peripheral base pointers */
#define QuadSPI_BASE_PTRS                        { QuadSPI0 }
/** Interrupt vectors for the QuadSPI peripheral type */
#define QuadSPI_IRQS                             { QSPI_IRQn }

/* ROMC - Peripheral instance base addresses */
/** Peripheral ROMC0 base address */
#define ROMC0_BASE                               (0x41090000u)
/** Peripheral ROMC0 base pointer */
#define ROMC0                                    ((ROMC_Type *)ROMC0_BASE)
/** Peripheral ROMC1 base address */
#define ROMC1_BASE                               (0x40900000u)
/** Peripheral ROMC1 base pointer */
#define ROMC1                                    ((ROMC_Type *)ROMC1_BASE)
/** Array initializer of ROMC peripheral base addresses */
#define ROMC_BASE_ADDRS                          { ROMC0_BASE, ROMC1_BASE }
/** Array initializer of ROMC peripheral base pointers */
#define ROMC_BASE_PTRS                           { ROMC0, ROMC1 }

/* SCG - Peripheral instance base addresses */
/** Peripheral SCG0 base address */
#define SCG0_BASE                                (0x41027000u)
/** Peripheral SCG0 base pointer */
#define SCG0                                     ((SCG_Type *)SCG0_BASE)
/** Peripheral SCG1 base address */
#define SCG1_BASE                                (0x403E0000u)
/** Peripheral SCG1 base pointer */
#define SCG1                                     ((SCG_Type *)SCG1_BASE)
/** Array initializer of SCG peripheral base addresses */
#define SCG_BASE_ADDRS                           { SCG0_BASE, SCG1_BASE }
/** Array initializer of SCG peripheral base pointers */
#define SCG_BASE_PTRS                            { SCG0, SCG1 }
/** Interrupt vectors for the SCG peripheral type */
#define SCG_IRQS                                 { SCG0_IRQn, NotAvail_IRQn }

/* SEMA42 - Peripheral instance base addresses */
/** Peripheral SEMA42_0 base address */
#define SEMA42_0_BASE                            (0x4101B000u)
/** Peripheral SEMA42_0 base pointer */
#define SEMA42_0                                 ((SEMA42_Type *)SEMA42_0_BASE)
/** Peripheral SEMA42_1 base address */
#define SEMA42_1_BASE                            (0x401B0000u)
/** Peripheral SEMA42_1 base pointer */
#define SEMA42_1                                 ((SEMA42_Type *)SEMA42_1_BASE)
/** Array initializer of SEMA42 peripheral base addresses */
#define SEMA42_BASE_ADDRS                        { SEMA42_0_BASE, SEMA42_1_BASE }
/** Array initializer of SEMA42 peripheral base pointers */
#define SEMA42_BASE_PTRS                         { SEMA42_0, SEMA42_1 }

/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x410A3000u)
/** Peripheral SIM base pointer */
#define SIM                                      ((SIM_Type *)SIM_BASE)
/** Array initializer of SIM peripheral base addresses */
#define SIM_BASE_ADDRS                           { SIM_BASE }
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM }
/** Interrupt vectors for the SIM peripheral type */
#define SIM_IRQS                                 { SIM_IRQn }

/* SMC - Peripheral instance base addresses */
/** Peripheral MSMC0 base address */
#define MSMC0_BASE                               (0x410A4000u)
/** Peripheral MSMC0 base pointer */
#define MSMC0                                    ((SMC_Type *)MSMC0_BASE)
/** Peripheral MSMC1 base address */
#define MSMC1_BASE                               (0x40410000u)
/** Peripheral MSMC1 base pointer */
#define MSMC1                                    ((SMC_Type *)MSMC1_BASE)
/** Array initializer of SMC peripheral base addresses */
#define SMC_BASE_ADDRS                           { MSMC0_BASE, MSMC1_BASE }
/** Array initializer of SMC peripheral base pointers */
#define SMC_BASE_PTRS                            { MSMC0, MSMC1 }
/** Interrupt vectors for the SMC peripheral type */
#define SMC_IRQS                                 { CMC0_IRQn, CMC1_IRQn }

/* SNVS - Peripheral instance base addresses */
/** Peripheral SNVS base address */
#define SNVS_BASE                                (0x41070000u)
/** Peripheral SNVS base pointer */
#define SNVS                                     ((SNVS_Type *)SNVS_BASE)
/** Array initializer of SNVS peripheral base addresses */
#define SNVS_BASE_ADDRS                          { SNVS_BASE }
/** Array initializer of SNVS peripheral base pointers */
#define SNVS_BASE_PTRS                           { SNVS }
/** Interrupt vectors for the SNVS peripheral type */
#define SNVS_IRQS                                { SNVS_IRQn }

/* TPM - Peripheral instance base addresses */
/** Peripheral TPM0 base address */
#define TPM0_BASE                                (0x41030000u)
/** Peripheral TPM0 base pointer */
#define TPM0                                     ((TPM_Type *)TPM0_BASE)
/** Peripheral TPM1 base address */
#define TPM1_BASE                                (0x41031000u)
/** Peripheral TPM1 base pointer */
#define TPM1                                     ((TPM_Type *)TPM1_BASE)
/** Peripheral TPM2 base address */
#define TPM2_BASE                                (0x410A8000u)
/** Peripheral TPM2 base pointer */
#define TPM2                                     ((TPM_Type *)TPM2_BASE)
/** Peripheral TPM3 base address */
#define TPM3_BASE                                (0x410A9000u)
/** Peripheral TPM3 base pointer */
#define TPM3                                     ((TPM_Type *)TPM3_BASE)
/** Peripheral TPM4 base address */
#define TPM4_BASE                                (0x40250000u)
/** Peripheral TPM4 base pointer */
#define TPM4                                     ((TPM_Type *)TPM4_BASE)
/** Peripheral TPM5 base address */
#define TPM5_BASE                                (0x40260000u)
/** Peripheral TPM5 base pointer */
#define TPM5                                     ((TPM_Type *)TPM5_BASE)
/** Peripheral TPM6 base address */
#define TPM6_BASE                                (0x40A10000u)
/** Peripheral TPM6 base pointer */
#define TPM6                                     ((TPM_Type *)TPM6_BASE)
/** Peripheral TPM7 base address */
#define TPM7_BASE                                (0x40A20000u)
/** Peripheral TPM7 base pointer */
#define TPM7                                     ((TPM_Type *)TPM7_BASE)
/** Array initializer of TPM peripheral base addresses */
#define TPM_BASE_ADDRS                           { TPM0_BASE, TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE, TPM7_BASE }
/** Array initializer of TPM peripheral base pointers */
#define TPM_BASE_PTRS                            { TPM0, TPM1, TPM2, TPM3, TPM4, TPM5, TPM6, TPM7 }
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { TPM0_IRQn, TPM1_IRQn, TPM2_IRQn, TPM3_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* TRGMUX - Peripheral instance base addresses */
/** Peripheral TRGMUX0 base address */
#define TRGMUX0_BASE                             (0x41024000u)
/** Peripheral TRGMUX0 base pointer */
#define TRGMUX0                                  ((TRGMUX_Type *)TRGMUX0_BASE)
/** Peripheral TRGMUX1 base address */
#define TRGMUX1_BASE                             (0x403A0000u)
/** Peripheral TRGMUX1 base pointer */
#define TRGMUX1                                  ((TRGMUX_Type *)TRGMUX1_BASE)
/** Array initializer of TRGMUX peripheral base addresses */
#define TRGMUX_BASE_ADDRS                        { TRGMUX0_BASE, TRGMUX1_BASE }
/** Array initializer of TRGMUX peripheral base pointers */
#define TRGMUX_BASE_PTRS                         { TRGMUX0, TRGMUX1 }

/* TRNG - Peripheral instance base addresses */
/** Peripheral TRNG0 base address */
#define TRNG0_BASE                               (0x4102C000u)
/** Peripheral TRNG0 base pointer */
#define TRNG0                                    ((TRNG_Type *)TRNG0_BASE)
/** Array initializer of TRNG peripheral base addresses */
#define TRNG_BASE_ADDRS                          { TRNG0_BASE }
/** Array initializer of TRNG peripheral base pointers */
#define TRNG_BASE_PTRS                           { TRNG0 }
/** Interrupt vectors for the TRNG peripheral type */
#define TRNG_IRQS                                { TRNG0_IRQn }

/* TSTMR - Peripheral instance base addresses */
/** Peripheral TSTMRA base address */
#define TSTMRA_BASE                              (0x410A3C00u)
/** Peripheral TSTMRA base pointer */
#define TSTMRA                                   ((TSTMR_Type *)TSTMRA_BASE)
/** Peripheral TSTMRB base address */
#define TSTMRB_BASE                              (0x410A3C08u)
/** Peripheral TSTMRB base pointer */
#define TSTMRB                                   ((TSTMR_Type *)TSTMRB_BASE)
/** Array initializer of TSTMR peripheral base addresses */
#define TSTMR_BASE_ADDRS                         { TSTMRA_BASE, TSTMRB_BASE }
/** Array initializer of TSTMR peripheral base pointers */
#define TSTMR_BASE_PTRS                          { TSTMRA, TSTMRB }

/* USB - Peripheral instance base addresses */
/** Peripheral USB0 base address */
#define USB0_BASE                                (0x40330000u)
/** Peripheral USB0 base pointer */
#define USB0                                     ((USB_Type *)USB0_BASE)
/** Peripheral USB1 base address */
#define USB1_BASE                                (0x40340000u)
/** Peripheral USB1 base pointer */
#define USB1                                     ((USB_Type *)USB1_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB0_BASE, USB1_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB0, USB1 }
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { USB0_IRQn, USB1_IRQn }

/* USBHSDCD - Peripheral instance base addresses */
/** Peripheral DCD base address */
#define DCD_BASE                                 (0x40350800u)
/** Peripheral DCD base pointer */
#define DCD                                      ((USBHSDCD_Type *)DCD_BASE)
/** Array initializer of USBHSDCD peripheral base addresses */
#define USBHSDCD_BASE_ADDRS                      { DCD_BASE }
/** Array initializer of USBHSDCD peripheral base pointers */
#define USBHSDCD_BASE_PTRS                       { DCD }

/* USBNC - Peripheral instance base addresses */
/** Peripheral USBNC0 base address */
#define USBNC0_BASE                              (0x40330200u)
/** Peripheral USBNC0 base pointer */
#define USBNC0                                   ((USBNC_Type *)USBNC0_BASE)
/** Peripheral USBNC1 base address */
#define USBNC1_BASE                              (0x40340200u)
/** Peripheral USBNC1 base pointer */
#define USBNC1                                   ((USBNC_Type *)USBNC1_BASE)
/** Array initializer of USBNC peripheral base addresses */
#define USBNC_BASE_ADDRS                         { USBNC0_BASE, USBNC1_BASE }
/** Array initializer of USBNC peripheral base pointers */
#define USBNC_BASE_PTRS                          { USBNC0, USBNC1 }

/* USBPHY - Peripheral instance base addresses */
/** Peripheral USBPHY base address */
#define USBPHY_BASE                              (0x40350000u)
/** Peripheral USBPHY base pointer */
#define USBPHY                                   ((USBPHY_Type *)USBPHY_BASE)
/** Array initializer of USBPHY peripheral base addresses */
#define USBPHY_BASE_ADDRS                        { USBPHY_BASE }
/** Array initializer of USBPHY peripheral base pointers */
#define USBPHY_BASE_PTRS                         { USBPHY }
/** Interrupt vectors for the USBPHY peripheral type */
#define USBPHY_IRQS                              { USBPHY_IRQn }

/* USDHC - Peripheral instance base addresses */
/** Peripheral USDHC0 base address */
#define USDHC0_BASE                              (0x40370000u)
/** Peripheral USDHC0 base pointer */
#define USDHC0                                   ((USDHC_Type *)USDHC0_BASE)
/** Peripheral USDHC1 base address */
#define USDHC1_BASE                              (0x40380000u)
/** Peripheral USDHC1 base pointer */
#define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
/** Array initializer of USDHC peripheral base addresses */
#define USDHC_BASE_ADDRS                         { USDHC0_BASE, USDHC1_BASE }
/** Array initializer of USDHC peripheral base pointers */
#define USDHC_BASE_PTRS                          { USDHC0, USDHC1 }

/* VIU - Peripheral instance base addresses */
/** Peripheral VIU base address */
#define VIU_BASE                                 (0x40A80000u)
/** Peripheral VIU base pointer */
#define VIU                                      ((VIU_Type *)VIU_BASE)
/** Array initializer of VIU peripheral base addresses */
#define VIU_BASE_ADDRS                           { VIU_BASE }
/** Array initializer of VIU peripheral base pointers */
#define VIU_BASE_PTRS                            { VIU }

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG0 base address */
#define WDOG0_BASE                               (0x41025000u)
/** Peripheral WDOG0 base pointer */
#define WDOG0                                    ((WDOG_Type *)WDOG0_BASE)
/** Peripheral WDOG1 base address */
#define WDOG1_BASE                               (0x403D0000u)
/** Peripheral WDOG1 base pointer */
#define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
/** Peripheral WDOG2 base address */
#define WDOG2_BASE                               (0x40430000u)
/** Peripheral WDOG2 base pointer */
#define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG0_BASE, WDOG1_BASE, WDOG2_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG0, WDOG1, WDOG2 }
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { WDOG0_IRQn, WDOG1_IRQn, WDOG2_IRQn }

/* XRDC - Peripheral instance base addresses */
/** Peripheral XRDC base address */
#define XRDC_BASE                                (0x41014000u)
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


#endif  /* MCIMX7U3_CM4_COMMON_H_ */

