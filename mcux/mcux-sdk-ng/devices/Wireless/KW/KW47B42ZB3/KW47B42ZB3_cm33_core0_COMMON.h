/*
** ###################################################################
**     Processor:           KW47B42ZB3AFTA_cm33_core0
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    Rev. 1, 2024-10-13
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250522
**
**     Abstract:
**         CMSIS Peripheral Access Layer for KW47B42ZB3_cm33_core0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file KW47B42ZB3_cm33_core0_COMMON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for KW47B42ZB3_cm33_core0
 *
 * CMSIS Peripheral Access Layer for KW47B42ZB3_cm33_core0
 */

#if !defined(KW47B42ZB3_CM33_CORE0_COMMON_H_)
#define KW47B42ZB3_CM33_CORE0_COMMON_H_          /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 94                 /**< Number of interrupts in the Vector table */

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
  DMA0_CH0_IRQn                = 2,                /**< DMA0 channel 0 error or transfer complete */
  DMA0_CH1_IRQn                = 3,                /**< DMA0 channel 1 error or transfer complete */
  DMA0_CH2_IRQn                = 4,                /**< DMA0 channel 2 error or transfer complete */
  DMA0_CH3_IRQn                = 5,                /**< DMA0 channel 3 error or transfer complete */
  DMA0_CH4_IRQn                = 6,                /**< DMA0 channel 4 error or transfer complete */
  DMA0_CH5_IRQn                = 7,                /**< DMA0 channel 5 error or transfer complete */
  DMA0_CH6_IRQn                = 8,                /**< DMA0 channel 6 error or transfer complete */
  DMA0_CH7_IRQn                = 9,                /**< DMA0 channel 7 error or transfer complete */
  DMA0_CH8_IRQn                = 10,               /**< DMA0 channel 8 error or transfer complete */
  DMA0_CH9_IRQn                = 11,               /**< DMA0 channel 9 error or transfer complete */
  DMA0_CH10_IRQn               = 12,               /**< DMA0 channel 10 error or transfer complete */
  DMA0_CH11_IRQn               = 13,               /**< DMA0 channel 11 error or transfer complete */
  DMA0_CH12_IRQn               = 14,               /**< DMA0 channel 12 error or transfer complete */
  DMA0_CH13_IRQn               = 15,               /**< DMA0 channel 13 error or transfer complete */
  DMA0_CH14_IRQn               = 16,               /**< DMA0 channel 14 error or transfer complete */
  DMA0_CH15_IRQn               = 17,               /**< DMA0 channel 15 error or transfer complete */
  EWM0_IRQn                    = 18,               /**< External Watchdog Monitor interrupt */
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
  CAN0_IRQn                    = 47,               /**< Controller Area Network 0 interrupt */
  RF_IMU0_IRQn                 = 48,               /**< Radio IMU interrupt 0 (msg_rdy_imu) */
  RF_IMU1_IRQn                 = 49,               /**< Radio IMU interrupt 1(msg_space_avail_imu) */
  RF_NBU_IRQn                  = 50,               /**< Radio NBU timeout interrupt */
  RF_FMU_IRQn                  = 51,               /**< Radio FMU interrupt */
  RF_WOR_IRQn                  = 52,               /**< Radio WOR RX FAIL interrupt */
  Reserved69_IRQn              = 53,               /**< Reserved interrupt */
  RF_Generic_IRQn              = 54,               /**< Radio Frequency 2.4 GHz - Generic Link Layer interrupt */
  RF_BRIC_IRQn                 = 55,               /**< Radio Frequency 2.4 GHz - BRIC interrupt */
  RF_LANT_SW_IRQn              = 56,               /**< Radio Transceiver - Radio LANT_SW interrupt */
  RFMC_IRQn                    = 57,               /**< RFMC interrupt */
  DSB_IRQn                     = 58,               /**< Data Stream Buffer interrupt */
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
  ADC0_IRQn                    = 71,               /**< Analog-to-Digital Converter - General Purpose0 interrupt */
  LPCMP0_IRQn                  = 72,               /**< Comparator - General Purpose0 interrupt */
  LPCMP1_IRQn                  = 73,               /**< Comparator - General Purpose1 interrupt */
  VBAT_IRQn                    = 74,               /**< Smart Power Switch Domain interrupt */
  Reserved91_IRQn              = 75,               /**< Reserved interrupt */
  CAN1_IRQn                    = 76,               /**< Controller Area Network 1 interrupt */
  DSP_IRQn                     = 77                /**< LCE interrupt */
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
#include "system_KW47B42ZB3_cm33_core0.h" /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef KW47B42ZB3_cm33_core0_SERIES
#define KW47B42ZB3_cm33_core0_SERIES
#endif
/* CPU specific feature definitions */
#include "KW47B42ZB3_cm33_core0_features.h"

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

/* CAN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CAN0 base address */
  #define CAN0_BASE                                (0x5003B000u)
  /** Peripheral CAN0 base address */
  #define CAN0_BASE_NS                             (0x4003B000u)
  /** Peripheral CAN0 base pointer */
  #define CAN0                                     ((CAN_Type *)CAN0_BASE)
  /** Peripheral CAN0 base pointer */
  #define CAN0_NS                                  ((CAN_Type *)CAN0_BASE_NS)
  /** Peripheral CAN1 base address */
  #define CAN1_BASE                                (0x5004F000u)
  /** Peripheral CAN1 base address */
  #define CAN1_BASE_NS                             (0x4004F000u)
  /** Peripheral CAN1 base pointer */
  #define CAN1                                     ((CAN_Type *)CAN1_BASE)
  /** Peripheral CAN1 base pointer */
  #define CAN1_NS                                  ((CAN_Type *)CAN1_BASE_NS)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { CAN0_BASE, CAN1_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { CAN0, CAN1 }
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS_NS                        { CAN0_BASE_NS, CAN1_BASE_NS }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS_NS                         { CAN0_NS, CAN1_NS }
#else
  /** Peripheral CAN0 base address */
  #define CAN0_BASE                                (0x4003B000u)
  /** Peripheral CAN0 base pointer */
  #define CAN0                                     ((CAN_Type *)CAN0_BASE)
  /** Peripheral CAN1 base address */
  #define CAN1_BASE                                (0x4004F000u)
  /** Peripheral CAN1 base pointer */
  #define CAN1                                     ((CAN_Type *)CAN1_BASE)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { CAN0_BASE, CAN1_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { CAN0, CAN1 }
#endif
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { CAN0_IRQn, CAN1_IRQn }
#define CAN_Tx_Warning_IRQS                      { CAN0_IRQn, CAN1_IRQn }
#define CAN_Wake_Up_IRQS                         { CAN0_IRQn, CAN1_IRQn }
#define CAN_Error_IRQS                           { CAN0_IRQn, CAN1_IRQn }
#define CAN_Bus_Off_IRQS                         { CAN0_IRQn, CAN1_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { CAN0_IRQn, CAN1_IRQn }

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

/* CIU2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CIU2 base address */
  #define CIU2_BASE                                (0x58948000u)
  /** Peripheral CIU2 base address */
  #define CIU2_BASE_NS                             (0x48948000u)
  /** Peripheral CIU2 base pointer */
  #define CIU2                                     ((CIU2_Type *)CIU2_BASE)
  /** Peripheral CIU2 base pointer */
  #define CIU2_NS                                  ((CIU2_Type *)CIU2_BASE_NS)
  /** Array initializer of CIU2 peripheral base addresses */
  #define CIU2_BASE_ADDRS                          { CIU2_BASE }
  /** Array initializer of CIU2 peripheral base pointers */
  #define CIU2_BASE_PTRS                           { CIU2 }
  /** Array initializer of CIU2 peripheral base addresses */
  #define CIU2_BASE_ADDRS_NS                       { CIU2_BASE_NS }
  /** Array initializer of CIU2 peripheral base pointers */
  #define CIU2_BASE_PTRS_NS                        { CIU2_NS }
#else
  /** Peripheral CIU2 base address */
  #define CIU2_BASE                                (0x48948000u)
  /** Peripheral CIU2 base pointer */
  #define CIU2                                     ((CIU2_Type *)CIU2_BASE)
  /** Array initializer of CIU2 peripheral base addresses */
  #define CIU2_BASE_ADDRS                          { CIU2_BASE }
  /** Array initializer of CIU2 peripheral base pointers */
  #define CIU2_BASE_PTRS                           { CIU2 }
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

/* DBGMB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DBGMB base address */
  #define DBGMB_BASE                               (0x58000000u)
  /** Peripheral DBGMB base address */
  #define DBGMB_BASE_NS                            (0x48000000u)
  /** Peripheral DBGMB base pointer */
  #define DBGMB                                    ((DBGMB_Type *)DBGMB_BASE)
  /** Peripheral DBGMB base pointer */
  #define DBGMB_NS                                 ((DBGMB_Type *)DBGMB_BASE_NS)
  /** Array initializer of DBGMB peripheral base addresses */
  #define DBGMB_BASE_ADDRS                         { DBGMB_BASE }
  /** Array initializer of DBGMB peripheral base pointers */
  #define DBGMB_BASE_PTRS                          { DBGMB }
  /** Array initializer of DBGMB peripheral base addresses */
  #define DBGMB_BASE_ADDRS_NS                      { DBGMB_BASE_NS }
  /** Array initializer of DBGMB peripheral base pointers */
  #define DBGMB_BASE_PTRS_NS                       { DBGMB_NS }
#else
  /** Peripheral DBGMB base address */
  #define DBGMB_BASE                               (0x48000000u)
  /** Peripheral DBGMB base pointer */
  #define DBGMB                                    ((DBGMB_Type *)DBGMB_BASE)
  /** Array initializer of DBGMB peripheral base addresses */
  #define DBGMB_BASE_ADDRS                         { DBGMB_BASE }
  /** Array initializer of DBGMB peripheral base pointers */
  #define DBGMB_BASE_PTRS                          { DBGMB }
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

/* DSB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DSB0 base address */
  #define DSB0_BASE                                (0x50041000u)
  /** Peripheral DSB0 base address */
  #define DSB0_BASE_NS                             (0x40041000u)
  /** Peripheral DSB0 base pointer */
  #define DSB0                                     ((DSB_Type *)DSB0_BASE)
  /** Peripheral DSB0 base pointer */
  #define DSB0_NS                                  ((DSB_Type *)DSB0_BASE_NS)
  /** Array initializer of DSB peripheral base addresses */
  #define DSB_BASE_ADDRS                           { DSB0_BASE }
  /** Array initializer of DSB peripheral base pointers */
  #define DSB_BASE_PTRS                            { DSB0 }
  /** Array initializer of DSB peripheral base addresses */
  #define DSB_BASE_ADDRS_NS                        { DSB0_BASE_NS }
  /** Array initializer of DSB peripheral base pointers */
  #define DSB_BASE_PTRS_NS                         { DSB0_NS }
#else
  /** Peripheral DSB0 base address */
  #define DSB0_BASE                                (0x40041000u)
  /** Peripheral DSB0 base pointer */
  #define DSB0                                     ((DSB_Type *)DSB0_BASE)
  /** Array initializer of DSB peripheral base addresses */
  #define DSB_BASE_ADDRS                           { DSB0_BASE }
  /** Array initializer of DSB peripheral base pointers */
  #define DSB_BASE_PTRS                            { DSB0 }
#endif

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
  /** Peripheral RF_FMU base address */
  #define RF_FMU_BASE                              (0x58981000u)
  /** Peripheral RF_FMU base address */
  #define RF_FMU_BASE_NS                           (0x48981000u)
  /** Peripheral RF_FMU base pointer */
  #define RF_FMU                                   ((FMU_Type *)RF_FMU_BASE)
  /** Peripheral RF_FMU base pointer */
  #define RF_FMU_NS                                ((FMU_Type *)RF_FMU_BASE_NS)
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS                           { FMU0_BASE, RF_FMU_BASE }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS                            { FMU0, RF_FMU }
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS_NS                        { FMU0_BASE_NS, RF_FMU_BASE_NS }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS_NS                         { FMU0_NS, RF_FMU_NS }
#else
  /** Peripheral FMU0 base address */
  #define FMU0_BASE                                (0x40020000u)
  /** Peripheral FMU0 base pointer */
  #define FMU0                                     ((FMU_Type *)FMU0_BASE)
  /** Peripheral RF_FMU base address */
  #define RF_FMU_BASE                              (0x48981000u)
  /** Peripheral RF_FMU base pointer */
  #define RF_FMU                                   ((FMU_Type *)RF_FMU_BASE)
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS                           { FMU0_BASE, RF_FMU_BASE }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS                            { FMU0, RF_FMU }
#endif

/* FRO192M - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FRO192M0 base address */
  #define FRO192M0_BASE                            (0x58980000u)
  /** Peripheral FRO192M0 base address */
  #define FRO192M0_BASE_NS                         (0x48980000u)
  /** Peripheral FRO192M0 base pointer */
  #define FRO192M0                                 ((FRO192M_Type *)FRO192M0_BASE)
  /** Peripheral FRO192M0 base pointer */
  #define FRO192M0_NS                              ((FRO192M_Type *)FRO192M0_BASE_NS)
  /** Array initializer of FRO192M peripheral base addresses */
  #define FRO192M_BASE_ADDRS                       { FRO192M0_BASE }
  /** Array initializer of FRO192M peripheral base pointers */
  #define FRO192M_BASE_PTRS                        { FRO192M0 }
  /** Array initializer of FRO192M peripheral base addresses */
  #define FRO192M_BASE_ADDRS_NS                    { FRO192M0_BASE_NS }
  /** Array initializer of FRO192M peripheral base pointers */
  #define FRO192M_BASE_PTRS_NS                     { FRO192M0_NS }
#else
  /** Peripheral FRO192M0 base address */
  #define FRO192M0_BASE                            (0x48980000u)
  /** Peripheral FRO192M0 base pointer */
  #define FRO192M0                                 ((FRO192M_Type *)FRO192M0_BASE)
  /** Array initializer of FRO192M peripheral base addresses */
  #define FRO192M_BASE_ADDRS                       { FRO192M0_BASE }
  /** Array initializer of FRO192M peripheral base pointers */
  #define FRO192M_BASE_PTRS                        { FRO192M0 }
#endif

/* GEN4PHY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_2P4GHZ_PHY base address */
  #define XCVR_2P4GHZ_PHY_BASE                     (0x58A07600u)
  /** Peripheral XCVR_2P4GHZ_PHY base address */
  #define XCVR_2P4GHZ_PHY_BASE_NS                  (0x48A07600u)
  /** Peripheral XCVR_2P4GHZ_PHY base pointer */
  #define XCVR_2P4GHZ_PHY                          ((GEN4PHY_Type *)XCVR_2P4GHZ_PHY_BASE)
  /** Peripheral XCVR_2P4GHZ_PHY base pointer */
  #define XCVR_2P4GHZ_PHY_NS                       ((GEN4PHY_Type *)XCVR_2P4GHZ_PHY_BASE_NS)
  /** Array initializer of GEN4PHY peripheral base addresses */
  #define GEN4PHY_BASE_ADDRS                       { XCVR_2P4GHZ_PHY_BASE }
  /** Array initializer of GEN4PHY peripheral base pointers */
  #define GEN4PHY_BASE_PTRS                        { XCVR_2P4GHZ_PHY }
  /** Array initializer of GEN4PHY peripheral base addresses */
  #define GEN4PHY_BASE_ADDRS_NS                    { XCVR_2P4GHZ_PHY_BASE_NS }
  /** Array initializer of GEN4PHY peripheral base pointers */
  #define GEN4PHY_BASE_PTRS_NS                     { XCVR_2P4GHZ_PHY_NS }
#else
  /** Peripheral XCVR_2P4GHZ_PHY base address */
  #define XCVR_2P4GHZ_PHY_BASE                     (0x48A07600u)
  /** Peripheral XCVR_2P4GHZ_PHY base pointer */
  #define XCVR_2P4GHZ_PHY                          ((GEN4PHY_Type *)XCVR_2P4GHZ_PHY_BASE)
  /** Array initializer of GEN4PHY peripheral base addresses */
  #define GEN4PHY_BASE_ADDRS                       { XCVR_2P4GHZ_PHY_BASE }
  /** Array initializer of GEN4PHY peripheral base pointers */
  #define GEN4PHY_BASE_PTRS                        { XCVR_2P4GHZ_PHY }
#endif

/* GENFSK - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GENFSK base address */
  #define GENFSK_BASE                              (0x58A02000u)
  /** Peripheral GENFSK base address */
  #define GENFSK_BASE_NS                           (0x48A02000u)
  /** Peripheral GENFSK base pointer */
  #define GENFSK                                   ((GENFSK_Type *)GENFSK_BASE)
  /** Peripheral GENFSK base pointer */
  #define GENFSK_NS                                ((GENFSK_Type *)GENFSK_BASE_NS)
  /** Array initializer of GENFSK peripheral base addresses */
  #define GENFSK_BASE_ADDRS                        { GENFSK_BASE }
  /** Array initializer of GENFSK peripheral base pointers */
  #define GENFSK_BASE_PTRS                         { GENFSK }
  /** Array initializer of GENFSK peripheral base addresses */
  #define GENFSK_BASE_ADDRS_NS                     { GENFSK_BASE_NS }
  /** Array initializer of GENFSK peripheral base pointers */
  #define GENFSK_BASE_PTRS_NS                      { GENFSK_NS }
#else
  /** Peripheral GENFSK base address */
  #define GENFSK_BASE                              (0x48A02000u)
  /** Peripheral GENFSK base pointer */
  #define GENFSK                                   ((GENFSK_Type *)GENFSK_BASE)
  /** Array initializer of GENFSK peripheral base addresses */
  #define GENFSK_BASE_ADDRS                        { GENFSK_BASE }
  /** Array initializer of GENFSK peripheral base pointers */
  #define GENFSK_BASE_PTRS                         { GENFSK }
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
  /** Peripheral I3C0 base address */
  #define I3C0_BASE                                (0x50035000u)
  /** Peripheral I3C0 base address */
  #define I3C0_BASE_NS                             (0x40035000u)
  /** Peripheral I3C0 base pointer */
  #define I3C0                                     ((I3C_Type *)I3C0_BASE)
  /** Peripheral I3C0 base pointer */
  #define I3C0_NS                                  ((I3C_Type *)I3C0_BASE_NS)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { I3C0_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { I3C0 }
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS_NS                        { I3C0_BASE_NS }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS_NS                         { I3C0_NS }
#else
  /** Peripheral I3C0 base address */
  #define I3C0_BASE                                (0x40035000u)
  /** Peripheral I3C0 base pointer */
  #define I3C0                                     ((I3C_Type *)I3C0_BASE)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { I3C0_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { I3C0 }
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
  /** Peripheral LPTMR2 base address */
  #define LPTMR2_BASE                              (0x58986000u)
  /** Peripheral LPTMR2 base address */
  #define LPTMR2_BASE_NS                           (0x48986000u)
  /** Peripheral LPTMR2 base pointer */
  #define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
  /** Peripheral LPTMR2 base pointer */
  #define LPTMR2_NS                                ((LPTMR_Type *)LPTMR2_BASE_NS)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { LPTMR0_BASE, LPTMR1_BASE, LPTMR2_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { LPTMR0, LPTMR1, LPTMR2 }
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS_NS                      { LPTMR0_BASE_NS, LPTMR1_BASE_NS, LPTMR2_BASE_NS }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS_NS                       { LPTMR0_NS, LPTMR1_NS, LPTMR2_NS }
#else
  /** Peripheral LPTMR0 base address */
  #define LPTMR0_BASE                              (0x4002D000u)
  /** Peripheral LPTMR0 base pointer */
  #define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE                              (0x4002E000u)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
  /** Peripheral LPTMR2 base address */
  #define LPTMR2_BASE                              (0x48986000u)
  /** Peripheral LPTMR2 base pointer */
  #define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { LPTMR0_BASE, LPTMR1_BASE, LPTMR2_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { LPTMR0, LPTMR1, LPTMR2 }
#endif
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn, LPTMR1_IRQn, NotAvail_IRQn }

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

/* MSF1_B_test - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FMU0_TEST base address */
  #define FMU0_TEST_BASE                           (0x5004C000u)
  /** Peripheral FMU0_TEST base address */
  #define FMU0_TEST_BASE_NS                        (0x4004C000u)
  /** Peripheral FMU0_TEST base pointer */
  #define FMU0_TEST                                ((MSF1_B_test_Type *)FMU0_TEST_BASE)
  /** Peripheral FMU0_TEST base pointer */
  #define FMU0_TEST_NS                             ((MSF1_B_test_Type *)FMU0_TEST_BASE_NS)
  /** Peripheral RF_FMU_TEST base address */
  #define RF_FMU_TEST_BASE                         (0x58985000u)
  /** Peripheral RF_FMU_TEST base address */
  #define RF_FMU_TEST_BASE_NS                      (0x48985000u)
  /** Peripheral RF_FMU_TEST base pointer */
  #define RF_FMU_TEST                              ((MSF1_B_test_Type *)RF_FMU_TEST_BASE)
  /** Peripheral RF_FMU_TEST base pointer */
  #define RF_FMU_TEST_NS                           ((MSF1_B_test_Type *)RF_FMU_TEST_BASE_NS)
  /** Array initializer of MSF1_B_test peripheral base addresses */
  #define MSF1_B_test_BASE_ADDRS                   { FMU0_TEST_BASE, RF_FMU_TEST_BASE }
  /** Array initializer of MSF1_B_test peripheral base pointers */
  #define MSF1_B_test_BASE_PTRS                    { FMU0_TEST, RF_FMU_TEST }
  /** Array initializer of MSF1_B_test peripheral base addresses */
  #define MSF1_B_test_BASE_ADDRS_NS                { FMU0_TEST_BASE_NS, RF_FMU_TEST_BASE_NS }
  /** Array initializer of MSF1_B_test peripheral base pointers */
  #define MSF1_B_test_BASE_PTRS_NS                 { FMU0_TEST_NS, RF_FMU_TEST_NS }
#else
  /** Peripheral FMU0_TEST base address */
  #define FMU0_TEST_BASE                           (0x4004C000u)
  /** Peripheral FMU0_TEST base pointer */
  #define FMU0_TEST                                ((MSF1_B_test_Type *)FMU0_TEST_BASE)
  /** Peripheral RF_FMU_TEST base address */
  #define RF_FMU_TEST_BASE                         (0x48985000u)
  /** Peripheral RF_FMU_TEST base pointer */
  #define RF_FMU_TEST                              ((MSF1_B_test_Type *)RF_FMU_TEST_BASE)
  /** Array initializer of MSF1_B_test peripheral base addresses */
  #define MSF1_B_test_BASE_ADDRS                   { FMU0_TEST_BASE, RF_FMU_TEST_BASE }
  /** Array initializer of MSF1_B_test peripheral base pointers */
  #define MSF1_B_test_BASE_PTRS                    { FMU0_TEST, RF_FMU_TEST }
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

/* RADIO_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RADIO_CTRL base address */
  #define RADIO_CTRL_BASE                          (0x58A06000u)
  /** Peripheral RADIO_CTRL base address */
  #define RADIO_CTRL_BASE_NS                       (0x48A06000u)
  /** Peripheral RADIO_CTRL base pointer */
  #define RADIO_CTRL                               ((RADIO_CTRL_Type *)RADIO_CTRL_BASE)
  /** Peripheral RADIO_CTRL base pointer */
  #define RADIO_CTRL_NS                            ((RADIO_CTRL_Type *)RADIO_CTRL_BASE_NS)
  /** Array initializer of RADIO_CTRL peripheral base addresses */
  #define RADIO_CTRL_BASE_ADDRS                    { RADIO_CTRL_BASE }
  /** Array initializer of RADIO_CTRL peripheral base pointers */
  #define RADIO_CTRL_BASE_PTRS                     { RADIO_CTRL }
  /** Array initializer of RADIO_CTRL peripheral base addresses */
  #define RADIO_CTRL_BASE_ADDRS_NS                 { RADIO_CTRL_BASE_NS }
  /** Array initializer of RADIO_CTRL peripheral base pointers */
  #define RADIO_CTRL_BASE_PTRS_NS                  { RADIO_CTRL_NS }
#else
  /** Peripheral RADIO_CTRL base address */
  #define RADIO_CTRL_BASE                          (0x48A06000u)
  /** Peripheral RADIO_CTRL base pointer */
  #define RADIO_CTRL                               ((RADIO_CTRL_Type *)RADIO_CTRL_BASE)
  /** Array initializer of RADIO_CTRL peripheral base addresses */
  #define RADIO_CTRL_BASE_ADDRS                    { RADIO_CTRL_BASE }
  /** Array initializer of RADIO_CTRL peripheral base pointers */
  #define RADIO_CTRL_BASE_PTRS                     { RADIO_CTRL }
#endif

/* RBME - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RBME base address */
  #define RBME_BASE                                (0x58A06200u)
  /** Peripheral RBME base address */
  #define RBME_BASE_NS                             (0x48A06200u)
  /** Peripheral RBME base pointer */
  #define RBME                                     ((RBME_Type *)RBME_BASE)
  /** Peripheral RBME base pointer */
  #define RBME_NS                                  ((RBME_Type *)RBME_BASE_NS)
  /** Array initializer of RBME peripheral base addresses */
  #define RBME_BASE_ADDRS                          { RBME_BASE }
  /** Array initializer of RBME peripheral base pointers */
  #define RBME_BASE_PTRS                           { RBME }
  /** Array initializer of RBME peripheral base addresses */
  #define RBME_BASE_ADDRS_NS                       { RBME_BASE_NS }
  /** Array initializer of RBME peripheral base pointers */
  #define RBME_BASE_PTRS_NS                        { RBME_NS }
#else
  /** Peripheral RBME base address */
  #define RBME_BASE                                (0x48A06200u)
  /** Peripheral RBME base pointer */
  #define RBME                                     ((RBME_Type *)RBME_BASE)
  /** Array initializer of RBME peripheral base addresses */
  #define RBME_BASE_ADDRS                          { RBME_BASE }
  /** Array initializer of RBME peripheral base pointers */
  #define RBME_BASE_PTRS                           { RBME }
#endif

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

/* RFMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RFMC base address */
  #define RFMC_BASE                                (0x50040000u)
  /** Peripheral RFMC base address */
  #define RFMC_BASE_NS                             (0x40040000u)
  /** Peripheral RFMC base pointer */
  #define RFMC                                     ((RFMC_Type *)RFMC_BASE)
  /** Peripheral RFMC base pointer */
  #define RFMC_NS                                  ((RFMC_Type *)RFMC_BASE_NS)
  /** Array initializer of RFMC peripheral base addresses */
  #define RFMC_BASE_ADDRS                          { RFMC_BASE }
  /** Array initializer of RFMC peripheral base pointers */
  #define RFMC_BASE_PTRS                           { RFMC }
  /** Array initializer of RFMC peripheral base addresses */
  #define RFMC_BASE_ADDRS_NS                       { RFMC_BASE_NS }
  /** Array initializer of RFMC peripheral base pointers */
  #define RFMC_BASE_PTRS_NS                        { RFMC_NS }
#else
  /** Peripheral RFMC base address */
  #define RFMC_BASE                                (0x40040000u)
  /** Peripheral RFMC base pointer */
  #define RFMC                                     ((RFMC_Type *)RFMC_BASE)
  /** Array initializer of RFMC peripheral base addresses */
  #define RFMC_BASE_ADDRS                          { RFMC_BASE }
  /** Array initializer of RFMC peripheral base pointers */
  #define RFMC_BASE_PTRS                           { RFMC }
#endif

/* RF_CMC1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RF_CMC1 base address */
  #define RF_CMC1_BASE                             (0x58983000u)
  /** Peripheral RF_CMC1 base address */
  #define RF_CMC1_BASE_NS                          (0x48983000u)
  /** Peripheral RF_CMC1 base pointer */
  #define RF_CMC1                                  ((RF_CMC1_Type *)RF_CMC1_BASE)
  /** Peripheral RF_CMC1 base pointer */
  #define RF_CMC1_NS                               ((RF_CMC1_Type *)RF_CMC1_BASE_NS)
  /** Array initializer of RF_CMC1 peripheral base addresses */
  #define RF_CMC1_BASE_ADDRS                       { RF_CMC1_BASE }
  /** Array initializer of RF_CMC1 peripheral base pointers */
  #define RF_CMC1_BASE_PTRS                        { RF_CMC1 }
  /** Array initializer of RF_CMC1 peripheral base addresses */
  #define RF_CMC1_BASE_ADDRS_NS                    { RF_CMC1_BASE_NS }
  /** Array initializer of RF_CMC1 peripheral base pointers */
  #define RF_CMC1_BASE_PTRS_NS                     { RF_CMC1_NS }
#else
  /** Peripheral RF_CMC1 base address */
  #define RF_CMC1_BASE                             (0x48983000u)
  /** Peripheral RF_CMC1 base pointer */
  #define RF_CMC1                                  ((RF_CMC1_Type *)RF_CMC1_BASE)
  /** Array initializer of RF_CMC1 peripheral base addresses */
  #define RF_CMC1_BASE_ADDRS                       { RF_CMC1_BASE }
  /** Array initializer of RF_CMC1 peripheral base pointers */
  #define RF_CMC1_BASE_PTRS                        { RF_CMC1 }
#endif

/* RF_FMCCFG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RF_FMCCFG base address */
  #define RF_FMCCFG_BASE                           (0x58982000u)
  /** Peripheral RF_FMCCFG base address */
  #define RF_FMCCFG_BASE_NS                        (0x48982000u)
  /** Peripheral RF_FMCCFG base pointer */
  #define RF_FMCCFG                                ((RF_FMCCFG_Type *)RF_FMCCFG_BASE)
  /** Peripheral RF_FMCCFG base pointer */
  #define RF_FMCCFG_NS                             ((RF_FMCCFG_Type *)RF_FMCCFG_BASE_NS)
  /** Array initializer of RF_FMCCFG peripheral base addresses */
  #define RF_FMCCFG_BASE_ADDRS                     { RF_FMCCFG_BASE }
  /** Array initializer of RF_FMCCFG peripheral base pointers */
  #define RF_FMCCFG_BASE_PTRS                      { RF_FMCCFG }
  /** Array initializer of RF_FMCCFG peripheral base addresses */
  #define RF_FMCCFG_BASE_ADDRS_NS                  { RF_FMCCFG_BASE_NS }
  /** Array initializer of RF_FMCCFG peripheral base pointers */
  #define RF_FMCCFG_BASE_PTRS_NS                   { RF_FMCCFG_NS }
#else
  /** Peripheral RF_FMCCFG base address */
  #define RF_FMCCFG_BASE                           (0x48982000u)
  /** Peripheral RF_FMCCFG base pointer */
  #define RF_FMCCFG                                ((RF_FMCCFG_Type *)RF_FMCCFG_BASE)
  /** Array initializer of RF_FMCCFG peripheral base addresses */
  #define RF_FMCCFG_BASE_ADDRS                     { RF_FMCCFG_BASE }
  /** Array initializer of RF_FMCCFG peripheral base pointers */
  #define RF_FMCCFG_BASE_PTRS                      { RF_FMCCFG }
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

/* RX_PACKET_RAM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RX_PACKET_RAM base address */
  #define RX_PACKET_RAM_BASE                       (0x58A09000u)
  /** Peripheral RX_PACKET_RAM base address */
  #define RX_PACKET_RAM_BASE_NS                    (0x48A09000u)
  /** Peripheral RX_PACKET_RAM base pointer */
  #define RX_PACKET_RAM                            ((RX_PACKET_RAM_Type *)RX_PACKET_RAM_BASE)
  /** Peripheral RX_PACKET_RAM base pointer */
  #define RX_PACKET_RAM_NS                         ((RX_PACKET_RAM_Type *)RX_PACKET_RAM_BASE_NS)
  /** Array initializer of RX_PACKET_RAM peripheral base addresses */
  #define RX_PACKET_RAM_BASE_ADDRS                 { RX_PACKET_RAM_BASE }
  /** Array initializer of RX_PACKET_RAM peripheral base pointers */
  #define RX_PACKET_RAM_BASE_PTRS                  { RX_PACKET_RAM }
  /** Array initializer of RX_PACKET_RAM peripheral base addresses */
  #define RX_PACKET_RAM_BASE_ADDRS_NS              { RX_PACKET_RAM_BASE_NS }
  /** Array initializer of RX_PACKET_RAM peripheral base pointers */
  #define RX_PACKET_RAM_BASE_PTRS_NS               { RX_PACKET_RAM_NS }
#else
  /** Peripheral RX_PACKET_RAM base address */
  #define RX_PACKET_RAM_BASE                       (0x48A09000u)
  /** Peripheral RX_PACKET_RAM base pointer */
  #define RX_PACKET_RAM                            ((RX_PACKET_RAM_Type *)RX_PACKET_RAM_BASE)
  /** Array initializer of RX_PACKET_RAM peripheral base addresses */
  #define RX_PACKET_RAM_BASE_ADDRS                 { RX_PACKET_RAM_BASE }
  /** Array initializer of RX_PACKET_RAM peripheral base pointers */
  #define RX_PACKET_RAM_BASE_PTRS                  { RX_PACKET_RAM }
#endif

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
  /** Peripheral RF_SFA base address */
  #define RF_SFA_BASE                              (0x58A06300u)
  /** Peripheral RF_SFA base address */
  #define RF_SFA_BASE_NS                           (0x48A06300u)
  /** Peripheral RF_SFA base pointer */
  #define RF_SFA                                   ((SFA_Type *)RF_SFA_BASE)
  /** Peripheral RF_SFA base pointer */
  #define RF_SFA_NS                                ((SFA_Type *)RF_SFA_BASE_NS)
  /** Array initializer of SFA peripheral base addresses */
  #define SFA_BASE_ADDRS                           { SFA0_BASE, RF_SFA_BASE }
  /** Array initializer of SFA peripheral base pointers */
  #define SFA_BASE_PTRS                            { SFA0, RF_SFA }
  /** Array initializer of SFA peripheral base addresses */
  #define SFA_BASE_ADDRS_NS                        { SFA0_BASE_NS, RF_SFA_BASE_NS }
  /** Array initializer of SFA peripheral base pointers */
  #define SFA_BASE_PTRS_NS                         { SFA0_NS, RF_SFA_NS }
#else
  /** Peripheral SFA0 base address */
  #define SFA0_BASE                                (0x4001D000u)
  /** Peripheral SFA0 base pointer */
  #define SFA0                                     ((SFA_Type *)SFA0_BASE)
  /** Peripheral RF_SFA base address */
  #define RF_SFA_BASE                              (0x48A06300u)
  /** Peripheral RF_SFA base pointer */
  #define RF_SFA                                   ((SFA_Type *)RF_SFA_BASE)
  /** Array initializer of SFA peripheral base addresses */
  #define SFA_BASE_ADDRS                           { SFA0_BASE, RF_SFA_BASE }
  /** Array initializer of SFA peripheral base pointers */
  #define SFA_BASE_PTRS                            { SFA0, RF_SFA }
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
#define MBC0_MEMORY_CFG_WORD_COUNT {8, 1, 1, 2}
#define MBC1_MEMORY_CFG_WORD_COUNT {1, 2, 2, 1}
#define MBC2_MEMORY_CFG_WORD_COUNT {11, 1, 2, 0}
#define MBC3_MEMORY_CFG_WORD_COUNT {0, 0, 0, 0}
#define MBC_MEMORY_CFG_WORD_COUNT {MBC0_MEMORY_CFG_WORD_COUNT , MBC1_MEMORY_CFG_WORD_COUNT, MBC2_MEMORY_CFG_WORD_COUNT, MBC3_MEMORY_CFG_WORD_COUNT}
#define MBC0_MEMORY_NSE_WORD_COUNT {2, 1, 1, 1}
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

/* TX_PACKET_RAM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TX_PACKET_RAM base address */
  #define TX_PACKET_RAM_BASE                       (0x58A08000u)
  /** Peripheral TX_PACKET_RAM base address */
  #define TX_PACKET_RAM_BASE_NS                    (0x48A08000u)
  /** Peripheral TX_PACKET_RAM base pointer */
  #define TX_PACKET_RAM                            ((TX_PACKET_RAM_Type *)TX_PACKET_RAM_BASE)
  /** Peripheral TX_PACKET_RAM base pointer */
  #define TX_PACKET_RAM_NS                         ((TX_PACKET_RAM_Type *)TX_PACKET_RAM_BASE_NS)
  /** Array initializer of TX_PACKET_RAM peripheral base addresses */
  #define TX_PACKET_RAM_BASE_ADDRS                 { TX_PACKET_RAM_BASE }
  /** Array initializer of TX_PACKET_RAM peripheral base pointers */
  #define TX_PACKET_RAM_BASE_PTRS                  { TX_PACKET_RAM }
  /** Array initializer of TX_PACKET_RAM peripheral base addresses */
  #define TX_PACKET_RAM_BASE_ADDRS_NS              { TX_PACKET_RAM_BASE_NS }
  /** Array initializer of TX_PACKET_RAM peripheral base pointers */
  #define TX_PACKET_RAM_BASE_PTRS_NS               { TX_PACKET_RAM_NS }
#else
  /** Peripheral TX_PACKET_RAM base address */
  #define TX_PACKET_RAM_BASE                       (0x48A08000u)
  /** Peripheral TX_PACKET_RAM base pointer */
  #define TX_PACKET_RAM                            ((TX_PACKET_RAM_Type *)TX_PACKET_RAM_BASE)
  /** Array initializer of TX_PACKET_RAM peripheral base addresses */
  #define TX_PACKET_RAM_BASE_ADDRS                 { TX_PACKET_RAM_BASE }
  /** Array initializer of TX_PACKET_RAM peripheral base pointers */
  #define TX_PACKET_RAM_BASE_PTRS                  { TX_PACKET_RAM }
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

/* WOR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WOR_REGS base address */
  #define WOR_REGS_BASE                            (0x58A06100u)
  /** Peripheral WOR_REGS base address */
  #define WOR_REGS_BASE_NS                         (0x48A06100u)
  /** Peripheral WOR_REGS base pointer */
  #define WOR_REGS                                 ((WOR_Type *)WOR_REGS_BASE)
  /** Peripheral WOR_REGS base pointer */
  #define WOR_REGS_NS                              ((WOR_Type *)WOR_REGS_BASE_NS)
  /** Array initializer of WOR peripheral base addresses */
  #define WOR_BASE_ADDRS                           { WOR_REGS_BASE }
  /** Array initializer of WOR peripheral base pointers */
  #define WOR_BASE_PTRS                            { WOR_REGS }
  /** Array initializer of WOR peripheral base addresses */
  #define WOR_BASE_ADDRS_NS                        { WOR_REGS_BASE_NS }
  /** Array initializer of WOR peripheral base pointers */
  #define WOR_BASE_PTRS_NS                         { WOR_REGS_NS }
#else
  /** Peripheral WOR_REGS base address */
  #define WOR_REGS_BASE                            (0x48A06100u)
  /** Peripheral WOR_REGS base pointer */
  #define WOR_REGS                                 ((WOR_Type *)WOR_REGS_BASE)
  /** Array initializer of WOR peripheral base addresses */
  #define WOR_BASE_ADDRS                           { WOR_REGS_BASE }
  /** Array initializer of WOR peripheral base pointers */
  #define WOR_BASE_PTRS                            { WOR_REGS }
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

/* XCVR_ANALOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_ANALOG base address */
  #define XCVR_ANALOG_BASE                         (0x58A07C00u)
  /** Peripheral XCVR_ANALOG base address */
  #define XCVR_ANALOG_BASE_NS                      (0x48A07C00u)
  /** Peripheral XCVR_ANALOG base pointer */
  #define XCVR_ANALOG                              ((XCVR_ANALOG_Type *)XCVR_ANALOG_BASE)
  /** Peripheral XCVR_ANALOG base pointer */
  #define XCVR_ANALOG_NS                           ((XCVR_ANALOG_Type *)XCVR_ANALOG_BASE_NS)
  /** Array initializer of XCVR_ANALOG peripheral base addresses */
  #define XCVR_ANALOG_BASE_ADDRS                   { XCVR_ANALOG_BASE }
  /** Array initializer of XCVR_ANALOG peripheral base pointers */
  #define XCVR_ANALOG_BASE_PTRS                    { XCVR_ANALOG }
  /** Array initializer of XCVR_ANALOG peripheral base addresses */
  #define XCVR_ANALOG_BASE_ADDRS_NS                { XCVR_ANALOG_BASE_NS }
  /** Array initializer of XCVR_ANALOG peripheral base pointers */
  #define XCVR_ANALOG_BASE_PTRS_NS                 { XCVR_ANALOG_NS }
#else
  /** Peripheral XCVR_ANALOG base address */
  #define XCVR_ANALOG_BASE                         (0x48A07C00u)
  /** Peripheral XCVR_ANALOG base pointer */
  #define XCVR_ANALOG                              ((XCVR_ANALOG_Type *)XCVR_ANALOG_BASE)
  /** Array initializer of XCVR_ANALOG peripheral base addresses */
  #define XCVR_ANALOG_BASE_ADDRS                   { XCVR_ANALOG_BASE }
  /** Array initializer of XCVR_ANALOG peripheral base pointers */
  #define XCVR_ANALOG_BASE_PTRS                    { XCVR_ANALOG }
#endif

/* XCVR_MISC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_MISC base address */
  #define XCVR_MISC_BASE                           (0x58A07D00u)
  /** Peripheral XCVR_MISC base address */
  #define XCVR_MISC_BASE_NS                        (0x48A07D00u)
  /** Peripheral XCVR_MISC base pointer */
  #define XCVR_MISC                                ((XCVR_MISC_Type *)XCVR_MISC_BASE)
  /** Peripheral XCVR_MISC base pointer */
  #define XCVR_MISC_NS                             ((XCVR_MISC_Type *)XCVR_MISC_BASE_NS)
  /** Array initializer of XCVR_MISC peripheral base addresses */
  #define XCVR_MISC_BASE_ADDRS                     { XCVR_MISC_BASE }
  /** Array initializer of XCVR_MISC peripheral base pointers */
  #define XCVR_MISC_BASE_PTRS                      { XCVR_MISC }
  /** Array initializer of XCVR_MISC peripheral base addresses */
  #define XCVR_MISC_BASE_ADDRS_NS                  { XCVR_MISC_BASE_NS }
  /** Array initializer of XCVR_MISC peripheral base pointers */
  #define XCVR_MISC_BASE_PTRS_NS                   { XCVR_MISC_NS }
#else
  /** Peripheral XCVR_MISC base address */
  #define XCVR_MISC_BASE                           (0x48A07D00u)
  /** Peripheral XCVR_MISC base pointer */
  #define XCVR_MISC                                ((XCVR_MISC_Type *)XCVR_MISC_BASE)
  /** Array initializer of XCVR_MISC peripheral base addresses */
  #define XCVR_MISC_BASE_ADDRS                     { XCVR_MISC_BASE }
  /** Array initializer of XCVR_MISC peripheral base pointers */
  #define XCVR_MISC_BASE_PTRS                      { XCVR_MISC }
#endif

/* XCVR_PLL_DIG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_PLL_DIG base address */
  #define XCVR_PLL_DIG_BASE                        (0x58A07300u)
  /** Peripheral XCVR_PLL_DIG base address */
  #define XCVR_PLL_DIG_BASE_NS                     (0x48A07300u)
  /** Peripheral XCVR_PLL_DIG base pointer */
  #define XCVR_PLL_DIG                             ((XCVR_PLL_DIG_Type *)XCVR_PLL_DIG_BASE)
  /** Peripheral XCVR_PLL_DIG base pointer */
  #define XCVR_PLL_DIG_NS                          ((XCVR_PLL_DIG_Type *)XCVR_PLL_DIG_BASE_NS)
  /** Array initializer of XCVR_PLL_DIG peripheral base addresses */
  #define XCVR_PLL_DIG_BASE_ADDRS                  { XCVR_PLL_DIG_BASE }
  /** Array initializer of XCVR_PLL_DIG peripheral base pointers */
  #define XCVR_PLL_DIG_BASE_PTRS                   { XCVR_PLL_DIG }
  /** Array initializer of XCVR_PLL_DIG peripheral base addresses */
  #define XCVR_PLL_DIG_BASE_ADDRS_NS               { XCVR_PLL_DIG_BASE_NS }
  /** Array initializer of XCVR_PLL_DIG peripheral base pointers */
  #define XCVR_PLL_DIG_BASE_PTRS_NS                { XCVR_PLL_DIG_NS }
#else
  /** Peripheral XCVR_PLL_DIG base address */
  #define XCVR_PLL_DIG_BASE                        (0x48A07300u)
  /** Peripheral XCVR_PLL_DIG base pointer */
  #define XCVR_PLL_DIG                             ((XCVR_PLL_DIG_Type *)XCVR_PLL_DIG_BASE)
  /** Array initializer of XCVR_PLL_DIG peripheral base addresses */
  #define XCVR_PLL_DIG_BASE_ADDRS                  { XCVR_PLL_DIG_BASE }
  /** Array initializer of XCVR_PLL_DIG peripheral base pointers */
  #define XCVR_PLL_DIG_BASE_PTRS                   { XCVR_PLL_DIG }
#endif

/* XCVR_RX_DIG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_RX_DIG base address */
  #define XCVR_RX_DIG_BASE                         (0x58A07000u)
  /** Peripheral XCVR_RX_DIG base address */
  #define XCVR_RX_DIG_BASE_NS                      (0x48A07000u)
  /** Peripheral XCVR_RX_DIG base pointer */
  #define XCVR_RX_DIG                              ((XCVR_RX_DIG_Type *)XCVR_RX_DIG_BASE)
  /** Peripheral XCVR_RX_DIG base pointer */
  #define XCVR_RX_DIG_NS                           ((XCVR_RX_DIG_Type *)XCVR_RX_DIG_BASE_NS)
  /** Array initializer of XCVR_RX_DIG peripheral base addresses */
  #define XCVR_RX_DIG_BASE_ADDRS                   { XCVR_RX_DIG_BASE }
  /** Array initializer of XCVR_RX_DIG peripheral base pointers */
  #define XCVR_RX_DIG_BASE_PTRS                    { XCVR_RX_DIG }
  /** Array initializer of XCVR_RX_DIG peripheral base addresses */
  #define XCVR_RX_DIG_BASE_ADDRS_NS                { XCVR_RX_DIG_BASE_NS }
  /** Array initializer of XCVR_RX_DIG peripheral base pointers */
  #define XCVR_RX_DIG_BASE_PTRS_NS                 { XCVR_RX_DIG_NS }
#else
  /** Peripheral XCVR_RX_DIG base address */
  #define XCVR_RX_DIG_BASE                         (0x48A07000u)
  /** Peripheral XCVR_RX_DIG base pointer */
  #define XCVR_RX_DIG                              ((XCVR_RX_DIG_Type *)XCVR_RX_DIG_BASE)
  /** Array initializer of XCVR_RX_DIG peripheral base addresses */
  #define XCVR_RX_DIG_BASE_ADDRS                   { XCVR_RX_DIG_BASE }
  /** Array initializer of XCVR_RX_DIG peripheral base pointers */
  #define XCVR_RX_DIG_BASE_PTRS                    { XCVR_RX_DIG }
#endif

/* XCVR_TSM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_TSM base address */
  #define XCVR_TSM_BASE                            (0x58A07800u)
  /** Peripheral XCVR_TSM base address */
  #define XCVR_TSM_BASE_NS                         (0x48A07800u)
  /** Peripheral XCVR_TSM base pointer */
  #define XCVR_TSM                                 ((XCVR_TSM_Type *)XCVR_TSM_BASE)
  /** Peripheral XCVR_TSM base pointer */
  #define XCVR_TSM_NS                              ((XCVR_TSM_Type *)XCVR_TSM_BASE_NS)
  /** Array initializer of XCVR_TSM peripheral base addresses */
  #define XCVR_TSM_BASE_ADDRS                      { XCVR_TSM_BASE }
  /** Array initializer of XCVR_TSM peripheral base pointers */
  #define XCVR_TSM_BASE_PTRS                       { XCVR_TSM }
  /** Array initializer of XCVR_TSM peripheral base addresses */
  #define XCVR_TSM_BASE_ADDRS_NS                   { XCVR_TSM_BASE_NS }
  /** Array initializer of XCVR_TSM peripheral base pointers */
  #define XCVR_TSM_BASE_PTRS_NS                    { XCVR_TSM_NS }
#else
  /** Peripheral XCVR_TSM base address */
  #define XCVR_TSM_BASE                            (0x48A07800u)
  /** Peripheral XCVR_TSM base pointer */
  #define XCVR_TSM                                 ((XCVR_TSM_Type *)XCVR_TSM_BASE)
  /** Array initializer of XCVR_TSM peripheral base addresses */
  #define XCVR_TSM_BASE_ADDRS                      { XCVR_TSM_BASE }
  /** Array initializer of XCVR_TSM peripheral base pointers */
  #define XCVR_TSM_BASE_PTRS                       { XCVR_TSM }
#endif

/* XCVR_TX_DIG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCVR_TX_DIG base address */
  #define XCVR_TX_DIG_BASE                         (0x58A07200u)
  /** Peripheral XCVR_TX_DIG base address */
  #define XCVR_TX_DIG_BASE_NS                      (0x48A07200u)
  /** Peripheral XCVR_TX_DIG base pointer */
  #define XCVR_TX_DIG                              ((XCVR_TX_DIG_Type *)XCVR_TX_DIG_BASE)
  /** Peripheral XCVR_TX_DIG base pointer */
  #define XCVR_TX_DIG_NS                           ((XCVR_TX_DIG_Type *)XCVR_TX_DIG_BASE_NS)
  /** Array initializer of XCVR_TX_DIG peripheral base addresses */
  #define XCVR_TX_DIG_BASE_ADDRS                   { XCVR_TX_DIG_BASE }
  /** Array initializer of XCVR_TX_DIG peripheral base pointers */
  #define XCVR_TX_DIG_BASE_PTRS                    { XCVR_TX_DIG }
  /** Array initializer of XCVR_TX_DIG peripheral base addresses */
  #define XCVR_TX_DIG_BASE_ADDRS_NS                { XCVR_TX_DIG_BASE_NS }
  /** Array initializer of XCVR_TX_DIG peripheral base pointers */
  #define XCVR_TX_DIG_BASE_PTRS_NS                 { XCVR_TX_DIG_NS }
#else
  /** Peripheral XCVR_TX_DIG base address */
  #define XCVR_TX_DIG_BASE                         (0x48A07200u)
  /** Peripheral XCVR_TX_DIG base pointer */
  #define XCVR_TX_DIG                              ((XCVR_TX_DIG_Type *)XCVR_TX_DIG_BASE)
  /** Array initializer of XCVR_TX_DIG peripheral base addresses */
  #define XCVR_TX_DIG_BASE_ADDRS                   { XCVR_TX_DIG_BASE }
  /** Array initializer of XCVR_TX_DIG peripheral base pointers */
  #define XCVR_TX_DIG_BASE_PTRS                    { XCVR_TX_DIG }
#endif

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

#if defined(KW47B42Z83_cm33_core0_H_) || defined(KW47B42Z96_cm33_core0_H_) || defined(KW47B42Z97_cm33_core0_H_) || defined(KW47B42ZB2_cm33_core0_H_) || defined(KW47B42ZB3_cm33_core0_H_) || defined(KW47B42ZB6_cm33_core0_H_) || defined(KW47B42ZB7_cm33_core0_H_) || defined(KW47Z420B2_H_) || defined(KW47Z420B3_H_) || defined(KW47Z42082_H_) || defined(KW47Z42092_H_)
#define RADIO_IS_GEN_4P7 (1)
#define NXP_RADIO_GEN (470)
#define IS_APP_CORE (1)
#define IS_RADIO_CORE (0)
#ifndef KW47_core0_SERIES
#define KW47_core0_SERIES
#endif

/*! @brief define LTC0 from LTC. */
#define LTC0 LTC


/*
 * Macros below define the chip revision.
 */
#define DEVICE_REVISION_A0     (0x10U)
#define DEVICE_REVISION_A1     (0x11U)
#define DEVICE_REVISION_A2     (0x12U)
#define DEVICE_REVISION_OTHERS (0xFFU)

#define IS_CHIP_REVISION_A0() (DEVICE_REVISION_A0 == Chip_GetVersion())
#define IS_CHIP_REVISION_A1() (DEVICE_REVISION_A1 == Chip_GetVersion())
#define IS_CHIP_REVISION_A2() (DEVICE_REVISION_A2 == Chip_GetVersion())

/*!
* @brief Get the chip value.
*
* @return chip version, 0x10: A0 version chip, 0x11: A1 version chip, 0x12: A2 version chip, 0xFF: invalid version.
*/
static inline uint8_t Chip_GetVersion(void)
{
    return DEVICE_REVISION_A0;
}

/*
 * CE STCMs base address.
 */
#define CE_STCM5_BASE (0x20020000u)
#define CE_STCM6_BASE (0x20028000u)
#define CE_STCM7_BASE (0x20030000u)

#elif defined(KW47B42Z83_cm33_core1_H_) || defined(KW47B42Z96_cm33_core1_H_) || defined(KW47B42Z97_cm33_core1_H_) || defined(KW47B42ZB2_cm33_core1_H_) || defined(KW47B42ZB3_cm33_core1_H_) || defined(KW47B42ZB6_cm33_core1_H_) || defined(KW47B42ZB7_cm33_core1_H_)
#define RADIO_IS_GEN_4P7 (1)
#define NXP_RADIO_GEN (470)
#define IS_APP_CORE (0)
#define IS_RADIO_CORE (1)
#ifndef KW47_core1_SERIES
#define KW47_core1_SERIES
#endif

/*! @brief define LTC0 from LTC. */
#define LTC0 LTC

#endif

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* KW47B42ZB3_CM33_CORE0_COMMON_H_ */

