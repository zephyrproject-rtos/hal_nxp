/*
** ###################################################################
**     Processors:          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_cm7
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    iMX952RM rev1 draftM
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b251015
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX95294_cm7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file MIMX95294_cm7_COMMON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIMX95294_cm7
 *
 * CMSIS Peripheral Access Layer for MIMX95294_cm7
 */

#if !defined(MIMX95294_CM7_COMMON_H_)
#define MIMX95294_CM7_COMMON_H_                  /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 971                /**< Number of interrupts in the Vector table */

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
  RESERVED16_IRQn              = 0,                /**< Reserved interrupt */
  RESERVED17_IRQn              = 1,                /**< DAP Interrupt */
  RESERVED18_IRQn              = 2,                /**< CTI trigger outputs from CM7 platform  (internal: CTIIRQ[0]) */
  RESERVED19_IRQn              = 3,                /**< CTI trigger outputs from CM33 platform  (internal: CTIIRQ[0]) */
  RESERVED20_IRQn              = 4,                /**< CTI trigger outputs from CA55 platform  (internal: nCTIIRQ[0]) */
  RESERVED21_IRQn              = 5,                /**< Performance Unit Interrupts from CA55 platform (interrnally:  PMUIRQ[0]) */
  RESERVED22_IRQn              = 6,                /**< ECC error with potential data corruption or loss of coherency from CA55 platform L3 Cache */
  RESERVED23_IRQn              = 7,                /**< 1-bit or 2-bit ECC or Parity error from CA55 platform L3 Cache */
  CAN1_IRQn                    = 8,                /**< AONMIX CAN-FD Interrupt from busoff */
  CAN1_ERROR_IRQn              = 9,                /**< AONMIX CAN-FD Correctable error interrupt */
  GPIO1_0_IRQn                 = 10,               /**< AONMIX GPIO interrupt request 0 */
  GPIO1_1_IRQn                 = 11,               /**< AONMIX GPIO interrupt request 1 */
  I3C1_IRQn                    = 12,               /**< AONMIX I3C interrupt request */
  LPI2C1_IRQn                  = 13,               /**< AONMIX LPI2C Master interrupt */
  LPI2C2_IRQn                  = 14,               /**< AONMIX LPI2C Master interrupt */
  LPIT1_IRQn                   = 15,               /**< AONMIX LPIT global interrupt */
  LPSPI1_IRQn                  = 16,               /**< AONMIX LPSPI interrupt */
  LPSPI2_IRQn                  = 17,               /**< AONMIX LPSPI interrupt */
  LPTMR1_IRQn                  = 18,               /**< AONMIX LPTMR async interrupt */
  LPUART1_IRQn                 = 19,               /**< AONMIX LPUART TX interrupt */
  LPUART2_IRQn                 = 20,               /**< AONMIX LPUART TX interrupt */
  RESERVED37_IRQn              = 21,               /**< AONMIX Sentinel MU0 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED38_IRQn              = 22,               /**< AONMIX Sentinel MU1 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED39_IRQn              = 23,               /**< AONMIX Sentinel MU2 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED40_IRQn              = 24,               /**< AONMIX Sentinel MU3 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED41_IRQn              = 25,               /**< AONMIX Sentinel MU4 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED42_IRQn              = 26,               /**< AONMIX Sentinel MU5 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED43_IRQn              = 27,               /**< V2X-FH MU APCH0 (APP0) A_TX interrupt */
  RESERVED44_IRQn              = 28,               /**< V2X-FH MU APHSM1 (HSM1) A_TX interrupt */
  TPM1_IRQn                    = 29,               /**< AONMIX LPTPM global interrupt */
  TPM2_IRQn                    = 30,               /**< AONMIX LPTPM global interrupt */
  WDOG1_IRQn                   = 31,               /**< AONMIX Watchdog interrupt request.  SRC reset source. */
  WDOG2_IRQn                   = 32,               /**< AONMIX Watchdog interrupt request.  SRC reset source. */
  TRDC_MGR_A_IRQn              = 33,               /**< AONMIX TRDC transfer error interrupt */
  SAI1_IRQn                    = 34,               /**< AONMIX SAI TX interrupt */
  RESERVED51_IRQn              = 35,               /**< AONMIX M33 PS Tag Parity Error */
  CM33_ECC_MCM_IRQn            = 36,               /**< AONMIX M33 TCM Error interrupt */
  RESERVED53_IRQn              = 37,               /**< M7MIX ECC Multi-bit error */
  CAN2_IRQn                    = 38,               /**< WAKEUPMIX CAN-FD Interrupt from busoff */
  CAN2_ERROR_IRQn              = 39,               /**< WAKEUPMIX CAN-FD Correctable error interrupt */
  CAN3_IRQn                    = 40,               /**< WAKEUPMIX CAN-FD Interrupt from busoff */
  CAN3_ERROR_IRQn              = 41,               /**< WAKEUPMIX CAN-FD Correctable error interrupt */
  WDOG6_IRQn                   = 42,               /**< DISPLAYMIX Watchdog interrupt request. SRC reset source. */
  RESERVED59_IRQn              = 43,               /**< Additional inverted version of Interrupt added for s500_scm_halt_ack_irq. Which could be uzseful for Sentinel Wakeup */
  RESERVED60_IRQn              = 44,               /**< s500.sentinel_irq_glue_s500_irq_req4 is connected with ocotp_cont_edc_err */
  DISPLAY_MIX_IRQn             = 45,               /**< Local Dimming Interrupt */
  FLEXIO1_IRQn                 = 46,               /**< WAKEUPMIX FLEXIO interrupt */
  FLEXIO2_IRQn                 = 47,               /**< WAKEUPMIX FLEXIO interrupt */
  RESERVED64_IRQn              = 48,               /**< Reserved */
  GPIO2_0_IRQn                 = 49,               /**< WAKEUPMIX GPIO interrupt request 0 */
  GPIO2_1_IRQn                 = 50,               /**< WAKEUPMIX GPIO interrupt request 1 */
  GPIO3_0_IRQn                 = 51,               /**< WAKEUPMIX GPIO interrupt request 0 */
  GPIO3_1_IRQn                 = 52,               /**< WAKEUPMIX GPIO interrupt request 1 */
  GPIO4_0_IRQn                 = 53,               /**< WAKEUPMIX GPIO interrupt request 0 */
  GPIO4_1_IRQn                 = 54,               /**< WAKEUPMIX GPIO interrupt request 1 */
  GPIO5_0_IRQn                 = 55,               /**< WAKEUPMIX GPIO interrupt request 0 */
  GPIO5_1_IRQn                 = 56,               /**< WAKEUPMIX GPIO interrupt request 1 */
  I3C2_IRQn                    = 57,               /**< WAKEUPMIX I3C interrupt request */
  LPI2C3_IRQn                  = 58,               /**< WAKEUPMIX LPI2C Master interrupt */
  LPI2C4_IRQn                  = 59,               /**< WAKEUPMIX LPI2C Master interrupt */
  LPIT2_IRQn                   = 60,               /**< WAKEUPMIX LPIT global interrupt */
  LPSPI3_IRQn                  = 61,               /**< WAKEUPMIX LPSPI interrupt */
  LPSPI4_IRQn                  = 62,               /**< WAKEUPMIX LPSPI interrupt */
  LPTMR2_IRQn                  = 63,               /**< WAKEUPMIX LPTMR async interrupt */
  LPUART3_IRQn                 = 64,               /**< WAKEUPMIX LPUART TX interrupt */
  LPUART4_IRQn                 = 65,               /**< WAKEUPMIX LPUART TX interrupt */
  LPUART5_IRQn                 = 66,               /**< WAKEUPMIX LPUART TX interrupt */
  LPUART6_IRQn                 = 67,               /**< WAKEUPMIX LPUART TX interrupt */
  LPUART7_IRQn                 = 68,               /**< WAKEUPMIX LPUART TX interrupt */
  LPUART8_IRQn                 = 69,               /**< WAKEUPMIX LPUART TX interrupt */
  MTR_MSTR_IRQn                = 70,               /**< AONMIX MTR Master error interrupt */
  BBNSM_IRQn                   = 71,               /**< BBNSM Non-Secure external wakeup alarm */
  SYS_CTR1_IRQn                = 72,               /**< WAKEUPMIX System Counter compare interrupt 0 */
  TPM3_IRQn                    = 73,               /**< WAKEUPMIX LPTPM global interrupt */
  TPM4_IRQn                    = 74,               /**< WAKEUPMIX LPTPM global interrupt */
  TPM5_IRQn                    = 75,               /**< WAKEUPMIX LPTPM async interrupt */
  TPM6_IRQn                    = 76,               /**< WAKEUPMIX LPTPM async interrupt */
  WDOG3_IRQn                   = 77,               /**< WAKEUPMIX Watchdog interrupt request. SRC reset source. */
  WDOG4_IRQn                   = 78,               /**< WAKEUPMIX Watchdog interrupt request. SRC reset source. */
  WDOG5_IRQn                   = 79,               /**< WAKEUPMIX Watchdog interrupt request. SRC reset source. */
  TMPSNS1_THR1_IRQn            = 80,               /**< ANAMIX TempSensor non-secure interrupt from Threshold 1 */
  TMPSNS1_THR2_IRQn            = 81,               /**< ANAMIX TempSensor non-secure interrupt from Threshold 2 */
  TMPSNS1_DRDY_IRQn            = 82,               /**< ANAMIX TempSensor non-secure data ready interrupt */
  TMPSNS2_THR1_IRQn            = 83,               /**< CORTEXAMIX TempSensor non-secure interrupt from Threshold 1 */
  TMPSNS2_THR2_IRQn            = 84,               /**< CORTEXAMIX TempSensor non-secure interrupt from Threshold 2 */
  TMPSNS2_DRDY_IRQn            = 85,               /**< CORTEXAMIX TempSensor non-secure data ready interrupt */
  USDHC1_IRQn                  = 86,               /**< MEGAMIX uSDHC Enhanced SDHC Interrupt Request */
  USDHC2_IRQn                  = 87,               /**< MEGAMIX uSDHC Enhanced SDHC Interrupt Request */
  TRDC_MGR_W1_IRQn             = 88,               /**< WAKEUPMIX TRDC transfer error interrupt */
  TRDC_MGR_W2_IRQn             = 89,               /**< WAKEUPMIX TRDC transfer error interrupt */
  TRDC_MGR_N_IRQn              = 90,               /**< NOCMIX TRDC transfer error interrupt */
  RESERVED107_IRQn             = 91,               /**< DRAM controller Performance Monitor Interrupt */
  RESERVED108_IRQn             = 92,               /**< DRAM controller Critical Interrupt */
  RESERVED109_IRQn             = 93,               /**< DRAM Phy Critical Interrupt 0 */
  INTG_BOOTROM_DEBUG_CTRL_IRQn = 94,               /**< Cortex-A Cluster Debug Wakeup Request */
  DMA3_ERROR_IRQn              = 95,               /**< AONMIX EDMA error interrupt */
  DMA3_0_IRQn                  = 96,               /**< AONMIX EDMA channel 0 interrupt */
  DMA3_1_IRQn                  = 97,               /**< AONMIX EDMA channel 1 interrupt */
  DMA3_2_IRQn                  = 98,               /**< AONMIX EDMA channel 2 interrupt */
  DMA3_3_IRQn                  = 99,               /**< AONMIX EDMA channel 3 interrupt */
  DMA3_4_IRQn                  = 100,              /**< AONMIX EDMA channel 4 interrupt */
  DMA3_5_IRQn                  = 101,              /**< AONMIX EDMA channel 5 interrupt */
  DMA3_6_IRQn                  = 102,              /**< AONMIX EDMA channel 6 interrupt */
  DMA3_7_IRQn                  = 103,              /**< AONMIX EDMA channel 7 interrupt */
  DMA3_8_IRQn                  = 104,              /**< AONMIX EDMA channel 8 interrupt */
  DMA3_9_IRQn                  = 105,              /**< AONMIX EDMA channel 9 interrupt */
  DMA3_10_IRQn                 = 106,              /**< AONMIX EDMA channel 10 interrupt */
  DMA3_11_IRQn                 = 107,              /**< AONMIX EDMA channel 11 interrupt */
  DMA3_12_IRQn                 = 108,              /**< AONMIX EDMA channel 12 interrupt */
  DMA3_13_IRQn                 = 109,              /**< AONMIX EDMA channel 13 interrupt */
  DMA3_14_IRQn                 = 110,              /**< AONMIX EDMA channel 14 interrupt */
  DMA3_15_IRQn                 = 111,              /**< AONMIX EDMA channel 15 interrupt */
  DMA3_16_IRQn                 = 112,              /**< AONMIX EDMA channel 16 interrupt */
  DMA3_17_IRQn                 = 113,              /**< AONMIX EDMA channel 17 interrupt */
  DMA3_18_IRQn                 = 114,              /**< AONMIX EDMA channel 18 interrupt */
  DMA3_19_IRQn                 = 115,              /**< AONMIX EDMA channel 19 interrupt */
  DMA3_20_IRQn                 = 116,              /**< AONMIX EDMA channel 20 interrupt */
  DMA3_21_IRQn                 = 117,              /**< AONMIX EDMA channel 21 interrupt */
  DMA3_22_IRQn                 = 118,              /**< AONMIX EDMA channel 22 interrupt */
  DMA3_23_IRQn                 = 119,              /**< AONMIX EDMA channel 23 interrupt */
  DMA3_24_IRQn                 = 120,              /**< AONMIX EDMA channel 24 interrupt */
  DMA3_25_IRQn                 = 121,              /**< AONMIX EDMA channel 25 interrupt */
  DMA3_26_IRQn                 = 122,              /**< AONMIX EDMA channel 26 interrupt */
  DMA3_27_IRQn                 = 123,              /**< AONMIX EDMA channel 27 interrupt */
  DMA3_28_IRQn                 = 124,              /**< AONMIX EDMA channel 28 interrupt */
  DMA3_29_IRQn                 = 125,              /**< AONMIX EDMA channel 29 interrupt */
  DMA3_30_IRQn                 = 126,              /**< AONMIX EDMA channel 30 interrupt */
  DMA5_2_ERROR_IRQn            = 127,              /**< WAKEUPMIX EDMA error interrupt */
  DMA5_2_0_1_IRQn              = 128,              /**< WAKEUPMIX EDMA channel 0 interrupt */
  DMA5_2_2_3_IRQn              = 129,              /**< WAKEUPMIX EDMA channel 2 interrupt */
  DMA5_2_4_5_IRQn              = 130,              /**< WAKEUPMIX EDMA channel 4 interrupt */
  DMA5_2_6_7_IRQn              = 131,              /**< WAKEUPMIX EDMA channel 6 interrupt */
  DMA5_2_8_9_IRQn              = 132,              /**< WAKEUPMIX EDMA channel 8 interrupt */
  DMA5_2_10_11_IRQn            = 133,              /**< WAKEUPMIX EDMA channel 10 interrupt */
  DMA5_2_12_13_IRQn            = 134,              /**< WAKEUPMIX EDMA channel 12 interrupt */
  DMA5_2_14_15_IRQn            = 135,              /**< WAKEUPMIX EDMA channel 14 interrupt */
  DMA5_2_16_17_IRQn            = 136,              /**< WAKEUPMIX EDMA channel 16 interrupt */
  DMA5_2_18_19_IRQn            = 137,              /**< WAKEUPMIX EDMA channel 18 interrupt */
  DMA5_2_20_21_IRQn            = 138,              /**< WAKEUPMIX EDMA channel 20 interrupt */
  DMA5_2_22_23_IRQn            = 139,              /**< WAKEUPMIX EDMA channel 22 interrupt */
  DMA5_2_24_25_IRQn            = 140,              /**< WAKEUPMIX EDMA channel 24 interrupt */
  DMA5_2_26_27_IRQn            = 141,              /**< WAKEUPMIX EDMA channel 26 interrupt */
  DMA5_2_28_29_IRQn            = 142,              /**< WAKEUPMIX EDMA channel 28 interrupt */
  DMA5_2_30_31_IRQn            = 143,              /**< WAKEUPMIX EDMA channel 30 interrupt */
  DMA5_2_32_33_IRQn            = 144,              /**< WAKEUPMIX EDMA channel 32 interrupt */
  DMA5_2_34_35_IRQn            = 145,              /**< WAKEUPMIX EDMA channel 34 interrupt */
  DMA5_2_36_37_IRQn            = 146,              /**< WAKEUPMIX EDMA channel 36 interrupt */
  DMA5_2_38_39_IRQn            = 147,              /**< WAKEUPMIX EDMA channel 38 interrupt */
  DMA5_2_40_41_IRQn            = 148,              /**< WAKEUPMIX EDMA channel 40 interrupt */
  DMA5_2_42_43_IRQn            = 149,              /**< WAKEUPMIX EDMA channel 42 interrupt */
  DMA5_2_44_45_IRQn            = 150,              /**< WAKEUPMIX EDMA channel 44 interrupt */
  DMA5_2_46_47_IRQn            = 151,              /**< WAKEUPMIX EDMA channel 46 interrupt */
  DMA5_2_48_49_IRQn            = 152,              /**< WAKEUPMIX EDMA channel 48 interrupt */
  DMA5_2_50_51_IRQn            = 153,              /**< WAKEUPMIX EDMA channel 50 interrupt */
  DMA5_2_52_53_IRQn            = 154,              /**< WAKEUPMIX EDMA channel 52 interrupt */
  DMA5_2_54_55_IRQn            = 155,              /**< WAKEUPMIX EDMA channel 54 interrupt */
  DMA5_2_56_57_IRQn            = 156,              /**< WAKEUPMIX EDMA channel 56 interrupt */
  DMA5_2_58_59_IRQn            = 157,              /**< WAKEUPMIX EDMA channel 58 interrupt */
  DMA5_2_60_61_IRQn            = 158,              /**< WAKEUPMIX EDMA channel 60 interrupt */
  DMA5_2_62_63_IRQn            = 159,              /**< WAKEUPMIX EDMA channel 62 interrupt */
  ELE_GROUP1_IRQn              = 160,              /**< Sentinel Group 1 reset source if no s500 reference clock is detected.  Output synchronized to 32khz clk. */
  ELE_GROUP2_IRQn              = 161,              /**< Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk. */
  ELE_GROUP3_IRQn              = 162,              /**< Sentinel Group 3 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk. */
  DBG_TRACE_IRQn               = 163,              /**< JTAGSW DAP MDM-AP SRC reset source */
  JTAGC_IRQn                   = 164,              /**< JTAGC SRC reset source (the JTAGC used for boundary scan, not JTAGC used for password authentication) */
  SYSREQRST_CM33_IRQn          = 165,              /**< CM33 SYSREQRST SRC reset source */
  LOCKUP_CM33_IRQn             = 166,              /**< CM33 LOCKUP SRC reset source */
  SYSREQRST_CM7_IRQn           = 167,              /**< CM7 SYSREQRST SRC reset source */
  LOCKUP_CM7_IRQn              = 168,              /**< CM7 LOCKUP SRC reset source */
  SAI2_IRQn                    = 169,              /**< NETCMIX SAI TX interrupt */
  SAI3_IRQn                    = 170,              /**< WAKEUPMIX SAI TX interrupt */
  SAI4_IRQn                    = 171,              /**< WAKEUPMIX SAI TX interrupt */
  SAI5_IRQn                    = 172,              /**< WAKEUPMIX SAI TX interrupt */
  USB1_WAKEUP_IRQn             = 173,              /**< USB-1 (USB 2.0) Wake-up Interrupt */
  USB2_WAKEUP_IRQn             = 174,              /**< USB-2 (USB 2.0) Wake-up Interrupt */
  USB1_IRQn                    = 175,              /**< USB-1 (USB 2.0 Controller) Interrupt */
  USB2_IRQn                    = 176,              /**< USB-2 (USB 2.0 Controller) Interrupt */
  LPSPI5_IRQn                  = 177,              /**< WAKEUPMIX LPSPI interrupt */
  LPSPI6_IRQn                  = 178,              /**< WAKEUPMIX LPSPI interrupt */
  LPSPI7_IRQn                  = 179,              /**< WAKEUPMIX LPSPI interrupt */
  LPSPI8_IRQn                  = 180,              /**< WAKEUPMIX LPSPI interrupt */
  LPI2C5_IRQn                  = 181,              /**< WAKEUPMIX LPI2C Master interrupt */
  LPI2C6_IRQn                  = 182,              /**< WAKEUPMIX LPI2C Master interrupt */
  LPI2C7_IRQn                  = 183,              /**< WAKEUPMIX LPI2C Master interrupt */
  LPI2C8_IRQn                  = 184,              /**< WAKEUPMIX LPI2C Master interrupt */
  PDM_HWVAD_ERROR_IRQn         = 185,              /**< AONMIXMIX PDM interrupt */
  PDM_HWVAD_EVENT_IRQn         = 186,              /**< AONMIXMIX PDM interrupt */
  PDM_ERROR_IRQn               = 187,              /**< AONMIXMIX PDM interrupt */
  PDM_EVENT_IRQn               = 188,              /**< AONMIXMIX PDM interrupt */
  RESERVED205_IRQn             = 189,              /**< WAKEUPMIX AUDIO XCVR interrupt */
  RESERVED206_IRQn             = 190,              /**< WAKEUPMIX AUDIO XCVR interrupt */
  USDHC3_IRQn                  = 191,              /**< MEGAMIX uSDHC Enhanced SDHC Interrupt Request */
  RESERVED208_IRQn             = 192,              /**< OCRAM ECC single bit error */
  RESERVED209_IRQn             = 193,              /**< OCRAM ECC multi bit error */
  RESERVED210_IRQn             = 194,              /**< CM33 MCM interrupt */
  RESERVED211_IRQn             = 195,              /**< ANAMIX SFA interrupt */
  RESERVED212_IRQn             = 196,              /**< GIC700 Fault */
  RESERVED213_IRQn             = 197,              /**< GIC700 Error */
  RESERVED214_IRQn             = 198,              /**< GIC700 PMU Counter Overflow */
  ADC_ER_IRQn                  = 199,              /**< ADC interrupt */
  ADC_WD_IRQn                  = 200,              /**< ADC interrupt */
  ADC_EOC_IRQn                 = 201,              /**< ADC interrupt */
  RESERVED218_IRQn             = 202,              /**< s500 glue logic IRQ */
  I3C1_RAW_IRQ_GLUE_IRQn       = 203,              /**< I3C1 wakeup irq after double sync */
  I3C2_RAW_IRQ_GLUE_IRQn       = 204,              /**< I3C2 wakeup irq after double sync */
  MU5_A_IRQn                   = 205,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU6_A_IRQn                   = 206,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU7_B_IRQn                   = 207,              /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU8_B_IRQn                   = 208,              /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  XSPI_SLV_IRQn                = 209,              /**< WAKEUPMIX XSPI Responder */
  FCCU0_IRQn                   = 210,              /**< AONMIX FCCU Interrupt Reaction 0 */
  FCCU1_IRQn                   = 211,              /**< AONMIX FCCU Interrupt Reaction 1 */
  FCCU2_IRQn                   = 212,              /**< AONMIX FCCU Interrupt Reaction 2 */
  STCU_IRQn                    = 213,              /**< AONMIX STCU Selftest end Interrupt */
  DISP_IRQSTEER0_IRQn          = 214,              /**< DISPLAYMIX IRQSTEER 0: Common Control */
  DISP_IRQSTEER1_IRQn          = 215,              /**< DISPLAYMIX IRQSTEER 1: Display 0 Domain 0 */
  DISP_IRQSTEER2_IRQn          = 216,              /**< DISPLAYMIX IRQSTEER 2: Display 0 Domain 1 */
  DISP_IRQSTEER3_IRQn          = 217,              /**< DISPLAYMIX IRQSTEER 3: Display 1 Domain 0 */
  DISP_IRQSTEER4_IRQn          = 218,              /**< DISPLAYMIX IRQSTEER 4: Display 1 Domain 1 */
  DISP_IRQSTEER7_IRQn          = 219,              /**< DISPLAYMIX IRQSTEER 7: Blitter */
  MU_C1_IRQn                   = 220,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  ISI_0_IRQn                   = 221,              /**< CAMERAMIX ISI interrupt Channel 0 */
  ISP_IRQn                     = 222,              /**< ISP Processing Interrupt - Context 0 */
  M7MIX_IRQn                   = 223,              /**< M7MIX MCM interrupt */
  IRQSTEER_0_IRQn              = 224,              /**< IRQSTEER0 interrupt */
  IRQSTEER_1_IRQn              = 225,              /**< IRQSTEER1 interrupt */
  IRQSTEER_2_IRQn              = 226,              /**< IRQSTEER2 interrupt */
  IRQSTEER_3_IRQn              = 227,              /**< IRQSTEER3 interrupt */
  IRQSTEER_4_IRQn              = 228,              /**< IRQSTEER4 interrupt */
  IRQSTEER_5_IRQn              = 229,              /**< IRQSTEER5 interrupt */
  IRQSTEER_6_IRQn              = 230,              /**< IRQSTEER6 interrupt */
  IRQSTEER_7_IRQn              = 231,              /**< IRQSTEER7 interrupt */
  IRQSTEER_8_IRQn              = 232,              /**< IRQSTEER8 interrupt */
  IRQSTEER_9_IRQn              = 233,              /**< IRQSTEER9 interrupt */
  IRQSTEER_10_IRQn             = 234,              /**< IRQSTEER10 interrupt */
  IRQSTEER_11_IRQn             = 235,              /**< IRQSTEER11 interrupt */
  MU1_A_IRQn                   = 236,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU1_B_IRQn                   = 237,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU2_A_IRQn                   = 238,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU2_B_IRQn                   = 239,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU3_A_IRQn                   = 240,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU3_B_IRQn                   = 241,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU4_A_IRQn                   = 242,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU4_B_IRQn                   = 243,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU5_B_IRQn                   = 244,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU6_B_IRQn                   = 245,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU7_A_IRQn                   = 246,              /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU8_A_IRQn                   = 247,              /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MSGINTR1_IRQn                = 248,              /**< MSGINTR Instance 1, Interrupt 1 */
  MSGINTR2_IRQn                = 249,              /**< MSGINTR Instance 2, Interrupt 1 */
  V2X_APCH1_IRQn               = 250,              /**< V2X-FH MU APCH1 (APP1) A_TX interrupt */
  V2X_HSM2_IRQn                = 251,              /**< V2X-FH MU APHSM2 (HSM2) A_TX interrupt */
  RESERVED268_IRQn             = 252,              /**< Reserved interrupt */
  RESERVED269_IRQn             = 253,              /**< Reserved interrupt */
  RESERVED270_IRQn             = 254,              /**< Reserved interrupt */
  RESERVED271_IRQn             = 255,              /**< Reserved interrupt */
  RESERVED272_IRQn             = 256,              /**< Reserved interrupt */
  RESERVED273_IRQn             = 257,              /**< Reserved interrupt */
  RESERVED274_IRQn             = 258,              /**< Reserved interrupt */
  RESERVED275_IRQn             = 259,              /**< Reserved interrupt */
  RESERVED276_IRQn             = 260,              /**< Reserved interrupt */
  RESERVED277_IRQn             = 261,              /**< Reserved interrupt */
  RESERVED278_IRQn             = 262,              /**< Reserved interrupt */
  RESERVED279_IRQn             = 263,              /**< Reserved interrupt */
  RESERVED280_IRQn             = 264,              /**< Reserved interrupt */
  RESERVED281_IRQn             = 265,              /**< Reserved interrupt */
  RESERVED282_IRQn             = 266,              /**< Reserved interrupt */
  RESERVED283_IRQn             = 267,              /**< Reserved interrupt */
  RESERVED284_IRQn             = 268,              /**< Reserved interrupt */
  RESERVED285_IRQn             = 269,              /**< Reserved interrupt */
  RESERVED286_IRQn             = 270,              /**< Reserved interrupt */
  RESERVED287_IRQn             = 271,              /**< Reserved interrupt */
  RESERVED288_IRQn             = 272,              /**< Reserved interrupt */
  RESERVED289_IRQn             = 273,              /**< Reserved interrupt */
  RESERVED290_IRQn             = 274,              /**< Reserved interrupt */
  RESERVED291_IRQn             = 275,              /**< Reserved interrupt */
  RESERVED292_IRQn             = 276,              /**< Reserved interrupt */
  RESERVED293_IRQn             = 277,              /**< Reserved interrupt */
  RESERVED294_IRQn             = 278,              /**< Reserved interrupt */
  RESERVED295_IRQn             = 279,              /**< Reserved interrupt */
  RESERVED296_IRQn             = 280,              /**< Reserved interrupt */
  RESERVED297_IRQn             = 281,              /**< Reserved interrupt */
  RESERVED298_IRQn             = 282,              /**< Reserved interrupt */
  RESERVED299_IRQn             = 283,              /**< Reserved interrupt */
  RESERVED300_IRQn             = 284,              /**< Reserved interrupt */
  RESERVED301_IRQn             = 285,              /**< Reserved interrupt */
  RESERVED302_IRQn             = 286,              /**< Reserved interrupt */
  RESERVED303_IRQn             = 287,              /**< Reserved interrupt */
  RESERVED304_IRQn             = 288,              /**< Reserved interrupt */
  RESERVED305_IRQn             = 289,              /**< Reserved interrupt */
  RESERVED306_IRQn             = 290,              /**< Reserved interrupt */
  RESERVED307_IRQn             = 291,              /**< Reserved interrupt */
  RESERVED308_IRQn             = 292,              /**< Reserved interrupt */
  RESERVED309_IRQn             = 293,              /**< Reserved interrupt */
  RESERVED310_IRQn             = 294,              /**< Reserved interrupt */
  RESERVED311_IRQn             = 295,              /**< Reserved interrupt */
  RESERVED312_IRQn             = 296,              /**< Reserved interrupt */
  RESERVED313_IRQn             = 297,              /**< Reserved interrupt */
  RESERVED314_IRQn             = 298,              /**< Reserved interrupt */
  RESERVED315_IRQn             = 299,              /**< Reserved interrupt */
  TRDC_MGR_C_IRQn              = 300,              /**< CAMERAMIX TRDC transfer error interrupt */
  TRDC_MGR_D_IRQn              = 301,              /**< DISPLAYMIX TRDC transfer error interrupt */
  TRDC_MGR_E_IRQn              = 302,              /**< NETCMIX TRDC transfer error interrupt */
  TRDC_MGR_G_IRQn              = 303,              /**< GPUMIX TRDC transfer error interrupt */
  TRDC_MGR_H_IRQn              = 304,              /**< HSIOMIX TRDC transfer error interrupt */
  TRDC_MGR_V_IRQn              = 305,              /**< VPUMIX TRDC transfer error interrupt */
  ERM_A_IRQn                   = 306,              /**< AONMIX ERM Single bit corrected ECC Error */
  RESERVED323_IRQn             = 307,              /**< M7MIX ERM Single bit corrected ECC Error */
  ERM_W_IRQn                   = 308,              /**< WAKEUPMIX ERM Single bit corrected ECC Error */
  ERM_ML_IRQn                  = 309,              /**< NPUMIX ERM Single bit corrected ECC Error */
  DMA5_3_ERROR_IRQn            = 310,              /**< WAKEUPMIX ACP EDMA error interrupt */
  OCRAM_C_IRQn                 = 311,              /**< OCRAM_C ECC multiple bit or address error */
  RESERVED328_IRQn             = 312,              /**< CAMERAMIX Cortex-M0+ Cache write-buffer error */
  RESERVED329_IRQn             = 313,              /**< CAMERAMIX Cortex-M0+ Cache data parity error */
  RESERVED330_IRQn             = 314,              /**< V2X-FH MU APSHE (SHE) A_TX interrupt */
  RESERVED331_IRQn             = 315,              /**< V2X-FH MU SCU/APDEBUG (DEBUG) B_TX interrupt */
  RESERVED332_IRQn             = 316,              /**< Reserved interrupt */
  RESERVED333_IRQn             = 317,              /**< Reserved interrupt */
  RESERVED334_IRQn             = 318,              /**< Reserved interrupt */
  RESERVED335_IRQn             = 319,              /**< Reserved interrupt */
  RESERVED336_IRQn             = 320,              /**< Reserved interrupt */
  RESERVED337_IRQn             = 321,              /**< Reserved interrupt */
  RESERVED338_IRQn             = 322,              /**< Reserved interrupt */
  RESERVED339_IRQn             = 323,              /**< Reserved interrupt */
  RESERVED340_IRQn             = 324,              /**< Reserved interrupt */
  RESERVED341_IRQn             = 325,              /**< Reserved interrupt */
  RESERVED342_IRQn             = 326,              /**< Reserved interrupt */
  RESERVED343_IRQn             = 327,              /**< Reserved interrupt */
  RESERVED344_IRQn             = 328,              /**< Reserved interrupt */
  RESERVED345_IRQn             = 329,              /**< Reserved interrupt */
  RESERVED346_IRQn             = 330,              /**< Reserved interrupt */
  RESERVED347_IRQn             = 331,              /**< Reserved interrupt */
  RESERVED348_IRQn             = 332,              /**< Reserved interrupt */
  RESERVED349_IRQn             = 333,              /**< Reserved interrupt */
  RESERVED350_IRQn             = 334,              /**< Reserved interrupt */
  RESERVED351_IRQn             = 335,              /**< Reserved interrupt */
  RESERVED352_IRQn             = 336,              /**< Reserved interrupt */
  RESERVED353_IRQn             = 337,              /**< Reserved interrupt */
  RESERVED354_IRQn             = 338,              /**< Reserved interrupt */
  RESERVED355_IRQn             = 339,              /**< Reserved interrupt */
  RESERVED356_IRQn             = 340,              /**< Reserved interrupt */
  RESERVED357_IRQn             = 341,              /**< Reserved interrupt */
  RESERVED358_IRQn             = 342,              /**< Reserved interrupt */
  RESERVED359_IRQn             = 343,              /**< Reserved interrupt */
  RESERVED360_IRQn             = 344,              /**< Reserved interrupt */
  RESERVED361_IRQn             = 345,              /**< Reserved interrupt */
  RESERVED362_IRQn             = 346,              /**< Reserved interrupt */
  RESERVED363_IRQn             = 347,              /**< Reserved interrupt */
  RESERVED364_IRQn             = 348,              /**< Reserved interrupt */
  RESERVED365_IRQn             = 349,              /**< Reserved interrupt */
  RESERVED366_IRQn             = 350,              /**< Reserved interrupt */
  RESERVED367_IRQn             = 351,              /**< Reserved interrupt */
  RESERVED368_IRQn             = 352,              /**< Reserved interrupt */
  RESERVED369_IRQn             = 353,              /**< Reserved interrupt */
  RESERVED370_IRQn             = 354,              /**< Reserved interrupt */
  RESERVED371_IRQn             = 355,              /**< Reserved interrupt */
  RESERVED372_IRQn             = 356,              /**< Reserved interrupt */
  RESERVED373_IRQn             = 357,              /**< Reserved interrupt */
  RESERVED374_IRQn             = 358,              /**< Reserved interrupt */
  RESERVED375_IRQn             = 359,              /**< Reserved interrupt */
  RESERVED376_IRQn             = 360,              /**< Reserved interrupt */
  RESERVED377_IRQn             = 361,              /**< Reserved interrupt */
  RESERVED378_IRQn             = 362,              /**< Reserved interrupt */
  RESERVED379_IRQn             = 363,              /**< Reserved interrupt */
  DMA5_3_0_1_IRQn              = 364,              /**< WAKEUPMIX ACP EDMA channel 0 interrupt */
  DMA5_3_2_3_IRQn              = 365,              /**< WAKEUPMIX ACP EDMA channel 2 interrupt */
  DMA5_3_4_5_IRQn              = 366,              /**< WAKEUPMIX ACP EDMA channel 4 interrupt */
  DMA5_3_6_7_IRQn              = 367,              /**< WAKEUPMIX ACP EDMA channel 6 interrupt */
  DMA5_3_8_9_IRQn              = 368,              /**< WAKEUPMIX ACP EDMA channel 8 interrupt */
  DMA5_3_10_11_IRQn            = 369,              /**< WAKEUPMIX ACP EDMA channel 10 interrupt */
  DMA5_3_12_13_IRQn            = 370,              /**< WAKEUPMIX ACP EDMA channel 12 interrupt */
  DMA5_3_14_15_IRQn            = 371,              /**< WAKEUPMIX ACP EDMA channel 14 interrupt */
  DMA5_3_16_17_IRQn            = 372,              /**< WAKEUPMIX ACP EDMA channel 16 interrupt */
  DMA5_3_18_19_IRQn            = 373,              /**< WAKEUPMIX ACP EDMA channel 18 interrupt */
  DMA5_3_20_21_IRQn            = 374,              /**< WAKEUPMIX ACP EDMA channel 20 interrupt */
  DMA5_3_22_23_IRQn            = 375,              /**< WAKEUPMIX ACP EDMA channel 22 interrupt */
  DMA5_3_24_25_IRQn            = 376,              /**< WAKEUPMIX ACP EDMA channel 24 interrupt */
  DMA5_3_26_27_IRQn            = 377,              /**< WAKEUPMIX ACP EDMA channel 26 interrupt */
  DMA5_3_28_29_IRQn            = 378,              /**< WAKEUPMIX ACP EDMA channel 28 interrupt */
  DMA5_3_30_31_IRQn            = 379,              /**< WAKEUPMIX ACP EDMA channel 30 interrupt */
  RESERVED396_IRQn             = 380,              /**< Reserved interrupt */
  RESERVED397_IRQn             = 381,              /**< Reserved interrupt */
  RESERVED398_IRQn             = 382,              /**< Reserved interrupt */
  RESERVED399_IRQn             = 383,              /**< Reserved interrupt */
  RESERVED400_IRQn             = 384,              /**< Reserved interrupt */
  RESERVED401_IRQn             = 385,              /**< Reserved interrupt */
  RESERVED402_IRQn             = 386,              /**< Reserved interrupt */
  RESERVED403_IRQn             = 387,              /**< Reserved interrupt */
  RESERVED404_IRQn             = 388,              /**< Reserved interrupt */
  RESERVED405_IRQn             = 389,              /**< Reserved interrupt */
  RESERVED406_IRQn             = 390,              /**< Reserved interrupt */
  RESERVED407_IRQn             = 391,              /**< Reserved interrupt */
  RESERVED408_IRQn             = 392,              /**< Reserved interrupt */
  RESERVED409_IRQn             = 393,              /**< Reserved interrupt */
  RESERVED410_IRQn             = 394,              /**< Reserved interrupt */
  RESERVED411_IRQn             = 395,              /**< Reserved interrupt */
  RESERVED412_IRQn             = 396,              /**< Reserved interrupt */
  RESERVED413_IRQn             = 397,              /**< Reserved interrupt */
  RESERVED414_IRQn             = 398,              /**< Reserved interrupt */
  RESERVED415_IRQn             = 399,              /**< Reserved interrupt */
  RESERVED416_IRQn             = 400,              /**< Reserved interrupt */
  RESERVED417_IRQn             = 401,              /**< Reserved interrupt */
  RESERVED418_IRQn             = 402,              /**< Reserved interrupt */
  RESERVED419_IRQn             = 403,              /**< Reserved interrupt */
  RESERVED420_IRQn             = 404,              /**< Reserved interrupt */
  RESERVED421_IRQn             = 405,              /**< Reserved interrupt */
  RESERVED422_IRQn             = 406,              /**< Reserved interrupt */
  RESERVED423_IRQn             = 407,              /**< Reserved interrupt */
  RESERVED424_IRQn             = 408,              /**< Reserved interrupt */
  RESERVED425_IRQn             = 409,              /**< Reserved interrupt */
  RESERVED426_IRQn             = 410,              /**< Reserved interrupt */
  RESERVED427_IRQn             = 411,              /**< Reserved interrupt */
  RESERVED428_IRQn             = 412,              /**< Reserved interrupt */
  RESERVED429_IRQn             = 413,              /**< Reserved interrupt */
  RESERVED430_IRQn             = 414,              /**< Reserved interrupt */
  RESERVED431_IRQn             = 415,              /**< Reserved interrupt */
  RESERVED432_IRQn             = 416,              /**< Reserved interrupt */
  RESERVED433_IRQn             = 417,              /**< Reserved interrupt */
  RESERVED434_IRQn             = 418,              /**< Reserved interrupt */
  RESERVED435_IRQn             = 419,              /**< Reserved interrupt */
  RESERVED436_IRQn             = 420,              /**< Reserved interrupt */
  RESERVED437_IRQn             = 421,              /**< Reserved interrupt */
  RESERVED438_IRQn             = 422,              /**< Reserved interrupt */
  RESERVED439_IRQn             = 423,              /**< Reserved interrupt */
  RESERVED440_IRQn             = 424,              /**< Reserved interrupt */
  RESERVED441_IRQn             = 425,              /**< Reserved interrupt */
  RESERVED442_IRQn             = 426,              /**< Reserved interrupt */
  RESERVED443_IRQn             = 427,              /**< Reserved interrupt */
  DMA5_3_32_33_IRQn            = 428,              /**<  WAKEUPMIX ACP EDMA channel 32 interrupt */
  DMA5_3_34_35_IRQn            = 429,              /**<  WAKEUPMIX ACP EDMA channel 34 interrupt */
  DMA5_3_36_37_IRQn            = 430,              /**<  WAKEUPMIX ACP EDMA channel 36 interrupt */
  DMA5_3_38_39_IRQn            = 431,              /**<  WAKEUPMIX ACP EDMA channel 38 interrupt */
  DMA5_3_40_41_IRQn            = 432,              /**<  WAKEUPMIX ACP EDMA channel 40 interrupt */
  DMA5_3_42_43_IRQn            = 433,              /**<  WAKEUPMIX ACP EDMA channel 42 interrupt */
  DMA5_3_44_45_IRQn            = 434,              /**<  WAKEUPMIX ACP EDMA channel 44 interrupt */
  DMA5_3_46_47_IRQn            = 435,              /**<  WAKEUPMIX ACP EDMA channel 46 interrupt */
  DMA5_3_48_49_IRQn            = 436,              /**<  WAKEUPMIX ACP EDMA channel 48 interrupt */
  DMA5_3_50_51_IRQn            = 437,              /**<  WAKEUPMIX ACP EDMA channel 50 interrupt */
  DMA5_3_52_53_IRQn            = 438,              /**<  WAKEUPMIX ACP EDMA channel 52 interrupt */
  DMA5_3_54_55_IRQn            = 439,              /**<  WAKEUPMIX ACP EDMA channel 54 interrupt */
  DMA5_3_56_57_IRQn            = 440,              /**<  WAKEUPMIX ACP EDMA channel 56 interrupt */
  DMA5_3_58_59_IRQn            = 441,              /**<  WAKEUPMIX ACP EDMA channel 58 interrupt */
  DMA5_3_60_61_IRQn            = 442,              /**<  WAKEUPMIX ACP EDMA channel 60 interrupt */
  DMA5_3_62_63_IRQn            = 443,              /**<  WAKEUPMIX ACP EDMA channel 62 interrupt */
  RESERVED460_IRQn             = 444,              /**< Reserved interrupt */
  RESERVED461_IRQn             = 445,              /**< Reserved interrupt */
  RESERVED462_IRQn             = 446,              /**< Reserved interrupt */
  RESERVED463_IRQn             = 447,              /**< Reserved interrupt */
  RESERVED464_IRQn             = 448,              /**< Reserved interrupt */
  RESERVED465_IRQn             = 449,              /**< Reserved interrupt */
  RESERVED466_IRQn             = 450,              /**< Reserved interrupt */
  RESERVED467_IRQn             = 451,              /**< Reserved interrupt */
  RESERVED468_IRQn             = 452,              /**< Reserved interrupt */
  RESERVED469_IRQn             = 453,              /**< Reserved interrupt */
  RESERVED470_IRQn             = 454,              /**< Reserved interrupt */
  RESERVED471_IRQn             = 455,              /**< Reserved interrupt */
  RESERVED472_IRQn             = 456,              /**< Reserved interrupt */
  RESERVED473_IRQn             = 457,              /**< Reserved interrupt */
  RESERVED474_IRQn             = 458,              /**< Reserved interrupt */
  RESERVED475_IRQn             = 459,              /**< Reserved interrupt */
  RESERVED476_IRQn             = 460,              /**< Reserved interrupt */
  RESERVED477_IRQn             = 461,              /**< Reserved interrupt */
  RESERVED478_IRQn             = 462,              /**< Reserved interrupt */
  RESERVED479_IRQn             = 463,              /**< Reserved interrupt */
  RESERVED480_IRQn             = 464,              /**< Reserved interrupt */
  RESERVED481_IRQn             = 465,              /**< Reserved interrupt */
  RESERVED482_IRQn             = 466,              /**< Reserved interrupt */
  RESERVED483_IRQn             = 467,              /**< Reserved interrupt */
  RESERVED484_IRQn             = 468,              /**< Reserved interrupt */
  RESERVED485_IRQn             = 469,              /**< Reserved interrupt */
  RESERVED486_IRQn             = 470,              /**< Reserved interrupt */
  RESERVED487_IRQn             = 471,              /**< Reserved interrupt */
  RESERVED488_IRQn             = 472,              /**< Reserved interrupt */
  RESERVED489_IRQn             = 473,              /**< Reserved interrupt */
  RESERVED490_IRQn             = 474,              /**< Reserved interrupt */
  RESERVED491_IRQn             = 475,              /**< Reserved interrupt */
  RESERVED492_IRQn             = 476,              /**< Reserved interrupt */
  RESERVED493_IRQn             = 477,              /**< Reserved interrupt */
  RESERVED494_IRQn             = 478,              /**< Reserved interrupt */
  RESERVED495_IRQn             = 479,              /**< Reserved interrupt */
  RESERVED496_IRQn             = 480,              /**< Reserved interrupt */
  RESERVED497_IRQn             = 481,              /**< Reserved interrupt */
  RESERVED498_IRQn             = 482,              /**< Reserved interrupt */
  RESERVED499_IRQn             = 483,              /**< Reserved interrupt */
  RESERVED500_IRQn             = 484,              /**< Reserved interrupt */
  RESERVED501_IRQn             = 485,              /**< Reserved interrupt */
  RESERVED502_IRQn             = 486,              /**< Reserved interrupt */
  RESERVED503_IRQn             = 487,              /**< Reserved interrupt */
  RESERVED504_IRQn             = 488,              /**< Reserved interrupt */
  RESERVED505_IRQn             = 489,              /**< Reserved interrupt */
  RESERVED506_IRQn             = 490,              /**< Reserved interrupt */
  RESERVED507_IRQn             = 491,              /**< Reserved interrupt */
  RESERVED508_IRQn             = 492,              /**< GPUMIX GPU Interrupt */
  RESERVED509_IRQn             = 493,              /**< GPUMIX Job Interrupt */
  RESERVED510_IRQn             = 494,              /**< GPUMIX MMU Interrupt */
  RESERVED511_IRQn             = 495,              /**< Reserved interrupt */
  RESERVED512_IRQn             = 496,              /**< Reserved interrupt */
  RESERVED513_IRQn             = 497,              /**< Reserved interrupt */
  RESERVED514_IRQn             = 498,              /**< Reserved interrupt */
  RESERVED515_IRQn             = 499,              /**< Reserved interrupt */
  RESERVED516_IRQn             = 500,              /**< Reserved interrupt */
  RESERVED517_IRQn             = 501,              /**< Reserved interrupt */
  RESERVED518_IRQn             = 502,              /**< Reserved interrupt */
  RESERVED519_IRQn             = 503,              /**< Reserved interrupt */
  RESERVED520_IRQn             = 504,              /**< Reserved interrupt */
  RESERVED521_IRQn             = 505,              /**< Reserved interrupt */
  RESERVED522_IRQn             = 506,              /**< Reserved interrupt */
  RESERVED523_IRQn             = 507,              /**< CODA980 VPU Encoder */
  RESERVED524_IRQn             = 508,              /**< Reserved interrupt */
  RESERVED525_IRQn             = 509,              /**< Reserved interrupt */
  RESERVED526_IRQn             = 510,              /**< Reserved interrupt */
  RESERVED527_IRQn             = 511,              /**< Reserved interrupt */
  RESERVED528_IRQn             = 512,              /**< Reserved interrupt */
  RESERVED529_IRQn             = 513,              /**< Reserved interrupt */
  RESERVED530_IRQn             = 514,              /**< Reserved interrupt */
  RESERVED531_IRQn             = 515,              /**< Reserved interrupt */
  RESERVED532_IRQn             = 516,              /**< Reserved interrupt */
  RESERVED533_IRQn             = 517,              /**< Reserved interrupt */
  RESERVED534_IRQn             = 518,              /**< Reserved interrupt */
  RESERVED535_IRQn             = 519,              /**< Reserved interrupt */
  RESERVED536_IRQn             = 520,              /**< Reserved interrupt */
  RESERVED537_IRQn             = 521,              /**< Reserved interrupt */
  RESERVED538_IRQn             = 522,              /**< Reserved interrupt */
  RESERVED539_IRQn             = 523,              /**< Reserved interrupt */
  RESERVED540_IRQn             = 524,              /**< Reserved interrupt */
  RESERVED541_IRQn             = 525,              /**< Reserved interrupt */
  RESERVED542_IRQn             = 526,              /**< Reserved interrupt */
  RESERVED543_IRQn             = 527,              /**< Reserved interrupt */
  RESERVED544_IRQn             = 528,              /**< Reserved interrupt */
  RESERVED545_IRQn             = 529,              /**< Reserved interrupt */
  RESERVED546_IRQn             = 530,              /**< Reserved interrupt */
  RESERVED547_IRQn             = 531,              /**< Reserved interrupt */
  RESERVED548_IRQn             = 532,              /**< Reserved interrupt */
  RESERVED549_IRQn             = 533,              /**< Reserved interrupt */
  RESERVED550_IRQn             = 534,              /**< Reserved interrupt */
  RESERVED551_IRQn             = 535,              /**< Reserved interrupt */
  RESERVED552_IRQn             = 536,              /**< Reserved interrupt */
  RESERVED553_IRQn             = 537,              /**< Reserved interrupt */
  RESERVED554_IRQn             = 538,              /**< Reserved interrupt */
  RESERVED555_IRQn             = 539,              /**< Reserved interrupt */
  RESERVED556_IRQn             = 540,              /**< Reserved interrupt */
  RESERVED557_IRQn             = 541,              /**< Reserved interrupt */
  RESERVED558_IRQn             = 542,              /**< Reserved interrupt */
  RESERVED559_IRQn             = 543,              /**< Reserved interrupt */
  RESERVED560_IRQn             = 544,              /**< Reserved interrupt */
  RESERVED561_IRQn             = 545,              /**< Reserved interrupt */
  RESERVED562_IRQn             = 546,              /**< Reserved interrupt */
  RESERVED563_IRQn             = 547,              /**< Reserved interrupt */
  RESERVED564_IRQn             = 548,              /**< Reserved interrupt */
  RESERVED565_IRQn             = 549,              /**< Reserved interrupt */
  RESERVED566_IRQn             = 550,              /**< Reserved interrupt */
  RESERVED567_IRQn             = 551,              /**< Reserved interrupt */
  RESERVED568_IRQn             = 552,              /**< Reserved interrupt */
  RESERVED569_IRQn             = 553,              /**< Reserved interrupt */
  RESERVED570_IRQn             = 554,              /**< Reserved interrupt */
  RESERVED571_IRQn             = 555,              /**< Reserved interrupt */
  RESERVED572_IRQn             = 556,              /**< NETC iEPRC PCI INT (one per each of two RC-EC) */
  RESERVED573_IRQn             = 557,              /**< NETC iEPRC PCI INT (one per each of two RC-EC) */
  RESERVED574_IRQn             = 558,              /**< PCIe Controller 1 INTA */
  RESERVED575_IRQn             = 559,              /**< PCIe Controller 1 INTB */
  RESERVED576_IRQn             = 560,              /**< PCIe Controller 1 INTC */
  RESERVED577_IRQn             = 561,              /**< PCIe Controller 1 INTD */
  RESERVED578_IRQn             = 562,              /**< PCIe miscellaneous interrupts */
  RESERVED579_IRQn             = 563,              /**< PCIe Controller EDMA channel interrupt */
  RESERVED580_IRQn             = 564,              /**< Reserved */
  RESERVED581_IRQn             = 565,              /**< Reserved */
  RESERVED582_IRQn             = 566,              /**< Reserved */
  RESERVED583_IRQn             = 567,              /**< Reserved */
  RESERVED584_IRQn             = 568,              /**< Reserved */
  RESERVED585_IRQn             = 569,              /**< Reserved */
  RESERVED586_IRQn             = 570,              /**< NPU Functional interrupt */
  RESERVED587_IRQn             = 571,              /**< NPU Fault interrupt */
  RESERVED588_IRQn             = 572,              /**< Reserved interrupt */
  RESERVED589_IRQn             = 573,              /**< Reserved interrupt */
  RESERVED590_IRQn             = 574,              /**< Reserved interrupt */
  RESERVED591_IRQn             = 575,              /**< Reserved interrupt */
  RESERVED592_IRQn             = 576,              /**< Reserved interrupt */
  RESERVED593_IRQn             = 577,              /**< Reserved interrupt */
  RESERVED594_IRQn             = 578,              /**< Reserved interrupt */
  RESERVED595_IRQn             = 579,              /**< Reserved interrupt */
  RESERVED596_IRQn             = 580,              /**< Reserved interrupt */
  RESERVED597_IRQn             = 581,              /**< Reserved interrupt */
  RESERVED598_IRQn             = 582,              /**< Reserved interrupt */
  RESERVED599_IRQn             = 583,              /**< Reserved interrupt */
  RESERVED600_IRQn             = 584,              /**< Reserved interrupt */
  RESERVED601_IRQn             = 585,              /**< Reserved interrupt */
  RESERVED602_IRQn             = 586,              /**< Reserved interrupt */
  RESERVED603_IRQn             = 587,              /**< Reserved interrupt */
  RESERVED604_IRQn             = 588,              /**< Reserved interrupt */
  RESERVED605_IRQn             = 589,              /**< Reserved interrupt */
  RESERVED606_IRQn             = 590,              /**< Reserved interrupt */
  RESERVED607_IRQn             = 591,              /**< Reserved interrupt */
  RESERVED608_IRQn             = 592,              /**< Reserved interrupt */
  RESERVED609_IRQn             = 593,              /**< Reserved interrupt */
  RESERVED610_IRQn             = 594,              /**< Reserved interrupt */
  RESERVED611_IRQn             = 595,              /**< Reserved interrupt */
  RESERVED612_IRQn             = 596,              /**< Reserved interrupt */
  RESERVED613_IRQn             = 597,              /**< Reserved interrupt */
  RESERVED614_IRQn             = 598,              /**< Reserved interrupt */
  RESERVED615_IRQn             = 599,              /**< Reserved interrupt */
  RESERVED616_IRQn             = 600,              /**< Reserved interrupt */
  RESERVED617_IRQn             = 601,              /**< Reserved interrupt */
  RESERVED618_IRQn             = 602,              /**< Reserved interrupt */
  RESERVED619_IRQn             = 603,              /**< Reserved interrupt */
  RESERVED620_IRQn             = 604,              /**< Reserved interrupt */
  RESERVED621_IRQn             = 605,              /**< Reserved interrupt */
  RESERVED622_IRQn             = 606,              /**< Reserved interrupt */
  RESERVED623_IRQn             = 607,              /**< Reserved interrupt */
  RESERVED624_IRQn             = 608,              /**< Reserved interrupt */
  RESERVED625_IRQn             = 609,              /**< Reserved interrupt */
  RESERVED626_IRQn             = 610,              /**< Reserved interrupt */
  RESERVED627_IRQn             = 611,              /**< Reserved interrupt */
  RESERVED628_IRQn             = 612,              /**< Reserved interrupt */
  RESERVED629_IRQn             = 613,              /**< Reserved interrupt */
  RESERVED630_IRQn             = 614,              /**< Reserved interrupt */
  RESERVED631_IRQn             = 615,              /**< Reserved interrupt */
  RESERVED632_IRQn             = 616,              /**< Reserved interrupt */
  RESERVED633_IRQn             = 617,              /**< Reserved interrupt */
  RESERVED634_IRQn             = 618,              /**< Reserved interrupt */
  RESERVED635_IRQn             = 619,              /**< Reserved interrupt */
  RESERVED636_IRQn             = 620,              /**< Reserved interrupt */
  RESERVED637_IRQn             = 621,              /**< Reserved interrupt */
  RESERVED638_IRQn             = 622,              /**< Reserved interrupt */
  RESERVED639_IRQn             = 623,              /**< Reserved interrupt */
  RESERVED640_IRQn             = 624,              /**< Reserved interrupt */
  RESERVED641_IRQn             = 625,              /**< Reserved interrupt */
  RESERVED642_IRQn             = 626,              /**< Reserved interrupt */
  RESERVED643_IRQn             = 627,              /**< Reserved interrupt */
  RESERVED644_IRQn             = 628,              /**< Reserved interrupt */
  RESERVED645_IRQn             = 629,              /**< Reserved interrupt */
  RESERVED646_IRQn             = 630,              /**< Reserved interrupt */
  RESERVED647_IRQn             = 631,              /**< Reserved interrupt */
  RESERVED648_IRQn             = 632,              /**< Reserved interrupt */
  RESERVED649_IRQn             = 633,              /**< Reserved interrupt */
  RESERVED650_IRQn             = 634,              /**< Reserved interrupt */
  LP_HDSK_GSKT_IRQn            = 635,              /**< SRC/GPC Low Power Handshake Gasket interrupt request for system management */
  RESERVED652_IRQn             = 636,              /**< Reserved interrupt */
  RESERVED653_IRQn             = 637,              /**< Reserved interrupt */
  RESERVED654_IRQn             = 638,              /**< Reserved interrupt */
  RESERVED655_IRQn             = 639,              /**< Reserved interrupt */
  RESERVED656_IRQn             = 640,              /**< Reserved interrupt */
  RESERVED657_IRQn             = 641,              /**< Reserved interrupt */
  RESERVED658_IRQn             = 642,              /**< Reserved interrupt */
  RESERVED659_IRQn             = 643,              /**< Reserved interrupt */
  RESERVED660_IRQn             = 644,              /**< Reserved interrupt */
  RESERVED661_IRQn             = 645,              /**< Reserved interrupt */
  RESERVED662_IRQn             = 646,              /**< Reserved interrupt */
  RESERVED663_IRQn             = 647,              /**< Reserved interrupt */
  RESERVED664_IRQn             = 648,              /**< Reserved interrupt */
  RESERVED665_IRQn             = 649,              /**< Reserved interrupt */
  RESERVED666_IRQn             = 650,              /**< Reserved interrupt */
  RESERVED667_IRQn             = 651,              /**< Reserved interrupt */
  RESERVED668_IRQn             = 652,              /**< Reserved interrupt */
  RESERVED669_IRQn             = 653,              /**< Reserved interrupt */
  RESERVED670_IRQn             = 654,              /**< Reserved interrupt */
  RESERVED671_IRQn             = 655,              /**< Reserved interrupt */
  RESERVED672_IRQn             = 656,              /**< Reserved interrupt */
  RESERVED673_IRQn             = 657,              /**< Reserved interrupt */
  RESERVED674_IRQn             = 658,              /**< Reserved interrupt */
  RESERVED675_IRQn             = 659,              /**< Reserved interrupt */
  RESERVED676_IRQn             = 660,              /**< Reserved interrupt */
  RESERVED677_IRQn             = 661,              /**< Reserved interrupt */
  RESERVED678_IRQn             = 662,              /**< Reserved interrupt */
  RESERVED679_IRQn             = 663,              /**< Reserved interrupt */
  RESERVED680_IRQn             = 664,              /**< Reserved interrupt */
  RESERVED681_IRQn             = 665,              /**< Reserved interrupt */
  RESERVED682_IRQn             = 666,              /**< Reserved interrupt */
  RESERVED683_IRQn             = 667,              /**< Reserved interrupt */
  RESERVED684_IRQn             = 668,              /**< Reserved interrupt */
  RESERVED685_IRQn             = 669,              /**< Reserved interrupt */
  RESERVED686_IRQn             = 670,              /**< Reserved interrupt */
  RESERVED687_IRQn             = 671,              /**< Reserved interrupt */
  RESERVED688_IRQn             = 672,              /**< Reserved interrupt */
  RESERVED689_IRQn             = 673,              /**< Reserved interrupt */
  RESERVED690_IRQn             = 674,              /**< Reserved interrupt */
  RESERVED691_IRQn             = 675,              /**< Reserved interrupt */
  RESERVED692_IRQn             = 676,              /**< Reserved interrupt */
  RESERVED693_IRQn             = 677,              /**< Reserved interrupt */
  RESERVED694_IRQn             = 678,              /**< Reserved interrupt */
  RESERVED695_IRQn             = 679,              /**< Reserved interrupt */
  RESERVED696_IRQn             = 680,              /**< Reserved interrupt */
  RESERVED697_IRQn             = 681,              /**< Reserved interrupt */
  RESERVED698_IRQn             = 682,              /**< Reserved interrupt */
  RESERVED699_IRQn             = 683,              /**< Reserved interrupt */
  MU_C2_IRQn                   = 684,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C3_IRQn                   = 685,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C4_IRQn                   = 686,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C5_IRQn                   = 687,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C6_IRQn                   = 688,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C7_IRQn                   = 689,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C8_IRQn                   = 690,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C9_IRQn                   = 691,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  ISI_1_IRQn                   = 692,              /**< CAMERAMIX ISI interrupt Channel 1 */
  ISI_2_IRQn                   = 693,              /**< CAMERAMIX ISI interrupt Channel 2 */
  ISI_3_IRQn                   = 694,              /**< CAMERAMIX ISI interrupt Channel 3 */
  ISI_4_IRQn                   = 695,              /**< CAMERAMIX ISI interrupt Channel 4 */
  ISI_5_IRQn                   = 696,              /**< CAMERAMIX ISI interrupt Channel 5 */
  ISI_6_IRQn                   = 697,              /**< CAMERAMIX ISI interrupt Channel 6 */
  ISI_7_IRQn                   = 698,              /**< CAMERAMIX ISI interrupt Channel 7 */
  DMA5_4_ERROR_IRQn            = 699,              /**< CAMERAMIX EDMA error interrupt */
  RESERVED716_IRQn             = 700,              /**< Reserved interrupt */
  RESERVED717_IRQn             = 701,              /**< Reserved interrupt */
  RESERVED718_IRQn             = 702,              /**< Reserved interrupt */
  RESERVED719_IRQn             = 703,              /**< Reserved interrupt */
  RESERVED720_IRQn             = 704,              /**< Reserved interrupt */
  RESERVED721_IRQn             = 705,              /**< Reserved interrupt */
  RESERVED722_IRQn             = 706,              /**< Reserved interrupt */
  RESERVED723_IRQn             = 707,              /**< Reserved interrupt */
  RESERVED724_IRQn             = 708,              /**< Reserved interrupt */
  RESERVED725_IRQn             = 709,              /**< Reserved interrupt */
  RESERVED726_IRQn             = 710,              /**< Reserved interrupt */
  RESERVED727_IRQn             = 711,              /**< Reserved interrupt */
  RESERVED728_IRQn             = 712,              /**< Reserved interrupt */
  RESERVED729_IRQn             = 713,              /**< Reserved interrupt */
  RESERVED730_IRQn             = 714,              /**< Reserved interrupt */
  RESERVED731_IRQn             = 715,              /**< Reserved interrupt */
  RESERVED732_IRQn             = 716,              /**< Reserved interrupt */
  RESERVED733_IRQn             = 717,              /**< Reserved interrupt */
  RESERVED734_IRQn             = 718,              /**< Reserved interrupt */
  RESERVED735_IRQn             = 719,              /**< Reserved interrupt */
  RESERVED736_IRQn             = 720,              /**< Reserved interrupt */
  RESERVED737_IRQn             = 721,              /**< Reserved interrupt */
  RESERVED738_IRQn             = 722,              /**< Reserved interrupt */
  RESERVED739_IRQn             = 723,              /**< Reserved interrupt */
  RESERVED740_IRQn             = 724,              /**< Reserved interrupt */
  RESERVED741_IRQn             = 725,              /**< Reserved interrupt */
  RESERVED742_IRQn             = 726,              /**< Reserved interrupt */
  RESERVED743_IRQn             = 727,              /**< Reserved interrupt */
  RESERVED744_IRQn             = 728,              /**< Reserved interrupt */
  RESERVED745_IRQn             = 729,              /**< Reserved interrupt */
  RESERVED746_IRQn             = 730,              /**< Reserved interrupt */
  RESERVED747_IRQn             = 731,              /**< Reserved interrupt */
  RESERVED748_IRQn             = 732,              /**< Reserved interrupt */
  RESERVED749_IRQn             = 733,              /**< Reserved interrupt */
  RESERVED750_IRQn             = 734,              /**< Reserved interrupt */
  RESERVED751_IRQn             = 735,              /**< Reserved interrupt */
  RESERVED752_IRQn             = 736,              /**< Reserved interrupt */
  RESERVED753_IRQn             = 737,              /**< Reserved interrupt */
  RESERVED754_IRQn             = 738,              /**< Reserved interrupt */
  RESERVED755_IRQn             = 739,              /**< Reserved interrupt */
  RESERVED756_IRQn             = 740,              /**< Reserved interrupt */
  RESERVED757_IRQn             = 741,              /**< Reserved interrupt */
  RESERVED758_IRQn             = 742,              /**< Reserved interrupt */
  RESERVED759_IRQn             = 743,              /**< Reserved interrupt */
  RESERVED760_IRQn             = 744,              /**< Reserved interrupt */
  RESERVED761_IRQn             = 745,              /**< Reserved interrupt */
  RESERVED762_IRQn             = 746,              /**< Reserved interrupt */
  RESERVED763_IRQn             = 747,              /**< Reserved interrupt */
  DMA5_4_0_1_IRQn              = 748,              /**< CAMERAMIX EDMA channel 0 interrupt */
  DMA5_4_2_3_IRQn              = 749,              /**< CAMERAMIX EDMA channel 2 interrupt */
  DMA5_4_4_5_IRQn              = 750,              /**< CAMERAMIX EDMA channel 4 interrupt */
  DMA5_4_6_7_IRQn              = 751,              /**< CAMERAMIX EDMA channel 6 interrupt */
  DMA5_4_8_9_IRQn              = 752,              /**< CAMERAMIX EDMA channel 8 interrupt */
  DMA5_4_10_11_IRQn            = 753,              /**< CAMERAMIX EDMA channel 10 interrupt */
  DMA5_4_12_13_IRQn            = 754,              /**< CAMERAMIX EDMA channel 12 interrupt */
  DMA5_4_14_15_IRQn            = 755,              /**< CAMERAMIX EDMA channel 14 interrupt */
  DMA5_4_16_17_IRQn            = 756,              /**< CAMERAMIX EDMA channel 16 interrupt */
  DMA5_4_18_19_IRQn            = 757,              /**< CAMERAMIX EDMA channel 18 interrupt */
  DMA5_4_20_21_IRQn            = 758,              /**< CAMERAMIX EDMA channel 20 interrupt */
  DMA5_4_22_23_IRQn            = 759,              /**< CAMERAMIX EDMA channel 22 interrupt */
  DMA5_4_24_25_IRQn            = 760,              /**< CAMERAMIX EDMA channel 24 interrupt */
  DMA5_4_26_27_IRQn            = 761,              /**< CAMERAMIX EDMA channel 26 interrupt */
  DMA5_4_28_29_IRQn            = 762,              /**< CAMERAMIX EDMA channel 28 interrupt */
  DMA5_4_30_31_IRQn            = 763,              /**< CAMERAMIX EDMA channel 30 interrupt */
  RESERVED780_IRQn             = 764,              /**< Reserved interrupt */
  RESERVED781_IRQn             = 765,              /**< Reserved interrupt */
  RESERVED782_IRQn             = 766,              /**< Reserved interrupt */
  RESERVED783_IRQn             = 767,              /**< Reserved interrupt */
  RESERVED784_IRQn             = 768,              /**< Reserved interrupt */
  RESERVED785_IRQn             = 769,              /**< Reserved interrupt */
  RESERVED786_IRQn             = 770,              /**< Reserved interrupt */
  RESERVED787_IRQn             = 771,              /**< Reserved interrupt */
  RESERVED788_IRQn             = 772,              /**< Reserved interrupt */
  RESERVED789_IRQn             = 773,              /**< Reserved interrupt */
  RESERVED790_IRQn             = 774,              /**< Reserved interrupt */
  RESERVED791_IRQn             = 775,              /**< Reserved interrupt */
  RESERVED792_IRQn             = 776,              /**< Reserved interrupt */
  RESERVED793_IRQn             = 777,              /**< Reserved interrupt */
  RESERVED794_IRQn             = 778,              /**< Reserved interrupt */
  RESERVED795_IRQn             = 779,              /**< Reserved interrupt */
  RESERVED796_IRQn             = 780,              /**< Reserved interrupt */
  RESERVED797_IRQn             = 781,              /**< Reserved interrupt */
  RESERVED798_IRQn             = 782,              /**< Reserved interrupt */
  RESERVED799_IRQn             = 783,              /**< Reserved interrupt */
  RESERVED800_IRQn             = 784,              /**< Reserved interrupt */
  RESERVED801_IRQn             = 785,              /**< Reserved interrupt */
  RESERVED802_IRQn             = 786,              /**< Reserved interrupt */
  RESERVED803_IRQn             = 787,              /**< Reserved interrupt */
  RESERVED804_IRQn             = 788,              /**< Reserved interrupt */
  RESERVED805_IRQn             = 789,              /**< Reserved interrupt */
  RESERVED806_IRQn             = 790,              /**< Reserved interrupt */
  RESERVED807_IRQn             = 791,              /**< Reserved interrupt */
  RESERVED808_IRQn             = 792,              /**< Reserved interrupt */
  RESERVED809_IRQn             = 793,              /**< Reserved interrupt */
  RESERVED810_IRQn             = 794,              /**< Reserved interrupt */
  RESERVED811_IRQn             = 795,              /**< Reserved interrupt */
  RESERVED812_IRQn             = 796,              /**< Reserved interrupt */
  RESERVED813_IRQn             = 797,              /**< Reserved interrupt */
  RESERVED814_IRQn             = 798,              /**< Reserved interrupt */
  RESERVED815_IRQn             = 799,              /**< Reserved interrupt */
  RESERVED816_IRQn             = 800,              /**< Reserved interrupt */
  RESERVED817_IRQn             = 801,              /**< Reserved interrupt */
  RESERVED818_IRQn             = 802,              /**< Reserved interrupt */
  RESERVED819_IRQn             = 803,              /**< Reserved interrupt */
  RESERVED820_IRQn             = 804,              /**< Reserved interrupt */
  RESERVED821_IRQn             = 805,              /**< Reserved interrupt */
  RESERVED822_IRQn             = 806,              /**< Reserved interrupt */
  RESERVED823_IRQn             = 807,              /**< Reserved interrupt */
  RESERVED824_IRQn             = 808,              /**< Reserved interrupt */
  RESERVED825_IRQn             = 809,              /**< Reserved interrupt */
  RESERVED826_IRQn             = 810,              /**< Reserved interrupt */
  RESERVED827_IRQn             = 811,              /**< Reserved interrupt */
  RESERVED828_IRQn             = 812,              /**< CAMERAMIX CSI Formatting Unit 1: Buffer overflow */
  RESERVED829_IRQn             = 813,              /**< CAMERAMIX CSI Formatting Unit 1: Interlaced Error */
  RESERVED830_IRQn             = 814,              /**< CAMERAMIX CSI Formatting Unit 1: Pixel Data Type Error */
  RESERVED831_IRQn             = 815,              /**< CAMERAMIX CSI Formatting Unit 2: Buffer overflow */
  RESERVED832_IRQn             = 816,              /**< CAMERAMIX CSI Formatting Unit 2: Interlaced Error */
  RESERVED833_IRQn             = 817,              /**< CAMERAMIX CSI Formatting Unit 2: Pixel Data Type Error */
  CSI1_IRQn                    = 818,              /**< CAMERAMIX CSI1 (Standalone MIPI-CSI) interrupt */
  CSI2_IRQn                    = 819,              /**< CAMERAMIX CSI2 (Combo MIPI-CSI/DSI) interrupt */
  ASRC1_IRQn                   = 820,              /**< mirq_asrc1_b */
  RESERVED837_IRQn             = 821,              /**< Reserved interrupt */
  RESERVED838_IRQn             = 822,              /**< Reserved interrupt */
  RESERVED839_IRQn             = 823,              /**< Reserved interrupt */
  RESERVED840_IRQn             = 824,              /**< Reserved interrupt */
  RESERVED841_IRQn             = 825,              /**< Reserved interrupt */
  RESERVED842_IRQn             = 826,              /**< Reserved interrupt */
  RESERVED843_IRQn             = 827,              /**< Reserved interrupt */
  RESERVED844_IRQn             = 828,              /**< Reserved interrupt */
  RESERVED845_IRQn             = 829,              /**< Reserved interrupt */
  RESERVED846_IRQn             = 830,              /**< Reserved interrupt */
  RESERVED847_IRQn             = 831,              /**< Reserved interrupt */
  RESERVED848_IRQn             = 832,              /**< Reserved interrupt */
  RESERVED849_IRQn             = 833,              /**< Reserved interrupt */
  RESERVED850_IRQn             = 834,              /**< Reserved interrupt */
  RESERVED851_IRQn             = 835,              /**< Reserved interrupt */
  RESERVED852_IRQn             = 836,              /**< Reserved interrupt */
  RESERVED853_IRQn             = 837,              /**< Reserved interrupt */
  RESERVED854_IRQn             = 838,              /**< Reserved interrupt */
  RESERVED855_IRQn             = 839,              /**< Reserved interrupt */
  RESERVED856_IRQn             = 840,              /**< Reserved interrupt */
  RESERVED857_IRQn             = 841,              /**< Reserved interrupt */
  RESERVED858_IRQn             = 842,              /**< Reserved interrupt */
  RESERVED859_IRQn             = 843,              /**< Reserved interrupt */
  RESERVED860_IRQn             = 844,              /**< Reserved interrupt */
  RESERVED861_IRQn             = 845,              /**< Reserved interrupt */
  RESERVED862_IRQn             = 846,              /**< Reserved interrupt */
  RESERVED863_IRQn             = 847,              /**< Reserved interrupt */
  RESERVED864_IRQn             = 848,              /**< Reserved interrupt */
  RESERVED865_IRQn             = 849,              /**< Reserved interrupt */
  RESERVED866_IRQn             = 850,              /**< Reserved interrupt */
  RESERVED867_IRQn             = 851,              /**< Reserved interrupt */
  RESERVED868_IRQn             = 852,              /**< Reserved interrupt */
  RESERVED869_IRQn             = 853,              /**< Reserved interrupt */
  RESERVED870_IRQn             = 854,              /**< Reserved interrupt */
  RESERVED871_IRQn             = 855,              /**< Reserved interrupt */
  RESERVED872_IRQn             = 856,              /**< Reserved interrupt */
  RESERVED873_IRQn             = 857,              /**< Reserved interrupt */
  RESERVED874_IRQn             = 858,              /**< Reserved interrupt */
  RESERVED875_IRQn             = 859,              /**< Reserved interrupt */
  RESERVED876_IRQn             = 860,              /**< Reserved interrupt */
  RESERVED877_IRQn             = 861,              /**< Reserved interrupt */
  RESERVED878_IRQn             = 862,              /**< Reserved interrupt */
  RESERVED879_IRQn             = 863,              /**< Reserved interrupt */
  RESERVED880_IRQn             = 864,              /**< Reserved interrupt */
  RESERVED881_IRQn             = 865,              /**< Reserved interrupt */
  RESERVED882_IRQn             = 866,              /**< Reserved interrupt */
  RESERVED883_IRQn             = 867,              /**< Reserved interrupt */
  RESERVED884_IRQn             = 868,              /**< Reserved interrupt */
  RESERVED885_IRQn             = 869,              /**< Reserved interrupt */
  RESERVED886_IRQn             = 870,              /**< Reserved interrupt */
  RESERVED887_IRQn             = 871,              /**< Reserved interrupt */
  RESERVED888_IRQn             = 872,              /**< Reserved interrupt */
  RESERVED889_IRQn             = 873,              /**< Reserved interrupt */
  RESERVED890_IRQn             = 874,              /**< Reserved interrupt */
  RESERVED891_IRQn             = 875,              /**< Reserved interrupt */
  ASRC2_IRQn                   = 876,              /**< mirq_asrc2_b */
  RESERVED893_IRQn             = 877,              /**< Reserved interrupt */
  RESERVED894_IRQn             = 878,              /**< Reserved interrupt */
  RESERVED895_IRQn             = 879,              /**< Reserved interrupt */
  RESERVED896_IRQn             = 880,              /**< Reserved interrupt */
  RESERVED897_IRQn             = 881,              /**< Reserved interrupt */
  RESERVED898_IRQn             = 882,              /**< Reserved interrupt */
  NOC_VPU_IRQn                 = 883,              /**< Reserved interrupt */
  NOC_DISPLAY_IRQn             = 884,              /**< Reserved interrupt */
  NOC_CAMERA_IRQn              = 885,              /**< Reserved interrupt */
  NOC_HSIO_IRQn                = 886,              /**< Reserved interrupt */
  NOC_WAKEUP_IRQn              = 887,              /**< Reserved interrupt */
  NOC_CENTRAL_IRQn             = 888,              /**< Reserved interrupt */
  ERM_DISPLAY_IRQn             = 889,              /**< DISPLAYMIX ERM Single bit corrected ECC Error */
  RESERVED906_IRQn             = 890,              /**< Reserved */
  SAI6_IRQn                    = 891,              /**< WAKEUPMIX SAI TX interrupt */
  RESERVED908_IRQn             = 892,              /**< Reserved interrupt */
  RESERVED909_IRQn             = 893,              /**< Reserved interrupt */
  RESERVED910_IRQn             = 894,              /**< Reserved interrupt */
  RESERVED911_IRQn             = 895,              /**< Reserved interrupt */
  RESERVED912_IRQn             = 896,              /**< Reserved interrupt */
  RESERVED913_IRQn             = 897,              /**< Reserved interrupt */
  RESERVED914_IRQn             = 898,              /**< Reserved interrupt */
  RESERVED915_IRQn             = 899,              /**< Reserved interrupt */
  RESERVED916_IRQn             = 900,              /**< Reserved interrupt */
  RESERVED917_IRQn             = 901,              /**< Reserved interrupt */
  RESERVED918_IRQn             = 902,              /**< Reserved interrupt */
  RESERVED919_IRQn             = 903,              /**< Reserved interrupt */
  RESERVED920_IRQn             = 904,              /**< Reserved interrupt */
  RESERVED921_IRQn             = 905,              /**< Reserved interrupt */
  RESERVED922_IRQn             = 906,              /**< Reserved interrupt */
  RESERVED923_IRQn             = 907,              /**< Reserved interrupt */
  RESERVED924_IRQn             = 908,              /**< Reserved interrupt */
  RESERVED925_IRQn             = 909,              /**< Reserved interrupt */
  RESERVED926_IRQn             = 910,              /**< Reserved interrupt */
  RESERVED927_IRQn             = 911,              /**< Reserved interrupt */
  RESERVED928_IRQn             = 912,              /**< Reserved interrupt */
  RESERVED929_IRQn             = 913,              /**< Reserved interrupt */
  RESERVED930_IRQn             = 914,              /**< Reserved interrupt */
  RESERVED931_IRQn             = 915,              /**< Reserved interrupt */
  RESERVED932_IRQn             = 916,              /**< Reserved interrupt */
  RESERVED933_IRQn             = 917,              /**< Reserved interrupt */
  RESERVED934_IRQn             = 918,              /**< Reserved interrupt */
  RESERVED935_IRQn             = 919,              /**< Reserved interrupt */
  RESERVED936_IRQn             = 920,              /**< Reserved interrupt */
  RESERVED937_IRQn             = 921,              /**< Reserved interrupt */
  RESERVED938_IRQn             = 922,              /**< Reserved interrupt */
  RESERVED939_IRQn             = 923,              /**< Reserved interrupt */
  RESERVED940_IRQn             = 924,              /**< Reserved interrupt */
  RESERVED941_IRQn             = 925,              /**< Reserved interrupt */
  RESERVED942_IRQn             = 926,              /**< Reserved interrupt */
  RESERVED943_IRQn             = 927,              /**< Reserved interrupt */
  RESERVED944_IRQn             = 928,              /**< Reserved interrupt */
  RESERVED945_IRQn             = 929,              /**< Reserved interrupt */
  RESERVED946_IRQn             = 930,              /**< Reserved interrupt */
  RESERVED947_IRQn             = 931,              /**< Reserved interrupt */
  RESERVED948_IRQn             = 932,              /**< Reserved interrupt */
  RESERVED949_IRQn             = 933,              /**< Reserved interrupt */
  RESERVED950_IRQn             = 934,              /**< Reserved interrupt */
  RESERVED951_IRQn             = 935,              /**< Reserved interrupt */
  RESERVED952_IRQn             = 936,              /**< Reserved interrupt */
  RESERVED953_IRQn             = 937,              /**< Reserved interrupt */
  RESERVED954_IRQn             = 938,              /**< Reserved interrupt */
  RESERVED955_IRQn             = 939,              /**< Reserved interrupt */
  XSPI1_0_IRQn                 = 940,              /**< xspi1 all interrupts ORed output for EENV0 (MEENV) */
  XSPI1_1_IRQn                 = 941,              /**< xspi1 all interrupts ORed output for EENV1 (MEENV) */
  XSPI1_2_IRQn                 = 942,              /**< xspi1 all interrupts ORed output for EENV2 (MEENV) */
  XSPI1_3_IRQn                 = 943,              /**< xspi1 all interrupts ORed output for EENV3 (MEENV) */
  XSPI1_4_IRQn                 = 944,              /**< xspi1 all interrupts ORed output for EENV4 (MEENV) */
  RESERVED961_IRQn             = 945,              /**< Anamix Gllitch Detector output (da_ip_voltage_glitch_detector_cln16ffc). It's a latch signal. It can be cleared.  Positive polarity i.e interrupt is generated when 0-->1 */
  RESERVED962_IRQn             = 946,              /**< Anamix VDET output (da_ip_vdetect_c16ffc). Detects high threshold on Core supply. It's a latch signal. It can be cleared.  Positive polarity i.e interrupt is generated when 0-->1 */
  CCM_IRQn                     = 947,              /**< LPCG Timeout interrupt generated by CCGR (CCM) */
  MU_D1_IRQn                   = 948,              /**< DISPLAYMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_D2_IRQn                   = 949,              /**< DISPLAYMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  GPT2_IRQn                    = 950,              /**< WAKEUPMIX GPT2 interrupt */
  GPT3_IRQn                    = 951,              /**< WAKEUPMIX GPT2 interrupt */
  GPT4_IRQn                    = 952,              /**< WAKEUPMIX GPT2 interrupt */
  GPT5_IRQn                    = 953,              /**< WAKEUPMIX GPT2 interrupt */
  LPSPI9_IRQn                  = 954               /**< DISPLAYMIX LPSPI interrupt */
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
#include "system_MIMX95294_cm7.h"      /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMX95294_cm7_SERIES
#define MIMX95294_cm7_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMX95294_cm7_features.h"

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup asrc_clock_source_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief The ASRC clock source
 */
typedef enum _asrc_clock_source
{
    kASRC_ClockSourceNotAvalible    = -1,          /**< not avalible */
    kASRC_ClockSourceBitClock0_AUD_PLL_DIV_CLK0 = 0U,       /**< SAI1 TX */
    kASRC_ClockSourceBitClock1_AUD_PLL_DIV_CLK1 = 1U,       /**< SAI1 RX */
    kASRC_ClockSourceBitClock2_MCLKOUT_0 = 2U,       /**< SAI2 TX */
    kASRC_ClockSourceBitClock3_MCLKOUT_1 = 3U,       /**< SAI2 RX */
    kASRC_ClockSourceBitClock4_SAI1_RX = 4U,       /**< SAI3 TX */
    kASRC_ClockSourceBitClock5_SAI1_TX = 5U,       /**< SAI3 RX */
    kASRC_ClockSourceBitClock6_SAI2_RX = 6U,       /**< SAI4 TX */
    kASRC_ClockSourceBitClock7_SAI2_TX = 7U,       /**< SAI4 RX */
    kASRC_ClockSourceBitClock8_SAI3_RX = 8U,      /**< SPDIF TX */
    kASRC_ClockSourceBitClock9_SAI3_TX = 9U,      /**< SPDIF RX */
    kASRC_ClockSourceBitClocka_SAI4_RX = 10U, /**< SAI2 CLOCK ROOT */
    kASRC_ClockSourceBitClockb_SAI4_TX = 11U, /**< SAI3 CLOCK ROOT */
    kASRC_ClockSourceBitClockc_SAI5_RX = 12U, /**< SAI4 CLOCK ROOT */
    kASRC_ClockSourceBitClockd_SAI5_TX = 13U, /**< MIC CLOCK ROOT */
    kASRC_ClockSourceMax = 13U, /**< Max CLOCK ROOT */
} asrc_clock_source_t;

/* @} */


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC base address */
#define ADC_BASE                                 (0x44530000u)
/** Peripheral ADC base pointer */
#define ADC                                      ((ADC_Type *)ADC_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC }

/* ANALOG_TRGMUX - Peripheral instance base addresses */
/** Peripheral ANALOG__TRGMUX base address */
#define ANALOG__TRGMUX_BASE                      (0x44531000u)
/** Peripheral ANALOG__TRGMUX base pointer */
#define ANALOG__TRGMUX                           ((ANALOG_TRGMUX_Type *)ANALOG__TRGMUX_BASE)
/** Array initializer of ANALOG_TRGMUX peripheral base addresses */
#define ANALOG_TRGMUX_BASE_ADDRS                 { ANALOG__TRGMUX_BASE }
/** Array initializer of ANALOG_TRGMUX peripheral base pointers */
#define ANALOG_TRGMUX_BASE_PTRS                  { ANALOG__TRGMUX }

/* ANALOG_VDET - Peripheral instance base addresses */
/** Peripheral ANALOG__VDET base address */
#define ANALOG__VDET_BASE                        (0x44486000u)
/** Peripheral ANALOG__VDET base pointer */
#define ANALOG__VDET                             ((ANALOG_VDET_Type *)ANALOG__VDET_BASE)
/** Array initializer of ANALOG_VDET peripheral base addresses */
#define ANALOG_VDET_BASE_ADDRS                   { ANALOG__VDET_BASE }
/** Array initializer of ANALOG_VDET peripheral base pointers */
#define ANALOG_VDET_BASE_PTRS                    { ANALOG__VDET }

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

/* AON_SYSPM - Peripheral instance base addresses */
/** Peripheral AON__M33_PCF1 base address */
#define AON__M33_PCF1_BASE                       (0x443E0000u)
/** Peripheral AON__M33_PCF1 base pointer */
#define AON__M33_PCF1                            ((AON_SYSPM_Type *)AON__M33_PCF1_BASE)
/** Peripheral AON__M33_PSF2 base address */
#define AON__M33_PSF2_BASE                       (0x443F0000u)
/** Peripheral AON__M33_PSF2 base pointer */
#define AON__M33_PSF2                            ((AON_SYSPM_Type *)AON__M33_PSF2_BASE)
/** Array initializer of AON_SYSPM peripheral base addresses */
#define AON_SYSPM_BASE_ADDRS                     { AON__M33_PCF1_BASE, AON__M33_PSF2_BASE }
/** Array initializer of AON_SYSPM peripheral base pointers */
#define AON_SYSPM_BASE_PTRS                      { AON__M33_PCF1, AON__M33_PSF2 }

/* ARDB - Peripheral instance base addresses */
/** Peripheral WAKEUP__XSPI1__ARDB base address */
#define WAKEUP__XSPI1__ARDB_BASE                 (0x47420000u)
/** Peripheral WAKEUP__XSPI1__ARDB base pointer */
#define WAKEUP__XSPI1__ARDB                      ((ARDB_Type *)WAKEUP__XSPI1__ARDB_BASE)
/** Array initializer of ARDB peripheral base addresses */
#define ARDB_BASE_ADDRS                          { WAKEUP__XSPI1__ARDB_BASE }
/** Array initializer of ARDB peripheral base pointers */
#define ARDB_BASE_PTRS                           { WAKEUP__XSPI1__ARDB }

/* ASRC - Peripheral instance base addresses */
/** Peripheral ASRC1 base address */
#define ASRC1_BASE                               (0x43000000u)
/** Peripheral ASRC1 base pointer */
#define ASRC1                                    ((ASRC_Type *)ASRC1_BASE)
/** Peripheral ASRC2 base address */
#define ASRC2_BASE                               (0x430F0000u)
/** Peripheral ASRC2 base pointer */
#define ASRC2                                    ((ASRC_Type *)ASRC2_BASE)
/** Array initializer of ASRC peripheral base addresses */
#define ASRC_BASE_ADDRS                          { ASRC1_BASE, ASRC2_BASE }
/** Array initializer of ASRC peripheral base pointers */
#define ASRC_BASE_PTRS                           { ASRC1, ASRC2 }
/** Interrupt vectors for the ASRC peripheral type */
#define ASRC_IRQS                                { ASRC1_IRQn, ASRC2_IRQn }

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
/** Peripheral BBSM__BLK_CTRL_BBSMMIX_BBSMMIX1 base address */
#define BBSM__BLK_CTRL_BBSMMIX_BBSMMIX1_BASE     (0x44410000u)
/** Peripheral BBSM__BLK_CTRL_BBSMMIX_BBSMMIX1 base pointer */
#define BBSM__BLK_CTRL_BBSMMIX_BBSMMIX1          ((BBSM_BLK_CTRL_BBSMMIX_Type *)BBSM__BLK_CTRL_BBSMMIX_BBSMMIX1_BASE)
/** Array initializer of BBSM_BLK_CTRL_BBSMMIX peripheral base addresses */
#define BBSM_BLK_CTRL_BBSMMIX_BASE_ADDRS         { BBSM__BLK_CTRL_BBSMMIX_BBSMMIX1_BASE }
/** Array initializer of BBSM_BLK_CTRL_BBSMMIX peripheral base pointers */
#define BBSM_BLK_CTRL_BBSMMIX_BASE_PTRS          { BBSM__BLK_CTRL_BBSMMIX_BBSMMIX1 }

/* BLK_CTRL_CAMERAMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_CAMERAMIX base address */
#define BLK_CTRL_CAMERAMIX_BASE                  (0x4AC10000u)
/** Peripheral BLK_CTRL_CAMERAMIX base pointer */
#define BLK_CTRL_CAMERAMIX                       ((BLK_CTRL_CAMERAMIX_Type *)BLK_CTRL_CAMERAMIX_BASE)
/** Array initializer of BLK_CTRL_CAMERAMIX peripheral base addresses */
#define BLK_CTRL_CAMERAMIX_BASE_ADDRS            { BLK_CTRL_CAMERAMIX_BASE }
/** Array initializer of BLK_CTRL_CAMERAMIX peripheral base pointers */
#define BLK_CTRL_CAMERAMIX_BASE_PTRS             { BLK_CTRL_CAMERAMIX }

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
#define BLK_CTRL_WAKEUPMIX_BASE                  (0x42040000u)
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
/** Array initializer of CACHE_ECC_MCM peripheral base addresses */
#define CACHE_ECC_MCM_BASE_ADDRS                 { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE }
/** Array initializer of CACHE_ECC_MCM peripheral base pointers */
#define CACHE_ECC_MCM_BASE_PTRS                  { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM }

/* CAMERA_DSI_CAMID_CSR - Peripheral instance base addresses */
/** Peripheral CAMERA__DSI_CAMID_CSR base address */
#define CAMERA__DSI_CAMID_CSR_BASE               (0x4ADE0000u)
/** Peripheral CAMERA__DSI_CAMID_CSR base pointer */
#define CAMERA__DSI_CAMID_CSR                    ((CAMERA_DSI_CAMID_CSR_Type *)CAMERA__DSI_CAMID_CSR_BASE)
/** Array initializer of CAMERA_DSI_CAMID_CSR peripheral base addresses */
#define CAMERA_DSI_CAMID_CSR_BASE_ADDRS          { CAMERA__DSI_CAMID_CSR_BASE }
/** Array initializer of CAMERA_DSI_CAMID_CSR peripheral base pointers */
#define CAMERA_DSI_CAMID_CSR_BASE_PTRS           { CAMERA__DSI_CAMID_CSR }

/* CAMERA_LSTCU - Peripheral instance base addresses */
/** Peripheral CAMERA__LSTCU base address */
#define CAMERA__LSTCU_BASE                       (0x4AF20000u)
/** Peripheral CAMERA__LSTCU base pointer */
#define CAMERA__LSTCU                            ((CAMERA_LSTCU_Type *)CAMERA__LSTCU_BASE)
/** Array initializer of CAMERA_LSTCU peripheral base addresses */
#define CAMERA_LSTCU_BASE_ADDRS                  { CAMERA__LSTCU_BASE }
/** Array initializer of CAMERA_LSTCU peripheral base pointers */
#define CAMERA_LSTCU_BASE_PTRS                   { CAMERA__LSTCU }

/* CAMERA_OCRAM_MECC - Peripheral instance base addresses */
/** Peripheral CAMERA__OCRAM_MECC base address */
#define CAMERA__OCRAM_MECC_BASE                  (0x4ADD0000u)
/** Peripheral CAMERA__OCRAM_MECC base pointer */
#define CAMERA__OCRAM_MECC                       ((CAMERA_OCRAM_MECC_Type *)CAMERA__OCRAM_MECC_BASE)
/** Array initializer of CAMERA_OCRAM_MECC peripheral base addresses */
#define CAMERA_OCRAM_MECC_BASE_ADDRS             { CAMERA__OCRAM_MECC_BASE }
/** Array initializer of CAMERA_OCRAM_MECC peripheral base pointers */
#define CAMERA_OCRAM_MECC_BASE_PTRS              { CAMERA__OCRAM_MECC }

/* CAMERA_PHY_CSR - Peripheral instance base addresses */
/** Peripheral CAMERA__PHY_CSR base address */
#define CAMERA__PHY_CSR_BASE                     (0x4AD20000u)
/** Peripheral CAMERA__PHY_CSR base pointer */
#define CAMERA__PHY_CSR                          ((CAMERA_PHY_CSR_Type *)CAMERA__PHY_CSR_BASE)
/** Array initializer of CAMERA_PHY_CSR peripheral base addresses */
#define CAMERA_PHY_CSR_BASE_ADDRS                { CAMERA__PHY_CSR_BASE }
/** Array initializer of CAMERA_PHY_CSR peripheral base pointers */
#define CAMERA_PHY_CSR_BASE_PTRS                 { CAMERA__PHY_CSR }

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN1 base address */
#define CAN1_BASE                                (0x443A0000u)
/** Peripheral CAN1 base pointer */
#define CAN1                                     ((CAN_Type *)CAN1_BASE)
/** Peripheral CAN2 base address */
#define CAN2_BASE                                (0x421D0000u)
/** Peripheral CAN2 base pointer */
#define CAN2                                     ((CAN_Type *)CAN2_BASE)
/** Peripheral CAN3 base address */
#define CAN3_BASE                                (0x42220000u)
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

/* CCM - Peripheral instance base addresses */
/** Peripheral CCM_CTRL base address */
#define CCM_CTRL_BASE                            (0x44450000u)
/** Peripheral CCM_CTRL base pointer */
#define CCM_CTRL                                 ((CCM_Type *)CCM_CTRL_BASE)
/** Array initializer of CCM peripheral base addresses */
#define CCM_BASE_ADDRS                           { CCM_CTRL_BASE }
/** Array initializer of CCM peripheral base pointers */
#define CCM_BASE_PTRS                            { CCM_CTRL }

/* CMU - Peripheral instance base addresses */
/** Peripheral ANALOG_CMU0 base address */
#define ANALOG_CMU0_BASE                         (0x44670000u)
/** Peripheral ANALOG_CMU0 base pointer */
#define ANALOG_CMU0                              ((CMU_Type *)ANALOG_CMU0_BASE)
/** Peripheral AON_CMUA1 base address */
#define AON_CMUA1_BASE                           (0x44540000u)
/** Peripheral AON_CMUA1 base pointer */
#define AON_CMUA1                                ((CMU_Type *)AON_CMUA1_BASE)
/** Peripheral AON_CMUA2 base address */
#define AON_CMUA2_BASE                           (0x44650000u)
/** Peripheral AON_CMUA2 base pointer */
#define AON_CMUA2                                ((CMU_Type *)AON_CMUA2_BASE)
/** Peripheral DDRC_CMU1 base address */
#define DDRC_CMU1_BASE                           (0x4E060000u)
/** Peripheral DDRC_CMU1 base pointer */
#define DDRC_CMU1                                ((CMU_Type *)DDRC_CMU1_BASE)
/** Peripheral DDRC_CMU2 base address */
#define DDRC_CMU2_BASE                           (0x4E070000u)
/** Peripheral DDRC_CMU2 base pointer */
#define DDRC_CMU2                                ((CMU_Type *)DDRC_CMU2_BASE)
/** Peripheral M7_CMUM0 base address */
#define M7_CMUM0_BASE                            (0x4A080000u)
/** Peripheral M7_CMUM0 base pointer */
#define M7_CMUM0                                 ((CMU_Type *)M7_CMUM0_BASE)
/** Peripheral M7_CMUM1 base address */
#define M7_CMUM1_BASE                            (0x4A090000u)
/** Peripheral M7_CMUM1 base pointer */
#define M7_CMUM1                                 ((CMU_Type *)M7_CMUM1_BASE)
/** Peripheral NOC_CMUN0 base address */
#define NOC_CMUN0_BASE                           (0x49070000u)
/** Peripheral NOC_CMUN0 base pointer */
#define NOC_CMUN0                                ((CMU_Type *)NOC_CMUN0_BASE)
/** Peripheral NOC_CMUN1 base address */
#define NOC_CMUN1_BASE                           (0x49080000u)
/** Peripheral NOC_CMUN1 base pointer */
#define NOC_CMUN1                                ((CMU_Type *)NOC_CMUN1_BASE)
/** Peripheral WAKEUP_CMU1 base address */
#define WAKEUP_CMU1_BASE                         (0x42370000u)
/** Peripheral WAKEUP_CMU1 base pointer */
#define WAKEUP_CMU1                              ((CMU_Type *)WAKEUP_CMU1_BASE)
/** Peripheral WAKEUP_CMU2 base address */
#define WAKEUP_CMU2_BASE                         (0x423C0000u)
/** Peripheral WAKEUP_CMU2 base pointer */
#define WAKEUP_CMU2                              ((CMU_Type *)WAKEUP_CMU2_BASE)
/** Array initializer of CMU peripheral base addresses */
#define CMU_BASE_ADDRS                           { ANALOG_CMU0_BASE, AON_CMUA1_BASE, AON_CMUA2_BASE, DDRC_CMU1_BASE, DDRC_CMU2_BASE, M7_CMUM0_BASE, M7_CMUM1_BASE, NOC_CMUN0_BASE, NOC_CMUN1_BASE, WAKEUP_CMU1_BASE, WAKEUP_CMU2_BASE }
/** Array initializer of CMU peripheral base pointers */
#define CMU_BASE_PTRS                            { ANALOG_CMU0, AON_CMUA1, AON_CMUA2, DDRC_CMU1, DDRC_CMU2, M7_CMUM0, M7_CMUM1, NOC_CMUN0, NOC_CMUN1, WAKEUP_CMU1, WAKEUP_CMU2 }

/* CORTEXA_BLK_CTRL - Peripheral instance base addresses */
/** Peripheral CORTEXA__BLK_CTRL_CORTEXAMIX base address */
#define CORTEXA__BLK_CTRL_CORTEXAMIX_BASE        (0x4A410000u)
/** Peripheral CORTEXA__BLK_CTRL_CORTEXAMIX base pointer */
#define CORTEXA__BLK_CTRL_CORTEXAMIX             ((CORTEXA_BLK_CTRL_Type *)CORTEXA__BLK_CTRL_CORTEXAMIX_BASE)
/** Array initializer of CORTEXA_BLK_CTRL peripheral base addresses */
#define CORTEXA_BLK_CTRL_BASE_ADDRS              { CORTEXA__BLK_CTRL_CORTEXAMIX_BASE }
/** Array initializer of CORTEXA_BLK_CTRL peripheral base pointers */
#define CORTEXA_BLK_CTRL_BASE_PTRS               { CORTEXA__BLK_CTRL_CORTEXAMIX }

/* DDRC - Peripheral instance base addresses */
/** Peripheral DDRC base address */
#define DDRC_BASE                                (0x4E080000u)
/** Peripheral DDRC base pointer */
#define DDRC                                     ((DDRC_Type *)DDRC_BASE)
/** Array initializer of DDRC peripheral base addresses */
#define DDRC_BASE_ADDRS                          { DDRC_BASE }
/** Array initializer of DDRC peripheral base pointers */
#define DDRC_BASE_PTRS                           { DDRC }

/* DDR_BLK_CTRL_DDRMIX - Peripheral instance base addresses */
/** Peripheral DDRC__BLK_CTRL_DDRMIX base address */
#define DDRC__BLK_CTRL_DDRMIX_BASE               (0x4E010000u)
/** Peripheral DDRC__BLK_CTRL_DDRMIX base pointer */
#define DDRC__BLK_CTRL_DDRMIX                    ((DDR_BLK_CTRL_DDRMIX_Type *)DDRC__BLK_CTRL_DDRMIX_BASE)
/** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base addresses */
#define DDR_BLK_CTRL_DDRMIX_BASE_ADDRS           { DDRC__BLK_CTRL_DDRMIX_BASE }
/** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base pointers */
#define DDR_BLK_CTRL_DDRMIX_BASE_PTRS            { DDRC__BLK_CTRL_DDRMIX }

/* DDR_LSTCU - Peripheral instance base addresses */
/** Peripheral DDRC__LSTCU base address */
#define DDRC__LSTCU_BASE                         (0x4E050000u)
/** Peripheral DDRC__LSTCU base pointer */
#define DDRC__LSTCU                              ((DDR_LSTCU_Type *)DDRC__LSTCU_BASE)
/** Array initializer of DDR_LSTCU peripheral base addresses */
#define DDR_LSTCU_BASE_ADDRS                     { DDRC__LSTCU_BASE }
/** Array initializer of DDR_LSTCU peripheral base pointers */
#define DDR_LSTCU_BASE_PTRS                      { DDRC__LSTCU }

/* DISPLAY_BLK_CTRL_DISPLAYMIX - Peripheral instance base addresses */
/** Peripheral DISPLAY__BLK_CTRL_DISPLAYMIX base address */
#define DISPLAY__BLK_CTRL_DISPLAYMIX_BASE        (0x4B010000u)
/** Peripheral DISPLAY__BLK_CTRL_DISPLAYMIX base pointer */
#define DISPLAY__BLK_CTRL_DISPLAYMIX             ((DISPLAY_BLK_CTRL_DISPLAYMIX_Type *)DISPLAY__BLK_CTRL_DISPLAYMIX_BASE)
/** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base addresses */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_ADDRS   { DISPLAY__BLK_CTRL_DISPLAYMIX_BASE }
/** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base pointers */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_PTRS    { DISPLAY__BLK_CTRL_DISPLAYMIX }

/* DISPLAY_CM0_CSR - Peripheral instance base addresses */
/** Peripheral DISPLAY__CM0_CSR base address */
#define DISPLAY__CM0_CSR_BASE                    (0x4B070000u)
/** Peripheral DISPLAY__CM0_CSR base pointer */
#define DISPLAY__CM0_CSR                         ((DISPLAY_CM0_CSR_Type *)DISPLAY__CM0_CSR_BASE)
/** Array initializer of DISPLAY_CM0_CSR peripheral base addresses */
#define DISPLAY_CM0_CSR_BASE_ADDRS               { DISPLAY__CM0_CSR_BASE }
/** Array initializer of DISPLAY_CM0_CSR peripheral base pointers */
#define DISPLAY_CM0_CSR_BASE_PTRS                { DISPLAY__CM0_CSR }

/* DISPLAY_CMU - Peripheral instance base addresses */
/** Peripheral DISPLAY__CMU0 base address */
#define DISPLAY__CMU0_BASE                       (0x4B2B0000u)
/** Peripheral DISPLAY__CMU0 base pointer */
#define DISPLAY__CMU0                            ((DISPLAY_CMU_Type *)DISPLAY__CMU0_BASE)
/** Peripheral DISPLAY__CMU1 base address */
#define DISPLAY__CMU1_BASE                       (0x4B2C0000u)
/** Peripheral DISPLAY__CMU1 base pointer */
#define DISPLAY__CMU1                            ((DISPLAY_CMU_Type *)DISPLAY__CMU1_BASE)
/** Array initializer of DISPLAY_CMU peripheral base addresses */
#define DISPLAY_CMU_BASE_ADDRS                   { DISPLAY__CMU0_BASE, DISPLAY__CMU1_BASE }
/** Array initializer of DISPLAY_CMU peripheral base pointers */
#define DISPLAY_CMU_BASE_PTRS                    { DISPLAY__CMU0, DISPLAY__CMU1 }

/* DISPLAY_DSI_CSR - Peripheral instance base addresses */
/** Peripheral DISPLAY__DSI_CSR base address */
#define DISPLAY__DSI_CSR_BASE                    (0x4B0A0000u)
/** Peripheral DISPLAY__DSI_CSR base pointer */
#define DISPLAY__DSI_CSR                         ((DISPLAY_DSI_CSR_Type *)DISPLAY__DSI_CSR_BASE)
/** Array initializer of DISPLAY_DSI_CSR peripheral base addresses */
#define DISPLAY_DSI_CSR_BASE_ADDRS               { DISPLAY__DSI_CSR_BASE }
/** Array initializer of DISPLAY_DSI_CSR peripheral base pointers */
#define DISPLAY_DSI_CSR_BASE_PTRS                { DISPLAY__DSI_CSR }

/* DISPLAY_EIM - Peripheral instance base addresses */
/** Peripheral DISPLAY__EIM base address */
#define DISPLAY__EIM_BASE                        (0x4B2F0000u)
/** Peripheral DISPLAY__EIM base pointer */
#define DISPLAY__EIM                             ((DISPLAY_EIM_Type *)DISPLAY__EIM_BASE)
/** Array initializer of DISPLAY_EIM peripheral base addresses */
#define DISPLAY_EIM_BASE_ADDRS                   { DISPLAY__EIM_BASE }
/** Array initializer of DISPLAY_EIM peripheral base pointers */
#define DISPLAY_EIM_BASE_PTRS                    { DISPLAY__EIM }

/* DISPLAY_ERM - Peripheral instance base addresses */
/** Peripheral DISPLAY__ERM base address */
#define DISPLAY__ERM_BASE                        (0x4B2E0000u)
/** Peripheral DISPLAY__ERM base pointer */
#define DISPLAY__ERM                             ((DISPLAY_ERM_Type *)DISPLAY__ERM_BASE)
/** Array initializer of DISPLAY_ERM peripheral base addresses */
#define DISPLAY_ERM_BASE_ADDRS                   { DISPLAY__ERM_BASE }
/** Array initializer of DISPLAY_ERM peripheral base pointers */
#define DISPLAY_ERM_BASE_PTRS                    { DISPLAY__ERM }

/* DISPLAY_LPWDOG - Peripheral instance base addresses */
/** Peripheral DISPLAY__LPWDOG6 base address */
#define DISPLAY__LPWDOG6_BASE                    (0x4B2A0000u)
/** Peripheral DISPLAY__LPWDOG6 base pointer */
#define DISPLAY__LPWDOG6                         ((DISPLAY_LPWDOG_Type *)DISPLAY__LPWDOG6_BASE)
/** Array initializer of DISPLAY_LPWDOG peripheral base addresses */
#define DISPLAY_LPWDOG_BASE_ADDRS                { DISPLAY__LPWDOG6_BASE }
/** Array initializer of DISPLAY_LPWDOG peripheral base pointers */
#define DISPLAY_LPWDOG_BASE_PTRS                 { DISPLAY__LPWDOG6 }

/* DISPLAY_LSTCU - Peripheral instance base addresses */
/** Peripheral DISPLAY__LSTCU base address */
#define DISPLAY__LSTCU_BASE                      (0x4B2D0000u)
/** Peripheral DISPLAY__LSTCU base pointer */
#define DISPLAY__LSTCU                           ((DISPLAY_LSTCU_Type *)DISPLAY__LSTCU_BASE)
/** Array initializer of DISPLAY_LSTCU peripheral base addresses */
#define DISPLAY_LSTCU_BASE_ADDRS                 { DISPLAY__LSTCU_BASE }
/** Array initializer of DISPLAY_LSTCU peripheral base pointers */
#define DISPLAY_LSTCU_BASE_PTRS                  { DISPLAY__LSTCU }

/* DISPLAY_MIPI_DSI_PHY - Peripheral instance base addresses */
/** Peripheral DISPLAY__MIPI_DSI_PHY base address */
#define DISPLAY__MIPI_DSI_PHY_BASE               (0x4B110000u)
/** Peripheral DISPLAY__MIPI_DSI_PHY base pointer */
#define DISPLAY__MIPI_DSI_PHY                    ((DISPLAY_MIPI_DSI_PHY_Type *)DISPLAY__MIPI_DSI_PHY_BASE)
/** Array initializer of DISPLAY_MIPI_DSI_PHY peripheral base addresses */
#define DISPLAY_MIPI_DSI_PHY_BASE_ADDRS          { DISPLAY__MIPI_DSI_PHY_BASE }
/** Array initializer of DISPLAY_MIPI_DSI_PHY peripheral base pointers */
#define DISPLAY_MIPI_DSI_PHY_BASE_PTRS           { DISPLAY__MIPI_DSI_PHY }

/* DISPLAY_OCRAM_MECC - Peripheral instance base addresses */
/** Peripheral DISPLAY__OCRAM_MECC base address */
#define DISPLAY__OCRAM_MECC_BASE                 (0x4B0F0000u)
/** Peripheral DISPLAY__OCRAM_MECC base pointer */
#define DISPLAY__OCRAM_MECC                      ((DISPLAY_OCRAM_MECC_Type *)DISPLAY__OCRAM_MECC_BASE)
/** Array initializer of DISPLAY_OCRAM_MECC peripheral base addresses */
#define DISPLAY_OCRAM_MECC_BASE_ADDRS            { DISPLAY__OCRAM_MECC_BASE }
/** Array initializer of DISPLAY_OCRAM_MECC peripheral base pointers */
#define DISPLAY_OCRAM_MECC_BASE_PTRS             { DISPLAY__OCRAM_MECC }

/* DISPLAY_PIXEL_INTERLEAVER - Peripheral instance base addresses */
/** Peripheral DISPLAY__PIXEL_INTERLEAVER base address */
#define DISPLAY__PIXEL_INTERLEAVER_BASE          (0x4B0D0000u)
/** Peripheral DISPLAY__PIXEL_INTERLEAVER base pointer */
#define DISPLAY__PIXEL_INTERLEAVER               ((DISPLAY_PIXEL_INTERLEAVER_Type *)DISPLAY__PIXEL_INTERLEAVER_BASE)
/** Array initializer of DISPLAY_PIXEL_INTERLEAVER peripheral base addresses */
#define DISPLAY_PIXEL_INTERLEAVER_BASE_ADDRS     { DISPLAY__PIXEL_INTERLEAVER_BASE }
/** Array initializer of DISPLAY_PIXEL_INTERLEAVER peripheral base pointers */
#define DISPLAY_PIXEL_INTERLEAVER_BASE_PTRS      { DISPLAY__PIXEL_INTERLEAVER }

/* DISPLAY_SEERIS - Peripheral instance base addresses */
/** Peripheral DISPLAY_SEERIS base address */
#define DISPLAY_SEERIS_BASE                      (0x4B400000u)
/** Peripheral DISPLAY_SEERIS base pointer */
#define DISPLAY_SEERIS                           ((DISPLAY_SEERIS_Type *)DISPLAY_SEERIS_BASE)
/** Array initializer of DISPLAY_SEERIS peripheral base addresses */
#define DISPLAY_SEERIS_BASE_ADDRS                { DISPLAY_SEERIS_BASE }
/** Array initializer of DISPLAY_SEERIS peripheral base pointers */
#define DISPLAY_SEERIS_BASE_PTRS                 { DISPLAY_SEERIS }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA3 base address */
#define DMA3_BASE                                (0x44000000u)
/** Peripheral DMA3 base pointer */
#define DMA3                                     ((DMA_Type *)DMA3_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA3_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA3 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { DMA3_0_IRQn, DMA3_1_IRQn, DMA3_2_IRQn, DMA3_3_IRQn, DMA3_4_IRQn, DMA3_5_IRQn, DMA3_6_IRQn, DMA3_7_IRQn, DMA3_8_IRQn, DMA3_9_IRQn, DMA3_10_IRQn, DMA3_11_IRQn, DMA3_12_IRQn, DMA3_13_IRQn, DMA3_14_IRQn, DMA3_15_IRQn, DMA3_16_IRQn, DMA3_17_IRQn, DMA3_18_IRQn, DMA3_19_IRQn, DMA3_20_IRQn, DMA3_21_IRQn, DMA3_22_IRQn, DMA3_23_IRQn, DMA3_24_IRQn, DMA3_25_IRQn, DMA3_26_IRQn, DMA3_27_IRQn, DMA3_28_IRQn, DMA3_29_IRQn, DMA3_30_IRQn } }
#define DMA_ERROR_IRQS                           { { DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn } }

/* DMA5 - Peripheral instance base addresses */
/** Peripheral EDMA5_2 base address */
#define EDMA5_2_BASE                             (0x42800000u)
/** Peripheral EDMA5_2 base pointer */
#define EDMA5_2                                  ((DMA5_Type *)EDMA5_2_BASE)
/** Peripheral EDMA5_3 base address */
#define EDMA5_3_BASE                             (0x42A10000u)
/** Peripheral EDMA5_3 base pointer */
#define EDMA5_3                                  ((DMA5_Type *)EDMA5_3_BASE)
/** Peripheral EDMA5_4 base address */
#define EDMA5_4_BASE                             (0x4AE10000u)
/** Peripheral EDMA5_4 base pointer */
#define EDMA5_4                                  ((DMA5_Type *)EDMA5_4_BASE)
/** Array initializer of DMA5 peripheral base addresses */
#define DMA5_BASE_ADDRS                          { 0u, 0u, EDMA5_2_BASE, EDMA5_3_BASE, EDMA5_4_BASE }
/** Array initializer of DMA5 peripheral base pointers */
#define DMA5_BASE_PTRS                           { (DMA5_Type *)0u, (DMA5_Type *)0u, EDMA5_2, EDMA5_3, EDMA5_4 }

/* DOORBELLS - Peripheral instance base addresses */
/** Peripheral GPU__REG__DOORBELLS base address */
#define GPU__REG__DOORBELLS_BASE                 (0x4D980000u)
/** Peripheral GPU__REG__DOORBELLS base pointer */
#define GPU__REG__DOORBELLS                      ((DOORBELLS_Type *)GPU__REG__DOORBELLS_BASE)
/** Array initializer of DOORBELLS peripheral base addresses */
#define DOORBELLS_BASE_ADDRS                     { GPU__REG__DOORBELLS_BASE }
/** Array initializer of DOORBELLS peripheral base pointers */
#define DOORBELLS_BASE_PTRS                      { GPU__REG__DOORBELLS }

/* DPU_IRQSTEER - Peripheral instance base addresses */
/** Peripheral DPU_IRQSTEER base address */
#define DPU_IRQSTEER_BASE                        (0x4B0B0000u)
/** Peripheral DPU_IRQSTEER base pointer */
#define DPU_IRQSTEER                             ((DPU_IRQSTEER_Type *)DPU_IRQSTEER_BASE)
/** Array initializer of DPU_IRQSTEER peripheral base addresses */
#define DPU_IRQSTEER_BASE_ADDRS                  { DPU_IRQSTEER_BASE }
/** Array initializer of DPU_IRQSTEER peripheral base pointers */
#define DPU_IRQSTEER_BASE_PTRS                   { DPU_IRQSTEER }

/* DSI_V2_HOST_DSI - Peripheral instance base addresses */
/** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI base address */
#define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE (0x4B060200u)
/** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI base pointer */
#define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI  ((DSI_V2_HOST_DSI_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE)
/** Array initializer of DSI_V2_HOST_DSI peripheral base addresses */
#define DSI_V2_HOST_DSI_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE }
/** Array initializer of DSI_V2_HOST_DSI peripheral base pointers */
#define DSI_V2_HOST_DSI_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI }

/* DSI_V2_HOST_INT - Peripheral instance base addresses */
/** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT base address */
#define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE (0x4B060400u)
/** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT base pointer */
#define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT  ((DSI_V2_HOST_INT_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE)
/** Array initializer of DSI_V2_HOST_INT peripheral base addresses */
#define DSI_V2_HOST_INT_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE }
/** Array initializer of DSI_V2_HOST_INT peripheral base pointers */
#define DSI_V2_HOST_INT_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT }

/* DSI_V2_HOST_IPI - Peripheral instance base addresses */
/** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI base address */
#define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE (0x4B060300u)
/** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI base pointer */
#define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI  ((DSI_V2_HOST_IPI_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE)
/** Array initializer of DSI_V2_HOST_IPI peripheral base addresses */
#define DSI_V2_HOST_IPI_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE }
/** Array initializer of DSI_V2_HOST_IPI peripheral base pointers */
#define DSI_V2_HOST_IPI_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI }

/* DSI_V2_HOST_MAIN - Peripheral instance base addresses */
/** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN base address */
#define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE (0x4B060000u)
/** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN base pointer */
#define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN ((DSI_V2_HOST_MAIN_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE)
/** Array initializer of DSI_V2_HOST_MAIN peripheral base addresses */
#define DSI_V2_HOST_MAIN_BASE_ADDRS              { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE }
/** Array initializer of DSI_V2_HOST_MAIN peripheral base pointers */
#define DSI_V2_HOST_MAIN_BASE_PTRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN }

/* DSI_V2_HOST_PHY - Peripheral instance base addresses */
/** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY base address */
#define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE (0x4B060100u)
/** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY base pointer */
#define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY  ((DSI_V2_HOST_PHY_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE)
/** Array initializer of DSI_V2_HOST_PHY peripheral base addresses */
#define DSI_V2_HOST_PHY_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE }
/** Array initializer of DSI_V2_HOST_PHY peripheral base pointers */
#define DSI_V2_HOST_PHY_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY }

/* ENETC_GLOBAL - Peripheral instance base addresses */
/** Peripheral EMDIO_GLOBAL base address */
#define EMDIO_GLOBAL_BASE                        (0x4CCB0000u)
/** Peripheral EMDIO_GLOBAL base pointer */
#define EMDIO_GLOBAL                             ((ENETC_GLOBAL_Type *)EMDIO_GLOBAL_BASE)
/** Peripheral ENETC0_GLOBAL base address */
#define ENETC0_GLOBAL_BASE                       (0x4CC20000u)
/** Peripheral ENETC0_GLOBAL base pointer */
#define ENETC0_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC0_GLOBAL_BASE)
/** Peripheral ENETC1_GLOBAL base address */
#define ENETC1_GLOBAL_BASE                       (0x4CC60000u)
/** Peripheral ENETC1_GLOBAL base pointer */
#define ENETC1_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC1_GLOBAL_BASE)
/** Peripheral TMR0_GLOBAL base address */
#define TMR0_GLOBAL_BASE                         (0x4CC90000u)
/** Peripheral TMR0_GLOBAL base pointer */
#define TMR0_GLOBAL                              ((ENETC_GLOBAL_Type *)TMR0_GLOBAL_BASE)
/** Array initializer of ENETC_GLOBAL peripheral base addresses */
#define ENETC_GLOBAL_BASE_ADDRS                  { EMDIO_GLOBAL_BASE, ENETC0_GLOBAL_BASE, ENETC1_GLOBAL_BASE, TMR0_GLOBAL_BASE }
/** Array initializer of ENETC_GLOBAL peripheral base pointers */
#define ENETC_GLOBAL_BASE_PTRS                   { EMDIO_GLOBAL, ENETC0_GLOBAL, ENETC1_GLOBAL, TMR0_GLOBAL }

/* ENETC_PCI_TYPE0 - Peripheral instance base addresses */
/** Peripheral EMDIO0_PCI_HDR_TYPE0 base address */
#define EMDIO0_PCI_HDR_TYPE0_BASE                (0x4CA02000u)
/** Peripheral EMDIO0_PCI_HDR_TYPE0 base pointer */
#define EMDIO0_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)EMDIO0_PCI_HDR_TYPE0_BASE)
/** Peripheral ENETC0_PCI_HDR_TYPE0 base address */
#define ENETC0_PCI_HDR_TYPE0_BASE                (0x4CA00000u)
/** Peripheral ENETC0_PCI_HDR_TYPE0 base pointer */
#define ENETC0_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)ENETC0_PCI_HDR_TYPE0_BASE)
/** Peripheral ENETC1_PCI_HDR_TYPE0 base address */
#define ENETC1_PCI_HDR_TYPE0_BASE                (0x4CB00000u)
/** Peripheral ENETC1_PCI_HDR_TYPE0 base pointer */
#define ENETC1_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)ENETC1_PCI_HDR_TYPE0_BASE)
/** Peripheral TMR0_PCI_HDR_TYPE0 base address */
#define TMR0_PCI_HDR_TYPE0_BASE                  (0x4CA01000u)
/** Peripheral TMR0_PCI_HDR_TYPE0 base pointer */
#define TMR0_PCI_HDR_TYPE0                       ((ENETC_PCI_TYPE0_Type *)TMR0_PCI_HDR_TYPE0_BASE)
/** Array initializer of ENETC_PCI_TYPE0 peripheral base addresses */
#define ENETC_PCI_TYPE0_BASE_ADDRS               { EMDIO0_PCI_HDR_TYPE0_BASE, ENETC0_PCI_HDR_TYPE0_BASE, ENETC1_PCI_HDR_TYPE0_BASE, TMR0_PCI_HDR_TYPE0_BASE }
/** Array initializer of ENETC_PCI_TYPE0 peripheral base pointers */
#define ENETC_PCI_TYPE0_BASE_PTRS                { EMDIO0_PCI_HDR_TYPE0, ENETC0_PCI_HDR_TYPE0, ENETC1_PCI_HDR_TYPE0, TMR0_PCI_HDR_TYPE0 }

/* ENETC_PF_EMDIO - Peripheral instance base addresses */
/** Peripheral EMDIO_BASE base address */
#define EMDIO_BASE_BASE                          (0x4CCA0000u)
/** Peripheral EMDIO_BASE base pointer */
#define EMDIO_BASE                               ((ENETC_PF_EMDIO_Type *)EMDIO_BASE_BASE)
/** Array initializer of ENETC_PF_EMDIO peripheral base addresses */
#define ENETC_PF_EMDIO_BASE_ADDRS                { EMDIO_BASE_BASE }
/** Array initializer of ENETC_PF_EMDIO peripheral base pointers */
#define ENETC_PF_EMDIO_BASE_PTRS                 { EMDIO_BASE }

/* ENETC_PF_TMR - Peripheral instance base addresses */
/** Peripheral TMR0_BASE base address */
#define TMR0_BASE_BASE                           (0x4CC80000u)
/** Peripheral TMR0_BASE base pointer */
#define TMR0_BASE                                ((ENETC_PF_TMR_Type *)TMR0_BASE_BASE)
/** Array initializer of ENETC_PF_TMR peripheral base addresses */
#define ENETC_PF_TMR_BASE_ADDRS                  { TMR0_BASE_BASE }
/** Array initializer of ENETC_PF_TMR peripheral base pointers */
#define ENETC_PF_TMR_BASE_PTRS                   { TMR0_BASE }

/* ENETC_SI - Peripheral instance base addresses */
/** Peripheral ENETC0_PSI base address */
#define ENETC0_PSI_BASE                          (0x4CC00000u)
/** Peripheral ENETC0_PSI base pointer */
#define ENETC0_PSI                               ((ENETC_SI_Type *)ENETC0_PSI_BASE)
/** Peripheral ENETC1_PSI base address */
#define ENETC1_PSI_BASE                          (0x4CC40000u)
/** Peripheral ENETC1_PSI base pointer */
#define ENETC1_PSI                               ((ENETC_SI_Type *)ENETC1_PSI_BASE)
/** Peripheral ENETC_VSI0 base address */
#define ENETC_VSI0_BASE                          (0x4CCE0000u)
/** Peripheral ENETC_VSI0 base pointer */
#define ENETC_VSI0                               ((ENETC_SI_Type *)ENETC_VSI0_BASE)
/** Peripheral ENETC_VSI1 base address */
#define ENETC_VSI1_BASE                          (0x4CCF0000u)
/** Peripheral ENETC_VSI1 base pointer */
#define ENETC_VSI1                               ((ENETC_SI_Type *)ENETC_VSI1_BASE)
/** Array initializer of ENETC_SI peripheral base addresses */
#define ENETC_SI_BASE_ADDRS                      { ENETC0_PSI_BASE, ENETC1_PSI_BASE, ENETC_VSI0_BASE, ENETC_VSI1_BASE }
/** Array initializer of ENETC_SI peripheral base pointers */
#define ENETC_SI_BASE_PTRS                       { ENETC0_PSI, ENETC1_PSI, ENETC_VSI0, ENETC_VSI1 }

/* ENETC_VF_PCI_TYPE0 - Peripheral instance base addresses */
/** Peripheral NETC_VF1_PCI_HDR_TYPE0 base address */
#define NETC_VF1_PCI_HDR_TYPE0_BASE              (0x4CA40000u)
/** Peripheral NETC_VF1_PCI_HDR_TYPE0 base pointer */
#define NETC_VF1_PCI_HDR_TYPE0                   ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF1_PCI_HDR_TYPE0_BASE)
/** Peripheral NETC_VF2_PCI_HDR_TYPE0 base address */
#define NETC_VF2_PCI_HDR_TYPE0_BASE              (0x4CB40000u)
/** Peripheral NETC_VF2_PCI_HDR_TYPE0 base pointer */
#define NETC_VF2_PCI_HDR_TYPE0                   ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF2_PCI_HDR_TYPE0_BASE)
/** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base addresses */
#define ENETC_VF_PCI_TYPE0_BASE_ADDRS            { NETC_VF1_PCI_HDR_TYPE0_BASE, NETC_VF2_PCI_HDR_TYPE0_BASE }
/** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base pointers */
#define ENETC_VF_PCI_TYPE0_BASE_PTRS             { NETC_VF1_PCI_HDR_TYPE0, NETC_VF2_PCI_HDR_TYPE0 }

/* FLEXIO - Peripheral instance base addresses */
/** Peripheral FLEXIO1 base address */
#define FLEXIO1_BASE                             (0x421E0000u)
/** Peripheral FLEXIO1 base pointer */
#define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
/** Peripheral FLEXIO2 base address */
#define FLEXIO2_BASE                             (0x421F0000u)
/** Peripheral FLEXIO2 base pointer */
#define FLEXIO2                                  ((FLEXIO_Type *)FLEXIO2_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE, FLEXIO2_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1, FLEXIO2 }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { NotAvail_IRQn, FLEXIO1_IRQn, FLEXIO2_IRQn }

/* FRO - Peripheral instance base addresses */
/** Peripheral FRO base address */
#define FRO_BASE                                 (0x44485000u)
/** Peripheral FRO base pointer */
#define FRO                                      ((FRO_Type *)FRO_BASE)
/** Array initializer of FRO peripheral base addresses */
#define FRO_BASE_ADDRS                           { FRO_BASE }
/** Array initializer of FRO peripheral base pointers */
#define FRO_BASE_PTRS                            { FRO }

/* GPC - Peripheral instance base addresses */
/** Peripheral GPC_CTRL_CM33 base address */
#define GPC_CTRL_CM33_BASE                       (0x44470000u)
/** Peripheral GPC_CTRL_CM33 base pointer */
#define GPC_CTRL_CM33                            ((GPC_Type *)GPC_CTRL_CM33_BASE)
/** Peripheral GPC_CTRL_CM7 base address */
#define GPC_CTRL_CM7_BASE                        (0x44470800u)
/** Peripheral GPC_CTRL_CM7 base pointer */
#define GPC_CTRL_CM7                             ((GPC_Type *)GPC_CTRL_CM7_BASE)
/** Peripheral GPC_CTRL_CA55_0 base address */
#define GPC_CTRL_CA55_0_BASE                     (0x44471000u)
/** Peripheral GPC_CTRL_CA55_0 base pointer */
#define GPC_CTRL_CA55_0                          ((GPC_Type *)GPC_CTRL_CA55_0_BASE)
/** Peripheral GPC_CTRL_CA55_1 base address */
#define GPC_CTRL_CA55_1_BASE                     (0x44471800u)
/** Peripheral GPC_CTRL_CA55_1 base pointer */
#define GPC_CTRL_CA55_1                          ((GPC_Type *)GPC_CTRL_CA55_1_BASE)
/** Peripheral GPC_CTRL_CA55_2 base address */
#define GPC_CTRL_CA55_2_BASE                     (0x44472000u)
/** Peripheral GPC_CTRL_CA55_2 base pointer */
#define GPC_CTRL_CA55_2                          ((GPC_Type *)GPC_CTRL_CA55_2_BASE)
/** Peripheral GPC_CTRL_CA55_3 base address */
#define GPC_CTRL_CA55_3_BASE                     (0x44472800u)
/** Peripheral GPC_CTRL_CA55_3 base pointer */
#define GPC_CTRL_CA55_3                          ((GPC_Type *)GPC_CTRL_CA55_3_BASE)
/** Peripheral GPC_CTRL_CA55_CLUSTER base address */
#define GPC_CTRL_CA55_CLUSTER_BASE               (0x44473000u)
/** Peripheral GPC_CTRL_CA55_CLUSTER base pointer */
#define GPC_CTRL_CA55_CLUSTER                    ((GPC_Type *)GPC_CTRL_CA55_CLUSTER_BASE)
/** Array initializer of GPC peripheral base addresses */
#define GPC_BASE_ADDRS                           { GPC_CTRL_CM33_BASE, GPC_CTRL_CM7_BASE, GPC_CTRL_CA55_0_BASE, GPC_CTRL_CA55_1_BASE, GPC_CTRL_CA55_2_BASE, GPC_CTRL_CA55_3_BASE, 0u, 0u, GPC_CTRL_CA55_CLUSTER_BASE }
/** Array initializer of GPC peripheral base pointers */
#define GPC_BASE_PTRS                            { GPC_CTRL_CM33, GPC_CTRL_CM7, GPC_CTRL_CA55_0, GPC_CTRL_CA55_1, GPC_CTRL_CA55_2, GPC_CTRL_CA55_3, (GPC_Type *)0u, (GPC_Type *)0u, GPC_CTRL_CA55_CLUSTER }

/* GPC_GLOBAL - Peripheral instance base addresses */
/** Peripheral GPC_GLOBAL base address */
#define GPC_GLOBAL_BASE                          (0x44473800u)
/** Peripheral GPC_GLOBAL base pointer */
#define GPC_GLOBAL                               ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE)
/** Array initializer of GPC_GLOBAL peripheral base addresses */
#define GPC_GLOBAL_BASE_ADDRS                    { GPC_GLOBAL_BASE }
/** Array initializer of GPC_GLOBAL peripheral base pointers */
#define GPC_GLOBAL_BASE_PTRS                     { GPC_GLOBAL }

/* GPU_BLK_CTRL_GPUMIX - Peripheral instance base addresses */
/** Peripheral GPU__BLK_CTRL_GPUMIX base address */
#define GPU__BLK_CTRL_GPUMIX_BASE                (0x4D810000u)
/** Peripheral GPU__BLK_CTRL_GPUMIX base pointer */
#define GPU__BLK_CTRL_GPUMIX                     ((GPU_BLK_CTRL_GPUMIX_Type *)GPU__BLK_CTRL_GPUMIX_BASE)
/** Array initializer of GPU_BLK_CTRL_GPUMIX peripheral base addresses */
#define GPU_BLK_CTRL_GPUMIX_BASE_ADDRS           { GPU__BLK_CTRL_GPUMIX_BASE }
/** Array initializer of GPU_BLK_CTRL_GPUMIX peripheral base pointers */
#define GPU_BLK_CTRL_GPUMIX_BASE_PTRS            { GPU__BLK_CTRL_GPUMIX }

/* GPU_REGISTERS - Peripheral instance base addresses */
/** Peripheral GPU__REG__GPU_REGISTERS base address */
#define GPU__REG__GPU_REGISTERS_BASE             (0x4D900000u)
/** Peripheral GPU__REG__GPU_REGISTERS base pointer */
#define GPU__REG__GPU_REGISTERS                  ((GPU_REGISTERS_Type *)GPU__REG__GPU_REGISTERS_BASE)
/** Array initializer of GPU_REGISTERS peripheral base addresses */
#define GPU_REGISTERS_BASE_ADDRS                 { GPU__REG__GPU_REGISTERS_BASE }
/** Array initializer of GPU_REGISTERS peripheral base pointers */
#define GPU_REGISTERS_BASE_PTRS                  { GPU__REG__GPU_REGISTERS }

/* HSIO_ATU - Peripheral instance base addresses */
/** Peripheral HSIO__ATU base address */
#define HSIO__ATU_BASE                           (0x4C070000u)
/** Peripheral HSIO__ATU base pointer */
#define HSIO__ATU                                ((HSIO_ATU_Type *)HSIO__ATU_BASE)
/** Array initializer of HSIO_ATU peripheral base addresses */
#define HSIO_ATU_BASE_ADDRS                      { HSIO__ATU_BASE }
/** Array initializer of HSIO_ATU peripheral base pointers */
#define HSIO_ATU_BASE_PTRS                       { HSIO__ATU }

/* HSIO_BLK_CTRL_HSIOMIX - Peripheral instance base addresses */
/** Peripheral HSIO__BLK_CTRL_HSIOMIX base address */
#define HSIO__BLK_CTRL_HSIOMIX_BASE              (0x4C010000u)
/** Peripheral HSIO__BLK_CTRL_HSIOMIX base pointer */
#define HSIO__BLK_CTRL_HSIOMIX                   ((HSIO_BLK_CTRL_HSIOMIX_Type *)HSIO__BLK_CTRL_HSIOMIX_BASE)
/** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base addresses */
#define HSIO_BLK_CTRL_HSIOMIX_BASE_ADDRS         { HSIO__BLK_CTRL_HSIOMIX_BASE }
/** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base pointers */
#define HSIO_BLK_CTRL_HSIOMIX_BASE_PTRS          { HSIO__BLK_CTRL_HSIOMIX }

/* HSIO_GHZ_LN_PLL - Peripheral instance base addresses */
/** Peripheral HSIO__GHZ_LN_PLL base address */
#define HSIO__GHZ_LN_PLL_BASE                    (0x44481800u)
/** Peripheral HSIO__GHZ_LN_PLL base pointer */
#define HSIO__GHZ_LN_PLL                         ((HSIO_GHZ_LN_PLL_Type *)HSIO__GHZ_LN_PLL_BASE)
/** Array initializer of HSIO_GHZ_LN_PLL peripheral base addresses */
#define HSIO_GHZ_LN_PLL_BASE_ADDRS               { HSIO__GHZ_LN_PLL_BASE }
/** Array initializer of HSIO_GHZ_LN_PLL peripheral base pointers */
#define HSIO_GHZ_LN_PLL_BASE_PTRS                { HSIO__GHZ_LN_PLL }

/* I2S - Peripheral instance base addresses */
/** Peripheral SAI1 base address */
#define SAI1_BASE                                (0x443B0000u)
/** Peripheral SAI1 base pointer */
#define SAI1                                     ((I2S_Type *)SAI1_BASE)
/** Peripheral SAI2 base address */
#define SAI2_BASE                                (0x4C880000u)
/** Peripheral SAI2 base pointer */
#define SAI2                                     ((I2S_Type *)SAI2_BASE)
/** Peripheral SAI3 base address */
#define SAI3_BASE                                (0x433E0000u)
/** Peripheral SAI3 base pointer */
#define SAI3                                     ((I2S_Type *)SAI3_BASE)
/** Peripheral SAI4 base address */
#define SAI4_BASE                                (0x433F0000u)
/** Peripheral SAI4 base pointer */
#define SAI4                                     ((I2S_Type *)SAI4_BASE)
/** Peripheral SAI5 base address */
#define SAI5_BASE                                (0x43400000u)
/** Peripheral SAI5 base pointer */
#define SAI5                                     ((I2S_Type *)SAI5_BASE)
/** Peripheral SAI6 base address */
#define SAI6_BASE                                (0x43410000u)
/** Peripheral SAI6 base pointer */
#define SAI6                                     ((I2S_Type *)SAI6_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, SAI2_BASE, SAI3_BASE, SAI4_BASE, SAI5_BASE, SAI6_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, SAI2, SAI3, SAI4, SAI5, SAI6 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn, SAI4_IRQn, SAI5_IRQn, SAI6_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn, SAI4_IRQn, SAI5_IRQn, SAI6_IRQn }

/* I3C - Peripheral instance base addresses */
/** Peripheral I3C1 base address */
#define I3C1_BASE                                (0x44330000u)
/** Peripheral I3C1 base pointer */
#define I3C1                                     ((I3C_Type *)I3C1_BASE)
/** Peripheral I3C2 base address */
#define I3C2_BASE                                (0x42140000u)
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
/** Peripheral AON__IOMUXC0__IOMUXC_GPR base address */
#define AON__IOMUXC0__IOMUXC_GPR_BASE            (0x443D0000u)
/** Peripheral AON__IOMUXC0__IOMUXC_GPR base pointer */
#define AON__IOMUXC0__IOMUXC_GPR                 ((IOMUXC_GPR_Type *)AON__IOMUXC0__IOMUXC_GPR_BASE)
/** Array initializer of IOMUXC_GPR peripheral base addresses */
#define IOMUXC_GPR_BASE_ADDRS                    { AON__IOMUXC0__IOMUXC_GPR_BASE }
/** Array initializer of IOMUXC_GPR peripheral base pointers */
#define IOMUXC_GPR_BASE_PTRS                     { AON__IOMUXC0__IOMUXC_GPR }

/* IPA_CONTROL - Peripheral instance base addresses */
/** Peripheral GPU__REG__IPA_CONTROL base address */
#define GPU__REG__IPA_CONTROL_BASE               (0x4D940000u)
/** Peripheral GPU__REG__IPA_CONTROL base pointer */
#define GPU__REG__IPA_CONTROL                    ((IPA_CONTROL_Type *)GPU__REG__IPA_CONTROL_BASE)
/** Array initializer of IPA_CONTROL peripheral base addresses */
#define IPA_CONTROL_BASE_ADDRS                   { GPU__REG__IPA_CONTROL_BASE }
/** Array initializer of IPA_CONTROL peripheral base pointers */
#define IPA_CONTROL_BASE_PTRS                    { GPU__REG__IPA_CONTROL }

/* IRQSTEER - Peripheral instance base addresses */
/** Peripheral IRQSTEER base address */
#define IRQSTEER_BASE                            (0x44680000u)
/** Peripheral IRQSTEER base pointer */
#define IRQSTEER                                 ((IRQSTEER_Type *)IRQSTEER_BASE)
/** Array initializer of IRQSTEER peripheral base addresses */
#define IRQSTEER_BASE_ADDRS                      { IRQSTEER_BASE }
/** Array initializer of IRQSTEER peripheral base pointers */
#define IRQSTEER_BASE_PTRS                       { IRQSTEER }

/* ISI - Peripheral instance base addresses */
/** Peripheral CAMERA__ISI base address */
#define CAMERA__ISI_BASE                         (0x4AD50000u)
/** Peripheral CAMERA__ISI base pointer */
#define CAMERA__ISI                              ((ISI_Type *)CAMERA__ISI_BASE)
/** Array initializer of ISI peripheral base addresses */
#define ISI_BASE_ADDRS                           { CAMERA__ISI_BASE }
/** Array initializer of ISI peripheral base pointers */
#define ISI_BASE_PTRS                            { CAMERA__ISI }

/* JPEG_DEC - Peripheral instance base addresses */
/** Peripheral VPU__JPEG_DEC1 base address */
#define VPU__JPEG_DEC1_BASE                      (0x4C500100u)
/** Peripheral VPU__JPEG_DEC1 base pointer */
#define VPU__JPEG_DEC1                           ((JPEG_DEC_Type *)VPU__JPEG_DEC1_BASE)
/** Array initializer of JPEG_DEC peripheral base addresses */
#define JPEG_DEC_BASE_ADDRS                      { VPU__JPEG_DEC1_BASE }
/** Array initializer of JPEG_DEC peripheral base pointers */
#define JPEG_DEC_BASE_PTRS                       { VPU__JPEG_DEC1 }

/* JPEG_DEC_WRAP - Peripheral instance base addresses */
/** Peripheral VPU__JPEG_DEC_WRAP0 base address */
#define VPU__JPEG_DEC_WRAP0_BASE                 (0x4C500000u)
/** Peripheral VPU__JPEG_DEC_WRAP0 base pointer */
#define VPU__JPEG_DEC_WRAP0                      ((JPEG_DEC_WRAP_Type *)VPU__JPEG_DEC_WRAP0_BASE)
/** Array initializer of JPEG_DEC_WRAP peripheral base addresses */
#define JPEG_DEC_WRAP_BASE_ADDRS                 { VPU__JPEG_DEC_WRAP0_BASE }
/** Array initializer of JPEG_DEC_WRAP peripheral base pointers */
#define JPEG_DEC_WRAP_BASE_PTRS                  { VPU__JPEG_DEC_WRAP0 }

/* LDB - Peripheral instance base addresses */
/** Peripheral LVDS base address */
#define LVDS_BASE                                (0x4B0C0000u)
/** Peripheral LVDS base pointer */
#define LVDS                                     ((LDB_Type *)LVDS_BASE)
/** Array initializer of LDB peripheral base addresses */
#define LDB_BASE_ADDRS                           { LVDS_BASE }
/** Array initializer of LDB peripheral base pointers */
#define LDB_BASE_PTRS                            { LVDS }

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
#define LPI2C3_BASE                              (0x42150000u)
/** Peripheral LPI2C3 base pointer */
#define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
/** Peripheral LPI2C4 base address */
#define LPI2C4_BASE                              (0x42160000u)
/** Peripheral LPI2C4 base pointer */
#define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
/** Peripheral LPI2C5 base address */
#define LPI2C5_BASE                              (0x422D0000u)
/** Peripheral LPI2C5 base pointer */
#define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
/** Peripheral LPI2C6 base address */
#define LPI2C6_BASE                              (0x422E0000u)
/** Peripheral LPI2C6 base pointer */
#define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
/** Peripheral LPI2C7 base address */
#define LPI2C7_BASE                              (0x422F0000u)
/** Peripheral LPI2C7 base pointer */
#define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
/** Peripheral LPI2C8 base address */
#define LPI2C8_BASE                              (0x42300000u)
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
#define LPIT2_BASE                               (0x420E0000u)
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
#define LPSPI3_BASE                              (0x42170000u)
/** Peripheral LPSPI3 base pointer */
#define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
/** Peripheral LPSPI4 base address */
#define LPSPI4_BASE                              (0x42180000u)
/** Peripheral LPSPI4 base pointer */
#define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
/** Peripheral LPSPI5 base address */
#define LPSPI5_BASE                              (0x42310000u)
/** Peripheral LPSPI5 base pointer */
#define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
/** Peripheral LPSPI6 base address */
#define LPSPI6_BASE                              (0x42320000u)
/** Peripheral LPSPI6 base pointer */
#define LPSPI6                                   ((LPSPI_Type *)LPSPI6_BASE)
/** Peripheral LPSPI7 base address */
#define LPSPI7_BASE                              (0x42330000u)
/** Peripheral LPSPI7 base pointer */
#define LPSPI7                                   ((LPSPI_Type *)LPSPI7_BASE)
/** Peripheral LPSPI8 base address */
#define LPSPI8_BASE                              (0x42340000u)
/** Peripheral LPSPI8 base pointer */
#define LPSPI8                                   ((LPSPI_Type *)LPSPI8_BASE)
/** Peripheral LPSPI9 base address */
#define LPSPI9_BASE                              (0x4B100000u)
/** Peripheral LPSPI9 base pointer */
#define LPSPI9                                   ((LPSPI_Type *)LPSPI9_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE, LPSPI6_BASE, LPSPI7_BASE, LPSPI8_BASE, LPSPI9_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5, LPSPI6, LPSPI7, LPSPI8, LPSPI9 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, LPSPI4_IRQn, LPSPI5_IRQn, LPSPI6_IRQn, LPSPI7_IRQn, LPSPI8_IRQn, LPSPI9_IRQn }

/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR1 base address */
#define LPTMR1_BASE                              (0x44300000u)
/** Peripheral LPTMR1 base pointer */
#define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
/** Peripheral LPTMR2 base address */
#define LPTMR2_BASE                              (0x420F0000u)
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
#define LPUART3_BASE                             (0x42190000u)
/** Peripheral LPUART3 base pointer */
#define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
/** Peripheral LPUART4 base address */
#define LPUART4_BASE                             (0x421A0000u)
/** Peripheral LPUART4 base pointer */
#define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
/** Peripheral LPUART5 base address */
#define LPUART5_BASE                             (0x421B0000u)
/** Peripheral LPUART5 base pointer */
#define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
/** Peripheral LPUART6 base address */
#define LPUART6_BASE                             (0x421C0000u)
/** Peripheral LPUART6 base pointer */
#define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
/** Peripheral LPUART7 base address */
#define LPUART7_BASE                             (0x422B0000u)
/** Peripheral LPUART7 base pointer */
#define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
/** Peripheral LPUART8 base address */
#define LPUART8_BASE                             (0x422C0000u)
/** Peripheral LPUART8 base pointer */
#define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn, LPUART6_IRQn, LPUART7_IRQn, LPUART8_IRQn }

/* M7_A7_APB_MCM - Peripheral instance base addresses */
/** Peripheral M7__A7_APB_MCM1 base address */
#define M7__A7_APB_MCM1_BASE                     (0x4A0A0000u)
/** Peripheral M7__A7_APB_MCM1 base pointer */
#define M7__A7_APB_MCM1                          ((M7_A7_APB_MCM_Type *)M7__A7_APB_MCM1_BASE)
/** Array initializer of M7_A7_APB_MCM peripheral base addresses */
#define M7_A7_APB_MCM_BASE_ADDRS                 { M7__A7_APB_MCM1_BASE }
/** Array initializer of M7_A7_APB_MCM peripheral base pointers */
#define M7_A7_APB_MCM_BASE_PTRS                  { M7__A7_APB_MCM1 }

/* M7_EIM - Peripheral instance base addresses */
/** Peripheral M7__EIM base address */
#define M7__EIM_BASE                             (0x4A060000u)
/** Peripheral M7__EIM base pointer */
#define M7__EIM                                  ((M7_EIM_Type *)M7__EIM_BASE)
/** Array initializer of M7_EIM peripheral base addresses */
#define M7_EIM_BASE_ADDRS                        { M7__EIM_BASE }
/** Array initializer of M7_EIM peripheral base pointers */
#define M7_EIM_BASE_PTRS                         { M7__EIM }

/* M7_ERM - Peripheral instance base addresses */
/** Peripheral M7__ERM base address */
#define M7__ERM_BASE                             (0x4A070000u)
/** Peripheral M7__ERM base pointer */
#define M7__ERM                                  ((M7_ERM_Type *)M7__ERM_BASE)
/** Array initializer of M7_ERM peripheral base addresses */
#define M7_ERM_BASE_ADDRS                        { M7__ERM_BASE }
/** Array initializer of M7_ERM peripheral base pointers */
#define M7_ERM_BASE_PTRS                         { M7__ERM }

/* M7_LSTCU - Peripheral instance base addresses */
/** Peripheral M7__LSTCU_M7MIX base address */
#define M7__LSTCU_M7MIX_BASE                     (0x4A050000u)
/** Peripheral M7__LSTCU_M7MIX base pointer */
#define M7__LSTCU_M7MIX                          ((M7_LSTCU_Type *)M7__LSTCU_M7MIX_BASE)
/** Array initializer of M7_LSTCU peripheral base addresses */
#define M7_LSTCU_BASE_ADDRS                      { M7__LSTCU_M7MIX_BASE }
/** Array initializer of M7_LSTCU peripheral base pointers */
#define M7_LSTCU_BASE_PTRS                       { M7__LSTCU_M7MIX }

/* M7_TCU - Peripheral instance base addresses */
/** Peripheral M7__TCU base address */
#define M7__TCU_BASE                             (0x4A000000u)
/** Peripheral M7__TCU base pointer */
#define M7__TCU                                  ((M7_TCU_Type *)M7__TCU_BASE)
/** Array initializer of M7_TCU peripheral base addresses */
#define M7_TCU_BASE_ADDRS                        { M7__TCU_BASE }
/** Array initializer of M7_TCU peripheral base pointers */
#define M7_TCU_BASE_PTRS                         { M7__TCU }

/* MSGINTR - Peripheral instance base addresses */
/** Peripheral MSGINTR1 base address */
#define MSGINTR1_BASE                            (0x44690000u)
/** Peripheral MSGINTR1 base pointer */
#define MSGINTR1                                 ((MSGINTR_Type *)MSGINTR1_BASE)
/** Peripheral MSGINTR2 base address */
#define MSGINTR2_BASE                            (0x446A0000u)
/** Peripheral MSGINTR2 base pointer */
#define MSGINTR2                                 ((MSGINTR_Type *)MSGINTR2_BASE)
/** Array initializer of MSGINTR peripheral base addresses */
#define MSGINTR_BASE_ADDRS                       { 0u, MSGINTR1_BASE, MSGINTR2_BASE }
/** Array initializer of MSGINTR peripheral base pointers */
#define MSGINTR_BASE_PTRS                        { (MSGINTR_Type *)0u, MSGINTR1, MSGINTR2 }
/** Interrupt vectors for the MSGINTR peripheral type */
#define MSGINTR_IRQS                             { NotAvail_IRQn, MSGINTR1_IRQn, MSGINTR2_IRQn }

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
#define MU7_MUA_BASE                             (0x42050000u)
/** Peripheral MU7_MUA base pointer */
#define MU7_MUA                                  ((MU_Type *)MU7_MUA_BASE)
/** Peripheral MU7_MUB base address */
#define MU7_MUB_BASE                             (0x42060000u)
/** Peripheral MU7_MUB base pointer */
#define MU7_MUB                                  ((MU_Type *)MU7_MUB_BASE)
/** Peripheral MU8_MUA base address */
#define MU8_MUA_BASE                             (0x42350000u)
/** Peripheral MU8_MUA base pointer */
#define MU8_MUA                                  ((MU_Type *)MU8_MUA_BASE)
/** Peripheral MU8_MUB base address */
#define MU8_MUB_BASE                             (0x42360000u)
/** Peripheral MU8_MUB base pointer */
#define MU8_MUB                                  ((MU_Type *)MU8_MUB_BASE)
/** Peripheral CAMERA__MUI_A1__MUA base address */
#define CAMERA__MUI_A1__MUA_BASE                 (0x4AC60000u)
/** Peripheral CAMERA__MUI_A1__MUA base pointer */
#define CAMERA__MUI_A1__MUA                      ((MU_Type *)CAMERA__MUI_A1__MUA_BASE)
/** Peripheral CAMERA__MUI_A2__MUA base address */
#define CAMERA__MUI_A2__MUA_BASE                 (0x4AC70000u)
/** Peripheral CAMERA__MUI_A2__MUA base pointer */
#define CAMERA__MUI_A2__MUA                      ((MU_Type *)CAMERA__MUI_A2__MUA_BASE)
/** Peripheral CAMERA__MUI_A3__MUA base address */
#define CAMERA__MUI_A3__MUA_BASE                 (0x4AC80000u)
/** Peripheral CAMERA__MUI_A3__MUA base pointer */
#define CAMERA__MUI_A3__MUA                      ((MU_Type *)CAMERA__MUI_A3__MUA_BASE)
/** Peripheral CAMERA__MUI_A4__MUA base address */
#define CAMERA__MUI_A4__MUA_BASE                 (0x4AC90000u)
/** Peripheral CAMERA__MUI_A4__MUA base pointer */
#define CAMERA__MUI_A4__MUA                      ((MU_Type *)CAMERA__MUI_A4__MUA_BASE)
/** Peripheral CAMERA__MUI_A5__MUA base address */
#define CAMERA__MUI_A5__MUA_BASE                 (0x4ACA0000u)
/** Peripheral CAMERA__MUI_A5__MUA base pointer */
#define CAMERA__MUI_A5__MUA                      ((MU_Type *)CAMERA__MUI_A5__MUA_BASE)
/** Peripheral CAMERA__MUI_A6__MUA base address */
#define CAMERA__MUI_A6__MUA_BASE                 (0x4ACB0000u)
/** Peripheral CAMERA__MUI_A6__MUA base pointer */
#define CAMERA__MUI_A6__MUA                      ((MU_Type *)CAMERA__MUI_A6__MUA_BASE)
/** Peripheral CAMERA__MUI_A7__MUA base address */
#define CAMERA__MUI_A7__MUA_BASE                 (0x4ACC0000u)
/** Peripheral CAMERA__MUI_A7__MUA base pointer */
#define CAMERA__MUI_A7__MUA                      ((MU_Type *)CAMERA__MUI_A7__MUA_BASE)
/** Peripheral CAMERA__MUI_A8__MUA base address */
#define CAMERA__MUI_A8__MUA_BASE                 (0x4ACD0000u)
/** Peripheral CAMERA__MUI_A8__MUA base pointer */
#define CAMERA__MUI_A8__MUA                      ((MU_Type *)CAMERA__MUI_A8__MUA_BASE)
/** Peripheral CAMERA__MUI_A9__MUA base address */
#define CAMERA__MUI_A9__MUA_BASE                 (0x4ACE0000u)
/** Peripheral CAMERA__MUI_A9__MUA base pointer */
#define CAMERA__MUI_A9__MUA                      ((MU_Type *)CAMERA__MUI_A9__MUA_BASE)
/** Peripheral DISPLAY__MUI_A1__MUA base address */
#define DISPLAY__MUI_A1__MUA_BASE                (0x4B080000u)
/** Peripheral DISPLAY__MUI_A1__MUA base pointer */
#define DISPLAY__MUI_A1__MUA                     ((MU_Type *)DISPLAY__MUI_A1__MUA_BASE)
/** Peripheral DISPLAY__MUI_A2__MUA base address */
#define DISPLAY__MUI_A2__MUA_BASE                (0x4B090000u)
/** Peripheral DISPLAY__MUI_A2__MUA base pointer */
#define DISPLAY__MUI_A2__MUA                     ((MU_Type *)DISPLAY__MUI_A2__MUA_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MU1_MUA_BASE, MU1_MUB_BASE, MU2_MUA_BASE, MU2_MUB_BASE, MU3_MUA_BASE, MU3_MUB_BASE, MU4_MUA_BASE, MU4_MUB_BASE, MU5_MUA_BASE, MU5_MUB_BASE, MU6_MUA_BASE, MU6_MUB_BASE, MU7_MUA_BASE, MU7_MUB_BASE, MU8_MUA_BASE, MU8_MUB_BASE, CAMERA__MUI_A1__MUA_BASE, CAMERA__MUI_A2__MUA_BASE, CAMERA__MUI_A3__MUA_BASE, CAMERA__MUI_A4__MUA_BASE, CAMERA__MUI_A5__MUA_BASE, CAMERA__MUI_A6__MUA_BASE, CAMERA__MUI_A7__MUA_BASE, CAMERA__MUI_A8__MUA_BASE, CAMERA__MUI_A9__MUA_BASE, DISPLAY__MUI_A1__MUA_BASE, DISPLAY__MUI_A2__MUA_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MU1_MUA, MU1_MUB, MU2_MUA, MU2_MUB, MU3_MUA, MU3_MUB, MU4_MUA, MU4_MUB, MU5_MUA, MU5_MUB, MU6_MUA, MU6_MUB, MU7_MUA, MU7_MUB, MU8_MUA, MU8_MUB, CAMERA__MUI_A1__MUA, CAMERA__MUI_A2__MUA, CAMERA__MUI_A3__MUA, CAMERA__MUI_A4__MUA, CAMERA__MUI_A5__MUA, CAMERA__MUI_A6__MUA, CAMERA__MUI_A7__MUA, CAMERA__MUI_A8__MUA, CAMERA__MUI_A9__MUA, DISPLAY__MUI_A1__MUA, DISPLAY__MUI_A2__MUA }
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU1_A_IRQn, MU1_B_IRQn, MU2_A_IRQn, MU2_B_IRQn, MU3_A_IRQn, MU3_B_IRQn, MU4_A_IRQn, MU4_B_IRQn, MU5_A_IRQn, MU5_B_IRQn, MU6_A_IRQn, MU6_B_IRQn, MU7_A_IRQn, MU7_B_IRQn, MU8_A_IRQn, MU8_B_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* NETC_ENETC - Peripheral instance base addresses */
/** Peripheral ENETC0_BASE base address */
#define ENETC0_BASE_BASE                         (0x4CC10000u)
/** Peripheral ENETC0_BASE base pointer */
#define ENETC0_BASE                              ((NETC_ENETC_Type *)ENETC0_BASE_BASE)
/** Peripheral ENETC1_BASE base address */
#define ENETC1_BASE_BASE                         (0x4CC50000u)
/** Peripheral ENETC1_BASE base pointer */
#define ENETC1_BASE                              ((NETC_ENETC_Type *)ENETC1_BASE_BASE)
/** Array initializer of NETC_ENETC peripheral base addresses */
#define NETC_ENETC_BASE_ADDRS                    { ENETC0_BASE_BASE, ENETC1_BASE_BASE }
/** Array initializer of NETC_ENETC peripheral base pointers */
#define NETC_ENETC_BASE_PTRS                     { ENETC0_BASE, ENETC1_BASE }

/* NETC_ETH_LINK - Peripheral instance base addresses */
/** Peripheral ENETC0_ETH_MAC_PORT base address */
#define ENETC0_ETH_MAC_PORT_BASE                 (0x4CC15000u)
/** Peripheral ENETC0_ETH_MAC_PORT base pointer */
#define ENETC0_ETH_MAC_PORT                      ((NETC_ETH_LINK_Type *)ENETC0_ETH_MAC_PORT_BASE)
/** Peripheral ENETC1_ETH_MAC_PORT base address */
#define ENETC1_ETH_MAC_PORT_BASE                 (0x4CC55000u)
/** Peripheral ENETC1_ETH_MAC_PORT base pointer */
#define ENETC1_ETH_MAC_PORT                      ((NETC_ETH_LINK_Type *)ENETC1_ETH_MAC_PORT_BASE)
/** Array initializer of NETC_ETH_LINK peripheral base addresses */
#define NETC_ETH_LINK_BASE_ADDRS                 { ENETC0_ETH_MAC_PORT_BASE, ENETC1_ETH_MAC_PORT_BASE }
/** Array initializer of NETC_ETH_LINK peripheral base pointers */
#define NETC_ETH_LINK_BASE_PTRS                  { ENETC0_ETH_MAC_PORT, ENETC1_ETH_MAC_PORT }

/* NETC_IERB - Peripheral instance base addresses */
/** Peripheral NETC_IERB base address */
#define NETC_IERB_BASE                           (0x4CD20000u)
/** Peripheral NETC_IERB base pointer */
#define NETC_IERB                                ((NETC_IERB_Type *)NETC_IERB_BASE)
/** Array initializer of NETC_IERB peripheral base addresses */
#define NETC_IERB_BASE_ADDRS                     { NETC_IERB_BASE }
/** Array initializer of NETC_IERB peripheral base pointers */
#define NETC_IERB_BASE_PTRS                      { NETC_IERB }

/* NETC_PORT - Peripheral instance base addresses */
/** Peripheral ENETC0_PORT base address */
#define ENETC0_PORT_BASE                         (0x4CC14000u)
/** Peripheral ENETC0_PORT base pointer */
#define ENETC0_PORT                              ((NETC_PORT_Type *)ENETC0_PORT_BASE)
/** Peripheral ENETC1_PORT base address */
#define ENETC1_PORT_BASE                         (0x4CC54000u)
/** Peripheral ENETC1_PORT base pointer */
#define ENETC1_PORT                              ((NETC_PORT_Type *)ENETC1_PORT_BASE)
/** Array initializer of NETC_PORT peripheral base addresses */
#define NETC_PORT_BASE_ADDRS                     { ENETC0_PORT_BASE, ENETC1_PORT_BASE }
/** Array initializer of NETC_PORT peripheral base pointers */
#define NETC_PORT_BASE_PTRS                      { ENETC0_PORT, ENETC1_PORT }

/* NETC_PRIV - Peripheral instance base addresses */
/** Peripheral NETC_PRIV base address */
#define NETC_PRIV_BASE                           (0x4CD30000u)
/** Peripheral NETC_PRIV base pointer */
#define NETC_PRIV                                ((NETC_PRIV_Type *)NETC_PRIV_BASE)
/** Array initializer of NETC_PRIV peripheral base addresses */
#define NETC_PRIV_BASE_ADDRS                     { NETC_PRIV_BASE }
/** Array initializer of NETC_PRIV peripheral base pointers */
#define NETC_PRIV_BASE_PTRS                      { NETC_PRIV }

/* NETC_SW_ENETC - Peripheral instance base addresses */
/** Peripheral ENETC0_COMMON base address */
#define ENETC0_COMMON_BASE                       (0x4CC11000u)
/** Peripheral ENETC0_COMMON base pointer */
#define ENETC0_COMMON                            ((NETC_SW_ENETC_Type *)ENETC0_COMMON_BASE)
/** Peripheral ENETC1_COMMON base address */
#define ENETC1_COMMON_BASE                       (0x4CC51000u)
/** Peripheral ENETC1_COMMON base pointer */
#define ENETC1_COMMON                            ((NETC_SW_ENETC_Type *)ENETC1_COMMON_BASE)
/** Array initializer of NETC_SW_ENETC peripheral base addresses */
#define NETC_SW_ENETC_BASE_ADDRS                 { ENETC0_COMMON_BASE, ENETC1_COMMON_BASE }
/** Array initializer of NETC_SW_ENETC peripheral base pointers */
#define NETC_SW_ENETC_BASE_PTRS                  { ENETC0_COMMON, ENETC1_COMMON }

/* NOC_ATU - Peripheral instance base addresses */
/** Peripheral NOC__ATU0 base address */
#define NOC__ATU0_BASE                           (0x490C0000u)
/** Peripheral NOC__ATU0 base pointer */
#define NOC__ATU0                                ((NOC_ATU_Type *)NOC__ATU0_BASE)
/** Peripheral NOC__ATU1 base address */
#define NOC__ATU1_BASE                           (0x490C0000u)
/** Peripheral NOC__ATU1 base pointer */
#define NOC__ATU1                                ((NOC_ATU_Type *)NOC__ATU1_BASE)
/** Array initializer of NOC_ATU peripheral base addresses */
#define NOC_ATU_BASE_ADDRS                       { NOC__ATU0_BASE, NOC__ATU1_BASE }
/** Array initializer of NOC_ATU peripheral base pointers */
#define NOC_ATU_BASE_PTRS                        { NOC__ATU0, NOC__ATU1 }

/* NOC_BLK_CTRL_NOCMIX - Peripheral instance base addresses */
/** Peripheral NOC__BLK_CTRL_NOCMIX base address */
#define NOC__BLK_CTRL_NOCMIX_BASE                (0x49000000u)
/** Peripheral NOC__BLK_CTRL_NOCMIX base pointer */
#define NOC__BLK_CTRL_NOCMIX                     ((NOC_BLK_CTRL_NOCMIX_Type *)NOC__BLK_CTRL_NOCMIX_BASE)
/** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base addresses */
#define NOC_BLK_CTRL_NOCMIX_BASE_ADDRS           { NOC__BLK_CTRL_NOCMIX_BASE }
/** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base pointers */
#define NOC_BLK_CTRL_NOCMIX_BASE_PTRS            { NOC__BLK_CTRL_NOCMIX }

/* NOC_EIM - Peripheral instance base addresses */
/** Peripheral NOC__EIMN base address */
#define NOC__EIMN_BASE                           (0x49270000u)
/** Peripheral NOC__EIMN base pointer */
#define NOC__EIMN                                ((NOC_EIM_Type *)NOC__EIMN_BASE)
/** Array initializer of NOC_EIM peripheral base addresses */
#define NOC_EIM_BASE_ADDRS                       { NOC__EIMN_BASE }
/** Array initializer of NOC_EIM peripheral base pointers */
#define NOC_EIM_BASE_PTRS                        { NOC__EIMN }

/* NOC_LSTCU - Peripheral instance base addresses */
/** Peripheral NOC__LSTCUN base address */
#define NOC__LSTCUN_BASE                         (0x490B0000u)
/** Peripheral NOC__LSTCUN base pointer */
#define NOC__LSTCUN                              ((NOC_LSTCU_Type *)NOC__LSTCUN_BASE)
/** Array initializer of NOC_LSTCU peripheral base addresses */
#define NOC_LSTCU_BASE_ADDRS                     { NOC__LSTCUN_BASE }
/** Array initializer of NOC_LSTCU peripheral base pointers */
#define NOC_LSTCU_BASE_PTRS                      { NOC__LSTCUN }

/* NOC_SRAMCTL - Peripheral instance base addresses */
/** Peripheral NOC__SRAMCTL base address */
#define NOC__SRAMCTL_BASE                        (0x490A0000u)
/** Peripheral NOC__SRAMCTL base pointer */
#define NOC__SRAMCTL                             ((NOC_SRAMCTL_Type *)NOC__SRAMCTL_BASE)
/** Array initializer of NOC_SRAMCTL peripheral base addresses */
#define NOC_SRAMCTL_BASE_ADDRS                   { NOC__SRAMCTL_BASE }
/** Array initializer of NOC_SRAMCTL peripheral base pointers */
#define NOC_SRAMCTL_BASE_PTRS                    { NOC__SRAMCTL }

/* NPU_BLK_CTRL - Peripheral instance base addresses */
/** Peripheral NPU__BLK_CTRL_NPUMIX base address */
#define NPU__BLK_CTRL_NPUMIX_BASE                (0x4A810000u)
/** Peripheral NPU__BLK_CTRL_NPUMIX base pointer */
#define NPU__BLK_CTRL_NPUMIX                     ((NPU_BLK_CTRL_Type *)NPU__BLK_CTRL_NPUMIX_BASE)
/** Array initializer of NPU_BLK_CTRL peripheral base addresses */
#define NPU_BLK_CTRL_BASE_ADDRS                  { NPU__BLK_CTRL_NPUMIX_BASE }
/** Array initializer of NPU_BLK_CTRL peripheral base pointers */
#define NPU_BLK_CTRL_BASE_PTRS                   { NPU__BLK_CTRL_NPUMIX }

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

/* OSC24M - Peripheral instance base addresses */
/** Peripheral OSC24M base address */
#define OSC24M_BASE                              (0x44480000u)
/** Peripheral OSC24M base pointer */
#define OSC24M                                   ((OSC24M_Type *)OSC24M_BASE)
/** Array initializer of OSC24M peripheral base addresses */
#define OSC24M_BASE_ADDRS                        { OSC24M_BASE }
/** Array initializer of OSC24M peripheral base pointers */
#define OSC24M_BASE_PTRS                         { OSC24M }

/* PCIE_DMA_IATU - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU base address */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE (0x4C360000u)
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU base pointer */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU ((PCIE_DMA_IATU_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE)
/** Array initializer of PCIE_DMA_IATU peripheral base addresses */
#define PCIE_DMA_IATU_BASE_ADDRS                 { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE }
/** Array initializer of PCIE_DMA_IATU peripheral base pointers */
#define PCIE_DMA_IATU_BASE_PTRS                  { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU }

/* PCIE_EP - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP base address */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE (0x4C300000u)
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP base pointer */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP ((PCIE_EP_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE)
/** Array initializer of PCIE_EP peripheral base addresses */
#define PCIE_EP_BASE_ADDRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE }
/** Array initializer of PCIE_EP peripheral base pointers */
#define PCIE_EP_BASE_PTRS                        { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP }

/* PCIE_RC - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC base address */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE (0x4C300000u)
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC base pointer */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC ((PCIE_RC_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE)
/** Array initializer of PCIE_RC peripheral base addresses */
#define PCIE_RC_BASE_ADDRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE }
/** Array initializer of PCIE_RC peripheral base pointers */
#define PCIE_RC_BASE_PTRS                        { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC }

/* PCIE_SHADOW_EP - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP base address */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE (0x4C320000u)
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP base pointer */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP ((PCIE_SHADOW_EP_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE)
/** Array initializer of PCIE_SHADOW_EP peripheral base addresses */
#define PCIE_SHADOW_EP_BASE_ADDRS                { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE }
/** Array initializer of PCIE_SHADOW_EP peripheral base pointers */
#define PCIE_SHADOW_EP_BASE_PTRS                 { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP }

/* PDM - Peripheral instance base addresses */
/** Peripheral PDM base address */
#define PDM_BASE                                 (0x44520000u)
/** Peripheral PDM base pointer */
#define PDM                                      ((PDM_Type *)PDM_BASE)
/** Array initializer of PDM peripheral base addresses */
#define PDM_BASE_ADDRS                           { PDM_BASE }
/** Array initializer of PDM peripheral base pointers */
#define PDM_BASE_PTRS                            { PDM }
/** Interrupt vectors for the PDM peripheral type */
#define PDM_HWVAD_Event_IRQS                     { PDM_HWVAD_EVENT_IRQn }
#define PDM_HWVAD_Error_IRQS                     { PDM_HWVAD_ERROR_IRQn }
#define PDM_Event_IRQS                           { PDM_EVENT_IRQn }
#define PDM_Error_IRQS                           { PDM_ERROR_IRQn }

/* PHY_CTRL_EX - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX base address */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE (0x4CF00000u)
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX base pointer */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX ((PHY_CTRL_EX_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE)
/** Array initializer of PHY_CTRL_EX peripheral base addresses */
#define PHY_CTRL_EX_BASE_ADDRS                   { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE }
/** Array initializer of PHY_CTRL_EX peripheral base pointers */
#define PHY_CTRL_EX_BASE_PTRS                    { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX }

/* PHY_ENET - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET base address */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE (0x4CF00000u)
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET base pointer */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET ((PHY_ENET_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE)
/** Array initializer of PHY_ENET peripheral base addresses */
#define PHY_ENET_BASE_ADDRS                      { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE }
/** Array initializer of PHY_ENET peripheral base pointers */
#define PHY_ENET_BASE_PTRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET }

/* PLL - Peripheral instance base addresses */
/** Peripheral SYS_PLL1 base address */
#define SYS_PLL1_BASE                            (0x44481000u)
/** Peripheral SYS_PLL1 base pointer */
#define SYS_PLL1                                 ((PLL_Type *)SYS_PLL1_BASE)
/** Peripheral ANALOG__AUDIO_FRACT_PLL1 base address */
#define ANALOG__AUDIO_FRACT_PLL1_BASE            (0x44481100u)
/** Peripheral ANALOG__AUDIO_FRACT_PLL1 base pointer */
#define ANALOG__AUDIO_FRACT_PLL1                 ((PLL_Type *)ANALOG__AUDIO_FRACT_PLL1_BASE)
/** Peripheral ANALOG__AUDIO_FRACT_PLL2 base address */
#define ANALOG__AUDIO_FRACT_PLL2_BASE            (0x44481200u)
/** Peripheral ANALOG__AUDIO_FRACT_PLL2 base pointer */
#define ANALOG__AUDIO_FRACT_PLL2                 ((PLL_Type *)ANALOG__AUDIO_FRACT_PLL2_BASE)
/** Peripheral ANALOG__VIDEO_FRACT_PLL1 base address */
#define ANALOG__VIDEO_FRACT_PLL1_BASE            (0x44481300u)
/** Peripheral ANALOG__VIDEO_FRACT_PLL1 base pointer */
#define ANALOG__VIDEO_FRACT_PLL1                 ((PLL_Type *)ANALOG__VIDEO_FRACT_PLL1_BASE)
/** Peripheral CORTEXA__FRACT_PLL_ARMPLL base address */
#define CORTEXA__FRACT_PLL_ARMPLL_BASE           (0x44481600u)
/** Peripheral CORTEXA__FRACT_PLL_ARMPLL base pointer */
#define CORTEXA__FRACT_PLL_ARMPLL                ((PLL_Type *)CORTEXA__FRACT_PLL_ARMPLL_BASE)
/** Peripheral DDRC__FRACT_PLL base address */
#define DDRC__FRACT_PLL_BASE                     (0x44481700u)
/** Peripheral DDRC__FRACT_PLL base pointer */
#define DDRC__FRACT_PLL                          ((PLL_Type *)DDRC__FRACT_PLL_BASE)
/** Peripheral DISPLAY__FRACT_PLL base address */
#define DISPLAY__FRACT_PLL_BASE                  (0x44481900u)
/** Peripheral DISPLAY__FRACT_PLL base pointer */
#define DISPLAY__FRACT_PLL                       ((PLL_Type *)DISPLAY__FRACT_PLL_BASE)
/** Array initializer of PLL peripheral base addresses */
#define PLL_BASE_ADDRS                           { SYS_PLL1_BASE, ANALOG__AUDIO_FRACT_PLL1_BASE, ANALOG__AUDIO_FRACT_PLL2_BASE, ANALOG__VIDEO_FRACT_PLL1_BASE, CORTEXA__FRACT_PLL_ARMPLL_BASE, DDRC__FRACT_PLL_BASE, DISPLAY__FRACT_PLL_BASE }
/** Array initializer of PLL peripheral base pointers */
#define PLL_BASE_PTRS                            { SYS_PLL1, ANALOG__AUDIO_FRACT_PLL1, ANALOG__AUDIO_FRACT_PLL2, ANALOG__VIDEO_FRACT_PLL1, CORTEXA__FRACT_PLL_ARMPLL, DDRC__FRACT_PLL, DISPLAY__FRACT_PLL }

/* PRIMARY_CSI2_CONTROLLER - Peripheral instance base addresses */
/** Peripheral CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER base address */
#define CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE (0x4AD30000u)
/** Peripheral CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER base pointer */
#define CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER ((PRIMARY_CSI2_CONTROLLER_Type *)CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE)
/** Array initializer of PRIMARY_CSI2_CONTROLLER peripheral base addresses */
#define PRIMARY_CSI2_CONTROLLER_BASE_ADDRS       { CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE }
/** Array initializer of PRIMARY_CSI2_CONTROLLER peripheral base pointers */
#define PRIMARY_CSI2_CONTROLLER_BASE_PTRS        { CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER }

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
/** Array initializer of RGPIO peripheral base addresses */
#define RGPIO_BASE_ADDRS                         { 0u, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE }
/** Array initializer of RGPIO peripheral base pointers */
#define RGPIO_BASE_PTRS                          { (RGPIO_Type *)0u, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5 }
/** Interrupt vectors for the RGPIO peripheral type */
#define RGPIO_IRQS                               { NotAvail_IRQn, GPIO1_0_IRQn, GPIO2_0_IRQn, GPIO3_0_IRQn, GPIO4_0_IRQn, GPIO5_0_IRQn }

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
/** Array initializer of S3MU peripheral base addresses */
#define S3MU_BASE_ADDRS                          { ELE_MU0_MUA_BASE, ELE_MU1_MUA_BASE, ELE_MU2_MUA_BASE, ELE_MU3_MUA_BASE, ELE_MU4_MUA_BASE, ELE_MU5_MUA_BASE }
/** Array initializer of S3MU peripheral base pointers */
#define S3MU_BASE_PTRS                           { ELE_MU0_MUA, ELE_MU1_MUA, ELE_MU2_MUA, ELE_MU3_MUA, ELE_MU4_MUA, ELE_MU5_MUA }

/* SECONDARY_CSI2_CONTROLLER - Peripheral instance base addresses */
/** Peripheral CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER base address */
#define CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE (0x4AD40000u)
/** Peripheral CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER base pointer */
#define CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER ((SECONDARY_CSI2_CONTROLLER_Type *)CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE)
/** Array initializer of SECONDARY_CSI2_CONTROLLER peripheral base addresses */
#define SECONDARY_CSI2_CONTROLLER_BASE_ADDRS     { CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE }
/** Array initializer of SECONDARY_CSI2_CONTROLLER peripheral base pointers */
#define SECONDARY_CSI2_CONTROLLER_BASE_PTRS      { CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER }

/* SEMA42 - Peripheral instance base addresses */
/** Peripheral SEMA42_1 base address */
#define SEMA42_1_BASE                            (0x44260000u)
/** Peripheral SEMA42_1 base pointer */
#define SEMA42_1                                 ((SEMA42_Type *)SEMA42_1_BASE)
/** Peripheral SEMA42_2 base address */
#define SEMA42_2_BASE                            (0x42070000u)
/** Peripheral SEMA42_2 base pointer */
#define SEMA42_2                                 ((SEMA42_Type *)SEMA42_2_BASE)
/** Array initializer of SEMA42 peripheral base addresses */
#define SEMA42_BASE_ADDRS                        { 0u, SEMA42_1_BASE, SEMA42_2_BASE }
/** Array initializer of SEMA42 peripheral base pointers */
#define SEMA42_BASE_PTRS                         { (SEMA42_Type *)0u, SEMA42_1, SEMA42_2 }

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
/** Peripheral CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE  (0x44461100u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE)
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
/** Peripheral CCMSRCGPC__SRC__XSPR_GPUMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE     (0x44463500u)
/** Peripheral CCMSRCGPC__SRC__XSPR_GPUMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_GPUMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE    (0x44463900u)
/** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE      (0x44464100u)
/** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_M7MIX_MEM           ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE    (0x44464500u)
/** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base address */
#define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE    (0x44464900u)
/** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base pointer */
#define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base address */
#define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE    (0x44464920u)
/** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base pointer */
#define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE     (0x44464D00u)
/** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_VPUMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE     (0x44465100u)
/** Peripheral CCMSRCGPC__SRC__XSPR_VPUMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_VPUMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base address */
#define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE  (0x44465500u)
/** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base pointer */
#define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE)
/** Array initializer of SRC_MEM peripheral base addresses */
#define SRC_MEM_BASE_ADDRS                       { CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE }
/** Array initializer of SRC_MEM peripheral base pointers */
#define SRC_MEM_BASE_PTRS                        { CCMSRCGPC__SRC__XSPR_AONMIX_MEM, CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM, CCMSRCGPC__SRC__XSPR_GPUMIX_MEM, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM, CCMSRCGPC__SRC__XSPR_M7MIX_MEM, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM, CCMSRCGPC__SRC__XSPR_VPUMIX_MEM, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM }

/* SRC_XSPR - Peripheral instance base addresses */
/** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX base address */
#define CCMSRCGPC__SRC__XSPR_AONMIX_BASE         (0x44460800u)
/** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_AONMIX              ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_AONMIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_BBSMMIX base address */
#define CCMSRCGPC__SRC__XSPR_BBSMMIX_BASE        (0x44460C00u)
/** Peripheral CCMSRCGPC__SRC__XSPR_BBSMMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_BBSMMIX             ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_BBSMMIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CAMERAMIX base address */
#define CCMSRCGPC__SRC__XSPR_CAMERAMIX_BASE      (0x44461000u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CAMERAMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_CAMERAMIX           ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_CAMERAMIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CCMSRCGPCMIX base address */
#define CCMSRCGPC__SRC__XSPR_CCMSRCGPCMIX_BASE   (0x44461400u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CCMSRCGPCMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_CCMSRCGPCMIX        ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_CCMSRCGPCMIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0 base address */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_BASE (0x44461800u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0 base pointer */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0     ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1 base address */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_BASE (0x44461C00u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1 base pointer */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1     ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2 base address */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_BASE (0x44462000u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2 base pointer */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2     ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3 base address */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_BASE (0x44462400u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3 base pointer */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3     ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM base address */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_BASE (0x44462800u)
/** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM base pointer */
#define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM  ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX base address */
#define CCMSRCGPC__SRC__XSPR_DDRMIX_BASE         (0x44462C00u)
/** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_DDRMIX              ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_DDRMIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX base address */
#define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_BASE     (0x44463000u)
/** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_DISPLAYMIX          ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_DISPLAYMIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_GPUMIX base address */
#define CCMSRCGPC__SRC__XSPR_GPUMIX_BASE         (0x44463400u)
/** Peripheral CCMSRCGPC__SRC__XSPR_GPUMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_GPUMIX              ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_GPUMIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_TOP base address */
#define CCMSRCGPC__SRC__XSPR_HSIOMIX_TOP_BASE    (0x44463800u)
/** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_TOP base pointer */
#define CCMSRCGPC__SRC__XSPR_HSIOMIX_TOP         ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_HSIOMIX_TOP_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_WAON base address */
#define CCMSRCGPC__SRC__XSPR_HSIOMIX_WAON_BASE   (0x44463C00u)
/** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_WAON base pointer */
#define CCMSRCGPC__SRC__XSPR_HSIOMIX_WAON        ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_HSIOMIX_WAON_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX base address */
#define CCMSRCGPC__SRC__XSPR_M7MIX_BASE          (0x44464000u)
/** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX base pointer */
#define CCMSRCGPC__SRC__XSPR_M7MIX               ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_M7MIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX base address */
#define CCMSRCGPC__SRC__XSPR_NETCMIX_BASE        (0x44464400u)
/** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_NETCMIX             ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_NETCMIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX base address */
#define CCMSRCGPC__SRC__XSPR_NOCMIX_BASE         (0x44464800u)
/** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_NOCMIX              ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX base address */
#define CCMSRCGPC__SRC__XSPR_NPUMIX_BASE         (0x44464C00u)
/** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_NPUMIX              ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_NPUMIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_VPUMIX base address */
#define CCMSRCGPC__SRC__XSPR_VPUMIX_BASE         (0x44465000u)
/** Peripheral CCMSRCGPC__SRC__XSPR_VPUMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_VPUMIX              ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_VPUMIX_BASE)
/** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX base address */
#define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_BASE      (0x44465400u)
/** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX base pointer */
#define CCMSRCGPC__SRC__XSPR_WAKEUPMIX           ((SRC_XSPR_Type *)CCMSRCGPC__SRC__XSPR_WAKEUPMIX_BASE)
/** Peripheral SRC_XSPR_ANAMIX base address */
#define SRC_XSPR_ANAMIX_BASE                     (0x44460400u)
/** Peripheral SRC_XSPR_ANAMIX base pointer */
#define SRC_XSPR_ANAMIX                          ((SRC_XSPR_Type *)SRC_XSPR_ANAMIX_BASE)
/** Array initializer of SRC_XSPR peripheral base addresses */
#define SRC_XSPR_BASE_ADDRS                      { CCMSRCGPC__SRC__XSPR_AONMIX_BASE, CCMSRCGPC__SRC__XSPR_BBSMMIX_BASE, CCMSRCGPC__SRC__XSPR_CAMERAMIX_BASE, CCMSRCGPC__SRC__XSPR_CCMSRCGPCMIX_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_BASE, CCMSRCGPC__SRC__XSPR_DDRMIX_BASE, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_BASE, CCMSRCGPC__SRC__XSPR_GPUMIX_BASE, CCMSRCGPC__SRC__XSPR_HSIOMIX_TOP_BASE, CCMSRCGPC__SRC__XSPR_HSIOMIX_WAON_BASE, CCMSRCGPC__SRC__XSPR_M7MIX_BASE, CCMSRCGPC__SRC__XSPR_NETCMIX_BASE, CCMSRCGPC__SRC__XSPR_NOCMIX_BASE, CCMSRCGPC__SRC__XSPR_NPUMIX_BASE, CCMSRCGPC__SRC__XSPR_VPUMIX_BASE, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_BASE, SRC_XSPR_ANAMIX_BASE }
/** Array initializer of SRC_XSPR peripheral base pointers */
#define SRC_XSPR_BASE_PTRS                       { CCMSRCGPC__SRC__XSPR_AONMIX, CCMSRCGPC__SRC__XSPR_BBSMMIX, CCMSRCGPC__SRC__XSPR_CAMERAMIX, CCMSRCGPC__SRC__XSPR_CCMSRCGPCMIX, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM, CCMSRCGPC__SRC__XSPR_DDRMIX, CCMSRCGPC__SRC__XSPR_DISPLAYMIX, CCMSRCGPC__SRC__XSPR_GPUMIX, CCMSRCGPC__SRC__XSPR_HSIOMIX_TOP, CCMSRCGPC__SRC__XSPR_HSIOMIX_WAON, CCMSRCGPC__SRC__XSPR_M7MIX, CCMSRCGPC__SRC__XSPR_NETCMIX, CCMSRCGPC__SRC__XSPR_NOCMIX, CCMSRCGPC__SRC__XSPR_NPUMIX, CCMSRCGPC__SRC__XSPR_VPUMIX, CCMSRCGPC__SRC__XSPR_WAKEUPMIX, SRC_XSPR_ANAMIX }

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
/** Peripheral SYS_CTR_CONTROL base address */
#define SYS_CTR_CONTROL_BASE                     (0x44290000u)
/** Peripheral SYS_CTR_CONTROL base pointer */
#define SYS_CTR_CONTROL                          ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE)
/** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
#define SYS_CTR_CONTROL_BASE_ADDRS               { SYS_CTR_CONTROL_BASE }
/** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
#define SYS_CTR_CONTROL_BASE_PTRS                { SYS_CTR_CONTROL }

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
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS base address */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE (0x4C340000u)
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS base pointer */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS ((SerDes_SS_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE)
/** Array initializer of SerDes_SS peripheral base addresses */
#define SerDes_SS_BASE_ADDRS                     { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE }
/** Array initializer of SerDes_SS peripheral base pointers */
#define SerDes_SS_BASE_PTRS                      { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS }

/* TCM_ECC_MCM - Peripheral instance base addresses */
/** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base address */
#define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE (0x44420000u)
/** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base pointer */
#define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM   ((TCM_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE)
/** Array initializer of TCM_ECC_MCM peripheral base addresses */
#define TCM_ECC_MCM_BASE_ADDRS                   { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE }
/** Array initializer of TCM_ECC_MCM peripheral base pointers */
#define TCM_ECC_MCM_BASE_PTRS                    { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM }

/* TMPSNS - Peripheral instance base addresses */
/** Peripheral TMPSNS1 base address */
#define TMPSNS1_BASE                             (0x44482000u)
/** Peripheral TMPSNS1 base pointer */
#define TMPSNS1                                  ((TMPSNS_Type *)TMPSNS1_BASE)
/** Peripheral TMPSNS2 base address */
#define TMPSNS2_BASE                             (0x4A440000u)
/** Peripheral TMPSNS2 base pointer */
#define TMPSNS2                                  ((TMPSNS_Type *)TMPSNS2_BASE)
/** Array initializer of TMPSNS peripheral base addresses */
#define TMPSNS_BASE_ADDRS                        { TMPSNS1_BASE, TMPSNS2_BASE }
/** Array initializer of TMPSNS peripheral base pointers */
#define TMPSNS_BASE_PTRS                         { TMPSNS1, TMPSNS2 }

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
#define TPM3_BASE                                (0x42100000u)
/** Peripheral TPM3 base pointer */
#define TPM3                                     ((TPM_Type *)TPM3_BASE)
/** Peripheral TPM4 base address */
#define TPM4_BASE                                (0x42110000u)
/** Peripheral TPM4 base pointer */
#define TPM4                                     ((TPM_Type *)TPM4_BASE)
/** Peripheral TPM5 base address */
#define TPM5_BASE                                (0x42120000u)
/** Peripheral TPM5 base pointer */
#define TPM5                                     ((TPM_Type *)TPM5_BASE)
/** Peripheral TPM6 base address */
#define TPM6_BASE                                (0x42130000u)
/** Peripheral TPM6 base pointer */
#define TPM6                                     ((TPM_Type *)TPM6_BASE)
/** Array initializer of TPM peripheral base addresses */
#define TPM_BASE_ADDRS                           { 0u, TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE }
/** Array initializer of TPM peripheral base pointers */
#define TPM_BASE_PTRS                            { (TPM_Type *)0u, TPM1, TPM2, TPM3, TPM4, TPM5, TPM6 }
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { NotAvail_IRQn, TPM1_IRQn, TPM2_IRQn, TPM3_IRQn, TPM4_IRQn, TPM5_IRQn, TPM6_IRQn }

/* TRDC_MGR_MEGA - Peripheral instance base addresses */
/** Peripheral WAKEUP__TRDC_MGR2 base address */
#define WAKEUP__TRDC_MGR2_BASE                   (0x424C0000u)
/** Peripheral WAKEUP__TRDC_MGR2 base pointer */
#define WAKEUP__TRDC_MGR2                        ((TRDC_MGR_MEGA_Type *)WAKEUP__TRDC_MGR2_BASE)
/** Array initializer of TRDC_MGR_MEGA peripheral base addresses */
#define TRDC_MGR_MEGA_BASE_ADDRS                 { WAKEUP__TRDC_MGR2_BASE }
/** Array initializer of TRDC_MGR_MEGA peripheral base pointers */
#define TRDC_MGR_MEGA_BASE_PTRS                  { WAKEUP__TRDC_MGR2 }

/* TSTMR - Peripheral instance base addresses */
/** Peripheral TSTMR1 base address */
#define TSTMR1_BASE                              (0x442C0000u)
/** Peripheral TSTMR1 base pointer */
#define TSTMR1                                   ((TSTMR_Type *)TSTMR1_BASE)
/** Peripheral TSTMR2 base address */
#define TSTMR2_BASE                              (0x420A0000u)
/** Peripheral TSTMR2 base pointer */
#define TSTMR2                                   ((TSTMR_Type *)TSTMR2_BASE)
/** Array initializer of TSTMR peripheral base addresses */
#define TSTMR_BASE_ADDRS                         { 0u, TSTMR1_BASE, TSTMR2_BASE }
/** Array initializer of TSTMR peripheral base pointers */
#define TSTMR_BASE_PTRS                          { (TSTMR_Type *)0u, TSTMR1, TSTMR2 }

/* USB - Peripheral instance base addresses */
/** Peripheral USB_OTG1 base address */
#define USB_OTG1_BASE                            (0x4C100000u)
/** Peripheral USB_OTG1 base pointer */
#define USB_OTG1                                 ((USB_Type *)USB_OTG1_BASE)
/** Peripheral USB_OTG2 base address */
#define USB_OTG2_BASE                            (0x4C200000u)
/** Peripheral USB_OTG2 base pointer */
#define USB_OTG2                                 ((USB_Type *)USB_OTG2_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB_OTG2_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB_OTG2 }

/* USBNC - Peripheral instance base addresses */
/** Peripheral USBNC_OTG1 base address */
#define USBNC_OTG1_BASE                          (0x4C100200u)
/** Peripheral USBNC_OTG1 base pointer */
#define USBNC_OTG1                               ((USBNC_Type *)USBNC_OTG1_BASE)
/** Peripheral USBNC_OTG2 base address */
#define USBNC_OTG2_BASE                          (0x4C200200u)
/** Peripheral USBNC_OTG2 base pointer */
#define USBNC_OTG2                               ((USBNC_Type *)USBNC_OTG2_BASE)
/** Array initializer of USBNC peripheral base addresses */
#define USBNC_BASE_ADDRS                         { USBNC_OTG1_BASE, USBNC_OTG2_BASE }
/** Array initializer of USBNC peripheral base pointers */
#define USBNC_BASE_PTRS                          { USBNC_OTG1, USBNC_OTG2 }

/* USDHC - Peripheral instance base addresses */
/** Peripheral WAKEUP__USDHC1 base address */
#define WAKEUP__USDHC1_BASE                      (0x42C20000u)
/** Peripheral WAKEUP__USDHC1 base pointer */
#define WAKEUP__USDHC1                           ((USDHC_Type *)WAKEUP__USDHC1_BASE)
/** Peripheral WAKEUP__USDHC2 base address */
#define WAKEUP__USDHC2_BASE                      (0x42C30000u)
/** Peripheral WAKEUP__USDHC2 base pointer */
#define WAKEUP__USDHC2                           ((USDHC_Type *)WAKEUP__USDHC2_BASE)
/** Peripheral WAKEUP__USDHC3 base address */
#define WAKEUP__USDHC3_BASE                      (0x42C40000u)
/** Peripheral WAKEUP__USDHC3 base pointer */
#define WAKEUP__USDHC3                           ((USDHC_Type *)WAKEUP__USDHC3_BASE)
/** Array initializer of USDHC peripheral base addresses */
#define USDHC_BASE_ADDRS                         { 0u, WAKEUP__USDHC1_BASE, WAKEUP__USDHC2_BASE, WAKEUP__USDHC3_BASE }
/** Array initializer of USDHC peripheral base pointers */
#define USDHC_BASE_PTRS                          { (USDHC_Type *)0u, WAKEUP__USDHC1, WAKEUP__USDHC2, WAKEUP__USDHC3 }

/* USER - Peripheral instance base addresses */
/** Peripheral GPU__REG__USER base address */
#define GPU__REG__USER_BASE                      (0x4D910000u)
/** Peripheral GPU__REG__USER base pointer */
#define GPU__REG__USER                           ((USER_Type *)GPU__REG__USER_BASE)
/** Array initializer of USER peripheral base addresses */
#define USER_BASE_ADDRS                          { GPU__REG__USER_BASE }
/** Array initializer of USER peripheral base pointers */
#define USER_BASE_PTRS                           { GPU__REG__USER }

/* VPU_ATU - Peripheral instance base addresses */
/** Peripheral VPU__ATU_CODA_PRIM base address */
#define VPU__ATU_CODA_PRIM_BASE                  (0x4C610000u)
/** Peripheral VPU__ATU_CODA_PRIM base pointer */
#define VPU__ATU_CODA_PRIM                       ((VPU_ATU_Type *)VPU__ATU_CODA_PRIM_BASE)
/** Peripheral VPU__ATU_CODA_SEC base address */
#define VPU__ATU_CODA_SEC_BASE                   (0x4C620000u)
/** Peripheral VPU__ATU_CODA_SEC base pointer */
#define VPU__ATU_CODA_SEC                        ((VPU_ATU_Type *)VPU__ATU_CODA_SEC_BASE)
/** Peripheral VPU__ATU_JPEG_DEC base address */
#define VPU__ATU_JPEG_DEC_BASE                   (0x4C640000u)
/** Peripheral VPU__ATU_JPEG_DEC base pointer */
#define VPU__ATU_JPEG_DEC                        ((VPU_ATU_Type *)VPU__ATU_JPEG_DEC_BASE)
/** Peripheral VPU__ATU_JPEG_ENC base address */
#define VPU__ATU_JPEG_ENC_BASE                   (0x4C630000u)
/** Peripheral VPU__ATU_JPEG_ENC base pointer */
#define VPU__ATU_JPEG_ENC                        ((VPU_ATU_Type *)VPU__ATU_JPEG_ENC_BASE)
/** Array initializer of VPU_ATU peripheral base addresses */
#define VPU_ATU_BASE_ADDRS                       { VPU__ATU_CODA_PRIM_BASE, VPU__ATU_CODA_SEC_BASE, VPU__ATU_JPEG_DEC_BASE, VPU__ATU_JPEG_ENC_BASE }
/** Array initializer of VPU_ATU peripheral base pointers */
#define VPU_ATU_BASE_PTRS                        { VPU__ATU_CODA_PRIM, VPU__ATU_CODA_SEC, VPU__ATU_JPEG_DEC, VPU__ATU_JPEG_ENC }

/* VPU_BLK_CTRL_VPUMIX - Peripheral instance base addresses */
/** Peripheral VPU__BLK_CTRL_VPUMIX base address */
#define VPU__BLK_CTRL_VPUMIX_BASE                (0x4C410000u)
/** Peripheral VPU__BLK_CTRL_VPUMIX base pointer */
#define VPU__BLK_CTRL_VPUMIX                     ((VPU_BLK_CTRL_VPUMIX_Type *)VPU__BLK_CTRL_VPUMIX_BASE)
/** Array initializer of VPU_BLK_CTRL_VPUMIX peripheral base addresses */
#define VPU_BLK_CTRL_VPUMIX_BASE_ADDRS           { VPU__BLK_CTRL_VPUMIX_BASE }
/** Array initializer of VPU_BLK_CTRL_VPUMIX peripheral base pointers */
#define VPU_BLK_CTRL_VPUMIX_BASE_PTRS            { VPU__BLK_CTRL_VPUMIX }

/* VPU_JPEG_ENC - Peripheral instance base addresses */
/** Peripheral VPU__JPEG_ENC base address */
#define VPU__JPEG_ENC_BASE                       (0x4C550100u)
/** Peripheral VPU__JPEG_ENC base pointer */
#define VPU__JPEG_ENC                            ((VPU_JPEG_ENC_Type *)VPU__JPEG_ENC_BASE)
/** Array initializer of VPU_JPEG_ENC peripheral base addresses */
#define VPU_JPEG_ENC_BASE_ADDRS                  { VPU__JPEG_ENC_BASE }
/** Array initializer of VPU_JPEG_ENC peripheral base pointers */
#define VPU_JPEG_ENC_BASE_PTRS                   { VPU__JPEG_ENC }

/* VPU_JPEG_ENC_WRAP - Peripheral instance base addresses */
/** Peripheral VPU__JPEG_ENC_WRAP base address */
#define VPU__JPEG_ENC_WRAP_BASE                  (0x4C550000u)
/** Peripheral VPU__JPEG_ENC_WRAP base pointer */
#define VPU__JPEG_ENC_WRAP                       ((VPU_JPEG_ENC_WRAP_Type *)VPU__JPEG_ENC_WRAP_BASE)
/** Array initializer of VPU_JPEG_ENC_WRAP peripheral base addresses */
#define VPU_JPEG_ENC_WRAP_BASE_ADDRS             { VPU__JPEG_ENC_WRAP_BASE }
/** Array initializer of VPU_JPEG_ENC_WRAP peripheral base pointers */
#define VPU_JPEG_ENC_WRAP_BASE_PTRS              { VPU__JPEG_ENC_WRAP }

/* VPU_VPU_DEC - Peripheral instance base addresses */
/** Peripheral VPU__VPU_DEC base address */
#define VPU__VPU_DEC_BASE                        (0x4C4B0000u)
/** Peripheral VPU__VPU_DEC base pointer */
#define VPU__VPU_DEC                             ((VPU_VPU_DEC_Type *)VPU__VPU_DEC_BASE)
/** Array initializer of VPU_VPU_DEC peripheral base addresses */
#define VPU_VPU_DEC_BASE_ADDRS                   { VPU__VPU_DEC_BASE }
/** Array initializer of VPU_VPU_DEC peripheral base pointers */
#define VPU_VPU_DEC_BASE_PTRS                    { VPU__VPU_DEC }

/* VPU_VPU_ENC - Peripheral instance base addresses */
/** Peripheral VPU__VPU_ENC base address */
#define VPU__VPU_ENC_BASE                        (0x4C460000u)
/** Peripheral VPU__VPU_ENC base pointer */
#define VPU__VPU_ENC                             ((VPU_VPU_ENC_Type *)VPU__VPU_ENC_BASE)
/** Array initializer of VPU_VPU_ENC peripheral base addresses */
#define VPU_VPU_ENC_BASE_ADDRS                   { VPU__VPU_ENC_BASE }
/** Array initializer of VPU_VPU_ENC peripheral base pointers */
#define VPU_VPU_ENC_BASE_PTRS                    { VPU__VPU_ENC }

/* VS_MII_MMD - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD base address */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE (0x4CEE0000u)
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD base pointer */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD ((VS_MII_MMD_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE)
/** Array initializer of VS_MII_MMD peripheral base addresses */
#define VS_MII_MMD_BASE_ADDRS                    { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE }
/** Array initializer of VS_MII_MMD peripheral base pointers */
#define VS_MII_MMD_BASE_PTRS                     { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD }

/* VS_MMD1 - Peripheral instance base addresses */
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 base address */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE (0x4CEC0000u)
/** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 base pointer */
#define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 ((VS_MMD1_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE)
/** Array initializer of VS_MMD1 peripheral base addresses */
#define VS_MMD1_BASE_ADDRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE }
/** Array initializer of VS_MMD1 peripheral base pointers */
#define VS_MMD1_BASE_PTRS                        { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 }

/* WAKEUP_AHBRM - Peripheral instance base addresses */
/** Peripheral WAKEUP__AHBRM1 base address */
#define WAKEUP__AHBRM1_BASE                      (0x42400800u)
/** Peripheral WAKEUP__AHBRM1 base pointer */
#define WAKEUP__AHBRM1                           ((WAKEUP_AHBRM_Type *)WAKEUP__AHBRM1_BASE)
/** Array initializer of WAKEUP_AHBRM peripheral base addresses */
#define WAKEUP_AHBRM_BASE_ADDRS                  { WAKEUP__AHBRM1_BASE }
/** Array initializer of WAKEUP_AHBRM peripheral base pointers */
#define WAKEUP_AHBRM_BASE_PTRS                   { WAKEUP__AHBRM1 }

/* WAKEUP_ATU - Peripheral instance base addresses */
/** Peripheral WAKEUP__ATUA base address */
#define WAKEUP__ATUA_BASE                        (0x42C70000u)
/** Peripheral WAKEUP__ATUA base pointer */
#define WAKEUP__ATUA                             ((WAKEUP_ATU_Type *)WAKEUP__ATUA_BASE)
/** Peripheral WAKEUP__ATUAHBAP base address */
#define WAKEUP__ATUAHBAP_BASE                    (0x42CD0000u)
/** Peripheral WAKEUP__ATUAHBAP base pointer */
#define WAKEUP__ATUAHBAP                         ((WAKEUP_ATU_Type *)WAKEUP__ATUAHBAP_BASE)
/** Peripheral WAKEUP__ATUA_LOCK base address */
#define WAKEUP__ATUA_LOCK_BASE                   (0x42C70000u)
/** Peripheral WAKEUP__ATUA_LOCK base pointer */
#define WAKEUP__ATUA_LOCK                        ((WAKEUP_ATU_Type *)WAKEUP__ATUA_LOCK_BASE)
/** Peripheral WAKEUP__ATUSDHC1 base address */
#define WAKEUP__ATUSDHC1_BASE                    (0x42C90000u)
/** Peripheral WAKEUP__ATUSDHC1 base pointer */
#define WAKEUP__ATUSDHC1                         ((WAKEUP_ATU_Type *)WAKEUP__ATUSDHC1_BASE)
/** Peripheral WAKEUP__ATUSDHC2 base address */
#define WAKEUP__ATUSDHC2_BASE                    (0x42CA0000u)
/** Peripheral WAKEUP__ATUSDHC2 base pointer */
#define WAKEUP__ATUSDHC2                         ((WAKEUP_ATU_Type *)WAKEUP__ATUSDHC2_BASE)
/** Peripheral WAKEUP__ATUSDHC3 base address */
#define WAKEUP__ATUSDHC3_BASE                    (0x42CB0000u)
/** Peripheral WAKEUP__ATUSDHC3 base pointer */
#define WAKEUP__ATUSDHC3                         ((WAKEUP_ATU_Type *)WAKEUP__ATUSDHC3_BASE)
/** Peripheral WAKEUP__ATUV2X base address */
#define WAKEUP__ATUV2X_BASE                      (0x42C80000u)
/** Peripheral WAKEUP__ATUV2X base pointer */
#define WAKEUP__ATUV2X                           ((WAKEUP_ATU_Type *)WAKEUP__ATUV2X_BASE)
/** Peripheral WAKEUP__ATUXSPI base address */
#define WAKEUP__ATUXSPI_BASE                     (0x42CC0000u)
/** Peripheral WAKEUP__ATUXSPI base pointer */
#define WAKEUP__ATUXSPI                          ((WAKEUP_ATU_Type *)WAKEUP__ATUXSPI_BASE)
/** Array initializer of WAKEUP_ATU peripheral base addresses */
#define WAKEUP_ATU_BASE_ADDRS                    { WAKEUP__ATUA_BASE, WAKEUP__ATUAHBAP_BASE, WAKEUP__ATUA_LOCK_BASE, WAKEUP__ATUSDHC1_BASE, WAKEUP__ATUSDHC2_BASE, WAKEUP__ATUSDHC3_BASE, WAKEUP__ATUV2X_BASE, WAKEUP__ATUXSPI_BASE }
/** Array initializer of WAKEUP_ATU peripheral base pointers */
#define WAKEUP_ATU_BASE_PTRS                     { WAKEUP__ATUA, WAKEUP__ATUAHBAP, WAKEUP__ATUA_LOCK, WAKEUP__ATUSDHC1, WAKEUP__ATUSDHC2, WAKEUP__ATUSDHC3, WAKEUP__ATUV2X, WAKEUP__ATUXSPI }

/* WAKEUP_AUDMIX - Peripheral instance base addresses */
/** Peripheral WAKEUP__AUDMIX1 base address */
#define WAKEUP__AUDMIX1_BASE                     (0x431F0000u)
/** Peripheral WAKEUP__AUDMIX1 base pointer */
#define WAKEUP__AUDMIX1                          ((WAKEUP_AUDMIX_Type *)WAKEUP__AUDMIX1_BASE)
/** Array initializer of WAKEUP_AUDMIX peripheral base addresses */
#define WAKEUP_AUDMIX_BASE_ADDRS                 { WAKEUP__AUDMIX1_BASE }
/** Array initializer of WAKEUP_AUDMIX peripheral base pointers */
#define WAKEUP_AUDMIX_BASE_PTRS                  { WAKEUP__AUDMIX1 }

/* WAKEUP_DMA_CRC - Peripheral instance base addresses */
/** Peripheral WAKEUP__DMA_CRC2 base address */
#define WAKEUP__DMA_CRC2_BASE                    (0x423D0000u)
/** Peripheral WAKEUP__DMA_CRC2 base pointer */
#define WAKEUP__DMA_CRC2                         ((WAKEUP_DMA_CRC_Type *)WAKEUP__DMA_CRC2_BASE)
/** Peripheral WAKEUP__DMA_CRC3 base address */
#define WAKEUP__DMA_CRC3_BASE                    (0x424F0000u)
/** Peripheral WAKEUP__DMA_CRC3 base pointer */
#define WAKEUP__DMA_CRC3                         ((WAKEUP_DMA_CRC_Type *)WAKEUP__DMA_CRC3_BASE)
/** Array initializer of WAKEUP_DMA_CRC peripheral base addresses */
#define WAKEUP_DMA_CRC_BASE_ADDRS                { WAKEUP__DMA_CRC2_BASE, WAKEUP__DMA_CRC3_BASE }
/** Array initializer of WAKEUP_DMA_CRC peripheral base pointers */
#define WAKEUP_DMA_CRC_BASE_PTRS                 { WAKEUP__DMA_CRC2, WAKEUP__DMA_CRC3 }

/* WAKEUP_EIM - Peripheral instance base addresses */
/** Peripheral WAKEUP__EIMW base address */
#define WAKEUP__EIMW_BASE                        (0x423A0000u)
/** Peripheral WAKEUP__EIMW base pointer */
#define WAKEUP__EIMW                             ((WAKEUP_EIM_Type *)WAKEUP__EIMW_BASE)
/** Array initializer of WAKEUP_EIM peripheral base addresses */
#define WAKEUP_EIM_BASE_ADDRS                    { WAKEUP__EIMW_BASE }
/** Array initializer of WAKEUP_EIM peripheral base pointers */
#define WAKEUP_EIM_BASE_PTRS                     { WAKEUP__EIMW }

/* WAKEUP_GPT - Peripheral instance base addresses */
/** Peripheral WAKEUP__GPT2 base address */
#define WAKEUP__GPT2_BASE                        (0x435D0000u)
/** Peripheral WAKEUP__GPT2 base pointer */
#define WAKEUP__GPT2                             ((WAKEUP_GPT_Type *)WAKEUP__GPT2_BASE)
/** Peripheral WAKEUP__GPT3 base address */
#define WAKEUP__GPT3_BASE                        (0x435E0000u)
/** Peripheral WAKEUP__GPT3 base pointer */
#define WAKEUP__GPT3                             ((WAKEUP_GPT_Type *)WAKEUP__GPT3_BASE)
/** Peripheral WAKEUP__GPT4 base address */
#define WAKEUP__GPT4_BASE                        (0x435F0000u)
/** Peripheral WAKEUP__GPT4 base pointer */
#define WAKEUP__GPT4                             ((WAKEUP_GPT_Type *)WAKEUP__GPT4_BASE)
/** Peripheral WAKEUP__GPT5 base address */
#define WAKEUP__GPT5_BASE                        (0x43600000u)
/** Peripheral WAKEUP__GPT5 base pointer */
#define WAKEUP__GPT5                             ((WAKEUP_GPT_Type *)WAKEUP__GPT5_BASE)
/** Array initializer of WAKEUP_GPT peripheral base addresses */
#define WAKEUP_GPT_BASE_ADDRS                    { WAKEUP__GPT2_BASE, WAKEUP__GPT3_BASE, WAKEUP__GPT4_BASE, WAKEUP__GPT5_BASE }
/** Array initializer of WAKEUP_GPT peripheral base pointers */
#define WAKEUP_GPT_BASE_PTRS                     { WAKEUP__GPT2, WAKEUP__GPT3, WAKEUP__GPT4, WAKEUP__GPT5 }

/* WAKEUP_TRDC_MGR - Peripheral instance base addresses */
/** Peripheral WAKEUP__TRDC_MGR1 base address */
#define WAKEUP__TRDC_MGR1_BASE                   (0x42080000u)
/** Peripheral WAKEUP__TRDC_MGR1 base pointer */
#define WAKEUP__TRDC_MGR1                        ((WAKEUP_TRDC_MGR_Type *)WAKEUP__TRDC_MGR1_BASE)
/** Array initializer of WAKEUP_TRDC_MGR peripheral base addresses */
#define WAKEUP_TRDC_MGR_BASE_ADDRS               { WAKEUP__TRDC_MGR1_BASE }
/** Array initializer of WAKEUP_TRDC_MGR peripheral base pointers */
#define WAKEUP_TRDC_MGR_BASE_PTRS                { WAKEUP__TRDC_MGR1 }

/* WAKEUP_XSPI_RESPONDER - Peripheral instance base addresses */
/** Peripheral WAKEUP__XSPI_RESPONDER base address */
#define WAKEUP__XSPI_RESPONDER_BASE              (0x42C50000u)
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
#define WDOG3_BASE                               (0x420B0000u)
/** Peripheral WDOG3 base pointer */
#define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
/** Peripheral WDOG4 base address */
#define WDOG4_BASE                               (0x420C0000u)
/** Peripheral WDOG4 base pointer */
#define WDOG4                                    ((WDOG_Type *)WDOG4_BASE)
/** Peripheral WDOG5 base address */
#define WDOG5_BASE                               (0x420D0000u)
/** Peripheral WDOG5 base pointer */
#define WDOG5                                    ((WDOG_Type *)WDOG5_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG1, WDOG2, WDOG3, WDOG4, WDOG5 }
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { WDOG1_IRQn, WDOG2_IRQn, WDOG3_IRQn, WDOG4_IRQn, WDOG5_IRQn }

/* XCACHE - Peripheral instance base addresses */
/** Peripheral M33_CACHE_CTRLPC base address */
#define M33_CACHE_CTRLPC_BASE                    (0x44400000u)
/** Peripheral M33_CACHE_CTRLPC base pointer */
#define M33_CACHE_CTRLPC                         ((XCACHE_Type *)M33_CACHE_CTRLPC_BASE)
/** Peripheral M33_CACHE_CTRLPS base address */
#define M33_CACHE_CTRLPS_BASE                    (0x44400800u)
/** Peripheral M33_CACHE_CTRLPS base pointer */
#define M33_CACHE_CTRLPS                         ((XCACHE_Type *)M33_CACHE_CTRLPS_BASE)
/** Array initializer of XCACHE peripheral base addresses */
#define XCACHE_BASE_ADDRS                        { M33_CACHE_CTRLPC_BASE, M33_CACHE_CTRLPS_BASE }
/** Array initializer of XCACHE peripheral base pointers */
#define XCACHE_BASE_PTRS                         { M33_CACHE_CTRLPC, M33_CACHE_CTRLPS }

/* XSPI - Peripheral instance base addresses */
/** Peripheral XSPI1 base address */
#define XSPI1_BASE                               (0x42400000u)
/** Peripheral XSPI1 base pointer */
#define XSPI1                                    ((XSPI_Type *)XSPI1_BASE)
/** Array initializer of XSPI peripheral base addresses */
#define XSPI_BASE_ADDRS                          { 0u, XSPI1_BASE }
/** Array initializer of XSPI peripheral base pointers */
#define XSPI_BASE_PTRS                           { (XSPI_Type *)0u, XSPI1 }
/** Interrupt vectors for the XSPI peripheral type */
#define XSPI_IRQS                                { {NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn,}, {XSPI1_0_IRQn, XSPI1_1_IRQn, XSPI1_2_IRQn, XSPI1_3_IRQn, XSPI1_4_IRQn}  }
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /* XSPI AMBA address. */
  #define XSPI1_AMBA_BASE      (0x38000000u)
  #define XSPI1_AMBA_BASE_NS   (0x28000000u)
  #define XSPI_AMBA_BASES      {0x00000000u, 0x38000000u}
  #define XSPI_AMBA_BASES_NS   {0x00000000u, 0x28000000u}
#else
  /* XSPI AMBA address. */
  #define XSPI1_AMBA_BASE      (0x28000000u)
  #define XSPI_AMBA_BASES      {0x00000000u, 0x28000000u}
#endif


/* blitb9cf - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__BLITB9CF base address */
#define DISPLAY__SEERIS__BLITB9CF_BASE           (0x4B471000u)
/** Peripheral DISPLAY__SEERIS__BLITB9CF base pointer */
#define DISPLAY__SEERIS__BLITB9CF                ((blitb9cf_Type *)DISPLAY__SEERIS__BLITB9CF_BASE)
/** Array initializer of blitb9cf peripheral base addresses */
#define blitb9cf_BASE_ADDRS                      { DISPLAY__SEERIS__BLITB9CF_BASE }
/** Array initializer of blitb9cf peripheral base pointers */
#define blitb9cf_BASE_PTRS                       { DISPLAY__SEERIS__BLITB9CF }

/* blitbld - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__BLITBLD base address */
#define DISPLAY__SEERIS__BLITBLD_BASE            (0x4B470000u)
/** Peripheral DISPLAY__SEERIS__BLITBLD base pointer */
#define DISPLAY__SEERIS__BLITBLD                 ((blitbld_Type *)DISPLAY__SEERIS__BLITBLD_BASE)
/** Array initializer of blitbld peripheral base addresses */
#define blitbld_BASE_ADDRS                       { DISPLAY__SEERIS__BLITBLD_BASE }
/** Array initializer of blitbld peripheral base pointers */
#define blitbld_BASE_PTRS                        { DISPLAY__SEERIS__BLITBLD }

/* clut - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CLUT base address */
#define DISPLAY__SEERIS__CLUT_BASE               (0x4B450000u)
/** Peripheral DISPLAY__SEERIS__CLUT base pointer */
#define DISPLAY__SEERIS__CLUT                    ((clut_Type *)DISPLAY__SEERIS__CLUT_BASE)
/** Array initializer of clut peripheral base addresses */
#define clut_BASE_ADDRS                          { DISPLAY__SEERIS__CLUT_BASE }
/** Array initializer of clut peripheral base pointers */
#define clut_BASE_PTRS                           { DISPLAY__SEERIS__CLUT }

/* clut1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CLUT1 base address */
#define DISPLAY__SEERIS__CLUT1_BASE              (0x4B450400u)
/** Peripheral DISPLAY__SEERIS__CLUT1 base pointer */
#define DISPLAY__SEERIS__CLUT1                   ((clut1_Type *)DISPLAY__SEERIS__CLUT1_BASE)
/** Array initializer of clut1 peripheral base addresses */
#define clut1_BASE_ADDRS                         { DISPLAY__SEERIS__CLUT1_BASE }
/** Array initializer of clut1 peripheral base pointers */
#define clut1_BASE_PTRS                          { DISPLAY__SEERIS__CLUT1 }

/* clut9cfg - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CLUT9CFG base address */
#define DISPLAY__SEERIS__CLUT9CFG_BASE           (0x4B451000u)
/** Peripheral DISPLAY__SEERIS__CLUT9CFG base pointer */
#define DISPLAY__SEERIS__CLUT9CFG                ((clut9cfg_Type *)DISPLAY__SEERIS__CLUT9CFG_BASE)
/** Array initializer of clut9cfg peripheral base addresses */
#define clut9cfg_BASE_ADDRS                      { DISPLAY__SEERIS__CLUT9CFG_BASE }
/** Array initializer of clut9cfg peripheral base pointers */
#define clut9cfg_BASE_PTRS                       { DISPLAY__SEERIS__CLUT9CFG }

/* cmdseq - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CMDSEQ base address */
#define DISPLAY__SEERIS__CMDSEQ_BASE             (0x4B410000u)
/** Peripheral DISPLAY__SEERIS__CMDSEQ base pointer */
#define DISPLAY__SEERIS__CMDSEQ                  ((cmdseq_Type *)DISPLAY__SEERIS__CMDSEQ_BASE)
/** Array initializer of cmdseq peripheral base addresses */
#define cmdseq_BASE_ADDRS                        { DISPLAY__SEERIS__CMDSEQ_BASE }
/** Array initializer of cmdseq peripheral base pointers */
#define cmdseq_BASE_PTRS                         { DISPLAY__SEERIS__CMDSEQ }

/* cmdseq1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CMDSEQ1 base address */
#define DISPLAY__SEERIS__CMDSEQ1_BASE            (0x4B410100u)
/** Peripheral DISPLAY__SEERIS__CMDSEQ1 base pointer */
#define DISPLAY__SEERIS__CMDSEQ1                 ((cmdseq1_Type *)DISPLAY__SEERIS__CMDSEQ1_BASE)
/** Array initializer of cmdseq1 peripheral base addresses */
#define cmdseq1_BASE_ADDRS                       { DISPLAY__SEERIS__CMDSEQ1_BASE }
/** Array initializer of cmdseq1 peripheral base pointers */
#define cmdseq1_BASE_PTRS                        { DISPLAY__SEERIS__CMDSEQ1 }

/* cmdseq2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CMDSEQ2 base address */
#define DISPLAY__SEERIS__CMDSEQ2_BASE            (0x4B410180u)
/** Peripheral DISPLAY__SEERIS__CMDSEQ2 base pointer */
#define DISPLAY__SEERIS__CMDSEQ2                 ((cmdseq2_Type *)DISPLAY__SEERIS__CMDSEQ2_BASE)
/** Array initializer of cmdseq2 peripheral base addresses */
#define cmdseq2_BASE_ADDRS                       { DISPLAY__SEERIS__CMDSEQ2_BASE }
/** Array initializer of cmdseq2 peripheral base pointers */
#define cmdseq2_BASE_PTRS                        { DISPLAY__SEERIS__CMDSEQ2 }

/* cmdseqir - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CMDSEQIR base address */
#define DISPLAY__SEERIS__CMDSEQIR_BASE           (0x4B411000u)
/** Peripheral DISPLAY__SEERIS__CMDSEQIR base pointer */
#define DISPLAY__SEERIS__CMDSEQIR                ((cmdseqir_Type *)DISPLAY__SEERIS__CMDSEQIR_BASE)
/** Array initializer of cmdseqir peripheral base addresses */
#define cmdseqir_BASE_ADDRS                      { DISPLAY__SEERIS__CMDSEQIR_BASE }
/** Array initializer of cmdseqir peripheral base pointers */
#define cmdseqir_BASE_PTRS                       { DISPLAY__SEERIS__CMDSEQIR }

/* cmdseqma - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CMDSEQMA base address */
#define DISPLAY__SEERIS__CMDSEQMA_BASE           (0x4B403000u)
/** Peripheral DISPLAY__SEERIS__CMDSEQMA base pointer */
#define DISPLAY__SEERIS__CMDSEQMA                ((cmdseqma_Type *)DISPLAY__SEERIS__CMDSEQMA_BASE)
/** Array initializer of cmdseqma peripheral base addresses */
#define cmdseqma_BASE_ADDRS                      { DISPLAY__SEERIS__CMDSEQMA_BASE }
/** Array initializer of cmdseqma peripheral base pointers */
#define cmdseqma_BASE_PTRS                       { DISPLAY__SEERIS__CMDSEQMA }

/* constf0c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CONSTF0C base address */
#define DISPLAY__SEERIS__CONSTF0C_BASE           (0x4B4F1000u)
/** Peripheral DISPLAY__SEERIS__CONSTF0C base pointer */
#define DISPLAY__SEERIS__CONSTF0C                ((constf0c_Type *)DISPLAY__SEERIS__CONSTF0C_BASE)
/** Array initializer of constf0c peripheral base addresses */
#define constf0c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF0C_BASE }
/** Array initializer of constf0c peripheral base pointers */
#define constf0c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF0C }

/* constf1c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CONSTF1C base address */
#define DISPLAY__SEERIS__CONSTF1C_BASE           (0x4B531000u)
/** Peripheral DISPLAY__SEERIS__CONSTF1C base pointer */
#define DISPLAY__SEERIS__CONSTF1C                ((constf1c_Type *)DISPLAY__SEERIS__CONSTF1C_BASE)
/** Array initializer of constf1c peripheral base addresses */
#define constf1c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF1C_BASE }
/** Array initializer of constf1c peripheral base pointers */
#define constf1c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF1C }

/* constf4c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CONSTF4C base address */
#define DISPLAY__SEERIS__CONSTF4C_BASE           (0x4B501000u)
/** Peripheral DISPLAY__SEERIS__CONSTF4C base pointer */
#define DISPLAY__SEERIS__CONSTF4C                ((constf4c_Type *)DISPLAY__SEERIS__CONSTF4C_BASE)
/** Array initializer of constf4c peripheral base addresses */
#define constf4c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF4C_BASE }
/** Array initializer of constf4c peripheral base pointers */
#define constf4c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF4C }

/* constf5c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CONSTF5C base address */
#define DISPLAY__SEERIS__CONSTF5C_BASE           (0x4B541000u)
/** Peripheral DISPLAY__SEERIS__CONSTF5C base pointer */
#define DISPLAY__SEERIS__CONSTF5C                ((constf5c_Type *)DISPLAY__SEERIS__CONSTF5C_BASE)
/** Array initializer of constf5c peripheral base addresses */
#define constf5c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF5C_BASE }
/** Array initializer of constf5c peripheral base pointers */
#define constf5c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF5C }

/* constfr - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CONSTFR base address */
#define DISPLAY__SEERIS__CONSTFR_BASE            (0x4B4F0000u)
/** Peripheral DISPLAY__SEERIS__CONSTFR base pointer */
#define DISPLAY__SEERIS__CONSTFR                 ((constfr_Type *)DISPLAY__SEERIS__CONSTFR_BASE)
/** Array initializer of constfr peripheral base addresses */
#define constfr_BASE_ADDRS                       { DISPLAY__SEERIS__CONSTFR_BASE }
/** Array initializer of constfr peripheral base pointers */
#define constfr_BASE_PTRS                        { DISPLAY__SEERIS__CONSTFR }

/* constfr1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CONSTFR1 base address */
#define DISPLAY__SEERIS__CONSTFR1_BASE           (0x4B500000u)
/** Peripheral DISPLAY__SEERIS__CONSTFR1 base pointer */
#define DISPLAY__SEERIS__CONSTFR1                ((constfr1_Type *)DISPLAY__SEERIS__CONSTFR1_BASE)
/** Array initializer of constfr1 peripheral base addresses */
#define constfr1_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTFR1_BASE }
/** Array initializer of constfr1 peripheral base pointers */
#define constfr1_BASE_PTRS                       { DISPLAY__SEERIS__CONSTFR1 }

/* constfr2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CONSTFR2 base address */
#define DISPLAY__SEERIS__CONSTFR2_BASE           (0x4B530000u)
/** Peripheral DISPLAY__SEERIS__CONSTFR2 base pointer */
#define DISPLAY__SEERIS__CONSTFR2                ((constfr2_Type *)DISPLAY__SEERIS__CONSTFR2_BASE)
/** Array initializer of constfr2 peripheral base addresses */
#define constfr2_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTFR2_BASE }
/** Array initializer of constfr2 peripheral base pointers */
#define constfr2_BASE_PTRS                       { DISPLAY__SEERIS__CONSTFR2 }

/* constfr3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__CONSTFR3 base address */
#define DISPLAY__SEERIS__CONSTFR3_BASE           (0x4B540000u)
/** Peripheral DISPLAY__SEERIS__CONSTFR3 base pointer */
#define DISPLAY__SEERIS__CONSTFR3                ((constfr3_Type *)DISPLAY__SEERIS__CONSTFR3_BASE)
/** Array initializer of constfr3 peripheral base addresses */
#define constfr3_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTFR3_BASE }
/** Array initializer of constfr3 peripheral base pointers */
#define constfr3_BASE_PTRS                       { DISPLAY__SEERIS__CONSTFR3 }

/* displa0c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__DISPLA0C base address */
#define DISPLAY__SEERIS__DISPLA0C_BASE           (0x4B6F1000u)
/** Peripheral DISPLAY__SEERIS__DISPLA0C base pointer */
#define DISPLAY__SEERIS__DISPLA0C                ((displa0c_Type *)DISPLAY__SEERIS__DISPLA0C_BASE)
/** Array initializer of displa0c peripheral base addresses */
#define displa0c_BASE_ADDRS                      { DISPLAY__SEERIS__DISPLA0C_BASE }
/** Array initializer of displa0c peripheral base pointers */
#define displa0c_BASE_PTRS                       { DISPLAY__SEERIS__DISPLA0C }

/* displa1c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__DISPLA1C base address */
#define DISPLAY__SEERIS__DISPLA1C_BASE           (0x4B781000u)
/** Peripheral DISPLAY__SEERIS__DISPLA1C base pointer */
#define DISPLAY__SEERIS__DISPLA1C                ((displa1c_Type *)DISPLAY__SEERIS__DISPLA1C_BASE)
/** Array initializer of displa1c peripheral base addresses */
#define displa1c_BASE_ADDRS                      { DISPLAY__SEERIS__DISPLA1C_BASE }
/** Array initializer of displa1c peripheral base pointers */
#define displa1c_BASE_PTRS                       { DISPLAY__SEERIS__DISPLA1C }

/* dither - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__DITHER base address */
#define DISPLAY__SEERIS__DITHER_BASE             (0x4B6F0000u)
/** Peripheral DISPLAY__SEERIS__DITHER base pointer */
#define DISPLAY__SEERIS__DITHER                  ((dither_Type *)DISPLAY__SEERIS__DITHER_BASE)
/** Array initializer of dither peripheral base addresses */
#define dither_BASE_ADDRS                        { DISPLAY__SEERIS__DITHER_BASE }
/** Array initializer of dither peripheral base pointers */
#define dither_BASE_PTRS                         { DISPLAY__SEERIS__DITHER }

/* dither1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__DITHER1 base address */
#define DISPLAY__SEERIS__DITHER1_BASE            (0x4B780000u)
/** Peripheral DISPLAY__SEERIS__DITHER1 base pointer */
#define DISPLAY__SEERIS__DITHER1                 ((dither1_Type *)DISPLAY__SEERIS__DITHER1_BASE)
/** Array initializer of dither1 peripheral base addresses */
#define dither1_BASE_ADDRS                       { DISPLAY__SEERIS__DITHER1_BASE }
/** Array initializer of dither1 peripheral base pointers */
#define dither1_BASE_PTRS                        { DISPLAY__SEERIS__DITHER1 }

/* domainb1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__DOMAINB1 base address */
#define DISPLAY__SEERIS__DOMAINB1_BASE           (0x4B730000u)
/** Peripheral DISPLAY__SEERIS__DOMAINB1 base pointer */
#define DISPLAY__SEERIS__DOMAINB1                ((domainb1_Type *)DISPLAY__SEERIS__DOMAINB1_BASE)
/** Array initializer of domainb1 peripheral base addresses */
#define domainb1_BASE_ADDRS                      { DISPLAY__SEERIS__DOMAINB1_BASE }
/** Array initializer of domainb1 peripheral base pointers */
#define domainb1_BASE_PTRS                       { DISPLAY__SEERIS__DOMAINB1 }

/* domainbl - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__DOMAINBL base address */
#define DISPLAY__SEERIS__DOMAINBL_BASE           (0x4B6A0000u)
/** Peripheral DISPLAY__SEERIS__DOMAINBL base pointer */
#define DISPLAY__SEERIS__DOMAINBL                ((domainbl_Type *)DISPLAY__SEERIS__DOMAINBL_BASE)
/** Array initializer of domainbl peripheral base addresses */
#define domainbl_BASE_ADDRS                      { DISPLAY__SEERIS__DOMAINBL_BASE }
/** Array initializer of domainbl peripheral base pointers */
#define domainbl_BASE_PTRS                       { DISPLAY__SEERIS__DOMAINBL }

/* domainma - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__DOMAINMA base address */
#define DISPLAY__SEERIS__DOMAINMA_BASE           (0x4B402000u)
/** Peripheral DISPLAY__SEERIS__DOMAINMA base pointer */
#define DISPLAY__SEERIS__DOMAINMA                ((domainma_Type *)DISPLAY__SEERIS__DOMAINMA_BASE)
/** Array initializer of domainma peripheral base addresses */
#define domainma_BASE_ADDRS                      { DISPLAY__SEERIS__DOMAINMA_BASE }
/** Array initializer of domainma peripheral base pointers */
#define domainma_BASE_PTRS                       { DISPLAY__SEERIS__DOMAINMA }

/* extdst - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__EXTDST base address */
#define DISPLAY__SEERIS__EXTDST_BASE             (0x4B510000u)
/** Peripheral DISPLAY__SEERIS__EXTDST base pointer */
#define DISPLAY__SEERIS__EXTDST                  ((extdst_Type *)DISPLAY__SEERIS__EXTDST_BASE)
/** Array initializer of extdst peripheral base addresses */
#define extdst_BASE_ADDRS                        { DISPLAY__SEERIS__EXTDST_BASE }
/** Array initializer of extdst peripheral base pointers */
#define extdst_BASE_PTRS                         { DISPLAY__SEERIS__EXTDST }

/* extdst0c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__EXTDST0C base address */
#define DISPLAY__SEERIS__EXTDST0C_BASE           (0x4B511000u)
/** Peripheral DISPLAY__SEERIS__EXTDST0C base pointer */
#define DISPLAY__SEERIS__EXTDST0C                ((extdst0c_Type *)DISPLAY__SEERIS__EXTDST0C_BASE)
/** Array initializer of extdst0c peripheral base addresses */
#define extdst0c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST0C_BASE }
/** Array initializer of extdst0c peripheral base pointers */
#define extdst0c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST0C }

/* extdst1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__EXTDST1 base address */
#define DISPLAY__SEERIS__EXTDST1_BASE            (0x4B520000u)
/** Peripheral DISPLAY__SEERIS__EXTDST1 base pointer */
#define DISPLAY__SEERIS__EXTDST1                 ((extdst1_Type *)DISPLAY__SEERIS__EXTDST1_BASE)
/** Array initializer of extdst1 peripheral base addresses */
#define extdst1_BASE_ADDRS                       { DISPLAY__SEERIS__EXTDST1_BASE }
/** Array initializer of extdst1 peripheral base pointers */
#define extdst1_BASE_PTRS                        { DISPLAY__SEERIS__EXTDST1 }

/* extdst1c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__EXTDST1C base address */
#define DISPLAY__SEERIS__EXTDST1C_BASE           (0x4B551000u)
/** Peripheral DISPLAY__SEERIS__EXTDST1C base pointer */
#define DISPLAY__SEERIS__EXTDST1C                ((extdst1c_Type *)DISPLAY__SEERIS__EXTDST1C_BASE)
/** Array initializer of extdst1c peripheral base addresses */
#define extdst1c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST1C_BASE }
/** Array initializer of extdst1c peripheral base pointers */
#define extdst1c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST1C }

/* extdst2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__EXTDST2 base address */
#define DISPLAY__SEERIS__EXTDST2_BASE            (0x4B550000u)
/** Peripheral DISPLAY__SEERIS__EXTDST2 base pointer */
#define DISPLAY__SEERIS__EXTDST2                 ((extdst2_Type *)DISPLAY__SEERIS__EXTDST2_BASE)
/** Array initializer of extdst2 peripheral base addresses */
#define extdst2_BASE_ADDRS                       { DISPLAY__SEERIS__EXTDST2_BASE }
/** Array initializer of extdst2 peripheral base pointers */
#define extdst2_BASE_PTRS                        { DISPLAY__SEERIS__EXTDST2 }

/* extdst3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__EXTDST3 base address */
#define DISPLAY__SEERIS__EXTDST3_BASE            (0x4B560000u)
/** Peripheral DISPLAY__SEERIS__EXTDST3 base pointer */
#define DISPLAY__SEERIS__EXTDST3                 ((extdst3_Type *)DISPLAY__SEERIS__EXTDST3_BASE)
/** Array initializer of extdst3 peripheral base addresses */
#define extdst3_BASE_ADDRS                       { DISPLAY__SEERIS__EXTDST3_BASE }
/** Array initializer of extdst3 peripheral base pointers */
#define extdst3_BASE_PTRS                        { DISPLAY__SEERIS__EXTDST3 }

/* extdst4c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__EXTDST4C base address */
#define DISPLAY__SEERIS__EXTDST4C_BASE           (0x4B521000u)
/** Peripheral DISPLAY__SEERIS__EXTDST4C base pointer */
#define DISPLAY__SEERIS__EXTDST4C                ((extdst4c_Type *)DISPLAY__SEERIS__EXTDST4C_BASE)
/** Array initializer of extdst4c peripheral base addresses */
#define extdst4c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST4C_BASE }
/** Array initializer of extdst4c peripheral base pointers */
#define extdst4c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST4C }

/* extdst5c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__EXTDST5C base address */
#define DISPLAY__SEERIS__EXTDST5C_BASE           (0x4B561000u)
/** Peripheral DISPLAY__SEERIS__EXTDST5C base pointer */
#define DISPLAY__SEERIS__EXTDST5C                ((extdst5c_Type *)DISPLAY__SEERIS__EXTDST5C_BASE)
/** Array initializer of extdst5c peripheral base addresses */
#define extdst5c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST5C_BASE }
/** Array initializer of extdst5c peripheral base pointers */
#define extdst5c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST5C }

/* fetchd9c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHD9C base address */
#define DISPLAY__SEERIS__FETCHD9C_BASE           (0x4B491000u)
/** Peripheral DISPLAY__SEERIS__FETCHD9C base pointer */
#define DISPLAY__SEERIS__FETCHD9C                ((fetchd9c_Type *)DISPLAY__SEERIS__FETCHD9C_BASE)
/** Array initializer of fetchd9c peripheral base addresses */
#define fetchd9c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHD9C_BASE }
/** Array initializer of fetchd9c peripheral base pointers */
#define fetchd9c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHD9C }

/* fetchde1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHDE1 base address */
#define DISPLAY__SEERIS__FETCHDE1_BASE           (0x4B490028u)
/** Peripheral DISPLAY__SEERIS__FETCHDE1 base pointer */
#define DISPLAY__SEERIS__FETCHDE1                ((fetchde1_Type *)DISPLAY__SEERIS__FETCHDE1_BASE)
/** Array initializer of fetchde1 peripheral base addresses */
#define fetchde1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE1_BASE }
/** Array initializer of fetchde1 peripheral base pointers */
#define fetchde1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE1 }

/* fetchde2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHDE2 base address */
#define DISPLAY__SEERIS__FETCHDE2_BASE           (0x4B490060u)
/** Peripheral DISPLAY__SEERIS__FETCHDE2 base pointer */
#define DISPLAY__SEERIS__FETCHDE2                ((fetchde2_Type *)DISPLAY__SEERIS__FETCHDE2_BASE)
/** Array initializer of fetchde2 peripheral base addresses */
#define fetchde2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE2_BASE }
/** Array initializer of fetchde2 peripheral base pointers */
#define fetchde2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE2 }

/* fetchde3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHDE3 base address */
#define DISPLAY__SEERIS__FETCHDE3_BASE           (0x4B490088u)
/** Peripheral DISPLAY__SEERIS__FETCHDE3 base pointer */
#define DISPLAY__SEERIS__FETCHDE3                ((fetchde3_Type *)DISPLAY__SEERIS__FETCHDE3_BASE)
/** Array initializer of fetchde3 peripheral base addresses */
#define fetchde3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE3_BASE }
/** Array initializer of fetchde3 peripheral base pointers */
#define fetchde3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE3 }

/* fetchde4 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHDE4 base address */
#define DISPLAY__SEERIS__FETCHDE4_BASE           (0x4B490098u)
/** Peripheral DISPLAY__SEERIS__FETCHDE4 base pointer */
#define DISPLAY__SEERIS__FETCHDE4                ((fetchde4_Type *)DISPLAY__SEERIS__FETCHDE4_BASE)
/** Array initializer of fetchde4 peripheral base addresses */
#define fetchde4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE4_BASE }
/** Array initializer of fetchde4 peripheral base pointers */
#define fetchde4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE4 }

/* fetchde5 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHDE5 base address */
#define DISPLAY__SEERIS__FETCHDE5_BASE           (0x4B490400u)
/** Peripheral DISPLAY__SEERIS__FETCHDE5 base pointer */
#define DISPLAY__SEERIS__FETCHDE5                ((fetchde5_Type *)DISPLAY__SEERIS__FETCHDE5_BASE)
/** Array initializer of fetchde5 peripheral base addresses */
#define fetchde5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE5_BASE }
/** Array initializer of fetchde5 peripheral base pointers */
#define fetchde5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE5 }

/* fetchdec - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHDEC base address */
#define DISPLAY__SEERIS__FETCHDEC_BASE           (0x4B490000u)
/** Peripheral DISPLAY__SEERIS__FETCHDEC base pointer */
#define DISPLAY__SEERIS__FETCHDEC                ((fetchdec_Type *)DISPLAY__SEERIS__FETCHDEC_BASE)
/** Array initializer of fetchdec peripheral base addresses */
#define fetchdec_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDEC_BASE }
/** Array initializer of fetchdec peripheral base pointers */
#define fetchdec_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDEC }

/* fetche0c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHE0C base address */
#define DISPLAY__SEERIS__FETCHE0C_BASE           (0x4B601000u)
/** Peripheral DISPLAY__SEERIS__FETCHE0C base pointer */
#define DISPLAY__SEERIS__FETCHE0C                ((fetche0c_Type *)DISPLAY__SEERIS__FETCHE0C_BASE)
/** Array initializer of fetche0c peripheral base addresses */
#define fetche0c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE0C_BASE }
/** Array initializer of fetche0c peripheral base pointers */
#define fetche0c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE0C }

/* fetche10 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHE10 base address */
#define DISPLAY__SEERIS__FETCHE10_BASE           (0x4B620000u)
/** Peripheral DISPLAY__SEERIS__FETCHE10 base pointer */
#define DISPLAY__SEERIS__FETCHE10                ((fetche10_Type *)DISPLAY__SEERIS__FETCHE10_BASE)
/** Array initializer of fetche10 peripheral base addresses */
#define fetche10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE10_BASE }
/** Array initializer of fetche10 peripheral base pointers */
#define fetche10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE10 }

/* fetche11 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHE11 base address */
#define DISPLAY__SEERIS__FETCHE11_BASE           (0x4B620010u)
/** Peripheral DISPLAY__SEERIS__FETCHE11 base pointer */
#define DISPLAY__SEERIS__FETCHE11                ((fetche11_Type *)DISPLAY__SEERIS__FETCHE11_BASE)
/** Array initializer of fetche11 peripheral base addresses */
#define fetche11_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE11_BASE }
/** Array initializer of fetche11 peripheral base pointers */
#define fetche11_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE11 }

/* fetche12 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHE12 base address */
#define DISPLAY__SEERIS__FETCHE12_BASE           (0x4B620048u)
/** Peripheral DISPLAY__SEERIS__FETCHE12 base pointer */
#define DISPLAY__SEERIS__FETCHE12                ((fetche12_Type *)DISPLAY__SEERIS__FETCHE12_BASE)
/** Array initializer of fetche12 peripheral base addresses */
#define fetche12_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE12_BASE }
/** Array initializer of fetche12 peripheral base pointers */
#define fetche12_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE12 }

/* fetche13 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHE13 base address */
#define DISPLAY__SEERIS__FETCHE13_BASE           (0x4B620060u)
/** Peripheral DISPLAY__SEERIS__FETCHE13 base pointer */
#define DISPLAY__SEERIS__FETCHE13                ((fetche13_Type *)DISPLAY__SEERIS__FETCHE13_BASE)
/** Array initializer of fetche13 peripheral base addresses */
#define fetche13_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE13_BASE }
/** Array initializer of fetche13 peripheral base pointers */
#define fetche13_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE13 }

/* fetche14 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHE14 base address */
#define DISPLAY__SEERIS__FETCHE14_BASE           (0x4B620068u)
/** Peripheral DISPLAY__SEERIS__FETCHE14 base pointer */
#define DISPLAY__SEERIS__FETCHE14                ((fetche14_Type *)DISPLAY__SEERIS__FETCHE14_BASE)
/** Array initializer of fetche14 peripheral base addresses */
#define fetche14_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE14_BASE }
/** Array initializer of fetche14 peripheral base pointers */
#define fetche14_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE14 }

/* fetche1c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHE1C base address */
#define DISPLAY__SEERIS__FETCHE1C_BASE           (0x4B621000u)
/** Peripheral DISPLAY__SEERIS__FETCHE1C base pointer */
#define DISPLAY__SEERIS__FETCHE1C                ((fetche1c_Type *)DISPLAY__SEERIS__FETCHE1C_BASE)
/** Array initializer of fetche1c peripheral base addresses */
#define fetche1c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE1C_BASE }
/** Array initializer of fetche1c peripheral base pointers */
#define fetche1c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE1C }

/* fetche9c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHE9C base address */
#define DISPLAY__SEERIS__FETCHE9C_BASE           (0x4B4A1000u)
/** Peripheral DISPLAY__SEERIS__FETCHE9C base pointer */
#define DISPLAY__SEERIS__FETCHE9C                ((fetche9c_Type *)DISPLAY__SEERIS__FETCHE9C_BASE)
/** Array initializer of fetche9c peripheral base addresses */
#define fetche9c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE9C_BASE }
/** Array initializer of fetche9c peripheral base pointers */
#define fetche9c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE9C }

/* fetchec1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHEC1 base address */
#define DISPLAY__SEERIS__FETCHEC1_BASE           (0x4B4A0010u)
/** Peripheral DISPLAY__SEERIS__FETCHEC1 base pointer */
#define DISPLAY__SEERIS__FETCHEC1                ((fetchec1_Type *)DISPLAY__SEERIS__FETCHEC1_BASE)
/** Array initializer of fetchec1 peripheral base addresses */
#define fetchec1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC1_BASE }
/** Array initializer of fetchec1 peripheral base pointers */
#define fetchec1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC1 }

/* fetchec2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHEC2 base address */
#define DISPLAY__SEERIS__FETCHEC2_BASE           (0x4B4A0048u)
/** Peripheral DISPLAY__SEERIS__FETCHEC2 base pointer */
#define DISPLAY__SEERIS__FETCHEC2                ((fetchec2_Type *)DISPLAY__SEERIS__FETCHEC2_BASE)
/** Array initializer of fetchec2 peripheral base addresses */
#define fetchec2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC2_BASE }
/** Array initializer of fetchec2 peripheral base pointers */
#define fetchec2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC2 }

/* fetchec3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHEC3 base address */
#define DISPLAY__SEERIS__FETCHEC3_BASE           (0x4B4A0060u)
/** Peripheral DISPLAY__SEERIS__FETCHEC3 base pointer */
#define DISPLAY__SEERIS__FETCHEC3                ((fetchec3_Type *)DISPLAY__SEERIS__FETCHEC3_BASE)
/** Array initializer of fetchec3 peripheral base addresses */
#define fetchec3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC3_BASE }
/** Array initializer of fetchec3 peripheral base pointers */
#define fetchec3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC3 }

/* fetchec4 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHEC4 base address */
#define DISPLAY__SEERIS__FETCHEC4_BASE           (0x4B4A0068u)
/** Peripheral DISPLAY__SEERIS__FETCHEC4 base pointer */
#define DISPLAY__SEERIS__FETCHEC4                ((fetchec4_Type *)DISPLAY__SEERIS__FETCHEC4_BASE)
/** Array initializer of fetchec4 peripheral base addresses */
#define fetchec4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC4_BASE }
/** Array initializer of fetchec4 peripheral base pointers */
#define fetchec4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC4 }

/* fetchec5 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHEC5 base address */
#define DISPLAY__SEERIS__FETCHEC5_BASE           (0x4B600000u)
/** Peripheral DISPLAY__SEERIS__FETCHEC5 base pointer */
#define DISPLAY__SEERIS__FETCHEC5                ((fetchec5_Type *)DISPLAY__SEERIS__FETCHEC5_BASE)
/** Array initializer of fetchec5 peripheral base addresses */
#define fetchec5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC5_BASE }
/** Array initializer of fetchec5 peripheral base pointers */
#define fetchec5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC5 }

/* fetchec6 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHEC6 base address */
#define DISPLAY__SEERIS__FETCHEC6_BASE           (0x4B600010u)
/** Peripheral DISPLAY__SEERIS__FETCHEC6 base pointer */
#define DISPLAY__SEERIS__FETCHEC6                ((fetchec6_Type *)DISPLAY__SEERIS__FETCHEC6_BASE)
/** Array initializer of fetchec6 peripheral base addresses */
#define fetchec6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC6_BASE }
/** Array initializer of fetchec6 peripheral base pointers */
#define fetchec6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC6 }

/* fetchec7 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHEC7 base address */
#define DISPLAY__SEERIS__FETCHEC7_BASE           (0x4B600048u)
/** Peripheral DISPLAY__SEERIS__FETCHEC7 base pointer */
#define DISPLAY__SEERIS__FETCHEC7                ((fetchec7_Type *)DISPLAY__SEERIS__FETCHEC7_BASE)
/** Array initializer of fetchec7 peripheral base addresses */
#define fetchec7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC7_BASE }
/** Array initializer of fetchec7 peripheral base pointers */
#define fetchec7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC7 }

/* fetchec8 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHEC8 base address */
#define DISPLAY__SEERIS__FETCHEC8_BASE           (0x4B600060u)
/** Peripheral DISPLAY__SEERIS__FETCHEC8 base pointer */
#define DISPLAY__SEERIS__FETCHEC8                ((fetchec8_Type *)DISPLAY__SEERIS__FETCHEC8_BASE)
/** Array initializer of fetchec8 peripheral base addresses */
#define fetchec8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC8_BASE }
/** Array initializer of fetchec8 peripheral base pointers */
#define fetchec8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC8 }

/* fetchec9 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHEC9 base address */
#define DISPLAY__SEERIS__FETCHEC9_BASE           (0x4B600068u)
/** Peripheral DISPLAY__SEERIS__FETCHEC9 base pointer */
#define DISPLAY__SEERIS__FETCHEC9                ((fetchec9_Type *)DISPLAY__SEERIS__FETCHEC9_BASE)
/** Array initializer of fetchec9 peripheral base addresses */
#define fetchec9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC9_BASE }
/** Array initializer of fetchec9 peripheral base pointers */
#define fetchec9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC9 }

/* fetcheco - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHECO base address */
#define DISPLAY__SEERIS__FETCHECO_BASE           (0x4B4A0000u)
/** Peripheral DISPLAY__SEERIS__FETCHECO base pointer */
#define DISPLAY__SEERIS__FETCHECO                ((fetcheco_Type *)DISPLAY__SEERIS__FETCHECO_BASE)
/** Array initializer of fetcheco peripheral base addresses */
#define fetcheco_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHECO_BASE }
/** Array initializer of fetcheco peripheral base pointers */
#define fetcheco_BASE_PTRS                       { DISPLAY__SEERIS__FETCHECO }

/* fetchl0c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL0C base address */
#define DISPLAY__SEERIS__FETCHL0C_BASE           (0x4B5C1000u)
/** Peripheral DISPLAY__SEERIS__FETCHL0C base pointer */
#define DISPLAY__SEERIS__FETCHL0C                ((fetchl0c_Type *)DISPLAY__SEERIS__FETCHL0C_BASE)
/** Array initializer of fetchl0c peripheral base addresses */
#define fetchl0c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL0C_BASE }
/** Array initializer of fetchl0c peripheral base pointers */
#define fetchl0c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL0C }

/* fetchl10 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL10 base address */
#define DISPLAY__SEERIS__FETCHL10_BASE           (0x4B5C01F8u)
/** Peripheral DISPLAY__SEERIS__FETCHL10 base pointer */
#define DISPLAY__SEERIS__FETCHL10                ((fetchl10_Type *)DISPLAY__SEERIS__FETCHL10_BASE)
/** Array initializer of fetchl10 peripheral base addresses */
#define fetchl10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL10_BASE }
/** Array initializer of fetchl10 peripheral base pointers */
#define fetchl10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL10 }

/* fetchl11 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL11 base address */
#define DISPLAY__SEERIS__FETCHL11_BASE           (0x4B5C0200u)
/** Peripheral DISPLAY__SEERIS__FETCHL11 base pointer */
#define DISPLAY__SEERIS__FETCHL11                ((fetchl11_Type *)DISPLAY__SEERIS__FETCHL11_BASE)
/** Array initializer of fetchl11 peripheral base addresses */
#define fetchl11_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL11_BASE }
/** Array initializer of fetchl11 peripheral base pointers */
#define fetchl11_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL11 }

/* fetchl12 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL12 base address */
#define DISPLAY__SEERIS__FETCHL12_BASE           (0x4B5C0400u)
/** Peripheral DISPLAY__SEERIS__FETCHL12 base pointer */
#define DISPLAY__SEERIS__FETCHL12                ((fetchl12_Type *)DISPLAY__SEERIS__FETCHL12_BASE)
/** Array initializer of fetchl12 peripheral base addresses */
#define fetchl12_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL12_BASE }
/** Array initializer of fetchl12 peripheral base pointers */
#define fetchl12_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL12 }

/* fetchl13 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL13 base address */
#define DISPLAY__SEERIS__FETCHL13_BASE           (0x4B5D0000u)
/** Peripheral DISPLAY__SEERIS__FETCHL13 base pointer */
#define DISPLAY__SEERIS__FETCHL13                ((fetchl13_Type *)DISPLAY__SEERIS__FETCHL13_BASE)
/** Array initializer of fetchl13 peripheral base addresses */
#define fetchl13_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL13_BASE }
/** Array initializer of fetchl13 peripheral base pointers */
#define fetchl13_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL13 }

/* fetchl14 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL14 base address */
#define DISPLAY__SEERIS__FETCHL14_BASE           (0x4B5D0018u)
/** Peripheral DISPLAY__SEERIS__FETCHL14 base pointer */
#define DISPLAY__SEERIS__FETCHL14                ((fetchl14_Type *)DISPLAY__SEERIS__FETCHL14_BASE)
/** Array initializer of fetchl14 peripheral base addresses */
#define fetchl14_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL14_BASE }
/** Array initializer of fetchl14 peripheral base pointers */
#define fetchl14_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL14 }

/* fetchl15 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL15 base address */
#define DISPLAY__SEERIS__FETCHL15_BASE           (0x4B5D0050u)
/** Peripheral DISPLAY__SEERIS__FETCHL15 base pointer */
#define DISPLAY__SEERIS__FETCHL15                ((fetchl15_Type *)DISPLAY__SEERIS__FETCHL15_BASE)
/** Array initializer of fetchl15 peripheral base addresses */
#define fetchl15_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL15_BASE }
/** Array initializer of fetchl15 peripheral base pointers */
#define fetchl15_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL15 }

/* fetchl16 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL16 base address */
#define DISPLAY__SEERIS__FETCHL16_BASE           (0x4B5D0088u)
/** Peripheral DISPLAY__SEERIS__FETCHL16 base pointer */
#define DISPLAY__SEERIS__FETCHL16                ((fetchl16_Type *)DISPLAY__SEERIS__FETCHL16_BASE)
/** Array initializer of fetchl16 peripheral base addresses */
#define fetchl16_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL16_BASE }
/** Array initializer of fetchl16 peripheral base pointers */
#define fetchl16_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL16 }

/* fetchl17 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL17 base address */
#define DISPLAY__SEERIS__FETCHL17_BASE           (0x4B5D00C0u)
/** Peripheral DISPLAY__SEERIS__FETCHL17 base pointer */
#define DISPLAY__SEERIS__FETCHL17                ((fetchl17_Type *)DISPLAY__SEERIS__FETCHL17_BASE)
/** Array initializer of fetchl17 peripheral base addresses */
#define fetchl17_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL17_BASE }
/** Array initializer of fetchl17 peripheral base pointers */
#define fetchl17_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL17 }

/* fetchl18 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL18 base address */
#define DISPLAY__SEERIS__FETCHL18_BASE           (0x4B5D00F8u)
/** Peripheral DISPLAY__SEERIS__FETCHL18 base pointer */
#define DISPLAY__SEERIS__FETCHL18                ((fetchl18_Type *)DISPLAY__SEERIS__FETCHL18_BASE)
/** Array initializer of fetchl18 peripheral base addresses */
#define fetchl18_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL18_BASE }
/** Array initializer of fetchl18 peripheral base pointers */
#define fetchl18_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL18 }

/* fetchl19 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL19 base address */
#define DISPLAY__SEERIS__FETCHL19_BASE           (0x4B5D0130u)
/** Peripheral DISPLAY__SEERIS__FETCHL19 base pointer */
#define DISPLAY__SEERIS__FETCHL19                ((fetchl19_Type *)DISPLAY__SEERIS__FETCHL19_BASE)
/** Array initializer of fetchl19 peripheral base addresses */
#define fetchl19_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL19_BASE }
/** Array initializer of fetchl19 peripheral base pointers */
#define fetchl19_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL19 }

/* fetchl1c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL1C base address */
#define DISPLAY__SEERIS__FETCHL1C_BASE           (0x4B5D1000u)
/** Peripheral DISPLAY__SEERIS__FETCHL1C base pointer */
#define DISPLAY__SEERIS__FETCHL1C                ((fetchl1c_Type *)DISPLAY__SEERIS__FETCHL1C_BASE)
/** Array initializer of fetchl1c peripheral base addresses */
#define fetchl1c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL1C_BASE }
/** Array initializer of fetchl1c peripheral base pointers */
#define fetchl1c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL1C }

/* fetchl20 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL20 base address */
#define DISPLAY__SEERIS__FETCHL20_BASE           (0x4B5D0168u)
/** Peripheral DISPLAY__SEERIS__FETCHL20 base pointer */
#define DISPLAY__SEERIS__FETCHL20                ((fetchl20_Type *)DISPLAY__SEERIS__FETCHL20_BASE)
/** Array initializer of fetchl20 peripheral base addresses */
#define fetchl20_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL20_BASE }
/** Array initializer of fetchl20 peripheral base pointers */
#define fetchl20_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL20 }

/* fetchl21 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL21 base address */
#define DISPLAY__SEERIS__FETCHL21_BASE           (0x4B5D01A0u)
/** Peripheral DISPLAY__SEERIS__FETCHL21 base pointer */
#define DISPLAY__SEERIS__FETCHL21                ((fetchl21_Type *)DISPLAY__SEERIS__FETCHL21_BASE)
/** Array initializer of fetchl21 peripheral base addresses */
#define fetchl21_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL21_BASE }
/** Array initializer of fetchl21 peripheral base pointers */
#define fetchl21_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL21 }

/* fetchl22 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL22 base address */
#define DISPLAY__SEERIS__FETCHL22_BASE           (0x4B5D01D8u)
/** Peripheral DISPLAY__SEERIS__FETCHL22 base pointer */
#define DISPLAY__SEERIS__FETCHL22                ((fetchl22_Type *)DISPLAY__SEERIS__FETCHL22_BASE)
/** Array initializer of fetchl22 peripheral base addresses */
#define fetchl22_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL22_BASE }
/** Array initializer of fetchl22 peripheral base pointers */
#define fetchl22_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL22 }

/* fetchl23 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL23 base address */
#define DISPLAY__SEERIS__FETCHL23_BASE           (0x4B5D01F8u)
/** Peripheral DISPLAY__SEERIS__FETCHL23 base pointer */
#define DISPLAY__SEERIS__FETCHL23                ((fetchl23_Type *)DISPLAY__SEERIS__FETCHL23_BASE)
/** Array initializer of fetchl23 peripheral base addresses */
#define fetchl23_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL23_BASE }
/** Array initializer of fetchl23 peripheral base pointers */
#define fetchl23_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL23 }

/* fetchl24 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL24 base address */
#define DISPLAY__SEERIS__FETCHL24_BASE           (0x4B5D0200u)
/** Peripheral DISPLAY__SEERIS__FETCHL24 base pointer */
#define DISPLAY__SEERIS__FETCHL24                ((fetchl24_Type *)DISPLAY__SEERIS__FETCHL24_BASE)
/** Array initializer of fetchl24 peripheral base addresses */
#define fetchl24_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL24_BASE }
/** Array initializer of fetchl24 peripheral base pointers */
#define fetchl24_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL24 }

/* fetchl25 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHL25 base address */
#define DISPLAY__SEERIS__FETCHL25_BASE           (0x4B5D0400u)
/** Peripheral DISPLAY__SEERIS__FETCHL25 base pointer */
#define DISPLAY__SEERIS__FETCHL25                ((fetchl25_Type *)DISPLAY__SEERIS__FETCHL25_BASE)
/** Array initializer of fetchl25 peripheral base addresses */
#define fetchl25_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL25_BASE }
/** Array initializer of fetchl25 peripheral base pointers */
#define fetchl25_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL25 }

/* fetchla1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHLA1 base address */
#define DISPLAY__SEERIS__FETCHLA1_BASE           (0x4B5C0018u)
/** Peripheral DISPLAY__SEERIS__FETCHLA1 base pointer */
#define DISPLAY__SEERIS__FETCHLA1                ((fetchla1_Type *)DISPLAY__SEERIS__FETCHLA1_BASE)
/** Array initializer of fetchla1 peripheral base addresses */
#define fetchla1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA1_BASE }
/** Array initializer of fetchla1 peripheral base pointers */
#define fetchla1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA1 }

/* fetchla2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHLA2 base address */
#define DISPLAY__SEERIS__FETCHLA2_BASE           (0x4B5C0050u)
/** Peripheral DISPLAY__SEERIS__FETCHLA2 base pointer */
#define DISPLAY__SEERIS__FETCHLA2                ((fetchla2_Type *)DISPLAY__SEERIS__FETCHLA2_BASE)
/** Array initializer of fetchla2 peripheral base addresses */
#define fetchla2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA2_BASE }
/** Array initializer of fetchla2 peripheral base pointers */
#define fetchla2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA2 }

/* fetchla3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHLA3 base address */
#define DISPLAY__SEERIS__FETCHLA3_BASE           (0x4B5C0088u)
/** Peripheral DISPLAY__SEERIS__FETCHLA3 base pointer */
#define DISPLAY__SEERIS__FETCHLA3                ((fetchla3_Type *)DISPLAY__SEERIS__FETCHLA3_BASE)
/** Array initializer of fetchla3 peripheral base addresses */
#define fetchla3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA3_BASE }
/** Array initializer of fetchla3 peripheral base pointers */
#define fetchla3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA3 }

/* fetchla4 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHLA4 base address */
#define DISPLAY__SEERIS__FETCHLA4_BASE           (0x4B5C00C0u)
/** Peripheral DISPLAY__SEERIS__FETCHLA4 base pointer */
#define DISPLAY__SEERIS__FETCHLA4                ((fetchla4_Type *)DISPLAY__SEERIS__FETCHLA4_BASE)
/** Array initializer of fetchla4 peripheral base addresses */
#define fetchla4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA4_BASE }
/** Array initializer of fetchla4 peripheral base pointers */
#define fetchla4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA4 }

/* fetchla5 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHLA5 base address */
#define DISPLAY__SEERIS__FETCHLA5_BASE           (0x4B5C00F8u)
/** Peripheral DISPLAY__SEERIS__FETCHLA5 base pointer */
#define DISPLAY__SEERIS__FETCHLA5                ((fetchla5_Type *)DISPLAY__SEERIS__FETCHLA5_BASE)
/** Array initializer of fetchla5 peripheral base addresses */
#define fetchla5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA5_BASE }
/** Array initializer of fetchla5 peripheral base pointers */
#define fetchla5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA5 }

/* fetchla6 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHLA6 base address */
#define DISPLAY__SEERIS__FETCHLA6_BASE           (0x4B5C0130u)
/** Peripheral DISPLAY__SEERIS__FETCHLA6 base pointer */
#define DISPLAY__SEERIS__FETCHLA6                ((fetchla6_Type *)DISPLAY__SEERIS__FETCHLA6_BASE)
/** Array initializer of fetchla6 peripheral base addresses */
#define fetchla6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA6_BASE }
/** Array initializer of fetchla6 peripheral base pointers */
#define fetchla6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA6 }

/* fetchla7 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHLA7 base address */
#define DISPLAY__SEERIS__FETCHLA7_BASE           (0x4B5C0168u)
/** Peripheral DISPLAY__SEERIS__FETCHLA7 base pointer */
#define DISPLAY__SEERIS__FETCHLA7                ((fetchla7_Type *)DISPLAY__SEERIS__FETCHLA7_BASE)
/** Array initializer of fetchla7 peripheral base addresses */
#define fetchla7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA7_BASE }
/** Array initializer of fetchla7 peripheral base pointers */
#define fetchla7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA7 }

/* fetchla8 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHLA8 base address */
#define DISPLAY__SEERIS__FETCHLA8_BASE           (0x4B5C01A0u)
/** Peripheral DISPLAY__SEERIS__FETCHLA8 base pointer */
#define DISPLAY__SEERIS__FETCHLA8                ((fetchla8_Type *)DISPLAY__SEERIS__FETCHLA8_BASE)
/** Array initializer of fetchla8 peripheral base addresses */
#define fetchla8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA8_BASE }
/** Array initializer of fetchla8 peripheral base pointers */
#define fetchla8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA8 }

/* fetchla9 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHLA9 base address */
#define DISPLAY__SEERIS__FETCHLA9_BASE           (0x4B5C01D8u)
/** Peripheral DISPLAY__SEERIS__FETCHLA9 base pointer */
#define DISPLAY__SEERIS__FETCHLA9                ((fetchla9_Type *)DISPLAY__SEERIS__FETCHLA9_BASE)
/** Array initializer of fetchla9 peripheral base addresses */
#define fetchla9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA9_BASE }
/** Array initializer of fetchla9 peripheral base pointers */
#define fetchla9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA9 }

/* fetchlay - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHLAY base address */
#define DISPLAY__SEERIS__FETCHLAY_BASE           (0x4B5C0000u)
/** Peripheral DISPLAY__SEERIS__FETCHLAY base pointer */
#define DISPLAY__SEERIS__FETCHLAY                ((fetchlay_Type *)DISPLAY__SEERIS__FETCHLAY_BASE)
/** Array initializer of fetchlay peripheral base addresses */
#define fetchlay_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLAY_BASE }
/** Array initializer of fetchlay peripheral base pointers */
#define fetchlay_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLAY }

/* fetchr10 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHR10 base address */
#define DISPLAY__SEERIS__FETCHR10_BASE           (0x4B484000u)
/** Peripheral DISPLAY__SEERIS__FETCHR10 base pointer */
#define DISPLAY__SEERIS__FETCHR10                ((fetchr10_Type *)DISPLAY__SEERIS__FETCHR10_BASE)
/** Array initializer of fetchr10 peripheral base addresses */
#define fetchr10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHR10_BASE }
/** Array initializer of fetchr10 peripheral base pointers */
#define fetchr10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHR10 }

/* fetchr9c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHR9C base address */
#define DISPLAY__SEERIS__FETCHR9C_BASE           (0x4B486000u)
/** Peripheral DISPLAY__SEERIS__FETCHR9C base pointer */
#define DISPLAY__SEERIS__FETCHR9C                ((fetchr9c_Type *)DISPLAY__SEERIS__FETCHR9C_BASE)
/** Array initializer of fetchr9c peripheral base addresses */
#define fetchr9c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHR9C_BASE }
/** Array initializer of fetchr9c peripheral base pointers */
#define fetchr9c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHR9C }

/* fetchro1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHRO1 base address */
#define DISPLAY__SEERIS__FETCHRO1_BASE           (0x4B480020u)
/** Peripheral DISPLAY__SEERIS__FETCHRO1 base pointer */
#define DISPLAY__SEERIS__FETCHRO1                ((fetchro1_Type *)DISPLAY__SEERIS__FETCHRO1_BASE)
/** Array initializer of fetchro1 peripheral base addresses */
#define fetchro1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO1_BASE }
/** Array initializer of fetchro1 peripheral base pointers */
#define fetchro1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO1 }

/* fetchro2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHRO2 base address */
#define DISPLAY__SEERIS__FETCHRO2_BASE           (0x4B480058u)
/** Peripheral DISPLAY__SEERIS__FETCHRO2 base pointer */
#define DISPLAY__SEERIS__FETCHRO2                ((fetchro2_Type *)DISPLAY__SEERIS__FETCHRO2_BASE)
/** Array initializer of fetchro2 peripheral base addresses */
#define fetchro2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO2_BASE }
/** Array initializer of fetchro2 peripheral base pointers */
#define fetchro2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO2 }

/* fetchro3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHRO3 base address */
#define DISPLAY__SEERIS__FETCHRO3_BASE           (0x4B4800A0u)
/** Peripheral DISPLAY__SEERIS__FETCHRO3 base pointer */
#define DISPLAY__SEERIS__FETCHRO3                ((fetchro3_Type *)DISPLAY__SEERIS__FETCHRO3_BASE)
/** Array initializer of fetchro3 peripheral base addresses */
#define fetchro3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO3_BASE }
/** Array initializer of fetchro3 peripheral base pointers */
#define fetchro3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO3 }

/* fetchro4 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHRO4 base address */
#define DISPLAY__SEERIS__FETCHRO4_BASE           (0x4B4800B0u)
/** Peripheral DISPLAY__SEERIS__FETCHRO4 base pointer */
#define DISPLAY__SEERIS__FETCHRO4                ((fetchro4_Type *)DISPLAY__SEERIS__FETCHRO4_BASE)
/** Array initializer of fetchro4 peripheral base addresses */
#define fetchro4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO4_BASE }
/** Array initializer of fetchro4 peripheral base pointers */
#define fetchro4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO4 }

/* fetchro5 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHRO5 base address */
#define DISPLAY__SEERIS__FETCHRO5_BASE           (0x4B480100u)
/** Peripheral DISPLAY__SEERIS__FETCHRO5 base pointer */
#define DISPLAY__SEERIS__FETCHRO5                ((fetchro5_Type *)DISPLAY__SEERIS__FETCHRO5_BASE)
/** Array initializer of fetchro5 peripheral base addresses */
#define fetchro5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO5_BASE }
/** Array initializer of fetchro5 peripheral base pointers */
#define fetchro5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO5 }

/* fetchro6 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHRO6 base address */
#define DISPLAY__SEERIS__FETCHRO6_BASE           (0x4B480200u)
/** Peripheral DISPLAY__SEERIS__FETCHRO6 base pointer */
#define DISPLAY__SEERIS__FETCHRO6                ((fetchro6_Type *)DISPLAY__SEERIS__FETCHRO6_BASE)
/** Array initializer of fetchro6 peripheral base addresses */
#define fetchro6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO6_BASE }
/** Array initializer of fetchro6 peripheral base pointers */
#define fetchro6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO6 }

/* fetchro7 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHRO7 base address */
#define DISPLAY__SEERIS__FETCHRO7_BASE           (0x4B480400u)
/** Peripheral DISPLAY__SEERIS__FETCHRO7 base pointer */
#define DISPLAY__SEERIS__FETCHRO7                ((fetchro7_Type *)DISPLAY__SEERIS__FETCHRO7_BASE)
/** Array initializer of fetchro7 peripheral base addresses */
#define fetchro7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO7_BASE }
/** Array initializer of fetchro7 peripheral base pointers */
#define fetchro7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO7 }

/* fetchro8 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHRO8 base address */
#define DISPLAY__SEERIS__FETCHRO8_BASE           (0x4B480600u)
/** Peripheral DISPLAY__SEERIS__FETCHRO8 base pointer */
#define DISPLAY__SEERIS__FETCHRO8                ((fetchro8_Type *)DISPLAY__SEERIS__FETCHRO8_BASE)
/** Array initializer of fetchro8 peripheral base addresses */
#define fetchro8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO8_BASE }
/** Array initializer of fetchro8 peripheral base pointers */
#define fetchro8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO8 }

/* fetchro9 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHRO9 base address */
#define DISPLAY__SEERIS__FETCHRO9_BASE           (0x4B482000u)
/** Peripheral DISPLAY__SEERIS__FETCHRO9 base pointer */
#define DISPLAY__SEERIS__FETCHRO9                ((fetchro9_Type *)DISPLAY__SEERIS__FETCHRO9_BASE)
/** Array initializer of fetchro9 peripheral base addresses */
#define fetchro9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO9_BASE }
/** Array initializer of fetchro9 peripheral base pointers */
#define fetchro9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO9 }

/* fetchrot - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHROT base address */
#define DISPLAY__SEERIS__FETCHROT_BASE           (0x4B480000u)
/** Peripheral DISPLAY__SEERIS__FETCHROT base pointer */
#define DISPLAY__SEERIS__FETCHROT                ((fetchrot_Type *)DISPLAY__SEERIS__FETCHROT_BASE)
/** Array initializer of fetchrot peripheral base addresses */
#define fetchrot_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHROT_BASE }
/** Array initializer of fetchrot peripheral base pointers */
#define fetchrot_BASE_PTRS                       { DISPLAY__SEERIS__FETCHROT }

/* fetchy0c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHY0C base address */
#define DISPLAY__SEERIS__FETCHY0C_BASE           (0x4B5F1000u)
/** Peripheral DISPLAY__SEERIS__FETCHY0C base pointer */
#define DISPLAY__SEERIS__FETCHY0C                ((fetchy0c_Type *)DISPLAY__SEERIS__FETCHY0C_BASE)
/** Array initializer of fetchy0c peripheral base addresses */
#define fetchy0c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY0C_BASE }
/** Array initializer of fetchy0c peripheral base pointers */
#define fetchy0c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY0C }

/* fetchy10 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHY10 base address */
#define DISPLAY__SEERIS__FETCHY10_BASE           (0x4B610000u)
/** Peripheral DISPLAY__SEERIS__FETCHY10 base pointer */
#define DISPLAY__SEERIS__FETCHY10                ((fetchy10_Type *)DISPLAY__SEERIS__FETCHY10_BASE)
/** Array initializer of fetchy10 peripheral base addresses */
#define fetchy10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY10_BASE }
/** Array initializer of fetchy10 peripheral base pointers */
#define fetchy10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY10 }

/* fetchy11 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHY11 base address */
#define DISPLAY__SEERIS__FETCHY11_BASE           (0x4B610028u)
/** Peripheral DISPLAY__SEERIS__FETCHY11 base pointer */
#define DISPLAY__SEERIS__FETCHY11                ((fetchy11_Type *)DISPLAY__SEERIS__FETCHY11_BASE)
/** Array initializer of fetchy11 peripheral base addresses */
#define fetchy11_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY11_BASE }
/** Array initializer of fetchy11 peripheral base pointers */
#define fetchy11_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY11 }

/* fetchy12 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHY12 base address */
#define DISPLAY__SEERIS__FETCHY12_BASE           (0x4B610060u)
/** Peripheral DISPLAY__SEERIS__FETCHY12 base pointer */
#define DISPLAY__SEERIS__FETCHY12                ((fetchy12_Type *)DISPLAY__SEERIS__FETCHY12_BASE)
/** Array initializer of fetchy12 peripheral base addresses */
#define fetchy12_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY12_BASE }
/** Array initializer of fetchy12 peripheral base pointers */
#define fetchy12_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY12 }

/* fetchy13 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHY13 base address */
#define DISPLAY__SEERIS__FETCHY13_BASE           (0x4B610078u)
/** Peripheral DISPLAY__SEERIS__FETCHY13 base pointer */
#define DISPLAY__SEERIS__FETCHY13                ((fetchy13_Type *)DISPLAY__SEERIS__FETCHY13_BASE)
/** Array initializer of fetchy13 peripheral base addresses */
#define fetchy13_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY13_BASE }
/** Array initializer of fetchy13 peripheral base pointers */
#define fetchy13_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY13 }

/* fetchy14 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHY14 base address */
#define DISPLAY__SEERIS__FETCHY14_BASE           (0x4B610088u)
/** Peripheral DISPLAY__SEERIS__FETCHY14 base pointer */
#define DISPLAY__SEERIS__FETCHY14                ((fetchy14_Type *)DISPLAY__SEERIS__FETCHY14_BASE)
/** Array initializer of fetchy14 peripheral base addresses */
#define fetchy14_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY14_BASE }
/** Array initializer of fetchy14 peripheral base pointers */
#define fetchy14_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY14 }

/* fetchy1c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHY1C base address */
#define DISPLAY__SEERIS__FETCHY1C_BASE           (0x4B611000u)
/** Peripheral DISPLAY__SEERIS__FETCHY1C base pointer */
#define DISPLAY__SEERIS__FETCHY1C                ((fetchy1c_Type *)DISPLAY__SEERIS__FETCHY1C_BASE)
/** Array initializer of fetchy1c peripheral base addresses */
#define fetchy1c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY1C_BASE }
/** Array initializer of fetchy1c peripheral base pointers */
#define fetchy1c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY1C }

/* fetchy3c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHY3C base address */
#define DISPLAY__SEERIS__FETCHY3C_BASE           (0x4B5E1000u)
/** Peripheral DISPLAY__SEERIS__FETCHY3C base pointer */
#define DISPLAY__SEERIS__FETCHY3C                ((fetchy3c_Type *)DISPLAY__SEERIS__FETCHY3C_BASE)
/** Array initializer of fetchy3c peripheral base addresses */
#define fetchy3c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY3C_BASE }
/** Array initializer of fetchy3c peripheral base pointers */
#define fetchy3c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY3C }

/* fetchyu1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHYU1 base address */
#define DISPLAY__SEERIS__FETCHYU1_BASE           (0x4B5E0028u)
/** Peripheral DISPLAY__SEERIS__FETCHYU1 base pointer */
#define DISPLAY__SEERIS__FETCHYU1                ((fetchyu1_Type *)DISPLAY__SEERIS__FETCHYU1_BASE)
/** Array initializer of fetchyu1 peripheral base addresses */
#define fetchyu1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU1_BASE }
/** Array initializer of fetchyu1 peripheral base pointers */
#define fetchyu1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU1 }

/* fetchyu2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHYU2 base address */
#define DISPLAY__SEERIS__FETCHYU2_BASE           (0x4B5E0060u)
/** Peripheral DISPLAY__SEERIS__FETCHYU2 base pointer */
#define DISPLAY__SEERIS__FETCHYU2                ((fetchyu2_Type *)DISPLAY__SEERIS__FETCHYU2_BASE)
/** Array initializer of fetchyu2 peripheral base addresses */
#define fetchyu2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU2_BASE }
/** Array initializer of fetchyu2 peripheral base pointers */
#define fetchyu2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU2 }

/* fetchyu3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHYU3 base address */
#define DISPLAY__SEERIS__FETCHYU3_BASE           (0x4B5E0078u)
/** Peripheral DISPLAY__SEERIS__FETCHYU3 base pointer */
#define DISPLAY__SEERIS__FETCHYU3                ((fetchyu3_Type *)DISPLAY__SEERIS__FETCHYU3_BASE)
/** Array initializer of fetchyu3 peripheral base addresses */
#define fetchyu3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU3_BASE }
/** Array initializer of fetchyu3 peripheral base pointers */
#define fetchyu3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU3 }

/* fetchyu4 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHYU4 base address */
#define DISPLAY__SEERIS__FETCHYU4_BASE           (0x4B5E0088u)
/** Peripheral DISPLAY__SEERIS__FETCHYU4 base pointer */
#define DISPLAY__SEERIS__FETCHYU4                ((fetchyu4_Type *)DISPLAY__SEERIS__FETCHYU4_BASE)
/** Array initializer of fetchyu4 peripheral base addresses */
#define fetchyu4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU4_BASE }
/** Array initializer of fetchyu4 peripheral base pointers */
#define fetchyu4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU4 }

/* fetchyu5 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHYU5 base address */
#define DISPLAY__SEERIS__FETCHYU5_BASE           (0x4B5F0000u)
/** Peripheral DISPLAY__SEERIS__FETCHYU5 base pointer */
#define DISPLAY__SEERIS__FETCHYU5                ((fetchyu5_Type *)DISPLAY__SEERIS__FETCHYU5_BASE)
/** Array initializer of fetchyu5 peripheral base addresses */
#define fetchyu5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU5_BASE }
/** Array initializer of fetchyu5 peripheral base pointers */
#define fetchyu5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU5 }

/* fetchyu6 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHYU6 base address */
#define DISPLAY__SEERIS__FETCHYU6_BASE           (0x4B5F0028u)
/** Peripheral DISPLAY__SEERIS__FETCHYU6 base pointer */
#define DISPLAY__SEERIS__FETCHYU6                ((fetchyu6_Type *)DISPLAY__SEERIS__FETCHYU6_BASE)
/** Array initializer of fetchyu6 peripheral base addresses */
#define fetchyu6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU6_BASE }
/** Array initializer of fetchyu6 peripheral base pointers */
#define fetchyu6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU6 }

/* fetchyu7 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHYU7 base address */
#define DISPLAY__SEERIS__FETCHYU7_BASE           (0x4B5F0060u)
/** Peripheral DISPLAY__SEERIS__FETCHYU7 base pointer */
#define DISPLAY__SEERIS__FETCHYU7                ((fetchyu7_Type *)DISPLAY__SEERIS__FETCHYU7_BASE)
/** Array initializer of fetchyu7 peripheral base addresses */
#define fetchyu7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU7_BASE }
/** Array initializer of fetchyu7 peripheral base pointers */
#define fetchyu7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU7 }

/* fetchyu8 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHYU8 base address */
#define DISPLAY__SEERIS__FETCHYU8_BASE           (0x4B5F0078u)
/** Peripheral DISPLAY__SEERIS__FETCHYU8 base pointer */
#define DISPLAY__SEERIS__FETCHYU8                ((fetchyu8_Type *)DISPLAY__SEERIS__FETCHYU8_BASE)
/** Array initializer of fetchyu8 peripheral base addresses */
#define fetchyu8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU8_BASE }
/** Array initializer of fetchyu8 peripheral base pointers */
#define fetchyu8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU8 }

/* fetchyu9 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHYU9 base address */
#define DISPLAY__SEERIS__FETCHYU9_BASE           (0x4B5F0088u)
/** Peripheral DISPLAY__SEERIS__FETCHYU9 base pointer */
#define DISPLAY__SEERIS__FETCHYU9                ((fetchyu9_Type *)DISPLAY__SEERIS__FETCHYU9_BASE)
/** Array initializer of fetchyu9 peripheral base addresses */
#define fetchyu9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU9_BASE }
/** Array initializer of fetchyu9 peripheral base pointers */
#define fetchyu9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU9 }

/* fetchyuv - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FETCHYUV base address */
#define DISPLAY__SEERIS__FETCHYUV_BASE           (0x4B5E0000u)
/** Peripheral DISPLAY__SEERIS__FETCHYUV base pointer */
#define DISPLAY__SEERIS__FETCHYUV                ((fetchyuv_Type *)DISPLAY__SEERIS__FETCHYUV_BASE)
/** Array initializer of fetchyuv peripheral base addresses */
#define fetchyuv_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYUV_BASE }
/** Array initializer of fetchyuv peripheral base pointers */
#define fetchyuv_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYUV }

/* filter - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FILTER base address */
#define DISPLAY__SEERIS__FILTER_BASE             (0x4B4D0000u)
/** Peripheral DISPLAY__SEERIS__FILTER base pointer */
#define DISPLAY__SEERIS__FILTER                  ((filter_Type *)DISPLAY__SEERIS__FILTER_BASE)
/** Array initializer of filter peripheral base addresses */
#define filter_BASE_ADDRS                        { DISPLAY__SEERIS__FILTER_BASE }
/** Array initializer of filter peripheral base pointers */
#define filter_BASE_PTRS                         { DISPLAY__SEERIS__FILTER }

/* filter9c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FILTER9C base address */
#define DISPLAY__SEERIS__FILTER9C_BASE           (0x4B4D1000u)
/** Peripheral DISPLAY__SEERIS__FILTER9C base pointer */
#define DISPLAY__SEERIS__FILTER9C                ((filter9c_Type *)DISPLAY__SEERIS__FILTER9C_BASE)
/** Array initializer of filter9c peripheral base addresses */
#define filter9c_BASE_ADDRS                      { DISPLAY__SEERIS__FILTER9C_BASE }
/** Array initializer of filter9c peripheral base pointers */
#define filter9c_BASE_PTRS                       { DISPLAY__SEERIS__FILTER9C }

/* framege1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FRAMEGE1 base address */
#define DISPLAY__SEERIS__FRAMEGE1_BASE           (0x4B740000u)
/** Peripheral DISPLAY__SEERIS__FRAMEGE1 base pointer */
#define DISPLAY__SEERIS__FRAMEGE1                ((framege1_Type *)DISPLAY__SEERIS__FRAMEGE1_BASE)
/** Array initializer of framege1 peripheral base addresses */
#define framege1_BASE_ADDRS                      { DISPLAY__SEERIS__FRAMEGE1_BASE }
/** Array initializer of framege1 peripheral base pointers */
#define framege1_BASE_PTRS                       { DISPLAY__SEERIS__FRAMEGE1 }

/* framegen - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__FRAMEGEN base address */
#define DISPLAY__SEERIS__FRAMEGEN_BASE           (0x4B6B0000u)
/** Peripheral DISPLAY__SEERIS__FRAMEGEN base pointer */
#define DISPLAY__SEERIS__FRAMEGEN                ((framegen_Type *)DISPLAY__SEERIS__FRAMEGEN_BASE)
/** Array initializer of framegen peripheral base addresses */
#define framegen_BASE_ADDRS                      { DISPLAY__SEERIS__FRAMEGEN_BASE }
/** Array initializer of framegen peripheral base pointers */
#define framegen_BASE_PTRS                       { DISPLAY__SEERIS__FRAMEGEN }

/* gammaco1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__GAMMACO1 base address */
#define DISPLAY__SEERIS__GAMMACO1_BASE           (0x4B6E0800u)
/** Peripheral DISPLAY__SEERIS__GAMMACO1 base pointer */
#define DISPLAY__SEERIS__GAMMACO1                ((gammaco1_Type *)DISPLAY__SEERIS__GAMMACO1_BASE)
/** Array initializer of gammaco1 peripheral base addresses */
#define gammaco1_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACO1_BASE }
/** Array initializer of gammaco1 peripheral base pointers */
#define gammaco1_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACO1 }

/* gammaco2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__GAMMACO2 base address */
#define DISPLAY__SEERIS__GAMMACO2_BASE           (0x4B770000u)
/** Peripheral DISPLAY__SEERIS__GAMMACO2 base pointer */
#define DISPLAY__SEERIS__GAMMACO2                ((gammaco2_Type *)DISPLAY__SEERIS__GAMMACO2_BASE)
/** Array initializer of gammaco2 peripheral base addresses */
#define gammaco2_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACO2_BASE }
/** Array initializer of gammaco2 peripheral base pointers */
#define gammaco2_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACO2 }

/* gammaco3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__GAMMACO3 base address */
#define DISPLAY__SEERIS__GAMMACO3_BASE           (0x4B770800u)
/** Peripheral DISPLAY__SEERIS__GAMMACO3 base pointer */
#define DISPLAY__SEERIS__GAMMACO3                ((gammaco3_Type *)DISPLAY__SEERIS__GAMMACO3_BASE)
/** Array initializer of gammaco3 peripheral base addresses */
#define gammaco3_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACO3_BASE }
/** Array initializer of gammaco3 peripheral base pointers */
#define gammaco3_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACO3 }

/* gammacor - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__GAMMACOR base address */
#define DISPLAY__SEERIS__GAMMACOR_BASE           (0x4B6E0000u)
/** Peripheral DISPLAY__SEERIS__GAMMACOR base pointer */
#define DISPLAY__SEERIS__GAMMACOR                ((gammacor_Type *)DISPLAY__SEERIS__GAMMACOR_BASE)
/** Array initializer of gammacor peripheral base addresses */
#define gammacor_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACOR_BASE }
/** Array initializer of gammacor peripheral base pointers */
#define gammacor_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACOR }

/* generalp - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__GENERALP base address */
#define DISPLAY__SEERIS__GENERALP_BASE           (0x4B412000u)
/** Peripheral DISPLAY__SEERIS__GENERALP base pointer */
#define DISPLAY__SEERIS__GENERALP                ((generalp_Type *)DISPLAY__SEERIS__GENERALP_BASE)
/** Array initializer of generalp peripheral base addresses */
#define generalp_BASE_ADDRS                      { DISPLAY__SEERIS__GENERALP_BASE }
/** Array initializer of generalp peripheral base pointers */
#define generalp_BASE_PTRS                       { DISPLAY__SEERIS__GENERALP }

/* hscale4c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__HSCALE4C base address */
#define DISPLAY__SEERIS__HSCALE4C_BASE           (0x4B641000u)
/** Peripheral DISPLAY__SEERIS__HSCALE4C base pointer */
#define DISPLAY__SEERIS__HSCALE4C                ((hscale4c_Type *)DISPLAY__SEERIS__HSCALE4C_BASE)
/** Array initializer of hscale4c peripheral base addresses */
#define hscale4c_BASE_ADDRS                      { DISPLAY__SEERIS__HSCALE4C_BASE }
/** Array initializer of hscale4c peripheral base pointers */
#define hscale4c_BASE_PTRS                       { DISPLAY__SEERIS__HSCALE4C }

/* hscale9c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__HSCALE9C base address */
#define DISPLAY__SEERIS__HSCALE9C_BASE           (0x4B4B1000u)
/** Peripheral DISPLAY__SEERIS__HSCALE9C base pointer */
#define DISPLAY__SEERIS__HSCALE9C                ((hscale9c_Type *)DISPLAY__SEERIS__HSCALE9C_BASE)
/** Array initializer of hscale9c peripheral base addresses */
#define hscale9c_BASE_ADDRS                      { DISPLAY__SEERIS__HSCALE9C_BASE }
/** Array initializer of hscale9c peripheral base pointers */
#define hscale9c_BASE_PTRS                       { DISPLAY__SEERIS__HSCALE9C }

/* hscaler - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__HSCALER base address */
#define DISPLAY__SEERIS__HSCALER_BASE            (0x4B4B0000u)
/** Peripheral DISPLAY__SEERIS__HSCALER base pointer */
#define DISPLAY__SEERIS__HSCALER                 ((hscaler_Type *)DISPLAY__SEERIS__HSCALER_BASE)
/** Array initializer of hscaler peripheral base addresses */
#define hscaler_BASE_ADDRS                       { DISPLAY__SEERIS__HSCALER_BASE }
/** Array initializer of hscaler peripheral base pointers */
#define hscaler_BASE_PTRS                        { DISPLAY__SEERIS__HSCALER }

/* hscaler1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__HSCALER1 base address */
#define DISPLAY__SEERIS__HSCALER1_BASE           (0x4B640000u)
/** Peripheral DISPLAY__SEERIS__HSCALER1 base pointer */
#define DISPLAY__SEERIS__HSCALER1                ((hscaler1_Type *)DISPLAY__SEERIS__HSCALER1_BASE)
/** Array initializer of hscaler1 peripheral base addresses */
#define hscaler1_BASE_ADDRS                      { DISPLAY__SEERIS__HSCALER1_BASE }
/** Array initializer of hscaler1 peripheral base pointers */
#define hscaler1_BASE_PTRS                       { DISPLAY__SEERIS__HSCALER1 }

/* idhash - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IDHASH base address */
#define DISPLAY__SEERIS__IDHASH_BASE             (0x4B700000u)
/** Peripheral DISPLAY__SEERIS__IDHASH base pointer */
#define DISPLAY__SEERIS__IDHASH                  ((idhash_Type *)DISPLAY__SEERIS__IDHASH_BASE)
/** Array initializer of idhash peripheral base addresses */
#define idhash_BASE_ADDRS                        { DISPLAY__SEERIS__IDHASH_BASE }
/** Array initializer of idhash peripheral base pointers */
#define idhash_BASE_PTRS                         { DISPLAY__SEERIS__IDHASH }

/* idhash0c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IDHASH0C base address */
#define DISPLAY__SEERIS__IDHASH0C_BASE           (0x4B703000u)
/** Peripheral DISPLAY__SEERIS__IDHASH0C base pointer */
#define DISPLAY__SEERIS__IDHASH0C                ((idhash0c_Type *)DISPLAY__SEERIS__IDHASH0C_BASE)
/** Array initializer of idhash0c peripheral base addresses */
#define idhash0c_BASE_ADDRS                      { DISPLAY__SEERIS__IDHASH0C_BASE }
/** Array initializer of idhash0c peripheral base pointers */
#define idhash0c_BASE_PTRS                       { DISPLAY__SEERIS__IDHASH0C }

/* idhash1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IDHASH1 base address */
#define DISPLAY__SEERIS__IDHASH1_BASE            (0x4B701000u)
/** Peripheral DISPLAY__SEERIS__IDHASH1 base pointer */
#define DISPLAY__SEERIS__IDHASH1                 ((idhash1_Type *)DISPLAY__SEERIS__IDHASH1_BASE)
/** Array initializer of idhash1 peripheral base addresses */
#define idhash1_BASE_ADDRS                       { DISPLAY__SEERIS__IDHASH1_BASE }
/** Array initializer of idhash1 peripheral base pointers */
#define idhash1_BASE_PTRS                        { DISPLAY__SEERIS__IDHASH1 }

/* idhash1c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IDHASH1C base address */
#define DISPLAY__SEERIS__IDHASH1C_BASE           (0x4B793000u)
/** Peripheral DISPLAY__SEERIS__IDHASH1C base pointer */
#define DISPLAY__SEERIS__IDHASH1C                ((idhash1c_Type *)DISPLAY__SEERIS__IDHASH1C_BASE)
/** Array initializer of idhash1c peripheral base addresses */
#define idhash1c_BASE_ADDRS                      { DISPLAY__SEERIS__IDHASH1C_BASE }
/** Array initializer of idhash1c peripheral base pointers */
#define idhash1c_BASE_PTRS                       { DISPLAY__SEERIS__IDHASH1C }

/* idhash2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IDHASH2 base address */
#define DISPLAY__SEERIS__IDHASH2_BASE            (0x4B790000u)
/** Peripheral DISPLAY__SEERIS__IDHASH2 base pointer */
#define DISPLAY__SEERIS__IDHASH2                 ((idhash2_Type *)DISPLAY__SEERIS__IDHASH2_BASE)
/** Array initializer of idhash2 peripheral base addresses */
#define idhash2_BASE_ADDRS                       { DISPLAY__SEERIS__IDHASH2_BASE }
/** Array initializer of idhash2 peripheral base pointers */
#define idhash2_BASE_PTRS                        { DISPLAY__SEERIS__IDHASH2 }

/* idhash3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IDHASH3 base address */
#define DISPLAY__SEERIS__IDHASH3_BASE            (0x4B791000u)
/** Peripheral DISPLAY__SEERIS__IDHASH3 base pointer */
#define DISPLAY__SEERIS__IDHASH3                 ((idhash3_Type *)DISPLAY__SEERIS__IDHASH3_BASE)
/** Array initializer of idhash3 peripheral base addresses */
#define idhash3_BASE_ADDRS                       { DISPLAY__SEERIS__IDHASH3_BASE }
/** Array initializer of idhash3 peripheral base pointers */
#define idhash3_BASE_PTRS                        { DISPLAY__SEERIS__IDHASH3 }

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

/* irq - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IRQ base address */
#define DISPLAY__SEERIS__IRQ_BASE                (0x4B401000u)
/** Peripheral DISPLAY__SEERIS__IRQ base pointer */
#define DISPLAY__SEERIS__IRQ                     ((irq_Type *)DISPLAY__SEERIS__IRQ_BASE)
/** Array initializer of irq peripheral base addresses */
#define irq_BASE_ADDRS                           { DISPLAY__SEERIS__IRQ_BASE }
/** Array initializer of irq peripheral base pointers */
#define irq_BASE_PTRS                            { DISPLAY__SEERIS__IRQ }

/* irq1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IRQ1 base address */
#define DISPLAY__SEERIS__IRQ1_BASE               (0x4B431000u)
/** Peripheral DISPLAY__SEERIS__IRQ1 base pointer */
#define DISPLAY__SEERIS__IRQ1                    ((irq1_Type *)DISPLAY__SEERIS__IRQ1_BASE)
/** Array initializer of irq1 peripheral base addresses */
#define irq1_BASE_ADDRS                          { DISPLAY__SEERIS__IRQ1_BASE }
/** Array initializer of irq1 peripheral base pointers */
#define irq1_BASE_PTRS                           { DISPLAY__SEERIS__IRQ1 }

/* irq2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IRQ2 base address */
#define DISPLAY__SEERIS__IRQ2_BASE               (0x4B7C1000u)
/** Peripheral DISPLAY__SEERIS__IRQ2 base pointer */
#define DISPLAY__SEERIS__IRQ2                    ((irq2_Type *)DISPLAY__SEERIS__IRQ2_BASE)
/** Array initializer of irq2 peripheral base addresses */
#define irq2_BASE_ADDRS                          { DISPLAY__SEERIS__IRQ2_BASE }
/** Array initializer of irq2 peripheral base pointers */
#define irq2_BASE_PTRS                           { DISPLAY__SEERIS__IRQ2 }

/* irq3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IRQ3 base address */
#define DISPLAY__SEERIS__IRQ3_BASE               (0x4B7D1000u)
/** Peripheral DISPLAY__SEERIS__IRQ3 base pointer */
#define DISPLAY__SEERIS__IRQ3                    ((irq3_Type *)DISPLAY__SEERIS__IRQ3_BASE)
/** Array initializer of irq3 peripheral base addresses */
#define irq3_BASE_ADDRS                          { DISPLAY__SEERIS__IRQ3_BASE }
/** Array initializer of irq3 peripheral base pointers */
#define irq3_BASE_PTRS                           { DISPLAY__SEERIS__IRQ3 }

/* irq4 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IRQ4 base address */
#define DISPLAY__SEERIS__IRQ4_BASE               (0x4B7E1000u)
/** Peripheral DISPLAY__SEERIS__IRQ4 base pointer */
#define DISPLAY__SEERIS__IRQ4                    ((irq4_Type *)DISPLAY__SEERIS__IRQ4_BASE)
/** Array initializer of irq4 peripheral base addresses */
#define irq4_BASE_ADDRS                          { DISPLAY__SEERIS__IRQ4_BASE }
/** Array initializer of irq4 peripheral base pointers */
#define irq4_BASE_PTRS                           { DISPLAY__SEERIS__IRQ4 }

/* irq5 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__IRQ5 base address */
#define DISPLAY__SEERIS__IRQ5_BASE               (0x4B7F1000u)
/** Peripheral DISPLAY__SEERIS__IRQ5 base pointer */
#define DISPLAY__SEERIS__IRQ5                    ((irq5_Type *)DISPLAY__SEERIS__IRQ5_BASE)
/** Array initializer of irq5 peripheral base addresses */
#define irq5_BASE_ADDRS                          { DISPLAY__SEERIS__IRQ5_BASE }
/** Array initializer of irq5 peripheral base pointers */
#define irq5_BASE_PTRS                           { DISPLAY__SEERIS__IRQ5 }

/* layerb1c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LAYERB1C base address */
#define DISPLAY__SEERIS__LAYERB1C_BASE           (0x4B571000u)
/** Peripheral DISPLAY__SEERIS__LAYERB1C base pointer */
#define DISPLAY__SEERIS__LAYERB1C                ((layerb1c_Type *)DISPLAY__SEERIS__LAYERB1C_BASE)
/** Array initializer of layerb1c peripheral base addresses */
#define layerb1c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB1C_BASE }
/** Array initializer of layerb1c peripheral base pointers */
#define layerb1c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB1C }

/* layerb2c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LAYERB2C base address */
#define DISPLAY__SEERIS__LAYERB2C_BASE           (0x4B581000u)
/** Peripheral DISPLAY__SEERIS__LAYERB2C base pointer */
#define DISPLAY__SEERIS__LAYERB2C                ((layerb2c_Type *)DISPLAY__SEERIS__LAYERB2C_BASE)
/** Array initializer of layerb2c peripheral base addresses */
#define layerb2c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB2C_BASE }
/** Array initializer of layerb2c peripheral base pointers */
#define layerb2c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB2C }

/* layerb3c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LAYERB3C base address */
#define DISPLAY__SEERIS__LAYERB3C_BASE           (0x4B591000u)
/** Peripheral DISPLAY__SEERIS__LAYERB3C base pointer */
#define DISPLAY__SEERIS__LAYERB3C                ((layerb3c_Type *)DISPLAY__SEERIS__LAYERB3C_BASE)
/** Array initializer of layerb3c peripheral base addresses */
#define layerb3c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB3C_BASE }
/** Array initializer of layerb3c peripheral base pointers */
#define layerb3c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB3C }

/* layerb4c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LAYERB4C base address */
#define DISPLAY__SEERIS__LAYERB4C_BASE           (0x4B5A1000u)
/** Peripheral DISPLAY__SEERIS__LAYERB4C base pointer */
#define DISPLAY__SEERIS__LAYERB4C                ((layerb4c_Type *)DISPLAY__SEERIS__LAYERB4C_BASE)
/** Array initializer of layerb4c peripheral base addresses */
#define layerb4c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB4C_BASE }
/** Array initializer of layerb4c peripheral base pointers */
#define layerb4c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB4C }

/* layerb5c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LAYERB5C base address */
#define DISPLAY__SEERIS__LAYERB5C_BASE           (0x4B5B1000u)
/** Peripheral DISPLAY__SEERIS__LAYERB5C base pointer */
#define DISPLAY__SEERIS__LAYERB5C                ((layerb5c_Type *)DISPLAY__SEERIS__LAYERB5C_BASE)
/** Array initializer of layerb5c peripheral base addresses */
#define layerb5c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB5C_BASE }
/** Array initializer of layerb5c peripheral base pointers */
#define layerb5c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB5C }

/* layerbl1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LAYERBL1 base address */
#define DISPLAY__SEERIS__LAYERBL1_BASE           (0x4B580000u)
/** Peripheral DISPLAY__SEERIS__LAYERBL1 base pointer */
#define DISPLAY__SEERIS__LAYERBL1                ((layerbl1_Type *)DISPLAY__SEERIS__LAYERBL1_BASE)
/** Array initializer of layerbl1 peripheral base addresses */
#define layerbl1_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERBL1_BASE }
/** Array initializer of layerbl1 peripheral base pointers */
#define layerbl1_BASE_PTRS                       { DISPLAY__SEERIS__LAYERBL1 }

/* layerbl2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LAYERBL2 base address */
#define DISPLAY__SEERIS__LAYERBL2_BASE           (0x4B590000u)
/** Peripheral DISPLAY__SEERIS__LAYERBL2 base pointer */
#define DISPLAY__SEERIS__LAYERBL2                ((layerbl2_Type *)DISPLAY__SEERIS__LAYERBL2_BASE)
/** Array initializer of layerbl2 peripheral base addresses */
#define layerbl2_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERBL2_BASE }
/** Array initializer of layerbl2 peripheral base pointers */
#define layerbl2_BASE_PTRS                       { DISPLAY__SEERIS__LAYERBL2 }

/* layerbl3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LAYERBL3 base address */
#define DISPLAY__SEERIS__LAYERBL3_BASE           (0x4B5A0000u)
/** Peripheral DISPLAY__SEERIS__LAYERBL3 base pointer */
#define DISPLAY__SEERIS__LAYERBL3                ((layerbl3_Type *)DISPLAY__SEERIS__LAYERBL3_BASE)
/** Array initializer of layerbl3 peripheral base addresses */
#define layerbl3_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERBL3_BASE }
/** Array initializer of layerbl3 peripheral base pointers */
#define layerbl3_BASE_PTRS                       { DISPLAY__SEERIS__LAYERBL3 }

/* layerbl4 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LAYERBL4 base address */
#define DISPLAY__SEERIS__LAYERBL4_BASE           (0x4B5B0000u)
/** Peripheral DISPLAY__SEERIS__LAYERBL4 base pointer */
#define DISPLAY__SEERIS__LAYERBL4                ((layerbl4_Type *)DISPLAY__SEERIS__LAYERBL4_BASE)
/** Array initializer of layerbl4 peripheral base addresses */
#define layerbl4_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERBL4_BASE }
/** Array initializer of layerbl4 peripheral base pointers */
#define layerbl4_BASE_PTRS                       { DISPLAY__SEERIS__LAYERBL4 }

/* layerble - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LAYERBLE base address */
#define DISPLAY__SEERIS__LAYERBLE_BASE           (0x4B570000u)
/** Peripheral DISPLAY__SEERIS__LAYERBLE base pointer */
#define DISPLAY__SEERIS__LAYERBLE                ((layerble_Type *)DISPLAY__SEERIS__LAYERBLE_BASE)
/** Array initializer of layerble peripheral base addresses */
#define layerble_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERBLE_BASE }
/** Array initializer of layerble peripheral base pointers */
#define layerble_BASE_PTRS                       { DISPLAY__SEERIS__LAYERBLE }

/* locald10 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD10 base address */
#define DISPLAY__SEERIS__LOCALD10_BASE           (0x4B721084u)
/** Peripheral DISPLAY__SEERIS__LOCALD10 base pointer */
#define DISPLAY__SEERIS__LOCALD10                ((locald10_Type *)DISPLAY__SEERIS__LOCALD10_BASE)
/** Array initializer of locald10 peripheral base addresses */
#define locald10_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD10_BASE }
/** Array initializer of locald10 peripheral base pointers */
#define locald10_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD10 }

/* locald11 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD11 base address */
#define DISPLAY__SEERIS__LOCALD11_BASE           (0x4B721218u)
/** Peripheral DISPLAY__SEERIS__LOCALD11 base pointer */
#define DISPLAY__SEERIS__LOCALD11                ((locald11_Type *)DISPLAY__SEERIS__LOCALD11_BASE)
/** Array initializer of locald11 peripheral base addresses */
#define locald11_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD11_BASE }
/** Array initializer of locald11 peripheral base pointers */
#define locald11_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD11 }

/* locald12 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD12 base address */
#define DISPLAY__SEERIS__LOCALD12_BASE           (0x4B721220u)
/** Peripheral DISPLAY__SEERIS__LOCALD12 base pointer */
#define DISPLAY__SEERIS__LOCALD12                ((locald12_Type *)DISPLAY__SEERIS__LOCALD12_BASE)
/** Array initializer of locald12 peripheral base addresses */
#define locald12_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD12_BASE }
/** Array initializer of locald12 peripheral base pointers */
#define locald12_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD12 }

/* locald13 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD13 base address */
#define DISPLAY__SEERIS__LOCALD13_BASE           (0x4B721250u)
/** Peripheral DISPLAY__SEERIS__LOCALD13 base pointer */
#define DISPLAY__SEERIS__LOCALD13                ((locald13_Type *)DISPLAY__SEERIS__LOCALD13_BASE)
/** Array initializer of locald13 peripheral base addresses */
#define locald13_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD13_BASE }
/** Array initializer of locald13 peripheral base pointers */
#define locald13_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD13 }

/* locald14 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD14 base address */
#define DISPLAY__SEERIS__LOCALD14_BASE           (0x4B721298u)
/** Peripheral DISPLAY__SEERIS__LOCALD14 base pointer */
#define DISPLAY__SEERIS__LOCALD14                ((locald14_Type *)DISPLAY__SEERIS__LOCALD14_BASE)
/** Array initializer of locald14 peripheral base addresses */
#define locald14_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD14_BASE }
/** Array initializer of locald14 peripheral base pointers */
#define locald14_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD14 }

/* locald15 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD15 base address */
#define DISPLAY__SEERIS__LOCALD15_BASE           (0x4B721300u)
/** Peripheral DISPLAY__SEERIS__LOCALD15 base pointer */
#define DISPLAY__SEERIS__LOCALD15                ((locald15_Type *)DISPLAY__SEERIS__LOCALD15_BASE)
/** Array initializer of locald15 peripheral base addresses */
#define locald15_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD15_BASE }
/** Array initializer of locald15 peripheral base pointers */
#define locald15_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD15 }

/* locald16 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD16 base address */
#define DISPLAY__SEERIS__LOCALD16_BASE           (0x4B7213A0u)
/** Peripheral DISPLAY__SEERIS__LOCALD16 base pointer */
#define DISPLAY__SEERIS__LOCALD16                ((locald16_Type *)DISPLAY__SEERIS__LOCALD16_BASE)
/** Array initializer of locald16 peripheral base addresses */
#define locald16_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD16_BASE }
/** Array initializer of locald16 peripheral base pointers */
#define locald16_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD16 }

/* locald17 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD17 base address */
#define DISPLAY__SEERIS__LOCALD17_BASE           (0x4B721400u)
/** Peripheral DISPLAY__SEERIS__LOCALD17 base pointer */
#define DISPLAY__SEERIS__LOCALD17                ((locald17_Type *)DISPLAY__SEERIS__LOCALD17_BASE)
/** Array initializer of locald17 peripheral base addresses */
#define locald17_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD17_BASE }
/** Array initializer of locald17 peripheral base pointers */
#define locald17_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD17 }

/* locald18 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD18 base address */
#define DISPLAY__SEERIS__LOCALD18_BASE           (0x4B721414u)
/** Peripheral DISPLAY__SEERIS__LOCALD18 base pointer */
#define DISPLAY__SEERIS__LOCALD18                ((locald18_Type *)DISPLAY__SEERIS__LOCALD18_BASE)
/** Array initializer of locald18 peripheral base addresses */
#define locald18_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD18_BASE }
/** Array initializer of locald18 peripheral base pointers */
#define locald18_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD18 }

/* locald19 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD19 base address */
#define DISPLAY__SEERIS__LOCALD19_BASE           (0x4B721420u)
/** Peripheral DISPLAY__SEERIS__LOCALD19 base pointer */
#define DISPLAY__SEERIS__LOCALD19                ((locald19_Type *)DISPLAY__SEERIS__LOCALD19_BASE)
/** Array initializer of locald19 peripheral base addresses */
#define locald19_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD19_BASE }
/** Array initializer of locald19 peripheral base pointers */
#define locald19_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD19 }

/* locald20 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD20 base address */
#define DISPLAY__SEERIS__LOCALD20_BASE           (0x4B721440u)
/** Peripheral DISPLAY__SEERIS__LOCALD20 base pointer */
#define DISPLAY__SEERIS__LOCALD20                ((locald20_Type *)DISPLAY__SEERIS__LOCALD20_BASE)
/** Array initializer of locald20 peripheral base addresses */
#define locald20_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD20_BASE }
/** Array initializer of locald20 peripheral base pointers */
#define locald20_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD20 }

/* locald21 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD21 base address */
#define DISPLAY__SEERIS__LOCALD21_BASE           (0x4B721644u)
/** Peripheral DISPLAY__SEERIS__LOCALD21 base pointer */
#define DISPLAY__SEERIS__LOCALD21                ((locald21_Type *)DISPLAY__SEERIS__LOCALD21_BASE)
/** Array initializer of locald21 peripheral base addresses */
#define locald21_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD21_BASE }
/** Array initializer of locald21 peripheral base pointers */
#define locald21_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD21 }

/* locald22 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD22 base address */
#define DISPLAY__SEERIS__LOCALD22_BASE           (0x4B721680u)
/** Peripheral DISPLAY__SEERIS__LOCALD22 base pointer */
#define DISPLAY__SEERIS__LOCALD22                ((locald22_Type *)DISPLAY__SEERIS__LOCALD22_BASE)
/** Array initializer of locald22 peripheral base addresses */
#define locald22_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD22_BASE }
/** Array initializer of locald22 peripheral base pointers */
#define locald22_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD22 }

/* locald23 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD23 base address */
#define DISPLAY__SEERIS__LOCALD23_BASE           (0x4B721770u)
/** Peripheral DISPLAY__SEERIS__LOCALD23 base pointer */
#define DISPLAY__SEERIS__LOCALD23                ((locald23_Type *)DISPLAY__SEERIS__LOCALD23_BASE)
/** Array initializer of locald23 peripheral base addresses */
#define locald23_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD23_BASE }
/** Array initializer of locald23 peripheral base pointers */
#define locald23_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD23 }

/* locald24 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD24 base address */
#define DISPLAY__SEERIS__LOCALD24_BASE           (0x4B721784u)
/** Peripheral DISPLAY__SEERIS__LOCALD24 base pointer */
#define DISPLAY__SEERIS__LOCALD24                ((locald24_Type *)DISPLAY__SEERIS__LOCALD24_BASE)
/** Array initializer of locald24 peripheral base addresses */
#define locald24_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD24_BASE }
/** Array initializer of locald24 peripheral base pointers */
#define locald24_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD24 }

/* locald25 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD25 base address */
#define DISPLAY__SEERIS__LOCALD25_BASE           (0x4B721A00u)
/** Peripheral DISPLAY__SEERIS__LOCALD25 base pointer */
#define DISPLAY__SEERIS__LOCALD25                ((locald25_Type *)DISPLAY__SEERIS__LOCALD25_BASE)
/** Array initializer of locald25 peripheral base addresses */
#define locald25_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD25_BASE }
/** Array initializer of locald25 peripheral base pointers */
#define locald25_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD25 }

/* locald26 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD26 base address */
#define DISPLAY__SEERIS__LOCALD26_BASE           (0x4B722000u)
/** Peripheral DISPLAY__SEERIS__LOCALD26 base pointer */
#define DISPLAY__SEERIS__LOCALD26                ((locald26_Type *)DISPLAY__SEERIS__LOCALD26_BASE)
/** Array initializer of locald26 peripheral base addresses */
#define locald26_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD26_BASE }
/** Array initializer of locald26 peripheral base pointers */
#define locald26_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD26 }

/* locald27 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD27 base address */
#define DISPLAY__SEERIS__LOCALD27_BASE           (0x4B723000u)
/** Peripheral DISPLAY__SEERIS__LOCALD27 base pointer */
#define DISPLAY__SEERIS__LOCALD27                ((locald27_Type *)DISPLAY__SEERIS__LOCALD27_BASE)
/** Array initializer of locald27 peripheral base addresses */
#define locald27_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD27_BASE }
/** Array initializer of locald27 peripheral base pointers */
#define locald27_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD27 }

/* locald28 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD28 base address */
#define DISPLAY__SEERIS__LOCALD28_BASE           (0x4B723080u)
/** Peripheral DISPLAY__SEERIS__LOCALD28 base pointer */
#define DISPLAY__SEERIS__LOCALD28                ((locald28_Type *)DISPLAY__SEERIS__LOCALD28_BASE)
/** Array initializer of locald28 peripheral base addresses */
#define locald28_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD28_BASE }
/** Array initializer of locald28 peripheral base pointers */
#define locald28_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD28 }

/* locald29 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD29 base address */
#define DISPLAY__SEERIS__LOCALD29_BASE           (0x4B723100u)
/** Peripheral DISPLAY__SEERIS__LOCALD29 base pointer */
#define DISPLAY__SEERIS__LOCALD29                ((locald29_Type *)DISPLAY__SEERIS__LOCALD29_BASE)
/** Array initializer of locald29 peripheral base addresses */
#define locald29_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD29_BASE }
/** Array initializer of locald29 peripheral base pointers */
#define locald29_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD29 }

/* locald30 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD30 base address */
#define DISPLAY__SEERIS__LOCALD30_BASE           (0x4B723180u)
/** Peripheral DISPLAY__SEERIS__LOCALD30 base pointer */
#define DISPLAY__SEERIS__LOCALD30                ((locald30_Type *)DISPLAY__SEERIS__LOCALD30_BASE)
/** Array initializer of locald30 peripheral base addresses */
#define locald30_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD30_BASE }
/** Array initializer of locald30 peripheral base pointers */
#define locald30_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD30 }

/* locald31 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD31 base address */
#define DISPLAY__SEERIS__LOCALD31_BASE           (0x4B723200u)
/** Peripheral DISPLAY__SEERIS__LOCALD31 base pointer */
#define DISPLAY__SEERIS__LOCALD31                ((locald31_Type *)DISPLAY__SEERIS__LOCALD31_BASE)
/** Array initializer of locald31 peripheral base addresses */
#define locald31_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD31_BASE }
/** Array initializer of locald31 peripheral base pointers */
#define locald31_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD31 }

/* locald32 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD32 base address */
#define DISPLAY__SEERIS__LOCALD32_BASE           (0x4B723280u)
/** Peripheral DISPLAY__SEERIS__LOCALD32 base pointer */
#define DISPLAY__SEERIS__LOCALD32                ((locald32_Type *)DISPLAY__SEERIS__LOCALD32_BASE)
/** Array initializer of locald32 peripheral base addresses */
#define locald32_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD32_BASE }
/** Array initializer of locald32 peripheral base pointers */
#define locald32_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD32 }

/* locald33 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD33 base address */
#define DISPLAY__SEERIS__LOCALD33_BASE           (0x4B723300u)
/** Peripheral DISPLAY__SEERIS__LOCALD33 base pointer */
#define DISPLAY__SEERIS__LOCALD33                ((locald33_Type *)DISPLAY__SEERIS__LOCALD33_BASE)
/** Array initializer of locald33 peripheral base addresses */
#define locald33_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD33_BASE }
/** Array initializer of locald33 peripheral base pointers */
#define locald33_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD33 }

/* locald34 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD34 base address */
#define DISPLAY__SEERIS__LOCALD34_BASE           (0x4B723380u)
/** Peripheral DISPLAY__SEERIS__LOCALD34 base pointer */
#define DISPLAY__SEERIS__LOCALD34                ((locald34_Type *)DISPLAY__SEERIS__LOCALD34_BASE)
/** Array initializer of locald34 peripheral base addresses */
#define locald34_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD34_BASE }
/** Array initializer of locald34 peripheral base pointers */
#define locald34_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD34 }

/* locald35 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD35 base address */
#define DISPLAY__SEERIS__LOCALD35_BASE           (0x4B723400u)
/** Peripheral DISPLAY__SEERIS__LOCALD35 base pointer */
#define DISPLAY__SEERIS__LOCALD35                ((locald35_Type *)DISPLAY__SEERIS__LOCALD35_BASE)
/** Array initializer of locald35 peripheral base addresses */
#define locald35_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD35_BASE }
/** Array initializer of locald35 peripheral base pointers */
#define locald35_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD35 }

/* locald36 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD36 base address */
#define DISPLAY__SEERIS__LOCALD36_BASE           (0x4B723480u)
/** Peripheral DISPLAY__SEERIS__LOCALD36 base pointer */
#define DISPLAY__SEERIS__LOCALD36                ((locald36_Type *)DISPLAY__SEERIS__LOCALD36_BASE)
/** Array initializer of locald36 peripheral base addresses */
#define locald36_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD36_BASE }
/** Array initializer of locald36 peripheral base pointers */
#define locald36_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD36 }

/* locald37 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD37 base address */
#define DISPLAY__SEERIS__LOCALD37_BASE           (0x4B723500u)
/** Peripheral DISPLAY__SEERIS__LOCALD37 base pointer */
#define DISPLAY__SEERIS__LOCALD37                ((locald37_Type *)DISPLAY__SEERIS__LOCALD37_BASE)
/** Array initializer of locald37 peripheral base addresses */
#define locald37_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD37_BASE }
/** Array initializer of locald37 peripheral base pointers */
#define locald37_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD37 }

/* locald38 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD38 base address */
#define DISPLAY__SEERIS__LOCALD38_BASE           (0x4B723580u)
/** Peripheral DISPLAY__SEERIS__LOCALD38 base pointer */
#define DISPLAY__SEERIS__LOCALD38                ((locald38_Type *)DISPLAY__SEERIS__LOCALD38_BASE)
/** Array initializer of locald38 peripheral base addresses */
#define locald38_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD38_BASE }
/** Array initializer of locald38 peripheral base pointers */
#define locald38_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD38 }

/* locald39 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD39 base address */
#define DISPLAY__SEERIS__LOCALD39_BASE           (0x4B723600u)
/** Peripheral DISPLAY__SEERIS__LOCALD39 base pointer */
#define DISPLAY__SEERIS__LOCALD39                ((locald39_Type *)DISPLAY__SEERIS__LOCALD39_BASE)
/** Array initializer of locald39 peripheral base addresses */
#define locald39_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD39_BASE }
/** Array initializer of locald39 peripheral base pointers */
#define locald39_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD39 }

/* locald40 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD40 base address */
#define DISPLAY__SEERIS__LOCALD40_BASE           (0x4B723680u)
/** Peripheral DISPLAY__SEERIS__LOCALD40 base pointer */
#define DISPLAY__SEERIS__LOCALD40                ((locald40_Type *)DISPLAY__SEERIS__LOCALD40_BASE)
/** Array initializer of locald40 peripheral base addresses */
#define locald40_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD40_BASE }
/** Array initializer of locald40 peripheral base pointers */
#define locald40_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD40 }

/* locald41 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD41 base address */
#define DISPLAY__SEERIS__LOCALD41_BASE           (0x4B723700u)
/** Peripheral DISPLAY__SEERIS__LOCALD41 base pointer */
#define DISPLAY__SEERIS__LOCALD41                ((locald41_Type *)DISPLAY__SEERIS__LOCALD41_BASE)
/** Array initializer of locald41 peripheral base addresses */
#define locald41_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD41_BASE }
/** Array initializer of locald41 peripheral base pointers */
#define locald41_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD41 }

/* locald42 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD42 base address */
#define DISPLAY__SEERIS__LOCALD42_BASE           (0x4B723780u)
/** Peripheral DISPLAY__SEERIS__LOCALD42 base pointer */
#define DISPLAY__SEERIS__LOCALD42                ((locald42_Type *)DISPLAY__SEERIS__LOCALD42_BASE)
/** Array initializer of locald42 peripheral base addresses */
#define locald42_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD42_BASE }
/** Array initializer of locald42 peripheral base pointers */
#define locald42_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD42 }

/* locald43 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD43 base address */
#define DISPLAY__SEERIS__LOCALD43_BASE           (0x4B723800u)
/** Peripheral DISPLAY__SEERIS__LOCALD43 base pointer */
#define DISPLAY__SEERIS__LOCALD43                ((locald43_Type *)DISPLAY__SEERIS__LOCALD43_BASE)
/** Array initializer of locald43 peripheral base addresses */
#define locald43_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD43_BASE }
/** Array initializer of locald43 peripheral base pointers */
#define locald43_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD43 }

/* locald44 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD44 base address */
#define DISPLAY__SEERIS__LOCALD44_BASE           (0x4B723880u)
/** Peripheral DISPLAY__SEERIS__LOCALD44 base pointer */
#define DISPLAY__SEERIS__LOCALD44                ((locald44_Type *)DISPLAY__SEERIS__LOCALD44_BASE)
/** Array initializer of locald44 peripheral base addresses */
#define locald44_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD44_BASE }
/** Array initializer of locald44 peripheral base pointers */
#define locald44_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD44 }

/* locald45 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD45 base address */
#define DISPLAY__SEERIS__LOCALD45_BASE           (0x4B723900u)
/** Peripheral DISPLAY__SEERIS__LOCALD45 base pointer */
#define DISPLAY__SEERIS__LOCALD45                ((locald45_Type *)DISPLAY__SEERIS__LOCALD45_BASE)
/** Array initializer of locald45 peripheral base addresses */
#define locald45_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD45_BASE }
/** Array initializer of locald45 peripheral base pointers */
#define locald45_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD45 }

/* locald46 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD46 base address */
#define DISPLAY__SEERIS__LOCALD46_BASE           (0x4B723980u)
/** Peripheral DISPLAY__SEERIS__LOCALD46 base pointer */
#define DISPLAY__SEERIS__LOCALD46                ((locald46_Type *)DISPLAY__SEERIS__LOCALD46_BASE)
/** Array initializer of locald46 peripheral base addresses */
#define locald46_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD46_BASE }
/** Array initializer of locald46 peripheral base pointers */
#define locald46_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD46 }

/* locald47 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD47 base address */
#define DISPLAY__SEERIS__LOCALD47_BASE           (0x4B723A00u)
/** Peripheral DISPLAY__SEERIS__LOCALD47 base pointer */
#define DISPLAY__SEERIS__LOCALD47                ((locald47_Type *)DISPLAY__SEERIS__LOCALD47_BASE)
/** Array initializer of locald47 peripheral base addresses */
#define locald47_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD47_BASE }
/** Array initializer of locald47 peripheral base pointers */
#define locald47_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD47 }

/* locald48 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD48 base address */
#define DISPLAY__SEERIS__LOCALD48_BASE           (0x4B723A80u)
/** Peripheral DISPLAY__SEERIS__LOCALD48 base pointer */
#define DISPLAY__SEERIS__LOCALD48                ((locald48_Type *)DISPLAY__SEERIS__LOCALD48_BASE)
/** Array initializer of locald48 peripheral base addresses */
#define locald48_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD48_BASE }
/** Array initializer of locald48 peripheral base pointers */
#define locald48_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD48 }

/* locald49 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD49 base address */
#define DISPLAY__SEERIS__LOCALD49_BASE           (0x4B723B00u)
/** Peripheral DISPLAY__SEERIS__LOCALD49 base pointer */
#define DISPLAY__SEERIS__LOCALD49                ((locald49_Type *)DISPLAY__SEERIS__LOCALD49_BASE)
/** Array initializer of locald49 peripheral base addresses */
#define locald49_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD49_BASE }
/** Array initializer of locald49 peripheral base pointers */
#define locald49_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD49 }

/* locald50 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD50 base address */
#define DISPLAY__SEERIS__LOCALD50_BASE           (0x4B723B80u)
/** Peripheral DISPLAY__SEERIS__LOCALD50 base pointer */
#define DISPLAY__SEERIS__LOCALD50                ((locald50_Type *)DISPLAY__SEERIS__LOCALD50_BASE)
/** Array initializer of locald50 peripheral base addresses */
#define locald50_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD50_BASE }
/** Array initializer of locald50 peripheral base pointers */
#define locald50_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD50 }

/* locald51 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD51 base address */
#define DISPLAY__SEERIS__LOCALD51_BASE           (0x4B723C00u)
/** Peripheral DISPLAY__SEERIS__LOCALD51 base pointer */
#define DISPLAY__SEERIS__LOCALD51                ((locald51_Type *)DISPLAY__SEERIS__LOCALD51_BASE)
/** Array initializer of locald51 peripheral base addresses */
#define locald51_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD51_BASE }
/** Array initializer of locald51 peripheral base pointers */
#define locald51_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD51 }

/* locald52 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD52 base address */
#define DISPLAY__SEERIS__LOCALD52_BASE           (0x4B723C80u)
/** Peripheral DISPLAY__SEERIS__LOCALD52 base pointer */
#define DISPLAY__SEERIS__LOCALD52                ((locald52_Type *)DISPLAY__SEERIS__LOCALD52_BASE)
/** Array initializer of locald52 peripheral base addresses */
#define locald52_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD52_BASE }
/** Array initializer of locald52 peripheral base pointers */
#define locald52_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD52 }

/* locald53 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD53 base address */
#define DISPLAY__SEERIS__LOCALD53_BASE           (0x4B723D00u)
/** Peripheral DISPLAY__SEERIS__LOCALD53 base pointer */
#define DISPLAY__SEERIS__LOCALD53                ((locald53_Type *)DISPLAY__SEERIS__LOCALD53_BASE)
/** Array initializer of locald53 peripheral base addresses */
#define locald53_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD53_BASE }
/** Array initializer of locald53 peripheral base pointers */
#define locald53_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD53 }

/* locald54 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD54 base address */
#define DISPLAY__SEERIS__LOCALD54_BASE           (0x4B723D80u)
/** Peripheral DISPLAY__SEERIS__LOCALD54 base pointer */
#define DISPLAY__SEERIS__LOCALD54                ((locald54_Type *)DISPLAY__SEERIS__LOCALD54_BASE)
/** Array initializer of locald54 peripheral base addresses */
#define locald54_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD54_BASE }
/** Array initializer of locald54 peripheral base pointers */
#define locald54_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD54 }

/* locald55 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD55 base address */
#define DISPLAY__SEERIS__LOCALD55_BASE           (0x4B723E00u)
/** Peripheral DISPLAY__SEERIS__LOCALD55 base pointer */
#define DISPLAY__SEERIS__LOCALD55                ((locald55_Type *)DISPLAY__SEERIS__LOCALD55_BASE)
/** Array initializer of locald55 peripheral base addresses */
#define locald55_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD55_BASE }
/** Array initializer of locald55 peripheral base pointers */
#define locald55_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD55 }

/* locald56 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD56 base address */
#define DISPLAY__SEERIS__LOCALD56_BASE           (0x4B723E80u)
/** Peripheral DISPLAY__SEERIS__LOCALD56 base pointer */
#define DISPLAY__SEERIS__LOCALD56                ((locald56_Type *)DISPLAY__SEERIS__LOCALD56_BASE)
/** Array initializer of locald56 peripheral base addresses */
#define locald56_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD56_BASE }
/** Array initializer of locald56 peripheral base pointers */
#define locald56_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD56 }

/* locald57 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD57 base address */
#define DISPLAY__SEERIS__LOCALD57_BASE           (0x4B723F00u)
/** Peripheral DISPLAY__SEERIS__LOCALD57 base pointer */
#define DISPLAY__SEERIS__LOCALD57                ((locald57_Type *)DISPLAY__SEERIS__LOCALD57_BASE)
/** Array initializer of locald57 peripheral base addresses */
#define locald57_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD57_BASE }
/** Array initializer of locald57 peripheral base pointers */
#define locald57_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD57 }

/* locald58 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD58 base address */
#define DISPLAY__SEERIS__LOCALD58_BASE           (0x4B723F80u)
/** Peripheral DISPLAY__SEERIS__LOCALD58 base pointer */
#define DISPLAY__SEERIS__LOCALD58                ((locald58_Type *)DISPLAY__SEERIS__LOCALD58_BASE)
/** Array initializer of locald58 peripheral base addresses */
#define locald58_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD58_BASE }
/** Array initializer of locald58 peripheral base pointers */
#define locald58_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD58 }

/* locald59 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD59 base address */
#define DISPLAY__SEERIS__LOCALD59_BASE           (0x4B724000u)
/** Peripheral DISPLAY__SEERIS__LOCALD59 base pointer */
#define DISPLAY__SEERIS__LOCALD59                ((locald59_Type *)DISPLAY__SEERIS__LOCALD59_BASE)
/** Array initializer of locald59 peripheral base addresses */
#define locald59_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD59_BASE }
/** Array initializer of locald59 peripheral base pointers */
#define locald59_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD59 }

/* locald60 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD60 base address */
#define DISPLAY__SEERIS__LOCALD60_BASE           (0x4B724080u)
/** Peripheral DISPLAY__SEERIS__LOCALD60 base pointer */
#define DISPLAY__SEERIS__LOCALD60                ((locald60_Type *)DISPLAY__SEERIS__LOCALD60_BASE)
/** Array initializer of locald60 peripheral base addresses */
#define locald60_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD60_BASE }
/** Array initializer of locald60 peripheral base pointers */
#define locald60_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD60 }

/* locald61 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD61 base address */
#define DISPLAY__SEERIS__LOCALD61_BASE           (0x4B724100u)
/** Peripheral DISPLAY__SEERIS__LOCALD61 base pointer */
#define DISPLAY__SEERIS__LOCALD61                ((locald61_Type *)DISPLAY__SEERIS__LOCALD61_BASE)
/** Array initializer of locald61 peripheral base addresses */
#define locald61_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD61_BASE }
/** Array initializer of locald61 peripheral base pointers */
#define locald61_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD61 }

/* locald62 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD62 base address */
#define DISPLAY__SEERIS__LOCALD62_BASE           (0x4B724180u)
/** Peripheral DISPLAY__SEERIS__LOCALD62 base pointer */
#define DISPLAY__SEERIS__LOCALD62                ((locald62_Type *)DISPLAY__SEERIS__LOCALD62_BASE)
/** Array initializer of locald62 peripheral base addresses */
#define locald62_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD62_BASE }
/** Array initializer of locald62 peripheral base pointers */
#define locald62_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD62 }

/* locald63 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD63 base address */
#define DISPLAY__SEERIS__LOCALD63_BASE           (0x4B724200u)
/** Peripheral DISPLAY__SEERIS__LOCALD63 base pointer */
#define DISPLAY__SEERIS__LOCALD63                ((locald63_Type *)DISPLAY__SEERIS__LOCALD63_BASE)
/** Array initializer of locald63 peripheral base addresses */
#define locald63_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD63_BASE }
/** Array initializer of locald63 peripheral base pointers */
#define locald63_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD63 }

/* locald64 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD64 base address */
#define DISPLAY__SEERIS__LOCALD64_BASE           (0x4B724280u)
/** Peripheral DISPLAY__SEERIS__LOCALD64 base pointer */
#define DISPLAY__SEERIS__LOCALD64                ((locald64_Type *)DISPLAY__SEERIS__LOCALD64_BASE)
/** Array initializer of locald64 peripheral base addresses */
#define locald64_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD64_BASE }
/** Array initializer of locald64 peripheral base pointers */
#define locald64_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD64 }

/* locald65 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD65 base address */
#define DISPLAY__SEERIS__LOCALD65_BASE           (0x4B724300u)
/** Peripheral DISPLAY__SEERIS__LOCALD65 base pointer */
#define DISPLAY__SEERIS__LOCALD65                ((locald65_Type *)DISPLAY__SEERIS__LOCALD65_BASE)
/** Array initializer of locald65 peripheral base addresses */
#define locald65_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD65_BASE }
/** Array initializer of locald65 peripheral base pointers */
#define locald65_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD65 }

/* locald66 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD66 base address */
#define DISPLAY__SEERIS__LOCALD66_BASE           (0x4B724380u)
/** Peripheral DISPLAY__SEERIS__LOCALD66 base pointer */
#define DISPLAY__SEERIS__LOCALD66                ((locald66_Type *)DISPLAY__SEERIS__LOCALD66_BASE)
/** Array initializer of locald66 peripheral base addresses */
#define locald66_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD66_BASE }
/** Array initializer of locald66 peripheral base pointers */
#define locald66_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD66 }

/* locald67 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD67 base address */
#define DISPLAY__SEERIS__LOCALD67_BASE           (0x4B724400u)
/** Peripheral DISPLAY__SEERIS__LOCALD67 base pointer */
#define DISPLAY__SEERIS__LOCALD67                ((locald67_Type *)DISPLAY__SEERIS__LOCALD67_BASE)
/** Array initializer of locald67 peripheral base addresses */
#define locald67_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD67_BASE }
/** Array initializer of locald67 peripheral base pointers */
#define locald67_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD67 }

/* locald68 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD68 base address */
#define DISPLAY__SEERIS__LOCALD68_BASE           (0x4B724480u)
/** Peripheral DISPLAY__SEERIS__LOCALD68 base pointer */
#define DISPLAY__SEERIS__LOCALD68                ((locald68_Type *)DISPLAY__SEERIS__LOCALD68_BASE)
/** Array initializer of locald68 peripheral base addresses */
#define locald68_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD68_BASE }
/** Array initializer of locald68 peripheral base pointers */
#define locald68_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD68 }

/* locald69 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD69 base address */
#define DISPLAY__SEERIS__LOCALD69_BASE           (0x4B724500u)
/** Peripheral DISPLAY__SEERIS__LOCALD69 base pointer */
#define DISPLAY__SEERIS__LOCALD69                ((locald69_Type *)DISPLAY__SEERIS__LOCALD69_BASE)
/** Array initializer of locald69 peripheral base addresses */
#define locald69_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD69_BASE }
/** Array initializer of locald69 peripheral base pointers */
#define locald69_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD69 }

/* locald70 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD70 base address */
#define DISPLAY__SEERIS__LOCALD70_BASE           (0x4B724580u)
/** Peripheral DISPLAY__SEERIS__LOCALD70 base pointer */
#define DISPLAY__SEERIS__LOCALD70                ((locald70_Type *)DISPLAY__SEERIS__LOCALD70_BASE)
/** Array initializer of locald70 peripheral base addresses */
#define locald70_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD70_BASE }
/** Array initializer of locald70 peripheral base pointers */
#define locald70_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD70 }

/* locald71 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD71 base address */
#define DISPLAY__SEERIS__LOCALD71_BASE           (0x4B724600u)
/** Peripheral DISPLAY__SEERIS__LOCALD71 base pointer */
#define DISPLAY__SEERIS__LOCALD71                ((locald71_Type *)DISPLAY__SEERIS__LOCALD71_BASE)
/** Array initializer of locald71 peripheral base addresses */
#define locald71_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD71_BASE }
/** Array initializer of locald71 peripheral base pointers */
#define locald71_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD71 }

/* locald72 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD72 base address */
#define DISPLAY__SEERIS__LOCALD72_BASE           (0x4B724680u)
/** Peripheral DISPLAY__SEERIS__LOCALD72 base pointer */
#define DISPLAY__SEERIS__LOCALD72                ((locald72_Type *)DISPLAY__SEERIS__LOCALD72_BASE)
/** Array initializer of locald72 peripheral base addresses */
#define locald72_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD72_BASE }
/** Array initializer of locald72 peripheral base pointers */
#define locald72_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD72 }

/* locald73 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD73 base address */
#define DISPLAY__SEERIS__LOCALD73_BASE           (0x4B724700u)
/** Peripheral DISPLAY__SEERIS__LOCALD73 base pointer */
#define DISPLAY__SEERIS__LOCALD73                ((locald73_Type *)DISPLAY__SEERIS__LOCALD73_BASE)
/** Array initializer of locald73 peripheral base addresses */
#define locald73_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD73_BASE }
/** Array initializer of locald73 peripheral base pointers */
#define locald73_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD73 }

/* locald74 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD74 base address */
#define DISPLAY__SEERIS__LOCALD74_BASE           (0x4B724780u)
/** Peripheral DISPLAY__SEERIS__LOCALD74 base pointer */
#define DISPLAY__SEERIS__LOCALD74                ((locald74_Type *)DISPLAY__SEERIS__LOCALD74_BASE)
/** Array initializer of locald74 peripheral base addresses */
#define locald74_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD74_BASE }
/** Array initializer of locald74 peripheral base pointers */
#define locald74_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD74 }

/* locald75 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD75 base address */
#define DISPLAY__SEERIS__LOCALD75_BASE           (0x4B725000u)
/** Peripheral DISPLAY__SEERIS__LOCALD75 base pointer */
#define DISPLAY__SEERIS__LOCALD75                ((locald75_Type *)DISPLAY__SEERIS__LOCALD75_BASE)
/** Array initializer of locald75 peripheral base addresses */
#define locald75_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD75_BASE }
/** Array initializer of locald75 peripheral base pointers */
#define locald75_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD75 }

/* locald76 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD76 base address */
#define DISPLAY__SEERIS__LOCALD76_BASE           (0x4B726000u)
/** Peripheral DISPLAY__SEERIS__LOCALD76 base pointer */
#define DISPLAY__SEERIS__LOCALD76                ((locald76_Type *)DISPLAY__SEERIS__LOCALD76_BASE)
/** Array initializer of locald76 peripheral base addresses */
#define locald76_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD76_BASE }
/** Array initializer of locald76 peripheral base pointers */
#define locald76_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD76 }

/* locald77 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD77 base address */
#define DISPLAY__SEERIS__LOCALD77_BASE           (0x4B727000u)
/** Peripheral DISPLAY__SEERIS__LOCALD77 base pointer */
#define DISPLAY__SEERIS__LOCALD77                ((locald77_Type *)DISPLAY__SEERIS__LOCALD77_BASE)
/** Array initializer of locald77 peripheral base addresses */
#define locald77_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD77_BASE }
/** Array initializer of locald77 peripheral base pointers */
#define locald77_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD77 }

/* locald78 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALD78 base address */
#define DISPLAY__SEERIS__LOCALD78_BASE           (0x4B728000u)
/** Peripheral DISPLAY__SEERIS__LOCALD78 base pointer */
#define DISPLAY__SEERIS__LOCALD78                ((locald78_Type *)DISPLAY__SEERIS__LOCALD78_BASE)
/** Array initializer of locald78 peripheral base addresses */
#define locald78_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALD78_BASE }
/** Array initializer of locald78 peripheral base pointers */
#define locald78_BASE_PTRS                       { DISPLAY__SEERIS__LOCALD78 }

/* localdi1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALDI1 base address */
#define DISPLAY__SEERIS__LOCALDI1_BASE           (0x4B720FF8u)
/** Peripheral DISPLAY__SEERIS__LOCALDI1 base pointer */
#define DISPLAY__SEERIS__LOCALDI1                ((localdi1_Type *)DISPLAY__SEERIS__LOCALDI1_BASE)
/** Array initializer of localdi1 peripheral base addresses */
#define localdi1_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALDI1_BASE }
/** Array initializer of localdi1 peripheral base pointers */
#define localdi1_BASE_PTRS                       { DISPLAY__SEERIS__LOCALDI1 }

/* localdi2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALDI2 base address */
#define DISPLAY__SEERIS__LOCALDI2_BASE           (0x4B721000u)
/** Peripheral DISPLAY__SEERIS__LOCALDI2 base pointer */
#define DISPLAY__SEERIS__LOCALDI2                ((localdi2_Type *)DISPLAY__SEERIS__LOCALDI2_BASE)
/** Array initializer of localdi2 peripheral base addresses */
#define localdi2_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALDI2_BASE }
/** Array initializer of localdi2 peripheral base pointers */
#define localdi2_BASE_PTRS                       { DISPLAY__SEERIS__LOCALDI2 }

/* localdi3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALDI3 base address */
#define DISPLAY__SEERIS__LOCALDI3_BASE           (0x4B721020u)
/** Peripheral DISPLAY__SEERIS__LOCALDI3 base pointer */
#define DISPLAY__SEERIS__LOCALDI3                ((localdi3_Type *)DISPLAY__SEERIS__LOCALDI3_BASE)
/** Array initializer of localdi3 peripheral base addresses */
#define localdi3_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALDI3_BASE }
/** Array initializer of localdi3 peripheral base pointers */
#define localdi3_BASE_PTRS                       { DISPLAY__SEERIS__LOCALDI3 }

/* localdi4 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALDI4 base address */
#define DISPLAY__SEERIS__LOCALDI4_BASE           (0x4B72102Cu)
/** Peripheral DISPLAY__SEERIS__LOCALDI4 base pointer */
#define DISPLAY__SEERIS__LOCALDI4                ((localdi4_Type *)DISPLAY__SEERIS__LOCALDI4_BASE)
/** Array initializer of localdi4 peripheral base addresses */
#define localdi4_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALDI4_BASE }
/** Array initializer of localdi4 peripheral base pointers */
#define localdi4_BASE_PTRS                       { DISPLAY__SEERIS__LOCALDI4 }

/* localdi5 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALDI5 base address */
#define DISPLAY__SEERIS__LOCALDI5_BASE           (0x4B721040u)
/** Peripheral DISPLAY__SEERIS__LOCALDI5 base pointer */
#define DISPLAY__SEERIS__LOCALDI5                ((localdi5_Type *)DISPLAY__SEERIS__LOCALDI5_BASE)
/** Array initializer of localdi5 peripheral base addresses */
#define localdi5_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALDI5_BASE }
/** Array initializer of localdi5 peripheral base pointers */
#define localdi5_BASE_PTRS                       { DISPLAY__SEERIS__LOCALDI5 }

/* localdi6 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALDI6 base address */
#define DISPLAY__SEERIS__LOCALDI6_BASE           (0x4B72104Cu)
/** Peripheral DISPLAY__SEERIS__LOCALDI6 base pointer */
#define DISPLAY__SEERIS__LOCALDI6                ((localdi6_Type *)DISPLAY__SEERIS__LOCALDI6_BASE)
/** Array initializer of localdi6 peripheral base addresses */
#define localdi6_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALDI6_BASE }
/** Array initializer of localdi6 peripheral base pointers */
#define localdi6_BASE_PTRS                       { DISPLAY__SEERIS__LOCALDI6 }

/* localdi7 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALDI7 base address */
#define DISPLAY__SEERIS__LOCALDI7_BASE           (0x4B721060u)
/** Peripheral DISPLAY__SEERIS__LOCALDI7 base pointer */
#define DISPLAY__SEERIS__LOCALDI7                ((localdi7_Type *)DISPLAY__SEERIS__LOCALDI7_BASE)
/** Array initializer of localdi7 peripheral base addresses */
#define localdi7_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALDI7_BASE }
/** Array initializer of localdi7 peripheral base pointers */
#define localdi7_BASE_PTRS                       { DISPLAY__SEERIS__LOCALDI7 }

/* localdi8 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALDI8 base address */
#define DISPLAY__SEERIS__LOCALDI8_BASE           (0x4B72107Cu)
/** Peripheral DISPLAY__SEERIS__LOCALDI8 base pointer */
#define DISPLAY__SEERIS__LOCALDI8                ((localdi8_Type *)DISPLAY__SEERIS__LOCALDI8_BASE)
/** Array initializer of localdi8 peripheral base addresses */
#define localdi8_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALDI8_BASE }
/** Array initializer of localdi8 peripheral base pointers */
#define localdi8_BASE_PTRS                       { DISPLAY__SEERIS__LOCALDI8 }

/* localdi9 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALDI9 base address */
#define DISPLAY__SEERIS__LOCALDI9_BASE           (0x4B721080u)
/** Peripheral DISPLAY__SEERIS__LOCALDI9 base pointer */
#define DISPLAY__SEERIS__LOCALDI9                ((localdi9_Type *)DISPLAY__SEERIS__LOCALDI9_BASE)
/** Array initializer of localdi9 peripheral base addresses */
#define localdi9_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALDI9_BASE }
/** Array initializer of localdi9 peripheral base pointers */
#define localdi9_BASE_PTRS                       { DISPLAY__SEERIS__LOCALDI9 }

/* localdim - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LOCALDIM base address */
#define DISPLAY__SEERIS__LOCALDIM_BASE           (0x4B720000u)
/** Peripheral DISPLAY__SEERIS__LOCALDIM base pointer */
#define DISPLAY__SEERIS__LOCALDIM                ((localdim_Type *)DISPLAY__SEERIS__LOCALDIM_BASE)
/** Array initializer of localdim peripheral base addresses */
#define localdim_BASE_ADDRS                      { DISPLAY__SEERIS__LOCALDIM_BASE }
/** Array initializer of localdim peripheral base pointers */
#define localdim_BASE_PTRS                       { DISPLAY__SEERIS__LOCALDIM }

/* lut3d - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LUT3D base address */
#define DISPLAY__SEERIS__LUT3D_BASE              (0x4B6D0000u)
/** Peripheral DISPLAY__SEERIS__LUT3D base pointer */
#define DISPLAY__SEERIS__LUT3D                   ((lut3d_Type *)DISPLAY__SEERIS__LUT3D_BASE)
/** Array initializer of lut3d peripheral base addresses */
#define lut3d_BASE_ADDRS                         { DISPLAY__SEERIS__LUT3D_BASE }
/** Array initializer of lut3d peripheral base pointers */
#define lut3d_BASE_PTRS                          { DISPLAY__SEERIS__LUT3D }

/* lut3d1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LUT3D1 base address */
#define DISPLAY__SEERIS__LUT3D1_BASE             (0x4B6D2000u)
/** Peripheral DISPLAY__SEERIS__LUT3D1 base pointer */
#define DISPLAY__SEERIS__LUT3D1                  ((lut3d1_Type *)DISPLAY__SEERIS__LUT3D1_BASE)
/** Array initializer of lut3d1 peripheral base addresses */
#define lut3d1_BASE_ADDRS                        { DISPLAY__SEERIS__LUT3D1_BASE }
/** Array initializer of lut3d1 peripheral base pointers */
#define lut3d1_BASE_PTRS                         { DISPLAY__SEERIS__LUT3D1 }

/* lut3d2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LUT3D2 base address */
#define DISPLAY__SEERIS__LUT3D2_BASE             (0x4B760000u)
/** Peripheral DISPLAY__SEERIS__LUT3D2 base pointer */
#define DISPLAY__SEERIS__LUT3D2                  ((lut3d2_Type *)DISPLAY__SEERIS__LUT3D2_BASE)
/** Array initializer of lut3d2 peripheral base addresses */
#define lut3d2_BASE_ADDRS                        { DISPLAY__SEERIS__LUT3D2_BASE }
/** Array initializer of lut3d2 peripheral base pointers */
#define lut3d2_BASE_PTRS                         { DISPLAY__SEERIS__LUT3D2 }

/* lut3d3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__LUT3D3 base address */
#define DISPLAY__SEERIS__LUT3D3_BASE             (0x4B762000u)
/** Peripheral DISPLAY__SEERIS__LUT3D3 base pointer */
#define DISPLAY__SEERIS__LUT3D3                  ((lut3d3_Type *)DISPLAY__SEERIS__LUT3D3_BASE)
/** Array initializer of lut3d3 peripheral base addresses */
#define lut3d3_BASE_ADDRS                        { DISPLAY__SEERIS__LUT3D3_BASE }
/** Array initializer of lut3d3 peripheral base pointers */
#define lut3d3_BASE_PTRS                         { DISPLAY__SEERIS__LUT3D3 }

/* matrix - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__MATRIX base address */
#define DISPLAY__SEERIS__MATRIX_BASE             (0x4B460000u)
/** Peripheral DISPLAY__SEERIS__MATRIX base pointer */
#define DISPLAY__SEERIS__MATRIX                  ((matrix_Type *)DISPLAY__SEERIS__MATRIX_BASE)
/** Array initializer of matrix peripheral base addresses */
#define matrix_BASE_ADDRS                        { DISPLAY__SEERIS__MATRIX_BASE }
/** Array initializer of matrix peripheral base pointers */
#define matrix_BASE_PTRS                         { DISPLAY__SEERIS__MATRIX }

/* matrix1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__MATRIX1 base address */
#define DISPLAY__SEERIS__MATRIX1_BASE            (0x4B460030u)
/** Peripheral DISPLAY__SEERIS__MATRIX1 base pointer */
#define DISPLAY__SEERIS__MATRIX1                 ((matrix1_Type *)DISPLAY__SEERIS__MATRIX1_BASE)
/** Array initializer of matrix1 peripheral base addresses */
#define matrix1_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIX1_BASE }
/** Array initializer of matrix1 peripheral base pointers */
#define matrix1_BASE_PTRS                        { DISPLAY__SEERIS__MATRIX1 }

/* matrix2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__MATRIX2 base address */
#define DISPLAY__SEERIS__MATRIX2_BASE            (0x4B630000u)
/** Peripheral DISPLAY__SEERIS__MATRIX2 base pointer */
#define DISPLAY__SEERIS__MATRIX2                 ((matrix2_Type *)DISPLAY__SEERIS__MATRIX2_BASE)
/** Array initializer of matrix2 peripheral base addresses */
#define matrix2_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIX2_BASE }
/** Array initializer of matrix2 peripheral base pointers */
#define matrix2_BASE_PTRS                        { DISPLAY__SEERIS__MATRIX2 }

/* matrix3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__MATRIX3 base address */
#define DISPLAY__SEERIS__MATRIX3_BASE            (0x4B630030u)
/** Peripheral DISPLAY__SEERIS__MATRIX3 base pointer */
#define DISPLAY__SEERIS__MATRIX3                 ((matrix3_Type *)DISPLAY__SEERIS__MATRIX3_BASE)
/** Array initializer of matrix3 peripheral base addresses */
#define matrix3_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIX3_BASE }
/** Array initializer of matrix3 peripheral base pointers */
#define matrix3_BASE_PTRS                        { DISPLAY__SEERIS__MATRIX3 }

/* matrix4c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__MATRIX4C base address */
#define DISPLAY__SEERIS__MATRIX4C_BASE           (0x4B631000u)
/** Peripheral DISPLAY__SEERIS__MATRIX4C base pointer */
#define DISPLAY__SEERIS__MATRIX4C                ((matrix4c_Type *)DISPLAY__SEERIS__MATRIX4C_BASE)
/** Array initializer of matrix4c peripheral base addresses */
#define matrix4c_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIX4C_BASE }
/** Array initializer of matrix4c peripheral base pointers */
#define matrix4c_BASE_PTRS                       { DISPLAY__SEERIS__MATRIX4C }

/* matrix9c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__MATRIX9C base address */
#define DISPLAY__SEERIS__MATRIX9C_BASE           (0x4B461000u)
/** Peripheral DISPLAY__SEERIS__MATRIX9C base pointer */
#define DISPLAY__SEERIS__MATRIX9C                ((matrix9c_Type *)DISPLAY__SEERIS__MATRIX9C_BASE)
/** Array initializer of matrix9c peripheral base addresses */
#define matrix9c_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIX9C_BASE }
/** Array initializer of matrix9c peripheral base pointers */
#define matrix9c_BASE_PTRS                       { DISPLAY__SEERIS__MATRIX9C }

/* matrixl - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__MATRIXL base address */
#define DISPLAY__SEERIS__MATRIXL_BASE            (0x4B6C0000u)
/** Peripheral DISPLAY__SEERIS__MATRIXL base pointer */
#define DISPLAY__SEERIS__MATRIXL                 ((matrixl_Type *)DISPLAY__SEERIS__MATRIXL_BASE)
/** Array initializer of matrixl peripheral base addresses */
#define matrixl_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIXL_BASE }
/** Array initializer of matrixl peripheral base pointers */
#define matrixl_BASE_PTRS                        { DISPLAY__SEERIS__MATRIXL }

/* matrixl1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__MATRIXL1 base address */
#define DISPLAY__SEERIS__MATRIXL1_BASE           (0x4B6C0030u)
/** Peripheral DISPLAY__SEERIS__MATRIXL1 base pointer */
#define DISPLAY__SEERIS__MATRIXL1                ((matrixl1_Type *)DISPLAY__SEERIS__MATRIXL1_BASE)
/** Array initializer of matrixl1 peripheral base addresses */
#define matrixl1_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIXL1_BASE }
/** Array initializer of matrixl1 peripheral base pointers */
#define matrixl1_BASE_PTRS                       { DISPLAY__SEERIS__MATRIXL1 }

/* matrixl2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__MATRIXL2 base address */
#define DISPLAY__SEERIS__MATRIXL2_BASE           (0x4B750000u)
/** Peripheral DISPLAY__SEERIS__MATRIXL2 base pointer */
#define DISPLAY__SEERIS__MATRIXL2                ((matrixl2_Type *)DISPLAY__SEERIS__MATRIXL2_BASE)
/** Array initializer of matrixl2 peripheral base addresses */
#define matrixl2_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIXL2_BASE }
/** Array initializer of matrixl2 peripheral base pointers */
#define matrixl2_BASE_PTRS                       { DISPLAY__SEERIS__MATRIXL2 }

/* matrixl3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__MATRIXL3 base address */
#define DISPLAY__SEERIS__MATRIXL3_BASE           (0x4B750030u)
/** Peripheral DISPLAY__SEERIS__MATRIXL3 base pointer */
#define DISPLAY__SEERIS__MATRIXL3                ((matrixl3_Type *)DISPLAY__SEERIS__MATRIXL3_BASE)
/** Array initializer of matrixl3 peripheral base addresses */
#define matrixl3_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIXL3_BASE }
/** Array initializer of matrixl3 peripheral base pointers */
#define matrixl3_BASE_PTRS                       { DISPLAY__SEERIS__MATRIXL3 }

/* rop - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__ROP base address */
#define DISPLAY__SEERIS__ROP_BASE                (0x4B440000u)
/** Peripheral DISPLAY__SEERIS__ROP base pointer */
#define DISPLAY__SEERIS__ROP                     ((rop_Type *)DISPLAY__SEERIS__ROP_BASE)
/** Array initializer of rop peripheral base addresses */
#define rop_BASE_ADDRS                           { DISPLAY__SEERIS__ROP_BASE }
/** Array initializer of rop peripheral base pointers */
#define rop_BASE_PTRS                            { DISPLAY__SEERIS__ROP }

/* rop9cfg - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__ROP9CFG base address */
#define DISPLAY__SEERIS__ROP9CFG_BASE            (0x4B441000u)
/** Peripheral DISPLAY__SEERIS__ROP9CFG base pointer */
#define DISPLAY__SEERIS__ROP9CFG                 ((rop9cfg_Type *)DISPLAY__SEERIS__ROP9CFG_BASE)
/** Array initializer of rop9cfg peripheral base addresses */
#define rop9cfg_BASE_ADDRS                       { DISPLAY__SEERIS__ROP9CFG_BASE }
/** Array initializer of rop9cfg peripheral base pointers */
#define rop9cfg_BASE_PTRS                        { DISPLAY__SEERIS__ROP9CFG }

/* sig - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__SIG base address */
#define DISPLAY__SEERIS__SIG_BASE                (0x4B710000u)
/** Peripheral DISPLAY__SEERIS__SIG base pointer */
#define DISPLAY__SEERIS__SIG                     ((sig_Type *)DISPLAY__SEERIS__SIG_BASE)
/** Array initializer of sig peripheral base addresses */
#define sig_BASE_ADDRS                           { DISPLAY__SEERIS__SIG_BASE }
/** Array initializer of sig peripheral base pointers */
#define sig_BASE_PTRS                            { DISPLAY__SEERIS__SIG }

/* sig0cfg - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__SIG0CFG base address */
#define DISPLAY__SEERIS__SIG0CFG_BASE            (0x4B711000u)
/** Peripheral DISPLAY__SEERIS__SIG0CFG base pointer */
#define DISPLAY__SEERIS__SIG0CFG                 ((sig0cfg_Type *)DISPLAY__SEERIS__SIG0CFG_BASE)
/** Array initializer of sig0cfg peripheral base addresses */
#define sig0cfg_BASE_ADDRS                       { DISPLAY__SEERIS__SIG0CFG_BASE }
/** Array initializer of sig0cfg peripheral base pointers */
#define sig0cfg_BASE_PTRS                        { DISPLAY__SEERIS__SIG0CFG }

/* sig1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__SIG1 base address */
#define DISPLAY__SEERIS__SIG1_BASE               (0x4B710400u)
/** Peripheral DISPLAY__SEERIS__SIG1 base pointer */
#define DISPLAY__SEERIS__SIG1                    ((sig1_Type *)DISPLAY__SEERIS__SIG1_BASE)
/** Array initializer of sig1 peripheral base addresses */
#define sig1_BASE_ADDRS                          { DISPLAY__SEERIS__SIG1_BASE }
/** Array initializer of sig1 peripheral base pointers */
#define sig1_BASE_PTRS                           { DISPLAY__SEERIS__SIG1 }

/* sig1cfg - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__SIG1CFG base address */
#define DISPLAY__SEERIS__SIG1CFG_BASE            (0x4B7A1000u)
/** Peripheral DISPLAY__SEERIS__SIG1CFG base pointer */
#define DISPLAY__SEERIS__SIG1CFG                 ((sig1cfg_Type *)DISPLAY__SEERIS__SIG1CFG_BASE)
/** Array initializer of sig1cfg peripheral base addresses */
#define sig1cfg_BASE_ADDRS                       { DISPLAY__SEERIS__SIG1CFG_BASE }
/** Array initializer of sig1cfg peripheral base pointers */
#define sig1cfg_BASE_PTRS                        { DISPLAY__SEERIS__SIG1CFG }

/* sig2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__SIG2 base address */
#define DISPLAY__SEERIS__SIG2_BASE               (0x4B7A0000u)
/** Peripheral DISPLAY__SEERIS__SIG2 base pointer */
#define DISPLAY__SEERIS__SIG2                    ((sig2_Type *)DISPLAY__SEERIS__SIG2_BASE)
/** Array initializer of sig2 peripheral base addresses */
#define sig2_BASE_ADDRS                          { DISPLAY__SEERIS__SIG2_BASE }
/** Array initializer of sig2 peripheral base pointers */
#define sig2_BASE_PTRS                           { DISPLAY__SEERIS__SIG2 }

/* sig3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__SIG3 base address */
#define DISPLAY__SEERIS__SIG3_BASE               (0x4B7A0400u)
/** Peripheral DISPLAY__SEERIS__SIG3 base pointer */
#define DISPLAY__SEERIS__SIG3                    ((sig3_Type *)DISPLAY__SEERIS__SIG3_BASE)
/** Array initializer of sig3 peripheral base addresses */
#define sig3_BASE_ADDRS                          { DISPLAY__SEERIS__SIG3_BASE }
/** Array initializer of sig3 peripheral base pointers */
#define sig3_BASE_PTRS                           { DISPLAY__SEERIS__SIG3 }

/* splanar - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__SPLANAR base address */
#define DISPLAY__SEERIS__SPLANAR_BASE            (0x4B4E0000u)
/** Peripheral DISPLAY__SEERIS__SPLANAR base pointer */
#define DISPLAY__SEERIS__SPLANAR                 ((splanar_Type *)DISPLAY__SEERIS__SPLANAR_BASE)
/** Array initializer of splanar peripheral base addresses */
#define splanar_BASE_ADDRS                       { DISPLAY__SEERIS__SPLANAR_BASE }
/** Array initializer of splanar peripheral base pointers */
#define splanar_BASE_PTRS                        { DISPLAY__SEERIS__SPLANAR }

/* splanar1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__SPLANAR1 base address */
#define DISPLAY__SEERIS__SPLANAR1_BASE           (0x4B4E0038u)
/** Peripheral DISPLAY__SEERIS__SPLANAR1 base pointer */
#define DISPLAY__SEERIS__SPLANAR1                ((splanar1_Type *)DISPLAY__SEERIS__SPLANAR1_BASE)
/** Array initializer of splanar1 peripheral base addresses */
#define splanar1_BASE_ADDRS                      { DISPLAY__SEERIS__SPLANAR1_BASE }
/** Array initializer of splanar1 peripheral base pointers */
#define splanar1_BASE_PTRS                       { DISPLAY__SEERIS__SPLANAR1 }

/* splanar2 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__SPLANAR2 base address */
#define DISPLAY__SEERIS__SPLANAR2_BASE           (0x4B4E0048u)
/** Peripheral DISPLAY__SEERIS__SPLANAR2 base pointer */
#define DISPLAY__SEERIS__SPLANAR2                ((splanar2_Type *)DISPLAY__SEERIS__SPLANAR2_BASE)
/** Array initializer of splanar2 peripheral base addresses */
#define splanar2_BASE_ADDRS                      { DISPLAY__SEERIS__SPLANAR2_BASE }
/** Array initializer of splanar2 peripheral base pointers */
#define splanar2_BASE_PTRS                       { DISPLAY__SEERIS__SPLANAR2 }

/* splanar3 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__SPLANAR3 base address */
#define DISPLAY__SEERIS__SPLANAR3_BASE           (0x4B4E0070u)
/** Peripheral DISPLAY__SEERIS__SPLANAR3 base pointer */
#define DISPLAY__SEERIS__SPLANAR3                ((splanar3_Type *)DISPLAY__SEERIS__SPLANAR3_BASE)
/** Array initializer of splanar3 peripheral base addresses */
#define splanar3_BASE_ADDRS                      { DISPLAY__SEERIS__SPLANAR3_BASE }
/** Array initializer of splanar3 peripheral base pointers */
#define splanar3_BASE_PTRS                       { DISPLAY__SEERIS__SPLANAR3 }

/* store9c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__STORE9C base address */
#define DISPLAY__SEERIS__STORE9C_BASE            (0x4B4E1000u)
/** Peripheral DISPLAY__SEERIS__STORE9C base pointer */
#define DISPLAY__SEERIS__STORE9C                 ((store9c_Type *)DISPLAY__SEERIS__STORE9C_BASE)
/** Array initializer of store9c peripheral base addresses */
#define store9c_BASE_ADDRS                       { DISPLAY__SEERIS__STORE9C_BASE }
/** Array initializer of store9c peripheral base pointers */
#define store9c_BASE_PTRS                        { DISPLAY__SEERIS__STORE9C }

/* vscaler - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__VSCALER base address */
#define DISPLAY__SEERIS__VSCALER_BASE            (0x4B4C0000u)
/** Peripheral DISPLAY__SEERIS__VSCALER base pointer */
#define DISPLAY__SEERIS__VSCALER                 ((vscaler_Type *)DISPLAY__SEERIS__VSCALER_BASE)
/** Array initializer of vscaler peripheral base addresses */
#define vscaler_BASE_ADDRS                       { DISPLAY__SEERIS__VSCALER_BASE }
/** Array initializer of vscaler peripheral base pointers */
#define vscaler_BASE_PTRS                        { DISPLAY__SEERIS__VSCALER }

/* vscaler1 - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__VSCALER1 base address */
#define DISPLAY__SEERIS__VSCALER1_BASE           (0x4B650000u)
/** Peripheral DISPLAY__SEERIS__VSCALER1 base pointer */
#define DISPLAY__SEERIS__VSCALER1                ((vscaler1_Type *)DISPLAY__SEERIS__VSCALER1_BASE)
/** Array initializer of vscaler1 peripheral base addresses */
#define vscaler1_BASE_ADDRS                      { DISPLAY__SEERIS__VSCALER1_BASE }
/** Array initializer of vscaler1 peripheral base pointers */
#define vscaler1_BASE_PTRS                       { DISPLAY__SEERIS__VSCALER1 }

/* vsclr4c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__VSCLR4C base address */
#define DISPLAY__SEERIS__VSCLR4C_BASE            (0x4B4C1000u)
/** Peripheral DISPLAY__SEERIS__VSCLR4C base pointer */
#define DISPLAY__SEERIS__VSCLR4C                 ((vsclr4c_Type *)DISPLAY__SEERIS__VSCLR4C_BASE)
/** Array initializer of vsclr4c peripheral base addresses */
#define vsclr4c_BASE_ADDRS                       { DISPLAY__SEERIS__VSCLR4C_BASE }
/** Array initializer of vsclr4c peripheral base pointers */
#define vsclr4c_BASE_PTRS                        { DISPLAY__SEERIS__VSCLR4C }

/* vsclr9c - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__VSCLR9C base address */
#define DISPLAY__SEERIS__VSCLR9C_BASE            (0x4B651000u)
/** Peripheral DISPLAY__SEERIS__VSCLR9C base pointer */
#define DISPLAY__SEERIS__VSCLR9C                 ((vsclr9c_Type *)DISPLAY__SEERIS__VSCLR9C_BASE)
/** Array initializer of vsclr9c peripheral base addresses */
#define vsclr9c_BASE_ADDRS                       { DISPLAY__SEERIS__VSCLR9C_BASE }
/** Array initializer of vsclr9c peripheral base pointers */
#define vsclr9c_BASE_PTRS                        { DISPLAY__SEERIS__VSCLR9C }

/* xpc - Peripheral instance base addresses */
/** Peripheral DISPLAY__SEERIS__XPC base address */
#define DISPLAY__SEERIS__XPC_BASE                (0x4B420000u)
/** Peripheral DISPLAY__SEERIS__XPC base pointer */
#define DISPLAY__SEERIS__XPC                     ((xpc_Type *)DISPLAY__SEERIS__XPC_BASE)
/** Array initializer of xpc peripheral base addresses */
#define xpc_BASE_ADDRS                           { DISPLAY__SEERIS__XPC_BASE }
/** Array initializer of xpc peripheral base pointers */
#define xpc_BASE_PTRS                            { DISPLAY__SEERIS__XPC }

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


#endif  /* MIMX95294_CM7_COMMON_H_ */

