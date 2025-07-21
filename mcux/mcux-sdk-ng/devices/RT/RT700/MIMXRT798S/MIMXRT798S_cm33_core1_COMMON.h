/*
** ###################################################################
**     Processors:          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGFOA_cm33_core1
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    iMXRT700RM Rev.2 DraftA, 05/2024
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT798S_cm33_core1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMXRT798S_cm33_core1_COMMON.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMXRT798S_cm33_core1
 *
 * CMSIS Peripheral Access Layer for MIMXRT798S_cm33_core1
 */

#if !defined(MIMXRT798S_CM33_CORE1_COMMON_H_)
#define MIMXRT798S_CM33_CORE1_COMMON_H_          /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0300U
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
#define NUMBER_OF_INT_VECTORS 109                /**< Number of interrupts in the Vector table */

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
  Reserved16_IRQn              = 0,                /**< Reserved interrupt 16 */
  Reserved17_IRQn              = 1,                /**< Reserved interrupt 17 */
  Reserved18_IRQn              = 2,                /**< Reserved interrupt 18 */
  FRO2_IRQn                    = 3,                /**< FRO: 300MHz FRO in VDD1 domain Async interrupt */
  GLIKEY4_IRQn                 = 4,                /**< GLIKEY: Interrupt */
  UTICK1_IRQn                  = 5,                /**< Micro-tick Timer */
  MRT1_IRQn                    = 6,                /**< MRT: Ored Interrupt request */
  CTIMER5_IRQn                 = 7,                /**< CTIMER: Interrupt request */
  CTIMER6_IRQn                 = 8,                /**< CTIMER: Interrupt request */
  CTIMER7_IRQn                 = 9,                /**< CTIMER: Interrupt request */
  LPI2C15_IRQn                 = 10,               /**< LPI2C: Interrupt request */
  LP_FLEXCOMM17_IRQn           = 11,               /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM18_IRQn           = 12,               /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM19_IRQn           = 13,               /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM20_IRQn           = 14,               /**< FLEXCOMM: Interrupt request */
  ADC_IRQn                     = 15,               /**< ADC0: Interrupt request */
  SDADC_IRQn                   = 16,               /**< SDADC0: Interrupt request */
  GLIKEY1_IRQn                 = 17,               /**< GLIKEY: Interrupt */
  ACMP_IRQn                    = 18,               /**< ACMP: interrupt request */
  PDM_EVENT_IRQn               = 19,               /**< MIC: Interrupt request for read data or Error */
  HYPERVISOR_IRQn              = 20,               /**< SECURE: Sense domain Hypervisor interrupt */
  SECURE_VIOLATION_IRQn        = 21,               /**< SECURE: Sense domain Secure violation interrupt */
  PDM_HWVAD_EVENT_IRQn         = 22,               /**< MIC: Hardware Voice Activity Detector interrupt or error interrupt */
  RTC1_ALARM_IRQn              = 23,               /**< RTC: Alarm interrupt */
  RTC1_IRQn                    = 24,               /**< RTC: wakeup interrupt to Sense domain */
  HIFI1_IRQn                   = 25,               /**< HIFI1: Interrupt request */
  MU1_B_IRQn                   = 26,               /**< MU1: MUB, CPU1 to CPU0 */
  MU2_B_IRQn                   = 27,               /**< MU2: MUB, CPU1  to HiFi4 */
  MU3_A_IRQn                   = 28,               /**< MU3: MUA, CPU1 to HiFi1 */
  PMC_IRQn                     = 29,               /**< PMC: Sense domain Interrupt */
  OS_EVENT_IRQn                = 30,               /**< OSEVENT: Event timer CPU1 Wakeup/interrupt */
  USDHC0_IRQn                  = 31,               /**< USDHC: Interrupt request */
  USDHC1_IRQn                  = 32,               /**< USDHC: Interrupt request */
  I3C2_IRQn                    = 33,               /**< I3C: Interrupt Request */
  USB0_IRQn                    = 34,               /**< USB: HSUSB Interrup request */
  USB1_IRQn                    = 35,               /**< USB: eUSB Interrup request */
  WDT2_IRQn                    = 36,               /**< WDT: Interrupt request */
  WDT3_IRQn                    = 37,               /**< WDT: Interrupt request */
  USBPHY0_IRQn                 = 38,               /**< HSUSBPHY: UTM interrupt request */
  Reserved55_IRQn              = 39,               /**< Reserved interrupt 55 */
  I3C3_IRQn                    = 40,               /**< I3C: Interrupt Request */
  FLEXIO_IRQn                  = 41,               /**< flexio: Interrupt request */
  LCDIF_IRQn                   = 42,               /**< dcn: Interrupt request */
  VGPU_IRQn                    = 43,               /**< VGPU interrupt from graphics core */
  MIPI_IRQn                    = 44,               /**< DSI: Interrupt request */
  EDMA2_CH0_IRQn               = 45,               /**< edma2: Channel 0 interrupt */
  EDMA2_CH1_IRQn               = 46,               /**< edma2: Channel 1 interrupt */
  EDMA2_CH2_IRQn               = 47,               /**< edma2: Channel 2 interrupt */
  EDMA2_CH3_IRQn               = 48,               /**< edma2: Channel 3 interrupt */
  EDMA2_CH4_IRQn               = 49,               /**< edma2: Channel 4 interrupt */
  EDMA2_CH5_IRQn               = 50,               /**< edma2: Channel 5 interrupt */
  EDMA2_CH6_IRQn               = 51,               /**< edma2: Channel 6 interrupt */
  EDMA2_CH7_IRQn               = 52,               /**< edma2: Channel 7 interrupt */
  EDMA3_CH0_IRQn               = 53,               /**< edma3: Channel 0 interrupt */
  EDMA3_CH1_IRQn               = 54,               /**< edma3: Channel 1 interrupt */
  EDMA3_CH2_IRQn               = 55,               /**< edma3: Channel 2 interrupt */
  EDMA3_CH3_IRQn               = 56,               /**< edma3: Channel 3 interrupt */
  EDMA3_CH4_IRQn               = 57,               /**< edma3: Channel 4 interrupt */
  EDMA3_CH5_IRQn               = 58,               /**< edma3: Channel 5 interrupt */
  EDMA3_CH6_IRQn               = 59,               /**< edma3: Channel 6 interrupt */
  EDMA3_CH7_IRQn               = 60,               /**< edma3: Channel 7 interrupt */
  GPIO80_IRQn                  = 61,               /**< rgpio8: Interupt request, channel 0 */
  GPIO81_IRQn                  = 62,               /**< rgpio8: Interupt request, channel 1 */
  GPIO90_IRQn                  = 63,               /**< rgpio9: Interupt request, channel 0 */
  GPIO91_IRQn                  = 64,               /**< rgpio9: Interupt request, channel 1 */
  GPIO100_IRQn                 = 65,               /**< rgpio10: Interupt request, channel 0 */
  GPIO101_IRQn                 = 66,               /**< rgpio10: Interupt request, channel 1 */
  Reserved83_IRQn              = 67,               /**< Reserved interrupt 83 */
  Reserved84_IRQn              = 68,               /**< Reserved interrupt 84 */
  PIN_INT0_IRQn                = 69,               /**< pint1: Interupt request 0 */
  PIN_INT1_IRQn                = 70,               /**< pint1: Interupt request 1 */
  PIN_INT2_IRQn                = 71,               /**< pint1: Interupt request 2 */
  PIN_INT3_IRQn                = 72,               /**< pint1: Interupt request 3 */
  SAI3_IRQn                    = 73,               /**< sai3: TX/RX interrupt */
  XSPI2_IRQn                   = 74,               /**< xspi2: Ored interrupt */
  MMU2_IRQn                    = 75,               /**< mmu2: Interrupt request */
  Reserved92_IRQn              = 76,               /**< Reserved interrupt */
  GDET3_IRQn                   = 77,               /**< GDET3: Interrupt request */
  CDOG3_IRQn                   = 78,               /**< cdog3: Interrupt request */
  CDOG4_IRQn                   = 79,               /**< cdog4: Interrupt request */
  Reserved96_IRQn              = 80,               /**< Reserved interrupt 96 */
  CPU1_IRQn                    = 81,               /**< CTI interrupt request */
  JPEGDEC_IRQn                 = 82,               /**< JPEGDEC Ored context 0-3 interrupt request */
  PNGDEC_IRQn                  = 83,               /**< PNGDEC interrupt request */
  Reserved100_IRQn             = 84,               /**< Reserved interrupt 100 */
  TEMPDET0_IRQn                = 85,               /**< TEMPDET0: Temperature Detect Interrupt request 0 */
  TEMPDET1_IRQn                = 86,               /**< TEMPDET1: Temperature Detect Interrupt request 1 */
  EZHV_IRQn                    = 87,               /**< ezhv: Interrupt request */
  SLEEPCON1_IRQn               = 88,               /**< SLEEPCON_SENSE CPU1 wakeup event */
  PVTS1_CPU1_IRQn              = 89,               /**< PVTS1 CPU1 interrupt */
  Reserved106_IRQn             = 90,               /**< Reserved interrupt 106 */
  PVTS1_HIFI1_IRQn             = 91,               /**< PVTS1 HIFI1 interrupt */
  Reserved108_IRQn             = 92                /**< Reserved interrupt 108 */
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
#include "system_MIMXRT798S_cm33_core1.h" /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMXRT798S_cm33_core1_SERIES
#define MIMXRT798S_cm33_core1_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMXRT798S_cm33_core1_features.h"

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup edma_request
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections.
 */
typedef enum _dma_request_source
{
    kDmaRequestMuxDisabled          = 0U,          /**< Unused DMA request 0 */
    kDmaRequestMuxMicfil            = 1U,          /**< MICFIL FIFO_request */
    kDmaRequestMuxXspi2Rx           = 2U,          /**< XSPI2 Receive */
    kDmaRequestMuxXspi2Tx           = 3U,          /**< XSPI2 Transmit */
    kDmaRequestMuxPinInt0           = 4U,          /**< PINT INT0 */
    kDmaRequestMuxPinInt1           = 5U,          /**< PINT INT1 */
    kDmaRequestMuxPinInt2           = 6U,          /**< PINT INT2 */
    kDmaRequestMuxPinInt3           = 7U,          /**< PINT INT3 */
    kDmaRequestMuxCtimer5M0         = 8U,          /**< CTIMER5 Match channel 0 request */
    kDmaRequestMuxCtimer5M1         = 9U,          /**< CTIMER5 Match channel 1 request */
    kDmaRequestMuxCtimer6M0         = 10U,         /**< CTIMER6 Match channel 0 request */
    kDmaRequestMuxCtimer6M1         = 11U,         /**< CTIMER6 Match channel 1 request */
    kDmaRequestMuxCtimer7M0         = 12U,         /**< CTIMER7 Match channel 0 request */
    kDmaRequestMuxCtimer7M1         = 13U,         /**< CTIMER7 Match channel 1 request */
    kDmaRequestMuxAdc0FifoARequest  = 14U,         /**< ADC0 FIFO A request */
    kDmaRequestMuxAdc0FifoBRequest  = 15U,         /**< ADC0 FIFO B request */
    kDmaRequestMuxSdAdcFifo0Request = 16U,         /**< SDADC0 FIFO 0 request */
    kDmaRequestMuxSdAdcFifo1Request = 17U,         /**< SDADC0 FIFO 1 request */
    kDmaRequestMuxSdAdcFifo2Request = 18U,         /**< SDADC0 FIFO 2 request */
    kDmaRequestMuxSdAdcFifo3Request = 19U,         /**< SDADC0 FIFO 3 request */
    kDmaRequestMuxCmpDmaRequest     = 20U,         /**< CMP DMA request */
    kDmaRequestMuxReserved21        = 21U,         /**< Reserved 21 */
    kDmaRequestMuxReserved22        = 22U,         /**< Reserved 22 */
    kDmaRequestMuxFlexIO0ShiftRegister0Request = 23U, /**< FlexIO0 Shifter0 Status DMA request OR Timer0 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister1Request = 24U, /**< FlexIO0 Shifter1 Status DMA request OR Timer1 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister2Request = 25U, /**< FlexIO0 Shifter2 Status DMA request OR Timer2 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister3Request = 26U, /**< FlexIO0 Shifter3 Status DMA request OR Timer3 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister4Request = 27U, /**< FlexIO0 Shifter4 Status DMA request OR Timer4 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister5Request = 28U, /**< FlexIO0 Shifter5 Status DMA request OR Timer5 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister6Request = 29U, /**< FlexIO0 Shifter6 Status DMA request OR Timer6 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister7Request = 30U, /**< FlexIO0 Shifter7 Status DMA request OR Timer7 Status DMA request */
    kDmaRequestMuxLpFlexcomm17Rx    = 31U,         /**< LP_FLEXCOMM17 Receive request */
    kDmaRequestMuxLpFlexcomm17Tx    = 32U,         /**< LP_FLEXCOMM17 Transmit request */
    kDmaRequestMuxLpFlexcomm18Rx    = 33U,         /**< LP_FLEXCOMM18 Receive request */
    kDmaRequestMuxLpFlexcomm18Tx    = 34U,         /**< LP_FLEXCOMM18 Transmit request */
    kDmaRequestMuxLpFlexcomm19Rx    = 35U,         /**< LP_FLEXCOMM19 Receive request */
    kDmaRequestMuxLpFlexcomm19Tx    = 36U,         /**< LP_FLEXCOMM19 Transmit request */
    kDmaRequestMuxLpFlexcomm20Rx    = 37U,         /**< LP_FLEXCOMM20 Receive request */
    kDmaRequestMuxLpFlexcomm20Tx    = 38U,         /**< LP_FLEXCOMM20 Transmit request */
    kDmaRequestMuxI3c2Tx            = 39U,         /**< I3C2 Transmit request */
    kDmaRequestMuxI3c2Rx            = 40U,         /**< I3C2 Receive request */
    kDmaRequestMuxI3c3Tx            = 41U,         /**< I3C3 Transmit request */
    kDmaRequestMuxI3c3Rx            = 42U,         /**< I3C3 Receive request */
    kDmaRequestMuxSai3Rx            = 43U,         /**< SAI3 Receive request */
    kDmaRequestMuxSai3Tx            = 44U,         /**< SAI3 Transmit request */
    kDmaRequestMuxGpio8PinEventRequest0 = 45U,     /**< GPIO8 Pin event request 0 */
    kDmaRequestMuxGpio8PinEventRequest1 = 46U,     /**< GPIO8 Pin event request 1 */
    kDmaRequestMuxGpio9PinEventRequest0 = 47U,     /**< GPIO9 Pin event request 0 */
    kDmaRequestMuxGpio9PinEventRequest1 = 48U,     /**< GPIO9 Pin event request 1 */
    kDmaRequestMuxGpio10PinEventRequest0 = 49U,    /**< GPIO10 Pin event request 0 */
    kDmaRequestMuxGpio10PinEventRequest1 = 50U,    /**< GPIO10 Pin event request 1 */
    kDmaRequestMuxLpi2c15Rx         = 51U,         /**< LPI2C15 receive request */
    kDmaRequestMuxLpi2c15Tx         = 52U,         /**< LPI2C15 transmit request */
} dma_request_source_t;

/* @} */


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADC0 base address */
  #define ADC0_BASE                                (0x5020C000u)
  /** Peripheral ADC0 base address */
  #define ADC0_BASE_NS                             (0x4020C000u)
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
  #define ADC0_BASE                                (0x4020C000u)
  /** Peripheral ADC0 base pointer */
  #define ADC0                                     ((ADC_Type *)ADC0_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC0_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC0 }
#endif
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC_IRQn }

/* AHBSC3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AHBSC3 base address */
  #define AHBSC3_BASE                              (0x50220000u)
  /** Peripheral AHBSC3 base address */
  #define AHBSC3_BASE_NS                           (0x40220000u)
  /** Peripheral AHBSC3 base pointer */
  #define AHBSC3                                   ((AHBSC3_Type *)AHBSC3_BASE)
  /** Peripheral AHBSC3 base pointer */
  #define AHBSC3_NS                                ((AHBSC3_Type *)AHBSC3_BASE_NS)
  /** Peripheral AHBSC3_ALIAS1 base address */
  #define AHBSC3_ALIAS1_BASE                       (0x50221000u)
  /** Peripheral AHBSC3_ALIAS1 base address */
  #define AHBSC3_ALIAS1_BASE_NS                    (0x40221000u)
  /** Peripheral AHBSC3_ALIAS1 base pointer */
  #define AHBSC3_ALIAS1                            ((AHBSC3_Type *)AHBSC3_ALIAS1_BASE)
  /** Peripheral AHBSC3_ALIAS1 base pointer */
  #define AHBSC3_ALIAS1_NS                         ((AHBSC3_Type *)AHBSC3_ALIAS1_BASE_NS)
  /** Peripheral AHBSC3_ALIAS2 base address */
  #define AHBSC3_ALIAS2_BASE                       (0x50222000u)
  /** Peripheral AHBSC3_ALIAS2 base address */
  #define AHBSC3_ALIAS2_BASE_NS                    (0x40222000u)
  /** Peripheral AHBSC3_ALIAS2 base pointer */
  #define AHBSC3_ALIAS2                            ((AHBSC3_Type *)AHBSC3_ALIAS2_BASE)
  /** Peripheral AHBSC3_ALIAS2 base pointer */
  #define AHBSC3_ALIAS2_NS                         ((AHBSC3_Type *)AHBSC3_ALIAS2_BASE_NS)
  /** Peripheral AHBSC3_ALIAS3 base address */
  #define AHBSC3_ALIAS3_BASE                       (0x50223000u)
  /** Peripheral AHBSC3_ALIAS3 base address */
  #define AHBSC3_ALIAS3_BASE_NS                    (0x40223000u)
  /** Peripheral AHBSC3_ALIAS3 base pointer */
  #define AHBSC3_ALIAS3                            ((AHBSC3_Type *)AHBSC3_ALIAS3_BASE)
  /** Peripheral AHBSC3_ALIAS3 base pointer */
  #define AHBSC3_ALIAS3_NS                         ((AHBSC3_Type *)AHBSC3_ALIAS3_BASE_NS)
  /** Array initializer of AHBSC3 peripheral base addresses */
  #define AHBSC3_BASE_ADDRS                        { AHBSC3_BASE, AHBSC3_ALIAS1_BASE, AHBSC3_ALIAS2_BASE, AHBSC3_ALIAS3_BASE }
  /** Array initializer of AHBSC3 peripheral base pointers */
  #define AHBSC3_BASE_PTRS                         { AHBSC3, AHBSC3_ALIAS1, AHBSC3_ALIAS2, AHBSC3_ALIAS3 }
  /** Array initializer of AHBSC3 peripheral base addresses */
  #define AHBSC3_BASE_ADDRS_NS                     { AHBSC3_BASE_NS, AHBSC3_ALIAS1_BASE_NS, AHBSC3_ALIAS2_BASE_NS, AHBSC3_ALIAS3_BASE_NS }
  /** Array initializer of AHBSC3 peripheral base pointers */
  #define AHBSC3_BASE_PTRS_NS                      { AHBSC3_NS, AHBSC3_ALIAS1_NS, AHBSC3_ALIAS2_NS, AHBSC3_ALIAS3_NS }
#else
  /** Peripheral AHBSC3 base address */
  #define AHBSC3_BASE                              (0x40220000u)
  /** Peripheral AHBSC3 base pointer */
  #define AHBSC3                                   ((AHBSC3_Type *)AHBSC3_BASE)
  /** Peripheral AHBSC3_ALIAS1 base address */
  #define AHBSC3_ALIAS1_BASE                       (0x40221000u)
  /** Peripheral AHBSC3_ALIAS1 base pointer */
  #define AHBSC3_ALIAS1                            ((AHBSC3_Type *)AHBSC3_ALIAS1_BASE)
  /** Peripheral AHBSC3_ALIAS2 base address */
  #define AHBSC3_ALIAS2_BASE                       (0x40222000u)
  /** Peripheral AHBSC3_ALIAS2 base pointer */
  #define AHBSC3_ALIAS2                            ((AHBSC3_Type *)AHBSC3_ALIAS2_BASE)
  /** Peripheral AHBSC3_ALIAS3 base address */
  #define AHBSC3_ALIAS3_BASE                       (0x40223000u)
  /** Peripheral AHBSC3_ALIAS3 base pointer */
  #define AHBSC3_ALIAS3                            ((AHBSC3_Type *)AHBSC3_ALIAS3_BASE)
  /** Array initializer of AHBSC3 peripheral base addresses */
  #define AHBSC3_BASE_ADDRS                        { AHBSC3_BASE, AHBSC3_ALIAS1_BASE, AHBSC3_ALIAS2_BASE, AHBSC3_ALIAS3_BASE }
  /** Array initializer of AHBSC3 peripheral base pointers */
  #define AHBSC3_BASE_PTRS                         { AHBSC3, AHBSC3_ALIAS1, AHBSC3_ALIAS2, AHBSC3_ALIAS3 }
#endif

/* AHBSC4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AHBSC4 base address */
  #define AHBSC4_BASE                              (0x50400000u)
  /** Peripheral AHBSC4 base address */
  #define AHBSC4_BASE_NS                           (0x40400000u)
  /** Peripheral AHBSC4 base pointer */
  #define AHBSC4                                   ((AHBSC4_Type *)AHBSC4_BASE)
  /** Peripheral AHBSC4 base pointer */
  #define AHBSC4_NS                                ((AHBSC4_Type *)AHBSC4_BASE_NS)
  /** Peripheral AHBSC4_ALIAS1 base address */
  #define AHBSC4_ALIAS1_BASE                       (0x50401000u)
  /** Peripheral AHBSC4_ALIAS1 base address */
  #define AHBSC4_ALIAS1_BASE_NS                    (0x40401000u)
  /** Peripheral AHBSC4_ALIAS1 base pointer */
  #define AHBSC4_ALIAS1                            ((AHBSC4_Type *)AHBSC4_ALIAS1_BASE)
  /** Peripheral AHBSC4_ALIAS1 base pointer */
  #define AHBSC4_ALIAS1_NS                         ((AHBSC4_Type *)AHBSC4_ALIAS1_BASE_NS)
  /** Peripheral AHBSC4_ALIAS2 base address */
  #define AHBSC4_ALIAS2_BASE                       (0x50402000u)
  /** Peripheral AHBSC4_ALIAS2 base address */
  #define AHBSC4_ALIAS2_BASE_NS                    (0x40402000u)
  /** Peripheral AHBSC4_ALIAS2 base pointer */
  #define AHBSC4_ALIAS2                            ((AHBSC4_Type *)AHBSC4_ALIAS2_BASE)
  /** Peripheral AHBSC4_ALIAS2 base pointer */
  #define AHBSC4_ALIAS2_NS                         ((AHBSC4_Type *)AHBSC4_ALIAS2_BASE_NS)
  /** Peripheral AHBSC4_ALIAS3 base address */
  #define AHBSC4_ALIAS3_BASE                       (0x50403000u)
  /** Peripheral AHBSC4_ALIAS3 base address */
  #define AHBSC4_ALIAS3_BASE_NS                    (0x40403000u)
  /** Peripheral AHBSC4_ALIAS3 base pointer */
  #define AHBSC4_ALIAS3                            ((AHBSC4_Type *)AHBSC4_ALIAS3_BASE)
  /** Peripheral AHBSC4_ALIAS3 base pointer */
  #define AHBSC4_ALIAS3_NS                         ((AHBSC4_Type *)AHBSC4_ALIAS3_BASE_NS)
  /** Array initializer of AHBSC4 peripheral base addresses */
  #define AHBSC4_BASE_ADDRS                        { AHBSC4_BASE, AHBSC4_ALIAS1_BASE, AHBSC4_ALIAS2_BASE, AHBSC4_ALIAS3_BASE }
  /** Array initializer of AHBSC4 peripheral base pointers */
  #define AHBSC4_BASE_PTRS                         { AHBSC4, AHBSC4_ALIAS1, AHBSC4_ALIAS2, AHBSC4_ALIAS3 }
  /** Array initializer of AHBSC4 peripheral base addresses */
  #define AHBSC4_BASE_ADDRS_NS                     { AHBSC4_BASE_NS, AHBSC4_ALIAS1_BASE_NS, AHBSC4_ALIAS2_BASE_NS, AHBSC4_ALIAS3_BASE_NS }
  /** Array initializer of AHBSC4 peripheral base pointers */
  #define AHBSC4_BASE_PTRS_NS                      { AHBSC4_NS, AHBSC4_ALIAS1_NS, AHBSC4_ALIAS2_NS, AHBSC4_ALIAS3_NS }
#else
  /** Peripheral AHBSC4 base address */
  #define AHBSC4_BASE                              (0x40400000u)
  /** Peripheral AHBSC4 base pointer */
  #define AHBSC4                                   ((AHBSC4_Type *)AHBSC4_BASE)
  /** Peripheral AHBSC4_ALIAS1 base address */
  #define AHBSC4_ALIAS1_BASE                       (0x40401000u)
  /** Peripheral AHBSC4_ALIAS1 base pointer */
  #define AHBSC4_ALIAS1                            ((AHBSC4_Type *)AHBSC4_ALIAS1_BASE)
  /** Peripheral AHBSC4_ALIAS2 base address */
  #define AHBSC4_ALIAS2_BASE                       (0x40402000u)
  /** Peripheral AHBSC4_ALIAS2 base pointer */
  #define AHBSC4_ALIAS2                            ((AHBSC4_Type *)AHBSC4_ALIAS2_BASE)
  /** Peripheral AHBSC4_ALIAS3 base address */
  #define AHBSC4_ALIAS3_BASE                       (0x40403000u)
  /** Peripheral AHBSC4_ALIAS3 base pointer */
  #define AHBSC4_ALIAS3                            ((AHBSC4_Type *)AHBSC4_ALIAS3_BASE)
  /** Array initializer of AHBSC4 peripheral base addresses */
  #define AHBSC4_BASE_ADDRS                        { AHBSC4_BASE, AHBSC4_ALIAS1_BASE, AHBSC4_ALIAS2_BASE, AHBSC4_ALIAS3_BASE }
  /** Array initializer of AHBSC4 peripheral base pointers */
  #define AHBSC4_BASE_PTRS                         { AHBSC4, AHBSC4_ALIAS1, AHBSC4_ALIAS2, AHBSC4_ALIAS3 }
#endif

/* CDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CDOG3 base address */
  #define CDOG3_BASE                               (0x5032B000u)
  /** Peripheral CDOG3 base address */
  #define CDOG3_BASE_NS                            (0x4032B000u)
  /** Peripheral CDOG3 base pointer */
  #define CDOG3                                    ((CDOG_Type *)CDOG3_BASE)
  /** Peripheral CDOG3 base pointer */
  #define CDOG3_NS                                 ((CDOG_Type *)CDOG3_BASE_NS)
  /** Peripheral CDOG4 base address */
  #define CDOG4_BASE                               (0x5032A000u)
  /** Peripheral CDOG4 base address */
  #define CDOG4_BASE_NS                            (0x4032A000u)
  /** Peripheral CDOG4 base pointer */
  #define CDOG4                                    ((CDOG_Type *)CDOG4_BASE)
  /** Peripheral CDOG4 base pointer */
  #define CDOG4_NS                                 ((CDOG_Type *)CDOG4_BASE_NS)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { 0u, 0u, 0u, CDOG3_BASE, CDOG4_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { (CDOG_Type *)0u, (CDOG_Type *)0u, (CDOG_Type *)0u, CDOG3, CDOG4 }
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS_NS                       { 0u, 0u, 0u, CDOG3_BASE_NS, CDOG4_BASE_NS }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS_NS                        { (CDOG_Type *)0u, (CDOG_Type *)0u, (CDOG_Type *)0u, CDOG3_NS, CDOG4_NS }
#else
  /** Peripheral CDOG3 base address */
  #define CDOG3_BASE                               (0x4032B000u)
  /** Peripheral CDOG3 base pointer */
  #define CDOG3                                    ((CDOG_Type *)CDOG3_BASE)
  /** Peripheral CDOG4 base address */
  #define CDOG4_BASE                               (0x4032A000u)
  /** Peripheral CDOG4 base pointer */
  #define CDOG4                                    ((CDOG_Type *)CDOG4_BASE)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { 0u, 0u, 0u, CDOG3_BASE, CDOG4_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { (CDOG_Type *)0u, (CDOG_Type *)0u, (CDOG_Type *)0u, CDOG3, CDOG4 }
#endif
/** Interrupt vectors for the CDOG peripheral type */
#define CDOG_IRQS                                { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, CDOG3_IRQn, CDOG4_IRQn }

/* CLKCTL1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CLKCTL1 base address */
  #define CLKCTL1_BASE                             (0x50041000u)
  /** Peripheral CLKCTL1 base address */
  #define CLKCTL1_BASE_NS                          (0x40041000u)
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
  #define CLKCTL1_BASE                             (0x40041000u)
  /** Peripheral CLKCTL1 base pointer */
  #define CLKCTL1                                  ((CLKCTL1_Type *)CLKCTL1_BASE)
  /** Array initializer of CLKCTL1 peripheral base addresses */
  #define CLKCTL1_BASE_ADDRS                       { CLKCTL1_BASE }
  /** Array initializer of CLKCTL1 peripheral base pointers */
  #define CLKCTL1_BASE_PTRS                        { CLKCTL1 }
#endif

/* CLKCTL2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CLKCTL2 base address */
  #define CLKCTL2_BASE                             (0x50065000u)
  /** Peripheral CLKCTL2 base address */
  #define CLKCTL2_BASE_NS                          (0x40065000u)
  /** Peripheral CLKCTL2 base pointer */
  #define CLKCTL2                                  ((CLKCTL2_Type *)CLKCTL2_BASE)
  /** Peripheral CLKCTL2 base pointer */
  #define CLKCTL2_NS                               ((CLKCTL2_Type *)CLKCTL2_BASE_NS)
  /** Array initializer of CLKCTL2 peripheral base addresses */
  #define CLKCTL2_BASE_ADDRS                       { CLKCTL2_BASE }
  /** Array initializer of CLKCTL2 peripheral base pointers */
  #define CLKCTL2_BASE_PTRS                        { CLKCTL2 }
  /** Array initializer of CLKCTL2 peripheral base addresses */
  #define CLKCTL2_BASE_ADDRS_NS                    { CLKCTL2_BASE_NS }
  /** Array initializer of CLKCTL2 peripheral base pointers */
  #define CLKCTL2_BASE_PTRS_NS                     { CLKCTL2_NS }
#else
  /** Peripheral CLKCTL2 base address */
  #define CLKCTL2_BASE                             (0x40065000u)
  /** Peripheral CLKCTL2 base pointer */
  #define CLKCTL2                                  ((CLKCTL2_Type *)CLKCTL2_BASE)
  /** Array initializer of CLKCTL2 peripheral base addresses */
  #define CLKCTL2_BASE_ADDRS                       { CLKCTL2_BASE }
  /** Array initializer of CLKCTL2 peripheral base pointers */
  #define CLKCTL2_BASE_PTRS                        { CLKCTL2 }
#endif

/* CLKCTL3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CLKCTL3 base address */
  #define CLKCTL3_BASE                             (0x50061000u)
  /** Peripheral CLKCTL3 base address */
  #define CLKCTL3_BASE_NS                          (0x40061000u)
  /** Peripheral CLKCTL3 base pointer */
  #define CLKCTL3                                  ((CLKCTL3_Type *)CLKCTL3_BASE)
  /** Peripheral CLKCTL3 base pointer */
  #define CLKCTL3_NS                               ((CLKCTL3_Type *)CLKCTL3_BASE_NS)
  /** Array initializer of CLKCTL3 peripheral base addresses */
  #define CLKCTL3_BASE_ADDRS                       { CLKCTL3_BASE }
  /** Array initializer of CLKCTL3 peripheral base pointers */
  #define CLKCTL3_BASE_PTRS                        { CLKCTL3 }
  /** Array initializer of CLKCTL3 peripheral base addresses */
  #define CLKCTL3_BASE_ADDRS_NS                    { CLKCTL3_BASE_NS }
  /** Array initializer of CLKCTL3 peripheral base pointers */
  #define CLKCTL3_BASE_PTRS_NS                     { CLKCTL3_NS }
#else
  /** Peripheral CLKCTL3 base address */
  #define CLKCTL3_BASE                             (0x40061000u)
  /** Peripheral CLKCTL3 base pointer */
  #define CLKCTL3                                  ((CLKCTL3_Type *)CLKCTL3_BASE)
  /** Array initializer of CLKCTL3 peripheral base addresses */
  #define CLKCTL3_BASE_ADDRS                       { CLKCTL3_BASE }
  /** Array initializer of CLKCTL3 peripheral base pointers */
  #define CLKCTL3_BASE_PTRS                        { CLKCTL3 }
#endif

/* CLKCTL4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CLKCTL4 base address */
  #define CLKCTL4_BASE                             (0x500A1000u)
  /** Peripheral CLKCTL4 base address */
  #define CLKCTL4_BASE_NS                          (0x400A1000u)
  /** Peripheral CLKCTL4 base pointer */
  #define CLKCTL4                                  ((CLKCTL4_Type *)CLKCTL4_BASE)
  /** Peripheral CLKCTL4 base pointer */
  #define CLKCTL4_NS                               ((CLKCTL4_Type *)CLKCTL4_BASE_NS)
  /** Array initializer of CLKCTL4 peripheral base addresses */
  #define CLKCTL4_BASE_ADDRS                       { CLKCTL4_BASE }
  /** Array initializer of CLKCTL4 peripheral base pointers */
  #define CLKCTL4_BASE_PTRS                        { CLKCTL4 }
  /** Array initializer of CLKCTL4 peripheral base addresses */
  #define CLKCTL4_BASE_ADDRS_NS                    { CLKCTL4_BASE_NS }
  /** Array initializer of CLKCTL4 peripheral base pointers */
  #define CLKCTL4_BASE_PTRS_NS                     { CLKCTL4_NS }
#else
  /** Peripheral CLKCTL4 base address */
  #define CLKCTL4_BASE                             (0x400A1000u)
  /** Peripheral CLKCTL4 base pointer */
  #define CLKCTL4                                  ((CLKCTL4_Type *)CLKCTL4_BASE)
  /** Array initializer of CLKCTL4 peripheral base addresses */
  #define CLKCTL4_BASE_ADDRS                       { CLKCTL4_BASE }
  /** Array initializer of CLKCTL4 peripheral base pointers */
  #define CLKCTL4_BASE_PTRS                        { CLKCTL4 }
#endif

/* CMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ACMP0 base address */
  #define ACMP0_BASE                               (0x5020B000u)
  /** Peripheral ACMP0 base address */
  #define ACMP0_BASE_NS                            (0x4020B000u)
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
  #define ACMP0_BASE                               (0x4020B000u)
  /** Peripheral ACMP0 base pointer */
  #define ACMP0                                    ((CMP_Type *)ACMP0_BASE)
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS                           { ACMP0_BASE }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS                            { ACMP0 }
#endif
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { ACMP_IRQn }

/* CTIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CTIMER5 base address */
  #define CTIMER5_BASE                             (0x50048000u)
  /** Peripheral CTIMER5 base address */
  #define CTIMER5_BASE_NS                          (0x40048000u)
  /** Peripheral CTIMER5 base pointer */
  #define CTIMER5                                  ((CTIMER_Type *)CTIMER5_BASE)
  /** Peripheral CTIMER5 base pointer */
  #define CTIMER5_NS                               ((CTIMER_Type *)CTIMER5_BASE_NS)
  /** Peripheral CTIMER6 base address */
  #define CTIMER6_BASE                             (0x50049000u)
  /** Peripheral CTIMER6 base address */
  #define CTIMER6_BASE_NS                          (0x40049000u)
  /** Peripheral CTIMER6 base pointer */
  #define CTIMER6                                  ((CTIMER_Type *)CTIMER6_BASE)
  /** Peripheral CTIMER6 base pointer */
  #define CTIMER6_NS                               ((CTIMER_Type *)CTIMER6_BASE_NS)
  /** Peripheral CTIMER7 base address */
  #define CTIMER7_BASE                             (0x5004A000u)
  /** Peripheral CTIMER7 base address */
  #define CTIMER7_BASE_NS                          (0x4004A000u)
  /** Peripheral CTIMER7 base pointer */
  #define CTIMER7                                  ((CTIMER_Type *)CTIMER7_BASE)
  /** Peripheral CTIMER7 base pointer */
  #define CTIMER7_NS                               ((CTIMER_Type *)CTIMER7_BASE_NS)
  /** Array initializer of CTIMER peripheral base addresses */
  #define CTIMER_BASE_ADDRS                        { 0u, 0u, 0u, 0u, 0u, CTIMER5_BASE, CTIMER6_BASE, CTIMER7_BASE }
  /** Array initializer of CTIMER peripheral base pointers */
  #define CTIMER_BASE_PTRS                         { (CTIMER_Type *)0u, (CTIMER_Type *)0u, (CTIMER_Type *)0u, (CTIMER_Type *)0u, (CTIMER_Type *)0u, CTIMER5, CTIMER6, CTIMER7 }
  /** Array initializer of CTIMER peripheral base addresses */
  #define CTIMER_BASE_ADDRS_NS                     { 0u, 0u, 0u, 0u, 0u, CTIMER5_BASE_NS, CTIMER6_BASE_NS, CTIMER7_BASE_NS }
  /** Array initializer of CTIMER peripheral base pointers */
  #define CTIMER_BASE_PTRS_NS                      { (CTIMER_Type *)0u, (CTIMER_Type *)0u, (CTIMER_Type *)0u, (CTIMER_Type *)0u, (CTIMER_Type *)0u, CTIMER5_NS, CTIMER6_NS, CTIMER7_NS }
#else
  /** Peripheral CTIMER5 base address */
  #define CTIMER5_BASE                             (0x40048000u)
  /** Peripheral CTIMER5 base pointer */
  #define CTIMER5                                  ((CTIMER_Type *)CTIMER5_BASE)
  /** Peripheral CTIMER6 base address */
  #define CTIMER6_BASE                             (0x40049000u)
  /** Peripheral CTIMER6 base pointer */
  #define CTIMER6                                  ((CTIMER_Type *)CTIMER6_BASE)
  /** Peripheral CTIMER7 base address */
  #define CTIMER7_BASE                             (0x4004A000u)
  /** Peripheral CTIMER7 base pointer */
  #define CTIMER7                                  ((CTIMER_Type *)CTIMER7_BASE)
  /** Array initializer of CTIMER peripheral base addresses */
  #define CTIMER_BASE_ADDRS                        { 0u, 0u, 0u, 0u, 0u, CTIMER5_BASE, CTIMER6_BASE, CTIMER7_BASE }
  /** Array initializer of CTIMER peripheral base pointers */
  #define CTIMER_BASE_PTRS                         { (CTIMER_Type *)0u, (CTIMER_Type *)0u, (CTIMER_Type *)0u, (CTIMER_Type *)0u, (CTIMER_Type *)0u, CTIMER5, CTIMER6, CTIMER7 }
#endif
/** Interrupt vectors for the CTIMER peripheral type */
#define CTIMER_IRQS                              { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, CTIMER5_IRQn, CTIMER6_IRQn, CTIMER7_IRQn }

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA2 base address */
  #define DMA2_BASE                                (0x50300000u)
  /** Peripheral DMA2 base address */
  #define DMA2_BASE_NS                             (0x40300000u)
  /** Peripheral DMA2 base pointer */
  #define DMA2                                     ((DMA_Type *)DMA2_BASE)
  /** Peripheral DMA2 base pointer */
  #define DMA2_NS                                  ((DMA_Type *)DMA2_BASE_NS)
  /** Peripheral DMA3 base address */
  #define DMA3_BASE                                (0x50310000u)
  /** Peripheral DMA3 base address */
  #define DMA3_BASE_NS                             (0x40310000u)
  /** Peripheral DMA3 base pointer */
  #define DMA3                                     ((DMA_Type *)DMA3_BASE)
  /** Peripheral DMA3 base pointer */
  #define DMA3_NS                                  ((DMA_Type *)DMA3_BASE_NS)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { 0u, 0u, DMA2_BASE, DMA3_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { (DMA_Type *)0u, (DMA_Type *)0u, DMA2, DMA3 }
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS_NS                        { 0u, 0u, DMA2_BASE_NS, DMA3_BASE_NS }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS_NS                         { (DMA_Type *)0u, (DMA_Type *)0u, DMA2_NS, DMA3_NS }
#else
  /** Peripheral DMA2 base address */
  #define DMA2_BASE                                (0x40300000u)
  /** Peripheral DMA2 base pointer */
  #define DMA2                                     ((DMA_Type *)DMA2_BASE)
  /** Peripheral DMA3 base address */
  #define DMA3_BASE                                (0x40310000u)
  /** Peripheral DMA3 base pointer */
  #define DMA3                                     ((DMA_Type *)DMA3_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { 0u, 0u, DMA2_BASE, DMA3_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { (DMA_Type *)0u, (DMA_Type *)0u, DMA2, DMA3 }
#endif
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { EDMA2_CH0_IRQn, EDMA2_CH1_IRQn, EDMA2_CH2_IRQn, EDMA2_CH3_IRQn, EDMA2_CH4_IRQn, EDMA2_CH5_IRQn, EDMA2_CH6_IRQn, EDMA2_CH7_IRQn }, { EDMA3_CH0_IRQn, EDMA3_CH1_IRQn, EDMA3_CH2_IRQn, EDMA3_CH3_IRQn, EDMA3_CH4_IRQn, EDMA3_CH5_IRQn, EDMA3_CH6_IRQn, EDMA3_CH7_IRQn } }

/* FLEXIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXIO base address */
  #define FLEXIO_BASE                              (0x50416000u)
  /** Peripheral FLEXIO base address */
  #define FLEXIO_BASE_NS                           (0x40416000u)
  /** Peripheral FLEXIO base pointer */
  #define FLEXIO                                   ((FLEXIO_Type *)FLEXIO_BASE)
  /** Peripheral FLEXIO base pointer */
  #define FLEXIO_NS                                ((FLEXIO_Type *)FLEXIO_BASE_NS)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { FLEXIO_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { FLEXIO }
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS_NS                     { FLEXIO_BASE_NS }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS_NS                      { FLEXIO_NS }
#else
  /** Peripheral FLEXIO base address */
  #define FLEXIO_BASE                              (0x40416000u)
  /** Peripheral FLEXIO base pointer */
  #define FLEXIO                                   ((FLEXIO_Type *)FLEXIO_BASE)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { FLEXIO_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { FLEXIO }
#endif
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { FLEXIO_IRQn }

/* FRO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FRO2 base address */
  #define FRO2_BASE                                (0x50061100u)
  /** Peripheral FRO2 base address */
  #define FRO2_BASE_NS                             (0x40061100u)
  /** Peripheral FRO2 base pointer */
  #define FRO2                                     ((FRO_Type *)FRO2_BASE)
  /** Peripheral FRO2 base pointer */
  #define FRO2_NS                                  ((FRO_Type *)FRO2_BASE_NS)
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS                           { 0u, 0u, FRO2_BASE }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS                            { (FRO_Type *)0u, (FRO_Type *)0u, FRO2 }
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS_NS                        { 0u, 0u, FRO2_BASE_NS }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS_NS                         { (FRO_Type *)0u, (FRO_Type *)0u, FRO2_NS }
#else
  /** Peripheral FRO2 base address */
  #define FRO2_BASE                                (0x40061100u)
  /** Peripheral FRO2 base pointer */
  #define FRO2                                     ((FRO_Type *)FRO2_BASE)
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS                           { 0u, 0u, FRO2_BASE }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS                            { (FRO_Type *)0u, (FRO_Type *)0u, FRO2 }
#endif

/* GDET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GDET3 base address */
  #define GDET3_BASE                               (0x5006B000u)
  /** Peripheral GDET3 base address */
  #define GDET3_BASE_NS                            (0x4006B000u)
  /** Peripheral GDET3 base pointer */
  #define GDET3                                    ((GDET_Type *)GDET3_BASE)
  /** Peripheral GDET3 base pointer */
  #define GDET3_NS                                 ((GDET_Type *)GDET3_BASE_NS)
  /** Array initializer of GDET peripheral base addresses */
  #define GDET_BASE_ADDRS                          { 0u, 0u, 0u, GDET3_BASE }
  /** Array initializer of GDET peripheral base pointers */
  #define GDET_BASE_PTRS                           { (GDET_Type *)0u, (GDET_Type *)0u, (GDET_Type *)0u, GDET3 }
  /** Array initializer of GDET peripheral base addresses */
  #define GDET_BASE_ADDRS_NS                       { 0u, 0u, 0u, GDET3_BASE_NS }
  /** Array initializer of GDET peripheral base pointers */
  #define GDET_BASE_PTRS_NS                        { (GDET_Type *)0u, (GDET_Type *)0u, (GDET_Type *)0u, GDET3_NS }
#else
  /** Peripheral GDET3 base address */
  #define GDET3_BASE                               (0x4006B000u)
  /** Peripheral GDET3 base pointer */
  #define GDET3                                    ((GDET_Type *)GDET3_BASE)
  /** Array initializer of GDET peripheral base addresses */
  #define GDET_BASE_ADDRS                          { 0u, 0u, 0u, GDET3_BASE }
  /** Array initializer of GDET peripheral base pointers */
  #define GDET_BASE_PTRS                           { (GDET_Type *)0u, (GDET_Type *)0u, (GDET_Type *)0u, GDET3 }
#endif
/** Interrupt vectors for the GDET peripheral type */
#define GDET_IRQS                                { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, GDET3_IRQn }

/* GLIKEY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GLIKEY1 base address */
  #define GLIKEY1_BASE                             (0x50220C00u)
  /** Peripheral GLIKEY1 base address */
  #define GLIKEY1_BASE_NS                          (0x40220C00u)
  /** Peripheral GLIKEY1 base pointer */
  #define GLIKEY1                                  ((GLIKEY_Type *)GLIKEY1_BASE)
  /** Peripheral GLIKEY1 base pointer */
  #define GLIKEY1_NS                               ((GLIKEY_Type *)GLIKEY1_BASE_NS)
  /** Peripheral GLIKEY2 base address */
  #define GLIKEY2_BASE                             (0x50400C00u)
  /** Peripheral GLIKEY2 base address */
  #define GLIKEY2_BASE_NS                          (0x40400C00u)
  /** Peripheral GLIKEY2 base pointer */
  #define GLIKEY2                                  ((GLIKEY_Type *)GLIKEY2_BASE)
  /** Peripheral GLIKEY2 base pointer */
  #define GLIKEY2_NS                               ((GLIKEY_Type *)GLIKEY2_BASE_NS)
  /** Peripheral GLIKEY4 base address */
  #define GLIKEY4_BASE                             (0x50062C00u)
  /** Peripheral GLIKEY4 base address */
  #define GLIKEY4_BASE_NS                          (0x40062C00u)
  /** Peripheral GLIKEY4 base pointer */
  #define GLIKEY4                                  ((GLIKEY_Type *)GLIKEY4_BASE)
  /** Peripheral GLIKEY4 base pointer */
  #define GLIKEY4_NS                               ((GLIKEY_Type *)GLIKEY4_BASE_NS)
  /** Peripheral GLIKEY5 base address */
  #define GLIKEY5_BASE                             (0x500A2C00u)
  /** Peripheral GLIKEY5 base address */
  #define GLIKEY5_BASE_NS                          (0x400A2C00u)
  /** Peripheral GLIKEY5 base pointer */
  #define GLIKEY5                                  ((GLIKEY_Type *)GLIKEY5_BASE)
  /** Peripheral GLIKEY5 base pointer */
  #define GLIKEY5_NS                               ((GLIKEY_Type *)GLIKEY5_BASE_NS)
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS                        { 0u, GLIKEY1_BASE, GLIKEY2_BASE, 0u, GLIKEY4_BASE, GLIKEY5_BASE }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS                         { (GLIKEY_Type *)0u, GLIKEY1, GLIKEY2, (GLIKEY_Type *)0u, GLIKEY4, GLIKEY5 }
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS_NS                     { 0u, GLIKEY1_BASE_NS, GLIKEY2_BASE_NS, 0u, GLIKEY4_BASE_NS, GLIKEY5_BASE_NS }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS_NS                      { (GLIKEY_Type *)0u, GLIKEY1_NS, GLIKEY2_NS, (GLIKEY_Type *)0u, GLIKEY4_NS, GLIKEY5_NS }
#else
  /** Peripheral GLIKEY1 base address */
  #define GLIKEY1_BASE                             (0x40220C00u)
  /** Peripheral GLIKEY1 base pointer */
  #define GLIKEY1                                  ((GLIKEY_Type *)GLIKEY1_BASE)
  /** Peripheral GLIKEY2 base address */
  #define GLIKEY2_BASE                             (0x40400C00u)
  /** Peripheral GLIKEY2 base pointer */
  #define GLIKEY2                                  ((GLIKEY_Type *)GLIKEY2_BASE)
  /** Peripheral GLIKEY4 base address */
  #define GLIKEY4_BASE                             (0x40062C00u)
  /** Peripheral GLIKEY4 base pointer */
  #define GLIKEY4                                  ((GLIKEY_Type *)GLIKEY4_BASE)
  /** Peripheral GLIKEY5 base address */
  #define GLIKEY5_BASE                             (0x400A2C00u)
  /** Peripheral GLIKEY5 base pointer */
  #define GLIKEY5                                  ((GLIKEY_Type *)GLIKEY5_BASE)
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS                        { 0u, GLIKEY1_BASE, GLIKEY2_BASE, 0u, GLIKEY4_BASE, GLIKEY5_BASE }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS                         { (GLIKEY_Type *)0u, GLIKEY1, GLIKEY2, (GLIKEY_Type *)0u, GLIKEY4, GLIKEY5 }
#endif

/* GPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPIO8 base address */
  #define GPIO8_BASE                               (0x50320000u)
  /** Peripheral GPIO8 base address */
  #define GPIO8_BASE_NS                            (0x40320000u)
  /** Peripheral GPIO8 base pointer */
  #define GPIO8                                    ((GPIO_Type *)GPIO8_BASE)
  /** Peripheral GPIO8 base pointer */
  #define GPIO8_NS                                 ((GPIO_Type *)GPIO8_BASE_NS)
  /** Peripheral GPIO9 base address */
  #define GPIO9_BASE                               (0x50322000u)
  /** Peripheral GPIO9 base address */
  #define GPIO9_BASE_NS                            (0x40322000u)
  /** Peripheral GPIO9 base pointer */
  #define GPIO9                                    ((GPIO_Type *)GPIO9_BASE)
  /** Peripheral GPIO9 base pointer */
  #define GPIO9_NS                                 ((GPIO_Type *)GPIO9_BASE_NS)
  /** Peripheral GPIO10 base address */
  #define GPIO10_BASE                              (0x50324000u)
  /** Peripheral GPIO10 base address */
  #define GPIO10_BASE_NS                           (0x40324000u)
  /** Peripheral GPIO10 base pointer */
  #define GPIO10                                   ((GPIO_Type *)GPIO10_BASE)
  /** Peripheral GPIO10 base pointer */
  #define GPIO10_NS                                ((GPIO_Type *)GPIO10_BASE_NS)
  /** Peripheral GPIO8_ALIAS base address */
  #define GPIO8_ALIAS_BASE                         (0x50321000u)
  /** Peripheral GPIO8_ALIAS base address */
  #define GPIO8_ALIAS_BASE_NS                      (0x40321000u)
  /** Peripheral GPIO8_ALIAS base pointer */
  #define GPIO8_ALIAS                              ((GPIO_Type *)GPIO8_ALIAS_BASE)
  /** Peripheral GPIO8_ALIAS base pointer */
  #define GPIO8_ALIAS_NS                           ((GPIO_Type *)GPIO8_ALIAS_BASE_NS)
  /** Peripheral GPIO9_ALIAS base address */
  #define GPIO9_ALIAS_BASE                         (0x50323000u)
  /** Peripheral GPIO9_ALIAS base address */
  #define GPIO9_ALIAS_BASE_NS                      (0x40323000u)
  /** Peripheral GPIO9_ALIAS base pointer */
  #define GPIO9_ALIAS                              ((GPIO_Type *)GPIO9_ALIAS_BASE)
  /** Peripheral GPIO9_ALIAS base pointer */
  #define GPIO9_ALIAS_NS                           ((GPIO_Type *)GPIO9_ALIAS_BASE_NS)
  /** Peripheral GPIO10_ALIAS base address */
  #define GPIO10_ALIAS_BASE                        (0x50325000u)
  /** Peripheral GPIO10_ALIAS base address */
  #define GPIO10_ALIAS_BASE_NS                     (0x40325000u)
  /** Peripheral GPIO10_ALIAS base pointer */
  #define GPIO10_ALIAS                             ((GPIO_Type *)GPIO10_ALIAS_BASE)
  /** Peripheral GPIO10_ALIAS base pointer */
  #define GPIO10_ALIAS_NS                          ((GPIO_Type *)GPIO10_ALIAS_BASE_NS)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, GPIO8_BASE, GPIO9_BASE, GPIO10_BASE, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, GPIO8_ALIAS_BASE, GPIO9_ALIAS_BASE, GPIO10_ALIAS_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, GPIO8, GPIO9, GPIO10, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, GPIO8_ALIAS, GPIO9_ALIAS, GPIO10_ALIAS }
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS_NS                       { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, GPIO8_BASE_NS, GPIO9_BASE_NS, GPIO10_BASE_NS, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, GPIO8_ALIAS_BASE_NS, GPIO9_ALIAS_BASE_NS, GPIO10_ALIAS_BASE_NS }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS_NS                        { (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, GPIO8_NS, GPIO9_NS, GPIO10_NS, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, GPIO8_ALIAS_NS, GPIO9_ALIAS_NS, GPIO10_ALIAS_NS }
#else
  /** Peripheral GPIO8 base address */
  #define GPIO8_BASE                               (0x40320000u)
  /** Peripheral GPIO8 base pointer */
  #define GPIO8                                    ((GPIO_Type *)GPIO8_BASE)
  /** Peripheral GPIO9 base address */
  #define GPIO9_BASE                               (0x40322000u)
  /** Peripheral GPIO9 base pointer */
  #define GPIO9                                    ((GPIO_Type *)GPIO9_BASE)
  /** Peripheral GPIO10 base address */
  #define GPIO10_BASE                              (0x40324000u)
  /** Peripheral GPIO10 base pointer */
  #define GPIO10                                   ((GPIO_Type *)GPIO10_BASE)
  /** Peripheral GPIO8_ALIAS base address */
  #define GPIO8_ALIAS_BASE                         (0x40321000u)
  /** Peripheral GPIO8_ALIAS base pointer */
  #define GPIO8_ALIAS                              ((GPIO_Type *)GPIO8_ALIAS_BASE)
  /** Peripheral GPIO9_ALIAS base address */
  #define GPIO9_ALIAS_BASE                         (0x40323000u)
  /** Peripheral GPIO9_ALIAS base pointer */
  #define GPIO9_ALIAS                              ((GPIO_Type *)GPIO9_ALIAS_BASE)
  /** Peripheral GPIO10_ALIAS base address */
  #define GPIO10_ALIAS_BASE                        (0x40325000u)
  /** Peripheral GPIO10_ALIAS base pointer */
  #define GPIO10_ALIAS                             ((GPIO_Type *)GPIO10_ALIAS_BASE)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, GPIO8_BASE, GPIO9_BASE, GPIO10_BASE, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, GPIO8_ALIAS_BASE, GPIO9_ALIAS_BASE, GPIO10_ALIAS_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, GPIO8, GPIO9, GPIO10, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, GPIO8_ALIAS, GPIO9_ALIAS, GPIO10_ALIAS }
#endif
/* Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS   {GPIO80_IRQn, GPIO90_IRQn, GPIO100_IRQn}
#define GPIO_IRQS_1 {GPIO81_IRQn, GPIO91_IRQn, GPIO101_IRQn}


/* I2S - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SAI3 base address */
  #define SAI3_BASE                                (0x5031C000u)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE_NS                             (0x4031C000u)
  /** Peripheral SAI3 base pointer */
  #define SAI3                                     ((I2S_Type *)SAI3_BASE)
  /** Peripheral SAI3 base pointer */
  #define SAI3_NS                                  ((I2S_Type *)SAI3_BASE_NS)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { 0u, 0u, 0u, SAI3_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { (I2S_Type *)0u, (I2S_Type *)0u, (I2S_Type *)0u, SAI3 }
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS_NS                        { 0u, 0u, 0u, SAI3_BASE_NS }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS_NS                         { (I2S_Type *)0u, (I2S_Type *)0u, (I2S_Type *)0u, SAI3_NS }
#else
  /** Peripheral SAI3 base address */
  #define SAI3_BASE                                (0x4031C000u)
  /** Peripheral SAI3 base pointer */
  #define SAI3                                     ((I2S_Type *)SAI3_BASE)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { 0u, 0u, 0u, SAI3_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { (I2S_Type *)0u, (I2S_Type *)0u, (I2S_Type *)0u, SAI3 }
#endif
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, SAI3_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, SAI3_IRQn }

/* I3C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I3C2 base address */
  #define I3C2_BASE                                (0x50056000u)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE_NS                             (0x40056000u)
  /** Peripheral I3C2 base pointer */
  #define I3C2                                     ((I3C_Type *)I3C2_BASE)
  /** Peripheral I3C2 base pointer */
  #define I3C2_NS                                  ((I3C_Type *)I3C2_BASE_NS)
  /** Peripheral I3C3 base address */
  #define I3C3_BASE                                (0x50057000u)
  /** Peripheral I3C3 base address */
  #define I3C3_BASE_NS                             (0x40057000u)
  /** Peripheral I3C3 base pointer */
  #define I3C3                                     ((I3C_Type *)I3C3_BASE)
  /** Peripheral I3C3 base pointer */
  #define I3C3_NS                                  ((I3C_Type *)I3C3_BASE_NS)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { 0u, 0u, I3C2_BASE, I3C3_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { (I3C_Type *)0u, (I3C_Type *)0u, I3C2, I3C3 }
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS_NS                        { 0u, 0u, I3C2_BASE_NS, I3C3_BASE_NS }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS_NS                         { (I3C_Type *)0u, (I3C_Type *)0u, I3C2_NS, I3C3_NS }
#else
  /** Peripheral I3C2 base address */
  #define I3C2_BASE                                (0x40056000u)
  /** Peripheral I3C2 base pointer */
  #define I3C2                                     ((I3C_Type *)I3C2_BASE)
  /** Peripheral I3C3 base address */
  #define I3C3_BASE                                (0x40057000u)
  /** Peripheral I3C3 base pointer */
  #define I3C3                                     ((I3C_Type *)I3C3_BASE)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { 0u, 0u, I3C2_BASE, I3C3_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { (I3C_Type *)0u, (I3C_Type *)0u, I3C2, I3C3 }
#endif
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { NotAvail_IRQn, NotAvail_IRQn, I3C2_IRQn, I3C3_IRQn }

/* INPUTMUX1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral INPUTMUX1 base address */
  #define INPUTMUX1_BASE                           (0x50046000u)
  /** Peripheral INPUTMUX1 base address */
  #define INPUTMUX1_BASE_NS                        (0x40046000u)
  /** Peripheral INPUTMUX1 base pointer */
  #define INPUTMUX1                                ((INPUTMUX1_Type *)INPUTMUX1_BASE)
  /** Peripheral INPUTMUX1 base pointer */
  #define INPUTMUX1_NS                             ((INPUTMUX1_Type *)INPUTMUX1_BASE_NS)
  /** Array initializer of INPUTMUX1 peripheral base addresses */
  #define INPUTMUX1_BASE_ADDRS                     { INPUTMUX1_BASE }
  /** Array initializer of INPUTMUX1 peripheral base pointers */
  #define INPUTMUX1_BASE_PTRS                      { INPUTMUX1 }
  /** Array initializer of INPUTMUX1 peripheral base addresses */
  #define INPUTMUX1_BASE_ADDRS_NS                  { INPUTMUX1_BASE_NS }
  /** Array initializer of INPUTMUX1 peripheral base pointers */
  #define INPUTMUX1_BASE_PTRS_NS                   { INPUTMUX1_NS }
#else
  /** Peripheral INPUTMUX1 base address */
  #define INPUTMUX1_BASE                           (0x40046000u)
  /** Peripheral INPUTMUX1 base pointer */
  #define INPUTMUX1                                ((INPUTMUX1_Type *)INPUTMUX1_BASE)
  /** Array initializer of INPUTMUX1 peripheral base addresses */
  #define INPUTMUX1_BASE_ADDRS                     { INPUTMUX1_BASE }
  /** Array initializer of INPUTMUX1 peripheral base pointers */
  #define INPUTMUX1_BASE_PTRS                      { INPUTMUX1 }
#endif
/** INPUTMUX extra definition */
#define INPUTMUX_Type INPUTMUX1_Type
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
#define INPUTMUX_BASE_ADDRS INPUTMUX1_BASE_ADDRS
#define INPUTMUX_BASE_PTRS INPUTMUX1_BASE_PTRS
#define INPUTMUX_BASE_ADDRS_NS INPUTMUX1_BASE_ADDRS_NS
#define INPUTMUX_BASE_PTRS_NS INPUTMUX1_BASE_PTRS_NS
#else
#define INPUTMUX_BASE_ADDRS INPUTMUX1_BASE_ADDRS
#define INPUTMUX_BASE_PTRS INPUTMUX1_BASE_PTRS
#endif


/* IOPCTL1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOPCTL1 base address */
  #define IOPCTL1_BASE                             (0x50064000u)
  /** Peripheral IOPCTL1 base address */
  #define IOPCTL1_BASE_NS                          (0x40064000u)
  /** Peripheral IOPCTL1 base pointer */
  #define IOPCTL1                                  ((IOPCTL1_Type *)IOPCTL1_BASE)
  /** Peripheral IOPCTL1 base pointer */
  #define IOPCTL1_NS                               ((IOPCTL1_Type *)IOPCTL1_BASE_NS)
  /** Array initializer of IOPCTL1 peripheral base addresses */
  #define IOPCTL1_BASE_ADDRS                       { IOPCTL1_BASE }
  /** Array initializer of IOPCTL1 peripheral base pointers */
  #define IOPCTL1_BASE_PTRS                        { IOPCTL1 }
  /** Array initializer of IOPCTL1 peripheral base addresses */
  #define IOPCTL1_BASE_ADDRS_NS                    { IOPCTL1_BASE_NS }
  /** Array initializer of IOPCTL1 peripheral base pointers */
  #define IOPCTL1_BASE_PTRS_NS                     { IOPCTL1_NS }
#else
  /** Peripheral IOPCTL1 base address */
  #define IOPCTL1_BASE                             (0x40064000u)
  /** Peripheral IOPCTL1 base pointer */
  #define IOPCTL1                                  ((IOPCTL1_Type *)IOPCTL1_BASE)
  /** Array initializer of IOPCTL1 peripheral base addresses */
  #define IOPCTL1_BASE_ADDRS                       { IOPCTL1_BASE }
  /** Array initializer of IOPCTL1 peripheral base pointers */
  #define IOPCTL1_BASE_PTRS                        { IOPCTL1 }
#endif

/* IOPCTL2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOPCTL2 base address */
  #define IOPCTL2_BASE                             (0x500A5000u)
  /** Peripheral IOPCTL2 base address */
  #define IOPCTL2_BASE_NS                          (0x400A5000u)
  /** Peripheral IOPCTL2 base pointer */
  #define IOPCTL2                                  ((IOPCTL2_Type *)IOPCTL2_BASE)
  /** Peripheral IOPCTL2 base pointer */
  #define IOPCTL2_NS                               ((IOPCTL2_Type *)IOPCTL2_BASE_NS)
  /** Array initializer of IOPCTL2 peripheral base addresses */
  #define IOPCTL2_BASE_ADDRS                       { IOPCTL2_BASE }
  /** Array initializer of IOPCTL2 peripheral base pointers */
  #define IOPCTL2_BASE_PTRS                        { IOPCTL2 }
  /** Array initializer of IOPCTL2 peripheral base addresses */
  #define IOPCTL2_BASE_ADDRS_NS                    { IOPCTL2_BASE_NS }
  /** Array initializer of IOPCTL2 peripheral base pointers */
  #define IOPCTL2_BASE_PTRS_NS                     { IOPCTL2_NS }
#else
  /** Peripheral IOPCTL2 base address */
  #define IOPCTL2_BASE                             (0x400A5000u)
  /** Peripheral IOPCTL2 base pointer */
  #define IOPCTL2                                  ((IOPCTL2_Type *)IOPCTL2_BASE)
  /** Array initializer of IOPCTL2 peripheral base addresses */
  #define IOPCTL2_BASE_ADDRS                       { IOPCTL2_BASE }
  /** Array initializer of IOPCTL2 peripheral base pointers */
  #define IOPCTL2_BASE_PTRS                        { IOPCTL2 }
#endif
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** Array initializer of IOPCTL peripheral base addresses */
  #define IOPCTL_BASE_ADDRS                        {0u, IOPCTL1_BASE, IOPCTLR2_BASE}
/** Array initializer of IOPCTL NS peripheral base addresses */
  #define IOPCTL_BASE_ADDRS_NS                     {0u, IOPCTL1_BASE_NS, IOPCTLR2_BASE_NS}
#else
/** Array initializer of IOPCTL peripheral base addresses */
  #define IOPCTL_BASE_ADDRS                        {0u, IOPCTL1_BASE, IOPCTLR2_BASE}
#endif


/* JPEGDEC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral JPEGDEC base address */
  #define JPEGDEC_BASE                             (0x500A6100u)
  /** Peripheral JPEGDEC base address */
  #define JPEGDEC_BASE_NS                          (0x400A6100u)
  /** Peripheral JPEGDEC base pointer */
  #define JPEGDEC                                  ((JPEGDEC_Type *)JPEGDEC_BASE)
  /** Peripheral JPEGDEC base pointer */
  #define JPEGDEC_NS                               ((JPEGDEC_Type *)JPEGDEC_BASE_NS)
  /** Array initializer of JPEGDEC peripheral base addresses */
  #define JPEGDEC_BASE_ADDRS                       { JPEGDEC_BASE }
  /** Array initializer of JPEGDEC peripheral base pointers */
  #define JPEGDEC_BASE_PTRS                        { JPEGDEC }
  /** Array initializer of JPEGDEC peripheral base addresses */
  #define JPEGDEC_BASE_ADDRS_NS                    { JPEGDEC_BASE_NS }
  /** Array initializer of JPEGDEC peripheral base pointers */
  #define JPEGDEC_BASE_PTRS_NS                     { JPEGDEC_NS }
#else
  /** Peripheral JPEGDEC base address */
  #define JPEGDEC_BASE                             (0x400A6100u)
  /** Peripheral JPEGDEC base pointer */
  #define JPEGDEC                                  ((JPEGDEC_Type *)JPEGDEC_BASE)
  /** Array initializer of JPEGDEC peripheral base addresses */
  #define JPEGDEC_BASE_ADDRS                       { JPEGDEC_BASE }
  /** Array initializer of JPEGDEC peripheral base pointers */
  #define JPEGDEC_BASE_PTRS                        { JPEGDEC }
#endif

/* JPGDECWRP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral JPGDECWRP base address */
  #define JPGDECWRP_BASE                           (0x500A6000u)
  /** Peripheral JPGDECWRP base address */
  #define JPGDECWRP_BASE_NS                        (0x400A6000u)
  /** Peripheral JPGDECWRP base pointer */
  #define JPGDECWRP                                ((JPGDECWRP_Type *)JPGDECWRP_BASE)
  /** Peripheral JPGDECWRP base pointer */
  #define JPGDECWRP_NS                             ((JPGDECWRP_Type *)JPGDECWRP_BASE_NS)
  /** Array initializer of JPGDECWRP peripheral base addresses */
  #define JPGDECWRP_BASE_ADDRS                     { JPGDECWRP_BASE }
  /** Array initializer of JPGDECWRP peripheral base pointers */
  #define JPGDECWRP_BASE_PTRS                      { JPGDECWRP }
  /** Array initializer of JPGDECWRP peripheral base addresses */
  #define JPGDECWRP_BASE_ADDRS_NS                  { JPGDECWRP_BASE_NS }
  /** Array initializer of JPGDECWRP peripheral base pointers */
  #define JPGDECWRP_BASE_PTRS_NS                   { JPGDECWRP_NS }
#else
  /** Peripheral JPGDECWRP base address */
  #define JPGDECWRP_BASE                           (0x400A6000u)
  /** Peripheral JPGDECWRP base pointer */
  #define JPGDECWRP                                ((JPGDECWRP_Type *)JPGDECWRP_BASE)
  /** Array initializer of JPGDECWRP peripheral base addresses */
  #define JPGDECWRP_BASE_ADDRS                     { JPGDECWRP_BASE }
  /** Array initializer of JPGDECWRP peripheral base pointers */
  #define JPGDECWRP_BASE_PTRS                      { JPGDECWRP }
#endif

/* LCDIF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LCDIF base address */
  #define LCDIF_BASE                               (0x50480000u)
  /** Peripheral LCDIF base address */
  #define LCDIF_BASE_NS                            (0x40480000u)
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
  #define LCDIF_BASE                               (0x40480000u)
  /** Peripheral LCDIF base pointer */
  #define LCDIF                                    ((LCDIF_Type *)LCDIF_BASE)
  /** Array initializer of LCDIF peripheral base addresses */
  #define LCDIF_BASE_ADDRS                         { LCDIF_BASE }
  /** Array initializer of LCDIF peripheral base pointers */
  #define LCDIF_BASE_PTRS                          { LCDIF }
#endif
/** Interrupt vectors for the LCDIF peripheral type */
#define LCDIF_IRQS                               { LCDIF_IRQn }

/* LPI2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPI2C15 base address */
  #define LPI2C15_BASE                             (0x50213000u)
  /** Peripheral LPI2C15 base address */
  #define LPI2C15_BASE_NS                          (0x40213000u)
  /** Peripheral LPI2C15 base pointer */
  #define LPI2C15                                  ((LPI2C_Type *)LPI2C15_BASE)
  /** Peripheral LPI2C15 base pointer */
  #define LPI2C15_NS                               ((LPI2C_Type *)LPI2C15_BASE_NS)
  /** Peripheral LPI2C17 base address */
  #define LPI2C17_BASE                             (0x50326800u)
  /** Peripheral LPI2C17 base address */
  #define LPI2C17_BASE_NS                          (0x40326800u)
  /** Peripheral LPI2C17 base pointer */
  #define LPI2C17                                  ((LPI2C_Type *)LPI2C17_BASE)
  /** Peripheral LPI2C17 base pointer */
  #define LPI2C17_NS                               ((LPI2C_Type *)LPI2C17_BASE_NS)
  /** Peripheral LPI2C18 base address */
  #define LPI2C18_BASE                             (0x50327800u)
  /** Peripheral LPI2C18 base address */
  #define LPI2C18_BASE_NS                          (0x40327800u)
  /** Peripheral LPI2C18 base pointer */
  #define LPI2C18                                  ((LPI2C_Type *)LPI2C18_BASE)
  /** Peripheral LPI2C18 base pointer */
  #define LPI2C18_NS                               ((LPI2C_Type *)LPI2C18_BASE_NS)
  /** Peripheral LPI2C19 base address */
  #define LPI2C19_BASE                             (0x50328800u)
  /** Peripheral LPI2C19 base address */
  #define LPI2C19_BASE_NS                          (0x40328800u)
  /** Peripheral LPI2C19 base pointer */
  #define LPI2C19                                  ((LPI2C_Type *)LPI2C19_BASE)
  /** Peripheral LPI2C19 base pointer */
  #define LPI2C19_NS                               ((LPI2C_Type *)LPI2C19_BASE_NS)
  /** Peripheral LPI2C20 base address */
  #define LPI2C20_BASE                             (0x50329800u)
  /** Peripheral LPI2C20 base address */
  #define LPI2C20_BASE_NS                          (0x40329800u)
  /** Peripheral LPI2C20 base pointer */
  #define LPI2C20                                  ((LPI2C_Type *)LPI2C20_BASE)
  /** Peripheral LPI2C20 base pointer */
  #define LPI2C20_NS                               ((LPI2C_Type *)LPI2C20_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LPI2C15_BASE, 0u, LPI2C17_BASE, LPI2C18_BASE, LPI2C19_BASE, LPI2C20_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, LPI2C15, (LPI2C_Type *)0u, LPI2C17, LPI2C18, LPI2C19, LPI2C20 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LPI2C15_BASE_NS, 0u, LPI2C17_BASE_NS, LPI2C18_BASE_NS, LPI2C19_BASE_NS, LPI2C20_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, LPI2C15_NS, (LPI2C_Type *)0u, LPI2C17_NS, LPI2C18_NS, LPI2C19_NS, LPI2C20_NS }
#else
  /** Peripheral LPI2C15 base address */
  #define LPI2C15_BASE                             (0x40213000u)
  /** Peripheral LPI2C15 base pointer */
  #define LPI2C15                                  ((LPI2C_Type *)LPI2C15_BASE)
  /** Peripheral LPI2C17 base address */
  #define LPI2C17_BASE                             (0x40326800u)
  /** Peripheral LPI2C17 base pointer */
  #define LPI2C17                                  ((LPI2C_Type *)LPI2C17_BASE)
  /** Peripheral LPI2C18 base address */
  #define LPI2C18_BASE                             (0x40327800u)
  /** Peripheral LPI2C18 base pointer */
  #define LPI2C18                                  ((LPI2C_Type *)LPI2C18_BASE)
  /** Peripheral LPI2C19 base address */
  #define LPI2C19_BASE                             (0x40328800u)
  /** Peripheral LPI2C19 base pointer */
  #define LPI2C19                                  ((LPI2C_Type *)LPI2C19_BASE)
  /** Peripheral LPI2C20 base address */
  #define LPI2C20_BASE                             (0x40329800u)
  /** Peripheral LPI2C20 base pointer */
  #define LPI2C20                                  ((LPI2C_Type *)LPI2C20_BASE)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LPI2C15_BASE, 0u, LPI2C17_BASE, LPI2C18_BASE, LPI2C19_BASE, LPI2C20_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, (LPI2C_Type *)0u, LPI2C15, (LPI2C_Type *)0u, LPI2C17, LPI2C18, LPI2C19, LPI2C20 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, LPI2C15_IRQn, NotAvail_IRQn, LP_FLEXCOMM17_IRQn, LP_FLEXCOMM18_IRQn, LP_FLEXCOMM19_IRQn, LP_FLEXCOMM20_IRQn }

/* LPSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPSPI14 base address */
  #define LPSPI14_BASE                             (0x50484000u)
  /** Peripheral LPSPI14 base address */
  #define LPSPI14_BASE_NS                          (0x40484000u)
  /** Peripheral LPSPI14 base pointer */
  #define LPSPI14                                  ((LPSPI_Type *)LPSPI14_BASE)
  /** Peripheral LPSPI14 base pointer */
  #define LPSPI14_NS                               ((LPSPI_Type *)LPSPI14_BASE_NS)
  /** Peripheral LPSPI16 base address */
  #define LPSPI16_BASE                             (0x50405000u)
  /** Peripheral LPSPI16 base address */
  #define LPSPI16_BASE_NS                          (0x40405000u)
  /** Peripheral LPSPI16 base pointer */
  #define LPSPI16                                  ((LPSPI_Type *)LPSPI16_BASE)
  /** Peripheral LPSPI16 base pointer */
  #define LPSPI16_NS                               ((LPSPI_Type *)LPSPI16_BASE_NS)
  /** Peripheral LPSPI17 base address */
  #define LPSPI17_BASE                             (0x50326000u)
  /** Peripheral LPSPI17 base address */
  #define LPSPI17_BASE_NS                          (0x40326000u)
  /** Peripheral LPSPI17 base pointer */
  #define LPSPI17                                  ((LPSPI_Type *)LPSPI17_BASE)
  /** Peripheral LPSPI17 base pointer */
  #define LPSPI17_NS                               ((LPSPI_Type *)LPSPI17_BASE_NS)
  /** Peripheral LPSPI18 base address */
  #define LPSPI18_BASE                             (0x50327000u)
  /** Peripheral LPSPI18 base address */
  #define LPSPI18_BASE_NS                          (0x40327000u)
  /** Peripheral LPSPI18 base pointer */
  #define LPSPI18                                  ((LPSPI_Type *)LPSPI18_BASE)
  /** Peripheral LPSPI18 base pointer */
  #define LPSPI18_NS                               ((LPSPI_Type *)LPSPI18_BASE_NS)
  /** Peripheral LPSPI19 base address */
  #define LPSPI19_BASE                             (0x50328000u)
  /** Peripheral LPSPI19 base address */
  #define LPSPI19_BASE_NS                          (0x40328000u)
  /** Peripheral LPSPI19 base pointer */
  #define LPSPI19                                  ((LPSPI_Type *)LPSPI19_BASE)
  /** Peripheral LPSPI19 base pointer */
  #define LPSPI19_NS                               ((LPSPI_Type *)LPSPI19_BASE_NS)
  /** Peripheral LPSPI20 base address */
  #define LPSPI20_BASE                             (0x50329000u)
  /** Peripheral LPSPI20 base address */
  #define LPSPI20_BASE_NS                          (0x40329000u)
  /** Peripheral LPSPI20 base pointer */
  #define LPSPI20                                  ((LPSPI_Type *)LPSPI20_BASE)
  /** Peripheral LPSPI20 base pointer */
  #define LPSPI20_NS                               ((LPSPI_Type *)LPSPI20_BASE_NS)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LPSPI14_BASE, 0u, LPSPI16_BASE, LPSPI17_BASE, LPSPI18_BASE, LPSPI19_BASE, LPSPI20_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, LPSPI14, (LPSPI_Type *)0u, LPSPI16, LPSPI17, LPSPI18, LPSPI19, LPSPI20 }
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS_NS                      { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LPSPI14_BASE_NS, 0u, LPSPI16_BASE_NS, LPSPI17_BASE_NS, LPSPI18_BASE_NS, LPSPI19_BASE_NS, LPSPI20_BASE_NS }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS_NS                       { (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, LPSPI14_NS, (LPSPI_Type *)0u, LPSPI16_NS, LPSPI17_NS, LPSPI18_NS, LPSPI19_NS, LPSPI20_NS }
#else
  /** Peripheral LPSPI14 base address */
  #define LPSPI14_BASE                             (0x40484000u)
  /** Peripheral LPSPI14 base pointer */
  #define LPSPI14                                  ((LPSPI_Type *)LPSPI14_BASE)
  /** Peripheral LPSPI16 base address */
  #define LPSPI16_BASE                             (0x40405000u)
  /** Peripheral LPSPI16 base pointer */
  #define LPSPI16                                  ((LPSPI_Type *)LPSPI16_BASE)
  /** Peripheral LPSPI17 base address */
  #define LPSPI17_BASE                             (0x40326000u)
  /** Peripheral LPSPI17 base pointer */
  #define LPSPI17                                  ((LPSPI_Type *)LPSPI17_BASE)
  /** Peripheral LPSPI18 base address */
  #define LPSPI18_BASE                             (0x40327000u)
  /** Peripheral LPSPI18 base pointer */
  #define LPSPI18                                  ((LPSPI_Type *)LPSPI18_BASE)
  /** Peripheral LPSPI19 base address */
  #define LPSPI19_BASE                             (0x40328000u)
  /** Peripheral LPSPI19 base pointer */
  #define LPSPI19                                  ((LPSPI_Type *)LPSPI19_BASE)
  /** Peripheral LPSPI20 base address */
  #define LPSPI20_BASE                             (0x40329000u)
  /** Peripheral LPSPI20 base pointer */
  #define LPSPI20                                  ((LPSPI_Type *)LPSPI20_BASE)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LPSPI14_BASE, 0u, LPSPI16_BASE, LPSPI17_BASE, LPSPI18_BASE, LPSPI19_BASE, LPSPI20_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, (LPSPI_Type *)0u, LPSPI14, (LPSPI_Type *)0u, LPSPI16, LPSPI17, LPSPI18, LPSPI19, LPSPI20 }
#endif
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, LP_FLEXCOMM17_IRQn, LP_FLEXCOMM18_IRQn, LP_FLEXCOMM19_IRQn, LP_FLEXCOMM20_IRQn }

/* LPUART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPUART17 base address */
  #define LPUART17_BASE                            (0x50326000u)
  /** Peripheral LPUART17 base address */
  #define LPUART17_BASE_NS                         (0x40326000u)
  /** Peripheral LPUART17 base pointer */
  #define LPUART17                                 ((LPUART_Type *)LPUART17_BASE)
  /** Peripheral LPUART17 base pointer */
  #define LPUART17_NS                              ((LPUART_Type *)LPUART17_BASE_NS)
  /** Peripheral LPUART18 base address */
  #define LPUART18_BASE                            (0x50327000u)
  /** Peripheral LPUART18 base address */
  #define LPUART18_BASE_NS                         (0x40327000u)
  /** Peripheral LPUART18 base pointer */
  #define LPUART18                                 ((LPUART_Type *)LPUART18_BASE)
  /** Peripheral LPUART18 base pointer */
  #define LPUART18_NS                              ((LPUART_Type *)LPUART18_BASE_NS)
  /** Peripheral LPUART19 base address */
  #define LPUART19_BASE                            (0x50328000u)
  /** Peripheral LPUART19 base address */
  #define LPUART19_BASE_NS                         (0x40328000u)
  /** Peripheral LPUART19 base pointer */
  #define LPUART19                                 ((LPUART_Type *)LPUART19_BASE)
  /** Peripheral LPUART19 base pointer */
  #define LPUART19_NS                              ((LPUART_Type *)LPUART19_BASE_NS)
  /** Peripheral LPUART20 base address */
  #define LPUART20_BASE                            (0x50329000u)
  /** Peripheral LPUART20 base address */
  #define LPUART20_BASE_NS                         (0x40329000u)
  /** Peripheral LPUART20 base pointer */
  #define LPUART20                                 ((LPUART_Type *)LPUART20_BASE)
  /** Peripheral LPUART20 base pointer */
  #define LPUART20_NS                              ((LPUART_Type *)LPUART20_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LPUART17_BASE, LPUART18_BASE, LPUART19_BASE, LPUART20_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, LPUART17, LPUART18, LPUART19, LPUART20 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LPUART17_BASE_NS, LPUART18_BASE_NS, LPUART19_BASE_NS, LPUART20_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, LPUART17_NS, LPUART18_NS, LPUART19_NS, LPUART20_NS }
#else
  /** Peripheral LPUART17 base address */
  #define LPUART17_BASE                            (0x40326000u)
  /** Peripheral LPUART17 base pointer */
  #define LPUART17                                 ((LPUART_Type *)LPUART17_BASE)
  /** Peripheral LPUART18 base address */
  #define LPUART18_BASE                            (0x40327000u)
  /** Peripheral LPUART18 base pointer */
  #define LPUART18                                 ((LPUART_Type *)LPUART18_BASE)
  /** Peripheral LPUART19 base address */
  #define LPUART19_BASE                            (0x40328000u)
  /** Peripheral LPUART19 base pointer */
  #define LPUART19                                 ((LPUART_Type *)LPUART19_BASE)
  /** Peripheral LPUART20 base address */
  #define LPUART20_BASE                            (0x40329000u)
  /** Peripheral LPUART20 base pointer */
  #define LPUART20                                 ((LPUART_Type *)LPUART20_BASE)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LPUART17_BASE, LPUART18_BASE, LPUART19_BASE, LPUART20_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, (LPUART_Type *)0u, LPUART17, LPUART18, LPUART19, LPUART20 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, LP_FLEXCOMM17_IRQn, LP_FLEXCOMM18_IRQn, LP_FLEXCOMM19_IRQn, LP_FLEXCOMM20_IRQn }
#define LPUART_ERR_IRQS                          { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, LP_FLEXCOMM17_IRQn, LP_FLEXCOMM18_IRQn, LP_FLEXCOMM19_IRQn, LP_FLEXCOMM20_IRQn }

/* LP_FLEXCOMM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LP_FLEXCOMM17 base address */
  #define LP_FLEXCOMM17_BASE                       (0x50326000u)
  /** Peripheral LP_FLEXCOMM17 base address */
  #define LP_FLEXCOMM17_BASE_NS                    (0x40326000u)
  /** Peripheral LP_FLEXCOMM17 base pointer */
  #define LP_FLEXCOMM17                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM17_BASE)
  /** Peripheral LP_FLEXCOMM17 base pointer */
  #define LP_FLEXCOMM17_NS                         ((LP_FLEXCOMM_Type *)LP_FLEXCOMM17_BASE_NS)
  /** Peripheral LP_FLEXCOMM18 base address */
  #define LP_FLEXCOMM18_BASE                       (0x50327000u)
  /** Peripheral LP_FLEXCOMM18 base address */
  #define LP_FLEXCOMM18_BASE_NS                    (0x40327000u)
  /** Peripheral LP_FLEXCOMM18 base pointer */
  #define LP_FLEXCOMM18                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM18_BASE)
  /** Peripheral LP_FLEXCOMM18 base pointer */
  #define LP_FLEXCOMM18_NS                         ((LP_FLEXCOMM_Type *)LP_FLEXCOMM18_BASE_NS)
  /** Peripheral LP_FLEXCOMM19 base address */
  #define LP_FLEXCOMM19_BASE                       (0x50328000u)
  /** Peripheral LP_FLEXCOMM19 base address */
  #define LP_FLEXCOMM19_BASE_NS                    (0x40328000u)
  /** Peripheral LP_FLEXCOMM19 base pointer */
  #define LP_FLEXCOMM19                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM19_BASE)
  /** Peripheral LP_FLEXCOMM19 base pointer */
  #define LP_FLEXCOMM19_NS                         ((LP_FLEXCOMM_Type *)LP_FLEXCOMM19_BASE_NS)
  /** Peripheral LP_FLEXCOMM20 base address */
  #define LP_FLEXCOMM20_BASE                       (0x50329000u)
  /** Peripheral LP_FLEXCOMM20 base address */
  #define LP_FLEXCOMM20_BASE_NS                    (0x40329000u)
  /** Peripheral LP_FLEXCOMM20 base pointer */
  #define LP_FLEXCOMM20                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM20_BASE)
  /** Peripheral LP_FLEXCOMM20 base pointer */
  #define LP_FLEXCOMM20_NS                         ((LP_FLEXCOMM_Type *)LP_FLEXCOMM20_BASE_NS)
  /** Array initializer of LP_FLEXCOMM peripheral base addresses */
  #define LP_FLEXCOMM_BASE_ADDRS                   { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LP_FLEXCOMM17_BASE, LP_FLEXCOMM18_BASE, LP_FLEXCOMM19_BASE, LP_FLEXCOMM20_BASE }
  /** Array initializer of LP_FLEXCOMM peripheral base pointers */
  #define LP_FLEXCOMM_BASE_PTRS                    { (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, LP_FLEXCOMM17, LP_FLEXCOMM18, LP_FLEXCOMM19, LP_FLEXCOMM20 }
  /** Array initializer of LP_FLEXCOMM peripheral base addresses */
  #define LP_FLEXCOMM_BASE_ADDRS_NS                { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LP_FLEXCOMM17_BASE_NS, LP_FLEXCOMM18_BASE_NS, LP_FLEXCOMM19_BASE_NS, LP_FLEXCOMM20_BASE_NS }
  /** Array initializer of LP_FLEXCOMM peripheral base pointers */
  #define LP_FLEXCOMM_BASE_PTRS_NS                 { (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, LP_FLEXCOMM17_NS, LP_FLEXCOMM18_NS, LP_FLEXCOMM19_NS, LP_FLEXCOMM20_NS }
#else
  /** Peripheral LP_FLEXCOMM17 base address */
  #define LP_FLEXCOMM17_BASE                       (0x40326000u)
  /** Peripheral LP_FLEXCOMM17 base pointer */
  #define LP_FLEXCOMM17                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM17_BASE)
  /** Peripheral LP_FLEXCOMM18 base address */
  #define LP_FLEXCOMM18_BASE                       (0x40327000u)
  /** Peripheral LP_FLEXCOMM18 base pointer */
  #define LP_FLEXCOMM18                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM18_BASE)
  /** Peripheral LP_FLEXCOMM19 base address */
  #define LP_FLEXCOMM19_BASE                       (0x40328000u)
  /** Peripheral LP_FLEXCOMM19 base pointer */
  #define LP_FLEXCOMM19                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM19_BASE)
  /** Peripheral LP_FLEXCOMM20 base address */
  #define LP_FLEXCOMM20_BASE                       (0x40329000u)
  /** Peripheral LP_FLEXCOMM20 base pointer */
  #define LP_FLEXCOMM20                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM20_BASE)
  /** Array initializer of LP_FLEXCOMM peripheral base addresses */
  #define LP_FLEXCOMM_BASE_ADDRS                   { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, LP_FLEXCOMM17_BASE, LP_FLEXCOMM18_BASE, LP_FLEXCOMM19_BASE, LP_FLEXCOMM20_BASE }
  /** Array initializer of LP_FLEXCOMM peripheral base pointers */
  #define LP_FLEXCOMM_BASE_PTRS                    { (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, (LP_FLEXCOMM_Type *)0u, LP_FLEXCOMM17, LP_FLEXCOMM18, LP_FLEXCOMM19, LP_FLEXCOMM20 }
#endif
/** Interrupt vectors for the LP_FLEXCOMM peripheral type */
#define LP_FLEXCOMM_IRQS                         { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, LP_FLEXCOMM17_IRQn, LP_FLEXCOMM18_IRQn, LP_FLEXCOMM19_IRQn, LP_FLEXCOMM20_IRQn }

/* MIPI_DSI_HOST - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MIPI_DSI_HOST base address */
  #define MIPI_DSI_HOST_BASE                       (0x50417000u)
  /** Peripheral MIPI_DSI_HOST base address */
  #define MIPI_DSI_HOST_BASE_NS                    (0x40417000u)
  /** Peripheral MIPI_DSI_HOST base pointer */
  #define MIPI_DSI_HOST                            ((MIPI_DSI_HOST_Type *)MIPI_DSI_HOST_BASE)
  /** Peripheral MIPI_DSI_HOST base pointer */
  #define MIPI_DSI_HOST_NS                         ((MIPI_DSI_HOST_Type *)MIPI_DSI_HOST_BASE_NS)
  /** Array initializer of MIPI_DSI_HOST peripheral base addresses */
  #define MIPI_DSI_HOST_BASE_ADDRS                 { MIPI_DSI_HOST_BASE }
  /** Array initializer of MIPI_DSI_HOST peripheral base pointers */
  #define MIPI_DSI_HOST_BASE_PTRS                  { MIPI_DSI_HOST }
  /** Array initializer of MIPI_DSI_HOST peripheral base addresses */
  #define MIPI_DSI_HOST_BASE_ADDRS_NS              { MIPI_DSI_HOST_BASE_NS }
  /** Array initializer of MIPI_DSI_HOST peripheral base pointers */
  #define MIPI_DSI_HOST_BASE_PTRS_NS               { MIPI_DSI_HOST_NS }
#else
  /** Peripheral MIPI_DSI_HOST base address */
  #define MIPI_DSI_HOST_BASE                       (0x40417000u)
  /** Peripheral MIPI_DSI_HOST base pointer */
  #define MIPI_DSI_HOST                            ((MIPI_DSI_HOST_Type *)MIPI_DSI_HOST_BASE)
  /** Array initializer of MIPI_DSI_HOST peripheral base addresses */
  #define MIPI_DSI_HOST_BASE_ADDRS                 { MIPI_DSI_HOST_BASE }
  /** Array initializer of MIPI_DSI_HOST peripheral base pointers */
  #define MIPI_DSI_HOST_BASE_PTRS                  { MIPI_DSI_HOST }
#endif
/** Interrupt vectors for the MIPI_DSI_HOST peripheral type */
#define MIPI_DSI_HOST_IRQS                       { MIPI_IRQn }

/* MMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MMU2 base address */
  #define MMU2_BASE                                (0x500A8000u)
  /** Peripheral MMU2 base address */
  #define MMU2_BASE_NS                             (0x400A8000u)
  /** Peripheral MMU2 base pointer */
  #define MMU2                                     ((MMU_Type *)MMU2_BASE)
  /** Peripheral MMU2 base pointer */
  #define MMU2_NS                                  ((MMU_Type *)MMU2_BASE_NS)
  /** Array initializer of MMU peripheral base addresses */
  #define MMU_BASE_ADDRS                           { MMU2_BASE }
  /** Array initializer of MMU peripheral base pointers */
  #define MMU_BASE_PTRS                            { MMU2 }
  /** Array initializer of MMU peripheral base addresses */
  #define MMU_BASE_ADDRS_NS                        { MMU2_BASE_NS }
  /** Array initializer of MMU peripheral base pointers */
  #define MMU_BASE_PTRS_NS                         { MMU2_NS }
#else
  /** Peripheral MMU2 base address */
  #define MMU2_BASE                                (0x400A8000u)
  /** Peripheral MMU2 base pointer */
  #define MMU2                                     ((MMU_Type *)MMU2_BASE)
  /** Array initializer of MMU peripheral base addresses */
  #define MMU_BASE_ADDRS                           { MMU2_BASE }
  /** Array initializer of MMU peripheral base pointers */
  #define MMU_BASE_PTRS                            { MMU2 }
#endif
/** Interrupt vectors for the MMU peripheral type */
#define MMU_IRQS                                 { MMU2_IRQn }

/* MRT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MRT1 base address */
  #define MRT1_BASE                                (0x5004D000u)
  /** Peripheral MRT1 base address */
  #define MRT1_BASE_NS                             (0x4004D000u)
  /** Peripheral MRT1 base pointer */
  #define MRT1                                     ((MRT_Type *)MRT1_BASE)
  /** Peripheral MRT1 base pointer */
  #define MRT1_NS                                  ((MRT_Type *)MRT1_BASE_NS)
  /** Array initializer of MRT peripheral base addresses */
  #define MRT_BASE_ADDRS                           { 0u, MRT1_BASE }
  /** Array initializer of MRT peripheral base pointers */
  #define MRT_BASE_PTRS                            { (MRT_Type *)0u, MRT1 }
  /** Array initializer of MRT peripheral base addresses */
  #define MRT_BASE_ADDRS_NS                        { 0u, MRT1_BASE_NS }
  /** Array initializer of MRT peripheral base pointers */
  #define MRT_BASE_PTRS_NS                         { (MRT_Type *)0u, MRT1_NS }
#else
  /** Peripheral MRT1 base address */
  #define MRT1_BASE                                (0x4004D000u)
  /** Peripheral MRT1 base pointer */
  #define MRT1                                     ((MRT_Type *)MRT1_BASE)
  /** Array initializer of MRT peripheral base addresses */
  #define MRT_BASE_ADDRS                           { 0u, MRT1_BASE }
  /** Array initializer of MRT peripheral base pointers */
  #define MRT_BASE_PTRS                            { (MRT_Type *)0u, MRT1 }
#endif
/** Interrupt vectors for the MRT peripheral type */
#define MRT_IRQS                                 { NotAvail_IRQn, MRT1_IRQn }

/* MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MU1_MUB base address */
  #define MU1_MUB_BASE                             (0x50203000u)
  /** Peripheral MU1_MUB base address */
  #define MU1_MUB_BASE_NS                          (0x40203000u)
  /** Peripheral MU1_MUB base pointer */
  #define MU1_MUB                                  ((MU_Type *)MU1_MUB_BASE)
  /** Peripheral MU1_MUB base pointer */
  #define MU1_MUB_NS                               ((MU_Type *)MU1_MUB_BASE_NS)
  /** Peripheral MU2_MUB base address */
  #define MU2_MUB_BASE                             (0x50205000u)
  /** Peripheral MU2_MUB base address */
  #define MU2_MUB_BASE_NS                          (0x40205000u)
  /** Peripheral MU2_MUB base pointer */
  #define MU2_MUB                                  ((MU_Type *)MU2_MUB_BASE)
  /** Peripheral MU2_MUB base pointer */
  #define MU2_MUB_NS                               ((MU_Type *)MU2_MUB_BASE_NS)
  /** Peripheral MU3_MUA base address */
  #define MU3_MUA_BASE                             (0x50319000u)
  /** Peripheral MU3_MUA base address */
  #define MU3_MUA_BASE_NS                          (0x40319000u)
  /** Peripheral MU3_MUA base pointer */
  #define MU3_MUA                                  ((MU_Type *)MU3_MUA_BASE)
  /** Peripheral MU3_MUA base pointer */
  #define MU3_MUA_NS                               ((MU_Type *)MU3_MUA_BASE_NS)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU1_MUB_BASE, MU2_MUB_BASE, MU3_MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU1_MUB, MU2_MUB, MU3_MUA }
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS_NS                         { MU1_MUB_BASE_NS, MU2_MUB_BASE_NS, MU3_MUA_BASE_NS }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS_NS                          { MU1_MUB_NS, MU2_MUB_NS, MU3_MUA_NS }
#else
  /** Peripheral MU1_MUB base address */
  #define MU1_MUB_BASE                             (0x40203000u)
  /** Peripheral MU1_MUB base pointer */
  #define MU1_MUB                                  ((MU_Type *)MU1_MUB_BASE)
  /** Peripheral MU2_MUB base address */
  #define MU2_MUB_BASE                             (0x40205000u)
  /** Peripheral MU2_MUB base pointer */
  #define MU2_MUB                                  ((MU_Type *)MU2_MUB_BASE)
  /** Peripheral MU3_MUA base address */
  #define MU3_MUA_BASE                             (0x40319000u)
  /** Peripheral MU3_MUA base pointer */
  #define MU3_MUA                                  ((MU_Type *)MU3_MUA_BASE)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU1_MUB_BASE, MU2_MUB_BASE, MU3_MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU1_MUB, MU2_MUB, MU3_MUA }
#endif
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU1_B_IRQn, MU2_B_IRQn, MU3_A_IRQn }

/* NIC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NIC_MEDIA1 base address */
  #define NIC_MEDIA1_BASE                          (0x504C0000u)
  /** Peripheral NIC_MEDIA1 base address */
  #define NIC_MEDIA1_BASE_NS                       (0x404C0000u)
  /** Peripheral NIC_MEDIA1 base pointer */
  #define NIC_MEDIA1                               ((NIC_Type *)NIC_MEDIA1_BASE)
  /** Peripheral NIC_MEDIA1 base pointer */
  #define NIC_MEDIA1_NS                            ((NIC_Type *)NIC_MEDIA1_BASE_NS)
  /** Array initializer of NIC peripheral base addresses */
  #define NIC_BASE_ADDRS                           { NIC_MEDIA1_BASE }
  /** Array initializer of NIC peripheral base pointers */
  #define NIC_BASE_PTRS                            { NIC_MEDIA1 }
  /** Array initializer of NIC peripheral base addresses */
  #define NIC_BASE_ADDRS_NS                        { NIC_MEDIA1_BASE_NS }
  /** Array initializer of NIC peripheral base pointers */
  #define NIC_BASE_PTRS_NS                         { NIC_MEDIA1_NS }
#else
  /** Peripheral NIC_MEDIA1 base address */
  #define NIC_MEDIA1_BASE                          (0x404C0000u)
  /** Peripheral NIC_MEDIA1 base pointer */
  #define NIC_MEDIA1                               ((NIC_Type *)NIC_MEDIA1_BASE)
  /** Array initializer of NIC peripheral base addresses */
  #define NIC_BASE_ADDRS                           { NIC_MEDIA1_BASE }
  /** Array initializer of NIC peripheral base pointers */
  #define NIC_BASE_PTRS                            { NIC_MEDIA1 }
#endif

/* OSC32KNP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OSC32KNP base address */
  #define OSC32KNP_BASE                            (0x50063000u)
  /** Peripheral OSC32KNP base address */
  #define OSC32KNP_BASE_NS                         (0x40063000u)
  /** Peripheral OSC32KNP base pointer */
  #define OSC32KNP                                 ((OSC32KNP_Type *)OSC32KNP_BASE)
  /** Peripheral OSC32KNP base pointer */
  #define OSC32KNP_NS                              ((OSC32KNP_Type *)OSC32KNP_BASE_NS)
  /** Array initializer of OSC32KNP peripheral base addresses */
  #define OSC32KNP_BASE_ADDRS                      { OSC32KNP_BASE }
  /** Array initializer of OSC32KNP peripheral base pointers */
  #define OSC32KNP_BASE_PTRS                       { OSC32KNP }
  /** Array initializer of OSC32KNP peripheral base addresses */
  #define OSC32KNP_BASE_ADDRS_NS                   { OSC32KNP_BASE_NS }
  /** Array initializer of OSC32KNP peripheral base pointers */
  #define OSC32KNP_BASE_PTRS_NS                    { OSC32KNP_NS }
#else
  /** Peripheral OSC32KNP base address */
  #define OSC32KNP_BASE                            (0x40063000u)
  /** Peripheral OSC32KNP base pointer */
  #define OSC32KNP                                 ((OSC32KNP_Type *)OSC32KNP_BASE)
  /** Array initializer of OSC32KNP peripheral base addresses */
  #define OSC32KNP_BASE_ADDRS                      { OSC32KNP_BASE }
  /** Array initializer of OSC32KNP peripheral base pointers */
  #define OSC32KNP_BASE_PTRS                       { OSC32KNP }
#endif

/* OSTIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OSTIMER_CPU1 base address */
  #define OSTIMER_CPU1_BASE                        (0x50209000u)
  /** Peripheral OSTIMER_CPU1 base address */
  #define OSTIMER_CPU1_BASE_NS                     (0x40209000u)
  /** Peripheral OSTIMER_CPU1 base pointer */
  #define OSTIMER_CPU1                             ((OSTIMER_Type *)OSTIMER_CPU1_BASE)
  /** Peripheral OSTIMER_CPU1 base pointer */
  #define OSTIMER_CPU1_NS                          ((OSTIMER_Type *)OSTIMER_CPU1_BASE_NS)
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS                       { OSTIMER_CPU1_BASE }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS                        { OSTIMER_CPU1 }
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS_NS                    { OSTIMER_CPU1_BASE_NS }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS_NS                     { OSTIMER_CPU1_NS }
#else
  /** Peripheral OSTIMER_CPU1 base address */
  #define OSTIMER_CPU1_BASE                        (0x40209000u)
  /** Peripheral OSTIMER_CPU1 base pointer */
  #define OSTIMER_CPU1                             ((OSTIMER_Type *)OSTIMER_CPU1_BASE)
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS                       { OSTIMER_CPU1_BASE }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS                        { OSTIMER_CPU1 }
#endif
/** Interrupt vectors for the OSTIMER peripheral type */
#define OSTIMER_IRQS                             { OS_EVENT_IRQn }

/* PDM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PDM base address */
  #define PDM_BASE                                 (0x5020E000u)
  /** Peripheral PDM base address */
  #define PDM_BASE_NS                              (0x4020E000u)
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
  #define PDM_BASE                                 (0x4020E000u)
  /** Peripheral PDM base pointer */
  #define PDM                                      ((PDM_Type *)PDM_BASE)
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS                           { PDM_BASE }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS                            { PDM }
#endif
/** Interrupt vectors for the PDM peripheral type */
#define PDM_HWVAD_Event_IRQS                     { PDM_HWVAD_EVENT_IRQn }
#define PDM_HWVAD_Error_IRQS                     { PDM_HWVAD_EVENT_IRQn }
#define PDM_Event_IRQS                           { PDM_EVENT_IRQn }
#define PDM_Error_IRQS                           { PDM_EVENT_IRQn }

/* PINT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PINT1 base address */
  #define PINT1_BASE                               (0x50045000u)
  /** Peripheral PINT1 base address */
  #define PINT1_BASE_NS                            (0x40045000u)
  /** Peripheral PINT1 base pointer */
  #define PINT1                                    ((PINT_Type *)PINT1_BASE)
  /** Peripheral PINT1 base pointer */
  #define PINT1_NS                                 ((PINT_Type *)PINT1_BASE_NS)
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS                          { PINT1_BASE }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS                           { PINT1 }
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS_NS                       { PINT1_BASE_NS }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS_NS                        { PINT1_NS }
#else
  /** Peripheral PINT1 base address */
  #define PINT1_BASE                               (0x40045000u)
  /** Peripheral PINT1 base pointer */
  #define PINT1                                    ((PINT_Type *)PINT1_BASE)
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS                          { PINT1_BASE }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS                           { PINT1 }
#endif
/** Interrupt vectors for the PINT peripheral type */
#define PINT_IRQS                                { PIN_INT0_IRQn, PIN_INT1_IRQn, PIN_INT2_IRQn, PIN_INT3_IRQn }

/* PMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PMC1 base address */
  #define PMC1_BASE                                (0x50210000u)
  /** Peripheral PMC1 base address */
  #define PMC1_BASE_NS                             (0x40210000u)
  /** Peripheral PMC1 base pointer */
  #define PMC1                                     ((PMC_Type *)PMC1_BASE)
  /** Peripheral PMC1 base pointer */
  #define PMC1_NS                                  ((PMC_Type *)PMC1_BASE_NS)
  /** Array initializer of PMC peripheral base addresses */
  #define PMC_BASE_ADDRS                           { PMC1_BASE }
  /** Array initializer of PMC peripheral base pointers */
  #define PMC_BASE_PTRS                            { PMC1 }
  /** Array initializer of PMC peripheral base addresses */
  #define PMC_BASE_ADDRS_NS                        { PMC1_BASE_NS }
  /** Array initializer of PMC peripheral base pointers */
  #define PMC_BASE_PTRS_NS                         { PMC1_NS }
#else
  /** Peripheral PMC1 base address */
  #define PMC1_BASE                                (0x40210000u)
  /** Peripheral PMC1 base pointer */
  #define PMC1                                     ((PMC_Type *)PMC1_BASE)
  /** Array initializer of PMC peripheral base addresses */
  #define PMC_BASE_ADDRS                           { PMC1_BASE }
  /** Array initializer of PMC peripheral base pointers */
  #define PMC_BASE_PTRS                            { PMC1 }
#endif

/* PNGDEC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PNGDEC base address */
  #define PNGDEC_BASE                              (0x500A7000u)
  /** Peripheral PNGDEC base address */
  #define PNGDEC_BASE_NS                           (0x400A7000u)
  /** Peripheral PNGDEC base pointer */
  #define PNGDEC                                   ((PNGDEC_Type *)PNGDEC_BASE)
  /** Peripheral PNGDEC base pointer */
  #define PNGDEC_NS                                ((PNGDEC_Type *)PNGDEC_BASE_NS)
  /** Array initializer of PNGDEC peripheral base addresses */
  #define PNGDEC_BASE_ADDRS                        { PNGDEC_BASE }
  /** Array initializer of PNGDEC peripheral base pointers */
  #define PNGDEC_BASE_PTRS                         { PNGDEC }
  /** Array initializer of PNGDEC peripheral base addresses */
  #define PNGDEC_BASE_ADDRS_NS                     { PNGDEC_BASE_NS }
  /** Array initializer of PNGDEC peripheral base pointers */
  #define PNGDEC_BASE_PTRS_NS                      { PNGDEC_NS }
#else
  /** Peripheral PNGDEC base address */
  #define PNGDEC_BASE                              (0x400A7000u)
  /** Peripheral PNGDEC base pointer */
  #define PNGDEC                                   ((PNGDEC_Type *)PNGDEC_BASE)
  /** Array initializer of PNGDEC peripheral base addresses */
  #define PNGDEC_BASE_ADDRS                        { PNGDEC_BASE }
  /** Array initializer of PNGDEC peripheral base pointers */
  #define PNGDEC_BASE_PTRS                         { PNGDEC }
#endif

/* PVTS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PVTS1 base address */
  #define PVTS1_BASE                               (0x50043000u)
  /** Peripheral PVTS1 base address */
  #define PVTS1_BASE_NS                            (0x40043000u)
  /** Peripheral PVTS1 base pointer */
  #define PVTS1                                    ((PVTS_Type *)PVTS1_BASE)
  /** Peripheral PVTS1 base pointer */
  #define PVTS1_NS                                 ((PVTS_Type *)PVTS1_BASE_NS)
  /** Array initializer of PVTS peripheral base addresses */
  #define PVTS_BASE_ADDRS                          { PVTS1_BASE }
  /** Array initializer of PVTS peripheral base pointers */
  #define PVTS_BASE_PTRS                           { PVTS1 }
  /** Array initializer of PVTS peripheral base addresses */
  #define PVTS_BASE_ADDRS_NS                       { PVTS1_BASE_NS }
  /** Array initializer of PVTS peripheral base pointers */
  #define PVTS_BASE_PTRS_NS                        { PVTS1_NS }
#else
  /** Peripheral PVTS1 base address */
  #define PVTS1_BASE                               (0x40043000u)
  /** Peripheral PVTS1 base pointer */
  #define PVTS1                                    ((PVTS_Type *)PVTS1_BASE)
  /** Array initializer of PVTS peripheral base addresses */
  #define PVTS_BASE_ADDRS                          { PVTS1_BASE }
  /** Array initializer of PVTS peripheral base pointers */
  #define PVTS_BASE_PTRS                           { PVTS1 }
#endif

/* RSTCTL1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RSTCTL1 base address */
  #define RSTCTL1_BASE                             (0x50040000u)
  /** Peripheral RSTCTL1 base address */
  #define RSTCTL1_BASE_NS                          (0x40040000u)
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
  #define RSTCTL1_BASE                             (0x40040000u)
  /** Peripheral RSTCTL1 base pointer */
  #define RSTCTL1                                  ((RSTCTL1_Type *)RSTCTL1_BASE)
  /** Array initializer of RSTCTL1 peripheral base addresses */
  #define RSTCTL1_BASE_ADDRS                       { RSTCTL1_BASE }
  /** Array initializer of RSTCTL1 peripheral base pointers */
  #define RSTCTL1_BASE_PTRS                        { RSTCTL1 }
#endif

/* RSTCTL2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RSTCTL2 base address */
  #define RSTCTL2_BASE                             (0x50067000u)
  /** Peripheral RSTCTL2 base address */
  #define RSTCTL2_BASE_NS                          (0x40067000u)
  /** Peripheral RSTCTL2 base pointer */
  #define RSTCTL2                                  ((RSTCTL2_Type *)RSTCTL2_BASE)
  /** Peripheral RSTCTL2 base pointer */
  #define RSTCTL2_NS                               ((RSTCTL2_Type *)RSTCTL2_BASE_NS)
  /** Array initializer of RSTCTL2 peripheral base addresses */
  #define RSTCTL2_BASE_ADDRS                       { RSTCTL2_BASE }
  /** Array initializer of RSTCTL2 peripheral base pointers */
  #define RSTCTL2_BASE_PTRS                        { RSTCTL2 }
  /** Array initializer of RSTCTL2 peripheral base addresses */
  #define RSTCTL2_BASE_ADDRS_NS                    { RSTCTL2_BASE_NS }
  /** Array initializer of RSTCTL2 peripheral base pointers */
  #define RSTCTL2_BASE_PTRS_NS                     { RSTCTL2_NS }
#else
  /** Peripheral RSTCTL2 base address */
  #define RSTCTL2_BASE                             (0x40067000u)
  /** Peripheral RSTCTL2 base pointer */
  #define RSTCTL2                                  ((RSTCTL2_Type *)RSTCTL2_BASE)
  /** Array initializer of RSTCTL2 peripheral base addresses */
  #define RSTCTL2_BASE_ADDRS                       { RSTCTL2_BASE }
  /** Array initializer of RSTCTL2 peripheral base pointers */
  #define RSTCTL2_BASE_PTRS                        { RSTCTL2 }
#endif

/* RSTCTL3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RSTCTL3 base address */
  #define RSTCTL3_BASE                             (0x50060000u)
  /** Peripheral RSTCTL3 base address */
  #define RSTCTL3_BASE_NS                          (0x40060000u)
  /** Peripheral RSTCTL3 base pointer */
  #define RSTCTL3                                  ((RSTCTL3_Type *)RSTCTL3_BASE)
  /** Peripheral RSTCTL3 base pointer */
  #define RSTCTL3_NS                               ((RSTCTL3_Type *)RSTCTL3_BASE_NS)
  /** Array initializer of RSTCTL3 peripheral base addresses */
  #define RSTCTL3_BASE_ADDRS                       { RSTCTL3_BASE }
  /** Array initializer of RSTCTL3 peripheral base pointers */
  #define RSTCTL3_BASE_PTRS                        { RSTCTL3 }
  /** Array initializer of RSTCTL3 peripheral base addresses */
  #define RSTCTL3_BASE_ADDRS_NS                    { RSTCTL3_BASE_NS }
  /** Array initializer of RSTCTL3 peripheral base pointers */
  #define RSTCTL3_BASE_PTRS_NS                     { RSTCTL3_NS }
#else
  /** Peripheral RSTCTL3 base address */
  #define RSTCTL3_BASE                             (0x40060000u)
  /** Peripheral RSTCTL3 base pointer */
  #define RSTCTL3                                  ((RSTCTL3_Type *)RSTCTL3_BASE)
  /** Array initializer of RSTCTL3 peripheral base addresses */
  #define RSTCTL3_BASE_ADDRS                       { RSTCTL3_BASE }
  /** Array initializer of RSTCTL3 peripheral base pointers */
  #define RSTCTL3_BASE_PTRS                        { RSTCTL3 }
#endif

/* RSTCTL4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RSTCTL4 base address */
  #define RSTCTL4_BASE                             (0x500A0000u)
  /** Peripheral RSTCTL4 base address */
  #define RSTCTL4_BASE_NS                          (0x400A0000u)
  /** Peripheral RSTCTL4 base pointer */
  #define RSTCTL4                                  ((RSTCTL4_Type *)RSTCTL4_BASE)
  /** Peripheral RSTCTL4 base pointer */
  #define RSTCTL4_NS                               ((RSTCTL4_Type *)RSTCTL4_BASE_NS)
  /** Array initializer of RSTCTL4 peripheral base addresses */
  #define RSTCTL4_BASE_ADDRS                       { RSTCTL4_BASE }
  /** Array initializer of RSTCTL4 peripheral base pointers */
  #define RSTCTL4_BASE_PTRS                        { RSTCTL4 }
  /** Array initializer of RSTCTL4 peripheral base addresses */
  #define RSTCTL4_BASE_ADDRS_NS                    { RSTCTL4_BASE_NS }
  /** Array initializer of RSTCTL4 peripheral base pointers */
  #define RSTCTL4_BASE_PTRS_NS                     { RSTCTL4_NS }
#else
  /** Peripheral RSTCTL4 base address */
  #define RSTCTL4_BASE                             (0x400A0000u)
  /** Peripheral RSTCTL4 base pointer */
  #define RSTCTL4                                  ((RSTCTL4_Type *)RSTCTL4_BASE)
  /** Array initializer of RSTCTL4 peripheral base addresses */
  #define RSTCTL4_BASE_ADDRS                       { RSTCTL4_BASE }
  /** Array initializer of RSTCTL4 peripheral base pointers */
  #define RSTCTL4_BASE_PTRS                        { RSTCTL4 }
#endif

/* RTC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RTC1 base address */
  #define RTC1_BASE                                (0x50069000u)
  /** Peripheral RTC1 base address */
  #define RTC1_BASE_NS                             (0x40069000u)
  /** Peripheral RTC1 base pointer */
  #define RTC1                                     ((RTC_Type *)RTC1_BASE)
  /** Peripheral RTC1 base pointer */
  #define RTC1_NS                                  ((RTC_Type *)RTC1_BASE_NS)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { RTC1_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { RTC1 }
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS_NS                        { RTC1_BASE_NS }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS_NS                         { RTC1_NS }
#else
  /** Peripheral RTC1 base address */
  #define RTC1_BASE                                (0x40069000u)
  /** Peripheral RTC1 base pointer */
  #define RTC1                                     ((RTC_Type *)RTC1_BASE)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { RTC1_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { RTC1 }
#endif

/* SCT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SCT0 base address */
  #define SCT0_BASE                                (0x50114000u)
  /** Peripheral SCT0 base address */
  #define SCT0_BASE_NS                             (0x40114000u)
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
  #define SCT0_BASE                                (0x40114000u)
  /** Peripheral SCT0 base pointer */
  #define SCT0                                     ((SCT_Type *)SCT0_BASE)
  /** Array initializer of SCT peripheral base addresses */
  #define SCT_BASE_ADDRS                           { SCT0_BASE }
  /** Array initializer of SCT peripheral base pointers */
  #define SCT_BASE_PTRS                            { SCT0 }
#endif

/* SDADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SDADC base address */
  #define SDADC_BASE                               (0x5020D000u)
  /** Peripheral SDADC base address */
  #define SDADC_BASE_NS                            (0x4020D000u)
  /** Peripheral SDADC base pointer */
  #define SDADC                                    ((SDADC_Type *)SDADC_BASE)
  /** Peripheral SDADC base pointer */
  #define SDADC_NS                                 ((SDADC_Type *)SDADC_BASE_NS)
  /** Array initializer of SDADC peripheral base addresses */
  #define SDADC_BASE_ADDRS                         { SDADC_BASE }
  /** Array initializer of SDADC peripheral base pointers */
  #define SDADC_BASE_PTRS                          { SDADC }
  /** Array initializer of SDADC peripheral base addresses */
  #define SDADC_BASE_ADDRS_NS                      { SDADC_BASE_NS }
  /** Array initializer of SDADC peripheral base pointers */
  #define SDADC_BASE_PTRS_NS                       { SDADC_NS }
#else
  /** Peripheral SDADC base address */
  #define SDADC_BASE                               (0x4020D000u)
  /** Peripheral SDADC base pointer */
  #define SDADC                                    ((SDADC_Type *)SDADC_BASE)
  /** Array initializer of SDADC peripheral base addresses */
  #define SDADC_BASE_ADDRS                         { SDADC_BASE }
  /** Array initializer of SDADC peripheral base pointers */
  #define SDADC_BASE_PTRS                          { SDADC }
#endif

/* SEMA42 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SEMA42_0 base address */
  #define SEMA42_0_BASE                            (0x50206000u)
  /** Peripheral SEMA42_0 base address */
  #define SEMA42_0_BASE_NS                         (0x40206000u)
  /** Peripheral SEMA42_0 base pointer */
  #define SEMA42_0                                 ((SEMA42_Type *)SEMA42_0_BASE)
  /** Peripheral SEMA42_0 base pointer */
  #define SEMA42_0_NS                              ((SEMA42_Type *)SEMA42_0_BASE_NS)
  /** Peripheral SEMA42_3 base address */
  #define SEMA42_3_BASE                            (0x5031B000u)
  /** Peripheral SEMA42_3 base address */
  #define SEMA42_3_BASE_NS                         (0x4031B000u)
  /** Peripheral SEMA42_3 base pointer */
  #define SEMA42_3                                 ((SEMA42_Type *)SEMA42_3_BASE)
  /** Peripheral SEMA42_3 base pointer */
  #define SEMA42_3_NS                              ((SEMA42_Type *)SEMA42_3_BASE_NS)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA42_0_BASE, 0u, 0u, SEMA42_3_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA42_0, (SEMA42_Type *)0u, (SEMA42_Type *)0u, SEMA42_3 }
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS_NS                     { SEMA42_0_BASE_NS, 0u, 0u, SEMA42_3_BASE_NS }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS_NS                      { SEMA42_0_NS, (SEMA42_Type *)0u, (SEMA42_Type *)0u, SEMA42_3_NS }
#else
  /** Peripheral SEMA42_0 base address */
  #define SEMA42_0_BASE                            (0x40206000u)
  /** Peripheral SEMA42_0 base pointer */
  #define SEMA42_0                                 ((SEMA42_Type *)SEMA42_0_BASE)
  /** Peripheral SEMA42_3 base address */
  #define SEMA42_3_BASE                            (0x4031B000u)
  /** Peripheral SEMA42_3 base pointer */
  #define SEMA42_3                                 ((SEMA42_Type *)SEMA42_3_BASE)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA42_0_BASE, 0u, 0u, SEMA42_3_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA42_0, (SEMA42_Type *)0u, (SEMA42_Type *)0u, SEMA42_3 }
#endif

/* SLEEPCON1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SLEEPCON1 base address */
  #define SLEEPCON1_BASE                           (0x50044000u)
  /** Peripheral SLEEPCON1 base address */
  #define SLEEPCON1_BASE_NS                        (0x40044000u)
  /** Peripheral SLEEPCON1 base pointer */
  #define SLEEPCON1                                ((SLEEPCON1_Type *)SLEEPCON1_BASE)
  /** Peripheral SLEEPCON1 base pointer */
  #define SLEEPCON1_NS                             ((SLEEPCON1_Type *)SLEEPCON1_BASE_NS)
  /** Array initializer of SLEEPCON1 peripheral base addresses */
  #define SLEEPCON1_BASE_ADDRS                     { SLEEPCON1_BASE }
  /** Array initializer of SLEEPCON1 peripheral base pointers */
  #define SLEEPCON1_BASE_PTRS                      { SLEEPCON1 }
  /** Array initializer of SLEEPCON1 peripheral base addresses */
  #define SLEEPCON1_BASE_ADDRS_NS                  { SLEEPCON1_BASE_NS }
  /** Array initializer of SLEEPCON1 peripheral base pointers */
  #define SLEEPCON1_BASE_PTRS_NS                   { SLEEPCON1_NS }
#else
  /** Peripheral SLEEPCON1 base address */
  #define SLEEPCON1_BASE                           (0x40044000u)
  /** Peripheral SLEEPCON1 base pointer */
  #define SLEEPCON1                                ((SLEEPCON1_Type *)SLEEPCON1_BASE)
  /** Array initializer of SLEEPCON1 peripheral base addresses */
  #define SLEEPCON1_BASE_ADDRS                     { SLEEPCON1_BASE }
  /** Array initializer of SLEEPCON1 peripheral base pointers */
  #define SLEEPCON1_BASE_PTRS                      { SLEEPCON1 }
#endif

/* SYSCON1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON1 base address */
  #define SYSCON1_BASE                             (0x50042000u)
  /** Peripheral SYSCON1 base address */
  #define SYSCON1_BASE_NS                          (0x40042000u)
  /** Peripheral SYSCON1 base pointer */
  #define SYSCON1                                  ((SYSCON1_Type *)SYSCON1_BASE)
  /** Peripheral SYSCON1 base pointer */
  #define SYSCON1_NS                               ((SYSCON1_Type *)SYSCON1_BASE_NS)
  /** Array initializer of SYSCON1 peripheral base addresses */
  #define SYSCON1_BASE_ADDRS                       { SYSCON1_BASE }
  /** Array initializer of SYSCON1 peripheral base pointers */
  #define SYSCON1_BASE_PTRS                        { SYSCON1 }
  /** Array initializer of SYSCON1 peripheral base addresses */
  #define SYSCON1_BASE_ADDRS_NS                    { SYSCON1_BASE_NS }
  /** Array initializer of SYSCON1 peripheral base pointers */
  #define SYSCON1_BASE_PTRS_NS                     { SYSCON1_NS }
#else
  /** Peripheral SYSCON1 base address */
  #define SYSCON1_BASE                             (0x40042000u)
  /** Peripheral SYSCON1 base pointer */
  #define SYSCON1                                  ((SYSCON1_Type *)SYSCON1_BASE)
  /** Array initializer of SYSCON1 peripheral base addresses */
  #define SYSCON1_BASE_ADDRS                       { SYSCON1_BASE }
  /** Array initializer of SYSCON1 peripheral base pointers */
  #define SYSCON1_BASE_PTRS                        { SYSCON1 }
#endif

/* SYSCON2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON2 base address */
  #define SYSCON2_BASE                             (0x50066000u)
  /** Peripheral SYSCON2 base address */
  #define SYSCON2_BASE_NS                          (0x40066000u)
  /** Peripheral SYSCON2 base pointer */
  #define SYSCON2                                  ((SYSCON2_Type *)SYSCON2_BASE)
  /** Peripheral SYSCON2 base pointer */
  #define SYSCON2_NS                               ((SYSCON2_Type *)SYSCON2_BASE_NS)
  /** Array initializer of SYSCON2 peripheral base addresses */
  #define SYSCON2_BASE_ADDRS                       { SYSCON2_BASE }
  /** Array initializer of SYSCON2 peripheral base pointers */
  #define SYSCON2_BASE_PTRS                        { SYSCON2 }
  /** Array initializer of SYSCON2 peripheral base addresses */
  #define SYSCON2_BASE_ADDRS_NS                    { SYSCON2_BASE_NS }
  /** Array initializer of SYSCON2 peripheral base pointers */
  #define SYSCON2_BASE_PTRS_NS                     { SYSCON2_NS }
#else
  /** Peripheral SYSCON2 base address */
  #define SYSCON2_BASE                             (0x40066000u)
  /** Peripheral SYSCON2 base pointer */
  #define SYSCON2                                  ((SYSCON2_Type *)SYSCON2_BASE)
  /** Array initializer of SYSCON2 peripheral base addresses */
  #define SYSCON2_BASE_ADDRS                       { SYSCON2_BASE }
  /** Array initializer of SYSCON2 peripheral base pointers */
  #define SYSCON2_BASE_PTRS                        { SYSCON2 }
#endif

/* SYSCON3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON3 base address */
  #define SYSCON3_BASE                             (0x50062000u)
  /** Peripheral SYSCON3 base address */
  #define SYSCON3_BASE_NS                          (0x40062000u)
  /** Peripheral SYSCON3 base pointer */
  #define SYSCON3                                  ((SYSCON3_Type *)SYSCON3_BASE)
  /** Peripheral SYSCON3 base pointer */
  #define SYSCON3_NS                               ((SYSCON3_Type *)SYSCON3_BASE_NS)
  /** Array initializer of SYSCON3 peripheral base addresses */
  #define SYSCON3_BASE_ADDRS                       { SYSCON3_BASE }
  /** Array initializer of SYSCON3 peripheral base pointers */
  #define SYSCON3_BASE_PTRS                        { SYSCON3 }
  /** Array initializer of SYSCON3 peripheral base addresses */
  #define SYSCON3_BASE_ADDRS_NS                    { SYSCON3_BASE_NS }
  /** Array initializer of SYSCON3 peripheral base pointers */
  #define SYSCON3_BASE_PTRS_NS                     { SYSCON3_NS }
#else
  /** Peripheral SYSCON3 base address */
  #define SYSCON3_BASE                             (0x40062000u)
  /** Peripheral SYSCON3 base pointer */
  #define SYSCON3                                  ((SYSCON3_Type *)SYSCON3_BASE)
  /** Array initializer of SYSCON3 peripheral base addresses */
  #define SYSCON3_BASE_ADDRS                       { SYSCON3_BASE }
  /** Array initializer of SYSCON3 peripheral base pointers */
  #define SYSCON3_BASE_PTRS                        { SYSCON3 }
#endif

/* SYSCON4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON4 base address */
  #define SYSCON4_BASE                             (0x500A2000u)
  /** Peripheral SYSCON4 base address */
  #define SYSCON4_BASE_NS                          (0x400A2000u)
  /** Peripheral SYSCON4 base pointer */
  #define SYSCON4                                  ((SYSCON4_Type *)SYSCON4_BASE)
  /** Peripheral SYSCON4 base pointer */
  #define SYSCON4_NS                               ((SYSCON4_Type *)SYSCON4_BASE_NS)
  /** Array initializer of SYSCON4 peripheral base addresses */
  #define SYSCON4_BASE_ADDRS                       { SYSCON4_BASE }
  /** Array initializer of SYSCON4 peripheral base pointers */
  #define SYSCON4_BASE_PTRS                        { SYSCON4 }
  /** Array initializer of SYSCON4 peripheral base addresses */
  #define SYSCON4_BASE_ADDRS_NS                    { SYSCON4_BASE_NS }
  /** Array initializer of SYSCON4 peripheral base pointers */
  #define SYSCON4_BASE_PTRS_NS                     { SYSCON4_NS }
#else
  /** Peripheral SYSCON4 base address */
  #define SYSCON4_BASE                             (0x400A2000u)
  /** Peripheral SYSCON4 base pointer */
  #define SYSCON4                                  ((SYSCON4_Type *)SYSCON4_BASE)
  /** Array initializer of SYSCON4 peripheral base addresses */
  #define SYSCON4_BASE_ADDRS                       { SYSCON4_BASE }
  /** Array initializer of SYSCON4 peripheral base pointers */
  #define SYSCON4_BASE_PTRS                        { SYSCON4 }
#endif

/* USB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USB0 base address */
  #define USB0_BASE                                (0x50418000u)
  /** Peripheral USB0 base address */
  #define USB0_BASE_NS                             (0x40418000u)
  /** Peripheral USB0 base pointer */
  #define USB0                                     ((USB_Type *)USB0_BASE)
  /** Peripheral USB0 base pointer */
  #define USB0_NS                                  ((USB_Type *)USB0_BASE_NS)
  /** Peripheral USB1 base address */
  #define USB1_BASE                                (0x50419000u)
  /** Peripheral USB1 base address */
  #define USB1_BASE_NS                             (0x40419000u)
  /** Peripheral USB1 base pointer */
  #define USB1                                     ((USB_Type *)USB1_BASE)
  /** Peripheral USB1 base pointer */
  #define USB1_NS                                  ((USB_Type *)USB1_BASE_NS)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { USB0_BASE, USB1_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { USB0, USB1 }
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS_NS                        { USB0_BASE_NS, USB1_BASE_NS }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS_NS                         { USB0_NS, USB1_NS }
#else
  /** Peripheral USB0 base address */
  #define USB0_BASE                                (0x40418000u)
  /** Peripheral USB0 base pointer */
  #define USB0                                     ((USB_Type *)USB0_BASE)
  /** Peripheral USB1 base address */
  #define USB1_BASE                                (0x40419000u)
  /** Peripheral USB1 base pointer */
  #define USB1                                     ((USB_Type *)USB1_BASE)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { USB0_BASE, USB1_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { USB0, USB1 }
#endif
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { USB0_IRQn, USB1_IRQn }
/* Backward compatibility */
#define GPTIMER0CTL                              GPTIMER0CTRL
#define GPTIMER1CTL                              GPTIMER1CTRL
#define USB_SBUSCFG                              SBUSCFG
#define EPLISTADDR                               ENDPTLISTADDR
#define EPSETUPSR                                ENDPTSETUPSTAT
#define EPPRIME                                  ENDPTPRIME
#define EPFLUSH                                  ENDPTFLUSH
#define EPSR                                     ENDPTSTAT
#define EPCOMPLETE                               ENDPTCOMPLETE
#define EPCR                                     ENDPTCTRL
#define EPCR0                                    ENDPTCTRL0
#define USBHS_ID_ID_MASK                         USB_ID_ID_MASK
#define USBHS_ID_ID_SHIFT                        USB_ID_ID_SHIFT
#define USBHS_ID_ID(x)                           USB_ID_ID(x)
#define USBHS_ID_NID_MASK                        USB_ID_NID_MASK
#define USBHS_ID_NID_SHIFT                       USB_ID_NID_SHIFT
#define USBHS_ID_NID(x)                          USB_ID_NID(x)
#define USBHS_ID_REVISION_MASK                   USB_ID_REVISION_MASK
#define USBHS_ID_REVISION_SHIFT                  USB_ID_REVISION_SHIFT
#define USBHS_ID_REVISION(x)                     USB_ID_REVISION(x)
#define USBHS_HWGENERAL_PHYW_MASK                USB_HWGENERAL_PHYW_MASK
#define USBHS_HWGENERAL_PHYW_SHIFT               USB_HWGENERAL_PHYW_SHIFT
#define USBHS_HWGENERAL_PHYW(x)                  USB_HWGENERAL_PHYW(x)
#define USBHS_HWGENERAL_PHYM_MASK                USB_HWGENERAL_PHYM_MASK
#define USBHS_HWGENERAL_PHYM_SHIFT               USB_HWGENERAL_PHYM_SHIFT
#define USBHS_HWGENERAL_PHYM(x)                  USB_HWGENERAL_PHYM(x)
#define USBHS_HWGENERAL_SM_MASK                  USB_HWGENERAL_SM_MASK
#define USBHS_HWGENERAL_SM_SHIFT                 USB_HWGENERAL_SM_SHIFT
#define USBHS_HWGENERAL_SM(x)                    USB_HWGENERAL_SM(x)
#define USBHS_HWHOST_HC_MASK                     USB_HWHOST_HC_MASK
#define USBHS_HWHOST_HC_SHIFT                    USB_HWHOST_HC_SHIFT
#define USBHS_HWHOST_HC(x)                       USB_HWHOST_HC(x)
#define USBHS_HWHOST_NPORT_MASK                  USB_HWHOST_NPORT_MASK
#define USBHS_HWHOST_NPORT_SHIFT                 USB_HWHOST_NPORT_SHIFT
#define USBHS_HWHOST_NPORT(x)                    USB_HWHOST_NPORT(x)
#define USBHS_HWDEVICE_DC_MASK                   USB_HWDEVICE_DC_MASK
#define USBHS_HWDEVICE_DC_SHIFT                  USB_HWDEVICE_DC_SHIFT
#define USBHS_HWDEVICE_DC(x)                     USB_HWDEVICE_DC(x)
#define USBHS_HWDEVICE_DEVEP_MASK                USB_HWDEVICE_DEVEP_MASK
#define USBHS_HWDEVICE_DEVEP_SHIFT               USB_HWDEVICE_DEVEP_SHIFT
#define USBHS_HWDEVICE_DEVEP(x)                  USB_HWDEVICE_DEVEP(x)
#define USBHS_HWTXBUF_TXBURST_MASK               USB_HWTXBUF_TXBURST_MASK
#define USBHS_HWTXBUF_TXBURST_SHIFT              USB_HWTXBUF_TXBURST_SHIFT
#define USBHS_HWTXBUF_TXBURST(x)                 USB_HWTXBUF_TXBURST(x)
#define USBHS_HWTXBUF_TXCHANADD_MASK             USB_HWTXBUF_TXCHANADD_MASK
#define USBHS_HWTXBUF_TXCHANADD_SHIFT            USB_HWTXBUF_TXCHANADD_SHIFT
#define USBHS_HWTXBUF_TXCHANADD(x)               USB_HWTXBUF_TXCHANADD(x)
#define USBHS_HWRXBUF_RXBURST_MASK               USB_HWRXBUF_RXBURST_MASK
#define USBHS_HWRXBUF_RXBURST_SHIFT              USB_HWRXBUF_RXBURST_SHIFT
#define USBHS_HWRXBUF_RXBURST(x)                 USB_HWRXBUF_RXBURST(x)
#define USBHS_HWRXBUF_RXADD_MASK                 USB_HWRXBUF_RXADD_MASK
#define USBHS_HWRXBUF_RXADD_SHIFT                USB_HWRXBUF_RXADD_SHIFT
#define USBHS_HWRXBUF_RXADD(x)                   USB_HWRXBUF_RXADD(x)
#define USBHS_GPTIMER0LD_GPTLD_MASK              USB_GPTIMER0LD_GPTLD_MASK
#define USBHS_GPTIMER0LD_GPTLD_SHIFT             USB_GPTIMER0LD_GPTLD_SHIFT
#define USBHS_GPTIMER0LD_GPTLD(x)                USB_GPTIMER0LD_GPTLD(x)
#define USBHS_GPTIMER0CTL_GPTCNT_MASK            USB_GPTIMER0CTRL_GPTCNT_MASK
#define USBHS_GPTIMER0CTL_GPTCNT_SHIFT           USB_GPTIMER0CTRL_GPTCNT_SHIFT
#define USBHS_GPTIMER0CTL_GPTCNT(x)              USB_GPTIMER0CTRL_GPTCNT(x)
#define USBHS_GPTIMER0CTL_MODE_MASK              USB_GPTIMER0CTRL_GPTMODE_MASK
#define USBHS_GPTIMER0CTL_MODE_SHIFT             USB_GPTIMER0CTRL_GPTMODE_SHIFT
#define USBHS_GPTIMER0CTL_MODE(x)                USB_GPTIMER0CTRL_GPTMODE(x)
#define USBHS_GPTIMER0CTL_RST_MASK               USB_GPTIMER0CTRL_GPTRST_MASK
#define USBHS_GPTIMER0CTL_RST_SHIFT              USB_GPTIMER0CTRL_GPTRST_SHIFT
#define USBHS_GPTIMER0CTL_RST(x)                 USB_GPTIMER0CTRL_GPTRST(x)
#define USBHS_GPTIMER0CTL_RUN_MASK               USB_GPTIMER0CTRL_GPTRUN_MASK
#define USBHS_GPTIMER0CTL_RUN_SHIFT              USB_GPTIMER0CTRL_GPTRUN_SHIFT
#define USBHS_GPTIMER0CTL_RUN(x)                 USB_GPTIMER0CTRL_GPTRUN(x)
#define USBHS_GPTIMER1LD_GPTLD_MASK              USB_GPTIMER1LD_GPTLD_MASK
#define USBHS_GPTIMER1LD_GPTLD_SHIFT             USB_GPTIMER1LD_GPTLD_SHIFT
#define USBHS_GPTIMER1LD_GPTLD(x)                USB_GPTIMER1LD_GPTLD(x)
#define USBHS_GPTIMER1CTL_GPTCNT_MASK            USB_GPTIMER1CTRL_GPTCNT_MASK
#define USBHS_GPTIMER1CTL_GPTCNT_SHIFT           USB_GPTIMER1CTRL_GPTCNT_SHIFT
#define USBHS_GPTIMER1CTL_GPTCNT(x)              USB_GPTIMER1CTRL_GPTCNT(x)
#define USBHS_GPTIMER1CTL_MODE_MASK              USB_GPTIMER1CTRL_GPTMODE_MASK
#define USBHS_GPTIMER1CTL_MODE_SHIFT             USB_GPTIMER1CTRL_GPTMODE_SHIFT
#define USBHS_GPTIMER1CTL_MODE(x)                USB_GPTIMER1CTRL_GPTMODE(x)
#define USBHS_GPTIMER1CTL_RST_MASK               USB_GPTIMER1CTRL_GPTRST_MASK
#define USBHS_GPTIMER1CTL_RST_SHIFT              USB_GPTIMER1CTRL_GPTRST_SHIFT
#define USBHS_GPTIMER1CTL_RST(x)                 USB_GPTIMER1CTRL_GPTRST(x)
#define USBHS_GPTIMER1CTL_RUN_MASK               USB_GPTIMER1CTRL_GPTRUN_MASK
#define USBHS_GPTIMER1CTL_RUN_SHIFT              USB_GPTIMER1CTRL_GPTRUN_SHIFT
#define USBHS_GPTIMER1CTL_RUN(x)                 USB_GPTIMER1CTRL_GPTRUN(x)
#define USBHS_USB_SBUSCFG_BURSTMODE_MASK         USB_SBUSCFG_AHBBRST_MASK
#define USBHS_USB_SBUSCFG_BURSTMODE_SHIFT        USB_SBUSCFG_AHBBRST_SHIFT
#define USBHS_USB_SBUSCFG_BURSTMODE(x)           USB_SBUSCFG_AHBBRST(x)
#define USBHS_HCIVERSION_CAPLENGTH(x)            USB_HCIVERSION_CAPLENGTH(x)
#define USBHS_HCIVERSION_HCIVERSION_MASK         USB_HCIVERSION_HCIVERSION_MASK
#define USBHS_HCIVERSION_HCIVERSION_SHIFT        USB_HCIVERSION_HCIVERSION_SHIFT
#define USBHS_HCIVERSION_HCIVERSION(x)           USB_HCIVERSION_HCIVERSION(x)
#define USBHS_HCSPARAMS_N_PORTS_MASK             USB_HCSPARAMS_N_PORTS_MASK
#define USBHS_HCSPARAMS_N_PORTS_SHIFT            USB_HCSPARAMS_N_PORTS_SHIFT
#define USBHS_HCSPARAMS_N_PORTS(x)               USB_HCSPARAMS_N_PORTS(x)
#define USBHS_HCSPARAMS_PPC_MASK                 USB_HCSPARAMS_PPC_MASK
#define USBHS_HCSPARAMS_PPC_SHIFT                USB_HCSPARAMS_PPC_SHIFT
#define USBHS_HCSPARAMS_PPC(x)                   USB_HCSPARAMS_PPC(x)
#define USBHS_HCSPARAMS_N_PCC_MASK               USB_HCSPARAMS_N_PCC_MASK
#define USBHS_HCSPARAMS_N_PCC_SHIFT              USB_HCSPARAMS_N_PCC_SHIFT
#define USBHS_HCSPARAMS_N_PCC(x)                 USB_HCSPARAMS_N_PCC(x)
#define USBHS_HCSPARAMS_N_CC_MASK                USB_HCSPARAMS_N_CC_MASK
#define USBHS_HCSPARAMS_N_CC_SHIFT               USB_HCSPARAMS_N_CC_SHIFT
#define USBHS_HCSPARAMS_N_CC(x)                  USB_HCSPARAMS_N_CC(x)
#define USBHS_HCSPARAMS_PI_MASK                  USB_HCSPARAMS_PI_MASK
#define USBHS_HCSPARAMS_PI_SHIFT                 USB_HCSPARAMS_PI_SHIFT
#define USBHS_HCSPARAMS_PI(x)                    USB_HCSPARAMS_PI(x)
#define USBHS_HCSPARAMS_N_PTT_MASK               USB_HCSPARAMS_N_PTT_MASK
#define USBHS_HCSPARAMS_N_PTT_SHIFT              USB_HCSPARAMS_N_PTT_SHIFT
#define USBHS_HCSPARAMS_N_PTT(x)                 USB_HCSPARAMS_N_PTT(x)
#define USBHS_HCSPARAMS_N_TT_MASK                USB_HCSPARAMS_N_TT_MASK
#define USBHS_HCSPARAMS_N_TT_SHIFT               USB_HCSPARAMS_N_TT_SHIFT
#define USBHS_HCSPARAMS_N_TT(x)                  USB_HCSPARAMS_N_TT(x)
#define USBHS_HCCPARAMS_ADC_MASK                 USB_HCCPARAMS_ADC_MASK
#define USBHS_HCCPARAMS_ADC_SHIFT                USB_HCCPARAMS_ADC_SHIFT
#define USBHS_HCCPARAMS_ADC(x)                   USB_HCCPARAMS_ADC(x)
#define USBHS_HCCPARAMS_PFL_MASK                 USB_HCCPARAMS_PFL_MASK
#define USBHS_HCCPARAMS_PFL_SHIFT                USB_HCCPARAMS_PFL_SHIFT
#define USBHS_HCCPARAMS_PFL(x)                   USB_HCCPARAMS_PFL(x)
#define USBHS_HCCPARAMS_ASP_MASK                 USB_HCCPARAMS_ASP_MASK
#define USBHS_HCCPARAMS_ASP_SHIFT                USB_HCCPARAMS_ASP_SHIFT
#define USBHS_HCCPARAMS_ASP(x)                   USB_HCCPARAMS_ASP(x)
#define USBHS_HCCPARAMS_IST_MASK                 USB_HCCPARAMS_IST_MASK
#define USBHS_HCCPARAMS_IST_SHIFT                USB_HCCPARAMS_IST_SHIFT
#define USBHS_HCCPARAMS_IST(x)                   USB_HCCPARAMS_IST(x)
#define USBHS_HCCPARAMS_EECP_MASK                USB_HCCPARAMS_EECP_MASK
#define USBHS_HCCPARAMS_EECP_SHIFT               USB_HCCPARAMS_EECP_SHIFT
#define USBHS_HCCPARAMS_EECP(x)                  USB_HCCPARAMS_EECP(x)
#define USBHS_DCIVERSION_DCIVERSION_MASK         USB_DCIVERSION_DCIVERSION_MASK
#define USBHS_DCIVERSION_DCIVERSION_SHIFT        USB_DCIVERSION_DCIVERSION_SHIFT
#define USBHS_DCIVERSION_DCIVERSION(x)           USB_DCIVERSION_DCIVERSION(x)
#define USBHS_DCCPARAMS_DEN_MASK                 USB_DCCPARAMS_DEN_MASK
#define USBHS_DCCPARAMS_DEN_SHIFT                USB_DCCPARAMS_DEN_SHIFT
#define USBHS_DCCPARAMS_DEN(x)                   USB_DCCPARAMS_DEN(x)
#define USBHS_DCCPARAMS_DC_MASK                  USB_DCCPARAMS_DC_MASK
#define USBHS_DCCPARAMS_DC_SHIFT                 USB_DCCPARAMS_DC_SHIFT
#define USBHS_DCCPARAMS_DC(x)                    USB_DCCPARAMS_DC(x)
#define USBHS_DCCPARAMS_HC_MASK                  USB_DCCPARAMS_HC_MASK
#define USBHS_DCCPARAMS_HC_SHIFT                 USB_DCCPARAMS_HC_SHIFT
#define USBHS_DCCPARAMS_HC(x)                    USB_DCCPARAMS_HC(x)
#define USBHS_USBCMD_RS_MASK                     USB_USBCMD_RS_MASK
#define USBHS_USBCMD_RS_SHIFT                    USB_USBCMD_RS_SHIFT
#define USBHS_USBCMD_RS(x)                       USB_USBCMD_RS(x)
#define USBHS_USBCMD_RST_MASK                    USB_USBCMD_RST_MASK
#define USBHS_USBCMD_RST_SHIFT                   USB_USBCMD_RST_SHIFT
#define USBHS_USBCMD_RST(x)                      USB_USBCMD_RST(x)
#define USBHS_USBCMD_FS_MASK                     USB_USBCMD_FS_1_MASK
#define USBHS_USBCMD_FS_SHIFT                    USB_USBCMD_FS_1_SHIFT
#define USBHS_USBCMD_FS(x)                       USB_USBCMD_FS_1(x)
#define USBHS_USBCMD_PSE_MASK                    USB_USBCMD_PSE_MASK
#define USBHS_USBCMD_PSE_SHIFT                   USB_USBCMD_PSE_SHIFT
#define USBHS_USBCMD_PSE(x)                      USB_USBCMD_PSE(x)
#define USBHS_USBCMD_ASE_MASK                    USB_USBCMD_ASE_MASK
#define USBHS_USBCMD_ASE_SHIFT                   USB_USBCMD_ASE_SHIFT
#define USBHS_USBCMD_ASE(x)                      USB_USBCMD_ASE(x)
#define USBHS_USBCMD_IAA_MASK                    USB_USBCMD_IAA_MASK
#define USBHS_USBCMD_IAA_SHIFT                   USB_USBCMD_IAA_SHIFT
#define USBHS_USBCMD_IAA(x)                      USB_USBCMD_IAA(x)
#define USBHS_USBCMD_ASP_MASK                    USB_USBCMD_ASP_MASK
#define USBHS_USBCMD_ASP_SHIFT                   USB_USBCMD_ASP_SHIFT
#define USBHS_USBCMD_ASP(x)                      USB_USBCMD_ASP(x)
#define USBHS_USBCMD_ASPE_MASK                   USB_USBCMD_ASPE_MASK
#define USBHS_USBCMD_ASPE_SHIFT                  USB_USBCMD_ASPE_SHIFT
#define USBHS_USBCMD_ASPE(x)                     USB_USBCMD_ASPE(x)
#define USBHS_USBCMD_ATDTW_MASK                  USB_USBCMD_ATDTW_MASK
#define USBHS_USBCMD_ATDTW_SHIFT                 USB_USBCMD_ATDTW_SHIFT
#define USBHS_USBCMD_ATDTW(x)                    USB_USBCMD_ATDTW(x)
#define USBHS_USBCMD_SUTW_MASK                   USB_USBCMD_SUTW_MASK
#define USBHS_USBCMD_SUTW_SHIFT                  USB_USBCMD_SUTW_SHIFT
#define USBHS_USBCMD_SUTW(x)                     USB_USBCMD_SUTW(x)
#define USBHS_USBCMD_FS2_MASK                    USB_USBCMD_FS_2_MASK
#define USBHS_USBCMD_FS2_SHIFT                   USB_USBCMD_FS_2_SHIFT
#define USBHS_USBCMD_FS2(x)                      USB_USBCMD_FS_2(x)
#define USBHS_USBCMD_ITC_MASK                    USB_USBCMD_ITC_MASK
#define USBHS_USBCMD_ITC_SHIFT                   USB_USBCMD_ITC_SHIFT
#define USBHS_USBCMD_ITC(x)                      USB_USBCMD_ITC(x)
#define USBHS_USBSTS_UI_MASK                     USB_USBSTS_UI_MASK
#define USBHS_USBSTS_UI_SHIFT                    USB_USBSTS_UI_SHIFT
#define USBHS_USBSTS_UI(x)                       USB_USBSTS_UI(x)
#define USBHS_USBSTS_UEI_MASK                    USB_USBSTS_UEI_MASK
#define USBHS_USBSTS_UEI_SHIFT                   USB_USBSTS_UEI_SHIFT
#define USBHS_USBSTS_UEI(x)                      USB_USBSTS_UEI(x)
#define USBHS_USBSTS_PCI_MASK                    USB_USBSTS_PCI_MASK
#define USBHS_USBSTS_PCI_SHIFT                   USB_USBSTS_PCI_SHIFT
#define USBHS_USBSTS_PCI(x)                      USB_USBSTS_PCI(x)
#define USBHS_USBSTS_FRI_MASK                    USB_USBSTS_FRI_MASK
#define USBHS_USBSTS_FRI_SHIFT                   USB_USBSTS_FRI_SHIFT
#define USBHS_USBSTS_FRI(x)                      USB_USBSTS_FRI(x)
#define USBHS_USBSTS_SEI_MASK                    USB_USBSTS_SEI_MASK
#define USBHS_USBSTS_SEI_SHIFT                   USB_USBSTS_SEI_SHIFT
#define USBHS_USBSTS_SEI(x)                      USB_USBSTS_SEI(x)
#define USBHS_USBSTS_AAI_MASK                    USB_USBSTS_AAI_MASK
#define USBHS_USBSTS_AAI_SHIFT                   USB_USBSTS_AAI_SHIFT
#define USBHS_USBSTS_AAI(x)                      USB_USBSTS_AAI(x)
#define USBHS_USBSTS_URI_MASK                    USB_USBSTS_URI_MASK
#define USBHS_USBSTS_URI_SHIFT                   USB_USBSTS_URI_SHIFT
#define USBHS_USBSTS_URI(x)                      USB_USBSTS_URI(x)
#define USBHS_USBSTS_SRI_MASK                    USB_USBSTS_SRI_MASK
#define USBHS_USBSTS_SRI_SHIFT                   USB_USBSTS_SRI_SHIFT
#define USBHS_USBSTS_SRI(x)                      USB_USBSTS_SRI(x)
#define USBHS_USBSTS_SLI_MASK                    USB_USBSTS_SLI_MASK
#define USBHS_USBSTS_SLI_SHIFT                   USB_USBSTS_SLI_SHIFT
#define USBHS_USBSTS_SLI(x)                      USB_USBSTS_SLI(x)
#define USBHS_USBSTS_ULPII_MASK                  USB_USBSTS_ULPII_MASK
#define USBHS_USBSTS_ULPII_SHIFT                 USB_USBSTS_ULPII_SHIFT
#define USBHS_USBSTS_ULPII(x)                    USB_USBSTS_ULPII(x)
#define USBHS_USBSTS_HCH_MASK                    USB_USBSTS_HCH_MASK
#define USBHS_USBSTS_HCH_SHIFT                   USB_USBSTS_HCH_SHIFT
#define USBHS_USBSTS_HCH(x)                      USB_USBSTS_HCH(x)
#define USBHS_USBSTS_RCL_MASK                    USB_USBSTS_RCL_MASK
#define USBHS_USBSTS_RCL_SHIFT                   USB_USBSTS_RCL_SHIFT
#define USBHS_USBSTS_RCL(x)                      USB_USBSTS_RCL(x)
#define USBHS_USBSTS_PS_MASK                     USB_USBSTS_PS_MASK
#define USBHS_USBSTS_PS_SHIFT                    USB_USBSTS_PS_SHIFT
#define USBHS_USBSTS_PS(x)                       USB_USBSTS_PS(x)
#define USBHS_USBSTS_AS_MASK                     USB_USBSTS_AS_MASK
#define USBHS_USBSTS_AS_SHIFT                    USB_USBSTS_AS_SHIFT
#define USBHS_USBSTS_AS(x)                       USB_USBSTS_AS(x)
#define USBHS_USBSTS_NAKI_MASK                   USB_USBSTS_NAKI_MASK
#define USBHS_USBSTS_NAKI_SHIFT                  USB_USBSTS_NAKI_SHIFT
#define USBHS_USBSTS_NAKI(x)                     USB_USBSTS_NAKI(x)
#define USBHS_USBSTS_TI0_MASK                    USB_USBSTS_TI0_MASK
#define USBHS_USBSTS_TI0_SHIFT                   USB_USBSTS_TI0_SHIFT
#define USBHS_USBSTS_TI0(x)                      USB_USBSTS_TI0(x)
#define USBHS_USBSTS_TI1_MASK                    USB_USBSTS_TI1_MASK
#define USBHS_USBSTS_TI1_SHIFT                   USB_USBSTS_TI1_SHIFT
#define USBHS_USBSTS_TI1(x)                      USB_USBSTS_TI1(x)
#define USBHS_USBINTR_UE_MASK                    USB_USBINTR_UE_MASK
#define USBHS_USBINTR_UE_SHIFT                   USB_USBINTR_UE_SHIFT
#define USBHS_USBINTR_UE(x)                      USB_USBINTR_UE(x)
#define USBHS_USBINTR_UEE_MASK                   USB_USBINTR_UEE_MASK
#define USBHS_USBINTR_UEE_SHIFT                  USB_USBINTR_UEE_SHIFT
#define USBHS_USBINTR_UEE(x)                     USB_USBINTR_UEE(x)
#define USBHS_USBINTR_PCE_MASK                   USB_USBINTR_PCE_MASK
#define USBHS_USBINTR_PCE_SHIFT                  USB_USBINTR_PCE_SHIFT
#define USBHS_USBINTR_PCE(x)                     USB_USBINTR_PCE(x)
#define USBHS_USBINTR_FRE_MASK                   USB_USBINTR_FRE_MASK
#define USBHS_USBINTR_FRE_SHIFT                  USB_USBINTR_FRE_SHIFT
#define USBHS_USBINTR_FRE(x)                     USB_USBINTR_FRE(x)
#define USBHS_USBINTR_SEE_MASK                   USB_USBINTR_SEE_MASK
#define USBHS_USBINTR_SEE_SHIFT                  USB_USBINTR_SEE_SHIFT
#define USBHS_USBINTR_SEE(x)                     USB_USBINTR_SEE(x)
#define USBHS_USBINTR_AAE_MASK                   USB_USBINTR_AAE_MASK
#define USBHS_USBINTR_AAE_SHIFT                  USB_USBINTR_AAE_SHIFT
#define USBHS_USBINTR_AAE(x)                     USB_USBINTR_AAE(x)
#define USBHS_USBINTR_URE_MASK                   USB_USBINTR_URE_MASK
#define USBHS_USBINTR_URE_SHIFT                  USB_USBINTR_URE_SHIFT
#define USBHS_USBINTR_URE(x)                     USB_USBINTR_URE(x)
#define USBHS_USBINTR_SRE_MASK                   USB_USBINTR_SRE_MASK
#define USBHS_USBINTR_SRE_SHIFT                  USB_USBINTR_SRE_SHIFT
#define USBHS_USBINTR_SRE(x)                     USB_USBINTR_SRE(x)
#define USBHS_USBINTR_SLE_MASK                   USB_USBINTR_SLE_MASK
#define USBHS_USBINTR_SLE_SHIFT                  USB_USBINTR_SLE_SHIFT
#define USBHS_USBINTR_SLE(x)                     USB_USBINTR_SLE(x)
#define USBHS_USBINTR_ULPIE_MASK                 USB_USBINTR_ULPIE_MASK
#define USBHS_USBINTR_ULPIE_SHIFT                USB_USBINTR_ULPIE_SHIFT
#define USBHS_USBINTR_ULPIE(x)                   USB_USBINTR_ULPIE(x)
#define USBHS_USBINTR_NAKE_MASK                  USB_USBINTR_NAKE_MASK
#define USBHS_USBINTR_NAKE_SHIFT                 USB_USBINTR_NAKE_SHIFT
#define USBHS_USBINTR_NAKE(x)                    USB_USBINTR_NAKE(x)
#define USBHS_USBINTR_UAIE_MASK                  USB_USBINTR_UAIE_MASK
#define USBHS_USBINTR_UAIE_SHIFT                 USB_USBINTR_UAIE_SHIFT
#define USBHS_USBINTR_UAIE(x)                    USB_USBINTR_UAIE(x)
#define USBHS_USBINTR_UPIE_MASK                  USB_USBINTR_UPIE_MASK
#define USBHS_USBINTR_UPIE_SHIFT                 USB_USBINTR_UPIE_SHIFT
#define USBHS_USBINTR_UPIE(x)                    USB_USBINTR_UPIE(x)
#define USBHS_USBINTR_TIE0_MASK                  USB_USBINTR_TIE0_MASK
#define USBHS_USBINTR_TIE0_SHIFT                 USB_USBINTR_TIE0_SHIFT
#define USBHS_USBINTR_TIE0(x)                    USB_USBINTR_TIE0(x)
#define USBHS_USBINTR_TIE1_MASK                  USB_USBINTR_TIE1_MASK
#define USBHS_USBINTR_TIE1_SHIFT                 USB_USBINTR_TIE1_SHIFT
#define USBHS_USBINTR_TIE1(x)                    USB_USBINTR_TIE1(x)
#define USBHS_FRINDEX_FRINDEX_MASK               USB_FRINDEX_FRINDEX_MASK
#define USBHS_FRINDEX_FRINDEX_SHIFT              USB_FRINDEX_FRINDEX_SHIFT
#define USBHS_FRINDEX_FRINDEX(x)                 USB_FRINDEX_FRINDEX(x)
#define USBHS_DEVICEADDR_USBADRA_MASK            USB_DEVICEADDR_USBADRA_MASK
#define USBHS_DEVICEADDR_USBADRA_SHIFT           USB_DEVICEADDR_USBADRA_SHIFT
#define USBHS_DEVICEADDR_USBADRA(x)              USB_DEVICEADDR_USBADRA(x)
#define USBHS_DEVICEADDR_USBADR_MASK             USB_DEVICEADDR_USBADR_MASK
#define USBHS_DEVICEADDR_USBADR_SHIFT            USB_DEVICEADDR_USBADR_SHIFT
#define USBHS_DEVICEADDR_USBADR(x)               USB_DEVICEADDR_USBADR(x)
#define USBHS_PERIODICLISTBASE_PERBASE_MASK      USB_PERIODICLISTBASE_BASEADR_MASK
#define USBHS_PERIODICLISTBASE_PERBASE_SHIFT     USB_PERIODICLISTBASE_BASEADR_SHIFT
#define USBHS_PERIODICLISTBASE_PERBASE(x)        USB_PERIODICLISTBASE_BASEADR(x)
#define USBHS_ASYNCLISTADDR_ASYBASE_MASK         USB_ASYNCLISTADDR_ASYBASE_MASK
#define USBHS_ASYNCLISTADDR_ASYBASE_SHIFT        USB_ASYNCLISTADDR_ASYBASE_SHIFT
#define USBHS_ASYNCLISTADDR_ASYBASE(x)           USB_ASYNCLISTADDR_ASYBASE(x)
#define USBHS_EPLISTADDR_EPBASE_MASK             USB_ENDPTLISTADDR_EPBASE_MASK
#define USBHS_EPLISTADDR_EPBASE_SHIFT            USB_ENDPTLISTADDR_EPBASE_SHIFT
#define USBHS_EPLISTADDR_EPBASE(x)               USB_ENDPTLISTADDR_EPBASE(x)
#define USBHS_BURSTSIZE_RXPBURST_MASK            USB_BURSTSIZE_RXPBURST_MASK
#define USBHS_BURSTSIZE_RXPBURST_SHIFT           USB_BURSTSIZE_RXPBURST_SHIFT
#define USBHS_BURSTSIZE_RXPBURST(x)              USB_BURSTSIZE_RXPBURST(x)
#define USBHS_BURSTSIZE_TXPBURST_MASK            USB_BURSTSIZE_TXPBURST_MASK
#define USBHS_BURSTSIZE_TXPBURST_SHIFT           USB_BURSTSIZE_TXPBURST_SHIFT
#define USBHS_BURSTSIZE_TXPBURST(x)              USB_BURSTSIZE_TXPBURST(x)
#define USBHS_TXFILLTUNING_TXSCHOH_MASK          USB_TXFILLTUNING_TXSCHOH_MASK
#define USBHS_TXFILLTUNING_TXSCHOH_SHIFT         USB_TXFILLTUNING_TXSCHOH_SHIFT
#define USBHS_TXFILLTUNING_TXSCHOH(x)            USB_TXFILLTUNING_TXSCHOH(x)
#define USBHS_TXFILLTUNING_TXSCHHEALTH_MASK      USB_TXFILLTUNING_TXSCHHEALTH_MASK
#define USBHS_TXFILLTUNING_TXSCHHEALTH_SHIFT     USB_TXFILLTUNING_TXSCHHEALTH_SHIFT
#define USBHS_TXFILLTUNING_TXSCHHEALTH(x)        USB_TXFILLTUNING_TXSCHHEALTH(x)
#define USBHS_TXFILLTUNING_TXFIFOTHRES_MASK      USB_TXFILLTUNING_TXFIFOTHRES_MASK
#define USBHS_TXFILLTUNING_TXFIFOTHRES_SHIFT     USB_TXFILLTUNING_TXFIFOTHRES_SHIFT
#define USBHS_TXFILLTUNING_TXFIFOTHRES(x)        USB_TXFILLTUNING_TXFIFOTHRES(x)
#define USBHS_ENDPTNAK_EPRN_MASK                 USB_ENDPTNAK_EPRN_MASK
#define USBHS_ENDPTNAK_EPRN_SHIFT                USB_ENDPTNAK_EPRN_SHIFT
#define USBHS_ENDPTNAK_EPRN(x)                   USB_ENDPTNAK_EPRN(x)
#define USBHS_ENDPTNAK_EPTN_MASK                 USB_ENDPTNAK_EPTN_MASK
#define USBHS_ENDPTNAK_EPTN_SHIFT                USB_ENDPTNAK_EPTN_SHIFT
#define USBHS_ENDPTNAK_EPTN(x)                   USB_ENDPTNAK_EPTN(x)
#define USBHS_ENDPTNAKEN_EPRNE_MASK              USB_ENDPTNAKEN_EPRNE_MASK
#define USBHS_ENDPTNAKEN_EPRNE_SHIFT             USB_ENDPTNAKEN_EPRNE_SHIFT
#define USBHS_ENDPTNAKEN_EPRNE(x)                USB_ENDPTNAKEN_EPRNE(x)
#define USBHS_ENDPTNAKEN_EPTNE_MASK              USB_ENDPTNAKEN_EPTNE_MASK
#define USBHS_ENDPTNAKEN_EPTNE_SHIFT             USB_ENDPTNAKEN_EPTNE_SHIFT
#define USBHS_ENDPTNAKEN_EPTNE(x)                USB_ENDPTNAKEN_EPTNE(x)
#define USBHS_CONFIGFLAG_CF_MASK                 USB_CONFIGFLAG_CF_MASK
#define USBHS_CONFIGFLAG_CF_SHIFT                USB_CONFIGFLAG_CF_SHIFT
#define USBHS_CONFIGFLAG_CF(x)                   USB_CONFIGFLAG_CF(x)
#define USBHS_PORTSC1_CCS_MASK                   USB_PORTSC1_CCS_MASK
#define USBHS_PORTSC1_CCS_SHIFT                  USB_PORTSC1_CCS_SHIFT
#define USBHS_PORTSC1_CCS(x)                     USB_PORTSC1_CCS(x)
#define USBHS_PORTSC1_CSC_MASK                   USB_PORTSC1_CSC_MASK
#define USBHS_PORTSC1_CSC_SHIFT                  USB_PORTSC1_CSC_SHIFT
#define USBHS_PORTSC1_CSC(x)                     USB_PORTSC1_CSC(x)
#define USBHS_PORTSC1_PE_MASK                    USB_PORTSC1_PE_MASK
#define USBHS_PORTSC1_PE_SHIFT                   USB_PORTSC1_PE_SHIFT
#define USBHS_PORTSC1_PE(x)                      USB_PORTSC1_PE(x)
#define USBHS_PORTSC1_PEC_MASK                   USB_PORTSC1_PEC_MASK
#define USBHS_PORTSC1_PEC_SHIFT                  USB_PORTSC1_PEC_SHIFT
#define USBHS_PORTSC1_PEC(x)                     USB_PORTSC1_PEC(x)
#define USBHS_PORTSC1_OCA_MASK                   USB_PORTSC1_OCA_MASK
#define USBHS_PORTSC1_OCA_SHIFT                  USB_PORTSC1_OCA_SHIFT
#define USBHS_PORTSC1_OCA(x)                     USB_PORTSC1_OCA(x)
#define USBHS_PORTSC1_OCC_MASK                   USB_PORTSC1_OCC_MASK
#define USBHS_PORTSC1_OCC_SHIFT                  USB_PORTSC1_OCC_SHIFT
#define USBHS_PORTSC1_OCC(x)                     USB_PORTSC1_OCC(x)
#define USBHS_PORTSC1_FPR_MASK                   USB_PORTSC1_FPR_MASK
#define USBHS_PORTSC1_FPR_SHIFT                  USB_PORTSC1_FPR_SHIFT
#define USBHS_PORTSC1_FPR(x)                     USB_PORTSC1_FPR(x)
#define USBHS_PORTSC1_SUSP_MASK                  USB_PORTSC1_SUSP_MASK
#define USBHS_PORTSC1_SUSP_SHIFT                 USB_PORTSC1_SUSP_SHIFT
#define USBHS_PORTSC1_SUSP(x)                    USB_PORTSC1_SUSP(x)
#define USBHS_PORTSC1_PR_MASK                    USB_PORTSC1_PR_MASK
#define USBHS_PORTSC1_PR_SHIFT                   USB_PORTSC1_PR_SHIFT
#define USBHS_PORTSC1_PR(x)                      USB_PORTSC1_PR(x)
#define USBHS_PORTSC1_HSP_MASK                   USB_PORTSC1_HSP_MASK
#define USBHS_PORTSC1_HSP_SHIFT                  USB_PORTSC1_HSP_SHIFT
#define USBHS_PORTSC1_HSP(x)                     USB_PORTSC1_HSP(x)
#define USBHS_PORTSC1_LS_MASK                    USB_PORTSC1_LS_MASK
#define USBHS_PORTSC1_LS_SHIFT                   USB_PORTSC1_LS_SHIFT
#define USBHS_PORTSC1_LS(x)                      USB_PORTSC1_LS(x)
#define USBHS_PORTSC1_PP_MASK                    USB_PORTSC1_PP_MASK
#define USBHS_PORTSC1_PP_SHIFT                   USB_PORTSC1_PP_SHIFT
#define USBHS_PORTSC1_PP(x)                      USB_PORTSC1_PP(x)
#define USBHS_PORTSC1_PO_MASK                    USB_PORTSC1_PO_MASK
#define USBHS_PORTSC1_PO_SHIFT                   USB_PORTSC1_PO_SHIFT
#define USBHS_PORTSC1_PO(x)                      USB_PORTSC1_PO(x)
#define USBHS_PORTSC1_PIC_MASK                   USB_PORTSC1_PIC_MASK
#define USBHS_PORTSC1_PIC_SHIFT                  USB_PORTSC1_PIC_SHIFT
#define USBHS_PORTSC1_PIC(x)                     USB_PORTSC1_PIC(x)
#define USBHS_PORTSC1_PTC_MASK                   USB_PORTSC1_PTC_MASK
#define USBHS_PORTSC1_PTC_SHIFT                  USB_PORTSC1_PTC_SHIFT
#define USBHS_PORTSC1_PTC(x)                     USB_PORTSC1_PTC(x)
#define USBHS_PORTSC1_WKCN_MASK                  USB_PORTSC1_WKCN_MASK
#define USBHS_PORTSC1_WKCN_SHIFT                 USB_PORTSC1_WKCN_SHIFT
#define USBHS_PORTSC1_WKCN(x)                    USB_PORTSC1_WKCN(x)
#define USBHS_PORTSC1_WKDS_MASK                  USB_PORTSC1_WKDC_MASK
#define USBHS_PORTSC1_WKDS_SHIFT                 USB_PORTSC1_WKDC_SHIFT
#define USBHS_PORTSC1_WKDS(x)                    USB_PORTSC1_WKDC(x)
#define USBHS_PORTSC1_WKOC_MASK                  USB_PORTSC1_WKOC_MASK
#define USBHS_PORTSC1_WKOC_SHIFT                 USB_PORTSC1_WKOC_SHIFT
#define USBHS_PORTSC1_WKOC(x)                    USB_PORTSC1_WKOC(x)
#define USBHS_PORTSC1_PHCD_MASK                  USB_PORTSC1_PHCD_MASK
#define USBHS_PORTSC1_PHCD_SHIFT                 USB_PORTSC1_PHCD_SHIFT
#define USBHS_PORTSC1_PHCD(x)                    USB_PORTSC1_PHCD(x)
#define USBHS_PORTSC1_PFSC_MASK                  USB_PORTSC1_PFSC_MASK
#define USBHS_PORTSC1_PFSC_SHIFT                 USB_PORTSC1_PFSC_SHIFT
#define USBHS_PORTSC1_PFSC(x)                    USB_PORTSC1_PFSC(x)
#define USBHS_PORTSC1_PTS2_MASK                  USB_PORTSC1_PTS_2_MASK
#define USBHS_PORTSC1_PTS2_SHIFT                 USB_PORTSC1_PTS_2_SHIFT
#define USBHS_PORTSC1_PTS2(x)                    USB_PORTSC1_PTS_2(x)
#define USBHS_PORTSC1_PSPD_MASK                  USB_PORTSC1_PSPD_MASK
#define USBHS_PORTSC1_PSPD_SHIFT                 USB_PORTSC1_PSPD_SHIFT
#define USBHS_PORTSC1_PSPD(x)                    USB_PORTSC1_PSPD(x)
#define USBHS_PORTSC1_PTW_MASK                   USB_PORTSC1_PTW_MASK
#define USBHS_PORTSC1_PTW_SHIFT                  USB_PORTSC1_PTW_SHIFT
#define USBHS_PORTSC1_PTW(x)                     USB_PORTSC1_PTW(x)
#define USBHS_PORTSC1_STS_MASK                   USB_PORTSC1_STS_MASK
#define USBHS_PORTSC1_STS_SHIFT                  USB_PORTSC1_STS_SHIFT
#define USBHS_PORTSC1_STS(x)                     USB_PORTSC1_STS(x)
#define USBHS_PORTSC1_PTS_MASK                   USB_PORTSC1_PTS_1_MASK
#define USBHS_PORTSC1_PTS_SHIFT                  USB_PORTSC1_PTS_1_SHIFT
#define USBHS_PORTSC1_PTS(x)                     USB_PORTSC1_PTS_1(x)
#define USBHS_OTGSC_VD_MASK                      USB_OTGSC_VD_MASK
#define USBHS_OTGSC_VD_SHIFT                     USB_OTGSC_VD_SHIFT
#define USBHS_OTGSC_VD(x)                        USB_OTGSC_VD(x)
#define USBHS_OTGSC_VC_MASK                      USB_OTGSC_VC_MASK
#define USBHS_OTGSC_VC_SHIFT                     USB_OTGSC_VC_SHIFT
#define USBHS_OTGSC_VC(x)                        USB_OTGSC_VC(x)
#define USBHS_OTGSC_OT_MASK                      USB_OTGSC_OT_MASK
#define USBHS_OTGSC_OT_SHIFT                     USB_OTGSC_OT_SHIFT
#define USBHS_OTGSC_OT(x)                        USB_OTGSC_OT(x)
#define USBHS_OTGSC_DP_MASK                      USB_OTGSC_DP_MASK
#define USBHS_OTGSC_DP_SHIFT                     USB_OTGSC_DP_SHIFT
#define USBHS_OTGSC_DP(x)                        USB_OTGSC_DP(x)
#define USBHS_OTGSC_IDPU_MASK                    USB_OTGSC_IDPU_MASK
#define USBHS_OTGSC_IDPU_SHIFT                   USB_OTGSC_IDPU_SHIFT
#define USBHS_OTGSC_IDPU(x)                      USB_OTGSC_IDPU(x)
#define USBHS_OTGSC_ID_MASK                      USB_OTGSC_ID_MASK
#define USBHS_OTGSC_ID_SHIFT                     USB_OTGSC_ID_SHIFT
#define USBHS_OTGSC_ID(x)                        USB_OTGSC_ID(x)
#define USBHS_OTGSC_AVV_MASK                     USB_OTGSC_AVV_MASK
#define USBHS_OTGSC_AVV_SHIFT                    USB_OTGSC_AVV_SHIFT
#define USBHS_OTGSC_AVV(x)                       USB_OTGSC_AVV(x)
#define USBHS_OTGSC_ASV_MASK                     USB_OTGSC_ASV_MASK
#define USBHS_OTGSC_ASV_SHIFT                    USB_OTGSC_ASV_SHIFT
#define USBHS_OTGSC_ASV(x)                       USB_OTGSC_ASV(x)
#define USBHS_OTGSC_BSV_MASK                     USB_OTGSC_BSV_MASK
#define USBHS_OTGSC_BSV_SHIFT                    USB_OTGSC_BSV_SHIFT
#define USBHS_OTGSC_BSV(x)                       USB_OTGSC_BSV(x)
#define USBHS_OTGSC_BSE_MASK                     USB_OTGSC_BSE_MASK
#define USBHS_OTGSC_BSE_SHIFT                    USB_OTGSC_BSE_SHIFT
#define USBHS_OTGSC_BSE(x)                       USB_OTGSC_BSE(x)
#define USBHS_OTGSC_MST_MASK                     USB_OTGSC_TOG_1MS_MASK
#define USBHS_OTGSC_MST_SHIFT                    USB_OTGSC_TOG_1MS_SHIFT
#define USBHS_OTGSC_MST(x)                       USB_OTGSC_TOG_1MS(x)
#define USBHS_OTGSC_DPS_MASK                     USB_OTGSC_DPS_MASK
#define USBHS_OTGSC_DPS_SHIFT                    USB_OTGSC_DPS_SHIFT
#define USBHS_OTGSC_DPS(x)                       USB_OTGSC_DPS(x)
#define USBHS_OTGSC_IDIS_MASK                    USB_OTGSC_IDIS_MASK
#define USBHS_OTGSC_IDIS_SHIFT                   USB_OTGSC_IDIS_SHIFT
#define USBHS_OTGSC_IDIS(x)                      USB_OTGSC_IDIS(x)
#define USBHS_OTGSC_AVVIS_MASK                   USB_OTGSC_AVVIS_MASK
#define USBHS_OTGSC_AVVIS_SHIFT                  USB_OTGSC_AVVIS_SHIFT
#define USBHS_OTGSC_AVVIS(x)                     USB_OTGSC_AVVIS(x)
#define USBHS_OTGSC_ASVIS_MASK                   USB_OTGSC_ASVIS_MASK
#define USBHS_OTGSC_ASVIS_SHIFT                  USB_OTGSC_ASVIS_SHIFT
#define USBHS_OTGSC_ASVIS(x)                     USB_OTGSC_ASVIS(x)
#define USBHS_OTGSC_BSVIS_MASK                   USB_OTGSC_BSVIS_MASK
#define USBHS_OTGSC_BSVIS_SHIFT                  USB_OTGSC_BSVIS_SHIFT
#define USBHS_OTGSC_BSVIS(x)                     USB_OTGSC_BSVIS(x)
#define USBHS_OTGSC_BSEIS_MASK                   USB_OTGSC_BSEIS_MASK
#define USBHS_OTGSC_BSEIS_SHIFT                  USB_OTGSC_BSEIS_SHIFT
#define USBHS_OTGSC_BSEIS(x)                     USB_OTGSC_BSEIS(x)
#define USBHS_OTGSC_MSS_MASK                     USB_OTGSC_STATUS_1MS_MASK
#define USBHS_OTGSC_MSS_SHIFT                    USB_OTGSC_STATUS_1MS_SHIFT
#define USBHS_OTGSC_MSS(x)                       USB_OTGSC_STATUS_1MS(x)
#define USBHS_OTGSC_DPIS_MASK                    USB_OTGSC_DPIS_MASK
#define USBHS_OTGSC_DPIS_SHIFT                   USB_OTGSC_DPIS_SHIFT
#define USBHS_OTGSC_DPIS(x)                      USB_OTGSC_DPIS(x)
#define USBHS_OTGSC_IDIE_MASK                    USB_OTGSC_IDIE_MASK
#define USBHS_OTGSC_IDIE_SHIFT                   USB_OTGSC_IDIE_SHIFT
#define USBHS_OTGSC_IDIE(x)                      USB_OTGSC_IDIE(x)
#define USBHS_OTGSC_AVVIE_MASK                   USB_OTGSC_AVVIE_MASK
#define USBHS_OTGSC_AVVIE_SHIFT                  USB_OTGSC_AVVIE_SHIFT
#define USBHS_OTGSC_AVVIE(x)                     USB_OTGSC_AVVIE(x)
#define USBHS_OTGSC_ASVIE_MASK                   USB_OTGSC_ASVIE_MASK
#define USBHS_OTGSC_ASVIE_SHIFT                  USB_OTGSC_ASVIE_SHIFT
#define USBHS_OTGSC_ASVIE(x)                     USB_OTGSC_ASVIE(x)
#define USBHS_OTGSC_BSVIE_MASK                   USB_OTGSC_BSVIE_MASK
#define USBHS_OTGSC_BSVIE_SHIFT                  USB_OTGSC_BSVIE_SHIFT
#define USBHS_OTGSC_BSVIE(x)                     USB_OTGSC_BSVIE(x)
#define USBHS_OTGSC_BSEIE_MASK                   USB_OTGSC_BSEIE_MASK
#define USBHS_OTGSC_BSEIE_SHIFT                  USB_OTGSC_BSEIE_SHIFT
#define USBHS_OTGSC_BSEIE(x)                     USB_OTGSC_BSEIE(x)
#define USBHS_OTGSC_MSE_MASK                     USB_OTGSC_EN_1MS_MASK
#define USBHS_OTGSC_MSE_SHIFT                    USB_OTGSC_EN_1MS_SHIFT
#define USBHS_OTGSC_MSE(x)                       USB_OTGSC_EN_1MS(x)
#define USBHS_OTGSC_DPIE_MASK                    USB_OTGSC_DPIE_MASK
#define USBHS_OTGSC_DPIE_SHIFT                   USB_OTGSC_DPIE_SHIFT
#define USBHS_OTGSC_DPIE(x)                      USB_OTGSC_DPIE(x)
#define USBHS_USBMODE_CM_MASK                    USB_USBMODE_CM_MASK
#define USBHS_USBMODE_CM_SHIFT                   USB_USBMODE_CM_SHIFT
#define USBHS_USBMODE_CM(x)                      USB_USBMODE_CM(x)
#define USBHS_USBMODE_ES_MASK                    USB_USBMODE_ES_MASK
#define USBHS_USBMODE_ES_SHIFT                   USB_USBMODE_ES_SHIFT
#define USBHS_USBMODE_ES(x)                      USB_USBMODE_ES(x)
#define USBHS_USBMODE_SLOM_MASK                  USB_USBMODE_SLOM_MASK
#define USBHS_USBMODE_SLOM_SHIFT                 USB_USBMODE_SLOM_SHIFT
#define USBHS_USBMODE_SLOM(x)                    USB_USBMODE_SLOM(x)
#define USBHS_USBMODE_SDIS_MASK                  USB_USBMODE_SDIS_MASK
#define USBHS_USBMODE_SDIS_SHIFT                 USB_USBMODE_SDIS_SHIFT
#define USBHS_USBMODE_SDIS(x)                    USB_USBMODE_SDIS(x)
#define USBHS_EPSETUPSR_EPSETUPSTAT_MASK         USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK
#define USBHS_EPSETUPSR_EPSETUPSTAT_SHIFT        USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT
#define USBHS_EPSETUPSR_EPSETUPSTAT(x)           USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT(x)
#define USBHS_EPPRIME_PERB_MASK                  USB_ENDPTPRIME_PERB_MASK
#define USBHS_EPPRIME_PERB_SHIFT                 USB_ENDPTPRIME_PERB_SHIFT
#define USBHS_EPPRIME_PERB(x)                    USB_ENDPTPRIME_PERB(x)
#define USBHS_EPPRIME_PETB_MASK                  USB_ENDPTPRIME_PETB_MASK
#define USBHS_EPPRIME_PETB_SHIFT                 USB_ENDPTPRIME_PETB_SHIFT
#define USBHS_EPPRIME_PETB(x)                    USB_ENDPTPRIME_PETB(x)
#define USBHS_EPFLUSH_FERB_MASK                  USB_ENDPTFLUSH_FERB_MASK
#define USBHS_EPFLUSH_FERB_SHIFT                 USB_ENDPTFLUSH_FERB_SHIFT
#define USBHS_EPFLUSH_FERB(x)                    USB_ENDPTFLUSH_FERB(x)
#define USBHS_EPFLUSH_FETB_MASK                  USB_ENDPTFLUSH_FETB_MASK
#define USBHS_EPFLUSH_FETB_SHIFT                 USB_ENDPTFLUSH_FETB_SHIFT
#define USBHS_EPFLUSH_FETB(x)                    USB_ENDPTFLUSH_FETB(x)
#define USBHS_EPSR_ERBR_MASK                     USB_ENDPTSTAT_ERBR_MASK
#define USBHS_EPSR_ERBR_SHIFT                    USB_ENDPTSTAT_ERBR_SHIFT
#define USBHS_EPSR_ERBR(x)                       USB_ENDPTSTAT_ERBR(x)
#define USBHS_EPSR_ETBR_MASK                     USB_ENDPTSTAT_ETBR_MASK
#define USBHS_EPSR_ETBR_SHIFT                    USB_ENDPTSTAT_ETBR_SHIFT
#define USBHS_EPSR_ETBR(x)                       USB_ENDPTSTAT_ETBR(x)
#define USBHS_EPCOMPLETE_ERCE_MASK               USB_ENDPTCOMPLETE_ERCE_MASK
#define USBHS_EPCOMPLETE_ERCE_SHIFT              USB_ENDPTCOMPLETE_ERCE_SHIFT
#define USBHS_EPCOMPLETE_ERCE(x)                 USB_ENDPTCOMPLETE_ERCE(x)
#define USBHS_EPCOMPLETE_ETCE_MASK               USB_ENDPTCOMPLETE_ETCE_MASK
#define USBHS_EPCOMPLETE_ETCE_SHIFT              USB_ENDPTCOMPLETE_ETCE_SHIFT
#define USBHS_EPCOMPLETE_ETCE(x)                 USB_ENDPTCOMPLETE_ETCE(x)
#define USBHS_EPCR0_RXS_MASK                     USB_ENDPTCTRL0_RXS_MASK
#define USBHS_EPCR0_RXS_SHIFT                    USB_ENDPTCTRL0_RXS_SHIFT
#define USBHS_EPCR0_RXS(x)                       USB_ENDPTCTRL0_RXS(x)
#define USBHS_EPCR0_RXT_MASK                     USB_ENDPTCTRL0_RXT_MASK
#define USBHS_EPCR0_RXT_SHIFT                    USB_ENDPTCTRL0_RXT_SHIFT
#define USBHS_EPCR0_RXT(x)                       USB_ENDPTCTRL0_RXT(x)
#define USBHS_EPCR0_RXE_MASK                     USB_ENDPTCTRL0_RXE_MASK
#define USBHS_EPCR0_RXE_SHIFT                    USB_ENDPTCTRL0_RXE_SHIFT
#define USBHS_EPCR0_RXE(x)                       USB_ENDPTCTRL0_RXE(x)
#define USBHS_EPCR0_TXS_MASK                     USB_ENDPTCTRL0_TXS_MASK
#define USBHS_EPCR0_TXS_SHIFT                    USB_ENDPTCTRL0_TXS_SHIFT
#define USBHS_EPCR0_TXS(x)                       USB_ENDPTCTRL0_TXS(x)
#define USBHS_EPCR0_TXT_MASK                     USB_ENDPTCTRL0_TXT_MASK
#define USBHS_EPCR0_TXT_SHIFT                    USB_ENDPTCTRL0_TXT_SHIFT
#define USBHS_EPCR0_TXT(x)                       USB_ENDPTCTRL0_TXT(x)
#define USBHS_EPCR0_TXE_MASK                     USB_ENDPTCTRL0_TXE_MASK
#define USBHS_EPCR0_TXE_SHIFT                    USB_ENDPTCTRL0_TXE_SHIFT
#define USBHS_EPCR0_TXE(x)                       USB_ENDPTCTRL0_TXE(x)
#define USBHS_EPCR_RXS_MASK                      USB_ENDPTCTRL_RXS_MASK
#define USBHS_EPCR_RXS_SHIFT                     USB_ENDPTCTRL_RXS_SHIFT
#define USBHS_EPCR_RXS(x)                        USB_ENDPTCTRL_RXS(x)
#define USBHS_EPCR_RXD_MASK                      USB_ENDPTCTRL_RXD_MASK
#define USBHS_EPCR_RXD_SHIFT                     USB_ENDPTCTRL_RXD_SHIFT
#define USBHS_EPCR_RXD(x)                        USB_ENDPTCTRL_RXD(x)
#define USBHS_EPCR_RXT_MASK                      USB_ENDPTCTRL_RXT_MASK
#define USBHS_EPCR_RXT_SHIFT                     USB_ENDPTCTRL_RXT_SHIFT
#define USBHS_EPCR_RXT(x)                        USB_ENDPTCTRL_RXT(x)
#define USBHS_EPCR_RXI_MASK                      USB_ENDPTCTRL_RXI_MASK
#define USBHS_EPCR_RXI_SHIFT                     USB_ENDPTCTRL_RXI_SHIFT
#define USBHS_EPCR_RXI(x)                        USB_ENDPTCTRL_RXI(x)
#define USBHS_EPCR_RXR_MASK                      USB_ENDPTCTRL_RXR_MASK
#define USBHS_EPCR_RXR_SHIFT                     USB_ENDPTCTRL_RXR_SHIFT
#define USBHS_EPCR_RXR(x)                        USB_ENDPTCTRL_RXR(x)
#define USBHS_EPCR_RXE_MASK                      USB_ENDPTCTRL_RXE_MASK
#define USBHS_EPCR_RXE_SHIFT                     USB_ENDPTCTRL_RXE_SHIFT
#define USBHS_EPCR_RXE(x)                        USB_ENDPTCTRL_RXE(x)
#define USBHS_EPCR_TXS_MASK                      USB_ENDPTCTRL_TXS_MASK
#define USBHS_EPCR_TXS_SHIFT                     USB_ENDPTCTRL_TXS_SHIFT
#define USBHS_EPCR_TXS(x)                        USB_ENDPTCTRL_TXS(x)
#define USBHS_EPCR_TXD_MASK                      USB_ENDPTCTRL_TXD_MASK
#define USBHS_EPCR_TXD_SHIFT                     USB_ENDPTCTRL_TXD_SHIFT
#define USBHS_EPCR_TXD(x)                        USB_ENDPTCTRL_TXD(x)
#define USBHS_EPCR_TXT_MASK                      USB_ENDPTCTRL_TXT_MASK
#define USBHS_EPCR_TXT_SHIFT                     USB_ENDPTCTRL_TXT_SHIFT
#define USBHS_EPCR_TXT(x)                        USB_ENDPTCTRL_TXT(x)
#define USBHS_EPCR_TXI_MASK                      USB_ENDPTCTRL_TXI_MASK
#define USBHS_EPCR_TXI_SHIFT                     USB_ENDPTCTRL_TXI_SHIFT
#define USBHS_EPCR_TXI(x)                        USB_ENDPTCTRL_TXI(x)
#define USBHS_EPCR_TXR_MASK                      USB_ENDPTCTRL_TXR_MASK
#define USBHS_EPCR_TXR_SHIFT                     USB_ENDPTCTRL_TXR_SHIFT
#define USBHS_EPCR_TXR(x)                        USB_ENDPTCTRL_TXR(x)
#define USBHS_EPCR_TXE_MASK                      USB_ENDPTCTRL_TXE_MASK
#define USBHS_EPCR_TXE_SHIFT                     USB_ENDPTCTRL_TXE_SHIFT
#define USBHS_EPCR_TXE(x)                        USB_ENDPTCTRL_TXE(x)
#define USBHS_EPCR_COUNT                         USB_ENDPTCTRL_COUNT
#define USBHS_Type                               USB_Type
#define USBHS_BASE_ADDRS                         USB_BASE_ADDRS
#define USBHS_IRQS                               USB_IRQS
#define USBHS_IRQHandler                         USB0_IRQHandler


/* USBHSDCD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBDCD base address */
  #define USBDCD_BASE                              (0x50414800u)
  /** Peripheral USBDCD base address */
  #define USBDCD_BASE_NS                           (0x40414800u)
  /** Peripheral USBDCD base pointer */
  #define USBDCD                                   ((USBHSDCD_Type *)USBDCD_BASE)
  /** Peripheral USBDCD base pointer */
  #define USBDCD_NS                                ((USBHSDCD_Type *)USBDCD_BASE_NS)
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS                      { USBDCD_BASE }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS                       { USBDCD }
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS_NS                   { USBDCD_BASE_NS }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS_NS                    { USBDCD_NS }
#else
  /** Peripheral USBDCD base address */
  #define USBDCD_BASE                              (0x40414800u)
  /** Peripheral USBDCD base pointer */
  #define USBDCD                                   ((USBHSDCD_Type *)USBDCD_BASE)
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS                      { USBDCD_BASE }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS                       { USBDCD }
#endif

/* USBNC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBNC0 base address */
  #define USBNC0_BASE                              (0x50418200u)
  /** Peripheral USBNC0 base address */
  #define USBNC0_BASE_NS                           (0x40418200u)
  /** Peripheral USBNC0 base pointer */
  #define USBNC0                                   ((USBNC_Type *)USBNC0_BASE)
  /** Peripheral USBNC0 base pointer */
  #define USBNC0_NS                                ((USBNC_Type *)USBNC0_BASE_NS)
  /** Peripheral USBNC1 base address */
  #define USBNC1_BASE                              (0x50419200u)
  /** Peripheral USBNC1 base address */
  #define USBNC1_BASE_NS                           (0x40419200u)
  /** Peripheral USBNC1 base pointer */
  #define USBNC1                                   ((USBNC_Type *)USBNC1_BASE)
  /** Peripheral USBNC1 base pointer */
  #define USBNC1_NS                                ((USBNC_Type *)USBNC1_BASE_NS)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { USBNC0_BASE, USBNC1_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { USBNC0, USBNC1 }
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS_NS                      { USBNC0_BASE_NS, USBNC1_BASE_NS }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS_NS                       { USBNC0_NS, USBNC1_NS }
#else
  /** Peripheral USBNC0 base address */
  #define USBNC0_BASE                              (0x40418200u)
  /** Peripheral USBNC0 base pointer */
  #define USBNC0                                   ((USBNC_Type *)USBNC0_BASE)
  /** Peripheral USBNC1 base address */
  #define USBNC1_BASE                              (0x40419200u)
  /** Peripheral USBNC1 base pointer */
  #define USBNC1                                   ((USBNC_Type *)USBNC1_BASE)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { USBNC0_BASE, USBNC1_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { USBNC0, USBNC1 }
#endif
/* Backward compatibility */
#define USB_OTGn_CTRL     CTRL1
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_MASK      USBNC_CTRL1_OVER_CUR_DIS_MASK
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_SHIFT     USBNC_CTRL1_OVER_CUR_DIS_SHIFT
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS(x)        USBNC_CTRL1_OVER_CUR_DIS(x)
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_MASK      USBNC_CTRL1_OVER_CUR_POL_MASK
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_SHIFT     USBNC_CTRL1_OVER_CUR_POL_SHIFT
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL(x)        USBNC_CTRL1_OVER_CUR_POL(x)
#define USBNC_USB_OTGn_CTRL_PWR_POL_MASK           USBNC_CTRL1_PWR_POL_MASK
#define USBNC_USB_OTGn_CTRL_PWR_POL_SHIFT          USBNC_CTRL1_PWR_POL_SHIFT
#define USBNC_USB_OTGn_CTRL_PWR_POL(x)             USBNC_CTRL1_PWR_POL(x)
#define USBNC_USB_OTGn_CTRL_WIE_MASK               USBNC_CTRL1_WIE_MASK
#define USBNC_USB_OTGn_CTRL_WIE_SHIFT              USBNC_CTRL1_WIE_SHIFT
#define USBNC_USB_OTGn_CTRL_WIE(x)                 USBNC_CTRL1_WIE(x)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_MASK        USBNC_CTRL1_WKUP_SW_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_SHIFT       USBNC_CTRL1_WKUP_SW_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN(x)          USBNC_CTRL1_WKUP_SW_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_MASK           USBNC_CTRL1_WKUP_SW_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_SW_SHIFT          USBNC_CTRL1_WKUP_SW_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_SW(x)             USBNC_CTRL1_WKUP_SW(x)
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_MASK      USBNC_CTRL1_WKUP_VBUS_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_SHIFT     USBNC_CTRL1_WKUP_VBUS_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN(x)        USBNC_CTRL1_WKUP_VBUS_EN(x)
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN_MASK  USBNC_CTRL1_REMOTE_WAKEUP_EN_MASK
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN_SHIFT USBNC_CTRL1_REMOTE_WAKEUP_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN(x)    USBNC_CTRL1_REMOTE_WAKEUP_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_MASK      USBNC_CTRL1_WKUP_DPDM_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_SHIFT     USBNC_CTRL1_WKUP_DPDM_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN(x)        USBNC_CTRL1_WKUP_DPDM_EN(x)
#define USBNC_USB_OTGn_CTRL_WIR_MASK               USBNC_CTRL1_WIR_MASK
#define USBNC_USB_OTGn_CTRL_WIR_SHIFT              USBNC_CTRL1_WIR_SHIFT
#define USBNC_USB_OTGn_CTRL_WIR(x)                 USBNC_CTRL1_WIR(x)
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
#define USBNC_STACK_BASE_ADDRS                     { USBNC0_BASE, USBNC1_BASE }
#define USBNC_STACK_BASE_ADDRS_NS                  { USBNC0_BASE_NS, USBNC1_BASE_NS  }
#else
#define USBNC_STACK_BASE_ADDRS                     { USBNC0_BASE, USBNC1_BASE }
#endif


/* USBPHY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBPHY base address */
  #define USBPHY_BASE                              (0x50414000u)
  /** Peripheral USBPHY base address */
  #define USBPHY_BASE_NS                           (0x40414000u)
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
  #define USBPHY_BASE                              (0x40414000u)
  /** Peripheral USBPHY base pointer */
  #define USBPHY                                   ((USBPHY_Type *)USBPHY_BASE)
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS                        { USBPHY_BASE }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS                         { USBPHY }
#endif
/** Interrupt vectors for the USBPHY peripheral type */
#define USBPHY_IRQS                              { USBPHY0_IRQn }
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
  #define USDHC0_BASE                              (0x50412000u)
  /** Peripheral USDHC0 base address */
  #define USDHC0_BASE_NS                           (0x40412000u)
  /** Peripheral USDHC0 base pointer */
  #define USDHC0                                   ((USDHC_Type *)USDHC0_BASE)
  /** Peripheral USDHC0 base pointer */
  #define USDHC0_NS                                ((USDHC_Type *)USDHC0_BASE_NS)
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE                              (0x50413000u)
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE_NS                           (0x40413000u)
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
  #define USDHC0_BASE                              (0x40412000u)
  /** Peripheral USDHC0 base pointer */
  #define USDHC0                                   ((USDHC_Type *)USDHC0_BASE)
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE                              (0x40413000u)
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
  /** Peripheral UTICK1 base address */
  #define UTICK1_BASE                              (0x50052000u)
  /** Peripheral UTICK1 base address */
  #define UTICK1_BASE_NS                           (0x40052000u)
  /** Peripheral UTICK1 base pointer */
  #define UTICK1                                   ((UTICK_Type *)UTICK1_BASE)
  /** Peripheral UTICK1 base pointer */
  #define UTICK1_NS                                ((UTICK_Type *)UTICK1_BASE_NS)
  /** Array initializer of UTICK peripheral base addresses */
  #define UTICK_BASE_ADDRS                         { 0u, UTICK1_BASE }
  /** Array initializer of UTICK peripheral base pointers */
  #define UTICK_BASE_PTRS                          { (UTICK_Type *)0u, UTICK1 }
  /** Array initializer of UTICK peripheral base addresses */
  #define UTICK_BASE_ADDRS_NS                      { 0u, UTICK1_BASE_NS }
  /** Array initializer of UTICK peripheral base pointers */
  #define UTICK_BASE_PTRS_NS                       { (UTICK_Type *)0u, UTICK1_NS }
#else
  /** Peripheral UTICK1 base address */
  #define UTICK1_BASE                              (0x40052000u)
  /** Peripheral UTICK1 base pointer */
  #define UTICK1                                   ((UTICK_Type *)UTICK1_BASE)
  /** Array initializer of UTICK peripheral base addresses */
  #define UTICK_BASE_ADDRS                         { 0u, UTICK1_BASE }
  /** Array initializer of UTICK peripheral base pointers */
  #define UTICK_BASE_PTRS                          { (UTICK_Type *)0u, UTICK1 }
#endif
/** Interrupt vectors for the UTICK peripheral type */
#define UTICK_IRQS                               { NotAvail_IRQn, UTICK1_IRQn }

/* WWDT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WWDT2 base address */
  #define WWDT2_BASE                               (0x50050000u)
  /** Peripheral WWDT2 base address */
  #define WWDT2_BASE_NS                            (0x40050000u)
  /** Peripheral WWDT2 base pointer */
  #define WWDT2                                    ((WWDT_Type *)WWDT2_BASE)
  /** Peripheral WWDT2 base pointer */
  #define WWDT2_NS                                 ((WWDT_Type *)WWDT2_BASE_NS)
  /** Peripheral WWDT3 base address */
  #define WWDT3_BASE                               (0x50051000u)
  /** Peripheral WWDT3 base address */
  #define WWDT3_BASE_NS                            (0x40051000u)
  /** Peripheral WWDT3 base pointer */
  #define WWDT3                                    ((WWDT_Type *)WWDT3_BASE)
  /** Peripheral WWDT3 base pointer */
  #define WWDT3_NS                                 ((WWDT_Type *)WWDT3_BASE_NS)
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS                          { 0u, 0u, WWDT2_BASE, WWDT3_BASE }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS                           { (WWDT_Type *)0u, (WWDT_Type *)0u, WWDT2, WWDT3 }
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS_NS                       { 0u, 0u, WWDT2_BASE_NS, WWDT3_BASE_NS }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS_NS                        { (WWDT_Type *)0u, (WWDT_Type *)0u, WWDT2_NS, WWDT3_NS }
#else
  /** Peripheral WWDT2 base address */
  #define WWDT2_BASE                               (0x40050000u)
  /** Peripheral WWDT2 base pointer */
  #define WWDT2                                    ((WWDT_Type *)WWDT2_BASE)
  /** Peripheral WWDT3 base address */
  #define WWDT3_BASE                               (0x40051000u)
  /** Peripheral WWDT3 base pointer */
  #define WWDT3                                    ((WWDT_Type *)WWDT3_BASE)
  /** Array initializer of WWDT peripheral base addresses */
  #define WWDT_BASE_ADDRS                          { 0u, 0u, WWDT2_BASE, WWDT3_BASE }
  /** Array initializer of WWDT peripheral base pointers */
  #define WWDT_BASE_PTRS                           { (WWDT_Type *)0u, (WWDT_Type *)0u, WWDT2, WWDT3 }
#endif
/** Interrupt vectors for the WWDT peripheral type */
#define WWDT_IRQS                                { NotAvail_IRQn, NotAvail_IRQn, WDT2_IRQn, WDT3_IRQn }

/* XSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XSPI2 base address */
  #define XSPI2_BASE                               (0x50411000u)
  /** Peripheral XSPI2 base address */
  #define XSPI2_BASE_NS                            (0x40411000u)
  /** Peripheral XSPI2 base pointer */
  #define XSPI2                                    ((XSPI_Type *)XSPI2_BASE)
  /** Peripheral XSPI2 base pointer */
  #define XSPI2_NS                                 ((XSPI_Type *)XSPI2_BASE_NS)
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS                          { 0u, 0u, XSPI2_BASE }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS                           { (XSPI_Type *)0u, (XSPI_Type *)0u, XSPI2 }
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS_NS                       { 0u, 0u, XSPI2_BASE_NS }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS_NS                        { (XSPI_Type *)0u, (XSPI_Type *)0u, XSPI2_NS }
#else
  /** Peripheral XSPI2 base address */
  #define XSPI2_BASE                               (0x40411000u)
  /** Peripheral XSPI2 base pointer */
  #define XSPI2                                    ((XSPI_Type *)XSPI2_BASE)
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS                          { 0u, 0u, XSPI2_BASE }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS                           { (XSPI_Type *)0u, (XSPI_Type *)0u, XSPI2 }
#endif
/** Interrupt vectors for the XSPI peripheral type */
#define XSPI_IRQS                                { NotAvail_IRQn, NotAvail_IRQn, XSPI2_IRQn }
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /* XSPI AMBA address. */
  #define XSPI0_AMBA_BASE      (0x38000000u)
  #define XSPI1_AMBA_BASE      (0x18000000u)
  #define XSPI2_AMBA_BASE      (0x70000000u)
  #define XSPI0_AMBA_BASE_NS   (0x28000000u)
  #define XSPI1_AMBA_BASE_NS   (0x08000000u)
  #define XSPI2_AMBA_BASE_NS   (0x60000000u)
  #define XSPI_AMBA_BASES      {0x38000000u, 0x18000000u, 0x70000000u}
  #define XSPI_AMBA_BASES_NS   {0x28000000u, 0x08000000u, 0x60000000u}
#else
  /* XSPI AMBA address. */
  #define XSPI0_AMBA_BASE      (0x28000000u)
  #define XSPI1_AMBA_BASE      (0x08000000u)
  #define XSPI2_AMBA_BASE      (0x60000000u)
  #define XSPI_AMBA_BASES      {0x28000000u, 0x08000000u, 0x60000000u}
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

/**  Used for get the base address of ROM API */
#define FSL_ROM_API_BASE_ADDR 0x1302F000U

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* MIMXRT798S_CM33_CORE1_COMMON_H_ */

