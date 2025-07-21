/*
** ###################################################################
**     Processors:          KW45Z41052AFPA
**                          KW45Z41052AFTA
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    Rev. 6, 05/22/2022
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for KW45Z41052
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file KW45Z41052_COMMON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for KW45Z41052
 *
 * CMSIS Peripheral Access Layer for KW45Z41052
 */

#if !defined(KW45Z41052_COMMON_H_)
#define KW45Z41052_COMMON_H_                     /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 92                 /**< Number of interrupts in the Vector table */

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
  CTI_IRQn                     = 0,                /**< Cross Trigger Interface interrupt */
  CMC0_IRQn                    = 1,                /**< Core Mode Controller interrupt */
  DMA0_CH0_IRQn                = 2,                /**< eDMA channel 0 error or transfer complete */
  DMA0_CH1_IRQn                = 3,                /**< eDMA channel 1 error or transfer complete */
  DMA0_CH2_IRQn                = 4,                /**< eDMA channel 2 error or transfer complete */
  DMA0_CH3_IRQn                = 5,                /**< eDMA channel 3 error or transfer complete */
  DMA0_CH4_IRQn                = 6,                /**< eDMA channel 4 error or transfer complete */
  DMA0_CH5_IRQn                = 7,                /**< eDMA channel 5 error or transfer complete */
  DMA0_CH6_IRQn                = 8,                /**< eDMA channel 6 error or transfer complete */
  DMA0_CH7_IRQn                = 9,                /**< eDMA channel 7 error or transfer complete */
  DMA0_CH8_IRQn                = 10,               /**< eDMA channel 8 error or transfer complete */
  DMA0_CH9_IRQn                = 11,               /**< eDMA channel 9 error or transfer complete */
  DMA0_CH10_IRQn               = 12,               /**< eDMA channel 10 error or transfer complete */
  DMA0_CH11_IRQn               = 13,               /**< eDMA channel 11 error or transfer complete */
  DMA0_CH12_IRQn               = 14,               /**< eDMA channel 12 error or transfer complete */
  DMA0_CH13_IRQn               = 15,               /**< eDMA channel 13 error or transfer complete */
  DMA0_CH14_IRQn               = 16,               /**< eDMA channel 14 error or transfer complete */
  DMA0_CH15_IRQn               = 17,               /**< eDMA channel 15 error or transfer complete */
  EWM0_IRQn                    = 18,               /**< External Watchdog Monitor 0 interrupt */
  MCM0_IRQn                    = 19,               /**< Miscellaneous Control Module interrupt */
  MSCM0_IRQn                   = 20,               /**< Miscellaneous System Control Module interrupt */
  SPC0_IRQn                    = 21,               /**< System Power Controller 0 interrupt */
  WUU0_IRQn                    = 22,               /**< Wake-Up Unit 0 interrupt */
  WDOG0_IRQn                   = 23,               /**< Watchdog Timer 0 interrupt */
  WDOG1_IRQn                   = 24,               /**< Watchdog Timer 1 interrupt */
  SCG0_IRQn                    = 25,               /**< System Clock Generator 0 interrupt */
  SFA0_IRQn                    = 26,               /**< Singal Frequency Analyzer 0 interrupt */
  FMU0_IRQn                    = 27,               /**< Flash Memory Unit 0 interrupt */
  ELE_CMD_IRQn                 = 28,               /**< EdgeLock enclave command interface interrupt */
  ELE_SECURE_IRQn              = 29,               /**< EdgeLock enclave interrupt */
  ELE_NONSECURE_IRQn           = 30,               /**< EdgeLock enclave non-secure interrupt */
  TRDC0_IRQn                   = 31,               /**< Trusted Resource Domain Controller 0 interrupt */
  RTC_Alarm_IRQn               = 32,               /**< Real Time Clock 0 alarm interrupt */
  RTC_Seconds_IRQn             = 33,               /**< Real Time Clock 0 seconds interrupt */
  LPTMR0_IRQn                  = 34,               /**< Low-Power Timer0 interrupt */
  LPTMR1_IRQn                  = 35,               /**< Low-Power Timer1 interrupt */
  LPIT0_IRQn                   = 36,               /**< Low-Power Periodic Interrupt Timer 0 interrupt */
  TPM0_IRQn                    = 37,               /**< Timer / PWM Module 0 interrupt */
  TPM1_IRQn                    = 38,               /**< Timer / PWM Module 1 interrupt */
  LPI2C0_IRQn                  = 39,               /**< Low-Power Inter Integrated Circuit 0 interrupt */
  LPI2C1_IRQn                  = 40,               /**< Low-Power Inter Integrated Circuit 1 interrupt */
  I3C0_IRQn                    = 41,               /**< Improved Inter-Integrated Circuit 0 interrupt */
  LPSPI0_IRQn                  = 42,               /**< Low-Power Serial Peripheral Interface 0 interrupt */
  LPSPI1_IRQn                  = 43,               /**< Low-Power Serial Peripheral Interface 1 interrupt */
  LPUART0_IRQn                 = 44,               /**< Low-Power Universal Asynchronous Receiver/Transmitter 0 interrupt */
  LPUART1_IRQn                 = 45,               /**< Low-Power Universal Asynchronous Receiver/Transmitter 1 interrupt */
  FLEXIO0_IRQn                 = 46,               /**< Flexible Input/Output 0 interrupt */
  Reserved63_IRQn              = 47,               /**< Reserved interrupt */
  Reserved64_IRQn              = 48,               /**< Reserved interrupt */
  Reserved65_IRQn              = 49,               /**< Reserved interrupt */
  Reserved66_IRQn              = 50,               /**< Reserved interrupt */
  Reserved67_IRQn              = 51,               /**< Reserved interrupt */
  Reserved68_IRQn              = 52,               /**< Reserved interrupt */
  Reserved69_IRQn              = 53,               /**< Reserved interrupt */
  Reserved70_IRQn              = 54,               /**< Reserved interrupt */
  Reserved71_IRQn              = 55,               /**< Reserved interrupt */
  Reserved72_IRQn              = 56,               /**< Reserved interrupt */
  Reserved73_IRQn              = 57,               /**< Reserved interrupt */
  Reserved74_IRQn              = 58,               /**< Reserved interrupt */
  GPIOA_INT0_IRQn              = 59,               /**< General Purpose Input/Output A interrupt 0 */
  GPIOA_INT1_IRQn              = 60,               /**< General Purpose Input/Output A interrupt 1 */
  GPIOB_INT0_IRQn              = 61,               /**< General Purpose Input/Output B interrupt 0 */
  GPIOB_INT1_IRQn              = 62,               /**< General Purpose Input/Output B interrupt 1 */
  GPIOC_INT0_IRQn              = 63,               /**< General Purpose Input/Output C interrupt 0 */
  GPIOC_INT1_IRQn              = 64,               /**< General Purpose Input/Output C interrupt 1 */
  GPIOD_INT0_IRQn              = 65,               /**< General Purpose Input/Output D interrupt 0 */
  GPIOD_INT1_IRQn              = 66,               /**< General Purpose Input/Output D interrupt 1 */
  PORTA_EFT_IRQn               = 67,               /**< PortA EFT interrupt */
  PORTB_EFT_IRQn               = 68,               /**< PortB EFT interrupt */
  PORTC_EFT_IRQn               = 69,               /**< PortC EFT interrupt */
  PORTD_EFT_IRQn               = 70,               /**< PortD EFT interrupt */
  ADC0_IRQn                    = 71,               /**< Analog-to-Digital Converter 0 interrupt */
  LPCMP0_IRQn                  = 72,               /**< Low-Power Comparator 0 interrupt */
  LPCMP1_IRQn                  = 73,               /**< Low-Power Comparator 1 interrupt */
  VBAT_IRQn                    = 74,               /**< Smart Power Switch Domain interrupt */
  Reserved91_IRQn              = 75                /**< Reserved interrupt */
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
#include "system_KW45Z41052.h"         /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef KW45Z41052_SERIES
#define KW45Z41052_SERIES
#endif
/* CPU specific feature definitions */
#include "KW45Z41052_features.h"

/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADC0 base address */
  #define ADC0_BASE                                (0x50047000u)
  /** Peripheral ADC0 base address */
  #define ADC0_BASE_NS                             (0x40047000u)
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
  #define ADC0_BASE                                (0x40047000u)
  /** Peripheral ADC0 base pointer */
  #define ADC0                                     ((ADC_Type *)ADC0_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC0_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC0 }
#endif
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn }

/* AXBS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AXBS0 base address */
  #define AXBS0_BASE                               (0x50000000u)
  /** Peripheral AXBS0 base address */
  #define AXBS0_BASE_NS                            (0x40000000u)
  /** Peripheral AXBS0 base pointer */
  #define AXBS0                                    ((AXBS_Type *)AXBS0_BASE)
  /** Peripheral AXBS0 base pointer */
  #define AXBS0_NS                                 ((AXBS_Type *)AXBS0_BASE_NS)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { AXBS0_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { AXBS0 }
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS_NS                       { AXBS0_BASE_NS }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS_NS                        { AXBS0_NS }
#else
  /** Peripheral AXBS0 base address */
  #define AXBS0_BASE                               (0x40000000u)
  /** Peripheral AXBS0 base pointer */
  #define AXBS0                                    ((AXBS_Type *)AXBS0_BASE)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { AXBS0_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { AXBS0 }
#endif

/* BRIC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BRIC base address */
  #define BRIC_BASE                                (0x58A06700u)
  /** Peripheral BRIC base address */
  #define BRIC_BASE_NS                             (0x48A06700u)
  /** Peripheral BRIC base pointer */
  #define BRIC                                     ((BRIC_Type *)BRIC_BASE)
  /** Peripheral BRIC base pointer */
  #define BRIC_NS                                  ((BRIC_Type *)BRIC_BASE_NS)
  /** Array initializer of BRIC peripheral base addresses */
  #define BRIC_BASE_ADDRS                          { BRIC_BASE }
  /** Array initializer of BRIC peripheral base pointers */
  #define BRIC_BASE_PTRS                           { BRIC }
  /** Array initializer of BRIC peripheral base addresses */
  #define BRIC_BASE_ADDRS_NS                       { BRIC_BASE_NS }
  /** Array initializer of BRIC peripheral base pointers */
  #define BRIC_BASE_PTRS_NS                        { BRIC_NS }
#else
  /** Peripheral BRIC base address */
  #define BRIC_BASE                                (0x48A06700u)
  /** Peripheral BRIC base pointer */
  #define BRIC                                     ((BRIC_Type *)BRIC_BASE)
  /** Array initializer of BRIC peripheral base addresses */
  #define BRIC_BASE_ADDRS                          { BRIC_BASE }
  /** Array initializer of BRIC peripheral base pointers */
  #define BRIC_BASE_PTRS                           { BRIC }
#endif

/* CCM32K - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CCM32K base address */
  #define CCM32K_BASE                              (0x5001F000u)
  /** Peripheral CCM32K base address */
  #define CCM32K_BASE_NS                           (0x4001F000u)
  /** Peripheral CCM32K base pointer */
  #define CCM32K                                   ((CCM32K_Type *)CCM32K_BASE)
  /** Peripheral CCM32K base pointer */
  #define CCM32K_NS                                ((CCM32K_Type *)CCM32K_BASE_NS)
  /** Array initializer of CCM32K peripheral base addresses */
  #define CCM32K_BASE_ADDRS                        { CCM32K_BASE }
  /** Array initializer of CCM32K peripheral base pointers */
  #define CCM32K_BASE_PTRS                         { CCM32K }
  /** Array initializer of CCM32K peripheral base addresses */
  #define CCM32K_BASE_ADDRS_NS                     { CCM32K_BASE_NS }
  /** Array initializer of CCM32K peripheral base pointers */
  #define CCM32K_BASE_PTRS_NS                      { CCM32K_NS }
#else
  /** Peripheral CCM32K base address */
  #define CCM32K_BASE                              (0x4001F000u)
  /** Peripheral CCM32K base pointer */
  #define CCM32K                                   ((CCM32K_Type *)CCM32K_BASE)
  /** Array initializer of CCM32K peripheral base addresses */
  #define CCM32K_BASE_ADDRS                        { CCM32K_BASE }
  /** Array initializer of CCM32K peripheral base pointers */
  #define CCM32K_BASE_PTRS                         { CCM32K }
#endif

/* CMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMC0 base address */
  #define CMC0_BASE                                (0x50001000u)
  /** Peripheral CMC0 base address */
  #define CMC0_BASE_NS                             (0x40001000u)
  /** Peripheral CMC0 base pointer */
  #define CMC0                                     ((CMC_Type *)CMC0_BASE)
  /** Peripheral CMC0 base pointer */
  #define CMC0_NS                                  ((CMC_Type *)CMC0_BASE_NS)
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS                           { CMC0_BASE }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS                            { CMC0 }
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS_NS                        { CMC0_BASE_NS }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS_NS                         { CMC0_NS }
#else
  /** Peripheral CMC0 base address */
  #define CMC0_BASE                                (0x40001000u)
  /** Peripheral CMC0 base pointer */
  #define CMC0                                     ((CMC_Type *)CMC0_BASE)
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS                           { CMC0_BASE }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS                            { CMC0 }
#endif

/* CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CRC0 base address */
  #define CRC0_BASE                                (0x50023000u)
  /** Peripheral CRC0 base address */
  #define CRC0_BASE_NS                             (0x40023000u)
  /** Peripheral CRC0 base pointer */
  #define CRC0                                     ((CRC_Type *)CRC0_BASE)
  /** Peripheral CRC0 base pointer */
  #define CRC0_NS                                  ((CRC_Type *)CRC0_BASE_NS)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC0_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC0 }
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS_NS                        { CRC0_BASE_NS }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS_NS                         { CRC0_NS }
#else
  /** Peripheral CRC0 base address */
  #define CRC0_BASE                                (0x40023000u)
  /** Peripheral CRC0 base pointer */
  #define CRC0                                     ((CRC_Type *)CRC0_BASE)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC0_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC0 }
#endif

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA0 base address */
  #define DMA0_BASE                                (0x50002000u)
  /** Peripheral DMA0 base address */
  #define DMA0_BASE_NS                             (0x40002000u)
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
  #define DMA0_BASE                                (0x40002000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA0_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA0 }
#endif
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { DMA0_CH0_IRQn, DMA0_CH1_IRQn, DMA0_CH2_IRQn, DMA0_CH3_IRQn, DMA0_CH4_IRQn, DMA0_CH5_IRQn, DMA0_CH6_IRQn, DMA0_CH7_IRQn, DMA0_CH8_IRQn, DMA0_CH9_IRQn, DMA0_CH10_IRQn, DMA0_CH11_IRQn, DMA0_CH12_IRQn, DMA0_CH13_IRQn, DMA0_CH14_IRQn, DMA0_CH15_IRQn } }

/* ELEMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ELEMUA base address */
  #define ELEMUA_BASE                              (0x50024000u)
  /** Peripheral ELEMUA base address */
  #define ELEMUA_BASE_NS                           (0x40024000u)
  /** Peripheral ELEMUA base pointer */
  #define ELEMUA                                   ((ELEMU_Type *)ELEMUA_BASE)
  /** Peripheral ELEMUA base pointer */
  #define ELEMUA_NS                                ((ELEMU_Type *)ELEMUA_BASE_NS)
  /** Array initializer of ELEMU peripheral base addresses */
  #define ELEMU_BASE_ADDRS                         { ELEMUA_BASE }
  /** Array initializer of ELEMU peripheral base pointers */
  #define ELEMU_BASE_PTRS                          { ELEMUA }
  /** Array initializer of ELEMU peripheral base addresses */
  #define ELEMU_BASE_ADDRS_NS                      { ELEMUA_BASE_NS }
  /** Array initializer of ELEMU peripheral base pointers */
  #define ELEMU_BASE_PTRS_NS                       { ELEMUA_NS }
#else
  /** Peripheral ELEMUA base address */
  #define ELEMUA_BASE                              (0x40024000u)
  /** Peripheral ELEMUA base pointer */
  #define ELEMUA                                   ((ELEMU_Type *)ELEMUA_BASE)
  /** Array initializer of ELEMU peripheral base addresses */
  #define ELEMU_BASE_ADDRS                         { ELEMUA_BASE }
  /** Array initializer of ELEMU peripheral base pointers */
  #define ELEMU_BASE_PTRS                          { ELEMUA }
#endif

/* EWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EWM0 base address */
  #define EWM0_BASE                                (0x50013000u)
  /** Peripheral EWM0 base address */
  #define EWM0_BASE_NS                             (0x40013000u)
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
  #define EWM0_BASE                                (0x40013000u)
  /** Peripheral EWM0 base pointer */
  #define EWM0                                     ((EWM_Type *)EWM0_BASE)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { EWM0_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { EWM0 }
#endif
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { EWM0_IRQn }

/* FLEXIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXIO0 base address */
  #define FLEXIO0_BASE                             (0x5003A000u)
  /** Peripheral FLEXIO0 base address */
  #define FLEXIO0_BASE_NS                          (0x4003A000u)
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
  #define FLEXIO0_BASE                             (0x4003A000u)
  /** Peripheral FLEXIO0 base pointer */
  #define FLEXIO0                                  ((FLEXIO_Type *)FLEXIO0_BASE)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { FLEXIO0_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { FLEXIO0 }
#endif
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { FLEXIO0_IRQn }

/* FMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FMU0 base address */
  #define FMU0_BASE                                (0x50020000u)
  /** Peripheral FMU0 base address */
  #define FMU0_BASE_NS                             (0x40020000u)
  /** Peripheral FMU0 base pointer */
  #define FMU0                                     ((FMU_Type *)FMU0_BASE)
  /** Peripheral FMU0 base pointer */
  #define FMU0_NS                                  ((FMU_Type *)FMU0_BASE_NS)
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS                           { FMU0_BASE }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS                            { FMU0 }
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS_NS                        { FMU0_BASE_NS }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS_NS                         { FMU0_NS }
#else
  /** Peripheral FMU0 base address */
  #define FMU0_BASE                                (0x40020000u)
  /** Peripheral FMU0 base pointer */
  #define FMU0                                     ((FMU_Type *)FMU0_BASE)
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS                           { FMU0_BASE }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS                            { FMU0 }
#endif

/* GPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPIOA base address */
  #define GPIOA_BASE                               (0x58010000u)
  /** Peripheral GPIOA base address */
  #define GPIOA_BASE_NS                            (0x48010000u)
  /** Peripheral GPIOA base pointer */
  #define GPIOA                                    ((GPIO_Type *)GPIOA_BASE)
  /** Peripheral GPIOA base pointer */
  #define GPIOA_NS                                 ((GPIO_Type *)GPIOA_BASE_NS)
  /** Peripheral GPIOB base address */
  #define GPIOB_BASE                               (0x58020000u)
  /** Peripheral GPIOB base address */
  #define GPIOB_BASE_NS                            (0x48020000u)
  /** Peripheral GPIOB base pointer */
  #define GPIOB                                    ((GPIO_Type *)GPIOB_BASE)
  /** Peripheral GPIOB base pointer */
  #define GPIOB_NS                                 ((GPIO_Type *)GPIOB_BASE_NS)
  /** Peripheral GPIOC base address */
  #define GPIOC_BASE                               (0x58030000u)
  /** Peripheral GPIOC base address */
  #define GPIOC_BASE_NS                            (0x48030000u)
  /** Peripheral GPIOC base pointer */
  #define GPIOC                                    ((GPIO_Type *)GPIOC_BASE)
  /** Peripheral GPIOC base pointer */
  #define GPIOC_NS                                 ((GPIO_Type *)GPIOC_BASE_NS)
  /** Peripheral GPIOD base address */
  #define GPIOD_BASE                               (0x50046000u)
  /** Peripheral GPIOD base address */
  #define GPIOD_BASE_NS                            (0x40046000u)
  /** Peripheral GPIOD base pointer */
  #define GPIOD                                    ((GPIO_Type *)GPIOD_BASE)
  /** Peripheral GPIOD base pointer */
  #define GPIOD_NS                                 ((GPIO_Type *)GPIOD_BASE_NS)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { GPIOA, GPIOB, GPIOC, GPIOD }
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS_NS                       { GPIOA_BASE_NS, GPIOB_BASE_NS, GPIOC_BASE_NS, GPIOD_BASE_NS }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS_NS                        { GPIOA_NS, GPIOB_NS, GPIOC_NS, GPIOD_NS }
#else
  /** Peripheral GPIOA base address */
  #define GPIOA_BASE                               (0x48010000u)
  /** Peripheral GPIOA base pointer */
  #define GPIOA                                    ((GPIO_Type *)GPIOA_BASE)
  /** Peripheral GPIOB base address */
  #define GPIOB_BASE                               (0x48020000u)
  /** Peripheral GPIOB base pointer */
  #define GPIOB                                    ((GPIO_Type *)GPIOB_BASE)
  /** Peripheral GPIOC base address */
  #define GPIOC_BASE                               (0x48030000u)
  /** Peripheral GPIOC base pointer */
  #define GPIOC                                    ((GPIO_Type *)GPIOC_BASE)
  /** Peripheral GPIOD base address */
  #define GPIOD_BASE                               (0x40046000u)
  /** Peripheral GPIOD base pointer */
  #define GPIOD                                    ((GPIO_Type *)GPIOD_BASE)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { GPIOA, GPIOB, GPIOC, GPIOD }
#endif

/* I3C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I3C base address */
  #define I3C_BASE                                 (0x50035000u)
  /** Peripheral I3C base address */
  #define I3C_BASE_NS                              (0x40035000u)
  /** Peripheral I3C base pointer */
  #define I3C                                      ((I3C_Type *)I3C_BASE)
  /** Peripheral I3C base pointer */
  #define I3C_NS                                   ((I3C_Type *)I3C_BASE_NS)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { I3C_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { I3C }
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS_NS                        { I3C_BASE_NS }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS_NS                         { I3C_NS }
#else
  /** Peripheral I3C base address */
  #define I3C_BASE                                 (0x40035000u)
  /** Peripheral I3C base pointer */
  #define I3C                                      ((I3C_Type *)I3C_BASE)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { I3C_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { I3C }
#endif
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { I3C0_IRQn }

/* LPCMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPCMP0 base address */
  #define LPCMP0_BASE                              (0x50048000u)
  /** Peripheral LPCMP0 base address */
  #define LPCMP0_BASE_NS                           (0x40048000u)
  /** Peripheral LPCMP0 base pointer */
  #define LPCMP0                                   ((LPCMP_Type *)LPCMP0_BASE)
  /** Peripheral LPCMP0 base pointer */
  #define LPCMP0_NS                                ((LPCMP_Type *)LPCMP0_BASE_NS)
  /** Peripheral LPCMP1 base address */
  #define LPCMP1_BASE                              (0x50049000u)
  /** Peripheral LPCMP1 base address */
  #define LPCMP1_BASE_NS                           (0x40049000u)
  /** Peripheral LPCMP1 base pointer */
  #define LPCMP1                                   ((LPCMP_Type *)LPCMP1_BASE)
  /** Peripheral LPCMP1 base pointer */
  #define LPCMP1_NS                                ((LPCMP_Type *)LPCMP1_BASE_NS)
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS                         { LPCMP0_BASE, LPCMP1_BASE }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS                          { LPCMP0, LPCMP1 }
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS_NS                      { LPCMP0_BASE_NS, LPCMP1_BASE_NS }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS_NS                       { LPCMP0_NS, LPCMP1_NS }
#else
  /** Peripheral LPCMP0 base address */
  #define LPCMP0_BASE                              (0x40048000u)
  /** Peripheral LPCMP0 base pointer */
  #define LPCMP0                                   ((LPCMP_Type *)LPCMP0_BASE)
  /** Peripheral LPCMP1 base address */
  #define LPCMP1_BASE                              (0x40049000u)
  /** Peripheral LPCMP1 base pointer */
  #define LPCMP1                                   ((LPCMP_Type *)LPCMP1_BASE)
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS                         { LPCMP0_BASE, LPCMP1_BASE }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS                          { LPCMP0, LPCMP1 }
#endif

/* LPI2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE                              (0x50033000u)
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE_NS                           (0x40033000u)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0_NS                                ((LPI2C_Type *)LPI2C0_BASE_NS)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x50034000u)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE_NS                           (0x40034000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1_NS                                ((LPI2C_Type *)LPI2C1_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { LPI2C0_BASE_NS, LPI2C1_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { LPI2C0_NS, LPI2C1_NS }
#else
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE                              (0x40033000u)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x40034000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn }

/* LPIT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPIT0 base address */
  #define LPIT0_BASE                               (0x5002F000u)
  /** Peripheral LPIT0 base address */
  #define LPIT0_BASE_NS                            (0x4002F000u)
  /** Peripheral LPIT0 base pointer */
  #define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
  /** Peripheral LPIT0 base pointer */
  #define LPIT0_NS                                 ((LPIT_Type *)LPIT0_BASE_NS)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { LPIT0_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { LPIT0 }
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS_NS                       { LPIT0_BASE_NS }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS_NS                        { LPIT0_NS }
#else
  /** Peripheral LPIT0 base address */
  #define LPIT0_BASE                               (0x4002F000u)
  /** Peripheral LPIT0 base pointer */
  #define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { LPIT0_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { LPIT0 }
#endif
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { { LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn, LPIT0_IRQn } }

/* LPSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE                              (0x50036000u)
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE_NS                           (0x40036000u)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0_NS                                ((LPSPI_Type *)LPSPI0_BASE_NS)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x50037000u)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE_NS                           (0x40037000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1_NS                                ((LPSPI_Type *)LPSPI1_BASE_NS)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1 }
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS_NS                      { LPSPI0_BASE_NS, LPSPI1_BASE_NS }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS_NS                       { LPSPI0_NS, LPSPI1_NS }
#else
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE                              (0x40036000u)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x40037000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1 }
#endif
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn }

/* LPTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPTMR0 base address */
  #define LPTMR0_BASE                              (0x5002D000u)
  /** Peripheral LPTMR0 base address */
  #define LPTMR0_BASE_NS                           (0x4002D000u)
  /** Peripheral LPTMR0 base pointer */
  #define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
  /** Peripheral LPTMR0 base pointer */
  #define LPTMR0_NS                                ((LPTMR_Type *)LPTMR0_BASE_NS)
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE                              (0x5002E000u)
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE_NS                           (0x4002E000u)
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
  #define LPTMR0_BASE                              (0x4002D000u)
  /** Peripheral LPTMR0 base pointer */
  #define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE                              (0x4002E000u)
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
  #define LPUART0_BASE                             (0x50038000u)
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE_NS                          (0x40038000u)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0_NS                               ((LPUART_Type *)LPUART0_BASE_NS)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x50039000u)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE_NS                          (0x40039000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1_NS                               ((LPUART_Type *)LPUART1_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART0, LPUART1 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { LPUART0_BASE_NS, LPUART1_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { LPUART0_NS, LPUART1_NS }
#else
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE                             (0x40038000u)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x40039000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART0, LPUART1 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_IRQn, LPUART1_IRQn }

/* LTC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LTC base address */
  #define LTC_BASE                                 (0x58A06800u)
  /** Peripheral LTC base address */
  #define LTC_BASE_NS                              (0x48A06800u)
  /** Peripheral LTC base pointer */
  #define LTC                                      ((LTC_Type *)LTC_BASE)
  /** Peripheral LTC base pointer */
  #define LTC_NS                                   ((LTC_Type *)LTC_BASE_NS)
  /** Array initializer of LTC peripheral base addresses */
  #define LTC_BASE_ADDRS                           { LTC_BASE }
  /** Array initializer of LTC peripheral base pointers */
  #define LTC_BASE_PTRS                            { LTC }
  /** Array initializer of LTC peripheral base addresses */
  #define LTC_BASE_ADDRS_NS                        { LTC_BASE_NS }
  /** Array initializer of LTC peripheral base pointers */
  #define LTC_BASE_PTRS_NS                         { LTC_NS }
#else
  /** Peripheral LTC base address */
  #define LTC_BASE                                 (0x48A06800u)
  /** Peripheral LTC base pointer */
  #define LTC                                      ((LTC_Type *)LTC_BASE)
  /** Array initializer of LTC peripheral base addresses */
  #define LTC_BASE_ADDRS                           { LTC_BASE }
  /** Array initializer of LTC peripheral base pointers */
  #define LTC_BASE_PTRS                            { LTC }
#endif

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

/* MRCC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MRCC base address */
  #define MRCC_BASE                                (0x5001C000u)
  /** Peripheral MRCC base address */
  #define MRCC_BASE_NS                             (0x4001C000u)
  /** Peripheral MRCC base pointer */
  #define MRCC                                     ((MRCC_Type *)MRCC_BASE)
  /** Peripheral MRCC base pointer */
  #define MRCC_NS                                  ((MRCC_Type *)MRCC_BASE_NS)
  /** Array initializer of MRCC peripheral base addresses */
  #define MRCC_BASE_ADDRS                          { MRCC_BASE }
  /** Array initializer of MRCC peripheral base pointers */
  #define MRCC_BASE_PTRS                           { MRCC }
  /** Array initializer of MRCC peripheral base addresses */
  #define MRCC_BASE_ADDRS_NS                       { MRCC_BASE_NS }
  /** Array initializer of MRCC peripheral base pointers */
  #define MRCC_BASE_PTRS_NS                        { MRCC_NS }
#else
  /** Peripheral MRCC base address */
  #define MRCC_BASE                                (0x4001C000u)
  /** Peripheral MRCC base pointer */
  #define MRCC                                     ((MRCC_Type *)MRCC_BASE)
  /** Array initializer of MRCC peripheral base addresses */
  #define MRCC_BASE_ADDRS                          { MRCC_BASE }
  /** Array initializer of MRCC peripheral base pointers */
  #define MRCC_BASE_PTRS                           { MRCC }
#endif

/* MSCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MSCM base address */
  #define MSCM_BASE                                (0x50014000u)
  /** Peripheral MSCM base address */
  #define MSCM_BASE_NS                             (0x40014000u)
  /** Peripheral MSCM base pointer */
  #define MSCM                                     ((MSCM_Type *)MSCM_BASE)
  /** Peripheral MSCM base pointer */
  #define MSCM_NS                                  ((MSCM_Type *)MSCM_BASE_NS)
  /** Array initializer of MSCM peripheral base addresses */
  #define MSCM_BASE_ADDRS                          { MSCM_BASE }
  /** Array initializer of MSCM peripheral base pointers */
  #define MSCM_BASE_PTRS                           { MSCM }
  /** Array initializer of MSCM peripheral base addresses */
  #define MSCM_BASE_ADDRS_NS                       { MSCM_BASE_NS }
  /** Array initializer of MSCM peripheral base pointers */
  #define MSCM_BASE_PTRS_NS                        { MSCM_NS }
#else
  /** Peripheral MSCM base address */
  #define MSCM_BASE                                (0x40014000u)
  /** Peripheral MSCM base pointer */
  #define MSCM                                     ((MSCM_Type *)MSCM_BASE)
  /** Array initializer of MSCM peripheral base addresses */
  #define MSCM_BASE_ADDRS                          { MSCM_BASE }
  /** Array initializer of MSCM peripheral base pointers */
  #define MSCM_BASE_PTRS                           { MSCM }
#endif

/* PORT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PORTA base address */
  #define PORTA_BASE                               (0x50042000u)
  /** Peripheral PORTA base address */
  #define PORTA_BASE_NS                            (0x40042000u)
  /** Peripheral PORTA base pointer */
  #define PORTA                                    ((PORT_Type *)PORTA_BASE)
  /** Peripheral PORTA base pointer */
  #define PORTA_NS                                 ((PORT_Type *)PORTA_BASE_NS)
  /** Peripheral PORTB base address */
  #define PORTB_BASE                               (0x50043000u)
  /** Peripheral PORTB base address */
  #define PORTB_BASE_NS                            (0x40043000u)
  /** Peripheral PORTB base pointer */
  #define PORTB                                    ((PORT_Type *)PORTB_BASE)
  /** Peripheral PORTB base pointer */
  #define PORTB_NS                                 ((PORT_Type *)PORTB_BASE_NS)
  /** Peripheral PORTC base address */
  #define PORTC_BASE                               (0x50044000u)
  /** Peripheral PORTC base address */
  #define PORTC_BASE_NS                            (0x40044000u)
  /** Peripheral PORTC base pointer */
  #define PORTC                                    ((PORT_Type *)PORTC_BASE)
  /** Peripheral PORTC base pointer */
  #define PORTC_NS                                 ((PORT_Type *)PORTC_BASE_NS)
  /** Peripheral PORTD base address */
  #define PORTD_BASE                               (0x50045000u)
  /** Peripheral PORTD base address */
  #define PORTD_BASE_NS                            (0x40045000u)
  /** Peripheral PORTD base pointer */
  #define PORTD                                    ((PORT_Type *)PORTD_BASE)
  /** Peripheral PORTD base pointer */
  #define PORTD_NS                                 ((PORT_Type *)PORTD_BASE_NS)
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD }
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS_NS                       { PORTA_BASE_NS, PORTB_BASE_NS, PORTC_BASE_NS, PORTD_BASE_NS }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS_NS                        { PORTA_NS, PORTB_NS, PORTC_NS, PORTD_NS }
#else
  /** Peripheral PORTA base address */
  #define PORTA_BASE                               (0x40042000u)
  /** Peripheral PORTA base pointer */
  #define PORTA                                    ((PORT_Type *)PORTA_BASE)
  /** Peripheral PORTB base address */
  #define PORTB_BASE                               (0x40043000u)
  /** Peripheral PORTB base pointer */
  #define PORTB                                    ((PORT_Type *)PORTB_BASE)
  /** Peripheral PORTC base address */
  #define PORTC_BASE                               (0x40044000u)
  /** Peripheral PORTC base pointer */
  #define PORTC                                    ((PORT_Type *)PORTC_BASE)
  /** Peripheral PORTD base address */
  #define PORTD_BASE                               (0x40045000u)
  /** Peripheral PORTD base pointer */
  #define PORTD                                    ((PORT_Type *)PORTD_BASE)
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD }
#endif
/** Interrupt vectors for the PORT peripheral type */
#define PORT_IRQS                                { PORTA_EFT_IRQn, PORTB_EFT_IRQn, PORTC_EFT_IRQn, PORTD_EFT_IRQn }

/* REGFILE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral REGFILE0 base address */
  #define REGFILE0_BASE                            (0x50021000u)
  /** Peripheral REGFILE0 base address */
  #define REGFILE0_BASE_NS                         (0x40021000u)
  /** Peripheral REGFILE0 base pointer */
  #define REGFILE0                                 ((REGFILE_Type *)REGFILE0_BASE)
  /** Peripheral REGFILE0 base pointer */
  #define REGFILE0_NS                              ((REGFILE_Type *)REGFILE0_BASE_NS)
  /** Peripheral REGFILE1 base address */
  #define REGFILE1_BASE                            (0x50022000u)
  /** Peripheral REGFILE1 base address */
  #define REGFILE1_BASE_NS                         (0x40022000u)
  /** Peripheral REGFILE1 base pointer */
  #define REGFILE1                                 ((REGFILE_Type *)REGFILE1_BASE)
  /** Peripheral REGFILE1 base pointer */
  #define REGFILE1_NS                              ((REGFILE_Type *)REGFILE1_BASE_NS)
  /** Array initializer of REGFILE peripheral base addresses */
  #define REGFILE_BASE_ADDRS                       { REGFILE0_BASE, REGFILE1_BASE }
  /** Array initializer of REGFILE peripheral base pointers */
  #define REGFILE_BASE_PTRS                        { REGFILE0, REGFILE1 }
  /** Array initializer of REGFILE peripheral base addresses */
  #define REGFILE_BASE_ADDRS_NS                    { REGFILE0_BASE_NS, REGFILE1_BASE_NS }
  /** Array initializer of REGFILE peripheral base pointers */
  #define REGFILE_BASE_PTRS_NS                     { REGFILE0_NS, REGFILE1_NS }
#else
  /** Peripheral REGFILE0 base address */
  #define REGFILE0_BASE                            (0x40021000u)
  /** Peripheral REGFILE0 base pointer */
  #define REGFILE0                                 ((REGFILE_Type *)REGFILE0_BASE)
  /** Peripheral REGFILE1 base address */
  #define REGFILE1_BASE                            (0x40022000u)
  /** Peripheral REGFILE1 base pointer */
  #define REGFILE1                                 ((REGFILE_Type *)REGFILE1_BASE)
  /** Array initializer of REGFILE peripheral base addresses */
  #define REGFILE_BASE_ADDRS                       { REGFILE0_BASE, REGFILE1_BASE }
  /** Array initializer of REGFILE peripheral base pointers */
  #define REGFILE_BASE_PTRS                        { REGFILE0, REGFILE1 }
#endif

/* RTC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RTC base address */
  #define RTC_BASE                                 (0x5002C000u)
  /** Peripheral RTC base address */
  #define RTC_BASE_NS                              (0x4002C000u)
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
  #define RTC_BASE                                 (0x4002C000u)
  /** Peripheral RTC base pointer */
  #define RTC                                      ((RTC_Type *)RTC_BASE)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { RTC_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { RTC }
#endif
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_Alarm_IRQn }
#define RTC_SECONDS_IRQS                         { RTC_Seconds_IRQn }

/* SCG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SCG0 base address */
  #define SCG0_BASE                                (0x5001E000u)
  /** Peripheral SCG0 base address */
  #define SCG0_BASE_NS                             (0x4001E000u)
  /** Peripheral SCG0 base pointer */
  #define SCG0                                     ((SCG_Type *)SCG0_BASE)
  /** Peripheral SCG0 base pointer */
  #define SCG0_NS                                  ((SCG_Type *)SCG0_BASE_NS)
  /** Array initializer of SCG peripheral base addresses */
  #define SCG_BASE_ADDRS                           { SCG0_BASE }
  /** Array initializer of SCG peripheral base pointers */
  #define SCG_BASE_PTRS                            { SCG0 }
  /** Array initializer of SCG peripheral base addresses */
  #define SCG_BASE_ADDRS_NS                        { SCG0_BASE_NS }
  /** Array initializer of SCG peripheral base pointers */
  #define SCG_BASE_PTRS_NS                         { SCG0_NS }
#else
  /** Peripheral SCG0 base address */
  #define SCG0_BASE                                (0x4001E000u)
  /** Peripheral SCG0 base pointer */
  #define SCG0                                     ((SCG_Type *)SCG0_BASE)
  /** Array initializer of SCG peripheral base addresses */
  #define SCG_BASE_ADDRS                           { SCG0_BASE }
  /** Array initializer of SCG peripheral base pointers */
  #define SCG_BASE_PTRS                            { SCG0 }
#endif

/* SEMA42 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SEMA42 base address */
  #define SEMA42_BASE                              (0x5003F000u)
  /** Peripheral SEMA42 base address */
  #define SEMA42_BASE_NS                           (0x4003F000u)
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
  #define SEMA42_BASE                              (0x4003F000u)
  /** Peripheral SEMA42 base pointer */
  #define SEMA42                                   ((SEMA42_Type *)SEMA42_BASE)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA42_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA42 }
#endif

/* SFA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SFA0 base address */
  #define SFA0_BASE                                (0x5001D000u)
  /** Peripheral SFA0 base address */
  #define SFA0_BASE_NS                             (0x4001D000u)
  /** Peripheral SFA0 base pointer */
  #define SFA0                                     ((SFA_Type *)SFA0_BASE)
  /** Peripheral SFA0 base pointer */
  #define SFA0_NS                                  ((SFA_Type *)SFA0_BASE_NS)
  /** Array initializer of SFA peripheral base addresses */
  #define SFA_BASE_ADDRS                           { SFA0_BASE }
  /** Array initializer of SFA peripheral base pointers */
  #define SFA_BASE_PTRS                            { SFA0 }
  /** Array initializer of SFA peripheral base addresses */
  #define SFA_BASE_ADDRS_NS                        { SFA0_BASE_NS }
  /** Array initializer of SFA peripheral base pointers */
  #define SFA_BASE_PTRS_NS                         { SFA0_NS }
#else
  /** Peripheral SFA0 base address */
  #define SFA0_BASE                                (0x4001D000u)
  /** Peripheral SFA0 base pointer */
  #define SFA0                                     ((SFA_Type *)SFA0_BASE)
  /** Array initializer of SFA peripheral base addresses */
  #define SFA_BASE_ADDRS                           { SFA0_BASE }
  /** Array initializer of SFA peripheral base pointers */
  #define SFA_BASE_PTRS                            { SFA0 }
#endif

/* SMSCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SMSCM base address */
  #define SMSCM_BASE                               (0x50015000u)
  /** Peripheral SMSCM base address */
  #define SMSCM_BASE_NS                            (0x40015000u)
  /** Peripheral SMSCM base pointer */
  #define SMSCM                                    ((SMSCM_Type *)SMSCM_BASE)
  /** Peripheral SMSCM base pointer */
  #define SMSCM_NS                                 ((SMSCM_Type *)SMSCM_BASE_NS)
  /** Array initializer of SMSCM peripheral base addresses */
  #define SMSCM_BASE_ADDRS                         { SMSCM_BASE }
  /** Array initializer of SMSCM peripheral base pointers */
  #define SMSCM_BASE_PTRS                          { SMSCM }
  /** Array initializer of SMSCM peripheral base addresses */
  #define SMSCM_BASE_ADDRS_NS                      { SMSCM_BASE_NS }
  /** Array initializer of SMSCM peripheral base pointers */
  #define SMSCM_BASE_PTRS_NS                       { SMSCM_NS }
#else
  /** Peripheral SMSCM base address */
  #define SMSCM_BASE                               (0x40015000u)
  /** Peripheral SMSCM base pointer */
  #define SMSCM                                    ((SMSCM_Type *)SMSCM_BASE)
  /** Array initializer of SMSCM peripheral base addresses */
  #define SMSCM_BASE_ADDRS                         { SMSCM_BASE }
  /** Array initializer of SMSCM peripheral base pointers */
  #define SMSCM_BASE_PTRS                          { SMSCM }
#endif

/* SPC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SPC0 base address */
  #define SPC0_BASE                                (0x50016000u)
  /** Peripheral SPC0 base address */
  #define SPC0_BASE_NS                             (0x40016000u)
  /** Peripheral SPC0 base pointer */
  #define SPC0                                     ((SPC_Type *)SPC0_BASE)
  /** Peripheral SPC0 base pointer */
  #define SPC0_NS                                  ((SPC_Type *)SPC0_BASE_NS)
  /** Array initializer of SPC peripheral base addresses */
  #define SPC_BASE_ADDRS                           { SPC0_BASE }
  /** Array initializer of SPC peripheral base pointers */
  #define SPC_BASE_PTRS                            { SPC0 }
  /** Array initializer of SPC peripheral base addresses */
  #define SPC_BASE_ADDRS_NS                        { SPC0_BASE_NS }
  /** Array initializer of SPC peripheral base pointers */
  #define SPC_BASE_PTRS_NS                         { SPC0_NS }
#else
  /** Peripheral SPC0 base address */
  #define SPC0_BASE                                (0x40016000u)
  /** Peripheral SPC0 base pointer */
  #define SPC0                                     ((SPC_Type *)SPC0_BASE)
  /** Array initializer of SPC peripheral base addresses */
  #define SPC_BASE_ADDRS                           { SPC0_BASE }
  /** Array initializer of SPC peripheral base pointers */
  #define SPC_BASE_PTRS                            { SPC0 }
#endif

/* SYSPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSPM base address */
  #define SYSPM_BASE                               (0x50017000u)
  /** Peripheral SYSPM base address */
  #define SYSPM_BASE_NS                            (0x40017000u)
  /** Peripheral SYSPM base pointer */
  #define SYSPM                                    ((SYSPM_Type *)SYSPM_BASE)
  /** Peripheral SYSPM base pointer */
  #define SYSPM_NS                                 ((SYSPM_Type *)SYSPM_BASE_NS)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { SYSPM_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { SYSPM }
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS_NS                      { SYSPM_BASE_NS }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS_NS                       { SYSPM_NS }
#else
  /** Peripheral SYSPM base address */
  #define SYSPM_BASE                               (0x40017000u)
  /** Peripheral SYSPM base pointer */
  #define SYSPM                                    ((SYSPM_Type *)SYSPM_BASE)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { SYSPM_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { SYSPM }
#endif

/* TPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TPM0 base address */
  #define TPM0_BASE                                (0x50031000u)
  /** Peripheral TPM0 base address */
  #define TPM0_BASE_NS                             (0x40031000u)
  /** Peripheral TPM0 base pointer */
  #define TPM0                                     ((TPM_Type *)TPM0_BASE)
  /** Peripheral TPM0 base pointer */
  #define TPM0_NS                                  ((TPM_Type *)TPM0_BASE_NS)
  /** Peripheral TPM1 base address */
  #define TPM1_BASE                                (0x50032000u)
  /** Peripheral TPM1 base address */
  #define TPM1_BASE_NS                             (0x40032000u)
  /** Peripheral TPM1 base pointer */
  #define TPM1                                     ((TPM_Type *)TPM1_BASE)
  /** Peripheral TPM1 base pointer */
  #define TPM1_NS                                  ((TPM_Type *)TPM1_BASE_NS)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE                                (0x58984000u)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE_NS                             (0x48984000u)
  /** Peripheral TPM2 base pointer */
  #define TPM2                                     ((TPM_Type *)TPM2_BASE)
  /** Peripheral TPM2 base pointer */
  #define TPM2_NS                                  ((TPM_Type *)TPM2_BASE_NS)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { TPM0_BASE, TPM1_BASE, TPM2_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { TPM0, TPM1, TPM2 }
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS_NS                        { TPM0_BASE_NS, TPM1_BASE_NS, TPM2_BASE_NS }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS_NS                         { TPM0_NS, TPM1_NS, TPM2_NS }
#else
  /** Peripheral TPM0 base address */
  #define TPM0_BASE                                (0x40031000u)
  /** Peripheral TPM0 base pointer */
  #define TPM0                                     ((TPM_Type *)TPM0_BASE)
  /** Peripheral TPM1 base address */
  #define TPM1_BASE                                (0x40032000u)
  /** Peripheral TPM1 base pointer */
  #define TPM1                                     ((TPM_Type *)TPM1_BASE)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE                                (0x48984000u)
  /** Peripheral TPM2 base pointer */
  #define TPM2                                     ((TPM_Type *)TPM2_BASE)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { TPM0_BASE, TPM1_BASE, TPM2_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { TPM0, TPM1, TPM2 }
#endif
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { TPM0_IRQn, TPM1_IRQn, NotAvail_IRQn }

/* TRDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRDC base address */
  #define TRDC_BASE                                (0x50026000u)
  /** Peripheral TRDC base address */
  #define TRDC_BASE_NS                             (0x40026000u)
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
  #define TRDC_BASE                                (0x40026000u)
  /** Peripheral TRDC base pointer */
  #define TRDC                                     ((TRDC_Type *)TRDC_BASE)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { TRDC_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { TRDC }
#endif
/** Interrupt vectors for the TRDC peripheral type */
#define TRDC_IRQS                                { TRDC0_IRQn }
#define MBC0_MEMORY_CFG_WORD_COUNT {4, 1, 1, 2}
#define MBC1_MEMORY_CFG_WORD_COUNT {1, 1, 1, 1}
#define MBC2_MEMORY_CFG_WORD_COUNT {10, 1, 2, 0}
#define MBC3_MEMORY_CFG_WORD_COUNT {0, 0, 0, 0}
#define MBC_MEMORY_CFG_WORD_COUNT {MBC0_MEMORY_CFG_WORD_COUNT , MBC1_MEMORY_CFG_WORD_COUNT, MBC2_MEMORY_CFG_WORD_COUNT, MBC3_MEMORY_CFG_WORD_COUNT}
#define MBC0_MEMORY_NSE_WORD_COUNT {1, 1, 1, 1}
#define MBC1_MEMORY_NSE_WORD_COUNT {1, 1, 1, 1}
#define MBC2_MEMORY_NSE_WORD_COUNT {3, 1, 1, 0}
#define MBC3_MEMORY_NSE_WORD_COUNT {0, 0, 0, 0}
#define MBC_MEMORY_NSE_WORD_COUNT {MBC0_MEMORY_NSE_WORD_COUNT , MBC1_MEMORY_NSE_WORD_COUNT, MBC2_MEMORY_NSE_WORD_COUNT, MBC3_MEMORY_NSE_WORD_COUNT}


/* TRGMUX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRGMUX0 base address */
  #define TRGMUX0_BASE                             (0x50018000u)
  /** Peripheral TRGMUX0 base address */
  #define TRGMUX0_BASE_NS                          (0x40018000u)
  /** Peripheral TRGMUX0 base pointer */
  #define TRGMUX0                                  ((TRGMUX_Type *)TRGMUX0_BASE)
  /** Peripheral TRGMUX0 base pointer */
  #define TRGMUX0_NS                               ((TRGMUX_Type *)TRGMUX0_BASE_NS)
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS                        { TRGMUX0_BASE }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS                         { TRGMUX0 }
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS_NS                     { TRGMUX0_BASE_NS }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS_NS                      { TRGMUX0_NS }
#else
  /** Peripheral TRGMUX0 base address */
  #define TRGMUX0_BASE                             (0x40018000u)
  /** Peripheral TRGMUX0 base pointer */
  #define TRGMUX0                                  ((TRGMUX_Type *)TRGMUX0_BASE)
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS                        { TRGMUX0_BASE }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS                         { TRGMUX0 }
#endif

/* TSTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TSTMR0 base address */
  #define TSTMR0_BASE                              (0x50030000u)
  /** Peripheral TSTMR0 base address */
  #define TSTMR0_BASE_NS                           (0x40030000u)
  /** Peripheral TSTMR0 base pointer */
  #define TSTMR0                                   ((TSTMR_Type *)TSTMR0_BASE)
  /** Peripheral TSTMR0 base pointer */
  #define TSTMR0_NS                                ((TSTMR_Type *)TSTMR0_BASE_NS)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { TSTMR0_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { TSTMR0 }
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS_NS                      { TSTMR0_BASE_NS }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS_NS                       { TSTMR0_NS }
#else
  /** Peripheral TSTMR0 base address */
  #define TSTMR0_BASE                              (0x40030000u)
  /** Peripheral TSTMR0 base pointer */
  #define TSTMR0                                   ((TSTMR_Type *)TSTMR0_BASE)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { TSTMR0_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { TSTMR0 }
#endif

/* VBAT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VBAT0 base address */
  #define VBAT0_BASE                               (0x5002B000u)
  /** Peripheral VBAT0 base address */
  #define VBAT0_BASE_NS                            (0x4002B000u)
  /** Peripheral VBAT0 base pointer */
  #define VBAT0                                    ((VBAT_Type *)VBAT0_BASE)
  /** Peripheral VBAT0 base pointer */
  #define VBAT0_NS                                 ((VBAT_Type *)VBAT0_BASE_NS)
  /** Array initializer of VBAT peripheral base addresses */
  #define VBAT_BASE_ADDRS                          { VBAT0_BASE }
  /** Array initializer of VBAT peripheral base pointers */
  #define VBAT_BASE_PTRS                           { VBAT0 }
  /** Array initializer of VBAT peripheral base addresses */
  #define VBAT_BASE_ADDRS_NS                       { VBAT0_BASE_NS }
  /** Array initializer of VBAT peripheral base pointers */
  #define VBAT_BASE_PTRS_NS                        { VBAT0_NS }
#else
  /** Peripheral VBAT0 base address */
  #define VBAT0_BASE                               (0x4002B000u)
  /** Peripheral VBAT0 base pointer */
  #define VBAT0                                    ((VBAT_Type *)VBAT0_BASE)
  /** Array initializer of VBAT peripheral base addresses */
  #define VBAT_BASE_ADDRS                          { VBAT0_BASE }
  /** Array initializer of VBAT peripheral base pointers */
  #define VBAT_BASE_PTRS                           { VBAT0 }
#endif

/* VREF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VREF0 base address */
  #define VREF0_BASE                               (0x5004A000u)
  /** Peripheral VREF0 base address */
  #define VREF0_BASE_NS                            (0x4004A000u)
  /** Peripheral VREF0 base pointer */
  #define VREF0                                    ((VREF_Type *)VREF0_BASE)
  /** Peripheral VREF0 base pointer */
  #define VREF0_NS                                 ((VREF_Type *)VREF0_BASE_NS)
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS                          { VREF0_BASE }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS                           { VREF0 }
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS_NS                       { VREF0_BASE_NS }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS_NS                        { VREF0_NS }
#else
  /** Peripheral VREF0 base address */
  #define VREF0_BASE                               (0x4004A000u)
  /** Peripheral VREF0 base pointer */
  #define VREF0                                    ((VREF_Type *)VREF0_BASE)
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS                          { VREF0_BASE }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS                           { VREF0 }
#endif

/* WDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WDOG0 base address */
  #define WDOG0_BASE                               (0x5001A000u)
  /** Peripheral WDOG0 base address */
  #define WDOG0_BASE_NS                            (0x4001A000u)
  /** Peripheral WDOG0 base pointer */
  #define WDOG0                                    ((WDOG_Type *)WDOG0_BASE)
  /** Peripheral WDOG0 base pointer */
  #define WDOG0_NS                                 ((WDOG_Type *)WDOG0_BASE_NS)
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE                               (0x5001B000u)
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE_NS                            (0x4001B000u)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1_NS                                 ((WDOG_Type *)WDOG1_BASE_NS)
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS                          { WDOG0_BASE, WDOG1_BASE }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS                           { WDOG0, WDOG1 }
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS_NS                       { WDOG0_BASE_NS, WDOG1_BASE_NS }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS_NS                        { WDOG0_NS, WDOG1_NS }
#else
  /** Peripheral WDOG0 base address */
  #define WDOG0_BASE                               (0x4001A000u)
  /** Peripheral WDOG0 base pointer */
  #define WDOG0                                    ((WDOG_Type *)WDOG0_BASE)
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE                               (0x4001B000u)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS                          { WDOG0_BASE, WDOG1_BASE }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS                           { WDOG0, WDOG1 }
#endif

/* WUU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WUU0 base address */
  #define WUU0_BASE                                (0x50019000u)
  /** Peripheral WUU0 base address */
  #define WUU0_BASE_NS                             (0x40019000u)
  /** Peripheral WUU0 base pointer */
  #define WUU0                                     ((WUU_Type *)WUU0_BASE)
  /** Peripheral WUU0 base pointer */
  #define WUU0_NS                                  ((WUU_Type *)WUU0_BASE_NS)
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS                           { WUU0_BASE }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS                            { WUU0 }
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS_NS                        { WUU0_BASE_NS }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS_NS                         { WUU0_NS }
#else
  /** Peripheral WUU0 base address */
  #define WUU0_BASE                                (0x40019000u)
  /** Peripheral WUU0 base pointer */
  #define WUU0                                     ((WUU_Type *)WUU0_BASE)
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS                           { WUU0_BASE }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS                            { WUU0 }
#endif
/** Interrupt vectors for the WUU peripheral type */
#define WUU_IRQS                                 { WUU0_IRQn }

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
#define NXP_VAL2FLD(field, value)    (((value) << (field##_SHIFT)) & (field##_MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field##_MASK)) >> (field##_SHIFT))

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

#define RADIO_IS_GEN_4P5 (1)
#define NXP_RADIO_GEN (450)

/*! @brief define LTC0 from LTC. */
#define LTC0 LTC


/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* KW45Z41052_COMMON_H_ */

