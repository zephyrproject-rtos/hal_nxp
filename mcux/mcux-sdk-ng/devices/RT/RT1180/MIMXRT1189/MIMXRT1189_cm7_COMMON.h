/*
** ###################################################################
**     Processors:          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189XVM8B_cm7
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    IMXRT1180RM, Rev 5, 01/2024
**     Version:             rev. 2.0, 2024-01-18
**     Build:               b241025
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT1189_cm7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**
** ###################################################################
*/

/*!
 * @file MIMXRT1189_cm7_COMMON.h
 * @version 2.0
 * @date 2024-01-18
 * @brief CMSIS Peripheral Access Layer for MIMXRT1189_cm7
 *
 * CMSIS Peripheral Access Layer for MIMXRT1189_cm7
 */

#if !defined(MIMXRT1189_CM7_COMMON_H_)
#define MIMXRT1189_CM7_COMMON_H_                 /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0200U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U

/* ----------------------------------------------------------------------------
   --
   ---------------------------------------------------------------------------- */

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
            (volatile uint16_t *)XBAR1_BASE, 0x0U, 111U, 0xDEU, 4U \
        }, \
        { \
            (volatile uint16_t *)XBAR2_BASE, 0x0U, 16U, 0x20U, 1U \
        }, \
        { \
            (volatile uint16_t *)XBAR3_BASE, 0x0U, 16U, 0x20U, 1U \
        } \
    }



/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 255                /**< Number of interrupts in the Vector table */

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
  TMR1_IRQn                    = 0,                /**< TMR1 interrupt */
  DAP_IRQn                     = 1,                /**< DAP interrupt */
  M7_CTI_TRIGGER_OUTPUT_IRQn   = 2,                /**< CTI trigger outputs from CM7 */
  M33_CTI_TRIGGER_OUTPUT_IRQn  = 3,                /**< CTI trigger outputs from CM33 */
  TMR5_IRQn                    = 4,                /**< TMR5 interrupt */
  TMR6_IRQn                    = 5,                /**< TMR6 interrupt */
  TMR7_IRQn                    = 6,                /**< TMR7 interrupt */
  TMR8_IRQn                    = 7,                /**< TMR8 interrupt */
  CAN1_IRQn                    = 8,                /**< CAN1 interrupt */
  CAN1_ERROR_IRQn              = 9,                /**< CAN1 error interrupt */
  GPIO1_0_IRQn                 = 10,               /**< GPIO1 interrupt 0 */
  GPIO1_1_IRQn                 = 11,               /**< GPIO1 interrupt 1 */
  I3C1_IRQn                    = 12,               /**< I3C1 interrupt */
  LPI2C1_IRQn                  = 13,               /**< LPI2C1 interrupt */
  LPI2C2_IRQn                  = 14,               /**< LPI2C2 interrupt */
  LPIT1_IRQn                   = 15,               /**< LPIT1 interrupt */
  LPSPI1_IRQn                  = 16,               /**< LPSPI1 interrupt */
  LPSPI2_IRQn                  = 17,               /**< LPSPI2 interrupt */
  LPTMR1_IRQn                  = 18,               /**< LPTMR1 interrupt */
  LPUART1_IRQn                 = 19,               /**< LPUART1 interrupt */
  LPUART2_IRQn                 = 20,               /**< LPUART2 interrupt */
  MU1_IRQn                     = 21,               /**< MU1 interrupt */
  MU2_IRQn                     = 22,               /**< MU2 interrupt */
  PWM1_FAULT_IRQn              = 23,               /**< PWM1 fault or reload error interrupt */
  PWM1_0_IRQn                  = 24,               /**< PWM1 capture 0, compare 0, or reload 0 interrupt */
  PWM1_1_IRQn                  = 25,               /**< PWM1 capture 1, compare 1, or reload 1 interrupt */
  PWM1_2_IRQn                  = 26,               /**< PWM1 capture 2, compare 2, or reload 2 interrupt */
  PWM1_3_IRQn                  = 27,               /**< PWM1 capture 3, compare 3, or reload 3 interrupt */
  EDGELOCK_TRUST_MUA_RX_FULL_IRQn = 28,            /**< Edgelock Trust MUA RX full interrupt */
  EDGELOCK_TRUST_MUA_TX_EMPTY_IRQn = 29,           /**< Edgelock Trust MUA TX empty interrupt */
  EDGELOCK_APPS_CORE_MUA_RX_FULL_IRQn = 30,        /**< Edgelock Apps Core MUA RX full interrupt */
  EDGELOCK_APPS_CORE_MUA_TX_EMPTY_IRQn = 31,       /**< Edgelock Apps Core MUA TX empty interrupt */
  EDGELOCK_REALTIME_CORE_MUA_RX_FULL_IRQn = 32,    /**< Edgelock Realtime Core MUA RX full interrupt */
  EDGELOCK_REALTIME_CORE_MUA_TX_EMPTY_IRQn = 33,   /**< Edgelock Realtime Core MUA TX empty interrupt */
  EDGELOCK_SECURE_IRQn         = 34,               /**< Edgelock secure interrupt */
  EDGELOCK_NONSECURE_IRQn      = 35,               /**< Edgelock non-secure interrupt */
  TPM1_IRQn                    = 36,               /**< TPM1 interrupt */
  TPM2_IRQn                    = 37,               /**< TPM2 interrupt */
  RTWDOG1_IRQn                 = 38,               /**< RTWDOG1 interrupt */
  RTWDOG2_IRQn                 = 39,               /**< RTWDOG2 interrupt */
  TRDC_MGR_AON_IRQn            = 40,               /**< AONMIX TRDC transfer error interrupt */
  PDM_HWVAD_EVENT_IRQn         = 41,               /**< HWVAD event interrupt */
  PDM_HWVAD_ERROR_IRQn         = 42,               /**< HWVAD error interrupt */
  PDM_EVENT_IRQn               = 43,               /**< PDM event interrupt */
  PDM_ERROR_IRQn               = 44,               /**< PDM error interrupt */
  SAI1_IRQn                    = 45,               /**< SAI interrupt */
  CM33_PS_IRQn                 = 46,               /**< M33 PS Tag/Data Parity Error */
  CM33_TCM_ECC_IRQn            = 47,               /**< M33 TCM ECC interrupt */
  CM33_TCM_ERROR_IRQn          = 48,               /**< M33 TCM Error interrupt */
  CM7_TCM_ECC_IRQn             = 49,               /**< M7 TCM ECC interrupt */
  CM7_TCM_ERROR_IRQn           = 50,               /**< M7 TCM Error interrupt */
  CAN2_IRQn                    = 51,               /**< CAN2 interrupt */
  CAN2_ERROR_IRQn              = 52,               /**< CAN2 error interrupt */
  FLEXIO1_IRQn                 = 53,               /**< FLEXIO1 interrupt */
  FLEXIO2_IRQn                 = 54,               /**< FLEXIO2 interrupt */
  FLEXSPI1_IRQn                = 55,               /**< FLEXSPI1 interrupt */
  FLEXSPI2_IRQn                = 56,               /**< FLEXSPI2 interrupt */
  GPIO2_0_IRQn                 = 57,               /**< GPIO2 interrupt 0 */
  GPIO2_1_IRQn                 = 58,               /**< GPIO2 interrupt 1 */
  GPIO3_0_IRQn                 = 59,               /**< GPIO3 interrupt 0 */
  GPIO3_1_IRQn                 = 60,               /**< GPIO3 interrupt 1 */
  I3C2_IRQn                    = 61,               /**< I3C2 interrupt */
  LPI2C3_IRQn                  = 62,               /**< LPI2C3 interrupt */
  LPI2C4_IRQn                  = 63,               /**< LPI2C4 interrput */
  LPIT2_IRQn                   = 64,               /**< LPIT2 interrupt */
  LPSPI3_IRQn                  = 65,               /**< LPSPI3 interrupt */
  LPSPI4_IRQn                  = 66,               /**< LPSPI4 interrupt */
  LPTMR2_IRQn                  = 67,               /**< LPTMR2 interrupt */
  LPUART3_IRQn                 = 68,               /**< LPUART3 interrupt */
  LPUART4_IRQn                 = 69,               /**< LPUART4 interrupt */
  LPUART5_IRQn                 = 70,               /**< LPUART5 interrupt */
  LPUART6_IRQn                 = 71,               /**< LPUART6 interrupt */
  Reserved88_IRQn              = 72,               /**< Reserved interrupt 88 */
  BBNSM_IRQn                   = 73,               /**< BBNSM iterrupt */
  SYS_CTR1_IRQn                = 74,               /**< System Counter compare interrupt 0 and 1 */
  TPM3_IRQn                    = 75,               /**< TPM3 interrupt */
  TPM4_IRQn                    = 76,               /**< TPM4 interrupt */
  TPM5_IRQn                    = 77,               /**< TPM5 interrupt */
  TPM6_IRQn                    = 78,               /**< TPM6 interrupt */
  RTWDOG3_IRQn                 = 79,               /**< RTWDOG3 interrupt */
  RTWDOG4_IRQn                 = 80,               /**< RTWDOG4 interrupt */
  RTWDOG5_IRQn                 = 81,               /**< RTWDOG5 interrupt */
  TRDC_MGR_WKUP_IRQn           = 82,               /**< WAKEUPMIX TRDC transfer error interrupt */
  TMPSNS_INT_IRQn              = 83,               /**< Temperature alarm interrupt */
  BBSM_IRQn                    = 84,               /**< BBSM wakeup alarm interrupt */
  LDO_AON_ANA_IRQn             = 85,               /**< Brown out interrupt */
  USDHC1_IRQn                  = 86,               /**< USDHC1 */
  USDHC2_IRQn                  = 87,               /**< USDHC2 */
  TRDC_MGR_MEGA_IRQn           = 88,               /**< MEGAMIX TRDC transfer error interrupt */
  SFA_IRQn                     = 89,               /**< Signal Frequency Analyzer interrupt */
  LDO_AON_DIG_IRQn             = 90,               /**< Brown out interrupt */
  MECC1_IRQn                   = 91,               /**< MECC1 interrupt */
  MECC2_IRQn                   = 92,               /**< MECC2 interrupt */
  ADC1_IRQn                    = 93,               /**< ADC1 interrupt */
  DMA_ERROR_IRQn               = 94,               /**< AON Domain eDMA error interrupt */
  DMA3_CH0_IRQn                = 95,               /**< AON Domain eDMA channel 0 interrupt */
  DMA3_CH1_IRQn                = 96,               /**< AON Domain eDMA channel 1 interrupt */
  DMA3_CH2_IRQn                = 97,               /**< AON Domain eDMA channel 2 interrupt */
  DMA3_CH3_IRQn                = 98,               /**< AON Domain eDMA channel 3 interrupt */
  DMA3_CH4_IRQn                = 99,               /**< AON Domain eDMA channel 4 interrupt */
  DMA3_CH5_IRQn                = 100,              /**< AON Domain eDMA channel 5 interrupt */
  DMA3_CH6_IRQn                = 101,              /**< AON Domain eDMA channel 6 interrupt */
  DMA3_CH7_IRQn                = 102,              /**< AON Domain eDMA channel 7 interrupt */
  DMA3_CH8_IRQn                = 103,              /**< AON Domain eDMA channel 8 interrupt */
  DMA3_CH9_IRQn                = 104,              /**< AON Domain eDMA channel 9 interrupt */
  DMA3_CH10_IRQn               = 105,              /**< AON Domain eDMA channel 10 interrupt */
  DMA3_CH11_IRQn               = 106,              /**< AON Domain eDMA channel 11 interrupt */
  DMA3_CH12_IRQn               = 107,              /**< AON Domain eDMA channel 12 interrupt */
  DMA3_CH13_IRQn               = 108,              /**< AON Domain eDMA channel 13 interrupt */
  DMA3_CH14_IRQn               = 109,              /**< AON Domain eDMA channel 14 interrupt */
  DMA3_CH15_IRQn               = 110,              /**< AON Domain eDMA channel 15 interrupt */
  DMA3_CH16_IRQn               = 111,              /**< AON Domain eDMA channel 16 interrupt */
  DMA3_CH17_IRQn               = 112,              /**< AON Domain eDMA channel 17 interrupt */
  DMA3_CH18_IRQn               = 113,              /**< AON Domain eDMA channel 18 interrupt */
  DMA3_CH19_IRQn               = 114,              /**< AON Domain eDMA channel 19 interrupt */
  DMA3_CH20_IRQn               = 115,              /**< AON Domain eDMA channel 20 interrupt */
  DMA3_CH21_IRQn               = 116,              /**< AON Domain eDMA channel 21 interrupt */
  DMA3_CH22_IRQn               = 117,              /**< AON Domain eDMA channel 22 interrupt */
  DMA3_CH23_IRQn               = 118,              /**< AON Domain eDMA channel 23 interrupt */
  DMA3_CH24_IRQn               = 119,              /**< AON Domain eDMA channel 24 interrupt */
  DMA3_CH25_IRQn               = 120,              /**< AON Domain eDMA channel 25 interrupt */
  DMA3_CH26_IRQn               = 121,              /**< AON Domain eDMA channel 26 interrupt */
  DMA3_CH27_IRQn               = 122,              /**< AON Domain eDMA channel 27 interrupt */
  DMA3_CH28_IRQn               = 123,              /**< AON Domain eDMA channel 28 interrupt */
  DMA3_CH29_IRQn               = 124,              /**< AON Domain eDMA channel 29 interrupt */
  DMA3_CH30_IRQn               = 125,              /**< AON Domain eDMA channel 30 interrupt */
  DMA3_CH31_IRQn               = 126,              /**< AON Domain eDMA channel 31 interrupt */
  DMA4_ERROR_IRQn              = 127,              /**< WAKEUP Domain eDMA error interrupt */
  DMA4_CH0_CH1_CH32_CH33_IRQn  = 128,              /**< WAKEUP Domain eDMA channel 0/1/32/33 interrupt */
  DMA4_CH2_CH3_CH34_CH35_IRQn  = 129,              /**< WAKEUP Domain eDMA channel 2/3/34/35 interrupt */
  DMA4_CH4_CH5_CH36_CH37_IRQn  = 130,              /**< WAKEUP Domain eDMA channel 4/5/36/37 interrupt */
  DMA4_CH6_CH7_CH38_CH39_IRQn  = 131,              /**< WAKEUP Domain eDMA channel 6/7/38/39 interrupt */
  DMA4_CH8_CH9_CH40_CH41_IRQn  = 132,              /**< WAKEUP Domain eDMA channel 8/9/40/41 interrupt */
  DMA4_CH10_CH11_CH42_CH43_IRQn = 133,             /**< WAKEUP Domain eDMA channel 10/11/42/43 interrupt */
  DMA4_CH12_CH13_CH44_CH45_IRQn = 134,             /**< WAKEUP Domain eDMA channel 12/13/44/45 interrupt */
  DMA4_CH14_CH15_CH46_CH47_IRQn = 135,             /**< WAKEUP Domain eDMA channel 14/15/46/47 interrupt */
  DMA4_CH16_CH17_CH48_CH49_IRQn = 136,             /**< WAKEUP Domain eDMA channel 16/17/48/49 interrupt */
  DMA4_CH18_CH19_CH50_CH51_IRQn = 137,             /**< WAKEUP Domain eDMA channel 18/19/50/51 interrupt */
  DMA4_CH20_CH21_CH52_CH53_IRQn = 138,             /**< WAKEUP Domain eDMA channel 20/21/52/53 interrupt */
  DMA4_CH22_CH23_CH54_CH55_IRQn = 139,             /**< WAKEUP Domain eDMA channel 22/23/54/55 interrupt */
  DMA4_CH24_CH25_CH56_CH57_IRQn = 140,             /**< WAKEUP Domain eDMA channel 24/25/56/57 interrupt */
  DMA4_CH26_CH27_CH58_CH59_IRQn = 141,             /**< WAKEUP Domain eDMA channel 26/27/58/59 interrupt */
  DMA4_CH28_CH29_CH60_CH61_IRQn = 142,             /**< WAKEUP Domain eDMA channel 28/29/60/61 interrupt */
  DMA4_CH30_CH31_CH62_CH63_IRQn = 143,             /**< WAKEUP Domain eDMA channel 30/31/62/63 interrupt */
  XBAR1_CH0_CH1_IRQn           = 144,              /**< XBAR1 channel 0/1 interrupt */
  XBAR1_CH2_CH3_IRQn           = 145,              /**< XBAR1 channel 2/3 interrupt */
  SINC3_CH0_CH1_CH2_CH3_IRQn   = 146,              /**< SINC Filter Glue 3 channel 0/1/2/3 */
  EWM_IRQn                     = 147,              /**< EWM reset out interrupt */
  SEMC_IRQn                    = 148,              /**< SEMC interrupt */
  LPIT3_IRQn                   = 149,              /**< LPIT3 interrupt */
  LPTMR3_IRQn                  = 150,              /**< LPTMR3 interrupt */
  TMR4_IRQn                    = 151,              /**< TMR4 interrupt */
  LPI2C5_IRQn                  = 152,              /**< LPI2C5 interrupt */
  LPI2C6_IRQn                  = 153,              /**< LPI2C6 interrupt */
  SAI4_IRQn                    = 154,              /**< SAI4 interrupt */
  SPDIF_IRQn                   = 155,              /**< SPDIF interrupt */
  LPUART9_IRQn                 = 156,              /**< LPUART9 interrupt */
  LPUART10_IRQn                = 157,              /**< LPUART10 interrupt */
  LPUART11_IRQn                = 158,              /**< LPUART11 interrupt */
  LPUART12_IRQn                = 159,              /**< LPUART12 interrupt */
  INTG_BOOTROM_DEBUG_CTRL_IRQn = 160,              /**< CM33, CM7, DAP access IRQ */
  EDGELOCK_REQ1_IRQn           = 161,              /**< Edgelock reuqest 1 interrupt */
  EDGELOCK_REQ2_IRQn           = 162,              /**< Edgelock reuqest 2 interrupt */
  EDGELOCK_REQ3_IRQn           = 163,              /**< Edgelock reuqest 3 interrupt */
  TMR3_IRQn                    = 164,              /**< TMR3 interrupt */
  JTAGC_IRQn                   = 165,              /**< JTAGC SRC reset source */
  M33_SYSRESET_REQ_IRQn        = 166,              /**< CM33 SYSREQRST SRC reset source */
  M33_LOCKUP_IRQn              = 167,              /**< CM33 LOCKUP SRC reset source */
  M7_SYSRESET_REQ_IRQn         = 168,              /**< CM33 SYSREQRST SRC reset source */
  M7_LOCKUP_IRQn               = 169,              /**< CM33 LOCKUP SRC reset source */
  PWM2_FAULT_IRQn              = 170,              /**< PWM2 fault or reload error interrupt */
  PWM2_0_IRQn                  = 171,              /**< PWM2 capture 0, compare 0, or reload 0 interrupt */
  PWM2_1_IRQn                  = 172,              /**< PWM2 capture 1, compare 1, or reload 1 interrupt */
  PWM2_2_IRQn                  = 173,              /**< PWM2 capture 2, compare 2, or reload 2 interrupt */
  PWM2_3_IRQn                  = 174,              /**< PWM2 capture 3, compare 3, or reload 3 interrupt */
  PWM3_FAULT_IRQn              = 175,              /**< PWM3 fault or reload error interrupt */
  PWM3_0_IRQn                  = 176,              /**< PWM3 capture 0, compare 0, or reload 0 interrupt */
  PWM3_1_IRQn                  = 177,              /**< PWM3 capture 1, compare 1, or reload 1 interrupt */
  PWM3_2_IRQn                  = 178,              /**< PWM3 capture 2, compare 2, or reload 2 interrupt */
  PWM3_3_IRQn                  = 179,              /**< PWM3 capture 3, compare 3, or reload 3 interrupt */
  PWM4_FAULT_IRQn              = 180,              /**< PWM4 fault or reload error interrupt */
  PWM4_0_IRQn                  = 181,              /**< PWM4 capture 0, compare 0, or reload 0 interrupt */
  PWM4_1_IRQn                  = 182,              /**< PWM4 capture 1, compare 1, or reload 1 interrupt */
  PWM4_2_IRQn                  = 183,              /**< PWM4 capture 2, compare 2, or reload 2 interrupt */
  PWM4_3_IRQn                  = 184,              /**< PWM4 capture 3, compare 3, or reload 3 interrupt */
  EQDC1_IRQn                   = 185,              /**< EQDC1 interrupt */
  EQDC2_IRQn                   = 186,              /**< EQDC2 interrupt */
  EQDC3_IRQn                   = 187,              /**< EQDC3 interrupt */
  EQDC4_IRQn                   = 188,              /**< EQDC4 interrupt */
  ADC2_IRQn                    = 189,              /**< ADC2 interrupt */
  DCDC_IRQn                    = 190,              /**< DCDC brown out interrupt */
  CAN3_IRQn                    = 191,              /**< CAN3 interrupt */
  CAN3_ERROR_IRQn              = 192,              /**< CAN3 error interrupt */
  DAC_IRQn                     = 193,              /**< DAC interrupt */
  LPSPI5_IRQn                  = 194,              /**< LPSPI5 interrupt */
  LPSPI6_IRQn                  = 195,              /**< LPSPI6 interrupt */
  LPUART7_IRQn                 = 196,              /**< LPUART7 interrupt */
  LPUART8_IRQn                 = 197,              /**< LPUART8 interrupt */
  SAI2_IRQn                    = 198,              /**< SAI2 interrupt */
  SAI3_IRQn                    = 199,              /**< SAI3 interrupt */
  ACMP1_IRQn                   = 200,              /**< CMP1 interrupt */
  ACMP2_IRQn                   = 201,              /**< CMP2 interrupt */
  ACMP3_IRQn                   = 202,              /**< CMP3 interrupt */
  ACMP4_IRQn                   = 203,              /**< CMP4 interrupt */
  CM7_PS_IRQn                  = 204,              /**< M7 PS Tag/Data Parity Error */
  CM7_MCM_IRQn                 = 205,              /**< M7 MCM interrupt */
  CM33_MCM_IRQn                = 206,              /**< M33 MCM interrupt */
  ECAT_INT_IRQn                = 207,              /**< EtherCAT interrupt */
  SAFETY_CLK_MON_IRQn          = 208,              /**< Safety clock monitor interrupt */
  GPT1_IRQn                    = 209,              /**< GPT1 interrupt */
  GPT2_IRQn                    = 210,              /**< GPT2 interrupt */
  KPP_IRQn                     = 211,              /**< KPP interrupt */
  USBPHY1_IRQn                 = 212,              /**< USBPHY1 interrupt */
  USBPHY2_IRQn                 = 213,              /**< USBPHY2 interrupt */
  USB_OTG2_IRQn                = 214,              /**< USBOTG2 interrupt */
  USB_OTG1_IRQn                = 215,              /**< USBOTG1 interrupt */
  FLEXSPI_SLV_IRQn             = 216,              /**< FLEXSPI follower interrupt */
  NETC_IRQn                    = 217,              /**< NETC interrupt */
  MSGINTR1_IRQn                = 218,              /**< MSGINTR1 interrupt */
  MSGINTR2_IRQn                = 219,              /**< MSGINTR2 interrupt */
  MSGINTR3_IRQn                = 220,              /**< MSGINTR3 interrupt */
  MSGINTR4_IRQn                = 221,              /**< MSGINTR4 interrupt */
  MSGINTR5_IRQn                = 222,              /**< MSGINTR5 interrupt */
  MSGINTR6_IRQn                = 223,              /**< MSGINTR6 interrupt */
  SINC1_CH0_IRQn               = 224,              /**< SINC Filter Glue 1 channel 0 */
  SINC1_CH1_IRQn               = 225,              /**< SINC Filter Glue 1 channel 1 */
  SINC1_CH2_IRQn               = 226,              /**< SINC Filter Glue 1 channel 2 */
  SINC1_CH3_IRQn               = 227,              /**< SINC Filter Glue 1 channel 3 */
  SINC2_CH0_IRQn               = 228,              /**< SINC Filter Glue 2 channel 0 */
  SINC2_CH1_IRQn               = 229,              /**< SINC Filter Glue 2 channel 1 */
  SINC2_CH2_IRQn               = 230,              /**< SINC Filter Glue 2 channel 2 */
  SINC2_CH3_IRQn               = 231,              /**< SINC Filter Glue 2 channel 3 */
  GPIO4_IRQn                   = 232,              /**< GPIO4 interrupt */
  TMR2_IRQn                    = 233,              /**< TMR2 interrupt */
  GPIO5_IRQn                   = 234,              /**< GPIO5 interrupt */
  ASRC_IRQn                    = 235,              /**< ASRC interrupt */
  GPIO6_IRQn                   = 236,              /**< GPIO6 interrupt */
  DBG_TRACE_IRQn               = 237,              /**< JTAGSW DAP MDM-AP SRC reset source */
  ECAT_RST_OUT_IRQn            = 238               /**< ECAT reset out interrupt */
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
#include "system_MIMXRT1189_cm7.h"     /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#define MIMXRT1189_cm7_SERIES
/* CPU specific feature definitions */
#include "MIMXRT1189_cm7_features.h"

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC1 base address */
#define ADC1_BASE                                (0x42600000u)
/** Peripheral ADC1 base pointer */
#define ADC1                                     ((ADC_Type *)ADC1_BASE)
/** Peripheral ADC2 base address */
#define ADC2_BASE                                (0x42E00000u)
/** Peripheral ADC2 base pointer */
#define ADC2                                     ((ADC_Type *)ADC2_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { 0u, ADC1_BASE, ADC2_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { (ADC_Type *)0u, ADC1, ADC2 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { NotAvail_IRQn, ADC1_IRQn, ADC2_IRQn }

/* ANADIG - Peripheral instance base addresses */
/** Peripheral ANADIG_SLOTS base address */
#define ANADIG_SLOTS_BASE                        (0x44480000u)
/** Peripheral ANADIG_SLOTS base pointer */
#define ANADIG_SLOTS                             ((ANADIG_Type *)ANADIG_SLOTS_BASE)
/** Array initializer of ANADIG peripheral base addresses */
#define ANADIG_BASE_ADDRS                        { ANADIG_SLOTS_BASE }
/** Array initializer of ANADIG peripheral base pointers */
#define ANADIG_BASE_PTRS                         { ANADIG_SLOTS }

/* ANADIG_LDO_BBSM - Peripheral instance base addresses */
/** Peripheral ANADIG_LDO_BBSM base address */
#define ANADIG_LDO_BBSM_BASE                     (0x44480000u)
/** Peripheral ANADIG_LDO_BBSM base pointer */
#define ANADIG_LDO_BBSM                          ((ANADIG_LDO_BBSM_Type *)ANADIG_LDO_BBSM_BASE)
/** Array initializer of ANADIG_LDO_BBSM peripheral base addresses */
#define ANADIG_LDO_BBSM_BASE_ADDRS               { ANADIG_LDO_BBSM_BASE }
/** Array initializer of ANADIG_LDO_BBSM peripheral base pointers */
#define ANADIG_LDO_BBSM_BASE_PTRS                { ANADIG_LDO_BBSM }

/* ANADIG_MISC - Peripheral instance base addresses */
/** Peripheral ANADIG_MISC base address */
#define ANADIG_MISC_BASE                         (0x44480000u)
/** Peripheral ANADIG_MISC base pointer */
#define ANADIG_MISC                              ((ANADIG_MISC_Type *)ANADIG_MISC_BASE)
/** Array initializer of ANADIG_MISC peripheral base addresses */
#define ANADIG_MISC_BASE_ADDRS                   { ANADIG_MISC_BASE }
/** Array initializer of ANADIG_MISC peripheral base pointers */
#define ANADIG_MISC_BASE_PTRS                    { ANADIG_MISC }

/* ANADIG_OSC - Peripheral instance base addresses */
/** Peripheral ANADIG_OSC base address */
#define ANADIG_OSC_BASE                          (0x44480000u)
/** Peripheral ANADIG_OSC base pointer */
#define ANADIG_OSC                               ((ANADIG_OSC_Type *)ANADIG_OSC_BASE)
/** Array initializer of ANADIG_OSC peripheral base addresses */
#define ANADIG_OSC_BASE_ADDRS                    { ANADIG_OSC_BASE }
/** Array initializer of ANADIG_OSC peripheral base pointers */
#define ANADIG_OSC_BASE_PTRS                     { ANADIG_OSC }

/* ANADIG_PLL - Peripheral instance base addresses */
/** Peripheral ANADIG_PLL base address */
#define ANADIG_PLL_BASE                          (0x44480000u)
/** Peripheral ANADIG_PLL base pointer */
#define ANADIG_PLL                               ((ANADIG_PLL_Type *)ANADIG_PLL_BASE)
/** Array initializer of ANADIG_PLL peripheral base addresses */
#define ANADIG_PLL_BASE_ADDRS                    { ANADIG_PLL_BASE }
/** Array initializer of ANADIG_PLL peripheral base pointers */
#define ANADIG_PLL_BASE_PTRS                     { ANADIG_PLL }

/* ANADIG_PMU - Peripheral instance base addresses */
/** Peripheral ANADIG_PMU base address */
#define ANADIG_PMU_BASE                          (0x44480000u)
/** Peripheral ANADIG_PMU base pointer */
#define ANADIG_PMU                               ((ANADIG_PMU_Type *)ANADIG_PMU_BASE)
/** Array initializer of ANADIG_PMU peripheral base addresses */
#define ANADIG_PMU_BASE_ADDRS                    { ANADIG_PMU_BASE }
/** Array initializer of ANADIG_PMU peripheral base pointers */
#define ANADIG_PMU_BASE_PTRS                     { ANADIG_PMU }

/* ANADIG_TEMPSENSOR - Peripheral instance base addresses */
/** Peripheral ANADIG_TEMPSENSOR base address */
#define ANADIG_TEMPSENSOR_BASE                   (0x44480000u)
/** Peripheral ANADIG_TEMPSENSOR base pointer */
#define ANADIG_TEMPSENSOR                        ((ANADIG_TEMPSENSOR_Type *)ANADIG_TEMPSENSOR_BASE)
/** Array initializer of ANADIG_TEMPSENSOR peripheral base addresses */
#define ANADIG_TEMPSENSOR_BASE_ADDRS             { ANADIG_TEMPSENSOR_BASE }
/** Array initializer of ANADIG_TEMPSENSOR peripheral base pointers */
#define ANADIG_TEMPSENSOR_BASE_PTRS              { ANADIG_TEMPSENSOR }

/* AOI - Peripheral instance base addresses */
/** Peripheral AOI1 base address */
#define AOI1_BASE                                (0x42780000u)
/** Peripheral AOI1 base pointer */
#define AOI1                                     ((AOI_Type *)AOI1_BASE)
/** Peripheral AOI2 base address */
#define AOI2_BASE                                (0x42790000u)
/** Peripheral AOI2 base pointer */
#define AOI2                                     ((AOI_Type *)AOI2_BASE)
/** Peripheral AOI3 base address */
#define AOI3_BASE                                (0x427E0000u)
/** Peripheral AOI3 base pointer */
#define AOI3                                     ((AOI_Type *)AOI3_BASE)
/** Peripheral AOI4 base address */
#define AOI4_BASE                                (0x427F0000u)
/** Peripheral AOI4 base pointer */
#define AOI4                                     ((AOI_Type *)AOI4_BASE)
/** Array initializer of AOI peripheral base addresses */
#define AOI_BASE_ADDRS                           { 0u, AOI1_BASE, AOI2_BASE, AOI3_BASE, AOI4_BASE }
/** Array initializer of AOI peripheral base pointers */
#define AOI_BASE_PTRS                            { (AOI_Type *)0u, AOI1, AOI2, AOI3, AOI4 }

/* ASRC - Peripheral instance base addresses */
/** Peripheral ASRC base address */
#define ASRC_BASE                                (0x429A0000u)
/** Peripheral ASRC base pointer */
#define ASRC                                     ((ASRC_Type *)ASRC_BASE)
/** Array initializer of ASRC peripheral base addresses */
#define ASRC_BASE_ADDRS                          { ASRC_BASE }
/** Array initializer of ASRC peripheral base pointers */
#define ASRC_BASE_PTRS                           { ASRC }
/** Interrupt vectors for the ASRC peripheral type */
#define ASRC_IRQS                                { ASRC_IRQn }

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
/** Interrupt vectors for the BBNSM peripheral type */
#define BBNSM_IRQS                               { BBNSM_IRQn }

/* BLK_CTRL_BBSMMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_BBSMMIX base address */
#define BLK_CTRL_BBSMMIX_BASE                    (0x44410000u)
/** Peripheral BLK_CTRL_BBSMMIX base pointer */
#define BLK_CTRL_BBSMMIX                         ((BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BASE)
/** Array initializer of BLK_CTRL_BBSMMIX peripheral base addresses */
#define BLK_CTRL_BBSMMIX_BASE_ADDRS              { BLK_CTRL_BBSMMIX_BASE }
/** Array initializer of BLK_CTRL_BBSMMIX peripheral base pointers */
#define BLK_CTRL_BBSMMIX_BASE_PTRS               { BLK_CTRL_BBSMMIX }

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
/** Peripheral CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM base address */
#define CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE (0x44401000u)
/** Peripheral CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM base pointer */
#define CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM      ((CACHE_ECC_MCM_Type *)CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE)
/** Array initializer of CACHE_ECC_MCM peripheral base addresses */
#define CACHE_ECC_MCM_BASE_ADDRS                 { CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE }
/** Array initializer of CACHE_ECC_MCM peripheral base pointers */
#define CACHE_ECC_MCM_BASE_PTRS                  { CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM }

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
#define CAN3_BASE                                (0x445B0000u)
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
/** Peripheral CCM base address */
#define CCM_BASE                                 (0x44450000u)
/** Peripheral CCM base pointer */
#define CCM                                      ((CCM_Type *)CCM_BASE)
/** Array initializer of CCM peripheral base addresses */
#define CCM_BASE_ADDRS                           { CCM_BASE }
/** Array initializer of CCM peripheral base pointers */
#define CCM_BASE_PTRS                            { CCM }

/* CMP - Peripheral instance base addresses */
/** Peripheral CMP1 base address */
#define CMP1_BASE                                (0x42DC0000u)
/** Peripheral CMP1 base pointer */
#define CMP1                                     ((CMP_Type *)CMP1_BASE)
/** Peripheral CMP2 base address */
#define CMP2_BASE                                (0x42DD0000u)
/** Peripheral CMP2 base pointer */
#define CMP2                                     ((CMP_Type *)CMP2_BASE)
/** Peripheral CMP3 base address */
#define CMP3_BASE                                (0x42DE0000u)
/** Peripheral CMP3 base pointer */
#define CMP3                                     ((CMP_Type *)CMP3_BASE)
/** Peripheral CMP4 base address */
#define CMP4_BASE                                (0x42DF0000u)
/** Peripheral CMP4 base pointer */
#define CMP4                                     ((CMP_Type *)CMP4_BASE)
/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           { 0u, CMP1_BASE, CMP2_BASE, CMP3_BASE, CMP4_BASE }
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            { (CMP_Type *)0u, CMP1, CMP2, CMP3, CMP4 }
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { NotAvail_IRQn, ACMP1_IRQn, ACMP2_IRQn, ACMP3_IRQn, ACMP4_IRQn }

/* DAC - Peripheral instance base addresses */
/** Peripheral DAC base address */
#define DAC_BASE                                 (0x42E20000u)
/** Peripheral DAC base pointer */
#define DAC                                      ((DAC_Type *)DAC_BASE)
/** Array initializer of DAC peripheral base addresses */
#define DAC_BASE_ADDRS                           { DAC_BASE }
/** Array initializer of DAC peripheral base pointers */
#define DAC_BASE_PTRS                            { DAC }
/** Interrupt vectors for the DAC peripheral type */
#define DAC_IRQS                                 { DAC_IRQn }

/* DCDC - Peripheral instance base addresses */
/** Peripheral DCDC base address */
#define DCDC_BASE                                (0x44520000u)
/** Peripheral DCDC base pointer */
#define DCDC                                     ((DCDC_Type *)DCDC_BASE)
/** Array initializer of DCDC peripheral base addresses */
#define DCDC_BASE_ADDRS                          { DCDC_BASE }
/** Array initializer of DCDC peripheral base pointers */
#define DCDC_BASE_PTRS                           { DCDC }
/** Interrupt vectors for the DCDC peripheral type */
#define DCDC_IRQS                                { DCDC_IRQn }

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
#define DMA_IRQS                                 { { DMA3_CH0_IRQn, DMA3_CH1_IRQn, DMA3_CH2_IRQn, DMA3_CH3_IRQn, DMA3_CH4_IRQn, DMA3_CH5_IRQn, DMA3_CH6_IRQn, DMA3_CH7_IRQn, DMA3_CH8_IRQn, DMA3_CH9_IRQn, DMA3_CH10_IRQn, DMA3_CH11_IRQn, DMA3_CH12_IRQn, DMA3_CH13_IRQn, DMA3_CH14_IRQn, DMA3_CH15_IRQn, DMA3_CH16_IRQn, DMA3_CH17_IRQn, DMA3_CH18_IRQn, DMA3_CH19_IRQn, DMA3_CH20_IRQn, DMA3_CH21_IRQn, DMA3_CH22_IRQn, DMA3_CH23_IRQn, DMA3_CH24_IRQn, DMA3_CH25_IRQn, DMA3_CH26_IRQn, DMA3_CH27_IRQn, DMA3_CH28_IRQn, DMA3_CH29_IRQn, DMA3_CH30_IRQn, DMA3_CH31_IRQn } }
#define DMA_ERROR_IRQS                           { { DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn } }

/* DMA4 - Peripheral instance base addresses */
/** Peripheral DMA4 base address */
#define DMA4_BASE                                (0x42000000u)
/** Peripheral DMA4 base pointer */
#define DMA4                                     ((DMA4_Type *)DMA4_BASE)
/** Array initializer of DMA4 peripheral base addresses */
#define DMA4_BASE_ADDRS                          { DMA4_BASE }
/** Array initializer of DMA4 peripheral base pointers */
#define DMA4_BASE_PTRS                           { DMA4 }
/** Interrupt vectors for the DMA4 peripheral type */
#define DMA4_IRQS                                { { DMA4_CH0_CH1_CH32_CH33_IRQn, DMA4_CH0_CH1_CH32_CH33_IRQn, DMA4_CH2_CH3_CH34_CH35_IRQn, DMA4_CH2_CH3_CH34_CH35_IRQn, DMA4_CH4_CH5_CH36_CH37_IRQn, DMA4_CH4_CH5_CH36_CH37_IRQn, DMA4_CH6_CH7_CH38_CH39_IRQn, DMA4_CH6_CH7_CH38_CH39_IRQn, DMA4_CH8_CH9_CH40_CH41_IRQn, DMA4_CH8_CH9_CH40_CH41_IRQn, DMA4_CH10_CH11_CH42_CH43_IRQn, DMA4_CH10_CH11_CH42_CH43_IRQn, DMA4_CH12_CH13_CH44_CH45_IRQn, DMA4_CH12_CH13_CH44_CH45_IRQn, DMA4_CH14_CH15_CH46_CH47_IRQn, DMA4_CH14_CH15_CH46_CH47_IRQn, DMA4_CH16_CH17_CH48_CH49_IRQn, DMA4_CH16_CH17_CH48_CH49_IRQn, DMA4_CH18_CH19_CH50_CH51_IRQn, DMA4_CH18_CH19_CH50_CH51_IRQn, DMA4_CH20_CH21_CH52_CH53_IRQn, DMA4_CH20_CH21_CH52_CH53_IRQn, DMA4_CH22_CH23_CH54_CH55_IRQn, DMA4_CH22_CH23_CH54_CH55_IRQn, DMA4_CH24_CH25_CH56_CH57_IRQn, DMA4_CH24_CH25_CH56_CH57_IRQn, DMA4_CH26_CH27_CH58_CH59_IRQn, DMA4_CH26_CH27_CH58_CH59_IRQn, DMA4_CH28_CH29_CH60_CH61_IRQn, DMA4_CH28_CH29_CH60_CH61_IRQn, DMA4_CH30_CH31_CH62_CH63_IRQn, DMA4_CH30_CH31_CH62_CH63_IRQn, DMA4_CH0_CH1_CH32_CH33_IRQn, DMA4_CH0_CH1_CH32_CH33_IRQn, DMA4_CH2_CH3_CH34_CH35_IRQn, DMA4_CH2_CH3_CH34_CH35_IRQn, DMA4_CH4_CH5_CH36_CH37_IRQn, DMA4_CH4_CH5_CH36_CH37_IRQn, DMA4_CH6_CH7_CH38_CH39_IRQn, DMA4_CH6_CH7_CH38_CH39_IRQn, DMA4_CH8_CH9_CH40_CH41_IRQn, DMA4_CH8_CH9_CH40_CH41_IRQn, DMA4_CH10_CH11_CH42_CH43_IRQn, DMA4_CH10_CH11_CH42_CH43_IRQn, DMA4_CH12_CH13_CH44_CH45_IRQn, DMA4_CH12_CH13_CH44_CH45_IRQn, DMA4_CH14_CH15_CH46_CH47_IRQn, DMA4_CH14_CH15_CH46_CH47_IRQn, DMA4_CH16_CH17_CH48_CH49_IRQn, DMA4_CH16_CH17_CH48_CH49_IRQn, DMA4_CH18_CH19_CH50_CH51_IRQn, DMA4_CH18_CH19_CH50_CH51_IRQn, DMA4_CH20_CH21_CH52_CH53_IRQn, DMA4_CH20_CH21_CH52_CH53_IRQn, DMA4_CH22_CH23_CH54_CH55_IRQn, DMA4_CH22_CH23_CH54_CH55_IRQn, DMA4_CH24_CH25_CH56_CH57_IRQn, DMA4_CH24_CH25_CH56_CH57_IRQn, DMA4_CH26_CH27_CH58_CH59_IRQn, DMA4_CH26_CH27_CH58_CH59_IRQn, DMA4_CH28_CH29_CH60_CH61_IRQn, DMA4_CH28_CH29_CH60_CH61_IRQn, DMA4_CH30_CH31_CH62_CH63_IRQn, DMA4_CH30_CH31_CH62_CH63_IRQn } }
#define DMA4_ERROR_IRQS                          { { DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn } }

/* ECAT - Peripheral instance base addresses */
/** Peripheral ECAT base address */
#define ECAT_BASE                                (0x42A80000u)
/** Peripheral ECAT base pointer */
#define ECAT                                     ((ECAT_Type *)ECAT_BASE)
/** Array initializer of ECAT peripheral base addresses */
#define ECAT_BASE_ADDRS                          { ECAT_BASE }
/** Array initializer of ECAT peripheral base pointers */
#define ECAT_BASE_PTRS                           { ECAT }

/* EIM - Peripheral instance base addresses */
/** Peripheral EIM base address */
#define EIM_BASE                                 (0x4B860000u)
/** Peripheral EIM base pointer */
#define EIM                                      ((EIM_Type *)EIM_BASE)
/** Array initializer of EIM peripheral base addresses */
#define EIM_BASE_ADDRS                           { EIM_BASE }
/** Array initializer of EIM peripheral base pointers */
#define EIM_BASE_PTRS                            { EIM }

/* ENETC_GLOBAL - Peripheral instance base addresses */
/** Peripheral EMDIO_GLOBAL base address */
#define EMDIO_GLOBAL_BASE                        (0x60BB0000u)
/** Peripheral EMDIO_GLOBAL base pointer */
#define EMDIO_GLOBAL                             ((ENETC_GLOBAL_Type *)EMDIO_GLOBAL_BASE)
/** Peripheral ENETC0_GLOBAL base address */
#define ENETC0_GLOBAL_BASE                       (0x60B20000u)
/** Peripheral ENETC0_GLOBAL base pointer */
#define ENETC0_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC0_GLOBAL_BASE)
/** Peripheral ENETC1_GLOBAL base address */
#define ENETC1_GLOBAL_BASE                       (0x60B60000u)
/** Peripheral ENETC1_GLOBAL base pointer */
#define ENETC1_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC1_GLOBAL_BASE)
/** Peripheral SW0_GLOBAL base address */
#define SW0_GLOBAL_BASE                          (0x60A80000u)
/** Peripheral SW0_GLOBAL base pointer */
#define SW0_GLOBAL                               ((ENETC_GLOBAL_Type *)SW0_GLOBAL_BASE)
/** Peripheral TMR0_GLOBAL base address */
#define TMR0_GLOBAL_BASE                         (0x60B90000u)
/** Peripheral TMR0_GLOBAL base pointer */
#define TMR0_GLOBAL                              ((ENETC_GLOBAL_Type *)TMR0_GLOBAL_BASE)
/** Array initializer of ENETC_GLOBAL peripheral base addresses */
#define ENETC_GLOBAL_BASE_ADDRS                  { EMDIO_GLOBAL_BASE, ENETC0_GLOBAL_BASE, ENETC1_GLOBAL_BASE, SW0_GLOBAL_BASE, TMR0_GLOBAL_BASE }
/** Array initializer of ENETC_GLOBAL peripheral base pointers */
#define ENETC_GLOBAL_BASE_PTRS                   { EMDIO_GLOBAL, ENETC0_GLOBAL, ENETC1_GLOBAL, SW0_GLOBAL, TMR0_GLOBAL }

/* ENETC_PCI_TYPE0 - Peripheral instance base addresses */
/** Peripheral NETC_F0_PCI_HDR_TYPE0 base address */
#define NETC_F0_PCI_HDR_TYPE0_BASE               (0x60000000u)
/** Peripheral NETC_F0_PCI_HDR_TYPE0 base pointer */
#define NETC_F0_PCI_HDR_TYPE0                    ((ENETC_PCI_TYPE0_Type *)NETC_F0_PCI_HDR_TYPE0_BASE)
/** Peripheral NETC_F1_PCI_HDR_TYPE0 base address */
#define NETC_F1_PCI_HDR_TYPE0_BASE               (0x60001000u)
/** Peripheral NETC_F1_PCI_HDR_TYPE0 base pointer */
#define NETC_F1_PCI_HDR_TYPE0                    ((ENETC_PCI_TYPE0_Type *)NETC_F1_PCI_HDR_TYPE0_BASE)
/** Peripheral NETC_F2_PCI_HDR_TYPE0 base address */
#define NETC_F2_PCI_HDR_TYPE0_BASE               (0x60002000u)
/** Peripheral NETC_F2_PCI_HDR_TYPE0 base pointer */
#define NETC_F2_PCI_HDR_TYPE0                    ((ENETC_PCI_TYPE0_Type *)NETC_F2_PCI_HDR_TYPE0_BASE)
/** Peripheral NETC_F3_PCI_HDR_TYPE0 base address */
#define NETC_F3_PCI_HDR_TYPE0_BASE               (0x60003000u)
/** Peripheral NETC_F3_PCI_HDR_TYPE0 base pointer */
#define NETC_F3_PCI_HDR_TYPE0                    ((ENETC_PCI_TYPE0_Type *)NETC_F3_PCI_HDR_TYPE0_BASE)
/** Peripheral NETC_F4_PCI_HDR_TYPE0 base address */
#define NETC_F4_PCI_HDR_TYPE0_BASE               (0x60004000u)
/** Peripheral NETC_F4_PCI_HDR_TYPE0 base pointer */
#define NETC_F4_PCI_HDR_TYPE0                    ((ENETC_PCI_TYPE0_Type *)NETC_F4_PCI_HDR_TYPE0_BASE)
/** Array initializer of ENETC_PCI_TYPE0 peripheral base addresses */
#define ENETC_PCI_TYPE0_BASE_ADDRS               { NETC_F0_PCI_HDR_TYPE0_BASE, NETC_F1_PCI_HDR_TYPE0_BASE, NETC_F2_PCI_HDR_TYPE0_BASE, NETC_F3_PCI_HDR_TYPE0_BASE, NETC_F4_PCI_HDR_TYPE0_BASE }
/** Array initializer of ENETC_PCI_TYPE0 peripheral base pointers */
#define ENETC_PCI_TYPE0_BASE_PTRS                { NETC_F0_PCI_HDR_TYPE0, NETC_F1_PCI_HDR_TYPE0, NETC_F2_PCI_HDR_TYPE0, NETC_F3_PCI_HDR_TYPE0, NETC_F4_PCI_HDR_TYPE0 }

/* ENETC_PF_EMDIO - Peripheral instance base addresses */
/** Peripheral EMDIO_BASE base address */
#define EMDIO_BASE_BASE                          (0x60BA0000u)
/** Peripheral EMDIO_BASE base pointer */
#define EMDIO_BASE                               ((ENETC_PF_EMDIO_Type *)EMDIO_BASE_BASE)
/** Array initializer of ENETC_PF_EMDIO peripheral base addresses */
#define ENETC_PF_EMDIO_BASE_ADDRS                { EMDIO_BASE_BASE }
/** Array initializer of ENETC_PF_EMDIO peripheral base pointers */
#define ENETC_PF_EMDIO_BASE_PTRS                 { EMDIO_BASE }

/* ENETC_PF_TMR - Peripheral instance base addresses */
/** Peripheral TMR0_BASE base address */
#define TMR0_BASE_BASE                           (0x60B80000u)
/** Peripheral TMR0_BASE base pointer */
#define TMR0_BASE                                ((ENETC_PF_TMR_Type *)TMR0_BASE_BASE)
/** Array initializer of ENETC_PF_TMR peripheral base addresses */
#define ENETC_PF_TMR_BASE_ADDRS                  { TMR0_BASE_BASE }
/** Array initializer of ENETC_PF_TMR peripheral base pointers */
#define ENETC_PF_TMR_BASE_PTRS                   { TMR0_BASE }

/* ENETC_SI - Peripheral instance base addresses */
/** Peripheral ENETC0_SI0 base address */
#define ENETC0_SI0_BASE                          (0x60B00000u)
/** Peripheral ENETC0_SI0 base pointer */
#define ENETC0_SI0                               ((ENETC_SI_Type *)ENETC0_SI0_BASE)
/** Peripheral ENETC1_SI0 base address */
#define ENETC1_SI0_BASE                          (0x60B40000u)
/** Peripheral ENETC1_SI0 base pointer */
#define ENETC1_SI0                               ((ENETC_SI_Type *)ENETC1_SI0_BASE)
/** Peripheral ENETC1_SI1 base address */
#define ENETC1_SI1_BASE                          (0x60C10000u)
/** Peripheral ENETC1_SI1 base pointer */
#define ENETC1_SI1                               ((ENETC_SI_Type *)ENETC1_SI1_BASE)
/** Array initializer of ENETC_SI peripheral base addresses */
#define ENETC_SI_BASE_ADDRS                      { ENETC0_SI0_BASE, ENETC1_SI0_BASE, ENETC1_SI1_BASE }
/** Array initializer of ENETC_SI peripheral base pointers */
#define ENETC_SI_BASE_PTRS                       { ENETC0_SI0, ENETC1_SI0, ENETC1_SI1 }

/* ENETC_VF_PCI_TYPE0 - Peripheral instance base addresses */
/** Peripheral NETC_VF1_PCI_HDR_TYPE0 base address */
#define NETC_VF1_PCI_HDR_TYPE0_BASE              (0x60100000u)
/** Peripheral NETC_VF1_PCI_HDR_TYPE0 base pointer */
#define NETC_VF1_PCI_HDR_TYPE0                   ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF1_PCI_HDR_TYPE0_BASE)
/** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base addresses */
#define ENETC_VF_PCI_TYPE0_BASE_ADDRS            { NETC_VF1_PCI_HDR_TYPE0_BASE }
/** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base pointers */
#define ENETC_VF_PCI_TYPE0_BASE_PTRS             { NETC_VF1_PCI_HDR_TYPE0 }

/* EQDC - Peripheral instance base addresses */
/** Peripheral EQDC1 base address */
#define EQDC1_BASE                               (0x42710000u)
/** Peripheral EQDC1 base pointer */
#define EQDC1                                    ((EQDC_Type *)EQDC1_BASE)
/** Peripheral EQDC2 base address */
#define EQDC2_BASE                               (0x42720000u)
/** Peripheral EQDC2 base pointer */
#define EQDC2                                    ((EQDC_Type *)EQDC2_BASE)
/** Peripheral EQDC3 base address */
#define EQDC3_BASE                               (0x42730000u)
/** Peripheral EQDC3 base pointer */
#define EQDC3                                    ((EQDC_Type *)EQDC3_BASE)
/** Peripheral EQDC4 base address */
#define EQDC4_BASE                               (0x42740000u)
/** Peripheral EQDC4 base pointer */
#define EQDC4                                    ((EQDC_Type *)EQDC4_BASE)
/** Array initializer of EQDC peripheral base addresses */
#define EQDC_BASE_ADDRS                          { 0u, EQDC1_BASE, EQDC2_BASE, EQDC3_BASE, EQDC4_BASE }
/** Array initializer of EQDC peripheral base pointers */
#define EQDC_BASE_PTRS                           { (EQDC_Type *)0u, EQDC1, EQDC2, EQDC3, EQDC4 }
/** Interrupt vectors for the EQDC peripheral type */
#define EQDC_COMPARE_IRQS                        { NotAvail_IRQn, EQDC1_IRQn, EQDC2_IRQn, EQDC3_IRQn, EQDC4_IRQn }
#define EQDC_HOME_IRQS                           { NotAvail_IRQn, EQDC1_IRQn, EQDC2_IRQn, EQDC3_IRQn, EQDC4_IRQn }
#define EQDC_WDOG_IRQS                           { NotAvail_IRQn, EQDC1_IRQn, EQDC2_IRQn, EQDC3_IRQn, EQDC4_IRQn }
#define EQDC_INDEX_IRQS                          { NotAvail_IRQn, EQDC1_IRQn, EQDC2_IRQn, EQDC3_IRQn, EQDC4_IRQn }
#define EQDC_INPUT_SWITCH_IRQS                   { NotAvail_IRQn, EQDC1_IRQn, EQDC2_IRQn, EQDC3_IRQn, EQDC4_IRQn }

/* ERM - Peripheral instance base addresses */
/** Peripheral ERM base address */
#define ERM_BASE                                 (0x4B864000u)
/** Peripheral ERM base pointer */
#define ERM                                      ((ERM_Type *)ERM_BASE)
/** Array initializer of ERM peripheral base addresses */
#define ERM_BASE_ADDRS                           { ERM_BASE }
/** Array initializer of ERM peripheral base pointers */
#define ERM_BASE_PTRS                            { ERM }

/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base address */
#define EWM_BASE                                 (0x427B0000u)
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
#define FLEXIO1_BASE                             (0x425C0000u)
/** Peripheral FLEXIO1 base pointer */
#define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
/** Peripheral FLEXIO2 base address */
#define FLEXIO2_BASE                             (0x425D0000u)
/** Peripheral FLEXIO2 base pointer */
#define FLEXIO2                                  ((FLEXIO_Type *)FLEXIO2_BASE)
/** Array initializer of FLEXIO peripheral base addresses */
#define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE, FLEXIO2_BASE }
/** Array initializer of FLEXIO peripheral base pointers */
#define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1, FLEXIO2 }
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { NotAvail_IRQn, FLEXIO1_IRQn, FLEXIO2_IRQn }

/* FLEXSPI - Peripheral instance base addresses */
/** Peripheral FLEXSPI1 base address */
#define FLEXSPI1_BASE                            (0x425E0000u)
/** Peripheral FLEXSPI1 base pointer */
#define FLEXSPI1                                 ((FLEXSPI_Type *)FLEXSPI1_BASE)
/** Peripheral FLEXSPI2 base address */
#define FLEXSPI2_BASE                            (0x445E0000u)
/** Peripheral FLEXSPI2 base pointer */
#define FLEXSPI2                                 ((FLEXSPI_Type *)FLEXSPI2_BASE)
/** Array initializer of FLEXSPI peripheral base addresses */
#define FLEXSPI_BASE_ADDRS                       { 0u, FLEXSPI1_BASE, FLEXSPI2_BASE }
/** Array initializer of FLEXSPI peripheral base pointers */
#define FLEXSPI_BASE_PTRS                        { (FLEXSPI_Type *)0u, FLEXSPI1, FLEXSPI2 }
/** Interrupt vectors for the FLEXSPI peripheral type */
#define FLEXSPI_IRQS                             { NotAvail_IRQn, FLEXSPI1_IRQn, FLEXSPI2_IRQn }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (2)
/* FlexSPI AMBA base address array. */
#define FlexSPI_AMBA_BASE_ARRAY                  { {0u, 0u}, {0x28000000u, 0x2000000u}, {0x4000000u, 0x22000000u} }
/* FlexSPI AMBA end address array. */
#define FlexSPI_AMBA_END_ARRAY                   { {0u, 0u}, {0x2FFFFFFFu, 0x3FFFFFFu}, {0x7FFFFFFu, 0x23FFFFFFu} }
/* FlexSPI1 AMBA address. */
#define FlexSPI1_AMBA_BASE                       (0x28000000u)
/* FlexSPI1 ASFM address. */
#define FlexSPI1_ASFM_BASE                       (0x28000000u)
/* Base Address of AHB address space mapped to IP RX FIFO. */
#define FlexSPI1_ARDF_BASE                       (0x47420000u)
/* Base Address of AHB address space mapped to IP TX FIFO. */
#define FlexSPI1_ATDF_BASE                       (0x47430000u)
/* FlexSPI2 AMBA address. */
#define FlexSPI2_AMBA_BASE                       (0x4000000u)
/* FlexSPI2 ASFM address. */
#define FlexSPI2_ASFM_BASE                       (0x4000000u)
/* Base Address of AHB address space mapped to IP RX FIFO. */
#define FlexSPI2_ARDF_BASE                       (0x4DE00000u)
/* Base Address of AHB address space mapped to IP TX FIFO. */
#define FlexSPI2_ATDF_BASE                       (0x4DE10000u)


/* FLEXSPI_SLV - Peripheral instance base addresses */
/** Peripheral FLEXSPI_SLV base address */
#define FLEXSPI_SLV_BASE                         (0x42900000u)
/** Peripheral FLEXSPI_SLV base pointer */
#define FLEXSPI_SLV                              ((FLEXSPI_SLV_Type *)FLEXSPI_SLV_BASE)
/** Array initializer of FLEXSPI_SLV peripheral base addresses */
#define FLEXSPI_SLV_BASE_ADDRS                   { FLEXSPI_SLV_BASE }
/** Array initializer of FLEXSPI_SLV peripheral base pointers */
#define FLEXSPI_SLV_BASE_PTRS                    { FLEXSPI_SLV }

/* GPC_CPU_CTRL - Peripheral instance base addresses */
/** Peripheral GPC_CPU_CTRL base address */
#define GPC_CPU_CTRL_BASE                        (0x44470000u)
/** Peripheral GPC_CPU_CTRL base pointer */
#define GPC_CPU_CTRL                             ((GPC_CPU_CTRL_Type *)GPC_CPU_CTRL_BASE)
/** Array initializer of GPC_CPU_CTRL peripheral base addresses */
#define GPC_CPU_CTRL_BASE_ADDRS                  { GPC_CPU_CTRL_BASE }
/** Array initializer of GPC_CPU_CTRL peripheral base pointers */
#define GPC_CPU_CTRL_BASE_PTRS                   { GPC_CPU_CTRL }

/* GPC_GLOBAL - Peripheral instance base addresses */
/** Peripheral GPC_GLOBAL base address */
#define GPC_GLOBAL_BASE                          (0x44472000u)
/** Peripheral GPC_GLOBAL base pointer */
#define GPC_GLOBAL                               ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE)
/** Array initializer of GPC_GLOBAL peripheral base addresses */
#define GPC_GLOBAL_BASE_ADDRS                    { GPC_GLOBAL_BASE }
/** Array initializer of GPC_GLOBAL peripheral base pointers */
#define GPC_GLOBAL_BASE_PTRS                     { GPC_GLOBAL }

/* GPC_SYS_SLEEP_CTRL - Peripheral instance base addresses */
/** Peripheral GPC_SYS_SLEEP_CTRL base address */
#define GPC_SYS_SLEEP_CTRL_BASE                  (0x44472800u)
/** Peripheral GPC_SYS_SLEEP_CTRL base pointer */
#define GPC_SYS_SLEEP_CTRL                       ((GPC_SYS_SLEEP_CTRL_Type *)GPC_SYS_SLEEP_CTRL_BASE)
/** Array initializer of GPC_SYS_SLEEP_CTRL peripheral base addresses */
#define GPC_SYS_SLEEP_CTRL_BASE_ADDRS            { GPC_SYS_SLEEP_CTRL_BASE }
/** Array initializer of GPC_SYS_SLEEP_CTRL peripheral base pointers */
#define GPC_SYS_SLEEP_CTRL_BASE_PTRS             { GPC_SYS_SLEEP_CTRL }

/* GPT - Peripheral instance base addresses */
/** Peripheral GPT1 base address */
#define GPT1_BASE                                (0x446C0000u)
/** Peripheral GPT1 base pointer */
#define GPT1                                     ((GPT_Type *)GPT1_BASE)
/** Peripheral GPT2 base address */
#define GPT2_BASE                                (0x42EC0000u)
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
#define SAI1_BASE                                (0x443B0000u)
/** Peripheral SAI1 base pointer */
#define SAI1                                     ((I2S_Type *)SAI1_BASE)
/** Peripheral SAI2 base address */
#define SAI2_BASE                                (0x42BB0000u)
/** Peripheral SAI2 base pointer */
#define SAI2                                     ((I2S_Type *)SAI2_BASE)
/** Peripheral SAI3 base address */
#define SAI3_BASE                                (0x42BC0000u)
/** Peripheral SAI3 base pointer */
#define SAI3                                     ((I2S_Type *)SAI3_BASE)
/** Peripheral SAI4 base address */
#define SAI4_BASE                                (0x42BD0000u)
/** Peripheral SAI4 base pointer */
#define SAI4                                     ((I2S_Type *)SAI4_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, SAI2_BASE, SAI3_BASE, SAI4_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, SAI2, SAI3, SAI4 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn, SAI4_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn, SAI4_IRQn }

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

/* IEE - Peripheral instance base addresses */
/** Peripheral IEE base address */
#define IEE_BASE                                 (0x42E40000u)
/** Peripheral IEE base pointer */
#define IEE                                      ((IEE_Type *)IEE_BASE)
/** Array initializer of IEE peripheral base addresses */
#define IEE_BASE_ADDRS                           { IEE_BASE }
/** Array initializer of IEE peripheral base pointers */
#define IEE_BASE_PTRS                            { IEE }

/* IEE_APC - Peripheral instance base addresses */
/** Peripheral IEE_APC base address */
#define IEE_APC_BASE                             (0x42E44000u)
/** Peripheral IEE_APC base pointer */
#define IEE_APC                                  ((IEE_APC_Type *)IEE_APC_BASE)
/** Array initializer of IEE_APC peripheral base addresses */
#define IEE_APC_BASE_ADDRS                       { IEE_APC_BASE }
/** Array initializer of IEE_APC peripheral base pointers */
#define IEE_APC_BASE_PTRS                        { IEE_APC }

/* IERC_IERB - Peripheral instance base addresses */
/** Peripheral IERC_IERB base address */
#define IERC_IERB_BASE                           (0x60810000u)
/** Peripheral IERC_IERB base pointer */
#define IERC_IERB                                ((IERC_IERB_Type *)IERC_IERB_BASE)
/** Array initializer of IERC_IERB peripheral base addresses */
#define IERC_IERB_BASE_ADDRS                     { IERC_IERB_BASE }
/** Array initializer of IERC_IERB peripheral base pointers */
#define IERC_IERB_BASE_PTRS                      { IERC_IERB }

/* IERC_PCI - Peripheral instance base addresses */
/** Peripheral IERC_F0_PCI_HDR_TYPE0 base address */
#define IERC_F0_PCI_HDR_TYPE0_BASE               (0x600F8000u)
/** Peripheral IERC_F0_PCI_HDR_TYPE0 base pointer */
#define IERC_F0_PCI_HDR_TYPE0                    ((IERC_PCI_Type *)IERC_F0_PCI_HDR_TYPE0_BASE)
/** Array initializer of IERC_PCI peripheral base addresses */
#define IERC_PCI_BASE_ADDRS                      { IERC_F0_PCI_HDR_TYPE0_BASE }
/** Array initializer of IERC_PCI peripheral base pointers */
#define IERC_PCI_BASE_PTRS                       { IERC_F0_PCI_HDR_TYPE0 }

/* IOMUXC - Peripheral instance base addresses */
/** Peripheral IOMUXC base address */
#define IOMUXC_BASE                              (0x42A10000u)
/** Peripheral IOMUXC base pointer */
#define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
/** Array initializer of IOMUXC peripheral base addresses */
#define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
/** Array initializer of IOMUXC peripheral base pointers */
#define IOMUXC_BASE_PTRS                         { IOMUXC }

/* IOMUXC_AON - Peripheral instance base addresses */
/** Peripheral IOMUXC_AON base address */
#define IOMUXC_AON_BASE                          (0x443C0000u)
/** Peripheral IOMUXC_AON base pointer */
#define IOMUXC_AON                               ((IOMUXC_AON_Type *)IOMUXC_AON_BASE)
/** Array initializer of IOMUXC_AON peripheral base addresses */
#define IOMUXC_AON_BASE_ADDRS                    { IOMUXC_AON_BASE }
/** Array initializer of IOMUXC_AON peripheral base pointers */
#define IOMUXC_AON_BASE_PTRS                     { IOMUXC_AON }

/* KPP - Peripheral instance base addresses */
/** Peripheral KPP base address */
#define KPP_BASE                                 (0x42A00000u)
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
#define LPI2C5_BASE                              (0x42D30000u)
/** Peripheral LPI2C5 base pointer */
#define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
/** Peripheral LPI2C6 base address */
#define LPI2C6_BASE                              (0x42D40000u)
/** Peripheral LPI2C6 base pointer */
#define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn, LPI2C4_IRQn, LPI2C5_IRQn, LPI2C6_IRQn }

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
#define LPIT3_BASE                               (0x42CC0000u)
/** Peripheral LPIT3 base pointer */
#define LPIT3                                    ((LPIT_Type *)LPIT3_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { 0u, LPIT1_BASE, LPIT2_BASE, LPIT3_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { (LPIT_Type *)0u, LPIT1, LPIT2, LPIT3 }
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { LPIT1_IRQn, LPIT1_IRQn, LPIT1_IRQn, LPIT1_IRQn }, { LPIT2_IRQn, LPIT2_IRQn, LPIT2_IRQn, LPIT2_IRQn }, { LPIT3_IRQn, LPIT3_IRQn, LPIT3_IRQn, LPIT3_IRQn } }

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
#define LPSPI5_BASE                              (0x42D50000u)
/** Peripheral LPSPI5 base pointer */
#define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
/** Peripheral LPSPI6 base address */
#define LPSPI6_BASE                              (0x42D60000u)
/** Peripheral LPSPI6 base pointer */
#define LPSPI6                                   ((LPSPI_Type *)LPSPI6_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE, LPSPI6_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5, LPSPI6 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, LPSPI4_IRQn, LPSPI5_IRQn, LPSPI6_IRQn }

/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR1 base address */
#define LPTMR1_BASE                              (0x44300000u)
/** Peripheral LPTMR1 base pointer */
#define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
/** Peripheral LPTMR2 base address */
#define LPTMR2_BASE                              (0x424D0000u)
/** Peripheral LPTMR2 base pointer */
#define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
/** Peripheral LPTMR3 base address */
#define LPTMR3_BASE                              (0x42CD0000u)
/** Peripheral LPTMR3 base pointer */
#define LPTMR3                                   ((LPTMR_Type *)LPTMR3_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { 0u, LPTMR1_BASE, LPTMR2_BASE, LPTMR3_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { (LPTMR_Type *)0u, LPTMR1, LPTMR2, LPTMR3 }
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { NotAvail_IRQn, LPTMR1_IRQn, LPTMR2_IRQn, LPTMR3_IRQn }

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
#define LPUART7_BASE                             (0x44570000u)
/** Peripheral LPUART7 base pointer */
#define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
/** Peripheral LPUART8 base address */
#define LPUART8_BASE                             (0x42DA0000u)
/** Peripheral LPUART8 base pointer */
#define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
/** Peripheral LPUART9 base address */
#define LPUART9_BASE                             (0x42D70000u)
/** Peripheral LPUART9 base pointer */
#define LPUART9                                  ((LPUART_Type *)LPUART9_BASE)
/** Peripheral LPUART10 base address */
#define LPUART10_BASE                            (0x42D80000u)
/** Peripheral LPUART10 base pointer */
#define LPUART10                                 ((LPUART_Type *)LPUART10_BASE)
/** Peripheral LPUART11 base address */
#define LPUART11_BASE                            (0x42D90000u)
/** Peripheral LPUART11 base pointer */
#define LPUART11                                 ((LPUART_Type *)LPUART11_BASE)
/** Peripheral LPUART12 base address */
#define LPUART12_BASE                            (0x44580000u)
/** Peripheral LPUART12 base pointer */
#define LPUART12                                 ((LPUART_Type *)LPUART12_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE, LPUART9_BASE, LPUART10_BASE, LPUART11_BASE, LPUART12_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8, LPUART9, LPUART10, LPUART11, LPUART12 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn, LPUART6_IRQn, LPUART7_IRQn, LPUART8_IRQn, LPUART9_IRQn, LPUART10_IRQn, LPUART11_IRQn, LPUART12_IRQn }

/* M7_MCM - Peripheral instance base addresses */
/** Peripheral M7_MCM base address */
#define M7_MCM_BASE                              (0xE0080000u)
/** Peripheral M7_MCM base pointer */
#define M7_MCM                                   ((M7_MCM_Type *)M7_MCM_BASE)
/** Array initializer of M7_MCM peripheral base addresses */
#define M7_MCM_BASE_ADDRS                        { M7_MCM_BASE }
/** Array initializer of M7_MCM peripheral base pointers */
#define M7_MCM_BASE_PTRS                         { M7_MCM }

/* MECC - Peripheral instance base addresses */
/** Peripheral MECC1 base address */
#define MECC1_BASE                               (0x42920000u)
/** Peripheral MECC1 base pointer */
#define MECC1                                    ((MECC_Type *)MECC1_BASE)
/** Peripheral MECC2 base address */
#define MECC2_BASE                               (0x42930000u)
/** Peripheral MECC2 base pointer */
#define MECC2                                    ((MECC_Type *)MECC2_BASE)
/** Array initializer of MECC peripheral base addresses */
#define MECC_BASE_ADDRS                          { 0u, MECC1_BASE, MECC2_BASE }
/** Array initializer of MECC peripheral base pointers */
#define MECC_BASE_PTRS                           { (MECC_Type *)0u, MECC1, MECC2 }

/* MSGINTR - Peripheral instance base addresses */
/** Peripheral MSGINTR1 base address */
#define MSGINTR1_BASE                            (0x428A0000u)
/** Peripheral MSGINTR1 base pointer */
#define MSGINTR1                                 ((MSGINTR_Type *)MSGINTR1_BASE)
/** Peripheral MSGINTR2 base address */
#define MSGINTR2_BASE                            (0x428B0000u)
/** Peripheral MSGINTR2 base pointer */
#define MSGINTR2                                 ((MSGINTR_Type *)MSGINTR2_BASE)
/** Peripheral MSGINTR3 base address */
#define MSGINTR3_BASE                            (0x428C0000u)
/** Peripheral MSGINTR3 base pointer */
#define MSGINTR3                                 ((MSGINTR_Type *)MSGINTR3_BASE)
/** Peripheral MSGINTR4 base address */
#define MSGINTR4_BASE                            (0x428D0000u)
/** Peripheral MSGINTR4 base pointer */
#define MSGINTR4                                 ((MSGINTR_Type *)MSGINTR4_BASE)
/** Peripheral MSGINTR5 base address */
#define MSGINTR5_BASE                            (0x428E0000u)
/** Peripheral MSGINTR5 base pointer */
#define MSGINTR5                                 ((MSGINTR_Type *)MSGINTR5_BASE)
/** Peripheral MSGINTR6 base address */
#define MSGINTR6_BASE                            (0x428F0000u)
/** Peripheral MSGINTR6 base pointer */
#define MSGINTR6                                 ((MSGINTR_Type *)MSGINTR6_BASE)
/** Array initializer of MSGINTR peripheral base addresses */
#define MSGINTR_BASE_ADDRS                       { 0u, MSGINTR1_BASE, MSGINTR2_BASE, MSGINTR3_BASE, MSGINTR4_BASE, MSGINTR5_BASE, MSGINTR6_BASE }
/** Array initializer of MSGINTR peripheral base pointers */
#define MSGINTR_BASE_PTRS                        { (MSGINTR_Type *)0u, MSGINTR1, MSGINTR2, MSGINTR3, MSGINTR4, MSGINTR5, MSGINTR6 }

/* MU - Peripheral instance base addresses */
/** Peripheral MU1_MUB base address */
#define MU1_MUB_BASE                             (0x44230000u)
/** Peripheral MU1_MUB base pointer */
#define MU1_MUB                                  ((MU_Type *)MU1_MUB_BASE)
/** Peripheral MU2_MUB base address */
#define MU2_MUB_BASE                             (0x42440000u)
/** Peripheral MU2_MUB base pointer */
#define MU2_MUB                                  ((MU_Type *)MU2_MUB_BASE)
/** Array initializer of MU peripheral base addresses */
#define MU_BASE_ADDRS                            { MU1_MUB_BASE, MU2_MUB_BASE }
/** Array initializer of MU peripheral base pointers */
#define MU_BASE_PTRS                             { MU1_MUB, MU2_MUB }
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU1_IRQn, MU2_IRQn }

/* NETC_ENETC - Peripheral instance base addresses */
/** Peripheral ENETC0_BASE base address */
#define ENETC0_BASE_BASE                         (0x60B10000u)
/** Peripheral ENETC0_BASE base pointer */
#define ENETC0_BASE                              ((NETC_ENETC_Type *)ENETC0_BASE_BASE)
/** Peripheral ENETC1_BASE base address */
#define ENETC1_BASE_BASE                         (0x60B50000u)
/** Peripheral ENETC1_BASE base pointer */
#define ENETC1_BASE                              ((NETC_ENETC_Type *)ENETC1_BASE_BASE)
/** Array initializer of NETC_ENETC peripheral base addresses */
#define NETC_ENETC_BASE_ADDRS                    { ENETC0_BASE_BASE, ENETC1_BASE_BASE }
/** Array initializer of NETC_ENETC peripheral base pointers */
#define NETC_ENETC_BASE_PTRS                     { ENETC0_BASE, ENETC1_BASE }

/* NETC_ETH_LINK - Peripheral instance base addresses */
/** Peripheral ENETC0_ETH_MAC_PORT base address */
#define ENETC0_ETH_MAC_PORT_BASE                 (0x60B15000u)
/** Peripheral ENETC0_ETH_MAC_PORT base pointer */
#define ENETC0_ETH_MAC_PORT                      ((NETC_ETH_LINK_Type *)ENETC0_ETH_MAC_PORT_BASE)
/** Peripheral SW0_ETH_MAC_PORT0 base address */
#define SW0_ETH_MAC_PORT0_BASE                   (0x60A05000u)
/** Peripheral SW0_ETH_MAC_PORT0 base pointer */
#define SW0_ETH_MAC_PORT0                        ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT0_BASE)
/** Peripheral SW0_ETH_MAC_PORT1 base address */
#define SW0_ETH_MAC_PORT1_BASE                   (0x60A09000u)
/** Peripheral SW0_ETH_MAC_PORT1 base pointer */
#define SW0_ETH_MAC_PORT1                        ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT1_BASE)
/** Peripheral SW0_ETH_MAC_PORT2 base address */
#define SW0_ETH_MAC_PORT2_BASE                   (0x60A0D000u)
/** Peripheral SW0_ETH_MAC_PORT2 base pointer */
#define SW0_ETH_MAC_PORT2                        ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT2_BASE)
/** Peripheral SW0_ETH_MAC_PORT3 base address */
#define SW0_ETH_MAC_PORT3_BASE                   (0x60A11000u)
/** Peripheral SW0_ETH_MAC_PORT3 base pointer */
#define SW0_ETH_MAC_PORT3                        ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT3_BASE)
/** Array initializer of NETC_ETH_LINK peripheral base addresses */
#define NETC_ETH_LINK_BASE_ADDRS                 { ENETC0_ETH_MAC_PORT_BASE, SW0_ETH_MAC_PORT0_BASE, SW0_ETH_MAC_PORT1_BASE, SW0_ETH_MAC_PORT2_BASE, SW0_ETH_MAC_PORT3_BASE }
/** Array initializer of NETC_ETH_LINK peripheral base pointers */
#define NETC_ETH_LINK_BASE_PTRS                  { ENETC0_ETH_MAC_PORT, SW0_ETH_MAC_PORT0, SW0_ETH_MAC_PORT1, SW0_ETH_MAC_PORT2, SW0_ETH_MAC_PORT3 }

/* NETC_IERB - Peripheral instance base addresses */
/** Peripheral NETC_IERB base address */
#define NETC_IERB_BASE                           (0x60800000u)
/** Peripheral NETC_IERB base pointer */
#define NETC_IERB                                ((NETC_IERB_Type *)NETC_IERB_BASE)
/** Array initializer of NETC_IERB peripheral base addresses */
#define NETC_IERB_BASE_ADDRS                     { NETC_IERB_BASE }
/** Array initializer of NETC_IERB peripheral base pointers */
#define NETC_IERB_BASE_PTRS                      { NETC_IERB }

/* NETC_PORT - Peripheral instance base addresses */
/** Peripheral ENETC0_PORT base address */
#define ENETC0_PORT_BASE                         (0x60B14000u)
/** Peripheral ENETC0_PORT base pointer */
#define ENETC0_PORT                              ((NETC_PORT_Type *)ENETC0_PORT_BASE)
/** Peripheral ENETC1_PORT base address */
#define ENETC1_PORT_BASE                         (0x60B54000u)
/** Peripheral ENETC1_PORT base pointer */
#define ENETC1_PORT                              ((NETC_PORT_Type *)ENETC1_PORT_BASE)
/** Peripheral SW0_PORT0 base address */
#define SW0_PORT0_BASE                           (0x60A04000u)
/** Peripheral SW0_PORT0 base pointer */
#define SW0_PORT0                                ((NETC_PORT_Type *)SW0_PORT0_BASE)
/** Peripheral SW0_PORT1 base address */
#define SW0_PORT1_BASE                           (0x60A08000u)
/** Peripheral SW0_PORT1 base pointer */
#define SW0_PORT1                                ((NETC_PORT_Type *)SW0_PORT1_BASE)
/** Peripheral SW0_PORT2 base address */
#define SW0_PORT2_BASE                           (0x60A0C000u)
/** Peripheral SW0_PORT2 base pointer */
#define SW0_PORT2                                ((NETC_PORT_Type *)SW0_PORT2_BASE)
/** Peripheral SW0_PORT3 base address */
#define SW0_PORT3_BASE                           (0x60A10000u)
/** Peripheral SW0_PORT3 base pointer */
#define SW0_PORT3                                ((NETC_PORT_Type *)SW0_PORT3_BASE)
/** Peripheral SW0_PORT4 base address */
#define SW0_PORT4_BASE                           (0x60A14000u)
/** Peripheral SW0_PORT4 base pointer */
#define SW0_PORT4                                ((NETC_PORT_Type *)SW0_PORT4_BASE)
/** Array initializer of NETC_PORT peripheral base addresses */
#define NETC_PORT_BASE_ADDRS                     { ENETC0_PORT_BASE, ENETC1_PORT_BASE, SW0_PORT0_BASE, SW0_PORT1_BASE, SW0_PORT2_BASE, SW0_PORT3_BASE, SW0_PORT4_BASE }
/** Array initializer of NETC_PORT peripheral base pointers */
#define NETC_PORT_BASE_PTRS                      { ENETC0_PORT, ENETC1_PORT, SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 }

/* NETC_PRIV - Peripheral instance base addresses */
/** Peripheral NETC_PRIV base address */
#define NETC_PRIV_BASE                           (0x60900000u)
/** Peripheral NETC_PRIV base pointer */
#define NETC_PRIV                                ((NETC_PRIV_Type *)NETC_PRIV_BASE)
/** Array initializer of NETC_PRIV peripheral base addresses */
#define NETC_PRIV_BASE_ADDRS                     { NETC_PRIV_BASE }
/** Array initializer of NETC_PRIV peripheral base pointers */
#define NETC_PRIV_BASE_PTRS                      { NETC_PRIV }

/* NETC_PSEUDO_LINK - Peripheral instance base addresses */
/** Peripheral ENETC1_PSEUDO_MAC_PORT base address */
#define ENETC1_PSEUDO_MAC_PORT_BASE              (0x60B55000u)
/** Peripheral ENETC1_PSEUDO_MAC_PORT base pointer */
#define ENETC1_PSEUDO_MAC_PORT                   ((NETC_PSEUDO_LINK_Type *)ENETC1_PSEUDO_MAC_PORT_BASE)
/** Peripheral SW0_PSEUDO_MAC_PORT4 base address */
#define SW0_PSEUDO_MAC_PORT4_BASE                (0x60A15000u)
/** Peripheral SW0_PSEUDO_MAC_PORT4 base pointer */
#define SW0_PSEUDO_MAC_PORT4                     ((NETC_PSEUDO_LINK_Type *)SW0_PSEUDO_MAC_PORT4_BASE)
/** Array initializer of NETC_PSEUDO_LINK peripheral base addresses */
#define NETC_PSEUDO_LINK_BASE_ADDRS              { ENETC1_PSEUDO_MAC_PORT_BASE, SW0_PSEUDO_MAC_PORT4_BASE }
/** Array initializer of NETC_PSEUDO_LINK peripheral base pointers */
#define NETC_PSEUDO_LINK_BASE_PTRS               { ENETC1_PSEUDO_MAC_PORT, SW0_PSEUDO_MAC_PORT4 }

/* NETC_SW - Peripheral instance base addresses */
/** Peripheral SW0_BASE base address */
#define SW0_BASE_BASE                            (0x60A00000u)
/** Peripheral SW0_BASE base pointer */
#define SW0_BASE                                 ((NETC_SW_Type *)SW0_BASE_BASE)
/** Array initializer of NETC_SW peripheral base addresses */
#define NETC_SW_BASE_ADDRS                       { SW0_BASE_BASE }
/** Array initializer of NETC_SW peripheral base pointers */
#define NETC_SW_BASE_PTRS                        { SW0_BASE }

/* NETC_SW_ENETC - Peripheral instance base addresses */
/** Peripheral ENETC0_COMMON base address */
#define ENETC0_COMMON_BASE                       (0x60B10000u)
/** Peripheral ENETC0_COMMON base pointer */
#define ENETC0_COMMON                            ((NETC_SW_ENETC_Type *)ENETC0_COMMON_BASE)
/** Peripheral ENETC1_COMMON base address */
#define ENETC1_COMMON_BASE                       (0x60B50000u)
/** Peripheral ENETC1_COMMON base pointer */
#define ENETC1_COMMON                            ((NETC_SW_ENETC_Type *)ENETC1_COMMON_BASE)
/** Peripheral SW0_COMMON base address */
#define SW0_COMMON_BASE                          (0x60A00000u)
/** Peripheral SW0_COMMON base pointer */
#define SW0_COMMON                               ((NETC_SW_ENETC_Type *)SW0_COMMON_BASE)
/** Array initializer of NETC_SW_ENETC peripheral base addresses */
#define NETC_SW_ENETC_BASE_ADDRS                 { ENETC0_COMMON_BASE, ENETC1_COMMON_BASE, SW0_COMMON_BASE }
/** Array initializer of NETC_SW_ENETC peripheral base pointers */
#define NETC_SW_ENETC_BASE_PTRS                  { ENETC0_COMMON, ENETC1_COMMON, SW0_COMMON }

/* OCOTP_FSB - Peripheral instance base addresses */
/** Peripheral OCOTP_FSB base address */
#define OCOTP_FSB_BASE                           (0x47518000u)
/** Peripheral OCOTP_FSB base pointer */
#define OCOTP_FSB                                ((OCOTP_FSB_Type *)OCOTP_FSB_BASE)
/** Array initializer of OCOTP_FSB peripheral base addresses */
#define OCOTP_FSB_BASE_ADDRS                     { OCOTP_FSB_BASE }
/** Array initializer of OCOTP_FSB peripheral base pointers */
#define OCOTP_FSB_BASE_PTRS                      { OCOTP_FSB }

/* OSC_RC_400M - Peripheral instance base addresses */
/** Peripheral OSC_RC_400M base address */
#define OSC_RC_400M_BASE                         (0x44484380u)
/** Peripheral OSC_RC_400M base pointer */
#define OSC_RC_400M                              ((OSC_RC_400M_Type *)OSC_RC_400M_BASE)
/** Array initializer of OSC_RC_400M peripheral base addresses */
#define OSC_RC_400M_BASE_ADDRS                   { OSC_RC_400M_BASE }
/** Array initializer of OSC_RC_400M peripheral base pointers */
#define OSC_RC_400M_BASE_PTRS                    { OSC_RC_400M }

/* OTFAD - Peripheral instance base addresses */
/** Peripheral OTFAD1 base address */
#define OTFAD1_BASE                              (0x425E0000u)
/** Peripheral OTFAD1 base pointer */
#define OTFAD1                                   ((OTFAD_Type *)OTFAD1_BASE)
/** Peripheral OTFAD2 base address */
#define OTFAD2_BASE                              (0x445E0000u)
/** Peripheral OTFAD2 base pointer */
#define OTFAD2                                   ((OTFAD_Type *)OTFAD2_BASE)
/** Array initializer of OTFAD peripheral base addresses */
#define OTFAD_BASE_ADDRS                         { 0u, OTFAD1_BASE, OTFAD2_BASE }
/** Array initializer of OTFAD peripheral base pointers */
#define OTFAD_BASE_PTRS                          { (OTFAD_Type *)0u, OTFAD1, OTFAD2 }

/* PDM - Peripheral instance base addresses */
/** Peripheral PDM base address */
#define PDM_BASE                                 (0x42BE0000u)
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

/* PHY_LDO - Peripheral instance base addresses */
/** Peripheral PHY_LDO base address */
#define PHY_LDO_BASE                             (0x44484680u)
/** Peripheral PHY_LDO base pointer */
#define PHY_LDO                                  ((PHY_LDO_Type *)PHY_LDO_BASE)
/** Array initializer of PHY_LDO peripheral base addresses */
#define PHY_LDO_BASE_ADDRS                       { PHY_LDO_BASE }
/** Array initializer of PHY_LDO peripheral base pointers */
#define PHY_LDO_BASE_PTRS                        { PHY_LDO }

/* PLL - Peripheral instance base addresses */
/** Peripheral AUDIO_PLL base address */
#define AUDIO_PLL_BASE                           (0x44484280u)
/** Peripheral AUDIO_PLL base pointer */
#define AUDIO_PLL                                ((PLL_Type *)AUDIO_PLL_BASE)
/** Peripheral ETHERNET_PLL base address */
#define ETHERNET_PLL_BASE                        (0x44484180u)
/** Peripheral ETHERNET_PLL base pointer */
#define ETHERNET_PLL                             ((PLL_Type *)ETHERNET_PLL_BASE)
/** Array initializer of PLL peripheral base addresses */
#define PLL_BASE_ADDRS                           { AUDIO_PLL_BASE, ETHERNET_PLL_BASE }
/** Array initializer of PLL peripheral base pointers */
#define PLL_BASE_PTRS                            { AUDIO_PLL, ETHERNET_PLL }

/* PWM - Peripheral instance base addresses */
/** Peripheral PWM1 base address */
#define PWM1_BASE                                (0x42650000u)
/** Peripheral PWM1 base pointer */
#define PWM1                                     ((PWM_Type *)PWM1_BASE)
/** Peripheral PWM2 base address */
#define PWM2_BASE                                (0x42660000u)
/** Peripheral PWM2 base pointer */
#define PWM2                                     ((PWM_Type *)PWM2_BASE)
/** Peripheral PWM3 base address */
#define PWM3_BASE                                (0x42670000u)
/** Peripheral PWM3 base pointer */
#define PWM3                                     ((PWM_Type *)PWM3_BASE)
/** Peripheral PWM4 base address */
#define PWM4_BASE                                (0x42680000u)
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

/* RGPIO - Peripheral instance base addresses */
/** Peripheral RGPIO1 base address */
#define RGPIO1_BASE                              (0x47400000u)
/** Peripheral RGPIO1 base pointer */
#define RGPIO1                                   ((RGPIO_Type *)RGPIO1_BASE)
/** Peripheral RGPIO2 base address */
#define RGPIO2_BASE                              (0x43810000u)
/** Peripheral RGPIO2 base pointer */
#define RGPIO2                                   ((RGPIO_Type *)RGPIO2_BASE)
/** Peripheral RGPIO3 base address */
#define RGPIO3_BASE                              (0x43820000u)
/** Peripheral RGPIO3 base pointer */
#define RGPIO3                                   ((RGPIO_Type *)RGPIO3_BASE)
/** Peripheral RGPIO4 base address */
#define RGPIO4_BASE                              (0x43830000u)
/** Peripheral RGPIO4 base pointer */
#define RGPIO4                                   ((RGPIO_Type *)RGPIO4_BASE)
/** Peripheral RGPIO5 base address */
#define RGPIO5_BASE                              (0x43840000u)
/** Peripheral RGPIO5 base pointer */
#define RGPIO5                                   ((RGPIO_Type *)RGPIO5_BASE)
/** Peripheral RGPIO6 base address */
#define RGPIO6_BASE                              (0x43850000u)
/** Peripheral RGPIO6 base pointer */
#define RGPIO6                                   ((RGPIO_Type *)RGPIO6_BASE)
/** Array initializer of RGPIO peripheral base addresses */
#define RGPIO_BASE_ADDRS                         { 0u, RGPIO1_BASE, RGPIO2_BASE, RGPIO3_BASE, RGPIO4_BASE, RGPIO5_BASE, RGPIO6_BASE }
/** Array initializer of RGPIO peripheral base pointers */
#define RGPIO_BASE_PTRS                          { (RGPIO_Type *)0u, RGPIO1, RGPIO2, RGPIO3, RGPIO4, RGPIO5, RGPIO6 }
/** Interrupt vectors for the RGPIO peripheral type */
#define RGPIO_CH0_IRQS                           { NotAvail_IRQn, GPIO1_0_IRQn, GPIO2_0_IRQn, GPIO3_0_IRQn, GPIO4_IRQn, GPIO5_IRQn, GPIO6_IRQn }
#define RGPIO_CH1_IRQS                           { NotAvail_IRQn, GPIO1_1_IRQn, GPIO2_1_IRQn, GPIO3_1_IRQn, GPIO4_IRQn, GPIO5_IRQn, GPIO6_IRQn }

/* RTWDOG - Peripheral instance base addresses */
/** Peripheral RTWDOG1 base address */
#define RTWDOG1_BASE                             (0x442D0000u)
/** Peripheral RTWDOG1 base pointer */
#define RTWDOG1                                  ((RTWDOG_Type *)RTWDOG1_BASE)
/** Peripheral RTWDOG2 base address */
#define RTWDOG2_BASE                             (0x442E0000u)
/** Peripheral RTWDOG2 base pointer */
#define RTWDOG2                                  ((RTWDOG_Type *)RTWDOG2_BASE)
/** Peripheral RTWDOG3 base address */
#define RTWDOG3_BASE                             (0x42490000u)
/** Peripheral RTWDOG3 base pointer */
#define RTWDOG3                                  ((RTWDOG_Type *)RTWDOG3_BASE)
/** Peripheral RTWDOG4 base address */
#define RTWDOG4_BASE                             (0x424A0000u)
/** Peripheral RTWDOG4 base pointer */
#define RTWDOG4                                  ((RTWDOG_Type *)RTWDOG4_BASE)
/** Peripheral RTWDOG5 base address */
#define RTWDOG5_BASE                             (0x424B0000u)
/** Peripheral RTWDOG5 base pointer */
#define RTWDOG5                                  ((RTWDOG_Type *)RTWDOG5_BASE)
/** Array initializer of RTWDOG peripheral base addresses */
#define RTWDOG_BASE_ADDRS                        { 0u, RTWDOG1_BASE, RTWDOG2_BASE, RTWDOG3_BASE, RTWDOG4_BASE, RTWDOG5_BASE }
/** Array initializer of RTWDOG peripheral base pointers */
#define RTWDOG_BASE_PTRS                         { (RTWDOG_Type *)0u, RTWDOG1, RTWDOG2, RTWDOG3, RTWDOG4, RTWDOG5 }
/** Interrupt vectors for the RTWDOG peripheral type */
#define RTWDOG_IRQS                              { NotAvail_IRQn, RTWDOG1_IRQn, RTWDOG2_IRQn, RTWDOG3_IRQn, RTWDOG4_IRQn, RTWDOG5_IRQn }
/* Extra definition */
#define RTWDOG_UPDATE_KEY                        (0xD928C520U)
#define RTWDOG_REFRESH_KEY                       (0xB480A602U)


/* S3MU - Peripheral instance base addresses */
/** Peripheral MU_APPS_S3MUA base address */
#define MU_APPS_S3MUA_BASE                       (0x47520000u)
/** Peripheral MU_APPS_S3MUA base pointer */
#define MU_APPS_S3MUA                            ((S3MU_Type *)MU_APPS_S3MUA_BASE)
/** Peripheral MU_RT_S3MUA base address */
#define MU_RT_S3MUA_BASE                         (0x47540000u)
/** Peripheral MU_RT_S3MUA base pointer */
#define MU_RT_S3MUA                              ((S3MU_Type *)MU_RT_S3MUA_BASE)
/** Array initializer of S3MU peripheral base addresses */
#define S3MU_BASE_ADDRS                          { MU_APPS_S3MUA_BASE, MU_RT_S3MUA_BASE }
/** Array initializer of S3MU peripheral base pointers */
#define S3MU_BASE_PTRS                           { MU_APPS_S3MUA, MU_RT_S3MUA }

/* SEMA42 - Peripheral instance base addresses */
/** Peripheral SEMA1 base address */
#define SEMA1_BASE                               (0x44260000u)
/** Peripheral SEMA1 base pointer */
#define SEMA1                                    ((SEMA42_Type *)SEMA1_BASE)
/** Peripheral SEMA2 base address */
#define SEMA2_BASE                               (0x42450000u)
/** Peripheral SEMA2 base pointer */
#define SEMA2                                    ((SEMA42_Type *)SEMA2_BASE)
/** Array initializer of SEMA42 peripheral base addresses */
#define SEMA42_BASE_ADDRS                        { SEMA1_BASE, SEMA2_BASE }
/** Array initializer of SEMA42 peripheral base pointers */
#define SEMA42_BASE_PTRS                         { SEMA1, SEMA2 }

/* SEMC - Peripheral instance base addresses */
/** Peripheral SEMC base address */
#define SEMC_BASE                                (0x42910000u)
/** Peripheral SEMC base pointer */
#define SEMC                                     ((SEMC_Type *)SEMC_BASE)
/** Array initializer of SEMC peripheral base addresses */
#define SEMC_BASE_ADDRS                          { SEMC_BASE }
/** Array initializer of SEMC peripheral base pointers */
#define SEMC_BASE_PTRS                           { SEMC }
/** Interrupt vectors for the SEMC peripheral type */
#define SEMC_IRQS                                { SEMC_IRQn }

/* SINC - Peripheral instance base addresses */
/** Peripheral SINC1 base address */
#define SINC1_BASE                               (0x42BF0000u)
/** Peripheral SINC1 base pointer */
#define SINC1                                    ((SINC_Type *)SINC1_BASE)
/** Peripheral SINC2 base address */
#define SINC2_BASE                               (0x42C00000u)
/** Peripheral SINC2 base pointer */
#define SINC2                                    ((SINC_Type *)SINC2_BASE)
/** Peripheral SINC3 base address */
#define SINC3_BASE                               (0x42C10000u)
/** Peripheral SINC3 base pointer */
#define SINC3                                    ((SINC_Type *)SINC3_BASE)
/** Array initializer of SINC peripheral base addresses */
#define SINC_BASE_ADDRS                          { 0u, SINC1_BASE, SINC2_BASE, SINC3_BASE }
/** Array initializer of SINC peripheral base pointers */
#define SINC_BASE_PTRS                           { (SINC_Type *)0u, SINC1, SINC2, SINC3 }
/** Interrupt vectors for the SINC peripheral type */
#define SINC_IRQS                                { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { SINC1_CH0_IRQn, SINC1_CH1_IRQn, SINC1_CH2_IRQn, SINC1_CH3_IRQn }, { SINC2_CH0_IRQn, SINC2_CH1_IRQn, SINC2_CH2_IRQn, SINC2_CH3_IRQn }, { SINC3_CH0_CH1_CH2_CH3_IRQn, SINC3_CH0_CH1_CH2_CH3_IRQn, SINC3_CH0_CH1_CH2_CH3_IRQn, SINC3_CH0_CH1_CH2_CH3_IRQn } }

/* SPDIF - Peripheral instance base addresses */
/** Peripheral SPDIF base address */
#define SPDIF_BASE                               (0x42BA0000u)
/** Peripheral SPDIF base pointer */
#define SPDIF                                    ((SPDIF_Type *)SPDIF_BASE)
/** Array initializer of SPDIF peripheral base addresses */
#define SPDIF_BASE_ADDRS                         { SPDIF_BASE }
/** Array initializer of SPDIF peripheral base pointers */
#define SPDIF_BASE_PTRS                          { SPDIF }
/** Interrupt vectors for the SPDIF peripheral type */
#define SPDIF_IRQS                               { SPDIF_IRQn }

/* SRC_GENERAL - Peripheral instance base addresses */
/** Peripheral SRC_GENERAL_REG base address */
#define SRC_GENERAL_REG_BASE                     (0x44460000u)
/** Peripheral SRC_GENERAL_REG base pointer */
#define SRC_GENERAL_REG                          ((SRC_GENERAL_Type *)SRC_GENERAL_REG_BASE)
/** Array initializer of SRC_GENERAL peripheral base addresses */
#define SRC_GENERAL_BASE_ADDRS                   { SRC_GENERAL_REG_BASE }
/** Array initializer of SRC_GENERAL peripheral base pointers */
#define SRC_GENERAL_BASE_PTRS                    { SRC_GENERAL_REG }

/* SRC_MIF_LN28FDSOI_SPLLRAM - Peripheral instance base addresses */
/** Peripheral AON_MIF_LN28FDSOI_SPLLRAM base address */
#define AON_MIF_LN28FDSOI_SPLLRAM_BASE           (0x44462400u)
/** Peripheral AON_MIF_LN28FDSOI_SPLLRAM base pointer */
#define AON_MIF_LN28FDSOI_SPLLRAM                ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)AON_MIF_LN28FDSOI_SPLLRAM_BASE)
/** Peripheral WAKEUP_MIF_LN28FDSOI_SPLLRAM base address */
#define WAKEUP_MIF_LN28FDSOI_SPLLRAM_BASE        (0x44462C00u)
/** Peripheral WAKEUP_MIF_LN28FDSOI_SPLLRAM base pointer */
#define WAKEUP_MIF_LN28FDSOI_SPLLRAM             ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)WAKEUP_MIF_LN28FDSOI_SPLLRAM_BASE)
/** Peripheral MEGA_MIF_LN28FDSOI_SPLLRAM base address */
#define MEGA_MIF_LN28FDSOI_SPLLRAM_BASE          (0x44463400u)
/** Peripheral MEGA_MIF_LN28FDSOI_SPLLRAM base pointer */
#define MEGA_MIF_LN28FDSOI_SPLLRAM               ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)MEGA_MIF_LN28FDSOI_SPLLRAM_BASE)
/** Peripheral NETC_MIF_LN28FDSOI_SPLLRAM base address */
#define NETC_MIF_LN28FDSOI_SPLLRAM_BASE          (0x44463C00u)
/** Peripheral NETC_MIF_LN28FDSOI_SPLLRAM base pointer */
#define NETC_MIF_LN28FDSOI_SPLLRAM               ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)NETC_MIF_LN28FDSOI_SPLLRAM_BASE)
/** Array initializer of SRC_MIF_LN28FDSOI_SPLLRAM peripheral base addresses */
#define SRC_MIF_LN28FDSOI_SPLLRAM_BASE_ADDRS     { AON_MIF_LN28FDSOI_SPLLRAM_BASE, WAKEUP_MIF_LN28FDSOI_SPLLRAM_BASE, MEGA_MIF_LN28FDSOI_SPLLRAM_BASE, NETC_MIF_LN28FDSOI_SPLLRAM_BASE }
/** Array initializer of SRC_MIF_LN28FDSOI_SPLLRAM peripheral base pointers */
#define SRC_MIF_LN28FDSOI_SPLLRAM_BASE_PTRS      { AON_MIF_LN28FDSOI_SPLLRAM, WAKEUP_MIF_LN28FDSOI_SPLLRAM, MEGA_MIF_LN28FDSOI_SPLLRAM, NETC_MIF_LN28FDSOI_SPLLRAM }

/* SRC_MIF_S28SPREGH - Peripheral instance base addresses */
/** Peripheral AON_MIF_S28SPREGH base address */
#define AON_MIF_S28SPREGH_BASE                   (0x44462000u)
/** Peripheral AON_MIF_S28SPREGH base pointer */
#define AON_MIF_S28SPREGH                        ((SRC_MIF_S28SPREGH_Type *)AON_MIF_S28SPREGH_BASE)
/** Peripheral WAKEUP_MIF_S28SPREGH base address */
#define WAKEUP_MIF_S28SPREGH_BASE                (0x44462800u)
/** Peripheral WAKEUP_MIF_S28SPREGH base pointer */
#define WAKEUP_MIF_S28SPREGH                     ((SRC_MIF_S28SPREGH_Type *)WAKEUP_MIF_S28SPREGH_BASE)
/** Peripheral MEGA_MIF_S28SPREGH base address */
#define MEGA_MIF_S28SPREGH_BASE                  (0x44463000u)
/** Peripheral MEGA_MIF_S28SPREGH base pointer */
#define MEGA_MIF_S28SPREGH                       ((SRC_MIF_S28SPREGH_Type *)MEGA_MIF_S28SPREGH_BASE)
/** Peripheral NETC_MIF_S28SPREGH base address */
#define NETC_MIF_S28SPREGH_BASE                  (0x44463800u)
/** Peripheral NETC_MIF_S28SPREGH base pointer */
#define NETC_MIF_S28SPREGH                       ((SRC_MIF_S28SPREGH_Type *)NETC_MIF_S28SPREGH_BASE)
/** Peripheral CM33PLATFORM_CACHE base address */
#define CM33PLATFORM_CACHE_BASE                  (0x44464000u)
/** Peripheral CM33PLATFORM_CACHE base pointer */
#define CM33PLATFORM_CACHE                       ((SRC_MIF_S28SPREGH_Type *)CM33PLATFORM_CACHE_BASE)
/** Peripheral CM7PLATFORM_CACHE base address */
#define CM7PLATFORM_CACHE_BASE                   (0x44464800u)
/** Peripheral CM7PLATFORM_CACHE base pointer */
#define CM7PLATFORM_CACHE                        ((SRC_MIF_S28SPREGH_Type *)CM7PLATFORM_CACHE_BASE)
/** Peripheral CM33PLATFORM_TCM base address */
#define CM33PLATFORM_TCM_BASE                    (0x44464400u)
/** Peripheral CM33PLATFORM_TCM base pointer */
#define CM33PLATFORM_TCM                         ((SRC_MIF_S28SPREGH_Type *)CM33PLATFORM_TCM_BASE)
/** Array initializer of SRC_MIF_S28SPREGH peripheral base addresses */
#define SRC_MIF_S28SPREGH_BASE_ADDRS             { AON_MIF_S28SPREGH_BASE, WAKEUP_MIF_S28SPREGH_BASE, MEGA_MIF_S28SPREGH_BASE, NETC_MIF_S28SPREGH_BASE, CM33PLATFORM_CACHE_BASE, CM7PLATFORM_CACHE_BASE, CM33PLATFORM_TCM_BASE }
/** Array initializer of SRC_MIF_S28SPREGH peripheral base pointers */
#define SRC_MIF_S28SPREGH_BASE_PTRS              { AON_MIF_S28SPREGH, WAKEUP_MIF_S28SPREGH, MEGA_MIF_S28SPREGH, NETC_MIF_S28SPREGH, CM33PLATFORM_CACHE, CM7PLATFORM_CACHE, CM33PLATFORM_TCM }

/* SRC_MIF_S28SPREGH_PSWA - Peripheral instance base addresses */
/** Peripheral CM7PLATFORM_TCM base address */
#define CM7PLATFORM_TCM_BASE                     (0x44464C00u)
/** Peripheral CM7PLATFORM_TCM base pointer */
#define CM7PLATFORM_TCM                          ((SRC_MIF_S28SPREGH_PSWA_Type *)CM7PLATFORM_TCM_BASE)
/** Array initializer of SRC_MIF_S28SPREGH_PSWA peripheral base addresses */
#define SRC_MIF_S28SPREGH_PSWA_BASE_ADDRS        { CM7PLATFORM_TCM_BASE }
/** Array initializer of SRC_MIF_S28SPREGH_PSWA peripheral base pointers */
#define SRC_MIF_S28SPREGH_PSWA_BASE_PTRS         { CM7PLATFORM_TCM }

/* SRC_MIX_SLICE - Peripheral instance base addresses */
/** Peripheral AON_MIX_SLICE base address */
#define AON_MIX_SLICE_BASE                       (0x44460800u)
/** Peripheral AON_MIX_SLICE base pointer */
#define AON_MIX_SLICE                            ((SRC_MIX_SLICE_Type *)AON_MIX_SLICE_BASE)
/** Peripheral WAKEUP_MIX_SLICE base address */
#define WAKEUP_MIX_SLICE_BASE                    (0x44460C00u)
/** Peripheral WAKEUP_MIX_SLICE base pointer */
#define WAKEUP_MIX_SLICE                         ((SRC_MIX_SLICE_Type *)WAKEUP_MIX_SLICE_BASE)
/** Peripheral MEGA_MIX_SLICE base address */
#define MEGA_MIX_SLICE_BASE                      (0x44461000u)
/** Peripheral MEGA_MIX_SLICE base pointer */
#define MEGA_MIX_SLICE                           ((SRC_MIX_SLICE_Type *)MEGA_MIX_SLICE_BASE)
/** Peripheral NETC_MIX_SLICE base address */
#define NETC_MIX_SLICE_BASE                      (0x44461400u)
/** Peripheral NETC_MIX_SLICE base pointer */
#define NETC_MIX_SLICE                           ((SRC_MIX_SLICE_Type *)NETC_MIX_SLICE_BASE)
/** Peripheral CM33PLATFORM_MIX_SLICE base address */
#define CM33PLATFORM_MIX_SLICE_BASE              (0x44461800u)
/** Peripheral CM33PLATFORM_MIX_SLICE base pointer */
#define CM33PLATFORM_MIX_SLICE                   ((SRC_MIX_SLICE_Type *)CM33PLATFORM_MIX_SLICE_BASE)
/** Peripheral CM7PLATFORM_MIX_SLICE base address */
#define CM7PLATFORM_MIX_SLICE_BASE               (0x44461C00u)
/** Peripheral CM7PLATFORM_MIX_SLICE base pointer */
#define CM7PLATFORM_MIX_SLICE                    ((SRC_MIX_SLICE_Type *)CM7PLATFORM_MIX_SLICE_BASE)
/** Array initializer of SRC_MIX_SLICE peripheral base addresses */
#define SRC_MIX_SLICE_BASE_ADDRS                 { AON_MIX_SLICE_BASE, WAKEUP_MIX_SLICE_BASE, MEGA_MIX_SLICE_BASE, NETC_MIX_SLICE_BASE, CM33PLATFORM_MIX_SLICE_BASE, CM7PLATFORM_MIX_SLICE_BASE }
/** Array initializer of SRC_MIX_SLICE peripheral base pointers */
#define SRC_MIX_SLICE_BASE_PTRS                  { AON_MIX_SLICE, WAKEUP_MIX_SLICE, MEGA_MIX_SLICE, NETC_MIX_SLICE, CM33PLATFORM_MIX_SLICE, CM7PLATFORM_MIX_SLICE }

/* SYSPM - Peripheral instance base addresses */
/** Peripheral M33_PCF1 base address */
#define M33_PCF1_BASE                            (0x443E0000u)
/** Peripheral M33_PCF1 base pointer */
#define M33_PCF1                                 ((SYSPM_Type *)M33_PCF1_BASE)
/** Peripheral M33_PSF1 base address */
#define M33_PSF1_BASE                            (0x443F0000u)
/** Peripheral M33_PSF1 base pointer */
#define M33_PSF1                                 ((SYSPM_Type *)M33_PSF1_BASE)
/** Array initializer of SYSPM peripheral base addresses */
#define SYSPM_BASE_ADDRS                         { M33_PCF1_BASE, M33_PSF1_BASE }
/** Array initializer of SYSPM peripheral base pointers */
#define SYSPM_BASE_PTRS                          { M33_PCF1, M33_PSF1 }

/* SYS_CTR_COMPARE - Peripheral instance base addresses */
/** Peripheral SYS_CTR_COMPARE base address */
#define SYS_CTR_COMPARE_BASE                     (0x442A0000u)
/** Peripheral SYS_CTR_COMPARE base pointer */
#define SYS_CTR_COMPARE                          ((SYS_CTR_COMPARE_Type *)SYS_CTR_COMPARE_BASE)
/** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
#define SYS_CTR_COMPARE_BASE_ADDRS               { SYS_CTR_COMPARE_BASE }
/** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
#define SYS_CTR_COMPARE_BASE_PTRS                { SYS_CTR_COMPARE }

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
/** Peripheral SYS_CTR_READ base address */
#define SYS_CTR_READ_BASE                        (0x442B0000u)
/** Peripheral SYS_CTR_READ base pointer */
#define SYS_CTR_READ                             ((SYS_CTR_READ_Type *)SYS_CTR_READ_BASE)
/** Array initializer of SYS_CTR_READ peripheral base addresses */
#define SYS_CTR_READ_BASE_ADDRS                  { SYS_CTR_READ_BASE }
/** Array initializer of SYS_CTR_READ peripheral base pointers */
#define SYS_CTR_READ_BASE_PTRS                   { SYS_CTR_READ }

/* TCM_ECC_MCM - Peripheral instance base addresses */
/** Peripheral CP_CM33_IMX9RTC__CM33_TCM_MCM base address */
#define CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE       (0x44420000u)
/** Peripheral CP_CM33_IMX9RTC__CM33_TCM_MCM base pointer */
#define CP_CM33_IMX9RTC__CM33_TCM_MCM            ((TCM_ECC_MCM_Type *)CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE)
/** Array initializer of TCM_ECC_MCM peripheral base addresses */
#define TCM_ECC_MCM_BASE_ADDRS                   { CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE }
/** Array initializer of TCM_ECC_MCM peripheral base pointers */
#define TCM_ECC_MCM_BASE_PTRS                    { CP_CM33_IMX9RTC__CM33_TCM_MCM }

/* TMPSNS - Peripheral instance base addresses */
/** Peripheral TMPSNS base address */
#define TMPSNS_BASE                              (0x44484580u)
/** Peripheral TMPSNS base pointer */
#define TMPSNS                                   ((TMPSNS_Type *)TMPSNS_BASE)
/** Array initializer of TMPSNS peripheral base addresses */
#define TMPSNS_BASE_ADDRS                        { TMPSNS_BASE }
/** Array initializer of TMPSNS peripheral base pointers */
#define TMPSNS_BASE_PTRS                         { TMPSNS }

/* TMR - Peripheral instance base addresses */
/** Peripheral TMR1 base address */
#define TMR1_BASE                                (0x42690000u)
/** Peripheral TMR1 base pointer */
#define TMR1                                     ((TMR_Type *)TMR1_BASE)
/** Peripheral TMR2 base address */
#define TMR2_BASE                                (0x426A0000u)
/** Peripheral TMR2 base pointer */
#define TMR2                                     ((TMR_Type *)TMR2_BASE)
/** Peripheral TMR3 base address */
#define TMR3_BASE                                (0x426B0000u)
/** Peripheral TMR3 base pointer */
#define TMR3                                     ((TMR_Type *)TMR3_BASE)
/** Peripheral TMR4 base address */
#define TMR4_BASE                                (0x426C0000u)
/** Peripheral TMR4 base pointer */
#define TMR4                                     ((TMR_Type *)TMR4_BASE)
/** Peripheral TMR5 base address */
#define TMR5_BASE                                (0x426D0000u)
/** Peripheral TMR5 base pointer */
#define TMR5                                     ((TMR_Type *)TMR5_BASE)
/** Peripheral TMR6 base address */
#define TMR6_BASE                                (0x426E0000u)
/** Peripheral TMR6 base pointer */
#define TMR6                                     ((TMR_Type *)TMR6_BASE)
/** Peripheral TMR7 base address */
#define TMR7_BASE                                (0x426F0000u)
/** Peripheral TMR7 base pointer */
#define TMR7                                     ((TMR_Type *)TMR7_BASE)
/** Peripheral TMR8 base address */
#define TMR8_BASE                                (0x42700000u)
/** Peripheral TMR8 base pointer */
#define TMR8                                     ((TMR_Type *)TMR8_BASE)
/** Array initializer of TMR peripheral base addresses */
#define TMR_BASE_ADDRS                           { 0u, TMR1_BASE, TMR2_BASE, TMR3_BASE, TMR4_BASE, TMR5_BASE, TMR6_BASE, TMR7_BASE, TMR8_BASE }
/** Array initializer of TMR peripheral base pointers */
#define TMR_BASE_PTRS                            { (TMR_Type *)0u, TMR1, TMR2, TMR3, TMR4, TMR5, TMR6, TMR7, TMR8 }
/** Interrupt vectors for the TMR peripheral type */
#define TMR_IRQS                                 { NotAvail_IRQn, TMR1_IRQn, TMR2_IRQn, TMR3_IRQn, TMR4_IRQn, TMR5_IRQn, TMR6_IRQn, TMR7_IRQn, TMR8_IRQn }

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

/* TRDC - Peripheral instance base addresses */
/** Peripheral TRDC1 base address */
#define TRDC1_BASE                               (0x44270000u)
/** Peripheral TRDC1 base pointer */
#define TRDC1                                    ((TRDC_Type *)TRDC1_BASE)
/** Peripheral TRDC2 base address */
#define TRDC2_BASE                               (0x42460000u)
/** Peripheral TRDC2 base pointer */
#define TRDC2                                    ((TRDC_Type *)TRDC2_BASE)
/** Peripheral TRDC3 base address */
#define TRDC3_BASE                               (0x42810000u)
/** Peripheral TRDC3 base pointer */
#define TRDC3                                    ((TRDC_Type *)TRDC3_BASE)
/** Array initializer of TRDC peripheral base addresses */
#define TRDC_BASE_ADDRS                          { 0u, TRDC1_BASE, TRDC2_BASE, TRDC3_BASE }
/** Array initializer of TRDC peripheral base pointers */
#define TRDC_BASE_PTRS                           { (TRDC_Type *)0u, TRDC1, TRDC2, TRDC3 }
/** Interrupt vectors for the TRDC peripheral type */
#define TRDC_IRQS                                { NotAvail_IRQn, TRDC_MGR_AON_IRQn, TRDC_MGR_WKUP_IRQn, TRDC_MGR_MEGA_IRQn }

/* TSTMR - Peripheral instance base addresses */
/** Peripheral TSTMR1_TSTMRA base address */
#define TSTMR1_TSTMRA_BASE                       (0x442C0000u)
/** Peripheral TSTMR1_TSTMRA base pointer */
#define TSTMR1_TSTMRA                            ((TSTMR_Type *)TSTMR1_TSTMRA_BASE)
/** Peripheral TSTMR2_TSTMRA base address */
#define TSTMR2_TSTMRA_BASE                       (0x42480000u)
/** Peripheral TSTMR2_TSTMRA base pointer */
#define TSTMR2_TSTMRA                            ((TSTMR_Type *)TSTMR2_TSTMRA_BASE)
/** Array initializer of TSTMR peripheral base addresses */
#define TSTMR_BASE_ADDRS                         { TSTMR1_TSTMRA_BASE, TSTMR2_TSTMRA_BASE }
/** Array initializer of TSTMR peripheral base pointers */
#define TSTMR_BASE_PTRS                          { TSTMR1_TSTMRA, TSTMR2_TSTMRA }

/* USB - Peripheral instance base addresses */
/** Peripheral USB_OTG1 base address */
#define USB_OTG1_BASE                            (0x42C80000u)
/** Peripheral USB_OTG1 base pointer */
#define USB_OTG1                                 ((USB_Type *)USB_OTG1_BASE)
/** Peripheral USB_OTG2 base address */
#define USB_OTG2_BASE                            (0x42C90000u)
/** Peripheral USB_OTG2 base pointer */
#define USB_OTG2                                 ((USB_Type *)USB_OTG2_BASE)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { 0u, USB_OTG1_BASE, USB_OTG2_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { (USB_Type *)0u, USB_OTG1, USB_OTG2 }
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { NotAvail_IRQn, USB_OTG1_IRQn, USB_OTG2_IRQn }

/* USBHSDCD - Peripheral instance base addresses */
/** Peripheral USBHSDCD1 base address */
#define USBHSDCD1_BASE                           (0x42CA0800u)
/** Peripheral USBHSDCD1 base pointer */
#define USBHSDCD1                                ((USBHSDCD_Type *)USBHSDCD1_BASE)
/** Peripheral USBHSDCD2 base address */
#define USBHSDCD2_BASE                           (0x42CB0800u)
/** Peripheral USBHSDCD2 base pointer */
#define USBHSDCD2                                ((USBHSDCD_Type *)USBHSDCD2_BASE)
/** Array initializer of USBHSDCD peripheral base addresses */
#define USBHSDCD_BASE_ADDRS                      { 0u, USBHSDCD1_BASE, USBHSDCD2_BASE }
/** Array initializer of USBHSDCD peripheral base pointers */
#define USBHSDCD_BASE_PTRS                       { (USBHSDCD_Type *)0u, USBHSDCD1, USBHSDCD2 }
/* Backward compatibility */
#define USBHSDCD_STACK_BASE_ADDRS                { USBHSDCD1_BASE, USBHSDCD2_BASE }


/* USBNC - Peripheral instance base addresses */
/** Peripheral USBNC_OTG1 base address */
#define USBNC_OTG1_BASE                          (0x42C80200u)
/** Peripheral USBNC_OTG1 base pointer */
#define USBNC_OTG1                               ((USBNC_Type *)USBNC_OTG1_BASE)
/** Peripheral USBNC_OTG2 base address */
#define USBNC_OTG2_BASE                          (0x42C90200u)
/** Peripheral USBNC_OTG2 base pointer */
#define USBNC_OTG2                               ((USBNC_Type *)USBNC_OTG2_BASE)
/** Array initializer of USBNC peripheral base addresses */
#define USBNC_BASE_ADDRS                         { 0u, USBNC_OTG1_BASE, USBNC_OTG2_BASE }
/** Array initializer of USBNC peripheral base pointers */
#define USBNC_BASE_PTRS                          { (USBNC_Type *)0u, USBNC_OTG1, USBNC_OTG2 }
/* Backward compatibility */
#define USB_OTGn_CTRL     CTRL1
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_MASK     USBNC_CTRL1_OVER_CUR_DIS_MASK
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_SHIFT     USBNC_CTRL1_OVER_CUR_DIS_SHIFT
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS(x)     USBNC_CTRL1_OVER_CUR_DIS(x)
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_MASK     USBNC_CTRL1_OVER_CUR_POL_MASK
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_SHIFT     USBNC_CTRL1_OVER_CUR_POL_SHIFT
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL(x)     USBNC_CTRL1_OVER_CUR_POL(x)
#define USBNC_USB_OTGn_CTRL_PWR_POL_MASK     USBNC_CTRL1_PWR_POL_MASK
#define USBNC_USB_OTGn_CTRL_PWR_POL_SHIFT     USBNC_CTRL1_PWR_POL_SHIFT
#define USBNC_USB_OTGn_CTRL_PWR_POL(x)     USBNC_CTRL1_PWR_POL(x)
#define USBNC_USB_OTGn_CTRL_WIE_MASK     USBNC_CTRL1_WIE_MASK
#define USBNC_USB_OTGn_CTRL_WIE_SHIFT     USBNC_CTRL1_WIE_SHIFT
#define USBNC_USB_OTGn_CTRL_WIE(x)     USBNC_CTRL1_WIE(x)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_MASK     USBNC_CTRL1_WKUP_SW_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_SHIFT     USBNC_CTRL1_WKUP_SW_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN(x)     USBNC_CTRL1_WKUP_SW_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_MASK     USBNC_CTRL1_WKUP_SW_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_SW_SHIFT     USBNC_CTRL1_WKUP_SW_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_SW(x)     USBNC_CTRL1_WKUP_SW(x)
#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN_MASK     USBNC_CTRL1_WKUP_ID_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN_SHIFT     USBNC_CTRL1_WKUP_ID_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN(x)     USBNC_CTRL1_WKUP_ID_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_MASK     USBNC_CTRL1_WKUP_VBUS_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_SHIFT     USBNC_CTRL1_WKUP_VBUS_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN(x)     USBNC_CTRL1_WKUP_VBUS_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_MASK     USBNC_CTRL1_WKUP_DPDM_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_SHIFT     USBNC_CTRL1_WKUP_DPDM_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN(x)     USBNC_CTRL1_WKUP_DPDM_EN(x)
#define USBNC_USB_OTGn_CTRL_WIR_MASK     USBNC_CTRL1_WIR_MASK
#define USBNC_USB_OTGn_CTRL_WIR_SHIFT     USBNC_CTRL1_WIR_SHIFT
#define USBNC_USB_OTGn_CTRL_WIR(x)     USBNC_CTRL1_WIR(x)
#define USBNC_STACK_BASE_ADDRS                { USBNC_OTG1_BASE, USBNC_OTG2_BASE }


/* USBPHY - Peripheral instance base addresses */
/** Peripheral USBPHY1 base address */
#define USBPHY1_BASE                             (0x42CA0000u)
/** Peripheral USBPHY1 base pointer */
#define USBPHY1                                  ((USBPHY_Type *)USBPHY1_BASE)
/** Peripheral USBPHY2 base address */
#define USBPHY2_BASE                             (0x42CB0000u)
/** Peripheral USBPHY2 base pointer */
#define USBPHY2                                  ((USBPHY_Type *)USBPHY2_BASE)
/** Array initializer of USBPHY peripheral base addresses */
#define USBPHY_BASE_ADDRS                        { 0u, USBPHY1_BASE, USBPHY2_BASE }
/** Array initializer of USBPHY peripheral base pointers */
#define USBPHY_BASE_PTRS                         { (USBPHY_Type *)0u, USBPHY1, USBPHY2 }
/** Interrupt vectors for the USBPHY peripheral type */
#define USBPHY_IRQS                              { NotAvail_IRQn, USBPHY1_IRQn, USBPHY2_IRQn }
/* Backward compatibility */
#define USBPHY_CTRL_ENDEVPLUGINDET_MASK     USBPHY_CTRL_ENDEVPLUGINDETECT_MASK
#define USBPHY_CTRL_ENDEVPLUGINDET_SHIFT    USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT
#define USBPHY_CTRL_ENDEVPLUGINDET(x)       USBPHY_CTRL_ENDEVPLUGINDETECT(x)
#define USBPHY_TX_TXCAL45DM_MASK            USBPHY_TX_TXCAL45DN_MASK
#define USBPHY_TX_TXCAL45DM_SHIFT           USBPHY_TX_TXCAL45DN_SHIFT
#define USBPHY_TX_TXCAL45DM(x)              USBPHY_TX_TXCAL45DN(x)

#define USBPHY_STACK_BASE_ADDRS             { USBPHY1_BASE, USBPHY2_BASE }


/* USDHC - Peripheral instance base addresses */
/** Peripheral USDHC1 base address */
#define USDHC1_BASE                              (0x42850000u)
/** Peripheral USDHC1 base pointer */
#define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
/** Peripheral USDHC2 base address */
#define USDHC2_BASE                              (0x42860000u)
/** Peripheral USDHC2 base pointer */
#define USDHC2                                   ((USDHC_Type *)USDHC2_BASE)
/** Array initializer of USDHC peripheral base addresses */
#define USDHC_BASE_ADDRS                         { 0u, USDHC1_BASE, USDHC2_BASE }
/** Array initializer of USDHC peripheral base pointers */
#define USDHC_BASE_PTRS                          { (USDHC_Type *)0u, USDHC1, USDHC2 }
/** Interrupt vectors for the USDHC peripheral type */
#define USDHC_IRQS                               { NotAvail_IRQn, USDHC1_IRQn, USDHC2_IRQn }

/* VMBANDGAP - Peripheral instance base addresses */
/** Peripheral VMBANDGAP base address */
#define VMBANDGAP_BASE                           (0x44484780u)
/** Peripheral VMBANDGAP base pointer */
#define VMBANDGAP                                ((VMBANDGAP_Type *)VMBANDGAP_BASE)
/** Array initializer of VMBANDGAP peripheral base addresses */
#define VMBANDGAP_BASE_ADDRS                     { VMBANDGAP_BASE }
/** Array initializer of VMBANDGAP peripheral base pointers */
#define VMBANDGAP_BASE_PTRS                      { VMBANDGAP }

/* VREF - Peripheral instance base addresses */
/** Peripheral VREF base address */
#define VREF_BASE                                (0x42E30000u)
/** Peripheral VREF base pointer */
#define VREF                                     ((VREF_Type *)VREF_BASE)
/** Array initializer of VREF peripheral base addresses */
#define VREF_BASE_ADDRS                          { VREF_BASE }
/** Array initializer of VREF peripheral base pointers */
#define VREF_BASE_PTRS                           { VREF }

/* XBAR_NUM_OUT221 - Peripheral instance base addresses */
/** Peripheral XBAR1 base address */
#define XBAR1_BASE                               (0x42750000u)
/** Peripheral XBAR1 base pointer */
#define XBAR1                                    ((XBAR_NUM_OUT221_Type *)XBAR1_BASE)
/** Array initializer of XBAR_NUM_OUT221 peripheral base addresses */
#define XBAR_NUM_OUT221_BASE_ADDRS               { XBAR1_BASE }
/** Array initializer of XBAR_NUM_OUT221 peripheral base pointers */
#define XBAR_NUM_OUT221_BASE_PTRS                { XBAR1 }

/* XBAR_NUM_OUT32 - Peripheral instance base addresses */
/** Peripheral XBAR2 base address */
#define XBAR2_BASE                               (0x42760000u)
/** Peripheral XBAR2 base pointer */
#define XBAR2                                    ((XBAR_NUM_OUT32_Type *)XBAR2_BASE)
/** Peripheral XBAR3 base address */
#define XBAR3_BASE                               (0x42770000u)
/** Peripheral XBAR3 base pointer */
#define XBAR3                                    ((XBAR_NUM_OUT32_Type *)XBAR3_BASE)
/** Array initializer of XBAR_NUM_OUT32 peripheral base addresses */
#define XBAR_NUM_OUT32_BASE_ADDRS                { XBAR2_BASE, XBAR3_BASE }
/** Array initializer of XBAR_NUM_OUT32 peripheral base pointers */
#define XBAR_NUM_OUT32_BASE_PTRS                 { XBAR2, XBAR3 }

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


#endif  /* MIMXRT1189_CM7_COMMON_H_ */

