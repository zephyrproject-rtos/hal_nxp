/*
** ###################################################################
**     Processors:          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGFOA_cm33_core0
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
**         CMSIS Peripheral Access Layer for MIMXRT798S_cm33_core0
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
 * @file MIMXRT798S_cm33_core0_COMMON.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMXRT798S_cm33_core0
 *
 * CMSIS Peripheral Access Layer for MIMXRT798S_cm33_core0
 */

#if !defined(MIMXRT798S_CM33_CORE0_COMMON_H_)
#define MIMXRT798S_CM33_CORE0_COMMON_H_          /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 174                /**< Number of interrupts in the Vector table */

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
  UTICK0_IRQn                  = 1,                /**< Micro-tick Timer */
  MRT0_IRQn                    = 2,                /**< MRT: Ored Interrupt request */
  CTIMER0_IRQn                 = 3,                /**< CTIMER: Interrupt request */
  CTIMER1_IRQn                 = 4,                /**< CTIMER: Interrupt request */
  SCT0_IRQn                    = 5,                /**< SCT: Interrupt request */
  CTIMER3_IRQn                 = 6,                /**< CTIMER: Interrupt request */
  LP_FLEXCOMM0_IRQn            = 7,                /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM1_IRQn            = 8,                /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM2_IRQn            = 9,                /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM3_IRQn            = 10,               /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM4_IRQn            = 11,               /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM5_IRQn            = 12,               /**< FLEXCOMM: Interrupt request */
  LPSPI14_IRQn                 = 13,               /**< LPSPI: Interrupt request */
  LPI2C15_IRQn                 = 14,               /**< LPI2C: Interrupt request */
  ADC_IRQn                     = 15,               /**< ADC0: Interrupt request */
  SDADC_IRQn                   = 16,               /**< SDADC0: Interrupt request */
  ACMP_IRQn                    = 17,               /**< ACMP: interrupt request */
  PDM_EVENT_IRQn               = 18,               /**< MIC: Interrupt request for read data or Error */
  PDM_HWVAD_EVENT_IRQn         = 19,               /**< MIC: Hardware Voice Activity Detector interrupt or error interrupt */
  HYPERVISOR_IRQn              = 20,               /**< SECURE: Compute domain P-Bus Hypervisor interrupt */
  SECURE_VIOLATION_IRQn        = 21,               /**< SECURE: Compute domain P-Bus Secure violation interrupt */
  SENSE_HYPERVISOR_IRQn        = 22,               /**< Sense domain Hypervisor interrupt */
  SENSE_SECURE_VIOLATION_IRQn  = 23,               /**< Sense domain Secure violation interrupt */
  MEDIA_HYPERVISOR_IRQn        = 24,               /**< Media domain Hypervisor interrupt */
  MEDIA_SECURE_VIOLATION_IRQn  = 25,               /**< Media domain Secure violation interrupt */
  RTC0_ALARM_IRQn              = 26,               /**< RTC: Alarm interrupt */
  RTC0_IRQn                    = 27,               /**< RTC: wakeup interrupt to Compute domain */
  HIFI4_IRQn                   = 28,               /**< HIFI4: Interrupt request */
  MU0_A_IRQn                   = 29,               /**< MU0: MUA, CPU0 to HiFi1 */
  MU1_A_IRQn                   = 30,               /**< MU1: MUA, CPU0 to CPU1 */
  MU4_A_IRQn                   = 31,               /**< MU4: MUA, CPU0 to HiFi4 */
  CTIMER2_IRQn                 = 32,               /**< CTIMER: Interrupt request */
  CTIMER4_IRQn                 = 33,               /**< CTIMER: Interrupt request */
  OS_EVENT_IRQn                = 34,               /**< OSEVENT: Event timer CPU0 Wakeup/interrupt */
  LP_FLEXCOMM6_IRQn            = 35,               /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM7_IRQn            = 36,               /**< FLEXCOMM: Interrupt request */
  USDHC0_IRQn                  = 37,               /**< USDHC: Interrupt request */
  USDHC1_IRQn                  = 38,               /**< USDHC: Interrupt request */
  I3C0_IRQn                    = 39,               /**< I3C: Interrupt Request */
  USB0_IRQn                    = 40,               /**< USB: HSUSB Interrup request */
  USB1_IRQn                    = 41,               /**< USB: eUSB Interrup request */
  WDT0_IRQn                    = 42,               /**< WDT: Interrupt request */
  WDT1_IRQn                    = 43,               /**< WDT: Interrupt request */
  USBPHY0_IRQn                 = 44,               /**< HSUSBPHY: UTM interrupt request */
  PUF_IRQn                     = 45,               /**< PUF: Interrupt Request */
  Reserved62_IRQn              = 46,               /**< Reserved interrupt 62 */
  LP_FLEXCOMM8_IRQn            = 47,               /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM9_IRQn            = 48,               /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM10_IRQn           = 49,               /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM11_IRQn           = 50,               /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM12_IRQn           = 51,               /**< FLEXCOMM: Interrupt request */
  LP_FLEXCOMM13_IRQn           = 52,               /**< FLEXCOMM: Interrupt request */
  LPSPI16_IRQn                 = 53,               /**< LPSPI: Interrupt request */
  I3C1_IRQn                    = 54,               /**< I3C: Interrupt Request */
  FLEXIO_IRQn                  = 55,               /**< FLEXIO: Interrupt request */
  LCDIF_IRQn                   = 56,               /**< LCDIF: Interrupt request */
  VGPU_IRQn                    = 57,               /**< VGPU: Interrupt from graphics core (Domain HCLK) */
  MIPI_IRQn                    = 58,               /**< DSI: Interrupt request */
  EDMA0_CH0_IRQn               = 59,               /**< EDMA: Channel 0 interrupt */
  EDMA0_CH1_IRQn               = 60,               /**< EDMA: Channel 1 interrupt */
  EDMA0_CH2_IRQn               = 61,               /**< EDMA: Channel 2 interrupt */
  EDMA0_CH3_IRQn               = 62,               /**< EDMA: Channel 3 interrupt */
  EDMA0_CH4_IRQn               = 63,               /**< EDMA: Channel 4 interrupt */
  EDMA0_CH5_IRQn               = 64,               /**< EDMA: Channel 5 interrupt */
  EDMA0_CH6_IRQn               = 65,               /**< EDMA: Channel 6 interrupt */
  EDMA0_CH7_IRQn               = 66,               /**< EDMA: Channel 7 interrupt */
  EDMA0_CH8_IRQn               = 67,               /**< EDMA: Channel 8 interrupt */
  EDMA0_CH9_IRQn               = 68,               /**< EDMA: Channel 9 interrupt */
  EDMA0_CH10_IRQn              = 69,               /**< EDMA: Channel 10 interrupt */
  EDMA0_CH11_IRQn              = 70,               /**< EDMA: Channel 11 interrupt */
  EDMA0_CH12_IRQn              = 71,               /**< EDMA: Channel 12 interrupt */
  EDMA0_CH13_IRQn              = 72,               /**< EDMA: Channel 13 interrupt */
  EDMA0_CH14_IRQn              = 73,               /**< EDMA: Channel 14 interrupt */
  EDMA0_CH15_IRQn              = 74,               /**< EDMA: Channel 15 interrupt */
  EDMA1_CH0_IRQn               = 75,               /**< EDMA: Channel 0 interrupt */
  EDMA1_CH1_IRQn               = 76,               /**< EDMA: Channel 1 interrupt */
  EDMA1_CH2_IRQn               = 77,               /**< EDMA: Channel 2 interrupt */
  EDMA1_CH3_IRQn               = 78,               /**< EDMA: Channel 3 interrupt */
  EDMA1_CH4_IRQn               = 79,               /**< EDMA: Channel 4 interrupt */
  EDMA1_CH5_IRQn               = 80,               /**< EDMA: Channel 5 interrupt */
  EDMA1_CH6_IRQn               = 81,               /**< EDMA: Channel 6 interrupt */
  EDMA1_CH7_IRQn               = 82,               /**< EDMA: Channel 7 interrupt */
  EDMA1_CH8_IRQn               = 83,               /**< EDMA: Channel 8 interrupt */
  EDMA1_CH9_IRQn               = 84,               /**< EDMA: Channel 9 interrupt */
  EDMA1_CH10_IRQn              = 85,               /**< EDMA: Channel 10 interrupt */
  EDMA1_CH11_IRQn              = 86,               /**< EDMA: Channel 11 interrupt */
  EDMA1_CH12_IRQn              = 87,               /**< EDMA: Channel 12 interrupt */
  EDMA1_CH13_IRQn              = 88,               /**< EDMA: Channel 13 interrupt */
  EDMA1_CH14_IRQn              = 89,               /**< EDMA: Channel 14 interrupt */
  EDMA1_CH15_IRQn              = 90,               /**< EDMA: Channel 15 interrupt */
  GPIO00_IRQn                  = 91,               /**< GPIO: Interupt request, channel 0 */
  GPIO01_IRQn                  = 92,               /**< GPIO: Interupt request, channel 1 */
  GPIO10_IRQn                  = 93,               /**< GPIO: Interupt request, channel 0 */
  GPIO11_IRQn                  = 94,               /**< GPIO: Interupt request, channel 1 */
  GPIO20_IRQn                  = 95,               /**< GPIO: Interupt request, channel 0 */
  GPIO21_IRQn                  = 96,               /**< GPIO: Interupt request, channel 1 */
  GPIO30_IRQn                  = 97,               /**< GPIO: Interupt request, channel 0 */
  GPIO31_IRQn                  = 98,               /**< GPIO: Interupt request, channel 1 */
  GPIO40_IRQn                  = 99,               /**< GPIO: Interupt request, channel 0 */
  GPIO41_IRQn                  = 100,              /**< GPIO: Interupt request, channel 1 */
  GPIO50_IRQn                  = 101,              /**< GPIO: Interupt request, channel 0 */
  GPIO51_IRQn                  = 102,              /**< GPIO: Interupt request, channel 1 */
  GPIO60_IRQn                  = 103,              /**< GPIO: Interupt request, channel 0 */
  GPIO61_IRQn                  = 104,              /**< GPIO: Interupt request, channel 1 */
  GPIO70_IRQn                  = 105,              /**< GPIO: Interupt request, channel 0 */
  GPIO71_IRQn                  = 106,              /**< GPIO: Interupt request, channel 1 */
  PIN_INT0_IRQn                = 107,              /**< PINT: Interupt request 0 */
  PIN_INT1_IRQn                = 108,              /**< PINT: Interupt request 1 */
  PIN_INT2_IRQn                = 109,              /**< PINT: Interupt request 2 */
  PIN_INT3_IRQn                = 110,              /**< PINT: Interupt request 3 */
  PIN_INT4_IRQn                = 111,              /**< PINT: Interupt request 4 */
  PIN_INT5_IRQn                = 112,              /**< PINT: Interupt request 5 */
  PIN_INT6_IRQn                = 113,              /**< PINT: Interupt request 6 */
  PIN_INT7_IRQn                = 114,              /**< PINT: Interupt request 7 */
  SAI0_IRQn                    = 115,              /**< SAI: TX/RX interrupt */
  SAI1_IRQn                    = 116,              /**< SAI: TX/RX interrupt */
  SAI2_IRQn                    = 117,              /**< SAI: TX/RX interrupt */
  XSPI0_IRQn                   = 118,              /**< xSPI: Ored interrupt */
  XSPI1_IRQn                   = 119,              /**< xSPI: Ored interrupt */
  XSPI2_IRQn                   = 120,              /**< xSPI: Ored interrupt */
  MMU0_IRQn                    = 121,              /**< MMU: Interrupt request */
  MMU1_IRQn                    = 122,              /**< MMU: Interrupt request */
  MMU2_IRQn                    = 123,              /**< MMU: Interrupt request */
  Freqme_IRQn                  = 124,              /**< FREQME: Interrupt request */
  GDET0_IRQn                   = 125,              /**< GDET0: Interrupt request */
  Reserved142_IRQn             = 126,              /**< Reserved interrupt */
  Reserved143_IRQn             = 127,              /**< Reserved interrupt */
  GDET3_IRQn                   = 128,              /**< GDET3: Interrupt request */
  CDOG0_IRQn                   = 129,              /**< CDOG: Interrupt request */
  CDOG1_IRQn                   = 130,              /**< CDOG: Interrupt request */
  CDOG2_IRQn                   = 131,              /**< CDOG: Interrupt request */
  ITRC0_IRQn                   = 132,              /**< ITRC: Interrupt, cleared by software */
  ELS_IRQn                     = 133,              /**< ELS Interrupt request */
  PKC_IRQn                     = 134,              /**< PKC: Public Key Cryptography Interrutp */
  OSCCA_IRQn                   = 135,              /**< OSCCA: OSCCA Interrupt request */
  SLEEPCON0_IRQn               = 136,              /**< WAKEUP: CPU0 wakeup event */
  CPU0_IRQn                    = 137,              /**< CTI0: interrupt request */
  PMC_IRQn                     = 138,              /**< PMC: Compute domain Interrupt */
  JPEGDEC_IRQn                 = 139,              /**< JPEGDEC: Ored Context 0-3 interrupt request */
  PNGDEC_IRQn                  = 140,              /**< PGNDEC: Interrut request */
  NPU_IRQn                     = 141,              /**< NPU: Interrupt request */
  TRNG_IRQn                    = 142,              /**< TRNG: interrupt */
  TEMPDET0_IRQn                = 143,              /**< TEMPDET0: Interrupt request 0 */
  TEMPDET1_IRQn                = 144,              /**< TEMPDET1: Interrupt request 1 */
  EZHV_IRQn                    = 145,              /**< EZH-V: Interrupt request */
  GLIKEY0_IRQn                 = 146,              /**< GLIKEY: Interrupt */
  GLIKEY2_IRQn                 = 147,              /**< GLIKEY: Interrupt */
  GLIKEY3_IRQn                 = 148,              /**< GLIKEY: Interrupt */
  GLIKEY5_IRQn                 = 149,              /**< GLIKEY: Interrupt */
  PVTS0_CPU0_IRQn              = 150,              /**< PVTS0 CPU0 interrupt */
  Reserved167_IRQn             = 151,              /**< Reserved interrupt 167 */
  PVTS0_HIFI4_IRQn             = 152,              /**< PVTS0 HIFI4 interrupt */
  Reserved169_IRQn             = 153,              /**< Reserved interrupt 169 */
  FRO0_IRQn                    = 154,              /**< FRO: 300MHz FRO in VDD2 domain Async interrupt */
  FRO1_IRQn                    = 155,              /**< FRO: 192MHz FRO in VDD2 domain Async interrupt */
  FRO2_IRQn                    = 156,              /**< FRO: 300MHz FRO in VDD1 domain Async interrupt */
  OCOTP_IRQn                   = 157               /**< OCOTP warning and integrity error interrupt */
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
#include "system_MIMXRT798S_cm33_core0.h" /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMXRT798S_cm33_core0_SERIES
#define MIMXRT798S_cm33_core0_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMXRT798S_cm33_core0_features.h"

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
    kDmaRequestMuxXspi0Rx           = 2U,          /**< XSPI0 Receive */
    kDmaRequestMuxXspi0Tx           = 3U,          /**< XSPI0 Transmit */
    kDmaRequestMuxXspi1Rx           = 4U,          /**< XSPI1 Receive */
    kDmaRequestMuxXspi1Tx           = 5U,          /**< XSPI1 Transmit */
    kDmaRequestMuxXspi2Rx           = 6U,          /**< XSPI2 Receive */
    kDmaRequestMuxXspi2Tx           = 7U,          /**< XSPI2 Transmit */
    kDmaRequestMuxPinInt0           = 8U,          /**< PINT INT0 */
    kDmaRequestMuxPinInt1           = 9U,          /**< PINT INT1 */
    kDmaRequestMuxPinInt2           = 10U,         /**< PINT INT2 */
    kDmaRequestMuxPinInt3           = 11U,         /**< PINT INT3 */
    kDmaRequestMuxPinInt4           = 12U,         /**< PINT INT4 */
    kDmaRequestMuxPinInt5           = 13U,         /**< PINT INT5 */
    kDmaRequestMuxPinInt6           = 14U,         /**< PINT INT6 */
    kDmaRequestMuxPinInt7           = 15U,         /**< PINT INT7 */
    kDmaRequestMuxCtimer0M0         = 16U,         /**< CTIMER0 Match channel 0 request */
    kDmaRequestMuxCtimer0M1         = 17U,         /**< CTIMER0 Match channel 1 request */
    kDmaRequestMuxCtimer1M0         = 18U,         /**< CTIMER1 Match channel 0 request */
    kDmaRequestMuxCtimer1M1         = 19U,         /**< CTIMER1 Match channel 1 request */
    kDmaRequestMuxCtimer2M0         = 20U,         /**< CTIMER2 Match channel 0 request */
    kDmaRequestMuxCtimer2M1         = 21U,         /**< CTIMER2 Match channel 1 request */
    kDmaRequestMuxCtimer3M0         = 22U,         /**< CTIMER3 Match channel 0 request */
    kDmaRequestMuxCtimer3M1         = 23U,         /**< CTIMER3 Match channel 1 request */
    kDmaRequestMuxCtimer4M0         = 24U,         /**< CTIMER4 Match channel 0 request */
    kDmaRequestMuxCtimer4M1         = 25U,         /**< CTIMER4 Match channel 1 request */
    kDmaRequestMuxSct0Dma0          = 26U,         /**< SCT0 DMA0 */
    kDmaRequestMuxSct0Dma1          = 27U,         /**< SCT0 DMA1 */
    kDmaRequestMuxAdc0FifoARequest  = 28U,         /**< ADC0 FIFO A request */
    kDmaRequestMuxAdc0FifoBRequest  = 29U,         /**< ADC0 FIFO B request */
    kDmaRequestMuxSdAdcFifo0Request = 30U,         /**< SDADC0 FIFO 0 request */
    kDmaRequestMuxSdAdcFifo1Request = 31U,         /**< SDADC0 FIFO 1 request */
    kDmaRequestMuxSdAdcFifo2Request = 32U,         /**< SDADC0 FIFO 2 request */
    kDmaRequestMuxSdAdcFifo3Request = 33U,         /**< SDADC0 FIFO 3 request */
    kDmaRequestMuxCmpDmaRequest     = 34U,         /**< CMP DMA request */
    kDmaRequestMuxItrc0TmprOut0     = 35U,         /**< ITRC0 TMPR_OUT0 */
    kDmaRequestMuxItrc0TmprOut1     = 36U,         /**< ITRC0 TMPR_OUT1 */
    kDmaRequestMuxFlexIO0ShiftRegister0Request = 37U, /**< FlexIO0 Shifter0 Status DMA request OR Timer0 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister1Request = 38U, /**< FlexIO0 Shifter1 Status DMA request OR Timer1 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister2Request = 39U, /**< FlexIO0 Shifter2 Status DMA request OR Timer2 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister3Request = 40U, /**< FlexIO0 Shifter3 Status DMA request OR Timer3 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister4Request = 41U, /**< FlexIO0 Shifter4 Status DMA request OR Timer4 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister5Request = 42U, /**< FlexIO0 Shifter5 Status DMA request OR Timer5 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister6Request = 43U, /**< FlexIO0 Shifter6 Status DMA request OR Timer6 Status DMA request */
    kDmaRequestMuxFlexIO0ShiftRegister7Request = 44U, /**< FlexIO0 Shifter7 Status DMA request OR Timer7 Status DMA request */
    kDmaRequestMuxLpFlexcomm0Rx     = 45U,         /**< LP_FLEXCOMM0 Receive request */
    kDmaRequestMuxLpFlexcomm0Tx     = 46U,         /**< LP_FLEXCOMM0 Transmit request */
    kDmaRequestMuxLpFlexcomm1Rx     = 47U,         /**< LP_FLEXCOMM1 Receive request */
    kDmaRequestMuxLpFlexcomm1Tx     = 48U,         /**< LP_FLEXCOMM1 Transmit request */
    kDmaRequestMuxLpFlexcomm2Rx     = 49U,         /**< LP_FLEXCOMM2 Receive request */
    kDmaRequestMuxLpFlexcomm2Tx     = 50U,         /**< LP_FLEXCOMM2 Transmit request */
    kDmaRequestMuxLpFlexcomm3Rx     = 51U,         /**< LP_FLEXCOMM3 Receive request */
    kDmaRequestMuxLpFlexcomm3Tx     = 52U,         /**< LP_FLEXCOMM3 Transmit request */
    kDmaRequestMuxLpFlexcomm4Rx     = 53U,         /**< LP_FLEXCOMM4 Receive request */
    kDmaRequestMuxLpFlexcomm4Tx     = 54U,         /**< LP_FLEXCOMM4 Transmit request */
    kDmaRequestMuxLpFlexcomm5Rx     = 55U,         /**< LP_FLEXCOMM5 Receive request */
    kDmaRequestMuxLpFlexcomm5Tx     = 56U,         /**< LP_FLEXCOMM5 Transmit request */
    kDmaRequestMuxLpFlexcomm6Rx     = 57U,         /**< LP_FLEXCOMM6 Receive request */
    kDmaRequestMuxLpFlexcomm6Tx     = 58U,         /**< LP_FLEXCOMM6 Transmit request */
    kDmaRequestMuxLpFlexcomm7Rx     = 59U,         /**< LP_FLEXCOMM7 Receive request */
    kDmaRequestMuxLpFlexcomm7Tx     = 60U,         /**< LP_FLEXCOMM7 Transmit request */
    kDmaRequestMuxLpFlexcomm8Rx     = 61U,         /**< LP_FLEXCOMM8 Receive request */
    kDmaRequestMuxLpFlexcomm8Tx     = 62U,         /**< LP_FLEXCOMM8 Transmit request */
    kDmaRequestMuxLpFlexcomm9Rx     = 63U,         /**< LP_FLEXCOMM9 Receive request */
    kDmaRequestMuxLpFlexcomm9Tx     = 64U,         /**< LP_FLEXCOMM9 Transmit request */
    kDmaRequestMuxLpFlexcomm10Rx    = 65U,         /**< LP_FLEXCOMM10 Receive request */
    kDmaRequestMuxLpFlexcomm10Tx    = 66U,         /**< LP_FLEXCOMM10 Transmit request */
    kDmaRequestMuxLpFlexcomm11Rx    = 67U,         /**< LP_FLEXCOMM11 Receive request */
    kDmaRequestMuxLpFlexcomm11Tx    = 68U,         /**< LP_FLEXCOMM11 Transmit request */
    kDmaRequestMuxLpFlexcomm12Rx    = 69U,         /**< LP_FLEXCOMM12 Receive request */
    kDmaRequestMuxLpFlexcomm12Tx    = 70U,         /**< LP_FLEXCOMM12 Transmit request */
    kDmaRequestMuxLpFlexcomm13Rx    = 71U,         /**< LP_FLEXCOMM13 Receive request */
    kDmaRequestMuxLpFlexcomm13Tx    = 72U,         /**< LP_FLEXCOMM13 Transmit request */
    kDmaRequestMuxLpspi14Rx         = 73U,         /**< LPSPI14 Receive request */
    kDmaRequestMuxLpspi14Tx         = 74U,         /**< LPSPI14 Transmit request */
    kDmaRequestMuxLpspi16Rx         = 75U,         /**< LPSPI16 Receive request */
    kDmaRequestMuxLpspi16Tx         = 76U,         /**< LPSPI16 Transmit request */
    kDmaRequestMuxI3c0Tx            = 77U,         /**< I3C0 Transmit request */
    kDmaRequestMuxI3c0Rx            = 78U,         /**< I3C0 Receive request */
    kDmaRequestMuxI3c1Tx            = 79U,         /**< I3C1 Transmit request */
    kDmaRequestMuxI3c1Rx            = 80U,         /**< I3C1 Receive request */
    kDmaRequestMuxSai0Rx            = 81U,         /**< SAI0 Receive request */
    kDmaRequestMuxSai0Tx            = 82U,         /**< SAI0 Transmit request */
    kDmaRequestMuxSai1Rx            = 83U,         /**< SAI1 Receive request */
    kDmaRequestMuxSai1Tx            = 84U,         /**< SAI1 Transmit request */
    kDmaRequestMuxSai2Rx            = 85U,         /**< SAI2 Receive request */
    kDmaRequestMuxSai2Tx            = 86U,         /**< SAI2 Transmit request */
    kDmaRequestMuxGpio0PinEventRequest0 = 87U,     /**< GPIO0 Pin event request 0 */
    kDmaRequestMuxGpio0PinEventRequest1 = 88U,     /**< GPIO0 Pin event request 1 */
    kDmaRequestMuxGpio1PinEventRequest0 = 89U,     /**< GPIO1 Pin event request 0 */
    kDmaRequestMuxGpio1PinEventRequest1 = 90U,     /**< GPIO1 Pin event request 1 */
    kDmaRequestMuxGpio2PinEventRequest0 = 91U,     /**< GPIO2 Pin event request 0 */
    kDmaRequestMuxGpio2PinEventRequest1 = 92U,     /**< GPIO2 Pin event request 1 */
    kDmaRequestMuxGpio3PinEventRequest0 = 93U,     /**< GPIO3 Pin event request 0 */
    kDmaRequestMuxGpio3PinEventRequest1 = 94U,     /**< GPIO3 Pin event request 1 */
    kDmaRequestMuxGpio4PinEventRequest0 = 95U,     /**< GPIO4 Pin event request 0 */
    kDmaRequestMuxGpio4PinEventRequest1 = 96U,     /**< GPIO4 Pin event request 1 */
    kDmaRequestMuxGpio5PinEventRequest0 = 97U,     /**< GPIO5 Pin event request 0 */
    kDmaRequestMuxGpio5PinEventRequest1 = 98U,     /**< GPIO5 Pin event request 1 */
    kDmaRequestMuxGpio6PinEventRequest0 = 99U,     /**< GPIO6 Pin event request 0 */
    kDmaRequestMuxGpio6PinEventRequest1 = 100U,    /**< GPIO6 Pin event request 1 */
    kDmaRequestMuxGpio7PinEventRequest0 = 101U,    /**< GPIO7 Pin event request 0 */
    kDmaRequestMuxGpio7PinEventRequest1 = 102U,    /**< GPIO7 Pin event request 1 */
    kDmaRequestMuxLpi2c15Rx         = 103U,        /**< LPI2C15 receive request */
    kDmaRequestMuxLpi2c15Tx         = 104U,        /**< LPI2C15 transmit request */
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

/* AHBSC0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AHBSC0 base address */
  #define AHBSC0_BASE                              (0x5017C000u)
  /** Peripheral AHBSC0 base address */
  #define AHBSC0_BASE_NS                           (0x4017C000u)
  /** Peripheral AHBSC0 base pointer */
  #define AHBSC0                                   ((AHBSC0_Type *)AHBSC0_BASE)
  /** Peripheral AHBSC0 base pointer */
  #define AHBSC0_NS                                ((AHBSC0_Type *)AHBSC0_BASE_NS)
  /** Peripheral AHBSC0_ALIAS1 base address */
  #define AHBSC0_ALIAS1_BASE                       (0x5017D000u)
  /** Peripheral AHBSC0_ALIAS1 base address */
  #define AHBSC0_ALIAS1_BASE_NS                    (0x4017D000u)
  /** Peripheral AHBSC0_ALIAS1 base pointer */
  #define AHBSC0_ALIAS1                            ((AHBSC0_Type *)AHBSC0_ALIAS1_BASE)
  /** Peripheral AHBSC0_ALIAS1 base pointer */
  #define AHBSC0_ALIAS1_NS                         ((AHBSC0_Type *)AHBSC0_ALIAS1_BASE_NS)
  /** Peripheral AHBSC0_ALIAS2 base address */
  #define AHBSC0_ALIAS2_BASE                       (0x5017E000u)
  /** Peripheral AHBSC0_ALIAS2 base address */
  #define AHBSC0_ALIAS2_BASE_NS                    (0x4017E000u)
  /** Peripheral AHBSC0_ALIAS2 base pointer */
  #define AHBSC0_ALIAS2                            ((AHBSC0_Type *)AHBSC0_ALIAS2_BASE)
  /** Peripheral AHBSC0_ALIAS2 base pointer */
  #define AHBSC0_ALIAS2_NS                         ((AHBSC0_Type *)AHBSC0_ALIAS2_BASE_NS)
  /** Peripheral AHBSC0_ALIAS3 base address */
  #define AHBSC0_ALIAS3_BASE                       (0x5017F000u)
  /** Peripheral AHBSC0_ALIAS3 base address */
  #define AHBSC0_ALIAS3_BASE_NS                    (0x4017F000u)
  /** Peripheral AHBSC0_ALIAS3 base pointer */
  #define AHBSC0_ALIAS3                            ((AHBSC0_Type *)AHBSC0_ALIAS3_BASE)
  /** Peripheral AHBSC0_ALIAS3 base pointer */
  #define AHBSC0_ALIAS3_NS                         ((AHBSC0_Type *)AHBSC0_ALIAS3_BASE_NS)
  /** Array initializer of AHBSC0 peripheral base addresses */
  #define AHBSC0_BASE_ADDRS                        { AHBSC0_BASE, AHBSC0_ALIAS1_BASE, AHBSC0_ALIAS2_BASE, AHBSC0_ALIAS3_BASE }
  /** Array initializer of AHBSC0 peripheral base pointers */
  #define AHBSC0_BASE_PTRS                         { AHBSC0, AHBSC0_ALIAS1, AHBSC0_ALIAS2, AHBSC0_ALIAS3 }
  /** Array initializer of AHBSC0 peripheral base addresses */
  #define AHBSC0_BASE_ADDRS_NS                     { AHBSC0_BASE_NS, AHBSC0_ALIAS1_BASE_NS, AHBSC0_ALIAS2_BASE_NS, AHBSC0_ALIAS3_BASE_NS }
  /** Array initializer of AHBSC0 peripheral base pointers */
  #define AHBSC0_BASE_PTRS_NS                      { AHBSC0_NS, AHBSC0_ALIAS1_NS, AHBSC0_ALIAS2_NS, AHBSC0_ALIAS3_NS }
#else
  /** Peripheral AHBSC0 base address */
  #define AHBSC0_BASE                              (0x4017C000u)
  /** Peripheral AHBSC0 base pointer */
  #define AHBSC0                                   ((AHBSC0_Type *)AHBSC0_BASE)
  /** Peripheral AHBSC0_ALIAS1 base address */
  #define AHBSC0_ALIAS1_BASE                       (0x4017D000u)
  /** Peripheral AHBSC0_ALIAS1 base pointer */
  #define AHBSC0_ALIAS1                            ((AHBSC0_Type *)AHBSC0_ALIAS1_BASE)
  /** Peripheral AHBSC0_ALIAS2 base address */
  #define AHBSC0_ALIAS2_BASE                       (0x4017E000u)
  /** Peripheral AHBSC0_ALIAS2 base pointer */
  #define AHBSC0_ALIAS2                            ((AHBSC0_Type *)AHBSC0_ALIAS2_BASE)
  /** Peripheral AHBSC0_ALIAS3 base address */
  #define AHBSC0_ALIAS3_BASE                       (0x4017F000u)
  /** Peripheral AHBSC0_ALIAS3 base pointer */
  #define AHBSC0_ALIAS3                            ((AHBSC0_Type *)AHBSC0_ALIAS3_BASE)
  /** Array initializer of AHBSC0 peripheral base addresses */
  #define AHBSC0_BASE_ADDRS                        { AHBSC0_BASE, AHBSC0_ALIAS1_BASE, AHBSC0_ALIAS2_BASE, AHBSC0_ALIAS3_BASE }
  /** Array initializer of AHBSC0 peripheral base pointers */
  #define AHBSC0_BASE_PTRS                         { AHBSC0, AHBSC0_ALIAS1, AHBSC0_ALIAS2, AHBSC0_ALIAS3 }
#endif

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

/* CACHE64_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CACHE64_CTRL0 base address */
  #define CACHE64_CTRL0_BASE                       (0x50035000u)
  /** Peripheral CACHE64_CTRL0 base address */
  #define CACHE64_CTRL0_BASE_NS                    (0x40035000u)
  /** Peripheral CACHE64_CTRL0 base pointer */
  #define CACHE64_CTRL0                            ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE)
  /** Peripheral CACHE64_CTRL0 base pointer */
  #define CACHE64_CTRL0_NS                         ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE_NS)
  /** Peripheral CACHE64_CTRL1 base address */
  #define CACHE64_CTRL1_BASE                       (0x50036000u)
  /** Peripheral CACHE64_CTRL1 base address */
  #define CACHE64_CTRL1_BASE_NS                    (0x40036000u)
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
  #define CACHE64_CTRL0_BASE                       (0x40035000u)
  /** Peripheral CACHE64_CTRL0 base pointer */
  #define CACHE64_CTRL0                            ((CACHE64_CTRL_Type *)CACHE64_CTRL0_BASE)
  /** Peripheral CACHE64_CTRL1 base address */
  #define CACHE64_CTRL1_BASE                       (0x40036000u)
  /** Peripheral CACHE64_CTRL1 base pointer */
  #define CACHE64_CTRL1                            ((CACHE64_CTRL_Type *)CACHE64_CTRL1_BASE)
  /** Array initializer of CACHE64_CTRL peripheral base addresses */
  #define CACHE64_CTRL_BASE_ADDRS                  { CACHE64_CTRL0_BASE, CACHE64_CTRL1_BASE }
  /** Array initializer of CACHE64_CTRL peripheral base pointers */
  #define CACHE64_CTRL_BASE_PTRS                   { CACHE64_CTRL0, CACHE64_CTRL1 }
#endif
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** CACHE64_CTRL physical memory base address */
 #define CACHE64_CTRL_PHYMEM_BASES                { 0x38000000u, 0x18000000u }
/** CACHE64_CTRL physical memory size */
 #define CACHE64_CTRL_PHYMEM_SIZES                { 0x08000000u, 0x08000000u }
/** CACHE64_CTRL physical memory base address */
 #define CACHE64_CTRL_PHYMEM_BASES_NS             { 0x28000000u, 0x08000000u }
/** CACHE64_CTRL physical memory size */
 #define CACHE64_CTRL_PHYMEM_SIZES_NS             { 0x08000000u, 0x08000000u }
#else
/** CACHE64_CTRL physical memory base address */
 #define CACHE64_CTRL_PHYMEM_BASES                { 0x28000000u, 0x08000000u }
/** CACHE64_CTRL physical memory size */
 #define CACHE64_CTRL_PHYMEM_SIZES                { 0x08000000u, 0x08000000u }
#endif
/* Backward compatibility */
#define CACHE64_CTRL_CSAR_PHYADDR_MASK (CACHE64_CTRL_CSAR_PHYADDR27_1_MASK | CACHE64_CTRL_CSAR_PHYADDR31_29_MASK)


/* CACHE64_POLSEL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CACHE64_POLSEL0 base address */
  #define CACHE64_POLSEL0_BASE                     (0x50035000u)
  /** Peripheral CACHE64_POLSEL0 base address */
  #define CACHE64_POLSEL0_BASE_NS                  (0x40035000u)
  /** Peripheral CACHE64_POLSEL0 base pointer */
  #define CACHE64_POLSEL0                          ((CACHE64_POLSEL_Type *)CACHE64_POLSEL0_BASE)
  /** Peripheral CACHE64_POLSEL0 base pointer */
  #define CACHE64_POLSEL0_NS                       ((CACHE64_POLSEL_Type *)CACHE64_POLSEL0_BASE_NS)
  /** Peripheral CACHE64_POLSEL1 base address */
  #define CACHE64_POLSEL1_BASE                     (0x50036000u)
  /** Peripheral CACHE64_POLSEL1 base address */
  #define CACHE64_POLSEL1_BASE_NS                  (0x40036000u)
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
  #define CACHE64_POLSEL0_BASE                     (0x40035000u)
  /** Peripheral CACHE64_POLSEL0 base pointer */
  #define CACHE64_POLSEL0                          ((CACHE64_POLSEL_Type *)CACHE64_POLSEL0_BASE)
  /** Peripheral CACHE64_POLSEL1 base address */
  #define CACHE64_POLSEL1_BASE                     (0x40036000u)
  /** Peripheral CACHE64_POLSEL1 base pointer */
  #define CACHE64_POLSEL1                          ((CACHE64_POLSEL_Type *)CACHE64_POLSEL1_BASE)
  /** Array initializer of CACHE64_POLSEL peripheral base addresses */
  #define CACHE64_POLSEL_BASE_ADDRS                { CACHE64_POLSEL0_BASE, CACHE64_POLSEL1_BASE }
  /** Array initializer of CACHE64_POLSEL peripheral base pointers */
  #define CACHE64_POLSEL_BASE_PTRS                 { CACHE64_POLSEL0, CACHE64_POLSEL1 }
#endif

/* CDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CDOG0 base address */
  #define CDOG0_BASE                               (0x50115000u)
  /** Peripheral CDOG0 base address */
  #define CDOG0_BASE_NS                            (0x40115000u)
  /** Peripheral CDOG0 base pointer */
  #define CDOG0                                    ((CDOG_Type *)CDOG0_BASE)
  /** Peripheral CDOG0 base pointer */
  #define CDOG0_NS                                 ((CDOG_Type *)CDOG0_BASE_NS)
  /** Peripheral CDOG1 base address */
  #define CDOG1_BASE                               (0x50116000u)
  /** Peripheral CDOG1 base address */
  #define CDOG1_BASE_NS                            (0x40116000u)
  /** Peripheral CDOG1 base pointer */
  #define CDOG1                                    ((CDOG_Type *)CDOG1_BASE)
  /** Peripheral CDOG1 base pointer */
  #define CDOG1_NS                                 ((CDOG_Type *)CDOG1_BASE_NS)
  /** Peripheral CDOG2 base address */
  #define CDOG2_BASE                               (0x50117000u)
  /** Peripheral CDOG2 base address */
  #define CDOG2_BASE_NS                            (0x40117000u)
  /** Peripheral CDOG2 base pointer */
  #define CDOG2                                    ((CDOG_Type *)CDOG2_BASE)
  /** Peripheral CDOG2 base pointer */
  #define CDOG2_NS                                 ((CDOG_Type *)CDOG2_BASE_NS)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { CDOG0_BASE, CDOG1_BASE, CDOG2_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { CDOG0, CDOG1, CDOG2 }
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS_NS                       { CDOG0_BASE_NS, CDOG1_BASE_NS, CDOG2_BASE_NS }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS_NS                        { CDOG0_NS, CDOG1_NS, CDOG2_NS }
#else
  /** Peripheral CDOG0 base address */
  #define CDOG0_BASE                               (0x40115000u)
  /** Peripheral CDOG0 base pointer */
  #define CDOG0                                    ((CDOG_Type *)CDOG0_BASE)
  /** Peripheral CDOG1 base address */
  #define CDOG1_BASE                               (0x40116000u)
  /** Peripheral CDOG1 base pointer */
  #define CDOG1                                    ((CDOG_Type *)CDOG1_BASE)
  /** Peripheral CDOG2 base address */
  #define CDOG2_BASE                               (0x40117000u)
  /** Peripheral CDOG2 base pointer */
  #define CDOG2                                    ((CDOG_Type *)CDOG2_BASE)
  /** Array initializer of CDOG peripheral base addresses */
  #define CDOG_BASE_ADDRS                          { CDOG0_BASE, CDOG1_BASE, CDOG2_BASE }
  /** Array initializer of CDOG peripheral base pointers */
  #define CDOG_BASE_PTRS                           { CDOG0, CDOG1, CDOG2 }
#endif
/** Interrupt vectors for the CDOG peripheral type */
#define CDOG_IRQS                                { CDOG0_IRQn, CDOG1_IRQn, CDOG2_IRQn }

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

/* CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CRC base address */
  #define CRC_BASE                                 (0x50151000u)
  /** Peripheral CRC base address */
  #define CRC_BASE_NS                              (0x40151000u)
  /** Peripheral CRC base pointer */
  #define CRC                                      ((CRC_Type *)CRC_BASE)
  /** Peripheral CRC base pointer */
  #define CRC_NS                                   ((CRC_Type *)CRC_BASE_NS)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC }
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS_NS                        { CRC_BASE_NS }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS_NS                         { CRC_NS }
#else
  /** Peripheral CRC base address */
  #define CRC_BASE                                 (0x40151000u)
  /** Peripheral CRC base pointer */
  #define CRC                                      ((CRC_Type *)CRC_BASE)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { CRC_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC }
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

/* DEBUG_MAILBOX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DEBUG_MAILBOX base address */
  #define DEBUG_MAILBOX_BASE                       (0x50198000u)
  /** Peripheral DEBUG_MAILBOX base address */
  #define DEBUG_MAILBOX_BASE_NS                    (0x40198000u)
  /** Peripheral DEBUG_MAILBOX base pointer */
  #define DEBUG_MAILBOX                            ((DEBUG_MAILBOX_Type *)DEBUG_MAILBOX_BASE)
  /** Peripheral DEBUG_MAILBOX base pointer */
  #define DEBUG_MAILBOX_NS                         ((DEBUG_MAILBOX_Type *)DEBUG_MAILBOX_BASE_NS)
  /** Array initializer of DEBUG_MAILBOX peripheral base addresses */
  #define DEBUG_MAILBOX_BASE_ADDRS                 { DEBUG_MAILBOX_BASE }
  /** Array initializer of DEBUG_MAILBOX peripheral base pointers */
  #define DEBUG_MAILBOX_BASE_PTRS                  { DEBUG_MAILBOX }
  /** Array initializer of DEBUG_MAILBOX peripheral base addresses */
  #define DEBUG_MAILBOX_BASE_ADDRS_NS              { DEBUG_MAILBOX_BASE_NS }
  /** Array initializer of DEBUG_MAILBOX peripheral base pointers */
  #define DEBUG_MAILBOX_BASE_PTRS_NS               { DEBUG_MAILBOX_NS }
#else
  /** Peripheral DEBUG_MAILBOX base address */
  #define DEBUG_MAILBOX_BASE                       (0x40198000u)
  /** Peripheral DEBUG_MAILBOX base pointer */
  #define DEBUG_MAILBOX                            ((DEBUG_MAILBOX_Type *)DEBUG_MAILBOX_BASE)
  /** Array initializer of DEBUG_MAILBOX peripheral base addresses */
  #define DEBUG_MAILBOX_BASE_ADDRS                 { DEBUG_MAILBOX_BASE }
  /** Array initializer of DEBUG_MAILBOX peripheral base pointers */
  #define DEBUG_MAILBOX_BASE_PTRS                  { DEBUG_MAILBOX }
#endif

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA0 base address */
  #define DMA0_BASE                                (0x50140000u)
  /** Peripheral DMA0 base address */
  #define DMA0_BASE_NS                             (0x40140000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Peripheral DMA0 base pointer */
  #define DMA0_NS                                  ((DMA_Type *)DMA0_BASE_NS)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE                                (0x50160000u)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE_NS                             (0x40160000u)
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
  #define DMA0_BASE                                (0x40140000u)
  /** Peripheral DMA0 base pointer */
  #define DMA0                                     ((DMA_Type *)DMA0_BASE)
  /** Peripheral DMA1 base address */
  #define DMA1_BASE                                (0x40160000u)
  /** Peripheral DMA1 base pointer */
  #define DMA1                                     ((DMA_Type *)DMA1_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA0_BASE, DMA1_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA0, DMA1 }
#endif
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { EDMA0_CH0_IRQn, EDMA0_CH1_IRQn, EDMA0_CH2_IRQn, EDMA0_CH3_IRQn, EDMA0_CH4_IRQn, EDMA0_CH5_IRQn, EDMA0_CH6_IRQn, EDMA0_CH7_IRQn, EDMA0_CH8_IRQn, EDMA0_CH9_IRQn, EDMA0_CH10_IRQn, EDMA0_CH11_IRQn, EDMA0_CH12_IRQn, EDMA0_CH13_IRQn, EDMA0_CH14_IRQn, EDMA0_CH15_IRQn }, \
                                                   { EDMA1_CH0_IRQn, EDMA1_CH1_IRQn, EDMA1_CH2_IRQn, EDMA1_CH3_IRQn, EDMA1_CH4_IRQn, EDMA1_CH5_IRQn, EDMA1_CH6_IRQn, EDMA1_CH7_IRQn, EDMA1_CH8_IRQn, EDMA1_CH9_IRQn, EDMA1_CH10_IRQn, EDMA1_CH11_IRQn, EDMA1_CH12_IRQn, EDMA1_CH13_IRQn, EDMA1_CH14_IRQn, EDMA1_CH15_IRQn } }

/* ELS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ELS base address */
  #define ELS_BASE                                 (0x50190000u)
  /** Peripheral ELS base address */
  #define ELS_BASE_NS                              (0x40190000u)
  /** Peripheral ELS base pointer */
  #define ELS                                      ((ELS_Type *)ELS_BASE)
  /** Peripheral ELS base pointer */
  #define ELS_NS                                   ((ELS_Type *)ELS_BASE_NS)
  /** Peripheral ELS_ALIAS1 base address */
  #define ELS_ALIAS1_BASE                          (0x50191000u)
  /** Peripheral ELS_ALIAS1 base address */
  #define ELS_ALIAS1_BASE_NS                       (0x40191000u)
  /** Peripheral ELS_ALIAS1 base pointer */
  #define ELS_ALIAS1                               ((ELS_Type *)ELS_ALIAS1_BASE)
  /** Peripheral ELS_ALIAS1 base pointer */
  #define ELS_ALIAS1_NS                            ((ELS_Type *)ELS_ALIAS1_BASE_NS)
  /** Peripheral ELS_ALIAS2 base address */
  #define ELS_ALIAS2_BASE                          (0x50192000u)
  /** Peripheral ELS_ALIAS2 base address */
  #define ELS_ALIAS2_BASE_NS                       (0x40192000u)
  /** Peripheral ELS_ALIAS2 base pointer */
  #define ELS_ALIAS2                               ((ELS_Type *)ELS_ALIAS2_BASE)
  /** Peripheral ELS_ALIAS2 base pointer */
  #define ELS_ALIAS2_NS                            ((ELS_Type *)ELS_ALIAS2_BASE_NS)
  /** Peripheral ELS_ALIAS3 base address */
  #define ELS_ALIAS3_BASE                          (0x50193000u)
  /** Peripheral ELS_ALIAS3 base address */
  #define ELS_ALIAS3_BASE_NS                       (0x40193000u)
  /** Peripheral ELS_ALIAS3 base pointer */
  #define ELS_ALIAS3                               ((ELS_Type *)ELS_ALIAS3_BASE)
  /** Peripheral ELS_ALIAS3 base pointer */
  #define ELS_ALIAS3_NS                            ((ELS_Type *)ELS_ALIAS3_BASE_NS)
  /** Array initializer of ELS peripheral base addresses */
  #define ELS_BASE_ADDRS                           { ELS_BASE, ELS_ALIAS1_BASE, ELS_ALIAS2_BASE, ELS_ALIAS3_BASE }
  /** Array initializer of ELS peripheral base pointers */
  #define ELS_BASE_PTRS                            { ELS, ELS_ALIAS1, ELS_ALIAS2, ELS_ALIAS3 }
  /** Array initializer of ELS peripheral base addresses */
  #define ELS_BASE_ADDRS_NS                        { ELS_BASE_NS, ELS_ALIAS1_BASE_NS, ELS_ALIAS2_BASE_NS, ELS_ALIAS3_BASE_NS }
  /** Array initializer of ELS peripheral base pointers */
  #define ELS_BASE_PTRS_NS                         { ELS_NS, ELS_ALIAS1_NS, ELS_ALIAS2_NS, ELS_ALIAS3_NS }
#else
  /** Peripheral ELS base address */
  #define ELS_BASE                                 (0x40190000u)
  /** Peripheral ELS base pointer */
  #define ELS                                      ((ELS_Type *)ELS_BASE)
  /** Peripheral ELS_ALIAS1 base address */
  #define ELS_ALIAS1_BASE                          (0x40191000u)
  /** Peripheral ELS_ALIAS1 base pointer */
  #define ELS_ALIAS1                               ((ELS_Type *)ELS_ALIAS1_BASE)
  /** Peripheral ELS_ALIAS2 base address */
  #define ELS_ALIAS2_BASE                          (0x40192000u)
  /** Peripheral ELS_ALIAS2 base pointer */
  #define ELS_ALIAS2                               ((ELS_Type *)ELS_ALIAS2_BASE)
  /** Peripheral ELS_ALIAS3 base address */
  #define ELS_ALIAS3_BASE                          (0x40193000u)
  /** Peripheral ELS_ALIAS3 base pointer */
  #define ELS_ALIAS3                               ((ELS_Type *)ELS_ALIAS3_BASE)
  /** Array initializer of ELS peripheral base addresses */
  #define ELS_BASE_ADDRS                           { ELS_BASE, ELS_ALIAS1_BASE, ELS_ALIAS2_BASE, ELS_ALIAS3_BASE }
  /** Array initializer of ELS peripheral base pointers */
  #define ELS_BASE_PTRS                            { ELS, ELS_ALIAS1, ELS_ALIAS2, ELS_ALIAS3 }
#endif

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

/* FREQME - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FREQME base address */
  #define FREQME_BASE                              (0x50023000u)
  /** Peripheral FREQME base address */
  #define FREQME_BASE_NS                           (0x40023000u)
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
  #define FREQME_BASE                              (0x40023000u)
  /** Peripheral FREQME base pointer */
  #define FREQME                                   ((FREQME_Type *)FREQME_BASE)
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS                        { FREQME_BASE }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS                         { FREQME }
#endif
/** Interrupt vectors for the FREQME peripheral type */
#define FREQME_IRQS                              { Freqme_IRQn }

/* FRO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FRO0 base address */
  #define FRO0_BASE                                (0x50001100u)
  /** Peripheral FRO0 base address */
  #define FRO0_BASE_NS                             (0x40001100u)
  /** Peripheral FRO0 base pointer */
  #define FRO0                                     ((FRO_Type *)FRO0_BASE)
  /** Peripheral FRO0 base pointer */
  #define FRO0_NS                                  ((FRO_Type *)FRO0_BASE_NS)
  /** Peripheral FRO1 base address */
  #define FRO1_BASE                                (0x50001000u)
  /** Peripheral FRO1 base address */
  #define FRO1_BASE_NS                             (0x40001000u)
  /** Peripheral FRO1 base pointer */
  #define FRO1                                     ((FRO_Type *)FRO1_BASE)
  /** Peripheral FRO1 base pointer */
  #define FRO1_NS                                  ((FRO_Type *)FRO1_BASE_NS)
  /** Peripheral FRO2 base address */
  #define FRO2_BASE                                (0x50061100u)
  /** Peripheral FRO2 base address */
  #define FRO2_BASE_NS                             (0x40061100u)
  /** Peripheral FRO2 base pointer */
  #define FRO2                                     ((FRO_Type *)FRO2_BASE)
  /** Peripheral FRO2 base pointer */
  #define FRO2_NS                                  ((FRO_Type *)FRO2_BASE_NS)
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS                           { FRO0_BASE, FRO1_BASE, FRO2_BASE }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS                            { FRO0, FRO1, FRO2 }
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS_NS                        { FRO0_BASE_NS, FRO1_BASE_NS, FRO2_BASE_NS }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS_NS                         { FRO0_NS, FRO1_NS, FRO2_NS }
#else
  /** Peripheral FRO0 base address */
  #define FRO0_BASE                                (0x40001100u)
  /** Peripheral FRO0 base pointer */
  #define FRO0                                     ((FRO_Type *)FRO0_BASE)
  /** Peripheral FRO1 base address */
  #define FRO1_BASE                                (0x40001000u)
  /** Peripheral FRO1 base pointer */
  #define FRO1                                     ((FRO_Type *)FRO1_BASE)
  /** Peripheral FRO2 base address */
  #define FRO2_BASE                                (0x40061100u)
  /** Peripheral FRO2 base pointer */
  #define FRO2                                     ((FRO_Type *)FRO2_BASE)
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS                           { FRO0_BASE, FRO1_BASE, FRO2_BASE }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS                            { FRO0, FRO1, FRO2 }
#endif

/* GDET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GDET0 base address */
  #define GDET0_BASE                               (0x50013000u)
  /** Peripheral GDET0 base address */
  #define GDET0_BASE_NS                            (0x40013000u)
  /** Peripheral GDET0 base pointer */
  #define GDET0                                    ((GDET_Type *)GDET0_BASE)
  /** Peripheral GDET0 base pointer */
  #define GDET0_NS                                 ((GDET_Type *)GDET0_BASE_NS)
  /** Peripheral GDET3 base address */
  #define GDET3_BASE                               (0x5006B000u)
  /** Peripheral GDET3 base address */
  #define GDET3_BASE_NS                            (0x4006B000u)
  /** Peripheral GDET3 base pointer */
  #define GDET3                                    ((GDET_Type *)GDET3_BASE)
  /** Peripheral GDET3 base pointer */
  #define GDET3_NS                                 ((GDET_Type *)GDET3_BASE_NS)
  /** Array initializer of GDET peripheral base addresses */
  #define GDET_BASE_ADDRS                          { GDET0_BASE, 0u, 0u, GDET3_BASE }
  /** Array initializer of GDET peripheral base pointers */
  #define GDET_BASE_PTRS                           { GDET0, (GDET_Type *)0u, (GDET_Type *)0u, GDET3 }
  /** Array initializer of GDET peripheral base addresses */
  #define GDET_BASE_ADDRS_NS                       { GDET0_BASE_NS, 0u, 0u, GDET3_BASE_NS }
  /** Array initializer of GDET peripheral base pointers */
  #define GDET_BASE_PTRS_NS                        { GDET0_NS, (GDET_Type *)0u, (GDET_Type *)0u, GDET3_NS }
#else
  /** Peripheral GDET0 base address */
  #define GDET0_BASE                               (0x40013000u)
  /** Peripheral GDET0 base pointer */
  #define GDET0                                    ((GDET_Type *)GDET0_BASE)
  /** Peripheral GDET3 base address */
  #define GDET3_BASE                               (0x4006B000u)
  /** Peripheral GDET3 base pointer */
  #define GDET3                                    ((GDET_Type *)GDET3_BASE)
  /** Array initializer of GDET peripheral base addresses */
  #define GDET_BASE_ADDRS                          { GDET0_BASE, 0u, 0u, GDET3_BASE }
  /** Array initializer of GDET peripheral base pointers */
  #define GDET_BASE_PTRS                           { GDET0, (GDET_Type *)0u, (GDET_Type *)0u, GDET3 }
#endif
/** Interrupt vectors for the GDET peripheral type */
#define GDET_IRQS                                { GDET0_IRQn, NotAvail_IRQn, NotAvail_IRQn, GDET3_IRQn }

/* GLIKEY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GLIKEY0 base address */
  #define GLIKEY0_BASE                             (0x5017CC00u)
  /** Peripheral GLIKEY0 base address */
  #define GLIKEY0_BASE_NS                          (0x4017CC00u)
  /** Peripheral GLIKEY0 base pointer */
  #define GLIKEY0                                  ((GLIKEY_Type *)GLIKEY0_BASE)
  /** Peripheral GLIKEY0 base pointer */
  #define GLIKEY0_NS                               ((GLIKEY_Type *)GLIKEY0_BASE_NS)
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
  /** Peripheral GLIKEY3 base address */
  #define GLIKEY3_BASE                             (0x50002C00u)
  /** Peripheral GLIKEY3 base address */
  #define GLIKEY3_BASE_NS                          (0x40002C00u)
  /** Peripheral GLIKEY3 base pointer */
  #define GLIKEY3                                  ((GLIKEY_Type *)GLIKEY3_BASE)
  /** Peripheral GLIKEY3 base pointer */
  #define GLIKEY3_NS                               ((GLIKEY_Type *)GLIKEY3_BASE_NS)
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
  #define GLIKEY_BASE_ADDRS                        { GLIKEY0_BASE, GLIKEY1_BASE, GLIKEY2_BASE, GLIKEY3_BASE, GLIKEY4_BASE, GLIKEY5_BASE }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS                         { GLIKEY0, GLIKEY1, GLIKEY2, GLIKEY3, GLIKEY4, GLIKEY5 }
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS_NS                     { GLIKEY0_BASE_NS, GLIKEY1_BASE_NS, GLIKEY2_BASE_NS, GLIKEY3_BASE_NS, GLIKEY4_BASE_NS, GLIKEY5_BASE_NS }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS_NS                      { GLIKEY0_NS, GLIKEY1_NS, GLIKEY2_NS, GLIKEY3_NS, GLIKEY4_NS, GLIKEY5_NS }
#else
  /** Peripheral GLIKEY0 base address */
  #define GLIKEY0_BASE                             (0x4017CC00u)
  /** Peripheral GLIKEY0 base pointer */
  #define GLIKEY0                                  ((GLIKEY_Type *)GLIKEY0_BASE)
  /** Peripheral GLIKEY1 base address */
  #define GLIKEY1_BASE                             (0x40220C00u)
  /** Peripheral GLIKEY1 base pointer */
  #define GLIKEY1                                  ((GLIKEY_Type *)GLIKEY1_BASE)
  /** Peripheral GLIKEY2 base address */
  #define GLIKEY2_BASE                             (0x40400C00u)
  /** Peripheral GLIKEY2 base pointer */
  #define GLIKEY2                                  ((GLIKEY_Type *)GLIKEY2_BASE)
  /** Peripheral GLIKEY3 base address */
  #define GLIKEY3_BASE                             (0x40002C00u)
  /** Peripheral GLIKEY3 base pointer */
  #define GLIKEY3                                  ((GLIKEY_Type *)GLIKEY3_BASE)
  /** Peripheral GLIKEY4 base address */
  #define GLIKEY4_BASE                             (0x40062C00u)
  /** Peripheral GLIKEY4 base pointer */
  #define GLIKEY4                                  ((GLIKEY_Type *)GLIKEY4_BASE)
  /** Peripheral GLIKEY5 base address */
  #define GLIKEY5_BASE                             (0x400A2C00u)
  /** Peripheral GLIKEY5 base pointer */
  #define GLIKEY5                                  ((GLIKEY_Type *)GLIKEY5_BASE)
  /** Array initializer of GLIKEY peripheral base addresses */
  #define GLIKEY_BASE_ADDRS                        { GLIKEY0_BASE, GLIKEY1_BASE, GLIKEY2_BASE, GLIKEY3_BASE, GLIKEY4_BASE, GLIKEY5_BASE }
  /** Array initializer of GLIKEY peripheral base pointers */
  #define GLIKEY_BASE_PTRS                         { GLIKEY0, GLIKEY1, GLIKEY2, GLIKEY3, GLIKEY4, GLIKEY5 }
#endif

/* GPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPIO0 base address */
  #define GPIO0_BASE                               (0x50100000u)
  /** Peripheral GPIO0 base address */
  #define GPIO0_BASE_NS                            (0x40100000u)
  /** Peripheral GPIO0 base pointer */
  #define GPIO0                                    ((GPIO_Type *)GPIO0_BASE)
  /** Peripheral GPIO0 base pointer */
  #define GPIO0_NS                                 ((GPIO_Type *)GPIO0_BASE_NS)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE                               (0x50102000u)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE_NS                            (0x40102000u)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1_NS                                 ((GPIO_Type *)GPIO1_BASE_NS)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE                               (0x50104000u)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE_NS                            (0x40104000u)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2_NS                                 ((GPIO_Type *)GPIO2_BASE_NS)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE                               (0x50106000u)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE_NS                            (0x40106000u)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3_NS                                 ((GPIO_Type *)GPIO3_BASE_NS)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE                               (0x50108000u)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE_NS                            (0x40108000u)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4                                    ((GPIO_Type *)GPIO4_BASE)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4_NS                                 ((GPIO_Type *)GPIO4_BASE_NS)
  /** Peripheral GPIO5 base address */
  #define GPIO5_BASE                               (0x5010A000u)
  /** Peripheral GPIO5 base address */
  #define GPIO5_BASE_NS                            (0x4010A000u)
  /** Peripheral GPIO5 base pointer */
  #define GPIO5                                    ((GPIO_Type *)GPIO5_BASE)
  /** Peripheral GPIO5 base pointer */
  #define GPIO5_NS                                 ((GPIO_Type *)GPIO5_BASE_NS)
  /** Peripheral GPIO6 base address */
  #define GPIO6_BASE                               (0x5010C000u)
  /** Peripheral GPIO6 base address */
  #define GPIO6_BASE_NS                            (0x4010C000u)
  /** Peripheral GPIO6 base pointer */
  #define GPIO6                                    ((GPIO_Type *)GPIO6_BASE)
  /** Peripheral GPIO6 base pointer */
  #define GPIO6_NS                                 ((GPIO_Type *)GPIO6_BASE_NS)
  /** Peripheral GPIO7 base address */
  #define GPIO7_BASE                               (0x5010E000u)
  /** Peripheral GPIO7 base address */
  #define GPIO7_BASE_NS                            (0x4010E000u)
  /** Peripheral GPIO7 base pointer */
  #define GPIO7                                    ((GPIO_Type *)GPIO7_BASE)
  /** Peripheral GPIO7 base pointer */
  #define GPIO7_NS                                 ((GPIO_Type *)GPIO7_BASE_NS)
  /** Peripheral GPIO0_ALIAS base address */
  #define GPIO0_ALIAS_BASE                         (0x50101000u)
  /** Peripheral GPIO0_ALIAS base address */
  #define GPIO0_ALIAS_BASE_NS                      (0x40101000u)
  /** Peripheral GPIO0_ALIAS base pointer */
  #define GPIO0_ALIAS                              ((GPIO_Type *)GPIO0_ALIAS_BASE)
  /** Peripheral GPIO0_ALIAS base pointer */
  #define GPIO0_ALIAS_NS                           ((GPIO_Type *)GPIO0_ALIAS_BASE_NS)
  /** Peripheral GPIO1_ALIAS base address */
  #define GPIO1_ALIAS_BASE                         (0x50103000u)
  /** Peripheral GPIO1_ALIAS base address */
  #define GPIO1_ALIAS_BASE_NS                      (0x40103000u)
  /** Peripheral GPIO1_ALIAS base pointer */
  #define GPIO1_ALIAS                              ((GPIO_Type *)GPIO1_ALIAS_BASE)
  /** Peripheral GPIO1_ALIAS base pointer */
  #define GPIO1_ALIAS_NS                           ((GPIO_Type *)GPIO1_ALIAS_BASE_NS)
  /** Peripheral GPIO2_ALIAS base address */
  #define GPIO2_ALIAS_BASE                         (0x50105000u)
  /** Peripheral GPIO2_ALIAS base address */
  #define GPIO2_ALIAS_BASE_NS                      (0x40105000u)
  /** Peripheral GPIO2_ALIAS base pointer */
  #define GPIO2_ALIAS                              ((GPIO_Type *)GPIO2_ALIAS_BASE)
  /** Peripheral GPIO2_ALIAS base pointer */
  #define GPIO2_ALIAS_NS                           ((GPIO_Type *)GPIO2_ALIAS_BASE_NS)
  /** Peripheral GPIO3_ALIAS base address */
  #define GPIO3_ALIAS_BASE                         (0x50107000u)
  /** Peripheral GPIO3_ALIAS base address */
  #define GPIO3_ALIAS_BASE_NS                      (0x40107000u)
  /** Peripheral GPIO3_ALIAS base pointer */
  #define GPIO3_ALIAS                              ((GPIO_Type *)GPIO3_ALIAS_BASE)
  /** Peripheral GPIO3_ALIAS base pointer */
  #define GPIO3_ALIAS_NS                           ((GPIO_Type *)GPIO3_ALIAS_BASE_NS)
  /** Peripheral GPIO4_ALIAS base address */
  #define GPIO4_ALIAS_BASE                         (0x50109000u)
  /** Peripheral GPIO4_ALIAS base address */
  #define GPIO4_ALIAS_BASE_NS                      (0x40109000u)
  /** Peripheral GPIO4_ALIAS base pointer */
  #define GPIO4_ALIAS                              ((GPIO_Type *)GPIO4_ALIAS_BASE)
  /** Peripheral GPIO4_ALIAS base pointer */
  #define GPIO4_ALIAS_NS                           ((GPIO_Type *)GPIO4_ALIAS_BASE_NS)
  /** Peripheral GPIO5_ALIAS base address */
  #define GPIO5_ALIAS_BASE                         (0x5010B000u)
  /** Peripheral GPIO5_ALIAS base address */
  #define GPIO5_ALIAS_BASE_NS                      (0x4010B000u)
  /** Peripheral GPIO5_ALIAS base pointer */
  #define GPIO5_ALIAS                              ((GPIO_Type *)GPIO5_ALIAS_BASE)
  /** Peripheral GPIO5_ALIAS base pointer */
  #define GPIO5_ALIAS_NS                           ((GPIO_Type *)GPIO5_ALIAS_BASE_NS)
  /** Peripheral GPIO6_ALIAS base address */
  #define GPIO6_ALIAS_BASE                         (0x5010D000u)
  /** Peripheral GPIO6_ALIAS base address */
  #define GPIO6_ALIAS_BASE_NS                      (0x4010D000u)
  /** Peripheral GPIO6_ALIAS base pointer */
  #define GPIO6_ALIAS                              ((GPIO_Type *)GPIO6_ALIAS_BASE)
  /** Peripheral GPIO6_ALIAS base pointer */
  #define GPIO6_ALIAS_NS                           ((GPIO_Type *)GPIO6_ALIAS_BASE_NS)
  /** Peripheral GPIO7_ALIAS base address */
  #define GPIO7_ALIAS_BASE                         (0x5010F000u)
  /** Peripheral GPIO7_ALIAS base address */
  #define GPIO7_ALIAS_BASE_NS                      (0x4010F000u)
  /** Peripheral GPIO7_ALIAS base pointer */
  #define GPIO7_ALIAS                              ((GPIO_Type *)GPIO7_ALIAS_BASE)
  /** Peripheral GPIO7_ALIAS base pointer */
  #define GPIO7_ALIAS_NS                           ((GPIO_Type *)GPIO7_ALIAS_BASE_NS)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { GPIO0_BASE, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE, GPIO6_BASE, GPIO7_BASE, 0u, 0u, 0u, GPIO0_ALIAS_BASE, GPIO1_ALIAS_BASE, GPIO2_ALIAS_BASE, GPIO3_ALIAS_BASE, GPIO4_ALIAS_BASE, GPIO5_ALIAS_BASE, GPIO6_ALIAS_BASE, GPIO7_ALIAS_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { GPIO0, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5, GPIO6, GPIO7, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, GPIO0_ALIAS, GPIO1_ALIAS, GPIO2_ALIAS, GPIO3_ALIAS, GPIO4_ALIAS, GPIO5_ALIAS, GPIO6_ALIAS, GPIO7_ALIAS }
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS_NS                       { GPIO0_BASE_NS, GPIO1_BASE_NS, GPIO2_BASE_NS, GPIO3_BASE_NS, GPIO4_BASE_NS, GPIO5_BASE_NS, GPIO6_BASE_NS, GPIO7_BASE_NS, 0u, 0u, 0u, GPIO0_ALIAS_BASE_NS, GPIO1_ALIAS_BASE_NS, GPIO2_ALIAS_BASE_NS, GPIO3_ALIAS_BASE_NS, GPIO4_ALIAS_BASE_NS, GPIO5_ALIAS_BASE_NS, GPIO6_ALIAS_BASE_NS, GPIO7_ALIAS_BASE_NS }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS_NS                        { GPIO0_NS, GPIO1_NS, GPIO2_NS, GPIO3_NS, GPIO4_NS, GPIO5_NS, GPIO6_NS, GPIO7_NS, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, GPIO0_ALIAS_NS, GPIO1_ALIAS_NS, GPIO2_ALIAS_NS, GPIO3_ALIAS_NS, GPIO4_ALIAS_NS, GPIO5_ALIAS_NS, GPIO6_ALIAS_NS, GPIO7_ALIAS_NS }
#else
  /** Peripheral GPIO0 base address */
  #define GPIO0_BASE                               (0x40100000u)
  /** Peripheral GPIO0 base pointer */
  #define GPIO0                                    ((GPIO_Type *)GPIO0_BASE)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE                               (0x40102000u)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE                               (0x40104000u)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE                               (0x40106000u)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE                               (0x40108000u)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4                                    ((GPIO_Type *)GPIO4_BASE)
  /** Peripheral GPIO5 base address */
  #define GPIO5_BASE                               (0x4010A000u)
  /** Peripheral GPIO5 base pointer */
  #define GPIO5                                    ((GPIO_Type *)GPIO5_BASE)
  /** Peripheral GPIO6 base address */
  #define GPIO6_BASE                               (0x4010C000u)
  /** Peripheral GPIO6 base pointer */
  #define GPIO6                                    ((GPIO_Type *)GPIO6_BASE)
  /** Peripheral GPIO7 base address */
  #define GPIO7_BASE                               (0x4010E000u)
  /** Peripheral GPIO7 base pointer */
  #define GPIO7                                    ((GPIO_Type *)GPIO7_BASE)
  /** Peripheral GPIO0_ALIAS base address */
  #define GPIO0_ALIAS_BASE                         (0x40101000u)
  /** Peripheral GPIO0_ALIAS base pointer */
  #define GPIO0_ALIAS                              ((GPIO_Type *)GPIO0_ALIAS_BASE)
  /** Peripheral GPIO1_ALIAS base address */
  #define GPIO1_ALIAS_BASE                         (0x40103000u)
  /** Peripheral GPIO1_ALIAS base pointer */
  #define GPIO1_ALIAS                              ((GPIO_Type *)GPIO1_ALIAS_BASE)
  /** Peripheral GPIO2_ALIAS base address */
  #define GPIO2_ALIAS_BASE                         (0x40105000u)
  /** Peripheral GPIO2_ALIAS base pointer */
  #define GPIO2_ALIAS                              ((GPIO_Type *)GPIO2_ALIAS_BASE)
  /** Peripheral GPIO3_ALIAS base address */
  #define GPIO3_ALIAS_BASE                         (0x40107000u)
  /** Peripheral GPIO3_ALIAS base pointer */
  #define GPIO3_ALIAS                              ((GPIO_Type *)GPIO3_ALIAS_BASE)
  /** Peripheral GPIO4_ALIAS base address */
  #define GPIO4_ALIAS_BASE                         (0x40109000u)
  /** Peripheral GPIO4_ALIAS base pointer */
  #define GPIO4_ALIAS                              ((GPIO_Type *)GPIO4_ALIAS_BASE)
  /** Peripheral GPIO5_ALIAS base address */
  #define GPIO5_ALIAS_BASE                         (0x4010B000u)
  /** Peripheral GPIO5_ALIAS base pointer */
  #define GPIO5_ALIAS                              ((GPIO_Type *)GPIO5_ALIAS_BASE)
  /** Peripheral GPIO6_ALIAS base address */
  #define GPIO6_ALIAS_BASE                         (0x4010D000u)
  /** Peripheral GPIO6_ALIAS base pointer */
  #define GPIO6_ALIAS                              ((GPIO_Type *)GPIO6_ALIAS_BASE)
  /** Peripheral GPIO7_ALIAS base address */
  #define GPIO7_ALIAS_BASE                         (0x4010F000u)
  /** Peripheral GPIO7_ALIAS base pointer */
  #define GPIO7_ALIAS                              ((GPIO_Type *)GPIO7_ALIAS_BASE)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { GPIO0_BASE, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE, GPIO6_BASE, GPIO7_BASE, 0u, 0u, 0u, GPIO0_ALIAS_BASE, GPIO1_ALIAS_BASE, GPIO2_ALIAS_BASE, GPIO3_ALIAS_BASE, GPIO4_ALIAS_BASE, GPIO5_ALIAS_BASE, GPIO6_ALIAS_BASE, GPIO7_ALIAS_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { GPIO0, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5, GPIO6, GPIO7, (GPIO_Type *)0u, (GPIO_Type *)0u, (GPIO_Type *)0u, GPIO0_ALIAS, GPIO1_ALIAS, GPIO2_ALIAS, GPIO3_ALIAS, GPIO4_ALIAS, GPIO5_ALIAS, GPIO6_ALIAS, GPIO7_ALIAS }
#endif
/* Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS   {GPIO00_IRQn, GPIO10_IRQn, GPIO20_IRQn, GPIO30_IRQn, GPIO40_IRQn, GPIO50_IRQn, GPIO60_IRQn, GPIO70_IRQn}
#define GPIO_IRQS_1 {GPIO01_IRQn, GPIO11_IRQn, GPIO21_IRQn, GPIO31_IRQn, GPIO41_IRQn, GPIO51_IRQn, GPIO61_IRQn, GPIO71_IRQn}


/* I2S - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SAI0 base address */
  #define SAI0_BASE                                (0x50152000u)
  /** Peripheral SAI0 base address */
  #define SAI0_BASE_NS                             (0x40152000u)
  /** Peripheral SAI0 base pointer */
  #define SAI0                                     ((I2S_Type *)SAI0_BASE)
  /** Peripheral SAI0 base pointer */
  #define SAI0_NS                                  ((I2S_Type *)SAI0_BASE_NS)
  /** Peripheral SAI1 base address */
  #define SAI1_BASE                                (0x50153000u)
  /** Peripheral SAI1 base address */
  #define SAI1_BASE_NS                             (0x40153000u)
  /** Peripheral SAI1 base pointer */
  #define SAI1                                     ((I2S_Type *)SAI1_BASE)
  /** Peripheral SAI1 base pointer */
  #define SAI1_NS                                  ((I2S_Type *)SAI1_BASE_NS)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE                                (0x50154000u)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE_NS                             (0x40154000u)
  /** Peripheral SAI2 base pointer */
  #define SAI2                                     ((I2S_Type *)SAI2_BASE)
  /** Peripheral SAI2 base pointer */
  #define SAI2_NS                                  ((I2S_Type *)SAI2_BASE_NS)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { SAI0_BASE, SAI1_BASE, SAI2_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { SAI0, SAI1, SAI2 }
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS_NS                        { SAI0_BASE_NS, SAI1_BASE_NS, SAI2_BASE_NS }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS_NS                         { SAI0_NS, SAI1_NS, SAI2_NS }
#else
  /** Peripheral SAI0 base address */
  #define SAI0_BASE                                (0x40152000u)
  /** Peripheral SAI0 base pointer */
  #define SAI0                                     ((I2S_Type *)SAI0_BASE)
  /** Peripheral SAI1 base address */
  #define SAI1_BASE                                (0x40153000u)
  /** Peripheral SAI1 base pointer */
  #define SAI1                                     ((I2S_Type *)SAI1_BASE)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE                                (0x40154000u)
  /** Peripheral SAI2 base pointer */
  #define SAI2                                     ((I2S_Type *)SAI2_BASE)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { SAI0_BASE, SAI1_BASE, SAI2_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { SAI0, SAI1, SAI2 }
#endif
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { SAI0_IRQn, SAI1_IRQn, SAI2_IRQn }
#define I2S_TX_IRQS                              { SAI0_IRQn, SAI1_IRQn, SAI2_IRQn }

/* I3C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I3C0 base address */
  #define I3C0_BASE                                (0x50037000u)
  /** Peripheral I3C0 base address */
  #define I3C0_BASE_NS                             (0x40037000u)
  /** Peripheral I3C0 base pointer */
  #define I3C0                                     ((I3C_Type *)I3C0_BASE)
  /** Peripheral I3C0 base pointer */
  #define I3C0_NS                                  ((I3C_Type *)I3C0_BASE_NS)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x50038000u)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE_NS                             (0x40038000u)
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
  #define I3C0_BASE                                (0x40037000u)
  /** Peripheral I3C0 base pointer */
  #define I3C0                                     ((I3C_Type *)I3C0_BASE)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x40038000u)
  /** Peripheral I3C1 base pointer */
  #define I3C1                                     ((I3C_Type *)I3C1_BASE)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { I3C0_BASE, I3C1_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { I3C0, I3C1 }
#endif
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { I3C0_IRQn, I3C1_IRQn }

/* INPUTMUX0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral INPUTMUX0 base address */
  #define INPUTMUX0_BASE                           (0x50026000u)
  /** Peripheral INPUTMUX0 base address */
  #define INPUTMUX0_BASE_NS                        (0x40026000u)
  /** Peripheral INPUTMUX0 base pointer */
  #define INPUTMUX0                                ((INPUTMUX0_Type *)INPUTMUX0_BASE)
  /** Peripheral INPUTMUX0 base pointer */
  #define INPUTMUX0_NS                             ((INPUTMUX0_Type *)INPUTMUX0_BASE_NS)
  /** Array initializer of INPUTMUX0 peripheral base addresses */
  #define INPUTMUX0_BASE_ADDRS                     { INPUTMUX0_BASE }
  /** Array initializer of INPUTMUX0 peripheral base pointers */
  #define INPUTMUX0_BASE_PTRS                      { INPUTMUX0 }
  /** Array initializer of INPUTMUX0 peripheral base addresses */
  #define INPUTMUX0_BASE_ADDRS_NS                  { INPUTMUX0_BASE_NS }
  /** Array initializer of INPUTMUX0 peripheral base pointers */
  #define INPUTMUX0_BASE_PTRS_NS                   { INPUTMUX0_NS }
#else
  /** Peripheral INPUTMUX0 base address */
  #define INPUTMUX0_BASE                           (0x40026000u)
  /** Peripheral INPUTMUX0 base pointer */
  #define INPUTMUX0                                ((INPUTMUX0_Type *)INPUTMUX0_BASE)
  /** Array initializer of INPUTMUX0 peripheral base addresses */
  #define INPUTMUX0_BASE_ADDRS                     { INPUTMUX0_BASE }
  /** Array initializer of INPUTMUX0 peripheral base pointers */
  #define INPUTMUX0_BASE_PTRS                      { INPUTMUX0 }
#endif
/** INPUTMUX extra definition */
#define INPUTMUX_Type INPUTMUX0_Type
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
#define INPUTMUX_BASE_ADDRS INPUTMUX0_BASE_ADDRS
#define INPUTMUX_BASE_PTRS INPUTMUX0_BASE_PTRS
#define INPUTMUX_BASE_ADDRS_NS INPUTMUX0_BASE_ADDRS_NS
#define INPUTMUX_BASE_PTRS_NS INPUTMUX0_BASE_PTRS_NS
#else
#define INPUTMUX_BASE_ADDRS INPUTMUX0_BASE_ADDRS
#define INPUTMUX_BASE_PTRS INPUTMUX0_BASE_PTRS
#endif


/* IOPCTL0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOPCTL0 base address */
  #define IOPCTL0_BASE                             (0x50004000u)
  /** Peripheral IOPCTL0 base address */
  #define IOPCTL0_BASE_NS                          (0x40004000u)
  /** Peripheral IOPCTL0 base pointer */
  #define IOPCTL0                                  ((IOPCTL0_Type *)IOPCTL0_BASE)
  /** Peripheral IOPCTL0 base pointer */
  #define IOPCTL0_NS                               ((IOPCTL0_Type *)IOPCTL0_BASE_NS)
  /** Array initializer of IOPCTL0 peripheral base addresses */
  #define IOPCTL0_BASE_ADDRS                       { IOPCTL0_BASE }
  /** Array initializer of IOPCTL0 peripheral base pointers */
  #define IOPCTL0_BASE_PTRS                        { IOPCTL0 }
  /** Array initializer of IOPCTL0 peripheral base addresses */
  #define IOPCTL0_BASE_ADDRS_NS                    { IOPCTL0_BASE_NS }
  /** Array initializer of IOPCTL0 peripheral base pointers */
  #define IOPCTL0_BASE_PTRS_NS                     { IOPCTL0_NS }
#else
  /** Peripheral IOPCTL0 base address */
  #define IOPCTL0_BASE                             (0x40004000u)
  /** Peripheral IOPCTL0 base pointer */
  #define IOPCTL0                                  ((IOPCTL0_Type *)IOPCTL0_BASE)
  /** Array initializer of IOPCTL0 peripheral base addresses */
  #define IOPCTL0_BASE_ADDRS                       { IOPCTL0_BASE }
  /** Array initializer of IOPCTL0 peripheral base pointers */
  #define IOPCTL0_BASE_PTRS                        { IOPCTL0 }
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
  #define IOPCTL_BASE_ADDRS                        {IOPCTL0_BASE, IOPCTL1_BASE, IOPCTLR2_BASE}
/** Array initializer of IOPCTL NS peripheral base addresses */
  #define IOPCTL_BASE_ADDRS_NS                     {IOPCTL0_BASE_NS, IOPCTL1_BASE_NS, IOPCTLR2_BASE_NS}
#else
/** Array initializer of IOPCTL peripheral base addresses */
  #define IOPCTL_BASE_ADDRS                        {IOPCTL0_BASE, IOPCTL1_BASE, IOPCTLR2_BASE}
#endif


/* ITRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ITRC base address */
  #define ITRC_BASE                                (0x50012000u)
  /** Peripheral ITRC base address */
  #define ITRC_BASE_NS                             (0x40012000u)
  /** Peripheral ITRC base pointer */
  #define ITRC                                     ((ITRC_Type *)ITRC_BASE)
  /** Peripheral ITRC base pointer */
  #define ITRC_NS                                  ((ITRC_Type *)ITRC_BASE_NS)
  /** Array initializer of ITRC peripheral base addresses */
  #define ITRC_BASE_ADDRS                          { ITRC_BASE }
  /** Array initializer of ITRC peripheral base pointers */
  #define ITRC_BASE_PTRS                           { ITRC }
  /** Array initializer of ITRC peripheral base addresses */
  #define ITRC_BASE_ADDRS_NS                       { ITRC_BASE_NS }
  /** Array initializer of ITRC peripheral base pointers */
  #define ITRC_BASE_PTRS_NS                        { ITRC_NS }
#else
  /** Peripheral ITRC base address */
  #define ITRC_BASE                                (0x40012000u)
  /** Peripheral ITRC base pointer */
  #define ITRC                                     ((ITRC_Type *)ITRC_BASE)
  /** Array initializer of ITRC peripheral base addresses */
  #define ITRC_BASE_ADDRS                          { ITRC_BASE }
  /** Array initializer of ITRC peripheral base pointers */
  #define ITRC_BASE_PTRS                           { ITRC }
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
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE                              (0x50110800u)
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE_NS                           (0x40110800u)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0_NS                                ((LPI2C_Type *)LPI2C0_BASE_NS)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x50111800u)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE_NS                           (0x40111800u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1_NS                                ((LPI2C_Type *)LPI2C1_BASE_NS)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE                              (0x50112800u)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE_NS                           (0x40112800u)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2_NS                                ((LPI2C_Type *)LPI2C2_BASE_NS)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE                              (0x50113800u)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE_NS                           (0x40113800u)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3_NS                                ((LPI2C_Type *)LPI2C3_BASE_NS)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE                              (0x50171800u)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE_NS                           (0x40171800u)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4_NS                                ((LPI2C_Type *)LPI2C4_BASE_NS)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE                              (0x50172800u)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE_NS                           (0x40172800u)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5_NS                                ((LPI2C_Type *)LPI2C5_BASE_NS)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE                              (0x50173800u)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE_NS                           (0x40173800u)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6_NS                                ((LPI2C_Type *)LPI2C6_BASE_NS)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE                              (0x50174800u)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE_NS                           (0x40174800u)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7_NS                                ((LPI2C_Type *)LPI2C7_BASE_NS)
  /** Peripheral LPI2C8 base address */
  #define LPI2C8_BASE                              (0x50199800u)
  /** Peripheral LPI2C8 base address */
  #define LPI2C8_BASE_NS                           (0x40199800u)
  /** Peripheral LPI2C8 base pointer */
  #define LPI2C8                                   ((LPI2C_Type *)LPI2C8_BASE)
  /** Peripheral LPI2C8 base pointer */
  #define LPI2C8_NS                                ((LPI2C_Type *)LPI2C8_BASE_NS)
  /** Peripheral LPI2C9 base address */
  #define LPI2C9_BASE                              (0x5019A800u)
  /** Peripheral LPI2C9 base address */
  #define LPI2C9_BASE_NS                           (0x4019A800u)
  /** Peripheral LPI2C9 base pointer */
  #define LPI2C9                                   ((LPI2C_Type *)LPI2C9_BASE)
  /** Peripheral LPI2C9 base pointer */
  #define LPI2C9_NS                                ((LPI2C_Type *)LPI2C9_BASE_NS)
  /** Peripheral LPI2C10 base address */
  #define LPI2C10_BASE                             (0x5019B800u)
  /** Peripheral LPI2C10 base address */
  #define LPI2C10_BASE_NS                          (0x4019B800u)
  /** Peripheral LPI2C10 base pointer */
  #define LPI2C10                                  ((LPI2C_Type *)LPI2C10_BASE)
  /** Peripheral LPI2C10 base pointer */
  #define LPI2C10_NS                               ((LPI2C_Type *)LPI2C10_BASE_NS)
  /** Peripheral LPI2C11 base address */
  #define LPI2C11_BASE                             (0x5019C800u)
  /** Peripheral LPI2C11 base address */
  #define LPI2C11_BASE_NS                          (0x4019C800u)
  /** Peripheral LPI2C11 base pointer */
  #define LPI2C11                                  ((LPI2C_Type *)LPI2C11_BASE)
  /** Peripheral LPI2C11 base pointer */
  #define LPI2C11_NS                               ((LPI2C_Type *)LPI2C11_BASE_NS)
  /** Peripheral LPI2C12 base address */
  #define LPI2C12_BASE                             (0x5019D800u)
  /** Peripheral LPI2C12 base address */
  #define LPI2C12_BASE_NS                          (0x4019D800u)
  /** Peripheral LPI2C12 base pointer */
  #define LPI2C12                                  ((LPI2C_Type *)LPI2C12_BASE)
  /** Peripheral LPI2C12 base pointer */
  #define LPI2C12_NS                               ((LPI2C_Type *)LPI2C12_BASE_NS)
  /** Peripheral LPI2C13 base address */
  #define LPI2C13_BASE                             (0x5019E800u)
  /** Peripheral LPI2C13 base address */
  #define LPI2C13_BASE_NS                          (0x4019E800u)
  /** Peripheral LPI2C13 base pointer */
  #define LPI2C13                                  ((LPI2C_Type *)LPI2C13_BASE)
  /** Peripheral LPI2C13 base pointer */
  #define LPI2C13_NS                               ((LPI2C_Type *)LPI2C13_BASE_NS)
  /** Peripheral LPI2C15 base address */
  #define LPI2C15_BASE                             (0x50213000u)
  /** Peripheral LPI2C15 base address */
  #define LPI2C15_BASE_NS                          (0x40213000u)
  /** Peripheral LPI2C15 base pointer */
  #define LPI2C15                                  ((LPI2C_Type *)LPI2C15_BASE)
  /** Peripheral LPI2C15 base pointer */
  #define LPI2C15_NS                               ((LPI2C_Type *)LPI2C15_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE, LPI2C8_BASE, LPI2C9_BASE, LPI2C10_BASE, LPI2C11_BASE, LPI2C12_BASE, LPI2C13_BASE, 0u, LPI2C15_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7, LPI2C8, LPI2C9, LPI2C10, LPI2C11, LPI2C12, LPI2C13, (LPI2C_Type *)0u, LPI2C15 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { LPI2C0_BASE_NS, LPI2C1_BASE_NS, LPI2C2_BASE_NS, LPI2C3_BASE_NS, LPI2C4_BASE_NS, LPI2C5_BASE_NS, LPI2C6_BASE_NS, LPI2C7_BASE_NS, LPI2C8_BASE_NS, LPI2C9_BASE_NS, LPI2C10_BASE_NS, LPI2C11_BASE_NS, LPI2C12_BASE_NS, LPI2C13_BASE_NS, 0u, LPI2C15_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { LPI2C0_NS, LPI2C1_NS, LPI2C2_NS, LPI2C3_NS, LPI2C4_NS, LPI2C5_NS, LPI2C6_NS, LPI2C7_NS, LPI2C8_NS, LPI2C9_NS, LPI2C10_NS, LPI2C11_NS, LPI2C12_NS, LPI2C13_NS, (LPI2C_Type *)0u, LPI2C15_NS }
#else
  /** Peripheral LPI2C0 base address */
  #define LPI2C0_BASE                              (0x40110800u)
  /** Peripheral LPI2C0 base pointer */
  #define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x40111800u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE                              (0x40112800u)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE                              (0x40113800u)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE                              (0x40171800u)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE                              (0x40172800u)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE                              (0x40173800u)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE                              (0x40174800u)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
  /** Peripheral LPI2C8 base address */
  #define LPI2C8_BASE                              (0x40199800u)
  /** Peripheral LPI2C8 base pointer */
  #define LPI2C8                                   ((LPI2C_Type *)LPI2C8_BASE)
  /** Peripheral LPI2C9 base address */
  #define LPI2C9_BASE                              (0x4019A800u)
  /** Peripheral LPI2C9 base pointer */
  #define LPI2C9                                   ((LPI2C_Type *)LPI2C9_BASE)
  /** Peripheral LPI2C10 base address */
  #define LPI2C10_BASE                             (0x4019B800u)
  /** Peripheral LPI2C10 base pointer */
  #define LPI2C10                                  ((LPI2C_Type *)LPI2C10_BASE)
  /** Peripheral LPI2C11 base address */
  #define LPI2C11_BASE                             (0x4019C800u)
  /** Peripheral LPI2C11 base pointer */
  #define LPI2C11                                  ((LPI2C_Type *)LPI2C11_BASE)
  /** Peripheral LPI2C12 base address */
  #define LPI2C12_BASE                             (0x4019D800u)
  /** Peripheral LPI2C12 base pointer */
  #define LPI2C12                                  ((LPI2C_Type *)LPI2C12_BASE)
  /** Peripheral LPI2C13 base address */
  #define LPI2C13_BASE                             (0x4019E800u)
  /** Peripheral LPI2C13 base pointer */
  #define LPI2C13                                  ((LPI2C_Type *)LPI2C13_BASE)
  /** Peripheral LPI2C15 base address */
  #define LPI2C15_BASE                             (0x40213000u)
  /** Peripheral LPI2C15 base pointer */
  #define LPI2C15                                  ((LPI2C_Type *)LPI2C15_BASE)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE, LPI2C8_BASE, LPI2C9_BASE, LPI2C10_BASE, LPI2C11_BASE, LPI2C12_BASE, LPI2C13_BASE, 0u, LPI2C15_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7, LPI2C8, LPI2C9, LPI2C10, LPI2C11, LPI2C12, LPI2C13, (LPI2C_Type *)0u, LPI2C15 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LP_FLEXCOMM0_IRQn, LP_FLEXCOMM1_IRQn, LP_FLEXCOMM2_IRQn, LP_FLEXCOMM3_IRQn, LP_FLEXCOMM4_IRQn, LP_FLEXCOMM5_IRQn, LP_FLEXCOMM6_IRQn, LP_FLEXCOMM7_IRQn, LP_FLEXCOMM8_IRQn, LP_FLEXCOMM9_IRQn, LP_FLEXCOMM10_IRQn, LP_FLEXCOMM11_IRQn, LP_FLEXCOMM12_IRQn, LP_FLEXCOMM13_IRQn, NotAvail_IRQn, LPI2C15_IRQn }

/* LPSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE                              (0x50110000u)
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE_NS                           (0x40110000u)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0_NS                                ((LPSPI_Type *)LPSPI0_BASE_NS)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x50111000u)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE_NS                           (0x40111000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1_NS                                ((LPSPI_Type *)LPSPI1_BASE_NS)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE                              (0x50112000u)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE_NS                           (0x40112000u)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2_NS                                ((LPSPI_Type *)LPSPI2_BASE_NS)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE                              (0x50113000u)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE_NS                           (0x40113000u)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3_NS                                ((LPSPI_Type *)LPSPI3_BASE_NS)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE                              (0x50171000u)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE_NS                           (0x40171000u)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4_NS                                ((LPSPI_Type *)LPSPI4_BASE_NS)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE                              (0x50172000u)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE_NS                           (0x40172000u)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5_NS                                ((LPSPI_Type *)LPSPI5_BASE_NS)
  /** Peripheral LPSPI6 base address */
  #define LPSPI6_BASE                              (0x50173000u)
  /** Peripheral LPSPI6 base address */
  #define LPSPI6_BASE_NS                           (0x40173000u)
  /** Peripheral LPSPI6 base pointer */
  #define LPSPI6                                   ((LPSPI_Type *)LPSPI6_BASE)
  /** Peripheral LPSPI6 base pointer */
  #define LPSPI6_NS                                ((LPSPI_Type *)LPSPI6_BASE_NS)
  /** Peripheral LPSPI7 base address */
  #define LPSPI7_BASE                              (0x50174000u)
  /** Peripheral LPSPI7 base address */
  #define LPSPI7_BASE_NS                           (0x40174000u)
  /** Peripheral LPSPI7 base pointer */
  #define LPSPI7                                   ((LPSPI_Type *)LPSPI7_BASE)
  /** Peripheral LPSPI7 base pointer */
  #define LPSPI7_NS                                ((LPSPI_Type *)LPSPI7_BASE_NS)
  /** Peripheral LPSPI8 base address */
  #define LPSPI8_BASE                              (0x50199000u)
  /** Peripheral LPSPI8 base address */
  #define LPSPI8_BASE_NS                           (0x40199000u)
  /** Peripheral LPSPI8 base pointer */
  #define LPSPI8                                   ((LPSPI_Type *)LPSPI8_BASE)
  /** Peripheral LPSPI8 base pointer */
  #define LPSPI8_NS                                ((LPSPI_Type *)LPSPI8_BASE_NS)
  /** Peripheral LPSPI9 base address */
  #define LPSPI9_BASE                              (0x5019A000u)
  /** Peripheral LPSPI9 base address */
  #define LPSPI9_BASE_NS                           (0x4019A000u)
  /** Peripheral LPSPI9 base pointer */
  #define LPSPI9                                   ((LPSPI_Type *)LPSPI9_BASE)
  /** Peripheral LPSPI9 base pointer */
  #define LPSPI9_NS                                ((LPSPI_Type *)LPSPI9_BASE_NS)
  /** Peripheral LPSPI10 base address */
  #define LPSPI10_BASE                             (0x5019B000u)
  /** Peripheral LPSPI10 base address */
  #define LPSPI10_BASE_NS                          (0x4019B000u)
  /** Peripheral LPSPI10 base pointer */
  #define LPSPI10                                  ((LPSPI_Type *)LPSPI10_BASE)
  /** Peripheral LPSPI10 base pointer */
  #define LPSPI10_NS                               ((LPSPI_Type *)LPSPI10_BASE_NS)
  /** Peripheral LPSPI11 base address */
  #define LPSPI11_BASE                             (0x5019C000u)
  /** Peripheral LPSPI11 base address */
  #define LPSPI11_BASE_NS                          (0x4019C000u)
  /** Peripheral LPSPI11 base pointer */
  #define LPSPI11                                  ((LPSPI_Type *)LPSPI11_BASE)
  /** Peripheral LPSPI11 base pointer */
  #define LPSPI11_NS                               ((LPSPI_Type *)LPSPI11_BASE_NS)
  /** Peripheral LPSPI12 base address */
  #define LPSPI12_BASE                             (0x5019D000u)
  /** Peripheral LPSPI12 base address */
  #define LPSPI12_BASE_NS                          (0x4019D000u)
  /** Peripheral LPSPI12 base pointer */
  #define LPSPI12                                  ((LPSPI_Type *)LPSPI12_BASE)
  /** Peripheral LPSPI12 base pointer */
  #define LPSPI12_NS                               ((LPSPI_Type *)LPSPI12_BASE_NS)
  /** Peripheral LPSPI13 base address */
  #define LPSPI13_BASE                             (0x5019E000u)
  /** Peripheral LPSPI13 base address */
  #define LPSPI13_BASE_NS                          (0x4019E000u)
  /** Peripheral LPSPI13 base pointer */
  #define LPSPI13                                  ((LPSPI_Type *)LPSPI13_BASE)
  /** Peripheral LPSPI13 base pointer */
  #define LPSPI13_NS                               ((LPSPI_Type *)LPSPI13_BASE_NS)
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
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE, LPSPI6_BASE, LPSPI7_BASE, LPSPI8_BASE, LPSPI9_BASE, LPSPI10_BASE, LPSPI11_BASE, LPSPI12_BASE, LPSPI13_BASE, LPSPI14_BASE, 0u, LPSPI16_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5, LPSPI6, LPSPI7, LPSPI8, LPSPI9, LPSPI10, LPSPI11, LPSPI12, LPSPI13, LPSPI14, (LPSPI_Type *)0u, LPSPI16 }
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS_NS                      { LPSPI0_BASE_NS, LPSPI1_BASE_NS, LPSPI2_BASE_NS, LPSPI3_BASE_NS, LPSPI4_BASE_NS, LPSPI5_BASE_NS, LPSPI6_BASE_NS, LPSPI7_BASE_NS, LPSPI8_BASE_NS, LPSPI9_BASE_NS, LPSPI10_BASE_NS, LPSPI11_BASE_NS, LPSPI12_BASE_NS, LPSPI13_BASE_NS, LPSPI14_BASE_NS, 0u, LPSPI16_BASE_NS }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS_NS                       { LPSPI0_NS, LPSPI1_NS, LPSPI2_NS, LPSPI3_NS, LPSPI4_NS, LPSPI5_NS, LPSPI6_NS, LPSPI7_NS, LPSPI8_NS, LPSPI9_NS, LPSPI10_NS, LPSPI11_NS, LPSPI12_NS, LPSPI13_NS, LPSPI14_NS, (LPSPI_Type *)0u, LPSPI16_NS }
#else
  /** Peripheral LPSPI0 base address */
  #define LPSPI0_BASE                              (0x40110000u)
  /** Peripheral LPSPI0 base pointer */
  #define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x40111000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE                              (0x40112000u)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE                              (0x40113000u)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE                              (0x40171000u)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE                              (0x40172000u)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
  /** Peripheral LPSPI6 base address */
  #define LPSPI6_BASE                              (0x40173000u)
  /** Peripheral LPSPI6 base pointer */
  #define LPSPI6                                   ((LPSPI_Type *)LPSPI6_BASE)
  /** Peripheral LPSPI7 base address */
  #define LPSPI7_BASE                              (0x40174000u)
  /** Peripheral LPSPI7 base pointer */
  #define LPSPI7                                   ((LPSPI_Type *)LPSPI7_BASE)
  /** Peripheral LPSPI8 base address */
  #define LPSPI8_BASE                              (0x40199000u)
  /** Peripheral LPSPI8 base pointer */
  #define LPSPI8                                   ((LPSPI_Type *)LPSPI8_BASE)
  /** Peripheral LPSPI9 base address */
  #define LPSPI9_BASE                              (0x4019A000u)
  /** Peripheral LPSPI9 base pointer */
  #define LPSPI9                                   ((LPSPI_Type *)LPSPI9_BASE)
  /** Peripheral LPSPI10 base address */
  #define LPSPI10_BASE                             (0x4019B000u)
  /** Peripheral LPSPI10 base pointer */
  #define LPSPI10                                  ((LPSPI_Type *)LPSPI10_BASE)
  /** Peripheral LPSPI11 base address */
  #define LPSPI11_BASE                             (0x4019C000u)
  /** Peripheral LPSPI11 base pointer */
  #define LPSPI11                                  ((LPSPI_Type *)LPSPI11_BASE)
  /** Peripheral LPSPI12 base address */
  #define LPSPI12_BASE                             (0x4019D000u)
  /** Peripheral LPSPI12 base pointer */
  #define LPSPI12                                  ((LPSPI_Type *)LPSPI12_BASE)
  /** Peripheral LPSPI13 base address */
  #define LPSPI13_BASE                             (0x4019E000u)
  /** Peripheral LPSPI13 base pointer */
  #define LPSPI13                                  ((LPSPI_Type *)LPSPI13_BASE)
  /** Peripheral LPSPI14 base address */
  #define LPSPI14_BASE                             (0x40484000u)
  /** Peripheral LPSPI14 base pointer */
  #define LPSPI14                                  ((LPSPI_Type *)LPSPI14_BASE)
  /** Peripheral LPSPI16 base address */
  #define LPSPI16_BASE                             (0x40405000u)
  /** Peripheral LPSPI16 base pointer */
  #define LPSPI16                                  ((LPSPI_Type *)LPSPI16_BASE)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE, LPSPI6_BASE, LPSPI7_BASE, LPSPI8_BASE, LPSPI9_BASE, LPSPI10_BASE, LPSPI11_BASE, LPSPI12_BASE, LPSPI13_BASE, LPSPI14_BASE, 0u, LPSPI16_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5, LPSPI6, LPSPI7, LPSPI8, LPSPI9, LPSPI10, LPSPI11, LPSPI12, LPSPI13, LPSPI14, (LPSPI_Type *)0u, LPSPI16 }
#endif
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LP_FLEXCOMM0_IRQn, LP_FLEXCOMM1_IRQn, LP_FLEXCOMM2_IRQn, LP_FLEXCOMM3_IRQn, LP_FLEXCOMM4_IRQn, LP_FLEXCOMM5_IRQn, LP_FLEXCOMM6_IRQn, LP_FLEXCOMM7_IRQn, LP_FLEXCOMM8_IRQn, LP_FLEXCOMM9_IRQn, LP_FLEXCOMM10_IRQn, LP_FLEXCOMM11_IRQn, LP_FLEXCOMM12_IRQn, LP_FLEXCOMM13_IRQn, LPSPI14_IRQn, NotAvail_IRQn, LPSPI16_IRQn }

/* LPUART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE                             (0x50110000u)
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE_NS                          (0x40110000u)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0_NS                               ((LPUART_Type *)LPUART0_BASE_NS)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x50111000u)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE_NS                          (0x40111000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1_NS                               ((LPUART_Type *)LPUART1_BASE_NS)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE                             (0x50112000u)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE_NS                          (0x40112000u)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2_NS                               ((LPUART_Type *)LPUART2_BASE_NS)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE                             (0x50113000u)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE_NS                          (0x40113000u)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3_NS                               ((LPUART_Type *)LPUART3_BASE_NS)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE                             (0x50171000u)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE_NS                          (0x40171000u)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4_NS                               ((LPUART_Type *)LPUART4_BASE_NS)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE                             (0x50172000u)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE_NS                          (0x40172000u)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5_NS                               ((LPUART_Type *)LPUART5_BASE_NS)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE                             (0x50173000u)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE_NS                          (0x40173000u)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6_NS                               ((LPUART_Type *)LPUART6_BASE_NS)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE                             (0x50174000u)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE_NS                          (0x40174000u)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7_NS                               ((LPUART_Type *)LPUART7_BASE_NS)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE                             (0x50199000u)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE_NS                          (0x40199000u)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8_NS                               ((LPUART_Type *)LPUART8_BASE_NS)
  /** Peripheral LPUART9 base address */
  #define LPUART9_BASE                             (0x5019A000u)
  /** Peripheral LPUART9 base address */
  #define LPUART9_BASE_NS                          (0x4019A000u)
  /** Peripheral LPUART9 base pointer */
  #define LPUART9                                  ((LPUART_Type *)LPUART9_BASE)
  /** Peripheral LPUART9 base pointer */
  #define LPUART9_NS                               ((LPUART_Type *)LPUART9_BASE_NS)
  /** Peripheral LPUART10 base address */
  #define LPUART10_BASE                            (0x5019B000u)
  /** Peripheral LPUART10 base address */
  #define LPUART10_BASE_NS                         (0x4019B000u)
  /** Peripheral LPUART10 base pointer */
  #define LPUART10                                 ((LPUART_Type *)LPUART10_BASE)
  /** Peripheral LPUART10 base pointer */
  #define LPUART10_NS                              ((LPUART_Type *)LPUART10_BASE_NS)
  /** Peripheral LPUART11 base address */
  #define LPUART11_BASE                            (0x5019C000u)
  /** Peripheral LPUART11 base address */
  #define LPUART11_BASE_NS                         (0x4019C000u)
  /** Peripheral LPUART11 base pointer */
  #define LPUART11                                 ((LPUART_Type *)LPUART11_BASE)
  /** Peripheral LPUART11 base pointer */
  #define LPUART11_NS                              ((LPUART_Type *)LPUART11_BASE_NS)
  /** Peripheral LPUART12 base address */
  #define LPUART12_BASE                            (0x5019D000u)
  /** Peripheral LPUART12 base address */
  #define LPUART12_BASE_NS                         (0x4019D000u)
  /** Peripheral LPUART12 base pointer */
  #define LPUART12                                 ((LPUART_Type *)LPUART12_BASE)
  /** Peripheral LPUART12 base pointer */
  #define LPUART12_NS                              ((LPUART_Type *)LPUART12_BASE_NS)
  /** Peripheral LPUART13 base address */
  #define LPUART13_BASE                            (0x5019E000u)
  /** Peripheral LPUART13 base address */
  #define LPUART13_BASE_NS                         (0x4019E000u)
  /** Peripheral LPUART13 base pointer */
  #define LPUART13                                 ((LPUART_Type *)LPUART13_BASE)
  /** Peripheral LPUART13 base pointer */
  #define LPUART13_NS                              ((LPUART_Type *)LPUART13_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE, LPUART9_BASE, LPUART10_BASE, LPUART11_BASE, LPUART12_BASE, LPUART13_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8, LPUART9, LPUART10, LPUART11, LPUART12, LPUART13 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { LPUART0_BASE_NS, LPUART1_BASE_NS, LPUART2_BASE_NS, LPUART3_BASE_NS, LPUART4_BASE_NS, LPUART5_BASE_NS, LPUART6_BASE_NS, LPUART7_BASE_NS, LPUART8_BASE_NS, LPUART9_BASE_NS, LPUART10_BASE_NS, LPUART11_BASE_NS, LPUART12_BASE_NS, LPUART13_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { LPUART0_NS, LPUART1_NS, LPUART2_NS, LPUART3_NS, LPUART4_NS, LPUART5_NS, LPUART6_NS, LPUART7_NS, LPUART8_NS, LPUART9_NS, LPUART10_NS, LPUART11_NS, LPUART12_NS, LPUART13_NS }
#else
  /** Peripheral LPUART0 base address */
  #define LPUART0_BASE                             (0x40110000u)
  /** Peripheral LPUART0 base pointer */
  #define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x40111000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE                             (0x40112000u)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE                             (0x40113000u)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE                             (0x40171000u)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE                             (0x40172000u)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE                             (0x40173000u)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE                             (0x40174000u)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE                             (0x40199000u)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
  /** Peripheral LPUART9 base address */
  #define LPUART9_BASE                             (0x4019A000u)
  /** Peripheral LPUART9 base pointer */
  #define LPUART9                                  ((LPUART_Type *)LPUART9_BASE)
  /** Peripheral LPUART10 base address */
  #define LPUART10_BASE                            (0x4019B000u)
  /** Peripheral LPUART10 base pointer */
  #define LPUART10                                 ((LPUART_Type *)LPUART10_BASE)
  /** Peripheral LPUART11 base address */
  #define LPUART11_BASE                            (0x4019C000u)
  /** Peripheral LPUART11 base pointer */
  #define LPUART11                                 ((LPUART_Type *)LPUART11_BASE)
  /** Peripheral LPUART12 base address */
  #define LPUART12_BASE                            (0x4019D000u)
  /** Peripheral LPUART12 base pointer */
  #define LPUART12                                 ((LPUART_Type *)LPUART12_BASE)
  /** Peripheral LPUART13 base address */
  #define LPUART13_BASE                            (0x4019E000u)
  /** Peripheral LPUART13 base pointer */
  #define LPUART13                                 ((LPUART_Type *)LPUART13_BASE)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE, LPUART9_BASE, LPUART10_BASE, LPUART11_BASE, LPUART12_BASE, LPUART13_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8, LPUART9, LPUART10, LPUART11, LPUART12, LPUART13 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LP_FLEXCOMM0_IRQn, LP_FLEXCOMM1_IRQn, LP_FLEXCOMM2_IRQn, LP_FLEXCOMM3_IRQn, LP_FLEXCOMM4_IRQn, LP_FLEXCOMM5_IRQn, LP_FLEXCOMM6_IRQn, LP_FLEXCOMM7_IRQn, LP_FLEXCOMM8_IRQn, LP_FLEXCOMM9_IRQn, LP_FLEXCOMM10_IRQn, LP_FLEXCOMM11_IRQn, LP_FLEXCOMM12_IRQn, LP_FLEXCOMM13_IRQn }
#define LPUART_ERR_IRQS                          { LP_FLEXCOMM0_IRQn, LP_FLEXCOMM1_IRQn, LP_FLEXCOMM2_IRQn, LP_FLEXCOMM3_IRQn, LP_FLEXCOMM4_IRQn, LP_FLEXCOMM5_IRQn, LP_FLEXCOMM6_IRQn, LP_FLEXCOMM7_IRQn, LP_FLEXCOMM8_IRQn, LP_FLEXCOMM9_IRQn, LP_FLEXCOMM10_IRQn, LP_FLEXCOMM11_IRQn, LP_FLEXCOMM12_IRQn, LP_FLEXCOMM13_IRQn }

/* LP_FLEXCOMM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LP_FLEXCOMM0 base address */
  #define LP_FLEXCOMM0_BASE                        (0x50110000u)
  /** Peripheral LP_FLEXCOMM0 base address */
  #define LP_FLEXCOMM0_BASE_NS                     (0x40110000u)
  /** Peripheral LP_FLEXCOMM0 base pointer */
  #define LP_FLEXCOMM0                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM0_BASE)
  /** Peripheral LP_FLEXCOMM0 base pointer */
  #define LP_FLEXCOMM0_NS                          ((LP_FLEXCOMM_Type *)LP_FLEXCOMM0_BASE_NS)
  /** Peripheral LP_FLEXCOMM1 base address */
  #define LP_FLEXCOMM1_BASE                        (0x50111000u)
  /** Peripheral LP_FLEXCOMM1 base address */
  #define LP_FLEXCOMM1_BASE_NS                     (0x40111000u)
  /** Peripheral LP_FLEXCOMM1 base pointer */
  #define LP_FLEXCOMM1                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM1_BASE)
  /** Peripheral LP_FLEXCOMM1 base pointer */
  #define LP_FLEXCOMM1_NS                          ((LP_FLEXCOMM_Type *)LP_FLEXCOMM1_BASE_NS)
  /** Peripheral LP_FLEXCOMM2 base address */
  #define LP_FLEXCOMM2_BASE                        (0x50112000u)
  /** Peripheral LP_FLEXCOMM2 base address */
  #define LP_FLEXCOMM2_BASE_NS                     (0x40112000u)
  /** Peripheral LP_FLEXCOMM2 base pointer */
  #define LP_FLEXCOMM2                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM2_BASE)
  /** Peripheral LP_FLEXCOMM2 base pointer */
  #define LP_FLEXCOMM2_NS                          ((LP_FLEXCOMM_Type *)LP_FLEXCOMM2_BASE_NS)
  /** Peripheral LP_FLEXCOMM3 base address */
  #define LP_FLEXCOMM3_BASE                        (0x50113000u)
  /** Peripheral LP_FLEXCOMM3 base address */
  #define LP_FLEXCOMM3_BASE_NS                     (0x40113000u)
  /** Peripheral LP_FLEXCOMM3 base pointer */
  #define LP_FLEXCOMM3                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM3_BASE)
  /** Peripheral LP_FLEXCOMM3 base pointer */
  #define LP_FLEXCOMM3_NS                          ((LP_FLEXCOMM_Type *)LP_FLEXCOMM3_BASE_NS)
  /** Peripheral LP_FLEXCOMM4 base address */
  #define LP_FLEXCOMM4_BASE                        (0x50171000u)
  /** Peripheral LP_FLEXCOMM4 base address */
  #define LP_FLEXCOMM4_BASE_NS                     (0x40171000u)
  /** Peripheral LP_FLEXCOMM4 base pointer */
  #define LP_FLEXCOMM4                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM4_BASE)
  /** Peripheral LP_FLEXCOMM4 base pointer */
  #define LP_FLEXCOMM4_NS                          ((LP_FLEXCOMM_Type *)LP_FLEXCOMM4_BASE_NS)
  /** Peripheral LP_FLEXCOMM5 base address */
  #define LP_FLEXCOMM5_BASE                        (0x50172000u)
  /** Peripheral LP_FLEXCOMM5 base address */
  #define LP_FLEXCOMM5_BASE_NS                     (0x40172000u)
  /** Peripheral LP_FLEXCOMM5 base pointer */
  #define LP_FLEXCOMM5                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM5_BASE)
  /** Peripheral LP_FLEXCOMM5 base pointer */
  #define LP_FLEXCOMM5_NS                          ((LP_FLEXCOMM_Type *)LP_FLEXCOMM5_BASE_NS)
  /** Peripheral LP_FLEXCOMM6 base address */
  #define LP_FLEXCOMM6_BASE                        (0x50173000u)
  /** Peripheral LP_FLEXCOMM6 base address */
  #define LP_FLEXCOMM6_BASE_NS                     (0x40173000u)
  /** Peripheral LP_FLEXCOMM6 base pointer */
  #define LP_FLEXCOMM6                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM6_BASE)
  /** Peripheral LP_FLEXCOMM6 base pointer */
  #define LP_FLEXCOMM6_NS                          ((LP_FLEXCOMM_Type *)LP_FLEXCOMM6_BASE_NS)
  /** Peripheral LP_FLEXCOMM7 base address */
  #define LP_FLEXCOMM7_BASE                        (0x50174000u)
  /** Peripheral LP_FLEXCOMM7 base address */
  #define LP_FLEXCOMM7_BASE_NS                     (0x40174000u)
  /** Peripheral LP_FLEXCOMM7 base pointer */
  #define LP_FLEXCOMM7                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM7_BASE)
  /** Peripheral LP_FLEXCOMM7 base pointer */
  #define LP_FLEXCOMM7_NS                          ((LP_FLEXCOMM_Type *)LP_FLEXCOMM7_BASE_NS)
  /** Peripheral LP_FLEXCOMM8 base address */
  #define LP_FLEXCOMM8_BASE                        (0x50199000u)
  /** Peripheral LP_FLEXCOMM8 base address */
  #define LP_FLEXCOMM8_BASE_NS                     (0x40199000u)
  /** Peripheral LP_FLEXCOMM8 base pointer */
  #define LP_FLEXCOMM8                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM8_BASE)
  /** Peripheral LP_FLEXCOMM8 base pointer */
  #define LP_FLEXCOMM8_NS                          ((LP_FLEXCOMM_Type *)LP_FLEXCOMM8_BASE_NS)
  /** Peripheral LP_FLEXCOMM9 base address */
  #define LP_FLEXCOMM9_BASE                        (0x5019A000u)
  /** Peripheral LP_FLEXCOMM9 base address */
  #define LP_FLEXCOMM9_BASE_NS                     (0x4019A000u)
  /** Peripheral LP_FLEXCOMM9 base pointer */
  #define LP_FLEXCOMM9                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM9_BASE)
  /** Peripheral LP_FLEXCOMM9 base pointer */
  #define LP_FLEXCOMM9_NS                          ((LP_FLEXCOMM_Type *)LP_FLEXCOMM9_BASE_NS)
  /** Peripheral LP_FLEXCOMM10 base address */
  #define LP_FLEXCOMM10_BASE                       (0x5019B000u)
  /** Peripheral LP_FLEXCOMM10 base address */
  #define LP_FLEXCOMM10_BASE_NS                    (0x4019B000u)
  /** Peripheral LP_FLEXCOMM10 base pointer */
  #define LP_FLEXCOMM10                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM10_BASE)
  /** Peripheral LP_FLEXCOMM10 base pointer */
  #define LP_FLEXCOMM10_NS                         ((LP_FLEXCOMM_Type *)LP_FLEXCOMM10_BASE_NS)
  /** Peripheral LP_FLEXCOMM11 base address */
  #define LP_FLEXCOMM11_BASE                       (0x5019C000u)
  /** Peripheral LP_FLEXCOMM11 base address */
  #define LP_FLEXCOMM11_BASE_NS                    (0x4019C000u)
  /** Peripheral LP_FLEXCOMM11 base pointer */
  #define LP_FLEXCOMM11                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM11_BASE)
  /** Peripheral LP_FLEXCOMM11 base pointer */
  #define LP_FLEXCOMM11_NS                         ((LP_FLEXCOMM_Type *)LP_FLEXCOMM11_BASE_NS)
  /** Peripheral LP_FLEXCOMM12 base address */
  #define LP_FLEXCOMM12_BASE                       (0x5019D000u)
  /** Peripheral LP_FLEXCOMM12 base address */
  #define LP_FLEXCOMM12_BASE_NS                    (0x4019D000u)
  /** Peripheral LP_FLEXCOMM12 base pointer */
  #define LP_FLEXCOMM12                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM12_BASE)
  /** Peripheral LP_FLEXCOMM12 base pointer */
  #define LP_FLEXCOMM12_NS                         ((LP_FLEXCOMM_Type *)LP_FLEXCOMM12_BASE_NS)
  /** Peripheral LP_FLEXCOMM13 base address */
  #define LP_FLEXCOMM13_BASE                       (0x5019E000u)
  /** Peripheral LP_FLEXCOMM13 base address */
  #define LP_FLEXCOMM13_BASE_NS                    (0x4019E000u)
  /** Peripheral LP_FLEXCOMM13 base pointer */
  #define LP_FLEXCOMM13                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM13_BASE)
  /** Peripheral LP_FLEXCOMM13 base pointer */
  #define LP_FLEXCOMM13_NS                         ((LP_FLEXCOMM_Type *)LP_FLEXCOMM13_BASE_NS)
  /** Array initializer of LP_FLEXCOMM peripheral base addresses */
  #define LP_FLEXCOMM_BASE_ADDRS                   { LP_FLEXCOMM0_BASE, LP_FLEXCOMM1_BASE, LP_FLEXCOMM2_BASE, LP_FLEXCOMM3_BASE, LP_FLEXCOMM4_BASE, LP_FLEXCOMM5_BASE, LP_FLEXCOMM6_BASE, LP_FLEXCOMM7_BASE, LP_FLEXCOMM8_BASE, LP_FLEXCOMM9_BASE, LP_FLEXCOMM10_BASE, LP_FLEXCOMM11_BASE, LP_FLEXCOMM12_BASE, LP_FLEXCOMM13_BASE }
  /** Array initializer of LP_FLEXCOMM peripheral base pointers */
  #define LP_FLEXCOMM_BASE_PTRS                    { LP_FLEXCOMM0, LP_FLEXCOMM1, LP_FLEXCOMM2, LP_FLEXCOMM3, LP_FLEXCOMM4, LP_FLEXCOMM5, LP_FLEXCOMM6, LP_FLEXCOMM7, LP_FLEXCOMM8, LP_FLEXCOMM9, LP_FLEXCOMM10, LP_FLEXCOMM11, LP_FLEXCOMM12, LP_FLEXCOMM13 }
  /** Array initializer of LP_FLEXCOMM peripheral base addresses */
  #define LP_FLEXCOMM_BASE_ADDRS_NS                { LP_FLEXCOMM0_BASE_NS, LP_FLEXCOMM1_BASE_NS, LP_FLEXCOMM2_BASE_NS, LP_FLEXCOMM3_BASE_NS, LP_FLEXCOMM4_BASE_NS, LP_FLEXCOMM5_BASE_NS, LP_FLEXCOMM6_BASE_NS, LP_FLEXCOMM7_BASE_NS, LP_FLEXCOMM8_BASE_NS, LP_FLEXCOMM9_BASE_NS, LP_FLEXCOMM10_BASE_NS, LP_FLEXCOMM11_BASE_NS, LP_FLEXCOMM12_BASE_NS, LP_FLEXCOMM13_BASE_NS }
  /** Array initializer of LP_FLEXCOMM peripheral base pointers */
  #define LP_FLEXCOMM_BASE_PTRS_NS                 { LP_FLEXCOMM0_NS, LP_FLEXCOMM1_NS, LP_FLEXCOMM2_NS, LP_FLEXCOMM3_NS, LP_FLEXCOMM4_NS, LP_FLEXCOMM5_NS, LP_FLEXCOMM6_NS, LP_FLEXCOMM7_NS, LP_FLEXCOMM8_NS, LP_FLEXCOMM9_NS, LP_FLEXCOMM10_NS, LP_FLEXCOMM11_NS, LP_FLEXCOMM12_NS, LP_FLEXCOMM13_NS }
#else
  /** Peripheral LP_FLEXCOMM0 base address */
  #define LP_FLEXCOMM0_BASE                        (0x40110000u)
  /** Peripheral LP_FLEXCOMM0 base pointer */
  #define LP_FLEXCOMM0                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM0_BASE)
  /** Peripheral LP_FLEXCOMM1 base address */
  #define LP_FLEXCOMM1_BASE                        (0x40111000u)
  /** Peripheral LP_FLEXCOMM1 base pointer */
  #define LP_FLEXCOMM1                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM1_BASE)
  /** Peripheral LP_FLEXCOMM2 base address */
  #define LP_FLEXCOMM2_BASE                        (0x40112000u)
  /** Peripheral LP_FLEXCOMM2 base pointer */
  #define LP_FLEXCOMM2                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM2_BASE)
  /** Peripheral LP_FLEXCOMM3 base address */
  #define LP_FLEXCOMM3_BASE                        (0x40113000u)
  /** Peripheral LP_FLEXCOMM3 base pointer */
  #define LP_FLEXCOMM3                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM3_BASE)
  /** Peripheral LP_FLEXCOMM4 base address */
  #define LP_FLEXCOMM4_BASE                        (0x40171000u)
  /** Peripheral LP_FLEXCOMM4 base pointer */
  #define LP_FLEXCOMM4                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM4_BASE)
  /** Peripheral LP_FLEXCOMM5 base address */
  #define LP_FLEXCOMM5_BASE                        (0x40172000u)
  /** Peripheral LP_FLEXCOMM5 base pointer */
  #define LP_FLEXCOMM5                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM5_BASE)
  /** Peripheral LP_FLEXCOMM6 base address */
  #define LP_FLEXCOMM6_BASE                        (0x40173000u)
  /** Peripheral LP_FLEXCOMM6 base pointer */
  #define LP_FLEXCOMM6                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM6_BASE)
  /** Peripheral LP_FLEXCOMM7 base address */
  #define LP_FLEXCOMM7_BASE                        (0x40174000u)
  /** Peripheral LP_FLEXCOMM7 base pointer */
  #define LP_FLEXCOMM7                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM7_BASE)
  /** Peripheral LP_FLEXCOMM8 base address */
  #define LP_FLEXCOMM8_BASE                        (0x40199000u)
  /** Peripheral LP_FLEXCOMM8 base pointer */
  #define LP_FLEXCOMM8                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM8_BASE)
  /** Peripheral LP_FLEXCOMM9 base address */
  #define LP_FLEXCOMM9_BASE                        (0x4019A000u)
  /** Peripheral LP_FLEXCOMM9 base pointer */
  #define LP_FLEXCOMM9                             ((LP_FLEXCOMM_Type *)LP_FLEXCOMM9_BASE)
  /** Peripheral LP_FLEXCOMM10 base address */
  #define LP_FLEXCOMM10_BASE                       (0x4019B000u)
  /** Peripheral LP_FLEXCOMM10 base pointer */
  #define LP_FLEXCOMM10                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM10_BASE)
  /** Peripheral LP_FLEXCOMM11 base address */
  #define LP_FLEXCOMM11_BASE                       (0x4019C000u)
  /** Peripheral LP_FLEXCOMM11 base pointer */
  #define LP_FLEXCOMM11                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM11_BASE)
  /** Peripheral LP_FLEXCOMM12 base address */
  #define LP_FLEXCOMM12_BASE                       (0x4019D000u)
  /** Peripheral LP_FLEXCOMM12 base pointer */
  #define LP_FLEXCOMM12                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM12_BASE)
  /** Peripheral LP_FLEXCOMM13 base address */
  #define LP_FLEXCOMM13_BASE                       (0x4019E000u)
  /** Peripheral LP_FLEXCOMM13 base pointer */
  #define LP_FLEXCOMM13                            ((LP_FLEXCOMM_Type *)LP_FLEXCOMM13_BASE)
  /** Array initializer of LP_FLEXCOMM peripheral base addresses */
  #define LP_FLEXCOMM_BASE_ADDRS                   { LP_FLEXCOMM0_BASE, LP_FLEXCOMM1_BASE, LP_FLEXCOMM2_BASE, LP_FLEXCOMM3_BASE, LP_FLEXCOMM4_BASE, LP_FLEXCOMM5_BASE, LP_FLEXCOMM6_BASE, LP_FLEXCOMM7_BASE, LP_FLEXCOMM8_BASE, LP_FLEXCOMM9_BASE, LP_FLEXCOMM10_BASE, LP_FLEXCOMM11_BASE, LP_FLEXCOMM12_BASE, LP_FLEXCOMM13_BASE }
  /** Array initializer of LP_FLEXCOMM peripheral base pointers */
  #define LP_FLEXCOMM_BASE_PTRS                    { LP_FLEXCOMM0, LP_FLEXCOMM1, LP_FLEXCOMM2, LP_FLEXCOMM3, LP_FLEXCOMM4, LP_FLEXCOMM5, LP_FLEXCOMM6, LP_FLEXCOMM7, LP_FLEXCOMM8, LP_FLEXCOMM9, LP_FLEXCOMM10, LP_FLEXCOMM11, LP_FLEXCOMM12, LP_FLEXCOMM13 }
#endif
/** Interrupt vectors for the LP_FLEXCOMM peripheral type */
#define LP_FLEXCOMM_IRQS                         { LP_FLEXCOMM0_IRQn, LP_FLEXCOMM1_IRQn, LP_FLEXCOMM2_IRQn, LP_FLEXCOMM3_IRQn, LP_FLEXCOMM4_IRQn, LP_FLEXCOMM5_IRQn, LP_FLEXCOMM6_IRQn, LP_FLEXCOMM7_IRQn, LP_FLEXCOMM8_IRQn, LP_FLEXCOMM9_IRQn, LP_FLEXCOMM10_IRQn, LP_FLEXCOMM11_IRQn, LP_FLEXCOMM12_IRQn, LP_FLEXCOMM13_IRQn }

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
  /** Peripheral MMU0 base address */
  #define MMU0_BASE                                (0x50030000u)
  /** Peripheral MMU0 base address */
  #define MMU0_BASE_NS                             (0x40030000u)
  /** Peripheral MMU0 base pointer */
  #define MMU0                                     ((MMU_Type *)MMU0_BASE)
  /** Peripheral MMU0 base pointer */
  #define MMU0_NS                                  ((MMU_Type *)MMU0_BASE_NS)
  /** Peripheral MMU1 base address */
  #define MMU1_BASE                                (0x50031000u)
  /** Peripheral MMU1 base address */
  #define MMU1_BASE_NS                             (0x40031000u)
  /** Peripheral MMU1 base pointer */
  #define MMU1                                     ((MMU_Type *)MMU1_BASE)
  /** Peripheral MMU1 base pointer */
  #define MMU1_NS                                  ((MMU_Type *)MMU1_BASE_NS)
  /** Peripheral MMU2 base address */
  #define MMU2_BASE                                (0x500A8000u)
  /** Peripheral MMU2 base address */
  #define MMU2_BASE_NS                             (0x400A8000u)
  /** Peripheral MMU2 base pointer */
  #define MMU2                                     ((MMU_Type *)MMU2_BASE)
  /** Peripheral MMU2 base pointer */
  #define MMU2_NS                                  ((MMU_Type *)MMU2_BASE_NS)
  /** Array initializer of MMU peripheral base addresses */
  #define MMU_BASE_ADDRS                           { MMU0_BASE, MMU1_BASE, MMU2_BASE }
  /** Array initializer of MMU peripheral base pointers */
  #define MMU_BASE_PTRS                            { MMU0, MMU1, MMU2 }
  /** Array initializer of MMU peripheral base addresses */
  #define MMU_BASE_ADDRS_NS                        { MMU0_BASE_NS, MMU1_BASE_NS, MMU2_BASE_NS }
  /** Array initializer of MMU peripheral base pointers */
  #define MMU_BASE_PTRS_NS                         { MMU0_NS, MMU1_NS, MMU2_NS }
#else
  /** Peripheral MMU0 base address */
  #define MMU0_BASE                                (0x40030000u)
  /** Peripheral MMU0 base pointer */
  #define MMU0                                     ((MMU_Type *)MMU0_BASE)
  /** Peripheral MMU1 base address */
  #define MMU1_BASE                                (0x40031000u)
  /** Peripheral MMU1 base pointer */
  #define MMU1                                     ((MMU_Type *)MMU1_BASE)
  /** Peripheral MMU2 base address */
  #define MMU2_BASE                                (0x400A8000u)
  /** Peripheral MMU2 base pointer */
  #define MMU2                                     ((MMU_Type *)MMU2_BASE)
  /** Array initializer of MMU peripheral base addresses */
  #define MMU_BASE_ADDRS                           { MMU0_BASE, MMU1_BASE, MMU2_BASE }
  /** Array initializer of MMU peripheral base pointers */
  #define MMU_BASE_PTRS                            { MMU0, MMU1, MMU2 }
#endif
/** Interrupt vectors for the MMU peripheral type */
#define MMU_IRQS                                 { MMU0_IRQn, MMU1_IRQn, MMU2_IRQn }

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
  /** Peripheral MU0_MUA base address */
  #define MU0_MUA_BASE                             (0x50200000u)
  /** Peripheral MU0_MUA base address */
  #define MU0_MUA_BASE_NS                          (0x40200000u)
  /** Peripheral MU0_MUA base pointer */
  #define MU0_MUA                                  ((MU_Type *)MU0_MUA_BASE)
  /** Peripheral MU0_MUA base pointer */
  #define MU0_MUA_NS                               ((MU_Type *)MU0_MUA_BASE_NS)
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE                             (0x50202000u)
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE_NS                          (0x40202000u)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA_NS                               ((MU_Type *)MU1_MUA_BASE_NS)
  /** Peripheral MU4_MUA base address */
  #define MU4_MUA_BASE                             (0x50189000u)
  /** Peripheral MU4_MUA base address */
  #define MU4_MUA_BASE_NS                          (0x40189000u)
  /** Peripheral MU4_MUA base pointer */
  #define MU4_MUA                                  ((MU_Type *)MU4_MUA_BASE)
  /** Peripheral MU4_MUA base pointer */
  #define MU4_MUA_NS                               ((MU_Type *)MU4_MUA_BASE_NS)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU0_MUA_BASE, MU1_MUA_BASE, MU4_MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU0_MUA, MU1_MUA, MU4_MUA }
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS_NS                         { MU0_MUA_BASE_NS, MU1_MUA_BASE_NS, MU4_MUA_BASE_NS }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS_NS                          { MU0_MUA_NS, MU1_MUA_NS, MU4_MUA_NS }
#else
  /** Peripheral MU0_MUA base address */
  #define MU0_MUA_BASE                             (0x40200000u)
  /** Peripheral MU0_MUA base pointer */
  #define MU0_MUA                                  ((MU_Type *)MU0_MUA_BASE)
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE                             (0x40202000u)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
  /** Peripheral MU4_MUA base address */
  #define MU4_MUA_BASE                             (0x40189000u)
  /** Peripheral MU4_MUA base pointer */
  #define MU4_MUA                                  ((MU_Type *)MU4_MUA_BASE)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU0_MUA_BASE, MU1_MUA_BASE, MU4_MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU0_MUA, MU1_MUA, MU4_MUA }
#endif
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU0_A_IRQn, MU1_A_IRQn, MU4_A_IRQn }

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

/* OCOTP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OCOTP base address */
  #define OCOTP_BASE                               (0x50018000u)
  /** Peripheral OCOTP base address */
  #define OCOTP_BASE_NS                            (0x40018000u)
  /** Peripheral OCOTP base pointer */
  #define OCOTP                                    ((OCOTP_Type *)OCOTP_BASE)
  /** Peripheral OCOTP base pointer */
  #define OCOTP_NS                                 ((OCOTP_Type *)OCOTP_BASE_NS)
  /** Array initializer of OCOTP peripheral base addresses */
  #define OCOTP_BASE_ADDRS                         { OCOTP_BASE }
  /** Array initializer of OCOTP peripheral base pointers */
  #define OCOTP_BASE_PTRS                          { OCOTP }
  /** Array initializer of OCOTP peripheral base addresses */
  #define OCOTP_BASE_ADDRS_NS                      { OCOTP_BASE_NS }
  /** Array initializer of OCOTP peripheral base pointers */
  #define OCOTP_BASE_PTRS_NS                       { OCOTP_NS }
#else
  /** Peripheral OCOTP base address */
  #define OCOTP_BASE                               (0x40018000u)
  /** Peripheral OCOTP base pointer */
  #define OCOTP                                    ((OCOTP_Type *)OCOTP_BASE)
  /** Array initializer of OCOTP peripheral base addresses */
  #define OCOTP_BASE_ADDRS                         { OCOTP_BASE }
  /** Array initializer of OCOTP peripheral base pointers */
  #define OCOTP_BASE_PTRS                          { OCOTP }
#endif
/** Interrupt vectors for the OCOTP peripheral type */
#define OCOTP_IRQS                               { OCOTP_IRQn }

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

/* OSCCA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OSCCA base address */
  #define OSCCA_BASE                               (0x5001A000u)
  /** Peripheral OSCCA base address */
  #define OSCCA_BASE_NS                            (0x4001A000u)
  /** Peripheral OSCCA base pointer */
  #define OSCCA                                    ((OSCCA_Type *)OSCCA_BASE)
  /** Peripheral OSCCA base pointer */
  #define OSCCA_NS                                 ((OSCCA_Type *)OSCCA_BASE_NS)
  /** Array initializer of OSCCA peripheral base addresses */
  #define OSCCA_BASE_ADDRS                         { OSCCA_BASE }
  /** Array initializer of OSCCA peripheral base pointers */
  #define OSCCA_BASE_PTRS                          { OSCCA }
  /** Array initializer of OSCCA peripheral base addresses */
  #define OSCCA_BASE_ADDRS_NS                      { OSCCA_BASE_NS }
  /** Array initializer of OSCCA peripheral base pointers */
  #define OSCCA_BASE_PTRS_NS                       { OSCCA_NS }
#else
  /** Peripheral OSCCA base address */
  #define OSCCA_BASE                               (0x4001A000u)
  /** Peripheral OSCCA base pointer */
  #define OSCCA                                    ((OSCCA_Type *)OSCCA_BASE)
  /** Array initializer of OSCCA peripheral base addresses */
  #define OSCCA_BASE_ADDRS                         { OSCCA_BASE }
  /** Array initializer of OSCCA peripheral base pointers */
  #define OSCCA_BASE_PTRS                          { OSCCA }
#endif

/* OSTIMER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OSTIMER_CPU0 base address */
  #define OSTIMER_CPU0_BASE                        (0x50207000u)
  /** Peripheral OSTIMER_CPU0 base address */
  #define OSTIMER_CPU0_BASE_NS                     (0x40207000u)
  /** Peripheral OSTIMER_CPU0 base pointer */
  #define OSTIMER_CPU0                             ((OSTIMER_Type *)OSTIMER_CPU0_BASE)
  /** Peripheral OSTIMER_CPU0 base pointer */
  #define OSTIMER_CPU0_NS                          ((OSTIMER_Type *)OSTIMER_CPU0_BASE_NS)
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS                       { OSTIMER_CPU0_BASE }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS                        { OSTIMER_CPU0 }
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS_NS                    { OSTIMER_CPU0_BASE_NS }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS_NS                     { OSTIMER_CPU0_NS }
#else
  /** Peripheral OSTIMER_CPU0 base address */
  #define OSTIMER_CPU0_BASE                        (0x40207000u)
  /** Peripheral OSTIMER_CPU0 base pointer */
  #define OSTIMER_CPU0                             ((OSTIMER_Type *)OSTIMER_CPU0_BASE)
  /** Array initializer of OSTIMER peripheral base addresses */
  #define OSTIMER_BASE_ADDRS                       { OSTIMER_CPU0_BASE }
  /** Array initializer of OSTIMER peripheral base pointers */
  #define OSTIMER_BASE_PTRS                        { OSTIMER_CPU0 }
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
  /** Peripheral PINT0 base address */
  #define PINT0_BASE                               (0x50025000u)
  /** Peripheral PINT0 base address */
  #define PINT0_BASE_NS                            (0x40025000u)
  /** Peripheral PINT0 base pointer */
  #define PINT0                                    ((PINT_Type *)PINT0_BASE)
  /** Peripheral PINT0 base pointer */
  #define PINT0_NS                                 ((PINT_Type *)PINT0_BASE_NS)
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS                          { PINT0_BASE }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS                           { PINT0 }
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS_NS                       { PINT0_BASE_NS }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS_NS                        { PINT0_NS }
#else
  /** Peripheral PINT0 base address */
  #define PINT0_BASE                               (0x40025000u)
  /** Peripheral PINT0 base pointer */
  #define PINT0                                    ((PINT_Type *)PINT0_BASE)
  /** Array initializer of PINT peripheral base addresses */
  #define PINT_BASE_ADDRS                          { PINT0_BASE }
  /** Array initializer of PINT peripheral base pointers */
  #define PINT_BASE_PTRS                           { PINT0 }
#endif
/** Interrupt vectors for the PINT peripheral type */
#define PINT_IRQS                                { PIN_INT0_IRQn, PIN_INT1_IRQn, PIN_INT2_IRQn, PIN_INT3_IRQn, PIN_INT4_IRQn, PIN_INT5_IRQn, PIN_INT6_IRQn, PIN_INT7_IRQn }

/* PKC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PKC base address */
  #define PKC_BASE                                 (0x50011000u)
  /** Peripheral PKC base address */
  #define PKC_BASE_NS                              (0x40011000u)
  /** Peripheral PKC base pointer */
  #define PKC                                      ((PKC_Type *)PKC_BASE)
  /** Peripheral PKC base pointer */
  #define PKC_NS                                   ((PKC_Type *)PKC_BASE_NS)
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS                           { PKC_BASE }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS                            { PKC }
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS_NS                        { PKC_BASE_NS }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS_NS                         { PKC_NS }
#else
  /** Peripheral PKC base address */
  #define PKC_BASE                                 (0x40011000u)
  /** Peripheral PKC base pointer */
  #define PKC                                      ((PKC_Type *)PKC_BASE)
  /** Array initializer of PKC peripheral base addresses */
  #define PKC_BASE_ADDRS                           { PKC_BASE }
  /** Array initializer of PKC peripheral base pointers */
  #define PKC_BASE_PTRS                            { PKC }
#endif

/* PMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PMC0 base address */
  #define PMC0_BASE                                (0x5020F000u)
  /** Peripheral PMC0 base address */
  #define PMC0_BASE_NS                             (0x4020F000u)
  /** Peripheral PMC0 base pointer */
  #define PMC0                                     ((PMC_Type *)PMC0_BASE)
  /** Peripheral PMC0 base pointer */
  #define PMC0_NS                                  ((PMC_Type *)PMC0_BASE_NS)
  /** Array initializer of PMC peripheral base addresses */
  #define PMC_BASE_ADDRS                           { PMC0_BASE }
  /** Array initializer of PMC peripheral base pointers */
  #define PMC_BASE_PTRS                            { PMC0 }
  /** Array initializer of PMC peripheral base addresses */
  #define PMC_BASE_ADDRS_NS                        { PMC0_BASE_NS }
  /** Array initializer of PMC peripheral base pointers */
  #define PMC_BASE_PTRS_NS                         { PMC0_NS }
#else
  /** Peripheral PMC0 base address */
  #define PMC0_BASE                                (0x4020F000u)
  /** Peripheral PMC0 base pointer */
  #define PMC0                                     ((PMC_Type *)PMC0_BASE)
  /** Array initializer of PMC peripheral base addresses */
  #define PMC_BASE_ADDRS                           { PMC0_BASE }
  /** Array initializer of PMC peripheral base pointers */
  #define PMC_BASE_PTRS                            { PMC0 }
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

/* PUF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PUF base address */
  #define PUF_BASE                                 (0x50194000u)
  /** Peripheral PUF base address */
  #define PUF_BASE_NS                              (0x40194000u)
  /** Peripheral PUF base pointer */
  #define PUF                                      ((PUF_Type *)PUF_BASE)
  /** Peripheral PUF base pointer */
  #define PUF_NS                                   ((PUF_Type *)PUF_BASE_NS)
  /** Peripheral PUF_ALIAS1 base address */
  #define PUF_ALIAS1_BASE                          (0x50195000u)
  /** Peripheral PUF_ALIAS1 base address */
  #define PUF_ALIAS1_BASE_NS                       (0x40195000u)
  /** Peripheral PUF_ALIAS1 base pointer */
  #define PUF_ALIAS1                               ((PUF_Type *)PUF_ALIAS1_BASE)
  /** Peripheral PUF_ALIAS1 base pointer */
  #define PUF_ALIAS1_NS                            ((PUF_Type *)PUF_ALIAS1_BASE_NS)
  /** Peripheral PUF_ALIAS2 base address */
  #define PUF_ALIAS2_BASE                          (0x50196000u)
  /** Peripheral PUF_ALIAS2 base address */
  #define PUF_ALIAS2_BASE_NS                       (0x40196000u)
  /** Peripheral PUF_ALIAS2 base pointer */
  #define PUF_ALIAS2                               ((PUF_Type *)PUF_ALIAS2_BASE)
  /** Peripheral PUF_ALIAS2 base pointer */
  #define PUF_ALIAS2_NS                            ((PUF_Type *)PUF_ALIAS2_BASE_NS)
  /** Peripheral PUF_ALIAS3 base address */
  #define PUF_ALIAS3_BASE                          (0x50197000u)
  /** Peripheral PUF_ALIAS3 base address */
  #define PUF_ALIAS3_BASE_NS                       (0x40197000u)
  /** Peripheral PUF_ALIAS3 base pointer */
  #define PUF_ALIAS3                               ((PUF_Type *)PUF_ALIAS3_BASE)
  /** Peripheral PUF_ALIAS3 base pointer */
  #define PUF_ALIAS3_NS                            ((PUF_Type *)PUF_ALIAS3_BASE_NS)
  /** Array initializer of PUF peripheral base addresses */
  #define PUF_BASE_ADDRS                           { PUF_BASE, PUF_ALIAS1_BASE, PUF_ALIAS2_BASE, PUF_ALIAS3_BASE }
  /** Array initializer of PUF peripheral base pointers */
  #define PUF_BASE_PTRS                            { PUF, PUF_ALIAS1, PUF_ALIAS2, PUF_ALIAS3 }
  /** Array initializer of PUF peripheral base addresses */
  #define PUF_BASE_ADDRS_NS                        { PUF_BASE_NS, PUF_ALIAS1_BASE_NS, PUF_ALIAS2_BASE_NS, PUF_ALIAS3_BASE_NS }
  /** Array initializer of PUF peripheral base pointers */
  #define PUF_BASE_PTRS_NS                         { PUF_NS, PUF_ALIAS1_NS, PUF_ALIAS2_NS, PUF_ALIAS3_NS }
#else
  /** Peripheral PUF base address */
  #define PUF_BASE                                 (0x40194000u)
  /** Peripheral PUF base pointer */
  #define PUF                                      ((PUF_Type *)PUF_BASE)
  /** Peripheral PUF_ALIAS1 base address */
  #define PUF_ALIAS1_BASE                          (0x40195000u)
  /** Peripheral PUF_ALIAS1 base pointer */
  #define PUF_ALIAS1                               ((PUF_Type *)PUF_ALIAS1_BASE)
  /** Peripheral PUF_ALIAS2 base address */
  #define PUF_ALIAS2_BASE                          (0x40196000u)
  /** Peripheral PUF_ALIAS2 base pointer */
  #define PUF_ALIAS2                               ((PUF_Type *)PUF_ALIAS2_BASE)
  /** Peripheral PUF_ALIAS3 base address */
  #define PUF_ALIAS3_BASE                          (0x40197000u)
  /** Peripheral PUF_ALIAS3 base pointer */
  #define PUF_ALIAS3                               ((PUF_Type *)PUF_ALIAS3_BASE)
  /** Array initializer of PUF peripheral base addresses */
  #define PUF_BASE_ADDRS                           { PUF_BASE, PUF_ALIAS1_BASE, PUF_ALIAS2_BASE, PUF_ALIAS3_BASE }
  /** Array initializer of PUF peripheral base pointers */
  #define PUF_BASE_PTRS                            { PUF, PUF_ALIAS1, PUF_ALIAS2, PUF_ALIAS3 }
#endif

/* PVTS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PVTS0 base address */
  #define PVTS0_BASE                               (0x50005000u)
  /** Peripheral PVTS0 base address */
  #define PVTS0_BASE_NS                            (0x40005000u)
  /** Peripheral PVTS0 base pointer */
  #define PVTS0                                    ((PVTS_Type *)PVTS0_BASE)
  /** Peripheral PVTS0 base pointer */
  #define PVTS0_NS                                 ((PVTS_Type *)PVTS0_BASE_NS)
  /** Array initializer of PVTS peripheral base addresses */
  #define PVTS_BASE_ADDRS                          { PVTS0_BASE }
  /** Array initializer of PVTS peripheral base pointers */
  #define PVTS_BASE_PTRS                           { PVTS0 }
  /** Array initializer of PVTS peripheral base addresses */
  #define PVTS_BASE_ADDRS_NS                       { PVTS0_BASE_NS }
  /** Array initializer of PVTS peripheral base pointers */
  #define PVTS_BASE_PTRS_NS                        { PVTS0_NS }
#else
  /** Peripheral PVTS0 base address */
  #define PVTS0_BASE                               (0x40005000u)
  /** Peripheral PVTS0 base pointer */
  #define PVTS0                                    ((PVTS_Type *)PVTS0_BASE)
  /** Array initializer of PVTS peripheral base addresses */
  #define PVTS_BASE_ADDRS                          { PVTS0_BASE }
  /** Array initializer of PVTS peripheral base pointers */
  #define PVTS_BASE_PTRS                           { PVTS0 }
#endif

/* ROMCP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ROMCP base address */
  #define ROMCP_BASE                               (0x50182000u)
  /** Peripheral ROMCP base address */
  #define ROMCP_BASE_NS                            (0x40182000u)
  /** Peripheral ROMCP base pointer */
  #define ROMCP                                    ((ROMCP_Type *)ROMCP_BASE)
  /** Peripheral ROMCP base pointer */
  #define ROMCP_NS                                 ((ROMCP_Type *)ROMCP_BASE_NS)
  /** Array initializer of ROMCP peripheral base addresses */
  #define ROMCP_BASE_ADDRS                         { ROMCP_BASE }
  /** Array initializer of ROMCP peripheral base pointers */
  #define ROMCP_BASE_PTRS                          { ROMCP }
  /** Array initializer of ROMCP peripheral base addresses */
  #define ROMCP_BASE_ADDRS_NS                      { ROMCP_BASE_NS }
  /** Array initializer of ROMCP peripheral base pointers */
  #define ROMCP_BASE_PTRS_NS                       { ROMCP_NS }
#else
  /** Peripheral ROMCP base address */
  #define ROMCP_BASE                               (0x40182000u)
  /** Peripheral ROMCP base pointer */
  #define ROMCP                                    ((ROMCP_Type *)ROMCP_BASE)
  /** Array initializer of ROMCP peripheral base addresses */
  #define ROMCP_BASE_ADDRS                         { ROMCP_BASE }
  /** Array initializer of ROMCP peripheral base pointers */
  #define ROMCP_BASE_PTRS                          { ROMCP }
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
  /** Peripheral RTC0 base address */
  #define RTC0_BASE                                (0x50068000u)
  /** Peripheral RTC0 base address */
  #define RTC0_BASE_NS                             (0x40068000u)
  /** Peripheral RTC0 base pointer */
  #define RTC0                                     ((RTC_Type *)RTC0_BASE)
  /** Peripheral RTC0 base pointer */
  #define RTC0_NS                                  ((RTC_Type *)RTC0_BASE_NS)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { RTC0_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { RTC0 }
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS_NS                        { RTC0_BASE_NS }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS_NS                         { RTC0_NS }
#else
  /** Peripheral RTC0 base address */
  #define RTC0_BASE                                (0x40068000u)
  /** Peripheral RTC0 base pointer */
  #define RTC0                                     ((RTC_Type *)RTC0_BASE)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { RTC0_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { RTC0 }
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
/** Interrupt vectors for the SCT peripheral type */
#define SCT_IRQS                                 { SCT0_IRQn }

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
  /** Peripheral SEMA42_4 base address */
  #define SEMA42_4_BASE                            (0x5018A000u)
  /** Peripheral SEMA42_4 base address */
  #define SEMA42_4_BASE_NS                         (0x4018A000u)
  /** Peripheral SEMA42_4 base pointer */
  #define SEMA42_4                                 ((SEMA42_Type *)SEMA42_4_BASE)
  /** Peripheral SEMA42_4 base pointer */
  #define SEMA42_4_NS                              ((SEMA42_Type *)SEMA42_4_BASE_NS)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA42_0_BASE, 0u, 0u, 0u, SEMA42_4_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA42_0, (SEMA42_Type *)0u, (SEMA42_Type *)0u, (SEMA42_Type *)0u, SEMA42_4 }
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS_NS                     { SEMA42_0_BASE_NS, 0u, 0u, 0u, SEMA42_4_BASE_NS }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS_NS                      { SEMA42_0_NS, (SEMA42_Type *)0u, (SEMA42_Type *)0u, (SEMA42_Type *)0u, SEMA42_4_NS }
#else
  /** Peripheral SEMA42_0 base address */
  #define SEMA42_0_BASE                            (0x40206000u)
  /** Peripheral SEMA42_0 base pointer */
  #define SEMA42_0                                 ((SEMA42_Type *)SEMA42_0_BASE)
  /** Peripheral SEMA42_4 base address */
  #define SEMA42_4_BASE                            (0x4018A000u)
  /** Peripheral SEMA42_4 base pointer */
  #define SEMA42_4                                 ((SEMA42_Type *)SEMA42_4_BASE)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA42_0_BASE, 0u, 0u, 0u, SEMA42_4_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA42_0, (SEMA42_Type *)0u, (SEMA42_Type *)0u, (SEMA42_Type *)0u, SEMA42_4 }
#endif

/* SLEEPCON0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SLEEPCON0 base address */
  #define SLEEPCON0_BASE                           (0x50003000u)
  /** Peripheral SLEEPCON0 base address */
  #define SLEEPCON0_BASE_NS                        (0x40003000u)
  /** Peripheral SLEEPCON0 base pointer */
  #define SLEEPCON0                                ((SLEEPCON0_Type *)SLEEPCON0_BASE)
  /** Peripheral SLEEPCON0 base pointer */
  #define SLEEPCON0_NS                             ((SLEEPCON0_Type *)SLEEPCON0_BASE_NS)
  /** Array initializer of SLEEPCON0 peripheral base addresses */
  #define SLEEPCON0_BASE_ADDRS                     { SLEEPCON0_BASE }
  /** Array initializer of SLEEPCON0 peripheral base pointers */
  #define SLEEPCON0_BASE_PTRS                      { SLEEPCON0 }
  /** Array initializer of SLEEPCON0 peripheral base addresses */
  #define SLEEPCON0_BASE_ADDRS_NS                  { SLEEPCON0_BASE_NS }
  /** Array initializer of SLEEPCON0 peripheral base pointers */
  #define SLEEPCON0_BASE_PTRS_NS                   { SLEEPCON0_NS }
#else
  /** Peripheral SLEEPCON0 base address */
  #define SLEEPCON0_BASE                           (0x40003000u)
  /** Peripheral SLEEPCON0 base pointer */
  #define SLEEPCON0                                ((SLEEPCON0_Type *)SLEEPCON0_BASE)
  /** Array initializer of SLEEPCON0 peripheral base addresses */
  #define SLEEPCON0_BASE_ADDRS                     { SLEEPCON0_BASE }
  /** Array initializer of SLEEPCON0 peripheral base pointers */
  #define SLEEPCON0_BASE_PTRS                      { SLEEPCON0 }
#endif

/* SYSCON0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON0 base address */
  #define SYSCON0_BASE                             (0x50002000u)
  /** Peripheral SYSCON0 base address */
  #define SYSCON0_BASE_NS                          (0x40002000u)
  /** Peripheral SYSCON0 base pointer */
  #define SYSCON0                                  ((SYSCON0_Type *)SYSCON0_BASE)
  /** Peripheral SYSCON0 base pointer */
  #define SYSCON0_NS                               ((SYSCON0_Type *)SYSCON0_BASE_NS)
  /** Array initializer of SYSCON0 peripheral base addresses */
  #define SYSCON0_BASE_ADDRS                       { SYSCON0_BASE }
  /** Array initializer of SYSCON0 peripheral base pointers */
  #define SYSCON0_BASE_PTRS                        { SYSCON0 }
  /** Array initializer of SYSCON0 peripheral base addresses */
  #define SYSCON0_BASE_ADDRS_NS                    { SYSCON0_BASE_NS }
  /** Array initializer of SYSCON0 peripheral base pointers */
  #define SYSCON0_BASE_PTRS_NS                     { SYSCON0_NS }
#else
  /** Peripheral SYSCON0 base address */
  #define SYSCON0_BASE                             (0x40002000u)
  /** Peripheral SYSCON0 base pointer */
  #define SYSCON0                                  ((SYSCON0_Type *)SYSCON0_BASE)
  /** Array initializer of SYSCON0 peripheral base addresses */
  #define SYSCON0_BASE_ADDRS                       { SYSCON0_BASE }
  /** Array initializer of SYSCON0 peripheral base pointers */
  #define SYSCON0_BASE_PTRS                        { SYSCON0 }
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

/* SYSPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMX_PERFMON0 base address */
  #define CMX_PERFMON0_BASE                        (0x5018C000u)
  /** Peripheral CMX_PERFMON0 base address */
  #define CMX_PERFMON0_BASE_NS                     (0x4018C000u)
  /** Peripheral CMX_PERFMON0 base pointer */
  #define CMX_PERFMON0                             ((SYSPM_Type *)CMX_PERFMON0_BASE)
  /** Peripheral CMX_PERFMON0 base pointer */
  #define CMX_PERFMON0_NS                          ((SYSPM_Type *)CMX_PERFMON0_BASE_NS)
  /** Peripheral CMX_PERFMON1 base address */
  #define CMX_PERFMON1_BASE                        (0x5018D000u)
  /** Peripheral CMX_PERFMON1 base address */
  #define CMX_PERFMON1_BASE_NS                     (0x4018D000u)
  /** Peripheral CMX_PERFMON1 base pointer */
  #define CMX_PERFMON1                             ((SYSPM_Type *)CMX_PERFMON1_BASE)
  /** Peripheral CMX_PERFMON1 base pointer */
  #define CMX_PERFMON1_NS                          ((SYSPM_Type *)CMX_PERFMON1_BASE_NS)
  /** Peripheral CMX_PERFMON2 base address */
  #define CMX_PERFMON2_BASE                        (0x5018E000u)
  /** Peripheral CMX_PERFMON2 base address */
  #define CMX_PERFMON2_BASE_NS                     (0x4018E000u)
  /** Peripheral CMX_PERFMON2 base pointer */
  #define CMX_PERFMON2                             ((SYSPM_Type *)CMX_PERFMON2_BASE)
  /** Peripheral CMX_PERFMON2 base pointer */
  #define CMX_PERFMON2_NS                          ((SYSPM_Type *)CMX_PERFMON2_BASE_NS)
  /** Peripheral CMX_PERFMON3 base address */
  #define CMX_PERFMON3_BASE                        (0x5018F000u)
  /** Peripheral CMX_PERFMON3 base address */
  #define CMX_PERFMON3_BASE_NS                     (0x4018F000u)
  /** Peripheral CMX_PERFMON3 base pointer */
  #define CMX_PERFMON3                             ((SYSPM_Type *)CMX_PERFMON3_BASE)
  /** Peripheral CMX_PERFMON3 base pointer */
  #define CMX_PERFMON3_NS                          ((SYSPM_Type *)CMX_PERFMON3_BASE_NS)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { CMX_PERFMON0_BASE, CMX_PERFMON1_BASE, CMX_PERFMON2_BASE, CMX_PERFMON3_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { CMX_PERFMON0, CMX_PERFMON1, CMX_PERFMON2, CMX_PERFMON3 }
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS_NS                      { CMX_PERFMON0_BASE_NS, CMX_PERFMON1_BASE_NS, CMX_PERFMON2_BASE_NS, CMX_PERFMON3_BASE_NS }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS_NS                       { CMX_PERFMON0_NS, CMX_PERFMON1_NS, CMX_PERFMON2_NS, CMX_PERFMON3_NS }
#else
  /** Peripheral CMX_PERFMON0 base address */
  #define CMX_PERFMON0_BASE                        (0x4018C000u)
  /** Peripheral CMX_PERFMON0 base pointer */
  #define CMX_PERFMON0                             ((SYSPM_Type *)CMX_PERFMON0_BASE)
  /** Peripheral CMX_PERFMON1 base address */
  #define CMX_PERFMON1_BASE                        (0x4018D000u)
  /** Peripheral CMX_PERFMON1 base pointer */
  #define CMX_PERFMON1                             ((SYSPM_Type *)CMX_PERFMON1_BASE)
  /** Peripheral CMX_PERFMON2 base address */
  #define CMX_PERFMON2_BASE                        (0x4018E000u)
  /** Peripheral CMX_PERFMON2 base pointer */
  #define CMX_PERFMON2                             ((SYSPM_Type *)CMX_PERFMON2_BASE)
  /** Peripheral CMX_PERFMON3 base address */
  #define CMX_PERFMON3_BASE                        (0x4018F000u)
  /** Peripheral CMX_PERFMON3 base pointer */
  #define CMX_PERFMON3                             ((SYSPM_Type *)CMX_PERFMON3_BASE)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { CMX_PERFMON0_BASE, CMX_PERFMON1_BASE, CMX_PERFMON2_BASE, CMX_PERFMON3_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { CMX_PERFMON0, CMX_PERFMON1, CMX_PERFMON2, CMX_PERFMON3 }
#endif

/* TRNG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRNG base address */
  #define TRNG_BASE                                (0x50187000u)
  /** Peripheral TRNG base address */
  #define TRNG_BASE_NS                             (0x40187000u)
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
  #define TRNG_BASE                                (0x40187000u)
  /** Peripheral TRNG base pointer */
  #define TRNG                                     ((TRNG_Type *)TRNG_BASE)
  /** Array initializer of TRNG peripheral base addresses */
  #define TRNG_BASE_ADDRS                          { TRNG_BASE }
  /** Array initializer of TRNG peripheral base pointers */
  #define TRNG_BASE_PTRS                           { TRNG }
#endif
/** Interrupt vectors for the TRNG peripheral type */
#define TRNG_IRQS                                { TRNG_IRQn }
/* Backward compatibility */
#define TRNG0                                    TRNG


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

/* XCACHE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCACHE0 base address */
  #define XCACHE0_BASE                             (0x50033000u)
  /** Peripheral XCACHE0 base address */
  #define XCACHE0_BASE_NS                          (0x40033000u)
  /** Peripheral XCACHE0 base pointer */
  #define XCACHE0                                  ((XCACHE_Type *)XCACHE0_BASE)
  /** Peripheral XCACHE0 base pointer */
  #define XCACHE0_NS                               ((XCACHE_Type *)XCACHE0_BASE_NS)
  /** Peripheral XCACHE1 base address */
  #define XCACHE1_BASE                             (0x50034000u)
  /** Peripheral XCACHE1 base address */
  #define XCACHE1_BASE_NS                          (0x40034000u)
  /** Peripheral XCACHE1 base pointer */
  #define XCACHE1                                  ((XCACHE_Type *)XCACHE1_BASE)
  /** Peripheral XCACHE1 base pointer */
  #define XCACHE1_NS                               ((XCACHE_Type *)XCACHE1_BASE_NS)
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS                        { XCACHE0_BASE, XCACHE1_BASE }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS                         { XCACHE0, XCACHE1 }
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS_NS                     { XCACHE0_BASE_NS, XCACHE1_BASE_NS }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS_NS                      { XCACHE0_NS, XCACHE1_NS }
#else
  /** Peripheral XCACHE0 base address */
  #define XCACHE0_BASE                             (0x40033000u)
  /** Peripheral XCACHE0 base pointer */
  #define XCACHE0                                  ((XCACHE_Type *)XCACHE0_BASE)
  /** Peripheral XCACHE1 base address */
  #define XCACHE1_BASE                             (0x40034000u)
  /** Peripheral XCACHE1 base pointer */
  #define XCACHE1                                  ((XCACHE_Type *)XCACHE1_BASE)
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS                        { XCACHE0_BASE, XCACHE1_BASE }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS                         { XCACHE0, XCACHE1 }
#endif
/** XCACHE physical memory base address */
 #define XCACHE_PHYMEM_BASES                       { 0x20000000u, 0x00000000u }
/** XCACHE physical memory size */
 #define XCACHE_PHYMEM_SIZES                       { 0x780000u, 0x780000u }
/* Backward compatibility */
#define XCACHE_CSAR_PHYADDR_MASK (XCACHE_CSAR_PHYADDR27_1_MASK | XCACHE_CSAR_PHYADDR31_29_MASK)


/* XSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XSPI0 base address */
  #define XSPI0_BASE                               (0x50184000u)
  /** Peripheral XSPI0 base address */
  #define XSPI0_BASE_NS                            (0x40184000u)
  /** Peripheral XSPI0 base pointer */
  #define XSPI0                                    ((XSPI_Type *)XSPI0_BASE)
  /** Peripheral XSPI0 base pointer */
  #define XSPI0_NS                                 ((XSPI_Type *)XSPI0_BASE_NS)
  /** Peripheral XSPI1 base address */
  #define XSPI1_BASE                               (0x50185000u)
  /** Peripheral XSPI1 base address */
  #define XSPI1_BASE_NS                            (0x40185000u)
  /** Peripheral XSPI1 base pointer */
  #define XSPI1                                    ((XSPI_Type *)XSPI1_BASE)
  /** Peripheral XSPI1 base pointer */
  #define XSPI1_NS                                 ((XSPI_Type *)XSPI1_BASE_NS)
  /** Peripheral XSPI2 base address */
  #define XSPI2_BASE                               (0x50411000u)
  /** Peripheral XSPI2 base address */
  #define XSPI2_BASE_NS                            (0x40411000u)
  /** Peripheral XSPI2 base pointer */
  #define XSPI2                                    ((XSPI_Type *)XSPI2_BASE)
  /** Peripheral XSPI2 base pointer */
  #define XSPI2_NS                                 ((XSPI_Type *)XSPI2_BASE_NS)
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS                          { XSPI0_BASE, XSPI1_BASE, XSPI2_BASE }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS                           { XSPI0, XSPI1, XSPI2 }
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS_NS                       { XSPI0_BASE_NS, XSPI1_BASE_NS, XSPI2_BASE_NS }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS_NS                        { XSPI0_NS, XSPI1_NS, XSPI2_NS }
#else
  /** Peripheral XSPI0 base address */
  #define XSPI0_BASE                               (0x40184000u)
  /** Peripheral XSPI0 base pointer */
  #define XSPI0                                    ((XSPI_Type *)XSPI0_BASE)
  /** Peripheral XSPI1 base address */
  #define XSPI1_BASE                               (0x40185000u)
  /** Peripheral XSPI1 base pointer */
  #define XSPI1                                    ((XSPI_Type *)XSPI1_BASE)
  /** Peripheral XSPI2 base address */
  #define XSPI2_BASE                               (0x40411000u)
  /** Peripheral XSPI2 base pointer */
  #define XSPI2                                    ((XSPI_Type *)XSPI2_BASE)
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS                          { XSPI0_BASE, XSPI1_BASE, XSPI2_BASE }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS                           { XSPI0, XSPI1, XSPI2 }
#endif
/** Interrupt vectors for the XSPI peripheral type */
#define XSPI_IRQS                                { XSPI0_IRQn, XSPI1_IRQn, XSPI2_IRQn }
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


#endif  /* MIMXRT798S_CM33_CORE0_COMMON_H_ */

