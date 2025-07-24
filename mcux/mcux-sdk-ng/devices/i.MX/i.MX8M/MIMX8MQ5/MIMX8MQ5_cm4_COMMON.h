/*
** ###################################################################
**     Processors:          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_cm4
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX8MDQLQRM, Rev. 0, Jan. 2018
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX8MQ5_cm4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMX8MQ5_cm4_COMMON.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMX8MQ5_cm4
 *
 * CMSIS Peripheral Access Layer for MIMX8MQ5_cm4
 */

#if !defined(MIMX8MQ5_CM4_COMMON_H_)
#define MIMX8MQ5_CM4_COMMON_H_                   /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0500U
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
  GPR_IRQ_IRQn                 = 0,                /**< GPR Interrupt. Used to notify cores on exception condition while boot. */
  DAP_IRQn                     = 1,                /**< DAP Interrupt */
  SDMA1_IRQn                   = 2,                /**< AND of all 48 SDMA interrupts (events) from all the channels */
  GPU_IRQn                     = 3,                /**< GPU Interrupt */
  SNVS_IRQn                    = 4,                /**< ON-OFF button press shorter than 5 seconds (pulse event) */
  LCDIF_IRQn                   = 5,                /**< LCDIF Sync Interrupt */
  SPDIF1_IRQn                  = 6,                /**< SPDIF1 Interrupt */
  H264_IRQn                    = 7,                /**< h264 Decoder Interrupt */
  VPUDMA_IRQn                  = 8,                /**< VPU DMA Interrupt */
  QOS_IRQn                     = 9,                /**< QOS interrupt */
  WDOG3_IRQn                   = 10,               /**< Watchdog Timer reset */
  HS_CP1_IRQn                  = 11,               /**< HS Interrupt Request */
  APBHDMA_IRQn                 = 12,               /**< GPMI operation channel 0-3 description complete interrupt */
  SPDIF2_IRQn                  = 13,               /**< SPDIF2 Interrupt */
  BCH_IRQn                     = 14,               /**< BCH operation complete interrupt */
  GPMI_IRQn                    = 15,               /**< GPMI operation TIMEOUT ERROR interrupt */
  HDMI_IRQ0_IRQn               = 16,               /**< HDMI Interrupt 0 */
  HDMI_IRQ1_IRQn               = 17,               /**< HDMI Interrupt 1 */
  HDMI_IRQ2_IRQn               = 18,               /**< HDMI Interrupt 2 */
  SNVS_Consolidated_IRQn       = 19,               /**< SRTC Consolidated Interrupt. Non TZ. */
  SNVS_Security_IRQn           = 20,               /**< SRTC Security Interrupt. TZ. */
  CSU_IRQn                     = 21,               /**< CSU Interrupt Request. Indicates to the processor that one or more alarm inputs were asserted. */
  USDHC1_IRQn                  = 22,               /**< uSDHC1 Enhanced SDHC Interrupt Request */
  USDHC2_IRQn                  = 23,               /**< uSDHC2 Enhanced SDHC Interrupt Request */
  DDC_IRQn                     = 24,               /**< DC8000 Display Controller IRQ */
  DTRC_IRQn                    = 25,               /**< DTRC interrupt */
  UART1_IRQn                   = 26,               /**< UART-1 ORed interrupt */
  UART2_IRQn                   = 27,               /**< UART-2 ORed interrupt */
  UART3_IRQn                   = 28,               /**< UART-3 ORed interrupt */
  UART4_IRQn                   = 29,               /**< UART-4 ORed interrupt */
  VP9_IRQn                     = 30,               /**< VP9 Decoder interrupt */
  ECSPI1_IRQn                  = 31,               /**< ECSPI1 interrupt request line to the core. */
  ECSPI2_IRQn                  = 32,               /**< ECSPI2 interrupt request line to the core. */
  ECSPI3_IRQn                  = 33,               /**< ECSPI3 interrupt request line to the core. */
  MIPI_DSI_IRQn                = 34,               /**< DSI Interrupt */
  I2C1_IRQn                    = 35,               /**< I2C-1 Interrupt */
  I2C2_IRQn                    = 36,               /**< I2C-2 Interrupt */
  I2C3_IRQn                    = 37,               /**< I2C-3 Interrupt */
  I2C4_IRQn                    = 38,               /**< I2C-4 Interrupt */
  RDC_IRQn                     = 39,               /**< RDC interrupt */
  USB1_IRQn                    = 40,               /**< USB1 Interrupt */
  USB2_IRQn                    = 41,               /**< USB1 Interrupt */
  CSI1_IRQn                    = 42,               /**< CSI1 interrupt */
  CSI2_IRQn                    = 43,               /**< CSI2 interrupt */
  MIPI_CSI1_IRQn               = 44,               /**< MIPI-CSI-1 Interrupt */
  MIPI_CSI2_IRQn               = 45,               /**< MIPI-CSI-2 Interrupt */
  GPT6_IRQn                    = 46,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  SCTR_IRQ0_IRQn               = 47,               /**< ISO7816IP Interrupt 0 */
  SCTR_IRQ1_IRQn               = 48,               /**< ISO7816IP Interrupt 1 */
  TEMPMON_IRQn                 = 49,               /**< TempSensor (Temperature alarm). */
  I2S3_IRQn                    = 50,               /**< SAI3 Receive / Transmit Interrupt */
  GPT5_IRQn                    = 51,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  GPT4_IRQn                    = 52,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  GPT3_IRQn                    = 53,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  GPT2_IRQn                    = 54,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  GPT1_IRQn                    = 55,               /**< OR of GPT Rollover interrupt line, Input Capture 1 and 2 lines, Output Compare 1, 2, and 3 Interrupt lines */
  GPIO1_INT7_IRQn              = 56,               /**< Active HIGH Interrupt from INT7 from GPIO */
  GPIO1_INT6_IRQn              = 57,               /**< Active HIGH Interrupt from INT6 from GPIO */
  GPIO1_INT5_IRQn              = 58,               /**< Active HIGH Interrupt from INT5 from GPIO */
  GPIO1_INT4_IRQn              = 59,               /**< Active HIGH Interrupt from INT4 from GPIO */
  GPIO1_INT3_IRQn              = 60,               /**< Active HIGH Interrupt from INT3 from GPIO */
  GPIO1_INT2_IRQn              = 61,               /**< Active HIGH Interrupt from INT2 from GPIO */
  GPIO1_INT1_IRQn              = 62,               /**< Active HIGH Interrupt from INT1 from GPIO */
  GPIO1_INT0_IRQn              = 63,               /**< Active HIGH Interrupt from INT0 from GPIO */
  GPIO1_Combined_0_15_IRQn     = 64,               /**< Combined interrupt indication for GPIO1 signal 0 throughout 15 */
  GPIO1_Combined_16_31_IRQn    = 65,               /**< Combined interrupt indication for GPIO1 signal 16 throughout 31 */
  GPIO2_Combined_0_15_IRQn     = 66,               /**< Combined interrupt indication for GPIO2 signal 0 throughout 15 */
  GPIO2_Combined_16_31_IRQn    = 67,               /**< Combined interrupt indication for GPIO2 signal 16 throughout 31 */
  GPIO3_Combined_0_15_IRQn     = 68,               /**< Combined interrupt indication for GPIO3 signal 0 throughout 15 */
  GPIO3_Combined_16_31_IRQn    = 69,               /**< Combined interrupt indication for GPIO3 signal 16 throughout 31 */
  GPIO4_Combined_0_15_IRQn     = 70,               /**< Combined interrupt indication for GPIO4 signal 0 throughout 15 */
  GPIO4_Combined_16_31_IRQn    = 71,               /**< Combined interrupt indication for GPIO4 signal 16 throughout 31 */
  GPIO5_Combined_0_15_IRQn     = 72,               /**< Combined interrupt indication for GPIO5 signal 0 throughout 15 */
  GPIO5_Combined_16_31_IRQn    = 73,               /**< Combined interrupt indication for GPIO5 signal 16 throughout 31 */
  PCIE_CTRL2_IRQ0_IRQn         = 74,               /**< Coming from GLUE logic, of set / reset FF, driven by PCIE signals. */
  PCIE_CTRL2_IRQ1_IRQn         = 75,               /**< Coming from GLUE logic, of set / reset FF, driven by PCIE signals. */
  PCIE_CTRL2_IRQ2_IRQn         = 76,               /**< Coming from GLUE logic, of set / reset FF, driven by PCIE signals. */
  PCIE_CTRL2_IRQ3_IRQn         = 77,               /**< Coming from GLUE logic, of set / reset FF, driven by PCIE signals. */
  WDOG1_IRQn                   = 78,               /**< Watchdog Timer reset */
  WDOG2_IRQn                   = 79,               /**< Watchdog Timer reset */
  PCIE_CTRL2_IRQn              = 80,               /**< Channels [63:32] interrupts requests */
  PWM1_IRQn                    = 81,               /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line. */
  PWM2_IRQn                    = 82,               /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line. */
  PWM3_IRQn                    = 83,               /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line. */
  PWM4_IRQn                    = 84,               /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line. */
  CCM_IRQ1_IRQn                = 85,               /**< CCM, Interrupt Request 1 */
  CCM_IRQ2_IRQn                = 86,               /**< CCM, Interrupt Request 2 */
  GPC_IRQn                     = 87,               /**< GPC Interrupt Request 1 */
  MU_A53_IRQn                  = 88,               /**< Interrupt to A53 */
  SRC_IRQn                     = 89,               /**< SRC interrupt request */
  I2S56_IRQn                   = 90,               /**< SAI5/6 Receive / Transmit Interrupt */
  RTIC_IRQn                    = 91,               /**< RTIC Interrupt */
  CPU_PerformanceUnit_IRQn     = 92,               /**< Performance Unit Interrupts from Cheetah (interrnally: PMUIRQ[n] */
  CPU_CTI_Trigger_IRQn         = 93,               /**< CTI trigger outputs (internal: nCTIIRQ[n] */
  SRC_Combined_IRQn            = 94,               /**< Combined CPU wdog interrupts (4x) out of SRC. */
  I2S1_IRQn                    = 95,               /**< SAI1 Receive / Transmit Interrupt */
  I2S2_IRQn                    = 96,               /**< SAI2 Receive / Transmit Interrupt */
  MU_M4_IRQn                   = 97,               /**< Interrupt to M4 */
  DDR_PerformanceMonitor_IRQn  = 98,               /**< ddr Interrupt for performance monitor */
  DDR_IRQn                     = 99,               /**< ddr Interrupt */
  I2S4_IRQn                    = 100,              /**< SAI4 Receive / Transmit Interrupt */
  CPU_Error_AXI_IRQn           = 101,              /**< CPU Error indicator for AXI transaction with a write response error condition */
  CPU_Error_L2RAM_IRQn         = 102,              /**< CPU Error indicator for L2 RAM double-bit ECC error */
  SDMA2_IRQn                   = 103,              /**< AND of all 48 SDMA interrupts (events) from all the channels */
  Reserved120_IRQn             = 104,              /**< Reserved */
  CAAM_IRQ0_IRQn               = 105,              /**< CAAM interrupt queue for JQ */
  CAAM_IRQ1_IRQn               = 106,              /**< CAAM interrupt queue for JQ */
  QSPI_IRQn                    = 107,              /**< QSPI Interrupt */
  TZASC_IRQn                   = 108,              /**< TZASC (PL380) interrupt */
  Reserved125_IRQn             = 109,              /**< Reserved */
  Reserved126_IRQn             = 110,              /**< Reserved */
  Reserved127_IRQn             = 111,              /**< Reserved */
  PERFMON1_IRQn                = 112,              /**< General Interrupt */
  PERFMON2_IRQn                = 113,              /**< General Interrupt */
  CAAM_IRQ2_IRQn               = 114,              /**< CAAM interrupt queue for JQ */
  CAAM_ERROR_IRQn              = 115,              /**< Recoverable error interrupt */
  HS_CP0_IRQn                  = 116,              /**< HS Interrupt Request */
  HEVC_IRQn                    = 117,              /**< HEVC interrupt */
  ENET1_MAC0_Rx_Tx_Done1_IRQn  = 118,              /**< MAC 0 Receive / Trasmit Frame / Buffer Done */
  ENET1_MAC0_Rx_Tx_Done2_IRQn  = 119,              /**< MAC 0 Receive / Trasmit Frame / Buffer Done */
  ENET1_IRQn                   = 120,              /**< MAC 0 IRQ */
  ENET1_1588_Timer_IRQn        = 121,              /**< MAC 0 1588 Timer Interrupt - synchronous */
  PCIE_CTRL1_IRQ0_IRQn         = 122,              /**< Coming from GLUE logic, of set / reset FF, driven by PCIE signals. */
  PCIE_CTRL1_IRQ1_IRQn         = 123,              /**< Coming from GLUE logic, of set / reset FF, driven by PCIE signals. */
  PCIE_CTRL1_IRQ2_IRQn         = 124,              /**< Coming from GLUE logic, of set / reset FF, driven by PCIE signals. */
  PCIE_CTRL1_IRQ3_IRQn         = 125,              /**< Coming from GLUE logic, of set / reset FF, driven by PCIE signals. */
  Reserved142_IRQn             = 126,              /**< Reserved */
  PCIE_CTRL1_IRQn              = 127               /**< Channels [63:32] interrupts requests */
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

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */

#include "core_cm4.h"                  /* Core Peripheral Access Layer */
#include "system_MIMX8MQ5_cm4.h"       /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMX8MQ5_cm4_SERIES
#define MIMX8MQ5_cm4_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMX8MQ5_cm4_features.h"

/* AIPSTZ - Peripheral instance base addresses */
/** Peripheral AIPSTZ1 base address */
#define AIPSTZ1_BASE                             (0x301F0000u)
/** Peripheral AIPSTZ1 base pointer */
#define AIPSTZ1                                  ((AIPSTZ_Type *)AIPSTZ1_BASE)
/** Peripheral AIPSTZ2 base address */
#define AIPSTZ2_BASE                             (0x305F0000u)
/** Peripheral AIPSTZ2 base pointer */
#define AIPSTZ2                                  ((AIPSTZ_Type *)AIPSTZ2_BASE)
/** Peripheral AIPSTZ3 base address */
#define AIPSTZ3_BASE                             (0x309F0000u)
/** Peripheral AIPSTZ3 base pointer */
#define AIPSTZ3                                  ((AIPSTZ_Type *)AIPSTZ3_BASE)
/** Peripheral AIPSTZ4 base address */
#define AIPSTZ4_BASE                             (0x32DF0000u)
/** Peripheral AIPSTZ4 base pointer */
#define AIPSTZ4                                  ((AIPSTZ_Type *)AIPSTZ4_BASE)
/** Array initializer of AIPSTZ peripheral base addresses */
#define AIPSTZ_BASE_ADDRS                        { 0u, AIPSTZ1_BASE, AIPSTZ2_BASE, AIPSTZ3_BASE, AIPSTZ4_BASE }
/** Array initializer of AIPSTZ peripheral base pointers */
#define AIPSTZ_BASE_PTRS                         { (AIPSTZ_Type *)0u, AIPSTZ1, AIPSTZ2, AIPSTZ3, AIPSTZ4 }

/* APBH - Peripheral instance base addresses */
/** Peripheral APBH base address */
#define APBH_BASE                                (0x33000000u)
/** Peripheral APBH base pointer */
#define APBH                                     ((APBH_Type *)APBH_BASE)
/** Array initializer of APBH peripheral base addresses */
#define APBH_BASE_ADDRS                          { APBH_BASE }
/** Array initializer of APBH peripheral base pointers */
#define APBH_BASE_PTRS                           { APBH }
/** Interrupt vectors for the APBH peripheral type */
#define APBH_IRQS                                { APBHDMA_IRQn }

/* BCH - Peripheral instance base addresses */
/** Peripheral BCH base address */
#define BCH_BASE                                 (0x33004000u)
/** Peripheral BCH base pointer */
#define BCH                                      ((BCH_Type *)BCH_BASE)
/** Array initializer of BCH peripheral base addresses */
#define BCH_BASE_ADDRS                           { BCH_BASE }
/** Array initializer of BCH peripheral base pointers */
#define BCH_BASE_PTRS                            { BCH }
/** Interrupt vectors for the BCH peripheral type */
#define BCH_IRQS                                 { BCH_IRQn }

/* BLK_CTL - Peripheral instance base addresses */
/** Peripheral DCSS__BLK_CTL base address */
#define DCSS__BLK_CTL_BASE                       (0x32E2F000u)
/** Peripheral DCSS__BLK_CTL base pointer */
#define DCSS__BLK_CTL                            ((BLK_CTL_Type *)DCSS__BLK_CTL_BASE)
/** Array initializer of BLK_CTL peripheral base addresses */
#define BLK_CTL_BASE_ADDRS                       { DCSS__BLK_CTL_BASE }
/** Array initializer of BLK_CTL peripheral base pointers */
#define BLK_CTL_BASE_PTRS                        { DCSS__BLK_CTL }

/* CCM - Peripheral instance base addresses */
/** Peripheral CCM base address */
#define CCM_BASE                                 (0x30380000u)
/** Peripheral CCM base pointer */
#define CCM                                      ((CCM_Type *)CCM_BASE)
/** Array initializer of CCM peripheral base addresses */
#define CCM_BASE_ADDRS                           { CCM_BASE }
/** Array initializer of CCM peripheral base pointers */
#define CCM_BASE_PTRS                            { CCM }
/** Interrupt vectors for the CCM peripheral type */
#define CCM_IRQS                                 { CCM_IRQ1_IRQn, CCM_IRQ2_IRQn }

/* CCM_ANALOG - Peripheral instance base addresses */
/** Peripheral CCM_ANALOG base address */
#define CCM_ANALOG_BASE                          (0x30360000u)
/** Peripheral CCM_ANALOG base pointer */
#define CCM_ANALOG                               ((CCM_ANALOG_Type *)CCM_ANALOG_BASE)
/** Array initializer of CCM_ANALOG peripheral base addresses */
#define CCM_ANALOG_BASE_ADDRS                    { CCM_ANALOG_BASE }
/** Array initializer of CCM_ANALOG peripheral base pointers */
#define CCM_ANALOG_BASE_PTRS                     { CCM_ANALOG }

/* CTX_LD - Peripheral instance base addresses */
/** Peripheral DCSS__CTX_LD base address */
#define DCSS__CTX_LD_BASE                        (0x32E23000u)
/** Peripheral DCSS__CTX_LD base pointer */
#define DCSS__CTX_LD                             ((CTX_LD_Type *)DCSS__CTX_LD_BASE)
/** Array initializer of CTX_LD peripheral base addresses */
#define CTX_LD_BASE_ADDRS                        { DCSS__CTX_LD_BASE }
/** Array initializer of CTX_LD peripheral base pointers */
#define CTX_LD_BASE_PTRS                         { DCSS__CTX_LD }

/* DDRC - Peripheral instance base addresses */
/** Peripheral DDRC base address */
#define DDRC_BASE                                (0x3D400000u)
/** Peripheral DDRC base pointer */
#define DDRC                                     ((DDRC_Type *)DDRC_BASE)
/** Array initializer of DDRC peripheral base addresses */
#define DDRC_BASE_ADDRS                          { DDRC_BASE }
/** Array initializer of DDRC peripheral base pointers */
#define DDRC_BASE_PTRS                           { DDRC }

/* DEC400D - Peripheral instance base addresses */
/** Peripheral DCSS__DEC400D base address */
#define DCSS__DEC400D_BASE                       (0x32E15000u)
/** Peripheral DCSS__DEC400D base pointer */
#define DCSS__DEC400D                            ((DEC400D_Type *)DCSS__DEC400D_BASE)
/** Array initializer of DEC400D peripheral base addresses */
#define DEC400D_BASE_ADDRS                       { DCSS__DEC400D_BASE }
/** Array initializer of DEC400D peripheral base pointers */
#define DEC400D_BASE_PTRS                        { DCSS__DEC400D }

/* DPR - Peripheral instance base addresses */
/** Peripheral DCSS__DPR1 base address */
#define DCSS__DPR1_BASE                          (0x32E18000u)
/** Peripheral DCSS__DPR1 base pointer */
#define DCSS__DPR1                               ((DPR_Type *)DCSS__DPR1_BASE)
/** Peripheral DCSS__DPR2 base address */
#define DCSS__DPR2_BASE                          (0x32E19000u)
/** Peripheral DCSS__DPR2 base pointer */
#define DCSS__DPR2                               ((DPR_Type *)DCSS__DPR2_BASE)
/** Peripheral DCSS__DPR3 base address */
#define DCSS__DPR3_BASE                          (0x32E1A000u)
/** Peripheral DCSS__DPR3 base pointer */
#define DCSS__DPR3                               ((DPR_Type *)DCSS__DPR3_BASE)
/** Array initializer of DPR peripheral base addresses */
#define DPR_BASE_ADDRS                           { 0u, DCSS__DPR1_BASE, DCSS__DPR2_BASE, DCSS__DPR3_BASE }
/** Array initializer of DPR peripheral base pointers */
#define DPR_BASE_PTRS                            { (DPR_Type *)0u, DCSS__DPR1, DCSS__DPR2, DCSS__DPR3 }

/* DTG - Peripheral instance base addresses */
/** Peripheral DCSS__DTG base address */
#define DCSS__DTG_BASE                           (0x32E20000u)
/** Peripheral DCSS__DTG base pointer */
#define DCSS__DTG                                ((DTG_Type *)DCSS__DTG_BASE)
/** Array initializer of DTG peripheral base addresses */
#define DTG_BASE_ADDRS                           { DCSS__DTG_BASE }
/** Array initializer of DTG peripheral base pointers */
#define DTG_BASE_PTRS                            { DCSS__DTG }

/* DTRC - Peripheral instance base addresses */
/** Peripheral DCSS__DTRC1 base address */
#define DCSS__DTRC1_BASE                         (0x32E16000u)
/** Peripheral DCSS__DTRC1 base pointer */
#define DCSS__DTRC1                              ((DTRC_Type *)DCSS__DTRC1_BASE)
/** Peripheral DCSS__DTRC2 base address */
#define DCSS__DTRC2_BASE                         (0x32E17000u)
/** Peripheral DCSS__DTRC2 base pointer */
#define DCSS__DTRC2                              ((DTRC_Type *)DCSS__DTRC2_BASE)
/** Array initializer of DTRC peripheral base addresses */
#define DTRC_BASE_ADDRS                          { 0u, DCSS__DTRC1_BASE, DCSS__DTRC2_BASE }
/** Array initializer of DTRC peripheral base pointers */
#define DTRC_BASE_PTRS                           { (DTRC_Type *)0u, DCSS__DTRC1, DCSS__DTRC2 }

/* ECSPI - Peripheral instance base addresses */
/** Peripheral ECSPI1 base address */
#define ECSPI1_BASE                              (0x30820000u)
/** Peripheral ECSPI1 base pointer */
#define ECSPI1                                   ((ECSPI_Type *)ECSPI1_BASE)
/** Peripheral ECSPI2 base address */
#define ECSPI2_BASE                              (0x30830000u)
/** Peripheral ECSPI2 base pointer */
#define ECSPI2                                   ((ECSPI_Type *)ECSPI2_BASE)
/** Peripheral ECSPI3 base address */
#define ECSPI3_BASE                              (0x30840000u)
/** Peripheral ECSPI3 base pointer */
#define ECSPI3                                   ((ECSPI_Type *)ECSPI3_BASE)
/** Array initializer of ECSPI peripheral base addresses */
#define ECSPI_BASE_ADDRS                         { 0u, ECSPI1_BASE, ECSPI2_BASE, ECSPI3_BASE }
/** Array initializer of ECSPI peripheral base pointers */
#define ECSPI_BASE_PTRS                          { (ECSPI_Type *)0u, ECSPI1, ECSPI2, ECSPI3 }
/** Interrupt vectors for the ECSPI peripheral type */
#define ECSPI_IRQS                               { NotAvail_IRQn, ECSPI1_IRQn, ECSPI2_IRQn, ECSPI3_IRQn }

/* ENET - Peripheral instance base addresses */
/** Peripheral ENET1 base address */
#define ENET1_BASE                               (0x30BE0000u)
/** Peripheral ENET1 base pointer */
#define ENET1                                    ((ENET_Type *)ENET1_BASE)
/** Array initializer of ENET peripheral base addresses */
#define ENET_BASE_ADDRS                          { ENET1_BASE }
/** Array initializer of ENET peripheral base pointers */
#define ENET_BASE_PTRS                           { ENET1 }
/** Interrupt vectors for the ENET peripheral type */
#define ENET_Transmit_IRQS                       { ENET1_IRQn }
#define ENET_Receive_IRQS                        { ENET1_IRQn }
#define ENET_Error_IRQS                          { ENET1_IRQn }
#define ENET_1588_Timer_IRQS                     { ENET1_1588_Timer_IRQn }
#define ENET_Ts_IRQS                             { ENET1_1588_Timer_IRQn }

/* GPC - Peripheral instance base addresses */
/** Peripheral GPC base address */
#define GPC_BASE                                 (0x303A0000u)
/** Peripheral GPC base pointer */
#define GPC                                      ((GPC_Type *)GPC_BASE)
/** Array initializer of GPC peripheral base addresses */
#define GPC_BASE_ADDRS                           { GPC_BASE }
/** Array initializer of GPC peripheral base pointers */
#define GPC_BASE_PTRS                            { GPC }
/** Interrupt vectors for the GPC peripheral type */
#define GPC_IRQS                                 { GPC_IRQn }

/* GPC_PGC - Peripheral instance base addresses */
/** Peripheral GPC_PGC base address */
#define GPC_PGC_BASE                             (0x303A0800u)
/** Peripheral GPC_PGC base pointer */
#define GPC_PGC                                  ((GPC_PGC_Type *)GPC_PGC_BASE)
/** Array initializer of GPC_PGC peripheral base addresses */
#define GPC_PGC_BASE_ADDRS                       { GPC_PGC_BASE }
/** Array initializer of GPC_PGC peripheral base pointers */
#define GPC_PGC_BASE_PTRS                        { GPC_PGC }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO1 base address */
#define GPIO1_BASE                               (0x30200000u)
/** Peripheral GPIO1 base pointer */
#define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
/** Peripheral GPIO2 base address */
#define GPIO2_BASE                               (0x30210000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO3 base address */
#define GPIO3_BASE                               (0x30220000u)
/** Peripheral GPIO3 base pointer */
#define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
/** Peripheral GPIO4 base address */
#define GPIO4_BASE                               (0x30230000u)
/** Peripheral GPIO4 base pointer */
#define GPIO4                                    ((GPIO_Type *)GPIO4_BASE)
/** Peripheral GPIO5 base address */
#define GPIO5_BASE                               (0x30240000u)
/** Peripheral GPIO5 base pointer */
#define GPIO5                                    ((GPIO_Type *)GPIO5_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { 0u, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { (GPIO_Type *)0u, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5 }
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS                                { NotAvail_IRQn, GPIO1_INT0_IRQn, GPIO1_INT1_IRQn, GPIO1_INT2_IRQn, GPIO1_INT3_IRQn, GPIO1_INT4_IRQn, GPIO1_INT5_IRQn, GPIO1_INT6_IRQn, GPIO1_INT7_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }
#define GPIO_COMBINED_LOW_IRQS                   { NotAvail_IRQn, GPIO1_Combined_0_15_IRQn, GPIO2_Combined_0_15_IRQn, GPIO3_Combined_0_15_IRQn, GPIO4_Combined_0_15_IRQn, GPIO5_Combined_0_15_IRQn }
#define GPIO_COMBINED_HIGH_IRQS                  { NotAvail_IRQn, GPIO1_Combined_16_31_IRQn, GPIO2_Combined_16_31_IRQn, GPIO3_Combined_16_31_IRQn, GPIO4_Combined_16_31_IRQn, GPIO5_Combined_16_31_IRQn }

/* GPMI - Peripheral instance base addresses */
/** Peripheral GPMI base address */
#define GPMI_BASE                                (0x33002000u)
/** Peripheral GPMI base pointer */
#define GPMI                                     ((GPMI_Type *)GPMI_BASE)
/** Array initializer of GPMI peripheral base addresses */
#define GPMI_BASE_ADDRS                          { GPMI_BASE }
/** Array initializer of GPMI peripheral base pointers */
#define GPMI_BASE_PTRS                           { GPMI }
/** Interrupt vectors for the GPMI peripheral type */
#define GPMI_IRQS                                { GPMI_IRQn }

/* GPT - Peripheral instance base addresses */
/** Peripheral GPT1 base address */
#define GPT1_BASE                                (0x302D0000u)
/** Peripheral GPT1 base pointer */
#define GPT1                                     ((GPT_Type *)GPT1_BASE)
/** Peripheral GPT2 base address */
#define GPT2_BASE                                (0x302E0000u)
/** Peripheral GPT2 base pointer */
#define GPT2                                     ((GPT_Type *)GPT2_BASE)
/** Peripheral GPT3 base address */
#define GPT3_BASE                                (0x302F0000u)
/** Peripheral GPT3 base pointer */
#define GPT3                                     ((GPT_Type *)GPT3_BASE)
/** Peripheral GPT4 base address */
#define GPT4_BASE                                (0x30700000u)
/** Peripheral GPT4 base pointer */
#define GPT4                                     ((GPT_Type *)GPT4_BASE)
/** Peripheral GPT5 base address */
#define GPT5_BASE                                (0x306F0000u)
/** Peripheral GPT5 base pointer */
#define GPT5                                     ((GPT_Type *)GPT5_BASE)
/** Peripheral GPT6 base address */
#define GPT6_BASE                                (0x306E0000u)
/** Peripheral GPT6 base pointer */
#define GPT6                                     ((GPT_Type *)GPT6_BASE)
/** Array initializer of GPT peripheral base addresses */
#define GPT_BASE_ADDRS                           { 0u, GPT1_BASE, GPT2_BASE, GPT3_BASE, GPT4_BASE, GPT5_BASE, GPT6_BASE }
/** Array initializer of GPT peripheral base pointers */
#define GPT_BASE_PTRS                            { (GPT_Type *)0u, GPT1, GPT2, GPT3, GPT4, GPT5, GPT6 }
/** Interrupt vectors for the GPT peripheral type */
#define GPT_IRQS                                 { NotAvail_IRQn, GPT1_IRQn, GPT2_IRQn, GPT3_IRQn, GPT4_IRQn, GPT5_IRQn, GPT6_IRQn }

/* HDMI_TX - Peripheral instance base addresses */
/** Peripheral HDMI_TX base address */
#define HDMI_TX_BASE                             (0x32C00000u)
/** Peripheral HDMI_TX base pointer */
#define HDMI_TX                                  ((HDMI_TX_Type *)HDMI_TX_BASE)
/** Array initializer of HDMI_TX peripheral base addresses */
#define HDMI_TX_BASE_ADDRS                       { HDMI_TX_BASE }
/** Array initializer of HDMI_TX peripheral base pointers */
#define HDMI_TX_BASE_PTRS                        { HDMI_TX }

/* I2C - Peripheral instance base addresses */
/** Peripheral I2C1 base address */
#define I2C1_BASE                                (0x30A20000u)
/** Peripheral I2C1 base pointer */
#define I2C1                                     ((I2C_Type *)I2C1_BASE)
/** Peripheral I2C2 base address */
#define I2C2_BASE                                (0x30A30000u)
/** Peripheral I2C2 base pointer */
#define I2C2                                     ((I2C_Type *)I2C2_BASE)
/** Peripheral I2C3 base address */
#define I2C3_BASE                                (0x30A40000u)
/** Peripheral I2C3 base pointer */
#define I2C3                                     ((I2C_Type *)I2C3_BASE)
/** Peripheral I2C4 base address */
#define I2C4_BASE                                (0x30A50000u)
/** Peripheral I2C4 base pointer */
#define I2C4                                     ((I2C_Type *)I2C4_BASE)
/** Array initializer of I2C peripheral base addresses */
#define I2C_BASE_ADDRS                           { 0u, I2C1_BASE, I2C2_BASE, I2C3_BASE, I2C4_BASE }
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { (I2C_Type *)0u, I2C1, I2C2, I2C3, I2C4 }
/** Interrupt vectors for the I2C peripheral type */
#define I2C_IRQS                                 { NotAvail_IRQn, I2C1_IRQn, I2C2_IRQn, I2C3_IRQn, I2C4_IRQn }

/* I2S - Peripheral instance base addresses */
/** Peripheral I2S1 base address */
#define I2S1_BASE                                (0x30010000u)
/** Peripheral I2S1 base pointer */
#define I2S1                                     ((I2S_Type *)I2S1_BASE)
/** Peripheral I2S2 base address */
#define I2S2_BASE                                (0x308B0000u)
/** Peripheral I2S2 base pointer */
#define I2S2                                     ((I2S_Type *)I2S2_BASE)
/** Peripheral I2S3 base address */
#define I2S3_BASE                                (0x308C0000u)
/** Peripheral I2S3 base pointer */
#define I2S3                                     ((I2S_Type *)I2S3_BASE)
/** Peripheral I2S4 base address */
#define I2S4_BASE                                (0x30050000u)
/** Peripheral I2S4 base pointer */
#define I2S4                                     ((I2S_Type *)I2S4_BASE)
/** Peripheral I2S5 base address */
#define I2S5_BASE                                (0x30040000u)
/** Peripheral I2S5 base pointer */
#define I2S5                                     ((I2S_Type *)I2S5_BASE)
/** Peripheral I2S6 base address */
#define I2S6_BASE                                (0x30030000u)
/** Peripheral I2S6 base pointer */
#define I2S6                                     ((I2S_Type *)I2S6_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { 0u, I2S1_BASE, I2S2_BASE, I2S3_BASE, I2S4_BASE, I2S5_BASE, I2S6_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { (I2S_Type *)0u, I2S1, I2S2, I2S3, I2S4, I2S5, I2S6 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, I2S1_IRQn, I2S2_IRQn, I2S3_IRQn, I2S4_IRQn, I2S56_IRQn, I2S56_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, I2S1_IRQn, I2S2_IRQn, I2S3_IRQn, I2S4_IRQn, I2S56_IRQn, I2S56_IRQn }

/* IOMUXC - Peripheral instance base addresses */
/** Peripheral IOMUXC base address */
#define IOMUXC_BASE                              (0x30330000u)
/** Peripheral IOMUXC base pointer */
#define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
/** Array initializer of IOMUXC peripheral base addresses */
#define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
/** Array initializer of IOMUXC peripheral base pointers */
#define IOMUXC_BASE_PTRS                         { IOMUXC }

/* IOMUXC_GPR - Peripheral instance base addresses */
/** Peripheral IOMUXC_GPR base address */
#define IOMUXC_GPR_BASE                          (0x30340000u)
/** Peripheral IOMUXC_GPR base pointer */
#define IOMUXC_GPR                               ((IOMUXC_GPR_Type *)IOMUXC_GPR_BASE)
/** Array initializer of IOMUXC_GPR peripheral base addresses */
#define IOMUXC_GPR_BASE_ADDRS                    { IOMUXC_GPR_BASE }
/** Array initializer of IOMUXC_GPR peripheral base pointers */
#define IOMUXC_GPR_BASE_PTRS                     { IOMUXC_GPR }

/* IRQ_STEER - Peripheral instance base addresses */
/** Peripheral IRQ_STEER base address */
#define IRQ_STEER_BASE                           (0x32E2D000u)
/** Peripheral IRQ_STEER base pointer */
#define IRQ_STEER                                ((IRQ_STEER_Type *)IRQ_STEER_BASE)
/** Array initializer of IRQ_STEER peripheral base addresses */
#define IRQ_STEER_BASE_ADDRS                     { IRQ_STEER_BASE }
/** Array initializer of IRQ_STEER peripheral base pointers */
#define IRQ_STEER_BASE_PTRS                      { IRQ_STEER }

/* LCDIF - Peripheral instance base addresses */
/** Peripheral LCDIF base address */
#define LCDIF_BASE                               (0x30320000u)
/** Peripheral LCDIF base pointer */
#define LCDIF                                    ((LCDIF_Type *)LCDIF_BASE)
/** Array initializer of LCDIF peripheral base addresses */
#define LCDIF_BASE_ADDRS                         { LCDIF_BASE }
/** Array initializer of LCDIF peripheral base pointers */
#define LCDIF_BASE_PTRS                          { LCDIF }

/* LMEM - Peripheral instance base addresses */
/** Peripheral LMEM base address */
#define LMEM_BASE                                (0xE0082000u)
/** Peripheral LMEM base pointer */
#define LMEM                                     ((LMEM_Type *)LMEM_BASE)
/** Array initializer of LMEM peripheral base addresses */
#define LMEM_BASE_ADDRS                          { LMEM_BASE }
/** Array initializer of LMEM peripheral base pointers */
#define LMEM_BASE_PTRS                           { LMEM }

/* LUT_LD - Peripheral instance base addresses */
/** Peripheral DCSS__LUT_LD base address */
#define DCSS__LUT_LD_BASE                        (0x32E24000u)
/** Peripheral DCSS__LUT_LD base pointer */
#define DCSS__LUT_LD                             ((LUT_LD_Type *)DCSS__LUT_LD_BASE)
/** Array initializer of LUT_LD peripheral base addresses */
#define LUT_LD_BASE_ADDRS                        { DCSS__LUT_LD_BASE }
/** Array initializer of LUT_LD peripheral base pointers */
#define LUT_LD_BASE_PTRS                         { DCSS__LUT_LD }

/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base address */
#define MCM_BASE                                 (0xE0080000u)
/** Peripheral MCM base pointer */
#define MCM                                      ((MCM_Type *)MCM_BASE)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS                           { MCM_BASE }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM }

/* MED_DC_SCALER - Peripheral instance base addresses */
/** Peripheral DCSS__MED_DC_SCALER base address */
#define DCSS__MED_DC_SCALER_BASE                 (0x32E1C000u)
/** Peripheral DCSS__MED_DC_SCALER base pointer */
#define DCSS__MED_DC_SCALER                      ((MED_DC_SCALER_Type *)DCSS__MED_DC_SCALER_BASE)
/** Array initializer of MED_DC_SCALER peripheral base addresses */
#define MED_DC_SCALER_BASE_ADDRS                 { DCSS__MED_DC_SCALER_BASE }
/** Array initializer of MED_DC_SCALER peripheral base pointers */
#define MED_DC_SCALER_BASE_PTRS                  { DCSS__MED_DC_SCALER }

/* MIPI_CSI2RX - Peripheral instance base addresses */
/** Peripheral MIPI_CSI2RX1 base address */
#define MIPI_CSI2RX1_BASE                        (0x30A70000u)
/** Peripheral MIPI_CSI2RX1 base pointer */
#define MIPI_CSI2RX1                             ((MIPI_CSI2RX_Type *)MIPI_CSI2RX1_BASE)
/** Peripheral MIPI_CSI2RX2 base address */
#define MIPI_CSI2RX2_BASE                        (0x30B60000u)
/** Peripheral MIPI_CSI2RX2 base pointer */
#define MIPI_CSI2RX2                             ((MIPI_CSI2RX_Type *)MIPI_CSI2RX2_BASE)
/** Array initializer of MIPI_CSI2RX peripheral base addresses */
#define MIPI_CSI2RX_BASE_ADDRS                   { 0u, MIPI_CSI2RX1_BASE, MIPI_CSI2RX2_BASE }
/** Array initializer of MIPI_CSI2RX peripheral base pointers */
#define MIPI_CSI2RX_BASE_PTRS                    { (MIPI_CSI2RX_Type *)0u, MIPI_CSI2RX1, MIPI_CSI2RX2 }

/* MIPI_DSI_HOST - Peripheral instance base addresses */
/** Peripheral MIPI_DSI_HOST base address */
#define MIPI_DSI_HOST_BASE                       (0x30A10000u)
/** Peripheral MIPI_DSI_HOST base pointer */
#define MIPI_DSI_HOST                            ((MIPI_DSI_HOST_Type *)MIPI_DSI_HOST_BASE)
/** Array initializer of MIPI_DSI_HOST peripheral base addresses */
#define MIPI_DSI_HOST_BASE_ADDRS                 { MIPI_DSI_HOST_BASE }
/** Array initializer of MIPI_DSI_HOST peripheral base pointers */
#define MIPI_DSI_HOST_BASE_PTRS                  { MIPI_DSI_HOST }

/* MIPI_DSI_HOST_APB_PKT_IF - Peripheral instance base addresses */
/** Peripheral MIPI_DSI_HOST_APB_PKT_IF base address */
#define MIPI_DSI_HOST_APB_PKT_IF_BASE            (0x30A10280u)
/** Peripheral MIPI_DSI_HOST_APB_PKT_IF base pointer */
#define MIPI_DSI_HOST_APB_PKT_IF                 ((MIPI_DSI_HOST_APB_PKT_IF_Type *)MIPI_DSI_HOST_APB_PKT_IF_BASE)
/** Array initializer of MIPI_DSI_HOST_APB_PKT_IF peripheral base addresses */
#define MIPI_DSI_HOST_APB_PKT_IF_BASE_ADDRS      { MIPI_DSI_HOST_APB_PKT_IF_BASE }
/** Array initializer of MIPI_DSI_HOST_APB_PKT_IF peripheral base pointers */
#define MIPI_DSI_HOST_APB_PKT_IF_BASE_PTRS       { MIPI_DSI_HOST_APB_PKT_IF }

/* MIPI_DSI_HOST_DPI_INTFC - Peripheral instance base addresses */
/** Peripheral MIPI_DSI_HOST_DPI_INTFC base address */
#define MIPI_DSI_HOST_DPI_INTFC_BASE             (0x30A10200u)
/** Peripheral MIPI_DSI_HOST_DPI_INTFC base pointer */
#define MIPI_DSI_HOST_DPI_INTFC                  ((MIPI_DSI_HOST_DPI_INTFC_Type *)MIPI_DSI_HOST_DPI_INTFC_BASE)
/** Array initializer of MIPI_DSI_HOST_DPI_INTFC peripheral base addresses */
#define MIPI_DSI_HOST_DPI_INTFC_BASE_ADDRS       { MIPI_DSI_HOST_DPI_INTFC_BASE }
/** Array initializer of MIPI_DSI_HOST_DPI_INTFC peripheral base pointers */
#define MIPI_DSI_HOST_DPI_INTFC_BASE_PTRS        { MIPI_DSI_HOST_DPI_INTFC }

/* MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC - Peripheral instance base addresses */
/** Peripheral MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC base address */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_BASE    (0x30A10300u)
/** Peripheral MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC base pointer */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC         ((MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_Type *)MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_BASE)
/** Array initializer of MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC peripheral base
 * addresses */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_BASE_ADDRS { MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_BASE }
/** Array initializer of MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC peripheral base
 * pointers */
#define MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC_BASE_PTRS { MIPI_DSI_HOST_FSL_IP1_DPHY_INTFC }

/* MU - Peripheral instance base addresses */
/** Peripheral MUB base address */
#define MUB_BASE                                 (0x30AB0000u)
/** Peripheral MUB base pointer */
#define MUB                                      ((MU_Type *)MUB_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MUB_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MUB }
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU_M4_IRQn }

/* OCOTP - Peripheral instance base addresses */
/** Peripheral OCOTP base address */
#define OCOTP_BASE                               (0x30350000u)
/** Peripheral OCOTP base pointer */
#define OCOTP                                    ((OCOTP_Type *)OCOTP_BASE)
/** Array initializer of OCOTP peripheral base addresses */
#define OCOTP_BASE_ADDRS                         { OCOTP_BASE }
/** Array initializer of OCOTP peripheral base pointers */
#define OCOTP_BASE_PTRS                          { OCOTP }

/* PWM - Peripheral instance base addresses */
/** Peripheral PWM1 base address */
#define PWM1_BASE                                (0x30660000u)
/** Peripheral PWM1 base pointer */
#define PWM1                                     ((PWM_Type *)PWM1_BASE)
/** Peripheral PWM2 base address */
#define PWM2_BASE                                (0x30670000u)
/** Peripheral PWM2 base pointer */
#define PWM2                                     ((PWM_Type *)PWM2_BASE)
/** Peripheral PWM3 base address */
#define PWM3_BASE                                (0x30680000u)
/** Peripheral PWM3 base pointer */
#define PWM3                                     ((PWM_Type *)PWM3_BASE)
/** Peripheral PWM4 base address */
#define PWM4_BASE                                (0x30690000u)
/** Peripheral PWM4 base pointer */
#define PWM4                                     ((PWM_Type *)PWM4_BASE)
/** Array initializer of PWM peripheral base addresses */
#define PWM_BASE_ADDRS                           { 0u, PWM1_BASE, PWM2_BASE, PWM3_BASE, PWM4_BASE }
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASE_PTRS                            { (PWM_Type *)0u, PWM1, PWM2, PWM3, PWM4 }
/** Interrupt vectors for the PWM peripheral type */
#define PWM_IRQS                                 { NotAvail_IRQn, PWM1_IRQn, PWM2_IRQn, PWM3_IRQn, PWM4_IRQn }

/* QuadSPI - Peripheral instance base addresses */
/** Peripheral QuadSPI base address */
#define QuadSPI_BASE                             (0x30BB0000u)
/** Peripheral QuadSPI base pointer */
#define QuadSPI                                  ((QuadSPI_Type *)QuadSPI_BASE)
/** Array initializer of QuadSPI peripheral base addresses */
#define QuadSPI_BASE_ADDRS                       { QuadSPI_BASE }
/** Array initializer of QuadSPI peripheral base pointers */
#define QuadSPI_BASE_PTRS                        { QuadSPI }
/** Interrupt vectors for the QuadSPI peripheral type */
#define QuadSPI_IRQS                             { QSPI_IRQn }

/* RDC - Peripheral instance base addresses */
/** Peripheral RDC base address */
#define RDC_BASE                                 (0x303D0000u)
/** Peripheral RDC base pointer */
#define RDC                                      ((RDC_Type *)RDC_BASE)
/** Array initializer of RDC peripheral base addresses */
#define RDC_BASE_ADDRS                           { RDC_BASE }
/** Array initializer of RDC peripheral base pointers */
#define RDC_BASE_PTRS                            { RDC }
/** Interrupt vectors for the RDC peripheral type */
#define RDC_IRQS                                 { RDC_IRQn }

/* RDC_SEMAPHORE - Peripheral instance base addresses */
/** Peripheral RDC_SEMAPHORE1 base address */
#define RDC_SEMAPHORE1_BASE                      (0x303B0000u)
/** Peripheral RDC_SEMAPHORE1 base pointer */
#define RDC_SEMAPHORE1                           ((RDC_SEMAPHORE_Type *)RDC_SEMAPHORE1_BASE)
/** Peripheral RDC_SEMAPHORE2 base address */
#define RDC_SEMAPHORE2_BASE                      (0x303C0000u)
/** Peripheral RDC_SEMAPHORE2 base pointer */
#define RDC_SEMAPHORE2                           ((RDC_SEMAPHORE_Type *)RDC_SEMAPHORE2_BASE)
/** Array initializer of RDC_SEMAPHORE peripheral base addresses */
#define RDC_SEMAPHORE_BASE_ADDRS                 { 0u, RDC_SEMAPHORE1_BASE, RDC_SEMAPHORE2_BASE }
/** Array initializer of RDC_SEMAPHORE peripheral base pointers */
#define RDC_SEMAPHORE_BASE_PTRS                  { (RDC_SEMAPHORE_Type *)0u, RDC_SEMAPHORE1, RDC_SEMAPHORE2 }

/* RD_SRC - Peripheral instance base addresses */
/** Peripheral DCSS__RD_SRC base address */
#define DCSS__RD_SRC_BASE                        (0x32E22000u)
/** Peripheral DCSS__RD_SRC base pointer */
#define DCSS__RD_SRC                             ((RD_SRC_Type *)DCSS__RD_SRC_BASE)
/** Array initializer of RD_SRC peripheral base addresses */
#define RD_SRC_BASE_ADDRS                        { DCSS__RD_SRC_BASE }
/** Array initializer of RD_SRC peripheral base pointers */
#define RD_SRC_BASE_PTRS                         { DCSS__RD_SRC }

/* ROMC - Peripheral instance base addresses */
/** Peripheral ROMC base address */
#define ROMC_BASE                                (0x30310000u)
/** Peripheral ROMC base pointer */
#define ROMC                                     ((ROMC_Type *)ROMC_BASE)
/** Array initializer of ROMC peripheral base addresses */
#define ROMC_BASE_ADDRS                          { ROMC_BASE }
/** Array initializer of ROMC peripheral base pointers */
#define ROMC_BASE_PTRS                           { ROMC }

/* SDMAARM - Peripheral instance base addresses */
/** Peripheral SDMAARM1 base address */
#define SDMAARM1_BASE                            (0x30BD0000u)
/** Peripheral SDMAARM1 base pointer */
#define SDMAARM1                                 ((SDMAARM_Type *)SDMAARM1_BASE)
/** Peripheral SDMAARM2 base address */
#define SDMAARM2_BASE                            (0x302C0000u)
/** Peripheral SDMAARM2 base pointer */
#define SDMAARM2                                 ((SDMAARM_Type *)SDMAARM2_BASE)
/** Array initializer of SDMAARM peripheral base addresses */
#define SDMAARM_BASE_ADDRS                       { 0u, SDMAARM1_BASE, SDMAARM2_BASE }
/** Array initializer of SDMAARM peripheral base pointers */
#define SDMAARM_BASE_PTRS                        { (SDMAARM_Type *)0u, SDMAARM1, SDMAARM2 }
/** Interrupt vectors for the SDMAARM peripheral type */
#define SDMAARM_IRQS                             { NotAvail_IRQn, SDMA1_IRQn, SDMA2_IRQn }

/* SEMA4 - Peripheral instance base addresses */
/** Peripheral SEMA4 base address */
#define SEMA4_BASE                               (0x30AC0000u)
/** Peripheral SEMA4 base pointer */
#define SEMA4                                    ((SEMA4_Type *)SEMA4_BASE)
/** Array initializer of SEMA4 peripheral base addresses */
#define SEMA4_BASE_ADDRS                         { SEMA4_BASE }
/** Array initializer of SEMA4 peripheral base pointers */
#define SEMA4_BASE_PTRS                          { SEMA4 }

/* SNVS - Peripheral instance base addresses */
/** Peripheral SNVS base address */
#define SNVS_BASE                                (0x30370000u)
/** Peripheral SNVS base pointer */
#define SNVS                                     ((SNVS_Type *)SNVS_BASE)
/** Array initializer of SNVS peripheral base addresses */
#define SNVS_BASE_ADDRS                          { SNVS_BASE }
/** Array initializer of SNVS peripheral base pointers */
#define SNVS_BASE_PTRS                           { SNVS }
/** Interrupt vectors for the SNVS peripheral type */
#define SNVS_IRQS                                { SNVS_IRQn }
#define SNVS_CONSOLIDATED_IRQS                   { SNVS_Consolidated_IRQn }
#define SNVS_SECURITY_IRQS                       { SNVS_Security_IRQn }

/* SPBA - Peripheral instance base addresses */
/** Peripheral SPBA1 base address */
#define SPBA1_BASE                               (0x308F0000u)
/** Peripheral SPBA1 base pointer */
#define SPBA1                                    ((SPBA_Type *)SPBA1_BASE)
/** Peripheral SPBA2 base address */
#define SPBA2_BASE                               (0x300F0000u)
/** Peripheral SPBA2 base pointer */
#define SPBA2                                    ((SPBA_Type *)SPBA2_BASE)
/** Array initializer of SPBA peripheral base addresses */
#define SPBA_BASE_ADDRS                          { 0u, SPBA1_BASE, SPBA2_BASE }
/** Array initializer of SPBA peripheral base pointers */
#define SPBA_BASE_PTRS                           { (SPBA_Type *)0u, SPBA1, SPBA2 }

/* SPDIF - Peripheral instance base addresses */
/** Peripheral SPDIF1 base address */
#define SPDIF1_BASE                              (0x30810000u)
/** Peripheral SPDIF1 base pointer */
#define SPDIF1                                   ((SPDIF_Type *)SPDIF1_BASE)
/** Peripheral SPDIF2 base address */
#define SPDIF2_BASE                              (0x308A0000u)
/** Peripheral SPDIF2 base pointer */
#define SPDIF2                                   ((SPDIF_Type *)SPDIF2_BASE)
/** Array initializer of SPDIF peripheral base addresses */
#define SPDIF_BASE_ADDRS                         { 0u, SPDIF1_BASE, SPDIF2_BASE }
/** Array initializer of SPDIF peripheral base pointers */
#define SPDIF_BASE_PTRS                          { (SPDIF_Type *)0u, SPDIF1, SPDIF2 }
/** Interrupt vectors for the SPDIF peripheral type */
#define SPDIF_IRQS                               { NotAvail_IRQn, SPDIF1_IRQn, SPDIF2_IRQn }

/* SRC - Peripheral instance base addresses */
/** Peripheral SRC base address */
#define SRC_BASE                                 (0x30390000u)
/** Peripheral SRC base pointer */
#define SRC                                      ((SRC_Type *)SRC_BASE)
/** Array initializer of SRC peripheral base addresses */
#define SRC_BASE_ADDRS                           { SRC_BASE }
/** Array initializer of SRC peripheral base pointers */
#define SRC_BASE_PTRS                            { SRC }
/** Interrupt vectors for the SRC peripheral type */
#define SRC_IRQS                                 { SRC_IRQn }
#define SRC_COMBINED_IRQS                        { SRC_Combined_IRQn }

/* SUBSAM - Peripheral instance base addresses */
/** Peripheral DCSS__SUBSAM base address */
#define DCSS__SUBSAM_BASE                        (0x32E1B000u)
/** Peripheral DCSS__SUBSAM base pointer */
#define DCSS__SUBSAM                             ((SUBSAM_Type *)DCSS__SUBSAM_BASE)
/** Array initializer of SUBSAM peripheral base addresses */
#define SUBSAM_BASE_ADDRS                        { DCSS__SUBSAM_BASE }
/** Array initializer of SUBSAM peripheral base pointers */
#define SUBSAM_BASE_PTRS                         { DCSS__SUBSAM }

/* TMU - Peripheral instance base addresses */
/** Peripheral TMU base address */
#define TMU_BASE                                 (0x30260000u)
/** Peripheral TMU base pointer */
#define TMU                                      ((TMU_Type *)TMU_BASE)
/** Array initializer of TMU peripheral base addresses */
#define TMU_BASE_ADDRS                           { TMU_BASE }
/** Array initializer of TMU peripheral base pointers */
#define TMU_BASE_PTRS                            { TMU }

/* UART - Peripheral instance base addresses */
/** Peripheral UART1 base address */
#define UART1_BASE                               (0x30860000u)
/** Peripheral UART1 base pointer */
#define UART1                                    ((UART_Type *)UART1_BASE)
/** Peripheral UART2 base address */
#define UART2_BASE                               (0x30890000u)
/** Peripheral UART2 base pointer */
#define UART2                                    ((UART_Type *)UART2_BASE)
/** Peripheral UART3 base address */
#define UART3_BASE                               (0x30880000u)
/** Peripheral UART3 base pointer */
#define UART3                                    ((UART_Type *)UART3_BASE)
/** Peripheral UART4 base address */
#define UART4_BASE                               (0x30A60000u)
/** Peripheral UART4 base pointer */
#define UART4                                    ((UART_Type *)UART4_BASE)
/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS                          { 0u, UART1_BASE, UART2_BASE, UART3_BASE, UART4_BASE }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                           { (UART_Type *)0u, UART1, UART2, UART3, UART4 }
/** Interrupt vectors for the UART peripheral type */
#define UART_IRQS                                { NotAvail_IRQn, UART1_IRQn, UART2_IRQn, UART3_IRQn, UART4_IRQn }

/* USDHC - Peripheral instance base addresses */
/** Peripheral uSDHC1 base address */
#define uSDHC1_BASE                              (0x30B40000u)
/** Peripheral uSDHC1 base pointer */
#define uSDHC1                                   ((USDHC_Type *)uSDHC1_BASE)
/** Peripheral uSDHC2 base address */
#define uSDHC2_BASE                              (0x30B50000u)
/** Peripheral uSDHC2 base pointer */
#define uSDHC2                                   ((USDHC_Type *)uSDHC2_BASE)
/** Array initializer of USDHC peripheral base addresses */
#define USDHC_BASE_ADDRS                         { 0u, uSDHC1_BASE, uSDHC2_BASE }
/** Array initializer of USDHC peripheral base pointers */
#define USDHC_BASE_PTRS                          { (USDHC_Type *)0u, uSDHC1, uSDHC2 }
/** Interrupt vectors for the USDHC peripheral type */
#define USDHC_IRQS                               { NotAvail_IRQn, USDHC1_IRQn, USDHC2_IRQn }

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG1 base address */
#define WDOG1_BASE                               (0x30280000u)
/** Peripheral WDOG1 base pointer */
#define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
/** Peripheral WDOG2 base address */
#define WDOG2_BASE                               (0x30290000u)
/** Peripheral WDOG2 base pointer */
#define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
/** Peripheral WDOG3 base address */
#define WDOG3_BASE                               (0x302A0000u)
/** Peripheral WDOG3 base pointer */
#define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { 0u, WDOG1_BASE, WDOG2_BASE, WDOG3_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { (WDOG_Type *)0u, WDOG1, WDOG2, WDOG3 }
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { NotAvail_IRQn, WDOG1_IRQn, WDOG2_IRQn, WDOG3_IRQn }

/* WR_SCL - Peripheral instance base addresses */
/** Peripheral DCSS__WR_SCL base address */
#define DCSS__WR_SCL_BASE                        (0x32E21000u)
/** Peripheral DCSS__WR_SCL base pointer */
#define DCSS__WR_SCL                             ((WR_SCL_Type *)DCSS__WR_SCL_BASE)
/** Array initializer of WR_SCL peripheral base addresses */
#define WR_SCL_BASE_ADDRS                        { DCSS__WR_SCL_BASE }
/** Array initializer of WR_SCL peripheral base pointers */
#define WR_SCL_BASE_PTRS                         { DCSS__WR_SCL }

/* XTALOSC - Peripheral instance base addresses */
/** Peripheral XTALOSC base address */
#define XTALOSC_BASE                             (0x30270000u)
/** Peripheral XTALOSC base pointer */
#define XTALOSC                                  ((XTALOSC_Type *)XTALOSC_BASE)
/** Array initializer of XTALOSC peripheral base addresses */
#define XTALOSC_BASE_ADDRS                       { XTALOSC_BASE }
/** Array initializer of XTALOSC peripheral base pointers */
#define XTALOSC_BASE_PTRS                        { XTALOSC }

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


#endif  /* MIMX8MQ5_CM4_COMMON_H_ */

