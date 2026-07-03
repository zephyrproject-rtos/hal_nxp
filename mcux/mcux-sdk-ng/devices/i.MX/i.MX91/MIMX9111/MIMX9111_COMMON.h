/*
** ###################################################################
**     Processors:          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX91RM Rev.1
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX9111
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MIMX9111_COMMON.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for MIMX9111
 *
 * CMSIS Peripheral Access Layer for MIMX9111
 */

#if !defined(MIMX9111_COMMON_H_)
#define MIMX9111_COMMON_H_                       /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 300                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  Software0_IRQn               = 0,                /**< Cortex-A55 Software Generated Interrupt 0 */
  Software1_IRQn               = 1,                /**< Cortex-A55 Software Generated Interrupt 1 */
  Software2_IRQn               = 2,                /**< Cortex-A55 Software Generated Interrupt 2 */
  Software3_IRQn               = 3,                /**< Cortex-A55 Software Generated Interrupt 3 */
  Software4_IRQn               = 4,                /**< Cortex-A55 Software Generated Interrupt 4 */
  Software5_IRQn               = 5,                /**< Cortex-A55 Software Generated Interrupt 5 */
  Software6_IRQn               = 6,                /**< Cortex-A55 Software Generated Interrupt 6 */
  Software7_IRQn               = 7,                /**< Cortex-A55 Software Generated Interrupt 7 */
  Software8_IRQn               = 8,                /**< Cortex-A55 Software Generated Interrupt 8 */
  Software9_IRQn               = 9,                /**< Cortex-A55 Software Generated Interrupt 9 */
  Software10_IRQn              = 10,               /**< Cortex-A55 Software Generated Interrupt 10 */
  Software11_IRQn              = 11,               /**< Cortex-A55 Software Generated Interrupt 11 */
  Software12_IRQn              = 12,               /**< Cortex-A55 Software Generated Interrupt 12 */
  Software13_IRQn              = 13,               /**< Cortex-A55 Software Generated Interrupt 13 */
  Software14_IRQn              = 14,               /**< Cortex-A55 Software Generated Interrupt 14 */
  Software15_IRQn              = 15,               /**< Cortex-A55 Software Generated Interrupt 15 */
  VirtualMaintenance_IRQn      = 25,               /**< Cortex-A55 Virtual Maintenance Interrupt */
  HypervisorTimer_IRQn         = 26,               /**< Cortex-A55 Hypervisor Timer Interrupt */
  VirtualTimer_IRQn            = 27,               /**< Cortex-A55 Virtual Timer Interrupt */
  LegacyFastInt_IRQn           = 28,               /**< Cortex-A55 Legacy nFIQ signal Interrupt */
  SecurePhyTimer_IRQn          = 29,               /**< Cortex-A55 Secure Physical Timer Interrupt */
  NonSecurePhyTimer_IRQn       = 30,               /**< Cortex-A55 Non-secure Physical Timer Interrupt */
  LegacyIRQ_IRQn               = 31,               /**< Cortex-A55 Legacy nIRQ Interrupt */

  /* Device specific interrupts */
  Reserved32_IRQn              = 32,               /**< Reserved interrupt */
  DAP_IRQn                     = 33,               /**< DAP interrupt */
  Reserved34_IRQn              = 34,               /**< Reserved interrupt */
  Reserved35_IRQn              = 35,               /**< Reserved interrupt */
  CTI_CA55_IRQn                = 36,               /**< CTI trigger outputs from CA55 platform */
  PMU_IRQn                     = 37,               /**< Performance Unit Interrupts from CA55 platform */
  CACHE_ECC_ERR_IRQn           = 38,               /**< ECC error from CA55 platform cache */
  CACHE_ECC_PARITY_ERR_IRQn    = 39,               /**< 1-bit or 2-bit ECC or Parity error from CA55 platform cache */
  CAN1_IRQn                    = 40,               /**< CAN1 interrupt */
  CAN1_ERROR_IRQn              = 41,               /**< CAN1 error interrupt */
  GPIO1_0_IRQn                 = 42,               /**< General Purpose Input/Output 1 interrupt 0 */
  GPIO1_1_IRQn                 = 43,               /**< General Purpose Input/Output 1 interrupt 1 */
  I3C1_IRQn                    = 44,               /**< Improved Inter-Integrated Circuit 1 interrupt */
  LPI2C1_IRQn                  = 45,               /**< Low Power Inter-Integrated Circuit module 1 */
  LPI2C2_IRQn                  = 46,               /**< Low Power Inter-Integrated Circuit module 2 */
  LPIT1_IRQn                   = 47,               /**< Low Power Periodic Interrupt Timer 1 */
  LPSPI1_IRQn                  = 48,               /**< Low Power Serial Peripheral Interface 1 */
  LPSPI2_IRQn                  = 49,               /**< Low Power Serial Peripheral Interface 2 */
  LPTMR1_IRQn                  = 50,               /**< Low Power Timer 1 */
  LPUART1_IRQn                 = 51,               /**< Low Power UART 1 */
  LPUART2_IRQn                 = 52,               /**< Low Power UART 2 */
  Reserved53_IRQn              = 53,               /**< Reserved interrupt */
  Reserved54_IRQn              = 54,               /**< Reserved interrupt */
  Reserved55_IRQn              = 55,               /**< Reserved interrupt */
  Reserved56_IRQn              = 56,               /**< Reserved interrupt */
  Reserved57_IRQn              = 57,               /**< Reserved interrupt */
  Reserved58_IRQn              = 58,               /**< Reserved interrupt */
  Reserved59_IRQn              = 59,               /**< Reserved interrupt */
  EDGELOCK_TRUST_MUA_RX_IRQn   = 60,               /**< Edgelock Trust MUA RX full interrupt */
  EDGELOCK_TRUST_MUA_TX_IRQn   = 61,               /**< Edgelock Trust MUA TX empty interrupt */
  EDGELOCK_APP_MUA_RX_IRQn     = 62,               /**< Edgelock Apps Core MUA RX full interrupt */
  EDGELOCK_APP_MUA_TX_IRQn     = 63,               /**< Edgelock Apps Core MUA TX empty interrupt */
  EDGELOCK_RT_MUA_RX_IRQn      = 64,               /**< Edgelock Realtime Core MUA RX full interrupt */
  EDGELOCK_RT_MUA_TX_IRQn      = 65,               /**< Edgelock Realtime Core MUA TX empty interrupt */
  EDGELOCK_SECURE_IRQn         = 66,               /**< Edgelock secure interrupt */
  EDGELOCK_NONSECURE_IRQn      = 67,               /**< Edgelock non-secure interrupt */
  TPM1_IRQn                    = 68,               /**< Timer PWM module 1 */
  TPM2_IRQn                    = 69,               /**< Timer PWM module 2 */
  WDOG1_IRQn                   = 70,               /**< Watchdog 1 Interrupt */
  WDOG2_IRQn                   = 71,               /**< Watchdog 2 Interrupt */
  TRDC_IRQn                    = 72,               /**< AONMIX TRDC transfer error interrupt */
  Reserved73_IRQn              = 73,               /**< Reserved interrupt */
  Reserved74_IRQn              = 74,               /**< Reserved interrupt */
  Reserved75_IRQn              = 75,               /**< Reserved interrupt */
  Reserved76_IRQn              = 76,               /**< Reserved interrupt */
  SAI1_IRQn                    = 77,               /**< Serial Audio Interface 1 */
  Reserved78_IRQn              = 78,               /**< Reserved interrupt */
  Reserved79_IRQn              = 79,               /**< Reserved interrupt */
  Reserved80_IRQn              = 80,               /**< Reserved interrupt */
  Reserved81_IRQn              = 81,               /**< Reserved interrupt */
  Reserved82_IRQn              = 82,               /**< Reserved interrupt */
  CAN2_IRQn                    = 83,               /**< CAN2 interrupt */
  CAN2_ERROR_IRQn              = 84,               /**< CAN2 error interrupt */
  Reserved85_IRQn              = 85,               /**< Reserved interrupt */
  Reserved86_IRQn              = 86,               /**< Reserved interrupt */
  FlexSPI1_IRQn                = 87,               /**< FlexSPI controller interface interrupt 1 */
  Reserved88_IRQn              = 88,               /**< Reserved interrupt */
  GPIO2_0_IRQn                 = 89,               /**< General Purpose Input/Output 2 interrupt 0 */
  GPIO2_1_IRQn                 = 90,               /**< General Purpose Input/Output 2 interrupt 1 */
  GPIO3_0_IRQn                 = 91,               /**< General Purpose Input/Output 3 interrupt 0 */
  GPIO3_1_IRQn                 = 92,               /**< General Purpose Input/Output 3 interrupt 1 */
  I3C2_IRQn                    = 93,               /**< Improved Inter-Integrated Circuit 2 interrupt */
  LPI2C3_IRQn                  = 94,               /**< Low Power Inter-Integrated Circuit module 3 */
  LPI2C4_IRQn                  = 95,               /**< Low Power Inter-Integrated Circuit module 4 */
  LPIT2_IRQn                   = 96,               /**< Low Power Periodic Interrupt Timer 2 */
  LPSPI3_IRQn                  = 97,               /**< Low Power Serial Peripheral Interface 3 */
  LPSPI4_IRQn                  = 98,               /**< Low Power Serial Peripheral Interface 4 */
  LPTMR2_IRQn                  = 99,               /**< Low Power Timer 2 */
  LPUART3_IRQn                 = 100,              /**< Low Power UART 3 */
  LPUART4_IRQn                 = 101,              /**< Low Power UART 4 */
  LPUART5_IRQn                 = 102,              /**< Low Power UART 5 */
  LPUART6_IRQn                 = 103,              /**< Low Power UART 6 */
  MTR_MASTER_ERR_IRQn          = 104,              /**< MTR Master error interrupt */
  BBNSM_NONSECURE_IRQn         = 105,              /**< BBNSM Non-Secure interrupt */
  SYS_CTR_COMPARE_IRQn         = 106,              /**< System Counter compare interrupt */
  TPM3_IRQn                    = 107,              /**< Timer PWM module 3 */
  TPM4_IRQn                    = 108,              /**< Timer PWM module 4 */
  TPM5_IRQn                    = 109,              /**< Timer PWM module 5 */
  TPM6_IRQn                    = 110,              /**< Timer PWM module 6 */
  WDOG3_IRQn                   = 111,              /**< Watchdog 3 Interrupt */
  WDOG4_IRQn                   = 112,              /**< Watchdog 4 Interrupt */
  WDOG5_IRQn                   = 113,              /**< Watchdog 5 Interrupt */
  TRDC_WAKEUPMIX_ERR_IRQn      = 114,              /**< WAKEUPMIX TRDC transfer error interrupt */
  TEMPMON_IRQn                 = 115,              /**< TempSensor interrupt */
  Reserved116_IRQn             = 116,              /**< Reserved interrupt */
  Reserved117_IRQn             = 117,              /**< Reserved interrupt */
  uSDHC1_IRQn                  = 118,              /**< ultra Secure Digital Host Controller interrupt 1 */
  uSDHC2_IRQn                  = 119,              /**< ultra Secure Digital Host Controller interrupt 2 */
  TRDC_MEGAMIX_ERR_IRQn        = 120,              /**< MEGAMIX TRDC transfer error interrupt */
  TRDC_NIC_WRAPPER_ERR_IRQn    = 121,              /**< NIC_WRAPPER TRDC transfer error interrupt */
  DRAM_PERFMON_IRQn            = 122,              /**< DRAM controller Performance Monitor Interrupt */
  DRAM_CRITICAL_IRQn           = 123,              /**< DRAM controller Critical Interrupt */
  DRAM_PHY_CRITICAL_IRQn       = 124,              /**< DRAM Phy Critical Interrupt */
  Reserved125_IRQn             = 125,              /**< Reserved interrupt */
  DMA3_ERROR_IRQn              = 126,              /**< eDMA1 error interrupt */
  DMA3_0_IRQn                  = 127,              /**< eDMA1 channel 0 interrupt */
  DMA3_1_IRQn                  = 128,              /**< eDMA1 channel 1 interrupt */
  DMA3_2_IRQn                  = 129,              /**< eDMA1 channel 2 interrupt */
  DMA3_3_IRQn                  = 130,              /**< eDMA1 channel 3 interrupt */
  DMA3_4_IRQn                  = 131,              /**< eDMA1 channel 4 interrupt */
  DMA3_5_IRQn                  = 132,              /**< eDMA1 channel 5 interrupt */
  DMA3_6_IRQn                  = 133,              /**< eDMA1 channel 6 interrupt */
  DMA3_7_IRQn                  = 134,              /**< eDMA1 channel 7 interrupt */
  DMA3_8_IRQn                  = 135,              /**< eDMA1 channel 8 interrupt */
  DMA3_9_IRQn                  = 136,              /**< eDMA1 channel 9 interrupt */
  DMA3_10_IRQn                 = 137,              /**< eDMA1 channel 10 interrupt */
  DMA3_11_IRQn                 = 138,              /**< eDMA1 channel 11 interrupt */
  DMA3_12_IRQn                 = 139,              /**< eDMA1 channel 12 interrupt */
  DMA3_13_IRQn                 = 140,              /**< eDMA1 channel 13 interrupt */
  DMA3_14_IRQn                 = 141,              /**< eDMA1 channel 14 interrupt */
  DMA3_15_IRQn                 = 142,              /**< eDMA1 channel 15 interrupt */
  DMA3_16_IRQn                 = 143,              /**< eDMA1 channel 16 interrupt */
  DMA3_17_IRQn                 = 144,              /**< eDMA1 channel 17 interrupt */
  DMA3_18_IRQn                 = 145,              /**< eDMA1 channel 18 interrupt */
  DMA3_19_IRQn                 = 146,              /**< eDMA1 channel 19 interrupt */
  DMA3_20_IRQn                 = 147,              /**< eDMA1 channel 20 interrupt */
  DMA3_21_IRQn                 = 148,              /**< eDMA1 channel 21 interrupt */
  DMA3_22_IRQn                 = 149,              /**< eDMA1 channel 22 interrupt */
  DMA3_23_IRQn                 = 150,              /**< eDMA1 channel 23 interrupt */
  DMA3_24_IRQn                 = 151,              /**< eDMA1 channel 24 interrupt */
  DMA3_25_IRQn                 = 152,              /**< eDMA1 channel 25 interrupt */
  DMA3_26_IRQn                 = 153,              /**< eDMA1 channel 26 interrupt */
  DMA3_27_IRQn                 = 154,              /**< eDMA1 channel 27 interrupt */
  DMA3_28_IRQn                 = 155,              /**< eDMA1 channel 28 interrupt */
  DMA3_29_IRQn                 = 156,              /**< eDMA1 channel 29 interrupt */
  DMA3_30_IRQn                 = 157,              /**< eDMA1 channel 30 interrupt */
  Reserved158_IRQn             = 158,              /**< Reserved interrupt */
  DMA4_ERROR_IRQn              = 159,              /**< eDMA2 error interrupt */
  DMA4_0_1_IRQn                = 160,              /**< eDMA2 channel 0/1 interrupt */
  DMA4_2_3_IRQn                = 161,              /**< eDMA2 channel 2/3 interrupt */
  DMA4_4_5_IRQn                = 162,              /**< eDMA2 channel 4/5 interrupt */
  DMA4_6_7_IRQn                = 163,              /**< eDMA2 channel 6/7 interrupt */
  DMA4_8_9_IRQn                = 164,              /**< eDMA2 channel 8/9 interrupt */
  DMA4_10_11_IRQn              = 165,              /**< eDMA2 channel 10/11 interrupt */
  DMA4_12_13_IRQn              = 166,              /**< eDMA2 channel 12/13 interrupt */
  DMA4_14_15_IRQn              = 167,              /**< eDMA2 channel 14/15 interrupt */
  DMA4_16_17_IRQn              = 168,              /**< eDMA2 channel 16/17 interrupt */
  DMA4_18_19_IRQn              = 169,              /**< eDMA2 channel 18/19 interrupt */
  DMA4_20_21_IRQn              = 170,              /**< eDMA2 channel 20/21 interrupt */
  DMA4_22_23_IRQn              = 171,              /**< eDMA2 channel 22/23 interrupt */
  DMA4_24_25_IRQn              = 172,              /**< eDMA2 channel 24/25 interrupt */
  DMA4_26_27_IRQn              = 173,              /**< eDMA2 channel 26/27 interrupt */
  DMA4_28_29_IRQn              = 174,              /**< eDMA2 channel 28/29 interrupt */
  DMA4_30_31_IRQn              = 175,              /**< eDMA2 channel 30/31 interrupt */
  DMA4_32_33_IRQn              = 176,              /**< eDMA2 channel 32/33 interrupt */
  DMA4_34_35_IRQn              = 177,              /**< eDMA2 channel 34/35 interrupt */
  DMA4_36_37_IRQn              = 178,              /**< eDMA2 channel 36/37 interrupt */
  DMA4_38_39_IRQn              = 179,              /**< eDMA2 channel 38/39 interrupt */
  DMA4_40_41_IRQn              = 180,              /**< eDMA2 channel 40/41 interrupt */
  DMA4_42_43_IRQn              = 181,              /**< eDMA2 channel 42/43 interrupt */
  DMA4_44_45_IRQn              = 182,              /**< eDMA2 channel 44/45 interrupt */
  DMA4_46_47_IRQn              = 183,              /**< eDMA2 channel 46/47 interrupt */
  DMA4_48_49_IRQn              = 184,              /**< eDMA2 channel 48/49 interrupt */
  DMA4_50_51_IRQn              = 185,              /**< eDMA2 channel 50/51 interrupt */
  DMA4_52_53_IRQn              = 186,              /**< eDMA2 channel 52/53 interrupt */
  DMA4_54_55_IRQn              = 187,              /**< eDMA2 channel 54/55 interrupt */
  DMA4_56_57_IRQn              = 188,              /**< eDMA2 channel 56/57 interrupt */
  DMA4_58_59_IRQn              = 189,              /**< eDMA2 channel 58/59 interrupt */
  DMA4_60_61_IRQn              = 190,              /**< eDMA2 channel 60/61 interrupt */
  DMA4_62_63_IRQn              = 191,              /**< eDMA2 channel 62/63 interrupt */
  DEBUG_WAKEUP_IRQn            = 192,              /**< Debug Wakeup Interrupt */
  EDGELOCK_GROUP1_RST_SRC_IRQn = 193,              /**< Edgelock Group 1 reset source */
  EDGELOCK_GROUP2_RST_SRC_0_IRQn = 194,            /**< Edgelock Group 2 reset source */
  EDGELOCK_GROUP2_RST_SRC_1_IRQn = 195,            /**< Edgelock Group 2 reset source */
  DBG_TRACE_RST_SRC_IRQn       = 196,              /**< JTAGSW DAP MDM-AP SRC reset source */
  JTAGC_RST_SRC_IRQn           = 197,              /**< JTAGC SRC reset source */
  Reserved198_IRQn             = 198,              /**< Reserved interrupt */
  Reserved199_IRQn             = 199,              /**< Reserved interrupt */
  Reserved200_IRQn             = 200,              /**< Reserved interrupt */
  Reserved201_IRQn             = 201,              /**< Reserved interrupt */
  SAI2_IRQn                    = 202,              /**< Serial Audio Interface 2 */
  SAI3_IRQn                    = 203,              /**< Serial Audio Interface 3 */
  ISI_IRQn                     = 204,              /**< ISI interrupt */
  Reserved205_IRQn             = 205,              /**< Reserved interrupt */
  Reserved206_IRQn             = 206,              /**< Reserved interrupt */
  Reserved207_IRQn             = 207,              /**< Reserved interrupt */
  LCDIFv3_IRQn                 = 208,              /**< LCDIF Sync Interrupt */
  Reserved209_IRQn             = 209,              /**< Reserved interrupt */
  Reserved210_IRQn             = 210,              /**< Reserved interrupt */
  ENET_MAC0_Rx_Tx_Done1_IRQn   = 211,              /**< MAC 0 Receive / Trasmit Frame / Buffer Done */
  ENET_MAC0_Rx_Tx_Done2_IRQn   = 212,              /**< MAC 0 Receive / Trasmit Frame / Buffer Done */
  ENET_IRQn                    = 213,              /**< MAC 0 IRQ */
  ENET_1588_IRQn               = 214,              /**< MAC 0 1588 Timer Interrupt - synchronous */
  ENET_QOS_PMT_IRQn            = 215,              /**< ENET QOS PMT interrupt */
  ENET_QOS_IRQn                = 216,              /**< ENET QOS interrupt */
  Reserved217_IRQn             = 217,              /**< Reserved interrupt */
  Reserved218_IRQn             = 218,              /**< Reserved interrupt */
  USB1_WAKEUP_IRQn             = 219,              /**< USB-1 Wake-up Interrupt */
  USB2_WAKEUP_IRQn             = 220,              /**< USB-2 Wake-up Interrupt */
  GPIO4_0_IRQn                 = 221,              /**< General Purpose Input/Output 4 interrupt 0 */
  GPIO4_1_IRQn                 = 222,              /**< General Purpose Input/Output 4 interrupt 1 */
  LPSPI5_IRQn                  = 223,              /**< Low Power Serial Peripheral Interface 5 */
  LPSPI6_IRQn                  = 224,              /**< Low Power Serial Peripheral Interface 6 */
  LPSPI7_IRQn                  = 225,              /**< Low Power Serial Peripheral Interface 7 */
  LPSPI8_IRQn                  = 226,              /**< Low Power Serial Peripheral Interface 8 */
  LPI2C5_IRQn                  = 227,              /**< Low Power Inter-Integrated Circuit module 5 */
  LPI2C6_IRQn                  = 228,              /**< Low Power Inter-Integrated Circuit module 6 */
  LPI2C7_IRQn                  = 229,              /**< Low Power Inter-Integrated Circuit module 7 */
  LPI2C8_IRQn                  = 230,              /**< Low Power Inter-Integrated Circuit module 8 */
  PDM_HWVAD_ERROR_IRQn         = 231,              /**< PDM interrupt */
  PDM_HWVAD_EVENT_IRQn         = 232,              /**< PDM interrupt */
  PDM_ERROR_IRQn               = 233,              /**< PDM interrupt */
  PDM_EVENT_IRQn               = 234,              /**< PDM interrupt */
  AUDIO_XCVR_0_IRQn            = 235,              /**< AUDIO XCVR interrupt */
  AUDIO_XCVR_1_IRQn            = 236,              /**< AUDIO XCVR interrupt */
  uSDHC3_IRQn                  = 237,              /**< ultra Secure Digital Host Controller interrupt 3 */
  OCRAM_MECC_0_IRQn            = 238,              /**< OCRAM MECC interrupt */
  OCRAM_MECC_1_IRQn            = 239,              /**< OCRAM MECC interrupt */
  TRDC_HSIOMIX_ERR_IRQn        = 240,              /**< HSIOMIX TRDC transfer error interrupt */
  TRDC_MEDIAMIX_ERR_IRQn       = 241,              /**< MEDIAMIX TRDC transfer error interrupt */
  LPUART7_IRQn                 = 242,              /**< Low Power UART 7 */
  LPUART8_IRQn                 = 243,              /**< Low Power UART 8 */
  Reserved244_IRQn             = 244,              /**< Reserved interrupt */
  SFA_IRQn                     = 245,              /**< SFA interrupt */
  GIC600_0_IRQn                = 246,              /**< GIC600 INTERRUPT */
  GIC600_1_IRQn                = 247,              /**< GIC600 INTERRUPT */
  GIC600_2_IRQn                = 248,              /**< GIC600 INTERRUPT */
  ADC_ER_IRQn                  = 249,              /**< ADC interrupt */
  ADC_WD_IRQn                  = 250,              /**< ADC interrupt */
  ADC_EOC_IRQn                 = 251,              /**< ADC interrupt */
  Reserved252_IRQn             = 252,              /**< Reserved interrupt */
  I3C1_WAKEUP_IRQn             = 253,              /**< I3C1 wakeup irq after double sync */
  I3C2_WAKEUP_IRQn             = 254,              /**< I3C2 wakeup irq after double sync */
  Reserved255_IRQn             = 255,              /**< Reserved interrupt */
  Reserved256_IRQn             = 256,              /**< Reserved interrupt */
  Reserved257_IRQn             = 257,              /**< Reserved interrupt */
  Reserved258_IRQn             = 258,              /**< Reserved interrupt */
  Reserved259_IRQn             = 259,              /**< Reserved interrupt */
  Reserved260_IRQn             = 260,              /**< Reserved interrupt */
  Reserved261_IRQn             = 261,              /**< Reserved interrupt */
  Reserved262_IRQn             = 262,              /**< Reserved interrupt */
  Reserved263_IRQn             = 263,              /**< Reserved interrupt */
  Reserved264_IRQn             = 264,              /**< Reserved interrupt */
  Reserved265_IRQn             = 265,              /**< Reserved interrupt */
  Reserved266_IRQn             = 266,              /**< Reserved interrupt */
  Reserved267_IRQn             = 267,              /**< Reserved interrupt */
  Reserved268_IRQn             = 268,              /**< Reserved interrupt */
  Reserved269_IRQn             = 269,              /**< Reserved interrupt */
  Reserved270_IRQn             = 270,              /**< Reserved interrupt */
  Reserved271_IRQn             = 271,              /**< Reserved interrupt */
  Reserved272_IRQn             = 272,              /**< Reserved interrupt */
  Reserved273_IRQn             = 273,              /**< Reserved interrupt */
  Reserved274_IRQn             = 274,              /**< Reserved interrupt */
  Reserved275_IRQn             = 275,              /**< Reserved interrupt */
  Reserved276_IRQn             = 276,              /**< Reserved interrupt */
  Reserved277_IRQn             = 277,              /**< Reserved interrupt */
  Reserved278_IRQn             = 278,              /**< Reserved interrupt */
  Reserved279_IRQn             = 279,              /**< Reserved interrupt */
  Reserved280_IRQn             = 280,              /**< Reserved interrupt */
  Reserved281_IRQn             = 281,              /**< Reserved interrupt */
  Reserved282_IRQn             = 282,              /**< Reserved interrupt */
  Reserved283_IRQn             = 283,              /**< Reserved interrupt */
  Reserved284_IRQn             = 284,              /**< Reserved interrupt */
  Reserved285_IRQn             = 285,              /**< Reserved interrupt */
  Reserved286_IRQn             = 286,              /**< Reserved interrupt */
  Reserved287_IRQn             = 287,              /**< Reserved interrupt */
  Reserved288_IRQn             = 288,              /**< Reserved interrupt */
  Reserved289_IRQn             = 289,              /**< Reserved interrupt */
  Reserved290_IRQn             = 290,              /**< Reserved interrupt */
  Reserved291_IRQn             = 291,              /**< Reserved interrupt */
  Reserved292_IRQn             = 292,              /**< Reserved interrupt */
  Reserved293_IRQn             = 293,              /**< Reserved interrupt */
  Reserved294_IRQn             = 294,              /**< Reserved interrupt */
  Reserved295_IRQn             = 295,              /**< Reserved interrupt */
  Reserved296_IRQn             = 296,              /**< Reserved interrupt */
  Reserved297_IRQn             = 297,              /**< Reserved interrupt */
  Reserved298_IRQn             = 298,              /**< Reserved interrupt */
  Reserved299_IRQn             = 299               /**< Reserved interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex A55 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex A55 Core Configuration
 * @{
 */

#define __CA55_REV                     0x0000    /**< Core revision r2p0 */
#define __GIC_PRIO_BITS                4         /**< Number of priority bits implemented in the GIC */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */
#define __FPU_USED                     1         /**< Indicates whether an FPU is used or not */
#define __MMU_PRESENT                  1         /**< MMU present or not */
#define __TIM_PRESENT                  1         /**< TIM present or not */
#define __CACHE_PRESENT                1         /**< CACHE present or not */
#define __GIC_PRESENT                  1         /**< GIC present or not */
#define GIC_DISTRIBUTOR_BASE           0x48000000 /**< GIC distributor base address */
#define GIC_REDISTRIBUTOR_BASE         0x48040000 /**< GIC CPU redistributor base address */

#include "core_ca55.h"                 /* Core Peripheral Access Layer */
#include "system_MIMX9111.h"           /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMX9111_SERIES
#define MIMX9111_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMX9111_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC1 base address */
#define ADC1_BASE                                (0x44530000u)
/** Peripheral ADC1 base pointer */
#define ADC1                                     ((ADC_Type *)ADC1_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC1_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC1 }

/* ANA_OSC - Peripheral instance base addresses */
/** Peripheral ANA_OSC base address */
#define ANA_OSC_BASE                             (0x44480000u)
/** Peripheral ANA_OSC base pointer */
#define ANA_OSC                                  ((ANA_OSC_Type *)ANA_OSC_BASE)
/** Array initializer of ANA_OSC peripheral base addresses */
#define ANA_OSC_BASE_ADDRS                       { ANA_OSC_BASE }
/** Array initializer of ANA_OSC peripheral base pointers */
#define ANA_OSC_BASE_PTRS                        { ANA_OSC }

/* AXBS - Peripheral instance base addresses */
/** Peripheral AXBS base address */
#define AXBS_BASE                                (0x44510000u)
/** Peripheral AXBS base pointer */
#define AXBS                                     ((AXBS_Type *)AXBS_BASE)
/** Array initializer of AXBS peripheral base addresses */
#define AXBS_BASE_ADDRS                          { AXBS_BASE }
/** Array initializer of AXBS peripheral base pointers */
#define AXBS_BASE_PTRS                           { AXBS }

/* BBNSM - Peripheral instance base addresses */
/** Peripheral BBNSM base address */
#define BBNSM_BASE                               (0x44440000u)
/** Peripheral BBNSM base pointer */
#define BBNSM                                    ((BBNSM_Type *)BBNSM_BASE)
/** Array initializer of BBNSM peripheral base addresses */
#define BBNSM_BASE_ADDRS                         { BBNSM_BASE }
/** Array initializer of BBNSM peripheral base pointers */
#define BBNSM_BASE_PTRS                          { BBNSM }

/* BLK_CTRL_DDRMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_DDRMIX1 base address */
#define BLK_CTRL_DDRMIX1_BASE                    (0x4E010000u)
/** Peripheral BLK_CTRL_DDRMIX1 base pointer */
#define BLK_CTRL_DDRMIX1                         ((BLK_CTRL_DDRMIX_Type *)BLK_CTRL_DDRMIX1_BASE)
/** Array initializer of BLK_CTRL_DDRMIX peripheral base addresses */
#define BLK_CTRL_DDRMIX_BASE_ADDRS               { BLK_CTRL_DDRMIX1_BASE }
/** Array initializer of BLK_CTRL_DDRMIX peripheral base pointers */
#define BLK_CTRL_DDRMIX_BASE_PTRS                { BLK_CTRL_DDRMIX1 }

/* BLK_CTRL_MEDIAMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_MEDIAMIX1 base address */
#define BLK_CTRL_MEDIAMIX1_BASE                  (0x4AC10000u)
/** Peripheral BLK_CTRL_MEDIAMIX1 base pointer */
#define BLK_CTRL_MEDIAMIX1                       ((BLK_CTRL_MEDIAMIX_Type *)BLK_CTRL_MEDIAMIX1_BASE)
/** Array initializer of BLK_CTRL_MEDIAMIX peripheral base addresses */
#define BLK_CTRL_MEDIAMIX_BASE_ADDRS             { BLK_CTRL_MEDIAMIX1_BASE }
/** Array initializer of BLK_CTRL_MEDIAMIX peripheral base pointers */
#define BLK_CTRL_MEDIAMIX_BASE_PTRS              { BLK_CTRL_MEDIAMIX1 }

/* BLK_CTRL_NIC_WRAPPER - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_NIC_WRAPPER1 base address */
#define BLK_CTRL_NIC_WRAPPER1_BASE               (0x49000000u)
/** Peripheral BLK_CTRL_NIC_WRAPPER1 base pointer */
#define BLK_CTRL_NIC_WRAPPER1                    ((BLK_CTRL_NIC_WRAPPER_Type *)BLK_CTRL_NIC_WRAPPER1_BASE)
/** Array initializer of BLK_CTRL_NIC_WRAPPER peripheral base addresses */
#define BLK_CTRL_NIC_WRAPPER_BASE_ADDRS          { BLK_CTRL_NIC_WRAPPER1_BASE }
/** Array initializer of BLK_CTRL_NIC_WRAPPER peripheral base pointers */
#define BLK_CTRL_NIC_WRAPPER_BASE_PTRS           { BLK_CTRL_NIC_WRAPPER1 }

/* BLK_CTRL_NS_AONMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_NS_AONMIX1 base address */
#define BLK_CTRL_NS_AONMIX1_BASE                 (0x44210000u)
/** Peripheral BLK_CTRL_NS_AONMIX1 base pointer */
#define BLK_CTRL_NS_AONMIX1                      ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX1_BASE)
/** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
#define BLK_CTRL_NS_AONMIX_BASE_ADDRS            { BLK_CTRL_NS_AONMIX1_BASE }
/** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
#define BLK_CTRL_NS_AONMIX_BASE_PTRS             { BLK_CTRL_NS_AONMIX1 }

/* BLK_CTRL_S_AONMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_S_AONMIX2 base address */
#define BLK_CTRL_S_AONMIX2_BASE                  (0x444F0000u)
/** Peripheral BLK_CTRL_S_AONMIX2 base pointer */
#define BLK_CTRL_S_AONMIX2                       ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX2_BASE)
/** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
#define BLK_CTRL_S_AONMIX_BASE_ADDRS             { BLK_CTRL_S_AONMIX2_BASE }
/** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
#define BLK_CTRL_S_AONMIX_BASE_PTRS              { BLK_CTRL_S_AONMIX2 }

/* BLK_CTRL_WAKEUPMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_WAKEUPMIX1 base address */
#define BLK_CTRL_WAKEUPMIX1_BASE                 (0x42420000u)
/** Peripheral BLK_CTRL_WAKEUPMIX1 base pointer */
#define BLK_CTRL_WAKEUPMIX1                      ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX1_BASE)
/** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
#define BLK_CTRL_WAKEUPMIX_BASE_ADDRS            { BLK_CTRL_WAKEUPMIX1_BASE }
/** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
#define BLK_CTRL_WAKEUPMIX_BASE_PTRS             { BLK_CTRL_WAKEUPMIX1 }

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN1 base address */
#define CAN1_BASE                                (0x443A0000u)
/** Peripheral CAN1 base pointer */
#define CAN1                                     ((CAN_Type *)CAN1_BASE)
/** Peripheral CAN2 base address */
#define CAN2_BASE                                (0x425B0000u)
/** Peripheral CAN2 base pointer */
#define CAN2                                     ((CAN_Type *)CAN2_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { 0u, CAN1_BASE, CAN2_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { (CAN_Type *)0u, CAN1, CAN2 }
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Tx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Wake_Up_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Error_IRQS                           { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Bus_Off_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }

/* CCM_CTRL - Peripheral instance base addresses */
/** Peripheral CCM_CTRL base address */
#define CCM_CTRL_BASE                            (0x44450000u)
/** Peripheral CCM_CTRL base pointer */
#define CCM_CTRL                                 ((CCM_CTRL_Type *)CCM_CTRL_BASE)
/** Array initializer of CCM_CTRL peripheral base addresses */
#define CCM_CTRL_BASE_ADDRS                      { CCM_CTRL_BASE }
/** Array initializer of CCM_CTRL peripheral base pointers */
#define CCM_CTRL_BASE_PTRS                       { CCM_CTRL }

/* DDRC - Peripheral instance base addresses */
/** Peripheral DDR_CTRL base address */
#define DDR_CTRL_BASE                            (0x4E300000u)
/** Peripheral DDR_CTRL base pointer */
#define DDR_CTRL                                 ((DDRC_Type *)DDR_CTRL_BASE)
/** Array initializer of DDRC peripheral base addresses */
#define DDRC_BASE_ADDRS                          { DDR_CTRL_BASE }
/** Array initializer of DDRC peripheral base pointers */
#define DDRC_BASE_PTRS                           { DDR_CTRL }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA3 base address */
#define DMA3_BASE                                (0x44000000u)
/** Peripheral DMA3 base pointer */
#define DMA3                                     ((DMA_Type *)DMA3_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA3_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA3 }

/* DMA4 - Peripheral instance base addresses */
/** Peripheral DMA4 base address */
#define DMA4_BASE                                (0u)
/** Peripheral DMA4 base pointer */
#define DMA4                                     ((DMA4_Type *)DMA4_BASE)
/** Array initializer of DMA4 peripheral base addresses */
#define DMA4_BASE_ADDRS                          { DMA4_BASE }
/** Array initializer of DMA4 peripheral base pointers */
#define DMA4_BASE_PTRS                           { DMA4 }

/* DMA4_TCD - Peripheral instance base addresses */
/** Peripheral EDMA4_2__TCD base address */
#define EDMA4_2__TCD_BASE                        (0u)
/** Peripheral EDMA4_2__TCD base pointer */
#define EDMA4_2__TCD                             ((DMA4_TCD_Type *)EDMA4_2__TCD_BASE)
/** Array initializer of DMA4_TCD peripheral base addresses */
#define DMA4_TCD_BASE_ADDRS                      { EDMA4_2__TCD_BASE }
/** Array initializer of DMA4_TCD peripheral base pointers */
#define DMA4_TCD_BASE_PTRS                       { EDMA4_2__TCD }

/* ENET_QOS - Peripheral instance base addresses */
/** Peripheral ENET_QOS base address */
#define ENET_QOS_BASE                            (0x428A0000u)
/** Peripheral ENET_QOS base pointer */
#define ENET_QOS                                 ((ENET_QOS_Type *)ENET_QOS_BASE)
/** Array initializer of ENET_QOS peripheral base addresses */
#define ENET_QOS_BASE_ADDRS                      { ENET_QOS_BASE }
/** Array initializer of ENET_QOS peripheral base pointers */
#define ENET_QOS_BASE_PTRS                       { ENET_QOS }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO1 base address */
#define FLEXIO1_BASE                             (0x425C0000u)
/** Peripheral FLEXIO1 base pointer */
#define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
/** Peripheral FLEXIO2 base address */
#define FLEXIO2_BASE                             (0x425D0000u)
/** Peripheral FLEXIO2 base pointer */
#define FLEXIO2                                  ((FLEXIO_Type *)FLEXIO2_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { FLEXIO1_BASE, FLEXIO2_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { FLEXIO1, FLEXIO2 }

/* FLEXSPI - Peripheral instance base addresses */
/** Peripheral FLEXSPI1 base address */
#define FLEXSPI1_BASE                            (0x425E0000u)
/** Peripheral FLEXSPI1 base pointer */
#define FLEXSPI1                                 ((FLEXSPI_Type *)FLEXSPI1_BASE)
/** Array initializer of FLEXSPI peripheral base addresses */
#define FLEXSPI_BASE_ADDRS                       { 0u, FLEXSPI1_BASE }
/** Array initializer of FLEXSPI peripheral base pointers */
#define FLEXSPI_BASE_PTRS                        { (FLEXSPI_Type *)0u, FLEXSPI1 }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (1)
/* FlexSPI AMBA base address array. */
#define FlexSPI_AMBA_BASE_ARRAY                  { {0x38000000u} }
/* FlexSPI AMBA end address array. */
#define FlexSPI_AMBA_END_ARRAY                   { {0x3FFFFFFFu} }
/* FlexSPI1 AMBA address. */
#define FlexSPI1_AMBA_BASE                       (0x38000000u)
/* FlexSPI1 ASFM address. */
#define FlexSPI1_ASFM_BASE                       (0x38000000u)
/* Base Address of AHB address space mapped to IP RX FIFO. */
#define FlexSPI1_ARDF_BASE                       (0x57420000u)
/* Base Address of AHB address space mapped to IP TX FIFO. */
#define FlexSPI1_ATDF_BASE                       (0x57430000u)


/* FSB - Peripheral instance base addresses */
/** Peripheral FSB1 base address */
#define FSB1_BASE                                (0x47510000u)
/** Peripheral FSB1 base pointer */
#define FSB1                                     ((FSB_Type *)FSB1_BASE)
/** Array initializer of FSB peripheral base addresses */
#define FSB_BASE_ADDRS                           { FSB1_BASE }
/** Array initializer of FSB peripheral base pointers */
#define FSB_BASE_PTRS                            { FSB1 }

/* GPC_CPU_CTRL - Peripheral instance base addresses */
/** Peripheral GPC__GPC_CTRL_CA55_0 base address */
#define GPC__GPC_CTRL_CA55_0_BASE                (0x44470800u)
/** Peripheral GPC__GPC_CTRL_CA55_0 base pointer */
#define GPC__GPC_CTRL_CA55_0                     ((GPC_CPU_CTRL_Type *)GPC__GPC_CTRL_CA55_0_BASE)
/** Peripheral GPC__GPC_CTRL_CA55_CLUSTER base address */
#define GPC__GPC_CTRL_CA55_CLUSTER_BASE          (0x44471800u)
/** Peripheral GPC__GPC_CTRL_CA55_CLUSTER base pointer */
#define GPC__GPC_CTRL_CA55_CLUSTER               ((GPC_CPU_CTRL_Type *)GPC__GPC_CTRL_CA55_CLUSTER_BASE)
/** Array initializer of GPC_CPU_CTRL peripheral base addresses */
#define GPC_CPU_CTRL_BASE_ADDRS                  { GPC__GPC_CTRL_CA55_0_BASE, GPC__GPC_CTRL_CA55_CLUSTER_BASE }
/** Array initializer of GPC_CPU_CTRL peripheral base pointers */
#define GPC_CPU_CTRL_BASE_PTRS                   { GPC__GPC_CTRL_CA55_0, GPC__GPC_CTRL_CA55_CLUSTER }

/* GPC_GLOBAL - Peripheral instance base addresses */
/** Peripheral GPC__GPC_GLOBAL base address */
#define GPC__GPC_GLOBAL_BASE                     (0x44474000u)
/** Peripheral GPC__GPC_GLOBAL base pointer */
#define GPC__GPC_GLOBAL                          ((GPC_GLOBAL_Type *)GPC__GPC_GLOBAL_BASE)
/** Array initializer of GPC_GLOBAL peripheral base addresses */
#define GPC_GLOBAL_BASE_ADDRS                    { GPC__GPC_GLOBAL_BASE }
/** Array initializer of GPC_GLOBAL peripheral base pointers */
#define GPC_GLOBAL_BASE_PTRS                     { GPC__GPC_GLOBAL }

/* I2S - Peripheral instance base addresses */
/** Peripheral SAI1 base address */
#define SAI1_BASE                                (0x443B0000u)
/** Peripheral SAI1 base pointer */
#define SAI1                                     ((I2S_Type *)SAI1_BASE)
/** Peripheral SAI2 base address */
#define SAI2_BASE                                (0x42650000u)
/** Peripheral SAI2 base pointer */
#define SAI2                                     ((I2S_Type *)SAI2_BASE)
/** Peripheral SAI3 base address */
#define SAI3_BASE                                (0x42660000u)
/** Peripheral SAI3 base pointer */
#define SAI3                                     ((I2S_Type *)SAI3_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, SAI2_BASE, SAI3_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, SAI2, SAI3 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn }

/* I3C - Peripheral instance base addresses */
/** Peripheral I3C1 base address */
#define I3C1_BASE                                (0x44330000u)
/** Peripheral I3C1 base pointer */
#define I3C1                                     ((I3C_Type *)I3C1_BASE)
/** Peripheral I3C2 base address */
#define I3C2_BASE                                (0x42520000u)
/** Peripheral I3C2 base pointer */
#define I3C2                                     ((I3C_Type *)I3C2_BASE)
/** Array initializer of I3C peripheral base addresses */
#define I3C_BASE_ADDRS                           { 0u, I3C1_BASE, I3C2_BASE }
/** Array initializer of I3C peripheral base pointers */
#define I3C_BASE_PTRS                            { (I3C_Type *)0u, I3C1, I3C2 }
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { NotAvail_IRQn, I3C1_IRQn, I3C2_IRQn }

/* IOMUXC1 - Peripheral instance base addresses */
/** Peripheral IOMUXC1 base address */
#define IOMUXC1_BASE                             (0x443C0000u)
/** Peripheral IOMUXC1 base pointer */
#define IOMUXC1                                  ((IOMUXC1_Type *)IOMUXC1_BASE)
/** Array initializer of IOMUXC1 peripheral base addresses */
#define IOMUXC1_BASE_ADDRS                       { IOMUXC1_BASE }
/** Array initializer of IOMUXC1 peripheral base pointers */
#define IOMUXC1_BASE_PTRS                        { IOMUXC1 }

/* IOMUXC_GPR - Peripheral instance base addresses */
/** Peripheral IOMUXC_GPR base address */
#define IOMUXC_GPR_BASE                          (0x443D0000u)
/** Peripheral IOMUXC_GPR base pointer */
#define IOMUXC_GPR                               ((IOMUXC_GPR_Type *)IOMUXC_GPR_BASE)
/** Array initializer of IOMUXC_GPR peripheral base addresses */
#define IOMUXC_GPR_BASE_ADDRS                    { IOMUXC_GPR_BASE }
/** Array initializer of IOMUXC_GPR peripheral base pointers */
#define IOMUXC_GPR_BASE_PTRS                     { IOMUXC_GPR }

/* ISI - Peripheral instance base addresses */
/** Peripheral ISI base address */
#define ISI_BASE                                 (0x4AE40000u)
/** Peripheral ISI base pointer */
#define ISI                                      ((ISI_Type *)ISI_BASE)
/** Array initializer of ISI peripheral base addresses */
#define ISI_BASE_ADDRS                           { ISI_BASE }
/** Array initializer of ISI peripheral base pointers */
#define ISI_BASE_PTRS                            { ISI }

/* LCDIF - Peripheral instance base addresses */
/** Peripheral LCDIF base address */
#define LCDIF_BASE                               (0x4AE30000u)
/** Peripheral LCDIF base pointer */
#define LCDIF                                    ((LCDIF_Type *)LCDIF_BASE)
/** Array initializer of LCDIF peripheral base addresses */
#define LCDIF_BASE_ADDRS                         { LCDIF_BASE }
/** Array initializer of LCDIF peripheral base pointers */
#define LCDIF_BASE_PTRS                          { LCDIF }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x44340000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Peripheral LPI2C2 base address */
#define LPI2C2_BASE                              (0x44350000u)
/** Peripheral LPI2C2 base pointer */
#define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
/** Peripheral LPI2C3 base address */
#define LPI2C3_BASE                              (0x42530000u)
/** Peripheral LPI2C3 base pointer */
#define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
/** Peripheral LPI2C4 base address */
#define LPI2C4_BASE                              (0x42540000u)
/** Peripheral LPI2C4 base pointer */
#define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
/** Peripheral LPI2C5 base address */
#define LPI2C5_BASE                              (0x426B0000u)
/** Peripheral LPI2C5 base pointer */
#define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
/** Peripheral LPI2C6 base address */
#define LPI2C6_BASE                              (0x426C0000u)
/** Peripheral LPI2C6 base pointer */
#define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
/** Peripheral LPI2C7 base address */
#define LPI2C7_BASE                              (0x426D0000u)
/** Peripheral LPI2C7 base pointer */
#define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
/** Peripheral LPI2C8 base address */
#define LPI2C8_BASE                              (0x426E0000u)
/** Peripheral LPI2C8 base pointer */
#define LPI2C8                                   ((LPI2C_Type *)LPI2C8_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE, LPI2C8_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7, LPI2C8 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn, LPI2C4_IRQn, LPI2C5_IRQn, LPI2C6_IRQn, LPI2C7_IRQn, LPI2C8_IRQn }

/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT1 base address */
#define LPIT1_BASE                               (0x442F0000u)
/** Peripheral LPIT1 base pointer */
#define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
/** Peripheral LPIT2 base address */
#define LPIT2_BASE                               (0x424C0000u)
/** Peripheral LPIT2 base pointer */
#define LPIT2                                    ((LPIT_Type *)LPIT2_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { 0u, LPIT1_BASE, LPIT2_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { (LPIT_Type *)0u, LPIT1, LPIT2 }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x44360000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x44370000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Peripheral LPSPI3 base address */
#define LPSPI3_BASE                              (0x42550000u)
/** Peripheral LPSPI3 base pointer */
#define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
/** Peripheral LPSPI4 base address */
#define LPSPI4_BASE                              (0x42560000u)
/** Peripheral LPSPI4 base pointer */
#define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
/** Peripheral LPSPI5 base address */
#define LPSPI5_BASE                              (0x426F0000u)
/** Peripheral LPSPI5 base pointer */
#define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
/** Peripheral LPSPI6 base address */
#define LPSPI6_BASE                              (0x42700000u)
/** Peripheral LPSPI6 base pointer */
#define LPSPI6                                   ((LPSPI_Type *)LPSPI6_BASE)
/** Peripheral LPSPI7 base address */
#define LPSPI7_BASE                              (0x42710000u)
/** Peripheral LPSPI7 base pointer */
#define LPSPI7                                   ((LPSPI_Type *)LPSPI7_BASE)
/** Peripheral LPSPI8 base address */
#define LPSPI8_BASE                              (0x42720000u)
/** Peripheral LPSPI8 base pointer */
#define LPSPI8                                   ((LPSPI_Type *)LPSPI8_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE, LPSPI6_BASE, LPSPI7_BASE, LPSPI8_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5, LPSPI6, LPSPI7, LPSPI8 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, LPSPI4_IRQn, LPSPI5_IRQn, LPSPI6_IRQn, LPSPI7_IRQn, LPSPI8_IRQn }

/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR1 base address */
#define LPTMR1_BASE                              (0x44300000u)
/** Peripheral LPTMR1 base pointer */
#define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
/** Peripheral LPTMR2 base address */
#define LPTMR2_BASE                              (0x424D0000u)
/** Peripheral LPTMR2 base pointer */
#define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { 0u, LPTMR1_BASE, LPTMR2_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { (LPTMR_Type *)0u, LPTMR1, LPTMR2 }
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { NotAvail_IRQn, LPTMR1_IRQn, LPTMR2_IRQn }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x44380000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x44390000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Peripheral LPUART3 base address */
#define LPUART3_BASE                             (0x42570000u)
/** Peripheral LPUART3 base pointer */
#define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
/** Peripheral LPUART4 base address */
#define LPUART4_BASE                             (0x42580000u)
/** Peripheral LPUART4 base pointer */
#define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
/** Peripheral LPUART5 base address */
#define LPUART5_BASE                             (0x42590000u)
/** Peripheral LPUART5 base pointer */
#define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
/** Peripheral LPUART6 base address */
#define LPUART6_BASE                             (0x425A0000u)
/** Peripheral LPUART6 base pointer */
#define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
/** Peripheral LPUART7 base address */
#define LPUART7_BASE                             (0x42690000u)
/** Peripheral LPUART7 base pointer */
#define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
/** Peripheral LPUART8 base address */
#define LPUART8_BASE                             (0x426A0000u)
/** Peripheral LPUART8 base pointer */
#define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn, LPUART6_IRQn, LPUART7_IRQn, LPUART8_IRQn }

/* MU - Peripheral instance base addresses */
/** Peripheral MU1__MUA base address */
#define MU1__MUA_BASE                            (0x44220000u)
/** Peripheral MU1__MUA base pointer */
#define MU1__MUA                                 ((MU_Type *)MU1__MUA_BASE)
/** Peripheral MU1__MUB base address */
#define MU1__MUB_BASE                            (0x44230000u)
/** Peripheral MU1__MUB base pointer */
#define MU1__MUB                                 ((MU_Type *)MU1__MUB_BASE)
/** Peripheral MU2__MUA base address */
#define MU2__MUA_BASE                            (0x42430000u)
/** Peripheral MU2__MUA base pointer */
#define MU2__MUA                                 ((MU_Type *)MU2__MUA_BASE)
/** Peripheral MU2__MUB base address */
#define MU2__MUB_BASE                            (0x42440000u)
/** Peripheral MU2__MUB base pointer */
#define MU2__MUB                                 ((MU_Type *)MU2__MUB_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MU1__MUA_BASE, MU1__MUB_BASE, MU2__MUA_BASE, MU2__MUB_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MU1__MUA, MU1__MUB, MU2__MUA, MU2__MUB }

/* OCRAM_CTRL - Peripheral instance base addresses */
/** Peripheral OCRAM_CTRL1 base address */
#define OCRAM_CTRL1_BASE                         (0x490A0000u)
/** Peripheral OCRAM_CTRL1 base pointer */
#define OCRAM_CTRL1                              ((OCRAM_CTRL_Type *)OCRAM_CTRL1_BASE)
/** Array initializer of OCRAM_CTRL peripheral base addresses */
#define OCRAM_CTRL_BASE_ADDRS                    { OCRAM_CTRL1_BASE }
/** Array initializer of OCRAM_CTRL peripheral base pointers */
#define OCRAM_CTRL_BASE_PTRS                     { OCRAM_CTRL1 }

/* PDM - Peripheral instance base addresses */
/** Peripheral PDM base address */
#define PDM_BASE                                 (0x44520000u)
/** Peripheral PDM base pointer */
#define PDM                                      ((PDM_Type *)PDM_BASE)
/** Array initializer of PDM peripheral base addresses */
#define PDM_BASE_ADDRS                           { PDM_BASE }
/** Array initializer of PDM peripheral base pointers */
#define PDM_BASE_PTRS                            { PDM }

/* PLL - Peripheral instance base addresses */
/** Peripheral ARMPLL base address */
#define ARMPLL_BASE                              (0x44481000u)
/** Peripheral ARMPLL base pointer */
#define ARMPLL                                   ((PLL_Type *)ARMPLL_BASE)
/** Peripheral AUDIOPLL base address */
#define AUDIOPLL_BASE                            (0x44481200u)
/** Peripheral AUDIOPLL base pointer */
#define AUDIOPLL                                 ((PLL_Type *)AUDIOPLL_BASE)
/** Peripheral DRAMPLL base address */
#define DRAMPLL_BASE                             (0x44481300u)
/** Peripheral DRAMPLL base pointer */
#define DRAMPLL                                  ((PLL_Type *)DRAMPLL_BASE)
/** Peripheral SYSPLL base address */
#define SYSPLL_BASE                              (0x44481100u)
/** Peripheral SYSPLL base pointer */
#define SYSPLL                                   ((PLL_Type *)SYSPLL_BASE)
/** Peripheral VIDEOPLL base address */
#define VIDEOPLL_BASE                            (0x44481400u)
/** Peripheral VIDEOPLL base pointer */
#define VIDEOPLL                                 ((PLL_Type *)VIDEOPLL_BASE)
/** Array initializer of PLL peripheral base addresses */
#define PLL_BASE_ADDRS                           { ARMPLL_BASE, AUDIOPLL_BASE, DRAMPLL_BASE, SYSPLL_BASE, VIDEOPLL_BASE }
/** Array initializer of PLL peripheral base pointers */
#define PLL_BASE_PTRS                            { ARMPLL, AUDIOPLL, DRAMPLL, SYSPLL, VIDEOPLL }

/* RGPIO - Peripheral instance base addresses */
/** Peripheral GPIO1 base address */
#define GPIO1_BASE                               (0x47400000u)
/** Peripheral GPIO1 base pointer */
#define GPIO1                                    ((RGPIO_Type *)GPIO1_BASE)
/** Peripheral GPIO2 base address */
#define GPIO2_BASE                               (0x43810000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2                                    ((RGPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO3 base address */
#define GPIO3_BASE                               (0x43820000u)
/** Peripheral GPIO3 base pointer */
#define GPIO3                                    ((RGPIO_Type *)GPIO3_BASE)
/** Peripheral GPIO4 base address */
#define GPIO4_BASE                               (0x43830000u)
/** Peripheral GPIO4 base pointer */
#define GPIO4                                    ((RGPIO_Type *)GPIO4_BASE)
/** Array initializer of RGPIO peripheral base addresses */
#define RGPIO_BASE_ADDRS                         { GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE }
/** Array initializer of RGPIO peripheral base pointers */
#define RGPIO_BASE_PTRS                          { GPIO1, GPIO2, GPIO3, GPIO4 }
/** Interrupt vectors for the RGPIO peripheral type */
#define RGPIO_IRQS                               { GPIO1_0_IRQn, GPIO2_0_IRQn, GPIO3_0_IRQn, GPIO4_0_IRQn }

/* SEMA42 - Peripheral instance base addresses */
/** Peripheral SEMA42_1 base address */
#define SEMA42_1_BASE                            (0x44260000u)
/** Peripheral SEMA42_1 base pointer */
#define SEMA42_1                                 ((SEMA42_Type *)SEMA42_1_BASE)
/** Peripheral SEMA42_2 base address */
#define SEMA42_2_BASE                            (0x42450000u)
/** Peripheral SEMA42_2 base pointer */
#define SEMA42_2                                 ((SEMA42_Type *)SEMA42_2_BASE)
/** Array initializer of SEMA42 peripheral base addresses */
#define SEMA42_BASE_ADDRS                        { 0u, SEMA42_1_BASE, SEMA42_2_BASE }
/** Array initializer of SEMA42 peripheral base pointers */
#define SEMA42_BASE_PTRS                         { (SEMA42_Type *)0u, SEMA42_1, SEMA42_2 }

/* SPDIF - Peripheral instance base addresses */
/** Peripheral SPDIF base address */
#define SPDIF_BASE                               (0x42680000u)
/** Peripheral SPDIF base pointer */
#define SPDIF                                    ((SPDIF_Type *)SPDIF_BASE)
/** Array initializer of SPDIF peripheral base addresses */
#define SPDIF_BASE_ADDRS                         { SPDIF_BASE }
/** Array initializer of SPDIF peripheral base pointers */
#define SPDIF_BASE_PTRS                          { SPDIF }

/* SRC_GENERAL_REG - Peripheral instance base addresses */
/** Peripheral SRC__SRC_GENERAL_REG base address */
#define SRC__SRC_GENERAL_REG_BASE                (0x44460000u)
/** Peripheral SRC__SRC_GENERAL_REG base pointer */
#define SRC__SRC_GENERAL_REG                     ((SRC_GENERAL_REG_Type *)SRC__SRC_GENERAL_REG_BASE)
/** Array initializer of SRC_GENERAL_REG peripheral base addresses */
#define SRC_GENERAL_REG_BASE_ADDRS               { SRC__SRC_GENERAL_REG_BASE }
/** Array initializer of SRC_GENERAL_REG peripheral base pointers */
#define SRC_GENERAL_REG_BASE_PTRS                { SRC__SRC_GENERAL_REG }

/* SRC_MEM_SLICE - Peripheral instance base addresses */
/** Peripheral SRC__SRC_A55C0_MEM base address */
#define SRC__SRC_A55C0_MEM_BASE                  (0x44465C00u)
/** Peripheral SRC__SRC_A55C0_MEM base pointer */
#define SRC__SRC_A55C0_MEM                       ((SRC_MEM_SLICE_Type *)SRC__SRC_A55C0_MEM_BASE)
/** Peripheral SRC__SRC_A55_SCU_MEM base address */
#define SRC__SRC_A55_SCU_MEM_BASE                (0x44466400u)
/** Peripheral SRC__SRC_A55_SCU_MEM base pointer */
#define SRC__SRC_A55_SCU_MEM                     ((SRC_MEM_SLICE_Type *)SRC__SRC_A55_SCU_MEM_BASE)
/** Peripheral SRC__SRC_AON_MEM base address */
#define SRC__SRC_AON_MEM_BASE                    (0x44463800u)
/** Peripheral SRC__SRC_AON_MEM base pointer */
#define SRC__SRC_AON_MEM                         ((SRC_MEM_SLICE_Type *)SRC__SRC_AON_MEM_BASE)
/** Peripheral SRC__SRC_DDR_MEM base address */
#define SRC__SRC_DDR_MEM_BASE                    (0x44464000u)
/** Peripheral SRC__SRC_DDR_MEM base pointer */
#define SRC__SRC_DDR_MEM                         ((SRC_MEM_SLICE_Type *)SRC__SRC_DDR_MEM_BASE)
/** Peripheral SRC__SRC_DPHY_MEM base address */
#define SRC__SRC_DPHY_MEM_BASE                   (0x44464400u)
/** Peripheral SRC__SRC_DPHY_MEM base pointer */
#define SRC__SRC_DPHY_MEM                        ((SRC_MEM_SLICE_Type *)SRC__SRC_DPHY_MEM_BASE)
/** Peripheral SRC__SRC_HSIO_MEM base address */
#define SRC__SRC_HSIO_MEM_BASE                   (0x44465400u)
/** Peripheral SRC__SRC_HSIO_MEM base pointer */
#define SRC__SRC_HSIO_MEM                        ((SRC_MEM_SLICE_Type *)SRC__SRC_HSIO_MEM_BASE)
/** Peripheral SRC__SRC_MEDIA_MEM base address */
#define SRC__SRC_MEDIA_MEM_BASE                  (0x44465800u)
/** Peripheral SRC__SRC_MEDIA_MEM base pointer */
#define SRC__SRC_MEDIA_MEM                       ((SRC_MEM_SLICE_Type *)SRC__SRC_MEDIA_MEM_BASE)
/** Peripheral SRC__SRC_NIC_MEM base address */
#define SRC__SRC_NIC_MEM_BASE                    (0x44464C00u)
/** Peripheral SRC__SRC_NIC_MEM base pointer */
#define SRC__SRC_NIC_MEM                         ((SRC_MEM_SLICE_Type *)SRC__SRC_NIC_MEM_BASE)
/** Peripheral SRC__SRC_NIC_OCRAM base address */
#define SRC__SRC_NIC_OCRAM_BASE                  (0x44465000u)
/** Peripheral SRC__SRC_NIC_OCRAM base pointer */
#define SRC__SRC_NIC_OCRAM                       ((SRC_MEM_SLICE_Type *)SRC__SRC_NIC_OCRAM_BASE)
/** Peripheral SRC__SRC_WKUP_MEM base address */
#define SRC__SRC_WKUP_MEM_BASE                   (0x44463C00u)
/** Peripheral SRC__SRC_WKUP_MEM base pointer */
#define SRC__SRC_WKUP_MEM                        ((SRC_MEM_SLICE_Type *)SRC__SRC_WKUP_MEM_BASE)
/** Array initializer of SRC_MEM_SLICE peripheral base addresses */
#define SRC_MEM_SLICE_BASE_ADDRS                 { SRC__SRC_A55C0_MEM_BASE, SRC__SRC_A55_SCU_MEM_BASE, SRC__SRC_AON_MEM_BASE, SRC__SRC_DDR_MEM_BASE, SRC__SRC_DPHY_MEM_BASE, SRC__SRC_HSIO_MEM_BASE, SRC__SRC_MEDIA_MEM_BASE, SRC__SRC_NIC_MEM_BASE, SRC__SRC_NIC_OCRAM_BASE, SRC__SRC_WKUP_MEM_BASE }
/** Array initializer of SRC_MEM_SLICE peripheral base pointers */
#define SRC_MEM_SLICE_BASE_PTRS                  { SRC__SRC_A55C0_MEM, SRC__SRC_A55_SCU_MEM, SRC__SRC_AON_MEM, SRC__SRC_DDR_MEM, SRC__SRC_DPHY_MEM, SRC__SRC_HSIO_MEM, SRC__SRC_MEDIA_MEM, SRC__SRC_NIC_MEM, SRC__SRC_NIC_OCRAM, SRC__SRC_WKUP_MEM }

/* SRC_MIX_SLICE - Peripheral instance base addresses */
/** Peripheral SRC__SRC_A55C0_SLICE base address */
#define SRC__SRC_A55C0_SLICE_BASE                (0x44462C00u)
/** Peripheral SRC__SRC_A55C0_SLICE base pointer */
#define SRC__SRC_A55C0_SLICE                     ((SRC_MIX_SLICE_Type *)SRC__SRC_A55C0_SLICE_BASE)
/** Peripheral SRC__SRC_A55P_SLICE base address */
#define SRC__SRC_A55P_SLICE_BASE                 (0x44463400u)
/** Peripheral SRC__SRC_A55P_SLICE base pointer */
#define SRC__SRC_A55P_SLICE                      ((SRC_MIX_SLICE_Type *)SRC__SRC_A55P_SLICE_BASE)
/** Peripheral SRC__SRC_AON_SLICE base address */
#define SRC__SRC_AON_SLICE_BASE                  (0x44460800u)
/** Peripheral SRC__SRC_AON_SLICE base pointer */
#define SRC__SRC_AON_SLICE                       ((SRC_MIX_SLICE_Type *)SRC__SRC_AON_SLICE_BASE)
/** Peripheral SRC__SRC_DDR_SLICE base address */
#define SRC__SRC_DDR_SLICE_BASE                  (0x44461000u)
/** Peripheral SRC__SRC_DDR_SLICE base pointer */
#define SRC__SRC_DDR_SLICE                       ((SRC_MIX_SLICE_Type *)SRC__SRC_DDR_SLICE_BASE)
/** Peripheral SRC__SRC_DPHY_SLICE base address */
#define SRC__SRC_DPHY_SLICE_BASE                 (0x44461400u)
/** Peripheral SRC__SRC_DPHY_SLICE base pointer */
#define SRC__SRC_DPHY_SLICE                      ((SRC_MIX_SLICE_Type *)SRC__SRC_DPHY_SLICE_BASE)
/** Peripheral SRC__SRC_EDGELOCK_SLICE base address */
#define SRC__SRC_EDGELOCK_SLICE_BASE             (0x44460400u)
/** Peripheral SRC__SRC_EDGELOCK_SLICE base pointer */
#define SRC__SRC_EDGELOCK_SLICE                  ((SRC_MIX_SLICE_Type *)SRC__SRC_EDGELOCK_SLICE_BASE)
/** Peripheral SRC__SRC_HSIO_SLICE base address */
#define SRC__SRC_HSIO_SLICE_BASE                 (0x44462000u)
/** Peripheral SRC__SRC_HSIO_SLICE base pointer */
#define SRC__SRC_HSIO_SLICE                      ((SRC_MIX_SLICE_Type *)SRC__SRC_HSIO_SLICE_BASE)
/** Peripheral SRC__SRC_MEDIA_SLICE base address */
#define SRC__SRC_MEDIA_SLICE_BASE                (0x44462400u)
/** Peripheral SRC__SRC_MEDIA_SLICE base pointer */
#define SRC__SRC_MEDIA_SLICE                     ((SRC_MIX_SLICE_Type *)SRC__SRC_MEDIA_SLICE_BASE)
/** Peripheral SRC__SRC_NIC_SLICE base address */
#define SRC__SRC_NIC_SLICE_BASE                  (0x44461C00u)
/** Peripheral SRC__SRC_NIC_SLICE base pointer */
#define SRC__SRC_NIC_SLICE                       ((SRC_MIX_SLICE_Type *)SRC__SRC_NIC_SLICE_BASE)
/** Peripheral SRC__SRC_WKUP_SLICE base address */
#define SRC__SRC_WKUP_SLICE_BASE                 (0x44460C00u)
/** Peripheral SRC__SRC_WKUP_SLICE base pointer */
#define SRC__SRC_WKUP_SLICE                      ((SRC_MIX_SLICE_Type *)SRC__SRC_WKUP_SLICE_BASE)
/** Array initializer of SRC_MIX_SLICE peripheral base addresses */
#define SRC_MIX_SLICE_BASE_ADDRS                 { SRC__SRC_A55C0_SLICE_BASE, SRC__SRC_A55P_SLICE_BASE, SRC__SRC_AON_SLICE_BASE, SRC__SRC_DDR_SLICE_BASE, SRC__SRC_DPHY_SLICE_BASE, SRC__SRC_EDGELOCK_SLICE_BASE, SRC__SRC_HSIO_SLICE_BASE, SRC__SRC_MEDIA_SLICE_BASE, SRC__SRC_NIC_SLICE_BASE, SRC__SRC_WKUP_SLICE_BASE }
/** Array initializer of SRC_MIX_SLICE peripheral base pointers */
#define SRC_MIX_SLICE_BASE_PTRS                  { SRC__SRC_A55C0_SLICE, SRC__SRC_A55P_SLICE, SRC__SRC_AON_SLICE, SRC__SRC_DDR_SLICE, SRC__SRC_DPHY_SLICE, SRC__SRC_EDGELOCK_SLICE, SRC__SRC_HSIO_SLICE, SRC__SRC_MEDIA_SLICE, SRC__SRC_NIC_SLICE, SRC__SRC_WKUP_SLICE }

/* SYS_CTR_COMPARE - Peripheral instance base addresses */
/** Peripheral SYS_CTR_CTLBASE1__SYS_CTR_COMPARE base address */
#define SYS_CTR_CTLBASE1__SYS_CTR_COMPARE_BASE   (0x442A0000u)
/** Peripheral SYS_CTR_CTLBASE1__SYS_CTR_COMPARE base pointer */
#define SYS_CTR_CTLBASE1__SYS_CTR_COMPARE        ((SYS_CTR_COMPARE_Type *)SYS_CTR_CTLBASE1__SYS_CTR_COMPARE_BASE)
/** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
#define SYS_CTR_COMPARE_BASE_ADDRS               { SYS_CTR_CTLBASE1__SYS_CTR_COMPARE_BASE }
/** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
#define SYS_CTR_COMPARE_BASE_PTRS                { SYS_CTR_CTLBASE1__SYS_CTR_COMPARE }

/* SYS_CTR_CONTROL - Peripheral instance base addresses */
/** Peripheral SYS_CTR_CTLBASE1__SYS_CTR_CONTROL base address */
#define SYS_CTR_CTLBASE1__SYS_CTR_CONTROL_BASE   (0x44290000u)
/** Peripheral SYS_CTR_CTLBASE1__SYS_CTR_CONTROL base pointer */
#define SYS_CTR_CTLBASE1__SYS_CTR_CONTROL        ((SYS_CTR_CONTROL_Type *)SYS_CTR_CTLBASE1__SYS_CTR_CONTROL_BASE)
/** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
#define SYS_CTR_CONTROL_BASE_ADDRS               { SYS_CTR_CTLBASE1__SYS_CTR_CONTROL_BASE }
/** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
#define SYS_CTR_CONTROL_BASE_PTRS                { SYS_CTR_CTLBASE1__SYS_CTR_CONTROL }

/* SYS_CTR_READ - Peripheral instance base addresses */
/** Peripheral SYS_CTR_CTLBASE1__SYS_CTR_READ base address */
#define SYS_CTR_CTLBASE1__SYS_CTR_READ_BASE      (0x442B0000u)
/** Peripheral SYS_CTR_CTLBASE1__SYS_CTR_READ base pointer */
#define SYS_CTR_CTLBASE1__SYS_CTR_READ           ((SYS_CTR_READ_Type *)SYS_CTR_CTLBASE1__SYS_CTR_READ_BASE)
/** Array initializer of SYS_CTR_READ peripheral base addresses */
#define SYS_CTR_READ_BASE_ADDRS                  { SYS_CTR_CTLBASE1__SYS_CTR_READ_BASE }
/** Array initializer of SYS_CTR_READ peripheral base pointers */
#define SYS_CTR_READ_BASE_PTRS                   { SYS_CTR_CTLBASE1__SYS_CTR_READ }

/* TCD - Peripheral instance base addresses */
/** Peripheral EDMA3_1__TCD base address */
#define EDMA3_1__TCD_BASE                        (0x44010000u)
/** Peripheral EDMA3_1__TCD base pointer */
#define EDMA3_1__TCD                             ((TCD_Type *)EDMA3_1__TCD_BASE)
/** Array initializer of TCD peripheral base addresses */
#define TCD_BASE_ADDRS                           { EDMA3_1__TCD_BASE }
/** Array initializer of TCD peripheral base pointers */
#define TCD_BASE_PTRS                            { EDMA3_1__TCD }

/* TEMPSENSE - Peripheral instance base addresses */
/** Peripheral U_TEMP_ANAMIX base address */
#define U_TEMP_ANAMIX_BASE                       (0x44482000u)
/** Peripheral U_TEMP_ANAMIX base pointer */
#define U_TEMP_ANAMIX                            ((TEMPSENSE_Type *)U_TEMP_ANAMIX_BASE)
/** Array initializer of TEMPSENSE peripheral base addresses */
#define TEMPSENSE_BASE_ADDRS                     { U_TEMP_ANAMIX_BASE }
/** Array initializer of TEMPSENSE peripheral base pointers */
#define TEMPSENSE_BASE_PTRS                      { U_TEMP_ANAMIX }

/* TPM - Peripheral instance base addresses */
/** Peripheral TPM1 base address */
#define TPM1_BASE                                (0x44310000u)
/** Peripheral TPM1 base pointer */
#define TPM1                                     ((TPM_Type *)TPM1_BASE)
/** Peripheral TPM2 base address */
#define TPM2_BASE                                (0x44320000u)
/** Peripheral TPM2 base pointer */
#define TPM2                                     ((TPM_Type *)TPM2_BASE)
/** Peripheral TPM3 base address */
#define TPM3_BASE                                (0x424E0000u)
/** Peripheral TPM3 base pointer */
#define TPM3                                     ((TPM_Type *)TPM3_BASE)
/** Peripheral TPM4 base address */
#define TPM4_BASE                                (0x424F0000u)
/** Peripheral TPM4 base pointer */
#define TPM4                                     ((TPM_Type *)TPM4_BASE)
/** Peripheral TPM5 base address */
#define TPM5_BASE                                (0x42500000u)
/** Peripheral TPM5 base pointer */
#define TPM5                                     ((TPM_Type *)TPM5_BASE)
/** Peripheral TPM6 base address */
#define TPM6_BASE                                (0x42510000u)
/** Peripheral TPM6 base pointer */
#define TPM6                                     ((TPM_Type *)TPM6_BASE)
/** Array initializer of TPM peripheral base addresses */
#define TPM_BASE_ADDRS                           { 0u, TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE }
/** Array initializer of TPM peripheral base pointers */
#define TPM_BASE_PTRS                            { (TPM_Type *)0u, TPM1, TPM2, TPM3, TPM4, TPM5, TPM6 }
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { NotAvail_IRQn, TPM1_IRQn, TPM2_IRQn, TPM3_IRQn, TPM4_IRQn, TPM5_IRQn, TPM6_IRQn }

/* TRDC_MBC0 - Peripheral instance base addresses */
/** Peripheral TRDC3 base address */
#define TRDC3_BASE                               (0x42810000u)
/** Peripheral TRDC3 base pointer */
#define TRDC3                                    ((TRDC_MBC0_Type *)TRDC3_BASE)
/** Peripheral TRDC5 base address */
#define TRDC5_BASE                               (0x4AC30000u)
/** Peripheral TRDC5 base pointer */
#define TRDC5                                    ((TRDC_MBC0_Type *)TRDC5_BASE)
/** Peripheral TRDC6 base address */
#define TRDC6_BASE                               (0x4C030000u)
/** Peripheral TRDC6 base pointer */
#define TRDC6                                    ((TRDC_MBC0_Type *)TRDC6_BASE)
/** Array initializer of TRDC_MBC0 peripheral base addresses */
#define TRDC_MBC0_BASE_ADDRS                     { 0u, 0u, 0u, TRDC3_BASE, 0u, TRDC5_BASE, TRDC6_BASE }
/** Array initializer of TRDC_MBC0 peripheral base pointers */
#define TRDC_MBC0_BASE_PTRS                      { (TRDC_MBC0_Type *)0u, (TRDC_MBC0_Type *)0u, (TRDC_MBC0_Type *)0u, TRDC3, (TRDC_MBC0_Type *)0u, TRDC5, TRDC6 }

/* TRDC_MBC2 - Peripheral instance base addresses */
/** Peripheral TRDC1 base address */
#define TRDC1_BASE                               (0x44270000u)
/** Peripheral TRDC1 base pointer */
#define TRDC1                                    ((TRDC_MBC2_Type *)TRDC1_BASE)
/** Peripheral TRDC2 base address */
#define TRDC2_BASE                               (0x42460000u)
/** Peripheral TRDC2 base pointer */
#define TRDC2                                    ((TRDC_MBC2_Type *)TRDC2_BASE)
/** Array initializer of TRDC_MBC2 peripheral base addresses */
#define TRDC_MBC2_BASE_ADDRS                     { 0u, TRDC1_BASE, TRDC2_BASE }
/** Array initializer of TRDC_MBC2 peripheral base pointers */
#define TRDC_MBC2_BASE_PTRS                      { (TRDC_MBC2_Type *)0u, TRDC1, TRDC2 }

/* TRDC_MBC4 - Peripheral instance base addresses */
/** Peripheral TRDC4 base address */
#define TRDC4_BASE                               (0x49010000u)
/** Peripheral TRDC4 base pointer */
#define TRDC4                                    ((TRDC_MBC4_Type *)TRDC4_BASE)
/** Array initializer of TRDC_MBC4 peripheral base addresses */
#define TRDC_MBC4_BASE_ADDRS                     { 0u, 0u, 0u, 0u, TRDC4_BASE }
/** Array initializer of TRDC_MBC4 peripheral base pointers */
#define TRDC_MBC4_BASE_PTRS                      { (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, (TRDC_MBC4_Type *)0u, TRDC4 }

/* TRGMUX - Peripheral instance base addresses */
/** Peripheral TRGMUX base address */
#define TRGMUX_BASE                              (0x44531000u)
/** Peripheral TRGMUX base pointer */
#define TRGMUX                                   ((TRGMUX_Type *)TRGMUX_BASE)
/** Array initializer of TRGMUX peripheral base addresses */
#define TRGMUX_BASE_ADDRS                        { TRGMUX_BASE }
/** Array initializer of TRGMUX peripheral base pointers */
#define TRGMUX_BASE_PTRS                         { TRGMUX }

/* TSTMR - Peripheral instance base addresses */
/** Peripheral TSTMR1__TSTMRA base address */
#define TSTMR1__TSTMRA_BASE                      (0x442C0000u)
/** Peripheral TSTMR1__TSTMRA base pointer */
#define TSTMR1__TSTMRA                           ((TSTMR_Type *)TSTMR1__TSTMRA_BASE)
/** Peripheral TSTMR2__TSTMRA base address */
#define TSTMR2__TSTMRA_BASE                      (0x42480000u)
/** Peripheral TSTMR2__TSTMRA base pointer */
#define TSTMR2__TSTMRA                           ((TSTMR_Type *)TSTMR2__TSTMRA_BASE)
/** Array initializer of TSTMR peripheral base addresses */
#define TSTMR_BASE_ADDRS                         { TSTMR1__TSTMRA_BASE, TSTMR2__TSTMRA_BASE }
/** Array initializer of TSTMR peripheral base pointers */
#define TSTMR_BASE_PTRS                          { TSTMR1__TSTMRA, TSTMR2__TSTMRA }

/* USB - Peripheral instance base addresses */
/** Peripheral USB__USB_OTG1 base address */
#define USB__USB_OTG1_BASE                       (0x4C100000u)
/** Peripheral USB__USB_OTG1 base pointer */
#define USB__USB_OTG1                            ((USB_Type *)USB__USB_OTG1_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB__USB_OTG1_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB__USB_OTG1 }

/* USBNC - Peripheral instance base addresses */
/** Peripheral USB__USBNC_OTG1 base address */
#define USB__USBNC_OTG1_BASE                     (0x4C100200u)
/** Peripheral USB__USBNC_OTG1 base pointer */
#define USB__USBNC_OTG1                          ((USBNC_Type *)USB__USBNC_OTG1_BASE)
/** Array initializer of USBNC peripheral base addresses */
#define USBNC_BASE_ADDRS                         { USB__USBNC_OTG1_BASE }
/** Array initializer of USBNC peripheral base pointers */
#define USBNC_BASE_PTRS                          { USB__USBNC_OTG1 }

/* USDHC - Peripheral instance base addresses */
/** Peripheral USDHC1 base address */
#define USDHC1_BASE                              (0x42850000u)
/** Peripheral USDHC1 base pointer */
#define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
/** Peripheral USDHC2 base address */
#define USDHC2_BASE                              (0x42860000u)
/** Peripheral USDHC2 base pointer */
#define USDHC2                                   ((USDHC_Type *)USDHC2_BASE)
/** Peripheral USDHC3 base address */
#define USDHC3_BASE                              (0x428B0000u)
/** Peripheral USDHC3 base pointer */
#define USDHC3                                   ((USDHC_Type *)USDHC3_BASE)
/** Array initializer of USDHC peripheral base addresses */
#define USDHC_BASE_ADDRS                         { 0u, USDHC1_BASE, USDHC2_BASE, USDHC3_BASE }
/** Array initializer of USDHC peripheral base pointers */
#define USDHC_BASE_PTRS                          { (USDHC_Type *)0u, USDHC1, USDHC2, USDHC3 }
/** Interrupt vectors for the USDHC peripheral type */
#define USDHC_IRQS                               { NotAvail_IRQn, uSDHC1_IRQn, uSDHC2_IRQn, uSDHC3_IRQn }

/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG1 base address */
#define WDOG1_BASE                               (0x442D0000u)
/** Peripheral WDOG1 base pointer */
#define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
/** Peripheral WDOG2 base address */
#define WDOG2_BASE                               (0x442E0000u)
/** Peripheral WDOG2 base pointer */
#define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
/** Peripheral WDOG3 base address */
#define WDOG3_BASE                               (0x42490000u)
/** Peripheral WDOG3 base pointer */
#define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
/** Peripheral WDOG4 base address */
#define WDOG4_BASE                               (0x424A0000u)
/** Peripheral WDOG4 base pointer */
#define WDOG4                                    ((WDOG_Type *)WDOG4_BASE)
/** Peripheral WDOG5 base address */
#define WDOG5_BASE                               (0x424B0000u)
/** Peripheral WDOG5 base pointer */
#define WDOG5                                    ((WDOG_Type *)WDOG5_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG1, WDOG2, WDOG3, WDOG4, WDOG5 }
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { WDOG1_IRQn, WDOG2_IRQn, WDOG3_IRQn, WDOG4_IRQn, WDOG5_IRQn }

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


#endif  /* MIMX9111_COMMON_H_ */
