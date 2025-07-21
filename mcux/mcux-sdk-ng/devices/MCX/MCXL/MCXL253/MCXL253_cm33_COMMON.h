/*
** ###################################################################
**     Processors:          MCXL253VDF_cm33
**                          MCXL253VLL_cm33
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXL25xRM DraftF
**     Version:             rev. 1.0, 2023-01-09
**     Build:               b250422
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCXL253_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file MCXL253_cm33_COMMON.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for MCXL253_cm33
 *
 * CMSIS Peripheral Access Layer for MCXL253_cm33
 */

#if !defined(MCXL253_CM33_COMMON_H_)
#define MCXL253_CM33_COMMON_H_                   /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 178                /**< Number of interrupts in the Vector table */

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
  Reserved16_IRQn              = 0,                /**< OR IRQ1 to IRQ79 */
  CMC_IRQn                     = 1,                /**< Core Mode Controller interrupt */
  DMA0_CH0_IRQn                = 2,                /**< DMA3_0_CH0 error or transfer complete */
  DMA0_CH1_IRQn                = 3,                /**< DMA3_0_CH1 error or transfer complete */
  DMA0_CH2_IRQn                = 4,                /**< DMA3_0_CH2 error or transfer complete */
  DMA0_CH3_IRQn                = 5,                /**< DMA3_0_CH3 error or transfer complete */
  ERM0_IRQn                    = 10,               /**< ERM Single Bit error interrupt */
  FMU0_IRQn                    = 12,               /**< Flash Management Unit interrupt */
  GLIKEY0_IRQn                 = 13,               /**< GLIKEY Interrupt  */
  MBC0_IRQn                    = 14,               /**< MBC secure violation interrupt */
  SCG0_IRQn                    = 15,               /**< System Clock Generator interrupt */
  WUU0_IRQn                    = 18,               /**< Wake Up Unit interrupt */
  LPI2C0_IRQn                  = 26,               /**< Low-Power Inter Integrated Circuit interrupt */
  LPI2C1_IRQn                  = 27,               /**< Low-Power Inter Integrated Circuit interrupt */
  LPSPI0_IRQn                  = 28,               /**< Low-Power Serial Peripheral Interface interrupt */
  LPSPI1_IRQn                  = 29,               /**< Low-Power Serial Peripheral Interface interrupt */
  LPUART0_IRQn                 = 31,               /**< Low-Power Universal Asynchronous Receive/Transmit interrupt */
  LPUART1_IRQn                 = 32,               /**< Low-Power Universal Asynchronous Receive/Transmit interrupt */
  CDOG0_IRQn                   = 38,               /**< Code Watchdog Timer 0 interrupt */
  CTIMER0_IRQn                 = 39,               /**< Standard counter/timer 0 interrupt */
  CTIMER1_IRQn                 = 40,               /**< Standard counter/timer 1 interrupt */
  CTIMER2_IRQn                 = 41,               /**< Standard counter/timer 2 interrupt */
  FREQME0_IRQn                 = 54,               /**< Frequency Measurement interrupt */
  OS_EVENT_IRQn                = 57,               /**< OS event timer interrupt */
  UTICK0_IRQn                  = 59,               /**< Micro-Tick Timer interrupt */
  WWDT0_IRQn                   = 60,               /**< Windowed Watchdog Timer 0 interrupt */
  ADC0_IRQn                    = 62,               /**< Analog-to-Digital Converter interrupt */
  CMP0_IRQn                    = 64,               /**< Comparator interrupt */
  GPIO10_IRQn                  = 71,               /**< General Purpose Input/Output 1 interrupt 0 */
  GPIO11_IRQn                  = 72,               /**< General Purpose Input/Output 1 interrupt 1 */
  GPIO20_IRQn                  = 73,               /**< General Purpose Input/Output 2 interrupt 0 */
  GPIO21_IRQn                  = 74,               /**< General Purpose Input/Output 2 interrupt 1 */
  GPIO30_IRQn                  = 75,               /**< General Purpose Input/Output 3 interrupt 0 */
  GPIO31_IRQn                  = 76,               /**< General Purpose Input/Output 3 interrupt 1 */
  MU_A_TX_IRQn                 = 80,               /**< Ored tx interrupt to MUA */
  MU_A_RX_IRQn                 = 81,               /**< Ored rx interrupt to MUA */
  MU_A_INT_IRQn                = 82,               /**< ORed general purpose interrupt request to MUA */
  CDOG1_IRQn                   = 83,               /**< Code Watchdog Timer 1 interrupt */
  DMA1_CH0_IRQn                = 96,               /**< DMA3_1_CH0 error or transfer complete */
  DMA1_CH1_IRQn                = 97,               /**< DMA3_1_CH1 error or transfer complete */
  DMA1_CH2_IRQn                = 98,               /**< DMA3_1_CH2 error or transfer complete */
  DMA1_CH3_IRQn                = 99,               /**< DMA3_1_CH3 error or transfer complete */
  PKC_IRQn                     = 110,              /**< PKC interrupt */
  SGI_IRQn                     = 111,              /**< SGI interrupt */
  TRNG_IRQn                    = 112,              /**< TRNG interrupt */
  ERR_SGI_UDF_TRNG_PKC_IRQn    = 113,              /**< ORed Error Interrupt from SGI, UDF,TRNG and PKC */
  HYPERVISOR_IRQn              = 114,              /**< Hypervisor interrupt */
  LPI2C0_AON_IRQn              = 128,              /**< Low-Power Inter Integrated Circuit interrupt */
  LPUART0_AON_IRQn             = 130,              /**< Low-Power Universal Asynchronous Receive/Transmit interrupt */
  GPIO00_AON_IRQn              = 132,              /**< General Purpose Input/Output interrupt 0 */
  GPIO01_AON_IRQn              = 133,              /**< General Purpose Input/Output interrupt 1 */
  LPCMP_IRQn                   = 139,              /**< Comparator */
  RTC_ALARM0_IRQn              = 140,              /**< RTC alarm 0 */
  RTC_ALARM1_IRQn              = 141,              /**< RTC alarm 1 */
  RTC_ALARM2_IRQn              = 142,              /**< RTC alarm 2 */
  RTC_WDT_IRQn                 = 143,              /**< RTC watchdog */
  RTC_XTAL_IRQn                = 144,              /**< RTC XTAL Fail */
  KPP_IRQn                     = 148,              /**< Keypad Interrupt */
  LPADC_AON_IRQn               = 149,              /**< ADC Summary Interrupt */
  TMR0_AON_IRQn                = 151,              /**< ORed QTMR Interrupts */
  TMR1_AON_IRQn                = 152,              /**< ORed QTMR Interrupts */
  LCSENSE_IRQn                 = 154,              /**< LCSense Fault/Tamper Interrupt */
  LPTMR_AON_IRQn               = 155,              /**< Low Power Timer 0 interrupt */
  CMP0_AON_IRQn                = 157,              /**< Comparator interrupt */
  ADVC_IRQn                    = 158,              /**< ADVC_2.0 Controller Interrupt */
  SGLCD_FRAME_AON_IRQn         = 160,              /**< Frame Update Interrupt */
  SGLCD_FFAULT_AON_IRQn        = 161               /**< Fault Detect Interrupt */
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
#include "system_MCXL253_cm33.h"       /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MCXL253_cm33_SERIES
#define MCXL253_cm33_SERIES
#endif
/* CPU specific feature definitions */
#include "MCXL253_cm33_features.h"

/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADC0 base address */
  #define ADC0_BASE                                (0x500AF000u)
  /** Peripheral ADC0 base address */
  #define ADC0_BASE_NS                             (0x400AF000u)
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
  #define ADC0_BASE                                (0x400AF000u)
  /** Peripheral ADC0 base pointer */
  #define ADC0                                     ((ADC_Type *)ADC0_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC0_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC0 }
#endif
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn }

/* AHBSC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AHBSC__AHBSC0 base address */
  #define AHBSC__AHBSC0_BASE                       (0x50108000u)
  /** Peripheral AHBSC__AHBSC0 base address */
  #define AHBSC__AHBSC0_BASE_NS                    (0x40108000u)
  /** Peripheral AHBSC__AHBSC0 base pointer */
  #define AHBSC__AHBSC0                            ((AHBSC_Type *)AHBSC__AHBSC0_BASE)
  /** Peripheral AHBSC__AHBSC0 base pointer */
  #define AHBSC__AHBSC0_NS                         ((AHBSC_Type *)AHBSC__AHBSC0_BASE_NS)
  /** Array initializer of AHBSC peripheral base addresses */
  #define AHBSC_BASE_ADDRS                         { AHBSC__AHBSC0_BASE }
  /** Array initializer of AHBSC peripheral base pointers */
  #define AHBSC_BASE_PTRS                          { AHBSC__AHBSC0 }
  /** Array initializer of AHBSC peripheral base addresses */
  #define AHBSC_BASE_ADDRS_NS                      { AHBSC__AHBSC0_BASE_NS }
  /** Array initializer of AHBSC peripheral base pointers */
  #define AHBSC_BASE_PTRS_NS                       { AHBSC__AHBSC0_NS }
#else
  /** Peripheral AHBSC__AHBSC0 base address */
  #define AHBSC__AHBSC0_BASE                       (0x40108000u)
  /** Peripheral AHBSC__AHBSC0 base pointer */
  #define AHBSC__AHBSC0                            ((AHBSC_Type *)AHBSC__AHBSC0_BASE)
  /** Array initializer of AHBSC peripheral base addresses */
  #define AHBSC_BASE_ADDRS                         { AHBSC__AHBSC0_BASE }
  /** Array initializer of AHBSC peripheral base pointers */
  #define AHBSC_BASE_PTRS                          { AHBSC__AHBSC0 }
#endif

/* AOI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AOI0 base address */
  #define AOI0_BASE                                (0x50089000u)
  /** Peripheral AOI0 base address */
  #define AOI0_BASE_NS                             (0x40089000u)
  /** Peripheral AOI0 base pointer */
  #define AOI0                                     ((AOI_Type *)AOI0_BASE)
  /** Peripheral AOI0 base pointer */
  #define AOI0_NS                                  ((AOI_Type *)AOI0_BASE_NS)
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS                           { AOI0_BASE }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS                            { AOI0 }
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS_NS                        { AOI0_BASE_NS }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS_NS                         { AOI0_NS }
#else
  /** Peripheral AOI0 base address */
  #define AOI0_BASE                                (0x40089000u)
  /** Peripheral AOI0 base pointer */
  #define AOI0                                     ((AOI_Type *)AOI0_BASE)
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS                           { AOI0_BASE }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS                            { AOI0 }
#endif

/* ATX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ATX0 base address */
  #define ATX0_BASE                                (0x500FD000u)
  /** Peripheral ATX0 base address */
  #define ATX0_BASE_NS                             (0x400FD000u)
  /** Peripheral ATX0 base pointer */
  #define ATX0                                     ((ATX_Type *)ATX0_BASE)
  /** Peripheral ATX0 base pointer */
  #define ATX0_NS                                  ((ATX_Type *)ATX0_BASE_NS)
  /** Array initializer of ATX peripheral base addresses */
  #define ATX_BASE_ADDRS                           { ATX0_BASE }
  /** Array initializer of ATX peripheral base pointers */
  #define ATX_BASE_PTRS                            { ATX0 }
  /** Array initializer of ATX peripheral base addresses */
  #define ATX_BASE_ADDRS_NS                        { ATX0_BASE_NS }
  /** Array initializer of ATX peripheral base pointers */
  #define ATX_BASE_PTRS_NS                         { ATX0_NS }
#else
  /** Peripheral ATX0 base address */
  #define ATX0_BASE                                (0x400FD000u)
  /** Peripheral ATX0 base pointer */
  #define ATX0                                     ((ATX_Type *)ATX0_BASE)
  /** Array initializer of ATX peripheral base addresses */
  #define ATX_BASE_ADDRS                           { ATX0_BASE }
  /** Array initializer of ATX peripheral base pointers */
  #define ATX_BASE_PTRS                            { ATX0 }
#endif

/* CDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CDOG0 base address */
  #define CDOG0_BASE                               (0x50100000u)
  /** Peripheral CDOG0 base address */
  #define CDOG0_BASE_NS                            (0x40100000u)
  /** Peripheral CDOG0 base pointer */
  #define CDOG0                                    ((CDOG_Type *)CDOG0_BASE)
  /** Peripheral CDOG0 base pointer */
  #define CDOG0_NS                                 ((CDOG_Type *)CDOG0_BASE_NS)
  /** Peripheral CDOG1 base address */
  #define CDOG1_BASE                               (0x50105000u)
  /** Peripheral CDOG1 base address */
  #define CDOG1_BASE_NS                            (0x40105000u)
  /** Peripheral CDOG1 base pointer */
  #define CDOG1                                    ((CDOG_Type *)CDOG1_BASE)
  /** Peripheral CDOG1 base pointer */
  #define CDOG1_NS                                 ((CDOG_Type *)CDOG1_BASE_NS)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { CDOG0_BASE, CDOG1_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { CDOG0, CDOG1 }
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS_NS                       { CDOG0_BASE_NS, CDOG1_BASE_NS }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS_NS                        { CDOG0_NS, CDOG1_NS }
#else
  /** Peripheral CDOG0 base address */
  #define CDOG0_BASE                               (0x40100000u)
  /** Peripheral CDOG0 base pointer */
  #define CDOG0                                    ((CDOG_Type *)CDOG0_BASE)
  /** Peripheral CDOG1 base address */
  #define CDOG1_BASE                               (0x40105000u)
  /** Peripheral CDOG1 base pointer */
  #define CDOG1                                    ((CDOG_Type *)CDOG1_BASE)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { CDOG0_BASE, CDOG1_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { CDOG0, CDOG1 }
#endif
/** Interrupt vectors for the CDOG peripheral type */
#define CDOG_IRQS                                { CDOG0_IRQn, CDOG1_IRQn }

/* CGU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__CGU base address */
  #define AON__CGU_BASE                            (0xB0099000u)
  /** Peripheral AON__CGU base address */
  #define AON__CGU_BASE_NS                         (0xA0099000u)
  /** Peripheral AON__CGU base pointer */
  #define AON__CGU                                 ((CGU_Type *)AON__CGU_BASE)
  /** Peripheral AON__CGU base pointer */
  #define AON__CGU_NS                              ((CGU_Type *)AON__CGU_BASE_NS)
  /** Array initializer of CGU peripheral base addresses */
  #define CGU_BASE_ADDRS                           { AON__CGU_BASE }
  /** Array initializer of CGU peripheral base pointers */
  #define CGU_BASE_PTRS                            { AON__CGU }
  /** Array initializer of CGU peripheral base addresses */
  #define CGU_BASE_ADDRS_NS                        { AON__CGU_BASE_NS }
  /** Array initializer of CGU peripheral base pointers */
  #define CGU_BASE_PTRS_NS                         { AON__CGU_NS }
#else
  /** Peripheral AON__CGU base address */
  #define AON__CGU_BASE                            (0xA0099000u)
  /** Peripheral AON__CGU base pointer */
  #define AON__CGU                                 ((CGU_Type *)AON__CGU_BASE)
  /** Array initializer of CGU peripheral base addresses */
  #define CGU_BASE_ADDRS                           { AON__CGU_BASE }
  /** Array initializer of CGU peripheral base pointers */
  #define CGU_BASE_PTRS                            { AON__CGU }
#endif

/* CMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMC base address */
  #define CMC_BASE                                 (0x5008B000u)
  /** Peripheral CMC base address */
  #define CMC_BASE_NS                              (0x4008B000u)
  /** Peripheral CMC base pointer */
  #define CMC                                      ((CMC_Type *)CMC_BASE)
  /** Peripheral CMC base pointer */
  #define CMC_NS                                   ((CMC_Type *)CMC_BASE_NS)
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS                           { CMC_BASE }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS                            { CMC }
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS_NS                        { CMC_BASE_NS }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS_NS                         { CMC_NS }
#else
  /** Peripheral CMC base address */
  #define CMC_BASE                                 (0x4008B000u)
  /** Peripheral CMC base pointer */
  #define CMC                                      ((CMC_Type *)CMC_BASE)
  /** Array initializer of CMC peripheral base addresses */
  #define CMC_BASE_ADDRS                           { CMC_BASE }
  /** Array initializer of CMC peripheral base pointers */
  #define CMC_BASE_PTRS                            { CMC }
#endif
/** Interrupt vectors for the CMC peripheral type */
#define CMC_IRQS                                 { CMC_IRQn }

/* CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CRC base address */
  #define CRC_BASE                                 (0x5008A000u)
  /** Peripheral CRC base address */
  #define CRC_BASE_NS                              (0x4008A000u)
  /** Peripheral CRC base pointer */
  #define CRC0                                     ((CRC_Type *)CRC_BASE)
  /** Peripheral CRC base pointer */
  #define CRC0_NS                                  ((CRC_Type *)CRC_BASE_NS)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC0 }
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS_NS                        { CRC_BASE_NS }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS_NS                         { CRC0_NS }
#else
  /** Peripheral CRC base address */
  #define CRC_BASE                                 (0x4008A000u)
  /** Peripheral CRC base pointer */
  #define CRC0                                     ((CRC_Type *)CRC_BASE)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC0 }
#endif

/* CTIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CTIMER0 base address */
  #define CTIMER0_BASE                             (0x50004000u)
  /** Peripheral CTIMER0 base address */
  #define CTIMER0_BASE_NS                          (0x40004000u)
  /** Peripheral CTIMER0 base pointer */
  #define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
  /** Peripheral CTIMER0 base pointer */
  #define CTIMER0_NS                               ((CTIMER_Type *)CTIMER0_BASE_NS)
  /** Peripheral CTIMER1 base address */
  #define CTIMER1_BASE                             (0x50005000u)
  /** Peripheral CTIMER1 base address */
  #define CTIMER1_BASE_NS                          (0x40005000u)
  /** Peripheral CTIMER1 base pointer */
  #define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
  /** Peripheral CTIMER1 base pointer */
  #define CTIMER1_NS                               ((CTIMER_Type *)CTIMER1_BASE_NS)
  /** Peripheral CTIMER2 base address */
  #define CTIMER2_BASE                             (0x50006000u)
  /** Peripheral CTIMER2 base address */
  #define CTIMER2_BASE_NS                          (0x40006000u)
  /** Peripheral CTIMER2 base pointer */
  #define CTIMER2                                  ((CTIMER_Type *)CTIMER2_BASE)
  /** Peripheral CTIMER2 base pointer */
  #define CTIMER2_NS                               ((CTIMER_Type *)CTIMER2_BASE_NS)
  /** Array initializer of CTIMER peripheral base addresses */
  #define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE, CTIMER2_BASE }
  /** Array initializer of CTIMER peripheral base pointers */
  #define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1, CTIMER2 }
  /** Array initializer of CTIMER peripheral base addresses */
  #define CTIMER_BASE_ADDRS_NS                     { CTIMER0_BASE_NS, CTIMER1_BASE_NS, CTIMER2_BASE_NS }
  /** Array initializer of CTIMER peripheral base pointers */
  #define CTIMER_BASE_PTRS_NS                      { CTIMER0_NS, CTIMER1_NS, CTIMER2_NS }
#else
  /** Peripheral CTIMER0 base address */
  #define CTIMER0_BASE                             (0x40004000u)
  /** Peripheral CTIMER0 base pointer */
  #define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
  /** Peripheral CTIMER1 base address */
  #define CTIMER1_BASE                             (0x40005000u)
  /** Peripheral CTIMER1 base pointer */
  #define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
  /** Peripheral CTIMER2 base address */
  #define CTIMER2_BASE                             (0x40006000u)
  /** Peripheral CTIMER2 base pointer */
  #define CTIMER2                                  ((CTIMER_Type *)CTIMER2_BASE)
  /** Array initializer of CTIMER peripheral base addresses */
  #define CTIMER_BASE_ADDRS                        { CTIMER0_BASE, CTIMER1_BASE, CTIMER2_BASE }
  /** Array initializer of CTIMER peripheral base pointers */
  #define CTIMER_BASE_PTRS                         { CTIMER0, CTIMER1, CTIMER2 }
#endif
/** Interrupt vectors for the CTIMER peripheral type */
#define CTIMER_IRQS                              { CTIMER0_IRQn, CTIMER1_IRQn, CTIMER2_IRQn }

/* DEBUGMAILBOX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DBGMAILBOX base address */
  #define DBGMAILBOX_BASE                          (0x50101000u)
  /** Peripheral DBGMAILBOX base address */
  #define DBGMAILBOX_BASE_NS                       (0x40101000u)
  /** Peripheral DBGMAILBOX base pointer */
  #define DBGMAILBOX                               ((DEBUGMAILBOX_Type *)DBGMAILBOX_BASE)
  /** Peripheral DBGMAILBOX base pointer */
  #define DBGMAILBOX_NS                            ((DEBUGMAILBOX_Type *)DBGMAILBOX_BASE_NS)
  /** Array initializer of DEBUGMAILBOX peripheral base addresses */
  #define DEBUGMAILBOX_BASE_ADDRS                  { DBGMAILBOX_BASE }
  /** Array initializer of DEBUGMAILBOX peripheral base pointers */
  #define DEBUGMAILBOX_BASE_PTRS                   { DBGMAILBOX }
  /** Array initializer of DEBUGMAILBOX peripheral base addresses */
  #define DEBUGMAILBOX_BASE_ADDRS_NS               { DBGMAILBOX_BASE_NS }
  /** Array initializer of DEBUGMAILBOX peripheral base pointers */
  #define DEBUGMAILBOX_BASE_PTRS_NS                { DBGMAILBOX_NS }
#else
  /** Peripheral DBGMAILBOX base address */
  #define DBGMAILBOX_BASE                          (0x40101000u)
  /** Peripheral DBGMAILBOX base pointer */
  #define DBGMAILBOX                               ((DEBUGMAILBOX_Type *)DBGMAILBOX_BASE)
  /** Array initializer of DEBUGMAILBOX peripheral base addresses */
  #define DEBUGMAILBOX_BASE_ADDRS                  { DBGMAILBOX_BASE }
  /** Array initializer of DEBUGMAILBOX peripheral base pointers */
  #define DEBUGMAILBOX_BASE_PTRS                   { DBGMAILBOX }
#endif

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA0 base address */
  #define DMA0_BASE                                (0x50080000u)
  /** Peripheral DMA0 base address */
  #define DMA0_BASE_NS                             (0x40080000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Peripheral DMA0 base pointer */
  #define DMA0_NS                                  ((DMA_Type *)DMA0_BASE_NS)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE                                (0x500D7000u)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE_NS                             (0x400D7000u)
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
  #define DMA0_BASE                                (0x40080000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE                                (0x400D7000u)
  /** Peripheral DMA1 base pointer */
  #define DMA1                                     ((DMA_Type *)DMA1_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA0_BASE, DMA1_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA0, DMA1 }
#endif

/* ERM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ERM0 base address */
  #define ERM0_BASE                                (0x5008D000u)
  /** Peripheral ERM0 base address */
  #define ERM0_BASE_NS                             (0x4008D000u)
  /** Peripheral ERM0 base pointer */
  #define ERM0                                     ((ERM_Type *)ERM0_BASE)
  /** Peripheral ERM0 base pointer */
  #define ERM0_NS                                  ((ERM_Type *)ERM0_BASE_NS)
  /** Array initializer of ERM peripheral base addresses */
  #define ERM_BASE_ADDRS                           { ERM0_BASE }
  /** Array initializer of ERM peripheral base pointers */
  #define ERM_BASE_PTRS                            { ERM0 }
  /** Array initializer of ERM peripheral base addresses */
  #define ERM_BASE_ADDRS_NS                        { ERM0_BASE_NS }
  /** Array initializer of ERM peripheral base pointers */
  #define ERM_BASE_PTRS_NS                         { ERM0_NS }
#else
  /** Peripheral ERM0 base address */
  #define ERM0_BASE                                (0x4008D000u)
  /** Peripheral ERM0 base pointer */
  #define ERM0                                     ((ERM_Type *)ERM0_BASE)
  /** Array initializer of ERM peripheral base addresses */
  #define ERM_BASE_ADDRS                           { ERM0_BASE }
  /** Array initializer of ERM peripheral base pointers */
  #define ERM_BASE_PTRS                            { ERM0 }
#endif

/* FMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FMC0 base address */
  #define FMC0_BASE                                (0x50094000u)
  /** Peripheral FMC0 base address */
  #define FMC0_BASE_NS                             (0x40094000u)
  /** Peripheral FMC0 base pointer */
  #define FMC0                                     ((FMC_Type *)FMC0_BASE)
  /** Peripheral FMC0 base pointer */
  #define FMC0_NS                                  ((FMC_Type *)FMC0_BASE_NS)
  /** Array initializer of FMC peripheral base addresses */
  #define FMC_BASE_ADDRS                           { FMC0_BASE }
  /** Array initializer of FMC peripheral base pointers */
  #define FMC_BASE_PTRS                            { FMC0 }
  /** Array initializer of FMC peripheral base addresses */
  #define FMC_BASE_ADDRS_NS                        { FMC0_BASE_NS }
  /** Array initializer of FMC peripheral base pointers */
  #define FMC_BASE_PTRS_NS                         { FMC0_NS }
#else
  /** Peripheral FMC0 base address */
  #define FMC0_BASE                                (0x40094000u)
  /** Peripheral FMC0 base pointer */
  #define FMC0                                     ((FMC_Type *)FMC0_BASE)
  /** Array initializer of FMC peripheral base addresses */
  #define FMC_BASE_ADDRS                           { FMC0_BASE }
  /** Array initializer of FMC peripheral base pointers */
  #define FMC_BASE_PTRS                            { FMC0 }
#endif

/* FMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FMU0 base address */
  #define FMU0_BASE                                (0x50095000u)
  /** Peripheral FMU0 base address */
  #define FMU0_BASE_NS                             (0x40095000u)
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
  #define FMU0_BASE                                (0x40095000u)
  /** Peripheral FMU0 base pointer */
  #define FMU0                                     ((FMU_Type *)FMU0_BASE)
  /** Array initializer of FMU peripheral base addresses */
  #define FMU_BASE_ADDRS                           { FMU0_BASE }
  /** Array initializer of FMU peripheral base pointers */
  #define FMU_BASE_PTRS                            { FMU0 }
#endif

/* FMUTEST - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FMU0TEST base address */
  #define FMU0TEST_BASE                            (0x50096000u)
  /** Peripheral FMU0TEST base address */
  #define FMU0TEST_BASE_NS                         (0x40096000u)
  /** Peripheral FMU0TEST base pointer */
  #define FMU0TEST                                 ((FMUTEST_Type *)FMU0TEST_BASE)
  /** Peripheral FMU0TEST base pointer */
  #define FMU0TEST_NS                              ((FMUTEST_Type *)FMU0TEST_BASE_NS)
  /** Array initializer of FMUTEST peripheral base addresses */
  #define FMUTEST_BASE_ADDRS                       { FMU0TEST_BASE }
  /** Array initializer of FMUTEST peripheral base pointers */
  #define FMUTEST_BASE_PTRS                        { FMU0TEST }
  /** Array initializer of FMUTEST peripheral base addresses */
  #define FMUTEST_BASE_ADDRS_NS                    { FMU0TEST_BASE_NS }
  /** Array initializer of FMUTEST peripheral base pointers */
  #define FMUTEST_BASE_PTRS_NS                     { FMU0TEST_NS }
#else
  /** Peripheral FMU0TEST base address */
  #define FMU0TEST_BASE                            (0x40096000u)
  /** Peripheral FMU0TEST base pointer */
  #define FMU0TEST                                 ((FMUTEST_Type *)FMU0TEST_BASE)
  /** Array initializer of FMUTEST peripheral base addresses */
  #define FMUTEST_BASE_ADDRS                       { FMU0TEST_BASE }
  /** Array initializer of FMUTEST peripheral base pointers */
  #define FMUTEST_BASE_PTRS                        { FMU0TEST }
#endif

/* FREQME - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FREQME0 base address */
  #define FREQME0_BASE                             (0x50009000u)
  /** Peripheral FREQME0 base address */
  #define FREQME0_BASE_NS                          (0x40009000u)
  /** Peripheral FREQME0 base pointer */
  #define FREQME0                                  ((FREQME_Type *)FREQME0_BASE)
  /** Peripheral FREQME0 base pointer */
  #define FREQME0_NS                               ((FREQME_Type *)FREQME0_BASE_NS)
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS                        { FREQME0_BASE }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS                         { FREQME0 }
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS_NS                     { FREQME0_BASE_NS }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS_NS                      { FREQME0_NS }
#else
  /** Peripheral FREQME0 base address */
  #define FREQME0_BASE                             (0x40009000u)
  /** Peripheral FREQME0 base pointer */
  #define FREQME0                                  ((FREQME_Type *)FREQME0_BASE)
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS                        { FREQME0_BASE }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS                         { FREQME0 }
#endif

/* GLIKEY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GLIKEY0 base address */
  #define GLIKEY0_BASE                             (0x50091D00u)
  /** Peripheral GLIKEY0 base address */
  #define GLIKEY0_BASE_NS                          (0x40091D00u)
  /** Peripheral GLIKEY0 base pointer */
  #define GLIKEY0                                  ((GLIKEY_Type *)GLIKEY0_BASE)
  /** Peripheral GLIKEY0 base pointer */
  #define GLIKEY0_NS                               ((GLIKEY_Type *)GLIKEY0_BASE_NS)
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS                        { GLIKEY0_BASE }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS                         { GLIKEY0 }
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS_NS                     { GLIKEY0_BASE_NS }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS_NS                      { GLIKEY0_NS }
#else
  /** Peripheral GLIKEY0 base address */
  #define GLIKEY0_BASE                             (0x40091D00u)
  /** Peripheral GLIKEY0 base pointer */
  #define GLIKEY0                                  ((GLIKEY_Type *)GLIKEY0_BASE)
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS                        { GLIKEY0_BASE }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS                         { GLIKEY0 }
#endif
/** Interrupt vectors for the GLIKEY peripheral type */
#define GLIKEY_IRQS                              { GLIKEY0_IRQn }

/* GPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__GPIO0 base address */
  #define AON__GPIO0_BASE                          (0xB009F000u)
  /** Peripheral AON__GPIO0 base address */
  #define AON__GPIO0_BASE_NS                       (0xA009F000u)
  /** Peripheral AON__GPIO0 base pointer */
  #define AON__GPIO0                               ((GPIO_Type *)AON__GPIO0_BASE)
  /** Peripheral AON__GPIO0 base pointer */
  #define AON__GPIO0_NS                            ((GPIO_Type *)AON__GPIO0_BASE_NS)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE                               (0x50102000u)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE_NS                            (0x40102000u)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1_NS                                 ((GPIO_Type *)GPIO1_BASE_NS)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE                               (0x50103000u)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE_NS                            (0x40103000u)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2_NS                                 ((GPIO_Type *)GPIO2_BASE_NS)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE                               (0x50104000u)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE_NS                            (0x40104000u)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3_NS                                 ((GPIO_Type *)GPIO3_BASE_NS)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { AON__GPIO0_BASE, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { AON__GPIO0, GPIO1, GPIO2, GPIO3 }
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS_NS                       { AON__GPIO0_BASE_NS, GPIO1_BASE_NS, GPIO2_BASE_NS, GPIO3_BASE_NS }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS_NS                        { AON__GPIO0_NS, GPIO1_NS, GPIO2_NS, GPIO3_NS }
#else
  /** Peripheral AON__GPIO0 base address */
  #define AON__GPIO0_BASE                          (0xA009F000u)
  /** Peripheral AON__GPIO0 base pointer */
  #define AON__GPIO0                               ((GPIO_Type *)AON__GPIO0_BASE)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE                               (0x40102000u)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE                               (0x40103000u)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE                               (0x40104000u)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { AON__GPIO0_BASE, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { AON__GPIO0, GPIO1, GPIO2, GPIO3 }
#endif
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS                                { NotAvail_IRQn, GPIO10_IRQn, GPIO20_IRQn, GPIO30_IRQn }

/* INPUTMUX_AON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__INPUTMUX1 base address */
  #define AON__INPUTMUX1_BASE                      (0xB0091000u)
  /** Peripheral AON__INPUTMUX1 base address */
  #define AON__INPUTMUX1_BASE_NS                   (0xA0091000u)
  /** Peripheral AON__INPUTMUX1 base pointer */
  #define AON__INPUTMUX1                           ((INPUTMUX_AON_Type *)AON__INPUTMUX1_BASE)
  /** Peripheral AON__INPUTMUX1 base pointer */
  #define AON__INPUTMUX1_NS                        ((INPUTMUX_AON_Type *)AON__INPUTMUX1_BASE_NS)
  /** Array initializer of INPUTMUX_AON peripheral base addresses */
  #define INPUTMUX_AON_BASE_ADDRS                  { AON__INPUTMUX1_BASE }
  /** Array initializer of INPUTMUX_AON peripheral base pointers */
  #define INPUTMUX_AON_BASE_PTRS                   { AON__INPUTMUX1 }
  /** Array initializer of INPUTMUX_AON peripheral base addresses */
  #define INPUTMUX_AON_BASE_ADDRS_NS               { AON__INPUTMUX1_BASE_NS }
  /** Array initializer of INPUTMUX_AON peripheral base pointers */
  #define INPUTMUX_AON_BASE_PTRS_NS                { AON__INPUTMUX1_NS }
#else
  /** Peripheral AON__INPUTMUX1 base address */
  #define AON__INPUTMUX1_BASE                      (0xA0091000u)
  /** Peripheral AON__INPUTMUX1 base pointer */
  #define AON__INPUTMUX1                           ((INPUTMUX_AON_Type *)AON__INPUTMUX1_BASE)
  /** Array initializer of INPUTMUX_AON peripheral base addresses */
  #define INPUTMUX_AON_BASE_ADDRS                  { AON__INPUTMUX1_BASE }
  /** Array initializer of INPUTMUX_AON peripheral base pointers */
  #define INPUTMUX_AON_BASE_PTRS                   { AON__INPUTMUX1 }
#endif

/* INPUTMUX_MAIN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral INPUTMUX0 base address */
  #define INPUTMUX0_BASE                           (0x50001000u)
  /** Peripheral INPUTMUX0 base address */
  #define INPUTMUX0_BASE_NS                        (0x40001000u)
  /** Peripheral INPUTMUX0 base pointer */
  #define INPUTMUX0                                ((INPUTMUX_MAIN_Type *)INPUTMUX0_BASE)
  /** Peripheral INPUTMUX0 base pointer */
  #define INPUTMUX0_NS                             ((INPUTMUX_MAIN_Type *)INPUTMUX0_BASE_NS)
  /** Array initializer of INPUTMUX_MAIN peripheral base addresses */
  #define INPUTMUX_MAIN_BASE_ADDRS                 { INPUTMUX0_BASE }
  /** Array initializer of INPUTMUX_MAIN peripheral base pointers */
  #define INPUTMUX_MAIN_BASE_PTRS                  { INPUTMUX0 }
  /** Array initializer of INPUTMUX_MAIN peripheral base addresses */
  #define INPUTMUX_MAIN_BASE_ADDRS_NS              { INPUTMUX0_BASE_NS }
  /** Array initializer of INPUTMUX_MAIN peripheral base pointers */
  #define INPUTMUX_MAIN_BASE_PTRS_NS               { INPUTMUX0_NS }
#else
  /** Peripheral INPUTMUX0 base address */
  #define INPUTMUX0_BASE                           (0x40001000u)
  /** Peripheral INPUTMUX0 base pointer */
  #define INPUTMUX0                                ((INPUTMUX_MAIN_Type *)INPUTMUX0_BASE)
  /** Array initializer of INPUTMUX_MAIN peripheral base addresses */
  #define INPUTMUX_MAIN_BASE_ADDRS                 { INPUTMUX0_BASE }
  /** Array initializer of INPUTMUX_MAIN peripheral base pointers */
  #define INPUTMUX_MAIN_BASE_PTRS                  { INPUTMUX0 }
#endif

/* KPP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__KPP0 base address */
  #define AON__KPP0_BASE                           (0xB0095000u)
  /** Peripheral AON__KPP0 base address */
  #define AON__KPP0_BASE_NS                        (0xA0095000u)
  /** Peripheral AON__KPP0 base pointer */
  #define AON__KPP0                                ((KPP_Type *)AON__KPP0_BASE)
  /** Peripheral AON__KPP0 base pointer */
  #define AON__KPP0_NS                             ((KPP_Type *)AON__KPP0_BASE_NS)
  /** Array initializer of KPP peripheral base addresses */
  #define KPP_BASE_ADDRS                           { AON__KPP0_BASE }
  /** Array initializer of KPP peripheral base pointers */
  #define KPP_BASE_PTRS                            { AON__KPP0 }
  /** Array initializer of KPP peripheral base addresses */
  #define KPP_BASE_ADDRS_NS                        { AON__KPP0_BASE_NS }
  /** Array initializer of KPP peripheral base pointers */
  #define KPP_BASE_PTRS_NS                         { AON__KPP0_NS }
#else
  /** Peripheral AON__KPP0 base address */
  #define AON__KPP0_BASE                           (0xA0095000u)
  /** Peripheral AON__KPP0 base pointer */
  #define AON__KPP0                                ((KPP_Type *)AON__KPP0_BASE)
  /** Array initializer of KPP peripheral base addresses */
  #define KPP_BASE_ADDRS                           { AON__KPP0_BASE }
  /** Array initializer of KPP peripheral base pointers */
  #define KPP_BASE_PTRS                            { AON__KPP0 }
#endif
/** Interrupt vectors for the KPP peripheral type */
#define KPP_IRQS                                 { KPP_IRQn }

/* LPACMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__LPACMP base address */
  #define AON__LPACMP_BASE                         (0xB009B000u)
  /** Peripheral AON__LPACMP base address */
  #define AON__LPACMP_BASE_NS                      (0xA009B000u)
  /** Peripheral AON__LPACMP base pointer */
  #define AON__LPACMP                              ((LPACMP_Type *)AON__LPACMP_BASE)
  /** Peripheral AON__LPACMP base pointer */
  #define AON__LPACMP_NS                           ((LPACMP_Type *)AON__LPACMP_BASE_NS)
  /** Array initializer of LPACMP peripheral base addresses */
  #define LPACMP_BASE_ADDRS                        { AON__LPACMP_BASE }
  /** Array initializer of LPACMP peripheral base pointers */
  #define LPACMP_BASE_PTRS                         { AON__LPACMP }
  /** Array initializer of LPACMP peripheral base addresses */
  #define LPACMP_BASE_ADDRS_NS                     { AON__LPACMP_BASE_NS }
  /** Array initializer of LPACMP peripheral base pointers */
  #define LPACMP_BASE_PTRS_NS                      { AON__LPACMP_NS }
#else
  /** Peripheral AON__LPACMP base address */
  #define AON__LPACMP_BASE                         (0xA009B000u)
  /** Peripheral AON__LPACMP base pointer */
  #define AON__LPACMP                              ((LPACMP_Type *)AON__LPACMP_BASE)
  /** Array initializer of LPACMP peripheral base addresses */
  #define LPACMP_BASE_ADDRS                        { AON__LPACMP_BASE }
  /** Array initializer of LPACMP peripheral base pointers */
  #define LPACMP_BASE_PTRS                         { AON__LPACMP }
#endif

/* LPADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__LPADC0 base address */
  #define AON__LPADC0_BASE                         (0xB0092000u)
  /** Peripheral AON__LPADC0 base address */
  #define AON__LPADC0_BASE_NS                      (0xA0092000u)
  /** Peripheral AON__LPADC0 base pointer */
  #define AON__LPADC0                              ((LPADC_Type *)AON__LPADC0_BASE)
  /** Peripheral AON__LPADC0 base pointer */
  #define AON__LPADC0_NS                           ((LPADC_Type *)AON__LPADC0_BASE_NS)
  /** Array initializer of LPADC peripheral base addresses */
  #define LPADC_BASE_ADDRS                         { AON__LPADC0_BASE }
  /** Array initializer of LPADC peripheral base pointers */
  #define LPADC_BASE_PTRS                          { AON__LPADC0 }
  /** Array initializer of LPADC peripheral base addresses */
  #define LPADC_BASE_ADDRS_NS                      { AON__LPADC0_BASE_NS }
  /** Array initializer of LPADC peripheral base pointers */
  #define LPADC_BASE_PTRS_NS                       { AON__LPADC0_NS }
#else
  /** Peripheral AON__LPADC0 base address */
  #define AON__LPADC0_BASE                         (0xA0092000u)
  /** Peripheral AON__LPADC0 base pointer */
  #define AON__LPADC0                              ((LPADC_Type *)AON__LPADC0_BASE)
  /** Array initializer of LPADC peripheral base addresses */
  #define LPADC_BASE_ADDRS                         { AON__LPADC0_BASE }
  /** Array initializer of LPADC peripheral base pointers */
  #define LPADC_BASE_PTRS                          { AON__LPADC0 }
#endif

/* LPCMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__CMP0 base address */
  #define AON__CMP0_BASE                           (0xB0086000u)
  /** Peripheral AON__CMP0 base address */
  #define AON__CMP0_BASE_NS                        (0xA0086000u)
  /** Peripheral AON__CMP0 base pointer */
  #define AON__CMP0                                ((LPCMP_Type *)AON__CMP0_BASE)
  /** Peripheral AON__CMP0 base pointer */
  #define AON__CMP0_NS                             ((LPCMP_Type *)AON__CMP0_BASE_NS)
  /** Peripheral CMP0 base address */
  #define CMP0_BASE                                (0x500B1000u)
  /** Peripheral CMP0 base address */
  #define CMP0_BASE_NS                             (0x400B1000u)
  /** Peripheral CMP0 base pointer */
  #define CMP0                                     ((LPCMP_Type *)CMP0_BASE)
  /** Peripheral CMP0 base pointer */
  #define CMP0_NS                                  ((LPCMP_Type *)CMP0_BASE_NS)
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS                         { AON__CMP0_BASE, CMP0_BASE }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS                          { AON__CMP0, CMP0 }
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS_NS                      { AON__CMP0_BASE_NS, CMP0_BASE_NS }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS_NS                       { AON__CMP0_NS, CMP0_NS }
#else
  /** Peripheral AON__CMP0 base address */
  #define AON__CMP0_BASE                           (0xA0086000u)
  /** Peripheral AON__CMP0 base pointer */
  #define AON__CMP0                                ((LPCMP_Type *)AON__CMP0_BASE)
  /** Peripheral CMP0 base address */
  #define CMP0_BASE                                (0x400B1000u)
  /** Peripheral CMP0 base pointer */
  #define CMP0                                     ((LPCMP_Type *)CMP0_BASE)
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS                         { AON__CMP0_BASE, CMP0_BASE }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS                          { AON__CMP0, CMP0 }
#endif
/** Interrupt vectors for the LPCMP peripheral type */
#define LPCMP_IRQS                               { NotAvail_IRQn, CMP0_IRQn }

/* LPI2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE                              (0x5009A000u)
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE_NS                           (0x4009A000u)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0_NS                                ((LPI2C_Type *)LPI2C0_BASE_NS)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x5009B000u)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE_NS                           (0x4009B000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1_NS                                ((LPI2C_Type *)LPI2C1_BASE_NS)
  /** Peripheral AON__LPI2C0 base address */
  #define AON__LPI2C0_BASE                         (0xB0080000u)
  /** Peripheral AON__LPI2C0 base address */
  #define AON__LPI2C0_BASE_NS                      (0xA0080000u)
  /** Peripheral AON__LPI2C0 base pointer */
  #define AON__LPI2C0                              ((LPI2C_Type *)AON__LPI2C0_BASE)
  /** Peripheral AON__LPI2C0 base pointer */
  #define AON__LPI2C0_NS                           ((LPI2C_Type *)AON__LPI2C0_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, AON__LPI2C0_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, AON__LPI2C0 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { LPI2C0_BASE_NS, LPI2C1_BASE_NS, AON__LPI2C0_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { LPI2C0_NS, LPI2C1_NS, AON__LPI2C0_NS }
#else
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE                              (0x4009A000u)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x4009B000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral AON__LPI2C0 base address */
  #define AON__LPI2C0_BASE                         (0xA0080000u)
  /** Peripheral AON__LPI2C0 base pointer */
  #define AON__LPI2C0                              ((LPI2C_Type *)AON__LPI2C0_BASE)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, AON__LPI2C0_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, AON__LPI2C0 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn, NotAvail_IRQn }

/* LPSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE                              (0x5009C000u)
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE_NS                           (0x4009C000u)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0_NS                                ((LPSPI_Type *)LPSPI0_BASE_NS)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x5009D000u)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE_NS                           (0x4009D000u)
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
  #define LPSPI0_BASE                              (0x4009C000u)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x4009D000u)
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
  /** Peripheral AON__LPTMR0 base address */
  #define AON__LPTMR0_BASE                         (0xB0088000u)
  /** Peripheral AON__LPTMR0 base address */
  #define AON__LPTMR0_BASE_NS                      (0xA0088000u)
  /** Peripheral AON__LPTMR0 base pointer */
  #define AON__LPTMR0                              ((LPTMR_Type *)AON__LPTMR0_BASE)
  /** Peripheral AON__LPTMR0 base pointer */
  #define AON__LPTMR0_NS                           ((LPTMR_Type *)AON__LPTMR0_BASE_NS)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { AON__LPTMR0_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { AON__LPTMR0 }
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS_NS                      { AON__LPTMR0_BASE_NS }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS_NS                       { AON__LPTMR0_NS }
#else
  /** Peripheral AON__LPTMR0 base address */
  #define AON__LPTMR0_BASE                         (0xA0088000u)
  /** Peripheral AON__LPTMR0 base pointer */
  #define AON__LPTMR0                              ((LPTMR_Type *)AON__LPTMR0_BASE)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { AON__LPTMR0_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { AON__LPTMR0 }
#endif

/* LPUART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE                             (0x5009F000u)
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE_NS                          (0x4009F000u)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0_NS                               ((LPUART_Type *)LPUART0_BASE_NS)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x500A0000u)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE_NS                          (0x400A0000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1_NS                               ((LPUART_Type *)LPUART1_BASE_NS)
  /** Peripheral AON__LPUART0 base address */
  #define AON__LPUART0_BASE                        (0xB0082000u)
  /** Peripheral AON__LPUART0 base address */
  #define AON__LPUART0_BASE_NS                     (0xA0082000u)
  /** Peripheral AON__LPUART0 base pointer */
  #define AON__LPUART0                             ((LPUART_Type *)AON__LPUART0_BASE)
  /** Peripheral AON__LPUART0 base pointer */
  #define AON__LPUART0_NS                          ((LPUART_Type *)AON__LPUART0_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, AON__LPUART0_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART0, LPUART1, AON__LPUART0 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { LPUART0_BASE_NS, LPUART1_BASE_NS, AON__LPUART0_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { LPUART0_NS, LPUART1_NS, AON__LPUART0_NS }
#else
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE                             (0x4009F000u)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x400A0000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral AON__LPUART0 base address */
  #define AON__LPUART0_BASE                        (0xA0082000u)
  /** Peripheral AON__LPUART0 base pointer */
  #define AON__LPUART0                             ((LPUART_Type *)AON__LPUART0_BASE)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, AON__LPUART0_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART0, LPUART1, AON__LPUART0 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn, LPUART0_AON_IRQn }

/* MBC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MBC0 base address */
  #define MBC0_BASE                                (0x5008E000u)
  /** Peripheral MBC0 base address */
  #define MBC0_BASE_NS                             (0x4008E000u)
  /** Peripheral MBC0 base pointer */
  #define MBC0                                     ((MBC_Type *)MBC0_BASE)
  /** Peripheral MBC0 base pointer */
  #define MBC0_NS                                  ((MBC_Type *)MBC0_BASE_NS)
  /** Array initializer of MBC peripheral base addresses */
  #define MBC_BASE_ADDRS                           { MBC0_BASE }
  /** Array initializer of MBC peripheral base pointers */
  #define MBC_BASE_PTRS                            { MBC0 }
  /** Array initializer of MBC peripheral base addresses */
  #define MBC_BASE_ADDRS_NS                        { MBC0_BASE_NS }
  /** Array initializer of MBC peripheral base pointers */
  #define MBC_BASE_PTRS_NS                         { MBC0_NS }
#else
  /** Peripheral MBC0 base address */
  #define MBC0_BASE                                (0x4008E000u)
  /** Peripheral MBC0 base pointer */
  #define MBC0                                     ((MBC_Type *)MBC0_BASE)
  /** Array initializer of MBC peripheral base addresses */
  #define MBC_BASE_ADDRS                           { MBC0_BASE }
  /** Array initializer of MBC peripheral base pointers */
  #define MBC_BASE_PTRS                            { MBC0 }
#endif

/* MRCC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MRCC base address */
  #define MRCC_BASE                                (0x50091000u)
  /** Peripheral MRCC base address */
  #define MRCC_BASE_NS                             (0x40091000u)
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
  #define MRCC_BASE                                (0x40091000u)
  /** Peripheral MRCC base pointer */
  #define MRCC                                     ((MRCC_Type *)MRCC_BASE)
  /** Array initializer of MRCC peripheral base addresses */
  #define MRCC_BASE_ADDRS                          { MRCC_BASE }
  /** Array initializer of MRCC peripheral base pointers */
  #define MRCC_BASE_PTRS                           { MRCC }
#endif

/* MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MUA base address */
  #define MUA_BASE                                 (0x500C4000u)
  /** Peripheral MUA base address */
  #define MUA_BASE_NS                              (0x400C4000u)
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
  #define MUA_BASE                                 (0x400C4000u)
  /** Peripheral MUA base pointer */
  #define MUA                                      ((MU_Type *)MUA_BASE)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MUA }
#endif

/* OSTIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OSTIMER0 base address */
  #define OSTIMER0_BASE                            (0x500AD000u)
  /** Peripheral OSTIMER0 base address */
  #define OSTIMER0_BASE_NS                         (0x400AD000u)
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
  #define OSTIMER0_BASE                            (0x400AD000u)
  /** Peripheral OSTIMER0 base pointer */
  #define OSTIMER0                                 ((OSTIMER_Type *)OSTIMER0_BASE)
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS                       { OSTIMER0_BASE }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS                        { OSTIMER0 }
#endif
/** Interrupt vectors for the OSTIMER peripheral type */
#define OSTIMER_IRQS                             { OS_EVENT_IRQn }

/* PKC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PKC0__PKC base address */
  #define PKC0__PKC_BASE                           (0x500D0000u)
  /** Peripheral PKC0__PKC base address */
  #define PKC0__PKC_BASE_NS                        (0x400D0000u)
  /** Peripheral PKC0__PKC base pointer */
  #define PKC0__PKC                                ((PKC_Type *)PKC0__PKC_BASE)
  /** Peripheral PKC0__PKC base pointer */
  #define PKC0__PKC_NS                             ((PKC_Type *)PKC0__PKC_BASE_NS)
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS                           { PKC0__PKC_BASE }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS                            { PKC0__PKC }
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS_NS                        { PKC0__PKC_BASE_NS }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS_NS                         { PKC0__PKC_NS }
#else
  /** Peripheral PKC0__PKC base address */
  #define PKC0__PKC_BASE                           (0x400D0000u)
  /** Peripheral PKC0__PKC base pointer */
  #define PKC0__PKC                                ((PKC_Type *)PKC0__PKC_BASE)
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS                           { PKC0__PKC_BASE }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS                            { PKC0__PKC }
#endif

/* PMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__PMU base address */
  #define AON__PMU_BASE                            (0xB0098000u)
  /** Peripheral AON__PMU base address */
  #define AON__PMU_BASE_NS                         (0xA0098000u)
  /** Peripheral AON__PMU base pointer */
  #define AON__PMU                                 ((PMU_Type *)AON__PMU_BASE)
  /** Peripheral AON__PMU base pointer */
  #define AON__PMU_NS                              ((PMU_Type *)AON__PMU_BASE_NS)
  /** Array initializer of PMU peripheral base addresses */
  #define PMU_BASE_ADDRS                           { AON__PMU_BASE }
  /** Array initializer of PMU peripheral base pointers */
  #define PMU_BASE_PTRS                            { AON__PMU }
  /** Array initializer of PMU peripheral base addresses */
  #define PMU_BASE_ADDRS_NS                        { AON__PMU_BASE_NS }
  /** Array initializer of PMU peripheral base pointers */
  #define PMU_BASE_PTRS_NS                         { AON__PMU_NS }
#else
  /** Peripheral AON__PMU base address */
  #define AON__PMU_BASE                            (0xA0098000u)
  /** Peripheral AON__PMU base pointer */
  #define AON__PMU                                 ((PMU_Type *)AON__PMU_BASE)
  /** Array initializer of PMU peripheral base addresses */
  #define PMU_BASE_ADDRS                           { AON__PMU_BASE }
  /** Array initializer of PMU peripheral base pointers */
  #define PMU_BASE_PTRS                            { AON__PMU }
#endif

/* PORT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__PORT0 base address */
  #define AON__PORT0_BASE                          (0xB0085000u)
  /** Peripheral AON__PORT0 base address */
  #define AON__PORT0_BASE_NS                       (0xA0085000u)
  /** Peripheral AON__PORT0 base pointer */
  #define AON__PORT0                               ((PORT_Type *)AON__PORT0_BASE)
  /** Peripheral AON__PORT0 base pointer */
  #define AON__PORT0_NS                            ((PORT_Type *)AON__PORT0_BASE_NS)
  /** Peripheral PORT1 base address */
  #define PORT1_BASE                               (0x500BC000u)
  /** Peripheral PORT1 base address */
  #define PORT1_BASE_NS                            (0x400BC000u)
  /** Peripheral PORT1 base pointer */
  #define PORT1                                    ((PORT_Type *)PORT1_BASE)
  /** Peripheral PORT1 base pointer */
  #define PORT1_NS                                 ((PORT_Type *)PORT1_BASE_NS)
  /** Peripheral PORT2 base address */
  #define PORT2_BASE                               (0x500BD000u)
  /** Peripheral PORT2 base address */
  #define PORT2_BASE_NS                            (0x400BD000u)
  /** Peripheral PORT2 base pointer */
  #define PORT2                                    ((PORT_Type *)PORT2_BASE)
  /** Peripheral PORT2 base pointer */
  #define PORT2_NS                                 ((PORT_Type *)PORT2_BASE_NS)
  /** Peripheral PORT3 base address */
  #define PORT3_BASE                               (0x500BE000u)
  /** Peripheral PORT3 base address */
  #define PORT3_BASE_NS                            (0x400BE000u)
  /** Peripheral PORT3 base pointer */
  #define PORT3                                    ((PORT_Type *)PORT3_BASE)
  /** Peripheral PORT3 base pointer */
  #define PORT3_NS                                 ((PORT_Type *)PORT3_BASE_NS)
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS                          { AON__PORT0_BASE, PORT1_BASE, PORT2_BASE, PORT3_BASE }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS                           { AON__PORT0, PORT1, PORT2, PORT3 }
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS_NS                       { AON__PORT0_BASE_NS, PORT1_BASE_NS, PORT2_BASE_NS, PORT3_BASE_NS }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS_NS                        { AON__PORT0_NS, PORT1_NS, PORT2_NS, PORT3_NS }
#else
  /** Peripheral AON__PORT0 base address */
  #define AON__PORT0_BASE                          (0xA0085000u)
  /** Peripheral AON__PORT0 base pointer */
  #define AON__PORT0                               ((PORT_Type *)AON__PORT0_BASE)
  /** Peripheral PORT1 base address */
  #define PORT1_BASE                               (0x400BC000u)
  /** Peripheral PORT1 base pointer */
  #define PORT1                                    ((PORT_Type *)PORT1_BASE)
  /** Peripheral PORT2 base address */
  #define PORT2_BASE                               (0x400BD000u)
  /** Peripheral PORT2 base pointer */
  #define PORT2                                    ((PORT_Type *)PORT2_BASE)
  /** Peripheral PORT3 base address */
  #define PORT3_BASE                               (0x400BE000u)
  /** Peripheral PORT3 base pointer */
  #define PORT3                                    ((PORT_Type *)PORT3_BASE)
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS                          { AON__PORT0_BASE, PORT1_BASE, PORT2_BASE, PORT3_BASE }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS                           { AON__PORT0, PORT1, PORT2, PORT3 }
#endif

/* RTC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__RTC_AON base address */
  #define AON__RTC_AON_BASE                        (0xB009A000u)
  /** Peripheral AON__RTC_AON base address */
  #define AON__RTC_AON_BASE_NS                     (0xA009A000u)
  /** Peripheral AON__RTC_AON base pointer */
  #define AON__RTC_AON                             ((RTC_Type *)AON__RTC_AON_BASE)
  /** Peripheral AON__RTC_AON base pointer */
  #define AON__RTC_AON_NS                          ((RTC_Type *)AON__RTC_AON_BASE_NS)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { AON__RTC_AON_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { AON__RTC_AON }
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS_NS                        { AON__RTC_AON_BASE_NS }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS_NS                         { AON__RTC_AON_NS }
#else
  /** Peripheral AON__RTC_AON base address */
  #define AON__RTC_AON_BASE                        (0xA009A000u)
  /** Peripheral AON__RTC_AON base pointer */
  #define AON__RTC_AON                             ((RTC_Type *)AON__RTC_AON_BASE)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { AON__RTC_AON_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { AON__RTC_AON }
#endif

/* SCG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SCG0 base address */
  #define SCG0_BASE                                (0x5008F000u)
  /** Peripheral SCG0 base address */
  #define SCG0_BASE_NS                             (0x4008F000u)
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
  #define SCG0_BASE                                (0x4008F000u)
  /** Peripheral SCG0 base pointer */
  #define SCG0                                     ((SCG_Type *)SCG0_BASE)
  /** Array initializer of SCG peripheral base addresses */
  #define SCG_BASE_ADDRS                           { SCG0_BASE }
  /** Array initializer of SCG peripheral base pointers */
  #define SCG_BASE_PTRS                            { SCG0 }
#endif

/* SGI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SGI0 base address */
  #define SGI0_BASE                                (0x500D1000u)
  /** Peripheral SGI0 base address */
  #define SGI0_BASE_NS                             (0x400D1000u)
  /** Peripheral SGI0 base pointer */
  #define SGI0                                     ((SGI_Type *)SGI0_BASE)
  /** Peripheral SGI0 base pointer */
  #define SGI0_NS                                  ((SGI_Type *)SGI0_BASE_NS)
  /** Array initializer of SGI peripheral base addresses */
  #define SGI_BASE_ADDRS                           { SGI0_BASE }
  /** Array initializer of SGI peripheral base pointers */
  #define SGI_BASE_PTRS                            { SGI0 }
  /** Array initializer of SGI peripheral base addresses */
  #define SGI_BASE_ADDRS_NS                        { SGI0_BASE_NS }
  /** Array initializer of SGI peripheral base pointers */
  #define SGI_BASE_PTRS_NS                         { SGI0_NS }
#else
  /** Peripheral SGI0 base address */
  #define SGI0_BASE                                (0x400D1000u)
  /** Peripheral SGI0 base pointer */
  #define SGI0                                     ((SGI_Type *)SGI0_BASE)
  /** Array initializer of SGI peripheral base addresses */
  #define SGI_BASE_ADDRS                           { SGI0_BASE }
  /** Array initializer of SGI peripheral base pointers */
  #define SGI_BASE_PTRS                            { SGI0 }
#endif

/* SGLCD_CONTROL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__SGLCD0_AON base address */
  #define AON__SGLCD0_AON_BASE                     (0xB0094000u)
  /** Peripheral AON__SGLCD0_AON base address */
  #define AON__SGLCD0_AON_BASE_NS                  (0xA0094000u)
  /** Peripheral AON__SGLCD0_AON base pointer */
  #define AON__SGLCD0_AON                          ((SGLCD_CONTROL_Type *)AON__SGLCD0_AON_BASE)
  /** Peripheral AON__SGLCD0_AON base pointer */
  #define AON__SGLCD0_AON_NS                       ((SGLCD_CONTROL_Type *)AON__SGLCD0_AON_BASE_NS)
  /** Array initializer of SGLCD_CONTROL peripheral base addresses */
  #define SGLCD_CONTROL_BASE_ADDRS                 { AON__SGLCD0_AON_BASE }
  /** Array initializer of SGLCD_CONTROL peripheral base pointers */
  #define SGLCD_CONTROL_BASE_PTRS                  { AON__SGLCD0_AON }
  /** Array initializer of SGLCD_CONTROL peripheral base addresses */
  #define SGLCD_CONTROL_BASE_ADDRS_NS              { AON__SGLCD0_AON_BASE_NS }
  /** Array initializer of SGLCD_CONTROL peripheral base pointers */
  #define SGLCD_CONTROL_BASE_PTRS_NS               { AON__SGLCD0_AON_NS }
#else
  /** Peripheral AON__SGLCD0_AON base address */
  #define AON__SGLCD0_AON_BASE                     (0xA0094000u)
  /** Peripheral AON__SGLCD0_AON base pointer */
  #define AON__SGLCD0_AON                          ((SGLCD_CONTROL_Type *)AON__SGLCD0_AON_BASE)
  /** Array initializer of SGLCD_CONTROL peripheral base addresses */
  #define SGLCD_CONTROL_BASE_ADDRS                 { AON__SGLCD0_AON_BASE }
  /** Array initializer of SGLCD_CONTROL peripheral base pointers */
  #define SGLCD_CONTROL_BASE_PTRS                  { AON__SGLCD0_AON }
#endif

/* SGLCD_FAULT_DETECT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SGLCD0_MAIN base address */
  #define SGLCD0_MAIN_BASE                         (0x500C7000u)
  /** Peripheral SGLCD0_MAIN base address */
  #define SGLCD0_MAIN_BASE_NS                      (0x400C7000u)
  /** Peripheral SGLCD0_MAIN base pointer */
  #define SGLCD0_MAIN                              ((SGLCD_FAULT_DETECT_Type *)SGLCD0_MAIN_BASE)
  /** Peripheral SGLCD0_MAIN base pointer */
  #define SGLCD0_MAIN_NS                           ((SGLCD_FAULT_DETECT_Type *)SGLCD0_MAIN_BASE_NS)
  /** Array initializer of SGLCD_FAULT_DETECT peripheral base addresses */
  #define SGLCD_FAULT_DETECT_BASE_ADDRS            { SGLCD0_MAIN_BASE }
  /** Array initializer of SGLCD_FAULT_DETECT peripheral base pointers */
  #define SGLCD_FAULT_DETECT_BASE_PTRS             { SGLCD0_MAIN }
  /** Array initializer of SGLCD_FAULT_DETECT peripheral base addresses */
  #define SGLCD_FAULT_DETECT_BASE_ADDRS_NS         { SGLCD0_MAIN_BASE_NS }
  /** Array initializer of SGLCD_FAULT_DETECT peripheral base pointers */
  #define SGLCD_FAULT_DETECT_BASE_PTRS_NS          { SGLCD0_MAIN_NS }
#else
  /** Peripheral SGLCD0_MAIN base address */
  #define SGLCD0_MAIN_BASE                         (0x400C7000u)
  /** Peripheral SGLCD0_MAIN base pointer */
  #define SGLCD0_MAIN                              ((SGLCD_FAULT_DETECT_Type *)SGLCD0_MAIN_BASE)
  /** Array initializer of SGLCD_FAULT_DETECT peripheral base addresses */
  #define SGLCD_FAULT_DETECT_BASE_ADDRS            { SGLCD0_MAIN_BASE }
  /** Array initializer of SGLCD_FAULT_DETECT peripheral base pointers */
  #define SGLCD_FAULT_DETECT_BASE_PTRS             { SGLCD0_MAIN }
#endif

/* SMM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__SMM base address */
  #define AON__SMM_BASE                            (0xB009A000u)
  /** Peripheral AON__SMM base address */
  #define AON__SMM_BASE_NS                         (0xA009A000u)
  /** Peripheral AON__SMM base pointer */
  #define AON__SMM                                 ((SMM_Type *)AON__SMM_BASE)
  /** Peripheral AON__SMM base pointer */
  #define AON__SMM_NS                              ((SMM_Type *)AON__SMM_BASE_NS)
  /** Array initializer of SMM peripheral base addresses */
  #define SMM_BASE_ADDRS                           { AON__SMM_BASE }
  /** Array initializer of SMM peripheral base pointers */
  #define SMM_BASE_PTRS                            { AON__SMM }
  /** Array initializer of SMM peripheral base addresses */
  #define SMM_BASE_ADDRS_NS                        { AON__SMM_BASE_NS }
  /** Array initializer of SMM peripheral base pointers */
  #define SMM_BASE_PTRS_NS                         { AON__SMM_NS }
#else
  /** Peripheral AON__SMM base address */
  #define AON__SMM_BASE                            (0xA009A000u)
  /** Peripheral AON__SMM base pointer */
  #define AON__SMM                                 ((SMM_Type *)AON__SMM_BASE)
  /** Array initializer of SMM peripheral base addresses */
  #define SMM_BASE_ADDRS                           { AON__SMM_BASE }
  /** Array initializer of SMM peripheral base pointers */
  #define SMM_BASE_PTRS                            { AON__SMM }
#endif

/* SYSCON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON base address */
  #define SYSCON_BASE                              (0x50091000u)
  /** Peripheral SYSCON base address */
  #define SYSCON_BASE_NS                           (0x40091000u)
  /** Peripheral SYSCON base pointer */
  #define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
  /** Peripheral SYSCON base pointer */
  #define SYSCON_NS                                ((SYSCON_Type *)SYSCON_BASE_NS)
  /** Array initializer of SYSCON peripheral base addresses */
  #define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
  /** Array initializer of SYSCON peripheral base pointers */
  #define SYSCON_BASE_PTRS                         { SYSCON }
  /** Array initializer of SYSCON peripheral base addresses */
  #define SYSCON_BASE_ADDRS_NS                     { SYSCON_BASE_NS }
  /** Array initializer of SYSCON peripheral base pointers */
  #define SYSCON_BASE_PTRS_NS                      { SYSCON_NS }
#else
  /** Peripheral SYSCON base address */
  #define SYSCON_BASE                              (0x40091000u)
  /** Peripheral SYSCON base pointer */
  #define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
  /** Array initializer of SYSCON peripheral base addresses */
  #define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
  /** Array initializer of SYSCON peripheral base pointers */
  #define SYSCON_BASE_PTRS                         { SYSCON }
#endif

/* SYSCON_AON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__SYSCON_AON base address */
  #define AON__SYSCON_AON_BASE                     (0xB0090000u)
  /** Peripheral AON__SYSCON_AON base address */
  #define AON__SYSCON_AON_BASE_NS                  (0xA0090000u)
  /** Peripheral AON__SYSCON_AON base pointer */
  #define AON__SYSCON_AON                          ((SYSCON_AON_Type *)AON__SYSCON_AON_BASE)
  /** Peripheral AON__SYSCON_AON base pointer */
  #define AON__SYSCON_AON_NS                       ((SYSCON_AON_Type *)AON__SYSCON_AON_BASE_NS)
  /** Array initializer of SYSCON_AON peripheral base addresses */
  #define SYSCON_AON_BASE_ADDRS                    { AON__SYSCON_AON_BASE }
  /** Array initializer of SYSCON_AON peripheral base pointers */
  #define SYSCON_AON_BASE_PTRS                     { AON__SYSCON_AON }
  /** Array initializer of SYSCON_AON peripheral base addresses */
  #define SYSCON_AON_BASE_ADDRS_NS                 { AON__SYSCON_AON_BASE_NS }
  /** Array initializer of SYSCON_AON peripheral base pointers */
  #define SYSCON_AON_BASE_PTRS_NS                  { AON__SYSCON_AON_NS }
#else
  /** Peripheral AON__SYSCON_AON base address */
  #define AON__SYSCON_AON_BASE                     (0xA0090000u)
  /** Peripheral AON__SYSCON_AON base pointer */
  #define AON__SYSCON_AON                          ((SYSCON_AON_Type *)AON__SYSCON_AON_BASE)
  /** Array initializer of SYSCON_AON peripheral base addresses */
  #define SYSCON_AON_BASE_ADDRS                    { AON__SYSCON_AON_BASE }
  /** Array initializer of SYSCON_AON peripheral base pointers */
  #define SYSCON_AON_BASE_PTRS                     { AON__SYSCON_AON }
#endif

/* TMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__TMR0 base address */
  #define AON__TMR0_BASE                           (0xB008E000u)
  /** Peripheral AON__TMR0 base address */
  #define AON__TMR0_BASE_NS                        (0xA008E000u)
  /** Peripheral AON__TMR0 base pointer */
  #define AON__TMR0                                ((TMR_Type *)AON__TMR0_BASE)
  /** Peripheral AON__TMR0 base pointer */
  #define AON__TMR0_NS                             ((TMR_Type *)AON__TMR0_BASE_NS)
  /** Peripheral AON__TMR1 base address */
  #define AON__TMR1_BASE                           (0xB008F000u)
  /** Peripheral AON__TMR1 base address */
  #define AON__TMR1_BASE_NS                        (0xA008F000u)
  /** Peripheral AON__TMR1 base pointer */
  #define AON__TMR1                                ((TMR_Type *)AON__TMR1_BASE)
  /** Peripheral AON__TMR1 base pointer */
  #define AON__TMR1_NS                             ((TMR_Type *)AON__TMR1_BASE_NS)
  /** Array initializer of TMR peripheral base addresses */
  #define TMR_BASE_ADDRS                           { AON__TMR0_BASE, AON__TMR1_BASE }
  /** Array initializer of TMR peripheral base pointers */
  #define TMR_BASE_PTRS                            { AON__TMR0, AON__TMR1 }
  /** Array initializer of TMR peripheral base addresses */
  #define TMR_BASE_ADDRS_NS                        { AON__TMR0_BASE_NS, AON__TMR1_BASE_NS }
  /** Array initializer of TMR peripheral base pointers */
  #define TMR_BASE_PTRS_NS                         { AON__TMR0_NS, AON__TMR1_NS }
#else
  /** Peripheral AON__TMR0 base address */
  #define AON__TMR0_BASE                           (0xA008E000u)
  /** Peripheral AON__TMR0 base pointer */
  #define AON__TMR0                                ((TMR_Type *)AON__TMR0_BASE)
  /** Peripheral AON__TMR1 base address */
  #define AON__TMR1_BASE                           (0xA008F000u)
  /** Peripheral AON__TMR1 base pointer */
  #define AON__TMR1                                ((TMR_Type *)AON__TMR1_BASE)
  /** Array initializer of TMR peripheral base addresses */
  #define TMR_BASE_ADDRS                           { AON__TMR0_BASE, AON__TMR1_BASE }
  /** Array initializer of TMR peripheral base pointers */
  #define TMR_BASE_PTRS                            { AON__TMR0, AON__TMR1 }
#endif

/* TRNG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRNG0 base address */
  #define TRNG0_BASE                               (0x500D2000u)
  /** Peripheral TRNG0 base address */
  #define TRNG0_BASE_NS                            (0x400D2000u)
  /** Peripheral TRNG0 base pointer */
  #define TRNG0                                    ((TRNG_Type *)TRNG0_BASE)
  /** Peripheral TRNG0 base pointer */
  #define TRNG0_NS                                 ((TRNG_Type *)TRNG0_BASE_NS)
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS                          { TRNG0_BASE }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS                           { TRNG0 }
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS_NS                       { TRNG0_BASE_NS }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS_NS                        { TRNG0_NS }
#else
  /** Peripheral TRNG0 base address */
  #define TRNG0_BASE                               (0x400D2000u)
  /** Peripheral TRNG0 base pointer */
  #define TRNG0                                    ((TRNG_Type *)TRNG0_BASE)
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS                          { TRNG0_BASE }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS                           { TRNG0 }
#endif

/* UDF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral UDF0 base address */
  #define UDF0_BASE                                (0x500D3000u)
  /** Peripheral UDF0 base address */
  #define UDF0_BASE_NS                             (0x400D3000u)
  /** Peripheral UDF0 base pointer */
  #define UDF0                                     ((UDF_Type *)UDF0_BASE)
  /** Peripheral UDF0 base pointer */
  #define UDF0_NS                                  ((UDF_Type *)UDF0_BASE_NS)
  /** Array initializer of UDF peripheral base addresses */
  #define UDF_BASE_ADDRS                           { UDF0_BASE }
  /** Array initializer of UDF peripheral base pointers */
  #define UDF_BASE_PTRS                            { UDF0 }
  /** Array initializer of UDF peripheral base addresses */
  #define UDF_BASE_ADDRS_NS                        { UDF0_BASE_NS }
  /** Array initializer of UDF peripheral base pointers */
  #define UDF_BASE_PTRS_NS                         { UDF0_NS }
#else
  /** Peripheral UDF0 base address */
  #define UDF0_BASE                                (0x400D3000u)
  /** Peripheral UDF0 base pointer */
  #define UDF0                                     ((UDF_Type *)UDF0_BASE)
  /** Array initializer of UDF peripheral base addresses */
  #define UDF_BASE_ADDRS                           { UDF0_BASE }
  /** Array initializer of UDF peripheral base pointers */
  #define UDF_BASE_PTRS                            { UDF0 }
#endif

/* UTICK - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral UTICK0 base address */
  #define UTICK0_BASE                              (0x5000B000u)
  /** Peripheral UTICK0 base address */
  #define UTICK0_BASE_NS                           (0x4000B000u)
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
  #define UTICK0_BASE                              (0x4000B000u)
  /** Peripheral UTICK0 base pointer */
  #define UTICK0                                   ((UTICK_Type *)UTICK0_BASE)
  /** Array initializer of UTICK peripheral base addresses */
  #define UTICK_BASE_ADDRS                         { UTICK0_BASE }
  /** Array initializer of UTICK peripheral base pointers */
  #define UTICK_BASE_PTRS                          { UTICK0 }
#endif
/** Interrupt vectors for the UTICK peripheral type */
#define UTICK_IRQS                               { UTICK0_IRQn }

/* WUU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WUU0 base address */
  #define WUU0_BASE                                (0x50092000u)
  /** Peripheral WUU0 base address */
  #define WUU0_BASE_NS                             (0x40092000u)
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
  #define WUU0_BASE                                (0x40092000u)
  /** Peripheral WUU0 base pointer */
  #define WUU0                                     ((WUU_Type *)WUU0_BASE)
  /** Array initializer of WUU peripheral base addresses */
  #define WUU_BASE_ADDRS                           { WUU0_BASE }
  /** Array initializer of WUU peripheral base pointers */
  #define WUU_BASE_PTRS                            { WUU0 }
#endif
/** Interrupt vectors for the WUU peripheral type */
#define WUU_IRQS                                 { WUU0_IRQn }

/* WWDT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WWDT0 base address */
  #define WWDT0_BASE                               (0x5000C000u)
  /** Peripheral WWDT0 base address */
  #define WWDT0_BASE_NS                            (0x4000C000u)
  /** Peripheral WWDT0 base pointer */
  #define WWDT0                                    ((WWDT_Type *)WWDT0_BASE)
  /** Peripheral WWDT0 base pointer */
  #define WWDT0_NS                                 ((WWDT_Type *)WWDT0_BASE_NS)
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS                          { WWDT0_BASE }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS                           { WWDT0 }
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS_NS                       { WWDT0_BASE_NS }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS_NS                        { WWDT0_NS }
#else
  /** Peripheral WWDT0 base address */
  #define WWDT0_BASE                               (0x4000C000u)
  /** Peripheral WWDT0 base pointer */
  #define WWDT0                                    ((WWDT_Type *)WWDT0_BASE)
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS                          { WWDT0_BASE }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS                           { WWDT0 }
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


#endif  /* MCXL253_CM33_COMMON_H_ */
