/*
** ###################################################################
**     Processors:          MKS22FN128VFT12
**                          MKS22FN128VLH12
**                          MKS22FN128VLL12
**                          MKS22FN256VFT12
**                          MKS22FN256VLH12
**                          MKS22FN256VLL12
**
**     Compilers:           Keil ARM C/C++ Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          MCUXpresso Compiler
**
**     Reference manual:    KS22P100M120SF0RM, Rev. 3, May, 2016
**     Version:             rev. 2.1, 2017-06-09
**     Build:               b171205
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MKS22F12
**
**     The Clear BSD License
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without
**     modification, are permitted (subject to the limitations in the
**     disclaimer below) provided that the following conditions are met:
**
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**
**     * Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from
**       this software without specific prior written permission.
**
**     NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
**     GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
**     HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
**     WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
**     MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
**     LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
**     CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
**     SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
**     BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
**     WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
**     OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
**     IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-06-23)
**         Initial version.
**     - rev. 2.0 (2015-10-10)
**         Update according to Rev1 RM, Sep 2015.
**     - rev. 2.1 (2017-06-09)
**         Update according to Rev3 RM, May 2016.
**
** ###################################################################
*/

/*!
 * @file MKS22F12.h
 * @version 2.1
 * @date 2017-06-09
 * @brief CMSIS Peripheral Access Layer for MKS22F12
 *
 * CMSIS Peripheral Access Layer for MKS22F12
 */

#ifndef _MKS22F12_H_
#define _MKS22F12_H_                             /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0200U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0001U

/**
 * @brief Macro to calculate address of an aliased word in the peripheral
 *        bitband area for a peripheral register and bit (bit band region 0x40000000 to
 *        0x400FFFFF).
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return  Address of the aliased word in the peripheral bitband area.
 */
#define BITBAND_REGADDR(Reg,Bit) (0x42000000u + (32u*((uint32_t)&(Reg) - (uint32_t)0x40000000u)) + (4u*((uint32_t)(Bit))))
/**
 * @brief Macro to access a single bit of a peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access. Can
 *        be used for peripherals with 32bit access allowed.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */
#define BITBAND_REG32(Reg,Bit) (*((uint32_t volatile*)(BITBAND_REGADDR((Reg),(Bit)))))
#define BITBAND_REG(Reg,Bit) (BITBAND_REG32((Reg),(Bit)))
/**
 * @brief Macro to access a single bit of a peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access. Can
 *        be used for peripherals with 16bit access allowed.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */
#define BITBAND_REG16(Reg,Bit) (*((uint16_t volatile*)(BITBAND_REGADDR((Reg),(Bit)))))
/**
 * @brief Macro to access a single bit of a peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access. Can
 *        be used for peripherals with 8bit access allowed.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */
#define BITBAND_REG8(Reg,Bit) (*((uint8_t volatile*)(BITBAND_REGADDR((Reg),(Bit)))))

/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 116                /**< Number of interrupts in the Vector table */

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
  DMA0_IRQn                    = 0,                /**< DMA Channel 0 Transfer Complete */
  DMA1_IRQn                    = 1,                /**< DMA Channel 1 Transfer Complete */
  DMA2_IRQn                    = 2,                /**< DMA Channel 2 Transfer Complete */
  DMA3_IRQn                    = 3,                /**< DMA Channel 3 Transfer Complete */
  DMA4_IRQn                    = 4,                /**< DMA Channel 4 Transfer Complete */
  DMA5_IRQn                    = 5,                /**< DMA Channel 5 Transfer Complete */
  DMA6_IRQn                    = 6,                /**< DMA Channel 6 Transfer Complete */
  DMA7_IRQn                    = 7,                /**< DMA Channel 7 Transfer Complete */
  DMA8_IRQn                    = 8,                /**< DMA Channel 8 Transfer Complete */
  DMA9_IRQn                    = 9,                /**< DMA Channel 9 Transfer Complete */
  DMA10_IRQn                   = 10,               /**< DMA Channel 10 Transfer Complete */
  DMA11_IRQn                   = 11,               /**< DMA Channel 11 Transfer Complete */
  DMA12_IRQn                   = 12,               /**< DMA Channel 12 Transfer Complete */
  DMA13_IRQn                   = 13,               /**< DMA Channel 13 Transfer Complete */
  DMA14_IRQn                   = 14,               /**< DMA Channel 14 Transfer Complete */
  DMA15_IRQn                   = 15,               /**< DMA Channel 15 Transfer Complete */
  DMA_Error_IRQn               = 16,               /**< DMA Error Interrupt */
  MCM_IRQn                     = 17,               /**< Normal Interrupt */
  FTF_IRQn                     = 18,               /**< FTFA Command complete interrupt */
  Read_Collision_IRQn          = 19,               /**< Read Collision Interrupt */
  LVD_LVW_IRQn                 = 20,               /**< Low Voltage Detect, Low Voltage Warning */
  LLWU_IRQn                    = 21,               /**< Low Leakage Wakeup Unit */
  WDOG_EWM_IRQn                = 22,               /**< WDOG Interrupt */
  RNG_IRQn                     = 23,               /**< RNG Interrupt */
  LPI2C0_IRQn                  = 24,               /**< LPI2C0 interrupt */
  LPI2C1_IRQn                  = 25,               /**< LPI2C1 interrupt */
  SPI0_IRQn                    = 26,               /**< SPI0 Interrupt */
  SPI1_IRQn                    = 27,               /**< SPI1 Interrupt */
  I2S0_Tx_IRQn                 = 28,               /**< I2S0 transmit interrupt */
  I2S0_Rx_IRQn                 = 29,               /**< I2S0 receive interrupt */
  LPUART0_IRQn                 = 30,               /**< LPUART0 status/error interrupt */
  UART0_RX_TX_IRQn             = 31,               /**< UART0 Status Sources interrupt */
  UART0_ERR_IRQn               = 32,               /**< UART0 Error Sources interrupt */
  UART1_RX_TX_IRQn             = 33,               /**< UART1 Status Sources interrupt */
  UART1_ERR_IRQn               = 34,               /**< UART1 Error Sources interrupt */
  UART2_RX_TX_IRQn             = 35,               /**< UART2 Status Sources interrupt */
  UART2_ERR_IRQn               = 36,               /**< UART2 Error Sources interrupt */
  Reserved53_IRQn              = 37,               /**< Reserved interrupt 53 */
  Reserved54_IRQn              = 38,               /**< Reserved interrupt 54 */
  ADC0_IRQn                    = 39,               /**< ADC0 interrupt */
  CMP0_IRQn                    = 40,               /**< CMP0 interrupt */
  Reserved57_IRQn              = 41,               /**< Reserved interrupt 57 */
  TPM0_IRQn                    = 42,               /**< TPM0 Timer Overflow and Channels interrupt */
  TPM1_IRQn                    = 43,               /**< TPM1 Timer Overflow and Channels interrupt */
  TPM2_IRQn                    = 44,               /**< TPM2 Timer Overflow and Channels interrupt */
  Reserved61_IRQn              = 45,               /**< Reserved interrupt 61 */
  RTC_IRQn                     = 46,               /**< RTC alarm interrupt */
  RTC_Seconds_IRQn             = 47,               /**< RTC seconds interrupt */
  PIT0_IRQn                    = 48,               /**< PIT timer channel 0 interrupt */
  PIT1_IRQn                    = 49,               /**< PIT timer channel 1 interrupt */
  PIT2_IRQn                    = 50,               /**< PIT timer channel 2 interrupt */
  PIT3_IRQn                    = 51,               /**< PIT timer channel 3 interrupt */
  PDB0_IRQn                    = 52,               /**< PDB0 Interrupt */
  USB0_IRQn                    = 53,               /**< USB0 interrupt */
  Reserved70_IRQn              = 54,               /**< Reserved interrupt 70 */
  Reserved71_IRQn              = 55,               /**< Reserved interrupt 71 */
  DAC0_IRQn                    = 56,               /**< DAC0 interrupt */
  MCG_IRQn                     = 57,               /**< MCG Interrupt */
  LPTMR0_IRQn                  = 58,               /**< LPTimer interrupt */
  PORTA_IRQn                   = 59,               /**< Port A interrupt */
  PORTB_IRQn                   = 60,               /**< Port B interrupt */
  PORTC_IRQn                   = 61,               /**< Port C interrupt */
  PORTD_IRQn                   = 62,               /**< Port D interrupt */
  PORTE_IRQn                   = 63,               /**< Port E interrupt */
  SWI_IRQn                     = 64,               /**< Software interrupt */
  Reserved81_IRQn              = 65,               /**< Reserved interrupt 81 */
  Reserved82_IRQn              = 66,               /**< Reserved interrupt 82 */
  Reserved83_IRQn              = 67,               /**< Reserved interrupt 83 */
  Reserved84_IRQn              = 68,               /**< Reserved interrupt 84 */
  Reserved85_IRQn              = 69,               /**< Reserved interrupt 85 */
  FLEXIO_IRQn                  = 70,               /**< Flexible IO interrupt */
  Reserved87_IRQn              = 71,               /**< Reserved interrupt 87 */
  Reserved88_IRQn              = 72,               /**< Reserved interrupt 88 */
  Reserved89_IRQn              = 73,               /**< Reserved interrupt 89 */
  Reserved90_IRQn              = 74,               /**< Reserved Interrupt 90 */
  CAN0_ORed_Message_buffer_IRQn = 75,              /**< CAN0 OR'd message buffers interrupt */
  CAN0_Bus_Off_IRQn            = 76,               /**< CAN0 bus off interrupt */
  CAN0_Error_IRQn              = 77,               /**< CAN0 error interrupt */
  CAN0_Tx_Warning_IRQn         = 78,               /**< CAN0 Tx warning interrupt */
  CAN0_Rx_Warning_IRQn         = 79,               /**< CAN0 Rx warning interrupt */
  CAN0_Wake_Up_IRQn            = 80,               /**< CAN0 wake up interrupt */
  Reserved97_IRQn              = 81,               /**< Reserved Interrupt 97 */
  Reserved98_IRQn              = 82,               /**< Reserved Interrupt 98 */
  Reserved99_IRQn              = 83,               /**< Reserved Interrupt 99 */
  Reserved100_IRQn             = 84,               /**< Reserved Interrupt 100 */
  Reserved101_IRQn             = 85,               /**< Reserved Interrupt 101 */
  Reserved102_IRQn             = 86,               /**< Reserved Interrupt 102 */
  Reserved103_IRQn             = 87,               /**< Reserved Interrupt 103 */
  I2S1_Tx_IRQn                 = 88,               /**< I2S1 transmit interrupt */
  I2S1_Rx_IRQn                 = 89,               /**< I2S1 receive interrupt */
  Reserved106_IRQn             = 90,               /**< Reserved Interrupt 106 */
  Reserved107_IRQn             = 91,               /**< Reserved Interrupt 107 */
  Reserved108_IRQn             = 92,               /**< Reserved Interrupt 108 */
  Reserved109_IRQn             = 93,               /**< Reserved Interrupt 109 */
  CAN1_ORed_Message_buffer_IRQn = 94,              /**< CAN0 OR'd message buffers interrupt */
  CAN1_Bus_Off_IRQn            = 95,               /**< CAN1 bus off interrupt */
  CAN1_Error_IRQn              = 96,               /**< CAN1 error interrupt */
  CAN1_Tx_Warning_IRQn         = 97,               /**< CAN1 Tx warning interrupt */
  CAN1_Rx_Warning_IRQn         = 98,               /**< CAN1 Rx warning interrupt */
  CAN1_Wake_Up_IRQn            = 99                /**< CAN1 wake up interrupt */
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

#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */

#include "core_cm4.h"                  /* Core Peripheral Access Layer */
#include "system_MKS22F12.h"           /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


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
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum _dma_request_source
{
    kDmaRequestMux0Disable          = 0|0x100U,    /**< DMAMUX TriggerDisabled. */
    kDmaRequestMux0Reserved1        = 1|0x100U,    /**< Reserved1 */
    kDmaRequestMux0UART0Rx          = 2|0x100U,    /**< UART0 Receive. */
    kDmaRequestMux0UART0Tx          = 3|0x100U,    /**< UART0 Transmit. */
    kDmaRequestMux0UART1Rx          = 4|0x100U,    /**< UART1 Receive. */
    kDmaRequestMux0UART1Tx          = 5|0x100U,    /**< UART1 Transmit. */
    kDmaRequestMux0UART2Rx          = 6|0x100U,    /**< UART2 Receive. */
    kDmaRequestMux0UART2Tx          = 7|0x100U,    /**< UART2 Transmit. */
    kDmaRequestMux0Reserved8        = 8|0x100U,    /**< Reserved8 */
    kDmaRequestMux0Reserved9        = 9|0x100U,    /**< Reserved9 */
    kDmaRequestMux0Reserved10       = 10|0x100U,   /**< Reserved10 */
    kDmaRequestMux0FlexCAN0         = 11|0x100U,   /**< CAN0. */
    kDmaRequestMux0I2S0Rx           = 12|0x100U,   /**< I2S0 Receive. */
    kDmaRequestMux0I2S0Tx           = 13|0x100U,   /**< I2S0 Transmit. */
    kDmaRequestMux0SPI0Rx           = 14|0x100U,   /**< SPI0 Receive. */
    kDmaRequestMux0SPI0Tx           = 15|0x100U,   /**< SPI0 Transmit. */
    kDmaRequestMux0SPI1             = 16|0x100U,   /**< SPI1 Transmit or Receive. */
    kDmaRequestMux0Reserved17       = 17|0x100U,   /**< Reserved17 */
    kDmaRequestMux0LPI2C0Rx         = 18|0x100U,   /**< LPI2C0 Receive. */
    kDmaRequestMux0LPI2C1Rx         = 19|0x100U,   /**< LPI2C1 Receive. */
    kDmaRequestMux0TPM0Channel0     = 20|0x100U,   /**< TPM0 C0V. */
    kDmaRequestMux0TPM0Channel1     = 21|0x100U,   /**< TPM0 C1V. */
    kDmaRequestMux0TPM0Channel2     = 22|0x100U,   /**< TPM0 C2V. */
    kDmaRequestMux0TPM0Channel3     = 23|0x100U,   /**< TPM0 C3V. */
    kDmaRequestMux0TPM0Channel4     = 24|0x100U,   /**< TPM0 C4V. */
    kDmaRequestMux0TPM0Channel5     = 25|0x100U,   /**< TPM0 C5V. */
    kDmaRequestMux0LPI2C0Tx         = 26|0x100U,   /**< LPI2C0 Transmit. */
    kDmaRequestMux0LPI2C1Tx         = 27|0x100U,   /**< LPI2C1 Transmit. */
    kDmaRequestMux0TPM1Channel0     = 28|0x100U,   /**< TPM1 C0V. */
    kDmaRequestMux0TPM1Channel1     = 29|0x100U,   /**< TPM1 C1V. */
    kDmaRequestMux0TPM2Channel0     = 30|0x100U,   /**< TPM2 C0V. */
    kDmaRequestMux0TPM2Channel1     = 31|0x100U,   /**< TPM2 C1V. */
    kDmaRequestMux0Reserved32       = 32|0x100U,   /**< Reserved32 */
    kDmaRequestMux0Reserved33       = 33|0x100U,   /**< Reserved33 */
    kDmaRequestMux0Reserved34       = 34|0x100U,   /**< Reserved34 */
    kDmaRequestMux0Reserved35       = 35|0x100U,   /**< Reserved35 */
    kDmaRequestMux0Reserved36       = 36|0x100U,   /**< Reserved36 */
    kDmaRequestMux0Reserved37       = 37|0x100U,   /**< Reserved37 */
    kDmaRequestMux0FlexIOChannel0   = 38|0x100U,   /**< FLEXIO. */
    kDmaRequestMux0FlexIOChannel1   = 39|0x100U,   /**< FLEXIO. */
    kDmaRequestMux0ADC0             = 40|0x100U,   /**< ADC0. */
    kDmaRequestMux0FlexCAN1         = 41|0x100U,   /**< CAN1. */
    kDmaRequestMux0CMP0             = 42|0x100U,   /**< CMP0. */
    kDmaRequestMux0FlexIOChannel2   = 43|0x100U,   /**< FLEXIO. */
    kDmaRequestMux0FlexIOChannel3   = 44|0x100U,   /**< FLEXIO. */
    kDmaRequestMux0DAC0             = 45|0x100U,   /**< DAC0. */
    kDmaRequestMux0I2S1Rx           = 46|0x100U,   /**< I2S1 Receive. */
    kDmaRequestMux0I2S1Tx           = 47|0x100U,   /**< I2S1 Transmit. */
    kDmaRequestMux0PDB              = 48|0x100U,   /**< PDB0. */
    kDmaRequestMux0PortA            = 49|0x100U,   /**< PTA. */
    kDmaRequestMux0PortB            = 50|0x100U,   /**< PTB. */
    kDmaRequestMux0PortC            = 51|0x100U,   /**< PTC. */
    kDmaRequestMux0PortD            = 52|0x100U,   /**< PTD. */
    kDmaRequestMux0PortE            = 53|0x100U,   /**< PTE. */
    kDmaRequestMux0TPM0Overflow     = 54|0x100U,   /**< TPM0. */
    kDmaRequestMux0TPM1Overflow     = 55|0x100U,   /**< TPM1. */
    kDmaRequestMux0TPM2Overflow     = 56|0x100U,   /**< TPM2. */
    kDmaRequestMux0Reserved57       = 57|0x100U,   /**< Reserved57 */
    kDmaRequestMux0LPUART0Rx        = 58|0x100U,   /**< LPUART0 Receive. */
    kDmaRequestMux0LPUART0Tx        = 59|0x100U,   /**< LPUART0 Transmit. */
    kDmaRequestMux0AlwaysOn60       = 60|0x100U,   /**< DMAMUX Always Enabled slot. */
    kDmaRequestMux0AlwaysOn61       = 61|0x100U,   /**< DMAMUX Always Enabled slot. */
    kDmaRequestMux0AlwaysOn62       = 62|0x100U,   /**< DMAMUX Always Enabled slot. */
    kDmaRequestMux0AlwaysOn63       = 63|0x100U,   /**< DMAMUX Always Enabled slot. */
} dma_request_source_t;

/* @} */


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC1[2];                            /**< ADC Status and Control Registers 1, array offset: 0x0, array step: 0x4 */
  __IO uint32_t CFG1;                              /**< ADC Configuration Register 1, offset: 0x8 */
  __IO uint32_t CFG2;                              /**< ADC Configuration Register 2, offset: 0xC */
  __I  uint32_t R[2];                              /**< ADC Data Result Register, array offset: 0x10, array step: 0x4 */
  __IO uint32_t CV1;                               /**< Compare Value Registers, offset: 0x18 */
  __IO uint32_t CV2;                               /**< Compare Value Registers, offset: 0x1C */
  __IO uint32_t SC2;                               /**< Status and Control Register 2, offset: 0x20 */
  __IO uint32_t SC3;                               /**< Status and Control Register 3, offset: 0x24 */
  __IO uint32_t OFS;                               /**< ADC Offset Correction Register, offset: 0x28 */
  __IO uint32_t PG;                                /**< ADC Plus-Side Gain Register, offset: 0x2C */
  __IO uint32_t MG;                                /**< ADC Minus-Side Gain Register, offset: 0x30 */
  __IO uint32_t CLPD;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x34 */
  __IO uint32_t CLPS;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x38 */
  __IO uint32_t CLP4;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x3C */
  __IO uint32_t CLP3;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x40 */
  __IO uint32_t CLP2;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x44 */
  __IO uint32_t CLP1;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x48 */
  __IO uint32_t CLP0;                              /**< ADC Plus-Side General Calibration Value Register, offset: 0x4C */
       uint8_t RESERVED_0[4];
  __IO uint32_t CLMD;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x54 */
  __IO uint32_t CLMS;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x58 */
  __IO uint32_t CLM4;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x5C */
  __IO uint32_t CLM3;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x60 */
  __IO uint32_t CLM2;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x64 */
  __IO uint32_t CLM1;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x68 */
  __IO uint32_t CLM0;                              /**< ADC Minus-Side General Calibration Value Register, offset: 0x6C */
} ADC_Type;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/*! @name SC1 - ADC Status and Control Registers 1 */
#define ADC_SC1_ADCH_MASK                        (0x1FU)
#define ADC_SC1_ADCH_SHIFT                       (0U)
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC1_ADCH_SHIFT)) & ADC_SC1_ADCH_MASK)
#define ADC_SC1_DIFF_MASK                        (0x20U)
#define ADC_SC1_DIFF_SHIFT                       (5U)
#define ADC_SC1_DIFF(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC1_DIFF_SHIFT)) & ADC_SC1_DIFF_MASK)
#define ADC_SC1_AIEN_MASK                        (0x40U)
#define ADC_SC1_AIEN_SHIFT                       (6U)
#define ADC_SC1_AIEN(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC1_AIEN_SHIFT)) & ADC_SC1_AIEN_MASK)
#define ADC_SC1_COCO_MASK                        (0x80U)
#define ADC_SC1_COCO_SHIFT                       (7U)
#define ADC_SC1_COCO(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC1_COCO_SHIFT)) & ADC_SC1_COCO_MASK)

/* The count of ADC_SC1 */
#define ADC_SC1_COUNT                            (2U)

/*! @name CFG1 - ADC Configuration Register 1 */
#define ADC_CFG1_ADICLK_MASK                     (0x3U)
#define ADC_CFG1_ADICLK_SHIFT                    (0U)
#define ADC_CFG1_ADICLK(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CFG1_ADICLK_SHIFT)) & ADC_CFG1_ADICLK_MASK)
#define ADC_CFG1_MODE_MASK                       (0xCU)
#define ADC_CFG1_MODE_SHIFT                      (2U)
#define ADC_CFG1_MODE(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG1_MODE_SHIFT)) & ADC_CFG1_MODE_MASK)
#define ADC_CFG1_ADLSMP_MASK                     (0x10U)
#define ADC_CFG1_ADLSMP_SHIFT                    (4U)
#define ADC_CFG1_ADLSMP(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CFG1_ADLSMP_SHIFT)) & ADC_CFG1_ADLSMP_MASK)
#define ADC_CFG1_ADIV_MASK                       (0x60U)
#define ADC_CFG1_ADIV_SHIFT                      (5U)
#define ADC_CFG1_ADIV(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG1_ADIV_SHIFT)) & ADC_CFG1_ADIV_MASK)
#define ADC_CFG1_ADLPC_MASK                      (0x80U)
#define ADC_CFG1_ADLPC_SHIFT                     (7U)
#define ADC_CFG1_ADLPC(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG1_ADLPC_SHIFT)) & ADC_CFG1_ADLPC_MASK)

/*! @name CFG2 - ADC Configuration Register 2 */
#define ADC_CFG2_ADLSTS_MASK                     (0x3U)
#define ADC_CFG2_ADLSTS_SHIFT                    (0U)
#define ADC_CFG2_ADLSTS(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CFG2_ADLSTS_SHIFT)) & ADC_CFG2_ADLSTS_MASK)
#define ADC_CFG2_ADHSC_MASK                      (0x4U)
#define ADC_CFG2_ADHSC_SHIFT                     (2U)
#define ADC_CFG2_ADHSC(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG2_ADHSC_SHIFT)) & ADC_CFG2_ADHSC_MASK)
#define ADC_CFG2_ADACKEN_MASK                    (0x8U)
#define ADC_CFG2_ADACKEN_SHIFT                   (3U)
#define ADC_CFG2_ADACKEN(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CFG2_ADACKEN_SHIFT)) & ADC_CFG2_ADACKEN_MASK)
#define ADC_CFG2_MUXSEL_MASK                     (0x10U)
#define ADC_CFG2_MUXSEL_SHIFT                    (4U)
#define ADC_CFG2_MUXSEL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CFG2_MUXSEL_SHIFT)) & ADC_CFG2_MUXSEL_MASK)

/*! @name R - ADC Data Result Register */
#define ADC_R_D_MASK                             (0xFFFFU)
#define ADC_R_D_SHIFT                            (0U)
#define ADC_R_D(x)                               (((uint32_t)(((uint32_t)(x)) << ADC_R_D_SHIFT)) & ADC_R_D_MASK)

/* The count of ADC_R */
#define ADC_R_COUNT                              (2U)

/*! @name CV1 - Compare Value Registers */
#define ADC_CV1_CV_MASK                          (0xFFFFU)
#define ADC_CV1_CV_SHIFT                         (0U)
#define ADC_CV1_CV(x)                            (((uint32_t)(((uint32_t)(x)) << ADC_CV1_CV_SHIFT)) & ADC_CV1_CV_MASK)

/*! @name CV2 - Compare Value Registers */
#define ADC_CV2_CV_MASK                          (0xFFFFU)
#define ADC_CV2_CV_SHIFT                         (0U)
#define ADC_CV2_CV(x)                            (((uint32_t)(((uint32_t)(x)) << ADC_CV2_CV_SHIFT)) & ADC_CV2_CV_MASK)

/*! @name SC2 - Status and Control Register 2 */
#define ADC_SC2_REFSEL_MASK                      (0x3U)
#define ADC_SC2_REFSEL_SHIFT                     (0U)
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_SC2_REFSEL_SHIFT)) & ADC_SC2_REFSEL_MASK)
#define ADC_SC2_DMAEN_MASK                       (0x4U)
#define ADC_SC2_DMAEN_SHIFT                      (2U)
#define ADC_SC2_DMAEN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC2_DMAEN_SHIFT)) & ADC_SC2_DMAEN_MASK)
#define ADC_SC2_ACREN_MASK                       (0x8U)
#define ADC_SC2_ACREN_SHIFT                      (3U)
#define ADC_SC2_ACREN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC2_ACREN_SHIFT)) & ADC_SC2_ACREN_MASK)
#define ADC_SC2_ACFGT_MASK                       (0x10U)
#define ADC_SC2_ACFGT_SHIFT                      (4U)
#define ADC_SC2_ACFGT(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC2_ACFGT_SHIFT)) & ADC_SC2_ACFGT_MASK)
#define ADC_SC2_ACFE_MASK                        (0x20U)
#define ADC_SC2_ACFE_SHIFT                       (5U)
#define ADC_SC2_ACFE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC2_ACFE_SHIFT)) & ADC_SC2_ACFE_MASK)
#define ADC_SC2_ADTRG_MASK                       (0x40U)
#define ADC_SC2_ADTRG_SHIFT                      (6U)
#define ADC_SC2_ADTRG(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC2_ADTRG_SHIFT)) & ADC_SC2_ADTRG_MASK)
#define ADC_SC2_ADACT_MASK                       (0x80U)
#define ADC_SC2_ADACT_SHIFT                      (7U)
#define ADC_SC2_ADACT(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_SC2_ADACT_SHIFT)) & ADC_SC2_ADACT_MASK)

/*! @name SC3 - Status and Control Register 3 */
#define ADC_SC3_AVGS_MASK                        (0x3U)
#define ADC_SC3_AVGS_SHIFT                       (0U)
#define ADC_SC3_AVGS(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC3_AVGS_SHIFT)) & ADC_SC3_AVGS_MASK)
#define ADC_SC3_AVGE_MASK                        (0x4U)
#define ADC_SC3_AVGE_SHIFT                       (2U)
#define ADC_SC3_AVGE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC3_AVGE_SHIFT)) & ADC_SC3_AVGE_MASK)
#define ADC_SC3_ADCO_MASK                        (0x8U)
#define ADC_SC3_ADCO_SHIFT                       (3U)
#define ADC_SC3_ADCO(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC3_ADCO_SHIFT)) & ADC_SC3_ADCO_MASK)
#define ADC_SC3_CALF_MASK                        (0x40U)
#define ADC_SC3_CALF_SHIFT                       (6U)
#define ADC_SC3_CALF(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_SC3_CALF_SHIFT)) & ADC_SC3_CALF_MASK)
#define ADC_SC3_CAL_MASK                         (0x80U)
#define ADC_SC3_CAL_SHIFT                        (7U)
#define ADC_SC3_CAL(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_SC3_CAL_SHIFT)) & ADC_SC3_CAL_MASK)

/*! @name OFS - ADC Offset Correction Register */
#define ADC_OFS_OFS_MASK                         (0xFFFFU)
#define ADC_OFS_OFS_SHIFT                        (0U)
#define ADC_OFS_OFS(x)                           (((uint32_t)(((uint32_t)(x)) << ADC_OFS_OFS_SHIFT)) & ADC_OFS_OFS_MASK)

/*! @name PG - ADC Plus-Side Gain Register */
#define ADC_PG_PG_MASK                           (0xFFFFU)
#define ADC_PG_PG_SHIFT                          (0U)
#define ADC_PG_PG(x)                             (((uint32_t)(((uint32_t)(x)) << ADC_PG_PG_SHIFT)) & ADC_PG_PG_MASK)

/*! @name MG - ADC Minus-Side Gain Register */
#define ADC_MG_MG_MASK                           (0xFFFFU)
#define ADC_MG_MG_SHIFT                          (0U)
#define ADC_MG_MG(x)                             (((uint32_t)(((uint32_t)(x)) << ADC_MG_MG_SHIFT)) & ADC_MG_MG_MASK)

/*! @name CLPD - ADC Plus-Side General Calibration Value Register */
#define ADC_CLPD_CLPD_MASK                       (0x3FU)
#define ADC_CLPD_CLPD_SHIFT                      (0U)
#define ADC_CLPD_CLPD(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLPD_CLPD_SHIFT)) & ADC_CLPD_CLPD_MASK)

/*! @name CLPS - ADC Plus-Side General Calibration Value Register */
#define ADC_CLPS_CLPS_MASK                       (0x3FU)
#define ADC_CLPS_CLPS_SHIFT                      (0U)
#define ADC_CLPS_CLPS(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLPS_CLPS_SHIFT)) & ADC_CLPS_CLPS_MASK)

/*! @name CLP4 - ADC Plus-Side General Calibration Value Register */
#define ADC_CLP4_CLP4_MASK                       (0x3FFU)
#define ADC_CLP4_CLP4_SHIFT                      (0U)
#define ADC_CLP4_CLP4(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP4_CLP4_SHIFT)) & ADC_CLP4_CLP4_MASK)

/*! @name CLP3 - ADC Plus-Side General Calibration Value Register */
#define ADC_CLP3_CLP3_MASK                       (0x1FFU)
#define ADC_CLP3_CLP3_SHIFT                      (0U)
#define ADC_CLP3_CLP3(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP3_CLP3_SHIFT)) & ADC_CLP3_CLP3_MASK)

/*! @name CLP2 - ADC Plus-Side General Calibration Value Register */
#define ADC_CLP2_CLP2_MASK                       (0xFFU)
#define ADC_CLP2_CLP2_SHIFT                      (0U)
#define ADC_CLP2_CLP2(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP2_CLP2_SHIFT)) & ADC_CLP2_CLP2_MASK)

/*! @name CLP1 - ADC Plus-Side General Calibration Value Register */
#define ADC_CLP1_CLP1_MASK                       (0x7FU)
#define ADC_CLP1_CLP1_SHIFT                      (0U)
#define ADC_CLP1_CLP1(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP1_CLP1_SHIFT)) & ADC_CLP1_CLP1_MASK)

/*! @name CLP0 - ADC Plus-Side General Calibration Value Register */
#define ADC_CLP0_CLP0_MASK                       (0x3FU)
#define ADC_CLP0_CLP0_SHIFT                      (0U)
#define ADC_CLP0_CLP0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLP0_CLP0_SHIFT)) & ADC_CLP0_CLP0_MASK)

/*! @name CLMD - ADC Minus-Side General Calibration Value Register */
#define ADC_CLMD_CLMD_MASK                       (0x3FU)
#define ADC_CLMD_CLMD_SHIFT                      (0U)
#define ADC_CLMD_CLMD(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLMD_CLMD_SHIFT)) & ADC_CLMD_CLMD_MASK)

/*! @name CLMS - ADC Minus-Side General Calibration Value Register */
#define ADC_CLMS_CLMS_MASK                       (0x3FU)
#define ADC_CLMS_CLMS_SHIFT                      (0U)
#define ADC_CLMS_CLMS(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLMS_CLMS_SHIFT)) & ADC_CLMS_CLMS_MASK)

/*! @name CLM4 - ADC Minus-Side General Calibration Value Register */
#define ADC_CLM4_CLM4_MASK                       (0x3FFU)
#define ADC_CLM4_CLM4_SHIFT                      (0U)
#define ADC_CLM4_CLM4(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLM4_CLM4_SHIFT)) & ADC_CLM4_CLM4_MASK)

/*! @name CLM3 - ADC Minus-Side General Calibration Value Register */
#define ADC_CLM3_CLM3_MASK                       (0x1FFU)
#define ADC_CLM3_CLM3_SHIFT                      (0U)
#define ADC_CLM3_CLM3(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLM3_CLM3_SHIFT)) & ADC_CLM3_CLM3_MASK)

/*! @name CLM2 - ADC Minus-Side General Calibration Value Register */
#define ADC_CLM2_CLM2_MASK                       (0xFFU)
#define ADC_CLM2_CLM2_SHIFT                      (0U)
#define ADC_CLM2_CLM2(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLM2_CLM2_SHIFT)) & ADC_CLM2_CLM2_MASK)

/*! @name CLM1 - ADC Minus-Side General Calibration Value Register */
#define ADC_CLM1_CLM1_MASK                       (0x7FU)
#define ADC_CLM1_CLM1_SHIFT                      (0U)
#define ADC_CLM1_CLM1(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLM1_CLM1_SHIFT)) & ADC_CLM1_CLM1_MASK)

/*! @name CLM0 - ADC Minus-Side General Calibration Value Register */
#define ADC_CLM0_CLM0_MASK                       (0x3FU)
#define ADC_CLM0_CLM0_SHIFT                      (0U)
#define ADC_CLM0_CLM0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CLM0_CLM0_SHIFT)) & ADC_CLM0_CLM0_MASK)


/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x4003B000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn }

/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CAN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Peripheral_Access_Layer CAN Peripheral Access Layer
 * @{
 */

/** CAN - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration Register, offset: 0x0 */
  __IO uint32_t CTRL1;                             /**< Control 1 register, offset: 0x4 */
  __IO uint32_t TIMER;                             /**< Free Running Timer, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t RXMGMASK;                          /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
  __IO uint32_t RX14MASK;                          /**< Rx 14 Mask register, offset: 0x14 */
  __IO uint32_t RX15MASK;                          /**< Rx 15 Mask register, offset: 0x18 */
  __IO uint32_t ECR;                               /**< Error Counter, offset: 0x1C */
  __IO uint32_t ESR1;                              /**< Error and Status 1 register, offset: 0x20 */
       uint8_t RESERVED_1[4];
  __IO uint32_t IMASK1;                            /**< Interrupt Masks 1 register, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t IFLAG1;                            /**< Interrupt Flags 1 register, offset: 0x30 */
  __IO uint32_t CTRL2;                             /**< Control 2 register, offset: 0x34 */
  __I  uint32_t ESR2;                              /**< Error and Status 2 register, offset: 0x38 */
       uint8_t RESERVED_3[8];
  __I  uint32_t CRCR;                              /**< CRC Register, offset: 0x44 */
  __IO uint32_t RXFGMASK;                          /**< Rx FIFO Global Mask register, offset: 0x48 */
  __I  uint32_t RXFIR;                             /**< Rx FIFO Information Register, offset: 0x4C */
  __IO uint32_t CBT;                               /**< CAN Bit Timing Register, offset: 0x50 */
       uint8_t RESERVED_4[44];
  struct {                                         /* offset: 0x80, array step: 0x10 */
    __IO uint32_t CS;                                /**< Message Buffer 0 CS Register..Message Buffer 15 CS Register, array offset: 0x80, array step: 0x10 */
    __IO uint32_t ID;                                /**< Message Buffer 0 ID Register..Message Buffer 15 ID Register, array offset: 0x84, array step: 0x10 */
    __IO uint32_t WORD0;                             /**< Message Buffer 0 WORD0 Register..Message Buffer 15 WORD0 Register, array offset: 0x88, array step: 0x10 */
    __IO uint32_t WORD1;                             /**< Message Buffer 0 WORD1 Register..Message Buffer 15 WORD1 Register, array offset: 0x8C, array step: 0x10 */
  } MB[16];
       uint8_t RESERVED_5[1792];
  __IO uint32_t RXIMR[16];                         /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
} CAN_Type;

/* ----------------------------------------------------------------------------
   -- CAN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Register_Masks CAN Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
#define CAN_MCR_MAXMB_MASK                       (0x7FU)
#define CAN_MCR_MAXMB_SHIFT                      (0U)
#define CAN_MCR_MAXMB(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_MCR_MAXMB_SHIFT)) & CAN_MCR_MAXMB_MASK)
#define CAN_MCR_IDAM_MASK                        (0x300U)
#define CAN_MCR_IDAM_SHIFT                       (8U)
#define CAN_MCR_IDAM(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_IDAM_SHIFT)) & CAN_MCR_IDAM_MASK)
#define CAN_MCR_AEN_MASK                         (0x1000U)
#define CAN_MCR_AEN_SHIFT                        (12U)
#define CAN_MCR_AEN(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_MCR_AEN_SHIFT)) & CAN_MCR_AEN_MASK)
#define CAN_MCR_LPRIOEN_MASK                     (0x2000U)
#define CAN_MCR_LPRIOEN_SHIFT                    (13U)
#define CAN_MCR_LPRIOEN(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_MCR_LPRIOEN_SHIFT)) & CAN_MCR_LPRIOEN_MASK)
#define CAN_MCR_DMA_MASK                         (0x8000U)
#define CAN_MCR_DMA_SHIFT                        (15U)
#define CAN_MCR_DMA(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_MCR_DMA_SHIFT)) & CAN_MCR_DMA_MASK)
#define CAN_MCR_IRMQ_MASK                        (0x10000U)
#define CAN_MCR_IRMQ_SHIFT                       (16U)
#define CAN_MCR_IRMQ(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_IRMQ_SHIFT)) & CAN_MCR_IRMQ_MASK)
#define CAN_MCR_SRXDIS_MASK                      (0x20000U)
#define CAN_MCR_SRXDIS_SHIFT                     (17U)
#define CAN_MCR_SRXDIS(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SRXDIS_SHIFT)) & CAN_MCR_SRXDIS_MASK)
#define CAN_MCR_DOZE_MASK                        (0x40000U)
#define CAN_MCR_DOZE_SHIFT                       (18U)
#define CAN_MCR_DOZE(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_DOZE_SHIFT)) & CAN_MCR_DOZE_MASK)
#define CAN_MCR_WAKSRC_MASK                      (0x80000U)
#define CAN_MCR_WAKSRC_SHIFT                     (19U)
#define CAN_MCR_WAKSRC(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_WAKSRC_SHIFT)) & CAN_MCR_WAKSRC_MASK)
#define CAN_MCR_LPMACK_MASK                      (0x100000U)
#define CAN_MCR_LPMACK_SHIFT                     (20U)
#define CAN_MCR_LPMACK(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_LPMACK_SHIFT)) & CAN_MCR_LPMACK_MASK)
#define CAN_MCR_WRNEN_MASK                       (0x200000U)
#define CAN_MCR_WRNEN_SHIFT                      (21U)
#define CAN_MCR_WRNEN(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_MCR_WRNEN_SHIFT)) & CAN_MCR_WRNEN_MASK)
#define CAN_MCR_SLFWAK_MASK                      (0x400000U)
#define CAN_MCR_SLFWAK_SHIFT                     (22U)
#define CAN_MCR_SLFWAK(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SLFWAK_SHIFT)) & CAN_MCR_SLFWAK_MASK)
#define CAN_MCR_SUPV_MASK                        (0x800000U)
#define CAN_MCR_SUPV_SHIFT                       (23U)
#define CAN_MCR_SUPV(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SUPV_SHIFT)) & CAN_MCR_SUPV_MASK)
#define CAN_MCR_FRZACK_MASK                      (0x1000000U)
#define CAN_MCR_FRZACK_SHIFT                     (24U)
#define CAN_MCR_FRZACK(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_FRZACK_SHIFT)) & CAN_MCR_FRZACK_MASK)
#define CAN_MCR_SOFTRST_MASK                     (0x2000000U)
#define CAN_MCR_SOFTRST_SHIFT                    (25U)
#define CAN_MCR_SOFTRST(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SOFTRST_SHIFT)) & CAN_MCR_SOFTRST_MASK)
#define CAN_MCR_WAKMSK_MASK                      (0x4000000U)
#define CAN_MCR_WAKMSK_SHIFT                     (26U)
#define CAN_MCR_WAKMSK(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_WAKMSK_SHIFT)) & CAN_MCR_WAKMSK_MASK)
#define CAN_MCR_NOTRDY_MASK                      (0x8000000U)
#define CAN_MCR_NOTRDY_SHIFT                     (27U)
#define CAN_MCR_NOTRDY(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_NOTRDY_SHIFT)) & CAN_MCR_NOTRDY_MASK)
#define CAN_MCR_HALT_MASK                        (0x10000000U)
#define CAN_MCR_HALT_SHIFT                       (28U)
#define CAN_MCR_HALT(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_HALT_SHIFT)) & CAN_MCR_HALT_MASK)
#define CAN_MCR_RFEN_MASK                        (0x20000000U)
#define CAN_MCR_RFEN_SHIFT                       (29U)
#define CAN_MCR_RFEN(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_RFEN_SHIFT)) & CAN_MCR_RFEN_MASK)
#define CAN_MCR_FRZ_MASK                         (0x40000000U)
#define CAN_MCR_FRZ_SHIFT                        (30U)
#define CAN_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_MCR_FRZ_SHIFT)) & CAN_MCR_FRZ_MASK)
#define CAN_MCR_MDIS_MASK                        (0x80000000U)
#define CAN_MCR_MDIS_SHIFT                       (31U)
#define CAN_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_MDIS_SHIFT)) & CAN_MCR_MDIS_MASK)

/*! @name CTRL1 - Control 1 register */
#define CAN_CTRL1_PROPSEG_MASK                   (0x7U)
#define CAN_CTRL1_PROPSEG_SHIFT                  (0U)
#define CAN_CTRL1_PROPSEG(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PROPSEG_SHIFT)) & CAN_CTRL1_PROPSEG_MASK)
#define CAN_CTRL1_LOM_MASK                       (0x8U)
#define CAN_CTRL1_LOM_SHIFT                      (3U)
#define CAN_CTRL1_LOM(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_LOM_SHIFT)) & CAN_CTRL1_LOM_MASK)
#define CAN_CTRL1_LBUF_MASK                      (0x10U)
#define CAN_CTRL1_LBUF_SHIFT                     (4U)
#define CAN_CTRL1_LBUF(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_LBUF_SHIFT)) & CAN_CTRL1_LBUF_MASK)
#define CAN_CTRL1_TSYN_MASK                      (0x20U)
#define CAN_CTRL1_TSYN_SHIFT                     (5U)
#define CAN_CTRL1_TSYN(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_TSYN_SHIFT)) & CAN_CTRL1_TSYN_MASK)
#define CAN_CTRL1_BOFFREC_MASK                   (0x40U)
#define CAN_CTRL1_BOFFREC_SHIFT                  (6U)
#define CAN_CTRL1_BOFFREC(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_BOFFREC_SHIFT)) & CAN_CTRL1_BOFFREC_MASK)
#define CAN_CTRL1_SMP_MASK                       (0x80U)
#define CAN_CTRL1_SMP_SHIFT                      (7U)
#define CAN_CTRL1_SMP(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_SMP_SHIFT)) & CAN_CTRL1_SMP_MASK)
#define CAN_CTRL1_RWRNMSK_MASK                   (0x400U)
#define CAN_CTRL1_RWRNMSK_SHIFT                  (10U)
#define CAN_CTRL1_RWRNMSK(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_RWRNMSK_SHIFT)) & CAN_CTRL1_RWRNMSK_MASK)
#define CAN_CTRL1_TWRNMSK_MASK                   (0x800U)
#define CAN_CTRL1_TWRNMSK_SHIFT                  (11U)
#define CAN_CTRL1_TWRNMSK(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_TWRNMSK_SHIFT)) & CAN_CTRL1_TWRNMSK_MASK)
#define CAN_CTRL1_LPB_MASK                       (0x1000U)
#define CAN_CTRL1_LPB_SHIFT                      (12U)
#define CAN_CTRL1_LPB(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_LPB_SHIFT)) & CAN_CTRL1_LPB_MASK)
#define CAN_CTRL1_CLKSRC_MASK                    (0x2000U)
#define CAN_CTRL1_CLKSRC_SHIFT                   (13U)
#define CAN_CTRL1_CLKSRC(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_CLKSRC_SHIFT)) & CAN_CTRL1_CLKSRC_MASK)
#define CAN_CTRL1_ERRMSK_MASK                    (0x4000U)
#define CAN_CTRL1_ERRMSK_SHIFT                   (14U)
#define CAN_CTRL1_ERRMSK(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_ERRMSK_SHIFT)) & CAN_CTRL1_ERRMSK_MASK)
#define CAN_CTRL1_BOFFMSK_MASK                   (0x8000U)
#define CAN_CTRL1_BOFFMSK_SHIFT                  (15U)
#define CAN_CTRL1_BOFFMSK(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_BOFFMSK_SHIFT)) & CAN_CTRL1_BOFFMSK_MASK)
#define CAN_CTRL1_PSEG2_MASK                     (0x70000U)
#define CAN_CTRL1_PSEG2_SHIFT                    (16U)
#define CAN_CTRL1_PSEG2(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PSEG2_SHIFT)) & CAN_CTRL1_PSEG2_MASK)
#define CAN_CTRL1_PSEG1_MASK                     (0x380000U)
#define CAN_CTRL1_PSEG1_SHIFT                    (19U)
#define CAN_CTRL1_PSEG1(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PSEG1_SHIFT)) & CAN_CTRL1_PSEG1_MASK)
#define CAN_CTRL1_RJW_MASK                       (0xC00000U)
#define CAN_CTRL1_RJW_SHIFT                      (22U)
#define CAN_CTRL1_RJW(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_RJW_SHIFT)) & CAN_CTRL1_RJW_MASK)
#define CAN_CTRL1_PRESDIV_MASK                   (0xFF000000U)
#define CAN_CTRL1_PRESDIV_SHIFT                  (24U)
#define CAN_CTRL1_PRESDIV(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PRESDIV_SHIFT)) & CAN_CTRL1_PRESDIV_MASK)

/*! @name TIMER - Free Running Timer */
#define CAN_TIMER_TIMER_MASK                     (0xFFFFU)
#define CAN_TIMER_TIMER_SHIFT                    (0U)
#define CAN_TIMER_TIMER(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_TIMER_TIMER_SHIFT)) & CAN_TIMER_TIMER_MASK)

/*! @name RXMGMASK - Rx Mailboxes Global Mask Register */
#define CAN_RXMGMASK_MG_MASK                     (0xFFFFFFFFU)
#define CAN_RXMGMASK_MG_SHIFT                    (0U)
#define CAN_RXMGMASK_MG(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_RXMGMASK_MG_SHIFT)) & CAN_RXMGMASK_MG_MASK)

/*! @name RX14MASK - Rx 14 Mask register */
#define CAN_RX14MASK_RX14M_MASK                  (0xFFFFFFFFU)
#define CAN_RX14MASK_RX14M_SHIFT                 (0U)
#define CAN_RX14MASK_RX14M(x)                    (((uint32_t)(((uint32_t)(x)) << CAN_RX14MASK_RX14M_SHIFT)) & CAN_RX14MASK_RX14M_MASK)

/*! @name RX15MASK - Rx 15 Mask register */
#define CAN_RX15MASK_RX15M_MASK                  (0xFFFFFFFFU)
#define CAN_RX15MASK_RX15M_SHIFT                 (0U)
#define CAN_RX15MASK_RX15M(x)                    (((uint32_t)(((uint32_t)(x)) << CAN_RX15MASK_RX15M_SHIFT)) & CAN_RX15MASK_RX15M_MASK)

/*! @name ECR - Error Counter */
#define CAN_ECR_TXERRCNT_MASK                    (0xFFU)
#define CAN_ECR_TXERRCNT_SHIFT                   (0U)
#define CAN_ECR_TXERRCNT(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ECR_TXERRCNT_SHIFT)) & CAN_ECR_TXERRCNT_MASK)
#define CAN_ECR_RXERRCNT_MASK                    (0xFF00U)
#define CAN_ECR_RXERRCNT_SHIFT                   (8U)
#define CAN_ECR_RXERRCNT(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ECR_RXERRCNT_SHIFT)) & CAN_ECR_RXERRCNT_MASK)

/*! @name ESR1 - Error and Status 1 register */
#define CAN_ESR1_WAKINT_MASK                     (0x1U)
#define CAN_ESR1_WAKINT_SHIFT                    (0U)
#define CAN_ESR1_WAKINT(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_WAKINT_SHIFT)) & CAN_ESR1_WAKINT_MASK)
#define CAN_ESR1_ERRINT_MASK                     (0x2U)
#define CAN_ESR1_ERRINT_SHIFT                    (1U)
#define CAN_ESR1_ERRINT(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_ERRINT_SHIFT)) & CAN_ESR1_ERRINT_MASK)
#define CAN_ESR1_BOFFINT_MASK                    (0x4U)
#define CAN_ESR1_BOFFINT_SHIFT                   (2U)
#define CAN_ESR1_BOFFINT(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BOFFINT_SHIFT)) & CAN_ESR1_BOFFINT_MASK)
#define CAN_ESR1_RX_MASK                         (0x8U)
#define CAN_ESR1_RX_SHIFT                        (3U)
#define CAN_ESR1_RX(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_RX_SHIFT)) & CAN_ESR1_RX_MASK)
#define CAN_ESR1_FLTCONF_MASK                    (0x30U)
#define CAN_ESR1_FLTCONF_SHIFT                   (4U)
#define CAN_ESR1_FLTCONF(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_FLTCONF_SHIFT)) & CAN_ESR1_FLTCONF_MASK)
#define CAN_ESR1_TX_MASK                         (0x40U)
#define CAN_ESR1_TX_SHIFT                        (6U)
#define CAN_ESR1_TX(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_TX_SHIFT)) & CAN_ESR1_TX_MASK)
#define CAN_ESR1_IDLE_MASK                       (0x80U)
#define CAN_ESR1_IDLE_SHIFT                      (7U)
#define CAN_ESR1_IDLE(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_IDLE_SHIFT)) & CAN_ESR1_IDLE_MASK)
#define CAN_ESR1_RXWRN_MASK                      (0x100U)
#define CAN_ESR1_RXWRN_SHIFT                     (8U)
#define CAN_ESR1_RXWRN(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_RXWRN_SHIFT)) & CAN_ESR1_RXWRN_MASK)
#define CAN_ESR1_TXWRN_MASK                      (0x200U)
#define CAN_ESR1_TXWRN_SHIFT                     (9U)
#define CAN_ESR1_TXWRN(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_TXWRN_SHIFT)) & CAN_ESR1_TXWRN_MASK)
#define CAN_ESR1_STFERR_MASK                     (0x400U)
#define CAN_ESR1_STFERR_SHIFT                    (10U)
#define CAN_ESR1_STFERR(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_STFERR_SHIFT)) & CAN_ESR1_STFERR_MASK)
#define CAN_ESR1_FRMERR_MASK                     (0x800U)
#define CAN_ESR1_FRMERR_SHIFT                    (11U)
#define CAN_ESR1_FRMERR(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_FRMERR_SHIFT)) & CAN_ESR1_FRMERR_MASK)
#define CAN_ESR1_CRCERR_MASK                     (0x1000U)
#define CAN_ESR1_CRCERR_SHIFT                    (12U)
#define CAN_ESR1_CRCERR(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_CRCERR_SHIFT)) & CAN_ESR1_CRCERR_MASK)
#define CAN_ESR1_ACKERR_MASK                     (0x2000U)
#define CAN_ESR1_ACKERR_SHIFT                    (13U)
#define CAN_ESR1_ACKERR(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_ACKERR_SHIFT)) & CAN_ESR1_ACKERR_MASK)
#define CAN_ESR1_BIT0ERR_MASK                    (0x4000U)
#define CAN_ESR1_BIT0ERR_SHIFT                   (14U)
#define CAN_ESR1_BIT0ERR(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BIT0ERR_SHIFT)) & CAN_ESR1_BIT0ERR_MASK)
#define CAN_ESR1_BIT1ERR_MASK                    (0x8000U)
#define CAN_ESR1_BIT1ERR_SHIFT                   (15U)
#define CAN_ESR1_BIT1ERR(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BIT1ERR_SHIFT)) & CAN_ESR1_BIT1ERR_MASK)
#define CAN_ESR1_RWRNINT_MASK                    (0x10000U)
#define CAN_ESR1_RWRNINT_SHIFT                   (16U)
#define CAN_ESR1_RWRNINT(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_RWRNINT_SHIFT)) & CAN_ESR1_RWRNINT_MASK)
#define CAN_ESR1_TWRNINT_MASK                    (0x20000U)
#define CAN_ESR1_TWRNINT_SHIFT                   (17U)
#define CAN_ESR1_TWRNINT(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_TWRNINT_SHIFT)) & CAN_ESR1_TWRNINT_MASK)
#define CAN_ESR1_SYNCH_MASK                      (0x40000U)
#define CAN_ESR1_SYNCH_SHIFT                     (18U)
#define CAN_ESR1_SYNCH(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_SYNCH_SHIFT)) & CAN_ESR1_SYNCH_MASK)
#define CAN_ESR1_BOFFDONEINT_MASK                (0x80000U)
#define CAN_ESR1_BOFFDONEINT_SHIFT               (19U)
#define CAN_ESR1_BOFFDONEINT(x)                  (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BOFFDONEINT_SHIFT)) & CAN_ESR1_BOFFDONEINT_MASK)
#define CAN_ESR1_ERROVR_MASK                     (0x200000U)
#define CAN_ESR1_ERROVR_SHIFT                    (21U)
#define CAN_ESR1_ERROVR(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_ERROVR_SHIFT)) & CAN_ESR1_ERROVR_MASK)

/*! @name IMASK1 - Interrupt Masks 1 register */
#define CAN_IMASK1_BUF31TO0M_MASK                (0xFFFFFFFFU)
#define CAN_IMASK1_BUF31TO0M_SHIFT               (0U)
#define CAN_IMASK1_BUF31TO0M(x)                  (((uint32_t)(((uint32_t)(x)) << CAN_IMASK1_BUF31TO0M_SHIFT)) & CAN_IMASK1_BUF31TO0M_MASK)

/*! @name IFLAG1 - Interrupt Flags 1 register */
#define CAN_IFLAG1_BUF0I_MASK                    (0x1U)
#define CAN_IFLAG1_BUF0I_SHIFT                   (0U)
#define CAN_IFLAG1_BUF0I(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF0I_SHIFT)) & CAN_IFLAG1_BUF0I_MASK)
#define CAN_IFLAG1_BUF4TO1I_MASK                 (0x1EU)
#define CAN_IFLAG1_BUF4TO1I_SHIFT                (1U)
#define CAN_IFLAG1_BUF4TO1I(x)                   (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF4TO1I_SHIFT)) & CAN_IFLAG1_BUF4TO1I_MASK)
#define CAN_IFLAG1_BUF5I_MASK                    (0x20U)
#define CAN_IFLAG1_BUF5I_SHIFT                   (5U)
#define CAN_IFLAG1_BUF5I(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF5I_SHIFT)) & CAN_IFLAG1_BUF5I_MASK)
#define CAN_IFLAG1_BUF6I_MASK                    (0x40U)
#define CAN_IFLAG1_BUF6I_SHIFT                   (6U)
#define CAN_IFLAG1_BUF6I(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF6I_SHIFT)) & CAN_IFLAG1_BUF6I_MASK)
#define CAN_IFLAG1_BUF7I_MASK                    (0x80U)
#define CAN_IFLAG1_BUF7I_SHIFT                   (7U)
#define CAN_IFLAG1_BUF7I(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF7I_SHIFT)) & CAN_IFLAG1_BUF7I_MASK)
#define CAN_IFLAG1_BUF31TO8I_MASK                (0xFFFFFF00U)
#define CAN_IFLAG1_BUF31TO8I_SHIFT               (8U)
#define CAN_IFLAG1_BUF31TO8I(x)                  (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF31TO8I_SHIFT)) & CAN_IFLAG1_BUF31TO8I_MASK)

/*! @name CTRL2 - Control 2 register */
#define CAN_CTRL2_EACEN_MASK                     (0x10000U)
#define CAN_CTRL2_EACEN_SHIFT                    (16U)
#define CAN_CTRL2_EACEN(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_EACEN_SHIFT)) & CAN_CTRL2_EACEN_MASK)
#define CAN_CTRL2_RRS_MASK                       (0x20000U)
#define CAN_CTRL2_RRS_SHIFT                      (17U)
#define CAN_CTRL2_RRS(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_RRS_SHIFT)) & CAN_CTRL2_RRS_MASK)
#define CAN_CTRL2_MRP_MASK                       (0x40000U)
#define CAN_CTRL2_MRP_SHIFT                      (18U)
#define CAN_CTRL2_MRP(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_MRP_SHIFT)) & CAN_CTRL2_MRP_MASK)
#define CAN_CTRL2_TASD_MASK                      (0xF80000U)
#define CAN_CTRL2_TASD_SHIFT                     (19U)
#define CAN_CTRL2_TASD(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_TASD_SHIFT)) & CAN_CTRL2_TASD_MASK)
#define CAN_CTRL2_RFFN_MASK                      (0xF000000U)
#define CAN_CTRL2_RFFN_SHIFT                     (24U)
#define CAN_CTRL2_RFFN(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_RFFN_SHIFT)) & CAN_CTRL2_RFFN_MASK)
#define CAN_CTRL2_BOFFDONEMSK_MASK               (0x40000000U)
#define CAN_CTRL2_BOFFDONEMSK_SHIFT              (30U)
#define CAN_CTRL2_BOFFDONEMSK(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_BOFFDONEMSK_SHIFT)) & CAN_CTRL2_BOFFDONEMSK_MASK)

/*! @name ESR2 - Error and Status 2 register */
#define CAN_ESR2_IMB_MASK                        (0x2000U)
#define CAN_ESR2_IMB_SHIFT                       (13U)
#define CAN_ESR2_IMB(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_ESR2_IMB_SHIFT)) & CAN_ESR2_IMB_MASK)
#define CAN_ESR2_VPS_MASK                        (0x4000U)
#define CAN_ESR2_VPS_SHIFT                       (14U)
#define CAN_ESR2_VPS(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_ESR2_VPS_SHIFT)) & CAN_ESR2_VPS_MASK)
#define CAN_ESR2_LPTM_MASK                       (0x7F0000U)
#define CAN_ESR2_LPTM_SHIFT                      (16U)
#define CAN_ESR2_LPTM(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_ESR2_LPTM_SHIFT)) & CAN_ESR2_LPTM_MASK)

/*! @name CRCR - CRC Register */
#define CAN_CRCR_TXCRC_MASK                      (0x7FFFU)
#define CAN_CRCR_TXCRC_SHIFT                     (0U)
#define CAN_CRCR_TXCRC(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CRCR_TXCRC_SHIFT)) & CAN_CRCR_TXCRC_MASK)
#define CAN_CRCR_MBCRC_MASK                      (0x7F0000U)
#define CAN_CRCR_MBCRC_SHIFT                     (16U)
#define CAN_CRCR_MBCRC(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CRCR_MBCRC_SHIFT)) & CAN_CRCR_MBCRC_MASK)

/*! @name RXFGMASK - Rx FIFO Global Mask register */
#define CAN_RXFGMASK_FGM_MASK                    (0xFFFFFFFFU)
#define CAN_RXFGMASK_FGM_SHIFT                   (0U)
#define CAN_RXFGMASK_FGM(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_RXFGMASK_FGM_SHIFT)) & CAN_RXFGMASK_FGM_MASK)

/*! @name RXFIR - Rx FIFO Information Register */
#define CAN_RXFIR_IDHIT_MASK                     (0x1FFU)
#define CAN_RXFIR_IDHIT_SHIFT                    (0U)
#define CAN_RXFIR_IDHIT(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_RXFIR_IDHIT_SHIFT)) & CAN_RXFIR_IDHIT_MASK)

/*! @name CBT - CAN Bit Timing Register */
#define CAN_CBT_EPSEG2_MASK                      (0x1FU)
#define CAN_CBT_EPSEG2_SHIFT                     (0U)
#define CAN_CBT_EPSEG2(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CBT_EPSEG2_SHIFT)) & CAN_CBT_EPSEG2_MASK)
#define CAN_CBT_EPSEG1_MASK                      (0x3E0U)
#define CAN_CBT_EPSEG1_SHIFT                     (5U)
#define CAN_CBT_EPSEG1(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CBT_EPSEG1_SHIFT)) & CAN_CBT_EPSEG1_MASK)
#define CAN_CBT_EPROPSEG_MASK                    (0xFC00U)
#define CAN_CBT_EPROPSEG_SHIFT                   (10U)
#define CAN_CBT_EPROPSEG(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_CBT_EPROPSEG_SHIFT)) & CAN_CBT_EPROPSEG_MASK)
#define CAN_CBT_ERJW_MASK                        (0xF0000U)
#define CAN_CBT_ERJW_SHIFT                       (16U)
#define CAN_CBT_ERJW(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_CBT_ERJW_SHIFT)) & CAN_CBT_ERJW_MASK)
#define CAN_CBT_EPRESDIV_MASK                    (0x7FE00000U)
#define CAN_CBT_EPRESDIV_SHIFT                   (21U)
#define CAN_CBT_EPRESDIV(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_CBT_EPRESDIV_SHIFT)) & CAN_CBT_EPRESDIV_MASK)
#define CAN_CBT_BTF_MASK                         (0x80000000U)
#define CAN_CBT_BTF_SHIFT                        (31U)
#define CAN_CBT_BTF(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_CBT_BTF_SHIFT)) & CAN_CBT_BTF_MASK)

/*! @name CS - Message Buffer 0 CS Register..Message Buffer 15 CS Register */
#define CAN_CS_TIME_STAMP_MASK                   (0xFFFFU)
#define CAN_CS_TIME_STAMP_SHIFT                  (0U)
#define CAN_CS_TIME_STAMP(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CS_TIME_STAMP_SHIFT)) & CAN_CS_TIME_STAMP_MASK)
#define CAN_CS_DLC_MASK                          (0xF0000U)
#define CAN_CS_DLC_SHIFT                         (16U)
#define CAN_CS_DLC(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_CS_DLC_SHIFT)) & CAN_CS_DLC_MASK)
#define CAN_CS_RTR_MASK                          (0x100000U)
#define CAN_CS_RTR_SHIFT                         (20U)
#define CAN_CS_RTR(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_CS_RTR_SHIFT)) & CAN_CS_RTR_MASK)
#define CAN_CS_IDE_MASK                          (0x200000U)
#define CAN_CS_IDE_SHIFT                         (21U)
#define CAN_CS_IDE(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_CS_IDE_SHIFT)) & CAN_CS_IDE_MASK)
#define CAN_CS_SRR_MASK                          (0x400000U)
#define CAN_CS_SRR_SHIFT                         (22U)
#define CAN_CS_SRR(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_CS_SRR_SHIFT)) & CAN_CS_SRR_MASK)
#define CAN_CS_CODE_MASK                         (0xF000000U)
#define CAN_CS_CODE_SHIFT                        (24U)
#define CAN_CS_CODE(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_CS_CODE_SHIFT)) & CAN_CS_CODE_MASK)

/* The count of CAN_CS */
#define CAN_CS_COUNT                             (16U)

/*! @name ID - Message Buffer 0 ID Register..Message Buffer 15 ID Register */
#define CAN_ID_EXT_MASK                          (0x3FFFFU)
#define CAN_ID_EXT_SHIFT                         (0U)
#define CAN_ID_EXT(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_ID_EXT_SHIFT)) & CAN_ID_EXT_MASK)
#define CAN_ID_STD_MASK                          (0x1FFC0000U)
#define CAN_ID_STD_SHIFT                         (18U)
#define CAN_ID_STD(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_ID_STD_SHIFT)) & CAN_ID_STD_MASK)
#define CAN_ID_PRIO_MASK                         (0xE0000000U)
#define CAN_ID_PRIO_SHIFT                        (29U)
#define CAN_ID_PRIO(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_ID_PRIO_SHIFT)) & CAN_ID_PRIO_MASK)

/* The count of CAN_ID */
#define CAN_ID_COUNT                             (16U)

/*! @name WORD0 - Message Buffer 0 WORD0 Register..Message Buffer 15 WORD0 Register */
#define CAN_WORD0_DATA_BYTE_3_MASK               (0xFFU)
#define CAN_WORD0_DATA_BYTE_3_SHIFT              (0U)
#define CAN_WORD0_DATA_BYTE_3(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_3_SHIFT)) & CAN_WORD0_DATA_BYTE_3_MASK)
#define CAN_WORD0_DATA_BYTE_2_MASK               (0xFF00U)
#define CAN_WORD0_DATA_BYTE_2_SHIFT              (8U)
#define CAN_WORD0_DATA_BYTE_2(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_2_SHIFT)) & CAN_WORD0_DATA_BYTE_2_MASK)
#define CAN_WORD0_DATA_BYTE_1_MASK               (0xFF0000U)
#define CAN_WORD0_DATA_BYTE_1_SHIFT              (16U)
#define CAN_WORD0_DATA_BYTE_1(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_1_SHIFT)) & CAN_WORD0_DATA_BYTE_1_MASK)
#define CAN_WORD0_DATA_BYTE_0_MASK               (0xFF000000U)
#define CAN_WORD0_DATA_BYTE_0_SHIFT              (24U)
#define CAN_WORD0_DATA_BYTE_0(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_0_SHIFT)) & CAN_WORD0_DATA_BYTE_0_MASK)

/* The count of CAN_WORD0 */
#define CAN_WORD0_COUNT                          (16U)

/*! @name WORD1 - Message Buffer 0 WORD1 Register..Message Buffer 15 WORD1 Register */
#define CAN_WORD1_DATA_BYTE_7_MASK               (0xFFU)
#define CAN_WORD1_DATA_BYTE_7_SHIFT              (0U)
#define CAN_WORD1_DATA_BYTE_7(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_7_SHIFT)) & CAN_WORD1_DATA_BYTE_7_MASK)
#define CAN_WORD1_DATA_BYTE_6_MASK               (0xFF00U)
#define CAN_WORD1_DATA_BYTE_6_SHIFT              (8U)
#define CAN_WORD1_DATA_BYTE_6(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_6_SHIFT)) & CAN_WORD1_DATA_BYTE_6_MASK)
#define CAN_WORD1_DATA_BYTE_5_MASK               (0xFF0000U)
#define CAN_WORD1_DATA_BYTE_5_SHIFT              (16U)
#define CAN_WORD1_DATA_BYTE_5(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_5_SHIFT)) & CAN_WORD1_DATA_BYTE_5_MASK)
#define CAN_WORD1_DATA_BYTE_4_MASK               (0xFF000000U)
#define CAN_WORD1_DATA_BYTE_4_SHIFT              (24U)
#define CAN_WORD1_DATA_BYTE_4(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_4_SHIFT)) & CAN_WORD1_DATA_BYTE_4_MASK)

/* The count of CAN_WORD1 */
#define CAN_WORD1_COUNT                          (16U)

/*! @name RXIMR - Rx Individual Mask Registers */
#define CAN_RXIMR_MI_MASK                        (0xFFFFFFFFU)
#define CAN_RXIMR_MI_SHIFT                       (0U)
#define CAN_RXIMR_MI(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_RXIMR_MI_SHIFT)) & CAN_RXIMR_MI_MASK)

/* The count of CAN_RXIMR */
#define CAN_RXIMR_COUNT                          (16U)


/*!
 * @}
 */ /* end of group CAN_Register_Masks */


/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base address */
#define CAN0_BASE                                (0x40024000u)
/** Peripheral CAN0 base pointer */
#define CAN0                                     ((CAN_Type *)CAN0_BASE)
/** Peripheral CAN1 base address */
#define CAN1_BASE                                (0x40025000u)
/** Peripheral CAN1 base pointer */
#define CAN1                                     ((CAN_Type *)CAN1_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { CAN0_BASE, CAN1_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { CAN0, CAN1 }
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { CAN0_Rx_Warning_IRQn, CAN1_Rx_Warning_IRQn }
#define CAN_Tx_Warning_IRQS                      { CAN0_Tx_Warning_IRQn, CAN1_Tx_Warning_IRQn }
#define CAN_Wake_Up_IRQS                         { CAN0_Wake_Up_IRQn, CAN1_Wake_Up_IRQn }
#define CAN_Error_IRQS                           { CAN0_Error_IRQn, CAN1_Error_IRQn }
#define CAN_Bus_Off_IRQS                         { CAN0_Bus_Off_IRQn, CAN1_Bus_Off_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { CAN0_ORed_Message_buffer_IRQn, CAN1_ORed_Message_buffer_IRQn }
#define CAN_IMASK1_BUFLM_MASK                    CAN_IMASK1_BUF31TO0M_MASK
#define CAN_IMASK1_BUFLM_SHIFT                   CAN_IMASK1_BUF31TO0M_SHIFT
#define CAN_IMASK1_BUFLM_WIDTH                   CAN_IMASK1_BUF31TO0M_WIDTH
#define CAN_IMASK1_BUFLM(x)                      CAN_IMASK1_BUF31TO0M(x)


/*!
 * @}
 */ /* end of group CAN_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Peripheral_Access_Layer CMP Peripheral Access Layer
 * @{
 */

/** CMP - Register Layout Typedef */
typedef struct {
  __IO uint8_t CR0;                                /**< CMP Control Register 0, offset: 0x0 */
  __IO uint8_t CR1;                                /**< CMP Control Register 1, offset: 0x1 */
  __IO uint8_t FPR;                                /**< CMP Filter Period Register, offset: 0x2 */
  __IO uint8_t SCR;                                /**< CMP Status and Control Register, offset: 0x3 */
  __IO uint8_t DACCR;                              /**< DAC Control Register, offset: 0x4 */
  __IO uint8_t MUXCR;                              /**< MUX Control Register, offset: 0x5 */
} CMP_Type;

/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMP_Register_Masks CMP Register Masks
 * @{
 */

/*! @name CR0 - CMP Control Register 0 */
#define CMP_CR0_HYSTCTR_MASK                     (0x3U)
#define CMP_CR0_HYSTCTR_SHIFT                    (0U)
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x)) << CMP_CR0_HYSTCTR_SHIFT)) & CMP_CR0_HYSTCTR_MASK)
#define CMP_CR0_FILTER_CNT_MASK                  (0x70U)
#define CMP_CR0_FILTER_CNT_SHIFT                 (4U)
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x)) << CMP_CR0_FILTER_CNT_SHIFT)) & CMP_CR0_FILTER_CNT_MASK)

/*! @name CR1 - CMP Control Register 1 */
#define CMP_CR1_EN_MASK                          (0x1U)
#define CMP_CR1_EN_SHIFT                         (0U)
#define CMP_CR1_EN(x)                            (((uint8_t)(((uint8_t)(x)) << CMP_CR1_EN_SHIFT)) & CMP_CR1_EN_MASK)
#define CMP_CR1_OPE_MASK                         (0x2U)
#define CMP_CR1_OPE_SHIFT                        (1U)
#define CMP_CR1_OPE(x)                           (((uint8_t)(((uint8_t)(x)) << CMP_CR1_OPE_SHIFT)) & CMP_CR1_OPE_MASK)
#define CMP_CR1_COS_MASK                         (0x4U)
#define CMP_CR1_COS_SHIFT                        (2U)
#define CMP_CR1_COS(x)                           (((uint8_t)(((uint8_t)(x)) << CMP_CR1_COS_SHIFT)) & CMP_CR1_COS_MASK)
#define CMP_CR1_INV_MASK                         (0x8U)
#define CMP_CR1_INV_SHIFT                        (3U)
#define CMP_CR1_INV(x)                           (((uint8_t)(((uint8_t)(x)) << CMP_CR1_INV_SHIFT)) & CMP_CR1_INV_MASK)
#define CMP_CR1_PMODE_MASK                       (0x10U)
#define CMP_CR1_PMODE_SHIFT                      (4U)
#define CMP_CR1_PMODE(x)                         (((uint8_t)(((uint8_t)(x)) << CMP_CR1_PMODE_SHIFT)) & CMP_CR1_PMODE_MASK)
#define CMP_CR1_TRIGM_MASK                       (0x20U)
#define CMP_CR1_TRIGM_SHIFT                      (5U)
#define CMP_CR1_TRIGM(x)                         (((uint8_t)(((uint8_t)(x)) << CMP_CR1_TRIGM_SHIFT)) & CMP_CR1_TRIGM_MASK)
#define CMP_CR1_WE_MASK                          (0x40U)
#define CMP_CR1_WE_SHIFT                         (6U)
#define CMP_CR1_WE(x)                            (((uint8_t)(((uint8_t)(x)) << CMP_CR1_WE_SHIFT)) & CMP_CR1_WE_MASK)
#define CMP_CR1_SE_MASK                          (0x80U)
#define CMP_CR1_SE_SHIFT                         (7U)
#define CMP_CR1_SE(x)                            (((uint8_t)(((uint8_t)(x)) << CMP_CR1_SE_SHIFT)) & CMP_CR1_SE_MASK)

/*! @name FPR - CMP Filter Period Register */
#define CMP_FPR_FILT_PER_MASK                    (0xFFU)
#define CMP_FPR_FILT_PER_SHIFT                   (0U)
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x)) << CMP_FPR_FILT_PER_SHIFT)) & CMP_FPR_FILT_PER_MASK)

/*! @name SCR - CMP Status and Control Register */
#define CMP_SCR_COUT_MASK                        (0x1U)
#define CMP_SCR_COUT_SHIFT                       (0U)
#define CMP_SCR_COUT(x)                          (((uint8_t)(((uint8_t)(x)) << CMP_SCR_COUT_SHIFT)) & CMP_SCR_COUT_MASK)
#define CMP_SCR_CFF_MASK                         (0x2U)
#define CMP_SCR_CFF_SHIFT                        (1U)
#define CMP_SCR_CFF(x)                           (((uint8_t)(((uint8_t)(x)) << CMP_SCR_CFF_SHIFT)) & CMP_SCR_CFF_MASK)
#define CMP_SCR_CFR_MASK                         (0x4U)
#define CMP_SCR_CFR_SHIFT                        (2U)
#define CMP_SCR_CFR(x)                           (((uint8_t)(((uint8_t)(x)) << CMP_SCR_CFR_SHIFT)) & CMP_SCR_CFR_MASK)
#define CMP_SCR_IEF_MASK                         (0x8U)
#define CMP_SCR_IEF_SHIFT                        (3U)
#define CMP_SCR_IEF(x)                           (((uint8_t)(((uint8_t)(x)) << CMP_SCR_IEF_SHIFT)) & CMP_SCR_IEF_MASK)
#define CMP_SCR_IER_MASK                         (0x10U)
#define CMP_SCR_IER_SHIFT                        (4U)
#define CMP_SCR_IER(x)                           (((uint8_t)(((uint8_t)(x)) << CMP_SCR_IER_SHIFT)) & CMP_SCR_IER_MASK)
#define CMP_SCR_DMAEN_MASK                       (0x40U)
#define CMP_SCR_DMAEN_SHIFT                      (6U)
#define CMP_SCR_DMAEN(x)                         (((uint8_t)(((uint8_t)(x)) << CMP_SCR_DMAEN_SHIFT)) & CMP_SCR_DMAEN_MASK)

/*! @name DACCR - DAC Control Register */
#define CMP_DACCR_VOSEL_MASK                     (0x3FU)
#define CMP_DACCR_VOSEL_SHIFT                    (0U)
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x)) << CMP_DACCR_VOSEL_SHIFT)) & CMP_DACCR_VOSEL_MASK)
#define CMP_DACCR_VRSEL_MASK                     (0x40U)
#define CMP_DACCR_VRSEL_SHIFT                    (6U)
#define CMP_DACCR_VRSEL(x)                       (((uint8_t)(((uint8_t)(x)) << CMP_DACCR_VRSEL_SHIFT)) & CMP_DACCR_VRSEL_MASK)
#define CMP_DACCR_DACEN_MASK                     (0x80U)
#define CMP_DACCR_DACEN_SHIFT                    (7U)
#define CMP_DACCR_DACEN(x)                       (((uint8_t)(((uint8_t)(x)) << CMP_DACCR_DACEN_SHIFT)) & CMP_DACCR_DACEN_MASK)

/*! @name MUXCR - MUX Control Register */
#define CMP_MUXCR_MSEL_MASK                      (0x7U)
#define CMP_MUXCR_MSEL_SHIFT                     (0U)
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x)) << CMP_MUXCR_MSEL_SHIFT)) & CMP_MUXCR_MSEL_MASK)
#define CMP_MUXCR_PSEL_MASK                      (0x38U)
#define CMP_MUXCR_PSEL_SHIFT                     (3U)
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x)) << CMP_MUXCR_PSEL_SHIFT)) & CMP_MUXCR_PSEL_MASK)


/*!
 * @}
 */ /* end of group CMP_Register_Masks */


/* CMP - Peripheral instance base addresses */
/** Peripheral CMP0 base address */
#define CMP0_BASE                                (0x40073000u)
/** Peripheral CMP0 base pointer */
#define CMP0                                     ((CMP_Type *)CMP0_BASE)
/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           { CMP0_BASE }
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { CMP0 }
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { CMP0_IRQn }

/*!
 * @}
 */ /* end of group CMP_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Peripheral_Access_Layer CRC Peripheral Access Layer
 * @{
 */

/** CRC - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __IO uint16_t DATAL;                             /**< CRC_DATAL register., offset: 0x0 */
      __IO uint16_t DATAH;                             /**< CRC_DATAH register., offset: 0x2 */
    } ACCESS16BIT;
    __IO uint32_t DATA;                              /**< CRC Data register, offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __IO uint8_t DATALL;                             /**< CRC_DATALL register., offset: 0x0 */
      __IO uint8_t DATALU;                             /**< CRC_DATALU register., offset: 0x1 */
      __IO uint8_t DATAHL;                             /**< CRC_DATAHL register., offset: 0x2 */
      __IO uint8_t DATAHU;                             /**< CRC_DATAHU register., offset: 0x3 */
    } ACCESS8BIT;
  };
  union {                                          /* offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      __IO uint16_t GPOLYL;                            /**< CRC_GPOLYL register., offset: 0x4 */
      __IO uint16_t GPOLYH;                            /**< CRC_GPOLYH register., offset: 0x6 */
    } GPOLY_ACCESS16BIT;
    __IO uint32_t GPOLY;                             /**< CRC Polynomial register, offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      __IO uint8_t GPOLYLL;                            /**< CRC_GPOLYLL register., offset: 0x4 */
      __IO uint8_t GPOLYLU;                            /**< CRC_GPOLYLU register., offset: 0x5 */
      __IO uint8_t GPOLYHL;                            /**< CRC_GPOLYHL register., offset: 0x6 */
      __IO uint8_t GPOLYHU;                            /**< CRC_GPOLYHU register., offset: 0x7 */
    } GPOLY_ACCESS8BIT;
  };
  union {                                          /* offset: 0x8 */
    __IO uint32_t CTRL;                              /**< CRC Control register, offset: 0x8 */
    struct {                                         /* offset: 0x8 */
           uint8_t RESERVED_0[3];
      __IO uint8_t CTRLHU;                             /**< CRC_CTRLHU register., offset: 0xB */
    } CTRL_ACCESS8BIT;
  };
} CRC_Type;

/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/*! @name DATAL - CRC_DATAL register. */
#define CRC_DATAL_DATAL_MASK                     (0xFFFFU)
#define CRC_DATAL_DATAL_SHIFT                    (0U)
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x)) << CRC_DATAL_DATAL_SHIFT)) & CRC_DATAL_DATAL_MASK)

/*! @name DATAH - CRC_DATAH register. */
#define CRC_DATAH_DATAH_MASK                     (0xFFFFU)
#define CRC_DATAH_DATAH_SHIFT                    (0U)
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x)) << CRC_DATAH_DATAH_SHIFT)) & CRC_DATAH_DATAH_MASK)

/*! @name DATA - CRC Data register */
#define CRC_DATA_LL_MASK                         (0xFFU)
#define CRC_DATA_LL_SHIFT                        (0U)
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_DATA_LL_SHIFT)) & CRC_DATA_LL_MASK)
#define CRC_DATA_LU_MASK                         (0xFF00U)
#define CRC_DATA_LU_SHIFT                        (8U)
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_DATA_LU_SHIFT)) & CRC_DATA_LU_MASK)
#define CRC_DATA_HL_MASK                         (0xFF0000U)
#define CRC_DATA_HL_SHIFT                        (16U)
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_DATA_HL_SHIFT)) & CRC_DATA_HL_MASK)
#define CRC_DATA_HU_MASK                         (0xFF000000U)
#define CRC_DATA_HU_SHIFT                        (24U)
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x)) << CRC_DATA_HU_SHIFT)) & CRC_DATA_HU_MASK)

/*! @name DATALL - CRC_DATALL register. */
#define CRC_DATALL_DATALL_MASK                   (0xFFU)
#define CRC_DATALL_DATALL_SHIFT                  (0U)
#define CRC_DATALL_DATALL(x)                     (((uint8_t)(((uint8_t)(x)) << CRC_DATALL_DATALL_SHIFT)) & CRC_DATALL_DATALL_MASK)

/*! @name DATALU - CRC_DATALU register. */
#define CRC_DATALU_DATALU_MASK                   (0xFFU)
#define CRC_DATALU_DATALU_SHIFT                  (0U)
#define CRC_DATALU_DATALU(x)                     (((uint8_t)(((uint8_t)(x)) << CRC_DATALU_DATALU_SHIFT)) & CRC_DATALU_DATALU_MASK)

/*! @name DATAHL - CRC_DATAHL register. */
#define CRC_DATAHL_DATAHL_MASK                   (0xFFU)
#define CRC_DATAHL_DATAHL_SHIFT                  (0U)
#define CRC_DATAHL_DATAHL(x)                     (((uint8_t)(((uint8_t)(x)) << CRC_DATAHL_DATAHL_SHIFT)) & CRC_DATAHL_DATAHL_MASK)

/*! @name DATAHU - CRC_DATAHU register. */
#define CRC_DATAHU_DATAHU_MASK                   (0xFFU)
#define CRC_DATAHU_DATAHU_SHIFT                  (0U)
#define CRC_DATAHU_DATAHU(x)                     (((uint8_t)(((uint8_t)(x)) << CRC_DATAHU_DATAHU_SHIFT)) & CRC_DATAHU_DATAHU_MASK)

/*! @name GPOLYL - CRC_GPOLYL register. */
#define CRC_GPOLYL_GPOLYL_MASK                   (0xFFFFU)
#define CRC_GPOLYL_GPOLYL_SHIFT                  (0U)
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x)) << CRC_GPOLYL_GPOLYL_SHIFT)) & CRC_GPOLYL_GPOLYL_MASK)

/*! @name GPOLYH - CRC_GPOLYH register. */
#define CRC_GPOLYH_GPOLYH_MASK                   (0xFFFFU)
#define CRC_GPOLYH_GPOLYH_SHIFT                  (0U)
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x)) << CRC_GPOLYH_GPOLYH_SHIFT)) & CRC_GPOLYH_GPOLYH_MASK)

/*! @name GPOLY - CRC Polynomial register */
#define CRC_GPOLY_LOW_MASK                       (0xFFFFU)
#define CRC_GPOLY_LOW_SHIFT                      (0U)
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_GPOLY_LOW_SHIFT)) & CRC_GPOLY_LOW_MASK)
#define CRC_GPOLY_HIGH_MASK                      (0xFFFF0000U)
#define CRC_GPOLY_HIGH_SHIFT                     (16U)
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x)) << CRC_GPOLY_HIGH_SHIFT)) & CRC_GPOLY_HIGH_MASK)

/*! @name GPOLYLL - CRC_GPOLYLL register. */
#define CRC_GPOLYLL_GPOLYLL_MASK                 (0xFFU)
#define CRC_GPOLYLL_GPOLYLL_SHIFT                (0U)
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x)) << CRC_GPOLYLL_GPOLYLL_SHIFT)) & CRC_GPOLYLL_GPOLYLL_MASK)

/*! @name GPOLYLU - CRC_GPOLYLU register. */
#define CRC_GPOLYLU_GPOLYLU_MASK                 (0xFFU)
#define CRC_GPOLYLU_GPOLYLU_SHIFT                (0U)
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x)) << CRC_GPOLYLU_GPOLYLU_SHIFT)) & CRC_GPOLYLU_GPOLYLU_MASK)

/*! @name GPOLYHL - CRC_GPOLYHL register. */
#define CRC_GPOLYHL_GPOLYHL_MASK                 (0xFFU)
#define CRC_GPOLYHL_GPOLYHL_SHIFT                (0U)
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x)) << CRC_GPOLYHL_GPOLYHL_SHIFT)) & CRC_GPOLYHL_GPOLYHL_MASK)

/*! @name GPOLYHU - CRC_GPOLYHU register. */
#define CRC_GPOLYHU_GPOLYHU_MASK                 (0xFFU)
#define CRC_GPOLYHU_GPOLYHU_SHIFT                (0U)
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x)) << CRC_GPOLYHU_GPOLYHU_SHIFT)) & CRC_GPOLYHU_GPOLYHU_MASK)

/*! @name CTRL - CRC Control register */
#define CRC_CTRL_TCRC_MASK                       (0x1000000U)
#define CRC_CTRL_TCRC_SHIFT                      (24U)
#define CRC_CTRL_TCRC(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_TCRC_SHIFT)) & CRC_CTRL_TCRC_MASK)
#define CRC_CTRL_WAS_MASK                        (0x2000000U)
#define CRC_CTRL_WAS_SHIFT                       (25U)
#define CRC_CTRL_WAS(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_WAS_SHIFT)) & CRC_CTRL_WAS_MASK)
#define CRC_CTRL_FXOR_MASK                       (0x4000000U)
#define CRC_CTRL_FXOR_SHIFT                      (26U)
#define CRC_CTRL_FXOR(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_FXOR_SHIFT)) & CRC_CTRL_FXOR_MASK)
#define CRC_CTRL_TOTR_MASK                       (0x30000000U)
#define CRC_CTRL_TOTR_SHIFT                      (28U)
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_TOTR_SHIFT)) & CRC_CTRL_TOTR_MASK)
#define CRC_CTRL_TOT_MASK                        (0xC0000000U)
#define CRC_CTRL_TOT_SHIFT                       (30U)
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_TOT_SHIFT)) & CRC_CTRL_TOT_MASK)

/*! @name CTRLHU - CRC_CTRLHU register. */
#define CRC_CTRLHU_TCRC_MASK                     (0x1U)
#define CRC_CTRLHU_TCRC_SHIFT                    (0U)
#define CRC_CTRLHU_TCRC(x)                       (((uint8_t)(((uint8_t)(x)) << CRC_CTRLHU_TCRC_SHIFT)) & CRC_CTRLHU_TCRC_MASK)
#define CRC_CTRLHU_WAS_MASK                      (0x2U)
#define CRC_CTRLHU_WAS_SHIFT                     (1U)
#define CRC_CTRLHU_WAS(x)                        (((uint8_t)(((uint8_t)(x)) << CRC_CTRLHU_WAS_SHIFT)) & CRC_CTRLHU_WAS_MASK)
#define CRC_CTRLHU_FXOR_MASK                     (0x4U)
#define CRC_CTRLHU_FXOR_SHIFT                    (2U)
#define CRC_CTRLHU_FXOR(x)                       (((uint8_t)(((uint8_t)(x)) << CRC_CTRLHU_FXOR_SHIFT)) & CRC_CTRLHU_FXOR_MASK)
#define CRC_CTRLHU_TOTR_MASK                     (0x30U)
#define CRC_CTRLHU_TOTR_SHIFT                    (4U)
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x)) << CRC_CTRLHU_TOTR_SHIFT)) & CRC_CTRLHU_TOTR_MASK)
#define CRC_CTRLHU_TOT_MASK                      (0xC0U)
#define CRC_CTRLHU_TOT_SHIFT                     (6U)
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x)) << CRC_CTRLHU_TOT_SHIFT)) & CRC_CTRLHU_TOT_MASK)


/*!
 * @}
 */ /* end of group CRC_Register_Masks */


/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base address */
#define CRC_BASE                                 (0x40032000u)
/** Peripheral CRC base pointer */
#define CRC0                                     ((CRC_Type *)CRC_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC0 }

/*!
 * @}
 */ /* end of group CRC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Peripheral_Access_Layer DAC Peripheral Access Layer
 * @{
 */

/** DAC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x2 */
    __IO uint8_t DATL;                               /**< DAC Data Low Register, array offset: 0x0, array step: 0x2 */
    __IO uint8_t DATH;                               /**< DAC Data High Register, array offset: 0x1, array step: 0x2 */
  } DAT[16];
  __IO uint8_t SR;                                 /**< DAC Status Register, offset: 0x20 */
  __IO uint8_t C0;                                 /**< DAC Control Register, offset: 0x21 */
  __IO uint8_t C1;                                 /**< DAC Control Register 1, offset: 0x22 */
  __IO uint8_t C2;                                 /**< DAC Control Register 2, offset: 0x23 */
} DAC_Type;

/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Masks DAC Register Masks
 * @{
 */

/*! @name DATL - DAC Data Low Register */
#define DAC_DATL_DATA0_MASK                      (0xFFU)
#define DAC_DATL_DATA0_SHIFT                     (0U)
#define DAC_DATL_DATA0(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_DATL_DATA0_SHIFT)) & DAC_DATL_DATA0_MASK)

/* The count of DAC_DATL */
#define DAC_DATL_COUNT                           (16U)

/*! @name DATH - DAC Data High Register */
#define DAC_DATH_DATA1_MASK                      (0xFU)
#define DAC_DATH_DATA1_SHIFT                     (0U)
#define DAC_DATH_DATA1(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_DATH_DATA1_SHIFT)) & DAC_DATH_DATA1_MASK)

/* The count of DAC_DATH */
#define DAC_DATH_COUNT                           (16U)

/*! @name SR - DAC Status Register */
#define DAC_SR_DACBFRPBF_MASK                    (0x1U)
#define DAC_SR_DACBFRPBF_SHIFT                   (0U)
#define DAC_SR_DACBFRPBF(x)                      (((uint8_t)(((uint8_t)(x)) << DAC_SR_DACBFRPBF_SHIFT)) & DAC_SR_DACBFRPBF_MASK)
#define DAC_SR_DACBFRPTF_MASK                    (0x2U)
#define DAC_SR_DACBFRPTF_SHIFT                   (1U)
#define DAC_SR_DACBFRPTF(x)                      (((uint8_t)(((uint8_t)(x)) << DAC_SR_DACBFRPTF_SHIFT)) & DAC_SR_DACBFRPTF_MASK)
#define DAC_SR_DACBFWMF_MASK                     (0x4U)
#define DAC_SR_DACBFWMF_SHIFT                    (2U)
#define DAC_SR_DACBFWMF(x)                       (((uint8_t)(((uint8_t)(x)) << DAC_SR_DACBFWMF_SHIFT)) & DAC_SR_DACBFWMF_MASK)

/*! @name C0 - DAC Control Register */
#define DAC_C0_DACBBIEN_MASK                     (0x1U)
#define DAC_C0_DACBBIEN_SHIFT                    (0U)
#define DAC_C0_DACBBIEN(x)                       (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACBBIEN_SHIFT)) & DAC_C0_DACBBIEN_MASK)
#define DAC_C0_DACBTIEN_MASK                     (0x2U)
#define DAC_C0_DACBTIEN_SHIFT                    (1U)
#define DAC_C0_DACBTIEN(x)                       (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACBTIEN_SHIFT)) & DAC_C0_DACBTIEN_MASK)
#define DAC_C0_DACBWIEN_MASK                     (0x4U)
#define DAC_C0_DACBWIEN_SHIFT                    (2U)
#define DAC_C0_DACBWIEN(x)                       (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACBWIEN_SHIFT)) & DAC_C0_DACBWIEN_MASK)
#define DAC_C0_LPEN_MASK                         (0x8U)
#define DAC_C0_LPEN_SHIFT                        (3U)
#define DAC_C0_LPEN(x)                           (((uint8_t)(((uint8_t)(x)) << DAC_C0_LPEN_SHIFT)) & DAC_C0_LPEN_MASK)
#define DAC_C0_DACSWTRG_MASK                     (0x10U)
#define DAC_C0_DACSWTRG_SHIFT                    (4U)
#define DAC_C0_DACSWTRG(x)                       (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACSWTRG_SHIFT)) & DAC_C0_DACSWTRG_MASK)
#define DAC_C0_DACTRGSEL_MASK                    (0x20U)
#define DAC_C0_DACTRGSEL_SHIFT                   (5U)
#define DAC_C0_DACTRGSEL(x)                      (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACTRGSEL_SHIFT)) & DAC_C0_DACTRGSEL_MASK)
#define DAC_C0_DACRFS_MASK                       (0x40U)
#define DAC_C0_DACRFS_SHIFT                      (6U)
#define DAC_C0_DACRFS(x)                         (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACRFS_SHIFT)) & DAC_C0_DACRFS_MASK)
#define DAC_C0_DACEN_MASK                        (0x80U)
#define DAC_C0_DACEN_SHIFT                       (7U)
#define DAC_C0_DACEN(x)                          (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACEN_SHIFT)) & DAC_C0_DACEN_MASK)

/*! @name C1 - DAC Control Register 1 */
#define DAC_C1_DACBFEN_MASK                      (0x1U)
#define DAC_C1_DACBFEN_SHIFT                     (0U)
#define DAC_C1_DACBFEN(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_C1_DACBFEN_SHIFT)) & DAC_C1_DACBFEN_MASK)
#define DAC_C1_DACBFMD_MASK                      (0x6U)
#define DAC_C1_DACBFMD_SHIFT                     (1U)
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_C1_DACBFMD_SHIFT)) & DAC_C1_DACBFMD_MASK)
#define DAC_C1_DACBFWM_MASK                      (0x18U)
#define DAC_C1_DACBFWM_SHIFT                     (3U)
#define DAC_C1_DACBFWM(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_C1_DACBFWM_SHIFT)) & DAC_C1_DACBFWM_MASK)
#define DAC_C1_DMAEN_MASK                        (0x80U)
#define DAC_C1_DMAEN_SHIFT                       (7U)
#define DAC_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x)) << DAC_C1_DMAEN_SHIFT)) & DAC_C1_DMAEN_MASK)

/*! @name C2 - DAC Control Register 2 */
#define DAC_C2_DACBFUP_MASK                      (0xFU)
#define DAC_C2_DACBFUP_SHIFT                     (0U)
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_C2_DACBFUP_SHIFT)) & DAC_C2_DACBFUP_MASK)
#define DAC_C2_DACBFRP_MASK                      (0xF0U)
#define DAC_C2_DACBFRP_SHIFT                     (4U)
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_C2_DACBFRP_SHIFT)) & DAC_C2_DACBFRP_MASK)


/*!
 * @}
 */ /* end of group DAC_Register_Masks */


/* DAC - Peripheral instance base addresses */
/** Peripheral DAC0 base address */
#define DAC0_BASE                                (0x4003F000u)
/** Peripheral DAC0 base pointer */
#define DAC0                                     ((DAC_Type *)DAC0_BASE)
/** Array initializer of DAC peripheral base addresses */
#define DAC_BASE_ADDRS                           { DAC0_BASE }
/** Array initializer of DAC peripheral base pointers */
#define DAC_BASE_PTRS                            { DAC0 }
/** Interrupt vectors for the DAC peripheral type */
#define DAC_IRQS                                 { DAC0_IRQn }

/*!
 * @}
 */ /* end of group DAC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control Register, offset: 0x0 */
  __I  uint32_t ES;                                /**< Error Status Register, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t ERQ;                               /**< Enable Request Register, offset: 0xC */
       uint8_t RESERVED_1[4];
  __IO uint32_t EEI;                               /**< Enable Error Interrupt Register, offset: 0x14 */
  __O  uint8_t CEEI;                               /**< Clear Enable Error Interrupt Register, offset: 0x18 */
  __O  uint8_t SEEI;                               /**< Set Enable Error Interrupt Register, offset: 0x19 */
  __O  uint8_t CERQ;                               /**< Clear Enable Request Register, offset: 0x1A */
  __O  uint8_t SERQ;                               /**< Set Enable Request Register, offset: 0x1B */
  __O  uint8_t CDNE;                               /**< Clear DONE Status Bit Register, offset: 0x1C */
  __O  uint8_t SSRT;                               /**< Set START Bit Register, offset: 0x1D */
  __O  uint8_t CERR;                               /**< Clear Error Register, offset: 0x1E */
  __O  uint8_t CINT;                               /**< Clear Interrupt Request Register, offset: 0x1F */
       uint8_t RESERVED_2[4];
  __IO uint32_t INT;                               /**< Interrupt Request Register, offset: 0x24 */
       uint8_t RESERVED_3[4];
  __IO uint32_t ERR;                               /**< Error Register, offset: 0x2C */
       uint8_t RESERVED_4[4];
  __I  uint32_t HRS;                               /**< Hardware Request Status Register, offset: 0x34 */
       uint8_t RESERVED_5[12];
  __IO uint32_t EARS;                              /**< Enable Asynchronous Request in Stop Register, offset: 0x44 */
       uint8_t RESERVED_6[184];
  __IO uint8_t DCHPRI3;                            /**< Channel n Priority Register, offset: 0x100 */
  __IO uint8_t DCHPRI2;                            /**< Channel n Priority Register, offset: 0x101 */
  __IO uint8_t DCHPRI1;                            /**< Channel n Priority Register, offset: 0x102 */
  __IO uint8_t DCHPRI0;                            /**< Channel n Priority Register, offset: 0x103 */
  __IO uint8_t DCHPRI7;                            /**< Channel n Priority Register, offset: 0x104 */
  __IO uint8_t DCHPRI6;                            /**< Channel n Priority Register, offset: 0x105 */
  __IO uint8_t DCHPRI5;                            /**< Channel n Priority Register, offset: 0x106 */
  __IO uint8_t DCHPRI4;                            /**< Channel n Priority Register, offset: 0x107 */
  __IO uint8_t DCHPRI11;                           /**< Channel n Priority Register, offset: 0x108 */
  __IO uint8_t DCHPRI10;                           /**< Channel n Priority Register, offset: 0x109 */
  __IO uint8_t DCHPRI9;                            /**< Channel n Priority Register, offset: 0x10A */
  __IO uint8_t DCHPRI8;                            /**< Channel n Priority Register, offset: 0x10B */
  __IO uint8_t DCHPRI15;                           /**< Channel n Priority Register, offset: 0x10C */
  __IO uint8_t DCHPRI14;                           /**< Channel n Priority Register, offset: 0x10D */
  __IO uint8_t DCHPRI13;                           /**< Channel n Priority Register, offset: 0x10E */
  __IO uint8_t DCHPRI12;                           /**< Channel n Priority Register, offset: 0x10F */
       uint8_t RESERVED_7[3824];
  struct {                                         /* offset: 0x1000, array step: 0x20 */
    __IO uint32_t SADDR;                             /**< TCD Source Address, array offset: 0x1000, array step: 0x20 */
    __IO uint16_t SOFF;                              /**< TCD Signed Source Address Offset, array offset: 0x1004, array step: 0x20 */
    __IO uint16_t ATTR;                              /**< TCD Transfer Attributes, array offset: 0x1006, array step: 0x20 */
    union {                                          /* offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLNO;                       /**< TCD Minor Byte Count (Minor Loop Mapping Disabled), array offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLOFFNO;                    /**< TCD Signed Minor Loop Offset (Minor Loop Mapping Enabled and Offset Disabled), array offset: 0x1008, array step: 0x20 */
      __IO uint32_t NBYTES_MLOFFYES;                   /**< TCD Signed Minor Loop Offset (Minor Loop Mapping and Offset Enabled), array offset: 0x1008, array step: 0x20 */
    };
    __IO uint32_t SLAST;                             /**< TCD Last Source Address Adjustment, array offset: 0x100C, array step: 0x20 */
    __IO uint32_t DADDR;                             /**< TCD Destination Address, array offset: 0x1010, array step: 0x20 */
    __IO uint16_t DOFF;                              /**< TCD Signed Destination Address Offset, array offset: 0x1014, array step: 0x20 */
    union {                                          /* offset: 0x1016, array step: 0x20 */
      __IO uint16_t CITER_ELINKNO;                     /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x1016, array step: 0x20 */
      __IO uint16_t CITER_ELINKYES;                    /**< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x1016, array step: 0x20 */
    };
    __IO uint32_t DLAST_SGA;                         /**< TCD Last Destination Address Adjustment/Scatter Gather Address, array offset: 0x1018, array step: 0x20 */
    __IO uint16_t CSR;                               /**< TCD Control and Status, array offset: 0x101C, array step: 0x20 */
    union {                                          /* offset: 0x101E, array step: 0x20 */
      __IO uint16_t BITER_ELINKNO;                     /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x101E, array step: 0x20 */
      __IO uint16_t BITER_ELINKYES;                    /**< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x101E, array step: 0x20 */
    };
  } TCD[16];
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/*! @name CR - Control Register */
#define DMA_CR_EDBG_MASK                         (0x2U)
#define DMA_CR_EDBG_SHIFT                        (1U)
#define DMA_CR_EDBG(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_CR_EDBG_SHIFT)) & DMA_CR_EDBG_MASK)
#define DMA_CR_ERCA_MASK                         (0x4U)
#define DMA_CR_ERCA_SHIFT                        (2U)
#define DMA_CR_ERCA(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_CR_ERCA_SHIFT)) & DMA_CR_ERCA_MASK)
#define DMA_CR_HOE_MASK                          (0x10U)
#define DMA_CR_HOE_SHIFT                         (4U)
#define DMA_CR_HOE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_CR_HOE_SHIFT)) & DMA_CR_HOE_MASK)
#define DMA_CR_HALT_MASK                         (0x20U)
#define DMA_CR_HALT_SHIFT                        (5U)
#define DMA_CR_HALT(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_CR_HALT_SHIFT)) & DMA_CR_HALT_MASK)
#define DMA_CR_CLM_MASK                          (0x40U)
#define DMA_CR_CLM_SHIFT                         (6U)
#define DMA_CR_CLM(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_CR_CLM_SHIFT)) & DMA_CR_CLM_MASK)
#define DMA_CR_EMLM_MASK                         (0x80U)
#define DMA_CR_EMLM_SHIFT                        (7U)
#define DMA_CR_EMLM(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_CR_EMLM_SHIFT)) & DMA_CR_EMLM_MASK)
#define DMA_CR_ECX_MASK                          (0x10000U)
#define DMA_CR_ECX_SHIFT                         (16U)
#define DMA_CR_ECX(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_CR_ECX_SHIFT)) & DMA_CR_ECX_MASK)
#define DMA_CR_CX_MASK                           (0x20000U)
#define DMA_CR_CX_SHIFT                          (17U)
#define DMA_CR_CX(x)                             (((uint32_t)(((uint32_t)(x)) << DMA_CR_CX_SHIFT)) & DMA_CR_CX_MASK)

/*! @name ES - Error Status Register */
#define DMA_ES_DBE_MASK                          (0x1U)
#define DMA_ES_DBE_SHIFT                         (0U)
#define DMA_ES_DBE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_DBE_SHIFT)) & DMA_ES_DBE_MASK)
#define DMA_ES_SBE_MASK                          (0x2U)
#define DMA_ES_SBE_SHIFT                         (1U)
#define DMA_ES_SBE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_SBE_SHIFT)) & DMA_ES_SBE_MASK)
#define DMA_ES_SGE_MASK                          (0x4U)
#define DMA_ES_SGE_SHIFT                         (2U)
#define DMA_ES_SGE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_SGE_SHIFT)) & DMA_ES_SGE_MASK)
#define DMA_ES_NCE_MASK                          (0x8U)
#define DMA_ES_NCE_SHIFT                         (3U)
#define DMA_ES_NCE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_NCE_SHIFT)) & DMA_ES_NCE_MASK)
#define DMA_ES_DOE_MASK                          (0x10U)
#define DMA_ES_DOE_SHIFT                         (4U)
#define DMA_ES_DOE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_DOE_SHIFT)) & DMA_ES_DOE_MASK)
#define DMA_ES_DAE_MASK                          (0x20U)
#define DMA_ES_DAE_SHIFT                         (5U)
#define DMA_ES_DAE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_DAE_SHIFT)) & DMA_ES_DAE_MASK)
#define DMA_ES_SOE_MASK                          (0x40U)
#define DMA_ES_SOE_SHIFT                         (6U)
#define DMA_ES_SOE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_SOE_SHIFT)) & DMA_ES_SOE_MASK)
#define DMA_ES_SAE_MASK                          (0x80U)
#define DMA_ES_SAE_SHIFT                         (7U)
#define DMA_ES_SAE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_SAE_SHIFT)) & DMA_ES_SAE_MASK)
#define DMA_ES_ERRCHN_MASK                       (0xF00U)
#define DMA_ES_ERRCHN_SHIFT                      (8U)
#define DMA_ES_ERRCHN(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ES_ERRCHN_SHIFT)) & DMA_ES_ERRCHN_MASK)
#define DMA_ES_CPE_MASK                          (0x4000U)
#define DMA_ES_CPE_SHIFT                         (14U)
#define DMA_ES_CPE(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_CPE_SHIFT)) & DMA_ES_CPE_MASK)
#define DMA_ES_ECX_MASK                          (0x10000U)
#define DMA_ES_ECX_SHIFT                         (16U)
#define DMA_ES_ECX(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_ECX_SHIFT)) & DMA_ES_ECX_MASK)
#define DMA_ES_VLD_MASK                          (0x80000000U)
#define DMA_ES_VLD_SHIFT                         (31U)
#define DMA_ES_VLD(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_ES_VLD_SHIFT)) & DMA_ES_VLD_MASK)

/*! @name ERQ - Enable Request Register */
#define DMA_ERQ_ERQ0_MASK                        (0x1U)
#define DMA_ERQ_ERQ0_SHIFT                       (0U)
#define DMA_ERQ_ERQ0(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ0_SHIFT)) & DMA_ERQ_ERQ0_MASK)
#define DMA_ERQ_ERQ1_MASK                        (0x2U)
#define DMA_ERQ_ERQ1_SHIFT                       (1U)
#define DMA_ERQ_ERQ1(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ1_SHIFT)) & DMA_ERQ_ERQ1_MASK)
#define DMA_ERQ_ERQ2_MASK                        (0x4U)
#define DMA_ERQ_ERQ2_SHIFT                       (2U)
#define DMA_ERQ_ERQ2(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ2_SHIFT)) & DMA_ERQ_ERQ2_MASK)
#define DMA_ERQ_ERQ3_MASK                        (0x8U)
#define DMA_ERQ_ERQ3_SHIFT                       (3U)
#define DMA_ERQ_ERQ3(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ3_SHIFT)) & DMA_ERQ_ERQ3_MASK)
#define DMA_ERQ_ERQ4_MASK                        (0x10U)
#define DMA_ERQ_ERQ4_SHIFT                       (4U)
#define DMA_ERQ_ERQ4(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ4_SHIFT)) & DMA_ERQ_ERQ4_MASK)
#define DMA_ERQ_ERQ5_MASK                        (0x20U)
#define DMA_ERQ_ERQ5_SHIFT                       (5U)
#define DMA_ERQ_ERQ5(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ5_SHIFT)) & DMA_ERQ_ERQ5_MASK)
#define DMA_ERQ_ERQ6_MASK                        (0x40U)
#define DMA_ERQ_ERQ6_SHIFT                       (6U)
#define DMA_ERQ_ERQ6(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ6_SHIFT)) & DMA_ERQ_ERQ6_MASK)
#define DMA_ERQ_ERQ7_MASK                        (0x80U)
#define DMA_ERQ_ERQ7_SHIFT                       (7U)
#define DMA_ERQ_ERQ7(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ7_SHIFT)) & DMA_ERQ_ERQ7_MASK)
#define DMA_ERQ_ERQ8_MASK                        (0x100U)
#define DMA_ERQ_ERQ8_SHIFT                       (8U)
#define DMA_ERQ_ERQ8(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ8_SHIFT)) & DMA_ERQ_ERQ8_MASK)
#define DMA_ERQ_ERQ9_MASK                        (0x200U)
#define DMA_ERQ_ERQ9_SHIFT                       (9U)
#define DMA_ERQ_ERQ9(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ9_SHIFT)) & DMA_ERQ_ERQ9_MASK)
#define DMA_ERQ_ERQ10_MASK                       (0x400U)
#define DMA_ERQ_ERQ10_SHIFT                      (10U)
#define DMA_ERQ_ERQ10(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ10_SHIFT)) & DMA_ERQ_ERQ10_MASK)
#define DMA_ERQ_ERQ11_MASK                       (0x800U)
#define DMA_ERQ_ERQ11_SHIFT                      (11U)
#define DMA_ERQ_ERQ11(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ11_SHIFT)) & DMA_ERQ_ERQ11_MASK)
#define DMA_ERQ_ERQ12_MASK                       (0x1000U)
#define DMA_ERQ_ERQ12_SHIFT                      (12U)
#define DMA_ERQ_ERQ12(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ12_SHIFT)) & DMA_ERQ_ERQ12_MASK)
#define DMA_ERQ_ERQ13_MASK                       (0x2000U)
#define DMA_ERQ_ERQ13_SHIFT                      (13U)
#define DMA_ERQ_ERQ13(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ13_SHIFT)) & DMA_ERQ_ERQ13_MASK)
#define DMA_ERQ_ERQ14_MASK                       (0x4000U)
#define DMA_ERQ_ERQ14_SHIFT                      (14U)
#define DMA_ERQ_ERQ14(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ14_SHIFT)) & DMA_ERQ_ERQ14_MASK)
#define DMA_ERQ_ERQ15_MASK                       (0x8000U)
#define DMA_ERQ_ERQ15_SHIFT                      (15U)
#define DMA_ERQ_ERQ15(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERQ_ERQ15_SHIFT)) & DMA_ERQ_ERQ15_MASK)

/*! @name EEI - Enable Error Interrupt Register */
#define DMA_EEI_EEI0_MASK                        (0x1U)
#define DMA_EEI_EEI0_SHIFT                       (0U)
#define DMA_EEI_EEI0(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI0_SHIFT)) & DMA_EEI_EEI0_MASK)
#define DMA_EEI_EEI1_MASK                        (0x2U)
#define DMA_EEI_EEI1_SHIFT                       (1U)
#define DMA_EEI_EEI1(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI1_SHIFT)) & DMA_EEI_EEI1_MASK)
#define DMA_EEI_EEI2_MASK                        (0x4U)
#define DMA_EEI_EEI2_SHIFT                       (2U)
#define DMA_EEI_EEI2(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI2_SHIFT)) & DMA_EEI_EEI2_MASK)
#define DMA_EEI_EEI3_MASK                        (0x8U)
#define DMA_EEI_EEI3_SHIFT                       (3U)
#define DMA_EEI_EEI3(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI3_SHIFT)) & DMA_EEI_EEI3_MASK)
#define DMA_EEI_EEI4_MASK                        (0x10U)
#define DMA_EEI_EEI4_SHIFT                       (4U)
#define DMA_EEI_EEI4(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI4_SHIFT)) & DMA_EEI_EEI4_MASK)
#define DMA_EEI_EEI5_MASK                        (0x20U)
#define DMA_EEI_EEI5_SHIFT                       (5U)
#define DMA_EEI_EEI5(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI5_SHIFT)) & DMA_EEI_EEI5_MASK)
#define DMA_EEI_EEI6_MASK                        (0x40U)
#define DMA_EEI_EEI6_SHIFT                       (6U)
#define DMA_EEI_EEI6(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI6_SHIFT)) & DMA_EEI_EEI6_MASK)
#define DMA_EEI_EEI7_MASK                        (0x80U)
#define DMA_EEI_EEI7_SHIFT                       (7U)
#define DMA_EEI_EEI7(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI7_SHIFT)) & DMA_EEI_EEI7_MASK)
#define DMA_EEI_EEI8_MASK                        (0x100U)
#define DMA_EEI_EEI8_SHIFT                       (8U)
#define DMA_EEI_EEI8(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI8_SHIFT)) & DMA_EEI_EEI8_MASK)
#define DMA_EEI_EEI9_MASK                        (0x200U)
#define DMA_EEI_EEI9_SHIFT                       (9U)
#define DMA_EEI_EEI9(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI9_SHIFT)) & DMA_EEI_EEI9_MASK)
#define DMA_EEI_EEI10_MASK                       (0x400U)
#define DMA_EEI_EEI10_SHIFT                      (10U)
#define DMA_EEI_EEI10(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI10_SHIFT)) & DMA_EEI_EEI10_MASK)
#define DMA_EEI_EEI11_MASK                       (0x800U)
#define DMA_EEI_EEI11_SHIFT                      (11U)
#define DMA_EEI_EEI11(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI11_SHIFT)) & DMA_EEI_EEI11_MASK)
#define DMA_EEI_EEI12_MASK                       (0x1000U)
#define DMA_EEI_EEI12_SHIFT                      (12U)
#define DMA_EEI_EEI12(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI12_SHIFT)) & DMA_EEI_EEI12_MASK)
#define DMA_EEI_EEI13_MASK                       (0x2000U)
#define DMA_EEI_EEI13_SHIFT                      (13U)
#define DMA_EEI_EEI13(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI13_SHIFT)) & DMA_EEI_EEI13_MASK)
#define DMA_EEI_EEI14_MASK                       (0x4000U)
#define DMA_EEI_EEI14_SHIFT                      (14U)
#define DMA_EEI_EEI14(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI14_SHIFT)) & DMA_EEI_EEI14_MASK)
#define DMA_EEI_EEI15_MASK                       (0x8000U)
#define DMA_EEI_EEI15_SHIFT                      (15U)
#define DMA_EEI_EEI15(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_EEI_EEI15_SHIFT)) & DMA_EEI_EEI15_MASK)

/*! @name CEEI - Clear Enable Error Interrupt Register */
#define DMA_CEEI_CEEI_MASK                       (0xFU)
#define DMA_CEEI_CEEI_SHIFT                      (0U)
#define DMA_CEEI_CEEI(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_CEEI_CEEI_SHIFT)) & DMA_CEEI_CEEI_MASK)
#define DMA_CEEI_CAEE_MASK                       (0x40U)
#define DMA_CEEI_CAEE_SHIFT                      (6U)
#define DMA_CEEI_CAEE(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_CEEI_CAEE_SHIFT)) & DMA_CEEI_CAEE_MASK)
#define DMA_CEEI_NOP_MASK                        (0x80U)
#define DMA_CEEI_NOP_SHIFT                       (7U)
#define DMA_CEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x)) << DMA_CEEI_NOP_SHIFT)) & DMA_CEEI_NOP_MASK)

/*! @name SEEI - Set Enable Error Interrupt Register */
#define DMA_SEEI_SEEI_MASK                       (0xFU)
#define DMA_SEEI_SEEI_SHIFT                      (0U)
#define DMA_SEEI_SEEI(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_SEEI_SEEI_SHIFT)) & DMA_SEEI_SEEI_MASK)
#define DMA_SEEI_SAEE_MASK                       (0x40U)
#define DMA_SEEI_SAEE_SHIFT                      (6U)
#define DMA_SEEI_SAEE(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_SEEI_SAEE_SHIFT)) & DMA_SEEI_SAEE_MASK)
#define DMA_SEEI_NOP_MASK                        (0x80U)
#define DMA_SEEI_NOP_SHIFT                       (7U)
#define DMA_SEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x)) << DMA_SEEI_NOP_SHIFT)) & DMA_SEEI_NOP_MASK)

/*! @name CERQ - Clear Enable Request Register */
#define DMA_CERQ_CERQ_MASK                       (0xFU)
#define DMA_CERQ_CERQ_SHIFT                      (0U)
#define DMA_CERQ_CERQ(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_CERQ_CERQ_SHIFT)) & DMA_CERQ_CERQ_MASK)
#define DMA_CERQ_CAER_MASK                       (0x40U)
#define DMA_CERQ_CAER_SHIFT                      (6U)
#define DMA_CERQ_CAER(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_CERQ_CAER_SHIFT)) & DMA_CERQ_CAER_MASK)
#define DMA_CERQ_NOP_MASK                        (0x80U)
#define DMA_CERQ_NOP_SHIFT                       (7U)
#define DMA_CERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x)) << DMA_CERQ_NOP_SHIFT)) & DMA_CERQ_NOP_MASK)

/*! @name SERQ - Set Enable Request Register */
#define DMA_SERQ_SERQ_MASK                       (0xFU)
#define DMA_SERQ_SERQ_SHIFT                      (0U)
#define DMA_SERQ_SERQ(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_SERQ_SERQ_SHIFT)) & DMA_SERQ_SERQ_MASK)
#define DMA_SERQ_SAER_MASK                       (0x40U)
#define DMA_SERQ_SAER_SHIFT                      (6U)
#define DMA_SERQ_SAER(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_SERQ_SAER_SHIFT)) & DMA_SERQ_SAER_MASK)
#define DMA_SERQ_NOP_MASK                        (0x80U)
#define DMA_SERQ_NOP_SHIFT                       (7U)
#define DMA_SERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x)) << DMA_SERQ_NOP_SHIFT)) & DMA_SERQ_NOP_MASK)

/*! @name CDNE - Clear DONE Status Bit Register */
#define DMA_CDNE_CDNE_MASK                       (0xFU)
#define DMA_CDNE_CDNE_SHIFT                      (0U)
#define DMA_CDNE_CDNE(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_CDNE_CDNE_SHIFT)) & DMA_CDNE_CDNE_MASK)
#define DMA_CDNE_CADN_MASK                       (0x40U)
#define DMA_CDNE_CADN_SHIFT                      (6U)
#define DMA_CDNE_CADN(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_CDNE_CADN_SHIFT)) & DMA_CDNE_CADN_MASK)
#define DMA_CDNE_NOP_MASK                        (0x80U)
#define DMA_CDNE_NOP_SHIFT                       (7U)
#define DMA_CDNE_NOP(x)                          (((uint8_t)(((uint8_t)(x)) << DMA_CDNE_NOP_SHIFT)) & DMA_CDNE_NOP_MASK)

/*! @name SSRT - Set START Bit Register */
#define DMA_SSRT_SSRT_MASK                       (0xFU)
#define DMA_SSRT_SSRT_SHIFT                      (0U)
#define DMA_SSRT_SSRT(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_SSRT_SSRT_SHIFT)) & DMA_SSRT_SSRT_MASK)
#define DMA_SSRT_SAST_MASK                       (0x40U)
#define DMA_SSRT_SAST_SHIFT                      (6U)
#define DMA_SSRT_SAST(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_SSRT_SAST_SHIFT)) & DMA_SSRT_SAST_MASK)
#define DMA_SSRT_NOP_MASK                        (0x80U)
#define DMA_SSRT_NOP_SHIFT                       (7U)
#define DMA_SSRT_NOP(x)                          (((uint8_t)(((uint8_t)(x)) << DMA_SSRT_NOP_SHIFT)) & DMA_SSRT_NOP_MASK)

/*! @name CERR - Clear Error Register */
#define DMA_CERR_CERR_MASK                       (0xFU)
#define DMA_CERR_CERR_SHIFT                      (0U)
#define DMA_CERR_CERR(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_CERR_CERR_SHIFT)) & DMA_CERR_CERR_MASK)
#define DMA_CERR_CAEI_MASK                       (0x40U)
#define DMA_CERR_CAEI_SHIFT                      (6U)
#define DMA_CERR_CAEI(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_CERR_CAEI_SHIFT)) & DMA_CERR_CAEI_MASK)
#define DMA_CERR_NOP_MASK                        (0x80U)
#define DMA_CERR_NOP_SHIFT                       (7U)
#define DMA_CERR_NOP(x)                          (((uint8_t)(((uint8_t)(x)) << DMA_CERR_NOP_SHIFT)) & DMA_CERR_NOP_MASK)

/*! @name CINT - Clear Interrupt Request Register */
#define DMA_CINT_CINT_MASK                       (0xFU)
#define DMA_CINT_CINT_SHIFT                      (0U)
#define DMA_CINT_CINT(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_CINT_CINT_SHIFT)) & DMA_CINT_CINT_MASK)
#define DMA_CINT_CAIR_MASK                       (0x40U)
#define DMA_CINT_CAIR_SHIFT                      (6U)
#define DMA_CINT_CAIR(x)                         (((uint8_t)(((uint8_t)(x)) << DMA_CINT_CAIR_SHIFT)) & DMA_CINT_CAIR_MASK)
#define DMA_CINT_NOP_MASK                        (0x80U)
#define DMA_CINT_NOP_SHIFT                       (7U)
#define DMA_CINT_NOP(x)                          (((uint8_t)(((uint8_t)(x)) << DMA_CINT_NOP_SHIFT)) & DMA_CINT_NOP_MASK)

/*! @name INT - Interrupt Request Register */
#define DMA_INT_INT0_MASK                        (0x1U)
#define DMA_INT_INT0_SHIFT                       (0U)
#define DMA_INT_INT0(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT0_SHIFT)) & DMA_INT_INT0_MASK)
#define DMA_INT_INT1_MASK                        (0x2U)
#define DMA_INT_INT1_SHIFT                       (1U)
#define DMA_INT_INT1(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT1_SHIFT)) & DMA_INT_INT1_MASK)
#define DMA_INT_INT2_MASK                        (0x4U)
#define DMA_INT_INT2_SHIFT                       (2U)
#define DMA_INT_INT2(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT2_SHIFT)) & DMA_INT_INT2_MASK)
#define DMA_INT_INT3_MASK                        (0x8U)
#define DMA_INT_INT3_SHIFT                       (3U)
#define DMA_INT_INT3(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT3_SHIFT)) & DMA_INT_INT3_MASK)
#define DMA_INT_INT4_MASK                        (0x10U)
#define DMA_INT_INT4_SHIFT                       (4U)
#define DMA_INT_INT4(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT4_SHIFT)) & DMA_INT_INT4_MASK)
#define DMA_INT_INT5_MASK                        (0x20U)
#define DMA_INT_INT5_SHIFT                       (5U)
#define DMA_INT_INT5(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT5_SHIFT)) & DMA_INT_INT5_MASK)
#define DMA_INT_INT6_MASK                        (0x40U)
#define DMA_INT_INT6_SHIFT                       (6U)
#define DMA_INT_INT6(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT6_SHIFT)) & DMA_INT_INT6_MASK)
#define DMA_INT_INT7_MASK                        (0x80U)
#define DMA_INT_INT7_SHIFT                       (7U)
#define DMA_INT_INT7(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT7_SHIFT)) & DMA_INT_INT7_MASK)
#define DMA_INT_INT8_MASK                        (0x100U)
#define DMA_INT_INT8_SHIFT                       (8U)
#define DMA_INT_INT8(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT8_SHIFT)) & DMA_INT_INT8_MASK)
#define DMA_INT_INT9_MASK                        (0x200U)
#define DMA_INT_INT9_SHIFT                       (9U)
#define DMA_INT_INT9(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT9_SHIFT)) & DMA_INT_INT9_MASK)
#define DMA_INT_INT10_MASK                       (0x400U)
#define DMA_INT_INT10_SHIFT                      (10U)
#define DMA_INT_INT10(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT10_SHIFT)) & DMA_INT_INT10_MASK)
#define DMA_INT_INT11_MASK                       (0x800U)
#define DMA_INT_INT11_SHIFT                      (11U)
#define DMA_INT_INT11(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT11_SHIFT)) & DMA_INT_INT11_MASK)
#define DMA_INT_INT12_MASK                       (0x1000U)
#define DMA_INT_INT12_SHIFT                      (12U)
#define DMA_INT_INT12(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT12_SHIFT)) & DMA_INT_INT12_MASK)
#define DMA_INT_INT13_MASK                       (0x2000U)
#define DMA_INT_INT13_SHIFT                      (13U)
#define DMA_INT_INT13(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT13_SHIFT)) & DMA_INT_INT13_MASK)
#define DMA_INT_INT14_MASK                       (0x4000U)
#define DMA_INT_INT14_SHIFT                      (14U)
#define DMA_INT_INT14(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT14_SHIFT)) & DMA_INT_INT14_MASK)
#define DMA_INT_INT15_MASK                       (0x8000U)
#define DMA_INT_INT15_SHIFT                      (15U)
#define DMA_INT_INT15(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_INT_INT15_SHIFT)) & DMA_INT_INT15_MASK)

/*! @name ERR - Error Register */
#define DMA_ERR_ERR0_MASK                        (0x1U)
#define DMA_ERR_ERR0_SHIFT                       (0U)
#define DMA_ERR_ERR0(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR0_SHIFT)) & DMA_ERR_ERR0_MASK)
#define DMA_ERR_ERR1_MASK                        (0x2U)
#define DMA_ERR_ERR1_SHIFT                       (1U)
#define DMA_ERR_ERR1(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR1_SHIFT)) & DMA_ERR_ERR1_MASK)
#define DMA_ERR_ERR2_MASK                        (0x4U)
#define DMA_ERR_ERR2_SHIFT                       (2U)
#define DMA_ERR_ERR2(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR2_SHIFT)) & DMA_ERR_ERR2_MASK)
#define DMA_ERR_ERR3_MASK                        (0x8U)
#define DMA_ERR_ERR3_SHIFT                       (3U)
#define DMA_ERR_ERR3(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR3_SHIFT)) & DMA_ERR_ERR3_MASK)
#define DMA_ERR_ERR4_MASK                        (0x10U)
#define DMA_ERR_ERR4_SHIFT                       (4U)
#define DMA_ERR_ERR4(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR4_SHIFT)) & DMA_ERR_ERR4_MASK)
#define DMA_ERR_ERR5_MASK                        (0x20U)
#define DMA_ERR_ERR5_SHIFT                       (5U)
#define DMA_ERR_ERR5(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR5_SHIFT)) & DMA_ERR_ERR5_MASK)
#define DMA_ERR_ERR6_MASK                        (0x40U)
#define DMA_ERR_ERR6_SHIFT                       (6U)
#define DMA_ERR_ERR6(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR6_SHIFT)) & DMA_ERR_ERR6_MASK)
#define DMA_ERR_ERR7_MASK                        (0x80U)
#define DMA_ERR_ERR7_SHIFT                       (7U)
#define DMA_ERR_ERR7(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR7_SHIFT)) & DMA_ERR_ERR7_MASK)
#define DMA_ERR_ERR8_MASK                        (0x100U)
#define DMA_ERR_ERR8_SHIFT                       (8U)
#define DMA_ERR_ERR8(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR8_SHIFT)) & DMA_ERR_ERR8_MASK)
#define DMA_ERR_ERR9_MASK                        (0x200U)
#define DMA_ERR_ERR9_SHIFT                       (9U)
#define DMA_ERR_ERR9(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR9_SHIFT)) & DMA_ERR_ERR9_MASK)
#define DMA_ERR_ERR10_MASK                       (0x400U)
#define DMA_ERR_ERR10_SHIFT                      (10U)
#define DMA_ERR_ERR10(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR10_SHIFT)) & DMA_ERR_ERR10_MASK)
#define DMA_ERR_ERR11_MASK                       (0x800U)
#define DMA_ERR_ERR11_SHIFT                      (11U)
#define DMA_ERR_ERR11(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR11_SHIFT)) & DMA_ERR_ERR11_MASK)
#define DMA_ERR_ERR12_MASK                       (0x1000U)
#define DMA_ERR_ERR12_SHIFT                      (12U)
#define DMA_ERR_ERR12(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR12_SHIFT)) & DMA_ERR_ERR12_MASK)
#define DMA_ERR_ERR13_MASK                       (0x2000U)
#define DMA_ERR_ERR13_SHIFT                      (13U)
#define DMA_ERR_ERR13(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR13_SHIFT)) & DMA_ERR_ERR13_MASK)
#define DMA_ERR_ERR14_MASK                       (0x4000U)
#define DMA_ERR_ERR14_SHIFT                      (14U)
#define DMA_ERR_ERR14(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR14_SHIFT)) & DMA_ERR_ERR14_MASK)
#define DMA_ERR_ERR15_MASK                       (0x8000U)
#define DMA_ERR_ERR15_SHIFT                      (15U)
#define DMA_ERR_ERR15(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_ERR_ERR15_SHIFT)) & DMA_ERR_ERR15_MASK)

/*! @name HRS - Hardware Request Status Register */
#define DMA_HRS_HRS0_MASK                        (0x1U)
#define DMA_HRS_HRS0_SHIFT                       (0U)
#define DMA_HRS_HRS0(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS0_SHIFT)) & DMA_HRS_HRS0_MASK)
#define DMA_HRS_HRS1_MASK                        (0x2U)
#define DMA_HRS_HRS1_SHIFT                       (1U)
#define DMA_HRS_HRS1(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS1_SHIFT)) & DMA_HRS_HRS1_MASK)
#define DMA_HRS_HRS2_MASK                        (0x4U)
#define DMA_HRS_HRS2_SHIFT                       (2U)
#define DMA_HRS_HRS2(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS2_SHIFT)) & DMA_HRS_HRS2_MASK)
#define DMA_HRS_HRS3_MASK                        (0x8U)
#define DMA_HRS_HRS3_SHIFT                       (3U)
#define DMA_HRS_HRS3(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS3_SHIFT)) & DMA_HRS_HRS3_MASK)
#define DMA_HRS_HRS4_MASK                        (0x10U)
#define DMA_HRS_HRS4_SHIFT                       (4U)
#define DMA_HRS_HRS4(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS4_SHIFT)) & DMA_HRS_HRS4_MASK)
#define DMA_HRS_HRS5_MASK                        (0x20U)
#define DMA_HRS_HRS5_SHIFT                       (5U)
#define DMA_HRS_HRS5(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS5_SHIFT)) & DMA_HRS_HRS5_MASK)
#define DMA_HRS_HRS6_MASK                        (0x40U)
#define DMA_HRS_HRS6_SHIFT                       (6U)
#define DMA_HRS_HRS6(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS6_SHIFT)) & DMA_HRS_HRS6_MASK)
#define DMA_HRS_HRS7_MASK                        (0x80U)
#define DMA_HRS_HRS7_SHIFT                       (7U)
#define DMA_HRS_HRS7(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS7_SHIFT)) & DMA_HRS_HRS7_MASK)
#define DMA_HRS_HRS8_MASK                        (0x100U)
#define DMA_HRS_HRS8_SHIFT                       (8U)
#define DMA_HRS_HRS8(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS8_SHIFT)) & DMA_HRS_HRS8_MASK)
#define DMA_HRS_HRS9_MASK                        (0x200U)
#define DMA_HRS_HRS9_SHIFT                       (9U)
#define DMA_HRS_HRS9(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS9_SHIFT)) & DMA_HRS_HRS9_MASK)
#define DMA_HRS_HRS10_MASK                       (0x400U)
#define DMA_HRS_HRS10_SHIFT                      (10U)
#define DMA_HRS_HRS10(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS10_SHIFT)) & DMA_HRS_HRS10_MASK)
#define DMA_HRS_HRS11_MASK                       (0x800U)
#define DMA_HRS_HRS11_SHIFT                      (11U)
#define DMA_HRS_HRS11(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS11_SHIFT)) & DMA_HRS_HRS11_MASK)
#define DMA_HRS_HRS12_MASK                       (0x1000U)
#define DMA_HRS_HRS12_SHIFT                      (12U)
#define DMA_HRS_HRS12(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS12_SHIFT)) & DMA_HRS_HRS12_MASK)
#define DMA_HRS_HRS13_MASK                       (0x2000U)
#define DMA_HRS_HRS13_SHIFT                      (13U)
#define DMA_HRS_HRS13(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS13_SHIFT)) & DMA_HRS_HRS13_MASK)
#define DMA_HRS_HRS14_MASK                       (0x4000U)
#define DMA_HRS_HRS14_SHIFT                      (14U)
#define DMA_HRS_HRS14(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS14_SHIFT)) & DMA_HRS_HRS14_MASK)
#define DMA_HRS_HRS15_MASK                       (0x8000U)
#define DMA_HRS_HRS15_SHIFT                      (15U)
#define DMA_HRS_HRS15(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_HRS_HRS15_SHIFT)) & DMA_HRS_HRS15_MASK)

/*! @name EARS - Enable Asynchronous Request in Stop Register */
#define DMA_EARS_EDREQ_0_MASK                    (0x1U)
#define DMA_EARS_EDREQ_0_SHIFT                   (0U)
#define DMA_EARS_EDREQ_0(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_0_SHIFT)) & DMA_EARS_EDREQ_0_MASK)
#define DMA_EARS_EDREQ_1_MASK                    (0x2U)
#define DMA_EARS_EDREQ_1_SHIFT                   (1U)
#define DMA_EARS_EDREQ_1(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_1_SHIFT)) & DMA_EARS_EDREQ_1_MASK)
#define DMA_EARS_EDREQ_2_MASK                    (0x4U)
#define DMA_EARS_EDREQ_2_SHIFT                   (2U)
#define DMA_EARS_EDREQ_2(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_2_SHIFT)) & DMA_EARS_EDREQ_2_MASK)
#define DMA_EARS_EDREQ_3_MASK                    (0x8U)
#define DMA_EARS_EDREQ_3_SHIFT                   (3U)
#define DMA_EARS_EDREQ_3(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_3_SHIFT)) & DMA_EARS_EDREQ_3_MASK)
#define DMA_EARS_EDREQ_4_MASK                    (0x10U)
#define DMA_EARS_EDREQ_4_SHIFT                   (4U)
#define DMA_EARS_EDREQ_4(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_4_SHIFT)) & DMA_EARS_EDREQ_4_MASK)
#define DMA_EARS_EDREQ_5_MASK                    (0x20U)
#define DMA_EARS_EDREQ_5_SHIFT                   (5U)
#define DMA_EARS_EDREQ_5(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_5_SHIFT)) & DMA_EARS_EDREQ_5_MASK)
#define DMA_EARS_EDREQ_6_MASK                    (0x40U)
#define DMA_EARS_EDREQ_6_SHIFT                   (6U)
#define DMA_EARS_EDREQ_6(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_6_SHIFT)) & DMA_EARS_EDREQ_6_MASK)
#define DMA_EARS_EDREQ_7_MASK                    (0x80U)
#define DMA_EARS_EDREQ_7_SHIFT                   (7U)
#define DMA_EARS_EDREQ_7(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_7_SHIFT)) & DMA_EARS_EDREQ_7_MASK)
#define DMA_EARS_EDREQ_8_MASK                    (0x100U)
#define DMA_EARS_EDREQ_8_SHIFT                   (8U)
#define DMA_EARS_EDREQ_8(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_8_SHIFT)) & DMA_EARS_EDREQ_8_MASK)
#define DMA_EARS_EDREQ_9_MASK                    (0x200U)
#define DMA_EARS_EDREQ_9_SHIFT                   (9U)
#define DMA_EARS_EDREQ_9(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_9_SHIFT)) & DMA_EARS_EDREQ_9_MASK)
#define DMA_EARS_EDREQ_10_MASK                   (0x400U)
#define DMA_EARS_EDREQ_10_SHIFT                  (10U)
#define DMA_EARS_EDREQ_10(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_10_SHIFT)) & DMA_EARS_EDREQ_10_MASK)
#define DMA_EARS_EDREQ_11_MASK                   (0x800U)
#define DMA_EARS_EDREQ_11_SHIFT                  (11U)
#define DMA_EARS_EDREQ_11(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_11_SHIFT)) & DMA_EARS_EDREQ_11_MASK)
#define DMA_EARS_EDREQ_12_MASK                   (0x1000U)
#define DMA_EARS_EDREQ_12_SHIFT                  (12U)
#define DMA_EARS_EDREQ_12(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_12_SHIFT)) & DMA_EARS_EDREQ_12_MASK)
#define DMA_EARS_EDREQ_13_MASK                   (0x2000U)
#define DMA_EARS_EDREQ_13_SHIFT                  (13U)
#define DMA_EARS_EDREQ_13(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_13_SHIFT)) & DMA_EARS_EDREQ_13_MASK)
#define DMA_EARS_EDREQ_14_MASK                   (0x4000U)
#define DMA_EARS_EDREQ_14_SHIFT                  (14U)
#define DMA_EARS_EDREQ_14(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_14_SHIFT)) & DMA_EARS_EDREQ_14_MASK)
#define DMA_EARS_EDREQ_15_MASK                   (0x8000U)
#define DMA_EARS_EDREQ_15_SHIFT                  (15U)
#define DMA_EARS_EDREQ_15(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_EARS_EDREQ_15_SHIFT)) & DMA_EARS_EDREQ_15_MASK)

/*! @name DCHPRI3 - Channel n Priority Register */
#define DMA_DCHPRI3_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI3_CHPRI_SHIFT                  (0U)
#define DMA_DCHPRI3_CHPRI(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI3_CHPRI_SHIFT)) & DMA_DCHPRI3_CHPRI_MASK)
#define DMA_DCHPRI3_DPA_MASK                     (0x40U)
#define DMA_DCHPRI3_DPA_SHIFT                    (6U)
#define DMA_DCHPRI3_DPA(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI3_DPA_SHIFT)) & DMA_DCHPRI3_DPA_MASK)
#define DMA_DCHPRI3_ECP_MASK                     (0x80U)
#define DMA_DCHPRI3_ECP_SHIFT                    (7U)
#define DMA_DCHPRI3_ECP(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI3_ECP_SHIFT)) & DMA_DCHPRI3_ECP_MASK)

/*! @name DCHPRI2 - Channel n Priority Register */
#define DMA_DCHPRI2_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI2_CHPRI_SHIFT                  (0U)
#define DMA_DCHPRI2_CHPRI(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI2_CHPRI_SHIFT)) & DMA_DCHPRI2_CHPRI_MASK)
#define DMA_DCHPRI2_DPA_MASK                     (0x40U)
#define DMA_DCHPRI2_DPA_SHIFT                    (6U)
#define DMA_DCHPRI2_DPA(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI2_DPA_SHIFT)) & DMA_DCHPRI2_DPA_MASK)
#define DMA_DCHPRI2_ECP_MASK                     (0x80U)
#define DMA_DCHPRI2_ECP_SHIFT                    (7U)
#define DMA_DCHPRI2_ECP(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI2_ECP_SHIFT)) & DMA_DCHPRI2_ECP_MASK)

/*! @name DCHPRI1 - Channel n Priority Register */
#define DMA_DCHPRI1_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI1_CHPRI_SHIFT                  (0U)
#define DMA_DCHPRI1_CHPRI(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI1_CHPRI_SHIFT)) & DMA_DCHPRI1_CHPRI_MASK)
#define DMA_DCHPRI1_DPA_MASK                     (0x40U)
#define DMA_DCHPRI1_DPA_SHIFT                    (6U)
#define DMA_DCHPRI1_DPA(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI1_DPA_SHIFT)) & DMA_DCHPRI1_DPA_MASK)
#define DMA_DCHPRI1_ECP_MASK                     (0x80U)
#define DMA_DCHPRI1_ECP_SHIFT                    (7U)
#define DMA_DCHPRI1_ECP(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI1_ECP_SHIFT)) & DMA_DCHPRI1_ECP_MASK)

/*! @name DCHPRI0 - Channel n Priority Register */
#define DMA_DCHPRI0_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI0_CHPRI_SHIFT                  (0U)
#define DMA_DCHPRI0_CHPRI(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI0_CHPRI_SHIFT)) & DMA_DCHPRI0_CHPRI_MASK)
#define DMA_DCHPRI0_DPA_MASK                     (0x40U)
#define DMA_DCHPRI0_DPA_SHIFT                    (6U)
#define DMA_DCHPRI0_DPA(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI0_DPA_SHIFT)) & DMA_DCHPRI0_DPA_MASK)
#define DMA_DCHPRI0_ECP_MASK                     (0x80U)
#define DMA_DCHPRI0_ECP_SHIFT                    (7U)
#define DMA_DCHPRI0_ECP(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI0_ECP_SHIFT)) & DMA_DCHPRI0_ECP_MASK)

/*! @name DCHPRI7 - Channel n Priority Register */
#define DMA_DCHPRI7_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI7_CHPRI_SHIFT                  (0U)
#define DMA_DCHPRI7_CHPRI(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI7_CHPRI_SHIFT)) & DMA_DCHPRI7_CHPRI_MASK)
#define DMA_DCHPRI7_DPA_MASK                     (0x40U)
#define DMA_DCHPRI7_DPA_SHIFT                    (6U)
#define DMA_DCHPRI7_DPA(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI7_DPA_SHIFT)) & DMA_DCHPRI7_DPA_MASK)
#define DMA_DCHPRI7_ECP_MASK                     (0x80U)
#define DMA_DCHPRI7_ECP_SHIFT                    (7U)
#define DMA_DCHPRI7_ECP(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI7_ECP_SHIFT)) & DMA_DCHPRI7_ECP_MASK)

/*! @name DCHPRI6 - Channel n Priority Register */
#define DMA_DCHPRI6_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI6_CHPRI_SHIFT                  (0U)
#define DMA_DCHPRI6_CHPRI(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI6_CHPRI_SHIFT)) & DMA_DCHPRI6_CHPRI_MASK)
#define DMA_DCHPRI6_DPA_MASK                     (0x40U)
#define DMA_DCHPRI6_DPA_SHIFT                    (6U)
#define DMA_DCHPRI6_DPA(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI6_DPA_SHIFT)) & DMA_DCHPRI6_DPA_MASK)
#define DMA_DCHPRI6_ECP_MASK                     (0x80U)
#define DMA_DCHPRI6_ECP_SHIFT                    (7U)
#define DMA_DCHPRI6_ECP(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI6_ECP_SHIFT)) & DMA_DCHPRI6_ECP_MASK)

/*! @name DCHPRI5 - Channel n Priority Register */
#define DMA_DCHPRI5_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI5_CHPRI_SHIFT                  (0U)
#define DMA_DCHPRI5_CHPRI(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI5_CHPRI_SHIFT)) & DMA_DCHPRI5_CHPRI_MASK)
#define DMA_DCHPRI5_DPA_MASK                     (0x40U)
#define DMA_DCHPRI5_DPA_SHIFT                    (6U)
#define DMA_DCHPRI5_DPA(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI5_DPA_SHIFT)) & DMA_DCHPRI5_DPA_MASK)
#define DMA_DCHPRI5_ECP_MASK                     (0x80U)
#define DMA_DCHPRI5_ECP_SHIFT                    (7U)
#define DMA_DCHPRI5_ECP(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI5_ECP_SHIFT)) & DMA_DCHPRI5_ECP_MASK)

/*! @name DCHPRI4 - Channel n Priority Register */
#define DMA_DCHPRI4_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI4_CHPRI_SHIFT                  (0U)
#define DMA_DCHPRI4_CHPRI(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI4_CHPRI_SHIFT)) & DMA_DCHPRI4_CHPRI_MASK)
#define DMA_DCHPRI4_DPA_MASK                     (0x40U)
#define DMA_DCHPRI4_DPA_SHIFT                    (6U)
#define DMA_DCHPRI4_DPA(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI4_DPA_SHIFT)) & DMA_DCHPRI4_DPA_MASK)
#define DMA_DCHPRI4_ECP_MASK                     (0x80U)
#define DMA_DCHPRI4_ECP_SHIFT                    (7U)
#define DMA_DCHPRI4_ECP(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI4_ECP_SHIFT)) & DMA_DCHPRI4_ECP_MASK)

/*! @name DCHPRI11 - Channel n Priority Register */
#define DMA_DCHPRI11_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI11_CHPRI_SHIFT                 (0U)
#define DMA_DCHPRI11_CHPRI(x)                    (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI11_CHPRI_SHIFT)) & DMA_DCHPRI11_CHPRI_MASK)
#define DMA_DCHPRI11_DPA_MASK                    (0x40U)
#define DMA_DCHPRI11_DPA_SHIFT                   (6U)
#define DMA_DCHPRI11_DPA(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI11_DPA_SHIFT)) & DMA_DCHPRI11_DPA_MASK)
#define DMA_DCHPRI11_ECP_MASK                    (0x80U)
#define DMA_DCHPRI11_ECP_SHIFT                   (7U)
#define DMA_DCHPRI11_ECP(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI11_ECP_SHIFT)) & DMA_DCHPRI11_ECP_MASK)

/*! @name DCHPRI10 - Channel n Priority Register */
#define DMA_DCHPRI10_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI10_CHPRI_SHIFT                 (0U)
#define DMA_DCHPRI10_CHPRI(x)                    (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI10_CHPRI_SHIFT)) & DMA_DCHPRI10_CHPRI_MASK)
#define DMA_DCHPRI10_DPA_MASK                    (0x40U)
#define DMA_DCHPRI10_DPA_SHIFT                   (6U)
#define DMA_DCHPRI10_DPA(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI10_DPA_SHIFT)) & DMA_DCHPRI10_DPA_MASK)
#define DMA_DCHPRI10_ECP_MASK                    (0x80U)
#define DMA_DCHPRI10_ECP_SHIFT                   (7U)
#define DMA_DCHPRI10_ECP(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI10_ECP_SHIFT)) & DMA_DCHPRI10_ECP_MASK)

/*! @name DCHPRI9 - Channel n Priority Register */
#define DMA_DCHPRI9_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI9_CHPRI_SHIFT                  (0U)
#define DMA_DCHPRI9_CHPRI(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI9_CHPRI_SHIFT)) & DMA_DCHPRI9_CHPRI_MASK)
#define DMA_DCHPRI9_DPA_MASK                     (0x40U)
#define DMA_DCHPRI9_DPA_SHIFT                    (6U)
#define DMA_DCHPRI9_DPA(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI9_DPA_SHIFT)) & DMA_DCHPRI9_DPA_MASK)
#define DMA_DCHPRI9_ECP_MASK                     (0x80U)
#define DMA_DCHPRI9_ECP_SHIFT                    (7U)
#define DMA_DCHPRI9_ECP(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI9_ECP_SHIFT)) & DMA_DCHPRI9_ECP_MASK)

/*! @name DCHPRI8 - Channel n Priority Register */
#define DMA_DCHPRI8_CHPRI_MASK                   (0xFU)
#define DMA_DCHPRI8_CHPRI_SHIFT                  (0U)
#define DMA_DCHPRI8_CHPRI(x)                     (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI8_CHPRI_SHIFT)) & DMA_DCHPRI8_CHPRI_MASK)
#define DMA_DCHPRI8_DPA_MASK                     (0x40U)
#define DMA_DCHPRI8_DPA_SHIFT                    (6U)
#define DMA_DCHPRI8_DPA(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI8_DPA_SHIFT)) & DMA_DCHPRI8_DPA_MASK)
#define DMA_DCHPRI8_ECP_MASK                     (0x80U)
#define DMA_DCHPRI8_ECP_SHIFT                    (7U)
#define DMA_DCHPRI8_ECP(x)                       (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI8_ECP_SHIFT)) & DMA_DCHPRI8_ECP_MASK)

/*! @name DCHPRI15 - Channel n Priority Register */
#define DMA_DCHPRI15_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI15_CHPRI_SHIFT                 (0U)
#define DMA_DCHPRI15_CHPRI(x)                    (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI15_CHPRI_SHIFT)) & DMA_DCHPRI15_CHPRI_MASK)
#define DMA_DCHPRI15_DPA_MASK                    (0x40U)
#define DMA_DCHPRI15_DPA_SHIFT                   (6U)
#define DMA_DCHPRI15_DPA(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI15_DPA_SHIFT)) & DMA_DCHPRI15_DPA_MASK)
#define DMA_DCHPRI15_ECP_MASK                    (0x80U)
#define DMA_DCHPRI15_ECP_SHIFT                   (7U)
#define DMA_DCHPRI15_ECP(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI15_ECP_SHIFT)) & DMA_DCHPRI15_ECP_MASK)

/*! @name DCHPRI14 - Channel n Priority Register */
#define DMA_DCHPRI14_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI14_CHPRI_SHIFT                 (0U)
#define DMA_DCHPRI14_CHPRI(x)                    (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI14_CHPRI_SHIFT)) & DMA_DCHPRI14_CHPRI_MASK)
#define DMA_DCHPRI14_DPA_MASK                    (0x40U)
#define DMA_DCHPRI14_DPA_SHIFT                   (6U)
#define DMA_DCHPRI14_DPA(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI14_DPA_SHIFT)) & DMA_DCHPRI14_DPA_MASK)
#define DMA_DCHPRI14_ECP_MASK                    (0x80U)
#define DMA_DCHPRI14_ECP_SHIFT                   (7U)
#define DMA_DCHPRI14_ECP(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI14_ECP_SHIFT)) & DMA_DCHPRI14_ECP_MASK)

/*! @name DCHPRI13 - Channel n Priority Register */
#define DMA_DCHPRI13_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI13_CHPRI_SHIFT                 (0U)
#define DMA_DCHPRI13_CHPRI(x)                    (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI13_CHPRI_SHIFT)) & DMA_DCHPRI13_CHPRI_MASK)
#define DMA_DCHPRI13_DPA_MASK                    (0x40U)
#define DMA_DCHPRI13_DPA_SHIFT                   (6U)
#define DMA_DCHPRI13_DPA(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI13_DPA_SHIFT)) & DMA_DCHPRI13_DPA_MASK)
#define DMA_DCHPRI13_ECP_MASK                    (0x80U)
#define DMA_DCHPRI13_ECP_SHIFT                   (7U)
#define DMA_DCHPRI13_ECP(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI13_ECP_SHIFT)) & DMA_DCHPRI13_ECP_MASK)

/*! @name DCHPRI12 - Channel n Priority Register */
#define DMA_DCHPRI12_CHPRI_MASK                  (0xFU)
#define DMA_DCHPRI12_CHPRI_SHIFT                 (0U)
#define DMA_DCHPRI12_CHPRI(x)                    (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI12_CHPRI_SHIFT)) & DMA_DCHPRI12_CHPRI_MASK)
#define DMA_DCHPRI12_DPA_MASK                    (0x40U)
#define DMA_DCHPRI12_DPA_SHIFT                   (6U)
#define DMA_DCHPRI12_DPA(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI12_DPA_SHIFT)) & DMA_DCHPRI12_DPA_MASK)
#define DMA_DCHPRI12_ECP_MASK                    (0x80U)
#define DMA_DCHPRI12_ECP_SHIFT                   (7U)
#define DMA_DCHPRI12_ECP(x)                      (((uint8_t)(((uint8_t)(x)) << DMA_DCHPRI12_ECP_SHIFT)) & DMA_DCHPRI12_ECP_MASK)

/*! @name SADDR - TCD Source Address */
#define DMA_SADDR_SADDR_MASK                     (0xFFFFFFFFU)
#define DMA_SADDR_SADDR_SHIFT                    (0U)
#define DMA_SADDR_SADDR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_SADDR_SADDR_SHIFT)) & DMA_SADDR_SADDR_MASK)

/* The count of DMA_SADDR */
#define DMA_SADDR_COUNT                          (16U)

/*! @name SOFF - TCD Signed Source Address Offset */
#define DMA_SOFF_SOFF_MASK                       (0xFFFFU)
#define DMA_SOFF_SOFF_SHIFT                      (0U)
#define DMA_SOFF_SOFF(x)                         (((uint16_t)(((uint16_t)(x)) << DMA_SOFF_SOFF_SHIFT)) & DMA_SOFF_SOFF_MASK)

/* The count of DMA_SOFF */
#define DMA_SOFF_COUNT                           (16U)

/*! @name ATTR - TCD Transfer Attributes */
#define DMA_ATTR_DSIZE_MASK                      (0x7U)
#define DMA_ATTR_DSIZE_SHIFT                     (0U)
#define DMA_ATTR_DSIZE(x)                        (((uint16_t)(((uint16_t)(x)) << DMA_ATTR_DSIZE_SHIFT)) & DMA_ATTR_DSIZE_MASK)
#define DMA_ATTR_DMOD_MASK                       (0xF8U)
#define DMA_ATTR_DMOD_SHIFT                      (3U)
#define DMA_ATTR_DMOD(x)                         (((uint16_t)(((uint16_t)(x)) << DMA_ATTR_DMOD_SHIFT)) & DMA_ATTR_DMOD_MASK)
#define DMA_ATTR_SSIZE_MASK                      (0x700U)
#define DMA_ATTR_SSIZE_SHIFT                     (8U)
#define DMA_ATTR_SSIZE(x)                        (((uint16_t)(((uint16_t)(x)) << DMA_ATTR_SSIZE_SHIFT)) & DMA_ATTR_SSIZE_MASK)
#define DMA_ATTR_SMOD_MASK                       (0xF800U)
#define DMA_ATTR_SMOD_SHIFT                      (11U)
#define DMA_ATTR_SMOD(x)                         (((uint16_t)(((uint16_t)(x)) << DMA_ATTR_SMOD_SHIFT)) & DMA_ATTR_SMOD_MASK)

/* The count of DMA_ATTR */
#define DMA_ATTR_COUNT                           (16U)

/*! @name NBYTES_MLNO - TCD Minor Byte Count (Minor Loop Mapping Disabled) */
#define DMA_NBYTES_MLNO_NBYTES_MASK              (0xFFFFFFFFU)
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             (0U)
#define DMA_NBYTES_MLNO_NBYTES(x)                (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLNO_NBYTES_SHIFT)) & DMA_NBYTES_MLNO_NBYTES_MASK)

/* The count of DMA_NBYTES_MLNO */
#define DMA_NBYTES_MLNO_COUNT                    (16U)

/*! @name NBYTES_MLOFFNO - TCD Signed Minor Loop Offset (Minor Loop Mapping Enabled and Offset Disabled) */
#define DMA_NBYTES_MLOFFNO_NBYTES_MASK           (0x3FFFFFFFU)
#define DMA_NBYTES_MLOFFNO_NBYTES_SHIFT          (0U)
#define DMA_NBYTES_MLOFFNO_NBYTES(x)             (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_NBYTES_MLOFFNO_NBYTES_MASK)
#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            (0x40000000U)
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           (30U)
#define DMA_NBYTES_MLOFFNO_DMLOE(x)              (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_NBYTES_MLOFFNO_DMLOE_MASK)
#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            (0x80000000U)
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           (31U)
#define DMA_NBYTES_MLOFFNO_SMLOE(x)              (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_NBYTES_MLOFFNO_SMLOE_MASK)

/* The count of DMA_NBYTES_MLOFFNO */
#define DMA_NBYTES_MLOFFNO_COUNT                 (16U)

/*! @name NBYTES_MLOFFYES - TCD Signed Minor Loop Offset (Minor Loop Mapping and Offset Enabled) */
#define DMA_NBYTES_MLOFFYES_NBYTES_MASK          (0x3FFU)
#define DMA_NBYTES_MLOFFYES_NBYTES_SHIFT         (0U)
#define DMA_NBYTES_MLOFFYES_NBYTES(x)            (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_NBYTES_MLOFFYES_NBYTES_MASK)
#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           (0x3FFFFC00U)
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          (10U)
#define DMA_NBYTES_MLOFFYES_MLOFF(x)             (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_NBYTES_MLOFFYES_MLOFF_MASK)
#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           (0x40000000U)
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          (30U)
#define DMA_NBYTES_MLOFFYES_DMLOE(x)             (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_NBYTES_MLOFFYES_DMLOE_MASK)
#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           (0x80000000U)
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          (31U)
#define DMA_NBYTES_MLOFFYES_SMLOE(x)             (((uint32_t)(((uint32_t)(x)) << DMA_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_NBYTES_MLOFFYES_SMLOE_MASK)

/* The count of DMA_NBYTES_MLOFFYES */
#define DMA_NBYTES_MLOFFYES_COUNT                (16U)

/*! @name SLAST - TCD Last Source Address Adjustment */
#define DMA_SLAST_SLAST_MASK                     (0xFFFFFFFFU)
#define DMA_SLAST_SLAST_SHIFT                    (0U)
#define DMA_SLAST_SLAST(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_SLAST_SLAST_SHIFT)) & DMA_SLAST_SLAST_MASK)

/* The count of DMA_SLAST */
#define DMA_SLAST_COUNT                          (16U)

/*! @name DADDR - TCD Destination Address */
#define DMA_DADDR_DADDR_MASK                     (0xFFFFFFFFU)
#define DMA_DADDR_DADDR_SHIFT                    (0U)
#define DMA_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DADDR_DADDR_SHIFT)) & DMA_DADDR_DADDR_MASK)

/* The count of DMA_DADDR */
#define DMA_DADDR_COUNT                          (16U)

/*! @name DOFF - TCD Signed Destination Address Offset */
#define DMA_DOFF_DOFF_MASK                       (0xFFFFU)
#define DMA_DOFF_DOFF_SHIFT                      (0U)
#define DMA_DOFF_DOFF(x)                         (((uint16_t)(((uint16_t)(x)) << DMA_DOFF_DOFF_SHIFT)) & DMA_DOFF_DOFF_MASK)

/* The count of DMA_DOFF */
#define DMA_DOFF_COUNT                           (16U)

/*! @name CITER_ELINKNO - TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
#define DMA_CITER_ELINKNO_CITER_MASK             (0x7FFFU)
#define DMA_CITER_ELINKNO_CITER_SHIFT            (0U)
#define DMA_CITER_ELINKNO_CITER(x)               (((uint16_t)(((uint16_t)(x)) << DMA_CITER_ELINKNO_CITER_SHIFT)) & DMA_CITER_ELINKNO_CITER_MASK)
#define DMA_CITER_ELINKNO_ELINK_MASK             (0x8000U)
#define DMA_CITER_ELINKNO_ELINK_SHIFT            (15U)
#define DMA_CITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x)) << DMA_CITER_ELINKNO_ELINK_SHIFT)) & DMA_CITER_ELINKNO_ELINK_MASK)

/* The count of DMA_CITER_ELINKNO */
#define DMA_CITER_ELINKNO_COUNT                  (16U)

/*! @name CITER_ELINKYES - TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
#define DMA_CITER_ELINKYES_CITER_MASK            (0x1FFU)
#define DMA_CITER_ELINKYES_CITER_SHIFT           (0U)
#define DMA_CITER_ELINKYES_CITER(x)              (((uint16_t)(((uint16_t)(x)) << DMA_CITER_ELINKYES_CITER_SHIFT)) & DMA_CITER_ELINKYES_CITER_MASK)
#define DMA_CITER_ELINKYES_LINKCH_MASK           (0x1E00U)
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          (9U)
#define DMA_CITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_CITER_ELINKYES_LINKCH_MASK)
#define DMA_CITER_ELINKYES_ELINK_MASK            (0x8000U)
#define DMA_CITER_ELINKYES_ELINK_SHIFT           (15U)
#define DMA_CITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_CITER_ELINKYES_ELINK_SHIFT)) & DMA_CITER_ELINKYES_ELINK_MASK)

/* The count of DMA_CITER_ELINKYES */
#define DMA_CITER_ELINKYES_COUNT                 (16U)

/*! @name DLAST_SGA - TCD Last Destination Address Adjustment/Scatter Gather Address */
#define DMA_DLAST_SGA_DLASTSGA_MASK              (0xFFFFFFFFU)
#define DMA_DLAST_SGA_DLASTSGA_SHIFT             (0U)
#define DMA_DLAST_SGA_DLASTSGA(x)                (((uint32_t)(((uint32_t)(x)) << DMA_DLAST_SGA_DLASTSGA_SHIFT)) & DMA_DLAST_SGA_DLASTSGA_MASK)

/* The count of DMA_DLAST_SGA */
#define DMA_DLAST_SGA_COUNT                      (16U)

/*! @name CSR - TCD Control and Status */
#define DMA_CSR_START_MASK                       (0x1U)
#define DMA_CSR_START_SHIFT                      (0U)
#define DMA_CSR_START(x)                         (((uint16_t)(((uint16_t)(x)) << DMA_CSR_START_SHIFT)) & DMA_CSR_START_MASK)
#define DMA_CSR_INTMAJOR_MASK                    (0x2U)
#define DMA_CSR_INTMAJOR_SHIFT                   (1U)
#define DMA_CSR_INTMAJOR(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_CSR_INTMAJOR_SHIFT)) & DMA_CSR_INTMAJOR_MASK)
#define DMA_CSR_INTHALF_MASK                     (0x4U)
#define DMA_CSR_INTHALF_SHIFT                    (2U)
#define DMA_CSR_INTHALF(x)                       (((uint16_t)(((uint16_t)(x)) << DMA_CSR_INTHALF_SHIFT)) & DMA_CSR_INTHALF_MASK)
#define DMA_CSR_DREQ_MASK                        (0x8U)
#define DMA_CSR_DREQ_SHIFT                       (3U)
#define DMA_CSR_DREQ(x)                          (((uint16_t)(((uint16_t)(x)) << DMA_CSR_DREQ_SHIFT)) & DMA_CSR_DREQ_MASK)
#define DMA_CSR_ESG_MASK                         (0x10U)
#define DMA_CSR_ESG_SHIFT                        (4U)
#define DMA_CSR_ESG(x)                           (((uint16_t)(((uint16_t)(x)) << DMA_CSR_ESG_SHIFT)) & DMA_CSR_ESG_MASK)
#define DMA_CSR_MAJORELINK_MASK                  (0x20U)
#define DMA_CSR_MAJORELINK_SHIFT                 (5U)
#define DMA_CSR_MAJORELINK(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_CSR_MAJORELINK_SHIFT)) & DMA_CSR_MAJORELINK_MASK)
#define DMA_CSR_ACTIVE_MASK                      (0x40U)
#define DMA_CSR_ACTIVE_SHIFT                     (6U)
#define DMA_CSR_ACTIVE(x)                        (((uint16_t)(((uint16_t)(x)) << DMA_CSR_ACTIVE_SHIFT)) & DMA_CSR_ACTIVE_MASK)
#define DMA_CSR_DONE_MASK                        (0x80U)
#define DMA_CSR_DONE_SHIFT                       (7U)
#define DMA_CSR_DONE(x)                          (((uint16_t)(((uint16_t)(x)) << DMA_CSR_DONE_SHIFT)) & DMA_CSR_DONE_MASK)
#define DMA_CSR_MAJORLINKCH_MASK                 (0xF00U)
#define DMA_CSR_MAJORLINKCH_SHIFT                (8U)
#define DMA_CSR_MAJORLINKCH(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_CSR_MAJORLINKCH_SHIFT)) & DMA_CSR_MAJORLINKCH_MASK)
#define DMA_CSR_BWC_MASK                         (0xC000U)
#define DMA_CSR_BWC_SHIFT                        (14U)
#define DMA_CSR_BWC(x)                           (((uint16_t)(((uint16_t)(x)) << DMA_CSR_BWC_SHIFT)) & DMA_CSR_BWC_MASK)

/* The count of DMA_CSR */
#define DMA_CSR_COUNT                            (16U)

/*! @name BITER_ELINKNO - TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
#define DMA_BITER_ELINKNO_BITER_MASK             (0x7FFFU)
#define DMA_BITER_ELINKNO_BITER_SHIFT            (0U)
#define DMA_BITER_ELINKNO_BITER(x)               (((uint16_t)(((uint16_t)(x)) << DMA_BITER_ELINKNO_BITER_SHIFT)) & DMA_BITER_ELINKNO_BITER_MASK)
#define DMA_BITER_ELINKNO_ELINK_MASK             (0x8000U)
#define DMA_BITER_ELINKNO_ELINK_SHIFT            (15U)
#define DMA_BITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x)) << DMA_BITER_ELINKNO_ELINK_SHIFT)) & DMA_BITER_ELINKNO_ELINK_MASK)

/* The count of DMA_BITER_ELINKNO */
#define DMA_BITER_ELINKNO_COUNT                  (16U)

/*! @name BITER_ELINKYES - TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
#define DMA_BITER_ELINKYES_BITER_MASK            (0x1FFU)
#define DMA_BITER_ELINKYES_BITER_SHIFT           (0U)
#define DMA_BITER_ELINKYES_BITER(x)              (((uint16_t)(((uint16_t)(x)) << DMA_BITER_ELINKYES_BITER_SHIFT)) & DMA_BITER_ELINKYES_BITER_MASK)
#define DMA_BITER_ELINKYES_LINKCH_MASK           (0x1E00U)
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          (9U)
#define DMA_BITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x)) << DMA_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_BITER_ELINKYES_LINKCH_MASK)
#define DMA_BITER_ELINKYES_ELINK_MASK            (0x8000U)
#define DMA_BITER_ELINKYES_ELINK_SHIFT           (15U)
#define DMA_BITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA_BITER_ELINKYES_ELINK_SHIFT)) & DMA_BITER_ELINKYES_ELINK_MASK)

/* The count of DMA_BITER_ELINKYES */
#define DMA_BITER_ELINKYES_COUNT                 (16U)


/*!
 * @}
 */ /* end of group DMA_Register_Masks */


/* DMA - Peripheral instance base addresses */
/** Peripheral DMA base address */
#define DMA_BASE                                 (0x40008000u)
/** Peripheral DMA base pointer */
#define DMA0                                     ((DMA_Type *)DMA_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_CHN_IRQS                             { { DMA0_IRQn, DMA1_IRQn, DMA2_IRQn, DMA3_IRQn, DMA4_IRQn, DMA5_IRQn, DMA6_IRQn, DMA7_IRQn, DMA8_IRQn, DMA9_IRQn, DMA10_IRQn, DMA11_IRQn, DMA12_IRQn, DMA13_IRQn, DMA14_IRQn, DMA15_IRQn } }
#define DMA_ERROR_IRQS                           { DMA_Error_IRQn }

/*!
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Peripheral_Access_Layer DMAMUX Peripheral Access Layer
 * @{
 */

/** DMAMUX - Register Layout Typedef */
typedef struct {
  __IO uint8_t CHCFG[16];                          /**< Channel Configuration register, array offset: 0x0, array step: 0x1 */
} DMAMUX_Type;

/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/*! @name CHCFG - Channel Configuration register */
#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FU)
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCFG_SOURCE_SHIFT)) & DMAMUX_CHCFG_SOURCE_MASK)
#define DMAMUX_CHCFG_TRIG_MASK                   (0x40U)
#define DMAMUX_CHCFG_TRIG_SHIFT                  (6U)
#define DMAMUX_CHCFG_TRIG(x)                     (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCFG_TRIG_SHIFT)) & DMAMUX_CHCFG_TRIG_MASK)
#define DMAMUX_CHCFG_ENBL_MASK                   (0x80U)
#define DMAMUX_CHCFG_ENBL_SHIFT                  (7U)
#define DMAMUX_CHCFG_ENBL(x)                     (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCFG_ENBL_SHIFT)) & DMAMUX_CHCFG_ENBL_MASK)

/* The count of DMAMUX_CHCFG */
#define DMAMUX_CHCFG_COUNT                       (16U)


/*!
 * @}
 */ /* end of group DMAMUX_Register_Masks */


/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX base address */
#define DMAMUX_BASE                              (0x40021000u)
/** Peripheral DMAMUX base pointer */
#define DMAMUX                                   ((DMAMUX_Type *)DMAMUX_BASE)
/** Array initializer of DMAMUX peripheral base addresses */
#define DMAMUX_BASE_ADDRS                        { DMAMUX_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { DMAMUX }

/*!
 * @}
 */ /* end of group DMAMUX_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- EWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Peripheral_Access_Layer EWM Peripheral Access Layer
 * @{
 */

/** EWM - Register Layout Typedef */
typedef struct {
  __IO uint8_t CTRL;                               /**< Control Register, offset: 0x0 */
  __O  uint8_t SERV;                               /**< Service Register, offset: 0x1 */
  __IO uint8_t CMPL;                               /**< Compare Low Register, offset: 0x2 */
  __IO uint8_t CMPH;                               /**< Compare High Register, offset: 0x3 */
       uint8_t RESERVED_0[1];
  __IO uint8_t CLKPRESCALER;                       /**< Clock Prescaler Register, offset: 0x5 */
} EWM_Type;

/* ----------------------------------------------------------------------------
   -- EWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Register_Masks EWM Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
#define EWM_CTRL_EWMEN_MASK                      (0x1U)
#define EWM_CTRL_EWMEN_SHIFT                     (0U)
#define EWM_CTRL_EWMEN(x)                        (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_EWMEN_SHIFT)) & EWM_CTRL_EWMEN_MASK)
#define EWM_CTRL_ASSIN_MASK                      (0x2U)
#define EWM_CTRL_ASSIN_SHIFT                     (1U)
#define EWM_CTRL_ASSIN(x)                        (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_ASSIN_SHIFT)) & EWM_CTRL_ASSIN_MASK)
#define EWM_CTRL_INEN_MASK                       (0x4U)
#define EWM_CTRL_INEN_SHIFT                      (2U)
#define EWM_CTRL_INEN(x)                         (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_INEN_SHIFT)) & EWM_CTRL_INEN_MASK)
#define EWM_CTRL_INTEN_MASK                      (0x8U)
#define EWM_CTRL_INTEN_SHIFT                     (3U)
#define EWM_CTRL_INTEN(x)                        (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_INTEN_SHIFT)) & EWM_CTRL_INTEN_MASK)

/*! @name SERV - Service Register */
#define EWM_SERV_SERVICE_MASK                    (0xFFU)
#define EWM_SERV_SERVICE_SHIFT                   (0U)
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x)) << EWM_SERV_SERVICE_SHIFT)) & EWM_SERV_SERVICE_MASK)

/*! @name CMPL - Compare Low Register */
#define EWM_CMPL_COMPAREL_MASK                   (0xFFU)
#define EWM_CMPL_COMPAREL_SHIFT                  (0U)
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x)) << EWM_CMPL_COMPAREL_SHIFT)) & EWM_CMPL_COMPAREL_MASK)

/*! @name CMPH - Compare High Register */
#define EWM_CMPH_COMPAREH_MASK                   (0xFFU)
#define EWM_CMPH_COMPAREH_SHIFT                  (0U)
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x)) << EWM_CMPH_COMPAREH_SHIFT)) & EWM_CMPH_COMPAREH_MASK)

/*! @name CLKPRESCALER - Clock Prescaler Register */
#define EWM_CLKPRESCALER_CLK_DIV_MASK            (0xFFU)
#define EWM_CLKPRESCALER_CLK_DIV_SHIFT           (0U)
#define EWM_CLKPRESCALER_CLK_DIV(x)              (((uint8_t)(((uint8_t)(x)) << EWM_CLKPRESCALER_CLK_DIV_SHIFT)) & EWM_CLKPRESCALER_CLK_DIV_MASK)


/*!
 * @}
 */ /* end of group EWM_Register_Masks */


/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base address */
#define EWM_BASE                                 (0x40061000u)
/** Peripheral EWM base pointer */
#define EWM                                      ((EWM_Type *)EWM_BASE)
/** Array initializer of EWM peripheral base addresses */
#define EWM_BASE_ADDRS                           { EWM_BASE }
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASE_PTRS                            { EWM }
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { WDOG_EWM_IRQn }

/*!
 * @}
 */ /* end of group EWM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FLEXIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXIO_Peripheral_Access_Layer FLEXIO Peripheral Access Layer
 * @{
 */

/** FLEXIO - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t CTRL;                              /**< FlexIO Control Register, offset: 0x8 */
  __I  uint32_t PIN;                               /**< Pin State Register, offset: 0xC */
  __IO uint32_t SHIFTSTAT;                         /**< Shifter Status Register, offset: 0x10 */
  __IO uint32_t SHIFTERR;                          /**< Shifter Error Register, offset: 0x14 */
  __IO uint32_t TIMSTAT;                           /**< Timer Status Register, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SHIFTSIEN;                         /**< Shifter Status Interrupt Enable, offset: 0x20 */
  __IO uint32_t SHIFTEIEN;                         /**< Shifter Error Interrupt Enable, offset: 0x24 */
  __IO uint32_t TIMIEN;                            /**< Timer Interrupt Enable Register, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SHIFTSDEN;                         /**< Shifter Status DMA Enable, offset: 0x30 */
       uint8_t RESERVED_2[76];
  __IO uint32_t SHIFTCTL[4];                       /**< Shifter Control N Register, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_3[112];
  __IO uint32_t SHIFTCFG[4];                       /**< Shifter Configuration N Register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_4[240];
  __IO uint32_t SHIFTBUF[4];                       /**< Shifter Buffer N Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_5[112];
  __IO uint32_t SHIFTBUFBIS[4];                    /**< Shifter Buffer N Bit Swapped Register, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_6[112];
  __IO uint32_t SHIFTBUFBYS[4];                    /**< Shifter Buffer N Byte Swapped Register, array offset: 0x300, array step: 0x4 */
       uint8_t RESERVED_7[112];
  __IO uint32_t SHIFTBUFBBS[4];                    /**< Shifter Buffer N Bit Byte Swapped Register, array offset: 0x380, array step: 0x4 */
       uint8_t RESERVED_8[112];
  __IO uint32_t TIMCTL[4];                         /**< Timer Control N Register, array offset: 0x400, array step: 0x4 */
       uint8_t RESERVED_9[112];
  __IO uint32_t TIMCFG[4];                         /**< Timer Configuration N Register, array offset: 0x480, array step: 0x4 */
       uint8_t RESERVED_10[112];
  __IO uint32_t TIMCMP[4];                         /**< Timer Compare N Register, array offset: 0x500, array step: 0x4 */
} FLEXIO_Type;

/* ----------------------------------------------------------------------------
   -- FLEXIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXIO_Register_Masks FLEXIO Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
#define FLEXIO_VERID_FEATURE_MASK                (0xFFFFU)
#define FLEXIO_VERID_FEATURE_SHIFT               (0U)
#define FLEXIO_VERID_FEATURE(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_VERID_FEATURE_SHIFT)) & FLEXIO_VERID_FEATURE_MASK)
#define FLEXIO_VERID_MINOR_MASK                  (0xFF0000U)
#define FLEXIO_VERID_MINOR_SHIFT                 (16U)
#define FLEXIO_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_VERID_MINOR_SHIFT)) & FLEXIO_VERID_MINOR_MASK)
#define FLEXIO_VERID_MAJOR_MASK                  (0xFF000000U)
#define FLEXIO_VERID_MAJOR_SHIFT                 (24U)
#define FLEXIO_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_VERID_MAJOR_SHIFT)) & FLEXIO_VERID_MAJOR_MASK)

/*! @name PARAM - Parameter Register */
#define FLEXIO_PARAM_SHIFTER_MASK                (0xFFU)
#define FLEXIO_PARAM_SHIFTER_SHIFT               (0U)
#define FLEXIO_PARAM_SHIFTER(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_PARAM_SHIFTER_SHIFT)) & FLEXIO_PARAM_SHIFTER_MASK)
#define FLEXIO_PARAM_TIMER_MASK                  (0xFF00U)
#define FLEXIO_PARAM_TIMER_SHIFT                 (8U)
#define FLEXIO_PARAM_TIMER(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_PARAM_TIMER_SHIFT)) & FLEXIO_PARAM_TIMER_MASK)
#define FLEXIO_PARAM_PIN_MASK                    (0xFF0000U)
#define FLEXIO_PARAM_PIN_SHIFT                   (16U)
#define FLEXIO_PARAM_PIN(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXIO_PARAM_PIN_SHIFT)) & FLEXIO_PARAM_PIN_MASK)
#define FLEXIO_PARAM_TRIGGER_MASK                (0xFF000000U)
#define FLEXIO_PARAM_TRIGGER_SHIFT               (24U)
#define FLEXIO_PARAM_TRIGGER(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_PARAM_TRIGGER_SHIFT)) & FLEXIO_PARAM_TRIGGER_MASK)

/*! @name CTRL - FlexIO Control Register */
#define FLEXIO_CTRL_FLEXEN_MASK                  (0x1U)
#define FLEXIO_CTRL_FLEXEN_SHIFT                 (0U)
#define FLEXIO_CTRL_FLEXEN(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_CTRL_FLEXEN_SHIFT)) & FLEXIO_CTRL_FLEXEN_MASK)
#define FLEXIO_CTRL_SWRST_MASK                   (0x2U)
#define FLEXIO_CTRL_SWRST_SHIFT                  (1U)
#define FLEXIO_CTRL_SWRST(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXIO_CTRL_SWRST_SHIFT)) & FLEXIO_CTRL_SWRST_MASK)
#define FLEXIO_CTRL_FASTACC_MASK                 (0x4U)
#define FLEXIO_CTRL_FASTACC_SHIFT                (2U)
#define FLEXIO_CTRL_FASTACC(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_CTRL_FASTACC_SHIFT)) & FLEXIO_CTRL_FASTACC_MASK)
#define FLEXIO_CTRL_DBGE_MASK                    (0x40000000U)
#define FLEXIO_CTRL_DBGE_SHIFT                   (30U)
#define FLEXIO_CTRL_DBGE(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXIO_CTRL_DBGE_SHIFT)) & FLEXIO_CTRL_DBGE_MASK)
#define FLEXIO_CTRL_DOZEN_MASK                   (0x80000000U)
#define FLEXIO_CTRL_DOZEN_SHIFT                  (31U)
#define FLEXIO_CTRL_DOZEN(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXIO_CTRL_DOZEN_SHIFT)) & FLEXIO_CTRL_DOZEN_MASK)

/*! @name PIN - Pin State Register */
#define FLEXIO_PIN_PDI_MASK                      (0xFFU)
#define FLEXIO_PIN_PDI_SHIFT                     (0U)
#define FLEXIO_PIN_PDI(x)                        (((uint32_t)(((uint32_t)(x)) << FLEXIO_PIN_PDI_SHIFT)) & FLEXIO_PIN_PDI_MASK)

/*! @name SHIFTSTAT - Shifter Status Register */
#define FLEXIO_SHIFTSTAT_SSF_MASK                (0xFU)
#define FLEXIO_SHIFTSTAT_SSF_SHIFT               (0U)
#define FLEXIO_SHIFTSTAT_SSF(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTSTAT_SSF_SHIFT)) & FLEXIO_SHIFTSTAT_SSF_MASK)

/*! @name SHIFTERR - Shifter Error Register */
#define FLEXIO_SHIFTERR_SEF_MASK                 (0xFU)
#define FLEXIO_SHIFTERR_SEF_SHIFT                (0U)
#define FLEXIO_SHIFTERR_SEF(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTERR_SEF_SHIFT)) & FLEXIO_SHIFTERR_SEF_MASK)

/*! @name TIMSTAT - Timer Status Register */
#define FLEXIO_TIMSTAT_TSF_MASK                  (0xFU)
#define FLEXIO_TIMSTAT_TSF_SHIFT                 (0U)
#define FLEXIO_TIMSTAT_TSF(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMSTAT_TSF_SHIFT)) & FLEXIO_TIMSTAT_TSF_MASK)

/*! @name SHIFTSIEN - Shifter Status Interrupt Enable */
#define FLEXIO_SHIFTSIEN_SSIE_MASK               (0xFU)
#define FLEXIO_SHIFTSIEN_SSIE_SHIFT              (0U)
#define FLEXIO_SHIFTSIEN_SSIE(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTSIEN_SSIE_SHIFT)) & FLEXIO_SHIFTSIEN_SSIE_MASK)

/*! @name SHIFTEIEN - Shifter Error Interrupt Enable */
#define FLEXIO_SHIFTEIEN_SEIE_MASK               (0xFU)
#define FLEXIO_SHIFTEIEN_SEIE_SHIFT              (0U)
#define FLEXIO_SHIFTEIEN_SEIE(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTEIEN_SEIE_SHIFT)) & FLEXIO_SHIFTEIEN_SEIE_MASK)

/*! @name TIMIEN - Timer Interrupt Enable Register */
#define FLEXIO_TIMIEN_TEIE_MASK                  (0xFU)
#define FLEXIO_TIMIEN_TEIE_SHIFT                 (0U)
#define FLEXIO_TIMIEN_TEIE(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMIEN_TEIE_SHIFT)) & FLEXIO_TIMIEN_TEIE_MASK)

/*! @name SHIFTSDEN - Shifter Status DMA Enable */
#define FLEXIO_SHIFTSDEN_SSDE_MASK               (0xFU)
#define FLEXIO_SHIFTSDEN_SSDE_SHIFT              (0U)
#define FLEXIO_SHIFTSDEN_SSDE(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTSDEN_SSDE_SHIFT)) & FLEXIO_SHIFTSDEN_SSDE_MASK)

/*! @name SHIFTCTL - Shifter Control N Register */
#define FLEXIO_SHIFTCTL_SMOD_MASK                (0x7U)
#define FLEXIO_SHIFTCTL_SMOD_SHIFT               (0U)
#define FLEXIO_SHIFTCTL_SMOD(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_SMOD_SHIFT)) & FLEXIO_SHIFTCTL_SMOD_MASK)
#define FLEXIO_SHIFTCTL_PINPOL_MASK              (0x80U)
#define FLEXIO_SHIFTCTL_PINPOL_SHIFT             (7U)
#define FLEXIO_SHIFTCTL_PINPOL(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_PINPOL_SHIFT)) & FLEXIO_SHIFTCTL_PINPOL_MASK)
#define FLEXIO_SHIFTCTL_PINSEL_MASK              (0x700U)
#define FLEXIO_SHIFTCTL_PINSEL_SHIFT             (8U)
#define FLEXIO_SHIFTCTL_PINSEL(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_PINSEL_SHIFT)) & FLEXIO_SHIFTCTL_PINSEL_MASK)
#define FLEXIO_SHIFTCTL_PINCFG_MASK              (0x30000U)
#define FLEXIO_SHIFTCTL_PINCFG_SHIFT             (16U)
#define FLEXIO_SHIFTCTL_PINCFG(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_PINCFG_SHIFT)) & FLEXIO_SHIFTCTL_PINCFG_MASK)
#define FLEXIO_SHIFTCTL_TIMPOL_MASK              (0x800000U)
#define FLEXIO_SHIFTCTL_TIMPOL_SHIFT             (23U)
#define FLEXIO_SHIFTCTL_TIMPOL(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_TIMPOL_SHIFT)) & FLEXIO_SHIFTCTL_TIMPOL_MASK)
#define FLEXIO_SHIFTCTL_TIMSEL_MASK              (0x3000000U)
#define FLEXIO_SHIFTCTL_TIMSEL_SHIFT             (24U)
#define FLEXIO_SHIFTCTL_TIMSEL(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCTL_TIMSEL_SHIFT)) & FLEXIO_SHIFTCTL_TIMSEL_MASK)

/* The count of FLEXIO_SHIFTCTL */
#define FLEXIO_SHIFTCTL_COUNT                    (4U)

/*! @name SHIFTCFG - Shifter Configuration N Register */
#define FLEXIO_SHIFTCFG_SSTART_MASK              (0x3U)
#define FLEXIO_SHIFTCFG_SSTART_SHIFT             (0U)
#define FLEXIO_SHIFTCFG_SSTART(x)                (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCFG_SSTART_SHIFT)) & FLEXIO_SHIFTCFG_SSTART_MASK)
#define FLEXIO_SHIFTCFG_SSTOP_MASK               (0x30U)
#define FLEXIO_SHIFTCFG_SSTOP_SHIFT              (4U)
#define FLEXIO_SHIFTCFG_SSTOP(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCFG_SSTOP_SHIFT)) & FLEXIO_SHIFTCFG_SSTOP_MASK)
#define FLEXIO_SHIFTCFG_INSRC_MASK               (0x100U)
#define FLEXIO_SHIFTCFG_INSRC_SHIFT              (8U)
#define FLEXIO_SHIFTCFG_INSRC(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTCFG_INSRC_SHIFT)) & FLEXIO_SHIFTCFG_INSRC_MASK)

/* The count of FLEXIO_SHIFTCFG */
#define FLEXIO_SHIFTCFG_COUNT                    (4U)

/*! @name SHIFTBUF - Shifter Buffer N Register */
#define FLEXIO_SHIFTBUF_SHIFTBUF_MASK            (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUF_SHIFTBUF_SHIFT           (0U)
#define FLEXIO_SHIFTBUF_SHIFTBUF(x)              (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUF_SHIFTBUF_SHIFT)) & FLEXIO_SHIFTBUF_SHIFTBUF_MASK)

/* The count of FLEXIO_SHIFTBUF */
#define FLEXIO_SHIFTBUF_COUNT                    (4U)

/*! @name SHIFTBUFBIS - Shifter Buffer N Bit Swapped Register */
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_SHIFT     (0U)
#define FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_SHIFT)) & FLEXIO_SHIFTBUFBIS_SHIFTBUFBIS_MASK)

/* The count of FLEXIO_SHIFTBUFBIS */
#define FLEXIO_SHIFTBUFBIS_COUNT                 (4U)

/*! @name SHIFTBUFBYS - Shifter Buffer N Byte Swapped Register */
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_SHIFT     (0U)
#define FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_SHIFT)) & FLEXIO_SHIFTBUFBYS_SHIFTBUFBYS_MASK)

/* The count of FLEXIO_SHIFTBUFBYS */
#define FLEXIO_SHIFTBUFBYS_COUNT                 (4U)

/*! @name SHIFTBUFBBS - Shifter Buffer N Bit Byte Swapped Register */
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_MASK      (0xFFFFFFFFU)
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_SHIFT     (0U)
#define FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS(x)        (((uint32_t)(((uint32_t)(x)) << FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_SHIFT)) & FLEXIO_SHIFTBUFBBS_SHIFTBUFBBS_MASK)

/* The count of FLEXIO_SHIFTBUFBBS */
#define FLEXIO_SHIFTBUFBBS_COUNT                 (4U)

/*! @name TIMCTL - Timer Control N Register */
#define FLEXIO_TIMCTL_TIMOD_MASK                 (0x3U)
#define FLEXIO_TIMCTL_TIMOD_SHIFT                (0U)
#define FLEXIO_TIMCTL_TIMOD(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_TIMOD_SHIFT)) & FLEXIO_TIMCTL_TIMOD_MASK)
#define FLEXIO_TIMCTL_PINPOL_MASK                (0x80U)
#define FLEXIO_TIMCTL_PINPOL_SHIFT               (7U)
#define FLEXIO_TIMCTL_PINPOL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_PINPOL_SHIFT)) & FLEXIO_TIMCTL_PINPOL_MASK)
#define FLEXIO_TIMCTL_PINSEL_MASK                (0x700U)
#define FLEXIO_TIMCTL_PINSEL_SHIFT               (8U)
#define FLEXIO_TIMCTL_PINSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_PINSEL_SHIFT)) & FLEXIO_TIMCTL_PINSEL_MASK)
#define FLEXIO_TIMCTL_PINCFG_MASK                (0x30000U)
#define FLEXIO_TIMCTL_PINCFG_SHIFT               (16U)
#define FLEXIO_TIMCTL_PINCFG(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_PINCFG_SHIFT)) & FLEXIO_TIMCTL_PINCFG_MASK)
#define FLEXIO_TIMCTL_TRGSRC_MASK                (0x400000U)
#define FLEXIO_TIMCTL_TRGSRC_SHIFT               (22U)
#define FLEXIO_TIMCTL_TRGSRC(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_TRGSRC_SHIFT)) & FLEXIO_TIMCTL_TRGSRC_MASK)
#define FLEXIO_TIMCTL_TRGPOL_MASK                (0x800000U)
#define FLEXIO_TIMCTL_TRGPOL_SHIFT               (23U)
#define FLEXIO_TIMCTL_TRGPOL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_TRGPOL_SHIFT)) & FLEXIO_TIMCTL_TRGPOL_MASK)
#define FLEXIO_TIMCTL_TRGSEL_MASK                (0xF000000U)
#define FLEXIO_TIMCTL_TRGSEL_SHIFT               (24U)
#define FLEXIO_TIMCTL_TRGSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCTL_TRGSEL_SHIFT)) & FLEXIO_TIMCTL_TRGSEL_MASK)

/* The count of FLEXIO_TIMCTL */
#define FLEXIO_TIMCTL_COUNT                      (4U)

/*! @name TIMCFG - Timer Configuration N Register */
#define FLEXIO_TIMCFG_TSTART_MASK                (0x2U)
#define FLEXIO_TIMCFG_TSTART_SHIFT               (1U)
#define FLEXIO_TIMCFG_TSTART(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TSTART_SHIFT)) & FLEXIO_TIMCFG_TSTART_MASK)
#define FLEXIO_TIMCFG_TSTOP_MASK                 (0x30U)
#define FLEXIO_TIMCFG_TSTOP_SHIFT                (4U)
#define FLEXIO_TIMCFG_TSTOP(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TSTOP_SHIFT)) & FLEXIO_TIMCFG_TSTOP_MASK)
#define FLEXIO_TIMCFG_TIMENA_MASK                (0x700U)
#define FLEXIO_TIMCFG_TIMENA_SHIFT               (8U)
#define FLEXIO_TIMCFG_TIMENA(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TIMENA_SHIFT)) & FLEXIO_TIMCFG_TIMENA_MASK)
#define FLEXIO_TIMCFG_TIMDIS_MASK                (0x7000U)
#define FLEXIO_TIMCFG_TIMDIS_SHIFT               (12U)
#define FLEXIO_TIMCFG_TIMDIS(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TIMDIS_SHIFT)) & FLEXIO_TIMCFG_TIMDIS_MASK)
#define FLEXIO_TIMCFG_TIMRST_MASK                (0x70000U)
#define FLEXIO_TIMCFG_TIMRST_SHIFT               (16U)
#define FLEXIO_TIMCFG_TIMRST(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TIMRST_SHIFT)) & FLEXIO_TIMCFG_TIMRST_MASK)
#define FLEXIO_TIMCFG_TIMDEC_MASK                (0x300000U)
#define FLEXIO_TIMCFG_TIMDEC_SHIFT               (20U)
#define FLEXIO_TIMCFG_TIMDEC(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TIMDEC_SHIFT)) & FLEXIO_TIMCFG_TIMDEC_MASK)
#define FLEXIO_TIMCFG_TIMOUT_MASK                (0x3000000U)
#define FLEXIO_TIMCFG_TIMOUT_SHIFT               (24U)
#define FLEXIO_TIMCFG_TIMOUT(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCFG_TIMOUT_SHIFT)) & FLEXIO_TIMCFG_TIMOUT_MASK)

/* The count of FLEXIO_TIMCFG */
#define FLEXIO_TIMCFG_COUNT                      (4U)

/*! @name TIMCMP - Timer Compare N Register */
#define FLEXIO_TIMCMP_CMP_MASK                   (0xFFFFU)
#define FLEXIO_TIMCMP_CMP_SHIFT                  (0U)
#define FLEXIO_TIMCMP_CMP(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXIO_TIMCMP_CMP_SHIFT)) & FLEXIO_TIMCMP_CMP_MASK)

/* The count of FLEXIO_TIMCMP */
#define FLEXIO_TIMCMP_COUNT                      (4U)


/*!
 * @}
 */ /* end of group FLEXIO_Register_Masks */


/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO base address */
#define FLEXIO_BASE                              (0x4005F000u)
/** Peripheral FLEXIO base pointer */
#define FLEXIO                                   ((FLEXIO_Type *)FLEXIO_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { FLEXIO_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { FLEXIO }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { FLEXIO_IRQn }

/*!
 * @}
 */ /* end of group FLEXIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Peripheral_Access_Layer FMC Peripheral Access Layer
 * @{
 */

/** FMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t PFAPR;                             /**< Flash Access Protection Register, offset: 0x0 */
  __IO uint32_t PFB0CR;                            /**< Flash Bank 0 Control Register, offset: 0x4 */
  __IO uint32_t PFB1CR;                            /**< Flash Bank 1 Control Register, offset: 0x8 */
       uint8_t RESERVED_0[244];
  __IO uint32_t TAGVDW0S[8];                       /**< Cache Tag Storage, array offset: 0x100, array step: 0x4 */
  __IO uint32_t TAGVDW1S[8];                       /**< Cache Tag Storage, array offset: 0x120, array step: 0x4 */
  __IO uint32_t TAGVDW2S[8];                       /**< Cache Tag Storage, array offset: 0x140, array step: 0x4 */
  __IO uint32_t TAGVDW3S[8];                       /**< Cache Tag Storage, array offset: 0x160, array step: 0x4 */
       uint8_t RESERVED_1[128];
  struct {                                         /* offset: 0x200, array step: index*0x40, index2*0x8 */
    __IO uint32_t DATA_U;                            /**< Cache Data Storage (upper word), array offset: 0x200, array step: index*0x40, index2*0x8 */
    __IO uint32_t DATA_L;                            /**< Cache Data Storage (lower word), array offset: 0x204, array step: index*0x40, index2*0x8 */
  } SET[4][8];
} FMC_Type;

/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Register_Masks FMC Register Masks
 * @{
 */

/*! @name PFAPR - Flash Access Protection Register */
#define FMC_PFAPR_M0AP_MASK                      (0x3U)
#define FMC_PFAPR_M0AP_SHIFT                     (0U)
#define FMC_PFAPR_M0AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M0AP_SHIFT)) & FMC_PFAPR_M0AP_MASK)
#define FMC_PFAPR_M1AP_MASK                      (0xCU)
#define FMC_PFAPR_M1AP_SHIFT                     (2U)
#define FMC_PFAPR_M1AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M1AP_SHIFT)) & FMC_PFAPR_M1AP_MASK)
#define FMC_PFAPR_M2AP_MASK                      (0x30U)
#define FMC_PFAPR_M2AP_SHIFT                     (4U)
#define FMC_PFAPR_M2AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M2AP_SHIFT)) & FMC_PFAPR_M2AP_MASK)
#define FMC_PFAPR_M3AP_MASK                      (0xC0U)
#define FMC_PFAPR_M3AP_SHIFT                     (6U)
#define FMC_PFAPR_M3AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M3AP_SHIFT)) & FMC_PFAPR_M3AP_MASK)
#define FMC_PFAPR_M4AP_MASK                      (0x300U)
#define FMC_PFAPR_M4AP_SHIFT                     (8U)
#define FMC_PFAPR_M4AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M4AP_SHIFT)) & FMC_PFAPR_M4AP_MASK)
#define FMC_PFAPR_M5AP_MASK                      (0xC00U)
#define FMC_PFAPR_M5AP_SHIFT                     (10U)
#define FMC_PFAPR_M5AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M5AP_SHIFT)) & FMC_PFAPR_M5AP_MASK)
#define FMC_PFAPR_M6AP_MASK                      (0x3000U)
#define FMC_PFAPR_M6AP_SHIFT                     (12U)
#define FMC_PFAPR_M6AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M6AP_SHIFT)) & FMC_PFAPR_M6AP_MASK)
#define FMC_PFAPR_M7AP_MASK                      (0xC000U)
#define FMC_PFAPR_M7AP_SHIFT                     (14U)
#define FMC_PFAPR_M7AP(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M7AP_SHIFT)) & FMC_PFAPR_M7AP_MASK)
#define FMC_PFAPR_M0PFD_MASK                     (0x10000U)
#define FMC_PFAPR_M0PFD_SHIFT                    (16U)
#define FMC_PFAPR_M0PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M0PFD_SHIFT)) & FMC_PFAPR_M0PFD_MASK)
#define FMC_PFAPR_M1PFD_MASK                     (0x20000U)
#define FMC_PFAPR_M1PFD_SHIFT                    (17U)
#define FMC_PFAPR_M1PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M1PFD_SHIFT)) & FMC_PFAPR_M1PFD_MASK)
#define FMC_PFAPR_M2PFD_MASK                     (0x40000U)
#define FMC_PFAPR_M2PFD_SHIFT                    (18U)
#define FMC_PFAPR_M2PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M2PFD_SHIFT)) & FMC_PFAPR_M2PFD_MASK)
#define FMC_PFAPR_M3PFD_MASK                     (0x80000U)
#define FMC_PFAPR_M3PFD_SHIFT                    (19U)
#define FMC_PFAPR_M3PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M3PFD_SHIFT)) & FMC_PFAPR_M3PFD_MASK)
#define FMC_PFAPR_M4PFD_MASK                     (0x100000U)
#define FMC_PFAPR_M4PFD_SHIFT                    (20U)
#define FMC_PFAPR_M4PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M4PFD_SHIFT)) & FMC_PFAPR_M4PFD_MASK)
#define FMC_PFAPR_M5PFD_MASK                     (0x200000U)
#define FMC_PFAPR_M5PFD_SHIFT                    (21U)
#define FMC_PFAPR_M5PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M5PFD_SHIFT)) & FMC_PFAPR_M5PFD_MASK)
#define FMC_PFAPR_M6PFD_MASK                     (0x400000U)
#define FMC_PFAPR_M6PFD_SHIFT                    (22U)
#define FMC_PFAPR_M6PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M6PFD_SHIFT)) & FMC_PFAPR_M6PFD_MASK)
#define FMC_PFAPR_M7PFD_MASK                     (0x800000U)
#define FMC_PFAPR_M7PFD_SHIFT                    (23U)
#define FMC_PFAPR_M7PFD(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFAPR_M7PFD_SHIFT)) & FMC_PFAPR_M7PFD_MASK)

/*! @name PFB0CR - Flash Bank 0 Control Register */
#define FMC_PFB0CR_B0SEBE_MASK                   (0x1U)
#define FMC_PFB0CR_B0SEBE_SHIFT                  (0U)
#define FMC_PFB0CR_B0SEBE(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0SEBE_SHIFT)) & FMC_PFB0CR_B0SEBE_MASK)
#define FMC_PFB0CR_B0IPE_MASK                    (0x2U)
#define FMC_PFB0CR_B0IPE_SHIFT                   (1U)
#define FMC_PFB0CR_B0IPE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0IPE_SHIFT)) & FMC_PFB0CR_B0IPE_MASK)
#define FMC_PFB0CR_B0DPE_MASK                    (0x4U)
#define FMC_PFB0CR_B0DPE_SHIFT                   (2U)
#define FMC_PFB0CR_B0DPE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0DPE_SHIFT)) & FMC_PFB0CR_B0DPE_MASK)
#define FMC_PFB0CR_B0ICE_MASK                    (0x8U)
#define FMC_PFB0CR_B0ICE_SHIFT                   (3U)
#define FMC_PFB0CR_B0ICE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0ICE_SHIFT)) & FMC_PFB0CR_B0ICE_MASK)
#define FMC_PFB0CR_B0DCE_MASK                    (0x10U)
#define FMC_PFB0CR_B0DCE_SHIFT                   (4U)
#define FMC_PFB0CR_B0DCE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0DCE_SHIFT)) & FMC_PFB0CR_B0DCE_MASK)
#define FMC_PFB0CR_CRC_MASK                      (0xE0U)
#define FMC_PFB0CR_CRC_SHIFT                     (5U)
#define FMC_PFB0CR_CRC(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_CRC_SHIFT)) & FMC_PFB0CR_CRC_MASK)
#define FMC_PFB0CR_B0MW_MASK                     (0x60000U)
#define FMC_PFB0CR_B0MW_SHIFT                    (17U)
#define FMC_PFB0CR_B0MW(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0MW_SHIFT)) & FMC_PFB0CR_B0MW_MASK)
#define FMC_PFB0CR_S_B_INV_MASK                  (0x80000U)
#define FMC_PFB0CR_S_B_INV_SHIFT                 (19U)
#define FMC_PFB0CR_S_B_INV(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_S_B_INV_SHIFT)) & FMC_PFB0CR_S_B_INV_MASK)
#define FMC_PFB0CR_CINV_WAY_MASK                 (0xF00000U)
#define FMC_PFB0CR_CINV_WAY_SHIFT                (20U)
#define FMC_PFB0CR_CINV_WAY(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_CINV_WAY_SHIFT)) & FMC_PFB0CR_CINV_WAY_MASK)
#define FMC_PFB0CR_CLCK_WAY_MASK                 (0xF000000U)
#define FMC_PFB0CR_CLCK_WAY_SHIFT                (24U)
#define FMC_PFB0CR_CLCK_WAY(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_CLCK_WAY_SHIFT)) & FMC_PFB0CR_CLCK_WAY_MASK)
#define FMC_PFB0CR_B0RWSC_MASK                   (0xF0000000U)
#define FMC_PFB0CR_B0RWSC_SHIFT                  (28U)
#define FMC_PFB0CR_B0RWSC(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_PFB0CR_B0RWSC_SHIFT)) & FMC_PFB0CR_B0RWSC_MASK)

/*! @name PFB1CR - Flash Bank 1 Control Register */
#define FMC_PFB1CR_B1SEBE_MASK                   (0x1U)
#define FMC_PFB1CR_B1SEBE_SHIFT                  (0U)
#define FMC_PFB1CR_B1SEBE(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_PFB1CR_B1SEBE_SHIFT)) & FMC_PFB1CR_B1SEBE_MASK)
#define FMC_PFB1CR_B1IPE_MASK                    (0x2U)
#define FMC_PFB1CR_B1IPE_SHIFT                   (1U)
#define FMC_PFB1CR_B1IPE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB1CR_B1IPE_SHIFT)) & FMC_PFB1CR_B1IPE_MASK)
#define FMC_PFB1CR_B1DPE_MASK                    (0x4U)
#define FMC_PFB1CR_B1DPE_SHIFT                   (2U)
#define FMC_PFB1CR_B1DPE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB1CR_B1DPE_SHIFT)) & FMC_PFB1CR_B1DPE_MASK)
#define FMC_PFB1CR_B1ICE_MASK                    (0x8U)
#define FMC_PFB1CR_B1ICE_SHIFT                   (3U)
#define FMC_PFB1CR_B1ICE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB1CR_B1ICE_SHIFT)) & FMC_PFB1CR_B1ICE_MASK)
#define FMC_PFB1CR_B1DCE_MASK                    (0x10U)
#define FMC_PFB1CR_B1DCE_SHIFT                   (4U)
#define FMC_PFB1CR_B1DCE(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_PFB1CR_B1DCE_SHIFT)) & FMC_PFB1CR_B1DCE_MASK)
#define FMC_PFB1CR_B1MW_MASK                     (0x60000U)
#define FMC_PFB1CR_B1MW_SHIFT                    (17U)
#define FMC_PFB1CR_B1MW(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_PFB1CR_B1MW_SHIFT)) & FMC_PFB1CR_B1MW_MASK)
#define FMC_PFB1CR_B1RWSC_MASK                   (0xF0000000U)
#define FMC_PFB1CR_B1RWSC_SHIFT                  (28U)
#define FMC_PFB1CR_B1RWSC(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_PFB1CR_B1RWSC_SHIFT)) & FMC_PFB1CR_B1RWSC_MASK)

/*! @name TAGVDW0S - Cache Tag Storage */
#define FMC_TAGVDW0S_valid_MASK                  (0x1U)
#define FMC_TAGVDW0S_valid_SHIFT                 (0U)
#define FMC_TAGVDW0S_valid(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S_valid_SHIFT)) & FMC_TAGVDW0S_valid_MASK)
#define FMC_TAGVDW0S_tag_MASK                    (0x7FFE0U)
#define FMC_TAGVDW0S_tag_SHIFT                   (5U)
#define FMC_TAGVDW0S_tag(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW0S_tag_SHIFT)) & FMC_TAGVDW0S_tag_MASK)

/* The count of FMC_TAGVDW0S */
#define FMC_TAGVDW0S_COUNT                       (8U)

/*! @name TAGVDW1S - Cache Tag Storage */
#define FMC_TAGVDW1S_valid_MASK                  (0x1U)
#define FMC_TAGVDW1S_valid_SHIFT                 (0U)
#define FMC_TAGVDW1S_valid(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S_valid_SHIFT)) & FMC_TAGVDW1S_valid_MASK)
#define FMC_TAGVDW1S_tag_MASK                    (0x7FFE0U)
#define FMC_TAGVDW1S_tag_SHIFT                   (5U)
#define FMC_TAGVDW1S_tag(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW1S_tag_SHIFT)) & FMC_TAGVDW1S_tag_MASK)

/* The count of FMC_TAGVDW1S */
#define FMC_TAGVDW1S_COUNT                       (8U)

/*! @name TAGVDW2S - Cache Tag Storage */
#define FMC_TAGVDW2S_valid_MASK                  (0x1U)
#define FMC_TAGVDW2S_valid_SHIFT                 (0U)
#define FMC_TAGVDW2S_valid(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S_valid_SHIFT)) & FMC_TAGVDW2S_valid_MASK)
#define FMC_TAGVDW2S_tag_MASK                    (0x7FFE0U)
#define FMC_TAGVDW2S_tag_SHIFT                   (5U)
#define FMC_TAGVDW2S_tag(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW2S_tag_SHIFT)) & FMC_TAGVDW2S_tag_MASK)

/* The count of FMC_TAGVDW2S */
#define FMC_TAGVDW2S_COUNT                       (8U)

/*! @name TAGVDW3S - Cache Tag Storage */
#define FMC_TAGVDW3S_valid_MASK                  (0x1U)
#define FMC_TAGVDW3S_valid_SHIFT                 (0U)
#define FMC_TAGVDW3S_valid(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S_valid_SHIFT)) & FMC_TAGVDW3S_valid_MASK)
#define FMC_TAGVDW3S_tag_MASK                    (0x7FFE0U)
#define FMC_TAGVDW3S_tag_SHIFT                   (5U)
#define FMC_TAGVDW3S_tag(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_TAGVDW3S_tag_SHIFT)) & FMC_TAGVDW3S_tag_MASK)

/* The count of FMC_TAGVDW3S */
#define FMC_TAGVDW3S_COUNT                       (8U)

/*! @name DATA_U - Cache Data Storage (upper word) */
#define FMC_DATA_U_data_MASK                     (0xFFFFFFFFU)
#define FMC_DATA_U_data_SHIFT                    (0U)
#define FMC_DATA_U_data(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_DATA_U_data_SHIFT)) & FMC_DATA_U_data_MASK)

/* The count of FMC_DATA_U */
#define FMC_DATA_U_COUNT                         (4U)

/* The count of FMC_DATA_U */
#define FMC_DATA_U_COUNT2                        (8U)

/*! @name DATA_L - Cache Data Storage (lower word) */
#define FMC_DATA_L_data_MASK                     (0xFFFFFFFFU)
#define FMC_DATA_L_data_SHIFT                    (0U)
#define FMC_DATA_L_data(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_DATA_L_data_SHIFT)) & FMC_DATA_L_data_MASK)

/* The count of FMC_DATA_L */
#define FMC_DATA_L_COUNT                         (4U)

/* The count of FMC_DATA_L */
#define FMC_DATA_L_COUNT2                        (8U)


/*!
 * @}
 */ /* end of group FMC_Register_Masks */


/* FMC - Peripheral instance base addresses */
/** Peripheral FMC base address */
#define FMC_BASE                                 (0x4001F000u)
/** Peripheral FMC base pointer */
#define FMC                                      ((FMC_Type *)FMC_BASE)
/** Array initializer of FMC peripheral base addresses */
#define FMC_BASE_ADDRS                           { FMC_BASE }
/** Array initializer of FMC peripheral base pointers */
#define FMC_BASE_PTRS                            { FMC }

/*!
 * @}
 */ /* end of group FMC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FTFA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Peripheral_Access_Layer FTFA Peripheral Access Layer
 * @{
 */

/** FTFA - Register Layout Typedef */
typedef struct {
  __IO uint8_t FSTAT;                              /**< Flash Status Register, offset: 0x0 */
  __IO uint8_t FCNFG;                              /**< Flash Configuration Register, offset: 0x1 */
  __I  uint8_t FSEC;                               /**< Flash Security Register, offset: 0x2 */
  __I  uint8_t FOPT;                               /**< Flash Option Register, offset: 0x3 */
  __IO uint8_t FCCOB3;                             /**< Flash Common Command Object Registers, offset: 0x4 */
  __IO uint8_t FCCOB2;                             /**< Flash Common Command Object Registers, offset: 0x5 */
  __IO uint8_t FCCOB1;                             /**< Flash Common Command Object Registers, offset: 0x6 */
  __IO uint8_t FCCOB0;                             /**< Flash Common Command Object Registers, offset: 0x7 */
  __IO uint8_t FCCOB7;                             /**< Flash Common Command Object Registers, offset: 0x8 */
  __IO uint8_t FCCOB6;                             /**< Flash Common Command Object Registers, offset: 0x9 */
  __IO uint8_t FCCOB5;                             /**< Flash Common Command Object Registers, offset: 0xA */
  __IO uint8_t FCCOB4;                             /**< Flash Common Command Object Registers, offset: 0xB */
  __IO uint8_t FCCOBB;                             /**< Flash Common Command Object Registers, offset: 0xC */
  __IO uint8_t FCCOBA;                             /**< Flash Common Command Object Registers, offset: 0xD */
  __IO uint8_t FCCOB9;                             /**< Flash Common Command Object Registers, offset: 0xE */
  __IO uint8_t FCCOB8;                             /**< Flash Common Command Object Registers, offset: 0xF */
  __IO uint8_t FPROT3;                             /**< Program Flash Protection Registers, offset: 0x10 */
  __IO uint8_t FPROT2;                             /**< Program Flash Protection Registers, offset: 0x11 */
  __IO uint8_t FPROT1;                             /**< Program Flash Protection Registers, offset: 0x12 */
  __IO uint8_t FPROT0;                             /**< Program Flash Protection Registers, offset: 0x13 */
       uint8_t RESERVED_0[4];
  __I  uint8_t XACCH3;                             /**< Execute-only Access Registers, offset: 0x18 */
  __I  uint8_t XACCH2;                             /**< Execute-only Access Registers, offset: 0x19 */
  __I  uint8_t XACCH1;                             /**< Execute-only Access Registers, offset: 0x1A */
  __I  uint8_t XACCH0;                             /**< Execute-only Access Registers, offset: 0x1B */
  __I  uint8_t XACCL3;                             /**< Execute-only Access Registers, offset: 0x1C */
  __I  uint8_t XACCL2;                             /**< Execute-only Access Registers, offset: 0x1D */
  __I  uint8_t XACCL1;                             /**< Execute-only Access Registers, offset: 0x1E */
  __I  uint8_t XACCL0;                             /**< Execute-only Access Registers, offset: 0x1F */
  __I  uint8_t SACCH3;                             /**< Supervisor-only Access Registers, offset: 0x20 */
  __I  uint8_t SACCH2;                             /**< Supervisor-only Access Registers, offset: 0x21 */
  __I  uint8_t SACCH1;                             /**< Supervisor-only Access Registers, offset: 0x22 */
  __I  uint8_t SACCH0;                             /**< Supervisor-only Access Registers, offset: 0x23 */
  __I  uint8_t SACCL3;                             /**< Supervisor-only Access Registers, offset: 0x24 */
  __I  uint8_t SACCL2;                             /**< Supervisor-only Access Registers, offset: 0x25 */
  __I  uint8_t SACCL1;                             /**< Supervisor-only Access Registers, offset: 0x26 */
  __I  uint8_t SACCL0;                             /**< Supervisor-only Access Registers, offset: 0x27 */
  __I  uint8_t FACSS;                              /**< Flash Access Segment Size Register, offset: 0x28 */
       uint8_t RESERVED_1[2];
  __I  uint8_t FACSN;                              /**< Flash Access Segment Number Register, offset: 0x2B */
} FTFA_Type;

/* ----------------------------------------------------------------------------
   -- FTFA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFA_Register_Masks FTFA Register Masks
 * @{
 */

/*! @name FSTAT - Flash Status Register */
#define FTFA_FSTAT_MGSTAT0_MASK                  (0x1U)
#define FTFA_FSTAT_MGSTAT0_SHIFT                 (0U)
#define FTFA_FSTAT_MGSTAT0(x)                    (((uint8_t)(((uint8_t)(x)) << FTFA_FSTAT_MGSTAT0_SHIFT)) & FTFA_FSTAT_MGSTAT0_MASK)
#define FTFA_FSTAT_FPVIOL_MASK                   (0x10U)
#define FTFA_FSTAT_FPVIOL_SHIFT                  (4U)
#define FTFA_FSTAT_FPVIOL(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FSTAT_FPVIOL_SHIFT)) & FTFA_FSTAT_FPVIOL_MASK)
#define FTFA_FSTAT_ACCERR_MASK                   (0x20U)
#define FTFA_FSTAT_ACCERR_SHIFT                  (5U)
#define FTFA_FSTAT_ACCERR(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FSTAT_ACCERR_SHIFT)) & FTFA_FSTAT_ACCERR_MASK)
#define FTFA_FSTAT_RDCOLERR_MASK                 (0x40U)
#define FTFA_FSTAT_RDCOLERR_SHIFT                (6U)
#define FTFA_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x)) << FTFA_FSTAT_RDCOLERR_SHIFT)) & FTFA_FSTAT_RDCOLERR_MASK)
#define FTFA_FSTAT_CCIF_MASK                     (0x80U)
#define FTFA_FSTAT_CCIF_SHIFT                    (7U)
#define FTFA_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x)) << FTFA_FSTAT_CCIF_SHIFT)) & FTFA_FSTAT_CCIF_MASK)

/*! @name FCNFG - Flash Configuration Register */
#define FTFA_FCNFG_ERSSUSP_MASK                  (0x10U)
#define FTFA_FCNFG_ERSSUSP_SHIFT                 (4U)
#define FTFA_FCNFG_ERSSUSP(x)                    (((uint8_t)(((uint8_t)(x)) << FTFA_FCNFG_ERSSUSP_SHIFT)) & FTFA_FCNFG_ERSSUSP_MASK)
#define FTFA_FCNFG_ERSAREQ_MASK                  (0x20U)
#define FTFA_FCNFG_ERSAREQ_SHIFT                 (5U)
#define FTFA_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x)) << FTFA_FCNFG_ERSAREQ_SHIFT)) & FTFA_FCNFG_ERSAREQ_MASK)
#define FTFA_FCNFG_RDCOLLIE_MASK                 (0x40U)
#define FTFA_FCNFG_RDCOLLIE_SHIFT                (6U)
#define FTFA_FCNFG_RDCOLLIE(x)                   (((uint8_t)(((uint8_t)(x)) << FTFA_FCNFG_RDCOLLIE_SHIFT)) & FTFA_FCNFG_RDCOLLIE_MASK)
#define FTFA_FCNFG_CCIE_MASK                     (0x80U)
#define FTFA_FCNFG_CCIE_SHIFT                    (7U)
#define FTFA_FCNFG_CCIE(x)                       (((uint8_t)(((uint8_t)(x)) << FTFA_FCNFG_CCIE_SHIFT)) & FTFA_FCNFG_CCIE_MASK)

/*! @name FSEC - Flash Security Register */
#define FTFA_FSEC_SEC_MASK                       (0x3U)
#define FTFA_FSEC_SEC_SHIFT                      (0U)
#define FTFA_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x)) << FTFA_FSEC_SEC_SHIFT)) & FTFA_FSEC_SEC_MASK)
#define FTFA_FSEC_FSLACC_MASK                    (0xCU)
#define FTFA_FSEC_FSLACC_SHIFT                   (2U)
#define FTFA_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x)) << FTFA_FSEC_FSLACC_SHIFT)) & FTFA_FSEC_FSLACC_MASK)
#define FTFA_FSEC_MEEN_MASK                      (0x30U)
#define FTFA_FSEC_MEEN_SHIFT                     (4U)
#define FTFA_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_FSEC_MEEN_SHIFT)) & FTFA_FSEC_MEEN_MASK)
#define FTFA_FSEC_KEYEN_MASK                     (0xC0U)
#define FTFA_FSEC_KEYEN_SHIFT                    (6U)
#define FTFA_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x)) << FTFA_FSEC_KEYEN_SHIFT)) & FTFA_FSEC_KEYEN_MASK)

/*! @name FOPT - Flash Option Register */
#define FTFA_FOPT_OPT_MASK                       (0xFFU)
#define FTFA_FOPT_OPT_SHIFT                      (0U)
#define FTFA_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x)) << FTFA_FOPT_OPT_SHIFT)) & FTFA_FOPT_OPT_MASK)

/*! @name FCCOB3 - Flash Common Command Object Registers */
#define FTFA_FCCOB3_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOB3_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOB3_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB3_CCOBn_SHIFT)) & FTFA_FCCOB3_CCOBn_MASK)

/*! @name FCCOB2 - Flash Common Command Object Registers */
#define FTFA_FCCOB2_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOB2_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOB2_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB2_CCOBn_SHIFT)) & FTFA_FCCOB2_CCOBn_MASK)

/*! @name FCCOB1 - Flash Common Command Object Registers */
#define FTFA_FCCOB1_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOB1_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOB1_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB1_CCOBn_SHIFT)) & FTFA_FCCOB1_CCOBn_MASK)

/*! @name FCCOB0 - Flash Common Command Object Registers */
#define FTFA_FCCOB0_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOB0_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOB0_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB0_CCOBn_SHIFT)) & FTFA_FCCOB0_CCOBn_MASK)

/*! @name FCCOB7 - Flash Common Command Object Registers */
#define FTFA_FCCOB7_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOB7_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOB7_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB7_CCOBn_SHIFT)) & FTFA_FCCOB7_CCOBn_MASK)

/*! @name FCCOB6 - Flash Common Command Object Registers */
#define FTFA_FCCOB6_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOB6_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOB6_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB6_CCOBn_SHIFT)) & FTFA_FCCOB6_CCOBn_MASK)

/*! @name FCCOB5 - Flash Common Command Object Registers */
#define FTFA_FCCOB5_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOB5_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOB5_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB5_CCOBn_SHIFT)) & FTFA_FCCOB5_CCOBn_MASK)

/*! @name FCCOB4 - Flash Common Command Object Registers */
#define FTFA_FCCOB4_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOB4_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOB4_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB4_CCOBn_SHIFT)) & FTFA_FCCOB4_CCOBn_MASK)

/*! @name FCCOBB - Flash Common Command Object Registers */
#define FTFA_FCCOBB_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOBB_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOBB_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOBB_CCOBn_SHIFT)) & FTFA_FCCOBB_CCOBn_MASK)

/*! @name FCCOBA - Flash Common Command Object Registers */
#define FTFA_FCCOBA_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOBA_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOBA_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOBA_CCOBn_SHIFT)) & FTFA_FCCOBA_CCOBn_MASK)

/*! @name FCCOB9 - Flash Common Command Object Registers */
#define FTFA_FCCOB9_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOB9_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOB9_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB9_CCOBn_SHIFT)) & FTFA_FCCOB9_CCOBn_MASK)

/*! @name FCCOB8 - Flash Common Command Object Registers */
#define FTFA_FCCOB8_CCOBn_MASK                   (0xFFU)
#define FTFA_FCCOB8_CCOBn_SHIFT                  (0U)
#define FTFA_FCCOB8_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FCCOB8_CCOBn_SHIFT)) & FTFA_FCCOB8_CCOBn_MASK)

/*! @name FPROT3 - Program Flash Protection Registers */
#define FTFA_FPROT3_PROT_MASK                    (0xFFU)
#define FTFA_FPROT3_PROT_SHIFT                   (0U)
#define FTFA_FPROT3_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFA_FPROT3_PROT_SHIFT)) & FTFA_FPROT3_PROT_MASK)

/*! @name FPROT2 - Program Flash Protection Registers */
#define FTFA_FPROT2_PROT_MASK                    (0xFFU)
#define FTFA_FPROT2_PROT_SHIFT                   (0U)
#define FTFA_FPROT2_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFA_FPROT2_PROT_SHIFT)) & FTFA_FPROT2_PROT_MASK)

/*! @name FPROT1 - Program Flash Protection Registers */
#define FTFA_FPROT1_PROT_MASK                    (0xFFU)
#define FTFA_FPROT1_PROT_SHIFT                   (0U)
#define FTFA_FPROT1_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFA_FPROT1_PROT_SHIFT)) & FTFA_FPROT1_PROT_MASK)

/*! @name FPROT0 - Program Flash Protection Registers */
#define FTFA_FPROT0_PROT_MASK                    (0xFFU)
#define FTFA_FPROT0_PROT_SHIFT                   (0U)
#define FTFA_FPROT0_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFA_FPROT0_PROT_SHIFT)) & FTFA_FPROT0_PROT_MASK)

/*! @name XACCH3 - Execute-only Access Registers */
#define FTFA_XACCH3_XA_MASK                      (0xFFU)
#define FTFA_XACCH3_XA_SHIFT                     (0U)
#define FTFA_XACCH3_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_XACCH3_XA_SHIFT)) & FTFA_XACCH3_XA_MASK)

/*! @name XACCH2 - Execute-only Access Registers */
#define FTFA_XACCH2_XA_MASK                      (0xFFU)
#define FTFA_XACCH2_XA_SHIFT                     (0U)
#define FTFA_XACCH2_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_XACCH2_XA_SHIFT)) & FTFA_XACCH2_XA_MASK)

/*! @name XACCH1 - Execute-only Access Registers */
#define FTFA_XACCH1_XA_MASK                      (0xFFU)
#define FTFA_XACCH1_XA_SHIFT                     (0U)
#define FTFA_XACCH1_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_XACCH1_XA_SHIFT)) & FTFA_XACCH1_XA_MASK)

/*! @name XACCH0 - Execute-only Access Registers */
#define FTFA_XACCH0_XA_MASK                      (0xFFU)
#define FTFA_XACCH0_XA_SHIFT                     (0U)
#define FTFA_XACCH0_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_XACCH0_XA_SHIFT)) & FTFA_XACCH0_XA_MASK)

/*! @name XACCL3 - Execute-only Access Registers */
#define FTFA_XACCL3_XA_MASK                      (0xFFU)
#define FTFA_XACCL3_XA_SHIFT                     (0U)
#define FTFA_XACCL3_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_XACCL3_XA_SHIFT)) & FTFA_XACCL3_XA_MASK)

/*! @name XACCL2 - Execute-only Access Registers */
#define FTFA_XACCL2_XA_MASK                      (0xFFU)
#define FTFA_XACCL2_XA_SHIFT                     (0U)
#define FTFA_XACCL2_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_XACCL2_XA_SHIFT)) & FTFA_XACCL2_XA_MASK)

/*! @name XACCL1 - Execute-only Access Registers */
#define FTFA_XACCL1_XA_MASK                      (0xFFU)
#define FTFA_XACCL1_XA_SHIFT                     (0U)
#define FTFA_XACCL1_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_XACCL1_XA_SHIFT)) & FTFA_XACCL1_XA_MASK)

/*! @name XACCL0 - Execute-only Access Registers */
#define FTFA_XACCL0_XA_MASK                      (0xFFU)
#define FTFA_XACCL0_XA_SHIFT                     (0U)
#define FTFA_XACCL0_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_XACCL0_XA_SHIFT)) & FTFA_XACCL0_XA_MASK)

/*! @name SACCH3 - Supervisor-only Access Registers */
#define FTFA_SACCH3_SA_MASK                      (0xFFU)
#define FTFA_SACCH3_SA_SHIFT                     (0U)
#define FTFA_SACCH3_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_SACCH3_SA_SHIFT)) & FTFA_SACCH3_SA_MASK)

/*! @name SACCH2 - Supervisor-only Access Registers */
#define FTFA_SACCH2_SA_MASK                      (0xFFU)
#define FTFA_SACCH2_SA_SHIFT                     (0U)
#define FTFA_SACCH2_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_SACCH2_SA_SHIFT)) & FTFA_SACCH2_SA_MASK)

/*! @name SACCH1 - Supervisor-only Access Registers */
#define FTFA_SACCH1_SA_MASK                      (0xFFU)
#define FTFA_SACCH1_SA_SHIFT                     (0U)
#define FTFA_SACCH1_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_SACCH1_SA_SHIFT)) & FTFA_SACCH1_SA_MASK)

/*! @name SACCH0 - Supervisor-only Access Registers */
#define FTFA_SACCH0_SA_MASK                      (0xFFU)
#define FTFA_SACCH0_SA_SHIFT                     (0U)
#define FTFA_SACCH0_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_SACCH0_SA_SHIFT)) & FTFA_SACCH0_SA_MASK)

/*! @name SACCL3 - Supervisor-only Access Registers */
#define FTFA_SACCL3_SA_MASK                      (0xFFU)
#define FTFA_SACCL3_SA_SHIFT                     (0U)
#define FTFA_SACCL3_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_SACCL3_SA_SHIFT)) & FTFA_SACCL3_SA_MASK)

/*! @name SACCL2 - Supervisor-only Access Registers */
#define FTFA_SACCL2_SA_MASK                      (0xFFU)
#define FTFA_SACCL2_SA_SHIFT                     (0U)
#define FTFA_SACCL2_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_SACCL2_SA_SHIFT)) & FTFA_SACCL2_SA_MASK)

/*! @name SACCL1 - Supervisor-only Access Registers */
#define FTFA_SACCL1_SA_MASK                      (0xFFU)
#define FTFA_SACCL1_SA_SHIFT                     (0U)
#define FTFA_SACCL1_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_SACCL1_SA_SHIFT)) & FTFA_SACCL1_SA_MASK)

/*! @name SACCL0 - Supervisor-only Access Registers */
#define FTFA_SACCL0_SA_MASK                      (0xFFU)
#define FTFA_SACCL0_SA_SHIFT                     (0U)
#define FTFA_SACCL0_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFA_SACCL0_SA_SHIFT)) & FTFA_SACCL0_SA_MASK)

/*! @name FACSS - Flash Access Segment Size Register */
#define FTFA_FACSS_SGSIZE_MASK                   (0xFFU)
#define FTFA_FACSS_SGSIZE_SHIFT                  (0U)
#define FTFA_FACSS_SGSIZE(x)                     (((uint8_t)(((uint8_t)(x)) << FTFA_FACSS_SGSIZE_SHIFT)) & FTFA_FACSS_SGSIZE_MASK)

/*! @name FACSN - Flash Access Segment Number Register */
#define FTFA_FACSN_NUMSG_MASK                    (0xFFU)
#define FTFA_FACSN_NUMSG_SHIFT                   (0U)
#define FTFA_FACSN_NUMSG(x)                      (((uint8_t)(((uint8_t)(x)) << FTFA_FACSN_NUMSG_SHIFT)) & FTFA_FACSN_NUMSG_MASK)


/*!
 * @}
 */ /* end of group FTFA_Register_Masks */


/* FTFA - Peripheral instance base addresses */
/** Peripheral FTFA base address */
#define FTFA_BASE                                (0x40020000u)
/** Peripheral FTFA base pointer */
#define FTFA                                     ((FTFA_Type *)FTFA_BASE)
/** Array initializer of FTFA peripheral base addresses */
#define FTFA_BASE_ADDRS                          { FTFA_BASE }
/** Array initializer of FTFA peripheral base pointers */
#define FTFA_BASE_PTRS                           { FTFA }
/** Interrupt vectors for the FTFA peripheral type */
#define FTFA_COMMAND_COMPLETE_IRQS               { FTF_IRQn }
#define FTFA_READ_COLLISION_IRQS                 { Read_Collision_IRQn }

/*!
 * @}
 */ /* end of group FTFA_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t PDOR;                              /**< Port Data Output Register, offset: 0x0 */
  __O  uint32_t PSOR;                              /**< Port Set Output Register, offset: 0x4 */
  __O  uint32_t PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
  __O  uint32_t PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
  __I  uint32_t PDIR;                              /**< Port Data Input Register, offset: 0x10 */
  __IO uint32_t PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
} GPIO_Type;

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/*! @name PDOR - Port Data Output Register */
#define GPIO_PDOR_PDO_MASK                       (0xFFFFFFFFU)
#define GPIO_PDOR_PDO_SHIFT                      (0U)
#define GPIO_PDOR_PDO(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_PDOR_PDO_SHIFT)) & GPIO_PDOR_PDO_MASK)

/*! @name PSOR - Port Set Output Register */
#define GPIO_PSOR_PTSO_MASK                      (0xFFFFFFFFU)
#define GPIO_PSOR_PTSO_SHIFT                     (0U)
#define GPIO_PSOR_PTSO(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PSOR_PTSO_SHIFT)) & GPIO_PSOR_PTSO_MASK)

/*! @name PCOR - Port Clear Output Register */
#define GPIO_PCOR_PTCO_MASK                      (0xFFFFFFFFU)
#define GPIO_PCOR_PTCO_SHIFT                     (0U)
#define GPIO_PCOR_PTCO(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PCOR_PTCO_SHIFT)) & GPIO_PCOR_PTCO_MASK)

/*! @name PTOR - Port Toggle Output Register */
#define GPIO_PTOR_PTTO_MASK                      (0xFFFFFFFFU)
#define GPIO_PTOR_PTTO_SHIFT                     (0U)
#define GPIO_PTOR_PTTO(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_PTOR_PTTO_SHIFT)) & GPIO_PTOR_PTTO_MASK)

/*! @name PDIR - Port Data Input Register */
#define GPIO_PDIR_PDI_MASK                       (0xFFFFFFFFU)
#define GPIO_PDIR_PDI_SHIFT                      (0U)
#define GPIO_PDIR_PDI(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_PDIR_PDI_SHIFT)) & GPIO_PDIR_PDI_MASK)

/*! @name PDDR - Port Data Direction Register */
#define GPIO_PDDR_PDD_MASK                       (0xFFFFFFFFU)
#define GPIO_PDDR_PDD_SHIFT                      (0U)
#define GPIO_PDDR_PDD(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_PDDR_PDD_SHIFT)) & GPIO_PDDR_PDD_MASK)


/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                               (0x400FF000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                    ((GPIO_Type *)GPIOA_BASE)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                               (0x400FF040u)
/** Peripheral GPIOB base pointer */
#define GPIOB                                    ((GPIO_Type *)GPIOB_BASE)
/** Peripheral GPIOC base address */
#define GPIOC_BASE                               (0x400FF080u)
/** Peripheral GPIOC base pointer */
#define GPIOC                                    ((GPIO_Type *)GPIOC_BASE)
/** Peripheral GPIOD base address */
#define GPIOD_BASE                               (0x400FF0C0u)
/** Peripheral GPIOD base pointer */
#define GPIOD                                    ((GPIO_Type *)GPIOD_BASE)
/** Peripheral GPIOE base address */
#define GPIOE_BASE                               (0x400FF100u)
/** Peripheral GPIOE base pointer */
#define GPIOE                                    ((GPIO_Type *)GPIOE_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE }

/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- I2S Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Peripheral_Access_Layer I2S Peripheral Access Layer
 * @{
 */

/** I2S - Register Layout Typedef */
typedef struct {
  __IO uint32_t TCSR;                              /**< SAI Transmit Control Register, offset: 0x0 */
  __IO uint32_t TCR1;                              /**< SAI Transmit Configuration 1 Register, offset: 0x4 */
  __IO uint32_t TCR2;                              /**< SAI Transmit Configuration 2 Register, offset: 0x8 */
  __IO uint32_t TCR3;                              /**< SAI Transmit Configuration 3 Register, offset: 0xC */
  __IO uint32_t TCR4;                              /**< SAI Transmit Configuration 4 Register, offset: 0x10 */
  __IO uint32_t TCR5;                              /**< SAI Transmit Configuration 5 Register, offset: 0x14 */
       uint8_t RESERVED_0[8];
  __O  uint32_t TDR[1];                            /**< SAI Transmit Data Register, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[28];
  __I  uint32_t TFR[1];                            /**< SAI Transmit FIFO Register, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_2[28];
  __IO uint32_t TMR;                               /**< SAI Transmit Mask Register, offset: 0x60 */
       uint8_t RESERVED_3[28];
  __IO uint32_t RCSR;                              /**< SAI Receive Control Register, offset: 0x80 */
  __IO uint32_t RCR1;                              /**< SAI Receive Configuration 1 Register, offset: 0x84 */
  __IO uint32_t RCR2;                              /**< SAI Receive Configuration 2 Register, offset: 0x88 */
  __IO uint32_t RCR3;                              /**< SAI Receive Configuration 3 Register, offset: 0x8C */
  __IO uint32_t RCR4;                              /**< SAI Receive Configuration 4 Register, offset: 0x90 */
  __IO uint32_t RCR5;                              /**< SAI Receive Configuration 5 Register, offset: 0x94 */
       uint8_t RESERVED_4[8];
  __I  uint32_t RDR[1];                            /**< SAI Receive Data Register, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_5[28];
  __I  uint32_t RFR[1];                            /**< SAI Receive FIFO Register, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_6[28];
  __IO uint32_t RMR;                               /**< SAI Receive Mask Register, offset: 0xE0 */
       uint8_t RESERVED_7[28];
  __IO uint32_t MCR;                               /**< SAI MCLK Control Register, offset: 0x100 */
  __IO uint32_t MDR;                               /**< SAI MCLK Divide Register, offset: 0x104 */
} I2S_Type;

/* ----------------------------------------------------------------------------
   -- I2S Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Register_Masks I2S Register Masks
 * @{
 */

/*! @name TCSR - SAI Transmit Control Register */
#define I2S_TCSR_FRDE_MASK                       (0x1U)
#define I2S_TCSR_FRDE_SHIFT                      (0U)
#define I2S_TCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRDE_SHIFT)) & I2S_TCSR_FRDE_MASK)
#define I2S_TCSR_FWDE_MASK                       (0x2U)
#define I2S_TCSR_FWDE_SHIFT                      (1U)
#define I2S_TCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWDE_SHIFT)) & I2S_TCSR_FWDE_MASK)
#define I2S_TCSR_FRIE_MASK                       (0x100U)
#define I2S_TCSR_FRIE_SHIFT                      (8U)
#define I2S_TCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRIE_SHIFT)) & I2S_TCSR_FRIE_MASK)
#define I2S_TCSR_FWIE_MASK                       (0x200U)
#define I2S_TCSR_FWIE_SHIFT                      (9U)
#define I2S_TCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWIE_SHIFT)) & I2S_TCSR_FWIE_MASK)
#define I2S_TCSR_FEIE_MASK                       (0x400U)
#define I2S_TCSR_FEIE_SHIFT                      (10U)
#define I2S_TCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FEIE_SHIFT)) & I2S_TCSR_FEIE_MASK)
#define I2S_TCSR_SEIE_MASK                       (0x800U)
#define I2S_TCSR_SEIE_SHIFT                      (11U)
#define I2S_TCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_SEIE_SHIFT)) & I2S_TCSR_SEIE_MASK)
#define I2S_TCSR_WSIE_MASK                       (0x1000U)
#define I2S_TCSR_WSIE_SHIFT                      (12U)
#define I2S_TCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_WSIE_SHIFT)) & I2S_TCSR_WSIE_MASK)
#define I2S_TCSR_FRF_MASK                        (0x10000U)
#define I2S_TCSR_FRF_SHIFT                       (16U)
#define I2S_TCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRF_SHIFT)) & I2S_TCSR_FRF_MASK)
#define I2S_TCSR_FWF_MASK                        (0x20000U)
#define I2S_TCSR_FWF_SHIFT                       (17U)
#define I2S_TCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWF_SHIFT)) & I2S_TCSR_FWF_MASK)
#define I2S_TCSR_FEF_MASK                        (0x40000U)
#define I2S_TCSR_FEF_SHIFT                       (18U)
#define I2S_TCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FEF_SHIFT)) & I2S_TCSR_FEF_MASK)
#define I2S_TCSR_SEF_MASK                        (0x80000U)
#define I2S_TCSR_SEF_SHIFT                       (19U)
#define I2S_TCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_SEF_SHIFT)) & I2S_TCSR_SEF_MASK)
#define I2S_TCSR_WSF_MASK                        (0x100000U)
#define I2S_TCSR_WSF_SHIFT                       (20U)
#define I2S_TCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_WSF_SHIFT)) & I2S_TCSR_WSF_MASK)
#define I2S_TCSR_SR_MASK                         (0x1000000U)
#define I2S_TCSR_SR_SHIFT                        (24U)
#define I2S_TCSR_SR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_SR_SHIFT)) & I2S_TCSR_SR_MASK)
#define I2S_TCSR_FR_MASK                         (0x2000000U)
#define I2S_TCSR_FR_SHIFT                        (25U)
#define I2S_TCSR_FR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FR_SHIFT)) & I2S_TCSR_FR_MASK)
#define I2S_TCSR_BCE_MASK                        (0x10000000U)
#define I2S_TCSR_BCE_SHIFT                       (28U)
#define I2S_TCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_BCE_SHIFT)) & I2S_TCSR_BCE_MASK)
#define I2S_TCSR_DBGE_MASK                       (0x20000000U)
#define I2S_TCSR_DBGE_SHIFT                      (29U)
#define I2S_TCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_DBGE_SHIFT)) & I2S_TCSR_DBGE_MASK)
#define I2S_TCSR_STOPE_MASK                      (0x40000000U)
#define I2S_TCSR_STOPE_SHIFT                     (30U)
#define I2S_TCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_STOPE_SHIFT)) & I2S_TCSR_STOPE_MASK)
#define I2S_TCSR_TE_MASK                         (0x80000000U)
#define I2S_TCSR_TE_SHIFT                        (31U)
#define I2S_TCSR_TE(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_TE_SHIFT)) & I2S_TCSR_TE_MASK)

/*! @name TCR1 - SAI Transmit Configuration 1 Register */
#define I2S_TCR1_TFW_MASK                        (0x7U)
#define I2S_TCR1_TFW_SHIFT                       (0U)
#define I2S_TCR1_TFW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR1_TFW_SHIFT)) & I2S_TCR1_TFW_MASK)

/*! @name TCR2 - SAI Transmit Configuration 2 Register */
#define I2S_TCR2_DIV_MASK                        (0xFFU)
#define I2S_TCR2_DIV_SHIFT                       (0U)
#define I2S_TCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_DIV_SHIFT)) & I2S_TCR2_DIV_MASK)
#define I2S_TCR2_BCD_MASK                        (0x1000000U)
#define I2S_TCR2_BCD_SHIFT                       (24U)
#define I2S_TCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCD_SHIFT)) & I2S_TCR2_BCD_MASK)
#define I2S_TCR2_BCP_MASK                        (0x2000000U)
#define I2S_TCR2_BCP_SHIFT                       (25U)
#define I2S_TCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCP_SHIFT)) & I2S_TCR2_BCP_MASK)
#define I2S_TCR2_MSEL_MASK                       (0xC000000U)
#define I2S_TCR2_MSEL_SHIFT                      (26U)
#define I2S_TCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_MSEL_SHIFT)) & I2S_TCR2_MSEL_MASK)
#define I2S_TCR2_BCI_MASK                        (0x10000000U)
#define I2S_TCR2_BCI_SHIFT                       (28U)
#define I2S_TCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCI_SHIFT)) & I2S_TCR2_BCI_MASK)
#define I2S_TCR2_BCS_MASK                        (0x20000000U)
#define I2S_TCR2_BCS_SHIFT                       (29U)
#define I2S_TCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCS_SHIFT)) & I2S_TCR2_BCS_MASK)
#define I2S_TCR2_SYNC_MASK                       (0xC0000000U)
#define I2S_TCR2_SYNC_SHIFT                      (30U)
#define I2S_TCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_SYNC_SHIFT)) & I2S_TCR2_SYNC_MASK)

/*! @name TCR3 - SAI Transmit Configuration 3 Register */
#define I2S_TCR3_WDFL_MASK                       (0xFU)
#define I2S_TCR3_WDFL_SHIFT                      (0U)
#define I2S_TCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR3_WDFL_SHIFT)) & I2S_TCR3_WDFL_MASK)
#define I2S_TCR3_TCE_MASK                        (0x10000U)
#define I2S_TCR3_TCE_SHIFT                       (16U)
#define I2S_TCR3_TCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR3_TCE_SHIFT)) & I2S_TCR3_TCE_MASK)

/*! @name TCR4 - SAI Transmit Configuration 4 Register */
#define I2S_TCR4_FSD_MASK                        (0x1U)
#define I2S_TCR4_FSD_SHIFT                       (0U)
#define I2S_TCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSD_SHIFT)) & I2S_TCR4_FSD_MASK)
#define I2S_TCR4_FSP_MASK                        (0x2U)
#define I2S_TCR4_FSP_SHIFT                       (1U)
#define I2S_TCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSP_SHIFT)) & I2S_TCR4_FSP_MASK)
#define I2S_TCR4_ONDEM_MASK                      (0x4U)
#define I2S_TCR4_ONDEM_SHIFT                     (2U)
#define I2S_TCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_ONDEM_SHIFT)) & I2S_TCR4_ONDEM_MASK)
#define I2S_TCR4_FSE_MASK                        (0x8U)
#define I2S_TCR4_FSE_SHIFT                       (3U)
#define I2S_TCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSE_SHIFT)) & I2S_TCR4_FSE_MASK)
#define I2S_TCR4_MF_MASK                         (0x10U)
#define I2S_TCR4_MF_SHIFT                        (4U)
#define I2S_TCR4_MF(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_MF_SHIFT)) & I2S_TCR4_MF_MASK)
#define I2S_TCR4_SYWD_MASK                       (0x1F00U)
#define I2S_TCR4_SYWD_SHIFT                      (8U)
#define I2S_TCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_SYWD_SHIFT)) & I2S_TCR4_SYWD_MASK)
#define I2S_TCR4_FRSZ_MASK                       (0xF0000U)
#define I2S_TCR4_FRSZ_SHIFT                      (16U)
#define I2S_TCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FRSZ_SHIFT)) & I2S_TCR4_FRSZ_MASK)
#define I2S_TCR4_FPACK_MASK                      (0x3000000U)
#define I2S_TCR4_FPACK_SHIFT                     (24U)
#define I2S_TCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FPACK_SHIFT)) & I2S_TCR4_FPACK_MASK)
#define I2S_TCR4_FCONT_MASK                      (0x10000000U)
#define I2S_TCR4_FCONT_SHIFT                     (28U)
#define I2S_TCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FCONT_SHIFT)) & I2S_TCR4_FCONT_MASK)

/*! @name TCR5 - SAI Transmit Configuration 5 Register */
#define I2S_TCR5_FBT_MASK                        (0x1F00U)
#define I2S_TCR5_FBT_SHIFT                       (8U)
#define I2S_TCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_FBT_SHIFT)) & I2S_TCR5_FBT_MASK)
#define I2S_TCR5_W0W_MASK                        (0x1F0000U)
#define I2S_TCR5_W0W_SHIFT                       (16U)
#define I2S_TCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_W0W_SHIFT)) & I2S_TCR5_W0W_MASK)
#define I2S_TCR5_WNW_MASK                        (0x1F000000U)
#define I2S_TCR5_WNW_SHIFT                       (24U)
#define I2S_TCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_WNW_SHIFT)) & I2S_TCR5_WNW_MASK)

/*! @name TDR - SAI Transmit Data Register */
#define I2S_TDR_TDR_MASK                         (0xFFFFFFFFU)
#define I2S_TDR_TDR_SHIFT                        (0U)
#define I2S_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TDR_TDR_SHIFT)) & I2S_TDR_TDR_MASK)

/* The count of I2S_TDR */
#define I2S_TDR_COUNT                            (1U)

/*! @name TFR - SAI Transmit FIFO Register */
#define I2S_TFR_RFP_MASK                         (0xFU)
#define I2S_TFR_RFP_SHIFT                        (0U)
#define I2S_TFR_RFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TFR_RFP_SHIFT)) & I2S_TFR_RFP_MASK)
#define I2S_TFR_WFP_MASK                         (0xF0000U)
#define I2S_TFR_WFP_SHIFT                        (16U)
#define I2S_TFR_WFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TFR_WFP_SHIFT)) & I2S_TFR_WFP_MASK)

/* The count of I2S_TFR */
#define I2S_TFR_COUNT                            (1U)

/*! @name TMR - SAI Transmit Mask Register */
#define I2S_TMR_TWM_MASK                         (0xFFFFU)
#define I2S_TMR_TWM_SHIFT                        (0U)
#define I2S_TMR_TWM(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TMR_TWM_SHIFT)) & I2S_TMR_TWM_MASK)

/*! @name RCSR - SAI Receive Control Register */
#define I2S_RCSR_FRDE_MASK                       (0x1U)
#define I2S_RCSR_FRDE_SHIFT                      (0U)
#define I2S_RCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRDE_SHIFT)) & I2S_RCSR_FRDE_MASK)
#define I2S_RCSR_FWDE_MASK                       (0x2U)
#define I2S_RCSR_FWDE_SHIFT                      (1U)
#define I2S_RCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWDE_SHIFT)) & I2S_RCSR_FWDE_MASK)
#define I2S_RCSR_FRIE_MASK                       (0x100U)
#define I2S_RCSR_FRIE_SHIFT                      (8U)
#define I2S_RCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRIE_SHIFT)) & I2S_RCSR_FRIE_MASK)
#define I2S_RCSR_FWIE_MASK                       (0x200U)
#define I2S_RCSR_FWIE_SHIFT                      (9U)
#define I2S_RCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWIE_SHIFT)) & I2S_RCSR_FWIE_MASK)
#define I2S_RCSR_FEIE_MASK                       (0x400U)
#define I2S_RCSR_FEIE_SHIFT                      (10U)
#define I2S_RCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FEIE_SHIFT)) & I2S_RCSR_FEIE_MASK)
#define I2S_RCSR_SEIE_MASK                       (0x800U)
#define I2S_RCSR_SEIE_SHIFT                      (11U)
#define I2S_RCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SEIE_SHIFT)) & I2S_RCSR_SEIE_MASK)
#define I2S_RCSR_WSIE_MASK                       (0x1000U)
#define I2S_RCSR_WSIE_SHIFT                      (12U)
#define I2S_RCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_WSIE_SHIFT)) & I2S_RCSR_WSIE_MASK)
#define I2S_RCSR_FRF_MASK                        (0x10000U)
#define I2S_RCSR_FRF_SHIFT                       (16U)
#define I2S_RCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRF_SHIFT)) & I2S_RCSR_FRF_MASK)
#define I2S_RCSR_FWF_MASK                        (0x20000U)
#define I2S_RCSR_FWF_SHIFT                       (17U)
#define I2S_RCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWF_SHIFT)) & I2S_RCSR_FWF_MASK)
#define I2S_RCSR_FEF_MASK                        (0x40000U)
#define I2S_RCSR_FEF_SHIFT                       (18U)
#define I2S_RCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FEF_SHIFT)) & I2S_RCSR_FEF_MASK)
#define I2S_RCSR_SEF_MASK                        (0x80000U)
#define I2S_RCSR_SEF_SHIFT                       (19U)
#define I2S_RCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SEF_SHIFT)) & I2S_RCSR_SEF_MASK)
#define I2S_RCSR_WSF_MASK                        (0x100000U)
#define I2S_RCSR_WSF_SHIFT                       (20U)
#define I2S_RCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_WSF_SHIFT)) & I2S_RCSR_WSF_MASK)
#define I2S_RCSR_SR_MASK                         (0x1000000U)
#define I2S_RCSR_SR_SHIFT                        (24U)
#define I2S_RCSR_SR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SR_SHIFT)) & I2S_RCSR_SR_MASK)
#define I2S_RCSR_FR_MASK                         (0x2000000U)
#define I2S_RCSR_FR_SHIFT                        (25U)
#define I2S_RCSR_FR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FR_SHIFT)) & I2S_RCSR_FR_MASK)
#define I2S_RCSR_BCE_MASK                        (0x10000000U)
#define I2S_RCSR_BCE_SHIFT                       (28U)
#define I2S_RCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_BCE_SHIFT)) & I2S_RCSR_BCE_MASK)
#define I2S_RCSR_DBGE_MASK                       (0x20000000U)
#define I2S_RCSR_DBGE_SHIFT                      (29U)
#define I2S_RCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_DBGE_SHIFT)) & I2S_RCSR_DBGE_MASK)
#define I2S_RCSR_STOPE_MASK                      (0x40000000U)
#define I2S_RCSR_STOPE_SHIFT                     (30U)
#define I2S_RCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_STOPE_SHIFT)) & I2S_RCSR_STOPE_MASK)
#define I2S_RCSR_RE_MASK                         (0x80000000U)
#define I2S_RCSR_RE_SHIFT                        (31U)
#define I2S_RCSR_RE(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_RE_SHIFT)) & I2S_RCSR_RE_MASK)

/*! @name RCR1 - SAI Receive Configuration 1 Register */
#define I2S_RCR1_RFW_MASK                        (0x7U)
#define I2S_RCR1_RFW_SHIFT                       (0U)
#define I2S_RCR1_RFW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR1_RFW_SHIFT)) & I2S_RCR1_RFW_MASK)

/*! @name RCR2 - SAI Receive Configuration 2 Register */
#define I2S_RCR2_DIV_MASK                        (0xFFU)
#define I2S_RCR2_DIV_SHIFT                       (0U)
#define I2S_RCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_DIV_SHIFT)) & I2S_RCR2_DIV_MASK)
#define I2S_RCR2_BCD_MASK                        (0x1000000U)
#define I2S_RCR2_BCD_SHIFT                       (24U)
#define I2S_RCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCD_SHIFT)) & I2S_RCR2_BCD_MASK)
#define I2S_RCR2_BCP_MASK                        (0x2000000U)
#define I2S_RCR2_BCP_SHIFT                       (25U)
#define I2S_RCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCP_SHIFT)) & I2S_RCR2_BCP_MASK)
#define I2S_RCR2_MSEL_MASK                       (0xC000000U)
#define I2S_RCR2_MSEL_SHIFT                      (26U)
#define I2S_RCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_MSEL_SHIFT)) & I2S_RCR2_MSEL_MASK)
#define I2S_RCR2_BCI_MASK                        (0x10000000U)
#define I2S_RCR2_BCI_SHIFT                       (28U)
#define I2S_RCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCI_SHIFT)) & I2S_RCR2_BCI_MASK)
#define I2S_RCR2_BCS_MASK                        (0x20000000U)
#define I2S_RCR2_BCS_SHIFT                       (29U)
#define I2S_RCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCS_SHIFT)) & I2S_RCR2_BCS_MASK)
#define I2S_RCR2_SYNC_MASK                       (0xC0000000U)
#define I2S_RCR2_SYNC_SHIFT                      (30U)
#define I2S_RCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_SYNC_SHIFT)) & I2S_RCR2_SYNC_MASK)

/*! @name RCR3 - SAI Receive Configuration 3 Register */
#define I2S_RCR3_WDFL_MASK                       (0xFU)
#define I2S_RCR3_WDFL_SHIFT                      (0U)
#define I2S_RCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR3_WDFL_SHIFT)) & I2S_RCR3_WDFL_MASK)
#define I2S_RCR3_RCE_MASK                        (0x10000U)
#define I2S_RCR3_RCE_SHIFT                       (16U)
#define I2S_RCR3_RCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR3_RCE_SHIFT)) & I2S_RCR3_RCE_MASK)

/*! @name RCR4 - SAI Receive Configuration 4 Register */
#define I2S_RCR4_FSD_MASK                        (0x1U)
#define I2S_RCR4_FSD_SHIFT                       (0U)
#define I2S_RCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSD_SHIFT)) & I2S_RCR4_FSD_MASK)
#define I2S_RCR4_FSP_MASK                        (0x2U)
#define I2S_RCR4_FSP_SHIFT                       (1U)
#define I2S_RCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSP_SHIFT)) & I2S_RCR4_FSP_MASK)
#define I2S_RCR4_ONDEM_MASK                      (0x4U)
#define I2S_RCR4_ONDEM_SHIFT                     (2U)
#define I2S_RCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_ONDEM_SHIFT)) & I2S_RCR4_ONDEM_MASK)
#define I2S_RCR4_FSE_MASK                        (0x8U)
#define I2S_RCR4_FSE_SHIFT                       (3U)
#define I2S_RCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSE_SHIFT)) & I2S_RCR4_FSE_MASK)
#define I2S_RCR4_MF_MASK                         (0x10U)
#define I2S_RCR4_MF_SHIFT                        (4U)
#define I2S_RCR4_MF(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_MF_SHIFT)) & I2S_RCR4_MF_MASK)
#define I2S_RCR4_SYWD_MASK                       (0x1F00U)
#define I2S_RCR4_SYWD_SHIFT                      (8U)
#define I2S_RCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_SYWD_SHIFT)) & I2S_RCR4_SYWD_MASK)
#define I2S_RCR4_FRSZ_MASK                       (0xF0000U)
#define I2S_RCR4_FRSZ_SHIFT                      (16U)
#define I2S_RCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FRSZ_SHIFT)) & I2S_RCR4_FRSZ_MASK)
#define I2S_RCR4_FPACK_MASK                      (0x3000000U)
#define I2S_RCR4_FPACK_SHIFT                     (24U)
#define I2S_RCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FPACK_SHIFT)) & I2S_RCR4_FPACK_MASK)
#define I2S_RCR4_FCONT_MASK                      (0x10000000U)
#define I2S_RCR4_FCONT_SHIFT                     (28U)
#define I2S_RCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FCONT_SHIFT)) & I2S_RCR4_FCONT_MASK)

/*! @name RCR5 - SAI Receive Configuration 5 Register */
#define I2S_RCR5_FBT_MASK                        (0x1F00U)
#define I2S_RCR5_FBT_SHIFT                       (8U)
#define I2S_RCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_FBT_SHIFT)) & I2S_RCR5_FBT_MASK)
#define I2S_RCR5_W0W_MASK                        (0x1F0000U)
#define I2S_RCR5_W0W_SHIFT                       (16U)
#define I2S_RCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_W0W_SHIFT)) & I2S_RCR5_W0W_MASK)
#define I2S_RCR5_WNW_MASK                        (0x1F000000U)
#define I2S_RCR5_WNW_SHIFT                       (24U)
#define I2S_RCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_WNW_SHIFT)) & I2S_RCR5_WNW_MASK)

/*! @name RDR - SAI Receive Data Register */
#define I2S_RDR_RDR_MASK                         (0xFFFFFFFFU)
#define I2S_RDR_RDR_SHIFT                        (0U)
#define I2S_RDR_RDR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RDR_RDR_SHIFT)) & I2S_RDR_RDR_MASK)

/* The count of I2S_RDR */
#define I2S_RDR_COUNT                            (1U)

/*! @name RFR - SAI Receive FIFO Register */
#define I2S_RFR_RFP_MASK                         (0xFU)
#define I2S_RFR_RFP_SHIFT                        (0U)
#define I2S_RFR_RFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RFR_RFP_SHIFT)) & I2S_RFR_RFP_MASK)
#define I2S_RFR_WFP_MASK                         (0xF0000U)
#define I2S_RFR_WFP_SHIFT                        (16U)
#define I2S_RFR_WFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RFR_WFP_SHIFT)) & I2S_RFR_WFP_MASK)

/* The count of I2S_RFR */
#define I2S_RFR_COUNT                            (1U)

/*! @name RMR - SAI Receive Mask Register */
#define I2S_RMR_RWM_MASK                         (0xFFFFU)
#define I2S_RMR_RWM_SHIFT                        (0U)
#define I2S_RMR_RWM(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RMR_RWM_SHIFT)) & I2S_RMR_RWM_MASK)

/*! @name MCR - SAI MCLK Control Register */
#define I2S_MCR_MICS_MASK                        (0x3000000U)
#define I2S_MCR_MICS_SHIFT                       (24U)
#define I2S_MCR_MICS(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_MCR_MICS_SHIFT)) & I2S_MCR_MICS_MASK)
#define I2S_MCR_MOE_MASK                         (0x40000000U)
#define I2S_MCR_MOE_SHIFT                        (30U)
#define I2S_MCR_MOE(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_MCR_MOE_SHIFT)) & I2S_MCR_MOE_MASK)
#define I2S_MCR_DUF_MASK                         (0x80000000U)
#define I2S_MCR_DUF_SHIFT                        (31U)
#define I2S_MCR_DUF(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_MCR_DUF_SHIFT)) & I2S_MCR_DUF_MASK)

/*! @name MDR - SAI MCLK Divide Register */
#define I2S_MDR_DIVIDE_MASK                      (0xFFFU)
#define I2S_MDR_DIVIDE_SHIFT                     (0U)
#define I2S_MDR_DIVIDE(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_MDR_DIVIDE_SHIFT)) & I2S_MDR_DIVIDE_MASK)
#define I2S_MDR_FRACT_MASK                       (0xFF000U)
#define I2S_MDR_FRACT_SHIFT                      (12U)
#define I2S_MDR_FRACT(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_MDR_FRACT_SHIFT)) & I2S_MDR_FRACT_MASK)


/*!
 * @}
 */ /* end of group I2S_Register_Masks */


/* I2S - Peripheral instance base addresses */
/** Peripheral I2S0 base address */
#define I2S0_BASE                                (0x4002F000u)
/** Peripheral I2S0 base pointer */
#define I2S0                                     ((I2S_Type *)I2S0_BASE)
/** Peripheral I2S1 base address */
#define I2S1_BASE                                (0x40030000u)
/** Peripheral I2S1 base pointer */
#define I2S1                                     ((I2S_Type *)I2S1_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { I2S0_BASE, I2S1_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { I2S0, I2S1 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { I2S0_Rx_IRQn, I2S1_Rx_IRQn }
#define I2S_TX_IRQS                              { I2S0_Tx_IRQn, I2S1_Tx_IRQn }

/*!
 * @}
 */ /* end of group I2S_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LLWU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Peripheral_Access_Layer LLWU Peripheral Access Layer
 * @{
 */

/** LLWU - Register Layout Typedef */
typedef struct {
  __IO uint8_t PE1;                                /**< LLWU Pin Enable 1 register, offset: 0x0 */
  __IO uint8_t PE2;                                /**< LLWU Pin Enable 2 register, offset: 0x1 */
  __IO uint8_t PE3;                                /**< LLWU Pin Enable 3 register, offset: 0x2 */
  __IO uint8_t PE4;                                /**< LLWU Pin Enable 4 register, offset: 0x3 */
  __IO uint8_t PE5;                                /**< LLWU Pin Enable 5 register, offset: 0x4 */
  __IO uint8_t PE6;                                /**< LLWU Pin Enable 6 register, offset: 0x5 */
  __IO uint8_t PE7;                                /**< LLWU Pin Enable 7 register, offset: 0x6 */
  __IO uint8_t PE8;                                /**< LLWU Pin Enable 8 register, offset: 0x7 */
  __IO uint8_t ME;                                 /**< LLWU Module Enable register, offset: 0x8 */
  __IO uint8_t PF1;                                /**< LLWU Pin Flag 1 register, offset: 0x9 */
  __IO uint8_t PF2;                                /**< LLWU Pin Flag 2 register, offset: 0xA */
  __IO uint8_t PF3;                                /**< LLWU Pin Flag 3 register, offset: 0xB */
  __IO uint8_t PF4;                                /**< LLWU Pin Flag 4 register, offset: 0xC */
  __I  uint8_t MF5;                                /**< LLWU Module Flag 5 register, offset: 0xD */
  __IO uint8_t FILT1;                              /**< LLWU Pin Filter 1 register, offset: 0xE */
  __IO uint8_t FILT2;                              /**< LLWU Pin Filter 2 register, offset: 0xF */
} LLWU_Type;

/* ----------------------------------------------------------------------------
   -- LLWU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Register_Masks LLWU Register Masks
 * @{
 */

/*! @name PE1 - LLWU Pin Enable 1 register */
#define LLWU_PE1_WUPE0_MASK                      (0x3U)
#define LLWU_PE1_WUPE0_SHIFT                     (0U)
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE1_WUPE0_SHIFT)) & LLWU_PE1_WUPE0_MASK)
#define LLWU_PE1_WUPE1_MASK                      (0xCU)
#define LLWU_PE1_WUPE1_SHIFT                     (2U)
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE1_WUPE1_SHIFT)) & LLWU_PE1_WUPE1_MASK)
#define LLWU_PE1_WUPE2_MASK                      (0x30U)
#define LLWU_PE1_WUPE2_SHIFT                     (4U)
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE1_WUPE2_SHIFT)) & LLWU_PE1_WUPE2_MASK)
#define LLWU_PE1_WUPE3_MASK                      (0xC0U)
#define LLWU_PE1_WUPE3_SHIFT                     (6U)
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE1_WUPE3_SHIFT)) & LLWU_PE1_WUPE3_MASK)

/*! @name PE2 - LLWU Pin Enable 2 register */
#define LLWU_PE2_WUPE4_MASK                      (0x3U)
#define LLWU_PE2_WUPE4_SHIFT                     (0U)
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE2_WUPE4_SHIFT)) & LLWU_PE2_WUPE4_MASK)
#define LLWU_PE2_WUPE5_MASK                      (0xCU)
#define LLWU_PE2_WUPE5_SHIFT                     (2U)
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE2_WUPE5_SHIFT)) & LLWU_PE2_WUPE5_MASK)
#define LLWU_PE2_WUPE6_MASK                      (0x30U)
#define LLWU_PE2_WUPE6_SHIFT                     (4U)
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE2_WUPE6_SHIFT)) & LLWU_PE2_WUPE6_MASK)
#define LLWU_PE2_WUPE7_MASK                      (0xC0U)
#define LLWU_PE2_WUPE7_SHIFT                     (6U)
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE2_WUPE7_SHIFT)) & LLWU_PE2_WUPE7_MASK)

/*! @name PE3 - LLWU Pin Enable 3 register */
#define LLWU_PE3_WUPE8_MASK                      (0x3U)
#define LLWU_PE3_WUPE8_SHIFT                     (0U)
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE3_WUPE8_SHIFT)) & LLWU_PE3_WUPE8_MASK)
#define LLWU_PE3_WUPE9_MASK                      (0xCU)
#define LLWU_PE3_WUPE9_SHIFT                     (2U)
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE3_WUPE9_SHIFT)) & LLWU_PE3_WUPE9_MASK)
#define LLWU_PE3_WUPE10_MASK                     (0x30U)
#define LLWU_PE3_WUPE10_SHIFT                    (4U)
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE3_WUPE10_SHIFT)) & LLWU_PE3_WUPE10_MASK)
#define LLWU_PE3_WUPE11_MASK                     (0xC0U)
#define LLWU_PE3_WUPE11_SHIFT                    (6U)
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE3_WUPE11_SHIFT)) & LLWU_PE3_WUPE11_MASK)

/*! @name PE4 - LLWU Pin Enable 4 register */
#define LLWU_PE4_WUPE12_MASK                     (0x3U)
#define LLWU_PE4_WUPE12_SHIFT                    (0U)
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE4_WUPE12_SHIFT)) & LLWU_PE4_WUPE12_MASK)
#define LLWU_PE4_WUPE13_MASK                     (0xCU)
#define LLWU_PE4_WUPE13_SHIFT                    (2U)
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE4_WUPE13_SHIFT)) & LLWU_PE4_WUPE13_MASK)
#define LLWU_PE4_WUPE14_MASK                     (0x30U)
#define LLWU_PE4_WUPE14_SHIFT                    (4U)
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE4_WUPE14_SHIFT)) & LLWU_PE4_WUPE14_MASK)
#define LLWU_PE4_WUPE15_MASK                     (0xC0U)
#define LLWU_PE4_WUPE15_SHIFT                    (6U)
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE4_WUPE15_SHIFT)) & LLWU_PE4_WUPE15_MASK)

/*! @name PE5 - LLWU Pin Enable 5 register */
#define LLWU_PE5_WUPE16_MASK                     (0x3U)
#define LLWU_PE5_WUPE16_SHIFT                    (0U)
#define LLWU_PE5_WUPE16(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE5_WUPE16_SHIFT)) & LLWU_PE5_WUPE16_MASK)
#define LLWU_PE5_WUPE17_MASK                     (0xCU)
#define LLWU_PE5_WUPE17_SHIFT                    (2U)
#define LLWU_PE5_WUPE17(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE5_WUPE17_SHIFT)) & LLWU_PE5_WUPE17_MASK)
#define LLWU_PE5_WUPE18_MASK                     (0x30U)
#define LLWU_PE5_WUPE18_SHIFT                    (4U)
#define LLWU_PE5_WUPE18(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE5_WUPE18_SHIFT)) & LLWU_PE5_WUPE18_MASK)
#define LLWU_PE5_WUPE19_MASK                     (0xC0U)
#define LLWU_PE5_WUPE19_SHIFT                    (6U)
#define LLWU_PE5_WUPE19(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE5_WUPE19_SHIFT)) & LLWU_PE5_WUPE19_MASK)

/*! @name PE6 - LLWU Pin Enable 6 register */
#define LLWU_PE6_WUPE20_MASK                     (0x3U)
#define LLWU_PE6_WUPE20_SHIFT                    (0U)
#define LLWU_PE6_WUPE20(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE6_WUPE20_SHIFT)) & LLWU_PE6_WUPE20_MASK)
#define LLWU_PE6_WUPE21_MASK                     (0xCU)
#define LLWU_PE6_WUPE21_SHIFT                    (2U)
#define LLWU_PE6_WUPE21(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE6_WUPE21_SHIFT)) & LLWU_PE6_WUPE21_MASK)
#define LLWU_PE6_WUPE22_MASK                     (0x30U)
#define LLWU_PE6_WUPE22_SHIFT                    (4U)
#define LLWU_PE6_WUPE22(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE6_WUPE22_SHIFT)) & LLWU_PE6_WUPE22_MASK)
#define LLWU_PE6_WUPE23_MASK                     (0xC0U)
#define LLWU_PE6_WUPE23_SHIFT                    (6U)
#define LLWU_PE6_WUPE23(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE6_WUPE23_SHIFT)) & LLWU_PE6_WUPE23_MASK)

/*! @name PE7 - LLWU Pin Enable 7 register */
#define LLWU_PE7_WUPE24_MASK                     (0x3U)
#define LLWU_PE7_WUPE24_SHIFT                    (0U)
#define LLWU_PE7_WUPE24(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE7_WUPE24_SHIFT)) & LLWU_PE7_WUPE24_MASK)
#define LLWU_PE7_WUPE25_MASK                     (0xCU)
#define LLWU_PE7_WUPE25_SHIFT                    (2U)
#define LLWU_PE7_WUPE25(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE7_WUPE25_SHIFT)) & LLWU_PE7_WUPE25_MASK)
#define LLWU_PE7_WUPE26_MASK                     (0x30U)
#define LLWU_PE7_WUPE26_SHIFT                    (4U)
#define LLWU_PE7_WUPE26(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE7_WUPE26_SHIFT)) & LLWU_PE7_WUPE26_MASK)
#define LLWU_PE7_WUPE27_MASK                     (0xC0U)
#define LLWU_PE7_WUPE27_SHIFT                    (6U)
#define LLWU_PE7_WUPE27(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE7_WUPE27_SHIFT)) & LLWU_PE7_WUPE27_MASK)

/*! @name PE8 - LLWU Pin Enable 8 register */
#define LLWU_PE8_WUPE28_MASK                     (0x3U)
#define LLWU_PE8_WUPE28_SHIFT                    (0U)
#define LLWU_PE8_WUPE28(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE8_WUPE28_SHIFT)) & LLWU_PE8_WUPE28_MASK)
#define LLWU_PE8_WUPE29_MASK                     (0xCU)
#define LLWU_PE8_WUPE29_SHIFT                    (2U)
#define LLWU_PE8_WUPE29(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE8_WUPE29_SHIFT)) & LLWU_PE8_WUPE29_MASK)
#define LLWU_PE8_WUPE30_MASK                     (0x30U)
#define LLWU_PE8_WUPE30_SHIFT                    (4U)
#define LLWU_PE8_WUPE30(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE8_WUPE30_SHIFT)) & LLWU_PE8_WUPE30_MASK)
#define LLWU_PE8_WUPE31_MASK                     (0xC0U)
#define LLWU_PE8_WUPE31_SHIFT                    (6U)
#define LLWU_PE8_WUPE31(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE8_WUPE31_SHIFT)) & LLWU_PE8_WUPE31_MASK)

/*! @name ME - LLWU Module Enable register */
#define LLWU_ME_WUME0_MASK                       (0x1U)
#define LLWU_ME_WUME0_SHIFT                      (0U)
#define LLWU_ME_WUME0(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME0_SHIFT)) & LLWU_ME_WUME0_MASK)
#define LLWU_ME_WUME1_MASK                       (0x2U)
#define LLWU_ME_WUME1_SHIFT                      (1U)
#define LLWU_ME_WUME1(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME1_SHIFT)) & LLWU_ME_WUME1_MASK)
#define LLWU_ME_WUME2_MASK                       (0x4U)
#define LLWU_ME_WUME2_SHIFT                      (2U)
#define LLWU_ME_WUME2(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME2_SHIFT)) & LLWU_ME_WUME2_MASK)
#define LLWU_ME_WUME3_MASK                       (0x8U)
#define LLWU_ME_WUME3_SHIFT                      (3U)
#define LLWU_ME_WUME3(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME3_SHIFT)) & LLWU_ME_WUME3_MASK)
#define LLWU_ME_WUME4_MASK                       (0x10U)
#define LLWU_ME_WUME4_SHIFT                      (4U)
#define LLWU_ME_WUME4(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME4_SHIFT)) & LLWU_ME_WUME4_MASK)
#define LLWU_ME_WUME5_MASK                       (0x20U)
#define LLWU_ME_WUME5_SHIFT                      (5U)
#define LLWU_ME_WUME5(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME5_SHIFT)) & LLWU_ME_WUME5_MASK)
#define LLWU_ME_WUME6_MASK                       (0x40U)
#define LLWU_ME_WUME6_SHIFT                      (6U)
#define LLWU_ME_WUME6(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME6_SHIFT)) & LLWU_ME_WUME6_MASK)
#define LLWU_ME_WUME7_MASK                       (0x80U)
#define LLWU_ME_WUME7_SHIFT                      (7U)
#define LLWU_ME_WUME7(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME7_SHIFT)) & LLWU_ME_WUME7_MASK)

/*! @name PF1 - LLWU Pin Flag 1 register */
#define LLWU_PF1_WUF0_MASK                       (0x1U)
#define LLWU_PF1_WUF0_SHIFT                      (0U)
#define LLWU_PF1_WUF0(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF0_SHIFT)) & LLWU_PF1_WUF0_MASK)
#define LLWU_PF1_WUF1_MASK                       (0x2U)
#define LLWU_PF1_WUF1_SHIFT                      (1U)
#define LLWU_PF1_WUF1(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF1_SHIFT)) & LLWU_PF1_WUF1_MASK)
#define LLWU_PF1_WUF2_MASK                       (0x4U)
#define LLWU_PF1_WUF2_SHIFT                      (2U)
#define LLWU_PF1_WUF2(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF2_SHIFT)) & LLWU_PF1_WUF2_MASK)
#define LLWU_PF1_WUF3_MASK                       (0x8U)
#define LLWU_PF1_WUF3_SHIFT                      (3U)
#define LLWU_PF1_WUF3(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF3_SHIFT)) & LLWU_PF1_WUF3_MASK)
#define LLWU_PF1_WUF4_MASK                       (0x10U)
#define LLWU_PF1_WUF4_SHIFT                      (4U)
#define LLWU_PF1_WUF4(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF4_SHIFT)) & LLWU_PF1_WUF4_MASK)
#define LLWU_PF1_WUF5_MASK                       (0x20U)
#define LLWU_PF1_WUF5_SHIFT                      (5U)
#define LLWU_PF1_WUF5(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF5_SHIFT)) & LLWU_PF1_WUF5_MASK)
#define LLWU_PF1_WUF6_MASK                       (0x40U)
#define LLWU_PF1_WUF6_SHIFT                      (6U)
#define LLWU_PF1_WUF6(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF6_SHIFT)) & LLWU_PF1_WUF6_MASK)
#define LLWU_PF1_WUF7_MASK                       (0x80U)
#define LLWU_PF1_WUF7_SHIFT                      (7U)
#define LLWU_PF1_WUF7(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF7_SHIFT)) & LLWU_PF1_WUF7_MASK)

/*! @name PF2 - LLWU Pin Flag 2 register */
#define LLWU_PF2_WUF8_MASK                       (0x1U)
#define LLWU_PF2_WUF8_SHIFT                      (0U)
#define LLWU_PF2_WUF8(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF8_SHIFT)) & LLWU_PF2_WUF8_MASK)
#define LLWU_PF2_WUF9_MASK                       (0x2U)
#define LLWU_PF2_WUF9_SHIFT                      (1U)
#define LLWU_PF2_WUF9(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF9_SHIFT)) & LLWU_PF2_WUF9_MASK)
#define LLWU_PF2_WUF10_MASK                      (0x4U)
#define LLWU_PF2_WUF10_SHIFT                     (2U)
#define LLWU_PF2_WUF10(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF10_SHIFT)) & LLWU_PF2_WUF10_MASK)
#define LLWU_PF2_WUF11_MASK                      (0x8U)
#define LLWU_PF2_WUF11_SHIFT                     (3U)
#define LLWU_PF2_WUF11(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF11_SHIFT)) & LLWU_PF2_WUF11_MASK)
#define LLWU_PF2_WUF12_MASK                      (0x10U)
#define LLWU_PF2_WUF12_SHIFT                     (4U)
#define LLWU_PF2_WUF12(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF12_SHIFT)) & LLWU_PF2_WUF12_MASK)
#define LLWU_PF2_WUF13_MASK                      (0x20U)
#define LLWU_PF2_WUF13_SHIFT                     (5U)
#define LLWU_PF2_WUF13(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF13_SHIFT)) & LLWU_PF2_WUF13_MASK)
#define LLWU_PF2_WUF14_MASK                      (0x40U)
#define LLWU_PF2_WUF14_SHIFT                     (6U)
#define LLWU_PF2_WUF14(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF14_SHIFT)) & LLWU_PF2_WUF14_MASK)
#define LLWU_PF2_WUF15_MASK                      (0x80U)
#define LLWU_PF2_WUF15_SHIFT                     (7U)
#define LLWU_PF2_WUF15(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF15_SHIFT)) & LLWU_PF2_WUF15_MASK)

/*! @name PF3 - LLWU Pin Flag 3 register */
#define LLWU_PF3_WUF16_MASK                      (0x1U)
#define LLWU_PF3_WUF16_SHIFT                     (0U)
#define LLWU_PF3_WUF16(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF16_SHIFT)) & LLWU_PF3_WUF16_MASK)
#define LLWU_PF3_WUF17_MASK                      (0x2U)
#define LLWU_PF3_WUF17_SHIFT                     (1U)
#define LLWU_PF3_WUF17(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF17_SHIFT)) & LLWU_PF3_WUF17_MASK)
#define LLWU_PF3_WUF18_MASK                      (0x4U)
#define LLWU_PF3_WUF18_SHIFT                     (2U)
#define LLWU_PF3_WUF18(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF18_SHIFT)) & LLWU_PF3_WUF18_MASK)
#define LLWU_PF3_WUF19_MASK                      (0x8U)
#define LLWU_PF3_WUF19_SHIFT                     (3U)
#define LLWU_PF3_WUF19(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF19_SHIFT)) & LLWU_PF3_WUF19_MASK)
#define LLWU_PF3_WUF20_MASK                      (0x10U)
#define LLWU_PF3_WUF20_SHIFT                     (4U)
#define LLWU_PF3_WUF20(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF20_SHIFT)) & LLWU_PF3_WUF20_MASK)
#define LLWU_PF3_WUF21_MASK                      (0x20U)
#define LLWU_PF3_WUF21_SHIFT                     (5U)
#define LLWU_PF3_WUF21(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF21_SHIFT)) & LLWU_PF3_WUF21_MASK)
#define LLWU_PF3_WUF22_MASK                      (0x40U)
#define LLWU_PF3_WUF22_SHIFT                     (6U)
#define LLWU_PF3_WUF22(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF22_SHIFT)) & LLWU_PF3_WUF22_MASK)
#define LLWU_PF3_WUF23_MASK                      (0x80U)
#define LLWU_PF3_WUF23_SHIFT                     (7U)
#define LLWU_PF3_WUF23(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF23_SHIFT)) & LLWU_PF3_WUF23_MASK)

/*! @name PF4 - LLWU Pin Flag 4 register */
#define LLWU_PF4_WUF24_MASK                      (0x1U)
#define LLWU_PF4_WUF24_SHIFT                     (0U)
#define LLWU_PF4_WUF24(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF24_SHIFT)) & LLWU_PF4_WUF24_MASK)
#define LLWU_PF4_WUF25_MASK                      (0x2U)
#define LLWU_PF4_WUF25_SHIFT                     (1U)
#define LLWU_PF4_WUF25(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF25_SHIFT)) & LLWU_PF4_WUF25_MASK)
#define LLWU_PF4_WUF26_MASK                      (0x4U)
#define LLWU_PF4_WUF26_SHIFT                     (2U)
#define LLWU_PF4_WUF26(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF26_SHIFT)) & LLWU_PF4_WUF26_MASK)
#define LLWU_PF4_WUF27_MASK                      (0x8U)
#define LLWU_PF4_WUF27_SHIFT                     (3U)
#define LLWU_PF4_WUF27(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF27_SHIFT)) & LLWU_PF4_WUF27_MASK)
#define LLWU_PF4_WUF28_MASK                      (0x10U)
#define LLWU_PF4_WUF28_SHIFT                     (4U)
#define LLWU_PF4_WUF28(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF28_SHIFT)) & LLWU_PF4_WUF28_MASK)
#define LLWU_PF4_WUF29_MASK                      (0x20U)
#define LLWU_PF4_WUF29_SHIFT                     (5U)
#define LLWU_PF4_WUF29(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF29_SHIFT)) & LLWU_PF4_WUF29_MASK)
#define LLWU_PF4_WUF30_MASK                      (0x40U)
#define LLWU_PF4_WUF30_SHIFT                     (6U)
#define LLWU_PF4_WUF30(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF30_SHIFT)) & LLWU_PF4_WUF30_MASK)
#define LLWU_PF4_WUF31_MASK                      (0x80U)
#define LLWU_PF4_WUF31_SHIFT                     (7U)
#define LLWU_PF4_WUF31(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF31_SHIFT)) & LLWU_PF4_WUF31_MASK)

/*! @name MF5 - LLWU Module Flag 5 register */
#define LLWU_MF5_MWUF0_MASK                      (0x1U)
#define LLWU_MF5_MWUF0_SHIFT                     (0U)
#define LLWU_MF5_MWUF0(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF0_SHIFT)) & LLWU_MF5_MWUF0_MASK)
#define LLWU_MF5_MWUF1_MASK                      (0x2U)
#define LLWU_MF5_MWUF1_SHIFT                     (1U)
#define LLWU_MF5_MWUF1(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF1_SHIFT)) & LLWU_MF5_MWUF1_MASK)
#define LLWU_MF5_MWUF2_MASK                      (0x4U)
#define LLWU_MF5_MWUF2_SHIFT                     (2U)
#define LLWU_MF5_MWUF2(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF2_SHIFT)) & LLWU_MF5_MWUF2_MASK)
#define LLWU_MF5_MWUF3_MASK                      (0x8U)
#define LLWU_MF5_MWUF3_SHIFT                     (3U)
#define LLWU_MF5_MWUF3(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF3_SHIFT)) & LLWU_MF5_MWUF3_MASK)
#define LLWU_MF5_MWUF4_MASK                      (0x10U)
#define LLWU_MF5_MWUF4_SHIFT                     (4U)
#define LLWU_MF5_MWUF4(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF4_SHIFT)) & LLWU_MF5_MWUF4_MASK)
#define LLWU_MF5_MWUF5_MASK                      (0x20U)
#define LLWU_MF5_MWUF5_SHIFT                     (5U)
#define LLWU_MF5_MWUF5(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF5_SHIFT)) & LLWU_MF5_MWUF5_MASK)
#define LLWU_MF5_MWUF6_MASK                      (0x40U)
#define LLWU_MF5_MWUF6_SHIFT                     (6U)
#define LLWU_MF5_MWUF6(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF6_SHIFT)) & LLWU_MF5_MWUF6_MASK)
#define LLWU_MF5_MWUF7_MASK                      (0x80U)
#define LLWU_MF5_MWUF7_SHIFT                     (7U)
#define LLWU_MF5_MWUF7(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF7_SHIFT)) & LLWU_MF5_MWUF7_MASK)

/*! @name FILT1 - LLWU Pin Filter 1 register */
#define LLWU_FILT1_FILTSEL_MASK                  (0x1FU)
#define LLWU_FILT1_FILTSEL_SHIFT                 (0U)
#define LLWU_FILT1_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x)) << LLWU_FILT1_FILTSEL_SHIFT)) & LLWU_FILT1_FILTSEL_MASK)
#define LLWU_FILT1_FILTE_MASK                    (0x60U)
#define LLWU_FILT1_FILTE_SHIFT                   (5U)
#define LLWU_FILT1_FILTE(x)                      (((uint8_t)(((uint8_t)(x)) << LLWU_FILT1_FILTE_SHIFT)) & LLWU_FILT1_FILTE_MASK)
#define LLWU_FILT1_FILTF_MASK                    (0x80U)
#define LLWU_FILT1_FILTF_SHIFT                   (7U)
#define LLWU_FILT1_FILTF(x)                      (((uint8_t)(((uint8_t)(x)) << LLWU_FILT1_FILTF_SHIFT)) & LLWU_FILT1_FILTF_MASK)

/*! @name FILT2 - LLWU Pin Filter 2 register */
#define LLWU_FILT2_FILTSEL_MASK                  (0x1FU)
#define LLWU_FILT2_FILTSEL_SHIFT                 (0U)
#define LLWU_FILT2_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x)) << LLWU_FILT2_FILTSEL_SHIFT)) & LLWU_FILT2_FILTSEL_MASK)
#define LLWU_FILT2_FILTE_MASK                    (0x60U)
#define LLWU_FILT2_FILTE_SHIFT                   (5U)
#define LLWU_FILT2_FILTE(x)                      (((uint8_t)(((uint8_t)(x)) << LLWU_FILT2_FILTE_SHIFT)) & LLWU_FILT2_FILTE_MASK)
#define LLWU_FILT2_FILTF_MASK                    (0x80U)
#define LLWU_FILT2_FILTF_SHIFT                   (7U)
#define LLWU_FILT2_FILTF(x)                      (((uint8_t)(((uint8_t)(x)) << LLWU_FILT2_FILTF_SHIFT)) & LLWU_FILT2_FILTF_MASK)


/*!
 * @}
 */ /* end of group LLWU_Register_Masks */


/* LLWU - Peripheral instance base addresses */
/** Peripheral LLWU base address */
#define LLWU_BASE                                (0x4007C000u)
/** Peripheral LLWU base pointer */
#define LLWU                                     ((LLWU_Type *)LLWU_BASE)
/** Array initializer of LLWU peripheral base addresses */
#define LLWU_BASE_ADDRS                          { LLWU_BASE }
/** Array initializer of LLWU peripheral base pointers */
#define LLWU_BASE_PTRS                           { LLWU }
/** Interrupt vectors for the LLWU peripheral type */
#define LLWU_IRQS                                { LLWU_IRQn }

/*!
 * @}
 */ /* end of group LLWU_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPI2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Peripheral_Access_Layer LPI2C Peripheral Access Layer
 * @{
 */

/** LPI2C - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t MCR;                               /**< Master Control Register, offset: 0x10 */
  __IO uint32_t MSR;                               /**< Master Status Register, offset: 0x14 */
  __IO uint32_t MIER;                              /**< Master Interrupt Enable Register, offset: 0x18 */
  __IO uint32_t MDER;                              /**< Master DMA Enable Register, offset: 0x1C */
  __IO uint32_t MCFGR0;                            /**< Master Configuration Register 0, offset: 0x20 */
  __IO uint32_t MCFGR1;                            /**< Master Configuration Register 1, offset: 0x24 */
  __IO uint32_t MCFGR2;                            /**< Master Configuration Register 2, offset: 0x28 */
  __IO uint32_t MCFGR3;                            /**< Master Configuration Register 3, offset: 0x2C */
       uint8_t RESERVED_1[16];
  __IO uint32_t MDMR;                              /**< Master Data Match Register, offset: 0x40 */
       uint8_t RESERVED_2[4];
  __IO uint32_t MCCR0;                             /**< Master Clock Configuration Register 0, offset: 0x48 */
       uint8_t RESERVED_3[4];
  __IO uint32_t MCCR1;                             /**< Master Clock Configuration Register 1, offset: 0x50 */
       uint8_t RESERVED_4[4];
  __IO uint32_t MFCR;                              /**< Master FIFO Control Register, offset: 0x58 */
  __I  uint32_t MFSR;                              /**< Master FIFO Status Register, offset: 0x5C */
  __O  uint32_t MTDR;                              /**< Master Transmit Data Register, offset: 0x60 */
       uint8_t RESERVED_5[12];
  __I  uint32_t MRDR;                              /**< Master Receive Data Register, offset: 0x70 */
       uint8_t RESERVED_6[156];
  __IO uint32_t SCR;                               /**< Slave Control Register, offset: 0x110 */
  __IO uint32_t SSR;                               /**< Slave Status Register, offset: 0x114 */
  __IO uint32_t SIER;                              /**< Slave Interrupt Enable Register, offset: 0x118 */
  __IO uint32_t SDER;                              /**< Slave DMA Enable Register, offset: 0x11C */
       uint8_t RESERVED_7[4];
  __IO uint32_t SCFGR1;                            /**< Slave Configuration Register 1, offset: 0x124 */
  __IO uint32_t SCFGR2;                            /**< Slave Configuration Register 2, offset: 0x128 */
       uint8_t RESERVED_8[20];
  __IO uint32_t SAMR;                              /**< Slave Address Match Register, offset: 0x140 */
       uint8_t RESERVED_9[12];
  __I  uint32_t SASR;                              /**< Slave Address Status Register, offset: 0x150 */
  __IO uint32_t STAR;                              /**< Slave Transmit ACK Register, offset: 0x154 */
       uint8_t RESERVED_10[8];
  __O  uint32_t STDR;                              /**< Slave Transmit Data Register, offset: 0x160 */
       uint8_t RESERVED_11[12];
  __I  uint32_t SRDR;                              /**< Slave Receive Data Register, offset: 0x170 */
} LPI2C_Type;

/* ----------------------------------------------------------------------------
   -- LPI2C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Register_Masks LPI2C Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
#define LPI2C_VERID_FEATURE_MASK                 (0xFFFFU)
#define LPI2C_VERID_FEATURE_SHIFT                (0U)
#define LPI2C_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << LPI2C_VERID_FEATURE_SHIFT)) & LPI2C_VERID_FEATURE_MASK)
#define LPI2C_VERID_MINOR_MASK                   (0xFF0000U)
#define LPI2C_VERID_MINOR_SHIFT                  (16U)
#define LPI2C_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_VERID_MINOR_SHIFT)) & LPI2C_VERID_MINOR_MASK)
#define LPI2C_VERID_MAJOR_MASK                   (0xFF000000U)
#define LPI2C_VERID_MAJOR_SHIFT                  (24U)
#define LPI2C_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_VERID_MAJOR_SHIFT)) & LPI2C_VERID_MAJOR_MASK)

/*! @name PARAM - Parameter Register */
#define LPI2C_PARAM_MTXFIFO_MASK                 (0xFU)
#define LPI2C_PARAM_MTXFIFO_SHIFT                (0U)
#define LPI2C_PARAM_MTXFIFO(x)                   (((uint32_t)(((uint32_t)(x)) << LPI2C_PARAM_MTXFIFO_SHIFT)) & LPI2C_PARAM_MTXFIFO_MASK)
#define LPI2C_PARAM_MRXFIFO_MASK                 (0xF00U)
#define LPI2C_PARAM_MRXFIFO_SHIFT                (8U)
#define LPI2C_PARAM_MRXFIFO(x)                   (((uint32_t)(((uint32_t)(x)) << LPI2C_PARAM_MRXFIFO_SHIFT)) & LPI2C_PARAM_MRXFIFO_MASK)

/*! @name MCR - Master Control Register */
#define LPI2C_MCR_MEN_MASK                       (0x1U)
#define LPI2C_MCR_MEN_SHIFT                      (0U)
#define LPI2C_MCR_MEN(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MCR_MEN_SHIFT)) & LPI2C_MCR_MEN_MASK)
#define LPI2C_MCR_RST_MASK                       (0x2U)
#define LPI2C_MCR_RST_SHIFT                      (1U)
#define LPI2C_MCR_RST(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MCR_RST_SHIFT)) & LPI2C_MCR_RST_MASK)
#define LPI2C_MCR_DOZEN_MASK                     (0x4U)
#define LPI2C_MCR_DOZEN_SHIFT                    (2U)
#define LPI2C_MCR_DOZEN(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MCR_DOZEN_SHIFT)) & LPI2C_MCR_DOZEN_MASK)
#define LPI2C_MCR_DBGEN_MASK                     (0x8U)
#define LPI2C_MCR_DBGEN_SHIFT                    (3U)
#define LPI2C_MCR_DBGEN(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MCR_DBGEN_SHIFT)) & LPI2C_MCR_DBGEN_MASK)
#define LPI2C_MCR_RTF_MASK                       (0x100U)
#define LPI2C_MCR_RTF_SHIFT                      (8U)
#define LPI2C_MCR_RTF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MCR_RTF_SHIFT)) & LPI2C_MCR_RTF_MASK)
#define LPI2C_MCR_RRF_MASK                       (0x200U)
#define LPI2C_MCR_RRF_SHIFT                      (9U)
#define LPI2C_MCR_RRF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MCR_RRF_SHIFT)) & LPI2C_MCR_RRF_MASK)

/*! @name MSR - Master Status Register */
#define LPI2C_MSR_TDF_MASK                       (0x1U)
#define LPI2C_MSR_TDF_SHIFT                      (0U)
#define LPI2C_MSR_TDF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MSR_TDF_SHIFT)) & LPI2C_MSR_TDF_MASK)
#define LPI2C_MSR_RDF_MASK                       (0x2U)
#define LPI2C_MSR_RDF_SHIFT                      (1U)
#define LPI2C_MSR_RDF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MSR_RDF_SHIFT)) & LPI2C_MSR_RDF_MASK)
#define LPI2C_MSR_EPF_MASK                       (0x100U)
#define LPI2C_MSR_EPF_SHIFT                      (8U)
#define LPI2C_MSR_EPF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MSR_EPF_SHIFT)) & LPI2C_MSR_EPF_MASK)
#define LPI2C_MSR_SDF_MASK                       (0x200U)
#define LPI2C_MSR_SDF_SHIFT                      (9U)
#define LPI2C_MSR_SDF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MSR_SDF_SHIFT)) & LPI2C_MSR_SDF_MASK)
#define LPI2C_MSR_NDF_MASK                       (0x400U)
#define LPI2C_MSR_NDF_SHIFT                      (10U)
#define LPI2C_MSR_NDF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MSR_NDF_SHIFT)) & LPI2C_MSR_NDF_MASK)
#define LPI2C_MSR_ALF_MASK                       (0x800U)
#define LPI2C_MSR_ALF_SHIFT                      (11U)
#define LPI2C_MSR_ALF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MSR_ALF_SHIFT)) & LPI2C_MSR_ALF_MASK)
#define LPI2C_MSR_FEF_MASK                       (0x1000U)
#define LPI2C_MSR_FEF_SHIFT                      (12U)
#define LPI2C_MSR_FEF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MSR_FEF_SHIFT)) & LPI2C_MSR_FEF_MASK)
#define LPI2C_MSR_PLTF_MASK                      (0x2000U)
#define LPI2C_MSR_PLTF_SHIFT                     (13U)
#define LPI2C_MSR_PLTF(x)                        (((uint32_t)(((uint32_t)(x)) << LPI2C_MSR_PLTF_SHIFT)) & LPI2C_MSR_PLTF_MASK)
#define LPI2C_MSR_DMF_MASK                       (0x4000U)
#define LPI2C_MSR_DMF_SHIFT                      (14U)
#define LPI2C_MSR_DMF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MSR_DMF_SHIFT)) & LPI2C_MSR_DMF_MASK)
#define LPI2C_MSR_MBF_MASK                       (0x1000000U)
#define LPI2C_MSR_MBF_SHIFT                      (24U)
#define LPI2C_MSR_MBF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MSR_MBF_SHIFT)) & LPI2C_MSR_MBF_MASK)
#define LPI2C_MSR_BBF_MASK                       (0x2000000U)
#define LPI2C_MSR_BBF_SHIFT                      (25U)
#define LPI2C_MSR_BBF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_MSR_BBF_SHIFT)) & LPI2C_MSR_BBF_MASK)

/*! @name MIER - Master Interrupt Enable Register */
#define LPI2C_MIER_TDIE_MASK                     (0x1U)
#define LPI2C_MIER_TDIE_SHIFT                    (0U)
#define LPI2C_MIER_TDIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MIER_TDIE_SHIFT)) & LPI2C_MIER_TDIE_MASK)
#define LPI2C_MIER_RDIE_MASK                     (0x2U)
#define LPI2C_MIER_RDIE_SHIFT                    (1U)
#define LPI2C_MIER_RDIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MIER_RDIE_SHIFT)) & LPI2C_MIER_RDIE_MASK)
#define LPI2C_MIER_EPIE_MASK                     (0x100U)
#define LPI2C_MIER_EPIE_SHIFT                    (8U)
#define LPI2C_MIER_EPIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MIER_EPIE_SHIFT)) & LPI2C_MIER_EPIE_MASK)
#define LPI2C_MIER_SDIE_MASK                     (0x200U)
#define LPI2C_MIER_SDIE_SHIFT                    (9U)
#define LPI2C_MIER_SDIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MIER_SDIE_SHIFT)) & LPI2C_MIER_SDIE_MASK)
#define LPI2C_MIER_NDIE_MASK                     (0x400U)
#define LPI2C_MIER_NDIE_SHIFT                    (10U)
#define LPI2C_MIER_NDIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MIER_NDIE_SHIFT)) & LPI2C_MIER_NDIE_MASK)
#define LPI2C_MIER_ALIE_MASK                     (0x800U)
#define LPI2C_MIER_ALIE_SHIFT                    (11U)
#define LPI2C_MIER_ALIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MIER_ALIE_SHIFT)) & LPI2C_MIER_ALIE_MASK)
#define LPI2C_MIER_FEIE_MASK                     (0x1000U)
#define LPI2C_MIER_FEIE_SHIFT                    (12U)
#define LPI2C_MIER_FEIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MIER_FEIE_SHIFT)) & LPI2C_MIER_FEIE_MASK)
#define LPI2C_MIER_PLTIE_MASK                    (0x2000U)
#define LPI2C_MIER_PLTIE_SHIFT                   (13U)
#define LPI2C_MIER_PLTIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPI2C_MIER_PLTIE_SHIFT)) & LPI2C_MIER_PLTIE_MASK)
#define LPI2C_MIER_DMIE_MASK                     (0x4000U)
#define LPI2C_MIER_DMIE_SHIFT                    (14U)
#define LPI2C_MIER_DMIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MIER_DMIE_SHIFT)) & LPI2C_MIER_DMIE_MASK)

/*! @name MDER - Master DMA Enable Register */
#define LPI2C_MDER_TDDE_MASK                     (0x1U)
#define LPI2C_MDER_TDDE_SHIFT                    (0U)
#define LPI2C_MDER_TDDE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MDER_TDDE_SHIFT)) & LPI2C_MDER_TDDE_MASK)
#define LPI2C_MDER_RDDE_MASK                     (0x2U)
#define LPI2C_MDER_RDDE_SHIFT                    (1U)
#define LPI2C_MDER_RDDE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MDER_RDDE_SHIFT)) & LPI2C_MDER_RDDE_MASK)

/*! @name MCFGR0 - Master Configuration Register 0 */
#define LPI2C_MCFGR0_HREN_MASK                   (0x1U)
#define LPI2C_MCFGR0_HREN_SHIFT                  (0U)
#define LPI2C_MCFGR0_HREN(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR0_HREN_SHIFT)) & LPI2C_MCFGR0_HREN_MASK)
#define LPI2C_MCFGR0_HRPOL_MASK                  (0x2U)
#define LPI2C_MCFGR0_HRPOL_SHIFT                 (1U)
#define LPI2C_MCFGR0_HRPOL(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR0_HRPOL_SHIFT)) & LPI2C_MCFGR0_HRPOL_MASK)
#define LPI2C_MCFGR0_HRSEL_MASK                  (0x4U)
#define LPI2C_MCFGR0_HRSEL_SHIFT                 (2U)
#define LPI2C_MCFGR0_HRSEL(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR0_HRSEL_SHIFT)) & LPI2C_MCFGR0_HRSEL_MASK)
#define LPI2C_MCFGR0_CIRFIFO_MASK                (0x100U)
#define LPI2C_MCFGR0_CIRFIFO_SHIFT               (8U)
#define LPI2C_MCFGR0_CIRFIFO(x)                  (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR0_CIRFIFO_SHIFT)) & LPI2C_MCFGR0_CIRFIFO_MASK)
#define LPI2C_MCFGR0_RDMO_MASK                   (0x200U)
#define LPI2C_MCFGR0_RDMO_SHIFT                  (9U)
#define LPI2C_MCFGR0_RDMO(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR0_RDMO_SHIFT)) & LPI2C_MCFGR0_RDMO_MASK)

/*! @name MCFGR1 - Master Configuration Register 1 */
#define LPI2C_MCFGR1_PRESCALE_MASK               (0x7U)
#define LPI2C_MCFGR1_PRESCALE_SHIFT              (0U)
#define LPI2C_MCFGR1_PRESCALE(x)                 (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR1_PRESCALE_SHIFT)) & LPI2C_MCFGR1_PRESCALE_MASK)
#define LPI2C_MCFGR1_AUTOSTOP_MASK               (0x100U)
#define LPI2C_MCFGR1_AUTOSTOP_SHIFT              (8U)
#define LPI2C_MCFGR1_AUTOSTOP(x)                 (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR1_AUTOSTOP_SHIFT)) & LPI2C_MCFGR1_AUTOSTOP_MASK)
#define LPI2C_MCFGR1_IGNACK_MASK                 (0x200U)
#define LPI2C_MCFGR1_IGNACK_SHIFT                (9U)
#define LPI2C_MCFGR1_IGNACK(x)                   (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR1_IGNACK_SHIFT)) & LPI2C_MCFGR1_IGNACK_MASK)
#define LPI2C_MCFGR1_TIMECFG_MASK                (0x400U)
#define LPI2C_MCFGR1_TIMECFG_SHIFT               (10U)
#define LPI2C_MCFGR1_TIMECFG(x)                  (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR1_TIMECFG_SHIFT)) & LPI2C_MCFGR1_TIMECFG_MASK)
#define LPI2C_MCFGR1_MATCFG_MASK                 (0x70000U)
#define LPI2C_MCFGR1_MATCFG_SHIFT                (16U)
#define LPI2C_MCFGR1_MATCFG(x)                   (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR1_MATCFG_SHIFT)) & LPI2C_MCFGR1_MATCFG_MASK)
#define LPI2C_MCFGR1_PINCFG_MASK                 (0x7000000U)
#define LPI2C_MCFGR1_PINCFG_SHIFT                (24U)
#define LPI2C_MCFGR1_PINCFG(x)                   (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR1_PINCFG_SHIFT)) & LPI2C_MCFGR1_PINCFG_MASK)

/*! @name MCFGR2 - Master Configuration Register 2 */
#define LPI2C_MCFGR2_BUSIDLE_MASK                (0xFFFU)
#define LPI2C_MCFGR2_BUSIDLE_SHIFT               (0U)
#define LPI2C_MCFGR2_BUSIDLE(x)                  (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR2_BUSIDLE_SHIFT)) & LPI2C_MCFGR2_BUSIDLE_MASK)
#define LPI2C_MCFGR2_FILTSCL_MASK                (0xF0000U)
#define LPI2C_MCFGR2_FILTSCL_SHIFT               (16U)
#define LPI2C_MCFGR2_FILTSCL(x)                  (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR2_FILTSCL_SHIFT)) & LPI2C_MCFGR2_FILTSCL_MASK)
#define LPI2C_MCFGR2_FILTSDA_MASK                (0xF000000U)
#define LPI2C_MCFGR2_FILTSDA_SHIFT               (24U)
#define LPI2C_MCFGR2_FILTSDA(x)                  (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR2_FILTSDA_SHIFT)) & LPI2C_MCFGR2_FILTSDA_MASK)

/*! @name MCFGR3 - Master Configuration Register 3 */
#define LPI2C_MCFGR3_PINLOW_MASK                 (0xFFF00U)
#define LPI2C_MCFGR3_PINLOW_SHIFT                (8U)
#define LPI2C_MCFGR3_PINLOW(x)                   (((uint32_t)(((uint32_t)(x)) << LPI2C_MCFGR3_PINLOW_SHIFT)) & LPI2C_MCFGR3_PINLOW_MASK)

/*! @name MDMR - Master Data Match Register */
#define LPI2C_MDMR_MATCH0_MASK                   (0xFFU)
#define LPI2C_MDMR_MATCH0_SHIFT                  (0U)
#define LPI2C_MDMR_MATCH0(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_MDMR_MATCH0_SHIFT)) & LPI2C_MDMR_MATCH0_MASK)
#define LPI2C_MDMR_MATCH1_MASK                   (0xFF0000U)
#define LPI2C_MDMR_MATCH1_SHIFT                  (16U)
#define LPI2C_MDMR_MATCH1(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_MDMR_MATCH1_SHIFT)) & LPI2C_MDMR_MATCH1_MASK)

/*! @name MCCR0 - Master Clock Configuration Register 0 */
#define LPI2C_MCCR0_CLKLO_MASK                   (0x3FU)
#define LPI2C_MCCR0_CLKLO_SHIFT                  (0U)
#define LPI2C_MCCR0_CLKLO(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_MCCR0_CLKLO_SHIFT)) & LPI2C_MCCR0_CLKLO_MASK)
#define LPI2C_MCCR0_CLKHI_MASK                   (0x3F00U)
#define LPI2C_MCCR0_CLKHI_SHIFT                  (8U)
#define LPI2C_MCCR0_CLKHI(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_MCCR0_CLKHI_SHIFT)) & LPI2C_MCCR0_CLKHI_MASK)
#define LPI2C_MCCR0_SETHOLD_MASK                 (0x3F0000U)
#define LPI2C_MCCR0_SETHOLD_SHIFT                (16U)
#define LPI2C_MCCR0_SETHOLD(x)                   (((uint32_t)(((uint32_t)(x)) << LPI2C_MCCR0_SETHOLD_SHIFT)) & LPI2C_MCCR0_SETHOLD_MASK)
#define LPI2C_MCCR0_DATAVD_MASK                  (0x3F000000U)
#define LPI2C_MCCR0_DATAVD_SHIFT                 (24U)
#define LPI2C_MCCR0_DATAVD(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_MCCR0_DATAVD_SHIFT)) & LPI2C_MCCR0_DATAVD_MASK)

/*! @name MCCR1 - Master Clock Configuration Register 1 */
#define LPI2C_MCCR1_CLKLO_MASK                   (0x3FU)
#define LPI2C_MCCR1_CLKLO_SHIFT                  (0U)
#define LPI2C_MCCR1_CLKLO(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_MCCR1_CLKLO_SHIFT)) & LPI2C_MCCR1_CLKLO_MASK)
#define LPI2C_MCCR1_CLKHI_MASK                   (0x3F00U)
#define LPI2C_MCCR1_CLKHI_SHIFT                  (8U)
#define LPI2C_MCCR1_CLKHI(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_MCCR1_CLKHI_SHIFT)) & LPI2C_MCCR1_CLKHI_MASK)
#define LPI2C_MCCR1_SETHOLD_MASK                 (0x3F0000U)
#define LPI2C_MCCR1_SETHOLD_SHIFT                (16U)
#define LPI2C_MCCR1_SETHOLD(x)                   (((uint32_t)(((uint32_t)(x)) << LPI2C_MCCR1_SETHOLD_SHIFT)) & LPI2C_MCCR1_SETHOLD_MASK)
#define LPI2C_MCCR1_DATAVD_MASK                  (0x3F000000U)
#define LPI2C_MCCR1_DATAVD_SHIFT                 (24U)
#define LPI2C_MCCR1_DATAVD(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_MCCR1_DATAVD_SHIFT)) & LPI2C_MCCR1_DATAVD_MASK)

/*! @name MFCR - Master FIFO Control Register */
#define LPI2C_MFCR_TXWATER_MASK                  (0xFFU)
#define LPI2C_MFCR_TXWATER_SHIFT                 (0U)
#define LPI2C_MFCR_TXWATER(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_MFCR_TXWATER_SHIFT)) & LPI2C_MFCR_TXWATER_MASK)
#define LPI2C_MFCR_RXWATER_MASK                  (0xFF0000U)
#define LPI2C_MFCR_RXWATER_SHIFT                 (16U)
#define LPI2C_MFCR_RXWATER(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_MFCR_RXWATER_SHIFT)) & LPI2C_MFCR_RXWATER_MASK)

/*! @name MFSR - Master FIFO Status Register */
#define LPI2C_MFSR_TXCOUNT_MASK                  (0xFFU)
#define LPI2C_MFSR_TXCOUNT_SHIFT                 (0U)
#define LPI2C_MFSR_TXCOUNT(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_MFSR_TXCOUNT_SHIFT)) & LPI2C_MFSR_TXCOUNT_MASK)
#define LPI2C_MFSR_RXCOUNT_MASK                  (0xFF0000U)
#define LPI2C_MFSR_RXCOUNT_SHIFT                 (16U)
#define LPI2C_MFSR_RXCOUNT(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_MFSR_RXCOUNT_SHIFT)) & LPI2C_MFSR_RXCOUNT_MASK)

/*! @name MTDR - Master Transmit Data Register */
#define LPI2C_MTDR_DATA_MASK                     (0xFFU)
#define LPI2C_MTDR_DATA_SHIFT                    (0U)
#define LPI2C_MTDR_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MTDR_DATA_SHIFT)) & LPI2C_MTDR_DATA_MASK)
#define LPI2C_MTDR_CMD_MASK                      (0x700U)
#define LPI2C_MTDR_CMD_SHIFT                     (8U)
#define LPI2C_MTDR_CMD(x)                        (((uint32_t)(((uint32_t)(x)) << LPI2C_MTDR_CMD_SHIFT)) & LPI2C_MTDR_CMD_MASK)

/*! @name MRDR - Master Receive Data Register */
#define LPI2C_MRDR_DATA_MASK                     (0xFFU)
#define LPI2C_MRDR_DATA_SHIFT                    (0U)
#define LPI2C_MRDR_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_MRDR_DATA_SHIFT)) & LPI2C_MRDR_DATA_MASK)
#define LPI2C_MRDR_RXEMPTY_MASK                  (0x4000U)
#define LPI2C_MRDR_RXEMPTY_SHIFT                 (14U)
#define LPI2C_MRDR_RXEMPTY(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_MRDR_RXEMPTY_SHIFT)) & LPI2C_MRDR_RXEMPTY_MASK)

/*! @name SCR - Slave Control Register */
#define LPI2C_SCR_SEN_MASK                       (0x1U)
#define LPI2C_SCR_SEN_SHIFT                      (0U)
#define LPI2C_SCR_SEN(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SCR_SEN_SHIFT)) & LPI2C_SCR_SEN_MASK)
#define LPI2C_SCR_RST_MASK                       (0x2U)
#define LPI2C_SCR_RST_SHIFT                      (1U)
#define LPI2C_SCR_RST(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SCR_RST_SHIFT)) & LPI2C_SCR_RST_MASK)
#define LPI2C_SCR_FILTEN_MASK                    (0x10U)
#define LPI2C_SCR_FILTEN_SHIFT                   (4U)
#define LPI2C_SCR_FILTEN(x)                      (((uint32_t)(((uint32_t)(x)) << LPI2C_SCR_FILTEN_SHIFT)) & LPI2C_SCR_FILTEN_MASK)
#define LPI2C_SCR_FILTDZ_MASK                    (0x20U)
#define LPI2C_SCR_FILTDZ_SHIFT                   (5U)
#define LPI2C_SCR_FILTDZ(x)                      (((uint32_t)(((uint32_t)(x)) << LPI2C_SCR_FILTDZ_SHIFT)) & LPI2C_SCR_FILTDZ_MASK)
#define LPI2C_SCR_RTF_MASK                       (0x100U)
#define LPI2C_SCR_RTF_SHIFT                      (8U)
#define LPI2C_SCR_RTF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SCR_RTF_SHIFT)) & LPI2C_SCR_RTF_MASK)
#define LPI2C_SCR_RRF_MASK                       (0x200U)
#define LPI2C_SCR_RRF_SHIFT                      (9U)
#define LPI2C_SCR_RRF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SCR_RRF_SHIFT)) & LPI2C_SCR_RRF_MASK)

/*! @name SSR - Slave Status Register */
#define LPI2C_SSR_TDF_MASK                       (0x1U)
#define LPI2C_SSR_TDF_SHIFT                      (0U)
#define LPI2C_SSR_TDF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_TDF_SHIFT)) & LPI2C_SSR_TDF_MASK)
#define LPI2C_SSR_RDF_MASK                       (0x2U)
#define LPI2C_SSR_RDF_SHIFT                      (1U)
#define LPI2C_SSR_RDF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_RDF_SHIFT)) & LPI2C_SSR_RDF_MASK)
#define LPI2C_SSR_AVF_MASK                       (0x4U)
#define LPI2C_SSR_AVF_SHIFT                      (2U)
#define LPI2C_SSR_AVF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_AVF_SHIFT)) & LPI2C_SSR_AVF_MASK)
#define LPI2C_SSR_TAF_MASK                       (0x8U)
#define LPI2C_SSR_TAF_SHIFT                      (3U)
#define LPI2C_SSR_TAF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_TAF_SHIFT)) & LPI2C_SSR_TAF_MASK)
#define LPI2C_SSR_RSF_MASK                       (0x100U)
#define LPI2C_SSR_RSF_SHIFT                      (8U)
#define LPI2C_SSR_RSF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_RSF_SHIFT)) & LPI2C_SSR_RSF_MASK)
#define LPI2C_SSR_SDF_MASK                       (0x200U)
#define LPI2C_SSR_SDF_SHIFT                      (9U)
#define LPI2C_SSR_SDF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_SDF_SHIFT)) & LPI2C_SSR_SDF_MASK)
#define LPI2C_SSR_BEF_MASK                       (0x400U)
#define LPI2C_SSR_BEF_SHIFT                      (10U)
#define LPI2C_SSR_BEF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_BEF_SHIFT)) & LPI2C_SSR_BEF_MASK)
#define LPI2C_SSR_FEF_MASK                       (0x800U)
#define LPI2C_SSR_FEF_SHIFT                      (11U)
#define LPI2C_SSR_FEF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_FEF_SHIFT)) & LPI2C_SSR_FEF_MASK)
#define LPI2C_SSR_AM0F_MASK                      (0x1000U)
#define LPI2C_SSR_AM0F_SHIFT                     (12U)
#define LPI2C_SSR_AM0F(x)                        (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_AM0F_SHIFT)) & LPI2C_SSR_AM0F_MASK)
#define LPI2C_SSR_AM1F_MASK                      (0x2000U)
#define LPI2C_SSR_AM1F_SHIFT                     (13U)
#define LPI2C_SSR_AM1F(x)                        (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_AM1F_SHIFT)) & LPI2C_SSR_AM1F_MASK)
#define LPI2C_SSR_GCF_MASK                       (0x4000U)
#define LPI2C_SSR_GCF_SHIFT                      (14U)
#define LPI2C_SSR_GCF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_GCF_SHIFT)) & LPI2C_SSR_GCF_MASK)
#define LPI2C_SSR_SARF_MASK                      (0x8000U)
#define LPI2C_SSR_SARF_SHIFT                     (15U)
#define LPI2C_SSR_SARF(x)                        (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_SARF_SHIFT)) & LPI2C_SSR_SARF_MASK)
#define LPI2C_SSR_SBF_MASK                       (0x1000000U)
#define LPI2C_SSR_SBF_SHIFT                      (24U)
#define LPI2C_SSR_SBF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_SBF_SHIFT)) & LPI2C_SSR_SBF_MASK)
#define LPI2C_SSR_BBF_MASK                       (0x2000000U)
#define LPI2C_SSR_BBF_SHIFT                      (25U)
#define LPI2C_SSR_BBF(x)                         (((uint32_t)(((uint32_t)(x)) << LPI2C_SSR_BBF_SHIFT)) & LPI2C_SSR_BBF_MASK)

/*! @name SIER - Slave Interrupt Enable Register */
#define LPI2C_SIER_TDIE_MASK                     (0x1U)
#define LPI2C_SIER_TDIE_SHIFT                    (0U)
#define LPI2C_SIER_TDIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_TDIE_SHIFT)) & LPI2C_SIER_TDIE_MASK)
#define LPI2C_SIER_RDIE_MASK                     (0x2U)
#define LPI2C_SIER_RDIE_SHIFT                    (1U)
#define LPI2C_SIER_RDIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_RDIE_SHIFT)) & LPI2C_SIER_RDIE_MASK)
#define LPI2C_SIER_AVIE_MASK                     (0x4U)
#define LPI2C_SIER_AVIE_SHIFT                    (2U)
#define LPI2C_SIER_AVIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_AVIE_SHIFT)) & LPI2C_SIER_AVIE_MASK)
#define LPI2C_SIER_TAIE_MASK                     (0x8U)
#define LPI2C_SIER_TAIE_SHIFT                    (3U)
#define LPI2C_SIER_TAIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_TAIE_SHIFT)) & LPI2C_SIER_TAIE_MASK)
#define LPI2C_SIER_RSIE_MASK                     (0x100U)
#define LPI2C_SIER_RSIE_SHIFT                    (8U)
#define LPI2C_SIER_RSIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_RSIE_SHIFT)) & LPI2C_SIER_RSIE_MASK)
#define LPI2C_SIER_SDIE_MASK                     (0x200U)
#define LPI2C_SIER_SDIE_SHIFT                    (9U)
#define LPI2C_SIER_SDIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_SDIE_SHIFT)) & LPI2C_SIER_SDIE_MASK)
#define LPI2C_SIER_BEIE_MASK                     (0x400U)
#define LPI2C_SIER_BEIE_SHIFT                    (10U)
#define LPI2C_SIER_BEIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_BEIE_SHIFT)) & LPI2C_SIER_BEIE_MASK)
#define LPI2C_SIER_FEIE_MASK                     (0x800U)
#define LPI2C_SIER_FEIE_SHIFT                    (11U)
#define LPI2C_SIER_FEIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_FEIE_SHIFT)) & LPI2C_SIER_FEIE_MASK)
#define LPI2C_SIER_AM0IE_MASK                    (0x1000U)
#define LPI2C_SIER_AM0IE_SHIFT                   (12U)
#define LPI2C_SIER_AM0IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_AM0IE_SHIFT)) & LPI2C_SIER_AM0IE_MASK)
#define LPI2C_SIER_AM1F_MASK                     (0x2000U)
#define LPI2C_SIER_AM1F_SHIFT                    (13U)
#define LPI2C_SIER_AM1F(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_AM1F_SHIFT)) & LPI2C_SIER_AM1F_MASK)
#define LPI2C_SIER_GCIE_MASK                     (0x4000U)
#define LPI2C_SIER_GCIE_SHIFT                    (14U)
#define LPI2C_SIER_GCIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_GCIE_SHIFT)) & LPI2C_SIER_GCIE_MASK)
#define LPI2C_SIER_SARIE_MASK                    (0x8000U)
#define LPI2C_SIER_SARIE_SHIFT                   (15U)
#define LPI2C_SIER_SARIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPI2C_SIER_SARIE_SHIFT)) & LPI2C_SIER_SARIE_MASK)

/*! @name SDER - Slave DMA Enable Register */
#define LPI2C_SDER_TDDE_MASK                     (0x1U)
#define LPI2C_SDER_TDDE_SHIFT                    (0U)
#define LPI2C_SDER_TDDE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SDER_TDDE_SHIFT)) & LPI2C_SDER_TDDE_MASK)
#define LPI2C_SDER_RDDE_MASK                     (0x2U)
#define LPI2C_SDER_RDDE_SHIFT                    (1U)
#define LPI2C_SDER_RDDE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SDER_RDDE_SHIFT)) & LPI2C_SDER_RDDE_MASK)
#define LPI2C_SDER_AVDE_MASK                     (0x4U)
#define LPI2C_SDER_AVDE_SHIFT                    (2U)
#define LPI2C_SDER_AVDE(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SDER_AVDE_SHIFT)) & LPI2C_SDER_AVDE_MASK)

/*! @name SCFGR1 - Slave Configuration Register 1 */
#define LPI2C_SCFGR1_ADRSTALL_MASK               (0x1U)
#define LPI2C_SCFGR1_ADRSTALL_SHIFT              (0U)
#define LPI2C_SCFGR1_ADRSTALL(x)                 (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR1_ADRSTALL_SHIFT)) & LPI2C_SCFGR1_ADRSTALL_MASK)
#define LPI2C_SCFGR1_RXSTALL_MASK                (0x2U)
#define LPI2C_SCFGR1_RXSTALL_SHIFT               (1U)
#define LPI2C_SCFGR1_RXSTALL(x)                  (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR1_RXSTALL_SHIFT)) & LPI2C_SCFGR1_RXSTALL_MASK)
#define LPI2C_SCFGR1_TXDSTALL_MASK               (0x4U)
#define LPI2C_SCFGR1_TXDSTALL_SHIFT              (2U)
#define LPI2C_SCFGR1_TXDSTALL(x)                 (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR1_TXDSTALL_SHIFT)) & LPI2C_SCFGR1_TXDSTALL_MASK)
#define LPI2C_SCFGR1_ACKSTALL_MASK               (0x8U)
#define LPI2C_SCFGR1_ACKSTALL_SHIFT              (3U)
#define LPI2C_SCFGR1_ACKSTALL(x)                 (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR1_ACKSTALL_SHIFT)) & LPI2C_SCFGR1_ACKSTALL_MASK)
#define LPI2C_SCFGR1_GCEN_MASK                   (0x100U)
#define LPI2C_SCFGR1_GCEN_SHIFT                  (8U)
#define LPI2C_SCFGR1_GCEN(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR1_GCEN_SHIFT)) & LPI2C_SCFGR1_GCEN_MASK)
#define LPI2C_SCFGR1_SAEN_MASK                   (0x200U)
#define LPI2C_SCFGR1_SAEN_SHIFT                  (9U)
#define LPI2C_SCFGR1_SAEN(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR1_SAEN_SHIFT)) & LPI2C_SCFGR1_SAEN_MASK)
#define LPI2C_SCFGR1_TXCFG_MASK                  (0x400U)
#define LPI2C_SCFGR1_TXCFG_SHIFT                 (10U)
#define LPI2C_SCFGR1_TXCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR1_TXCFG_SHIFT)) & LPI2C_SCFGR1_TXCFG_MASK)
#define LPI2C_SCFGR1_RXCFG_MASK                  (0x800U)
#define LPI2C_SCFGR1_RXCFG_SHIFT                 (11U)
#define LPI2C_SCFGR1_RXCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR1_RXCFG_SHIFT)) & LPI2C_SCFGR1_RXCFG_MASK)
#define LPI2C_SCFGR1_IGNACK_MASK                 (0x1000U)
#define LPI2C_SCFGR1_IGNACK_SHIFT                (12U)
#define LPI2C_SCFGR1_IGNACK(x)                   (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR1_IGNACK_SHIFT)) & LPI2C_SCFGR1_IGNACK_MASK)
#define LPI2C_SCFGR1_HSMEN_MASK                  (0x2000U)
#define LPI2C_SCFGR1_HSMEN_SHIFT                 (13U)
#define LPI2C_SCFGR1_HSMEN(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR1_HSMEN_SHIFT)) & LPI2C_SCFGR1_HSMEN_MASK)
#define LPI2C_SCFGR1_ADDRCFG_MASK                (0x70000U)
#define LPI2C_SCFGR1_ADDRCFG_SHIFT               (16U)
#define LPI2C_SCFGR1_ADDRCFG(x)                  (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR1_ADDRCFG_SHIFT)) & LPI2C_SCFGR1_ADDRCFG_MASK)

/*! @name SCFGR2 - Slave Configuration Register 2 */
#define LPI2C_SCFGR2_CLKHOLD_MASK                (0xFU)
#define LPI2C_SCFGR2_CLKHOLD_SHIFT               (0U)
#define LPI2C_SCFGR2_CLKHOLD(x)                  (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR2_CLKHOLD_SHIFT)) & LPI2C_SCFGR2_CLKHOLD_MASK)
#define LPI2C_SCFGR2_DATAVD_MASK                 (0x3F00U)
#define LPI2C_SCFGR2_DATAVD_SHIFT                (8U)
#define LPI2C_SCFGR2_DATAVD(x)                   (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR2_DATAVD_SHIFT)) & LPI2C_SCFGR2_DATAVD_MASK)
#define LPI2C_SCFGR2_FILTSCL_MASK                (0xF0000U)
#define LPI2C_SCFGR2_FILTSCL_SHIFT               (16U)
#define LPI2C_SCFGR2_FILTSCL(x)                  (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR2_FILTSCL_SHIFT)) & LPI2C_SCFGR2_FILTSCL_MASK)
#define LPI2C_SCFGR2_FILTSDA_MASK                (0xF000000U)
#define LPI2C_SCFGR2_FILTSDA_SHIFT               (24U)
#define LPI2C_SCFGR2_FILTSDA(x)                  (((uint32_t)(((uint32_t)(x)) << LPI2C_SCFGR2_FILTSDA_SHIFT)) & LPI2C_SCFGR2_FILTSDA_MASK)

/*! @name SAMR - Slave Address Match Register */
#define LPI2C_SAMR_ADDR0_MASK                    (0x7FEU)
#define LPI2C_SAMR_ADDR0_SHIFT                   (1U)
#define LPI2C_SAMR_ADDR0(x)                      (((uint32_t)(((uint32_t)(x)) << LPI2C_SAMR_ADDR0_SHIFT)) & LPI2C_SAMR_ADDR0_MASK)
#define LPI2C_SAMR_ADDR1_MASK                    (0x7FE0000U)
#define LPI2C_SAMR_ADDR1_SHIFT                   (17U)
#define LPI2C_SAMR_ADDR1(x)                      (((uint32_t)(((uint32_t)(x)) << LPI2C_SAMR_ADDR1_SHIFT)) & LPI2C_SAMR_ADDR1_MASK)

/*! @name SASR - Slave Address Status Register */
#define LPI2C_SASR_RADDR_MASK                    (0x7FFU)
#define LPI2C_SASR_RADDR_SHIFT                   (0U)
#define LPI2C_SASR_RADDR(x)                      (((uint32_t)(((uint32_t)(x)) << LPI2C_SASR_RADDR_SHIFT)) & LPI2C_SASR_RADDR_MASK)
#define LPI2C_SASR_ANV_MASK                      (0x4000U)
#define LPI2C_SASR_ANV_SHIFT                     (14U)
#define LPI2C_SASR_ANV(x)                        (((uint32_t)(((uint32_t)(x)) << LPI2C_SASR_ANV_SHIFT)) & LPI2C_SASR_ANV_MASK)

/*! @name STAR - Slave Transmit ACK Register */
#define LPI2C_STAR_TXNACK_MASK                   (0x1U)
#define LPI2C_STAR_TXNACK_SHIFT                  (0U)
#define LPI2C_STAR_TXNACK(x)                     (((uint32_t)(((uint32_t)(x)) << LPI2C_STAR_TXNACK_SHIFT)) & LPI2C_STAR_TXNACK_MASK)

/*! @name STDR - Slave Transmit Data Register */
#define LPI2C_STDR_DATA_MASK                     (0xFFU)
#define LPI2C_STDR_DATA_SHIFT                    (0U)
#define LPI2C_STDR_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_STDR_DATA_SHIFT)) & LPI2C_STDR_DATA_MASK)

/*! @name SRDR - Slave Receive Data Register */
#define LPI2C_SRDR_DATA_MASK                     (0xFFU)
#define LPI2C_SRDR_DATA_SHIFT                    (0U)
#define LPI2C_SRDR_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << LPI2C_SRDR_DATA_SHIFT)) & LPI2C_SRDR_DATA_MASK)
#define LPI2C_SRDR_RXEMPTY_MASK                  (0x4000U)
#define LPI2C_SRDR_RXEMPTY_SHIFT                 (14U)
#define LPI2C_SRDR_RXEMPTY(x)                    (((uint32_t)(((uint32_t)(x)) << LPI2C_SRDR_RXEMPTY_SHIFT)) & LPI2C_SRDR_RXEMPTY_MASK)
#define LPI2C_SRDR_SOF_MASK                      (0x8000U)
#define LPI2C_SRDR_SOF_SHIFT                     (15U)
#define LPI2C_SRDR_SOF(x)                        (((uint32_t)(((uint32_t)(x)) << LPI2C_SRDR_SOF_SHIFT)) & LPI2C_SRDR_SOF_MASK)


/*!
 * @}
 */ /* end of group LPI2C_Register_Masks */


/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x40066000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x40067000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn }

/*!
 * @}
 */ /* end of group LPI2C_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPTMR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Peripheral_Access_Layer LPTMR Peripheral Access Layer
 * @{
 */

/** LPTMR - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSR;                               /**< Low Power Timer Control Status Register, offset: 0x0 */
  __IO uint32_t PSR;                               /**< Low Power Timer Prescale Register, offset: 0x4 */
  __IO uint32_t CMR;                               /**< Low Power Timer Compare Register, offset: 0x8 */
  __IO uint32_t CNR;                               /**< Low Power Timer Counter Register, offset: 0xC */
} LPTMR_Type;

/* ----------------------------------------------------------------------------
   -- LPTMR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Register_Masks LPTMR Register Masks
 * @{
 */

/*! @name CSR - Low Power Timer Control Status Register */
#define LPTMR_CSR_TEN_MASK                       (0x1U)
#define LPTMR_CSR_TEN_SHIFT                      (0U)
#define LPTMR_CSR_TEN(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TEN_SHIFT)) & LPTMR_CSR_TEN_MASK)
#define LPTMR_CSR_TMS_MASK                       (0x2U)
#define LPTMR_CSR_TMS_SHIFT                      (1U)
#define LPTMR_CSR_TMS(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TMS_SHIFT)) & LPTMR_CSR_TMS_MASK)
#define LPTMR_CSR_TFC_MASK                       (0x4U)
#define LPTMR_CSR_TFC_SHIFT                      (2U)
#define LPTMR_CSR_TFC(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TFC_SHIFT)) & LPTMR_CSR_TFC_MASK)
#define LPTMR_CSR_TPP_MASK                       (0x8U)
#define LPTMR_CSR_TPP_SHIFT                      (3U)
#define LPTMR_CSR_TPP(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TPP_SHIFT)) & LPTMR_CSR_TPP_MASK)
#define LPTMR_CSR_TPS_MASK                       (0x30U)
#define LPTMR_CSR_TPS_SHIFT                      (4U)
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TPS_SHIFT)) & LPTMR_CSR_TPS_MASK)
#define LPTMR_CSR_TIE_MASK                       (0x40U)
#define LPTMR_CSR_TIE_SHIFT                      (6U)
#define LPTMR_CSR_TIE(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TIE_SHIFT)) & LPTMR_CSR_TIE_MASK)
#define LPTMR_CSR_TCF_MASK                       (0x80U)
#define LPTMR_CSR_TCF_SHIFT                      (7U)
#define LPTMR_CSR_TCF(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_CSR_TCF_SHIFT)) & LPTMR_CSR_TCF_MASK)

/*! @name PSR - Low Power Timer Prescale Register */
#define LPTMR_PSR_PCS_MASK                       (0x3U)
#define LPTMR_PSR_PCS_SHIFT                      (0U)
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x)) << LPTMR_PSR_PCS_SHIFT)) & LPTMR_PSR_PCS_MASK)
#define LPTMR_PSR_PBYP_MASK                      (0x4U)
#define LPTMR_PSR_PBYP_SHIFT                     (2U)
#define LPTMR_PSR_PBYP(x)                        (((uint32_t)(((uint32_t)(x)) << LPTMR_PSR_PBYP_SHIFT)) & LPTMR_PSR_PBYP_MASK)
#define LPTMR_PSR_PRESCALE_MASK                  (0x78U)
#define LPTMR_PSR_PRESCALE_SHIFT                 (3U)
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x)) << LPTMR_PSR_PRESCALE_SHIFT)) & LPTMR_PSR_PRESCALE_MASK)

/*! @name CMR - Low Power Timer Compare Register */
#define LPTMR_CMR_COMPARE_MASK                   (0xFFFFU)
#define LPTMR_CMR_COMPARE_SHIFT                  (0U)
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x)) << LPTMR_CMR_COMPARE_SHIFT)) & LPTMR_CMR_COMPARE_MASK)

/*! @name CNR - Low Power Timer Counter Register */
#define LPTMR_CNR_COUNTER_MASK                   (0xFFFFU)
#define LPTMR_CNR_COUNTER_SHIFT                  (0U)
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x)) << LPTMR_CNR_COUNTER_SHIFT)) & LPTMR_CNR_COUNTER_MASK)


/*!
 * @}
 */ /* end of group LPTMR_Register_Masks */


/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0x40040000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR0_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0 }
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn }

/*!
 * @}
 */ /* end of group LPTMR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPUART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Peripheral_Access_Layer LPUART Peripheral Access Layer
 * @{
 */

/** LPUART - Register Layout Typedef */
typedef struct {
  __IO uint32_t BAUD;                              /**< LPUART Baud Rate Register, offset: 0x0 */
  __IO uint32_t STAT;                              /**< LPUART Status Register, offset: 0x4 */
  __IO uint32_t CTRL;                              /**< LPUART Control Register, offset: 0x8 */
  __IO uint32_t DATA;                              /**< LPUART Data Register, offset: 0xC */
  __IO uint32_t MATCH;                             /**< LPUART Match Address Register, offset: 0x10 */
  __IO uint32_t MODIR;                             /**< LPUART Modem IrDA Register, offset: 0x14 */
} LPUART_Type;

/* ----------------------------------------------------------------------------
   -- LPUART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Register_Masks LPUART Register Masks
 * @{
 */

/*! @name BAUD - LPUART Baud Rate Register */
#define LPUART_BAUD_SBR_MASK                     (0x1FFFU)
#define LPUART_BAUD_SBR_SHIFT                    (0U)
#define LPUART_BAUD_SBR(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_SBR_SHIFT)) & LPUART_BAUD_SBR_MASK)
#define LPUART_BAUD_SBNS_MASK                    (0x2000U)
#define LPUART_BAUD_SBNS_SHIFT                   (13U)
#define LPUART_BAUD_SBNS(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_SBNS_SHIFT)) & LPUART_BAUD_SBNS_MASK)
#define LPUART_BAUD_RXEDGIE_MASK                 (0x4000U)
#define LPUART_BAUD_RXEDGIE_SHIFT                (14U)
#define LPUART_BAUD_RXEDGIE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_RXEDGIE_SHIFT)) & LPUART_BAUD_RXEDGIE_MASK)
#define LPUART_BAUD_LBKDIE_MASK                  (0x8000U)
#define LPUART_BAUD_LBKDIE_SHIFT                 (15U)
#define LPUART_BAUD_LBKDIE(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_LBKDIE_SHIFT)) & LPUART_BAUD_LBKDIE_MASK)
#define LPUART_BAUD_RESYNCDIS_MASK               (0x10000U)
#define LPUART_BAUD_RESYNCDIS_SHIFT              (16U)
#define LPUART_BAUD_RESYNCDIS(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_RESYNCDIS_SHIFT)) & LPUART_BAUD_RESYNCDIS_MASK)
#define LPUART_BAUD_BOTHEDGE_MASK                (0x20000U)
#define LPUART_BAUD_BOTHEDGE_SHIFT               (17U)
#define LPUART_BAUD_BOTHEDGE(x)                  (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_BOTHEDGE_SHIFT)) & LPUART_BAUD_BOTHEDGE_MASK)
#define LPUART_BAUD_MATCFG_MASK                  (0xC0000U)
#define LPUART_BAUD_MATCFG_SHIFT                 (18U)
#define LPUART_BAUD_MATCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_MATCFG_SHIFT)) & LPUART_BAUD_MATCFG_MASK)
#define LPUART_BAUD_RDMAE_MASK                   (0x200000U)
#define LPUART_BAUD_RDMAE_SHIFT                  (21U)
#define LPUART_BAUD_RDMAE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_RDMAE_SHIFT)) & LPUART_BAUD_RDMAE_MASK)
#define LPUART_BAUD_TDMAE_MASK                   (0x800000U)
#define LPUART_BAUD_TDMAE_SHIFT                  (23U)
#define LPUART_BAUD_TDMAE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_TDMAE_SHIFT)) & LPUART_BAUD_TDMAE_MASK)
#define LPUART_BAUD_OSR_MASK                     (0x1F000000U)
#define LPUART_BAUD_OSR_SHIFT                    (24U)
#define LPUART_BAUD_OSR(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_OSR_SHIFT)) & LPUART_BAUD_OSR_MASK)
#define LPUART_BAUD_M10_MASK                     (0x20000000U)
#define LPUART_BAUD_M10_SHIFT                    (29U)
#define LPUART_BAUD_M10(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_M10_SHIFT)) & LPUART_BAUD_M10_MASK)
#define LPUART_BAUD_MAEN2_MASK                   (0x40000000U)
#define LPUART_BAUD_MAEN2_SHIFT                  (30U)
#define LPUART_BAUD_MAEN2(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_MAEN2_SHIFT)) & LPUART_BAUD_MAEN2_MASK)
#define LPUART_BAUD_MAEN1_MASK                   (0x80000000U)
#define LPUART_BAUD_MAEN1_SHIFT                  (31U)
#define LPUART_BAUD_MAEN1(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_BAUD_MAEN1_SHIFT)) & LPUART_BAUD_MAEN1_MASK)

/*! @name STAT - LPUART Status Register */
#define LPUART_STAT_MA2F_MASK                    (0x4000U)
#define LPUART_STAT_MA2F_SHIFT                   (14U)
#define LPUART_STAT_MA2F(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_MA2F_SHIFT)) & LPUART_STAT_MA2F_MASK)
#define LPUART_STAT_MA1F_MASK                    (0x8000U)
#define LPUART_STAT_MA1F_SHIFT                   (15U)
#define LPUART_STAT_MA1F(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_MA1F_SHIFT)) & LPUART_STAT_MA1F_MASK)
#define LPUART_STAT_PF_MASK                      (0x10000U)
#define LPUART_STAT_PF_SHIFT                     (16U)
#define LPUART_STAT_PF(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_PF_SHIFT)) & LPUART_STAT_PF_MASK)
#define LPUART_STAT_FE_MASK                      (0x20000U)
#define LPUART_STAT_FE_SHIFT                     (17U)
#define LPUART_STAT_FE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_FE_SHIFT)) & LPUART_STAT_FE_MASK)
#define LPUART_STAT_NF_MASK                      (0x40000U)
#define LPUART_STAT_NF_SHIFT                     (18U)
#define LPUART_STAT_NF(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_NF_SHIFT)) & LPUART_STAT_NF_MASK)
#define LPUART_STAT_OR_MASK                      (0x80000U)
#define LPUART_STAT_OR_SHIFT                     (19U)
#define LPUART_STAT_OR(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_OR_SHIFT)) & LPUART_STAT_OR_MASK)
#define LPUART_STAT_IDLE_MASK                    (0x100000U)
#define LPUART_STAT_IDLE_SHIFT                   (20U)
#define LPUART_STAT_IDLE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_IDLE_SHIFT)) & LPUART_STAT_IDLE_MASK)
#define LPUART_STAT_RDRF_MASK                    (0x200000U)
#define LPUART_STAT_RDRF_SHIFT                   (21U)
#define LPUART_STAT_RDRF(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RDRF_SHIFT)) & LPUART_STAT_RDRF_MASK)
#define LPUART_STAT_TC_MASK                      (0x400000U)
#define LPUART_STAT_TC_SHIFT                     (22U)
#define LPUART_STAT_TC(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_TC_SHIFT)) & LPUART_STAT_TC_MASK)
#define LPUART_STAT_TDRE_MASK                    (0x800000U)
#define LPUART_STAT_TDRE_SHIFT                   (23U)
#define LPUART_STAT_TDRE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_TDRE_SHIFT)) & LPUART_STAT_TDRE_MASK)
#define LPUART_STAT_RAF_MASK                     (0x1000000U)
#define LPUART_STAT_RAF_SHIFT                    (24U)
#define LPUART_STAT_RAF(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RAF_SHIFT)) & LPUART_STAT_RAF_MASK)
#define LPUART_STAT_LBKDE_MASK                   (0x2000000U)
#define LPUART_STAT_LBKDE_SHIFT                  (25U)
#define LPUART_STAT_LBKDE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_LBKDE_SHIFT)) & LPUART_STAT_LBKDE_MASK)
#define LPUART_STAT_BRK13_MASK                   (0x4000000U)
#define LPUART_STAT_BRK13_SHIFT                  (26U)
#define LPUART_STAT_BRK13(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_BRK13_SHIFT)) & LPUART_STAT_BRK13_MASK)
#define LPUART_STAT_RWUID_MASK                   (0x8000000U)
#define LPUART_STAT_RWUID_SHIFT                  (27U)
#define LPUART_STAT_RWUID(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RWUID_SHIFT)) & LPUART_STAT_RWUID_MASK)
#define LPUART_STAT_RXINV_MASK                   (0x10000000U)
#define LPUART_STAT_RXINV_SHIFT                  (28U)
#define LPUART_STAT_RXINV(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RXINV_SHIFT)) & LPUART_STAT_RXINV_MASK)
#define LPUART_STAT_MSBF_MASK                    (0x20000000U)
#define LPUART_STAT_MSBF_SHIFT                   (29U)
#define LPUART_STAT_MSBF(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_MSBF_SHIFT)) & LPUART_STAT_MSBF_MASK)
#define LPUART_STAT_RXEDGIF_MASK                 (0x40000000U)
#define LPUART_STAT_RXEDGIF_SHIFT                (30U)
#define LPUART_STAT_RXEDGIF(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_RXEDGIF_SHIFT)) & LPUART_STAT_RXEDGIF_MASK)
#define LPUART_STAT_LBKDIF_MASK                  (0x80000000U)
#define LPUART_STAT_LBKDIF_SHIFT                 (31U)
#define LPUART_STAT_LBKDIF(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_STAT_LBKDIF_SHIFT)) & LPUART_STAT_LBKDIF_MASK)

/*! @name CTRL - LPUART Control Register */
#define LPUART_CTRL_PT_MASK                      (0x1U)
#define LPUART_CTRL_PT_SHIFT                     (0U)
#define LPUART_CTRL_PT(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_PT_SHIFT)) & LPUART_CTRL_PT_MASK)
#define LPUART_CTRL_PE_MASK                      (0x2U)
#define LPUART_CTRL_PE_SHIFT                     (1U)
#define LPUART_CTRL_PE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_PE_SHIFT)) & LPUART_CTRL_PE_MASK)
#define LPUART_CTRL_ILT_MASK                     (0x4U)
#define LPUART_CTRL_ILT_SHIFT                    (2U)
#define LPUART_CTRL_ILT(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_ILT_SHIFT)) & LPUART_CTRL_ILT_MASK)
#define LPUART_CTRL_WAKE_MASK                    (0x8U)
#define LPUART_CTRL_WAKE_SHIFT                   (3U)
#define LPUART_CTRL_WAKE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_WAKE_SHIFT)) & LPUART_CTRL_WAKE_MASK)
#define LPUART_CTRL_M_MASK                       (0x10U)
#define LPUART_CTRL_M_SHIFT                      (4U)
#define LPUART_CTRL_M(x)                         (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_M_SHIFT)) & LPUART_CTRL_M_MASK)
#define LPUART_CTRL_RSRC_MASK                    (0x20U)
#define LPUART_CTRL_RSRC_SHIFT                   (5U)
#define LPUART_CTRL_RSRC(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RSRC_SHIFT)) & LPUART_CTRL_RSRC_MASK)
#define LPUART_CTRL_DOZEEN_MASK                  (0x40U)
#define LPUART_CTRL_DOZEEN_SHIFT                 (6U)
#define LPUART_CTRL_DOZEEN(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_DOZEEN_SHIFT)) & LPUART_CTRL_DOZEEN_MASK)
#define LPUART_CTRL_LOOPS_MASK                   (0x80U)
#define LPUART_CTRL_LOOPS_SHIFT                  (7U)
#define LPUART_CTRL_LOOPS(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_LOOPS_SHIFT)) & LPUART_CTRL_LOOPS_MASK)
#define LPUART_CTRL_IDLECFG_MASK                 (0x700U)
#define LPUART_CTRL_IDLECFG_SHIFT                (8U)
#define LPUART_CTRL_IDLECFG(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_IDLECFG_SHIFT)) & LPUART_CTRL_IDLECFG_MASK)
#define LPUART_CTRL_MA2IE_MASK                   (0x4000U)
#define LPUART_CTRL_MA2IE_SHIFT                  (14U)
#define LPUART_CTRL_MA2IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_MA2IE_SHIFT)) & LPUART_CTRL_MA2IE_MASK)
#define LPUART_CTRL_MA1IE_MASK                   (0x8000U)
#define LPUART_CTRL_MA1IE_SHIFT                  (15U)
#define LPUART_CTRL_MA1IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_MA1IE_SHIFT)) & LPUART_CTRL_MA1IE_MASK)
#define LPUART_CTRL_SBK_MASK                     (0x10000U)
#define LPUART_CTRL_SBK_SHIFT                    (16U)
#define LPUART_CTRL_SBK(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_SBK_SHIFT)) & LPUART_CTRL_SBK_MASK)
#define LPUART_CTRL_RWU_MASK                     (0x20000U)
#define LPUART_CTRL_RWU_SHIFT                    (17U)
#define LPUART_CTRL_RWU(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RWU_SHIFT)) & LPUART_CTRL_RWU_MASK)
#define LPUART_CTRL_RE_MASK                      (0x40000U)
#define LPUART_CTRL_RE_SHIFT                     (18U)
#define LPUART_CTRL_RE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RE_SHIFT)) & LPUART_CTRL_RE_MASK)
#define LPUART_CTRL_TE_MASK                      (0x80000U)
#define LPUART_CTRL_TE_SHIFT                     (19U)
#define LPUART_CTRL_TE(x)                        (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TE_SHIFT)) & LPUART_CTRL_TE_MASK)
#define LPUART_CTRL_ILIE_MASK                    (0x100000U)
#define LPUART_CTRL_ILIE_SHIFT                   (20U)
#define LPUART_CTRL_ILIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_ILIE_SHIFT)) & LPUART_CTRL_ILIE_MASK)
#define LPUART_CTRL_RIE_MASK                     (0x200000U)
#define LPUART_CTRL_RIE_SHIFT                    (21U)
#define LPUART_CTRL_RIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_RIE_SHIFT)) & LPUART_CTRL_RIE_MASK)
#define LPUART_CTRL_TCIE_MASK                    (0x400000U)
#define LPUART_CTRL_TCIE_SHIFT                   (22U)
#define LPUART_CTRL_TCIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TCIE_SHIFT)) & LPUART_CTRL_TCIE_MASK)
#define LPUART_CTRL_TIE_MASK                     (0x800000U)
#define LPUART_CTRL_TIE_SHIFT                    (23U)
#define LPUART_CTRL_TIE(x)                       (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TIE_SHIFT)) & LPUART_CTRL_TIE_MASK)
#define LPUART_CTRL_PEIE_MASK                    (0x1000000U)
#define LPUART_CTRL_PEIE_SHIFT                   (24U)
#define LPUART_CTRL_PEIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_PEIE_SHIFT)) & LPUART_CTRL_PEIE_MASK)
#define LPUART_CTRL_FEIE_MASK                    (0x2000000U)
#define LPUART_CTRL_FEIE_SHIFT                   (25U)
#define LPUART_CTRL_FEIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_FEIE_SHIFT)) & LPUART_CTRL_FEIE_MASK)
#define LPUART_CTRL_NEIE_MASK                    (0x4000000U)
#define LPUART_CTRL_NEIE_SHIFT                   (26U)
#define LPUART_CTRL_NEIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_NEIE_SHIFT)) & LPUART_CTRL_NEIE_MASK)
#define LPUART_CTRL_ORIE_MASK                    (0x8000000U)
#define LPUART_CTRL_ORIE_SHIFT                   (27U)
#define LPUART_CTRL_ORIE(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_ORIE_SHIFT)) & LPUART_CTRL_ORIE_MASK)
#define LPUART_CTRL_TXINV_MASK                   (0x10000000U)
#define LPUART_CTRL_TXINV_SHIFT                  (28U)
#define LPUART_CTRL_TXINV(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TXINV_SHIFT)) & LPUART_CTRL_TXINV_MASK)
#define LPUART_CTRL_TXDIR_MASK                   (0x20000000U)
#define LPUART_CTRL_TXDIR_SHIFT                  (29U)
#define LPUART_CTRL_TXDIR(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_TXDIR_SHIFT)) & LPUART_CTRL_TXDIR_MASK)
#define LPUART_CTRL_R9T8_MASK                    (0x40000000U)
#define LPUART_CTRL_R9T8_SHIFT                   (30U)
#define LPUART_CTRL_R9T8(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_R9T8_SHIFT)) & LPUART_CTRL_R9T8_MASK)
#define LPUART_CTRL_R8T9_MASK                    (0x80000000U)
#define LPUART_CTRL_R8T9_SHIFT                   (31U)
#define LPUART_CTRL_R8T9(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_CTRL_R8T9_SHIFT)) & LPUART_CTRL_R8T9_MASK)

/*! @name DATA - LPUART Data Register */
#define LPUART_DATA_R0T0_MASK                    (0x1U)
#define LPUART_DATA_R0T0_SHIFT                   (0U)
#define LPUART_DATA_R0T0(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R0T0_SHIFT)) & LPUART_DATA_R0T0_MASK)
#define LPUART_DATA_R1T1_MASK                    (0x2U)
#define LPUART_DATA_R1T1_SHIFT                   (1U)
#define LPUART_DATA_R1T1(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R1T1_SHIFT)) & LPUART_DATA_R1T1_MASK)
#define LPUART_DATA_R2T2_MASK                    (0x4U)
#define LPUART_DATA_R2T2_SHIFT                   (2U)
#define LPUART_DATA_R2T2(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R2T2_SHIFT)) & LPUART_DATA_R2T2_MASK)
#define LPUART_DATA_R3T3_MASK                    (0x8U)
#define LPUART_DATA_R3T3_SHIFT                   (3U)
#define LPUART_DATA_R3T3(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R3T3_SHIFT)) & LPUART_DATA_R3T3_MASK)
#define LPUART_DATA_R4T4_MASK                    (0x10U)
#define LPUART_DATA_R4T4_SHIFT                   (4U)
#define LPUART_DATA_R4T4(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R4T4_SHIFT)) & LPUART_DATA_R4T4_MASK)
#define LPUART_DATA_R5T5_MASK                    (0x20U)
#define LPUART_DATA_R5T5_SHIFT                   (5U)
#define LPUART_DATA_R5T5(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R5T5_SHIFT)) & LPUART_DATA_R5T5_MASK)
#define LPUART_DATA_R6T6_MASK                    (0x40U)
#define LPUART_DATA_R6T6_SHIFT                   (6U)
#define LPUART_DATA_R6T6(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R6T6_SHIFT)) & LPUART_DATA_R6T6_MASK)
#define LPUART_DATA_R7T7_MASK                    (0x80U)
#define LPUART_DATA_R7T7_SHIFT                   (7U)
#define LPUART_DATA_R7T7(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R7T7_SHIFT)) & LPUART_DATA_R7T7_MASK)
#define LPUART_DATA_R8T8_MASK                    (0x100U)
#define LPUART_DATA_R8T8_SHIFT                   (8U)
#define LPUART_DATA_R8T8(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R8T8_SHIFT)) & LPUART_DATA_R8T8_MASK)
#define LPUART_DATA_R9T9_MASK                    (0x200U)
#define LPUART_DATA_R9T9_SHIFT                   (9U)
#define LPUART_DATA_R9T9(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_R9T9_SHIFT)) & LPUART_DATA_R9T9_MASK)
#define LPUART_DATA_IDLINE_MASK                  (0x800U)
#define LPUART_DATA_IDLINE_SHIFT                 (11U)
#define LPUART_DATA_IDLINE(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_IDLINE_SHIFT)) & LPUART_DATA_IDLINE_MASK)
#define LPUART_DATA_RXEMPT_MASK                  (0x1000U)
#define LPUART_DATA_RXEMPT_SHIFT                 (12U)
#define LPUART_DATA_RXEMPT(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_RXEMPT_SHIFT)) & LPUART_DATA_RXEMPT_MASK)
#define LPUART_DATA_FRETSC_MASK                  (0x2000U)
#define LPUART_DATA_FRETSC_SHIFT                 (13U)
#define LPUART_DATA_FRETSC(x)                    (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_FRETSC_SHIFT)) & LPUART_DATA_FRETSC_MASK)
#define LPUART_DATA_PARITYE_MASK                 (0x4000U)
#define LPUART_DATA_PARITYE_SHIFT                (14U)
#define LPUART_DATA_PARITYE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_PARITYE_SHIFT)) & LPUART_DATA_PARITYE_MASK)
#define LPUART_DATA_NOISY_MASK                   (0x8000U)
#define LPUART_DATA_NOISY_SHIFT                  (15U)
#define LPUART_DATA_NOISY(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_DATA_NOISY_SHIFT)) & LPUART_DATA_NOISY_MASK)

/*! @name MATCH - LPUART Match Address Register */
#define LPUART_MATCH_MA1_MASK                    (0x3FFU)
#define LPUART_MATCH_MA1_SHIFT                   (0U)
#define LPUART_MATCH_MA1(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_MATCH_MA1_SHIFT)) & LPUART_MATCH_MA1_MASK)
#define LPUART_MATCH_MA2_MASK                    (0x3FF0000U)
#define LPUART_MATCH_MA2_SHIFT                   (16U)
#define LPUART_MATCH_MA2(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_MATCH_MA2_SHIFT)) & LPUART_MATCH_MA2_MASK)

/*! @name MODIR - LPUART Modem IrDA Register */
#define LPUART_MODIR_TXCTSE_MASK                 (0x1U)
#define LPUART_MODIR_TXCTSE_SHIFT                (0U)
#define LPUART_MODIR_TXCTSE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXCTSE_SHIFT)) & LPUART_MODIR_TXCTSE_MASK)
#define LPUART_MODIR_TXRTSE_MASK                 (0x2U)
#define LPUART_MODIR_TXRTSE_SHIFT                (1U)
#define LPUART_MODIR_TXRTSE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXRTSE_SHIFT)) & LPUART_MODIR_TXRTSE_MASK)
#define LPUART_MODIR_TXRTSPOL_MASK               (0x4U)
#define LPUART_MODIR_TXRTSPOL_SHIFT              (2U)
#define LPUART_MODIR_TXRTSPOL(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXRTSPOL_SHIFT)) & LPUART_MODIR_TXRTSPOL_MASK)
#define LPUART_MODIR_RXRTSE_MASK                 (0x8U)
#define LPUART_MODIR_RXRTSE_SHIFT                (3U)
#define LPUART_MODIR_RXRTSE(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_RXRTSE_SHIFT)) & LPUART_MODIR_RXRTSE_MASK)
#define LPUART_MODIR_TXCTSC_MASK                 (0x10U)
#define LPUART_MODIR_TXCTSC_SHIFT                (4U)
#define LPUART_MODIR_TXCTSC(x)                   (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXCTSC_SHIFT)) & LPUART_MODIR_TXCTSC_MASK)
#define LPUART_MODIR_TXCTSSRC_MASK               (0x20U)
#define LPUART_MODIR_TXCTSSRC_SHIFT              (5U)
#define LPUART_MODIR_TXCTSSRC(x)                 (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TXCTSSRC_SHIFT)) & LPUART_MODIR_TXCTSSRC_MASK)
#define LPUART_MODIR_TNP_MASK                    (0x30000U)
#define LPUART_MODIR_TNP_SHIFT                   (16U)
#define LPUART_MODIR_TNP(x)                      (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_TNP_SHIFT)) & LPUART_MODIR_TNP_MASK)
#define LPUART_MODIR_IREN_MASK                   (0x40000U)
#define LPUART_MODIR_IREN_SHIFT                  (18U)
#define LPUART_MODIR_IREN(x)                     (((uint32_t)(((uint32_t)(x)) << LPUART_MODIR_IREN_SHIFT)) & LPUART_MODIR_IREN_MASK)


/*!
 * @}
 */ /* end of group LPUART_Register_Masks */


/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x4002A000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_IRQn }

/*!
 * @}
 */ /* end of group LPUART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Peripheral_Access_Layer MCG Peripheral Access Layer
 * @{
 */

/** MCG - Register Layout Typedef */
typedef struct {
  __IO uint8_t C1;                                 /**< MCG Control 1 Register, offset: 0x0 */
  __IO uint8_t C2;                                 /**< MCG Control 2 Register, offset: 0x1 */
  __IO uint8_t C3;                                 /**< MCG Control 3 Register, offset: 0x2 */
  __IO uint8_t C4;                                 /**< MCG Control 4 Register, offset: 0x3 */
  __IO uint8_t C5;                                 /**< MCG Control 5 Register, offset: 0x4 */
  __IO uint8_t C6;                                 /**< MCG Control 6 Register, offset: 0x5 */
  __IO uint8_t S;                                  /**< MCG Status Register, offset: 0x6 */
       uint8_t RESERVED_0[1];
  __IO uint8_t SC;                                 /**< MCG Status and Control Register, offset: 0x8 */
       uint8_t RESERVED_1[1];
  __IO uint8_t ATCVH;                              /**< MCG Auto Trim Compare Value High Register, offset: 0xA */
  __IO uint8_t ATCVL;                              /**< MCG Auto Trim Compare Value Low Register, offset: 0xB */
  __IO uint8_t C7;                                 /**< MCG Control 7 Register, offset: 0xC */
  __IO uint8_t C8;                                 /**< MCG Control 8 Register, offset: 0xD */
} MCG_Type;

/* ----------------------------------------------------------------------------
   -- MCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Register_Masks MCG Register Masks
 * @{
 */

/*! @name C1 - MCG Control 1 Register */
#define MCG_C1_IREFSTEN_MASK                     (0x1U)
#define MCG_C1_IREFSTEN_SHIFT                    (0U)
#define MCG_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_C1_IREFSTEN_SHIFT)) & MCG_C1_IREFSTEN_MASK)
#define MCG_C1_IRCLKEN_MASK                      (0x2U)
#define MCG_C1_IRCLKEN_SHIFT                     (1U)
#define MCG_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x)) << MCG_C1_IRCLKEN_SHIFT)) & MCG_C1_IRCLKEN_MASK)
#define MCG_C1_IREFS_MASK                        (0x4U)
#define MCG_C1_IREFS_SHIFT                       (2U)
#define MCG_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C1_IREFS_SHIFT)) & MCG_C1_IREFS_MASK)
#define MCG_C1_FRDIV_MASK                        (0x38U)
#define MCG_C1_FRDIV_SHIFT                       (3U)
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C1_FRDIV_SHIFT)) & MCG_C1_FRDIV_MASK)
#define MCG_C1_CLKS_MASK                         (0xC0U)
#define MCG_C1_CLKS_SHIFT                        (6U)
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C1_CLKS_SHIFT)) & MCG_C1_CLKS_MASK)

/*! @name C2 - MCG Control 2 Register */
#define MCG_C2_IRCS_MASK                         (0x1U)
#define MCG_C2_IRCS_SHIFT                        (0U)
#define MCG_C2_IRCS(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C2_IRCS_SHIFT)) & MCG_C2_IRCS_MASK)
#define MCG_C2_LP_MASK                           (0x2U)
#define MCG_C2_LP_SHIFT                          (1U)
#define MCG_C2_LP(x)                             (((uint8_t)(((uint8_t)(x)) << MCG_C2_LP_SHIFT)) & MCG_C2_LP_MASK)
#define MCG_C2_EREFS_MASK                        (0x4U)
#define MCG_C2_EREFS_SHIFT                       (2U)
#define MCG_C2_EREFS(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C2_EREFS_SHIFT)) & MCG_C2_EREFS_MASK)
#define MCG_C2_HGO_MASK                          (0x8U)
#define MCG_C2_HGO_SHIFT                         (3U)
#define MCG_C2_HGO(x)                            (((uint8_t)(((uint8_t)(x)) << MCG_C2_HGO_SHIFT)) & MCG_C2_HGO_MASK)
#define MCG_C2_RANGE_MASK                        (0x30U)
#define MCG_C2_RANGE_SHIFT                       (4U)
#define MCG_C2_RANGE(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C2_RANGE_SHIFT)) & MCG_C2_RANGE_MASK)
#define MCG_C2_FCFTRIM_MASK                      (0x40U)
#define MCG_C2_FCFTRIM_SHIFT                     (6U)
#define MCG_C2_FCFTRIM(x)                        (((uint8_t)(((uint8_t)(x)) << MCG_C2_FCFTRIM_SHIFT)) & MCG_C2_FCFTRIM_MASK)
#define MCG_C2_LOCRE0_MASK                       (0x80U)
#define MCG_C2_LOCRE0_SHIFT                      (7U)
#define MCG_C2_LOCRE0(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C2_LOCRE0_SHIFT)) & MCG_C2_LOCRE0_MASK)

/*! @name C3 - MCG Control 3 Register */
#define MCG_C3_SCTRIM_MASK                       (0xFFU)
#define MCG_C3_SCTRIM_SHIFT                      (0U)
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C3_SCTRIM_SHIFT)) & MCG_C3_SCTRIM_MASK)

/*! @name C4 - MCG Control 4 Register */
#define MCG_C4_SCFTRIM_MASK                      (0x1U)
#define MCG_C4_SCFTRIM_SHIFT                     (0U)
#define MCG_C4_SCFTRIM(x)                        (((uint8_t)(((uint8_t)(x)) << MCG_C4_SCFTRIM_SHIFT)) & MCG_C4_SCFTRIM_MASK)
#define MCG_C4_FCTRIM_MASK                       (0x1EU)
#define MCG_C4_FCTRIM_SHIFT                      (1U)
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C4_FCTRIM_SHIFT)) & MCG_C4_FCTRIM_MASK)
#define MCG_C4_DRST_DRS_MASK                     (0x60U)
#define MCG_C4_DRST_DRS_SHIFT                    (5U)
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_C4_DRST_DRS_SHIFT)) & MCG_C4_DRST_DRS_MASK)
#define MCG_C4_DMX32_MASK                        (0x80U)
#define MCG_C4_DMX32_SHIFT                       (7U)
#define MCG_C4_DMX32(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C4_DMX32_SHIFT)) & MCG_C4_DMX32_MASK)

/*! @name C5 - MCG Control 5 Register */
#define MCG_C5_PRDIV0_MASK                       (0x1FU)
#define MCG_C5_PRDIV0_SHIFT                      (0U)
#define MCG_C5_PRDIV0(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C5_PRDIV0_SHIFT)) & MCG_C5_PRDIV0_MASK)
#define MCG_C5_PLLSTEN0_MASK                     (0x20U)
#define MCG_C5_PLLSTEN0_SHIFT                    (5U)
#define MCG_C5_PLLSTEN0(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_C5_PLLSTEN0_SHIFT)) & MCG_C5_PLLSTEN0_MASK)
#define MCG_C5_PLLCLKEN0_MASK                    (0x40U)
#define MCG_C5_PLLCLKEN0_SHIFT                   (6U)
#define MCG_C5_PLLCLKEN0(x)                      (((uint8_t)(((uint8_t)(x)) << MCG_C5_PLLCLKEN0_SHIFT)) & MCG_C5_PLLCLKEN0_MASK)

/*! @name C6 - MCG Control 6 Register */
#define MCG_C6_VDIV0_MASK                        (0x1FU)
#define MCG_C6_VDIV0_SHIFT                       (0U)
#define MCG_C6_VDIV0(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C6_VDIV0_SHIFT)) & MCG_C6_VDIV0_MASK)
#define MCG_C6_CME0_MASK                         (0x20U)
#define MCG_C6_CME0_SHIFT                        (5U)
#define MCG_C6_CME0(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C6_CME0_SHIFT)) & MCG_C6_CME0_MASK)
#define MCG_C6_PLLS_MASK                         (0x40U)
#define MCG_C6_PLLS_SHIFT                        (6U)
#define MCG_C6_PLLS(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C6_PLLS_SHIFT)) & MCG_C6_PLLS_MASK)
#define MCG_C6_LOLIE0_MASK                       (0x80U)
#define MCG_C6_LOLIE0_SHIFT                      (7U)
#define MCG_C6_LOLIE0(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C6_LOLIE0_SHIFT)) & MCG_C6_LOLIE0_MASK)

/*! @name S - MCG Status Register */
#define MCG_S_IRCST_MASK                         (0x1U)
#define MCG_S_IRCST_SHIFT                        (0U)
#define MCG_S_IRCST(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_IRCST_SHIFT)) & MCG_S_IRCST_MASK)
#define MCG_S_OSCINIT0_MASK                      (0x2U)
#define MCG_S_OSCINIT0_SHIFT                     (1U)
#define MCG_S_OSCINIT0(x)                        (((uint8_t)(((uint8_t)(x)) << MCG_S_OSCINIT0_SHIFT)) & MCG_S_OSCINIT0_MASK)
#define MCG_S_CLKST_MASK                         (0xCU)
#define MCG_S_CLKST_SHIFT                        (2U)
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_CLKST_SHIFT)) & MCG_S_CLKST_MASK)
#define MCG_S_IREFST_MASK                        (0x10U)
#define MCG_S_IREFST_SHIFT                       (4U)
#define MCG_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_S_IREFST_SHIFT)) & MCG_S_IREFST_MASK)
#define MCG_S_PLLST_MASK                         (0x20U)
#define MCG_S_PLLST_SHIFT                        (5U)
#define MCG_S_PLLST(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_PLLST_SHIFT)) & MCG_S_PLLST_MASK)
#define MCG_S_LOCK0_MASK                         (0x40U)
#define MCG_S_LOCK0_SHIFT                        (6U)
#define MCG_S_LOCK0(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_LOCK0_SHIFT)) & MCG_S_LOCK0_MASK)
#define MCG_S_LOLS0_MASK                         (0x80U)
#define MCG_S_LOLS0_SHIFT                        (7U)
#define MCG_S_LOLS0(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_S_LOLS0_SHIFT)) & MCG_S_LOLS0_MASK)

/*! @name SC - MCG Status and Control Register */
#define MCG_SC_LOCS0_MASK                        (0x1U)
#define MCG_SC_LOCS0_SHIFT                       (0U)
#define MCG_SC_LOCS0(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_SC_LOCS0_SHIFT)) & MCG_SC_LOCS0_MASK)
#define MCG_SC_FCRDIV_MASK                       (0xEU)
#define MCG_SC_FCRDIV_SHIFT                      (1U)
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_SC_FCRDIV_SHIFT)) & MCG_SC_FCRDIV_MASK)
#define MCG_SC_FLTPRSRV_MASK                     (0x10U)
#define MCG_SC_FLTPRSRV_SHIFT                    (4U)
#define MCG_SC_FLTPRSRV(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_SC_FLTPRSRV_SHIFT)) & MCG_SC_FLTPRSRV_MASK)
#define MCG_SC_ATMF_MASK                         (0x20U)
#define MCG_SC_ATMF_SHIFT                        (5U)
#define MCG_SC_ATMF(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_SC_ATMF_SHIFT)) & MCG_SC_ATMF_MASK)
#define MCG_SC_ATMS_MASK                         (0x40U)
#define MCG_SC_ATMS_SHIFT                        (6U)
#define MCG_SC_ATMS(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_SC_ATMS_SHIFT)) & MCG_SC_ATMS_MASK)
#define MCG_SC_ATME_MASK                         (0x80U)
#define MCG_SC_ATME_SHIFT                        (7U)
#define MCG_SC_ATME(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_SC_ATME_SHIFT)) & MCG_SC_ATME_MASK)

/*! @name ATCVH - MCG Auto Trim Compare Value High Register */
#define MCG_ATCVH_ATCVH_MASK                     (0xFFU)
#define MCG_ATCVH_ATCVH_SHIFT                    (0U)
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_ATCVH_ATCVH_SHIFT)) & MCG_ATCVH_ATCVH_MASK)

/*! @name ATCVL - MCG Auto Trim Compare Value Low Register */
#define MCG_ATCVL_ATCVL_MASK                     (0xFFU)
#define MCG_ATCVL_ATCVL_SHIFT                    (0U)
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x)) << MCG_ATCVL_ATCVL_SHIFT)) & MCG_ATCVL_ATCVL_MASK)

/*! @name C7 - MCG Control 7 Register */
#define MCG_C7_OSCSEL_MASK                       (0x3U)
#define MCG_C7_OSCSEL_SHIFT                      (0U)
#define MCG_C7_OSCSEL(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C7_OSCSEL_SHIFT)) & MCG_C7_OSCSEL_MASK)

/*! @name C8 - MCG Control 8 Register */
#define MCG_C8_LOCS1_MASK                        (0x1U)
#define MCG_C8_LOCS1_SHIFT                       (0U)
#define MCG_C8_LOCS1(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C8_LOCS1_SHIFT)) & MCG_C8_LOCS1_MASK)
#define MCG_C8_CME1_MASK                         (0x20U)
#define MCG_C8_CME1_SHIFT                        (5U)
#define MCG_C8_CME1(x)                           (((uint8_t)(((uint8_t)(x)) << MCG_C8_CME1_SHIFT)) & MCG_C8_CME1_MASK)
#define MCG_C8_LOLRE_MASK                        (0x40U)
#define MCG_C8_LOLRE_SHIFT                       (6U)
#define MCG_C8_LOLRE(x)                          (((uint8_t)(((uint8_t)(x)) << MCG_C8_LOLRE_SHIFT)) & MCG_C8_LOLRE_MASK)
#define MCG_C8_LOCRE1_MASK                       (0x80U)
#define MCG_C8_LOCRE1_SHIFT                      (7U)
#define MCG_C8_LOCRE1(x)                         (((uint8_t)(((uint8_t)(x)) << MCG_C8_LOCRE1_SHIFT)) & MCG_C8_LOCRE1_MASK)


/*!
 * @}
 */ /* end of group MCG_Register_Masks */


/* MCG - Peripheral instance base addresses */
/** Peripheral MCG base address */
#define MCG_BASE                                 (0x40064000u)
/** Peripheral MCG base pointer */
#define MCG                                      ((MCG_Type *)MCG_BASE)
/** Array initializer of MCG peripheral base addresses */
#define MCG_BASE_ADDRS                           { MCG_BASE }
/** Array initializer of MCG peripheral base pointers */
#define MCG_BASE_PTRS                            { MCG }

/*!
 * @}
 */ /* end of group MCG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __I  uint16_t PLASC;                             /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  __I  uint16_t PLAMC;                             /**< Crossbar Switch (AXBS) Master Configuration, offset: 0xA */
  __IO uint32_t PLACR;                             /**< Crossbar Switch (AXBS) Control Register, offset: 0xC */
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control Register, offset: 0x10 */
       uint8_t RESERVED_1[44];
  __IO uint32_t CPO;                               /**< Compute Operation Control Register, offset: 0x40 */
} MCM_Type;

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/*! @name PLASC - Crossbar Switch (AXBS) Slave Configuration */
#define MCM_PLASC_ASC_MASK                       (0xFFU)
#define MCM_PLASC_ASC_SHIFT                      (0U)
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC_SHIFT)) & MCM_PLASC_ASC_MASK)

/*! @name PLAMC - Crossbar Switch (AXBS) Master Configuration */
#define MCM_PLAMC_AMC_MASK                       (0xFFU)
#define MCM_PLAMC_AMC_SHIFT                      (0U)
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC_SHIFT)) & MCM_PLAMC_AMC_MASK)

/*! @name PLACR - Crossbar Switch (AXBS) Control Register */
#define MCM_PLACR_ARB_MASK                       (0x200U)
#define MCM_PLACR_ARB_SHIFT                      (9U)
#define MCM_PLACR_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_PLACR_ARB_SHIFT)) & MCM_PLACR_ARB_MASK)

/*! @name ISCR - Interrupt Status and Control Register */
#define MCM_ISCR_FIOC_MASK                       (0x100U)
#define MCM_ISCR_FIOC_SHIFT                      (8U)
#define MCM_ISCR_FIOC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOC_SHIFT)) & MCM_ISCR_FIOC_MASK)
#define MCM_ISCR_FDZC_MASK                       (0x200U)
#define MCM_ISCR_FDZC_SHIFT                      (9U)
#define MCM_ISCR_FDZC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZC_SHIFT)) & MCM_ISCR_FDZC_MASK)
#define MCM_ISCR_FOFC_MASK                       (0x400U)
#define MCM_ISCR_FOFC_SHIFT                      (10U)
#define MCM_ISCR_FOFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFC_SHIFT)) & MCM_ISCR_FOFC_MASK)
#define MCM_ISCR_FUFC_MASK                       (0x800U)
#define MCM_ISCR_FUFC_SHIFT                      (11U)
#define MCM_ISCR_FUFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFC_SHIFT)) & MCM_ISCR_FUFC_MASK)
#define MCM_ISCR_FIXC_MASK                       (0x1000U)
#define MCM_ISCR_FIXC_SHIFT                      (12U)
#define MCM_ISCR_FIXC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXC_SHIFT)) & MCM_ISCR_FIXC_MASK)
#define MCM_ISCR_FIDC_MASK                       (0x8000U)
#define MCM_ISCR_FIDC_SHIFT                      (15U)
#define MCM_ISCR_FIDC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDC_SHIFT)) & MCM_ISCR_FIDC_MASK)
#define MCM_ISCR_FIOCE_MASK                      (0x1000000U)
#define MCM_ISCR_FIOCE_SHIFT                     (24U)
#define MCM_ISCR_FIOCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOCE_SHIFT)) & MCM_ISCR_FIOCE_MASK)
#define MCM_ISCR_FDZCE_MASK                      (0x2000000U)
#define MCM_ISCR_FDZCE_SHIFT                     (25U)
#define MCM_ISCR_FDZCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZCE_SHIFT)) & MCM_ISCR_FDZCE_MASK)
#define MCM_ISCR_FOFCE_MASK                      (0x4000000U)
#define MCM_ISCR_FOFCE_SHIFT                     (26U)
#define MCM_ISCR_FOFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFCE_SHIFT)) & MCM_ISCR_FOFCE_MASK)
#define MCM_ISCR_FUFCE_MASK                      (0x8000000U)
#define MCM_ISCR_FUFCE_SHIFT                     (27U)
#define MCM_ISCR_FUFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFCE_SHIFT)) & MCM_ISCR_FUFCE_MASK)
#define MCM_ISCR_FIXCE_MASK                      (0x10000000U)
#define MCM_ISCR_FIXCE_SHIFT                     (28U)
#define MCM_ISCR_FIXCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXCE_SHIFT)) & MCM_ISCR_FIXCE_MASK)
#define MCM_ISCR_FIDCE_MASK                      (0x80000000U)
#define MCM_ISCR_FIDCE_SHIFT                     (31U)
#define MCM_ISCR_FIDCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDCE_SHIFT)) & MCM_ISCR_FIDCE_MASK)

/*! @name CPO - Compute Operation Control Register */
#define MCM_CPO_CPOREQ_MASK                      (0x1U)
#define MCM_CPO_CPOREQ_SHIFT                     (0U)
#define MCM_CPO_CPOREQ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOREQ_SHIFT)) & MCM_CPO_CPOREQ_MASK)
#define MCM_CPO_CPOACK_MASK                      (0x2U)
#define MCM_CPO_CPOACK_SHIFT                     (1U)
#define MCM_CPO_CPOACK(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOACK_SHIFT)) & MCM_CPO_CPOACK_MASK)
#define MCM_CPO_CPOWOI_MASK                      (0x4U)
#define MCM_CPO_CPOWOI_SHIFT                     (2U)
#define MCM_CPO_CPOWOI(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOWOI_SHIFT)) & MCM_CPO_CPOWOI_MASK)


/*!
 * @}
 */ /* end of group MCM_Register_Masks */


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
#define MCM_IRQS                                 { MCM_IRQn }

/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- NV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Peripheral_Access_Layer NV Peripheral Access Layer
 * @{
 */

/** NV - Register Layout Typedef */
typedef struct {
  __I  uint8_t BACKKEY3;                           /**< Backdoor Comparison Key 3., offset: 0x0 */
  __I  uint8_t BACKKEY2;                           /**< Backdoor Comparison Key 2., offset: 0x1 */
  __I  uint8_t BACKKEY1;                           /**< Backdoor Comparison Key 1., offset: 0x2 */
  __I  uint8_t BACKKEY0;                           /**< Backdoor Comparison Key 0., offset: 0x3 */
  __I  uint8_t BACKKEY7;                           /**< Backdoor Comparison Key 7., offset: 0x4 */
  __I  uint8_t BACKKEY6;                           /**< Backdoor Comparison Key 6., offset: 0x5 */
  __I  uint8_t BACKKEY5;                           /**< Backdoor Comparison Key 5., offset: 0x6 */
  __I  uint8_t BACKKEY4;                           /**< Backdoor Comparison Key 4., offset: 0x7 */
  __I  uint8_t FPROT3;                             /**< Non-volatile P-Flash Protection 1 - Low Register, offset: 0x8 */
  __I  uint8_t FPROT2;                             /**< Non-volatile P-Flash Protection 1 - High Register, offset: 0x9 */
  __I  uint8_t FPROT1;                             /**< Non-volatile P-Flash Protection 0 - Low Register, offset: 0xA */
  __I  uint8_t FPROT0;                             /**< Non-volatile P-Flash Protection 0 - High Register, offset: 0xB */
  __I  uint8_t FSEC;                               /**< Non-volatile Flash Security Register, offset: 0xC */
  __I  uint8_t FOPT;                               /**< Non-volatile Flash Option Register, offset: 0xD */
} NV_Type;

/* ----------------------------------------------------------------------------
   -- NV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Masks NV Register Masks
 * @{
 */

/*! @name BACKKEY3 - Backdoor Comparison Key 3. */
#define NV_BACKKEY3_KEY_MASK                     (0xFFU)
#define NV_BACKKEY3_KEY_SHIFT                    (0U)
#define NV_BACKKEY3_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY3_KEY_SHIFT)) & NV_BACKKEY3_KEY_MASK)

/*! @name BACKKEY2 - Backdoor Comparison Key 2. */
#define NV_BACKKEY2_KEY_MASK                     (0xFFU)
#define NV_BACKKEY2_KEY_SHIFT                    (0U)
#define NV_BACKKEY2_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY2_KEY_SHIFT)) & NV_BACKKEY2_KEY_MASK)

/*! @name BACKKEY1 - Backdoor Comparison Key 1. */
#define NV_BACKKEY1_KEY_MASK                     (0xFFU)
#define NV_BACKKEY1_KEY_SHIFT                    (0U)
#define NV_BACKKEY1_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY1_KEY_SHIFT)) & NV_BACKKEY1_KEY_MASK)

/*! @name BACKKEY0 - Backdoor Comparison Key 0. */
#define NV_BACKKEY0_KEY_MASK                     (0xFFU)
#define NV_BACKKEY0_KEY_SHIFT                    (0U)
#define NV_BACKKEY0_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY0_KEY_SHIFT)) & NV_BACKKEY0_KEY_MASK)

/*! @name BACKKEY7 - Backdoor Comparison Key 7. */
#define NV_BACKKEY7_KEY_MASK                     (0xFFU)
#define NV_BACKKEY7_KEY_SHIFT                    (0U)
#define NV_BACKKEY7_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY7_KEY_SHIFT)) & NV_BACKKEY7_KEY_MASK)

/*! @name BACKKEY6 - Backdoor Comparison Key 6. */
#define NV_BACKKEY6_KEY_MASK                     (0xFFU)
#define NV_BACKKEY6_KEY_SHIFT                    (0U)
#define NV_BACKKEY6_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY6_KEY_SHIFT)) & NV_BACKKEY6_KEY_MASK)

/*! @name BACKKEY5 - Backdoor Comparison Key 5. */
#define NV_BACKKEY5_KEY_MASK                     (0xFFU)
#define NV_BACKKEY5_KEY_SHIFT                    (0U)
#define NV_BACKKEY5_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY5_KEY_SHIFT)) & NV_BACKKEY5_KEY_MASK)

/*! @name BACKKEY4 - Backdoor Comparison Key 4. */
#define NV_BACKKEY4_KEY_MASK                     (0xFFU)
#define NV_BACKKEY4_KEY_SHIFT                    (0U)
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY4_KEY_SHIFT)) & NV_BACKKEY4_KEY_MASK)

/*! @name FPROT3 - Non-volatile P-Flash Protection 1 - Low Register */
#define NV_FPROT3_PROT_MASK                      (0xFFU)
#define NV_FPROT3_PROT_SHIFT                     (0U)
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT3_PROT_SHIFT)) & NV_FPROT3_PROT_MASK)

/*! @name FPROT2 - Non-volatile P-Flash Protection 1 - High Register */
#define NV_FPROT2_PROT_MASK                      (0xFFU)
#define NV_FPROT2_PROT_SHIFT                     (0U)
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT2_PROT_SHIFT)) & NV_FPROT2_PROT_MASK)

/*! @name FPROT1 - Non-volatile P-Flash Protection 0 - Low Register */
#define NV_FPROT1_PROT_MASK                      (0xFFU)
#define NV_FPROT1_PROT_SHIFT                     (0U)
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT1_PROT_SHIFT)) & NV_FPROT1_PROT_MASK)

/*! @name FPROT0 - Non-volatile P-Flash Protection 0 - High Register */
#define NV_FPROT0_PROT_MASK                      (0xFFU)
#define NV_FPROT0_PROT_SHIFT                     (0U)
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT0_PROT_SHIFT)) & NV_FPROT0_PROT_MASK)

/*! @name FSEC - Non-volatile Flash Security Register */
#define NV_FSEC_SEC_MASK                         (0x3U)
#define NV_FSEC_SEC_SHIFT                        (0U)
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x)) << NV_FSEC_SEC_SHIFT)) & NV_FSEC_SEC_MASK)
#define NV_FSEC_FSLACC_MASK                      (0xCU)
#define NV_FSEC_FSLACC_SHIFT                     (2U)
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FSEC_FSLACC_SHIFT)) & NV_FSEC_FSLACC_MASK)
#define NV_FSEC_MEEN_MASK                        (0x30U)
#define NV_FSEC_MEEN_SHIFT                       (4U)
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x)) << NV_FSEC_MEEN_SHIFT)) & NV_FSEC_MEEN_MASK)
#define NV_FSEC_KEYEN_MASK                       (0xC0U)
#define NV_FSEC_KEYEN_SHIFT                      (6U)
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x)) << NV_FSEC_KEYEN_SHIFT)) & NV_FSEC_KEYEN_MASK)

/*! @name FOPT - Non-volatile Flash Option Register */
#define NV_FOPT_LPBOOT_MASK                      (0x1U)
#define NV_FOPT_LPBOOT_SHIFT                     (0U)
#define NV_FOPT_LPBOOT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FOPT_LPBOOT_SHIFT)) & NV_FOPT_LPBOOT_MASK)
#define NV_FOPT_EZPORT_DIS_MASK                  (0x2U)
#define NV_FOPT_EZPORT_DIS_SHIFT                 (1U)
#define NV_FOPT_EZPORT_DIS(x)                    (((uint8_t)(((uint8_t)(x)) << NV_FOPT_EZPORT_DIS_SHIFT)) & NV_FOPT_EZPORT_DIS_MASK)
#define NV_FOPT_NMI_DIS_MASK                     (0x4U)
#define NV_FOPT_NMI_DIS_SHIFT                    (2U)
#define NV_FOPT_NMI_DIS(x)                       (((uint8_t)(((uint8_t)(x)) << NV_FOPT_NMI_DIS_SHIFT)) & NV_FOPT_NMI_DIS_MASK)
#define NV_FOPT_FAST_INIT_MASK                   (0x20U)
#define NV_FOPT_FAST_INIT_SHIFT                  (5U)
#define NV_FOPT_FAST_INIT(x)                     (((uint8_t)(((uint8_t)(x)) << NV_FOPT_FAST_INIT_SHIFT)) & NV_FOPT_FAST_INIT_MASK)


/*!
 * @}
 */ /* end of group NV_Register_Masks */


/* NV - Peripheral instance base addresses */
/** Peripheral FTFA_FlashConfig base address */
#define FTFA_FlashConfig_BASE                    (0x400u)
/** Peripheral FTFA_FlashConfig base pointer */
#define FTFA_FlashConfig                         ((NV_Type *)FTFA_FlashConfig_BASE)
/** Array initializer of NV peripheral base addresses */
#define NV_BASE_ADDRS                            { FTFA_FlashConfig_BASE }
/** Array initializer of NV peripheral base pointers */
#define NV_BASE_PTRS                             { FTFA_FlashConfig }

/*!
 * @}
 */ /* end of group NV_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- OSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Peripheral_Access_Layer OSC Peripheral Access Layer
 * @{
 */

/** OSC - Register Layout Typedef */
typedef struct {
  __IO uint8_t CR;                                 /**< OSC Control Register, offset: 0x0 */
       uint8_t RESERVED_0[1];
  __IO uint8_t DIV;                                /**< OSC_DIV, offset: 0x2 */
} OSC_Type;

/* ----------------------------------------------------------------------------
   -- OSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Masks OSC Register Masks
 * @{
 */

/*! @name CR - OSC Control Register */
#define OSC_CR_SC16P_MASK                        (0x1U)
#define OSC_CR_SC16P_SHIFT                       (0U)
#define OSC_CR_SC16P(x)                          (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC16P_SHIFT)) & OSC_CR_SC16P_MASK)
#define OSC_CR_SC8P_MASK                         (0x2U)
#define OSC_CR_SC8P_SHIFT                        (1U)
#define OSC_CR_SC8P(x)                           (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC8P_SHIFT)) & OSC_CR_SC8P_MASK)
#define OSC_CR_SC4P_MASK                         (0x4U)
#define OSC_CR_SC4P_SHIFT                        (2U)
#define OSC_CR_SC4P(x)                           (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC4P_SHIFT)) & OSC_CR_SC4P_MASK)
#define OSC_CR_SC2P_MASK                         (0x8U)
#define OSC_CR_SC2P_SHIFT                        (3U)
#define OSC_CR_SC2P(x)                           (((uint8_t)(((uint8_t)(x)) << OSC_CR_SC2P_SHIFT)) & OSC_CR_SC2P_MASK)
#define OSC_CR_EREFSTEN_MASK                     (0x20U)
#define OSC_CR_EREFSTEN_SHIFT                    (5U)
#define OSC_CR_EREFSTEN(x)                       (((uint8_t)(((uint8_t)(x)) << OSC_CR_EREFSTEN_SHIFT)) & OSC_CR_EREFSTEN_MASK)
#define OSC_CR_ERCLKEN_MASK                      (0x80U)
#define OSC_CR_ERCLKEN_SHIFT                     (7U)
#define OSC_CR_ERCLKEN(x)                        (((uint8_t)(((uint8_t)(x)) << OSC_CR_ERCLKEN_SHIFT)) & OSC_CR_ERCLKEN_MASK)

/*! @name DIV - OSC_DIV */
#define OSC_DIV_ERPS_MASK                        (0xC0U)
#define OSC_DIV_ERPS_SHIFT                       (6U)
#define OSC_DIV_ERPS(x)                          (((uint8_t)(((uint8_t)(x)) << OSC_DIV_ERPS_SHIFT)) & OSC_DIV_ERPS_MASK)


/*!
 * @}
 */ /* end of group OSC_Register_Masks */


/* OSC - Peripheral instance base addresses */
/** Peripheral OSC base address */
#define OSC_BASE                                 (0x40065000u)
/** Peripheral OSC base pointer */
#define OSC                                      ((OSC_Type *)OSC_BASE)
/** Array initializer of OSC peripheral base addresses */
#define OSC_BASE_ADDRS                           { OSC_BASE }
/** Array initializer of OSC peripheral base pointers */
#define OSC_BASE_PTRS                            { OSC }

/*!
 * @}
 */ /* end of group OSC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PDB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Peripheral_Access_Layer PDB Peripheral Access Layer
 * @{
 */

/** PDB - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC;                                /**< Status and Control register, offset: 0x0 */
  __IO uint32_t MOD;                               /**< Modulus register, offset: 0x4 */
  __I  uint32_t CNT;                               /**< Counter register, offset: 0x8 */
  __IO uint32_t IDLY;                              /**< Interrupt Delay register, offset: 0xC */
  struct {                                         /* offset: 0x10, array step: 0x10 */
    __IO uint32_t C1;                                /**< Channel n Control register 1, array offset: 0x10, array step: 0x10 */
    __IO uint32_t S;                                 /**< Channel n Status register, array offset: 0x14, array step: 0x10 */
    __IO uint32_t DLY[2];                            /**< Channel n Delay 0 register..Channel n Delay 1 register, array offset: 0x18, array step: index*0x10, index2*0x4 */
  } CH[1];
       uint8_t RESERVED_0[304];
  struct {                                         /* offset: 0x150, array step: 0x8 */
    __IO uint32_t INTC;                              /**< DAC Interval Trigger n Control register, array offset: 0x150, array step: 0x8 */
    __IO uint32_t INT;                               /**< DAC Interval n register, array offset: 0x154, array step: 0x8 */
  } DAC[1];
       uint8_t RESERVED_1[56];
  __IO uint32_t POEN;                              /**< Pulse-Out n Enable register, offset: 0x190 */
  __IO uint32_t PODLY[1];                          /**< Pulse-Out n Delay register, array offset: 0x194, array step: 0x4 */
} PDB_Type;

/* ----------------------------------------------------------------------------
   -- PDB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Register_Masks PDB Register Masks
 * @{
 */

/*! @name SC - Status and Control register */
#define PDB_SC_LDOK_MASK                         (0x1U)
#define PDB_SC_LDOK_SHIFT                        (0U)
#define PDB_SC_LDOK(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_SC_LDOK_SHIFT)) & PDB_SC_LDOK_MASK)
#define PDB_SC_CONT_MASK                         (0x2U)
#define PDB_SC_CONT_SHIFT                        (1U)
#define PDB_SC_CONT(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_SC_CONT_SHIFT)) & PDB_SC_CONT_MASK)
#define PDB_SC_MULT_MASK                         (0xCU)
#define PDB_SC_MULT_SHIFT                        (2U)
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_SC_MULT_SHIFT)) & PDB_SC_MULT_MASK)
#define PDB_SC_PDBIE_MASK                        (0x20U)
#define PDB_SC_PDBIE_SHIFT                       (5U)
#define PDB_SC_PDBIE(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_SC_PDBIE_SHIFT)) & PDB_SC_PDBIE_MASK)
#define PDB_SC_PDBIF_MASK                        (0x40U)
#define PDB_SC_PDBIF_SHIFT                       (6U)
#define PDB_SC_PDBIF(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_SC_PDBIF_SHIFT)) & PDB_SC_PDBIF_MASK)
#define PDB_SC_PDBEN_MASK                        (0x80U)
#define PDB_SC_PDBEN_SHIFT                       (7U)
#define PDB_SC_PDBEN(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_SC_PDBEN_SHIFT)) & PDB_SC_PDBEN_MASK)
#define PDB_SC_TRGSEL_MASK                       (0xF00U)
#define PDB_SC_TRGSEL_SHIFT                      (8U)
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_SC_TRGSEL_SHIFT)) & PDB_SC_TRGSEL_MASK)
#define PDB_SC_PRESCALER_MASK                    (0x7000U)
#define PDB_SC_PRESCALER_SHIFT                   (12U)
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x)) << PDB_SC_PRESCALER_SHIFT)) & PDB_SC_PRESCALER_MASK)
#define PDB_SC_DMAEN_MASK                        (0x8000U)
#define PDB_SC_DMAEN_SHIFT                       (15U)
#define PDB_SC_DMAEN(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_SC_DMAEN_SHIFT)) & PDB_SC_DMAEN_MASK)
#define PDB_SC_SWTRIG_MASK                       (0x10000U)
#define PDB_SC_SWTRIG_SHIFT                      (16U)
#define PDB_SC_SWTRIG(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_SC_SWTRIG_SHIFT)) & PDB_SC_SWTRIG_MASK)
#define PDB_SC_PDBEIE_MASK                       (0x20000U)
#define PDB_SC_PDBEIE_SHIFT                      (17U)
#define PDB_SC_PDBEIE(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_SC_PDBEIE_SHIFT)) & PDB_SC_PDBEIE_MASK)
#define PDB_SC_LDMOD_MASK                        (0xC0000U)
#define PDB_SC_LDMOD_SHIFT                       (18U)
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_SC_LDMOD_SHIFT)) & PDB_SC_LDMOD_MASK)

/*! @name MOD - Modulus register */
#define PDB_MOD_MOD_MASK                         (0xFFFFU)
#define PDB_MOD_MOD_SHIFT                        (0U)
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_MOD_MOD_SHIFT)) & PDB_MOD_MOD_MASK)

/*! @name CNT - Counter register */
#define PDB_CNT_CNT_MASK                         (0xFFFFU)
#define PDB_CNT_CNT_SHIFT                        (0U)
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_CNT_CNT_SHIFT)) & PDB_CNT_CNT_MASK)

/*! @name IDLY - Interrupt Delay register */
#define PDB_IDLY_IDLY_MASK                       (0xFFFFU)
#define PDB_IDLY_IDLY_SHIFT                      (0U)
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_IDLY_IDLY_SHIFT)) & PDB_IDLY_IDLY_MASK)

/*! @name C1 - Channel n Control register 1 */
#define PDB_C1_EN_MASK                           (0xFFU)
#define PDB_C1_EN_SHIFT                          (0U)
#define PDB_C1_EN(x)                             (((uint32_t)(((uint32_t)(x)) << PDB_C1_EN_SHIFT)) & PDB_C1_EN_MASK)
#define PDB_C1_TOS_MASK                          (0xFF00U)
#define PDB_C1_TOS_SHIFT                         (8U)
#define PDB_C1_TOS(x)                            (((uint32_t)(((uint32_t)(x)) << PDB_C1_TOS_SHIFT)) & PDB_C1_TOS_MASK)
#define PDB_C1_BB_MASK                           (0xFF0000U)
#define PDB_C1_BB_SHIFT                          (16U)
#define PDB_C1_BB(x)                             (((uint32_t)(((uint32_t)(x)) << PDB_C1_BB_SHIFT)) & PDB_C1_BB_MASK)

/* The count of PDB_C1 */
#define PDB_C1_COUNT                             (1U)

/*! @name S - Channel n Status register */
#define PDB_S_ERR_MASK                           (0xFFU)
#define PDB_S_ERR_SHIFT                          (0U)
#define PDB_S_ERR(x)                             (((uint32_t)(((uint32_t)(x)) << PDB_S_ERR_SHIFT)) & PDB_S_ERR_MASK)
#define PDB_S_CF_MASK                            (0xFF0000U)
#define PDB_S_CF_SHIFT                           (16U)
#define PDB_S_CF(x)                              (((uint32_t)(((uint32_t)(x)) << PDB_S_CF_SHIFT)) & PDB_S_CF_MASK)

/* The count of PDB_S */
#define PDB_S_COUNT                              (1U)

/*! @name DLY - Channel n Delay 0 register..Channel n Delay 1 register */
#define PDB_DLY_DLY_MASK                         (0xFFFFU)
#define PDB_DLY_DLY_SHIFT                        (0U)
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_DLY_DLY_SHIFT)) & PDB_DLY_DLY_MASK)

/* The count of PDB_DLY */
#define PDB_DLY_COUNT                            (1U)

/* The count of PDB_DLY */
#define PDB_DLY_COUNT2                           (2U)

/*! @name INTC - DAC Interval Trigger n Control register */
#define PDB_INTC_TOE_MASK                        (0x1U)
#define PDB_INTC_TOE_SHIFT                       (0U)
#define PDB_INTC_TOE(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_INTC_TOE_SHIFT)) & PDB_INTC_TOE_MASK)
#define PDB_INTC_EXT_MASK                        (0x2U)
#define PDB_INTC_EXT_SHIFT                       (1U)
#define PDB_INTC_EXT(x)                          (((uint32_t)(((uint32_t)(x)) << PDB_INTC_EXT_SHIFT)) & PDB_INTC_EXT_MASK)

/* The count of PDB_INTC */
#define PDB_INTC_COUNT                           (1U)

/*! @name INT - DAC Interval n register */
#define PDB_INT_INT_MASK                         (0xFFFFU)
#define PDB_INT_INT_SHIFT                        (0U)
#define PDB_INT_INT(x)                           (((uint32_t)(((uint32_t)(x)) << PDB_INT_INT_SHIFT)) & PDB_INT_INT_MASK)

/* The count of PDB_INT */
#define PDB_INT_COUNT                            (1U)

/*! @name POEN - Pulse-Out n Enable register */
#define PDB_POEN_POEN_MASK                       (0xFFU)
#define PDB_POEN_POEN_SHIFT                      (0U)
#define PDB_POEN_POEN(x)                         (((uint32_t)(((uint32_t)(x)) << PDB_POEN_POEN_SHIFT)) & PDB_POEN_POEN_MASK)

/*! @name PODLY - Pulse-Out n Delay register */
#define PDB_PODLY_DLY2_MASK                      (0xFFFFU)
#define PDB_PODLY_DLY2_SHIFT                     (0U)
#define PDB_PODLY_DLY2(x)                        (((uint32_t)(((uint32_t)(x)) << PDB_PODLY_DLY2_SHIFT)) & PDB_PODLY_DLY2_MASK)
#define PDB_PODLY_DLY1_MASK                      (0xFFFF0000U)
#define PDB_PODLY_DLY1_SHIFT                     (16U)
#define PDB_PODLY_DLY1(x)                        (((uint32_t)(((uint32_t)(x)) << PDB_PODLY_DLY1_SHIFT)) & PDB_PODLY_DLY1_MASK)

/* The count of PDB_PODLY */
#define PDB_PODLY_COUNT                          (1U)


/*!
 * @}
 */ /* end of group PDB_Register_Masks */


/* PDB - Peripheral instance base addresses */
/** Peripheral PDB0 base address */
#define PDB0_BASE                                (0x40036000u)
/** Peripheral PDB0 base pointer */
#define PDB0                                     ((PDB_Type *)PDB0_BASE)
/** Array initializer of PDB peripheral base addresses */
#define PDB_BASE_ADDRS                           { PDB0_BASE }
/** Array initializer of PDB peripheral base pointers */
#define PDB_BASE_PTRS                            { PDB0 }
/** Interrupt vectors for the PDB peripheral type */
#define PDB_IRQS                                 { PDB0_IRQn }

/*!
 * @}
 */ /* end of group PDB_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Peripheral_Access_Layer PIT Peripheral Access Layer
 * @{
 */

/** PIT - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< PIT Module Control Register, offset: 0x0 */
       uint8_t RESERVED_0[220];
  __I  uint32_t LTMR64H;                           /**< PIT Upper Lifetime Timer Register, offset: 0xE0 */
  __I  uint32_t LTMR64L;                           /**< PIT Lower Lifetime Timer Register, offset: 0xE4 */
       uint8_t RESERVED_1[24];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    __IO uint32_t LDVAL;                             /**< Timer Load Value Register, array offset: 0x100, array step: 0x10 */
    __I  uint32_t CVAL;                              /**< Current Timer Value Register, array offset: 0x104, array step: 0x10 */
    __IO uint32_t TCTRL;                             /**< Timer Control Register, array offset: 0x108, array step: 0x10 */
    __IO uint32_t TFLG;                              /**< Timer Flag Register, array offset: 0x10C, array step: 0x10 */
  } CHANNEL[4];
} PIT_Type;

/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Masks PIT Register Masks
 * @{
 */

/*! @name MCR - PIT Module Control Register */
#define PIT_MCR_FRZ_MASK                         (0x1U)
#define PIT_MCR_FRZ_SHIFT                        (0U)
#define PIT_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x)) << PIT_MCR_FRZ_SHIFT)) & PIT_MCR_FRZ_MASK)
#define PIT_MCR_MDIS_MASK                        (0x2U)
#define PIT_MCR_MDIS_SHIFT                       (1U)
#define PIT_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x)) << PIT_MCR_MDIS_SHIFT)) & PIT_MCR_MDIS_MASK)

/*! @name LTMR64H - PIT Upper Lifetime Timer Register */
#define PIT_LTMR64H_LTH_MASK                     (0xFFFFFFFFU)
#define PIT_LTMR64H_LTH_SHIFT                    (0U)
#define PIT_LTMR64H_LTH(x)                       (((uint32_t)(((uint32_t)(x)) << PIT_LTMR64H_LTH_SHIFT)) & PIT_LTMR64H_LTH_MASK)

/*! @name LTMR64L - PIT Lower Lifetime Timer Register */
#define PIT_LTMR64L_LTL_MASK                     (0xFFFFFFFFU)
#define PIT_LTMR64L_LTL_SHIFT                    (0U)
#define PIT_LTMR64L_LTL(x)                       (((uint32_t)(((uint32_t)(x)) << PIT_LTMR64L_LTL_SHIFT)) & PIT_LTMR64L_LTL_MASK)

/*! @name LDVAL - Timer Load Value Register */
#define PIT_LDVAL_TSV_MASK                       (0xFFFFFFFFU)
#define PIT_LDVAL_TSV_SHIFT                      (0U)
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_LDVAL_TSV_SHIFT)) & PIT_LDVAL_TSV_MASK)

/* The count of PIT_LDVAL */
#define PIT_LDVAL_COUNT                          (4U)

/*! @name CVAL - Current Timer Value Register */
#define PIT_CVAL_TVL_MASK                        (0xFFFFFFFFU)
#define PIT_CVAL_TVL_SHIFT                       (0U)
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x)) << PIT_CVAL_TVL_SHIFT)) & PIT_CVAL_TVL_MASK)

/* The count of PIT_CVAL */
#define PIT_CVAL_COUNT                           (4U)

/*! @name TCTRL - Timer Control Register */
#define PIT_TCTRL_TEN_MASK                       (0x1U)
#define PIT_TCTRL_TEN_SHIFT                      (0U)
#define PIT_TCTRL_TEN(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_TEN_SHIFT)) & PIT_TCTRL_TEN_MASK)
#define PIT_TCTRL_TIE_MASK                       (0x2U)
#define PIT_TCTRL_TIE_SHIFT                      (1U)
#define PIT_TCTRL_TIE(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_TIE_SHIFT)) & PIT_TCTRL_TIE_MASK)
#define PIT_TCTRL_CHN_MASK                       (0x4U)
#define PIT_TCTRL_CHN_SHIFT                      (2U)
#define PIT_TCTRL_CHN(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_CHN_SHIFT)) & PIT_TCTRL_CHN_MASK)

/* The count of PIT_TCTRL */
#define PIT_TCTRL_COUNT                          (4U)

/*! @name TFLG - Timer Flag Register */
#define PIT_TFLG_TIF_MASK                        (0x1U)
#define PIT_TFLG_TIF_SHIFT                       (0U)
#define PIT_TFLG_TIF(x)                          (((uint32_t)(((uint32_t)(x)) << PIT_TFLG_TIF_SHIFT)) & PIT_TFLG_TIF_MASK)

/* The count of PIT_TFLG */
#define PIT_TFLG_COUNT                           (4U)


/*!
 * @}
 */ /* end of group PIT_Register_Masks */


/* PIT - Peripheral instance base addresses */
/** Peripheral PIT base address */
#define PIT_BASE                                 (0x40037000u)
/** Peripheral PIT base pointer */
#define PIT                                      ((PIT_Type *)PIT_BASE)
/** Array initializer of PIT peripheral base addresses */
#define PIT_BASE_ADDRS                           { PIT_BASE }
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            { PIT }
/** Interrupt vectors for the PIT peripheral type */
#define PIT_IRQS                                 { { PIT0_IRQn, PIT1_IRQn, PIT2_IRQn, PIT3_IRQn } }

/*!
 * @}
 */ /* end of group PIT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __IO uint8_t LVDSC1;                             /**< Low Voltage Detect Status And Control 1 register, offset: 0x0 */
  __IO uint8_t LVDSC2;                             /**< Low Voltage Detect Status And Control 2 register, offset: 0x1 */
  __IO uint8_t REGSC;                              /**< Regulator Status And Control register, offset: 0x2 */
       uint8_t RESERVED_0[8];
  __IO uint8_t HVDSC1;                             /**< High Voltage Detect Status And Control 1 register, offset: 0xB */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name LVDSC1 - Low Voltage Detect Status And Control 1 register */
#define PMC_LVDSC1_LVDV_MASK                     (0x3U)
#define PMC_LVDSC1_LVDV_SHIFT                    (0U)
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC1_LVDV_SHIFT)) & PMC_LVDSC1_LVDV_MASK)
#define PMC_LVDSC1_LVDRE_MASK                    (0x10U)
#define PMC_LVDSC1_LVDRE_SHIFT                   (4U)
#define PMC_LVDSC1_LVDRE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC1_LVDRE_SHIFT)) & PMC_LVDSC1_LVDRE_MASK)
#define PMC_LVDSC1_LVDIE_MASK                    (0x20U)
#define PMC_LVDSC1_LVDIE_SHIFT                   (5U)
#define PMC_LVDSC1_LVDIE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC1_LVDIE_SHIFT)) & PMC_LVDSC1_LVDIE_MASK)
#define PMC_LVDSC1_LVDACK_MASK                   (0x40U)
#define PMC_LVDSC1_LVDACK_SHIFT                  (6U)
#define PMC_LVDSC1_LVDACK(x)                     (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC1_LVDACK_SHIFT)) & PMC_LVDSC1_LVDACK_MASK)
#define PMC_LVDSC1_LVDF_MASK                     (0x80U)
#define PMC_LVDSC1_LVDF_SHIFT                    (7U)
#define PMC_LVDSC1_LVDF(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC1_LVDF_SHIFT)) & PMC_LVDSC1_LVDF_MASK)

/*! @name LVDSC2 - Low Voltage Detect Status And Control 2 register */
#define PMC_LVDSC2_LVWV_MASK                     (0x3U)
#define PMC_LVDSC2_LVWV_SHIFT                    (0U)
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC2_LVWV_SHIFT)) & PMC_LVDSC2_LVWV_MASK)
#define PMC_LVDSC2_LVWIE_MASK                    (0x20U)
#define PMC_LVDSC2_LVWIE_SHIFT                   (5U)
#define PMC_LVDSC2_LVWIE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC2_LVWIE_SHIFT)) & PMC_LVDSC2_LVWIE_MASK)
#define PMC_LVDSC2_LVWACK_MASK                   (0x40U)
#define PMC_LVDSC2_LVWACK_SHIFT                  (6U)
#define PMC_LVDSC2_LVWACK(x)                     (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC2_LVWACK_SHIFT)) & PMC_LVDSC2_LVWACK_MASK)
#define PMC_LVDSC2_LVWF_MASK                     (0x80U)
#define PMC_LVDSC2_LVWF_SHIFT                    (7U)
#define PMC_LVDSC2_LVWF(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC2_LVWF_SHIFT)) & PMC_LVDSC2_LVWF_MASK)

/*! @name REGSC - Regulator Status And Control register */
#define PMC_REGSC_BGBE_MASK                      (0x1U)
#define PMC_REGSC_BGBE_SHIFT                     (0U)
#define PMC_REGSC_BGBE(x)                        (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_BGBE_SHIFT)) & PMC_REGSC_BGBE_MASK)
#define PMC_REGSC_REGONS_MASK                    (0x4U)
#define PMC_REGSC_REGONS_SHIFT                   (2U)
#define PMC_REGSC_REGONS(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_REGONS_SHIFT)) & PMC_REGSC_REGONS_MASK)
#define PMC_REGSC_ACKISO_MASK                    (0x8U)
#define PMC_REGSC_ACKISO_SHIFT                   (3U)
#define PMC_REGSC_ACKISO(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_ACKISO_SHIFT)) & PMC_REGSC_ACKISO_MASK)
#define PMC_REGSC_BGEN_MASK                      (0x10U)
#define PMC_REGSC_BGEN_SHIFT                     (4U)
#define PMC_REGSC_BGEN(x)                        (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_BGEN_SHIFT)) & PMC_REGSC_BGEN_MASK)

/*! @name HVDSC1 - High Voltage Detect Status And Control 1 register */
#define PMC_HVDSC1_HVDV_MASK                     (0x1U)
#define PMC_HVDSC1_HVDV_SHIFT                    (0U)
#define PMC_HVDSC1_HVDV(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_HVDSC1_HVDV_SHIFT)) & PMC_HVDSC1_HVDV_MASK)
#define PMC_HVDSC1_HVDRE_MASK                    (0x10U)
#define PMC_HVDSC1_HVDRE_SHIFT                   (4U)
#define PMC_HVDSC1_HVDRE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_HVDSC1_HVDRE_SHIFT)) & PMC_HVDSC1_HVDRE_MASK)
#define PMC_HVDSC1_HVDIE_MASK                    (0x20U)
#define PMC_HVDSC1_HVDIE_SHIFT                   (5U)
#define PMC_HVDSC1_HVDIE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_HVDSC1_HVDIE_SHIFT)) & PMC_HVDSC1_HVDIE_MASK)
#define PMC_HVDSC1_HVDACK_MASK                   (0x40U)
#define PMC_HVDSC1_HVDACK_SHIFT                  (6U)
#define PMC_HVDSC1_HVDACK(x)                     (((uint8_t)(((uint8_t)(x)) << PMC_HVDSC1_HVDACK_SHIFT)) & PMC_HVDSC1_HVDACK_MASK)
#define PMC_HVDSC1_HVDF_MASK                     (0x80U)
#define PMC_HVDSC1_HVDF_SHIFT                    (7U)
#define PMC_HVDSC1_HVDF(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_HVDSC1_HVDF_SHIFT)) & PMC_HVDSC1_HVDF_MASK)


/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base address */
#define PMC_BASE                                 (0x4007D000u)
/** Peripheral PMC base pointer */
#define PMC                                      ((PMC_Type *)PMC_BASE)
/** Array initializer of PMC peripheral base addresses */
#define PMC_BASE_ADDRS                           { PMC_BASE }
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASE_PTRS                            { PMC }
/** Interrupt vectors for the PMC peripheral type */
#define PMC_IRQS                                 { LVD_LVW_IRQn }

/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */

/** PORT - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCR[32];                           /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  __O  uint32_t GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
  __O  uint32_t GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
  __O  uint32_t GICLR;                             /**< Global Interrupt Control Low Register, offset: 0x88 */
  __O  uint32_t GICHR;                             /**< Global Interrupt Control High Register, offset: 0x8C */
       uint8_t RESERVED_0[16];
  __IO uint32_t ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
       uint8_t RESERVED_1[28];
  __IO uint32_t DFER;                              /**< Digital Filter Enable Register, offset: 0xC0 */
  __IO uint32_t DFCR;                              /**< Digital Filter Clock Register, offset: 0xC4 */
  __IO uint32_t DFWR;                              /**< Digital Filter Width Register, offset: 0xC8 */
} PORT_Type;

/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/*! @name PCR - Pin Control Register n */
#define PORT_PCR_PS_MASK                         (0x1U)
#define PORT_PCR_PS_SHIFT                        (0U)
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PS_SHIFT)) & PORT_PCR_PS_MASK)
#define PORT_PCR_PE_MASK                         (0x2U)
#define PORT_PCR_PE_SHIFT                        (1U)
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PE_SHIFT)) & PORT_PCR_PE_MASK)
#define PORT_PCR_SRE_MASK                        (0x4U)
#define PORT_PCR_SRE_SHIFT                       (2U)
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_SRE_SHIFT)) & PORT_PCR_SRE_MASK)
#define PORT_PCR_PFE_MASK                        (0x10U)
#define PORT_PCR_PFE_SHIFT                       (4U)
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PFE_SHIFT)) & PORT_PCR_PFE_MASK)
#define PORT_PCR_ODE_MASK                        (0x20U)
#define PORT_PCR_ODE_SHIFT                       (5U)
#define PORT_PCR_ODE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_ODE_SHIFT)) & PORT_PCR_ODE_MASK)
#define PORT_PCR_DSE_MASK                        (0x40U)
#define PORT_PCR_DSE_SHIFT                       (6U)
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_DSE_SHIFT)) & PORT_PCR_DSE_MASK)
#define PORT_PCR_MUX_MASK                        (0xF00U)
#define PORT_PCR_MUX_SHIFT                       (8U)
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_MUX_SHIFT)) & PORT_PCR_MUX_MASK)
#define PORT_PCR_LK_MASK                         (0x8000U)
#define PORT_PCR_LK_SHIFT                        (15U)
#define PORT_PCR_LK(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_LK_SHIFT)) & PORT_PCR_LK_MASK)
#define PORT_PCR_IRQC_MASK                       (0xF0000U)
#define PORT_PCR_IRQC_SHIFT                      (16U)
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_PCR_IRQC_SHIFT)) & PORT_PCR_IRQC_MASK)
#define PORT_PCR_ISF_MASK                        (0x1000000U)
#define PORT_PCR_ISF_SHIFT                       (24U)
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_ISF_SHIFT)) & PORT_PCR_ISF_MASK)

/* The count of PORT_PCR */
#define PORT_PCR_COUNT                           (32U)

/*! @name GPCLR - Global Pin Control Low Register */
#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCLR_GPWD_SHIFT                    (0U)
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWD_SHIFT)) & PORT_GPCLR_GPWD_MASK)
#define PORT_GPCLR_GPWE_MASK                     (0xFFFF0000U)
#define PORT_GPCLR_GPWE_SHIFT                    (16U)
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE_SHIFT)) & PORT_GPCLR_GPWE_MASK)

/*! @name GPCHR - Global Pin Control High Register */
#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCHR_GPWD_SHIFT                    (0U)
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWD_SHIFT)) & PORT_GPCHR_GPWD_MASK)
#define PORT_GPCHR_GPWE_MASK                     (0xFFFF0000U)
#define PORT_GPCHR_GPWE_SHIFT                    (16U)
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE_SHIFT)) & PORT_GPCHR_GPWE_MASK)

/*! @name GICLR - Global Interrupt Control Low Register */
#define PORT_GICLR_GIWE_MASK                     (0xFFFFU)
#define PORT_GICLR_GIWE_SHIFT                    (0U)
#define PORT_GICLR_GIWE(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GICLR_GIWE_SHIFT)) & PORT_GICLR_GIWE_MASK)
#define PORT_GICLR_GIWD_MASK                     (0xFFFF0000U)
#define PORT_GICLR_GIWD_SHIFT                    (16U)
#define PORT_GICLR_GIWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GICLR_GIWD_SHIFT)) & PORT_GICLR_GIWD_MASK)

/*! @name GICHR - Global Interrupt Control High Register */
#define PORT_GICHR_GIWE_MASK                     (0xFFFFU)
#define PORT_GICHR_GIWE_SHIFT                    (0U)
#define PORT_GICHR_GIWE(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GICHR_GIWE_SHIFT)) & PORT_GICHR_GIWE_MASK)
#define PORT_GICHR_GIWD_MASK                     (0xFFFF0000U)
#define PORT_GICHR_GIWD_SHIFT                    (16U)
#define PORT_GICHR_GIWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GICHR_GIWD_SHIFT)) & PORT_GICHR_GIWD_MASK)

/*! @name ISFR - Interrupt Status Flag Register */
#define PORT_ISFR_ISF_MASK                       (0xFFFFFFFFU)
#define PORT_ISFR_ISF_SHIFT                      (0U)
#define PORT_ISFR_ISF(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_ISFR_ISF_SHIFT)) & PORT_ISFR_ISF_MASK)

/*! @name DFER - Digital Filter Enable Register */
#define PORT_DFER_DFE_MASK                       (0xFFFFFFFFU)
#define PORT_DFER_DFE_SHIFT                      (0U)
#define PORT_DFER_DFE(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_DFER_DFE_SHIFT)) & PORT_DFER_DFE_MASK)

/*! @name DFCR - Digital Filter Clock Register */
#define PORT_DFCR_CS_MASK                        (0x1U)
#define PORT_DFCR_CS_SHIFT                       (0U)
#define PORT_DFCR_CS(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_DFCR_CS_SHIFT)) & PORT_DFCR_CS_MASK)

/*! @name DFWR - Digital Filter Width Register */
#define PORT_DFWR_FILT_MASK                      (0x1FU)
#define PORT_DFWR_FILT_SHIFT                     (0U)
#define PORT_DFWR_FILT(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_DFWR_FILT_SHIFT)) & PORT_DFWR_FILT_MASK)


/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x40049000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x4004A000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x4004B000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x4004C000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)
/** Peripheral PORTE base address */
#define PORTE_BASE                               (0x4004D000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD, PORTE }
/** Interrupt vectors for the PORT peripheral type */
#define PORT_IRQS                                { PORTA_IRQn, PORTB_IRQn, PORTC_IRQn, PORTD_IRQn, PORTE_IRQn }

/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Peripheral_Access_Layer RCM Peripheral Access Layer
 * @{
 */

/** RCM - Register Layout Typedef */
typedef struct {
  __I  uint8_t SRS0;                               /**< System Reset Status Register 0, offset: 0x0 */
  __I  uint8_t SRS1;                               /**< System Reset Status Register 1, offset: 0x1 */
       uint8_t RESERVED_0[2];
  __IO uint8_t RPFC;                               /**< Reset Pin Filter Control register, offset: 0x4 */
  __IO uint8_t RPFW;                               /**< Reset Pin Filter Width register, offset: 0x5 */
       uint8_t RESERVED_1[2];
  __IO uint8_t SSRS0;                              /**< Sticky System Reset Status Register 0, offset: 0x8 */
  __IO uint8_t SSRS1;                              /**< Sticky System Reset Status Register 1, offset: 0x9 */
} RCM_Type;

/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Masks RCM Register Masks
 * @{
 */

/*! @name SRS0 - System Reset Status Register 0 */
#define RCM_SRS0_WAKEUP_MASK                     (0x1U)
#define RCM_SRS0_WAKEUP_SHIFT                    (0U)
#define RCM_SRS0_WAKEUP(x)                       (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_WAKEUP_SHIFT)) & RCM_SRS0_WAKEUP_MASK)
#define RCM_SRS0_LVD_MASK                        (0x2U)
#define RCM_SRS0_LVD_SHIFT                       (1U)
#define RCM_SRS0_LVD(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_LVD_SHIFT)) & RCM_SRS0_LVD_MASK)
#define RCM_SRS0_LOC_MASK                        (0x4U)
#define RCM_SRS0_LOC_SHIFT                       (2U)
#define RCM_SRS0_LOC(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_LOC_SHIFT)) & RCM_SRS0_LOC_MASK)
#define RCM_SRS0_LOL_MASK                        (0x8U)
#define RCM_SRS0_LOL_SHIFT                       (3U)
#define RCM_SRS0_LOL(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_LOL_SHIFT)) & RCM_SRS0_LOL_MASK)
#define RCM_SRS0_WDOG_MASK                       (0x20U)
#define RCM_SRS0_WDOG_SHIFT                      (5U)
#define RCM_SRS0_WDOG(x)                         (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_WDOG_SHIFT)) & RCM_SRS0_WDOG_MASK)
#define RCM_SRS0_PIN_MASK                        (0x40U)
#define RCM_SRS0_PIN_SHIFT                       (6U)
#define RCM_SRS0_PIN(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_PIN_SHIFT)) & RCM_SRS0_PIN_MASK)
#define RCM_SRS0_POR_MASK                        (0x80U)
#define RCM_SRS0_POR_SHIFT                       (7U)
#define RCM_SRS0_POR(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_POR_SHIFT)) & RCM_SRS0_POR_MASK)

/*! @name SRS1 - System Reset Status Register 1 */
#define RCM_SRS1_JTAG_MASK                       (0x1U)
#define RCM_SRS1_JTAG_SHIFT                      (0U)
#define RCM_SRS1_JTAG(x)                         (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_JTAG_SHIFT)) & RCM_SRS1_JTAG_MASK)
#define RCM_SRS1_LOCKUP_MASK                     (0x2U)
#define RCM_SRS1_LOCKUP_SHIFT                    (1U)
#define RCM_SRS1_LOCKUP(x)                       (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_LOCKUP_SHIFT)) & RCM_SRS1_LOCKUP_MASK)
#define RCM_SRS1_SW_MASK                         (0x4U)
#define RCM_SRS1_SW_SHIFT                        (2U)
#define RCM_SRS1_SW(x)                           (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_SW_SHIFT)) & RCM_SRS1_SW_MASK)
#define RCM_SRS1_MDM_AP_MASK                     (0x8U)
#define RCM_SRS1_MDM_AP_SHIFT                    (3U)
#define RCM_SRS1_MDM_AP(x)                       (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_MDM_AP_SHIFT)) & RCM_SRS1_MDM_AP_MASK)
#define RCM_SRS1_SACKERR_MASK                    (0x20U)
#define RCM_SRS1_SACKERR_SHIFT                   (5U)
#define RCM_SRS1_SACKERR(x)                      (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_SACKERR_SHIFT)) & RCM_SRS1_SACKERR_MASK)

/*! @name RPFC - Reset Pin Filter Control register */
#define RCM_RPFC_RSTFLTSRW_MASK                  (0x3U)
#define RCM_RPFC_RSTFLTSRW_SHIFT                 (0U)
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x)) << RCM_RPFC_RSTFLTSRW_SHIFT)) & RCM_RPFC_RSTFLTSRW_MASK)
#define RCM_RPFC_RSTFLTSS_MASK                   (0x4U)
#define RCM_RPFC_RSTFLTSS_SHIFT                  (2U)
#define RCM_RPFC_RSTFLTSS(x)                     (((uint8_t)(((uint8_t)(x)) << RCM_RPFC_RSTFLTSS_SHIFT)) & RCM_RPFC_RSTFLTSS_MASK)

/*! @name RPFW - Reset Pin Filter Width register */
#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FU)
#define RCM_RPFW_RSTFLTSEL_SHIFT                 (0U)
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x)) << RCM_RPFW_RSTFLTSEL_SHIFT)) & RCM_RPFW_RSTFLTSEL_MASK)

/*! @name SSRS0 - Sticky System Reset Status Register 0 */
#define RCM_SSRS0_SWAKEUP_MASK                   (0x1U)
#define RCM_SSRS0_SWAKEUP_SHIFT                  (0U)
#define RCM_SSRS0_SWAKEUP(x)                     (((uint8_t)(((uint8_t)(x)) << RCM_SSRS0_SWAKEUP_SHIFT)) & RCM_SSRS0_SWAKEUP_MASK)
#define RCM_SSRS0_SLVD_MASK                      (0x2U)
#define RCM_SSRS0_SLVD_SHIFT                     (1U)
#define RCM_SSRS0_SLVD(x)                        (((uint8_t)(((uint8_t)(x)) << RCM_SSRS0_SLVD_SHIFT)) & RCM_SSRS0_SLVD_MASK)
#define RCM_SSRS0_SLOC_MASK                      (0x4U)
#define RCM_SSRS0_SLOC_SHIFT                     (2U)
#define RCM_SSRS0_SLOC(x)                        (((uint8_t)(((uint8_t)(x)) << RCM_SSRS0_SLOC_SHIFT)) & RCM_SSRS0_SLOC_MASK)
#define RCM_SSRS0_SLOL_MASK                      (0x8U)
#define RCM_SSRS0_SLOL_SHIFT                     (3U)
#define RCM_SSRS0_SLOL(x)                        (((uint8_t)(((uint8_t)(x)) << RCM_SSRS0_SLOL_SHIFT)) & RCM_SSRS0_SLOL_MASK)
#define RCM_SSRS0_SWDOG_MASK                     (0x20U)
#define RCM_SSRS0_SWDOG_SHIFT                    (5U)
#define RCM_SSRS0_SWDOG(x)                       (((uint8_t)(((uint8_t)(x)) << RCM_SSRS0_SWDOG_SHIFT)) & RCM_SSRS0_SWDOG_MASK)
#define RCM_SSRS0_SPIN_MASK                      (0x40U)
#define RCM_SSRS0_SPIN_SHIFT                     (6U)
#define RCM_SSRS0_SPIN(x)                        (((uint8_t)(((uint8_t)(x)) << RCM_SSRS0_SPIN_SHIFT)) & RCM_SSRS0_SPIN_MASK)
#define RCM_SSRS0_SPOR_MASK                      (0x80U)
#define RCM_SSRS0_SPOR_SHIFT                     (7U)
#define RCM_SSRS0_SPOR(x)                        (((uint8_t)(((uint8_t)(x)) << RCM_SSRS0_SPOR_SHIFT)) & RCM_SSRS0_SPOR_MASK)

/*! @name SSRS1 - Sticky System Reset Status Register 1 */
#define RCM_SSRS1_SJTAG_MASK                     (0x1U)
#define RCM_SSRS1_SJTAG_SHIFT                    (0U)
#define RCM_SSRS1_SJTAG(x)                       (((uint8_t)(((uint8_t)(x)) << RCM_SSRS1_SJTAG_SHIFT)) & RCM_SSRS1_SJTAG_MASK)
#define RCM_SSRS1_SLOCKUP_MASK                   (0x2U)
#define RCM_SSRS1_SLOCKUP_SHIFT                  (1U)
#define RCM_SSRS1_SLOCKUP(x)                     (((uint8_t)(((uint8_t)(x)) << RCM_SSRS1_SLOCKUP_SHIFT)) & RCM_SSRS1_SLOCKUP_MASK)
#define RCM_SSRS1_SSW_MASK                       (0x4U)
#define RCM_SSRS1_SSW_SHIFT                      (2U)
#define RCM_SSRS1_SSW(x)                         (((uint8_t)(((uint8_t)(x)) << RCM_SSRS1_SSW_SHIFT)) & RCM_SSRS1_SSW_MASK)
#define RCM_SSRS1_SMDM_AP_MASK                   (0x8U)
#define RCM_SSRS1_SMDM_AP_SHIFT                  (3U)
#define RCM_SSRS1_SMDM_AP(x)                     (((uint8_t)(((uint8_t)(x)) << RCM_SSRS1_SMDM_AP_SHIFT)) & RCM_SSRS1_SMDM_AP_MASK)
#define RCM_SSRS1_SSACKERR_MASK                  (0x20U)
#define RCM_SSRS1_SSACKERR_SHIFT                 (5U)
#define RCM_SSRS1_SSACKERR(x)                    (((uint8_t)(((uint8_t)(x)) << RCM_SSRS1_SSACKERR_SHIFT)) & RCM_SSRS1_SSACKERR_MASK)


/*!
 * @}
 */ /* end of group RCM_Register_Masks */


/* RCM - Peripheral instance base addresses */
/** Peripheral RCM base address */
#define RCM_BASE                                 (0x4007F000u)
/** Peripheral RCM base pointer */
#define RCM                                      ((RCM_Type *)RCM_BASE)
/** Array initializer of RCM peripheral base addresses */
#define RCM_BASE_ADDRS                           { RCM_BASE }
/** Array initializer of RCM peripheral base pointers */
#define RCM_BASE_PTRS                            { RCM }

/*!
 * @}
 */ /* end of group RCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RFSYS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RFSYS_Peripheral_Access_Layer RFSYS Peripheral Access Layer
 * @{
 */

/** RFSYS - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG[8];                            /**< Register file register, array offset: 0x0, array step: 0x4 */
} RFSYS_Type;

/* ----------------------------------------------------------------------------
   -- RFSYS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RFSYS_Register_Masks RFSYS Register Masks
 * @{
 */

/*! @name REG - Register file register */
#define RFSYS_REG_LL_MASK                        (0xFFU)
#define RFSYS_REG_LL_SHIFT                       (0U)
#define RFSYS_REG_LL(x)                          (((uint32_t)(((uint32_t)(x)) << RFSYS_REG_LL_SHIFT)) & RFSYS_REG_LL_MASK)
#define RFSYS_REG_LH_MASK                        (0xFF00U)
#define RFSYS_REG_LH_SHIFT                       (8U)
#define RFSYS_REG_LH(x)                          (((uint32_t)(((uint32_t)(x)) << RFSYS_REG_LH_SHIFT)) & RFSYS_REG_LH_MASK)
#define RFSYS_REG_HL_MASK                        (0xFF0000U)
#define RFSYS_REG_HL_SHIFT                       (16U)
#define RFSYS_REG_HL(x)                          (((uint32_t)(((uint32_t)(x)) << RFSYS_REG_HL_SHIFT)) & RFSYS_REG_HL_MASK)
#define RFSYS_REG_HH_MASK                        (0xFF000000U)
#define RFSYS_REG_HH_SHIFT                       (24U)
#define RFSYS_REG_HH(x)                          (((uint32_t)(((uint32_t)(x)) << RFSYS_REG_HH_SHIFT)) & RFSYS_REG_HH_MASK)

/* The count of RFSYS_REG */
#define RFSYS_REG_COUNT                          (8U)


/*!
 * @}
 */ /* end of group RFSYS_Register_Masks */


/* RFSYS - Peripheral instance base addresses */
/** Peripheral RFSYS base address */
#define RFSYS_BASE                               (0x40041000u)
/** Peripheral RFSYS base pointer */
#define RFSYS                                    ((RFSYS_Type *)RFSYS_BASE)
/** Array initializer of RFSYS peripheral base addresses */
#define RFSYS_BASE_ADDRS                         { RFSYS_BASE }
/** Array initializer of RFSYS peripheral base pointers */
#define RFSYS_BASE_PTRS                          { RFSYS }

/*!
 * @}
 */ /* end of group RFSYS_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RFVBAT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RFVBAT_Peripheral_Access_Layer RFVBAT Peripheral Access Layer
 * @{
 */

/** RFVBAT - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG[8];                            /**< VBAT register file register, array offset: 0x0, array step: 0x4 */
} RFVBAT_Type;

/* ----------------------------------------------------------------------------
   -- RFVBAT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RFVBAT_Register_Masks RFVBAT Register Masks
 * @{
 */

/*! @name REG - VBAT register file register */
#define RFVBAT_REG_LL_MASK                       (0xFFU)
#define RFVBAT_REG_LL_SHIFT                      (0U)
#define RFVBAT_REG_LL(x)                         (((uint32_t)(((uint32_t)(x)) << RFVBAT_REG_LL_SHIFT)) & RFVBAT_REG_LL_MASK)
#define RFVBAT_REG_LH_MASK                       (0xFF00U)
#define RFVBAT_REG_LH_SHIFT                      (8U)
#define RFVBAT_REG_LH(x)                         (((uint32_t)(((uint32_t)(x)) << RFVBAT_REG_LH_SHIFT)) & RFVBAT_REG_LH_MASK)
#define RFVBAT_REG_HL_MASK                       (0xFF0000U)
#define RFVBAT_REG_HL_SHIFT                      (16U)
#define RFVBAT_REG_HL(x)                         (((uint32_t)(((uint32_t)(x)) << RFVBAT_REG_HL_SHIFT)) & RFVBAT_REG_HL_MASK)
#define RFVBAT_REG_HH_MASK                       (0xFF000000U)
#define RFVBAT_REG_HH_SHIFT                      (24U)
#define RFVBAT_REG_HH(x)                         (((uint32_t)(((uint32_t)(x)) << RFVBAT_REG_HH_SHIFT)) & RFVBAT_REG_HH_MASK)

/* The count of RFVBAT_REG */
#define RFVBAT_REG_COUNT                         (8U)


/*!
 * @}
 */ /* end of group RFVBAT_Register_Masks */


/* RFVBAT - Peripheral instance base addresses */
/** Peripheral RFVBAT base address */
#define RFVBAT_BASE                              (0x4003E000u)
/** Peripheral RFVBAT base pointer */
#define RFVBAT                                   ((RFVBAT_Type *)RFVBAT_BASE)
/** Array initializer of RFVBAT peripheral base addresses */
#define RFVBAT_BASE_ADDRS                        { RFVBAT_BASE }
/** Array initializer of RFVBAT peripheral base pointers */
#define RFVBAT_BASE_PTRS                         { RFVBAT }

/*!
 * @}
 */ /* end of group RFVBAT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RNG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RNG_Peripheral_Access_Layer RNG Peripheral Access Layer
 * @{
 */

/** RNG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< RNGA Control Register, offset: 0x0 */
  __I  uint32_t SR;                                /**< RNGA Status Register, offset: 0x4 */
  __O  uint32_t ER;                                /**< RNGA Entropy Register, offset: 0x8 */
  __I  uint32_t OR;                                /**< RNGA Output Register, offset: 0xC */
} RNG_Type;

/* ----------------------------------------------------------------------------
   -- RNG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RNG_Register_Masks RNG Register Masks
 * @{
 */

/*! @name CR - RNGA Control Register */
#define RNG_CR_GO_MASK                           (0x1U)
#define RNG_CR_GO_SHIFT                          (0U)
#define RNG_CR_GO(x)                             (((uint32_t)(((uint32_t)(x)) << RNG_CR_GO_SHIFT)) & RNG_CR_GO_MASK)
#define RNG_CR_HA_MASK                           (0x2U)
#define RNG_CR_HA_SHIFT                          (1U)
#define RNG_CR_HA(x)                             (((uint32_t)(((uint32_t)(x)) << RNG_CR_HA_SHIFT)) & RNG_CR_HA_MASK)
#define RNG_CR_INTM_MASK                         (0x4U)
#define RNG_CR_INTM_SHIFT                        (2U)
#define RNG_CR_INTM(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_CR_INTM_SHIFT)) & RNG_CR_INTM_MASK)
#define RNG_CR_CLRI_MASK                         (0x8U)
#define RNG_CR_CLRI_SHIFT                        (3U)
#define RNG_CR_CLRI(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_CR_CLRI_SHIFT)) & RNG_CR_CLRI_MASK)
#define RNG_CR_SLP_MASK                          (0x10U)
#define RNG_CR_SLP_SHIFT                         (4U)
#define RNG_CR_SLP(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_CR_SLP_SHIFT)) & RNG_CR_SLP_MASK)

/*! @name SR - RNGA Status Register */
#define RNG_SR_SECV_MASK                         (0x1U)
#define RNG_SR_SECV_SHIFT                        (0U)
#define RNG_SR_SECV(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_SR_SECV_SHIFT)) & RNG_SR_SECV_MASK)
#define RNG_SR_LRS_MASK                          (0x2U)
#define RNG_SR_LRS_SHIFT                         (1U)
#define RNG_SR_LRS(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_SR_LRS_SHIFT)) & RNG_SR_LRS_MASK)
#define RNG_SR_ORU_MASK                          (0x4U)
#define RNG_SR_ORU_SHIFT                         (2U)
#define RNG_SR_ORU(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_SR_ORU_SHIFT)) & RNG_SR_ORU_MASK)
#define RNG_SR_ERRI_MASK                         (0x8U)
#define RNG_SR_ERRI_SHIFT                        (3U)
#define RNG_SR_ERRI(x)                           (((uint32_t)(((uint32_t)(x)) << RNG_SR_ERRI_SHIFT)) & RNG_SR_ERRI_MASK)
#define RNG_SR_SLP_MASK                          (0x10U)
#define RNG_SR_SLP_SHIFT                         (4U)
#define RNG_SR_SLP(x)                            (((uint32_t)(((uint32_t)(x)) << RNG_SR_SLP_SHIFT)) & RNG_SR_SLP_MASK)
#define RNG_SR_OREG_LVL_MASK                     (0xFF00U)
#define RNG_SR_OREG_LVL_SHIFT                    (8U)
#define RNG_SR_OREG_LVL(x)                       (((uint32_t)(((uint32_t)(x)) << RNG_SR_OREG_LVL_SHIFT)) & RNG_SR_OREG_LVL_MASK)
#define RNG_SR_OREG_SIZE_MASK                    (0xFF0000U)
#define RNG_SR_OREG_SIZE_SHIFT                   (16U)
#define RNG_SR_OREG_SIZE(x)                      (((uint32_t)(((uint32_t)(x)) << RNG_SR_OREG_SIZE_SHIFT)) & RNG_SR_OREG_SIZE_MASK)

/*! @name ER - RNGA Entropy Register */
#define RNG_ER_EXT_ENT_MASK                      (0xFFFFFFFFU)
#define RNG_ER_EXT_ENT_SHIFT                     (0U)
#define RNG_ER_EXT_ENT(x)                        (((uint32_t)(((uint32_t)(x)) << RNG_ER_EXT_ENT_SHIFT)) & RNG_ER_EXT_ENT_MASK)

/*! @name OR - RNGA Output Register */
#define RNG_OR_RANDOUT_MASK                      (0xFFFFFFFFU)
#define RNG_OR_RANDOUT_SHIFT                     (0U)
#define RNG_OR_RANDOUT(x)                        (((uint32_t)(((uint32_t)(x)) << RNG_OR_RANDOUT_SHIFT)) & RNG_OR_RANDOUT_MASK)


/*!
 * @}
 */ /* end of group RNG_Register_Masks */


/* RNG - Peripheral instance base addresses */
/** Peripheral RNG base address */
#define RNG_BASE                                 (0x40029000u)
/** Peripheral RNG base pointer */
#define RNG                                      ((RNG_Type *)RNG_BASE)
/** Array initializer of RNG peripheral base addresses */
#define RNG_BASE_ADDRS                           { RNG_BASE }
/** Array initializer of RNG peripheral base pointers */
#define RNG_BASE_PTRS                            { RNG }
/** Interrupt vectors for the RNG peripheral type */
#define RNG_IRQS                                 { RNG_IRQn }

/*!
 * @}
 */ /* end of group RNG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint32_t TSR;                               /**< RTC Time Seconds Register, offset: 0x0 */
  __IO uint32_t TPR;                               /**< RTC Time Prescaler Register, offset: 0x4 */
  __IO uint32_t TAR;                               /**< RTC Time Alarm Register, offset: 0x8 */
  __IO uint32_t TCR;                               /**< RTC Time Compensation Register, offset: 0xC */
  __IO uint32_t CR;                                /**< RTC Control Register, offset: 0x10 */
  __IO uint32_t SR;                                /**< RTC Status Register, offset: 0x14 */
  __IO uint32_t LR;                                /**< RTC Lock Register, offset: 0x18 */
  __IO uint32_t IER;                               /**< RTC Interrupt Enable Register, offset: 0x1C */
       uint8_t RESERVED_0[2016];
  __IO uint32_t WAR;                               /**< RTC Write Access Register, offset: 0x800 */
  __IO uint32_t RAR;                               /**< RTC Read Access Register, offset: 0x804 */
} RTC_Type;

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/*! @name TSR - RTC Time Seconds Register */
#define RTC_TSR_TSR_MASK                         (0xFFFFFFFFU)
#define RTC_TSR_TSR_SHIFT                        (0U)
#define RTC_TSR_TSR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TSR_TSR_SHIFT)) & RTC_TSR_TSR_MASK)

/*! @name TPR - RTC Time Prescaler Register */
#define RTC_TPR_TPR_MASK                         (0xFFFFU)
#define RTC_TPR_TPR_SHIFT                        (0U)
#define RTC_TPR_TPR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TPR_TPR_SHIFT)) & RTC_TPR_TPR_MASK)

/*! @name TAR - RTC Time Alarm Register */
#define RTC_TAR_TAR_MASK                         (0xFFFFFFFFU)
#define RTC_TAR_TAR_SHIFT                        (0U)
#define RTC_TAR_TAR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TAR_TAR_SHIFT)) & RTC_TAR_TAR_MASK)

/*! @name TCR - RTC Time Compensation Register */
#define RTC_TCR_TCR_MASK                         (0xFFU)
#define RTC_TCR_TCR_SHIFT                        (0U)
#define RTC_TCR_TCR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TCR_TCR_SHIFT)) & RTC_TCR_TCR_MASK)
#define RTC_TCR_CIR_MASK                         (0xFF00U)
#define RTC_TCR_CIR_SHIFT                        (8U)
#define RTC_TCR_CIR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TCR_CIR_SHIFT)) & RTC_TCR_CIR_MASK)
#define RTC_TCR_TCV_MASK                         (0xFF0000U)
#define RTC_TCR_TCV_SHIFT                        (16U)
#define RTC_TCR_TCV(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TCR_TCV_SHIFT)) & RTC_TCR_TCV_MASK)
#define RTC_TCR_CIC_MASK                         (0xFF000000U)
#define RTC_TCR_CIC_SHIFT                        (24U)
#define RTC_TCR_CIC(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_TCR_CIC_SHIFT)) & RTC_TCR_CIC_MASK)

/*! @name CR - RTC Control Register */
#define RTC_CR_SWR_MASK                          (0x1U)
#define RTC_CR_SWR_SHIFT                         (0U)
#define RTC_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_SWR_SHIFT)) & RTC_CR_SWR_MASK)
#define RTC_CR_WPE_MASK                          (0x2U)
#define RTC_CR_WPE_SHIFT                         (1U)
#define RTC_CR_WPE(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_WPE_SHIFT)) & RTC_CR_WPE_MASK)
#define RTC_CR_SUP_MASK                          (0x4U)
#define RTC_CR_SUP_SHIFT                         (2U)
#define RTC_CR_SUP(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_SUP_SHIFT)) & RTC_CR_SUP_MASK)
#define RTC_CR_UM_MASK                           (0x8U)
#define RTC_CR_UM_SHIFT                          (3U)
#define RTC_CR_UM(x)                             (((uint32_t)(((uint32_t)(x)) << RTC_CR_UM_SHIFT)) & RTC_CR_UM_MASK)
#define RTC_CR_WPS_MASK                          (0x10U)
#define RTC_CR_WPS_SHIFT                         (4U)
#define RTC_CR_WPS(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_CR_WPS_SHIFT)) & RTC_CR_WPS_MASK)
#define RTC_CR_OSCE_MASK                         (0x100U)
#define RTC_CR_OSCE_SHIFT                        (8U)
#define RTC_CR_OSCE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_OSCE_SHIFT)) & RTC_CR_OSCE_MASK)
#define RTC_CR_CLKO_MASK                         (0x200U)
#define RTC_CR_CLKO_SHIFT                        (9U)
#define RTC_CR_CLKO(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_CLKO_SHIFT)) & RTC_CR_CLKO_MASK)
#define RTC_CR_SC16P_MASK                        (0x400U)
#define RTC_CR_SC16P_SHIFT                       (10U)
#define RTC_CR_SC16P(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_CR_SC16P_SHIFT)) & RTC_CR_SC16P_MASK)
#define RTC_CR_SC8P_MASK                         (0x800U)
#define RTC_CR_SC8P_SHIFT                        (11U)
#define RTC_CR_SC8P(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_SC8P_SHIFT)) & RTC_CR_SC8P_MASK)
#define RTC_CR_SC4P_MASK                         (0x1000U)
#define RTC_CR_SC4P_SHIFT                        (12U)
#define RTC_CR_SC4P(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_SC4P_SHIFT)) & RTC_CR_SC4P_MASK)
#define RTC_CR_SC2P_MASK                         (0x2000U)
#define RTC_CR_SC2P_SHIFT                        (13U)
#define RTC_CR_SC2P(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CR_SC2P_SHIFT)) & RTC_CR_SC2P_MASK)

/*! @name SR - RTC Status Register */
#define RTC_SR_TIF_MASK                          (0x1U)
#define RTC_SR_TIF_SHIFT                         (0U)
#define RTC_SR_TIF(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_SR_TIF_SHIFT)) & RTC_SR_TIF_MASK)
#define RTC_SR_TOF_MASK                          (0x2U)
#define RTC_SR_TOF_SHIFT                         (1U)
#define RTC_SR_TOF(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_SR_TOF_SHIFT)) & RTC_SR_TOF_MASK)
#define RTC_SR_TAF_MASK                          (0x4U)
#define RTC_SR_TAF_SHIFT                         (2U)
#define RTC_SR_TAF(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_SR_TAF_SHIFT)) & RTC_SR_TAF_MASK)
#define RTC_SR_TCE_MASK                          (0x10U)
#define RTC_SR_TCE_SHIFT                         (4U)
#define RTC_SR_TCE(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_SR_TCE_SHIFT)) & RTC_SR_TCE_MASK)

/*! @name LR - RTC Lock Register */
#define RTC_LR_TCL_MASK                          (0x8U)
#define RTC_LR_TCL_SHIFT                         (3U)
#define RTC_LR_TCL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_TCL_SHIFT)) & RTC_LR_TCL_MASK)
#define RTC_LR_CRL_MASK                          (0x10U)
#define RTC_LR_CRL_SHIFT                         (4U)
#define RTC_LR_CRL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_CRL_SHIFT)) & RTC_LR_CRL_MASK)
#define RTC_LR_SRL_MASK                          (0x20U)
#define RTC_LR_SRL_SHIFT                         (5U)
#define RTC_LR_SRL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_SRL_SHIFT)) & RTC_LR_SRL_MASK)
#define RTC_LR_LRL_MASK                          (0x40U)
#define RTC_LR_LRL_SHIFT                         (6U)
#define RTC_LR_LRL(x)                            (((uint32_t)(((uint32_t)(x)) << RTC_LR_LRL_SHIFT)) & RTC_LR_LRL_MASK)

/*! @name IER - RTC Interrupt Enable Register */
#define RTC_IER_TIIE_MASK                        (0x1U)
#define RTC_IER_TIIE_SHIFT                       (0U)
#define RTC_IER_TIIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_TIIE_SHIFT)) & RTC_IER_TIIE_MASK)
#define RTC_IER_TOIE_MASK                        (0x2U)
#define RTC_IER_TOIE_SHIFT                       (1U)
#define RTC_IER_TOIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_TOIE_SHIFT)) & RTC_IER_TOIE_MASK)
#define RTC_IER_TAIE_MASK                        (0x4U)
#define RTC_IER_TAIE_SHIFT                       (2U)
#define RTC_IER_TAIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_TAIE_SHIFT)) & RTC_IER_TAIE_MASK)
#define RTC_IER_TSIE_MASK                        (0x10U)
#define RTC_IER_TSIE_SHIFT                       (4U)
#define RTC_IER_TSIE(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_TSIE_SHIFT)) & RTC_IER_TSIE_MASK)
#define RTC_IER_WPON_MASK                        (0x80U)
#define RTC_IER_WPON_SHIFT                       (7U)
#define RTC_IER_WPON(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_IER_WPON_SHIFT)) & RTC_IER_WPON_MASK)

/*! @name WAR - RTC Write Access Register */
#define RTC_WAR_TSRW_MASK                        (0x1U)
#define RTC_WAR_TSRW_SHIFT                       (0U)
#define RTC_WAR_TSRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TSRW_SHIFT)) & RTC_WAR_TSRW_MASK)
#define RTC_WAR_TPRW_MASK                        (0x2U)
#define RTC_WAR_TPRW_SHIFT                       (1U)
#define RTC_WAR_TPRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TPRW_SHIFT)) & RTC_WAR_TPRW_MASK)
#define RTC_WAR_TARW_MASK                        (0x4U)
#define RTC_WAR_TARW_SHIFT                       (2U)
#define RTC_WAR_TARW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TARW_SHIFT)) & RTC_WAR_TARW_MASK)
#define RTC_WAR_TCRW_MASK                        (0x8U)
#define RTC_WAR_TCRW_SHIFT                       (3U)
#define RTC_WAR_TCRW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_TCRW_SHIFT)) & RTC_WAR_TCRW_MASK)
#define RTC_WAR_CRW_MASK                         (0x10U)
#define RTC_WAR_CRW_SHIFT                        (4U)
#define RTC_WAR_CRW(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_WAR_CRW_SHIFT)) & RTC_WAR_CRW_MASK)
#define RTC_WAR_SRW_MASK                         (0x20U)
#define RTC_WAR_SRW_SHIFT                        (5U)
#define RTC_WAR_SRW(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_WAR_SRW_SHIFT)) & RTC_WAR_SRW_MASK)
#define RTC_WAR_LRW_MASK                         (0x40U)
#define RTC_WAR_LRW_SHIFT                        (6U)
#define RTC_WAR_LRW(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_WAR_LRW_SHIFT)) & RTC_WAR_LRW_MASK)
#define RTC_WAR_IERW_MASK                        (0x80U)
#define RTC_WAR_IERW_SHIFT                       (7U)
#define RTC_WAR_IERW(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_WAR_IERW_SHIFT)) & RTC_WAR_IERW_MASK)

/*! @name RAR - RTC Read Access Register */
#define RTC_RAR_TSRR_MASK                        (0x1U)
#define RTC_RAR_TSRR_SHIFT                       (0U)
#define RTC_RAR_TSRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TSRR_SHIFT)) & RTC_RAR_TSRR_MASK)
#define RTC_RAR_TPRR_MASK                        (0x2U)
#define RTC_RAR_TPRR_SHIFT                       (1U)
#define RTC_RAR_TPRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TPRR_SHIFT)) & RTC_RAR_TPRR_MASK)
#define RTC_RAR_TARR_MASK                        (0x4U)
#define RTC_RAR_TARR_SHIFT                       (2U)
#define RTC_RAR_TARR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TARR_SHIFT)) & RTC_RAR_TARR_MASK)
#define RTC_RAR_TCRR_MASK                        (0x8U)
#define RTC_RAR_TCRR_SHIFT                       (3U)
#define RTC_RAR_TCRR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_TCRR_SHIFT)) & RTC_RAR_TCRR_MASK)
#define RTC_RAR_CRR_MASK                         (0x10U)
#define RTC_RAR_CRR_SHIFT                        (4U)
#define RTC_RAR_CRR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_RAR_CRR_SHIFT)) & RTC_RAR_CRR_MASK)
#define RTC_RAR_SRR_MASK                         (0x20U)
#define RTC_RAR_SRR_SHIFT                        (5U)
#define RTC_RAR_SRR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_RAR_SRR_SHIFT)) & RTC_RAR_SRR_MASK)
#define RTC_RAR_LRR_MASK                         (0x40U)
#define RTC_RAR_LRR_SHIFT                        (6U)
#define RTC_RAR_LRR(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_RAR_LRR_SHIFT)) & RTC_RAR_LRR_MASK)
#define RTC_RAR_IERR_MASK                        (0x80U)
#define RTC_RAR_IERR_SHIFT                       (7U)
#define RTC_RAR_IERR(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_RAR_IERR_SHIFT)) & RTC_RAR_IERR_MASK)


/*!
 * @}
 */ /* end of group RTC_Register_Masks */


/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x4003D000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }
#define RTC_SECONDS_IRQS                         { RTC_Seconds_IRQn }

/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SOPT1;                             /**< System Options Register 1, offset: 0x0 */
       uint8_t RESERVED_0[4096];
  __IO uint32_t SOPT2;                             /**< System Options Register 2, offset: 0x1004 */
       uint8_t RESERVED_1[8];
  __IO uint32_t SOPT5;                             /**< System Options Register 5, offset: 0x1010 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SOPT7;                             /**< System Options Register 7, offset: 0x1018 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SOPT9;                             /**< System Options Register 9, offset: 0x1020 */
  __I  uint32_t SDID;                              /**< System Device Identification Register, offset: 0x1024 */
       uint8_t RESERVED_4[12];
  __IO uint32_t SCGC4;                             /**< System Clock Gating Control Register 4, offset: 0x1034 */
  __IO uint32_t SCGC5;                             /**< System Clock Gating Control Register 5, offset: 0x1038 */
  __IO uint32_t SCGC6;                             /**< System Clock Gating Control Register 6, offset: 0x103C */
  __IO uint32_t SCGC7;                             /**< System Clock Gating Control Register 7, offset: 0x1040 */
  __IO uint32_t CLKDIV1;                           /**< System Clock Divider Register 1, offset: 0x1044 */
  __IO uint32_t CLKDIV2;                           /**< System Clock Divider Register 2, offset: 0x1048 */
  __IO uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x104C */
  __I  uint32_t FCFG2;                             /**< Flash Configuration Register 2, offset: 0x1050 */
  __I  uint32_t UIDH;                              /**< Unique Identification Register High, offset: 0x1054 */
  __I  uint32_t UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x1058 */
  __I  uint32_t UIDML;                             /**< Unique Identification Register Mid Low, offset: 0x105C */
  __I  uint32_t UIDL;                              /**< Unique Identification Register Low, offset: 0x1060 */
  __IO uint32_t CLKDIV3;                           /**< System Clock Divider Register 3, offset: 0x1064 */
       uint8_t RESERVED_5[4];
  __IO uint32_t MISCCTL;                           /**< Miscellaneous Control Register, offset: 0x106C */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/*! @name SOPT1 - System Options Register 1 */
#define SIM_SOPT1_RAMSIZE_MASK                   (0xF000U)
#define SIM_SOPT1_RAMSIZE_SHIFT                  (12U)
#define SIM_SOPT1_RAMSIZE(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_RAMSIZE_SHIFT)) & SIM_SOPT1_RAMSIZE_MASK)
#define SIM_SOPT1_OSC32KOUT_MASK                 (0x30000U)
#define SIM_SOPT1_OSC32KOUT_SHIFT                (16U)
#define SIM_SOPT1_OSC32KOUT(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_OSC32KOUT_SHIFT)) & SIM_SOPT1_OSC32KOUT_MASK)
#define SIM_SOPT1_OSC32KSEL_MASK                 (0xC0000U)
#define SIM_SOPT1_OSC32KSEL_SHIFT                (18U)
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT1_OSC32KSEL_SHIFT)) & SIM_SOPT1_OSC32KSEL_MASK)

/*! @name SOPT2 - System Options Register 2 */
#define SIM_SOPT2_LPI2C1SRC_MASK                 (0xCU)
#define SIM_SOPT2_LPI2C1SRC_SHIFT                (2U)
#define SIM_SOPT2_LPI2C1SRC(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_LPI2C1SRC_SHIFT)) & SIM_SOPT2_LPI2C1SRC_MASK)
#define SIM_SOPT2_RTCCLKOUTSEL_MASK              (0x10U)
#define SIM_SOPT2_RTCCLKOUTSEL_SHIFT             (4U)
#define SIM_SOPT2_RTCCLKOUTSEL(x)                (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_RTCCLKOUTSEL_SHIFT)) & SIM_SOPT2_RTCCLKOUTSEL_MASK)
#define SIM_SOPT2_CLKOUTSEL_MASK                 (0xE0U)
#define SIM_SOPT2_CLKOUTSEL_SHIFT                (5U)
#define SIM_SOPT2_CLKOUTSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_CLKOUTSEL_SHIFT)) & SIM_SOPT2_CLKOUTSEL_MASK)
#define SIM_SOPT2_LPI2C0SRC_MASK                 (0xC00U)
#define SIM_SOPT2_LPI2C0SRC_SHIFT                (10U)
#define SIM_SOPT2_LPI2C0SRC(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_LPI2C0SRC_SHIFT)) & SIM_SOPT2_LPI2C0SRC_MASK)
#define SIM_SOPT2_TRACECLKSEL_MASK               (0x1000U)
#define SIM_SOPT2_TRACECLKSEL_SHIFT              (12U)
#define SIM_SOPT2_TRACECLKSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_TRACECLKSEL_SHIFT)) & SIM_SOPT2_TRACECLKSEL_MASK)
#define SIM_SOPT2_PLLFLLSEL_MASK                 (0x30000U)
#define SIM_SOPT2_PLLFLLSEL_SHIFT                (16U)
#define SIM_SOPT2_PLLFLLSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_PLLFLLSEL_SHIFT)) & SIM_SOPT2_PLLFLLSEL_MASK)
#define SIM_SOPT2_USBSRC_MASK                    (0x40000U)
#define SIM_SOPT2_USBSRC_SHIFT                   (18U)
#define SIM_SOPT2_USBSRC(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_USBSRC_SHIFT)) & SIM_SOPT2_USBSRC_MASK)
#define SIM_SOPT2_FLEXIOSRC_MASK                 (0xC00000U)
#define SIM_SOPT2_FLEXIOSRC_SHIFT                (22U)
#define SIM_SOPT2_FLEXIOSRC(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_FLEXIOSRC_SHIFT)) & SIM_SOPT2_FLEXIOSRC_MASK)
#define SIM_SOPT2_TPMSRC_MASK                    (0x3000000U)
#define SIM_SOPT2_TPMSRC_SHIFT                   (24U)
#define SIM_SOPT2_TPMSRC(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_TPMSRC_SHIFT)) & SIM_SOPT2_TPMSRC_MASK)
#define SIM_SOPT2_LPUARTSRC_MASK                 (0xC000000U)
#define SIM_SOPT2_LPUARTSRC_SHIFT                (26U)
#define SIM_SOPT2_LPUARTSRC(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_SOPT2_LPUARTSRC_SHIFT)) & SIM_SOPT2_LPUARTSRC_MASK)

/*! @name SOPT5 - System Options Register 5 */
#define SIM_SOPT5_UART0TXSRC_MASK                (0x3U)
#define SIM_SOPT5_UART0TXSRC_SHIFT               (0U)
#define SIM_SOPT5_UART0TXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART0TXSRC_SHIFT)) & SIM_SOPT5_UART0TXSRC_MASK)
#define SIM_SOPT5_UART0RXSRC_MASK                (0xCU)
#define SIM_SOPT5_UART0RXSRC_SHIFT               (2U)
#define SIM_SOPT5_UART0RXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART0RXSRC_SHIFT)) & SIM_SOPT5_UART0RXSRC_MASK)
#define SIM_SOPT5_UART1TXSRC_MASK                (0x30U)
#define SIM_SOPT5_UART1TXSRC_SHIFT               (4U)
#define SIM_SOPT5_UART1TXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART1TXSRC_SHIFT)) & SIM_SOPT5_UART1TXSRC_MASK)
#define SIM_SOPT5_UART1RXSRC_MASK                (0xC0U)
#define SIM_SOPT5_UART1RXSRC_SHIFT               (6U)
#define SIM_SOPT5_UART1RXSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_UART1RXSRC_SHIFT)) & SIM_SOPT5_UART1RXSRC_MASK)
#define SIM_SOPT5_LPUART0TXSRC_MASK              (0x30000U)
#define SIM_SOPT5_LPUART0TXSRC_SHIFT             (16U)
#define SIM_SOPT5_LPUART0TXSRC(x)                (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_LPUART0TXSRC_SHIFT)) & SIM_SOPT5_LPUART0TXSRC_MASK)
#define SIM_SOPT5_LPUART0RXSRC_MASK              (0xC0000U)
#define SIM_SOPT5_LPUART0RXSRC_SHIFT             (18U)
#define SIM_SOPT5_LPUART0RXSRC(x)                (((uint32_t)(((uint32_t)(x)) << SIM_SOPT5_LPUART0RXSRC_SHIFT)) & SIM_SOPT5_LPUART0RXSRC_MASK)

/*! @name SOPT7 - System Options Register 7 */
#define SIM_SOPT7_ADC0TRGSEL_MASK                (0xFU)
#define SIM_SOPT7_ADC0TRGSEL_SHIFT               (0U)
#define SIM_SOPT7_ADC0TRGSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0TRGSEL_SHIFT)) & SIM_SOPT7_ADC0TRGSEL_MASK)
#define SIM_SOPT7_ADC0PRETRGSEL_MASK             (0x10U)
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT            (4U)
#define SIM_SOPT7_ADC0PRETRGSEL(x)               (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0PRETRGSEL_SHIFT)) & SIM_SOPT7_ADC0PRETRGSEL_MASK)
#define SIM_SOPT7_ADC0ALTTRGEN_MASK              (0x80U)
#define SIM_SOPT7_ADC0ALTTRGEN_SHIFT             (7U)
#define SIM_SOPT7_ADC0ALTTRGEN(x)                (((uint32_t)(((uint32_t)(x)) << SIM_SOPT7_ADC0ALTTRGEN_SHIFT)) & SIM_SOPT7_ADC0ALTTRGEN_MASK)

/*! @name SOPT9 - System Options Register 9 */
#define SIM_SOPT9_TPM1CH0SRC_MASK                (0xC0000U)
#define SIM_SOPT9_TPM1CH0SRC_SHIFT               (18U)
#define SIM_SOPT9_TPM1CH0SRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT9_TPM1CH0SRC_SHIFT)) & SIM_SOPT9_TPM1CH0SRC_MASK)
#define SIM_SOPT9_TPM2CH0SRC_MASK                (0x300000U)
#define SIM_SOPT9_TPM2CH0SRC_SHIFT               (20U)
#define SIM_SOPT9_TPM2CH0SRC(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT9_TPM2CH0SRC_SHIFT)) & SIM_SOPT9_TPM2CH0SRC_MASK)
#define SIM_SOPT9_TPM0CLKSEL_MASK                (0x1000000U)
#define SIM_SOPT9_TPM0CLKSEL_SHIFT               (24U)
#define SIM_SOPT9_TPM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT9_TPM0CLKSEL_SHIFT)) & SIM_SOPT9_TPM0CLKSEL_MASK)
#define SIM_SOPT9_TPM1CLKSEL_MASK                (0x2000000U)
#define SIM_SOPT9_TPM1CLKSEL_SHIFT               (25U)
#define SIM_SOPT9_TPM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT9_TPM1CLKSEL_SHIFT)) & SIM_SOPT9_TPM1CLKSEL_MASK)
#define SIM_SOPT9_TPM2CLKSEL_MASK                (0x4000000U)
#define SIM_SOPT9_TPM2CLKSEL_SHIFT               (26U)
#define SIM_SOPT9_TPM2CLKSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_SOPT9_TPM2CLKSEL_SHIFT)) & SIM_SOPT9_TPM2CLKSEL_MASK)

/*! @name SDID - System Device Identification Register */
#define SIM_SDID_PINID_MASK                      (0xFU)
#define SIM_SDID_PINID_SHIFT                     (0U)
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_PINID_SHIFT)) & SIM_SDID_PINID_MASK)
#define SIM_SDID_FAMID_MASK                      (0x70U)
#define SIM_SDID_FAMID_SHIFT                     (4U)
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_FAMID_SHIFT)) & SIM_SDID_FAMID_MASK)
#define SIM_SDID_DIEID_MASK                      (0xF80U)
#define SIM_SDID_DIEID_SHIFT                     (7U)
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_DIEID_SHIFT)) & SIM_SDID_DIEID_MASK)
#define SIM_SDID_REVID_MASK                      (0xF000U)
#define SIM_SDID_REVID_SHIFT                     (12U)
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_REVID_SHIFT)) & SIM_SDID_REVID_MASK)
#define SIM_SDID_SERIESID_MASK                   (0xF00000U)
#define SIM_SDID_SERIESID_SHIFT                  (20U)
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SERIESID_SHIFT)) & SIM_SDID_SERIESID_MASK)
#define SIM_SDID_SUBFAMID_MASK                   (0xF000000U)
#define SIM_SDID_SUBFAMID_SHIFT                  (24U)
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SUBFAMID_SHIFT)) & SIM_SDID_SUBFAMID_MASK)
#define SIM_SDID_FAMILYID_MASK                   (0xF0000000U)
#define SIM_SDID_FAMILYID_SHIFT                  (28U)
#define SIM_SDID_FAMILYID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_FAMILYID_SHIFT)) & SIM_SDID_FAMILYID_MASK)

/*! @name SCGC4 - System Clock Gating Control Register 4 */
#define SIM_SCGC4_EWM_MASK                       (0x2U)
#define SIM_SCGC4_EWM_SHIFT                      (1U)
#define SIM_SCGC4_EWM(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_EWM_SHIFT)) & SIM_SCGC4_EWM_MASK)
#define SIM_SCGC4_LPI2C0_MASK                    (0x40U)
#define SIM_SCGC4_LPI2C0_SHIFT                   (6U)
#define SIM_SCGC4_LPI2C0(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_LPI2C0_SHIFT)) & SIM_SCGC4_LPI2C0_MASK)
#define SIM_SCGC4_LPI2C1_MASK                    (0x80U)
#define SIM_SCGC4_LPI2C1_SHIFT                   (7U)
#define SIM_SCGC4_LPI2C1(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_LPI2C1_SHIFT)) & SIM_SCGC4_LPI2C1_MASK)
#define SIM_SCGC4_UART0_MASK                     (0x400U)
#define SIM_SCGC4_UART0_SHIFT                    (10U)
#define SIM_SCGC4_UART0(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART0_SHIFT)) & SIM_SCGC4_UART0_MASK)
#define SIM_SCGC4_UART1_MASK                     (0x800U)
#define SIM_SCGC4_UART1_SHIFT                    (11U)
#define SIM_SCGC4_UART1(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART1_SHIFT)) & SIM_SCGC4_UART1_MASK)
#define SIM_SCGC4_UART2_MASK                     (0x1000U)
#define SIM_SCGC4_UART2_SHIFT                    (12U)
#define SIM_SCGC4_UART2(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_UART2_SHIFT)) & SIM_SCGC4_UART2_MASK)
#define SIM_SCGC4_USBOTG_MASK                    (0x40000U)
#define SIM_SCGC4_USBOTG_SHIFT                   (18U)
#define SIM_SCGC4_USBOTG(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_USBOTG_SHIFT)) & SIM_SCGC4_USBOTG_MASK)
#define SIM_SCGC4_CMP_MASK                       (0x80000U)
#define SIM_SCGC4_CMP_SHIFT                      (19U)
#define SIM_SCGC4_CMP(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC4_CMP_SHIFT)) & SIM_SCGC4_CMP_MASK)

/*! @name SCGC5 - System Clock Gating Control Register 5 */
#define SIM_SCGC5_LPTMR_MASK                     (0x1U)
#define SIM_SCGC5_LPTMR_SHIFT                    (0U)
#define SIM_SCGC5_LPTMR(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_LPTMR_SHIFT)) & SIM_SCGC5_LPTMR_MASK)
#define SIM_SCGC5_PORTA_MASK                     (0x200U)
#define SIM_SCGC5_PORTA_SHIFT                    (9U)
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTA_SHIFT)) & SIM_SCGC5_PORTA_MASK)
#define SIM_SCGC5_PORTB_MASK                     (0x400U)
#define SIM_SCGC5_PORTB_SHIFT                    (10U)
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTB_SHIFT)) & SIM_SCGC5_PORTB_MASK)
#define SIM_SCGC5_PORTC_MASK                     (0x800U)
#define SIM_SCGC5_PORTC_SHIFT                    (11U)
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTC_SHIFT)) & SIM_SCGC5_PORTC_MASK)
#define SIM_SCGC5_PORTD_MASK                     (0x1000U)
#define SIM_SCGC5_PORTD_SHIFT                    (12U)
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTD_SHIFT)) & SIM_SCGC5_PORTD_MASK)
#define SIM_SCGC5_PORTE_MASK                     (0x2000U)
#define SIM_SCGC5_PORTE_SHIFT                    (13U)
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTE_SHIFT)) & SIM_SCGC5_PORTE_MASK)
#define SIM_SCGC5_FLEXIO_MASK                    (0x80000000U)
#define SIM_SCGC5_FLEXIO_SHIFT                   (31U)
#define SIM_SCGC5_FLEXIO(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_FLEXIO_SHIFT)) & SIM_SCGC5_FLEXIO_MASK)

/*! @name SCGC6 - System Clock Gating Control Register 6 */
#define SIM_SCGC6_FTF_MASK                       (0x1U)
#define SIM_SCGC6_FTF_SHIFT                      (0U)
#define SIM_SCGC6_FTF(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_FTF_SHIFT)) & SIM_SCGC6_FTF_MASK)
#define SIM_SCGC6_DMAMUX_MASK                    (0x2U)
#define SIM_SCGC6_DMAMUX_SHIFT                   (1U)
#define SIM_SCGC6_DMAMUX(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DMAMUX_SHIFT)) & SIM_SCGC6_DMAMUX_MASK)
#define SIM_SCGC6_FLEXCAN0_MASK                  (0x10U)
#define SIM_SCGC6_FLEXCAN0_SHIFT                 (4U)
#define SIM_SCGC6_FLEXCAN0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_FLEXCAN0_SHIFT)) & SIM_SCGC6_FLEXCAN0_MASK)
#define SIM_SCGC6_FLEXCAN1_MASK                  (0x20U)
#define SIM_SCGC6_FLEXCAN1_SHIFT                 (5U)
#define SIM_SCGC6_FLEXCAN1(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_FLEXCAN1_SHIFT)) & SIM_SCGC6_FLEXCAN1_MASK)
#define SIM_SCGC6_RNGA_MASK                      (0x200U)
#define SIM_SCGC6_RNGA_SHIFT                     (9U)
#define SIM_SCGC6_RNGA(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_RNGA_SHIFT)) & SIM_SCGC6_RNGA_MASK)
#define SIM_SCGC6_LPUART0_MASK                   (0x400U)
#define SIM_SCGC6_LPUART0_SHIFT                  (10U)
#define SIM_SCGC6_LPUART0(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_LPUART0_SHIFT)) & SIM_SCGC6_LPUART0_MASK)
#define SIM_SCGC6_SPI0_MASK                      (0x1000U)
#define SIM_SCGC6_SPI0_SHIFT                     (12U)
#define SIM_SCGC6_SPI0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_SPI0_SHIFT)) & SIM_SCGC6_SPI0_MASK)
#define SIM_SCGC6_SPI1_MASK                      (0x2000U)
#define SIM_SCGC6_SPI1_SHIFT                     (13U)
#define SIM_SCGC6_SPI1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_SPI1_SHIFT)) & SIM_SCGC6_SPI1_MASK)
#define SIM_SCGC6_I2S0_MASK                      (0x8000U)
#define SIM_SCGC6_I2S0_SHIFT                     (15U)
#define SIM_SCGC6_I2S0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_I2S0_SHIFT)) & SIM_SCGC6_I2S0_MASK)
#define SIM_SCGC6_I2S1_MASK                      (0x10000U)
#define SIM_SCGC6_I2S1_SHIFT                     (16U)
#define SIM_SCGC6_I2S1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_I2S1_SHIFT)) & SIM_SCGC6_I2S1_MASK)
#define SIM_SCGC6_CRC_MASK                       (0x40000U)
#define SIM_SCGC6_CRC_SHIFT                      (18U)
#define SIM_SCGC6_CRC(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_CRC_SHIFT)) & SIM_SCGC6_CRC_MASK)
#define SIM_SCGC6_PDB_MASK                       (0x400000U)
#define SIM_SCGC6_PDB_SHIFT                      (22U)
#define SIM_SCGC6_PDB(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PDB_SHIFT)) & SIM_SCGC6_PDB_MASK)
#define SIM_SCGC6_PIT_MASK                       (0x800000U)
#define SIM_SCGC6_PIT_SHIFT                      (23U)
#define SIM_SCGC6_PIT(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_PIT_SHIFT)) & SIM_SCGC6_PIT_MASK)
#define SIM_SCGC6_TPM0_MASK                      (0x1000000U)
#define SIM_SCGC6_TPM0_SHIFT                     (24U)
#define SIM_SCGC6_TPM0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_TPM0_SHIFT)) & SIM_SCGC6_TPM0_MASK)
#define SIM_SCGC6_TPM1_MASK                      (0x2000000U)
#define SIM_SCGC6_TPM1_SHIFT                     (25U)
#define SIM_SCGC6_TPM1(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_TPM1_SHIFT)) & SIM_SCGC6_TPM1_MASK)
#define SIM_SCGC6_TPM2_MASK                      (0x4000000U)
#define SIM_SCGC6_TPM2_SHIFT                     (26U)
#define SIM_SCGC6_TPM2(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_TPM2_SHIFT)) & SIM_SCGC6_TPM2_MASK)
#define SIM_SCGC6_ADC0_MASK                      (0x8000000U)
#define SIM_SCGC6_ADC0_SHIFT                     (27U)
#define SIM_SCGC6_ADC0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_ADC0_SHIFT)) & SIM_SCGC6_ADC0_MASK)
#define SIM_SCGC6_RTC_MASK                       (0x20000000U)
#define SIM_SCGC6_RTC_SHIFT                      (29U)
#define SIM_SCGC6_RTC(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_RTC_SHIFT)) & SIM_SCGC6_RTC_MASK)
#define SIM_SCGC6_DAC0_MASK                      (0x80000000U)
#define SIM_SCGC6_DAC0_SHIFT                     (31U)
#define SIM_SCGC6_DAC0(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SCGC6_DAC0_SHIFT)) & SIM_SCGC6_DAC0_MASK)

/*! @name SCGC7 - System Clock Gating Control Register 7 */
#define SIM_SCGC7_DMA_MASK                       (0x2U)
#define SIM_SCGC7_DMA_SHIFT                      (1U)
#define SIM_SCGC7_DMA(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_SCGC7_DMA_SHIFT)) & SIM_SCGC7_DMA_MASK)

/*! @name CLKDIV1 - System Clock Divider Register 1 */
#define SIM_CLKDIV1_OUTDIV4_MASK                 (0xF0000U)
#define SIM_CLKDIV1_OUTDIV4_SHIFT                (16U)
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV4_SHIFT)) & SIM_CLKDIV1_OUTDIV4_MASK)
#define SIM_CLKDIV1_OUTDIV2_MASK                 (0xF000000U)
#define SIM_CLKDIV1_OUTDIV2_SHIFT                (24U)
#define SIM_CLKDIV1_OUTDIV2(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV2_SHIFT)) & SIM_CLKDIV1_OUTDIV2_MASK)
#define SIM_CLKDIV1_OUTDIV1_MASK                 (0xF0000000U)
#define SIM_CLKDIV1_OUTDIV1_SHIFT                (28U)
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV1_OUTDIV1_SHIFT)) & SIM_CLKDIV1_OUTDIV1_MASK)

/*! @name CLKDIV2 - System Clock Divider Register 2 */
#define SIM_CLKDIV2_USBFRAC_MASK                 (0x1U)
#define SIM_CLKDIV2_USBFRAC_SHIFT                (0U)
#define SIM_CLKDIV2_USBFRAC(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV2_USBFRAC_SHIFT)) & SIM_CLKDIV2_USBFRAC_MASK)
#define SIM_CLKDIV2_USBDIV_MASK                  (0xEU)
#define SIM_CLKDIV2_USBDIV_SHIFT                 (1U)
#define SIM_CLKDIV2_USBDIV(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV2_USBDIV_SHIFT)) & SIM_CLKDIV2_USBDIV_MASK)

/*! @name FCFG1 - Flash Configuration Register 1 */
#define SIM_FCFG1_FLASHDIS_MASK                  (0x1U)
#define SIM_FCFG1_FLASHDIS_SHIFT                 (0U)
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDIS_SHIFT)) & SIM_FCFG1_FLASHDIS_MASK)
#define SIM_FCFG1_FLASHDOZE_MASK                 (0x2U)
#define SIM_FCFG1_FLASHDOZE_SHIFT                (1U)
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDOZE_SHIFT)) & SIM_FCFG1_FLASHDOZE_MASK)
#define SIM_FCFG1_PFSIZE_MASK                    (0xF000000U)
#define SIM_FCFG1_PFSIZE_SHIFT                   (24U)
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_PFSIZE_SHIFT)) & SIM_FCFG1_PFSIZE_MASK)

/*! @name FCFG2 - Flash Configuration Register 2 */
#define SIM_FCFG2_MAXADDR0_MASK                  (0x7F000000U)
#define SIM_FCFG2_MAXADDR0_SHIFT                 (24U)
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_MAXADDR0_SHIFT)) & SIM_FCFG2_MAXADDR0_MASK)

/*! @name UIDH - Unique Identification Register High */
#define SIM_UIDH_UID_MASK                        (0xFFFFFFFFU)
#define SIM_UIDH_UID_SHIFT                       (0U)
#define SIM_UIDH_UID(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_UIDH_UID_SHIFT)) & SIM_UIDH_UID_MASK)

/*! @name UIDMH - Unique Identification Register Mid-High */
#define SIM_UIDMH_UID_MASK                       (0xFFFFFFFFU)
#define SIM_UIDMH_UID_SHIFT                      (0U)
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_UIDMH_UID_SHIFT)) & SIM_UIDMH_UID_MASK)

/*! @name UIDML - Unique Identification Register Mid Low */
#define SIM_UIDML_UID_MASK                       (0xFFFFFFFFU)
#define SIM_UIDML_UID_SHIFT                      (0U)
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x)) << SIM_UIDML_UID_SHIFT)) & SIM_UIDML_UID_MASK)

/*! @name UIDL - Unique Identification Register Low */
#define SIM_UIDL_UID_MASK                        (0xFFFFFFFFU)
#define SIM_UIDL_UID_SHIFT                       (0U)
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_UIDL_UID_SHIFT)) & SIM_UIDL_UID_MASK)

/*! @name CLKDIV3 - System Clock Divider Register 3 */
#define SIM_CLKDIV3_PLLFLLFRAC_MASK              (0x1U)
#define SIM_CLKDIV3_PLLFLLFRAC_SHIFT             (0U)
#define SIM_CLKDIV3_PLLFLLFRAC(x)                (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV3_PLLFLLFRAC_SHIFT)) & SIM_CLKDIV3_PLLFLLFRAC_MASK)
#define SIM_CLKDIV3_PLLFLLDIV_MASK               (0xEU)
#define SIM_CLKDIV3_PLLFLLDIV_SHIFT              (1U)
#define SIM_CLKDIV3_PLLFLLDIV(x)                 (((uint32_t)(((uint32_t)(x)) << SIM_CLKDIV3_PLLFLLDIV_SHIFT)) & SIM_CLKDIV3_PLLFLLDIV_MASK)

/*! @name MISCCTL - Miscellaneous Control Register */
#define SIM_MISCCTL_UARTSELONUSB_MASK            (0x3U)
#define SIM_MISCCTL_UARTSELONUSB_SHIFT           (0U)
#define SIM_MISCCTL_UARTSELONUSB(x)              (((uint32_t)(((uint32_t)(x)) << SIM_MISCCTL_UARTSELONUSB_SHIFT)) & SIM_MISCCTL_UARTSELONUSB_MASK)
#define SIM_MISCCTL_FlexIOS0_MASK                (0x4U)
#define SIM_MISCCTL_FlexIOS0_SHIFT               (2U)
#define SIM_MISCCTL_FlexIOS0(x)                  (((uint32_t)(((uint32_t)(x)) << SIM_MISCCTL_FlexIOS0_SHIFT)) & SIM_MISCCTL_FlexIOS0_MASK)


/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x40047000u)
/** Peripheral SIM base pointer */
#define SIM                                      ((SIM_Type *)SIM_BASE)
/** Array initializer of SIM peripheral base addresses */
#define SIM_BASE_ADDRS                           { SIM_BASE }
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM }

/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Peripheral_Access_Layer SMC Peripheral Access Layer
 * @{
 */

/** SMC - Register Layout Typedef */
typedef struct {
  __IO uint8_t PMPROT;                             /**< Power Mode Protection register, offset: 0x0 */
  __IO uint8_t PMCTRL;                             /**< Power Mode Control register, offset: 0x1 */
  __IO uint8_t STOPCTRL;                           /**< Stop Control Register, offset: 0x2 */
  __I  uint8_t PMSTAT;                             /**< Power Mode Status register, offset: 0x3 */
} SMC_Type;

/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Masks SMC Register Masks
 * @{
 */

/*! @name PMPROT - Power Mode Protection register */
#define SMC_PMPROT_AVLLS_MASK                    (0x2U)
#define SMC_PMPROT_AVLLS_SHIFT                   (1U)
#define SMC_PMPROT_AVLLS(x)                      (((uint8_t)(((uint8_t)(x)) << SMC_PMPROT_AVLLS_SHIFT)) & SMC_PMPROT_AVLLS_MASK)
#define SMC_PMPROT_ALLS_MASK                     (0x8U)
#define SMC_PMPROT_ALLS_SHIFT                    (3U)
#define SMC_PMPROT_ALLS(x)                       (((uint8_t)(((uint8_t)(x)) << SMC_PMPROT_ALLS_SHIFT)) & SMC_PMPROT_ALLS_MASK)
#define SMC_PMPROT_AVLP_MASK                     (0x20U)
#define SMC_PMPROT_AVLP_SHIFT                    (5U)
#define SMC_PMPROT_AVLP(x)                       (((uint8_t)(((uint8_t)(x)) << SMC_PMPROT_AVLP_SHIFT)) & SMC_PMPROT_AVLP_MASK)
#define SMC_PMPROT_AHSRUN_MASK                   (0x80U)
#define SMC_PMPROT_AHSRUN_SHIFT                  (7U)
#define SMC_PMPROT_AHSRUN(x)                     (((uint8_t)(((uint8_t)(x)) << SMC_PMPROT_AHSRUN_SHIFT)) & SMC_PMPROT_AHSRUN_MASK)

/*! @name PMCTRL - Power Mode Control register */
#define SMC_PMCTRL_STOPM_MASK                    (0x7U)
#define SMC_PMCTRL_STOPM_SHIFT                   (0U)
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x)) << SMC_PMCTRL_STOPM_SHIFT)) & SMC_PMCTRL_STOPM_MASK)
#define SMC_PMCTRL_STOPA_MASK                    (0x8U)
#define SMC_PMCTRL_STOPA_SHIFT                   (3U)
#define SMC_PMCTRL_STOPA(x)                      (((uint8_t)(((uint8_t)(x)) << SMC_PMCTRL_STOPA_SHIFT)) & SMC_PMCTRL_STOPA_MASK)
#define SMC_PMCTRL_RUNM_MASK                     (0x60U)
#define SMC_PMCTRL_RUNM_SHIFT                    (5U)
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x)) << SMC_PMCTRL_RUNM_SHIFT)) & SMC_PMCTRL_RUNM_MASK)

/*! @name STOPCTRL - Stop Control Register */
#define SMC_STOPCTRL_LLSM_MASK                   (0x7U)
#define SMC_STOPCTRL_LLSM_SHIFT                  (0U)
#define SMC_STOPCTRL_LLSM(x)                     (((uint8_t)(((uint8_t)(x)) << SMC_STOPCTRL_LLSM_SHIFT)) & SMC_STOPCTRL_LLSM_MASK)
#define SMC_STOPCTRL_LPOPO_MASK                  (0x8U)
#define SMC_STOPCTRL_LPOPO_SHIFT                 (3U)
#define SMC_STOPCTRL_LPOPO(x)                    (((uint8_t)(((uint8_t)(x)) << SMC_STOPCTRL_LPOPO_SHIFT)) & SMC_STOPCTRL_LPOPO_MASK)
#define SMC_STOPCTRL_PORPO_MASK                  (0x20U)
#define SMC_STOPCTRL_PORPO_SHIFT                 (5U)
#define SMC_STOPCTRL_PORPO(x)                    (((uint8_t)(((uint8_t)(x)) << SMC_STOPCTRL_PORPO_SHIFT)) & SMC_STOPCTRL_PORPO_MASK)
#define SMC_STOPCTRL_PSTOPO_MASK                 (0xC0U)
#define SMC_STOPCTRL_PSTOPO_SHIFT                (6U)
#define SMC_STOPCTRL_PSTOPO(x)                   (((uint8_t)(((uint8_t)(x)) << SMC_STOPCTRL_PSTOPO_SHIFT)) & SMC_STOPCTRL_PSTOPO_MASK)

/*! @name PMSTAT - Power Mode Status register */
#define SMC_PMSTAT_PMSTAT_MASK                   (0xFFU)
#define SMC_PMSTAT_PMSTAT_SHIFT                  (0U)
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x)) << SMC_PMSTAT_PMSTAT_SHIFT)) & SMC_PMSTAT_PMSTAT_MASK)


/*!
 * @}
 */ /* end of group SMC_Register_Masks */


/* SMC - Peripheral instance base addresses */
/** Peripheral SMC base address */
#define SMC_BASE                                 (0x4007E000u)
/** Peripheral SMC base pointer */
#define SMC                                      ((SMC_Type *)SMC_BASE)
/** Array initializer of SMC peripheral base addresses */
#define SMC_BASE_ADDRS                           { SMC_BASE }
/** Array initializer of SMC peripheral base pointers */
#define SMC_BASE_PTRS                            { SMC }

/*!
 * @}
 */ /* end of group SMC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Peripheral_Access_Layer SPI Peripheral Access Layer
 * @{
 */

/** SPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t TCR;                               /**< Transfer Count Register, offset: 0x8 */
  union {                                          /* offset: 0xC */
    __IO uint32_t CTAR[2];                           /**< Clock and Transfer Attributes Register (In Master Mode), array offset: 0xC, array step: 0x4 */
    __IO uint32_t CTAR_SLAVE[1];                     /**< Clock and Transfer Attributes Register (In Slave Mode), array offset: 0xC, array step: 0x4 */
  };
       uint8_t RESERVED_1[24];
  __IO uint32_t SR;                                /**< Status Register, offset: 0x2C */
  __IO uint32_t RSER;                              /**< DMA/Interrupt Request Select and Enable Register, offset: 0x30 */
  union {                                          /* offset: 0x34 */
    __IO uint32_t PUSHR;                             /**< PUSH TX FIFO Register In Master Mode, offset: 0x34 */
    __IO uint32_t PUSHR_SLAVE;                       /**< PUSH TX FIFO Register In Slave Mode, offset: 0x34 */
  };
  __I  uint32_t POPR;                              /**< POP RX FIFO Register, offset: 0x38 */
  __I  uint32_t TXFR0;                             /**< Transmit FIFO Registers, offset: 0x3C */
  __I  uint32_t TXFR1;                             /**< Transmit FIFO Registers, offset: 0x40 */
  __I  uint32_t TXFR2;                             /**< Transmit FIFO Registers, offset: 0x44 */
  __I  uint32_t TXFR3;                             /**< Transmit FIFO Registers, offset: 0x48 */
       uint8_t RESERVED_2[48];
  __I  uint32_t RXFR0;                             /**< Receive FIFO Registers, offset: 0x7C */
  __I  uint32_t RXFR1;                             /**< Receive FIFO Registers, offset: 0x80 */
  __I  uint32_t RXFR2;                             /**< Receive FIFO Registers, offset: 0x84 */
  __I  uint32_t RXFR3;                             /**< Receive FIFO Registers, offset: 0x88 */
} SPI_Type;

/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
#define SPI_MCR_HALT_MASK                        (0x1U)
#define SPI_MCR_HALT_SHIFT                       (0U)
#define SPI_MCR_HALT(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_HALT_SHIFT)) & SPI_MCR_HALT_MASK)
#define SPI_MCR_SMPL_PT_MASK                     (0x300U)
#define SPI_MCR_SMPL_PT_SHIFT                    (8U)
#define SPI_MCR_SMPL_PT(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_MCR_SMPL_PT_SHIFT)) & SPI_MCR_SMPL_PT_MASK)
#define SPI_MCR_CLR_RXF_MASK                     (0x400U)
#define SPI_MCR_CLR_RXF_SHIFT                    (10U)
#define SPI_MCR_CLR_RXF(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_MCR_CLR_RXF_SHIFT)) & SPI_MCR_CLR_RXF_MASK)
#define SPI_MCR_CLR_TXF_MASK                     (0x800U)
#define SPI_MCR_CLR_TXF_SHIFT                    (11U)
#define SPI_MCR_CLR_TXF(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_MCR_CLR_TXF_SHIFT)) & SPI_MCR_CLR_TXF_MASK)
#define SPI_MCR_DIS_RXF_MASK                     (0x1000U)
#define SPI_MCR_DIS_RXF_SHIFT                    (12U)
#define SPI_MCR_DIS_RXF(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_MCR_DIS_RXF_SHIFT)) & SPI_MCR_DIS_RXF_MASK)
#define SPI_MCR_DIS_TXF_MASK                     (0x2000U)
#define SPI_MCR_DIS_TXF_SHIFT                    (13U)
#define SPI_MCR_DIS_TXF(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_MCR_DIS_TXF_SHIFT)) & SPI_MCR_DIS_TXF_MASK)
#define SPI_MCR_MDIS_MASK                        (0x4000U)
#define SPI_MCR_MDIS_SHIFT                       (14U)
#define SPI_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_MDIS_SHIFT)) & SPI_MCR_MDIS_MASK)
#define SPI_MCR_DOZE_MASK                        (0x8000U)
#define SPI_MCR_DOZE_SHIFT                       (15U)
#define SPI_MCR_DOZE(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_DOZE_SHIFT)) & SPI_MCR_DOZE_MASK)
#define SPI_MCR_PCSIS_MASK                       (0x3F0000U)
#define SPI_MCR_PCSIS_SHIFT                      (16U)
#define SPI_MCR_PCSIS(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_MCR_PCSIS_SHIFT)) & SPI_MCR_PCSIS_MASK)
#define SPI_MCR_ROOE_MASK                        (0x1000000U)
#define SPI_MCR_ROOE_SHIFT                       (24U)
#define SPI_MCR_ROOE(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_ROOE_SHIFT)) & SPI_MCR_ROOE_MASK)
#define SPI_MCR_PCSSE_MASK                       (0x2000000U)
#define SPI_MCR_PCSSE_SHIFT                      (25U)
#define SPI_MCR_PCSSE(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_MCR_PCSSE_SHIFT)) & SPI_MCR_PCSSE_MASK)
#define SPI_MCR_MTFE_MASK                        (0x4000000U)
#define SPI_MCR_MTFE_SHIFT                       (26U)
#define SPI_MCR_MTFE(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_MTFE_SHIFT)) & SPI_MCR_MTFE_MASK)
#define SPI_MCR_FRZ_MASK                         (0x8000000U)
#define SPI_MCR_FRZ_SHIFT                        (27U)
#define SPI_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_MCR_FRZ_SHIFT)) & SPI_MCR_FRZ_MASK)
#define SPI_MCR_DCONF_MASK                       (0x30000000U)
#define SPI_MCR_DCONF_SHIFT                      (28U)
#define SPI_MCR_DCONF(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_MCR_DCONF_SHIFT)) & SPI_MCR_DCONF_MASK)
#define SPI_MCR_CONT_SCKE_MASK                   (0x40000000U)
#define SPI_MCR_CONT_SCKE_SHIFT                  (30U)
#define SPI_MCR_CONT_SCKE(x)                     (((uint32_t)(((uint32_t)(x)) << SPI_MCR_CONT_SCKE_SHIFT)) & SPI_MCR_CONT_SCKE_MASK)
#define SPI_MCR_MSTR_MASK                        (0x80000000U)
#define SPI_MCR_MSTR_SHIFT                       (31U)
#define SPI_MCR_MSTR(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_MCR_MSTR_SHIFT)) & SPI_MCR_MSTR_MASK)

/*! @name TCR - Transfer Count Register */
#define SPI_TCR_SPI_TCNT_MASK                    (0xFFFF0000U)
#define SPI_TCR_SPI_TCNT_SHIFT                   (16U)
#define SPI_TCR_SPI_TCNT(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_TCR_SPI_TCNT_SHIFT)) & SPI_TCR_SPI_TCNT_MASK)

/*! @name CTAR - Clock and Transfer Attributes Register (In Master Mode) */
#define SPI_CTAR_BR_MASK                         (0xFU)
#define SPI_CTAR_BR_SHIFT                        (0U)
#define SPI_CTAR_BR(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_BR_SHIFT)) & SPI_CTAR_BR_MASK)
#define SPI_CTAR_DT_MASK                         (0xF0U)
#define SPI_CTAR_DT_SHIFT                        (4U)
#define SPI_CTAR_DT(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_DT_SHIFT)) & SPI_CTAR_DT_MASK)
#define SPI_CTAR_ASC_MASK                        (0xF00U)
#define SPI_CTAR_ASC_SHIFT                       (8U)
#define SPI_CTAR_ASC(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_ASC_SHIFT)) & SPI_CTAR_ASC_MASK)
#define SPI_CTAR_CSSCK_MASK                      (0xF000U)
#define SPI_CTAR_CSSCK_SHIFT                     (12U)
#define SPI_CTAR_CSSCK(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_CSSCK_SHIFT)) & SPI_CTAR_CSSCK_MASK)
#define SPI_CTAR_PBR_MASK                        (0x30000U)
#define SPI_CTAR_PBR_SHIFT                       (16U)
#define SPI_CTAR_PBR(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_PBR_SHIFT)) & SPI_CTAR_PBR_MASK)
#define SPI_CTAR_PDT_MASK                        (0xC0000U)
#define SPI_CTAR_PDT_SHIFT                       (18U)
#define SPI_CTAR_PDT(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_PDT_SHIFT)) & SPI_CTAR_PDT_MASK)
#define SPI_CTAR_PASC_MASK                       (0x300000U)
#define SPI_CTAR_PASC_SHIFT                      (20U)
#define SPI_CTAR_PASC(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_PASC_SHIFT)) & SPI_CTAR_PASC_MASK)
#define SPI_CTAR_PCSSCK_MASK                     (0xC00000U)
#define SPI_CTAR_PCSSCK_SHIFT                    (22U)
#define SPI_CTAR_PCSSCK(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_PCSSCK_SHIFT)) & SPI_CTAR_PCSSCK_MASK)
#define SPI_CTAR_LSBFE_MASK                      (0x1000000U)
#define SPI_CTAR_LSBFE_SHIFT                     (24U)
#define SPI_CTAR_LSBFE(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_LSBFE_SHIFT)) & SPI_CTAR_LSBFE_MASK)
#define SPI_CTAR_CPHA_MASK                       (0x2000000U)
#define SPI_CTAR_CPHA_SHIFT                      (25U)
#define SPI_CTAR_CPHA(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_CPHA_SHIFT)) & SPI_CTAR_CPHA_MASK)
#define SPI_CTAR_CPOL_MASK                       (0x4000000U)
#define SPI_CTAR_CPOL_SHIFT                      (26U)
#define SPI_CTAR_CPOL(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_CPOL_SHIFT)) & SPI_CTAR_CPOL_MASK)
#define SPI_CTAR_FMSZ_MASK                       (0x78000000U)
#define SPI_CTAR_FMSZ_SHIFT                      (27U)
#define SPI_CTAR_FMSZ(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_FMSZ_SHIFT)) & SPI_CTAR_FMSZ_MASK)
#define SPI_CTAR_DBR_MASK                        (0x80000000U)
#define SPI_CTAR_DBR_SHIFT                       (31U)
#define SPI_CTAR_DBR(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_DBR_SHIFT)) & SPI_CTAR_DBR_MASK)

/* The count of SPI_CTAR */
#define SPI_CTAR_COUNT                           (2U)

/*! @name CTAR_SLAVE - Clock and Transfer Attributes Register (In Slave Mode) */
#define SPI_CTAR_SLAVE_CPHA_MASK                 (0x2000000U)
#define SPI_CTAR_SLAVE_CPHA_SHIFT                (25U)
#define SPI_CTAR_SLAVE_CPHA(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_SLAVE_CPHA_SHIFT)) & SPI_CTAR_SLAVE_CPHA_MASK)
#define SPI_CTAR_SLAVE_CPOL_MASK                 (0x4000000U)
#define SPI_CTAR_SLAVE_CPOL_SHIFT                (26U)
#define SPI_CTAR_SLAVE_CPOL(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_SLAVE_CPOL_SHIFT)) & SPI_CTAR_SLAVE_CPOL_MASK)
#define SPI_CTAR_SLAVE_FMSZ_MASK                 (0x78000000U)
#define SPI_CTAR_SLAVE_FMSZ_SHIFT                (27U)
#define SPI_CTAR_SLAVE_FMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << SPI_CTAR_SLAVE_FMSZ_SHIFT)) & SPI_CTAR_SLAVE_FMSZ_MASK)

/* The count of SPI_CTAR_SLAVE */
#define SPI_CTAR_SLAVE_COUNT                     (1U)

/*! @name SR - Status Register */
#define SPI_SR_POPNXTPTR_MASK                    (0xFU)
#define SPI_SR_POPNXTPTR_SHIFT                   (0U)
#define SPI_SR_POPNXTPTR(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_SR_POPNXTPTR_SHIFT)) & SPI_SR_POPNXTPTR_MASK)
#define SPI_SR_RXCTR_MASK                        (0xF0U)
#define SPI_SR_RXCTR_SHIFT                       (4U)
#define SPI_SR_RXCTR(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_SR_RXCTR_SHIFT)) & SPI_SR_RXCTR_MASK)
#define SPI_SR_TXNXTPTR_MASK                     (0xF00U)
#define SPI_SR_TXNXTPTR_SHIFT                    (8U)
#define SPI_SR_TXNXTPTR(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_SR_TXNXTPTR_SHIFT)) & SPI_SR_TXNXTPTR_MASK)
#define SPI_SR_TXCTR_MASK                        (0xF000U)
#define SPI_SR_TXCTR_SHIFT                       (12U)
#define SPI_SR_TXCTR(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_SR_TXCTR_SHIFT)) & SPI_SR_TXCTR_MASK)
#define SPI_SR_RFDF_MASK                         (0x20000U)
#define SPI_SR_RFDF_SHIFT                        (17U)
#define SPI_SR_RFDF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_RFDF_SHIFT)) & SPI_SR_RFDF_MASK)
#define SPI_SR_RFOF_MASK                         (0x80000U)
#define SPI_SR_RFOF_SHIFT                        (19U)
#define SPI_SR_RFOF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_RFOF_SHIFT)) & SPI_SR_RFOF_MASK)
#define SPI_SR_TFFF_MASK                         (0x2000000U)
#define SPI_SR_TFFF_SHIFT                        (25U)
#define SPI_SR_TFFF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_TFFF_SHIFT)) & SPI_SR_TFFF_MASK)
#define SPI_SR_TFUF_MASK                         (0x8000000U)
#define SPI_SR_TFUF_SHIFT                        (27U)
#define SPI_SR_TFUF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_TFUF_SHIFT)) & SPI_SR_TFUF_MASK)
#define SPI_SR_EOQF_MASK                         (0x10000000U)
#define SPI_SR_EOQF_SHIFT                        (28U)
#define SPI_SR_EOQF(x)                           (((uint32_t)(((uint32_t)(x)) << SPI_SR_EOQF_SHIFT)) & SPI_SR_EOQF_MASK)
#define SPI_SR_TXRXS_MASK                        (0x40000000U)
#define SPI_SR_TXRXS_SHIFT                       (30U)
#define SPI_SR_TXRXS(x)                          (((uint32_t)(((uint32_t)(x)) << SPI_SR_TXRXS_SHIFT)) & SPI_SR_TXRXS_MASK)
#define SPI_SR_TCF_MASK                          (0x80000000U)
#define SPI_SR_TCF_SHIFT                         (31U)
#define SPI_SR_TCF(x)                            (((uint32_t)(((uint32_t)(x)) << SPI_SR_TCF_SHIFT)) & SPI_SR_TCF_MASK)

/*! @name RSER - DMA/Interrupt Request Select and Enable Register */
#define SPI_RSER_RFDF_DIRS_MASK                  (0x10000U)
#define SPI_RSER_RFDF_DIRS_SHIFT                 (16U)
#define SPI_RSER_RFDF_DIRS(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_RSER_RFDF_DIRS_SHIFT)) & SPI_RSER_RFDF_DIRS_MASK)
#define SPI_RSER_RFDF_RE_MASK                    (0x20000U)
#define SPI_RSER_RFDF_RE_SHIFT                   (17U)
#define SPI_RSER_RFDF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RSER_RFDF_RE_SHIFT)) & SPI_RSER_RFDF_RE_MASK)
#define SPI_RSER_RFOF_RE_MASK                    (0x80000U)
#define SPI_RSER_RFOF_RE_SHIFT                   (19U)
#define SPI_RSER_RFOF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RSER_RFOF_RE_SHIFT)) & SPI_RSER_RFOF_RE_MASK)
#define SPI_RSER_TFFF_DIRS_MASK                  (0x1000000U)
#define SPI_RSER_TFFF_DIRS_SHIFT                 (24U)
#define SPI_RSER_TFFF_DIRS(x)                    (((uint32_t)(((uint32_t)(x)) << SPI_RSER_TFFF_DIRS_SHIFT)) & SPI_RSER_TFFF_DIRS_MASK)
#define SPI_RSER_TFFF_RE_MASK                    (0x2000000U)
#define SPI_RSER_TFFF_RE_SHIFT                   (25U)
#define SPI_RSER_TFFF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RSER_TFFF_RE_SHIFT)) & SPI_RSER_TFFF_RE_MASK)
#define SPI_RSER_TFUF_RE_MASK                    (0x8000000U)
#define SPI_RSER_TFUF_RE_SHIFT                   (27U)
#define SPI_RSER_TFUF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RSER_TFUF_RE_SHIFT)) & SPI_RSER_TFUF_RE_MASK)
#define SPI_RSER_EOQF_RE_MASK                    (0x10000000U)
#define SPI_RSER_EOQF_RE_SHIFT                   (28U)
#define SPI_RSER_EOQF_RE(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RSER_EOQF_RE_SHIFT)) & SPI_RSER_EOQF_RE_MASK)
#define SPI_RSER_TCF_RE_MASK                     (0x80000000U)
#define SPI_RSER_TCF_RE_SHIFT                    (31U)
#define SPI_RSER_TCF_RE(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_RSER_TCF_RE_SHIFT)) & SPI_RSER_TCF_RE_MASK)

/*! @name PUSHR - PUSH TX FIFO Register In Master Mode */
#define SPI_PUSHR_TXDATA_MASK                    (0xFFFFU)
#define SPI_PUSHR_TXDATA_SHIFT                   (0U)
#define SPI_PUSHR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_TXDATA_SHIFT)) & SPI_PUSHR_TXDATA_MASK)
#define SPI_PUSHR_PCS_MASK                       (0x3F0000U)
#define SPI_PUSHR_PCS_SHIFT                      (16U)
#define SPI_PUSHR_PCS(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_PCS_SHIFT)) & SPI_PUSHR_PCS_MASK)
#define SPI_PUSHR_CTCNT_MASK                     (0x4000000U)
#define SPI_PUSHR_CTCNT_SHIFT                    (26U)
#define SPI_PUSHR_CTCNT(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_CTCNT_SHIFT)) & SPI_PUSHR_CTCNT_MASK)
#define SPI_PUSHR_EOQ_MASK                       (0x8000000U)
#define SPI_PUSHR_EOQ_SHIFT                      (27U)
#define SPI_PUSHR_EOQ(x)                         (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_EOQ_SHIFT)) & SPI_PUSHR_EOQ_MASK)
#define SPI_PUSHR_CTAS_MASK                      (0x70000000U)
#define SPI_PUSHR_CTAS_SHIFT                     (28U)
#define SPI_PUSHR_CTAS(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_CTAS_SHIFT)) & SPI_PUSHR_CTAS_MASK)
#define SPI_PUSHR_CONT_MASK                      (0x80000000U)
#define SPI_PUSHR_CONT_SHIFT                     (31U)
#define SPI_PUSHR_CONT(x)                        (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_CONT_SHIFT)) & SPI_PUSHR_CONT_MASK)

/*! @name PUSHR_SLAVE - PUSH TX FIFO Register In Slave Mode */
#define SPI_PUSHR_SLAVE_TXDATA_MASK              (0xFFFFU)
#define SPI_PUSHR_SLAVE_TXDATA_SHIFT             (0U)
#define SPI_PUSHR_SLAVE_TXDATA(x)                (((uint32_t)(((uint32_t)(x)) << SPI_PUSHR_SLAVE_TXDATA_SHIFT)) & SPI_PUSHR_SLAVE_TXDATA_MASK)

/*! @name POPR - POP RX FIFO Register */
#define SPI_POPR_RXDATA_MASK                     (0xFFFFFFFFU)
#define SPI_POPR_RXDATA_SHIFT                    (0U)
#define SPI_POPR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x)) << SPI_POPR_RXDATA_SHIFT)) & SPI_POPR_RXDATA_MASK)

/*! @name TXFR0 - Transmit FIFO Registers */
#define SPI_TXFR0_TXDATA_MASK                    (0xFFFFU)
#define SPI_TXFR0_TXDATA_SHIFT                   (0U)
#define SPI_TXFR0_TXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_TXFR0_TXDATA_SHIFT)) & SPI_TXFR0_TXDATA_MASK)
#define SPI_TXFR0_TXCMD_TXDATA_MASK              (0xFFFF0000U)
#define SPI_TXFR0_TXCMD_TXDATA_SHIFT             (16U)
#define SPI_TXFR0_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x)) << SPI_TXFR0_TXCMD_TXDATA_SHIFT)) & SPI_TXFR0_TXCMD_TXDATA_MASK)

/*! @name TXFR1 - Transmit FIFO Registers */
#define SPI_TXFR1_TXDATA_MASK                    (0xFFFFU)
#define SPI_TXFR1_TXDATA_SHIFT                   (0U)
#define SPI_TXFR1_TXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_TXFR1_TXDATA_SHIFT)) & SPI_TXFR1_TXDATA_MASK)
#define SPI_TXFR1_TXCMD_TXDATA_MASK              (0xFFFF0000U)
#define SPI_TXFR1_TXCMD_TXDATA_SHIFT             (16U)
#define SPI_TXFR1_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x)) << SPI_TXFR1_TXCMD_TXDATA_SHIFT)) & SPI_TXFR1_TXCMD_TXDATA_MASK)

/*! @name TXFR2 - Transmit FIFO Registers */
#define SPI_TXFR2_TXDATA_MASK                    (0xFFFFU)
#define SPI_TXFR2_TXDATA_SHIFT                   (0U)
#define SPI_TXFR2_TXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_TXFR2_TXDATA_SHIFT)) & SPI_TXFR2_TXDATA_MASK)
#define SPI_TXFR2_TXCMD_TXDATA_MASK              (0xFFFF0000U)
#define SPI_TXFR2_TXCMD_TXDATA_SHIFT             (16U)
#define SPI_TXFR2_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x)) << SPI_TXFR2_TXCMD_TXDATA_SHIFT)) & SPI_TXFR2_TXCMD_TXDATA_MASK)

/*! @name TXFR3 - Transmit FIFO Registers */
#define SPI_TXFR3_TXDATA_MASK                    (0xFFFFU)
#define SPI_TXFR3_TXDATA_SHIFT                   (0U)
#define SPI_TXFR3_TXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_TXFR3_TXDATA_SHIFT)) & SPI_TXFR3_TXDATA_MASK)
#define SPI_TXFR3_TXCMD_TXDATA_MASK              (0xFFFF0000U)
#define SPI_TXFR3_TXCMD_TXDATA_SHIFT             (16U)
#define SPI_TXFR3_TXCMD_TXDATA(x)                (((uint32_t)(((uint32_t)(x)) << SPI_TXFR3_TXCMD_TXDATA_SHIFT)) & SPI_TXFR3_TXCMD_TXDATA_MASK)

/*! @name RXFR0 - Receive FIFO Registers */
#define SPI_RXFR0_RXDATA_MASK                    (0xFFFFFFFFU)
#define SPI_RXFR0_RXDATA_SHIFT                   (0U)
#define SPI_RXFR0_RXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RXFR0_RXDATA_SHIFT)) & SPI_RXFR0_RXDATA_MASK)

/*! @name RXFR1 - Receive FIFO Registers */
#define SPI_RXFR1_RXDATA_MASK                    (0xFFFFFFFFU)
#define SPI_RXFR1_RXDATA_SHIFT                   (0U)
#define SPI_RXFR1_RXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RXFR1_RXDATA_SHIFT)) & SPI_RXFR1_RXDATA_MASK)

/*! @name RXFR2 - Receive FIFO Registers */
#define SPI_RXFR2_RXDATA_MASK                    (0xFFFFFFFFU)
#define SPI_RXFR2_RXDATA_SHIFT                   (0U)
#define SPI_RXFR2_RXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RXFR2_RXDATA_SHIFT)) & SPI_RXFR2_RXDATA_MASK)

/*! @name RXFR3 - Receive FIFO Registers */
#define SPI_RXFR3_RXDATA_MASK                    (0xFFFFFFFFU)
#define SPI_RXFR3_RXDATA_SHIFT                   (0U)
#define SPI_RXFR3_RXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << SPI_RXFR3_RXDATA_SHIFT)) & SPI_RXFR3_RXDATA_MASK)


/*!
 * @}
 */ /* end of group SPI_Register_Masks */


/* SPI - Peripheral instance base addresses */
/** Peripheral SPI0 base address */
#define SPI0_BASE                                (0x4002C000u)
/** Peripheral SPI0 base pointer */
#define SPI0                                     ((SPI_Type *)SPI0_BASE)
/** Peripheral SPI1 base address */
#define SPI1_BASE                                (0x4002D000u)
/** Peripheral SPI1 base pointer */
#define SPI1                                     ((SPI_Type *)SPI1_BASE)
/** Array initializer of SPI peripheral base addresses */
#define SPI_BASE_ADDRS                           { SPI0_BASE, SPI1_BASE }
/** Array initializer of SPI peripheral base pointers */
#define SPI_BASE_PTRS                            { SPI0, SPI1 }
/** Interrupt vectors for the SPI peripheral type */
#define SPI_IRQS                                 { SPI0_IRQn, SPI1_IRQn }

/*!
 * @}
 */ /* end of group SPI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TPM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPM_Peripheral_Access_Layer TPM Peripheral Access Layer
 * @{
 */

/** TPM - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t GLOBAL;                            /**< TPM Global Register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SC;                                /**< Status and Control, offset: 0x10 */
  __IO uint32_t CNT;                               /**< Counter, offset: 0x14 */
  __IO uint32_t MOD;                               /**< Modulo, offset: 0x18 */
  __IO uint32_t STATUS;                            /**< Capture and Compare Status, offset: 0x1C */
  struct {                                         /* offset: 0x20, array step: 0x8 */
    __IO uint32_t CnSC;                              /**< Channel (n) Status and Control, array offset: 0x20, array step: 0x8 */
    __IO uint32_t CnV;                               /**< Channel (n) Value, array offset: 0x24, array step: 0x8 */
  } CONTROLS[6];
       uint8_t RESERVED_1[20];
  __IO uint32_t COMBINE;                           /**< Combine Channel Register, offset: 0x64 */
       uint8_t RESERVED_2[4];
  __IO uint32_t TRIG;                              /**< Channel Trigger, offset: 0x6C */
  __IO uint32_t POL;                               /**< Channel Polarity, offset: 0x70 */
       uint8_t RESERVED_3[4];
  __IO uint32_t FILTER;                            /**< Filter Control, offset: 0x78 */
       uint8_t RESERVED_4[4];
  __IO uint32_t QDCTRL;                            /**< Quadrature Decoder Control and Status, offset: 0x80 */
  __IO uint32_t CONF;                              /**< Configuration, offset: 0x84 */
} TPM_Type;

/* ----------------------------------------------------------------------------
   -- TPM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TPM_Register_Masks TPM Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
#define TPM_VERID_FEATURE_MASK                   (0xFFFFU)
#define TPM_VERID_FEATURE_SHIFT                  (0U)
#define TPM_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << TPM_VERID_FEATURE_SHIFT)) & TPM_VERID_FEATURE_MASK)
#define TPM_VERID_MINOR_MASK                     (0xFF0000U)
#define TPM_VERID_MINOR_SHIFT                    (16U)
#define TPM_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_VERID_MINOR_SHIFT)) & TPM_VERID_MINOR_MASK)
#define TPM_VERID_MAJOR_MASK                     (0xFF000000U)
#define TPM_VERID_MAJOR_SHIFT                    (24U)
#define TPM_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_VERID_MAJOR_SHIFT)) & TPM_VERID_MAJOR_MASK)

/*! @name PARAM - Parameter Register */
#define TPM_PARAM_CHAN_MASK                      (0xFFU)
#define TPM_PARAM_CHAN_SHIFT                     (0U)
#define TPM_PARAM_CHAN(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_PARAM_CHAN_SHIFT)) & TPM_PARAM_CHAN_MASK)
#define TPM_PARAM_TRIG_MASK                      (0xFF00U)
#define TPM_PARAM_TRIG_SHIFT                     (8U)
#define TPM_PARAM_TRIG(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_PARAM_TRIG_SHIFT)) & TPM_PARAM_TRIG_MASK)
#define TPM_PARAM_WIDTH_MASK                     (0xFF0000U)
#define TPM_PARAM_WIDTH_SHIFT                    (16U)
#define TPM_PARAM_WIDTH(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_PARAM_WIDTH_SHIFT)) & TPM_PARAM_WIDTH_MASK)

/*! @name GLOBAL - TPM Global Register */
#define TPM_GLOBAL_RST_MASK                      (0x2U)
#define TPM_GLOBAL_RST_SHIFT                     (1U)
#define TPM_GLOBAL_RST(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_GLOBAL_RST_SHIFT)) & TPM_GLOBAL_RST_MASK)

/*! @name SC - Status and Control */
#define TPM_SC_PS_MASK                           (0x7U)
#define TPM_SC_PS_SHIFT                          (0U)
#define TPM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x)) << TPM_SC_PS_SHIFT)) & TPM_SC_PS_MASK)
#define TPM_SC_CMOD_MASK                         (0x18U)
#define TPM_SC_CMOD_SHIFT                        (3U)
#define TPM_SC_CMOD(x)                           (((uint32_t)(((uint32_t)(x)) << TPM_SC_CMOD_SHIFT)) & TPM_SC_CMOD_MASK)
#define TPM_SC_CPWMS_MASK                        (0x20U)
#define TPM_SC_CPWMS_SHIFT                       (5U)
#define TPM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_SC_CPWMS_SHIFT)) & TPM_SC_CPWMS_MASK)
#define TPM_SC_TOIE_MASK                         (0x40U)
#define TPM_SC_TOIE_SHIFT                        (6U)
#define TPM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x)) << TPM_SC_TOIE_SHIFT)) & TPM_SC_TOIE_MASK)
#define TPM_SC_TOF_MASK                          (0x80U)
#define TPM_SC_TOF_SHIFT                         (7U)
#define TPM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x)) << TPM_SC_TOF_SHIFT)) & TPM_SC_TOF_MASK)
#define TPM_SC_DMA_MASK                          (0x100U)
#define TPM_SC_DMA_SHIFT                         (8U)
#define TPM_SC_DMA(x)                            (((uint32_t)(((uint32_t)(x)) << TPM_SC_DMA_SHIFT)) & TPM_SC_DMA_MASK)

/*! @name CNT - Counter */
#define TPM_CNT_COUNT_MASK                       (0xFFFFU)
#define TPM_CNT_COUNT_SHIFT                      (0U)
#define TPM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CNT_COUNT_SHIFT)) & TPM_CNT_COUNT_MASK)

/*! @name MOD - Modulo */
#define TPM_MOD_MOD_MASK                         (0xFFFFU)
#define TPM_MOD_MOD_SHIFT                        (0U)
#define TPM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x)) << TPM_MOD_MOD_SHIFT)) & TPM_MOD_MOD_MASK)

/*! @name STATUS - Capture and Compare Status */
#define TPM_STATUS_CH0F_MASK                     (0x1U)
#define TPM_STATUS_CH0F_SHIFT                    (0U)
#define TPM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH0F_SHIFT)) & TPM_STATUS_CH0F_MASK)
#define TPM_STATUS_CH1F_MASK                     (0x2U)
#define TPM_STATUS_CH1F_SHIFT                    (1U)
#define TPM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH1F_SHIFT)) & TPM_STATUS_CH1F_MASK)
#define TPM_STATUS_CH2F_MASK                     (0x4U)
#define TPM_STATUS_CH2F_SHIFT                    (2U)
#define TPM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH2F_SHIFT)) & TPM_STATUS_CH2F_MASK)
#define TPM_STATUS_CH3F_MASK                     (0x8U)
#define TPM_STATUS_CH3F_SHIFT                    (3U)
#define TPM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH3F_SHIFT)) & TPM_STATUS_CH3F_MASK)
#define TPM_STATUS_CH4F_MASK                     (0x10U)
#define TPM_STATUS_CH4F_SHIFT                    (4U)
#define TPM_STATUS_CH4F(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH4F_SHIFT)) & TPM_STATUS_CH4F_MASK)
#define TPM_STATUS_CH5F_MASK                     (0x20U)
#define TPM_STATUS_CH5F_SHIFT                    (5U)
#define TPM_STATUS_CH5F(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_CH5F_SHIFT)) & TPM_STATUS_CH5F_MASK)
#define TPM_STATUS_TOF_MASK                      (0x100U)
#define TPM_STATUS_TOF_SHIFT                     (8U)
#define TPM_STATUS_TOF(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_STATUS_TOF_SHIFT)) & TPM_STATUS_TOF_MASK)

/*! @name CnSC - Channel (n) Status and Control */
#define TPM_CnSC_DMA_MASK                        (0x1U)
#define TPM_CnSC_DMA_SHIFT                       (0U)
#define TPM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_DMA_SHIFT)) & TPM_CnSC_DMA_MASK)
#define TPM_CnSC_ELSA_MASK                       (0x4U)
#define TPM_CnSC_ELSA_SHIFT                      (2U)
#define TPM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_ELSA_SHIFT)) & TPM_CnSC_ELSA_MASK)
#define TPM_CnSC_ELSB_MASK                       (0x8U)
#define TPM_CnSC_ELSB_SHIFT                      (3U)
#define TPM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_ELSB_SHIFT)) & TPM_CnSC_ELSB_MASK)
#define TPM_CnSC_MSA_MASK                        (0x10U)
#define TPM_CnSC_MSA_SHIFT                       (4U)
#define TPM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_MSA_SHIFT)) & TPM_CnSC_MSA_MASK)
#define TPM_CnSC_MSB_MASK                        (0x20U)
#define TPM_CnSC_MSB_SHIFT                       (5U)
#define TPM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_MSB_SHIFT)) & TPM_CnSC_MSB_MASK)
#define TPM_CnSC_CHIE_MASK                       (0x40U)
#define TPM_CnSC_CHIE_SHIFT                      (6U)
#define TPM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_CHIE_SHIFT)) & TPM_CnSC_CHIE_MASK)
#define TPM_CnSC_CHF_MASK                        (0x80U)
#define TPM_CnSC_CHF_SHIFT                       (7U)
#define TPM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_CnSC_CHF_SHIFT)) & TPM_CnSC_CHF_MASK)

/* The count of TPM_CnSC */
#define TPM_CnSC_COUNT                           (6U)

/*! @name CnV - Channel (n) Value */
#define TPM_CnV_VAL_MASK                         (0xFFFFU)
#define TPM_CnV_VAL_SHIFT                        (0U)
#define TPM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x)) << TPM_CnV_VAL_SHIFT)) & TPM_CnV_VAL_MASK)

/* The count of TPM_CnV */
#define TPM_CnV_COUNT                            (6U)

/*! @name COMBINE - Combine Channel Register */
#define TPM_COMBINE_COMBINE0_MASK                (0x1U)
#define TPM_COMBINE_COMBINE0_SHIFT               (0U)
#define TPM_COMBINE_COMBINE0(x)                  (((uint32_t)(((uint32_t)(x)) << TPM_COMBINE_COMBINE0_SHIFT)) & TPM_COMBINE_COMBINE0_MASK)
#define TPM_COMBINE_COMSWAP0_MASK                (0x2U)
#define TPM_COMBINE_COMSWAP0_SHIFT               (1U)
#define TPM_COMBINE_COMSWAP0(x)                  (((uint32_t)(((uint32_t)(x)) << TPM_COMBINE_COMSWAP0_SHIFT)) & TPM_COMBINE_COMSWAP0_MASK)
#define TPM_COMBINE_COMBINE1_MASK                (0x100U)
#define TPM_COMBINE_COMBINE1_SHIFT               (8U)
#define TPM_COMBINE_COMBINE1(x)                  (((uint32_t)(((uint32_t)(x)) << TPM_COMBINE_COMBINE1_SHIFT)) & TPM_COMBINE_COMBINE1_MASK)
#define TPM_COMBINE_COMSWAP1_MASK                (0x200U)
#define TPM_COMBINE_COMSWAP1_SHIFT               (9U)
#define TPM_COMBINE_COMSWAP1(x)                  (((uint32_t)(((uint32_t)(x)) << TPM_COMBINE_COMSWAP1_SHIFT)) & TPM_COMBINE_COMSWAP1_MASK)
#define TPM_COMBINE_COMBINE2_MASK                (0x10000U)
#define TPM_COMBINE_COMBINE2_SHIFT               (16U)
#define TPM_COMBINE_COMBINE2(x)                  (((uint32_t)(((uint32_t)(x)) << TPM_COMBINE_COMBINE2_SHIFT)) & TPM_COMBINE_COMBINE2_MASK)
#define TPM_COMBINE_COMSWAP2_MASK                (0x20000U)
#define TPM_COMBINE_COMSWAP2_SHIFT               (17U)
#define TPM_COMBINE_COMSWAP2(x)                  (((uint32_t)(((uint32_t)(x)) << TPM_COMBINE_COMSWAP2_SHIFT)) & TPM_COMBINE_COMSWAP2_MASK)

/*! @name TRIG - Channel Trigger */
#define TPM_TRIG_TRIG0_MASK                      (0x1U)
#define TPM_TRIG_TRIG0_SHIFT                     (0U)
#define TPM_TRIG_TRIG0(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_TRIG_TRIG0_SHIFT)) & TPM_TRIG_TRIG0_MASK)
#define TPM_TRIG_TRIG1_MASK                      (0x2U)
#define TPM_TRIG_TRIG1_SHIFT                     (1U)
#define TPM_TRIG_TRIG1(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_TRIG_TRIG1_SHIFT)) & TPM_TRIG_TRIG1_MASK)
#define TPM_TRIG_TRIG2_MASK                      (0x4U)
#define TPM_TRIG_TRIG2_SHIFT                     (2U)
#define TPM_TRIG_TRIG2(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_TRIG_TRIG2_SHIFT)) & TPM_TRIG_TRIG2_MASK)
#define TPM_TRIG_TRIG3_MASK                      (0x8U)
#define TPM_TRIG_TRIG3_SHIFT                     (3U)
#define TPM_TRIG_TRIG3(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_TRIG_TRIG3_SHIFT)) & TPM_TRIG_TRIG3_MASK)
#define TPM_TRIG_TRIG4_MASK                      (0x10U)
#define TPM_TRIG_TRIG4_SHIFT                     (4U)
#define TPM_TRIG_TRIG4(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_TRIG_TRIG4_SHIFT)) & TPM_TRIG_TRIG4_MASK)
#define TPM_TRIG_TRIG5_MASK                      (0x20U)
#define TPM_TRIG_TRIG5_SHIFT                     (5U)
#define TPM_TRIG_TRIG5(x)                        (((uint32_t)(((uint32_t)(x)) << TPM_TRIG_TRIG5_SHIFT)) & TPM_TRIG_TRIG5_MASK)

/*! @name POL - Channel Polarity */
#define TPM_POL_POL0_MASK                        (0x1U)
#define TPM_POL_POL0_SHIFT                       (0U)
#define TPM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_POL_POL0_SHIFT)) & TPM_POL_POL0_MASK)
#define TPM_POL_POL1_MASK                        (0x2U)
#define TPM_POL_POL1_SHIFT                       (1U)
#define TPM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_POL_POL1_SHIFT)) & TPM_POL_POL1_MASK)
#define TPM_POL_POL2_MASK                        (0x4U)
#define TPM_POL_POL2_SHIFT                       (2U)
#define TPM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_POL_POL2_SHIFT)) & TPM_POL_POL2_MASK)
#define TPM_POL_POL3_MASK                        (0x8U)
#define TPM_POL_POL3_SHIFT                       (3U)
#define TPM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_POL_POL3_SHIFT)) & TPM_POL_POL3_MASK)
#define TPM_POL_POL4_MASK                        (0x10U)
#define TPM_POL_POL4_SHIFT                       (4U)
#define TPM_POL_POL4(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_POL_POL4_SHIFT)) & TPM_POL_POL4_MASK)
#define TPM_POL_POL5_MASK                        (0x20U)
#define TPM_POL_POL5_SHIFT                       (5U)
#define TPM_POL_POL5(x)                          (((uint32_t)(((uint32_t)(x)) << TPM_POL_POL5_SHIFT)) & TPM_POL_POL5_MASK)

/*! @name FILTER - Filter Control */
#define TPM_FILTER_CH0FVAL_MASK                  (0xFU)
#define TPM_FILTER_CH0FVAL_SHIFT                 (0U)
#define TPM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << TPM_FILTER_CH0FVAL_SHIFT)) & TPM_FILTER_CH0FVAL_MASK)
#define TPM_FILTER_CH1FVAL_MASK                  (0xF0U)
#define TPM_FILTER_CH1FVAL_SHIFT                 (4U)
#define TPM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << TPM_FILTER_CH1FVAL_SHIFT)) & TPM_FILTER_CH1FVAL_MASK)
#define TPM_FILTER_CH2FVAL_MASK                  (0xF00U)
#define TPM_FILTER_CH2FVAL_SHIFT                 (8U)
#define TPM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << TPM_FILTER_CH2FVAL_SHIFT)) & TPM_FILTER_CH2FVAL_MASK)
#define TPM_FILTER_CH3FVAL_MASK                  (0xF000U)
#define TPM_FILTER_CH3FVAL_SHIFT                 (12U)
#define TPM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << TPM_FILTER_CH3FVAL_SHIFT)) & TPM_FILTER_CH3FVAL_MASK)
#define TPM_FILTER_CH4FVAL_MASK                  (0xF0000U)
#define TPM_FILTER_CH4FVAL_SHIFT                 (16U)
#define TPM_FILTER_CH4FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << TPM_FILTER_CH4FVAL_SHIFT)) & TPM_FILTER_CH4FVAL_MASK)
#define TPM_FILTER_CH5FVAL_MASK                  (0xF00000U)
#define TPM_FILTER_CH5FVAL_SHIFT                 (20U)
#define TPM_FILTER_CH5FVAL(x)                    (((uint32_t)(((uint32_t)(x)) << TPM_FILTER_CH5FVAL_SHIFT)) & TPM_FILTER_CH5FVAL_MASK)

/*! @name QDCTRL - Quadrature Decoder Control and Status */
#define TPM_QDCTRL_QUADEN_MASK                   (0x1U)
#define TPM_QDCTRL_QUADEN_SHIFT                  (0U)
#define TPM_QDCTRL_QUADEN(x)                     (((uint32_t)(((uint32_t)(x)) << TPM_QDCTRL_QUADEN_SHIFT)) & TPM_QDCTRL_QUADEN_MASK)
#define TPM_QDCTRL_TOFDIR_MASK                   (0x2U)
#define TPM_QDCTRL_TOFDIR_SHIFT                  (1U)
#define TPM_QDCTRL_TOFDIR(x)                     (((uint32_t)(((uint32_t)(x)) << TPM_QDCTRL_TOFDIR_SHIFT)) & TPM_QDCTRL_TOFDIR_MASK)
#define TPM_QDCTRL_QUADIR_MASK                   (0x4U)
#define TPM_QDCTRL_QUADIR_SHIFT                  (2U)
#define TPM_QDCTRL_QUADIR(x)                     (((uint32_t)(((uint32_t)(x)) << TPM_QDCTRL_QUADIR_SHIFT)) & TPM_QDCTRL_QUADIR_MASK)
#define TPM_QDCTRL_QUADMODE_MASK                 (0x8U)
#define TPM_QDCTRL_QUADMODE_SHIFT                (3U)
#define TPM_QDCTRL_QUADMODE(x)                   (((uint32_t)(((uint32_t)(x)) << TPM_QDCTRL_QUADMODE_SHIFT)) & TPM_QDCTRL_QUADMODE_MASK)

/*! @name CONF - Configuration */
#define TPM_CONF_DOZEEN_MASK                     (0x20U)
#define TPM_CONF_DOZEEN_SHIFT                    (5U)
#define TPM_CONF_DOZEEN(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_CONF_DOZEEN_SHIFT)) & TPM_CONF_DOZEEN_MASK)
#define TPM_CONF_DBGMODE_MASK                    (0xC0U)
#define TPM_CONF_DBGMODE_SHIFT                   (6U)
#define TPM_CONF_DBGMODE(x)                      (((uint32_t)(((uint32_t)(x)) << TPM_CONF_DBGMODE_SHIFT)) & TPM_CONF_DBGMODE_MASK)
#define TPM_CONF_GTBSYNC_MASK                    (0x100U)
#define TPM_CONF_GTBSYNC_SHIFT                   (8U)
#define TPM_CONF_GTBSYNC(x)                      (((uint32_t)(((uint32_t)(x)) << TPM_CONF_GTBSYNC_SHIFT)) & TPM_CONF_GTBSYNC_MASK)
#define TPM_CONF_GTBEEN_MASK                     (0x200U)
#define TPM_CONF_GTBEEN_SHIFT                    (9U)
#define TPM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_CONF_GTBEEN_SHIFT)) & TPM_CONF_GTBEEN_MASK)
#define TPM_CONF_CSOT_MASK                       (0x10000U)
#define TPM_CONF_CSOT_SHIFT                      (16U)
#define TPM_CONF_CSOT(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CONF_CSOT_SHIFT)) & TPM_CONF_CSOT_MASK)
#define TPM_CONF_CSOO_MASK                       (0x20000U)
#define TPM_CONF_CSOO_SHIFT                      (17U)
#define TPM_CONF_CSOO(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CONF_CSOO_SHIFT)) & TPM_CONF_CSOO_MASK)
#define TPM_CONF_CROT_MASK                       (0x40000U)
#define TPM_CONF_CROT_SHIFT                      (18U)
#define TPM_CONF_CROT(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CONF_CROT_SHIFT)) & TPM_CONF_CROT_MASK)
#define TPM_CONF_CPOT_MASK                       (0x80000U)
#define TPM_CONF_CPOT_SHIFT                      (19U)
#define TPM_CONF_CPOT(x)                         (((uint32_t)(((uint32_t)(x)) << TPM_CONF_CPOT_SHIFT)) & TPM_CONF_CPOT_MASK)
#define TPM_CONF_TRGPOL_MASK                     (0x400000U)
#define TPM_CONF_TRGPOL_SHIFT                    (22U)
#define TPM_CONF_TRGPOL(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_CONF_TRGPOL_SHIFT)) & TPM_CONF_TRGPOL_MASK)
#define TPM_CONF_TRGSRC_MASK                     (0x800000U)
#define TPM_CONF_TRGSRC_SHIFT                    (23U)
#define TPM_CONF_TRGSRC(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_CONF_TRGSRC_SHIFT)) & TPM_CONF_TRGSRC_MASK)
#define TPM_CONF_TRGSEL_MASK                     (0xF000000U)
#define TPM_CONF_TRGSEL_SHIFT                    (24U)
#define TPM_CONF_TRGSEL(x)                       (((uint32_t)(((uint32_t)(x)) << TPM_CONF_TRGSEL_SHIFT)) & TPM_CONF_TRGSEL_MASK)


/*!
 * @}
 */ /* end of group TPM_Register_Masks */


/* TPM - Peripheral instance base addresses */
/** Peripheral TPM0 base address */
#define TPM0_BASE                                (0x40038000u)
/** Peripheral TPM0 base pointer */
#define TPM0                                     ((TPM_Type *)TPM0_BASE)
/** Peripheral TPM1 base address */
#define TPM1_BASE                                (0x40039000u)
/** Peripheral TPM1 base pointer */
#define TPM1                                     ((TPM_Type *)TPM1_BASE)
/** Peripheral TPM2 base address */
#define TPM2_BASE                                (0x4003A000u)
/** Peripheral TPM2 base pointer */
#define TPM2                                     ((TPM_Type *)TPM2_BASE)
/** Array initializer of TPM peripheral base addresses */
#define TPM_BASE_ADDRS                           { TPM0_BASE, TPM1_BASE, TPM2_BASE }
/** Array initializer of TPM peripheral base pointers */
#define TPM_BASE_PTRS                            { TPM0, TPM1, TPM2 }

/*!
 * @}
 */ /* end of group TPM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- UART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */

/** UART - Register Layout Typedef */
typedef struct {
  __IO uint8_t BDH;                                /**< UART Baud Rate Registers: High, offset: 0x0 */
  __IO uint8_t BDL;                                /**< UART Baud Rate Registers: Low, offset: 0x1 */
  __IO uint8_t C1;                                 /**< UART Control Register 1, offset: 0x2 */
  __IO uint8_t C2;                                 /**< UART Control Register 2, offset: 0x3 */
  __I  uint8_t S1;                                 /**< UART Status Register 1, offset: 0x4 */
  __IO uint8_t S2;                                 /**< UART Status Register 2, offset: 0x5 */
  __IO uint8_t C3;                                 /**< UART Control Register 3, offset: 0x6 */
  __IO uint8_t D;                                  /**< UART Data Register, offset: 0x7 */
  __IO uint8_t MA1;                                /**< UART Match Address Registers 1, offset: 0x8 */
  __IO uint8_t MA2;                                /**< UART Match Address Registers 2, offset: 0x9 */
  __IO uint8_t C4;                                 /**< UART Control Register 4, offset: 0xA */
  __IO uint8_t C5;                                 /**< UART Control Register 5, offset: 0xB */
  __I  uint8_t ED;                                 /**< UART Extended Data Register, offset: 0xC */
  __IO uint8_t MODEM;                              /**< UART Modem Register, offset: 0xD */
  __IO uint8_t IR;                                 /**< UART Infrared Register, offset: 0xE */
       uint8_t RESERVED_0[1];
  __IO uint8_t PFIFO;                              /**< UART FIFO Parameters, offset: 0x10 */
  __IO uint8_t CFIFO;                              /**< UART FIFO Control Register, offset: 0x11 */
  __IO uint8_t SFIFO;                              /**< UART FIFO Status Register, offset: 0x12 */
  __IO uint8_t TWFIFO;                             /**< UART FIFO Transmit Watermark, offset: 0x13 */
  __I  uint8_t TCFIFO;                             /**< UART FIFO Transmit Count, offset: 0x14 */
  __IO uint8_t RWFIFO;                             /**< UART FIFO Receive Watermark, offset: 0x15 */
  __I  uint8_t RCFIFO;                             /**< UART FIFO Receive Count, offset: 0x16 */
       uint8_t RESERVED_1[1];
  __IO uint8_t C7816;                              /**< UART 7816 Control Register, offset: 0x18 */
  __IO uint8_t IE7816;                             /**< UART 7816 Interrupt Enable Register, offset: 0x19 */
  __IO uint8_t IS7816;                             /**< UART 7816 Interrupt Status Register, offset: 0x1A */
  __IO uint8_t WP7816;                             /**< UART 7816 Wait Parameter Register, offset: 0x1B */
  __IO uint8_t WN7816;                             /**< UART 7816 Wait N Register, offset: 0x1C */
  __IO uint8_t WF7816;                             /**< UART 7816 Wait FD Register, offset: 0x1D */
  __IO uint8_t ET7816;                             /**< UART 7816 Error Threshold Register, offset: 0x1E */
  __IO uint8_t TL7816;                             /**< UART 7816 Transmit Length Register, offset: 0x1F */
       uint8_t RESERVED_2[26];
  __IO uint8_t AP7816A_T0;                         /**< UART 7816 ATR Duration Timer Register A, offset: 0x3A */
  __IO uint8_t AP7816B_T0;                         /**< UART 7816 ATR Duration Timer Register B, offset: 0x3B */
  union {                                          /* offset: 0x3C */
    struct {                                         /* offset: 0x3C */
      __IO uint8_t WP7816A_T0;                         /**< UART 7816 Wait Parameter Register A, offset: 0x3C */
      __IO uint8_t WP7816B_T0;                         /**< UART 7816 Wait Parameter Register B, offset: 0x3D */
    } TYPE0;
    struct {                                         /* offset: 0x3C */
      __IO uint8_t WP7816A_T1;                         /**< UART 7816 Wait Parameter Register A, offset: 0x3C */
      __IO uint8_t WP7816B_T1;                         /**< UART 7816 Wait Parameter Register B, offset: 0x3D */
    } TYPE1;
  };
  __IO uint8_t WGP7816_T1;                         /**< UART 7816 Wait and Guard Parameter Register, offset: 0x3E */
  __IO uint8_t WP7816C_T1;                         /**< UART 7816 Wait Parameter Register C, offset: 0x3F */
} UART_Type;

/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/*! @name BDH - UART Baud Rate Registers: High */
#define UART_BDH_SBR_MASK                        (0x1FU)
#define UART_BDH_SBR_SHIFT                       (0U)
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x)) << UART_BDH_SBR_SHIFT)) & UART_BDH_SBR_MASK)
#define UART_BDH_SBNS_MASK                       (0x20U)
#define UART_BDH_SBNS_SHIFT                      (5U)
#define UART_BDH_SBNS(x)                         (((uint8_t)(((uint8_t)(x)) << UART_BDH_SBNS_SHIFT)) & UART_BDH_SBNS_MASK)
#define UART_BDH_RXEDGIE_MASK                    (0x40U)
#define UART_BDH_RXEDGIE_SHIFT                   (6U)
#define UART_BDH_RXEDGIE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_BDH_RXEDGIE_SHIFT)) & UART_BDH_RXEDGIE_MASK)
#define UART_BDH_LBKDIE_MASK                     (0x80U)
#define UART_BDH_LBKDIE_SHIFT                    (7U)
#define UART_BDH_LBKDIE(x)                       (((uint8_t)(((uint8_t)(x)) << UART_BDH_LBKDIE_SHIFT)) & UART_BDH_LBKDIE_MASK)

/*! @name BDL - UART Baud Rate Registers: Low */
#define UART_BDL_SBR_MASK                        (0xFFU)
#define UART_BDL_SBR_SHIFT                       (0U)
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x)) << UART_BDL_SBR_SHIFT)) & UART_BDL_SBR_MASK)

/*! @name C1 - UART Control Register 1 */
#define UART_C1_PT_MASK                          (0x1U)
#define UART_C1_PT_SHIFT                         (0U)
#define UART_C1_PT(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C1_PT_SHIFT)) & UART_C1_PT_MASK)
#define UART_C1_PE_MASK                          (0x2U)
#define UART_C1_PE_SHIFT                         (1U)
#define UART_C1_PE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C1_PE_SHIFT)) & UART_C1_PE_MASK)
#define UART_C1_ILT_MASK                         (0x4U)
#define UART_C1_ILT_SHIFT                        (2U)
#define UART_C1_ILT(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C1_ILT_SHIFT)) & UART_C1_ILT_MASK)
#define UART_C1_WAKE_MASK                        (0x8U)
#define UART_C1_WAKE_SHIFT                       (3U)
#define UART_C1_WAKE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C1_WAKE_SHIFT)) & UART_C1_WAKE_MASK)
#define UART_C1_M_MASK                           (0x10U)
#define UART_C1_M_SHIFT                          (4U)
#define UART_C1_M(x)                             (((uint8_t)(((uint8_t)(x)) << UART_C1_M_SHIFT)) & UART_C1_M_MASK)
#define UART_C1_RSRC_MASK                        (0x20U)
#define UART_C1_RSRC_SHIFT                       (5U)
#define UART_C1_RSRC(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C1_RSRC_SHIFT)) & UART_C1_RSRC_MASK)
#define UART_C1_UARTSWAI_MASK                    (0x40U)
#define UART_C1_UARTSWAI_SHIFT                   (6U)
#define UART_C1_UARTSWAI(x)                      (((uint8_t)(((uint8_t)(x)) << UART_C1_UARTSWAI_SHIFT)) & UART_C1_UARTSWAI_MASK)
#define UART_C1_LOOPS_MASK                       (0x80U)
#define UART_C1_LOOPS_SHIFT                      (7U)
#define UART_C1_LOOPS(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C1_LOOPS_SHIFT)) & UART_C1_LOOPS_MASK)

/*! @name C2 - UART Control Register 2 */
#define UART_C2_SBK_MASK                         (0x1U)
#define UART_C2_SBK_SHIFT                        (0U)
#define UART_C2_SBK(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_SBK_SHIFT)) & UART_C2_SBK_MASK)
#define UART_C2_RWU_MASK                         (0x2U)
#define UART_C2_RWU_SHIFT                        (1U)
#define UART_C2_RWU(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_RWU_SHIFT)) & UART_C2_RWU_MASK)
#define UART_C2_RE_MASK                          (0x4U)
#define UART_C2_RE_SHIFT                         (2U)
#define UART_C2_RE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C2_RE_SHIFT)) & UART_C2_RE_MASK)
#define UART_C2_TE_MASK                          (0x8U)
#define UART_C2_TE_SHIFT                         (3U)
#define UART_C2_TE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C2_TE_SHIFT)) & UART_C2_TE_MASK)
#define UART_C2_ILIE_MASK                        (0x10U)
#define UART_C2_ILIE_SHIFT                       (4U)
#define UART_C2_ILIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C2_ILIE_SHIFT)) & UART_C2_ILIE_MASK)
#define UART_C2_RIE_MASK                         (0x20U)
#define UART_C2_RIE_SHIFT                        (5U)
#define UART_C2_RIE(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_RIE_SHIFT)) & UART_C2_RIE_MASK)
#define UART_C2_TCIE_MASK                        (0x40U)
#define UART_C2_TCIE_SHIFT                       (6U)
#define UART_C2_TCIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C2_TCIE_SHIFT)) & UART_C2_TCIE_MASK)
#define UART_C2_TIE_MASK                         (0x80U)
#define UART_C2_TIE_SHIFT                        (7U)
#define UART_C2_TIE(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C2_TIE_SHIFT)) & UART_C2_TIE_MASK)

/*! @name S1 - UART Status Register 1 */
#define UART_S1_PF_MASK                          (0x1U)
#define UART_S1_PF_SHIFT                         (0U)
#define UART_S1_PF(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_PF_SHIFT)) & UART_S1_PF_MASK)
#define UART_S1_FE_MASK                          (0x2U)
#define UART_S1_FE_SHIFT                         (1U)
#define UART_S1_FE(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_FE_SHIFT)) & UART_S1_FE_MASK)
#define UART_S1_NF_MASK                          (0x4U)
#define UART_S1_NF_SHIFT                         (2U)
#define UART_S1_NF(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_NF_SHIFT)) & UART_S1_NF_MASK)
#define UART_S1_OR_MASK                          (0x8U)
#define UART_S1_OR_SHIFT                         (3U)
#define UART_S1_OR(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_OR_SHIFT)) & UART_S1_OR_MASK)
#define UART_S1_IDLE_MASK                        (0x10U)
#define UART_S1_IDLE_SHIFT                       (4U)
#define UART_S1_IDLE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_S1_IDLE_SHIFT)) & UART_S1_IDLE_MASK)
#define UART_S1_RDRF_MASK                        (0x20U)
#define UART_S1_RDRF_SHIFT                       (5U)
#define UART_S1_RDRF(x)                          (((uint8_t)(((uint8_t)(x)) << UART_S1_RDRF_SHIFT)) & UART_S1_RDRF_MASK)
#define UART_S1_TC_MASK                          (0x40U)
#define UART_S1_TC_SHIFT                         (6U)
#define UART_S1_TC(x)                            (((uint8_t)(((uint8_t)(x)) << UART_S1_TC_SHIFT)) & UART_S1_TC_MASK)
#define UART_S1_TDRE_MASK                        (0x80U)
#define UART_S1_TDRE_SHIFT                       (7U)
#define UART_S1_TDRE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_S1_TDRE_SHIFT)) & UART_S1_TDRE_MASK)

/*! @name S2 - UART Status Register 2 */
#define UART_S2_RAF_MASK                         (0x1U)
#define UART_S2_RAF_SHIFT                        (0U)
#define UART_S2_RAF(x)                           (((uint8_t)(((uint8_t)(x)) << UART_S2_RAF_SHIFT)) & UART_S2_RAF_MASK)
#define UART_S2_LBKDE_MASK                       (0x2U)
#define UART_S2_LBKDE_SHIFT                      (1U)
#define UART_S2_LBKDE(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_LBKDE_SHIFT)) & UART_S2_LBKDE_MASK)
#define UART_S2_BRK13_MASK                       (0x4U)
#define UART_S2_BRK13_SHIFT                      (2U)
#define UART_S2_BRK13(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_BRK13_SHIFT)) & UART_S2_BRK13_MASK)
#define UART_S2_RWUID_MASK                       (0x8U)
#define UART_S2_RWUID_SHIFT                      (3U)
#define UART_S2_RWUID(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_RWUID_SHIFT)) & UART_S2_RWUID_MASK)
#define UART_S2_RXINV_MASK                       (0x10U)
#define UART_S2_RXINV_SHIFT                      (4U)
#define UART_S2_RXINV(x)                         (((uint8_t)(((uint8_t)(x)) << UART_S2_RXINV_SHIFT)) & UART_S2_RXINV_MASK)
#define UART_S2_MSBF_MASK                        (0x20U)
#define UART_S2_MSBF_SHIFT                       (5U)
#define UART_S2_MSBF(x)                          (((uint8_t)(((uint8_t)(x)) << UART_S2_MSBF_SHIFT)) & UART_S2_MSBF_MASK)
#define UART_S2_RXEDGIF_MASK                     (0x40U)
#define UART_S2_RXEDGIF_SHIFT                    (6U)
#define UART_S2_RXEDGIF(x)                       (((uint8_t)(((uint8_t)(x)) << UART_S2_RXEDGIF_SHIFT)) & UART_S2_RXEDGIF_MASK)
#define UART_S2_LBKDIF_MASK                      (0x80U)
#define UART_S2_LBKDIF_SHIFT                     (7U)
#define UART_S2_LBKDIF(x)                        (((uint8_t)(((uint8_t)(x)) << UART_S2_LBKDIF_SHIFT)) & UART_S2_LBKDIF_MASK)

/*! @name C3 - UART Control Register 3 */
#define UART_C3_PEIE_MASK                        (0x1U)
#define UART_C3_PEIE_SHIFT                       (0U)
#define UART_C3_PEIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_PEIE_SHIFT)) & UART_C3_PEIE_MASK)
#define UART_C3_FEIE_MASK                        (0x2U)
#define UART_C3_FEIE_SHIFT                       (1U)
#define UART_C3_FEIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_FEIE_SHIFT)) & UART_C3_FEIE_MASK)
#define UART_C3_NEIE_MASK                        (0x4U)
#define UART_C3_NEIE_SHIFT                       (2U)
#define UART_C3_NEIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_NEIE_SHIFT)) & UART_C3_NEIE_MASK)
#define UART_C3_ORIE_MASK                        (0x8U)
#define UART_C3_ORIE_SHIFT                       (3U)
#define UART_C3_ORIE(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C3_ORIE_SHIFT)) & UART_C3_ORIE_MASK)
#define UART_C3_TXINV_MASK                       (0x10U)
#define UART_C3_TXINV_SHIFT                      (4U)
#define UART_C3_TXINV(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C3_TXINV_SHIFT)) & UART_C3_TXINV_MASK)
#define UART_C3_TXDIR_MASK                       (0x20U)
#define UART_C3_TXDIR_SHIFT                      (5U)
#define UART_C3_TXDIR(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C3_TXDIR_SHIFT)) & UART_C3_TXDIR_MASK)
#define UART_C3_T8_MASK                          (0x40U)
#define UART_C3_T8_SHIFT                         (6U)
#define UART_C3_T8(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C3_T8_SHIFT)) & UART_C3_T8_MASK)
#define UART_C3_R8_MASK                          (0x80U)
#define UART_C3_R8_SHIFT                         (7U)
#define UART_C3_R8(x)                            (((uint8_t)(((uint8_t)(x)) << UART_C3_R8_SHIFT)) & UART_C3_R8_MASK)

/*! @name D - UART Data Register */
#define UART_D_RT_MASK                           (0xFFU)
#define UART_D_RT_SHIFT                          (0U)
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x)) << UART_D_RT_SHIFT)) & UART_D_RT_MASK)

/*! @name MA1 - UART Match Address Registers 1 */
#define UART_MA1_MA_MASK                         (0xFFU)
#define UART_MA1_MA_SHIFT                        (0U)
#define UART_MA1_MA(x)                           (((uint8_t)(((uint8_t)(x)) << UART_MA1_MA_SHIFT)) & UART_MA1_MA_MASK)

/*! @name MA2 - UART Match Address Registers 2 */
#define UART_MA2_MA_MASK                         (0xFFU)
#define UART_MA2_MA_SHIFT                        (0U)
#define UART_MA2_MA(x)                           (((uint8_t)(((uint8_t)(x)) << UART_MA2_MA_SHIFT)) & UART_MA2_MA_MASK)

/*! @name C4 - UART Control Register 4 */
#define UART_C4_BRFA_MASK                        (0x1FU)
#define UART_C4_BRFA_SHIFT                       (0U)
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x)) << UART_C4_BRFA_SHIFT)) & UART_C4_BRFA_MASK)
#define UART_C4_M10_MASK                         (0x20U)
#define UART_C4_M10_SHIFT                        (5U)
#define UART_C4_M10(x)                           (((uint8_t)(((uint8_t)(x)) << UART_C4_M10_SHIFT)) & UART_C4_M10_MASK)
#define UART_C4_MAEN2_MASK                       (0x40U)
#define UART_C4_MAEN2_SHIFT                      (6U)
#define UART_C4_MAEN2(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C4_MAEN2_SHIFT)) & UART_C4_MAEN2_MASK)
#define UART_C4_MAEN1_MASK                       (0x80U)
#define UART_C4_MAEN1_SHIFT                      (7U)
#define UART_C4_MAEN1(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C4_MAEN1_SHIFT)) & UART_C4_MAEN1_MASK)

/*! @name C5 - UART Control Register 5 */
#define UART_C5_LBKDDMAS_MASK                    (0x8U)
#define UART_C5_LBKDDMAS_SHIFT                   (3U)
#define UART_C5_LBKDDMAS(x)                      (((uint8_t)(((uint8_t)(x)) << UART_C5_LBKDDMAS_SHIFT)) & UART_C5_LBKDDMAS_MASK)
#define UART_C5_RDMAS_MASK                       (0x20U)
#define UART_C5_RDMAS_SHIFT                      (5U)
#define UART_C5_RDMAS(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C5_RDMAS_SHIFT)) & UART_C5_RDMAS_MASK)
#define UART_C5_TDMAS_MASK                       (0x80U)
#define UART_C5_TDMAS_SHIFT                      (7U)
#define UART_C5_TDMAS(x)                         (((uint8_t)(((uint8_t)(x)) << UART_C5_TDMAS_SHIFT)) & UART_C5_TDMAS_MASK)

/*! @name ED - UART Extended Data Register */
#define UART_ED_PARITYE_MASK                     (0x40U)
#define UART_ED_PARITYE_SHIFT                    (6U)
#define UART_ED_PARITYE(x)                       (((uint8_t)(((uint8_t)(x)) << UART_ED_PARITYE_SHIFT)) & UART_ED_PARITYE_MASK)
#define UART_ED_NOISY_MASK                       (0x80U)
#define UART_ED_NOISY_SHIFT                      (7U)
#define UART_ED_NOISY(x)                         (((uint8_t)(((uint8_t)(x)) << UART_ED_NOISY_SHIFT)) & UART_ED_NOISY_MASK)

/*! @name MODEM - UART Modem Register */
#define UART_MODEM_TXCTSE_MASK                   (0x1U)
#define UART_MODEM_TXCTSE_SHIFT                  (0U)
#define UART_MODEM_TXCTSE(x)                     (((uint8_t)(((uint8_t)(x)) << UART_MODEM_TXCTSE_SHIFT)) & UART_MODEM_TXCTSE_MASK)
#define UART_MODEM_TXRTSE_MASK                   (0x2U)
#define UART_MODEM_TXRTSE_SHIFT                  (1U)
#define UART_MODEM_TXRTSE(x)                     (((uint8_t)(((uint8_t)(x)) << UART_MODEM_TXRTSE_SHIFT)) & UART_MODEM_TXRTSE_MASK)
#define UART_MODEM_TXRTSPOL_MASK                 (0x4U)
#define UART_MODEM_TXRTSPOL_SHIFT                (2U)
#define UART_MODEM_TXRTSPOL(x)                   (((uint8_t)(((uint8_t)(x)) << UART_MODEM_TXRTSPOL_SHIFT)) & UART_MODEM_TXRTSPOL_MASK)
#define UART_MODEM_RXRTSE_MASK                   (0x8U)
#define UART_MODEM_RXRTSE_SHIFT                  (3U)
#define UART_MODEM_RXRTSE(x)                     (((uint8_t)(((uint8_t)(x)) << UART_MODEM_RXRTSE_SHIFT)) & UART_MODEM_RXRTSE_MASK)

/*! @name IR - UART Infrared Register */
#define UART_IR_TNP_MASK                         (0x3U)
#define UART_IR_TNP_SHIFT                        (0U)
#define UART_IR_TNP(x)                           (((uint8_t)(((uint8_t)(x)) << UART_IR_TNP_SHIFT)) & UART_IR_TNP_MASK)
#define UART_IR_IREN_MASK                        (0x4U)
#define UART_IR_IREN_SHIFT                       (2U)
#define UART_IR_IREN(x)                          (((uint8_t)(((uint8_t)(x)) << UART_IR_IREN_SHIFT)) & UART_IR_IREN_MASK)

/*! @name PFIFO - UART FIFO Parameters */
#define UART_PFIFO_RXFIFOSIZE_MASK               (0x7U)
#define UART_PFIFO_RXFIFOSIZE_SHIFT              (0U)
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x)) << UART_PFIFO_RXFIFOSIZE_SHIFT)) & UART_PFIFO_RXFIFOSIZE_MASK)
#define UART_PFIFO_RXFE_MASK                     (0x8U)
#define UART_PFIFO_RXFE_SHIFT                    (3U)
#define UART_PFIFO_RXFE(x)                       (((uint8_t)(((uint8_t)(x)) << UART_PFIFO_RXFE_SHIFT)) & UART_PFIFO_RXFE_MASK)
#define UART_PFIFO_TXFIFOSIZE_MASK               (0x70U)
#define UART_PFIFO_TXFIFOSIZE_SHIFT              (4U)
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x)) << UART_PFIFO_TXFIFOSIZE_SHIFT)) & UART_PFIFO_TXFIFOSIZE_MASK)
#define UART_PFIFO_TXFE_MASK                     (0x80U)
#define UART_PFIFO_TXFE_SHIFT                    (7U)
#define UART_PFIFO_TXFE(x)                       (((uint8_t)(((uint8_t)(x)) << UART_PFIFO_TXFE_SHIFT)) & UART_PFIFO_TXFE_MASK)

/*! @name CFIFO - UART FIFO Control Register */
#define UART_CFIFO_RXUFE_MASK                    (0x1U)
#define UART_CFIFO_RXUFE_SHIFT                   (0U)
#define UART_CFIFO_RXUFE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_CFIFO_RXUFE_SHIFT)) & UART_CFIFO_RXUFE_MASK)
#define UART_CFIFO_TXOFE_MASK                    (0x2U)
#define UART_CFIFO_TXOFE_SHIFT                   (1U)
#define UART_CFIFO_TXOFE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_CFIFO_TXOFE_SHIFT)) & UART_CFIFO_TXOFE_MASK)
#define UART_CFIFO_RXOFE_MASK                    (0x4U)
#define UART_CFIFO_RXOFE_SHIFT                   (2U)
#define UART_CFIFO_RXOFE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_CFIFO_RXOFE_SHIFT)) & UART_CFIFO_RXOFE_MASK)
#define UART_CFIFO_RXFLUSH_MASK                  (0x40U)
#define UART_CFIFO_RXFLUSH_SHIFT                 (6U)
#define UART_CFIFO_RXFLUSH(x)                    (((uint8_t)(((uint8_t)(x)) << UART_CFIFO_RXFLUSH_SHIFT)) & UART_CFIFO_RXFLUSH_MASK)
#define UART_CFIFO_TXFLUSH_MASK                  (0x80U)
#define UART_CFIFO_TXFLUSH_SHIFT                 (7U)
#define UART_CFIFO_TXFLUSH(x)                    (((uint8_t)(((uint8_t)(x)) << UART_CFIFO_TXFLUSH_SHIFT)) & UART_CFIFO_TXFLUSH_MASK)

/*! @name SFIFO - UART FIFO Status Register */
#define UART_SFIFO_RXUF_MASK                     (0x1U)
#define UART_SFIFO_RXUF_SHIFT                    (0U)
#define UART_SFIFO_RXUF(x)                       (((uint8_t)(((uint8_t)(x)) << UART_SFIFO_RXUF_SHIFT)) & UART_SFIFO_RXUF_MASK)
#define UART_SFIFO_TXOF_MASK                     (0x2U)
#define UART_SFIFO_TXOF_SHIFT                    (1U)
#define UART_SFIFO_TXOF(x)                       (((uint8_t)(((uint8_t)(x)) << UART_SFIFO_TXOF_SHIFT)) & UART_SFIFO_TXOF_MASK)
#define UART_SFIFO_RXOF_MASK                     (0x4U)
#define UART_SFIFO_RXOF_SHIFT                    (2U)
#define UART_SFIFO_RXOF(x)                       (((uint8_t)(((uint8_t)(x)) << UART_SFIFO_RXOF_SHIFT)) & UART_SFIFO_RXOF_MASK)
#define UART_SFIFO_RXEMPT_MASK                   (0x40U)
#define UART_SFIFO_RXEMPT_SHIFT                  (6U)
#define UART_SFIFO_RXEMPT(x)                     (((uint8_t)(((uint8_t)(x)) << UART_SFIFO_RXEMPT_SHIFT)) & UART_SFIFO_RXEMPT_MASK)
#define UART_SFIFO_TXEMPT_MASK                   (0x80U)
#define UART_SFIFO_TXEMPT_SHIFT                  (7U)
#define UART_SFIFO_TXEMPT(x)                     (((uint8_t)(((uint8_t)(x)) << UART_SFIFO_TXEMPT_SHIFT)) & UART_SFIFO_TXEMPT_MASK)

/*! @name TWFIFO - UART FIFO Transmit Watermark */
#define UART_TWFIFO_TXWATER_MASK                 (0xFFU)
#define UART_TWFIFO_TXWATER_SHIFT                (0U)
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x)) << UART_TWFIFO_TXWATER_SHIFT)) & UART_TWFIFO_TXWATER_MASK)

/*! @name TCFIFO - UART FIFO Transmit Count */
#define UART_TCFIFO_TXCOUNT_MASK                 (0xFFU)
#define UART_TCFIFO_TXCOUNT_SHIFT                (0U)
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x)) << UART_TCFIFO_TXCOUNT_SHIFT)) & UART_TCFIFO_TXCOUNT_MASK)

/*! @name RWFIFO - UART FIFO Receive Watermark */
#define UART_RWFIFO_RXWATER_MASK                 (0xFFU)
#define UART_RWFIFO_RXWATER_SHIFT                (0U)
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x)) << UART_RWFIFO_RXWATER_SHIFT)) & UART_RWFIFO_RXWATER_MASK)

/*! @name RCFIFO - UART FIFO Receive Count */
#define UART_RCFIFO_RXCOUNT_MASK                 (0xFFU)
#define UART_RCFIFO_RXCOUNT_SHIFT                (0U)
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x)) << UART_RCFIFO_RXCOUNT_SHIFT)) & UART_RCFIFO_RXCOUNT_MASK)

/*! @name C7816 - UART 7816 Control Register */
#define UART_C7816_ISO_7816E_MASK                (0x1U)
#define UART_C7816_ISO_7816E_SHIFT               (0U)
#define UART_C7816_ISO_7816E(x)                  (((uint8_t)(((uint8_t)(x)) << UART_C7816_ISO_7816E_SHIFT)) & UART_C7816_ISO_7816E_MASK)
#define UART_C7816_TTYPE_MASK                    (0x2U)
#define UART_C7816_TTYPE_SHIFT                   (1U)
#define UART_C7816_TTYPE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_C7816_TTYPE_SHIFT)) & UART_C7816_TTYPE_MASK)
#define UART_C7816_INIT_MASK                     (0x4U)
#define UART_C7816_INIT_SHIFT                    (2U)
#define UART_C7816_INIT(x)                       (((uint8_t)(((uint8_t)(x)) << UART_C7816_INIT_SHIFT)) & UART_C7816_INIT_MASK)
#define UART_C7816_ANACK_MASK                    (0x8U)
#define UART_C7816_ANACK_SHIFT                   (3U)
#define UART_C7816_ANACK(x)                      (((uint8_t)(((uint8_t)(x)) << UART_C7816_ANACK_SHIFT)) & UART_C7816_ANACK_MASK)
#define UART_C7816_ONACK_MASK                    (0x10U)
#define UART_C7816_ONACK_SHIFT                   (4U)
#define UART_C7816_ONACK(x)                      (((uint8_t)(((uint8_t)(x)) << UART_C7816_ONACK_SHIFT)) & UART_C7816_ONACK_MASK)

/*! @name IE7816 - UART 7816 Interrupt Enable Register */
#define UART_IE7816_RXTE_MASK                    (0x1U)
#define UART_IE7816_RXTE_SHIFT                   (0U)
#define UART_IE7816_RXTE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_IE7816_RXTE_SHIFT)) & UART_IE7816_RXTE_MASK)
#define UART_IE7816_TXTE_MASK                    (0x2U)
#define UART_IE7816_TXTE_SHIFT                   (1U)
#define UART_IE7816_TXTE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_IE7816_TXTE_SHIFT)) & UART_IE7816_TXTE_MASK)
#define UART_IE7816_GTVE_MASK                    (0x4U)
#define UART_IE7816_GTVE_SHIFT                   (2U)
#define UART_IE7816_GTVE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_IE7816_GTVE_SHIFT)) & UART_IE7816_GTVE_MASK)
#define UART_IE7816_ADTE_MASK                    (0x8U)
#define UART_IE7816_ADTE_SHIFT                   (3U)
#define UART_IE7816_ADTE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_IE7816_ADTE_SHIFT)) & UART_IE7816_ADTE_MASK)
#define UART_IE7816_INITDE_MASK                  (0x10U)
#define UART_IE7816_INITDE_SHIFT                 (4U)
#define UART_IE7816_INITDE(x)                    (((uint8_t)(((uint8_t)(x)) << UART_IE7816_INITDE_SHIFT)) & UART_IE7816_INITDE_MASK)
#define UART_IE7816_BWTE_MASK                    (0x20U)
#define UART_IE7816_BWTE_SHIFT                   (5U)
#define UART_IE7816_BWTE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_IE7816_BWTE_SHIFT)) & UART_IE7816_BWTE_MASK)
#define UART_IE7816_CWTE_MASK                    (0x40U)
#define UART_IE7816_CWTE_SHIFT                   (6U)
#define UART_IE7816_CWTE(x)                      (((uint8_t)(((uint8_t)(x)) << UART_IE7816_CWTE_SHIFT)) & UART_IE7816_CWTE_MASK)
#define UART_IE7816_WTE_MASK                     (0x80U)
#define UART_IE7816_WTE_SHIFT                    (7U)
#define UART_IE7816_WTE(x)                       (((uint8_t)(((uint8_t)(x)) << UART_IE7816_WTE_SHIFT)) & UART_IE7816_WTE_MASK)

/*! @name IS7816 - UART 7816 Interrupt Status Register */
#define UART_IS7816_RXT_MASK                     (0x1U)
#define UART_IS7816_RXT_SHIFT                    (0U)
#define UART_IS7816_RXT(x)                       (((uint8_t)(((uint8_t)(x)) << UART_IS7816_RXT_SHIFT)) & UART_IS7816_RXT_MASK)
#define UART_IS7816_TXT_MASK                     (0x2U)
#define UART_IS7816_TXT_SHIFT                    (1U)
#define UART_IS7816_TXT(x)                       (((uint8_t)(((uint8_t)(x)) << UART_IS7816_TXT_SHIFT)) & UART_IS7816_TXT_MASK)
#define UART_IS7816_GTV_MASK                     (0x4U)
#define UART_IS7816_GTV_SHIFT                    (2U)
#define UART_IS7816_GTV(x)                       (((uint8_t)(((uint8_t)(x)) << UART_IS7816_GTV_SHIFT)) & UART_IS7816_GTV_MASK)
#define UART_IS7816_ADT_MASK                     (0x8U)
#define UART_IS7816_ADT_SHIFT                    (3U)
#define UART_IS7816_ADT(x)                       (((uint8_t)(((uint8_t)(x)) << UART_IS7816_ADT_SHIFT)) & UART_IS7816_ADT_MASK)
#define UART_IS7816_INITD_MASK                   (0x10U)
#define UART_IS7816_INITD_SHIFT                  (4U)
#define UART_IS7816_INITD(x)                     (((uint8_t)(((uint8_t)(x)) << UART_IS7816_INITD_SHIFT)) & UART_IS7816_INITD_MASK)
#define UART_IS7816_BWT_MASK                     (0x20U)
#define UART_IS7816_BWT_SHIFT                    (5U)
#define UART_IS7816_BWT(x)                       (((uint8_t)(((uint8_t)(x)) << UART_IS7816_BWT_SHIFT)) & UART_IS7816_BWT_MASK)
#define UART_IS7816_CWT_MASK                     (0x40U)
#define UART_IS7816_CWT_SHIFT                    (6U)
#define UART_IS7816_CWT(x)                       (((uint8_t)(((uint8_t)(x)) << UART_IS7816_CWT_SHIFT)) & UART_IS7816_CWT_MASK)
#define UART_IS7816_WT_MASK                      (0x80U)
#define UART_IS7816_WT_SHIFT                     (7U)
#define UART_IS7816_WT(x)                        (((uint8_t)(((uint8_t)(x)) << UART_IS7816_WT_SHIFT)) & UART_IS7816_WT_MASK)

/*! @name WP7816 - UART 7816 Wait Parameter Register */
#define UART_WP7816_WTX_MASK                     (0xFFU)
#define UART_WP7816_WTX_SHIFT                    (0U)
#define UART_WP7816_WTX(x)                       (((uint8_t)(((uint8_t)(x)) << UART_WP7816_WTX_SHIFT)) & UART_WP7816_WTX_MASK)

/*! @name WN7816 - UART 7816 Wait N Register */
#define UART_WN7816_GTN_MASK                     (0xFFU)
#define UART_WN7816_GTN_SHIFT                    (0U)
#define UART_WN7816_GTN(x)                       (((uint8_t)(((uint8_t)(x)) << UART_WN7816_GTN_SHIFT)) & UART_WN7816_GTN_MASK)

/*! @name WF7816 - UART 7816 Wait FD Register */
#define UART_WF7816_GTFD_MASK                    (0xFFU)
#define UART_WF7816_GTFD_SHIFT                   (0U)
#define UART_WF7816_GTFD(x)                      (((uint8_t)(((uint8_t)(x)) << UART_WF7816_GTFD_SHIFT)) & UART_WF7816_GTFD_MASK)

/*! @name ET7816 - UART 7816 Error Threshold Register */
#define UART_ET7816_RXTHRESHOLD_MASK             (0xFU)
#define UART_ET7816_RXTHRESHOLD_SHIFT            (0U)
#define UART_ET7816_RXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x)) << UART_ET7816_RXTHRESHOLD_SHIFT)) & UART_ET7816_RXTHRESHOLD_MASK)
#define UART_ET7816_TXTHRESHOLD_MASK             (0xF0U)
#define UART_ET7816_TXTHRESHOLD_SHIFT            (4U)
#define UART_ET7816_TXTHRESHOLD(x)               (((uint8_t)(((uint8_t)(x)) << UART_ET7816_TXTHRESHOLD_SHIFT)) & UART_ET7816_TXTHRESHOLD_MASK)

/*! @name TL7816 - UART 7816 Transmit Length Register */
#define UART_TL7816_TLEN_MASK                    (0xFFU)
#define UART_TL7816_TLEN_SHIFT                   (0U)
#define UART_TL7816_TLEN(x)                      (((uint8_t)(((uint8_t)(x)) << UART_TL7816_TLEN_SHIFT)) & UART_TL7816_TLEN_MASK)

/*! @name AP7816A_T0 - UART 7816 ATR Duration Timer Register A */
#define UART_AP7816A_T0_ADTI_H_MASK              (0xFFU)
#define UART_AP7816A_T0_ADTI_H_SHIFT             (0U)
#define UART_AP7816A_T0_ADTI_H(x)                (((uint8_t)(((uint8_t)(x)) << UART_AP7816A_T0_ADTI_H_SHIFT)) & UART_AP7816A_T0_ADTI_H_MASK)

/*! @name AP7816B_T0 - UART 7816 ATR Duration Timer Register B */
#define UART_AP7816B_T0_ADTI_L_MASK              (0xFFU)
#define UART_AP7816B_T0_ADTI_L_SHIFT             (0U)
#define UART_AP7816B_T0_ADTI_L(x)                (((uint8_t)(((uint8_t)(x)) << UART_AP7816B_T0_ADTI_L_SHIFT)) & UART_AP7816B_T0_ADTI_L_MASK)

/*! @name WP7816A_T0 - UART 7816 Wait Parameter Register A */
#define UART_WP7816A_T0_WI_H_MASK                (0xFFU)
#define UART_WP7816A_T0_WI_H_SHIFT               (0U)
#define UART_WP7816A_T0_WI_H(x)                  (((uint8_t)(((uint8_t)(x)) << UART_WP7816A_T0_WI_H_SHIFT)) & UART_WP7816A_T0_WI_H_MASK)

/*! @name WP7816B_T0 - UART 7816 Wait Parameter Register B */
#define UART_WP7816B_T0_WI_L_MASK                (0xFFU)
#define UART_WP7816B_T0_WI_L_SHIFT               (0U)
#define UART_WP7816B_T0_WI_L(x)                  (((uint8_t)(((uint8_t)(x)) << UART_WP7816B_T0_WI_L_SHIFT)) & UART_WP7816B_T0_WI_L_MASK)

/*! @name WP7816A_T1 - UART 7816 Wait Parameter Register A */
#define UART_WP7816A_T1_BWI_H_MASK               (0xFFU)
#define UART_WP7816A_T1_BWI_H_SHIFT              (0U)
#define UART_WP7816A_T1_BWI_H(x)                 (((uint8_t)(((uint8_t)(x)) << UART_WP7816A_T1_BWI_H_SHIFT)) & UART_WP7816A_T1_BWI_H_MASK)

/*! @name WP7816B_T1 - UART 7816 Wait Parameter Register B */
#define UART_WP7816B_T1_BWI_L_MASK               (0xFFU)
#define UART_WP7816B_T1_BWI_L_SHIFT              (0U)
#define UART_WP7816B_T1_BWI_L(x)                 (((uint8_t)(((uint8_t)(x)) << UART_WP7816B_T1_BWI_L_SHIFT)) & UART_WP7816B_T1_BWI_L_MASK)

/*! @name WGP7816_T1 - UART 7816 Wait and Guard Parameter Register */
#define UART_WGP7816_T1_BGI_MASK                 (0xFU)
#define UART_WGP7816_T1_BGI_SHIFT                (0U)
#define UART_WGP7816_T1_BGI(x)                   (((uint8_t)(((uint8_t)(x)) << UART_WGP7816_T1_BGI_SHIFT)) & UART_WGP7816_T1_BGI_MASK)
#define UART_WGP7816_T1_CWI1_MASK                (0xF0U)
#define UART_WGP7816_T1_CWI1_SHIFT               (4U)
#define UART_WGP7816_T1_CWI1(x)                  (((uint8_t)(((uint8_t)(x)) << UART_WGP7816_T1_CWI1_SHIFT)) & UART_WGP7816_T1_CWI1_MASK)

/*! @name WP7816C_T1 - UART 7816 Wait Parameter Register C */
#define UART_WP7816C_T1_CWI2_MASK                (0x1FU)
#define UART_WP7816C_T1_CWI2_SHIFT               (0U)
#define UART_WP7816C_T1_CWI2(x)                  (((uint8_t)(((uint8_t)(x)) << UART_WP7816C_T1_CWI2_SHIFT)) & UART_WP7816C_T1_CWI2_MASK)


/*!
 * @}
 */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/** Peripheral UART0 base address */
#define UART0_BASE                               (0x4006A000u)
/** Peripheral UART0 base pointer */
#define UART0                                    ((UART_Type *)UART0_BASE)
/** Peripheral UART1 base address */
#define UART1_BASE                               (0x4006B000u)
/** Peripheral UART1 base pointer */
#define UART1                                    ((UART_Type *)UART1_BASE)
/** Peripheral UART2 base address */
#define UART2_BASE                               (0x4006C000u)
/** Peripheral UART2 base pointer */
#define UART2                                    ((UART_Type *)UART2_BASE)
/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS                          { UART0_BASE, UART1_BASE, UART2_BASE }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                           { UART0, UART1, UART2 }
/** Interrupt vectors for the UART peripheral type */
#define UART_RX_TX_IRQS                          { UART0_RX_TX_IRQn, UART1_RX_TX_IRQn, UART2_RX_TX_IRQn }
#define UART_ERR_IRQS                            { UART0_ERR_IRQn, UART1_ERR_IRQn, UART2_ERR_IRQn }

/*!
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- USB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Peripheral_Access_Layer USB Peripheral Access Layer
 * @{
 */

/** USB - Register Layout Typedef */
typedef struct {
  __I  uint8_t PERID;                              /**< Peripheral ID register, offset: 0x0 */
       uint8_t RESERVED_0[3];
  __I  uint8_t IDCOMP;                             /**< Peripheral ID Complement register, offset: 0x4 */
       uint8_t RESERVED_1[3];
  __I  uint8_t REV;                                /**< Peripheral Revision register, offset: 0x8 */
       uint8_t RESERVED_2[3];
  __I  uint8_t ADDINFO;                            /**< Peripheral Additional Info register, offset: 0xC */
       uint8_t RESERVED_3[3];
  __IO uint8_t OTGISTAT;                           /**< OTG Interrupt Status register, offset: 0x10 */
       uint8_t RESERVED_4[3];
  __IO uint8_t OTGICR;                             /**< OTG Interrupt Control register, offset: 0x14 */
       uint8_t RESERVED_5[3];
  __IO uint8_t OTGSTAT;                            /**< OTG Status register, offset: 0x18 */
       uint8_t RESERVED_6[3];
  __IO uint8_t OTGCTL;                             /**< OTG Control register, offset: 0x1C */
       uint8_t RESERVED_7[99];
  __IO uint8_t ISTAT;                              /**< Interrupt Status register, offset: 0x80 */
       uint8_t RESERVED_8[3];
  __IO uint8_t INTEN;                              /**< Interrupt Enable register, offset: 0x84 */
       uint8_t RESERVED_9[3];
  __IO uint8_t ERRSTAT;                            /**< Error Interrupt Status register, offset: 0x88 */
       uint8_t RESERVED_10[3];
  __IO uint8_t ERREN;                              /**< Error Interrupt Enable register, offset: 0x8C */
       uint8_t RESERVED_11[3];
  __I  uint8_t STAT;                               /**< Status register, offset: 0x90 */
       uint8_t RESERVED_12[3];
  __IO uint8_t CTL;                                /**< Control register, offset: 0x94 */
       uint8_t RESERVED_13[3];
  __IO uint8_t ADDR;                               /**< Address register, offset: 0x98 */
       uint8_t RESERVED_14[3];
  __IO uint8_t BDTPAGE1;                           /**< BDT Page register 1, offset: 0x9C */
       uint8_t RESERVED_15[3];
  __IO uint8_t FRMNUML;                            /**< Frame Number register Low, offset: 0xA0 */
       uint8_t RESERVED_16[3];
  __IO uint8_t FRMNUMH;                            /**< Frame Number register High, offset: 0xA4 */
       uint8_t RESERVED_17[3];
  __IO uint8_t TOKEN;                              /**< Token register, offset: 0xA8 */
       uint8_t RESERVED_18[3];
  __IO uint8_t SOFTHLD;                            /**< SOF Threshold register, offset: 0xAC */
       uint8_t RESERVED_19[3];
  __IO uint8_t BDTPAGE2;                           /**< BDT Page Register 2, offset: 0xB0 */
       uint8_t RESERVED_20[3];
  __IO uint8_t BDTPAGE3;                           /**< BDT Page Register 3, offset: 0xB4 */
       uint8_t RESERVED_21[11];
  struct {                                         /* offset: 0xC0, array step: 0x4 */
    __IO uint8_t ENDPT;                              /**< Endpoint Control register, array offset: 0xC0, array step: 0x4 */
         uint8_t RESERVED_0[3];
  } ENDPOINT[16];
  __IO uint8_t USBCTRL;                            /**< USB Control register, offset: 0x100 */
       uint8_t RESERVED_22[3];
  __I  uint8_t OBSERVE;                            /**< USB OTG Observe register, offset: 0x104 */
       uint8_t RESERVED_23[3];
  __IO uint8_t CONTROL;                            /**< USB OTG Control register, offset: 0x108 */
       uint8_t RESERVED_24[3];
  __IO uint8_t USBTRC0;                            /**< USB Transceiver Control register 0, offset: 0x10C */
       uint8_t RESERVED_25[7];
  __IO uint8_t USBFRMADJUST;                       /**< Frame Adjust Register, offset: 0x114 */
       uint8_t RESERVED_26[23];
  __IO uint8_t MISCCTRL;                           /**< Miscellaneous Control register, offset: 0x12C */
       uint8_t RESERVED_27[3];
  __IO uint8_t STALL_IL_DIS;                       /**< Peripheral mode stall disable for endpoints 7 to 0 in IN direction, offset: 0x130 */
       uint8_t RESERVED_28[3];
  __IO uint8_t STALL_IH_DIS;                       /**< Peripheral mode stall disable for endpoints 15 to 8 in IN direction, offset: 0x134 */
       uint8_t RESERVED_29[3];
  __IO uint8_t STALL_OL_DIS;                       /**< Peripheral mode stall disable for endpoints 7 to 0 in OUT direction, offset: 0x138 */
       uint8_t RESERVED_30[3];
  __IO uint8_t STALL_OH_DIS;                       /**< Peripheral mode stall disable for endpoints 15 to 8 in OUT direction, offset: 0x13C */
       uint8_t RESERVED_31[3];
  __IO uint8_t CLK_RECOVER_CTRL;                   /**< USB Clock recovery control, offset: 0x140 */
       uint8_t RESERVED_32[3];
  __IO uint8_t CLK_RECOVER_IRC_EN;                 /**< IRC48M oscillator enable register, offset: 0x144 */
       uint8_t RESERVED_33[15];
  __IO uint8_t CLK_RECOVER_INT_EN;                 /**< Clock recovery combined interrupt enable, offset: 0x154 */
       uint8_t RESERVED_34[7];
  __IO uint8_t CLK_RECOVER_INT_STATUS;             /**< Clock recovery separated interrupt status, offset: 0x15C */
} USB_Type;

/* ----------------------------------------------------------------------------
   -- USB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Register_Masks USB Register Masks
 * @{
 */

/*! @name PERID - Peripheral ID register */
#define USB_PERID_ID_MASK                        (0x3FU)
#define USB_PERID_ID_SHIFT                       (0U)
#define USB_PERID_ID(x)                          (((uint8_t)(((uint8_t)(x)) << USB_PERID_ID_SHIFT)) & USB_PERID_ID_MASK)

/*! @name IDCOMP - Peripheral ID Complement register */
#define USB_IDCOMP_NID_MASK                      (0x3FU)
#define USB_IDCOMP_NID_SHIFT                     (0U)
#define USB_IDCOMP_NID(x)                        (((uint8_t)(((uint8_t)(x)) << USB_IDCOMP_NID_SHIFT)) & USB_IDCOMP_NID_MASK)

/*! @name REV - Peripheral Revision register */
#define USB_REV_REV_MASK                         (0xFFU)
#define USB_REV_REV_SHIFT                        (0U)
#define USB_REV_REV(x)                           (((uint8_t)(((uint8_t)(x)) << USB_REV_REV_SHIFT)) & USB_REV_REV_MASK)

/*! @name ADDINFO - Peripheral Additional Info register */
#define USB_ADDINFO_IEHOST_MASK                  (0x1U)
#define USB_ADDINFO_IEHOST_SHIFT                 (0U)
#define USB_ADDINFO_IEHOST(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ADDINFO_IEHOST_SHIFT)) & USB_ADDINFO_IEHOST_MASK)

/*! @name OTGISTAT - OTG Interrupt Status register */
#define USB_OTGISTAT_LINE_STATE_CHG_MASK         (0x20U)
#define USB_OTGISTAT_LINE_STATE_CHG_SHIFT        (5U)
#define USB_OTGISTAT_LINE_STATE_CHG(x)           (((uint8_t)(((uint8_t)(x)) << USB_OTGISTAT_LINE_STATE_CHG_SHIFT)) & USB_OTGISTAT_LINE_STATE_CHG_MASK)
#define USB_OTGISTAT_ONEMSEC_MASK                (0x40U)
#define USB_OTGISTAT_ONEMSEC_SHIFT               (6U)
#define USB_OTGISTAT_ONEMSEC(x)                  (((uint8_t)(((uint8_t)(x)) << USB_OTGISTAT_ONEMSEC_SHIFT)) & USB_OTGISTAT_ONEMSEC_MASK)

/*! @name OTGICR - OTG Interrupt Control register */
#define USB_OTGICR_LINESTATEEN_MASK              (0x20U)
#define USB_OTGICR_LINESTATEEN_SHIFT             (5U)
#define USB_OTGICR_LINESTATEEN(x)                (((uint8_t)(((uint8_t)(x)) << USB_OTGICR_LINESTATEEN_SHIFT)) & USB_OTGICR_LINESTATEEN_MASK)
#define USB_OTGICR_ONEMSECEN_MASK                (0x40U)
#define USB_OTGICR_ONEMSECEN_SHIFT               (6U)
#define USB_OTGICR_ONEMSECEN(x)                  (((uint8_t)(((uint8_t)(x)) << USB_OTGICR_ONEMSECEN_SHIFT)) & USB_OTGICR_ONEMSECEN_MASK)

/*! @name OTGSTAT - OTG Status register */
#define USB_OTGSTAT_LINESTATESTABLE_MASK         (0x20U)
#define USB_OTGSTAT_LINESTATESTABLE_SHIFT        (5U)
#define USB_OTGSTAT_LINESTATESTABLE(x)           (((uint8_t)(((uint8_t)(x)) << USB_OTGSTAT_LINESTATESTABLE_SHIFT)) & USB_OTGSTAT_LINESTATESTABLE_MASK)
#define USB_OTGSTAT_ONEMSECEN_MASK               (0x40U)
#define USB_OTGSTAT_ONEMSECEN_SHIFT              (6U)
#define USB_OTGSTAT_ONEMSECEN(x)                 (((uint8_t)(((uint8_t)(x)) << USB_OTGSTAT_ONEMSECEN_SHIFT)) & USB_OTGSTAT_ONEMSECEN_MASK)

/*! @name OTGCTL - OTG Control register */
#define USB_OTGCTL_OTGEN_MASK                    (0x4U)
#define USB_OTGCTL_OTGEN_SHIFT                   (2U)
#define USB_OTGCTL_OTGEN(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OTGCTL_OTGEN_SHIFT)) & USB_OTGCTL_OTGEN_MASK)
#define USB_OTGCTL_DMLOW_MASK                    (0x10U)
#define USB_OTGCTL_DMLOW_SHIFT                   (4U)
#define USB_OTGCTL_DMLOW(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OTGCTL_DMLOW_SHIFT)) & USB_OTGCTL_DMLOW_MASK)
#define USB_OTGCTL_DPLOW_MASK                    (0x20U)
#define USB_OTGCTL_DPLOW_SHIFT                   (5U)
#define USB_OTGCTL_DPLOW(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OTGCTL_DPLOW_SHIFT)) & USB_OTGCTL_DPLOW_MASK)
#define USB_OTGCTL_DPHIGH_MASK                   (0x80U)
#define USB_OTGCTL_DPHIGH_SHIFT                  (7U)
#define USB_OTGCTL_DPHIGH(x)                     (((uint8_t)(((uint8_t)(x)) << USB_OTGCTL_DPHIGH_SHIFT)) & USB_OTGCTL_DPHIGH_MASK)

/*! @name ISTAT - Interrupt Status register */
#define USB_ISTAT_USBRST_MASK                    (0x1U)
#define USB_ISTAT_USBRST_SHIFT                   (0U)
#define USB_ISTAT_USBRST(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_USBRST_SHIFT)) & USB_ISTAT_USBRST_MASK)
#define USB_ISTAT_ERROR_MASK                     (0x2U)
#define USB_ISTAT_ERROR_SHIFT                    (1U)
#define USB_ISTAT_ERROR(x)                       (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_ERROR_SHIFT)) & USB_ISTAT_ERROR_MASK)
#define USB_ISTAT_SOFTOK_MASK                    (0x4U)
#define USB_ISTAT_SOFTOK_SHIFT                   (2U)
#define USB_ISTAT_SOFTOK(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_SOFTOK_SHIFT)) & USB_ISTAT_SOFTOK_MASK)
#define USB_ISTAT_TOKDNE_MASK                    (0x8U)
#define USB_ISTAT_TOKDNE_SHIFT                   (3U)
#define USB_ISTAT_TOKDNE(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_TOKDNE_SHIFT)) & USB_ISTAT_TOKDNE_MASK)
#define USB_ISTAT_SLEEP_MASK                     (0x10U)
#define USB_ISTAT_SLEEP_SHIFT                    (4U)
#define USB_ISTAT_SLEEP(x)                       (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_SLEEP_SHIFT)) & USB_ISTAT_SLEEP_MASK)
#define USB_ISTAT_RESUME_MASK                    (0x20U)
#define USB_ISTAT_RESUME_SHIFT                   (5U)
#define USB_ISTAT_RESUME(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_RESUME_SHIFT)) & USB_ISTAT_RESUME_MASK)
#define USB_ISTAT_ATTACH_MASK                    (0x40U)
#define USB_ISTAT_ATTACH_SHIFT                   (6U)
#define USB_ISTAT_ATTACH(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_ATTACH_SHIFT)) & USB_ISTAT_ATTACH_MASK)
#define USB_ISTAT_STALL_MASK                     (0x80U)
#define USB_ISTAT_STALL_SHIFT                    (7U)
#define USB_ISTAT_STALL(x)                       (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_STALL_SHIFT)) & USB_ISTAT_STALL_MASK)

/*! @name INTEN - Interrupt Enable register */
#define USB_INTEN_USBRSTEN_MASK                  (0x1U)
#define USB_INTEN_USBRSTEN_SHIFT                 (0U)
#define USB_INTEN_USBRSTEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_INTEN_USBRSTEN_SHIFT)) & USB_INTEN_USBRSTEN_MASK)
#define USB_INTEN_ERROREN_MASK                   (0x2U)
#define USB_INTEN_ERROREN_SHIFT                  (1U)
#define USB_INTEN_ERROREN(x)                     (((uint8_t)(((uint8_t)(x)) << USB_INTEN_ERROREN_SHIFT)) & USB_INTEN_ERROREN_MASK)
#define USB_INTEN_SOFTOKEN_MASK                  (0x4U)
#define USB_INTEN_SOFTOKEN_SHIFT                 (2U)
#define USB_INTEN_SOFTOKEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_INTEN_SOFTOKEN_SHIFT)) & USB_INTEN_SOFTOKEN_MASK)
#define USB_INTEN_TOKDNEEN_MASK                  (0x8U)
#define USB_INTEN_TOKDNEEN_SHIFT                 (3U)
#define USB_INTEN_TOKDNEEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_INTEN_TOKDNEEN_SHIFT)) & USB_INTEN_TOKDNEEN_MASK)
#define USB_INTEN_SLEEPEN_MASK                   (0x10U)
#define USB_INTEN_SLEEPEN_SHIFT                  (4U)
#define USB_INTEN_SLEEPEN(x)                     (((uint8_t)(((uint8_t)(x)) << USB_INTEN_SLEEPEN_SHIFT)) & USB_INTEN_SLEEPEN_MASK)
#define USB_INTEN_RESUMEEN_MASK                  (0x20U)
#define USB_INTEN_RESUMEEN_SHIFT                 (5U)
#define USB_INTEN_RESUMEEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_INTEN_RESUMEEN_SHIFT)) & USB_INTEN_RESUMEEN_MASK)
#define USB_INTEN_ATTACHEN_MASK                  (0x40U)
#define USB_INTEN_ATTACHEN_SHIFT                 (6U)
#define USB_INTEN_ATTACHEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_INTEN_ATTACHEN_SHIFT)) & USB_INTEN_ATTACHEN_MASK)
#define USB_INTEN_STALLEN_MASK                   (0x80U)
#define USB_INTEN_STALLEN_SHIFT                  (7U)
#define USB_INTEN_STALLEN(x)                     (((uint8_t)(((uint8_t)(x)) << USB_INTEN_STALLEN_SHIFT)) & USB_INTEN_STALLEN_MASK)

/*! @name ERRSTAT - Error Interrupt Status register */
#define USB_ERRSTAT_PIDERR_MASK                  (0x1U)
#define USB_ERRSTAT_PIDERR_SHIFT                 (0U)
#define USB_ERRSTAT_PIDERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_PIDERR_SHIFT)) & USB_ERRSTAT_PIDERR_MASK)
#define USB_ERRSTAT_CRC5EOF_MASK                 (0x2U)
#define USB_ERRSTAT_CRC5EOF_SHIFT                (1U)
#define USB_ERRSTAT_CRC5EOF(x)                   (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_CRC5EOF_SHIFT)) & USB_ERRSTAT_CRC5EOF_MASK)
#define USB_ERRSTAT_CRC16_MASK                   (0x4U)
#define USB_ERRSTAT_CRC16_SHIFT                  (2U)
#define USB_ERRSTAT_CRC16(x)                     (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_CRC16_SHIFT)) & USB_ERRSTAT_CRC16_MASK)
#define USB_ERRSTAT_DFN8_MASK                    (0x8U)
#define USB_ERRSTAT_DFN8_SHIFT                   (3U)
#define USB_ERRSTAT_DFN8(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_DFN8_SHIFT)) & USB_ERRSTAT_DFN8_MASK)
#define USB_ERRSTAT_BTOERR_MASK                  (0x10U)
#define USB_ERRSTAT_BTOERR_SHIFT                 (4U)
#define USB_ERRSTAT_BTOERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_BTOERR_SHIFT)) & USB_ERRSTAT_BTOERR_MASK)
#define USB_ERRSTAT_DMAERR_MASK                  (0x20U)
#define USB_ERRSTAT_DMAERR_SHIFT                 (5U)
#define USB_ERRSTAT_DMAERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_DMAERR_SHIFT)) & USB_ERRSTAT_DMAERR_MASK)
#define USB_ERRSTAT_OWNERR_MASK                  (0x40U)
#define USB_ERRSTAT_OWNERR_SHIFT                 (6U)
#define USB_ERRSTAT_OWNERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_OWNERR_SHIFT)) & USB_ERRSTAT_OWNERR_MASK)
#define USB_ERRSTAT_BTSERR_MASK                  (0x80U)
#define USB_ERRSTAT_BTSERR_SHIFT                 (7U)
#define USB_ERRSTAT_BTSERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_BTSERR_SHIFT)) & USB_ERRSTAT_BTSERR_MASK)

/*! @name ERREN - Error Interrupt Enable register */
#define USB_ERREN_PIDERREN_MASK                  (0x1U)
#define USB_ERREN_PIDERREN_SHIFT                 (0U)
#define USB_ERREN_PIDERREN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERREN_PIDERREN_SHIFT)) & USB_ERREN_PIDERREN_MASK)
#define USB_ERREN_CRC5EOFEN_MASK                 (0x2U)
#define USB_ERREN_CRC5EOFEN_SHIFT                (1U)
#define USB_ERREN_CRC5EOFEN(x)                   (((uint8_t)(((uint8_t)(x)) << USB_ERREN_CRC5EOFEN_SHIFT)) & USB_ERREN_CRC5EOFEN_MASK)
#define USB_ERREN_CRC16EN_MASK                   (0x4U)
#define USB_ERREN_CRC16EN_SHIFT                  (2U)
#define USB_ERREN_CRC16EN(x)                     (((uint8_t)(((uint8_t)(x)) << USB_ERREN_CRC16EN_SHIFT)) & USB_ERREN_CRC16EN_MASK)
#define USB_ERREN_DFN8EN_MASK                    (0x8U)
#define USB_ERREN_DFN8EN_SHIFT                   (3U)
#define USB_ERREN_DFN8EN(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ERREN_DFN8EN_SHIFT)) & USB_ERREN_DFN8EN_MASK)
#define USB_ERREN_BTOERREN_MASK                  (0x10U)
#define USB_ERREN_BTOERREN_SHIFT                 (4U)
#define USB_ERREN_BTOERREN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERREN_BTOERREN_SHIFT)) & USB_ERREN_BTOERREN_MASK)
#define USB_ERREN_DMAERREN_MASK                  (0x20U)
#define USB_ERREN_DMAERREN_SHIFT                 (5U)
#define USB_ERREN_DMAERREN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERREN_DMAERREN_SHIFT)) & USB_ERREN_DMAERREN_MASK)
#define USB_ERREN_OWNERREN_MASK                  (0x40U)
#define USB_ERREN_OWNERREN_SHIFT                 (6U)
#define USB_ERREN_OWNERREN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERREN_OWNERREN_SHIFT)) & USB_ERREN_OWNERREN_MASK)
#define USB_ERREN_BTSERREN_MASK                  (0x80U)
#define USB_ERREN_BTSERREN_SHIFT                 (7U)
#define USB_ERREN_BTSERREN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERREN_BTSERREN_SHIFT)) & USB_ERREN_BTSERREN_MASK)

/*! @name STAT - Status register */
#define USB_STAT_ODD_MASK                        (0x4U)
#define USB_STAT_ODD_SHIFT                       (2U)
#define USB_STAT_ODD(x)                          (((uint8_t)(((uint8_t)(x)) << USB_STAT_ODD_SHIFT)) & USB_STAT_ODD_MASK)
#define USB_STAT_TX_MASK                         (0x8U)
#define USB_STAT_TX_SHIFT                        (3U)
#define USB_STAT_TX(x)                           (((uint8_t)(((uint8_t)(x)) << USB_STAT_TX_SHIFT)) & USB_STAT_TX_MASK)
#define USB_STAT_ENDP_MASK                       (0xF0U)
#define USB_STAT_ENDP_SHIFT                      (4U)
#define USB_STAT_ENDP(x)                         (((uint8_t)(((uint8_t)(x)) << USB_STAT_ENDP_SHIFT)) & USB_STAT_ENDP_MASK)

/*! @name CTL - Control register */
#define USB_CTL_USBENSOFEN_MASK                  (0x1U)
#define USB_CTL_USBENSOFEN_SHIFT                 (0U)
#define USB_CTL_USBENSOFEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_CTL_USBENSOFEN_SHIFT)) & USB_CTL_USBENSOFEN_MASK)
#define USB_CTL_ODDRST_MASK                      (0x2U)
#define USB_CTL_ODDRST_SHIFT                     (1U)
#define USB_CTL_ODDRST(x)                        (((uint8_t)(((uint8_t)(x)) << USB_CTL_ODDRST_SHIFT)) & USB_CTL_ODDRST_MASK)
#define USB_CTL_RESUME_MASK                      (0x4U)
#define USB_CTL_RESUME_SHIFT                     (2U)
#define USB_CTL_RESUME(x)                        (((uint8_t)(((uint8_t)(x)) << USB_CTL_RESUME_SHIFT)) & USB_CTL_RESUME_MASK)
#define USB_CTL_HOSTMODEEN_MASK                  (0x8U)
#define USB_CTL_HOSTMODEEN_SHIFT                 (3U)
#define USB_CTL_HOSTMODEEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_CTL_HOSTMODEEN_SHIFT)) & USB_CTL_HOSTMODEEN_MASK)
#define USB_CTL_RESET_MASK                       (0x10U)
#define USB_CTL_RESET_SHIFT                      (4U)
#define USB_CTL_RESET(x)                         (((uint8_t)(((uint8_t)(x)) << USB_CTL_RESET_SHIFT)) & USB_CTL_RESET_MASK)
#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          (0x20U)
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         (5U)
#define USB_CTL_TXSUSPENDTOKENBUSY(x)            (((uint8_t)(((uint8_t)(x)) << USB_CTL_TXSUSPENDTOKENBUSY_SHIFT)) & USB_CTL_TXSUSPENDTOKENBUSY_MASK)
#define USB_CTL_SE0_MASK                         (0x40U)
#define USB_CTL_SE0_SHIFT                        (6U)
#define USB_CTL_SE0(x)                           (((uint8_t)(((uint8_t)(x)) << USB_CTL_SE0_SHIFT)) & USB_CTL_SE0_MASK)
#define USB_CTL_JSTATE_MASK                      (0x80U)
#define USB_CTL_JSTATE_SHIFT                     (7U)
#define USB_CTL_JSTATE(x)                        (((uint8_t)(((uint8_t)(x)) << USB_CTL_JSTATE_SHIFT)) & USB_CTL_JSTATE_MASK)

/*! @name ADDR - Address register */
#define USB_ADDR_ADDR_MASK                       (0x7FU)
#define USB_ADDR_ADDR_SHIFT                      (0U)
#define USB_ADDR_ADDR(x)                         (((uint8_t)(((uint8_t)(x)) << USB_ADDR_ADDR_SHIFT)) & USB_ADDR_ADDR_MASK)
#define USB_ADDR_LSEN_MASK                       (0x80U)
#define USB_ADDR_LSEN_SHIFT                      (7U)
#define USB_ADDR_LSEN(x)                         (((uint8_t)(((uint8_t)(x)) << USB_ADDR_LSEN_SHIFT)) & USB_ADDR_LSEN_MASK)

/*! @name BDTPAGE1 - BDT Page register 1 */
#define USB_BDTPAGE1_BDTBA_MASK                  (0xFEU)
#define USB_BDTPAGE1_BDTBA_SHIFT                 (1U)
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x)) << USB_BDTPAGE1_BDTBA_SHIFT)) & USB_BDTPAGE1_BDTBA_MASK)

/*! @name FRMNUML - Frame Number register Low */
#define USB_FRMNUML_FRM_MASK                     (0xFFU)
#define USB_FRMNUML_FRM_SHIFT                    (0U)
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x)) << USB_FRMNUML_FRM_SHIFT)) & USB_FRMNUML_FRM_MASK)

/*! @name FRMNUMH - Frame Number register High */
#define USB_FRMNUMH_FRM_MASK                     (0x7U)
#define USB_FRMNUMH_FRM_SHIFT                    (0U)
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x)) << USB_FRMNUMH_FRM_SHIFT)) & USB_FRMNUMH_FRM_MASK)

/*! @name TOKEN - Token register */
#define USB_TOKEN_TOKENENDPT_MASK                (0xFU)
#define USB_TOKEN_TOKENENDPT_SHIFT               (0U)
#define USB_TOKEN_TOKENENDPT(x)                  (((uint8_t)(((uint8_t)(x)) << USB_TOKEN_TOKENENDPT_SHIFT)) & USB_TOKEN_TOKENENDPT_MASK)
#define USB_TOKEN_TOKENPID_MASK                  (0xF0U)
#define USB_TOKEN_TOKENPID_SHIFT                 (4U)
#define USB_TOKEN_TOKENPID(x)                    (((uint8_t)(((uint8_t)(x)) << USB_TOKEN_TOKENPID_SHIFT)) & USB_TOKEN_TOKENPID_MASK)

/*! @name SOFTHLD - SOF Threshold register */
#define USB_SOFTHLD_CNT_MASK                     (0xFFU)
#define USB_SOFTHLD_CNT_SHIFT                    (0U)
#define USB_SOFTHLD_CNT(x)                       (((uint8_t)(((uint8_t)(x)) << USB_SOFTHLD_CNT_SHIFT)) & USB_SOFTHLD_CNT_MASK)

/*! @name BDTPAGE2 - BDT Page Register 2 */
#define USB_BDTPAGE2_BDTBA_MASK                  (0xFFU)
#define USB_BDTPAGE2_BDTBA_SHIFT                 (0U)
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x)) << USB_BDTPAGE2_BDTBA_SHIFT)) & USB_BDTPAGE2_BDTBA_MASK)

/*! @name BDTPAGE3 - BDT Page Register 3 */
#define USB_BDTPAGE3_BDTBA_MASK                  (0xFFU)
#define USB_BDTPAGE3_BDTBA_SHIFT                 (0U)
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x)) << USB_BDTPAGE3_BDTBA_SHIFT)) & USB_BDTPAGE3_BDTBA_MASK)

/*! @name ENDPT - Endpoint Control register */
#define USB_ENDPT_EPHSHK_MASK                    (0x1U)
#define USB_ENDPT_EPHSHK_SHIFT                   (0U)
#define USB_ENDPT_EPHSHK(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPHSHK_SHIFT)) & USB_ENDPT_EPHSHK_MASK)
#define USB_ENDPT_EPSTALL_MASK                   (0x2U)
#define USB_ENDPT_EPSTALL_SHIFT                  (1U)
#define USB_ENDPT_EPSTALL(x)                     (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPSTALL_SHIFT)) & USB_ENDPT_EPSTALL_MASK)
#define USB_ENDPT_EPTXEN_MASK                    (0x4U)
#define USB_ENDPT_EPTXEN_SHIFT                   (2U)
#define USB_ENDPT_EPTXEN(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPTXEN_SHIFT)) & USB_ENDPT_EPTXEN_MASK)
#define USB_ENDPT_EPRXEN_MASK                    (0x8U)
#define USB_ENDPT_EPRXEN_SHIFT                   (3U)
#define USB_ENDPT_EPRXEN(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPRXEN_SHIFT)) & USB_ENDPT_EPRXEN_MASK)
#define USB_ENDPT_EPCTLDIS_MASK                  (0x10U)
#define USB_ENDPT_EPCTLDIS_SHIFT                 (4U)
#define USB_ENDPT_EPCTLDIS(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPCTLDIS_SHIFT)) & USB_ENDPT_EPCTLDIS_MASK)
#define USB_ENDPT_RETRYDIS_MASK                  (0x40U)
#define USB_ENDPT_RETRYDIS_SHIFT                 (6U)
#define USB_ENDPT_RETRYDIS(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_RETRYDIS_SHIFT)) & USB_ENDPT_RETRYDIS_MASK)
#define USB_ENDPT_HOSTWOHUB_MASK                 (0x80U)
#define USB_ENDPT_HOSTWOHUB_SHIFT                (7U)
#define USB_ENDPT_HOSTWOHUB(x)                   (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_HOSTWOHUB_SHIFT)) & USB_ENDPT_HOSTWOHUB_MASK)

/* The count of USB_ENDPT */
#define USB_ENDPT_COUNT                          (16U)

/*! @name USBCTRL - USB Control register */
#define USB_USBCTRL_UARTSEL_MASK                 (0x10U)
#define USB_USBCTRL_UARTSEL_SHIFT                (4U)
#define USB_USBCTRL_UARTSEL(x)                   (((uint8_t)(((uint8_t)(x)) << USB_USBCTRL_UARTSEL_SHIFT)) & USB_USBCTRL_UARTSEL_MASK)
#define USB_USBCTRL_UARTCHLS_MASK                (0x20U)
#define USB_USBCTRL_UARTCHLS_SHIFT               (5U)
#define USB_USBCTRL_UARTCHLS(x)                  (((uint8_t)(((uint8_t)(x)) << USB_USBCTRL_UARTCHLS_SHIFT)) & USB_USBCTRL_UARTCHLS_MASK)
#define USB_USBCTRL_PDE_MASK                     (0x40U)
#define USB_USBCTRL_PDE_SHIFT                    (6U)
#define USB_USBCTRL_PDE(x)                       (((uint8_t)(((uint8_t)(x)) << USB_USBCTRL_PDE_SHIFT)) & USB_USBCTRL_PDE_MASK)
#define USB_USBCTRL_SUSP_MASK                    (0x80U)
#define USB_USBCTRL_SUSP_SHIFT                   (7U)
#define USB_USBCTRL_SUSP(x)                      (((uint8_t)(((uint8_t)(x)) << USB_USBCTRL_SUSP_SHIFT)) & USB_USBCTRL_SUSP_MASK)

/*! @name OBSERVE - USB OTG Observe register */
#define USB_OBSERVE_DMPD_MASK                    (0x10U)
#define USB_OBSERVE_DMPD_SHIFT                   (4U)
#define USB_OBSERVE_DMPD(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OBSERVE_DMPD_SHIFT)) & USB_OBSERVE_DMPD_MASK)
#define USB_OBSERVE_DPPD_MASK                    (0x40U)
#define USB_OBSERVE_DPPD_SHIFT                   (6U)
#define USB_OBSERVE_DPPD(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OBSERVE_DPPD_SHIFT)) & USB_OBSERVE_DPPD_MASK)
#define USB_OBSERVE_DPPU_MASK                    (0x80U)
#define USB_OBSERVE_DPPU_SHIFT                   (7U)
#define USB_OBSERVE_DPPU(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OBSERVE_DPPU_SHIFT)) & USB_OBSERVE_DPPU_MASK)

/*! @name CONTROL - USB OTG Control register */
#define USB_CONTROL_DPPULLUPNONOTG_MASK          (0x10U)
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         (4U)
#define USB_CONTROL_DPPULLUPNONOTG(x)            (((uint8_t)(((uint8_t)(x)) << USB_CONTROL_DPPULLUPNONOTG_SHIFT)) & USB_CONTROL_DPPULLUPNONOTG_MASK)

/*! @name USBTRC0 - USB Transceiver Control register 0 */
#define USB_USBTRC0_USB_RESUME_INT_MASK          (0x1U)
#define USB_USBTRC0_USB_RESUME_INT_SHIFT         (0U)
#define USB_USBTRC0_USB_RESUME_INT(x)            (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_USB_RESUME_INT_SHIFT)) & USB_USBTRC0_USB_RESUME_INT_MASK)
#define USB_USBTRC0_SYNC_DET_MASK                (0x2U)
#define USB_USBTRC0_SYNC_DET_SHIFT               (1U)
#define USB_USBTRC0_SYNC_DET(x)                  (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_SYNC_DET_SHIFT)) & USB_USBTRC0_SYNC_DET_MASK)
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_MASK    (0x4U)
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_SHIFT   (2U)
#define USB_USBTRC0_USB_CLK_RECOVERY_INT(x)      (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_USB_CLK_RECOVERY_INT_SHIFT)) & USB_USBTRC0_USB_CLK_RECOVERY_INT_MASK)
#define USB_USBTRC0_VREDG_DET_MASK               (0x8U)
#define USB_USBTRC0_VREDG_DET_SHIFT              (3U)
#define USB_USBTRC0_VREDG_DET(x)                 (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_VREDG_DET_SHIFT)) & USB_USBTRC0_VREDG_DET_MASK)
#define USB_USBTRC0_VFEDG_DET_MASK               (0x10U)
#define USB_USBTRC0_VFEDG_DET_SHIFT              (4U)
#define USB_USBTRC0_VFEDG_DET(x)                 (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_VFEDG_DET_SHIFT)) & USB_USBTRC0_VFEDG_DET_MASK)
#define USB_USBTRC0_USBRESMEN_MASK               (0x20U)
#define USB_USBTRC0_USBRESMEN_SHIFT              (5U)
#define USB_USBTRC0_USBRESMEN(x)                 (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_USBRESMEN_SHIFT)) & USB_USBTRC0_USBRESMEN_MASK)
#define USB_USBTRC0_USBRESET_MASK                (0x80U)
#define USB_USBTRC0_USBRESET_SHIFT               (7U)
#define USB_USBTRC0_USBRESET(x)                  (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_USBRESET_SHIFT)) & USB_USBTRC0_USBRESET_MASK)

/*! @name USBFRMADJUST - Frame Adjust Register */
#define USB_USBFRMADJUST_ADJ_MASK                (0xFFU)
#define USB_USBFRMADJUST_ADJ_SHIFT               (0U)
#define USB_USBFRMADJUST_ADJ(x)                  (((uint8_t)(((uint8_t)(x)) << USB_USBFRMADJUST_ADJ_SHIFT)) & USB_USBFRMADJUST_ADJ_MASK)

/*! @name MISCCTRL - Miscellaneous Control register */
#define USB_MISCCTRL_SOFDYNTHLD_MASK             (0x1U)
#define USB_MISCCTRL_SOFDYNTHLD_SHIFT            (0U)
#define USB_MISCCTRL_SOFDYNTHLD(x)               (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_SOFDYNTHLD_SHIFT)) & USB_MISCCTRL_SOFDYNTHLD_MASK)
#define USB_MISCCTRL_SOFBUSSET_MASK              (0x2U)
#define USB_MISCCTRL_SOFBUSSET_SHIFT             (1U)
#define USB_MISCCTRL_SOFBUSSET(x)                (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_SOFBUSSET_SHIFT)) & USB_MISCCTRL_SOFBUSSET_MASK)
#define USB_MISCCTRL_OWNERRISODIS_MASK           (0x4U)
#define USB_MISCCTRL_OWNERRISODIS_SHIFT          (2U)
#define USB_MISCCTRL_OWNERRISODIS(x)             (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_OWNERRISODIS_SHIFT)) & USB_MISCCTRL_OWNERRISODIS_MASK)
#define USB_MISCCTRL_VREDG_EN_MASK               (0x8U)
#define USB_MISCCTRL_VREDG_EN_SHIFT              (3U)
#define USB_MISCCTRL_VREDG_EN(x)                 (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_VREDG_EN_SHIFT)) & USB_MISCCTRL_VREDG_EN_MASK)
#define USB_MISCCTRL_VFEDG_EN_MASK               (0x10U)
#define USB_MISCCTRL_VFEDG_EN_SHIFT              (4U)
#define USB_MISCCTRL_VFEDG_EN(x)                 (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_VFEDG_EN_SHIFT)) & USB_MISCCTRL_VFEDG_EN_MASK)
#define USB_MISCCTRL_STL_ADJ_EN_MASK             (0x80U)
#define USB_MISCCTRL_STL_ADJ_EN_SHIFT            (7U)
#define USB_MISCCTRL_STL_ADJ_EN(x)               (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_STL_ADJ_EN_SHIFT)) & USB_MISCCTRL_STL_ADJ_EN_MASK)

/*! @name STALL_IL_DIS - Peripheral mode stall disable for endpoints 7 to 0 in IN direction */
#define USB_STALL_IL_DIS_STALL_I_DIS0_MASK       (0x1U)
#define USB_STALL_IL_DIS_STALL_I_DIS0_SHIFT      (0U)
#define USB_STALL_IL_DIS_STALL_I_DIS0(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS0_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS0_MASK)
#define USB_STALL_IL_DIS_STALL_I_DIS1_MASK       (0x2U)
#define USB_STALL_IL_DIS_STALL_I_DIS1_SHIFT      (1U)
#define USB_STALL_IL_DIS_STALL_I_DIS1(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS1_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS1_MASK)
#define USB_STALL_IL_DIS_STALL_I_DIS2_MASK       (0x4U)
#define USB_STALL_IL_DIS_STALL_I_DIS2_SHIFT      (2U)
#define USB_STALL_IL_DIS_STALL_I_DIS2(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS2_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS2_MASK)
#define USB_STALL_IL_DIS_STALL_I_DIS3_MASK       (0x8U)
#define USB_STALL_IL_DIS_STALL_I_DIS3_SHIFT      (3U)
#define USB_STALL_IL_DIS_STALL_I_DIS3(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS3_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS3_MASK)
#define USB_STALL_IL_DIS_STALL_I_DIS4_MASK       (0x10U)
#define USB_STALL_IL_DIS_STALL_I_DIS4_SHIFT      (4U)
#define USB_STALL_IL_DIS_STALL_I_DIS4(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS4_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS4_MASK)
#define USB_STALL_IL_DIS_STALL_I_DIS5_MASK       (0x20U)
#define USB_STALL_IL_DIS_STALL_I_DIS5_SHIFT      (5U)
#define USB_STALL_IL_DIS_STALL_I_DIS5(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS5_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS5_MASK)
#define USB_STALL_IL_DIS_STALL_I_DIS6_MASK       (0x40U)
#define USB_STALL_IL_DIS_STALL_I_DIS6_SHIFT      (6U)
#define USB_STALL_IL_DIS_STALL_I_DIS6(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS6_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS6_MASK)
#define USB_STALL_IL_DIS_STALL_I_DIS7_MASK       (0x80U)
#define USB_STALL_IL_DIS_STALL_I_DIS7_SHIFT      (7U)
#define USB_STALL_IL_DIS_STALL_I_DIS7(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS7_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS7_MASK)

/*! @name STALL_IH_DIS - Peripheral mode stall disable for endpoints 15 to 8 in IN direction */
#define USB_STALL_IH_DIS_STALL_I_DIS8_MASK       (0x1U)
#define USB_STALL_IH_DIS_STALL_I_DIS8_SHIFT      (0U)
#define USB_STALL_IH_DIS_STALL_I_DIS8(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS8_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS8_MASK)
#define USB_STALL_IH_DIS_STALL_I_DIS9_MASK       (0x2U)
#define USB_STALL_IH_DIS_STALL_I_DIS9_SHIFT      (1U)
#define USB_STALL_IH_DIS_STALL_I_DIS9(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS9_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS9_MASK)
#define USB_STALL_IH_DIS_STALL_I_DIS10_MASK      (0x4U)
#define USB_STALL_IH_DIS_STALL_I_DIS10_SHIFT     (2U)
#define USB_STALL_IH_DIS_STALL_I_DIS10(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS10_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS10_MASK)
#define USB_STALL_IH_DIS_STALL_I_DIS11_MASK      (0x8U)
#define USB_STALL_IH_DIS_STALL_I_DIS11_SHIFT     (3U)
#define USB_STALL_IH_DIS_STALL_I_DIS11(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS11_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS11_MASK)
#define USB_STALL_IH_DIS_STALL_I_DIS12_MASK      (0x10U)
#define USB_STALL_IH_DIS_STALL_I_DIS12_SHIFT     (4U)
#define USB_STALL_IH_DIS_STALL_I_DIS12(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS12_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS12_MASK)
#define USB_STALL_IH_DIS_STALL_I_DIS13_MASK      (0x20U)
#define USB_STALL_IH_DIS_STALL_I_DIS13_SHIFT     (5U)
#define USB_STALL_IH_DIS_STALL_I_DIS13(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS13_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS13_MASK)
#define USB_STALL_IH_DIS_STALL_I_DIS14_MASK      (0x40U)
#define USB_STALL_IH_DIS_STALL_I_DIS14_SHIFT     (6U)
#define USB_STALL_IH_DIS_STALL_I_DIS14(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS14_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS14_MASK)
#define USB_STALL_IH_DIS_STALL_I_DIS15_MASK      (0x80U)
#define USB_STALL_IH_DIS_STALL_I_DIS15_SHIFT     (7U)
#define USB_STALL_IH_DIS_STALL_I_DIS15(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS15_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS15_MASK)

/*! @name STALL_OL_DIS - Peripheral mode stall disable for endpoints 7 to 0 in OUT direction */
#define USB_STALL_OL_DIS_STALL_O_DIS0_MASK       (0x1U)
#define USB_STALL_OL_DIS_STALL_O_DIS0_SHIFT      (0U)
#define USB_STALL_OL_DIS_STALL_O_DIS0(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS0_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS0_MASK)
#define USB_STALL_OL_DIS_STALL_O_DIS1_MASK       (0x2U)
#define USB_STALL_OL_DIS_STALL_O_DIS1_SHIFT      (1U)
#define USB_STALL_OL_DIS_STALL_O_DIS1(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS1_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS1_MASK)
#define USB_STALL_OL_DIS_STALL_O_DIS2_MASK       (0x4U)
#define USB_STALL_OL_DIS_STALL_O_DIS2_SHIFT      (2U)
#define USB_STALL_OL_DIS_STALL_O_DIS2(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS2_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS2_MASK)
#define USB_STALL_OL_DIS_STALL_O_DIS3_MASK       (0x8U)
#define USB_STALL_OL_DIS_STALL_O_DIS3_SHIFT      (3U)
#define USB_STALL_OL_DIS_STALL_O_DIS3(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS3_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS3_MASK)
#define USB_STALL_OL_DIS_STALL_O_DIS4_MASK       (0x10U)
#define USB_STALL_OL_DIS_STALL_O_DIS4_SHIFT      (4U)
#define USB_STALL_OL_DIS_STALL_O_DIS4(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS4_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS4_MASK)
#define USB_STALL_OL_DIS_STALL_O_DIS5_MASK       (0x20U)
#define USB_STALL_OL_DIS_STALL_O_DIS5_SHIFT      (5U)
#define USB_STALL_OL_DIS_STALL_O_DIS5(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS5_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS5_MASK)
#define USB_STALL_OL_DIS_STALL_O_DIS6_MASK       (0x40U)
#define USB_STALL_OL_DIS_STALL_O_DIS6_SHIFT      (6U)
#define USB_STALL_OL_DIS_STALL_O_DIS6(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS6_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS6_MASK)
#define USB_STALL_OL_DIS_STALL_O_DIS7_MASK       (0x80U)
#define USB_STALL_OL_DIS_STALL_O_DIS7_SHIFT      (7U)
#define USB_STALL_OL_DIS_STALL_O_DIS7(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS7_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS7_MASK)

/*! @name STALL_OH_DIS - Peripheral mode stall disable for endpoints 15 to 8 in OUT direction */
#define USB_STALL_OH_DIS_STALL_O_DIS8_MASK       (0x1U)
#define USB_STALL_OH_DIS_STALL_O_DIS8_SHIFT      (0U)
#define USB_STALL_OH_DIS_STALL_O_DIS8(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS8_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS8_MASK)
#define USB_STALL_OH_DIS_STALL_O_DIS9_MASK       (0x2U)
#define USB_STALL_OH_DIS_STALL_O_DIS9_SHIFT      (1U)
#define USB_STALL_OH_DIS_STALL_O_DIS9(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS9_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS9_MASK)
#define USB_STALL_OH_DIS_STALL_O_DIS10_MASK      (0x4U)
#define USB_STALL_OH_DIS_STALL_O_DIS10_SHIFT     (2U)
#define USB_STALL_OH_DIS_STALL_O_DIS10(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS10_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS10_MASK)
#define USB_STALL_OH_DIS_STALL_O_DIS11_MASK      (0x8U)
#define USB_STALL_OH_DIS_STALL_O_DIS11_SHIFT     (3U)
#define USB_STALL_OH_DIS_STALL_O_DIS11(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS11_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS11_MASK)
#define USB_STALL_OH_DIS_STALL_O_DIS12_MASK      (0x10U)
#define USB_STALL_OH_DIS_STALL_O_DIS12_SHIFT     (4U)
#define USB_STALL_OH_DIS_STALL_O_DIS12(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS12_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS12_MASK)
#define USB_STALL_OH_DIS_STALL_O_DIS13_MASK      (0x20U)
#define USB_STALL_OH_DIS_STALL_O_DIS13_SHIFT     (5U)
#define USB_STALL_OH_DIS_STALL_O_DIS13(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS13_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS13_MASK)
#define USB_STALL_OH_DIS_STALL_O_DIS14_MASK      (0x40U)
#define USB_STALL_OH_DIS_STALL_O_DIS14_SHIFT     (6U)
#define USB_STALL_OH_DIS_STALL_O_DIS14(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS14_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS14_MASK)
#define USB_STALL_OH_DIS_STALL_O_DIS15_MASK      (0x80U)
#define USB_STALL_OH_DIS_STALL_O_DIS15_SHIFT     (7U)
#define USB_STALL_OH_DIS_STALL_O_DIS15(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS15_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS15_MASK)

/*! @name CLK_RECOVER_CTRL - USB Clock recovery control */
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK (0x20U)
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT (5U)
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN(x) (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT)) & USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK)
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK (0x40U)
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT (6U)
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN(x) (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT)) & USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK)
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK (0x80U)
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT (7U)
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN(x) (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT)) & USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK)

/*! @name CLK_RECOVER_IRC_EN - IRC48M oscillator enable register */
#define USB_CLK_RECOVER_IRC_EN_REG_EN_MASK       (0x1U)
#define USB_CLK_RECOVER_IRC_EN_REG_EN_SHIFT      (0U)
#define USB_CLK_RECOVER_IRC_EN_REG_EN(x)         (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_IRC_EN_REG_EN_SHIFT)) & USB_CLK_RECOVER_IRC_EN_REG_EN_MASK)
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK       (0x2U)
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT      (1U)
#define USB_CLK_RECOVER_IRC_EN_IRC_EN(x)         (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT)) & USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK)

/*! @name CLK_RECOVER_INT_EN - Clock recovery combined interrupt enable */
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK (0x10U)
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT (4U)
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN(x)   (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT)) & USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK)

/*! @name CLK_RECOVER_INT_STATUS - Clock recovery separated interrupt status */
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK (0x10U)
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT (4U)
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR(x)  (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT)) & USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK)


/*!
 * @}
 */ /* end of group USB_Register_Masks */


/* USB - Peripheral instance base addresses */
/** Peripheral USB0 base address */
#define USB0_BASE                                (0x40072000u)
/** Peripheral USB0 base pointer */
#define USB0                                     ((USB_Type *)USB0_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB0_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB0 }
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { USB0_IRQn }

/*!
 * @}
 */ /* end of group USB_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */

/** WDOG - Register Layout Typedef */
typedef struct {
  __IO uint16_t STCTRLH;                           /**< Watchdog Status and Control Register High, offset: 0x0 */
  __IO uint16_t STCTRLL;                           /**< Watchdog Status and Control Register Low, offset: 0x2 */
  __IO uint16_t TOVALH;                            /**< Watchdog Time-out Value Register High, offset: 0x4 */
  __IO uint16_t TOVALL;                            /**< Watchdog Time-out Value Register Low, offset: 0x6 */
  __IO uint16_t WINH;                              /**< Watchdog Window Register High, offset: 0x8 */
  __IO uint16_t WINL;                              /**< Watchdog Window Register Low, offset: 0xA */
  __IO uint16_t REFRESH;                           /**< Watchdog Refresh register, offset: 0xC */
  __IO uint16_t UNLOCK;                            /**< Watchdog Unlock register, offset: 0xE */
  __IO uint16_t TMROUTH;                           /**< Watchdog Timer Output Register High, offset: 0x10 */
  __IO uint16_t TMROUTL;                           /**< Watchdog Timer Output Register Low, offset: 0x12 */
  __IO uint16_t RSTCNT;                            /**< Watchdog Reset Count register, offset: 0x14 */
  __IO uint16_t PRESC;                             /**< Watchdog Prescaler register, offset: 0x16 */
} WDOG_Type;

/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/*! @name STCTRLH - Watchdog Status and Control Register High */
#define WDOG_STCTRLH_WDOGEN_MASK                 (0x1U)
#define WDOG_STCTRLH_WDOGEN_SHIFT                (0U)
#define WDOG_STCTRLH_WDOGEN(x)                   (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_WDOGEN_SHIFT)) & WDOG_STCTRLH_WDOGEN_MASK)
#define WDOG_STCTRLH_CLKSRC_MASK                 (0x2U)
#define WDOG_STCTRLH_CLKSRC_SHIFT                (1U)
#define WDOG_STCTRLH_CLKSRC(x)                   (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_CLKSRC_SHIFT)) & WDOG_STCTRLH_CLKSRC_MASK)
#define WDOG_STCTRLH_IRQRSTEN_MASK               (0x4U)
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              (2U)
#define WDOG_STCTRLH_IRQRSTEN(x)                 (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_IRQRSTEN_SHIFT)) & WDOG_STCTRLH_IRQRSTEN_MASK)
#define WDOG_STCTRLH_WINEN_MASK                  (0x8U)
#define WDOG_STCTRLH_WINEN_SHIFT                 (3U)
#define WDOG_STCTRLH_WINEN(x)                    (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_WINEN_SHIFT)) & WDOG_STCTRLH_WINEN_MASK)
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            (0x10U)
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           (4U)
#define WDOG_STCTRLH_ALLOWUPDATE(x)              (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_ALLOWUPDATE_SHIFT)) & WDOG_STCTRLH_ALLOWUPDATE_MASK)
#define WDOG_STCTRLH_DBGEN_MASK                  (0x20U)
#define WDOG_STCTRLH_DBGEN_SHIFT                 (5U)
#define WDOG_STCTRLH_DBGEN(x)                    (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_DBGEN_SHIFT)) & WDOG_STCTRLH_DBGEN_MASK)
#define WDOG_STCTRLH_STOPEN_MASK                 (0x40U)
#define WDOG_STCTRLH_STOPEN_SHIFT                (6U)
#define WDOG_STCTRLH_STOPEN(x)                   (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_STOPEN_SHIFT)) & WDOG_STCTRLH_STOPEN_MASK)
#define WDOG_STCTRLH_WAITEN_MASK                 (0x80U)
#define WDOG_STCTRLH_WAITEN_SHIFT                (7U)
#define WDOG_STCTRLH_WAITEN(x)                   (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_WAITEN_SHIFT)) & WDOG_STCTRLH_WAITEN_MASK)
#define WDOG_STCTRLH_TESTWDOG_MASK               (0x400U)
#define WDOG_STCTRLH_TESTWDOG_SHIFT              (10U)
#define WDOG_STCTRLH_TESTWDOG(x)                 (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_TESTWDOG_SHIFT)) & WDOG_STCTRLH_TESTWDOG_MASK)
#define WDOG_STCTRLH_TESTSEL_MASK                (0x800U)
#define WDOG_STCTRLH_TESTSEL_SHIFT               (11U)
#define WDOG_STCTRLH_TESTSEL(x)                  (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_TESTSEL_SHIFT)) & WDOG_STCTRLH_TESTSEL_MASK)
#define WDOG_STCTRLH_BYTESEL_MASK                (0x3000U)
#define WDOG_STCTRLH_BYTESEL_SHIFT               (12U)
#define WDOG_STCTRLH_BYTESEL(x)                  (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_BYTESEL_SHIFT)) & WDOG_STCTRLH_BYTESEL_MASK)
#define WDOG_STCTRLH_DISTESTWDOG_MASK            (0x4000U)
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           (14U)
#define WDOG_STCTRLH_DISTESTWDOG(x)              (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLH_DISTESTWDOG_SHIFT)) & WDOG_STCTRLH_DISTESTWDOG_MASK)

/*! @name STCTRLL - Watchdog Status and Control Register Low */
#define WDOG_STCTRLL_INTFLG_MASK                 (0x8000U)
#define WDOG_STCTRLL_INTFLG_SHIFT                (15U)
#define WDOG_STCTRLL_INTFLG(x)                   (((uint16_t)(((uint16_t)(x)) << WDOG_STCTRLL_INTFLG_SHIFT)) & WDOG_STCTRLL_INTFLG_MASK)

/*! @name TOVALH - Watchdog Time-out Value Register High */
#define WDOG_TOVALH_TOVALHIGH_MASK               (0xFFFFU)
#define WDOG_TOVALH_TOVALHIGH_SHIFT              (0U)
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint16_t)(((uint16_t)(x)) << WDOG_TOVALH_TOVALHIGH_SHIFT)) & WDOG_TOVALH_TOVALHIGH_MASK)

/*! @name TOVALL - Watchdog Time-out Value Register Low */
#define WDOG_TOVALL_TOVALLOW_MASK                (0xFFFFU)
#define WDOG_TOVALL_TOVALLOW_SHIFT               (0U)
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint16_t)(((uint16_t)(x)) << WDOG_TOVALL_TOVALLOW_SHIFT)) & WDOG_TOVALL_TOVALLOW_MASK)

/*! @name WINH - Watchdog Window Register High */
#define WDOG_WINH_WINHIGH_MASK                   (0xFFFFU)
#define WDOG_WINH_WINHIGH_SHIFT                  (0U)
#define WDOG_WINH_WINHIGH(x)                     (((uint16_t)(((uint16_t)(x)) << WDOG_WINH_WINHIGH_SHIFT)) & WDOG_WINH_WINHIGH_MASK)

/*! @name WINL - Watchdog Window Register Low */
#define WDOG_WINL_WINLOW_MASK                    (0xFFFFU)
#define WDOG_WINL_WINLOW_SHIFT                   (0U)
#define WDOG_WINL_WINLOW(x)                      (((uint16_t)(((uint16_t)(x)) << WDOG_WINL_WINLOW_SHIFT)) & WDOG_WINL_WINLOW_MASK)

/*! @name REFRESH - Watchdog Refresh register */
#define WDOG_REFRESH_WDOGREFRESH_MASK            (0xFFFFU)
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           (0U)
#define WDOG_REFRESH_WDOGREFRESH(x)              (((uint16_t)(((uint16_t)(x)) << WDOG_REFRESH_WDOGREFRESH_SHIFT)) & WDOG_REFRESH_WDOGREFRESH_MASK)

/*! @name UNLOCK - Watchdog Unlock register */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              (0xFFFFU)
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             (0U)
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((uint16_t)(((uint16_t)(x)) << WDOG_UNLOCK_WDOGUNLOCK_SHIFT)) & WDOG_UNLOCK_WDOGUNLOCK_MASK)

/*! @name TMROUTH - Watchdog Timer Output Register High */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           (0xFFFFU)
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          (0U)
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((uint16_t)(((uint16_t)(x)) << WDOG_TMROUTH_TIMEROUTHIGH_SHIFT)) & WDOG_TMROUTH_TIMEROUTHIGH_MASK)

/*! @name TMROUTL - Watchdog Timer Output Register Low */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            (0xFFFFU)
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           (0U)
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((uint16_t)(((uint16_t)(x)) << WDOG_TMROUTL_TIMEROUTLOW_SHIFT)) & WDOG_TMROUTL_TIMEROUTLOW_MASK)

/*! @name RSTCNT - Watchdog Reset Count register */
#define WDOG_RSTCNT_RSTCNT_MASK                  (0xFFFFU)
#define WDOG_RSTCNT_RSTCNT_SHIFT                 (0U)
#define WDOG_RSTCNT_RSTCNT(x)                    (((uint16_t)(((uint16_t)(x)) << WDOG_RSTCNT_RSTCNT_SHIFT)) & WDOG_RSTCNT_RSTCNT_MASK)

/*! @name PRESC - Watchdog Prescaler register */
#define WDOG_PRESC_PRESCVAL_MASK                 (0x700U)
#define WDOG_PRESC_PRESCVAL_SHIFT                (8U)
#define WDOG_PRESC_PRESCVAL(x)                   (((uint16_t)(((uint16_t)(x)) << WDOG_PRESC_PRESCVAL_SHIFT)) & WDOG_PRESC_PRESCVAL_MASK)


/*!
 * @}
 */ /* end of group WDOG_Register_Masks */


/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base address */
#define WDOG_BASE                                (0x40052000u)
/** Peripheral WDOG base pointer */
#define WDOG                                     ((WDOG_Type *)WDOG_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG }
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { WDOG_EWM_IRQn }

/*!
 * @}
 */ /* end of group WDOG_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


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

#define  MCG_C2_EREFS0_MASK          MCG_C2_EREFS_MASK
#define  MCG_C2_EREFS0_SHIFT         MCG_C2_EREFS_SHIFT
#define  MCG_C2_HGO0_MASK            MCG_C2_HGO_MASK
#define  MCG_C2_HGO0_SHIFT           MCG_C2_HGO_SHIFT
#define  MCG_C2_RANGE0_MASK          MCG_C2_RANGE_MASK
#define  MCG_C2_RANGE0_SHIFT         MCG_C2_RANGE_SHIFT
#define  MCG_C2_RANGE0(x)            MCG_C2_RANGE(x)
#define  DSPI0                       SPI0
#define  DSPI1                       SPI1
#define  FLEXCAN0                    CAN0
#define  FLEXCAN1                    CAN1
#define  PTA_BASE                    GPIOA_BASE
#define  PTA                         GPIOA
#define  PTB_BASE                    GPIOB_BASE
#define  PTB                         GPIOB
#define  PTC_BASE                    GPIOC_BASE
#define  PTC                         GPIOC
#define  PTD_BASE                    GPIOD_BASE
#define  PTD                         GPIOD
#define  PTE_BASE                    GPIOE_BASE
#define  PTE                         GPIOE
#define  DMAMUX0                     DMAMUX
#define  USB_ADDINFO_IRQNUM_MASK     This_symbol_has_been_deprecated
#define  USB_ADDINFO_IRQNUM_SHIFT    This_symbol_has_been_deprecated
#define  USB_ADDINFO_IRQNUM(x)       This_symbol_has_been_deprecated
#define  Watchdog_IRQn               WDOG_EWM_IRQn
#define  Watchdog_IRQHandler         WDOG_EWM_IRQHandler
#define  LPTimer_IRQn                LPTMR0_IRQn
#define  LPTimer_IRQHandler          LPTMR0_IRQHandler
#define  LLW_IRQn                    LLWU_IRQn
#define  LLW_IRQHandler              LLWU_IRQHandler

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* _MKS22F12_H_ */

