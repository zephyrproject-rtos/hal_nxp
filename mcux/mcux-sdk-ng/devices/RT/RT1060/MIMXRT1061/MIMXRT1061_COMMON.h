/*
** ###################################################################
**     Processors:          MIMXRT1061CVJ5A
**                          MIMXRT1061CVJ5B
**                          MIMXRT1061CVL5A
**                          MIMXRT1061CVL5B
**                          MIMXRT1061DVJ6A
**                          MIMXRT1061DVJ6B
**                          MIMXRT1061DVL6A
**                          MIMXRT1061DVL6B
**                          MIMXRT1061XVN5B
**
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    IMXRT1060RM Rev.3, 07/2021 | IMXRT106XSRM Rev.0
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT1061
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1060RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1060RM Rev.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1060RM Rev.3.
**     - rev. 1.4 (2022-03-25)
**         Add RT1060X device
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMXRT1061_COMMON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMXRT1061
 *
 * CMSIS Peripheral Access Layer for MIMXRT1061
 */

#if !defined(MIMXRT1061_COMMON_H_)
#define MIMXRT1061_COMMON_H_                     /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 174                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M7 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M7 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M7 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M7 Usage Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M7 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M7 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M7 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M7 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_DMA16_IRQn              = 0,                /**< DMA channel 0/16 transfer complete */
  DMA1_DMA17_IRQn              = 1,                /**< DMA channel 1/17 transfer complete */
  DMA2_DMA18_IRQn              = 2,                /**< DMA channel 2/18 transfer complete */
  DMA3_DMA19_IRQn              = 3,                /**< DMA channel 3/19 transfer complete */
  DMA4_DMA20_IRQn              = 4,                /**< DMA channel 4/20 transfer complete */
  DMA5_DMA21_IRQn              = 5,                /**< DMA channel 5/21 transfer complete */
  DMA6_DMA22_IRQn              = 6,                /**< DMA channel 6/22 transfer complete */
  DMA7_DMA23_IRQn              = 7,                /**< DMA channel 7/23 transfer complete */
  DMA8_DMA24_IRQn              = 8,                /**< DMA channel 8/24 transfer complete */
  DMA9_DMA25_IRQn              = 9,                /**< DMA channel 9/25 transfer complete */
  DMA10_DMA26_IRQn             = 10,               /**< DMA channel 10/26 transfer complete */
  DMA11_DMA27_IRQn             = 11,               /**< DMA channel 11/27 transfer complete */
  DMA12_DMA28_IRQn             = 12,               /**< DMA channel 12/28 transfer complete */
  DMA13_DMA29_IRQn             = 13,               /**< DMA channel 13/29 transfer complete */
  DMA14_DMA30_IRQn             = 14,               /**< DMA channel 14/30 transfer complete */
  DMA15_DMA31_IRQn             = 15,               /**< DMA channel 15/31 transfer complete */
  DMA_ERROR_IRQn               = 16,               /**< DMA error interrupt channels 0-15 / 16-31 */
  CTI0_ERROR_IRQn              = 17,               /**< CTI0_Error */
  CTI1_ERROR_IRQn              = 18,               /**< CTI1_Error */
  CORE_IRQn                    = 19,               /**< CorePlatform exception IRQ */
  LPUART1_IRQn                 = 20,               /**< LPUART1 TX interrupt and RX interrupt */
  LPUART2_IRQn                 = 21,               /**< LPUART2 TX interrupt and RX interrupt */
  LPUART3_IRQn                 = 22,               /**< LPUART3 TX interrupt and RX interrupt */
  LPUART4_IRQn                 = 23,               /**< LPUART4 TX interrupt and RX interrupt */
  LPUART5_IRQn                 = 24,               /**< LPUART5 TX interrupt and RX interrupt */
  LPUART6_IRQn                 = 25,               /**< LPUART6 TX interrupt and RX interrupt */
  LPUART7_IRQn                 = 26,               /**< LPUART7 TX interrupt and RX interrupt */
  LPUART8_IRQn                 = 27,               /**< LPUART8 TX interrupt and RX interrupt */
  LPI2C1_IRQn                  = 28,               /**< LPI2C1 interrupt */
  LPI2C2_IRQn                  = 29,               /**< LPI2C2 interrupt */
  LPI2C3_IRQn                  = 30,               /**< LPI2C3 interrupt */
  LPI2C4_IRQn                  = 31,               /**< LPI2C4 interrupt */
  LPSPI1_IRQn                  = 32,               /**< LPSPI1 single interrupt vector for all sources */
  LPSPI2_IRQn                  = 33,               /**< LPSPI2 single interrupt vector for all sources */
  LPSPI3_IRQn                  = 34,               /**< LPSPI3 single interrupt vector for all sources */
  LPSPI4_IRQn                  = 35,               /**< LPSPI4  single interrupt vector for all sources */
  CAN1_IRQn                    = 36,               /**< CAN1 interrupt */
  CAN2_IRQn                    = 37,               /**< CAN2 interrupt */
  FLEXRAM_IRQn                 = 38,               /**< FlexRAM address out of range Or access hit IRQ */
  KPP_IRQn                     = 39,               /**< Keypad nterrupt */
  TSC_DIG_IRQn                 = 40,               /**< TSC interrupt */
  GPR_IRQ_IRQn                 = 41,               /**< GPR interrupt */
  Reserved58_IRQn              = 42,               /**< Reserved interrupt */
  Reserved59_IRQn              = 43,               /**< Reserved interrupt */
  Reserved60_IRQn              = 44,               /**< Reserved interrupt */
  WDOG2_IRQn                   = 45,               /**< WDOG2 interrupt */
  SNVS_HP_WRAPPER_IRQn         = 46,               /**< SRTC Consolidated Interrupt. Non TZ */
  SNVS_HP_WRAPPER_TZ_IRQn      = 47,               /**< SRTC Security Interrupt. TZ */
  SNVS_LP_WRAPPER_IRQn         = 48,               /**< ON-OFF button press shorter than 5 secs (pulse event) */
  CSU_IRQn                     = 49,               /**< CSU interrupt */
  DCP_IRQn                     = 50,               /**< DCP_IRQ interrupt */
  DCP_VMI_IRQn                 = 51,               /**< DCP_VMI_IRQ interrupt */
  Reserved68_IRQn              = 52,               /**< Reserved interrupt */
  TRNG_IRQn                    = 53,               /**< TRNG interrupt */
  SJC_IRQn                     = 54,               /**< SJC interrupt */
  BEE_IRQn                     = 55,               /**< BEE interrupt */
  SAI1_IRQn                    = 56,               /**< SAI1 interrupt */
  SAI2_IRQn                    = 57,               /**< SAI1 interrupt */
  SAI3_RX_IRQn                 = 58,               /**< SAI3 interrupt */
  SAI3_TX_IRQn                 = 59,               /**< SAI3 interrupt */
  SPDIF_IRQn                   = 60,               /**< SPDIF interrupt */
  PMU_EVENT_IRQn               = 61,               /**< Brown-out event interrupt */
  Reserved78_IRQn              = 62,               /**< Reserved interrupt */
  TEMP_LOW_HIGH_IRQn           = 63,               /**< TempSensor low/high interrupt */
  TEMP_PANIC_IRQn              = 64,               /**< TempSensor panic interrupt */
  USB_PHY1_IRQn                = 65,               /**< USBPHY (UTMI0), Interrupt */
  USB_PHY2_IRQn                = 66,               /**< USBPHY (UTMI1), Interrupt */
  ADC1_IRQn                    = 67,               /**< ADC1 interrupt */
  ADC2_IRQn                    = 68,               /**< ADC2 interrupt */
  DCDC_IRQn                    = 69,               /**< DCDC interrupt */
  Reserved86_IRQn              = 70,               /**< Reserved interrupt */
  GPIO10_Combined_0_31_IRQn    = 71,               /**< Combined interrupt indication for GPIO10 signal 0 throughout 31 */
  GPIO1_INT0_IRQn              = 72,               /**< Active HIGH Interrupt from INT0 from GPIO */
  GPIO1_INT1_IRQn              = 73,               /**< Active HIGH Interrupt from INT1 from GPIO */
  GPIO1_INT2_IRQn              = 74,               /**< Active HIGH Interrupt from INT2 from GPIO */
  GPIO1_INT3_IRQn              = 75,               /**< Active HIGH Interrupt from INT3 from GPIO */
  GPIO1_INT4_IRQn              = 76,               /**< Active HIGH Interrupt from INT4 from GPIO */
  GPIO1_INT5_IRQn              = 77,               /**< Active HIGH Interrupt from INT5 from GPIO */
  GPIO1_INT6_IRQn              = 78,               /**< Active HIGH Interrupt from INT6 from GPIO */
  GPIO1_INT7_IRQn              = 79,               /**< Active HIGH Interrupt from INT7 from GPIO */
  GPIO1_Combined_0_15_IRQn     = 80,               /**< Combined interrupt indication for GPIO1 signal 0 throughout 15 */
  GPIO1_Combined_16_31_IRQn    = 81,               /**< Combined interrupt indication for GPIO1 signal 16 throughout 31 */
  GPIO2_Combined_0_15_IRQn     = 82,               /**< Combined interrupt indication for GPIO2 signal 0 throughout 15 */
  GPIO2_Combined_16_31_IRQn    = 83,               /**< Combined interrupt indication for GPIO2 signal 16 throughout 31 */
  GPIO3_Combined_0_15_IRQn     = 84,               /**< Combined interrupt indication for GPIO3 signal 0 throughout 15 */
  GPIO3_Combined_16_31_IRQn    = 85,               /**< Combined interrupt indication for GPIO3 signal 16 throughout 31 */
  GPIO4_Combined_0_15_IRQn     = 86,               /**< Combined interrupt indication for GPIO4 signal 0 throughout 15 */
  GPIO4_Combined_16_31_IRQn    = 87,               /**< Combined interrupt indication for GPIO4 signal 16 throughout 31 */
  GPIO5_Combined_0_15_IRQn     = 88,               /**< Combined interrupt indication for GPIO5 signal 0 throughout 15 */
  GPIO5_Combined_16_31_IRQn    = 89,               /**< Combined interrupt indication for GPIO5 signal 16 throughout 31 */
  FLEXIO1_IRQn                 = 90,               /**< FLEXIO1 interrupt */
  FLEXIO2_IRQn                 = 91,               /**< FLEXIO2 interrupt */
  WDOG1_IRQn                   = 92,               /**< WDOG1 interrupt */
  RTWDOG_IRQn                  = 93,               /**< RTWDOG interrupt */
  EWM_IRQn                     = 94,               /**< EWM interrupt */
  CCM_1_IRQn                   = 95,               /**< CCM IRQ1 interrupt */
  CCM_2_IRQn                   = 96,               /**< CCM IRQ2 interrupt */
  GPC_IRQn                     = 97,               /**< GPC interrupt */
  SRC_IRQn                     = 98,               /**< SRC interrupt */
  Reserved115_IRQn             = 99,               /**< Reserved interrupt */
  GPT1_IRQn                    = 100,              /**< GPT1 interrupt */
  GPT2_IRQn                    = 101,              /**< GPT2 interrupt */
  PWM1_0_IRQn                  = 102,              /**< PWM1 capture 0, compare 0, or reload 0 interrupt */
  PWM1_1_IRQn                  = 103,              /**< PWM1 capture 1, compare 1, or reload 0 interrupt */
  PWM1_2_IRQn                  = 104,              /**< PWM1 capture 2, compare 2, or reload 0 interrupt */
  PWM1_3_IRQn                  = 105,              /**< PWM1 capture 3, compare 3, or reload 0 interrupt */
  PWM1_FAULT_IRQn              = 106,              /**< PWM1 fault or reload error interrupt */
  FLEXSPI2_IRQn                = 107,              /**< FlexSPI2 interrupt */
  FLEXSPI_IRQn                 = 108,              /**< FlexSPI0 interrupt */
  SEMC_IRQn                    = 109,              /**< SEMC interrupt */
  USDHC1_IRQn                  = 110,              /**< USDHC1 interrupt */
  USDHC2_IRQn                  = 111,              /**< USDHC2 interrupt */
  USB_OTG2_IRQn                = 112,              /**< USBO2 USB OTG2 */
  USB_OTG1_IRQn                = 113,              /**< USBO2 USB OTG1 */
  ENET_IRQn                    = 114,              /**< ENET interrupt */
  ENET_1588_Timer_IRQn         = 115,              /**< ENET_1588_Timer interrupt */
  XBAR1_IRQ_0_1_IRQn           = 116,              /**< XBARA1 output signal 0, 1 interrupt */
  XBAR1_IRQ_2_3_IRQn           = 117,              /**< XBARA1 output signal 2, 3 interrupt */
  ADC_ETC_IRQ0_IRQn            = 118,              /**< ADCETC IRQ0 interrupt */
  ADC_ETC_IRQ1_IRQn            = 119,              /**< ADCETC IRQ1 interrupt */
  ADC_ETC_IRQ2_IRQn            = 120,              /**< ADCETC IRQ2 interrupt */
  ADC_ETC_ERROR_IRQ_IRQn       = 121,              /**< ADCETC Error IRQ interrupt */
  PIT_IRQn                     = 122,              /**< PIT interrupt */
  ACMP1_IRQn                   = 123,              /**< ACMP interrupt */
  ACMP2_IRQn                   = 124,              /**< ACMP interrupt */
  ACMP3_IRQn                   = 125,              /**< ACMP interrupt */
  ACMP4_IRQn                   = 126,              /**< ACMP interrupt */
  Reserved143_IRQn             = 127,              /**< Reserved interrupt */
  Reserved144_IRQn             = 128,              /**< Reserved interrupt */
  ENC1_IRQn                    = 129,              /**< ENC1 interrupt */
  ENC2_IRQn                    = 130,              /**< ENC2 interrupt */
  ENC3_IRQn                    = 131,              /**< ENC3 interrupt */
  ENC4_IRQn                    = 132,              /**< ENC4 interrupt */
  TMR1_IRQn                    = 133,              /**< TMR1 interrupt */
  TMR2_IRQn                    = 134,              /**< TMR2 interrupt */
  TMR3_IRQn                    = 135,              /**< TMR3 interrupt */
  TMR4_IRQn                    = 136,              /**< TMR4 interrupt */
  PWM2_0_IRQn                  = 137,              /**< PWM2 capture 0, compare 0, or reload 0 interrupt */
  PWM2_1_IRQn                  = 138,              /**< PWM2 capture 1, compare 1, or reload 0 interrupt */
  PWM2_2_IRQn                  = 139,              /**< PWM2 capture 2, compare 2, or reload 0 interrupt */
  PWM2_3_IRQn                  = 140,              /**< PWM2 capture 3, compare 3, or reload 0 interrupt */
  PWM2_FAULT_IRQn              = 141,              /**< PWM2 fault or reload error interrupt */
  PWM3_0_IRQn                  = 142,              /**< PWM3 capture 0, compare 0, or reload 0 interrupt */
  PWM3_1_IRQn                  = 143,              /**< PWM3 capture 1, compare 1, or reload 0 interrupt */
  PWM3_2_IRQn                  = 144,              /**< PWM3 capture 2, compare 2, or reload 0 interrupt */
  PWM3_3_IRQn                  = 145,              /**< PWM3 capture 3, compare 3, or reload 0 interrupt */
  PWM3_FAULT_IRQn              = 146,              /**< PWM3 fault or reload error interrupt */
  PWM4_0_IRQn                  = 147,              /**< PWM4 capture 0, compare 0, or reload 0 interrupt */
  PWM4_1_IRQn                  = 148,              /**< PWM4 capture 1, compare 1, or reload 0 interrupt */
  PWM4_2_IRQn                  = 149,              /**< PWM4 capture 2, compare 2, or reload 0 interrupt */
  PWM4_3_IRQn                  = 150,              /**< PWM4 capture 3, compare 3, or reload 0 interrupt */
  PWM4_FAULT_IRQn              = 151,              /**< PWM4 fault or reload error interrupt */
  ENET2_IRQn                   = 152,              /**< ENET2 interrupt */
  ENET2_1588_Timer_IRQn        = 153,              /**< ENET2_1588_Timer interrupt */
  CAN3_IRQn                    = 154,              /**< CAN3 interrupt */
  Reserved171_IRQn             = 155,              /**< Reserved interrupt */
  FLEXIO3_IRQn                 = 156,              /**< FLEXIO3 interrupt */
  GPIO6_7_8_9_IRQn             = 157               /**< GPIO6, GPIO7, GPIO8, GPIO9 interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M7 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M7 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __ICACHE_PRESENT               1         /**< Defines if an ICACHE is present or not */
#define __DCACHE_PRESENT               1         /**< Defines if an DCACHE is present or not */
#define __DTCM_PRESENT                 1         /**< Defines if an DTCM is present or not */
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */

#include "core_cm7.h"                  /* Core Peripheral Access Layer */
#include "system_MIMXRT1061.h"         /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMXRT1061_SERIES
#define MIMXRT1061_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMXRT1061_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC1 base address */
#define ADC1_BASE                                (0x400C4000u)
/** Peripheral ADC1 base pointer */
#define ADC1                                     ((ADC_Type *)ADC1_BASE)
/** Peripheral ADC2 base address */
#define ADC2_BASE                                (0x400C8000u)
/** Peripheral ADC2 base pointer */
#define ADC2                                     ((ADC_Type *)ADC2_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { 0u, ADC1_BASE, ADC2_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { (ADC_Type *)0u, ADC1, ADC2 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { NotAvail_IRQn, ADC1_IRQn, ADC2_IRQn }

/* ADC_ETC - Peripheral instance base addresses */
/** Peripheral ADC_ETC base address */
#define ADC_ETC_BASE                             (0x403B0000u)
/** Peripheral ADC_ETC base pointer */
#define ADC_ETC                                  ((ADC_ETC_Type *)ADC_ETC_BASE)
/** Array initializer of ADC_ETC peripheral base addresses */
#define ADC_ETC_BASE_ADDRS                       { ADC_ETC_BASE }
/** Array initializer of ADC_ETC peripheral base pointers */
#define ADC_ETC_BASE_PTRS                        { ADC_ETC }
/** Interrupt vectors for the ADC_ETC peripheral type */
#define ADC_ETC_IRQS                             { { ADC_ETC_IRQ0_IRQn, ADC_ETC_IRQ1_IRQn, ADC_ETC_IRQ2_IRQn } }
#define ADC_ETC_FAULT_IRQS                       { ADC_ETC_ERROR_IRQ_IRQn }

/* AIPSTZ - Peripheral instance base addresses */
/** Peripheral AIPSTZ1 base address */
#define AIPSTZ1_BASE                             (0x4007C000u)
/** Peripheral AIPSTZ1 base pointer */
#define AIPSTZ1                                  ((AIPSTZ_Type *)AIPSTZ1_BASE)
/** Peripheral AIPSTZ2 base address */
#define AIPSTZ2_BASE                             (0x4017C000u)
/** Peripheral AIPSTZ2 base pointer */
#define AIPSTZ2                                  ((AIPSTZ_Type *)AIPSTZ2_BASE)
/** Peripheral AIPSTZ3 base address */
#define AIPSTZ3_BASE                             (0x4027C000u)
/** Peripheral AIPSTZ3 base pointer */
#define AIPSTZ3                                  ((AIPSTZ_Type *)AIPSTZ3_BASE)
/** Peripheral AIPSTZ4 base address */
#define AIPSTZ4_BASE                             (0x4037C000u)
/** Peripheral AIPSTZ4 base pointer */
#define AIPSTZ4                                  ((AIPSTZ_Type *)AIPSTZ4_BASE)
/** Array initializer of AIPSTZ peripheral base addresses */
#define AIPSTZ_BASE_ADDRS                        { 0u, AIPSTZ1_BASE, AIPSTZ2_BASE, AIPSTZ3_BASE, AIPSTZ4_BASE }
/** Array initializer of AIPSTZ peripheral base pointers */
#define AIPSTZ_BASE_PTRS                         { (AIPSTZ_Type *)0u, AIPSTZ1, AIPSTZ2, AIPSTZ3, AIPSTZ4 }

/* AOI - Peripheral instance base addresses */
/** Peripheral AOI1 base address */
#define AOI1_BASE                                (0x403B4000u)
/** Peripheral AOI1 base pointer */
#define AOI1                                     ((AOI_Type *)AOI1_BASE)
/** Peripheral AOI2 base address */
#define AOI2_BASE                                (0x403B8000u)
/** Peripheral AOI2 base pointer */
#define AOI2                                     ((AOI_Type *)AOI2_BASE)
/** Array initializer of AOI peripheral base addresses */
#define AOI_BASE_ADDRS                           { 0u, AOI1_BASE, AOI2_BASE }
/** Array initializer of AOI peripheral base pointers */
#define AOI_BASE_PTRS                            { (AOI_Type *)0u, AOI1, AOI2 }

/* BEE - Peripheral instance base addresses */
/** Peripheral BEE base address */
#define BEE_BASE                                 (0x403EC000u)
/** Peripheral BEE base pointer */
#define BEE                                      ((BEE_Type *)BEE_BASE)
/** Array initializer of BEE peripheral base addresses */
#define BEE_BASE_ADDRS                           { BEE_BASE }
/** Array initializer of BEE peripheral base pointers */
#define BEE_BASE_PTRS                            { BEE }

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN1 base address */
#define CAN1_BASE                                (0x401D0000u)
/** Peripheral CAN1 base pointer */
#define CAN1                                     ((CAN_Type *)CAN1_BASE)
/** Peripheral CAN2 base address */
#define CAN2_BASE                                (0x401D4000u)
/** Peripheral CAN2 base pointer */
#define CAN2                                     ((CAN_Type *)CAN2_BASE)
/** Peripheral CAN3 base address */
#define CAN3_BASE                                (0x401D8000u)
/** Peripheral CAN3 base pointer */
#define CAN3                                     ((CAN_Type *)CAN3_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { 0u, CAN1_BASE, CAN2_BASE, CAN3_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { (CAN_Type *)0u, CAN1, CAN2, CAN3 }
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }
#define CAN_Tx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }
#define CAN_Wake_Up_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }
#define CAN_Error_IRQS                           { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }
#define CAN_Bus_Off_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }
/* Backward compatibility */
#define CAN_ECR_TXERRCNT_MASK         CAN_ECR_TX_ERR_COUNTER_MASK
#define CAN_ECR_TXERRCNT_SHIFT        CAN_ECR_TX_ERR_COUNTER_SHIFT
#define CAN_ECR_TXERRCNT(x)           CAN_ECR_TX_ERR_COUNTER(x)
#define CAN_ECR_RXERRCNT_MASK         CAN_ECR_RX_ERR_COUNTER_MASK
#define CAN_ECR_RXERRCNT_SHIFT        CAN_ECR_RX_ERR_COUNTER_SHIFT
#define CAN_ECR_RXERRCNT(x)           CAN_ECR_RX_ERR_COUNTER(x)


/* CCM - Peripheral instance base addresses */
/** Peripheral CCM base address */
#define CCM_BASE                                 (0x400FC000u)
/** Peripheral CCM base pointer */
#define CCM                                      ((CCM_Type *)CCM_BASE)
/** Array initializer of CCM peripheral base addresses */
#define CCM_BASE_ADDRS                           { CCM_BASE }
/** Array initializer of CCM peripheral base pointers */
#define CCM_BASE_PTRS                            { CCM }
/** Interrupt vectors for the CCM peripheral type */
#define CCM_IRQS                                 { CCM_1_IRQn, CCM_2_IRQn }

/* CCM_ANALOG - Peripheral instance base addresses */
/** Peripheral CCM_ANALOG base address */
#define CCM_ANALOG_BASE                          (0x400D8000u)
/** Peripheral CCM_ANALOG base pointer */
#define CCM_ANALOG                               ((CCM_ANALOG_Type *)CCM_ANALOG_BASE)
/** Array initializer of CCM_ANALOG peripheral base addresses */
#define CCM_ANALOG_BASE_ADDRS                    { CCM_ANALOG_BASE }
/** Array initializer of CCM_ANALOG peripheral base pointers */
#define CCM_ANALOG_BASE_PTRS                     { CCM_ANALOG }

/* CM7_MCM - Peripheral instance base addresses */
/** Peripheral CM7_MCM base address */
#define CM7_MCM_BASE                             (0xE0080000u)
/** Peripheral CM7_MCM base pointer */
#define CM7_MCM                                  ((CM7_MCM_Type *)CM7_MCM_BASE)
/** Array initializer of CM7_MCM peripheral base addresses */
#define CM7_MCM_BASE_ADDRS                       { CM7_MCM_BASE }
/** Array initializer of CM7_MCM peripheral base pointers */
#define CM7_MCM_BASE_PTRS                        { CM7_MCM }

/* CMP - Peripheral instance base addresses */
/** Peripheral CMP1 base address */
#define CMP1_BASE                                (0x40094000u)
/** Peripheral CMP1 base pointer */
#define CMP1                                     ((CMP_Type *)CMP1_BASE)
/** Peripheral CMP2 base address */
#define CMP2_BASE                                (0x40094008u)
/** Peripheral CMP2 base pointer */
#define CMP2                                     ((CMP_Type *)CMP2_BASE)
/** Peripheral CMP3 base address */
#define CMP3_BASE                                (0x40094010u)
/** Peripheral CMP3 base pointer */
#define CMP3                                     ((CMP_Type *)CMP3_BASE)
/** Peripheral CMP4 base address */
#define CMP4_BASE                                (0x40094018u)
/** Peripheral CMP4 base pointer */
#define CMP4                                     ((CMP_Type *)CMP4_BASE)
/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           { 0u, CMP1_BASE, CMP2_BASE, CMP3_BASE, CMP4_BASE }
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { (CMP_Type *)0u, CMP1, CMP2, CMP3, CMP4 }
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { NotAvail_IRQn, ACMP1_IRQn, ACMP2_IRQn, ACMP3_IRQn, ACMP4_IRQn }

/* CSU - Peripheral instance base addresses */
/** Peripheral CSU base address */
#define CSU_BASE                                 (0x400DC000u)
/** Peripheral CSU base pointer */
#define CSU                                      ((CSU_Type *)CSU_BASE)
/** Array initializer of CSU peripheral base addresses */
#define CSU_BASE_ADDRS                           { CSU_BASE }
/** Array initializer of CSU peripheral base pointers */
#define CSU_BASE_PTRS                            { CSU }

/* DCDC - Peripheral instance base addresses */
/** Peripheral DCDC base address */
#define DCDC_BASE                                (0x40080000u)
/** Peripheral DCDC base pointer */
#define DCDC                                     ((DCDC_Type *)DCDC_BASE)
/** Array initializer of DCDC peripheral base addresses */
#define DCDC_BASE_ADDRS                          { DCDC_BASE }
/** Array initializer of DCDC peripheral base pointers */
#define DCDC_BASE_PTRS                           { DCDC }
/** Interrupt vectors for the DCDC peripheral type */
#define DCDC_IRQS                                { DCDC_IRQn }

/* DCP - Peripheral instance base addresses */
/** Peripheral DCP base address */
#define DCP_BASE                                 (0x402FC000u)
/** Peripheral DCP base pointer */
#define DCP                                      ((DCP_Type *)DCP_BASE)
/** Array initializer of DCP peripheral base addresses */
#define DCP_BASE_ADDRS                           { DCP_BASE }
/** Array initializer of DCP peripheral base pointers */
#define DCP_BASE_PTRS                            { DCP }
/** Interrupt vectors for the DCP peripheral type */
#define DCP_IRQS                                 { DCP_IRQn }
#define DCP_VMI_IRQS                             { DCP_VMI_IRQn }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x400E8000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_CHN_IRQS                             { { DMA0_DMA16_IRQn, DMA1_DMA17_IRQn, DMA2_DMA18_IRQn, DMA3_DMA19_IRQn, DMA4_DMA20_IRQn, DMA5_DMA21_IRQn, DMA6_DMA22_IRQn, DMA7_DMA23_IRQn, DMA8_DMA24_IRQn, DMA9_DMA25_IRQn, DMA10_DMA26_IRQn, DMA11_DMA27_IRQn, DMA12_DMA28_IRQn, DMA13_DMA29_IRQn, DMA14_DMA30_IRQn, DMA15_DMA31_IRQn, DMA0_DMA16_IRQn, DMA1_DMA17_IRQn, DMA2_DMA18_IRQn, DMA3_DMA19_IRQn, DMA4_DMA20_IRQn, DMA5_DMA21_IRQn, DMA6_DMA22_IRQn, DMA7_DMA23_IRQn, DMA8_DMA24_IRQn, DMA9_DMA25_IRQn, DMA10_DMA26_IRQn, DMA11_DMA27_IRQn, DMA12_DMA28_IRQn, DMA13_DMA29_IRQn, DMA14_DMA30_IRQn, DMA15_DMA31_IRQn } }
#define DMA_ERROR_IRQS                           { DMA_ERROR_IRQn }

/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX base address */
#define DMAMUX_BASE                              (0x400EC000u)
/** Peripheral DMAMUX base pointer */
#define DMAMUX                                   ((DMAMUX_Type *)DMAMUX_BASE)
/** Array initializer of DMAMUX peripheral base addresses */
#define DMAMUX_BASE_ADDRS                        { DMAMUX_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { DMAMUX }

/* ENC - Peripheral instance base addresses */
/** Peripheral ENC1 base address */
#define ENC1_BASE                                (0x403C8000u)
/** Peripheral ENC1 base pointer */
#define ENC1                                     ((ENC_Type *)ENC1_BASE)
/** Peripheral ENC2 base address */
#define ENC2_BASE                                (0x403CC000u)
/** Peripheral ENC2 base pointer */
#define ENC2                                     ((ENC_Type *)ENC2_BASE)
/** Peripheral ENC3 base address */
#define ENC3_BASE                                (0x403D0000u)
/** Peripheral ENC3 base pointer */
#define ENC3                                     ((ENC_Type *)ENC3_BASE)
/** Peripheral ENC4 base address */
#define ENC4_BASE                                (0x403D4000u)
/** Peripheral ENC4 base pointer */
#define ENC4                                     ((ENC_Type *)ENC4_BASE)
/** Array initializer of ENC peripheral base addresses */
#define ENC_BASE_ADDRS                           { 0u, ENC1_BASE, ENC2_BASE, ENC3_BASE, ENC4_BASE }
/** Array initializer of ENC peripheral base pointers */
#define ENC_BASE_PTRS                            { (ENC_Type *)0u, ENC1, ENC2, ENC3, ENC4 }
/** Interrupt vectors for the ENC peripheral type */
#define ENC_COMPARE_IRQS                         { NotAvail_IRQn, ENC1_IRQn, ENC2_IRQn, ENC3_IRQn, ENC4_IRQn }
#define ENC_HOME_IRQS                            { NotAvail_IRQn, ENC1_IRQn, ENC2_IRQn, ENC3_IRQn, ENC4_IRQn }
#define ENC_WDOG_IRQS                            { NotAvail_IRQn, ENC1_IRQn, ENC2_IRQn, ENC3_IRQn, ENC4_IRQn }
#define ENC_INDEX_IRQS                           { NotAvail_IRQn, ENC1_IRQn, ENC2_IRQn, ENC3_IRQn, ENC4_IRQn }
#define ENC_INPUT_SWITCH_IRQS                    { NotAvail_IRQn, ENC1_IRQn, ENC2_IRQn, ENC3_IRQn, ENC4_IRQn }

/* ENET - Peripheral instance base addresses */
/** Peripheral ENET base address */
#define ENET_BASE                                (0x402D8000u)
/** Peripheral ENET base pointer */
#define ENET                                     ((ENET_Type *)ENET_BASE)
/** Peripheral ENET2 base address */
#define ENET2_BASE                               (0x402D4000u)
/** Peripheral ENET2 base pointer */
#define ENET2                                    ((ENET_Type *)ENET2_BASE)
/** Array initializer of ENET peripheral base addresses */
#define ENET_BASE_ADDRS                          { ENET_BASE, 0u, ENET2_BASE }
/** Array initializer of ENET peripheral base pointers */
#define ENET_BASE_PTRS                           { ENET, (ENET_Type *)0u, ENET2 }
/** Interrupt vectors for the ENET peripheral type */
#define ENET_Transmit_IRQS                       { ENET_IRQn, NotAvail_IRQn, ENET2_IRQn }
#define ENET_Receive_IRQS                        { ENET_IRQn, NotAvail_IRQn, ENET2_IRQn }
#define ENET_Error_IRQS                          { ENET_IRQn, NotAvail_IRQn, ENET2_IRQn }
#define ENET_1588_Timer_IRQS                     { ENET_1588_Timer_IRQn, NotAvail_IRQn, ENET2_1588_Timer_IRQn }
#define ENET_Ts_IRQS                             { ENET_IRQn, NotAvail_IRQn, ENET2_IRQn }

/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base address */
#define EWM_BASE                                 (0x400B4000u)
/** Peripheral EWM base pointer */
#define EWM                                      ((EWM_Type *)EWM_BASE)
/** Array initializer of EWM peripheral base addresses */
#define EWM_BASE_ADDRS                           { EWM_BASE }
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASE_PTRS                            { EWM }
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { EWM_IRQn }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO1 base address */
#define FLEXIO1_BASE                             (0x401AC000u)
/** Peripheral FLEXIO1 base pointer */
#define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
/** Peripheral FLEXIO2 base address */
#define FLEXIO2_BASE                             (0x401B0000u)
/** Peripheral FLEXIO2 base pointer */
#define FLEXIO2                                  ((FLEXIO_Type *)FLEXIO2_BASE)
/** Peripheral FLEXIO3 base address */
#define FLEXIO3_BASE                             (0x42020000u)
/** Peripheral FLEXIO3 base pointer */
#define FLEXIO3                                  ((FLEXIO_Type *)FLEXIO3_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE, FLEXIO2_BASE, FLEXIO3_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1, FLEXIO2, FLEXIO3 }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { NotAvail_IRQn, FLEXIO1_IRQn, FLEXIO2_IRQn, FLEXIO3_IRQn }

/* FLEXRAM - Peripheral instance base addresses */
/** Peripheral FLEXRAM base address */
#define FLEXRAM_BASE                             (0x400B0000u)
/** Peripheral FLEXRAM base pointer */
#define FLEXRAM                                  ((FLEXRAM_Type *)FLEXRAM_BASE)
/** Array initializer of FLEXRAM peripheral base addresses */
#define FLEXRAM_BASE_ADDRS                       { FLEXRAM_BASE }
/** Array initializer of FLEXRAM peripheral base pointers */
#define FLEXRAM_BASE_PTRS                        { FLEXRAM }
/** Interrupt vectors for the FLEXRAM peripheral type */
#define FLEXRAM_IRQS                             { FLEXRAM_IRQn }

/* FLEXSPI - Peripheral instance base addresses */
/** Peripheral FLEXSPI base address */
#define FLEXSPI_BASE                             (0x402A8000u)
/** Peripheral FLEXSPI base pointer */
#define FLEXSPI                                  ((FLEXSPI_Type *)FLEXSPI_BASE)
/** Peripheral FLEXSPI2 base address */
#define FLEXSPI2_BASE                            (0x402A4000u)
/** Peripheral FLEXSPI2 base pointer */
#define FLEXSPI2                                 ((FLEXSPI_Type *)FLEXSPI2_BASE)
/** Array initializer of FLEXSPI peripheral base addresses */
#define FLEXSPI_BASE_ADDRS                       { FLEXSPI_BASE, 0u, FLEXSPI2_BASE }
/** Array initializer of FLEXSPI peripheral base pointers */
#define FLEXSPI_BASE_PTRS                        { FLEXSPI, (FLEXSPI_Type *)0u, FLEXSPI2 }
/** Interrupt vectors for the FLEXSPI peripheral type */
#define FLEXSPI_IRQS                             { FLEXSPI_IRQn, NotAvail_IRQn, FLEXSPI2_IRQn }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (1)
/* FlexSPI AMBA base address array. */
#define FlexSPI_AMBA_BASE_ARRAY                 { {0x60000000u}, {0u}, {0x70000000u} }
/* FlexSPI AMBA end address array. */
#define FlexSPI_AMBA_END_ARRAY                  { {0x6FFFFFFFu}, {0u}, {0x7EFFFFFFu} }
/* FlexSPI AMBA address. */
#define FlexSPI_AMBA_BASE                        (0x60000000u)
/* FlexSPI ASFM address. */
#define FlexSPI_ASFM_BASE                        (0x60000000u)
/* Base Address of AHB address space mapped to IP RX FIFO. */
#define FlexSPI_ARDF_BASE                        (0x7FC00000u)
/* Base Address of AHB address space mapped to IP TX FIFO. */
#define FlexSPI_ATDF_BASE                        (0x7F800000u)
/* FlexSPI2 AMBA address. */
#define FlexSPI2_AMBA_BASE                       (0x70000000u)
/* FlexSPI ASFM address. */
#define FlexSPI2_ASFM_BASE                       (0x70000000u)
/* Base Address of AHB address space mapped to IP RX FIFO. */
#define FlexSPI2_ARDF_BASE                       (0x7F400000u)
/* Base Address of AHB address space mapped to IP TX FIFO. */
#define FlexSPI2_ATDF_BASE                       (0x7F000000u)


/* GPC - Peripheral instance base addresses */
/** Peripheral GPC base address */
#define GPC_BASE                                 (0x400F4000u)
/** Peripheral GPC base pointer */
#define GPC                                      ((GPC_Type *)GPC_BASE)
/** Array initializer of GPC peripheral base addresses */
#define GPC_BASE_ADDRS                           { GPC_BASE }
/** Array initializer of GPC peripheral base pointers */
#define GPC_BASE_PTRS                            { GPC }
/** Interrupt vectors for the GPC peripheral type */
#define GPC_IRQS                                 { GPC_IRQn }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO1 base address */
#define GPIO1_BASE                               (0x401B8000u)
/** Peripheral GPIO1 base pointer */
#define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
/** Peripheral GPIO2 base address */
#define GPIO2_BASE                               (0x401BC000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO3 base address */
#define GPIO3_BASE                               (0x401C0000u)
/** Peripheral GPIO3 base pointer */
#define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
/** Peripheral GPIO4 base address */
#define GPIO4_BASE                               (0x401C4000u)
/** Peripheral GPIO4 base pointer */
#define GPIO4                                    ((GPIO_Type *)GPIO4_BASE)
/** Peripheral GPIO5 base address */
#define GPIO5_BASE                               (0x400C0000u)
/** Peripheral GPIO5 base pointer */
#define GPIO5                                    ((GPIO_Type *)GPIO5_BASE)
/** Peripheral GPIO6 base address */
#define GPIO6_BASE                               (0x42000000u)
/** Peripheral GPIO6 base pointer */
#define GPIO6                                    ((GPIO_Type *)GPIO6_BASE)
/** Peripheral GPIO7 base address */
#define GPIO7_BASE                               (0x42004000u)
/** Peripheral GPIO7 base pointer */
#define GPIO7                                    ((GPIO_Type *)GPIO7_BASE)
/** Peripheral GPIO8 base address */
#define GPIO8_BASE                               (0x42008000u)
/** Peripheral GPIO8 base pointer */
#define GPIO8                                    ((GPIO_Type *)GPIO8_BASE)
/** Peripheral GPIO9 base address */
#define GPIO9_BASE                               (0x4200C000u)
/** Peripheral GPIO9 base pointer */
#define GPIO9                                    ((GPIO_Type *)GPIO9_BASE)
/** Peripheral GPIO10 base address */
#define GPIO10_BASE                              (0x401C8000u)
/** Peripheral GPIO10 base pointer */
#define GPIO10                                   ((GPIO_Type *)GPIO10_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { 0u, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE, GPIO6_BASE, GPIO7_BASE, GPIO8_BASE, GPIO9_BASE, GPIO10_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { (GPIO_Type *)0u, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5, GPIO6, GPIO7, GPIO8, GPIO9, GPIO10 }
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS                                { NotAvail_IRQn, GPIO1_INT0_IRQn, GPIO1_INT1_IRQn, GPIO1_INT2_IRQn, GPIO1_INT3_IRQn, GPIO1_INT4_IRQn, GPIO1_INT5_IRQn, GPIO1_INT6_IRQn, GPIO1_INT7_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }
#define GPIO_COMBINED_LOW_IRQS                   { NotAvail_IRQn, GPIO1_Combined_0_15_IRQn, GPIO2_Combined_0_15_IRQn, GPIO3_Combined_0_15_IRQn, GPIO4_Combined_0_15_IRQn, GPIO5_Combined_0_15_IRQn, GPIO6_7_8_9_IRQn, GPIO6_7_8_9_IRQn, GPIO6_7_8_9_IRQn, GPIO6_7_8_9_IRQn, GPIO10_Combined_0_31_IRQn }
#define GPIO_COMBINED_HIGH_IRQS                  { NotAvail_IRQn, GPIO1_Combined_16_31_IRQn, GPIO2_Combined_16_31_IRQn, GPIO3_Combined_16_31_IRQn, GPIO4_Combined_16_31_IRQn, GPIO5_Combined_16_31_IRQn, GPIO6_7_8_9_IRQn, GPIO6_7_8_9_IRQn, GPIO6_7_8_9_IRQn, GPIO6_7_8_9_IRQn, GPIO10_Combined_0_31_IRQn }

/* GPT - Peripheral instance base addresses */
/** Peripheral GPT1 base address */
#define GPT1_BASE                                (0x401EC000u)
/** Peripheral GPT1 base pointer */
#define GPT1                                     ((GPT_Type *)GPT1_BASE)
/** Peripheral GPT2 base address */
#define GPT2_BASE                                (0x401F0000u)
/** Peripheral GPT2 base pointer */
#define GPT2                                     ((GPT_Type *)GPT2_BASE)
/** Array initializer of GPT peripheral base addresses */
#define GPT_BASE_ADDRS                           { 0u, GPT1_BASE, GPT2_BASE }
/** Array initializer of GPT peripheral base pointers */
#define GPT_BASE_PTRS                            { (GPT_Type *)0u, GPT1, GPT2 }
/** Interrupt vectors for the GPT peripheral type */
#define GPT_IRQS                                 { NotAvail_IRQn, GPT1_IRQn, GPT2_IRQn }

/* I2S - Peripheral instance base addresses */
/** Peripheral SAI1 base address */
#define SAI1_BASE                                (0x40384000u)
/** Peripheral SAI1 base pointer */
#define SAI1                                     ((I2S_Type *)SAI1_BASE)
/** Peripheral SAI2 base address */
#define SAI2_BASE                                (0x40388000u)
/** Peripheral SAI2 base pointer */
#define SAI2                                     ((I2S_Type *)SAI2_BASE)
/** Peripheral SAI3 base address */
#define SAI3_BASE                                (0x4038C000u)
/** Peripheral SAI3 base pointer */
#define SAI3                                     ((I2S_Type *)SAI3_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, SAI2_BASE, SAI3_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, SAI2, SAI3 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_RX_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_TX_IRQn }

/* IOMUXC - Peripheral instance base addresses */
/** Peripheral IOMUXC base address */
#define IOMUXC_BASE                              (0x401F8000u)
/** Peripheral IOMUXC base pointer */
#define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
/** Array initializer of IOMUXC peripheral base addresses */
#define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
/** Array initializer of IOMUXC peripheral base pointers */
#define IOMUXC_BASE_PTRS                         { IOMUXC }

/* IOMUXC_GPR - Peripheral instance base addresses */
/** Peripheral IOMUXC_GPR base address */
#define IOMUXC_GPR_BASE                          (0x400AC000u)
/** Peripheral IOMUXC_GPR base pointer */
#define IOMUXC_GPR                               ((IOMUXC_GPR_Type *)IOMUXC_GPR_BASE)
/** Array initializer of IOMUXC_GPR peripheral base addresses */
#define IOMUXC_GPR_BASE_ADDRS                    { IOMUXC_GPR_BASE }
/** Array initializer of IOMUXC_GPR peripheral base pointers */
#define IOMUXC_GPR_BASE_PTRS                     { IOMUXC_GPR }

/* IOMUXC_SNVS - Peripheral instance base addresses */
/** Peripheral IOMUXC_SNVS base address */
#define IOMUXC_SNVS_BASE                         (0x400A8000u)
/** Peripheral IOMUXC_SNVS base pointer */
#define IOMUXC_SNVS                              ((IOMUXC_SNVS_Type *)IOMUXC_SNVS_BASE)
/** Array initializer of IOMUXC_SNVS peripheral base addresses */
#define IOMUXC_SNVS_BASE_ADDRS                   { IOMUXC_SNVS_BASE }
/** Array initializer of IOMUXC_SNVS peripheral base pointers */
#define IOMUXC_SNVS_BASE_PTRS                    { IOMUXC_SNVS }

/* IOMUXC_SNVS_GPR - Peripheral instance base addresses */
/** Peripheral IOMUXC_SNVS_GPR base address */
#define IOMUXC_SNVS_GPR_BASE                     (0x400A4000u)
/** Peripheral IOMUXC_SNVS_GPR base pointer */
#define IOMUXC_SNVS_GPR                          ((IOMUXC_SNVS_GPR_Type *)IOMUXC_SNVS_GPR_BASE)
/** Array initializer of IOMUXC_SNVS_GPR peripheral base addresses */
#define IOMUXC_SNVS_GPR_BASE_ADDRS               { IOMUXC_SNVS_GPR_BASE }
/** Array initializer of IOMUXC_SNVS_GPR peripheral base pointers */
#define IOMUXC_SNVS_GPR_BASE_PTRS                { IOMUXC_SNVS_GPR }

/* KPP - Peripheral instance base addresses */
/** Peripheral KPP base address */
#define KPP_BASE                                 (0x401FC000u)
/** Peripheral KPP base pointer */
#define KPP                                      ((KPP_Type *)KPP_BASE)
/** Array initializer of KPP peripheral base addresses */
#define KPP_BASE_ADDRS                           { KPP_BASE }
/** Array initializer of KPP peripheral base pointers */
#define KPP_BASE_PTRS                            { KPP }
/** Interrupt vectors for the KPP peripheral type */
#define KPP_IRQS                                 { KPP_IRQn }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x403F0000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x403F4000u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
/** Peripheral LPI2C3 base address */
#define LPI2C3_BASE                              (0x403F8000u)
/** Peripheral LPI2C3 base pointer */
#define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
/** Peripheral LPI2C4 base address */
#define LPI2C4_BASE                              (0x403FC000u)
/** Peripheral LPI2C4 base pointer */
#define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2, LPI2C3, LPI2C4 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn, LPI2C4_IRQn }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x40394000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x40398000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Peripheral LPSPI3 base address */
#define LPSPI3_BASE                              (0x4039C000u)
/** Peripheral LPSPI3 base pointer */
#define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
/** Peripheral LPSPI4 base address */
#define LPSPI4_BASE                              (0x403A0000u)
/** Peripheral LPSPI4 base pointer */
#define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2, LPSPI3, LPSPI4 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, LPSPI4_IRQn }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x40184000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x40188000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Peripheral LPUART3 base address */
#define LPUART3_BASE                             (0x4018C000u)
/** Peripheral LPUART3 base pointer */
#define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
/** Peripheral LPUART4 base address */
#define LPUART4_BASE                             (0x40190000u)
/** Peripheral LPUART4 base pointer */
#define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
/** Peripheral LPUART5 base address */
#define LPUART5_BASE                             (0x40194000u)
/** Peripheral LPUART5 base pointer */
#define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
/** Peripheral LPUART6 base address */
#define LPUART6_BASE                             (0x40198000u)
/** Peripheral LPUART6 base pointer */
#define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
/** Peripheral LPUART7 base address */
#define LPUART7_BASE                             (0x4019C000u)
/** Peripheral LPUART7 base pointer */
#define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
/** Peripheral LPUART8 base address */
#define LPUART8_BASE                             (0x401A0000u)
/** Peripheral LPUART8 base pointer */
#define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn, LPUART6_IRQn, LPUART7_IRQn, LPUART8_IRQn }

/* OCOTP - Peripheral instance base addresses */
/** Peripheral OCOTP base address */
#define OCOTP_BASE                               (0x401F4000u)
/** Peripheral OCOTP base pointer */
#define OCOTP                                    ((OCOTP_Type *)OCOTP_BASE)
/** Array initializer of OCOTP peripheral base addresses */
#define OCOTP_BASE_ADDRS                         { OCOTP_BASE }
/** Array initializer of OCOTP peripheral base pointers */
#define OCOTP_BASE_PTRS                          { OCOTP }

/* PGC - Peripheral instance base addresses */
/** Peripheral PGC base address */
#define PGC_BASE                                 (0x400F4000u)
/** Peripheral PGC base pointer */
#define PGC                                      ((PGC_Type *)PGC_BASE)
/** Array initializer of PGC peripheral base addresses */
#define PGC_BASE_ADDRS                           { PGC_BASE }
/** Array initializer of PGC peripheral base pointers */
#define PGC_BASE_PTRS                            { PGC }

/* PIT - Peripheral instance base addresses */
/** Peripheral PIT base address */
#define PIT_BASE                                 (0x40084000u)
/** Peripheral PIT base pointer */
#define PIT                                      ((PIT_Type *)PIT_BASE)
/** Array initializer of PIT peripheral base addresses */
#define PIT_BASE_ADDRS                           { PIT_BASE }
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            { PIT }
/** Interrupt vectors for the PIT peripheral type */
#define PIT_IRQS                                 { { PIT_IRQn, PIT_IRQn, PIT_IRQn, PIT_IRQn } }

/* PMU - Peripheral instance base addresses */
/** Peripheral PMU base address */
#define PMU_BASE                                 (0x400D8000u)
/** Peripheral PMU base pointer */
#define PMU                                      ((PMU_Type *)PMU_BASE)
/** Array initializer of PMU peripheral base addresses */
#define PMU_BASE_ADDRS                           { PMU_BASE }
/** Array initializer of PMU peripheral base pointers */
#define PMU_BASE_PTRS                            { PMU }

/* PWM - Peripheral instance base addresses */
/** Peripheral PWM1 base address */
#define PWM1_BASE                                (0x403DC000u)
/** Peripheral PWM1 base pointer */
#define PWM1                                     ((PWM_Type *)PWM1_BASE)
/** Peripheral PWM2 base address */
#define PWM2_BASE                                (0x403E0000u)
/** Peripheral PWM2 base pointer */
#define PWM2                                     ((PWM_Type *)PWM2_BASE)
/** Peripheral PWM3 base address */
#define PWM3_BASE                                (0x403E4000u)
/** Peripheral PWM3 base pointer */
#define PWM3                                     ((PWM_Type *)PWM3_BASE)
/** Peripheral PWM4 base address */
#define PWM4_BASE                                (0x403E8000u)
/** Peripheral PWM4 base pointer */
#define PWM4                                     ((PWM_Type *)PWM4_BASE)
/** Array initializer of PWM peripheral base addresses */
#define PWM_BASE_ADDRS                           { 0u, PWM1_BASE, PWM2_BASE, PWM3_BASE, PWM4_BASE }
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASE_PTRS                            { (PWM_Type *)0u, PWM1, PWM2, PWM3, PWM4 }
/** Interrupt vectors for the PWM peripheral type */
#define PWM_CMP_IRQS                             { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn }, { PWM2_0_IRQn, PWM2_1_IRQn, PWM2_2_IRQn, PWM2_3_IRQn }, { PWM3_0_IRQn, PWM3_1_IRQn, PWM3_2_IRQn, PWM3_3_IRQn }, { PWM4_0_IRQn, PWM4_1_IRQn, PWM4_2_IRQn, PWM4_3_IRQn } }
#define PWM_RELOAD_IRQS                          { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn }, { PWM2_0_IRQn, PWM2_1_IRQn, PWM2_2_IRQn, PWM2_3_IRQn }, { PWM3_0_IRQn, PWM3_1_IRQn, PWM3_2_IRQn, PWM3_3_IRQn }, { PWM4_0_IRQn, PWM4_1_IRQn, PWM4_2_IRQn, PWM4_3_IRQn } }
#define PWM_CAPTURE_IRQS                         { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn }, { PWM2_0_IRQn, PWM2_1_IRQn, PWM2_2_IRQn, PWM2_3_IRQn }, { PWM3_0_IRQn, PWM3_1_IRQn, PWM3_2_IRQn, PWM3_3_IRQn }, { PWM4_0_IRQn, PWM4_1_IRQn, PWM4_2_IRQn, PWM4_3_IRQn } }
#define PWM_FAULT_IRQS                           { NotAvail_IRQn, PWM1_FAULT_IRQn, PWM2_FAULT_IRQn, PWM3_FAULT_IRQn, PWM4_FAULT_IRQn }
#define PWM_RELOAD_ERROR_IRQS                    { NotAvail_IRQn, PWM1_FAULT_IRQn, PWM2_FAULT_IRQn, PWM3_FAULT_IRQn, PWM4_FAULT_IRQn }

/* ROMC - Peripheral instance base addresses */
/** Peripheral ROMC base address */
#define ROMC_BASE                                (0x40180000u)
/** Peripheral ROMC base pointer */
#define ROMC                                     ((ROMC_Type *)ROMC_BASE)
/** Array initializer of ROMC peripheral base addresses */
#define ROMC_BASE_ADDRS                          { ROMC_BASE }
/** Array initializer of ROMC peripheral base pointers */
#define ROMC_BASE_PTRS                           { ROMC }

/* RTWDOG - Peripheral instance base addresses */
/** Peripheral RTWDOG base address */
#define RTWDOG_BASE                              (0x400BC000u)
/** Peripheral RTWDOG base pointer */
#define RTWDOG                                   ((RTWDOG_Type *)RTWDOG_BASE)
/** Array initializer of RTWDOG peripheral base addresses */
#define RTWDOG_BASE_ADDRS                        { RTWDOG_BASE }
/** Array initializer of RTWDOG peripheral base pointers */
#define RTWDOG_BASE_PTRS                         { RTWDOG }
/** Interrupt vectors for the RTWDOG peripheral type */
#define RTWDOG_IRQS                              { RTWDOG_IRQn }

/* SEMC - Peripheral instance base addresses */
/** Peripheral SEMC base address */
#define SEMC_BASE                                (0x402F0000u)
/** Peripheral SEMC base pointer */
#define SEMC                                     ((SEMC_Type *)SEMC_BASE)
/** Array initializer of SEMC peripheral base addresses */
#define SEMC_BASE_ADDRS                          { SEMC_BASE }
/** Array initializer of SEMC peripheral base pointers */
#define SEMC_BASE_PTRS                           { SEMC }
/** Interrupt vectors for the SEMC peripheral type */
#define SEMC_IRQS                                { SEMC_IRQn }

/* SNVS - Peripheral instance base addresses */
/** Peripheral SNVS base address */
#define SNVS_BASE                                (0x400D4000u)
/** Peripheral SNVS base pointer */
#define SNVS                                     ((SNVS_Type *)SNVS_BASE)
/** Array initializer of SNVS peripheral base addresses */
#define SNVS_BASE_ADDRS                          { SNVS_BASE }
/** Array initializer of SNVS peripheral base pointers */
#define SNVS_BASE_PTRS                           { SNVS }
/** Interrupt vectors for the SNVS peripheral type */
#define SNVS_IRQS                                { SNVS_LP_WRAPPER_IRQn }
#define SNVS_CONSOLIDATED_IRQS                   { SNVS_HP_WRAPPER_IRQn }
#define SNVS_SECURITY_IRQS                       { SNVS_HP_WRAPPER_TZ_IRQn }

/* SPDIF - Peripheral instance base addresses */
/** Peripheral SPDIF base address */
#define SPDIF_BASE                               (0x40380000u)
/** Peripheral SPDIF base pointer */
#define SPDIF                                    ((SPDIF_Type *)SPDIF_BASE)
/** Array initializer of SPDIF peripheral base addresses */
#define SPDIF_BASE_ADDRS                         { SPDIF_BASE }
/** Array initializer of SPDIF peripheral base pointers */
#define SPDIF_BASE_PTRS                          { SPDIF }
/** Interrupt vectors for the SPDIF peripheral type */
#define SPDIF_IRQS                               { SPDIF_IRQn }

/* SRC - Peripheral instance base addresses */
/** Peripheral SRC base address */
#define SRC_BASE                                 (0x400F8000u)
/** Peripheral SRC base pointer */
#define SRC                                      ((SRC_Type *)SRC_BASE)
/** Array initializer of SRC peripheral base addresses */
#define SRC_BASE_ADDRS                           { SRC_BASE }
/** Array initializer of SRC peripheral base pointers */
#define SRC_BASE_PTRS                            { SRC }
/** Interrupt vectors for the SRC peripheral type */
#define SRC_IRQS                                 { SRC_IRQn }

/* TEMPMON - Peripheral instance base addresses */
/** Peripheral TEMPMON base address */
#define TEMPMON_BASE                             (0x400D8000u)
/** Peripheral TEMPMON base pointer */
#define TEMPMON                                  ((TEMPMON_Type *)TEMPMON_BASE)
/** Array initializer of TEMPMON peripheral base addresses */
#define TEMPMON_BASE_ADDRS                       { TEMPMON_BASE }
/** Array initializer of TEMPMON peripheral base pointers */
#define TEMPMON_BASE_PTRS                        { TEMPMON }

/* TMR - Peripheral instance base addresses */
/** Peripheral TMR1 base address */
#define TMR1_BASE                                (0x401DC000u)
/** Peripheral TMR1 base pointer */
#define TMR1                                     ((TMR_Type *)TMR1_BASE)
/** Peripheral TMR2 base address */
#define TMR2_BASE                                (0x401E0000u)
/** Peripheral TMR2 base pointer */
#define TMR2                                     ((TMR_Type *)TMR2_BASE)
/** Peripheral TMR3 base address */
#define TMR3_BASE                                (0x401E4000u)
/** Peripheral TMR3 base pointer */
#define TMR3                                     ((TMR_Type *)TMR3_BASE)
/** Peripheral TMR4 base address */
#define TMR4_BASE                                (0x401E8000u)
/** Peripheral TMR4 base pointer */
#define TMR4                                     ((TMR_Type *)TMR4_BASE)
/** Array initializer of TMR peripheral base addresses */
#define TMR_BASE_ADDRS                           { 0u, TMR1_BASE, TMR2_BASE, TMR3_BASE, TMR4_BASE }
/** Array initializer of TMR peripheral base pointers */
#define TMR_BASE_PTRS                            { (TMR_Type *)0u, TMR1, TMR2, TMR3, TMR4 }
/** Interrupt vectors for the TMR peripheral type */
#define TMR_IRQS                                 { NotAvail_IRQn, TMR1_IRQn, TMR2_IRQn, TMR3_IRQn, TMR4_IRQn }

/* TRNG - Peripheral instance base addresses */
/** Peripheral TRNG base address */
#define TRNG_BASE                                (0x400CC000u)
/** Peripheral TRNG base pointer */
#define TRNG                                     ((TRNG_Type *)TRNG_BASE)
/** Array initializer of TRNG peripheral base addresses */
#define TRNG_BASE_ADDRS                          { TRNG_BASE }
/** Array initializer of TRNG peripheral base pointers */
#define TRNG_BASE_PTRS                           { TRNG }
/** Interrupt vectors for the TRNG peripheral type */
#define TRNG_IRQS                                { TRNG_IRQn }

/* TSC - Peripheral instance base addresses */
/** Peripheral TSC base address */
#define TSC_BASE                                 (0x400E0000u)
/** Peripheral TSC base pointer */
#define TSC                                      ((TSC_Type *)TSC_BASE)
/** Array initializer of TSC peripheral base addresses */
#define TSC_BASE_ADDRS                           { TSC_BASE }
/** Array initializer of TSC peripheral base pointers */
#define TSC_BASE_PTRS                            { TSC }
/** Interrupt vectors for the TSC peripheral type */
#define TSC_IRQS                                 { TSC_DIG_IRQn }

/* USB - Peripheral instance base addresses */
/** Peripheral USB1 base address */
#define USB1_BASE                                (0x402E0000u)
/** Peripheral USB1 base pointer */
#define USB1                                     ((USB_Type *)USB1_BASE)
/** Peripheral USB2 base address */
#define USB2_BASE                                (0x402E0200u)
/** Peripheral USB2 base pointer */
#define USB2                                     ((USB_Type *)USB2_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { 0u, USB1_BASE, USB2_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { (USB_Type *)0u, USB1, USB2 }
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { NotAvail_IRQn, USB_OTG1_IRQn, USB_OTG2_IRQn }

/* USBNC - Peripheral instance base addresses */
/** Peripheral USBNC1 base address */
#define USBNC1_BASE                              (0x402E0000u)
/** Peripheral USBNC1 base pointer */
#define USBNC1                                   ((USBNC_Type *)USBNC1_BASE)
/** Peripheral USBNC2 base address */
#define USBNC2_BASE                              (0x402E0004u)
/** Peripheral USBNC2 base pointer */
#define USBNC2                                   ((USBNC_Type *)USBNC2_BASE)
/** Array initializer of USBNC peripheral base addresses */
#define USBNC_BASE_ADDRS                         { 0u, USBNC1_BASE, USBNC2_BASE }
/** Array initializer of USBNC peripheral base pointers */
#define USBNC_BASE_PTRS                          { (USBNC_Type *)0u, USBNC1, USBNC2 }

/* USBPHY - Peripheral instance base addresses */
/** Peripheral USBPHY1 base address */
#define USBPHY1_BASE                             (0x400D9000u)
/** Peripheral USBPHY1 base pointer */
#define USBPHY1                                  ((USBPHY_Type *)USBPHY1_BASE)
/** Peripheral USBPHY2 base address */
#define USBPHY2_BASE                             (0x400DA000u)
/** Peripheral USBPHY2 base pointer */
#define USBPHY2                                  ((USBPHY_Type *)USBPHY2_BASE)
/** Array initializer of USBPHY peripheral base addresses */
#define USBPHY_BASE_ADDRS                        { 0u, USBPHY1_BASE, USBPHY2_BASE }
/** Array initializer of USBPHY peripheral base pointers */
#define USBPHY_BASE_PTRS                         { (USBPHY_Type *)0u, USBPHY1, USBPHY2 }
/** Interrupt vectors for the USBPHY peripheral type */
#define USBPHY_IRQS                              { NotAvail_IRQn, USB_PHY1_IRQn, USB_PHY2_IRQn }
/* Backward compatibility */
#define USBPHY_CTRL_ENDEVPLUGINDET_MASK     USBPHY_CTRL_ENDEVPLUGINDETECT_MASK
#define USBPHY_CTRL_ENDEVPLUGINDET_SHIFT    USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT
#define USBPHY_CTRL_ENDEVPLUGINDET(x)       USBPHY_CTRL_ENDEVPLUGINDETECT(x)
#define USBPHY_TX_TXCAL45DM_MASK            USBPHY_TX_TXCAL45DN_MASK
#define USBPHY_TX_TXCAL45DM_SHIFT           USBPHY_TX_TXCAL45DN_SHIFT
#define USBPHY_TX_TXCAL45DM(x)              USBPHY_TX_TXCAL45DN(x)

#define USBPHY_STACK_BASE_ADDRS             { USBPHY1_BASE, USBPHY2_BASE }


/* USB_ANALOG - Peripheral instance base addresses */
/** Peripheral USB_ANALOG base address */
#define USB_ANALOG_BASE                          (0x400D8000u)
/** Peripheral USB_ANALOG base pointer */
#define USB_ANALOG                               ((USB_ANALOG_Type *)USB_ANALOG_BASE)
/** Array initializer of USB_ANALOG peripheral base addresses */
#define USB_ANALOG_BASE_ADDRS                    { USB_ANALOG_BASE }
/** Array initializer of USB_ANALOG peripheral base pointers */
#define USB_ANALOG_BASE_PTRS                     { USB_ANALOG }

/* USDHC - Peripheral instance base addresses */
/** Peripheral USDHC1 base address */
#define USDHC1_BASE                              (0x402C0000u)
/** Peripheral USDHC1 base pointer */
#define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
/** Peripheral USDHC2 base address */
#define USDHC2_BASE                              (0x402C4000u)
/** Peripheral USDHC2 base pointer */
#define USDHC2                                   ((USDHC_Type *)USDHC2_BASE)
/** Array initializer of USDHC peripheral base addresses */
#define USDHC_BASE_ADDRS                         { 0u, USDHC1_BASE, USDHC2_BASE }
/** Array initializer of USDHC peripheral base pointers */
#define USDHC_BASE_PTRS                          { (USDHC_Type *)0u, USDHC1, USDHC2 }
/** Interrupt vectors for the USDHC peripheral type */
#define USDHC_IRQS                               { NotAvail_IRQn, USDHC1_IRQn, USDHC2_IRQn }

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG1 base address */
#define WDOG1_BASE                               (0x400B8000u)
/** Peripheral WDOG1 base pointer */
#define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
/** Peripheral WDOG2 base address */
#define WDOG2_BASE                               (0x400D0000u)
/** Peripheral WDOG2 base pointer */
#define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { 0u, WDOG1_BASE, WDOG2_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { (WDOG_Type *)0u, WDOG1, WDOG2 }
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { NotAvail_IRQn, WDOG1_IRQn, WDOG2_IRQn }

/* XBARA - Peripheral instance base addresses */
/** Peripheral XBARA1 base address */
#define XBARA1_BASE                              (0x403BC000u)
/** Peripheral XBARA1 base pointer */
#define XBARA1                                   ((XBARA_Type *)XBARA1_BASE)
/** Array initializer of XBARA peripheral base addresses */
#define XBARA_BASE_ADDRS                         { 0u, XBARA1_BASE }
/** Array initializer of XBARA peripheral base pointers */
#define XBARA_BASE_PTRS                          { (XBARA_Type *)0u, XBARA1 }

/* XBARB - Peripheral instance base addresses */
/** Peripheral XBARB2 base address */
#define XBARB2_BASE                              (0x403C0000u)
/** Peripheral XBARB2 base pointer */
#define XBARB2                                   ((XBARB_Type *)XBARB2_BASE)
/** Peripheral XBARB3 base address */
#define XBARB3_BASE                              (0x403C4000u)
/** Peripheral XBARB3 base pointer */
#define XBARB3                                   ((XBARB_Type *)XBARB3_BASE)
/** Array initializer of XBARB peripheral base addresses */
#define XBARB_BASE_ADDRS                         { 0u, 0u, XBARB2_BASE, XBARB3_BASE }
/** Array initializer of XBARB peripheral base pointers */
#define XBARB_BASE_PTRS                          { (XBARB_Type *)0u, (XBARB_Type *)0u, XBARB2, XBARB3 }

/* XTALOSC24M - Peripheral instance base addresses */
/** Peripheral XTALOSC24M base address */
#define XTALOSC24M_BASE                          (0x400D8000u)
/** Peripheral XTALOSC24M base pointer */
#define XTALOSC24M                               ((XTALOSC24M_Type *)XTALOSC24M_BASE)
/** Array initializer of XTALOSC24M peripheral base addresses */
#define XTALOSC24M_BASE_ADDRS                    { XTALOSC24M_BASE }
/** Array initializer of XTALOSC24M peripheral base pointers */
#define XTALOSC24M_BASE_PTRS                     { XTALOSC24M }

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


#endif  /* MIMXRT1061_COMMON_H_ */

