/*
** ###################################################################
**     Processors:          MIMX8UD5CVP08_cm33
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVP08_cm33
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX8ULPRM, Rev. D, December. 2022
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX8UD5_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMX8UD5_cm33_COMMON.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMX8UD5_cm33
 *
 * CMSIS Peripheral Access Layer for MIMX8UD5_cm33
 */

#if !defined(MIMX8UD5_CM33_COMMON_H_)
#define MIMX8UD5_CM33_COMMON_H_                  /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0600U
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
#define NUMBER_OF_INT_VECTORS 196                /**< Number of interrupts in the Vector table */

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
  CTI0_IRQn                    = 0,                /**< Cross Trigger Interface */
  DMA0_0_IRQn                  = 1,                /**< DMA0 Channel 0 Error or Transfer Complete */
  DMA0_1_IRQn                  = 2,                /**< DMA0 Channel 1 Error or Transfer Complete */
  DMA0_2_IRQn                  = 3,                /**< DMA0 Channel 2 Error or Transfer Complete */
  DMA0_3_IRQn                  = 4,                /**< DMA0 Channel 3 Error or Transfer Complete */
  DMA0_4_IRQn                  = 5,                /**< DMA0 Channel 4 Error or Transfer Complete */
  DMA0_5_IRQn                  = 6,                /**< DMA0 Channel 5 Error or Transfer Complete */
  DMA0_6_IRQn                  = 7,                /**< DMA0 Channel 6 Error or Transfer Complete */
  DMA0_7_IRQn                  = 8,                /**< DMA0 Channel 7 Error or Transfer Complete */
  DMA0_8_IRQn                  = 9,                /**< DMA0 Channel 8 Error or Transfer Complete */
  DMA0_9_IRQn                  = 10,               /**< DMA0 Channel 9 Error or Transfer Complete */
  DMA0_10_IRQn                 = 11,               /**< DMA0 Channel 10 Error or Transfer Complete */
  DMA0_11_IRQn                 = 12,               /**< DMA0 Channel 11 Error or Transfer Complete */
  DMA0_12_IRQn                 = 13,               /**< DMA0 Channel 12 Error or Transfer Complete */
  DMA0_13_IRQn                 = 14,               /**< DMA0 Channel 13 Error or Transfer Complete */
  DMA0_14_IRQn                 = 15,               /**< DMA0 Channel 14 Error or Transfer Complete */
  DMA0_15_IRQn                 = 16,               /**< DMA0 Channel 15 Error or Transfer Complete */
  DMA0_16_IRQn                 = 17,               /**< DMA0 Channel 16 Error or Transfer Complete */
  DMA0_17_IRQn                 = 18,               /**< DMA0 Channel 17 Error or Transfer Complete */
  DMA0_18_IRQn                 = 19,               /**< DMA0 Channel 18 Error or Transfer Complete */
  DMA0_19_IRQn                 = 20,               /**< DMA0 Channel 19 Error or Transfer Complete */
  DMA0_20_IRQn                 = 21,               /**< DMA0 Channel 20 Error or Transfer Complete */
  DMA0_21_IRQn                 = 22,               /**< DMA0 Channel 21 Error or Transfer Complete */
  DMA0_22_IRQn                 = 23,               /**< DMA0 Channel 22 Error or Transfer Complete */
  DMA0_23_IRQn                 = 24,               /**< DMA0 Channel 23 Error or Transfer Complete */
  DMA0_24_IRQn                 = 25,               /**< DMA0 Channel 24 Error or Transfer Complete */
  DMA0_25_IRQn                 = 26,               /**< DMA0 Channel 25 Error or Transfer Complete */
  DMA0_26_IRQn                 = 27,               /**< DMA0 Channel 26 Error or Transfer Complete */
  DMA0_27_IRQn                 = 28,               /**< DMA0 Channel 27 Error or Transfer Complete */
  DMA0_28_IRQn                 = 29,               /**< DMA0 Channel 28 Error or Transfer Complete */
  DMA0_29_IRQn                 = 30,               /**< DMA0 Channel 29 Error or Transfer Complete */
  DMA0_30_IRQn                 = 31,               /**< DMA0 Channel 30 Error or Transfer Complete */
  DMA0_31_IRQn                 = 32,               /**< DMA0 Channel 31 Error or Transfer Complete */
  DMA2_0_IRQn                  = 33,               /**< DMA2 Channel 0 Error or Transfer Complete */
  DMA2_1_IRQn                  = 34,               /**< DMA2 Channel 1 Error or Transfer Complete */
  DMA2_2_IRQn                  = 35,               /**< DMA2 Channel 2 Error or Transfer Complete */
  DMA2_3_IRQn                  = 36,               /**< DMA2 Channel 3 Error or Transfer Complete */
  DMA2_4_IRQn                  = 37,               /**< DMA2 Channel 4 Error or Transfer Complete */
  DMA2_5_IRQn                  = 38,               /**< DMA2 Channel 5 Error or Transfer Complete */
  DMA2_6_IRQn                  = 39,               /**< DMA2 Channel 6 Error or Transfer Complete */
  DMA2_7_IRQn                  = 40,               /**< DMA2 Channel 7 Error or Transfer Complete */
  DMA2_8_IRQn                  = 41,               /**< DMA2 Channel 8 Error or Transfer Complete */
  DMA2_9_IRQn                  = 42,               /**< DMA2 Channel 9 Error or Transfer Complete */
  DMA2_10_IRQn                 = 43,               /**< DMA2 Channel 10 Error or Transfer Complete */
  DMA2_11_IRQn                 = 44,               /**< DMA2 Channel 11 Error or Transfer Complete */
  DMA2_12_IRQn                 = 45,               /**< DMA2 Channel 12 Error or Transfer Complete */
  DMA2_13_IRQn                 = 46,               /**< DMA2 Channel 13 Error or Transfer Complete */
  DMA2_14_IRQn                 = 47,               /**< DMA2 Channel 14 Error or Transfer Complete */
  DMA2_15_IRQn                 = 48,               /**< DMA2 Channel 15 Error or Transfer Complete */
  DMA2_16_IRQn                 = 49,               /**< DMA2 Channel 16 Error or Transfer Complete */
  DMA2_17_IRQn                 = 50,               /**< DMA2 Channel 17 Error or Transfer Complete */
  DMA2_18_IRQn                 = 51,               /**< DMA2 Channel 18 Error or Transfer Complete */
  DMA2_19_IRQn                 = 52,               /**< DMA2 Channel 19 Error or Transfer Complete */
  DMA2_20_IRQn                 = 53,               /**< DMA2 Channel 20 Error or Transfer Complete */
  DMA2_21_IRQn                 = 54,               /**< DMA2 Channel 21 Error or Transfer Complete */
  DMA2_22_IRQn                 = 55,               /**< DMA2 Channel 22 Error or Transfer Complete */
  DMA2_23_IRQn                 = 56,               /**< DMA2 Channel 23 Error or Transfer Complete */
  DMA2_24_IRQn                 = 57,               /**< DMA2 Channel 24 Error or Transfer Complete */
  DMA2_25_IRQn                 = 58,               /**< DMA2 Channel 25 Error or Transfer Complete */
  DMA2_26_IRQn                 = 59,               /**< DMA2 Channel 26 Error or Transfer Complete */
  DMA2_27_IRQn                 = 60,               /**< DMA2 Channel 27 Error or Transfer Complete */
  DMA2_28_IRQn                 = 61,               /**< DMA2 Channel 28 Error or Transfer Complete */
  DMA2_29_IRQn                 = 62,               /**< DMA2 Channel 29 Error or Transfer Complete */
  DMA2_30_IRQn                 = 63,               /**< DMA2 Channel 30 Error or Transfer Complete */
  DMA2_31_IRQn                 = 64,               /**< DMA2 Channel 31 Error or Transfer Complete */
  CMC0_IRQn                    = 65,               /**< Core Mode Controller 0 */
  CMC2_IRQn                    = 66,               /**< Core Mode Controller 2 */
  uPower_IRQn                  = 67,               /**< uPower interrupt */
  WUU0_IRQn                    = 68,               /**< Wake Up Unit 0 */
  CGC0_IRQn                    = 69,               /**< System Clock Generator for RT interrupt */
  CGC1_IRQn                    = 70,               /**< Clock Generation and Control 1 */
  CGC2_IRQn                    = 71,               /**< Clock Generation and Control 2 */
  SIM0_IRQn                    = 72,               /**< System Integration Module 0 */
  PMC_IRQn                     = 73,               /**< Power Management Controller */
  MU0_A_IRQn                   = 74,               /**< Messaging Unit 0 - Side A (to communicate with A35core) */
  MU1_A_IRQn                   = 75,               /**< Messaging Unit 1 - Side A (to communicate with Fusion DSP) */
  MU2_A_IRQn                   = 76,               /**< Messaging Unit 2 - Side A (to communicate with HiFi4 DSP) */
  WDOG0_IRQn                   = 77,               /**< Watchdog 0 Interrupt */
  WDOG1_IRQn                   = 78,               /**< Watchdog 1 Interrupt */
  WDOG2_IRQn                   = 79,               /**< Watchdog 2 Interrupt */
  WDOG3_IRQn                   = 80,               /**< Watchdog 3 Interrupt */
  WDOG4_IRQn                   = 81,               /**< Watchdog 4 Interrupt */
  EWM_IRQn                     = 82,               /**< External Watchdog Monitor Interrupt */
  CMC1_IRQn                    = 83,               /**< Core Mode Controller 1 */
  SNTCommandInterface_IRQn     = 84,               /**< Sentinel command interface interrupt */
  SNTSecure_IRQn               = 85,               /**< Sentinel secure interrupt */
  SNTNonSecure_IRQn            = 86,               /**< Sentinel non-secure interrupt */
  BBNSM_IRQn                   = 87,               /**< Secure Non-Volatile Storage Consolidated Interrupt */
  TRDC_IRQn                    = 88,               /**< Trusted Resource Domain Controller interrupt */
  XRDC_IRQn                    = 89,               /**< Extended Rexource Domain Control */
  LPTMR0_IRQn                  = 90,               /**< Low Power Timer 0 */
  LPTMR1_IRQn                  = 91,               /**< Low Power Timer 1 */
  Reserved108_IRQn             = 92,               /**< Reserved */
  Reserved109_IRQn             = 93,               /**< Reserved */
  LPIT0_IRQn                   = 94,               /**< Low Power Periodic Interrupt Timer 0 */
  TPM0_IRQn                    = 95,               /**< Timer PWM module 0 */
  TPM1_IRQn                    = 96,               /**< Timer PWM module 1 */
  TPM2_IRQn                    = 97,               /**< Timer PWM module 2 */
  TPM3_IRQn                    = 98,               /**< Timer PWM module 3 */
  TPM4_IRQn                    = 99,               /**< Timer PWM module 4 */
  Reserved116_IRQn             = 100,              /**< Reserved */
  MRT0_IRQn                    = 101,              /**< Multi-Rate Timer interrupt */
  FlexCAN_IRQn                 = 102,              /**< Flexible Controller Area Network interrupt */
  FLEXIO0_IRQn                 = 103,              /**< Flexible IO 0 */
  LPI2C0_IRQn                  = 104,              /**< Low Power Inter-Integrated Circuit module 0 */
  LPI2C1_IRQn                  = 105,              /**< Low Power Inter-Integrated Circuit module 1 */
  LPI2C2_IRQn                  = 106,              /**< Low Power Inter-Integrated Circuit module 2 */
  LPI2C3_IRQn                  = 107,              /**< Low Power Inter-Integrated Circuit module 3 */
  LPSPI0_IRQn                  = 108,              /**< Low Power Serial Peripheral Interface 0 */
  LPSPI1_IRQn                  = 109,              /**< Low Power Serial Peripheral Interface 1 */
  LPSPI2_IRQn                  = 110,              /**< Low Power Serial Peripheral Interface 2 */
  LPSPI3_IRQn                  = 111,              /**< Low Power Serial Peripheral Interface 3 */
  LPUART0_IRQn                 = 112,              /**< Low Power UART 0 */
  LPUART1_IRQn                 = 113,              /**< Low Power UART 1 */
  LPUART2_IRQn                 = 114,              /**< Low Power UART 2 */
  LPUART3_IRQn                 = 115,              /**< Low Power UART 3 */
  USB0_IRQn                    = 116,              /**< USB Interrupt from A7 subsystem */
  USBPHY0_IRQn                 = 117,              /**< USB PHY (used in conjunction with USB0) */
  USB1_IRQn                    = 118,              /**< USB Interrupt from A7 subsystem */
  USBPHY1_IRQn                 = 119,              /**< USB PHY (used in conjunction with USB1) */
  PDM_EVENT_IRQn               = 120,              /**< Digital Microphone interrupt */
  PDM_HWVAD_EVENT_IRQn         = 121,              /**< Digital Microphone Voice Activity Detection interrupt */
  SAI0_IRQn                    = 122,              /**< Serial Audio Interface 0 */
  SAI1_IRQn                    = 123,              /**< Serial Audio Interface 1 */
  SAI2_IRQn                    = 124,              /**< Serial Audio Interface 2 */
  SAI3_IRQn                    = 125,              /**< Serial Audio Interface 3 */
  SAI6_IRQn                    = 126,              /**< Serial Audio Interface 6 */
  SAI7_IRQn                    = 127,              /**< Serial Audio Interface 7 */
  SPDIF_IRQn                   = 128,              /**< Sony/Phillips Digital Interface */
  DCNano_IRQn                  = 129,              /**< Display Control Nano interrupt */
  DSI_IRQn                     = 130,              /**< DSI controller interrupt */
  GPU3D_IRQn                   = 131,              /**< Graphic Processor Unit 3D interrupt */
  GPU2D_IRQn                   = 132,              /**< Graphic Processor Unit 2D interrupt */
  GPIOA_INT0_IRQn              = 133,              /**< General Purpose Input/Output A interrupt 0 */
  GPIOA_INT1_IRQn              = 134,              /**< General Purpose Input/Output A interrupt 1 */
  GPIOB_INT0_IRQn              = 135,              /**< General Purpose Input/Output B interrupt 0 */
  GPIOB_INT1_IRQn              = 136,              /**< General Purpose Input/Output B interrupt 1 */
  GPIOC_INT0_IRQn              = 137,              /**< General Purpose Input/Output C interrupt 0 */
  GPIOC_INT1_IRQn              = 138,              /**< General Purpose Input/Output C interrupt 1 */
  GPIOD_INT0_IRQn              = 139,              /**< General Purpose Input/Output D interrupt 0 */
  GPIOD_INT1_IRQn              = 140,              /**< General Purpose Input/Output D interrupt 1 */
  GPIOE_INT0_IRQn              = 141,              /**< General Purpose Input/Output E interrupt 0 */
  GPIOE_INT1_IRQn              = 142,              /**< General Purpose Input/Output E interrupt 1 */
  GPIOF_INT0_IRQn              = 143,              /**< General Purpose Input/Output F interrupt 0 */
  GPIOF_INT1_IRQn              = 144,              /**< General Purpose Input/Output F interrupt 1 */
  Reserved161_IRQn             = 145,              /**< Reserved */
  Reserved162_IRQn             = 146,              /**< Reserved */
  Reserved163_IRQn             = 147,              /**< Reserved */
  Reserved164_IRQn             = 148,              /**< Reserved */
  Reserved165_IRQn             = 149,              /**< Reserved */
  Reserved166_IRQn             = 150,              /**< Reserved */
  ADC0_IRQn                    = 151,              /**< Analog to Digital Convertor 0 */
  ADC1_IRQn                    = 152,              /**< Analog to Digital Convertor 1 */
  CMP0_IRQn                    = 153,              /**< Comparator 0 */
  CMP1_IRQn                    = 154,              /**< Comparator 1 */
  DAC0_IRQn                    = 155,              /**< Digital to Analog Convertor 0 */
  DAC1_IRQn                    = 156,              /**< Digital to Analog Convertor 1 */
  FlexSPI0_IRQn                = 157,              /**< FlexSPI controller interface interrupt 0 */
  FlexSPI1_IRQn                = 158,              /**< FlexSPI controller interface interrupt 1 */
  FlexSPI2_IRQn                = 159,              /**< FlexSPI controller interface interrupt 2 */
  uSDHC0_IRQn                  = 160,              /**< ultra Secure Digital Host Controller interrupt 0 */
  uSDHC1_IRQn                  = 161,              /**< ultra Secure Digital Host Controller interrupt 1 */
  uSDHC2_IRQn                  = 162,              /**< ultra Secure Digital Host Controller interrupt 2 */
  MDDR_IRQn                    = 163,              /**< Multi-Port Double Data Rate */
  FLEXIO1_IRQn                 = 164,              /**< Flexible IO 1 interrupt */
  I3C0_IRQn                    = 165,              /**< Improved Inter-Integrated Circuit 0 interrupt */
  I3C1_IRQn                    = 166,              /**< Improved Inter-Integrated Circuit 1 interrupt */
  CASPER_IRQn                  = 167,              /**< Cryptographic Accelerator and Signal Processing Engine with RAM-sharing */
  PowerQuad_IRQn               = 168,              /**< PowerQuad Digital Signal Co-Processor */
  EPDC_IRQn                    = 169,              /**< Electronics Paper Display Controller interrupt */
  PXP_IRQn                     = 170,              /**< Pixel Processor interrupt */
  CTI1_IRQn                    = 171,              /**< Cross Trigger Interface */
  DMA1_0_IRQn                  = 172,              /**< DMA1 Channel 0 error or transfer complete */
  DMA1_1_IRQn                  = 173,              /**< DMA1 Channel 1 error or transfer complete */
  DMA1_2_IRQn                  = 174,              /**< DMA1 Channel 2 error or transfer complete */
  DMA1_3_IRQn                  = 175,              /**< DMA1 Channel 3 error or transfer complete */
  DMA1_4_IRQn                  = 176,              /**< DMA1 Channel 4 error or transfer complete */
  DMA1_5_IRQn                  = 177,              /**< DMA1 Channel 5 error or transfer complete */
  DMA1_6_IRQn                  = 178,              /**< DMA1 Channel 6 error or transfer complete */
  DMA1_7_IRQn                  = 179               /**< DMA1 Channel 7 error or transfer complete */
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
#define __SAUREGION_PRESENT            1         /**< Defines if an SAU is present or not */

#include "core_cm33.h"                 /* Core Peripheral Access Layer */
#include "system_MIMX8UD5_cm33.h"      /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMX8UD5_cm33_SERIES
#define MIMX8UD5_cm33_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMX8UD5_cm33_features.h"

/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADC0 base address */
  #define ADC0_BASE                                (0x38040000u)
  /** Peripheral ADC0 base address */
  #define ADC0_BASE_NS                             (0x28040000u)
  /** Peripheral ADC0 base pointer */
  #define ADC0                                     ((ADC_Type *)ADC0_BASE)
  /** Peripheral ADC0 base pointer */
  #define ADC0_NS                                  ((ADC_Type *)ADC0_BASE_NS)
  /** Peripheral ADC1 base address */
  #define ADC1_BASE                                (0x380A2000u)
  /** Peripheral ADC1 base address */
  #define ADC1_BASE_NS                             (0x280A2000u)
  /** Peripheral ADC1 base pointer */
  #define ADC1                                     ((ADC_Type *)ADC1_BASE)
  /** Peripheral ADC1 base pointer */
  #define ADC1_NS                                  ((ADC_Type *)ADC1_BASE_NS)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC0_BASE, ADC1_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC0, ADC1 }
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS_NS                        { ADC0_BASE_NS, ADC1_BASE_NS }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS_NS                         { ADC0_NS, ADC1_NS }
#else
  /** Peripheral ADC0 base address */
  #define ADC0_BASE                                (0x28040000u)
  /** Peripheral ADC0 base pointer */
  #define ADC0                                     ((ADC_Type *)ADC0_BASE)
  /** Peripheral ADC1 base address */
  #define ADC1_BASE                                (0x280A2000u)
  /** Peripheral ADC1 base pointer */
  #define ADC1                                     ((ADC_Type *)ADC1_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC0_BASE, ADC1_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC0, ADC1 }
#endif
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn, ADC1_IRQn }

/* AHB_ADDR_REMAP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADDR_REMAP0 base address */
  #define ADDR_REMAP0_BASE                         (0x38039800u)
  /** Peripheral ADDR_REMAP0 base address */
  #define ADDR_REMAP0_BASE_NS                      (0x28039800u)
  /** Peripheral ADDR_REMAP0 base pointer */
  #define ADDR_REMAP0                              ((AHB_ADDR_REMAP_Type *)ADDR_REMAP0_BASE)
  /** Peripheral ADDR_REMAP0 base pointer */
  #define ADDR_REMAP0_NS                           ((AHB_ADDR_REMAP_Type *)ADDR_REMAP0_BASE_NS)
  /** Peripheral ADDR_REMAP1 base address */
  #define ADDR_REMAP1_BASE                         (0x39810800u)
  /** Peripheral ADDR_REMAP1 base address */
  #define ADDR_REMAP1_BASE_NS                      (0x29810800u)
  /** Peripheral ADDR_REMAP1 base pointer */
  #define ADDR_REMAP1                              ((AHB_ADDR_REMAP_Type *)ADDR_REMAP1_BASE)
  /** Peripheral ADDR_REMAP1 base pointer */
  #define ADDR_REMAP1_NS                           ((AHB_ADDR_REMAP_Type *)ADDR_REMAP1_BASE_NS)
  /** Array initializer of AHB_ADDR_REMAP peripheral base addresses */
  #define AHB_ADDR_REMAP_BASE_ADDRS                { ADDR_REMAP0_BASE, ADDR_REMAP1_BASE }
  /** Array initializer of AHB_ADDR_REMAP peripheral base pointers */
  #define AHB_ADDR_REMAP_BASE_PTRS                 { ADDR_REMAP0, ADDR_REMAP1 }
  /** Array initializer of AHB_ADDR_REMAP peripheral base addresses */
  #define AHB_ADDR_REMAP_BASE_ADDRS_NS             { ADDR_REMAP0_BASE_NS, ADDR_REMAP1_BASE_NS }
  /** Array initializer of AHB_ADDR_REMAP peripheral base pointers */
  #define AHB_ADDR_REMAP_BASE_PTRS_NS              { ADDR_REMAP0_NS, ADDR_REMAP1_NS }
#else
  /** Peripheral ADDR_REMAP0 base address */
  #define ADDR_REMAP0_BASE                         (0x28039800u)
  /** Peripheral ADDR_REMAP0 base pointer */
  #define ADDR_REMAP0                              ((AHB_ADDR_REMAP_Type *)ADDR_REMAP0_BASE)
  /** Peripheral ADDR_REMAP1 base address */
  #define ADDR_REMAP1_BASE                         (0x29810800u)
  /** Peripheral ADDR_REMAP1 base pointer */
  #define ADDR_REMAP1                              ((AHB_ADDR_REMAP_Type *)ADDR_REMAP1_BASE)
  /** Array initializer of AHB_ADDR_REMAP peripheral base addresses */
  #define AHB_ADDR_REMAP_BASE_ADDRS                { ADDR_REMAP0_BASE, ADDR_REMAP1_BASE }
  /** Array initializer of AHB_ADDR_REMAP peripheral base pointers */
  #define AHB_ADDR_REMAP_BASE_PTRS                 { ADDR_REMAP0, ADDR_REMAP1 }
#endif

/* AXBS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AXBS0 base address */
  #define AXBS0_BASE                               (0x38000000u)
  /** Peripheral AXBS0 base address */
  #define AXBS0_BASE_NS                            (0x28000000u)
  /** Peripheral AXBS0 base pointer */
  #define AXBS0                                    ((AXBS_Type *)AXBS0_BASE)
  /** Peripheral AXBS0 base pointer */
  #define AXBS0_NS                                 ((AXBS_Type *)AXBS0_BASE_NS)
  /** Peripheral AXBS1 base address */
  #define AXBS1_BASE                               (0x39000000u)
  /** Peripheral AXBS1 base address */
  #define AXBS1_BASE_NS                            (0x29000000u)
  /** Peripheral AXBS1 base pointer */
  #define AXBS1                                    ((AXBS_Type *)AXBS1_BASE)
  /** Peripheral AXBS1 base pointer */
  #define AXBS1_NS                                 ((AXBS_Type *)AXBS1_BASE_NS)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { AXBS0_BASE, AXBS1_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { AXBS0, AXBS1 }
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS_NS                       { AXBS0_BASE_NS, AXBS1_BASE_NS }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS_NS                        { AXBS0_NS, AXBS1_NS }
#else
  /** Peripheral AXBS0 base address */
  #define AXBS0_BASE                               (0x28000000u)
  /** Peripheral AXBS0 base pointer */
  #define AXBS0                                    ((AXBS_Type *)AXBS0_BASE)
  /** Peripheral AXBS1 base address */
  #define AXBS1_BASE                               (0x29000000u)
  /** Peripheral AXBS1 base pointer */
  #define AXBS1                                    ((AXBS_Type *)AXBS1_BASE)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { AXBS0_BASE, AXBS1_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { AXBS0, AXBS1 }
#endif

/* BBNSM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE                               (0x38038000u)
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE_NS                            (0x28038000u)
  /** Peripheral BBNSM base pointer */
  #define BBNSM                                    ((BBNSM_Type *)BBNSM_BASE)
  /** Peripheral BBNSM base pointer */
  #define BBNSM_NS                                 ((BBNSM_Type *)BBNSM_BASE_NS)
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS                         { BBNSM_BASE }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS                          { BBNSM }
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS_NS                      { BBNSM_BASE_NS }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS_NS                       { BBNSM_NS }
#else
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE                               (0x28038000u)
  /** Peripheral BBNSM base pointer */
  #define BBNSM                                    ((BBNSM_Type *)BBNSM_BASE)
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS                         { BBNSM_BASE }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS                          { BBNSM }
#endif

/* CACHE64_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CACHE64_CTRL0 base address */
  #define CACHE64_CTRL0_BASE                       (0x38046000u)
  /** Peripheral CACHE64_CTRL0 base address */
  #define CACHE64_CTRL0_BASE_NS                    (0x28046000u)
  /** Peripheral CACHE64_CTRL0 base pointer */
  #define CACHE64_CTRL0                            ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE)
  /** Peripheral CACHE64_CTRL0 base pointer */
  #define CACHE64_CTRL0_NS                         ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE_NS)
  /** Peripheral CACHE64_CTRL1 base address */
  #define CACHE64_CTRL1_BASE                       (0x38046800u)
  /** Peripheral CACHE64_CTRL1 base address */
  #define CACHE64_CTRL1_BASE_NS                    (0x28046800u)
  /** Peripheral CACHE64_CTRL1 base pointer */
  #define CACHE64_CTRL1                            ((CACHE64_CTRL_Type *)CACHE64_CTRL1_BASE)
  /** Peripheral CACHE64_CTRL1 base pointer */
  #define CACHE64_CTRL1_NS                         ((CACHE64_CTRL_Type *)CACHE64_CTRL1_BASE_NS)
  /** Array initializer of CACHE64_CTRL peripheral base addresses */
  #define CACHE64_CTRL_BASE_ADDRS                  { CACHE64_CTRL0_BASE, CACHE64_CTRL1_BASE }
  /** Array initializer of CACHE64_CTRL peripheral base pointers */
  #define CACHE64_CTRL_BASE_PTRS                   { CACHE64_CTRL0, CACHE64_CTRL1 }
  /** Array initializer of CACHE64_CTRL peripheral base addresses */
  #define CACHE64_CTRL_BASE_ADDRS_NS               { CACHE64_CTRL0_BASE_NS, CACHE64_CTRL1_BASE_NS }
  /** Array initializer of CACHE64_CTRL peripheral base pointers */
  #define CACHE64_CTRL_BASE_PTRS_NS                { CACHE64_CTRL0_NS, CACHE64_CTRL1_NS }
#else
  /** Peripheral CACHE64_CTRL0 base address */
  #define CACHE64_CTRL0_BASE                       (0x28046000u)
  /** Peripheral CACHE64_CTRL0 base pointer */
  #define CACHE64_CTRL0                            ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE)
  /** Peripheral CACHE64_CTRL1 base address */
  #define CACHE64_CTRL1_BASE                       (0x28046800u)
  /** Peripheral CACHE64_CTRL1 base pointer */
  #define CACHE64_CTRL1                            ((CACHE64_CTRL_Type *)CACHE64_CTRL1_BASE)
  /** Array initializer of CACHE64_CTRL peripheral base addresses */
  #define CACHE64_CTRL_BASE_ADDRS                  { CACHE64_CTRL0_BASE, CACHE64_CTRL1_BASE }
  /** Array initializer of CACHE64_CTRL peripheral base pointers */
  #define CACHE64_CTRL_BASE_PTRS                   { CACHE64_CTRL0, CACHE64_CTRL1 }
#endif
/** CACHE64_CTRL physical memory base address */
 #define CACHE64_CTRL_PHYMEM_BASES                { 0x00000000u, 0x20000000u }
/** CACHE64_CTRL physical memory size */
 #define CACHE64_CTRL_PHYMEM_SIZES                { 0x20000000u, 0xE0000000u }


/* CAN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CAN0 base address */
  #define CAN0_BASE                                (0x380A8000u)
  /** Peripheral CAN0 base address */
  #define CAN0_BASE_NS                             (0x280A8000u)
  /** Peripheral CAN0 base pointer */
  #define CAN0                                     ((CAN_Type *)CAN0_BASE)
  /** Peripheral CAN0 base pointer */
  #define CAN0_NS                                  ((CAN_Type *)CAN0_BASE_NS)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { CAN0_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { CAN0 }
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS_NS                        { CAN0_BASE_NS }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS_NS                         { CAN0_NS }
#else
  /** Peripheral CAN0 base address */
  #define CAN0_BASE                                (0x280A8000u)
  /** Peripheral CAN0 base pointer */
  #define CAN0                                     ((CAN_Type *)CAN0_BASE)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { CAN0_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { CAN0 }
#endif
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { FlexCAN_IRQn }
#define CAN_Tx_Warning_IRQS                      { FlexCAN_IRQn }
#define CAN_Wake_Up_IRQS                         { FlexCAN_IRQn }
#define CAN_Error_IRQS                           { FlexCAN_IRQn }
#define CAN_Bus_Off_IRQS                         { FlexCAN_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { FlexCAN_IRQn }

/* CASPER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CASPER base address */
  #define CASPER_BASE                              (0x38410000u)
  /** Peripheral CASPER base address */
  #define CASPER_BASE_NS                           (0x28410000u)
  /** Peripheral CASPER base pointer */
  #define CASPER                                   ((CASPER_Type *)CASPER_BASE)
  /** Peripheral CASPER base pointer */
  #define CASPER_NS                                ((CASPER_Type *)CASPER_BASE_NS)
  /** Array initializer of CASPER peripheral base addresses */
  #define CASPER_BASE_ADDRS                        { CASPER_BASE }
  /** Array initializer of CASPER peripheral base pointers */
  #define CASPER_BASE_PTRS                         { CASPER }
  /** Array initializer of CASPER peripheral base addresses */
  #define CASPER_BASE_ADDRS_NS                     { CASPER_BASE_NS }
  /** Array initializer of CASPER peripheral base pointers */
  #define CASPER_BASE_PTRS_NS                      { CASPER_NS }
#else
  /** Peripheral CASPER base address */
  #define CASPER_BASE                              (0x28410000u)
  /** Peripheral CASPER base pointer */
  #define CASPER                                   ((CASPER_Type *)CASPER_BASE)
  /** Array initializer of CASPER peripheral base addresses */
  #define CASPER_BASE_ADDRS                        { CASPER_BASE }
  /** Array initializer of CASPER peripheral base pointers */
  #define CASPER_BASE_PTRS                         { CASPER }
#endif
/** Interrupt vectors for the CASPER peripheral type */
#define CASPER_IRQS                              { CASPER_IRQn }

/* CGC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CGC_RTD base address */
  #define CGC_RTD_BASE                             (0x3802F000u)
  /** Peripheral CGC_RTD base address */
  #define CGC_RTD_BASE_NS                          (0x2802F000u)
  /** Peripheral CGC_RTD base pointer */
  #define CGC_RTD                                  ((CGC_Type *)CGC_RTD_BASE)
  /** Peripheral CGC_RTD base pointer */
  #define CGC_RTD_NS                               ((CGC_Type *)CGC_RTD_BASE_NS)
  /** Array initializer of CGC peripheral base addresses */
  #define CGC_BASE_ADDRS                           { CGC_RTD_BASE }
  /** Array initializer of CGC peripheral base pointers */
  #define CGC_BASE_PTRS                            { CGC_RTD }
  /** Array initializer of CGC peripheral base addresses */
  #define CGC_BASE_ADDRS_NS                        { CGC_RTD_BASE_NS }
  /** Array initializer of CGC peripheral base pointers */
  #define CGC_BASE_PTRS_NS                         { CGC_RTD_NS }
#else
  /** Peripheral CGC_RTD base address */
  #define CGC_RTD_BASE                             (0x2802F000u)
  /** Peripheral CGC_RTD base pointer */
  #define CGC_RTD                                  ((CGC_Type *)CGC_RTD_BASE)
  /** Array initializer of CGC peripheral base addresses */
  #define CGC_BASE_ADDRS                           { CGC_RTD_BASE }
  /** Array initializer of CGC peripheral base pointers */
  #define CGC_BASE_PTRS                            { CGC_RTD }
#endif
/** Interrupt vectors for the CGC peripheral type */
#define CGC_IRQS                                 { CGC0_IRQn }

/* CGC_AD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CGC_AD base address */
  #define CGC_AD_BASE                              (0x392C0000u)
  /** Peripheral CGC_AD base address */
  #define CGC_AD_BASE_NS                           (0x292C0000u)
  /** Peripheral CGC_AD base pointer */
  #define CGC_AD                                   ((CGC_AD_Type *)CGC_AD_BASE)
  /** Peripheral CGC_AD base pointer */
  #define CGC_AD_NS                                ((CGC_AD_Type *)CGC_AD_BASE_NS)
  /** Array initializer of CGC_AD peripheral base addresses */
  #define CGC_AD_BASE_ADDRS                        { CGC_AD_BASE }
  /** Array initializer of CGC_AD peripheral base pointers */
  #define CGC_AD_BASE_PTRS                         { CGC_AD }
  /** Array initializer of CGC_AD peripheral base addresses */
  #define CGC_AD_BASE_ADDRS_NS                     { CGC_AD_BASE_NS }
  /** Array initializer of CGC_AD peripheral base pointers */
  #define CGC_AD_BASE_PTRS_NS                      { CGC_AD_NS }
#else
  /** Peripheral CGC_AD base address */
  #define CGC_AD_BASE                              (0x292C0000u)
  /** Peripheral CGC_AD base pointer */
  #define CGC_AD                                   ((CGC_AD_Type *)CGC_AD_BASE)
  /** Array initializer of CGC_AD peripheral base addresses */
  #define CGC_AD_BASE_ADDRS                        { CGC_AD_BASE }
  /** Array initializer of CGC_AD peripheral base pointers */
  #define CGC_AD_BASE_PTRS                         { CGC_AD }
#endif
/** Interrupt vectors for the CGC_AD peripheral type */
#define CGC_AD_IRQS                              { CGC1_IRQn }

/* CGC_LPAV - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CGC_LPAV base address */
  #define CGC_LPAV_BASE                            (0x3DA60000u)
  /** Peripheral CGC_LPAV base address */
  #define CGC_LPAV_BASE_NS                         (0x2DA60000u)
  /** Peripheral CGC_LPAV base pointer */
  #define CGC_LPAV                                 ((CGC_LPAV_Type *)CGC_LPAV_BASE)
  /** Peripheral CGC_LPAV base pointer */
  #define CGC_LPAV_NS                              ((CGC_LPAV_Type *)CGC_LPAV_BASE_NS)
  /** Array initializer of CGC_LPAV peripheral base addresses */
  #define CGC_LPAV_BASE_ADDRS                      { CGC_LPAV_BASE }
  /** Array initializer of CGC_LPAV peripheral base pointers */
  #define CGC_LPAV_BASE_PTRS                       { CGC_LPAV }
  /** Array initializer of CGC_LPAV peripheral base addresses */
  #define CGC_LPAV_BASE_ADDRS_NS                   { CGC_LPAV_BASE_NS }
  /** Array initializer of CGC_LPAV peripheral base pointers */
  #define CGC_LPAV_BASE_PTRS_NS                    { CGC_LPAV_NS }
#else
  /** Peripheral CGC_LPAV base address */
  #define CGC_LPAV_BASE                            (0x2DA60000u)
  /** Peripheral CGC_LPAV base pointer */
  #define CGC_LPAV                                 ((CGC_LPAV_Type *)CGC_LPAV_BASE)
  /** Array initializer of CGC_LPAV peripheral base addresses */
  #define CGC_LPAV_BASE_ADDRS                      { CGC_LPAV_BASE }
  /** Array initializer of CGC_LPAV peripheral base pointers */
  #define CGC_LPAV_BASE_PTRS                       { CGC_LPAV }
#endif
/** Interrupt vectors for the CGC_LPAV peripheral type */
#define CGC_LPAV_IRQS                            { CGC2_IRQn }

/* CMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMC_RTD base address */
  #define CMC_RTD_BASE                             (0x38025000u)
  /** Peripheral CMC_RTD base address */
  #define CMC_RTD_BASE_NS                          (0x28025000u)
  /** Peripheral CMC_RTD base pointer */
  #define CMC_RTD                                  ((CMC_Type *)CMC_RTD_BASE)
  /** Peripheral CMC_RTD base pointer */
  #define CMC_RTD_NS                               ((CMC_Type *)CMC_RTD_BASE_NS)
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS                           { CMC_RTD_BASE }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS                            { CMC_RTD }
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS_NS                        { CMC_RTD_BASE_NS }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS_NS                         { CMC_RTD_NS }
#else
  /** Peripheral CMC_RTD base address */
  #define CMC_RTD_BASE                             (0x28025000u)
  /** Peripheral CMC_RTD base pointer */
  #define CMC_RTD                                  ((CMC_Type *)CMC_RTD_BASE)
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS                           { CMC_RTD_BASE }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS                            { CMC_RTD }
#endif

/* CMC_AD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMC_AD base address */
  #define CMC_AD_BASE                              (0x39240000u)
  /** Peripheral CMC_AD base address */
  #define CMC_AD_BASE_NS                           (0x29240000u)
  /** Peripheral CMC_AD base pointer */
  #define CMC_AD                                   ((CMC_AD_Type *)CMC_AD_BASE)
  /** Peripheral CMC_AD base pointer */
  #define CMC_AD_NS                                ((CMC_AD_Type *)CMC_AD_BASE_NS)
  /** Array initializer of CMC_AD peripheral base addresses */
  #define CMC_AD_BASE_ADDRS                        { CMC_AD_BASE }
  /** Array initializer of CMC_AD peripheral base pointers */
  #define CMC_AD_BASE_PTRS                         { CMC_AD }
  /** Array initializer of CMC_AD peripheral base addresses */
  #define CMC_AD_BASE_ADDRS_NS                     { CMC_AD_BASE_NS }
  /** Array initializer of CMC_AD peripheral base pointers */
  #define CMC_AD_BASE_PTRS_NS                      { CMC_AD_NS }
#else
  /** Peripheral CMC_AD base address */
  #define CMC_AD_BASE                              (0x29240000u)
  /** Peripheral CMC_AD base pointer */
  #define CMC_AD                                   ((CMC_AD_Type *)CMC_AD_BASE)
  /** Array initializer of CMC_AD peripheral base addresses */
  #define CMC_AD_BASE_ADDRS                        { CMC_AD_BASE }
  /** Array initializer of CMC_AD peripheral base pointers */
  #define CMC_AD_BASE_PTRS                         { CMC_AD }
#endif

/* CMC_LPAC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMC_LPAC base address */
  #define CMC_LPAC_BASE                            (0x3DA40000u)
  /** Peripheral CMC_LPAC base address */
  #define CMC_LPAC_BASE_NS                         (0x2DA40000u)
  /** Peripheral CMC_LPAC base pointer */
  #define CMC_LPAC                                 ((CMC_LPAC_Type *)CMC_LPAC_BASE)
  /** Peripheral CMC_LPAC base pointer */
  #define CMC_LPAC_NS                              ((CMC_LPAC_Type *)CMC_LPAC_BASE_NS)
  /** Array initializer of CMC_LPAC peripheral base addresses */
  #define CMC_LPAC_BASE_ADDRS                      { CMC_LPAC_BASE }
  /** Array initializer of CMC_LPAC peripheral base pointers */
  #define CMC_LPAC_BASE_PTRS                       { CMC_LPAC }
  /** Array initializer of CMC_LPAC peripheral base addresses */
  #define CMC_LPAC_BASE_ADDRS_NS                   { CMC_LPAC_BASE_NS }
  /** Array initializer of CMC_LPAC peripheral base pointers */
  #define CMC_LPAC_BASE_PTRS_NS                    { CMC_LPAC_NS }
#else
  /** Peripheral CMC_LPAC base address */
  #define CMC_LPAC_BASE                            (0x2DA40000u)
  /** Peripheral CMC_LPAC base pointer */
  #define CMC_LPAC                                 ((CMC_LPAC_Type *)CMC_LPAC_BASE)
  /** Array initializer of CMC_LPAC peripheral base addresses */
  #define CMC_LPAC_BASE_ADDRS                      { CMC_LPAC_BASE }
  /** Array initializer of CMC_LPAC peripheral base pointers */
  #define CMC_LPAC_BASE_PTRS                       { CMC_LPAC }
#endif

/* CMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMP0 base address */
  #define CMP0_BASE                                (0x38041000u)
  /** Peripheral CMP0 base address */
  #define CMP0_BASE_NS                             (0x28041000u)
  /** Peripheral CMP0 base pointer */
  #define CMP0                                     ((CMP_Type *)CMP0_BASE)
  /** Peripheral CMP0 base pointer */
  #define CMP0_NS                                  ((CMP_Type *)CMP0_BASE_NS)
  /** Peripheral CMP1 base address */
  #define CMP1_BASE                                (0x38042000u)
  /** Peripheral CMP1 base address */
  #define CMP1_BASE_NS                             (0x28042000u)
  /** Peripheral CMP1 base pointer */
  #define CMP1                                     ((CMP_Type *)CMP1_BASE)
  /** Peripheral CMP1 base pointer */
  #define CMP1_NS                                  ((CMP_Type *)CMP1_BASE_NS)
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS                           { CMP0_BASE, CMP1_BASE }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS                            { CMP0, CMP1 }
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS_NS                        { CMP0_BASE_NS, CMP1_BASE_NS }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS_NS                         { CMP0_NS, CMP1_NS }
#else
  /** Peripheral CMP0 base address */
  #define CMP0_BASE                                (0x28041000u)
  /** Peripheral CMP0 base pointer */
  #define CMP0                                     ((CMP_Type *)CMP0_BASE)
  /** Peripheral CMP1 base address */
  #define CMP1_BASE                                (0x28042000u)
  /** Peripheral CMP1 base pointer */
  #define CMP1                                     ((CMP_Type *)CMP1_BASE)
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS                           { CMP0_BASE, CMP1_BASE }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS                            { CMP0, CMP1 }
#endif
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { CMP0_IRQn, CMP1_IRQn }

/* DAC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DAC0 base address */
  #define DAC0_BASE                                (0x38043000u)
  /** Peripheral DAC0 base address */
  #define DAC0_BASE_NS                             (0x28043000u)
  /** Peripheral DAC0 base pointer */
  #define DAC0                                     ((DAC_Type *)DAC0_BASE)
  /** Peripheral DAC0 base pointer */
  #define DAC0_NS                                  ((DAC_Type *)DAC0_BASE_NS)
  /** Peripheral DAC1 base address */
  #define DAC1_BASE                                (0x38044000u)
  /** Peripheral DAC1 base address */
  #define DAC1_BASE_NS                             (0x28044000u)
  /** Peripheral DAC1 base pointer */
  #define DAC1                                     ((DAC_Type *)DAC1_BASE)
  /** Peripheral DAC1 base pointer */
  #define DAC1_NS                                  ((DAC_Type *)DAC1_BASE_NS)
  /** Array initializer of DAC peripheral base addresses */
  #define DAC_BASE_ADDRS                           { DAC0_BASE, DAC1_BASE }
  /** Array initializer of DAC peripheral base pointers */
  #define DAC_BASE_PTRS                            { DAC0, DAC1 }
  /** Array initializer of DAC peripheral base addresses */
  #define DAC_BASE_ADDRS_NS                        { DAC0_BASE_NS, DAC1_BASE_NS }
  /** Array initializer of DAC peripheral base pointers */
  #define DAC_BASE_PTRS_NS                         { DAC0_NS, DAC1_NS }
#else
  /** Peripheral DAC0 base address */
  #define DAC0_BASE                                (0x28043000u)
  /** Peripheral DAC0 base pointer */
  #define DAC0                                     ((DAC_Type *)DAC0_BASE)
  /** Peripheral DAC1 base address */
  #define DAC1_BASE                                (0x28044000u)
  /** Peripheral DAC1 base pointer */
  #define DAC1                                     ((DAC_Type *)DAC1_BASE)
  /** Array initializer of DAC peripheral base addresses */
  #define DAC_BASE_ADDRS                           { DAC0_BASE, DAC1_BASE }
  /** Array initializer of DAC peripheral base pointers */
  #define DAC_BASE_PTRS                            { DAC0, DAC1 }
#endif
/** Interrupt vectors for the DAC peripheral type */
#define DAC_IRQS                                 { DAC0_IRQn, DAC1_IRQn }

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA0 base address */
  #define DMA0_BASE                                (0x38001000u)
  /** Peripheral DMA0 base address */
  #define DMA0_BASE_NS                             (0x28001000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Peripheral DMA0 base pointer */
  #define DMA0_NS                                  ((DMA_Type *)DMA0_BASE_NS)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA0_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA0 }
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS_NS                        { DMA0_BASE_NS }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS_NS                         { DMA0_NS }
#else
  /** Peripheral DMA0 base address */
  #define DMA0_BASE                                (0x28001000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA0_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA0 }
#endif
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { DMA0_0_IRQn, DMA0_1_IRQn, DMA0_2_IRQn, DMA0_3_IRQn, DMA0_4_IRQn, DMA0_5_IRQn, DMA0_6_IRQn, DMA0_7_IRQn, DMA0_8_IRQn, DMA0_9_IRQn, DMA0_10_IRQn, DMA0_11_IRQn, DMA0_12_IRQn, DMA0_13_IRQn, DMA0_14_IRQn, DMA0_15_IRQn, DMA0_16_IRQn, DMA0_17_IRQn, DMA0_18_IRQn, DMA0_19_IRQn, DMA0_20_IRQn, DMA0_21_IRQn, DMA0_22_IRQn, DMA0_23_IRQn, DMA0_24_IRQn, DMA0_25_IRQn, DMA0_26_IRQn, DMA0_27_IRQn, DMA0_28_IRQn, DMA0_29_IRQn, DMA0_30_IRQn, DMA0_31_IRQn } }
#define DMA_ERROR_IRQS                           { { DMA0_0_IRQn, DMA0_1_IRQn, DMA0_2_IRQn, DMA0_3_IRQn, DMA0_4_IRQn, DMA0_5_IRQn, DMA0_6_IRQn, DMA0_7_IRQn, DMA0_8_IRQn, DMA0_9_IRQn, DMA0_10_IRQn, DMA0_11_IRQn, DMA0_12_IRQn, DMA0_13_IRQn, DMA0_14_IRQn, DMA0_15_IRQn, DMA0_16_IRQn, DMA0_17_IRQn, DMA0_18_IRQn, DMA0_19_IRQn, DMA0_20_IRQn, DMA0_21_IRQn, DMA0_22_IRQn, DMA0_23_IRQn, DMA0_24_IRQn, DMA0_25_IRQn, DMA0_26_IRQn, DMA0_27_IRQn, DMA0_28_IRQn, DMA0_29_IRQn, DMA0_30_IRQn, DMA0_31_IRQn } }

/* DMA_AD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA1 base address */
  #define DMA1_BASE                                (0x39010000u)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE_NS                             (0x29010000u)
  /** Peripheral DMA1 base pointer */
  #define DMA1                                     ((DMA_AD_Type *)DMA1_BASE)
  /** Peripheral DMA1 base pointer */
  #define DMA1_NS                                  ((DMA_AD_Type *)DMA1_BASE_NS)
  /** Peripheral DMA2 base address */
  #define DMA2_BASE                                (0x3D800000u)
  /** Peripheral DMA2 base address */
  #define DMA2_BASE_NS                             (0x2D800000u)
  /** Peripheral DMA2 base pointer */
  #define DMA2                                     ((DMA_AD_Type *)DMA2_BASE)
  /** Peripheral DMA2 base pointer */
  #define DMA2_NS                                  ((DMA_AD_Type *)DMA2_BASE_NS)
  /** Array initializer of DMA_AD peripheral base addresses */
  #define DMA_AD_BASE_ADDRS                        { DMA1_BASE, DMA2_BASE }
  /** Array initializer of DMA_AD peripheral base pointers */
  #define DMA_AD_BASE_PTRS                         { DMA1, DMA2 }
  /** Array initializer of DMA_AD peripheral base addresses */
  #define DMA_AD_BASE_ADDRS_NS                     { DMA1_BASE_NS, DMA2_BASE_NS }
  /** Array initializer of DMA_AD peripheral base pointers */
  #define DMA_AD_BASE_PTRS_NS                      { DMA1_NS, DMA2_NS }
#else
  /** Peripheral DMA1 base address */
  #define DMA1_BASE                                (0x29010000u)
  /** Peripheral DMA1 base pointer */
  #define DMA1                                     ((DMA_AD_Type *)DMA1_BASE)
  /** Peripheral DMA2 base address */
  #define DMA2_BASE                                (0x2D800000u)
  /** Peripheral DMA2 base pointer */
  #define DMA2                                     ((DMA_AD_Type *)DMA2_BASE)
  /** Array initializer of DMA_AD peripheral base addresses */
  #define DMA_AD_BASE_ADDRS                        { DMA1_BASE, DMA2_BASE }
  /** Array initializer of DMA_AD peripheral base pointers */
  #define DMA_AD_BASE_PTRS                         { DMA1, DMA2 }
#endif
/** Interrupt vectors for the DMA_AD peripheral type */
#define DMA_AD_IRQS                              { { DMA1_0_IRQn, DMA1_1_IRQn, DMA1_2_IRQn, DMA1_3_IRQn, DMA1_4_IRQn, DMA1_5_IRQn, DMA1_6_IRQn, DMA1_7_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, \
                                                   { DMA2_0_IRQn, DMA2_1_IRQn, DMA2_2_IRQn, DMA2_3_IRQn, DMA2_4_IRQn, DMA2_5_IRQn, DMA2_6_IRQn, DMA2_7_IRQn, DMA2_8_IRQn, DMA2_9_IRQn, DMA2_10_IRQn, DMA2_11_IRQn, DMA2_12_IRQn, DMA2_13_IRQn, DMA2_14_IRQn, DMA2_15_IRQn, DMA2_16_IRQn, DMA2_17_IRQn, DMA2_18_IRQn, DMA2_19_IRQn, DMA2_20_IRQn, DMA2_21_IRQn, DMA2_22_IRQn, DMA2_23_IRQn, DMA2_24_IRQn, DMA2_25_IRQn, DMA2_26_IRQn, DMA2_27_IRQn, DMA2_28_IRQn, DMA2_29_IRQn, DMA2_30_IRQn, DMA2_31_IRQn } }
#define DMA_AD_ERROR_IRQS                        { { DMA1_0_IRQn, DMA1_1_IRQn, DMA1_2_IRQn, DMA1_3_IRQn, DMA1_4_IRQn, DMA1_5_IRQn, DMA1_6_IRQn, DMA1_7_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, \
                                                   { DMA2_0_IRQn, DMA2_1_IRQn, DMA2_2_IRQn, DMA2_3_IRQn, DMA2_4_IRQn, DMA2_5_IRQn, DMA2_6_IRQn, DMA2_7_IRQn, DMA2_8_IRQn, DMA2_9_IRQn, DMA2_10_IRQn, DMA2_11_IRQn, DMA2_12_IRQn, DMA2_13_IRQn, DMA2_14_IRQn, DMA2_15_IRQn, DMA2_16_IRQn, DMA2_17_IRQn, DMA2_18_IRQn, DMA2_19_IRQn, DMA2_20_IRQn, DMA2_21_IRQn, DMA2_22_IRQn, DMA2_23_IRQn, DMA2_24_IRQn, DMA2_25_IRQn, DMA2_26_IRQn, DMA2_27_IRQn, DMA2_28_IRQn, DMA2_29_IRQn, DMA2_30_IRQn, DMA2_31_IRQn } }

/* ENET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENET base address */
  #define ENET_BASE                                (0x39950000u)
  /** Peripheral ENET base address */
  #define ENET_BASE_NS                             (0x29950000u)
  /** Peripheral ENET base pointer */
  #define ENET                                     ((ENET_Type *)ENET_BASE)
  /** Peripheral ENET base pointer */
  #define ENET_NS                                  ((ENET_Type *)ENET_BASE_NS)
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS                          { ENET_BASE }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS                           { ENET }
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS_NS                       { ENET_BASE_NS }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS_NS                        { ENET_NS }
#else
  /** Peripheral ENET base address */
  #define ENET_BASE                                (0x29950000u)
  /** Peripheral ENET base pointer */
  #define ENET                                     ((ENET_Type *)ENET_BASE)
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS                          { ENET_BASE }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS                           { ENET }
#endif

/* EWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EWM0 base address */
  #define EWM0_BASE                                (0x3802E000u)
  /** Peripheral EWM0 base address */
  #define EWM0_BASE_NS                             (0x2802E000u)
  /** Peripheral EWM0 base pointer */
  #define EWM0                                     ((EWM_Type *)EWM0_BASE)
  /** Peripheral EWM0 base pointer */
  #define EWM0_NS                                  ((EWM_Type *)EWM0_BASE_NS)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { EWM0_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { EWM0 }
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS_NS                        { EWM0_BASE_NS }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS_NS                         { EWM0_NS }
#else
  /** Peripheral EWM0 base address */
  #define EWM0_BASE                                (0x2802E000u)
  /** Peripheral EWM0 base pointer */
  #define EWM0                                     ((EWM_Type *)EWM0_BASE)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { EWM0_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { EWM0 }
#endif
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { EWM_IRQn }

/* FLEXIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXIO0 base address */
  #define FLEXIO0_BASE                             (0x3803C000u)
  /** Peripheral FLEXIO0 base address */
  #define FLEXIO0_BASE_NS                          (0x2803C000u)
  /** Peripheral FLEXIO0 base pointer */
  #define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
  /** Peripheral FLEXIO0 base pointer */
  #define FLEXIO0_NS                               ((FLEXIO_Type *)FLEXIO0_BASE_NS)
  /** Peripheral FLEXIO1 base address */
  #define FLEXIO1_BASE                             (0x39350000u)
  /** Peripheral FLEXIO1 base address */
  #define FLEXIO1_BASE_NS                          (0x29350000u)
  /** Peripheral FLEXIO1 base pointer */
  #define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
  /** Peripheral FLEXIO1 base pointer */
  #define FLEXIO1_NS                               ((FLEXIO_Type *)FLEXIO1_BASE_NS)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE, FLEXIO1_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { FLEXIO0, FLEXIO1 }
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS_NS                     { FLEXIO0_BASE_NS, FLEXIO1_BASE_NS }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS_NS                      { FLEXIO0_NS, FLEXIO1_NS }
#else
  /** Peripheral FLEXIO0 base address */
  #define FLEXIO0_BASE                             (0x2803C000u)
  /** Peripheral FLEXIO0 base pointer */
  #define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
  /** Peripheral FLEXIO1 base address */
  #define FLEXIO1_BASE                             (0x29350000u)
  /** Peripheral FLEXIO1 base pointer */
  #define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE, FLEXIO1_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { FLEXIO0, FLEXIO1 }
#endif
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { FLEXIO0_IRQn, FLEXIO1_IRQn }

/* FLEXSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXSPI0 base address */
  #define FLEXSPI0_BASE                            (0x38039000u)
  /** Peripheral FLEXSPI0 base address */
  #define FLEXSPI0_BASE_NS                         (0x28039000u)
  /** Peripheral FLEXSPI0 base pointer */
  #define FLEXSPI0                                 ((FLEXSPI_Type *)FLEXSPI0_BASE)
  /** Peripheral FLEXSPI0 base pointer */
  #define FLEXSPI0_NS                              ((FLEXSPI_Type *)FLEXSPI0_BASE_NS)
  /** Peripheral FLEXSPI1 base address */
  #define FLEXSPI1_BASE                            (0x38092000u)
  /** Peripheral FLEXSPI1 base address */
  #define FLEXSPI1_BASE_NS                         (0x28092000u)
  /** Peripheral FLEXSPI1 base pointer */
  #define FLEXSPI1                                 ((FLEXSPI_Type *)FLEXSPI1_BASE)
  /** Peripheral FLEXSPI1 base pointer */
  #define FLEXSPI1_NS                              ((FLEXSPI_Type *)FLEXSPI1_BASE_NS)
  /** Peripheral FLEXSPI2 base address */
  #define FLEXSPI2_BASE                            (0x39810000u)
  /** Peripheral FLEXSPI2 base address */
  #define FLEXSPI2_BASE_NS                         (0x29810000u)
  /** Peripheral FLEXSPI2 base pointer */
  #define FLEXSPI2                                 ((FLEXSPI_Type *)FLEXSPI2_BASE)
  /** Peripheral FLEXSPI2 base pointer */
  #define FLEXSPI2_NS                              ((FLEXSPI_Type *)FLEXSPI2_BASE_NS)
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS                       { FLEXSPI0_BASE, FLEXSPI1_BASE, FLEXSPI2_BASE }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS                        { FLEXSPI0, FLEXSPI1, FLEXSPI2 }
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS_NS                    { FLEXSPI0_BASE_NS, FLEXSPI1_BASE_NS, FLEXSPI2_BASE_NS }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS_NS                     { FLEXSPI0_NS, FLEXSPI1_NS, FLEXSPI2_NS }
#else
  /** Peripheral FLEXSPI0 base address */
  #define FLEXSPI0_BASE                            (0x28039000u)
  /** Peripheral FLEXSPI0 base pointer */
  #define FLEXSPI0                                 ((FLEXSPI_Type *)FLEXSPI0_BASE)
  /** Peripheral FLEXSPI1 base address */
  #define FLEXSPI1_BASE                            (0x28092000u)
  /** Peripheral FLEXSPI1 base pointer */
  #define FLEXSPI1                                 ((FLEXSPI_Type *)FLEXSPI1_BASE)
  /** Peripheral FLEXSPI2 base address */
  #define FLEXSPI2_BASE                            (0x29810000u)
  /** Peripheral FLEXSPI2 base pointer */
  #define FLEXSPI2                                 ((FLEXSPI_Type *)FLEXSPI2_BASE)
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS                       { FLEXSPI0_BASE, FLEXSPI1_BASE, FLEXSPI2_BASE }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS                        { FLEXSPI0, FLEXSPI1, FLEXSPI2 }
#endif
/** Interrupt vectors for the FLEXSPI peripheral type */
#define FLEXSPI_IRQS                             { FlexSPI0_IRQn, FlexSPI1_IRQn, FlexSPI2_IRQn }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (1)
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** FlexSPI AMBA base address array */
#define FlexSPI_AMBA_BASE_ARRAY                    { {0x14000000u}, {0x50000000u}, {0x70000000u} }
/** FlexSPI AMBA end address array */
#define FlexSPI_AMBA_END_ARRAY                     { {0x1BFFFFFFu}, {0x5FFFFFFFu}, {0x7FFFFFFFu} }
/** FlexSPI AMBA base address array */
#define FlexSPI_AMBA_BASE_ARRAY_NS                 { {0x04000000u}, {0x40000000u}, {0x60000000u} }
/** FlexSPI AMBA end address array */
#define FlexSPI_AMBA_END_ARRAY_NS                  { {0x0BFFFFFFu}, {0x4FFFFFFFu}, {0x6FFFFFFFu} }
/* FlexSPI0 AMBA base address. */
#define FlexSPI0_AMBA_BASE                         (0x14000000u)
/* FlexSPI1 AMBA base address. */
#define FlexSPI1_AMBA_BASE                         (0x50000000u)
/* FlexSPI2 AMBA base address. */
#define FlexSPI2_AMBA_BASE                         (0x70000000u)
#else
/** FlexSPI AMBA base address array */
#define FlexSPI_AMBA_BASE_ARRAY                    { {0x04000000u}, {0x40000000u}, {0x60000000u} }
/** FlexSPI AMBA end address array */
#define FlexSPI_AMBA_END_ARRAY                     { {0x0BFFFFFFu}, {0x4FFFFFFFu}, {0x6FFFFFFFu} }
/* FlexSPI0 AMBA base address. */
#define FlexSPI0_AMBA_BASE                         (0x04000000u)
/* FlexSPI1 AMBA base address. */
#define FlexSPI1_AMBA_BASE                         (0x40000000u)
/* FlexSPI2 AMBA base address. */
#define FlexSPI2_AMBA_BASE                         (0x60000000u)
#endif


/* I2S - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SAI0 base address */
  #define SAI0_BASE                                (0x3809C000u)
  /** Peripheral SAI0 base address */
  #define SAI0_BASE_NS                             (0x2809C000u)
  /** Peripheral SAI0 base pointer */
  #define SAI0                                     ((I2S_Type *)SAI0_BASE)
  /** Peripheral SAI0 base pointer */
  #define SAI0_NS                                  ((I2S_Type *)SAI0_BASE_NS)
  /** Peripheral SAI1 base address */
  #define SAI1_BASE                                (0x3809D000u)
  /** Peripheral SAI1 base address */
  #define SAI1_BASE_NS                             (0x2809D000u)
  /** Peripheral SAI1 base pointer */
  #define SAI1                                     ((I2S_Type *)SAI1_BASE)
  /** Peripheral SAI1 base pointer */
  #define SAI1_NS                                  ((I2S_Type *)SAI1_BASE_NS)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE                                (0x3810F000u)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE_NS                             (0x2810F000u)
  /** Peripheral SAI2 base pointer */
  #define SAI2                                     ((I2S_Type *)SAI2_BASE)
  /** Peripheral SAI2 base pointer */
  #define SAI2_NS                                  ((I2S_Type *)SAI2_BASE_NS)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE                                (0x38110000u)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE_NS                             (0x28110000u)
  /** Peripheral SAI3 base pointer */
  #define SAI3                                     ((I2S_Type *)SAI3_BASE)
  /** Peripheral SAI3 base pointer */
  #define SAI3_NS                                  ((I2S_Type *)SAI3_BASE_NS)
  /** Peripheral SAI4 base address */
  #define SAI4_BASE                                (0x39880000u)
  /** Peripheral SAI4 base address */
  #define SAI4_BASE_NS                             (0x29880000u)
  /** Peripheral SAI4 base pointer */
  #define SAI4                                     ((I2S_Type *)SAI4_BASE)
  /** Peripheral SAI4 base pointer */
  #define SAI4_NS                                  ((I2S_Type *)SAI4_BASE_NS)
  /** Peripheral SAI5 base address */
  #define SAI5_BASE                                (0x39890000u)
  /** Peripheral SAI5 base address */
  #define SAI5_BASE_NS                             (0x29890000u)
  /** Peripheral SAI5 base pointer */
  #define SAI5                                     ((I2S_Type *)SAI5_BASE)
  /** Peripheral SAI5 base pointer */
  #define SAI5_NS                                  ((I2S_Type *)SAI5_BASE_NS)
  /** Peripheral SAI6 base address */
  #define SAI6_BASE                                (0x3DA90000u)
  /** Peripheral SAI6 base address */
  #define SAI6_BASE_NS                             (0x2DA90000u)
  /** Peripheral SAI6 base pointer */
  #define SAI6                                     ((I2S_Type *)SAI6_BASE)
  /** Peripheral SAI6 base pointer */
  #define SAI6_NS                                  ((I2S_Type *)SAI6_BASE_NS)
  /** Peripheral SAI7 base address */
  #define SAI7_BASE                                (0x3DAA0000u)
  /** Peripheral SAI7 base address */
  #define SAI7_BASE_NS                             (0x2DAA0000u)
  /** Peripheral SAI7 base pointer */
  #define SAI7                                     ((I2S_Type *)SAI7_BASE)
  /** Peripheral SAI7 base pointer */
  #define SAI7_NS                                  ((I2S_Type *)SAI7_BASE_NS)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { SAI0_BASE, SAI1_BASE, SAI2_BASE, SAI3_BASE, SAI4_BASE, SAI5_BASE, SAI6_BASE, SAI7_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { SAI0, SAI1, SAI2, SAI3, SAI4, SAI5, SAI6, SAI7 }
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS_NS                        { SAI0_BASE_NS, SAI1_BASE_NS, SAI2_BASE_NS, SAI3_BASE_NS, SAI4_BASE_NS, SAI5_BASE_NS, SAI6_BASE_NS, SAI7_BASE_NS }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS_NS                         { SAI0_NS, SAI1_NS, SAI2_NS, SAI3_NS, SAI4_NS, SAI5_NS, SAI6_NS, SAI7_NS }
#else
  /** Peripheral SAI0 base address */
  #define SAI0_BASE                                (0x2809C000u)
  /** Peripheral SAI0 base pointer */
  #define SAI0                                     ((I2S_Type *)SAI0_BASE)
  /** Peripheral SAI1 base address */
  #define SAI1_BASE                                (0x2809D000u)
  /** Peripheral SAI1 base pointer */
  #define SAI1                                     ((I2S_Type *)SAI1_BASE)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE                                (0x2810F000u)
  /** Peripheral SAI2 base pointer */
  #define SAI2                                     ((I2S_Type *)SAI2_BASE)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE                                (0x28110000u)
  /** Peripheral SAI3 base pointer */
  #define SAI3                                     ((I2S_Type *)SAI3_BASE)
  /** Peripheral SAI4 base address */
  #define SAI4_BASE                                (0x29880000u)
  /** Peripheral SAI4 base pointer */
  #define SAI4                                     ((I2S_Type *)SAI4_BASE)
  /** Peripheral SAI5 base address */
  #define SAI5_BASE                                (0x29890000u)
  /** Peripheral SAI5 base pointer */
  #define SAI5                                     ((I2S_Type *)SAI5_BASE)
  /** Peripheral SAI6 base address */
  #define SAI6_BASE                                (0x2DA90000u)
  /** Peripheral SAI6 base pointer */
  #define SAI6                                     ((I2S_Type *)SAI6_BASE)
  /** Peripheral SAI7 base address */
  #define SAI7_BASE                                (0x2DAA0000u)
  /** Peripheral SAI7 base pointer */
  #define SAI7                                     ((I2S_Type *)SAI7_BASE)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { SAI0_BASE, SAI1_BASE, SAI2_BASE, SAI3_BASE, SAI4_BASE, SAI5_BASE, SAI6_BASE, SAI7_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { SAI0, SAI1, SAI2, SAI3, SAI4, SAI5, SAI6, SAI7 }
#endif
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { SAI0_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn, NotAvail_IRQn, NotAvail_IRQn, SAI6_IRQn, SAI7_IRQn }
#define I2S_TX_IRQS                              { SAI0_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn, NotAvail_IRQn, NotAvail_IRQn, SAI6_IRQn, SAI7_IRQn }

/* I3C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I3C0 base address */
  #define I3C0_BASE                                (0x3803D000u)
  /** Peripheral I3C0 base address */
  #define I3C0_BASE_NS                             (0x2803D000u)
  /** Peripheral I3C0 base pointer */
  #define I3C0                                     ((I3C_Type *)I3C0_BASE)
  /** Peripheral I3C0 base pointer */
  #define I3C0_NS                                  ((I3C_Type *)I3C0_BASE_NS)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x3810A000u)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE_NS                             (0x2810A000u)
  /** Peripheral I3C1 base pointer */
  #define I3C1                                     ((I3C_Type *)I3C1_BASE)
  /** Peripheral I3C1 base pointer */
  #define I3C1_NS                                  ((I3C_Type *)I3C1_BASE_NS)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE                                (0x39360000u)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE_NS                             (0x29360000u)
  /** Peripheral I3C2 base pointer */
  #define I3C2                                     ((I3C_Type *)I3C2_BASE)
  /** Peripheral I3C2 base pointer */
  #define I3C2_NS                                  ((I3C_Type *)I3C2_BASE_NS)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { I3C0_BASE, I3C1_BASE, I3C2_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { I3C0, I3C1, I3C2 }
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS_NS                        { I3C0_BASE_NS, I3C1_BASE_NS, I3C2_BASE_NS }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS_NS                         { I3C0_NS, I3C1_NS, I3C2_NS }
#else
  /** Peripheral I3C0 base address */
  #define I3C0_BASE                                (0x2803D000u)
  /** Peripheral I3C0 base pointer */
  #define I3C0                                     ((I3C_Type *)I3C0_BASE)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x2810A000u)
  /** Peripheral I3C1 base pointer */
  #define I3C1                                     ((I3C_Type *)I3C1_BASE)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE                                (0x29360000u)
  /** Peripheral I3C2 base pointer */
  #define I3C2                                     ((I3C_Type *)I3C2_BASE)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { I3C0_BASE, I3C1_BASE, I3C2_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { I3C0, I3C1, I3C2 }
#endif
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { I3C0_IRQn, I3C1_IRQn, NotAvail_IRQn }

/* IOMUXC0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOMUXC0 base address */
  #define IOMUXC0_BASE                             (0x380A1000u)
  /** Peripheral IOMUXC0 base address */
  #define IOMUXC0_BASE_NS                          (0x280A1000u)
  /** Peripheral IOMUXC0 base pointer */
  #define IOMUXC0                                  ((IOMUXC0_Type *)IOMUXC0_BASE)
  /** Peripheral IOMUXC0 base pointer */
  #define IOMUXC0_NS                               ((IOMUXC0_Type *)IOMUXC0_BASE_NS)
  /** Array initializer of IOMUXC0 peripheral base addresses */
  #define IOMUXC0_BASE_ADDRS                       { IOMUXC0_BASE }
  /** Array initializer of IOMUXC0 peripheral base pointers */
  #define IOMUXC0_BASE_PTRS                        { IOMUXC0 }
  /** Array initializer of IOMUXC0 peripheral base addresses */
  #define IOMUXC0_BASE_ADDRS_NS                    { IOMUXC0_BASE_NS }
  /** Array initializer of IOMUXC0 peripheral base pointers */
  #define IOMUXC0_BASE_PTRS_NS                     { IOMUXC0_NS }
#else
  /** Peripheral IOMUXC0 base address */
  #define IOMUXC0_BASE                             (0x280A1000u)
  /** Peripheral IOMUXC0 base pointer */
  #define IOMUXC0                                  ((IOMUXC0_Type *)IOMUXC0_BASE)
  /** Array initializer of IOMUXC0 peripheral base addresses */
  #define IOMUXC0_BASE_ADDRS                       { IOMUXC0_BASE }
  /** Array initializer of IOMUXC0 peripheral base pointers */
  #define IOMUXC0_BASE_PTRS                        { IOMUXC0 }
#endif

/* IOMUXC1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOMUXC1 base address */
  #define IOMUXC1_BASE                             (0x398C0000u)
  /** Peripheral IOMUXC1 base address */
  #define IOMUXC1_BASE_NS                          (0x298C0000u)
  /** Peripheral IOMUXC1 base pointer */
  #define IOMUXC1                                  ((IOMUXC1_Type *)IOMUXC1_BASE)
  /** Peripheral IOMUXC1 base pointer */
  #define IOMUXC1_NS                               ((IOMUXC1_Type *)IOMUXC1_BASE_NS)
  /** Array initializer of IOMUXC1 peripheral base addresses */
  #define IOMUXC1_BASE_ADDRS                       { IOMUXC1_BASE }
  /** Array initializer of IOMUXC1 peripheral base pointers */
  #define IOMUXC1_BASE_PTRS                        { IOMUXC1 }
  /** Array initializer of IOMUXC1 peripheral base addresses */
  #define IOMUXC1_BASE_ADDRS_NS                    { IOMUXC1_BASE_NS }
  /** Array initializer of IOMUXC1 peripheral base pointers */
  #define IOMUXC1_BASE_PTRS_NS                     { IOMUXC1_NS }
#else
  /** Peripheral IOMUXC1 base address */
  #define IOMUXC1_BASE                             (0x298C0000u)
  /** Peripheral IOMUXC1 base pointer */
  #define IOMUXC1                                  ((IOMUXC1_Type *)IOMUXC1_BASE)
  /** Array initializer of IOMUXC1 peripheral base addresses */
  #define IOMUXC1_BASE_ADDRS                       { IOMUXC1_BASE }
  /** Array initializer of IOMUXC1 peripheral base pointers */
  #define IOMUXC1_BASE_PTRS                        { IOMUXC1 }
#endif

/* ISI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ISI0 base address */
  #define ISI0_BASE                                (0x3DAC0000u)
  /** Peripheral ISI0 base address */
  #define ISI0_BASE_NS                             (0x2DAC0000u)
  /** Peripheral ISI0 base pointer */
  #define ISI0                                     ((ISI_Type *)ISI0_BASE)
  /** Peripheral ISI0 base pointer */
  #define ISI0_NS                                  ((ISI_Type *)ISI0_BASE_NS)
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS                           { ISI0_BASE }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS                            { ISI0 }
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS_NS                        { ISI0_BASE_NS }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS_NS                         { ISI0_NS }
#else
  /** Peripheral ISI0 base address */
  #define ISI0_BASE                                (0x2DAC0000u)
  /** Peripheral ISI0 base pointer */
  #define ISI0                                     ((ISI_Type *)ISI0_BASE)
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS                           { ISI0_BASE }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS                            { ISI0 }
#endif

/* LCDIF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LCDIF base address */
  #define LCDIF_BASE                               (0x3E050000u)
  /** Peripheral LCDIF base address */
  #define LCDIF_BASE_NS                            (0x2E050000u)
  /** Peripheral LCDIF base pointer */
  #define LCDIF                                    ((LCDIF_Type *)LCDIF_BASE)
  /** Peripheral LCDIF base pointer */
  #define LCDIF_NS                                 ((LCDIF_Type *)LCDIF_BASE_NS)
  /** Array initializer of LCDIF peripheral base addresses */
  #define LCDIF_BASE_ADDRS                         { LCDIF_BASE }
  /** Array initializer of LCDIF peripheral base pointers */
  #define LCDIF_BASE_PTRS                          { LCDIF }
  /** Array initializer of LCDIF peripheral base addresses */
  #define LCDIF_BASE_ADDRS_NS                      { LCDIF_BASE_NS }
  /** Array initializer of LCDIF peripheral base pointers */
  #define LCDIF_BASE_PTRS_NS                       { LCDIF_NS }
#else
  /** Peripheral LCDIF base address */
  #define LCDIF_BASE                               (0x2E050000u)
  /** Peripheral LCDIF base pointer */
  #define LCDIF                                    ((LCDIF_Type *)LCDIF_BASE)
  /** Array initializer of LCDIF peripheral base addresses */
  #define LCDIF_BASE_ADDRS                         { LCDIF_BASE }
  /** Array initializer of LCDIF peripheral base pointers */
  #define LCDIF_BASE_PTRS                          { LCDIF }
#endif
/** Interrupt vectors for the LCDIF peripheral type */
#define LCDIF_IRQS                               { DCNano_IRQn }

/* LPDDR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPDDR base address */
  #define LPDDR_BASE                               (0x3E060000u)
  /** Peripheral LPDDR base address */
  #define LPDDR_BASE_NS                            (0x2E060000u)
  /** Peripheral LPDDR base pointer */
  #define LPDDR                                    ((LPDDR_Type *)LPDDR_BASE)
  /** Peripheral LPDDR base pointer */
  #define LPDDR_NS                                 ((LPDDR_Type *)LPDDR_BASE_NS)
  /** Array initializer of LPDDR peripheral base addresses */
  #define LPDDR_BASE_ADDRS                         { LPDDR_BASE }
  /** Array initializer of LPDDR peripheral base pointers */
  #define LPDDR_BASE_PTRS                          { LPDDR }
  /** Array initializer of LPDDR peripheral base addresses */
  #define LPDDR_BASE_ADDRS_NS                      { LPDDR_BASE_NS }
  /** Array initializer of LPDDR peripheral base pointers */
  #define LPDDR_BASE_PTRS_NS                       { LPDDR_NS }
#else
  /** Peripheral LPDDR base address */
  #define LPDDR_BASE                               (0x2E060000u)
  /** Peripheral LPDDR base pointer */
  #define LPDDR                                    ((LPDDR_Type *)LPDDR_BASE)
  /** Array initializer of LPDDR peripheral base addresses */
  #define LPDDR_BASE_ADDRS                         { LPDDR_BASE }
  /** Array initializer of LPDDR peripheral base pointers */
  #define LPDDR_BASE_PTRS                          { LPDDR }
#endif

/* LPI2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE                              (0x38098000u)
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE_NS                           (0x28098000u)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0_NS                                ((LPI2C_Type *)LPI2C0_BASE_NS)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x38099000u)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE_NS                           (0x28099000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1_NS                                ((LPI2C_Type *)LPI2C1_BASE_NS)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE                              (0x38108000u)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE_NS                           (0x28108000u)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2_NS                                ((LPI2C_Type *)LPI2C2_BASE_NS)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE                              (0x38109000u)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE_NS                           (0x28109000u)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3_NS                                ((LPI2C_Type *)LPI2C3_BASE_NS)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE                              (0x39370000u)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE_NS                           (0x29370000u)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4_NS                                ((LPI2C_Type *)LPI2C4_BASE_NS)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE                              (0x39380000u)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE_NS                           (0x29380000u)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5_NS                                ((LPI2C_Type *)LPI2C5_BASE_NS)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE                              (0x39840000u)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE_NS                           (0x29840000u)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6_NS                                ((LPI2C_Type *)LPI2C6_BASE_NS)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE                              (0x39850000u)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE_NS                           (0x29850000u)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7_NS                                ((LPI2C_Type *)LPI2C7_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { LPI2C0_BASE_NS, LPI2C1_BASE_NS, LPI2C2_BASE_NS, LPI2C3_BASE_NS, LPI2C4_BASE_NS, LPI2C5_BASE_NS, LPI2C6_BASE_NS, LPI2C7_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { LPI2C0_NS, LPI2C1_NS, LPI2C2_NS, LPI2C3_NS, LPI2C4_NS, LPI2C5_NS, LPI2C6_NS, LPI2C7_NS }
#else
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE                              (0x28098000u)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x28099000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE                              (0x28108000u)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE                              (0x28109000u)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE                              (0x29370000u)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE                              (0x29380000u)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE                              (0x29840000u)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE                              (0x29850000u)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* LPIT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPIT0 base address */
  #define LPIT0_BASE                               (0x3803B000u)
  /** Peripheral LPIT0 base address */
  #define LPIT0_BASE_NS                            (0x2803B000u)
  /** Peripheral LPIT0 base pointer */
  #define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
  /** Peripheral LPIT0 base pointer */
  #define LPIT0_NS                                 ((LPIT_Type *)LPIT0_BASE_NS)
  /** Peripheral LPIT1 base address */
  #define LPIT1_BASE                               (0x39320000u)
  /** Peripheral LPIT1 base address */
  #define LPIT1_BASE_NS                            (0x29320000u)
  /** Peripheral LPIT1 base pointer */
  #define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
  /** Peripheral LPIT1 base pointer */
  #define LPIT1_NS                                 ((LPIT_Type *)LPIT1_BASE_NS)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { LPIT0_BASE, LPIT1_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { LPIT0, LPIT1 }
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS_NS                       { LPIT0_BASE_NS, LPIT1_BASE_NS }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS_NS                        { LPIT0_NS, LPIT1_NS }
#else
  /** Peripheral LPIT0 base address */
  #define LPIT0_BASE                               (0x2803B000u)
  /** Peripheral LPIT0 base pointer */
  #define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
  /** Peripheral LPIT1 base address */
  #define LPIT1_BASE                               (0x29320000u)
  /** Peripheral LPIT1 base pointer */
  #define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { LPIT0_BASE, LPIT1_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { LPIT0, LPIT1 }
#endif
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { { LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn }, { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn } }

/* LPSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE                              (0x3803E000u)
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE_NS                           (0x2803E000u)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0_NS                                ((LPSPI_Type *)LPSPI0_BASE_NS)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x3803F000u)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE_NS                           (0x2803F000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1_NS                                ((LPSPI_Type *)LPSPI1_BASE_NS)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE                              (0x3810D000u)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE_NS                           (0x2810D000u)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2_NS                                ((LPSPI_Type *)LPSPI2_BASE_NS)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE                              (0x3810E000u)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE_NS                           (0x2810E000u)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3_NS                                ((LPSPI_Type *)LPSPI3_BASE_NS)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE                              (0x393B0000u)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE_NS                           (0x293B0000u)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4_NS                                ((LPSPI_Type *)LPSPI4_BASE_NS)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE                              (0x393C0000u)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE_NS                           (0x293C0000u)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5_NS                                ((LPSPI_Type *)LPSPI5_BASE_NS)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5 }
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS_NS                      { LPSPI0_BASE_NS, LPSPI1_BASE_NS, LPSPI2_BASE_NS, LPSPI3_BASE_NS, LPSPI4_BASE_NS, LPSPI5_BASE_NS }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS_NS                       { LPSPI0_NS, LPSPI1_NS, LPSPI2_NS, LPSPI3_NS, LPSPI4_NS, LPSPI5_NS }
#else
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE                              (0x2803E000u)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x2803F000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE                              (0x2810D000u)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE                              (0x2810E000u)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE                              (0x293B0000u)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE                              (0x293C0000u)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5 }
#endif
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* LPTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPTMR0 base address */
  #define LPTMR0_BASE                              (0x38093000u)
  /** Peripheral LPTMR0 base address */
  #define LPTMR0_BASE_NS                           (0x28093000u)
  /** Peripheral LPTMR0 base pointer */
  #define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
  /** Peripheral LPTMR0 base pointer */
  #define LPTMR0_NS                                ((LPTMR_Type *)LPTMR0_BASE_NS)
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE                              (0x38094000u)
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE_NS                           (0x28094000u)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1_NS                                ((LPTMR_Type *)LPTMR1_BASE_NS)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { LPTMR0_BASE, LPTMR1_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { LPTMR0, LPTMR1 }
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS_NS                      { LPTMR0_BASE_NS, LPTMR1_BASE_NS }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS_NS                       { LPTMR0_NS, LPTMR1_NS }
#else
  /** Peripheral LPTMR0 base address */
  #define LPTMR0_BASE                              (0x28093000u)
  /** Peripheral LPTMR0 base pointer */
  #define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE                              (0x28094000u)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { LPTMR0_BASE, LPTMR1_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { LPTMR0, LPTMR1 }
#endif
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn, LPTMR1_IRQn }

/* LPUART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE                             (0x3809A000u)
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE_NS                          (0x2809A000u)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0_NS                               ((LPUART_Type *)LPUART0_BASE_NS)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x3809B000u)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE_NS                          (0x2809B000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1_NS                               ((LPUART_Type *)LPUART1_BASE_NS)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE                             (0x3810B000u)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE_NS                          (0x2810B000u)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2_NS                               ((LPUART_Type *)LPUART2_BASE_NS)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE                             (0x3810C000u)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE_NS                          (0x2810C000u)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3_NS                               ((LPUART_Type *)LPUART3_BASE_NS)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE                             (0x39390000u)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE_NS                          (0x29390000u)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4_NS                               ((LPUART_Type *)LPUART4_BASE_NS)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE                             (0x393A0000u)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE_NS                          (0x293A0000u)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5_NS                               ((LPUART_Type *)LPUART5_BASE_NS)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE                             (0x39860000u)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE_NS                          (0x29860000u)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6_NS                               ((LPUART_Type *)LPUART6_BASE_NS)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE                             (0x39870000u)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE_NS                          (0x29870000u)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7_NS                               ((LPUART_Type *)LPUART7_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { LPUART0_BASE_NS, LPUART1_BASE_NS, LPUART2_BASE_NS, LPUART3_BASE_NS, LPUART4_BASE_NS, LPUART5_BASE_NS, LPUART6_BASE_NS, LPUART7_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { LPUART0_NS, LPUART1_NS, LPUART2_NS, LPUART3_NS, LPUART4_NS, LPUART5_NS, LPUART6_NS, LPUART7_NS }
#else
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE                             (0x2809A000u)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x2809B000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE                             (0x2810B000u)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE                             (0x2810C000u)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE                             (0x29390000u)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE                             (0x293A0000u)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE                             (0x29860000u)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE                             (0x29870000u)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MCM base address */
  #define MCM_BASE                                 (0xF0080000u)
  /** Peripheral MCM base address */
  #define MCM_BASE_NS                              (0xE0080000u)
  /** Peripheral MCM base pointer */
  #define MCM                                      ((MCM_Type *)MCM_BASE)
  /** Peripheral MCM base pointer */
  #define MCM_NS                                   ((MCM_Type *)MCM_BASE_NS)
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS                           { MCM_BASE }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS                            { MCM }
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS_NS                        { MCM_BASE_NS }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS_NS                         { MCM_NS }
#else
  /** Peripheral MCM base address */
  #define MCM_BASE                                 (0xE0080000u)
  /** Peripheral MCM base pointer */
  #define MCM                                      ((MCM_Type *)MCM_BASE)
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS                           { MCM_BASE }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS                            { MCM }
#endif

/* MIPI_CSI2RX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MIPI_CSI2RX base address */
  #define MIPI_CSI2RX_BASE                         (0x3DAD0000u)
  /** Peripheral MIPI_CSI2RX base address */
  #define MIPI_CSI2RX_BASE_NS                      (0x2DAD0000u)
  /** Peripheral MIPI_CSI2RX base pointer */
  #define MIPI_CSI2RX                              ((MIPI_CSI2RX_Type *)MIPI_CSI2RX_BASE)
  /** Peripheral MIPI_CSI2RX base pointer */
  #define MIPI_CSI2RX_NS                           ((MIPI_CSI2RX_Type *)MIPI_CSI2RX_BASE_NS)
  /** Array initializer of MIPI_CSI2RX peripheral base addresses */
  #define MIPI_CSI2RX_BASE_ADDRS                   { MIPI_CSI2RX_BASE }
  /** Array initializer of MIPI_CSI2RX peripheral base pointers */
  #define MIPI_CSI2RX_BASE_PTRS                    { MIPI_CSI2RX }
  /** Array initializer of MIPI_CSI2RX peripheral base addresses */
  #define MIPI_CSI2RX_BASE_ADDRS_NS                { MIPI_CSI2RX_BASE_NS }
  /** Array initializer of MIPI_CSI2RX peripheral base pointers */
  #define MIPI_CSI2RX_BASE_PTRS_NS                 { MIPI_CSI2RX_NS }
#else
  /** Peripheral MIPI_CSI2RX base address */
  #define MIPI_CSI2RX_BASE                         (0x2DAD0000u)
  /** Peripheral MIPI_CSI2RX base pointer */
  #define MIPI_CSI2RX                              ((MIPI_CSI2RX_Type *)MIPI_CSI2RX_BASE)
  /** Array initializer of MIPI_CSI2RX peripheral base addresses */
  #define MIPI_CSI2RX_BASE_ADDRS                   { MIPI_CSI2RX_BASE }
  /** Array initializer of MIPI_CSI2RX peripheral base pointers */
  #define MIPI_CSI2RX_BASE_PTRS                    { MIPI_CSI2RX }
#endif

/* MIPI_CSI_CSR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MIPI_CSI_CSR base address */
  #define MIPI_CSI_CSR_BASE                        (0x3DAF0000u)
  /** Peripheral MIPI_CSI_CSR base address */
  #define MIPI_CSI_CSR_BASE_NS                     (0x2DAF0000u)
  /** Peripheral MIPI_CSI_CSR base pointer */
  #define MIPI_CSI_CSR                             ((MIPI_CSI_CSR_Type *)MIPI_CSI_CSR_BASE)
  /** Peripheral MIPI_CSI_CSR base pointer */
  #define MIPI_CSI_CSR_NS                          ((MIPI_CSI_CSR_Type *)MIPI_CSI_CSR_BASE_NS)
  /** Array initializer of MIPI_CSI_CSR peripheral base addresses */
  #define MIPI_CSI_CSR_BASE_ADDRS                  { MIPI_CSI_CSR_BASE }
  /** Array initializer of MIPI_CSI_CSR peripheral base pointers */
  #define MIPI_CSI_CSR_BASE_PTRS                   { MIPI_CSI_CSR }
  /** Array initializer of MIPI_CSI_CSR peripheral base addresses */
  #define MIPI_CSI_CSR_BASE_ADDRS_NS               { MIPI_CSI_CSR_BASE_NS }
  /** Array initializer of MIPI_CSI_CSR peripheral base pointers */
  #define MIPI_CSI_CSR_BASE_PTRS_NS                { MIPI_CSI_CSR_NS }
#else
  /** Peripheral MIPI_CSI_CSR base address */
  #define MIPI_CSI_CSR_BASE                        (0x2DAF0000u)
  /** Peripheral MIPI_CSI_CSR base pointer */
  #define MIPI_CSI_CSR                             ((MIPI_CSI_CSR_Type *)MIPI_CSI_CSR_BASE)
  /** Array initializer of MIPI_CSI_CSR peripheral base addresses */
  #define MIPI_CSI_CSR_BASE_ADDRS                  { MIPI_CSI_CSR_BASE }
  /** Array initializer of MIPI_CSI_CSR peripheral base pointers */
  #define MIPI_CSI_CSR_BASE_PTRS                   { MIPI_CSI_CSR }
#endif

/* MIPI_DSI_HOST - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MIPI_DSI base address */
  #define MIPI_DSI_BASE                            (0x3DB00000u)
  /** Peripheral MIPI_DSI base address */
  #define MIPI_DSI_BASE_NS                         (0x2DB00000u)
  /** Peripheral MIPI_DSI base pointer */
  #define MIPI_DSI                                 ((MIPI_DSI_HOST_Type *)MIPI_DSI_BASE)
  /** Peripheral MIPI_DSI base pointer */
  #define MIPI_DSI_NS                              ((MIPI_DSI_HOST_Type *)MIPI_DSI_BASE_NS)
  /** Array initializer of MIPI_DSI_HOST peripheral base addresses */
  #define MIPI_DSI_HOST_BASE_ADDRS                 { MIPI_DSI_BASE }
  /** Array initializer of MIPI_DSI_HOST peripheral base pointers */
  #define MIPI_DSI_HOST_BASE_PTRS                  { MIPI_DSI }
  /** Array initializer of MIPI_DSI_HOST peripheral base addresses */
  #define MIPI_DSI_HOST_BASE_ADDRS_NS              { MIPI_DSI_BASE_NS }
  /** Array initializer of MIPI_DSI_HOST peripheral base pointers */
  #define MIPI_DSI_HOST_BASE_PTRS_NS               { MIPI_DSI_NS }
#else
  /** Peripheral MIPI_DSI base address */
  #define MIPI_DSI_BASE                            (0x2DB00000u)
  /** Peripheral MIPI_DSI base pointer */
  #define MIPI_DSI                                 ((MIPI_DSI_HOST_Type *)MIPI_DSI_BASE)
  /** Array initializer of MIPI_DSI_HOST peripheral base addresses */
  #define MIPI_DSI_HOST_BASE_ADDRS                 { MIPI_DSI_BASE }
  /** Array initializer of MIPI_DSI_HOST peripheral base pointers */
  #define MIPI_DSI_HOST_BASE_PTRS                  { MIPI_DSI }
#endif

/* MRT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MRT0 base address */
  #define MRT0_BASE                                (0x38107000u)
  /** Peripheral MRT0 base address */
  #define MRT0_BASE_NS                             (0x28107000u)
  /** Peripheral MRT0 base pointer */
  #define MRT0                                     ((MRT_Type *)MRT0_BASE)
  /** Peripheral MRT0 base pointer */
  #define MRT0_NS                                  ((MRT_Type *)MRT0_BASE_NS)
  /** Array initializer of MRT peripheral base addresses */
  #define MRT_BASE_ADDRS                           { MRT0_BASE }
  /** Array initializer of MRT peripheral base pointers */
  #define MRT_BASE_PTRS                            { MRT0 }
  /** Array initializer of MRT peripheral base addresses */
  #define MRT_BASE_ADDRS_NS                        { MRT0_BASE_NS }
  /** Array initializer of MRT peripheral base pointers */
  #define MRT_BASE_PTRS_NS                         { MRT0_NS }
#else
  /** Peripheral MRT0 base address */
  #define MRT0_BASE                                (0x28107000u)
  /** Peripheral MRT0 base pointer */
  #define MRT0                                     ((MRT_Type *)MRT0_BASE)
  /** Array initializer of MRT peripheral base addresses */
  #define MRT_BASE_ADDRS                           { MRT0_BASE }
  /** Array initializer of MRT peripheral base pointers */
  #define MRT_BASE_PTRS                            { MRT0 }
#endif
/** Interrupt vectors for the MRT peripheral type */
#define MRT_IRQS                                 { MRT0_IRQn }

/* MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MU0_MUA base address */
  #define MU0_MUA_BASE                             (0x38022000u)
  /** Peripheral MU0_MUA base address */
  #define MU0_MUA_BASE_NS                          (0x28022000u)
  /** Peripheral MU0_MUA base pointer */
  #define MU0_MUA                                  ((MU_Type *)MU0_MUA_BASE)
  /** Peripheral MU0_MUA base pointer */
  #define MU0_MUA_NS                               ((MU_Type *)MU0_MUA_BASE_NS)
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE                             (0x38023000u)
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE_NS                          (0x28023000u)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA_NS                               ((MU_Type *)MU1_MUA_BASE_NS)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE                             (0x38024000u)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE_NS                          (0x28024000u)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA                                  ((MU_Type *)MU2_MUA_BASE)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA_NS                               ((MU_Type *)MU2_MUA_BASE_NS)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU0_MUA_BASE, MU1_MUA_BASE, MU2_MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU0_MUA, MU1_MUA, MU2_MUA }
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS_NS                         { MU0_MUA_BASE_NS, MU1_MUA_BASE_NS, MU2_MUA_BASE_NS }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS_NS                          { MU0_MUA_NS, MU1_MUA_NS, MU2_MUA_NS }
#else
  /** Peripheral MU0_MUA base address */
  #define MU0_MUA_BASE                             (0x28022000u)
  /** Peripheral MU0_MUA base pointer */
  #define MU0_MUA                                  ((MU_Type *)MU0_MUA_BASE)
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE                             (0x28023000u)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE                             (0x28024000u)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA                                  ((MU_Type *)MU2_MUA_BASE)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU0_MUA_BASE, MU1_MUA_BASE, MU2_MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU0_MUA, MU1_MUA, MU2_MUA }
#endif
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU0_A_IRQn, MU1_A_IRQn, MU2_A_IRQn }

/* MU_RTD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SENTINEL__MUA_RTD base address */
  #define SENTINEL__MUA_RTD_BASE                   (0x37040000u)
  /** Peripheral SENTINEL__MUA_RTD base address */
  #define SENTINEL__MUA_RTD_BASE_NS                (0x27040000u)
  /** Peripheral SENTINEL__MUA_RTD base pointer */
  #define SENTINEL__MUA_RTD                        ((MU_RTD_Type *)SENTINEL__MUA_RTD_BASE)
  /** Peripheral SENTINEL__MUA_RTD base pointer */
  #define SENTINEL__MUA_RTD_NS                     ((MU_RTD_Type *)SENTINEL__MUA_RTD_BASE_NS)
  /** Array initializer of MU_RTD peripheral base addresses */
  #define MU_RTD_BASE_ADDRS                        { SENTINEL__MUA_RTD_BASE }
  /** Array initializer of MU_RTD peripheral base pointers */
  #define MU_RTD_BASE_PTRS                         { SENTINEL__MUA_RTD }
  /** Array initializer of MU_RTD peripheral base addresses */
  #define MU_RTD_BASE_ADDRS_NS                     { SENTINEL__MUA_RTD_BASE_NS }
  /** Array initializer of MU_RTD peripheral base pointers */
  #define MU_RTD_BASE_PTRS_NS                      { SENTINEL__MUA_RTD_NS }
#else
  /** Peripheral SENTINEL__MUA_RTD base address */
  #define SENTINEL__MUA_RTD_BASE                   (0x27040000u)
  /** Peripheral SENTINEL__MUA_RTD base pointer */
  #define SENTINEL__MUA_RTD                        ((MU_RTD_Type *)SENTINEL__MUA_RTD_BASE)
  /** Array initializer of MU_RTD peripheral base addresses */
  #define MU_RTD_BASE_ADDRS                        { SENTINEL__MUA_RTD_BASE }
  /** Array initializer of MU_RTD peripheral base pointers */
  #define MU_RTD_BASE_PTRS                         { SENTINEL__MUA_RTD }
#endif

/* PCC0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PCC0 base address */
  #define PCC0_BASE                                (0x38030000u)
  /** Peripheral PCC0 base address */
  #define PCC0_BASE_NS                             (0x28030000u)
  /** Peripheral PCC0 base pointer */
  #define PCC0                                     ((PCC0_Type *)PCC0_BASE)
  /** Peripheral PCC0 base pointer */
  #define PCC0_NS                                  ((PCC0_Type *)PCC0_BASE_NS)
  /** Array initializer of PCC0 peripheral base addresses */
  #define PCC0_BASE_ADDRS                          { PCC0_BASE }
  /** Array initializer of PCC0 peripheral base pointers */
  #define PCC0_BASE_PTRS                           { PCC0 }
  /** Array initializer of PCC0 peripheral base addresses */
  #define PCC0_BASE_ADDRS_NS                       { PCC0_BASE_NS }
  /** Array initializer of PCC0 peripheral base pointers */
  #define PCC0_BASE_PTRS_NS                        { PCC0_NS }
#else
  /** Peripheral PCC0 base address */
  #define PCC0_BASE                                (0x28030000u)
  /** Peripheral PCC0 base pointer */
  #define PCC0                                     ((PCC0_Type *)PCC0_BASE)
  /** Array initializer of PCC0 peripheral base addresses */
  #define PCC0_BASE_ADDRS                          { PCC0_BASE }
  /** Array initializer of PCC0 peripheral base pointers */
  #define PCC0_BASE_PTRS                           { PCC0 }
#endif

/* PCC1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PCC1 base address */
  #define PCC1_BASE                                (0x38091000u)
  /** Peripheral PCC1 base address */
  #define PCC1_BASE_NS                             (0x28091000u)
  /** Peripheral PCC1 base pointer */
  #define PCC1                                     ((PCC1_Type *)PCC1_BASE)
  /** Peripheral PCC1 base pointer */
  #define PCC1_NS                                  ((PCC1_Type *)PCC1_BASE_NS)
  /** Array initializer of PCC1 peripheral base addresses */
  #define PCC1_BASE_ADDRS                          { PCC1_BASE }
  /** Array initializer of PCC1 peripheral base pointers */
  #define PCC1_BASE_PTRS                           { PCC1 }
  /** Array initializer of PCC1 peripheral base addresses */
  #define PCC1_BASE_ADDRS_NS                       { PCC1_BASE_NS }
  /** Array initializer of PCC1 peripheral base pointers */
  #define PCC1_BASE_PTRS_NS                        { PCC1_NS }
#else
  /** Peripheral PCC1 base address */
  #define PCC1_BASE                                (0x28091000u)
  /** Peripheral PCC1 base pointer */
  #define PCC1                                     ((PCC1_Type *)PCC1_BASE)
  /** Array initializer of PCC1 peripheral base addresses */
  #define PCC1_BASE_ADDRS                          { PCC1_BASE }
  /** Array initializer of PCC1 peripheral base pointers */
  #define PCC1_BASE_PTRS                           { PCC1 }
#endif

/* PCC2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PCC2 base address */
  #define PCC2_BASE                                (0x38102000u)
  /** Peripheral PCC2 base address */
  #define PCC2_BASE_NS                             (0x28102000u)
  /** Peripheral PCC2 base pointer */
  #define PCC2                                     ((PCC2_Type *)PCC2_BASE)
  /** Peripheral PCC2 base pointer */
  #define PCC2_NS                                  ((PCC2_Type *)PCC2_BASE_NS)
  /** Array initializer of PCC2 peripheral base addresses */
  #define PCC2_BASE_ADDRS                          { PCC2_BASE }
  /** Array initializer of PCC2 peripheral base pointers */
  #define PCC2_BASE_PTRS                           { PCC2 }
  /** Array initializer of PCC2 peripheral base addresses */
  #define PCC2_BASE_ADDRS_NS                       { PCC2_BASE_NS }
  /** Array initializer of PCC2 peripheral base pointers */
  #define PCC2_BASE_PTRS_NS                        { PCC2_NS }
#else
  /** Peripheral PCC2 base address */
  #define PCC2_BASE                                (0x28102000u)
  /** Peripheral PCC2 base pointer */
  #define PCC2                                     ((PCC2_Type *)PCC2_BASE)
  /** Array initializer of PCC2 peripheral base addresses */
  #define PCC2_BASE_ADDRS                          { PCC2_BASE }
  /** Array initializer of PCC2 peripheral base pointers */
  #define PCC2_BASE_PTRS                           { PCC2 }
#endif

/* PCC3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PCC3 base address */
  #define PCC3_BASE                                (0x392D0000u)
  /** Peripheral PCC3 base address */
  #define PCC3_BASE_NS                             (0x292D0000u)
  /** Peripheral PCC3 base pointer */
  #define PCC3                                     ((PCC3_Type *)PCC3_BASE)
  /** Peripheral PCC3 base pointer */
  #define PCC3_NS                                  ((PCC3_Type *)PCC3_BASE_NS)
  /** Array initializer of PCC3 peripheral base addresses */
  #define PCC3_BASE_ADDRS                          { PCC3_BASE }
  /** Array initializer of PCC3 peripheral base pointers */
  #define PCC3_BASE_PTRS                           { PCC3 }
  /** Array initializer of PCC3 peripheral base addresses */
  #define PCC3_BASE_ADDRS_NS                       { PCC3_BASE_NS }
  /** Array initializer of PCC3 peripheral base pointers */
  #define PCC3_BASE_PTRS_NS                        { PCC3_NS }
#else
  /** Peripheral PCC3 base address */
  #define PCC3_BASE                                (0x292D0000u)
  /** Peripheral PCC3 base pointer */
  #define PCC3                                     ((PCC3_Type *)PCC3_BASE)
  /** Array initializer of PCC3 peripheral base addresses */
  #define PCC3_BASE_ADDRS                          { PCC3_BASE }
  /** Array initializer of PCC3 peripheral base pointers */
  #define PCC3_BASE_PTRS                           { PCC3 }
#endif

/* PCC4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PCC4 base address */
  #define PCC4_BASE                                (0x39800000u)
  /** Peripheral PCC4 base address */
  #define PCC4_BASE_NS                             (0x29800000u)
  /** Peripheral PCC4 base pointer */
  #define PCC4                                     ((PCC4_Type *)PCC4_BASE)
  /** Peripheral PCC4 base pointer */
  #define PCC4_NS                                  ((PCC4_Type *)PCC4_BASE_NS)
  /** Array initializer of PCC4 peripheral base addresses */
  #define PCC4_BASE_ADDRS                          { PCC4_BASE }
  /** Array initializer of PCC4 peripheral base pointers */
  #define PCC4_BASE_PTRS                           { PCC4 }
  /** Array initializer of PCC4 peripheral base addresses */
  #define PCC4_BASE_ADDRS_NS                       { PCC4_BASE_NS }
  /** Array initializer of PCC4 peripheral base pointers */
  #define PCC4_BASE_PTRS_NS                        { PCC4_NS }
#else
  /** Peripheral PCC4 base address */
  #define PCC4_BASE                                (0x29800000u)
  /** Peripheral PCC4 base pointer */
  #define PCC4                                     ((PCC4_Type *)PCC4_BASE)
  /** Array initializer of PCC4 peripheral base addresses */
  #define PCC4_BASE_ADDRS                          { PCC4_BASE }
  /** Array initializer of PCC4 peripheral base pointers */
  #define PCC4_BASE_PTRS                           { PCC4 }
#endif

/* PCC5 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PCC5 base address */
  #define PCC5_BASE                                (0x3DA70000u)
  /** Peripheral PCC5 base address */
  #define PCC5_BASE_NS                             (0x2DA70000u)
  /** Peripheral PCC5 base pointer */
  #define PCC5                                     ((PCC5_Type *)PCC5_BASE)
  /** Peripheral PCC5 base pointer */
  #define PCC5_NS                                  ((PCC5_Type *)PCC5_BASE_NS)
  /** Array initializer of PCC5 peripheral base addresses */
  #define PCC5_BASE_ADDRS                          { PCC5_BASE }
  /** Array initializer of PCC5 peripheral base pointers */
  #define PCC5_BASE_PTRS                           { PCC5 }
  /** Array initializer of PCC5 peripheral base addresses */
  #define PCC5_BASE_ADDRS_NS                       { PCC5_BASE_NS }
  /** Array initializer of PCC5 peripheral base pointers */
  #define PCC5_BASE_PTRS_NS                        { PCC5_NS }
#else
  /** Peripheral PCC5 base address */
  #define PCC5_BASE                                (0x2DA70000u)
  /** Peripheral PCC5 base pointer */
  #define PCC5                                     ((PCC5_Type *)PCC5_BASE)
  /** Array initializer of PCC5 peripheral base addresses */
  #define PCC5_BASE_ADDRS                          { PCC5_BASE }
  /** Array initializer of PCC5 peripheral base pointers */
  #define PCC5_BASE_PTRS                           { PCC5 }
#endif

/* PDM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PDM base address */
  #define PDM_BASE                                 (0x38111000u)
  /** Peripheral PDM base address */
  #define PDM_BASE_NS                              (0x28111000u)
  /** Peripheral PDM base pointer */
  #define PDM                                      ((PDM_Type *)PDM_BASE)
  /** Peripheral PDM base pointer */
  #define PDM_NS                                   ((PDM_Type *)PDM_BASE_NS)
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS                           { PDM_BASE }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS                            { PDM }
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS_NS                        { PDM_BASE_NS }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS_NS                         { PDM_NS }
#else
  /** Peripheral PDM base address */
  #define PDM_BASE                                 (0x28111000u)
  /** Peripheral PDM base pointer */
  #define PDM                                      ((PDM_Type *)PDM_BASE)
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS                           { PDM_BASE }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS                            { PDM }
#endif

/* POWERQUAD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral POWERQUAD base address */
  #define POWERQUAD_BASE                           (0x38400000u)
  /** Peripheral POWERQUAD base address */
  #define POWERQUAD_BASE_NS                        (0x28400000u)
  /** Peripheral POWERQUAD base pointer */
  #define POWERQUAD                                ((POWERQUAD_Type *)POWERQUAD_BASE)
  /** Peripheral POWERQUAD base pointer */
  #define POWERQUAD_NS                             ((POWERQUAD_Type *)POWERQUAD_BASE_NS)
  /** Array initializer of POWERQUAD peripheral base addresses */
  #define POWERQUAD_BASE_ADDRS                     { POWERQUAD_BASE }
  /** Array initializer of POWERQUAD peripheral base pointers */
  #define POWERQUAD_BASE_PTRS                      { POWERQUAD }
  /** Array initializer of POWERQUAD peripheral base addresses */
  #define POWERQUAD_BASE_ADDRS_NS                  { POWERQUAD_BASE_NS }
  /** Array initializer of POWERQUAD peripheral base pointers */
  #define POWERQUAD_BASE_PTRS_NS                   { POWERQUAD_NS }
#else
  /** Peripheral POWERQUAD base address */
  #define POWERQUAD_BASE                           (0x28400000u)
  /** Peripheral POWERQUAD base pointer */
  #define POWERQUAD                                ((POWERQUAD_Type *)POWERQUAD_BASE)
  /** Array initializer of POWERQUAD peripheral base addresses */
  #define POWERQUAD_BASE_ADDRS                     { POWERQUAD_BASE }
  /** Array initializer of POWERQUAD peripheral base pointers */
  #define POWERQUAD_BASE_PTRS                      { POWERQUAD }
#endif
/** Interrupt vectors for the POWERQUAD peripheral type */
#define POWERQUAD_IRQS                           { PowerQuad_IRQn }

/* PXP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PXP base address */
  #define PXP_BASE                                 (0x3DB40000u)
  /** Peripheral PXP base address */
  #define PXP_BASE_NS                              (0x2DB40000u)
  /** Peripheral PXP base pointer */
  #define PXP                                      ((PXP_Type *)PXP_BASE)
  /** Peripheral PXP base pointer */
  #define PXP_NS                                   ((PXP_Type *)PXP_BASE_NS)
  /** Array initializer of PXP peripheral base addresses */
  #define PXP_BASE_ADDRS                           { PXP_BASE }
  /** Array initializer of PXP peripheral base pointers */
  #define PXP_BASE_PTRS                            { PXP }
  /** Array initializer of PXP peripheral base addresses */
  #define PXP_BASE_ADDRS_NS                        { PXP_BASE_NS }
  /** Array initializer of PXP peripheral base pointers */
  #define PXP_BASE_PTRS_NS                         { PXP_NS }
#else
  /** Peripheral PXP base address */
  #define PXP_BASE                                 (0x2DB40000u)
  /** Peripheral PXP base pointer */
  #define PXP                                      ((PXP_Type *)PXP_BASE)
  /** Array initializer of PXP peripheral base addresses */
  #define PXP_BASE_ADDRS                           { PXP_BASE }
  /** Array initializer of PXP peripheral base pointers */
  #define PXP_BASE_PTRS                            { PXP }
#endif
/** Interrupt vectors for the PXP peripheral type */
#define PXP_IRQ0_IRQS                            { PXP_IRQn }
#define PXP_IRQ1_IRQS                            { PXP_IRQn }

/* RGPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPIOA base address */
  #define GPIOA_BASE                               (0x38800000u)
  /** Peripheral GPIOA base address */
  #define GPIOA_BASE_NS                            (0x28800000u)
  /** Peripheral GPIOA base pointer */
  #define GPIOA                                    ((RGPIO_Type *)GPIOA_BASE)
  /** Peripheral GPIOA base pointer */
  #define GPIOA_NS                                 ((RGPIO_Type *)GPIOA_BASE_NS)
  /** Peripheral GPIOB base address */
  #define GPIOB_BASE                               (0x38810000u)
  /** Peripheral GPIOB base address */
  #define GPIOB_BASE_NS                            (0x28810000u)
  /** Peripheral GPIOB base pointer */
  #define GPIOB                                    ((RGPIO_Type *)GPIOB_BASE)
  /** Peripheral GPIOB base pointer */
  #define GPIOB_NS                                 ((RGPIO_Type *)GPIOB_BASE_NS)
  /** Peripheral GPIOC base address */
  #define GPIOC_BASE                               (0x38820000u)
  /** Peripheral GPIOC base address */
  #define GPIOC_BASE_NS                            (0x28820000u)
  /** Peripheral GPIOC base pointer */
  #define GPIOC                                    ((RGPIO_Type *)GPIOC_BASE)
  /** Peripheral GPIOC base pointer */
  #define GPIOC_NS                                 ((RGPIO_Type *)GPIOC_BASE_NS)
  /** Peripheral GPIOD base address */
  #define GPIOD_BASE                               (0x3E200000u)
  /** Peripheral GPIOD base address */
  #define GPIOD_BASE_NS                            (0x2E200000u)
  /** Peripheral GPIOD base pointer */
  #define GPIOD                                    ((RGPIO_Type *)GPIOD_BASE)
  /** Peripheral GPIOD base pointer */
  #define GPIOD_NS                                 ((RGPIO_Type *)GPIOD_BASE_NS)
  /** Peripheral GPIOE base address */
  #define GPIOE_BASE                               (0x3D000000u)
  /** Peripheral GPIOE base address */
  #define GPIOE_BASE_NS                            (0x2D000000u)
  /** Peripheral GPIOE base pointer */
  #define GPIOE                                    ((RGPIO_Type *)GPIOE_BASE)
  /** Peripheral GPIOE base pointer */
  #define GPIOE_NS                                 ((RGPIO_Type *)GPIOE_BASE_NS)
  /** Peripheral GPIOF base address */
  #define GPIOF_BASE                               (0x3D010000u)
  /** Peripheral GPIOF base address */
  #define GPIOF_BASE_NS                            (0x2D010000u)
  /** Peripheral GPIOF base pointer */
  #define GPIOF                                    ((RGPIO_Type *)GPIOF_BASE)
  /** Peripheral GPIOF base pointer */
  #define GPIOF_NS                                 ((RGPIO_Type *)GPIOF_BASE_NS)
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS                         { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE, GPIOF_BASE }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS                          { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF }
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS_NS                      { GPIOA_BASE_NS, GPIOB_BASE_NS, GPIOC_BASE_NS, GPIOD_BASE_NS, GPIOE_BASE_NS, GPIOF_BASE_NS }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS_NS                       { GPIOA_NS, GPIOB_NS, GPIOC_NS, GPIOD_NS, GPIOE_NS, GPIOF_NS }
#else
  /** Peripheral GPIOA base address */
  #define GPIOA_BASE                               (0x28800000u)
  /** Peripheral GPIOA base pointer */
  #define GPIOA                                    ((RGPIO_Type *)GPIOA_BASE)
  /** Peripheral GPIOB base address */
  #define GPIOB_BASE                               (0x28810000u)
  /** Peripheral GPIOB base pointer */
  #define GPIOB                                    ((RGPIO_Type *)GPIOB_BASE)
  /** Peripheral GPIOC base address */
  #define GPIOC_BASE                               (0x28820000u)
  /** Peripheral GPIOC base pointer */
  #define GPIOC                                    ((RGPIO_Type *)GPIOC_BASE)
  /** Peripheral GPIOD base address */
  #define GPIOD_BASE                               (0x2E200000u)
  /** Peripheral GPIOD base pointer */
  #define GPIOD                                    ((RGPIO_Type *)GPIOD_BASE)
  /** Peripheral GPIOE base address */
  #define GPIOE_BASE                               (0x2D000000u)
  /** Peripheral GPIOE base pointer */
  #define GPIOE                                    ((RGPIO_Type *)GPIOE_BASE)
  /** Peripheral GPIOF base address */
  #define GPIOF_BASE                               (0x2D010000u)
  /** Peripheral GPIOF base pointer */
  #define GPIOF                                    ((RGPIO_Type *)GPIOF_BASE)
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS                         { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE, GPIOF_BASE }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS                          { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF }
#endif

/* SEMA42 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SEMA42_0 base address */
  #define SEMA42_0_BASE                            (0x38037000u)
  /** Peripheral SEMA42_0 base address */
  #define SEMA42_0_BASE_NS                         (0x28037000u)
  /** Peripheral SEMA42_0 base pointer */
  #define SEMA42_0                                 ((SEMA42_Type *)SEMA42_0_BASE)
  /** Peripheral SEMA42_0 base pointer */
  #define SEMA42_0_NS                              ((SEMA42_Type *)SEMA42_0_BASE_NS)
  /** Peripheral SEMA42_1 base address */
  #define SEMA42_1_BASE                            (0x39300000u)
  /** Peripheral SEMA42_1 base address */
  #define SEMA42_1_BASE_NS                         (0x29300000u)
  /** Peripheral SEMA42_1 base pointer */
  #define SEMA42_1                                 ((SEMA42_Type *)SEMA42_1_BASE)
  /** Peripheral SEMA42_1 base pointer */
  #define SEMA42_1_NS                              ((SEMA42_Type *)SEMA42_1_BASE_NS)
  /** Peripheral SEMA42_2 base address */
  #define SEMA42_2_BASE                            (0x3DA30000u)
  /** Peripheral SEMA42_2 base address */
  #define SEMA42_2_BASE_NS                         (0x2DA30000u)
  /** Peripheral SEMA42_2 base pointer */
  #define SEMA42_2                                 ((SEMA42_Type *)SEMA42_2_BASE)
  /** Peripheral SEMA42_2 base pointer */
  #define SEMA42_2_NS                              ((SEMA42_Type *)SEMA42_2_BASE_NS)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA42_0_BASE, SEMA42_1_BASE, SEMA42_2_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA42_0, SEMA42_1, SEMA42_2 }
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS_NS                     { SEMA42_0_BASE_NS, SEMA42_1_BASE_NS, SEMA42_2_BASE_NS }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS_NS                      { SEMA42_0_NS, SEMA42_1_NS, SEMA42_2_NS }
#else
  /** Peripheral SEMA42_0 base address */
  #define SEMA42_0_BASE                            (0x28037000u)
  /** Peripheral SEMA42_0 base pointer */
  #define SEMA42_0                                 ((SEMA42_Type *)SEMA42_0_BASE)
  /** Peripheral SEMA42_1 base address */
  #define SEMA42_1_BASE                            (0x29300000u)
  /** Peripheral SEMA42_1 base pointer */
  #define SEMA42_1                                 ((SEMA42_Type *)SEMA42_1_BASE)
  /** Peripheral SEMA42_2 base address */
  #define SEMA42_2_BASE                            (0x2DA30000u)
  /** Peripheral SEMA42_2 base pointer */
  #define SEMA42_2                                 ((SEMA42_Type *)SEMA42_2_BASE)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA42_0_BASE, SEMA42_1_BASE, SEMA42_2_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA42_0, SEMA42_1, SEMA42_2 }
#endif

/* SIM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SIM_RTD base address */
  #define SIM_RTD_BASE                             (0x3802A000u)
  /** Peripheral SIM_RTD base address */
  #define SIM_RTD_BASE_NS                          (0x2802A000u)
  /** Peripheral SIM_RTD base pointer */
  #define SIM_RTD                                  ((SIM_Type *)SIM_RTD_BASE)
  /** Peripheral SIM_RTD base pointer */
  #define SIM_RTD_NS                               ((SIM_Type *)SIM_RTD_BASE_NS)
  /** Array initializer of SIM peripheral base addresses */
  #define SIM_BASE_ADDRS                           { SIM_RTD_BASE }
  /** Array initializer of SIM peripheral base pointers */
  #define SIM_BASE_PTRS                            { SIM_RTD }
  /** Array initializer of SIM peripheral base addresses */
  #define SIM_BASE_ADDRS_NS                        { SIM_RTD_BASE_NS }
  /** Array initializer of SIM peripheral base pointers */
  #define SIM_BASE_PTRS_NS                         { SIM_RTD_NS }
#else
  /** Peripheral SIM_RTD base address */
  #define SIM_RTD_BASE                             (0x2802A000u)
  /** Peripheral SIM_RTD base pointer */
  #define SIM_RTD                                  ((SIM_Type *)SIM_RTD_BASE)
  /** Array initializer of SIM peripheral base addresses */
  #define SIM_BASE_ADDRS                           { SIM_RTD_BASE }
  /** Array initializer of SIM peripheral base pointers */
  #define SIM_BASE_PTRS                            { SIM_RTD }
#endif
/** Interrupt vectors for the SIM peripheral type */
#define SIM_IRQS                                 { SIM0_IRQn }

/* SIM_AD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SIM_AD base address */
  #define SIM_AD_BASE                              (0x39290000u)
  /** Peripheral SIM_AD base address */
  #define SIM_AD_BASE_NS                           (0x29290000u)
  /** Peripheral SIM_AD base pointer */
  #define SIM_AD                                   ((SIM_AD_Type *)SIM_AD_BASE)
  /** Peripheral SIM_AD base pointer */
  #define SIM_AD_NS                                ((SIM_AD_Type *)SIM_AD_BASE_NS)
  /** Array initializer of SIM_AD peripheral base addresses */
  #define SIM_AD_BASE_ADDRS                        { SIM_AD_BASE }
  /** Array initializer of SIM_AD peripheral base pointers */
  #define SIM_AD_BASE_PTRS                         { SIM_AD }
  /** Array initializer of SIM_AD peripheral base addresses */
  #define SIM_AD_BASE_ADDRS_NS                     { SIM_AD_BASE_NS }
  /** Array initializer of SIM_AD peripheral base pointers */
  #define SIM_AD_BASE_PTRS_NS                      { SIM_AD_NS }
#else
  /** Peripheral SIM_AD base address */
  #define SIM_AD_BASE                              (0x29290000u)
  /** Peripheral SIM_AD base pointer */
  #define SIM_AD                                   ((SIM_AD_Type *)SIM_AD_BASE)
  /** Array initializer of SIM_AD peripheral base addresses */
  #define SIM_AD_BASE_ADDRS                        { SIM_AD_BASE }
  /** Array initializer of SIM_AD peripheral base pointers */
  #define SIM_AD_BASE_PTRS                         { SIM_AD }
#endif

/* SIM_LPAV - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SIM_LPAV base address */
  #define SIM_LPAV_BASE                            (0x3DA50000u)
  /** Peripheral SIM_LPAV base address */
  #define SIM_LPAV_BASE_NS                         (0x2DA50000u)
  /** Peripheral SIM_LPAV base pointer */
  #define SIM_LPAV                                 ((SIM_LPAV_Type *)SIM_LPAV_BASE)
  /** Peripheral SIM_LPAV base pointer */
  #define SIM_LPAV_NS                              ((SIM_LPAV_Type *)SIM_LPAV_BASE_NS)
  /** Array initializer of SIM_LPAV peripheral base addresses */
  #define SIM_LPAV_BASE_ADDRS                      { SIM_LPAV_BASE }
  /** Array initializer of SIM_LPAV peripheral base pointers */
  #define SIM_LPAV_BASE_PTRS                       { SIM_LPAV }
  /** Array initializer of SIM_LPAV peripheral base addresses */
  #define SIM_LPAV_BASE_ADDRS_NS                   { SIM_LPAV_BASE_NS }
  /** Array initializer of SIM_LPAV peripheral base pointers */
  #define SIM_LPAV_BASE_PTRS_NS                    { SIM_LPAV_NS }
#else
  /** Peripheral SIM_LPAV base address */
  #define SIM_LPAV_BASE                            (0x2DA50000u)
  /** Peripheral SIM_LPAV base pointer */
  #define SIM_LPAV                                 ((SIM_LPAV_Type *)SIM_LPAV_BASE)
  /** Array initializer of SIM_LPAV peripheral base addresses */
  #define SIM_LPAV_BASE_ADDRS                      { SIM_LPAV_BASE }
  /** Array initializer of SIM_LPAV peripheral base pointers */
  #define SIM_LPAV_BASE_PTRS                       { SIM_LPAV }
#endif

/* SIM_SEC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SIM_SEC base address */
  #define SIM_SEC_BASE                             (0x3802B000u)
  /** Peripheral SIM_SEC base address */
  #define SIM_SEC_BASE_NS                          (0x2802B000u)
  /** Peripheral SIM_SEC base pointer */
  #define SIM_SEC                                  ((SIM_SEC_Type *)SIM_SEC_BASE)
  /** Peripheral SIM_SEC base pointer */
  #define SIM_SEC_NS                               ((SIM_SEC_Type *)SIM_SEC_BASE_NS)
  /** Array initializer of SIM_SEC peripheral base addresses */
  #define SIM_SEC_BASE_ADDRS                       { SIM_SEC_BASE }
  /** Array initializer of SIM_SEC peripheral base pointers */
  #define SIM_SEC_BASE_PTRS                        { SIM_SEC }
  /** Array initializer of SIM_SEC peripheral base addresses */
  #define SIM_SEC_BASE_ADDRS_NS                    { SIM_SEC_BASE_NS }
  /** Array initializer of SIM_SEC peripheral base pointers */
  #define SIM_SEC_BASE_PTRS_NS                     { SIM_SEC_NS }
#else
  /** Peripheral SIM_SEC base address */
  #define SIM_SEC_BASE                             (0x2802B000u)
  /** Peripheral SIM_SEC base pointer */
  #define SIM_SEC                                  ((SIM_SEC_Type *)SIM_SEC_BASE)
  /** Array initializer of SIM_SEC peripheral base addresses */
  #define SIM_SEC_BASE_ADDRS                       { SIM_SEC_BASE }
  /** Array initializer of SIM_SEC peripheral base pointers */
  #define SIM_SEC_BASE_PTRS                        { SIM_SEC }
#endif

/* SPDIF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SPDIF base address */
  #define SPDIF_BASE                               (0x3DAB0000u)
  /** Peripheral SPDIF base address */
  #define SPDIF_BASE_NS                            (0x2DAB0000u)
  /** Peripheral SPDIF base pointer */
  #define SPDIF                                    ((SPDIF_Type *)SPDIF_BASE)
  /** Peripheral SPDIF base pointer */
  #define SPDIF_NS                                 ((SPDIF_Type *)SPDIF_BASE_NS)
  /** Array initializer of SPDIF peripheral base addresses */
  #define SPDIF_BASE_ADDRS                         { SPDIF_BASE }
  /** Array initializer of SPDIF peripheral base pointers */
  #define SPDIF_BASE_PTRS                          { SPDIF }
  /** Array initializer of SPDIF peripheral base addresses */
  #define SPDIF_BASE_ADDRS_NS                      { SPDIF_BASE_NS }
  /** Array initializer of SPDIF peripheral base pointers */
  #define SPDIF_BASE_PTRS_NS                       { SPDIF_NS }
#else
  /** Peripheral SPDIF base address */
  #define SPDIF_BASE                               (0x2DAB0000u)
  /** Peripheral SPDIF base pointer */
  #define SPDIF                                    ((SPDIF_Type *)SPDIF_BASE)
  /** Array initializer of SPDIF peripheral base addresses */
  #define SPDIF_BASE_ADDRS                         { SPDIF_BASE }
  /** Array initializer of SPDIF peripheral base pointers */
  #define SPDIF_BASE_PTRS                          { SPDIF }
#endif
/** Interrupt vectors for the SPDIF peripheral type */
#define SPDIF_IRQS                               { SPDIF_IRQn }

/* SYSPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSPM0 base address */
  #define SYSPM0_BASE                              (0x38026000u)
  /** Peripheral SYSPM0 base address */
  #define SYSPM0_BASE_NS                           (0x28026000u)
  /** Peripheral SYSPM0 base pointer */
  #define SYSPM0                                   ((SYSPM_Type *)SYSPM0_BASE)
  /** Peripheral SYSPM0 base pointer */
  #define SYSPM0_NS                                ((SYSPM_Type *)SYSPM0_BASE_NS)
  /** Peripheral SYSPM1 base address */
  #define SYSPM1_BASE                              (0x39270000u)
  /** Peripheral SYSPM1 base address */
  #define SYSPM1_BASE_NS                           (0x29270000u)
  /** Peripheral SYSPM1 base pointer */
  #define SYSPM1                                   ((SYSPM_Type *)SYSPM1_BASE)
  /** Peripheral SYSPM1 base pointer */
  #define SYSPM1_NS                                ((SYSPM_Type *)SYSPM1_BASE_NS)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { SYSPM0_BASE, SYSPM1_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { SYSPM0, SYSPM1 }
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS_NS                      { SYSPM0_BASE_NS, SYSPM1_BASE_NS }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS_NS                       { SYSPM0_NS, SYSPM1_NS }
#else
  /** Peripheral SYSPM0 base address */
  #define SYSPM0_BASE                              (0x28026000u)
  /** Peripheral SYSPM0 base pointer */
  #define SYSPM0                                   ((SYSPM_Type *)SYSPM0_BASE)
  /** Peripheral SYSPM1 base address */
  #define SYSPM1_BASE                              (0x29270000u)
  /** Peripheral SYSPM1 base pointer */
  #define SYSPM1                                   ((SYSPM_Type *)SYSPM1_BASE)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { SYSPM0_BASE, SYSPM1_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { SYSPM0, SYSPM1 }
#endif

/* TPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TPM0 base address */
  #define TPM0_BASE                                (0x38095000u)
  /** Peripheral TPM0 base address */
  #define TPM0_BASE_NS                             (0x28095000u)
  /** Peripheral TPM0 base pointer */
  #define TPM0                                     ((TPM_Type *)TPM0_BASE)
  /** Peripheral TPM0 base pointer */
  #define TPM0_NS                                  ((TPM_Type *)TPM0_BASE_NS)
  /** Peripheral TPM1 base address */
  #define TPM1_BASE                                (0x38096000u)
  /** Peripheral TPM1 base address */
  #define TPM1_BASE_NS                             (0x28096000u)
  /** Peripheral TPM1 base pointer */
  #define TPM1                                     ((TPM_Type *)TPM1_BASE)
  /** Peripheral TPM1 base pointer */
  #define TPM1_NS                                  ((TPM_Type *)TPM1_BASE_NS)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE                                (0x38105000u)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE_NS                             (0x28105000u)
  /** Peripheral TPM2 base pointer */
  #define TPM2                                     ((TPM_Type *)TPM2_BASE)
  /** Peripheral TPM2 base pointer */
  #define TPM2_NS                                  ((TPM_Type *)TPM2_BASE_NS)
  /** Peripheral TPM3 base address */
  #define TPM3_BASE                                (0x38106000u)
  /** Peripheral TPM3 base address */
  #define TPM3_BASE_NS                             (0x28106000u)
  /** Peripheral TPM3 base pointer */
  #define TPM3                                     ((TPM_Type *)TPM3_BASE)
  /** Peripheral TPM3 base pointer */
  #define TPM3_NS                                  ((TPM_Type *)TPM3_BASE_NS)
  /** Peripheral TPM4 base address */
  #define TPM4_BASE                                (0x39330000u)
  /** Peripheral TPM4 base address */
  #define TPM4_BASE_NS                             (0x29330000u)
  /** Peripheral TPM4 base pointer */
  #define TPM4                                     ((TPM_Type *)TPM4_BASE)
  /** Peripheral TPM4 base pointer */
  #define TPM4_NS                                  ((TPM_Type *)TPM4_BASE_NS)
  /** Peripheral TPM5 base address */
  #define TPM5_BASE                                (0x39340000u)
  /** Peripheral TPM5 base address */
  #define TPM5_BASE_NS                             (0x29340000u)
  /** Peripheral TPM5 base pointer */
  #define TPM5                                     ((TPM_Type *)TPM5_BASE)
  /** Peripheral TPM5 base pointer */
  #define TPM5_NS                                  ((TPM_Type *)TPM5_BASE_NS)
  /** Peripheral TPM6 base address */
  #define TPM6_BASE                                (0x39820000u)
  /** Peripheral TPM6 base address */
  #define TPM6_BASE_NS                             (0x29820000u)
  /** Peripheral TPM6 base pointer */
  #define TPM6                                     ((TPM_Type *)TPM6_BASE)
  /** Peripheral TPM6 base pointer */
  #define TPM6_NS                                  ((TPM_Type *)TPM6_BASE_NS)
  /** Peripheral TPM7 base address */
  #define TPM7_BASE                                (0x39830000u)
  /** Peripheral TPM7 base address */
  #define TPM7_BASE_NS                             (0x29830000u)
  /** Peripheral TPM7 base pointer */
  #define TPM7                                     ((TPM_Type *)TPM7_BASE)
  /** Peripheral TPM7 base pointer */
  #define TPM7_NS                                  ((TPM_Type *)TPM7_BASE_NS)
  /** Peripheral TPM8 base address */
  #define TPM8_BASE                                (0x3DA80000u)
  /** Peripheral TPM8 base address */
  #define TPM8_BASE_NS                             (0x2DA80000u)
  /** Peripheral TPM8 base pointer */
  #define TPM8                                     ((TPM_Type *)TPM8_BASE)
  /** Peripheral TPM8 base pointer */
  #define TPM8_NS                                  ((TPM_Type *)TPM8_BASE_NS)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { TPM0_BASE, TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE, TPM7_BASE, TPM8_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { TPM0, TPM1, TPM2, TPM3, TPM4, TPM5, TPM6, TPM7, TPM8 }
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS_NS                        { TPM0_BASE_NS, TPM1_BASE_NS, TPM2_BASE_NS, TPM3_BASE_NS, TPM4_BASE_NS, TPM5_BASE_NS, TPM6_BASE_NS, TPM7_BASE_NS, TPM8_BASE_NS }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS_NS                         { TPM0_NS, TPM1_NS, TPM2_NS, TPM3_NS, TPM4_NS, TPM5_NS, TPM6_NS, TPM7_NS, TPM8_NS }
#else
  /** Peripheral TPM0 base address */
  #define TPM0_BASE                                (0x28095000u)
  /** Peripheral TPM0 base pointer */
  #define TPM0                                     ((TPM_Type *)TPM0_BASE)
  /** Peripheral TPM1 base address */
  #define TPM1_BASE                                (0x28096000u)
  /** Peripheral TPM1 base pointer */
  #define TPM1                                     ((TPM_Type *)TPM1_BASE)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE                                (0x28105000u)
  /** Peripheral TPM2 base pointer */
  #define TPM2                                     ((TPM_Type *)TPM2_BASE)
  /** Peripheral TPM3 base address */
  #define TPM3_BASE                                (0x28106000u)
  /** Peripheral TPM3 base pointer */
  #define TPM3                                     ((TPM_Type *)TPM3_BASE)
  /** Peripheral TPM4 base address */
  #define TPM4_BASE                                (0x29330000u)
  /** Peripheral TPM4 base pointer */
  #define TPM4                                     ((TPM_Type *)TPM4_BASE)
  /** Peripheral TPM5 base address */
  #define TPM5_BASE                                (0x29340000u)
  /** Peripheral TPM5 base pointer */
  #define TPM5                                     ((TPM_Type *)TPM5_BASE)
  /** Peripheral TPM6 base address */
  #define TPM6_BASE                                (0x29820000u)
  /** Peripheral TPM6 base pointer */
  #define TPM6                                     ((TPM_Type *)TPM6_BASE)
  /** Peripheral TPM7 base address */
  #define TPM7_BASE                                (0x29830000u)
  /** Peripheral TPM7 base pointer */
  #define TPM7                                     ((TPM_Type *)TPM7_BASE)
  /** Peripheral TPM8 base address */
  #define TPM8_BASE                                (0x2DA80000u)
  /** Peripheral TPM8 base pointer */
  #define TPM8                                     ((TPM_Type *)TPM8_BASE)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { TPM0_BASE, TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE, TPM7_BASE, TPM8_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { TPM0, TPM1, TPM2, TPM3, TPM4, TPM5, TPM6, TPM7, TPM8 }
#endif
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { TPM0_IRQn, TPM1_IRQn, TPM2_IRQn, TPM3_IRQn, TPM4_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* TRDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRDC base address */
  #define TRDC_BASE                                (0x38031000u)
  /** Peripheral TRDC base address */
  #define TRDC_BASE_NS                             (0x28031000u)
  /** Peripheral TRDC base pointer */
  #define TRDC                                     ((TRDC_Type *)TRDC_BASE)
  /** Peripheral TRDC base pointer */
  #define TRDC_NS                                  ((TRDC_Type *)TRDC_BASE_NS)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { TRDC_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { TRDC }
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS_NS                       { TRDC_BASE_NS }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS_NS                        { TRDC_NS }
#else
  /** Peripheral TRDC base address */
  #define TRDC_BASE                                (0x28031000u)
  /** Peripheral TRDC base pointer */
  #define TRDC                                     ((TRDC_Type *)TRDC_BASE)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { TRDC_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { TRDC }
#endif
/** Interrupt vectors for the TRDC peripheral type */
#define TRDC_IRQS                                { TRDC_IRQn }
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


/* TRGMUX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRGMUX0 base address */
  #define TRGMUX0_BASE                             (0x38027000u)
  /** Peripheral TRGMUX0 base address */
  #define TRGMUX0_BASE_NS                          (0x28027000u)
  /** Peripheral TRGMUX0 base pointer */
  #define TRGMUX0                                  ((TRGMUX_Type *)TRGMUX0_BASE)
  /** Peripheral TRGMUX0 base pointer */
  #define TRGMUX0_NS                               ((TRGMUX_Type *)TRGMUX0_BASE_NS)
  /** Peripheral TRGMUX1 base address */
  #define TRGMUX1_BASE                             (0x39250000u)
  /** Peripheral TRGMUX1 base address */
  #define TRGMUX1_BASE_NS                          (0x29250000u)
  /** Peripheral TRGMUX1 base pointer */
  #define TRGMUX1                                  ((TRGMUX_Type *)TRGMUX1_BASE)
  /** Peripheral TRGMUX1 base pointer */
  #define TRGMUX1_NS                               ((TRGMUX_Type *)TRGMUX1_BASE_NS)
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS                        { TRGMUX0_BASE, TRGMUX1_BASE }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS                         { TRGMUX0, TRGMUX1 }
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS_NS                     { TRGMUX0_BASE_NS, TRGMUX1_BASE_NS }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS_NS                      { TRGMUX0_NS, TRGMUX1_NS }
#else
  /** Peripheral TRGMUX0 base address */
  #define TRGMUX0_BASE                             (0x28027000u)
  /** Peripheral TRGMUX0 base pointer */
  #define TRGMUX0                                  ((TRGMUX_Type *)TRGMUX0_BASE)
  /** Peripheral TRGMUX1 base address */
  #define TRGMUX1_BASE                             (0x29250000u)
  /** Peripheral TRGMUX1 base pointer */
  #define TRGMUX1                                  ((TRGMUX_Type *)TRGMUX1_BASE)
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS                        { TRGMUX0_BASE, TRGMUX1_BASE }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS                         { TRGMUX0, TRGMUX1 }
#endif

/* TSTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TSTMR0__TIMESTAMP0 base address */
  #define TSTMR0__TIMESTAMP0_BASE                  (0x3802AC00u)
  /** Peripheral TSTMR0__TIMESTAMP0 base address */
  #define TSTMR0__TIMESTAMP0_BASE_NS               (0x2802AC00u)
  /** Peripheral TSTMR0__TIMESTAMP0 base pointer */
  #define TSTMR0__TIMESTAMP0                       ((TSTMR_Type *)TSTMR0__TIMESTAMP0_BASE)
  /** Peripheral TSTMR0__TIMESTAMP0 base pointer */
  #define TSTMR0__TIMESTAMP0_NS                    ((TSTMR_Type *)TSTMR0__TIMESTAMP0_BASE_NS)
  /** Peripheral TSTMR1__TIMESTAMP0 base address */
  #define TSTMR1__TIMESTAMP0_BASE                  (0x39290C00u)
  /** Peripheral TSTMR1__TIMESTAMP0 base address */
  #define TSTMR1__TIMESTAMP0_BASE_NS               (0x29290C00u)
  /** Peripheral TSTMR1__TIMESTAMP0 base pointer */
  #define TSTMR1__TIMESTAMP0                       ((TSTMR_Type *)TSTMR1__TIMESTAMP0_BASE)
  /** Peripheral TSTMR1__TIMESTAMP0 base pointer */
  #define TSTMR1__TIMESTAMP0_NS                    ((TSTMR_Type *)TSTMR1__TIMESTAMP0_BASE_NS)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { TSTMR0__TIMESTAMP0_BASE, TSTMR1__TIMESTAMP0_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { TSTMR0__TIMESTAMP0, TSTMR1__TIMESTAMP0 }
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS_NS                      { TSTMR0__TIMESTAMP0_BASE_NS, TSTMR1__TIMESTAMP0_BASE_NS }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS_NS                       { TSTMR0__TIMESTAMP0_NS, TSTMR1__TIMESTAMP0_NS }
#else
  /** Peripheral TSTMR0__TIMESTAMP0 base address */
  #define TSTMR0__TIMESTAMP0_BASE                  (0x2802AC00u)
  /** Peripheral TSTMR0__TIMESTAMP0 base pointer */
  #define TSTMR0__TIMESTAMP0                       ((TSTMR_Type *)TSTMR0__TIMESTAMP0_BASE)
  /** Peripheral TSTMR1__TIMESTAMP0 base address */
  #define TSTMR1__TIMESTAMP0_BASE                  (0x29290C00u)
  /** Peripheral TSTMR1__TIMESTAMP0 base pointer */
  #define TSTMR1__TIMESTAMP0                       ((TSTMR_Type *)TSTMR1__TIMESTAMP0_BASE)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { TSTMR0__TIMESTAMP0_BASE, TSTMR1__TIMESTAMP0_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { TSTMR0__TIMESTAMP0, TSTMR1__TIMESTAMP0 }
#endif

/* USB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USB0 base address */
  #define USB0_BASE                                (0x39900000u)
  /** Peripheral USB0 base address */
  #define USB0_BASE_NS                             (0x29900000u)
  /** Peripheral USB0 base pointer */
  #define USB0                                     ((USB_Type *)USB0_BASE)
  /** Peripheral USB0 base pointer */
  #define USB0_NS                                  ((USB_Type *)USB0_BASE_NS)
  /** Peripheral USB1 base address */
  #define USB1_BASE                                (0x39920000u)
  /** Peripheral USB1 base address */
  #define USB1_BASE_NS                             (0x29920000u)
  /** Peripheral USB1 base pointer */
  #define USB1                                     ((USB_Type *)USB1_BASE)
  /** Peripheral USB1 base pointer */
  #define USB1_NS                                  ((USB_Type *)USB1_BASE_NS)
  /** Peripheral USB_XBAR base address */
  #define USB_XBAR_BASE                            (0x39940000u)
  /** Peripheral USB_XBAR base address */
  #define USB_XBAR_BASE_NS                         (0x29940000u)
  /** Peripheral USB_XBAR base pointer */
  #define USB_XBAR                                 ((USB_Type *)USB_XBAR_BASE)
  /** Peripheral USB_XBAR base pointer */
  #define USB_XBAR_NS                              ((USB_Type *)USB_XBAR_BASE_NS)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { USB0_BASE, USB1_BASE, USB_XBAR_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { USB0, USB1, USB_XBAR }
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS_NS                        { USB0_BASE_NS, USB1_BASE_NS, USB_XBAR_BASE_NS }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS_NS                         { USB0_NS, USB1_NS, USB_XBAR_NS }
#else
  /** Peripheral USB0 base address */
  #define USB0_BASE                                (0x29900000u)
  /** Peripheral USB0 base pointer */
  #define USB0                                     ((USB_Type *)USB0_BASE)
  /** Peripheral USB1 base address */
  #define USB1_BASE                                (0x29920000u)
  /** Peripheral USB1 base pointer */
  #define USB1                                     ((USB_Type *)USB1_BASE)
  /** Peripheral USB_XBAR base address */
  #define USB_XBAR_BASE                            (0x29940000u)
  /** Peripheral USB_XBAR base pointer */
  #define USB_XBAR                                 ((USB_Type *)USB_XBAR_BASE)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { USB0_BASE, USB1_BASE, USB_XBAR_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { USB0, USB1, USB_XBAR }
#endif
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { USB0_IRQn, USB1_IRQn, NotAvail_IRQn }

/* USBHSDCD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBDCD0 base address */
  #define USBDCD0_BASE                             (0x39910800u)
  /** Peripheral USBDCD0 base address */
  #define USBDCD0_BASE_NS                          (0x29910800u)
  /** Peripheral USBDCD0 base pointer */
  #define USBDCD0                                  ((USBHSDCD_Type *)USBDCD0_BASE)
  /** Peripheral USBDCD0 base pointer */
  #define USBDCD0_NS                               ((USBHSDCD_Type *)USBDCD0_BASE_NS)
  /** Peripheral USBDCD1 base address */
  #define USBDCD1_BASE                             (0x39930800u)
  /** Peripheral USBDCD1 base address */
  #define USBDCD1_BASE_NS                          (0x29930800u)
  /** Peripheral USBDCD1 base pointer */
  #define USBDCD1                                  ((USBHSDCD_Type *)USBDCD1_BASE)
  /** Peripheral USBDCD1 base pointer */
  #define USBDCD1_NS                               ((USBHSDCD_Type *)USBDCD1_BASE_NS)
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS                      { USBDCD0_BASE, USBDCD1_BASE }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS                       { USBDCD0, USBDCD1 }
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS_NS                   { USBDCD0_BASE_NS, USBDCD1_BASE_NS }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS_NS                    { USBDCD0_NS, USBDCD1_NS }
#else
  /** Peripheral USBDCD0 base address */
  #define USBDCD0_BASE                             (0x29910800u)
  /** Peripheral USBDCD0 base pointer */
  #define USBDCD0                                  ((USBHSDCD_Type *)USBDCD0_BASE)
  /** Peripheral USBDCD1 base address */
  #define USBDCD1_BASE                             (0x29930800u)
  /** Peripheral USBDCD1 base pointer */
  #define USBDCD1                                  ((USBHSDCD_Type *)USBDCD1_BASE)
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS                      { USBDCD0_BASE, USBDCD1_BASE }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS                       { USBDCD0, USBDCD1 }
#endif

/* USBNC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBNC0 base address */
  #define USBNC0_BASE                              (0x39900200u)
  /** Peripheral USBNC0 base address */
  #define USBNC0_BASE_NS                           (0x29900200u)
  /** Peripheral USBNC0 base pointer */
  #define USBNC0                                   ((USBNC_Type *)USBNC0_BASE)
  /** Peripheral USBNC0 base pointer */
  #define USBNC0_NS                                ((USBNC_Type *)USBNC0_BASE_NS)
  /** Peripheral USBNC1 base address */
  #define USBNC1_BASE                              (0x39920200u)
  /** Peripheral USBNC1 base address */
  #define USBNC1_BASE_NS                           (0x29920200u)
  /** Peripheral USBNC1 base pointer */
  #define USBNC1                                   ((USBNC_Type *)USBNC1_BASE)
  /** Peripheral USBNC1 base pointer */
  #define USBNC1_NS                                ((USBNC_Type *)USBNC1_BASE_NS)
  /** Peripheral USBNC_XBAR base address */
  #define USBNC_XBAR_BASE                          (0x39940200u)
  /** Peripheral USBNC_XBAR base address */
  #define USBNC_XBAR_BASE_NS                       (0x29940200u)
  /** Peripheral USBNC_XBAR base pointer */
  #define USBNC_XBAR                               ((USBNC_Type *)USBNC_XBAR_BASE)
  /** Peripheral USBNC_XBAR base pointer */
  #define USBNC_XBAR_NS                            ((USBNC_Type *)USBNC_XBAR_BASE_NS)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { USBNC0_BASE, USBNC1_BASE, USBNC_XBAR_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { USBNC0, USBNC1, USBNC_XBAR }
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS_NS                      { USBNC0_BASE_NS, USBNC1_BASE_NS, USBNC_XBAR_BASE_NS }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS_NS                       { USBNC0_NS, USBNC1_NS, USBNC_XBAR_NS }
#else
  /** Peripheral USBNC0 base address */
  #define USBNC0_BASE                              (0x29900200u)
  /** Peripheral USBNC0 base pointer */
  #define USBNC0                                   ((USBNC_Type *)USBNC0_BASE)
  /** Peripheral USBNC1 base address */
  #define USBNC1_BASE                              (0x29920200u)
  /** Peripheral USBNC1 base pointer */
  #define USBNC1                                   ((USBNC_Type *)USBNC1_BASE)
  /** Peripheral USBNC_XBAR base address */
  #define USBNC_XBAR_BASE                          (0x29940200u)
  /** Peripheral USBNC_XBAR base pointer */
  #define USBNC_XBAR                               ((USBNC_Type *)USBNC_XBAR_BASE)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { USBNC0_BASE, USBNC1_BASE, USBNC_XBAR_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { USBNC0, USBNC1, USBNC_XBAR }
#endif

/* USBPHY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USB0_PHY base address */
  #define USB0_PHY_BASE                            (0x39910000u)
  /** Peripheral USB0_PHY base address */
  #define USB0_PHY_BASE_NS                         (0x29910000u)
  /** Peripheral USB0_PHY base pointer */
  #define USB0_PHY                                 ((USBPHY_Type *)USB0_PHY_BASE)
  /** Peripheral USB0_PHY base pointer */
  #define USB0_PHY_NS                              ((USBPHY_Type *)USB0_PHY_BASE_NS)
  /** Peripheral USB1_PHY base address */
  #define USB1_PHY_BASE                            (0x39930000u)
  /** Peripheral USB1_PHY base address */
  #define USB1_PHY_BASE_NS                         (0x29930000u)
  /** Peripheral USB1_PHY base pointer */
  #define USB1_PHY                                 ((USBPHY_Type *)USB1_PHY_BASE)
  /** Peripheral USB1_PHY base pointer */
  #define USB1_PHY_NS                              ((USBPHY_Type *)USB1_PHY_BASE_NS)
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS                        { USB0_PHY_BASE, USB1_PHY_BASE }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS                         { USB0_PHY, USB1_PHY }
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS_NS                     { USB0_PHY_BASE_NS, USB1_PHY_BASE_NS }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS_NS                      { USB0_PHY_NS, USB1_PHY_NS }
#else
  /** Peripheral USB0_PHY base address */
  #define USB0_PHY_BASE                            (0x29910000u)
  /** Peripheral USB0_PHY base pointer */
  #define USB0_PHY                                 ((USBPHY_Type *)USB0_PHY_BASE)
  /** Peripheral USB1_PHY base address */
  #define USB1_PHY_BASE                            (0x29930000u)
  /** Peripheral USB1_PHY base pointer */
  #define USB1_PHY                                 ((USBPHY_Type *)USB1_PHY_BASE)
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS                        { USB0_PHY_BASE, USB1_PHY_BASE }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS                         { USB0_PHY, USB1_PHY }
#endif
/** Interrupt vectors for the USBPHY peripheral type */
#define USBPHY_IRQS                              { USBPHY0_IRQn, USBPHY1_IRQn }
/* Backward compatibility */
#define USBPHY_CTRL_ENDEVPLUGINDET_MASK     USBPHY_CTRL_ENDEVPLUGINDETECT_MASK
#define USBPHY_CTRL_ENDEVPLUGINDET_SHIFT    USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT
#define USBPHY_CTRL_ENDEVPLUGINDET(x)       USBPHY_CTRL_ENDEVPLUGINDETECT(x)
#define USBPHY_TX_TXCAL45DM_MASK            USBPHY_TX_TXCAL45DN_MASK
#define USBPHY_TX_TXCAL45DM_SHIFT           USBPHY_TX_TXCAL45DN_SHIFT
#define USBPHY_TX_TXCAL45DM(x)              USBPHY_TX_TXCAL45DN(x)


/* USDHC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USDHC0 base address */
  #define USDHC0_BASE                              (0x398D0000u)
  /** Peripheral USDHC0 base address */
  #define USDHC0_BASE_NS                           (0x298D0000u)
  /** Peripheral USDHC0 base pointer */
  #define USDHC0                                   ((USDHC_Type *)USDHC0_BASE)
  /** Peripheral USDHC0 base pointer */
  #define USDHC0_NS                                ((USDHC_Type *)USDHC0_BASE_NS)
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE                              (0x398E0000u)
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE_NS                           (0x298E0000u)
  /** Peripheral USDHC1 base pointer */
  #define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
  /** Peripheral USDHC1 base pointer */
  #define USDHC1_NS                                ((USDHC_Type *)USDHC1_BASE_NS)
  /** Peripheral USDHC2 base address */
  #define USDHC2_BASE                              (0x398F0000u)
  /** Peripheral USDHC2 base address */
  #define USDHC2_BASE_NS                           (0x298F0000u)
  /** Peripheral USDHC2 base pointer */
  #define USDHC2                                   ((USDHC_Type *)USDHC2_BASE)
  /** Peripheral USDHC2 base pointer */
  #define USDHC2_NS                                ((USDHC_Type *)USDHC2_BASE_NS)
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS                         { USDHC0_BASE, USDHC1_BASE, USDHC2_BASE }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS                          { USDHC0, USDHC1, USDHC2 }
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS_NS                      { USDHC0_BASE_NS, USDHC1_BASE_NS, USDHC2_BASE_NS }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS_NS                       { USDHC0_NS, USDHC1_NS, USDHC2_NS }
#else
  /** Peripheral USDHC0 base address */
  #define USDHC0_BASE                              (0x298D0000u)
  /** Peripheral USDHC0 base pointer */
  #define USDHC0                                   ((USDHC_Type *)USDHC0_BASE)
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE                              (0x298E0000u)
  /** Peripheral USDHC1 base pointer */
  #define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
  /** Peripheral USDHC2 base address */
  #define USDHC2_BASE                              (0x298F0000u)
  /** Peripheral USDHC2 base pointer */
  #define USDHC2                                   ((USDHC_Type *)USDHC2_BASE)
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS                         { USDHC0_BASE, USDHC1_BASE, USDHC2_BASE }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS                          { USDHC0, USDHC1, USDHC2 }
#endif
/** Interrupt vectors for the USDHC peripheral type */
#define USDHC_IRQS                               { uSDHC0_IRQn, uSDHC1_IRQn, uSDHC2_IRQn }

/* WDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WDOG0 base address */
  #define WDOG0_BASE                               (0x3802C000u)
  /** Peripheral WDOG0 base address */
  #define WDOG0_BASE_NS                            (0x2802C000u)
  /** Peripheral WDOG0 base pointer */
  #define WDOG0                                    ((WDOG_Type *)WDOG0_BASE)
  /** Peripheral WDOG0 base pointer */
  #define WDOG0_NS                                 ((WDOG_Type *)WDOG0_BASE_NS)
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE                               (0x3802D000u)
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE_NS                            (0x2802D000u)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1_NS                                 ((WDOG_Type *)WDOG1_BASE_NS)
  /** Peripheral WDOG2 base address */
  #define WDOG2_BASE                               (0x38101000u)
  /** Peripheral WDOG2 base address */
  #define WDOG2_BASE_NS                            (0x28101000u)
  /** Peripheral WDOG2 base pointer */
  #define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
  /** Peripheral WDOG2 base pointer */
  #define WDOG2_NS                                 ((WDOG_Type *)WDOG2_BASE_NS)
  /** Peripheral WDOG3 base address */
  #define WDOG3_BASE                               (0x392A0000u)
  /** Peripheral WDOG3 base address */
  #define WDOG3_BASE_NS                            (0x292A0000u)
  /** Peripheral WDOG3 base pointer */
  #define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
  /** Peripheral WDOG3 base pointer */
  #define WDOG3_NS                                 ((WDOG_Type *)WDOG3_BASE_NS)
  /** Peripheral WDOG4 base address */
  #define WDOG4_BASE                               (0x392B0000u)
  /** Peripheral WDOG4 base address */
  #define WDOG4_BASE_NS                            (0x292B0000u)
  /** Peripheral WDOG4 base pointer */
  #define WDOG4                                    ((WDOG_Type *)WDOG4_BASE)
  /** Peripheral WDOG4 base pointer */
  #define WDOG4_NS                                 ((WDOG_Type *)WDOG4_BASE_NS)
  /** Peripheral WDOG5 base address */
  #define WDOG5_BASE                               (0x3DB20000u)
  /** Peripheral WDOG5 base address */
  #define WDOG5_BASE_NS                            (0x2DB20000u)
  /** Peripheral WDOG5 base pointer */
  #define WDOG5                                    ((WDOG_Type *)WDOG5_BASE)
  /** Peripheral WDOG5 base pointer */
  #define WDOG5_NS                                 ((WDOG_Type *)WDOG5_BASE_NS)
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS                          { WDOG0_BASE, WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS                           { WDOG0, WDOG1, WDOG2, WDOG3, WDOG4, WDOG5 }
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS_NS                       { WDOG0_BASE_NS, WDOG1_BASE_NS, WDOG2_BASE_NS, WDOG3_BASE_NS, WDOG4_BASE_NS, WDOG5_BASE_NS }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS_NS                        { WDOG0_NS, WDOG1_NS, WDOG2_NS, WDOG3_NS, WDOG4_NS, WDOG5_NS }
#else
  /** Peripheral WDOG0 base address */
  #define WDOG0_BASE                               (0x2802C000u)
  /** Peripheral WDOG0 base pointer */
  #define WDOG0                                    ((WDOG_Type *)WDOG0_BASE)
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE                               (0x2802D000u)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
  /** Peripheral WDOG2 base address */
  #define WDOG2_BASE                               (0x28101000u)
  /** Peripheral WDOG2 base pointer */
  #define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
  /** Peripheral WDOG3 base address */
  #define WDOG3_BASE                               (0x292A0000u)
  /** Peripheral WDOG3 base pointer */
  #define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
  /** Peripheral WDOG4 base address */
  #define WDOG4_BASE                               (0x292B0000u)
  /** Peripheral WDOG4 base pointer */
  #define WDOG4                                    ((WDOG_Type *)WDOG4_BASE)
  /** Peripheral WDOG5 base address */
  #define WDOG5_BASE                               (0x2DB20000u)
  /** Peripheral WDOG5 base pointer */
  #define WDOG5                                    ((WDOG_Type *)WDOG5_BASE)
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS                          { WDOG0_BASE, WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS                           { WDOG0, WDOG1, WDOG2, WDOG3, WDOG4, WDOG5 }
#endif
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { WDOG0_IRQn, WDOG1_IRQn, WDOG2_IRQn, WDOG3_IRQn, WDOG4_IRQn, NotAvail_IRQn }

/* WUU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WUU0 base address */
  #define WUU0_BASE                                (0x38028000u)
  /** Peripheral WUU0 base address */
  #define WUU0_BASE_NS                             (0x28028000u)
  /** Peripheral WUU0 base pointer */
  #define WUU0                                     ((WUU_Type *)WUU0_BASE)
  /** Peripheral WUU0 base pointer */
  #define WUU0_NS                                  ((WUU_Type *)WUU0_BASE_NS)
  /** Peripheral WUU1 base address */
  #define WUU1_BASE                                (0x39260000u)
  /** Peripheral WUU1 base address */
  #define WUU1_BASE_NS                             (0x29260000u)
  /** Peripheral WUU1 base pointer */
  #define WUU1                                     ((WUU_Type *)WUU1_BASE)
  /** Peripheral WUU1 base pointer */
  #define WUU1_NS                                  ((WUU_Type *)WUU1_BASE_NS)
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS                           { WUU0_BASE, WUU1_BASE }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS                            { WUU0, WUU1 }
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS_NS                        { WUU0_BASE_NS, WUU1_BASE_NS }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS_NS                         { WUU0_NS, WUU1_NS }
#else
  /** Peripheral WUU0 base address */
  #define WUU0_BASE                                (0x28028000u)
  /** Peripheral WUU0 base pointer */
  #define WUU0                                     ((WUU_Type *)WUU0_BASE)
  /** Peripheral WUU1 base address */
  #define WUU1_BASE                                (0x29260000u)
  /** Peripheral WUU1 base pointer */
  #define WUU1                                     ((WUU_Type *)WUU1_BASE)
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS                           { WUU0_BASE, WUU1_BASE }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS                            { WUU0, WUU1 }
#endif
/** Interrupt vectors for the WUU peripheral type */
#define WUU_IRQS                                 { WUU0_IRQn, NotAvail_IRQn }

/* XRDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XRDC base address */
  #define XRDC_BASE                                (0x392F0000u)
  /** Peripheral XRDC base address */
  #define XRDC_BASE_NS                             (0x292F0000u)
  /** Peripheral XRDC base pointer */
  #define XRDC                                     ((XRDC_Type *)XRDC_BASE)
  /** Peripheral XRDC base pointer */
  #define XRDC_NS                                  ((XRDC_Type *)XRDC_BASE_NS)
  /** Array initializer of XRDC peripheral base addresses */
  #define XRDC_BASE_ADDRS                          { XRDC_BASE }
  /** Array initializer of XRDC peripheral base pointers */
  #define XRDC_BASE_PTRS                           { XRDC }
  /** Array initializer of XRDC peripheral base addresses */
  #define XRDC_BASE_ADDRS_NS                       { XRDC_BASE_NS }
  /** Array initializer of XRDC peripheral base pointers */
  #define XRDC_BASE_PTRS_NS                        { XRDC_NS }
#else
  /** Peripheral XRDC base address */
  #define XRDC_BASE                                (0x292F0000u)
  /** Peripheral XRDC base pointer */
  #define XRDC                                     ((XRDC_Type *)XRDC_BASE)
  /** Array initializer of XRDC peripheral base addresses */
  #define XRDC_BASE_ADDRS                          { XRDC_BASE }
  /** Array initializer of XRDC peripheral base pointers */
  #define XRDC_BASE_PTRS                           { XRDC }
#endif
/** Interrupt vectors for the XRDC peripheral type */
#define XRDC_IRQS                                { XRDC_IRQn }

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


#endif  /* MIMX8UD5_CM33_COMMON_H_ */

