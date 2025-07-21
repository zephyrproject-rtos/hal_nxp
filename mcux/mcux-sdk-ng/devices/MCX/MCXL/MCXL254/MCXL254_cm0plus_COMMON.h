/*
** ###################################################################
**     Processors:          MCXL254VDF_cm0plus
**                          MCXL254VLL_cm0plus
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
**         CMSIS Peripheral Access Layer for MCXL254_cm0plus
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
 * @file MCXL254_cm0plus_COMMON.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for MCXL254_cm0plus
 *
 * CMSIS Peripheral Access Layer for MCXL254_cm0plus
 */

#if !defined(MCXL254_CM0PLUS_COMMON_H_)
#define MCXL254_CM0PLUS_COMMON_H_                /**< Symbol preventing repeated inclusion */

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
  LPI2C0_AON_IRQn              = 1,                /**< Low-Power Inter Integrated Circuit interrupt */
  LPUART0_AON_IRQn             = 3,                /**< Low-Power Universal Asynchronous Receive/Transmit interrupt */
  GPIO00_AON_IRQn              = 5,                /**< General Purpose Input/Output interrupt 0 */
  MU_B_TX_IRQn                 = 7,                /**< Ored tx interrupt to MUB */
  MU_B_RX_IRQn                 = 8,                /**< Ored rx interrupt to MUB */
  MU_B_INT_IRQn                = 9,                /**< ORed general purpose interrupt request to MUB */
  SMM_IRQn                     = 10,               /**< SMM IRQ */
  SNS_IRQn                     = 11,               /**< SNS - first fail test finish */
  LPCMP_IRQn                   = 12,               /**< Comparator */
  RTC_ALARM0_IRQn              = 13,               /**< RTC alarm 0 */
  RTC_ALARM1_IRQn              = 14,               /**< RTC alarm 1 */
  RTC_ALARM2_IRQn              = 15,               /**< RTC alarm 2 */
  RTC_WDT_IRQn                 = 16,               /**< RTC watchdog */
  RTC_XTAL_IRQn                = 17,               /**< RTC XTAL Fail */
  SMM_EXT_IRQn                 = 18,               /**< External interrupt */
  CGU_IRQn                     = 19,               /**< CGU IRQ */
  PMU_IRQn                     = 20,               /**< PMU IRQ */
  KPP_IRQn                     = 21,               /**< Keypad Interrupt */
  LPADC_AON_IRQn               = 22,               /**< Analog-to-Digital Converter interrupt */
  SGLCD_AON_IRQn               = 23,               /**< SLCD frame start interrupt */
  TMR0_AON_IRQn                = 24,               /**< ORed QTMR Interrupts */
  TMR1_AON_IRQn                = 25,               /**< ORed QTMR Interrupts */
  LCSENSE_IRQn                 = 27,               /**< LCSense Fault/Tamper Interrupt */
  LPTMR_AON_IRQn               = 28,               /**< Low Power Timer 0 interrupt */
  CMP0_AON_IRQn                = 30,               /**< Comparator interrupt */
  ADVC_IRQn                    = 31                /**< ADVC_2.0 Controller Interrupt */
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
#define __NVIC_PRIO_BITS               3         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */

#include "core_cm0plus.h"              /* Core Peripheral Access Layer */
#include "system_MCXL254_cm0plus.h"    /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MCXL254_cm0plus_SERIES
#define MCXL254_cm0plus_SERIES
#endif
/* CPU specific feature definitions */
#include "MCXL254_cm0plus_features.h"

/* CGU - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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

/* GPIO - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
  /** Peripheral AON__GPIO0 base address */
  #define AON__GPIO0_BASE                          (0xB009F000u)
  /** Peripheral AON__GPIO0 base address */
  #define AON__GPIO0_BASE_NS                       (0xA009F000u)
  /** Peripheral AON__GPIO0 base pointer */
  #define AON__GPIO0                               ((GPIO_Type *)AON__GPIO0_BASE)
  /** Peripheral AON__GPIO0 base pointer */
  #define AON__GPIO0_NS                            ((GPIO_Type *)AON__GPIO0_BASE_NS)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { AON__GPIO0_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { AON__GPIO0 }
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS_NS                       { AON__GPIO0_BASE_NS }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS_NS                        { AON__GPIO0_NS }
#else
  /** Peripheral AON__GPIO0 base address */
  #define AON__GPIO0_BASE                          (0xA009F000u)
  /** Peripheral AON__GPIO0 base pointer */
  #define AON__GPIO0                               ((GPIO_Type *)AON__GPIO0_BASE)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { AON__GPIO0_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { AON__GPIO0 }
#endif
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS                                { GPIO00_AON_IRQn }

/* INPUTMUX_AON - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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

/* KPP - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
  /** Peripheral AON__CMP0 base address */
  #define AON__CMP0_BASE                           (0xB0086000u)
  /** Peripheral AON__CMP0 base address */
  #define AON__CMP0_BASE_NS                        (0xA0086000u)
  /** Peripheral AON__CMP0 base pointer */
  #define AON__CMP0                                ((LPCMP_Type *)AON__CMP0_BASE)
  /** Peripheral AON__CMP0 base pointer */
  #define AON__CMP0_NS                             ((LPCMP_Type *)AON__CMP0_BASE_NS)
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS                         { AON__CMP0_BASE }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS                          { AON__CMP0 }
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS_NS                      { AON__CMP0_BASE_NS }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS_NS                       { AON__CMP0_NS }
#else
  /** Peripheral AON__CMP0 base address */
  #define AON__CMP0_BASE                           (0xA0086000u)
  /** Peripheral AON__CMP0 base pointer */
  #define AON__CMP0                                ((LPCMP_Type *)AON__CMP0_BASE)
  /** Array initializer of LPCMP peripheral base addresses */
  #define LPCMP_BASE_ADDRS                         { AON__CMP0_BASE }
  /** Array initializer of LPCMP peripheral base pointers */
  #define LPCMP_BASE_PTRS                          { AON__CMP0 }
#endif

/* LPI2C - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
  /** Peripheral AON__LPI2C0 base address */
  #define AON__LPI2C0_BASE                         (0xB0080000u)
  /** Peripheral AON__LPI2C0 base address */
  #define AON__LPI2C0_BASE_NS                      (0xA0080000u)
  /** Peripheral AON__LPI2C0 base pointer */
  #define AON__LPI2C0                              ((LPI2C_Type *)AON__LPI2C0_BASE)
  /** Peripheral AON__LPI2C0 base pointer */
  #define AON__LPI2C0_NS                           ((LPI2C_Type *)AON__LPI2C0_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { 0u, 0u, AON__LPI2C0_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, (LPI2C_Type *)0u, AON__LPI2C0 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { 0u, 0u, AON__LPI2C0_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { (LPI2C_Type *)0u, (LPI2C_Type *)0u, AON__LPI2C0_NS }
#else
  /** Peripheral AON__LPI2C0 base address */
  #define AON__LPI2C0_BASE                         (0xA0080000u)
  /** Peripheral AON__LPI2C0 base pointer */
  #define AON__LPI2C0                              ((LPI2C_Type *)AON__LPI2C0_BASE)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { 0u, 0u, AON__LPI2C0_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, (LPI2C_Type *)0u, AON__LPI2C0 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, NotAvail_IRQn, LPI2C0_AON_IRQn }

/* LPTMR - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
  /** Peripheral AON__LPUART0 base address */
  #define AON__LPUART0_BASE                        (0xB0082000u)
  /** Peripheral AON__LPUART0 base address */
  #define AON__LPUART0_BASE_NS                     (0xA0082000u)
  /** Peripheral AON__LPUART0 base pointer */
  #define AON__LPUART0                             ((LPUART_Type *)AON__LPUART0_BASE)
  /** Peripheral AON__LPUART0 base pointer */
  #define AON__LPUART0_NS                          ((LPUART_Type *)AON__LPUART0_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { 0u, 0u, AON__LPUART0_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, (LPUART_Type *)0u, AON__LPUART0 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { 0u, 0u, AON__LPUART0_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { (LPUART_Type *)0u, (LPUART_Type *)0u, AON__LPUART0_NS }
#else
  /** Peripheral AON__LPUART0 base address */
  #define AON__LPUART0_BASE                        (0xA0082000u)
  /** Peripheral AON__LPUART0 base pointer */
  #define AON__LPUART0                             ((LPUART_Type *)AON__LPUART0_BASE)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { 0u, 0u, AON__LPUART0_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, (LPUART_Type *)0u, AON__LPUART0 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, NotAvail_IRQn, LPUART0_AON_IRQn }

/* MU - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
  /** Peripheral MUB base address */
  #define MUB_BASE                                 (0xB0084000u)
  /** Peripheral MUB base address */
  #define MUB_BASE_NS                              (0xA0084000u)
  /** Peripheral MUB base pointer */
  #define MUB                                      ((MU_Type *)MUB_BASE)
  /** Peripheral MUB base pointer */
  #define MUB_NS                                   ((MU_Type *)MUB_BASE_NS)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MUB_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MUB }
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS_NS                         { MUB_BASE_NS }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS_NS                          { MUB_NS }
#else
  /** Peripheral MUB base address */
  #define MUB_BASE                                 (0xA0084000u)
  /** Peripheral MUB base pointer */
  #define MUB                                      ((MU_Type *)MUB_BASE)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MUB_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MUB }
#endif

/* PMU - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
  /** Peripheral AON__PORT0 base address */
  #define AON__PORT0_BASE                          (0xB0085000u)
  /** Peripheral AON__PORT0 base address */
  #define AON__PORT0_BASE_NS                       (0xA0085000u)
  /** Peripheral AON__PORT0 base pointer */
  #define AON__PORT0                               ((PORT_Type *)AON__PORT0_BASE)
  /** Peripheral AON__PORT0 base pointer */
  #define AON__PORT0_NS                            ((PORT_Type *)AON__PORT0_BASE_NS)
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS                          { AON__PORT0_BASE }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS                           { AON__PORT0 }
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS_NS                       { AON__PORT0_BASE_NS }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS_NS                        { AON__PORT0_NS }
#else
  /** Peripheral AON__PORT0 base address */
  #define AON__PORT0_BASE                          (0xA0085000u)
  /** Peripheral AON__PORT0 base pointer */
  #define AON__PORT0                               ((PORT_Type *)AON__PORT0_BASE)
  /** Array initializer of PORT peripheral base addresses */
  #define PORT_BASE_ADDRS                          { AON__PORT0_BASE }
  /** Array initializer of PORT peripheral base pointers */
  #define PORT_BASE_PTRS                           { AON__PORT0 }
#endif

/* RTC - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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

/* SGLCD_CONTROL - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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

/* SMM - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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

/* SYSCON_AON - Peripheral instance base addresses */
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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
#if ((defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2)) || defined(CPU1_IS_SECURE_MASTER))
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


#endif  /* MCXL254_CM0PLUS_COMMON_H_ */
