/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    iMXRT500RM Rev.1, 07/2022
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT533S
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
 * @file MIMXRT533S_COMMON.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMXRT533S
 *
 * CMSIS Peripheral Access Layer for MIMXRT533S
 */

#if !defined(MIMXRT533S_COMMON_H_)
#define MIMXRT533S_COMMON_H_                     /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 90                 /**< Number of interrupts in the Vector table */

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
  WDT0_IRQn                    = 0,                /**< Watchdog timer interrupt */
  DMA0_IRQn                    = 1,                /**< DMA interrupt */
  GPIO_INTA_IRQn               = 2,                /**< GPIO Interrupt A */
  GPIO_INTB_IRQn               = 3,                /**< GPIO Interrupt B */
  PIN_INT0_IRQn                = 4,                /**< General Purpose Input/Output interrupt 0 */
  PIN_INT1_IRQn                = 5,                /**< General Purpose Input/Output interrupt 1 */
  PIN_INT2_IRQn                = 6,                /**< General Purpose Input/Output interrupt 2 */
  PIN_INT3_IRQn                = 7,                /**< General Purpose Input/Output interrupt 3 */
  UTICK0_IRQn                  = 8,                /**< Micro-tick Timer */
  MRT0_IRQn                    = 9,                /**< Multi-Rate Timer */
  CTIMER0_IRQn                 = 10,               /**< Standard counter/timer CTIMER0 */
  CTIMER1_IRQn                 = 11,               /**< Standard counter/timer CTIMER1 */
  SCT0_IRQn                    = 12,               /**< SCTimer/PWM */
  CTIMER3_IRQn                 = 13,               /**< Standard counter/timer CTIMER3 */
  FLEXCOMM0_IRQn               = 14,               /**< FlexComm interrupt */
  FLEXCOMM1_IRQn               = 15,               /**< FlexComm interrupt */
  FLEXCOMM2_IRQn               = 16,               /**< FlexComm interrupt */
  FLEXCOMM3_IRQn               = 17,               /**< FlexComm interrupt */
  FLEXCOMM4_IRQn               = 18,               /**< FlexComm interrupt */
  FLEXCOMM5_IRQn               = 19,               /**< FlexComm interrupt */
  FLEXCOMM14_IRQn              = 20,               /**< FlexComm interrupt. Standalone SPI */
  FLEXCOMM15_IRQn              = 21,               /**< FlexComm interrupt. Standalone I2C */
  ADC0_IRQn                    = 22,               /**< Analog-to-Digital Converter interrupt */
  Reserved39_IRQn              = 23,               /**< Reserved interrupt */
  ACMP_IRQn                    = 24,               /**< Analog comparator Interrupts */
  DMIC0_IRQn                   = 25,               /**< Digital Microphone Interface interrupt */
  Reserved42_IRQn              = 26,               /**< Reserved interrupt */
  HYPERVISOR_IRQn              = 27,               /**< Hypervisor interrupt */
  SECURE_VIOLATION_IRQn        = 28,               /**< Secure violation interrupt */
  HWVAD0_IRQn                  = 29,               /**< Hardware Voice Activity Detector interrupt */
  Reserved46_IRQn              = 30,               /**< Reserved interrupt */
  RNG_IRQn                     = 31,               /**< Random Number Generator interrupt */
  RTC_IRQn                     = 32,               /**< Real Time Clock Alarm interrupt OR Wakeup timer interrupt */
  MU_A_IRQn                    = 34,               /**< Messaging Unit - Side A */
  PIN_INT4_IRQn                = 35,               /**< General Purpose Input/Output interrupt 4 */
  PIN_INT5_IRQn                = 36,               /**< General Purpose Input/Output interrupt 5 */
  PIN_INT6_IRQn                = 37,               /**< General Purpose Input/Output interrupt 6 */
  PIN_INT7_IRQn                = 38,               /**< General Purpose Input/Output interrupt 7 */
  CTIMER2_IRQn                 = 39,               /**< Standard counter/timer CTIMER2 */
  CTIMER4_IRQn                 = 40,               /**< Standard counter/timer CTIMER4 */
  OS_EVENT_IRQn                = 41,               /**< Event timer M33 Wakeup/interrupt */
  FLEXSPI0_FLEXSPI1_IRQn       = 42,               /**< FlexSPI0_IRQ OR FlexSPI1_IRQ */
  FLEXCOMM6_IRQn               = 43,               /**< FlexComm interrupt */
  FLEXCOMM7_IRQn               = 44,               /**< FlexComm interrupt */
  USDHC0_IRQn                  = 45,               /**< USDHC interrupt */
  USDHC1_IRQn                  = 46,               /**< USDHC interrupt */
  SGPIO_INTA_IRQn              = 47,               /**< Secure GPIO HS interrupt 0 */
  SGPIO_INTB_IRQn              = 48,               /**< Secure GPIO HS interrupt 1 */
  I3C0_IRQn                    = 49,               /**< Improved Inter Integrated Circuit 0 interrupt */
  USB0_IRQn                    = 50,               /**< USB device */
  USB0_NEEDCLK_IRQn            = 51,               /**< USB Activity Wake-up Interrupt */
  WDT1_IRQn                    = 52,               /**< Watchdog timer 1 interrupt */
  USB_PHYDCD_IRQn              = 53,               /**< USBPHY DCD interrupt */
  DMA1_IRQn                    = 54,               /**< DMA interrupt */
  PUF_IRQn                     = 55,               /**< QuidKey interrupt */
  POWERQUAD_IRQn               = 56,               /**< Powerquad interrupt */
  CASPER_IRQn                  = 57,               /**< Caspar interrupt */
  PMU_PMIC_IRQn                = 58,               /**< Power Management Control interrupt */
  HASHCRYPT_IRQn               = 59,               /**< SHA interrupt */
  FLEXCOMM8_IRQn               = 60,               /**< FlexComm interrupt */
  FLEXCOMM9_IRQn               = 61,               /**< FlexComm interrupt */
  FLEXCOMM10_IRQn              = 62,               /**< FlexComm interrupt */
  FLEXCOMM11_IRQn              = 63,               /**< FlexComm interrupt */
  FLEXCOMM12_IRQn              = 64,               /**< FlexComm interrupt */
  FLEXCOMM13_IRQn              = 65,               /**< FlexComm interrupt */
  FLEXCOMM16_IRQn              = 66,               /**< FlexComm interrupt */
  I3C1_IRQn                    = 67,               /**< Improved Inter Integrated Circuit 1 interrupt */
  FLEXIO_IRQn                  = 68,               /**< Flexible I/O interrupt */
  Reserved88_IRQn              = 72,
  SDMA_IRQn                    = 73                /**< Smart DMA Engine Controller interrupt */
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
#include "system_MIMXRT533S.h"         /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMXRT533S_SERIES
#define MIMXRT533S_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMXRT533S_features.h"

/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADC0 base address */
  #define ADC0_BASE                                (0x5013A000u)
  /** Peripheral ADC0 base address */
  #define ADC0_BASE_NS                             (0x4013A000u)
  /** Peripheral ADC0 base pointer */
  #define ADC0                                     ((ADC_Type *)ADC0_BASE)
  /** Peripheral ADC0 base pointer */
  #define ADC0_NS                                  ((ADC_Type *)ADC0_BASE_NS)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC0_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC0 }
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS_NS                        { ADC0_BASE_NS }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS_NS                         { ADC0_NS }
#else
  /** Peripheral ADC0 base address */
  #define ADC0_BASE                                (0x4013A000u)
  /** Peripheral ADC0 base pointer */
  #define ADC0                                     ((ADC_Type *)ADC0_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC0_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC0 }
#endif
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn }

/* AHB_SECURE_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AHB_SECURE_CTRL base address */
  #define AHB_SECURE_CTRL_BASE                     (0x50148000u)
  /** Peripheral AHB_SECURE_CTRL base address */
  #define AHB_SECURE_CTRL_BASE_NS                  (0x40148000u)
  /** Peripheral AHB_SECURE_CTRL base pointer */
  #define AHB_SECURE_CTRL                          ((AHB_SECURE_CTRL_Type *)AHB_SECURE_CTRL_BASE)
  /** Peripheral AHB_SECURE_CTRL base pointer */
  #define AHB_SECURE_CTRL_NS                       ((AHB_SECURE_CTRL_Type *)AHB_SECURE_CTRL_BASE_NS)
  /** Array initializer of AHB_SECURE_CTRL peripheral base addresses */
  #define AHB_SECURE_CTRL_BASE_ADDRS               { AHB_SECURE_CTRL_BASE }
  /** Array initializer of AHB_SECURE_CTRL peripheral base pointers */
  #define AHB_SECURE_CTRL_BASE_PTRS                { AHB_SECURE_CTRL }
  /** Array initializer of AHB_SECURE_CTRL peripheral base addresses */
  #define AHB_SECURE_CTRL_BASE_ADDRS_NS            { AHB_SECURE_CTRL_BASE_NS }
  /** Array initializer of AHB_SECURE_CTRL peripheral base pointers */
  #define AHB_SECURE_CTRL_BASE_PTRS_NS             { AHB_SECURE_CTRL_NS }
#else
  /** Peripheral AHB_SECURE_CTRL base address */
  #define AHB_SECURE_CTRL_BASE                     (0x40148000u)
  /** Peripheral AHB_SECURE_CTRL base pointer */
  #define AHB_SECURE_CTRL                          ((AHB_SECURE_CTRL_Type *)AHB_SECURE_CTRL_BASE)
  /** Array initializer of AHB_SECURE_CTRL peripheral base addresses */
  #define AHB_SECURE_CTRL_BASE_ADDRS               { AHB_SECURE_CTRL_BASE }
  /** Array initializer of AHB_SECURE_CTRL peripheral base pointers */
  #define AHB_SECURE_CTRL_BASE_PTRS                { AHB_SECURE_CTRL }
#endif

/* AXI_SWITCH_AMIB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AXI_SWITCH_AMIB base address */
  #define AXI_SWITCH_AMIB_BASE                     (0x50282000u)
  /** Peripheral AXI_SWITCH_AMIB base address */
  #define AXI_SWITCH_AMIB_BASE_NS                  (0x40282000u)
  /** Peripheral AXI_SWITCH_AMIB base pointer */
  #define AXI_SWITCH_AMIB                          ((AXI_SWITCH_AMIB_Type *)AXI_SWITCH_AMIB_BASE)
  /** Peripheral AXI_SWITCH_AMIB base pointer */
  #define AXI_SWITCH_AMIB_NS                       ((AXI_SWITCH_AMIB_Type *)AXI_SWITCH_AMIB_BASE_NS)
  /** Array initializer of AXI_SWITCH_AMIB peripheral base addresses */
  #define AXI_SWITCH_AMIB_BASE_ADDRS               { AXI_SWITCH_AMIB_BASE }
  /** Array initializer of AXI_SWITCH_AMIB peripheral base pointers */
  #define AXI_SWITCH_AMIB_BASE_PTRS                { AXI_SWITCH_AMIB }
  /** Array initializer of AXI_SWITCH_AMIB peripheral base addresses */
  #define AXI_SWITCH_AMIB_BASE_ADDRS_NS            { AXI_SWITCH_AMIB_BASE_NS }
  /** Array initializer of AXI_SWITCH_AMIB peripheral base pointers */
  #define AXI_SWITCH_AMIB_BASE_PTRS_NS             { AXI_SWITCH_AMIB_NS }
#else
  /** Peripheral AXI_SWITCH_AMIB base address */
  #define AXI_SWITCH_AMIB_BASE                     (0x40282000u)
  /** Peripheral AXI_SWITCH_AMIB base pointer */
  #define AXI_SWITCH_AMIB                          ((AXI_SWITCH_AMIB_Type *)AXI_SWITCH_AMIB_BASE)
  /** Array initializer of AXI_SWITCH_AMIB peripheral base addresses */
  #define AXI_SWITCH_AMIB_BASE_ADDRS               { AXI_SWITCH_AMIB_BASE }
  /** Array initializer of AXI_SWITCH_AMIB peripheral base pointers */
  #define AXI_SWITCH_AMIB_BASE_PTRS                { AXI_SWITCH_AMIB }
#endif

/* AXI_SWITCH_ASIB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AXI_SWITCH_ASIB base address */
  #define AXI_SWITCH_ASIB_BASE                     (0x502C2000u)
  /** Peripheral AXI_SWITCH_ASIB base address */
  #define AXI_SWITCH_ASIB_BASE_NS                  (0x402C2000u)
  /** Peripheral AXI_SWITCH_ASIB base pointer */
  #define AXI_SWITCH_ASIB                          ((AXI_SWITCH_ASIB_Type *)AXI_SWITCH_ASIB_BASE)
  /** Peripheral AXI_SWITCH_ASIB base pointer */
  #define AXI_SWITCH_ASIB_NS                       ((AXI_SWITCH_ASIB_Type *)AXI_SWITCH_ASIB_BASE_NS)
  /** Array initializer of AXI_SWITCH_ASIB peripheral base addresses */
  #define AXI_SWITCH_ASIB_BASE_ADDRS               { AXI_SWITCH_ASIB_BASE }
  /** Array initializer of AXI_SWITCH_ASIB peripheral base pointers */
  #define AXI_SWITCH_ASIB_BASE_PTRS                { AXI_SWITCH_ASIB }
  /** Array initializer of AXI_SWITCH_ASIB peripheral base addresses */
  #define AXI_SWITCH_ASIB_BASE_ADDRS_NS            { AXI_SWITCH_ASIB_BASE_NS }
  /** Array initializer of AXI_SWITCH_ASIB peripheral base pointers */
  #define AXI_SWITCH_ASIB_BASE_PTRS_NS             { AXI_SWITCH_ASIB_NS }
#else
  /** Peripheral AXI_SWITCH_ASIB base address */
  #define AXI_SWITCH_ASIB_BASE                     (0x402C2000u)
  /** Peripheral AXI_SWITCH_ASIB base pointer */
  #define AXI_SWITCH_ASIB                          ((AXI_SWITCH_ASIB_Type *)AXI_SWITCH_ASIB_BASE)
  /** Array initializer of AXI_SWITCH_ASIB peripheral base addresses */
  #define AXI_SWITCH_ASIB_BASE_ADDRS               { AXI_SWITCH_ASIB_BASE }
  /** Array initializer of AXI_SWITCH_ASIB peripheral base pointers */
  #define AXI_SWITCH_ASIB_BASE_PTRS                { AXI_SWITCH_ASIB }
#endif

/* CACHE64_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CACHE64_CTRL0 base address */
  #define CACHE64_CTRL0_BASE                       (0x50033000u)
  /** Peripheral CACHE64_CTRL0 base address */
  #define CACHE64_CTRL0_BASE_NS                    (0x40033000u)
  /** Peripheral CACHE64_CTRL0 base pointer */
  #define CACHE64_CTRL0                            ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE)
  /** Peripheral CACHE64_CTRL0 base pointer */
  #define CACHE64_CTRL0_NS                         ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE_NS)
  /** Peripheral CACHE64_CTRL1 base address */
  #define CACHE64_CTRL1_BASE                       (0x50034000u)
  /** Peripheral CACHE64_CTRL1 base address */
  #define CACHE64_CTRL1_BASE_NS                    (0x40034000u)
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
#endif
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** CACHE64_CTRL physical memory base address */
 #define CACHE64_CTRL_PHYMEM_BASES                { 0x18000000u, 0x38000000u }
/** CACHE64_CTRL physical memory size */
 #define CACHE64_CTRL_PHYMEM_SIZES                { 0x08000000u, 0x08000000u }
/** CACHE64_CTRL physical memory base address */
 #define CACHE64_CTRL_PHYMEM_BASES_NS             { 0x08000000u, 0x28000000u }
/** CACHE64_CTRL physical memory size */
 #define CACHE64_CTRL_PHYMEM_SIZES_NS             { 0x08000000u, 0x08000000u }
#else
/** CACHE64_CTRL physical memory base address */
 #define CACHE64_CTRL_PHYMEM_BASES                { 0x08000000u, 0x28000000u }
/** CACHE64_CTRL physical memory size */
 #define CACHE64_CTRL_PHYMEM_SIZES                { 0x08000000u, 0x08000000u }
#endif
/* Backward compatibility */
#define CACHE64_CTRL_CSAR_PHYADDR_MASK (CACHE64_CTRL_CSAR_PHYADDR27_1_MASK | CACHE64_CTRL_CSAR_PHYADDR31_29_MASK)


/* CACHE64_POLSEL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CACHE64_POLSEL0 base address */
  #define CACHE64_POLSEL0_BASE                     (0x50033000u)
  /** Peripheral CACHE64_POLSEL0 base address */
  #define CACHE64_POLSEL0_BASE_NS                  (0x40033000u)
  /** Peripheral CACHE64_POLSEL0 base pointer */
  #define CACHE64_POLSEL0                          ((CACHE64_POLSEL_Type *)CACHE64_POLSEL0_BASE)
  /** Peripheral CACHE64_POLSEL0 base pointer */
  #define CACHE64_POLSEL0_NS                       ((CACHE64_POLSEL_Type *)CACHE64_POLSEL0_BASE_NS)
  /** Peripheral CACHE64_POLSEL1 base address */
  #define CACHE64_POLSEL1_BASE                     (0x50034000u)
  /** Peripheral CACHE64_POLSEL1 base address */
  #define CACHE64_POLSEL1_BASE_NS                  (0x40034000u)
  /** Peripheral CACHE64_POLSEL1 base pointer */
  #define CACHE64_POLSEL1                          ((CACHE64_POLSEL_Type *)CACHE64_POLSEL1_BASE)
  /** Peripheral CACHE64_POLSEL1 base pointer */
  #define CACHE64_POLSEL1_NS                       ((CACHE64_POLSEL_Type *)CACHE64_POLSEL1_BASE_NS)
  /** Array initializer of CACHE64_POLSEL peripheral base addresses */
  #define CACHE64_POLSEL_BASE_ADDRS                { CACHE64_POLSEL0_BASE, CACHE64_POLSEL1_BASE }
  /** Array initializer of CACHE64_POLSEL peripheral base pointers */
  #define CACHE64_POLSEL_BASE_PTRS                 { CACHE64_POLSEL0, CACHE64_POLSEL1 }
  /** Array initializer of CACHE64_POLSEL peripheral base addresses */
  #define CACHE64_POLSEL_BASE_ADDRS_NS             { CACHE64_POLSEL0_BASE_NS, CACHE64_POLSEL1_BASE_NS }
  /** Array initializer of CACHE64_POLSEL peripheral base pointers */
  #define CACHE64_POLSEL_BASE_PTRS_NS              { CACHE64_POLSEL0_NS, CACHE64_POLSEL1_NS }
#else
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
#endif

/* CASPER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CASPER base address */
  #define CASPER_BASE                              (0x50201000u)
  /** Peripheral CASPER base address */
  #define CASPER_BASE_NS                           (0x40201000u)
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
  #define CASPER_BASE                              (0x40201000u)
  /** Peripheral CASPER base pointer */
  #define CASPER                                   ((CASPER_Type *)CASPER_BASE)
  /** Array initializer of CASPER peripheral base addresses */
  #define CASPER_BASE_ADDRS                        { CASPER_BASE }
  /** Array initializer of CASPER peripheral base pointers */
  #define CASPER_BASE_PTRS                         { CASPER }
#endif
/** Interrupt vectors for the CASPER peripheral type */
#define CASPER_IRQS                              { CASPER_IRQn }

/* CLKCTL0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CLKCTL0 base address */
  #define CLKCTL0_BASE                             (0x50001000u)
  /** Peripheral CLKCTL0 base address */
  #define CLKCTL0_BASE_NS                          (0x40001000u)
  /** Peripheral CLKCTL0 base pointer */
  #define CLKCTL0                                  ((CLKCTL0_Type *)CLKCTL0_BASE)
  /** Peripheral CLKCTL0 base pointer */
  #define CLKCTL0_NS                               ((CLKCTL0_Type *)CLKCTL0_BASE_NS)
  /** Array initializer of CLKCTL0 peripheral base addresses */
  #define CLKCTL0_BASE_ADDRS                       { CLKCTL0_BASE }
  /** Array initializer of CLKCTL0 peripheral base pointers */
  #define CLKCTL0_BASE_PTRS                        { CLKCTL0 }
  /** Array initializer of CLKCTL0 peripheral base addresses */
  #define CLKCTL0_BASE_ADDRS_NS                    { CLKCTL0_BASE_NS }
  /** Array initializer of CLKCTL0 peripheral base pointers */
  #define CLKCTL0_BASE_PTRS_NS                     { CLKCTL0_NS }
#else
  /** Peripheral CLKCTL0 base address */
  #define CLKCTL0_BASE                             (0x40001000u)
  /** Peripheral CLKCTL0 base pointer */
  #define CLKCTL0                                  ((CLKCTL0_Type *)CLKCTL0_BASE)
  /** Array initializer of CLKCTL0 peripheral base addresses */
  #define CLKCTL0_BASE_ADDRS                       { CLKCTL0_BASE }
  /** Array initializer of CLKCTL0 peripheral base pointers */
  #define CLKCTL0_BASE_PTRS                        { CLKCTL0 }
#endif

/* CLKCTL1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CLKCTL1 base address */
  #define CLKCTL1_BASE                             (0x50021000u)
  /** Peripheral CLKCTL1 base address */
  #define CLKCTL1_BASE_NS                          (0x40021000u)
  /** Peripheral CLKCTL1 base pointer */
  #define CLKCTL1                                  ((CLKCTL1_Type *)CLKCTL1_BASE)
  /** Peripheral CLKCTL1 base pointer */
  #define CLKCTL1_NS                               ((CLKCTL1_Type *)CLKCTL1_BASE_NS)
  /** Array initializer of CLKCTL1 peripheral base addresses */
  #define CLKCTL1_BASE_ADDRS                       { CLKCTL1_BASE }
  /** Array initializer of CLKCTL1 peripheral base pointers */
  #define CLKCTL1_BASE_PTRS                        { CLKCTL1 }
  /** Array initializer of CLKCTL1 peripheral base addresses */
  #define CLKCTL1_BASE_ADDRS_NS                    { CLKCTL1_BASE_NS }
  /** Array initializer of CLKCTL1 peripheral base pointers */
  #define CLKCTL1_BASE_PTRS_NS                     { CLKCTL1_NS }
#else
  /** Peripheral CLKCTL1 base address */
  #define CLKCTL1_BASE                             (0x40021000u)
  /** Peripheral CLKCTL1 base pointer */
  #define CLKCTL1                                  ((CLKCTL1_Type *)CLKCTL1_BASE)
  /** Array initializer of CLKCTL1 peripheral base addresses */
  #define CLKCTL1_BASE_ADDRS                       { CLKCTL1_BASE }
  /** Array initializer of CLKCTL1 peripheral base pointers */
  #define CLKCTL1_BASE_PTRS                        { CLKCTL1 }
#endif

/* CMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ACMP0 base address */
  #define ACMP0_BASE                               (0x50139000u)
  /** Peripheral ACMP0 base address */
  #define ACMP0_BASE_NS                            (0x40139000u)
  /** Peripheral ACMP0 base pointer */
  #define ACMP0                                    ((CMP_Type *)ACMP0_BASE)
  /** Peripheral ACMP0 base pointer */
  #define ACMP0_NS                                 ((CMP_Type *)ACMP0_BASE_NS)
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS                           { ACMP0_BASE }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS                            { ACMP0 }
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS_NS                        { ACMP0_BASE_NS }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS_NS                         { ACMP0_NS }
#else
  /** Peripheral ACMP0 base address */
  #define ACMP0_BASE                               (0x40139000u)
  /** Peripheral ACMP0 base pointer */
  #define ACMP0                                    ((CMP_Type *)ACMP0_BASE)
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS                           { ACMP0_BASE }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS                            { ACMP0 }
#endif
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { ACMP_IRQn }

/* CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CRC_ENGINE base address */
  #define CRC_ENGINE_BASE                          (0x50120000u)
  /** Peripheral CRC_ENGINE base address */
  #define CRC_ENGINE_BASE_NS                       (0x40120000u)
  /** Peripheral CRC_ENGINE base pointer */
  #define CRC_ENGINE                               ((CRC_Type *)CRC_ENGINE_BASE)
  /** Peripheral CRC_ENGINE base pointer */
  #define CRC_ENGINE_NS                            ((CRC_Type *)CRC_ENGINE_BASE_NS)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC_ENGINE_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC_ENGINE }
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS_NS                        { CRC_ENGINE_BASE_NS }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS_NS                         { CRC_ENGINE_NS }
#else
  /** Peripheral CRC_ENGINE base address */
  #define CRC_ENGINE_BASE                          (0x40120000u)
  /** Peripheral CRC_ENGINE base pointer */
  #define CRC_ENGINE                               ((CRC_Type *)CRC_ENGINE_BASE)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC_ENGINE_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC_ENGINE }
#endif

/* CTIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CTIMER0 base address */
  #define CTIMER0_BASE                             (0x50028000u)
  /** Peripheral CTIMER0 base address */
  #define CTIMER0_BASE_NS                          (0x40028000u)
  /** Peripheral CTIMER0 base pointer */
  #define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
  /** Peripheral CTIMER0 base pointer */
  #define CTIMER0_NS                               ((CTIMER_Type *)CTIMER0_BASE_NS)
  /** Peripheral CTIMER1 base address */
  #define CTIMER1_BASE                             (0x50029000u)
  /** Peripheral CTIMER1 base address */
  #define CTIMER1_BASE_NS                          (0x40029000u)
  /** Peripheral CTIMER1 base pointer */
  #define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
  /** Peripheral CTIMER1 base pointer */
  #define CTIMER1_NS                               ((CTIMER_Type *)CTIMER1_BASE_NS)
  /** Peripheral CTIMER2 base address */
  #define CTIMER2_BASE                             (0x5002A000u)
  /** Peripheral CTIMER2 base address */
  #define CTIMER2_BASE_NS                          (0x4002A000u)
  /** Peripheral CTIMER2 base pointer */
  #define CTIMER2                                  ((CTIMER_Type *)CTIMER2_BASE)
  /** Peripheral CTIMER2 base pointer */
  #define CTIMER2_NS                               ((CTIMER_Type *)CTIMER2_BASE_NS)
  /** Peripheral CTIMER3 base address */
  #define CTIMER3_BASE                             (0x5002B000u)
  /** Peripheral CTIMER3 base address */
  #define CTIMER3_BASE_NS                          (0x4002B000u)
  /** Peripheral CTIMER3 base pointer */
  #define CTIMER3                                  ((CTIMER_Type *)CTIMER3_BASE)
  /** Peripheral CTIMER3 base pointer */
  #define CTIMER3_NS                               ((CTIMER_Type *)CTIMER3_BASE_NS)
  /** Peripheral CTIMER4 base address */
  #define CTIMER4_BASE                             (0x5002C000u)
  /** Peripheral CTIMER4 base address */
  #define CTIMER4_BASE_NS                          (0x4002C000u)
  /** Peripheral CTIMER4 base pointer */
  #define CTIMER4                                  ((CTIMER_Type *)CTIMER4_BASE)
  /** Peripheral CTIMER4 base pointer */
  #define CTIMER4_NS                               ((CTIMER_Type *)CTIMER4_BASE_NS)
  /** Array initializer of CTIMER peripheral base addresses */
  #define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE, CTIMER2_BASE, CTIMER3_BASE, CTIMER4_BASE }
  /** Array initializer of CTIMER peripheral base pointers */
  #define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1, CTIMER2, CTIMER3, CTIMER4 }
  /** Array initializer of CTIMER peripheral base addresses */
  #define CTIMER_BASE_ADDRS_NS                     { CTIMER0_BASE_NS, CTIMER1_BASE_NS, CTIMER2_BASE_NS, CTIMER3_BASE_NS, CTIMER4_BASE_NS }
  /** Array initializer of CTIMER peripheral base pointers */
  #define CTIMER_BASE_PTRS_NS                      { CTIMER0_NS, CTIMER1_NS, CTIMER2_NS, CTIMER3_NS, CTIMER4_NS }
#else
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
#endif
/** Interrupt vectors for the CTIMER peripheral type */
#define CTIMER_IRQS                              { CTIMER0_IRQn, CTIMER1_IRQn, CTIMER2_IRQn, CTIMER3_IRQn, CTIMER4_IRQn }

/* DEBUGGER_MAILBOX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DEBUGGER_MAILBOX base address */
  #define DEBUGGER_MAILBOX_BASE                    (0x5010F000u)
  /** Peripheral DEBUGGER_MAILBOX base address */
  #define DEBUGGER_MAILBOX_BASE_NS                 (0x4010F000u)
  /** Peripheral DEBUGGER_MAILBOX base pointer */
  #define DEBUGGER_MAILBOX                         ((DEBUGGER_MAILBOX_Type *)DEBUGGER_MAILBOX_BASE)
  /** Peripheral DEBUGGER_MAILBOX base pointer */
  #define DEBUGGER_MAILBOX_NS                      ((DEBUGGER_MAILBOX_Type *)DEBUGGER_MAILBOX_BASE_NS)
  /** Array initializer of DEBUGGER_MAILBOX peripheral base addresses */
  #define DEBUGGER_MAILBOX_BASE_ADDRS              { DEBUGGER_MAILBOX_BASE }
  /** Array initializer of DEBUGGER_MAILBOX peripheral base pointers */
  #define DEBUGGER_MAILBOX_BASE_PTRS               { DEBUGGER_MAILBOX }
  /** Array initializer of DEBUGGER_MAILBOX peripheral base addresses */
  #define DEBUGGER_MAILBOX_BASE_ADDRS_NS           { DEBUGGER_MAILBOX_BASE_NS }
  /** Array initializer of DEBUGGER_MAILBOX peripheral base pointers */
  #define DEBUGGER_MAILBOX_BASE_PTRS_NS            { DEBUGGER_MAILBOX_NS }
#else
  /** Peripheral DEBUGGER_MAILBOX base address */
  #define DEBUGGER_MAILBOX_BASE                    (0x4010F000u)
  /** Peripheral DEBUGGER_MAILBOX base pointer */
  #define DEBUGGER_MAILBOX                         ((DEBUGGER_MAILBOX_Type *)DEBUGGER_MAILBOX_BASE)
  /** Array initializer of DEBUGGER_MAILBOX peripheral base addresses */
  #define DEBUGGER_MAILBOX_BASE_ADDRS              { DEBUGGER_MAILBOX_BASE }
  /** Array initializer of DEBUGGER_MAILBOX peripheral base pointers */
  #define DEBUGGER_MAILBOX_BASE_PTRS               { DEBUGGER_MAILBOX }
#endif

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA0 base address */
  #define DMA0_BASE                                (0x50104000u)
  /** Peripheral DMA0 base address */
  #define DMA0_BASE_NS                             (0x40104000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Peripheral DMA0 base pointer */
  #define DMA0_NS                                  ((DMA_Type *)DMA0_BASE_NS)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE                                (0x50105000u)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE_NS                             (0x40105000u)
  /** Peripheral DMA1 base pointer */
  #define DMA1                                     ((DMA_Type *)DMA1_BASE)
  /** Peripheral DMA1 base pointer */
  #define DMA1_NS                                  ((DMA_Type *)DMA1_BASE_NS)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA0_BASE, DMA1_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA0, DMA1 }
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS_NS                        { DMA0_BASE_NS, DMA1_BASE_NS }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS_NS                         { DMA0_NS, DMA1_NS }
#else
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
#endif
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { DMA0_IRQn, DMA1_IRQn }

/* DMIC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMIC0 base address */
  #define DMIC0_BASE                               (0x50121000u)
  /** Peripheral DMIC0 base address */
  #define DMIC0_BASE_NS                            (0x40121000u)
  /** Peripheral DMIC0 base pointer */
  #define DMIC0                                    ((DMIC_Type *)DMIC0_BASE)
  /** Peripheral DMIC0 base pointer */
  #define DMIC0_NS                                 ((DMIC_Type *)DMIC0_BASE_NS)
  /** Array initializer of DMIC peripheral base addresses */
  #define DMIC_BASE_ADDRS                          { DMIC0_BASE }
  /** Array initializer of DMIC peripheral base pointers */
  #define DMIC_BASE_PTRS                           { DMIC0 }
  /** Array initializer of DMIC peripheral base addresses */
  #define DMIC_BASE_ADDRS_NS                       { DMIC0_BASE_NS }
  /** Array initializer of DMIC peripheral base pointers */
  #define DMIC_BASE_PTRS_NS                        { DMIC0_NS }
#else
  /** Peripheral DMIC0 base address */
  #define DMIC0_BASE                               (0x40121000u)
  /** Peripheral DMIC0 base pointer */
  #define DMIC0                                    ((DMIC_Type *)DMIC0_BASE)
  /** Array initializer of DMIC peripheral base addresses */
  #define DMIC_BASE_ADDRS                          { DMIC0_BASE }
  /** Array initializer of DMIC peripheral base pointers */
  #define DMIC_BASE_PTRS                           { DMIC0 }
#endif
/** Interrupt vectors for the DMIC peripheral type */
#define DMIC_IRQS                                { DMIC0_IRQn }
#define DMIC_HWVAD_IRQS                          { HWVAD0_IRQn }

/* FLEXCOMM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXCOMM0 base address */
  #define FLEXCOMM0_BASE                           (0x50106000u)
  /** Peripheral FLEXCOMM0 base address */
  #define FLEXCOMM0_BASE_NS                        (0x40106000u)
  /** Peripheral FLEXCOMM0 base pointer */
  #define FLEXCOMM0                                ((FLEXCOMM_Type *)FLEXCOMM0_BASE)
  /** Peripheral FLEXCOMM0 base pointer */
  #define FLEXCOMM0_NS                             ((FLEXCOMM_Type *)FLEXCOMM0_BASE_NS)
  /** Peripheral FLEXCOMM1 base address */
  #define FLEXCOMM1_BASE                           (0x50107000u)
  /** Peripheral FLEXCOMM1 base address */
  #define FLEXCOMM1_BASE_NS                        (0x40107000u)
  /** Peripheral FLEXCOMM1 base pointer */
  #define FLEXCOMM1                                ((FLEXCOMM_Type *)FLEXCOMM1_BASE)
  /** Peripheral FLEXCOMM1 base pointer */
  #define FLEXCOMM1_NS                             ((FLEXCOMM_Type *)FLEXCOMM1_BASE_NS)
  /** Peripheral FLEXCOMM2 base address */
  #define FLEXCOMM2_BASE                           (0x50108000u)
  /** Peripheral FLEXCOMM2 base address */
  #define FLEXCOMM2_BASE_NS                        (0x40108000u)
  /** Peripheral FLEXCOMM2 base pointer */
  #define FLEXCOMM2                                ((FLEXCOMM_Type *)FLEXCOMM2_BASE)
  /** Peripheral FLEXCOMM2 base pointer */
  #define FLEXCOMM2_NS                             ((FLEXCOMM_Type *)FLEXCOMM2_BASE_NS)
  /** Peripheral FLEXCOMM3 base address */
  #define FLEXCOMM3_BASE                           (0x50109000u)
  /** Peripheral FLEXCOMM3 base address */
  #define FLEXCOMM3_BASE_NS                        (0x40109000u)
  /** Peripheral FLEXCOMM3 base pointer */
  #define FLEXCOMM3                                ((FLEXCOMM_Type *)FLEXCOMM3_BASE)
  /** Peripheral FLEXCOMM3 base pointer */
  #define FLEXCOMM3_NS                             ((FLEXCOMM_Type *)FLEXCOMM3_BASE_NS)
  /** Peripheral FLEXCOMM4 base address */
  #define FLEXCOMM4_BASE                           (0x50122000u)
  /** Peripheral FLEXCOMM4 base address */
  #define FLEXCOMM4_BASE_NS                        (0x40122000u)
  /** Peripheral FLEXCOMM4 base pointer */
  #define FLEXCOMM4                                ((FLEXCOMM_Type *)FLEXCOMM4_BASE)
  /** Peripheral FLEXCOMM4 base pointer */
  #define FLEXCOMM4_NS                             ((FLEXCOMM_Type *)FLEXCOMM4_BASE_NS)
  /** Peripheral FLEXCOMM5 base address */
  #define FLEXCOMM5_BASE                           (0x50123000u)
  /** Peripheral FLEXCOMM5 base address */
  #define FLEXCOMM5_BASE_NS                        (0x40123000u)
  /** Peripheral FLEXCOMM5 base pointer */
  #define FLEXCOMM5                                ((FLEXCOMM_Type *)FLEXCOMM5_BASE)
  /** Peripheral FLEXCOMM5 base pointer */
  #define FLEXCOMM5_NS                             ((FLEXCOMM_Type *)FLEXCOMM5_BASE_NS)
  /** Peripheral FLEXCOMM6 base address */
  #define FLEXCOMM6_BASE                           (0x50124000u)
  /** Peripheral FLEXCOMM6 base address */
  #define FLEXCOMM6_BASE_NS                        (0x40124000u)
  /** Peripheral FLEXCOMM6 base pointer */
  #define FLEXCOMM6                                ((FLEXCOMM_Type *)FLEXCOMM6_BASE)
  /** Peripheral FLEXCOMM6 base pointer */
  #define FLEXCOMM6_NS                             ((FLEXCOMM_Type *)FLEXCOMM6_BASE_NS)
  /** Peripheral FLEXCOMM7 base address */
  #define FLEXCOMM7_BASE                           (0x50125000u)
  /** Peripheral FLEXCOMM7 base address */
  #define FLEXCOMM7_BASE_NS                        (0x40125000u)
  /** Peripheral FLEXCOMM7 base pointer */
  #define FLEXCOMM7                                ((FLEXCOMM_Type *)FLEXCOMM7_BASE)
  /** Peripheral FLEXCOMM7 base pointer */
  #define FLEXCOMM7_NS                             ((FLEXCOMM_Type *)FLEXCOMM7_BASE_NS)
  /** Peripheral FLEXCOMM8 base address */
  #define FLEXCOMM8_BASE                           (0x50209000u)
  /** Peripheral FLEXCOMM8 base address */
  #define FLEXCOMM8_BASE_NS                        (0x40209000u)
  /** Peripheral FLEXCOMM8 base pointer */
  #define FLEXCOMM8                                ((FLEXCOMM_Type *)FLEXCOMM8_BASE)
  /** Peripheral FLEXCOMM8 base pointer */
  #define FLEXCOMM8_NS                             ((FLEXCOMM_Type *)FLEXCOMM8_BASE_NS)
  /** Peripheral FLEXCOMM9 base address */
  #define FLEXCOMM9_BASE                           (0x5020A000u)
  /** Peripheral FLEXCOMM9 base address */
  #define FLEXCOMM9_BASE_NS                        (0x4020A000u)
  /** Peripheral FLEXCOMM9 base pointer */
  #define FLEXCOMM9                                ((FLEXCOMM_Type *)FLEXCOMM9_BASE)
  /** Peripheral FLEXCOMM9 base pointer */
  #define FLEXCOMM9_NS                             ((FLEXCOMM_Type *)FLEXCOMM9_BASE_NS)
  /** Peripheral FLEXCOMM10 base address */
  #define FLEXCOMM10_BASE                          (0x5020B000u)
  /** Peripheral FLEXCOMM10 base address */
  #define FLEXCOMM10_BASE_NS                       (0x4020B000u)
  /** Peripheral FLEXCOMM10 base pointer */
  #define FLEXCOMM10                               ((FLEXCOMM_Type *)FLEXCOMM10_BASE)
  /** Peripheral FLEXCOMM10 base pointer */
  #define FLEXCOMM10_NS                            ((FLEXCOMM_Type *)FLEXCOMM10_BASE_NS)
  /** Peripheral FLEXCOMM11 base address */
  #define FLEXCOMM11_BASE                          (0x5020C000u)
  /** Peripheral FLEXCOMM11 base address */
  #define FLEXCOMM11_BASE_NS                       (0x4020C000u)
  /** Peripheral FLEXCOMM11 base pointer */
  #define FLEXCOMM11                               ((FLEXCOMM_Type *)FLEXCOMM11_BASE)
  /** Peripheral FLEXCOMM11 base pointer */
  #define FLEXCOMM11_NS                            ((FLEXCOMM_Type *)FLEXCOMM11_BASE_NS)
  /** Peripheral FLEXCOMM12 base address */
  #define FLEXCOMM12_BASE                          (0x5020D000u)
  /** Peripheral FLEXCOMM12 base address */
  #define FLEXCOMM12_BASE_NS                       (0x4020D000u)
  /** Peripheral FLEXCOMM12 base pointer */
  #define FLEXCOMM12                               ((FLEXCOMM_Type *)FLEXCOMM12_BASE)
  /** Peripheral FLEXCOMM12 base pointer */
  #define FLEXCOMM12_NS                            ((FLEXCOMM_Type *)FLEXCOMM12_BASE_NS)
  /** Peripheral FLEXCOMM13 base address */
  #define FLEXCOMM13_BASE                          (0x5020E000u)
  /** Peripheral FLEXCOMM13 base address */
  #define FLEXCOMM13_BASE_NS                       (0x4020E000u)
  /** Peripheral FLEXCOMM13 base pointer */
  #define FLEXCOMM13                               ((FLEXCOMM_Type *)FLEXCOMM13_BASE)
  /** Peripheral FLEXCOMM13 base pointer */
  #define FLEXCOMM13_NS                            ((FLEXCOMM_Type *)FLEXCOMM13_BASE_NS)
  /** Peripheral FLEXCOMM14 base address */
  #define FLEXCOMM14_BASE                          (0x50126000u)
  /** Peripheral FLEXCOMM14 base address */
  #define FLEXCOMM14_BASE_NS                       (0x40126000u)
  /** Peripheral FLEXCOMM14 base pointer */
  #define FLEXCOMM14                               ((FLEXCOMM_Type *)FLEXCOMM14_BASE)
  /** Peripheral FLEXCOMM14 base pointer */
  #define FLEXCOMM14_NS                            ((FLEXCOMM_Type *)FLEXCOMM14_BASE_NS)
  /** Peripheral FLEXCOMM15 base address */
  #define FLEXCOMM15_BASE                          (0x50127000u)
  /** Peripheral FLEXCOMM15 base address */
  #define FLEXCOMM15_BASE_NS                       (0x40127000u)
  /** Peripheral FLEXCOMM15 base pointer */
  #define FLEXCOMM15                               ((FLEXCOMM_Type *)FLEXCOMM15_BASE)
  /** Peripheral FLEXCOMM15 base pointer */
  #define FLEXCOMM15_NS                            ((FLEXCOMM_Type *)FLEXCOMM15_BASE_NS)
  /** Peripheral FLEXCOMM16 base address */
  #define FLEXCOMM16_BASE                          (0x50128000u)
  /** Peripheral FLEXCOMM16 base address */
  #define FLEXCOMM16_BASE_NS                       (0x40128000u)
  /** Peripheral FLEXCOMM16 base pointer */
  #define FLEXCOMM16                               ((FLEXCOMM_Type *)FLEXCOMM16_BASE)
  /** Peripheral FLEXCOMM16 base pointer */
  #define FLEXCOMM16_NS                            ((FLEXCOMM_Type *)FLEXCOMM16_BASE_NS)
  /** Array initializer of FLEXCOMM peripheral base addresses */
  #define FLEXCOMM_BASE_ADDRS                      { FLEXCOMM0_BASE, FLEXCOMM1_BASE, FLEXCOMM2_BASE, FLEXCOMM3_BASE, FLEXCOMM4_BASE, FLEXCOMM5_BASE, FLEXCOMM6_BASE, FLEXCOMM7_BASE, FLEXCOMM8_BASE, FLEXCOMM9_BASE, FLEXCOMM10_BASE, FLEXCOMM11_BASE, FLEXCOMM12_BASE, FLEXCOMM13_BASE, FLEXCOMM14_BASE, FLEXCOMM15_BASE, FLEXCOMM16_BASE }
  /** Array initializer of FLEXCOMM peripheral base pointers */
  #define FLEXCOMM_BASE_PTRS                       { FLEXCOMM0, FLEXCOMM1, FLEXCOMM2, FLEXCOMM3, FLEXCOMM4, FLEXCOMM5, FLEXCOMM6, FLEXCOMM7, FLEXCOMM8, FLEXCOMM9, FLEXCOMM10, FLEXCOMM11, FLEXCOMM12, FLEXCOMM13, FLEXCOMM14, FLEXCOMM15, FLEXCOMM16 }
  /** Array initializer of FLEXCOMM peripheral base addresses */
  #define FLEXCOMM_BASE_ADDRS_NS                   { FLEXCOMM0_BASE_NS, FLEXCOMM1_BASE_NS, FLEXCOMM2_BASE_NS, FLEXCOMM3_BASE_NS, FLEXCOMM4_BASE_NS, FLEXCOMM5_BASE_NS, FLEXCOMM6_BASE_NS, FLEXCOMM7_BASE_NS, FLEXCOMM8_BASE_NS, FLEXCOMM9_BASE_NS, FLEXCOMM10_BASE_NS, FLEXCOMM11_BASE_NS, FLEXCOMM12_BASE_NS, FLEXCOMM13_BASE_NS, FLEXCOMM14_BASE_NS, FLEXCOMM15_BASE_NS, FLEXCOMM16_BASE_NS }
  /** Array initializer of FLEXCOMM peripheral base pointers */
  #define FLEXCOMM_BASE_PTRS_NS                    { FLEXCOMM0_NS, FLEXCOMM1_NS, FLEXCOMM2_NS, FLEXCOMM3_NS, FLEXCOMM4_NS, FLEXCOMM5_NS, FLEXCOMM6_NS, FLEXCOMM7_NS, FLEXCOMM8_NS, FLEXCOMM9_NS, FLEXCOMM10_NS, FLEXCOMM11_NS, FLEXCOMM12_NS, FLEXCOMM13_NS, FLEXCOMM14_NS, FLEXCOMM15_NS, FLEXCOMM16_NS }
#else
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
#endif
/** Interrupt vectors for the FLEXCOMM peripheral type */
#define FLEXCOMM_IRQS                            { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, FLEXCOMM8_IRQn, FLEXCOMM9_IRQn, FLEXCOMM10_IRQn, FLEXCOMM11_IRQn, FLEXCOMM12_IRQn, FLEXCOMM13_IRQn, FLEXCOMM14_IRQn, FLEXCOMM15_IRQn, FLEXCOMM16_IRQn }

/* FLEXIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXIO0 base address */
  #define FLEXIO0_BASE                             (0x50032000u)
  /** Peripheral FLEXIO0 base address */
  #define FLEXIO0_BASE_NS                          (0x40032000u)
  /** Peripheral FLEXIO0 base pointer */
  #define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
  /** Peripheral FLEXIO0 base pointer */
  #define FLEXIO0_NS                               ((FLEXIO_Type *)FLEXIO0_BASE_NS)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { FLEXIO0 }
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS_NS                     { FLEXIO0_BASE_NS }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS_NS                      { FLEXIO0_NS }
#else
  /** Peripheral FLEXIO0 base address */
  #define FLEXIO0_BASE                             (0x40032000u)
  /** Peripheral FLEXIO0 base pointer */
  #define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { FLEXIO0 }
#endif
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { FLEXIO_IRQn }

/* FLEXSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXSPI0 base address */
  #define FLEXSPI0_BASE                            (0x50134000u)
  /** Peripheral FLEXSPI0 base address */
  #define FLEXSPI0_BASE_NS                         (0x40134000u)
  /** Peripheral FLEXSPI0 base pointer */
  #define FLEXSPI0                                 ((FLEXSPI_Type *)FLEXSPI0_BASE)
  /** Peripheral FLEXSPI0 base pointer */
  #define FLEXSPI0_NS                              ((FLEXSPI_Type *)FLEXSPI0_BASE_NS)
  /** Peripheral FLEXSPI1 base address */
  #define FLEXSPI1_BASE                            (0x5013C000u)
  /** Peripheral FLEXSPI1 base address */
  #define FLEXSPI1_BASE_NS                         (0x4013C000u)
  /** Peripheral FLEXSPI1 base pointer */
  #define FLEXSPI1                                 ((FLEXSPI_Type *)FLEXSPI1_BASE)
  /** Peripheral FLEXSPI1 base pointer */
  #define FLEXSPI1_NS                              ((FLEXSPI_Type *)FLEXSPI1_BASE_NS)
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS                       { FLEXSPI0_BASE, FLEXSPI1_BASE }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS                        { FLEXSPI0, FLEXSPI1 }
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS_NS                    { FLEXSPI0_BASE_NS, FLEXSPI1_BASE_NS }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS_NS                     { FLEXSPI0_NS, FLEXSPI1_NS }
#else
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
#endif
/** Interrupt vectors for the FLEXSPI peripheral type */
#define FLEXSPI_IRQS                             { FLEXSPI0_FLEXSPI1_IRQn, FLEXSPI0_FLEXSPI1_IRQn }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (1)
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** FlexSPI AMBA base address array */
#define FlexSPI_AMBA_BASE_ARRAY                   { {0x18000000u}, {0x38000000u} }
/** FlexSPI AMBA end address array */
#define FlexSPI_AMBA_END_ARRAY                    { {0x1FFFFFFFu}, {0x3FFFFFFFu} }
/** FlexSPI AMBA base address array */
#define FlexSPI_AMBA_BASE_ARRAY_NS                { {0x08000000u}, {0x28000000u} }
/** FlexSPI AMBA end address array */
#define FlexSPI_AMBA_END_ARRAY_NS                 { {0x0FFFFFFFu}, {0x2FFFFFFFu} }
/* FlexSPI0 AMBA address. */
#define FlexSPI0_AMBA_BASE                       (0x18000000u)
#define FlexSPI0_AMBA_BASE_NS                    (0x08000000u)
/* FlexSPI1 AMBA address. */
#define FlexSPI1_AMBA_BASE                       (0x38000000u)
#define FlexSPI1_AMBA_BASE_NS                    (0x28000000u)
#else
/** FlexSPI AMBA base address array */
#define FlexSPI_AMBA_BASE_ARRAY                   { {0x08000000u}, {0x28000000u} }
/** FlexSPI AMBA end address array */
#define FlexSPI_AMBA_END_ARRAY                    { {0x0FFFFFFFu}, {0x2FFFFFFFu} }
/* FlexSPI0 AMBA address. */
#define FlexSPI0_AMBA_BASE                       (0x08000000u)
/* FlexSPI1 AMBA address. */
#define FlexSPI1_AMBA_BASE                       (0x28000000u)
#endif


/* FREQME - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FREQME base address */
  #define FREQME_BASE                              (0x5002F000u)
  /** Peripheral FREQME base address */
  #define FREQME_BASE_NS                           (0x4002F000u)
  /** Peripheral FREQME base pointer */
  #define FREQME                                   ((FREQME_Type *)FREQME_BASE)
  /** Peripheral FREQME base pointer */
  #define FREQME_NS                                ((FREQME_Type *)FREQME_BASE_NS)
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS                        { FREQME_BASE }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS                         { FREQME }
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS_NS                     { FREQME_BASE_NS }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS_NS                      { FREQME_NS }
#else
  /** Peripheral FREQME base address */
  #define FREQME_BASE                              (0x4002F000u)
  /** Peripheral FREQME base pointer */
  #define FREQME                                   ((FREQME_Type *)FREQME_BASE)
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS                        { FREQME_BASE }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS                         { FREQME }
#endif

/* GPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPIO base address */
  #define GPIO_BASE                                (0x50100000u)
  /** Peripheral GPIO base address */
  #define GPIO_BASE_NS                             (0x40100000u)
  /** Peripheral GPIO base pointer */
  #define GPIO                                     ((GPIO_Type *)GPIO_BASE)
  /** Peripheral GPIO base pointer */
  #define GPIO_NS                                  ((GPIO_Type *)GPIO_BASE_NS)
  /** Peripheral SECGPIO base address */
  #define SECGPIO_BASE                             (0x50204000u)
  /** Peripheral SECGPIO base address */
  #define SECGPIO_BASE_NS                          (0x40204000u)
  /** Peripheral SECGPIO base pointer */
  #define SECGPIO                                  ((GPIO_Type *)SECGPIO_BASE)
  /** Peripheral SECGPIO base pointer */
  #define SECGPIO_NS                               ((GPIO_Type *)SECGPIO_BASE_NS)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { GPIO_BASE, SECGPIO_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { GPIO, SECGPIO }
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS_NS                       { GPIO_BASE_NS, SECGPIO_BASE_NS }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS_NS                        { GPIO_NS, SECGPIO_NS }
#else
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
#endif

/* HASHCRYPT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HASHCRYPT base address */
  #define HASHCRYPT_BASE                           (0x50208000u)
  /** Peripheral HASHCRYPT base address */
  #define HASHCRYPT_BASE_NS                        (0x40208000u)
  /** Peripheral HASHCRYPT base pointer */
  #define HASHCRYPT                                ((HASHCRYPT_Type *)HASHCRYPT_BASE)
  /** Peripheral HASHCRYPT base pointer */
  #define HASHCRYPT_NS                             ((HASHCRYPT_Type *)HASHCRYPT_BASE_NS)
  /** Array initializer of HASHCRYPT peripheral base addresses */
  #define HASHCRYPT_BASE_ADDRS                     { HASHCRYPT_BASE }
  /** Array initializer of HASHCRYPT peripheral base pointers */
  #define HASHCRYPT_BASE_PTRS                      { HASHCRYPT }
  /** Array initializer of HASHCRYPT peripheral base addresses */
  #define HASHCRYPT_BASE_ADDRS_NS                  { HASHCRYPT_BASE_NS }
  /** Array initializer of HASHCRYPT peripheral base pointers */
  #define HASHCRYPT_BASE_PTRS_NS                   { HASHCRYPT_NS }
#else
  /** Peripheral HASHCRYPT base address */
  #define HASHCRYPT_BASE                           (0x40208000u)
  /** Peripheral HASHCRYPT base pointer */
  #define HASHCRYPT                                ((HASHCRYPT_Type *)HASHCRYPT_BASE)
  /** Array initializer of HASHCRYPT peripheral base addresses */
  #define HASHCRYPT_BASE_ADDRS                     { HASHCRYPT_BASE }
  /** Array initializer of HASHCRYPT peripheral base pointers */
  #define HASHCRYPT_BASE_PTRS                      { HASHCRYPT }
#endif
/** Interrupt vectors for the HASHCRYPT peripheral type */
#define HASHCRYPT_IRQS                           { HASHCRYPT_IRQn }

/* I2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I2C0 base address */
  #define I2C0_BASE                                (0x50106000u)
  /** Peripheral I2C0 base address */
  #define I2C0_BASE_NS                             (0x40106000u)
  /** Peripheral I2C0 base pointer */
  #define I2C0                                     ((I2C_Type *)I2C0_BASE)
  /** Peripheral I2C0 base pointer */
  #define I2C0_NS                                  ((I2C_Type *)I2C0_BASE_NS)
  /** Peripheral I2C1 base address */
  #define I2C1_BASE                                (0x50107000u)
  /** Peripheral I2C1 base address */
  #define I2C1_BASE_NS                             (0x40107000u)
  /** Peripheral I2C1 base pointer */
  #define I2C1                                     ((I2C_Type *)I2C1_BASE)
  /** Peripheral I2C1 base pointer */
  #define I2C1_NS                                  ((I2C_Type *)I2C1_BASE_NS)
  /** Peripheral I2C2 base address */
  #define I2C2_BASE                                (0x50108000u)
  /** Peripheral I2C2 base address */
  #define I2C2_BASE_NS                             (0x40108000u)
  /** Peripheral I2C2 base pointer */
  #define I2C2                                     ((I2C_Type *)I2C2_BASE)
  /** Peripheral I2C2 base pointer */
  #define I2C2_NS                                  ((I2C_Type *)I2C2_BASE_NS)
  /** Peripheral I2C3 base address */
  #define I2C3_BASE                                (0x50109000u)
  /** Peripheral I2C3 base address */
  #define I2C3_BASE_NS                             (0x40109000u)
  /** Peripheral I2C3 base pointer */
  #define I2C3                                     ((I2C_Type *)I2C3_BASE)
  /** Peripheral I2C3 base pointer */
  #define I2C3_NS                                  ((I2C_Type *)I2C3_BASE_NS)
  /** Peripheral I2C4 base address */
  #define I2C4_BASE                                (0x50122000u)
  /** Peripheral I2C4 base address */
  #define I2C4_BASE_NS                             (0x40122000u)
  /** Peripheral I2C4 base pointer */
  #define I2C4                                     ((I2C_Type *)I2C4_BASE)
  /** Peripheral I2C4 base pointer */
  #define I2C4_NS                                  ((I2C_Type *)I2C4_BASE_NS)
  /** Peripheral I2C5 base address */
  #define I2C5_BASE                                (0x50123000u)
  /** Peripheral I2C5 base address */
  #define I2C5_BASE_NS                             (0x40123000u)
  /** Peripheral I2C5 base pointer */
  #define I2C5                                     ((I2C_Type *)I2C5_BASE)
  /** Peripheral I2C5 base pointer */
  #define I2C5_NS                                  ((I2C_Type *)I2C5_BASE_NS)
  /** Peripheral I2C6 base address */
  #define I2C6_BASE                                (0x50124000u)
  /** Peripheral I2C6 base address */
  #define I2C6_BASE_NS                             (0x40124000u)
  /** Peripheral I2C6 base pointer */
  #define I2C6                                     ((I2C_Type *)I2C6_BASE)
  /** Peripheral I2C6 base pointer */
  #define I2C6_NS                                  ((I2C_Type *)I2C6_BASE_NS)
  /** Peripheral I2C7 base address */
  #define I2C7_BASE                                (0x50125000u)
  /** Peripheral I2C7 base address */
  #define I2C7_BASE_NS                             (0x40125000u)
  /** Peripheral I2C7 base pointer */
  #define I2C7                                     ((I2C_Type *)I2C7_BASE)
  /** Peripheral I2C7 base pointer */
  #define I2C7_NS                                  ((I2C_Type *)I2C7_BASE_NS)
  /** Peripheral I2C8 base address */
  #define I2C8_BASE                                (0x50209000u)
  /** Peripheral I2C8 base address */
  #define I2C8_BASE_NS                             (0x40209000u)
  /** Peripheral I2C8 base pointer */
  #define I2C8                                     ((I2C_Type *)I2C8_BASE)
  /** Peripheral I2C8 base pointer */
  #define I2C8_NS                                  ((I2C_Type *)I2C8_BASE_NS)
  /** Peripheral I2C9 base address */
  #define I2C9_BASE                                (0x5020A000u)
  /** Peripheral I2C9 base address */
  #define I2C9_BASE_NS                             (0x4020A000u)
  /** Peripheral I2C9 base pointer */
  #define I2C9                                     ((I2C_Type *)I2C9_BASE)
  /** Peripheral I2C9 base pointer */
  #define I2C9_NS                                  ((I2C_Type *)I2C9_BASE_NS)
  /** Peripheral I2C10 base address */
  #define I2C10_BASE                               (0x5020B000u)
  /** Peripheral I2C10 base address */
  #define I2C10_BASE_NS                            (0x4020B000u)
  /** Peripheral I2C10 base pointer */
  #define I2C10                                    ((I2C_Type *)I2C10_BASE)
  /** Peripheral I2C10 base pointer */
  #define I2C10_NS                                 ((I2C_Type *)I2C10_BASE_NS)
  /** Peripheral I2C11 base address */
  #define I2C11_BASE                               (0x5020C000u)
  /** Peripheral I2C11 base address */
  #define I2C11_BASE_NS                            (0x4020C000u)
  /** Peripheral I2C11 base pointer */
  #define I2C11                                    ((I2C_Type *)I2C11_BASE)
  /** Peripheral I2C11 base pointer */
  #define I2C11_NS                                 ((I2C_Type *)I2C11_BASE_NS)
  /** Peripheral I2C12 base address */
  #define I2C12_BASE                               (0x5020D000u)
  /** Peripheral I2C12 base address */
  #define I2C12_BASE_NS                            (0x4020D000u)
  /** Peripheral I2C12 base pointer */
  #define I2C12                                    ((I2C_Type *)I2C12_BASE)
  /** Peripheral I2C12 base pointer */
  #define I2C12_NS                                 ((I2C_Type *)I2C12_BASE_NS)
  /** Peripheral I2C13 base address */
  #define I2C13_BASE                               (0x5020E000u)
  /** Peripheral I2C13 base address */
  #define I2C13_BASE_NS                            (0x4020E000u)
  /** Peripheral I2C13 base pointer */
  #define I2C13                                    ((I2C_Type *)I2C13_BASE)
  /** Peripheral I2C13 base pointer */
  #define I2C13_NS                                 ((I2C_Type *)I2C13_BASE_NS)
  /** Peripheral I2C15 base address */
  #define I2C15_BASE                               (0x50127000u)
  /** Peripheral I2C15 base address */
  #define I2C15_BASE_NS                            (0x40127000u)
  /** Peripheral I2C15 base pointer */
  #define I2C15                                    ((I2C_Type *)I2C15_BASE)
  /** Peripheral I2C15 base pointer */
  #define I2C15_NS                                 ((I2C_Type *)I2C15_BASE_NS)
  /** Array initializer of I2C peripheral base addresses */
  #define I2C_BASE_ADDRS                           { I2C0_BASE, I2C1_BASE, I2C2_BASE, I2C3_BASE, I2C4_BASE, I2C5_BASE, I2C6_BASE, I2C7_BASE, I2C8_BASE, I2C9_BASE, I2C10_BASE, I2C11_BASE, I2C12_BASE, I2C13_BASE, I2C15_BASE }
  /** Array initializer of I2C peripheral base pointers */
  #define I2C_BASE_PTRS                            { I2C0, I2C1, I2C2, I2C3, I2C4, I2C5, I2C6, I2C7, I2C8, I2C9, I2C10, I2C11, I2C12, I2C13, I2C15 }
  /** Array initializer of I2C peripheral base addresses */
  #define I2C_BASE_ADDRS_NS                        { I2C0_BASE_NS, I2C1_BASE_NS, I2C2_BASE_NS, I2C3_BASE_NS, I2C4_BASE_NS, I2C5_BASE_NS, I2C6_BASE_NS, I2C7_BASE_NS, I2C8_BASE_NS, I2C9_BASE_NS, I2C10_BASE_NS, I2C11_BASE_NS, I2C12_BASE_NS, I2C13_BASE_NS, I2C15_BASE_NS }
  /** Array initializer of I2C peripheral base pointers */
  #define I2C_BASE_PTRS_NS                         { I2C0_NS, I2C1_NS, I2C2_NS, I2C3_NS, I2C4_NS, I2C5_NS, I2C6_NS, I2C7_NS, I2C8_NS, I2C9_NS, I2C10_NS, I2C11_NS, I2C12_NS, I2C13_NS, I2C15_NS }
#else
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
#endif
/** Interrupt vectors for the I2C peripheral type */
#define I2C_IRQS                                 { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, FLEXCOMM8_IRQn, FLEXCOMM9_IRQn, FLEXCOMM10_IRQn, FLEXCOMM11_IRQn, FLEXCOMM12_IRQn, FLEXCOMM13_IRQn, FLEXCOMM15_IRQn }

/* I2S - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I2S0 base address */
  #define I2S0_BASE                                (0x50106000u)
  /** Peripheral I2S0 base address */
  #define I2S0_BASE_NS                             (0x40106000u)
  /** Peripheral I2S0 base pointer */
  #define I2S0                                     ((I2S_Type *)I2S0_BASE)
  /** Peripheral I2S0 base pointer */
  #define I2S0_NS                                  ((I2S_Type *)I2S0_BASE_NS)
  /** Peripheral I2S1 base address */
  #define I2S1_BASE                                (0x50107000u)
  /** Peripheral I2S1 base address */
  #define I2S1_BASE_NS                             (0x40107000u)
  /** Peripheral I2S1 base pointer */
  #define I2S1                                     ((I2S_Type *)I2S1_BASE)
  /** Peripheral I2S1 base pointer */
  #define I2S1_NS                                  ((I2S_Type *)I2S1_BASE_NS)
  /** Peripheral I2S2 base address */
  #define I2S2_BASE                                (0x50108000u)
  /** Peripheral I2S2 base address */
  #define I2S2_BASE_NS                             (0x40108000u)
  /** Peripheral I2S2 base pointer */
  #define I2S2                                     ((I2S_Type *)I2S2_BASE)
  /** Peripheral I2S2 base pointer */
  #define I2S2_NS                                  ((I2S_Type *)I2S2_BASE_NS)
  /** Peripheral I2S3 base address */
  #define I2S3_BASE                                (0x50109000u)
  /** Peripheral I2S3 base address */
  #define I2S3_BASE_NS                             (0x40109000u)
  /** Peripheral I2S3 base pointer */
  #define I2S3                                     ((I2S_Type *)I2S3_BASE)
  /** Peripheral I2S3 base pointer */
  #define I2S3_NS                                  ((I2S_Type *)I2S3_BASE_NS)
  /** Peripheral I2S4 base address */
  #define I2S4_BASE                                (0x50122000u)
  /** Peripheral I2S4 base address */
  #define I2S4_BASE_NS                             (0x40122000u)
  /** Peripheral I2S4 base pointer */
  #define I2S4                                     ((I2S_Type *)I2S4_BASE)
  /** Peripheral I2S4 base pointer */
  #define I2S4_NS                                  ((I2S_Type *)I2S4_BASE_NS)
  /** Peripheral I2S5 base address */
  #define I2S5_BASE                                (0x50123000u)
  /** Peripheral I2S5 base address */
  #define I2S5_BASE_NS                             (0x40123000u)
  /** Peripheral I2S5 base pointer */
  #define I2S5                                     ((I2S_Type *)I2S5_BASE)
  /** Peripheral I2S5 base pointer */
  #define I2S5_NS                                  ((I2S_Type *)I2S5_BASE_NS)
  /** Peripheral I2S6 base address */
  #define I2S6_BASE                                (0x50124000u)
  /** Peripheral I2S6 base address */
  #define I2S6_BASE_NS                             (0x40124000u)
  /** Peripheral I2S6 base pointer */
  #define I2S6                                     ((I2S_Type *)I2S6_BASE)
  /** Peripheral I2S6 base pointer */
  #define I2S6_NS                                  ((I2S_Type *)I2S6_BASE_NS)
  /** Peripheral I2S7 base address */
  #define I2S7_BASE                                (0x50125000u)
  /** Peripheral I2S7 base address */
  #define I2S7_BASE_NS                             (0x40125000u)
  /** Peripheral I2S7 base pointer */
  #define I2S7                                     ((I2S_Type *)I2S7_BASE)
  /** Peripheral I2S7 base pointer */
  #define I2S7_NS                                  ((I2S_Type *)I2S7_BASE_NS)
  /** Peripheral I2S8 base address */
  #define I2S8_BASE                                (0x50209000u)
  /** Peripheral I2S8 base address */
  #define I2S8_BASE_NS                             (0x40209000u)
  /** Peripheral I2S8 base pointer */
  #define I2S8                                     ((I2S_Type *)I2S8_BASE)
  /** Peripheral I2S8 base pointer */
  #define I2S8_NS                                  ((I2S_Type *)I2S8_BASE_NS)
  /** Peripheral I2S9 base address */
  #define I2S9_BASE                                (0x5020A000u)
  /** Peripheral I2S9 base address */
  #define I2S9_BASE_NS                             (0x4020A000u)
  /** Peripheral I2S9 base pointer */
  #define I2S9                                     ((I2S_Type *)I2S9_BASE)
  /** Peripheral I2S9 base pointer */
  #define I2S9_NS                                  ((I2S_Type *)I2S9_BASE_NS)
  /** Peripheral I2S10 base address */
  #define I2S10_BASE                               (0x5020B000u)
  /** Peripheral I2S10 base address */
  #define I2S10_BASE_NS                            (0x4020B000u)
  /** Peripheral I2S10 base pointer */
  #define I2S10                                    ((I2S_Type *)I2S10_BASE)
  /** Peripheral I2S10 base pointer */
  #define I2S10_NS                                 ((I2S_Type *)I2S10_BASE_NS)
  /** Peripheral I2S11 base address */
  #define I2S11_BASE                               (0x5020C000u)
  /** Peripheral I2S11 base address */
  #define I2S11_BASE_NS                            (0x4020C000u)
  /** Peripheral I2S11 base pointer */
  #define I2S11                                    ((I2S_Type *)I2S11_BASE)
  /** Peripheral I2S11 base pointer */
  #define I2S11_NS                                 ((I2S_Type *)I2S11_BASE_NS)
  /** Peripheral I2S12 base address */
  #define I2S12_BASE                               (0x5020D000u)
  /** Peripheral I2S12 base address */
  #define I2S12_BASE_NS                            (0x4020D000u)
  /** Peripheral I2S12 base pointer */
  #define I2S12                                    ((I2S_Type *)I2S12_BASE)
  /** Peripheral I2S12 base pointer */
  #define I2S12_NS                                 ((I2S_Type *)I2S12_BASE_NS)
  /** Peripheral I2S13 base address */
  #define I2S13_BASE                               (0x5020E000u)
  /** Peripheral I2S13 base address */
  #define I2S13_BASE_NS                            (0x4020E000u)
  /** Peripheral I2S13 base pointer */
  #define I2S13                                    ((I2S_Type *)I2S13_BASE)
  /** Peripheral I2S13 base pointer */
  #define I2S13_NS                                 ((I2S_Type *)I2S13_BASE_NS)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { I2S0_BASE, I2S1_BASE, I2S2_BASE, I2S3_BASE, I2S4_BASE, I2S5_BASE, I2S6_BASE, I2S7_BASE, I2S8_BASE, I2S9_BASE, I2S10_BASE, I2S11_BASE, I2S12_BASE, I2S13_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { I2S0, I2S1, I2S2, I2S3, I2S4, I2S5, I2S6, I2S7, I2S8, I2S9, I2S10, I2S11, I2S12, I2S13 }
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS_NS                        { I2S0_BASE_NS, I2S1_BASE_NS, I2S2_BASE_NS, I2S3_BASE_NS, I2S4_BASE_NS, I2S5_BASE_NS, I2S6_BASE_NS, I2S7_BASE_NS, I2S8_BASE_NS, I2S9_BASE_NS, I2S10_BASE_NS, I2S11_BASE_NS, I2S12_BASE_NS, I2S13_BASE_NS }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS_NS                         { I2S0_NS, I2S1_NS, I2S2_NS, I2S3_NS, I2S4_NS, I2S5_NS, I2S6_NS, I2S7_NS, I2S8_NS, I2S9_NS, I2S10_NS, I2S11_NS, I2S12_NS, I2S13_NS }
#else
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
#endif
/** Interrupt vectors for the I2S peripheral type */
#define I2S_IRQS                                 { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, FLEXCOMM8_IRQn, FLEXCOMM9_IRQn, FLEXCOMM10_IRQn, FLEXCOMM11_IRQn, FLEXCOMM12_IRQn, FLEXCOMM13_IRQn }

/* I3C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I3C0 base address */
  #define I3C0_BASE                                (0x50036000u)
  /** Peripheral I3C0 base address */
  #define I3C0_BASE_NS                             (0x40036000u)
  /** Peripheral I3C0 base pointer */
  #define I3C0                                     ((I3C_Type *)I3C0_BASE)
  /** Peripheral I3C0 base pointer */
  #define I3C0_NS                                  ((I3C_Type *)I3C0_BASE_NS)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x50037000u)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE_NS                             (0x40037000u)
  /** Peripheral I3C1 base pointer */
  #define I3C1                                     ((I3C_Type *)I3C1_BASE)
  /** Peripheral I3C1 base pointer */
  #define I3C1_NS                                  ((I3C_Type *)I3C1_BASE_NS)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { I3C0_BASE, I3C1_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { I3C0, I3C1 }
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS_NS                        { I3C0_BASE_NS, I3C1_BASE_NS }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS_NS                         { I3C0_NS, I3C1_NS }
#else
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
#endif
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { I3C0_IRQn, I3C1_IRQn }

/* INPUTMUX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral INPUTMUX base address */
  #define INPUTMUX_BASE                            (0x50026000u)
  /** Peripheral INPUTMUX base address */
  #define INPUTMUX_BASE_NS                         (0x40026000u)
  /** Peripheral INPUTMUX base pointer */
  #define INPUTMUX                                 ((INPUTMUX_Type *)INPUTMUX_BASE)
  /** Peripheral INPUTMUX base pointer */
  #define INPUTMUX_NS                              ((INPUTMUX_Type *)INPUTMUX_BASE_NS)
  /** Array initializer of INPUTMUX peripheral base addresses */
  #define INPUTMUX_BASE_ADDRS                      { INPUTMUX_BASE }
  /** Array initializer of INPUTMUX peripheral base pointers */
  #define INPUTMUX_BASE_PTRS                       { INPUTMUX }
  /** Array initializer of INPUTMUX peripheral base addresses */
  #define INPUTMUX_BASE_ADDRS_NS                   { INPUTMUX_BASE_NS }
  /** Array initializer of INPUTMUX peripheral base pointers */
  #define INPUTMUX_BASE_PTRS_NS                    { INPUTMUX_NS }
#else
  /** Peripheral INPUTMUX base address */
  #define INPUTMUX_BASE                            (0x40026000u)
  /** Peripheral INPUTMUX base pointer */
  #define INPUTMUX                                 ((INPUTMUX_Type *)INPUTMUX_BASE)
  /** Array initializer of INPUTMUX peripheral base addresses */
  #define INPUTMUX_BASE_ADDRS                      { INPUTMUX_BASE }
  /** Array initializer of INPUTMUX peripheral base pointers */
  #define INPUTMUX_BASE_PTRS                       { INPUTMUX }
#endif

/* IOPCTL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOPCTL base address */
  #define IOPCTL_BASE                              (0x50004000u)
  /** Peripheral IOPCTL base address */
  #define IOPCTL_BASE_NS                           (0x40004000u)
  /** Peripheral IOPCTL base pointer */
  #define IOPCTL                                   ((IOPCTL_Type *)IOPCTL_BASE)
  /** Peripheral IOPCTL base pointer */
  #define IOPCTL_NS                                ((IOPCTL_Type *)IOPCTL_BASE_NS)
  /** Array initializer of IOPCTL peripheral base addresses */
  #define IOPCTL_BASE_ADDRS                        { IOPCTL_BASE }
  /** Array initializer of IOPCTL peripheral base pointers */
  #define IOPCTL_BASE_PTRS                         { IOPCTL }
  /** Array initializer of IOPCTL peripheral base addresses */
  #define IOPCTL_BASE_ADDRS_NS                     { IOPCTL_BASE_NS }
  /** Array initializer of IOPCTL peripheral base pointers */
  #define IOPCTL_BASE_PTRS_NS                      { IOPCTL_NS }
#else
  /** Peripheral IOPCTL base address */
  #define IOPCTL_BASE                              (0x40004000u)
  /** Peripheral IOPCTL base pointer */
  #define IOPCTL                                   ((IOPCTL_Type *)IOPCTL_BASE)
  /** Array initializer of IOPCTL peripheral base addresses */
  #define IOPCTL_BASE_ADDRS                        { IOPCTL_BASE }
  /** Array initializer of IOPCTL peripheral base pointers */
  #define IOPCTL_BASE_PTRS                         { IOPCTL }
#endif

/* MRT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MRT0 base address */
  #define MRT0_BASE                                (0x5002D000u)
  /** Peripheral MRT0 base address */
  #define MRT0_BASE_NS                             (0x4002D000u)
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
  #define MRT0_BASE                                (0x4002D000u)
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
  /** Peripheral MUA base address */
  #define MUA_BASE                                 (0x50110000u)
  /** Peripheral MUA base address */
  #define MUA_BASE_NS                              (0x40110000u)
  /** Peripheral MUA base pointer */
  #define MUA                                      ((MU_Type *)MUA_BASE)
  /** Peripheral MUA base pointer */
  #define MUA_NS                                   ((MU_Type *)MUA_BASE_NS)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MUA }
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS_NS                         { MUA_BASE_NS }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS_NS                          { MUA_NS }
#else
  /** Peripheral MUA base address */
  #define MUA_BASE                                 (0x40110000u)
  /** Peripheral MUA base pointer */
  #define MUA                                      ((MU_Type *)MUA_BASE)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MUA }
#endif
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU_A_IRQn }

/* OCOTP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OCOTP0 base address */
  #define OCOTP0_BASE                              (0x50130000u)
  /** Peripheral OCOTP0 base address */
  #define OCOTP0_BASE_NS                           (0x40130000u)
  /** Peripheral OCOTP0 base pointer */
  #define OCOTP0                                   ((OCOTP_Type *)OCOTP0_BASE)
  /** Peripheral OCOTP0 base pointer */
  #define OCOTP0_NS                                ((OCOTP_Type *)OCOTP0_BASE_NS)
  /** Array initializer of OCOTP peripheral base addresses */
  #define OCOTP_BASE_ADDRS                         { OCOTP0_BASE }
  /** Array initializer of OCOTP peripheral base pointers */
  #define OCOTP_BASE_PTRS                          { OCOTP0 }
  /** Array initializer of OCOTP peripheral base addresses */
  #define OCOTP_BASE_ADDRS_NS                      { OCOTP0_BASE_NS }
  /** Array initializer of OCOTP peripheral base pointers */
  #define OCOTP_BASE_PTRS_NS                       { OCOTP0_NS }
#else
  /** Peripheral OCOTP0 base address */
  #define OCOTP0_BASE                              (0x40130000u)
  /** Peripheral OCOTP0 base pointer */
  #define OCOTP0                                   ((OCOTP_Type *)OCOTP0_BASE)
  /** Array initializer of OCOTP peripheral base addresses */
  #define OCOTP_BASE_ADDRS                         { OCOTP0_BASE }
  /** Array initializer of OCOTP peripheral base pointers */
  #define OCOTP_BASE_PTRS                          { OCOTP0 }
#endif

/* OSTIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OSTIMER0 base address */
  #define OSTIMER0_BASE                            (0x50113000u)
  /** Peripheral OSTIMER0 base address */
  #define OSTIMER0_BASE_NS                         (0x40113000u)
  /** Peripheral OSTIMER0 base pointer */
  #define OSTIMER0                                 ((OSTIMER_Type *)OSTIMER0_BASE)
  /** Peripheral OSTIMER0 base pointer */
  #define OSTIMER0_NS                              ((OSTIMER_Type *)OSTIMER0_BASE_NS)
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS                       { OSTIMER0_BASE }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS                        { OSTIMER0 }
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS_NS                    { OSTIMER0_BASE_NS }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS_NS                     { OSTIMER0_NS }
#else
  /** Peripheral OSTIMER0 base address */
  #define OSTIMER0_BASE                            (0x40113000u)
  /** Peripheral OSTIMER0 base pointer */
  #define OSTIMER0                                 ((OSTIMER_Type *)OSTIMER0_BASE)
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS                       { OSTIMER0_BASE }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS                        { OSTIMER0 }
#endif
/** Interrupt vectors for the OSTIMER peripheral type */
#define OSTIMER_IRQS                             { OS_EVENT_IRQn }

/* OTFAD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OTFAD0 base address */
  #define OTFAD0_BASE                              (0x50134000u)
  /** Peripheral OTFAD0 base address */
  #define OTFAD0_BASE_NS                           (0x40134000u)
  /** Peripheral OTFAD0 base pointer */
  #define OTFAD0                                   ((OTFAD_Type *)OTFAD0_BASE)
  /** Peripheral OTFAD0 base pointer */
  #define OTFAD0_NS                                ((OTFAD_Type *)OTFAD0_BASE_NS)
  /** Array initializer of OTFAD peripheral base addresses */
  #define OTFAD_BASE_ADDRS                         { OTFAD0_BASE }
  /** Array initializer of OTFAD peripheral base pointers */
  #define OTFAD_BASE_PTRS                          { OTFAD0 }
  /** Array initializer of OTFAD peripheral base addresses */
  #define OTFAD_BASE_ADDRS_NS                      { OTFAD0_BASE_NS }
  /** Array initializer of OTFAD peripheral base pointers */
  #define OTFAD_BASE_PTRS_NS                       { OTFAD0_NS }
#else
  /** Peripheral OTFAD0 base address */
  #define OTFAD0_BASE                              (0x40134000u)
  /** Peripheral OTFAD0 base pointer */
  #define OTFAD0                                   ((OTFAD_Type *)OTFAD0_BASE)
  /** Array initializer of OTFAD peripheral base addresses */
  #define OTFAD_BASE_ADDRS                         { OTFAD0_BASE }
  /** Array initializer of OTFAD peripheral base pointers */
  #define OTFAD_BASE_PTRS                          { OTFAD0 }
#endif

/* PINT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PINT base address */
  #define PINT_BASE                                (0x50025000u)
  /** Peripheral PINT base address */
  #define PINT_BASE_NS                             (0x40025000u)
  /** Peripheral PINT base pointer */
  #define PINT                                     ((PINT_Type *)PINT_BASE)
  /** Peripheral PINT base pointer */
  #define PINT_NS                                  ((PINT_Type *)PINT_BASE_NS)
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS                          { PINT_BASE }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS                           { PINT }
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS_NS                       { PINT_BASE_NS }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS_NS                        { PINT_NS }
#else
  /** Peripheral PINT base address */
  #define PINT_BASE                                (0x40025000u)
  /** Peripheral PINT base pointer */
  #define PINT                                     ((PINT_Type *)PINT_BASE)
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS                          { PINT_BASE }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS                           { PINT }
#endif
/** Interrupt vectors for the PINT peripheral type */
#define PINT_IRQS                                { PIN_INT0_IRQn, PIN_INT1_IRQn, PIN_INT2_IRQn, PIN_INT3_IRQn, PIN_INT4_IRQn, PIN_INT5_IRQn, PIN_INT6_IRQn, PIN_INT7_IRQn }

/* PMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PMC base address */
  #define PMC_BASE                                 (0x50135000u)
  /** Peripheral PMC base address */
  #define PMC_BASE_NS                              (0x40135000u)
  /** Peripheral PMC base pointer */
  #define PMC                                      ((PMC_Type *)PMC_BASE)
  /** Peripheral PMC base pointer */
  #define PMC_NS                                   ((PMC_Type *)PMC_BASE_NS)
  /** Array initializer of PMC peripheral base addresses */
  #define PMC_BASE_ADDRS                           { PMC_BASE }
  /** Array initializer of PMC peripheral base pointers */
  #define PMC_BASE_PTRS                            { PMC }
  /** Array initializer of PMC peripheral base addresses */
  #define PMC_BASE_ADDRS_NS                        { PMC_BASE_NS }
  /** Array initializer of PMC peripheral base pointers */
  #define PMC_BASE_PTRS_NS                         { PMC_NS }
#else
  /** Peripheral PMC base address */
  #define PMC_BASE                                 (0x40135000u)
  /** Peripheral PMC base pointer */
  #define PMC                                      ((PMC_Type *)PMC_BASE)
  /** Array initializer of PMC peripheral base addresses */
  #define PMC_BASE_ADDRS                           { PMC_BASE }
  /** Array initializer of PMC peripheral base pointers */
  #define PMC_BASE_PTRS                            { PMC }
#endif

/* POWERQUAD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral POWERQUAD base address */
  #define POWERQUAD_BASE                           (0x50200000u)
  /** Peripheral POWERQUAD base address */
  #define POWERQUAD_BASE_NS                        (0x40200000u)
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
  #define POWERQUAD_BASE                           (0x40200000u)
  /** Peripheral POWERQUAD base pointer */
  #define POWERQUAD                                ((POWERQUAD_Type *)POWERQUAD_BASE)
  /** Array initializer of POWERQUAD peripheral base addresses */
  #define POWERQUAD_BASE_ADDRS                     { POWERQUAD_BASE }
  /** Array initializer of POWERQUAD peripheral base pointers */
  #define POWERQUAD_BASE_PTRS                      { POWERQUAD }
#endif
/** Interrupt vectors for the POWERQUAD peripheral type */
#define POWERQUAD_IRQS                           { POWERQUAD_IRQn }

/* PUF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PUF base address */
  #define PUF_BASE                                 (0x50006000u)
  /** Peripheral PUF base address */
  #define PUF_BASE_NS                              (0x40006000u)
  /** Peripheral PUF base pointer */
  #define PUF                                      ((PUF_Type *)PUF_BASE)
  /** Peripheral PUF base pointer */
  #define PUF_NS                                   ((PUF_Type *)PUF_BASE_NS)
  /** Array initializer of PUF peripheral base addresses */
  #define PUF_BASE_ADDRS                           { PUF_BASE }
  /** Array initializer of PUF peripheral base pointers */
  #define PUF_BASE_PTRS                            { PUF }
  /** Array initializer of PUF peripheral base addresses */
  #define PUF_BASE_ADDRS_NS                        { PUF_BASE_NS }
  /** Array initializer of PUF peripheral base pointers */
  #define PUF_BASE_PTRS_NS                         { PUF_NS }
#else
  /** Peripheral PUF base address */
  #define PUF_BASE                                 (0x40006000u)
  /** Peripheral PUF base pointer */
  #define PUF                                      ((PUF_Type *)PUF_BASE)
  /** Array initializer of PUF peripheral base addresses */
  #define PUF_BASE_ADDRS                           { PUF_BASE }
  /** Array initializer of PUF peripheral base pointers */
  #define PUF_BASE_PTRS                            { PUF }
#endif

/* RSTCTL0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RSTCTL0 base address */
  #define RSTCTL0_BASE                             (0x50000000u)
  /** Peripheral RSTCTL0 base address */
  #define RSTCTL0_BASE_NS                          (0x40000000u)
  /** Peripheral RSTCTL0 base pointer */
  #define RSTCTL0                                  ((RSTCTL0_Type *)RSTCTL0_BASE)
  /** Peripheral RSTCTL0 base pointer */
  #define RSTCTL0_NS                               ((RSTCTL0_Type *)RSTCTL0_BASE_NS)
  /** Array initializer of RSTCTL0 peripheral base addresses */
  #define RSTCTL0_BASE_ADDRS                       { RSTCTL0_BASE }
  /** Array initializer of RSTCTL0 peripheral base pointers */
  #define RSTCTL0_BASE_PTRS                        { RSTCTL0 }
  /** Array initializer of RSTCTL0 peripheral base addresses */
  #define RSTCTL0_BASE_ADDRS_NS                    { RSTCTL0_BASE_NS }
  /** Array initializer of RSTCTL0 peripheral base pointers */
  #define RSTCTL0_BASE_PTRS_NS                     { RSTCTL0_NS }
#else
  /** Peripheral RSTCTL0 base address */
  #define RSTCTL0_BASE                             (0x40000000u)
  /** Peripheral RSTCTL0 base pointer */
  #define RSTCTL0                                  ((RSTCTL0_Type *)RSTCTL0_BASE)
  /** Array initializer of RSTCTL0 peripheral base addresses */
  #define RSTCTL0_BASE_ADDRS                       { RSTCTL0_BASE }
  /** Array initializer of RSTCTL0 peripheral base pointers */
  #define RSTCTL0_BASE_PTRS                        { RSTCTL0 }
#endif

/* RSTCTL1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RSTCTL1 base address */
  #define RSTCTL1_BASE                             (0x50020000u)
  /** Peripheral RSTCTL1 base address */
  #define RSTCTL1_BASE_NS                          (0x40020000u)
  /** Peripheral RSTCTL1 base pointer */
  #define RSTCTL1                                  ((RSTCTL1_Type *)RSTCTL1_BASE)
  /** Peripheral RSTCTL1 base pointer */
  #define RSTCTL1_NS                               ((RSTCTL1_Type *)RSTCTL1_BASE_NS)
  /** Array initializer of RSTCTL1 peripheral base addresses */
  #define RSTCTL1_BASE_ADDRS                       { RSTCTL1_BASE }
  /** Array initializer of RSTCTL1 peripheral base pointers */
  #define RSTCTL1_BASE_PTRS                        { RSTCTL1 }
  /** Array initializer of RSTCTL1 peripheral base addresses */
  #define RSTCTL1_BASE_ADDRS_NS                    { RSTCTL1_BASE_NS }
  /** Array initializer of RSTCTL1 peripheral base pointers */
  #define RSTCTL1_BASE_PTRS_NS                     { RSTCTL1_NS }
#else
  /** Peripheral RSTCTL1 base address */
  #define RSTCTL1_BASE                             (0x40020000u)
  /** Peripheral RSTCTL1 base pointer */
  #define RSTCTL1                                  ((RSTCTL1_Type *)RSTCTL1_BASE)
  /** Array initializer of RSTCTL1 peripheral base addresses */
  #define RSTCTL1_BASE_ADDRS                       { RSTCTL1_BASE }
  /** Array initializer of RSTCTL1 peripheral base pointers */
  #define RSTCTL1_BASE_PTRS                        { RSTCTL1 }
#endif

/* RTC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RTC base address */
  #define RTC_BASE                                 (0x50030000u)
  /** Peripheral RTC base address */
  #define RTC_BASE_NS                              (0x40030000u)
  /** Peripheral RTC base pointer */
  #define RTC                                      ((RTC_Type *)RTC_BASE)
  /** Peripheral RTC base pointer */
  #define RTC_NS                                   ((RTC_Type *)RTC_BASE_NS)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { RTC_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { RTC }
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS_NS                        { RTC_BASE_NS }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS_NS                         { RTC_NS }
#else
  /** Peripheral RTC base address */
  #define RTC_BASE                                 (0x40030000u)
  /** Peripheral RTC base pointer */
  #define RTC                                      ((RTC_Type *)RTC_BASE)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { RTC_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { RTC }
#endif
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }

/* SCT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SCT0 base address */
  #define SCT0_BASE                                (0x50146000u)
  /** Peripheral SCT0 base address */
  #define SCT0_BASE_NS                             (0x40146000u)
  /** Peripheral SCT0 base pointer */
  #define SCT0                                     ((SCT_Type *)SCT0_BASE)
  /** Peripheral SCT0 base pointer */
  #define SCT0_NS                                  ((SCT_Type *)SCT0_BASE_NS)
  /** Array initializer of SCT peripheral base addresses */
  #define SCT_BASE_ADDRS                           { SCT0_BASE }
  /** Array initializer of SCT peripheral base pointers */
  #define SCT_BASE_PTRS                            { SCT0 }
  /** Array initializer of SCT peripheral base addresses */
  #define SCT_BASE_ADDRS_NS                        { SCT0_BASE_NS }
  /** Array initializer of SCT peripheral base pointers */
  #define SCT_BASE_PTRS_NS                         { SCT0_NS }
#else
  /** Peripheral SCT0 base address */
  #define SCT0_BASE                                (0x40146000u)
  /** Peripheral SCT0 base pointer */
  #define SCT0                                     ((SCT_Type *)SCT0_BASE)
  /** Array initializer of SCT peripheral base addresses */
  #define SCT_BASE_ADDRS                           { SCT0_BASE }
  /** Array initializer of SCT peripheral base pointers */
  #define SCT_BASE_PTRS                            { SCT0 }
#endif
/** Interrupt vectors for the SCT peripheral type */
#define SCT_IRQS                                 { SCT0_IRQn }

/* SEMA42 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SEMA42 base address */
  #define SEMA42_BASE                              (0x50112000u)
  /** Peripheral SEMA42 base address */
  #define SEMA42_BASE_NS                           (0x40112000u)
  /** Peripheral SEMA42 base pointer */
  #define SEMA42                                   ((SEMA42_Type *)SEMA42_BASE)
  /** Peripheral SEMA42 base pointer */
  #define SEMA42_NS                                ((SEMA42_Type *)SEMA42_BASE_NS)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA42_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA42 }
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS_NS                     { SEMA42_BASE_NS }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS_NS                      { SEMA42_NS }
#else
  /** Peripheral SEMA42 base address */
  #define SEMA42_BASE                              (0x40112000u)
  /** Peripheral SEMA42 base pointer */
  #define SEMA42                                   ((SEMA42_Type *)SEMA42_BASE)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA42_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA42 }
#endif

/* SPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SPI0 base address */
  #define SPI0_BASE                                (0x50106000u)
  /** Peripheral SPI0 base address */
  #define SPI0_BASE_NS                             (0x40106000u)
  /** Peripheral SPI0 base pointer */
  #define SPI0                                     ((SPI_Type *)SPI0_BASE)
  /** Peripheral SPI0 base pointer */
  #define SPI0_NS                                  ((SPI_Type *)SPI0_BASE_NS)
  /** Peripheral SPI1 base address */
  #define SPI1_BASE                                (0x50107000u)
  /** Peripheral SPI1 base address */
  #define SPI1_BASE_NS                             (0x40107000u)
  /** Peripheral SPI1 base pointer */
  #define SPI1                                     ((SPI_Type *)SPI1_BASE)
  /** Peripheral SPI1 base pointer */
  #define SPI1_NS                                  ((SPI_Type *)SPI1_BASE_NS)
  /** Peripheral SPI2 base address */
  #define SPI2_BASE                                (0x50108000u)
  /** Peripheral SPI2 base address */
  #define SPI2_BASE_NS                             (0x40108000u)
  /** Peripheral SPI2 base pointer */
  #define SPI2                                     ((SPI_Type *)SPI2_BASE)
  /** Peripheral SPI2 base pointer */
  #define SPI2_NS                                  ((SPI_Type *)SPI2_BASE_NS)
  /** Peripheral SPI3 base address */
  #define SPI3_BASE                                (0x50109000u)
  /** Peripheral SPI3 base address */
  #define SPI3_BASE_NS                             (0x40109000u)
  /** Peripheral SPI3 base pointer */
  #define SPI3                                     ((SPI_Type *)SPI3_BASE)
  /** Peripheral SPI3 base pointer */
  #define SPI3_NS                                  ((SPI_Type *)SPI3_BASE_NS)
  /** Peripheral SPI4 base address */
  #define SPI4_BASE                                (0x50122000u)
  /** Peripheral SPI4 base address */
  #define SPI4_BASE_NS                             (0x40122000u)
  /** Peripheral SPI4 base pointer */
  #define SPI4                                     ((SPI_Type *)SPI4_BASE)
  /** Peripheral SPI4 base pointer */
  #define SPI4_NS                                  ((SPI_Type *)SPI4_BASE_NS)
  /** Peripheral SPI5 base address */
  #define SPI5_BASE                                (0x50123000u)
  /** Peripheral SPI5 base address */
  #define SPI5_BASE_NS                             (0x40123000u)
  /** Peripheral SPI5 base pointer */
  #define SPI5                                     ((SPI_Type *)SPI5_BASE)
  /** Peripheral SPI5 base pointer */
  #define SPI5_NS                                  ((SPI_Type *)SPI5_BASE_NS)
  /** Peripheral SPI6 base address */
  #define SPI6_BASE                                (0x50124000u)
  /** Peripheral SPI6 base address */
  #define SPI6_BASE_NS                             (0x40124000u)
  /** Peripheral SPI6 base pointer */
  #define SPI6                                     ((SPI_Type *)SPI6_BASE)
  /** Peripheral SPI6 base pointer */
  #define SPI6_NS                                  ((SPI_Type *)SPI6_BASE_NS)
  /** Peripheral SPI7 base address */
  #define SPI7_BASE                                (0x50125000u)
  /** Peripheral SPI7 base address */
  #define SPI7_BASE_NS                             (0x40125000u)
  /** Peripheral SPI7 base pointer */
  #define SPI7                                     ((SPI_Type *)SPI7_BASE)
  /** Peripheral SPI7 base pointer */
  #define SPI7_NS                                  ((SPI_Type *)SPI7_BASE_NS)
  /** Peripheral SPI8 base address */
  #define SPI8_BASE                                (0x50209000u)
  /** Peripheral SPI8 base address */
  #define SPI8_BASE_NS                             (0x40209000u)
  /** Peripheral SPI8 base pointer */
  #define SPI8                                     ((SPI_Type *)SPI8_BASE)
  /** Peripheral SPI8 base pointer */
  #define SPI8_NS                                  ((SPI_Type *)SPI8_BASE_NS)
  /** Peripheral SPI9 base address */
  #define SPI9_BASE                                (0x5020A000u)
  /** Peripheral SPI9 base address */
  #define SPI9_BASE_NS                             (0x4020A000u)
  /** Peripheral SPI9 base pointer */
  #define SPI9                                     ((SPI_Type *)SPI9_BASE)
  /** Peripheral SPI9 base pointer */
  #define SPI9_NS                                  ((SPI_Type *)SPI9_BASE_NS)
  /** Peripheral SPI10 base address */
  #define SPI10_BASE                               (0x5020B000u)
  /** Peripheral SPI10 base address */
  #define SPI10_BASE_NS                            (0x4020B000u)
  /** Peripheral SPI10 base pointer */
  #define SPI10                                    ((SPI_Type *)SPI10_BASE)
  /** Peripheral SPI10 base pointer */
  #define SPI10_NS                                 ((SPI_Type *)SPI10_BASE_NS)
  /** Peripheral SPI11 base address */
  #define SPI11_BASE                               (0x5020C000u)
  /** Peripheral SPI11 base address */
  #define SPI11_BASE_NS                            (0x4020C000u)
  /** Peripheral SPI11 base pointer */
  #define SPI11                                    ((SPI_Type *)SPI11_BASE)
  /** Peripheral SPI11 base pointer */
  #define SPI11_NS                                 ((SPI_Type *)SPI11_BASE_NS)
  /** Peripheral SPI12 base address */
  #define SPI12_BASE                               (0x5020D000u)
  /** Peripheral SPI12 base address */
  #define SPI12_BASE_NS                            (0x4020D000u)
  /** Peripheral SPI12 base pointer */
  #define SPI12                                    ((SPI_Type *)SPI12_BASE)
  /** Peripheral SPI12 base pointer */
  #define SPI12_NS                                 ((SPI_Type *)SPI12_BASE_NS)
  /** Peripheral SPI13 base address */
  #define SPI13_BASE                               (0x5020E000u)
  /** Peripheral SPI13 base address */
  #define SPI13_BASE_NS                            (0x4020E000u)
  /** Peripheral SPI13 base pointer */
  #define SPI13                                    ((SPI_Type *)SPI13_BASE)
  /** Peripheral SPI13 base pointer */
  #define SPI13_NS                                 ((SPI_Type *)SPI13_BASE_NS)
  /** Peripheral SPI14 base address */
  #define SPI14_BASE                               (0x50126000u)
  /** Peripheral SPI14 base address */
  #define SPI14_BASE_NS                            (0x40126000u)
  /** Peripheral SPI14 base pointer */
  #define SPI14                                    ((SPI_Type *)SPI14_BASE)
  /** Peripheral SPI14 base pointer */
  #define SPI14_NS                                 ((SPI_Type *)SPI14_BASE_NS)
  /** Peripheral SPI16 base address */
  #define SPI16_BASE                               (0x50128000u)
  /** Peripheral SPI16 base address */
  #define SPI16_BASE_NS                            (0x40128000u)
  /** Peripheral SPI16 base pointer */
  #define SPI16                                    ((SPI_Type *)SPI16_BASE)
  /** Peripheral SPI16 base pointer */
  #define SPI16_NS                                 ((SPI_Type *)SPI16_BASE_NS)
  /** Array initializer of SPI peripheral base addresses */
  #define SPI_BASE_ADDRS                           { SPI0_BASE, SPI1_BASE, SPI2_BASE, SPI3_BASE, SPI4_BASE, SPI5_BASE, SPI6_BASE, SPI7_BASE, SPI8_BASE, SPI9_BASE, SPI10_BASE, SPI11_BASE, SPI12_BASE, SPI13_BASE, SPI14_BASE, SPI16_BASE }
  /** Array initializer of SPI peripheral base pointers */
  #define SPI_BASE_PTRS                            { SPI0, SPI1, SPI2, SPI3, SPI4, SPI5, SPI6, SPI7, SPI8, SPI9, SPI10, SPI11, SPI12, SPI13, SPI14, SPI16 }
  /** Array initializer of SPI peripheral base addresses */
  #define SPI_BASE_ADDRS_NS                        { SPI0_BASE_NS, SPI1_BASE_NS, SPI2_BASE_NS, SPI3_BASE_NS, SPI4_BASE_NS, SPI5_BASE_NS, SPI6_BASE_NS, SPI7_BASE_NS, SPI8_BASE_NS, SPI9_BASE_NS, SPI10_BASE_NS, SPI11_BASE_NS, SPI12_BASE_NS, SPI13_BASE_NS, SPI14_BASE_NS, SPI16_BASE_NS }
  /** Array initializer of SPI peripheral base pointers */
  #define SPI_BASE_PTRS_NS                         { SPI0_NS, SPI1_NS, SPI2_NS, SPI3_NS, SPI4_NS, SPI5_NS, SPI6_NS, SPI7_NS, SPI8_NS, SPI9_NS, SPI10_NS, SPI11_NS, SPI12_NS, SPI13_NS, SPI14_NS, SPI16_NS }
#else
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
#endif
/** Interrupt vectors for the SPI peripheral type */
#define SPI_IRQS                                 { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, FLEXCOMM8_IRQn, FLEXCOMM9_IRQn, FLEXCOMM10_IRQn, FLEXCOMM11_IRQn, FLEXCOMM12_IRQn, FLEXCOMM13_IRQn, FLEXCOMM14_IRQn, FLEXCOMM16_IRQn }

/* SYSCTL0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCTL0 base address */
  #define SYSCTL0_BASE                             (0x50002000u)
  /** Peripheral SYSCTL0 base address */
  #define SYSCTL0_BASE_NS                          (0x40002000u)
  /** Peripheral SYSCTL0 base pointer */
  #define SYSCTL0                                  ((SYSCTL0_Type *)SYSCTL0_BASE)
  /** Peripheral SYSCTL0 base pointer */
  #define SYSCTL0_NS                               ((SYSCTL0_Type *)SYSCTL0_BASE_NS)
  /** Array initializer of SYSCTL0 peripheral base addresses */
  #define SYSCTL0_BASE_ADDRS                       { SYSCTL0_BASE }
  /** Array initializer of SYSCTL0 peripheral base pointers */
  #define SYSCTL0_BASE_PTRS                        { SYSCTL0 }
  /** Array initializer of SYSCTL0 peripheral base addresses */
  #define SYSCTL0_BASE_ADDRS_NS                    { SYSCTL0_BASE_NS }
  /** Array initializer of SYSCTL0 peripheral base pointers */
  #define SYSCTL0_BASE_PTRS_NS                     { SYSCTL0_NS }
#else
  /** Peripheral SYSCTL0 base address */
  #define SYSCTL0_BASE                             (0x40002000u)
  /** Peripheral SYSCTL0 base pointer */
  #define SYSCTL0                                  ((SYSCTL0_Type *)SYSCTL0_BASE)
  /** Array initializer of SYSCTL0 peripheral base addresses */
  #define SYSCTL0_BASE_ADDRS                       { SYSCTL0_BASE }
  /** Array initializer of SYSCTL0 peripheral base pointers */
  #define SYSCTL0_BASE_PTRS                        { SYSCTL0 }
#endif

/* SYSCTL1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCTL1 base address */
  #define SYSCTL1_BASE                             (0x50022000u)
  /** Peripheral SYSCTL1 base address */
  #define SYSCTL1_BASE_NS                          (0x40022000u)
  /** Peripheral SYSCTL1 base pointer */
  #define SYSCTL1                                  ((SYSCTL1_Type *)SYSCTL1_BASE)
  /** Peripheral SYSCTL1 base pointer */
  #define SYSCTL1_NS                               ((SYSCTL1_Type *)SYSCTL1_BASE_NS)
  /** Array initializer of SYSCTL1 peripheral base addresses */
  #define SYSCTL1_BASE_ADDRS                       { SYSCTL1_BASE }
  /** Array initializer of SYSCTL1 peripheral base pointers */
  #define SYSCTL1_BASE_PTRS                        { SYSCTL1 }
  /** Array initializer of SYSCTL1 peripheral base addresses */
  #define SYSCTL1_BASE_ADDRS_NS                    { SYSCTL1_BASE_NS }
  /** Array initializer of SYSCTL1 peripheral base pointers */
  #define SYSCTL1_BASE_PTRS_NS                     { SYSCTL1_NS }
#else
  /** Peripheral SYSCTL1 base address */
  #define SYSCTL1_BASE                             (0x40022000u)
  /** Peripheral SYSCTL1 base pointer */
  #define SYSCTL1                                  ((SYSCTL1_Type *)SYSCTL1_BASE)
  /** Array initializer of SYSCTL1 peripheral base addresses */
  #define SYSCTL1_BASE_ADDRS                       { SYSCTL1_BASE }
  /** Array initializer of SYSCTL1 peripheral base pointers */
  #define SYSCTL1_BASE_PTRS                        { SYSCTL1 }
#endif

/* TRNG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRNG base address */
  #define TRNG_BASE                                (0x50138000u)
  /** Peripheral TRNG base address */
  #define TRNG_BASE_NS                             (0x40138000u)
  /** Peripheral TRNG base pointer */
  #define TRNG                                     ((TRNG_Type *)TRNG_BASE)
  /** Peripheral TRNG base pointer */
  #define TRNG_NS                                  ((TRNG_Type *)TRNG_BASE_NS)
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS                          { TRNG_BASE }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS                           { TRNG }
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS_NS                       { TRNG_BASE_NS }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS_NS                        { TRNG_NS }
#else
  /** Peripheral TRNG base address */
  #define TRNG_BASE                                (0x40138000u)
  /** Peripheral TRNG base pointer */
  #define TRNG                                     ((TRNG_Type *)TRNG_BASE)
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS                          { TRNG_BASE }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS                           { TRNG }
#endif
/** Interrupt vectors for the TRNG peripheral type */
#define TRNG_IRQS                                { RNG_IRQn }

/* USART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USART0 base address */
  #define USART0_BASE                              (0x50106000u)
  /** Peripheral USART0 base address */
  #define USART0_BASE_NS                           (0x40106000u)
  /** Peripheral USART0 base pointer */
  #define USART0                                   ((USART_Type *)USART0_BASE)
  /** Peripheral USART0 base pointer */
  #define USART0_NS                                ((USART_Type *)USART0_BASE_NS)
  /** Peripheral USART1 base address */
  #define USART1_BASE                              (0x50107000u)
  /** Peripheral USART1 base address */
  #define USART1_BASE_NS                           (0x40107000u)
  /** Peripheral USART1 base pointer */
  #define USART1                                   ((USART_Type *)USART1_BASE)
  /** Peripheral USART1 base pointer */
  #define USART1_NS                                ((USART_Type *)USART1_BASE_NS)
  /** Peripheral USART2 base address */
  #define USART2_BASE                              (0x50108000u)
  /** Peripheral USART2 base address */
  #define USART2_BASE_NS                           (0x40108000u)
  /** Peripheral USART2 base pointer */
  #define USART2                                   ((USART_Type *)USART2_BASE)
  /** Peripheral USART2 base pointer */
  #define USART2_NS                                ((USART_Type *)USART2_BASE_NS)
  /** Peripheral USART3 base address */
  #define USART3_BASE                              (0x50109000u)
  /** Peripheral USART3 base address */
  #define USART3_BASE_NS                           (0x40109000u)
  /** Peripheral USART3 base pointer */
  #define USART3                                   ((USART_Type *)USART3_BASE)
  /** Peripheral USART3 base pointer */
  #define USART3_NS                                ((USART_Type *)USART3_BASE_NS)
  /** Peripheral USART4 base address */
  #define USART4_BASE                              (0x50122000u)
  /** Peripheral USART4 base address */
  #define USART4_BASE_NS                           (0x40122000u)
  /** Peripheral USART4 base pointer */
  #define USART4                                   ((USART_Type *)USART4_BASE)
  /** Peripheral USART4 base pointer */
  #define USART4_NS                                ((USART_Type *)USART4_BASE_NS)
  /** Peripheral USART5 base address */
  #define USART5_BASE                              (0x50123000u)
  /** Peripheral USART5 base address */
  #define USART5_BASE_NS                           (0x40123000u)
  /** Peripheral USART5 base pointer */
  #define USART5                                   ((USART_Type *)USART5_BASE)
  /** Peripheral USART5 base pointer */
  #define USART5_NS                                ((USART_Type *)USART5_BASE_NS)
  /** Peripheral USART6 base address */
  #define USART6_BASE                              (0x50124000u)
  /** Peripheral USART6 base address */
  #define USART6_BASE_NS                           (0x40124000u)
  /** Peripheral USART6 base pointer */
  #define USART6                                   ((USART_Type *)USART6_BASE)
  /** Peripheral USART6 base pointer */
  #define USART6_NS                                ((USART_Type *)USART6_BASE_NS)
  /** Peripheral USART7 base address */
  #define USART7_BASE                              (0x50125000u)
  /** Peripheral USART7 base address */
  #define USART7_BASE_NS                           (0x40125000u)
  /** Peripheral USART7 base pointer */
  #define USART7                                   ((USART_Type *)USART7_BASE)
  /** Peripheral USART7 base pointer */
  #define USART7_NS                                ((USART_Type *)USART7_BASE_NS)
  /** Peripheral USART8 base address */
  #define USART8_BASE                              (0x50209000u)
  /** Peripheral USART8 base address */
  #define USART8_BASE_NS                           (0x40209000u)
  /** Peripheral USART8 base pointer */
  #define USART8                                   ((USART_Type *)USART8_BASE)
  /** Peripheral USART8 base pointer */
  #define USART8_NS                                ((USART_Type *)USART8_BASE_NS)
  /** Peripheral USART9 base address */
  #define USART9_BASE                              (0x5020A000u)
  /** Peripheral USART9 base address */
  #define USART9_BASE_NS                           (0x4020A000u)
  /** Peripheral USART9 base pointer */
  #define USART9                                   ((USART_Type *)USART9_BASE)
  /** Peripheral USART9 base pointer */
  #define USART9_NS                                ((USART_Type *)USART9_BASE_NS)
  /** Peripheral USART10 base address */
  #define USART10_BASE                             (0x5020B000u)
  /** Peripheral USART10 base address */
  #define USART10_BASE_NS                          (0x4020B000u)
  /** Peripheral USART10 base pointer */
  #define USART10                                  ((USART_Type *)USART10_BASE)
  /** Peripheral USART10 base pointer */
  #define USART10_NS                               ((USART_Type *)USART10_BASE_NS)
  /** Peripheral USART11 base address */
  #define USART11_BASE                             (0x5020C000u)
  /** Peripheral USART11 base address */
  #define USART11_BASE_NS                          (0x4020C000u)
  /** Peripheral USART11 base pointer */
  #define USART11                                  ((USART_Type *)USART11_BASE)
  /** Peripheral USART11 base pointer */
  #define USART11_NS                               ((USART_Type *)USART11_BASE_NS)
  /** Peripheral USART12 base address */
  #define USART12_BASE                             (0x5020D000u)
  /** Peripheral USART12 base address */
  #define USART12_BASE_NS                          (0x4020D000u)
  /** Peripheral USART12 base pointer */
  #define USART12                                  ((USART_Type *)USART12_BASE)
  /** Peripheral USART12 base pointer */
  #define USART12_NS                               ((USART_Type *)USART12_BASE_NS)
  /** Peripheral USART13 base address */
  #define USART13_BASE                             (0x5020E000u)
  /** Peripheral USART13 base address */
  #define USART13_BASE_NS                          (0x4020E000u)
  /** Peripheral USART13 base pointer */
  #define USART13                                  ((USART_Type *)USART13_BASE)
  /** Peripheral USART13 base pointer */
  #define USART13_NS                               ((USART_Type *)USART13_BASE_NS)
  /** Array initializer of USART peripheral base addresses */
  #define USART_BASE_ADDRS                         { USART0_BASE, USART1_BASE, USART2_BASE, USART3_BASE, USART4_BASE, USART5_BASE, USART6_BASE, USART7_BASE, USART8_BASE, USART9_BASE, USART10_BASE, USART11_BASE, USART12_BASE, USART13_BASE }
  /** Array initializer of USART peripheral base pointers */
  #define USART_BASE_PTRS                          { USART0, USART1, USART2, USART3, USART4, USART5, USART6, USART7, USART8, USART9, USART10, USART11, USART12, USART13 }
  /** Array initializer of USART peripheral base addresses */
  #define USART_BASE_ADDRS_NS                      { USART0_BASE_NS, USART1_BASE_NS, USART2_BASE_NS, USART3_BASE_NS, USART4_BASE_NS, USART5_BASE_NS, USART6_BASE_NS, USART7_BASE_NS, USART8_BASE_NS, USART9_BASE_NS, USART10_BASE_NS, USART11_BASE_NS, USART12_BASE_NS, USART13_BASE_NS }
  /** Array initializer of USART peripheral base pointers */
  #define USART_BASE_PTRS_NS                       { USART0_NS, USART1_NS, USART2_NS, USART3_NS, USART4_NS, USART5_NS, USART6_NS, USART7_NS, USART8_NS, USART9_NS, USART10_NS, USART11_NS, USART12_NS, USART13_NS }
#else
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
#endif
/** Interrupt vectors for the USART peripheral type */
#define USART_IRQS                               { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, FLEXCOMM8_IRQn, FLEXCOMM9_IRQn, FLEXCOMM10_IRQn, FLEXCOMM11_IRQn, FLEXCOMM12_IRQn, FLEXCOMM13_IRQn }

/* USBHSD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBHSD base address */
  #define USBHSD_BASE                              (0x50144000u)
  /** Peripheral USBHSD base address */
  #define USBHSD_BASE_NS                           (0x40144000u)
  /** Peripheral USBHSD base pointer */
  #define USBHSD                                   ((USBHSD_Type *)USBHSD_BASE)
  /** Peripheral USBHSD base pointer */
  #define USBHSD_NS                                ((USBHSD_Type *)USBHSD_BASE_NS)
  /** Array initializer of USBHSD peripheral base addresses */
  #define USBHSD_BASE_ADDRS                        { USBHSD_BASE }
  /** Array initializer of USBHSD peripheral base pointers */
  #define USBHSD_BASE_PTRS                         { USBHSD }
  /** Array initializer of USBHSD peripheral base addresses */
  #define USBHSD_BASE_ADDRS_NS                     { USBHSD_BASE_NS }
  /** Array initializer of USBHSD peripheral base pointers */
  #define USBHSD_BASE_PTRS_NS                      { USBHSD_NS }
#else
  /** Peripheral USBHSD base address */
  #define USBHSD_BASE                              (0x40144000u)
  /** Peripheral USBHSD base pointer */
  #define USBHSD                                   ((USBHSD_Type *)USBHSD_BASE)
  /** Array initializer of USBHSD peripheral base addresses */
  #define USBHSD_BASE_ADDRS                        { USBHSD_BASE }
  /** Array initializer of USBHSD peripheral base pointers */
  #define USBHSD_BASE_PTRS                         { USBHSD }
#endif
/** Interrupt vectors for the USBHSD peripheral type */
#define USBHSD_IRQS                              { USB0_IRQn }

/* USBHSDCD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBHSDCD base address */
  #define USBHSDCD_BASE                            (0x5013B800u)
  /** Peripheral USBHSDCD base address */
  #define USBHSDCD_BASE_NS                         (0x4013B800u)
  /** Peripheral USBHSDCD base pointer */
  #define USBHSDCD                                 ((USBHSDCD_Type *)USBHSDCD_BASE)
  /** Peripheral USBHSDCD base pointer */
  #define USBHSDCD_NS                              ((USBHSDCD_Type *)USBHSDCD_BASE_NS)
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS                      { USBHSDCD_BASE }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS                       { USBHSDCD }
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS_NS                   { USBHSDCD_BASE_NS }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS_NS                    { USBHSDCD_NS }
#else
  /** Peripheral USBHSDCD base address */
  #define USBHSDCD_BASE                            (0x4013B800u)
  /** Peripheral USBHSDCD base pointer */
  #define USBHSDCD                                 ((USBHSDCD_Type *)USBHSDCD_BASE)
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS                      { USBHSDCD_BASE }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS                       { USBHSDCD }
#endif
/** Interrupt vectors for the USBHSDCD peripheral type */
#define USBHSDCD_IRQS                            { USB_PHYDCD_IRQn }

/* USBHSH - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBHSH base address */
  #define USBHSH_BASE                              (0x50145000u)
  /** Peripheral USBHSH base address */
  #define USBHSH_BASE_NS                           (0x40145000u)
  /** Peripheral USBHSH base pointer */
  #define USBHSH                                   ((USBHSH_Type *)USBHSH_BASE)
  /** Peripheral USBHSH base pointer */
  #define USBHSH_NS                                ((USBHSH_Type *)USBHSH_BASE_NS)
  /** Array initializer of USBHSH peripheral base addresses */
  #define USBHSH_BASE_ADDRS                        { USBHSH_BASE }
  /** Array initializer of USBHSH peripheral base pointers */
  #define USBHSH_BASE_PTRS                         { USBHSH }
  /** Array initializer of USBHSH peripheral base addresses */
  #define USBHSH_BASE_ADDRS_NS                     { USBHSH_BASE_NS }
  /** Array initializer of USBHSH peripheral base pointers */
  #define USBHSH_BASE_PTRS_NS                      { USBHSH_NS }
#else
  /** Peripheral USBHSH base address */
  #define USBHSH_BASE                              (0x40145000u)
  /** Peripheral USBHSH base pointer */
  #define USBHSH                                   ((USBHSH_Type *)USBHSH_BASE)
  /** Array initializer of USBHSH peripheral base addresses */
  #define USBHSH_BASE_ADDRS                        { USBHSH_BASE }
  /** Array initializer of USBHSH peripheral base pointers */
  #define USBHSH_BASE_PTRS                         { USBHSH }
#endif
/** Interrupt vectors for the USBHSH peripheral type */
#define USBHSH_IRQS                              { USB0_IRQn }
#define USBHSH_NEEDCLK_IRQS                      { USB0_NEEDCLK_IRQn }

/* USBPHY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBPHY base address */
  #define USBPHY_BASE                              (0x5013B000u)
  /** Peripheral USBPHY base address */
  #define USBPHY_BASE_NS                           (0x4013B000u)
  /** Peripheral USBPHY base pointer */
  #define USBPHY                                   ((USBPHY_Type *)USBPHY_BASE)
  /** Peripheral USBPHY base pointer */
  #define USBPHY_NS                                ((USBPHY_Type *)USBPHY_BASE_NS)
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS                        { USBPHY_BASE }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS                         { USBPHY }
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS_NS                     { USBPHY_BASE_NS }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS_NS                      { USBPHY_NS }
#else
  /** Peripheral USBPHY base address */
  #define USBPHY_BASE                              (0x4013B000u)
  /** Peripheral USBPHY base pointer */
  #define USBPHY                                   ((USBPHY_Type *)USBPHY_BASE)
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS                        { USBPHY_BASE }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS                         { USBPHY }
#endif

/* USDHC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USDHC0 base address */
  #define USDHC0_BASE                              (0x50136000u)
  /** Peripheral USDHC0 base address */
  #define USDHC0_BASE_NS                           (0x40136000u)
  /** Peripheral USDHC0 base pointer */
  #define USDHC0                                   ((USDHC_Type *)USDHC0_BASE)
  /** Peripheral USDHC0 base pointer */
  #define USDHC0_NS                                ((USDHC_Type *)USDHC0_BASE_NS)
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE                              (0x50137000u)
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE_NS                           (0x40137000u)
  /** Peripheral USDHC1 base pointer */
  #define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
  /** Peripheral USDHC1 base pointer */
  #define USDHC1_NS                                ((USDHC_Type *)USDHC1_BASE_NS)
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS                         { USDHC0_BASE, USDHC1_BASE }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS                          { USDHC0, USDHC1 }
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS_NS                      { USDHC0_BASE_NS, USDHC1_BASE_NS }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS_NS                       { USDHC0_NS, USDHC1_NS }
#else
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
#endif
/** Interrupt vectors for the USDHC peripheral type */
#define USDHC_IRQS                               { USDHC0_IRQn, USDHC1_IRQn }

/* UTICK - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral UTICK0 base address */
  #define UTICK0_BASE                              (0x5000F000u)
  /** Peripheral UTICK0 base address */
  #define UTICK0_BASE_NS                           (0x4000F000u)
  /** Peripheral UTICK0 base pointer */
  #define UTICK0                                   ((UTICK_Type *)UTICK0_BASE)
  /** Peripheral UTICK0 base pointer */
  #define UTICK0_NS                                ((UTICK_Type *)UTICK0_BASE_NS)
  /** Array initializer of UTICK peripheral base addresses */
  #define UTICK_BASE_ADDRS                         { UTICK0_BASE }
  /** Array initializer of UTICK peripheral base pointers */
  #define UTICK_BASE_PTRS                          { UTICK0 }
  /** Array initializer of UTICK peripheral base addresses */
  #define UTICK_BASE_ADDRS_NS                      { UTICK0_BASE_NS }
  /** Array initializer of UTICK peripheral base pointers */
  #define UTICK_BASE_PTRS_NS                       { UTICK0_NS }
#else
  /** Peripheral UTICK0 base address */
  #define UTICK0_BASE                              (0x4000F000u)
  /** Peripheral UTICK0 base pointer */
  #define UTICK0                                   ((UTICK_Type *)UTICK0_BASE)
  /** Array initializer of UTICK peripheral base addresses */
  #define UTICK_BASE_ADDRS                         { UTICK0_BASE }
  /** Array initializer of UTICK peripheral base pointers */
  #define UTICK_BASE_PTRS                          { UTICK0 }
#endif
/** Interrupt vectors for the UTICK peripheral type */
#define UTICK_IRQS                               { UTICK0_IRQn }

/* WWDT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WWDT0 base address */
  #define WWDT0_BASE                               (0x5000E000u)
  /** Peripheral WWDT0 base address */
  #define WWDT0_BASE_NS                            (0x4000E000u)
  /** Peripheral WWDT0 base pointer */
  #define WWDT0                                    ((WWDT_Type *)WWDT0_BASE)
  /** Peripheral WWDT0 base pointer */
  #define WWDT0_NS                                 ((WWDT_Type *)WWDT0_BASE_NS)
  /** Peripheral WWDT1 base address */
  #define WWDT1_BASE                               (0x5002E000u)
  /** Peripheral WWDT1 base address */
  #define WWDT1_BASE_NS                            (0x4002E000u)
  /** Peripheral WWDT1 base pointer */
  #define WWDT1                                    ((WWDT_Type *)WWDT1_BASE)
  /** Peripheral WWDT1 base pointer */
  #define WWDT1_NS                                 ((WWDT_Type *)WWDT1_BASE_NS)
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS                          { WWDT0_BASE, WWDT1_BASE }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS                           { WWDT0, WWDT1 }
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS_NS                       { WWDT0_BASE_NS, WWDT1_BASE_NS }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS_NS                        { WWDT0_NS, WWDT1_NS }
#else
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
#endif
/** Interrupt vectors for the WWDT peripheral type */
#define WWDT_IRQS                                { WDT0_IRQn, WDT1_IRQn }

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

/**  Used for get the base address of ROM API */
#define FSL_ROM_API_BASE_ADDR 0x1302F000U

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* MIMXRT533S_COMMON_H_ */

