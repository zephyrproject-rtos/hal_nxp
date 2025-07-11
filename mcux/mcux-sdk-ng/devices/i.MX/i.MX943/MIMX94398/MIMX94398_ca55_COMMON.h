/*
** ###################################################################
**     Processors:          MIMX94398AVKE_ca55
**                          MIMX94398AVKJ_ca55
**                          MIMX94398AVKM_ca55
**                          MIMX94398AVME_ca55
**                          MIMX94398AVMJ_ca55
**                          MIMX94398AVMM_ca55
**                          MIMX94398CVKE_ca55
**                          MIMX94398CVKJ_ca55
**                          MIMX94398CVKM_ca55
**                          MIMX94398CVME_ca55
**                          MIMX94398CVMJ_ca55
**                          MIMX94398CVMM_ca55
**                          MIMX94398DVKE_ca55
**                          MIMX94398DVKJ_ca55
**                          MIMX94398DVKM_ca55
**                          MIMX94398DVME_ca55
**                          MIMX94398DVMJ_ca55
**                          MIMX94398DVMM_ca55
**                          MIMX94398XVKE_ca55
**                          MIMX94398XVKJ_ca55
**                          MIMX94398XVKM_ca55
**                          MIMX94398XVME_ca55
**                          MIMX94398XVMJ_ca55
**                          MIMX94398XVMM_ca55
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    iMX943RM rev1 draftK
**     Version:             rev. 1.0, 2023-11-01
**     Build:               b241210
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX94398_ca55
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-11-01)
**         Initial version.
**         core name and core alias name
**         +---------------------------------------------------------------------+
**         | core name  |                  core alias name                       |
**         +---------------------------------------------------------------------+
**         | cm33_core0 | m33, cm33                                              |
**         +---------------------------------------------------------------------+
**         | cm33_core1 | m33_2, cm33_2, cm33_sync, netcmix_cm33                 |
**         +---------------------------------------------------------------------+
**         | cm7_core0  | m7, cm7                                                |
**         +---------------------------------------------------------------------+
**         | cm7_core1  | m7_2, cm7_2                                            |
**         +---------------------------------------------------------------------+
**         | ca55_core0 | a55, ca55, a55_0, ca55_0                               |
**         +---------------------------------------------------------------------+
**         | ca55_core1 | a55, ca55, a55_1, ca55_1                               |
**         +---------------------------------------------------------------------+
**         | ca55_core2 | a55, ca55, a55_2, ca55_2                               |
**         +---------------------------------------------------------------------+
**         | ca55_core3 | a55, ca55, a55_3, ca55_3                               |
**         +---------------------------------------------------------------------+
**
** ###################################################################
*/

/*!
 * @file MIMX94398_ca55_COMMON.h
 * @version 1.0
 * @date 2023-11-01
 * @brief CMSIS Peripheral Access Layer for MIMX94398_ca55
 *
 * CMSIS Peripheral Access Layer for MIMX94398_ca55
 */

#if !defined(MIMX94398_CA55_COMMON_H_)
#define MIMX94398_CA55_COMMON_H_                 /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U


/** Peripheral GIC Distributor base address */
#define GIC_DISTRIBUTOR_BASE                     (0x48000000u)
/** Peripheral GIC Redistributor base address */
#define GIC_REDISTRIBUTOR_BASE                   (0x48060000u)

/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 408                /**< Number of interrupts in the Vector table */

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
  Reserved33_IRQn              = 33,               /**< DAP interrupt */
  Reserved34_IRQn              = 34,               /**< CTI trigger outputs from CM7 platform */
  Reserved35_IRQn              = 35,               /**< CTI trigger outputs from CM33 platform */
  Reserved36_IRQn              = 36,               /**< CTI trigger outputs from CA55 platform */
  Reserved37_IRQn              = 37,               /**< Performance Unit Interrupts from CA55 platform */
  Reserved38_IRQn              = 38,               /**< ECC error from CA55 platform cache */
  Reserved39_IRQn              = 39,               /**< 1-bit or 2-bit ECC or Parity error from CA55 platform cache */
  CAN1_IRQn                    = 40,               /**< CAN1 interrupt */
  CAN1_ERROR_IRQn              = 41,               /**< CAN1 error interrupt */
  Reserved42_IRQn              = 42,               /**< General Purpose Input/Output 1 interrupt 0 */
  Reserved43_IRQn              = 43,               /**< General Purpose Input/Output 1 interrupt 1 */
  I3C1_IRQn                    = 44,               /**< Improved Inter-Integrated Circuit 1 interrupt */
  LPI2C1_IRQn                  = 45,               /**< Low Power Inter-Integrated Circuit module 1 */
  LPI2C2_IRQn                  = 46,               /**< Low Power Inter-Integrated Circuit module 2 */
  LPIT1_IRQn                   = 47,               /**< Low Power Periodic Interrupt Timer 1 */
  LPSPI1_IRQn                  = 48,               /**< Low Power Serial Peripheral Interface 1 */
  LPSPI2_IRQn                  = 49,               /**< Low Power Serial Peripheral Interface 2 */
  LPTMR1_IRQn                  = 50,               /**< Low Power Timer 1 */
  LPUART1_IRQn                 = 51,               /**< Low Power UART 1 */
  LPUART2_IRQn                 = 52,               /**< Low Power UART 2 */
  Reserved53_IRQn              = 53,               /**< AONMIX Sentinel MU0 SideA interrupt */
  Reserved54_IRQn              = 54,               /**< AONMIX Sentinel MU1 SideA interrupt */
  Reserved55_IRQn              = 55,               /**< AONMIX Sentinel MU2 SideA interrupt */
  Reserved56_IRQn              = 56,               /**< AONMIX Sentinel MU3 SideA interrupt */
  Reserved57_IRQn              = 57,               /**< AONMIX Sentinel MU4 SideA interrupt */
  Reserved58_IRQn              = 58,               /**< AONMIX Sentinel MU5 SideA interrupt */
  V2X_FH_APCH0_IRQn            = 59,               /**< V2X-FH MU APCH0 (APP0) interrupt */
  V2X_FH_APHSM1_IRQn           = 60,               /**< V2X-FH MU APHSM1 (HSM1) interrupt */
  TPM1_IRQn                    = 61,               /**< Timer PWM module 1 */
  TPM2_IRQn                    = 62,               /**< Timer PWM module 2 */
  WDOG1_IRQn                   = 63,               /**< Watchdog 1 Interrupt */
  WDOG2_IRQn                   = 64,               /**< Watchdog 2 Interrupt */
  TRDC_MGR_A_IRQn              = 65,               /**< AONMIX TRDC transfer error interrupt */
  SAI1_IRQn                    = 66,               /**< Serial Audio Interface 1 */
  Reserved67_IRQn              = 67,               /**< AONMIX M33 PS Error */
  Reserved68_IRQn              = 68,               /**< AONMIX M33 TCM Error interrupt */
  Reserved69_IRQn              = 69,               /**< M7MIX ECC Multi-bit error */
  CAN2_IRQn                    = 70,               /**< CAN2 interrupt */
  CAN2_ERROR_IRQn              = 71,               /**< CAN2 error interrupt */
  CAN3_IRQn                    = 72,               /**< CAN3 interrupt */
  CAN3_ERROR_IRQn              = 73,               /**< CAN3 error interrupt */
  CAN4_IRQn                    = 74,               /**< CAN4 interrupt */
  CAN4_ERROR_IRQn              = 75,               /**< CAN4 error interrupt */
  CAN5_IRQn                    = 76,               /**< CAN5 interrupt */
  CAN5_ERROR_IRQn              = 77,               /**< CAN5 error interrupt */
  FLEXIO1_IRQn                 = 78,               /**< Flexible IO 1 interrupt */
  FLEXIO2_IRQn                 = 79,               /**< Flexible IO 2 interrupt */
  FlexSPI1_IRQn                = 80,               /**< FlexSPI controller interface interrupt 1 */
  Reserved81_IRQn              = 81,               /**< General Purpose Input/Output 2 interrupt 0 */
  Reserved82_IRQn              = 82,               /**< General Purpose Input/Output 2 interrupt 1 */
  Reserved83_IRQn              = 83,               /**< General Purpose Input/Output 3 interrupt 0 */
  Reserved84_IRQn              = 84,               /**< General Purpose Input/Output 3 interrupt 1 */
  Reserved85_IRQn              = 85,               /**< General Purpose Input/Output 4 interrupt 0 */
  Reserved86_IRQn              = 86,               /**< General Purpose Input/Output 4 interrupt 1 */
  Reserved87_IRQn              = 87,               /**< General Purpose Input/Output 5 interrupt 0 */
  Reserved88_IRQn              = 88,               /**< General Purpose Input/Output 5 interrupt 1 */
  I3C2_IRQn                    = 89,               /**< Improved Inter-Integrated Circuit 2 interrupt */
  LPI2C3_IRQn                  = 90,               /**< Low Power Inter-Integrated Circuit module 3 */
  LPI2C4_IRQn                  = 91,               /**< Low Power Inter-Integrated Circuit module 4 */
  LPIT2_IRQn                   = 92,               /**< Low Power Periodic Interrupt Timer 2 */
  LPSPI3_IRQn                  = 93,               /**< Low Power Serial Peripheral Interface 3 */
  LPSPI4_IRQn                  = 94,               /**< Low Power Serial Peripheral Interface 4 */
  LPTMR2_IRQn                  = 95,               /**< Low Power Timer 2 */
  LPUART3_IRQn                 = 96,               /**< Low Power UART 3 */
  LPUART4_IRQn                 = 97,               /**< Low Power UART 4 */
  LPUART5_IRQn                 = 98,               /**< Low Power UART 5 */
  LPUART6_IRQn                 = 99,               /**< Low Power UART 6 */
  LPUART7_IRQn                 = 100,              /**< Low Power UART 7 */
  LPUART8_IRQn                 = 101,              /**< Low Power UART 8 */
  Reserved102_IRQn             = 102,              /**< MTR Master error interrupt */
  Reserved103_IRQn             = 103,              /**< BBNSM Non-Secure interrupt */
  Reserved104_IRQn             = 104,              /**< System Counter compare interrupt */
  TPM3_IRQn                    = 105,              /**< Timer PWM module 3 */
  TPM4_IRQn                    = 106,              /**< Timer PWM module 4 */
  TPM5_IRQn                    = 107,              /**< Timer PWM module 5 */
  TPM6_IRQn                    = 108,              /**< Timer PWM module 6 */
  WDOG3_IRQn                   = 109,              /**< Watchdog 3 Interrupt */
  WDOG4_IRQn                   = 110,              /**< Watchdog 4 Interrupt */
  WDOG5_IRQn                   = 111,              /**< Watchdog 5 Interrupt */
  Reserved112_IRQn             = 112,              /**< ANAMIX TempSensor non-secure interrupt from Threshold 1 */
  Reserved113_IRQn             = 113,              /**< ANAMIX TempSensor non-secure interrupt from Threshold 2 */
  Reserved114_IRQn             = 114,              /**< ANAMIX TempSensor non-secure interrupt from Threshold 3 */
  Reserved115_IRQn             = 115,              /**< CORTEXAMIX TempSensor non-secure interrupt from Threshold 1 */
  Reserved116_IRQn             = 116,              /**< CORTEXAMIX TempSensor non-secure interrupt from Threshold 2 */
  Reserved117_IRQn             = 117,              /**< CORTEXAMIX TempSensor non-secure data ready interrupt */
  uSDHC1_IRQn                  = 118,              /**< ultra Secure Digital Host Controller interrupt 1 */
  uSDHC2_IRQn                  = 119,              /**< ultra Secure Digital Host Controller interrupt 2 */
  Reserved120_IRQn             = 120,              /**< MEGAMIX TRDC transfer error interrupt */
  Reserved121_IRQn             = 121,              /**< NIC_WRAPPER TRDC transfer error interrupt */
  Reserved122_IRQn             = 122,              /**< NOCMIX TRDC transfer error interrupt */
  Reserved123_IRQn             = 123,              /**< DRAM controller Performance Monitor Interrupt */
  Reserved124_IRQn             = 124,              /**< DRAM controller Critical Interrupt */
  Reserved125_IRQn             = 125,              /**< DRAM Phy Critical Interrupt */
  Reserved126_IRQn             = 126,              /**< Reserved */
  DMA3_ERROR_IRQn              = 127,              /**< eDMA1 error interrupt */
  DMA3_0_IRQn                  = 128,              /**< eDMA1 channel 0 interrupt */
  DMA3_1_IRQn                  = 129,              /**< eDMA1 channel 1 interrupt */
  DMA3_2_IRQn                  = 130,              /**< eDMA1 channel 2 interrupt */
  DMA3_3_IRQn                  = 131,              /**< eDMA1 channel 3 interrupt */
  DMA3_4_IRQn                  = 132,              /**< eDMA1 channel 4 interrupt */
  DMA3_5_IRQn                  = 133,              /**< eDMA1 channel 5 interrupt */
  DMA3_6_IRQn                  = 134,              /**< eDMA1 channel 6 interrupt */
  DMA3_7_IRQn                  = 135,              /**< eDMA1 channel 7 interrupt */
  DMA3_8_IRQn                  = 136,              /**< eDMA1 channel 8 interrupt */
  DMA3_9_IRQn                  = 137,              /**< eDMA1 channel 9 interrupt */
  DMA3_10_IRQn                 = 138,              /**< eDMA1 channel 10 interrupt */
  DMA3_11_IRQn                 = 139,              /**< eDMA1 channel 11 interrupt */
  DMA3_12_IRQn                 = 140,              /**< eDMA1 channel 12 interrupt */
  DMA3_13_IRQn                 = 141,              /**< eDMA1 channel 13 interrupt */
  DMA3_14_IRQn                 = 142,              /**< eDMA1 channel 14 interrupt */
  DMA3_15_IRQn                 = 143,              /**< eDMA1 channel 15 interrupt */
  DMA3_16_IRQn                 = 144,              /**< eDMA1 channel 16 interrupt */
  DMA3_17_IRQn                 = 145,              /**< eDMA1 channel 17 interrupt */
  DMA3_18_IRQn                 = 146,              /**< eDMA1 channel 18 interrupt */
  DMA3_19_IRQn                 = 147,              /**< eDMA1 channel 19 interrupt */
  DMA3_20_IRQn                 = 148,              /**< eDMA1 channel 20 interrupt */
  DMA3_21_IRQn                 = 149,              /**< eDMA1 channel 21 interrupt */
  DMA3_22_IRQn                 = 150,              /**< eDMA1 channel 22 interrupt */
  DMA3_23_IRQn                 = 151,              /**< eDMA1 channel 23 interrupt */
  DMA3_24_IRQn                 = 152,              /**< eDMA1 channel 24 interrupt */
  DMA3_25_IRQn                 = 153,              /**< eDMA1 channel 25 interrupt */
  DMA3_26_IRQn                 = 154,              /**< eDMA1 channel 26 interrupt */
  DMA3_27_IRQn                 = 155,              /**< eDMA1 channel 27 interrupt */
  DMA3_28_IRQn                 = 156,              /**< eDMA1 channel 28 interrupt */
  DMA3_29_IRQn                 = 157,              /**< eDMA1 channel 29 interrupt */
  DMA3_30_IRQn                 = 158,              /**< eDMA1 channel 30 interrupt */
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
  Reserved192_IRQn             = 192,              /**< Sentinel Group 1 reset source if no s500 reference clock is detected.  Output synchronized to 32khz clk. */
  Reserved193_IRQn             = 193,              /**< Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk. */
  Reserved194_IRQn             = 194,              /**< Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk. */
  Reserved195_IRQn             = 195,              /**< JTAGSW DAP MDM-AP SRC reset source */
  Reserved196_IRQn             = 196,              /**< JTAGC SRC reset source */
  CM33_SYSRESETREQ_IRQn        = 197,              /**< CM33 SYSREQRST SRC reset source */
  CM33_LOCKUP_IRQn             = 198,              /**< CM33 LOCKUP SRC reset source */
  CM7_SYSRESETREQ_IRQn         = 199,              /**< CM7 SYSREQRST SRC reset source */
  CM7_LOCKUP_IRQn              = 200,              /**< CM7 LOCKUP SRC reset source */
  SAI2_IRQn                    = 201,              /**< Serial Audio Interface 2 */
  SAI3_IRQn                    = 202,              /**< Serial Audio Interface 3 */
  SAI4_IRQn                    = 203,              /**< Serial Audio Interface 4 */
  SAI5_IRQn                    = 204,              /**< Serial Audio Interface 5 */
  Reserved205_IRQn             = 205,              /**< USB-1 Wake-up Interrupt */
  Reserved206_IRQn             = 206,              /**< USB-2 Wake-up Interrupt */
  USB1_IRQn                    = 207,              /**< USB-1 Interrupt */
  USB2_IRQn                    = 208,              /**< USB-2 Interrupt */
  LPSPI5_IRQn                  = 209,              /**< Low Power Serial Peripheral Interface 5 */
  LPSPI6_IRQn                  = 210,              /**< Low Power Serial Peripheral Interface 6 */
  LPSPI7_IRQn                  = 211,              /**< Low Power Serial Peripheral Interface 7 */
  LPSPI8_IRQn                  = 212,              /**< Low Power Serial Peripheral Interface 8 */
  LPI2C5_IRQn                  = 213,              /**< Low Power Inter-Integrated Circuit module 5 */
  LPI2C6_IRQn                  = 214,              /**< Low Power Inter-Integrated Circuit module 6 */
  LPI2C7_IRQn                  = 215,              /**< Low Power Inter-Integrated Circuit module 7 */
  LPI2C8_IRQn                  = 216,              /**< Low Power Inter-Integrated Circuit module 8 */
  PDM_HWVAD_ERROR_IRQn         = 217,              /**< PDM interrupt */
  PDM_HWVAD_EVENT_IRQn         = 218,              /**< PDM interrupt */
  PDM_ERROR_IRQn               = 219,              /**< PDM interrupt */
  PDM_EVENT_IRQn               = 220,              /**< PDM interrupt */
  Reserved221_IRQn             = 221,              /**< AUDIO XCVR interrupt */
  Reserved222_IRQn             = 222,              /**< AUDIO XCVR interrupt */
  uSDHC3_IRQn                  = 223,              /**< ultra Secure Digital Host Controller interrupt 3 */
  Reserved224_IRQn             = 224,              /**< OCRAM MECC interrupt */
  Reserved225_IRQn             = 225,              /**< OCRAM MECC interrupt */
  Reserved226_IRQn             = 226,              /**< CM33 MCM interrupt */
  Reserved227_IRQn             = 227,              /**< ANAMIX SFA interrupt */
  Reserved228_IRQn             = 228,              /**< GIC700 Fault */
  Reserved229_IRQn             = 229,              /**< GIC700 Error */
  Reserved230_IRQn             = 230,              /**< GIC700 PMU Counter Overflow */
  ADC_ER_IRQn                  = 231,              /**< ADC interrupt */
  ADC_WD_IRQn                  = 232,              /**< ADC interrupt */
  ADC_EOC_IRQn                 = 233,              /**< ADC interrupt */
  Reserved234_IRQn             = 234,              /**< s500 glue logic IRQ */
  Reserved235_IRQn             = 235,              /**< I3C1 wakeup irq after double sync */
  Reserved236_IRQn             = 236,              /**< I3C2 wakeup irq after double sync */
  MU5_A_IRQn                   = 237,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU6_A_IRQn                   = 238,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU7_B_IRQn                   = 239,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU8_B_IRQn                   = 240,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  Reserved241_IRQn             = 241,              /**< WAKEUPMIX XSPI Responder */
  Reserved242_IRQn             = 242,              /**< AONMIX FCCU Interrupt Reaction 0 */
  Reserved243_IRQn             = 243,              /**< AONMIX FCCU Interrupt Reaction 1 */
  Reserved244_IRQn             = 244,              /**< AONMIX FCCU Interrupt Reaction 2 */
  Reserved245_IRQn             = 245,              /**< AONMIX STCU Selftest end Interrupt */
  DISP_IRQSTEER0_IRQn          = 246,              /**< DISPLAYMIX IRQSTEER 0 */
  DISP_IRQSTEER1_IRQn          = 247,              /**< DISPLAYMIX IRQSTEER 1 */
  DISP_IRQSTEER2_IRQn          = 248,              /**< DISPLAYMIX IRQSTEER 2 */
  DISP_IRQSTEER3_IRQn          = 249,              /**< DISPLAYMIX IRQSTEER 3 */
  DISP_IRQSTEER4_IRQn          = 250,              /**< DISPLAYMIX IRQSTEER 4 */
  DISP_IRQSTEER7_IRQn          = 251,              /**< DISPLAYMIX IRQSTEER 7 */
  Reserved252_IRQn             = 252,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  Reserved253_IRQn             = 253,              /**< CAMERAMIX ISI interrupt Channel 0 */
  Reserved254_IRQn             = 254,              /**< ISP Processing Interrupt - Context 0 */
  Reserved255_IRQn             = 255,              /**< M7MIX MCM interrupt */
  MU1_A_IRQn                   = 256,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU1_B_IRQn                   = 257,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU2_A_IRQn                   = 258,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU2_B_IRQn                   = 259,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU3_A_IRQn                   = 260,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU3_B_IRQn                   = 261,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU4_A_IRQn                   = 262,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU4_B_IRQn                   = 263,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU5_B_IRQn                   = 264,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU6_B_IRQn                   = 265,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU7_A_IRQn                   = 266,              /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU8_A_IRQn                   = 267,              /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MSGINTR1_IRQn                = 268,              /**< MSGINTR Instance 1, Interrupt */
  MSGINTR2_IRQn                = 269,              /**< MSGINTR Instance 2, Interrupts */
  Reserved270_IRQn             = 270,              /**< V2X-FH MU APCH1 (APP1) interrupt */
  Reserved271_IRQn             = 271,              /**< V2X-FH MU APHSM2 (HSM2) interrupt */
  Reserved272_IRQn             = 272,              /**< CAMERAMIX TRDC transfer error interrupt */
  Reserved273_IRQn             = 273,              /**< DISPLAYMIX TRDC transfer error interrupt */
  Reserved274_IRQn             = 274,              /**< NETCMIX TRDC transfer error interrupt */
  Reserved275_IRQn             = 275,              /**< GPUMIX TRDC transfer error interrupt */
  Reserved276_IRQn             = 276,              /**< HSIOMIX TRDC transfer error interrupt */
  Reserved277_IRQn             = 277,              /**< VPUMIX TRDC transfer error interrupt */
  Reserved278_IRQn             = 278,              /**< AONMIX ERM Single bit corrected ECC Error */
  Reserved279_IRQn             = 279,              /**< M7MIX ERM Single bit corrected ECC Error */
  Reserved280_IRQn             = 280,              /**< WAKEUPMIX ERM Single bit corrected ECC Error */
  Reserved281_IRQn             = 281,              /**< NPUMIX ERM Single bit corrected ECC Error */
  Reserved282_IRQn             = 282,              /**< WAKEUPMIX ACP EDMA error interrupt */
  Reserved283_IRQn             = 283,              /**< OCRAM_C ECC multiple bit or address error */
  Reserved284_IRQn             = 284,              /**< CAMERAMIX Cortex-M0+ Cache write-buffer error */
  Reserved285_IRQn             = 285,              /**< CAMERAMIX Cortex-M0+ Cache data parity error */
  Reserved286_IRQn             = 286,              /**< V2X-FH MU APSHE (SHE) interrupt */
  Reserved287_IRQn             = 287,              /**< V2X-FH MU SCU/APDEBUG (DEBUG) interrupt */
  DMA5_0_1_IRQn                = 288,              /**< eDMA3 channel 0/1 interrupt */
  DMA5_2_3_IRQn                = 289,              /**< eDMA3 channel 2/3 interrupt */
  DMA5_4_5_IRQn                = 290,              /**< eDMA3 channel 4/5 interrupt */
  DMA5_6_7_IRQn                = 291,              /**< eDMA3 channel 6/7 interrupt */
  DMA5_8_9_IRQn                = 292,              /**< eDMA3 channel 8/9 interrupt */
  DMA5_10_11_IRQn              = 293,              /**< eDMA3 channel 10/11 interrupt */
  DMA5_12_13_IRQn              = 294,              /**< eDMA3 channel 12/13 interrupt */
  DMA5_14_15_IRQn              = 295,              /**< eDMA3 channel 14/15 interrupt */
  DMA5_16_17_IRQn              = 296,              /**< eDMA3 channel 16/17 interrupt */
  DMA5_18_19_IRQn              = 297,              /**< eDMA3 channel 18/19 interrupt */
  DMA5_20_21_IRQn              = 298,              /**< eDMA3 channel 20/21 interrupt */
  DMA5_22_23_IRQn              = 299,              /**< eDMA3 channel 22/23 interrupt */
  DMA5_24_25_IRQn              = 300,              /**< eDMA3 channel 24/25 interrupt */
  DMA5_26_27_IRQn              = 301,              /**< eDMA3 channel 26/27 interrupt */
  DMA5_28_29_IRQn              = 302,              /**< eDMA3 channel 28/29 interrupt */
  DMA5_30_31_IRQn              = 303,              /**< eDMA3 channel 30/31 interrupt */
  DMA5_32_33_IRQn              = 304,              /**< eDMA3 channel 32/33 interrupt */
  DMA5_34_35_IRQn              = 305,              /**< eDMA3 channel 34/35 interrupt */
  DMA5_36_37_IRQn              = 306,              /**< eDMA3 channel 36/37 interrupt */
  DMA5_38_39_IRQn              = 307,              /**< eDMA3 channel 38/39 interrupt */
  DMA5_40_41_IRQn              = 308,              /**< eDMA3 channel 40/41 interrupt */
  DMA5_42_43_IRQn              = 309,              /**< eDMA3 channel 42/43 interrupt */
  DMA5_44_45_IRQn              = 310,              /**< eDMA3 channel 44/45 interrupt */
  DMA5_46_47_IRQn              = 311,              /**< eDMA3 channel 46/47 interrupt */
  DMA5_48_49_IRQn              = 312,              /**< eDMA3 channel 48/49 interrupt */
  DMA5_50_51_IRQn              = 313,              /**< eDMA3 channel 50/51 interrupt */
  DMA5_52_53_IRQn              = 314,              /**< eDMA3 channel 52/53 interrupt */
  DMA5_54_55_IRQn              = 315,              /**< eDMA3 channel 54/55 interrupt */
  DMA5_56_57_IRQn              = 316,              /**< eDMA3 channel 56/57 interrupt */
  DMA5_58_59_IRQn              = 317,              /**< eDMA3 channel 58/59 interrupt */
  DMA5_60_61_IRQn              = 318,              /**< eDMA3 channel 60/61 interrupt */
  DMA5_62_63_IRQn              = 319,              /**< eDMA3 channel 62/63 interrupt */
  Reserved320_IRQn             = 320,              /**< GPUMIX GPU Interrupt */
  Reserved321_IRQn             = 321,              /**< GPUMIX Job Interrupt */
  Reserved322_IRQn             = 322,              /**< GPUMIX MMU Interrupt */
  Reserved323_IRQn             = 323,              /**< Reserved INTERRUPT */
  Reserved324_IRQn             = 324,              /**< Reserved interrupt */
  Reserved325_IRQn             = 325,              /**< Reserved interrupt */
  Reserved326_IRQn             = 326,              /**< Reserved interrupt */
  Reserved327_IRQn             = 327,              /**< Reserved interrupt */
  Reserved328_IRQn             = 328,              /**< Reserved interrupt */
  Reserved329_IRQn             = 329,              /**< Reserved interrupt */
  Reserved330_IRQn             = 330,              /**< Reserved interrupt */
  Reserved331_IRQn             = 331,              /**< Reserved interrupt */
  Reserved332_IRQn             = 332,              /**< Reserved interrupt */
  Reserved333_IRQn             = 333,              /**< Reserved interrupt */
  Reserved334_IRQn             = 334,              /**< Reserved interrupt */
  Reserved335_IRQn             = 335,              /**< Reserved interrupt */
  Reserved336_IRQn             = 336,              /**< NETC iEPRC PCI INT */
  Reserved337_IRQn             = 337,              /**< NETC iEPRC PCI INT */
  Reserved338_IRQn             = 338,              /**< PCIe Controller 1 INTA */
  Reserved339_IRQn             = 339,              /**< PCIe Controller 1 INTB */
  Reserved340_IRQn             = 340,              /**< PCIe Controller 1 INTC */
  Reserved341_IRQn             = 341,              /**< PCIe Controller 1 INTD */
  Reserved342_IRQn             = 342,              /**< PCIe interrupts */
  Reserved343_IRQn             = 343,              /**< PCIe Controller EDMA channel interrupt */
  Reserved344_IRQn             = 344,              /**< PCIe Controller 1 INTA */
  Reserved345_IRQn             = 345,              /**< PCIe Controller 1 INTB */
  Reserved346_IRQn             = 346,              /**< PCIe Controller 1 INTC */
  Reserved347_IRQn             = 347,              /**< PCIe Controller 1 INTD */
  Reserved348_IRQn             = 348,              /**< PCIe miscellaneous interrupts */
  Reserved349_IRQn             = 349,              /**< PCIe Controller EDMA channel interrupt */
  Reserved350_IRQn             = 350,              /**< Wakeup interrupt from CLKREQ#, WAKEUP#, BEACON_DET */
  Reserved351_IRQn             = 351,              /**< NPUMIX Functional interrupt */
  Reserved352_IRQn             = 352,              /**< DISPLAYMIX Real-time traffic TBU: Fault Handling RAS Interrupt for a contained error */
  Reserved353_IRQn             = 353,              /**< DISPLAYMIX Real-time traffic TBU: Error Handling RAS Interrupt for an uncontained error */
  Reserved354_IRQn             = 354,              /**< DISPLAYMIX Real-time traffic TBU: Critical Error Interrupt for an uncontainable error */
  Reserved355_IRQn             = 355,              /**< DISPLAYMIX Real-time traffic TBU: PMU Interrupt */
  Reserved356_IRQn             = 356,              /**< TCU Event queue, secure interrupt */
  Reserved357_IRQn             = 357,              /**< TCU Event queue, non-secure interrupt */
  Reserved358_IRQn             = 358,              /**< TCU SYNC complete, non-secure interrupt */
  Reserved359_IRQn             = 359,              /**< TCU SYNC complete, secure interrupt */
  Reserved360_IRQn             = 360,              /**< TCU global non-secure interrupt */
  Reserved361_IRQn             = 361,              /**< TCU global secure interrupt */
  Reserved362_IRQn             = 362,              /**< TCU fault handling RAS interrupt for a contained error */
  Reserved363_IRQn             = 363,              /**< TCU error recovery RAS interrupt for an uncontained error */
  Reserved364_IRQn             = 364,              /**< TCU critical error interrupt, for an uncontainable uncorrected error */
  Reserved365_IRQn             = 365,              /**< TCU PMU interrupt */
  Reserved366_IRQn             = 366,              /**< TCU Page Request Interface */
  GPC_SM_REQ_IRQn              = 367,              /**< SRC/GPC Low Power Handshake Gasket interrupt request for system management */
  Reserved368_IRQn             = 368,              /**< CAMERAMIX MU Ored of all */
  Reserved369_IRQn             = 369,              /**< CAMERAMIX MU Ored of all */
  Reserved370_IRQn             = 370,              /**< CAMERAMIX MU Ored of all */
  Reserved371_IRQn             = 371,              /**< CAMERAMIX MU Ored of all */
  Reserved372_IRQn             = 372,              /**< CAMERAMIX MU Ored of all */
  Reserved373_IRQn             = 373,              /**< CAMERAMIX MU Ored of all */
  Reserved374_IRQn             = 374,              /**< CAMERAMIX MU Ored of all */
  Reserved375_IRQn             = 375,              /**< CAMERAMIX MU Ored of all */
  Reserved376_IRQn             = 376,              /**< CAMERAMIX ISI interrupt Channel 1 */
  Reserved377_IRQn             = 377,              /**< CAMERAMIX ISI interrupt Channel 2 */
  Reserved378_IRQn             = 378,              /**< CAMERAMIX ISI interrupt Channel 3 */
  Reserved379_IRQn             = 379,              /**< CAMERAMIX ISI interrupt Channel 4 */
  Reserved380_IRQn             = 380,              /**< CAMERAMIX ISI interrupt Channel 5 */
  Reserved381_IRQn             = 381,              /**< CAMERAMIX ISI interrupt Channel 6 */
  Reserved382_IRQn             = 382,              /**< CAMERAMIX ISI interrupt Channel 7 */
  Reserved383_IRQn             = 383,              /**< CAMERAMIX EDMA error interrupt */
  Reserved384_IRQn             = 384,              /**< CAMERAMIX EDMA channel 0 interrupt */
  Reserved385_IRQn             = 385,              /**< CAMERAMIX EDMA channel 2 interrupt */
  Reserved386_IRQn             = 386,              /**< CAMERAMIX EDMA channel 4 interrupt */
  Reserved387_IRQn             = 387,              /**< CAMERAMIX EDMA channel 6 interrupt */
  Reserved388_IRQn             = 388,              /**< CAMERAMIX EDMA channel 8 interrupt */
  Reserved389_IRQn             = 389,              /**< CAMERAMIX EDMA channel 10 interrupt */
  Reserved390_IRQn             = 390,              /**< CAMERAMIX EDMA channel 12 interrupt */
  Reserved391_IRQn             = 391,              /**< CAMERAMIX EDMA channel 14 interrupt */
  Reserved392_IRQn             = 392,              /**< CAMERAMIX EDMA channel 16 interrupt */
  Reserved393_IRQn             = 393,              /**< CAMERAMIX EDMA channel 18 interrupt */
  Reserved394_IRQn             = 394,              /**< CAMERAMIX EDMA channel 20 interrupt */
  Reserved395_IRQn             = 395,              /**< CAMERAMIX EDMA channel 22 interrupt */
  Reserved396_IRQn             = 396,              /**< CAMERAMIX EDMA channel 24 interrupt */
  Reserved397_IRQn             = 397,              /**< CAMERAMIX EDMA channel 26 interrupt */
  Reserved398_IRQn             = 398,              /**< CAMERAMIX EDMA channel 28 interrupt */
  Reserved399_IRQn             = 399,              /**< CAMERAMIX EDMA channel 30 interrupt */
  Reserved400_IRQn             = 400,              /**< CAMERAMIX CSI Formatting Unit 1: Buffer overflow */
  Reserved401_IRQn             = 401,              /**< CAMERAMIX CSI Formatting Unit 1: Interlaced Error */
  Reserved402_IRQn             = 402,              /**< CAMERAMIX CSI Formatting Unit 1: Pixel Data Type Error */
  Reserved403_IRQn             = 403,              /**< CAMERAMIX CSI Formatting Unit 2: Buffer overflow */
  Reserved404_IRQn             = 404,              /**< CAMERAMIX CSI Formatting Unit 2: Interlaced Error */
  Reserved405_IRQn             = 405,              /**< CAMERAMIX CSI Formatting Unit 2: Pixel Data Type Error */
  Reserved406_IRQn             = 406,              /**< CAMERAMIX CSI1 */
  Reserved407_IRQn             = 407               /**< CAMERAMIX CSI2 */
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

#define __CA55_REV                     0x0004    /**< Core revision r0p4 */
#define __GIC_PRIO_BITS                4         /**< Number of priority bits implemented in the GIC */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */
#define __FPU_USED                     1         /**< Indicates whether an FPU is used or not */
#define __GIC_PRESENT                  1         /**< Defines if a GIC is present or not */
#define __MMU_PRESENT                  1         /**< MMU present or not */
#define __TIM_PRESENT                  1         /**< Defines if a Timer is present or not */
#define __CACHE_PRESENT                1         /**< CACHE present or not */

#include "core_ca55.h"                 /* Core Peripheral Access Layer */
#include "system_MIMX94398_ca55.h"     /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#define MIMX94398_ca55_SERIES
/* CPU specific feature definitions */
#include "MIMX94398_ca55_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC base address */
#define ADC_BASE                                 (0x44530000u)
/** Peripheral ADC base pointer */
#define ADC                                      ((ADC_Type *)ADC_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC }

/* ANALOG_AGDET - Peripheral instance base addresses */
/** Peripheral ANALOG__AGDET base address */
#define ANALOG__AGDET_BASE                       (0x44487000u)
/** Peripheral ANALOG__AGDET base pointer */
#define ANALOG__AGDET                            ((ANALOG_AGDET_Type *)ANALOG__AGDET_BASE)
/** Array initializer of ANALOG_AGDET peripheral base addresses */
#define ANALOG_AGDET_BASE_ADDRS                  { ANALOG__AGDET_BASE }
/** Array initializer of ANALOG_AGDET peripheral base pointers */
#define ANALOG_AGDET_BASE_PTRS                   { ANALOG__AGDET }

/* ANALOG_CMU - Peripheral instance base addresses */
/** Peripheral ANALOG__CMU0 base address */
#define ANALOG__CMU0_BASE                        (0x44670000u)
/** Peripheral ANALOG__CMU0 base pointer */
#define ANALOG__CMU0                             ((ANALOG_CMU_Type *)ANALOG__CMU0_BASE)
/** Array initializer of ANALOG_CMU peripheral base addresses */
#define ANALOG_CMU_BASE_ADDRS                    { ANALOG__CMU0_BASE }
/** Array initializer of ANALOG_CMU peripheral base pointers */
#define ANALOG_CMU_BASE_PTRS                     { ANALOG__CMU0 }

/* ANALOG_OSC24M - Peripheral instance base addresses */
/** Peripheral ANALOG__OSC24M base address */
#define ANALOG__OSC24M_BASE                      (0x44480000u)
/** Peripheral ANALOG__OSC24M base pointer */
#define ANALOG__OSC24M                           ((ANALOG_OSC24M_Type *)ANALOG__OSC24M_BASE)
/** Array initializer of ANALOG_OSC24M peripheral base addresses */
#define ANALOG_OSC24M_BASE_ADDRS                 { ANALOG__OSC24M_BASE }
/** Array initializer of ANALOG_OSC24M peripheral base pointers */
#define ANALOG_OSC24M_BASE_PTRS                  { ANALOG__OSC24M }

/* ANALOG_PMRO - Peripheral instance base addresses */
/** Peripheral ANALOG__PMRO base address */
#define ANALOG__PMRO_BASE                        (0x44484000u)
/** Peripheral ANALOG__PMRO base pointer */
#define ANALOG__PMRO                             ((ANALOG_PMRO_Type *)ANALOG__PMRO_BASE)
/** Array initializer of ANALOG_PMRO peripheral base addresses */
#define ANALOG_PMRO_BASE_ADDRS                   { ANALOG__PMRO_BASE }
/** Array initializer of ANALOG_PMRO peripheral base pointers */
#define ANALOG_PMRO_BASE_PTRS                    { ANALOG__PMRO }

/* ANALOG_SFA - Peripheral instance base addresses */
/** Peripheral ANALOG__SFA base address */
#define ANALOG__SFA_BASE                         (0x44483000u)
/** Peripheral ANALOG__SFA base pointer */
#define ANALOG__SFA                              ((ANALOG_SFA_Type *)ANALOG__SFA_BASE)
/** Array initializer of ANALOG_SFA peripheral base addresses */
#define ANALOG_SFA_BASE_ADDRS                    { ANALOG__SFA_BASE }
/** Array initializer of ANALOG_SFA peripheral base pointers */
#define ANALOG_SFA_BASE_PTRS                     { ANALOG__SFA }

/* ANALOG_TCU - Peripheral instance base addresses */
/** Peripheral ANALOG__TCU base address */
#define ANALOG__TCU_BASE                         (0x444C0000u)
/** Peripheral ANALOG__TCU base pointer */
#define ANALOG__TCU                              ((ANALOG_TCU_Type *)ANALOG__TCU_BASE)
/** Array initializer of ANALOG_TCU peripheral base addresses */
#define ANALOG_TCU_BASE_ADDRS                    { ANALOG__TCU_BASE }
/** Array initializer of ANALOG_TCU peripheral base pointers */
#define ANALOG_TCU_BASE_PTRS                     { ANALOG__TCU }

/* ANALOG_VDET - Peripheral instance base addresses */
/** Peripheral ANALOG__VDET base address */
#define ANALOG__VDET_BASE                        (0x44486000u)
/** Peripheral ANALOG__VDET base pointer */
#define ANALOG__VDET                             ((ANALOG_VDET_Type *)ANALOG__VDET_BASE)
/** Array initializer of ANALOG_VDET peripheral base addresses */
#define ANALOG_VDET_BASE_ADDRS                   { ANALOG__VDET_BASE }
/** Array initializer of ANALOG_VDET peripheral base pointers */
#define ANALOG_VDET_BASE_PTRS                    { ANALOG__VDET }

/* AOI - Peripheral instance base addresses */
/** Peripheral AOI1 base address */
#define AOI1_BASE                                (0x42840000u)
/** Peripheral AOI1 base pointer */
#define AOI1                                     ((AOI_Type *)AOI1_BASE)
/** Peripheral AOI2 base address */
#define AOI2_BASE                                (0x42844000u)
/** Peripheral AOI2 base pointer */
#define AOI2                                     ((AOI_Type *)AOI2_BASE)
/** Peripheral AOI3 base address */
#define AOI3_BASE                                (0x42848000u)
/** Peripheral AOI3 base pointer */
#define AOI3                                     ((AOI_Type *)AOI3_BASE)
/** Peripheral AOI4 base address */
#define AOI4_BASE                                (0x4284C000u)
/** Peripheral AOI4 base pointer */
#define AOI4                                     ((AOI_Type *)AOI4_BASE)
/** Array initializer of AOI peripheral base addresses */
#define AOI_BASE_ADDRS                           { 0u, AOI1_BASE, AOI2_BASE, AOI3_BASE, AOI4_BASE }
/** Array initializer of AOI peripheral base pointers */
#define AOI_BASE_PTRS                            { (AOI_Type *)0u, AOI1, AOI2, AOI3, AOI4 }

/* AON_CMU - Peripheral instance base addresses */
/** Peripheral AON__CMUA1 base address */
#define AON__CMUA1_BASE                          (0x44540000u)
/** Peripheral AON__CMUA1 base pointer */
#define AON__CMUA1                               ((AON_CMU_Type *)AON__CMUA1_BASE)
/** Peripheral AON__CMUA2 base address */
#define AON__CMUA2_BASE                          (0x44650000u)
/** Peripheral AON__CMUA2 base pointer */
#define AON__CMUA2                               ((AON_CMU_Type *)AON__CMUA2_BASE)
/** Array initializer of AON_CMU peripheral base addresses */
#define AON_CMU_BASE_ADDRS                       { AON__CMUA1_BASE, AON__CMUA2_BASE }
/** Array initializer of AON_CMU peripheral base pointers */
#define AON_CMU_BASE_PTRS                        { AON__CMUA1, AON__CMUA2 }

/* AON_CRC - Peripheral instance base addresses */
/** Peripheral AON__CRCA base address */
#define AON__CRCA_BASE                           (0x44660000u)
/** Peripheral AON__CRCA base pointer */
#define AON__CRCA                                ((AON_CRC_Type *)AON__CRCA_BASE)
/** Array initializer of AON_CRC peripheral base addresses */
#define AON_CRC_BASE_ADDRS                       { AON__CRCA_BASE }
/** Array initializer of AON_CRC peripheral base pointers */
#define AON_CRC_BASE_PTRS                        { AON__CRCA }

/* AON_CSTCU - Peripheral instance base addresses */
/** Peripheral AON__CSTCU base address */
#define AON__CSTCU_BASE                          (0x44590000u)
/** Peripheral AON__CSTCU base pointer */
#define AON__CSTCU                               ((AON_CSTCU_Type *)AON__CSTCU_BASE)
/** Array initializer of AON_CSTCU peripheral base addresses */
#define AON_CSTCU_BASE_ADDRS                     { AON__CSTCU_BASE }
/** Array initializer of AON_CSTCU peripheral base pointers */
#define AON_CSTCU_BASE_PTRS                      { AON__CSTCU }

/* AON_EIM - Peripheral instance base addresses */
/** Peripheral AON__EIMA base address */
#define AON__EIMA_BASE                           (0x44550000u)
/** Peripheral AON__EIMA base pointer */
#define AON__EIMA                                ((AON_EIM_Type *)AON__EIMA_BASE)
/** Array initializer of AON_EIM peripheral base addresses */
#define AON_EIM_BASE_ADDRS                       { AON__EIMA_BASE }
/** Array initializer of AON_EIM peripheral base pointers */
#define AON_EIM_BASE_PTRS                        { AON__EIMA }

/* AON_FCCU - Peripheral instance base addresses */
/** Peripheral AON__FCCU base address */
#define AON__FCCU_BASE                           (0x44570000u)
/** Peripheral AON__FCCU base pointer */
#define AON__FCCU                                ((AON_FCCU_Type *)AON__FCCU_BASE)
/** Array initializer of AON_FCCU peripheral base addresses */
#define AON_FCCU_BASE_ADDRS                      { AON__FCCU_BASE }
/** Array initializer of AON_FCCU peripheral base pointers */
#define AON_FCCU_BASE_PTRS                       { AON__FCCU }

/* AON_INTM - Peripheral instance base addresses */
/** Peripheral AON__INTM base address */
#define AON__INTM_BASE                           (0x44580000u)
/** Peripheral AON__INTM base pointer */
#define AON__INTM                                ((AON_INTM_Type *)AON__INTM_BASE)
/** Array initializer of AON_INTM peripheral base addresses */
#define AON_INTM_BASE_ADDRS                      { AON__INTM_BASE }
/** Array initializer of AON_INTM peripheral base pointers */
#define AON_INTM_BASE_PTRS                       { AON__INTM }

/* AON_LSTCU - Peripheral instance base addresses */
/** Peripheral AON__LSTCUA base address */
#define AON__LSTCUA_BASE                         (0x445A0000u)
/** Peripheral AON__LSTCUA base pointer */
#define AON__LSTCUA                              ((AON_LSTCU_Type *)AON__LSTCUA_BASE)
/** Array initializer of AON_LSTCU peripheral base addresses */
#define AON_LSTCU_BASE_ADDRS                     { AON__LSTCUA_BASE }
/** Array initializer of AON_LSTCU peripheral base pointers */
#define AON_LSTCU_BASE_PTRS                      { AON__LSTCUA }

/* AON_MCM - Peripheral instance base addresses */
/** Peripheral AON__MCM base address */
#define AON__MCM_BASE                            (0xE0080000u)
/** Peripheral AON__MCM base pointer */
#define AON__MCM                                 ((AON_MCM_Type *)AON__MCM_BASE)
/** Array initializer of AON_MCM peripheral base addresses */
#define AON_MCM_BASE_ADDRS                       { AON__MCM_BASE }
/** Array initializer of AON_MCM peripheral base pointers */
#define AON_MCM_BASE_PTRS                        { AON__MCM }

/* AON_ROMCP - Peripheral instance base addresses */
/** Peripheral AON__ROMCP1 base address */
#define AON__ROMCP1_BASE                         (0x44430000u)
/** Peripheral AON__ROMCP1 base pointer */
#define AON__ROMCP1                              ((AON_ROMCP_Type *)AON__ROMCP1_BASE)
/** Array initializer of AON_ROMCP peripheral base addresses */
#define AON_ROMCP_BASE_ADDRS                     { AON__ROMCP1_BASE }
/** Array initializer of AON_ROMCP peripheral base pointers */
#define AON_ROMCP_BASE_PTRS                      { AON__ROMCP1 }

/* AON_SYSPM - Peripheral instance base addresses */
/** Peripheral AON__M33_PCF1 base address */
#define AON__M33_PCF1_BASE                       (0x443E0000u)
/** Peripheral AON__M33_PCF1 base pointer */
#define AON__M33_PCF1                            ((AON_SYSPM_Type *)AON__M33_PCF1_BASE)
/** Peripheral AON__M33_PSF1 base address */
#define AON__M33_PSF1_BASE                       (0x443F0000u)
/** Peripheral AON__M33_PSF1 base pointer */
#define AON__M33_PSF1                            ((AON_SYSPM_Type *)AON__M33_PSF1_BASE)
/** Array initializer of AON_SYSPM peripheral base addresses */
#define AON_SYSPM_BASE_ADDRS                     { AON__M33_PCF1_BASE, AON__M33_PSF1_BASE }
/** Array initializer of AON_SYSPM peripheral base pointers */
#define AON_SYSPM_BASE_PTRS                      { AON__M33_PCF1, AON__M33_PSF1 }

/* AON_TCU - Peripheral instance base addresses */
/** Peripheral AON__TCU base address */
#define AON__TCU_BASE                            (0x444B0000u)
/** Peripheral AON__TCU base pointer */
#define AON__TCU                                 ((AON_TCU_Type *)AON__TCU_BASE)
/** Array initializer of AON_TCU peripheral base addresses */
#define AON_TCU_BASE_ADDRS                       { AON__TCU_BASE }
/** Array initializer of AON_TCU peripheral base pointers */
#define AON_TCU_BASE_PTRS                        { AON__TCU }

/* AON_TRDC_MGR - Peripheral instance base addresses */
/** Peripheral AON__TRDC_MGR base address */
#define AON__TRDC_MGR_BASE                       (0x44270000u)
/** Peripheral AON__TRDC_MGR base pointer */
#define AON__TRDC_MGR                            ((AON_TRDC_MGR_Type *)AON__TRDC_MGR_BASE)
/** Array initializer of AON_TRDC_MGR peripheral base addresses */
#define AON_TRDC_MGR_BASE_ADDRS                  { AON__TRDC_MGR_BASE }
/** Array initializer of AON_TRDC_MGR peripheral base pointers */
#define AON_TRDC_MGR_BASE_PTRS                   { AON__TRDC_MGR }

/* ARDB - Peripheral instance base addresses */
/** Peripheral WAKEUP__XSPI1__ARDB base address */
#define WAKEUP__XSPI1__ARDB_BASE                 (0x42B90000u)
/** Peripheral WAKEUP__XSPI1__ARDB base pointer */
#define WAKEUP__XSPI1__ARDB                      ((ARDB_Type *)WAKEUP__XSPI1__ARDB_BASE)
/** Peripheral WAKEUP__XSPI2__ARDB base address */
#define WAKEUP__XSPI2__ARDB_BASE                 (0x42BE0000u)
/** Peripheral WAKEUP__XSPI2__ARDB base pointer */
#define WAKEUP__XSPI2__ARDB                      ((ARDB_Type *)WAKEUP__XSPI2__ARDB_BASE)
/** Array initializer of ARDB peripheral base addresses */
#define ARDB_BASE_ADDRS                          { WAKEUP__XSPI1__ARDB_BASE, WAKEUP__XSPI2__ARDB_BASE }
/** Array initializer of ARDB peripheral base pointers */
#define ARDB_BASE_PTRS                           { WAKEUP__XSPI1__ARDB, WAKEUP__XSPI2__ARDB }

/* ATU_USB2 - Peripheral instance base addresses */
/** Peripheral HSIO__ATU_USB2 base address */
#define HSIO__ATU_USB2_BASE                      (0x4C070000u)
/** Peripheral HSIO__ATU_USB2 base pointer */
#define HSIO__ATU_USB2                           ((ATU_USB2_Type *)HSIO__ATU_USB2_BASE)
/** Array initializer of ATU_USB2 peripheral base addresses */
#define ATU_USB2_BASE_ADDRS                      { HSIO__ATU_USB2_BASE }
/** Array initializer of ATU_USB2 peripheral base pointers */
#define ATU_USB2_BASE_PTRS                       { HSIO__ATU_USB2 }

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

/* BBSM_BLK_CTRL_BBSMMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_BBSMMIX base address */
#define BLK_CTRL_BBSMMIX_BASE                    (0x44410000u)
/** Peripheral BLK_CTRL_BBSMMIX base pointer */
#define BLK_CTRL_BBSMMIX                         ((BBSM_BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BASE)
/** Array initializer of BBSM_BLK_CTRL_BBSMMIX peripheral base addresses */
#define BBSM_BLK_CTRL_BBSMMIX_BASE_ADDRS         { BLK_CTRL_BBSMMIX_BASE }
/** Array initializer of BBSM_BLK_CTRL_BBSMMIX peripheral base pointers */
#define BBSM_BLK_CTRL_BBSMMIX_BASE_PTRS          { BLK_CTRL_BBSMMIX }

/* BBSM_TCU - Peripheral instance base addresses */
/** Peripheral BBSM__TCU_BBSMMIX base address */
#define BBSM__TCU_BBSMMIX_BASE                   (0x444E0000u)
/** Peripheral BBSM__TCU_BBSMMIX base pointer */
#define BBSM__TCU_BBSMMIX                        ((BBSM_TCU_Type *)BBSM__TCU_BBSMMIX_BASE)
/** Array initializer of BBSM_TCU peripheral base addresses */
#define BBSM_TCU_BASE_ADDRS                      { BBSM__TCU_BBSMMIX_BASE }
/** Array initializer of BBSM_TCU peripheral base pointers */
#define BBSM_TCU_BASE_PTRS                       { BBSM__TCU_BBSMMIX }

/* BISS - Peripheral instance base addresses */
/** Peripheral BISS1 base address */
#define BISS1_BASE                               (0x42CE0000u)
/** Peripheral BISS1 base pointer */
#define BISS1                                    ((BISS_Type *)BISS1_BASE)
/** Array initializer of BISS peripheral base addresses */
#define BISS_BASE_ADDRS                          { BISS1_BASE }
/** Array initializer of BISS peripheral base pointers */
#define BISS_BASE_PTRS                           { BISS1 }

/* BLK_CTRL_NETCMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_NETCMIX base address */
#define BLK_CTRL_NETCMIX_BASE                    (0x4C810000u)
/** Peripheral BLK_CTRL_NETCMIX base pointer */
#define BLK_CTRL_NETCMIX                         ((BLK_CTRL_NETCMIX_Type *)BLK_CTRL_NETCMIX_BASE)
/** Array initializer of BLK_CTRL_NETCMIX peripheral base addresses */
#define BLK_CTRL_NETCMIX_BASE_ADDRS              { BLK_CTRL_NETCMIX_BASE }
/** Array initializer of BLK_CTRL_NETCMIX peripheral base pointers */
#define BLK_CTRL_NETCMIX_BASE_PTRS               { BLK_CTRL_NETCMIX }

/* BLK_CTRL_NS_AONMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_NS_AONMIX base address */
#define BLK_CTRL_NS_AONMIX_BASE                  (0x44210000u)
/** Peripheral BLK_CTRL_NS_AONMIX base pointer */
#define BLK_CTRL_NS_AONMIX                       ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX_BASE)
/** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
#define BLK_CTRL_NS_AONMIX_BASE_ADDRS            { BLK_CTRL_NS_AONMIX_BASE }
/** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
#define BLK_CTRL_NS_AONMIX_BASE_PTRS             { BLK_CTRL_NS_AONMIX }

/* BLK_CTRL_S_AONMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_S_AONMIX base address */
#define BLK_CTRL_S_AONMIX_BASE                   (0x444F0000u)
/** Peripheral BLK_CTRL_S_AONMIX base pointer */
#define BLK_CTRL_S_AONMIX                        ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX_BASE)
/** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
#define BLK_CTRL_S_AONMIX_BASE_ADDRS             { BLK_CTRL_S_AONMIX_BASE }
/** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
#define BLK_CTRL_S_AONMIX_BASE_PTRS              { BLK_CTRL_S_AONMIX }

/* BLK_CTRL_WAKEUPMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_WAKEUPMIX base address */
#define BLK_CTRL_WAKEUPMIX_BASE                  (0x42420000u)
/** Peripheral BLK_CTRL_WAKEUPMIX base pointer */
#define BLK_CTRL_WAKEUPMIX                       ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX_BASE)
/** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
#define BLK_CTRL_WAKEUPMIX_BASE_ADDRS            { BLK_CTRL_WAKEUPMIX_BASE }
/** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
#define BLK_CTRL_WAKEUPMIX_BASE_PTRS             { BLK_CTRL_WAKEUPMIX }

/* CACHE_ECC_MCM - Peripheral instance base addresses */
/** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base address */
#define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE (0x44401000u)
/** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base pointer */
#define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM ((CACHE_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE)
/** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base address */
#define NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE (0x4D1A1000u)
/** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base pointer */
#define NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM ((CACHE_ECC_MCM_Type *)NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE)
/** Array initializer of CACHE_ECC_MCM peripheral base addresses */
#define CACHE_ECC_MCM_BASE_ADDRS                 { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE, NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE }
/** Array initializer of CACHE_ECC_MCM peripheral base pointers */
#define CACHE_ECC_MCM_BASE_PTRS                  { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM, NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM }

/* CAMERA_ATU - Peripheral instance base addresses */
/** Peripheral DISPLAY__ATU base address */
#define DISPLAY__ATU_BASE                        (0x4B060000u)
/** Peripheral DISPLAY__ATU base pointer */
#define DISPLAY__ATU                             ((CAMERA_ATU_Type *)DISPLAY__ATU_BASE)
/** Array initializer of CAMERA_ATU peripheral base addresses */
#define CAMERA_ATU_BASE_ADDRS                    { DISPLAY__ATU_BASE }
/** Array initializer of CAMERA_ATU peripheral base pointers */
#define CAMERA_ATU_BASE_PTRS                     { DISPLAY__ATU }

/* CAMIX_BLK_CTRL - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_CAMIX base address */
#define BLK_CTRL_CAMIX_BASE                      (0x4A410000u)
/** Peripheral BLK_CTRL_CAMIX base pointer */
#define BLK_CTRL_CAMIX                           ((CAMIX_BLK_CTRL_Type *)BLK_CTRL_CAMIX_BASE)
/** Array initializer of CAMIX_BLK_CTRL peripheral base addresses */
#define CAMIX_BLK_CTRL_BASE_ADDRS                { BLK_CTRL_CAMIX_BASE }
/** Array initializer of CAMIX_BLK_CTRL peripheral base pointers */
#define CAMIX_BLK_CTRL_BASE_PTRS                 { BLK_CTRL_CAMIX }

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN1 base address */
#define CAN1_BASE                                (0x443A0000u)
/** Peripheral CAN1 base pointer */
#define CAN1                                     ((CAN_Type *)CAN1_BASE)
/** Peripheral CAN2 base address */
#define CAN2_BASE                                (0x425B0000u)
/** Peripheral CAN2 base pointer */
#define CAN2                                     ((CAN_Type *)CAN2_BASE)
/** Peripheral CAN3 base address */
#define CAN3_BASE                                (0x425E0000u)
/** Peripheral CAN3 base pointer */
#define CAN3                                     ((CAN_Type *)CAN3_BASE)
/** Peripheral CAN4 base address */
#define CAN4_BASE                                (0x425F0000u)
/** Peripheral CAN4 base pointer */
#define CAN4                                     ((CAN_Type *)CAN4_BASE)
/** Peripheral CAN5 base address */
#define CAN5_BASE                                (0x42600000u)
/** Peripheral CAN5 base pointer */
#define CAN5                                     ((CAN_Type *)CAN5_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { 0u, CAN1_BASE, CAN2_BASE, CAN3_BASE, CAN4_BASE, CAN5_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { (CAN_Type *)0u, CAN1, CAN2, CAN3, CAN4, CAN5 }
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn, CAN4_IRQn, CAN5_IRQn }
#define CAN_Tx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn, CAN4_IRQn, CAN5_IRQn }
#define CAN_Wake_Up_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn, CAN4_IRQn, CAN5_IRQn }
#define CAN_Error_IRQS                           { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn, CAN4_IRQn, CAN5_IRQn }
#define CAN_Bus_Off_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn, CAN4_IRQn, CAN5_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { NotAvail_IRQn, CAN1_IRQn, CAN1_IRQn, CAN2_IRQn, CAN2_IRQn, CAN3_IRQn, CAN3_IRQn, CAN4_IRQn, CAN4_IRQn, CAN5_IRQn, CAN5_IRQn }

/* CCM - Peripheral instance base addresses */
/** Peripheral CCM_CTRL base address */
#define CCM_CTRL_BASE                            (0x44450000u)
/** Peripheral CCM_CTRL base pointer */
#define CCM_CTRL                                 ((CCM_Type *)CCM_CTRL_BASE)
/** Array initializer of CCM peripheral base addresses */
#define CCM_BASE_ADDRS                           { CCM_CTRL_BASE }
/** Array initializer of CCM peripheral base pointers */
#define CCM_BASE_PTRS                            { CCM_CTRL }

/* CCMSRCGPC_TCU - Peripheral instance base addresses */
/** Peripheral CCMSRCGPC__TCU base address */
#define CCMSRCGPC__TCU_BASE                      (0x444D0000u)
/** Peripheral CCMSRCGPC__TCU base pointer */
#define CCMSRCGPC__TCU                           ((CCMSRCGPC_TCU_Type *)CCMSRCGPC__TCU_BASE)
/** Array initializer of CCMSRCGPC_TCU peripheral base addresses */
#define CCMSRCGPC_TCU_BASE_ADDRS                 { CCMSRCGPC__TCU_BASE }
/** Array initializer of CCMSRCGPC_TCU peripheral base pointers */
#define CCMSRCGPC_TCU_BASE_PTRS                  { CCMSRCGPC__TCU }

/* CORTEXA_TCU - Peripheral instance base addresses */
/** Peripheral CORTEXA__TCU base address */
#define CORTEXA__TCU_BASE                        (0x4A400000u)
/** Peripheral CORTEXA__TCU base pointer */
#define CORTEXA__TCU                             ((CORTEXA_TCU_Type *)CORTEXA__TCU_BASE)
/** Array initializer of CORTEXA_TCU peripheral base addresses */
#define CORTEXA_TCU_BASE_ADDRS                   { CORTEXA__TCU_BASE }
/** Array initializer of CORTEXA_TCU peripheral base pointers */
#define CORTEXA_TCU_BASE_PTRS                    { CORTEXA__TCU }

/* DCIF - Peripheral instance base addresses */
/** Peripheral DCIF base address */
#define DCIF_BASE                                (0x4B120000u)
/** Peripheral DCIF base pointer */
#define DCIF                                     ((DCIF_Type *)DCIF_BASE)
/** Array initializer of DCIF peripheral base addresses */
#define DCIF_BASE_ADDRS                          { DCIF_BASE }
/** Array initializer of DCIF peripheral base pointers */
#define DCIF_BASE_PTRS                           { DCIF }

/* DDR_BLK_CTRL_DDRMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_DDRMIX base address */
#define BLK_CTRL_DDRMIX_BASE                     (0x4E010000u)
/** Peripheral BLK_CTRL_DDRMIX base pointer */
#define BLK_CTRL_DDRMIX                          ((DDR_BLK_CTRL_DDRMIX_Type *)BLK_CTRL_DDRMIX_BASE)
/** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base addresses */
#define DDR_BLK_CTRL_DDRMIX_BASE_ADDRS           { BLK_CTRL_DDRMIX_BASE }
/** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base pointers */
#define DDR_BLK_CTRL_DDRMIX_BASE_PTRS            { BLK_CTRL_DDRMIX }

/* DDR_CMU - Peripheral instance base addresses */
/** Peripheral DDRC__CMU_1 base address */
#define DDRC__CMU_1_BASE                         (0x4E060000u)
/** Peripheral DDRC__CMU_1 base pointer */
#define DDRC__CMU_1                              ((DDR_CMU_Type *)DDRC__CMU_1_BASE)
/** Peripheral DDRC__CMU_2 base address */
#define DDRC__CMU_2_BASE                         (0x4E070000u)
/** Peripheral DDRC__CMU_2 base pointer */
#define DDRC__CMU_2                              ((DDR_CMU_Type *)DDRC__CMU_2_BASE)
/** Array initializer of DDR_CMU peripheral base addresses */
#define DDR_CMU_BASE_ADDRS                       { DDRC__CMU_1_BASE, DDRC__CMU_2_BASE }
/** Array initializer of DDR_CMU peripheral base pointers */
#define DDR_CMU_BASE_PTRS                        { DDRC__CMU_1, DDRC__CMU_2 }

/* DDR_DDRC - Peripheral instance base addresses */
/** Peripheral DDRC base address */
#define DDRC_BASE                                (0x4E080000u)
/** Peripheral DDRC base pointer */
#define DDRC                                     ((DDR_DDRC_Type *)DDRC_BASE)
/** Array initializer of DDR_DDRC peripheral base addresses */
#define DDR_DDRC_BASE_ADDRS                      { DDRC_BASE }
/** Array initializer of DDR_DDRC peripheral base pointers */
#define DDR_DDRC_BASE_PTRS                       { DDRC }

/* DDR_LSTCU - Peripheral instance base addresses */
/** Peripheral DDRC__LSTCU base address */
#define DDRC__LSTCU_BASE                         (0x4E050000u)
/** Peripheral DDRC__LSTCU base pointer */
#define DDRC__LSTCU                              ((DDR_LSTCU_Type *)DDRC__LSTCU_BASE)
/** Array initializer of DDR_LSTCU peripheral base addresses */
#define DDR_LSTCU_BASE_ADDRS                     { DDRC__LSTCU_BASE }
/** Array initializer of DDR_LSTCU peripheral base pointers */
#define DDR_LSTCU_BASE_PTRS                      { DDRC__LSTCU }

/* DDR_TCU - Peripheral instance base addresses */
/** Peripheral DDRC__TCU base address */
#define DDRC__TCU_BASE                           (0x4E000000u)
/** Peripheral DDRC__TCU base pointer */
#define DDRC__TCU                                ((DDR_TCU_Type *)DDRC__TCU_BASE)
/** Array initializer of DDR_TCU peripheral base addresses */
#define DDR_TCU_BASE_ADDRS                       { DDRC__TCU_BASE }
/** Array initializer of DDR_TCU peripheral base pointers */
#define DDR_TCU_BASE_PTRS                        { DDRC__TCU }

/* DISPLAY_BLK_CTRL_DISPLAYMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_DISPLAYMIX base address */
#define BLK_CTRL_DISPLAYMIX_BASE                 (0x4B010000u)
/** Peripheral BLK_CTRL_DISPLAYMIX base pointer */
#define BLK_CTRL_DISPLAYMIX                      ((DISPLAY_BLK_CTRL_DISPLAYMIX_Type *)BLK_CTRL_DISPLAYMIX_BASE)
/** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base addresses */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_ADDRS   { BLK_CTRL_DISPLAYMIX_BASE }
/** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base pointers */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_PTRS    { BLK_CTRL_DISPLAYMIX }

/* DISPLAY_BLK_CTRL_LVDS - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_LVDS base address */
#define BLK_CTRL_LVDS_BASE                       (0x4B0C0000u)
/** Peripheral BLK_CTRL_LVDS base pointer */
#define BLK_CTRL_LVDS                            ((DISPLAY_BLK_CTRL_LVDS_Type *)BLK_CTRL_LVDS_BASE)
/** Array initializer of DISPLAY_BLK_CTRL_LVDS peripheral base addresses */
#define DISPLAY_BLK_CTRL_LVDS_BASE_ADDRS         { BLK_CTRL_LVDS_BASE }
/** Array initializer of DISPLAY_BLK_CTRL_LVDS peripheral base pointers */
#define DISPLAY_BLK_CTRL_LVDS_BASE_PTRS          { BLK_CTRL_LVDS }

/* DISPLAY_TCU - Peripheral instance base addresses */
/** Peripheral DISPLAY__TCU base address */
#define DISPLAY__TCU_BASE                        (0x4B000000u)
/** Peripheral DISPLAY__TCU base pointer */
#define DISPLAY__TCU                             ((DISPLAY_TCU_Type *)DISPLAY__TCU_BASE)
/** Array initializer of DISPLAY_TCU peripheral base addresses */
#define DISPLAY_TCU_BASE_ADDRS                   { DISPLAY__TCU_BASE }
/** Array initializer of DISPLAY_TCU peripheral base pointers */
#define DISPLAY_TCU_BASE_PTRS                    { DISPLAY__TCU }

/* DISPLAY_TRDC_MGR - Peripheral instance base addresses */
/** Peripheral DISPLAY__TRDC_MGR_D base address */
#define DISPLAY__TRDC_MGR_D_BASE                 (0x4B040000u)
/** Peripheral DISPLAY__TRDC_MGR_D base pointer */
#define DISPLAY__TRDC_MGR_D                      ((DISPLAY_TRDC_MGR_Type *)DISPLAY__TRDC_MGR_D_BASE)
/** Array initializer of DISPLAY_TRDC_MGR peripheral base addresses */
#define DISPLAY_TRDC_MGR_BASE_ADDRS              { DISPLAY__TRDC_MGR_D_BASE }
/** Array initializer of DISPLAY_TRDC_MGR peripheral base pointers */
#define DISPLAY_TRDC_MGR_BASE_PTRS               { DISPLAY__TRDC_MGR_D }

/* DMA - Peripheral instance base addresses */
/** Peripheral EDMA1 base address */
#define EDMA1_BASE                               (0x44000000u)
/** Peripheral EDMA1 base pointer */
#define EDMA1                                    ((DMA_Type *)EDMA1_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { EDMA1_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { EDMA1 }

/* DMA5 - Peripheral instance base addresses */
/** Peripheral EDMA2 base address */
#define EDMA2_BASE                               (0x42000000u)
/** Peripheral EDMA2 base pointer */
#define EDMA2                                    ((DMA5_Type *)EDMA2_BASE)
/** Peripheral EDMA3 base address */
#define EDMA3_BASE                               (0x42210000u)
/** Peripheral EDMA3 base pointer */
#define EDMA3                                    ((DMA5_Type *)EDMA3_BASE)
/** Peripheral EDMA4 base address */
#define EDMA4_BASE                               (0x42DF0000u)
/** Peripheral EDMA4 base pointer */
#define EDMA4                                    ((DMA5_Type *)EDMA4_BASE)
/** Array initializer of DMA5 peripheral base addresses */
#define DMA5_BASE_ADDRS                          { 0u, 0u, EDMA2_BASE, EDMA3_BASE, EDMA4_BASE }
/** Array initializer of DMA5 peripheral base pointers */
#define DMA5_BASE_PTRS                           { (DMA5_Type *)0u, (DMA5_Type *)0u, EDMA2, EDMA3, EDMA4 }

/* DWC_usb3 - Peripheral instance base addresses */
/** Peripheral HSIO__USB_3_01__USB3 base address */
#define HSIO__USB_3_01__USB3_BASE                (0x4C100000u)
/** Peripheral HSIO__USB_3_01__USB3 base pointer */
#define HSIO__USB_3_01__USB3                     ((DWC_usb3_Type *)HSIO__USB_3_01__USB3_BASE)
/** Array initializer of DWC_usb3 peripheral base addresses */
#define DWC_usb3_BASE_ADDRS                      { HSIO__USB_3_01__USB3_BASE }
/** Array initializer of DWC_usb3 peripheral base pointers */
#define DWC_usb3_BASE_PTRS                       { HSIO__USB_3_01__USB3 }

/* ECAT - Peripheral instance base addresses */
/** Peripheral ETHERCAT base address */
#define ETHERCAT_BASE                            (0x4CF80000u)
/** Peripheral ETHERCAT base pointer */
#define ETHERCAT                                 ((ECAT_Type *)ETHERCAT_BASE)
/** Array initializer of ECAT peripheral base addresses */
#define ECAT_BASE_ADDRS                          { ETHERCAT_BASE }
/** Array initializer of ECAT peripheral base pointers */
#define ECAT_BASE_PTRS                           { ETHERCAT }

/* ENDAT2P2 - Peripheral instance base addresses */
/** Peripheral ENDAT2P2_1 base address */
#define ENDAT2P2_1_BASE                          (0x42CB0000u)
/** Peripheral ENDAT2P2_1 base pointer */
#define ENDAT2P2_1                               ((ENDAT2P2_Type *)ENDAT2P2_1_BASE)
/** Peripheral ENDAT2P2_2 base address */
#define ENDAT2P2_2_BASE                          (0x42CC0000u)
/** Peripheral ENDAT2P2_2 base pointer */
#define ENDAT2P2_2                               ((ENDAT2P2_Type *)ENDAT2P2_2_BASE)
/** Array initializer of ENDAT2P2 peripheral base addresses */
#define ENDAT2P2_BASE_ADDRS                      { ENDAT2P2_1_BASE, ENDAT2P2_2_BASE }
/** Array initializer of ENDAT2P2 peripheral base pointers */
#define ENDAT2P2_BASE_PTRS                       { ENDAT2P2_1, ENDAT2P2_2 }

/* ENDAT3 - Peripheral instance base addresses */
/** Peripheral ENDAT3 base address */
#define ENDAT3_BASE                              (0x42CD0000u)
/** Peripheral ENDAT3 base pointer */
#define ENDAT3                                   ((ENDAT3_Type *)ENDAT3_BASE)
/** Array initializer of ENDAT3 peripheral base addresses */
#define ENDAT3_BASE_ADDRS                        { ENDAT3_BASE }
/** Array initializer of ENDAT3 peripheral base pointers */
#define ENDAT3_BASE_PTRS                         { ENDAT3 }

/* ENETC_COMMON - Peripheral instance base addresses */
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE (0x4CD51000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON ((ENETC_COMMON_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE)
/** Array initializer of ENETC_COMMON peripheral base addresses */
#define ENETC_COMMON_BASE_ADDRS                  { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE }
/** Array initializer of ENETC_COMMON peripheral base pointers */
#define ENETC_COMMON_BASE_PTRS                   { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON }

/* ENETC_GLOBAL - Peripheral instance base addresses */
/** Peripheral EMDIO_GLOBAL base address */
#define EMDIO_GLOBAL_BASE                        (0x4CDF0000u)
/** Peripheral EMDIO_GLOBAL base pointer */
#define EMDIO_GLOBAL                             ((ENETC_GLOBAL_Type *)EMDIO_GLOBAL_BASE)
/** Peripheral ENETC0_GLOBAL base address */
#define ENETC0_GLOBAL_BASE                       (0x4CCA0000u)
/** Peripheral ENETC0_GLOBAL base pointer */
#define ENETC0_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC0_GLOBAL_BASE)
/** Peripheral ENETC1_GLOBAL base address */
#define ENETC1_GLOBAL_BASE                       (0x4CCE0000u)
/** Peripheral ENETC1_GLOBAL base pointer */
#define ENETC1_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC1_GLOBAL_BASE)
/** Peripheral ENETC2_GLOBAL base address */
#define ENETC2_GLOBAL_BASE                       (0x4CD20000u)
/** Peripheral ENETC2_GLOBAL base pointer */
#define ENETC2_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC2_GLOBAL_BASE)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL_BASE (0x4CD60000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL ((ENETC_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL_BASE)
/** Peripheral TMR0_GLOBAL base address */
#define TMR0_GLOBAL_BASE                         (0x4CD90000u)
/** Peripheral TMR0_GLOBAL base pointer */
#define TMR0_GLOBAL                              ((ENETC_GLOBAL_Type *)TMR0_GLOBAL_BASE)
/** Array initializer of ENETC_GLOBAL peripheral base addresses */
#define ENETC_GLOBAL_BASE_ADDRS                  { EMDIO_GLOBAL_BASE, ENETC0_GLOBAL_BASE, ENETC1_GLOBAL_BASE, ENETC2_GLOBAL_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL_BASE, TMR0_GLOBAL_BASE }
/** Array initializer of ENETC_GLOBAL peripheral base pointers */
#define ENETC_GLOBAL_BASE_PTRS                   { EMDIO_GLOBAL, ENETC0_GLOBAL, ENETC1_GLOBAL, ENETC2_GLOBAL, NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL, TMR0_GLOBAL }

/* ENETC_PCI_TYPE0 - Peripheral instance base addresses */
/** Peripheral EMDIO0_PCI_HDR_TYPE0 base address */
#define EMDIO0_PCI_HDR_TYPE0_BASE                (0x4CBC0000u)
/** Peripheral EMDIO0_PCI_HDR_TYPE0 base pointer */
#define EMDIO0_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)EMDIO0_PCI_HDR_TYPE0_BASE)
/** Peripheral ENETC0_PCI_HDR_TYPE0 base address */
#define ENETC0_PCI_HDR_TYPE0_BASE                (0x4CB00000u)
/** Peripheral ENETC0_PCI_HDR_TYPE0 base pointer */
#define ENETC0_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)ENETC0_PCI_HDR_TYPE0_BASE)
/** Peripheral ENETC1_PCI_HDR_TYPE0 base address */
#define ENETC1_PCI_HDR_TYPE0_BASE                (0x4CB40000u)
/** Peripheral ENETC1_PCI_HDR_TYPE0 base pointer */
#define ENETC1_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)ENETC1_PCI_HDR_TYPE0_BASE)
/** Peripheral ENETC2_PCI_HDR_TYPE0 base address */
#define ENETC2_PCI_HDR_TYPE0_BASE                (0x4CB80000u)
/** Peripheral ENETC2_PCI_HDR_TYPE0 base pointer */
#define ENETC2_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)ENETC2_PCI_HDR_TYPE0_BASE)
/** Peripheral ENETC3_PCI_HDR_TYPE0 base address */
#define ENETC3_PCI_HDR_TYPE0_BASE                (0x4CA00000u)
/** Peripheral ENETC3_PCI_HDR_TYPE0 base pointer */
#define ENETC3_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)ENETC3_PCI_HDR_TYPE0_BASE)
/** Peripheral SW0_PCI_HDR_TYPE0 base address */
#define SW0_PCI_HDR_TYPE0_BASE                   (0x4CA02000u)
/** Peripheral SW0_PCI_HDR_TYPE0 base pointer */
#define SW0_PCI_HDR_TYPE0                        ((ENETC_PCI_TYPE0_Type *)SW0_PCI_HDR_TYPE0_BASE)
/** Peripheral TMR0_PCI_HDR_TYPE0 base address */
#define TMR0_PCI_HDR_TYPE0_BASE                  (0x4CA01000u)
/** Peripheral TMR0_PCI_HDR_TYPE0 base pointer */
#define TMR0_PCI_HDR_TYPE0                       ((ENETC_PCI_TYPE0_Type *)TMR0_PCI_HDR_TYPE0_BASE)
/** Array initializer of ENETC_PCI_TYPE0 peripheral base addresses */
#define ENETC_PCI_TYPE0_BASE_ADDRS               { EMDIO0_PCI_HDR_TYPE0_BASE, ENETC0_PCI_HDR_TYPE0_BASE, ENETC1_PCI_HDR_TYPE0_BASE, ENETC2_PCI_HDR_TYPE0_BASE, ENETC3_PCI_HDR_TYPE0_BASE, SW0_PCI_HDR_TYPE0_BASE, TMR0_PCI_HDR_TYPE0_BASE }
/** Array initializer of ENETC_PCI_TYPE0 peripheral base pointers */
#define ENETC_PCI_TYPE0_BASE_PTRS                { EMDIO0_PCI_HDR_TYPE0, ENETC0_PCI_HDR_TYPE0, ENETC1_PCI_HDR_TYPE0, ENETC2_PCI_HDR_TYPE0, ENETC3_PCI_HDR_TYPE0, SW0_PCI_HDR_TYPE0, TMR0_PCI_HDR_TYPE0 }

/* ENETC_PF_EMDIO - Peripheral instance base addresses */
/** Peripheral EMDIO_BASE base address */
#define EMDIO_BASE_BASE                          (0x4CDE0000u)
/** Peripheral EMDIO_BASE base pointer */
#define EMDIO_BASE                               ((ENETC_PF_EMDIO_Type *)EMDIO_BASE_BASE)
/** Array initializer of ENETC_PF_EMDIO peripheral base addresses */
#define ENETC_PF_EMDIO_BASE_ADDRS                { EMDIO_BASE_BASE }
/** Array initializer of ENETC_PF_EMDIO peripheral base pointers */
#define ENETC_PF_EMDIO_BASE_PTRS                 { EMDIO_BASE }

/* ENETC_PF_TMR - Peripheral instance base addresses */
/** Peripheral TMR0_BASE base address */
#define TMR0_BASE_BASE                           (0x4CD80000u)
/** Peripheral TMR0_BASE base pointer */
#define TMR0_BASE                                ((ENETC_PF_TMR_Type *)TMR0_BASE_BASE)
/** Array initializer of ENETC_PF_TMR peripheral base addresses */
#define ENETC_PF_TMR_BASE_ADDRS                  { TMR0_BASE_BASE }
/** Array initializer of ENETC_PF_TMR peripheral base pointers */
#define ENETC_PF_TMR_BASE_PTRS                   { TMR0_BASE }

/* ENETC_PORT - Peripheral instance base addresses */
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE (0x4CD54000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT ((ENETC_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE)
/** Array initializer of ENETC_PORT peripheral base addresses */
#define ENETC_PORT_BASE_ADDRS                    { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE }
/** Array initializer of ENETC_PORT peripheral base pointers */
#define ENETC_PORT_BASE_PTRS                     { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT }

/* ENETC_SI - Peripheral instance base addresses */
/** Peripheral ENETC0_PSI base address */
#define ENETC0_PSI_BASE                          (0x4CC80000u)
/** Peripheral ENETC0_PSI base pointer */
#define ENETC0_PSI                               ((ENETC_SI_Type *)ENETC0_PSI_BASE)
/** Peripheral ENETC1_PSI base address */
#define ENETC1_PSI_BASE                          (0x4CCC0000u)
/** Peripheral ENETC1_PSI base pointer */
#define ENETC1_PSI                               ((ENETC_SI_Type *)ENETC1_PSI_BASE)
/** Peripheral ENETC2_PSI base address */
#define ENETC2_PSI_BASE                          (0x4CD00000u)
/** Peripheral ENETC2_PSI base pointer */
#define ENETC2_PSI                               ((ENETC_SI_Type *)ENETC2_PSI_BASE)
/** Peripheral ENETC3_PSI base address */
#define ENETC3_PSI_BASE                          (0x4CD40000u)
/** Peripheral ENETC3_PSI base pointer */
#define ENETC3_PSI                               ((ENETC_SI_Type *)ENETC3_PSI_BASE)
/** Peripheral ENETC_VSI0 base address */
#define ENETC_VSI0_BASE                          (0x4CE50000u)
/** Peripheral ENETC_VSI0 base pointer */
#define ENETC_VSI0                               ((ENETC_SI_Type *)ENETC_VSI0_BASE)
/** Peripheral ENETC_VSI1 base address */
#define ENETC_VSI1_BASE                          (0x4CE60000u)
/** Peripheral ENETC_VSI1 base pointer */
#define ENETC_VSI1                               ((ENETC_SI_Type *)ENETC_VSI1_BASE)
/** Peripheral ENETC_VSI2 base address */
#define ENETC_VSI2_BASE                          (0x4CE70000u)
/** Peripheral ENETC_VSI2 base pointer */
#define ENETC_VSI2                               ((ENETC_SI_Type *)ENETC_VSI2_BASE)
/** Array initializer of ENETC_SI peripheral base addresses */
#define ENETC_SI_BASE_ADDRS                      { ENETC0_PSI_BASE, ENETC1_PSI_BASE, ENETC2_PSI_BASE, ENETC3_PSI_BASE, ENETC_VSI0_BASE, ENETC_VSI1_BASE, ENETC_VSI2_BASE }
/** Array initializer of ENETC_SI peripheral base pointers */
#define ENETC_SI_BASE_PTRS                       { ENETC0_PSI, ENETC1_PSI, ENETC2_PSI, ENETC3_PSI, ENETC_VSI0, ENETC_VSI1, ENETC_VSI2 }

/* ENETC_VF_PCI_TYPE0 - Peripheral instance base addresses */
/** Peripheral NETC_VF1_PCI_HDR_TYPE0 base address */
#define NETC_VF1_PCI_HDR_TYPE0_BASE              (0x4CA40000u)
/** Peripheral NETC_VF1_PCI_HDR_TYPE0 base pointer */
#define NETC_VF1_PCI_HDR_TYPE0                   ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF1_PCI_HDR_TYPE0_BASE)
/** Peripheral NETC_VF2_PCI_HDR_TYPE0 base address */
#define NETC_VF2_PCI_HDR_TYPE0_BASE              (0x4CA80000u)
/** Peripheral NETC_VF2_PCI_HDR_TYPE0 base pointer */
#define NETC_VF2_PCI_HDR_TYPE0                   ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF2_PCI_HDR_TYPE0_BASE)
/** Peripheral NETC_VF3_PCI_HDR_TYPE0 base address */
#define NETC_VF3_PCI_HDR_TYPE0_BASE              (0x4CAC0000u)
/** Peripheral NETC_VF3_PCI_HDR_TYPE0 base pointer */
#define NETC_VF3_PCI_HDR_TYPE0                   ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF3_PCI_HDR_TYPE0_BASE)
/** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base addresses */
#define ENETC_VF_PCI_TYPE0_BASE_ADDRS            { NETC_VF1_PCI_HDR_TYPE0_BASE, NETC_VF2_PCI_HDR_TYPE0_BASE, NETC_VF3_PCI_HDR_TYPE0_BASE }
/** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base pointers */
#define ENETC_VF_PCI_TYPE0_BASE_PTRS             { NETC_VF1_PCI_HDR_TYPE0, NETC_VF2_PCI_HDR_TYPE0, NETC_VF3_PCI_HDR_TYPE0 }

/* ENET_PHY_CTRL_EX - Peripheral instance base addresses */
/** Peripheral ENET_PHY_CTRL_EX base address */
#define ENET_PHY_CTRL_EX_BASE                    (0xC00000u)
/** Peripheral ENET_PHY_CTRL_EX base pointer */
#define ENET_PHY_CTRL_EX                         ((ENET_PHY_CTRL_EX_Type *)ENET_PHY_CTRL_EX_BASE)
/** Array initializer of ENET_PHY_CTRL_EX peripheral base addresses */
#define ENET_PHY_CTRL_EX_BASE_ADDRS              { ENET_PHY_CTRL_EX_BASE }
/** Array initializer of ENET_PHY_CTRL_EX peripheral base pointers */
#define ENET_PHY_CTRL_EX_BASE_PTRS               { ENET_PHY_CTRL_EX }

/* ENET_PHY_MAC_ADAPTER - Peripheral instance base addresses */
/** Peripheral ENET_PHY_MAC_ADAPTER base address */
#define ENET_PHY_MAC_ADAPTER_BASE                (0x3E0000u)
/** Peripheral ENET_PHY_MAC_ADAPTER base pointer */
#define ENET_PHY_MAC_ADAPTER                     ((ENET_PHY_MAC_ADAPTER_Type *)ENET_PHY_MAC_ADAPTER_BASE)
/** Array initializer of ENET_PHY_MAC_ADAPTER peripheral base addresses */
#define ENET_PHY_MAC_ADAPTER_BASE_ADDRS          { ENET_PHY_MAC_ADAPTER_BASE }
/** Array initializer of ENET_PHY_MAC_ADAPTER peripheral base pointers */
#define ENET_PHY_MAC_ADAPTER_BASE_PTRS           { ENET_PHY_MAC_ADAPTER }

/* EQDC - Peripheral instance base addresses */
/** Peripheral EQDC1 base address */
#define EQDC1_BASE                               (0x429E0000u)
/** Peripheral EQDC1 base pointer */
#define EQDC1                                    ((EQDC_Type *)EQDC1_BASE)
/** Peripheral EQDC2 base address */
#define EQDC2_BASE                               (0x429F0000u)
/** Peripheral EQDC2 base pointer */
#define EQDC2                                    ((EQDC_Type *)EQDC2_BASE)
/** Peripheral EQDC3 base address */
#define EQDC3_BASE                               (0x42A00000u)
/** Peripheral EQDC3 base pointer */
#define EQDC3                                    ((EQDC_Type *)EQDC3_BASE)
/** Peripheral EQDC4 base address */
#define EQDC4_BASE                               (0x42A10000u)
/** Peripheral EQDC4 base pointer */
#define EQDC4                                    ((EQDC_Type *)EQDC4_BASE)
/** Array initializer of EQDC peripheral base addresses */
#define EQDC_BASE_ADDRS                          { EQDC1_BASE, EQDC2_BASE, EQDC3_BASE, EQDC4_BASE }
/** Array initializer of EQDC peripheral base pointers */
#define EQDC_BASE_PTRS                           { EQDC1, EQDC2, EQDC3, EQDC4 }

/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base address */
#define EWM_BASE                                 (0x42950000u)
/** Peripheral EWM base pointer */
#define EWM                                      ((EWM_Type *)EWM_BASE)
/** Array initializer of EWM peripheral base addresses */
#define EWM_BASE_ADDRS                           { EWM_BASE }
/** Array initializer of EWM peripheral base pointers */
#define EWM_BASE_PTRS                            { EWM }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO1 base address */
#define FLEXIO1_BASE                             (0x425C0000u)
/** Peripheral FLEXIO1 base pointer */
#define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
/** Peripheral FLEXIO2 base address */
#define FLEXIO2_BASE                             (0x425D0000u)
/** Peripheral FLEXIO2 base pointer */
#define FLEXIO2                                  ((FLEXIO_Type *)FLEXIO2_BASE)
/** Peripheral FLEXIO3 base address */
#define FLEXIO3_BASE                             (0x4D100000u)
/** Peripheral FLEXIO3 base pointer */
#define FLEXIO3                                  ((FLEXIO_Type *)FLEXIO3_BASE)
/** Peripheral FLEXIO4 base address */
#define FLEXIO4_BASE                             (0x4D110000u)
/** Peripheral FLEXIO4 base pointer */
#define FLEXIO4                                  ((FLEXIO_Type *)FLEXIO4_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE, FLEXIO2_BASE, FLEXIO3_BASE, FLEXIO4_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1, FLEXIO2, FLEXIO3, FLEXIO4 }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { NotAvail_IRQn, FLEXIO1_IRQn, FLEXIO2_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* FRO - Peripheral instance base addresses */
/** Peripheral FRO base address */
#define FRO_BASE                                 (0x44485000u)
/** Peripheral FRO base pointer */
#define FRO                                      ((FRO_Type *)FRO_BASE)
/** Array initializer of FRO peripheral base addresses */
#define FRO_BASE_ADDRS                           { FRO_BASE }
/** Array initializer of FRO peripheral base pointers */
#define FRO_BASE_PTRS                            { FRO }

/* FSB - Peripheral instance base addresses */
/** Peripheral AON__ELE__FSB base address */
#define AON__ELE__FSB_BASE                       (0x8E510000u)
/** Peripheral AON__ELE__FSB base pointer */
#define AON__ELE__FSB                            ((FSB_Type *)AON__ELE__FSB_BASE)
/** Array initializer of FSB peripheral base addresses */
#define FSB_BASE_ADDRS                           { AON__ELE__FSB_BASE }
/** Array initializer of FSB peripheral base pointers */
#define FSB_BASE_PTRS                            { AON__ELE__FSB }

/* GLITCHFILTER - Peripheral instance base addresses */
/** Peripheral AON__GLITCHFILTER__IGF base address */
#define AON__GLITCHFILTER__IGF_BASE              (0x446E0000u)
/** Peripheral AON__GLITCHFILTER__IGF base pointer */
#define AON__GLITCHFILTER__IGF                   ((GLITCHFILTER_Type *)AON__GLITCHFILTER__IGF_BASE)
/** Array initializer of GLITCHFILTER peripheral base addresses */
#define GLITCHFILTER_BASE_ADDRS                  { AON__GLITCHFILTER__IGF_BASE }
/** Array initializer of GLITCHFILTER peripheral base pointers */
#define GLITCHFILTER_BASE_PTRS                   { AON__GLITCHFILTER__IGF }

/* GPC_CPU_CTRL - Peripheral instance base addresses */
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_0 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE     (0x44471000u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_0 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_0          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_1 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE     (0x44471800u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_1 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_1          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_2 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE     (0x44472000u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_2 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_2          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_3 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE     (0x44472800u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_3 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_3          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE (0x44473000u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER    ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE        (0x44470800u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CM7             ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7_2 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CM7_2_BASE      (0x44473800u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7_2 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CM7_2           ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CM7_2_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM33 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE       (0x44470000u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM33 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CM33            ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33_BASE  (0x44474000u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33       ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33_BASE)
/** Array initializer of GPC_CPU_CTRL peripheral base addresses */
#define GPC_CPU_CTRL_BASE_ADDRS                  { CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE, CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE, CCMSRCGPC__GPC__GPC_CTRL_CM7_2_BASE, CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE, CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33_BASE }
/** Array initializer of GPC_CPU_CTRL peripheral base pointers */
#define GPC_CPU_CTRL_BASE_PTRS                   { CCMSRCGPC__GPC__GPC_CTRL_CA55_0, CCMSRCGPC__GPC__GPC_CTRL_CA55_1, CCMSRCGPC__GPC__GPC_CTRL_CA55_2, CCMSRCGPC__GPC__GPC_CTRL_CA55_3, CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER, CCMSRCGPC__GPC__GPC_CTRL_CM7, CCMSRCGPC__GPC__GPC_CTRL_CM7_2, CCMSRCGPC__GPC__GPC_CTRL_CM33, CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33 }

/* GPC_GLOBAL - Peripheral instance base addresses */
/** Peripheral GPC_GLOBAL base address */
#define GPC_GLOBAL_BASE                          (0x44474800u)
/** Peripheral GPC_GLOBAL base pointer */
#define GPC_GLOBAL                               ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE)
/** Array initializer of GPC_GLOBAL peripheral base addresses */
#define GPC_GLOBAL_BASE_ADDRS                    { GPC_GLOBAL_BASE }
/** Array initializer of GPC_GLOBAL peripheral base pointers */
#define GPC_GLOBAL_BASE_PTRS                     { GPC_GLOBAL }

/* GPT - Peripheral instance base addresses */
/** Peripheral GPT1 base address */
#define GPT1_BASE                                (0x446F0000u)
/** Peripheral GPT1 base pointer */
#define GPT1                                     ((GPT_Type *)GPT1_BASE)
/** Array initializer of GPT peripheral base addresses */
#define GPT_BASE_ADDRS                           { GPT1_BASE }
/** Array initializer of GPT peripheral base pointers */
#define GPT_BASE_PTRS                            { GPT1 }

/* HIPERFACE - Peripheral instance base addresses */
/** Peripheral HIPERFACE1 base address */
#define HIPERFACE1_BASE                          (0x42CF0000u)
/** Peripheral HIPERFACE1 base pointer */
#define HIPERFACE1                               ((HIPERFACE_Type *)HIPERFACE1_BASE)
/** Peripheral HIPERFACE2 base address */
#define HIPERFACE2_BASE                          (0x42D20000u)
/** Peripheral HIPERFACE2 base pointer */
#define HIPERFACE2                               ((HIPERFACE_Type *)HIPERFACE2_BASE)
/** Array initializer of HIPERFACE peripheral base addresses */
#define HIPERFACE_BASE_ADDRS                     { HIPERFACE1_BASE, HIPERFACE2_BASE }
/** Array initializer of HIPERFACE peripheral base pointers */
#define HIPERFACE_BASE_PTRS                      { HIPERFACE1, HIPERFACE2 }

/* HSIO_BLK_CTRL_HSIOMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_HSIOMIX base address */
#define BLK_CTRL_HSIOMIX_BASE                    (0x4C010000u)
/** Peripheral BLK_CTRL_HSIOMIX base pointer */
#define BLK_CTRL_HSIOMIX                         ((HSIO_BLK_CTRL_HSIOMIX_Type *)BLK_CTRL_HSIOMIX_BASE)
/** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base addresses */
#define HSIO_BLK_CTRL_HSIOMIX_BASE_ADDRS         { BLK_CTRL_HSIOMIX_BASE }
/** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base pointers */
#define HSIO_BLK_CTRL_HSIOMIX_BASE_PTRS          { BLK_CTRL_HSIOMIX }

/* HSIO_TCU - Peripheral instance base addresses */
/** Peripheral HSIO__TCU base address */
#define HSIO__TCU_BASE                           (0x4C000000u)
/** Peripheral HSIO__TCU base pointer */
#define HSIO__TCU                                ((HSIO_TCU_Type *)HSIO__TCU_BASE)
/** Array initializer of HSIO_TCU peripheral base addresses */
#define HSIO_TCU_BASE_ADDRS                      { HSIO__TCU_BASE }
/** Array initializer of HSIO_TCU peripheral base pointers */
#define HSIO_TCU_BASE_PTRS                       { HSIO__TCU }

/* HSIO_TRDC_MGR - Peripheral instance base addresses */
/** Peripheral HSIO__TRDC_MGR_HSIOMIX base address */
#define HSIO__TRDC_MGR_HSIOMIX_BASE              (0x4C040000u)
/** Peripheral HSIO__TRDC_MGR_HSIOMIX base pointer */
#define HSIO__TRDC_MGR_HSIOMIX                   ((HSIO_TRDC_MGR_Type *)HSIO__TRDC_MGR_HSIOMIX_BASE)
/** Array initializer of HSIO_TRDC_MGR peripheral base addresses */
#define HSIO_TRDC_MGR_BASE_ADDRS                 { HSIO__TRDC_MGR_HSIOMIX_BASE }
/** Array initializer of HSIO_TRDC_MGR peripheral base pointers */
#define HSIO_TRDC_MGR_BASE_PTRS                  { HSIO__TRDC_MGR_HSIOMIX }

/* I2S - Peripheral instance base addresses */
/** Peripheral SAI1 base address */
#define SAI1_BASE                                (0x443B0000u)
/** Peripheral SAI1 base pointer */
#define SAI1                                     ((I2S_Type *)SAI1_BASE)
/** Peripheral SAI3 base address */
#define SAI3_BASE                                (0x42660000u)
/** Peripheral SAI3 base pointer */
#define SAI3                                     ((I2S_Type *)SAI3_BASE)
/** Peripheral SAI4 base address */
#define SAI4_BASE                                (0x42670000u)
/** Peripheral SAI4 base pointer */
#define SAI4                                     ((I2S_Type *)SAI4_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, 0u, SAI3_BASE, SAI4_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, (I2S_Type *)0u, SAI3, SAI4 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, NotAvail_IRQn, SAI3_IRQn, SAI4_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, NotAvail_IRQn, SAI3_IRQn, SAI4_IRQn }

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

/* IOMUXC - Peripheral instance base addresses */
/** Peripheral IOMUXC base address */
#define IOMUXC_BASE                              (0x443C0000u)
/** Peripheral IOMUXC base pointer */
#define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
/** Array initializer of IOMUXC peripheral base addresses */
#define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
/** Array initializer of IOMUXC peripheral base pointers */
#define IOMUXC_BASE_PTRS                         { IOMUXC }

/* IOMUXC_GPR - Peripheral instance base addresses */
/** Peripheral IOMUXC_GPR base address */
#define IOMUXC_GPR_BASE                          (0x443D0000u)
/** Peripheral IOMUXC_GPR base pointer */
#define IOMUXC_GPR                               ((IOMUXC_GPR_Type *)IOMUXC_GPR_BASE)
/** Array initializer of IOMUXC_GPR peripheral base addresses */
#define IOMUXC_GPR_BASE_ADDRS                    { IOMUXC_GPR_BASE }
/** Array initializer of IOMUXC_GPR peripheral base pointers */
#define IOMUXC_GPR_BASE_PTRS                     { IOMUXC_GPR }

/* IRQSTEER - Peripheral instance base addresses */
/** Peripheral IRQSTEERM7 base address */
#define IRQSTEERM7_BASE                          (0x44680000u)
/** Peripheral IRQSTEERM7 base pointer */
#define IRQSTEERM7                               ((IRQSTEER_Type *)IRQSTEERM7_BASE)
/** Peripheral IRQSTEERM33 base address */
#define IRQSTEERM33_BASE                         (0x44760000u)
/** Peripheral IRQSTEERM33 base pointer */
#define IRQSTEERM33                              ((IRQSTEER_Type *)IRQSTEERM33_BASE)
/** Array initializer of IRQSTEER peripheral base addresses */
#define IRQSTEER_BASE_ADDRS                      { IRQSTEERM7_BASE, IRQSTEERM33_BASE }
/** Array initializer of IRQSTEER peripheral base pointers */
#define IRQSTEER_BASE_PTRS                       { IRQSTEERM7, IRQSTEERM33 }

/* IRQSTEERA55 - Peripheral instance base addresses */
/** Peripheral AON__IRQSTEERA55 base address */
#define AON__IRQSTEERA55_BASE                    (0x446A0000u)
/** Peripheral AON__IRQSTEERA55 base pointer */
#define AON__IRQSTEERA55                         ((IRQSTEERA55_Type *)AON__IRQSTEERA55_BASE)
/** Array initializer of IRQSTEERA55 peripheral base addresses */
#define IRQSTEERA55_BASE_ADDRS                   { AON__IRQSTEERA55_BASE }
/** Array initializer of IRQSTEERA55 peripheral base pointers */
#define IRQSTEERA55_BASE_PTRS                    { AON__IRQSTEERA55 }

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
#define LPI2C_IRQS                               { NotAvail_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn, LPI2C4_IRQn, LPI2C5_IRQn, LPI2C6_IRQn, NotAvail_IRQn, LPI2C8_IRQn }

/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT1 base address */
#define LPIT1_BASE                               (0x442F0000u)
/** Peripheral LPIT1 base pointer */
#define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
/** Peripheral LPIT2 base address */
#define LPIT2_BASE                               (0x424C0000u)
/** Peripheral LPIT2 base pointer */
#define LPIT2                                    ((LPIT_Type *)LPIT2_BASE)
/** Peripheral LPIT3 base address */
#define LPIT3_BASE                               (0x427F0000u)
/** Peripheral LPIT3 base pointer */
#define LPIT3                                    ((LPIT_Type *)LPIT3_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { 0u, LPIT1_BASE, LPIT2_BASE, LPIT3_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { (LPIT_Type *)0u, LPIT1, LPIT2, LPIT3 }
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { LPIT1_IRQn, LPIT1_IRQn, LPIT1_IRQn, LPIT1_IRQn }, { LPIT2_IRQn, LPIT2_IRQn, LPIT2_IRQn, LPIT2_IRQn }, { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn } }

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
/** Peripheral LPUART9 base address */
#define LPUART9_BASE                             (0x42A50000u)
/** Peripheral LPUART9 base pointer */
#define LPUART9                                  ((LPUART_Type *)LPUART9_BASE)
/** Peripheral LPUART10 base address */
#define LPUART10_BASE                            (0x42A60000u)
/** Peripheral LPUART10 base pointer */
#define LPUART10                                 ((LPUART_Type *)LPUART10_BASE)
/** Peripheral LPUART11 base address */
#define LPUART11_BASE                            (0x42A70000u)
/** Peripheral LPUART11 base pointer */
#define LPUART11                                 ((LPUART_Type *)LPUART11_BASE)
/** Peripheral LPUART12 base address */
#define LPUART12_BASE                            (0x42A80000u)
/** Peripheral LPUART12 base pointer */
#define LPUART12                                 ((LPUART_Type *)LPUART12_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE, LPUART9_BASE, LPUART10_BASE, LPUART11_BASE, LPUART12_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8, LPUART9, LPUART10, LPUART11, LPUART12 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* M7_A7_APB_MCM - Peripheral instance base addresses */
/** Peripheral M7_1__A7_APB_MCM1 base address */
#define M7_1__A7_APB_MCM1_BASE                   (0x49CA0000u)
/** Peripheral M7_1__A7_APB_MCM1 base pointer */
#define M7_1__A7_APB_MCM1                        ((M7_A7_APB_MCM_Type *)M7_1__A7_APB_MCM1_BASE)
/** Peripheral M7__A7_APB_MCM1 base address */
#define M7__A7_APB_MCM1_BASE                     (0x4A0A0000u)
/** Peripheral M7__A7_APB_MCM1 base pointer */
#define M7__A7_APB_MCM1                          ((M7_A7_APB_MCM_Type *)M7__A7_APB_MCM1_BASE)
/** Array initializer of M7_A7_APB_MCM peripheral base addresses */
#define M7_A7_APB_MCM_BASE_ADDRS                 { M7_1__A7_APB_MCM1_BASE, M7__A7_APB_MCM1_BASE }
/** Array initializer of M7_A7_APB_MCM peripheral base pointers */
#define M7_A7_APB_MCM_BASE_PTRS                  { M7_1__A7_APB_MCM1, M7__A7_APB_MCM1 }

/* M7_CMU - Peripheral instance base addresses */
/** Peripheral M7_1__CMU_M0 base address */
#define M7_1__CMU_M0_BASE                        (0x49C80000u)
/** Peripheral M7_1__CMU_M0 base pointer */
#define M7_1__CMU_M0                             ((M7_CMU_Type *)M7_1__CMU_M0_BASE)
/** Peripheral M7_1__CMU_M1 base address */
#define M7_1__CMU_M1_BASE                        (0x49C90000u)
/** Peripheral M7_1__CMU_M1 base pointer */
#define M7_1__CMU_M1                             ((M7_CMU_Type *)M7_1__CMU_M1_BASE)
/** Peripheral M7__CMU_M0 base address */
#define M7__CMU_M0_BASE                          (0x4A080000u)
/** Peripheral M7__CMU_M0 base pointer */
#define M7__CMU_M0                               ((M7_CMU_Type *)M7__CMU_M0_BASE)
/** Peripheral M7__CMU_M1 base address */
#define M7__CMU_M1_BASE                          (0x4A090000u)
/** Peripheral M7__CMU_M1 base pointer */
#define M7__CMU_M1                               ((M7_CMU_Type *)M7__CMU_M1_BASE)
/** Array initializer of M7_CMU peripheral base addresses */
#define M7_CMU_BASE_ADDRS                        { M7_1__CMU_M0_BASE, M7_1__CMU_M1_BASE, M7__CMU_M0_BASE, M7__CMU_M1_BASE }
/** Array initializer of M7_CMU peripheral base pointers */
#define M7_CMU_BASE_PTRS                         { M7_1__CMU_M0, M7_1__CMU_M1, M7__CMU_M0, M7__CMU_M1 }

/* M7_EIM - Peripheral instance base addresses */
/** Peripheral M7_1__EIM base address */
#define M7_1__EIM_BASE                           (0x49C60000u)
/** Peripheral M7_1__EIM base pointer */
#define M7_1__EIM                                ((M7_EIM_Type *)M7_1__EIM_BASE)
/** Peripheral M7__EIM base address */
#define M7__EIM_BASE                             (0x4A060000u)
/** Peripheral M7__EIM base pointer */
#define M7__EIM                                  ((M7_EIM_Type *)M7__EIM_BASE)
/** Array initializer of M7_EIM peripheral base addresses */
#define M7_EIM_BASE_ADDRS                        { M7_1__EIM_BASE, M7__EIM_BASE }
/** Array initializer of M7_EIM peripheral base pointers */
#define M7_EIM_BASE_PTRS                         { M7_1__EIM, M7__EIM }

/* M7_ERM - Peripheral instance base addresses */
/** Peripheral M7_1__ERM base address */
#define M7_1__ERM_BASE                           (0x49C70000u)
/** Peripheral M7_1__ERM base pointer */
#define M7_1__ERM                                ((M7_ERM_Type *)M7_1__ERM_BASE)
/** Peripheral M7__ERM base address */
#define M7__ERM_BASE                             (0x4A070000u)
/** Peripheral M7__ERM base pointer */
#define M7__ERM                                  ((M7_ERM_Type *)M7__ERM_BASE)
/** Array initializer of M7_ERM peripheral base addresses */
#define M7_ERM_BASE_ADDRS                        { M7_1__ERM_BASE, M7__ERM_BASE }
/** Array initializer of M7_ERM peripheral base pointers */
#define M7_ERM_BASE_PTRS                         { M7_1__ERM, M7__ERM }

/* M7_LSTCU - Peripheral instance base addresses */
/** Peripheral M7_1__LSTCU_M7MIX base address */
#define M7_1__LSTCU_M7MIX_BASE                   (0x49C50000u)
/** Peripheral M7_1__LSTCU_M7MIX base pointer */
#define M7_1__LSTCU_M7MIX                        ((M7_LSTCU_Type *)M7_1__LSTCU_M7MIX_BASE)
/** Peripheral M7__LSTCU_M7MIX base address */
#define M7__LSTCU_M7MIX_BASE                     (0x4A050000u)
/** Peripheral M7__LSTCU_M7MIX base pointer */
#define M7__LSTCU_M7MIX                          ((M7_LSTCU_Type *)M7__LSTCU_M7MIX_BASE)
/** Array initializer of M7_LSTCU peripheral base addresses */
#define M7_LSTCU_BASE_ADDRS                      { M7_1__LSTCU_M7MIX_BASE, M7__LSTCU_M7MIX_BASE }
/** Array initializer of M7_LSTCU peripheral base pointers */
#define M7_LSTCU_BASE_PTRS                       { M7_1__LSTCU_M7MIX, M7__LSTCU_M7MIX }

/* M7_TCU - Peripheral instance base addresses */
/** Peripheral M7_1__TCU base address */
#define M7_1__TCU_BASE                           (0x49C00000u)
/** Peripheral M7_1__TCU base pointer */
#define M7_1__TCU                                ((M7_TCU_Type *)M7_1__TCU_BASE)
/** Peripheral M7__TCU base address */
#define M7__TCU_BASE                             (0x4A000000u)
/** Peripheral M7__TCU base pointer */
#define M7__TCU                                  ((M7_TCU_Type *)M7__TCU_BASE)
/** Array initializer of M7_TCU peripheral base addresses */
#define M7_TCU_BASE_ADDRS                        { M7_1__TCU_BASE, M7__TCU_BASE }
/** Array initializer of M7_TCU peripheral base pointers */
#define M7_TCU_BASE_PTRS                         { M7_1__TCU, M7__TCU }

/* MSGINTR - Peripheral instance base addresses */
/** Peripheral MSGINTR1 base address */
#define MSGINTR1_BASE                            (0x42C30000u)
/** Peripheral MSGINTR1 base pointer */
#define MSGINTR1                                 ((MSGINTR_Type *)MSGINTR1_BASE)
/** Peripheral MSGINTR2 base address */
#define MSGINTR2_BASE                            (0x42C40000u)
/** Peripheral MSGINTR2 base pointer */
#define MSGINTR2                                 ((MSGINTR_Type *)MSGINTR2_BASE)
/** Peripheral MSGINTR3 base address */
#define MSGINTR3_BASE                            (0x42C50000u)
/** Peripheral MSGINTR3 base pointer */
#define MSGINTR3                                 ((MSGINTR_Type *)MSGINTR3_BASE)
/** Peripheral MSGINTR4 base address */
#define MSGINTR4_BASE                            (0x42C60000u)
/** Peripheral MSGINTR4 base pointer */
#define MSGINTR4                                 ((MSGINTR_Type *)MSGINTR4_BASE)
/** Peripheral MSGINTR5 base address */
#define MSGINTR5_BASE                            (0x42C70000u)
/** Peripheral MSGINTR5 base pointer */
#define MSGINTR5                                 ((MSGINTR_Type *)MSGINTR5_BASE)
/** Peripheral MSGINTR6 base address */
#define MSGINTR6_BASE                            (0x42C80000u)
/** Peripheral MSGINTR6 base pointer */
#define MSGINTR6                                 ((MSGINTR_Type *)MSGINTR6_BASE)
/** Peripheral MSGINTR7 base address */
#define MSGINTR7_BASE                            (0x42C90000u)
/** Peripheral MSGINTR7 base pointer */
#define MSGINTR7                                 ((MSGINTR_Type *)MSGINTR7_BASE)
/** Peripheral MSGINTR8 base address */
#define MSGINTR8_BASE                            (0x42CA0000u)
/** Peripheral MSGINTR8 base pointer */
#define MSGINTR8                                 ((MSGINTR_Type *)MSGINTR8_BASE)
/** Array initializer of MSGINTR peripheral base addresses */
#define MSGINTR_BASE_ADDRS                       { 0u, MSGINTR1_BASE, MSGINTR2_BASE, MSGINTR3_BASE, MSGINTR4_BASE, MSGINTR5_BASE, MSGINTR6_BASE, MSGINTR7_BASE, MSGINTR8_BASE }
/** Array initializer of MSGINTR peripheral base pointers */
#define MSGINTR_BASE_PTRS                        { (MSGINTR_Type *)0u, MSGINTR1, MSGINTR2, MSGINTR3, MSGINTR4, MSGINTR5, MSGINTR6, MSGINTR7, MSGINTR8 }

/* MU - Peripheral instance base addresses */
/** Peripheral MU1_MUA base address */
#define MU1_MUA_BASE                             (0x44220000u)
/** Peripheral MU1_MUA base pointer */
#define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
/** Peripheral MU1_MUB base address */
#define MU1_MUB_BASE                             (0x44230000u)
/** Peripheral MU1_MUB base pointer */
#define MU1_MUB                                  ((MU_Type *)MU1_MUB_BASE)
/** Peripheral MU2_MUA base address */
#define MU2_MUA_BASE                             (0x445B0000u)
/** Peripheral MU2_MUA base pointer */
#define MU2_MUA                                  ((MU_Type *)MU2_MUA_BASE)
/** Peripheral MU2_MUB base address */
#define MU2_MUB_BASE                             (0x445C0000u)
/** Peripheral MU2_MUB base pointer */
#define MU2_MUB                                  ((MU_Type *)MU2_MUB_BASE)
/** Peripheral MU3_MUA base address */
#define MU3_MUA_BASE                             (0x445D0000u)
/** Peripheral MU3_MUA base pointer */
#define MU3_MUA                                  ((MU_Type *)MU3_MUA_BASE)
/** Peripheral MU3_MUB base address */
#define MU3_MUB_BASE                             (0x445E0000u)
/** Peripheral MU3_MUB base pointer */
#define MU3_MUB                                  ((MU_Type *)MU3_MUB_BASE)
/** Peripheral MU4_MUA base address */
#define MU4_MUA_BASE                             (0x445F0000u)
/** Peripheral MU4_MUA base pointer */
#define MU4_MUA                                  ((MU_Type *)MU4_MUA_BASE)
/** Peripheral MU4_MUB base address */
#define MU4_MUB_BASE                             (0x44600000u)
/** Peripheral MU4_MUB base pointer */
#define MU4_MUB                                  ((MU_Type *)MU4_MUB_BASE)
/** Peripheral MU5_MUA base address */
#define MU5_MUA_BASE                             (0x44610000u)
/** Peripheral MU5_MUA base pointer */
#define MU5_MUA                                  ((MU_Type *)MU5_MUA_BASE)
/** Peripheral MU5_MUB base address */
#define MU5_MUB_BASE                             (0x44620000u)
/** Peripheral MU5_MUB base pointer */
#define MU5_MUB                                  ((MU_Type *)MU5_MUB_BASE)
/** Peripheral MU6_MUA base address */
#define MU6_MUA_BASE                             (0x44630000u)
/** Peripheral MU6_MUA base pointer */
#define MU6_MUA                                  ((MU_Type *)MU6_MUA_BASE)
/** Peripheral MU6_MUB base address */
#define MU6_MUB_BASE                             (0x44640000u)
/** Peripheral MU6_MUB base pointer */
#define MU6_MUB                                  ((MU_Type *)MU6_MUB_BASE)
/** Peripheral MU7_MUA base address */
#define MU7_MUA_BASE                             (0x44700000u)
/** Peripheral MU7_MUA base pointer */
#define MU7_MUA                                  ((MU_Type *)MU7_MUA_BASE)
/** Peripheral MU7_MUB base address */
#define MU7_MUB_BASE                             (0x44710000u)
/** Peripheral MU7_MUB base pointer */
#define MU7_MUB                                  ((MU_Type *)MU7_MUB_BASE)
/** Peripheral MU8_MUA base address */
#define MU8_MUA_BASE                             (0x44720000u)
/** Peripheral MU8_MUA base pointer */
#define MU8_MUA                                  ((MU_Type *)MU8_MUA_BASE)
/** Peripheral MU8_MUB base address */
#define MU8_MUB_BASE                             (0x44730000u)
/** Peripheral MU8_MUB base pointer */
#define MU8_MUB                                  ((MU_Type *)MU8_MUB_BASE)
/** Peripheral MU9_MUA base address */
#define MU9_MUA_BASE                             (0x44740000u)
/** Peripheral MU9_MUA base pointer */
#define MU9_MUA                                  ((MU_Type *)MU9_MUA_BASE)
/** Peripheral MU9_MUB base address */
#define MU9_MUB_BASE                             (0x44750000u)
/** Peripheral MU9_MUB base pointer */
#define MU9_MUB                                  ((MU_Type *)MU9_MUB_BASE)
/** Peripheral NETC__MUA1__MUA base address */
#define NETC__MUA1__MUA_BASE                     (0x4D120000u)
/** Peripheral NETC__MUA1__MUA base pointer */
#define NETC__MUA1__MUA                          ((MU_Type *)NETC__MUA1__MUA_BASE)
/** Peripheral NETC__MUA1__MUB base address */
#define NETC__MUA1__MUB_BASE                     (0x4D130000u)
/** Peripheral NETC__MUA1__MUB base pointer */
#define NETC__MUA1__MUB                          ((MU_Type *)NETC__MUA1__MUB_BASE)
/** Peripheral NETC__MUA2__MUA base address */
#define NETC__MUA2__MUA_BASE                     (0x4D140000u)
/** Peripheral NETC__MUA2__MUA base pointer */
#define NETC__MUA2__MUA                          ((MU_Type *)NETC__MUA2__MUA_BASE)
/** Peripheral NETC__MUA2__MUB base address */
#define NETC__MUA2__MUB_BASE                     (0x4D150000u)
/** Peripheral NETC__MUA2__MUB base pointer */
#define NETC__MUA2__MUB                          ((MU_Type *)NETC__MUA2__MUB_BASE)
/** Peripheral NETC__MUA3__MUA base address */
#define NETC__MUA3__MUA_BASE                     (0x4D160000u)
/** Peripheral NETC__MUA3__MUA base pointer */
#define NETC__MUA3__MUA                          ((MU_Type *)NETC__MUA3__MUA_BASE)
/** Peripheral NETC__MUA3__MUB base address */
#define NETC__MUA3__MUB_BASE                     (0x4D170000u)
/** Peripheral NETC__MUA3__MUB base pointer */
#define NETC__MUA3__MUB                          ((MU_Type *)NETC__MUA3__MUB_BASE)
/** Peripheral NETC__MUA4__MUA base address */
#define NETC__MUA4__MUA_BASE                     (0x4D180000u)
/** Peripheral NETC__MUA4__MUA base pointer */
#define NETC__MUA4__MUA                          ((MU_Type *)NETC__MUA4__MUA_BASE)
/** Peripheral NETC__MUA4__MUB base address */
#define NETC__MUA4__MUB_BASE                     (0x4D190000u)
/** Peripheral NETC__MUA4__MUB base pointer */
#define NETC__MUA4__MUB                          ((MU_Type *)NETC__MUA4__MUB_BASE)
/** Peripheral WAKEUP__MUI_A10__MUA base address */
#define WAKEUP__MUI_A10__MUA_BASE                (0x42430000u)
/** Peripheral WAKEUP__MUI_A10__MUA base pointer */
#define WAKEUP__MUI_A10__MUA                     ((MU_Type *)WAKEUP__MUI_A10__MUA_BASE)
/** Peripheral WAKEUP__MUI_A10__MUB base address */
#define WAKEUP__MUI_A10__MUB_BASE                (0x42440000u)
/** Peripheral WAKEUP__MUI_A10__MUB base pointer */
#define WAKEUP__MUI_A10__MUB                     ((MU_Type *)WAKEUP__MUI_A10__MUB_BASE)
/** Peripheral WAKEUP__MUI_A11__MUA base address */
#define WAKEUP__MUI_A11__MUA_BASE                (0x42730000u)
/** Peripheral WAKEUP__MUI_A11__MUA base pointer */
#define WAKEUP__MUI_A11__MUA                     ((MU_Type *)WAKEUP__MUI_A11__MUA_BASE)
/** Peripheral WAKEUP__MUI_A11__MUB base address */
#define WAKEUP__MUI_A11__MUB_BASE                (0x42740000u)
/** Peripheral WAKEUP__MUI_A11__MUB base pointer */
#define WAKEUP__MUI_A11__MUB                     ((MU_Type *)WAKEUP__MUI_A11__MUB_BASE)
/** Peripheral WAKEUP__MUI_A12__MUA base address */
#define WAKEUP__MUI_A12__MUA_BASE                (0x42AB0000u)
/** Peripheral WAKEUP__MUI_A12__MUA base pointer */
#define WAKEUP__MUI_A12__MUA                     ((MU_Type *)WAKEUP__MUI_A12__MUA_BASE)
/** Peripheral WAKEUP__MUI_A12__MUB base address */
#define WAKEUP__MUI_A12__MUB_BASE                (0x42AC0000u)
/** Peripheral WAKEUP__MUI_A12__MUB base pointer */
#define WAKEUP__MUI_A12__MUB                     ((MU_Type *)WAKEUP__MUI_A12__MUB_BASE)
/** Peripheral WAKEUP__MUI_A13__MUA base address */
#define WAKEUP__MUI_A13__MUA_BASE                (0x42AD0000u)
/** Peripheral WAKEUP__MUI_A13__MUA base pointer */
#define WAKEUP__MUI_A13__MUA                     ((MU_Type *)WAKEUP__MUI_A13__MUA_BASE)
/** Peripheral WAKEUP__MUI_A13__MUB base address */
#define WAKEUP__MUI_A13__MUB_BASE                (0x42AE0000u)
/** Peripheral WAKEUP__MUI_A13__MUB base pointer */
#define WAKEUP__MUI_A13__MUB                     ((MU_Type *)WAKEUP__MUI_A13__MUB_BASE)
/** Peripheral WAKEUP__MUI_A14__MUA base address */
#define WAKEUP__MUI_A14__MUA_BASE                (0x42AF0000u)
/** Peripheral WAKEUP__MUI_A14__MUA base pointer */
#define WAKEUP__MUI_A14__MUA                     ((MU_Type *)WAKEUP__MUI_A14__MUA_BASE)
/** Peripheral WAKEUP__MUI_A14__MUB base address */
#define WAKEUP__MUI_A14__MUB_BASE                (0x42B00000u)
/** Peripheral WAKEUP__MUI_A14__MUB base pointer */
#define WAKEUP__MUI_A14__MUB                     ((MU_Type *)WAKEUP__MUI_A14__MUB_BASE)
/** Peripheral WAKEUP__MUI_A15__MUA base address */
#define WAKEUP__MUI_A15__MUA_BASE                (0x42B10000u)
/** Peripheral WAKEUP__MUI_A15__MUA base pointer */
#define WAKEUP__MUI_A15__MUA                     ((MU_Type *)WAKEUP__MUI_A15__MUA_BASE)
/** Peripheral WAKEUP__MUI_A15__MUB base address */
#define WAKEUP__MUI_A15__MUB_BASE                (0x42B20000u)
/** Peripheral WAKEUP__MUI_A15__MUB base pointer */
#define WAKEUP__MUI_A15__MUB                     ((MU_Type *)WAKEUP__MUI_A15__MUB_BASE)
/** Peripheral WAKEUP__MUI_A16__MUA base address */
#define WAKEUP__MUI_A16__MUA_BASE                (0x42B30000u)
/** Peripheral WAKEUP__MUI_A16__MUA base pointer */
#define WAKEUP__MUI_A16__MUA                     ((MU_Type *)WAKEUP__MUI_A16__MUA_BASE)
/** Peripheral WAKEUP__MUI_A16__MUB base address */
#define WAKEUP__MUI_A16__MUB_BASE                (0x42B40000u)
/** Peripheral WAKEUP__MUI_A16__MUB base pointer */
#define WAKEUP__MUI_A16__MUB                     ((MU_Type *)WAKEUP__MUI_A16__MUB_BASE)
/** Peripheral WAKEUP__MUI_A17__MUA base address */
#define WAKEUP__MUI_A17__MUA_BASE                (0x42B50000u)
/** Peripheral WAKEUP__MUI_A17__MUA base pointer */
#define WAKEUP__MUI_A17__MUA                     ((MU_Type *)WAKEUP__MUI_A17__MUA_BASE)
/** Peripheral WAKEUP__MUI_A17__MUB base address */
#define WAKEUP__MUI_A17__MUB_BASE                (0x42B60000u)
/** Peripheral WAKEUP__MUI_A17__MUB base pointer */
#define WAKEUP__MUI_A17__MUB                     ((MU_Type *)WAKEUP__MUI_A17__MUB_BASE)
/** Peripheral WAKEUP__MUI_A18__MUA base address */
#define WAKEUP__MUI_A18__MUA_BASE                (0x42B70000u)
/** Peripheral WAKEUP__MUI_A18__MUA base pointer */
#define WAKEUP__MUI_A18__MUA                     ((MU_Type *)WAKEUP__MUI_A18__MUA_BASE)
/** Peripheral WAKEUP__MUI_A18__MUB base address */
#define WAKEUP__MUI_A18__MUB_BASE                (0x42B80000u)
/** Peripheral WAKEUP__MUI_A18__MUB base pointer */
#define WAKEUP__MUI_A18__MUB                     ((MU_Type *)WAKEUP__MUI_A18__MUB_BASE)
/** Peripheral WAKEUP__V2X__MU0__MUA base address */
#define WAKEUP__V2X__MU0__MUA_BASE               (0x87300000u)
/** Peripheral WAKEUP__V2X__MU0__MUA base pointer */
#define WAKEUP__V2X__MU0__MUA                    ((MU_Type *)WAKEUP__V2X__MU0__MUA_BASE)
/** Peripheral WAKEUP__V2X__MU1__MUA base address */
#define WAKEUP__V2X__MU1__MUA_BASE               (0x87310000u)
/** Peripheral WAKEUP__V2X__MU1__MUA base pointer */
#define WAKEUP__V2X__MU1__MUA                    ((MU_Type *)WAKEUP__V2X__MU1__MUA_BASE)
/** Peripheral WAKEUP__V2X__MU2__MUA base address */
#define WAKEUP__V2X__MU2__MUA_BASE               (0x87320000u)
/** Peripheral WAKEUP__V2X__MU2__MUA base pointer */
#define WAKEUP__V2X__MU2__MUA                    ((MU_Type *)WAKEUP__V2X__MU2__MUA_BASE)
/** Peripheral WAKEUP__V2X__MU3__MUA base address */
#define WAKEUP__V2X__MU3__MUA_BASE               (0x87330000u)
/** Peripheral WAKEUP__V2X__MU3__MUA base pointer */
#define WAKEUP__V2X__MU3__MUA                    ((MU_Type *)WAKEUP__V2X__MU3__MUA_BASE)
/** Peripheral WAKEUP__V2X__MU4__MUA base address */
#define WAKEUP__V2X__MU4__MUA_BASE               (0x87340000u)
/** Peripheral WAKEUP__V2X__MU4__MUA base pointer */
#define WAKEUP__V2X__MU4__MUA                    ((MU_Type *)WAKEUP__V2X__MU4__MUA_BASE)
/** Peripheral WAKEUP__V2X__MU5__MUB base address */
#define WAKEUP__V2X__MU5__MUB_BASE               (0x87358000u)
/** Peripheral WAKEUP__V2X__MU5__MUB base pointer */
#define WAKEUP__V2X__MU5__MUB                    ((MU_Type *)WAKEUP__V2X__MU5__MUB_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MU1_MUA_BASE, MU1_MUB_BASE, MU2_MUA_BASE, MU2_MUB_BASE, MU3_MUA_BASE, MU3_MUB_BASE, MU4_MUA_BASE, MU4_MUB_BASE, MU5_MUA_BASE, MU5_MUB_BASE, MU6_MUA_BASE, MU6_MUB_BASE, MU7_MUA_BASE, MU7_MUB_BASE, MU8_MUA_BASE, MU8_MUB_BASE, MU9_MUA_BASE, MU9_MUB_BASE, NETC__MUA1__MUA_BASE, NETC__MUA1__MUB_BASE, NETC__MUA2__MUA_BASE, NETC__MUA2__MUB_BASE, NETC__MUA3__MUA_BASE, NETC__MUA3__MUB_BASE, NETC__MUA4__MUA_BASE, NETC__MUA4__MUB_BASE, WAKEUP__MUI_A10__MUA_BASE, WAKEUP__MUI_A10__MUB_BASE, WAKEUP__MUI_A11__MUA_BASE, WAKEUP__MUI_A11__MUB_BASE, WAKEUP__MUI_A12__MUA_BASE, WAKEUP__MUI_A12__MUB_BASE, WAKEUP__MUI_A13__MUA_BASE, WAKEUP__MUI_A13__MUB_BASE, WAKEUP__MUI_A14__MUA_BASE, WAKEUP__MUI_A14__MUB_BASE, WAKEUP__MUI_A15__MUA_BASE, WAKEUP__MUI_A15__MUB_BASE, WAKEUP__MUI_A16__MUA_BASE, WAKEUP__MUI_A16__MUB_BASE, WAKEUP__MUI_A17__MUA_BASE, WAKEUP__MUI_A17__MUB_BASE, WAKEUP__MUI_A18__MUA_BASE, WAKEUP__MUI_A18__MUB_BASE, WAKEUP__V2X__MU0__MUA_BASE, WAKEUP__V2X__MU1__MUA_BASE, WAKEUP__V2X__MU2__MUA_BASE, WAKEUP__V2X__MU3__MUA_BASE, WAKEUP__V2X__MU4__MUA_BASE, WAKEUP__V2X__MU5__MUB_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MU1_MUA, MU1_MUB, MU2_MUA, MU2_MUB, MU3_MUA, MU3_MUB, MU4_MUA, MU4_MUB, MU5_MUA, MU5_MUB, MU6_MUA, MU6_MUB, MU7_MUA, MU7_MUB, MU8_MUA, MU8_MUB, MU9_MUA, MU9_MUB, NETC__MUA1__MUA, NETC__MUA1__MUB, NETC__MUA2__MUA, NETC__MUA2__MUB, NETC__MUA3__MUA, NETC__MUA3__MUB, NETC__MUA4__MUA, NETC__MUA4__MUB, WAKEUP__MUI_A10__MUA, WAKEUP__MUI_A10__MUB, WAKEUP__MUI_A11__MUA, WAKEUP__MUI_A11__MUB, WAKEUP__MUI_A12__MUA, WAKEUP__MUI_A12__MUB, WAKEUP__MUI_A13__MUA, WAKEUP__MUI_A13__MUB, WAKEUP__MUI_A14__MUA, WAKEUP__MUI_A14__MUB, WAKEUP__MUI_A15__MUA, WAKEUP__MUI_A15__MUB, WAKEUP__MUI_A16__MUA, WAKEUP__MUI_A16__MUB, WAKEUP__MUI_A17__MUA, WAKEUP__MUI_A17__MUB, WAKEUP__MUI_A18__MUA, WAKEUP__MUI_A18__MUB, WAKEUP__V2X__MU0__MUA, WAKEUP__V2X__MU1__MUA, WAKEUP__V2X__MU2__MUA, WAKEUP__V2X__MU3__MUA, WAKEUP__V2X__MU4__MUA, WAKEUP__V2X__MU5__MUB }
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU1_A_IRQn, MU1_B_IRQn, MU2_A_IRQn, MU2_B_IRQn, MU3_A_IRQn, MU3_B_IRQn, MU4_A_IRQn, MU4_B_IRQn, MU5_A_IRQn, MU5_B_IRQn, MU6_A_IRQn, MU6_B_IRQn, NotAvail_IRQn, MU7_B_IRQn, NotAvail_IRQn, MU8_B_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* NECTMIX_CM33_AIPS - Peripheral instance base addresses */
/** Peripheral NETC__CM33_PCF1 base address */
#define NETC__CM33_PCF1_BASE                     (0x4D1B0000u)
/** Peripheral NETC__CM33_PCF1 base pointer */
#define NETC__CM33_PCF1                          ((NECTMIX_CM33_AIPS_Type *)NETC__CM33_PCF1_BASE)
/** Peripheral NETC__CM33_PSF1 base address */
#define NETC__CM33_PSF1_BASE                     (0x4D1C0000u)
/** Peripheral NETC__CM33_PSF1 base pointer */
#define NETC__CM33_PSF1                          ((NECTMIX_CM33_AIPS_Type *)NETC__CM33_PSF1_BASE)
/** Array initializer of NECTMIX_CM33_AIPS peripheral base addresses */
#define NECTMIX_CM33_AIPS_BASE_ADDRS             { NETC__CM33_PCF1_BASE, NETC__CM33_PSF1_BASE }
/** Array initializer of NECTMIX_CM33_AIPS peripheral base pointers */
#define NECTMIX_CM33_AIPS_BASE_PTRS              { NETC__CM33_PCF1, NETC__CM33_PSF1 }

/* NETC_CMU - Peripheral instance base addresses */
/** Peripheral NETC__CMU base address */
#define NETC__CMU_BASE                           (0x4D080000u)
/** Peripheral NETC__CMU base pointer */
#define NETC__CMU                                ((NETC_CMU_Type *)NETC__CMU_BASE)
/** Array initializer of NETC_CMU peripheral base addresses */
#define NETC_CMU_BASE_ADDRS                      { NETC__CMU_BASE }
/** Array initializer of NETC_CMU peripheral base pointers */
#define NETC_CMU_BASE_PTRS                       { NETC__CMU }

/* NETC_EIM - Peripheral instance base addresses */
/** Peripheral NETC__EIM base address */
#define NETC__EIM_BASE                           (0x4D070000u)
/** Peripheral NETC__EIM base pointer */
#define NETC__EIM                                ((NETC_EIM_Type *)NETC__EIM_BASE)
/** Array initializer of NETC_EIM peripheral base addresses */
#define NETC_EIM_BASE_ADDRS                      { NETC__EIM_BASE }
/** Array initializer of NETC_EIM peripheral base pointers */
#define NETC_EIM_BASE_PTRS                       { NETC__EIM }

/* NETC_ENETC - Peripheral instance base addresses */
/** Peripheral ENETC0_BASE base address */
#define ENETC0_BASE_BASE                         (0x4CC90000u)
/** Peripheral ENETC0_BASE base pointer */
#define ENETC0_BASE                              ((NETC_ENETC_Type *)ENETC0_BASE_BASE)
/** Peripheral ENETC1_BASE base address */
#define ENETC1_BASE_BASE                         (0x4CCD0000u)
/** Peripheral ENETC1_BASE base pointer */
#define ENETC1_BASE                              ((NETC_ENETC_Type *)ENETC1_BASE_BASE)
/** Peripheral ENETC2_BASE base address */
#define ENETC2_BASE_BASE                         (0x4CD10000u)
/** Peripheral ENETC2_BASE base pointer */
#define ENETC2_BASE                              ((NETC_ENETC_Type *)ENETC2_BASE_BASE)
/** Peripheral ENETC3_BASE base address */
#define ENETC3_BASE_BASE                         (0x4CD50000u)
/** Peripheral ENETC3_BASE base pointer */
#define ENETC3_BASE                              ((NETC_ENETC_Type *)ENETC3_BASE_BASE)
/** Array initializer of NETC_ENETC peripheral base addresses */
#define NETC_ENETC_BASE_ADDRS                    { ENETC0_BASE_BASE, ENETC1_BASE_BASE, ENETC2_BASE_BASE, ENETC3_BASE_BASE }
/** Array initializer of NETC_ENETC peripheral base pointers */
#define NETC_ENETC_BASE_PTRS                     { ENETC0_BASE, ENETC1_BASE, ENETC2_BASE, ENETC3_BASE }

/* NETC_ERM - Peripheral instance base addresses */
/** Peripheral NETC__ERM base address */
#define NETC__ERM_BASE                           (0x4D060000u)
/** Peripheral NETC__ERM base pointer */
#define NETC__ERM                                ((NETC_ERM_Type *)NETC__ERM_BASE)
/** Array initializer of NETC_ERM peripheral base addresses */
#define NETC_ERM_BASE_ADDRS                      { NETC__ERM_BASE }
/** Array initializer of NETC_ERM peripheral base pointers */
#define NETC_ERM_BASE_PTRS                       { NETC__ERM }

/* NETC_ETH_LINK - Peripheral instance base addresses */
/** Peripheral ENETC0_ETH_MAC_PORT base address */
#define ENETC0_ETH_MAC_PORT_BASE                 (0x4CC95000u)
/** Peripheral ENETC0_ETH_MAC_PORT base pointer */
#define ENETC0_ETH_MAC_PORT                      ((NETC_ETH_LINK_Type *)ENETC0_ETH_MAC_PORT_BASE)
/** Peripheral ENETC1_ETH_MAC_PORT base address */
#define ENETC1_ETH_MAC_PORT_BASE                 (0x4CCD5000u)
/** Peripheral ENETC1_ETH_MAC_PORT base pointer */
#define ENETC1_ETH_MAC_PORT                      ((NETC_ETH_LINK_Type *)ENETC1_ETH_MAC_PORT_BASE)
/** Peripheral ENETC2_ETH_MAC_PORT base address */
#define ENETC2_ETH_MAC_PORT_BASE                 (0x4CD15000u)
/** Peripheral ENETC2_ETH_MAC_PORT base pointer */
#define ENETC2_ETH_MAC_PORT                      ((NETC_ETH_LINK_Type *)ENETC2_ETH_MAC_PORT_BASE)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0 base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0_BASE (0x4CC05000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0 base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0 ((NETC_ETH_LINK_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0_BASE)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1 base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1_BASE (0x4CC09000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1 base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1 ((NETC_ETH_LINK_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1_BASE)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2 base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2_BASE (0x4CC0D000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2 base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2 ((NETC_ETH_LINK_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2_BASE)
/** Array initializer of NETC_ETH_LINK peripheral base addresses */
#define NETC_ETH_LINK_BASE_ADDRS                 { ENETC0_ETH_MAC_PORT_BASE, ENETC1_ETH_MAC_PORT_BASE, ENETC2_ETH_MAC_PORT_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2_BASE }
/** Array initializer of NETC_ETH_LINK peripheral base pointers */
#define NETC_ETH_LINK_BASE_PTRS                  { ENETC0_ETH_MAC_PORT, ENETC1_ETH_MAC_PORT, ENETC2_ETH_MAC_PORT, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2 }

/* NETC_IERB - Peripheral instance base addresses */
/** Peripheral NETC_IERB base address */
#define NETC_IERB_BASE                           (0x4CEB0000u)
/** Peripheral NETC_IERB base pointer */
#define NETC_IERB                                ((NETC_IERB_Type *)NETC_IERB_BASE)
/** Array initializer of NETC_IERB peripheral base addresses */
#define NETC_IERB_BASE_ADDRS                     { NETC_IERB_BASE }
/** Array initializer of NETC_IERB peripheral base pointers */
#define NETC_IERB_BASE_PTRS                      { NETC_IERB }

/* NETC_LSTCU - Peripheral instance base addresses */
/** Peripheral NETC__LSTCU base address */
#define NETC__LSTCU_BASE                         (0x4D090000u)
/** Peripheral NETC__LSTCU base pointer */
#define NETC__LSTCU                              ((NETC_LSTCU_Type *)NETC__LSTCU_BASE)
/** Array initializer of NETC_LSTCU peripheral base addresses */
#define NETC_LSTCU_BASE_ADDRS                    { NETC__LSTCU_BASE }
/** Array initializer of NETC_LSTCU peripheral base pointers */
#define NETC_LSTCU_BASE_PTRS                     { NETC__LSTCU }

/* NETC_MAX_CORE - Peripheral instance base addresses */
/** Peripheral NETC__AXBS_MAX_CORE base address */
#define NETC__AXBS_MAX_CORE_BASE                 (0x4D1D0000u)
/** Peripheral NETC__AXBS_MAX_CORE base pointer */
#define NETC__AXBS_MAX_CORE                      ((NETC_MAX_CORE_Type *)NETC__AXBS_MAX_CORE_BASE)
/** Array initializer of NETC_MAX_CORE peripheral base addresses */
#define NETC_MAX_CORE_BASE_ADDRS                 { NETC__AXBS_MAX_CORE_BASE }
/** Array initializer of NETC_MAX_CORE peripheral base pointers */
#define NETC_MAX_CORE_BASE_PTRS                  { NETC__AXBS_MAX_CORE }

/* NETC_OCSRAM_MCM - Peripheral instance base addresses */
/** Peripheral NETC__OCRAM_MCM base address */
#define NETC__OCRAM_MCM_BASE                     (0x4D0B0000u)
/** Peripheral NETC__OCRAM_MCM base pointer */
#define NETC__OCRAM_MCM                          ((NETC_OCSRAM_MCM_Type *)NETC__OCRAM_MCM_BASE)
/** Array initializer of NETC_OCSRAM_MCM peripheral base addresses */
#define NETC_OCSRAM_MCM_BASE_ADDRS               { NETC__OCRAM_MCM_BASE }
/** Array initializer of NETC_OCSRAM_MCM peripheral base pointers */
#define NETC_OCSRAM_MCM_BASE_PTRS                { NETC__OCRAM_MCM }

/* NETC_PORT - Peripheral instance base addresses */
/** Peripheral ENETC0_PORT base address */
#define ENETC0_PORT_BASE                         (0x4CC94000u)
/** Peripheral ENETC0_PORT base pointer */
#define ENETC0_PORT                              ((NETC_PORT_Type *)ENETC0_PORT_BASE)
/** Peripheral ENETC1_PORT base address */
#define ENETC1_PORT_BASE                         (0x4CCD4000u)
/** Peripheral ENETC1_PORT base pointer */
#define ENETC1_PORT                              ((NETC_PORT_Type *)ENETC1_PORT_BASE)
/** Peripheral ENETC2_PORT base address */
#define ENETC2_PORT_BASE                         (0x4CD14000u)
/** Peripheral ENETC2_PORT base pointer */
#define ENETC2_PORT                              ((NETC_PORT_Type *)ENETC2_PORT_BASE)
/** Peripheral SW0_PORT0 base address */
#define SW0_PORT0_BASE                           (0x4CC04000u)
/** Peripheral SW0_PORT0 base pointer */
#define SW0_PORT0                                ((NETC_PORT_Type *)SW0_PORT0_BASE)
/** Peripheral SW0_PORT1 base address */
#define SW0_PORT1_BASE                           (0x4CC08000u)
/** Peripheral SW0_PORT1 base pointer */
#define SW0_PORT1                                ((NETC_PORT_Type *)SW0_PORT1_BASE)
/** Peripheral SW0_PORT2 base address */
#define SW0_PORT2_BASE                           (0x4CC0C000u)
/** Peripheral SW0_PORT2 base pointer */
#define SW0_PORT2                                ((NETC_PORT_Type *)SW0_PORT2_BASE)
/** Array initializer of NETC_PORT peripheral base addresses */
#define NETC_PORT_BASE_ADDRS                     { ENETC0_PORT_BASE, ENETC1_PORT_BASE, ENETC2_PORT_BASE, SW0_PORT0_BASE, SW0_PORT1_BASE, SW0_PORT2_BASE }
/** Array initializer of NETC_PORT peripheral base pointers */
#define NETC_PORT_BASE_PTRS                      { ENETC0_PORT, ENETC1_PORT, ENETC2_PORT, SW0_PORT0, SW0_PORT1, SW0_PORT2 }

/* NETC_PRIV - Peripheral instance base addresses */
/** Peripheral NETC_PRIV base address */
#define NETC_PRIV_BASE                           (0x4CEC0000u)
/** Peripheral NETC_PRIV base pointer */
#define NETC_PRIV                                ((NETC_PRIV_Type *)NETC_PRIV_BASE)
/** Array initializer of NETC_PRIV peripheral base addresses */
#define NETC_PRIV_BASE_ADDRS                     { NETC_PRIV_BASE }
/** Array initializer of NETC_PRIV peripheral base pointers */
#define NETC_PRIV_BASE_PTRS                      { NETC_PRIV }

/* NETC_PSEUDO_LINK - Peripheral instance base addresses */
/** Peripheral ENETC3_PSEUDO_MAC_PORT base address */
#define ENETC3_PSEUDO_MAC_PORT_BASE              (0x4CD55000u)
/** Peripheral ENETC3_PSEUDO_MAC_PORT base pointer */
#define ENETC3_PSEUDO_MAC_PORT                   ((NETC_PSEUDO_LINK_Type *)ENETC3_PSEUDO_MAC_PORT_BASE)
/** Array initializer of NETC_PSEUDO_LINK peripheral base addresses */
#define NETC_PSEUDO_LINK_BASE_ADDRS              { ENETC3_PSEUDO_MAC_PORT_BASE }
/** Array initializer of NETC_PSEUDO_LINK peripheral base pointers */
#define NETC_PSEUDO_LINK_BASE_PTRS               { ENETC3_PSEUDO_MAC_PORT }

/* NETC_SW - Peripheral instance base addresses */
/** Peripheral SW0_BASE base address */
#define SW0_BASE_BASE                            (0x4CC00000u)
/** Peripheral SW0_BASE base pointer */
#define SW0_BASE                                 ((NETC_SW_Type *)SW0_BASE_BASE)
/** Array initializer of NETC_SW peripheral base addresses */
#define NETC_SW_BASE_ADDRS                       { SW0_BASE_BASE }
/** Array initializer of NETC_SW peripheral base pointers */
#define NETC_SW_BASE_PTRS                        { SW0_BASE }

/* NETC_SW_ENETC - Peripheral instance base addresses */
/** Peripheral ENETC0_COMMON base address */
#define ENETC0_COMMON_BASE                       (0x4CC91000u)
/** Peripheral ENETC0_COMMON base pointer */
#define ENETC0_COMMON                            ((NETC_SW_ENETC_Type *)ENETC0_COMMON_BASE)
/** Peripheral ENETC1_COMMON base address */
#define ENETC1_COMMON_BASE                       (0x4CCD1000u)
/** Peripheral ENETC1_COMMON base pointer */
#define ENETC1_COMMON                            ((NETC_SW_ENETC_Type *)ENETC1_COMMON_BASE)
/** Peripheral ENETC2_COMMON base address */
#define ENETC2_COMMON_BASE                       (0x4CD11000u)
/** Peripheral ENETC2_COMMON base pointer */
#define ENETC2_COMMON                            ((NETC_SW_ENETC_Type *)ENETC2_COMMON_BASE)
/** Peripheral SW0_COMMON base address */
#define SW0_COMMON_BASE                          (0x4CC01000u)
/** Peripheral SW0_COMMON base pointer */
#define SW0_COMMON                               ((NETC_SW_ENETC_Type *)SW0_COMMON_BASE)
/** Array initializer of NETC_SW_ENETC peripheral base addresses */
#define NETC_SW_ENETC_BASE_ADDRS                 { ENETC0_COMMON_BASE, ENETC1_COMMON_BASE, ENETC2_COMMON_BASE, SW0_COMMON_BASE }
/** Array initializer of NETC_SW_ENETC peripheral base pointers */
#define NETC_SW_ENETC_BASE_PTRS                  { ENETC0_COMMON, ENETC1_COMMON, ENETC2_COMMON, SW0_COMMON }

/* NETC_TCU - Peripheral instance base addresses */
/** Peripheral NETC__TCU base address */
#define NETC__TCU_BASE                           (0x4C800000u)
/** Peripheral NETC__TCU base pointer */
#define NETC__TCU                                ((NETC_TCU_Type *)NETC__TCU_BASE)
/** Array initializer of NETC_TCU peripheral base addresses */
#define NETC_TCU_BASE_ADDRS                      { NETC__TCU_BASE }
/** Array initializer of NETC_TCU peripheral base pointers */
#define NETC_TCU_BASE_PTRS                       { NETC__TCU }

/* NETC_TCU_CM33 - Peripheral instance base addresses */
/** Peripheral NETC__TCU_CM33 base address */
#define NETC__TCU_CM33_BASE                      (0x4D000000u)
/** Peripheral NETC__TCU_CM33 base pointer */
#define NETC__TCU_CM33                           ((NETC_TCU_CM33_Type *)NETC__TCU_CM33_BASE)
/** Array initializer of NETC_TCU_CM33 peripheral base addresses */
#define NETC_TCU_CM33_BASE_ADDRS                 { NETC__TCU_CM33_BASE }
/** Array initializer of NETC_TCU_CM33 peripheral base pointers */
#define NETC_TCU_CM33_BASE_PTRS                  { NETC__TCU_CM33 }

/* NETC_TMR_BASE - Peripheral instance base addresses */
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE_BASE (0x4CDA0000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE   ((NETC_TMR_BASE_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE_BASE)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE_BASE (0x4CDC0000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE   ((NETC_TMR_BASE_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE_BASE)
/** Array initializer of NETC_TMR_BASE peripheral base addresses */
#define NETC_TMR_BASE_BASE_ADDRS                 { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE_BASE }
/** Array initializer of NETC_TMR_BASE peripheral base pointers */
#define NETC_TMR_BASE_BASE_PTRS                  { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE }

/* NETC_TRDC_MGR - Peripheral instance base addresses */
/** Peripheral NETC__TRDC_MGRE base address */
#define NETC__TRDC_MGRE_BASE                     (0x4C840000u)
/** Peripheral NETC__TRDC_MGRE base pointer */
#define NETC__TRDC_MGRE                          ((NETC_TRDC_MGR_Type *)NETC__TRDC_MGRE_BASE)
/** Array initializer of NETC_TRDC_MGR peripheral base addresses */
#define NETC_TRDC_MGR_BASE_ADDRS                 { NETC__TRDC_MGRE_BASE }
/** Array initializer of NETC_TRDC_MGR peripheral base pointers */
#define NETC_TRDC_MGR_BASE_PTRS                  { NETC__TRDC_MGRE }

/* NETC_TRDC_MGR_CM33 - Peripheral instance base addresses */
/** Peripheral NETC__TRDC_MGRE_CM33 base address */
#define NETC__TRDC_MGRE_CM33_BASE                (0x4D040000u)
/** Peripheral NETC__TRDC_MGRE_CM33 base pointer */
#define NETC__TRDC_MGRE_CM33                     ((NETC_TRDC_MGR_CM33_Type *)NETC__TRDC_MGRE_CM33_BASE)
/** Array initializer of NETC_TRDC_MGR_CM33 peripheral base addresses */
#define NETC_TRDC_MGR_CM33_BASE_ADDRS            { NETC__TRDC_MGRE_CM33_BASE }
/** Array initializer of NETC_TRDC_MGR_CM33 peripheral base pointers */
#define NETC_TRDC_MGR_CM33_BASE_PTRS             { NETC__TRDC_MGRE_CM33 }

/* NEUTRON - Peripheral instance base addresses */
/** Peripheral NPU__NEUTRON_NPU__NEUTRON0__NEUTRON base address */
#define NPU__NEUTRON_NPU__NEUTRON0__NEUTRON_BASE (0x4ABC0000u)
/** Peripheral NPU__NEUTRON_NPU__NEUTRON0__NEUTRON base pointer */
#define NPU__NEUTRON_NPU__NEUTRON0__NEUTRON      ((NEUTRON_Type *)NPU__NEUTRON_NPU__NEUTRON0__NEUTRON_BASE)
/** Peripheral NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON base address */
#define NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON_BASE (0x4ABC4000u)
/** Peripheral NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON base pointer */
#define NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON ((NEUTRON_Type *)NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON_BASE)
/** Array initializer of NEUTRON peripheral base addresses */
#define NEUTRON_BASE_ADDRS                       { NPU__NEUTRON_NPU__NEUTRON0__NEUTRON_BASE, NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON_BASE }
/** Array initializer of NEUTRON peripheral base pointers */
#define NEUTRON_BASE_PTRS                        { NPU__NEUTRON_NPU__NEUTRON0__NEUTRON, NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON }

/* NOC_BLK_CTRL_NOCMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_NOCMIX base address */
#define BLK_CTRL_NOCMIX_BASE                     (0x49000000u)
/** Peripheral BLK_CTRL_NOCMIX base pointer */
#define BLK_CTRL_NOCMIX                          ((NOC_BLK_CTRL_NOCMIX_Type *)BLK_CTRL_NOCMIX_BASE)
/** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base addresses */
#define NOC_BLK_CTRL_NOCMIX_BASE_ADDRS           { BLK_CTRL_NOCMIX_BASE }
/** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base pointers */
#define NOC_BLK_CTRL_NOCMIX_BASE_PTRS            { BLK_CTRL_NOCMIX }

/* NOC_CMU - Peripheral instance base addresses */
/** Peripheral NOC__CMU_N0 base address */
#define NOC__CMU_N0_BASE                         (0x49070000u)
/** Peripheral NOC__CMU_N0 base pointer */
#define NOC__CMU_N0                              ((NOC_CMU_Type *)NOC__CMU_N0_BASE)
/** Peripheral NOC__CMU_N1 base address */
#define NOC__CMU_N1_BASE                         (0x49080000u)
/** Peripheral NOC__CMU_N1 base pointer */
#define NOC__CMU_N1                              ((NOC_CMU_Type *)NOC__CMU_N1_BASE)
/** Array initializer of NOC_CMU peripheral base addresses */
#define NOC_CMU_BASE_ADDRS                       { NOC__CMU_N0_BASE, NOC__CMU_N1_BASE }
/** Array initializer of NOC_CMU peripheral base pointers */
#define NOC_CMU_BASE_PTRS                        { NOC__CMU_N0, NOC__CMU_N1 }

/* NOC_EIM - Peripheral instance base addresses */
/** Peripheral NOC__EIMN base address */
#define NOC__EIMN_BASE                           (0x49210000u)
/** Peripheral NOC__EIMN base pointer */
#define NOC__EIMN                                ((NOC_EIM_Type *)NOC__EIMN_BASE)
/** Array initializer of NOC_EIM peripheral base addresses */
#define NOC_EIM_BASE_ADDRS                       { NOC__EIMN_BASE }
/** Array initializer of NOC_EIM peripheral base pointers */
#define NOC_EIM_BASE_PTRS                        { NOC__EIMN }

/* NOC_GICA - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICA base address */
#define NOC__GIC__GICA_BASE                      (0x48010000u)
/** Peripheral NOC__GIC__GICA base pointer */
#define NOC__GIC__GICA                           ((NOC_GICA_Type *)NOC__GIC__GICA_BASE)
/** Array initializer of NOC_GICA peripheral base addresses */
#define NOC_GICA_BASE_ADDRS                      { NOC__GIC__GICA_BASE }
/** Array initializer of NOC_GICA peripheral base pointers */
#define NOC_GICA_BASE_PTRS                       { NOC__GIC__GICA }

/* NOC_GICD - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICD base address */
#define NOC__GIC__GICD_BASE                      (0x48000000u)
/** Peripheral NOC__GIC__GICD base pointer */
#define NOC__GIC__GICD                           ((NOC_GICD_Type *)NOC__GIC__GICD_BASE)
/** Array initializer of NOC_GICD peripheral base addresses */
#define NOC_GICD_BASE_ADDRS                      { NOC__GIC__GICD_BASE }
/** Array initializer of NOC_GICD peripheral base pointers */
#define NOC_GICD_BASE_PTRS                       { NOC__GIC__GICD }

/* NOC_GICDA - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICDA base address */
#define NOC__GIC__GICDA_BASE                     (0x480E0000u)
/** Peripheral NOC__GIC__GICDA base pointer */
#define NOC__GIC__GICDA                          ((NOC_GICDA_Type *)NOC__GIC__GICDA_BASE)
/** Array initializer of NOC_GICDA peripheral base addresses */
#define NOC_GICDA_BASE_ADDRS                     { NOC__GIC__GICDA_BASE }
/** Array initializer of NOC_GICDA peripheral base pointers */
#define NOC_GICDA_BASE_PTRS                      { NOC__GIC__GICDA }

/* NOC_GICP - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICP base address */
#define NOC__GIC__GICP_BASE                      (0x48030000u)
/** Peripheral NOC__GIC__GICP base pointer */
#define NOC__GIC__GICP                           ((NOC_GICP_Type *)NOC__GIC__GICP_BASE)
/** Array initializer of NOC_GICP peripheral base addresses */
#define NOC_GICP_BASE_ADDRS                      { NOC__GIC__GICP_BASE }
/** Array initializer of NOC_GICP peripheral base pointers */
#define NOC_GICP_BASE_PTRS                       { NOC__GIC__GICP }

/* NOC_GICRlpi0 - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICRLPI0 base address */
#define NOC__GIC__GICRLPI0_BASE                  (0x48060000u)
/** Peripheral NOC__GIC__GICRLPI0 base pointer */
#define NOC__GIC__GICRLPI0                       ((NOC_GICRlpi0_Type *)NOC__GIC__GICRLPI0_BASE)
/** Array initializer of NOC_GICRlpi0 peripheral base addresses */
#define NOC_GICRlpi0_BASE_ADDRS                  { NOC__GIC__GICRLPI0_BASE }
/** Array initializer of NOC_GICRlpi0 peripheral base pointers */
#define NOC_GICRlpi0_BASE_PTRS                   { NOC__GIC__GICRLPI0 }

/* NOC_GICRlpi1 - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICRLPI1 base address */
#define NOC__GIC__GICRLPI1_BASE                  (0x48080000u)
/** Peripheral NOC__GIC__GICRLPI1 base pointer */
#define NOC__GIC__GICRLPI1                       ((NOC_GICRlpi1_Type *)NOC__GIC__GICRLPI1_BASE)
/** Array initializer of NOC_GICRlpi1 peripheral base addresses */
#define NOC_GICRlpi1_BASE_ADDRS                  { NOC__GIC__GICRLPI1_BASE }
/** Array initializer of NOC_GICRlpi1 peripheral base pointers */
#define NOC_GICRlpi1_BASE_PTRS                   { NOC__GIC__GICRLPI1 }

/* NOC_GICRlpi2 - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICRLPI2 base address */
#define NOC__GIC__GICRLPI2_BASE                  (0x480A0000u)
/** Peripheral NOC__GIC__GICRLPI2 base pointer */
#define NOC__GIC__GICRLPI2                       ((NOC_GICRlpi2_Type *)NOC__GIC__GICRLPI2_BASE)
/** Array initializer of NOC_GICRlpi2 peripheral base addresses */
#define NOC_GICRlpi2_BASE_ADDRS                  { NOC__GIC__GICRLPI2_BASE }
/** Array initializer of NOC_GICRlpi2 peripheral base pointers */
#define NOC_GICRlpi2_BASE_PTRS                   { NOC__GIC__GICRLPI2 }

/* NOC_GICRlpi3 - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICRLPI3 base address */
#define NOC__GIC__GICRLPI3_BASE                  (0x480C0000u)
/** Peripheral NOC__GIC__GICRLPI3 base pointer */
#define NOC__GIC__GICRLPI3                       ((NOC_GICRlpi3_Type *)NOC__GIC__GICRLPI3_BASE)
/** Array initializer of NOC_GICRlpi3 peripheral base addresses */
#define NOC_GICRlpi3_BASE_ADDRS                  { NOC__GIC__GICRLPI3_BASE }
/** Array initializer of NOC_GICRlpi3 peripheral base pointers */
#define NOC_GICRlpi3_BASE_PTRS                   { NOC__GIC__GICRLPI3 }

/* NOC_GICRsgi0 - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICRSGI0 base address */
#define NOC__GIC__GICRSGI0_BASE                  (0x48070000u)
/** Peripheral NOC__GIC__GICRSGI0 base pointer */
#define NOC__GIC__GICRSGI0                       ((NOC_GICRsgi0_Type *)NOC__GIC__GICRSGI0_BASE)
/** Array initializer of NOC_GICRsgi0 peripheral base addresses */
#define NOC_GICRsgi0_BASE_ADDRS                  { NOC__GIC__GICRSGI0_BASE }
/** Array initializer of NOC_GICRsgi0 peripheral base pointers */
#define NOC_GICRsgi0_BASE_PTRS                   { NOC__GIC__GICRSGI0 }

/* NOC_GICRsgi2 - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICRSGI2 base address */
#define NOC__GIC__GICRSGI2_BASE                  (0x480B0000u)
/** Peripheral NOC__GIC__GICRSGI2 base pointer */
#define NOC__GIC__GICRSGI2                       ((NOC_GICRsgi2_Type *)NOC__GIC__GICRSGI2_BASE)
/** Array initializer of NOC_GICRsgi2 peripheral base addresses */
#define NOC_GICRsgi2_BASE_ADDRS                  { NOC__GIC__GICRSGI2_BASE }
/** Array initializer of NOC_GICRsgi2 peripheral base pointers */
#define NOC_GICRsgi2_BASE_PTRS                   { NOC__GIC__GICRSGI2 }

/* NOC_GICRsgi3 - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICRSGI3 base address */
#define NOC__GIC__GICRSGI3_BASE                  (0x480D0000u)
/** Peripheral NOC__GIC__GICRSGI3 base pointer */
#define NOC__GIC__GICRSGI3                       ((NOC_GICRsgi3_Type *)NOC__GIC__GICRSGI3_BASE)
/** Array initializer of NOC_GICRsgi3 peripheral base addresses */
#define NOC_GICRsgi3_BASE_ADDRS                  { NOC__GIC__GICRSGI3_BASE }
/** Array initializer of NOC_GICRsgi3 peripheral base pointers */
#define NOC_GICRsgi3_BASE_PTRS                   { NOC__GIC__GICRSGI3 }

/* NOC_GICRsgil - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICRSGI1 base address */
#define NOC__GIC__GICRSGI1_BASE                  (0x48090000u)
/** Peripheral NOC__GIC__GICRSGI1 base pointer */
#define NOC__GIC__GICRSGI1                       ((NOC_GICRsgil_Type *)NOC__GIC__GICRSGI1_BASE)
/** Array initializer of NOC_GICRsgil peripheral base addresses */
#define NOC_GICRsgil_BASE_ADDRS                  { NOC__GIC__GICRSGI1_BASE }
/** Array initializer of NOC_GICRsgil peripheral base pointers */
#define NOC_GICRsgil_BASE_PTRS                   { NOC__GIC__GICRSGI1 }

/* NOC_GICT - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GICT base address */
#define NOC__GIC__GICT_BASE                      (0x48020000u)
/** Peripheral NOC__GIC__GICT base pointer */
#define NOC__GIC__GICT                           ((NOC_GICT_Type *)NOC__GIC__GICT_BASE)
/** Array initializer of NOC_GICT peripheral base addresses */
#define NOC_GICT_BASE_ADDRS                      { NOC__GIC__GICT_BASE }
/** Array initializer of NOC_GICT peripheral base pointers */
#define NOC_GICT_BASE_PTRS                       { NOC__GIC__GICT }

/* NOC_GITS0 - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GITS0 base address */
#define NOC__GIC__GITS0_BASE                     (0x48040000u)
/** Peripheral NOC__GIC__GITS0 base pointer */
#define NOC__GIC__GITS0                          ((NOC_GITS0_Type *)NOC__GIC__GITS0_BASE)
/** Array initializer of NOC_GITS0 peripheral base addresses */
#define NOC_GITS0_BASE_ADDRS                     { NOC__GIC__GITS0_BASE }
/** Array initializer of NOC_GITS0 peripheral base pointers */
#define NOC_GITS0_BASE_PTRS                      { NOC__GIC__GITS0 }

/* NOC_GITS0translater - Peripheral instance base addresses */
/** Peripheral NOC__GIC__GITS0TRANSLATER base address */
#define NOC__GIC__GITS0TRANSLATER_BASE           (0x48050000u)
/** Peripheral NOC__GIC__GITS0TRANSLATER base pointer */
#define NOC__GIC__GITS0TRANSLATER                ((NOC_GITS0translater_Type *)NOC__GIC__GITS0TRANSLATER_BASE)
/** Array initializer of NOC_GITS0translater peripheral base addresses */
#define NOC_GITS0translater_BASE_ADDRS           { NOC__GIC__GITS0TRANSLATER_BASE }
/** Array initializer of NOC_GITS0translater peripheral base pointers */
#define NOC_GITS0translater_BASE_PTRS            { NOC__GIC__GITS0TRANSLATER }

/* NOC_I_LCDIF_rd_I_main_QosG - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR base address */
#define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE (0x4B151000u)
/** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR base pointer */
#define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR ((NOC_I_LCDIF_rd_I_main_QosG_Type *)DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_I_LCDIF_rd_I_main_QosG peripheral base addresses */
#define NOC_I_LCDIF_rd_I_main_QosG_BASE_ADDRS    { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_I_LCDIF_rd_I_main_QosG peripheral base pointers */
#define NOC_I_LCDIF_rd_I_main_QosG_BASE_PTRS     { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR }

/* NOC_I_LCDIF_rd_I_main_TranStatFltr - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER base
 * address */
#define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x4B151180u)
/** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER base
 * pointer */
#define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_I_LCDIF_rd_I_main_TranStatFltr_Type *)DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of NOC_I_LCDIF_rd_I_main_TranStatFltr peripheral base
 * addresses */
#define NOC_I_LCDIF_rd_I_main_TranStatFltr_BASE_ADDRS { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of NOC_I_LCDIF_rd_I_main_TranStatFltr peripheral base
 * pointers */
#define NOC_I_LCDIF_rd_I_main_TranStatFltr_BASE_PTRS { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER }

/* NOC_I_PXP_rd_I_main_QosG - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR base address */
#define DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE (0x4B151080u)
/** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR base pointer */
#define DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR ((NOC_I_PXP_rd_I_main_QosG_Type *)DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_I_PXP_rd_I_main_QosG peripheral base addresses */
#define NOC_I_PXP_rd_I_main_QosG_BASE_ADDRS      { DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_I_PXP_rd_I_main_QosG peripheral base pointers */
#define NOC_I_PXP_rd_I_main_QosG_BASE_PTRS       { DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR }

/* NOC_I_PXP_rd_I_main_TranStatFltr - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER base address
 * */
#define DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x4B151200u)
/** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer
 * */
#define DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_I_PXP_rd_I_main_TranStatFltr_Type *)DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of NOC_I_PXP_rd_I_main_TranStatFltr peripheral base
 * addresses */
#define NOC_I_PXP_rd_I_main_TranStatFltr_BASE_ADDRS { DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of NOC_I_PXP_rd_I_main_TranStatFltr peripheral base
 * pointers */
#define NOC_I_PXP_rd_I_main_TranStatFltr_BASE_PTRS { DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER }

/* NOC_I_PXP_wr_I_main_QosG - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR base address */
#define DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE (0x4B151100u)
/** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR base pointer */
#define DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR ((NOC_I_PXP_wr_I_main_QosG_Type *)DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_I_PXP_wr_I_main_QosG peripheral base addresses */
#define NOC_I_PXP_wr_I_main_QosG_BASE_ADDRS      { DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_I_PXP_wr_I_main_QosG peripheral base pointers */
#define NOC_I_PXP_wr_I_main_QosG_BASE_PTRS       { DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR }

/* NOC_I_PXP_wr_I_main_TranStatFltr - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER base address
 * */
#define DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x4B151280u)
/** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer
 * */
#define DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER ((NOC_I_PXP_wr_I_main_TranStatFltr_Type *)DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of NOC_I_PXP_wr_I_main_TranStatFltr peripheral base
 * addresses */
#define NOC_I_PXP_wr_I_main_TranStatFltr_BASE_ADDRS { DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of NOC_I_PXP_wr_I_main_TranStatFltr peripheral base
 * pointers */
#define NOC_I_PXP_wr_I_main_TranStatFltr_BASE_PTRS { DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER }

/* NOC_LSTCU - Peripheral instance base addresses */
/** Peripheral NOC__LSTCUN base address */
#define NOC__LSTCUN_BASE                         (0x490B0000u)
/** Peripheral NOC__LSTCUN base pointer */
#define NOC__LSTCUN                              ((NOC_LSTCU_Type *)NOC__LSTCUN_BASE)
/** Array initializer of NOC_LSTCU peripheral base addresses */
#define NOC_LSTCU_BASE_ADDRS                     { NOC__LSTCUN_BASE }
/** Array initializer of NOC_LSTCU peripheral base pointers */
#define NOC_LSTCU_BASE_PTRS                      { NOC__LSTCUN }

/* NOC_Probe_LCDIF_rd_main_Probe - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE base address */
#define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE_BASE (0x4B150400u)
/** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE base pointer */
#define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE  ((NOC_Probe_LCDIF_rd_main_Probe_Type *)DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE_BASE)
/** Array initializer of NOC_Probe_LCDIF_rd_main_Probe peripheral base addresses
 * */
#define NOC_Probe_LCDIF_rd_main_Probe_BASE_ADDRS { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE_BASE }
/** Array initializer of NOC_Probe_LCDIF_rd_main_Probe peripheral base pointers
 * */
#define NOC_Probe_LCDIF_rd_main_Probe_BASE_PTRS  { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE }

/* NOC_Probe_LCDIF_rd_main_TrStProf - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER base
 * address */
#define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER_BASE (0x4B151300u)
/** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER base
 * pointer */
#define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_LCDIF_rd_main_TrStProf_Type *)DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER_BASE)
/** Array initializer of NOC_Probe_LCDIF_rd_main_TrStProf peripheral base
 * addresses */
#define NOC_Probe_LCDIF_rd_main_TrStProf_BASE_ADDRS { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER_BASE }
/** Array initializer of NOC_Probe_LCDIF_rd_main_TrStProf peripheral base
 * pointers */
#define NOC_Probe_LCDIF_rd_main_TrStProf_BASE_PTRS { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER }

/* NOC_Probe_PXP_rd_main_Probe - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE base address */
#define DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE (0x4B150800u)
/** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE base pointer */
#define DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE    ((NOC_Probe_PXP_rd_main_Probe_Type *)DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE)
/** Array initializer of NOC_Probe_PXP_rd_main_Probe peripheral base addresses */
#define NOC_Probe_PXP_rd_main_Probe_BASE_ADDRS   { DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE }
/** Array initializer of NOC_Probe_PXP_rd_main_Probe peripheral base pointers */
#define NOC_Probe_PXP_rd_main_Probe_BASE_PTRS    { DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE }

/* NOC_Probe_PXP_rd_main_TrStProf - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER base
 * address */
#define DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER_BASE (0x4B151380u)
/** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER base
 * pointer */
#define DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_PXP_rd_main_TrStProf_Type *)DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER_BASE)
/** Array initializer of NOC_Probe_PXP_rd_main_TrStProf peripheral base
 * addresses */
#define NOC_Probe_PXP_rd_main_TrStProf_BASE_ADDRS { DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER_BASE }
/** Array initializer of NOC_Probe_PXP_rd_main_TrStProf peripheral base pointers
 * */
#define NOC_Probe_PXP_rd_main_TrStProf_BASE_PTRS { DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER }

/* NOC_Probe_PXP_wr_main_Probe - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE base address */
#define DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE (0x4B150C00u)
/** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE base pointer */
#define DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE    ((NOC_Probe_PXP_wr_main_Probe_Type *)DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE)
/** Array initializer of NOC_Probe_PXP_wr_main_Probe peripheral base addresses */
#define NOC_Probe_PXP_wr_main_Probe_BASE_ADDRS   { DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE }
/** Array initializer of NOC_Probe_PXP_wr_main_Probe peripheral base pointers */
#define NOC_Probe_PXP_wr_main_Probe_BASE_PTRS    { DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE }

/* NOC_Probe_PXP_wr_main_TrStProf - Peripheral instance base addresses */
/** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER base
 * address */
#define DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER_BASE (0x4B151400u)
/** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER base
 * pointer */
#define DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_PXP_wr_main_TrStProf_Type *)DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER_BASE)
/** Array initializer of NOC_Probe_PXP_wr_main_TrStProf peripheral base
 * addresses */
#define NOC_Probe_PXP_wr_main_TrStProf_BASE_ADDRS { DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER_BASE }
/** Array initializer of NOC_Probe_PXP_wr_main_TrStProf peripheral base pointers
 * */
#define NOC_Probe_PXP_wr_main_TrStProf_BASE_PTRS { DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER }

/* NOC_Probe_m_e_0_main_Probe - Peripheral instance base addresses */
/** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_PROBE base address */
#define NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE    (0x49060000u)
/** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_PROBE base pointer */
#define NOC__GPV__PROBE_M_E_0_MAIN_PROBE         ((NOC_Probe_m_e_0_main_Probe_Type *)NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE)
/** Array initializer of NOC_Probe_m_e_0_main_Probe peripheral base addresses */
#define NOC_Probe_m_e_0_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE }
/** Array initializer of NOC_Probe_m_e_0_main_Probe peripheral base pointers */
#define NOC_Probe_m_e_0_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_0_MAIN_PROBE }

/* NOC_Probe_m_e_0_main_TranStatProf - Peripheral instance base addresses */
/** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER base address */
#define NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER_BASE (0x49063980u)
/** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER base pointer */
#define NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_m_e_0_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER_BASE)
/** Array initializer of NOC_Probe_m_e_0_main_TranStatProf peripheral base
 * addresses */
#define NOC_Probe_m_e_0_main_TranStatProf_BASE_ADDRS { NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER_BASE }
/** Array initializer of NOC_Probe_m_e_0_main_TranStatProf peripheral base
 * pointers */
#define NOC_Probe_m_e_0_main_TranStatProf_BASE_PTRS { NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER }

/* NOC_Probe_m_e_3_main_Probe - Peripheral instance base addresses */
/** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_PROBE base address */
#define NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE    (0x49060400u)
/** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_PROBE base pointer */
#define NOC__GPV__PROBE_M_E_3_MAIN_PROBE         ((NOC_Probe_m_e_3_main_Probe_Type *)NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE)
/** Array initializer of NOC_Probe_m_e_3_main_Probe peripheral base addresses */
#define NOC_Probe_m_e_3_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE }
/** Array initializer of NOC_Probe_m_e_3_main_Probe peripheral base pointers */
#define NOC_Probe_m_e_3_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_3_MAIN_PROBE }

/* NOC_Probe_m_e_3_main_TranStatProf - Peripheral instance base addresses */
/** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER base address */
#define NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER_BASE (0x49063A00u)
/** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER base pointer */
#define NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_m_e_3_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER_BASE)
/** Array initializer of NOC_Probe_m_e_3_main_TranStatProf peripheral base
 * addresses */
#define NOC_Probe_m_e_3_main_TranStatProf_BASE_ADDRS { NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER_BASE }
/** Array initializer of NOC_Probe_m_e_3_main_TranStatProf peripheral base
 * pointers */
#define NOC_Probe_m_e_3_main_TranStatProf_BASE_PTRS { NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER }

/* NOC_Probe_m_e_6_main_Probe - Peripheral instance base addresses */
/** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_PROBE base address */
#define NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE    (0x49061000u)
/** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_PROBE base pointer */
#define NOC__GPV__PROBE_M_E_6_MAIN_PROBE         ((NOC_Probe_m_e_6_main_Probe_Type *)NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE)
/** Array initializer of NOC_Probe_m_e_6_main_Probe peripheral base addresses */
#define NOC_Probe_m_e_6_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE }
/** Array initializer of NOC_Probe_m_e_6_main_Probe peripheral base pointers */
#define NOC_Probe_m_e_6_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_6_MAIN_PROBE }

/* NOC_Probe_m_e_6_main_TranStatProf - Peripheral instance base addresses */
/** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER base address */
#define NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER_BASE (0x49063B80u)
/** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER base pointer */
#define NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_m_e_6_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER_BASE)
/** Array initializer of NOC_Probe_m_e_6_main_TranStatProf peripheral base
 * addresses */
#define NOC_Probe_m_e_6_main_TranStatProf_BASE_ADDRS { NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER_BASE }
/** Array initializer of NOC_Probe_m_e_6_main_TranStatProf peripheral base
 * pointers */
#define NOC_Probe_m_e_6_main_TranStatProf_BASE_PTRS { NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER }

/* NOC_Probe_m_e_7_main_Probe - Peripheral instance base addresses */
/** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_PROBE base address */
#define NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE    (0x49061400u)
/** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_PROBE base pointer */
#define NOC__GPV__PROBE_M_E_7_MAIN_PROBE         ((NOC_Probe_m_e_7_main_Probe_Type *)NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE)
/** Array initializer of NOC_Probe_m_e_7_main_Probe peripheral base addresses */
#define NOC_Probe_m_e_7_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE }
/** Array initializer of NOC_Probe_m_e_7_main_Probe peripheral base pointers */
#define NOC_Probe_m_e_7_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_7_MAIN_PROBE }

/* NOC_Probe_m_e_7_main_TranStatProf - Peripheral instance base addresses */
/** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER base address */
#define NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER_BASE (0x49063C00u)
/** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER base pointer */
#define NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_m_e_7_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER_BASE)
/** Array initializer of NOC_Probe_m_e_7_main_TranStatProf peripheral base
 * addresses */
#define NOC_Probe_m_e_7_main_TranStatProf_BASE_ADDRS { NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER_BASE }
/** Array initializer of NOC_Probe_m_e_7_main_TranStatProf peripheral base
 * pointers */
#define NOC_Probe_m_e_7_main_TranStatProf_BASE_PTRS { NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER }

/* NOC_Probe_m_e_9_main_Probe - Peripheral instance base addresses */
/** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_PROBE base address */
#define NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE    (0x49061800u)
/** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_PROBE base pointer */
#define NOC__GPV__PROBE_M_E_9_MAIN_PROBE         ((NOC_Probe_m_e_9_main_Probe_Type *)NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE)
/** Array initializer of NOC_Probe_m_e_9_main_Probe peripheral base addresses */
#define NOC_Probe_m_e_9_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE }
/** Array initializer of NOC_Probe_m_e_9_main_Probe peripheral base pointers */
#define NOC_Probe_m_e_9_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_9_MAIN_PROBE }

/* NOC_Probe_m_e_9_main_TranStatProf - Peripheral instance base addresses */
/** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER base address */
#define NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER_BASE (0x49063C80u)
/** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER base pointer */
#define NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_m_e_9_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER_BASE)
/** Array initializer of NOC_Probe_m_e_9_main_TranStatProf peripheral base
 * addresses */
#define NOC_Probe_m_e_9_main_TranStatProf_BASE_ADDRS { NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER_BASE }
/** Array initializer of NOC_Probe_m_e_9_main_TranStatProf peripheral base
 * pointers */
#define NOC_Probe_m_e_9_main_TranStatProf_BASE_PTRS { NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER }

/* NOC_SRAMCTL - Peripheral instance base addresses */
/** Peripheral NOC__SRAMCTL base address */
#define NOC__SRAMCTL_BASE                        (0x490A0000u)
/** Peripheral NOC__SRAMCTL base pointer */
#define NOC__SRAMCTL                             ((NOC_SRAMCTL_Type *)NOC__SRAMCTL_BASE)
/** Array initializer of NOC_SRAMCTL peripheral base addresses */
#define NOC_SRAMCTL_BASE_ADDRS                   { NOC__SRAMCTL_BASE }
/** Array initializer of NOC_SRAMCTL peripheral base pointers */
#define NOC_SRAMCTL_BASE_PTRS                    { NOC__SRAMCTL }

/* NOC_TCU - Peripheral instance base addresses */
/** Peripheral NOC__TCU base address */
#define NOC__TCU_BASE                            (0x49040000u)
/** Peripheral NOC__TCU base pointer */
#define NOC__TCU                                 ((NOC_TCU_Type *)NOC__TCU_BASE)
/** Array initializer of NOC_TCU peripheral base addresses */
#define NOC_TCU_BASE_ADDRS                       { NOC__TCU_BASE }
/** Array initializer of NOC_TCU peripheral base pointers */
#define NOC_TCU_BASE_PTRS                        { NOC__TCU }

/* NOC_TRDC_MGR - Peripheral instance base addresses */
/** Peripheral NOC__TRDC_MGRN base address */
#define NOC__TRDC_MGRN_BASE                      (0x49010000u)
/** Peripheral NOC__TRDC_MGRN base pointer */
#define NOC__TRDC_MGRN                           ((NOC_TRDC_MGR_Type *)NOC__TRDC_MGRN_BASE)
/** Array initializer of NOC_TRDC_MGR peripheral base addresses */
#define NOC_TRDC_MGR_BASE_ADDRS                  { NOC__TRDC_MGRN_BASE }
/** Array initializer of NOC_TRDC_MGR peripheral base pointers */
#define NOC_TRDC_MGR_BASE_PTRS                   { NOC__TRDC_MGRN }

/* NOC_always_on_main_ResFaultCntr - Peripheral instance base addresses */
/** Peripheral NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER base address */
#define NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER_BASE (0x49063080u)
/** Peripheral NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER base pointer */
#define NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER ((NOC_always_on_main_ResFaultCntr_Type *)NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER_BASE)
/** Array initializer of NOC_always_on_main_ResFaultCntr peripheral base
 * addresses */
#define NOC_always_on_main_ResFaultCntr_BASE_ADDRS { NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER_BASE }
/** Array initializer of NOC_always_on_main_ResFaultCntr peripheral base
 * pointers */
#define NOC_always_on_main_ResFaultCntr_BASE_PTRS { NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER }

/* NOC_m_e_0_rd_I_m_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE (0x49062400u)
/** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_0_rd_I_m_QosGen_Type *)NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_0_rd_I_m_QosGen peripheral base addresses */
#define NOC_m_e_0_rd_I_m_QosGen_BASE_ADDRS       { NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_0_rd_I_m_QosGen peripheral base pointers */
#define NOC_m_e_0_rd_I_m_QosGen_BASE_PTRS        { NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR }

/* NOC_m_e_0_rd_I_main_TranStatFilt - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
#define NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x49063100u)
/** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
#define NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_0_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of NOC_m_e_0_rd_I_main_TranStatFilt peripheral base
 * addresses */
#define NOC_m_e_0_rd_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of NOC_m_e_0_rd_I_main_TranStatFilt peripheral base
 * pointers */
#define NOC_m_e_0_rd_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER }

/* NOC_m_e_0_wr_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE (0x49062480u)
/** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_0_wr_I_main_QosGen_Type *)NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_0_wr_I_main_QosGen peripheral base addresses */
#define NOC_m_e_0_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_0_wr_I_main_QosGen peripheral base pointers */
#define NOC_m_e_0_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR }

/* NOC_m_e_0_wr_I_main_TranStatFilt - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
#define NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x49063180u)
/** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
#define NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_0_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of NOC_m_e_0_wr_I_main_TranStatFilt peripheral base
 * addresses */
#define NOC_m_e_0_wr_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of NOC_m_e_0_wr_I_main_TranStatFilt peripheral base
 * pointers */
#define NOC_m_e_0_wr_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER }

/* NOC_m_e_1a_rd_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE (0x49062500u)
/** Peripheral NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR  ((NOC_m_e_1a_rd_I_main_QosGen_Type *)NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_1a_rd_I_main_QosGen peripheral base addresses */
#define NOC_m_e_1a_rd_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_1a_rd_I_main_QosGen peripheral base pointers */
#define NOC_m_e_1a_rd_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR }

/* NOC_m_e_1a_wr_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE (0x49062580u)
/** Peripheral NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR  ((NOC_m_e_1a_wr_I_main_QosGen_Type *)NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_1a_wr_I_main_QosGen peripheral base addresses */
#define NOC_m_e_1a_wr_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_1a_wr_I_main_QosGen peripheral base pointers */
#define NOC_m_e_1a_wr_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR }

/* NOC_m_e_1b_rd_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE (0x49062600u)
/** Peripheral NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR  ((NOC_m_e_1b_rd_I_main_QosGen_Type *)NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_1b_rd_I_main_QosGen peripheral base addresses */
#define NOC_m_e_1b_rd_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_1b_rd_I_main_QosGen peripheral base pointers */
#define NOC_m_e_1b_rd_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR }

/* NOC_m_e_1b_wr_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE (0x49062680u)
/** Peripheral NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR  ((NOC_m_e_1b_wr_I_main_QosGen_Type *)NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_1b_wr_I_main_QosGen peripheral base addresses */
#define NOC_m_e_1b_wr_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_1b_wr_I_main_QosGen peripheral base pointers */
#define NOC_m_e_1b_wr_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR }

/* NOC_m_e_3_rd_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE (0x49062800u)
/** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_3_rd_I_main_QosGen_Type *)NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_3_rd_I_main_QosGen peripheral base addresses */
#define NOC_m_e_3_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_3_rd_I_main_QosGen peripheral base pointers */
#define NOC_m_e_3_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR }

/* NOC_m_e_3_rd_I_main_TranStatFilt - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
#define NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x49063200u)
/** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
#define NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_3_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of NOC_m_e_3_rd_I_main_TranStatFilt peripheral base
 * addresses */
#define NOC_m_e_3_rd_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of NOC_m_e_3_rd_I_main_TranStatFilt peripheral base
 * pointers */
#define NOC_m_e_3_rd_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER }

/* NOC_m_e_3_wr_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE (0x49062880u)
/** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_3_wr_I_main_QosGen_Type *)NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_3_wr_I_main_QosGen peripheral base addresses */
#define NOC_m_e_3_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_3_wr_I_main_QosGen peripheral base pointers */
#define NOC_m_e_3_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR }

/* NOC_m_e_6_rd_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE (0x49062B00u)
/** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_6_rd_I_main_QosGen_Type *)NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_6_rd_I_main_QosGen peripheral base addresses */
#define NOC_m_e_6_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_6_rd_I_main_QosGen peripheral base pointers */
#define NOC_m_e_6_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR }

/* NOC_m_e_6_rd_I_main_TranStatFilt - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
#define NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x49063500u)
/** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
#define NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_6_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of NOC_m_e_6_rd_I_main_TranStatFilt peripheral base
 * addresses */
#define NOC_m_e_6_rd_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of NOC_m_e_6_rd_I_main_TranStatFilt peripheral base
 * pointers */
#define NOC_m_e_6_rd_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER }

/* NOC_m_e_6_wr_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE (0x49062B80u)
/** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_6_wr_I_main_QosGen_Type *)NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_6_wr_I_main_QosGen peripheral base addresses */
#define NOC_m_e_6_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_6_wr_I_main_QosGen peripheral base pointers */
#define NOC_m_e_6_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR }

/* NOC_m_e_6_wr_I_main_TranStatFilt - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
#define NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x49063580u)
/** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
#define NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_6_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of NOC_m_e_6_wr_I_main_TranStatFilt peripheral base
 * addresses */
#define NOC_m_e_6_wr_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of NOC_m_e_6_wr_I_main_TranStatFilt peripheral base
 * pointers */
#define NOC_m_e_6_wr_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER }

/* NOC_m_e_7_rd_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE (0x49062C00u)
/** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_7_rd_I_main_QosGen_Type *)NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_7_rd_I_main_QosGen peripheral base addresses */
#define NOC_m_e_7_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_7_rd_I_main_QosGen peripheral base pointers */
#define NOC_m_e_7_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR }

/* NOC_m_e_7_rd_I_main_TranStatFilt - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
#define NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x49063600u)
/** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
#define NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_7_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of NOC_m_e_7_rd_I_main_TranStatFilt peripheral base
 * addresses */
#define NOC_m_e_7_rd_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of NOC_m_e_7_rd_I_main_TranStatFilt peripheral base
 * pointers */
#define NOC_m_e_7_rd_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER }

/* NOC_m_e_7_wr_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE (0x49062D80u)
/** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_7_wr_I_main_QosGen_Type *)NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_7_wr_I_main_QosGen peripheral base addresses */
#define NOC_m_e_7_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_7_wr_I_main_QosGen peripheral base pointers */
#define NOC_m_e_7_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR }

/* NOC_m_e_7_wr_I_main_TranStatFilt - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
#define NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x49063680u)
/** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
#define NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_7_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of NOC_m_e_7_wr_I_main_TranStatFilt peripheral base
 * addresses */
#define NOC_m_e_7_wr_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of NOC_m_e_7_wr_I_main_TranStatFilt peripheral base
 * pointers */
#define NOC_m_e_7_wr_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER }

/* NOC_m_e_9_rd_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE (0x49062E00u)
/** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_9_rd_I_main_QosGen_Type *)NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_9_rd_I_main_QosGen peripheral base addresses */
#define NOC_m_e_9_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_9_rd_I_main_QosGen peripheral base pointers */
#define NOC_m_e_9_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR }

/* NOC_m_e_9_wr_I_main_QosGen - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR base address */
#define NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE (0x49062E80u)
/** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR base pointer */
#define NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_9_wr_I_main_QosGen_Type *)NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE)
/** Array initializer of NOC_m_e_9_wr_I_main_QosGen peripheral base addresses */
#define NOC_m_e_9_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE }
/** Array initializer of NOC_m_e_9_wr_I_main_QosGen peripheral base pointers */
#define NOC_m_e_9_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR }

/* NOC_m_e_9_wr_I_main_TranStatFilt - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
#define NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x49063780u)
/** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
#define NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_9_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of NOC_m_e_9_wr_I_main_TranStatFilt peripheral base
 * addresses */
#define NOC_m_e_9_wr_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of NOC_m_e_9_wr_I_main_TranStatFilt peripheral base
 * pointers */
#define NOC_m_e_9_wr_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER }

/* NPU_EIM - Peripheral instance base addresses */
/** Peripheral NPU__EIM_NPUMIX base address */
#define NPU__EIM_NPUMIX_BASE                     (0x4A860000u)
/** Peripheral NPU__EIM_NPUMIX base pointer */
#define NPU__EIM_NPUMIX                          ((NPU_EIM_Type *)NPU__EIM_NPUMIX_BASE)
/** Array initializer of NPU_EIM peripheral base addresses */
#define NPU_EIM_BASE_ADDRS                       { NPU__EIM_NPUMIX_BASE }
/** Array initializer of NPU_EIM peripheral base pointers */
#define NPU_EIM_BASE_PTRS                        { NPU__EIM_NPUMIX }

/* NPU_LSTCU - Peripheral instance base addresses */
/** Peripheral NPU__LSTCU_NPUMIX base address */
#define NPU__LSTCU_NPUMIX_BASE                   (0x4A850000u)
/** Peripheral NPU__LSTCU_NPUMIX base pointer */
#define NPU__LSTCU_NPUMIX                        ((NPU_LSTCU_Type *)NPU__LSTCU_NPUMIX_BASE)
/** Array initializer of NPU_LSTCU peripheral base addresses */
#define NPU_LSTCU_BASE_ADDRS                     { NPU__LSTCU_NPUMIX_BASE }
/** Array initializer of NPU_LSTCU peripheral base pointers */
#define NPU_LSTCU_BASE_PTRS                      { NPU__LSTCU_NPUMIX }

/* NPU_TCU - Peripheral instance base addresses */
/** Peripheral NPU__TCU base address */
#define NPU__TCU_BASE                            (0x4A800000u)
/** Peripheral NPU__TCU base pointer */
#define NPU__TCU                                 ((NPU_TCU_Type *)NPU__TCU_BASE)
/** Array initializer of NPU_TCU peripheral base addresses */
#define NPU_TCU_BASE_ADDRS                       { NPU__TCU_BASE }
/** Array initializer of NPU_TCU peripheral base pointers */
#define NPU_TCU_BASE_PTRS                        { NPU__TCU }

/* PCIE_DMA_IATU - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE1__PCIE_DMA_IATU base address */
#define HSIO__PCIE1__PCIE_DMA_IATU_BASE          (0x4C360000u)
/** Peripheral HSIO__PCIE1__PCIE_DMA_IATU base pointer */
#define HSIO__PCIE1__PCIE_DMA_IATU               ((PCIE_DMA_IATU_Type *)HSIO__PCIE1__PCIE_DMA_IATU_BASE)
/** Peripheral HSIO__PCIE2__PCIE_DMA_IATU base address */
#define HSIO__PCIE2__PCIE_DMA_IATU_BASE          (0x4C3E0000u)
/** Peripheral HSIO__PCIE2__PCIE_DMA_IATU base pointer */
#define HSIO__PCIE2__PCIE_DMA_IATU               ((PCIE_DMA_IATU_Type *)HSIO__PCIE2__PCIE_DMA_IATU_BASE)
/** Array initializer of PCIE_DMA_IATU peripheral base addresses */
#define PCIE_DMA_IATU_BASE_ADDRS                 { HSIO__PCIE1__PCIE_DMA_IATU_BASE, HSIO__PCIE2__PCIE_DMA_IATU_BASE }
/** Array initializer of PCIE_DMA_IATU peripheral base pointers */
#define PCIE_DMA_IATU_BASE_PTRS                  { HSIO__PCIE1__PCIE_DMA_IATU, HSIO__PCIE2__PCIE_DMA_IATU }

/* PCIE_EP - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE1__PCIE_EP base address */
#define HSIO__PCIE1__PCIE_EP_BASE                (0x4C300000u)
/** Peripheral HSIO__PCIE1__PCIE_EP base pointer */
#define HSIO__PCIE1__PCIE_EP                     ((PCIE_EP_Type *)HSIO__PCIE1__PCIE_EP_BASE)
/** Peripheral HSIO__PCIE2__PCIE_EP base address */
#define HSIO__PCIE2__PCIE_EP_BASE                (0x4C380000u)
/** Peripheral HSIO__PCIE2__PCIE_EP base pointer */
#define HSIO__PCIE2__PCIE_EP                     ((PCIE_EP_Type *)HSIO__PCIE2__PCIE_EP_BASE)
/** Array initializer of PCIE_EP peripheral base addresses */
#define PCIE_EP_BASE_ADDRS                       { HSIO__PCIE1__PCIE_EP_BASE, HSIO__PCIE2__PCIE_EP_BASE }
/** Array initializer of PCIE_EP peripheral base pointers */
#define PCIE_EP_BASE_PTRS                        { HSIO__PCIE1__PCIE_EP, HSIO__PCIE2__PCIE_EP }

/* PCIE_RC - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE1__PCIE_RC base address */
#define HSIO__PCIE1__PCIE_RC_BASE                (0x4C300000u)
/** Peripheral HSIO__PCIE1__PCIE_RC base pointer */
#define HSIO__PCIE1__PCIE_RC                     ((PCIE_RC_Type *)HSIO__PCIE1__PCIE_RC_BASE)
/** Peripheral HSIO__PCIE2__PCIE_RC base address */
#define HSIO__PCIE2__PCIE_RC_BASE                (0x4C380000u)
/** Peripheral HSIO__PCIE2__PCIE_RC base pointer */
#define HSIO__PCIE2__PCIE_RC                     ((PCIE_RC_Type *)HSIO__PCIE2__PCIE_RC_BASE)
/** Array initializer of PCIE_RC peripheral base addresses */
#define PCIE_RC_BASE_ADDRS                       { HSIO__PCIE1__PCIE_RC_BASE, HSIO__PCIE2__PCIE_RC_BASE }
/** Array initializer of PCIE_RC peripheral base pointers */
#define PCIE_RC_BASE_PTRS                        { HSIO__PCIE1__PCIE_RC, HSIO__PCIE2__PCIE_RC }

/* PCIE_SHADOW_EP - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE1__PCIE_SHADOW_EP base address */
#define HSIO__PCIE1__PCIE_SHADOW_EP_BASE         (0x4C320000u)
/** Peripheral HSIO__PCIE1__PCIE_SHADOW_EP base pointer */
#define HSIO__PCIE1__PCIE_SHADOW_EP              ((PCIE_SHADOW_EP_Type *)HSIO__PCIE1__PCIE_SHADOW_EP_BASE)
/** Peripheral HSIO__PCIE2__PCIE_SHADOW_EP base address */
#define HSIO__PCIE2__PCIE_SHADOW_EP_BASE         (0x4C3A0000u)
/** Peripheral HSIO__PCIE2__PCIE_SHADOW_EP base pointer */
#define HSIO__PCIE2__PCIE_SHADOW_EP              ((PCIE_SHADOW_EP_Type *)HSIO__PCIE2__PCIE_SHADOW_EP_BASE)
/** Array initializer of PCIE_SHADOW_EP peripheral base addresses */
#define PCIE_SHADOW_EP_BASE_ADDRS                { HSIO__PCIE1__PCIE_SHADOW_EP_BASE, HSIO__PCIE2__PCIE_SHADOW_EP_BASE }
/** Array initializer of PCIE_SHADOW_EP peripheral base pointers */
#define PCIE_SHADOW_EP_BASE_PTRS                 { HSIO__PCIE1__PCIE_SHADOW_EP, HSIO__PCIE2__PCIE_SHADOW_EP }

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
/** Peripheral SYS_PLL1 base address */
#define SYS_PLL1_BASE                            (0x44481000u)
/** Peripheral SYS_PLL1 base pointer */
#define SYS_PLL1                                 ((PLL_Type *)SYS_PLL1_BASE)
/** Peripheral AUDIO_PLL1 base address */
#define AUDIO_PLL1_BASE                          (0x44481100u)
/** Peripheral AUDIO_PLL1 base pointer */
#define AUDIO_PLL1                               ((PLL_Type *)AUDIO_PLL1_BASE)
/** Peripheral AUDIO_PLL2 base address */
#define AUDIO_PLL2_BASE                          (0x44481200u)
/** Peripheral AUDIO_PLL2 base pointer */
#define AUDIO_PLL2                               ((PLL_Type *)AUDIO_PLL2_BASE)
/** Peripheral ENCODER_PLL base address */
#define ENCODER_PLL_BASE                         (0x44481300u)
/** Peripheral ENCODER_PLL base pointer */
#define ENCODER_PLL                              ((PLL_Type *)ENCODER_PLL_BASE)
/** Peripheral ARM_PLL base address */
#define ARM_PLL_BASE                             (0x44481600u)
/** Peripheral ARM_PLL base pointer */
#define ARM_PLL                                  ((PLL_Type *)ARM_PLL_BASE)
/** Peripheral DRAM_PLL base address */
#define DRAM_PLL_BASE                            (0x44481700u)
/** Peripheral DRAM_PLL base pointer */
#define DRAM_PLL                                 ((PLL_Type *)DRAM_PLL_BASE)
/** Peripheral HSIO_PLL base address */
#define HSIO_PLL_BASE                            (0x44481800u)
/** Peripheral HSIO_PLL base pointer */
#define HSIO_PLL                                 ((PLL_Type *)HSIO_PLL_BASE)
/** Peripheral LDB_PLL base address */
#define LDB_PLL_BASE                             (0x44481900u)
/** Peripheral LDB_PLL base pointer */
#define LDB_PLL                                  ((PLL_Type *)LDB_PLL_BASE)
/** Array initializer of PLL peripheral base addresses */
#define PLL_BASE_ADDRS                           { SYS_PLL1_BASE, AUDIO_PLL1_BASE, AUDIO_PLL2_BASE, ENCODER_PLL_BASE, ARM_PLL_BASE, DRAM_PLL_BASE, HSIO_PLL_BASE, LDB_PLL_BASE }
/** Array initializer of PLL peripheral base pointers */
#define PLL_BASE_PTRS                            { SYS_PLL1, AUDIO_PLL1, AUDIO_PLL2, ENCODER_PLL, ARM_PLL, DRAM_PLL, HSIO_PLL, LDB_PLL }

/* PWM - Peripheral instance base addresses */
/** Peripheral PWM1 base address */
#define PWM1_BASE                                (0x429A0000u)
/** Peripheral PWM1 base pointer */
#define PWM1                                     ((PWM_Type *)PWM1_BASE)
/** Peripheral PWM2 base address */
#define PWM2_BASE                                (0x429B0000u)
/** Peripheral PWM2 base pointer */
#define PWM2                                     ((PWM_Type *)PWM2_BASE)
/** Peripheral PWM3 base address */
#define PWM3_BASE                                (0x429C0000u)
/** Peripheral PWM3 base pointer */
#define PWM3                                     ((PWM_Type *)PWM3_BASE)
/** Peripheral PWM4 base address */
#define PWM4_BASE                                (0x429D0000u)
/** Peripheral PWM4 base pointer */
#define PWM4                                     ((PWM_Type *)PWM4_BASE)
/** Array initializer of PWM peripheral base addresses */
#define PWM_BASE_ADDRS                           { 0u, PWM1_BASE, PWM2_BASE, PWM3_BASE, PWM4_BASE }
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASE_PTRS                            { (PWM_Type *)0u, PWM1, PWM2, PWM3, PWM4 }

/* PXP - Peripheral instance base addresses */
/** Peripheral PXP base address */
#define PXP_BASE                                 (0x4B110000u)
/** Peripheral PXP base pointer */
#define PXP                                      ((PXP_Type *)PXP_BASE)
/** Array initializer of PXP peripheral base addresses */
#define PXP_BASE_ADDRS                           { PXP_BASE }
/** Array initializer of PXP peripheral base pointers */
#define PXP_BASE_PTRS                            { PXP }

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
#define GPIO4_BASE                               (0x43840000u)
/** Peripheral GPIO4 base pointer */
#define GPIO4                                    ((RGPIO_Type *)GPIO4_BASE)
/** Peripheral GPIO5 base address */
#define GPIO5_BASE                               (0x43850000u)
/** Peripheral GPIO5 base pointer */
#define GPIO5                                    ((RGPIO_Type *)GPIO5_BASE)
/** Peripheral GPIO6 base address */
#define GPIO6_BASE                               (0x43860000u)
/** Peripheral GPIO6 base pointer */
#define GPIO6                                    ((RGPIO_Type *)GPIO6_BASE)
/** Peripheral GPIO7 base address */
#define GPIO7_BASE                               (0x43870000u)
/** Peripheral GPIO7 base pointer */
#define GPIO7                                    ((RGPIO_Type *)GPIO7_BASE)
/** Array initializer of RGPIO peripheral base addresses */
#define RGPIO_BASE_ADDRS                         { 0u, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE, GPIO6_BASE, GPIO7_BASE }
/** Array initializer of RGPIO peripheral base pointers */
#define RGPIO_BASE_PTRS                          { (RGPIO_Type *)0u, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5, GPIO6, GPIO7 }

/* S3MU - Peripheral instance base addresses */
/** Peripheral ELE_MU0_MUA base address */
#define ELE_MU0_MUA_BASE                         (0x47520000u)
/** Peripheral ELE_MU0_MUA base pointer */
#define ELE_MU0_MUA                              ((S3MU_Type *)ELE_MU0_MUA_BASE)
/** Peripheral ELE_MU1_MUA base address */
#define ELE_MU1_MUA_BASE                         (0x47530000u)
/** Peripheral ELE_MU1_MUA base pointer */
#define ELE_MU1_MUA                              ((S3MU_Type *)ELE_MU1_MUA_BASE)
/** Peripheral ELE_MU2_MUA base address */
#define ELE_MU2_MUA_BASE                         (0x47540000u)
/** Peripheral ELE_MU2_MUA base pointer */
#define ELE_MU2_MUA                              ((S3MU_Type *)ELE_MU2_MUA_BASE)
/** Peripheral ELE_MU3_MUA base address */
#define ELE_MU3_MUA_BASE                         (0x47550000u)
/** Peripheral ELE_MU3_MUA base pointer */
#define ELE_MU3_MUA                              ((S3MU_Type *)ELE_MU3_MUA_BASE)
/** Peripheral ELE_MU4_MUA base address */
#define ELE_MU4_MUA_BASE                         (0x47560000u)
/** Peripheral ELE_MU4_MUA base pointer */
#define ELE_MU4_MUA                              ((S3MU_Type *)ELE_MU4_MUA_BASE)
/** Peripheral ELE_MU5_MUA base address */
#define ELE_MU5_MUA_BASE                         (0x47570000u)
/** Peripheral ELE_MU5_MUA base pointer */
#define ELE_MU5_MUA                              ((S3MU_Type *)ELE_MU5_MUA_BASE)
/** Peripheral ELE_MU6_MUA base address */
#define ELE_MU6_MUA_BASE                         (0x47580000u)
/** Peripheral ELE_MU6_MUA base pointer */
#define ELE_MU6_MUA                              ((S3MU_Type *)ELE_MU6_MUA_BASE)
/** Peripheral ELE_MU7_MUA base address */
#define ELE_MU7_MUA_BASE                         (0x47590000u)
/** Peripheral ELE_MU7_MUA base pointer */
#define ELE_MU7_MUA                              ((S3MU_Type *)ELE_MU7_MUA_BASE)
/** Peripheral ELE_MU8_MUA base address */
#define ELE_MU8_MUA_BASE                         (0x475A0000u)
/** Peripheral ELE_MU8_MUA base pointer */
#define ELE_MU8_MUA                              ((S3MU_Type *)ELE_MU8_MUA_BASE)
/** Array initializer of S3MU peripheral base addresses */
#define S3MU_BASE_ADDRS                          { ELE_MU0_MUA_BASE, ELE_MU1_MUA_BASE, ELE_MU2_MUA_BASE, ELE_MU3_MUA_BASE, ELE_MU4_MUA_BASE, ELE_MU5_MUA_BASE, ELE_MU6_MUA_BASE, ELE_MU7_MUA_BASE, ELE_MU8_MUA_BASE }
/** Array initializer of S3MU peripheral base pointers */
#define S3MU_BASE_PTRS                           { ELE_MU0_MUA, ELE_MU1_MUA, ELE_MU2_MUA, ELE_MU3_MUA, ELE_MU4_MUA, ELE_MU5_MUA, ELE_MU6_MUA, ELE_MU7_MUA, ELE_MU8_MUA }

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

/* SINC - Peripheral instance base addresses */
/** Peripheral SINC1 base address */
#define SINC1_BASE                               (0x42960000u)
/** Peripheral SINC1 base pointer */
#define SINC1                                    ((SINC_Type *)SINC1_BASE)
/** Peripheral SINC2 base address */
#define SINC2_BASE                               (0x42970000u)
/** Peripheral SINC2 base pointer */
#define SINC2                                    ((SINC_Type *)SINC2_BASE)
/** Peripheral SINC3 base address */
#define SINC3_BASE                               (0x42980000u)
/** Peripheral SINC3 base pointer */
#define SINC3                                    ((SINC_Type *)SINC3_BASE)
/** Peripheral SINC4 base address */
#define SINC4_BASE                               (0x42990000u)
/** Peripheral SINC4 base pointer */
#define SINC4                                    ((SINC_Type *)SINC4_BASE)
/** Array initializer of SINC peripheral base addresses */
#define SINC_BASE_ADDRS                          { 0u, SINC1_BASE, SINC2_BASE, SINC3_BASE, SINC4_BASE }
/** Array initializer of SINC peripheral base pointers */
#define SINC_BASE_PTRS                           { (SINC_Type *)0u, SINC1, SINC2, SINC3, SINC4 }

/* SRC_GEN - Peripheral instance base addresses */
/** Peripheral SRC_GEN base address */
#define SRC_GEN_BASE                             (0x44460000u)
/** Peripheral SRC_GEN base pointer */
#define SRC_GEN                                  ((SRC_GEN_Type *)SRC_GEN_BASE)
/** Array initializer of SRC_GEN peripheral base addresses */
#define SRC_GEN_BASE_ADDRS                       { SRC_GEN_BASE }
/** Array initializer of SRC_GEN peripheral base pointers */
#define SRC_GEN_BASE_PTRS                        { SRC_GEN }

/* SRC_MEM - Peripheral instance base addresses */
/** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE     (0x44460900u)
/** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_AONMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base address */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE (0x44461900u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base address */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE (0x44461D00u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base address */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE (0x44462100u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base address */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE (0x44462500u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base address */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE (0x44462900u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base pointer */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base address */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE (0x44462920u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base pointer */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE     (0x44462D00u)
/** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE (0x44463100u)
/** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE    (0x44463900u)
/** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE      (0x44463500u)
/** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_M7MIX_MEM           ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_M72MIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_M72MIX_MEM_BASE     (0x44461100u)
/** Peripheral CCMSRCGPC__SRC__XSPR_M72MIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_M72MIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_M72MIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE    (0x44464100u)
/** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base address */
#define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE    (0x44464500u)
/** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base pointer */
#define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base address */
#define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE    (0x44464520u)
/** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base pointer */
#define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE     (0x44464900u)
/** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE  (0x44464D00u)
/** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE)
/** Array initializer of SRC_MEM peripheral base addresses */
#define SRC_MEM_BASE_ADDRS                       { CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_M72MIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE }
/** Array initializer of SRC_MEM peripheral base pointers */
#define SRC_MEM_BASE_PTRS                        { CCMSRCGPC__SRC__XSPR_AONMIX_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM, CCMSRCGPC__SRC__XSPR_M7MIX_MEM, CCMSRCGPC__SRC__XSPR_M72MIX_MEM, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM }

/* SRC_XSPR - Peripheral instance base addresses */
/** Peripheral SRC_XSPR_ANAMIX base address */
#define SRC_XSPR_ANAMIX_BASE                     (0x44460400u)
/** Peripheral SRC_XSPR_ANAMIX base pointer */
#define SRC_XSPR_ANAMIX                          ((SRC_XSPR_Type *)SRC_XSPR_ANAMIX_BASE)
/** Peripheral SRC_XSPR_AONMIX base address */
#define SRC_XSPR_AONMIX_BASE                     (0x44460800u)
/** Peripheral SRC_XSPR_AONMIX base pointer */
#define SRC_XSPR_AONMIX                          ((SRC_XSPR_Type *)SRC_XSPR_AONMIX_BASE)
/** Peripheral SRC_XSPR_BBSMMIX base address */
#define SRC_XSPR_BBSMMIX_BASE                    (0x44460C00u)
/** Peripheral SRC_XSPR_BBSMMIX base pointer */
#define SRC_XSPR_BBSMMIX                         ((SRC_XSPR_Type *)SRC_XSPR_BBSMMIX_BASE)
/** Peripheral SRC_XSPR_CCMSRCGPCMIX base address */
#define SRC_XSPR_CCMSRCGPCMIX_BASE               (0x44461400u)
/** Peripheral SRC_XSPR_CCMSRCGPCMIX base pointer */
#define SRC_XSPR_CCMSRCGPCMIX                    ((SRC_XSPR_Type *)SRC_XSPR_CCMSRCGPCMIX_BASE)
/** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base address */
#define SRC_XSPR_CORTEXMIX_CORE0_BASE            (0x44461800u)
/** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base pointer */
#define SRC_XSPR_CORTEXMIX_CORE0                 ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE0_BASE)
/** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base address */
#define SRC_XSPR_CORTEXMIX_CORE1_BASE            (0x44461C00u)
/** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base pointer */
#define SRC_XSPR_CORTEXMIX_CORE1                 ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE1_BASE)
/** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base address */
#define SRC_XSPR_CORTEXMIX_CORE2_BASE            (0x44462000u)
/** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base pointer */
#define SRC_XSPR_CORTEXMIX_CORE2                 ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE2_BASE)
/** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base address */
#define SRC_XSPR_CORTEXMIX_CORE3_BASE            (0x44462400u)
/** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base pointer */
#define SRC_XSPR_CORTEXMIX_CORE3                 ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE3_BASE)
/** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base address */
#define SRC_XSPR_CORTEXMIX_PLATFORM_BASE         (0x44462800u)
/** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base pointer */
#define SRC_XSPR_CORTEXMIX_PLATFORM              ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_PLATFORM_BASE)
/** Peripheral SRC_XSPR_DDRMIX base address */
#define SRC_XSPR_DDRMIX_BASE                     (0x44462C00u)
/** Peripheral SRC_XSPR_DDRMIX base pointer */
#define SRC_XSPR_DDRMIX                          ((SRC_XSPR_Type *)SRC_XSPR_DDRMIX_BASE)
/** Peripheral SRC_XSPR_DISPLAYMIX base address */
#define SRC_XSPR_DISPLAYMIX_BASE                 (0x44463000u)
/** Peripheral SRC_XSPR_DISPLAYMIX base pointer */
#define SRC_XSPR_DISPLAYMIX                      ((SRC_XSPR_Type *)SRC_XSPR_DISPLAYMIX_BASE)
/** Peripheral SRC_XSPR_HSIOMIX_TOP base address */
#define SRC_XSPR_HSIOMIX_TOP_BASE                (0x44463800u)
/** Peripheral SRC_XSPR_HSIOMIX_TOP base pointer */
#define SRC_XSPR_HSIOMIX_TOP                     ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_TOP_BASE)
/** Peripheral SRC_XSPR_HSIOMIX_WAON base address */
#define SRC_XSPR_HSIOMIX_WAON_BASE               (0x44463C00u)
/** Peripheral SRC_XSPR_HSIOMIX_WAON base pointer */
#define SRC_XSPR_HSIOMIX_WAON                    ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_WAON_BASE)
/** Peripheral SRC_XSPR_M70MIX base address */
#define SRC_XSPR_M70MIX_BASE                     (0x44463400u)
/** Peripheral SRC_XSPR_M70MIX base pointer */
#define SRC_XSPR_M70MIX                          ((SRC_XSPR_Type *)SRC_XSPR_M70MIX_BASE)
/** Peripheral SRC_XSPR_M71MIX base address */
#define SRC_XSPR_M71MIX_BASE                     (0x44461000u)
/** Peripheral SRC_XSPR_M71MIX base pointer */
#define SRC_XSPR_M71MIX                          ((SRC_XSPR_Type *)SRC_XSPR_M71MIX_BASE)
/** Peripheral SRC_XSPR_NETCMIX base address */
#define SRC_XSPR_NETCMIX_BASE                    (0x44464000u)
/** Peripheral SRC_XSPR_NETCMIX base pointer */
#define SRC_XSPR_NETCMIX                         ((SRC_XSPR_Type *)SRC_XSPR_NETCMIX_BASE)
/** Peripheral SRC_XSPR_NOCMIX base address */
#define SRC_XSPR_NOCMIX_BASE                     (0x44464400u)
/** Peripheral SRC_XSPR_NOCMIX base pointer */
#define SRC_XSPR_NOCMIX                          ((SRC_XSPR_Type *)SRC_XSPR_NOCMIX_BASE)
/** Peripheral SRC_XSPR_NPUMIX base address */
#define SRC_XSPR_NPUMIX_BASE                     (0x44464800u)
/** Peripheral SRC_XSPR_NPUMIX base pointer */
#define SRC_XSPR_NPUMIX                          ((SRC_XSPR_Type *)SRC_XSPR_NPUMIX_BASE)
/** Peripheral SRC_XSPR_WAKEUPMIX base address */
#define SRC_XSPR_WAKEUPMIX_BASE                  (0x44464C00u)
/** Peripheral SRC_XSPR_WAKEUPMIX base pointer */
#define SRC_XSPR_WAKEUPMIX                       ((SRC_XSPR_Type *)SRC_XSPR_WAKEUPMIX_BASE)
/** Array initializer of SRC_XSPR peripheral base addresses */
#define SRC_XSPR_BASE_ADDRS                      { SRC_XSPR_ANAMIX_BASE, SRC_XSPR_AONMIX_BASE, SRC_XSPR_BBSMMIX_BASE, SRC_XSPR_CCMSRCGPCMIX_BASE, SRC_XSPR_CORTEXMIX_CORE0_BASE, SRC_XSPR_CORTEXMIX_CORE1_BASE, SRC_XSPR_CORTEXMIX_CORE2_BASE, SRC_XSPR_CORTEXMIX_CORE3_BASE, SRC_XSPR_CORTEXMIX_PLATFORM_BASE, SRC_XSPR_DDRMIX_BASE, SRC_XSPR_DISPLAYMIX_BASE, SRC_XSPR_HSIOMIX_TOP_BASE, SRC_XSPR_HSIOMIX_WAON_BASE, SRC_XSPR_M70MIX_BASE, SRC_XSPR_M71MIX_BASE, SRC_XSPR_NETCMIX_BASE, SRC_XSPR_NOCMIX_BASE, SRC_XSPR_NPUMIX_BASE, SRC_XSPR_WAKEUPMIX_BASE }
/** Array initializer of SRC_XSPR peripheral base pointers */
#define SRC_XSPR_BASE_PTRS                       { SRC_XSPR_ANAMIX, SRC_XSPR_AONMIX, SRC_XSPR_BBSMMIX, SRC_XSPR_CCMSRCGPCMIX, SRC_XSPR_CORTEXMIX_CORE0, SRC_XSPR_CORTEXMIX_CORE1, SRC_XSPR_CORTEXMIX_CORE2, SRC_XSPR_CORTEXMIX_CORE3, SRC_XSPR_CORTEXMIX_PLATFORM, SRC_XSPR_DDRMIX, SRC_XSPR_DISPLAYMIX, SRC_XSPR_HSIOMIX_TOP, SRC_XSPR_HSIOMIX_WAON, SRC_XSPR_M70MIX, SRC_XSPR_M71MIX, SRC_XSPR_NETCMIX, SRC_XSPR_NOCMIX, SRC_XSPR_NPUMIX, SRC_XSPR_WAKEUPMIX }

/* SW_GLOBAL - Peripheral instance base addresses */
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE (0x4CC70000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL  ((SW_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE)
/** Array initializer of SW_GLOBAL peripheral base addresses */
#define SW_GLOBAL_BASE_ADDRS                     { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE }
/** Array initializer of SW_GLOBAL peripheral base pointers */
#define SW_GLOBAL_BASE_PTRS                      { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL }

/* SW_PORT - Peripheral instance base addresses */
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3 base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE (0x4CC10000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3 base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3   ((SW_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE)
/** Array initializer of SW_PORT peripheral base addresses */
#define SW_PORT_BASE_ADDRS                       { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE }
/** Array initializer of SW_PORT peripheral base pointers */
#define SW_PORT_BASE_PTRS                        { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3 }

/* SW_PSEUDO_MAC_PORT - Peripheral instance base addresses */
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE (0x4CC11000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 ((SW_PSEUDO_MAC_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE)
/** Array initializer of SW_PSEUDO_MAC_PORT peripheral base addresses */
#define SW_PSEUDO_MAC_PORT_BASE_ADDRS            { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE }
/** Array initializer of SW_PSEUDO_MAC_PORT peripheral base pointers */
#define SW_PSEUDO_MAC_PORT_BASE_PTRS             { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 }

/* SYS_CTR_COMPARE - Peripheral instance base addresses */
/** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base address */
#define AON__SYS_CTR1__SYS_CTR_COMPARE_BASE      (0x442A0000u)
/** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base pointer */
#define AON__SYS_CTR1__SYS_CTR_COMPARE           ((SYS_CTR_COMPARE_Type *)AON__SYS_CTR1__SYS_CTR_COMPARE_BASE)
/** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
#define SYS_CTR_COMPARE_BASE_ADDRS               { AON__SYS_CTR1__SYS_CTR_COMPARE_BASE }
/** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
#define SYS_CTR_COMPARE_BASE_PTRS                { AON__SYS_CTR1__SYS_CTR_COMPARE }

/* SYS_CTR_CONTROL - Peripheral instance base addresses */
/** Peripheral AON__SYS_CTR1__SYS_CTR_CONTROL base address */
#define AON__SYS_CTR1__SYS_CTR_CONTROL_BASE      (0x44290000u)
/** Peripheral AON__SYS_CTR1__SYS_CTR_CONTROL base pointer */
#define AON__SYS_CTR1__SYS_CTR_CONTROL           ((SYS_CTR_CONTROL_Type *)AON__SYS_CTR1__SYS_CTR_CONTROL_BASE)
/** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
#define SYS_CTR_CONTROL_BASE_ADDRS               { AON__SYS_CTR1__SYS_CTR_CONTROL_BASE }
/** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
#define SYS_CTR_CONTROL_BASE_PTRS                { AON__SYS_CTR1__SYS_CTR_CONTROL }

/* SYS_CTR_READ - Peripheral instance base addresses */
/** Peripheral AON__SYS_CTR1__SYS_CTR_READ base address */
#define AON__SYS_CTR1__SYS_CTR_READ_BASE         (0x442B0000u)
/** Peripheral AON__SYS_CTR1__SYS_CTR_READ base pointer */
#define AON__SYS_CTR1__SYS_CTR_READ              ((SYS_CTR_READ_Type *)AON__SYS_CTR1__SYS_CTR_READ_BASE)
/** Array initializer of SYS_CTR_READ peripheral base addresses */
#define SYS_CTR_READ_BASE_ADDRS                  { AON__SYS_CTR1__SYS_CTR_READ_BASE }
/** Array initializer of SYS_CTR_READ peripheral base pointers */
#define SYS_CTR_READ_BASE_PTRS                   { AON__SYS_CTR1__SYS_CTR_READ }

/* SerDes_SS - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE1__SERDES_SS base address */
#define HSIO__PCIE1__SERDES_SS_BASE              (0x4C340000u)
/** Peripheral HSIO__PCIE1__SERDES_SS base pointer */
#define HSIO__PCIE1__SERDES_SS                   ((SerDes_SS_Type *)HSIO__PCIE1__SERDES_SS_BASE)
/** Peripheral HSIO__PCIE2__SERDES_SS base address */
#define HSIO__PCIE2__SERDES_SS_BASE              (0x4C3C0000u)
/** Peripheral HSIO__PCIE2__SERDES_SS base pointer */
#define HSIO__PCIE2__SERDES_SS                   ((SerDes_SS_Type *)HSIO__PCIE2__SERDES_SS_BASE)
/** Array initializer of SerDes_SS peripheral base addresses */
#define SerDes_SS_BASE_ADDRS                     { HSIO__PCIE1__SERDES_SS_BASE, HSIO__PCIE2__SERDES_SS_BASE }
/** Array initializer of SerDes_SS peripheral base pointers */
#define SerDes_SS_BASE_PTRS                      { HSIO__PCIE1__SERDES_SS, HSIO__PCIE2__SERDES_SS }

/* TCM_ECC_MCM - Peripheral instance base addresses */
/** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base address */
#define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE (0x44420000u)
/** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base pointer */
#define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM   ((TCM_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE)
/** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base address */
#define NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE (0x4D0A0000u)
/** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base pointer */
#define NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM  ((TCM_ECC_MCM_Type *)NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE)
/** Array initializer of TCM_ECC_MCM peripheral base addresses */
#define TCM_ECC_MCM_BASE_ADDRS                   { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE, NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE }
/** Array initializer of TCM_ECC_MCM peripheral base pointers */
#define TCM_ECC_MCM_BASE_PTRS                    { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM, NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM }

/* TMPSNS - Peripheral instance base addresses */
/** Peripheral CORTEXA__TMPSNS base address */
#define CORTEXA__TMPSNS_BASE                     (0x4A440000u)
/** Peripheral CORTEXA__TMPSNS base pointer */
#define CORTEXA__TMPSNS                          ((TMPSNS_Type *)CORTEXA__TMPSNS_BASE)
/** Peripheral TMPSNS base address */
#define TMPSNS_BASE                              (0x44482000u)
/** Peripheral TMPSNS base pointer */
#define TMPSNS                                   ((TMPSNS_Type *)TMPSNS_BASE)
/** Array initializer of TMPSNS peripheral base addresses */
#define TMPSNS_BASE_ADDRS                        { CORTEXA__TMPSNS_BASE, TMPSNS_BASE }
/** Array initializer of TMPSNS peripheral base pointers */
#define TMPSNS_BASE_PTRS                         { CORTEXA__TMPSNS, TMPSNS }

/* TMR - Peripheral instance base addresses */
/** Peripheral TMR1 base address */
#define TMR1_BASE                                (0x428D0000u)
/** Peripheral TMR1 base pointer */
#define TMR1                                     ((TMR_Type *)TMR1_BASE)
/** Peripheral TMR2 base address */
#define TMR2_BASE                                (0x428E0000u)
/** Peripheral TMR2 base pointer */
#define TMR2                                     ((TMR_Type *)TMR2_BASE)
/** Peripheral TMR3 base address */
#define TMR3_BASE                                (0x428F0000u)
/** Peripheral TMR3 base pointer */
#define TMR3                                     ((TMR_Type *)TMR3_BASE)
/** Peripheral TMR4 base address */
#define TMR4_BASE                                (0x42900000u)
/** Peripheral TMR4 base pointer */
#define TMR4                                     ((TMR_Type *)TMR4_BASE)
/** Peripheral TMR5 base address */
#define TMR5_BASE                                (0x42910000u)
/** Peripheral TMR5 base pointer */
#define TMR5                                     ((TMR_Type *)TMR5_BASE)
/** Peripheral TMR6 base address */
#define TMR6_BASE                                (0x42920000u)
/** Peripheral TMR6 base pointer */
#define TMR6                                     ((TMR_Type *)TMR6_BASE)
/** Peripheral TMR7 base address */
#define TMR7_BASE                                (0x42930000u)
/** Peripheral TMR7 base pointer */
#define TMR7                                     ((TMR_Type *)TMR7_BASE)
/** Peripheral TMR8 base address */
#define TMR8_BASE                                (0x42940000u)
/** Peripheral TMR8 base pointer */
#define TMR8                                     ((TMR_Type *)TMR8_BASE)
/** Array initializer of TMR peripheral base addresses */
#define TMR_BASE_ADDRS                           { TMR1_BASE, TMR2_BASE, TMR3_BASE, TMR4_BASE, TMR5_BASE, TMR6_BASE, TMR7_BASE, TMR8_BASE }
/** Array initializer of TMR peripheral base pointers */
#define TMR_BASE_PTRS                            { TMR1, TMR2, TMR3, TMR4, TMR5, TMR6, TMR7, TMR8 }

/* TMR_GLOBAL - Peripheral instance base addresses */
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL_BASE (0x4CDB0000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL ((TMR_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL_BASE)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL_BASE (0x4CDD0000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL ((TMR_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL_BASE)
/** Array initializer of TMR_GLOBAL peripheral base addresses */
#define TMR_GLOBAL_BASE_ADDRS                    { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL_BASE }
/** Array initializer of TMR_GLOBAL peripheral base pointers */
#define TMR_GLOBAL_BASE_PTRS                     { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL }

/* TMR_PCI_HDR_TYPE0 - Peripheral instance base addresses */
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0 base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0_BASE (0x4CB01000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0 base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0 ((TMR_PCI_HDR_TYPE0_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0_BASE)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0 base address */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0_BASE (0x4CB81000u)
/** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0 base pointer */
#define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0 ((TMR_PCI_HDR_TYPE0_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0_BASE)
/** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base addresses */
#define TMR_PCI_HDR_TYPE0_BASE_ADDRS             { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0_BASE }
/** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base pointers */
#define TMR_PCI_HDR_TYPE0_BASE_PTRS              { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0 }

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
#define TPM_BASE_ADDRS                           { TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE }
/** Array initializer of TPM peripheral base pointers */
#define TPM_BASE_PTRS                            { TPM1, TPM2, TPM3, TPM4, TPM5, TPM6 }
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { TPM1_IRQn, TPM2_IRQn, TPM3_IRQn, TPM4_IRQn, TPM5_IRQn, TPM6_IRQn }

/* TRDC_MGR_WKUP1 - Peripheral instance base addresses */
/** Peripheral WAKEUP__TRDC_MGR_WKUP1 base address */
#define WAKEUP__TRDC_MGR_WKUP1_BASE              (0x42460000u)
/** Peripheral WAKEUP__TRDC_MGR_WKUP1 base pointer */
#define WAKEUP__TRDC_MGR_WKUP1                   ((TRDC_MGR_WKUP1_Type *)WAKEUP__TRDC_MGR_WKUP1_BASE)
/** Array initializer of TRDC_MGR_WKUP1 peripheral base addresses */
#define TRDC_MGR_WKUP1_BASE_ADDRS                { WAKEUP__TRDC_MGR_WKUP1_BASE }
/** Array initializer of TRDC_MGR_WKUP1 peripheral base pointers */
#define TRDC_MGR_WKUP1_BASE_PTRS                 { WAKEUP__TRDC_MGR_WKUP1 }

/* TRDC_MGR_WKUP2 - Peripheral instance base addresses */
/** Peripheral WAKEUP__TRDC_MGR_WKUP2 base address */
#define WAKEUP__TRDC_MGR_WKUP2_BASE              (0x42800000u)
/** Peripheral WAKEUP__TRDC_MGR_WKUP2 base pointer */
#define WAKEUP__TRDC_MGR_WKUP2                   ((TRDC_MGR_WKUP2_Type *)WAKEUP__TRDC_MGR_WKUP2_BASE)
/** Array initializer of TRDC_MGR_WKUP2 peripheral base addresses */
#define TRDC_MGR_WKUP2_BASE_ADDRS                { WAKEUP__TRDC_MGR_WKUP2_BASE }
/** Array initializer of TRDC_MGR_WKUP2 peripheral base pointers */
#define TRDC_MGR_WKUP2_BASE_PTRS                 { WAKEUP__TRDC_MGR_WKUP2 }

/* TSTMR - Peripheral instance base addresses */
/** Peripheral TSTMR1_A base address */
#define TSTMR1_A_BASE                            (0x442C0000u)
/** Peripheral TSTMR1_A base pointer */
#define TSTMR1_A                                 ((TSTMR_Type *)TSTMR1_A_BASE)
/** Peripheral TSTMR2_A base address */
#define TSTMR2_A_BASE                            (0x42480000u)
/** Peripheral TSTMR2_A base pointer */
#define TSTMR2_A                                 ((TSTMR_Type *)TSTMR2_A_BASE)
/** Array initializer of TSTMR peripheral base addresses */
#define TSTMR_BASE_ADDRS                         { TSTMR1_A_BASE, TSTMR2_A_BASE }
/** Array initializer of TSTMR peripheral base pointers */
#define TSTMR_BASE_PTRS                          { TSTMR1_A, TSTMR2_A }

/* USB - Peripheral instance base addresses */
/** Peripheral HSIO__USB_2_0__USB_OTG1 base address */
#define HSIO__USB_2_0__USB_OTG1_BASE             (0x4C200000u)
/** Peripheral HSIO__USB_2_0__USB_OTG1 base pointer */
#define HSIO__USB_2_0__USB_OTG1                  ((USB_Type *)HSIO__USB_2_0__USB_OTG1_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { HSIO__USB_2_0__USB_OTG1_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { HSIO__USB_2_0__USB_OTG1 }

/* USB3_GLUE - Peripheral instance base addresses */
/** Peripheral HSIO__USB_3_01__GLUE base address */
#define HSIO__USB_3_01__GLUE_BASE                (0x4C1F0000u)
/** Peripheral HSIO__USB_3_01__GLUE base pointer */
#define HSIO__USB_3_01__GLUE                     ((USB3_GLUE_Type *)HSIO__USB_3_01__GLUE_BASE)
/** Array initializer of USB3_GLUE peripheral base addresses */
#define USB3_GLUE_BASE_ADDRS                     { HSIO__USB_3_01__GLUE_BASE }
/** Array initializer of USB3_GLUE peripheral base pointers */
#define USB3_GLUE_BASE_PTRS                      { HSIO__USB_3_01__GLUE }

/* USB3_PHY_TCA - Peripheral instance base addresses */
/** Peripheral HSIO__USB_3_0_PHY__TCA base address */
#define HSIO__USB_3_0_PHY__TCA_BASE              (0x4C1FC000u)
/** Peripheral HSIO__USB_3_0_PHY__TCA base pointer */
#define HSIO__USB_3_0_PHY__TCA                   ((USB3_PHY_TCA_Type *)HSIO__USB_3_0_PHY__TCA_BASE)
/** Array initializer of USB3_PHY_TCA peripheral base addresses */
#define USB3_PHY_TCA_BASE_ADDRS                  { HSIO__USB_3_0_PHY__TCA_BASE }
/** Array initializer of USB3_PHY_TCA peripheral base pointers */
#define USB3_PHY_TCA_BASE_PTRS                   { HSIO__USB_3_0_PHY__TCA }

/* USBNC - Peripheral instance base addresses */
/** Peripheral HSIO__USB_2_0__USBNC_OTG1 base address */
#define HSIO__USB_2_0__USBNC_OTG1_BASE           (0x4C200200u)
/** Peripheral HSIO__USB_2_0__USBNC_OTG1 base pointer */
#define HSIO__USB_2_0__USBNC_OTG1                ((USBNC_Type *)HSIO__USB_2_0__USBNC_OTG1_BASE)
/** Array initializer of USBNC peripheral base addresses */
#define USBNC_BASE_ADDRS                         { HSIO__USB_2_0__USBNC_OTG1_BASE }
/** Array initializer of USBNC peripheral base pointers */
#define USBNC_BASE_PTRS                          { HSIO__USB_2_0__USBNC_OTG1 }

/* WAKEUP_ATU - Peripheral instance base addresses */
/** Peripheral WAKEUP__ATUA base address */
#define WAKEUP__ATUA_BASE                        (0x42760000u)
/** Peripheral WAKEUP__ATUA base pointer */
#define WAKEUP__ATUA                             ((WAKEUP_ATU_Type *)WAKEUP__ATUA_BASE)
/** Peripheral WAKEUP__ATUM base address */
#define WAKEUP__ATUM_BASE                        (0x42770000u)
/** Peripheral WAKEUP__ATUM base pointer */
#define WAKEUP__ATUM                             ((WAKEUP_ATU_Type *)WAKEUP__ATUM_BASE)
/** Peripheral WAKEUP__ATUM33 base address */
#define WAKEUP__ATUM33_BASE                      (0x427D0000u)
/** Peripheral WAKEUP__ATUM33 base pointer */
#define WAKEUP__ATUM33                           ((WAKEUP_ATU_Type *)WAKEUP__ATUM33_BASE)
/** Peripheral WAKEUP__ATU_M70 base address */
#define WAKEUP__ATU_M70_BASE                     (0x42A90000u)
/** Peripheral WAKEUP__ATU_M70 base pointer */
#define WAKEUP__ATU_M70                          ((WAKEUP_ATU_Type *)WAKEUP__ATU_M70_BASE)
/** Peripheral WAKEUP__ATU_M71 base address */
#define WAKEUP__ATU_M71_BASE                     (0x42AA0000u)
/** Peripheral WAKEUP__ATU_M71 base pointer */
#define WAKEUP__ATU_M71                          ((WAKEUP_ATU_Type *)WAKEUP__ATU_M71_BASE)
/** Peripheral WAKEUP__AUDIO_XCVR base address */
#define WAKEUP__AUDIO_XCVR_BASE                  (0x42680000u)
/** Peripheral WAKEUP__AUDIO_XCVR base pointer */
#define WAKEUP__AUDIO_XCVR                       ((WAKEUP_ATU_Type *)WAKEUP__AUDIO_XCVR_BASE)
/** Array initializer of WAKEUP_ATU peripheral base addresses */
#define WAKEUP_ATU_BASE_ADDRS                    { WAKEUP__ATUA_BASE, WAKEUP__ATUM_BASE, WAKEUP__ATUM33_BASE, WAKEUP__ATU_M70_BASE, WAKEUP__ATU_M71_BASE, WAKEUP__AUDIO_XCVR_BASE }
/** Array initializer of WAKEUP_ATU peripheral base pointers */
#define WAKEUP_ATU_BASE_PTRS                     { WAKEUP__ATUA, WAKEUP__ATUM, WAKEUP__ATUM33, WAKEUP__ATU_M70, WAKEUP__ATU_M71, WAKEUP__AUDIO_XCVR }

/* WAKEUP_CMU - Peripheral instance base addresses */
/** Peripheral WAKEUP__CMU1 base address */
#define WAKEUP__CMU1_BASE                        (0x42750000u)
/** Peripheral WAKEUP__CMU1 base pointer */
#define WAKEUP__CMU1                             ((WAKEUP_CMU_Type *)WAKEUP__CMU1_BASE)
/** Peripheral WAKEUP__CMU2 base address */
#define WAKEUP__CMU2_BASE                        (0x427A0000u)
/** Peripheral WAKEUP__CMU2 base pointer */
#define WAKEUP__CMU2                             ((WAKEUP_CMU_Type *)WAKEUP__CMU2_BASE)
/** Array initializer of WAKEUP_CMU peripheral base addresses */
#define WAKEUP_CMU_BASE_ADDRS                    { WAKEUP__CMU1_BASE, WAKEUP__CMU2_BASE }
/** Array initializer of WAKEUP_CMU peripheral base pointers */
#define WAKEUP_CMU_BASE_PTRS                     { WAKEUP__CMU1, WAKEUP__CMU2 }

/* WAKEUP_DMA_CRC - Peripheral instance base addresses */
/** Peripheral WAKEUP__DMA_CRC2 base address */
#define WAKEUP__DMA_CRC2_BASE                    (0x427B0000u)
/** Peripheral WAKEUP__DMA_CRC2 base pointer */
#define WAKEUP__DMA_CRC2                         ((WAKEUP_DMA_CRC_Type *)WAKEUP__DMA_CRC2_BASE)
/** Peripheral WAKEUP__DMA_CRC4 base address */
#define WAKEUP__DMA_CRC4_BASE                    (0x427C0000u)
/** Peripheral WAKEUP__DMA_CRC4 base pointer */
#define WAKEUP__DMA_CRC4                         ((WAKEUP_DMA_CRC_Type *)WAKEUP__DMA_CRC4_BASE)
/** Array initializer of WAKEUP_DMA_CRC peripheral base addresses */
#define WAKEUP_DMA_CRC_BASE_ADDRS                { WAKEUP__DMA_CRC2_BASE, WAKEUP__DMA_CRC4_BASE }
/** Array initializer of WAKEUP_DMA_CRC peripheral base pointers */
#define WAKEUP_DMA_CRC_BASE_PTRS                 { WAKEUP__DMA_CRC2, WAKEUP__DMA_CRC4 }

/* WAKEUP_EIM - Peripheral instance base addresses */
/** Peripheral WAKEUP__EIM base address */
#define WAKEUP__EIM_BASE                         (0x42780000u)
/** Peripheral WAKEUP__EIM base pointer */
#define WAKEUP__EIM                              ((WAKEUP_EIM_Type *)WAKEUP__EIM_BASE)
/** Array initializer of WAKEUP_EIM peripheral base addresses */
#define WAKEUP_EIM_BASE_ADDRS                    { WAKEUP__EIM_BASE }
/** Array initializer of WAKEUP_EIM peripheral base pointers */
#define WAKEUP_EIM_BASE_PTRS                     { WAKEUP__EIM }

/* WAKEUP_ERM - Peripheral instance base addresses */
/** Peripheral WAKEUP__ERM base address */
#define WAKEUP__ERM_BASE                         (0x42790000u)
/** Peripheral WAKEUP__ERM base pointer */
#define WAKEUP__ERM                              ((WAKEUP_ERM_Type *)WAKEUP__ERM_BASE)
/** Array initializer of WAKEUP_ERM peripheral base addresses */
#define WAKEUP_ERM_BASE_ADDRS                    { WAKEUP__ERM_BASE }
/** Array initializer of WAKEUP_ERM peripheral base pointers */
#define WAKEUP_ERM_BASE_PTRS                     { WAKEUP__ERM }

/* WAKEUP_GPT - Peripheral instance base addresses */
/** Peripheral GPT2 base address */
#define GPT2_BASE                                (0x428A0000u)
/** Peripheral GPT2 base pointer */
#define GPT2                                     ((WAKEUP_GPT_Type *)GPT2_BASE)
/** Peripheral GPT3 base address */
#define GPT3_BASE                                (0x428B0000u)
/** Peripheral GPT3 base pointer */
#define GPT3                                     ((WAKEUP_GPT_Type *)GPT3_BASE)
/** Peripheral GPT4 base address */
#define GPT4_BASE                                (0x428C0000u)
/** Peripheral GPT4 base pointer */
#define GPT4                                     ((WAKEUP_GPT_Type *)GPT4_BASE)
/** Array initializer of WAKEUP_GPT peripheral base addresses */
#define WAKEUP_GPT_BASE_ADDRS                    { 0u, 0u, GPT2_BASE, GPT3_BASE, GPT4_BASE }
/** Array initializer of WAKEUP_GPT peripheral base pointers */
#define WAKEUP_GPT_BASE_PTRS                     { (WAKEUP_GPT_Type *)0u, (WAKEUP_GPT_Type *)0u, GPT2, GPT3, GPT4 }

/* WAKEUP_ROMCP - Peripheral instance base addresses */
/** Peripheral WAKEUP__ROMCP2 base address */
#define WAKEUP__ROMCP2_BASE                      (0x42640000u)
/** Peripheral WAKEUP__ROMCP2 base pointer */
#define WAKEUP__ROMCP2                           ((WAKEUP_ROMCP_Type *)WAKEUP__ROMCP2_BASE)
/** Array initializer of WAKEUP_ROMCP peripheral base addresses */
#define WAKEUP_ROMCP_BASE_ADDRS                  { WAKEUP__ROMCP2_BASE }
/** Array initializer of WAKEUP_ROMCP peripheral base pointers */
#define WAKEUP_ROMCP_BASE_PTRS                   { WAKEUP__ROMCP2 }

/* WAKEUP_SAI - Peripheral instance base addresses */
/** Peripheral WAKEUP__SAI2 base address */
#define WAKEUP__SAI2_BASE                        (0x42650000u)
/** Peripheral WAKEUP__SAI2 base pointer */
#define WAKEUP__SAI2                             ((WAKEUP_SAI_Type *)WAKEUP__SAI2_BASE)
/** Array initializer of WAKEUP_SAI peripheral base addresses */
#define WAKEUP_SAI_BASE_ADDRS                    { WAKEUP__SAI2_BASE }
/** Array initializer of WAKEUP_SAI peripheral base pointers */
#define WAKEUP_SAI_BASE_PTRS                     { WAKEUP__SAI2 }

/* WAKEUP_TCW - Peripheral instance base addresses */
/** Peripheral WAKEUP__TCW base address */
#define WAKEUP__TCW_BASE                         (0x42620000u)
/** Peripheral WAKEUP__TCW base pointer */
#define WAKEUP__TCW                              ((WAKEUP_TCW_Type *)WAKEUP__TCW_BASE)
/** Array initializer of WAKEUP_TCW peripheral base addresses */
#define WAKEUP_TCW_BASE_ADDRS                    { WAKEUP__TCW_BASE }
/** Array initializer of WAKEUP_TCW peripheral base pointers */
#define WAKEUP_TCW_BASE_PTRS                     { WAKEUP__TCW }

/* WAKEUP_TRDC_MGR_MEGA - Peripheral instance base addresses */
/** Peripheral WAKEUP__TRDC_MGR_MEGA base address */
#define WAKEUP__TRDC_MGR_MEGA_BASE               (0x42810000u)
/** Peripheral WAKEUP__TRDC_MGR_MEGA base pointer */
#define WAKEUP__TRDC_MGR_MEGA                    ((WAKEUP_TRDC_MGR_MEGA_Type *)WAKEUP__TRDC_MGR_MEGA_BASE)
/** Array initializer of WAKEUP_TRDC_MGR_MEGA peripheral base addresses */
#define WAKEUP_TRDC_MGR_MEGA_BASE_ADDRS          { WAKEUP__TRDC_MGR_MEGA_BASE }
/** Array initializer of WAKEUP_TRDC_MGR_MEGA peripheral base pointers */
#define WAKEUP_TRDC_MGR_MEGA_BASE_PTRS           { WAKEUP__TRDC_MGR_MEGA }

/* WAKEUP_USDHC - Peripheral instance base addresses */
/** Peripheral WAKEUP__USDHC1 base address */
#define WAKEUP__USDHC1_BASE                      (0x42850000u)
/** Peripheral WAKEUP__USDHC1 base pointer */
#define WAKEUP__USDHC1                           ((WAKEUP_USDHC_Type *)WAKEUP__USDHC1_BASE)
/** Peripheral WAKEUP__USDHC2 base address */
#define WAKEUP__USDHC2_BASE                      (0x42860000u)
/** Peripheral WAKEUP__USDHC2 base pointer */
#define WAKEUP__USDHC2                           ((WAKEUP_USDHC_Type *)WAKEUP__USDHC2_BASE)
/** Peripheral WAKEUP__USDHC3 base address */
#define WAKEUP__USDHC3_BASE                      (0x42880000u)
/** Peripheral WAKEUP__USDHC3 base pointer */
#define WAKEUP__USDHC3                           ((WAKEUP_USDHC_Type *)WAKEUP__USDHC3_BASE)
/** Array initializer of WAKEUP_USDHC peripheral base addresses */
#define WAKEUP_USDHC_BASE_ADDRS                  { WAKEUP__USDHC1_BASE, WAKEUP__USDHC2_BASE, WAKEUP__USDHC3_BASE }
/** Array initializer of WAKEUP_USDHC peripheral base pointers */
#define WAKEUP_USDHC_BASE_PTRS                   { WAKEUP__USDHC1, WAKEUP__USDHC2, WAKEUP__USDHC3 }

/* WAKEUP_V2X_FH - Peripheral instance base addresses */
/** Peripheral WAKEUP__V2X_FH base address */
#define WAKEUP__V2X_FH_BASE                      (0x47300000u)
/** Peripheral WAKEUP__V2X_FH base pointer */
#define WAKEUP__V2X_FH                           ((WAKEUP_V2X_FH_Type *)WAKEUP__V2X_FH_BASE)
/** Array initializer of WAKEUP_V2X_FH peripheral base addresses */
#define WAKEUP_V2X_FH_BASE_ADDRS                 { WAKEUP__V2X_FH_BASE }
/** Array initializer of WAKEUP_V2X_FH peripheral base pointers */
#define WAKEUP_V2X_FH_BASE_PTRS                  { WAKEUP__V2X_FH }

/* WAKEUP_XSPI_RESPONDER - Peripheral instance base addresses */
/** Peripheral WAKEUP__XSPI_RESPONDER base address */
#define WAKEUP__XSPI_RESPONDER_BASE              (0x42890000u)
/** Peripheral WAKEUP__XSPI_RESPONDER base pointer */
#define WAKEUP__XSPI_RESPONDER                   ((WAKEUP_XSPI_RESPONDER_Type *)WAKEUP__XSPI_RESPONDER_BASE)
/** Array initializer of WAKEUP_XSPI_RESPONDER peripheral base addresses */
#define WAKEUP_XSPI_RESPONDER_BASE_ADDRS         { WAKEUP__XSPI_RESPONDER_BASE }
/** Array initializer of WAKEUP_XSPI_RESPONDER peripheral base pointers */
#define WAKEUP_XSPI_RESPONDER_BASE_PTRS          { WAKEUP__XSPI_RESPONDER }

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
#define WDOG3_BASE                               (0x49220000u)
/** Peripheral WDOG3 base pointer */
#define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
/** Peripheral WDOG4 base address */
#define WDOG4_BASE                               (0x49230000u)
/** Peripheral WDOG4 base pointer */
#define WDOG4                                    ((WDOG_Type *)WDOG4_BASE)
/** Peripheral WDOG5 base address */
#define WDOG5_BASE                               (0x424B0000u)
/** Peripheral WDOG5 base pointer */
#define WDOG5                                    ((WDOG_Type *)WDOG5_BASE)
/** Peripheral WDOG6 base address */
#define WDOG6_BASE                               (0x427E0000u)
/** Peripheral WDOG6 base pointer */
#define WDOG6                                    ((WDOG_Type *)WDOG6_BASE)
/** Peripheral WDOG7 base address */
#define WDOG7_BASE                               (0x4D0E0000u)
/** Peripheral WDOG7 base pointer */
#define WDOG7                                    ((WDOG_Type *)WDOG7_BASE)
/** Peripheral WDOG8 base address */
#define WDOG8_BASE                               (0x4D0F0000u)
/** Peripheral WDOG8 base pointer */
#define WDOG8                                    ((WDOG_Type *)WDOG8_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE, WDOG6_BASE, WDOG7_BASE, WDOG8_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG1, WDOG2, WDOG3, WDOG4, WDOG5, WDOG6, WDOG7, WDOG8 }

/* XBAR1 - Peripheral instance base addresses */
/** Peripheral XBAR1 base address */
#define XBAR1_BASE                               (0x42A20000u)
/** Peripheral XBAR1 base pointer */
#define XBAR1                                    ((XBAR1_Type *)XBAR1_BASE)
/** Array initializer of XBAR1 peripheral base addresses */
#define XBAR1_BASE_ADDRS                         { XBAR1_BASE }
/** Array initializer of XBAR1 peripheral base pointers */
#define XBAR1_BASE_PTRS                          { XBAR1 }

/* XBAR2 - Peripheral instance base addresses */
/** Peripheral XBAR2 base address */
#define XBAR2_BASE                               (0x42A30000u)
/** Peripheral XBAR2 base pointer */
#define XBAR2                                    ((XBAR2_Type *)XBAR2_BASE)
/** Array initializer of XBAR2 peripheral base addresses */
#define XBAR2_BASE_ADDRS                         { XBAR2_BASE }
/** Array initializer of XBAR2 peripheral base pointers */
#define XBAR2_BASE_PTRS                          { XBAR2 }

/* XBAR3 - Peripheral instance base addresses */
/** Peripheral XBAR3 base address */
#define XBAR3_BASE                               (0x42A40000u)
/** Peripheral XBAR3 base pointer */
#define XBAR3                                    ((XBAR3_Type *)XBAR3_BASE)
/** Array initializer of XBAR3 peripheral base addresses */
#define XBAR3_BASE_ADDRS                         { XBAR3_BASE }
/** Array initializer of XBAR3 peripheral base pointers */
#define XBAR3_BASE_PTRS                          { XBAR3 }
/* XBAR related definitions */
typedef enum
{
    kXBAR_DSC1 = 1,
    kXBAR_DSC2 = 2,
    kXBAR_DSC3 = 3
} xbar_instance_t;
#define XBAR_INFO \
    { \
        { \
            (volatile uint32_t *)XBAR1_BASE, 0x0U, 256U, 0x400U, 4U \
        }, \
        { \
            (volatile uint32_t *)XBAR2_BASE, 0x0U, 32U, 0x80U, 1U \
        }, \
        { \
            (volatile uint32_t *)XBAR3_BASE, 0x0U, 32U, 0x80U, 1U \
        } \
    }
#include "fsl_elec_spec.h"
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (1700000000UL)


/* XSPI - Peripheral instance base addresses */
/** Peripheral XSPI1 base address */
#define XSPI1_BASE                               (0x42B90000u)
/** Peripheral XSPI1 base pointer */
#define XSPI1                                    ((XSPI_Type *)XSPI1_BASE)
/** Peripheral XSPI2 base address */
#define XSPI2_BASE                               (0x42BE0000u)
/** Peripheral XSPI2 base pointer */
#define XSPI2                                    ((XSPI_Type *)XSPI2_BASE)
/** Array initializer of XSPI peripheral base addresses */
#define XSPI_BASE_ADDRS                          { 0u, XSPI1_BASE, XSPI2_BASE }
/** Array initializer of XSPI peripheral base pointers */
#define XSPI_BASE_PTRS                           { (XSPI_Type *)0u, XSPI1, XSPI2 }
/** Interrupt vectors for the XSPI peripheral type */
#define XSPI_IRQS                                { NotAvail_IRQn, XSPI1_IRQn, XSPI2_IRQn  }
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /* XSPI AMBA address. */
  #define XSPI1_AMBA_BASE      (0x38000000u)
  #define XSPI2_AMBA_BASE      (0x34000000u)
  #define XSPI1_AMBA_BASE_NS   (0x28000000u)
  #define XSPI2_AMBA_BASE_NS   (0x24000000u)
  #define XSPI_AMBA_BASES      {0x00000000u, 0x38000000u, 0x34000000u}
  #define XSPI_AMBA_BASES_NS   {0x00000000u, 0x28000000u, 0x24000000u}
#else
  /* XSPI AMBA address. */
  #define XSPI1_AMBA_BASE      (0x28000000u)
  #define XSPI2_AMBA_BASE      (0x24000000u)
  #define XSPI_AMBA_BASES      {0x00000000u, 0x28000000u, 0x24000000u}
#endif


/* ieprc_ierb - Peripheral instance base addresses */
/** Peripheral NETC__IEPRC_1__IEPRC_IERB base address */
#define NETC__IEPRC_1__IEPRC_IERB_BASE           (0x4C8A0000u)
/** Peripheral NETC__IEPRC_1__IEPRC_IERB base pointer */
#define NETC__IEPRC_1__IEPRC_IERB                ((ieprc_ierb_Type *)NETC__IEPRC_1__IEPRC_IERB_BASE)
/** Array initializer of ieprc_ierb peripheral base addresses */
#define ieprc_ierb_BASE_ADDRS                    { NETC__IEPRC_1__IEPRC_IERB_BASE }
/** Array initializer of ieprc_ierb peripheral base pointers */
#define ieprc_ierb_BASE_PTRS                     { NETC__IEPRC_1__IEPRC_IERB }

/* ieprc_pci - Peripheral instance base addresses */
/** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base address */
#define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE (0x4CA08000u)
/** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base pointer */
#define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE)
/** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base address */
#define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE (0x4CB08000u)
/** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base pointer */
#define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE)
/** Array initializer of ieprc_pci peripheral base addresses */
#define ieprc_pci_BASE_ADDRS                     { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE }
/** Array initializer of ieprc_pci peripheral base pointers */
#define ieprc_pci_BASE_PTRS                      { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 }

/* ieprc_prb - Peripheral instance base addresses */
/** Peripheral NETC__IEPRC_1__IEPRC_PRB base address */
#define NETC__IEPRC_1__IEPRC_PRB_BASE            (0x4C8B0000u)
/** Peripheral NETC__IEPRC_1__IEPRC_PRB base pointer */
#define NETC__IEPRC_1__IEPRC_PRB                 ((ieprc_prb_Type *)NETC__IEPRC_1__IEPRC_PRB_BASE)
/** Array initializer of ieprc_prb peripheral base addresses */
#define ieprc_prb_BASE_ADDRS                     { NETC__IEPRC_1__IEPRC_PRB_BASE }
/** Array initializer of ieprc_prb peripheral base pointers */
#define ieprc_prb_BASE_PTRS                      { NETC__IEPRC_1__IEPRC_PRB }

/* m_e_3_wr_I_main_TranStatFilt - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
#define NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x49063280u)
/** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
#define NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER ((m_e_3_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of m_e_3_wr_I_main_TranStatFilt peripheral base addresses
 * */
#define m_e_3_wr_I_main_TranStatFilt_BASE_ADDRS  { NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of m_e_3_wr_I_main_TranStatFilt peripheral base pointers */
#define m_e_3_wr_I_main_TranStatFilt_BASE_PTRS   { NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER }

/* m_e_9_rd_I_main_TransactionStatFilter - Peripheral instance base addresses */
/** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
#define NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x49063700u)
/** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
#define NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER ((m_e_9_rd_I_main_TransactionStatFilter_Type *)NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
/** Array initializer of m_e_9_rd_I_main_TransactionStatFilter peripheral base
 * addresses */
#define m_e_9_rd_I_main_TransactionStatFilter_BASE_ADDRS { NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
/** Array initializer of m_e_9_rd_I_main_TransactionStatFilter peripheral base
 * pointers */
#define m_e_9_rd_I_main_TransactionStatFilter_BASE_PTRS { NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER }

/* neutrons - Peripheral instance base addresses */
/** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC base address */
#define NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC_BASE (0x4AC00000u)
/** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC base pointer */
#define NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC     ((neutrons_Type *)NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC_BASE)
/** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV base address */
#define NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV_BASE (0x4AB80000u)
/** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV base pointer */
#define NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV      ((neutrons_Type *)NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV_BASE)
/** Array initializer of neutrons peripheral base addresses */
#define neutrons_BASE_ADDRS                      { NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC_BASE, NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV_BASE }
/** Array initializer of neutrons peripheral base pointers */
#define neutrons_BASE_PTRS                       { NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC, NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV }

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


#endif  /* MIMX94398_CA55_COMMON_H_ */

