/*
** ###################################################################
**     Processors:          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    LPC55S3x Reference Manual Rev. DraftG, 07/2021
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPC5536
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file LPC5536_COMMON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LPC5536
 *
 * CMSIS Peripheral Access Layer for LPC5536
 */

#if !defined(LPC5536_COMMON_H_)
#define LPC5536_COMMON_H_                        /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 136                /**< Number of interrupts in the Vector table */

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
  WDT_BOD_IRQn                 = 0,                /**< Windowed watchdog timer, Brownout detect, Flash interrupt */
  DMA0_IRQn                    = 1,                /**< DMA0 controller */
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
  FLEXCOMM0_IRQn               = 14,               /**< Flexcomm Interface 0 (USART, SPI, I2C, I2S, FLEXCOMM) */
  FLEXCOMM1_IRQn               = 15,               /**< Flexcomm Interface 1 (USART, SPI, I2C, I2S, FLEXCOMM) */
  FLEXCOMM2_IRQn               = 16,               /**< Flexcomm Interface 2 (USART, SPI, I2C, I2S, FLEXCOMM) */
  FLEXCOMM3_IRQn               = 17,               /**< Flexcomm Interface 3 (USART, SPI, I2C, I2S, FLEXCOMM) */
  FLEXCOMM4_IRQn               = 18,               /**< Flexcomm Interface 4 (USART, SPI, I2C, I2S, FLEXCOMM) */
  FLEXCOMM5_IRQn               = 19,               /**< Flexcomm Interface 5 (USART, SPI, I2C, I2S, FLEXCOMM) */
  FLEXCOMM6_IRQn               = 20,               /**< Flexcomm Interface 6 (USART, SPI, I2C, I2S, FLEXCOMM) */
  FLEXCOMM7_IRQn               = 21,               /**< Flexcomm Interface 7 (USART, SPI, I2C, I2S, FLEXCOMM) */
  ADC0_IRQn                    = 22,               /**< ADC0  */
  ADC1_IRQn                    = 23,               /**< ADC1 */
  ACMP_IRQn                    = 24,               /**< ACMP interrupts */
  DMIC_IRQn                    = 25,               /**< Digital microphone and DMIC subsystem */
  HWVAD0_IRQn                  = 26,               /**< Hardware Voice Activity Detector */
  USB0_NEEDCLK_IRQn            = 27,               /**< USB Activity Wake-up Interrupt */
  USB0_IRQn                    = 28,               /**< USB device */
  RTC_IRQn                     = 29,               /**< RTC alarm and wake-up interrupts */
  EZH_ARCH_B0_IRQn             = 30,               /**< EZH interrupt */
  WAKEUP_IRQn                  = 31,               /**< Wakeup interrupt */
  PIN_INT4_IRQn                = 32,               /**< Pin interrupt 4 or pattern match engine slice 4 int */
  PIN_INT5_IRQn                = 33,               /**< Pin interrupt 5 or pattern match engine slice 5 int */
  PIN_INT6_IRQn                = 34,               /**< Pin interrupt 6 or pattern match engine slice 6 int */
  PIN_INT7_IRQn                = 35,               /**< Pin interrupt 7 or pattern match engine slice 7 int */
  CTIMER2_IRQn                 = 36,               /**< Standard counter/timer CTIMER2 */
  CTIMER4_IRQn                 = 37,               /**< Standard counter/timer CTIMER4 */
  OS_EVENT_IRQn                = 38,               /**< OS_EVENT_TIMER and OS_EVENT_WAKEUP interrupts */
  FlexSPI0_IRQn                = 39,               /**< FlexSPI interrupt */
  Reserved56_IRQn              = 40,               /**< Reserved interrupt */
  Reserved57_IRQn              = 41,               /**< Reserved interrupt */
  Reserved58_IRQn              = 42,               /**< Reserved interrupt */
  CAN0_IRQ0_IRQn               = 43,               /**< CAN0 interrupt0 */
  CAN0_IRQ1_IRQn               = 44,               /**< CAN0 interrupt1 */
  Reserved61_IRQn              = 45,               /**< Reserved interrupt */
  Reserved62_IRQn              = 46,               /**< Reserved interrupt */
  Reserved63_IRQn              = 47,               /**< Reserved interrupt */
  Reserved64_IRQn              = 48,               /**< Reserved interrupt */
  SEC_HYPERVISOR_CALL_IRQn     = 49,               /**< SEC_HYPERVISOR_CALL interrupt */
  SEC_GPIO_INT0_IRQ0_IRQn      = 50,               /**< SEC_GPIO_INT00 interrupt */
  SEC_GPIO_INT0_IRQ1_IRQn      = 51,               /**< SEC_GPIO_INT01 interrupt */
  Freqme_IRQn                  = 52,               /**< frequency measure interrupt */
  SEC_VIO_IRQn                 = 53,               /**< SEC_VIO interrupt */
  ELS_IRQn                     = 54,               /**< ELS and ELS error interrupts */
  PKC_IRQn                     = 55,               /**< Public Key Cryptography interrupt */
  Reserved72_IRQn              = 56,               /**< Reserved interrupt */
  POWERQUAD_IRQn               = 57,               /**< PowerQuad interrupt */
  DMA1_IRQn                    = 58,               /**< DMA1 interrupt */
  FLEXCOMM8_IRQn               = 59,               /**< LSPI_HS interrupt */
  CDOG_IRQn                    = 60,               /**< CodeWDG interrupt */
  Reserved77_IRQn              = 61,               /**< Reserved interrupt */
  I3C0_IRQn                    = 62,               /**< I3C interrupt */
  Reserved79_IRQn              = 63,               /**< Reserved interrupt */
  Reserved80_IRQn              = 64,               /**< Reserved interrupt */
  ELS_IRQ1_IRQn                = 65,               /**< ELS_IRQ1 */
  Tamper_IRQn                  = 66,               /**< Tamper */
  Reserved83_IRQn              = 67,               /**< Reserved interrupt */
  Reserved84_IRQn              = 68,               /**< Reserved interrupt */
  Reserved85_IRQn              = 69,               /**< Reserved interrupt */
  Reserved86_IRQn              = 70,               /**< Reserved interrupt */
  Reserved87_IRQn              = 71,               /**< Reserved interrupt */
  Reserved88_IRQn              = 72,               /**< Reserved interrupt */
  Reserved89_IRQn              = 73,               /**< Reserved interrupt */
  DAC0_IRQn                    = 74,               /**< dac0 interrupt */
  DAC1_IRQn                    = 75,               /**< dac1 interrupt */
  DAC2_IRQn                    = 76,               /**< dac2 interrupt */
  HSCMP0_IRQn                  = 77,               /**< hscmp0 interrupt */
  HSCMP1_IRQn                  = 78,               /**< hscmp1 interrupt */
  HSCMP2_IRQn                  = 79,               /**< hscmp2 interrupt */
  FLEXPWM0_CAPTURE_IRQn        = 80,               /**< flexpwm0_capture interrupt */
  FLEXPWM0_FAULT_IRQn          = 81,               /**< flexpwm0_fault interrupt */
  FLEXPWM0_RELOAD_ERROR_IRQn   = 82,               /**< flexpwm0_reload_error interrupt */
  FLEXPWM0_COMPARE0_IRQn       = 83,               /**< flexpwm0_compare0 interrupt */
  FLEXPWM0_RELOAD0_IRQn        = 84,               /**< flexpwm0_reload0 interrupt */
  FLEXPWM0_COMPARE1_IRQn       = 85,               /**< flexpwm0_compare1 interrupt */
  FLEXPWM0_RELOAD1_IRQn        = 86,               /**< flexpwm0_reload1 interrupt */
  FLEXPWM0_COMPARE2_IRQn       = 87,               /**< flexpwm0_compare2 interrupt */
  FLEXPWM0_RELOAD2_IRQn        = 88,               /**< flexpwm0_reload2 interrupt */
  FLEXPWM0_COMPARE3_IRQn       = 89,               /**< flexpwm0_compare3 interrupt */
  FLEXPWM0_RELOAD3_IRQn        = 90,               /**< flexpwm0_reload3 interrupt */
  FLEXPWM1_CAPTURE_IRQn        = 91,               /**< flexpwm1_capture interrupt */
  FLEXPWM1_FAULT_IRQn          = 92,               /**< flexpwm1_fault interrupt */
  FLEXPWM1_RELOAD_ERROR_IRQn   = 93,               /**< flexpwm1_reload_error interrupt */
  FLEXPWM1_COMPARE0_IRQn       = 94,               /**< flexpwm1_compare0 interrupt */
  FLEXPWM1_RELOAD0_IRQn        = 95,               /**< flexpwm1_reload0 interrupt */
  FLEXPWM1_COMPARE1_IRQn       = 96,               /**< flexpwm1_compare1 interrupt */
  FLEXPWM1_RELOAD1_IRQn        = 97,               /**< flexpwm1_reload1 interrupt */
  FLEXPWM1_COMPARE2_IRQn       = 98,               /**< flexpwm1_compare2 interrupt */
  FLEXPWM1_RELOAD2_IRQn        = 99,               /**< flexpwm1_reload2 interrupt */
  FLEXPWM1_COMPARE3_IRQn       = 100,              /**< flexpwm1_compare3 interrupt */
  FLEXPWM1_RELOAD3_IRQn        = 101,              /**< flexpwm1_reload3 interrupt */
  ENC0_COMPARE_IRQn            = 102,              /**< enc0_compare interrupt */
  ENC0_HOME_IRQn               = 103,              /**< enc0_home interrupt */
  ENC0_WDG_IRQn                = 104,              /**< enc0_wdg interrupt */
  ENC0_IDX_IRQn                = 105,              /**< enc0_idx interrupt */
  ENC1_COMPARE_IRQn            = 106,              /**< enc1_compare interrupt */
  ENC1_HOME_IRQn               = 107,              /**< enc1_home interrupt */
  ENC1_WDG_IRQn                = 108,              /**< enc1_wdg interrupt */
  ENC1_IDX_IRQn                = 109,              /**< enc1_idx interrupt */
  Reserved126_IRQn             = 110,              /**< Reserved interrupt */
  Reserved127_IRQn             = 111,              /**< Reserved interrupt */
  ELS_ERR_IRQn                 = 112,              /**< ELS error interrupt */
  PKC_ERR_IRQn                 = 113,              /**< PKC error interrupt */
  Reserved130_IRQn             = 114,              /**< Reserved interrupt */
  Reserved131_IRQn             = 115,              /**< Reserved interrupt */
  Reserved132_IRQn             = 116,              /**< Reserved interrupt */
  Reserved133_IRQn             = 117,              /**< Reserved interrupt */
  FLASH_IRQn                   = 118,              /**< flash interrupt */
  RAM_PARITY_ECC_ERR_IRQn      = 119               /**< ram_parity_ecc_err interrupt */
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
#include "system_LPC5536.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef LPC5536_SERIES
#define LPC5536_SERIES
#endif
/* CPU specific feature definitions */
#include "LPC5536_features.h"

/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADC0 base address */
  #define ADC0_BASE                                (0x500A0000u)
  /** Peripheral ADC0 base address */
  #define ADC0_BASE_NS                             (0x400A0000u)
  /** Peripheral ADC0 base pointer */
  #define ADC0                                     ((ADC_Type *)ADC0_BASE)
  /** Peripheral ADC0 base pointer */
  #define ADC0_NS                                  ((ADC_Type *)ADC0_BASE_NS)
  /** Peripheral ADC1 base address */
  #define ADC1_BASE                                (0x500B1000u)
  /** Peripheral ADC1 base address */
  #define ADC1_BASE_NS                             (0x400B1000u)
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
  #define ADC0_BASE                                (0x400A0000u)
  /** Peripheral ADC0 base pointer */
  #define ADC0                                     ((ADC_Type *)ADC0_BASE)
  /** Peripheral ADC1 base address */
  #define ADC1_BASE                                (0x400B1000u)
  /** Peripheral ADC1 base pointer */
  #define ADC1                                     ((ADC_Type *)ADC1_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC0_BASE, ADC1_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC0, ADC1 }
#endif
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn, ADC1_IRQn }

/* ANACTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANACTRL base address */
  #define ANACTRL_BASE                             (0x50013000u)
  /** Peripheral ANACTRL base address */
  #define ANACTRL_BASE_NS                          (0x40013000u)
  /** Peripheral ANACTRL base pointer */
  #define ANACTRL                                  ((ANACTRL_Type *)ANACTRL_BASE)
  /** Peripheral ANACTRL base pointer */
  #define ANACTRL_NS                               ((ANACTRL_Type *)ANACTRL_BASE_NS)
  /** Array initializer of ANACTRL peripheral base addresses */
  #define ANACTRL_BASE_ADDRS                       { ANACTRL_BASE }
  /** Array initializer of ANACTRL peripheral base pointers */
  #define ANACTRL_BASE_PTRS                        { ANACTRL }
  /** Array initializer of ANACTRL peripheral base addresses */
  #define ANACTRL_BASE_ADDRS_NS                    { ANACTRL_BASE_NS }
  /** Array initializer of ANACTRL peripheral base pointers */
  #define ANACTRL_BASE_PTRS_NS                     { ANACTRL_NS }
#else
  /** Peripheral ANACTRL base address */
  #define ANACTRL_BASE                             (0x40013000u)
  /** Peripheral ANACTRL base pointer */
  #define ANACTRL                                  ((ANACTRL_Type *)ANACTRL_BASE)
  /** Array initializer of ANACTRL peripheral base addresses */
  #define ANACTRL_BASE_ADDRS                       { ANACTRL_BASE }
  /** Array initializer of ANACTRL peripheral base pointers */
  #define ANACTRL_BASE_PTRS                        { ANACTRL }
#endif

/* AOI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AOI0 base address */
  #define AOI0_BASE                                (0x500C7000u)
  /** Peripheral AOI0 base address */
  #define AOI0_BASE_NS                             (0x400C7000u)
  /** Peripheral AOI0 base pointer */
  #define AOI0                                     ((AOI_Type *)AOI0_BASE)
  /** Peripheral AOI0 base pointer */
  #define AOI0_NS                                  ((AOI_Type *)AOI0_BASE_NS)
  /** Peripheral AOI1 base address */
  #define AOI1_BASE                                (0x500C8000u)
  /** Peripheral AOI1 base address */
  #define AOI1_BASE_NS                             (0x400C8000u)
  /** Peripheral AOI1 base pointer */
  #define AOI1                                     ((AOI_Type *)AOI1_BASE)
  /** Peripheral AOI1 base pointer */
  #define AOI1_NS                                  ((AOI_Type *)AOI1_BASE_NS)
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS                           { AOI0_BASE, AOI1_BASE }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS                            { AOI0, AOI1 }
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS_NS                        { AOI0_BASE_NS, AOI1_BASE_NS }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS_NS                         { AOI0_NS, AOI1_NS }
#else
  /** Peripheral AOI0 base address */
  #define AOI0_BASE                                (0x400C7000u)
  /** Peripheral AOI0 base pointer */
  #define AOI0                                     ((AOI_Type *)AOI0_BASE)
  /** Peripheral AOI1 base address */
  #define AOI1_BASE                                (0x400C8000u)
  /** Peripheral AOI1 base pointer */
  #define AOI1                                     ((AOI_Type *)AOI1_BASE)
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS                           { AOI0_BASE, AOI1_BASE }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS                            { AOI0, AOI1 }
#endif

/* CACHE64_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CACHE64_CTRL0 base address */
  #define CACHE64_CTRL0_BASE                       (0x5002E000u)
  /** Peripheral CACHE64_CTRL0 base address */
  #define CACHE64_CTRL0_BASE_NS                    (0x4002E000u)
  /** Peripheral CACHE64_CTRL0 base pointer */
  #define CACHE64_CTRL0                            ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE)
  /** Peripheral CACHE64_CTRL0 base pointer */
  #define CACHE64_CTRL0_NS                         ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE_NS)
  /** Array initializer of CACHE64_CTRL peripheral base addresses */
  #define CACHE64_CTRL_BASE_ADDRS                  { CACHE64_CTRL0_BASE }
  /** Array initializer of CACHE64_CTRL peripheral base pointers */
  #define CACHE64_CTRL_BASE_PTRS                   { CACHE64_CTRL0 }
  /** Array initializer of CACHE64_CTRL peripheral base addresses */
  #define CACHE64_CTRL_BASE_ADDRS_NS               { CACHE64_CTRL0_BASE_NS }
  /** Array initializer of CACHE64_CTRL peripheral base pointers */
  #define CACHE64_CTRL_BASE_PTRS_NS                { CACHE64_CTRL0_NS }
#else
  /** Peripheral CACHE64_CTRL0 base address */
  #define CACHE64_CTRL0_BASE                       (0x4002E000u)
  /** Peripheral CACHE64_CTRL0 base pointer */
  #define CACHE64_CTRL0                            ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE)
  /** Array initializer of CACHE64_CTRL peripheral base addresses */
  #define CACHE64_CTRL_BASE_ADDRS                  { CACHE64_CTRL0_BASE }
  /** Array initializer of CACHE64_CTRL peripheral base pointers */
  #define CACHE64_CTRL_BASE_PTRS                   { CACHE64_CTRL0 }
#endif
/** CACHE64_CTRL physical memory base alias count */
 #define CACHE64_CTRL_PHYMEM_BASE_ALIAS_COUNT     (2)
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** CACHE64_CTRL physical memory base address */
 #define CACHE64_CTRL_PHYMEM_BASES                { {0x18000000u, 0x38000000u} }
/** CACHE64_CTRL physical memory size */
 #define CACHE64_CTRL_PHYMEM_SIZES                { {0x08000000u, 0x08000000u} }
/** CACHE64_CTRL physical memory base address */
 #define CACHE64_CTRL_PHYMEM_BASES_NS             { {0x08000000u, 0x28000000u} }
/** CACHE64_CTRL physical memory size */
 #define CACHE64_CTRL_PHYMEM_SIZES_NS             { {0x08000000u, 0x08000000u} }
#else
/** CACHE64_CTRL physical memory base address */
 #define CACHE64_CTRL_PHYMEM_BASES                { {0x08000000u, 0x28000000u} }
/** CACHE64_CTRL physical memory size */
 #define CACHE64_CTRL_PHYMEM_SIZES                { {0x08000000u, 0x08000000u} }
#endif
/* Backward compatibility */


/* CACHE64_POLSEL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CACHE64_POLSEL0 base address */
  #define CACHE64_POLSEL0_BASE                     (0x5002E000u)
  /** Peripheral CACHE64_POLSEL0 base address */
  #define CACHE64_POLSEL0_BASE_NS                  (0x4002E000u)
  /** Peripheral CACHE64_POLSEL0 base pointer */
  #define CACHE64_POLSEL0                          ((CACHE64_POLSEL_Type *)CACHE64_POLSEL0_BASE)
  /** Peripheral CACHE64_POLSEL0 base pointer */
  #define CACHE64_POLSEL0_NS                       ((CACHE64_POLSEL_Type *)CACHE64_POLSEL0_BASE_NS)
  /** Array initializer of CACHE64_POLSEL peripheral base addresses */
  #define CACHE64_POLSEL_BASE_ADDRS                { CACHE64_POLSEL0_BASE }
  /** Array initializer of CACHE64_POLSEL peripheral base pointers */
  #define CACHE64_POLSEL_BASE_PTRS                 { CACHE64_POLSEL0 }
  /** Array initializer of CACHE64_POLSEL peripheral base addresses */
  #define CACHE64_POLSEL_BASE_ADDRS_NS             { CACHE64_POLSEL0_BASE_NS }
  /** Array initializer of CACHE64_POLSEL peripheral base pointers */
  #define CACHE64_POLSEL_BASE_PTRS_NS              { CACHE64_POLSEL0_NS }
#else
  /** Peripheral CACHE64_POLSEL0 base address */
  #define CACHE64_POLSEL0_BASE                     (0x4002E000u)
  /** Peripheral CACHE64_POLSEL0 base pointer */
  #define CACHE64_POLSEL0                          ((CACHE64_POLSEL_Type *)CACHE64_POLSEL0_BASE)
  /** Array initializer of CACHE64_POLSEL peripheral base addresses */
  #define CACHE64_POLSEL_BASE_ADDRS                { CACHE64_POLSEL0_BASE }
  /** Array initializer of CACHE64_POLSEL peripheral base pointers */
  #define CACHE64_POLSEL_BASE_PTRS                 { CACHE64_POLSEL0 }
#endif

/* CAN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CAN0 base address */
  #define CAN0_BASE                                (0x5009D000u)
  /** Peripheral CAN0 base address */
  #define CAN0_BASE_NS                             (0x4009D000u)
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
  #define CAN0_BASE                                (0x4009D000u)
  /** Peripheral CAN0 base pointer */
  #define CAN0                                     ((CAN_Type *)CAN0_BASE)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { CAN0_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { CAN0 }
#endif
/** Interrupt vectors for the CAN peripheral type */
#define CAN_IRQS                                 { { CAN0_IRQ0_IRQn, CAN0_IRQ1_IRQn } }

/* CDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CDOG base address */
  #define CDOG_BASE                                (0x500A1000u)
  /** Peripheral CDOG base address */
  #define CDOG_BASE_NS                             (0x400A1000u)
  /** Peripheral CDOG base pointer */
  #define CDOG                                     ((CDOG_Type *)CDOG_BASE)
  /** Peripheral CDOG base pointer */
  #define CDOG_NS                                  ((CDOG_Type *)CDOG_BASE_NS)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { CDOG_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { CDOG }
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS_NS                       { CDOG_BASE_NS }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS_NS                        { CDOG_NS }
#else
  /** Peripheral CDOG base address */
  #define CDOG_BASE                                (0x400A1000u)
  /** Peripheral CDOG base pointer */
  #define CDOG                                     ((CDOG_Type *)CDOG_BASE)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { CDOG_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { CDOG }
#endif
/** Interrupt vectors for the CDOG peripheral type */
#define CDOG_IRQS                                { CDOG_IRQn }

/* CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CRC0 base address */
  #define CRC0_BASE                                (0x50095000u)
  /** Peripheral CRC0 base address */
  #define CRC0_BASE_NS                             (0x40095000u)
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
  #define CRC0_BASE                                (0x40095000u)
  /** Peripheral CRC0 base pointer */
  #define CRC0                                     ((CRC_Type *)CRC0_BASE)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC0_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC0 }
#endif

/* CTIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CTIMER0 base address */
  #define CTIMER0_BASE                             (0x50008000u)
  /** Peripheral CTIMER0 base address */
  #define CTIMER0_BASE_NS                          (0x40008000u)
  /** Peripheral CTIMER0 base pointer */
  #define CTIMER0                                  ((CTIMER_Type *)CTIMER0_BASE)
  /** Peripheral CTIMER0 base pointer */
  #define CTIMER0_NS                               ((CTIMER_Type *)CTIMER0_BASE_NS)
  /** Peripheral CTIMER1 base address */
  #define CTIMER1_BASE                             (0x50009000u)
  /** Peripheral CTIMER1 base address */
  #define CTIMER1_BASE_NS                          (0x40009000u)
  /** Peripheral CTIMER1 base pointer */
  #define CTIMER1                                  ((CTIMER_Type *)CTIMER1_BASE)
  /** Peripheral CTIMER1 base pointer */
  #define CTIMER1_NS                               ((CTIMER_Type *)CTIMER1_BASE_NS)
  /** Peripheral CTIMER2 base address */
  #define CTIMER2_BASE                             (0x50028000u)
  /** Peripheral CTIMER2 base address */
  #define CTIMER2_BASE_NS                          (0x40028000u)
  /** Peripheral CTIMER2 base pointer */
  #define CTIMER2                                  ((CTIMER_Type *)CTIMER2_BASE)
  /** Peripheral CTIMER2 base pointer */
  #define CTIMER2_NS                               ((CTIMER_Type *)CTIMER2_BASE_NS)
  /** Peripheral CTIMER3 base address */
  #define CTIMER3_BASE                             (0x50029000u)
  /** Peripheral CTIMER3 base address */
  #define CTIMER3_BASE_NS                          (0x40029000u)
  /** Peripheral CTIMER3 base pointer */
  #define CTIMER3                                  ((CTIMER_Type *)CTIMER3_BASE)
  /** Peripheral CTIMER3 base pointer */
  #define CTIMER3_NS                               ((CTIMER_Type *)CTIMER3_BASE_NS)
  /** Peripheral CTIMER4 base address */
  #define CTIMER4_BASE                             (0x5002A000u)
  /** Peripheral CTIMER4 base address */
  #define CTIMER4_BASE_NS                          (0x4002A000u)
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
  #define CTIMER3_BASE                             (0x40029000u)
  /** Peripheral CTIMER3 base pointer */
  #define CTIMER3                                  ((CTIMER_Type *)CTIMER3_BASE)
  /** Peripheral CTIMER4 base address */
  #define CTIMER4_BASE                             (0x4002A000u)
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
  /** Peripheral DEBUGGER_MAILBOX0 base address */
  #define DEBUGGER_MAILBOX0_BASE                   (0x5009C000u)
  /** Peripheral DEBUGGER_MAILBOX0 base address */
  #define DEBUGGER_MAILBOX0_BASE_NS                (0x4009C000u)
  /** Peripheral DEBUGGER_MAILBOX0 base pointer */
  #define DEBUGGER_MAILBOX0                        ((DEBUGGER_MAILBOX_Type *)DEBUGGER_MAILBOX0_BASE)
  /** Peripheral DEBUGGER_MAILBOX0 base pointer */
  #define DEBUGGER_MAILBOX0_NS                     ((DEBUGGER_MAILBOX_Type *)DEBUGGER_MAILBOX0_BASE_NS)
  /** Array initializer of DEBUGGER_MAILBOX peripheral base addresses */
  #define DEBUGGER_MAILBOX_BASE_ADDRS              { DEBUGGER_MAILBOX0_BASE }
  /** Array initializer of DEBUGGER_MAILBOX peripheral base pointers */
  #define DEBUGGER_MAILBOX_BASE_PTRS               { DEBUGGER_MAILBOX0 }
  /** Array initializer of DEBUGGER_MAILBOX peripheral base addresses */
  #define DEBUGGER_MAILBOX_BASE_ADDRS_NS           { DEBUGGER_MAILBOX0_BASE_NS }
  /** Array initializer of DEBUGGER_MAILBOX peripheral base pointers */
  #define DEBUGGER_MAILBOX_BASE_PTRS_NS            { DEBUGGER_MAILBOX0_NS }
#else
  /** Peripheral DEBUGGER_MAILBOX0 base address */
  #define DEBUGGER_MAILBOX0_BASE                   (0x4009C000u)
  /** Peripheral DEBUGGER_MAILBOX0 base pointer */
  #define DEBUGGER_MAILBOX0                        ((DEBUGGER_MAILBOX_Type *)DEBUGGER_MAILBOX0_BASE)
  /** Array initializer of DEBUGGER_MAILBOX peripheral base addresses */
  #define DEBUGGER_MAILBOX_BASE_ADDRS              { DEBUGGER_MAILBOX0_BASE }
  /** Array initializer of DEBUGGER_MAILBOX peripheral base pointers */
  #define DEBUGGER_MAILBOX_BASE_PTRS               { DEBUGGER_MAILBOX0 }
#endif

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA0 base address */
  #define DMA0_BASE                                (0x50082000u)
  /** Peripheral DMA0 base address */
  #define DMA0_BASE_NS                             (0x40082000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Peripheral DMA0 base pointer */
  #define DMA0_NS                                  ((DMA_Type *)DMA0_BASE_NS)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE                                (0x500A7000u)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE_NS                             (0x400A7000u)
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
  #define DMA0_BASE                                (0x40082000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE                                (0x400A7000u)
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
  #define DMIC0_BASE                               (0x50090000u)
  /** Peripheral DMIC0 base address */
  #define DMIC0_BASE_NS                            (0x40090000u)
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
  #define DMIC0_BASE                               (0x40090000u)
  /** Peripheral DMIC0 base pointer */
  #define DMIC0                                    ((DMIC_Type *)DMIC0_BASE)
  /** Array initializer of DMIC peripheral base addresses */
  #define DMIC_BASE_ADDRS                          { DMIC0_BASE }
  /** Array initializer of DMIC peripheral base pointers */
  #define DMIC_BASE_PTRS                           { DMIC0 }
#endif
/** Interrupt vectors for the DMIC peripheral type */
#define DMIC_IRQS                                { DMIC_IRQn }
#define DMIC_HWVAD_IRQS                          { HWVAD0_IRQn }

/* ENC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENC0 base address */
  #define ENC0_BASE                                (0x500C4000u)
  /** Peripheral ENC0 base address */
  #define ENC0_BASE_NS                             (0x400C4000u)
  /** Peripheral ENC0 base pointer */
  #define ENC0                                     ((ENC_Type *)ENC0_BASE)
  /** Peripheral ENC0 base pointer */
  #define ENC0_NS                                  ((ENC_Type *)ENC0_BASE_NS)
  /** Peripheral ENC1 base address */
  #define ENC1_BASE                                (0x500C6000u)
  /** Peripheral ENC1 base address */
  #define ENC1_BASE_NS                             (0x400C6000u)
  /** Peripheral ENC1 base pointer */
  #define ENC1                                     ((ENC_Type *)ENC1_BASE)
  /** Peripheral ENC1 base pointer */
  #define ENC1_NS                                  ((ENC_Type *)ENC1_BASE_NS)
  /** Array initializer of ENC peripheral base addresses */
  #define ENC_BASE_ADDRS                           { ENC0_BASE, ENC1_BASE }
  /** Array initializer of ENC peripheral base pointers */
  #define ENC_BASE_PTRS                            { ENC0, ENC1 }
  /** Array initializer of ENC peripheral base addresses */
  #define ENC_BASE_ADDRS_NS                        { ENC0_BASE_NS, ENC1_BASE_NS }
  /** Array initializer of ENC peripheral base pointers */
  #define ENC_BASE_PTRS_NS                         { ENC0_NS, ENC1_NS }
#else
  /** Peripheral ENC0 base address */
  #define ENC0_BASE                                (0x400C4000u)
  /** Peripheral ENC0 base pointer */
  #define ENC0                                     ((ENC_Type *)ENC0_BASE)
  /** Peripheral ENC1 base address */
  #define ENC1_BASE                                (0x400C6000u)
  /** Peripheral ENC1 base pointer */
  #define ENC1                                     ((ENC_Type *)ENC1_BASE)
  /** Array initializer of ENC peripheral base addresses */
  #define ENC_BASE_ADDRS                           { ENC0_BASE, ENC1_BASE }
  /** Array initializer of ENC peripheral base pointers */
  #define ENC_BASE_PTRS                            { ENC0, ENC1 }
#endif
/** Interrupt vectors for the ENC peripheral type */
#define ENC_COMPARE_IRQS                         { ENC0_COMPARE_IRQn, ENC1_COMPARE_IRQn }
#define ENC_HOME_IRQS                            { ENC0_HOME_IRQn, ENC1_HOME_IRQn }
#define ENC_WDOG_IRQS                            { ENC0_WDG_IRQn, ENC1_WDG_IRQn }
#define ENC_INDEX_IRQS                           { ENC0_IDX_IRQn, ENC1_IDX_IRQn }

/* FLASH - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLASH base address */
  #define FLASH_BASE                               (0x50034000u)
  /** Peripheral FLASH base address */
  #define FLASH_BASE_NS                            (0x40034000u)
  /** Peripheral FLASH base pointer */
  #define FLASH                                    ((FLASH_Type *)FLASH_BASE)
  /** Peripheral FLASH base pointer */
  #define FLASH_NS                                 ((FLASH_Type *)FLASH_BASE_NS)
  /** Array initializer of FLASH peripheral base addresses */
  #define FLASH_BASE_ADDRS                         { FLASH_BASE }
  /** Array initializer of FLASH peripheral base pointers */
  #define FLASH_BASE_PTRS                          { FLASH }
  /** Array initializer of FLASH peripheral base addresses */
  #define FLASH_BASE_ADDRS_NS                      { FLASH_BASE_NS }
  /** Array initializer of FLASH peripheral base pointers */
  #define FLASH_BASE_PTRS_NS                       { FLASH_NS }
#else
  /** Peripheral FLASH base address */
  #define FLASH_BASE                               (0x40034000u)
  /** Peripheral FLASH base pointer */
  #define FLASH                                    ((FLASH_Type *)FLASH_BASE)
  /** Array initializer of FLASH peripheral base addresses */
  #define FLASH_BASE_ADDRS                         { FLASH_BASE }
  /** Array initializer of FLASH peripheral base pointers */
  #define FLASH_BASE_PTRS                          { FLASH }
#endif

/* FLEXCOMM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXCOMM0 base address */
  #define FLEXCOMM0_BASE                           (0x50086000u)
  /** Peripheral FLEXCOMM0 base address */
  #define FLEXCOMM0_BASE_NS                        (0x40086000u)
  /** Peripheral FLEXCOMM0 base pointer */
  #define FLEXCOMM0                                ((FLEXCOMM_Type *)FLEXCOMM0_BASE)
  /** Peripheral FLEXCOMM0 base pointer */
  #define FLEXCOMM0_NS                             ((FLEXCOMM_Type *)FLEXCOMM0_BASE_NS)
  /** Peripheral FLEXCOMM1 base address */
  #define FLEXCOMM1_BASE                           (0x50087000u)
  /** Peripheral FLEXCOMM1 base address */
  #define FLEXCOMM1_BASE_NS                        (0x40087000u)
  /** Peripheral FLEXCOMM1 base pointer */
  #define FLEXCOMM1                                ((FLEXCOMM_Type *)FLEXCOMM1_BASE)
  /** Peripheral FLEXCOMM1 base pointer */
  #define FLEXCOMM1_NS                             ((FLEXCOMM_Type *)FLEXCOMM1_BASE_NS)
  /** Peripheral FLEXCOMM2 base address */
  #define FLEXCOMM2_BASE                           (0x50088000u)
  /** Peripheral FLEXCOMM2 base address */
  #define FLEXCOMM2_BASE_NS                        (0x40088000u)
  /** Peripheral FLEXCOMM2 base pointer */
  #define FLEXCOMM2                                ((FLEXCOMM_Type *)FLEXCOMM2_BASE)
  /** Peripheral FLEXCOMM2 base pointer */
  #define FLEXCOMM2_NS                             ((FLEXCOMM_Type *)FLEXCOMM2_BASE_NS)
  /** Peripheral FLEXCOMM3 base address */
  #define FLEXCOMM3_BASE                           (0x50089000u)
  /** Peripheral FLEXCOMM3 base address */
  #define FLEXCOMM3_BASE_NS                        (0x40089000u)
  /** Peripheral FLEXCOMM3 base pointer */
  #define FLEXCOMM3                                ((FLEXCOMM_Type *)FLEXCOMM3_BASE)
  /** Peripheral FLEXCOMM3 base pointer */
  #define FLEXCOMM3_NS                             ((FLEXCOMM_Type *)FLEXCOMM3_BASE_NS)
  /** Peripheral FLEXCOMM4 base address */
  #define FLEXCOMM4_BASE                           (0x5008A000u)
  /** Peripheral FLEXCOMM4 base address */
  #define FLEXCOMM4_BASE_NS                        (0x4008A000u)
  /** Peripheral FLEXCOMM4 base pointer */
  #define FLEXCOMM4                                ((FLEXCOMM_Type *)FLEXCOMM4_BASE)
  /** Peripheral FLEXCOMM4 base pointer */
  #define FLEXCOMM4_NS                             ((FLEXCOMM_Type *)FLEXCOMM4_BASE_NS)
  /** Peripheral FLEXCOMM5 base address */
  #define FLEXCOMM5_BASE                           (0x50096000u)
  /** Peripheral FLEXCOMM5 base address */
  #define FLEXCOMM5_BASE_NS                        (0x40096000u)
  /** Peripheral FLEXCOMM5 base pointer */
  #define FLEXCOMM5                                ((FLEXCOMM_Type *)FLEXCOMM5_BASE)
  /** Peripheral FLEXCOMM5 base pointer */
  #define FLEXCOMM5_NS                             ((FLEXCOMM_Type *)FLEXCOMM5_BASE_NS)
  /** Peripheral FLEXCOMM6 base address */
  #define FLEXCOMM6_BASE                           (0x50097000u)
  /** Peripheral FLEXCOMM6 base address */
  #define FLEXCOMM6_BASE_NS                        (0x40097000u)
  /** Peripheral FLEXCOMM6 base pointer */
  #define FLEXCOMM6                                ((FLEXCOMM_Type *)FLEXCOMM6_BASE)
  /** Peripheral FLEXCOMM6 base pointer */
  #define FLEXCOMM6_NS                             ((FLEXCOMM_Type *)FLEXCOMM6_BASE_NS)
  /** Peripheral FLEXCOMM7 base address */
  #define FLEXCOMM7_BASE                           (0x50098000u)
  /** Peripheral FLEXCOMM7 base address */
  #define FLEXCOMM7_BASE_NS                        (0x40098000u)
  /** Peripheral FLEXCOMM7 base pointer */
  #define FLEXCOMM7                                ((FLEXCOMM_Type *)FLEXCOMM7_BASE)
  /** Peripheral FLEXCOMM7 base pointer */
  #define FLEXCOMM7_NS                             ((FLEXCOMM_Type *)FLEXCOMM7_BASE_NS)
  /** Peripheral FLEXCOMM8 base address */
  #define FLEXCOMM8_BASE                           (0x5009F000u)
  /** Peripheral FLEXCOMM8 base address */
  #define FLEXCOMM8_BASE_NS                        (0x4009F000u)
  /** Peripheral FLEXCOMM8 base pointer */
  #define FLEXCOMM8                                ((FLEXCOMM_Type *)FLEXCOMM8_BASE)
  /** Peripheral FLEXCOMM8 base pointer */
  #define FLEXCOMM8_NS                             ((FLEXCOMM_Type *)FLEXCOMM8_BASE_NS)
  /** Array initializer of FLEXCOMM peripheral base addresses */
  #define FLEXCOMM_BASE_ADDRS                      { FLEXCOMM0_BASE, FLEXCOMM1_BASE, FLEXCOMM2_BASE, FLEXCOMM3_BASE, FLEXCOMM4_BASE, FLEXCOMM5_BASE, FLEXCOMM6_BASE, FLEXCOMM7_BASE, FLEXCOMM8_BASE }
  /** Array initializer of FLEXCOMM peripheral base pointers */
  #define FLEXCOMM_BASE_PTRS                       { FLEXCOMM0, FLEXCOMM1, FLEXCOMM2, FLEXCOMM3, FLEXCOMM4, FLEXCOMM5, FLEXCOMM6, FLEXCOMM7, FLEXCOMM8 }
  /** Array initializer of FLEXCOMM peripheral base addresses */
  #define FLEXCOMM_BASE_ADDRS_NS                   { FLEXCOMM0_BASE_NS, FLEXCOMM1_BASE_NS, FLEXCOMM2_BASE_NS, FLEXCOMM3_BASE_NS, FLEXCOMM4_BASE_NS, FLEXCOMM5_BASE_NS, FLEXCOMM6_BASE_NS, FLEXCOMM7_BASE_NS, FLEXCOMM8_BASE_NS }
  /** Array initializer of FLEXCOMM peripheral base pointers */
  #define FLEXCOMM_BASE_PTRS_NS                    { FLEXCOMM0_NS, FLEXCOMM1_NS, FLEXCOMM2_NS, FLEXCOMM3_NS, FLEXCOMM4_NS, FLEXCOMM5_NS, FLEXCOMM6_NS, FLEXCOMM7_NS, FLEXCOMM8_NS }
#else
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
  #define FLEXCOMM8_BASE                           (0x4009F000u)
  /** Peripheral FLEXCOMM8 base pointer */
  #define FLEXCOMM8                                ((FLEXCOMM_Type *)FLEXCOMM8_BASE)
  /** Array initializer of FLEXCOMM peripheral base addresses */
  #define FLEXCOMM_BASE_ADDRS                      { FLEXCOMM0_BASE, FLEXCOMM1_BASE, FLEXCOMM2_BASE, FLEXCOMM3_BASE, FLEXCOMM4_BASE, FLEXCOMM5_BASE, FLEXCOMM6_BASE, FLEXCOMM7_BASE, FLEXCOMM8_BASE }
  /** Array initializer of FLEXCOMM peripheral base pointers */
  #define FLEXCOMM_BASE_PTRS                       { FLEXCOMM0, FLEXCOMM1, FLEXCOMM2, FLEXCOMM3, FLEXCOMM4, FLEXCOMM5, FLEXCOMM6, FLEXCOMM7, FLEXCOMM8 }
#endif
/** Interrupt vectors for the FLEXCOMM peripheral type */
#define FLEXCOMM_IRQS                            { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, FLEXCOMM8_IRQn }

/* FLEXSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXSPI0 base address */
  #define FLEXSPI0_BASE                            (0x500C0000u)
  /** Peripheral FLEXSPI0 base address */
  #define FLEXSPI0_BASE_NS                         (0x400C0000u)
  /** Peripheral FLEXSPI0 base pointer */
  #define FLEXSPI0                                 ((FLEXSPI_Type *)FLEXSPI0_BASE)
  /** Peripheral FLEXSPI0 base pointer */
  #define FLEXSPI0_NS                              ((FLEXSPI_Type *)FLEXSPI0_BASE_NS)
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS                       { FLEXSPI0_BASE }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS                        { FLEXSPI0 }
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS_NS                    { FLEXSPI0_BASE_NS }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS_NS                     { FLEXSPI0_NS }
#else
  /** Peripheral FLEXSPI0 base address */
  #define FLEXSPI0_BASE                            (0x400C0000u)
  /** Peripheral FLEXSPI0 base pointer */
  #define FLEXSPI0                                 ((FLEXSPI_Type *)FLEXSPI0_BASE)
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS                       { FLEXSPI0_BASE }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS                        { FLEXSPI0 }
#endif
/** Interrupt vectors for the FLEXSPI peripheral type */
#define FLEXSPI_IRQS                             { FlexSPI0_IRQn }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (1)
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** FlexSPI AMBA base address array */
#define FlexSPI_AMBA_BASE_ARRAY                   { {0x18000000u} }
/** FlexSPI AMBA end address array */
#define FlexSPI_AMBA_END_ARRAY                    { {0x1FFFFFFFu} }
/** FlexSPI AMBA base address array */
#define FlexSPI_AMBA_BASE_ARRAY_NS                { {0x08000000u} }
/** FlexSPI AMBA end address array */
#define FlexSPI_AMBA_END_ARRAY_NS                 { {0x0FFFFFFFu} }
/** FlexSPI0 AMBA base address */
#define FlexSPI0_AMBA_BASE                        (0x18000000u)
/** FlexSPI0 AMBA base address */
#define FlexSPI0_AMBA_BASE_NS                     (0x08000000u)
#else
/** FlexSPI AMBA base address array */
#define FlexSPI_AMBA_BASE_ARRAY                   { {0x08000000u} }
/** FlexSPI AMBA end address array */
#define FlexSPI_AMBA_END_ARRAY                    { {0x0FFFFFFFu} }
/** FlexSPI0 AMBA base address */
#define FlexSPI0_AMBA_BASE                        (0x08000000u)
#endif


/* FREQME - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FREQME base address */
  #define FREQME_BASE                              (0x50013140u)
  /** Peripheral FREQME base address */
  #define FREQME_BASE_NS                           (0x40013140u)
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
  #define FREQME_BASE                              (0x40013140u)
  /** Peripheral FREQME base pointer */
  #define FREQME                                   ((FREQME_Type *)FREQME_BASE)
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS                        { FREQME_BASE }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS                         { FREQME }
#endif
/** Interrupt vectors for the FREQME peripheral type */
#define FREQME_IRQS                              { Freqme_IRQn }

/* GINT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GINT0 base address */
  #define GINT0_BASE                               (0x50002000u)
  /** Peripheral GINT0 base address */
  #define GINT0_BASE_NS                            (0x40002000u)
  /** Peripheral GINT0 base pointer */
  #define GINT0                                    ((GINT_Type *)GINT0_BASE)
  /** Peripheral GINT0 base pointer */
  #define GINT0_NS                                 ((GINT_Type *)GINT0_BASE_NS)
  /** Peripheral GINT1 base address */
  #define GINT1_BASE                               (0x50003000u)
  /** Peripheral GINT1 base address */
  #define GINT1_BASE_NS                            (0x40003000u)
  /** Peripheral GINT1 base pointer */
  #define GINT1                                    ((GINT_Type *)GINT1_BASE)
  /** Peripheral GINT1 base pointer */
  #define GINT1_NS                                 ((GINT_Type *)GINT1_BASE_NS)
  /** Array initializer of GINT peripheral base addresses */
  #define GINT_BASE_ADDRS                          { GINT0_BASE, GINT1_BASE }
  /** Array initializer of GINT peripheral base pointers */
  #define GINT_BASE_PTRS                           { GINT0, GINT1 }
  /** Array initializer of GINT peripheral base addresses */
  #define GINT_BASE_ADDRS_NS                       { GINT0_BASE_NS, GINT1_BASE_NS }
  /** Array initializer of GINT peripheral base pointers */
  #define GINT_BASE_PTRS_NS                        { GINT0_NS, GINT1_NS }
#else
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
#endif
/** Interrupt vectors for the GINT peripheral type */
#define GINT_IRQS                                { GINT0_IRQn, GINT1_IRQn }

/* GPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPIO base address */
  #define GPIO_BASE                                (0x5008C000u)
  /** Peripheral GPIO base address */
  #define GPIO_BASE_NS                             (0x4008C000u)
  /** Peripheral GPIO base pointer */
  #define GPIO                                     ((GPIO_Type *)GPIO_BASE)
  /** Peripheral GPIO base pointer */
  #define GPIO_NS                                  ((GPIO_Type *)GPIO_BASE_NS)
  /** Peripheral SECGPIO base address */
  #define SECGPIO_BASE                             (0x500A8000u)
  /** Peripheral SECGPIO base address */
  #define SECGPIO_BASE_NS                          (0x400A8000u)
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
  #define GPIO_BASE                                (0x4008C000u)
  /** Peripheral GPIO base pointer */
  #define GPIO                                     ((GPIO_Type *)GPIO_BASE)
  /** Peripheral SECGPIO base address */
  #define SECGPIO_BASE                             (0x400A8000u)
  /** Peripheral SECGPIO base pointer */
  #define SECGPIO                                  ((GPIO_Type *)SECGPIO_BASE)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { GPIO_BASE, SECGPIO_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { GPIO, SECGPIO }
#endif

/* HSCMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSCMP0 base address */
  #define HSCMP0_BASE                              (0x500B3000u)
  /** Peripheral HSCMP0 base address */
  #define HSCMP0_BASE_NS                           (0x400B3000u)
  /** Peripheral HSCMP0 base pointer */
  #define HSCMP0                                   ((HSCMP_Type *)HSCMP0_BASE)
  /** Peripheral HSCMP0 base pointer */
  #define HSCMP0_NS                                ((HSCMP_Type *)HSCMP0_BASE_NS)
  /** Peripheral HSCMP1 base address */
  #define HSCMP1_BASE                              (0x500B7000u)
  /** Peripheral HSCMP1 base address */
  #define HSCMP1_BASE_NS                           (0x400B7000u)
  /** Peripheral HSCMP1 base pointer */
  #define HSCMP1                                   ((HSCMP_Type *)HSCMP1_BASE)
  /** Peripheral HSCMP1 base pointer */
  #define HSCMP1_NS                                ((HSCMP_Type *)HSCMP1_BASE_NS)
  /** Peripheral HSCMP2 base address */
  #define HSCMP2_BASE                              (0x500BA000u)
  /** Peripheral HSCMP2 base address */
  #define HSCMP2_BASE_NS                           (0x400BA000u)
  /** Peripheral HSCMP2 base pointer */
  #define HSCMP2                                   ((HSCMP_Type *)HSCMP2_BASE)
  /** Peripheral HSCMP2 base pointer */
  #define HSCMP2_NS                                ((HSCMP_Type *)HSCMP2_BASE_NS)
  /** Array initializer of HSCMP peripheral base addresses */
  #define HSCMP_BASE_ADDRS                         { HSCMP0_BASE, HSCMP1_BASE, HSCMP2_BASE }
  /** Array initializer of HSCMP peripheral base pointers */
  #define HSCMP_BASE_PTRS                          { HSCMP0, HSCMP1, HSCMP2 }
  /** Array initializer of HSCMP peripheral base addresses */
  #define HSCMP_BASE_ADDRS_NS                      { HSCMP0_BASE_NS, HSCMP1_BASE_NS, HSCMP2_BASE_NS }
  /** Array initializer of HSCMP peripheral base pointers */
  #define HSCMP_BASE_PTRS_NS                       { HSCMP0_NS, HSCMP1_NS, HSCMP2_NS }
#else
  /** Peripheral HSCMP0 base address */
  #define HSCMP0_BASE                              (0x400B3000u)
  /** Peripheral HSCMP0 base pointer */
  #define HSCMP0                                   ((HSCMP_Type *)HSCMP0_BASE)
  /** Peripheral HSCMP1 base address */
  #define HSCMP1_BASE                              (0x400B7000u)
  /** Peripheral HSCMP1 base pointer */
  #define HSCMP1                                   ((HSCMP_Type *)HSCMP1_BASE)
  /** Peripheral HSCMP2 base address */
  #define HSCMP2_BASE                              (0x400BA000u)
  /** Peripheral HSCMP2 base pointer */
  #define HSCMP2                                   ((HSCMP_Type *)HSCMP2_BASE)
  /** Array initializer of HSCMP peripheral base addresses */
  #define HSCMP_BASE_ADDRS                         { HSCMP0_BASE, HSCMP1_BASE, HSCMP2_BASE }
  /** Array initializer of HSCMP peripheral base pointers */
  #define HSCMP_BASE_PTRS                          { HSCMP0, HSCMP1, HSCMP2 }
#endif
/** Interrupt vectors for the HSCMP peripheral type */
#define HSCMP_IRQS                               { HSCMP0_IRQn, HSCMP1_IRQn, HSCMP2_IRQn }

/* I2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I2C0 base address */
  #define I2C0_BASE                                (0x50086000u)
  /** Peripheral I2C0 base address */
  #define I2C0_BASE_NS                             (0x40086000u)
  /** Peripheral I2C0 base pointer */
  #define I2C0                                     ((I2C_Type *)I2C0_BASE)
  /** Peripheral I2C0 base pointer */
  #define I2C0_NS                                  ((I2C_Type *)I2C0_BASE_NS)
  /** Peripheral I2C1 base address */
  #define I2C1_BASE                                (0x50087000u)
  /** Peripheral I2C1 base address */
  #define I2C1_BASE_NS                             (0x40087000u)
  /** Peripheral I2C1 base pointer */
  #define I2C1                                     ((I2C_Type *)I2C1_BASE)
  /** Peripheral I2C1 base pointer */
  #define I2C1_NS                                  ((I2C_Type *)I2C1_BASE_NS)
  /** Peripheral I2C2 base address */
  #define I2C2_BASE                                (0x50088000u)
  /** Peripheral I2C2 base address */
  #define I2C2_BASE_NS                             (0x40088000u)
  /** Peripheral I2C2 base pointer */
  #define I2C2                                     ((I2C_Type *)I2C2_BASE)
  /** Peripheral I2C2 base pointer */
  #define I2C2_NS                                  ((I2C_Type *)I2C2_BASE_NS)
  /** Peripheral I2C3 base address */
  #define I2C3_BASE                                (0x50089000u)
  /** Peripheral I2C3 base address */
  #define I2C3_BASE_NS                             (0x40089000u)
  /** Peripheral I2C3 base pointer */
  #define I2C3                                     ((I2C_Type *)I2C3_BASE)
  /** Peripheral I2C3 base pointer */
  #define I2C3_NS                                  ((I2C_Type *)I2C3_BASE_NS)
  /** Peripheral I2C4 base address */
  #define I2C4_BASE                                (0x5008A000u)
  /** Peripheral I2C4 base address */
  #define I2C4_BASE_NS                             (0x4008A000u)
  /** Peripheral I2C4 base pointer */
  #define I2C4                                     ((I2C_Type *)I2C4_BASE)
  /** Peripheral I2C4 base pointer */
  #define I2C4_NS                                  ((I2C_Type *)I2C4_BASE_NS)
  /** Peripheral I2C5 base address */
  #define I2C5_BASE                                (0x50096000u)
  /** Peripheral I2C5 base address */
  #define I2C5_BASE_NS                             (0x40096000u)
  /** Peripheral I2C5 base pointer */
  #define I2C5                                     ((I2C_Type *)I2C5_BASE)
  /** Peripheral I2C5 base pointer */
  #define I2C5_NS                                  ((I2C_Type *)I2C5_BASE_NS)
  /** Peripheral I2C6 base address */
  #define I2C6_BASE                                (0x50097000u)
  /** Peripheral I2C6 base address */
  #define I2C6_BASE_NS                             (0x40097000u)
  /** Peripheral I2C6 base pointer */
  #define I2C6                                     ((I2C_Type *)I2C6_BASE)
  /** Peripheral I2C6 base pointer */
  #define I2C6_NS                                  ((I2C_Type *)I2C6_BASE_NS)
  /** Peripheral I2C7 base address */
  #define I2C7_BASE                                (0x50098000u)
  /** Peripheral I2C7 base address */
  #define I2C7_BASE_NS                             (0x40098000u)
  /** Peripheral I2C7 base pointer */
  #define I2C7                                     ((I2C_Type *)I2C7_BASE)
  /** Peripheral I2C7 base pointer */
  #define I2C7_NS                                  ((I2C_Type *)I2C7_BASE_NS)
  /** Array initializer of I2C peripheral base addresses */
  #define I2C_BASE_ADDRS                           { I2C0_BASE, I2C1_BASE, I2C2_BASE, I2C3_BASE, I2C4_BASE, I2C5_BASE, I2C6_BASE, I2C7_BASE }
  /** Array initializer of I2C peripheral base pointers */
  #define I2C_BASE_PTRS                            { I2C0, I2C1, I2C2, I2C3, I2C4, I2C5, I2C6, I2C7 }
  /** Array initializer of I2C peripheral base addresses */
  #define I2C_BASE_ADDRS_NS                        { I2C0_BASE_NS, I2C1_BASE_NS, I2C2_BASE_NS, I2C3_BASE_NS, I2C4_BASE_NS, I2C5_BASE_NS, I2C6_BASE_NS, I2C7_BASE_NS }
  /** Array initializer of I2C peripheral base pointers */
  #define I2C_BASE_PTRS_NS                         { I2C0_NS, I2C1_NS, I2C2_NS, I2C3_NS, I2C4_NS, I2C5_NS, I2C6_NS, I2C7_NS }
#else
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
  /** Array initializer of I2C peripheral base addresses */
  #define I2C_BASE_ADDRS                           { I2C0_BASE, I2C1_BASE, I2C2_BASE, I2C3_BASE, I2C4_BASE, I2C5_BASE, I2C6_BASE, I2C7_BASE }
  /** Array initializer of I2C peripheral base pointers */
  #define I2C_BASE_PTRS                            { I2C0, I2C1, I2C2, I2C3, I2C4, I2C5, I2C6, I2C7 }
#endif
/** Interrupt vectors for the I2C peripheral type */
#define I2C_IRQS                                 { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn }

/* I2S - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I2S0 base address */
  #define I2S0_BASE                                (0x50086000u)
  /** Peripheral I2S0 base address */
  #define I2S0_BASE_NS                             (0x40086000u)
  /** Peripheral I2S0 base pointer */
  #define I2S0                                     ((I2S_Type *)I2S0_BASE)
  /** Peripheral I2S0 base pointer */
  #define I2S0_NS                                  ((I2S_Type *)I2S0_BASE_NS)
  /** Peripheral I2S1 base address */
  #define I2S1_BASE                                (0x50087000u)
  /** Peripheral I2S1 base address */
  #define I2S1_BASE_NS                             (0x40087000u)
  /** Peripheral I2S1 base pointer */
  #define I2S1                                     ((I2S_Type *)I2S1_BASE)
  /** Peripheral I2S1 base pointer */
  #define I2S1_NS                                  ((I2S_Type *)I2S1_BASE_NS)
  /** Peripheral I2S2 base address */
  #define I2S2_BASE                                (0x50088000u)
  /** Peripheral I2S2 base address */
  #define I2S2_BASE_NS                             (0x40088000u)
  /** Peripheral I2S2 base pointer */
  #define I2S2                                     ((I2S_Type *)I2S2_BASE)
  /** Peripheral I2S2 base pointer */
  #define I2S2_NS                                  ((I2S_Type *)I2S2_BASE_NS)
  /** Peripheral I2S3 base address */
  #define I2S3_BASE                                (0x50089000u)
  /** Peripheral I2S3 base address */
  #define I2S3_BASE_NS                             (0x40089000u)
  /** Peripheral I2S3 base pointer */
  #define I2S3                                     ((I2S_Type *)I2S3_BASE)
  /** Peripheral I2S3 base pointer */
  #define I2S3_NS                                  ((I2S_Type *)I2S3_BASE_NS)
  /** Peripheral I2S4 base address */
  #define I2S4_BASE                                (0x5008A000u)
  /** Peripheral I2S4 base address */
  #define I2S4_BASE_NS                             (0x4008A000u)
  /** Peripheral I2S4 base pointer */
  #define I2S4                                     ((I2S_Type *)I2S4_BASE)
  /** Peripheral I2S4 base pointer */
  #define I2S4_NS                                  ((I2S_Type *)I2S4_BASE_NS)
  /** Peripheral I2S5 base address */
  #define I2S5_BASE                                (0x50096000u)
  /** Peripheral I2S5 base address */
  #define I2S5_BASE_NS                             (0x40096000u)
  /** Peripheral I2S5 base pointer */
  #define I2S5                                     ((I2S_Type *)I2S5_BASE)
  /** Peripheral I2S5 base pointer */
  #define I2S5_NS                                  ((I2S_Type *)I2S5_BASE_NS)
  /** Peripheral I2S6 base address */
  #define I2S6_BASE                                (0x50097000u)
  /** Peripheral I2S6 base address */
  #define I2S6_BASE_NS                             (0x40097000u)
  /** Peripheral I2S6 base pointer */
  #define I2S6                                     ((I2S_Type *)I2S6_BASE)
  /** Peripheral I2S6 base pointer */
  #define I2S6_NS                                  ((I2S_Type *)I2S6_BASE_NS)
  /** Peripheral I2S7 base address */
  #define I2S7_BASE                                (0x50098000u)
  /** Peripheral I2S7 base address */
  #define I2S7_BASE_NS                             (0x40098000u)
  /** Peripheral I2S7 base pointer */
  #define I2S7                                     ((I2S_Type *)I2S7_BASE)
  /** Peripheral I2S7 base pointer */
  #define I2S7_NS                                  ((I2S_Type *)I2S7_BASE_NS)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { I2S0_BASE, I2S1_BASE, I2S2_BASE, I2S3_BASE, I2S4_BASE, I2S5_BASE, I2S6_BASE, I2S7_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { I2S0, I2S1, I2S2, I2S3, I2S4, I2S5, I2S6, I2S7 }
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS_NS                        { I2S0_BASE_NS, I2S1_BASE_NS, I2S2_BASE_NS, I2S3_BASE_NS, I2S4_BASE_NS, I2S5_BASE_NS, I2S6_BASE_NS, I2S7_BASE_NS }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS_NS                         { I2S0_NS, I2S1_NS, I2S2_NS, I2S3_NS, I2S4_NS, I2S5_NS, I2S6_NS, I2S7_NS }
#else
  /** Peripheral I2S0 base address */
  #define I2S0_BASE                                (0x40086000u)
  /** Peripheral I2S0 base pointer */
  #define I2S0                                     ((I2S_Type *)I2S0_BASE)
  /** Peripheral I2S1 base address */
  #define I2S1_BASE                                (0x40087000u)
  /** Peripheral I2S1 base pointer */
  #define I2S1                                     ((I2S_Type *)I2S1_BASE)
  /** Peripheral I2S2 base address */
  #define I2S2_BASE                                (0x40088000u)
  /** Peripheral I2S2 base pointer */
  #define I2S2                                     ((I2S_Type *)I2S2_BASE)
  /** Peripheral I2S3 base address */
  #define I2S3_BASE                                (0x40089000u)
  /** Peripheral I2S3 base pointer */
  #define I2S3                                     ((I2S_Type *)I2S3_BASE)
  /** Peripheral I2S4 base address */
  #define I2S4_BASE                                (0x4008A000u)
  /** Peripheral I2S4 base pointer */
  #define I2S4                                     ((I2S_Type *)I2S4_BASE)
  /** Peripheral I2S5 base address */
  #define I2S5_BASE                                (0x40096000u)
  /** Peripheral I2S5 base pointer */
  #define I2S5                                     ((I2S_Type *)I2S5_BASE)
  /** Peripheral I2S6 base address */
  #define I2S6_BASE                                (0x40097000u)
  /** Peripheral I2S6 base pointer */
  #define I2S6                                     ((I2S_Type *)I2S6_BASE)
  /** Peripheral I2S7 base address */
  #define I2S7_BASE                                (0x40098000u)
  /** Peripheral I2S7 base pointer */
  #define I2S7                                     ((I2S_Type *)I2S7_BASE)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { I2S0_BASE, I2S1_BASE, I2S2_BASE, I2S3_BASE, I2S4_BASE, I2S5_BASE, I2S6_BASE, I2S7_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { I2S0, I2S1, I2S2, I2S3, I2S4, I2S5, I2S6, I2S7 }
#endif
/** Interrupt vectors for the I2S peripheral type */
#define I2S_IRQS                                 { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn }

/* I3C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I3C0 base address */
  #define I3C0_BASE                                (0x50016000u)
  /** Peripheral I3C0 base address */
  #define I3C0_BASE_NS                             (0x40016000u)
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
  #define I3C0_BASE                                (0x40016000u)
  /** Peripheral I3C0 base pointer */
  #define I3C0                                     ((I3C_Type *)I3C0_BASE)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { I3C0_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { I3C0 }
#endif
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { I3C0_IRQn }

/* INPUTMUX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral INPUTMUX base address */
  #define INPUTMUX_BASE                            (0x50006000u)
  /** Peripheral INPUTMUX base address */
  #define INPUTMUX_BASE_NS                         (0x40006000u)
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
  #define INPUTMUX_BASE                            (0x40006000u)
  /** Peripheral INPUTMUX base pointer */
  #define INPUTMUX                                 ((INPUTMUX_Type *)INPUTMUX_BASE)
  /** Array initializer of INPUTMUX peripheral base addresses */
  #define INPUTMUX_BASE_ADDRS                      { INPUTMUX_BASE }
  /** Array initializer of INPUTMUX peripheral base pointers */
  #define INPUTMUX_BASE_PTRS                       { INPUTMUX }
#endif

/* IOCON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOCON base address */
  #define IOCON_BASE                               (0x50001000u)
  /** Peripheral IOCON base address */
  #define IOCON_BASE_NS                            (0x40001000u)
  /** Peripheral IOCON base pointer */
  #define IOCON                                    ((IOCON_Type *)IOCON_BASE)
  /** Peripheral IOCON base pointer */
  #define IOCON_NS                                 ((IOCON_Type *)IOCON_BASE_NS)
  /** Array initializer of IOCON peripheral base addresses */
  #define IOCON_BASE_ADDRS                         { IOCON_BASE }
  /** Array initializer of IOCON peripheral base pointers */
  #define IOCON_BASE_PTRS                          { IOCON }
  /** Array initializer of IOCON peripheral base addresses */
  #define IOCON_BASE_ADDRS_NS                      { IOCON_BASE_NS }
  /** Array initializer of IOCON peripheral base pointers */
  #define IOCON_BASE_PTRS_NS                       { IOCON_NS }
#else
  /** Peripheral IOCON base address */
  #define IOCON_BASE                               (0x40001000u)
  /** Peripheral IOCON base pointer */
  #define IOCON                                    ((IOCON_Type *)IOCON_BASE)
  /** Array initializer of IOCON peripheral base addresses */
  #define IOCON_BASE_ADDRS                         { IOCON_BASE }
  /** Array initializer of IOCON peripheral base pointers */
  #define IOCON_BASE_PTRS                          { IOCON }
#endif

/* LPDAC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DAC0 base address */
  #define DAC0_BASE                                (0x500B2000u)
  /** Peripheral DAC0 base address */
  #define DAC0_BASE_NS                             (0x400B2000u)
  /** Peripheral DAC0 base pointer */
  #define DAC0                                     ((LPDAC_Type *)DAC0_BASE)
  /** Peripheral DAC0 base pointer */
  #define DAC0_NS                                  ((LPDAC_Type *)DAC0_BASE_NS)
  /** Peripheral DAC1 base address */
  #define DAC1_BASE                                (0x500B6000u)
  /** Peripheral DAC1 base address */
  #define DAC1_BASE_NS                             (0x400B6000u)
  /** Peripheral DAC1 base pointer */
  #define DAC1                                     ((LPDAC_Type *)DAC1_BASE)
  /** Peripheral DAC1 base pointer */
  #define DAC1_NS                                  ((LPDAC_Type *)DAC1_BASE_NS)
  /** Peripheral DAC2 base address */
  #define DAC2_BASE                                (0x500B9000u)
  /** Peripheral DAC2 base address */
  #define DAC2_BASE_NS                             (0x400B9000u)
  /** Peripheral DAC2 base pointer */
  #define DAC2                                     ((LPDAC_Type *)DAC2_BASE)
  /** Peripheral DAC2 base pointer */
  #define DAC2_NS                                  ((LPDAC_Type *)DAC2_BASE_NS)
  /** Array initializer of LPDAC peripheral base addresses */
  #define LPDAC_BASE_ADDRS                         { DAC0_BASE, DAC1_BASE, DAC2_BASE }
  /** Array initializer of LPDAC peripheral base pointers */
  #define LPDAC_BASE_PTRS                          { DAC0, DAC1, DAC2 }
  /** Array initializer of LPDAC peripheral base addresses */
  #define LPDAC_BASE_ADDRS_NS                      { DAC0_BASE_NS, DAC1_BASE_NS, DAC2_BASE_NS }
  /** Array initializer of LPDAC peripheral base pointers */
  #define LPDAC_BASE_PTRS_NS                       { DAC0_NS, DAC1_NS, DAC2_NS }
#else
  /** Peripheral DAC0 base address */
  #define DAC0_BASE                                (0x400B2000u)
  /** Peripheral DAC0 base pointer */
  #define DAC0                                     ((LPDAC_Type *)DAC0_BASE)
  /** Peripheral DAC1 base address */
  #define DAC1_BASE                                (0x400B6000u)
  /** Peripheral DAC1 base pointer */
  #define DAC1                                     ((LPDAC_Type *)DAC1_BASE)
  /** Peripheral DAC2 base address */
  #define DAC2_BASE                                (0x400B9000u)
  /** Peripheral DAC2 base pointer */
  #define DAC2                                     ((LPDAC_Type *)DAC2_BASE)
  /** Array initializer of LPDAC peripheral base addresses */
  #define LPDAC_BASE_ADDRS                         { DAC0_BASE, DAC1_BASE, DAC2_BASE }
  /** Array initializer of LPDAC peripheral base pointers */
  #define LPDAC_BASE_PTRS                          { DAC0, DAC1, DAC2 }
#endif
/** Interrupt vectors for the LPDAC peripheral type */
#define LPDAC_IRQS                               { DAC0_IRQn, DAC1_IRQn, DAC2_IRQn }

/* MRT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MRT0 base address */
  #define MRT0_BASE                                (0x5000D000u)
  /** Peripheral MRT0 base address */
  #define MRT0_BASE_NS                             (0x4000D000u)
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
  #define MRT0_BASE                                (0x4000D000u)
  /** Peripheral MRT0 base pointer */
  #define MRT0                                     ((MRT_Type *)MRT0_BASE)
  /** Array initializer of MRT peripheral base addresses */
  #define MRT_BASE_ADDRS                           { MRT0_BASE }
  /** Array initializer of MRT peripheral base pointers */
  #define MRT_BASE_PTRS                            { MRT0 }
#endif
/** Interrupt vectors for the MRT peripheral type */
#define MRT_IRQS                                 { MRT0_IRQn }

/* OPAMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OPAMP0 base address */
  #define OPAMP0_BASE                              (0x500B4000u)
  /** Peripheral OPAMP0 base address */
  #define OPAMP0_BASE_NS                           (0x400B4000u)
  /** Peripheral OPAMP0 base pointer */
  #define OPAMP0                                   ((OPAMP_Type *)OPAMP0_BASE)
  /** Peripheral OPAMP0 base pointer */
  #define OPAMP0_NS                                ((OPAMP_Type *)OPAMP0_BASE_NS)
  /** Peripheral OPAMP1 base address */
  #define OPAMP1_BASE                              (0x500B8000u)
  /** Peripheral OPAMP1 base address */
  #define OPAMP1_BASE_NS                           (0x400B8000u)
  /** Peripheral OPAMP1 base pointer */
  #define OPAMP1                                   ((OPAMP_Type *)OPAMP1_BASE)
  /** Peripheral OPAMP1 base pointer */
  #define OPAMP1_NS                                ((OPAMP_Type *)OPAMP1_BASE_NS)
  /** Peripheral OPAMP2 base address */
  #define OPAMP2_BASE                              (0x500BB000u)
  /** Peripheral OPAMP2 base address */
  #define OPAMP2_BASE_NS                           (0x400BB000u)
  /** Peripheral OPAMP2 base pointer */
  #define OPAMP2                                   ((OPAMP_Type *)OPAMP2_BASE)
  /** Peripheral OPAMP2 base pointer */
  #define OPAMP2_NS                                ((OPAMP_Type *)OPAMP2_BASE_NS)
  /** Array initializer of OPAMP peripheral base addresses */
  #define OPAMP_BASE_ADDRS                         { OPAMP0_BASE, OPAMP1_BASE, OPAMP2_BASE }
  /** Array initializer of OPAMP peripheral base pointers */
  #define OPAMP_BASE_PTRS                          { OPAMP0, OPAMP1, OPAMP2 }
  /** Array initializer of OPAMP peripheral base addresses */
  #define OPAMP_BASE_ADDRS_NS                      { OPAMP0_BASE_NS, OPAMP1_BASE_NS, OPAMP2_BASE_NS }
  /** Array initializer of OPAMP peripheral base pointers */
  #define OPAMP_BASE_PTRS_NS                       { OPAMP0_NS, OPAMP1_NS, OPAMP2_NS }
#else
  /** Peripheral OPAMP0 base address */
  #define OPAMP0_BASE                              (0x400B4000u)
  /** Peripheral OPAMP0 base pointer */
  #define OPAMP0                                   ((OPAMP_Type *)OPAMP0_BASE)
  /** Peripheral OPAMP1 base address */
  #define OPAMP1_BASE                              (0x400B8000u)
  /** Peripheral OPAMP1 base pointer */
  #define OPAMP1                                   ((OPAMP_Type *)OPAMP1_BASE)
  /** Peripheral OPAMP2 base address */
  #define OPAMP2_BASE                              (0x400BB000u)
  /** Peripheral OPAMP2 base pointer */
  #define OPAMP2                                   ((OPAMP_Type *)OPAMP2_BASE)
  /** Array initializer of OPAMP peripheral base addresses */
  #define OPAMP_BASE_ADDRS                         { OPAMP0_BASE, OPAMP1_BASE, OPAMP2_BASE }
  /** Array initializer of OPAMP peripheral base pointers */
  #define OPAMP_BASE_PTRS                          { OPAMP0, OPAMP1, OPAMP2 }
#endif

/* OSTIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OSTIMER0 base address */
  #define OSTIMER0_BASE                            (0x5002D000u)
  /** Peripheral OSTIMER0 base address */
  #define OSTIMER0_BASE_NS                         (0x4002D000u)
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
  #define OSTIMER0_BASE                            (0x4002D000u)
  /** Peripheral OSTIMER0 base pointer */
  #define OSTIMER0                                 ((OSTIMER_Type *)OSTIMER0_BASE)
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS                       { OSTIMER0_BASE }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS                        { OSTIMER0 }
#endif
/** Interrupt vectors for the OSTIMER peripheral type */
#define OSTIMER_IRQS                             { OS_EVENT_IRQn }

/* PINT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PINT base address */
  #define PINT_BASE                                (0x50004000u)
  /** Peripheral PINT base address */
  #define PINT_BASE_NS                             (0x40004000u)
  /** Peripheral PINT base pointer */
  #define PINT                                     ((PINT_Type *)PINT_BASE)
  /** Peripheral PINT base pointer */
  #define PINT_NS                                  ((PINT_Type *)PINT_BASE_NS)
  /** Peripheral SECPINT base address */
  #define SECPINT_BASE                             (0x50005000u)
  /** Peripheral SECPINT base address */
  #define SECPINT_BASE_NS                          (0x40005000u)
  /** Peripheral SECPINT base pointer */
  #define SECPINT                                  ((PINT_Type *)SECPINT_BASE)
  /** Peripheral SECPINT base pointer */
  #define SECPINT_NS                               ((PINT_Type *)SECPINT_BASE_NS)
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS                          { PINT_BASE, SECPINT_BASE }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS                           { PINT, SECPINT }
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS_NS                       { PINT_BASE_NS, SECPINT_BASE_NS }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS_NS                        { PINT_NS, SECPINT_NS }
#else
  /** Peripheral PINT base address */
  #define PINT_BASE                                (0x40004000u)
  /** Peripheral PINT base pointer */
  #define PINT                                     ((PINT_Type *)PINT_BASE)
  /** Peripheral SECPINT base address */
  #define SECPINT_BASE                             (0x40005000u)
  /** Peripheral SECPINT base pointer */
  #define SECPINT                                  ((PINT_Type *)SECPINT_BASE)
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS                          { PINT_BASE, SECPINT_BASE }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS                           { PINT, SECPINT }
#endif
/** Interrupt vectors for the PINT peripheral type */
#define PINT_IRQS                                { PIN_INT0_IRQn, PIN_INT1_IRQn, PIN_INT2_IRQn, PIN_INT3_IRQn, PIN_INT4_IRQn, PIN_INT5_IRQn, PIN_INT6_IRQn, PIN_INT7_IRQn, SEC_GPIO_INT0_IRQ0_IRQn, SEC_GPIO_INT0_IRQ1_IRQn }

/* PMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PMC base address */
  #define PMC_BASE                                 (0x50020000u)
  /** Peripheral PMC base address */
  #define PMC_BASE_NS                              (0x40020000u)
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
  #define PMC_BASE                                 (0x40020000u)
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
  #define POWERQUAD_BASE                           (0x500A6000u)
  /** Peripheral POWERQUAD base address */
  #define POWERQUAD_BASE_NS                        (0x400A6000u)
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
  #define POWERQUAD_BASE                           (0x400A6000u)
  /** Peripheral POWERQUAD base pointer */
  #define POWERQUAD                                ((POWERQUAD_Type *)POWERQUAD_BASE)
  /** Array initializer of POWERQUAD peripheral base addresses */
  #define POWERQUAD_BASE_ADDRS                     { POWERQUAD_BASE }
  /** Array initializer of POWERQUAD peripheral base pointers */
  #define POWERQUAD_BASE_PTRS                      { POWERQUAD }
#endif
/** Interrupt vectors for the POWERQUAD peripheral type */
#define POWERQUAD_IRQS                           { POWERQUAD_IRQn }

/* PWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PWM0 base address */
  #define PWM0_BASE                                (0x500C3000u)
  /** Peripheral PWM0 base address */
  #define PWM0_BASE_NS                             (0x400C3000u)
  /** Peripheral PWM0 base pointer */
  #define PWM0                                     ((PWM_Type *)PWM0_BASE)
  /** Peripheral PWM0 base pointer */
  #define PWM0_NS                                  ((PWM_Type *)PWM0_BASE_NS)
  /** Peripheral PWM1 base address */
  #define PWM1_BASE                                (0x500C5000u)
  /** Peripheral PWM1 base address */
  #define PWM1_BASE_NS                             (0x400C5000u)
  /** Peripheral PWM1 base pointer */
  #define PWM1                                     ((PWM_Type *)PWM1_BASE)
  /** Peripheral PWM1 base pointer */
  #define PWM1_NS                                  ((PWM_Type *)PWM1_BASE_NS)
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS                           { PWM0_BASE, PWM1_BASE }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS                            { PWM0, PWM1 }
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS_NS                        { PWM0_BASE_NS, PWM1_BASE_NS }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS_NS                         { PWM0_NS, PWM1_NS }
#else
  /** Peripheral PWM0 base address */
  #define PWM0_BASE                                (0x400C3000u)
  /** Peripheral PWM0 base pointer */
  #define PWM0                                     ((PWM_Type *)PWM0_BASE)
  /** Peripheral PWM1 base address */
  #define PWM1_BASE                                (0x400C5000u)
  /** Peripheral PWM1 base pointer */
  #define PWM1                                     ((PWM_Type *)PWM1_BASE)
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS                           { PWM0_BASE, PWM1_BASE }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS                            { PWM0, PWM1 }
#endif
/** Interrupt vectors for the PWM peripheral type */
#define PWM_CMP_IRQS                             { { FLEXPWM0_COMPARE0_IRQn, FLEXPWM0_COMPARE1_IRQn, FLEXPWM0_COMPARE2_IRQn, FLEXPWM0_COMPARE3_IRQn }, { FLEXPWM1_COMPARE0_IRQn, FLEXPWM1_COMPARE1_IRQn, FLEXPWM1_COMPARE2_IRQn, FLEXPWM1_COMPARE3_IRQn } }
#define PWM_RELOAD_IRQS                          { { FLEXPWM0_RELOAD0_IRQn, FLEXPWM0_RELOAD1_IRQn, FLEXPWM0_RELOAD2_IRQn, FLEXPWM0_RELOAD3_IRQn }, { FLEXPWM1_RELOAD0_IRQn, FLEXPWM1_RELOAD1_IRQn, FLEXPWM1_RELOAD2_IRQn, FLEXPWM1_RELOAD3_IRQn } }
#define PWM_CAPTURE_IRQS                         { { FLEXPWM0_CAPTURE_IRQn, FLEXPWM0_CAPTURE_IRQn, FLEXPWM0_CAPTURE_IRQn, FLEXPWM0_CAPTURE_IRQn }, { FLEXPWM1_CAPTURE_IRQn, FLEXPWM1_CAPTURE_IRQn, FLEXPWM1_CAPTURE_IRQn, FLEXPWM1_CAPTURE_IRQn } }
#define PWM_FAULT_IRQS                           { FLEXPWM0_FAULT_IRQn, FLEXPWM1_FAULT_IRQn }
#define PWM_RELOAD_ERROR_IRQS                    { FLEXPWM0_RELOAD_ERROR_IRQn, FLEXPWM1_RELOAD_ERROR_IRQn }

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
#define RTC_IRQS                                 { RTC_IRQn }

/* SCT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SCT0 base address */
  #define SCT0_BASE                                (0x50085000u)
  /** Peripheral SCT0 base address */
  #define SCT0_BASE_NS                             (0x40085000u)
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
  #define SCT0_BASE                                (0x40085000u)
  /** Peripheral SCT0 base pointer */
  #define SCT0                                     ((SCT_Type *)SCT0_BASE)
  /** Array initializer of SCT peripheral base addresses */
  #define SCT_BASE_ADDRS                           { SCT0_BASE }
  /** Array initializer of SCT peripheral base pointers */
  #define SCT_BASE_PTRS                            { SCT0 }
#endif
/** Interrupt vectors for the SCT peripheral type */
#define SCT_IRQS                                 { SCT0_IRQn }

/* SPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SPI0 base address */
  #define SPI0_BASE                                (0x50086000u)
  /** Peripheral SPI0 base address */
  #define SPI0_BASE_NS                             (0x40086000u)
  /** Peripheral SPI0 base pointer */
  #define SPI0                                     ((SPI_Type *)SPI0_BASE)
  /** Peripheral SPI0 base pointer */
  #define SPI0_NS                                  ((SPI_Type *)SPI0_BASE_NS)
  /** Peripheral SPI1 base address */
  #define SPI1_BASE                                (0x50087000u)
  /** Peripheral SPI1 base address */
  #define SPI1_BASE_NS                             (0x40087000u)
  /** Peripheral SPI1 base pointer */
  #define SPI1                                     ((SPI_Type *)SPI1_BASE)
  /** Peripheral SPI1 base pointer */
  #define SPI1_NS                                  ((SPI_Type *)SPI1_BASE_NS)
  /** Peripheral SPI2 base address */
  #define SPI2_BASE                                (0x50088000u)
  /** Peripheral SPI2 base address */
  #define SPI2_BASE_NS                             (0x40088000u)
  /** Peripheral SPI2 base pointer */
  #define SPI2                                     ((SPI_Type *)SPI2_BASE)
  /** Peripheral SPI2 base pointer */
  #define SPI2_NS                                  ((SPI_Type *)SPI2_BASE_NS)
  /** Peripheral SPI3 base address */
  #define SPI3_BASE                                (0x50089000u)
  /** Peripheral SPI3 base address */
  #define SPI3_BASE_NS                             (0x40089000u)
  /** Peripheral SPI3 base pointer */
  #define SPI3                                     ((SPI_Type *)SPI3_BASE)
  /** Peripheral SPI3 base pointer */
  #define SPI3_NS                                  ((SPI_Type *)SPI3_BASE_NS)
  /** Peripheral SPI4 base address */
  #define SPI4_BASE                                (0x5008A000u)
  /** Peripheral SPI4 base address */
  #define SPI4_BASE_NS                             (0x4008A000u)
  /** Peripheral SPI4 base pointer */
  #define SPI4                                     ((SPI_Type *)SPI4_BASE)
  /** Peripheral SPI4 base pointer */
  #define SPI4_NS                                  ((SPI_Type *)SPI4_BASE_NS)
  /** Peripheral SPI5 base address */
  #define SPI5_BASE                                (0x50096000u)
  /** Peripheral SPI5 base address */
  #define SPI5_BASE_NS                             (0x40096000u)
  /** Peripheral SPI5 base pointer */
  #define SPI5                                     ((SPI_Type *)SPI5_BASE)
  /** Peripheral SPI5 base pointer */
  #define SPI5_NS                                  ((SPI_Type *)SPI5_BASE_NS)
  /** Peripheral SPI6 base address */
  #define SPI6_BASE                                (0x50097000u)
  /** Peripheral SPI6 base address */
  #define SPI6_BASE_NS                             (0x40097000u)
  /** Peripheral SPI6 base pointer */
  #define SPI6                                     ((SPI_Type *)SPI6_BASE)
  /** Peripheral SPI6 base pointer */
  #define SPI6_NS                                  ((SPI_Type *)SPI6_BASE_NS)
  /** Peripheral SPI7 base address */
  #define SPI7_BASE                                (0x50098000u)
  /** Peripheral SPI7 base address */
  #define SPI7_BASE_NS                             (0x40098000u)
  /** Peripheral SPI7 base pointer */
  #define SPI7                                     ((SPI_Type *)SPI7_BASE)
  /** Peripheral SPI7 base pointer */
  #define SPI7_NS                                  ((SPI_Type *)SPI7_BASE_NS)
  /** Peripheral SPI8 base address */
  #define SPI8_BASE                                (0x5009F000u)
  /** Peripheral SPI8 base address */
  #define SPI8_BASE_NS                             (0x4009F000u)
  /** Peripheral SPI8 base pointer */
  #define SPI8                                     ((SPI_Type *)SPI8_BASE)
  /** Peripheral SPI8 base pointer */
  #define SPI8_NS                                  ((SPI_Type *)SPI8_BASE_NS)
  /** Array initializer of SPI peripheral base addresses */
  #define SPI_BASE_ADDRS                           { SPI0_BASE, SPI1_BASE, SPI2_BASE, SPI3_BASE, SPI4_BASE, SPI5_BASE, SPI6_BASE, SPI7_BASE, SPI8_BASE }
  /** Array initializer of SPI peripheral base pointers */
  #define SPI_BASE_PTRS                            { SPI0, SPI1, SPI2, SPI3, SPI4, SPI5, SPI6, SPI7, SPI8 }
  /** Array initializer of SPI peripheral base addresses */
  #define SPI_BASE_ADDRS_NS                        { SPI0_BASE_NS, SPI1_BASE_NS, SPI2_BASE_NS, SPI3_BASE_NS, SPI4_BASE_NS, SPI5_BASE_NS, SPI6_BASE_NS, SPI7_BASE_NS, SPI8_BASE_NS }
  /** Array initializer of SPI peripheral base pointers */
  #define SPI_BASE_PTRS_NS                         { SPI0_NS, SPI1_NS, SPI2_NS, SPI3_NS, SPI4_NS, SPI5_NS, SPI6_NS, SPI7_NS, SPI8_NS }
#else
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
  #define SPI8_BASE                                (0x4009F000u)
  /** Peripheral SPI8 base pointer */
  #define SPI8                                     ((SPI_Type *)SPI8_BASE)
  /** Array initializer of SPI peripheral base addresses */
  #define SPI_BASE_ADDRS                           { SPI0_BASE, SPI1_BASE, SPI2_BASE, SPI3_BASE, SPI4_BASE, SPI5_BASE, SPI6_BASE, SPI7_BASE, SPI8_BASE }
  /** Array initializer of SPI peripheral base pointers */
  #define SPI_BASE_PTRS                            { SPI0, SPI1, SPI2, SPI3, SPI4, SPI5, SPI6, SPI7, SPI8 }
#endif
/** Interrupt vectors for the SPI peripheral type */
#define SPI_IRQS                                 { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn, FLEXCOMM8_IRQn }

/* SYSCON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON base address */
  #define SYSCON_BASE                              (0x50000000u)
  /** Peripheral SYSCON base address */
  #define SYSCON_BASE_NS                           (0x40000000u)
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
  #define SYSCON_BASE                              (0x40000000u)
  /** Peripheral SYSCON base pointer */
  #define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
  /** Array initializer of SYSCON peripheral base addresses */
  #define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
  /** Array initializer of SYSCON peripheral base pointers */
  #define SYSCON_BASE_PTRS                         { SYSCON }
#endif

/* SYSCTL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCTL base address */
  #define SYSCTL_BASE                              (0x50023000u)
  /** Peripheral SYSCTL base address */
  #define SYSCTL_BASE_NS                           (0x40023000u)
  /** Peripheral SYSCTL base pointer */
  #define SYSCTL                                   ((SYSCTL_Type *)SYSCTL_BASE)
  /** Peripheral SYSCTL base pointer */
  #define SYSCTL_NS                                ((SYSCTL_Type *)SYSCTL_BASE_NS)
  /** Array initializer of SYSCTL peripheral base addresses */
  #define SYSCTL_BASE_ADDRS                        { SYSCTL_BASE }
  /** Array initializer of SYSCTL peripheral base pointers */
  #define SYSCTL_BASE_PTRS                         { SYSCTL }
  /** Array initializer of SYSCTL peripheral base addresses */
  #define SYSCTL_BASE_ADDRS_NS                     { SYSCTL_BASE_NS }
  /** Array initializer of SYSCTL peripheral base pointers */
  #define SYSCTL_BASE_PTRS_NS                      { SYSCTL_NS }
#else
  /** Peripheral SYSCTL base address */
  #define SYSCTL_BASE                              (0x40023000u)
  /** Peripheral SYSCTL base pointer */
  #define SYSCTL                                   ((SYSCTL_Type *)SYSCTL_BASE)
  /** Array initializer of SYSCTL peripheral base addresses */
  #define SYSCTL_BASE_ADDRS                        { SYSCTL_BASE }
  /** Array initializer of SYSCTL peripheral base pointers */
  #define SYSCTL_BASE_PTRS                         { SYSCTL }
#endif

/* USART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USART0 base address */
  #define USART0_BASE                              (0x50086000u)
  /** Peripheral USART0 base address */
  #define USART0_BASE_NS                           (0x40086000u)
  /** Peripheral USART0 base pointer */
  #define USART0                                   ((USART_Type *)USART0_BASE)
  /** Peripheral USART0 base pointer */
  #define USART0_NS                                ((USART_Type *)USART0_BASE_NS)
  /** Peripheral USART1 base address */
  #define USART1_BASE                              (0x50087000u)
  /** Peripheral USART1 base address */
  #define USART1_BASE_NS                           (0x40087000u)
  /** Peripheral USART1 base pointer */
  #define USART1                                   ((USART_Type *)USART1_BASE)
  /** Peripheral USART1 base pointer */
  #define USART1_NS                                ((USART_Type *)USART1_BASE_NS)
  /** Peripheral USART2 base address */
  #define USART2_BASE                              (0x50088000u)
  /** Peripheral USART2 base address */
  #define USART2_BASE_NS                           (0x40088000u)
  /** Peripheral USART2 base pointer */
  #define USART2                                   ((USART_Type *)USART2_BASE)
  /** Peripheral USART2 base pointer */
  #define USART2_NS                                ((USART_Type *)USART2_BASE_NS)
  /** Peripheral USART3 base address */
  #define USART3_BASE                              (0x50089000u)
  /** Peripheral USART3 base address */
  #define USART3_BASE_NS                           (0x40089000u)
  /** Peripheral USART3 base pointer */
  #define USART3                                   ((USART_Type *)USART3_BASE)
  /** Peripheral USART3 base pointer */
  #define USART3_NS                                ((USART_Type *)USART3_BASE_NS)
  /** Peripheral USART4 base address */
  #define USART4_BASE                              (0x5008A000u)
  /** Peripheral USART4 base address */
  #define USART4_BASE_NS                           (0x4008A000u)
  /** Peripheral USART4 base pointer */
  #define USART4                                   ((USART_Type *)USART4_BASE)
  /** Peripheral USART4 base pointer */
  #define USART4_NS                                ((USART_Type *)USART4_BASE_NS)
  /** Peripheral USART5 base address */
  #define USART5_BASE                              (0x50096000u)
  /** Peripheral USART5 base address */
  #define USART5_BASE_NS                           (0x40096000u)
  /** Peripheral USART5 base pointer */
  #define USART5                                   ((USART_Type *)USART5_BASE)
  /** Peripheral USART5 base pointer */
  #define USART5_NS                                ((USART_Type *)USART5_BASE_NS)
  /** Peripheral USART6 base address */
  #define USART6_BASE                              (0x50097000u)
  /** Peripheral USART6 base address */
  #define USART6_BASE_NS                           (0x40097000u)
  /** Peripheral USART6 base pointer */
  #define USART6                                   ((USART_Type *)USART6_BASE)
  /** Peripheral USART6 base pointer */
  #define USART6_NS                                ((USART_Type *)USART6_BASE_NS)
  /** Peripheral USART7 base address */
  #define USART7_BASE                              (0x50098000u)
  /** Peripheral USART7 base address */
  #define USART7_BASE_NS                           (0x40098000u)
  /** Peripheral USART7 base pointer */
  #define USART7                                   ((USART_Type *)USART7_BASE)
  /** Peripheral USART7 base pointer */
  #define USART7_NS                                ((USART_Type *)USART7_BASE_NS)
  /** Array initializer of USART peripheral base addresses */
  #define USART_BASE_ADDRS                         { USART0_BASE, USART1_BASE, USART2_BASE, USART3_BASE, USART4_BASE, USART5_BASE, USART6_BASE, USART7_BASE }
  /** Array initializer of USART peripheral base pointers */
  #define USART_BASE_PTRS                          { USART0, USART1, USART2, USART3, USART4, USART5, USART6, USART7 }
  /** Array initializer of USART peripheral base addresses */
  #define USART_BASE_ADDRS_NS                      { USART0_BASE_NS, USART1_BASE_NS, USART2_BASE_NS, USART3_BASE_NS, USART4_BASE_NS, USART5_BASE_NS, USART6_BASE_NS, USART7_BASE_NS }
  /** Array initializer of USART peripheral base pointers */
  #define USART_BASE_PTRS_NS                       { USART0_NS, USART1_NS, USART2_NS, USART3_NS, USART4_NS, USART5_NS, USART6_NS, USART7_NS }
#else
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
  /** Array initializer of USART peripheral base addresses */
  #define USART_BASE_ADDRS                         { USART0_BASE, USART1_BASE, USART2_BASE, USART3_BASE, USART4_BASE, USART5_BASE, USART6_BASE, USART7_BASE }
  /** Array initializer of USART peripheral base pointers */
  #define USART_BASE_PTRS                          { USART0, USART1, USART2, USART3, USART4, USART5, USART6, USART7 }
#endif
/** Interrupt vectors for the USART peripheral type */
#define USART_IRQS                               { FLEXCOMM0_IRQn, FLEXCOMM1_IRQn, FLEXCOMM2_IRQn, FLEXCOMM3_IRQn, FLEXCOMM4_IRQn, FLEXCOMM5_IRQn, FLEXCOMM6_IRQn, FLEXCOMM7_IRQn }

/* USB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USB0 base address */
  #define USB0_BASE                                (0x50084000u)
  /** Peripheral USB0 base address */
  #define USB0_BASE_NS                             (0x40084000u)
  /** Peripheral USB0 base pointer */
  #define USB0                                     ((USB_Type *)USB0_BASE)
  /** Peripheral USB0 base pointer */
  #define USB0_NS                                  ((USB_Type *)USB0_BASE_NS)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { USB0_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { USB0 }
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS_NS                        { USB0_BASE_NS }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS_NS                         { USB0_NS }
#else
  /** Peripheral USB0 base address */
  #define USB0_BASE                                (0x40084000u)
  /** Peripheral USB0 base pointer */
  #define USB0                                     ((USB_Type *)USB0_BASE)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { USB0_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { USB0 }
#endif
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { USB0_IRQn }
#define USB_NEEDCLK_IRQS                         { USB0_NEEDCLK_IRQn }

/* USBFSH - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBFSH base address */
  #define USBFSH_BASE                              (0x500A2000u)
  /** Peripheral USBFSH base address */
  #define USBFSH_BASE_NS                           (0x400A2000u)
  /** Peripheral USBFSH base pointer */
  #define USBFSH                                   ((USBFSH_Type *)USBFSH_BASE)
  /** Peripheral USBFSH base pointer */
  #define USBFSH_NS                                ((USBFSH_Type *)USBFSH_BASE_NS)
  /** Array initializer of USBFSH peripheral base addresses */
  #define USBFSH_BASE_ADDRS                        { USBFSH_BASE }
  /** Array initializer of USBFSH peripheral base pointers */
  #define USBFSH_BASE_PTRS                         { USBFSH }
  /** Array initializer of USBFSH peripheral base addresses */
  #define USBFSH_BASE_ADDRS_NS                     { USBFSH_BASE_NS }
  /** Array initializer of USBFSH peripheral base pointers */
  #define USBFSH_BASE_PTRS_NS                      { USBFSH_NS }
#else
  /** Peripheral USBFSH base address */
  #define USBFSH_BASE                              (0x400A2000u)
  /** Peripheral USBFSH base pointer */
  #define USBFSH                                   ((USBFSH_Type *)USBFSH_BASE)
  /** Array initializer of USBFSH peripheral base addresses */
  #define USBFSH_BASE_ADDRS                        { USBFSH_BASE }
  /** Array initializer of USBFSH peripheral base pointers */
  #define USBFSH_BASE_PTRS                         { USBFSH }
#endif
/** Interrupt vectors for the USBFSH peripheral type */
#define USBFSH_IRQS                              { USB0_IRQn }
#define USBFSH_NEEDCLK_IRQS                      { USB0_NEEDCLK_IRQn }

/* UTICK - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral UTICK0 base address */
  #define UTICK0_BASE                              (0x5000E000u)
  /** Peripheral UTICK0 base address */
  #define UTICK0_BASE_NS                           (0x4000E000u)
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
  #define UTICK0_BASE                              (0x4000E000u)
  /** Peripheral UTICK0 base pointer */
  #define UTICK0                                   ((UTICK_Type *)UTICK0_BASE)
  /** Array initializer of UTICK peripheral base addresses */
  #define UTICK_BASE_ADDRS                         { UTICK0_BASE }
  /** Array initializer of UTICK peripheral base pointers */
  #define UTICK_BASE_PTRS                          { UTICK0 }
#endif
/** Interrupt vectors for the UTICK peripheral type */
#define UTICK_IRQS                               { UTICK0_IRQn }

/* VREF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VREF base address */
  #define VREF_BASE                                (0x500B5000u)
  /** Peripheral VREF base address */
  #define VREF_BASE_NS                             (0x400B5000u)
  /** Peripheral VREF base pointer */
  #define VREF                                     ((VREF_Type *)VREF_BASE)
  /** Peripheral VREF base pointer */
  #define VREF_NS                                  ((VREF_Type *)VREF_BASE_NS)
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS                          { VREF_BASE }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS                           { VREF }
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS_NS                       { VREF_BASE_NS }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS_NS                        { VREF_NS }
#else
  /** Peripheral VREF base address */
  #define VREF_BASE                                (0x400B5000u)
  /** Peripheral VREF base pointer */
  #define VREF                                     ((VREF_Type *)VREF_BASE)
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS                          { VREF_BASE }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS                           { VREF }
#endif

/* WWDT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WWDT base address */
  #define WWDT_BASE                                (0x5000C000u)
  /** Peripheral WWDT base address */
  #define WWDT_BASE_NS                             (0x4000C000u)
  /** Peripheral WWDT base pointer */
  #define WWDT                                     ((WWDT_Type *)WWDT_BASE)
  /** Peripheral WWDT base pointer */
  #define WWDT_NS                                  ((WWDT_Type *)WWDT_BASE_NS)
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS                          { WWDT_BASE }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS                           { WWDT }
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS_NS                       { WWDT_BASE_NS }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS_NS                        { WWDT_NS }
#else
  /** Peripheral WWDT base address */
  #define WWDT_BASE                                (0x4000C000u)
  /** Peripheral WWDT base pointer */
  #define WWDT                                     ((WWDT_Type *)WWDT_BASE)
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS                          { WWDT_BASE }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS                           { WWDT }
#endif
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

/** AHB Secure Control */
#if defined(SECTRL0)
    #define AHB_SECURE_CTRL                                SECTRL0
#endif


/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* LPC5536_COMMON_H_ */

