/*
** ###################################################################
**     Processors:          MIMXRT1011CAE4A
**                          MIMXRT1011DAE5A
**
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    IMXRT1010RM Rev.1, 10/2021 | IMXRT1010SRM Rev.0
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT1011
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-02-14)
**         Initial version.
**     - rev. 1.0 (2019-08-01)
**         Rev.0 Header GA
**     - rev. 1.1 (2019-08-06)
**         Update header files to align with IMXRT1010RM Rev.B.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1010RM Rev.1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMXRT1011_COMMON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMXRT1011
 *
 * CMSIS Peripheral Access Layer for MIMXRT1011
 */

#if !defined(MIMXRT1011_COMMON_H_)
#define MIMXRT1011_COMMON_H_                     /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 96                 /**< Number of interrupts in the Vector table */

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
  DMA0_IRQn                    = 0,                /**< DMA channel 0 transfer complete */
  DMA1_IRQn                    = 1,                /**< DMA channel 1 transfer complete */
  DMA2_IRQn                    = 2,                /**< DMA channel 2 transfer complete */
  DMA3_IRQn                    = 3,                /**< DMA channel 3 transfer complete */
  DMA4_IRQn                    = 4,                /**< DMA channel 4 transfer complete */
  DMA5_IRQn                    = 5,                /**< DMA channel 5 transfer complete */
  DMA6_IRQn                    = 6,                /**< DMA channel 6 transfer complete */
  DMA7_IRQn                    = 7,                /**< DMA channel 7 transfer complete */
  DMA8_IRQn                    = 8,                /**< DMA channel 8 transfer complete */
  DMA9_IRQn                    = 9,                /**< DMA channel 9 transfer complete */
  DMA10_IRQn                   = 10,               /**< DMA channel 10 transfer complete */
  DMA11_IRQn                   = 11,               /**< DMA channel 11 transfer complete */
  DMA12_IRQn                   = 12,               /**< DMA channel 12 transfer complete */
  DMA13_IRQn                   = 13,               /**< DMA channel 13 transfer complete */
  DMA14_IRQn                   = 14,               /**< DMA channel 14 transfer complete */
  DMA15_IRQn                   = 15,               /**< DMA channel 15 transfer complete */
  DMA_ERROR_IRQn               = 16,               /**< DMA error interrupt channels 0-15 */
  CTI0_ERROR_IRQn              = 17,               /**< CTI trigger outputs */
  CTI1_ERROR_IRQn              = 18,               /**< CTI trigger outputs */
  CORE_IRQn                    = 19,               /**< CorePlatform exception IRQ */
  LPUART1_IRQn                 = 20,               /**< LPUART1 TX interrupt and RX interrupt */
  LPUART2_IRQn                 = 21,               /**< LPUART2 TX interrupt and RX interrupt */
  LPUART3_IRQn                 = 22,               /**< LPUART3 TX interrupt and RX interrupt */
  LPUART4_IRQn                 = 23,               /**< LPUART4 TX interrupt and RX interrupt */
  PIT_IRQn                     = 24,               /**< PIT interrupt */
  USB_OTG1_IRQn                = 25,               /**< USBO2 USB OTG1 */
  FLEXSPI_IRQn                 = 26,               /**< FlexSPI0 interrupt */
  FLEXRAM_IRQn                 = 27,               /**< FlexRAM address out of range Or access hit IRQ */
  LPI2C1_IRQn                  = 28,               /**< LPI2C1 interrupt */
  LPI2C2_IRQn                  = 29,               /**< LPI2C2 interrupt */
  GPT1_IRQn                    = 30,               /**< GPT1 interrupt */
  GPT2_IRQn                    = 31,               /**< GPT2 interrupt */
  LPSPI1_IRQn                  = 32,               /**< LPSPI1 single interrupt vector for all sources */
  LPSPI2_IRQn                  = 33,               /**< LPSPI2 single interrupt vector for all sources */
  PWM1_0_IRQn                  = 34,               /**< PWM1 capture 0, compare 0, or reload 0 interrupt */
  PWM1_1_IRQn                  = 35,               /**< PWM1 capture 1, compare 1, or reload 0 interrupt */
  PWM1_2_IRQn                  = 36,               /**< PWM1 capture 2, compare 2, or reload 0 interrupt */
  PWM1_3_IRQn                  = 37,               /**< PWM1 capture 3, compare 3, or reload 0 interrupt */
  PWM1_FAULT_IRQn              = 38,               /**< PWM1 fault or reload error interrupt */
  KPP_IRQn                     = 39,               /**< Keypad nterrupt */
  SRC_IRQn                     = 40,               /**< SRC interrupt */
  GPR_IRQ_IRQn                 = 41,               /**< Used to notify cores on exception condition while boot */
  CCM_1_IRQn                   = 42,               /**< CCM IRQ1 interrupt */
  CCM_2_IRQn                   = 43,               /**< CCM IRQ2 interrupt */
  EWM_IRQn                     = 44,               /**< EWM interrupt */
  WDOG2_IRQn                   = 45,               /**< WDOG2 interrupt */
  SNVS_HP_WRAPPER_IRQn         = 46,               /**< SNVS Functional Interrupt */
  SNVS_HP_WRAPPER_TZ_IRQn      = 47,               /**< SNVS Security Interrupt */
  SNVS_LP_WRAPPER_IRQn         = 48,               /**< ON-OFF button press shorter than 5 secs (pulse event) */
  CSU_IRQn                     = 49,               /**< CSU interrupt */
  DCP_IRQn                     = 50,               /**< Combined DCP channel interrupts(except channel 0) and CRC interrupt */
  DCP_VMI_IRQn                 = 51,               /**< IRQ of DCP channel 0 */
  Reserved68_IRQn              = 52,               /**< Reserved interrupt */
  TRNG_IRQn                    = 53,               /**< TRNG interrupt */
  Reserved70_IRQn              = 54,               /**< Reserved interrupt */
  Reserved71_IRQn              = 55,               /**< Reserved interrupt */
  SAI1_IRQn                    = 56,               /**< SAI1 interrupt */
  RTWDOG_IRQn                  = 57,               /**< RTWDOG interrupt */
  SAI3_RX_IRQn                 = 58,               /**< SAI3 interrupt */
  SAI3_TX_IRQn                 = 59,               /**< SAI3 interrupt */
  SPDIF_IRQn                   = 60,               /**< SPDIF interrupt */
  PMU_IRQn                     = 61,               /**< PMU interrupt */
  XBAR1_IRQ_0_1_2_3_IRQn       = 62,               /**< XBAR1 interrupt */
  TEMP_LOW_HIGH_IRQn           = 63,               /**< TEMPMON interrupt */
  TEMP_PANIC_IRQn              = 64,               /**< TEMPMON interrupt */
  USB_PHY_IRQn                 = 65,               /**< USBPHY (OTG1 UTMI), Interrupt */
  GPC_IRQn                     = 66,               /**< GPC interrupt */
  ADC1_IRQn                    = 67,               /**< ADC1 interrupt */
  FLEXIO1_IRQn                 = 68,               /**< FLEXIO1 interrupt */
  DCDC_IRQn                    = 69,               /**< DCDC interrupt */
  GPIO1_Combined_0_15_IRQn     = 70,               /**< Combined interrupt indication for GPIO1 signal 0 throughout 15 */
  GPIO1_Combined_16_31_IRQn    = 71,               /**< Combined interrupt indication for GPIO1 signal 16 throughout 31 */
  GPIO2_Combined_0_15_IRQn     = 72,               /**< Combined interrupt indication for GPIO2 signal 0 throughout 15 */
  GPIO5_Combined_0_15_IRQn     = 73,               /**< Combined interrupt indication for GPIO5 signal 0 throughout 15 */
  WDOG1_IRQn                   = 74,               /**< WDOG1 interrupt */
  ADC_ETC_IRQ0_IRQn            = 75,               /**< ADCETC IRQ0 interrupt */
  ADC_ETC_IRQ1_IRQn            = 76,               /**< ADCETC IRQ1 interrupt */
  ADC_ETC_IRQ2_IRQn            = 77,               /**< ADCETC IRQ2 interrupt */
  ADC_ETC_IRQ3_IRQn            = 78,               /**< ADCETC IRQ3 interrupt */
  ADC_ETC_ERROR_IRQ_IRQn       = 79                /**< ADCETC Error IRQ interrupt */
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
#include "system_MIMXRT1011.h"         /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMXRT1011_SERIES
#define MIMXRT1011_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMXRT1011_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC1 base address */
#define ADC1_BASE                                (0x400C4000u)
/** Peripheral ADC1 base pointer */
#define ADC1                                     ((ADC_Type *)ADC1_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { 0u, ADC1_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { (ADC_Type *)0u, ADC1 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { NotAvail_IRQn, ADC1_IRQn }

/* ADC_ETC - Peripheral instance base addresses */
/** Peripheral ADC_ETC base address */
#define ADC_ETC_BASE                             (0x40088000u)
/** Peripheral ADC_ETC base pointer */
#define ADC_ETC                                  ((ADC_ETC_Type *)ADC_ETC_BASE)
/** Array initializer of ADC_ETC peripheral base addresses */
#define ADC_ETC_BASE_ADDRS                       { ADC_ETC_BASE }
/** Array initializer of ADC_ETC peripheral base pointers */
#define ADC_ETC_BASE_PTRS                        { ADC_ETC }
/** Interrupt vectors for the ADC_ETC peripheral type */
#define ADC_ETC_IRQS                             { { ADC_ETC_IRQ0_IRQn, ADC_ETC_IRQ1_IRQn, ADC_ETC_IRQ2_IRQn, ADC_ETC_IRQ3_IRQn } }
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
/** Array initializer of AIPSTZ peripheral base addresses */
#define AIPSTZ_BASE_ADDRS                        { 0u, AIPSTZ1_BASE, AIPSTZ2_BASE }
/** Array initializer of AIPSTZ peripheral base pointers */
#define AIPSTZ_BASE_PTRS                         { (AIPSTZ_Type *)0u, AIPSTZ1, AIPSTZ2 }

/* AOI - Peripheral instance base addresses */
/** Peripheral AOI base address */
#define AOI_BASE                                 (0x40094000u)
/** Peripheral AOI base pointer */
#define AOI                                      ((AOI_Type *)AOI_BASE)
/** Array initializer of AOI peripheral base addresses */
#define AOI_BASE_ADDRS                           { AOI_BASE }
/** Array initializer of AOI peripheral base pointers */
#define AOI_BASE_PTRS                            { AOI }

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
#define DCP_BASE                                 (0x400F0000u)
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
#define DMA_CHN_IRQS                             { { DMA0_IRQn, DMA1_IRQn, DMA2_IRQn, DMA3_IRQn, DMA4_IRQn, DMA5_IRQn, DMA6_IRQn, DMA7_IRQn, DMA8_IRQn, DMA9_IRQn, DMA10_IRQn, DMA11_IRQn, DMA12_IRQn, DMA13_IRQn, DMA14_IRQn, DMA15_IRQn } }
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
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1 }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { NotAvail_IRQn, FLEXIO1_IRQn }

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
#define FLEXSPI_BASE                             (0x400A0000u)
/** Peripheral FLEXSPI base pointer */
#define FLEXSPI                                  ((FLEXSPI_Type *)FLEXSPI_BASE)
/** Array initializer of FLEXSPI peripheral base addresses */
#define FLEXSPI_BASE_ADDRS                       { FLEXSPI_BASE }
/** Array initializer of FLEXSPI peripheral base pointers */
#define FLEXSPI_BASE_PTRS                        { FLEXSPI }
/** Interrupt vectors for the FLEXSPI peripheral type */
#define FLEXSPI_IRQS                             { FLEXSPI_IRQn }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (1)
/* FlexSPI AMBA base address array. */
#define FlexSPI_AMBA_BASE_ARRAY                 { {0x60000000u} }
/* FlexSPI AMBA end address array. */
#define FlexSPI_AMBA_END_ARRAY                  { {0x7F7FFFFFu} }
/* FlexSPI AMBA address. */
#define FlexSPI_AMBA_BASE                        (0x60000000u)
/* FlexSPI ASFM address. */
#define FlexSPI_ASFM_BASE                        (0x60000000u)
/* Base Address of AHB address space mapped to IP RX FIFO. */
#define FlexSPI_ARDF_BASE                        (0x7FC00000u)
/* Base Address of AHB address space mapped to IP TX FIFO. */
#define FlexSPI_ATDF_BASE                        (0x7F800000u)


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
#define GPIO2_BASE                               (0x42000000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO5 base address */
#define GPIO5_BASE                               (0x400C0000u)
/** Peripheral GPIO5 base pointer */
#define GPIO5                                    ((GPIO_Type *)GPIO5_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { 0u, GPIO1_BASE, GPIO2_BASE, 0u, 0u, GPIO5_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { (GPIO_Type *)0u, GPIO1, GPIO2, (GPIO_Type *)0u, (GPIO_Type *)0u, GPIO5 }
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_COMBINED_LOW_IRQS                   { NotAvail_IRQn, GPIO1_Combined_0_15_IRQn, GPIO2_Combined_0_15_IRQn, NotAvail_IRQn, NotAvail_IRQn, GPIO5_Combined_0_15_IRQn }
#define GPIO_COMBINED_HIGH_IRQS                  { NotAvail_IRQn, GPIO1_Combined_16_31_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

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
#define SAI1_BASE                                (0x401E0000u)
/** Peripheral SAI1 base pointer */
#define SAI1                                     ((I2S_Type *)SAI1_BASE)
/** Peripheral SAI3 base address */
#define SAI3_BASE                                (0x401E8000u)
/** Peripheral SAI3 base pointer */
#define SAI3                                     ((I2S_Type *)SAI3_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, 0u, SAI3_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, (I2S_Type *)0u, SAI3 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, NotAvail_IRQn, SAI3_RX_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, NotAvail_IRQn, SAI3_TX_IRQn }

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
#define LPI2C1_BASE                              (0x401A4000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x401A8000u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, LPI2C1_IRQn, LPI2C2_IRQn }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x40194000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x40198000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, LPSPI1_IRQn, LPSPI2_IRQn }

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
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn }

/* OCOTP - Peripheral instance base addresses */
/** Peripheral OCOTP base address */
#define OCOTP_BASE                               (0x401F4000u)
/** Peripheral OCOTP base pointer */
#define OCOTP                                    ((OCOTP_Type *)OCOTP_BASE)
/** Array initializer of OCOTP peripheral base addresses */
#define OCOTP_BASE_ADDRS                         { OCOTP_BASE }
/** Array initializer of OCOTP peripheral base pointers */
#define OCOTP_BASE_PTRS                          { OCOTP }

/* OTFAD - Peripheral instance base addresses */
/** Peripheral OTFAD base address */
#define OTFAD_BASE                               (0x400A0000u)
/** Peripheral OTFAD base pointer */
#define OTFAD                                    ((OTFAD_Type *)OTFAD_BASE)
/** Array initializer of OTFAD peripheral base addresses */
#define OTFAD_BASE_ADDRS                         { OTFAD_BASE }
/** Array initializer of OTFAD peripheral base pointers */
#define OTFAD_BASE_PTRS                          { OTFAD }

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
#define PWM1_BASE                                (0x401CC000u)
/** Peripheral PWM1 base pointer */
#define PWM1                                     ((PWM_Type *)PWM1_BASE)
/** Array initializer of PWM peripheral base addresses */
#define PWM_BASE_ADDRS                           { 0u, PWM1_BASE }
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASE_PTRS                            { (PWM_Type *)0u, PWM1 }
/** Interrupt vectors for the PWM peripheral type */
#define PWM_CMP_IRQS                             { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn } }
#define PWM_RELOAD_IRQS                          { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn } }
#define PWM_CAPTURE_IRQS                         { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn } }
#define PWM_FAULT_IRQS                           { NotAvail_IRQn, PWM1_FAULT_IRQn }
#define PWM_RELOAD_ERROR_IRQS                    { NotAvail_IRQn, PWM1_FAULT_IRQn }

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
#define SPDIF_BASE                               (0x401DC000u)
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

/* USB - Peripheral instance base addresses */
/** Peripheral USB base address */
#define USB_BASE                                 (0x400E4000u)
/** Peripheral USB base pointer */
#define USB                                      ((USB_Type *)USB_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB }
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { USB_OTG1_IRQn }

/* USBNC - Peripheral instance base addresses */
/** Peripheral USBNC base address */
#define USBNC_BASE                               (0x400E4000u)
/** Peripheral USBNC base pointer */
#define USBNC                                    ((USBNC_Type *)USBNC_BASE)
/** Array initializer of USBNC peripheral base addresses */
#define USBNC_BASE_ADDRS                         { USBNC_BASE }
/** Array initializer of USBNC peripheral base pointers */
#define USBNC_BASE_PTRS                          { USBNC }

/* USBPHY - Peripheral instance base addresses */
/** Peripheral USBPHY base address */
#define USBPHY_BASE                              (0x400D9000u)
/** Peripheral USBPHY base pointer */
#define USBPHY                                   ((USBPHY_Type *)USBPHY_BASE)
/** Array initializer of USBPHY peripheral base addresses */
#define USBPHY_BASE_ADDRS                        { USBPHY_BASE }
/** Array initializer of USBPHY peripheral base pointers */
#define USBPHY_BASE_PTRS                         { USBPHY }
/** Interrupt vectors for the USBPHY peripheral type */
#define USBPHY_IRQS                              { USB_PHY_IRQn }
/* Backward compatibility */
#define USBPHY_CTRL_ENDEVPLUGINDET_MASK     USBPHY_CTRL_ENDEVPLUGINDETECT_MASK
#define USBPHY_CTRL_ENDEVPLUGINDET_SHIFT    USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT
#define USBPHY_CTRL_ENDEVPLUGINDET(x)       USBPHY_CTRL_ENDEVPLUGINDETECT(x)
#define USBPHY_TX_TXCAL45DM_MASK            USBPHY_TX_TXCAL45DN_MASK
#define USBPHY_TX_TXCAL45DM_SHIFT           USBPHY_TX_TXCAL45DN_SHIFT
#define USBPHY_TX_TXCAL45DM(x)              USBPHY_TX_TXCAL45DN(x)


/* USB_ANALOG - Peripheral instance base addresses */
/** Peripheral USB_ANALOG base address */
#define USB_ANALOG_BASE                          (0x400D8000u)
/** Peripheral USB_ANALOG base pointer */
#define USB_ANALOG                               ((USB_ANALOG_Type *)USB_ANALOG_BASE)
/** Array initializer of USB_ANALOG peripheral base addresses */
#define USB_ANALOG_BASE_ADDRS                    { USB_ANALOG_BASE }
/** Array initializer of USB_ANALOG peripheral base pointers */
#define USB_ANALOG_BASE_PTRS                     { USB_ANALOG }

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
/** Peripheral XBARA base address */
#define XBARA_BASE                               (0x40098000u)
/** Peripheral XBARA base pointer */
#define XBARA                                    ((XBARA_Type *)XBARA_BASE)
/** Array initializer of XBARA peripheral base addresses */
#define XBARA_BASE_ADDRS                         { XBARA_BASE }
/** Array initializer of XBARA peripheral base pointers */
#define XBARA_BASE_PTRS                          { XBARA }

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


#endif  /* MIMXRT1011_COMMON_H_ */

