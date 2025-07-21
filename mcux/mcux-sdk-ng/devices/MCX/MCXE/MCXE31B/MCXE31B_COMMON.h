/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXE31 RM Rev1
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250527
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCXE31B
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MCXE31B_COMMON.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for MCXE31B
 *
 * CMSIS Peripheral Access Layer for MCXE31B
 */

#if !defined(MCXE31B_COMMON_H_)
#define MCXE31B_COMMON_H_                        /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0000U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0001U


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 240                /**< Number of interrupts in the Vector table */

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
  INT0_IRQn                    = 0,                /**< CPU to CPU int0 */
  INT1_IRQn                    = 1,                /**< CPU to CPU int1 */
  INT2_IRQn                    = 2,                /**< CPU to CPU int2 */
  INT3_IRQn                    = 3,                /**< CPU to CPU int3 */
  DMATCD0_IRQn                 = 4,                /**< DMA transfer complete and error CH0 */
  DMATCD1_IRQn                 = 5,                /**< DMA transfer complete and error CH1 */
  DMATCD2_IRQn                 = 6,                /**< DMA transfer complete and error CH2 */
  DMATCD3_IRQn                 = 7,                /**< DMA transfer complete and error CH3 */
  DMATCD4_IRQn                 = 8,                /**< DMA transfer complete and error CH4 */
  DMATCD5_IRQn                 = 9,                /**< DMA transfer complete and error CH5 */
  DMATCD6_IRQn                 = 10,               /**< DMA transfer complete and error CH6 */
  DMATCD7_IRQn                 = 11,               /**< DMA transfer complete and error CH7 */
  DMATCD8_IRQn                 = 12,               /**< DMA transfer complete and error CH8 */
  DMATCD9_IRQn                 = 13,               /**< DMA transfer complete and error CH9 */
  DMATCD10_IRQn                = 14,               /**< DMA transfer complete and error CH10 */
  DMATCD11_IRQn                = 15,               /**< DMA transfer complete and error CH11 */
  DMATCD12_IRQn                = 16,               /**< DMA transfer complete and error CH12 */
  DMATCD13_IRQn                = 17,               /**< DMA transfer complete and error CH13 */
  DMATCD14_IRQn                = 18,               /**< DMA transfer complete and error CH14 */
  DMATCD15_IRQn                = 19,               /**< DMA transfer complete and error CH15 */
  DMATCD16_IRQn                = 20,               /**< DMA transfer complete and error CH16 */
  DMATCD17_IRQn                = 21,               /**< DMA transfer complete and error CH17 */
  DMATCD18_IRQn                = 22,               /**< DMA transfer complete and error CH18 */
  DMATCD19_IRQn                = 23,               /**< DMA transfer complete and error CH19 */
  DMATCD20_IRQn                = 24,               /**< DMA transfer complete and error CH20 */
  DMATCD21_IRQn                = 25,               /**< DMA transfer complete and error CH21 */
  DMATCD22_IRQn                = 26,               /**< DMA transfer complete and error CH22 */
  DMATCD23_IRQn                = 27,               /**< DMA transfer complete and error CH23 */
  DMATCD24_IRQn                = 28,               /**< DMA transfer complete and error CH24 */
  DMATCD25_IRQn                = 29,               /**< DMA transfer complete and error CH25 */
  DMATCD26_IRQn                = 30,               /**< DMA transfer complete and error CH26 */
  DMATCD27_IRQn                = 31,               /**< DMA transfer complete and error CH27 */
  DMATCD28_IRQn                = 32,               /**< DMA transfer complete and error CH28 */
  DMATCD29_IRQn                = 33,               /**< DMA transfer complete and error CH29 */
  DMATCD30_IRQn                = 34,               /**< DMA transfer complete and error CH30 */
  DMATCD31_IRQn                = 35,               /**< DMA transfer complete and error CH31 */
  ERM_0_IRQn                   = 36,               /**< Single bit ECC error */
  ERM_1_IRQn                   = 37,               /**< Multi bit ECC error */
  MCM_IRQn                     = 38,               /**< FPU ORed sources ORed with MCM Write Abort interrupt */
  STM0_IRQn                    = 39,               /**< Single interrupt vector for all four channels */
  STM1_IRQn                    = 40,               /**< Single interrupt vector for all four channels */
  Reserved57_IRQn              = 41,               /**< Reserved interrupt */
  SWT0_IRQn                    = 42,               /**< Platform watchdog initial time-out */
  Reserved59_IRQn              = 43,               /**< Reserved interrupt */
  Reserved60_IRQn              = 44,               /**< Reserved interrupt */
  Reserved61_IRQn              = 45,               /**< Reserved interrupt */
  Reserved62_IRQn              = 46,               /**< Reserved interrupt */
  Reserved63_IRQn              = 47,               /**< Reserved interrupt */
  FLASH_0_IRQn                 = 48,               /**< Program or erase operation is completed */
  FLASH_1_IRQn                 = 49,               /**< Main watchdog timeout interrupt */
  FLASH_2_IRQn                 = 50,               /**< Alternate watchdog timeout interrupt */
  RGM_IRQn                     = 51,               /**< Interrupt request to the system */
  PMC_IRQn                     = 52,               /**< One interrupt for all LVDs, One interrupt for all HVDs */
  SIUL2_0_IRQn                 = 53,               /**< External Interrupt Vector 0 */
  SIUL2_1_IRQn                 = 54,               /**< External Interrupt Vector 1 */
  SIUL2_2_IRQn                 = 55,               /**< External Interrupt Vector 2 */
  SIUL2_3_IRQn                 = 56,               /**< External Interrupt Vector 3 */
  EMIOS0_2_IRQn                = 61,               /**< Interrupt request 23, 22, 21, 20 */
  EMIOS0_3_IRQn                = 62,               /**< Interrupt request 19, 18, 17, 16 */
  EMIOS0_4_IRQn                = 63,               /**< Interrupt request 15, 14, 13, 12 */
  EMIOS0_5_IRQn                = 64,               /**< Interrupt request 11, 10, 9, 8 */
  EMIOS0_6_IRQn                = 65,               /**< Interrupt request 7, 6, 5, 4 */
  EMIOS0_7_IRQn                = 66,               /**< Interrupt request 3, 2, 1, 0 */
  Reserved83_IRQn              = 67,               /**< Reserved interrupt */
  Reserved84_IRQn              = 68,               /**< Reserved interrupt */
  EMIOS1_2_IRQn                = 69,               /**< Interrupt request 23, 22, 21, 20 */
  EMIOS1_3_IRQn                = 70,               /**< Interrupt request 19, 18, 17, 16 */
  EMIOS1_4_IRQn                = 71,               /**< Interrupt request 15, 14, 13, 12 */
  EMIOS1_5_IRQn                = 72,               /**< Interrupt request 11, 10, 9, 8 */
  EMIOS1_6_IRQn                = 73,               /**< Interrupt request 7, 6, 5, 4 */
  EMIOS1_7_IRQn                = 74,               /**< Interrupt request 3, 2, 1, 0 */
  Reserved91_IRQn              = 75,               /**< Reserved interrupt */
  Reserved92_IRQn              = 76,               /**< Reserved interrupt */
  EMIOS2_2_IRQn                = 77,               /**< Interrupt request 23, 22, 21, 20 */
  EMIOS2_3_IRQn                = 78,               /**< Interrupt request 19, 18, 17, 16 */
  EMIOS2_4_IRQn                = 79,               /**< Interrupt request 15, 14, 13, 12 */
  EMIOS2_5_IRQn                = 80,               /**< Interrupt request 11, 10, 9, 8 */
  EMIOS2_6_IRQn                = 81,               /**< Interrupt request 7, 6, 5, 4 */
  EMIOS2_7_IRQn                = 82,               /**< Interrupt request 3, 2, 1, 0 */
  WKPU_IRQn                    = 83,               /**< Interrupts from pad group 0, 1, 2, 3, 0_64, 1_64, 2_64, 3_64 */
  CMU0_IRQn                    = 84,               /**< CMU0 interrupt */
  CMU1_IRQn                    = 85,               /**< CMU1 interrupt */
  CMU2_IRQn                    = 86,               /**< CMU2 interrupt */
  BCTU_IRQn                    = 87,               /**< Ored interrupt for BCTU */
  Reserved104_IRQn             = 88,               /**< Reserved interrupt */
  Reserved105_IRQn             = 89,               /**< Reserved interrupt */
  Reserved106_IRQn             = 90,               /**< Reserved interrupt */
  Reserved107_IRQn             = 91,               /**< Reserved interrupt */
  LCU0_IRQn                    = 92,               /**< Interrupt_0, 1, 2 */
  LCU1_IRQn                    = 93,               /**< Interrupt_0, 1, 2 */
  Reserved110_IRQn             = 94,               /**< Reserved interrupt */
  Reserved111_IRQn             = 95,               /**< Reserved interrupt */
  PIT0_IRQn                    = 96,               /**< Interrupt for Channel0, Channel1, Channel2, Channel3, Channel4 */
  PIT1_IRQn                    = 97,               /**< Interrupt for Channel0, Channel1, Channel2, Channel3 */
  PIT2_IRQn                    = 98,               /**< Interrupt for Channel0, Channel1, Channel2, Channel3 */
  Reserved115_IRQn             = 99,               /**< Reserved interrupt */
  Reserved116_IRQn             = 100,              /**< Reserved interrupt */
  Reserved117_IRQn             = 101,              /**< Reserved interrupt */
  RTC_IRQn                     = 102,              /**< RTCF or ROVRF interrupt to be serviced by the system controller */
  Reserved119_IRQn             = 103,              /**< Reserved interrupt */
  Reserved120_IRQn             = 104,              /**< Reserved interrupt */
  EMAC_0_IRQn                  = 105,              /**< Common interrupt */
  EMAC_1_IRQn                  = 106,              /**< Tx interrupt 0 and 1 */
  EMAC_2_IRQn                  = 107,              /**< rx interrupt 0 */
  EMAC_3_IRQn                  = 108,              /**< safety interrupt correctable */
  FlexCAN0_0_IRQn              = 109,              /**< Ored status and error */
  FlexCAN0_1_IRQn              = 110,              /**< Message Buffer Interrupt line 0-31 */
  FlexCAN0_2_IRQn              = 111,              /**< Message Buffer Interrupt line 32-63 */
  FlexCAN0_3_IRQn              = 112,              /**< Message Buffer Interrupt line 64-95 */
  FlexCAN1_0_IRQn              = 113,              /**< Ored status and error */
  FlexCAN1_1_IRQn              = 114,              /**< Message Buffer Interrupt line 0-31 */
  FlexCAN1_2_IRQn              = 115,              /**< Message Buffer Interrupt line 32-63 */
  FlexCAN2_0_IRQn              = 116,              /**< Ored status and error */
  FlexCAN2_1_IRQn              = 117,              /**< Message Buffer Interrupt line 0-31 */
  FlexCAN2_2_IRQn              = 118,              /**< Message Buffer Interrupt line 32-63 */
  FlexCAN3_0_IRQn              = 119,              /**< Ored status and error */
  FlexCAN3_1_IRQn              = 120,              /**< Message Buffer Interrupt line 0-31 */
  FlexCAN4_0_IRQn              = 121,              /**< Ored status and error */
  FlexCAN4_1_IRQn              = 122,              /**< Message Buffer Interrupt line 0-31 */
  FlexCAN5_0_IRQn              = 123,              /**< Ored status and error */
  FlexCAN5_1_IRQn              = 124,              /**< Message Buffer Interrupt line 0-31 */
  FLEXIO_IRQn                  = 139,              /**< FlexIO Interrupt */
  LPUART_0_IRQn                = 141,              /**< TX and RX interrupt */
  LPUART_1_IRQn                = 142,              /**< TX and RX interrupt */
  LPUART_2_IRQn                = 143,              /**< TX and RX interrupt */
  LPUART_3_IRQn                = 144,              /**< TX and RX interrupt */
  LPUART_4_IRQn                = 145,              /**< TX and RX interrupt */
  LPUART_5_IRQn                = 146,              /**< TX and RX interrupt */
  LPUART_6_IRQn                = 147,              /**< TX and RX interrupt */
  LPUART_7_IRQn                = 148,              /**< TX and RX interrupt */
  LPUART_8_IRQn                = 149,              /**< TX and RX interrupt */
  LPUART_9_IRQn                = 150,              /**< TX and RX interrupt */
  LPUART_10_IRQn               = 151,              /**< TX and RX interrupt */
  LPUART_11_IRQn               = 152,              /**< TX and RX interrupt */
  LPUART_12_IRQn               = 153,              /**< TX and RX interrupt */
  LPUART_13_IRQn               = 154,              /**< TX and RX interrupt */
  LPUART_14_IRQn               = 155,              /**< TX and RX interrupt */
  LPUART_15_IRQn               = 156,              /**< TX and RX interrupt */
  Reserved173_IRQn             = 157,              /**< Reserved interrupt */
  Reserved174_IRQn             = 158,              /**< Reserved interrupt */
  Reserved175_IRQn             = 159,              /**< Reserved interrupt */
  Reserved176_IRQn             = 160,              /**< Reserved interrupt */
  LPI2C0_IRQn                  = 161,              /**< LPI2C Interrupt */
  LPI2C1_IRQn                  = 162,              /**< LPI2C Interrupt */
  Reserved179_IRQn             = 163,              /**< Reserved interrupt */
  Reserved180_IRQn             = 164,              /**< Reserved interrupt */
  LPSPI0_IRQn                  = 165,              /**< LPSPI Interrupt */
  LPSPI1_IRQn                  = 166,              /**< LPSPI Interrupt */
  LPSPI2_IRQn                  = 167,              /**< LPSPI Interrupt */
  LPSPI3_IRQn                  = 168,              /**< LPSPI Interrupt */
  LPSPI4_IRQn                  = 169,              /**< LPSPI Interrupt */
  LPSPI5_IRQn                  = 170,              /**< LPSPI Interrupt */
  Reserved187_IRQn             = 171,              /**< Reserved interrupt */
  Reserved188_IRQn             = 172,              /**< Reserved interrupt */
  QSPI_IRQn                    = 173,              /**< All interrupts ORed output */
  SAI0_IRQn                    = 174,              /**< RX and TX interrupt */
  SAI1_IRQn                    = 175,              /**< RX and TX interrupt */
  Reserved192_IRQn             = 176,              /**< Reserved interrupt */
  Reserved193_IRQn             = 177,              /**< Reserved interrupt */
  JDC_IRQn                     = 178,              /**< Indicates new data to be read from JIN_IPS register or can be written to JOUT_IPS register */
  Reserved195_IRQn             = 179,              /**< Reserved interrupt */
  ADC0_IRQn                    = 180,              /**< End of conversion, Error interrupt, Watchdog interrupt */
  ADC1_IRQn                    = 181,              /**< End of conversion, Error interrupt, Watchdog interrupt */
  ADC2_IRQn                    = 182,              /**< End of conversion, Error interrupt, Watchdog interrupt */
  CMP0_IRQn                    = 183,              /**< Async interrupt */
  CMP1_IRQn                    = 184,              /**< Async interrupt */
  CMP2_IRQn                    = 185,              /**< Async interrupt */
  FCCU_0_IRQn                  = 189,              /**< Interrupt request (ALARM state) */
  FCCU_1_IRQn                  = 190,              /**< Interrupt request (miscellaneous conditions) */
  Reserved207_IRQn             = 191,              /**< Reserved interrupt */
  MU0_B_TX_IRQn                = 192,              /**< ORed TX interrupt to MU-0 */
  MU0_B_RX_IRQn                = 193,              /**< ORed RX interrupt to MU-0 */
  MU0_B_IRQn                   = 194,              /**< ORed general purpose interrupt request to MU-0 */
  MU1_B_TX_IRQn                = 195,              /**< ORed TX interrupt to MU-1 */
  MU1_B_RX_IRQn                = 196,              /**< ORed RX interrupt to MU-1 */
  MU1_B_IRQn                   = 197,              /**< ORed general purpose interrupt request to MU-1 */
  Reserved214_IRQn             = 198,              /**< Reserved interrupt */
  Reserved215_IRQn             = 199,              /**< Reserved interrupt */
  Reserved216_IRQn             = 200,              /**< Reserved interrupt */
  Reserved217_IRQn             = 201,              /**< Reserved interrupt */
  Reserved218_IRQn             = 202,              /**< Reserved interrupt */
  Reserved219_IRQn             = 203,              /**< Reserved interrupt */
  Reserved220_IRQn             = 204,              /**< Reserved interrupt */
  Reserved221_IRQn             = 205,              /**< Reserved interrupt */
  Reserved222_IRQn             = 206,              /**< Reserved interrupt */
  Reserved223_IRQn             = 207,              /**< Reserved interrupt */
  Reserved224_IRQn             = 208,              /**< Reserved interrupt */
  Reserved225_IRQn             = 209,              /**< Reserved interrupt */
  Reserved226_IRQn             = 210,              /**< Reserved interrupt */
  Reserved227_IRQn             = 211,              /**< Reserved interrupt */
  PLL_LOL_IRQn                 = 212,              /**< PLL LOL interrupt */
  CORE_CLK_FAIL_IRQn           = 213,              /**< CORE_CLK_FAIL CMU reset reaction interrupt */
  Reserved230_IRQn             = 214,              /**< PLL2 LOL interrupt */
  AIPS_PLAT_CLK_FAIL_IRQn      = 215,              /**< AIPS_PLAT_CLK_FAIL CMU reset reaction interrupt */
  Reserved232_IRQn             = 216,              /**< XRDC Error Interrupt */
  HSE_B_CLK_FAIL_IRQn          = 217,              /**< HSE_B_CLK_FAIL CMU reset reaction interrupt */
  Reserved234_IRQn             = 218,              /**< Reserved interrupt */
  Reserved235_IRQn             = 219,              /**< CM7_CORE_CLK_FAIL CMU reset reaction interrupt */
  Reserved236_IRQn             = 220,              /**< Reserved interrupt */
  Reserved237_IRQn             = 221,              /**< Reserved interrupt */
  Reserved238_IRQn             = 222,              /**< Reserved interrupt */
  Reserved239_IRQn             = 223               /**< Reserved interrupt */
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
#include "system_MCXE31B.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MCXE31B_SERIES
#define MCXE31B_SERIES
#endif
/* CPU specific feature definitions */
#include "MCXE31B_features.h"

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
 * Refer to Reference Manual DMAMUX chapter for avaiable TCDs.
 */
typedef enum _dma_request_source
{
    kDmaRequestMux0Disabled         = 0U,          /**< Disabled */
    kDmaRequestMux1Disabled         = 0U,          /**< Disabled */
    kDmaRequestMux0SIUL2Req0        = 1U,          /**< SIUL2 DMA request 0 */
    kDmaRequestMux1SIUL2Req8        = 1U,          /**< SIUL2 DMA request 8 */
    kDmaRequestMux0SIUL2Req1        = 2U,          /**< SIUL2 DMA request 1 */
    kDmaRequestMux1SIUL2Req9        = 2U,          /**< SIUL2 DMA request 9 */
    kDmaRequestMux0SIUL2Req2        = 3U,          /**< SIUL2 DMA request 2 */
    kDmaRequestMux1SIUL2Req10       = 3U,          /**< SIUL2 DMA request 10 */
    kDmaRequestMux0SIUL2Req3        = 4U,          /**< SIUL2 DMA request 3 */
    kDmaRequestMux1SIUL2Req11       = 4U,          /**< SIUL2 DMA request 11 */
    kDmaRequestMux0SIUL2Req4        = 5U,          /**< SIUL2 DMA request 4 */
    kDmaRequestMux1SIUL2Req12       = 5U,          /**< SIUL2 DMA request 12 */
    kDmaRequestMux0SIUL2Req5        = 6U,          /**< SIUL2 DMA request 5 */
    kDmaRequestMux1SIUL2Req13       = 6U,          /**< SIUL2 DMA request 13 */
    kDmaRequestMux0SIUL2Req6        = 7U,          /**< SIUL2 DMA request 6 */
    kDmaRequestMux1SIUL2Req14       = 7U,          /**< SIUL2 DMA request 14 */
    kDmaRequestMux0SIUL2Req7        = 8U,          /**< SIUL2 DMA request 7 */
    kDmaRequestMux1SIUL2Req15       = 8U,          /**< SIUL2 DMA request 15 */
    kDmaRequestMux0BCTUFifo1        = 9U,          /**< BCTU DMA FIFO1 request */
    kDmaRequestMux1BCTUFifo2        = 9U,          /**< BCTU DMA FIFO2 request */
    kDmaRequestMux0BCTUReq0         = 10U,         /**< BCTU DMA request 0 */
    kDmaRequestMux1BCTUReq2         = 10U,         /**< BCTU DMA request 2 */
    kDmaRequestMux0BCTUReq1         = 11U,         /**< BCTU DMA request 1 */
    kDmaRequestMux1EMIOS0Req16      = 11U,         /**< EMIOS_0 DMA request 16 */
    kDmaRequestMux0EMIOS0Req0       = 12U,         /**< EMIOS_0 DMA request 0 */
    kDmaRequestMux1EMIOS0Req17      = 12U,         /**< EMIOS_0 DMA request 17 */
    kDmaRequestMux0EMIOS0Req1       = 13U,         /**< EMIOS_0 DMA request 1 */
    kDmaRequestMux1EMIOS0Req18      = 13U,         /**< EMIOS_0 DMA request 18 */
    kDmaRequestMux0EMIOS0Req9       = 14U,         /**< EMIOS_0 DMA request 9 */
    kDmaRequestMux1EMIOS0Req19      = 14U,         /**< EMIOS_0 DMA request 19 */
    kDmaRequestMux0EMIOS0Req10      = 15U,         /**< EMIOS_0 DMA request 10 */
    kDmaRequestMux1EMIOS1Req16      = 15U,         /**< EMIOS_1 DMA request 16 */
    kDmaRequestMux0EMIOS1Req0       = 16U,         /**< EMIOS_1 DMA request 0 */
    kDmaRequestMux1EMIOS1Req17      = 16U,         /**< EMIOS_1 DMA request 17 */
    kDmaRequestMux0EMIOS1Req1       = 17U,         /**< EMIOS_1 DMA request 1 */
    kDmaRequestMux1EMIOS1Req18      = 17U,         /**< EMIOS_1 DMA request 18 */
    kDmaRequestMux0EMIOS1Req9       = 18U,         /**< EMIOS_1 DMA request 9 */
    kDmaRequestMux1EMIOS1Req19      = 18U,         /**< EMIOS_1 DMA request 19 */
    kDmaRequestMux0EMIOS1Req10      = 19U,         /**< EMIOS_1 DMA request 10 */
    kDmaRequestMux1EMIOS2Req16      = 19U,         /**< EMIOS_2 DMA request 16 */
    kDmaRequestMux0EMIOS2Req0       = 20U,         /**< EMIOS_2 DMA request 0 */
    kDmaRequestMux1EMIOS2Req17      = 20U,         /**< EMIOS_2 DMA request 17 */
    kDmaRequestMux0EMIOS2Req1       = 21U,         /**< EMIOS_2 DMA request 1 */
    kDmaRequestMux1EMIOS2Req18      = 21U,         /**< EMIOS_2 DMA request 18 */
    kDmaRequestMux0EMIOS2Req9       = 22U,         /**< EMIOS_2 DMA request 9 */
    kDmaRequestMux1EMIOS2Req19      = 22U,         /**< EMIOS_2 DMA request 19 */
    kDmaRequestMux0EMIOS2Req10      = 23U,         /**< EMIOS_2 DMA request 10 */
    kDmaRequestMux1LCU0Req1         = 23U,         /**< LCU_0 DMA request 1 */
    kDmaRequestMux0LCU0Req0         = 24U,         /**< LCU_0 DMA request 0 */
    kDmaRequestMux1LCU0Req2         = 24U,         /**< LCU_0 DMA request 2 */
    kDmaRequestMux0LCU1Req0         = 25U,         /**< LCU_1 DMA request 0 */
    kDmaRequestMux1LCU1Req1         = 25U,         /**< LCU_1 DMA request 1 */
    kDmaRequestMux0CAN0             = 29U,         /**< FLEXCAN_0 DMA request */
    kDmaRequestMux0CAN1             = 30U,         /**< FLEXCAN_1 DMA request */
    kDmaRequestMux1CAN4             = 30U,         /**< FLEXCAN_4 DMA request */
    kDmaRequestMux0CAN2             = 31U,         /**< FLEXCAN_2 DMA request */
    kDmaRequestMux1CAN5             = 31U,         /**< FLEXCAN_5 DMA request */
    kDmaRequestMux0CAN3             = 32U,         /**< FLEXCAN_3 DMA request */
    kDmaRequestMux0FLEXIOChannel0   = 33U,         /**< FlexIO Timer0 or Shifter0 DMA request */
    kDmaRequestMux0FLEXIOChannel1   = 34U,         /**< FlexIO Timer 1 or Shifter1 DMA request */
    kDmaRequestMux1FLEXIOChannel4   = 34U,         /**< FlexIO Timer4 or Shifter4 DMA request */
    kDmaRequestMux0FLEXIOChannel2   = 35U,         /**< FlexIO Timer 2 or Shifter2 DMA request */
    kDmaRequestMux1FLEXIOChannel5   = 35U,         /**< FlexIO Timer5 or Shifter5 DMA request */
    kDmaRequestMux0FLEXIOChannel3   = 36U,         /**< FlexIO Timer 3 or Shifter3 DMA request */
    kDmaRequestMux1FLEXIOChannel6   = 36U,         /**< FlexIO Timer6 or Shifter6 DMA request */
    kDmaRequestMux0LPUART0LPUART8Tx = 37U,         /**< LPUART_0 or LPUART_8 Transmit DMA request */
    kDmaRequestMux1FLEXIOChannel7   = 37U,         /**< FlexIO Timer7 or Shifter7 DMA request */
    kDmaRequestMux0LPUART0LPUART8Rx = 38U,         /**< LPUART_0 or LPUART_8 Receive DMA request */
    kDmaRequestMux1LPUART2LPUART10Tx = 38U,        /**< LPUART_2 or LPUART_10 Transmit DMA request */
    kDmaRequestMux0LPUART1LPUART9Tx = 39U,         /**< LPUART_1 or LPUART_9 Transmit DMA request */
    kDmaRequestMux1LPUART2LPUART10Rx = 39U,        /**< LPUART2 or LPUART_10 Receive DMA request */
    kDmaRequestMux0LPUART1LPUART9Rx = 40U,         /**< LPUART_1 or LPUART_9 Receive DMA request */
    kDmaRequestMux1LPUART3LPUART11Tx = 40U,        /**< LPUART_3 or LPUART_11 Transmit DMA request */
    kDmaRequestMux0LPI2C0Rx         = 41U,         /**< LPI2C0 DMA RX or RX Slave request */
    kDmaRequestMux1LPUART3LPUART11Rx = 41U,        /**< LPUART_3 or LPUART_11 Receive DMA request */
    kDmaRequestMux0LPI2C0Tx         = 42U,         /**< LPI2C0 DMA TX or Tx Slave request */
    kDmaRequestMux1LPUART4LPUART12Tx = 42U,        /**< LPUART4 or LPUART_12 Transmit DMA request */
    kDmaRequestMux0LPSPI0Tx         = 43U,         /**< LPSPI_0 DMA TX request */
    kDmaRequestMux1LPUART4LPUART12Rx = 43U,        /**< LPUART_4 or LPUART_12 Receive DMA request */
    kDmaRequestMux0LPSPI0Rx         = 44U,         /**< LPSPI_0 DMA RX request */
    kDmaRequestMux1LPUART5LPUART13Tx = 44U,        /**< LPUART 5 or LPUART_13 Transmit DMA request */
    kDmaRequestMux0LPSPI1Tx         = 45U,         /**< LPSPI_1 DMA TX request */
    kDmaRequestMux1LPUART5LPUART13Rx = 45U,        /**< LPUART5 or LPUART_13 Receive DMA request */
    kDmaRequestMux0LPSPI1Rx         = 46U,         /**< LPSPI_1 DMA RX request */
    kDmaRequestMux1LPUART6LPUART14Tx = 46U,        /**< LPUART_6 or LPUART_14 Transmit DMA request */
    kDmaRequestMux0LPSPI2Tx         = 47U,         /**< LPSPI_2 DMA TX request */
    kDmaRequestMux1LPUART6LPUART14Rx = 47U,        /**< LPUART_6 or LPUART_14 Receive DMA request */
    kDmaRequestMux0LPSPI2Rx         = 48U,         /**< LPSPI_2 DMA RX request */
    kDmaRequestMux1LPUART7LPUART15Tx = 48U,        /**< LPUART_7 or LPUART_15 Transmit DMA request */
    kDmaRequestMux0LPSPI3Tx         = 49U,         /**< LPSPI_3 DMA TX request */
    kDmaRequestMux1LPUART7LPUART15Rx = 49U,        /**< LPUART7 or LPUART_15 Receive DMA request */
    kDmaRequestMux0LPSPI3Rx         = 50U,         /**< LPSPI_3 DMA RX request */
    kDmaRequestMux1LPI2C1Rx         = 50U,         /**< LPI2C1 DMA RX or Slave RX request */
    kDmaRequestMux0QSPIRx           = 53U,         /**< QSPI RX Buffer Drain DMA request */
    kDmaRequestMux1LPSPI4Rx         = 53U,         /**< LPSPI_4 DMA RX request */
    kDmaRequestMux0QSPITx           = 54U,         /**< QSPI TX Buffer Fill DMA request */
    kDmaRequestMux1LPSPI5Tx         = 54U,         /**< LPSPI_5 DMA TX request */
    kDmaRequestMux0SAI0Rx           = 55U,         /**< SAI_0 DMA Receive request */
    kDmaRequestMux1LPSPI5Rx         = 55U,         /**< LPSPI_5 DMA RX request */
    kDmaRequestMux0SAI0Tx           = 56U,         /**< SAI_0 DMA Transmit request */
    kDmaRequestMux1SAI1Rx           = 56U,         /**< SAI_1 DMA Receive request */
    kDmaRequestMux0ADC0             = 58U,         /**< ADC_0 DMA request */
    kDmaRequestMux0ADC1             = 59U,         /**< ADC_1 DMA request */
    kDmaRequestMux0ADC2             = 60U,         /**< ADC_2 DMA request */
    kDmaRequestMux1LPCMP1           = 60U,         /**< LPCMP_1 DMA COUT request */
    kDmaRequestMux0LPCMP0           = 61U,         /**< LPCMP_0 DMA COUT request */
    kDmaRequestMux1LPCMP2           = 61U,         /**< LPCMP_2 DMA COUT request */
    kDmaRequestMux0AlwaysOn62       = 62U,         /**<  Always On */
    kDmaRequestMux1AwaysOn62        = 62U,         /**<  Always On */
    kDmaRequestMux0AlwaysOn63       = 63U,         /**<  Always On */
    kDmaRequestMux1AwaysOn63        = 63U,         /**<  Always On */
    kDmaRequestMux1LCU1Req2         = 26U,         /**< LCU_1 DMA request 2 */
    kDmaRequestMux1EMACPTPTimer     = 27U,         /**< EMAC IEEE 1588 PTP timer ch0-3 */
    kDmaRequestMux1LPI2C1Tx         = 51U,         /**< LPI2C1 DMA TX or Slave Tx request */
    kDmaRequestMux1LPSPI4Tx         = 52U,         /**< LPSPI_4 DMA TX request */
    kDmaRequestMux1SAI1Tx           = 57U,         /**< SAI_1 DMA Transmit request */
} dma_request_source_t;

/* @} */

/*!
 * @addtogroup trgmux_source
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Structure for the TRGMUX source
 *
 * Defines the structure for the TRGMUX source collections.
 */
typedef enum _trgmux_source
{
    kTRGMUX_SourceDisabled          = 0U,          /**< Trigger function is disabled */
    kTRGMUX_SourceAlwaysHigh        = 1U,          /**< Trigger function is always high */
    kTRGMUX_SourceAdc0Eoc           = 2U,          /**< ADC0 End of Conversion is selected */
    kTRGMUX_SourceAdc1Eoc           = 3U,          /**< ADC1 End of Conversion is selected */
    kTRGMUX_SourceAdc2Eoc           = 4U,          /**< ADC2 End of Conversion is selected */
    kTRGMUX_SourceLpcmp0            = 5U,          /**< LPCMP_0 Comparator output is selected */
    kTRGMUX_SourceLpcmp1            = 6U,          /**< LPCMP_1 Comparator output is selected */
    kTRGMUX_SourceLpcmp2            = 7U,          /**< LPCMP_2 Comparator output is selected */
    kTRGMUX_SourceDmaCh0            = 8U,          /**< eDMA Channel 0 Done is selected */
    kTRGMUX_SourceDmaCh1            = 9U,          /**< eDMA Channel 1 Done is selected */
    kTRGMUX_SourceDmaCh16           = 10U,         /**< eDMA Channel 16 Done is selected */
    kTRGMUX_SourceDmaCh17           = 11U,         /**< eDMA Channel 17 Done is selected */
    kTRGMUX_SourceEmios0ReloadOutCh23 = 12U,       /**< eMIOS_0 Reload Out Ch23 is selected */
    kTRGMUX_SourceEmios0ReloadOutCh22 = 13U,       /**< eMIOS_0 Reload Out Ch22 is selected */
    kTRGMUX_SourceEmios0ReloadOutCh8 = 14U,        /**< eMIOS_0 Reload Out Ch8 is selected */
    kTRGMUX_SourceEmios0ReloadOutCh0 = 15U,        /**< eMIOS_0 Reload Out Ch0 is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh0 = 16U,       /**< eMIOS_0_IPP_DO_eMIOS_CH[0] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh1 = 17U,       /**< eMIOS_0_IPP_DO_eMIOS_CH[1] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh2 = 18U,       /**< eMIOS_0_IPP_DO_eMIOS_CH[2] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh3 = 19U,       /**< eMIOS_0_IPP_DO_eMIOS_CH[3] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh4 = 20U,       /**< eMIOS_0_IPP_DO_eMIOS_CH[4] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh5 = 21U,       /**< eMIOS_0_IPP_DO_eMIOS_CH[5] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh6 = 22U,       /**< eMIOS_0_IPP_DO_eMIOS_CH[6] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh7 = 23U,       /**< eMIOS_0_IPP_DO_eMIOS_CH[7] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh8 = 24U,       /**< eMIOS_0_IPP_DO_eMIOS_CH[8] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh9 = 25U,       /**< eMIOS_0_IPP_DO_eMIOS_CH[9] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh10 = 26U,      /**< eMIOS_0_IPP_DO_eMIOS_CH[10] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh11 = 27U,      /**< eMIOS_0_IPP_DO_eMIOS_CH[11] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh12 = 28U,      /**< eMIOS_0_IPP_DO_eMIOS_CH[12] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh13 = 29U,      /**< eMIOS_0_IPP_DO_eMIOS_CH[13] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh14 = 30U,      /**< eMIOS_0_IPP_DO_eMIOS_CH[14] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh15 = 31U,      /**< eMIOS_0_IPP_DO_eMIOS_CH[15] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh22 = 32U,      /**< eMIOS_0_IPP_DO_eMIOS_CH[22] is selected */
    kTRGMUX_SourceEmios0IppDoEmiosCh23 = 33U,      /**< eMIOS_0_IPP_DO_eMIOS_CH[23] is selected */
    kTRGMUX_SourceEmios1ReloadOutCh23 = 34U,       /**< eMIOS_1 Reload Out Ch23 is selected */
    kTRGMUX_SourceEmios1ReloadOutCh22 = 35U,       /**< eMIOS_1 Reload Out Ch22 is selected */
    kTRGMUX_SourceEmios1ReloadOutCh8 = 36U,        /**< eMIOS_1 Reload Out Ch8 is selected */
    kTRGMUX_SourceEmios1ReloadOutCh0 = 37U,        /**< eMIOS_1 Reload Out Ch0 is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh0 = 38U,       /**< eMIOS_1_IPP_DO_eMIOS_CH[0] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh1 = 39U,       /**< eMIOS_1_IPP_DO_eMIOS_CH[1] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh2 = 40U,       /**< eMIOS_1_IPP_DO_eMIOS_CH[2] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh3 = 41U,       /**< eMIOS_1_IPP_DO_eMIOS_CH[3] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh4 = 42U,       /**< eMIOS_1_IPP_DO_eMIOS_CH[4] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh5 = 43U,       /**< eMIOS_1_IPP_DO_eMIOS_CH[5] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh6 = 44U,       /**< eMIOS_1_IPP_DO_eMIOS_CH[6] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh7 = 45U,       /**< eMIOS_1_IPP_DO_eMIOS_CH[7] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh8 = 46U,       /**< eMIOS_1_IPP_DO_eMIOS_CH[8] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh9 = 47U,       /**< eMIOS_1_IPP_DO_eMIOS_CH[9] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh10 = 48U,      /**< eMIOS_1_IPP_DO_eMIOS_CH[10] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh11 = 49U,      /**< eMIOS_1_IPP_DO_eMIOS_CH[11] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh12 = 50U,      /**< eMIOS_1_IPP_DO_eMIOS_CH[12] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh13 = 51U,      /**< eMIOS_1_IPP_DO_eMIOS_CH[13] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh14 = 52U,      /**< eMIOS_1_IPP_DO_eMIOS_CH[14] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh15 = 53U,      /**< eMIOS_1_IPP_DO_eMIOS_CH[15] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh22 = 54U,      /**< eMIOS_1_IPP_DO_eMIOS_CH[22] is selected */
    kTRGMUX_SourceEmios1IppDoEmiosCh23 = 55U,      /**< eMIOS_1_IPP_DO_eMIOS_CH[23] is selected */
    kTRGMUX_SourceFlexIOTrg0        = 56U,         /**< FLEXIO Trigger 0 is selected */
    kTRGMUX_SourceFlexIOTrg1        = 57U,         /**< FLEXIO Trigger 1 is selected */
    kTRGMUX_SourceFlexIOTrg2        = 58U,         /**< FLEXIO Trigger 2 is selected */
    kTRGMUX_SourceFlexIOTrg3        = 59U,         /**< FLEXIO Trigger 3 is selected */
    kTRGMUX_SourceTriggerMuxInput0  = 60U,         /**< SIUL2 TRGMUX IN0 is selected */
    kTRGMUX_SourceTriggerMuxInput1  = 61U,         /**< SIUL2 TRGMUX IN1 is selected */
    kTRGMUX_SourceTriggerMuxInput2  = 62U,         /**< SIUL2 TRGMUX IN2 is selected */
    kTRGMUX_SourceTriggerMuxInput3  = 63U,         /**< SIUL2 TRGMUX IN3 is selected */
    kTRGMUX_SourceTriggerMuxInput4  = 64U,         /**< SIUL2 TRGMUX IN4 is selected */
    kTRGMUX_SourceTriggerMuxInput5  = 65U,         /**< SIUL2 TRGMUX IN5 is selected */
    kTRGMUX_SourceTriggerMuxInput6  = 66U,         /**< SIUL2 TRGMUX IN6 is selected */
    kTRGMUX_SourceTriggerMuxInput7  = 67U,         /**< SIUL2 TRGMUX IN7 is selected */
    kTRGMUX_SourceTriggerMuxInput8  = 68U,         /**< SIUL2 TRGMUX IN8 is selected */
    kTRGMUX_SourceTriggerMuxInput9  = 69U,         /**< SIUL2 TRGMUX IN9 is selected */
    kTRGMUX_SourceTriggerMuxInput10 = 70U,         /**< SIUL2 TRGMUX IN10 is selected */
    kTRGMUX_SourceTriggerMuxInput11 = 71U,         /**< SIUL2 TRGMUX IN11 is selected */
    kTRGMUX_SourceTriggerMuxInput12 = 72U,         /**< SIUL2 TRGMUX IN12 is selected */
    kTRGMUX_SourceTriggerMuxInput13 = 73U,         /**< SIUL2 TRGMUX IN13 is selected */
    kTRGMUX_SourceTriggerMuxInput14 = 74U,         /**< SIUL2 TRGMUX IN14 is selected */
    kTRGMUX_SourceTriggerMuxInput15 = 75U,         /**< SIUL2 TRGMUX IN15 is selected */
    kTRGMUX0_SourceLpi2c0Master     = 76U,         /**< LPI2C_0 Master trigger is selected */
    kTRGMUX0_SourceLpi2c0Slave      = 77U,         /**< LPI2C_0 Slave trigger is selected */
    kTRGMUX0_SourceLpspi0Frame      = 78U,         /**< LPSPI0 End of Frame is selected */
    kTRGMUX0_SourceLpspi0RxData     = 79U,         /**< LPSPI0 RX Data input is selected */
    kTRGMUX0_SourceLpspi1Frame      = 80U,         /**< LPSPI1 End of Frame is selected */
    kTRGMUX0_SourceLpspi1RxData     = 81U,         /**< LPSPI1 RX Data input is selected */
    kTRGMUX0_SourceLpspi2Frame      = 82U,         /**< LPSPI2 End of Frame is selected */
    kTRGMUX0_SourceLpspi2RxData     = 83U,         /**< LPSPI2 RX Data input is selected */
    kTRGMUX0_SourceLpuart0TxData    = 84U,         /**< LPUART0 TX Data input is selected */
    kTRGMUX0_SourceLpuart0RxData    = 85U,         /**< LPUART0 RX Data input is selected */
    kTRGMUX0_SourceLpuart0RxIdle    = 86U,         /**< LPUART0 RX Idle input is selected */
    kTRGMUX0_SourceLpuart1TxData    = 87U,         /**< LPUART1 TX Data input is selected */
    kTRGMUX0_SourceLpuart1RxData    = 88U,         /**< LPUART1 RX Data input is selected */
    kTRGMUX0_SourceLpuart1RxIdle    = 89U,         /**< LPUART1 RX Idle input is selected */
    kTRGMUX0_SourceLpuart2TxData    = 90U,         /**< LPUART2 TX Data input is selected */
    kTRGMUX0_SourceLpuart2RxData    = 91U,         /**< LPUART2 RX Data input is selected */
    kTRGMUX0_SourceLpuart2RxIdle    = 92U,         /**< LPUART2 RX Idle input is selected */
    kTRGMUX_SourceLcu0Lc0Out0       = 93U,         /**< LCU_0 LC0 Out_i0 is selected */
    kTRGMUX_SourceLcu0Lc0Out1       = 94U,         /**< LCU_0 LC0 Out_i1 is selected */
    kTRGMUX_SourceLcu0Lc0Out2       = 95U,         /**< LCU_0 LC0 Out_i2 is selected */
    kTRGMUX_SourceLcu0Lc0Out3       = 96U,         /**< LCU_0 LC0 Out_i3 is selected */
    kTRGMUX_SourceLcu0Lc1Out0       = 97U,         /**< LCU_0 LC1 Out_i0 is selected */
    kTRGMUX_SourceLcu0Lc1Out1       = 98U,         /**< LCU_0 LC1 Out_i1 is selected */
    kTRGMUX_SourceLcu0Lc1Out2       = 99U,         /**< LCU_0 LC1 Out_i2 is selected */
    kTRGMUX_SourceLcu0Lc1Out3       = 100U,        /**< LCU_0 LC1 Out_i3 is selected */
    kTRGMUX_SourceLcu0Lc2Out0       = 101U,        /**< LCU_0 LC2 Out_i0 is selected */
    kTRGMUX_SourceLcu0Lc2Out1       = 102U,        /**< LCU_0 LC2 Out_i1 is selected */
    kTRGMUX_SourceLcu0Lc2Out2       = 103U,        /**< LCU_0 LC2 Out_i2 is selected */
    kTRGMUX_SourceLcu0Lc2Out3       = 104U,        /**< LCU_0 LC2 Out_i3 is selected */
    kTRGMUX_SourceLcu1Lc0Out0       = 105U,        /**< LCU_1 LC0 Out_i0 is selected */
    kTRGMUX_SourceLcu1Lc0Out1       = 106U,        /**< LCU_1 LC0 Out_i1 is selected */
    kTRGMUX_SourceLcu1Lc0Out2       = 107U,        /**< LCU_1 LC0 Out_i2 is selected */
    kTRGMUX_SourceLcu1Lc0Out3       = 108U,        /**< LCU_1 LC0 Out_i3 is selected */
    kTRGMUX_SourceLcu1Lc1Out0       = 109U,        /**< LCU_1 LC1 Out_i0 is selected */
    kTRGMUX_SourceLcu1Lc1Out1       = 110U,        /**< LCU_1 LC1 Out_i1 is selected */
    kTRGMUX_SourceLcu1Lc1Out2       = 111U,        /**< LCU_1 LC1 Out_i2 is selected */
    kTRGMUX_SourceLcu1Lc1Out3       = 112U,        /**< LCU_1 LC1 Out_i3 is selected */
    kTRGMUX_SourceLcu1Lc2Out0       = 113U,        /**< LCU_1 LC2 Out_i0 is selected */
    kTRGMUX_SourceLcu1Lc2Out1       = 114U,        /**< LCU_1 LC2 Out_i1 is selected */
    kTRGMUX_SourceLcu1Lc2Out2       = 115U,        /**< LCU_1 LC2 Out_i2 is selected */
    kTRGMUX_SourceLcu1Lc2Out3       = 116U,        /**< LCU_1 LC2 Out_i3 is selected */
    kTRGMUX_SourcePit0Ch0           = 117U,        /**< PIT0 Channel0 is selected */
    kTRGMUX_SourcePit0Ch1           = 118U,        /**< PIT0 Channel1 is selected */
    kTRGMUX_SourcePit0Ch2           = 119U,        /**< PIT0 Channel2 is selected */
    kTRGMUX_SourcPit0Ch3            = 120U,        /**< PIT0 Channel3 is selected */
    kTRGMUX_SourcPit0Ch4Rti         = 121U,        /**< PIT0 Channel4 RTI is selected */
    kTRGMUX_SourcePit1Ch0           = 122U,        /**< PIT1 Channel0 is selected */
    kTRGMUX_SourcePit1Ch1           = 123U,        /**< PIT1 Channel1 is selected */
    kTRGMUX_SourcePit1Ch2           = 124U,        /**< PIT1 Channel2 is selected */
    kTRGMUX_SourcPit1Ch3            = 125U,        /**< PIT1 Channel3 is selected */
    kTRGMUX_SourcCm7Txev            = 126U,        /**< CM7 TXEV is selected */
} trgmux_source_t;

/*!
 * @brief Structure for the TRGMUX device
 *
 * Defines the structure for the TRGMUX device collections.
 */
typedef enum _trgmux_device
{
    kTRGMUX_Adc0                    = 0U,          /**< ADC_0 device trigger input */
    kTRGMUX_Adc1                    = 1U,          /**< ADC_1 device trigger input */
    kTRGMUX_Adc2                    = 2U,          /**< ADC_2 device trigger input */
    kTRGMUX_Lpcmp0                  = 3U,          /**< LPCMP_0 device trigger input */
    kTRGMUX_Lpcmp1                  = 4U,          /**< LPCMP_1 device trigger input */
    kTRGMUX_Lpcmp2                  = 5U,          /**< LPCMP_2 device trigger input */
    kTRGMUX_Bctu                    = 6U,          /**< BCTU device trigger input */
    kTRGMUX_Emios012_Odis           = 7U,          /**< eMIOS012_ODIS device trigger input */
    kTRGMUX_Emios0_0                = 8U,          /**< eMIOS0_0 device trigger input */
    kTRGMUX_Emios0_1                = 9U,          /**< eMIOS0_1 device trigger input */
    kTRGMUX_Emios0_2                = 10U,         /**< eMIOS0_2 device trigger input */
    kTRGMUX_Emios0_3                = 11U,         /**< eMIOS0_3 device trigger input */
    kTRGMUX_Emios1_0                = 12U,         /**< eMIOS1_0 device trigger input */
    kTRGMUX_Emios1_1                = 13U,         /**< eMIOS1_1 device trigger input */
    kTRGMUX_Emios1_2                = 14U,         /**< eMIOS1_2 device trigger input */
    kTRGMUX_Emios1_3                = 15U,         /**< eMIOS1_3 device trigger input */
    kTRGMUX_Flexio                  = 16U,         /**< FLEXIO device trigger input */
    kTRGMUX_ExtOut0                 = 17U,         /**< SIUL2 TRGMUX_OUT0 device trigger input */
    kTRGMUX_ExtOut1                 = 18U,         /**< SIUL2 TRGMUX_OUT1 device trigger input */
    kTRGMUX_ExtOut2                 = 19U,         /**< SIUL2 TRGMUX_OUT2 device trigger input */
    kTRGMUX_ExtOut3                 = 20U,         /**< SIUL2 TRGMUX_OUT3 device trigger input */
    kTRGMUX_Lpi2c0                  = 21U,         /**< LPI2C_0 device trigger input */
    kTRGMUX_Lpspi0                  = 22U,         /**< LPSPI_0 device trigger input */
    kTRGMUX_Lpspi1                  = 23U,         /**< LPSPI_1 device trigger input */
    kTRGMUX_Lpspi2                  = 24U,         /**< LPSPI_2 device trigger input */
    kTRGMUX_Lpuart0                 = 25U,         /**< LPUART_0 device trigger input */
    kTRGMUX_Lpuart1                 = 26U,         /**< LPUART_1 device trigger input */
    kTRGMUX_Lpuart2                 = 27U,         /**< LPUART_2 device trigger input */
    kTRGMUX_Lpuart3                 = 28U,         /**< LPUART_3 device trigger input */
    kTRGMUX_Lcu0Sync                = 29U,         /**< LCU0_SYNC device trigger input */
    kTRGMUX_Lcu0Force               = 30U,         /**< LCU0_FORCE device trigger input */
    kTRGMUX_Lcu0_0                  = 31U,         /**< LCU0_0 device trigger input */
    kTRGMUX_Lcu0_1                  = 32U,         /**< LCU0_1 device trigger input */
    kTRGMUX_Lcu0_2                  = 33U,         /**< LCU0_2 device trigger input */
    kTRGMUX_Lcu1Sync                = 34U,         /**< LCU1_SYNC device trigger input */
    kTRGMUX_Lcu1Force               = 35U,         /**< LCU1_FORCE device trigger input */
    kTRGMUX_Lcu1_0                  = 36U,         /**< LCU1_0 device trigger input */
    kTRGMUX_Lcu1_1                  = 37U,         /**< LCU1_1 device trigger input */
    kTRGMUX_Lcu1_2                  = 38U,         /**< LCU1_2 device trigger input */
    kTRGMUX_Cm7Rxev                 = 39U,         /**< CM7_RXEV device trigger input */
} trgmux_device_t;

/* @} */

/*!
 * @addtogroup tspc_group1_pad
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Structure for the TSPC group1
 *
 * Defines the structure for the TSPC group1 pads.
 */
typedef enum _tspc_group1_pads
{
    kTSPC_Group1PTD1                = (uint64_t)(1ULL << 0), /**< TSPC pad mask PTD1 in group 1 */
    kTSPC_Group1PTD0                = (uint64_t)(1ULL << 1), /**< TSPC pad mask PTD0 in group 1 */
    kTSPC_Group1PTB3                = (uint64_t)(1ULL << 2), /**< TSPC pad mask PTB3 in group 1 */
    kTSPC_Group1PTB2                = (uint64_t)(1ULL << 3), /**< TSPC pad mask PTB2 in group 1 */
    kTSPC_Group1PTB1                = (uint64_t)(1ULL << 4), /**< TSPC pad mask PTB1 in group 1 */
    kTSPC_Group1PTB0                = (uint64_t)(1ULL << 5), /**< TSPC pad mask PTB0 in group 1 */
    kTSPC_Group1PTC9                = (uint64_t)(1ULL << 6), /**< TSPC pad mask PTC9 in group 1 */
    kTSPC_Group1PTC8                = (uint64_t)(1ULL << 7), /**< TSPC pad mask PTC8 in group 1 */
    kTSPC_Group1PTA7                = (uint64_t)(1ULL << 8), /**< TSPC pad mask PTA7 in group 1 */
    kTSPC_Group1PTB13               = (uint64_t)(1ULL << 9), /**< TSPC pad mask PTB13 in group 1 */
    kTSPC_Group1PTD3                = (uint64_t)(1ULL << 10), /**< TSPC pad mask PTD3 in group 1 */
    kTSPC_Group1PTD2                = (uint64_t)(1ULL << 11), /**< TSPC pad mask PTD2 in group 1 */
    kTSPC_Group1PTE16               = (uint64_t)(1ULL << 12), /**< TSPC pad mask PTE16 in group 1 */
    kTSPC_Group1PTE15               = (uint64_t)(1ULL << 13), /**< TSPC pad mask PTE15 in group 1 */
    kTSPC_Group1PTE11               = (uint64_t)(1ULL << 14), /**< TSPC pad mask PTE11 in group 1 */
    kTSPC_Group1PTE10               = (uint64_t)(1ULL << 15), /**< TSPC pad mask PTE10 in group 1 */
    kTSPC_Group1PTC12               = (uint64_t)(1ULL << 16), /**< TSPC pad mask PTC12 in group 1 */
    kTSPC_Group1PTC11               = (uint64_t)(1ULL << 17), /**< TSPC pad mask PTC11 in group 1 */
    kTSPC_Group1PTC10               = (uint64_t)(1ULL << 18), /**< TSPC pad mask PTC10 in group 1 */
    kTSPC_Group1PTA6                = (uint64_t)(1ULL << 19), /**< TSPC pad mask PTA6 in group 1. */
    kTSPC_Group1PTB17               = (uint64_t)(1ULL << 20), /**< TSPC pad mask PTB17 in group 1 */
    kTSPC_Group1PTB15               = (uint64_t)(1ULL << 21), /**< TSPC pad mask PTB15 in group 1 */
    kTSPC_Group1PTB14               = (uint64_t)(1ULL << 22), /**< TSPC pad mask PTB14 in group 1 */
    kTSPC_Group1PTB12               = (uint64_t)(1ULL << 23), /**< TSPC pad mask PTB12 in group 1 */
    kTSPC_Group1PTD4                = (uint64_t)(1ULL << 24), /**< TSPC pad mask PTD4 in group 1 */
    kTSPC_Group1PTA18               = (uint64_t)(1ULL << 25), /**< TSPC pad mask PTA18 in group 1 */
    kTSPC_Group1PTA19               = (uint64_t)(1ULL << 26), /**< TSPC pad mask PTA19 in group 1 */
    kTSPC_Group1PTA20               = (uint64_t)(1ULL << 27), /**< TSPC pad mask PTA20 in group 1 */
    kTSPC_Group1PTA21               = (uint64_t)(1ULL << 28), /**< TSPC pad mask PTA21 in group 1 */
    kTSPC_Group1PTE5                = (uint64_t)(1ULL << 29), /**< TSPC pad mask PTE5 in group 1 */
    kTSPC_Group1PTE4                = (uint64_t)(1ULL << 30), /**< TSPC pad mask PTE4 in group 1 */
    kTSPC_Group1PTC21               = (uint64_t)(1ULL << 31), /**< TSPC pad mask PTC21 in group 1 */
    kTSPC_Group1PTC23               = (uint64_t)(1ULL << 32), /**< TSPC pad mask PTC23 in group 1 */
    kTSPC_Group1PTC24               = (uint64_t)(1ULL << 33), /**< TSPC pad mask PTC24 in group 1 */
    kTSPC_Group1PTC25               = (uint64_t)(1ULL << 34), /**< TSPC pad mask PTC25 in group 1 */
    kTSPC_Group1PTC26               = (uint64_t)(1ULL << 35), /**< TSPC pad mask PTC26 in group 1 */
    kTSPC_Group1PTC27               = (uint64_t)(1ULL << 36), /**< TSPC pad mask PTC27 in group 1 */
    kTSPC_Group1PTC28               = (uint64_t)(1ULL << 37), /**< TSPC pad mask PTC28 in group 1 */
    kTSPC_Group1PTC29               = (uint64_t)(1ULL << 38), /**< TSPC pad mask PTC29 in group 1 */
    kTSPC_Group1PTC30               = (uint64_t)(1ULL << 39), /**< TSPC pad mask PTC30 in group 1 */
    kTSPC_Group1PTC31               = (uint64_t)(1ULL << 40), /**< TSPC pad mask PTC31 in group 1 */
    kTSPC_Group1PTE7                = (uint64_t)(1ULL << 41), /**< TSPC pad mask PTE7 in group 1 */
    kTSPC_Group1PTA17               = (uint64_t)(1ULL << 42), /**< TSPC pad mask PTA17 in group 1 */
    kTSPC_Group1PTD20               = (uint64_t)(1ULL << 43), /**< TSPC pad mask PTD20 in group 1 */
    kTSPC_Group1PTD21               = (uint64_t)(1ULL << 44), /**< TSPC pad mask PTD21 in group 1 */
    kTSPC_Group1PTD22               = (uint64_t)(1ULL << 45), /**< TSPC pad mask PTD22 in group 1 */
} tspc_group1_pads_t;

/*!
 * @brief Structure for the TSPC group2
 *
 * Defines the structure for the TSPC group2 pads.
 */
typedef enum _tspc_group2_pads
{
    kTSPC_Group2PTA3                = (uint64_t)(1ULL << 0), /**< TSPC pad mask PTA3 in group 2 */
    kTSPC_Group2PTA2                = (uint64_t)(1ULL << 1), /**< TSPC pad mask PTA2 in group 2 */
    kTSPC_Group2PTA0                = (uint64_t)(1ULL << 2), /**< TSPC pad mask PTA0 in group 2 */
    kTSPC_Group2PTC7                = (uint64_t)(1ULL << 3), /**< TSPC pad mask PTC7 in group 2 */
    kTSPC_Group2PTA13               = (uint64_t)(1ULL << 4), /**< TSPC pad mask PTA13 in group 2 */
    kTSPC_Group2PTA11               = (uint64_t)(1ULL << 5), /**< TSPC pad mask PTA11 in group 2 */
    kTSPC_Group2PTA10               = (uint64_t)(1ULL << 6), /**< TSPC pad mask PTA10 in group 2 */
    kTSPC_Group2PTC5                = (uint64_t)(1ULL << 7), /**< TSPC pad mask PTC5 in group 2 */
    kTSPC_Group2PTA4                = (uint64_t)(1ULL << 8), /**< TSPC pad mask PTA4 in group 2 */
    kTSPC_Group2PTB11               = (uint64_t)(1ULL << 9), /**< TSPC pad mask PTB11 in group 2 */
    kTSPC_Group2PTB10               = (uint64_t)(1ULL << 10), /**< TSPC pad mask PTB10 in group 2 */
    kTSPC_Group2PTB9                = (uint64_t)(1ULL << 11), /**< TSPC pad mask PTB9 in group 2 */
    kTSPC_Group2PTB8                = (uint64_t)(1ULL << 12), /**< TSPC pad mask PTB8 in group 2 */
    kTSPC_Group2PTA16               = (uint64_t)(1ULL << 13), /**< TSPC pad mask PTA16 in group 2 */
    kTSPC_Group2PTA15               = (uint64_t)(1ULL << 14), /**< TSPC pad mask PTA15 in group 2 */
    kTSPC_Group2PTE6                = (uint64_t)(1ULL << 15), /**< TSPC pad mask PTE6 in group 2 */
    kTSPC_Group2PTE2                = (uint64_t)(1ULL << 16), /**< TSPC pad mask PTE2 in group 2 */
    kTSPC_Group2PTA14               = (uint64_t)(1ULL << 17), /**< TSPC pad mask PTA14 in group 2 */
    kTSPC_Group2PTE1                = (uint64_t)(1ULL << 18), /**< TSPC pad mask PTE1 in group 2 */
    kTSPC_Group2PTE0                = (uint64_t)(1ULL << 19), /**< TSPC pad mask PTE0 in group 2 */
    kTSPC_Group2PTA9                = (uint64_t)(1ULL << 20), /**< TSPC pad mask PTA9 in group 2 */
    kTSPC_Group2PTA12               = (uint64_t)(1ULL << 21), /**< TSPC pad mask PTA12 in group 2 */
    kTSPC_Group2PTD23               = (uint64_t)(1ULL << 22), /**< TSPC pad mask PTD23 in group 2 */
    kTSPC_Group2PTD24               = (uint64_t)(1ULL << 23), /**< TSPC pad mask PTD24 in group 2 */
    kTSPC_Group2PTD26               = (uint64_t)(1ULL << 24), /**< TSPC pad mask PTD26 in group 2 */
    kTSPC_Group2PTD27               = (uint64_t)(1ULL << 25), /**< TSPC pad mask PTD27 in group 2 */
    kTSPC_Group2PTD28               = (uint64_t)(1ULL << 26), /**< TSPC pad mask PTD28 in group 2 */
    kTSPC_Group2PTD29               = (uint64_t)(1ULL << 27), /**< TSPC pad mask PTD29 in group 2 */
    kTSPC_Group2PTD30               = (uint64_t)(1ULL << 28), /**< TSPC pad mask PTD30 in group 2 */
    kTSPC_Group2PTD31               = (uint64_t)(1ULL << 29), /**< TSPC pad mask PTD31 in group 2 */
    kTSPC_Group2PTE17               = (uint64_t)(1ULL << 30), /**< TSPC pad mask PTE17 in group 2 */
    kTSPC_Group2PTE18               = (uint64_t)(1ULL << 31), /**< TSPC pad mask PTE18 in group 2 */
    kTSPC_Group2PTE21               = (uint64_t)(1ULL << 32), /**< TSPC pad mask PTE21 in group 2 */
    kTSPC_Group2PTE22               = (uint64_t)(1ULL << 33), /**< TSPC pad mask PTE22 in group 2 */
    kTSPC_Group2PTE23               = (uint64_t)(1ULL << 34), /**< TSPC pad mask PTE23 in group 2 */
    kTSPC_Group2PTE24               = (uint64_t)(1ULL << 35), /**< TSPC pad mask PTE24 in group 2 */
    kTSPC_Group2PTE25               = (uint64_t)(1ULL << 36), /**< TSPC pad mask PTE25 in group 2 */
    kTSPC_Group2PTE26               = (uint64_t)(1ULL << 37), /**< TSPC pad mask PTE26 in group 2 */
} tspc_group2_pads_t;

/* @} */

/*!
 * @addtogroup xbic
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the XBIC Master Port
 *
 * Defines the structure for the xbic master port collections.
 */
typedef enum _xbic_master_port
{
    kXbicAxbsMasterCortexM70Ahbm    = 0U,          /**< Cortex-M7 AHBM */
    kXbicAxbsPeriMasterCortexM70Ahbp = 0U,         /**< Cortex-M7 AHBP */
    kXbicAxbsEdmaMasterEdma         = 0U,          /**< EDMA */
    kXbicAxbsTcmMasterAxbs3         = 0U,          /**< AXBS3 */
    kXbicAxbsMasterAxbs2S0          = 1U,          /**< AXBS2 S0 */
    kXbicAxbsPeriMasterAxbs2S1      = 1U,          /**< AXBS2 S1 */
    kXbicAxbsMasterHseB             = 2U,          /**< HSE-B */
    kXbicAxbsPeriMasterHseB         = 2U,          /**< HSE-B */
    kkXbicAxbsMasterEmac            = 3U,          /**< EMAC */
} xbic_master_port_t;

/* @} */

/*!
 * @brief Structure for the XBIC Slave Port
 *
 * Defines the structure for the XBIC Slave Port collections.
 */
typedef enum _xbic_slave_port
{
    kXbicAxbsSlaveFlashMemoryPort0  = 0U,          /**< Flash Memory port0 */
    kXbicAxbsPeriSlaveAips0         = 0U,          /**< AIPS0 */
    kXbicAxbsEdmaSlaveAxbs0M1       = 0U,          /**< AXBS0 M1 */
    kXbicAxbsTcmSlaveCortexM70Tcm   = 0U,          /**< TCM */
    kXbicAxbsSlaveFlashMemoryPort1  = 1U,          /**< Flash Memory port1 */
    kXbicAxbsPeriSlaveAips1         = 1U,          /**< AIPS1 */
    kXbicAxbsEdmaSlaveAxbs1M1       = 1U,          /**< AXBS1 M1 */
    kXbicAxbsSlavePram0             = 2U,          /**< PRAM0 */
    kXbicAxbsPeriSlaveAips2         = 2U,          /**< AIPS2 */
    kXbicAxbsSlaveCortexM7Tcm       = 3U,          /**< TCM */
    kXbicAxbsSlaveFlashMemoryPort2  = 4U,          /**< Flash Memory port2 */
    kXbicAxbsSlaveQuadSpi           = 5U,          /**< QSPI */
    kXbicAxbsSlavePram1             = 6U,          /**< PRAM1 */
} xbic_slave_port_t;

/* @} */


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC_0 base address */
#define ADC_0_BASE                               (0x400A0000u)
/** Peripheral ADC_0 base pointer */
#define ADC_0                                    ((ADC_Type *)ADC_0_BASE)
/** Peripheral ADC_1 base address */
#define ADC_1_BASE                               (0x400A4000u)
/** Peripheral ADC_1 base pointer */
#define ADC_1                                    ((ADC_Type *)ADC_1_BASE)
/** Peripheral ADC_2 base address */
#define ADC_2_BASE                               (0x400A8000u)
/** Peripheral ADC_2 base pointer */
#define ADC_2                                    ((ADC_Type *)ADC_2_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC_0_BASE, ADC_1_BASE, ADC_2_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC_0, ADC_1, ADC_2 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn, ADC1_IRQn, ADC2_IRQn }

/* AXBS_LITE - Peripheral instance base addresses */
/** Peripheral AXBS_LITE base address */
#define AXBS_LITE_BASE                           (0x40200000u)
/** Peripheral AXBS_LITE base pointer */
#define AXBS_LITE                                ((AXBS_LITE_Type *)AXBS_LITE_BASE)
/** Array initializer of AXBS_LITE peripheral base addresses */
#define AXBS_LITE_BASE_ADDRS                     { AXBS_LITE_BASE }
/** Array initializer of AXBS_LITE peripheral base pointers */
#define AXBS_LITE_BASE_PTRS                      { AXBS_LITE }

/* BCTU - Peripheral instance base addresses */
/** Peripheral BCTU base address */
#define BCTU_BASE                                (0x40084000u)
/** Peripheral BCTU base pointer */
#define BCTU                                     ((BCTU_Type *)BCTU_BASE)
/** Array initializer of BCTU peripheral base addresses */
#define BCTU_BASE_ADDRS                          { BCTU_BASE }
/** Array initializer of BCTU peripheral base pointers */
#define BCTU_BASE_PTRS                           { BCTU }

/* CAN - Peripheral instance base addresses */
/** Peripheral FLEXCAN_0 base address */
#define FLEXCAN_0_BASE                           (0x40304000u)
/** Peripheral FLEXCAN_0 base pointer */
#define FLEXCAN_0                                ((CAN_Type *)FLEXCAN_0_BASE)
/** Peripheral FLEXCAN_1 base address */
#define FLEXCAN_1_BASE                           (0x40308000u)
/** Peripheral FLEXCAN_1 base pointer */
#define FLEXCAN_1                                ((CAN_Type *)FLEXCAN_1_BASE)
/** Peripheral FLEXCAN_2 base address */
#define FLEXCAN_2_BASE                           (0x4030C000u)
/** Peripheral FLEXCAN_2 base pointer */
#define FLEXCAN_2                                ((CAN_Type *)FLEXCAN_2_BASE)
/** Peripheral FLEXCAN_3 base address */
#define FLEXCAN_3_BASE                           (0x40310000u)
/** Peripheral FLEXCAN_3 base pointer */
#define FLEXCAN_3                                ((CAN_Type *)FLEXCAN_3_BASE)
/** Peripheral FLEXCAN_4 base address */
#define FLEXCAN_4_BASE                           (0x40314000u)
/** Peripheral FLEXCAN_4 base pointer */
#define FLEXCAN_4                                ((CAN_Type *)FLEXCAN_4_BASE)
/** Peripheral FLEXCAN_5 base address */
#define FLEXCAN_5_BASE                           (0x40318000u)
/** Peripheral FLEXCAN_5 base pointer */
#define FLEXCAN_5                                ((CAN_Type *)FLEXCAN_5_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { FLEXCAN_0_BASE, FLEXCAN_1_BASE, FLEXCAN_2_BASE, FLEXCAN_3_BASE, FLEXCAN_4_BASE, FLEXCAN_5_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { FLEXCAN_0, FLEXCAN_1, FLEXCAN_2, FLEXCAN_3, FLEXCAN_4, FLEXCAN_5 }
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { FlexCAN0_0_IRQn, FlexCAN1_0_IRQn, FlexCAN2_0_IRQn, FlexCAN3_0_IRQn, FlexCAN4_0_IRQn, FlexCAN5_0_IRQn }
#define CAN_Tx_Warning_IRQS                      { FlexCAN0_0_IRQn, FlexCAN1_0_IRQn, FlexCAN2_0_IRQn, FlexCAN3_0_IRQn, FlexCAN4_0_IRQn, FlexCAN5_0_IRQn }
#define CAN_Wake_Up_IRQS                         { FlexCAN0_0_IRQn, FlexCAN1_0_IRQn, FlexCAN2_0_IRQn, FlexCAN3_0_IRQn, FlexCAN4_0_IRQn, FlexCAN5_0_IRQn }
#define CAN_Error_IRQS                           { FlexCAN0_0_IRQn, FlexCAN1_0_IRQn, FlexCAN2_0_IRQn, FlexCAN3_0_IRQn, FlexCAN4_0_IRQn, FlexCAN5_0_IRQn }
#define CAN_Bus_Off_IRQS                         { FlexCAN0_0_IRQn, FlexCAN1_0_IRQn, FlexCAN2_0_IRQn, FlexCAN3_0_IRQn, FlexCAN4_0_IRQn, FlexCAN5_0_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { { FlexCAN0_1_IRQn, FlexCAN0_2_IRQn, FlexCAN0_3_IRQn }, { FlexCAN1_1_IRQn, FlexCAN1_2_IRQn, NotAvail_IRQn }, { FlexCAN2_1_IRQn, FlexCAN2_2_IRQn, NotAvail_IRQn }, { FlexCAN3_1_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { FlexCAN4_1_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { FlexCAN5_1_IRQn, NotAvail_IRQn, NotAvail_IRQn } }

/* CMU_FC - Peripheral instance base addresses */
/** Peripheral CMU_0 base address */
#define CMU_0_BASE                               (0x402BC000u)
/** Peripheral CMU_0 base pointer */
#define CMU_0                                    ((CMU_FC_Type *)CMU_0_BASE)
/** Peripheral CMU_3 base address */
#define CMU_3_BASE                               (0x402BC060u)
/** Peripheral CMU_3 base pointer */
#define CMU_3                                    ((CMU_FC_Type *)CMU_3_BASE)
/** Peripheral CMU_4 base address */
#define CMU_4_BASE                               (0x402BC080u)
/** Peripheral CMU_4 base pointer */
#define CMU_4                                    ((CMU_FC_Type *)CMU_4_BASE)
/** Peripheral CMU_5 base address */
#define CMU_5_BASE                               (0x402BC0A0u)
/** Peripheral CMU_5 base pointer */
#define CMU_5                                    ((CMU_FC_Type *)CMU_5_BASE)
/** Array initializer of CMU_FC peripheral base addresses */
#define CMU_FC_BASE_ADDRS                        { CMU_0_BASE, CMU_3_BASE, CMU_4_BASE, CMU_5_BASE }
/** Array initializer of CMU_FC peripheral base pointers */
#define CMU_FC_BASE_PTRS                         { CMU_0, CMU_3, CMU_4, CMU_5 }

/* CMU_FM - Peripheral instance base addresses */
/** Peripheral CMU_1 base address */
#define CMU_1_BASE                               (0x402BC020u)
/** Peripheral CMU_1 base pointer */
#define CMU_1                                    ((CMU_FM_Type *)CMU_1_BASE)
/** Peripheral CMU_2 base address */
#define CMU_2_BASE                               (0x402BC040u)
/** Peripheral CMU_2 base pointer */
#define CMU_2                                    ((CMU_FM_Type *)CMU_2_BASE)
/** Array initializer of CMU_FM peripheral base addresses */
#define CMU_FM_BASE_ADDRS                        { CMU_1_BASE, CMU_2_BASE }
/** Array initializer of CMU_FM peripheral base pointers */
#define CMU_FM_BASE_PTRS                         { CMU_1, CMU_2 }

/* CONFIGURATION - Peripheral instance base addresses */
/** Peripheral CONFIGURATION base address */
#define CONFIGURATION_BASE                       (0x4039C000u)
/** Peripheral CONFIGURATION base pointer */
#define CONFIGURATION                            ((CONFIGURATION_Type *)CONFIGURATION_BASE)
/** Array initializer of CONFIGURATION peripheral base addresses */
#define CONFIGURATION_BASE_ADDRS                 { CONFIGURATION_BASE }
/** Array initializer of CONFIGURATION peripheral base pointers */
#define CONFIGURATION_BASE_PTRS                  { CONFIGURATION }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base address */
#define CRC_BASE                                 (0x40380000u)
/** Peripheral CRC base pointer */
#define CRC                                      ((CRC_Type *)CRC_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC }

/* DCM - Peripheral instance base addresses */
/** Peripheral DCM base address */
#define DCM_BASE                                 (0x402AC000u)
/** Peripheral DCM base pointer */
#define DCM                                      ((DCM_Type *)DCM_BASE)
/** Array initializer of DCM peripheral base addresses */
#define DCM_BASE_ADDRS                           { DCM_BASE }
/** Array initializer of DCM peripheral base pointers */
#define DCM_BASE_PTRS                            { DCM }

/* DCM_GPR - Peripheral instance base addresses */
/** Peripheral DCM_GPR base address */
#define DCM_GPR_BASE                             (0x402AC000u)
/** Peripheral DCM_GPR base pointer */
#define DCM_GPR                                  ((DCM_GPR_Type *)DCM_GPR_BASE)
/** Array initializer of DCM_GPR peripheral base addresses */
#define DCM_GPR_BASE_ADDRS                       { DCM_GPR_BASE }
/** Array initializer of DCM_GPR peripheral base pointers */
#define DCM_GPR_BASE_PTRS                        { DCM_GPR }

/* DMA - Peripheral instance base addresses */
/** Peripheral EDMA base address */
#define EDMA_BASE                                (0x4020C000u)
/** Peripheral EDMA base pointer */
#define EDMA                                     ((DMA_Type *)EDMA_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { EDMA_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { EDMA }

/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX_0 base address */
#define DMAMUX_0_BASE                            (0x40280000u)
/** Peripheral DMAMUX_0 base pointer */
#define DMAMUX_0                                 ((DMAMUX_Type *)DMAMUX_0_BASE)
/** Peripheral DMAMUX_1 base address */
#define DMAMUX_1_BASE                            (0x40284000u)
/** Peripheral DMAMUX_1 base pointer */
#define DMAMUX_1                                 ((DMAMUX_Type *)DMAMUX_1_BASE)
/** Array initializer of DMAMUX peripheral base addresses */
#define DMAMUX_BASE_ADDRS                        { DMAMUX_0_BASE, DMAMUX_1_BASE }
/** Array initializer of DMAMUX peripheral base pointers */
#define DMAMUX_BASE_PTRS                         { DMAMUX_0, DMAMUX_1 }

/* EIM - Peripheral instance base addresses */
/** Peripheral EIM base address */
#define EIM_BASE                                 (0x40258000u)
/** Peripheral EIM base pointer */
#define EIM                                      ((EIM_Type *)EIM_BASE)
/** Array initializer of EIM peripheral base addresses */
#define EIM_BASE_ADDRS                           { EIM_BASE }
/** Array initializer of EIM peripheral base pointers */
#define EIM_BASE_PTRS                            { EIM }

/* EMAC - Peripheral instance base addresses */
/** Peripheral EMAC base address */
#define EMAC_BASE                                (0x40480000u)
/** Peripheral EMAC base pointer */
#define EMAC                                     ((EMAC_Type *)EMAC_BASE)
/** Array initializer of EMAC peripheral base addresses */
#define EMAC_BASE_ADDRS                          { EMAC_BASE }
/** Array initializer of EMAC peripheral base pointers */
#define EMAC_BASE_PTRS                           { EMAC }

/* EMIOS - Peripheral instance base addresses */
/** Peripheral EMIOS_0 base address */
#define EMIOS_0_BASE                             (0x40088000u)
/** Peripheral EMIOS_0 base pointer */
#define EMIOS_0                                  ((EMIOS_Type *)EMIOS_0_BASE)
/** Peripheral EMIOS_1 base address */
#define EMIOS_1_BASE                             (0x4008C000u)
/** Peripheral EMIOS_1 base pointer */
#define EMIOS_1                                  ((EMIOS_Type *)EMIOS_1_BASE)
/** Peripheral EMIOS_2 base address */
#define EMIOS_2_BASE                             (0x40090000u)
/** Peripheral EMIOS_2 base pointer */
#define EMIOS_2                                  ((EMIOS_Type *)EMIOS_2_BASE)
/** Array initializer of EMIOS peripheral base addresses */
#define EMIOS_BASE_ADDRS                         { EMIOS_0_BASE, EMIOS_1_BASE, EMIOS_2_BASE }
/** Array initializer of EMIOS peripheral base pointers */
#define EMIOS_BASE_PTRS                          { EMIOS_0, EMIOS_1, EMIOS_2 }

/* ERM - Peripheral instance base addresses */
/** Peripheral ERM base address */
#define ERM_BASE                                 (0x4025C000u)
/** Peripheral ERM base pointer */
#define ERM                                      ((ERM_Type *)ERM_BASE)
/** Array initializer of ERM peripheral base addresses */
#define ERM_BASE_ADDRS                           { ERM_BASE }
/** Array initializer of ERM peripheral base pointers */
#define ERM_BASE_PTRS                            { ERM }

/* FCCU - Peripheral instance base addresses */
/** Peripheral FCCU base address */
#define FCCU_BASE                                (0x40384000u)
/** Peripheral FCCU base pointer */
#define FCCU                                     ((FCCU_Type *)FCCU_BASE)
/** Array initializer of FCCU peripheral base addresses */
#define FCCU_BASE_ADDRS                          { FCCU_BASE }
/** Array initializer of FCCU peripheral base pointers */
#define FCCU_BASE_PTRS                           { FCCU }

/* FIRC - Peripheral instance base addresses */
/** Peripheral FIRC base address */
#define FIRC_BASE                                (0x402D0000u)
/** Peripheral FIRC base pointer */
#define FIRC                                     ((FIRC_Type *)FIRC_BASE)
/** Array initializer of FIRC peripheral base addresses */
#define FIRC_BASE_ADDRS                          { FIRC_BASE }
/** Array initializer of FIRC peripheral base pointers */
#define FIRC_BASE_PTRS                           { FIRC }

/* FLASH - Peripheral instance base addresses */
/** Peripheral FLASH base address */
#define FLASH_BASE                               (0x402EC000u)
/** Peripheral FLASH base pointer */
#define FLASH                                    ((FLASH_Type *)FLASH_BASE)
/** Array initializer of FLASH peripheral base addresses */
#define FLASH_BASE_ADDRS                         { FLASH_BASE }
/** Array initializer of FLASH peripheral base pointers */
#define FLASH_BASE_PTRS                          { FLASH }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO base address */
#define FLEXIO_BASE                              (0x40324000u)
/** Peripheral FLEXIO base pointer */
#define FLEXIO                                   ((FLEXIO_Type *)FLEXIO_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { FLEXIO_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { FLEXIO }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { FLEXIO_IRQn }

/* FXOSC - Peripheral instance base addresses */
/** Peripheral FXOSC base address */
#define FXOSC_BASE                               (0x402D4000u)
/** Peripheral FXOSC base pointer */
#define FXOSC                                    ((FXOSC_Type *)FXOSC_BASE)
/** Array initializer of FXOSC peripheral base addresses */
#define FXOSC_BASE_ADDRS                         { FXOSC_BASE }
/** Array initializer of FXOSC peripheral base pointers */
#define FXOSC_BASE_PTRS                          { FXOSC }

/* I2S - Peripheral instance base addresses */
/** Peripheral SAI_0 base address */
#define SAI_0_BASE                               (0x4036C000u)
/** Peripheral SAI_0 base pointer */
#define SAI_0                                    ((I2S_Type *)SAI_0_BASE)
/** Peripheral SAI_1 base address */
#define SAI_1_BASE                               (0x404DC000u)
/** Peripheral SAI_1 base pointer */
#define SAI_1                                    ((I2S_Type *)SAI_1_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { SAI_0_BASE, SAI_1_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { SAI_0, SAI_1 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { SAI0_IRQn, SAI1_IRQn }
#define I2S_TX_IRQS                              { SAI0_IRQn, SAI1_IRQn }

/* INTM - Peripheral instance base addresses */
/** Peripheral INTM base address */
#define INTM_BASE                                (0x4027C000u)
/** Peripheral INTM base pointer */
#define INTM                                     ((INTM_Type *)INTM_BASE)
/** Array initializer of INTM peripheral base addresses */
#define INTM_BASE_ADDRS                          { INTM_BASE }
/** Array initializer of INTM peripheral base pointers */
#define INTM_BASE_PTRS                           { INTM }

/* JDC - Peripheral instance base addresses */
/** Peripheral JDC base address */
#define JDC_BASE                                 (0x40394000u)
/** Peripheral JDC base pointer */
#define JDC                                      ((JDC_Type *)JDC_BASE)
/** Array initializer of JDC peripheral base addresses */
#define JDC_BASE_ADDRS                           { JDC_BASE }
/** Array initializer of JDC peripheral base pointers */
#define JDC_BASE_PTRS                            { JDC }

/* LCU - Peripheral instance base addresses */
/** Peripheral LCU_0 base address */
#define LCU_0_BASE                               (0x40098000u)
/** Peripheral LCU_0 base pointer */
#define LCU_0                                    ((LCU_Type *)LCU_0_BASE)
/** Peripheral LCU_1 base address */
#define LCU_1_BASE                               (0x4009C000u)
/** Peripheral LCU_1 base pointer */
#define LCU_1                                    ((LCU_Type *)LCU_1_BASE)
/** Array initializer of LCU peripheral base addresses */
#define LCU_BASE_ADDRS                           { LCU_0_BASE, LCU_1_BASE }
/** Array initializer of LCU peripheral base pointers */
#define LCU_BASE_PTRS                            { LCU_0, LCU_1 }
/** Interrupt vectors for the LCU peripheral type */
#define LCU_IRQS                                 { LCU0_IRQn, LCU1_IRQn }

/* LPCMP - Peripheral instance base addresses */
/** Peripheral LPCMP_0 base address */
#define LPCMP_0_BASE                             (0x40370000u)
/** Peripheral LPCMP_0 base pointer */
#define LPCMP_0                                  ((LPCMP_Type *)LPCMP_0_BASE)
/** Peripheral LPCMP_1 base address */
#define LPCMP_1_BASE                             (0x40374000u)
/** Peripheral LPCMP_1 base pointer */
#define LPCMP_1                                  ((LPCMP_Type *)LPCMP_1_BASE)
/** Peripheral LPCMP_2 base address */
#define LPCMP_2_BASE                             (0x404E8000u)
/** Peripheral LPCMP_2 base pointer */
#define LPCMP_2                                  ((LPCMP_Type *)LPCMP_2_BASE)
/** Array initializer of LPCMP peripheral base addresses */
#define LPCMP_BASE_ADDRS                         { LPCMP_0_BASE, LPCMP_1_BASE, LPCMP_2_BASE }
/** Array initializer of LPCMP peripheral base pointers */
#define LPCMP_BASE_PTRS                          { LPCMP_0, LPCMP_1, LPCMP_2 }
/** Interrupt vectors for the LPCMP peripheral type */
#define LPCMP_IRQS                               { CMP0_IRQn, CMP1_IRQn, CMP2_IRQn }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C_0 base address */
#define LPI2C_0_BASE                             (0x40350000u)
/** Peripheral LPI2C_0 base pointer */
#define LPI2C_0                                  ((LPI2C_Type *)LPI2C_0_BASE)
/** Peripheral LPI2C_1 base address */
#define LPI2C_1_BASE                             (0x40354000u)
/** Peripheral LPI2C_1 base pointer */
#define LPI2C_1                                  ((LPI2C_Type *)LPI2C_1_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C_0_BASE, LPI2C_1_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C_0, LPI2C_1 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI_0 base address */
#define LPSPI_0_BASE                             (0x40358000u)
/** Peripheral LPSPI_0 base pointer */
#define LPSPI_0                                  ((LPSPI_Type *)LPSPI_0_BASE)
/** Peripheral LPSPI_1 base address */
#define LPSPI_1_BASE                             (0x4035C000u)
/** Peripheral LPSPI_1 base pointer */
#define LPSPI_1                                  ((LPSPI_Type *)LPSPI_1_BASE)
/** Peripheral LPSPI_2 base address */
#define LPSPI_2_BASE                             (0x40360000u)
/** Peripheral LPSPI_2 base pointer */
#define LPSPI_2                                  ((LPSPI_Type *)LPSPI_2_BASE)
/** Peripheral LPSPI_3 base address */
#define LPSPI_3_BASE                             (0x40364000u)
/** Peripheral LPSPI_3 base pointer */
#define LPSPI_3                                  ((LPSPI_Type *)LPSPI_3_BASE)
/** Peripheral LPSPI_4 base address */
#define LPSPI_4_BASE                             (0x404BC000u)
/** Peripheral LPSPI_4 base pointer */
#define LPSPI_4                                  ((LPSPI_Type *)LPSPI_4_BASE)
/** Peripheral LPSPI_5 base address */
#define LPSPI_5_BASE                             (0x404C0000u)
/** Peripheral LPSPI_5 base pointer */
#define LPSPI_5                                  ((LPSPI_Type *)LPSPI_5_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI_0_BASE, LPSPI_1_BASE, LPSPI_2_BASE, LPSPI_3_BASE, LPSPI_4_BASE, LPSPI_5_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI_0, LPSPI_1, LPSPI_2, LPSPI_3, LPSPI_4, LPSPI_5 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, LPSPI4_IRQn, LPSPI5_IRQn }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART_0 base address */
#define LPUART_0_BASE                            (0x40328000u)
/** Peripheral LPUART_0 base pointer */
#define LPUART_0                                 ((LPUART_Type *)LPUART_0_BASE)
/** Peripheral LPUART_1 base address */
#define LPUART_1_BASE                            (0x4032C000u)
/** Peripheral LPUART_1 base pointer */
#define LPUART_1                                 ((LPUART_Type *)LPUART_1_BASE)
/** Peripheral LPUART_2 base address */
#define LPUART_2_BASE                            (0x40330000u)
/** Peripheral LPUART_2 base pointer */
#define LPUART_2                                 ((LPUART_Type *)LPUART_2_BASE)
/** Peripheral LPUART_3 base address */
#define LPUART_3_BASE                            (0x40334000u)
/** Peripheral LPUART_3 base pointer */
#define LPUART_3                                 ((LPUART_Type *)LPUART_3_BASE)
/** Peripheral LPUART_4 base address */
#define LPUART_4_BASE                            (0x40338000u)
/** Peripheral LPUART_4 base pointer */
#define LPUART_4                                 ((LPUART_Type *)LPUART_4_BASE)
/** Peripheral LPUART_5 base address */
#define LPUART_5_BASE                            (0x4033C000u)
/** Peripheral LPUART_5 base pointer */
#define LPUART_5                                 ((LPUART_Type *)LPUART_5_BASE)
/** Peripheral LPUART_6 base address */
#define LPUART_6_BASE                            (0x40340000u)
/** Peripheral LPUART_6 base pointer */
#define LPUART_6                                 ((LPUART_Type *)LPUART_6_BASE)
/** Peripheral LPUART_7 base address */
#define LPUART_7_BASE                            (0x40344000u)
/** Peripheral LPUART_7 base pointer */
#define LPUART_7                                 ((LPUART_Type *)LPUART_7_BASE)
/** Peripheral LPUART_8 base address */
#define LPUART_8_BASE                            (0x4048C000u)
/** Peripheral LPUART_8 base pointer */
#define LPUART_8                                 ((LPUART_Type *)LPUART_8_BASE)
/** Peripheral LPUART_9 base address */
#define LPUART_9_BASE                            (0x40490000u)
/** Peripheral LPUART_9 base pointer */
#define LPUART_9                                 ((LPUART_Type *)LPUART_9_BASE)
/** Peripheral LPUART_10 base address */
#define LPUART_10_BASE                           (0x40494000u)
/** Peripheral LPUART_10 base pointer */
#define LPUART_10                                ((LPUART_Type *)LPUART_10_BASE)
/** Peripheral LPUART_11 base address */
#define LPUART_11_BASE                           (0x40498000u)
/** Peripheral LPUART_11 base pointer */
#define LPUART_11                                ((LPUART_Type *)LPUART_11_BASE)
/** Peripheral LPUART_12 base address */
#define LPUART_12_BASE                           (0x4049C000u)
/** Peripheral LPUART_12 base pointer */
#define LPUART_12                                ((LPUART_Type *)LPUART_12_BASE)
/** Peripheral LPUART_13 base address */
#define LPUART_13_BASE                           (0x404A0000u)
/** Peripheral LPUART_13 base pointer */
#define LPUART_13                                ((LPUART_Type *)LPUART_13_BASE)
/** Peripheral LPUART_14 base address */
#define LPUART_14_BASE                           (0x404A4000u)
/** Peripheral LPUART_14 base pointer */
#define LPUART_14                                ((LPUART_Type *)LPUART_14_BASE)
/** Peripheral LPUART_15 base address */
#define LPUART_15_BASE                           (0x404A8000u)
/** Peripheral LPUART_15 base pointer */
#define LPUART_15                                ((LPUART_Type *)LPUART_15_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART_0_BASE, LPUART_1_BASE, LPUART_2_BASE, LPUART_3_BASE, LPUART_4_BASE, LPUART_5_BASE, LPUART_6_BASE, LPUART_7_BASE, LPUART_8_BASE, LPUART_9_BASE, LPUART_10_BASE, LPUART_11_BASE, LPUART_12_BASE, LPUART_13_BASE, LPUART_14_BASE, LPUART_15_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART_0, LPUART_1, LPUART_2, LPUART_3, LPUART_4, LPUART_5, LPUART_6, LPUART_7, LPUART_8, LPUART_9, LPUART_10, LPUART_11, LPUART_12, LPUART_13, LPUART_14, LPUART_15 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART_0_IRQn, LPUART_1_IRQn, LPUART_2_IRQn, LPUART_3_IRQn, LPUART_4_IRQn, LPUART_5_IRQn, LPUART_6_IRQn, LPUART_7_IRQn, LPUART_8_IRQn, LPUART_9_IRQn, LPUART_10_IRQn, LPUART_11_IRQn, LPUART_12_IRQn, LPUART_13_IRQn, LPUART_14_IRQn, LPUART_15_IRQn }

/* MCM - Peripheral instance base addresses */
/** Peripheral MCM_0 base address */
#define MCM_0_BASE                               (0xE0080000u)
/** Peripheral MCM_0 base pointer */
#define MCM_0                                    ((MCM_Type *)MCM_0_BASE)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS                           { MCM_0_BASE }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM_0 }

/* MC_CGM - Peripheral instance base addresses */
/** Peripheral MC_CGM base address */
#define MC_CGM_BASE                              (0x402D8000u)
/** Peripheral MC_CGM base pointer */
#define MC_CGM                                   ((MC_CGM_Type *)MC_CGM_BASE)
/** Array initializer of MC_CGM peripheral base addresses */
#define MC_CGM_BASE_ADDRS                        { MC_CGM_BASE }
/** Array initializer of MC_CGM peripheral base pointers */
#define MC_CGM_BASE_PTRS                         { MC_CGM }

/* MC_ME - Peripheral instance base addresses */
/** Peripheral MC_ME base address */
#define MC_ME_BASE                               (0x402DC000u)
/** Peripheral MC_ME base pointer */
#define MC_ME                                    ((MC_ME_Type *)MC_ME_BASE)
/** Array initializer of MC_ME peripheral base addresses */
#define MC_ME_BASE_ADDRS                         { MC_ME_BASE }
/** Array initializer of MC_ME peripheral base pointers */
#define MC_ME_BASE_PTRS                          { MC_ME }

/* MC_RGM - Peripheral instance base addresses */
/** Peripheral MC_RGM base address */
#define MC_RGM_BASE                              (0x4028C000u)
/** Peripheral MC_RGM base pointer */
#define MC_RGM                                   ((MC_RGM_Type *)MC_RGM_BASE)
/** Array initializer of MC_RGM peripheral base addresses */
#define MC_RGM_BASE_ADDRS                        { MC_RGM_BASE }
/** Array initializer of MC_RGM peripheral base pointers */
#define MC_RGM_BASE_PTRS                         { MC_RGM }

/* MDM_AP - Peripheral instance base addresses */
/** Peripheral MDM_AP base address */
#define MDM_AP_BASE                              (0x40250600u)
/** Peripheral MDM_AP base pointer */
#define MDM_AP                                   ((MDM_AP_Type *)MDM_AP_BASE)
/** Array initializer of MDM_AP peripheral base addresses */
#define MDM_AP_BASE_ADDRS                        { MDM_AP_BASE }
/** Array initializer of MDM_AP peripheral base pointers */
#define MDM_AP_BASE_PTRS                         { MDM_AP }

/* MSCM - Peripheral instance base addresses */
/** Peripheral MSCM base address */
#define MSCM_BASE                                (0x40260000u)
/** Peripheral MSCM base pointer */
#define MSCM                                     ((MSCM_Type *)MSCM_BASE)
/** Array initializer of MSCM peripheral base addresses */
#define MSCM_BASE_ADDRS                          { MSCM_BASE }
/** Array initializer of MSCM peripheral base pointers */
#define MSCM_BASE_PTRS                           { MSCM }

/* MU - Peripheral instance base addresses */
/** Peripheral MU0_B base address */
#define MU0_B_BASE                               (0x4038C000u)
/** Peripheral MU0_B base pointer */
#define MU0_B                                    ((MU_Type *)MU0_B_BASE)
/** Peripheral MU1_B base address */
#define MU1_B_BASE                               (0x404EC000u)
/** Peripheral MU1_B base pointer */
#define MU1_B                                    ((MU_Type *)MU1_B_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MU0_B_BASE, MU1_B_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MU0_B, MU1_B }

/* PFLASH - Peripheral instance base addresses */
/** Peripheral PFLASH base address */
#define PFLASH_BASE                              (0x40268000u)
/** Peripheral PFLASH base pointer */
#define PFLASH                                   ((PFLASH_Type *)PFLASH_BASE)
/** Array initializer of PFLASH peripheral base addresses */
#define PFLASH_BASE_ADDRS                        { PFLASH_BASE }
/** Array initializer of PFLASH peripheral base pointers */
#define PFLASH_BASE_PTRS                         { PFLASH }

/* PIT - Peripheral instance base addresses */
/** Peripheral PIT_0 base address */
#define PIT_0_BASE                               (0x400B0000u)
/** Peripheral PIT_0 base pointer */
#define PIT_0                                    ((PIT_Type *)PIT_0_BASE)
/** Peripheral PIT_1 base address */
#define PIT_1_BASE                               (0x400B4000u)
/** Peripheral PIT_1 base pointer */
#define PIT_1                                    ((PIT_Type *)PIT_1_BASE)
/** Peripheral PIT_2 base address */
#define PIT_2_BASE                               (0x402FC000u)
/** Peripheral PIT_2 base pointer */
#define PIT_2                                    ((PIT_Type *)PIT_2_BASE)
/** Array initializer of PIT peripheral base addresses */
#define PIT_BASE_ADDRS                           { PIT_0_BASE, PIT_1_BASE, PIT_2_BASE }
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            { PIT_0, PIT_1, PIT_2 }
/** Interrupt vectors for the PIT peripheral type */
#define PIT_IRQS                                 { { PIT0_IRQn, PIT0_IRQn, PIT0_IRQn, PIT0_IRQn }, { PIT1_IRQn, PIT1_IRQn, PIT1_IRQn, PIT1_IRQn }, { PIT2_IRQn, PIT2_IRQn, PIT2_IRQn, PIT2_IRQn } }

/* PLL - Peripheral instance base addresses */
/** Peripheral PLL base address */
#define PLL_BASE                                 (0x402E0000u)
/** Peripheral PLL base pointer */
#define PLL                                      ((PLL_Type *)PLL_BASE)
/** Array initializer of PLL peripheral base addresses */
#define PLL_BASE_ADDRS                           { PLL_BASE }
/** Array initializer of PLL peripheral base pointers */
#define PLL_BASE_PTRS                            { PLL }

/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base address */
#define PMC_BASE                                 (0x402E8000u)
/** Peripheral PMC base pointer */
#define PMC                                      ((PMC_Type *)PMC_BASE)
/** Array initializer of PMC peripheral base addresses */
#define PMC_BASE_ADDRS                           { PMC_BASE }
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASE_PTRS                            { PMC }

/* PRAMC - Peripheral instance base addresses */
/** Peripheral PRAMC_0 base address */
#define PRAMC_0_BASE                             (0x40264000u)
/** Peripheral PRAMC_0 base pointer */
#define PRAMC_0                                  ((PRAMC_Type *)PRAMC_0_BASE)
/** Peripheral PRAMC_1 base address */
#define PRAMC_1_BASE                             (0x40464000u)
/** Peripheral PRAMC_1 base pointer */
#define PRAMC_1                                  ((PRAMC_Type *)PRAMC_1_BASE)
/** Array initializer of PRAMC peripheral base addresses */
#define PRAMC_BASE_ADDRS                         { PRAMC_0_BASE, PRAMC_1_BASE }
/** Array initializer of PRAMC peripheral base pointers */
#define PRAMC_BASE_PTRS                          { PRAMC_0, PRAMC_1 }

/* QuadSPI - Peripheral instance base addresses */
/** Peripheral QUADSPI base address */
#define QUADSPI_BASE                             (0x404CC000u)
/** Peripheral QUADSPI base pointer */
#define QUADSPI                                  ((QuadSPI_Type *)QUADSPI_BASE)
/** Array initializer of QuadSPI peripheral base addresses */
#define QuadSPI_BASE_ADDRS                       { QUADSPI_BASE }
/** Array initializer of QuadSPI peripheral base pointers */
#define QuadSPI_BASE_PTRS                        { QUADSPI }
/** Interrupt vectors for the QuadSPI peripheral type */
#define QuadSPI_IRQS                             { QSPI_IRQn }

/* QuadSPI_ARDB - Peripheral instance base addresses */
/** Peripheral QUADSPI_ARDB base address */
#define QUADSPI_ARDB_BASE                        (0x68000000u)
/** Peripheral QUADSPI_ARDB base pointer */
#define QUADSPI_ARDB                             ((QuadSPI_ARDB_Type *)QUADSPI_ARDB_BASE)
/** Array initializer of QuadSPI_ARDB peripheral base addresses */
#define QuadSPI_ARDB_BASE_ADDRS                  { QUADSPI_ARDB_BASE }
/** Array initializer of QuadSPI_ARDB peripheral base pointers */
#define QuadSPI_ARDB_BASE_PTRS                   { QUADSPI_ARDB }

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x40288000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }

/* SDA_AP - Peripheral instance base addresses */
/** Peripheral SDA_AP base address */
#define SDA_AP_BASE                              (0x40254700u)
/** Peripheral SDA_AP base pointer */
#define SDA_AP                                   ((SDA_AP_Type *)SDA_AP_BASE)
/** Array initializer of SDA_AP peripheral base addresses */
#define SDA_AP_BASE_ADDRS                        { SDA_AP_BASE }
/** Array initializer of SDA_AP peripheral base pointers */
#define SDA_AP_BASE_PTRS                         { SDA_AP }

/* SELFTEST - Peripheral instance base addresses */
/** Peripheral SELFTEST base address */
#define SELFTEST_BASE                            (0x403B0000u)
/** Peripheral SELFTEST base pointer */
#define SELFTEST                                 ((SELFTEST_Type *)SELFTEST_BASE)
/** Array initializer of SELFTEST peripheral base addresses */
#define SELFTEST_BASE_ADDRS                      { SELFTEST_BASE }
/** Array initializer of SELFTEST peripheral base pointers */
#define SELFTEST_BASE_PTRS                       { SELFTEST }

/* SEMA42 - Peripheral instance base addresses */
/** Peripheral SEMA42 base address */
#define SEMA42_BASE                              (0x40460000u)
/** Peripheral SEMA42 base pointer */
#define SEMA42                                   ((SEMA42_Type *)SEMA42_BASE)
/** Array initializer of SEMA42 peripheral base addresses */
#define SEMA42_BASE_ADDRS                        { SEMA42_BASE }
/** Array initializer of SEMA42 peripheral base pointers */
#define SEMA42_BASE_PTRS                         { SEMA42 }

/* SIRC - Peripheral instance base addresses */
/** Peripheral SIRC base address */
#define SIRC_BASE                                (0x402C8000u)
/** Peripheral SIRC base pointer */
#define SIRC                                     ((SIRC_Type *)SIRC_BASE)
/** Array initializer of SIRC peripheral base addresses */
#define SIRC_BASE_ADDRS                          { SIRC_BASE }
/** Array initializer of SIRC peripheral base pointers */
#define SIRC_BASE_PTRS                           { SIRC }

/* SIUL2 - Peripheral instance base addresses */
/** Peripheral SIUL2 base address */
#define SIUL2_BASE                               (0x40290000u)
/** Peripheral SIUL2 base pointer */
#define SIUL2                                    ((SIUL2_Type *)SIUL2_BASE)
/** Array initializer of SIUL2 peripheral base addresses */
#define SIUL2_BASE_ADDRS                         { SIUL2_BASE }
/** Array initializer of SIUL2 peripheral base pointers */
#define SIUL2_BASE_PTRS                          { SIUL2 }

/* STCU - Peripheral instance base addresses */
/** Peripheral STCU base address */
#define STCU_BASE                                (0x403A0000u)
/** Peripheral STCU base pointer */
#define STCU                                     ((STCU_Type *)STCU_BASE)
/** Array initializer of STCU peripheral base addresses */
#define STCU_BASE_ADDRS                          { STCU_BASE }
/** Array initializer of STCU peripheral base pointers */
#define STCU_BASE_PTRS                           { STCU }

/* STM - Peripheral instance base addresses */
/** Peripheral STM_0 base address */
#define STM_0_BASE                               (0x40274000u)
/** Peripheral STM_0 base pointer */
#define STM_0                                    ((STM_Type *)STM_0_BASE)
/** Peripheral STM_1 base address */
#define STM_1_BASE                               (0x40474000u)
/** Peripheral STM_1 base pointer */
#define STM_1                                    ((STM_Type *)STM_1_BASE)
/** Array initializer of STM peripheral base addresses */
#define STM_BASE_ADDRS                           { STM_0_BASE, STM_1_BASE }
/** Array initializer of STM peripheral base pointers */
#define STM_BASE_PTRS                            { STM_0, STM_1 }
/** Interrupt vectors for the STM peripheral type */
#define STM_IRQS                                 { STM0_IRQn, STM1_IRQn }

/* SWT - Peripheral instance base addresses */
/** Peripheral SWT_0 base address */
#define SWT_0_BASE                               (0x40270000u)
/** Peripheral SWT_0 base pointer */
#define SWT_0                                    ((SWT_Type *)SWT_0_BASE)
/** Array initializer of SWT peripheral base addresses */
#define SWT_BASE_ADDRS                           { SWT_0_BASE }
/** Array initializer of SWT peripheral base pointers */
#define SWT_BASE_PTRS                            { SWT_0 }
/** Interrupt vectors for the SWT peripheral type */
#define SWT_IRQS                                 { SWT0_IRQn }

/* SXOSC - Peripheral instance base addresses */
/** Peripheral SXOSC base address */
#define SXOSC_BASE                               (0x402CC000u)
/** Peripheral SXOSC base pointer */
#define SXOSC                                    ((SXOSC_Type *)SXOSC_BASE)
/** Array initializer of SXOSC peripheral base addresses */
#define SXOSC_BASE_ADDRS                         { SXOSC_BASE }
/** Array initializer of SXOSC peripheral base pointers */
#define SXOSC_BASE_PTRS                          { SXOSC }

/* TEMPSENSE - Peripheral instance base addresses */
/** Peripheral TEMPSENSE base address */
#define TEMPSENSE_BASE                           (0x4037C000u)
/** Peripheral TEMPSENSE base pointer */
#define TEMPSENSE                                ((TEMPSENSE_Type *)TEMPSENSE_BASE)
/** Array initializer of TEMPSENSE peripheral base addresses */
#define TEMPSENSE_BASE_ADDRS                     { TEMPSENSE_BASE }
/** Array initializer of TEMPSENSE peripheral base pointers */
#define TEMPSENSE_BASE_PTRS                      { TEMPSENSE }

/* TRGMUX - Peripheral instance base addresses */
/** Peripheral TRGMUX base address */
#define TRGMUX_BASE                              (0x40080000u)
/** Peripheral TRGMUX base pointer */
#define TRGMUX                                   ((TRGMUX_Type *)TRGMUX_BASE)
/** Array initializer of TRGMUX peripheral base addresses */
#define TRGMUX_BASE_ADDRS                        { TRGMUX_BASE }
/** Array initializer of TRGMUX peripheral base pointers */
#define TRGMUX_BASE_PTRS                         { TRGMUX }

/* TSPC - Peripheral instance base addresses */
/** Peripheral TSPC base address */
#define TSPC_BASE                                (0x402C4000u)
/** Peripheral TSPC base pointer */
#define TSPC                                     ((TSPC_Type *)TSPC_BASE)
/** Array initializer of TSPC peripheral base addresses */
#define TSPC_BASE_ADDRS                          { TSPC_BASE }
/** Array initializer of TSPC peripheral base pointers */
#define TSPC_BASE_PTRS                           { TSPC }

/* VIRT_WRAPPER - Peripheral instance base addresses */
/** Peripheral VIRT_WRAPPER base address */
#define VIRT_WRAPPER_BASE                        (0x402A8000u)
/** Peripheral VIRT_WRAPPER base pointer */
#define VIRT_WRAPPER                             ((VIRT_WRAPPER_Type *)VIRT_WRAPPER_BASE)
/** Array initializer of VIRT_WRAPPER peripheral base addresses */
#define VIRT_WRAPPER_BASE_ADDRS                  { VIRT_WRAPPER_BASE }
/** Array initializer of VIRT_WRAPPER peripheral base pointers */
#define VIRT_WRAPPER_BASE_PTRS                   { VIRT_WRAPPER }

/* WKPU - Peripheral instance base addresses */
/** Peripheral WKPU base address */
#define WKPU_BASE                                (0x402B4000u)
/** Peripheral WKPU base pointer */
#define WKPU                                     ((WKPU_Type *)WKPU_BASE)
/** Array initializer of WKPU peripheral base addresses */
#define WKPU_BASE_ADDRS                          { WKPU_BASE }
/** Array initializer of WKPU peripheral base pointers */
#define WKPU_BASE_PTRS                           { WKPU }

/* XBIC - Peripheral instance base addresses */
/** Peripheral XBIC_AXBS base address */
#define XBIC_AXBS_BASE                           (0x40204000u)
/** Peripheral XBIC_AXBS base pointer */
#define XBIC_AXBS                                ((XBIC_Type *)XBIC_AXBS_BASE)
/** Peripheral XBIC_AXBS_EDMA base address */
#define XBIC_AXBS_EDMA_BASE                      (0x40404000u)
/** Peripheral XBIC_AXBS_EDMA base pointer */
#define XBIC_AXBS_EDMA                           ((XBIC_Type *)XBIC_AXBS_EDMA_BASE)
/** Peripheral XBIC_AXBS_PERI base address */
#define XBIC_AXBS_PERI_BASE                      (0x40208000u)
/** Peripheral XBIC_AXBS_PERI base pointer */
#define XBIC_AXBS_PERI                           ((XBIC_Type *)XBIC_AXBS_PERI_BASE)
/** Peripheral XBIC_AXBS_TCM base address */
#define XBIC_AXBS_TCM_BASE                       (0x40400000u)
/** Peripheral XBIC_AXBS_TCM base pointer */
#define XBIC_AXBS_TCM                            ((XBIC_Type *)XBIC_AXBS_TCM_BASE)
/** Array initializer of XBIC peripheral base addresses */
#define XBIC_BASE_ADDRS                          { XBIC_AXBS_BASE, XBIC_AXBS_EDMA_BASE, XBIC_AXBS_PERI_BASE, XBIC_AXBS_TCM_BASE }
/** Array initializer of XBIC peripheral base pointers */
#define XBIC_BASE_PTRS                           { XBIC_AXBS, XBIC_AXBS_EDMA, XBIC_AXBS_PERI, XBIC_AXBS_TCM }

/* XRDC - Peripheral instance base addresses */
/** Peripheral XRDC base address */
#define XRDC_BASE                                (0x40278000u)
/** Peripheral XRDC base pointer */
#define XRDC                                     ((XRDC_Type *)XRDC_BASE)
/** Array initializer of XRDC peripheral base addresses */
#define XRDC_BASE_ADDRS                          { XRDC_BASE }
/** Array initializer of XRDC peripheral base pointers */
#define XRDC_BASE_PTRS                           { XRDC }

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


#endif  /* MCXE31B_COMMON_H_ */

