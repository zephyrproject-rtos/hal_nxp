/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181XVP2B
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
**         CMSIS Peripheral Access Layer for MIMXRT1181
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
 * @file MIMXRT1181_COMMON.h
 * @version 2.0
 * @date 2024-01-18
 * @brief CMSIS Peripheral Access Layer for MIMXRT1181
 *
 * CMSIS Peripheral Access Layer for MIMXRT1181
 */

#if !defined(MIMXRT1181_COMMON_H_)
#define MIMXRT1181_COMMON_H_                     /**< Symbol preventing repeated inclusion */

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
  TMR1_IRQn                    = 0,                /**< TMR1 interrupt */
  DAP_IRQn                     = 1,                /**< DAP interrupt */
  M7_CTI_TRIGGER_OUTPUT_IRQn   = 2,                /**< CTI trigger outputs from CM7 */
  M33_CTI_TRIGGER_OUTPUT_IRQn  = 3,                /**< CTI trigger outputs from CM33 */
  Reserved20_IRQn              = 4,                /**< Reserved interrupt */
  Reserved21_IRQn              = 5,                /**< Reserved interrupt */
  Reserved22_IRQn              = 6,                /**< Reserved interrupt */
  Reserved23_IRQn              = 7,                /**< Reserved interrupt */
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
  Reserved79_IRQn              = 63,               /**< Reserved interrupt */
  LPIT2_IRQn                   = 64,               /**< LPIT2 interrupt */
  LPSPI3_IRQn                  = 65,               /**< LPSPI3 interrupt */
  LPSPI4_IRQn                  = 66,               /**< LPSPI4 interrupt */
  Reserved83_IRQn              = 67,               /**< Reserved interrupt */
  LPUART3_IRQn                 = 68,               /**< LPUART3 interrupt */
  LPUART4_IRQn                 = 69,               /**< LPUART4 interrupt */
  LPUART5_IRQn                 = 70,               /**< LPUART5 interrupt */
  LPUART6_IRQn                 = 71,               /**< LPUART6 interrupt */
  Reserved88_IRQn              = 72,               /**< Reserved interrupt 88 */
  BBNSM_IRQn                   = 73,               /**< BBNSM iterrupt */
  SYS_CTR1_IRQn                = 74,               /**< System Counter compare interrupt 0 and 1 */
  TPM3_IRQn                    = 75,               /**< TPM3 interrupt */
  Reserved92_IRQn              = 76,               /**< Reserved interrupt */
  Reserved93_IRQn              = 77,               /**< Reserved interrupt */
  Reserved94_IRQn              = 78,               /**< Reserved interrupt */
  RTWDOG3_IRQn                 = 79,               /**< RTWDOG3 interrupt */
  RTWDOG4_IRQn                 = 80,               /**< RTWDOG4 interrupt */
  RTWDOG5_IRQn                 = 81,               /**< RTWDOG5 interrupt */
  TRDC_MGR_WKUP_IRQn           = 82,               /**< WAKEUPMIX TRDC transfer error interrupt */
  TMPSNS_INT_IRQn              = 83,               /**< Temperature alarm interrupt */
  BBSM_IRQn                    = 84,               /**< BBSM wakeup alarm interrupt */
  LDO_AON_ANA_IRQn             = 85,               /**< Brown out interrupt */
  USDHC1_IRQn                  = 86,               /**< USDHC1 */
  Reserved103_IRQn             = 87,               /**< Reserved interrupt */
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
  Reserved162_IRQn             = 146,              /**< Reserved interrupt */
  EWM_IRQn                     = 147,              /**< EWM reset out interrupt */
  Reserved164_IRQn             = 148,              /**< Reserved interrupt */
  LPIT3_IRQn                   = 149,              /**< LPIT3 interrupt */
  Reserved166_IRQn             = 150,              /**< Reserved interrupt */
  TMR4_IRQn                    = 151,              /**< TMR4 interrupt */
  Reserved168_IRQn             = 152,              /**< Reserved interrupt */
  Reserved169_IRQn             = 153,              /**< Reserved interrupt */
  SAI4_IRQn                    = 154,              /**< SAI4 interrupt */
  SPDIF_IRQn                   = 155,              /**< SPDIF interrupt */
  Reserved172_IRQn             = 156,              /**< Reserved interrupt */
  Reserved173_IRQn             = 157,              /**< Reserved interrupt */
  Reserved174_IRQn             = 158,              /**< Reserved interrupt */
  Reserved175_IRQn             = 159,              /**< Reserved interrupt */
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
  Reserved191_IRQn             = 175,              /**< Reserved interrupt */
  Reserved192_IRQn             = 176,              /**< Reserved interrupt */
  Reserved193_IRQn             = 177,              /**< Reserved interrupt */
  Reserved194_IRQn             = 178,              /**< Reserved interrupt */
  Reserved195_IRQn             = 179,              /**< Reserved interrupt */
  Reserved196_IRQn             = 180,              /**< Reserved interrupt */
  Reserved197_IRQn             = 181,              /**< Reserved interrupt */
  Reserved198_IRQn             = 182,              /**< Reserved interrupt */
  Reserved199_IRQn             = 183,              /**< Reserved interrupt */
  Reserved200_IRQn             = 184,              /**< Reserved interrupt */
  EQDC1_IRQn                   = 185,              /**< EQDC1 interrupt */
  EQDC2_IRQn                   = 186,              /**< EQDC2 interrupt */
  Reserved203_IRQn             = 187,              /**< Reserved interrupt */
  Reserved204_IRQn             = 188,              /**< Reserved interrupt */
  Reserved205_IRQn             = 189,              /**< Reserved interrupt */
  DCDC_IRQn                    = 190,              /**< DCDC brown out interrupt */
  Reserved207_IRQn             = 191,              /**< Reserved interrupt */
  Reserved208_IRQn             = 192,              /**< Reserved interrupt */
  DAC_IRQn                     = 193,              /**< DAC interrupt */
  Reserved210_IRQn             = 194,              /**< Reserved interrupt */
  Reserved211_IRQn             = 195,              /**< Reserved interrupt */
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
  Reserved223_IRQn             = 207,              /**< Reserved interrupt */
  SAFETY_CLK_MON_IRQn          = 208,              /**< Safety clock monitor interrupt */
  GPT1_IRQn                    = 209,              /**< GPT1 interrupt */
  GPT2_IRQn                    = 210,              /**< GPT2 interrupt */
  KPP_IRQn                     = 211,              /**< KPP interrupt */
  Reserved228_IRQn             = 212,              /**< Reserved interrupt */
  Reserved229_IRQn             = 213,              /**< Reserved interrupt */
  Reserved230_IRQn             = 214,              /**< Reserved interrupt */
  Reserved231_IRQn             = 215,              /**< Reserved interrupt */
  FLEXSPI_SLV_IRQn             = 216,              /**< FLEXSPI follower interrupt */
  NETC_IRQn                    = 217,              /**< NETC interrupt */
  MSGINTR1_IRQn                = 218,              /**< MSGINTR1 interrupt */
  MSGINTR2_IRQn                = 219,              /**< MSGINTR2 interrupt */
  MSGINTR3_IRQn                = 220,              /**< MSGINTR3 interrupt */
  MSGINTR4_IRQn                = 221,              /**< MSGINTR4 interrupt */
  MSGINTR5_IRQn                = 222,              /**< MSGINTR5 interrupt */
  MSGINTR6_IRQn                = 223,              /**< MSGINTR6 interrupt */
  Reserved240_IRQn             = 224,              /**< Reserved interrupt */
  Reserved241_IRQn             = 225,              /**< Reserved interrupt */
  Reserved242_IRQn             = 226,              /**< Reserved interrupt */
  Reserved243_IRQn             = 227,              /**< Reserved interrupt */
  Reserved244_IRQn             = 228,              /**< Reserved interrupt */
  Reserved245_IRQn             = 229,              /**< Reserved interrupt */
  Reserved246_IRQn             = 230,              /**< Reserved interrupt */
  Reserved247_IRQn             = 231,              /**< Reserved interrupt */
  GPIO4_IRQn                   = 232,              /**< GPIO4 interrupt */
  TMR2_IRQn                    = 233,              /**< TMR2 interrupt */
  GPIO5_IRQn                   = 234,              /**< GPIO5 interrupt */
  ASRC_IRQn                    = 235,              /**< ASRC interrupt */
  GPIO6_IRQn                   = 236,              /**< GPIO6 interrupt */
  DBG_TRACE_IRQn               = 237,              /**< JTAGSW DAP MDM-AP SRC reset source */
  Reserved254_IRQn             = 238               /**< Reserved interrupt */
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
#include "system_MIMXRT1181.h"         /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#define MIMXRT1181_SERIES
/* CPU specific feature definitions */
#include "MIMXRT1181_features.h"

/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADC1 base address */
  #define ADC1_BASE                                (0x52600000u)
  /** Peripheral ADC1 base address */
  #define ADC1_BASE_NS                             (0x42600000u)
  /** Peripheral ADC1 base pointer */
  #define ADC1                                     ((ADC_Type *)ADC1_BASE)
  /** Peripheral ADC1 base pointer */
  #define ADC1_NS                                  ((ADC_Type *)ADC1_BASE_NS)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { 0u, ADC1_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { (ADC_Type *)0u, ADC1 }
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS_NS                        { 0u, ADC1_BASE_NS }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS_NS                         { (ADC_Type *)0u, ADC1_NS }
#else
  /** Peripheral ADC1 base address */
  #define ADC1_BASE                                (0x42600000u)
  /** Peripheral ADC1 base pointer */
  #define ADC1                                     ((ADC_Type *)ADC1_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { 0u, ADC1_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { (ADC_Type *)0u, ADC1 }
#endif
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { NotAvail_IRQn, ADC1_IRQn }

/* ANADIG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANADIG_SLOTS base address */
  #define ANADIG_SLOTS_BASE                        (0x54480000u)
  /** Peripheral ANADIG_SLOTS base address */
  #define ANADIG_SLOTS_BASE_NS                     (0x44480000u)
  /** Peripheral ANADIG_SLOTS base pointer */
  #define ANADIG_SLOTS                             ((ANADIG_Type *)ANADIG_SLOTS_BASE)
  /** Peripheral ANADIG_SLOTS base pointer */
  #define ANADIG_SLOTS_NS                          ((ANADIG_Type *)ANADIG_SLOTS_BASE_NS)
  /** Array initializer of ANADIG peripheral base addresses */
  #define ANADIG_BASE_ADDRS                        { ANADIG_SLOTS_BASE }
  /** Array initializer of ANADIG peripheral base pointers */
  #define ANADIG_BASE_PTRS                         { ANADIG_SLOTS }
  /** Array initializer of ANADIG peripheral base addresses */
  #define ANADIG_BASE_ADDRS_NS                     { ANADIG_SLOTS_BASE_NS }
  /** Array initializer of ANADIG peripheral base pointers */
  #define ANADIG_BASE_PTRS_NS                      { ANADIG_SLOTS_NS }
#else
  /** Peripheral ANADIG_SLOTS base address */
  #define ANADIG_SLOTS_BASE                        (0x44480000u)
  /** Peripheral ANADIG_SLOTS base pointer */
  #define ANADIG_SLOTS                             ((ANADIG_Type *)ANADIG_SLOTS_BASE)
  /** Array initializer of ANADIG peripheral base addresses */
  #define ANADIG_BASE_ADDRS                        { ANADIG_SLOTS_BASE }
  /** Array initializer of ANADIG peripheral base pointers */
  #define ANADIG_BASE_PTRS                         { ANADIG_SLOTS }
#endif

/* ANADIG_LDO_BBSM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANADIG_LDO_BBSM base address */
  #define ANADIG_LDO_BBSM_BASE                     (0x54480000u)
  /** Peripheral ANADIG_LDO_BBSM base address */
  #define ANADIG_LDO_BBSM_BASE_NS                  (0x44480000u)
  /** Peripheral ANADIG_LDO_BBSM base pointer */
  #define ANADIG_LDO_BBSM                          ((ANADIG_LDO_BBSM_Type *)ANADIG_LDO_BBSM_BASE)
  /** Peripheral ANADIG_LDO_BBSM base pointer */
  #define ANADIG_LDO_BBSM_NS                       ((ANADIG_LDO_BBSM_Type *)ANADIG_LDO_BBSM_BASE_NS)
  /** Array initializer of ANADIG_LDO_BBSM peripheral base addresses */
  #define ANADIG_LDO_BBSM_BASE_ADDRS               { ANADIG_LDO_BBSM_BASE }
  /** Array initializer of ANADIG_LDO_BBSM peripheral base pointers */
  #define ANADIG_LDO_BBSM_BASE_PTRS                { ANADIG_LDO_BBSM }
  /** Array initializer of ANADIG_LDO_BBSM peripheral base addresses */
  #define ANADIG_LDO_BBSM_BASE_ADDRS_NS            { ANADIG_LDO_BBSM_BASE_NS }
  /** Array initializer of ANADIG_LDO_BBSM peripheral base pointers */
  #define ANADIG_LDO_BBSM_BASE_PTRS_NS             { ANADIG_LDO_BBSM_NS }
#else
  /** Peripheral ANADIG_LDO_BBSM base address */
  #define ANADIG_LDO_BBSM_BASE                     (0x44480000u)
  /** Peripheral ANADIG_LDO_BBSM base pointer */
  #define ANADIG_LDO_BBSM                          ((ANADIG_LDO_BBSM_Type *)ANADIG_LDO_BBSM_BASE)
  /** Array initializer of ANADIG_LDO_BBSM peripheral base addresses */
  #define ANADIG_LDO_BBSM_BASE_ADDRS               { ANADIG_LDO_BBSM_BASE }
  /** Array initializer of ANADIG_LDO_BBSM peripheral base pointers */
  #define ANADIG_LDO_BBSM_BASE_PTRS                { ANADIG_LDO_BBSM }
#endif

/* ANADIG_MISC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANADIG_MISC base address */
  #define ANADIG_MISC_BASE                         (0x54480000u)
  /** Peripheral ANADIG_MISC base address */
  #define ANADIG_MISC_BASE_NS                      (0x44480000u)
  /** Peripheral ANADIG_MISC base pointer */
  #define ANADIG_MISC                              ((ANADIG_MISC_Type *)ANADIG_MISC_BASE)
  /** Peripheral ANADIG_MISC base pointer */
  #define ANADIG_MISC_NS                           ((ANADIG_MISC_Type *)ANADIG_MISC_BASE_NS)
  /** Array initializer of ANADIG_MISC peripheral base addresses */
  #define ANADIG_MISC_BASE_ADDRS                   { ANADIG_MISC_BASE }
  /** Array initializer of ANADIG_MISC peripheral base pointers */
  #define ANADIG_MISC_BASE_PTRS                    { ANADIG_MISC }
  /** Array initializer of ANADIG_MISC peripheral base addresses */
  #define ANADIG_MISC_BASE_ADDRS_NS                { ANADIG_MISC_BASE_NS }
  /** Array initializer of ANADIG_MISC peripheral base pointers */
  #define ANADIG_MISC_BASE_PTRS_NS                 { ANADIG_MISC_NS }
#else
  /** Peripheral ANADIG_MISC base address */
  #define ANADIG_MISC_BASE                         (0x44480000u)
  /** Peripheral ANADIG_MISC base pointer */
  #define ANADIG_MISC                              ((ANADIG_MISC_Type *)ANADIG_MISC_BASE)
  /** Array initializer of ANADIG_MISC peripheral base addresses */
  #define ANADIG_MISC_BASE_ADDRS                   { ANADIG_MISC_BASE }
  /** Array initializer of ANADIG_MISC peripheral base pointers */
  #define ANADIG_MISC_BASE_PTRS                    { ANADIG_MISC }
#endif

/* ANADIG_OSC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANADIG_OSC base address */
  #define ANADIG_OSC_BASE                          (0x54480000u)
  /** Peripheral ANADIG_OSC base address */
  #define ANADIG_OSC_BASE_NS                       (0x44480000u)
  /** Peripheral ANADIG_OSC base pointer */
  #define ANADIG_OSC                               ((ANADIG_OSC_Type *)ANADIG_OSC_BASE)
  /** Peripheral ANADIG_OSC base pointer */
  #define ANADIG_OSC_NS                            ((ANADIG_OSC_Type *)ANADIG_OSC_BASE_NS)
  /** Array initializer of ANADIG_OSC peripheral base addresses */
  #define ANADIG_OSC_BASE_ADDRS                    { ANADIG_OSC_BASE }
  /** Array initializer of ANADIG_OSC peripheral base pointers */
  #define ANADIG_OSC_BASE_PTRS                     { ANADIG_OSC }
  /** Array initializer of ANADIG_OSC peripheral base addresses */
  #define ANADIG_OSC_BASE_ADDRS_NS                 { ANADIG_OSC_BASE_NS }
  /** Array initializer of ANADIG_OSC peripheral base pointers */
  #define ANADIG_OSC_BASE_PTRS_NS                  { ANADIG_OSC_NS }
#else
  /** Peripheral ANADIG_OSC base address */
  #define ANADIG_OSC_BASE                          (0x44480000u)
  /** Peripheral ANADIG_OSC base pointer */
  #define ANADIG_OSC                               ((ANADIG_OSC_Type *)ANADIG_OSC_BASE)
  /** Array initializer of ANADIG_OSC peripheral base addresses */
  #define ANADIG_OSC_BASE_ADDRS                    { ANADIG_OSC_BASE }
  /** Array initializer of ANADIG_OSC peripheral base pointers */
  #define ANADIG_OSC_BASE_PTRS                     { ANADIG_OSC }
#endif

/* ANADIG_PLL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANADIG_PLL base address */
  #define ANADIG_PLL_BASE                          (0x54480000u)
  /** Peripheral ANADIG_PLL base address */
  #define ANADIG_PLL_BASE_NS                       (0x44480000u)
  /** Peripheral ANADIG_PLL base pointer */
  #define ANADIG_PLL                               ((ANADIG_PLL_Type *)ANADIG_PLL_BASE)
  /** Peripheral ANADIG_PLL base pointer */
  #define ANADIG_PLL_NS                            ((ANADIG_PLL_Type *)ANADIG_PLL_BASE_NS)
  /** Array initializer of ANADIG_PLL peripheral base addresses */
  #define ANADIG_PLL_BASE_ADDRS                    { ANADIG_PLL_BASE }
  /** Array initializer of ANADIG_PLL peripheral base pointers */
  #define ANADIG_PLL_BASE_PTRS                     { ANADIG_PLL }
  /** Array initializer of ANADIG_PLL peripheral base addresses */
  #define ANADIG_PLL_BASE_ADDRS_NS                 { ANADIG_PLL_BASE_NS }
  /** Array initializer of ANADIG_PLL peripheral base pointers */
  #define ANADIG_PLL_BASE_PTRS_NS                  { ANADIG_PLL_NS }
#else
  /** Peripheral ANADIG_PLL base address */
  #define ANADIG_PLL_BASE                          (0x44480000u)
  /** Peripheral ANADIG_PLL base pointer */
  #define ANADIG_PLL                               ((ANADIG_PLL_Type *)ANADIG_PLL_BASE)
  /** Array initializer of ANADIG_PLL peripheral base addresses */
  #define ANADIG_PLL_BASE_ADDRS                    { ANADIG_PLL_BASE }
  /** Array initializer of ANADIG_PLL peripheral base pointers */
  #define ANADIG_PLL_BASE_PTRS                     { ANADIG_PLL }
#endif

/* ANADIG_PMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANADIG_PMU base address */
  #define ANADIG_PMU_BASE                          (0x54480000u)
  /** Peripheral ANADIG_PMU base address */
  #define ANADIG_PMU_BASE_NS                       (0x44480000u)
  /** Peripheral ANADIG_PMU base pointer */
  #define ANADIG_PMU                               ((ANADIG_PMU_Type *)ANADIG_PMU_BASE)
  /** Peripheral ANADIG_PMU base pointer */
  #define ANADIG_PMU_NS                            ((ANADIG_PMU_Type *)ANADIG_PMU_BASE_NS)
  /** Array initializer of ANADIG_PMU peripheral base addresses */
  #define ANADIG_PMU_BASE_ADDRS                    { ANADIG_PMU_BASE }
  /** Array initializer of ANADIG_PMU peripheral base pointers */
  #define ANADIG_PMU_BASE_PTRS                     { ANADIG_PMU }
  /** Array initializer of ANADIG_PMU peripheral base addresses */
  #define ANADIG_PMU_BASE_ADDRS_NS                 { ANADIG_PMU_BASE_NS }
  /** Array initializer of ANADIG_PMU peripheral base pointers */
  #define ANADIG_PMU_BASE_PTRS_NS                  { ANADIG_PMU_NS }
#else
  /** Peripheral ANADIG_PMU base address */
  #define ANADIG_PMU_BASE                          (0x44480000u)
  /** Peripheral ANADIG_PMU base pointer */
  #define ANADIG_PMU                               ((ANADIG_PMU_Type *)ANADIG_PMU_BASE)
  /** Array initializer of ANADIG_PMU peripheral base addresses */
  #define ANADIG_PMU_BASE_ADDRS                    { ANADIG_PMU_BASE }
  /** Array initializer of ANADIG_PMU peripheral base pointers */
  #define ANADIG_PMU_BASE_PTRS                     { ANADIG_PMU }
#endif

/* ANADIG_TEMPSENSOR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANADIG_TEMPSENSOR base address */
  #define ANADIG_TEMPSENSOR_BASE                   (0x54480000u)
  /** Peripheral ANADIG_TEMPSENSOR base address */
  #define ANADIG_TEMPSENSOR_BASE_NS                (0x44480000u)
  /** Peripheral ANADIG_TEMPSENSOR base pointer */
  #define ANADIG_TEMPSENSOR                        ((ANADIG_TEMPSENSOR_Type *)ANADIG_TEMPSENSOR_BASE)
  /** Peripheral ANADIG_TEMPSENSOR base pointer */
  #define ANADIG_TEMPSENSOR_NS                     ((ANADIG_TEMPSENSOR_Type *)ANADIG_TEMPSENSOR_BASE_NS)
  /** Array initializer of ANADIG_TEMPSENSOR peripheral base addresses */
  #define ANADIG_TEMPSENSOR_BASE_ADDRS             { ANADIG_TEMPSENSOR_BASE }
  /** Array initializer of ANADIG_TEMPSENSOR peripheral base pointers */
  #define ANADIG_TEMPSENSOR_BASE_PTRS              { ANADIG_TEMPSENSOR }
  /** Array initializer of ANADIG_TEMPSENSOR peripheral base addresses */
  #define ANADIG_TEMPSENSOR_BASE_ADDRS_NS          { ANADIG_TEMPSENSOR_BASE_NS }
  /** Array initializer of ANADIG_TEMPSENSOR peripheral base pointers */
  #define ANADIG_TEMPSENSOR_BASE_PTRS_NS           { ANADIG_TEMPSENSOR_NS }
#else
  /** Peripheral ANADIG_TEMPSENSOR base address */
  #define ANADIG_TEMPSENSOR_BASE                   (0x44480000u)
  /** Peripheral ANADIG_TEMPSENSOR base pointer */
  #define ANADIG_TEMPSENSOR                        ((ANADIG_TEMPSENSOR_Type *)ANADIG_TEMPSENSOR_BASE)
  /** Array initializer of ANADIG_TEMPSENSOR peripheral base addresses */
  #define ANADIG_TEMPSENSOR_BASE_ADDRS             { ANADIG_TEMPSENSOR_BASE }
  /** Array initializer of ANADIG_TEMPSENSOR peripheral base pointers */
  #define ANADIG_TEMPSENSOR_BASE_PTRS              { ANADIG_TEMPSENSOR }
#endif

/* AOI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AOI1 base address */
  #define AOI1_BASE                                (0x52780000u)
  /** Peripheral AOI1 base address */
  #define AOI1_BASE_NS                             (0x42780000u)
  /** Peripheral AOI1 base pointer */
  #define AOI1                                     ((AOI_Type *)AOI1_BASE)
  /** Peripheral AOI1 base pointer */
  #define AOI1_NS                                  ((AOI_Type *)AOI1_BASE_NS)
  /** Peripheral AOI2 base address */
  #define AOI2_BASE                                (0x52790000u)
  /** Peripheral AOI2 base address */
  #define AOI2_BASE_NS                             (0x42790000u)
  /** Peripheral AOI2 base pointer */
  #define AOI2                                     ((AOI_Type *)AOI2_BASE)
  /** Peripheral AOI2 base pointer */
  #define AOI2_NS                                  ((AOI_Type *)AOI2_BASE_NS)
  /** Peripheral AOI3 base address */
  #define AOI3_BASE                                (0x527E0000u)
  /** Peripheral AOI3 base address */
  #define AOI3_BASE_NS                             (0x427E0000u)
  /** Peripheral AOI3 base pointer */
  #define AOI3                                     ((AOI_Type *)AOI3_BASE)
  /** Peripheral AOI3 base pointer */
  #define AOI3_NS                                  ((AOI_Type *)AOI3_BASE_NS)
  /** Peripheral AOI4 base address */
  #define AOI4_BASE                                (0x527F0000u)
  /** Peripheral AOI4 base address */
  #define AOI4_BASE_NS                             (0x427F0000u)
  /** Peripheral AOI4 base pointer */
  #define AOI4                                     ((AOI_Type *)AOI4_BASE)
  /** Peripheral AOI4 base pointer */
  #define AOI4_NS                                  ((AOI_Type *)AOI4_BASE_NS)
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS                           { 0u, AOI1_BASE, AOI2_BASE, AOI3_BASE, AOI4_BASE }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS                            { (AOI_Type *)0u, AOI1, AOI2, AOI3, AOI4 }
  /** Array initializer of AOI peripheral base addresses */
  #define AOI_BASE_ADDRS_NS                        { 0u, AOI1_BASE_NS, AOI2_BASE_NS, AOI3_BASE_NS, AOI4_BASE_NS }
  /** Array initializer of AOI peripheral base pointers */
  #define AOI_BASE_PTRS_NS                         { (AOI_Type *)0u, AOI1_NS, AOI2_NS, AOI3_NS, AOI4_NS }
#else
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
#endif

/* ASRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ASRC base address */
  #define ASRC_BASE                                (0x529A0000u)
  /** Peripheral ASRC base address */
  #define ASRC_BASE_NS                             (0x429A0000u)
  /** Peripheral ASRC base pointer */
  #define ASRC                                     ((ASRC_Type *)ASRC_BASE)
  /** Peripheral ASRC base pointer */
  #define ASRC_NS                                  ((ASRC_Type *)ASRC_BASE_NS)
  /** Array initializer of ASRC peripheral base addresses */
  #define ASRC_BASE_ADDRS                          { ASRC_BASE }
  /** Array initializer of ASRC peripheral base pointers */
  #define ASRC_BASE_PTRS                           { ASRC }
  /** Array initializer of ASRC peripheral base addresses */
  #define ASRC_BASE_ADDRS_NS                       { ASRC_BASE_NS }
  /** Array initializer of ASRC peripheral base pointers */
  #define ASRC_BASE_PTRS_NS                        { ASRC_NS }
#else
  /** Peripheral ASRC base address */
  #define ASRC_BASE                                (0x429A0000u)
  /** Peripheral ASRC base pointer */
  #define ASRC                                     ((ASRC_Type *)ASRC_BASE)
  /** Array initializer of ASRC peripheral base addresses */
  #define ASRC_BASE_ADDRS                          { ASRC_BASE }
  /** Array initializer of ASRC peripheral base pointers */
  #define ASRC_BASE_PTRS                           { ASRC }
#endif
/** Interrupt vectors for the ASRC peripheral type */
#define ASRC_IRQS                                { ASRC_IRQn }

/* AXBS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AXBS base address */
  #define AXBS_BASE                                (0x54510000u)
  /** Peripheral AXBS base address */
  #define AXBS_BASE_NS                             (0x44510000u)
  /** Peripheral AXBS base pointer */
  #define AXBS                                     ((AXBS_Type *)AXBS_BASE)
  /** Peripheral AXBS base pointer */
  #define AXBS_NS                                  ((AXBS_Type *)AXBS_BASE_NS)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { AXBS_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { AXBS }
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS_NS                       { AXBS_BASE_NS }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS_NS                        { AXBS_NS }
#else
  /** Peripheral AXBS base address */
  #define AXBS_BASE                                (0x44510000u)
  /** Peripheral AXBS base pointer */
  #define AXBS                                     ((AXBS_Type *)AXBS_BASE)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { AXBS_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { AXBS }
#endif

/* BBNSM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE                               (0x54440000u)
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE_NS                            (0x44440000u)
  /** Peripheral BBNSM base pointer */
  #define BBNSM                                    ((BBNSM_Type *)BBNSM_BASE)
  /** Peripheral BBNSM base pointer */
  #define BBNSM_NS                                 ((BBNSM_Type *)BBNSM_BASE_NS)
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS                         { BBNSM_BASE }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS                          { BBNSM }
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS_NS                      { BBNSM_BASE_NS }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS_NS                       { BBNSM_NS }
#else
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE                               (0x44440000u)
  /** Peripheral BBNSM base pointer */
  #define BBNSM                                    ((BBNSM_Type *)BBNSM_BASE)
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS                         { BBNSM_BASE }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS                          { BBNSM }
#endif
/** Interrupt vectors for the BBNSM peripheral type */
#define BBNSM_IRQS                               { BBNSM_IRQn }

/* BLK_CTRL_BBSMMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_BBSMMIX base address */
  #define BLK_CTRL_BBSMMIX_BASE                    (0x54410000u)
  /** Peripheral BLK_CTRL_BBSMMIX base address */
  #define BLK_CTRL_BBSMMIX_BASE_NS                 (0x44410000u)
  /** Peripheral BLK_CTRL_BBSMMIX base pointer */
  #define BLK_CTRL_BBSMMIX                         ((BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BASE)
  /** Peripheral BLK_CTRL_BBSMMIX base pointer */
  #define BLK_CTRL_BBSMMIX_NS                      ((BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base addresses */
  #define BLK_CTRL_BBSMMIX_BASE_ADDRS              { BLK_CTRL_BBSMMIX_BASE }
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base pointers */
  #define BLK_CTRL_BBSMMIX_BASE_PTRS               { BLK_CTRL_BBSMMIX }
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base addresses */
  #define BLK_CTRL_BBSMMIX_BASE_ADDRS_NS           { BLK_CTRL_BBSMMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base pointers */
  #define BLK_CTRL_BBSMMIX_BASE_PTRS_NS            { BLK_CTRL_BBSMMIX_NS }
#else
  /** Peripheral BLK_CTRL_BBSMMIX base address */
  #define BLK_CTRL_BBSMMIX_BASE                    (0x44410000u)
  /** Peripheral BLK_CTRL_BBSMMIX base pointer */
  #define BLK_CTRL_BBSMMIX                         ((BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BASE)
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base addresses */
  #define BLK_CTRL_BBSMMIX_BASE_ADDRS              { BLK_CTRL_BBSMMIX_BASE }
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base pointers */
  #define BLK_CTRL_BBSMMIX_BASE_PTRS               { BLK_CTRL_BBSMMIX }
#endif

/* BLK_CTRL_NS_AONMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_NS_AONMIX base address */
  #define BLK_CTRL_NS_AONMIX_BASE                  (0x54210000u)
  /** Peripheral BLK_CTRL_NS_AONMIX base address */
  #define BLK_CTRL_NS_AONMIX_BASE_NS               (0x44210000u)
  /** Peripheral BLK_CTRL_NS_AONMIX base pointer */
  #define BLK_CTRL_NS_AONMIX                       ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX_BASE)
  /** Peripheral BLK_CTRL_NS_AONMIX base pointer */
  #define BLK_CTRL_NS_AONMIX_NS                    ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
  #define BLK_CTRL_NS_AONMIX_BASE_ADDRS            { BLK_CTRL_NS_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
  #define BLK_CTRL_NS_AONMIX_BASE_PTRS             { BLK_CTRL_NS_AONMIX }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
  #define BLK_CTRL_NS_AONMIX_BASE_ADDRS_NS         { BLK_CTRL_NS_AONMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
  #define BLK_CTRL_NS_AONMIX_BASE_PTRS_NS          { BLK_CTRL_NS_AONMIX_NS }
#else
  /** Peripheral BLK_CTRL_NS_AONMIX base address */
  #define BLK_CTRL_NS_AONMIX_BASE                  (0x44210000u)
  /** Peripheral BLK_CTRL_NS_AONMIX base pointer */
  #define BLK_CTRL_NS_AONMIX                       ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX_BASE)
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
  #define BLK_CTRL_NS_AONMIX_BASE_ADDRS            { BLK_CTRL_NS_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
  #define BLK_CTRL_NS_AONMIX_BASE_PTRS             { BLK_CTRL_NS_AONMIX }
#endif

/* BLK_CTRL_S_AONMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_S_AONMIX base address */
  #define BLK_CTRL_S_AONMIX_BASE                   (0x544F0000u)
  /** Peripheral BLK_CTRL_S_AONMIX base address */
  #define BLK_CTRL_S_AONMIX_BASE_NS                (0x444F0000u)
  /** Peripheral BLK_CTRL_S_AONMIX base pointer */
  #define BLK_CTRL_S_AONMIX                        ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX_BASE)
  /** Peripheral BLK_CTRL_S_AONMIX base pointer */
  #define BLK_CTRL_S_AONMIX_NS                     ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
  #define BLK_CTRL_S_AONMIX_BASE_ADDRS             { BLK_CTRL_S_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
  #define BLK_CTRL_S_AONMIX_BASE_PTRS              { BLK_CTRL_S_AONMIX }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
  #define BLK_CTRL_S_AONMIX_BASE_ADDRS_NS          { BLK_CTRL_S_AONMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
  #define BLK_CTRL_S_AONMIX_BASE_PTRS_NS           { BLK_CTRL_S_AONMIX_NS }
#else
  /** Peripheral BLK_CTRL_S_AONMIX base address */
  #define BLK_CTRL_S_AONMIX_BASE                   (0x444F0000u)
  /** Peripheral BLK_CTRL_S_AONMIX base pointer */
  #define BLK_CTRL_S_AONMIX                        ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX_BASE)
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
  #define BLK_CTRL_S_AONMIX_BASE_ADDRS             { BLK_CTRL_S_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
  #define BLK_CTRL_S_AONMIX_BASE_PTRS              { BLK_CTRL_S_AONMIX }
#endif

/* BLK_CTRL_WAKEUPMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_WAKEUPMIX base address */
  #define BLK_CTRL_WAKEUPMIX_BASE                  (0x52420000u)
  /** Peripheral BLK_CTRL_WAKEUPMIX base address */
  #define BLK_CTRL_WAKEUPMIX_BASE_NS               (0x42420000u)
  /** Peripheral BLK_CTRL_WAKEUPMIX base pointer */
  #define BLK_CTRL_WAKEUPMIX                       ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX_BASE)
  /** Peripheral BLK_CTRL_WAKEUPMIX base pointer */
  #define BLK_CTRL_WAKEUPMIX_NS                    ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
  #define BLK_CTRL_WAKEUPMIX_BASE_ADDRS            { BLK_CTRL_WAKEUPMIX_BASE }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
  #define BLK_CTRL_WAKEUPMIX_BASE_PTRS             { BLK_CTRL_WAKEUPMIX }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
  #define BLK_CTRL_WAKEUPMIX_BASE_ADDRS_NS         { BLK_CTRL_WAKEUPMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
  #define BLK_CTRL_WAKEUPMIX_BASE_PTRS_NS          { BLK_CTRL_WAKEUPMIX_NS }
#else
  /** Peripheral BLK_CTRL_WAKEUPMIX base address */
  #define BLK_CTRL_WAKEUPMIX_BASE                  (0x42420000u)
  /** Peripheral BLK_CTRL_WAKEUPMIX base pointer */
  #define BLK_CTRL_WAKEUPMIX                       ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX_BASE)
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
  #define BLK_CTRL_WAKEUPMIX_BASE_ADDRS            { BLK_CTRL_WAKEUPMIX_BASE }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
  #define BLK_CTRL_WAKEUPMIX_BASE_PTRS             { BLK_CTRL_WAKEUPMIX }
#endif

/* CACHE_ECC_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM base address */
  #define CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE (0x54401000u)
  /** Peripheral CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM base address */
  #define CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE_NS (0x44401000u)
  /** Peripheral CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM base pointer */
  #define CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM      ((CACHE_ECC_MCM_Type *)CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE)
  /** Peripheral CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM base pointer */
  #define CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_NS   ((CACHE_ECC_MCM_Type *)CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE_NS)
  /** Array initializer of CACHE_ECC_MCM peripheral base addresses */
  #define CACHE_ECC_MCM_BASE_ADDRS                 { CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE }
  /** Array initializer of CACHE_ECC_MCM peripheral base pointers */
  #define CACHE_ECC_MCM_BASE_PTRS                  { CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM }
  /** Array initializer of CACHE_ECC_MCM peripheral base addresses */
  #define CACHE_ECC_MCM_BASE_ADDRS_NS              { CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE_NS }
  /** Array initializer of CACHE_ECC_MCM peripheral base pointers */
  #define CACHE_ECC_MCM_BASE_PTRS_NS               { CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_NS }
#else
  /** Peripheral CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM base address */
  #define CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE (0x44401000u)
  /** Peripheral CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM base pointer */
  #define CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM      ((CACHE_ECC_MCM_Type *)CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE)
  /** Array initializer of CACHE_ECC_MCM peripheral base addresses */
  #define CACHE_ECC_MCM_BASE_ADDRS                 { CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM_BASE }
  /** Array initializer of CACHE_ECC_MCM peripheral base pointers */
  #define CACHE_ECC_MCM_BASE_PTRS                  { CP_CM33_IMX9RTC__CM33_CACHE_ECC_MCM }
#endif

/* CAN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CAN1 base address */
  #define CAN1_BASE                                (0x543A0000u)
  /** Peripheral CAN1 base address */
  #define CAN1_BASE_NS                             (0x443A0000u)
  /** Peripheral CAN1 base pointer */
  #define CAN1                                     ((CAN_Type *)CAN1_BASE)
  /** Peripheral CAN1 base pointer */
  #define CAN1_NS                                  ((CAN_Type *)CAN1_BASE_NS)
  /** Peripheral CAN2 base address */
  #define CAN2_BASE                                (0x525B0000u)
  /** Peripheral CAN2 base address */
  #define CAN2_BASE_NS                             (0x425B0000u)
  /** Peripheral CAN2 base pointer */
  #define CAN2                                     ((CAN_Type *)CAN2_BASE)
  /** Peripheral CAN2 base pointer */
  #define CAN2_NS                                  ((CAN_Type *)CAN2_BASE_NS)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { 0u, CAN1_BASE, CAN2_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { (CAN_Type *)0u, CAN1, CAN2 }
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS_NS                        { 0u, CAN1_BASE_NS, CAN2_BASE_NS }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS_NS                         { (CAN_Type *)0u, CAN1_NS, CAN2_NS }
#else
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
#endif
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Tx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Wake_Up_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Error_IRQS                           { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_Bus_Off_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn }

/* CCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CCM base address */
  #define CCM_BASE                                 (0x54450000u)
  /** Peripheral CCM base address */
  #define CCM_BASE_NS                              (0x44450000u)
  /** Peripheral CCM base pointer */
  #define CCM                                      ((CCM_Type *)CCM_BASE)
  /** Peripheral CCM base pointer */
  #define CCM_NS                                   ((CCM_Type *)CCM_BASE_NS)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { CCM_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { CCM }
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS_NS                        { CCM_BASE_NS }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS_NS                         { CCM_NS }
#else
  /** Peripheral CCM base address */
  #define CCM_BASE                                 (0x44450000u)
  /** Peripheral CCM base pointer */
  #define CCM                                      ((CCM_Type *)CCM_BASE)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { CCM_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { CCM }
#endif

/* CMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMP1 base address */
  #define CMP1_BASE                                (0x52DC0000u)
  /** Peripheral CMP1 base address */
  #define CMP1_BASE_NS                             (0x42DC0000u)
  /** Peripheral CMP1 base pointer */
  #define CMP1                                     ((CMP_Type *)CMP1_BASE)
  /** Peripheral CMP1 base pointer */
  #define CMP1_NS                                  ((CMP_Type *)CMP1_BASE_NS)
  /** Peripheral CMP2 base address */
  #define CMP2_BASE                                (0x52DD0000u)
  /** Peripheral CMP2 base address */
  #define CMP2_BASE_NS                             (0x42DD0000u)
  /** Peripheral CMP2 base pointer */
  #define CMP2                                     ((CMP_Type *)CMP2_BASE)
  /** Peripheral CMP2 base pointer */
  #define CMP2_NS                                  ((CMP_Type *)CMP2_BASE_NS)
  /** Peripheral CMP3 base address */
  #define CMP3_BASE                                (0x52DE0000u)
  /** Peripheral CMP3 base address */
  #define CMP3_BASE_NS                             (0x42DE0000u)
  /** Peripheral CMP3 base pointer */
  #define CMP3                                     ((CMP_Type *)CMP3_BASE)
  /** Peripheral CMP3 base pointer */
  #define CMP3_NS                                  ((CMP_Type *)CMP3_BASE_NS)
  /** Peripheral CMP4 base address */
  #define CMP4_BASE                                (0x52DF0000u)
  /** Peripheral CMP4 base address */
  #define CMP4_BASE_NS                             (0x42DF0000u)
  /** Peripheral CMP4 base pointer */
  #define CMP4                                     ((CMP_Type *)CMP4_BASE)
  /** Peripheral CMP4 base pointer */
  #define CMP4_NS                                  ((CMP_Type *)CMP4_BASE_NS)
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS                           { 0u, CMP1_BASE, CMP2_BASE, CMP3_BASE, CMP4_BASE }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS                            { (CMP_Type *)0u, CMP1, CMP2, CMP3, CMP4 }
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS_NS                        { 0u, CMP1_BASE_NS, CMP2_BASE_NS, CMP3_BASE_NS, CMP4_BASE_NS }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS_NS                         { (CMP_Type *)0u, CMP1_NS, CMP2_NS, CMP3_NS, CMP4_NS }
#else
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
#endif
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { NotAvail_IRQn, ACMP1_IRQn, ACMP2_IRQn, ACMP3_IRQn, ACMP4_IRQn }

/* DAC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DAC base address */
  #define DAC_BASE                                 (0x52E20000u)
  /** Peripheral DAC base address */
  #define DAC_BASE_NS                              (0x42E20000u)
  /** Peripheral DAC base pointer */
  #define DAC                                      ((DAC_Type *)DAC_BASE)
  /** Peripheral DAC base pointer */
  #define DAC_NS                                   ((DAC_Type *)DAC_BASE_NS)
  /** Array initializer of DAC peripheral base addresses */
  #define DAC_BASE_ADDRS                           { DAC_BASE }
  /** Array initializer of DAC peripheral base pointers */
  #define DAC_BASE_PTRS                            { DAC }
  /** Array initializer of DAC peripheral base addresses */
  #define DAC_BASE_ADDRS_NS                        { DAC_BASE_NS }
  /** Array initializer of DAC peripheral base pointers */
  #define DAC_BASE_PTRS_NS                         { DAC_NS }
#else
  /** Peripheral DAC base address */
  #define DAC_BASE                                 (0x42E20000u)
  /** Peripheral DAC base pointer */
  #define DAC                                      ((DAC_Type *)DAC_BASE)
  /** Array initializer of DAC peripheral base addresses */
  #define DAC_BASE_ADDRS                           { DAC_BASE }
  /** Array initializer of DAC peripheral base pointers */
  #define DAC_BASE_PTRS                            { DAC }
#endif
/** Interrupt vectors for the DAC peripheral type */
#define DAC_IRQS                                 { DAC_IRQn }

/* DCDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DCDC base address */
  #define DCDC_BASE                                (0x54520000u)
  /** Peripheral DCDC base address */
  #define DCDC_BASE_NS                             (0x44520000u)
  /** Peripheral DCDC base pointer */
  #define DCDC                                     ((DCDC_Type *)DCDC_BASE)
  /** Peripheral DCDC base pointer */
  #define DCDC_NS                                  ((DCDC_Type *)DCDC_BASE_NS)
  /** Array initializer of DCDC peripheral base addresses */
  #define DCDC_BASE_ADDRS                          { DCDC_BASE }
  /** Array initializer of DCDC peripheral base pointers */
  #define DCDC_BASE_PTRS                           { DCDC }
  /** Array initializer of DCDC peripheral base addresses */
  #define DCDC_BASE_ADDRS_NS                       { DCDC_BASE_NS }
  /** Array initializer of DCDC peripheral base pointers */
  #define DCDC_BASE_PTRS_NS                        { DCDC_NS }
#else
  /** Peripheral DCDC base address */
  #define DCDC_BASE                                (0x44520000u)
  /** Peripheral DCDC base pointer */
  #define DCDC                                     ((DCDC_Type *)DCDC_BASE)
  /** Array initializer of DCDC peripheral base addresses */
  #define DCDC_BASE_ADDRS                          { DCDC_BASE }
  /** Array initializer of DCDC peripheral base pointers */
  #define DCDC_BASE_PTRS                           { DCDC }
#endif
/** Interrupt vectors for the DCDC peripheral type */
#define DCDC_IRQS                                { DCDC_IRQn }

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA3 base address */
  #define DMA3_BASE                                (0x54000000u)
  /** Peripheral DMA3 base address */
  #define DMA3_BASE_NS                             (0x44000000u)
  /** Peripheral DMA3 base pointer */
  #define DMA3                                     ((DMA_Type *)DMA3_BASE)
  /** Peripheral DMA3 base pointer */
  #define DMA3_NS                                  ((DMA_Type *)DMA3_BASE_NS)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA3_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA3 }
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS_NS                        { DMA3_BASE_NS }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS_NS                         { DMA3_NS }
#else
  /** Peripheral DMA3 base address */
  #define DMA3_BASE                                (0x44000000u)
  /** Peripheral DMA3 base pointer */
  #define DMA3                                     ((DMA_Type *)DMA3_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA3_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA3 }
#endif
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { DMA3_CH0_IRQn, DMA3_CH1_IRQn, DMA3_CH2_IRQn, DMA3_CH3_IRQn, DMA3_CH4_IRQn, DMA3_CH5_IRQn, DMA3_CH6_IRQn, DMA3_CH7_IRQn, DMA3_CH8_IRQn, DMA3_CH9_IRQn, DMA3_CH10_IRQn, DMA3_CH11_IRQn, DMA3_CH12_IRQn, DMA3_CH13_IRQn, DMA3_CH14_IRQn, DMA3_CH15_IRQn, DMA3_CH16_IRQn, DMA3_CH17_IRQn, DMA3_CH18_IRQn, DMA3_CH19_IRQn, DMA3_CH20_IRQn, DMA3_CH21_IRQn, DMA3_CH22_IRQn, DMA3_CH23_IRQn, DMA3_CH24_IRQn, DMA3_CH25_IRQn, DMA3_CH26_IRQn, DMA3_CH27_IRQn, DMA3_CH28_IRQn, DMA3_CH29_IRQn, DMA3_CH30_IRQn, DMA3_CH31_IRQn } }
#define DMA_ERROR_IRQS                           { { DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn, DMA_ERROR_IRQn } }

/* DMA4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA4 base address */
  #define DMA4_BASE                                (0x52000000u)
  /** Peripheral DMA4 base address */
  #define DMA4_BASE_NS                             (0x42000000u)
  /** Peripheral DMA4 base pointer */
  #define DMA4                                     ((DMA4_Type *)DMA4_BASE)
  /** Peripheral DMA4 base pointer */
  #define DMA4_NS                                  ((DMA4_Type *)DMA4_BASE_NS)
  /** Array initializer of DMA4 peripheral base addresses */
  #define DMA4_BASE_ADDRS                          { DMA4_BASE }
  /** Array initializer of DMA4 peripheral base pointers */
  #define DMA4_BASE_PTRS                           { DMA4 }
  /** Array initializer of DMA4 peripheral base addresses */
  #define DMA4_BASE_ADDRS_NS                       { DMA4_BASE_NS }
  /** Array initializer of DMA4 peripheral base pointers */
  #define DMA4_BASE_PTRS_NS                        { DMA4_NS }
#else
  /** Peripheral DMA4 base address */
  #define DMA4_BASE                                (0x42000000u)
  /** Peripheral DMA4 base pointer */
  #define DMA4                                     ((DMA4_Type *)DMA4_BASE)
  /** Array initializer of DMA4 peripheral base addresses */
  #define DMA4_BASE_ADDRS                          { DMA4_BASE }
  /** Array initializer of DMA4 peripheral base pointers */
  #define DMA4_BASE_PTRS                           { DMA4 }
#endif
/** Interrupt vectors for the DMA4 peripheral type */
#define DMA4_IRQS                                { { DMA4_CH0_CH1_CH32_CH33_IRQn, DMA4_CH0_CH1_CH32_CH33_IRQn, DMA4_CH2_CH3_CH34_CH35_IRQn, DMA4_CH2_CH3_CH34_CH35_IRQn, DMA4_CH4_CH5_CH36_CH37_IRQn, DMA4_CH4_CH5_CH36_CH37_IRQn, DMA4_CH6_CH7_CH38_CH39_IRQn, DMA4_CH6_CH7_CH38_CH39_IRQn, DMA4_CH8_CH9_CH40_CH41_IRQn, DMA4_CH8_CH9_CH40_CH41_IRQn, DMA4_CH10_CH11_CH42_CH43_IRQn, DMA4_CH10_CH11_CH42_CH43_IRQn, DMA4_CH12_CH13_CH44_CH45_IRQn, DMA4_CH12_CH13_CH44_CH45_IRQn, DMA4_CH14_CH15_CH46_CH47_IRQn, DMA4_CH14_CH15_CH46_CH47_IRQn, DMA4_CH16_CH17_CH48_CH49_IRQn, DMA4_CH16_CH17_CH48_CH49_IRQn, DMA4_CH18_CH19_CH50_CH51_IRQn, DMA4_CH18_CH19_CH50_CH51_IRQn, DMA4_CH20_CH21_CH52_CH53_IRQn, DMA4_CH20_CH21_CH52_CH53_IRQn, DMA4_CH22_CH23_CH54_CH55_IRQn, DMA4_CH22_CH23_CH54_CH55_IRQn, DMA4_CH24_CH25_CH56_CH57_IRQn, DMA4_CH24_CH25_CH56_CH57_IRQn, DMA4_CH26_CH27_CH58_CH59_IRQn, DMA4_CH26_CH27_CH58_CH59_IRQn, DMA4_CH28_CH29_CH60_CH61_IRQn, DMA4_CH28_CH29_CH60_CH61_IRQn, DMA4_CH30_CH31_CH62_CH63_IRQn, DMA4_CH30_CH31_CH62_CH63_IRQn, DMA4_CH0_CH1_CH32_CH33_IRQn, DMA4_CH0_CH1_CH32_CH33_IRQn, DMA4_CH2_CH3_CH34_CH35_IRQn, DMA4_CH2_CH3_CH34_CH35_IRQn, DMA4_CH4_CH5_CH36_CH37_IRQn, DMA4_CH4_CH5_CH36_CH37_IRQn, DMA4_CH6_CH7_CH38_CH39_IRQn, DMA4_CH6_CH7_CH38_CH39_IRQn, DMA4_CH8_CH9_CH40_CH41_IRQn, DMA4_CH8_CH9_CH40_CH41_IRQn, DMA4_CH10_CH11_CH42_CH43_IRQn, DMA4_CH10_CH11_CH42_CH43_IRQn, DMA4_CH12_CH13_CH44_CH45_IRQn, DMA4_CH12_CH13_CH44_CH45_IRQn, DMA4_CH14_CH15_CH46_CH47_IRQn, DMA4_CH14_CH15_CH46_CH47_IRQn, DMA4_CH16_CH17_CH48_CH49_IRQn, DMA4_CH16_CH17_CH48_CH49_IRQn, DMA4_CH18_CH19_CH50_CH51_IRQn, DMA4_CH18_CH19_CH50_CH51_IRQn, DMA4_CH20_CH21_CH52_CH53_IRQn, DMA4_CH20_CH21_CH52_CH53_IRQn, DMA4_CH22_CH23_CH54_CH55_IRQn, DMA4_CH22_CH23_CH54_CH55_IRQn, DMA4_CH24_CH25_CH56_CH57_IRQn, DMA4_CH24_CH25_CH56_CH57_IRQn, DMA4_CH26_CH27_CH58_CH59_IRQn, DMA4_CH26_CH27_CH58_CH59_IRQn, DMA4_CH28_CH29_CH60_CH61_IRQn, DMA4_CH28_CH29_CH60_CH61_IRQn, DMA4_CH30_CH31_CH62_CH63_IRQn, DMA4_CH30_CH31_CH62_CH63_IRQn } }
#define DMA4_ERROR_IRQS                          { { DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn, DMA4_ERROR_IRQn } }

/* EIM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EIM base address */
  #define EIM_BASE                                 (0x5B860000u)
  /** Peripheral EIM base address */
  #define EIM_BASE_NS                              (0x4B860000u)
  /** Peripheral EIM base pointer */
  #define EIM                                      ((EIM_Type *)EIM_BASE)
  /** Peripheral EIM base pointer */
  #define EIM_NS                                   ((EIM_Type *)EIM_BASE_NS)
  /** Array initializer of EIM peripheral base addresses */
  #define EIM_BASE_ADDRS                           { EIM_BASE }
  /** Array initializer of EIM peripheral base pointers */
  #define EIM_BASE_PTRS                            { EIM }
  /** Array initializer of EIM peripheral base addresses */
  #define EIM_BASE_ADDRS_NS                        { EIM_BASE_NS }
  /** Array initializer of EIM peripheral base pointers */
  #define EIM_BASE_PTRS_NS                         { EIM_NS }
#else
  /** Peripheral EIM base address */
  #define EIM_BASE                                 (0x4B860000u)
  /** Peripheral EIM base pointer */
  #define EIM                                      ((EIM_Type *)EIM_BASE)
  /** Array initializer of EIM peripheral base addresses */
  #define EIM_BASE_ADDRS                           { EIM_BASE }
  /** Array initializer of EIM peripheral base pointers */
  #define EIM_BASE_PTRS                            { EIM }
#endif

/* ENETC_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EMDIO_GLOBAL base address */
  #define EMDIO_GLOBAL_BASE                        (0x70BB0000u)
  /** Peripheral EMDIO_GLOBAL base address */
  #define EMDIO_GLOBAL_BASE_NS                     (0x60BB0000u)
  /** Peripheral EMDIO_GLOBAL base pointer */
  #define EMDIO_GLOBAL                             ((ENETC_GLOBAL_Type *)EMDIO_GLOBAL_BASE)
  /** Peripheral EMDIO_GLOBAL base pointer */
  #define EMDIO_GLOBAL_NS                          ((ENETC_GLOBAL_Type *)EMDIO_GLOBAL_BASE_NS)
  /** Peripheral ENETC0_GLOBAL base address */
  #define ENETC0_GLOBAL_BASE                       (0x70B20000u)
  /** Peripheral ENETC0_GLOBAL base address */
  #define ENETC0_GLOBAL_BASE_NS                    (0x60B20000u)
  /** Peripheral ENETC0_GLOBAL base pointer */
  #define ENETC0_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC0_GLOBAL_BASE)
  /** Peripheral ENETC0_GLOBAL base pointer */
  #define ENETC0_GLOBAL_NS                         ((ENETC_GLOBAL_Type *)ENETC0_GLOBAL_BASE_NS)
  /** Peripheral ENETC1_GLOBAL base address */
  #define ENETC1_GLOBAL_BASE                       (0x70B60000u)
  /** Peripheral ENETC1_GLOBAL base address */
  #define ENETC1_GLOBAL_BASE_NS                    (0x60B60000u)
  /** Peripheral ENETC1_GLOBAL base pointer */
  #define ENETC1_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC1_GLOBAL_BASE)
  /** Peripheral ENETC1_GLOBAL base pointer */
  #define ENETC1_GLOBAL_NS                         ((ENETC_GLOBAL_Type *)ENETC1_GLOBAL_BASE_NS)
  /** Peripheral SW0_GLOBAL base address */
  #define SW0_GLOBAL_BASE                          (0x70A80000u)
  /** Peripheral SW0_GLOBAL base address */
  #define SW0_GLOBAL_BASE_NS                       (0x60A80000u)
  /** Peripheral SW0_GLOBAL base pointer */
  #define SW0_GLOBAL                               ((ENETC_GLOBAL_Type *)SW0_GLOBAL_BASE)
  /** Peripheral SW0_GLOBAL base pointer */
  #define SW0_GLOBAL_NS                            ((ENETC_GLOBAL_Type *)SW0_GLOBAL_BASE_NS)
  /** Peripheral TMR0_GLOBAL base address */
  #define TMR0_GLOBAL_BASE                         (0x70B90000u)
  /** Peripheral TMR0_GLOBAL base address */
  #define TMR0_GLOBAL_BASE_NS                      (0x60B90000u)
  /** Peripheral TMR0_GLOBAL base pointer */
  #define TMR0_GLOBAL                              ((ENETC_GLOBAL_Type *)TMR0_GLOBAL_BASE)
  /** Peripheral TMR0_GLOBAL base pointer */
  #define TMR0_GLOBAL_NS                           ((ENETC_GLOBAL_Type *)TMR0_GLOBAL_BASE_NS)
  /** Array initializer of ENETC_GLOBAL peripheral base addresses */
  #define ENETC_GLOBAL_BASE_ADDRS                  { EMDIO_GLOBAL_BASE, ENETC0_GLOBAL_BASE, ENETC1_GLOBAL_BASE, SW0_GLOBAL_BASE, TMR0_GLOBAL_BASE }
  /** Array initializer of ENETC_GLOBAL peripheral base pointers */
  #define ENETC_GLOBAL_BASE_PTRS                   { EMDIO_GLOBAL, ENETC0_GLOBAL, ENETC1_GLOBAL, SW0_GLOBAL, TMR0_GLOBAL }
  /** Array initializer of ENETC_GLOBAL peripheral base addresses */
  #define ENETC_GLOBAL_BASE_ADDRS_NS               { EMDIO_GLOBAL_BASE_NS, ENETC0_GLOBAL_BASE_NS, ENETC1_GLOBAL_BASE_NS, SW0_GLOBAL_BASE_NS, TMR0_GLOBAL_BASE_NS }
  /** Array initializer of ENETC_GLOBAL peripheral base pointers */
  #define ENETC_GLOBAL_BASE_PTRS_NS                { EMDIO_GLOBAL_NS, ENETC0_GLOBAL_NS, ENETC1_GLOBAL_NS, SW0_GLOBAL_NS, TMR0_GLOBAL_NS }
#else
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
#endif

/* ENETC_PCI_TYPE0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC_F0_PCI_HDR_TYPE0 base address */
  #define NETC_F0_PCI_HDR_TYPE0_BASE               (0x70000000u)
  /** Peripheral NETC_F0_PCI_HDR_TYPE0 base address */
  #define NETC_F0_PCI_HDR_TYPE0_BASE_NS            (0x60000000u)
  /** Peripheral NETC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC_F0_PCI_HDR_TYPE0                    ((ENETC_PCI_TYPE0_Type *)NETC_F0_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC_F0_PCI_HDR_TYPE0_NS                 ((ENETC_PCI_TYPE0_Type *)NETC_F0_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral NETC_F1_PCI_HDR_TYPE0 base address */
  #define NETC_F1_PCI_HDR_TYPE0_BASE               (0x70001000u)
  /** Peripheral NETC_F1_PCI_HDR_TYPE0 base address */
  #define NETC_F1_PCI_HDR_TYPE0_BASE_NS            (0x60001000u)
  /** Peripheral NETC_F1_PCI_HDR_TYPE0 base pointer */
  #define NETC_F1_PCI_HDR_TYPE0                    ((ENETC_PCI_TYPE0_Type *)NETC_F1_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC_F1_PCI_HDR_TYPE0 base pointer */
  #define NETC_F1_PCI_HDR_TYPE0_NS                 ((ENETC_PCI_TYPE0_Type *)NETC_F1_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral NETC_F2_PCI_HDR_TYPE0 base address */
  #define NETC_F2_PCI_HDR_TYPE0_BASE               (0x70002000u)
  /** Peripheral NETC_F2_PCI_HDR_TYPE0 base address */
  #define NETC_F2_PCI_HDR_TYPE0_BASE_NS            (0x60002000u)
  /** Peripheral NETC_F2_PCI_HDR_TYPE0 base pointer */
  #define NETC_F2_PCI_HDR_TYPE0                    ((ENETC_PCI_TYPE0_Type *)NETC_F2_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC_F2_PCI_HDR_TYPE0 base pointer */
  #define NETC_F2_PCI_HDR_TYPE0_NS                 ((ENETC_PCI_TYPE0_Type *)NETC_F2_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral NETC_F3_PCI_HDR_TYPE0 base address */
  #define NETC_F3_PCI_HDR_TYPE0_BASE               (0x70003000u)
  /** Peripheral NETC_F3_PCI_HDR_TYPE0 base address */
  #define NETC_F3_PCI_HDR_TYPE0_BASE_NS            (0x60003000u)
  /** Peripheral NETC_F3_PCI_HDR_TYPE0 base pointer */
  #define NETC_F3_PCI_HDR_TYPE0                    ((ENETC_PCI_TYPE0_Type *)NETC_F3_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC_F3_PCI_HDR_TYPE0 base pointer */
  #define NETC_F3_PCI_HDR_TYPE0_NS                 ((ENETC_PCI_TYPE0_Type *)NETC_F3_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral NETC_F4_PCI_HDR_TYPE0 base address */
  #define NETC_F4_PCI_HDR_TYPE0_BASE               (0x70004000u)
  /** Peripheral NETC_F4_PCI_HDR_TYPE0 base address */
  #define NETC_F4_PCI_HDR_TYPE0_BASE_NS            (0x60004000u)
  /** Peripheral NETC_F4_PCI_HDR_TYPE0 base pointer */
  #define NETC_F4_PCI_HDR_TYPE0                    ((ENETC_PCI_TYPE0_Type *)NETC_F4_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC_F4_PCI_HDR_TYPE0 base pointer */
  #define NETC_F4_PCI_HDR_TYPE0_NS                 ((ENETC_PCI_TYPE0_Type *)NETC_F4_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of ENETC_PCI_TYPE0 peripheral base addresses */
  #define ENETC_PCI_TYPE0_BASE_ADDRS               { NETC_F0_PCI_HDR_TYPE0_BASE, NETC_F1_PCI_HDR_TYPE0_BASE, NETC_F2_PCI_HDR_TYPE0_BASE, NETC_F3_PCI_HDR_TYPE0_BASE, NETC_F4_PCI_HDR_TYPE0_BASE }
  /** Array initializer of ENETC_PCI_TYPE0 peripheral base pointers */
  #define ENETC_PCI_TYPE0_BASE_PTRS                { NETC_F0_PCI_HDR_TYPE0, NETC_F1_PCI_HDR_TYPE0, NETC_F2_PCI_HDR_TYPE0, NETC_F3_PCI_HDR_TYPE0, NETC_F4_PCI_HDR_TYPE0 }
  /** Array initializer of ENETC_PCI_TYPE0 peripheral base addresses */
  #define ENETC_PCI_TYPE0_BASE_ADDRS_NS            { NETC_F0_PCI_HDR_TYPE0_BASE_NS, NETC_F1_PCI_HDR_TYPE0_BASE_NS, NETC_F2_PCI_HDR_TYPE0_BASE_NS, NETC_F3_PCI_HDR_TYPE0_BASE_NS, NETC_F4_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of ENETC_PCI_TYPE0 peripheral base pointers */
  #define ENETC_PCI_TYPE0_BASE_PTRS_NS             { NETC_F0_PCI_HDR_TYPE0_NS, NETC_F1_PCI_HDR_TYPE0_NS, NETC_F2_PCI_HDR_TYPE0_NS, NETC_F3_PCI_HDR_TYPE0_NS, NETC_F4_PCI_HDR_TYPE0_NS }
#else
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
#endif

/* ENETC_PF_EMDIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EMDIO_BASE base address */
  #define EMDIO_BASE_BASE                          (0x70BA0000u)
  /** Peripheral EMDIO_BASE base address */
  #define EMDIO_BASE_BASE_NS                       (0x60BA0000u)
  /** Peripheral EMDIO_BASE base pointer */
  #define EMDIO_BASE                               ((ENETC_PF_EMDIO_Type *)EMDIO_BASE_BASE)
  /** Peripheral EMDIO_BASE base pointer */
  #define EMDIO_BASE_NS                            ((ENETC_PF_EMDIO_Type *)EMDIO_BASE_BASE_NS)
  /** Array initializer of ENETC_PF_EMDIO peripheral base addresses */
  #define ENETC_PF_EMDIO_BASE_ADDRS                { EMDIO_BASE_BASE }
  /** Array initializer of ENETC_PF_EMDIO peripheral base pointers */
  #define ENETC_PF_EMDIO_BASE_PTRS                 { EMDIO_BASE }
  /** Array initializer of ENETC_PF_EMDIO peripheral base addresses */
  #define ENETC_PF_EMDIO_BASE_ADDRS_NS             { EMDIO_BASE_BASE_NS }
  /** Array initializer of ENETC_PF_EMDIO peripheral base pointers */
  #define ENETC_PF_EMDIO_BASE_PTRS_NS              { EMDIO_BASE_NS }
#else
  /** Peripheral EMDIO_BASE base address */
  #define EMDIO_BASE_BASE                          (0x60BA0000u)
  /** Peripheral EMDIO_BASE base pointer */
  #define EMDIO_BASE                               ((ENETC_PF_EMDIO_Type *)EMDIO_BASE_BASE)
  /** Array initializer of ENETC_PF_EMDIO peripheral base addresses */
  #define ENETC_PF_EMDIO_BASE_ADDRS                { EMDIO_BASE_BASE }
  /** Array initializer of ENETC_PF_EMDIO peripheral base pointers */
  #define ENETC_PF_EMDIO_BASE_PTRS                 { EMDIO_BASE }
#endif

/* ENETC_PF_TMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TMR0_BASE base address */
  #define TMR0_BASE_BASE                           (0x70B80000u)
  /** Peripheral TMR0_BASE base address */
  #define TMR0_BASE_BASE_NS                        (0x60B80000u)
  /** Peripheral TMR0_BASE base pointer */
  #define TMR0_BASE                                ((ENETC_PF_TMR_Type *)TMR0_BASE_BASE)
  /** Peripheral TMR0_BASE base pointer */
  #define TMR0_BASE_NS                             ((ENETC_PF_TMR_Type *)TMR0_BASE_BASE_NS)
  /** Array initializer of ENETC_PF_TMR peripheral base addresses */
  #define ENETC_PF_TMR_BASE_ADDRS                  { TMR0_BASE_BASE }
  /** Array initializer of ENETC_PF_TMR peripheral base pointers */
  #define ENETC_PF_TMR_BASE_PTRS                   { TMR0_BASE }
  /** Array initializer of ENETC_PF_TMR peripheral base addresses */
  #define ENETC_PF_TMR_BASE_ADDRS_NS               { TMR0_BASE_BASE_NS }
  /** Array initializer of ENETC_PF_TMR peripheral base pointers */
  #define ENETC_PF_TMR_BASE_PTRS_NS                { TMR0_BASE_NS }
#else
  /** Peripheral TMR0_BASE base address */
  #define TMR0_BASE_BASE                           (0x60B80000u)
  /** Peripheral TMR0_BASE base pointer */
  #define TMR0_BASE                                ((ENETC_PF_TMR_Type *)TMR0_BASE_BASE)
  /** Array initializer of ENETC_PF_TMR peripheral base addresses */
  #define ENETC_PF_TMR_BASE_ADDRS                  { TMR0_BASE_BASE }
  /** Array initializer of ENETC_PF_TMR peripheral base pointers */
  #define ENETC_PF_TMR_BASE_PTRS                   { TMR0_BASE }
#endif

/* ENETC_SI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENETC0_SI0 base address */
  #define ENETC0_SI0_BASE                          (0x70B00000u)
  /** Peripheral ENETC0_SI0 base address */
  #define ENETC0_SI0_BASE_NS                       (0x60B00000u)
  /** Peripheral ENETC0_SI0 base pointer */
  #define ENETC0_SI0                               ((ENETC_SI_Type *)ENETC0_SI0_BASE)
  /** Peripheral ENETC0_SI0 base pointer */
  #define ENETC0_SI0_NS                            ((ENETC_SI_Type *)ENETC0_SI0_BASE_NS)
  /** Peripheral ENETC1_SI0 base address */
  #define ENETC1_SI0_BASE                          (0x70B40000u)
  /** Peripheral ENETC1_SI0 base address */
  #define ENETC1_SI0_BASE_NS                       (0x60B40000u)
  /** Peripheral ENETC1_SI0 base pointer */
  #define ENETC1_SI0                               ((ENETC_SI_Type *)ENETC1_SI0_BASE)
  /** Peripheral ENETC1_SI0 base pointer */
  #define ENETC1_SI0_NS                            ((ENETC_SI_Type *)ENETC1_SI0_BASE_NS)
  /** Peripheral ENETC1_SI1 base address */
  #define ENETC1_SI1_BASE                          (0x70C10000u)
  /** Peripheral ENETC1_SI1 base address */
  #define ENETC1_SI1_BASE_NS                       (0x60C10000u)
  /** Peripheral ENETC1_SI1 base pointer */
  #define ENETC1_SI1                               ((ENETC_SI_Type *)ENETC1_SI1_BASE)
  /** Peripheral ENETC1_SI1 base pointer */
  #define ENETC1_SI1_NS                            ((ENETC_SI_Type *)ENETC1_SI1_BASE_NS)
  /** Array initializer of ENETC_SI peripheral base addresses */
  #define ENETC_SI_BASE_ADDRS                      { ENETC0_SI0_BASE, ENETC1_SI0_BASE, ENETC1_SI1_BASE }
  /** Array initializer of ENETC_SI peripheral base pointers */
  #define ENETC_SI_BASE_PTRS                       { ENETC0_SI0, ENETC1_SI0, ENETC1_SI1 }
  /** Array initializer of ENETC_SI peripheral base addresses */
  #define ENETC_SI_BASE_ADDRS_NS                   { ENETC0_SI0_BASE_NS, ENETC1_SI0_BASE_NS, ENETC1_SI1_BASE_NS }
  /** Array initializer of ENETC_SI peripheral base pointers */
  #define ENETC_SI_BASE_PTRS_NS                    { ENETC0_SI0_NS, ENETC1_SI0_NS, ENETC1_SI1_NS }
#else
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
#endif

/* ENETC_VF_PCI_TYPE0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC_VF1_PCI_HDR_TYPE0 base address */
  #define NETC_VF1_PCI_HDR_TYPE0_BASE              (0x70100000u)
  /** Peripheral NETC_VF1_PCI_HDR_TYPE0 base address */
  #define NETC_VF1_PCI_HDR_TYPE0_BASE_NS           (0x60100000u)
  /** Peripheral NETC_VF1_PCI_HDR_TYPE0 base pointer */
  #define NETC_VF1_PCI_HDR_TYPE0                   ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF1_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC_VF1_PCI_HDR_TYPE0 base pointer */
  #define NETC_VF1_PCI_HDR_TYPE0_NS                ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF1_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base addresses */
  #define ENETC_VF_PCI_TYPE0_BASE_ADDRS            { NETC_VF1_PCI_HDR_TYPE0_BASE }
  /** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base pointers */
  #define ENETC_VF_PCI_TYPE0_BASE_PTRS             { NETC_VF1_PCI_HDR_TYPE0 }
  /** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base addresses */
  #define ENETC_VF_PCI_TYPE0_BASE_ADDRS_NS         { NETC_VF1_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base pointers */
  #define ENETC_VF_PCI_TYPE0_BASE_PTRS_NS          { NETC_VF1_PCI_HDR_TYPE0_NS }
#else
  /** Peripheral NETC_VF1_PCI_HDR_TYPE0 base address */
  #define NETC_VF1_PCI_HDR_TYPE0_BASE              (0x60100000u)
  /** Peripheral NETC_VF1_PCI_HDR_TYPE0 base pointer */
  #define NETC_VF1_PCI_HDR_TYPE0                   ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF1_PCI_HDR_TYPE0_BASE)
  /** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base addresses */
  #define ENETC_VF_PCI_TYPE0_BASE_ADDRS            { NETC_VF1_PCI_HDR_TYPE0_BASE }
  /** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base pointers */
  #define ENETC_VF_PCI_TYPE0_BASE_PTRS             { NETC_VF1_PCI_HDR_TYPE0 }
#endif

/* EQDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EQDC1 base address */
  #define EQDC1_BASE                               (0x52710000u)
  /** Peripheral EQDC1 base address */
  #define EQDC1_BASE_NS                            (0x42710000u)
  /** Peripheral EQDC1 base pointer */
  #define EQDC1                                    ((EQDC_Type *)EQDC1_BASE)
  /** Peripheral EQDC1 base pointer */
  #define EQDC1_NS                                 ((EQDC_Type *)EQDC1_BASE_NS)
  /** Peripheral EQDC2 base address */
  #define EQDC2_BASE                               (0x52720000u)
  /** Peripheral EQDC2 base address */
  #define EQDC2_BASE_NS                            (0x42720000u)
  /** Peripheral EQDC2 base pointer */
  #define EQDC2                                    ((EQDC_Type *)EQDC2_BASE)
  /** Peripheral EQDC2 base pointer */
  #define EQDC2_NS                                 ((EQDC_Type *)EQDC2_BASE_NS)
  /** Array initializer of EQDC peripheral base addresses */
  #define EQDC_BASE_ADDRS                          { 0u, EQDC1_BASE, EQDC2_BASE }
  /** Array initializer of EQDC peripheral base pointers */
  #define EQDC_BASE_PTRS                           { (EQDC_Type *)0u, EQDC1, EQDC2 }
  /** Array initializer of EQDC peripheral base addresses */
  #define EQDC_BASE_ADDRS_NS                       { 0u, EQDC1_BASE_NS, EQDC2_BASE_NS }
  /** Array initializer of EQDC peripheral base pointers */
  #define EQDC_BASE_PTRS_NS                        { (EQDC_Type *)0u, EQDC1_NS, EQDC2_NS }
#else
  /** Peripheral EQDC1 base address */
  #define EQDC1_BASE                               (0x42710000u)
  /** Peripheral EQDC1 base pointer */
  #define EQDC1                                    ((EQDC_Type *)EQDC1_BASE)
  /** Peripheral EQDC2 base address */
  #define EQDC2_BASE                               (0x42720000u)
  /** Peripheral EQDC2 base pointer */
  #define EQDC2                                    ((EQDC_Type *)EQDC2_BASE)
  /** Array initializer of EQDC peripheral base addresses */
  #define EQDC_BASE_ADDRS                          { 0u, EQDC1_BASE, EQDC2_BASE }
  /** Array initializer of EQDC peripheral base pointers */
  #define EQDC_BASE_PTRS                           { (EQDC_Type *)0u, EQDC1, EQDC2 }
#endif
/** Interrupt vectors for the EQDC peripheral type */
#define EQDC_COMPARE_IRQS                        { NotAvail_IRQn, EQDC1_IRQn, EQDC2_IRQn }
#define EQDC_HOME_IRQS                           { NotAvail_IRQn, EQDC1_IRQn, EQDC2_IRQn }
#define EQDC_WDOG_IRQS                           { NotAvail_IRQn, EQDC1_IRQn, EQDC2_IRQn }
#define EQDC_INDEX_IRQS                          { NotAvail_IRQn, EQDC1_IRQn, EQDC2_IRQn }
#define EQDC_INPUT_SWITCH_IRQS                   { NotAvail_IRQn, EQDC1_IRQn, EQDC2_IRQn }

/* ERM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ERM base address */
  #define ERM_BASE                                 (0x5B864000u)
  /** Peripheral ERM base address */
  #define ERM_BASE_NS                              (0x4B864000u)
  /** Peripheral ERM base pointer */
  #define ERM                                      ((ERM_Type *)ERM_BASE)
  /** Peripheral ERM base pointer */
  #define ERM_NS                                   ((ERM_Type *)ERM_BASE_NS)
  /** Array initializer of ERM peripheral base addresses */
  #define ERM_BASE_ADDRS                           { ERM_BASE }
  /** Array initializer of ERM peripheral base pointers */
  #define ERM_BASE_PTRS                            { ERM }
  /** Array initializer of ERM peripheral base addresses */
  #define ERM_BASE_ADDRS_NS                        { ERM_BASE_NS }
  /** Array initializer of ERM peripheral base pointers */
  #define ERM_BASE_PTRS_NS                         { ERM_NS }
#else
  /** Peripheral ERM base address */
  #define ERM_BASE                                 (0x4B864000u)
  /** Peripheral ERM base pointer */
  #define ERM                                      ((ERM_Type *)ERM_BASE)
  /** Array initializer of ERM peripheral base addresses */
  #define ERM_BASE_ADDRS                           { ERM_BASE }
  /** Array initializer of ERM peripheral base pointers */
  #define ERM_BASE_PTRS                            { ERM }
#endif

/* EWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EWM base address */
  #define EWM_BASE                                 (0x527B0000u)
  /** Peripheral EWM base address */
  #define EWM_BASE_NS                              (0x427B0000u)
  /** Peripheral EWM base pointer */
  #define EWM                                      ((EWM_Type *)EWM_BASE)
  /** Peripheral EWM base pointer */
  #define EWM_NS                                   ((EWM_Type *)EWM_BASE_NS)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { EWM_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { EWM }
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS_NS                        { EWM_BASE_NS }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS_NS                         { EWM_NS }
#else
  /** Peripheral EWM base address */
  #define EWM_BASE                                 (0x427B0000u)
  /** Peripheral EWM base pointer */
  #define EWM                                      ((EWM_Type *)EWM_BASE)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { EWM_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { EWM }
#endif
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { EWM_IRQn }

/* FLEXIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXIO1 base address */
  #define FLEXIO1_BASE                             (0x525C0000u)
  /** Peripheral FLEXIO1 base address */
  #define FLEXIO1_BASE_NS                          (0x425C0000u)
  /** Peripheral FLEXIO1 base pointer */
  #define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
  /** Peripheral FLEXIO1 base pointer */
  #define FLEXIO1_NS                               ((FLEXIO_Type *)FLEXIO1_BASE_NS)
  /** Peripheral FLEXIO2 base address */
  #define FLEXIO2_BASE                             (0x525D0000u)
  /** Peripheral FLEXIO2 base address */
  #define FLEXIO2_BASE_NS                          (0x425D0000u)
  /** Peripheral FLEXIO2 base pointer */
  #define FLEXIO2                                  ((FLEXIO_Type *)FLEXIO2_BASE)
  /** Peripheral FLEXIO2 base pointer */
  #define FLEXIO2_NS                               ((FLEXIO_Type *)FLEXIO2_BASE_NS)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE, FLEXIO2_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1, FLEXIO2 }
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS_NS                     { 0u, FLEXIO1_BASE_NS, FLEXIO2_BASE_NS }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS_NS                      { (FLEXIO_Type *)0u, FLEXIO1_NS, FLEXIO2_NS }
#else
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
#endif
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { NotAvail_IRQn, FLEXIO1_IRQn, FLEXIO2_IRQn }

/* FLEXSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXSPI1 base address */
  #define FLEXSPI1_BASE                            (0x525E0000u)
  /** Peripheral FLEXSPI1 base address */
  #define FLEXSPI1_BASE_NS                         (0x425E0000u)
  /** Peripheral FLEXSPI1 base pointer */
  #define FLEXSPI1                                 ((FLEXSPI_Type *)FLEXSPI1_BASE)
  /** Peripheral FLEXSPI1 base pointer */
  #define FLEXSPI1_NS                              ((FLEXSPI_Type *)FLEXSPI1_BASE_NS)
  /** Peripheral FLEXSPI2 base address */
  #define FLEXSPI2_BASE                            (0x545E0000u)
  /** Peripheral FLEXSPI2 base address */
  #define FLEXSPI2_BASE_NS                         (0x445E0000u)
  /** Peripheral FLEXSPI2 base pointer */
  #define FLEXSPI2                                 ((FLEXSPI_Type *)FLEXSPI2_BASE)
  /** Peripheral FLEXSPI2 base pointer */
  #define FLEXSPI2_NS                              ((FLEXSPI_Type *)FLEXSPI2_BASE_NS)
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS                       { 0u, FLEXSPI1_BASE, FLEXSPI2_BASE }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS                        { (FLEXSPI_Type *)0u, FLEXSPI1, FLEXSPI2 }
  /** Array initializer of FLEXSPI peripheral base addresses */
  #define FLEXSPI_BASE_ADDRS_NS                    { 0u, FLEXSPI1_BASE_NS, FLEXSPI2_BASE_NS }
  /** Array initializer of FLEXSPI peripheral base pointers */
  #define FLEXSPI_BASE_PTRS_NS                     { (FLEXSPI_Type *)0u, FLEXSPI1_NS, FLEXSPI2_NS }
#else
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
#endif
/** Interrupt vectors for the FLEXSPI peripheral type */
#define FLEXSPI_IRQS                             { NotAvail_IRQn, FLEXSPI1_IRQn, FLEXSPI2_IRQn }
/** FlexSPI AMBA memory base alias count */
#define FLEXSPI_AMBA_BASE_ALIAS_COUNT     (2)
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /* FlexSPI AMBA base address array. */
  #define FlexSPI_AMBA_BASE_ARRAY                  { {0u, 0u}, {0x38000000u, 0x12000000u}, {0x14000000u, 0x32000000u} }
  #define FlexSPI_AMBA_BASE_ARRAY_NS               { {0u, 0u}, {0x28000000u, 0x2000000u}, {0x4000000u, 0x22000000u} }
  /* FlexSPI AMBA end address array. */
  #define FlexSPI_AMBA_END_ARRAY                   { {0u, 0u}, {0x3FFFFFFFu, 0x13FFFFFFu}, {0x17FFFFFFu, 0x33FFFFFFu} }
  #define FlexSPI_AMBA_END_ARRAY_NS                { {0u, 0u}, {0x2FFFFFFFu, 0x3FFFFFFu}, {0x7FFFFFFu, 0x23FFFFFFu} }
  /* FlexSPI1 AMBA address. */
  #define FlexSPI1_AMBA_BASE                       (0x38000000u)
  #define FlexSPI1_AMBA_BASE_NS                    (0x28000000u)
  /* FlexSPI1 ASFM address. */
  #define FlexSPI1_ASFM_BASE                       (0x38000000u)
  #define FlexSPI1_ASFM_BASE_NS                    (0x28000000u)
  /* Base Address of AHB address space mapped to IP RX FIFO. */
  #define FlexSPI1_ARDF_BASE                       (0x57420000u)
  #define FlexSPI1_ARDF_BASE_NS                    (0x47420000u)
  /* Base Address of AHB address space mapped to IP TX FIFO. */
  #define FlexSPI1_ATDF_BASE                       (0x57430000u)
  #define FlexSPI1_ATDF_BASE_NS                    (0x47430000u)
  /* FlexSPI2 AMBA address. */
  #define FlexSPI2_AMBA_BASE                       (0x14000000u)
  #define FlexSPI2_AMBA_BASE_NS                    (0x4000000u)
  /* FlexSPI2 ASFM address. */
  #define FlexSPI2_ASFM_BASE                       (0x14000000u)
  #define FlexSPI2_ASFM_BASE_NS                    (0x4000000u)
  /* Base Address of AHB address space mapped to IP RX FIFO. */
  #define FlexSPI2_ARDF_BASE                       (0x5DE00000u)
  #define FlexSPI2_ARDF_BASE_NS                    (0x4DE00000u)
  /* Base Address of AHB address space mapped to IP TX FIFO. */
  #define FlexSPI2_ATDF_BASE                       (0x5DE10000u)
  #define FlexSPI2_ATDF_BASE_NS                    (0x4DE10000u)
#else
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
#endif


/* FLEXSPI_SLV - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXSPI_SLV base address */
  #define FLEXSPI_SLV_BASE                         (0x52900000u)
  /** Peripheral FLEXSPI_SLV base address */
  #define FLEXSPI_SLV_BASE_NS                      (0x42900000u)
  /** Peripheral FLEXSPI_SLV base pointer */
  #define FLEXSPI_SLV                              ((FLEXSPI_SLV_Type *)FLEXSPI_SLV_BASE)
  /** Peripheral FLEXSPI_SLV base pointer */
  #define FLEXSPI_SLV_NS                           ((FLEXSPI_SLV_Type *)FLEXSPI_SLV_BASE_NS)
  /** Array initializer of FLEXSPI_SLV peripheral base addresses */
  #define FLEXSPI_SLV_BASE_ADDRS                   { FLEXSPI_SLV_BASE }
  /** Array initializer of FLEXSPI_SLV peripheral base pointers */
  #define FLEXSPI_SLV_BASE_PTRS                    { FLEXSPI_SLV }
  /** Array initializer of FLEXSPI_SLV peripheral base addresses */
  #define FLEXSPI_SLV_BASE_ADDRS_NS                { FLEXSPI_SLV_BASE_NS }
  /** Array initializer of FLEXSPI_SLV peripheral base pointers */
  #define FLEXSPI_SLV_BASE_PTRS_NS                 { FLEXSPI_SLV_NS }
#else
  /** Peripheral FLEXSPI_SLV base address */
  #define FLEXSPI_SLV_BASE                         (0x42900000u)
  /** Peripheral FLEXSPI_SLV base pointer */
  #define FLEXSPI_SLV                              ((FLEXSPI_SLV_Type *)FLEXSPI_SLV_BASE)
  /** Array initializer of FLEXSPI_SLV peripheral base addresses */
  #define FLEXSPI_SLV_BASE_ADDRS                   { FLEXSPI_SLV_BASE }
  /** Array initializer of FLEXSPI_SLV peripheral base pointers */
  #define FLEXSPI_SLV_BASE_PTRS                    { FLEXSPI_SLV }
#endif

/* GPC_CPU_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPC_CPU_CTRL base address */
  #define GPC_CPU_CTRL_BASE                        (0x54470000u)
  /** Peripheral GPC_CPU_CTRL base address */
  #define GPC_CPU_CTRL_BASE_NS                     (0x44470000u)
  /** Peripheral GPC_CPU_CTRL base pointer */
  #define GPC_CPU_CTRL                             ((GPC_CPU_CTRL_Type *)GPC_CPU_CTRL_BASE)
  /** Peripheral GPC_CPU_CTRL base pointer */
  #define GPC_CPU_CTRL_NS                          ((GPC_CPU_CTRL_Type *)GPC_CPU_CTRL_BASE_NS)
  /** Array initializer of GPC_CPU_CTRL peripheral base addresses */
  #define GPC_CPU_CTRL_BASE_ADDRS                  { GPC_CPU_CTRL_BASE }
  /** Array initializer of GPC_CPU_CTRL peripheral base pointers */
  #define GPC_CPU_CTRL_BASE_PTRS                   { GPC_CPU_CTRL }
  /** Array initializer of GPC_CPU_CTRL peripheral base addresses */
  #define GPC_CPU_CTRL_BASE_ADDRS_NS               { GPC_CPU_CTRL_BASE_NS }
  /** Array initializer of GPC_CPU_CTRL peripheral base pointers */
  #define GPC_CPU_CTRL_BASE_PTRS_NS                { GPC_CPU_CTRL_NS }
#else
  /** Peripheral GPC_CPU_CTRL base address */
  #define GPC_CPU_CTRL_BASE                        (0x44470000u)
  /** Peripheral GPC_CPU_CTRL base pointer */
  #define GPC_CPU_CTRL                             ((GPC_CPU_CTRL_Type *)GPC_CPU_CTRL_BASE)
  /** Array initializer of GPC_CPU_CTRL peripheral base addresses */
  #define GPC_CPU_CTRL_BASE_ADDRS                  { GPC_CPU_CTRL_BASE }
  /** Array initializer of GPC_CPU_CTRL peripheral base pointers */
  #define GPC_CPU_CTRL_BASE_PTRS                   { GPC_CPU_CTRL }
#endif

/* GPC_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPC_GLOBAL base address */
  #define GPC_GLOBAL_BASE                          (0x54472000u)
  /** Peripheral GPC_GLOBAL base address */
  #define GPC_GLOBAL_BASE_NS                       (0x44472000u)
  /** Peripheral GPC_GLOBAL base pointer */
  #define GPC_GLOBAL                               ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE)
  /** Peripheral GPC_GLOBAL base pointer */
  #define GPC_GLOBAL_NS                            ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE_NS)
  /** Array initializer of GPC_GLOBAL peripheral base addresses */
  #define GPC_GLOBAL_BASE_ADDRS                    { GPC_GLOBAL_BASE }
  /** Array initializer of GPC_GLOBAL peripheral base pointers */
  #define GPC_GLOBAL_BASE_PTRS                     { GPC_GLOBAL }
  /** Array initializer of GPC_GLOBAL peripheral base addresses */
  #define GPC_GLOBAL_BASE_ADDRS_NS                 { GPC_GLOBAL_BASE_NS }
  /** Array initializer of GPC_GLOBAL peripheral base pointers */
  #define GPC_GLOBAL_BASE_PTRS_NS                  { GPC_GLOBAL_NS }
#else
  /** Peripheral GPC_GLOBAL base address */
  #define GPC_GLOBAL_BASE                          (0x44472000u)
  /** Peripheral GPC_GLOBAL base pointer */
  #define GPC_GLOBAL                               ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE)
  /** Array initializer of GPC_GLOBAL peripheral base addresses */
  #define GPC_GLOBAL_BASE_ADDRS                    { GPC_GLOBAL_BASE }
  /** Array initializer of GPC_GLOBAL peripheral base pointers */
  #define GPC_GLOBAL_BASE_PTRS                     { GPC_GLOBAL }
#endif

/* GPC_SYS_SLEEP_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPC_SYS_SLEEP_CTRL base address */
  #define GPC_SYS_SLEEP_CTRL_BASE                  (0x54472800u)
  /** Peripheral GPC_SYS_SLEEP_CTRL base address */
  #define GPC_SYS_SLEEP_CTRL_BASE_NS               (0x44472800u)
  /** Peripheral GPC_SYS_SLEEP_CTRL base pointer */
  #define GPC_SYS_SLEEP_CTRL                       ((GPC_SYS_SLEEP_CTRL_Type *)GPC_SYS_SLEEP_CTRL_BASE)
  /** Peripheral GPC_SYS_SLEEP_CTRL base pointer */
  #define GPC_SYS_SLEEP_CTRL_NS                    ((GPC_SYS_SLEEP_CTRL_Type *)GPC_SYS_SLEEP_CTRL_BASE_NS)
  /** Array initializer of GPC_SYS_SLEEP_CTRL peripheral base addresses */
  #define GPC_SYS_SLEEP_CTRL_BASE_ADDRS            { GPC_SYS_SLEEP_CTRL_BASE }
  /** Array initializer of GPC_SYS_SLEEP_CTRL peripheral base pointers */
  #define GPC_SYS_SLEEP_CTRL_BASE_PTRS             { GPC_SYS_SLEEP_CTRL }
  /** Array initializer of GPC_SYS_SLEEP_CTRL peripheral base addresses */
  #define GPC_SYS_SLEEP_CTRL_BASE_ADDRS_NS         { GPC_SYS_SLEEP_CTRL_BASE_NS }
  /** Array initializer of GPC_SYS_SLEEP_CTRL peripheral base pointers */
  #define GPC_SYS_SLEEP_CTRL_BASE_PTRS_NS          { GPC_SYS_SLEEP_CTRL_NS }
#else
  /** Peripheral GPC_SYS_SLEEP_CTRL base address */
  #define GPC_SYS_SLEEP_CTRL_BASE                  (0x44472800u)
  /** Peripheral GPC_SYS_SLEEP_CTRL base pointer */
  #define GPC_SYS_SLEEP_CTRL                       ((GPC_SYS_SLEEP_CTRL_Type *)GPC_SYS_SLEEP_CTRL_BASE)
  /** Array initializer of GPC_SYS_SLEEP_CTRL peripheral base addresses */
  #define GPC_SYS_SLEEP_CTRL_BASE_ADDRS            { GPC_SYS_SLEEP_CTRL_BASE }
  /** Array initializer of GPC_SYS_SLEEP_CTRL peripheral base pointers */
  #define GPC_SYS_SLEEP_CTRL_BASE_PTRS             { GPC_SYS_SLEEP_CTRL }
#endif

/* GPT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPT1 base address */
  #define GPT1_BASE                                (0x546C0000u)
  /** Peripheral GPT1 base address */
  #define GPT1_BASE_NS                             (0x446C0000u)
  /** Peripheral GPT1 base pointer */
  #define GPT1                                     ((GPT_Type *)GPT1_BASE)
  /** Peripheral GPT1 base pointer */
  #define GPT1_NS                                  ((GPT_Type *)GPT1_BASE_NS)
  /** Peripheral GPT2 base address */
  #define GPT2_BASE                                (0x52EC0000u)
  /** Peripheral GPT2 base address */
  #define GPT2_BASE_NS                             (0x42EC0000u)
  /** Peripheral GPT2 base pointer */
  #define GPT2                                     ((GPT_Type *)GPT2_BASE)
  /** Peripheral GPT2 base pointer */
  #define GPT2_NS                                  ((GPT_Type *)GPT2_BASE_NS)
  /** Array initializer of GPT peripheral base addresses */
  #define GPT_BASE_ADDRS                           { 0u, GPT1_BASE, GPT2_BASE }
  /** Array initializer of GPT peripheral base pointers */
  #define GPT_BASE_PTRS                            { (GPT_Type *)0u, GPT1, GPT2 }
  /** Array initializer of GPT peripheral base addresses */
  #define GPT_BASE_ADDRS_NS                        { 0u, GPT1_BASE_NS, GPT2_BASE_NS }
  /** Array initializer of GPT peripheral base pointers */
  #define GPT_BASE_PTRS_NS                         { (GPT_Type *)0u, GPT1_NS, GPT2_NS }
#else
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
#endif
/** Interrupt vectors for the GPT peripheral type */
#define GPT_IRQS                                 { NotAvail_IRQn, GPT1_IRQn, GPT2_IRQn }

/* I2S - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SAI1 base address */
  #define SAI1_BASE                                (0x543B0000u)
  /** Peripheral SAI1 base address */
  #define SAI1_BASE_NS                             (0x443B0000u)
  /** Peripheral SAI1 base pointer */
  #define SAI1                                     ((I2S_Type *)SAI1_BASE)
  /** Peripheral SAI1 base pointer */
  #define SAI1_NS                                  ((I2S_Type *)SAI1_BASE_NS)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE                                (0x52BB0000u)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE_NS                             (0x42BB0000u)
  /** Peripheral SAI2 base pointer */
  #define SAI2                                     ((I2S_Type *)SAI2_BASE)
  /** Peripheral SAI2 base pointer */
  #define SAI2_NS                                  ((I2S_Type *)SAI2_BASE_NS)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE                                (0x52BC0000u)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE_NS                             (0x42BC0000u)
  /** Peripheral SAI3 base pointer */
  #define SAI3                                     ((I2S_Type *)SAI3_BASE)
  /** Peripheral SAI3 base pointer */
  #define SAI3_NS                                  ((I2S_Type *)SAI3_BASE_NS)
  /** Peripheral SAI4 base address */
  #define SAI4_BASE                                (0x52BD0000u)
  /** Peripheral SAI4 base address */
  #define SAI4_BASE_NS                             (0x42BD0000u)
  /** Peripheral SAI4 base pointer */
  #define SAI4                                     ((I2S_Type *)SAI4_BASE)
  /** Peripheral SAI4 base pointer */
  #define SAI4_NS                                  ((I2S_Type *)SAI4_BASE_NS)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, SAI2_BASE, SAI3_BASE, SAI4_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, SAI2, SAI3, SAI4 }
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS_NS                        { 0u, SAI1_BASE_NS, SAI2_BASE_NS, SAI3_BASE_NS, SAI4_BASE_NS }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS_NS                         { (I2S_Type *)0u, SAI1_NS, SAI2_NS, SAI3_NS, SAI4_NS }
#else
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
#endif
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn, SAI4_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn, SAI4_IRQn }

/* I3C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x54330000u)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE_NS                             (0x44330000u)
  /** Peripheral I3C1 base pointer */
  #define I3C1                                     ((I3C_Type *)I3C1_BASE)
  /** Peripheral I3C1 base pointer */
  #define I3C1_NS                                  ((I3C_Type *)I3C1_BASE_NS)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE                                (0x52520000u)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE_NS                             (0x42520000u)
  /** Peripheral I3C2 base pointer */
  #define I3C2                                     ((I3C_Type *)I3C2_BASE)
  /** Peripheral I3C2 base pointer */
  #define I3C2_NS                                  ((I3C_Type *)I3C2_BASE_NS)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { 0u, I3C1_BASE, I3C2_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { (I3C_Type *)0u, I3C1, I3C2 }
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS_NS                        { 0u, I3C1_BASE_NS, I3C2_BASE_NS }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS_NS                         { (I3C_Type *)0u, I3C1_NS, I3C2_NS }
#else
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
#endif
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { NotAvail_IRQn, I3C1_IRQn, I3C2_IRQn }

/* IEE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IEE base address */
  #define IEE_BASE                                 (0x52E40000u)
  /** Peripheral IEE base address */
  #define IEE_BASE_NS                              (0x42E40000u)
  /** Peripheral IEE base pointer */
  #define IEE                                      ((IEE_Type *)IEE_BASE)
  /** Peripheral IEE base pointer */
  #define IEE_NS                                   ((IEE_Type *)IEE_BASE_NS)
  /** Array initializer of IEE peripheral base addresses */
  #define IEE_BASE_ADDRS                           { IEE_BASE }
  /** Array initializer of IEE peripheral base pointers */
  #define IEE_BASE_PTRS                            { IEE }
  /** Array initializer of IEE peripheral base addresses */
  #define IEE_BASE_ADDRS_NS                        { IEE_BASE_NS }
  /** Array initializer of IEE peripheral base pointers */
  #define IEE_BASE_PTRS_NS                         { IEE_NS }
#else
  /** Peripheral IEE base address */
  #define IEE_BASE                                 (0x42E40000u)
  /** Peripheral IEE base pointer */
  #define IEE                                      ((IEE_Type *)IEE_BASE)
  /** Array initializer of IEE peripheral base addresses */
  #define IEE_BASE_ADDRS                           { IEE_BASE }
  /** Array initializer of IEE peripheral base pointers */
  #define IEE_BASE_PTRS                            { IEE }
#endif

/* IEE_APC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IEE_APC base address */
  #define IEE_APC_BASE                             (0x52E44000u)
  /** Peripheral IEE_APC base address */
  #define IEE_APC_BASE_NS                          (0x42E44000u)
  /** Peripheral IEE_APC base pointer */
  #define IEE_APC                                  ((IEE_APC_Type *)IEE_APC_BASE)
  /** Peripheral IEE_APC base pointer */
  #define IEE_APC_NS                               ((IEE_APC_Type *)IEE_APC_BASE_NS)
  /** Array initializer of IEE_APC peripheral base addresses */
  #define IEE_APC_BASE_ADDRS                       { IEE_APC_BASE }
  /** Array initializer of IEE_APC peripheral base pointers */
  #define IEE_APC_BASE_PTRS                        { IEE_APC }
  /** Array initializer of IEE_APC peripheral base addresses */
  #define IEE_APC_BASE_ADDRS_NS                    { IEE_APC_BASE_NS }
  /** Array initializer of IEE_APC peripheral base pointers */
  #define IEE_APC_BASE_PTRS_NS                     { IEE_APC_NS }
#else
  /** Peripheral IEE_APC base address */
  #define IEE_APC_BASE                             (0x42E44000u)
  /** Peripheral IEE_APC base pointer */
  #define IEE_APC                                  ((IEE_APC_Type *)IEE_APC_BASE)
  /** Array initializer of IEE_APC peripheral base addresses */
  #define IEE_APC_BASE_ADDRS                       { IEE_APC_BASE }
  /** Array initializer of IEE_APC peripheral base pointers */
  #define IEE_APC_BASE_PTRS                        { IEE_APC }
#endif

/* IERC_IERB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IERC_IERB base address */
  #define IERC_IERB_BASE                           (0x70810000u)
  /** Peripheral IERC_IERB base address */
  #define IERC_IERB_BASE_NS                        (0x60810000u)
  /** Peripheral IERC_IERB base pointer */
  #define IERC_IERB                                ((IERC_IERB_Type *)IERC_IERB_BASE)
  /** Peripheral IERC_IERB base pointer */
  #define IERC_IERB_NS                             ((IERC_IERB_Type *)IERC_IERB_BASE_NS)
  /** Array initializer of IERC_IERB peripheral base addresses */
  #define IERC_IERB_BASE_ADDRS                     { IERC_IERB_BASE }
  /** Array initializer of IERC_IERB peripheral base pointers */
  #define IERC_IERB_BASE_PTRS                      { IERC_IERB }
  /** Array initializer of IERC_IERB peripheral base addresses */
  #define IERC_IERB_BASE_ADDRS_NS                  { IERC_IERB_BASE_NS }
  /** Array initializer of IERC_IERB peripheral base pointers */
  #define IERC_IERB_BASE_PTRS_NS                   { IERC_IERB_NS }
#else
  /** Peripheral IERC_IERB base address */
  #define IERC_IERB_BASE                           (0x60810000u)
  /** Peripheral IERC_IERB base pointer */
  #define IERC_IERB                                ((IERC_IERB_Type *)IERC_IERB_BASE)
  /** Array initializer of IERC_IERB peripheral base addresses */
  #define IERC_IERB_BASE_ADDRS                     { IERC_IERB_BASE }
  /** Array initializer of IERC_IERB peripheral base pointers */
  #define IERC_IERB_BASE_PTRS                      { IERC_IERB }
#endif

/* IERC_PCI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IERC_F0_PCI_HDR_TYPE0 base address */
  #define IERC_F0_PCI_HDR_TYPE0_BASE               (0x700F8000u)
  /** Peripheral IERC_F0_PCI_HDR_TYPE0 base address */
  #define IERC_F0_PCI_HDR_TYPE0_BASE_NS            (0x600F8000u)
  /** Peripheral IERC_F0_PCI_HDR_TYPE0 base pointer */
  #define IERC_F0_PCI_HDR_TYPE0                    ((IERC_PCI_Type *)IERC_F0_PCI_HDR_TYPE0_BASE)
  /** Peripheral IERC_F0_PCI_HDR_TYPE0 base pointer */
  #define IERC_F0_PCI_HDR_TYPE0_NS                 ((IERC_PCI_Type *)IERC_F0_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of IERC_PCI peripheral base addresses */
  #define IERC_PCI_BASE_ADDRS                      { IERC_F0_PCI_HDR_TYPE0_BASE }
  /** Array initializer of IERC_PCI peripheral base pointers */
  #define IERC_PCI_BASE_PTRS                       { IERC_F0_PCI_HDR_TYPE0 }
  /** Array initializer of IERC_PCI peripheral base addresses */
  #define IERC_PCI_BASE_ADDRS_NS                   { IERC_F0_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of IERC_PCI peripheral base pointers */
  #define IERC_PCI_BASE_PTRS_NS                    { IERC_F0_PCI_HDR_TYPE0_NS }
#else
  /** Peripheral IERC_F0_PCI_HDR_TYPE0 base address */
  #define IERC_F0_PCI_HDR_TYPE0_BASE               (0x600F8000u)
  /** Peripheral IERC_F0_PCI_HDR_TYPE0 base pointer */
  #define IERC_F0_PCI_HDR_TYPE0                    ((IERC_PCI_Type *)IERC_F0_PCI_HDR_TYPE0_BASE)
  /** Array initializer of IERC_PCI peripheral base addresses */
  #define IERC_PCI_BASE_ADDRS                      { IERC_F0_PCI_HDR_TYPE0_BASE }
  /** Array initializer of IERC_PCI peripheral base pointers */
  #define IERC_PCI_BASE_PTRS                       { IERC_F0_PCI_HDR_TYPE0 }
#endif

/* IOMUXC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOMUXC base address */
  #define IOMUXC_BASE                              (0x52A10000u)
  /** Peripheral IOMUXC base address */
  #define IOMUXC_BASE_NS                           (0x42A10000u)
  /** Peripheral IOMUXC base pointer */
  #define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
  /** Peripheral IOMUXC base pointer */
  #define IOMUXC_NS                                ((IOMUXC_Type *)IOMUXC_BASE_NS)
  /** Array initializer of IOMUXC peripheral base addresses */
  #define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
  /** Array initializer of IOMUXC peripheral base pointers */
  #define IOMUXC_BASE_PTRS                         { IOMUXC }
  /** Array initializer of IOMUXC peripheral base addresses */
  #define IOMUXC_BASE_ADDRS_NS                     { IOMUXC_BASE_NS }
  /** Array initializer of IOMUXC peripheral base pointers */
  #define IOMUXC_BASE_PTRS_NS                      { IOMUXC_NS }
#else
  /** Peripheral IOMUXC base address */
  #define IOMUXC_BASE                              (0x42A10000u)
  /** Peripheral IOMUXC base pointer */
  #define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
  /** Array initializer of IOMUXC peripheral base addresses */
  #define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
  /** Array initializer of IOMUXC peripheral base pointers */
  #define IOMUXC_BASE_PTRS                         { IOMUXC }
#endif

/* IOMUXC_AON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOMUXC_AON base address */
  #define IOMUXC_AON_BASE                          (0x543C0000u)
  /** Peripheral IOMUXC_AON base address */
  #define IOMUXC_AON_BASE_NS                       (0x443C0000u)
  /** Peripheral IOMUXC_AON base pointer */
  #define IOMUXC_AON                               ((IOMUXC_AON_Type *)IOMUXC_AON_BASE)
  /** Peripheral IOMUXC_AON base pointer */
  #define IOMUXC_AON_NS                            ((IOMUXC_AON_Type *)IOMUXC_AON_BASE_NS)
  /** Array initializer of IOMUXC_AON peripheral base addresses */
  #define IOMUXC_AON_BASE_ADDRS                    { IOMUXC_AON_BASE }
  /** Array initializer of IOMUXC_AON peripheral base pointers */
  #define IOMUXC_AON_BASE_PTRS                     { IOMUXC_AON }
  /** Array initializer of IOMUXC_AON peripheral base addresses */
  #define IOMUXC_AON_BASE_ADDRS_NS                 { IOMUXC_AON_BASE_NS }
  /** Array initializer of IOMUXC_AON peripheral base pointers */
  #define IOMUXC_AON_BASE_PTRS_NS                  { IOMUXC_AON_NS }
#else
  /** Peripheral IOMUXC_AON base address */
  #define IOMUXC_AON_BASE                          (0x443C0000u)
  /** Peripheral IOMUXC_AON base pointer */
  #define IOMUXC_AON                               ((IOMUXC_AON_Type *)IOMUXC_AON_BASE)
  /** Array initializer of IOMUXC_AON peripheral base addresses */
  #define IOMUXC_AON_BASE_ADDRS                    { IOMUXC_AON_BASE }
  /** Array initializer of IOMUXC_AON peripheral base pointers */
  #define IOMUXC_AON_BASE_PTRS                     { IOMUXC_AON }
#endif

/* KPP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral KPP base address */
  #define KPP_BASE                                 (0x52A00000u)
  /** Peripheral KPP base address */
  #define KPP_BASE_NS                              (0x42A00000u)
  /** Peripheral KPP base pointer */
  #define KPP                                      ((KPP_Type *)KPP_BASE)
  /** Peripheral KPP base pointer */
  #define KPP_NS                                   ((KPP_Type *)KPP_BASE_NS)
  /** Array initializer of KPP peripheral base addresses */
  #define KPP_BASE_ADDRS                           { KPP_BASE }
  /** Array initializer of KPP peripheral base pointers */
  #define KPP_BASE_PTRS                            { KPP }
  /** Array initializer of KPP peripheral base addresses */
  #define KPP_BASE_ADDRS_NS                        { KPP_BASE_NS }
  /** Array initializer of KPP peripheral base pointers */
  #define KPP_BASE_PTRS_NS                         { KPP_NS }
#else
  /** Peripheral KPP base address */
  #define KPP_BASE                                 (0x42A00000u)
  /** Peripheral KPP base pointer */
  #define KPP                                      ((KPP_Type *)KPP_BASE)
  /** Array initializer of KPP peripheral base addresses */
  #define KPP_BASE_ADDRS                           { KPP_BASE }
  /** Array initializer of KPP peripheral base pointers */
  #define KPP_BASE_PTRS                            { KPP }
#endif
/** Interrupt vectors for the KPP peripheral type */
#define KPP_IRQS                                 { KPP_IRQn }

/* LPI2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x54340000u)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE_NS                           (0x44340000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1_NS                                ((LPI2C_Type *)LPI2C1_BASE_NS)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE                              (0x54350000u)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE_NS                           (0x44350000u)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2_NS                                ((LPI2C_Type *)LPI2C2_BASE_NS)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE                              (0x52530000u)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE_NS                           (0x42530000u)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3_NS                                ((LPI2C_Type *)LPI2C3_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2, LPI2C3 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { 0u, LPI2C1_BASE_NS, LPI2C2_BASE_NS, LPI2C3_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { (LPI2C_Type *)0u, LPI2C1_NS, LPI2C2_NS, LPI2C3_NS }
#else
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
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2, LPI2C3 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn }

/* LPIT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPIT1 base address */
  #define LPIT1_BASE                               (0x542F0000u)
  /** Peripheral LPIT1 base address */
  #define LPIT1_BASE_NS                            (0x442F0000u)
  /** Peripheral LPIT1 base pointer */
  #define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
  /** Peripheral LPIT1 base pointer */
  #define LPIT1_NS                                 ((LPIT_Type *)LPIT1_BASE_NS)
  /** Peripheral LPIT2 base address */
  #define LPIT2_BASE                               (0x524C0000u)
  /** Peripheral LPIT2 base address */
  #define LPIT2_BASE_NS                            (0x424C0000u)
  /** Peripheral LPIT2 base pointer */
  #define LPIT2                                    ((LPIT_Type *)LPIT2_BASE)
  /** Peripheral LPIT2 base pointer */
  #define LPIT2_NS                                 ((LPIT_Type *)LPIT2_BASE_NS)
  /** Peripheral LPIT3 base address */
  #define LPIT3_BASE                               (0x52CC0000u)
  /** Peripheral LPIT3 base address */
  #define LPIT3_BASE_NS                            (0x42CC0000u)
  /** Peripheral LPIT3 base pointer */
  #define LPIT3                                    ((LPIT_Type *)LPIT3_BASE)
  /** Peripheral LPIT3 base pointer */
  #define LPIT3_NS                                 ((LPIT_Type *)LPIT3_BASE_NS)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { 0u, LPIT1_BASE, LPIT2_BASE, LPIT3_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { (LPIT_Type *)0u, LPIT1, LPIT2, LPIT3 }
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS_NS                       { 0u, LPIT1_BASE_NS, LPIT2_BASE_NS, LPIT3_BASE_NS }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS_NS                        { (LPIT_Type *)0u, LPIT1_NS, LPIT2_NS, LPIT3_NS }
#else
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
#endif
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { LPIT1_IRQn, LPIT1_IRQn, LPIT1_IRQn, LPIT1_IRQn }, { LPIT2_IRQn, LPIT2_IRQn, LPIT2_IRQn, LPIT2_IRQn }, { LPIT3_IRQn, LPIT3_IRQn, LPIT3_IRQn, LPIT3_IRQn } }

/* LPSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x54360000u)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE_NS                           (0x44360000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1_NS                                ((LPSPI_Type *)LPSPI1_BASE_NS)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE                              (0x54370000u)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE_NS                           (0x44370000u)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2_NS                                ((LPSPI_Type *)LPSPI2_BASE_NS)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE                              (0x52550000u)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE_NS                           (0x42550000u)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3_NS                                ((LPSPI_Type *)LPSPI3_BASE_NS)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE                              (0x52560000u)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE_NS                           (0x42560000u)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4_NS                                ((LPSPI_Type *)LPSPI4_BASE_NS)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2, LPSPI3, LPSPI4 }
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS_NS                      { 0u, LPSPI1_BASE_NS, LPSPI2_BASE_NS, LPSPI3_BASE_NS, LPSPI4_BASE_NS }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS_NS                       { (LPSPI_Type *)0u, LPSPI1_NS, LPSPI2_NS, LPSPI3_NS, LPSPI4_NS }
#else
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
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2, LPSPI3, LPSPI4 }
#endif
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, LPSPI4_IRQn }

/* LPTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE                              (0x54300000u)
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE_NS                           (0x44300000u)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1_NS                                ((LPTMR_Type *)LPTMR1_BASE_NS)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { 0u, LPTMR1_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { (LPTMR_Type *)0u, LPTMR1 }
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS_NS                      { 0u, LPTMR1_BASE_NS }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS_NS                       { (LPTMR_Type *)0u, LPTMR1_NS }
#else
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE                              (0x44300000u)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { 0u, LPTMR1_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { (LPTMR_Type *)0u, LPTMR1 }
#endif
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { NotAvail_IRQn, LPTMR1_IRQn }

/* LPUART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x54380000u)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE_NS                          (0x44380000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1_NS                               ((LPUART_Type *)LPUART1_BASE_NS)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE                             (0x54390000u)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE_NS                          (0x44390000u)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2_NS                               ((LPUART_Type *)LPUART2_BASE_NS)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE                             (0x52570000u)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE_NS                          (0x42570000u)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3_NS                               ((LPUART_Type *)LPUART3_BASE_NS)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE                             (0x52580000u)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE_NS                          (0x42580000u)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4_NS                               ((LPUART_Type *)LPUART4_BASE_NS)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE                             (0x52590000u)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE_NS                          (0x42590000u)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5_NS                               ((LPUART_Type *)LPUART5_BASE_NS)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE                             (0x525A0000u)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE_NS                          (0x425A0000u)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6_NS                               ((LPUART_Type *)LPUART6_BASE_NS)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE                             (0x54570000u)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE_NS                          (0x44570000u)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7_NS                               ((LPUART_Type *)LPUART7_BASE_NS)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE                             (0x52DA0000u)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE_NS                          (0x42DA0000u)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8_NS                               ((LPUART_Type *)LPUART8_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { 0u, LPUART1_BASE_NS, LPUART2_BASE_NS, LPUART3_BASE_NS, LPUART4_BASE_NS, LPUART5_BASE_NS, LPUART6_BASE_NS, LPUART7_BASE_NS, LPUART8_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { (LPUART_Type *)0u, LPUART1_NS, LPUART2_NS, LPUART3_NS, LPUART4_NS, LPUART5_NS, LPUART6_NS, LPUART7_NS, LPUART8_NS }
#else
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
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn, LPUART6_IRQn, LPUART7_IRQn, LPUART8_IRQn }

/* MECC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MECC1 base address */
  #define MECC1_BASE                               (0x52920000u)
  /** Peripheral MECC1 base address */
  #define MECC1_BASE_NS                            (0x42920000u)
  /** Peripheral MECC1 base pointer */
  #define MECC1                                    ((MECC_Type *)MECC1_BASE)
  /** Peripheral MECC1 base pointer */
  #define MECC1_NS                                 ((MECC_Type *)MECC1_BASE_NS)
  /** Peripheral MECC2 base address */
  #define MECC2_BASE                               (0x52930000u)
  /** Peripheral MECC2 base address */
  #define MECC2_BASE_NS                            (0x42930000u)
  /** Peripheral MECC2 base pointer */
  #define MECC2                                    ((MECC_Type *)MECC2_BASE)
  /** Peripheral MECC2 base pointer */
  #define MECC2_NS                                 ((MECC_Type *)MECC2_BASE_NS)
  /** Array initializer of MECC peripheral base addresses */
  #define MECC_BASE_ADDRS                          { 0u, MECC1_BASE, MECC2_BASE }
  /** Array initializer of MECC peripheral base pointers */
  #define MECC_BASE_PTRS                           { (MECC_Type *)0u, MECC1, MECC2 }
  /** Array initializer of MECC peripheral base addresses */
  #define MECC_BASE_ADDRS_NS                       { 0u, MECC1_BASE_NS, MECC2_BASE_NS }
  /** Array initializer of MECC peripheral base pointers */
  #define MECC_BASE_PTRS_NS                        { (MECC_Type *)0u, MECC1_NS, MECC2_NS }
#else
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
#endif

/* MSGINTR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MSGINTR1 base address */
  #define MSGINTR1_BASE                            (0x528A0000u)
  /** Peripheral MSGINTR1 base address */
  #define MSGINTR1_BASE_NS                         (0x428A0000u)
  /** Peripheral MSGINTR1 base pointer */
  #define MSGINTR1                                 ((MSGINTR_Type *)MSGINTR1_BASE)
  /** Peripheral MSGINTR1 base pointer */
  #define MSGINTR1_NS                              ((MSGINTR_Type *)MSGINTR1_BASE_NS)
  /** Peripheral MSGINTR2 base address */
  #define MSGINTR2_BASE                            (0x528B0000u)
  /** Peripheral MSGINTR2 base address */
  #define MSGINTR2_BASE_NS                         (0x428B0000u)
  /** Peripheral MSGINTR2 base pointer */
  #define MSGINTR2                                 ((MSGINTR_Type *)MSGINTR2_BASE)
  /** Peripheral MSGINTR2 base pointer */
  #define MSGINTR2_NS                              ((MSGINTR_Type *)MSGINTR2_BASE_NS)
  /** Peripheral MSGINTR3 base address */
  #define MSGINTR3_BASE                            (0x528C0000u)
  /** Peripheral MSGINTR3 base address */
  #define MSGINTR3_BASE_NS                         (0x428C0000u)
  /** Peripheral MSGINTR3 base pointer */
  #define MSGINTR3                                 ((MSGINTR_Type *)MSGINTR3_BASE)
  /** Peripheral MSGINTR3 base pointer */
  #define MSGINTR3_NS                              ((MSGINTR_Type *)MSGINTR3_BASE_NS)
  /** Peripheral MSGINTR4 base address */
  #define MSGINTR4_BASE                            (0x528D0000u)
  /** Peripheral MSGINTR4 base address */
  #define MSGINTR4_BASE_NS                         (0x428D0000u)
  /** Peripheral MSGINTR4 base pointer */
  #define MSGINTR4                                 ((MSGINTR_Type *)MSGINTR4_BASE)
  /** Peripheral MSGINTR4 base pointer */
  #define MSGINTR4_NS                              ((MSGINTR_Type *)MSGINTR4_BASE_NS)
  /** Peripheral MSGINTR5 base address */
  #define MSGINTR5_BASE                            (0x528E0000u)
  /** Peripheral MSGINTR5 base address */
  #define MSGINTR5_BASE_NS                         (0x428E0000u)
  /** Peripheral MSGINTR5 base pointer */
  #define MSGINTR5                                 ((MSGINTR_Type *)MSGINTR5_BASE)
  /** Peripheral MSGINTR5 base pointer */
  #define MSGINTR5_NS                              ((MSGINTR_Type *)MSGINTR5_BASE_NS)
  /** Peripheral MSGINTR6 base address */
  #define MSGINTR6_BASE                            (0x528F0000u)
  /** Peripheral MSGINTR6 base address */
  #define MSGINTR6_BASE_NS                         (0x428F0000u)
  /** Peripheral MSGINTR6 base pointer */
  #define MSGINTR6                                 ((MSGINTR_Type *)MSGINTR6_BASE)
  /** Peripheral MSGINTR6 base pointer */
  #define MSGINTR6_NS                              ((MSGINTR_Type *)MSGINTR6_BASE_NS)
  /** Array initializer of MSGINTR peripheral base addresses */
  #define MSGINTR_BASE_ADDRS                       { 0u, MSGINTR1_BASE, MSGINTR2_BASE, MSGINTR3_BASE, MSGINTR4_BASE, MSGINTR5_BASE, MSGINTR6_BASE }
  /** Array initializer of MSGINTR peripheral base pointers */
  #define MSGINTR_BASE_PTRS                        { (MSGINTR_Type *)0u, MSGINTR1, MSGINTR2, MSGINTR3, MSGINTR4, MSGINTR5, MSGINTR6 }
  /** Array initializer of MSGINTR peripheral base addresses */
  #define MSGINTR_BASE_ADDRS_NS                    { 0u, MSGINTR1_BASE_NS, MSGINTR2_BASE_NS, MSGINTR3_BASE_NS, MSGINTR4_BASE_NS, MSGINTR5_BASE_NS, MSGINTR6_BASE_NS }
  /** Array initializer of MSGINTR peripheral base pointers */
  #define MSGINTR_BASE_PTRS_NS                     { (MSGINTR_Type *)0u, MSGINTR1_NS, MSGINTR2_NS, MSGINTR3_NS, MSGINTR4_NS, MSGINTR5_NS, MSGINTR6_NS }
#else
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
#endif

/* MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE                             (0x54220000u)
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE_NS                          (0x44220000u)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA_NS                               ((MU_Type *)MU1_MUA_BASE_NS)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE                             (0x52430000u)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE_NS                          (0x42430000u)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA                                  ((MU_Type *)MU2_MUA_BASE)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA_NS                               ((MU_Type *)MU2_MUA_BASE_NS)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU1_MUA_BASE, MU2_MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU1_MUA, MU2_MUA }
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS_NS                         { MU1_MUA_BASE_NS, MU2_MUA_BASE_NS }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS_NS                          { MU1_MUA_NS, MU2_MUA_NS }
#else
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE                             (0x44220000u)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE                             (0x42430000u)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA                                  ((MU_Type *)MU2_MUA_BASE)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU1_MUA_BASE, MU2_MUA_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU1_MUA, MU2_MUA }
#endif
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU1_IRQn, MU2_IRQn }

/* NETC_ENETC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENETC0_BASE base address */
  #define ENETC0_BASE_BASE                         (0x70B10000u)
  /** Peripheral ENETC0_BASE base address */
  #define ENETC0_BASE_BASE_NS                      (0x60B10000u)
  /** Peripheral ENETC0_BASE base pointer */
  #define ENETC0_BASE                              ((NETC_ENETC_Type *)ENETC0_BASE_BASE)
  /** Peripheral ENETC0_BASE base pointer */
  #define ENETC0_BASE_NS                           ((NETC_ENETC_Type *)ENETC0_BASE_BASE_NS)
  /** Peripheral ENETC1_BASE base address */
  #define ENETC1_BASE_BASE                         (0x70B50000u)
  /** Peripheral ENETC1_BASE base address */
  #define ENETC1_BASE_BASE_NS                      (0x60B50000u)
  /** Peripheral ENETC1_BASE base pointer */
  #define ENETC1_BASE                              ((NETC_ENETC_Type *)ENETC1_BASE_BASE)
  /** Peripheral ENETC1_BASE base pointer */
  #define ENETC1_BASE_NS                           ((NETC_ENETC_Type *)ENETC1_BASE_BASE_NS)
  /** Array initializer of NETC_ENETC peripheral base addresses */
  #define NETC_ENETC_BASE_ADDRS                    { ENETC0_BASE_BASE, ENETC1_BASE_BASE }
  /** Array initializer of NETC_ENETC peripheral base pointers */
  #define NETC_ENETC_BASE_PTRS                     { ENETC0_BASE, ENETC1_BASE }
  /** Array initializer of NETC_ENETC peripheral base addresses */
  #define NETC_ENETC_BASE_ADDRS_NS                 { ENETC0_BASE_BASE_NS, ENETC1_BASE_BASE_NS }
  /** Array initializer of NETC_ENETC peripheral base pointers */
  #define NETC_ENETC_BASE_PTRS_NS                  { ENETC0_BASE_NS, ENETC1_BASE_NS }
#else
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
#endif

/* NETC_ETH_LINK - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENETC0_ETH_MAC_PORT base address */
  #define ENETC0_ETH_MAC_PORT_BASE                 (0x70B15000u)
  /** Peripheral ENETC0_ETH_MAC_PORT base address */
  #define ENETC0_ETH_MAC_PORT_BASE_NS              (0x60B15000u)
  /** Peripheral ENETC0_ETH_MAC_PORT base pointer */
  #define ENETC0_ETH_MAC_PORT                      ((NETC_ETH_LINK_Type *)ENETC0_ETH_MAC_PORT_BASE)
  /** Peripheral ENETC0_ETH_MAC_PORT base pointer */
  #define ENETC0_ETH_MAC_PORT_NS                   ((NETC_ETH_LINK_Type *)ENETC0_ETH_MAC_PORT_BASE_NS)
  /** Peripheral SW0_ETH_MAC_PORT0 base address */
  #define SW0_ETH_MAC_PORT0_BASE                   (0x70A05000u)
  /** Peripheral SW0_ETH_MAC_PORT0 base address */
  #define SW0_ETH_MAC_PORT0_BASE_NS                (0x60A05000u)
  /** Peripheral SW0_ETH_MAC_PORT0 base pointer */
  #define SW0_ETH_MAC_PORT0                        ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT0_BASE)
  /** Peripheral SW0_ETH_MAC_PORT0 base pointer */
  #define SW0_ETH_MAC_PORT0_NS                     ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT0_BASE_NS)
  /** Peripheral SW0_ETH_MAC_PORT1 base address */
  #define SW0_ETH_MAC_PORT1_BASE                   (0x70A09000u)
  /** Peripheral SW0_ETH_MAC_PORT1 base address */
  #define SW0_ETH_MAC_PORT1_BASE_NS                (0x60A09000u)
  /** Peripheral SW0_ETH_MAC_PORT1 base pointer */
  #define SW0_ETH_MAC_PORT1                        ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT1_BASE)
  /** Peripheral SW0_ETH_MAC_PORT1 base pointer */
  #define SW0_ETH_MAC_PORT1_NS                     ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT1_BASE_NS)
  /** Peripheral SW0_ETH_MAC_PORT2 base address */
  #define SW0_ETH_MAC_PORT2_BASE                   (0x70A0D000u)
  /** Peripheral SW0_ETH_MAC_PORT2 base address */
  #define SW0_ETH_MAC_PORT2_BASE_NS                (0x60A0D000u)
  /** Peripheral SW0_ETH_MAC_PORT2 base pointer */
  #define SW0_ETH_MAC_PORT2                        ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT2_BASE)
  /** Peripheral SW0_ETH_MAC_PORT2 base pointer */
  #define SW0_ETH_MAC_PORT2_NS                     ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT2_BASE_NS)
  /** Peripheral SW0_ETH_MAC_PORT3 base address */
  #define SW0_ETH_MAC_PORT3_BASE                   (0x70A11000u)
  /** Peripheral SW0_ETH_MAC_PORT3 base address */
  #define SW0_ETH_MAC_PORT3_BASE_NS                (0x60A11000u)
  /** Peripheral SW0_ETH_MAC_PORT3 base pointer */
  #define SW0_ETH_MAC_PORT3                        ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT3_BASE)
  /** Peripheral SW0_ETH_MAC_PORT3 base pointer */
  #define SW0_ETH_MAC_PORT3_NS                     ((NETC_ETH_LINK_Type *)SW0_ETH_MAC_PORT3_BASE_NS)
  /** Array initializer of NETC_ETH_LINK peripheral base addresses */
  #define NETC_ETH_LINK_BASE_ADDRS                 { ENETC0_ETH_MAC_PORT_BASE, SW0_ETH_MAC_PORT0_BASE, SW0_ETH_MAC_PORT1_BASE, SW0_ETH_MAC_PORT2_BASE, SW0_ETH_MAC_PORT3_BASE }
  /** Array initializer of NETC_ETH_LINK peripheral base pointers */
  #define NETC_ETH_LINK_BASE_PTRS                  { ENETC0_ETH_MAC_PORT, SW0_ETH_MAC_PORT0, SW0_ETH_MAC_PORT1, SW0_ETH_MAC_PORT2, SW0_ETH_MAC_PORT3 }
  /** Array initializer of NETC_ETH_LINK peripheral base addresses */
  #define NETC_ETH_LINK_BASE_ADDRS_NS              { ENETC0_ETH_MAC_PORT_BASE_NS, SW0_ETH_MAC_PORT0_BASE_NS, SW0_ETH_MAC_PORT1_BASE_NS, SW0_ETH_MAC_PORT2_BASE_NS, SW0_ETH_MAC_PORT3_BASE_NS }
  /** Array initializer of NETC_ETH_LINK peripheral base pointers */
  #define NETC_ETH_LINK_BASE_PTRS_NS               { ENETC0_ETH_MAC_PORT_NS, SW0_ETH_MAC_PORT0_NS, SW0_ETH_MAC_PORT1_NS, SW0_ETH_MAC_PORT2_NS, SW0_ETH_MAC_PORT3_NS }
#else
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
#endif

/* NETC_IERB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC_IERB base address */
  #define NETC_IERB_BASE                           (0x70800000u)
  /** Peripheral NETC_IERB base address */
  #define NETC_IERB_BASE_NS                        (0x60800000u)
  /** Peripheral NETC_IERB base pointer */
  #define NETC_IERB                                ((NETC_IERB_Type *)NETC_IERB_BASE)
  /** Peripheral NETC_IERB base pointer */
  #define NETC_IERB_NS                             ((NETC_IERB_Type *)NETC_IERB_BASE_NS)
  /** Array initializer of NETC_IERB peripheral base addresses */
  #define NETC_IERB_BASE_ADDRS                     { NETC_IERB_BASE }
  /** Array initializer of NETC_IERB peripheral base pointers */
  #define NETC_IERB_BASE_PTRS                      { NETC_IERB }
  /** Array initializer of NETC_IERB peripheral base addresses */
  #define NETC_IERB_BASE_ADDRS_NS                  { NETC_IERB_BASE_NS }
  /** Array initializer of NETC_IERB peripheral base pointers */
  #define NETC_IERB_BASE_PTRS_NS                   { NETC_IERB_NS }
#else
  /** Peripheral NETC_IERB base address */
  #define NETC_IERB_BASE                           (0x60800000u)
  /** Peripheral NETC_IERB base pointer */
  #define NETC_IERB                                ((NETC_IERB_Type *)NETC_IERB_BASE)
  /** Array initializer of NETC_IERB peripheral base addresses */
  #define NETC_IERB_BASE_ADDRS                     { NETC_IERB_BASE }
  /** Array initializer of NETC_IERB peripheral base pointers */
  #define NETC_IERB_BASE_PTRS                      { NETC_IERB }
#endif

/* NETC_PORT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENETC0_PORT base address */
  #define ENETC0_PORT_BASE                         (0x70B14000u)
  /** Peripheral ENETC0_PORT base address */
  #define ENETC0_PORT_BASE_NS                      (0x60B14000u)
  /** Peripheral ENETC0_PORT base pointer */
  #define ENETC0_PORT                              ((NETC_PORT_Type *)ENETC0_PORT_BASE)
  /** Peripheral ENETC0_PORT base pointer */
  #define ENETC0_PORT_NS                           ((NETC_PORT_Type *)ENETC0_PORT_BASE_NS)
  /** Peripheral ENETC1_PORT base address */
  #define ENETC1_PORT_BASE                         (0x70B54000u)
  /** Peripheral ENETC1_PORT base address */
  #define ENETC1_PORT_BASE_NS                      (0x60B54000u)
  /** Peripheral ENETC1_PORT base pointer */
  #define ENETC1_PORT                              ((NETC_PORT_Type *)ENETC1_PORT_BASE)
  /** Peripheral ENETC1_PORT base pointer */
  #define ENETC1_PORT_NS                           ((NETC_PORT_Type *)ENETC1_PORT_BASE_NS)
  /** Peripheral SW0_PORT0 base address */
  #define SW0_PORT0_BASE                           (0x70A04000u)
  /** Peripheral SW0_PORT0 base address */
  #define SW0_PORT0_BASE_NS                        (0x60A04000u)
  /** Peripheral SW0_PORT0 base pointer */
  #define SW0_PORT0                                ((NETC_PORT_Type *)SW0_PORT0_BASE)
  /** Peripheral SW0_PORT0 base pointer */
  #define SW0_PORT0_NS                             ((NETC_PORT_Type *)SW0_PORT0_BASE_NS)
  /** Peripheral SW0_PORT1 base address */
  #define SW0_PORT1_BASE                           (0x70A08000u)
  /** Peripheral SW0_PORT1 base address */
  #define SW0_PORT1_BASE_NS                        (0x60A08000u)
  /** Peripheral SW0_PORT1 base pointer */
  #define SW0_PORT1                                ((NETC_PORT_Type *)SW0_PORT1_BASE)
  /** Peripheral SW0_PORT1 base pointer */
  #define SW0_PORT1_NS                             ((NETC_PORT_Type *)SW0_PORT1_BASE_NS)
  /** Peripheral SW0_PORT2 base address */
  #define SW0_PORT2_BASE                           (0x70A0C000u)
  /** Peripheral SW0_PORT2 base address */
  #define SW0_PORT2_BASE_NS                        (0x60A0C000u)
  /** Peripheral SW0_PORT2 base pointer */
  #define SW0_PORT2                                ((NETC_PORT_Type *)SW0_PORT2_BASE)
  /** Peripheral SW0_PORT2 base pointer */
  #define SW0_PORT2_NS                             ((NETC_PORT_Type *)SW0_PORT2_BASE_NS)
  /** Peripheral SW0_PORT3 base address */
  #define SW0_PORT3_BASE                           (0x70A10000u)
  /** Peripheral SW0_PORT3 base address */
  #define SW0_PORT3_BASE_NS                        (0x60A10000u)
  /** Peripheral SW0_PORT3 base pointer */
  #define SW0_PORT3                                ((NETC_PORT_Type *)SW0_PORT3_BASE)
  /** Peripheral SW0_PORT3 base pointer */
  #define SW0_PORT3_NS                             ((NETC_PORT_Type *)SW0_PORT3_BASE_NS)
  /** Peripheral SW0_PORT4 base address */
  #define SW0_PORT4_BASE                           (0x70A14000u)
  /** Peripheral SW0_PORT4 base address */
  #define SW0_PORT4_BASE_NS                        (0x60A14000u)
  /** Peripheral SW0_PORT4 base pointer */
  #define SW0_PORT4                                ((NETC_PORT_Type *)SW0_PORT4_BASE)
  /** Peripheral SW0_PORT4 base pointer */
  #define SW0_PORT4_NS                             ((NETC_PORT_Type *)SW0_PORT4_BASE_NS)
  /** Array initializer of NETC_PORT peripheral base addresses */
  #define NETC_PORT_BASE_ADDRS                     { ENETC0_PORT_BASE, ENETC1_PORT_BASE, SW0_PORT0_BASE, SW0_PORT1_BASE, SW0_PORT2_BASE, SW0_PORT3_BASE, SW0_PORT4_BASE }
  /** Array initializer of NETC_PORT peripheral base pointers */
  #define NETC_PORT_BASE_PTRS                      { ENETC0_PORT, ENETC1_PORT, SW0_PORT0, SW0_PORT1, SW0_PORT2, SW0_PORT3, SW0_PORT4 }
  /** Array initializer of NETC_PORT peripheral base addresses */
  #define NETC_PORT_BASE_ADDRS_NS                  { ENETC0_PORT_BASE_NS, ENETC1_PORT_BASE_NS, SW0_PORT0_BASE_NS, SW0_PORT1_BASE_NS, SW0_PORT2_BASE_NS, SW0_PORT3_BASE_NS, SW0_PORT4_BASE_NS }
  /** Array initializer of NETC_PORT peripheral base pointers */
  #define NETC_PORT_BASE_PTRS_NS                   { ENETC0_PORT_NS, ENETC1_PORT_NS, SW0_PORT0_NS, SW0_PORT1_NS, SW0_PORT2_NS, SW0_PORT3_NS, SW0_PORT4_NS }
#else
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
#endif

/* NETC_PRIV - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC_PRIV base address */
  #define NETC_PRIV_BASE                           (0x70900000u)
  /** Peripheral NETC_PRIV base address */
  #define NETC_PRIV_BASE_NS                        (0x60900000u)
  /** Peripheral NETC_PRIV base pointer */
  #define NETC_PRIV                                ((NETC_PRIV_Type *)NETC_PRIV_BASE)
  /** Peripheral NETC_PRIV base pointer */
  #define NETC_PRIV_NS                             ((NETC_PRIV_Type *)NETC_PRIV_BASE_NS)
  /** Array initializer of NETC_PRIV peripheral base addresses */
  #define NETC_PRIV_BASE_ADDRS                     { NETC_PRIV_BASE }
  /** Array initializer of NETC_PRIV peripheral base pointers */
  #define NETC_PRIV_BASE_PTRS                      { NETC_PRIV }
  /** Array initializer of NETC_PRIV peripheral base addresses */
  #define NETC_PRIV_BASE_ADDRS_NS                  { NETC_PRIV_BASE_NS }
  /** Array initializer of NETC_PRIV peripheral base pointers */
  #define NETC_PRIV_BASE_PTRS_NS                   { NETC_PRIV_NS }
#else
  /** Peripheral NETC_PRIV base address */
  #define NETC_PRIV_BASE                           (0x60900000u)
  /** Peripheral NETC_PRIV base pointer */
  #define NETC_PRIV                                ((NETC_PRIV_Type *)NETC_PRIV_BASE)
  /** Array initializer of NETC_PRIV peripheral base addresses */
  #define NETC_PRIV_BASE_ADDRS                     { NETC_PRIV_BASE }
  /** Array initializer of NETC_PRIV peripheral base pointers */
  #define NETC_PRIV_BASE_PTRS                      { NETC_PRIV }
#endif

/* NETC_PSEUDO_LINK - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENETC1_PSEUDO_MAC_PORT base address */
  #define ENETC1_PSEUDO_MAC_PORT_BASE              (0x70B55000u)
  /** Peripheral ENETC1_PSEUDO_MAC_PORT base address */
  #define ENETC1_PSEUDO_MAC_PORT_BASE_NS           (0x60B55000u)
  /** Peripheral ENETC1_PSEUDO_MAC_PORT base pointer */
  #define ENETC1_PSEUDO_MAC_PORT                   ((NETC_PSEUDO_LINK_Type *)ENETC1_PSEUDO_MAC_PORT_BASE)
  /** Peripheral ENETC1_PSEUDO_MAC_PORT base pointer */
  #define ENETC1_PSEUDO_MAC_PORT_NS                ((NETC_PSEUDO_LINK_Type *)ENETC1_PSEUDO_MAC_PORT_BASE_NS)
  /** Peripheral SW0_PSEUDO_MAC_PORT4 base address */
  #define SW0_PSEUDO_MAC_PORT4_BASE                (0x70A15000u)
  /** Peripheral SW0_PSEUDO_MAC_PORT4 base address */
  #define SW0_PSEUDO_MAC_PORT4_BASE_NS             (0x60A15000u)
  /** Peripheral SW0_PSEUDO_MAC_PORT4 base pointer */
  #define SW0_PSEUDO_MAC_PORT4                     ((NETC_PSEUDO_LINK_Type *)SW0_PSEUDO_MAC_PORT4_BASE)
  /** Peripheral SW0_PSEUDO_MAC_PORT4 base pointer */
  #define SW0_PSEUDO_MAC_PORT4_NS                  ((NETC_PSEUDO_LINK_Type *)SW0_PSEUDO_MAC_PORT4_BASE_NS)
  /** Array initializer of NETC_PSEUDO_LINK peripheral base addresses */
  #define NETC_PSEUDO_LINK_BASE_ADDRS              { ENETC1_PSEUDO_MAC_PORT_BASE, SW0_PSEUDO_MAC_PORT4_BASE }
  /** Array initializer of NETC_PSEUDO_LINK peripheral base pointers */
  #define NETC_PSEUDO_LINK_BASE_PTRS               { ENETC1_PSEUDO_MAC_PORT, SW0_PSEUDO_MAC_PORT4 }
  /** Array initializer of NETC_PSEUDO_LINK peripheral base addresses */
  #define NETC_PSEUDO_LINK_BASE_ADDRS_NS           { ENETC1_PSEUDO_MAC_PORT_BASE_NS, SW0_PSEUDO_MAC_PORT4_BASE_NS }
  /** Array initializer of NETC_PSEUDO_LINK peripheral base pointers */
  #define NETC_PSEUDO_LINK_BASE_PTRS_NS            { ENETC1_PSEUDO_MAC_PORT_NS, SW0_PSEUDO_MAC_PORT4_NS }
#else
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
#endif

/* NETC_SW - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SW0_BASE base address */
  #define SW0_BASE_BASE                            (0x70A00000u)
  /** Peripheral SW0_BASE base address */
  #define SW0_BASE_BASE_NS                         (0x60A00000u)
  /** Peripheral SW0_BASE base pointer */
  #define SW0_BASE                                 ((NETC_SW_Type *)SW0_BASE_BASE)
  /** Peripheral SW0_BASE base pointer */
  #define SW0_BASE_NS                              ((NETC_SW_Type *)SW0_BASE_BASE_NS)
  /** Array initializer of NETC_SW peripheral base addresses */
  #define NETC_SW_BASE_ADDRS                       { SW0_BASE_BASE }
  /** Array initializer of NETC_SW peripheral base pointers */
  #define NETC_SW_BASE_PTRS                        { SW0_BASE }
  /** Array initializer of NETC_SW peripheral base addresses */
  #define NETC_SW_BASE_ADDRS_NS                    { SW0_BASE_BASE_NS }
  /** Array initializer of NETC_SW peripheral base pointers */
  #define NETC_SW_BASE_PTRS_NS                     { SW0_BASE_NS }
#else
  /** Peripheral SW0_BASE base address */
  #define SW0_BASE_BASE                            (0x60A00000u)
  /** Peripheral SW0_BASE base pointer */
  #define SW0_BASE                                 ((NETC_SW_Type *)SW0_BASE_BASE)
  /** Array initializer of NETC_SW peripheral base addresses */
  #define NETC_SW_BASE_ADDRS                       { SW0_BASE_BASE }
  /** Array initializer of NETC_SW peripheral base pointers */
  #define NETC_SW_BASE_PTRS                        { SW0_BASE }
#endif

/* NETC_SW_ENETC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENETC0_COMMON base address */
  #define ENETC0_COMMON_BASE                       (0x70B10000u)
  /** Peripheral ENETC0_COMMON base address */
  #define ENETC0_COMMON_BASE_NS                    (0x60B10000u)
  /** Peripheral ENETC0_COMMON base pointer */
  #define ENETC0_COMMON                            ((NETC_SW_ENETC_Type *)ENETC0_COMMON_BASE)
  /** Peripheral ENETC0_COMMON base pointer */
  #define ENETC0_COMMON_NS                         ((NETC_SW_ENETC_Type *)ENETC0_COMMON_BASE_NS)
  /** Peripheral ENETC1_COMMON base address */
  #define ENETC1_COMMON_BASE                       (0x70B50000u)
  /** Peripheral ENETC1_COMMON base address */
  #define ENETC1_COMMON_BASE_NS                    (0x60B50000u)
  /** Peripheral ENETC1_COMMON base pointer */
  #define ENETC1_COMMON                            ((NETC_SW_ENETC_Type *)ENETC1_COMMON_BASE)
  /** Peripheral ENETC1_COMMON base pointer */
  #define ENETC1_COMMON_NS                         ((NETC_SW_ENETC_Type *)ENETC1_COMMON_BASE_NS)
  /** Peripheral SW0_COMMON base address */
  #define SW0_COMMON_BASE                          (0x70A00000u)
  /** Peripheral SW0_COMMON base address */
  #define SW0_COMMON_BASE_NS                       (0x60A00000u)
  /** Peripheral SW0_COMMON base pointer */
  #define SW0_COMMON                               ((NETC_SW_ENETC_Type *)SW0_COMMON_BASE)
  /** Peripheral SW0_COMMON base pointer */
  #define SW0_COMMON_NS                            ((NETC_SW_ENETC_Type *)SW0_COMMON_BASE_NS)
  /** Array initializer of NETC_SW_ENETC peripheral base addresses */
  #define NETC_SW_ENETC_BASE_ADDRS                 { ENETC0_COMMON_BASE, ENETC1_COMMON_BASE, SW0_COMMON_BASE }
  /** Array initializer of NETC_SW_ENETC peripheral base pointers */
  #define NETC_SW_ENETC_BASE_PTRS                  { ENETC0_COMMON, ENETC1_COMMON, SW0_COMMON }
  /** Array initializer of NETC_SW_ENETC peripheral base addresses */
  #define NETC_SW_ENETC_BASE_ADDRS_NS              { ENETC0_COMMON_BASE_NS, ENETC1_COMMON_BASE_NS, SW0_COMMON_BASE_NS }
  /** Array initializer of NETC_SW_ENETC peripheral base pointers */
  #define NETC_SW_ENETC_BASE_PTRS_NS               { ENETC0_COMMON_NS, ENETC1_COMMON_NS, SW0_COMMON_NS }
#else
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
#endif

/* OCOTP_FSB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OCOTP_FSB base address */
  #define OCOTP_FSB_BASE                           (0x57518000u)
  /** Peripheral OCOTP_FSB base address */
  #define OCOTP_FSB_BASE_NS                        (0x47518000u)
  /** Peripheral OCOTP_FSB base pointer */
  #define OCOTP_FSB                                ((OCOTP_FSB_Type *)OCOTP_FSB_BASE)
  /** Peripheral OCOTP_FSB base pointer */
  #define OCOTP_FSB_NS                             ((OCOTP_FSB_Type *)OCOTP_FSB_BASE_NS)
  /** Array initializer of OCOTP_FSB peripheral base addresses */
  #define OCOTP_FSB_BASE_ADDRS                     { OCOTP_FSB_BASE }
  /** Array initializer of OCOTP_FSB peripheral base pointers */
  #define OCOTP_FSB_BASE_PTRS                      { OCOTP_FSB }
  /** Array initializer of OCOTP_FSB peripheral base addresses */
  #define OCOTP_FSB_BASE_ADDRS_NS                  { OCOTP_FSB_BASE_NS }
  /** Array initializer of OCOTP_FSB peripheral base pointers */
  #define OCOTP_FSB_BASE_PTRS_NS                   { OCOTP_FSB_NS }
#else
  /** Peripheral OCOTP_FSB base address */
  #define OCOTP_FSB_BASE                           (0x47518000u)
  /** Peripheral OCOTP_FSB base pointer */
  #define OCOTP_FSB                                ((OCOTP_FSB_Type *)OCOTP_FSB_BASE)
  /** Array initializer of OCOTP_FSB peripheral base addresses */
  #define OCOTP_FSB_BASE_ADDRS                     { OCOTP_FSB_BASE }
  /** Array initializer of OCOTP_FSB peripheral base pointers */
  #define OCOTP_FSB_BASE_PTRS                      { OCOTP_FSB }
#endif

/* OSC_RC_400M - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OSC_RC_400M base address */
  #define OSC_RC_400M_BASE                         (0x54484380u)
  /** Peripheral OSC_RC_400M base address */
  #define OSC_RC_400M_BASE_NS                      (0x44484380u)
  /** Peripheral OSC_RC_400M base pointer */
  #define OSC_RC_400M                              ((OSC_RC_400M_Type *)OSC_RC_400M_BASE)
  /** Peripheral OSC_RC_400M base pointer */
  #define OSC_RC_400M_NS                           ((OSC_RC_400M_Type *)OSC_RC_400M_BASE_NS)
  /** Array initializer of OSC_RC_400M peripheral base addresses */
  #define OSC_RC_400M_BASE_ADDRS                   { OSC_RC_400M_BASE }
  /** Array initializer of OSC_RC_400M peripheral base pointers */
  #define OSC_RC_400M_BASE_PTRS                    { OSC_RC_400M }
  /** Array initializer of OSC_RC_400M peripheral base addresses */
  #define OSC_RC_400M_BASE_ADDRS_NS                { OSC_RC_400M_BASE_NS }
  /** Array initializer of OSC_RC_400M peripheral base pointers */
  #define OSC_RC_400M_BASE_PTRS_NS                 { OSC_RC_400M_NS }
#else
  /** Peripheral OSC_RC_400M base address */
  #define OSC_RC_400M_BASE                         (0x44484380u)
  /** Peripheral OSC_RC_400M base pointer */
  #define OSC_RC_400M                              ((OSC_RC_400M_Type *)OSC_RC_400M_BASE)
  /** Array initializer of OSC_RC_400M peripheral base addresses */
  #define OSC_RC_400M_BASE_ADDRS                   { OSC_RC_400M_BASE }
  /** Array initializer of OSC_RC_400M peripheral base pointers */
  #define OSC_RC_400M_BASE_PTRS                    { OSC_RC_400M }
#endif

/* OTFAD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OTFAD1 base address */
  #define OTFAD1_BASE                              (0x525E0000u)
  /** Peripheral OTFAD1 base address */
  #define OTFAD1_BASE_NS                           (0x425E0000u)
  /** Peripheral OTFAD1 base pointer */
  #define OTFAD1                                   ((OTFAD_Type *)OTFAD1_BASE)
  /** Peripheral OTFAD1 base pointer */
  #define OTFAD1_NS                                ((OTFAD_Type *)OTFAD1_BASE_NS)
  /** Peripheral OTFAD2 base address */
  #define OTFAD2_BASE                              (0x545E0000u)
  /** Peripheral OTFAD2 base address */
  #define OTFAD2_BASE_NS                           (0x445E0000u)
  /** Peripheral OTFAD2 base pointer */
  #define OTFAD2                                   ((OTFAD_Type *)OTFAD2_BASE)
  /** Peripheral OTFAD2 base pointer */
  #define OTFAD2_NS                                ((OTFAD_Type *)OTFAD2_BASE_NS)
  /** Array initializer of OTFAD peripheral base addresses */
  #define OTFAD_BASE_ADDRS                         { 0u, OTFAD1_BASE, OTFAD2_BASE }
  /** Array initializer of OTFAD peripheral base pointers */
  #define OTFAD_BASE_PTRS                          { (OTFAD_Type *)0u, OTFAD1, OTFAD2 }
  /** Array initializer of OTFAD peripheral base addresses */
  #define OTFAD_BASE_ADDRS_NS                      { 0u, OTFAD1_BASE_NS, OTFAD2_BASE_NS }
  /** Array initializer of OTFAD peripheral base pointers */
  #define OTFAD_BASE_PTRS_NS                       { (OTFAD_Type *)0u, OTFAD1_NS, OTFAD2_NS }
#else
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
#endif

/* PDM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PDM base address */
  #define PDM_BASE                                 (0x52BE0000u)
  /** Peripheral PDM base address */
  #define PDM_BASE_NS                              (0x42BE0000u)
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
  #define PDM_BASE                                 (0x42BE0000u)
  /** Peripheral PDM base pointer */
  #define PDM                                      ((PDM_Type *)PDM_BASE)
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS                           { PDM_BASE }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS                            { PDM }
#endif
/** Interrupt vectors for the PDM peripheral type */
#define PDM_HWVAD_Event_IRQS                     { PDM_HWVAD_EVENT_IRQn }
#define PDM_HWVAD_Error_IRQS                     { PDM_HWVAD_ERROR_IRQn }
#define PDM_Event_IRQS                           { PDM_EVENT_IRQn }
#define PDM_Error_IRQS                           { PDM_ERROR_IRQn }

/* PHY_LDO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PHY_LDO base address */
  #define PHY_LDO_BASE                             (0x54484680u)
  /** Peripheral PHY_LDO base address */
  #define PHY_LDO_BASE_NS                          (0x44484680u)
  /** Peripheral PHY_LDO base pointer */
  #define PHY_LDO                                  ((PHY_LDO_Type *)PHY_LDO_BASE)
  /** Peripheral PHY_LDO base pointer */
  #define PHY_LDO_NS                               ((PHY_LDO_Type *)PHY_LDO_BASE_NS)
  /** Array initializer of PHY_LDO peripheral base addresses */
  #define PHY_LDO_BASE_ADDRS                       { PHY_LDO_BASE }
  /** Array initializer of PHY_LDO peripheral base pointers */
  #define PHY_LDO_BASE_PTRS                        { PHY_LDO }
  /** Array initializer of PHY_LDO peripheral base addresses */
  #define PHY_LDO_BASE_ADDRS_NS                    { PHY_LDO_BASE_NS }
  /** Array initializer of PHY_LDO peripheral base pointers */
  #define PHY_LDO_BASE_PTRS_NS                     { PHY_LDO_NS }
#else
  /** Peripheral PHY_LDO base address */
  #define PHY_LDO_BASE                             (0x44484680u)
  /** Peripheral PHY_LDO base pointer */
  #define PHY_LDO                                  ((PHY_LDO_Type *)PHY_LDO_BASE)
  /** Array initializer of PHY_LDO peripheral base addresses */
  #define PHY_LDO_BASE_ADDRS                       { PHY_LDO_BASE }
  /** Array initializer of PHY_LDO peripheral base pointers */
  #define PHY_LDO_BASE_PTRS                        { PHY_LDO }
#endif

/* PLL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO_PLL base address */
  #define AUDIO_PLL_BASE                           (0x54484280u)
  /** Peripheral AUDIO_PLL base address */
  #define AUDIO_PLL_BASE_NS                        (0x44484280u)
  /** Peripheral AUDIO_PLL base pointer */
  #define AUDIO_PLL                                ((PLL_Type *)AUDIO_PLL_BASE)
  /** Peripheral AUDIO_PLL base pointer */
  #define AUDIO_PLL_NS                             ((PLL_Type *)AUDIO_PLL_BASE_NS)
  /** Peripheral ETHERNET_PLL base address */
  #define ETHERNET_PLL_BASE                        (0x54484180u)
  /** Peripheral ETHERNET_PLL base address */
  #define ETHERNET_PLL_BASE_NS                     (0x44484180u)
  /** Peripheral ETHERNET_PLL base pointer */
  #define ETHERNET_PLL                             ((PLL_Type *)ETHERNET_PLL_BASE)
  /** Peripheral ETHERNET_PLL base pointer */
  #define ETHERNET_PLL_NS                          ((PLL_Type *)ETHERNET_PLL_BASE_NS)
  /** Array initializer of PLL peripheral base addresses */
  #define PLL_BASE_ADDRS                           { AUDIO_PLL_BASE, ETHERNET_PLL_BASE }
  /** Array initializer of PLL peripheral base pointers */
  #define PLL_BASE_PTRS                            { AUDIO_PLL, ETHERNET_PLL }
  /** Array initializer of PLL peripheral base addresses */
  #define PLL_BASE_ADDRS_NS                        { AUDIO_PLL_BASE_NS, ETHERNET_PLL_BASE_NS }
  /** Array initializer of PLL peripheral base pointers */
  #define PLL_BASE_PTRS_NS                         { AUDIO_PLL_NS, ETHERNET_PLL_NS }
#else
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
#endif

/* PWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PWM1 base address */
  #define PWM1_BASE                                (0x52650000u)
  /** Peripheral PWM1 base address */
  #define PWM1_BASE_NS                             (0x42650000u)
  /** Peripheral PWM1 base pointer */
  #define PWM1                                     ((PWM_Type *)PWM1_BASE)
  /** Peripheral PWM1 base pointer */
  #define PWM1_NS                                  ((PWM_Type *)PWM1_BASE_NS)
  /** Peripheral PWM2 base address */
  #define PWM2_BASE                                (0x52660000u)
  /** Peripheral PWM2 base address */
  #define PWM2_BASE_NS                             (0x42660000u)
  /** Peripheral PWM2 base pointer */
  #define PWM2                                     ((PWM_Type *)PWM2_BASE)
  /** Peripheral PWM2 base pointer */
  #define PWM2_NS                                  ((PWM_Type *)PWM2_BASE_NS)
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS                           { 0u, PWM1_BASE, PWM2_BASE }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS                            { (PWM_Type *)0u, PWM1, PWM2 }
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS_NS                        { 0u, PWM1_BASE_NS, PWM2_BASE_NS }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS_NS                         { (PWM_Type *)0u, PWM1_NS, PWM2_NS }
#else
  /** Peripheral PWM1 base address */
  #define PWM1_BASE                                (0x42650000u)
  /** Peripheral PWM1 base pointer */
  #define PWM1                                     ((PWM_Type *)PWM1_BASE)
  /** Peripheral PWM2 base address */
  #define PWM2_BASE                                (0x42660000u)
  /** Peripheral PWM2 base pointer */
  #define PWM2                                     ((PWM_Type *)PWM2_BASE)
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS                           { 0u, PWM1_BASE, PWM2_BASE }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS                            { (PWM_Type *)0u, PWM1, PWM2 }
#endif
/** Interrupt vectors for the PWM peripheral type */
#define PWM_CMP_IRQS                             { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn }, { PWM2_0_IRQn, PWM2_1_IRQn, PWM2_2_IRQn, PWM2_3_IRQn } }
#define PWM_RELOAD_IRQS                          { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn }, { PWM2_0_IRQn, PWM2_1_IRQn, PWM2_2_IRQn, PWM2_3_IRQn } }
#define PWM_CAPTURE_IRQS                         { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { PWM1_0_IRQn, PWM1_1_IRQn, PWM1_2_IRQn, PWM1_3_IRQn }, { PWM2_0_IRQn, PWM2_1_IRQn, PWM2_2_IRQn, PWM2_3_IRQn } }
#define PWM_FAULT_IRQS                           { NotAvail_IRQn, PWM1_FAULT_IRQn, PWM2_FAULT_IRQn }
#define PWM_RELOAD_ERROR_IRQS                    { NotAvail_IRQn, PWM1_FAULT_IRQn, PWM2_FAULT_IRQn }

/* RGPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RGPIO1 base address */
  #define RGPIO1_BASE                              (0x57400000u)
  /** Peripheral RGPIO1 base address */
  #define RGPIO1_BASE_NS                           (0x47400000u)
  /** Peripheral RGPIO1 base pointer */
  #define RGPIO1                                   ((RGPIO_Type *)RGPIO1_BASE)
  /** Peripheral RGPIO1 base pointer */
  #define RGPIO1_NS                                ((RGPIO_Type *)RGPIO1_BASE_NS)
  /** Peripheral RGPIO2 base address */
  #define RGPIO2_BASE                              (0x53810000u)
  /** Peripheral RGPIO2 base address */
  #define RGPIO2_BASE_NS                           (0x43810000u)
  /** Peripheral RGPIO2 base pointer */
  #define RGPIO2                                   ((RGPIO_Type *)RGPIO2_BASE)
  /** Peripheral RGPIO2 base pointer */
  #define RGPIO2_NS                                ((RGPIO_Type *)RGPIO2_BASE_NS)
  /** Peripheral RGPIO3 base address */
  #define RGPIO3_BASE                              (0x53820000u)
  /** Peripheral RGPIO3 base address */
  #define RGPIO3_BASE_NS                           (0x43820000u)
  /** Peripheral RGPIO3 base pointer */
  #define RGPIO3                                   ((RGPIO_Type *)RGPIO3_BASE)
  /** Peripheral RGPIO3 base pointer */
  #define RGPIO3_NS                                ((RGPIO_Type *)RGPIO3_BASE_NS)
  /** Peripheral RGPIO4 base address */
  #define RGPIO4_BASE                              (0x53830000u)
  /** Peripheral RGPIO4 base address */
  #define RGPIO4_BASE_NS                           (0x43830000u)
  /** Peripheral RGPIO4 base pointer */
  #define RGPIO4                                   ((RGPIO_Type *)RGPIO4_BASE)
  /** Peripheral RGPIO4 base pointer */
  #define RGPIO4_NS                                ((RGPIO_Type *)RGPIO4_BASE_NS)
  /** Peripheral RGPIO5 base address */
  #define RGPIO5_BASE                              (0x53840000u)
  /** Peripheral RGPIO5 base address */
  #define RGPIO5_BASE_NS                           (0x43840000u)
  /** Peripheral RGPIO5 base pointer */
  #define RGPIO5                                   ((RGPIO_Type *)RGPIO5_BASE)
  /** Peripheral RGPIO5 base pointer */
  #define RGPIO5_NS                                ((RGPIO_Type *)RGPIO5_BASE_NS)
  /** Peripheral RGPIO6 base address */
  #define RGPIO6_BASE                              (0x53850000u)
  /** Peripheral RGPIO6 base address */
  #define RGPIO6_BASE_NS                           (0x43850000u)
  /** Peripheral RGPIO6 base pointer */
  #define RGPIO6                                   ((RGPIO_Type *)RGPIO6_BASE)
  /** Peripheral RGPIO6 base pointer */
  #define RGPIO6_NS                                ((RGPIO_Type *)RGPIO6_BASE_NS)
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS                         { 0u, RGPIO1_BASE, RGPIO2_BASE, RGPIO3_BASE, RGPIO4_BASE, RGPIO5_BASE, RGPIO6_BASE }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS                          { (RGPIO_Type *)0u, RGPIO1, RGPIO2, RGPIO3, RGPIO4, RGPIO5, RGPIO6 }
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS_NS                      { 0u, RGPIO1_BASE_NS, RGPIO2_BASE_NS, RGPIO3_BASE_NS, RGPIO4_BASE_NS, RGPIO5_BASE_NS, RGPIO6_BASE_NS }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS_NS                       { (RGPIO_Type *)0u, RGPIO1_NS, RGPIO2_NS, RGPIO3_NS, RGPIO4_NS, RGPIO5_NS, RGPIO6_NS }
#else
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
#endif
/** Interrupt vectors for the RGPIO peripheral type */
#define RGPIO_CH0_IRQS                           { NotAvail_IRQn, GPIO1_0_IRQn, GPIO2_0_IRQn, GPIO3_0_IRQn, GPIO4_IRQn, GPIO5_IRQn, GPIO6_IRQn }
#define RGPIO_CH1_IRQS                           { NotAvail_IRQn, GPIO1_1_IRQn, GPIO2_1_IRQn, GPIO3_1_IRQn, GPIO4_IRQn, GPIO5_IRQn, GPIO6_IRQn }

/* RTWDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral RTWDOG1 base address */
  #define RTWDOG1_BASE                             (0x542D0000u)
  /** Peripheral RTWDOG1 base address */
  #define RTWDOG1_BASE_NS                          (0x442D0000u)
  /** Peripheral RTWDOG1 base pointer */
  #define RTWDOG1                                  ((RTWDOG_Type *)RTWDOG1_BASE)
  /** Peripheral RTWDOG1 base pointer */
  #define RTWDOG1_NS                               ((RTWDOG_Type *)RTWDOG1_BASE_NS)
  /** Peripheral RTWDOG2 base address */
  #define RTWDOG2_BASE                             (0x542E0000u)
  /** Peripheral RTWDOG2 base address */
  #define RTWDOG2_BASE_NS                          (0x442E0000u)
  /** Peripheral RTWDOG2 base pointer */
  #define RTWDOG2                                  ((RTWDOG_Type *)RTWDOG2_BASE)
  /** Peripheral RTWDOG2 base pointer */
  #define RTWDOG2_NS                               ((RTWDOG_Type *)RTWDOG2_BASE_NS)
  /** Peripheral RTWDOG3 base address */
  #define RTWDOG3_BASE                             (0x52490000u)
  /** Peripheral RTWDOG3 base address */
  #define RTWDOG3_BASE_NS                          (0x42490000u)
  /** Peripheral RTWDOG3 base pointer */
  #define RTWDOG3                                  ((RTWDOG_Type *)RTWDOG3_BASE)
  /** Peripheral RTWDOG3 base pointer */
  #define RTWDOG3_NS                               ((RTWDOG_Type *)RTWDOG3_BASE_NS)
  /** Peripheral RTWDOG4 base address */
  #define RTWDOG4_BASE                             (0x524A0000u)
  /** Peripheral RTWDOG4 base address */
  #define RTWDOG4_BASE_NS                          (0x424A0000u)
  /** Peripheral RTWDOG4 base pointer */
  #define RTWDOG4                                  ((RTWDOG_Type *)RTWDOG4_BASE)
  /** Peripheral RTWDOG4 base pointer */
  #define RTWDOG4_NS                               ((RTWDOG_Type *)RTWDOG4_BASE_NS)
  /** Peripheral RTWDOG5 base address */
  #define RTWDOG5_BASE                             (0x524B0000u)
  /** Peripheral RTWDOG5 base address */
  #define RTWDOG5_BASE_NS                          (0x424B0000u)
  /** Peripheral RTWDOG5 base pointer */
  #define RTWDOG5                                  ((RTWDOG_Type *)RTWDOG5_BASE)
  /** Peripheral RTWDOG5 base pointer */
  #define RTWDOG5_NS                               ((RTWDOG_Type *)RTWDOG5_BASE_NS)
  /** Array initializer of RTWDOG peripheral base addresses */
  #define RTWDOG_BASE_ADDRS                        { 0u, RTWDOG1_BASE, RTWDOG2_BASE, RTWDOG3_BASE, RTWDOG4_BASE, RTWDOG5_BASE }
  /** Array initializer of RTWDOG peripheral base pointers */
  #define RTWDOG_BASE_PTRS                         { (RTWDOG_Type *)0u, RTWDOG1, RTWDOG2, RTWDOG3, RTWDOG4, RTWDOG5 }
  /** Array initializer of RTWDOG peripheral base addresses */
  #define RTWDOG_BASE_ADDRS_NS                     { 0u, RTWDOG1_BASE_NS, RTWDOG2_BASE_NS, RTWDOG3_BASE_NS, RTWDOG4_BASE_NS, RTWDOG5_BASE_NS }
  /** Array initializer of RTWDOG peripheral base pointers */
  #define RTWDOG_BASE_PTRS_NS                      { (RTWDOG_Type *)0u, RTWDOG1_NS, RTWDOG2_NS, RTWDOG3_NS, RTWDOG4_NS, RTWDOG5_NS }
#else
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
#endif
/** Interrupt vectors for the RTWDOG peripheral type */
#define RTWDOG_IRQS                              { NotAvail_IRQn, RTWDOG1_IRQn, RTWDOG2_IRQn, RTWDOG3_IRQn, RTWDOG4_IRQn, RTWDOG5_IRQn }
/* Extra definition */
#define RTWDOG_UPDATE_KEY                        (0xD928C520U)
#define RTWDOG_REFRESH_KEY                       (0xB480A602U)


/* S3MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MU_APPS_S3MUA base address */
  #define MU_APPS_S3MUA_BASE                       (0x57520000u)
  /** Peripheral MU_APPS_S3MUA base address */
  #define MU_APPS_S3MUA_BASE_NS                    (0x47520000u)
  /** Peripheral MU_APPS_S3MUA base pointer */
  #define MU_APPS_S3MUA                            ((S3MU_Type *)MU_APPS_S3MUA_BASE)
  /** Peripheral MU_APPS_S3MUA base pointer */
  #define MU_APPS_S3MUA_NS                         ((S3MU_Type *)MU_APPS_S3MUA_BASE_NS)
  /** Peripheral MU_RT_S3MUA base address */
  #define MU_RT_S3MUA_BASE                         (0x57540000u)
  /** Peripheral MU_RT_S3MUA base address */
  #define MU_RT_S3MUA_BASE_NS                      (0x47540000u)
  /** Peripheral MU_RT_S3MUA base pointer */
  #define MU_RT_S3MUA                              ((S3MU_Type *)MU_RT_S3MUA_BASE)
  /** Peripheral MU_RT_S3MUA base pointer */
  #define MU_RT_S3MUA_NS                           ((S3MU_Type *)MU_RT_S3MUA_BASE_NS)
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS                          { MU_APPS_S3MUA_BASE, MU_RT_S3MUA_BASE }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS                           { MU_APPS_S3MUA, MU_RT_S3MUA }
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS_NS                       { MU_APPS_S3MUA_BASE_NS, MU_RT_S3MUA_BASE_NS }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS_NS                        { MU_APPS_S3MUA_NS, MU_RT_S3MUA_NS }
#else
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
#endif

/* SEMA42 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SEMA1 base address */
  #define SEMA1_BASE                               (0x54260000u)
  /** Peripheral SEMA1 base address */
  #define SEMA1_BASE_NS                            (0x44260000u)
  /** Peripheral SEMA1 base pointer */
  #define SEMA1                                    ((SEMA42_Type *)SEMA1_BASE)
  /** Peripheral SEMA1 base pointer */
  #define SEMA1_NS                                 ((SEMA42_Type *)SEMA1_BASE_NS)
  /** Peripheral SEMA2 base address */
  #define SEMA2_BASE                               (0x52450000u)
  /** Peripheral SEMA2 base address */
  #define SEMA2_BASE_NS                            (0x42450000u)
  /** Peripheral SEMA2 base pointer */
  #define SEMA2                                    ((SEMA42_Type *)SEMA2_BASE)
  /** Peripheral SEMA2 base pointer */
  #define SEMA2_NS                                 ((SEMA42_Type *)SEMA2_BASE_NS)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { SEMA1_BASE, SEMA2_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { SEMA1, SEMA2 }
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS_NS                     { SEMA1_BASE_NS, SEMA2_BASE_NS }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS_NS                      { SEMA1_NS, SEMA2_NS }
#else
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
#endif

/* SPDIF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SPDIF base address */
  #define SPDIF_BASE                               (0x52BA0000u)
  /** Peripheral SPDIF base address */
  #define SPDIF_BASE_NS                            (0x42BA0000u)
  /** Peripheral SPDIF base pointer */
  #define SPDIF                                    ((SPDIF_Type *)SPDIF_BASE)
  /** Peripheral SPDIF base pointer */
  #define SPDIF_NS                                 ((SPDIF_Type *)SPDIF_BASE_NS)
  /** Array initializer of SPDIF peripheral base addresses */
  #define SPDIF_BASE_ADDRS                         { SPDIF_BASE }
  /** Array initializer of SPDIF peripheral base pointers */
  #define SPDIF_BASE_PTRS                          { SPDIF }
  /** Array initializer of SPDIF peripheral base addresses */
  #define SPDIF_BASE_ADDRS_NS                      { SPDIF_BASE_NS }
  /** Array initializer of SPDIF peripheral base pointers */
  #define SPDIF_BASE_PTRS_NS                       { SPDIF_NS }
#else
  /** Peripheral SPDIF base address */
  #define SPDIF_BASE                               (0x42BA0000u)
  /** Peripheral SPDIF base pointer */
  #define SPDIF                                    ((SPDIF_Type *)SPDIF_BASE)
  /** Array initializer of SPDIF peripheral base addresses */
  #define SPDIF_BASE_ADDRS                         { SPDIF_BASE }
  /** Array initializer of SPDIF peripheral base pointers */
  #define SPDIF_BASE_PTRS                          { SPDIF }
#endif
/** Interrupt vectors for the SPDIF peripheral type */
#define SPDIF_IRQS                               { SPDIF_IRQn }

/* SRC_GENERAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SRC_GENERAL_REG base address */
  #define SRC_GENERAL_REG_BASE                     (0x54460000u)
  /** Peripheral SRC_GENERAL_REG base address */
  #define SRC_GENERAL_REG_BASE_NS                  (0x44460000u)
  /** Peripheral SRC_GENERAL_REG base pointer */
  #define SRC_GENERAL_REG                          ((SRC_GENERAL_Type *)SRC_GENERAL_REG_BASE)
  /** Peripheral SRC_GENERAL_REG base pointer */
  #define SRC_GENERAL_REG_NS                       ((SRC_GENERAL_Type *)SRC_GENERAL_REG_BASE_NS)
  /** Array initializer of SRC_GENERAL peripheral base addresses */
  #define SRC_GENERAL_BASE_ADDRS                   { SRC_GENERAL_REG_BASE }
  /** Array initializer of SRC_GENERAL peripheral base pointers */
  #define SRC_GENERAL_BASE_PTRS                    { SRC_GENERAL_REG }
  /** Array initializer of SRC_GENERAL peripheral base addresses */
  #define SRC_GENERAL_BASE_ADDRS_NS                { SRC_GENERAL_REG_BASE_NS }
  /** Array initializer of SRC_GENERAL peripheral base pointers */
  #define SRC_GENERAL_BASE_PTRS_NS                 { SRC_GENERAL_REG_NS }
#else
  /** Peripheral SRC_GENERAL_REG base address */
  #define SRC_GENERAL_REG_BASE                     (0x44460000u)
  /** Peripheral SRC_GENERAL_REG base pointer */
  #define SRC_GENERAL_REG                          ((SRC_GENERAL_Type *)SRC_GENERAL_REG_BASE)
  /** Array initializer of SRC_GENERAL peripheral base addresses */
  #define SRC_GENERAL_BASE_ADDRS                   { SRC_GENERAL_REG_BASE }
  /** Array initializer of SRC_GENERAL peripheral base pointers */
  #define SRC_GENERAL_BASE_PTRS                    { SRC_GENERAL_REG }
#endif

/* SRC_MIF_LN28FDSOI_SPLLRAM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON_MIF_LN28FDSOI_SPLLRAM base address */
  #define AON_MIF_LN28FDSOI_SPLLRAM_BASE           (0x54462400u)
  /** Peripheral AON_MIF_LN28FDSOI_SPLLRAM base address */
  #define AON_MIF_LN28FDSOI_SPLLRAM_BASE_NS        (0x44462400u)
  /** Peripheral AON_MIF_LN28FDSOI_SPLLRAM base pointer */
  #define AON_MIF_LN28FDSOI_SPLLRAM                ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)AON_MIF_LN28FDSOI_SPLLRAM_BASE)
  /** Peripheral AON_MIF_LN28FDSOI_SPLLRAM base pointer */
  #define AON_MIF_LN28FDSOI_SPLLRAM_NS             ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)AON_MIF_LN28FDSOI_SPLLRAM_BASE_NS)
  /** Peripheral WAKEUP_MIF_LN28FDSOI_SPLLRAM base address */
  #define WAKEUP_MIF_LN28FDSOI_SPLLRAM_BASE        (0x54462C00u)
  /** Peripheral WAKEUP_MIF_LN28FDSOI_SPLLRAM base address */
  #define WAKEUP_MIF_LN28FDSOI_SPLLRAM_BASE_NS     (0x44462C00u)
  /** Peripheral WAKEUP_MIF_LN28FDSOI_SPLLRAM base pointer */
  #define WAKEUP_MIF_LN28FDSOI_SPLLRAM             ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)WAKEUP_MIF_LN28FDSOI_SPLLRAM_BASE)
  /** Peripheral WAKEUP_MIF_LN28FDSOI_SPLLRAM base pointer */
  #define WAKEUP_MIF_LN28FDSOI_SPLLRAM_NS          ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)WAKEUP_MIF_LN28FDSOI_SPLLRAM_BASE_NS)
  /** Peripheral MEGA_MIF_LN28FDSOI_SPLLRAM base address */
  #define MEGA_MIF_LN28FDSOI_SPLLRAM_BASE          (0x54463400u)
  /** Peripheral MEGA_MIF_LN28FDSOI_SPLLRAM base address */
  #define MEGA_MIF_LN28FDSOI_SPLLRAM_BASE_NS       (0x44463400u)
  /** Peripheral MEGA_MIF_LN28FDSOI_SPLLRAM base pointer */
  #define MEGA_MIF_LN28FDSOI_SPLLRAM               ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)MEGA_MIF_LN28FDSOI_SPLLRAM_BASE)
  /** Peripheral MEGA_MIF_LN28FDSOI_SPLLRAM base pointer */
  #define MEGA_MIF_LN28FDSOI_SPLLRAM_NS            ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)MEGA_MIF_LN28FDSOI_SPLLRAM_BASE_NS)
  /** Peripheral NETC_MIF_LN28FDSOI_SPLLRAM base address */
  #define NETC_MIF_LN28FDSOI_SPLLRAM_BASE          (0x54463C00u)
  /** Peripheral NETC_MIF_LN28FDSOI_SPLLRAM base address */
  #define NETC_MIF_LN28FDSOI_SPLLRAM_BASE_NS       (0x44463C00u)
  /** Peripheral NETC_MIF_LN28FDSOI_SPLLRAM base pointer */
  #define NETC_MIF_LN28FDSOI_SPLLRAM               ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)NETC_MIF_LN28FDSOI_SPLLRAM_BASE)
  /** Peripheral NETC_MIF_LN28FDSOI_SPLLRAM base pointer */
  #define NETC_MIF_LN28FDSOI_SPLLRAM_NS            ((SRC_MIF_LN28FDSOI_SPLLRAM_Type *)NETC_MIF_LN28FDSOI_SPLLRAM_BASE_NS)
  /** Array initializer of SRC_MIF_LN28FDSOI_SPLLRAM peripheral base addresses */
  #define SRC_MIF_LN28FDSOI_SPLLRAM_BASE_ADDRS     { AON_MIF_LN28FDSOI_SPLLRAM_BASE, WAKEUP_MIF_LN28FDSOI_SPLLRAM_BASE, MEGA_MIF_LN28FDSOI_SPLLRAM_BASE, NETC_MIF_LN28FDSOI_SPLLRAM_BASE }
  /** Array initializer of SRC_MIF_LN28FDSOI_SPLLRAM peripheral base pointers */
  #define SRC_MIF_LN28FDSOI_SPLLRAM_BASE_PTRS      { AON_MIF_LN28FDSOI_SPLLRAM, WAKEUP_MIF_LN28FDSOI_SPLLRAM, MEGA_MIF_LN28FDSOI_SPLLRAM, NETC_MIF_LN28FDSOI_SPLLRAM }
  /** Array initializer of SRC_MIF_LN28FDSOI_SPLLRAM peripheral base addresses */
  #define SRC_MIF_LN28FDSOI_SPLLRAM_BASE_ADDRS_NS  { AON_MIF_LN28FDSOI_SPLLRAM_BASE_NS, WAKEUP_MIF_LN28FDSOI_SPLLRAM_BASE_NS, MEGA_MIF_LN28FDSOI_SPLLRAM_BASE_NS, NETC_MIF_LN28FDSOI_SPLLRAM_BASE_NS }
  /** Array initializer of SRC_MIF_LN28FDSOI_SPLLRAM peripheral base pointers */
  #define SRC_MIF_LN28FDSOI_SPLLRAM_BASE_PTRS_NS   { AON_MIF_LN28FDSOI_SPLLRAM_NS, WAKEUP_MIF_LN28FDSOI_SPLLRAM_NS, MEGA_MIF_LN28FDSOI_SPLLRAM_NS, NETC_MIF_LN28FDSOI_SPLLRAM_NS }
#else
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
#endif

/* SRC_MIF_S28SPREGH - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON_MIF_S28SPREGH base address */
  #define AON_MIF_S28SPREGH_BASE                   (0x54462000u)
  /** Peripheral AON_MIF_S28SPREGH base address */
  #define AON_MIF_S28SPREGH_BASE_NS                (0x44462000u)
  /** Peripheral AON_MIF_S28SPREGH base pointer */
  #define AON_MIF_S28SPREGH                        ((SRC_MIF_S28SPREGH_Type *)AON_MIF_S28SPREGH_BASE)
  /** Peripheral AON_MIF_S28SPREGH base pointer */
  #define AON_MIF_S28SPREGH_NS                     ((SRC_MIF_S28SPREGH_Type *)AON_MIF_S28SPREGH_BASE_NS)
  /** Peripheral WAKEUP_MIF_S28SPREGH base address */
  #define WAKEUP_MIF_S28SPREGH_BASE                (0x54462800u)
  /** Peripheral WAKEUP_MIF_S28SPREGH base address */
  #define WAKEUP_MIF_S28SPREGH_BASE_NS             (0x44462800u)
  /** Peripheral WAKEUP_MIF_S28SPREGH base pointer */
  #define WAKEUP_MIF_S28SPREGH                     ((SRC_MIF_S28SPREGH_Type *)WAKEUP_MIF_S28SPREGH_BASE)
  /** Peripheral WAKEUP_MIF_S28SPREGH base pointer */
  #define WAKEUP_MIF_S28SPREGH_NS                  ((SRC_MIF_S28SPREGH_Type *)WAKEUP_MIF_S28SPREGH_BASE_NS)
  /** Peripheral MEGA_MIF_S28SPREGH base address */
  #define MEGA_MIF_S28SPREGH_BASE                  (0x54463000u)
  /** Peripheral MEGA_MIF_S28SPREGH base address */
  #define MEGA_MIF_S28SPREGH_BASE_NS               (0x44463000u)
  /** Peripheral MEGA_MIF_S28SPREGH base pointer */
  #define MEGA_MIF_S28SPREGH                       ((SRC_MIF_S28SPREGH_Type *)MEGA_MIF_S28SPREGH_BASE)
  /** Peripheral MEGA_MIF_S28SPREGH base pointer */
  #define MEGA_MIF_S28SPREGH_NS                    ((SRC_MIF_S28SPREGH_Type *)MEGA_MIF_S28SPREGH_BASE_NS)
  /** Peripheral NETC_MIF_S28SPREGH base address */
  #define NETC_MIF_S28SPREGH_BASE                  (0x54463800u)
  /** Peripheral NETC_MIF_S28SPREGH base address */
  #define NETC_MIF_S28SPREGH_BASE_NS               (0x44463800u)
  /** Peripheral NETC_MIF_S28SPREGH base pointer */
  #define NETC_MIF_S28SPREGH                       ((SRC_MIF_S28SPREGH_Type *)NETC_MIF_S28SPREGH_BASE)
  /** Peripheral NETC_MIF_S28SPREGH base pointer */
  #define NETC_MIF_S28SPREGH_NS                    ((SRC_MIF_S28SPREGH_Type *)NETC_MIF_S28SPREGH_BASE_NS)
  /** Peripheral CM33PLATFORM_CACHE base address */
  #define CM33PLATFORM_CACHE_BASE                  (0x54464000u)
  /** Peripheral CM33PLATFORM_CACHE base address */
  #define CM33PLATFORM_CACHE_BASE_NS               (0x44464000u)
  /** Peripheral CM33PLATFORM_CACHE base pointer */
  #define CM33PLATFORM_CACHE                       ((SRC_MIF_S28SPREGH_Type *)CM33PLATFORM_CACHE_BASE)
  /** Peripheral CM33PLATFORM_CACHE base pointer */
  #define CM33PLATFORM_CACHE_NS                    ((SRC_MIF_S28SPREGH_Type *)CM33PLATFORM_CACHE_BASE_NS)
  /** Peripheral CM7PLATFORM_CACHE base address */
  #define CM7PLATFORM_CACHE_BASE                   (0x54464800u)
  /** Peripheral CM7PLATFORM_CACHE base address */
  #define CM7PLATFORM_CACHE_BASE_NS                (0x44464800u)
  /** Peripheral CM7PLATFORM_CACHE base pointer */
  #define CM7PLATFORM_CACHE                        ((SRC_MIF_S28SPREGH_Type *)CM7PLATFORM_CACHE_BASE)
  /** Peripheral CM7PLATFORM_CACHE base pointer */
  #define CM7PLATFORM_CACHE_NS                     ((SRC_MIF_S28SPREGH_Type *)CM7PLATFORM_CACHE_BASE_NS)
  /** Peripheral CM33PLATFORM_TCM base address */
  #define CM33PLATFORM_TCM_BASE                    (0x54464400u)
  /** Peripheral CM33PLATFORM_TCM base address */
  #define CM33PLATFORM_TCM_BASE_NS                 (0x44464400u)
  /** Peripheral CM33PLATFORM_TCM base pointer */
  #define CM33PLATFORM_TCM                         ((SRC_MIF_S28SPREGH_Type *)CM33PLATFORM_TCM_BASE)
  /** Peripheral CM33PLATFORM_TCM base pointer */
  #define CM33PLATFORM_TCM_NS                      ((SRC_MIF_S28SPREGH_Type *)CM33PLATFORM_TCM_BASE_NS)
  /** Array initializer of SRC_MIF_S28SPREGH peripheral base addresses */
  #define SRC_MIF_S28SPREGH_BASE_ADDRS             { AON_MIF_S28SPREGH_BASE, WAKEUP_MIF_S28SPREGH_BASE, MEGA_MIF_S28SPREGH_BASE, NETC_MIF_S28SPREGH_BASE, CM33PLATFORM_CACHE_BASE, CM7PLATFORM_CACHE_BASE, CM33PLATFORM_TCM_BASE }
  /** Array initializer of SRC_MIF_S28SPREGH peripheral base pointers */
  #define SRC_MIF_S28SPREGH_BASE_PTRS              { AON_MIF_S28SPREGH, WAKEUP_MIF_S28SPREGH, MEGA_MIF_S28SPREGH, NETC_MIF_S28SPREGH, CM33PLATFORM_CACHE, CM7PLATFORM_CACHE, CM33PLATFORM_TCM }
  /** Array initializer of SRC_MIF_S28SPREGH peripheral base addresses */
  #define SRC_MIF_S28SPREGH_BASE_ADDRS_NS          { AON_MIF_S28SPREGH_BASE_NS, WAKEUP_MIF_S28SPREGH_BASE_NS, MEGA_MIF_S28SPREGH_BASE_NS, NETC_MIF_S28SPREGH_BASE_NS, CM33PLATFORM_CACHE_BASE_NS, CM7PLATFORM_CACHE_BASE_NS, CM33PLATFORM_TCM_BASE_NS }
  /** Array initializer of SRC_MIF_S28SPREGH peripheral base pointers */
  #define SRC_MIF_S28SPREGH_BASE_PTRS_NS           { AON_MIF_S28SPREGH_NS, WAKEUP_MIF_S28SPREGH_NS, MEGA_MIF_S28SPREGH_NS, NETC_MIF_S28SPREGH_NS, CM33PLATFORM_CACHE_NS, CM7PLATFORM_CACHE_NS, CM33PLATFORM_TCM_NS }
#else
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
#endif

/* SRC_MIF_S28SPREGH_PSWA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CM7PLATFORM_TCM base address */
  #define CM7PLATFORM_TCM_BASE                     (0x54464C00u)
  /** Peripheral CM7PLATFORM_TCM base address */
  #define CM7PLATFORM_TCM_BASE_NS                  (0x44464C00u)
  /** Peripheral CM7PLATFORM_TCM base pointer */
  #define CM7PLATFORM_TCM                          ((SRC_MIF_S28SPREGH_PSWA_Type *)CM7PLATFORM_TCM_BASE)
  /** Peripheral CM7PLATFORM_TCM base pointer */
  #define CM7PLATFORM_TCM_NS                       ((SRC_MIF_S28SPREGH_PSWA_Type *)CM7PLATFORM_TCM_BASE_NS)
  /** Array initializer of SRC_MIF_S28SPREGH_PSWA peripheral base addresses */
  #define SRC_MIF_S28SPREGH_PSWA_BASE_ADDRS        { CM7PLATFORM_TCM_BASE }
  /** Array initializer of SRC_MIF_S28SPREGH_PSWA peripheral base pointers */
  #define SRC_MIF_S28SPREGH_PSWA_BASE_PTRS         { CM7PLATFORM_TCM }
  /** Array initializer of SRC_MIF_S28SPREGH_PSWA peripheral base addresses */
  #define SRC_MIF_S28SPREGH_PSWA_BASE_ADDRS_NS     { CM7PLATFORM_TCM_BASE_NS }
  /** Array initializer of SRC_MIF_S28SPREGH_PSWA peripheral base pointers */
  #define SRC_MIF_S28SPREGH_PSWA_BASE_PTRS_NS      { CM7PLATFORM_TCM_NS }
#else
  /** Peripheral CM7PLATFORM_TCM base address */
  #define CM7PLATFORM_TCM_BASE                     (0x44464C00u)
  /** Peripheral CM7PLATFORM_TCM base pointer */
  #define CM7PLATFORM_TCM                          ((SRC_MIF_S28SPREGH_PSWA_Type *)CM7PLATFORM_TCM_BASE)
  /** Array initializer of SRC_MIF_S28SPREGH_PSWA peripheral base addresses */
  #define SRC_MIF_S28SPREGH_PSWA_BASE_ADDRS        { CM7PLATFORM_TCM_BASE }
  /** Array initializer of SRC_MIF_S28SPREGH_PSWA peripheral base pointers */
  #define SRC_MIF_S28SPREGH_PSWA_BASE_PTRS         { CM7PLATFORM_TCM }
#endif

/* SRC_MIX_SLICE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON_MIX_SLICE base address */
  #define AON_MIX_SLICE_BASE                       (0x54460800u)
  /** Peripheral AON_MIX_SLICE base address */
  #define AON_MIX_SLICE_BASE_NS                    (0x44460800u)
  /** Peripheral AON_MIX_SLICE base pointer */
  #define AON_MIX_SLICE                            ((SRC_MIX_SLICE_Type *)AON_MIX_SLICE_BASE)
  /** Peripheral AON_MIX_SLICE base pointer */
  #define AON_MIX_SLICE_NS                         ((SRC_MIX_SLICE_Type *)AON_MIX_SLICE_BASE_NS)
  /** Peripheral WAKEUP_MIX_SLICE base address */
  #define WAKEUP_MIX_SLICE_BASE                    (0x54460C00u)
  /** Peripheral WAKEUP_MIX_SLICE base address */
  #define WAKEUP_MIX_SLICE_BASE_NS                 (0x44460C00u)
  /** Peripheral WAKEUP_MIX_SLICE base pointer */
  #define WAKEUP_MIX_SLICE                         ((SRC_MIX_SLICE_Type *)WAKEUP_MIX_SLICE_BASE)
  /** Peripheral WAKEUP_MIX_SLICE base pointer */
  #define WAKEUP_MIX_SLICE_NS                      ((SRC_MIX_SLICE_Type *)WAKEUP_MIX_SLICE_BASE_NS)
  /** Peripheral MEGA_MIX_SLICE base address */
  #define MEGA_MIX_SLICE_BASE                      (0x54461000u)
  /** Peripheral MEGA_MIX_SLICE base address */
  #define MEGA_MIX_SLICE_BASE_NS                   (0x44461000u)
  /** Peripheral MEGA_MIX_SLICE base pointer */
  #define MEGA_MIX_SLICE                           ((SRC_MIX_SLICE_Type *)MEGA_MIX_SLICE_BASE)
  /** Peripheral MEGA_MIX_SLICE base pointer */
  #define MEGA_MIX_SLICE_NS                        ((SRC_MIX_SLICE_Type *)MEGA_MIX_SLICE_BASE_NS)
  /** Peripheral NETC_MIX_SLICE base address */
  #define NETC_MIX_SLICE_BASE                      (0x54461400u)
  /** Peripheral NETC_MIX_SLICE base address */
  #define NETC_MIX_SLICE_BASE_NS                   (0x44461400u)
  /** Peripheral NETC_MIX_SLICE base pointer */
  #define NETC_MIX_SLICE                           ((SRC_MIX_SLICE_Type *)NETC_MIX_SLICE_BASE)
  /** Peripheral NETC_MIX_SLICE base pointer */
  #define NETC_MIX_SLICE_NS                        ((SRC_MIX_SLICE_Type *)NETC_MIX_SLICE_BASE_NS)
  /** Peripheral CM33PLATFORM_MIX_SLICE base address */
  #define CM33PLATFORM_MIX_SLICE_BASE              (0x54461800u)
  /** Peripheral CM33PLATFORM_MIX_SLICE base address */
  #define CM33PLATFORM_MIX_SLICE_BASE_NS           (0x44461800u)
  /** Peripheral CM33PLATFORM_MIX_SLICE base pointer */
  #define CM33PLATFORM_MIX_SLICE                   ((SRC_MIX_SLICE_Type *)CM33PLATFORM_MIX_SLICE_BASE)
  /** Peripheral CM33PLATFORM_MIX_SLICE base pointer */
  #define CM33PLATFORM_MIX_SLICE_NS                ((SRC_MIX_SLICE_Type *)CM33PLATFORM_MIX_SLICE_BASE_NS)
  /** Peripheral CM7PLATFORM_MIX_SLICE base address */
  #define CM7PLATFORM_MIX_SLICE_BASE               (0x54461C00u)
  /** Peripheral CM7PLATFORM_MIX_SLICE base address */
  #define CM7PLATFORM_MIX_SLICE_BASE_NS            (0x44461C00u)
  /** Peripheral CM7PLATFORM_MIX_SLICE base pointer */
  #define CM7PLATFORM_MIX_SLICE                    ((SRC_MIX_SLICE_Type *)CM7PLATFORM_MIX_SLICE_BASE)
  /** Peripheral CM7PLATFORM_MIX_SLICE base pointer */
  #define CM7PLATFORM_MIX_SLICE_NS                 ((SRC_MIX_SLICE_Type *)CM7PLATFORM_MIX_SLICE_BASE_NS)
  /** Array initializer of SRC_MIX_SLICE peripheral base addresses */
  #define SRC_MIX_SLICE_BASE_ADDRS                 { AON_MIX_SLICE_BASE, WAKEUP_MIX_SLICE_BASE, MEGA_MIX_SLICE_BASE, NETC_MIX_SLICE_BASE, CM33PLATFORM_MIX_SLICE_BASE, CM7PLATFORM_MIX_SLICE_BASE }
  /** Array initializer of SRC_MIX_SLICE peripheral base pointers */
  #define SRC_MIX_SLICE_BASE_PTRS                  { AON_MIX_SLICE, WAKEUP_MIX_SLICE, MEGA_MIX_SLICE, NETC_MIX_SLICE, CM33PLATFORM_MIX_SLICE, CM7PLATFORM_MIX_SLICE }
  /** Array initializer of SRC_MIX_SLICE peripheral base addresses */
  #define SRC_MIX_SLICE_BASE_ADDRS_NS              { AON_MIX_SLICE_BASE_NS, WAKEUP_MIX_SLICE_BASE_NS, MEGA_MIX_SLICE_BASE_NS, NETC_MIX_SLICE_BASE_NS, CM33PLATFORM_MIX_SLICE_BASE_NS, CM7PLATFORM_MIX_SLICE_BASE_NS }
  /** Array initializer of SRC_MIX_SLICE peripheral base pointers */
  #define SRC_MIX_SLICE_BASE_PTRS_NS               { AON_MIX_SLICE_NS, WAKEUP_MIX_SLICE_NS, MEGA_MIX_SLICE_NS, NETC_MIX_SLICE_NS, CM33PLATFORM_MIX_SLICE_NS, CM7PLATFORM_MIX_SLICE_NS }
#else
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
#endif

/* SYSPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral M33_PCF1 base address */
  #define M33_PCF1_BASE                            (0x543E0000u)
  /** Peripheral M33_PCF1 base address */
  #define M33_PCF1_BASE_NS                         (0x443E0000u)
  /** Peripheral M33_PCF1 base pointer */
  #define M33_PCF1                                 ((SYSPM_Type *)M33_PCF1_BASE)
  /** Peripheral M33_PCF1 base pointer */
  #define M33_PCF1_NS                              ((SYSPM_Type *)M33_PCF1_BASE_NS)
  /** Peripheral M33_PSF1 base address */
  #define M33_PSF1_BASE                            (0x543F0000u)
  /** Peripheral M33_PSF1 base address */
  #define M33_PSF1_BASE_NS                         (0x443F0000u)
  /** Peripheral M33_PSF1 base pointer */
  #define M33_PSF1                                 ((SYSPM_Type *)M33_PSF1_BASE)
  /** Peripheral M33_PSF1 base pointer */
  #define M33_PSF1_NS                              ((SYSPM_Type *)M33_PSF1_BASE_NS)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { M33_PCF1_BASE, M33_PSF1_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { M33_PCF1, M33_PSF1 }
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS_NS                      { M33_PCF1_BASE_NS, M33_PSF1_BASE_NS }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS_NS                       { M33_PCF1_NS, M33_PSF1_NS }
#else
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
#endif

/* SYS_CTR_COMPARE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYS_CTR_COMPARE base address */
  #define SYS_CTR_COMPARE_BASE                     (0x542A0000u)
  /** Peripheral SYS_CTR_COMPARE base address */
  #define SYS_CTR_COMPARE_BASE_NS                  (0x442A0000u)
  /** Peripheral SYS_CTR_COMPARE base pointer */
  #define SYS_CTR_COMPARE                          ((SYS_CTR_COMPARE_Type *)SYS_CTR_COMPARE_BASE)
  /** Peripheral SYS_CTR_COMPARE base pointer */
  #define SYS_CTR_COMPARE_NS                       ((SYS_CTR_COMPARE_Type *)SYS_CTR_COMPARE_BASE_NS)
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS               { SYS_CTR_COMPARE_BASE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS                { SYS_CTR_COMPARE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS_NS            { SYS_CTR_COMPARE_BASE_NS }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS_NS             { SYS_CTR_COMPARE_NS }
#else
  /** Peripheral SYS_CTR_COMPARE base address */
  #define SYS_CTR_COMPARE_BASE                     (0x442A0000u)
  /** Peripheral SYS_CTR_COMPARE base pointer */
  #define SYS_CTR_COMPARE                          ((SYS_CTR_COMPARE_Type *)SYS_CTR_COMPARE_BASE)
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS               { SYS_CTR_COMPARE_BASE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS                { SYS_CTR_COMPARE }
#endif

/* SYS_CTR_CONTROL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYS_CTR_CONTROL base address */
  #define SYS_CTR_CONTROL_BASE                     (0x54290000u)
  /** Peripheral SYS_CTR_CONTROL base address */
  #define SYS_CTR_CONTROL_BASE_NS                  (0x44290000u)
  /** Peripheral SYS_CTR_CONTROL base pointer */
  #define SYS_CTR_CONTROL                          ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE)
  /** Peripheral SYS_CTR_CONTROL base pointer */
  #define SYS_CTR_CONTROL_NS                       ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE_NS)
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS               { SYS_CTR_CONTROL_BASE }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS                { SYS_CTR_CONTROL }
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS_NS            { SYS_CTR_CONTROL_BASE_NS }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS_NS             { SYS_CTR_CONTROL_NS }
#else
  /** Peripheral SYS_CTR_CONTROL base address */
  #define SYS_CTR_CONTROL_BASE                     (0x44290000u)
  /** Peripheral SYS_CTR_CONTROL base pointer */
  #define SYS_CTR_CONTROL                          ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE)
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS               { SYS_CTR_CONTROL_BASE }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS                { SYS_CTR_CONTROL }
#endif

/* SYS_CTR_READ - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYS_CTR_READ base address */
  #define SYS_CTR_READ_BASE                        (0x542B0000u)
  /** Peripheral SYS_CTR_READ base address */
  #define SYS_CTR_READ_BASE_NS                     (0x442B0000u)
  /** Peripheral SYS_CTR_READ base pointer */
  #define SYS_CTR_READ                             ((SYS_CTR_READ_Type *)SYS_CTR_READ_BASE)
  /** Peripheral SYS_CTR_READ base pointer */
  #define SYS_CTR_READ_NS                          ((SYS_CTR_READ_Type *)SYS_CTR_READ_BASE_NS)
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS                  { SYS_CTR_READ_BASE }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS                   { SYS_CTR_READ }
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS_NS               { SYS_CTR_READ_BASE_NS }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS_NS                { SYS_CTR_READ_NS }
#else
  /** Peripheral SYS_CTR_READ base address */
  #define SYS_CTR_READ_BASE                        (0x442B0000u)
  /** Peripheral SYS_CTR_READ base pointer */
  #define SYS_CTR_READ                             ((SYS_CTR_READ_Type *)SYS_CTR_READ_BASE)
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS                  { SYS_CTR_READ_BASE }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS                   { SYS_CTR_READ }
#endif

/* TCM_ECC_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CP_CM33_IMX9RTC__CM33_TCM_MCM base address */
  #define CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE       (0x54420000u)
  /** Peripheral CP_CM33_IMX9RTC__CM33_TCM_MCM base address */
  #define CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE_NS    (0x44420000u)
  /** Peripheral CP_CM33_IMX9RTC__CM33_TCM_MCM base pointer */
  #define CP_CM33_IMX9RTC__CM33_TCM_MCM            ((TCM_ECC_MCM_Type *)CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE)
  /** Peripheral CP_CM33_IMX9RTC__CM33_TCM_MCM base pointer */
  #define CP_CM33_IMX9RTC__CM33_TCM_MCM_NS         ((TCM_ECC_MCM_Type *)CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE_NS)
  /** Array initializer of TCM_ECC_MCM peripheral base addresses */
  #define TCM_ECC_MCM_BASE_ADDRS                   { CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE }
  /** Array initializer of TCM_ECC_MCM peripheral base pointers */
  #define TCM_ECC_MCM_BASE_PTRS                    { CP_CM33_IMX9RTC__CM33_TCM_MCM }
  /** Array initializer of TCM_ECC_MCM peripheral base addresses */
  #define TCM_ECC_MCM_BASE_ADDRS_NS                { CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE_NS }
  /** Array initializer of TCM_ECC_MCM peripheral base pointers */
  #define TCM_ECC_MCM_BASE_PTRS_NS                 { CP_CM33_IMX9RTC__CM33_TCM_MCM_NS }
#else
  /** Peripheral CP_CM33_IMX9RTC__CM33_TCM_MCM base address */
  #define CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE       (0x44420000u)
  /** Peripheral CP_CM33_IMX9RTC__CM33_TCM_MCM base pointer */
  #define CP_CM33_IMX9RTC__CM33_TCM_MCM            ((TCM_ECC_MCM_Type *)CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE)
  /** Array initializer of TCM_ECC_MCM peripheral base addresses */
  #define TCM_ECC_MCM_BASE_ADDRS                   { CP_CM33_IMX9RTC__CM33_TCM_MCM_BASE }
  /** Array initializer of TCM_ECC_MCM peripheral base pointers */
  #define TCM_ECC_MCM_BASE_PTRS                    { CP_CM33_IMX9RTC__CM33_TCM_MCM }
#endif

/* TMPSNS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TMPSNS base address */
  #define TMPSNS_BASE                              (0x54484580u)
  /** Peripheral TMPSNS base address */
  #define TMPSNS_BASE_NS                           (0x44484580u)
  /** Peripheral TMPSNS base pointer */
  #define TMPSNS                                   ((TMPSNS_Type *)TMPSNS_BASE)
  /** Peripheral TMPSNS base pointer */
  #define TMPSNS_NS                                ((TMPSNS_Type *)TMPSNS_BASE_NS)
  /** Array initializer of TMPSNS peripheral base addresses */
  #define TMPSNS_BASE_ADDRS                        { TMPSNS_BASE }
  /** Array initializer of TMPSNS peripheral base pointers */
  #define TMPSNS_BASE_PTRS                         { TMPSNS }
  /** Array initializer of TMPSNS peripheral base addresses */
  #define TMPSNS_BASE_ADDRS_NS                     { TMPSNS_BASE_NS }
  /** Array initializer of TMPSNS peripheral base pointers */
  #define TMPSNS_BASE_PTRS_NS                      { TMPSNS_NS }
#else
  /** Peripheral TMPSNS base address */
  #define TMPSNS_BASE                              (0x44484580u)
  /** Peripheral TMPSNS base pointer */
  #define TMPSNS                                   ((TMPSNS_Type *)TMPSNS_BASE)
  /** Array initializer of TMPSNS peripheral base addresses */
  #define TMPSNS_BASE_ADDRS                        { TMPSNS_BASE }
  /** Array initializer of TMPSNS peripheral base pointers */
  #define TMPSNS_BASE_PTRS                         { TMPSNS }
#endif

/* TMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TMR1 base address */
  #define TMR1_BASE                                (0x52690000u)
  /** Peripheral TMR1 base address */
  #define TMR1_BASE_NS                             (0x42690000u)
  /** Peripheral TMR1 base pointer */
  #define TMR1                                     ((TMR_Type *)TMR1_BASE)
  /** Peripheral TMR1 base pointer */
  #define TMR1_NS                                  ((TMR_Type *)TMR1_BASE_NS)
  /** Peripheral TMR2 base address */
  #define TMR2_BASE                                (0x526A0000u)
  /** Peripheral TMR2 base address */
  #define TMR2_BASE_NS                             (0x426A0000u)
  /** Peripheral TMR2 base pointer */
  #define TMR2                                     ((TMR_Type *)TMR2_BASE)
  /** Peripheral TMR2 base pointer */
  #define TMR2_NS                                  ((TMR_Type *)TMR2_BASE_NS)
  /** Peripheral TMR3 base address */
  #define TMR3_BASE                                (0x526B0000u)
  /** Peripheral TMR3 base address */
  #define TMR3_BASE_NS                             (0x426B0000u)
  /** Peripheral TMR3 base pointer */
  #define TMR3                                     ((TMR_Type *)TMR3_BASE)
  /** Peripheral TMR3 base pointer */
  #define TMR3_NS                                  ((TMR_Type *)TMR3_BASE_NS)
  /** Peripheral TMR4 base address */
  #define TMR4_BASE                                (0x526C0000u)
  /** Peripheral TMR4 base address */
  #define TMR4_BASE_NS                             (0x426C0000u)
  /** Peripheral TMR4 base pointer */
  #define TMR4                                     ((TMR_Type *)TMR4_BASE)
  /** Peripheral TMR4 base pointer */
  #define TMR4_NS                                  ((TMR_Type *)TMR4_BASE_NS)
  /** Array initializer of TMR peripheral base addresses */
  #define TMR_BASE_ADDRS                           { 0u, TMR1_BASE, TMR2_BASE, TMR3_BASE, TMR4_BASE }
  /** Array initializer of TMR peripheral base pointers */
  #define TMR_BASE_PTRS                            { (TMR_Type *)0u, TMR1, TMR2, TMR3, TMR4 }
  /** Array initializer of TMR peripheral base addresses */
  #define TMR_BASE_ADDRS_NS                        { 0u, TMR1_BASE_NS, TMR2_BASE_NS, TMR3_BASE_NS, TMR4_BASE_NS }
  /** Array initializer of TMR peripheral base pointers */
  #define TMR_BASE_PTRS_NS                         { (TMR_Type *)0u, TMR1_NS, TMR2_NS, TMR3_NS, TMR4_NS }
#else
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
  /** Array initializer of TMR peripheral base addresses */
  #define TMR_BASE_ADDRS                           { 0u, TMR1_BASE, TMR2_BASE, TMR3_BASE, TMR4_BASE }
  /** Array initializer of TMR peripheral base pointers */
  #define TMR_BASE_PTRS                            { (TMR_Type *)0u, TMR1, TMR2, TMR3, TMR4 }
#endif
/** Interrupt vectors for the TMR peripheral type */
#define TMR_IRQS                                 { NotAvail_IRQn, TMR1_IRQn, TMR2_IRQn, TMR3_IRQn, TMR4_IRQn }

/* TPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TPM1 base address */
  #define TPM1_BASE                                (0x54310000u)
  /** Peripheral TPM1 base address */
  #define TPM1_BASE_NS                             (0x44310000u)
  /** Peripheral TPM1 base pointer */
  #define TPM1                                     ((TPM_Type *)TPM1_BASE)
  /** Peripheral TPM1 base pointer */
  #define TPM1_NS                                  ((TPM_Type *)TPM1_BASE_NS)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE                                (0x54320000u)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE_NS                             (0x44320000u)
  /** Peripheral TPM2 base pointer */
  #define TPM2                                     ((TPM_Type *)TPM2_BASE)
  /** Peripheral TPM2 base pointer */
  #define TPM2_NS                                  ((TPM_Type *)TPM2_BASE_NS)
  /** Peripheral TPM3 base address */
  #define TPM3_BASE                                (0x524E0000u)
  /** Peripheral TPM3 base address */
  #define TPM3_BASE_NS                             (0x424E0000u)
  /** Peripheral TPM3 base pointer */
  #define TPM3                                     ((TPM_Type *)TPM3_BASE)
  /** Peripheral TPM3 base pointer */
  #define TPM3_NS                                  ((TPM_Type *)TPM3_BASE_NS)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { 0u, TPM1_BASE, TPM2_BASE, TPM3_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { (TPM_Type *)0u, TPM1, TPM2, TPM3 }
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS_NS                        { 0u, TPM1_BASE_NS, TPM2_BASE_NS, TPM3_BASE_NS }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS_NS                         { (TPM_Type *)0u, TPM1_NS, TPM2_NS, TPM3_NS }
#else
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
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { 0u, TPM1_BASE, TPM2_BASE, TPM3_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { (TPM_Type *)0u, TPM1, TPM2, TPM3 }
#endif
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { NotAvail_IRQn, TPM1_IRQn, TPM2_IRQn, TPM3_IRQn }

/* TRDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TRDC1 base address */
  #define TRDC1_BASE                               (0x54270000u)
  /** Peripheral TRDC1 base address */
  #define TRDC1_BASE_NS                            (0x44270000u)
  /** Peripheral TRDC1 base pointer */
  #define TRDC1                                    ((TRDC_Type *)TRDC1_BASE)
  /** Peripheral TRDC1 base pointer */
  #define TRDC1_NS                                 ((TRDC_Type *)TRDC1_BASE_NS)
  /** Peripheral TRDC2 base address */
  #define TRDC2_BASE                               (0x52460000u)
  /** Peripheral TRDC2 base address */
  #define TRDC2_BASE_NS                            (0x42460000u)
  /** Peripheral TRDC2 base pointer */
  #define TRDC2                                    ((TRDC_Type *)TRDC2_BASE)
  /** Peripheral TRDC2 base pointer */
  #define TRDC2_NS                                 ((TRDC_Type *)TRDC2_BASE_NS)
  /** Peripheral TRDC3 base address */
  #define TRDC3_BASE                               (0x52810000u)
  /** Peripheral TRDC3 base address */
  #define TRDC3_BASE_NS                            (0x42810000u)
  /** Peripheral TRDC3 base pointer */
  #define TRDC3                                    ((TRDC_Type *)TRDC3_BASE)
  /** Peripheral TRDC3 base pointer */
  #define TRDC3_NS                                 ((TRDC_Type *)TRDC3_BASE_NS)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { 0u, TRDC1_BASE, TRDC2_BASE, TRDC3_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { (TRDC_Type *)0u, TRDC1, TRDC2, TRDC3 }
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS_NS                       { 0u, TRDC1_BASE_NS, TRDC2_BASE_NS, TRDC3_BASE_NS }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS_NS                        { (TRDC_Type *)0u, TRDC1_NS, TRDC2_NS, TRDC3_NS }
#else
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
#endif
/** Interrupt vectors for the TRDC peripheral type */
#define TRDC_IRQS                                { NotAvail_IRQn, TRDC_MGR_AON_IRQn, TRDC_MGR_WKUP_IRQn, TRDC_MGR_MEGA_IRQn }
#define MBC0_MEMORY_CFG_WORD_COUNT {1,2,4,1}
#define MBC1_MEMORY_CFG_WORD_COUNT {1,1,1,1}
#define MBC2_MEMORY_CFG_WORD_COUNT {9,6,1,1}
#define MBC3_MEMORY_CFG_WORD_COUNT {3,0,0,0}
#define MBC_MEMORY_CFG_WORD_COUNT {MBC0_MEMORY_CFG_WORD_COUNT , MBC1_MEMORY_CFG_WORD_COUNT, MBC2_MEMORY_CFG_WORD_COUNT, MBC3_MEMORY_CFG_WORD_COUNT}
#define MBC0_MEMORY_NSE_WORD_COUNT {1,1,1,1}
#define MBC1_MEMORY_NSE_WORD_COUNT {1,1,1,1}
#define MBC2_MEMORY_NSE_WORD_COUNT {3,2,1,1}
#define MBC3_MEMORY_NSE_WORD_COUNT {1,0,0,0}
#define MBC_MEMORY_NSE_WORD_COUNT {MBC0_MEMORY_NSE_WORD_COUNT , MBC1_MEMORY_NSE_WORD_COUNT, MBC2_MEMORY_NSE_WORD_COUNT, MBC3_MEMORY_NSE_WORD_COUNT}


/* TSTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TSTMR1_TSTMRA base address */
  #define TSTMR1_TSTMRA_BASE                       (0x542C0000u)
  /** Peripheral TSTMR1_TSTMRA base address */
  #define TSTMR1_TSTMRA_BASE_NS                    (0x442C0000u)
  /** Peripheral TSTMR1_TSTMRA base pointer */
  #define TSTMR1_TSTMRA                            ((TSTMR_Type *)TSTMR1_TSTMRA_BASE)
  /** Peripheral TSTMR1_TSTMRA base pointer */
  #define TSTMR1_TSTMRA_NS                         ((TSTMR_Type *)TSTMR1_TSTMRA_BASE_NS)
  /** Peripheral TSTMR2_TSTMRA base address */
  #define TSTMR2_TSTMRA_BASE                       (0x52480000u)
  /** Peripheral TSTMR2_TSTMRA base address */
  #define TSTMR2_TSTMRA_BASE_NS                    (0x42480000u)
  /** Peripheral TSTMR2_TSTMRA base pointer */
  #define TSTMR2_TSTMRA                            ((TSTMR_Type *)TSTMR2_TSTMRA_BASE)
  /** Peripheral TSTMR2_TSTMRA base pointer */
  #define TSTMR2_TSTMRA_NS                         ((TSTMR_Type *)TSTMR2_TSTMRA_BASE_NS)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { TSTMR1_TSTMRA_BASE, TSTMR2_TSTMRA_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { TSTMR1_TSTMRA, TSTMR2_TSTMRA }
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS_NS                      { TSTMR1_TSTMRA_BASE_NS, TSTMR2_TSTMRA_BASE_NS }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS_NS                       { TSTMR1_TSTMRA_NS, TSTMR2_TSTMRA_NS }
#else
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
#endif

/* USBHSDCD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBHSDCD1 base address */
  #define USBHSDCD1_BASE                           (0x52CA0800u)
  /** Peripheral USBHSDCD1 base address */
  #define USBHSDCD1_BASE_NS                        (0x42CA0800u)
  /** Peripheral USBHSDCD1 base pointer */
  #define USBHSDCD1                                ((USBHSDCD_Type *)USBHSDCD1_BASE)
  /** Peripheral USBHSDCD1 base pointer */
  #define USBHSDCD1_NS                             ((USBHSDCD_Type *)USBHSDCD1_BASE_NS)
  /** Peripheral USBHSDCD2 base address */
  #define USBHSDCD2_BASE                           (0x52CB0800u)
  /** Peripheral USBHSDCD2 base address */
  #define USBHSDCD2_BASE_NS                        (0x42CB0800u)
  /** Peripheral USBHSDCD2 base pointer */
  #define USBHSDCD2                                ((USBHSDCD_Type *)USBHSDCD2_BASE)
  /** Peripheral USBHSDCD2 base pointer */
  #define USBHSDCD2_NS                             ((USBHSDCD_Type *)USBHSDCD2_BASE_NS)
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS                      { 0u, USBHSDCD1_BASE, USBHSDCD2_BASE }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS                       { (USBHSDCD_Type *)0u, USBHSDCD1, USBHSDCD2 }
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS_NS                   { 0u, USBHSDCD1_BASE_NS, USBHSDCD2_BASE_NS }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS_NS                    { (USBHSDCD_Type *)0u, USBHSDCD1_NS, USBHSDCD2_NS }
#else
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
#endif
/* Backward compatibility */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
#define USBHSDCD_STACK_BASE_ADDRS               { USBHSDCD1_BASE, USBHSDCD2_BASE }
#define USBHSDCD_STACK_BASE_ADDRS_NS            { USBHSDCD1_BASE_NS, USBHSDCD2_BASE_NS }
#else
#define USBHSDCD_STACK_BASE_ADDRS                { USBHSDCD1_BASE, USBHSDCD2_BASE }
#endif


/* USDHC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE                              (0x52850000u)
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE_NS                           (0x42850000u)
  /** Peripheral USDHC1 base pointer */
  #define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
  /** Peripheral USDHC1 base pointer */
  #define USDHC1_NS                                ((USDHC_Type *)USDHC1_BASE_NS)
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS                         { 0u, USDHC1_BASE }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS                          { (USDHC_Type *)0u, USDHC1 }
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS_NS                      { 0u, USDHC1_BASE_NS }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS_NS                       { (USDHC_Type *)0u, USDHC1_NS }
#else
  /** Peripheral USDHC1 base address */
  #define USDHC1_BASE                              (0x42850000u)
  /** Peripheral USDHC1 base pointer */
  #define USDHC1                                   ((USDHC_Type *)USDHC1_BASE)
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS                         { 0u, USDHC1_BASE }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS                          { (USDHC_Type *)0u, USDHC1 }
#endif
/** Interrupt vectors for the USDHC peripheral type */
#define USDHC_IRQS                               { NotAvail_IRQn, USDHC1_IRQn }

/* VMBANDGAP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VMBANDGAP base address */
  #define VMBANDGAP_BASE                           (0x54484780u)
  /** Peripheral VMBANDGAP base address */
  #define VMBANDGAP_BASE_NS                        (0x44484780u)
  /** Peripheral VMBANDGAP base pointer */
  #define VMBANDGAP                                ((VMBANDGAP_Type *)VMBANDGAP_BASE)
  /** Peripheral VMBANDGAP base pointer */
  #define VMBANDGAP_NS                             ((VMBANDGAP_Type *)VMBANDGAP_BASE_NS)
  /** Array initializer of VMBANDGAP peripheral base addresses */
  #define VMBANDGAP_BASE_ADDRS                     { VMBANDGAP_BASE }
  /** Array initializer of VMBANDGAP peripheral base pointers */
  #define VMBANDGAP_BASE_PTRS                      { VMBANDGAP }
  /** Array initializer of VMBANDGAP peripheral base addresses */
  #define VMBANDGAP_BASE_ADDRS_NS                  { VMBANDGAP_BASE_NS }
  /** Array initializer of VMBANDGAP peripheral base pointers */
  #define VMBANDGAP_BASE_PTRS_NS                   { VMBANDGAP_NS }
#else
  /** Peripheral VMBANDGAP base address */
  #define VMBANDGAP_BASE                           (0x44484780u)
  /** Peripheral VMBANDGAP base pointer */
  #define VMBANDGAP                                ((VMBANDGAP_Type *)VMBANDGAP_BASE)
  /** Array initializer of VMBANDGAP peripheral base addresses */
  #define VMBANDGAP_BASE_ADDRS                     { VMBANDGAP_BASE }
  /** Array initializer of VMBANDGAP peripheral base pointers */
  #define VMBANDGAP_BASE_PTRS                      { VMBANDGAP }
#endif

/* VREF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VREF base address */
  #define VREF_BASE                                (0x52E30000u)
  /** Peripheral VREF base address */
  #define VREF_BASE_NS                             (0x42E30000u)
  /** Peripheral VREF base pointer */
  #define VREF                                     ((VREF_Type *)VREF_BASE)
  /** Peripheral VREF base pointer */
  #define VREF_NS                                  ((VREF_Type *)VREF_BASE_NS)
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS                          { VREF_BASE }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS                           { VREF }
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS_NS                       { VREF_BASE_NS }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS_NS                        { VREF_NS }
#else
  /** Peripheral VREF base address */
  #define VREF_BASE                                (0x42E30000u)
  /** Peripheral VREF base pointer */
  #define VREF                                     ((VREF_Type *)VREF_BASE)
  /** Array initializer of VREF peripheral base addresses */
  #define VREF_BASE_ADDRS                          { VREF_BASE }
  /** Array initializer of VREF peripheral base pointers */
  #define VREF_BASE_PTRS                           { VREF }
#endif

/* XBAR_NUM_OUT221 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XBAR1 base address */
  #define XBAR1_BASE                               (0x52750000u)
  /** Peripheral XBAR1 base address */
  #define XBAR1_BASE_NS                            (0x42750000u)
  /** Peripheral XBAR1 base pointer */
  #define XBAR1                                    ((XBAR_NUM_OUT221_Type *)XBAR1_BASE)
  /** Peripheral XBAR1 base pointer */
  #define XBAR1_NS                                 ((XBAR_NUM_OUT221_Type *)XBAR1_BASE_NS)
  /** Array initializer of XBAR_NUM_OUT221 peripheral base addresses */
  #define XBAR_NUM_OUT221_BASE_ADDRS               { XBAR1_BASE }
  /** Array initializer of XBAR_NUM_OUT221 peripheral base pointers */
  #define XBAR_NUM_OUT221_BASE_PTRS                { XBAR1 }
  /** Array initializer of XBAR_NUM_OUT221 peripheral base addresses */
  #define XBAR_NUM_OUT221_BASE_ADDRS_NS            { XBAR1_BASE_NS }
  /** Array initializer of XBAR_NUM_OUT221 peripheral base pointers */
  #define XBAR_NUM_OUT221_BASE_PTRS_NS             { XBAR1_NS }
#else
  /** Peripheral XBAR1 base address */
  #define XBAR1_BASE                               (0x42750000u)
  /** Peripheral XBAR1 base pointer */
  #define XBAR1                                    ((XBAR_NUM_OUT221_Type *)XBAR1_BASE)
  /** Array initializer of XBAR_NUM_OUT221 peripheral base addresses */
  #define XBAR_NUM_OUT221_BASE_ADDRS               { XBAR1_BASE }
  /** Array initializer of XBAR_NUM_OUT221 peripheral base pointers */
  #define XBAR_NUM_OUT221_BASE_PTRS                { XBAR1 }
#endif

/* XBAR_NUM_OUT32 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XBAR2 base address */
  #define XBAR2_BASE                               (0x52760000u)
  /** Peripheral XBAR2 base address */
  #define XBAR2_BASE_NS                            (0x42760000u)
  /** Peripheral XBAR2 base pointer */
  #define XBAR2                                    ((XBAR_NUM_OUT32_Type *)XBAR2_BASE)
  /** Peripheral XBAR2 base pointer */
  #define XBAR2_NS                                 ((XBAR_NUM_OUT32_Type *)XBAR2_BASE_NS)
  /** Peripheral XBAR3 base address */
  #define XBAR3_BASE                               (0x52770000u)
  /** Peripheral XBAR3 base address */
  #define XBAR3_BASE_NS                            (0x42770000u)
  /** Peripheral XBAR3 base pointer */
  #define XBAR3                                    ((XBAR_NUM_OUT32_Type *)XBAR3_BASE)
  /** Peripheral XBAR3 base pointer */
  #define XBAR3_NS                                 ((XBAR_NUM_OUT32_Type *)XBAR3_BASE_NS)
  /** Array initializer of XBAR_NUM_OUT32 peripheral base addresses */
  #define XBAR_NUM_OUT32_BASE_ADDRS                { XBAR2_BASE, XBAR3_BASE }
  /** Array initializer of XBAR_NUM_OUT32 peripheral base pointers */
  #define XBAR_NUM_OUT32_BASE_PTRS                 { XBAR2, XBAR3 }
  /** Array initializer of XBAR_NUM_OUT32 peripheral base addresses */
  #define XBAR_NUM_OUT32_BASE_ADDRS_NS             { XBAR2_BASE_NS, XBAR3_BASE_NS }
  /** Array initializer of XBAR_NUM_OUT32 peripheral base pointers */
  #define XBAR_NUM_OUT32_BASE_PTRS_NS              { XBAR2_NS, XBAR3_NS }
#else
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
#endif

/* XCACHE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XCACHE_PC base address */
  #define XCACHE_PC_BASE                           (0x54400000u)
  /** Peripheral XCACHE_PC base address */
  #define XCACHE_PC_BASE_NS                        (0x44400000u)
  /** Peripheral XCACHE_PC base pointer */
  #define XCACHE_PC                                ((XCACHE_Type *)XCACHE_PC_BASE)
  /** Peripheral XCACHE_PC base pointer */
  #define XCACHE_PC_NS                             ((XCACHE_Type *)XCACHE_PC_BASE_NS)
  /** Peripheral XCACHE_PS base address */
  #define XCACHE_PS_BASE                           (0x54400800u)
  /** Peripheral XCACHE_PS base address */
  #define XCACHE_PS_BASE_NS                        (0x44400800u)
  /** Peripheral XCACHE_PS base pointer */
  #define XCACHE_PS                                ((XCACHE_Type *)XCACHE_PS_BASE)
  /** Peripheral XCACHE_PS base pointer */
  #define XCACHE_PS_NS                             ((XCACHE_Type *)XCACHE_PS_BASE_NS)
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS                        { XCACHE_PC_BASE, XCACHE_PS_BASE }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS                         { XCACHE_PC, XCACHE_PS }
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS_NS                     { XCACHE_PC_BASE_NS, XCACHE_PS_BASE_NS }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS_NS                      { XCACHE_PC_NS, XCACHE_PS_NS }
#else
  /** Peripheral XCACHE_PC base address */
  #define XCACHE_PC_BASE                           (0x44400000u)
  /** Peripheral XCACHE_PC base pointer */
  #define XCACHE_PC                                ((XCACHE_Type *)XCACHE_PC_BASE)
  /** Peripheral XCACHE_PS base address */
  #define XCACHE_PS_BASE                           (0x44400800u)
  /** Peripheral XCACHE_PS base pointer */
  #define XCACHE_PS                                ((XCACHE_Type *)XCACHE_PS_BASE)
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS                        { XCACHE_PC_BASE, XCACHE_PS_BASE }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS                         { XCACHE_PC, XCACHE_PS }
#endif
/** XCACHE physical memory base address */
#define XCACHE_PHYMEM_BASES                        { 0x00000000u, 0x20000000u }
/** XCACHE physical memory size */
#define XCACHE_PHYMEM_SIZES                        { 0x20000000u, 0xE0000000u }


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


#endif  /* MIMXRT1181_COMMON_H_ */

