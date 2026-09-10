/*
** ###################################################################
**     Processors:          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**
**     Compilers:
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    iMXRT2660RM Rev.1 DraftN, 08/2026
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMXRT2661
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MIMXRT2661_COMMON.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for MIMXRT2661
 *
 * CMSIS Peripheral Access Layer for MIMXRT2661
 */

#if !defined(MIMXRT2661_COMMON_H_)
#define MIMXRT2661_COMMON_H_                     /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U

/* ----------------------------------------------------------------------------
   --
   ---------------------------------------------------------------------------- */

/* XBAR related definitions */
typedef enum
{
    kXBAR_AUDIO     = 1, /*!< AUDIO_XBAR, XBAR in AUDIO_SS */
    kXBAR_HSP_XBAR0 = 2, /*!< HSP_XBAR_0, XBAR in HSP_SS */
    kXBAR_HSP_XBAR1 = 3, /*!< HSP_XBAR_1, XBAR in HSP_SS */
    kXBAR_HSP_XBAR2 = 4, /*!< HSP_XBAR_2, XBAR in HSP_SS */
    kXBAR_WAKE = 5 /*!< WAKE_XBAR, XBAR in WAKE_SS */
} xbar_instance_t;
#define XBAR_INFO \
    { \
        { \
            (volatile uint32_t *)AUDIO__XBAR_BASE, 0x0U, 11U, 0x2CU, 1U \
        }, \
        { \
            (volatile uint32_t *)HSP__XBAR_0_BASE, 0x0U, 261U, 0x414U, 8U \
        }, \
        { \
            (volatile uint32_t *)HSP__XBAR_1_BASE, 0x0U, 64U, 0x100U, 1U \
        }, \
        { \
            (volatile uint32_t *)HSP__XBAR_2_BASE, 0x0U, 40U, 0xA0U, 1U \
        }, \
        { \
            (volatile uint32_t *)WAKE__XBAR_BASE, 0x0U, 35U, 0x8CU, 2U \
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
#define NUMBER_OF_INT_VECTORS 350                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M85 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M85 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M85 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M85 Usage Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M85 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M85 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M85 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M85 System Tick Interrupt */

  /* Device specific interrupts */
  CMPT_CM85_CTI_IRQn           = 0,                /**< CM85: Cti Interrupt Request 0/Cti Interrupt Request 1 */
  Reserved17_IRQn              = 1,                /**< Reserved interrupt 17 */
  Reserved18_IRQn              = 2,                /**< Reserved interrupt 18 */
  CMPT_CM85_ECC_ERROR_IRQn     = 3,                /**< CM85: Single / Multi Bit Ecc Error From L1$ Or Tcm */
  Reserved20_IRQn              = 4,                /**< Reserved interrupt 20 */
  Reserved21_IRQn              = 5,                /**< Reserved interrupt 21 */
  CMPT_CM85_MCM_IRQn           = 6,                /**< CMPT CM85 MCM: Interrupt request */
  CMPT_TRDC_IRQn               = 7,                /**< CMPT TRDC: Interrupt request */
  CMPT_NPU_IRQn                = 8,                /**< CMPT NPU: Interrupt request */
  CMPT_SRAMCTL_0_IRQn          = 9,                /**< CMPT SRAMCTL0: Interrupt request */
  CMPT_SRAMCTL_1_IRQn          = 10,               /**< CMPT SRAMCTL1: Interrupt request */
  CMPT_SRAMCTL_2_IRQn          = 11,               /**< CMPT SRAMCTL2: Interrupt request */
  Reserved28_IRQn              = 12,               /**< Reserved interrupt */
  CMPT_FREQME_IRQn             = 16,               /**< CMPT FREQME: Interrupt request */
  CMPT_LLC_IRQn                = 20,               /**< CMPT LLC: Interrupt request */
  CMPT_DAP_IRQn                = 24,               /**< CMPT DAP: Interrupt request */
  MAIN_TRDC_IRQn               = 25,               /**< MAIN TRDC: Interrupt request */
  MAIN_AHB2AXI_IRQn            = 26,               /**< XHB500: Interrupt On Error Response for a Buffered Or Early Terminated Write */
  MAIN_MMU_IRQn                = 28,               /**< MMU: Interrupt request */
  MAIN_EDMA3_CH0_IRQn          = 29,               /**< MAIN EDMA3: Channel 0 interrupt */
  MAIN_EDMA3_CH1_IRQn          = 30,               /**< MAIN EDMA3: Channel 1 interrupt */
  MAIN_EDMA3_CH2_IRQn          = 31,               /**< MAIN EDMA3: Channel 2 interrupt */
  MAIN_EDMA3_CH3_IRQn          = 32,               /**< MAIN EDMA3: Channel 3 interrupt */
  MAIN_EDMA3_CH4_IRQn          = 33,               /**< MAIN EDMA3: Channel 4 interrupt */
  MAIN_EDMA3_CH5_IRQn          = 34,               /**< MAIN EDMA3: Channel 5 interrupt */
  MAIN_EDMA3_CH6_IRQn          = 35,               /**< MAIN EDMA3: Channel 6 interrupt */
  MAIN_EDMA3_CH7_IRQn          = 36,               /**< MAIN EDMA3: Channel 7 interrupt */
  MAIN_EDMA3_CH8_IRQn          = 37,               /**< MAIN EDMA3: Channel 8 interrupt */
  MAIN_EDMA3_CH9_IRQn          = 38,               /**< MAIN EDMA3: Channel 9 interrupt */
  MAIN_EDMA3_CH10_IRQn         = 39,               /**< MAIN EDMA3: Channel 10 interrupt */
  MAIN_EDMA3_CH11_IRQn         = 40,               /**< MAIN EDMA3: Channel 11 interrupt */
  MAIN_EDMA3_CH12_IRQn         = 41,               /**< MAIN EDMA3: Channel 12 interrupt */
  MAIN_EDMA3_CH13_IRQn         = 42,               /**< MAIN EDMA3: Channel 13 interrupt */
  MAIN_EDMA3_CH14_IRQn         = 43,               /**< MAIN EDMA3: Channel 14 interrupt */
  MAIN_EDMA3_CH15_IRQn         = 44,               /**< MAIN EDMA3: Channel 15 interrupt */
  MAIN_EDMA3_CH16_IRQn         = 45,               /**< MAIN EDMA3: Channel 16 interrupt */
  MAIN_EDMA3_CH17_IRQn         = 46,               /**< MAIN EDMA3: Channel 17 interrupt */
  MAIN_EDMA3_CH18_IRQn         = 47,               /**< MAIN EDMA3: Channel 18 interrupt */
  MAIN_EDMA3_CH19_IRQn         = 48,               /**< MAIN EDMA3: Channel 19 interrupt */
  MAIN_EDMA3_CH20_IRQn         = 49,               /**< MAIN EDMA3: Channel 20 interrupt */
  MAIN_EDMA3_CH21_IRQn         = 50,               /**< MAIN EDMA3: Channel 21 interrupt */
  MAIN_EDMA3_CH22_IRQn         = 51,               /**< MAIN EDMA3: Channel 22 interrupt */
  MAIN_EDMA3_CH23_IRQn         = 52,               /**< MAIN EDMA3: Channel 23 interrupt */
  MAIN_EDMA3_CH24_IRQn         = 53,               /**< MAIN EDMA3: Channel 24 interrupt */
  MAIN_EDMA3_CH25_IRQn         = 54,               /**< MAIN EDMA3: Channel 25 interrupt */
  MAIN_EDMA3_CH26_IRQn         = 55,               /**< MAIN EDMA3: Channel 26 interrupt */
  MAIN_EDMA3_CH27_IRQn         = 56,               /**< MAIN EDMA3: Channel 27 interrupt */
  MAIN_EDMA3_CH28_IRQn         = 57,               /**< MAIN EDMA3: Channel 28 interrupt */
  MAIN_EDMA3_CH29_IRQn         = 58,               /**< MAIN EDMA3: Channel 29 interrupt */
  MAIN_EDMA3_CH30_IRQn         = 59,               /**< MAIN EDMA3: Channel 30 interrupt */
  MAIN_EDMA3_CH31_IRQn         = 60,               /**< MAIN EDMA3: Channel 31 interrupt */
  MAIN_EDMA5_CH0_IRQn          = 61,               /**< MAIN EDMA5: Channel 0 interrupt */
  MAIN_EDMA5_CH1_IRQn          = 62,               /**< MAIN EDMA5: Channel 1 interrupt */
  MAIN_EDMA5_CH2_IRQn          = 63,               /**< MAIN EDMA5: Channel 2 interrupt */
  MAIN_EDMA5_CH3_IRQn          = 64,               /**< MAIN EDMA5: Channel 3 interrupt */
  MAIN_EDMA5_CH4_IRQn          = 65,               /**< MAIN EDMA5: Channel 4 interrupt */
  MAIN_EDMA5_CH5_IRQn          = 66,               /**< MAIN EDMA5: Channel 5 interrupt */
  MAIN_EDMA5_CH6_IRQn          = 67,               /**< MAIN EDMA5: Channel 6 interrupt */
  MAIN_EDMA5_CH7_IRQn          = 68,               /**< MAIN EDMA5: Channel 7 interrupt */
  MAIN_EDMA5_CH8_IRQn          = 69,               /**< MAIN EDMA5: Channel 8 interrupt */
  MAIN_EDMA5_CH9_IRQn          = 70,               /**< MAIN EDMA5: Channel 9 interrupt */
  MAIN_EDMA5_CH10_IRQn         = 71,               /**< MAIN EDMA5: Channel 10 interrupt */
  MAIN_EDMA5_CH11_IRQn         = 72,               /**< MAIN EDMA5: Channel 11 interrupt */
  MAIN_EDMA5_CH12_IRQn         = 73,               /**< MAIN EDMA5: Channel 12 interrupt */
  MAIN_EDMA5_CH13_IRQn         = 74,               /**< MAIN EDMA5: Channel 13 interrupt */
  MAIN_EDMA5_CH14_IRQn         = 75,               /**< MAIN EDMA5: Channel 14 interrupt */
  MAIN_EDMA5_CH15_IRQn         = 76,               /**< MAIN EDMA5: Channel 15 interrupt */
  MAIN_FREQME_IRQn             = 77,               /**< MAIN FREQME: interrupt request */
  HSP_STM_IRQn                 = 78,               /**< HSP STM: Interrupt request */
  MAIN_XSPI0_IRQn              = 82,               /**< MAIN XSPI0: interrupt request */
  MAIN_XSPI1_IRQn              = 83,               /**< MAIN XSPI1: interrupt request */
  SYSCON_CGU_INT0_IRQn         = 86,               /**< CGU: Vdda 0V8 Status Interrupt */
  SYSCON_CGU_INT1_IRQn         = 87,               /**< CGU: Audiopll Dnum Update Done Interrupt */
  SYSCON_CGU_INT2_IRQn         = 88,               /**< CGU: Videopll Dnum Update Done Interrupt */
  MAIN_CSSI_IRQn               = 89,               /**< CSSI:Status/Error Interrupt/Active Interrupt */
  MAIN_CSSI_SENTMU0A_IRQn      = 90,               /**< CSSI_MU: MU0A Ored Tx Interrupt To Mua */
  MAIN_CSSI_SENTMU1A_IRQn      = 91,               /**< CSSI_MU: Mu1A Ored Tx Interrupt To Mua */
  SYSCON_PMU_INT0_IRQn         = 93,               /**< PMU: Ored All Sensor And Monitor Interrupts */
  SYSCON_PMU_INT1_IRQn         = 94,               /**< PMU: Body Bias Interrupt */
  SYSCON_RESETCON_IRQn         = 95,               /**< SYSCON RESETCON: Interrupt request */
  SYSCON_FREQME_IRQn           = 96,               /**< SYSCON FREQME: Interrupt request */
  HSP_XBAR0_CH0_IRQn           = 100,              /**< HSP XBAR0 Channel 0 interrupt */
  HSP_XBAR0_CH1_IRQn           = 101,              /**< HSP XBAR0 Channel 1 interrupt */
  HSP_XBAR0_CH2_IRQn           = 102,              /**< HSP XBAR0 Channel 2 interrupt */
  HSP_XBAR0_CH3_IRQn           = 103,              /**< HSP XBAR0 Channel 3 interrupt */
  HSP_XBAR0_CH4_IRQn           = 104,              /**< HSP XBAR0 Channel 4 interrupt */
  HSP_XBAR0_CH5_IRQn           = 105,              /**< HSP XBAR0 Channel 5 interrupt */
  HSP_XBAR0_CH6_IRQn           = 106,              /**< HSP XBAR0 Channel 6 interrupt */
  HSP_XBAR0_CH7_IRQn           = 107,              /**< HSP XBAR0 Channel 7 interrupt */
  HSP_ADC0_IRQn                = 112,              /**< HSP ADC0 interrupt */
  HSP_ADC1_IRQn                = 113,              /**< HSP ADC1 interrupt */
  HSP_DAC_IRQn                 = 114,              /**< HSP DAC interrupt */
  HSP_LPIT0_IRQn               = 115,              /**< HSP LPIT0 interrupt */
  HSP_LPIT1_IRQn               = 116,              /**< HSP LPIT1 interrupt */
  HSP_EFLEXPWM0_CH0_IRQn       = 117,              /**< HSP EFLEXPWM0 channel 0 interrupt */
  HSP_EFLEXPWM0_CH1_IRQn       = 118,              /**< HSP EFLEXPWM0 channel 1 interrupt */
  HSP_EFLEXPWM0_CH2_IRQn       = 119,              /**< HSP EFLEXPWM0 channel 2 interrupt */
  HSP_EFLEXPWM0_CH3_IRQn       = 120,              /**< HSP EFLEXPWM0 channel 3 interrupt */
  HSP_EFLEXPWM0_ERROR_IRQn     = 121,              /**< HSP EFLEXPWM0 fault interrupt */
  HSP_EFLEXPWM1_CH0_IRQn       = 122,              /**< HSP EFLEXPWM1 channel 0 interrupt */
  HSP_EFLEXPWM1_CH1_IRQn       = 123,              /**< HSP EFLEXPWM1 channel 1 interrupt */
  HSP_EFLEXPWM1_CH2_IRQn       = 124,              /**< HSP EFLEXPWM1 channel 2 interrupt */
  HSP_EFLEXPWM1_CH3_IRQn       = 125,              /**< HSP EFLEXPWM1 channel 3 interrupt */
  HSP_EFLEXPWM1_ERROR_IRQn     = 126,              /**< HSP EFLEXPWM1 fault interrupt */
  HSP_EFLEXPWM2_CH0_IRQn       = 127,              /**< HSP EFLEXPWM2 channel 0 interrupt */
  HSP_EFLEXPWM2_CH1_IRQn       = 128,              /**< HSP EFLEXPWM2 channel 1 interrupt */
  HSP_EFLEXPWM2_CH2_IRQn       = 129,              /**< HSP EFLEXPWM2 channel 2 interrupt */
  HSP_EFLEXPWM2_CH3_IRQn       = 130,              /**< HSP EFLEXPWM2 channel 3 interrupt */
  HSP_EFLEXPWM2_ERROR_IRQn     = 131,              /**< HSP EFLEXPWM2 fault interrupt */
  HSP_EFLEXPWM3_CH0_IRQn       = 132,              /**< HSP EFLEXPWM3 channel 0 interrupt */
  HSP_EFLEXPWM3_CH1_IRQn       = 133,              /**< HSP EFLEXPWM3 channel 1 interrupt */
  HSP_EFLEXPWM3_CH2_IRQn       = 134,              /**< HSP EFLEXPWM3 channel 2 interrupt */
  HSP_EFLEXPWM3_CH3_IRQn       = 135,              /**< HSP EFLEXPWM3 channel 3 interrupt */
  HSP_EFLEXPWM3_ERROR_IRQn     = 136,              /**< HSP EFLEXPWM3 fault interrupt */
  HSP_QTPM0_IRQn               = 137,              /**< HSP QUADTPM0 interrupt */
  HSP_QTPM1_IRQn               = 138,              /**< HSP QUADTPM1 interrupt */
  HSP_QTPM2_IRQn               = 139,              /**< HSP QUADTPM2 interrupt */
  HSP_QTPM3_IRQn               = 140,              /**< HSP QUADTPM3 interrupt */
  HSP_QTMR0_IRQn               = 149,              /**< HSP QUADTMR0 interrupt */
  HSP_QTMR1_IRQn               = 150,              /**< HSP QUADTMR1 interrupt */
  HSP_QTMR2_IRQn               = 151,              /**< HSP QUADTMR2 interrupt */
  HSP_QTMR3_IRQn               = 152,              /**< HSP QUADTMR3 interrupt */
  HSP_EQDC0_IRQn               = 153,              /**< HSP EQDC0 interrupt */
  HSP_EQDC1_IRQn               = 154,              /**< HSP EQDC1 interrupt */
  HSP_EQDC2_IRQn               = 155,              /**< HSP EQDC2 interrupt */
  HSP_EQDC3_IRQn               = 156,              /**< HSP EQDC3 interrupt */
  HSP_SINC0_CH0_IRQn           = 157,              /**< HSP SINC0 channel 0 interrupt */
  HSP_SINC0_CH1_IRQn           = 158,              /**< HSP SINC0 channel 1 interrupt */
  HSP_SINC0_CH2_IRQn           = 159,              /**< HSP SINC0 channel 2 interrupt */
  HSP_SINC0_CH3_IRQn           = 160,              /**< HSP SINC0 channel 3 interrupt */
  HSP_SINC1_CH0_IRQn           = 161,              /**< HSP SINC1 channel 0 interrupt */
  HSP_SINC1_CH1_IRQn           = 162,              /**< HSP SINC1 channel 1 interrupt */
  HSP_SINC1_CH2_IRQn           = 163,              /**< HSP SINC1 channel 2 interrupt */
  HSP_SINC1_CH3_IRQn           = 164,              /**< HSP SINC1 channel 3 interrupt */
  HSP_FLEXCAN0_IRQn            = 165,              /**< HSP FLEXCAN0 interrupt */
  HSP_FLEXCAN0_ERROR_IRQn      = 166,              /**< HSP FLEXCAN0 error interrupt */
  HSP_FLEXCAN1_IRQn            = 167,              /**< HSP FLEXCAN1 interrupt */
  HSP_FLEXCAN1_ERROR_IRQn      = 168,              /**< HSP FLEXCAN1 error interrupt */
  HSP_FLEXCAN2_IRQn            = 169,              /**< HSP FLEXCAN2 interrupt */
  HSP_FLEXCAN2_ERROR_IRQn      = 170,              /**< HSP FLEXCAN2 error interrupt */
  HSP_FLEXIO0_IRQn             = 171,              /**< HSP FLEXIO0 interrupt */
  HSP_FLEXIO1_IRQn             = 172,              /**< HSP FLEXIO1 interrupt */
  HSP_FLEXIO2_IRQn             = 173,              /**< HSP FLEXIO2 interrupt */
  HSP_I3C_IRQn                 = 174,              /**< HSP I3C interrupt */
  HSP_LPI2C0_IRQn              = 175,              /**< HSP LPI2C0 interrupt */
  HSP_LPI2C1_IRQn              = 176,              /**< HSP LPI2C1 interrupt */
  Reserved193_IRQn             = 177,              /**< Reserved interrupt */
  Reserved194_IRQn             = 178,              /**< Reserved interrupt */
  HSP_LPSPI0_IRQn              = 179,              /**< HSP LPSPI0 interrupt */
  HSP_LPSPI1_IRQn              = 180,              /**< HSP LPSPI1 interrupt */
  HSP_LPSPI2_IRQn              = 181,              /**< HSP LPSPI2 interrupt */
  HSP_LPSPI3_IRQn              = 182,              /**< HSP LPSPI3 interrupt */
  HSP_LPSPI4_IRQn              = 183,              /**< HSP LPSPI4 interrupt */
  HSP_LPUART0_IRQn             = 184,              /**< HSP LPUART0 interrupt */
  HSP_LPUART1_IRQn             = 185,              /**< HSP LPUART1 interrupt */
  HSP_LPUART2_IRQn             = 186,              /**< HSP LPUART2 interrupt */
  HSP_LPUART3_IRQn             = 187,              /**< HSP LPUART3 interrupt */
  HSP_LPUART4_IRQn             = 188,              /**< HSP LPUART4 interrupt */
  HSP_LPUART5_IRQn             = 189,              /**< HSP LPUART5 interrupt */
  HSP_GPIO0_CH0_IRQn           = 190,              /**< HSP GPIO0 channel 0 interrupt */
  HSP_GPIO0_CH1_IRQn           = 191,              /**< HSP GPIO0 channel 1 interrupt */
  HSP_GPIO1_CH0_IRQn           = 192,              /**< HSP GPIO1 channel 0 interrupt */
  HSP_GPIO1_CH1_IRQn           = 193,              /**< HSP GPIO1 channel 1 interrupt */
  HSP_GPIO2_CH0_IRQn           = 194,              /**< HSP GPIO2 channel 0 interrupt */
  HSP_GPIO2_CH1_IRQn           = 195,              /**< HSP GPIO2 channel 1 interrupt */
  HSP_GPIO3_CH0_IRQn           = 196,              /**< HSP GPIO3 channel 0 interrupt */
  HSP_GPIO3_CH1_IRQn           = 197,              /**< HSP GPIO3 channel 1 interrupt */
  HSP_GPIO4_CH0_IRQn           = 198,              /**< HSP GPIO4 channel 0 interrupt */
  HSP_GPIO4_CH1_IRQn           = 199,              /**< HSP GPIO4 channel 1 interrupt */
  Reserved216_IRQn             = 200,              /**< Reserved interrupt */
  Reserved217_IRQn             = 201,              /**< Reserved interrupt */
  Reserved218_IRQn             = 202,              /**< Reserved interrupt */
  Reserved219_IRQn             = 203,              /**< Reserved interrupt */
  WAKE_TRDC_IRQn               = 205,              /**< WAKE TRDC interrupt */
  WAKE_XBAR_CH0_IRQn           = 206,              /**< WAKE XBAR channel 0 interrupt */
  WAKE_XBAR_CH1_IRQn           = 207,              /**< WAKE XBAR channel 1 interrupt */
  WAKE_EDMA3_CH0_IRQn          = 208,              /**< WAKE EDMA3: Channel 0 interrupt */
  WAKE_EDMA3_CH1_IRQn          = 209,              /**< WAKE EDMA3: Channel 1 interrupt */
  WAKE_EDMA3_CH2_IRQn          = 210,              /**< WAKE EDMA3: Channel 2 interrupt */
  WAKE_EDMA3_CH3_IRQn          = 211,              /**< WAKE EDMA3: Channel 3 interrupt */
  WAKE_EDMA3_CH4_IRQn          = 212,              /**< WAKE EDMA3: Channel 4 interrupt */
  WAKE_EDMA3_CH5_IRQn          = 213,              /**< WAKE EDMA3: Channel 5 interrupt */
  WAKE_EDMA3_CH6_IRQn          = 214,              /**< WAKE EDMA3: Channel 6 interrupt */
  WAKE_EDMA3_CH7_IRQn          = 215,              /**< WAKE EDMA3: Channel 7 interrupt */
  WAKE_ACMP0_IRQn              = 216,              /**< WAKE CMP0 interrupt */
  WAKE_ACMP1_IRQn              = 217,              /**< WAKE CMP1 interrupt */
  WAKE_ACMP2_IRQn              = 218,              /**< WAKE CMP2 interrupt */
  WAKE_ACMP3_IRQn              = 219,              /**< WAKE CMP3 interrupt */
  WAKE_EWM_IRQn                = 220,              /**< WAKE EWM interrupt */
  WAKE_FREQME_IRQn             = 221,              /**< WAKE FREQME interrupt */
  WAKE_LPTMR0_IRQn             = 222,              /**< WAKE LPTMR0 interrupt */
  WAKE_LPTMR1_IRQn             = 223,              /**< WAKE LPTMR1 interrupt */
  WAKE_QTPM0_IRQn              = 224,              /**< WAKE QTPM0 interrupt */
  WAKE_QTPM1_IRQn              = 225,              /**< WAKE QTPM1 interrupt */
  WAKE_QTPM2_IRQn              = 226,              /**< WAKE QTPM2 interrupt */
  WAKE_QTPM3_IRQn              = 227,              /**< WAKE QTPM3 interrupt */
  WAKE_SWT0_IRQn               = 228,              /**< WAKE SWT0 interrupt */
  WAKE_SWT1_IRQn               = 229,              /**< WAKE SWT1 interrupt */
  Reserved246_IRQn             = 230,              /**< Reserved interrupt */
  Reserved247_IRQn             = 231,              /**< Reserved interrupt */
  WAKE_I3C_IRQn                = 234,              /**< WAKE I3C interrupt */
  WAKE_LPI2C0_IRQn             = 235,              /**< WAKE LPI2C0 interrupt */
  WAKE_LPI2C1_IRQn             = 236,              /**< WAKE LPI2C1 interrupt */
  WAKE_LPSPI_IRQn              = 237,              /**< WAKE LPSPI interrupt */
  WAKE_LPUART0_IRQn            = 238,              /**< WAKE LPUART0 interrupt */
  WAKE_LPUART1_IRQn            = 239,              /**< WAKE LPUART1 interrupt */
  WAKE_GPIO_CH0_IRQn           = 240,              /**< WAKE GPIO channel 0 interrupt */
  WAKE_GPIO_CH1_IRQn           = 241,              /**< WAKE GPIO channel 1 interrupt */
  WAKE_PDM_EVENT_IRQn          = 242,              /**< WAKE MICIFL  Filter Results Available (Fifo) Interrupt/ */
  WAKE_PDM_ERROR_IRQn          = 243,              /**< WAKE MICIFL Error interrupt */
  WAKE_PDM_HWVAD_EVENT_IRQn    = 244,              /**< WAKE MICIFL Hwvad Activation interrupt */
  WAKE_PDM_HWVAD_ERROR_IRQn    = 245,              /**< WAKE MICIFL Hwvad Exception Interrupt */
  VBAT_BBSM_INT0_IRQn          = 247,              /**< BBSM: Alarm interrupt0 */
  VBAT_TDET_IRQn               = 249,              /**< VBAT TDET interrupt */
  VBAT_LPTMR_IRQn              = 250,              /**< VBAT LPTMR interrupt */
  VBAT_RTC_IRQn                = 251,              /**< VBAT RTC interrupt */
  VBAT_GPIO_CH0_IRQn           = 252,              /**< VBAT GPIO channel 0 interrupt */
  VBAT_GPIO_CH1_IRQn           = 253,              /**< VBAT GPIO channel 1 interrupt */
  VBAT_VBATCON_IRQn            = 254,              /**< vbatcon Interrupt Request */
  AUDIO_TRDC_IRQn              = 255,              /**< AUDIO TRDC interrupt */
  AUDIO_SAI0_IRQn              = 256,              /**< AUDIO SAI0 interrupt */
  AUDIO_SAI1_IRQn              = 257,              /**< AUDIO SAI1 interrupt */
  AUDIO_SAI2_IRQn              = 258,              /**< AUDIO SAI2 interrupt */
  AUDIO_PDM_EVENT_IRQn         = 262,              /**< AUDIO MICDIL Filter Results Available (Fifo) Interrupt */
  AUDIO_PDM_ERROR_IRQn         = 263,              /**< AUDIO MICDIL Error interrupt */
  AUDIO_SPDIF_IRQn             = 270,              /**< AUDIO SPDIF interrupt */
  AUDIO_EDMA3_CH0_IRQn         = 271,              /**< AUDIO EDMA3: Channel 0 interrupt */
  AUDIO_EDMA3_CH1_IRQn         = 272,              /**< AUDIO EDMA3: Channel 1 interrupt */
  AUDIO_EDMA3_CH2_IRQn         = 273,              /**< AUDIO EDMA3: Channel 2 interrupt */
  AUDIO_EDMA3_CH3_IRQn         = 274,              /**< AUDIO EDMA3: Channel 3 interrupt */
  AUDIO_EDMA3_CH4_IRQn         = 275,              /**< AUDIO EDMA3: Channel 4 interrupt */
  AUDIO_EDMA3_CH5_IRQn         = 276,              /**< AUDIO EDMA3: Channel 5 interrupt */
  AUDIO_EDMA3_CH6_IRQn         = 277,              /**< AUDIO EDMA3: Channel 6 interrupt */
  AUDIO_EDMA3_CH7_IRQn         = 278,              /**< AUDIO EDMA3: Channel 7 interrupt */
  AUDIO_ASRC_IRQn              = 288,              /**< AUDIO ASRC interrupt */
  AUDIO_FREQME_IRQn            = 289,              /**< AUDIO FREQME interrupt */
  COMM_TRDC_IRQn               = 295,              /**< COMM TRDC interrupt */
  COMM_ENET_QOS_IRQn           = 296,              /**< COMM ENET_QOS interrupt */
  COMM_ENET_QOS_TX_IRQn        = 297,              /**< ENET_QOS: Per Channel Transmit Interrupt Signal To Host System */
  COMM_ENET_QOS_RX_IRQn        = 298,              /**< ENET_QOS: Per Channel Receive Interrupt Signal To Host System */
  COMM_ENET_TX_IRQn            = 299,              /**< COMM ENET TX interrupt */
  COMM_ENET_RX_IRQn            = 300,              /**< COMM ENET RX interrupt */
  COMM_ENET_OTHER_IRQn         = 301,              /**< ENET_1G_MAC: ETH OTHER_INT0_17 */
  COMM_ENET_1588_IRQn          = 302,              /**< ENET_1G_MAC: IEEE-1588 Timer Interrupt */
  COMM_FLEXSPI_SLV_IRQn        = 303,              /**< COMM FlexSPI follower interrupt */
  COMM_USB0_IRQn               = 304,              /**< COMM USBHS interrupt */
  COMM_USBPHY_IRQn             = 305,              /**< COMM USBPHY interrupt */
  COMM_USB1_IRQn               = 306,              /**< COMM USBFS interrupt */
  COMM_USDHC0_IRQn             = 307,              /**< COMM USDHC0 interrupt */
  COMM_USDHC1_IRQn             = 308,              /**< COMM USDHC1 interrupt */
  COMM_TENBASET_PHY0_IRQn      = 310,              /**< XENO_PHY0:Functional IRQ1 interrupt request  */
  COMM_TENBASET_PHY1_IRQn      = 312,              /**< XENO_PHY1:Functional IRQ1 interrupt request  */
  COMM_FREQME_IRQn             = 314,              /**< COMM FREQME interrupt */
  MEDIA_TRDC_IRQn              = 315,              /**< MEDIA TRDC interrupt */
  MEDIA_DCIF_CH0_IRQn          = 317,              /**< MEDIA DCIF channel 0 interrupt */
  MEDIA_DCIF_CH1_IRQn          = 318,              /**< MEDIA DCIF channel 1 interrupt */
  MEDIA_DCIF_CH2_IRQn          = 319,              /**< MEDIA DCIF channel 2 interrupt */
  MEDIA_DCIF_CH3_IRQn          = 320,              /**< MEDIA DCIF channel 3 interrupt */
  MEDIA_DCIF_CH4_IRQn          = 321,              /**< MEDIA DCIF channel 4 interrupt */
  MEDIA_DCIF_CH5_IRQn          = 322,              /**< MEDIA DCIF channel 5 interrupt */
  MEDIA_DCIF_CH6_IRQn          = 323,              /**< MEDIA DCIF channel 6 interrupt */
  MEDIA_DCIF_CH7_IRQn          = 324,              /**< MEDIA DCIF channel 7 interrupt */
  MEDIA_DCIF_CH8_IRQn          = 325,              /**< MEDIA DCIF channel 8 interrupt */
  Reserved342_IRQn             = 326,              /**< Reserved interrupt */
  MEDIA_REFORMATTER_IRQn       = 327,              /**< MEDIA REFORMATTER interrupt */
  MEDIA_ISI_IRQn               = 328,              /**< MEDIA ISI interrupt */
  MEDIA_TINGPU_IRQn            = 329,              /**< MEDIA TINGPU interrupt */
  MEDIA_JPEGDEC_IRQn           = 330,              /**< MEDIA JPEGDEC interrupt */
  Reserved347_IRQn             = 331,              /**< Reserved interrupt */
  Reserved348_IRQn             = 332,              /**< Reserved interrupt */
  MEDIA_FREQME_IRQn            = 333               /**< MEDIA FREQME interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M85 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M85 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __ICACHE_PRESENT               1         /**< Defines if an ICACHE is present or not */
#define __DCACHE_PRESENT               1         /**< Defines if an DCACHE is present or not */
#define __NVIC_PRIO_BITS               3         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */
#define __DSP_PRESENT                  1         /**< Defines if Armv8-M Mainline core supports DSP instructions */
#define __SAUREGION_PRESENT            1         /**< Defines if an SAU is present or not */

#include "core_cm85.h"                 /* Core Peripheral Access Layer */
#include "system_MIMXRT2661.h"         /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMXRT2661_SERIES
#define MIMXRT2661_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMXRT2661_features.h"

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup asrc_clock_source
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
    kASRC_ClockSourceBitClock0_AUD_PLL_DIV_CLK0 = 0U, /**< DSC clock output 0 */
    kASRC_ClockSourceBitClock1_AUD_PLL_DIV_CLK1 = 1U, /**< DSC clock output 1 */
    kASRC_ClockSourceBitClock2_AUD_CLK0 = 2U,      /**< Audio Clock Multiplexer 0 output */
    kASRC_ClockSourceBitClock3_AUD_CLK1 = 3U,      /**< Audio Clock Multiplexer 1 output */
    kASRC_ClockSourceBitClock4_eSAI0_RX_CLK = 4U,  /**< eSAI0 Receiver serial bit clock */
    kASRC_ClockSourceBitClock5_eSAI0_TX_CLK = 5U,  /**< eSAI0 Transmitter serial bit clock */
    kASRC_ClockSourceBitClock6_SPDIF0_RX = 6U,     /**< SPDIF0 Receiver serial bit clock */
    kASRC_ClockSourceBitClock7_SPDIF1_RX = 7U,     /**< SPDIF1 Receiver serial bit clock */
    kASRC_ClockSourceBitClock8_SAI0_RX_BCLK = 8U,  /**< SAI0 Receiver serial bit clock */
    kASRC_ClockSourceBitClock9_SAI0_TX_BCLK = 9U,  /**< SAI0 Transmitter serial bit clock */
    kASRC_ClockSourceBitClocka_SAI1_RX_BCLK = 10U, /**< SAI1 Receiver serial bit clock */
    kASRC_ClockSourceBitClockb_SAI1_TX_BCLK = 11U, /**< SAI1 Transmitter serial bit clock */
    kASRC_ClockSourceBitClockc_SAI2_RX_BCLK = 12U, /**< SAI2 Receiver serial bit clock */
    kASRC_ClockSourceBitClockd_SAI3_RX_BCLK = 13U, /**< SAI3 Receiver serial bit clock */
    kASRC_ClockSourceBitClocke_ASRC0_PRE_SEL = 14U, /**< ASRC0 pre-selector multiplexer */
    kASRC_ClockSourceMax            = 14U,         /**< max value */
} asrc_clock_source_t;

/*!
 * @addtogroup edma0_request
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the DMA0 hardware request
 *
 * Defines the enumeration for the DMA0 hardware request collections.
 */
typedef enum _main_edma5_request_source
{
    kDmaRequestMux0MainXSPI0Rx      = 1|0x100U,    /**< MAIN XSPI0 Rx Buffer Drain Request */
    kDmaRequestMux0MainXSPI0Tx      = 2|0x100U,    /**< MAIN XSPI0 Tx Buffer Fill Request */
    kDmaRequestMux0MainXSPI1Rx      = 3|0x100U,    /**< MAIN XSPI1 Rx Buffer Drain Request */
    kDmaRequestMux0MainXSPI1Tx      = 4|0x100U,    /**< MAIN XSPI1 Tx Buffer Fill Request */
    kDmaRequestMux0HspXBAR0OUT0     = 10|0x100U,   /**< HSP XBAR_OUT0 Request */
    kDmaRequestMux0HspXBAR0OUT1     = 11|0x100U,   /**< HSP XBAR_OUT1 Request */
    kDmaRequestMux0HspXBAR0OUT2     = 12|0x100U,   /**< HSP XBAR_OUT2 Request */
    kDmaRequestMux0HspXBAR0OUT3     = 13|0x100U,   /**< HSP XBAR_OUT3 Request */
    kDmaRequestMux0HspXBAR0OUT4     = 14|0x100U,   /**< HSP XBAR_OUT4 Request */
    kDmaRequestMux0HspXBAR0OUT5     = 15|0x100U,   /**< HSP XBAR_OUT5 Request */
    kDmaRequestMux0HspXBAR0OUT6     = 16|0x100U,   /**< HSP XBAR_OUT6 Request */
    kDmaRequestMux0HspXBAR0OUT7     = 17|0x100U,   /**< HSP XBAR_OUT7 Request */
    kDmaRequestMux0HspADC0Channel0  = 18|0x100U,   /**< HSP ADC0 Fifo 0 Request */
    kDmaRequestMux0HspADC0Channel1  = 19|0x100U,   /**< HSP ADC0 Fifo 1 Request */
    kDmaRequestMux0HspADC1Channel0  = 20|0x100U,   /**< HSP ADC1 Fifo 0 Request */
    kDmaRequestMux0HspADC1Channel1  = 21|0x100U,   /**< HSP ADC1 Fifo 1 Request */
    kDmaRequestMux0HspDAC           = 22|0x100U,   /**< HSP DAC Fifo Request */
    kDmaRequestMux0HspFlexIO0Request0Request8 = 23|0x100U, /**< HSP FlexIO0 Request 0 and Request 8 */
    kDmaRequestMux0HspFlexIO0Request1Request9 = 24|0x100U, /**< HSP FlexIO0 Request 1 and Request 9 */
    kDmaRequestMux0HspFlexIO0Request2Request10 = 25|0x100U, /**< HSP FlexIO0 Request 2 and Request 10 */
    kDmaRequestMux0HspFlexIO0Request3Request11 = 26|0x100U, /**< HSP FlexIO0 Request 3 and Request 11 */
    kDmaRequestMux0HspFlexIO0Request4Request12 = 27|0x100U, /**< HSP FlexIO0 Request 4 and Request 12 */
    kDmaRequestMux0HspFlexIO0Request5Request13 = 28|0x100U, /**< HSP FlexIO0 Request 5 and Request 13 */
    kDmaRequestMux0HspFlexIO0Request6Request14 = 29|0x100U, /**< HSP FlexIO0 Request 6 and Request 14 */
    kDmaRequestMux0HspFlexIO0Request7Request15 = 30|0x100U, /**< HSP FlexIO0 Request 7 and Request 15 */
    kDmaRequestMux0HspFlexIO1Request0Request8 = 31|0x100U, /**< HSP FlexIO0 Request 0 and Request 8 */
    kDmaRequestMux0HspFlexIO1Request1Request9 = 32|0x100U, /**< HSP FlexIO0 Request 1 and Request 9 */
    kDmaRequestMux0HspFlexIO1Request2Request10 = 33|0x100U, /**< HSP FlexIO0 Request 2 and Request 10 */
    kDmaRequestMux0HspFlexIO1Request3Request11 = 34|0x100U, /**< HSP FlexIO0 Request 3 and Request 11 */
    kDmaRequestMux0HspFlexIO1Request4Request12 = 35|0x100U, /**< HSP FlexIO0 Request 4 and Request 12 */
    kDmaRequestMux0HspFlexIO1Request5Request13 = 36|0x100U, /**< HSP FlexIO0 Request 5 and Request 13 */
    kDmaRequestMux0HspFlexIO1Request6Request14 = 37|0x100U, /**< HSP FlexIO0 Request 6 and Request 14 */
    kDmaRequestMux0HspFlexIO1Request7Request15 = 38|0x100U, /**< HSP FlexIO0 Request 7 and Request 15 */
    kDmaRequestMux0HspFlexIO2Request0Request8 = 39|0x100U, /**< HSP FlexIO0 Request 0 and Request 8 */
    kDmaRequestMux0HspFlexIO2Request1Request9 = 40|0x100U, /**< HSP FlexIO0 Request 1 and Request 9 */
    kDmaRequestMux0HspFlexIO2Request2Request10 = 41|0x100U, /**< HSP FlexIO0 Request 2 and Request 10 */
    kDmaRequestMux0HspFlexIO2Request3Request11 = 42|0x100U, /**< HSP FlexIO0 Request 3 and Request 11 */
    kDmaRequestMux0HspFlexIO2Request4Request12 = 43|0x100U, /**< HSP FlexIO0 Request 4 and Request 12 */
    kDmaRequestMux0HspFlexIO2Request5Request13 = 44|0x100U, /**< HSP FlexIO0 Request 5 and Request 13 */
    kDmaRequestMux0HspFlexIO2Request6Request14 = 45|0x100U, /**< HSP FlexIO0 Request 6 and Request 14 */
    kDmaRequestMux0HspFlexIO2Request7Request15 = 46|0x100U, /**< HSP FlexIO0 Request 7 and Request 15 */
    kDmaRequestMux0HspLPSPI0Tx      = 47|0x100U,   /**< HSP LPSPI0 Master/Slave Transmit */
    kDmaRequestMux0HspLPSPI0Rx      = 48|0x100U,   /**< HSP LPSPI0 Master/Slave Receive */
    kDmaRequestMux0HspLPSPI1Tx      = 49|0x100U,   /**< HSP LPSPI1 Master/Slave Transmit */
    kDmaRequestMux0HspLPSPI1Rx      = 50|0x100U,   /**< HSP LPSPI1 Master/Slave Receive */
    kDmaRequestMux0HspLPSPI2Tx      = 51|0x100U,   /**< HSP LPSPI2 Master/Slave Transmit */
    kDmaRequestMux0HspLPSPI2Rx      = 52|0x100U,   /**< HSP LPSPI2 Master/Slave Receive */
    kDmaRequestMux0HspLPSPI3Tx      = 53|0x100U,   /**< HSP LPSPI3 Master/Slave Transmit */
    kDmaRequestMux0HspLPSPI3Rx      = 54|0x100U,   /**< HSP LPSPI3 Master/Slave Receive */
    kDmaRequestMux0HspLPSPI4Tx      = 55|0x100U,   /**< HSP LPSPI4 Master/Slave Transmit */
    kDmaRequestMux0HspLPSPI4Rx      = 56|0x100U,   /**< HSP LPSPI4 Master/Slave Receive */
    kDmaRequestMux0HspRGPIO0Channel0 = 57|0x100U,  /**< HSP RGPIO0 Channel 0 */
    kDmaRequestMux0HspRGPIO0Channel1 = 58|0x100U,  /**< HSP RGPIO0 Channel 1 */
    kDmaRequestMux0HspRGPIO1Channel0 = 59|0x100U,  /**< HSP RGPIO1 Channel 0 */
    kDmaRequestMux0HspRGPIO1Channel1 = 60|0x100U,  /**< HSP RGPIO1 Channel 1 */
    kDmaRequestMux0HspRGPIO2Channel0 = 61|0x100U,  /**< HSP RGPIO2 Channel 0 */
    kDmaRequestMux0HspRGPIO2Channel1 = 62|0x100U,  /**< HSP RGPIO2 Channel 1 */
    kDmaRequestMux0HspRGPIO3Channel0 = 63|0x100U,  /**< HSP RGPIO3 Channel 0 */
    kDmaRequestMux0HspRGPIO3Channel1 = 64|0x100U,  /**< HSP RGPIO3 Channel 1 */
    kDmaRequestMux0HspRGPIO4Channel0 = 65|0x100U,  /**< HSP RGPIO4 Channel 0 */
    kDmaRequestMux0HspRGPIO4Channel1 = 66|0x100U,  /**< HSP RGPIO4 Channel 1 */
    kDmaRequestMux0CommENET0Channel0 = 73|0x100U,  /**< COMM ENET QOS Request 0 */
    kDmaRequestMux0CommENET0Channel1 = 74|0x100U,  /**< COMM ENET QOS Request 1 */
    kDmaRequestMux0CommENET1Channel0 = 75|0x100U,  /**< COMM ENET Request 0 */
    kDmaRequestMux0CommENET1Channel1 = 76|0x100U,  /**< COMM ENET Request 1 */
} main_edma5_request_source_t;

/* @} */

/*!
 * @addtogroup edma1_request
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the DMA1 hardware request
 *
 * Defines the enumeration for the DMA1 hardware request collections.
 */
typedef enum _main_edma3_request_source
{
    kDmaRequestMux1MainXSPI0Rx      = 1|0x200U,    /**< MAIN XSPI0 Rx Buffer Drain Request */
    kDmaRequestMux1MainXSPI0Tx      = 2|0x200U,    /**< MAIN XSPI0 Tx Buffer Fill Request */
    kDmaRequestMux1MainXSPI1Rx      = 3|0x200U,    /**< MAIN XSPI1 Rx Buffer Drain Request */
    kDmaRequestMux1MainXSPI1Tx      = 4|0x200U,    /**< MAIN XSPI1 Tx Buffer Fill Request */
    kDmaRequestMux1HspXBAR0OUT0     = 10|0x200U,   /**< HSP XBAR_OUT0 Request */
    kDmaRequestMux1HspXBAR0OUT1     = 11|0x200U,   /**< HSP XBAR_OUT1 Request */
    kDmaRequestMux1HspXBAR0OUT2     = 12|0x200U,   /**< HSP XBAR_OUT2 Request */
    kDmaRequestMux1HspXBAR0OUT3     = 13|0x200U,   /**< HSP XBAR_OUT3 Request */
    kDmaRequestMux1HspXBAR0OUT4     = 14|0x200U,   /**< HSP XBAR_OUT4 Request */
    kDmaRequestMux1HspXBAR0OUT5     = 15|0x200U,   /**< HSP XBAR_OUT5 Request */
    kDmaRequestMux1HspXBAR0OUT6     = 16|0x200U,   /**< HSP XBAR_OUT6 Request */
    kDmaRequestMux1HspXBAR0OUT7     = 17|0x200U,   /**< HSP XBAR_OUT7 Request */
    kDmaRequestMux1HspADC0Channel0  = 18|0x200U,   /**< HSP ADC0 Fifo 0 Request */
    kDmaRequestMux1HspADC0Channel1  = 19|0x200U,   /**< HSP ADC0 Fifo 1 Request */
    kDmaRequestMux1HspADC1Channel0  = 20|0x200U,   /**< HSP ADC1 Fifo 0 Request */
    kDmaRequestMux1HspADC1Channel1  = 21|0x200U,   /**< HSP ADC1 Fifo 1 Request */
    kDmaRequestMux1HspDAC           = 22|0x200U,   /**< HSP DAC Fifo Request */
    kDmaRequestMux1HspEFLEXPWM0Capture0 = 23|0x200U, /**< HSP EFLEXPWM0 Read Request For Capture Registers Of Submodule 0 */
    kDmaRequestMux1HspEFLEXPWM0Capture1 = 24|0x200U, /**< HSP EFLEXPWM0 Read Request For Capture Registers Of Submodule 1 */
    kDmaRequestMux1HspEFLEXPWM0Capture2 = 25|0x200U, /**< HSP EFLEXPWM0 Read Request For Capture Registers Of Submodule 2 */
    kDmaRequestMux1HspEFLEXPWM0Capture3 = 26|0x200U, /**< HSP EFLEXPWM0 Read Request For Capture Registers Of Submodule 3 */
    kDmaRequestMux1HspEFLEXPWM0Value0 = 27|0x200U, /**< HSP EFLEXPWM0 Write Request For Value Registers Of Submodule 0 */
    kDmaRequestMux1HspEFLEXPWM0Value1 = 28|0x200U, /**< HSP EFLEXPWM0 Write Request For Value Registers Of Submodule 1 */
    kDmaRequestMux1HspEFLEXPWM0Value2 = 29|0x200U, /**< HSP EFLEXPWM0 Write Request For Value Registers Of Submodule 2 */
    kDmaRequestMux1HspEFLEXPWM0Value3 = 30|0x200U, /**< HSP EFLEXPWM0 Write Request For Value Registers Of Submodule 3 */
    kDmaRequestMux1HspEFLEXPWM1Capture0 = 31|0x200U, /**< HSP EFLEXPWM1 Read Request For Capture Registers Of Submodule 0 */
    kDmaRequestMux1HspEFLEXPWM1Capture1 = 32|0x200U, /**< HSP EFLEXPWM1 Read Request For Capture Registers Of Submodule 1 */
    kDmaRequestMux1HspEFLEXPWM1Capture2 = 33|0x200U, /**< HSP EFLEXPWM1 Read Request For Capture Registers Of Submodule 2 */
    kDmaRequestMux1HspEFLEXPWM1Capture3 = 34|0x200U, /**< HSP EFLEXPWM1 Read Request For Capture Registers Of Submodule 3 */
    kDmaRequestMux1HspEFLEXPWM1Value0 = 35|0x200U, /**< HSP EFLEXPWM1 Write Request For Value Registers Of Submodule 0 */
    kDmaRequestMux1HspEFLEXPWM1Value1 = 36|0x200U, /**< HSP EFLEXPWM1 Write Request For Value Registers Of Submodule 1 */
    kDmaRequestMux1HspEFLEXPWM1Value2 = 37|0x200U, /**< HSP EFLEXPWM1 Write Request For Value Registers Of Submodule 2 */
    kDmaRequestMux1HspEFLEXPWM1Value3 = 38|0x200U, /**< HSP EFLEXPWM1 Write Request For Value Registers Of Submodule 3 */
    kDmaRequestMux1HspEFLEXPWM2Capture0 = 39|0x200U, /**< HSP EFLEXPWM2 Read Request For Capture Registers Of Submodule 0 */
    kDmaRequestMux1HspEFLEXPWM2Capture1 = 40|0x200U, /**< HSP EFLEXPWM2 Read Request For Capture Registers Of Submodule 1 */
    kDmaRequestMux1HspEFLEXPWM2Capture2 = 41|0x200U, /**< HSP EFLEXPWM2 Read Request For Capture Registers Of Submodule 2 */
    kDmaRequestMux1HspEFLEXPWM2Capture3 = 42|0x200U, /**< HSP EFLEXPWM2 Read Request For Capture Registers Of Submodule 3 */
    kDmaRequestMux1HspEFLEXPWM2Value0 = 43|0x200U, /**< HSP EFLEXPWM2 Write Request For Value Registers Of Submodule 0 */
    kDmaRequestMux1HspEFLEXPWM2Value1 = 44|0x200U, /**< HSP EFLEXPWM2 Write Request For Value Registers Of Submodule 1 */
    kDmaRequestMux1HspEFLEXPWM2Value2 = 45|0x200U, /**< HSP EFLEXPWM2 Write Request For Value Registers Of Submodule 2 */
    kDmaRequestMux1HspEFLEXPWM2Value3 = 46|0x200U, /**< HSP EFLEXPWM2 Write Request For Value Registers Of Submodule 3 */
    kDmaRequestMux1HspEFLEXPWM3Capture0 = 47|0x200U, /**< HSP EFLEXPWM3 Read Request For Capture Registers Of Submodule 0 */
    kDmaRequestMux1HspEFLEXPWM3Capture1 = 48|0x200U, /**< HSP EFLEXPWM3 Read Request For Capture Registers Of Submodule 1 */
    kDmaRequestMux1HspEFLEXPWM3Capture2 = 49|0x200U, /**< HSP EFLEXPWM3 Read Request For Capture Registers Of Submodule 2 */
    kDmaRequestMux1HspEFLEXPWM3Capture3 = 50|0x200U, /**< HSP EFLEXPWM3 Read Request For Capture Registers Of Submodule 3 */
    kDmaRequestMux1HspEFLEXPWM3Value0 = 51|0x200U, /**< HSP EFLEXPWM3 Write Request For Value Registers Of Submodule 0 */
    kDmaRequestMux1HspEFLEXPWM3Value1 = 52|0x200U, /**< HSP EFLEXPWM3 Write Request For Value Registers Of Submodule 1 */
    kDmaRequestMux1HspEFLEXPWM3Value2 = 53|0x200U, /**< HSP EFLEXPWM3 Write Request For Value Registers Of Submodule 2 */
    kDmaRequestMux1HspEFLEXPWM3Value3 = 54|0x200U, /**< HSP EFLEXPWM3 Write Request For Value Registers Of Submodule 3 */
    kDmaRequestMux1HspQUADTPM0Count0 = 55|0x200U,  /**< HSP QUADTPM0 Counter 0 Overflow Request */
    kDmaRequestMux1HspQUADTPM0Count1 = 56|0x200U,  /**< HSP QUADTPM0 Counter 1 Overflow Request */
    kDmaRequestMux1HspQUADTPM0Count2 = 57|0x200U,  /**< HSP QUADTPM0 Counter 2 Overflow Request */
    kDmaRequestMux1HspQUADTPM0Count3 = 58|0x200U,  /**< HSP QUADTPM0 Counter 3 Overflow Request */
    kDmaRequestMux1HspQUADTPM0Channel02 = 59|0x200U, /**< HSP QUADTPM0 Channel 0/2 Overflow Request */
    kDmaRequestMux1HspQUADTPM0Channel13 = 60|0x200U, /**< HSP QUADTPM0 Channel 1/3 Overflow Request */
    kDmaRequestMux1HspQUADTPM0Channel46 = 61|0x200U, /**< HSP QUADTPM0 Channel 4/6 Overflow Request */
    kDmaRequestMux1HspQUADTPM0Channel57 = 62|0x200U, /**< HSP QUADTPM0 Channel 5/7 Overflow Request */
    kDmaRequestMux1HspQTMR0Channel0 = 79|0x200U,   /**< HSP QTMR0 Channel 0 Capture Request */
    kDmaRequestMux1HspQTMR0Channel1 = 80|0x200U,   /**< HSP QTMR0 Channel 1 Capture Request */
    kDmaRequestMux1HspQTMR0Channel2 = 81|0x200U,   /**< HSP QTMR0 Channel 2 Capture Request */
    kDmaRequestMux1HspQTMR0Channel3 = 82|0x200U,   /**< HSP QTMR0 Channel 3 Capture Request */
    kDmaRequestMux1HspQTMR0Channel0Load1 = 83|0x200U, /**< HSP QTMR0 Channel 0 Load Register 1 Request */
    kDmaRequestMux1HspQTMR0Channel0Load2 = 84|0x200U, /**< HSP QTMR0 Channel 0 Load Register 2 Request */
    kDmaRequestMux1HspQTMR0Channel2Load1 = 85|0x200U, /**< HSP QTMR0 Channel 2 Load Register 1 Request */
    kDmaRequestMux1HspQTMR0Channel2Load2 = 86|0x200U, /**< HSP QTMR0 Channel 2 Load Register 2 Request */
    kDmaRequestMux1HspQTMR1Channel0 = 87|0x200U,   /**< HSP QTMR1 Channel 0 Capture Request */
    kDmaRequestMux1HspQTMR1Channel1 = 88|0x200U,   /**< HSP QTMR1 Channel 1 Capture Request */
    kDmaRequestMux1HspQTMR1Channel2 = 89|0x200U,   /**< HSP QTMR1 Channel 2 Capture Request */
    kDmaRequestMux1HspQTMR1Channel3 = 90|0x200U,   /**< HSP QTMR1 Channel 3 Capture Request */
    kDmaRequestMux1HspQTMR1Channel0Load1 = 91|0x200U, /**< HSP QTMR1 Channel 0 Load Register 1 Request */
    kDmaRequestMux1HspQTMR1Channel0Load2 = 92|0x200U, /**< HSP QTMR1 Channel 0 Load Register 2 Request */
    kDmaRequestMux1HspQTMR1Channel2Load1 = 93|0x200U, /**< HSP QTMR1 Channel 2 Load Register 1 Request */
    kDmaRequestMux1HspQTMR1Channel2Load2 = 94|0x200U, /**< HSP QTMR1 Channel 2 Load Register 2 Request */
    kDmaRequestMux1HspQTMR2Channel0 = 95|0x200U,   /**< HSP QTMR2 Channel 0 Capture Request */
    kDmaRequestMux1HspQTMR2Channel1 = 96|0x200U,   /**< HSP QTMR2 Channel 1 Capture Request */
    kDmaRequestMux1HspQTMR2Channel2 = 97|0x200U,   /**< HSP QTMR2 Channel 2 Capture Request */
    kDmaRequestMux1HspQTMR2Channel3 = 98|0x200U,   /**< HSP QTMR2 Channel 3 Capture Request */
    kDmaRequestMux1HspQTMR2Channel0Load1 = 99|0x200U, /**< HSP QTMR2 Channel 0 Load Register 1 Request */
    kDmaRequestMux1HspQTMR2Channel0Load2 = 100|0x200U, /**< HSP QTMR2 Channel 0 Load Register 2 Request */
    kDmaRequestMux1HspQTMR2Channel2Load1 = 101|0x200U, /**< HSP QTMR2 Channel 2 Load Register 1 Request */
    kDmaRequestMux1HspQTMR2Channel2Load2 = 102|0x200U, /**< HSP QTMR2 Channel 2 Load Register 2 Request */
    kDmaRequestMux1HspQTMR3Channel0 = 103|0x200U,  /**< HSP QTMR3 Channel 0 Capture Request */
    kDmaRequestMux1HspQTMR3Channel1 = 104|0x200U,  /**< HSP QTMR3 Channel 1 Capture Request */
    kDmaRequestMux1HspQTMR3Channel2 = 105|0x200U,  /**< HSP QTMR3 Channel 2 Capture Request */
    kDmaRequestMux1HspQTMR3Channel3 = 106|0x200U,  /**< HSP QTMR3 Channel 3 Capture Request */
    kDmaRequestMux1HspQTMR3Channel0Load1 = 107|0x200U, /**< HSP QTMR3 Channel 0 Load Register 1 Request */
    kDmaRequestMux1HspQTMR3Channel0Load2 = 108|0x200U, /**< HSP QTMR3 Channel 0 Load Register 2 Request */
    kDmaRequestMux1HspQTMR3Channel2Load1 = 109|0x200U, /**< HSP QTMR3 Channel 2 Load Register 1 Request */
    kDmaRequestMux1HspQTMR3Channel2Load2 = 110|0x200U, /**< HSP QTMR3 Channel 2 Load Register 2 Request */
    kDmaRequestMux1HspEQDC0         = 111|0x200U,  /**< HSP EQDC0 Request Triggered By Loading Values From Outer- To Inner-Set Registers */
    kDmaRequestMux1HspEQDC1         = 112|0x200U,  /**< HSP EQDC1 Request Triggered By Loading Values From Outer- To Inner-Set Registers */
    kDmaRequestMux1HspEQDC2         = 113|0x200U,  /**< HSP EQDC2 Request Triggered By Loading Values From Outer- To Inner-Set Registers */
    kDmaRequestMux1HspEQDC3         = 114|0x200U,  /**< HSP EQDC3 Request Triggered By Loading Values From Outer- To Inner-Set Registers */
    kDmaRequestMux1HspSINC0Fifo0    = 115|0x200U,  /**< HSP SINC0 fifo0 */
    kDmaRequestMux1HspSINC0Alt0     = 116|0x200U,  /**< HSP SINC0 alt0 */
    kDmaRequestMux1HspSINC0Fifo1    = 117|0x200U,  /**< HSP SINC0 fifo1 */
    kDmaRequestMux1HspSINC0Alt1     = 118|0x200U,  /**< HSP SINC0 alt1 */
    kDmaRequestMux1HspSINC0Fifo2    = 119|0x200U,  /**< HSP SINC0 fifo2 */
    kDmaRequestMux1HspSINC0Alt2     = 120|0x200U,  /**< HSP SINC0 alt2 */
    kDmaRequestMux1HspSINC0Fifo3    = 121|0x200U,  /**< HSP SINC0 fifo3 */
    kDmaRequestMux1HspSINC0Alt3     = 122|0x200U,  /**< HSP SINC0 alt3 */
    kDmaRequestMux1HspSINC1Fifo0    = 123|0x200U,  /**< HSP SINC1 fifo0 */
    kDmaRequestMux1HspSINC1Alt0     = 124|0x200U,  /**< HSP SINC1 alt0 */
    kDmaRequestMux1HspSINC1Fifo1    = 125|0x200U,  /**< HSP SINC1 fifo1 */
    kDmaRequestMux1HspSINC1Alt1     = 126|0x200U,  /**< HSP SINC1 alt1 */
    kDmaRequestMux1HspSINC1Fifo2    = 127|0x200U,  /**< HSP SINC1 fifo2 */
    kDmaRequestMux1HspSINC1Alt2     = 128|0x200U,  /**< HSP SINC1 alt2 */
    kDmaRequestMux1HspSINC1Fifo3    = 129|0x200U,  /**< HSP SINC1 fifo3 */
    kDmaRequestMux1HspSINC1Alt3     = 130|0x200U,  /**< HSP SINC1 alt3 */
    kDmaRequestMux1HspFlexCAN0      = 131|0x200U,  /**< HSP FlexCAN0 */
    kDmaRequestMux1HspFlexCAN1      = 132|0x200U,  /**< HSP FlexCAN1 */
    kDmaRequestMux1HspFlexCAN2      = 133|0x200U,  /**< HSP FlexCAN2 */
    kDmaRequestMux1HspFlexIO0Request0Request8 = 134|0x200U, /**< HSP FlexIO0 Request 0 and Request 8 */
    kDmaRequestMux1HspFlexIO0Request1Request9 = 135|0x200U, /**< HSP FlexIO0 Request 1 and Request 9 */
    kDmaRequestMux1HspFlexIO0Request2Request10 = 136|0x200U, /**< HSP FlexIO0 Request 2 and Request 10 */
    kDmaRequestMux1HspFlexIO0Request3Request11 = 137|0x200U, /**< HSP FlexIO0 Request 3 and Request 11 */
    kDmaRequestMux1HspFlexIO0Request4Request12 = 138|0x200U, /**< HSP FlexIO0 Request 4 and Request 12 */
    kDmaRequestMux1HspFlexIO0Request5Request13 = 139|0x200U, /**< HSP FlexIO0 Request 5 and Request 13 */
    kDmaRequestMux1HspFlexIO0Request6Request14 = 140|0x200U, /**< HSP FlexIO0 Request 6 and Request 14 */
    kDmaRequestMux1HspFlexIO0Request7Request15 = 141|0x200U, /**< HSP FlexIO0 Request 7 and Request 15 */
    kDmaRequestMux1HspFlexIO1Request0Request8 = 142|0x200U, /**< HSP FlexIO0 Request 0 and Request 8 */
    kDmaRequestMux1HspFlexIO1Request1Request9 = 143|0x200U, /**< HSP FlexIO0 Request 1 and Request 9 */
    kDmaRequestMux1HspFlexIO1Request2Request10 = 144|0x200U, /**< HSP FlexIO0 Request 2 and Request 10 */
    kDmaRequestMux1HspFlexIO1Request3Request11 = 145|0x200U, /**< HSP FlexIO0 Request 3 and Request 11 */
    kDmaRequestMux1HspFlexIO1Request4Request12 = 146|0x200U, /**< HSP FlexIO0 Request 4 and Request 12 */
    kDmaRequestMux1HspFlexIO1Request5Request13 = 147|0x200U, /**< HSP FlexIO0 Request 5 and Request 13 */
    kDmaRequestMux1HspFlexIO1Request6Request14 = 148|0x200U, /**< HSP FlexIO0 Request 6 and Request 14 */
    kDmaRequestMux1HspFlexIO1Request7Request15 = 149|0x200U, /**< HSP FlexIO0 Request 7 and Request 15 */
    kDmaRequestMux1HspFlexIO2Request0Request8 = 150|0x200U, /**< HSP FlexIO0 Request 0 and Request 8 */
    kDmaRequestMux1HspFlexIO2Request1Request9 = 151|0x200U, /**< HSP FlexIO0 Request 1 and Request 9 */
    kDmaRequestMux1HspFlexIO2Request2Request10 = 152|0x200U, /**< HSP FlexIO0 Request 2 and Request 10 */
    kDmaRequestMux1HspFlexIO2Request3Request11 = 153|0x200U, /**< HSP FlexIO0 Request 3 and Request 11 */
    kDmaRequestMux1HspFlexIO2Request4Request12 = 154|0x200U, /**< HSP FlexIO0 Request 4 and Request 12 */
    kDmaRequestMux1HspFlexIO2Request5Request13 = 155|0x200U, /**< HSP FlexIO0 Request 5 and Request 13 */
    kDmaRequestMux1HspFlexIO2Request6Request14 = 156|0x200U, /**< HSP FlexIO0 Request 6 and Request 14 */
    kDmaRequestMux1HspFlexIO2Request7Request15 = 157|0x200U, /**< HSP FlexIO0 Request 7 and Request 15 */
    kDmaRequestMux1HspI3CFromBus    = 158|0x200U,  /**< HSP I3C From-bus DMA Request */
    kDmaRequestMux1HspI3CToBus      = 159|0x200U,  /**< HSP I3C to-bus DMA Request */
    kDmaRequestMux1HspLPI2C0Tx      = 161|0x200U,  /**< HSP LPI2C0 Master/Slave Transmit */
    kDmaRequestMux1HspLPI2C0Rx      = 162|0x200U,  /**< HSP LPI2C0 Master/Slave Receive */
    kDmaRequestMux1HspLPI2C1Tx      = 163|0x200U,  /**< HSP LPI2C1 Master/Slave Transmit */
    kDmaRequestMux1HspLPI2C1Rx      = 164|0x200U,  /**< HSP LPI2C1 Master/Slave Receive */
    kDmaRequestMux1HspLPSPI0Tx      = 169|0x200U,  /**< HSP LPSPI0 Master/Slave Transmit */
    kDmaRequestMux1HspLPSPI0Rx      = 170|0x200U,  /**< HSP LPSPI0 Master/Slave Receive */
    kDmaRequestMux1HspLPSPI1Tx      = 171|0x200U,  /**< HSP LPSPI1 Master/Slave Transmit */
    kDmaRequestMux1HspLPSPI1Rx      = 172|0x200U,  /**< HSP LPSPI1 Master/Slave Receive */
    kDmaRequestMux1HspLPSPI2Tx      = 173|0x200U,  /**< HSP LPSPI2 Master/Slave Transmit */
    kDmaRequestMux1HspLPSPI2Rx      = 174|0x200U,  /**< HSP LPSPI2 Master/Slave Receive */
    kDmaRequestMux1HspLPSPI3Tx      = 175|0x200U,  /**< HSP LPSPI3 Master/Slave Transmit */
    kDmaRequestMux1HspLPSPI3Rx      = 176|0x200U,  /**< HSP LPSPI3 Master/Slave Receive */
    kDmaRequestMux1HspLPSPI4Tx      = 177|0x200U,  /**< HSP LPSPI4 Master/Slave Transmit */
    kDmaRequestMux1HspLPSPI4Rx      = 178|0x200U,  /**< HSP LPSPI4 Master/Slave Receive */
    kDmaRequestMux1HspLPUART0Tx     = 179|0x200U,  /**< HSP LPLPUART0 Master/Slave Transmit */
    kDmaRequestMux1HspLPUART0Rx     = 180|0x200U,  /**< HSP LPLPUART0 Master/Slave Receive */
    kDmaRequestMux1HspLPUART1Tx     = 181|0x200U,  /**< HSP LPLPUART1 Master/Slave Transmit */
    kDmaRequestMux1HspLPUART1Rx     = 182|0x200U,  /**< HSP LPLPUART1 Master/Slave Receive */
    kDmaRequestMux1HspLPUART2Tx     = 183|0x200U,  /**< HSP LPLPUART2 Master/Slave Transmit */
    kDmaRequestMux1HspLPUART2Rx     = 184|0x200U,  /**< HSP LPLPUART2 Master/Slave Receive */
    kDmaRequestMux1HspLPUART3Tx     = 185|0x200U,  /**< HSP LPLPUART3 Master/Slave Transmit */
    kDmaRequestMux1HspLPUART3Rx     = 186|0x200U,  /**< HSP LPLPUART3 Master/Slave Receive */
    kDmaRequestMux1HspLPUART4Tx     = 187|0x200U,  /**< HSP LPLPUART4 Master/Slave Transmit */
    kDmaRequestMux1HspLPUART4Rx     = 188|0x200U,  /**< HSP LPLPUART4 Master/Slave Receive */
    kDmaRequestMux1HspLPUART5Tx     = 189|0x200U,  /**< HSP LPLPUART5 Master/Slave Transmit */
    kDmaRequestMux1HspLPUART5Rx     = 190|0x200U,  /**< HSP LPLPUART5 Master/Slave Receive */
    kDmaRequestMux1HspRGPIO0Channel0 = 191|0x200U, /**< HSP RGPIO0 Channel 0 */
    kDmaRequestMux1HspRGPIO0Channel1 = 192|0x200U, /**< HSP RGPIO0 Channel 1 */
    kDmaRequestMux1HspRGPIO1Channel0 = 193|0x200U, /**< HSP RGPIO1 Channel 0 */
    kDmaRequestMux1HspRGPIO1Channel1 = 194|0x200U, /**< HSP RGPIO1 Channel 1 */
    kDmaRequestMux1HspRGPIO2Channel0 = 195|0x200U, /**< HSP RGPIO2 Channel 0 */
    kDmaRequestMux1HspRGPIO2Channel1 = 196|0x200U, /**< HSP RGPIO2 Channel 1 */
    kDmaRequestMux1HspRGPIO3Channel0 = 197|0x200U, /**< HSP RGPIO3 Channel 0 */
    kDmaRequestMux1HspRGPIO3Channel1 = 198|0x200U, /**< HSP RGPIO3 Channel 1 */
    kDmaRequestMux1HspRGPIO4Channel0 = 199|0x200U, /**< HSP RGPIO4 Channel 0 */
    kDmaRequestMux1HspRGPIO4Channel1 = 200|0x200U, /**< HSP RGPIO4 Channel 1 */
} main_edma3_request_source_t;

/* @} */

/*!
 * @addtogroup edma2_request
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the DMA2 hardware request
 *
 * Defines the enumeration for the DMA2 hardware request collections.
 */
typedef enum _audio_edma3_request_source
{
    kDmaRequestMux2AudioMic         = 1|0x300U,    /**< AUDIO MICFIL Request */
    kDmaRequestMux2AudioSAI0Tx      = 3|0x300U,    /**< AUDIO SAI0 Tx Request */
    kDmaRequestMux2AudioSAI0Rx      = 4|0x300U,    /**< AUDIO SAI0 Rx Request */
    kDmaRequestMux2AudioSAI1Tx      = 5|0x300U,    /**< AUDIO SAI1 Tx Request */
    kDmaRequestMux2AudioSAI1Rx      = 6|0x300U,    /**< AUDIO SAI1 Rx Request */
    kDmaRequestMux2AudioSAI2Tx      = 7|0x300U,    /**< AUDIO SAI2 Tx Request */
    kDmaRequestMux2AudioSAI2Rx      = 8|0x300U,    /**< AUDIO SAI2 Rx Request */
    kDmaRequestMux2AudioSpdifRx     = 15|0x300U,   /**< AUDIO SPDIF Rx Request */
    kDmaRequestMux2AudioSpdifTx     = 16|0x300U,   /**< AUDIO SPDIF Tx Request */
    kDmaRequestMux2AudioAsrcPairAInput = 17|0x300U, /**< AUDIO ASRC PairA input Request */
    kDmaRequestMux2AudioAsrcPairBInput = 18|0x300U, /**< AUDIO ASRC PairB input Request */
    kDmaRequestMux2AudioAsrcPairCInput = 19|0x300U, /**< AUDIO ASRC PairC input Request */
    kDmaRequestMux2AudioAsrcPairAOutput = 20|0x300U, /**< AUDIO ASRC PairA Output Request */
    kDmaRequestMux2AudioAsrcPairBOutput = 21|0x300U, /**< AUDIO ASRC PairB Output Request */
    kDmaRequestMux2AudioAsrcPairCOutput = 22|0x300U, /**< AUDIO ASRC PairC Output Request */
} audio_edma3_request_source_t;

/* @} */

/*!
 * @addtogroup edma3_request
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the DMA3 hardware request
 *
 * Defines the enumeration for the DMA3 hardware request collections.
 */
typedef enum _wake_edma3_request_source
{
    kDmaRequestMux3WakeXbarOut0     = 1|0x400U,    /**< WAKE XBAR OUT0 Request */
    kDmaRequestMux3WakeXbarOut1     = 2|0x400U,    /**< WAKE XBAR OUT1 Request */
    kDmaRequestMux3WakeCMP0         = 3|0x400U,    /**< WAKE ACMP0 Request */
    kDmaRequestMux3WakeCMP1         = 4|0x400U,    /**< WAKE ACMP1 Request */
    kDmaRequestMux3WakeCMP2         = 5|0x400U,    /**< WAKE ACMP2 Request */
    kDmaRequestMux3WakeCMP3         = 6|0x400U,    /**< WAKE ACMP3 Request */
    kDmaRequestMux3WakeLPTMR0       = 7|0x400U,    /**< WAKE LPTMR0 Request */
    kDmaRequestMux3WakeLPTMR1       = 8|0x400U,    /**< WAKE LPTMR1 Request */
    kDmaRequestMux3WakeQUADTPMCount0 = 9|0x400U,   /**< WAKE QUADTPM Counter 0 Overflow Request */
    kDmaRequestMux3WakeQUADTPMCount1 = 10|0x400U,  /**< WAKE QUADTPM Counter 1 Overflow Request */
    kDmaRequestMux3WakeQUADTPMCount2 = 11|0x400U,  /**< WAKE QUADTPM Counter 2 Overflow Request */
    kDmaRequestMux3WakeQUADTPMCount3 = 12|0x400U,  /**< WAKE QUADTPM Counter 3 Overflow Request */
    kDmaRequestMux3WakeQUADTPMChannel02 = 13|0x400U, /**< WAKE QUADTPM Channel 0/2 Overflow Request */
    kDmaRequestMux3WakeQUADTPMChannel13 = 14|0x400U, /**< WAKE QUADTPM Channel 1/3 Overflow Request */
    kDmaRequestMux3WakeQUADTPMChannel46 = 15|0x400U, /**< WAKE QUADTPM Channel 4/6 Overflow Request */
    kDmaRequestMux3WakeQUADTPMChannel57 = 16|0x400U, /**< WAKE QUADTPM Channel 5/7 Overflow Request */
    kDmaRequestMux3WakeI3CFromBus   = 17|0x400U,   /**< WAKE I3C From-bus DMA Request */
    kDmaRequestMux3WakeI3CToBus     = 18|0x400U,   /**< WAKE I3C to-bus DMA Request */
    kDmaRequestMux3WakeLPI2C0Tx     = 20|0x400U,   /**< WAKE LPI2C0 Master/Slave Transmit */
    kDmaRequestMux3WakeLPI2C0Rx     = 21|0x400U,   /**< WAKE LPI2C0 Master/Slave Receive */
    kDmaRequestMux3WakeLPI2C1Tx     = 22|0x400U,   /**< WAKE LPI2C1 Master/Slave Transmit */
    kDmaRequestMux3WakeLPI2C1Rx     = 23|0x400U,   /**< WAKE LPI2C1 Master/Slave Receive */
    kDmaRequestMux3WakeLPSPITx      = 24|0x400U,   /**< WAKE LPSPI Master/Slave Transmit */
    kDmaRequestMux3WakeLPSPIRx      = 25|0x400U,   /**< WAKE LPSPI Master/Slave Receive */
    kDmaRequestMux3WakeLPUART0Tx    = 26|0x400U,   /**< WAKE LPLPUART0 Master/Slave Transmit */
    kDmaRequestMux3WakeLPUART0Rx    = 27|0x400U,   /**< WAKE LPLPUART0 Master/Slave Receive */
    kDmaRequestMux3WakeLPUART1Tx    = 28|0x400U,   /**< WAKE LPLPUART1 Master/Slave Transmit */
    kDmaRequestMux3WakeLPUART1Rx    = 29|0x400U,   /**< WAKE LPLPUART1 Master/Slave Receive */
    kDmaRequestMux3WakeRGPIOChannel0 = 30|0x400U,  /**< WAKE RGPIO Channel 0 */
    kDmaRequestMux3WakeRGPIOChannel1 = 31|0x400U,  /**< WAKE RGPIO Channel 1 */
    kDmaRequestMux3WakeMic          = 32|0x400U,   /**< WAKE MICFIL Request */
    kDmaRequestMux3VbatLPTMR        = 35|0x400U,   /**< VBAT LPTMR Request */
    kDmaRequestMux3VbatLrRGPIOChannel0 = 36|0x400U, /**< VBAT RGPIO Channel 0 */
    kDmaRequestMux3VbatLrRGPIOChannel1 = 37|0x400U, /**< VBAT RGPIO Channel 1 */
} wake_edma3_request_source_t;

/* @} */

typedef enum _xbar_input_signal
{
    kAUDIO__XBAR_InputLogicLow      = 0|0x10000U,  /**< LOGIC_LOW output assigned to AUDIO_XBAR_IN0 input. */
    kAUDIO__XBAR_InputLogicHigh     = 1|0x10000U,  /**< LOGIC_HIGH output assigned to AUDIO_XBAR_IN1 input. */
    kAUDIO__XBAR_InputAudioEdmaTrigOut0 = 2|0x10000U, /**< AUDIO_EDMA_TRIG_OUT0 output assigned to AUDIO_XBAR_IN2 input. */
    kAUDIO__XBAR_InputRESERVED3     = 3|0x10000U,  /**< AUDIO_XBAR_IN3 input is reserved. */
    kAUDIO__XBAR_InputAudioEdmaIdle = 4|0x10000U,  /**< AUDIO_EDMA_IDLE output assigned to AUDIO_XBAR_IN4 input. */
    kAUDIO__XBAR_InputAudioSai0TxBclk = 5|0x10000U, /**< AUDIO_SAI0_TX_BCLK output assigned to AUDIO_XBAR_IN5 input. */
    kAUDIO__XBAR_InputAudioSai0RxBclk = 6|0x10000U, /**< AUDIO_SAI0_RX_BCLK output assigned to AUDIO_XBAR_IN6 input. */
    kAUDIO__XBAR_InputAudioSai0TxSync = 7|0x10000U, /**< AUDIO_SAI0_TX_SYNC output assigned to AUDIO_XBAR_IN7 input. */
    kAUDIO__XBAR_InputAudioSai0RxSync = 8|0x10000U, /**< AUDIO_SAI0_RX_SYNC output assigned to AUDIO_XBAR_IN8 input. */
    kAUDIO__XBAR_InputAudioSai1TxBclk = 9|0x10000U, /**< AUDIO_SAI1_TX_BCLK output assigned to AUDIO_XBAR_IN9 input. */
    kAUDIO__XBAR_InputAudioSai1RxBclk = 10|0x10000U, /**< AUDIO_SAI1_RX_BCLK output assigned to AUDIO_XBAR_IN10 input. */
    kAUDIO__XBAR_InputAudioSai1TxSync = 11|0x10000U, /**< AUDIO_SAI1_TX_SYNC output assigned to AUDIO_XBAR_IN11 input. */
    kAUDIO__XBAR_InputAudioSai1RxSync = 12|0x10000U, /**< AUDIO_SAI1_RX_SYNC output assigned to AUDIO_XBAR_IN12 input. */
    kAUDIO__XBAR_InputAudioSai2TxBclk = 13|0x10000U, /**< AUDIO_SAI2_TX_BCLK output assigned to AUDIO_XBAR_IN13 input. */
    kAUDIO__XBAR_InputAudioSai2RxBclk = 14|0x10000U, /**< AUDIO_SAI2_RX_BCLK output assigned to AUDIO_XBAR_IN14 input. */
    kAUDIO__XBAR_InputAudioSai2TxSync = 15|0x10000U, /**< AUDIO_SAI2_TX_SYNC output assigned to AUDIO_XBAR_IN15 input. */
    kAUDIO__XBAR_InputAudioSai2RxSync = 16|0x10000U, /**< AUDIO_SAI2_RX_SYNC output assigned to AUDIO_XBAR_IN16 input. */
    kAUDIO__XBAR_InputRESERVED17    = 17|0x10000U, /**< AUDIO_XBAR_IN17 input is reserved. */
    kAUDIO__XBAR_InputRESERVED18    = 18|0x10000U, /**< AUDIO_XBAR_IN18 input is reserved. */
    kAUDIO__XBAR_InputRESERVED19    = 19|0x10000U, /**< AUDIO_XBAR_IN19 input is reserved. */
    kAUDIO__XBAR_InputRESERVED20    = 20|0x10000U, /**< AUDIO_XBAR_IN20 input is reserved. */
    kAUDIO__XBAR_InputRESERVED21    = 21|0x10000U, /**< AUDIO_XBAR_IN21 input is reserved. */
    kAUDIO__XBAR_InputRESERVED22    = 22|0x10000U, /**< AUDIO_XBAR_IN22 input is reserved. */
    kAUDIO__XBAR_InputRESERVED23    = 23|0x10000U, /**< AUDIO_XBAR_IN23 input is reserved. */
    kAUDIO__XBAR_InputRESERVED24    = 24|0x10000U, /**< AUDIO_XBAR_IN24 input is reserved. */
    kAUDIO__XBAR_InputRESERVED25    = 25|0x10000U, /**< AUDIO_XBAR_IN25 input is reserved. */
    kAUDIO__XBAR_InputRESERVED26    = 26|0x10000U, /**< AUDIO_XBAR_IN26 input is reserved. */
    kAUDIO__XBAR_InputRESERVED27    = 27|0x10000U, /**< AUDIO_XBAR_IN27 input is reserved. */
    kAUDIO__XBAR_InputRESERVED28    = 28|0x10000U, /**< AUDIO_XBAR_IN28 input is reserved. */
    kAUDIO__XBAR_InputAudioSpdifRecClk = 29|0x10000U, /**< AUDIO_SPDIF_REC_CLK output assigned to AUDIO_XBAR_IN29 input. */
    kAUDIO__XBAR_InputAudioMicfilMicFilter = 30|0x10000U, /**< AUDIO_MICFIL_MIC_FILTER output assigned to AUDIO_XBAR_IN30 input. */
    kAUDIO__XBAR_InputRESERVED31    = 31|0x10000U, /**< AUDIO_XBAR_IN31 input is reserved. */
    kAUDIO__XBAR_InputRESERVED32    = 32|0x10000U, /**< AUDIO_XBAR_IN32 input is reserved. */
    kAUDIO__XBAR_InputRESERVED33    = 33|0x10000U, /**< AUDIO_XBAR_IN33 input is reserved. */
    kAUDIO__XBAR_InputRESERVED34    = 34|0x10000U, /**< AUDIO_XBAR_IN34 input is reserved. */
    kAUDIO__XBAR_InputRESERVED35    = 35|0x10000U, /**< AUDIO_XBAR_IN35 input is reserved. */
    kAUDIO__XBAR_InputRESERVED36    = 36|0x10000U, /**< AUDIO_XBAR_IN36 input is reserved. */
    kAUDIO__XBAR_InputRESERVED37    = 37|0x10000U, /**< AUDIO_XBAR_IN37 input is reserved. */
    kAUDIO__XBAR_InputRESERVED38    = 38|0x10000U, /**< AUDIO_XBAR_IN38 input is reserved. */
    kAUDIO__XBAR_InputRESERVED39    = 39|0x10000U, /**< AUDIO_XBAR_IN39 input is reserved. */
    kAUDIO__XBAR_InputRESERVED40    = 40|0x10000U, /**< AUDIO_XBAR_IN40 input is reserved. */
    kAUDIO__XBAR_InputRESERVED41    = 41|0x10000U, /**< AUDIO_XBAR_IN41 input is reserved. */
    kAUDIO__XBAR_InputRESERVED42    = 42|0x10000U, /**< AUDIO_XBAR_IN42 input is reserved. */
    kHSP__XBAR_0_InputLogicLow      = 0|0x20000U,  /**< LOGIC_LOW output assigned to HSP_XBAR_0_IN0 input. */
    kHSP__XBAR_0_InputLogicHigh     = 1|0x20000U,  /**< LOGIC_HIGH output assigned to HSP_XBAR_0_IN1 input. */
    kHSP__XBAR_0_InputHspXbar2Out0  = 2|0x20000U,  /**< HSP_XBAR2_OUT0 output assigned to HSP_XBAR_0_IN2 input. */
    kHSP__XBAR_0_InputHspXbar2Out1  = 3|0x20000U,  /**< HSP_XBAR2_OUT1 output assigned to HSP_XBAR_0_IN3 input. */
    kHSP__XBAR_0_InputHspXbar2Out2  = 4|0x20000U,  /**< HSP_XBAR2_OUT2 output assigned to HSP_XBAR_0_IN4 input. */
    kHSP__XBAR_0_InputHspXbar2Out3  = 5|0x20000U,  /**< HSP_XBAR2_OUT3 output assigned to HSP_XBAR_0_IN5 input. */
    kHSP__XBAR_0_InputHspXbar2Out4  = 6|0x20000U,  /**< HSP_XBAR2_OUT4 output assigned to HSP_XBAR_0_IN6 input. */
    kHSP__XBAR_0_InputHspXbar2Out5  = 7|0x20000U,  /**< HSP_XBAR2_OUT5 output assigned to HSP_XBAR_0_IN7 input. */
    kHSP__XBAR_0_InputHspXbar2Out6  = 8|0x20000U,  /**< HSP_XBAR2_OUT6 output assigned to HSP_XBAR_0_IN8 input. */
    kHSP__XBAR_0_InputHspXbar2Out7  = 9|0x20000U,  /**< HSP_XBAR2_OUT7 output assigned to HSP_XBAR_0_IN9 input. */
    kHSP__XBAR_0_InputHspXbar2Out8  = 10|0x20000U, /**< HSP_XBAR2_OUT8 output assigned to HSP_XBAR_0_IN10 input. */
    kHSP__XBAR_0_InputHspXbar2Out9  = 11|0x20000U, /**< HSP_XBAR2_OUT9 output assigned to HSP_XBAR_0_IN11 input. */
    kHSP__XBAR_0_InputHspXbar2Out10 = 12|0x20000U, /**< HSP_XBAR2_OUT10 output assigned to HSP_XBAR_0_IN12 input. */
    kHSP__XBAR_0_InputHspXbar2Out11 = 13|0x20000U, /**< HSP_XBAR2_OUT11 output assigned to HSP_XBAR_0_IN13 input. */
    kHSP__XBAR_0_InputHspXbar2Out12 = 14|0x20000U, /**< HSP_XBAR2_OUT12 output assigned to HSP_XBAR_0_IN14 input. */
    kHSP__XBAR_0_InputHspXbar2Out13 = 15|0x20000U, /**< HSP_XBAR2_OUT13 output assigned to HSP_XBAR_0_IN15 input. */
    kHSP__XBAR_0_InputHspXbar2Out14 = 16|0x20000U, /**< HSP_XBAR2_OUT14 output assigned to HSP_XBAR_0_IN16 input. */
    kHSP__XBAR_0_InputHspXbar2Out15 = 17|0x20000U, /**< HSP_XBAR2_OUT15 output assigned to HSP_XBAR_0_IN17 input. */
    kHSP__XBAR_0_InputHspXbar2Out16 = 18|0x20000U, /**< HSP_XBAR2_OUT16 output assigned to HSP_XBAR_0_IN18 input. */
    kHSP__XBAR_0_InputHspXbar2Out17 = 19|0x20000U, /**< HSP_XBAR2_OUT17 output assigned to HSP_XBAR_0_IN19 input. */
    kHSP__XBAR_0_InputHspXbar2Out18 = 20|0x20000U, /**< HSP_XBAR2_OUT18 output assigned to HSP_XBAR_0_IN20 input. */
    kHSP__XBAR_0_InputHspXbar2Out19 = 21|0x20000U, /**< HSP_XBAR2_OUT19 output assigned to HSP_XBAR_0_IN21 input. */
    kHSP__XBAR_0_InputHspXbar2Out20 = 22|0x20000U, /**< HSP_XBAR2_OUT20 output assigned to HSP_XBAR_0_IN22 input. */
    kHSP__XBAR_0_InputHspXbar2Out21 = 23|0x20000U, /**< HSP_XBAR2_OUT21 output assigned to HSP_XBAR_0_IN23 input. */
    kHSP__XBAR_0_InputHspXbar2Out22 = 24|0x20000U, /**< HSP_XBAR2_OUT22 output assigned to HSP_XBAR_0_IN24 input. */
    kHSP__XBAR_0_InputHspXbar2Out23 = 25|0x20000U, /**< HSP_XBAR2_OUT23 output assigned to HSP_XBAR_0_IN25 input. */
    kHSP__XBAR_0_InputHspXbar2Out24 = 26|0x20000U, /**< HSP_XBAR2_OUT24 output assigned to HSP_XBAR_0_IN26 input. */
    kHSP__XBAR_0_InputHspXbar2Out25 = 27|0x20000U, /**< HSP_XBAR2_OUT25 output assigned to HSP_XBAR_0_IN27 input. */
    kHSP__XBAR_0_InputHspXbar2Out26 = 28|0x20000U, /**< HSP_XBAR2_OUT26 output assigned to HSP_XBAR_0_IN28 input. */
    kHSP__XBAR_0_InputHspXbar2Out27 = 29|0x20000U, /**< HSP_XBAR2_OUT27 output assigned to HSP_XBAR_0_IN29 input. */
    kHSP__XBAR_0_InputHspXbar2Out28 = 30|0x20000U, /**< HSP_XBAR2_OUT28 output assigned to HSP_XBAR_0_IN30 input. */
    kHSP__XBAR_0_InputHspXbar2Out29 = 31|0x20000U, /**< HSP_XBAR2_OUT29 output assigned to HSP_XBAR_0_IN31 input. */
    kHSP__XBAR_0_InputHspXbar2Out30 = 32|0x20000U, /**< HSP_XBAR2_OUT30 output assigned to HSP_XBAR_0_IN32 input. */
    kHSP__XBAR_0_InputHspXbar2Out31 = 33|0x20000U, /**< HSP_XBAR2_OUT31 output assigned to HSP_XBAR_0_IN33 input. */
    kHSP__XBAR_0_InputHspXbar2Out32 = 34|0x20000U, /**< HSP_XBAR2_OUT32 output assigned to HSP_XBAR_0_IN34 input. */
    kHSP__XBAR_0_InputHspXbar2Out33 = 35|0x20000U, /**< HSP_XBAR2_OUT33 output assigned to HSP_XBAR_0_IN35 input. */
    kHSP__XBAR_0_InputHspXbar2Out34 = 36|0x20000U, /**< HSP_XBAR2_OUT34 output assigned to HSP_XBAR_0_IN36 input. */
    kHSP__XBAR_0_InputHspXbar2Out35 = 37|0x20000U, /**< HSP_XBAR2_OUT35 output assigned to HSP_XBAR_0_IN37 input. */
    kHSP__XBAR_0_InputHspXbar2Out36 = 38|0x20000U, /**< HSP_XBAR2_OUT36 output assigned to HSP_XBAR_0_IN38 input. */
    kHSP__XBAR_0_InputHspXbar2Out37 = 39|0x20000U, /**< HSP_XBAR2_OUT37 output assigned to HSP_XBAR_0_IN39 input. */
    kHSP__XBAR_0_InputHspXbar2Out38 = 40|0x20000U, /**< HSP_XBAR2_OUT38 output assigned to HSP_XBAR_0_IN40 input. */
    kHSP__XBAR_0_InputHspXbar2Out39 = 41|0x20000U, /**< HSP_XBAR2_OUT39 output assigned to HSP_XBAR_0_IN41 input. */
    kHSP__XBAR_0_InputHspEvtg0Outa0 = 42|0x20000U, /**< HSP_EVTG0_OUTA0 output assigned to HSP_XBAR_0_IN42 input. */
    kHSP__XBAR_0_InputHspEvtg0Outb0 = 43|0x20000U, /**< HSP_EVTG0_OUTB0 output assigned to HSP_XBAR_0_IN43 input. */
    kHSP__XBAR_0_InputHspEvtg0Outa1 = 44|0x20000U, /**< HSP_EVTG0_OUTA1 output assigned to HSP_XBAR_0_IN44 input. */
    kHSP__XBAR_0_InputHspEvtg0Outb1 = 45|0x20000U, /**< HSP_EVTG0_OUTB1 output assigned to HSP_XBAR_0_IN45 input. */
    kHSP__XBAR_0_InputHspEvtg0Outa2 = 46|0x20000U, /**< HSP_EVTG0_OUTA2 output assigned to HSP_XBAR_0_IN46 input. */
    kHSP__XBAR_0_InputHspEvtg0Outb2 = 47|0x20000U, /**< HSP_EVTG0_OUTB2 output assigned to HSP_XBAR_0_IN47 input. */
    kHSP__XBAR_0_InputHspEvtg0Outa3 = 48|0x20000U, /**< HSP_EVTG0_OUTA3 output assigned to HSP_XBAR_0_IN48 input. */
    kHSP__XBAR_0_InputHspEvtg0Outb3 = 49|0x20000U, /**< HSP_EVTG0_OUTB3 output assigned to HSP_XBAR_0_IN49 input. */
    kHSP__XBAR_0_InputHspEvtg1Outa0 = 50|0x20000U, /**< HSP_EVTG1_OUTA0 output assigned to HSP_XBAR_0_IN50 input. */
    kHSP__XBAR_0_InputHspEvtg1Outb0 = 51|0x20000U, /**< HSP_EVTG1_OUTB0 output assigned to HSP_XBAR_0_IN51 input. */
    kHSP__XBAR_0_InputHspEvtg1Outa1 = 52|0x20000U, /**< HSP_EVTG1_OUTA1 output assigned to HSP_XBAR_0_IN52 input. */
    kHSP__XBAR_0_InputHspEvtg1Outb1 = 53|0x20000U, /**< HSP_EVTG1_OUTB1 output assigned to HSP_XBAR_0_IN53 input. */
    kHSP__XBAR_0_InputHspEvtg1Outa2 = 54|0x20000U, /**< HSP_EVTG1_OUTA2 output assigned to HSP_XBAR_0_IN54 input. */
    kHSP__XBAR_0_InputHspEvtg1Outb2 = 55|0x20000U, /**< HSP_EVTG1_OUTB2 output assigned to HSP_XBAR_0_IN55 input. */
    kHSP__XBAR_0_InputHspEvtg1Outa3 = 56|0x20000U, /**< HSP_EVTG1_OUTA3 output assigned to HSP_XBAR_0_IN56 input. */
    kHSP__XBAR_0_InputHspEvtg1Outb3 = 57|0x20000U, /**< HSP_EVTG1_OUTB3 output assigned to HSP_XBAR_0_IN57 input. */
    kHSP__XBAR_0_InputHspEvtg2Outa0 = 58|0x20000U, /**< HSP_EVTG2_OUTA0 output assigned to HSP_XBAR_0_IN58 input. */
    kHSP__XBAR_0_InputHspEvtg2Outb0 = 59|0x20000U, /**< HSP_EVTG2_OUTB0 output assigned to HSP_XBAR_0_IN59 input. */
    kHSP__XBAR_0_InputHspEvtg2Outa1 = 60|0x20000U, /**< HSP_EVTG2_OUTA1 output assigned to HSP_XBAR_0_IN60 input. */
    kHSP__XBAR_0_InputHspEvtg2Outb1 = 61|0x20000U, /**< HSP_EVTG2_OUTB1 output assigned to HSP_XBAR_0_IN61 input. */
    kHSP__XBAR_0_InputHspEvtg2Outa2 = 62|0x20000U, /**< HSP_EVTG2_OUTA2 output assigned to HSP_XBAR_0_IN62 input. */
    kHSP__XBAR_0_InputHspEvtg2Outb2 = 63|0x20000U, /**< HSP_EVTG2_OUTB2 output assigned to HSP_XBAR_0_IN63 input. */
    kHSP__XBAR_0_InputHspEvtg2Outa3 = 64|0x20000U, /**< HSP_EVTG2_OUTA3 output assigned to HSP_XBAR_0_IN64 input. */
    kHSP__XBAR_0_InputHspEvtg2Outb3 = 65|0x20000U, /**< HSP_EVTG2_OUTB3 output assigned to HSP_XBAR_0_IN65 input. */
    kHSP__XBAR_0_InputHspEvtg3Outa0 = 66|0x20000U, /**< HSP_EVTG3_OUTA0 output assigned to HSP_XBAR_0_IN66 input. */
    kHSP__XBAR_0_InputHspEvtg3Outb0 = 67|0x20000U, /**< HSP_EVTG3_OUTB0 output assigned to HSP_XBAR_0_IN67 input. */
    kHSP__XBAR_0_InputHspEvtg3Outa1 = 68|0x20000U, /**< HSP_EVTG3_OUTA1 output assigned to HSP_XBAR_0_IN68 input. */
    kHSP__XBAR_0_InputHspEvtg3Outb1 = 69|0x20000U, /**< HSP_EVTG3_OUTB1 output assigned to HSP_XBAR_0_IN69 input. */
    kHSP__XBAR_0_InputHspEvtg3Outa2 = 70|0x20000U, /**< HSP_EVTG3_OUTA2 output assigned to HSP_XBAR_0_IN70 input. */
    kHSP__XBAR_0_InputHspEvtg3Outb2 = 71|0x20000U, /**< HSP_EVTG3_OUTB2 output assigned to HSP_XBAR_0_IN71 input. */
    kHSP__XBAR_0_InputHspEvtg3Outa3 = 72|0x20000U, /**< HSP_EVTG3_OUTA3 output assigned to HSP_XBAR_0_IN72 input. */
    kHSP__XBAR_0_InputHspEvtg3Outb3 = 73|0x20000U, /**< HSP_EVTG3_OUTB3 output assigned to HSP_XBAR_0_IN73 input. */
    kHSP__XBAR_0_InputAudioXbarOut5 = 74|0x20000U, /**< AUDIO_XBAR_OUT5 output assigned to HSP_XBAR_0_IN74 input. */
    kHSP__XBAR_0_InputAudioXbarOut6 = 75|0x20000U, /**< AUDIO_XBAR_OUT6 output assigned to HSP_XBAR_0_IN75 input. */
    kHSP__XBAR_0_InputAudioXbarOut7 = 76|0x20000U, /**< AUDIO_XBAR_OUT7 output assigned to HSP_XBAR_0_IN76 input. */
    kHSP__XBAR_0_InputAudioXbarOut8 = 77|0x20000U, /**< AUDIO_XBAR_OUT8 output assigned to HSP_XBAR_0_IN77 input. */
    kHSP__XBAR_0_InputWakeXbarOut21 = 78|0x20000U, /**< WAKE_XBAR_OUT21 output assigned to HSP_XBAR_0_IN78 input. */
    kHSP__XBAR_0_InputWakeXbarOut22 = 79|0x20000U, /**< WAKE_XBAR_OUT22 output assigned to HSP_XBAR_0_IN79 input. */
    kHSP__XBAR_0_InputWakeXbarOut23 = 80|0x20000U, /**< WAKE_XBAR_OUT23 output assigned to HSP_XBAR_0_IN80 input. */
    kHSP__XBAR_0_InputWakeXbarOut24 = 81|0x20000U, /**< WAKE_XBAR_OUT24 output assigned to HSP_XBAR_0_IN81 input. */
    kHSP__XBAR_0_InputWakeXbarOut25 = 82|0x20000U, /**< WAKE_XBAR_OUT25 output assigned to HSP_XBAR_0_IN82 input. */
    kHSP__XBAR_0_InputWakeXbarOut26 = 83|0x20000U, /**< WAKE_XBAR_OUT26 output assigned to HSP_XBAR_0_IN83 input. */
    kHSP__XBAR_0_InputWakeXbarOut27 = 84|0x20000U, /**< WAKE_XBAR_OUT27 output assigned to HSP_XBAR_0_IN84 input. */
    kHSP__XBAR_0_InputWakeXbarOut28 = 85|0x20000U, /**< WAKE_XBAR_OUT28 output assigned to HSP_XBAR_0_IN85 input. */
    kHSP__XBAR_0_InputHspXbar0In0   = 86|0x20000U, /**< HSP_XBAR0_IN0 output assigned to HSP_XBAR_0_IN86 input. */
    kHSP__XBAR_0_InputHspXbar0In1   = 87|0x20000U, /**< HSP_XBAR0_IN1 output assigned to HSP_XBAR_0_IN87 input. */
    kHSP__XBAR_0_InputHspXbar0In2   = 88|0x20000U, /**< HSP_XBAR0_IN2 output assigned to HSP_XBAR_0_IN88 input. */
    kHSP__XBAR_0_InputHspXbar0In3   = 89|0x20000U, /**< HSP_XBAR0_IN3 output assigned to HSP_XBAR_0_IN89 input. */
    kHSP__XBAR_0_InputHspXbar0In4   = 90|0x20000U, /**< HSP_XBAR0_IN4 output assigned to HSP_XBAR_0_IN90 input. */
    kHSP__XBAR_0_InputHspXbar0In5   = 91|0x20000U, /**< HSP_XBAR0_IN5 output assigned to HSP_XBAR_0_IN91 input. */
    kHSP__XBAR_0_InputHspXbar0In6   = 92|0x20000U, /**< HSP_XBAR0_IN6 output assigned to HSP_XBAR_0_IN92 input. */
    kHSP__XBAR_0_InputHspXbar0In7   = 93|0x20000U, /**< HSP_XBAR0_IN7 output assigned to HSP_XBAR_0_IN93 input. */
    kHSP__XBAR_0_InputHspXbar0In8   = 94|0x20000U, /**< HSP_XBAR0_IN8 output assigned to HSP_XBAR_0_IN94 input. */
    kHSP__XBAR_0_InputHspXbar0In9   = 95|0x20000U, /**< HSP_XBAR0_IN9 output assigned to HSP_XBAR_0_IN95 input. */
    kHSP__XBAR_0_InputHspXbar0In10  = 96|0x20000U, /**< HSP_XBAR0_IN10 output assigned to HSP_XBAR_0_IN96 input. */
    kHSP__XBAR_0_InputHspXbar0In11  = 97|0x20000U, /**< HSP_XBAR0_IN11 output assigned to HSP_XBAR_0_IN97 input. */
    kHSP__XBAR_0_InputHspXbar0In12  = 98|0x20000U, /**< HSP_XBAR0_IN12 output assigned to HSP_XBAR_0_IN98 input. */
    kHSP__XBAR_0_InputHspXbar0In13  = 99|0x20000U, /**< HSP_XBAR0_IN13 output assigned to HSP_XBAR_0_IN99 input. */
    kHSP__XBAR_0_InputHspXbar0In14  = 100|0x20000U, /**< HSP_XBAR0_IN14 output assigned to HSP_XBAR_0_IN100 input. */
    kHSP__XBAR_0_InputHspXbar0In15  = 101|0x20000U, /**< HSP_XBAR0_IN15 output assigned to HSP_XBAR_0_IN101 input. */
    kHSP__XBAR_0_InputHspXbar0In16  = 102|0x20000U, /**< HSP_XBAR0_IN16 output assigned to HSP_XBAR_0_IN102 input. */
    kHSP__XBAR_0_InputHspXbar0In17  = 103|0x20000U, /**< HSP_XBAR0_IN17 output assigned to HSP_XBAR_0_IN103 input. */
    kHSP__XBAR_0_InputHspXbar0In18  = 104|0x20000U, /**< HSP_XBAR0_IN18 output assigned to HSP_XBAR_0_IN104 input. */
    kHSP__XBAR_0_InputHspXbar0In19  = 105|0x20000U, /**< HSP_XBAR0_IN19 output assigned to HSP_XBAR_0_IN105 input. */
    kHSP__XBAR_0_InputHspXbar0In20  = 106|0x20000U, /**< HSP_XBAR0_IN20 output assigned to HSP_XBAR_0_IN106 input. */
    kHSP__XBAR_0_InputHspXbar0In21  = 107|0x20000U, /**< HSP_XBAR0_IN21 output assigned to HSP_XBAR_0_IN107 input. */
    kHSP__XBAR_0_InputHspXbar0In22  = 108|0x20000U, /**< HSP_XBAR0_IN22 output assigned to HSP_XBAR_0_IN108 input. */
    kHSP__XBAR_0_InputHspXbar0In23  = 109|0x20000U, /**< HSP_XBAR0_IN23 output assigned to HSP_XBAR_0_IN109 input. */
    kHSP__XBAR_0_InputHspXbar0In24  = 110|0x20000U, /**< HSP_XBAR0_IN24 output assigned to HSP_XBAR_0_IN110 input. */
    kHSP__XBAR_0_InputHspXbar0In25  = 111|0x20000U, /**< HSP_XBAR0_IN25 output assigned to HSP_XBAR_0_IN111 input. */
    kHSP__XBAR_0_InputHspXbar0In26  = 112|0x20000U, /**< HSP_XBAR0_IN26 output assigned to HSP_XBAR_0_IN112 input. */
    kHSP__XBAR_0_InputHspXbar0In27  = 113|0x20000U, /**< HSP_XBAR0_IN27 output assigned to HSP_XBAR_0_IN113 input. */
    kHSP__XBAR_0_InputHspXbar0In28  = 114|0x20000U, /**< HSP_XBAR0_IN28 output assigned to HSP_XBAR_0_IN114 input. */
    kHSP__XBAR_0_InputHspXbar0In29  = 115|0x20000U, /**< HSP_XBAR0_IN29 output assigned to HSP_XBAR_0_IN115 input. */
    kHSP__XBAR_0_InputHspXbar0In30  = 116|0x20000U, /**< HSP_XBAR0_IN30 output assigned to HSP_XBAR_0_IN116 input. */
    kHSP__XBAR_0_InputHspXbar0In31  = 117|0x20000U, /**< HSP_XBAR0_IN31 output assigned to HSP_XBAR_0_IN117 input. */
    kHSP__XBAR_0_InputHspTrgsync1TrigOut0 = 118|0x20000U, /**< HSP_TRGSYNC1_TRIG_OUT0 output assigned to HSP_XBAR_0_IN118 input. */
    kHSP__XBAR_0_InputHspTrgsync1TrigOut1 = 119|0x20000U, /**< HSP_TRGSYNC1_TRIG_OUT1 output assigned to HSP_XBAR_0_IN119 input. */
    kHSP__XBAR_0_InputHspTrgsync1TrigOut2 = 120|0x20000U, /**< HSP_TRGSYNC1_TRIG_OUT2 output assigned to HSP_XBAR_0_IN120 input. */
    kHSP__XBAR_0_InputHspTrgsync1TrigOut3 = 121|0x20000U, /**< HSP_TRGSYNC1_TRIG_OUT3 output assigned to HSP_XBAR_0_IN121 input. */
    kHSP__XBAR_0_InputHspTrgsync1TrigOut4 = 122|0x20000U, /**< HSP_TRGSYNC1_TRIG_OUT4 output assigned to HSP_XBAR_0_IN122 input. */
    kHSP__XBAR_0_InputHspTrgsync1TrigOut5 = 123|0x20000U, /**< HSP_TRGSYNC1_TRIG_OUT5 output assigned to HSP_XBAR_0_IN123 input. */
    kHSP__XBAR_0_InputHspTrgsync1TrigOut6 = 124|0x20000U, /**< HSP_TRGSYNC1_TRIG_OUT6 output assigned to HSP_XBAR_0_IN124 input. */
    kHSP__XBAR_0_InputHspTrgsync1TrigOut7 = 125|0x20000U, /**< HSP_TRGSYNC1_TRIG_OUT7 output assigned to HSP_XBAR_0_IN125 input. */
    kHSP__XBAR_1_InputLogicLow      = 0|0x30000U,  /**< LOGIC_LOW output assigned to HSP_XBAR_1_IN0 input. */
    kHSP__XBAR_1_InputLogicHigh     = 1|0x30000U,  /**< LOGIC_HIGH output assigned to HSP_XBAR_1_IN1 input. */
    kHSP__XBAR_1_InputHspXbar2Out0  = 2|0x30000U,  /**< HSP_XBAR2_OUT0 output assigned to HSP_XBAR_1_IN2 input. */
    kHSP__XBAR_1_InputHspXbar2Out1  = 3|0x30000U,  /**< HSP_XBAR2_OUT1 output assigned to HSP_XBAR_1_IN3 input. */
    kHSP__XBAR_1_InputHspXbar2Out2  = 4|0x30000U,  /**< HSP_XBAR2_OUT2 output assigned to HSP_XBAR_1_IN4 input. */
    kHSP__XBAR_1_InputHspXbar2Out3  = 5|0x30000U,  /**< HSP_XBAR2_OUT3 output assigned to HSP_XBAR_1_IN5 input. */
    kHSP__XBAR_1_InputHspXbar2Out4  = 6|0x30000U,  /**< HSP_XBAR2_OUT4 output assigned to HSP_XBAR_1_IN6 input. */
    kHSP__XBAR_1_InputHspXbar2Out5  = 7|0x30000U,  /**< HSP_XBAR2_OUT5 output assigned to HSP_XBAR_1_IN7 input. */
    kHSP__XBAR_1_InputHspXbar2Out6  = 8|0x30000U,  /**< HSP_XBAR2_OUT6 output assigned to HSP_XBAR_1_IN8 input. */
    kHSP__XBAR_1_InputHspXbar2Out7  = 9|0x30000U,  /**< HSP_XBAR2_OUT7 output assigned to HSP_XBAR_1_IN9 input. */
    kHSP__XBAR_1_InputHspXbar2Out8  = 10|0x30000U, /**< HSP_XBAR2_OUT8 output assigned to HSP_XBAR_1_IN10 input. */
    kHSP__XBAR_1_InputHspXbar2Out9  = 11|0x30000U, /**< HSP_XBAR2_OUT9 output assigned to HSP_XBAR_1_IN11 input. */
    kHSP__XBAR_1_InputHspXbar2Out10 = 12|0x30000U, /**< HSP_XBAR2_OUT10 output assigned to HSP_XBAR_1_IN12 input. */
    kHSP__XBAR_1_InputHspXbar2Out11 = 13|0x30000U, /**< HSP_XBAR2_OUT11 output assigned to HSP_XBAR_1_IN13 input. */
    kHSP__XBAR_1_InputHspXbar2Out12 = 14|0x30000U, /**< HSP_XBAR2_OUT12 output assigned to HSP_XBAR_1_IN14 input. */
    kHSP__XBAR_1_InputHspXbar2Out13 = 15|0x30000U, /**< HSP_XBAR2_OUT13 output assigned to HSP_XBAR_1_IN15 input. */
    kHSP__XBAR_1_InputHspXbar2Out14 = 16|0x30000U, /**< HSP_XBAR2_OUT14 output assigned to HSP_XBAR_1_IN16 input. */
    kHSP__XBAR_1_InputHspXbar2Out15 = 17|0x30000U, /**< HSP_XBAR2_OUT15 output assigned to HSP_XBAR_1_IN17 input. */
    kHSP__XBAR_1_InputHspXbar2Out16 = 18|0x30000U, /**< HSP_XBAR2_OUT16 output assigned to HSP_XBAR_1_IN18 input. */
    kHSP__XBAR_1_InputHspXbar2Out17 = 19|0x30000U, /**< HSP_XBAR2_OUT17 output assigned to HSP_XBAR_1_IN19 input. */
    kHSP__XBAR_1_InputHspXbar2Out18 = 20|0x30000U, /**< HSP_XBAR2_OUT18 output assigned to HSP_XBAR_1_IN20 input. */
    kHSP__XBAR_1_InputHspXbar2Out19 = 21|0x30000U, /**< HSP_XBAR2_OUT19 output assigned to HSP_XBAR_1_IN21 input. */
    kHSP__XBAR_1_InputHspXbar2Out20 = 22|0x30000U, /**< HSP_XBAR2_OUT20 output assigned to HSP_XBAR_1_IN22 input. */
    kHSP__XBAR_1_InputHspXbar2Out21 = 23|0x30000U, /**< HSP_XBAR2_OUT21 output assigned to HSP_XBAR_1_IN23 input. */
    kHSP__XBAR_1_InputHspXbar2Out22 = 24|0x30000U, /**< HSP_XBAR2_OUT22 output assigned to HSP_XBAR_1_IN24 input. */
    kHSP__XBAR_1_InputHspXbar2Out23 = 25|0x30000U, /**< HSP_XBAR2_OUT23 output assigned to HSP_XBAR_1_IN25 input. */
    kHSP__XBAR_1_InputHspXbar2Out24 = 26|0x30000U, /**< HSP_XBAR2_OUT24 output assigned to HSP_XBAR_1_IN26 input. */
    kHSP__XBAR_1_InputHspXbar2Out25 = 27|0x30000U, /**< HSP_XBAR2_OUT25 output assigned to HSP_XBAR_1_IN27 input. */
    kHSP__XBAR_1_InputHspXbar2Out26 = 28|0x30000U, /**< HSP_XBAR2_OUT26 output assigned to HSP_XBAR_1_IN28 input. */
    kHSP__XBAR_1_InputHspXbar2Out27 = 29|0x30000U, /**< HSP_XBAR2_OUT27 output assigned to HSP_XBAR_1_IN29 input. */
    kHSP__XBAR_1_InputHspXbar2Out28 = 30|0x30000U, /**< HSP_XBAR2_OUT28 output assigned to HSP_XBAR_1_IN30 input. */
    kHSP__XBAR_1_InputHspXbar2Out29 = 31|0x30000U, /**< HSP_XBAR2_OUT29 output assigned to HSP_XBAR_1_IN31 input. */
    kHSP__XBAR_1_InputHspXbar2Out30 = 32|0x30000U, /**< HSP_XBAR2_OUT30 output assigned to HSP_XBAR_1_IN32 input. */
    kHSP__XBAR_1_InputHspXbar2Out31 = 33|0x30000U, /**< HSP_XBAR2_OUT31 output assigned to HSP_XBAR_1_IN33 input. */
    kHSP__XBAR_1_InputHspXbar2Out32 = 34|0x30000U, /**< HSP_XBAR2_OUT32 output assigned to HSP_XBAR_1_IN34 input. */
    kHSP__XBAR_1_InputHspXbar2Out33 = 35|0x30000U, /**< HSP_XBAR2_OUT33 output assigned to HSP_XBAR_1_IN35 input. */
    kHSP__XBAR_1_InputHspXbar2Out34 = 36|0x30000U, /**< HSP_XBAR2_OUT34 output assigned to HSP_XBAR_1_IN36 input. */
    kHSP__XBAR_1_InputHspXbar2Out35 = 37|0x30000U, /**< HSP_XBAR2_OUT35 output assigned to HSP_XBAR_1_IN37 input. */
    kHSP__XBAR_1_InputHspXbar2Out36 = 38|0x30000U, /**< HSP_XBAR2_OUT36 output assigned to HSP_XBAR_1_IN38 input. */
    kHSP__XBAR_1_InputHspXbar2Out37 = 39|0x30000U, /**< HSP_XBAR2_OUT37 output assigned to HSP_XBAR_1_IN39 input. */
    kHSP__XBAR_1_InputHspXbar2Out38 = 40|0x30000U, /**< HSP_XBAR2_OUT38 output assigned to HSP_XBAR_1_IN40 input. */
    kHSP__XBAR_1_InputHspXbar2Out39 = 41|0x30000U, /**< HSP_XBAR2_OUT39 output assigned to HSP_XBAR_1_IN41 input. */
    kHSP__XBAR_1_InputAudioXbarOut5 = 42|0x30000U, /**< AUDIO_XBAR_OUT5 output assigned to HSP_XBAR_1_IN42 input. */
    kHSP__XBAR_1_InputAudioXbarOut6 = 43|0x30000U, /**< AUDIO_XBAR_OUT6 output assigned to HSP_XBAR_1_IN43 input. */
    kHSP__XBAR_1_InputAudioXbarOut7 = 44|0x30000U, /**< AUDIO_XBAR_OUT7 output assigned to HSP_XBAR_1_IN44 input. */
    kHSP__XBAR_1_InputAudioXbarOut8 = 45|0x30000U, /**< AUDIO_XBAR_OUT8 output assigned to HSP_XBAR_1_IN45 input. */
    kHSP__XBAR_1_InputWakeXbarOut21 = 46|0x30000U, /**< WAKE_XBAR_OUT21 output assigned to HSP_XBAR_1_IN46 input. */
    kHSP__XBAR_1_InputWakeXbarOut22 = 47|0x30000U, /**< WAKE_XBAR_OUT22 output assigned to HSP_XBAR_1_IN47 input. */
    kHSP__XBAR_1_InputWakeXbarOut23 = 48|0x30000U, /**< WAKE_XBAR_OUT23 output assigned to HSP_XBAR_1_IN48 input. */
    kHSP__XBAR_1_InputWakeXbarOut24 = 49|0x30000U, /**< WAKE_XBAR_OUT24 output assigned to HSP_XBAR_1_IN49 input. */
    kHSP__XBAR_1_InputWakeXbarOut25 = 50|0x30000U, /**< WAKE_XBAR_OUT25 output assigned to HSP_XBAR_1_IN50 input. */
    kHSP__XBAR_1_InputWakeXbarOut26 = 51|0x30000U, /**< WAKE_XBAR_OUT26 output assigned to HSP_XBAR_1_IN51 input. */
    kHSP__XBAR_1_InputWakeXbarOut27 = 52|0x30000U, /**< WAKE_XBAR_OUT27 output assigned to HSP_XBAR_1_IN52 input. */
    kHSP__XBAR_1_InputWakeXbarOut28 = 53|0x30000U, /**< WAKE_XBAR_OUT28 output assigned to HSP_XBAR_1_IN53 input. */
    kHSP__XBAR_1_InputHspXbar1In0   = 54|0x30000U, /**< HSP_XBAR1_IN0 output assigned to HSP_XBAR_1_IN54 input. */
    kHSP__XBAR_1_InputHspXbar1In1   = 55|0x30000U, /**< HSP_XBAR1_IN1 output assigned to HSP_XBAR_1_IN55 input. */
    kHSP__XBAR_1_InputHspXbar1In2   = 56|0x30000U, /**< HSP_XBAR1_IN2 output assigned to HSP_XBAR_1_IN56 input. */
    kHSP__XBAR_1_InputHspXbar1In3   = 57|0x30000U, /**< HSP_XBAR1_IN3 output assigned to HSP_XBAR_1_IN57 input. */
    kHSP__XBAR_1_InputHspXbar1In4   = 58|0x30000U, /**< HSP_XBAR1_IN4 output assigned to HSP_XBAR_1_IN58 input. */
    kHSP__XBAR_1_InputHspXbar1In5   = 59|0x30000U, /**< HSP_XBAR1_IN5 output assigned to HSP_XBAR_1_IN59 input. */
    kHSP__XBAR_1_InputHspXbar1In6   = 60|0x30000U, /**< HSP_XBAR1_IN6 output assigned to HSP_XBAR_1_IN60 input. */
    kHSP__XBAR_1_InputHspXbar1In7   = 61|0x30000U, /**< HSP_XBAR1_IN7 output assigned to HSP_XBAR_1_IN61 input. */
    kHSP__XBAR_1_InputHspXbar1In8   = 62|0x30000U, /**< HSP_XBAR1_IN8 output assigned to HSP_XBAR_1_IN62 input. */
    kHSP__XBAR_1_InputHspXbar1In9   = 63|0x30000U, /**< HSP_XBAR1_IN9 output assigned to HSP_XBAR_1_IN63 input. */
    kHSP__XBAR_1_InputHspXbar1In10  = 64|0x30000U, /**< HSP_XBAR1_IN10 output assigned to HSP_XBAR_1_IN64 input. */
    kHSP__XBAR_1_InputHspXbar1In11  = 65|0x30000U, /**< HSP_XBAR1_IN11 output assigned to HSP_XBAR_1_IN65 input. */
    kHSP__XBAR_1_InputHspXbar1In12  = 66|0x30000U, /**< HSP_XBAR1_IN12 output assigned to HSP_XBAR_1_IN66 input. */
    kHSP__XBAR_1_InputHspXbar1In13  = 67|0x30000U, /**< HSP_XBAR1_IN13 output assigned to HSP_XBAR_1_IN67 input. */
    kHSP__XBAR_1_InputHspXbar1In14  = 68|0x30000U, /**< HSP_XBAR1_IN14 output assigned to HSP_XBAR_1_IN68 input. */
    kHSP__XBAR_1_InputHspXbar1In15  = 69|0x30000U, /**< HSP_XBAR1_IN15 output assigned to HSP_XBAR_1_IN69 input. */
    kHSP__XBAR_1_InputHspXbar1In16  = 70|0x30000U, /**< HSP_XBAR1_IN16 output assigned to HSP_XBAR_1_IN70 input. */
    kHSP__XBAR_1_InputHspXbar1In17  = 71|0x30000U, /**< HSP_XBAR1_IN17 output assigned to HSP_XBAR_1_IN71 input. */
    kHSP__XBAR_1_InputHspXbar1In18  = 72|0x30000U, /**< HSP_XBAR1_IN18 output assigned to HSP_XBAR_1_IN72 input. */
    kHSP__XBAR_1_InputHspXbar1In19  = 73|0x30000U, /**< HSP_XBAR1_IN19 output assigned to HSP_XBAR_1_IN73 input. */
    kHSP__XBAR_1_InputHspXbar1In20  = 74|0x30000U, /**< HSP_XBAR1_IN20 output assigned to HSP_XBAR_1_IN74 input. */
    kHSP__XBAR_1_InputHspXbar1In21  = 75|0x30000U, /**< HSP_XBAR1_IN21 output assigned to HSP_XBAR_1_IN75 input. */
    kHSP__XBAR_1_InputHspXbar1In22  = 76|0x30000U, /**< HSP_XBAR1_IN22 output assigned to HSP_XBAR_1_IN76 input. */
    kHSP__XBAR_1_InputHspXbar1In23  = 77|0x30000U, /**< HSP_XBAR1_IN23 output assigned to HSP_XBAR_1_IN77 input. */
    kHSP__XBAR_1_InputHspXbar1In24  = 78|0x30000U, /**< HSP_XBAR1_IN24 output assigned to HSP_XBAR_1_IN78 input. */
    kHSP__XBAR_1_InputHspXbar1In25  = 79|0x30000U, /**< HSP_XBAR1_IN25 output assigned to HSP_XBAR_1_IN79 input. */
    kHSP__XBAR_1_InputHspXbar1In26  = 80|0x30000U, /**< HSP_XBAR1_IN26 output assigned to HSP_XBAR_1_IN80 input. */
    kHSP__XBAR_1_InputHspXbar1In27  = 81|0x30000U, /**< HSP_XBAR1_IN27 output assigned to HSP_XBAR_1_IN81 input. */
    kHSP__XBAR_1_InputHspXbar1In28  = 82|0x30000U, /**< HSP_XBAR1_IN28 output assigned to HSP_XBAR_1_IN82 input. */
    kHSP__XBAR_1_InputHspXbar1In29  = 83|0x30000U, /**< HSP_XBAR1_IN29 output assigned to HSP_XBAR_1_IN83 input. */
    kHSP__XBAR_1_InputHspXbar1In30  = 84|0x30000U, /**< HSP_XBAR1_IN30 output assigned to HSP_XBAR_1_IN84 input. */
    kHSP__XBAR_1_InputHspXbar1In31  = 85|0x30000U, /**< HSP_XBAR1_IN31 output assigned to HSP_XBAR_1_IN85 input. */
    kHSP__XBAR_1_InputHspTrgsync1TrigOut0 = 86|0x30000U, /**< HSP_TRGSYNC1_TRIG_OUT0 output assigned to HSP_XBAR_1_IN86 input. */
    kHSP__XBAR_1_InputHspTrgsync1TrigOut1 = 87|0x30000U, /**< HSP_TRGSYNC1_TRIG_OUT1 output assigned to HSP_XBAR_1_IN87 input. */
    kHSP__XBAR_1_InputHspTrgsync1TrigOut2 = 88|0x30000U, /**< HSP_TRGSYNC1_TRIG_OUT2 output assigned to HSP_XBAR_1_IN88 input. */
    kHSP__XBAR_1_InputHspTrgsync1TrigOut3 = 89|0x30000U, /**< HSP_TRGSYNC1_TRIG_OUT3 output assigned to HSP_XBAR_1_IN89 input. */
    kHSP__XBAR_1_InputHspTrgsync1TrigOut4 = 90|0x30000U, /**< HSP_TRGSYNC1_TRIG_OUT4 output assigned to HSP_XBAR_1_IN90 input. */
    kHSP__XBAR_1_InputHspTrgsync1TrigOut5 = 91|0x30000U, /**< HSP_TRGSYNC1_TRIG_OUT5 output assigned to HSP_XBAR_1_IN91 input. */
    kHSP__XBAR_1_InputHspTrgsync1TrigOut6 = 92|0x30000U, /**< HSP_TRGSYNC1_TRIG_OUT6 output assigned to HSP_XBAR_1_IN92 input. */
    kHSP__XBAR_1_InputHspTrgsync1TrigOut7 = 93|0x30000U, /**< HSP_TRGSYNC1_TRIG_OUT7 output assigned to HSP_XBAR_1_IN93 input. */
    kHSP__XBAR_2_InputLogicLow      = 0|0x40000U,  /**< LOGIC_LOW output assigned to HSP_XBAR_2_IN0 input. */
    kHSP__XBAR_2_InputLogicHigh     = 1|0x40000U,  /**< LOGIC_HIGH output assigned to HSP_XBAR_2_IN1 input. */
    kHSP__XBAR_2_InputMainEdma1TrigOut0 = 2|0x40000U, /**< MAIN_EDMA1_TRIG_OUT0 output assigned to HSP_XBAR_2_IN2 input. */
    kHSP__XBAR_2_InputMainEdma1TrigOut1 = 3|0x40000U, /**< MAIN_EDMA1_TRIG_OUT1 output assigned to HSP_XBAR_2_IN3 input. */
    kHSP__XBAR_2_InputMainEdma1TrigOut2 = 4|0x40000U, /**< MAIN_EDMA1_TRIG_OUT2 output assigned to HSP_XBAR_2_IN4 input. */
    kHSP__XBAR_2_InputMainEdma1TrigOut3 = 5|0x40000U, /**< MAIN_EDMA1_TRIG_OUT3 output assigned to HSP_XBAR_2_IN5 input. */
    kHSP__XBAR_2_InputMainEdma1Idle = 6|0x40000U,  /**< MAIN_EDMA1_IDLE output assigned to HSP_XBAR_2_IN6 input. */
    kHSP__XBAR_2_InputMainEdma0TrigOut0 = 7|0x40000U, /**< MAIN_EDMA0_TRIG_OUT0 output assigned to HSP_XBAR_2_IN7 input. */
    kHSP__XBAR_2_InputMainEdma0TrigOut1 = 8|0x40000U, /**< MAIN_EDMA0_TRIG_OUT1 output assigned to HSP_XBAR_2_IN8 input. */
    kHSP__XBAR_2_InputMainEdma0Idle = 9|0x40000U,  /**< MAIN_EDMA0_IDLE output assigned to HSP_XBAR_2_IN9 input. */
    kHSP__XBAR_2_InputHspAdc0TcompPulse0 = 10|0x40000U, /**< HSP_ADC0_TCOMP_PULSE0 output assigned to HSP_XBAR_2_IN10 input. */
    kHSP__XBAR_2_InputHspAdc0TcompPulse1 = 11|0x40000U, /**< HSP_ADC0_TCOMP_PULSE1 output assigned to HSP_XBAR_2_IN11 input. */
    kHSP__XBAR_2_InputHspAdc0TcompPulse2 = 12|0x40000U, /**< HSP_ADC0_TCOMP_PULSE2 output assigned to HSP_XBAR_2_IN12 input. */
    kHSP__XBAR_2_InputHspAdc0TcompPulse3 = 13|0x40000U, /**< HSP_ADC0_TCOMP_PULSE3 output assigned to HSP_XBAR_2_IN13 input. */
    kHSP__XBAR_2_InputHspAdc0TcompPulse4 = 14|0x40000U, /**< HSP_ADC0_TCOMP_PULSE4 output assigned to HSP_XBAR_2_IN14 input. */
    kHSP__XBAR_2_InputHspAdc0TcompPulse5 = 15|0x40000U, /**< HSP_ADC0_TCOMP_PULSE5 output assigned to HSP_XBAR_2_IN15 input. */
    kHSP__XBAR_2_InputHspAdc0TcompPulse6 = 16|0x40000U, /**< HSP_ADC0_TCOMP_PULSE6 output assigned to HSP_XBAR_2_IN16 input. */
    kHSP__XBAR_2_InputHspAdc0TcompPulse7 = 17|0x40000U, /**< HSP_ADC0_TCOMP_PULSE7 output assigned to HSP_XBAR_2_IN17 input. */
    kHSP__XBAR_2_InputHspAdc1TcompPulse0 = 18|0x40000U, /**< HSP_ADC1_TCOMP_PULSE0 output assigned to HSP_XBAR_2_IN18 input. */
    kHSP__XBAR_2_InputHspAdc1TcompPulse1 = 19|0x40000U, /**< HSP_ADC1_TCOMP_PULSE1 output assigned to HSP_XBAR_2_IN19 input. */
    kHSP__XBAR_2_InputHspAdc1TcompPulse2 = 20|0x40000U, /**< HSP_ADC1_TCOMP_PULSE2 output assigned to HSP_XBAR_2_IN20 input. */
    kHSP__XBAR_2_InputHspAdc1TcompPulse3 = 21|0x40000U, /**< HSP_ADC1_TCOMP_PULSE3 output assigned to HSP_XBAR_2_IN21 input. */
    kHSP__XBAR_2_InputHspAdc1TcompPulse4 = 22|0x40000U, /**< HSP_ADC1_TCOMP_PULSE4 output assigned to HSP_XBAR_2_IN22 input. */
    kHSP__XBAR_2_InputHspAdc1TcompPulse5 = 23|0x40000U, /**< HSP_ADC1_TCOMP_PULSE5 output assigned to HSP_XBAR_2_IN23 input. */
    kHSP__XBAR_2_InputHspAdc1TcompPulse6 = 24|0x40000U, /**< HSP_ADC1_TCOMP_PULSE6 output assigned to HSP_XBAR_2_IN24 input. */
    kHSP__XBAR_2_InputHspAdc1TcompPulse7 = 25|0x40000U, /**< HSP_ADC1_TCOMP_PULSE7 output assigned to HSP_XBAR_2_IN25 input. */
    kHSP__XBAR_2_InputHspLpit0TrigOut0 = 26|0x40000U, /**< HSP_LPIT0_TRIG_OUT0 output assigned to HSP_XBAR_2_IN26 input. */
    kHSP__XBAR_2_InputHspLpit0TrigOut1 = 27|0x40000U, /**< HSP_LPIT0_TRIG_OUT1 output assigned to HSP_XBAR_2_IN27 input. */
    kHSP__XBAR_2_InputHspLpit0TrigOut2 = 28|0x40000U, /**< HSP_LPIT0_TRIG_OUT2 output assigned to HSP_XBAR_2_IN28 input. */
    kHSP__XBAR_2_InputHspLpit0TrigOut3 = 29|0x40000U, /**< HSP_LPIT0_TRIG_OUT3 output assigned to HSP_XBAR_2_IN29 input. */
    kHSP__XBAR_2_InputHspLpit1TrigOut0 = 30|0x40000U, /**< HSP_LPIT1_TRIG_OUT0 output assigned to HSP_XBAR_2_IN30 input. */
    kHSP__XBAR_2_InputHspLpit1TrigOut1 = 31|0x40000U, /**< HSP_LPIT1_TRIG_OUT1 output assigned to HSP_XBAR_2_IN31 input. */
    kHSP__XBAR_2_InputHspLpit1TrigOut2 = 32|0x40000U, /**< HSP_LPIT1_TRIG_OUT2 output assigned to HSP_XBAR_2_IN32 input. */
    kHSP__XBAR_2_InputHspLpit1TrigOut3 = 33|0x40000U, /**< HSP_LPIT1_TRIG_OUT3 output assigned to HSP_XBAR_2_IN33 input. */
    kHSP__XBAR_2_InputHspFlexpwm0Sm0Reload = 34|0x40000U, /**< HSP_FLEXPWM0_SM0_RELOAD output assigned to HSP_XBAR_2_IN34 input. */
    kHSP__XBAR_2_InputHspFlexpwm0Sm0TrigOut0 = 35|0x40000U, /**< HSP_FLEXPWM0_SM0_TRIG_OUT0 output assigned to HSP_XBAR_2_IN35 input. */
    kHSP__XBAR_2_InputHspFlexpwm0Sm0TrigOut1 = 36|0x40000U, /**< HSP_FLEXPWM0_SM0_TRIG_OUT1 output assigned to HSP_XBAR_2_IN36 input. */
    kHSP__XBAR_2_InputHspFlexpwm0Sm1TrigOut0 = 37|0x40000U, /**< HSP_FLEXPWM0_SM1_TRIG_OUT0 output assigned to HSP_XBAR_2_IN37 input. */
    kHSP__XBAR_2_InputHspFlexpwm0Sm1TrigOut1 = 38|0x40000U, /**< HSP_FLEXPWM0_SM1_TRIG_OUT1 output assigned to HSP_XBAR_2_IN38 input. */
    kHSP__XBAR_2_InputHspFlexpwm0Sm2TrigOut0 = 39|0x40000U, /**< HSP_FLEXPWM0_SM2_TRIG_OUT0 output assigned to HSP_XBAR_2_IN39 input. */
    kHSP__XBAR_2_InputHspFlexpwm0Sm2TrigOut1 = 40|0x40000U, /**< HSP_FLEXPWM0_SM2_TRIG_OUT1 output assigned to HSP_XBAR_2_IN40 input. */
    kHSP__XBAR_2_InputHspFlexpwm0Sm3TrigOut0 = 41|0x40000U, /**< HSP_FLEXPWM0_SM3_TRIG_OUT0 output assigned to HSP_XBAR_2_IN41 input. */
    kHSP__XBAR_2_InputHspFlexpwm0Sm3TrigOut1 = 42|0x40000U, /**< HSP_FLEXPWM0_SM3_TRIG_OUT1 output assigned to HSP_XBAR_2_IN42 input. */
    kHSP__XBAR_2_InputHspFlexpwm1Sm0Reload = 43|0x40000U, /**< HSP_FLEXPWM1_SM0_RELOAD output assigned to HSP_XBAR_2_IN43 input. */
    kHSP__XBAR_2_InputHspFlexpwm1Sm0TrigOut0 = 44|0x40000U, /**< HSP_FLEXPWM1_SM0_TRIG_OUT0 output assigned to HSP_XBAR_2_IN44 input. */
    kHSP__XBAR_2_InputHspFlexpwm1Sm0TrigOut1 = 45|0x40000U, /**< HSP_FLEXPWM1_SM0_TRIG_OUT1 output assigned to HSP_XBAR_2_IN45 input. */
    kHSP__XBAR_2_InputHspFlexpwm1Sm1TrigOut0 = 46|0x40000U, /**< HSP_FLEXPWM1_SM1_TRIG_OUT0 output assigned to HSP_XBAR_2_IN46 input. */
    kHSP__XBAR_2_InputHspFlexpwm1Sm1TrigOut1 = 47|0x40000U, /**< HSP_FLEXPWM1_SM1_TRIG_OUT1 output assigned to HSP_XBAR_2_IN47 input. */
    kHSP__XBAR_2_InputHspFlexpwm1Sm2TrigOut0 = 48|0x40000U, /**< HSP_FLEXPWM1_SM2_TRIG_OUT0 output assigned to HSP_XBAR_2_IN48 input. */
    kHSP__XBAR_2_InputHspFlexpwm1Sm2TrigOut1 = 49|0x40000U, /**< HSP_FLEXPWM1_SM2_TRIG_OUT1 output assigned to HSP_XBAR_2_IN49 input. */
    kHSP__XBAR_2_InputHspFlexpwm1Sm3TrigOut0 = 50|0x40000U, /**< HSP_FLEXPWM1_SM3_TRIG_OUT0 output assigned to HSP_XBAR_2_IN50 input. */
    kHSP__XBAR_2_InputHspFlexpwm1Sm3TrigOut1 = 51|0x40000U, /**< HSP_FLEXPWM1_SM3_TRIG_OUT1 output assigned to HSP_XBAR_2_IN51 input. */
    kHSP__XBAR_2_InputHspFlexpwm2Sm0Reload = 52|0x40000U, /**< HSP_FLEXPWM2_SM0_RELOAD output assigned to HSP_XBAR_2_IN52 input. */
    kHSP__XBAR_2_InputHspFlexpwm2Sm0TrigOut0 = 53|0x40000U, /**< HSP_FLEXPWM2_SM0_TRIG_OUT0 output assigned to HSP_XBAR_2_IN53 input. */
    kHSP__XBAR_2_InputHspFlexpwm2Sm0TrigOut1 = 54|0x40000U, /**< HSP_FLEXPWM2_SM0_TRIG_OUT1 output assigned to HSP_XBAR_2_IN54 input. */
    kHSP__XBAR_2_InputHspFlexpwm2Sm1TrigOut0 = 55|0x40000U, /**< HSP_FLEXPWM2_SM1_TRIG_OUT0 output assigned to HSP_XBAR_2_IN55 input. */
    kHSP__XBAR_2_InputHspFlexpwm2Sm1TrigOut1 = 56|0x40000U, /**< HSP_FLEXPWM2_SM1_TRIG_OUT1 output assigned to HSP_XBAR_2_IN56 input. */
    kHSP__XBAR_2_InputHspFlexpwm2Sm2TrigOut0 = 57|0x40000U, /**< HSP_FLEXPWM2_SM2_TRIG_OUT0 output assigned to HSP_XBAR_2_IN57 input. */
    kHSP__XBAR_2_InputHspFlexpwm2Sm2TrigOut1 = 58|0x40000U, /**< HSP_FLEXPWM2_SM2_TRIG_OUT1 output assigned to HSP_XBAR_2_IN58 input. */
    kHSP__XBAR_2_InputHspFlexpwm2Sm3TrigOut0 = 59|0x40000U, /**< HSP_FLEXPWM2_SM3_TRIG_OUT0 output assigned to HSP_XBAR_2_IN59 input. */
    kHSP__XBAR_2_InputHspFlexpwm2Sm3TrigOut1 = 60|0x40000U, /**< HSP_FLEXPWM2_SM3_TRIG_OUT1 output assigned to HSP_XBAR_2_IN60 input. */
    kHSP__XBAR_2_InputHspFlexpwm3Sm0Reload = 61|0x40000U, /**< HSP_FLEXPWM3_SM0_RELOAD output assigned to HSP_XBAR_2_IN61 input. */
    kHSP__XBAR_2_InputHspFlexpwm3Sm0TrigOut0 = 62|0x40000U, /**< HSP_FLEXPWM3_SM0_TRIG_OUT0 output assigned to HSP_XBAR_2_IN62 input. */
    kHSP__XBAR_2_InputHspFlexpwm3Sm0TrigOut1 = 63|0x40000U, /**< HSP_FLEXPWM3_SM0_TRIG_OUT1 output assigned to HSP_XBAR_2_IN63 input. */
    kHSP__XBAR_2_InputHspFlexpwm3Sm1TrigOut0 = 64|0x40000U, /**< HSP_FLEXPWM3_SM1_TRIG_OUT0 output assigned to HSP_XBAR_2_IN64 input. */
    kHSP__XBAR_2_InputHspFlexpwm3Sm1TrigOut1 = 65|0x40000U, /**< HSP_FLEXPWM3_SM1_TRIG_OUT1 output assigned to HSP_XBAR_2_IN65 input. */
    kHSP__XBAR_2_InputHspFlexpwm3Sm2TrigOut0 = 66|0x40000U, /**< HSP_FLEXPWM3_SM2_TRIG_OUT0 output assigned to HSP_XBAR_2_IN66 input. */
    kHSP__XBAR_2_InputHspFlexpwm3Sm2TrigOut1 = 67|0x40000U, /**< HSP_FLEXPWM3_SM2_TRIG_OUT1 output assigned to HSP_XBAR_2_IN67 input. */
    kHSP__XBAR_2_InputHspFlexpwm3Sm3TrigOut0 = 68|0x40000U, /**< HSP_FLEXPWM3_SM3_TRIG_OUT0 output assigned to HSP_XBAR_2_IN68 input. */
    kHSP__XBAR_2_InputHspFlexpwm3Sm3TrigOut1 = 69|0x40000U, /**< HSP_FLEXPWM3_SM3_TRIG_OUT1 output assigned to HSP_XBAR_2_IN69 input. */
    kHSP__XBAR_2_InputHspQuadtpm0CntTrigOut0 = 70|0x40000U, /**< HSP_QUADTPM0_CNT_TRIG_OUT0 output assigned to HSP_XBAR_2_IN70 input. */
    kHSP__XBAR_2_InputHspQuadtpm0CntTrigOut1 = 71|0x40000U, /**< HSP_QUADTPM0_CNT_TRIG_OUT1 output assigned to HSP_XBAR_2_IN71 input. */
    kHSP__XBAR_2_InputHspQuadtpm0CntTrigOut2 = 72|0x40000U, /**< HSP_QUADTPM0_CNT_TRIG_OUT2 output assigned to HSP_XBAR_2_IN72 input. */
    kHSP__XBAR_2_InputHspQuadtpm0CntTrigOut3 = 73|0x40000U, /**< HSP_QUADTPM0_CNT_TRIG_OUT3 output assigned to HSP_XBAR_2_IN73 input. */
    kHSP__XBAR_2_InputHspQuadtpm0ChTrigOut0 = 74|0x40000U, /**< HSP_QUADTPM0_CH_TRIG_OUT0 output assigned to HSP_XBAR_2_IN74 input. */
    kHSP__XBAR_2_InputHspQuadtpm0ChTrigOut1 = 75|0x40000U, /**< HSP_QUADTPM0_CH_TRIG_OUT1 output assigned to HSP_XBAR_2_IN75 input. */
    kHSP__XBAR_2_InputHspQuadtpm0ChTrigOut2 = 76|0x40000U, /**< HSP_QUADTPM0_CH_TRIG_OUT2 output assigned to HSP_XBAR_2_IN76 input. */
    kHSP__XBAR_2_InputHspQuadtpm0ChTrigOut3 = 77|0x40000U, /**< HSP_QUADTPM0_CH_TRIG_OUT3 output assigned to HSP_XBAR_2_IN77 input. */
    kHSP__XBAR_2_InputHspQuadtpm0ChTrigOut4 = 78|0x40000U, /**< HSP_QUADTPM0_CH_TRIG_OUT4 output assigned to HSP_XBAR_2_IN78 input. */
    kHSP__XBAR_2_InputHspQuadtpm0ChTrigOut5 = 79|0x40000U, /**< HSP_QUADTPM0_CH_TRIG_OUT5 output assigned to HSP_XBAR_2_IN79 input. */
    kHSP__XBAR_2_InputHspQuadtpm0ChTrigOut6 = 80|0x40000U, /**< HSP_QUADTPM0_CH_TRIG_OUT6 output assigned to HSP_XBAR_2_IN80 input. */
    kHSP__XBAR_2_InputHspQuadtpm0ChTrigOut7 = 81|0x40000U, /**< HSP_QUADTPM0_CH_TRIG_OUT7 output assigned to HSP_XBAR_2_IN81 input. */
    kHSP__XBAR_2_InputRESERVED82    = 82|0x40000U, /**< HSP_XBAR_2_IN82 input is reserved. */
    kHSP__XBAR_2_InputRESERVED83    = 83|0x40000U, /**< HSP_XBAR_2_IN83 input is reserved. */
    kHSP__XBAR_2_InputRESERVED84    = 84|0x40000U, /**< HSP_XBAR_2_IN84 input is reserved. */
    kHSP__XBAR_2_InputRESERVED85    = 85|0x40000U, /**< HSP_XBAR_2_IN85 input is reserved. */
    kHSP__XBAR_2_InputRESERVED86    = 86|0x40000U, /**< HSP_XBAR_2_IN86 input is reserved. */
    kHSP__XBAR_2_InputRESERVED87    = 87|0x40000U, /**< HSP_XBAR_2_IN87 input is reserved. */
    kHSP__XBAR_2_InputRESERVED88    = 88|0x40000U, /**< HSP_XBAR_2_IN88 input is reserved. */
    kHSP__XBAR_2_InputRESERVED89    = 89|0x40000U, /**< HSP_XBAR_2_IN89 input is reserved. */
    kHSP__XBAR_2_InputRESERVED90    = 90|0x40000U, /**< HSP_XBAR_2_IN90 input is reserved. */
    kHSP__XBAR_2_InputRESERVED91    = 91|0x40000U, /**< HSP_XBAR_2_IN91 input is reserved. */
    kHSP__XBAR_2_InputRESERVED92    = 92|0x40000U, /**< HSP_XBAR_2_IN92 input is reserved. */
    kHSP__XBAR_2_InputRESERVED93    = 93|0x40000U, /**< HSP_XBAR_2_IN93 input is reserved. */
    kHSP__XBAR_2_InputRESERVED94    = 94|0x40000U, /**< HSP_XBAR_2_IN94 input is reserved. */
    kHSP__XBAR_2_InputRESERVED95    = 95|0x40000U, /**< HSP_XBAR_2_IN95 input is reserved. */
    kHSP__XBAR_2_InputRESERVED96    = 96|0x40000U, /**< HSP_XBAR_2_IN96 input is reserved. */
    kHSP__XBAR_2_InputRESERVED97    = 97|0x40000U, /**< HSP_XBAR_2_IN97 input is reserved. */
    kHSP__XBAR_2_InputRESERVED98    = 98|0x40000U, /**< HSP_XBAR_2_IN98 input is reserved. */
    kHSP__XBAR_2_InputRESERVED99    = 99|0x40000U, /**< HSP_XBAR_2_IN99 input is reserved. */
    kHSP__XBAR_2_InputRESERVED100   = 100|0x40000U, /**< HSP_XBAR_2_IN100 input is reserved. */
    kHSP__XBAR_2_InputRESERVED101   = 101|0x40000U, /**< HSP_XBAR_2_IN101 input is reserved. */
    kHSP__XBAR_2_InputRESERVED102   = 102|0x40000U, /**< HSP_XBAR_2_IN102 input is reserved. */
    kHSP__XBAR_2_InputRESERVED103   = 103|0x40000U, /**< HSP_XBAR_2_IN103 input is reserved. */
    kHSP__XBAR_2_InputRESERVED104   = 104|0x40000U, /**< HSP_XBAR_2_IN104 input is reserved. */
    kHSP__XBAR_2_InputRESERVED105   = 105|0x40000U, /**< HSP_XBAR_2_IN105 input is reserved. */
    kHSP__XBAR_2_InputHspQtmr0Out0  = 106|0x40000U, /**< HSP_QTMR0_OUT0 output assigned to HSP_XBAR_2_IN106 input. */
    kHSP__XBAR_2_InputHspQtmr0Out1  = 107|0x40000U, /**< HSP_QTMR0_OUT1 output assigned to HSP_XBAR_2_IN107 input. */
    kHSP__XBAR_2_InputHspQtmr0Out2  = 108|0x40000U, /**< HSP_QTMR0_OUT2 output assigned to HSP_XBAR_2_IN108 input. */
    kHSP__XBAR_2_InputHspQtmr0Out3  = 109|0x40000U, /**< HSP_QTMR0_OUT3 output assigned to HSP_XBAR_2_IN109 input. */
    kHSP__XBAR_2_InputHspQtmr1Out0  = 110|0x40000U, /**< HSP_QTMR1_OUT0 output assigned to HSP_XBAR_2_IN110 input. */
    kHSP__XBAR_2_InputHspQtmr1Out1  = 111|0x40000U, /**< HSP_QTMR1_OUT1 output assigned to HSP_XBAR_2_IN111 input. */
    kHSP__XBAR_2_InputHspQtmr1Out2  = 112|0x40000U, /**< HSP_QTMR1_OUT2 output assigned to HSP_XBAR_2_IN112 input. */
    kHSP__XBAR_2_InputHspQtmr1Out3  = 113|0x40000U, /**< HSP_QTMR1_OUT3 output assigned to HSP_XBAR_2_IN113 input. */
    kHSP__XBAR_2_InputHspQtmr2Out0  = 114|0x40000U, /**< HSP_QTMR2_OUT0 output assigned to HSP_XBAR_2_IN114 input. */
    kHSP__XBAR_2_InputHspQtmr2Out1  = 115|0x40000U, /**< HSP_QTMR2_OUT1 output assigned to HSP_XBAR_2_IN115 input. */
    kHSP__XBAR_2_InputHspQtmr2Out2  = 116|0x40000U, /**< HSP_QTMR2_OUT2 output assigned to HSP_XBAR_2_IN116 input. */
    kHSP__XBAR_2_InputHspQtmr2Out3  = 117|0x40000U, /**< HSP_QTMR2_OUT3 output assigned to HSP_XBAR_2_IN117 input. */
    kHSP__XBAR_2_InputHspQtmr3Out0  = 118|0x40000U, /**< HSP_QTMR3_OUT0 output assigned to HSP_XBAR_2_IN118 input. */
    kHSP__XBAR_2_InputHspQtmr3Out1  = 119|0x40000U, /**< HSP_QTMR3_OUT1 output assigned to HSP_XBAR_2_IN119 input. */
    kHSP__XBAR_2_InputHspQtmr3Out2  = 120|0x40000U, /**< HSP_QTMR3_OUT2 output assigned to HSP_XBAR_2_IN120 input. */
    kHSP__XBAR_2_InputHspQtmr3Out3  = 121|0x40000U, /**< HSP_QTMR3_OUT3 output assigned to HSP_XBAR_2_IN121 input. */
    kHSP__XBAR_2_InputHspQdec0PosMatch0 = 122|0x40000U, /**< HSP_QDEC0_POS_MATCH0 output assigned to HSP_XBAR_2_IN122 input. */
    kHSP__XBAR_2_InputHspQdec0PosMatch1 = 123|0x40000U, /**< HSP_QDEC0_POS_MATCH1 output assigned to HSP_XBAR_2_IN123 input. */
    kHSP__XBAR_2_InputHspQdec0PosMatch2 = 124|0x40000U, /**< HSP_QDEC0_POS_MATCH2 output assigned to HSP_XBAR_2_IN124 input. */
    kHSP__XBAR_2_InputHspQdec0PosMatch3 = 125|0x40000U, /**< HSP_QDEC0_POS_MATCH3 output assigned to HSP_XBAR_2_IN125 input. */
    kHSP__XBAR_2_InputHspQdec0CompFlg0 = 126|0x40000U, /**< HSP_QDEC0_COMP_FLG0 output assigned to HSP_XBAR_2_IN126 input. */
    kHSP__XBAR_2_InputHspQdec0CompFlg1 = 127|0x40000U, /**< HSP_QDEC0_COMP_FLG1 output assigned to HSP_XBAR_2_IN127 input. */
    kHSP__XBAR_2_InputHspQdec0CompFlg2 = 128|0x40000U, /**< HSP_QDEC0_COMP_FLG2 output assigned to HSP_XBAR_2_IN128 input. */
    kHSP__XBAR_2_InputHspQdec0CompFlg3 = 129|0x40000U, /**< HSP_QDEC0_COMP_FLG3 output assigned to HSP_XBAR_2_IN129 input. */
    kHSP__XBAR_2_InputHspQdec0Dir   = 130|0x40000U, /**< HSP_QDEC0_DIR output assigned to HSP_XBAR_2_IN130 input. */
    kHSP__XBAR_2_InputHspQdec0CntUp = 131|0x40000U, /**< HSP_QDEC0_CNT_UP output assigned to HSP_XBAR_2_IN131 input. */
    kHSP__XBAR_2_InputHspQdec0CntDown = 132|0x40000U, /**< HSP_QDEC0_CNT_DOWN output assigned to HSP_XBAR_2_IN132 input. */
    kHSP__XBAR_2_InputHspQdec1PosMatch0 = 133|0x40000U, /**< HSP_QDEC1_POS_MATCH0 output assigned to HSP_XBAR_2_IN133 input. */
    kHSP__XBAR_2_InputHspQdec1PosMatch1 = 134|0x40000U, /**< HSP_QDEC1_POS_MATCH1 output assigned to HSP_XBAR_2_IN134 input. */
    kHSP__XBAR_2_InputHspQdec1PosMatch2 = 135|0x40000U, /**< HSP_QDEC1_POS_MATCH2 output assigned to HSP_XBAR_2_IN135 input. */
    kHSP__XBAR_2_InputHspQdec1PosMatch3 = 136|0x40000U, /**< HSP_QDEC1_POS_MATCH3 output assigned to HSP_XBAR_2_IN136 input. */
    kHSP__XBAR_2_InputHspQdec1CompFlg0 = 137|0x40000U, /**< HSP_QDEC1_COMP_FLG0 output assigned to HSP_XBAR_2_IN137 input. */
    kHSP__XBAR_2_InputHspQdec1CompFlg1 = 138|0x40000U, /**< HSP_QDEC1_COMP_FLG1 output assigned to HSP_XBAR_2_IN138 input. */
    kHSP__XBAR_2_InputHspQdec1CompFlg2 = 139|0x40000U, /**< HSP_QDEC1_COMP_FLG2 output assigned to HSP_XBAR_2_IN139 input. */
    kHSP__XBAR_2_InputHspQdec1CompFlg3 = 140|0x40000U, /**< HSP_QDEC1_COMP_FLG3 output assigned to HSP_XBAR_2_IN140 input. */
    kHSP__XBAR_2_InputHspQdec1Dir   = 141|0x40000U, /**< HSP_QDEC1_DIR output assigned to HSP_XBAR_2_IN141 input. */
    kHSP__XBAR_2_InputHspQdec1CntUp = 142|0x40000U, /**< HSP_QDEC1_CNT_UP output assigned to HSP_XBAR_2_IN142 input. */
    kHSP__XBAR_2_InputHspQdec1CntDown = 143|0x40000U, /**< HSP_QDEC1_CNT_DOWN output assigned to HSP_XBAR_2_IN143 input. */
    kHSP__XBAR_2_InputHspQdec2PosMatch0 = 144|0x40000U, /**< HSP_QDEC2_POS_MATCH0 output assigned to HSP_XBAR_2_IN144 input. */
    kHSP__XBAR_2_InputHspQdec2PosMatch1 = 145|0x40000U, /**< HSP_QDEC2_POS_MATCH1 output assigned to HSP_XBAR_2_IN145 input. */
    kHSP__XBAR_2_InputHspQdec2PosMatch2 = 146|0x40000U, /**< HSP_QDEC2_POS_MATCH2 output assigned to HSP_XBAR_2_IN146 input. */
    kHSP__XBAR_2_InputHspQdec2PosMatch3 = 147|0x40000U, /**< HSP_QDEC2_POS_MATCH3 output assigned to HSP_XBAR_2_IN147 input. */
    kHSP__XBAR_2_InputHspQdec2CompFlg0 = 148|0x40000U, /**< HSP_QDEC2_COMP_FLG0 output assigned to HSP_XBAR_2_IN148 input. */
    kHSP__XBAR_2_InputHspQdec2CompFlg1 = 149|0x40000U, /**< HSP_QDEC2_COMP_FLG1 output assigned to HSP_XBAR_2_IN149 input. */
    kHSP__XBAR_2_InputHspQdec2CompFlg2 = 150|0x40000U, /**< HSP_QDEC2_COMP_FLG2 output assigned to HSP_XBAR_2_IN150 input. */
    kHSP__XBAR_2_InputHspQdec2CompFlg3 = 151|0x40000U, /**< HSP_QDEC2_COMP_FLG3 output assigned to HSP_XBAR_2_IN151 input. */
    kHSP__XBAR_2_InputHspQdec2Dir   = 152|0x40000U, /**< HSP_QDEC2_DIR output assigned to HSP_XBAR_2_IN152 input. */
    kHSP__XBAR_2_InputHspQdec2CntUp = 153|0x40000U, /**< HSP_QDEC2_CNT_UP output assigned to HSP_XBAR_2_IN153 input. */
    kHSP__XBAR_2_InputHspQdec2CntDown = 154|0x40000U, /**< HSP_QDEC2_CNT_DOWN output assigned to HSP_XBAR_2_IN154 input. */
    kHSP__XBAR_2_InputHspQdec3PosMatch0 = 155|0x40000U, /**< HSP_QDEC3_POS_MATCH0 output assigned to HSP_XBAR_2_IN155 input. */
    kHSP__XBAR_2_InputHspQdec3PosMatch1 = 156|0x40000U, /**< HSP_QDEC3_POS_MATCH1 output assigned to HSP_XBAR_2_IN156 input. */
    kHSP__XBAR_2_InputHspQdec3PosMatch2 = 157|0x40000U, /**< HSP_QDEC3_POS_MATCH2 output assigned to HSP_XBAR_2_IN157 input. */
    kHSP__XBAR_2_InputHspQdec3PosMatch3 = 158|0x40000U, /**< HSP_QDEC3_POS_MATCH3 output assigned to HSP_XBAR_2_IN158 input. */
    kHSP__XBAR_2_InputHspQdec3CompFlg0 = 159|0x40000U, /**< HSP_QDEC3_COMP_FLG0 output assigned to HSP_XBAR_2_IN159 input. */
    kHSP__XBAR_2_InputHspQdec3CompFlg1 = 160|0x40000U, /**< HSP_QDEC3_COMP_FLG1 output assigned to HSP_XBAR_2_IN160 input. */
    kHSP__XBAR_2_InputHspQdec3CompFlg2 = 161|0x40000U, /**< HSP_QDEC3_COMP_FLG2 output assigned to HSP_XBAR_2_IN161 input. */
    kHSP__XBAR_2_InputHspQdec3CompFlg3 = 162|0x40000U, /**< HSP_QDEC3_COMP_FLG3 output assigned to HSP_XBAR_2_IN162 input. */
    kHSP__XBAR_2_InputHspQdec3Dir   = 163|0x40000U, /**< HSP_QDEC3_DIR output assigned to HSP_XBAR_2_IN163 input. */
    kHSP__XBAR_2_InputHspQdec3CntUp = 164|0x40000U, /**< HSP_QDEC3_CNT_UP output assigned to HSP_XBAR_2_IN164 input. */
    kHSP__XBAR_2_InputHspQdec3CntDown = 165|0x40000U, /**< HSP_QDEC3_CNT_DOWN output assigned to HSP_XBAR_2_IN165 input. */
    kHSP__XBAR_2_InputHspSinc0PulseTrigOut0 = 166|0x40000U, /**< HSP_SINC0_PULSE_TRIG_OUT0 output assigned to HSP_XBAR_2_IN166 input. */
    kHSP__XBAR_2_InputHspSinc0PulseTrigOut1 = 167|0x40000U, /**< HSP_SINC0_PULSE_TRIG_OUT1 output assigned to HSP_XBAR_2_IN167 input. */
    kHSP__XBAR_2_InputHspSinc0PulseTrigOut2 = 168|0x40000U, /**< HSP_SINC0_PULSE_TRIG_OUT2 output assigned to HSP_XBAR_2_IN168 input. */
    kHSP__XBAR_2_InputHspSinc0PulseTrigOut3 = 169|0x40000U, /**< HSP_SINC0_PULSE_TRIG_OUT3 output assigned to HSP_XBAR_2_IN169 input. */
    kHSP__XBAR_2_InputHspSinc0FiltCc0 = 170|0x40000U, /**< HSP_SINC0_FILT_CC0 output assigned to HSP_XBAR_2_IN170 input. */
    kHSP__XBAR_2_InputHspSinc0FiltCc1 = 171|0x40000U, /**< HSP_SINC0_FILT_CC1 output assigned to HSP_XBAR_2_IN171 input. */
    kHSP__XBAR_2_InputHspSinc0FiltCc2 = 172|0x40000U, /**< HSP_SINC0_FILT_CC2 output assigned to HSP_XBAR_2_IN172 input. */
    kHSP__XBAR_2_InputHspSinc0FiltCc3 = 173|0x40000U, /**< HSP_SINC0_FILT_CC3 output assigned to HSP_XBAR_2_IN173 input. */
    kHSP__XBAR_2_InputHspSinc0ModOut2 = 174|0x40000U, /**< HSP_SINC0_MOD_OUT2 output assigned to HSP_XBAR_2_IN174 input. */
    kHSP__XBAR_2_InputHspSinc0Break0 = 175|0x40000U, /**< HSP_SINC0_BREAK0 output assigned to HSP_XBAR_2_IN175 input. */
    kHSP__XBAR_2_InputHspSinc0Break1 = 176|0x40000U, /**< HSP_SINC0_BREAK1 output assigned to HSP_XBAR_2_IN176 input. */
    kHSP__XBAR_2_InputHspSinc0Break2 = 177|0x40000U, /**< HSP_SINC0_BREAK2 output assigned to HSP_XBAR_2_IN177 input. */
    kHSP__XBAR_2_InputHspSinc0Break3 = 178|0x40000U, /**< HSP_SINC0_BREAK3 output assigned to HSP_XBAR_2_IN178 input. */
    kHSP__XBAR_2_InputHspSinc1PulseTrigOut0 = 179|0x40000U, /**< HSP_SINC1_PULSE_TRIG_OUT0 output assigned to HSP_XBAR_2_IN179 input. */
    kHSP__XBAR_2_InputHspSinc1PulseTrigOut1 = 180|0x40000U, /**< HSP_SINC1_PULSE_TRIG_OUT1 output assigned to HSP_XBAR_2_IN180 input. */
    kHSP__XBAR_2_InputHspSinc1PulseTrigOut2 = 181|0x40000U, /**< HSP_SINC1_PULSE_TRIG_OUT2 output assigned to HSP_XBAR_2_IN181 input. */
    kHSP__XBAR_2_InputHspSinc1PulseTrigOut3 = 182|0x40000U, /**< HSP_SINC1_PULSE_TRIG_OUT3 output assigned to HSP_XBAR_2_IN182 input. */
    kHSP__XBAR_2_InputHspSinc1FiltCc0 = 183|0x40000U, /**< HSP_SINC1_FILT_CC0 output assigned to HSP_XBAR_2_IN183 input. */
    kHSP__XBAR_2_InputHspSinc1FiltCc1 = 184|0x40000U, /**< HSP_SINC1_FILT_CC1 output assigned to HSP_XBAR_2_IN184 input. */
    kHSP__XBAR_2_InputHspSinc1FiltCc2 = 185|0x40000U, /**< HSP_SINC1_FILT_CC2 output assigned to HSP_XBAR_2_IN185 input. */
    kHSP__XBAR_2_InputHspSinc1FiltCc3 = 186|0x40000U, /**< HSP_SINC1_FILT_CC3 output assigned to HSP_XBAR_2_IN186 input. */
    kHSP__XBAR_2_InputHspSinc1ModOut2 = 187|0x40000U, /**< HSP_SINC1_MOD_OUT2 output assigned to HSP_XBAR_2_IN187 input. */
    kHSP__XBAR_2_InputHspSinc1Break0 = 188|0x40000U, /**< HSP_SINC1_BREAK0 output assigned to HSP_XBAR_2_IN188 input. */
    kHSP__XBAR_2_InputHspSinc1Break1 = 189|0x40000U, /**< HSP_SINC1_BREAK1 output assigned to HSP_XBAR_2_IN189 input. */
    kHSP__XBAR_2_InputHspSinc1Break2 = 190|0x40000U, /**< HSP_SINC1_BREAK2 output assigned to HSP_XBAR_2_IN190 input. */
    kHSP__XBAR_2_InputHspSinc1Break3 = 191|0x40000U, /**< HSP_SINC1_BREAK3 output assigned to HSP_XBAR_2_IN191 input. */
    kHSP__XBAR_2_InputHspFlexio0TrigOut0 = 192|0x40000U, /**< HSP_FLEXIO0_TRIG_OUT0 output assigned to HSP_XBAR_2_IN192 input. */
    kHSP__XBAR_2_InputHspFlexio0TrigOut1 = 193|0x40000U, /**< HSP_FLEXIO0_TRIG_OUT1 output assigned to HSP_XBAR_2_IN193 input. */
    kHSP__XBAR_2_InputHspFlexio0TrigOut2 = 194|0x40000U, /**< HSP_FLEXIO0_TRIG_OUT2 output assigned to HSP_XBAR_2_IN194 input. */
    kHSP__XBAR_2_InputHspFlexio0TrigOut3 = 195|0x40000U, /**< HSP_FLEXIO0_TRIG_OUT3 output assigned to HSP_XBAR_2_IN195 input. */
    kHSP__XBAR_2_InputHspFlexio1TrigOut0 = 196|0x40000U, /**< HSP_FLEXIO1_TRIG_OUT0 output assigned to HSP_XBAR_2_IN196 input. */
    kHSP__XBAR_2_InputHspFlexio1TrigOut1 = 197|0x40000U, /**< HSP_FLEXIO1_TRIG_OUT1 output assigned to HSP_XBAR_2_IN197 input. */
    kHSP__XBAR_2_InputHspFlexio1TrigOut2 = 198|0x40000U, /**< HSP_FLEXIO1_TRIG_OUT2 output assigned to HSP_XBAR_2_IN198 input. */
    kHSP__XBAR_2_InputHspFlexio1TrigOut3 = 199|0x40000U, /**< HSP_FLEXIO1_TRIG_OUT3 output assigned to HSP_XBAR_2_IN199 input. */
    kHSP__XBAR_2_InputHspFlexio2TrigOut0 = 200|0x40000U, /**< HSP_FLEXIO2_TRIG_OUT0 output assigned to HSP_XBAR_2_IN200 input. */
    kHSP__XBAR_2_InputHspFlexio2TrigOut1 = 201|0x40000U, /**< HSP_FLEXIO2_TRIG_OUT1 output assigned to HSP_XBAR_2_IN201 input. */
    kHSP__XBAR_2_InputHspFlexio2TrigOut2 = 202|0x40000U, /**< HSP_FLEXIO2_TRIG_OUT2 output assigned to HSP_XBAR_2_IN202 input. */
    kHSP__XBAR_2_InputHspFlexio2TrigOut3 = 203|0x40000U, /**< HSP_FLEXIO2_TRIG_OUT3 output assigned to HSP_XBAR_2_IN203 input. */
    kHSP__XBAR_2_InputHspLpi2c0TrigOut = 204|0x40000U, /**< HSP_LPI2C0_TRIG_OUT output assigned to HSP_XBAR_2_IN204 input. */
    kHSP__XBAR_2_InputHspLpi2c0MstBusy = 205|0x40000U, /**< HSP_LPI2C0_MST_BUSY output assigned to HSP_XBAR_2_IN205 input. */
    kHSP__XBAR_2_InputHspLpi2c0BusBusy = 206|0x40000U, /**< HSP_LPI2C0_BUS_BUSY output assigned to HSP_XBAR_2_IN206 input. */
    kHSP__XBAR_2_InputHspLpi2c1TrigOut = 207|0x40000U, /**< HSP_LPI2C1_TRIG_OUT output assigned to HSP_XBAR_2_IN207 input. */
    kHSP__XBAR_2_InputHspLpi2c1MstBusy = 208|0x40000U, /**< HSP_LPI2C1_MST_BUSY output assigned to HSP_XBAR_2_IN208 input. */
    kHSP__XBAR_2_InputHspLpi2c1BusBusy = 209|0x40000U, /**< HSP_LPI2C1_BUS_BUSY output assigned to HSP_XBAR_2_IN209 input. */
    kHSP__XBAR_2_InputRESERVED210   = 210|0x40000U, /**< HSP_XBAR_2_IN210 input is reserved. */
    kHSP__XBAR_2_InputRESERVED211   = 211|0x40000U, /**< HSP_XBAR_2_IN211 input is reserved. */
    kHSP__XBAR_2_InputRESERVED212   = 212|0x40000U, /**< HSP_XBAR_2_IN212 input is reserved. */
    kHSP__XBAR_2_InputRESERVED213   = 213|0x40000U, /**< HSP_XBAR_2_IN213 input is reserved. */
    kHSP__XBAR_2_InputRESERVED214   = 214|0x40000U, /**< HSP_XBAR_2_IN214 input is reserved. */
    kHSP__XBAR_2_InputRESERVED215   = 215|0x40000U, /**< HSP_XBAR_2_IN215 input is reserved. */
    kHSP__XBAR_2_InputHspLpspi0EndOfFrame = 216|0x40000U, /**< HSP_LPSPI0_END_OF_FRAME output assigned to HSP_XBAR_2_IN216 input. */
    kHSP__XBAR_2_InputHspLpspi0EndOfWord = 217|0x40000U, /**< HSP_LPSPI0_END_OF_WORD output assigned to HSP_XBAR_2_IN217 input. */
    kHSP__XBAR_2_InputHspLpspi1EndOfFrame = 218|0x40000U, /**< HSP_LPSPI1_END_OF_FRAME output assigned to HSP_XBAR_2_IN218 input. */
    kHSP__XBAR_2_InputHspLpspi1EndOfWord = 219|0x40000U, /**< HSP_LPSPI1_END_OF_WORD output assigned to HSP_XBAR_2_IN219 input. */
    kHSP__XBAR_2_InputHspLpspi2EndOfFrame = 220|0x40000U, /**< HSP_LPSPI2_END_OF_FRAME output assigned to HSP_XBAR_2_IN220 input. */
    kHSP__XBAR_2_InputHspLpspi2EndOfWord = 221|0x40000U, /**< HSP_LPSPI2_END_OF_WORD output assigned to HSP_XBAR_2_IN221 input. */
    kHSP__XBAR_2_InputHspLpspi3EndOfFrame = 222|0x40000U, /**< HSP_LPSPI3_END_OF_FRAME output assigned to HSP_XBAR_2_IN222 input. */
    kHSP__XBAR_2_InputHspLpspi3EndOfWord = 223|0x40000U, /**< HSP_LPSPI3_END_OF_WORD output assigned to HSP_XBAR_2_IN223 input. */
    kHSP__XBAR_2_InputHspLpspi4EndOfFrame = 224|0x40000U, /**< HSP_LPSPI4_END_OF_FRAME output assigned to HSP_XBAR_2_IN224 input. */
    kHSP__XBAR_2_InputHspLpspi4EndOfWord = 225|0x40000U, /**< HSP_LPSPI4_END_OF_WORD output assigned to HSP_XBAR_2_IN225 input. */
    kHSP__XBAR_2_InputHspLpuart0TxEndOfWord = 226|0x40000U, /**< HSP_LPUART0_TX_END_OF_WORD output assigned to HSP_XBAR_2_IN226 input. */
    kHSP__XBAR_2_InputHspLpuart0RxEndOfWord = 227|0x40000U, /**< HSP_LPUART0_RX_END_OF_WORD output assigned to HSP_XBAR_2_IN227 input. */
    kHSP__XBAR_2_InputHspLpuart0RxIdle = 228|0x40000U, /**< HSP_LPUART0_RX_IDLE output assigned to HSP_XBAR_2_IN228 input. */
    kHSP__XBAR_2_InputHspLpuart0TxData = 229|0x40000U, /**< HSP_LPUART0_TX_DATA output assigned to HSP_XBAR_2_IN229 input. */
    kHSP__XBAR_2_InputHspLpuart1TxEndOfWord = 230|0x40000U, /**< HSP_LPUART1_TX_END_OF_WORD output assigned to HSP_XBAR_2_IN230 input. */
    kHSP__XBAR_2_InputHspLpuart1RxEndOfWord = 231|0x40000U, /**< HSP_LPUART1_RX_END_OF_WORD output assigned to HSP_XBAR_2_IN231 input. */
    kHSP__XBAR_2_InputHspLpuart1RxIdle = 232|0x40000U, /**< HSP_LPUART1_RX_IDLE output assigned to HSP_XBAR_2_IN232 input. */
    kHSP__XBAR_2_InputHspLpuart1TxData = 233|0x40000U, /**< HSP_LPUART1_TX_DATA output assigned to HSP_XBAR_2_IN233 input. */
    kHSP__XBAR_2_InputHspLpuart2TxEndOfWord = 234|0x40000U, /**< HSP_LPUART2_TX_END_OF_WORD output assigned to HSP_XBAR_2_IN234 input. */
    kHSP__XBAR_2_InputHspLpuart2RxEndOfWord = 235|0x40000U, /**< HSP_LPUART2_RX_END_OF_WORD output assigned to HSP_XBAR_2_IN235 input. */
    kHSP__XBAR_2_InputHspLpuart2RxIdle = 236|0x40000U, /**< HSP_LPUART2_RX_IDLE output assigned to HSP_XBAR_2_IN236 input. */
    kHSP__XBAR_2_InputHspLpuart2TxData = 237|0x40000U, /**< HSP_LPUART2_TX_DATA output assigned to HSP_XBAR_2_IN237 input. */
    kHSP__XBAR_2_InputHspLpuart3TxEndOfWord = 238|0x40000U, /**< HSP_LPUART3_TX_END_OF_WORD output assigned to HSP_XBAR_2_IN238 input. */
    kHSP__XBAR_2_InputHspLpuart3RxEndOfWord = 239|0x40000U, /**< HSP_LPUART3_RX_END_OF_WORD output assigned to HSP_XBAR_2_IN239 input. */
    kHSP__XBAR_2_InputHspLpuart3RxIdle = 240|0x40000U, /**< HSP_LPUART3_RX_IDLE output assigned to HSP_XBAR_2_IN240 input. */
    kHSP__XBAR_2_InputHspLpuart3TxData = 241|0x40000U, /**< HSP_LPUART3_TX_DATA output assigned to HSP_XBAR_2_IN241 input. */
    kHSP__XBAR_2_InputHspLpuart4TxEndOfWord = 242|0x40000U, /**< HSP_LPUART4_TX_END_OF_WORD output assigned to HSP_XBAR_2_IN242 input. */
    kHSP__XBAR_2_InputHspLpuart4RxEndOfWord = 243|0x40000U, /**< HSP_LPUART4_RX_END_OF_WORD output assigned to HSP_XBAR_2_IN243 input. */
    kHSP__XBAR_2_InputHspLpuart4RxIdle = 244|0x40000U, /**< HSP_LPUART4_RX_IDLE output assigned to HSP_XBAR_2_IN244 input. */
    kHSP__XBAR_2_InputHspLpuart4TxData = 245|0x40000U, /**< HSP_LPUART4_TX_DATA output assigned to HSP_XBAR_2_IN245 input. */
    kHSP__XBAR_2_InputHspLpuart5TxEndOfWord = 246|0x40000U, /**< HSP_LPUART5_TX_END_OF_WORD output assigned to HSP_XBAR_2_IN246 input. */
    kHSP__XBAR_2_InputHspLpuart5RxEndOfWord = 247|0x40000U, /**< HSP_LPUART5_RX_END_OF_WORD output assigned to HSP_XBAR_2_IN247 input. */
    kHSP__XBAR_2_InputHspLpuart5RxIdle = 248|0x40000U, /**< HSP_LPUART5_RX_IDLE output assigned to HSP_XBAR_2_IN248 input. */
    kHSP__XBAR_2_InputHspLpuart5TxData = 249|0x40000U, /**< HSP_LPUART5_TX_DATA output assigned to HSP_XBAR_2_IN249 input. */
    kHSP__XBAR_2_InputHspGpio0TrigOut0 = 250|0x40000U, /**< HSP_GPIO0_TRIG_OUT0 output assigned to HSP_XBAR_2_IN250 input. */
    kHSP__XBAR_2_InputHspGpio0TrigOut1 = 251|0x40000U, /**< HSP_GPIO0_TRIG_OUT1 output assigned to HSP_XBAR_2_IN251 input. */
    kHSP__XBAR_2_InputHspGpio1TrigOut0 = 252|0x40000U, /**< HSP_GPIO1_TRIG_OUT0 output assigned to HSP_XBAR_2_IN252 input. */
    kHSP__XBAR_2_InputHspGpio1TrigOut1 = 253|0x40000U, /**< HSP_GPIO1_TRIG_OUT1 output assigned to HSP_XBAR_2_IN253 input. */
    kHSP__XBAR_2_InputHspGpio2TrigOut0 = 254|0x40000U, /**< HSP_GPIO2_TRIG_OUT0 output assigned to HSP_XBAR_2_IN254 input. */
    kHSP__XBAR_2_InputHspGpio2TrigOut1 = 255|0x40000U, /**< HSP_GPIO2_TRIG_OUT1 output assigned to HSP_XBAR_2_IN255 input. */
    kHSP__XBAR_2_InputHspGpio3TrigOut0 = 256|0x40000U, /**< HSP_GPIO3_TRIG_OUT0 output assigned to HSP_XBAR_2_IN256 input. */
    kHSP__XBAR_2_InputHspGpio3TrigOut1 = 257|0x40000U, /**< HSP_GPIO3_TRIG_OUT1 output assigned to HSP_XBAR_2_IN257 input. */
    kHSP__XBAR_2_InputHspGpio4TrigOut0 = 258|0x40000U, /**< HSP_GPIO4_TRIG_OUT0 output assigned to HSP_XBAR_2_IN258 input. */
    kHSP__XBAR_2_InputHspGpio4TrigOut1 = 259|0x40000U, /**< HSP_GPIO4_TRIG_OUT1 output assigned to HSP_XBAR_2_IN259 input. */
    kHSP__XBAR_2_InputRESERVED260   = 260|0x40000U, /**< HSP_XBAR_2_IN260 input is reserved. */
    kHSP__XBAR_2_InputRESERVED261   = 261|0x40000U, /**< HSP_XBAR_2_IN261 input is reserved. */
    kHSP__XBAR_2_InputRESERVED262   = 262|0x40000U, /**< HSP_XBAR_2_IN262 input is reserved. */
    kHSP__XBAR_2_InputRESERVED263   = 263|0x40000U, /**< HSP_XBAR_2_IN263 input is reserved. */
    kHSP__XBAR_2_InputCommUsb0Sof   = 264|0x40000U, /**< COMM_USB0_SOF output assigned to HSP_XBAR_2_IN264 input. */
    kHSP__XBAR_2_InputCommUsb1Sof   = 265|0x40000U, /**< COMM_USB1_SOF output assigned to HSP_XBAR_2_IN265 input. */
    kHSP__XBAR_2_InputCommEnet0PpsCh0 = 266|0x40000U, /**< COMM_ENET0_PPS_CH0 output assigned to HSP_XBAR_2_IN266 input. */
    kHSP__XBAR_2_InputCommEnet0PpsCh1 = 267|0x40000U, /**< COMM_ENET0_PPS_CH1 output assigned to HSP_XBAR_2_IN267 input. */
    kHSP__XBAR_2_InputCommEnet0PpsCh2 = 268|0x40000U, /**< COMM_ENET0_PPS_CH2 output assigned to HSP_XBAR_2_IN268 input. */
    kHSP__XBAR_2_InputCommEnet0PpsCh3 = 269|0x40000U, /**< COMM_ENET0_PPS_CH3 output assigned to HSP_XBAR_2_IN269 input. */
    kHSP__XBAR_2_InputCommEth1Ieee1588TimerOut0 = 270|0x40000U, /**< COMM_ETH1_IEEE_1588_TIMER_OUT0 output assigned to HSP_XBAR_2_IN270 input. */
    kHSP__XBAR_2_InputCommEth1Ieee1588TimerOut1 = 271|0x40000U, /**< COMM_ETH1_IEEE_1588_TIMER_OUT1 output assigned to HSP_XBAR_2_IN271 input. */
    kHSP__XBAR_2_InputCommEth1Ieee1588TimerOut2 = 272|0x40000U, /**< COMM_ETH1_IEEE_1588_TIMER_OUT2 output assigned to HSP_XBAR_2_IN272 input. */
    kHSP__XBAR_2_InputCommEth1Ieee1588TimerOut3 = 273|0x40000U, /**< COMM_ETH1_IEEE_1588_TIMER_OUT3 output assigned to HSP_XBAR_2_IN273 input. */
    kHSP__XBAR_2_InputRESERVED274   = 274|0x40000U, /**< HSP_XBAR_2_IN274 input is reserved. */
    kHSP__XBAR_2_InputCommXenophy0TxFrame = 275|0x40000U, /**< COMM_XENOPHY0_TX_FRAME output assigned to HSP_XBAR_2_IN275 input. */
    kHSP__XBAR_2_InputCommXenophy0RxFrame = 276|0x40000U, /**< COMM_XENOPHY0_RX_FRAME output assigned to HSP_XBAR_2_IN276 input. */
    kHSP__XBAR_2_InputCommXenophy1TxFrame = 277|0x40000U, /**< COMM_XENOPHY1_TX_FRAME output assigned to HSP_XBAR_2_IN277 input. */
    kHSP__XBAR_2_InputCommXenophy1RxFrame = 278|0x40000U, /**< COMM_XENOPHY1_RX_FRAME output assigned to HSP_XBAR_2_IN278 input. */
    kHSP__XBAR_2_InputCmptCm85Txev  = 279|0x40000U, /**< CMPT_CM85_TXEV output assigned to HSP_XBAR_2_IN279 input. */
    kHSP__XBAR_2_InputRESERVED280   = 280|0x40000U, /**< HSP_XBAR_2_IN280 input is reserved. */
    kHSP__XBAR_2_InputRESERVED281   = 281|0x40000U, /**< HSP_XBAR_2_IN281 input is reserved. */
    kHSP__XBAR_2_InputRESERVED282   = 282|0x40000U, /**< HSP_XBAR_2_IN282 input is reserved. */
    kWAKE__XBAR_InputLogicLow       = 0|0x50000U,  /**< LOGIC_LOW output assigned to WAKE_XBAR_IN0 input. */
    kWAKE__XBAR_InputLogicHigh      = 1|0x50000U,  /**< LOGIC_HIGH output assigned to WAKE_XBAR_IN1 input. */
    kWAKE__XBAR_InputWakeEdmaTrigOut0 = 2|0x50000U, /**< WAKE_EDMA_TRIG_OUT0 output assigned to WAKE_XBAR_IN2 input. */
    kWAKE__XBAR_InputWakeEdmaIdle   = 3|0x50000U,  /**< WAKE_EDMA_IDLE output assigned to WAKE_XBAR_IN3 input. */
    kWAKE__XBAR_InputWakeAcmp0Cout  = 4|0x50000U,  /**< WAKE_ACMP0_COUT output assigned to WAKE_XBAR_IN4 input. */
    kWAKE__XBAR_InputWakeAcmp1Cout  = 5|0x50000U,  /**< WAKE_ACMP1_COUT output assigned to WAKE_XBAR_IN5 input. */
    kWAKE__XBAR_InputWakeAcmp2Cout  = 6|0x50000U,  /**< WAKE_ACMP2_COUT output assigned to WAKE_XBAR_IN6 input. */
    kWAKE__XBAR_InputWakeAcmp3Cout  = 7|0x50000U,  /**< WAKE_ACMP3_COUT output assigned to WAKE_XBAR_IN7 input. */
    kWAKE__XBAR_InputWakeLptmr0TrigOut = 8|0x50000U, /**< WAKE_LPTMR0_TRIG_OUT output assigned to WAKE_XBAR_IN8 input. */
    kWAKE__XBAR_InputWakeLptmr1TrigOut = 9|0x50000U, /**< WAKE_LPTMR1_TRIG_OUT output assigned to WAKE_XBAR_IN9 input. */
    kWAKE__XBAR_InputWakeQuadtpmCntTrigOut0 = 10|0x50000U, /**< WAKE_QUADTPM_CNT_TRIG_OUT0 output assigned to WAKE_XBAR_IN10 input. */
    kWAKE__XBAR_InputWakeQuadtpmCntTrigOut1 = 11|0x50000U, /**< WAKE_QUADTPM_CNT_TRIG_OUT1 output assigned to WAKE_XBAR_IN11 input. */
    kWAKE__XBAR_InputWakeQuadtpmCntTrigOut2 = 12|0x50000U, /**< WAKE_QUADTPM_CNT_TRIG_OUT2 output assigned to WAKE_XBAR_IN12 input. */
    kWAKE__XBAR_InputWakeQuadtpmCntTrigOut3 = 13|0x50000U, /**< WAKE_QUADTPM_CNT_TRIG_OUT3 output assigned to WAKE_XBAR_IN13 input. */
    kWAKE__XBAR_InputWakeQuadtpmChTrigOut0 = 14|0x50000U, /**< WAKE_QUADTPM_CH_TRIG_OUT0 output assigned to WAKE_XBAR_IN14 input. */
    kWAKE__XBAR_InputWakeQuadtpmChTrigOut1 = 15|0x50000U, /**< WAKE_QUADTPM_CH_TRIG_OUT1 output assigned to WAKE_XBAR_IN15 input. */
    kWAKE__XBAR_InputWakeQuadtpmChTrigOut2 = 16|0x50000U, /**< WAKE_QUADTPM_CH_TRIG_OUT2 output assigned to WAKE_XBAR_IN16 input. */
    kWAKE__XBAR_InputWakeQuadtpmChTrigOut3 = 17|0x50000U, /**< WAKE_QUADTPM_CH_TRIG_OUT3 output assigned to WAKE_XBAR_IN17 input. */
    kWAKE__XBAR_InputWakeQuadtpmChTrigOut4 = 18|0x50000U, /**< WAKE_QUADTPM_CH_TRIG_OUT4 output assigned to WAKE_XBAR_IN18 input. */
    kWAKE__XBAR_InputWakeQuadtpmChTrigOut5 = 19|0x50000U, /**< WAKE_QUADTPM_CH_TRIG_OUT5 output assigned to WAKE_XBAR_IN19 input. */
    kWAKE__XBAR_InputWakeQuadtpmChTrigOut6 = 20|0x50000U, /**< WAKE_QUADTPM_CH_TRIG_OUT6 output assigned to WAKE_XBAR_IN20 input. */
    kWAKE__XBAR_InputWakeQuadtpmChTrigOut7 = 21|0x50000U, /**< WAKE_QUADTPM_CH_TRIG_OUT7 output assigned to WAKE_XBAR_IN21 input. */
    kWAKE__XBAR_InputWakeLpi2c0TrigOut = 22|0x50000U, /**< WAKE_LPI2C0_TRIG_OUT output assigned to WAKE_XBAR_IN22 input. */
    kWAKE__XBAR_InputWakeLpi2c0MstBusy = 23|0x50000U, /**< WAKE_LPI2C0_MST_BUSY output assigned to WAKE_XBAR_IN23 input. */
    kWAKE__XBAR_InputWakeLpi2c0BusBusy = 24|0x50000U, /**< WAKE_LPI2C0_BUS_BUSY output assigned to WAKE_XBAR_IN24 input. */
    kWAKE__XBAR_InputWakeLpi2c1TrigOut = 25|0x50000U, /**< WAKE_LPI2C1_TRIG_OUT output assigned to WAKE_XBAR_IN25 input. */
    kWAKE__XBAR_InputWakeLpi2c1MstBusy = 26|0x50000U, /**< WAKE_LPI2C1_MST_BUSY output assigned to WAKE_XBAR_IN26 input. */
    kWAKE__XBAR_InputWakeLpi2c1BusBusy = 27|0x50000U, /**< WAKE_LPI2C1_BUS_BUSY output assigned to WAKE_XBAR_IN27 input. */
    kWAKE__XBAR_InputWakeLpspiEndOfFrame = 28|0x50000U, /**< WAKE_LPSPI_END_OF_FRAME output assigned to WAKE_XBAR_IN28 input. */
    kWAKE__XBAR_InputWakeLpspiEndOfWord = 29|0x50000U, /**< WAKE_LPSPI_END_OF_WORD output assigned to WAKE_XBAR_IN29 input. */
    kWAKE__XBAR_InputWakeLpuart0TxEndOfWord = 30|0x50000U, /**< WAKE_LPUART0_TX_END_OF_WORD output assigned to WAKE_XBAR_IN30 input. */
    kWAKE__XBAR_InputWakeLpuart0RxEndOfWord = 31|0x50000U, /**< WAKE_LPUART0_RX_END_OF_WORD output assigned to WAKE_XBAR_IN31 input. */
    kWAKE__XBAR_InputWakeLpuart0RxIdle = 32|0x50000U, /**< WAKE_LPUART0_RX_IDLE output assigned to WAKE_XBAR_IN32 input. */
    kWAKE__XBAR_InputWakeLpuart0TxData = 33|0x50000U, /**< WAKE_LPUART0_TX_DATA output assigned to WAKE_XBAR_IN33 input. */
    kWAKE__XBAR_InputWakeLpuart1TxEndOfWord = 34|0x50000U, /**< WAKE_LPUART1_TX_END_OF_WORD output assigned to WAKE_XBAR_IN34 input. */
    kWAKE__XBAR_InputWakeLpuart1RxEndOfWord = 35|0x50000U, /**< WAKE_LPUART1_RX_END_OF_WORD output assigned to WAKE_XBAR_IN35 input. */
    kWAKE__XBAR_InputWakeLpuart1RxIdle = 36|0x50000U, /**< WAKE_LPUART1_RX_IDLE output assigned to WAKE_XBAR_IN36 input. */
    kWAKE__XBAR_InputWakeLpuart1TxData = 37|0x50000U, /**< WAKE_LPUART1_TX_DATA output assigned to WAKE_XBAR_IN37 input. */
    kWAKE__XBAR_InputWakeMicfilMicFilter = 38|0x50000U, /**< WAKE_MICFIL_MIC_FILTER output assigned to WAKE_XBAR_IN38 input. */
    kWAKE__XBAR_InputWakeMicfilHwvadEvert = 39|0x50000U, /**< WAKE_MICFIL_HWVAD_EVERT output assigned to WAKE_XBAR_IN39 input. */
    kWAKE__XBAR_InputWakeGpioTrigOut0 = 40|0x50000U, /**< WAKE_GPIO_TRIG_OUT0 output assigned to WAKE_XBAR_IN40 input. */
    kWAKE__XBAR_InputWakeGpioTrigOut1 = 41|0x50000U, /**< WAKE_GPIO_TRIG_OUT1 output assigned to WAKE_XBAR_IN41 input. */
    kWAKE__XBAR_InputVbatTdetTemperOut = 42|0x50000U, /**< VBAT_TDET_TEMPER_OUT output assigned to WAKE_XBAR_IN42 input. */
    kWAKE__XBAR_InputVbatLptmrTrigOut = 43|0x50000U, /**< VBAT_LPTMR_TRIG_OUT output assigned to WAKE_XBAR_IN43 input. */
    kWAKE__XBAR_InputVbatRtcCalOut  = 44|0x50000U, /**< VBAT_RTC_CAL_OUT output assigned to WAKE_XBAR_IN44 input. */
    kWAKE__XBAR_InputVbatRtcAlarm   = 45|0x50000U, /**< VBAT_RTC_ALARM output assigned to WAKE_XBAR_IN45 input. */
    kWAKE__XBAR_InputVbatRtcClkOut  = 46|0x50000U, /**< VBAT_RTC_CLK_OUT output assigned to WAKE_XBAR_IN46 input. */
    kWAKE__XBAR_InputVbatGpioTrigOut0 = 47|0x50000U, /**< VBAT_GPIO_TRIG_OUT0 output assigned to WAKE_XBAR_IN47 input. */
    kWAKE__XBAR_InputVbatGpioTrigOut1 = 48|0x50000U, /**< VBAT_GPIO_TRIG_OUT1 output assigned to WAKE_XBAR_IN48 input. */
    kWAKE__XBAR_InputRESERVED49     = 49|0x50000U, /**< WAKE_XBAR_IN49 input is reserved. */
    kWAKE__XBAR_InputRESERVED50     = 50|0x50000U, /**< WAKE_XBAR_IN50 input is reserved. */
    kWAKE__XBAR_InputHspTrgsync0SyncOut0 = 51|0x50000U, /**< HSP_TRGSYNC0_SYNC_OUT0 output assigned to WAKE_XBAR_IN51 input. */
    kWAKE__XBAR_InputHspTrgsync0SyncOut1 = 52|0x50000U, /**< HSP_TRGSYNC0_SYNC_OUT1 output assigned to WAKE_XBAR_IN52 input. */
    kWAKE__XBAR_InputHspTrgsync0SyncOut2 = 53|0x50000U, /**< HSP_TRGSYNC0_SYNC_OUT2 output assigned to WAKE_XBAR_IN53 input. */
    kWAKE__XBAR_InputHspTrgsync0SyncOut3 = 54|0x50000U, /**< HSP_TRGSYNC0_SYNC_OUT3 output assigned to WAKE_XBAR_IN54 input. */
    kWAKE__XBAR_InputHspTrgsync0SyncOut4 = 55|0x50000U, /**< HSP_TRGSYNC0_SYNC_OUT4 output assigned to WAKE_XBAR_IN55 input. */
    kWAKE__XBAR_InputHspTrgsync0SyncOut5 = 56|0x50000U, /**< HSP_TRGSYNC0_SYNC_OUT5 output assigned to WAKE_XBAR_IN56 input. */
    kWAKE__XBAR_InputHspTrgsync0SyncOut6 = 57|0x50000U, /**< HSP_TRGSYNC0_SYNC_OUT6 output assigned to WAKE_XBAR_IN57 input. */
    kWAKE__XBAR_InputHspTrgsync0SyncOut7 = 58|0x50000U, /**< HSP_TRGSYNC0_SYNC_OUT7 output assigned to WAKE_XBAR_IN58 input. */
    kWAKE__XBAR_InputWakeXbarIn0    = 59|0x50000U, /**< WAKE_XBAR_IN0 output assigned to WAKE_XBAR_IN59 input. */
    kWAKE__XBAR_InputWakeXbarIn1    = 60|0x50000U, /**< WAKE_XBAR_IN1 output assigned to WAKE_XBAR_IN60 input. */
    kWAKE__XBAR_InputWakeXbarIn2    = 61|0x50000U, /**< WAKE_XBAR_IN2 output assigned to WAKE_XBAR_IN61 input. */
    kWAKE__XBAR_InputWakeXbarIn3    = 62|0x50000U, /**< WAKE_XBAR_IN3 output assigned to WAKE_XBAR_IN62 input. */
    kWAKE__XBAR_InputWakeXbarIn4    = 63|0x50000U, /**< WAKE_XBAR_IN4 output assigned to WAKE_XBAR_IN63 input. */
    kWAKE__XBAR_InputWakeXbarIn5    = 64|0x50000U, /**< WAKE_XBAR_IN5 output assigned to WAKE_XBAR_IN64 input. */
    kWAKE__XBAR_InputWakeXbarIn6    = 65|0x50000U, /**< WAKE_XBAR_IN6 output assigned to WAKE_XBAR_IN65 input. */
    kWAKE__XBAR_InputWakeXbarIn7    = 66|0x50000U, /**< WAKE_XBAR_IN7 output assigned to WAKE_XBAR_IN66 input. */
    kWAKE__XBAR_InputWakeTrgsyncSyncOut0 = 67|0x50000U, /**< WAKE_TRGSYNC_SYNC_OUT0 output assigned to WAKE_XBAR_IN67 input. */
    kWAKE__XBAR_InputWakeTrgsyncSyncOut1 = 68|0x50000U, /**< WAKE_TRGSYNC_SYNC_OUT1 output assigned to WAKE_XBAR_IN68 input. */
    kWAKE__XBAR_InputWakeTrgsyncSyncOut2 = 69|0x50000U, /**< WAKE_TRGSYNC_SYNC_OUT2 output assigned to WAKE_XBAR_IN69 input. */
    kWAKE__XBAR_InputWakeTrgsyncSyncOut3 = 70|0x50000U, /**< WAKE_TRGSYNC_SYNC_OUT3 output assigned to WAKE_XBAR_IN70 input. */
} xbar_input_signal_t;

typedef enum _xbar_output_signal
{
    kAUDIO__XBAR_OutputCommFreqmeInput = 0|0x10000U, /**< AUDIO_XBAR_OUT0 output assigned to COMM_FREQME_INPUT */
    kAUDIO__XBAR_OutputRESERVED1    = 1|0x10000U,  /**< AUDIO_XBAR_OUT1 output is reserved. */
    kAUDIO__XBAR_OutputRESERVED2    = 2|0x10000U,  /**< AUDIO_XBAR_OUT2 output is reserved. */
    kAUDIO__XBAR_OutputRESERVED3    = 3|0x10000U,  /**< AUDIO_XBAR_OUT3 output is reserved. */
    kAUDIO__XBAR_OutputRESERVED4    = 4|0x10000U,  /**< AUDIO_XBAR_OUT4 output is reserved. */
    kAUDIO__XBAR_OutputHspXbar0In74Xbar1In42 = 5|0x10000U, /**< AUDIO_XBAR_OUT5 output assigned to HSP_XBAR0_IN74_XBAR1_IN42 */
    kAUDIO__XBAR_OutputHspXbar0In75Xbar1In43 = 6|0x10000U, /**< AUDIO_XBAR_OUT6 output assigned to HSP_XBAR0_IN75_XBAR1_IN43 */
    kAUDIO__XBAR_OutputHspXbar0In76Xbar1In44 = 7|0x10000U, /**< AUDIO_XBAR_OUT7 output assigned to HSP_XBAR0_IN76_XBAR1_IN44 */
    kAUDIO__XBAR_OutputHspXbar0In77Xbar1In45 = 8|0x10000U, /**< AUDIO_XBAR_OUT8 output assigned to HSP_XBAR0_IN77_XBAR1_IN45 */
    kAUDIO__XBAR_OutputRESERVED9    = 9|0x10000U,  /**< AUDIO_XBAR_OUT9 output is reserved. */
    kAUDIO__XBAR_OutputRESERVED10   = 10|0x10000U, /**< AUDIO_XBAR_OUT10 output is reserved. */
    kHSP__XBAR_0_OutputHspXbar0Out0 = 0|0x20000U,  /**< HSP_XBAR_0_OUT0 output assigned to HSP_XBAR0_OUT0 */
    kHSP__XBAR_0_OutputHspXbar0Out1 = 1|0x20000U,  /**< HSP_XBAR_0_OUT1 output assigned to HSP_XBAR0_OUT1 */
    kHSP__XBAR_0_OutputHspXbar0Out2 = 2|0x20000U,  /**< HSP_XBAR_0_OUT2 output assigned to HSP_XBAR0_OUT2 */
    kHSP__XBAR_0_OutputHspXbar0Out3 = 3|0x20000U,  /**< HSP_XBAR_0_OUT3 output assigned to HSP_XBAR0_OUT3 */
    kHSP__XBAR_0_OutputHspXbar0Out4 = 4|0x20000U,  /**< HSP_XBAR_0_OUT4 output assigned to HSP_XBAR0_OUT4 */
    kHSP__XBAR_0_OutputHspXbar0Out5 = 5|0x20000U,  /**< HSP_XBAR_0_OUT5 output assigned to HSP_XBAR0_OUT5 */
    kHSP__XBAR_0_OutputHspXbar0Out6 = 6|0x20000U,  /**< HSP_XBAR_0_OUT6 output assigned to HSP_XBAR0_OUT6 */
    kHSP__XBAR_0_OutputHspXbar0Out7 = 7|0x20000U,  /**< HSP_XBAR_0_OUT7 output assigned to HSP_XBAR0_OUT7 */
    kHSP__XBAR_0_OutputMainFreqmeInput = 8|0x20000U, /**< HSP_XBAR_0_OUT8 output assigned to MAIN_FREQME_INPUT */
    kHSP__XBAR_0_OutputSysconFreqmeInput = 9|0x20000U, /**< HSP_XBAR_0_OUT9 output assigned to SYSCON_FREQME_INPUT */
    kHSP__XBAR_0_OutputHspAdc01Ch01TrigIn0 = 10|0x20000U, /**< HSP_XBAR_0_OUT10 output assigned to HSP_ADC0_1_CH0_1_TRIG_IN0 */
    kHSP__XBAR_0_OutputHspAdc01Ch01TrigIn1 = 11|0x20000U, /**< HSP_XBAR_0_OUT11 output assigned to HSP_ADC0_1_CH0_1_TRIG_IN1 */
    kHSP__XBAR_0_OutputHspAdc01Ch01TrigIn2 = 12|0x20000U, /**< HSP_XBAR_0_OUT12 output assigned to HSP_ADC0_1_CH0_1_TRIG_IN2 */
    kHSP__XBAR_0_OutputHspAdc01Ch01TrigIn3 = 13|0x20000U, /**< HSP_XBAR_0_OUT13 output assigned to HSP_ADC0_1_CH0_1_TRIG_IN3 */
    kHSP__XBAR_0_OutputHspAdc01Ch01TrigIn4 = 14|0x20000U, /**< HSP_XBAR_0_OUT14 output assigned to HSP_ADC0_1_CH0_1_TRIG_IN4 */
    kHSP__XBAR_0_OutputHspAdc01Ch01TrigIn5 = 15|0x20000U, /**< HSP_XBAR_0_OUT15 output assigned to HSP_ADC0_1_CH0_1_TRIG_IN5 */
    kHSP__XBAR_0_OutputHspAdc01Ch01TrigIn6 = 16|0x20000U, /**< HSP_XBAR_0_OUT16 output assigned to HSP_ADC0_1_CH0_1_TRIG_IN6 */
    kHSP__XBAR_0_OutputHspAdc01Ch01TrigIn7 = 17|0x20000U, /**< HSP_XBAR_0_OUT17 output assigned to HSP_ADC0_1_CH0_1_TRIG_IN7 */
    kHSP__XBAR_0_OutputHspAdc10Ch01TrigIn0 = 18|0x20000U, /**< HSP_XBAR_0_OUT18 output assigned to HSP_ADC1_0_CH0_1_TRIG_IN0 */
    kHSP__XBAR_0_OutputHspAdc10Ch01TrigIn1 = 19|0x20000U, /**< HSP_XBAR_0_OUT19 output assigned to HSP_ADC1_0_CH0_1_TRIG_IN1 */
    kHSP__XBAR_0_OutputHspAdc10Ch01TrigIn2 = 20|0x20000U, /**< HSP_XBAR_0_OUT20 output assigned to HSP_ADC1_0_CH0_1_TRIG_IN2 */
    kHSP__XBAR_0_OutputHspAdc10Ch01TrigIn3 = 21|0x20000U, /**< HSP_XBAR_0_OUT21 output assigned to HSP_ADC1_0_CH0_1_TRIG_IN3 */
    kHSP__XBAR_0_OutputHspAdc10Ch01TrigIn4 = 22|0x20000U, /**< HSP_XBAR_0_OUT22 output assigned to HSP_ADC1_0_CH0_1_TRIG_IN4 */
    kHSP__XBAR_0_OutputHspAdc10Ch01TrigIn5 = 23|0x20000U, /**< HSP_XBAR_0_OUT23 output assigned to HSP_ADC1_0_CH0_1_TRIG_IN5 */
    kHSP__XBAR_0_OutputHspAdc10Ch01TrigIn6 = 24|0x20000U, /**< HSP_XBAR_0_OUT24 output assigned to HSP_ADC1_0_CH0_1_TRIG_IN6 */
    kHSP__XBAR_0_OutputHspAdc10Ch01TrigIn7 = 25|0x20000U, /**< HSP_XBAR_0_OUT25 output assigned to HSP_ADC1_0_CH0_1_TRIG_IN7 */
    kHSP__XBAR_0_OutputHspDacTrigIn = 26|0x20000U, /**< HSP_XBAR_0_OUT26 output assigned to HSP_DAC_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpit0TrigIn0 = 27|0x20000U, /**< HSP_XBAR_0_OUT27 output assigned to HSP_LPIT0_TRIG_IN0 */
    kHSP__XBAR_0_OutputHspLpit0TrigIn1 = 28|0x20000U, /**< HSP_XBAR_0_OUT28 output assigned to HSP_LPIT0_TRIG_IN1 */
    kHSP__XBAR_0_OutputHspLpit0TrigIn2 = 29|0x20000U, /**< HSP_XBAR_0_OUT29 output assigned to HSP_LPIT0_TRIG_IN2 */
    kHSP__XBAR_0_OutputHspLpit0TrigIn3 = 30|0x20000U, /**< HSP_XBAR_0_OUT30 output assigned to HSP_LPIT0_TRIG_IN3 */
    kHSP__XBAR_0_OutputHspLpit1TrigIn0 = 31|0x20000U, /**< HSP_XBAR_0_OUT31 output assigned to HSP_LPIT1_TRIG_IN0 */
    kHSP__XBAR_0_OutputHspLpit1TrigIn1 = 32|0x20000U, /**< HSP_XBAR_0_OUT32 output assigned to HSP_LPIT1_TRIG_IN1 */
    kHSP__XBAR_0_OutputHspLpit1TrigIn2 = 33|0x20000U, /**< HSP_XBAR_0_OUT33 output assigned to HSP_LPIT1_TRIG_IN2 */
    kHSP__XBAR_0_OutputHspLpit1TrigIn3 = 34|0x20000U, /**< HSP_XBAR_0_OUT34 output assigned to HSP_LPIT1_TRIG_IN3 */
    kHSP__XBAR_0_OutputHspFlexpwm0FaultIn0 = 35|0x20000U, /**< HSP_XBAR_0_OUT35 output assigned to HSP_FLEXPWM0_FAULT_IN0 */
    kHSP__XBAR_0_OutputHspFlexpwm0FaultIn1 = 36|0x20000U, /**< HSP_XBAR_0_OUT36 output assigned to HSP_FLEXPWM0_FAULT_IN1 */
    kHSP__XBAR_0_OutputHspFlexpwm0FaultIn2 = 37|0x20000U, /**< HSP_XBAR_0_OUT37 output assigned to HSP_FLEXPWM0_FAULT_IN2 */
    kHSP__XBAR_0_OutputHspFlexpwm0FaultIn3 = 38|0x20000U, /**< HSP_XBAR_0_OUT38 output assigned to HSP_FLEXPWM0_FAULT_IN3 */
    kHSP__XBAR_0_OutputHspFlexpwm0ExtClk = 39|0x20000U, /**< HSP_XBAR_0_OUT39 output assigned to HSP_FLEXPWM0_EXT_CLK */
    kHSP__XBAR_0_OutputHspFlexpwm0ExtForce = 40|0x20000U, /**< HSP_XBAR_0_OUT40 output assigned to HSP_FLEXPWM0_EXT_FORCE */
    kHSP__XBAR_0_OutputHspFlexpwm0ExtSync0 = 41|0x20000U, /**< HSP_XBAR_0_OUT41 output assigned to HSP_FLEXPWM0_EXT_SYNC0 */
    kHSP__XBAR_0_OutputHspFlexpwm0ExtSync1 = 42|0x20000U, /**< HSP_XBAR_0_OUT42 output assigned to HSP_FLEXPWM0_EXT_SYNC1 */
    kHSP__XBAR_0_OutputHspFlexpwm0ExtSync2 = 43|0x20000U, /**< HSP_XBAR_0_OUT43 output assigned to HSP_FLEXPWM0_EXT_SYNC2 */
    kHSP__XBAR_0_OutputHspFlexpwm0ExtSync3 = 44|0x20000U, /**< HSP_XBAR_0_OUT44 output assigned to HSP_FLEXPWM0_EXT_SYNC3 */
    kHSP__XBAR_0_OutputHspFlexpwm0Exta0 = 45|0x20000U, /**< HSP_XBAR_0_OUT45 output assigned to HSP_FLEXPWM0_EXTA0 */
    kHSP__XBAR_0_OutputHspFlexpwm0Exta1 = 46|0x20000U, /**< HSP_XBAR_0_OUT46 output assigned to HSP_FLEXPWM0_EXTA1 */
    kHSP__XBAR_0_OutputHspFlexpwm0Exta2 = 47|0x20000U, /**< HSP_XBAR_0_OUT47 output assigned to HSP_FLEXPWM0_EXTA2 */
    kHSP__XBAR_0_OutputHspFlexpwm0Exta3 = 48|0x20000U, /**< HSP_XBAR_0_OUT48 output assigned to HSP_FLEXPWM0_EXTA3 */
    kHSP__XBAR_0_OutputHspFlexpwm1FaultIn0 = 49|0x20000U, /**< HSP_XBAR_0_OUT49 output assigned to HSP_FLEXPWM1_FAULT_IN0 */
    kHSP__XBAR_0_OutputHspFlexpwm1FaultIn1 = 50|0x20000U, /**< HSP_XBAR_0_OUT50 output assigned to HSP_FLEXPWM1_FAULT_IN1 */
    kHSP__XBAR_0_OutputHspFlexpwm1FaultIn2 = 51|0x20000U, /**< HSP_XBAR_0_OUT51 output assigned to HSP_FLEXPWM1_FAULT_IN2 */
    kHSP__XBAR_0_OutputHspFlexpwm1FaultIn3 = 52|0x20000U, /**< HSP_XBAR_0_OUT52 output assigned to HSP_FLEXPWM1_FAULT_IN3 */
    kHSP__XBAR_0_OutputHspFlexpwm1ExtClk = 53|0x20000U, /**< HSP_XBAR_0_OUT53 output assigned to HSP_FLEXPWM1_EXT_CLK */
    kHSP__XBAR_0_OutputHspFlexpwm1ExtForce = 54|0x20000U, /**< HSP_XBAR_0_OUT54 output assigned to HSP_FLEXPWM1_EXT_FORCE */
    kHSP__XBAR_0_OutputHspFlexpwm1ExtSync0 = 55|0x20000U, /**< HSP_XBAR_0_OUT55 output assigned to HSP_FLEXPWM1_EXT_SYNC0 */
    kHSP__XBAR_0_OutputHspFlexpwm1ExtSync1 = 56|0x20000U, /**< HSP_XBAR_0_OUT56 output assigned to HSP_FLEXPWM1_EXT_SYNC1 */
    kHSP__XBAR_0_OutputHspFlexpwm1ExtSync2 = 57|0x20000U, /**< HSP_XBAR_0_OUT57 output assigned to HSP_FLEXPWM1_EXT_SYNC2 */
    kHSP__XBAR_0_OutputHspFlexpwm1ExtSync3 = 58|0x20000U, /**< HSP_XBAR_0_OUT58 output assigned to HSP_FLEXPWM1_EXT_SYNC3 */
    kHSP__XBAR_0_OutputHspFlexpwm1Exta0 = 59|0x20000U, /**< HSP_XBAR_0_OUT59 output assigned to HSP_FLEXPWM1_EXTA0 */
    kHSP__XBAR_0_OutputHspFlexpwm1Exta1 = 60|0x20000U, /**< HSP_XBAR_0_OUT60 output assigned to HSP_FLEXPWM1_EXTA1 */
    kHSP__XBAR_0_OutputHspFlexpwm1Exta2 = 61|0x20000U, /**< HSP_XBAR_0_OUT61 output assigned to HSP_FLEXPWM1_EXTA2 */
    kHSP__XBAR_0_OutputHspFlexpwm1Exta3 = 62|0x20000U, /**< HSP_XBAR_0_OUT62 output assigned to HSP_FLEXPWM1_EXTA3 */
    kHSP__XBAR_0_OutputHspFlexpwm2FaultIn0 = 63|0x20000U, /**< HSP_XBAR_0_OUT63 output assigned to HSP_FLEXPWM2_FAULT_IN0 */
    kHSP__XBAR_0_OutputHspFlexpwm2FaultIn1 = 64|0x20000U, /**< HSP_XBAR_0_OUT64 output assigned to HSP_FLEXPWM2_FAULT_IN1 */
    kHSP__XBAR_0_OutputHspFlexpwm2FaultIn2 = 65|0x20000U, /**< HSP_XBAR_0_OUT65 output assigned to HSP_FLEXPWM2_FAULT_IN2 */
    kHSP__XBAR_0_OutputHspFlexpwm2FaultIn3 = 66|0x20000U, /**< HSP_XBAR_0_OUT66 output assigned to HSP_FLEXPWM2_FAULT_IN3 */
    kHSP__XBAR_0_OutputHspFlexpwm2ExtClk = 67|0x20000U, /**< HSP_XBAR_0_OUT67 output assigned to HSP_FLEXPWM2_EXT_CLK */
    kHSP__XBAR_0_OutputHspFlexpwm2ExtForce = 68|0x20000U, /**< HSP_XBAR_0_OUT68 output assigned to HSP_FLEXPWM2_EXT_FORCE */
    kHSP__XBAR_0_OutputHspFlexpwm2ExtSync0 = 69|0x20000U, /**< HSP_XBAR_0_OUT69 output assigned to HSP_FLEXPWM2_EXT_SYNC0 */
    kHSP__XBAR_0_OutputHspFlexpwm2ExtSync1 = 70|0x20000U, /**< HSP_XBAR_0_OUT70 output assigned to HSP_FLEXPWM2_EXT_SYNC1 */
    kHSP__XBAR_0_OutputHspFlexpwm2ExtSync2 = 71|0x20000U, /**< HSP_XBAR_0_OUT71 output assigned to HSP_FLEXPWM2_EXT_SYNC2 */
    kHSP__XBAR_0_OutputHspFlexpwm2ExtSync3 = 72|0x20000U, /**< HSP_XBAR_0_OUT72 output assigned to HSP_FLEXPWM2_EXT_SYNC3 */
    kHSP__XBAR_0_OutputHspFlexpwm2Exta0 = 73|0x20000U, /**< HSP_XBAR_0_OUT73 output assigned to HSP_FLEXPWM2_EXTA0 */
    kHSP__XBAR_0_OutputHspFlexpwm2Exta1 = 74|0x20000U, /**< HSP_XBAR_0_OUT74 output assigned to HSP_FLEXPWM2_EXTA1 */
    kHSP__XBAR_0_OutputHspFlexpwm2Exta2 = 75|0x20000U, /**< HSP_XBAR_0_OUT75 output assigned to HSP_FLEXPWM2_EXTA2 */
    kHSP__XBAR_0_OutputHspFlexpwm2Exta3 = 76|0x20000U, /**< HSP_XBAR_0_OUT76 output assigned to HSP_FLEXPWM2_EXTA3 */
    kHSP__XBAR_0_OutputHspFlexpwm3FaultIn0 = 77|0x20000U, /**< HSP_XBAR_0_OUT77 output assigned to HSP_FLEXPWM3_FAULT_IN0 */
    kHSP__XBAR_0_OutputHspFlexpwm3FaultIn1 = 78|0x20000U, /**< HSP_XBAR_0_OUT78 output assigned to HSP_FLEXPWM3_FAULT_IN1 */
    kHSP__XBAR_0_OutputHspFlexpwm3FaultIn2 = 79|0x20000U, /**< HSP_XBAR_0_OUT79 output assigned to HSP_FLEXPWM3_FAULT_IN2 */
    kHSP__XBAR_0_OutputHspFlexpwm3FaultIn3 = 80|0x20000U, /**< HSP_XBAR_0_OUT80 output assigned to HSP_FLEXPWM3_FAULT_IN3 */
    kHSP__XBAR_0_OutputHspFlexpwm3ExtClk = 81|0x20000U, /**< HSP_XBAR_0_OUT81 output assigned to HSP_FLEXPWM3_EXT_CLK */
    kHSP__XBAR_0_OutputHspFlexpwm3ExtForce = 82|0x20000U, /**< HSP_XBAR_0_OUT82 output assigned to HSP_FLEXPWM3_EXT_FORCE */
    kHSP__XBAR_0_OutputHspFlexpwm3ExtSync0 = 83|0x20000U, /**< HSP_XBAR_0_OUT83 output assigned to HSP_FLEXPWM3_EXT_SYNC0 */
    kHSP__XBAR_0_OutputHspFlexpwm3ExtSync1 = 84|0x20000U, /**< HSP_XBAR_0_OUT84 output assigned to HSP_FLEXPWM3_EXT_SYNC1 */
    kHSP__XBAR_0_OutputHspFlexpwm3ExtSync2 = 85|0x20000U, /**< HSP_XBAR_0_OUT85 output assigned to HSP_FLEXPWM3_EXT_SYNC2 */
    kHSP__XBAR_0_OutputHspFlexpwm3ExtSync3 = 86|0x20000U, /**< HSP_XBAR_0_OUT86 output assigned to HSP_FLEXPWM3_EXT_SYNC3 */
    kHSP__XBAR_0_OutputHspFlexpwm3Exta0 = 87|0x20000U, /**< HSP_XBAR_0_OUT87 output assigned to HSP_FLEXPWM3_EXTA0 */
    kHSP__XBAR_0_OutputHspFlexpwm3Exta1 = 88|0x20000U, /**< HSP_XBAR_0_OUT88 output assigned to HSP_FLEXPWM3_EXTA1 */
    kHSP__XBAR_0_OutputHspFlexpwm3Exta2 = 89|0x20000U, /**< HSP_XBAR_0_OUT89 output assigned to HSP_FLEXPWM3_EXTA2 */
    kHSP__XBAR_0_OutputHspFlexpwm3Exta3 = 90|0x20000U, /**< HSP_XBAR_0_OUT90 output assigned to HSP_FLEXPWM3_EXTA3 */
    kHSP__XBAR_0_OutputHspFlexpwm0123FaultIn4 = 91|0x20000U, /**< HSP_XBAR_0_OUT91 output assigned to HSP_FLEXPWM0_1_2_3_FAULT_IN4 */
    kHSP__XBAR_0_OutputHspFlexpwm0123FaultIn5 = 92|0x20000U, /**< HSP_XBAR_0_OUT92 output assigned to HSP_FLEXPWM0_1_2_3_FAULT_IN5 */
    kHSP__XBAR_0_OutputHspFlexpwm0123FaultIn6 = 93|0x20000U, /**< HSP_XBAR_0_OUT93 output assigned to HSP_FLEXPWM0_1_2_3_FAULT_IN6 */
    kHSP__XBAR_0_OutputHspFlexpwm0123FaultIn7 = 94|0x20000U, /**< HSP_XBAR_0_OUT94 output assigned to HSP_FLEXPWM0_1_2_3_FAULT_IN7 */
    kHSP__XBAR_0_OutputHspQuadtpm0TrigIn0 = 95|0x20000U, /**< HSP_XBAR_0_OUT95 output assigned to HSP_QUADTPM0_TRIG_IN0 */
    kHSP__XBAR_0_OutputHspQuadtpm0TrigIn1 = 96|0x20000U, /**< HSP_XBAR_0_OUT96 output assigned to HSP_QUADTPM0_TRIG_IN1 */
    kHSP__XBAR_0_OutputHspQuadtpm0TrigIn2 = 97|0x20000U, /**< HSP_XBAR_0_OUT97 output assigned to HSP_QUADTPM0_TRIG_IN2 */
    kHSP__XBAR_0_OutputHspQuadtpm0TrigIn3 = 98|0x20000U, /**< HSP_XBAR_0_OUT98 output assigned to HSP_QUADTPM0_TRIG_IN3 */
    kHSP__XBAR_0_OutputRESERVED99   = 99|0x20000U, /**< HSP_XBAR_0_OUT99 output is reserved. */
    kHSP__XBAR_0_OutputRESERVED100  = 100|0x20000U, /**< HSP_XBAR_0_OUT100 output is reserved. */
    kHSP__XBAR_0_OutputRESERVED101  = 101|0x20000U, /**< HSP_XBAR_0_OUT101 output is reserved. */
    kHSP__XBAR_0_OutputRESERVED102  = 102|0x20000U, /**< HSP_XBAR_0_OUT102 output is reserved. */
    kHSP__XBAR_0_OutputRESERVED103  = 103|0x20000U, /**< HSP_XBAR_0_OUT103 output is reserved. */
    kHSP__XBAR_0_OutputRESERVED104  = 104|0x20000U, /**< HSP_XBAR_0_OUT104 output is reserved. */
    kHSP__XBAR_0_OutputRESERVED105  = 105|0x20000U, /**< HSP_XBAR_0_OUT105 output is reserved. */
    kHSP__XBAR_0_OutputRESERVED106  = 106|0x20000U, /**< HSP_XBAR_0_OUT106 output is reserved. */
    kHSP__XBAR_0_OutputHspQtmr0In0  = 107|0x20000U, /**< HSP_XBAR_0_OUT107 output assigned to HSP_QTMR0_IN0 */
    kHSP__XBAR_0_OutputHspQtmr0In1  = 108|0x20000U, /**< HSP_XBAR_0_OUT108 output assigned to HSP_QTMR0_IN1 */
    kHSP__XBAR_0_OutputHspQtmr0In2  = 109|0x20000U, /**< HSP_XBAR_0_OUT109 output assigned to HSP_QTMR0_IN2 */
    kHSP__XBAR_0_OutputHspQtmr0In3  = 110|0x20000U, /**< HSP_XBAR_0_OUT110 output assigned to HSP_QTMR0_IN3 */
    kHSP__XBAR_0_OutputHspQtmr1In0  = 111|0x20000U, /**< HSP_XBAR_0_OUT111 output assigned to HSP_QTMR1_IN0 */
    kHSP__XBAR_0_OutputHspQtmr1In1  = 112|0x20000U, /**< HSP_XBAR_0_OUT112 output assigned to HSP_QTMR1_IN1 */
    kHSP__XBAR_0_OutputHspQtmr1In2  = 113|0x20000U, /**< HSP_XBAR_0_OUT113 output assigned to HSP_QTMR1_IN2 */
    kHSP__XBAR_0_OutputHspQtmr1In3  = 114|0x20000U, /**< HSP_XBAR_0_OUT114 output assigned to HSP_QTMR1_IN3 */
    kHSP__XBAR_0_OutputHspQtmr2In0  = 115|0x20000U, /**< HSP_XBAR_0_OUT115 output assigned to HSP_QTMR2_IN0 */
    kHSP__XBAR_0_OutputHspQtmr2In1  = 116|0x20000U, /**< HSP_XBAR_0_OUT116 output assigned to HSP_QTMR2_IN1 */
    kHSP__XBAR_0_OutputHspQtmr2In2  = 117|0x20000U, /**< HSP_XBAR_0_OUT117 output assigned to HSP_QTMR2_IN2 */
    kHSP__XBAR_0_OutputHspQtmr2In3  = 118|0x20000U, /**< HSP_XBAR_0_OUT118 output assigned to HSP_QTMR2_IN3 */
    kHSP__XBAR_0_OutputHspQtmr3In0  = 119|0x20000U, /**< HSP_XBAR_0_OUT119 output assigned to HSP_QTMR3_IN0 */
    kHSP__XBAR_0_OutputHspQtmr3In1  = 120|0x20000U, /**< HSP_XBAR_0_OUT120 output assigned to HSP_QTMR3_IN1 */
    kHSP__XBAR_0_OutputHspQtmr3In2  = 121|0x20000U, /**< HSP_XBAR_0_OUT121 output assigned to HSP_QTMR3_IN2 */
    kHSP__XBAR_0_OutputHspQtmr3In3  = 122|0x20000U, /**< HSP_XBAR_0_OUT122 output assigned to HSP_QTMR3_IN3 */
    kHSP__XBAR_0_OutputHspEqdc0PhaseAIn = 123|0x20000U, /**< HSP_XBAR_0_OUT123 output assigned to HSP_EQDC0_PHASE_A_IN */
    kHSP__XBAR_0_OutputHspEqdc0PhaseBIn = 124|0x20000U, /**< HSP_XBAR_0_OUT124 output assigned to HSP_EQDC0_PHASE_B_IN */
    kHSP__XBAR_0_OutputHspEqdc0IndexIn = 125|0x20000U, /**< HSP_XBAR_0_OUT125 output assigned to HSP_EQDC0_INDEX_IN */
    kHSP__XBAR_0_OutputHspEqdc0HomeIn = 126|0x20000U, /**< HSP_XBAR_0_OUT126 output assigned to HSP_EQDC0_HOME_IN */
    kHSP__XBAR_0_OutputHspEqdc0TrigIn = 127|0x20000U, /**< HSP_XBAR_0_OUT127 output assigned to HSP_EQDC0_TRIG_IN */
    kHSP__XBAR_0_OutputHspEqdc0Capture1 = 128|0x20000U, /**< HSP_XBAR_0_OUT128 output assigned to HSP_EQDC0_CAPTURE1 */
    kHSP__XBAR_0_OutputHspEqdc0Capture2 = 129|0x20000U, /**< HSP_XBAR_0_OUT129 output assigned to HSP_EQDC0_CAPTURE2 */
    kHSP__XBAR_0_OutputHspEqdc0Capture3 = 130|0x20000U, /**< HSP_XBAR_0_OUT130 output assigned to HSP_EQDC0_CAPTURE3 */
    kHSP__XBAR_0_OutputHspEqdc1PhaseAIn = 131|0x20000U, /**< HSP_XBAR_0_OUT131 output assigned to HSP_EQDC1_PHASE_A_IN */
    kHSP__XBAR_0_OutputHspEqdc1PhaseBIn = 132|0x20000U, /**< HSP_XBAR_0_OUT132 output assigned to HSP_EQDC1_PHASE_B_IN */
    kHSP__XBAR_0_OutputHspEqdc1IndexIn = 133|0x20000U, /**< HSP_XBAR_0_OUT133 output assigned to HSP_EQDC1_INDEX_IN */
    kHSP__XBAR_0_OutputHspEqdc1HomeIn = 134|0x20000U, /**< HSP_XBAR_0_OUT134 output assigned to HSP_EQDC1_HOME_IN */
    kHSP__XBAR_0_OutputHspEqdc1TrigIn = 135|0x20000U, /**< HSP_XBAR_0_OUT135 output assigned to HSP_EQDC1_TRIG_IN */
    kHSP__XBAR_0_OutputHspEqdc1Capture1 = 136|0x20000U, /**< HSP_XBAR_0_OUT136 output assigned to HSP_EQDC1_CAPTURE1 */
    kHSP__XBAR_0_OutputHspEqdc1Capture2 = 137|0x20000U, /**< HSP_XBAR_0_OUT137 output assigned to HSP_EQDC1_CAPTURE2 */
    kHSP__XBAR_0_OutputHspEqdc1Capture3 = 138|0x20000U, /**< HSP_XBAR_0_OUT138 output assigned to HSP_EQDC1_CAPTURE3 */
    kHSP__XBAR_0_OutputHspEqdc2PhaseAIn = 139|0x20000U, /**< HSP_XBAR_0_OUT139 output assigned to HSP_EQDC2_PHASE_A_IN */
    kHSP__XBAR_0_OutputHspEqdc2PhaseBIn = 140|0x20000U, /**< HSP_XBAR_0_OUT140 output assigned to HSP_EQDC2_PHASE_B_IN */
    kHSP__XBAR_0_OutputHspEqdc2IndexIn = 141|0x20000U, /**< HSP_XBAR_0_OUT141 output assigned to HSP_EQDC2_INDEX_IN */
    kHSP__XBAR_0_OutputHspEqdc2HomeIn = 142|0x20000U, /**< HSP_XBAR_0_OUT142 output assigned to HSP_EQDC2_HOME_IN */
    kHSP__XBAR_0_OutputHspEqdc2TrigIn = 143|0x20000U, /**< HSP_XBAR_0_OUT143 output assigned to HSP_EQDC2_TRIG_IN */
    kHSP__XBAR_0_OutputHspEqdc2Capture1 = 144|0x20000U, /**< HSP_XBAR_0_OUT144 output assigned to HSP_EQDC2_CAPTURE1 */
    kHSP__XBAR_0_OutputHspEqdc2Capture2 = 145|0x20000U, /**< HSP_XBAR_0_OUT145 output assigned to HSP_EQDC2_CAPTURE2 */
    kHSP__XBAR_0_OutputHspEqdc2Capture3 = 146|0x20000U, /**< HSP_XBAR_0_OUT146 output assigned to HSP_EQDC2_CAPTURE3 */
    kHSP__XBAR_0_OutputHspEqdc3PhaseAIn = 147|0x20000U, /**< HSP_XBAR_0_OUT147 output assigned to HSP_EQDC3_PHASE_A_IN */
    kHSP__XBAR_0_OutputHspEqdc3PhaseBIn = 148|0x20000U, /**< HSP_XBAR_0_OUT148 output assigned to HSP_EQDC3_PHASE_B_IN */
    kHSP__XBAR_0_OutputHspEqdc3IndexIn = 149|0x20000U, /**< HSP_XBAR_0_OUT149 output assigned to HSP_EQDC3_INDEX_IN */
    kHSP__XBAR_0_OutputHspEqdc3HomeIn = 150|0x20000U, /**< HSP_XBAR_0_OUT150 output assigned to HSP_EQDC3_HOME_IN */
    kHSP__XBAR_0_OutputHspEqdc3TrigIn = 151|0x20000U, /**< HSP_XBAR_0_OUT151 output assigned to HSP_EQDC3_TRIG_IN */
    kHSP__XBAR_0_OutputHspEqdc3Capture1 = 152|0x20000U, /**< HSP_XBAR_0_OUT152 output assigned to HSP_EQDC3_CAPTURE1 */
    kHSP__XBAR_0_OutputHspEqdc3Capture2 = 153|0x20000U, /**< HSP_XBAR_0_OUT153 output assigned to HSP_EQDC3_CAPTURE2 */
    kHSP__XBAR_0_OutputHspEqdc3Capture3 = 154|0x20000U, /**< HSP_XBAR_0_OUT154 output assigned to HSP_EQDC3_CAPTURE3 */
    kHSP__XBAR_0_OutputHspSinc0TrigIn0 = 155|0x20000U, /**< HSP_XBAR_0_OUT155 output assigned to HSP_SINC0_TRIG_IN0 */
    kHSP__XBAR_0_OutputHspSinc0TrigIn1 = 156|0x20000U, /**< HSP_XBAR_0_OUT156 output assigned to HSP_SINC0_TRIG_IN1 */
    kHSP__XBAR_0_OutputHspSinc0TrigIn2 = 157|0x20000U, /**< HSP_XBAR_0_OUT157 output assigned to HSP_SINC0_TRIG_IN2 */
    kHSP__XBAR_0_OutputHspSinc0TrigIn3 = 158|0x20000U, /**< HSP_XBAR_0_OUT158 output assigned to HSP_SINC0_TRIG_IN3 */
    kHSP__XBAR_0_OutputHspSinc1TrigIn0 = 159|0x20000U, /**< HSP_XBAR_0_OUT159 output assigned to HSP_SINC1_TRIG_IN0 */
    kHSP__XBAR_0_OutputHspSinc1TrigIn1 = 160|0x20000U, /**< HSP_XBAR_0_OUT160 output assigned to HSP_SINC1_TRIG_IN1 */
    kHSP__XBAR_0_OutputHspSinc1TrigIn2 = 161|0x20000U, /**< HSP_XBAR_0_OUT161 output assigned to HSP_SINC1_TRIG_IN2 */
    kHSP__XBAR_0_OutputHspSinc1TrigIn3 = 162|0x20000U, /**< HSP_XBAR_0_OUT162 output assigned to HSP_SINC1_TRIG_IN3 */
    kHSP__XBAR_0_OutputHspSinc01ModIn0 = 163|0x20000U, /**< HSP_XBAR_0_OUT163 output assigned to HSP_SINC0_1_MOD_IN0 */
    kHSP__XBAR_0_OutputHspSinc01ModIn1 = 164|0x20000U, /**< HSP_XBAR_0_OUT164 output assigned to HSP_SINC0_1_MOD_IN1 */
    kHSP__XBAR_0_OutputHspSinc01ModIn2 = 165|0x20000U, /**< HSP_XBAR_0_OUT165 output assigned to HSP_SINC0_1_MOD_IN2 */
    kHSP__XBAR_0_OutputHspSinc01ModIn3 = 166|0x20000U, /**< HSP_XBAR_0_OUT166 output assigned to HSP_SINC0_1_MOD_IN3 */
    kHSP__XBAR_0_OutputHspFlexcan0TimeTick = 167|0x20000U, /**< HSP_XBAR_0_OUT167 output assigned to HSP_FLEXCAN0_TIME_TICK */
    kHSP__XBAR_0_OutputHspFlexcan1TimeTick = 168|0x20000U, /**< HSP_XBAR_0_OUT168 output assigned to HSP_FLEXCAN1_TIME_TICK */
    kHSP__XBAR_0_OutputHspFlexcan2TimeTick = 169|0x20000U, /**< HSP_XBAR_0_OUT169 output assigned to HSP_FLEXCAN2_TIME_TICK */
    kHSP__XBAR_0_OutputHspFlexio0TrigIn0 = 170|0x20000U, /**< HSP_XBAR_0_OUT170 output assigned to HSP_FLEXIO0_TRIG_IN0 */
    kHSP__XBAR_0_OutputHspFlexio0TrigIn1 = 171|0x20000U, /**< HSP_XBAR_0_OUT171 output assigned to HSP_FLEXIO0_TRIG_IN1 */
    kHSP__XBAR_0_OutputHspFlexio0TrigIn2 = 172|0x20000U, /**< HSP_XBAR_0_OUT172 output assigned to HSP_FLEXIO0_TRIG_IN2 */
    kHSP__XBAR_0_OutputHspFlexio0TrigIn3 = 173|0x20000U, /**< HSP_XBAR_0_OUT173 output assigned to HSP_FLEXIO0_TRIG_IN3 */
    kHSP__XBAR_0_OutputHspFlexio1TrigIn0 = 174|0x20000U, /**< HSP_XBAR_0_OUT174 output assigned to HSP_FLEXIO1_TRIG_IN0 */
    kHSP__XBAR_0_OutputHspFlexio1TrigIn1 = 175|0x20000U, /**< HSP_XBAR_0_OUT175 output assigned to HSP_FLEXIO1_TRIG_IN1 */
    kHSP__XBAR_0_OutputHspFlexio1TrigIn2 = 176|0x20000U, /**< HSP_XBAR_0_OUT176 output assigned to HSP_FLEXIO1_TRIG_IN2 */
    kHSP__XBAR_0_OutputHspFlexio1TrigIn3 = 177|0x20000U, /**< HSP_XBAR_0_OUT177 output assigned to HSP_FLEXIO1_TRIG_IN3 */
    kHSP__XBAR_0_OutputHspFlexio2TrigIn0 = 178|0x20000U, /**< HSP_XBAR_0_OUT178 output assigned to HSP_FLEXIO2_TRIG_IN0 */
    kHSP__XBAR_0_OutputHspFlexio2TrigIn1 = 179|0x20000U, /**< HSP_XBAR_0_OUT179 output assigned to HSP_FLEXIO2_TRIG_IN1 */
    kHSP__XBAR_0_OutputHspFlexio2TrigIn2 = 180|0x20000U, /**< HSP_XBAR_0_OUT180 output assigned to HSP_FLEXIO2_TRIG_IN2 */
    kHSP__XBAR_0_OutputHspFlexio2TrigIn3 = 181|0x20000U, /**< HSP_XBAR_0_OUT181 output assigned to HSP_FLEXIO2_TRIG_IN3 */
    kHSP__XBAR_0_OutputHspLpi2c0TrigIn = 182|0x20000U, /**< HSP_XBAR_0_OUT182 output assigned to HSP_LPI2C0_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpi2c1TrigIn = 183|0x20000U, /**< HSP_XBAR_0_OUT183 output assigned to HSP_LPI2C1_TRIG_IN */
    kHSP__XBAR_0_OutputRESERVED184  = 184|0x20000U, /**< HSP_XBAR_0_OUT184 output is reserved. */
    kHSP__XBAR_0_OutputRESERVED185  = 185|0x20000U, /**< HSP_XBAR_0_OUT185 output is reserved. */
    kHSP__XBAR_0_OutputHspLpspi0TrigIn = 186|0x20000U, /**< HSP_XBAR_0_OUT186 output assigned to HSP_LPSPI0_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpspi1TrigIn = 187|0x20000U, /**< HSP_XBAR_0_OUT187 output assigned to HSP_LPSPI1_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpspi2TrigIn = 188|0x20000U, /**< HSP_XBAR_0_OUT188 output assigned to HSP_LPSPI2_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpspi3TrigIn = 189|0x20000U, /**< HSP_XBAR_0_OUT189 output assigned to HSP_LPSPI3_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpspi4TrigIn = 190|0x20000U, /**< HSP_XBAR_0_OUT190 output assigned to HSP_LPSPI4_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpuart0TrigIn = 191|0x20000U, /**< HSP_XBAR_0_OUT191 output assigned to HSP_LPUART0_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpuart1TrigIn = 192|0x20000U, /**< HSP_XBAR_0_OUT192 output assigned to HSP_LPUART1_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpuart2TrigIn = 193|0x20000U, /**< HSP_XBAR_0_OUT193 output assigned to HSP_LPUART2_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpuart3TrigIn = 194|0x20000U, /**< HSP_XBAR_0_OUT194 output assigned to HSP_LPUART3_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpuart4TrigIn = 195|0x20000U, /**< HSP_XBAR_0_OUT195 output assigned to HSP_LPUART4_TRIG_IN */
    kHSP__XBAR_0_OutputHspLpuart5TrigIn = 196|0x20000U, /**< HSP_XBAR_0_OUT196 output assigned to HSP_LPUART5_TRIG_IN */
    kHSP__XBAR_0_OutputRESERVED197  = 197|0x20000U, /**< HSP_XBAR_0_OUT197 output is reserved. */
    kHSP__XBAR_0_OutputRESERVED198  = 198|0x20000U, /**< HSP_XBAR_0_OUT198 output is reserved. */
    kHSP__XBAR_0_OutputCommFreqmeInput = 199|0x20000U, /**< HSP_XBAR_0_OUT199 output assigned to COMM_FREQME_INPUT */
    kHSP__XBAR_0_OutputCommEth0AuxTsTrigIn0 = 200|0x20000U, /**< HSP_XBAR_0_OUT200 output assigned to COMM_ETH0_AUX_TS_TRIG_IN0 */
    kHSP__XBAR_0_OutputCommEth0AuxTsTrigIn1 = 201|0x20000U, /**< HSP_XBAR_0_OUT201 output assigned to COMM_ETH0_AUX_TS_TRIG_IN1 */
    kHSP__XBAR_0_OutputCommEth0AuxTsTrigIn2 = 202|0x20000U, /**< HSP_XBAR_0_OUT202 output assigned to COMM_ETH0_AUX_TS_TRIG_IN2 */
    kHSP__XBAR_0_OutputCommEth0AuxTsTrigIn3 = 203|0x20000U, /**< HSP_XBAR_0_OUT203 output assigned to COMM_ETH0_AUX_TS_TRIG_IN3 */
    kHSP__XBAR_0_OutputCommEth0McgTrigIn0 = 204|0x20000U, /**< HSP_XBAR_0_OUT204 output assigned to COMM_ETH0_MCG_TRIG_IN0 */
    kHSP__XBAR_0_OutputCommEth0McgTrigIn1 = 205|0x20000U, /**< HSP_XBAR_0_OUT205 output assigned to COMM_ETH0_MCG_TRIG_IN1 */
    kHSP__XBAR_0_OutputCommEth0McgTrigIn2 = 206|0x20000U, /**< HSP_XBAR_0_OUT206 output assigned to COMM_ETH0_MCG_TRIG_IN2 */
    kHSP__XBAR_0_OutputCommEth0McgTrigIn3 = 207|0x20000U, /**< HSP_XBAR_0_OUT207 output assigned to COMM_ETH0_MCG_TRIG_IN3 */
    kHSP__XBAR_0_OutputCommEth1Ieee1588TimerIn0 = 208|0x20000U, /**< HSP_XBAR_0_OUT208 output assigned to COMM_ETH1_IEEE_1588_TIMER_IN0 */
    kHSP__XBAR_0_OutputCommEth1Ieee1588TimerIn1 = 209|0x20000U, /**< HSP_XBAR_0_OUT209 output assigned to COMM_ETH1_IEEE_1588_TIMER_IN1 */
    kHSP__XBAR_0_OutputCommEth1Ieee1588TimerIn2 = 210|0x20000U, /**< HSP_XBAR_0_OUT210 output assigned to COMM_ETH1_IEEE_1588_TIMER_IN2 */
    kHSP__XBAR_0_OutputCommEth1Ieee1588TimerIn3 = 211|0x20000U, /**< HSP_XBAR_0_OUT211 output assigned to COMM_ETH1_IEEE_1588_TIMER_IN3 */
    kHSP__XBAR_0_OutputRESERVED212  = 212|0x20000U, /**< HSP_XBAR_0_OUT212 output is reserved. */
    kHSP__XBAR_0_OutputCmptM85Rxev  = 213|0x20000U, /**< HSP_XBAR_0_OUT213 output assigned to CMPT_M85_RXEV */
    kHSP__XBAR_0_OutputRESERVED214  = 214|0x20000U, /**< HSP_XBAR_0_OUT214 output is reserved. */
    kHSP__XBAR_0_OutputRESERVED215  = 215|0x20000U, /**< HSP_XBAR_0_OUT215 output is reserved. */
    kHSP__XBAR_0_OutputCmptLlcPmTrigIn = 216|0x20000U, /**< HSP_XBAR_0_OUT216 output assigned to CMPT_LLC_PM_TRIG_IN */
    kHSP__XBAR_0_OutputCmptFreqmeInput = 217|0x20000U, /**< HSP_XBAR_0_OUT217 output assigned to CMPT_FREQME_INPUT */
    kHSP__XBAR_0_OutputMediaFreqmeInput = 218|0x20000U, /**< HSP_XBAR_0_OUT218 output assigned to MEDIA_FREQME_INPUT */
    kHSP__XBAR_0_OutputMediaDcif0DbiIn = 219|0x20000U, /**< HSP_XBAR_0_OUT219 output assigned to MEDIA_DCIF0_DBI_IN */
    kHSP__XBAR_0_OutputRESERVED220  = 220|0x20000U, /**< HSP_XBAR_0_OUT220 output is reserved. */
    kHSP__XBAR_0_OutputHspTrgsync0SyncIn0 = 221|0x20000U, /**< HSP_XBAR_0_OUT221 output assigned to HSP_TRGSYNC0_SYNC_IN0 */
    kHSP__XBAR_0_OutputHspTrgsync0SyncIn1 = 222|0x20000U, /**< HSP_XBAR_0_OUT222 output assigned to HSP_TRGSYNC0_SYNC_IN1 */
    kHSP__XBAR_0_OutputHspTrgsync0SyncIn2 = 223|0x20000U, /**< HSP_XBAR_0_OUT223 output assigned to HSP_TRGSYNC0_SYNC_IN2 */
    kHSP__XBAR_0_OutputHspTrgsync0SyncIn3 = 224|0x20000U, /**< HSP_XBAR_0_OUT224 output assigned to HSP_TRGSYNC0_SYNC_IN3 */
    kHSP__XBAR_0_OutputHspTrgsync0SyncIn4 = 225|0x20000U, /**< HSP_XBAR_0_OUT225 output assigned to HSP_TRGSYNC0_SYNC_IN4 */
    kHSP__XBAR_0_OutputHspTrgsync0SyncIn5 = 226|0x20000U, /**< HSP_XBAR_0_OUT226 output assigned to HSP_TRGSYNC0_SYNC_IN5 */
    kHSP__XBAR_0_OutputHspTrgsync0SyncIn6 = 227|0x20000U, /**< HSP_XBAR_0_OUT227 output assigned to HSP_TRGSYNC0_SYNC_IN6 */
    kHSP__XBAR_0_OutputHspTrgsync0SyncIn7 = 228|0x20000U, /**< HSP_XBAR_0_OUT228 output assigned to HSP_TRGSYNC0_SYNC_IN7 */
    kHSP__XBAR_0_OutputHspXbar0Out8 = 229|0x20000U, /**< HSP_XBAR_0_OUT229 output assigned to HSP_XBAR0_OUT8 */
    kHSP__XBAR_0_OutputHspXbar0Out9 = 230|0x20000U, /**< HSP_XBAR_0_OUT230 output assigned to HSP_XBAR0_OUT9 */
    kHSP__XBAR_0_OutputHspXbar0Out10 = 231|0x20000U, /**< HSP_XBAR_0_OUT231 output assigned to HSP_XBAR0_OUT10 */
    kHSP__XBAR_0_OutputHspXbar0Out11 = 232|0x20000U, /**< HSP_XBAR_0_OUT232 output assigned to HSP_XBAR0_OUT11 */
    kHSP__XBAR_0_OutputHspXbar0Out12 = 233|0x20000U, /**< HSP_XBAR_0_OUT233 output assigned to HSP_XBAR0_OUT12 */
    kHSP__XBAR_0_OutputHspXbar0Out13 = 234|0x20000U, /**< HSP_XBAR_0_OUT234 output assigned to HSP_XBAR0_OUT13 */
    kHSP__XBAR_0_OutputHspXbar0Out14 = 235|0x20000U, /**< HSP_XBAR_0_OUT235 output assigned to HSP_XBAR0_OUT14 */
    kHSP__XBAR_0_OutputHspXbar0Out15 = 236|0x20000U, /**< HSP_XBAR_0_OUT236 output assigned to HSP_XBAR0_OUT15 */
    kHSP__XBAR_0_OutputHspXbar0Out16 = 237|0x20000U, /**< HSP_XBAR_0_OUT237 output assigned to HSP_XBAR0_OUT16 */
    kHSP__XBAR_0_OutputHspXbar0Out17 = 238|0x20000U, /**< HSP_XBAR_0_OUT238 output assigned to HSP_XBAR0_OUT17 */
    kHSP__XBAR_0_OutputHspXbar0Out18 = 239|0x20000U, /**< HSP_XBAR_0_OUT239 output assigned to HSP_XBAR0_OUT18 */
    kHSP__XBAR_0_OutputHspXbar0Out19 = 240|0x20000U, /**< HSP_XBAR_0_OUT240 output assigned to HSP_XBAR0_OUT19 */
    kHSP__XBAR_0_OutputHspXbar0Out20 = 241|0x20000U, /**< HSP_XBAR_0_OUT241 output assigned to HSP_XBAR0_OUT20 */
    kHSP__XBAR_0_OutputHspXbar0Out21 = 242|0x20000U, /**< HSP_XBAR_0_OUT242 output assigned to HSP_XBAR0_OUT21 */
    kHSP__XBAR_0_OutputHspXbar0Out22 = 243|0x20000U, /**< HSP_XBAR_0_OUT243 output assigned to HSP_XBAR0_OUT22 */
    kHSP__XBAR_0_OutputHspXbar0Out23 = 244|0x20000U, /**< HSP_XBAR_0_OUT244 output assigned to HSP_XBAR0_OUT23 */
    kHSP__XBAR_0_OutputHspXbar0Out24 = 245|0x20000U, /**< HSP_XBAR_0_OUT245 output assigned to HSP_XBAR0_OUT24 */
    kHSP__XBAR_0_OutputHspXbar0Out25 = 246|0x20000U, /**< HSP_XBAR_0_OUT246 output assigned to HSP_XBAR0_OUT25 */
    kHSP__XBAR_0_OutputHspXbar0Out26 = 247|0x20000U, /**< HSP_XBAR_0_OUT247 output assigned to HSP_XBAR0_OUT26 */
    kHSP__XBAR_0_OutputHspXbar0Out27 = 248|0x20000U, /**< HSP_XBAR_0_OUT248 output assigned to HSP_XBAR0_OUT27 */
    kHSP__XBAR_0_OutputHspXbar0Out28 = 249|0x20000U, /**< HSP_XBAR_0_OUT249 output assigned to HSP_XBAR0_OUT28 */
    kHSP__XBAR_0_OutputHspXbar0Out29 = 250|0x20000U, /**< HSP_XBAR_0_OUT250 output assigned to HSP_XBAR0_OUT29 */
    kHSP__XBAR_0_OutputHspXbar0Out30 = 251|0x20000U, /**< HSP_XBAR_0_OUT251 output assigned to HSP_XBAR0_OUT30 */
    kHSP__XBAR_0_OutputHspXbar0Out31 = 252|0x20000U, /**< HSP_XBAR_0_OUT252 output assigned to HSP_XBAR0_OUT31 */
    kHSP__XBAR_0_OutputHspTrgsync1SyncIn0 = 253|0x20000U, /**< HSP_XBAR_0_OUT253 output assigned to HSP_TRGSYNC1_SYNC_IN0 */
    kHSP__XBAR_0_OutputHspTrgsync1SyncIn1 = 254|0x20000U, /**< HSP_XBAR_0_OUT254 output assigned to HSP_TRGSYNC1_SYNC_IN1 */
    kHSP__XBAR_0_OutputHspTrgsync1SyncIn2 = 255|0x20000U, /**< HSP_XBAR_0_OUT255 output assigned to HSP_TRGSYNC1_SYNC_IN2 */
    kHSP__XBAR_0_OutputHspTrgsync1SyncIn3 = 256|0x20000U, /**< HSP_XBAR_0_OUT256 output assigned to HSP_TRGSYNC1_SYNC_IN3 */
    kHSP__XBAR_0_OutputHspTrgsync1SyncIn4 = 257|0x20000U, /**< HSP_XBAR_0_OUT257 output assigned to HSP_TRGSYNC1_SYNC_IN4 */
    kHSP__XBAR_0_OutputHspTrgsync1SyncIn5 = 258|0x20000U, /**< HSP_XBAR_0_OUT258 output assigned to HSP_TRGSYNC1_SYNC_IN5 */
    kHSP__XBAR_0_OutputHspTrgsync1SyncIn6 = 259|0x20000U, /**< HSP_XBAR_0_OUT259 output assigned to HSP_TRGSYNC1_SYNC_IN6 */
    kHSP__XBAR_0_OutputHspTrgsync1SyncIn7 = 260|0x20000U, /**< HSP_XBAR_0_OUT260 output assigned to HSP_TRGSYNC1_SYNC_IN7 */
    kHSP__XBAR_1_OutputHspEvtg0Ina0 = 0|0x30000U,  /**< HSP_XBAR_1_OUT0 output assigned to HSP_EVTG0_INA0 */
    kHSP__XBAR_1_OutputHspEvtg0Inb0 = 1|0x30000U,  /**< HSP_XBAR_1_OUT1 output assigned to HSP_EVTG0_INB0 */
    kHSP__XBAR_1_OutputHspEvtg0Inc0 = 2|0x30000U,  /**< HSP_XBAR_1_OUT2 output assigned to HSP_EVTG0_INC0 */
    kHSP__XBAR_1_OutputHspEvtg0Ind0 = 3|0x30000U,  /**< HSP_XBAR_1_OUT3 output assigned to HSP_EVTG0_IND0 */
    kHSP__XBAR_1_OutputHspEvtg0Ina1 = 4|0x30000U,  /**< HSP_XBAR_1_OUT4 output assigned to HSP_EVTG0_INA1 */
    kHSP__XBAR_1_OutputHspEvtg0Inb1 = 5|0x30000U,  /**< HSP_XBAR_1_OUT5 output assigned to HSP_EVTG0_INB1 */
    kHSP__XBAR_1_OutputHspEvtg0Inc1 = 6|0x30000U,  /**< HSP_XBAR_1_OUT6 output assigned to HSP_EVTG0_INC1 */
    kHSP__XBAR_1_OutputHspEvtg0Ind1 = 7|0x30000U,  /**< HSP_XBAR_1_OUT7 output assigned to HSP_EVTG0_IND1 */
    kHSP__XBAR_1_OutputHspEvtg0Ina2 = 8|0x30000U,  /**< HSP_XBAR_1_OUT8 output assigned to HSP_EVTG0_INA2 */
    kHSP__XBAR_1_OutputHspEvtg0Inb2 = 9|0x30000U,  /**< HSP_XBAR_1_OUT9 output assigned to HSP_EVTG0_INB2 */
    kHSP__XBAR_1_OutputHspEvtg0Inc2 = 10|0x30000U, /**< HSP_XBAR_1_OUT10 output assigned to HSP_EVTG0_INC2 */
    kHSP__XBAR_1_OutputHspEvtg0Ind2 = 11|0x30000U, /**< HSP_XBAR_1_OUT11 output assigned to HSP_EVTG0_IND2 */
    kHSP__XBAR_1_OutputHspEvtg0Ina3 = 12|0x30000U, /**< HSP_XBAR_1_OUT12 output assigned to HSP_EVTG0_INA3 */
    kHSP__XBAR_1_OutputHspEvtg0Inb3 = 13|0x30000U, /**< HSP_XBAR_1_OUT13 output assigned to HSP_EVTG0_INB3 */
    kHSP__XBAR_1_OutputHspEvtg0Inc3 = 14|0x30000U, /**< HSP_XBAR_1_OUT14 output assigned to HSP_EVTG0_INC3 */
    kHSP__XBAR_1_OutputHspEvtg0Ind3 = 15|0x30000U, /**< HSP_XBAR_1_OUT15 output assigned to HSP_EVTG0_IND3 */
    kHSP__XBAR_1_OutputHspEvtg1Ina0 = 16|0x30000U, /**< HSP_XBAR_1_OUT16 output assigned to HSP_EVTG1_INA0 */
    kHSP__XBAR_1_OutputHspEvtg1Inb0 = 17|0x30000U, /**< HSP_XBAR_1_OUT17 output assigned to HSP_EVTG1_INB0 */
    kHSP__XBAR_1_OutputHspEvtg1Inc0 = 18|0x30000U, /**< HSP_XBAR_1_OUT18 output assigned to HSP_EVTG1_INC0 */
    kHSP__XBAR_1_OutputHspEvtg1Ind0 = 19|0x30000U, /**< HSP_XBAR_1_OUT19 output assigned to HSP_EVTG1_IND0 */
    kHSP__XBAR_1_OutputHspEvtg1Ina1 = 20|0x30000U, /**< HSP_XBAR_1_OUT20 output assigned to HSP_EVTG1_INA1 */
    kHSP__XBAR_1_OutputHspEvtg1Inb1 = 21|0x30000U, /**< HSP_XBAR_1_OUT21 output assigned to HSP_EVTG1_INB1 */
    kHSP__XBAR_1_OutputHspEvtg1Inc1 = 22|0x30000U, /**< HSP_XBAR_1_OUT22 output assigned to HSP_EVTG1_INC1 */
    kHSP__XBAR_1_OutputHspEvtg1Ind1 = 23|0x30000U, /**< HSP_XBAR_1_OUT23 output assigned to HSP_EVTG1_IND1 */
    kHSP__XBAR_1_OutputHspEvtg1Ina2 = 24|0x30000U, /**< HSP_XBAR_1_OUT24 output assigned to HSP_EVTG1_INA2 */
    kHSP__XBAR_1_OutputHspEvtg1Inb2 = 25|0x30000U, /**< HSP_XBAR_1_OUT25 output assigned to HSP_EVTG1_INB2 */
    kHSP__XBAR_1_OutputHspEvtg1Inc2 = 26|0x30000U, /**< HSP_XBAR_1_OUT26 output assigned to HSP_EVTG1_INC2 */
    kHSP__XBAR_1_OutputHspEvtg1Ind2 = 27|0x30000U, /**< HSP_XBAR_1_OUT27 output assigned to HSP_EVTG1_IND2 */
    kHSP__XBAR_1_OutputHspEvtg1Ina3 = 28|0x30000U, /**< HSP_XBAR_1_OUT28 output assigned to HSP_EVTG1_INA3 */
    kHSP__XBAR_1_OutputHspEvtg1Inb3 = 29|0x30000U, /**< HSP_XBAR_1_OUT29 output assigned to HSP_EVTG1_INB3 */
    kHSP__XBAR_1_OutputHspEvtg1Inc3 = 30|0x30000U, /**< HSP_XBAR_1_OUT30 output assigned to HSP_EVTG1_INC3 */
    kHSP__XBAR_1_OutputHspEvtg1Ind3 = 31|0x30000U, /**< HSP_XBAR_1_OUT31 output assigned to HSP_EVTG1_IND3 */
    kHSP__XBAR_1_OutputHspEvtg2Ina0 = 32|0x30000U, /**< HSP_XBAR_1_OUT32 output assigned to HSP_EVTG2_INA0 */
    kHSP__XBAR_1_OutputHspEvtg2Inb0 = 33|0x30000U, /**< HSP_XBAR_1_OUT33 output assigned to HSP_EVTG2_INB0 */
    kHSP__XBAR_1_OutputHspEvtg2Inc0 = 34|0x30000U, /**< HSP_XBAR_1_OUT34 output assigned to HSP_EVTG2_INC0 */
    kHSP__XBAR_1_OutputHspEvtg2Ind0 = 35|0x30000U, /**< HSP_XBAR_1_OUT35 output assigned to HSP_EVTG2_IND0 */
    kHSP__XBAR_1_OutputHspEvtg2Ina1 = 36|0x30000U, /**< HSP_XBAR_1_OUT36 output assigned to HSP_EVTG2_INA1 */
    kHSP__XBAR_1_OutputHspEvtg2Inb1 = 37|0x30000U, /**< HSP_XBAR_1_OUT37 output assigned to HSP_EVTG2_INB1 */
    kHSP__XBAR_1_OutputHspEvtg2Inc1 = 38|0x30000U, /**< HSP_XBAR_1_OUT38 output assigned to HSP_EVTG2_INC1 */
    kHSP__XBAR_1_OutputHspEvtg2Ind1 = 39|0x30000U, /**< HSP_XBAR_1_OUT39 output assigned to HSP_EVTG2_IND1 */
    kHSP__XBAR_1_OutputHspEvtg2Ina2 = 40|0x30000U, /**< HSP_XBAR_1_OUT40 output assigned to HSP_EVTG2_INA2 */
    kHSP__XBAR_1_OutputHspEvtg2Inb2 = 41|0x30000U, /**< HSP_XBAR_1_OUT41 output assigned to HSP_EVTG2_INB2 */
    kHSP__XBAR_1_OutputHspEvtg2Inc2 = 42|0x30000U, /**< HSP_XBAR_1_OUT42 output assigned to HSP_EVTG2_INC2 */
    kHSP__XBAR_1_OutputHspEvtg2Ind2 = 43|0x30000U, /**< HSP_XBAR_1_OUT43 output assigned to HSP_EVTG2_IND2 */
    kHSP__XBAR_1_OutputHspEvtg2Ina3 = 44|0x30000U, /**< HSP_XBAR_1_OUT44 output assigned to HSP_EVTG2_INA3 */
    kHSP__XBAR_1_OutputHspEvtg2Inb3 = 45|0x30000U, /**< HSP_XBAR_1_OUT45 output assigned to HSP_EVTG2_INB3 */
    kHSP__XBAR_1_OutputHspEvtg2Inc3 = 46|0x30000U, /**< HSP_XBAR_1_OUT46 output assigned to HSP_EVTG2_INC3 */
    kHSP__XBAR_1_OutputHspEvtg2Ind3 = 47|0x30000U, /**< HSP_XBAR_1_OUT47 output assigned to HSP_EVTG2_IND3 */
    kHSP__XBAR_1_OutputHspEvtg3Ina0 = 48|0x30000U, /**< HSP_XBAR_1_OUT48 output assigned to HSP_EVTG3_INA0 */
    kHSP__XBAR_1_OutputHspEvtg3Inb0 = 49|0x30000U, /**< HSP_XBAR_1_OUT49 output assigned to HSP_EVTG3_INB0 */
    kHSP__XBAR_1_OutputHspEvtg3Inc0 = 50|0x30000U, /**< HSP_XBAR_1_OUT50 output assigned to HSP_EVTG3_INC0 */
    kHSP__XBAR_1_OutputHspEvtg3Ind0 = 51|0x30000U, /**< HSP_XBAR_1_OUT51 output assigned to HSP_EVTG3_IND0 */
    kHSP__XBAR_1_OutputHspEvtg3Ina1 = 52|0x30000U, /**< HSP_XBAR_1_OUT52 output assigned to HSP_EVTG3_INA1 */
    kHSP__XBAR_1_OutputHspEvtg3Inb1 = 53|0x30000U, /**< HSP_XBAR_1_OUT53 output assigned to HSP_EVTG3_INB1 */
    kHSP__XBAR_1_OutputHspEvtg3Inc1 = 54|0x30000U, /**< HSP_XBAR_1_OUT54 output assigned to HSP_EVTG3_INC1 */
    kHSP__XBAR_1_OutputHspEvtg3Ind1 = 55|0x30000U, /**< HSP_XBAR_1_OUT55 output assigned to HSP_EVTG3_IND1 */
    kHSP__XBAR_1_OutputHspEvtg3Ina2 = 56|0x30000U, /**< HSP_XBAR_1_OUT56 output assigned to HSP_EVTG3_INA2 */
    kHSP__XBAR_1_OutputHspEvtg3Inb2 = 57|0x30000U, /**< HSP_XBAR_1_OUT57 output assigned to HSP_EVTG3_INB2 */
    kHSP__XBAR_1_OutputHspEvtg3Inc2 = 58|0x30000U, /**< HSP_XBAR_1_OUT58 output assigned to HSP_EVTG3_INC2 */
    kHSP__XBAR_1_OutputHspEvtg3Ind2 = 59|0x30000U, /**< HSP_XBAR_1_OUT59 output assigned to HSP_EVTG3_IND2 */
    kHSP__XBAR_1_OutputHspEvtg3Ina3 = 60|0x30000U, /**< HSP_XBAR_1_OUT60 output assigned to HSP_EVTG3_INA3 */
    kHSP__XBAR_1_OutputHspEvtg3Inb3 = 61|0x30000U, /**< HSP_XBAR_1_OUT61 output assigned to HSP_EVTG3_INB3 */
    kHSP__XBAR_1_OutputHspEvtg3Inc3 = 62|0x30000U, /**< HSP_XBAR_1_OUT62 output assigned to HSP_EVTG3_INC3 */
    kHSP__XBAR_1_OutputHspEvtg3Ind3 = 63|0x30000U, /**< HSP_XBAR_1_OUT63 output assigned to HSP_EVTG3_IND3 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In2 = 0|0x40000U, /**< HSP_XBAR_2_OUT0 output assigned to HSP_XBAR0_XBAR1_IN2 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In3 = 1|0x40000U, /**< HSP_XBAR_2_OUT1 output assigned to HSP_XBAR0_XBAR1_IN3 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In4 = 2|0x40000U, /**< HSP_XBAR_2_OUT2 output assigned to HSP_XBAR0_XBAR1_IN4 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In5 = 3|0x40000U, /**< HSP_XBAR_2_OUT3 output assigned to HSP_XBAR0_XBAR1_IN5 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In6 = 4|0x40000U, /**< HSP_XBAR_2_OUT4 output assigned to HSP_XBAR0_XBAR1_IN6 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In7 = 5|0x40000U, /**< HSP_XBAR_2_OUT5 output assigned to HSP_XBAR0_XBAR1_IN7 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In8 = 6|0x40000U, /**< HSP_XBAR_2_OUT6 output assigned to HSP_XBAR0_XBAR1_IN8 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In9 = 7|0x40000U, /**< HSP_XBAR_2_OUT7 output assigned to HSP_XBAR0_XBAR1_IN9 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In10 = 8|0x40000U, /**< HSP_XBAR_2_OUT8 output assigned to HSP_XBAR0_XBAR1_IN10 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In11 = 9|0x40000U, /**< HSP_XBAR_2_OUT9 output assigned to HSP_XBAR0_XBAR1_IN11 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In12 = 10|0x40000U, /**< HSP_XBAR_2_OUT10 output assigned to HSP_XBAR0_XBAR1_IN12 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In13 = 11|0x40000U, /**< HSP_XBAR_2_OUT11 output assigned to HSP_XBAR0_XBAR1_IN13 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In14 = 12|0x40000U, /**< HSP_XBAR_2_OUT12 output assigned to HSP_XBAR0_XBAR1_IN14 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In15 = 13|0x40000U, /**< HSP_XBAR_2_OUT13 output assigned to HSP_XBAR0_XBAR1_IN15 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In16 = 14|0x40000U, /**< HSP_XBAR_2_OUT14 output assigned to HSP_XBAR0_XBAR1_IN16 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In17 = 15|0x40000U, /**< HSP_XBAR_2_OUT15 output assigned to HSP_XBAR0_XBAR1_IN17 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In18 = 16|0x40000U, /**< HSP_XBAR_2_OUT16 output assigned to HSP_XBAR0_XBAR1_IN18 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In19 = 17|0x40000U, /**< HSP_XBAR_2_OUT17 output assigned to HSP_XBAR0_XBAR1_IN19 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In20 = 18|0x40000U, /**< HSP_XBAR_2_OUT18 output assigned to HSP_XBAR0_XBAR1_IN20 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In21 = 19|0x40000U, /**< HSP_XBAR_2_OUT19 output assigned to HSP_XBAR0_XBAR1_IN21 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In22 = 20|0x40000U, /**< HSP_XBAR_2_OUT20 output assigned to HSP_XBAR0_XBAR1_IN22 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In23 = 21|0x40000U, /**< HSP_XBAR_2_OUT21 output assigned to HSP_XBAR0_XBAR1_IN23 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In24 = 22|0x40000U, /**< HSP_XBAR_2_OUT22 output assigned to HSP_XBAR0_XBAR1_IN24 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In25 = 23|0x40000U, /**< HSP_XBAR_2_OUT23 output assigned to HSP_XBAR0_XBAR1_IN25 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In26 = 24|0x40000U, /**< HSP_XBAR_2_OUT24 output assigned to HSP_XBAR0_XBAR1_IN26 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In27 = 25|0x40000U, /**< HSP_XBAR_2_OUT25 output assigned to HSP_XBAR0_XBAR1_IN27 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In28 = 26|0x40000U, /**< HSP_XBAR_2_OUT26 output assigned to HSP_XBAR0_XBAR1_IN28 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In29 = 27|0x40000U, /**< HSP_XBAR_2_OUT27 output assigned to HSP_XBAR0_XBAR1_IN29 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In30 = 28|0x40000U, /**< HSP_XBAR_2_OUT28 output assigned to HSP_XBAR0_XBAR1_IN30 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In31 = 29|0x40000U, /**< HSP_XBAR_2_OUT29 output assigned to HSP_XBAR0_XBAR1_IN31 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In32 = 30|0x40000U, /**< HSP_XBAR_2_OUT30 output assigned to HSP_XBAR0_XBAR1_IN32 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In33 = 31|0x40000U, /**< HSP_XBAR_2_OUT31 output assigned to HSP_XBAR0_XBAR1_IN33 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In34 = 32|0x40000U, /**< HSP_XBAR_2_OUT32 output assigned to HSP_XBAR0_XBAR1_IN34 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In35 = 33|0x40000U, /**< HSP_XBAR_2_OUT33 output assigned to HSP_XBAR0_XBAR1_IN35 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In36 = 34|0x40000U, /**< HSP_XBAR_2_OUT34 output assigned to HSP_XBAR0_XBAR1_IN36 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In37 = 35|0x40000U, /**< HSP_XBAR_2_OUT35 output assigned to HSP_XBAR0_XBAR1_IN37 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In38 = 36|0x40000U, /**< HSP_XBAR_2_OUT36 output assigned to HSP_XBAR0_XBAR1_IN38 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In39 = 37|0x40000U, /**< HSP_XBAR_2_OUT37 output assigned to HSP_XBAR0_XBAR1_IN39 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In40 = 38|0x40000U, /**< HSP_XBAR_2_OUT38 output assigned to HSP_XBAR0_XBAR1_IN40 */
    kHSP__XBAR_2_OutputHspXbar0Xbar1In41 = 39|0x40000U, /**< HSP_XBAR_2_OUT39 output assigned to HSP_XBAR0_XBAR1_IN41 */
    kWAKE__XBAR_OutputWakeXbarOut0  = 0|0x50000U,  /**< WAKE_XBAR_OUT0 output assigned to WAKE_XBAR_OUT0 */
    kWAKE__XBAR_OutputWakeXbarOut1  = 1|0x50000U,  /**< WAKE_XBAR_OUT1 output assigned to WAKE_XBAR_OUT1 */
    kWAKE__XBAR_OutputWakeAcmp0Sample = 2|0x50000U, /**< WAKE_XBAR_OUT2 output assigned to WAKE_ACMP0_SAMPLE */
    kWAKE__XBAR_OutputWakeAcmp1Sample = 3|0x50000U, /**< WAKE_XBAR_OUT3 output assigned to WAKE_ACMP1_SAMPLE */
    kWAKE__XBAR_OutputWakeAcmp2Sample = 4|0x50000U, /**< WAKE_XBAR_OUT4 output assigned to WAKE_ACMP2_SAMPLE */
    kWAKE__XBAR_OutputWakeAcmp3Sample = 5|0x50000U, /**< WAKE_XBAR_OUT5 output assigned to WAKE_ACMP3_SAMPLE */
    kWAKE__XBAR_OutputWakeAcmp0123RrTrig = 6|0x50000U, /**< WAKE_XBAR_OUT6 output assigned to WAKE_ACMP0123_RR_TRIG */
    kWAKE__XBAR_OutputWakeEwmIn     = 7|0x50000U,  /**< WAKE_XBAR_OUT7 output assigned to WAKE_EWM_IN */
    kWAKE__XBAR_OutputWakeFreqmeInput = 8|0x50000U, /**< WAKE_XBAR_OUT8 output assigned to WAKE_FREQME_INPUT */
    kWAKE__XBAR_OutputWakeQuadtpmTrigIn0 = 9|0x50000U, /**< WAKE_XBAR_OUT9 output assigned to WAKE_QUADTPM_TRIG_IN0 */
    kWAKE__XBAR_OutputWakeQuadtpmTrigIn1 = 10|0x50000U, /**< WAKE_XBAR_OUT10 output assigned to WAKE_QUADTPM_TRIG_IN1 */
    kWAKE__XBAR_OutputWakeQuadtpmTrigIn2 = 11|0x50000U, /**< WAKE_XBAR_OUT11 output assigned to WAKE_QUADTPM_TRIG_IN2 */
    kWAKE__XBAR_OutputWakeQuadtpmTrigIn3 = 12|0x50000U, /**< WAKE_XBAR_OUT12 output assigned to WAKE_QUADTPM_TRIG_IN3 */
    kWAKE__XBAR_OutputWakeLpi2c0TrigIn = 13|0x50000U, /**< WAKE_XBAR_OUT13 output assigned to WAKE_LPI2C0_TRIG_IN */
    kWAKE__XBAR_OutputWakeLpi2c1TrigIn = 14|0x50000U, /**< WAKE_XBAR_OUT14 output assigned to WAKE_LPI2C1_TRIG_IN */
    kWAKE__XBAR_OutputWakeLpspiTrigIn = 15|0x50000U, /**< WAKE_XBAR_OUT15 output assigned to WAKE_LPSPI_TRIG_IN */
    kWAKE__XBAR_OutputWakeLpuart0TrigIn = 16|0x50000U, /**< WAKE_XBAR_OUT16 output assigned to WAKE_LPUART0_TRIG_IN */
    kWAKE__XBAR_OutputWakeLpuart1TrigIn = 17|0x50000U, /**< WAKE_XBAR_OUT17 output assigned to WAKE_LPUART1_TRIG_IN */
    kWAKE__XBAR_OutputRESERVED18    = 18|0x50000U, /**< WAKE_XBAR_OUT18 output is reserved. */
    kWAKE__XBAR_OutputRESERVED19    = 19|0x50000U, /**< WAKE_XBAR_OUT19 output is reserved. */
    kWAKE__XBAR_OutputRESERVED20    = 20|0x50000U, /**< WAKE_XBAR_OUT20 output is reserved. */
    kWAKE__XBAR_OutputHspXbar0In78Xbar1In46 = 21|0x50000U, /**< WAKE_XBAR_OUT21 output assigned to HSP_XBAR0_IN78_XBAR1_IN46 */
    kWAKE__XBAR_OutputHspXbar0In79Xbar1In47 = 22|0x50000U, /**< WAKE_XBAR_OUT22 output assigned to HSP_XBAR0_IN79_XBAR1_IN47 */
    kWAKE__XBAR_OutputHspXbar0In80Xbar1In48 = 23|0x50000U, /**< WAKE_XBAR_OUT23 output assigned to HSP_XBAR0_IN80_XBAR1_IN48 */
    kWAKE__XBAR_OutputHspXbar0In81Xbar1In49 = 24|0x50000U, /**< WAKE_XBAR_OUT24 output assigned to HSP_XBAR0_IN81_XBAR1_IN49 */
    kWAKE__XBAR_OutputHspXbar0In82Xbar1In50 = 25|0x50000U, /**< WAKE_XBAR_OUT25 output assigned to HSP_XBAR0_IN82_XBAR1_IN50 */
    kWAKE__XBAR_OutputHspXbar0In83Xbar1In51 = 26|0x50000U, /**< WAKE_XBAR_OUT26 output assigned to HSP_XBAR0_IN83_XBAR1_IN51 */
    kWAKE__XBAR_OutputHspXbar0In84Xbar1In52 = 27|0x50000U, /**< WAKE_XBAR_OUT27 output assigned to HSP_XBAR0_IN84_XBAR1_IN52 */
    kWAKE__XBAR_OutputHspXbar0In85Xbar1In53 = 28|0x50000U, /**< WAKE_XBAR_OUT28 output assigned to HSP_XBAR0_IN85_XBAR1_IN53 */
    kWAKE__XBAR_OutputWakeXbarOut29 = 29|0x50000U, /**< WAKE_XBAR_OUT29 output assigned to WAKE_XBAR_OUT29 */
    kWAKE__XBAR_OutputWakeXbarOut30 = 30|0x50000U, /**< WAKE_XBAR_OUT30 output assigned to WAKE_XBAR_OUT30 */
    kWAKE__XBAR_OutputWakeTrgsyncSyncIn0 = 31|0x50000U, /**< WAKE_XBAR_OUT31 output assigned to WAKE_TRGSYNC_SYNC_IN0 */
    kWAKE__XBAR_OutputWakeTrgsyncSyncIn1 = 32|0x50000U, /**< WAKE_XBAR_OUT32 output assigned to WAKE_TRGSYNC_SYNC_IN1 */
    kWAKE__XBAR_OutputWakeTrgsyncSyncIn2 = 33|0x50000U, /**< WAKE_XBAR_OUT33 output assigned to WAKE_TRGSYNC_SYNC_IN2 */
    kWAKE__XBAR_OutputWakeTrgsyncSyncIn3 = 34|0x50000U, /**< WAKE_XBAR_OUT34 output assigned to WAKE_TRGSYNC_SYNC_IN3 */
} xbar_output_signal_t;


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__ADC_0 base address */
  #define HSP__ADC_0_BASE                          (0x52050000u)
  /** Peripheral HSP__ADC_0 base address */
  #define HSP__ADC_0_BASE_NS                       (0x42050000u)
  /** Peripheral HSP__ADC_0 base pointer */
  #define HSP__ADC_0                               ((ADC_Type *)HSP__ADC_0_BASE)
  /** Peripheral HSP__ADC_0 base pointer */
  #define HSP__ADC_0_NS                            ((ADC_Type *)HSP__ADC_0_BASE_NS)
  /** Peripheral HSP__ADC_1 base address */
  #define HSP__ADC_1_BASE                          (0x52850000u)
  /** Peripheral HSP__ADC_1 base address */
  #define HSP__ADC_1_BASE_NS                       (0x42850000u)
  /** Peripheral HSP__ADC_1 base pointer */
  #define HSP__ADC_1                               ((ADC_Type *)HSP__ADC_1_BASE)
  /** Peripheral HSP__ADC_1 base pointer */
  #define HSP__ADC_1_NS                            ((ADC_Type *)HSP__ADC_1_BASE_NS)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { HSP__ADC_0_BASE, HSP__ADC_1_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { HSP__ADC_0, HSP__ADC_1 }
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS_NS                        { HSP__ADC_0_BASE_NS, HSP__ADC_1_BASE_NS }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS_NS                         { HSP__ADC_0_NS, HSP__ADC_1_NS }
#else
  /** Peripheral HSP__ADC_0 base address */
  #define HSP__ADC_0_BASE                          (0x42050000u)
  /** Peripheral HSP__ADC_0 base pointer */
  #define HSP__ADC_0                               ((ADC_Type *)HSP__ADC_0_BASE)
  /** Peripheral HSP__ADC_1 base address */
  #define HSP__ADC_1_BASE                          (0x42850000u)
  /** Peripheral HSP__ADC_1 base pointer */
  #define HSP__ADC_1                               ((ADC_Type *)HSP__ADC_1_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { HSP__ADC_0_BASE, HSP__ADC_1_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { HSP__ADC_0, HSP__ADC_1 }
#endif
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { HSP_ADC0_IRQn, HSP_ADC1_IRQn }

/* AHB_SRAMC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MAIN__AHB_SRAMC base address */
  #define MAIN__AHB_SRAMC_BASE                     (0x50080000u)
  /** Peripheral MAIN__AHB_SRAMC base address */
  #define MAIN__AHB_SRAMC_BASE_NS                  (0x40080000u)
  /** Peripheral MAIN__AHB_SRAMC base pointer */
  #define MAIN__AHB_SRAMC                          ((AHB_SRAMC_Type *)MAIN__AHB_SRAMC_BASE)
  /** Peripheral MAIN__AHB_SRAMC base pointer */
  #define MAIN__AHB_SRAMC_NS                       ((AHB_SRAMC_Type *)MAIN__AHB_SRAMC_BASE_NS)
  /** Array initializer of AHB_SRAMC peripheral base addresses */
  #define AHB_SRAMC_BASE_ADDRS                     { MAIN__AHB_SRAMC_BASE }
  /** Array initializer of AHB_SRAMC peripheral base pointers */
  #define AHB_SRAMC_BASE_PTRS                      { MAIN__AHB_SRAMC }
  /** Array initializer of AHB_SRAMC peripheral base addresses */
  #define AHB_SRAMC_BASE_ADDRS_NS                  { MAIN__AHB_SRAMC_BASE_NS }
  /** Array initializer of AHB_SRAMC peripheral base pointers */
  #define AHB_SRAMC_BASE_PTRS_NS                   { MAIN__AHB_SRAMC_NS }
#else
  /** Peripheral MAIN__AHB_SRAMC base address */
  #define MAIN__AHB_SRAMC_BASE                     (0x40080000u)
  /** Peripheral MAIN__AHB_SRAMC base pointer */
  #define MAIN__AHB_SRAMC                          ((AHB_SRAMC_Type *)MAIN__AHB_SRAMC_BASE)
  /** Array initializer of AHB_SRAMC peripheral base addresses */
  #define AHB_SRAMC_BASE_ADDRS                     { MAIN__AHB_SRAMC_BASE }
  /** Array initializer of AHB_SRAMC peripheral base pointers */
  #define AHB_SRAMC_BASE_PTRS                      { MAIN__AHB_SRAMC }
#endif

/* ASRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO__ASRC base address */
  #define AUDIO__ASRC_BASE                         (0x58140000u)
  /** Peripheral AUDIO__ASRC base address */
  #define AUDIO__ASRC_BASE_NS                      (0x48140000u)
  /** Peripheral AUDIO__ASRC base pointer */
  #define AUDIO__ASRC                              ((ASRC_Type *)AUDIO__ASRC_BASE)
  /** Peripheral AUDIO__ASRC base pointer */
  #define AUDIO__ASRC_NS                           ((ASRC_Type *)AUDIO__ASRC_BASE_NS)
  /** Array initializer of ASRC peripheral base addresses */
  #define ASRC_BASE_ADDRS                          { AUDIO__ASRC_BASE }
  /** Array initializer of ASRC peripheral base pointers */
  #define ASRC_BASE_PTRS                           { AUDIO__ASRC }
  /** Array initializer of ASRC peripheral base addresses */
  #define ASRC_BASE_ADDRS_NS                       { AUDIO__ASRC_BASE_NS }
  /** Array initializer of ASRC peripheral base pointers */
  #define ASRC_BASE_PTRS_NS                        { AUDIO__ASRC_NS }
#else
  /** Peripheral AUDIO__ASRC base address */
  #define AUDIO__ASRC_BASE                         (0x48140000u)
  /** Peripheral AUDIO__ASRC base pointer */
  #define AUDIO__ASRC                              ((ASRC_Type *)AUDIO__ASRC_BASE)
  /** Array initializer of ASRC peripheral base addresses */
  #define ASRC_BASE_ADDRS                          { AUDIO__ASRC_BASE }
  /** Array initializer of ASRC peripheral base pointers */
  #define ASRC_BASE_PTRS                           { AUDIO__ASRC }
#endif
/** Interrupt vectors for the ASRC peripheral type */
#define ASRC_IRQS                                { AUDIO_ASRC_IRQn }

/* AUDIO_XCVR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO__SPDIF base address */
  #define AUDIO__SPDIF_BASE                        (0x58600000u)
  /** Peripheral AUDIO__SPDIF base address */
  #define AUDIO__SPDIF_BASE_NS                     (0x48600000u)
  /** Peripheral AUDIO__SPDIF base pointer */
  #define AUDIO__SPDIF                             ((AUDIO_XCVR_Type *)AUDIO__SPDIF_BASE)
  /** Peripheral AUDIO__SPDIF base pointer */
  #define AUDIO__SPDIF_NS                          ((AUDIO_XCVR_Type *)AUDIO__SPDIF_BASE_NS)
  /** Array initializer of AUDIO_XCVR peripheral base addresses */
  #define AUDIO_XCVR_BASE_ADDRS                    { AUDIO__SPDIF_BASE }
  /** Array initializer of AUDIO_XCVR peripheral base pointers */
  #define AUDIO_XCVR_BASE_PTRS                     { AUDIO__SPDIF }
  /** Array initializer of AUDIO_XCVR peripheral base addresses */
  #define AUDIO_XCVR_BASE_ADDRS_NS                 { AUDIO__SPDIF_BASE_NS }
  /** Array initializer of AUDIO_XCVR peripheral base pointers */
  #define AUDIO_XCVR_BASE_PTRS_NS                  { AUDIO__SPDIF_NS }
#else
  /** Peripheral AUDIO__SPDIF base address */
  #define AUDIO__SPDIF_BASE                        (0x48600000u)
  /** Peripheral AUDIO__SPDIF base pointer */
  #define AUDIO__SPDIF                             ((AUDIO_XCVR_Type *)AUDIO__SPDIF_BASE)
  /** Array initializer of AUDIO_XCVR peripheral base addresses */
  #define AUDIO_XCVR_BASE_ADDRS                    { AUDIO__SPDIF_BASE }
  /** Array initializer of AUDIO_XCVR peripheral base pointers */
  #define AUDIO_XCVR_BASE_PTRS                     { AUDIO__SPDIF }
#endif
/** Interrupt vectors for the AUDIO_XCVR peripheral type */
#define AUDIO_XCVR_IRQS                          { AUDIO_SPDIF_IRQn }

/* AXBS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MAIN__AXBS base address */
  #define MAIN__AXBS_BASE                          (0x50090000u)
  /** Peripheral MAIN__AXBS base address */
  #define MAIN__AXBS_BASE_NS                       (0x40090000u)
  /** Peripheral MAIN__AXBS base pointer */
  #define MAIN__AXBS                               ((AXBS_Type *)MAIN__AXBS_BASE)
  /** Peripheral MAIN__AXBS base pointer */
  #define MAIN__AXBS_NS                            ((AXBS_Type *)MAIN__AXBS_BASE_NS)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { MAIN__AXBS_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { MAIN__AXBS }
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS_NS                       { MAIN__AXBS_BASE_NS }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS_NS                        { MAIN__AXBS_NS }
#else
  /** Peripheral MAIN__AXBS base address */
  #define MAIN__AXBS_BASE                          (0x40090000u)
  /** Peripheral MAIN__AXBS base pointer */
  #define MAIN__AXBS                               ((AXBS_Type *)MAIN__AXBS_BASE)
  /** Array initializer of AXBS peripheral base addresses */
  #define AXBS_BASE_ADDRS                          { MAIN__AXBS_BASE }
  /** Array initializer of AXBS peripheral base pointers */
  #define AXBS_BASE_PTRS                           { MAIN__AXBS }
#endif

/* CAN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__FLEXCAN_0 base address */
  #define HSP__FLEXCAN_0_BASE                      (0x520F0000u)
  /** Peripheral HSP__FLEXCAN_0 base address */
  #define HSP__FLEXCAN_0_BASE_NS                   (0x420F0000u)
  /** Peripheral HSP__FLEXCAN_0 base pointer */
  #define HSP__FLEXCAN_0                           ((CAN_Type *)HSP__FLEXCAN_0_BASE)
  /** Peripheral HSP__FLEXCAN_0 base pointer */
  #define HSP__FLEXCAN_0_NS                        ((CAN_Type *)HSP__FLEXCAN_0_BASE_NS)
  /** Peripheral HSP__FLEXCAN_1 base address */
  #define HSP__FLEXCAN_1_BASE                      (0x52100000u)
  /** Peripheral HSP__FLEXCAN_1 base address */
  #define HSP__FLEXCAN_1_BASE_NS                   (0x42100000u)
  /** Peripheral HSP__FLEXCAN_1 base pointer */
  #define HSP__FLEXCAN_1                           ((CAN_Type *)HSP__FLEXCAN_1_BASE)
  /** Peripheral HSP__FLEXCAN_1 base pointer */
  #define HSP__FLEXCAN_1_NS                        ((CAN_Type *)HSP__FLEXCAN_1_BASE_NS)
  /** Peripheral HSP__FLEXCAN_2 base address */
  #define HSP__FLEXCAN_2_BASE                      (0x528F0000u)
  /** Peripheral HSP__FLEXCAN_2 base address */
  #define HSP__FLEXCAN_2_BASE_NS                   (0x428F0000u)
  /** Peripheral HSP__FLEXCAN_2 base pointer */
  #define HSP__FLEXCAN_2                           ((CAN_Type *)HSP__FLEXCAN_2_BASE)
  /** Peripheral HSP__FLEXCAN_2 base pointer */
  #define HSP__FLEXCAN_2_NS                        ((CAN_Type *)HSP__FLEXCAN_2_BASE_NS)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { HSP__FLEXCAN_0_BASE, HSP__FLEXCAN_1_BASE, HSP__FLEXCAN_2_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { HSP__FLEXCAN_0, HSP__FLEXCAN_1, HSP__FLEXCAN_2 }
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS_NS                        { HSP__FLEXCAN_0_BASE_NS, HSP__FLEXCAN_1_BASE_NS, HSP__FLEXCAN_2_BASE_NS }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS_NS                         { HSP__FLEXCAN_0_NS, HSP__FLEXCAN_1_NS, HSP__FLEXCAN_2_NS }
#else
  /** Peripheral HSP__FLEXCAN_0 base address */
  #define HSP__FLEXCAN_0_BASE                      (0x420F0000u)
  /** Peripheral HSP__FLEXCAN_0 base pointer */
  #define HSP__FLEXCAN_0                           ((CAN_Type *)HSP__FLEXCAN_0_BASE)
  /** Peripheral HSP__FLEXCAN_1 base address */
  #define HSP__FLEXCAN_1_BASE                      (0x42100000u)
  /** Peripheral HSP__FLEXCAN_1 base pointer */
  #define HSP__FLEXCAN_1                           ((CAN_Type *)HSP__FLEXCAN_1_BASE)
  /** Peripheral HSP__FLEXCAN_2 base address */
  #define HSP__FLEXCAN_2_BASE                      (0x428F0000u)
  /** Peripheral HSP__FLEXCAN_2 base pointer */
  #define HSP__FLEXCAN_2                           ((CAN_Type *)HSP__FLEXCAN_2_BASE)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { HSP__FLEXCAN_0_BASE, HSP__FLEXCAN_1_BASE, HSP__FLEXCAN_2_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { HSP__FLEXCAN_0, HSP__FLEXCAN_1, HSP__FLEXCAN_2 }
#endif
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { HSP_FLEXCAN0_IRQn, HSP_FLEXCAN1_IRQn, HSP_FLEXCAN2_IRQn }
#define CAN_Tx_Warning_IRQS                      { HSP_FLEXCAN0_IRQn, HSP_FLEXCAN1_IRQn, HSP_FLEXCAN2_IRQn }
#define CAN_Wake_Up_IRQS                         { HSP_FLEXCAN0_IRQn, HSP_FLEXCAN1_IRQn, HSP_FLEXCAN2_IRQn }
#define CAN_Error_IRQS                           { HSP_FLEXCAN0_IRQn, HSP_FLEXCAN1_IRQn, HSP_FLEXCAN2_IRQn }
#define CAN_Bus_Off_IRQS                         { HSP_FLEXCAN0_IRQn, HSP_FLEXCAN1_IRQn, HSP_FLEXCAN2_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { HSP_FLEXCAN0_IRQn, HSP_FLEXCAN1_IRQn, HSP_FLEXCAN2_IRQn }

/* CCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO__CCM base address */
  #define AUDIO__CCM_BASE                          (0x58060000u)
  /** Peripheral AUDIO__CCM base address */
  #define AUDIO__CCM_BASE_NS                       (0x48060000u)
  /** Peripheral AUDIO__CCM base pointer */
  #define AUDIO__CCM                               ((CCM_Type *)AUDIO__CCM_BASE)
  /** Peripheral AUDIO__CCM base pointer */
  #define AUDIO__CCM_NS                            ((CCM_Type *)AUDIO__CCM_BASE_NS)
  /** Peripheral CMPT__CCM base address */
  #define CMPT__CCM_BASE                           (0x54060000u)
  /** Peripheral CMPT__CCM base address */
  #define CMPT__CCM_BASE_NS                        (0x44060000u)
  /** Peripheral CMPT__CCM base pointer */
  #define CMPT__CCM                                ((CCM_Type *)CMPT__CCM_BASE)
  /** Peripheral CMPT__CCM base pointer */
  #define CMPT__CCM_NS                             ((CCM_Type *)CMPT__CCM_BASE_NS)
  /** Peripheral COMM__CCM base address */
  #define COMM__CCM_BASE                           (0x5A060000u)
  /** Peripheral COMM__CCM base address */
  #define COMM__CCM_BASE_NS                        (0x4A060000u)
  /** Peripheral COMM__CCM base pointer */
  #define COMM__CCM                                ((CCM_Type *)COMM__CCM_BASE)
  /** Peripheral COMM__CCM base pointer */
  #define COMM__CCM_NS                             ((CCM_Type *)COMM__CCM_BASE_NS)
  /** Peripheral MAIN__CCM base address */
  #define MAIN__CCM_BASE                           (0x50060000u)
  /** Peripheral MAIN__CCM base address */
  #define MAIN__CCM_BASE_NS                        (0x40060000u)
  /** Peripheral MAIN__CCM base pointer */
  #define MAIN__CCM                                ((CCM_Type *)MAIN__CCM_BASE)
  /** Peripheral MAIN__CCM base pointer */
  #define MAIN__CCM_NS                             ((CCM_Type *)MAIN__CCM_BASE_NS)
  /** Peripheral MEDIA__CCM base address */
  #define MEDIA__CCM_BASE                          (0x5C060000u)
  /** Peripheral MEDIA__CCM base address */
  #define MEDIA__CCM_BASE_NS                       (0x4C060000u)
  /** Peripheral MEDIA__CCM base pointer */
  #define MEDIA__CCM                               ((CCM_Type *)MEDIA__CCM_BASE)
  /** Peripheral MEDIA__CCM base pointer */
  #define MEDIA__CCM_NS                            ((CCM_Type *)MEDIA__CCM_BASE_NS)
  /** Peripheral SYSCON__CCM base address */
  #define SYSCON__CCM_BASE                         (0x50510000u)
  /** Peripheral SYSCON__CCM base address */
  #define SYSCON__CCM_BASE_NS                      (0x40510000u)
  /** Peripheral SYSCON__CCM base pointer */
  #define SYSCON__CCM                              ((CCM_Type *)SYSCON__CCM_BASE)
  /** Peripheral SYSCON__CCM base pointer */
  #define SYSCON__CCM_NS                           ((CCM_Type *)SYSCON__CCM_BASE_NS)
  /** Peripheral WAKE__CCM base address */
  #define WAKE__CCM_BASE                           (0x56060000u)
  /** Peripheral WAKE__CCM base address */
  #define WAKE__CCM_BASE_NS                        (0x46060000u)
  /** Peripheral WAKE__CCM base pointer */
  #define WAKE__CCM                                ((CCM_Type *)WAKE__CCM_BASE)
  /** Peripheral WAKE__CCM base pointer */
  #define WAKE__CCM_NS                             ((CCM_Type *)WAKE__CCM_BASE_NS)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { AUDIO__CCM_BASE, CMPT__CCM_BASE, COMM__CCM_BASE, MAIN__CCM_BASE, MEDIA__CCM_BASE, SYSCON__CCM_BASE, WAKE__CCM_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { AUDIO__CCM, CMPT__CCM, COMM__CCM, MAIN__CCM, MEDIA__CCM, SYSCON__CCM, WAKE__CCM }
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS_NS                        { AUDIO__CCM_BASE_NS, CMPT__CCM_BASE_NS, COMM__CCM_BASE_NS, MAIN__CCM_BASE_NS, MEDIA__CCM_BASE_NS, SYSCON__CCM_BASE_NS, WAKE__CCM_BASE_NS }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS_NS                         { AUDIO__CCM_NS, CMPT__CCM_NS, COMM__CCM_NS, MAIN__CCM_NS, MEDIA__CCM_NS, SYSCON__CCM_NS, WAKE__CCM_NS }
#else
  /** Peripheral AUDIO__CCM base address */
  #define AUDIO__CCM_BASE                          (0x48060000u)
  /** Peripheral AUDIO__CCM base pointer */
  #define AUDIO__CCM                               ((CCM_Type *)AUDIO__CCM_BASE)
  /** Peripheral CMPT__CCM base address */
  #define CMPT__CCM_BASE                           (0x44060000u)
  /** Peripheral CMPT__CCM base pointer */
  #define CMPT__CCM                                ((CCM_Type *)CMPT__CCM_BASE)
  /** Peripheral COMM__CCM base address */
  #define COMM__CCM_BASE                           (0x4A060000u)
  /** Peripheral COMM__CCM base pointer */
  #define COMM__CCM                                ((CCM_Type *)COMM__CCM_BASE)
  /** Peripheral MAIN__CCM base address */
  #define MAIN__CCM_BASE                           (0x40060000u)
  /** Peripheral MAIN__CCM base pointer */
  #define MAIN__CCM                                ((CCM_Type *)MAIN__CCM_BASE)
  /** Peripheral MEDIA__CCM base address */
  #define MEDIA__CCM_BASE                          (0x4C060000u)
  /** Peripheral MEDIA__CCM base pointer */
  #define MEDIA__CCM                               ((CCM_Type *)MEDIA__CCM_BASE)
  /** Peripheral SYSCON__CCM base address */
  #define SYSCON__CCM_BASE                         (0x40510000u)
  /** Peripheral SYSCON__CCM base pointer */
  #define SYSCON__CCM                              ((CCM_Type *)SYSCON__CCM_BASE)
  /** Peripheral WAKE__CCM base address */
  #define WAKE__CCM_BASE                           (0x46060000u)
  /** Peripheral WAKE__CCM base pointer */
  #define WAKE__CCM                                ((CCM_Type *)WAKE__CCM_BASE)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { AUDIO__CCM_BASE, CMPT__CCM_BASE, COMM__CCM_BASE, MAIN__CCM_BASE, MEDIA__CCM_BASE, SYSCON__CCM_BASE, WAKE__CCM_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { AUDIO__CCM, CMPT__CCM, COMM__CCM, MAIN__CCM, MEDIA__CCM, SYSCON__CCM, WAKE__CCM }
#endif

/* CGUANA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON__CGUANA base address */
  #define SYSCON__CGUANA_BASE                      (0x50500000u)
  /** Peripheral SYSCON__CGUANA base address */
  #define SYSCON__CGUANA_BASE_NS                   (0x40500000u)
  /** Peripheral SYSCON__CGUANA base pointer */
  #define SYSCON__CGUANA                           ((CGUANA_Type *)SYSCON__CGUANA_BASE)
  /** Peripheral SYSCON__CGUANA base pointer */
  #define SYSCON__CGUANA_NS                        ((CGUANA_Type *)SYSCON__CGUANA_BASE_NS)
  /** Array initializer of CGUANA peripheral base addresses */
  #define CGUANA_BASE_ADDRS                        { SYSCON__CGUANA_BASE }
  /** Array initializer of CGUANA peripheral base pointers */
  #define CGUANA_BASE_PTRS                         { SYSCON__CGUANA }
  /** Array initializer of CGUANA peripheral base addresses */
  #define CGUANA_BASE_ADDRS_NS                     { SYSCON__CGUANA_BASE_NS }
  /** Array initializer of CGUANA peripheral base pointers */
  #define CGUANA_BASE_PTRS_NS                      { SYSCON__CGUANA_NS }
#else
  /** Peripheral SYSCON__CGUANA base address */
  #define SYSCON__CGUANA_BASE                      (0x40500000u)
  /** Peripheral SYSCON__CGUANA base pointer */
  #define SYSCON__CGUANA                           ((CGUANA_Type *)SYSCON__CGUANA_BASE)
  /** Array initializer of CGUANA peripheral base addresses */
  #define CGUANA_BASE_ADDRS                        { SYSCON__CGUANA_BASE }
  /** Array initializer of CGUANA peripheral base pointers */
  #define CGUANA_BASE_PTRS                         { SYSCON__CGUANA }
#endif

/* CMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKE__ACMP_0 base address */
  #define WAKE__ACMP_0_BASE                        (0x560D0000u)
  /** Peripheral WAKE__ACMP_0 base address */
  #define WAKE__ACMP_0_BASE_NS                     (0x460D0000u)
  /** Peripheral WAKE__ACMP_0 base pointer */
  #define WAKE__ACMP_0                             ((CMP_Type *)WAKE__ACMP_0_BASE)
  /** Peripheral WAKE__ACMP_0 base pointer */
  #define WAKE__ACMP_0_NS                          ((CMP_Type *)WAKE__ACMP_0_BASE_NS)
  /** Peripheral WAKE__ACMP_1 base address */
  #define WAKE__ACMP_1_BASE                        (0x560E0000u)
  /** Peripheral WAKE__ACMP_1 base address */
  #define WAKE__ACMP_1_BASE_NS                     (0x460E0000u)
  /** Peripheral WAKE__ACMP_1 base pointer */
  #define WAKE__ACMP_1                             ((CMP_Type *)WAKE__ACMP_1_BASE)
  /** Peripheral WAKE__ACMP_1 base pointer */
  #define WAKE__ACMP_1_NS                          ((CMP_Type *)WAKE__ACMP_1_BASE_NS)
  /** Peripheral WAKE__ACMP_2 base address */
  #define WAKE__ACMP_2_BASE                        (0x560F0000u)
  /** Peripheral WAKE__ACMP_2 base address */
  #define WAKE__ACMP_2_BASE_NS                     (0x460F0000u)
  /** Peripheral WAKE__ACMP_2 base pointer */
  #define WAKE__ACMP_2                             ((CMP_Type *)WAKE__ACMP_2_BASE)
  /** Peripheral WAKE__ACMP_2 base pointer */
  #define WAKE__ACMP_2_NS                          ((CMP_Type *)WAKE__ACMP_2_BASE_NS)
  /** Peripheral WAKE__ACMP_3 base address */
  #define WAKE__ACMP_3_BASE                        (0x56100000u)
  /** Peripheral WAKE__ACMP_3 base address */
  #define WAKE__ACMP_3_BASE_NS                     (0x46100000u)
  /** Peripheral WAKE__ACMP_3 base pointer */
  #define WAKE__ACMP_3                             ((CMP_Type *)WAKE__ACMP_3_BASE)
  /** Peripheral WAKE__ACMP_3 base pointer */
  #define WAKE__ACMP_3_NS                          ((CMP_Type *)WAKE__ACMP_3_BASE_NS)
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS                           { WAKE__ACMP_0_BASE, WAKE__ACMP_1_BASE, WAKE__ACMP_2_BASE, WAKE__ACMP_3_BASE }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS                            { WAKE__ACMP_0, WAKE__ACMP_1, WAKE__ACMP_2, WAKE__ACMP_3 }
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS_NS                        { WAKE__ACMP_0_BASE_NS, WAKE__ACMP_1_BASE_NS, WAKE__ACMP_2_BASE_NS, WAKE__ACMP_3_BASE_NS }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS_NS                         { WAKE__ACMP_0_NS, WAKE__ACMP_1_NS, WAKE__ACMP_2_NS, WAKE__ACMP_3_NS }
#else
  /** Peripheral WAKE__ACMP_0 base address */
  #define WAKE__ACMP_0_BASE                        (0x460D0000u)
  /** Peripheral WAKE__ACMP_0 base pointer */
  #define WAKE__ACMP_0                             ((CMP_Type *)WAKE__ACMP_0_BASE)
  /** Peripheral WAKE__ACMP_1 base address */
  #define WAKE__ACMP_1_BASE                        (0x460E0000u)
  /** Peripheral WAKE__ACMP_1 base pointer */
  #define WAKE__ACMP_1                             ((CMP_Type *)WAKE__ACMP_1_BASE)
  /** Peripheral WAKE__ACMP_2 base address */
  #define WAKE__ACMP_2_BASE                        (0x460F0000u)
  /** Peripheral WAKE__ACMP_2 base pointer */
  #define WAKE__ACMP_2                             ((CMP_Type *)WAKE__ACMP_2_BASE)
  /** Peripheral WAKE__ACMP_3 base address */
  #define WAKE__ACMP_3_BASE                        (0x46100000u)
  /** Peripheral WAKE__ACMP_3 base pointer */
  #define WAKE__ACMP_3                             ((CMP_Type *)WAKE__ACMP_3_BASE)
  /** Array initializer of CMP peripheral base addresses */
  #define CMP_BASE_ADDRS                           { WAKE__ACMP_0_BASE, WAKE__ACMP_1_BASE, WAKE__ACMP_2_BASE, WAKE__ACMP_3_BASE }
  /** Array initializer of CMP peripheral base pointers */
  #define CMP_BASE_PTRS                            { WAKE__ACMP_0, WAKE__ACMP_1, WAKE__ACMP_2, WAKE__ACMP_3 }
#endif
/** Interrupt vectors for the CMP peripheral type */
#define CMP_IRQS                                 { WAKE_ACMP0_IRQn, WAKE_ACMP1_IRQn, WAKE_ACMP2_IRQn, WAKE_ACMP3_IRQn }

/* CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__CRC base address */
  #define HSP__CRC_BASE                            (0x52980000u)
  /** Peripheral HSP__CRC base address */
  #define HSP__CRC_BASE_NS                         (0x42980000u)
  /** Peripheral HSP__CRC base pointer */
  #define HSP__CRC                                 ((CRC_Type *)HSP__CRC_BASE)
  /** Peripheral HSP__CRC base pointer */
  #define HSP__CRC_NS                              ((CRC_Type *)HSP__CRC_BASE_NS)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { HSP__CRC_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { HSP__CRC }
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS_NS                        { HSP__CRC_BASE_NS }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS_NS                         { HSP__CRC_NS }
#else
  /** Peripheral HSP__CRC base address */
  #define HSP__CRC_BASE                            (0x42980000u)
  /** Peripheral HSP__CRC base pointer */
  #define HSP__CRC                                 ((CRC_Type *)HSP__CRC_BASE)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { HSP__CRC_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { HSP__CRC }
#endif

/* DCIF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MEDIA__DCIF base address */
  #define MEDIA__DCIF_BASE                         (0x5C200000u)
  /** Peripheral MEDIA__DCIF base address */
  #define MEDIA__DCIF_BASE_NS                      (0x4C200000u)
  /** Peripheral MEDIA__DCIF base pointer */
  #define MEDIA__DCIF                              ((DCIF_Type *)MEDIA__DCIF_BASE)
  /** Peripheral MEDIA__DCIF base pointer */
  #define MEDIA__DCIF_NS                           ((DCIF_Type *)MEDIA__DCIF_BASE_NS)
  /** Array initializer of DCIF peripheral base addresses */
  #define DCIF_BASE_ADDRS                          { MEDIA__DCIF_BASE }
  /** Array initializer of DCIF peripheral base pointers */
  #define DCIF_BASE_PTRS                           { MEDIA__DCIF }
  /** Array initializer of DCIF peripheral base addresses */
  #define DCIF_BASE_ADDRS_NS                       { MEDIA__DCIF_BASE_NS }
  /** Array initializer of DCIF peripheral base pointers */
  #define DCIF_BASE_PTRS_NS                        { MEDIA__DCIF_NS }
#else
  /** Peripheral MEDIA__DCIF base address */
  #define MEDIA__DCIF_BASE                         (0x4C200000u)
  /** Peripheral MEDIA__DCIF base pointer */
  #define MEDIA__DCIF                              ((DCIF_Type *)MEDIA__DCIF_BASE)
  /** Array initializer of DCIF peripheral base addresses */
  #define DCIF_BASE_ADDRS                          { MEDIA__DCIF_BASE }
  /** Array initializer of DCIF peripheral base pointers */
  #define DCIF_BASE_PTRS                           { MEDIA__DCIF }
#endif
/** Interrupt vectors for the DCIF peripheral type */
#define DCIF_IRQS                                { MEDIA_DCIF_CH0_IRQn, MEDIA_DCIF_CH1_IRQn, MEDIA_DCIF_CH2_IRQn, MEDIA_DCIF_CH3_IRQn, MEDIA_DCIF_CH4_IRQn, MEDIA_DCIF_CH5_IRQn, MEDIA_DCIF_CH6_IRQn, MEDIA_DCIF_CH7_IRQn, MEDIA_DCIF_CH8_IRQn }

/* DEBUGMAILBOX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKE__DBGMB base address */
  #define WAKE__DBGMB_BASE                         (0x51E00000u)
  /** Peripheral WAKE__DBGMB base address */
  #define WAKE__DBGMB_BASE_NS                      (0x41E00000u)
  /** Peripheral WAKE__DBGMB base pointer */
  #define WAKE__DBGMB                              ((DEBUGMAILBOX_Type *)WAKE__DBGMB_BASE)
  /** Peripheral WAKE__DBGMB base pointer */
  #define WAKE__DBGMB_NS                           ((DEBUGMAILBOX_Type *)WAKE__DBGMB_BASE_NS)
  /** Array initializer of DEBUGMAILBOX peripheral base addresses */
  #define DEBUGMAILBOX_BASE_ADDRS                  { WAKE__DBGMB_BASE }
  /** Array initializer of DEBUGMAILBOX peripheral base pointers */
  #define DEBUGMAILBOX_BASE_PTRS                   { WAKE__DBGMB }
  /** Array initializer of DEBUGMAILBOX peripheral base addresses */
  #define DEBUGMAILBOX_BASE_ADDRS_NS               { WAKE__DBGMB_BASE_NS }
  /** Array initializer of DEBUGMAILBOX peripheral base pointers */
  #define DEBUGMAILBOX_BASE_PTRS_NS                { WAKE__DBGMB_NS }
#else
  /** Peripheral WAKE__DBGMB base address */
  #define WAKE__DBGMB_BASE                         (0x41E00000u)
  /** Peripheral WAKE__DBGMB base pointer */
  #define WAKE__DBGMB                              ((DEBUGMAILBOX_Type *)WAKE__DBGMB_BASE)
  /** Array initializer of DEBUGMAILBOX peripheral base addresses */
  #define DEBUGMAILBOX_BASE_ADDRS                  { WAKE__DBGMB_BASE }
  /** Array initializer of DEBUGMAILBOX peripheral base pointers */
  #define DEBUGMAILBOX_BASE_PTRS                   { WAKE__DBGMB }
#endif

/* DIGTMP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VBAT__TDET base address */
  #define VBAT__TDET_BASE                          (0x56320000u)
  /** Peripheral VBAT__TDET base address */
  #define VBAT__TDET_BASE_NS                       (0x46320000u)
  /** Peripheral VBAT__TDET base pointer */
  #define VBAT__TDET                               ((DIGTMP_Type *)VBAT__TDET_BASE)
  /** Peripheral VBAT__TDET base pointer */
  #define VBAT__TDET_NS                            ((DIGTMP_Type *)VBAT__TDET_BASE_NS)
  /** Array initializer of DIGTMP peripheral base addresses */
  #define DIGTMP_BASE_ADDRS                        { VBAT__TDET_BASE }
  /** Array initializer of DIGTMP peripheral base pointers */
  #define DIGTMP_BASE_PTRS                         { VBAT__TDET }
  /** Array initializer of DIGTMP peripheral base addresses */
  #define DIGTMP_BASE_ADDRS_NS                     { VBAT__TDET_BASE_NS }
  /** Array initializer of DIGTMP peripheral base pointers */
  #define DIGTMP_BASE_PTRS_NS                      { VBAT__TDET_NS }
#else
  /** Peripheral VBAT__TDET base address */
  #define VBAT__TDET_BASE                          (0x46320000u)
  /** Peripheral VBAT__TDET base pointer */
  #define VBAT__TDET                               ((DIGTMP_Type *)VBAT__TDET_BASE)
  /** Array initializer of DIGTMP peripheral base addresses */
  #define DIGTMP_BASE_ADDRS                        { VBAT__TDET_BASE }
  /** Array initializer of DIGTMP peripheral base pointers */
  #define DIGTMP_BASE_PTRS                         { VBAT__TDET }
#endif

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO__EDMA3 base address */
  #define AUDIO__EDMA3_BASE                        (0x58170000u)
  /** Peripheral AUDIO__EDMA3 base address */
  #define AUDIO__EDMA3_BASE_NS                     (0x48170000u)
  /** Peripheral AUDIO__EDMA3 base pointer */
  #define AUDIO__EDMA3                             ((DMA_Type *)AUDIO__EDMA3_BASE)
  /** Peripheral AUDIO__EDMA3 base pointer */
  #define AUDIO__EDMA3_NS                          ((DMA_Type *)AUDIO__EDMA3_BASE_NS)
  /** Peripheral MAIN__EDMA3 base address */
  #define MAIN__EDMA3_BASE                         (0x500E0000u)
  /** Peripheral MAIN__EDMA3 base address */
  #define MAIN__EDMA3_BASE_NS                      (0x400E0000u)
  /** Peripheral MAIN__EDMA3 base pointer */
  #define MAIN__EDMA3                              ((DMA_Type *)MAIN__EDMA3_BASE)
  /** Peripheral MAIN__EDMA3 base pointer */
  #define MAIN__EDMA3_NS                           ((DMA_Type *)MAIN__EDMA3_BASE_NS)
  /** Peripheral WAKE__EDMA3 base address */
  #define WAKE__EDMA3_BASE                         (0x56270000u)
  /** Peripheral WAKE__EDMA3 base address */
  #define WAKE__EDMA3_BASE_NS                      (0x46270000u)
  /** Peripheral WAKE__EDMA3 base pointer */
  #define WAKE__EDMA3                              ((DMA_Type *)WAKE__EDMA3_BASE)
  /** Peripheral WAKE__EDMA3 base pointer */
  #define WAKE__EDMA3_NS                           ((DMA_Type *)WAKE__EDMA3_BASE_NS)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { AUDIO__EDMA3_BASE, MAIN__EDMA3_BASE, WAKE__EDMA3_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { AUDIO__EDMA3, MAIN__EDMA3, WAKE__EDMA3 }
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS_NS                        { AUDIO__EDMA3_BASE_NS, MAIN__EDMA3_BASE_NS, WAKE__EDMA3_BASE_NS }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS_NS                         { AUDIO__EDMA3_NS, MAIN__EDMA3_NS, WAKE__EDMA3_NS }
#else
  /** Peripheral AUDIO__EDMA3 base address */
  #define AUDIO__EDMA3_BASE                        (0x48170000u)
  /** Peripheral AUDIO__EDMA3 base pointer */
  #define AUDIO__EDMA3                             ((DMA_Type *)AUDIO__EDMA3_BASE)
  /** Peripheral MAIN__EDMA3 base address */
  #define MAIN__EDMA3_BASE                         (0x400E0000u)
  /** Peripheral MAIN__EDMA3 base pointer */
  #define MAIN__EDMA3                              ((DMA_Type *)MAIN__EDMA3_BASE)
  /** Peripheral WAKE__EDMA3 base address */
  #define WAKE__EDMA3_BASE                         (0x46270000u)
  /** Peripheral WAKE__EDMA3 base pointer */
  #define WAKE__EDMA3                              ((DMA_Type *)WAKE__EDMA3_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { AUDIO__EDMA3_BASE, MAIN__EDMA3_BASE, WAKE__EDMA3_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { AUDIO__EDMA3, MAIN__EDMA3, WAKE__EDMA3 }
#endif
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { AUDIO_EDMA3_CH0_IRQn, AUDIO_EDMA3_CH1_IRQn, AUDIO_EDMA3_CH2_IRQn, AUDIO_EDMA3_CH3_IRQn, AUDIO_EDMA3_CH4_IRQn, AUDIO_EDMA3_CH5_IRQn, AUDIO_EDMA3_CH6_IRQn, AUDIO_EDMA3_CH7_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, \
                                                   { MAIN_EDMA3_CH0_IRQn, MAIN_EDMA3_CH1_IRQn, MAIN_EDMA3_CH2_IRQn, MAIN_EDMA3_CH3_IRQn, MAIN_EDMA3_CH4_IRQn, MAIN_EDMA3_CH5_IRQn, MAIN_EDMA3_CH6_IRQn, MAIN_EDMA3_CH7_IRQn, MAIN_EDMA3_CH8_IRQn, MAIN_EDMA3_CH9_IRQn, MAIN_EDMA3_CH10_IRQn, MAIN_EDMA3_CH11_IRQn, MAIN_EDMA3_CH12_IRQn, MAIN_EDMA3_CH13_IRQn, MAIN_EDMA3_CH14_IRQn, MAIN_EDMA3_CH15_IRQn, MAIN_EDMA3_CH16_IRQn, MAIN_EDMA3_CH17_IRQn, MAIN_EDMA3_CH18_IRQn, MAIN_EDMA3_CH19_IRQn, MAIN_EDMA3_CH20_IRQn, MAIN_EDMA3_CH21_IRQn, MAIN_EDMA3_CH22_IRQn, MAIN_EDMA3_CH23_IRQn, MAIN_EDMA3_CH24_IRQn, MAIN_EDMA3_CH25_IRQn, MAIN_EDMA3_CH26_IRQn, MAIN_EDMA3_CH27_IRQn, MAIN_EDMA3_CH28_IRQn, MAIN_EDMA3_CH29_IRQn, MAIN_EDMA3_CH30_IRQn, MAIN_EDMA3_CH31_IRQn }, \
                                                   { WAKE_EDMA3_CH0_IRQn, WAKE_EDMA3_CH1_IRQn, WAKE_EDMA3_CH2_IRQn, WAKE_EDMA3_CH3_IRQn, WAKE_EDMA3_CH4_IRQn, WAKE_EDMA3_CH5_IRQn, WAKE_EDMA3_CH6_IRQn, WAKE_EDMA3_CH7_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn } }

/* DMA5 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MAIN__EDMA5 base address */
  #define MAIN__EDMA5_BASE                         (0x50300000u)
  /** Peripheral MAIN__EDMA5 base address */
  #define MAIN__EDMA5_BASE_NS                      (0x40300000u)
  /** Peripheral MAIN__EDMA5 base pointer */
  #define MAIN__EDMA5                              ((DMA5_Type *)MAIN__EDMA5_BASE)
  /** Peripheral MAIN__EDMA5 base pointer */
  #define MAIN__EDMA5_NS                           ((DMA5_Type *)MAIN__EDMA5_BASE_NS)
  /** Array initializer of DMA5 peripheral base addresses */
  #define DMA5_BASE_ADDRS                          { MAIN__EDMA5_BASE }
  /** Array initializer of DMA5 peripheral base pointers */
  #define DMA5_BASE_PTRS                           { MAIN__EDMA5 }
  /** Array initializer of DMA5 peripheral base addresses */
  #define DMA5_BASE_ADDRS_NS                       { MAIN__EDMA5_BASE_NS }
  /** Array initializer of DMA5 peripheral base pointers */
  #define DMA5_BASE_PTRS_NS                        { MAIN__EDMA5_NS }
#else
  /** Peripheral MAIN__EDMA5 base address */
  #define MAIN__EDMA5_BASE                         (0x40300000u)
  /** Peripheral MAIN__EDMA5 base pointer */
  #define MAIN__EDMA5                              ((DMA5_Type *)MAIN__EDMA5_BASE)
  /** Array initializer of DMA5 peripheral base addresses */
  #define DMA5_BASE_ADDRS                          { MAIN__EDMA5_BASE }
  /** Array initializer of DMA5 peripheral base pointers */
  #define DMA5_BASE_PTRS                           { MAIN__EDMA5 }
#endif
/** Interrupt vectors for the DMA5 peripheral type */
#define DMA5_IRQS                                { { MAIN_EDMA5_CH0_IRQn, MAIN_EDMA5_CH1_IRQn, MAIN_EDMA5_CH2_IRQn, MAIN_EDMA5_CH3_IRQn, MAIN_EDMA5_CH4_IRQn, MAIN_EDMA5_CH5_IRQn, MAIN_EDMA5_CH6_IRQn, MAIN_EDMA5_CH7_IRQn, MAIN_EDMA5_CH8_IRQn, MAIN_EDMA5_CH9_IRQn, MAIN_EDMA5_CH10_IRQn, MAIN_EDMA5_CH11_IRQn, MAIN_EDMA5_CH12_IRQn, MAIN_EDMA5_CH13_IRQn, MAIN_EDMA5_CH14_IRQn, MAIN_EDMA5_CH15_IRQn } }

/* ENET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral COMM__ENET base address */
  #define COMM__ENET_BASE                          (0x5A0D0000u)
  /** Peripheral COMM__ENET base address */
  #define COMM__ENET_BASE_NS                       (0x4A0D0000u)
  /** Peripheral COMM__ENET base pointer */
  #define COMM__ENET                               ((ENET_Type *)COMM__ENET_BASE)
  /** Peripheral COMM__ENET base pointer */
  #define COMM__ENET_NS                            ((ENET_Type *)COMM__ENET_BASE_NS)
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS                          { COMM__ENET_BASE }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS                           { COMM__ENET }
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS_NS                       { COMM__ENET_BASE_NS }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS_NS                        { COMM__ENET_NS }
#else
  /** Peripheral COMM__ENET base address */
  #define COMM__ENET_BASE                          (0x4A0D0000u)
  /** Peripheral COMM__ENET base pointer */
  #define COMM__ENET                               ((ENET_Type *)COMM__ENET_BASE)
  /** Array initializer of ENET peripheral base addresses */
  #define ENET_BASE_ADDRS                          { COMM__ENET_BASE }
  /** Array initializer of ENET peripheral base pointers */
  #define ENET_BASE_PTRS                           { COMM__ENET }
#endif
/** Interrupt vectors for the ENET peripheral type */
#define ENET_Transmit_IRQS                       { COMM_ENET_TX_IRQn }
#define ENET_Receive_IRQS                        { COMM_ENET_RX_IRQn }
#define ENET_Error_IRQS                          { COMM_ENET_OTHER_IRQn }
#define ENET_1588_Timer_IRQS                     { COMM_ENET_1588_IRQn }
#define ENET_Ts_IRQS                             { COMM_ENET_TX_IRQn }
/* ENET Buffer Descriptor and Buffer Address Alignment. */
#define ENET_BUFF_ALIGNMENT                      (64U)


/* ENET_QOS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral COMM__ENET_QOS base address */
  #define COMM__ENET_QOS_BASE                      (0x5A0C0000u)
  /** Peripheral COMM__ENET_QOS base address */
  #define COMM__ENET_QOS_BASE_NS                   (0x4A0C0000u)
  /** Peripheral COMM__ENET_QOS base pointer */
  #define COMM__ENET_QOS                           ((ENET_QOS_Type *)COMM__ENET_QOS_BASE)
  /** Peripheral COMM__ENET_QOS base pointer */
  #define COMM__ENET_QOS_NS                        ((ENET_QOS_Type *)COMM__ENET_QOS_BASE_NS)
  /** Array initializer of ENET_QOS peripheral base addresses */
  #define ENET_QOS_BASE_ADDRS                      { COMM__ENET_QOS_BASE }
  /** Array initializer of ENET_QOS peripheral base pointers */
  #define ENET_QOS_BASE_PTRS                       { COMM__ENET_QOS }
  /** Array initializer of ENET_QOS peripheral base addresses */
  #define ENET_QOS_BASE_ADDRS_NS                   { COMM__ENET_QOS_BASE_NS }
  /** Array initializer of ENET_QOS peripheral base pointers */
  #define ENET_QOS_BASE_PTRS_NS                    { COMM__ENET_QOS_NS }
#else
  /** Peripheral COMM__ENET_QOS base address */
  #define COMM__ENET_QOS_BASE                      (0x4A0C0000u)
  /** Peripheral COMM__ENET_QOS base pointer */
  #define COMM__ENET_QOS                           ((ENET_QOS_Type *)COMM__ENET_QOS_BASE)
  /** Array initializer of ENET_QOS peripheral base addresses */
  #define ENET_QOS_BASE_ADDRS                      { COMM__ENET_QOS_BASE }
  /** Array initializer of ENET_QOS peripheral base pointers */
  #define ENET_QOS_BASE_PTRS                       { COMM__ENET_QOS }
#endif
/** Interrupt vectors for the ENET_QOS peripheral type */
#define ENET_QOS_IRQS                            { COMM_ENET_QOS_IRQn }

/* EQDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__EQDC_0 base address */
  #define HSP__EQDC_0_BASE                         (0x520C0000u)
  /** Peripheral HSP__EQDC_0 base address */
  #define HSP__EQDC_0_BASE_NS                      (0x420C0000u)
  /** Peripheral HSP__EQDC_0 base pointer */
  #define HSP__EQDC_0                              ((EQDC_Type *)HSP__EQDC_0_BASE)
  /** Peripheral HSP__EQDC_0 base pointer */
  #define HSP__EQDC_0_NS                           ((EQDC_Type *)HSP__EQDC_0_BASE_NS)
  /** Peripheral HSP__EQDC_1 base address */
  #define HSP__EQDC_1_BASE                         (0x520D0000u)
  /** Peripheral HSP__EQDC_1 base address */
  #define HSP__EQDC_1_BASE_NS                      (0x420D0000u)
  /** Peripheral HSP__EQDC_1 base pointer */
  #define HSP__EQDC_1                              ((EQDC_Type *)HSP__EQDC_1_BASE)
  /** Peripheral HSP__EQDC_1 base pointer */
  #define HSP__EQDC_1_NS                           ((EQDC_Type *)HSP__EQDC_1_BASE_NS)
  /** Peripheral HSP__EQDC_2 base address */
  #define HSP__EQDC_2_BASE                         (0x528C0000u)
  /** Peripheral HSP__EQDC_2 base address */
  #define HSP__EQDC_2_BASE_NS                      (0x428C0000u)
  /** Peripheral HSP__EQDC_2 base pointer */
  #define HSP__EQDC_2                              ((EQDC_Type *)HSP__EQDC_2_BASE)
  /** Peripheral HSP__EQDC_2 base pointer */
  #define HSP__EQDC_2_NS                           ((EQDC_Type *)HSP__EQDC_2_BASE_NS)
  /** Peripheral HSP__EQDC_3 base address */
  #define HSP__EQDC_3_BASE                         (0x528D0000u)
  /** Peripheral HSP__EQDC_3 base address */
  #define HSP__EQDC_3_BASE_NS                      (0x428D0000u)
  /** Peripheral HSP__EQDC_3 base pointer */
  #define HSP__EQDC_3                              ((EQDC_Type *)HSP__EQDC_3_BASE)
  /** Peripheral HSP__EQDC_3 base pointer */
  #define HSP__EQDC_3_NS                           ((EQDC_Type *)HSP__EQDC_3_BASE_NS)
  /** Array initializer of EQDC peripheral base addresses */
  #define EQDC_BASE_ADDRS                          { HSP__EQDC_0_BASE, HSP__EQDC_1_BASE, HSP__EQDC_2_BASE, HSP__EQDC_3_BASE }
  /** Array initializer of EQDC peripheral base pointers */
  #define EQDC_BASE_PTRS                           { HSP__EQDC_0, HSP__EQDC_1, HSP__EQDC_2, HSP__EQDC_3 }
  /** Array initializer of EQDC peripheral base addresses */
  #define EQDC_BASE_ADDRS_NS                       { HSP__EQDC_0_BASE_NS, HSP__EQDC_1_BASE_NS, HSP__EQDC_2_BASE_NS, HSP__EQDC_3_BASE_NS }
  /** Array initializer of EQDC peripheral base pointers */
  #define EQDC_BASE_PTRS_NS                        { HSP__EQDC_0_NS, HSP__EQDC_1_NS, HSP__EQDC_2_NS, HSP__EQDC_3_NS }
#else
  /** Peripheral HSP__EQDC_0 base address */
  #define HSP__EQDC_0_BASE                         (0x420C0000u)
  /** Peripheral HSP__EQDC_0 base pointer */
  #define HSP__EQDC_0                              ((EQDC_Type *)HSP__EQDC_0_BASE)
  /** Peripheral HSP__EQDC_1 base address */
  #define HSP__EQDC_1_BASE                         (0x420D0000u)
  /** Peripheral HSP__EQDC_1 base pointer */
  #define HSP__EQDC_1                              ((EQDC_Type *)HSP__EQDC_1_BASE)
  /** Peripheral HSP__EQDC_2 base address */
  #define HSP__EQDC_2_BASE                         (0x428C0000u)
  /** Peripheral HSP__EQDC_2 base pointer */
  #define HSP__EQDC_2                              ((EQDC_Type *)HSP__EQDC_2_BASE)
  /** Peripheral HSP__EQDC_3 base address */
  #define HSP__EQDC_3_BASE                         (0x428D0000u)
  /** Peripheral HSP__EQDC_3 base pointer */
  #define HSP__EQDC_3                              ((EQDC_Type *)HSP__EQDC_3_BASE)
  /** Array initializer of EQDC peripheral base addresses */
  #define EQDC_BASE_ADDRS                          { HSP__EQDC_0_BASE, HSP__EQDC_1_BASE, HSP__EQDC_2_BASE, HSP__EQDC_3_BASE }
  /** Array initializer of EQDC peripheral base pointers */
  #define EQDC_BASE_PTRS                           { HSP__EQDC_0, HSP__EQDC_1, HSP__EQDC_2, HSP__EQDC_3 }
#endif
/** Interrupt vectors for the EQDC peripheral type */
#define EQDC_COMPARE_IRQS                        { HSP_EQDC0_IRQn, HSP_EQDC1_IRQn, HSP_EQDC2_IRQn, HSP_EQDC3_IRQn }
#define EQDC_HOME_IRQS                           { HSP_EQDC0_IRQn, HSP_EQDC1_IRQn, HSP_EQDC2_IRQn, HSP_EQDC3_IRQn }
#define EQDC_WDOG_IRQS                           { HSP_EQDC0_IRQn, HSP_EQDC1_IRQn, HSP_EQDC2_IRQn, HSP_EQDC3_IRQn }
#define EQDC_INDEX_IRQS                          { HSP_EQDC0_IRQn, HSP_EQDC1_IRQn, HSP_EQDC2_IRQn, HSP_EQDC3_IRQn }
#define EQDC_INPUT_SWITCH_IRQS                   { HSP_EQDC0_IRQn, HSP_EQDC1_IRQn, HSP_EQDC2_IRQn, HSP_EQDC3_IRQn }

/* EVTG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__EVTG_0 base address */
  #define HSP__EVTG_0_BASE                         (0x52000000u)
  /** Peripheral HSP__EVTG_0 base address */
  #define HSP__EVTG_0_BASE_NS                      (0x42000000u)
  /** Peripheral HSP__EVTG_0 base pointer */
  #define HSP__EVTG_0                              ((EVTG_Type *)HSP__EVTG_0_BASE)
  /** Peripheral HSP__EVTG_0 base pointer */
  #define HSP__EVTG_0_NS                           ((EVTG_Type *)HSP__EVTG_0_BASE_NS)
  /** Peripheral HSP__EVTG_1 base address */
  #define HSP__EVTG_1_BASE                         (0x52010000u)
  /** Peripheral HSP__EVTG_1 base address */
  #define HSP__EVTG_1_BASE_NS                      (0x42010000u)
  /** Peripheral HSP__EVTG_1 base pointer */
  #define HSP__EVTG_1                              ((EVTG_Type *)HSP__EVTG_1_BASE)
  /** Peripheral HSP__EVTG_1 base pointer */
  #define HSP__EVTG_1_NS                           ((EVTG_Type *)HSP__EVTG_1_BASE_NS)
  /** Peripheral HSP__EVTG_2 base address */
  #define HSP__EVTG_2_BASE                         (0x52800000u)
  /** Peripheral HSP__EVTG_2 base address */
  #define HSP__EVTG_2_BASE_NS                      (0x42800000u)
  /** Peripheral HSP__EVTG_2 base pointer */
  #define HSP__EVTG_2                              ((EVTG_Type *)HSP__EVTG_2_BASE)
  /** Peripheral HSP__EVTG_2 base pointer */
  #define HSP__EVTG_2_NS                           ((EVTG_Type *)HSP__EVTG_2_BASE_NS)
  /** Peripheral HSP__EVTG_3 base address */
  #define HSP__EVTG_3_BASE                         (0x52810000u)
  /** Peripheral HSP__EVTG_3 base address */
  #define HSP__EVTG_3_BASE_NS                      (0x42810000u)
  /** Peripheral HSP__EVTG_3 base pointer */
  #define HSP__EVTG_3                              ((EVTG_Type *)HSP__EVTG_3_BASE)
  /** Peripheral HSP__EVTG_3 base pointer */
  #define HSP__EVTG_3_NS                           ((EVTG_Type *)HSP__EVTG_3_BASE_NS)
  /** Array initializer of EVTG peripheral base addresses */
  #define EVTG_BASE_ADDRS                          { HSP__EVTG_0_BASE, HSP__EVTG_1_BASE, HSP__EVTG_2_BASE, HSP__EVTG_3_BASE }
  /** Array initializer of EVTG peripheral base pointers */
  #define EVTG_BASE_PTRS                           { HSP__EVTG_0, HSP__EVTG_1, HSP__EVTG_2, HSP__EVTG_3 }
  /** Array initializer of EVTG peripheral base addresses */
  #define EVTG_BASE_ADDRS_NS                       { HSP__EVTG_0_BASE_NS, HSP__EVTG_1_BASE_NS, HSP__EVTG_2_BASE_NS, HSP__EVTG_3_BASE_NS }
  /** Array initializer of EVTG peripheral base pointers */
  #define EVTG_BASE_PTRS_NS                        { HSP__EVTG_0_NS, HSP__EVTG_1_NS, HSP__EVTG_2_NS, HSP__EVTG_3_NS }
#else
  /** Peripheral HSP__EVTG_0 base address */
  #define HSP__EVTG_0_BASE                         (0x42000000u)
  /** Peripheral HSP__EVTG_0 base pointer */
  #define HSP__EVTG_0                              ((EVTG_Type *)HSP__EVTG_0_BASE)
  /** Peripheral HSP__EVTG_1 base address */
  #define HSP__EVTG_1_BASE                         (0x42010000u)
  /** Peripheral HSP__EVTG_1 base pointer */
  #define HSP__EVTG_1                              ((EVTG_Type *)HSP__EVTG_1_BASE)
  /** Peripheral HSP__EVTG_2 base address */
  #define HSP__EVTG_2_BASE                         (0x42800000u)
  /** Peripheral HSP__EVTG_2 base pointer */
  #define HSP__EVTG_2                              ((EVTG_Type *)HSP__EVTG_2_BASE)
  /** Peripheral HSP__EVTG_3 base address */
  #define HSP__EVTG_3_BASE                         (0x42810000u)
  /** Peripheral HSP__EVTG_3 base pointer */
  #define HSP__EVTG_3                              ((EVTG_Type *)HSP__EVTG_3_BASE)
  /** Array initializer of EVTG peripheral base addresses */
  #define EVTG_BASE_ADDRS                          { HSP__EVTG_0_BASE, HSP__EVTG_1_BASE, HSP__EVTG_2_BASE, HSP__EVTG_3_BASE }
  /** Array initializer of EVTG peripheral base pointers */
  #define EVTG_BASE_PTRS                           { HSP__EVTG_0, HSP__EVTG_1, HSP__EVTG_2, HSP__EVTG_3 }
#endif

/* EWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKE__EWM base address */
  #define WAKE__EWM_BASE                           (0x56110000u)
  /** Peripheral WAKE__EWM base address */
  #define WAKE__EWM_BASE_NS                        (0x46110000u)
  /** Peripheral WAKE__EWM base pointer */
  #define WAKE__EWM                                ((EWM_Type *)WAKE__EWM_BASE)
  /** Peripheral WAKE__EWM base pointer */
  #define WAKE__EWM_NS                             ((EWM_Type *)WAKE__EWM_BASE_NS)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { WAKE__EWM_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { WAKE__EWM }
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS_NS                        { WAKE__EWM_BASE_NS }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS_NS                         { WAKE__EWM_NS }
#else
  /** Peripheral WAKE__EWM base address */
  #define WAKE__EWM_BASE                           (0x46110000u)
  /** Peripheral WAKE__EWM base pointer */
  #define WAKE__EWM                                ((EWM_Type *)WAKE__EWM_BASE)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { WAKE__EWM_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { WAKE__EWM }
#endif
/** Interrupt vectors for the EWM peripheral type */
#define EWM_IRQS                                 { WAKE_EWM_IRQn }

/* FLEXIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__FLEXIO_0 base address */
  #define HSP__FLEXIO_0_BASE                       (0x52110000u)
  /** Peripheral HSP__FLEXIO_0 base address */
  #define HSP__FLEXIO_0_BASE_NS                    (0x42110000u)
  /** Peripheral HSP__FLEXIO_0 base pointer */
  #define HSP__FLEXIO_0                            ((FLEXIO_Type *)HSP__FLEXIO_0_BASE)
  /** Peripheral HSP__FLEXIO_0 base pointer */
  #define HSP__FLEXIO_0_NS                         ((FLEXIO_Type *)HSP__FLEXIO_0_BASE_NS)
  /** Peripheral HSP__FLEXIO_1 base address */
  #define HSP__FLEXIO_1_BASE                       (0x52120000u)
  /** Peripheral HSP__FLEXIO_1 base address */
  #define HSP__FLEXIO_1_BASE_NS                    (0x42120000u)
  /** Peripheral HSP__FLEXIO_1 base pointer */
  #define HSP__FLEXIO_1                            ((FLEXIO_Type *)HSP__FLEXIO_1_BASE)
  /** Peripheral HSP__FLEXIO_1 base pointer */
  #define HSP__FLEXIO_1_NS                         ((FLEXIO_Type *)HSP__FLEXIO_1_BASE_NS)
  /** Peripheral HSP__FLEXIO_2 base address */
  #define HSP__FLEXIO_2_BASE                       (0x52900000u)
  /** Peripheral HSP__FLEXIO_2 base address */
  #define HSP__FLEXIO_2_BASE_NS                    (0x42900000u)
  /** Peripheral HSP__FLEXIO_2 base pointer */
  #define HSP__FLEXIO_2                            ((FLEXIO_Type *)HSP__FLEXIO_2_BASE)
  /** Peripheral HSP__FLEXIO_2 base pointer */
  #define HSP__FLEXIO_2_NS                         ((FLEXIO_Type *)HSP__FLEXIO_2_BASE_NS)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { HSP__FLEXIO_0_BASE, HSP__FLEXIO_1_BASE, HSP__FLEXIO_2_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { HSP__FLEXIO_0, HSP__FLEXIO_1, HSP__FLEXIO_2 }
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS_NS                     { HSP__FLEXIO_0_BASE_NS, HSP__FLEXIO_1_BASE_NS, HSP__FLEXIO_2_BASE_NS }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS_NS                      { HSP__FLEXIO_0_NS, HSP__FLEXIO_1_NS, HSP__FLEXIO_2_NS }
#else
  /** Peripheral HSP__FLEXIO_0 base address */
  #define HSP__FLEXIO_0_BASE                       (0x42110000u)
  /** Peripheral HSP__FLEXIO_0 base pointer */
  #define HSP__FLEXIO_0                            ((FLEXIO_Type *)HSP__FLEXIO_0_BASE)
  /** Peripheral HSP__FLEXIO_1 base address */
  #define HSP__FLEXIO_1_BASE                       (0x42120000u)
  /** Peripheral HSP__FLEXIO_1 base pointer */
  #define HSP__FLEXIO_1                            ((FLEXIO_Type *)HSP__FLEXIO_1_BASE)
  /** Peripheral HSP__FLEXIO_2 base address */
  #define HSP__FLEXIO_2_BASE                       (0x42900000u)
  /** Peripheral HSP__FLEXIO_2 base pointer */
  #define HSP__FLEXIO_2                            ((FLEXIO_Type *)HSP__FLEXIO_2_BASE)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { HSP__FLEXIO_0_BASE, HSP__FLEXIO_1_BASE, HSP__FLEXIO_2_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { HSP__FLEXIO_0, HSP__FLEXIO_1, HSP__FLEXIO_2 }
#endif
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { HSP_FLEXIO0_IRQn, HSP_FLEXIO1_IRQn, HSP_FLEXIO2_IRQn }

/* FLEXSPI_SLV - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral COMM__FLEXSPI_FLR base address */
  #define COMM__FLEXSPI_FLR_BASE                   (0x5A0E0000u)
  /** Peripheral COMM__FLEXSPI_FLR base address */
  #define COMM__FLEXSPI_FLR_BASE_NS                (0x4A0E0000u)
  /** Peripheral COMM__FLEXSPI_FLR base pointer */
  #define COMM__FLEXSPI_FLR                        ((FLEXSPI_SLV_Type *)COMM__FLEXSPI_FLR_BASE)
  /** Peripheral COMM__FLEXSPI_FLR base pointer */
  #define COMM__FLEXSPI_FLR_NS                     ((FLEXSPI_SLV_Type *)COMM__FLEXSPI_FLR_BASE_NS)
  /** Array initializer of FLEXSPI_SLV peripheral base addresses */
  #define FLEXSPI_SLV_BASE_ADDRS                   { COMM__FLEXSPI_FLR_BASE }
  /** Array initializer of FLEXSPI_SLV peripheral base pointers */
  #define FLEXSPI_SLV_BASE_PTRS                    { COMM__FLEXSPI_FLR }
  /** Array initializer of FLEXSPI_SLV peripheral base addresses */
  #define FLEXSPI_SLV_BASE_ADDRS_NS                { COMM__FLEXSPI_FLR_BASE_NS }
  /** Array initializer of FLEXSPI_SLV peripheral base pointers */
  #define FLEXSPI_SLV_BASE_PTRS_NS                 { COMM__FLEXSPI_FLR_NS }
#else
  /** Peripheral COMM__FLEXSPI_FLR base address */
  #define COMM__FLEXSPI_FLR_BASE                   (0x4A0E0000u)
  /** Peripheral COMM__FLEXSPI_FLR base pointer */
  #define COMM__FLEXSPI_FLR                        ((FLEXSPI_SLV_Type *)COMM__FLEXSPI_FLR_BASE)
  /** Array initializer of FLEXSPI_SLV peripheral base addresses */
  #define FLEXSPI_SLV_BASE_ADDRS                   { COMM__FLEXSPI_FLR_BASE }
  /** Array initializer of FLEXSPI_SLV peripheral base pointers */
  #define FLEXSPI_SLV_BASE_PTRS                    { COMM__FLEXSPI_FLR }
#endif
/** Interrupt vectors for the FLEXSPI_SLV peripheral type */
#define FLEXSPI_SLV_IRQS                         { COMM_FLEXSPI_SLV_IRQn }

/* FREQME - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO__FREQME base address */
  #define AUDIO__FREQME_BASE                       (0x58090000u)
  /** Peripheral AUDIO__FREQME base address */
  #define AUDIO__FREQME_BASE_NS                    (0x48090000u)
  /** Peripheral AUDIO__FREQME base pointer */
  #define AUDIO__FREQME                            ((FREQME_Type *)AUDIO__FREQME_BASE)
  /** Peripheral AUDIO__FREQME base pointer */
  #define AUDIO__FREQME_NS                         ((FREQME_Type *)AUDIO__FREQME_BASE_NS)
  /** Peripheral CMPT__FREQME base address */
  #define CMPT__FREQME_BASE                        (0x541D0000u)
  /** Peripheral CMPT__FREQME base address */
  #define CMPT__FREQME_BASE_NS                     (0x441D0000u)
  /** Peripheral CMPT__FREQME base pointer */
  #define CMPT__FREQME                             ((FREQME_Type *)CMPT__FREQME_BASE)
  /** Peripheral CMPT__FREQME base pointer */
  #define CMPT__FREQME_NS                          ((FREQME_Type *)CMPT__FREQME_BASE_NS)
  /** Peripheral COMM__FREQME base address */
  #define COMM__FREQME_BASE                        (0x5A120000u)
  /** Peripheral COMM__FREQME base address */
  #define COMM__FREQME_BASE_NS                     (0x4A120000u)
  /** Peripheral COMM__FREQME base pointer */
  #define COMM__FREQME                             ((FREQME_Type *)COMM__FREQME_BASE)
  /** Peripheral COMM__FREQME base pointer */
  #define COMM__FREQME_NS                          ((FREQME_Type *)COMM__FREQME_BASE_NS)
  /** Peripheral MAIN__FREQME base address */
  #define MAIN__FREQME_BASE                        (0x50410000u)
  /** Peripheral MAIN__FREQME base address */
  #define MAIN__FREQME_BASE_NS                     (0x40410000u)
  /** Peripheral MAIN__FREQME base pointer */
  #define MAIN__FREQME                             ((FREQME_Type *)MAIN__FREQME_BASE)
  /** Peripheral MAIN__FREQME base pointer */
  #define MAIN__FREQME_NS                          ((FREQME_Type *)MAIN__FREQME_BASE_NS)
  /** Peripheral MEDIA__FREQME base address */
  #define MEDIA__FREQME_BASE                       (0x5C100000u)
  /** Peripheral MEDIA__FREQME base address */
  #define MEDIA__FREQME_BASE_NS                    (0x4C100000u)
  /** Peripheral MEDIA__FREQME base pointer */
  #define MEDIA__FREQME                            ((FREQME_Type *)MEDIA__FREQME_BASE)
  /** Peripheral MEDIA__FREQME base pointer */
  #define MEDIA__FREQME_NS                         ((FREQME_Type *)MEDIA__FREQME_BASE_NS)
  /** Peripheral SYSCON__FREQME base address */
  #define SYSCON__FREQME_BASE                      (0x50590000u)
  /** Peripheral SYSCON__FREQME base address */
  #define SYSCON__FREQME_BASE_NS                   (0x40590000u)
  /** Peripheral SYSCON__FREQME base pointer */
  #define SYSCON__FREQME                           ((FREQME_Type *)SYSCON__FREQME_BASE)
  /** Peripheral SYSCON__FREQME base pointer */
  #define SYSCON__FREQME_NS                        ((FREQME_Type *)SYSCON__FREQME_BASE_NS)
  /** Peripheral WAKE__FREQME base address */
  #define WAKE__FREQME_BASE                        (0x56080000u)
  /** Peripheral WAKE__FREQME base address */
  #define WAKE__FREQME_BASE_NS                     (0x46080000u)
  /** Peripheral WAKE__FREQME base pointer */
  #define WAKE__FREQME                             ((FREQME_Type *)WAKE__FREQME_BASE)
  /** Peripheral WAKE__FREQME base pointer */
  #define WAKE__FREQME_NS                          ((FREQME_Type *)WAKE__FREQME_BASE_NS)
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS                        { AUDIO__FREQME_BASE, CMPT__FREQME_BASE, COMM__FREQME_BASE, MAIN__FREQME_BASE, MEDIA__FREQME_BASE, SYSCON__FREQME_BASE, WAKE__FREQME_BASE }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS                         { AUDIO__FREQME, CMPT__FREQME, COMM__FREQME, MAIN__FREQME, MEDIA__FREQME, SYSCON__FREQME, WAKE__FREQME }
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS_NS                     { AUDIO__FREQME_BASE_NS, CMPT__FREQME_BASE_NS, COMM__FREQME_BASE_NS, MAIN__FREQME_BASE_NS, MEDIA__FREQME_BASE_NS, SYSCON__FREQME_BASE_NS, WAKE__FREQME_BASE_NS }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS_NS                      { AUDIO__FREQME_NS, CMPT__FREQME_NS, COMM__FREQME_NS, MAIN__FREQME_NS, MEDIA__FREQME_NS, SYSCON__FREQME_NS, WAKE__FREQME_NS }
#else
  /** Peripheral AUDIO__FREQME base address */
  #define AUDIO__FREQME_BASE                       (0x48090000u)
  /** Peripheral AUDIO__FREQME base pointer */
  #define AUDIO__FREQME                            ((FREQME_Type *)AUDIO__FREQME_BASE)
  /** Peripheral CMPT__FREQME base address */
  #define CMPT__FREQME_BASE                        (0x441D0000u)
  /** Peripheral CMPT__FREQME base pointer */
  #define CMPT__FREQME                             ((FREQME_Type *)CMPT__FREQME_BASE)
  /** Peripheral COMM__FREQME base address */
  #define COMM__FREQME_BASE                        (0x4A120000u)
  /** Peripheral COMM__FREQME base pointer */
  #define COMM__FREQME                             ((FREQME_Type *)COMM__FREQME_BASE)
  /** Peripheral MAIN__FREQME base address */
  #define MAIN__FREQME_BASE                        (0x40410000u)
  /** Peripheral MAIN__FREQME base pointer */
  #define MAIN__FREQME                             ((FREQME_Type *)MAIN__FREQME_BASE)
  /** Peripheral MEDIA__FREQME base address */
  #define MEDIA__FREQME_BASE                       (0x4C100000u)
  /** Peripheral MEDIA__FREQME base pointer */
  #define MEDIA__FREQME                            ((FREQME_Type *)MEDIA__FREQME_BASE)
  /** Peripheral SYSCON__FREQME base address */
  #define SYSCON__FREQME_BASE                      (0x40590000u)
  /** Peripheral SYSCON__FREQME base pointer */
  #define SYSCON__FREQME                           ((FREQME_Type *)SYSCON__FREQME_BASE)
  /** Peripheral WAKE__FREQME base address */
  #define WAKE__FREQME_BASE                        (0x46080000u)
  /** Peripheral WAKE__FREQME base pointer */
  #define WAKE__FREQME                             ((FREQME_Type *)WAKE__FREQME_BASE)
  /** Array initializer of FREQME peripheral base addresses */
  #define FREQME_BASE_ADDRS                        { AUDIO__FREQME_BASE, CMPT__FREQME_BASE, COMM__FREQME_BASE, MAIN__FREQME_BASE, MEDIA__FREQME_BASE, SYSCON__FREQME_BASE, WAKE__FREQME_BASE }
  /** Array initializer of FREQME peripheral base pointers */
  #define FREQME_BASE_PTRS                         { AUDIO__FREQME, CMPT__FREQME, COMM__FREQME, MAIN__FREQME, MEDIA__FREQME, SYSCON__FREQME, WAKE__FREQME }
#endif
/** Interrupt vectors for the FREQME peripheral type */
#define FREQME_IRQS                              { AUDIO_FREQME_IRQn, CMPT_FREQME_IRQn, COMM_FREQME_IRQn, MAIN_FREQME_IRQn, MEDIA_FREQME_IRQn, SYSCON_FREQME_IRQn, WAKE_FREQME_IRQn }

/* FSB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MAIN__FSB base address */
  #define MAIN__FSB_BASE                           (0x50600000u)
  /** Peripheral MAIN__FSB base address */
  #define MAIN__FSB_BASE_NS                        (0x40600000u)
  /** Peripheral MAIN__FSB base pointer */
  #define MAIN__FSB                                ((FSB_Type *)MAIN__FSB_BASE)
  /** Peripheral MAIN__FSB base pointer */
  #define MAIN__FSB_NS                             ((FSB_Type *)MAIN__FSB_BASE_NS)
  /** Array initializer of FSB peripheral base addresses */
  #define FSB_BASE_ADDRS                           { MAIN__FSB_BASE }
  /** Array initializer of FSB peripheral base pointers */
  #define FSB_BASE_PTRS                            { MAIN__FSB }
  /** Array initializer of FSB peripheral base addresses */
  #define FSB_BASE_ADDRS_NS                        { MAIN__FSB_BASE_NS }
  /** Array initializer of FSB peripheral base pointers */
  #define FSB_BASE_PTRS_NS                         { MAIN__FSB_NS }
#else
  /** Peripheral MAIN__FSB base address */
  #define MAIN__FSB_BASE                           (0x40600000u)
  /** Peripheral MAIN__FSB base pointer */
  #define MAIN__FSB                                ((FSB_Type *)MAIN__FSB_BASE)
  /** Array initializer of FSB peripheral base addresses */
  #define FSB_BASE_ADDRS                           { MAIN__FSB_BASE }
  /** Array initializer of FSB peripheral base pointers */
  #define FSB_BASE_PTRS                            { MAIN__FSB }
#endif

/* GPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__GPIO_0 base address */
  #define HSP__GPIO_0_BASE                         (0x53800000u)
  /** Peripheral HSP__GPIO_0 base address */
  #define HSP__GPIO_0_BASE_NS                      (0x43800000u)
  /** Peripheral HSP__GPIO_0 base pointer */
  #define HSP__GPIO_0                              ((GPIO_Type *)HSP__GPIO_0_BASE)
  /** Peripheral HSP__GPIO_0 base pointer */
  #define HSP__GPIO_0_NS                           ((GPIO_Type *)HSP__GPIO_0_BASE_NS)
  /** Peripheral HSP__GPIO_1 base address */
  #define HSP__GPIO_1_BASE                         (0x53810000u)
  /** Peripheral HSP__GPIO_1 base address */
  #define HSP__GPIO_1_BASE_NS                      (0x43810000u)
  /** Peripheral HSP__GPIO_1 base pointer */
  #define HSP__GPIO_1                              ((GPIO_Type *)HSP__GPIO_1_BASE)
  /** Peripheral HSP__GPIO_1 base pointer */
  #define HSP__GPIO_1_NS                           ((GPIO_Type *)HSP__GPIO_1_BASE_NS)
  /** Peripheral HSP__GPIO_2 base address */
  #define HSP__GPIO_2_BASE                         (0x53820000u)
  /** Peripheral HSP__GPIO_2 base address */
  #define HSP__GPIO_2_BASE_NS                      (0x43820000u)
  /** Peripheral HSP__GPIO_2 base pointer */
  #define HSP__GPIO_2                              ((GPIO_Type *)HSP__GPIO_2_BASE)
  /** Peripheral HSP__GPIO_2 base pointer */
  #define HSP__GPIO_2_NS                           ((GPIO_Type *)HSP__GPIO_2_BASE_NS)
  /** Peripheral HSP__GPIO_3 base address */
  #define HSP__GPIO_3_BASE                         (0x53830000u)
  /** Peripheral HSP__GPIO_3 base address */
  #define HSP__GPIO_3_BASE_NS                      (0x43830000u)
  /** Peripheral HSP__GPIO_3 base pointer */
  #define HSP__GPIO_3                              ((GPIO_Type *)HSP__GPIO_3_BASE)
  /** Peripheral HSP__GPIO_3 base pointer */
  #define HSP__GPIO_3_NS                           ((GPIO_Type *)HSP__GPIO_3_BASE_NS)
  /** Peripheral HSP__GPIO_4 base address */
  #define HSP__GPIO_4_BASE                         (0x53840000u)
  /** Peripheral HSP__GPIO_4 base address */
  #define HSP__GPIO_4_BASE_NS                      (0x43840000u)
  /** Peripheral HSP__GPIO_4 base pointer */
  #define HSP__GPIO_4                              ((GPIO_Type *)HSP__GPIO_4_BASE)
  /** Peripheral HSP__GPIO_4 base pointer */
  #define HSP__GPIO_4_NS                           ((GPIO_Type *)HSP__GPIO_4_BASE_NS)
  /** Peripheral VBAT__GPIO base address */
  #define VBAT__GPIO_BASE                          (0x56350000u)
  /** Peripheral VBAT__GPIO base address */
  #define VBAT__GPIO_BASE_NS                       (0x46350000u)
  /** Peripheral VBAT__GPIO base pointer */
  #define VBAT__GPIO                               ((GPIO_Type *)VBAT__GPIO_BASE)
  /** Peripheral VBAT__GPIO base pointer */
  #define VBAT__GPIO_NS                            ((GPIO_Type *)VBAT__GPIO_BASE_NS)
  /** Peripheral WAKE__GPIO base address */
  #define WAKE__GPIO_BASE                          (0x56210000u)
  /** Peripheral WAKE__GPIO base address */
  #define WAKE__GPIO_BASE_NS                       (0x46210000u)
  /** Peripheral WAKE__GPIO base pointer */
  #define WAKE__GPIO                               ((GPIO_Type *)WAKE__GPIO_BASE)
  /** Peripheral WAKE__GPIO base pointer */
  #define WAKE__GPIO_NS                            ((GPIO_Type *)WAKE__GPIO_BASE_NS)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { HSP__GPIO_0_BASE, HSP__GPIO_1_BASE, HSP__GPIO_2_BASE, HSP__GPIO_3_BASE, HSP__GPIO_4_BASE, VBAT__GPIO_BASE, WAKE__GPIO_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { HSP__GPIO_0, HSP__GPIO_1, HSP__GPIO_2, HSP__GPIO_3, HSP__GPIO_4, VBAT__GPIO, WAKE__GPIO }
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS_NS                       { HSP__GPIO_0_BASE_NS, HSP__GPIO_1_BASE_NS, HSP__GPIO_2_BASE_NS, HSP__GPIO_3_BASE_NS, HSP__GPIO_4_BASE_NS, VBAT__GPIO_BASE_NS, WAKE__GPIO_BASE_NS }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS_NS                        { HSP__GPIO_0_NS, HSP__GPIO_1_NS, HSP__GPIO_2_NS, HSP__GPIO_3_NS, HSP__GPIO_4_NS, VBAT__GPIO_NS, WAKE__GPIO_NS }
#else
  /** Peripheral HSP__GPIO_0 base address */
  #define HSP__GPIO_0_BASE                         (0x43800000u)
  /** Peripheral HSP__GPIO_0 base pointer */
  #define HSP__GPIO_0                              ((GPIO_Type *)HSP__GPIO_0_BASE)
  /** Peripheral HSP__GPIO_1 base address */
  #define HSP__GPIO_1_BASE                         (0x43810000u)
  /** Peripheral HSP__GPIO_1 base pointer */
  #define HSP__GPIO_1                              ((GPIO_Type *)HSP__GPIO_1_BASE)
  /** Peripheral HSP__GPIO_2 base address */
  #define HSP__GPIO_2_BASE                         (0x43820000u)
  /** Peripheral HSP__GPIO_2 base pointer */
  #define HSP__GPIO_2                              ((GPIO_Type *)HSP__GPIO_2_BASE)
  /** Peripheral HSP__GPIO_3 base address */
  #define HSP__GPIO_3_BASE                         (0x43830000u)
  /** Peripheral HSP__GPIO_3 base pointer */
  #define HSP__GPIO_3                              ((GPIO_Type *)HSP__GPIO_3_BASE)
  /** Peripheral HSP__GPIO_4 base address */
  #define HSP__GPIO_4_BASE                         (0x43840000u)
  /** Peripheral HSP__GPIO_4 base pointer */
  #define HSP__GPIO_4                              ((GPIO_Type *)HSP__GPIO_4_BASE)
  /** Peripheral VBAT__GPIO base address */
  #define VBAT__GPIO_BASE                          (0x46350000u)
  /** Peripheral VBAT__GPIO base pointer */
  #define VBAT__GPIO                               ((GPIO_Type *)VBAT__GPIO_BASE)
  /** Peripheral WAKE__GPIO base address */
  #define WAKE__GPIO_BASE                          (0x46210000u)
  /** Peripheral WAKE__GPIO base pointer */
  #define WAKE__GPIO                               ((GPIO_Type *)WAKE__GPIO_BASE)
  /** Array initializer of GPIO peripheral base addresses */
  #define GPIO_BASE_ADDRS                          { HSP__GPIO_0_BASE, HSP__GPIO_1_BASE, HSP__GPIO_2_BASE, HSP__GPIO_3_BASE, HSP__GPIO_4_BASE, VBAT__GPIO_BASE, WAKE__GPIO_BASE }
  /** Array initializer of GPIO peripheral base pointers */
  #define GPIO_BASE_PTRS                           { HSP__GPIO_0, HSP__GPIO_1, HSP__GPIO_2, HSP__GPIO_3, HSP__GPIO_4, VBAT__GPIO, WAKE__GPIO }
#endif
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS                                { HSP_GPIO0_CH0_IRQn, HSP_GPIO1_CH0_IRQn, HSP_GPIO2_CH0_IRQn, HSP_GPIO3_CH0_IRQn, HSP_GPIO4_CH0_IRQn, VBAT_GPIO_CH0_IRQn, WAKE_GPIO_CH0_IRQn }
#define GPIO_1_IRQS                              { HSP_GPIO0_CH1_IRQn, HSP_GPIO1_CH1_IRQn, HSP_GPIO2_CH1_IRQn, HSP_GPIO3_CH1_IRQn, HSP_GPIO4_CH1_IRQn, VBAT_GPIO_CH1_IRQn, WAKE_GPIO_CH1_IRQn }
/* Backward compatibility */
#define GPIO_IRQS_1                              GPIO_1_IRQS


/* I2S - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO__SAI_0 base address */
  #define AUDIO__SAI_0_BASE                        (0x580C0000u)
  /** Peripheral AUDIO__SAI_0 base address */
  #define AUDIO__SAI_0_BASE_NS                     (0x480C0000u)
  /** Peripheral AUDIO__SAI_0 base pointer */
  #define AUDIO__SAI_0                             ((I2S_Type *)AUDIO__SAI_0_BASE)
  /** Peripheral AUDIO__SAI_0 base pointer */
  #define AUDIO__SAI_0_NS                          ((I2S_Type *)AUDIO__SAI_0_BASE_NS)
  /** Peripheral AUDIO__SAI_1 base address */
  #define AUDIO__SAI_1_BASE                        (0x580D0000u)
  /** Peripheral AUDIO__SAI_1 base address */
  #define AUDIO__SAI_1_BASE_NS                     (0x480D0000u)
  /** Peripheral AUDIO__SAI_1 base pointer */
  #define AUDIO__SAI_1                             ((I2S_Type *)AUDIO__SAI_1_BASE)
  /** Peripheral AUDIO__SAI_1 base pointer */
  #define AUDIO__SAI_1_NS                          ((I2S_Type *)AUDIO__SAI_1_BASE_NS)
  /** Peripheral AUDIO__SAI_2 base address */
  #define AUDIO__SAI_2_BASE                        (0x580E0000u)
  /** Peripheral AUDIO__SAI_2 base address */
  #define AUDIO__SAI_2_BASE_NS                     (0x480E0000u)
  /** Peripheral AUDIO__SAI_2 base pointer */
  #define AUDIO__SAI_2                             ((I2S_Type *)AUDIO__SAI_2_BASE)
  /** Peripheral AUDIO__SAI_2 base pointer */
  #define AUDIO__SAI_2_NS                          ((I2S_Type *)AUDIO__SAI_2_BASE_NS)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { AUDIO__SAI_0_BASE, AUDIO__SAI_1_BASE, AUDIO__SAI_2_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { AUDIO__SAI_0, AUDIO__SAI_1, AUDIO__SAI_2 }
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS_NS                        { AUDIO__SAI_0_BASE_NS, AUDIO__SAI_1_BASE_NS, AUDIO__SAI_2_BASE_NS }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS_NS                         { AUDIO__SAI_0_NS, AUDIO__SAI_1_NS, AUDIO__SAI_2_NS }
#else
  /** Peripheral AUDIO__SAI_0 base address */
  #define AUDIO__SAI_0_BASE                        (0x480C0000u)
  /** Peripheral AUDIO__SAI_0 base pointer */
  #define AUDIO__SAI_0                             ((I2S_Type *)AUDIO__SAI_0_BASE)
  /** Peripheral AUDIO__SAI_1 base address */
  #define AUDIO__SAI_1_BASE                        (0x480D0000u)
  /** Peripheral AUDIO__SAI_1 base pointer */
  #define AUDIO__SAI_1                             ((I2S_Type *)AUDIO__SAI_1_BASE)
  /** Peripheral AUDIO__SAI_2 base address */
  #define AUDIO__SAI_2_BASE                        (0x480E0000u)
  /** Peripheral AUDIO__SAI_2 base pointer */
  #define AUDIO__SAI_2                             ((I2S_Type *)AUDIO__SAI_2_BASE)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { AUDIO__SAI_0_BASE, AUDIO__SAI_1_BASE, AUDIO__SAI_2_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { AUDIO__SAI_0, AUDIO__SAI_1, AUDIO__SAI_2 }
#endif
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { AUDIO_SAI0_IRQn, AUDIO_SAI1_IRQn, AUDIO_SAI2_IRQn }
#define I2S_TX_IRQS                              { AUDIO_SAI0_IRQn, AUDIO_SAI1_IRQn, AUDIO_SAI2_IRQn }

/* I3C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__I3C base address */
  #define HSP__I3C_BASE                            (0x52130000u)
  /** Peripheral HSP__I3C base address */
  #define HSP__I3C_BASE_NS                         (0x42130000u)
  /** Peripheral HSP__I3C base pointer */
  #define HSP__I3C                                 ((I3C_Type *)HSP__I3C_BASE)
  /** Peripheral HSP__I3C base pointer */
  #define HSP__I3C_NS                              ((I3C_Type *)HSP__I3C_BASE_NS)
  /** Peripheral WAKE__I3C base address */
  #define WAKE__I3C_BASE                           (0x561B0000u)
  /** Peripheral WAKE__I3C base address */
  #define WAKE__I3C_BASE_NS                        (0x461B0000u)
  /** Peripheral WAKE__I3C base pointer */
  #define WAKE__I3C                                ((I3C_Type *)WAKE__I3C_BASE)
  /** Peripheral WAKE__I3C base pointer */
  #define WAKE__I3C_NS                             ((I3C_Type *)WAKE__I3C_BASE_NS)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { HSP__I3C_BASE, WAKE__I3C_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { HSP__I3C, WAKE__I3C }
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS_NS                        { HSP__I3C_BASE_NS, WAKE__I3C_BASE_NS }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS_NS                         { HSP__I3C_NS, WAKE__I3C_NS }
#else
  /** Peripheral HSP__I3C base address */
  #define HSP__I3C_BASE                            (0x42130000u)
  /** Peripheral HSP__I3C base pointer */
  #define HSP__I3C                                 ((I3C_Type *)HSP__I3C_BASE)
  /** Peripheral WAKE__I3C base address */
  #define WAKE__I3C_BASE                           (0x461B0000u)
  /** Peripheral WAKE__I3C base pointer */
  #define WAKE__I3C                                ((I3C_Type *)WAKE__I3C_BASE)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { HSP__I3C_BASE, WAKE__I3C_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { HSP__I3C, WAKE__I3C }
#endif
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { HSP_I3C_IRQn, WAKE_I3C_IRQn }

/* INPUTMUX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO__INPUTMUX base address */
  #define AUDIO__INPUTMUX_BASE                     (0x580A0000u)
  /** Peripheral AUDIO__INPUTMUX base address */
  #define AUDIO__INPUTMUX_BASE_NS                  (0x480A0000u)
  /** Peripheral AUDIO__INPUTMUX base pointer */
  #define AUDIO__INPUTMUX                          ((INPUTMUX_Type *)AUDIO__INPUTMUX_BASE)
  /** Peripheral AUDIO__INPUTMUX base pointer */
  #define AUDIO__INPUTMUX_NS                       ((INPUTMUX_Type *)AUDIO__INPUTMUX_BASE_NS)
  /** Peripheral CMPT__INPUTMUX base address */
  #define CMPT__INPUTMUX_BASE                      (0x541E0000u)
  /** Peripheral CMPT__INPUTMUX base address */
  #define CMPT__INPUTMUX_BASE_NS                   (0x441E0000u)
  /** Peripheral CMPT__INPUTMUX base pointer */
  #define CMPT__INPUTMUX                           ((INPUTMUX_Type *)CMPT__INPUTMUX_BASE)
  /** Peripheral CMPT__INPUTMUX base pointer */
  #define CMPT__INPUTMUX_NS                        ((INPUTMUX_Type *)CMPT__INPUTMUX_BASE_NS)
  /** Peripheral COMM__INPUTMUX base address */
  #define COMM__INPUTMUX_BASE                      (0x5A130000u)
  /** Peripheral COMM__INPUTMUX base address */
  #define COMM__INPUTMUX_BASE_NS                   (0x4A130000u)
  /** Peripheral COMM__INPUTMUX base pointer */
  #define COMM__INPUTMUX                           ((INPUTMUX_Type *)COMM__INPUTMUX_BASE)
  /** Peripheral COMM__INPUTMUX base pointer */
  #define COMM__INPUTMUX_NS                        ((INPUTMUX_Type *)COMM__INPUTMUX_BASE_NS)
  /** Peripheral MAIN__INPUTMUX base address */
  #define MAIN__INPUTMUX_BASE                      (0x50420000u)
  /** Peripheral MAIN__INPUTMUX base address */
  #define MAIN__INPUTMUX_BASE_NS                   (0x40420000u)
  /** Peripheral MAIN__INPUTMUX base pointer */
  #define MAIN__INPUTMUX                           ((INPUTMUX_Type *)MAIN__INPUTMUX_BASE)
  /** Peripheral MAIN__INPUTMUX base pointer */
  #define MAIN__INPUTMUX_NS                        ((INPUTMUX_Type *)MAIN__INPUTMUX_BASE_NS)
  /** Peripheral MEDIA__INPUTMUX base address */
  #define MEDIA__INPUTMUX_BASE                     (0x5C110000u)
  /** Peripheral MEDIA__INPUTMUX base address */
  #define MEDIA__INPUTMUX_BASE_NS                  (0x4C110000u)
  /** Peripheral MEDIA__INPUTMUX base pointer */
  #define MEDIA__INPUTMUX                          ((INPUTMUX_Type *)MEDIA__INPUTMUX_BASE)
  /** Peripheral MEDIA__INPUTMUX base pointer */
  #define MEDIA__INPUTMUX_NS                       ((INPUTMUX_Type *)MEDIA__INPUTMUX_BASE_NS)
  /** Peripheral SYSCON__INPUTMUX base address */
  #define SYSCON__INPUTMUX_BASE                    (0x505A0000u)
  /** Peripheral SYSCON__INPUTMUX base address */
  #define SYSCON__INPUTMUX_BASE_NS                 (0x405A0000u)
  /** Peripheral SYSCON__INPUTMUX base pointer */
  #define SYSCON__INPUTMUX                         ((INPUTMUX_Type *)SYSCON__INPUTMUX_BASE)
  /** Peripheral SYSCON__INPUTMUX base pointer */
  #define SYSCON__INPUTMUX_NS                      ((INPUTMUX_Type *)SYSCON__INPUTMUX_BASE_NS)
  /** Peripheral WAKE__INPUTMUX base address */
  #define WAKE__INPUTMUX_BASE                      (0x56090000u)
  /** Peripheral WAKE__INPUTMUX base address */
  #define WAKE__INPUTMUX_BASE_NS                   (0x46090000u)
  /** Peripheral WAKE__INPUTMUX base pointer */
  #define WAKE__INPUTMUX                           ((INPUTMUX_Type *)WAKE__INPUTMUX_BASE)
  /** Peripheral WAKE__INPUTMUX base pointer */
  #define WAKE__INPUTMUX_NS                        ((INPUTMUX_Type *)WAKE__INPUTMUX_BASE_NS)
  /** Array initializer of INPUTMUX peripheral base addresses */
  #define INPUTMUX_BASE_ADDRS                      { AUDIO__INPUTMUX_BASE, CMPT__INPUTMUX_BASE, COMM__INPUTMUX_BASE, MAIN__INPUTMUX_BASE, MEDIA__INPUTMUX_BASE, SYSCON__INPUTMUX_BASE, WAKE__INPUTMUX_BASE }
  /** Array initializer of INPUTMUX peripheral base pointers */
  #define INPUTMUX_BASE_PTRS                       { AUDIO__INPUTMUX, CMPT__INPUTMUX, COMM__INPUTMUX, MAIN__INPUTMUX, MEDIA__INPUTMUX, SYSCON__INPUTMUX, WAKE__INPUTMUX }
  /** Array initializer of INPUTMUX peripheral base addresses */
  #define INPUTMUX_BASE_ADDRS_NS                   { AUDIO__INPUTMUX_BASE_NS, CMPT__INPUTMUX_BASE_NS, COMM__INPUTMUX_BASE_NS, MAIN__INPUTMUX_BASE_NS, MEDIA__INPUTMUX_BASE_NS, SYSCON__INPUTMUX_BASE_NS, WAKE__INPUTMUX_BASE_NS }
  /** Array initializer of INPUTMUX peripheral base pointers */
  #define INPUTMUX_BASE_PTRS_NS                    { AUDIO__INPUTMUX_NS, CMPT__INPUTMUX_NS, COMM__INPUTMUX_NS, MAIN__INPUTMUX_NS, MEDIA__INPUTMUX_NS, SYSCON__INPUTMUX_NS, WAKE__INPUTMUX_NS }
#else
  /** Peripheral AUDIO__INPUTMUX base address */
  #define AUDIO__INPUTMUX_BASE                     (0x480A0000u)
  /** Peripheral AUDIO__INPUTMUX base pointer */
  #define AUDIO__INPUTMUX                          ((INPUTMUX_Type *)AUDIO__INPUTMUX_BASE)
  /** Peripheral CMPT__INPUTMUX base address */
  #define CMPT__INPUTMUX_BASE                      (0x441E0000u)
  /** Peripheral CMPT__INPUTMUX base pointer */
  #define CMPT__INPUTMUX                           ((INPUTMUX_Type *)CMPT__INPUTMUX_BASE)
  /** Peripheral COMM__INPUTMUX base address */
  #define COMM__INPUTMUX_BASE                      (0x4A130000u)
  /** Peripheral COMM__INPUTMUX base pointer */
  #define COMM__INPUTMUX                           ((INPUTMUX_Type *)COMM__INPUTMUX_BASE)
  /** Peripheral MAIN__INPUTMUX base address */
  #define MAIN__INPUTMUX_BASE                      (0x40420000u)
  /** Peripheral MAIN__INPUTMUX base pointer */
  #define MAIN__INPUTMUX                           ((INPUTMUX_Type *)MAIN__INPUTMUX_BASE)
  /** Peripheral MEDIA__INPUTMUX base address */
  #define MEDIA__INPUTMUX_BASE                     (0x4C110000u)
  /** Peripheral MEDIA__INPUTMUX base pointer */
  #define MEDIA__INPUTMUX                          ((INPUTMUX_Type *)MEDIA__INPUTMUX_BASE)
  /** Peripheral SYSCON__INPUTMUX base address */
  #define SYSCON__INPUTMUX_BASE                    (0x405A0000u)
  /** Peripheral SYSCON__INPUTMUX base pointer */
  #define SYSCON__INPUTMUX                         ((INPUTMUX_Type *)SYSCON__INPUTMUX_BASE)
  /** Peripheral WAKE__INPUTMUX base address */
  #define WAKE__INPUTMUX_BASE                      (0x46090000u)
  /** Peripheral WAKE__INPUTMUX base pointer */
  #define WAKE__INPUTMUX                           ((INPUTMUX_Type *)WAKE__INPUTMUX_BASE)
  /** Array initializer of INPUTMUX peripheral base addresses */
  #define INPUTMUX_BASE_ADDRS                      { AUDIO__INPUTMUX_BASE, CMPT__INPUTMUX_BASE, COMM__INPUTMUX_BASE, MAIN__INPUTMUX_BASE, MEDIA__INPUTMUX_BASE, SYSCON__INPUTMUX_BASE, WAKE__INPUTMUX_BASE }
  /** Array initializer of INPUTMUX peripheral base pointers */
  #define INPUTMUX_BASE_PTRS                       { AUDIO__INPUTMUX, CMPT__INPUTMUX, COMM__INPUTMUX, MAIN__INPUTMUX, MEDIA__INPUTMUX, SYSCON__INPUTMUX, WAKE__INPUTMUX }
#endif

/* IOMUXC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MAIN__IOMUXC base address */
  #define MAIN__IOMUXC_BASE                        (0x521C0000u)
  /** Peripheral MAIN__IOMUXC base address */
  #define MAIN__IOMUXC_BASE_NS                     (0x421C0000u)
  /** Peripheral MAIN__IOMUXC base pointer */
  #define MAIN__IOMUXC                             ((IOMUXC_Type *)MAIN__IOMUXC_BASE)
  /** Peripheral MAIN__IOMUXC base pointer */
  #define MAIN__IOMUXC_NS                          ((IOMUXC_Type *)MAIN__IOMUXC_BASE_NS)
  /** Peripheral VBAT__IOMUXC base address */
  #define VBAT__IOMUXC_BASE                        (0x56360000u)
  /** Peripheral VBAT__IOMUXC base address */
  #define VBAT__IOMUXC_BASE_NS                     (0x46360000u)
  /** Peripheral VBAT__IOMUXC base pointer */
  #define VBAT__IOMUXC                             ((IOMUXC_Type *)VBAT__IOMUXC_BASE)
  /** Peripheral VBAT__IOMUXC base pointer */
  #define VBAT__IOMUXC_NS                          ((IOMUXC_Type *)VBAT__IOMUXC_BASE_NS)
  /** Peripheral WAKE__IOMUXC base address */
  #define WAKE__IOMUXC_BASE                        (0x56220000u)
  /** Peripheral WAKE__IOMUXC base address */
  #define WAKE__IOMUXC_BASE_NS                     (0x46220000u)
  /** Peripheral WAKE__IOMUXC base pointer */
  #define WAKE__IOMUXC                             ((IOMUXC_Type *)WAKE__IOMUXC_BASE)
  /** Peripheral WAKE__IOMUXC base pointer */
  #define WAKE__IOMUXC_NS                          ((IOMUXC_Type *)WAKE__IOMUXC_BASE_NS)
  /** Array initializer of IOMUXC peripheral base addresses */
  #define IOMUXC_BASE_ADDRS                        { MAIN__IOMUXC_BASE, VBAT__IOMUXC_BASE, WAKE__IOMUXC_BASE }
  /** Array initializer of IOMUXC peripheral base pointers */
  #define IOMUXC_BASE_PTRS                         { MAIN__IOMUXC, VBAT__IOMUXC, WAKE__IOMUXC }
  /** Array initializer of IOMUXC peripheral base addresses */
  #define IOMUXC_BASE_ADDRS_NS                     { MAIN__IOMUXC_BASE_NS, VBAT__IOMUXC_BASE_NS, WAKE__IOMUXC_BASE_NS }
  /** Array initializer of IOMUXC peripheral base pointers */
  #define IOMUXC_BASE_PTRS_NS                      { MAIN__IOMUXC_NS, VBAT__IOMUXC_NS, WAKE__IOMUXC_NS }
#else
  /** Peripheral MAIN__IOMUXC base address */
  #define MAIN__IOMUXC_BASE                        (0x421C0000u)
  /** Peripheral MAIN__IOMUXC base pointer */
  #define MAIN__IOMUXC                             ((IOMUXC_Type *)MAIN__IOMUXC_BASE)
  /** Peripheral VBAT__IOMUXC base address */
  #define VBAT__IOMUXC_BASE                        (0x46360000u)
  /** Peripheral VBAT__IOMUXC base pointer */
  #define VBAT__IOMUXC                             ((IOMUXC_Type *)VBAT__IOMUXC_BASE)
  /** Peripheral WAKE__IOMUXC base address */
  #define WAKE__IOMUXC_BASE                        (0x46220000u)
  /** Peripheral WAKE__IOMUXC base pointer */
  #define WAKE__IOMUXC                             ((IOMUXC_Type *)WAKE__IOMUXC_BASE)
  /** Array initializer of IOMUXC peripheral base addresses */
  #define IOMUXC_BASE_ADDRS                        { MAIN__IOMUXC_BASE, VBAT__IOMUXC_BASE, WAKE__IOMUXC_BASE }
  /** Array initializer of IOMUXC peripheral base pointers */
  #define IOMUXC_BASE_PTRS                         { MAIN__IOMUXC, VBAT__IOMUXC, WAKE__IOMUXC }
#endif

/* ISI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MEDIA__ISI base address */
  #define MEDIA__ISI_BASE                          (0x5C120000u)
  /** Peripheral MEDIA__ISI base address */
  #define MEDIA__ISI_BASE_NS                       (0x4C120000u)
  /** Peripheral MEDIA__ISI base pointer */
  #define MEDIA__ISI                               ((ISI_Type *)MEDIA__ISI_BASE)
  /** Peripheral MEDIA__ISI base pointer */
  #define MEDIA__ISI_NS                            ((ISI_Type *)MEDIA__ISI_BASE_NS)
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS                           { MEDIA__ISI_BASE }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS                            { MEDIA__ISI }
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS_NS                        { MEDIA__ISI_BASE_NS }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS_NS                         { MEDIA__ISI_NS }
#else
  /** Peripheral MEDIA__ISI base address */
  #define MEDIA__ISI_BASE                          (0x4C120000u)
  /** Peripheral MEDIA__ISI base pointer */
  #define MEDIA__ISI                               ((ISI_Type *)MEDIA__ISI_BASE)
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS                           { MEDIA__ISI_BASE }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS                            { MEDIA__ISI }
#endif
/** Interrupt vectors for the ISI peripheral type */
#define ISI_IRQS                                 { MEDIA_ISI_IRQn }

/* JPEGDEC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MEDIA__JPEGDEC base address */
  #define MEDIA__JPEGDEC_BASE                      (0x5C0C0100u)
  /** Peripheral MEDIA__JPEGDEC base address */
  #define MEDIA__JPEGDEC_BASE_NS                   (0x4C0C0100u)
  /** Peripheral MEDIA__JPEGDEC base pointer */
  #define MEDIA__JPEGDEC                           ((JPEGDEC_Type *)MEDIA__JPEGDEC_BASE)
  /** Peripheral MEDIA__JPEGDEC base pointer */
  #define MEDIA__JPEGDEC_NS                        ((JPEGDEC_Type *)MEDIA__JPEGDEC_BASE_NS)
  /** Array initializer of JPEGDEC peripheral base addresses */
  #define JPEGDEC_BASE_ADDRS                       { MEDIA__JPEGDEC_BASE }
  /** Array initializer of JPEGDEC peripheral base pointers */
  #define JPEGDEC_BASE_PTRS                        { MEDIA__JPEGDEC }
  /** Array initializer of JPEGDEC peripheral base addresses */
  #define JPEGDEC_BASE_ADDRS_NS                    { MEDIA__JPEGDEC_BASE_NS }
  /** Array initializer of JPEGDEC peripheral base pointers */
  #define JPEGDEC_BASE_PTRS_NS                     { MEDIA__JPEGDEC_NS }
#else
  /** Peripheral MEDIA__JPEGDEC base address */
  #define MEDIA__JPEGDEC_BASE                      (0x4C0C0100u)
  /** Peripheral MEDIA__JPEGDEC base pointer */
  #define MEDIA__JPEGDEC                           ((JPEGDEC_Type *)MEDIA__JPEGDEC_BASE)
  /** Array initializer of JPEGDEC peripheral base addresses */
  #define JPEGDEC_BASE_ADDRS                       { MEDIA__JPEGDEC_BASE }
  /** Array initializer of JPEGDEC peripheral base pointers */
  #define JPEGDEC_BASE_PTRS                        { MEDIA__JPEGDEC }
#endif

/* JPGDECWRP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MEDIA__JPGDECWRP base address */
  #define MEDIA__JPGDECWRP_BASE                    (0x5C0C0000u)
  /** Peripheral MEDIA__JPGDECWRP base address */
  #define MEDIA__JPGDECWRP_BASE_NS                 (0x4C0C0000u)
  /** Peripheral MEDIA__JPGDECWRP base pointer */
  #define MEDIA__JPGDECWRP                         ((JPGDECWRP_Type *)MEDIA__JPGDECWRP_BASE)
  /** Peripheral MEDIA__JPGDECWRP base pointer */
  #define MEDIA__JPGDECWRP_NS                      ((JPGDECWRP_Type *)MEDIA__JPGDECWRP_BASE_NS)
  /** Array initializer of JPGDECWRP peripheral base addresses */
  #define JPGDECWRP_BASE_ADDRS                     { MEDIA__JPGDECWRP_BASE }
  /** Array initializer of JPGDECWRP peripheral base pointers */
  #define JPGDECWRP_BASE_PTRS                      { MEDIA__JPGDECWRP }
  /** Array initializer of JPGDECWRP peripheral base addresses */
  #define JPGDECWRP_BASE_ADDRS_NS                  { MEDIA__JPGDECWRP_BASE_NS }
  /** Array initializer of JPGDECWRP peripheral base pointers */
  #define JPGDECWRP_BASE_PTRS_NS                   { MEDIA__JPGDECWRP_NS }
#else
  /** Peripheral MEDIA__JPGDECWRP base address */
  #define MEDIA__JPGDECWRP_BASE                    (0x4C0C0000u)
  /** Peripheral MEDIA__JPGDECWRP base pointer */
  #define MEDIA__JPGDECWRP                         ((JPGDECWRP_Type *)MEDIA__JPGDECWRP_BASE)
  /** Array initializer of JPGDECWRP peripheral base addresses */
  #define JPGDECWRP_BASE_ADDRS                     { MEDIA__JPGDECWRP_BASE }
  /** Array initializer of JPGDECWRP peripheral base pointers */
  #define JPGDECWRP_BASE_PTRS                      { MEDIA__JPGDECWRP }
#endif

/* LLC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMPT__LLC base address */
  #define CMPT__LLC_BASE                           (0x541A0000u)
  /** Peripheral CMPT__LLC base address */
  #define CMPT__LLC_BASE_NS                        (0x441A0000u)
  /** Peripheral CMPT__LLC base pointer */
  #define CMPT__LLC                                ((LLC_Type *)CMPT__LLC_BASE)
  /** Peripheral CMPT__LLC base pointer */
  #define CMPT__LLC_NS                             ((LLC_Type *)CMPT__LLC_BASE_NS)
  /** Array initializer of LLC peripheral base addresses */
  #define LLC_BASE_ADDRS                           { CMPT__LLC_BASE }
  /** Array initializer of LLC peripheral base pointers */
  #define LLC_BASE_PTRS                            { CMPT__LLC }
  /** Array initializer of LLC peripheral base addresses */
  #define LLC_BASE_ADDRS_NS                        { CMPT__LLC_BASE_NS }
  /** Array initializer of LLC peripheral base pointers */
  #define LLC_BASE_PTRS_NS                         { CMPT__LLC_NS }
#else
  /** Peripheral CMPT__LLC base address */
  #define CMPT__LLC_BASE                           (0x441A0000u)
  /** Peripheral CMPT__LLC base pointer */
  #define CMPT__LLC                                ((LLC_Type *)CMPT__LLC_BASE)
  /** Array initializer of LLC peripheral base addresses */
  #define LLC_BASE_ADDRS                           { CMPT__LLC_BASE }
  /** Array initializer of LLC peripheral base pointers */
  #define LLC_BASE_PTRS                            { CMPT__LLC }
#endif
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** LLC physical memory base address */
  #define LLC_PHYMEM_BASES                { { 0x78000000u, 0x98000000u } }
  /** LLC physical memory size */
  #define LLC_PHYMEM_SIZES                { { 0x8000000u, 0x8000000u } }
  /** LLC physical memory base address */
  #define LLC_PHYMEM_BASES_NS             { { 0x68000000u, 0x88000000u } }
  /** LLC physical memory size */
  #define LLC_PHYMEM_SIZES_NS             { { 0x8000000u, 0x8000000u } }
#else
  /** LLC physical memory base address */
  #define LLC_PHYMEM_BASES                { { 0x68000000u, 0x88000000u } }
  /** LLC physical memory size */
  #define LLC_PHYMEM_SIZES                { { 0x8000000u, 0x8000000u } }
#endif
/** Number of physical memory base-address aliases per LLC instance.
    Each LLC instance is reachable through a direct (bypass) alias and a
    cached alias, so the LLC_PHYMEM_BASES/SIZES tables carry two columns per
    instance. */
#define LLC_PHYMEM_BASE_ALIAS_COUNT     (2)


/* LPDAC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__DAC base address */
  #define HSP__DAC_BASE                            (0x52060000u)
  /** Peripheral HSP__DAC base address */
  #define HSP__DAC_BASE_NS                         (0x42060000u)
  /** Peripheral HSP__DAC base pointer */
  #define HSP__DAC                                 ((LPDAC_Type *)HSP__DAC_BASE)
  /** Peripheral HSP__DAC base pointer */
  #define HSP__DAC_NS                              ((LPDAC_Type *)HSP__DAC_BASE_NS)
  /** Array initializer of LPDAC peripheral base addresses */
  #define LPDAC_BASE_ADDRS                         { HSP__DAC_BASE }
  /** Array initializer of LPDAC peripheral base pointers */
  #define LPDAC_BASE_PTRS                          { HSP__DAC }
  /** Array initializer of LPDAC peripheral base addresses */
  #define LPDAC_BASE_ADDRS_NS                      { HSP__DAC_BASE_NS }
  /** Array initializer of LPDAC peripheral base pointers */
  #define LPDAC_BASE_PTRS_NS                       { HSP__DAC_NS }
#else
  /** Peripheral HSP__DAC base address */
  #define HSP__DAC_BASE                            (0x42060000u)
  /** Peripheral HSP__DAC base pointer */
  #define HSP__DAC                                 ((LPDAC_Type *)HSP__DAC_BASE)
  /** Array initializer of LPDAC peripheral base addresses */
  #define LPDAC_BASE_ADDRS                         { HSP__DAC_BASE }
  /** Array initializer of LPDAC peripheral base pointers */
  #define LPDAC_BASE_PTRS                          { HSP__DAC }
#endif
/** Interrupt vectors for the LPDAC peripheral type */
#define LPDAC_IRQS                               { HSP_DAC_IRQn }

/* LPI2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__LPI2C_0 base address */
  #define HSP__LPI2C_0_BASE                        (0x52140000u)
  /** Peripheral HSP__LPI2C_0 base address */
  #define HSP__LPI2C_0_BASE_NS                     (0x42140000u)
  /** Peripheral HSP__LPI2C_0 base pointer */
  #define HSP__LPI2C_0                             ((LPI2C_Type *)HSP__LPI2C_0_BASE)
  /** Peripheral HSP__LPI2C_0 base pointer */
  #define HSP__LPI2C_0_NS                          ((LPI2C_Type *)HSP__LPI2C_0_BASE_NS)
  /** Peripheral HSP__LPI2C_1 base address */
  #define HSP__LPI2C_1_BASE                        (0x52910000u)
  /** Peripheral HSP__LPI2C_1 base address */
  #define HSP__LPI2C_1_BASE_NS                     (0x42910000u)
  /** Peripheral HSP__LPI2C_1 base pointer */
  #define HSP__LPI2C_1                             ((LPI2C_Type *)HSP__LPI2C_1_BASE)
  /** Peripheral HSP__LPI2C_1 base pointer */
  #define HSP__LPI2C_1_NS                          ((LPI2C_Type *)HSP__LPI2C_1_BASE_NS)
  /** Peripheral WAKE__LPI2C_0 base address */
  #define WAKE__LPI2C_0_BASE                       (0x561C0000u)
  /** Peripheral WAKE__LPI2C_0 base address */
  #define WAKE__LPI2C_0_BASE_NS                    (0x461C0000u)
  /** Peripheral WAKE__LPI2C_0 base pointer */
  #define WAKE__LPI2C_0                            ((LPI2C_Type *)WAKE__LPI2C_0_BASE)
  /** Peripheral WAKE__LPI2C_0 base pointer */
  #define WAKE__LPI2C_0_NS                         ((LPI2C_Type *)WAKE__LPI2C_0_BASE_NS)
  /** Peripheral WAKE__LPI2C_1 base address */
  #define WAKE__LPI2C_1_BASE                       (0x561D0000u)
  /** Peripheral WAKE__LPI2C_1 base address */
  #define WAKE__LPI2C_1_BASE_NS                    (0x461D0000u)
  /** Peripheral WAKE__LPI2C_1 base pointer */
  #define WAKE__LPI2C_1                            ((LPI2C_Type *)WAKE__LPI2C_1_BASE)
  /** Peripheral WAKE__LPI2C_1 base pointer */
  #define WAKE__LPI2C_1_NS                         ((LPI2C_Type *)WAKE__LPI2C_1_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { HSP__LPI2C_0_BASE, HSP__LPI2C_1_BASE, WAKE__LPI2C_0_BASE, WAKE__LPI2C_1_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { HSP__LPI2C_0, HSP__LPI2C_1, WAKE__LPI2C_0, WAKE__LPI2C_1 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { HSP__LPI2C_0_BASE_NS, HSP__LPI2C_1_BASE_NS, WAKE__LPI2C_0_BASE_NS, WAKE__LPI2C_1_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { HSP__LPI2C_0_NS, HSP__LPI2C_1_NS, WAKE__LPI2C_0_NS, WAKE__LPI2C_1_NS }
#else
  /** Peripheral HSP__LPI2C_0 base address */
  #define HSP__LPI2C_0_BASE                        (0x42140000u)
  /** Peripheral HSP__LPI2C_0 base pointer */
  #define HSP__LPI2C_0                             ((LPI2C_Type *)HSP__LPI2C_0_BASE)
  /** Peripheral HSP__LPI2C_1 base address */
  #define HSP__LPI2C_1_BASE                        (0x42910000u)
  /** Peripheral HSP__LPI2C_1 base pointer */
  #define HSP__LPI2C_1                             ((LPI2C_Type *)HSP__LPI2C_1_BASE)
  /** Peripheral WAKE__LPI2C_0 base address */
  #define WAKE__LPI2C_0_BASE                       (0x461C0000u)
  /** Peripheral WAKE__LPI2C_0 base pointer */
  #define WAKE__LPI2C_0                            ((LPI2C_Type *)WAKE__LPI2C_0_BASE)
  /** Peripheral WAKE__LPI2C_1 base address */
  #define WAKE__LPI2C_1_BASE                       (0x461D0000u)
  /** Peripheral WAKE__LPI2C_1 base pointer */
  #define WAKE__LPI2C_1                            ((LPI2C_Type *)WAKE__LPI2C_1_BASE)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { HSP__LPI2C_0_BASE, HSP__LPI2C_1_BASE, WAKE__LPI2C_0_BASE, WAKE__LPI2C_1_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { HSP__LPI2C_0, HSP__LPI2C_1, WAKE__LPI2C_0, WAKE__LPI2C_1 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { HSP_LPI2C0_IRQn, HSP_LPI2C1_IRQn, WAKE_LPI2C0_IRQn, WAKE_LPI2C1_IRQn }

/* LPIT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__LPIT_0 base address */
  #define HSP__LPIT_0_BASE                         (0x52070000u)
  /** Peripheral HSP__LPIT_0 base address */
  #define HSP__LPIT_0_BASE_NS                      (0x42070000u)
  /** Peripheral HSP__LPIT_0 base pointer */
  #define HSP__LPIT_0                              ((LPIT_Type *)HSP__LPIT_0_BASE)
  /** Peripheral HSP__LPIT_0 base pointer */
  #define HSP__LPIT_0_NS                           ((LPIT_Type *)HSP__LPIT_0_BASE_NS)
  /** Peripheral HSP__LPIT_1 base address */
  #define HSP__LPIT_1_BASE                         (0x52860000u)
  /** Peripheral HSP__LPIT_1 base address */
  #define HSP__LPIT_1_BASE_NS                      (0x42860000u)
  /** Peripheral HSP__LPIT_1 base pointer */
  #define HSP__LPIT_1                              ((LPIT_Type *)HSP__LPIT_1_BASE)
  /** Peripheral HSP__LPIT_1 base pointer */
  #define HSP__LPIT_1_NS                           ((LPIT_Type *)HSP__LPIT_1_BASE_NS)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { HSP__LPIT_0_BASE, HSP__LPIT_1_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { HSP__LPIT_0, HSP__LPIT_1 }
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS_NS                       { HSP__LPIT_0_BASE_NS, HSP__LPIT_1_BASE_NS }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS_NS                        { HSP__LPIT_0_NS, HSP__LPIT_1_NS }
#else
  /** Peripheral HSP__LPIT_0 base address */
  #define HSP__LPIT_0_BASE                         (0x42070000u)
  /** Peripheral HSP__LPIT_0 base pointer */
  #define HSP__LPIT_0                              ((LPIT_Type *)HSP__LPIT_0_BASE)
  /** Peripheral HSP__LPIT_1 base address */
  #define HSP__LPIT_1_BASE                         (0x42860000u)
  /** Peripheral HSP__LPIT_1 base pointer */
  #define HSP__LPIT_1                              ((LPIT_Type *)HSP__LPIT_1_BASE)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { HSP__LPIT_0_BASE, HSP__LPIT_1_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { HSP__LPIT_0, HSP__LPIT_1 }
#endif
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { { HSP_LPIT0_IRQn, HSP_LPIT0_IRQn, HSP_LPIT0_IRQn, HSP_LPIT0_IRQn }, { HSP_LPIT1_IRQn, HSP_LPIT1_IRQn, HSP_LPIT1_IRQn, HSP_LPIT1_IRQn } }

/* LPSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__LPSPI_0 base address */
  #define HSP__LPSPI_0_BASE                        (0x52160000u)
  /** Peripheral HSP__LPSPI_0 base address */
  #define HSP__LPSPI_0_BASE_NS                     (0x42160000u)
  /** Peripheral HSP__LPSPI_0 base pointer */
  #define HSP__LPSPI_0                             ((LPSPI_Type *)HSP__LPSPI_0_BASE)
  /** Peripheral HSP__LPSPI_0 base pointer */
  #define HSP__LPSPI_0_NS                          ((LPSPI_Type *)HSP__LPSPI_0_BASE_NS)
  /** Peripheral HSP__LPSPI_1 base address */
  #define HSP__LPSPI_1_BASE                        (0x52170000u)
  /** Peripheral HSP__LPSPI_1 base address */
  #define HSP__LPSPI_1_BASE_NS                     (0x42170000u)
  /** Peripheral HSP__LPSPI_1 base pointer */
  #define HSP__LPSPI_1                             ((LPSPI_Type *)HSP__LPSPI_1_BASE)
  /** Peripheral HSP__LPSPI_1 base pointer */
  #define HSP__LPSPI_1_NS                          ((LPSPI_Type *)HSP__LPSPI_1_BASE_NS)
  /** Peripheral HSP__LPSPI_2 base address */
  #define HSP__LPSPI_2_BASE                        (0x52180000u)
  /** Peripheral HSP__LPSPI_2 base address */
  #define HSP__LPSPI_2_BASE_NS                     (0x42180000u)
  /** Peripheral HSP__LPSPI_2 base pointer */
  #define HSP__LPSPI_2                             ((LPSPI_Type *)HSP__LPSPI_2_BASE)
  /** Peripheral HSP__LPSPI_2 base pointer */
  #define HSP__LPSPI_2_NS                          ((LPSPI_Type *)HSP__LPSPI_2_BASE_NS)
  /** Peripheral HSP__LPSPI_3 base address */
  #define HSP__LPSPI_3_BASE                        (0x52930000u)
  /** Peripheral HSP__LPSPI_3 base address */
  #define HSP__LPSPI_3_BASE_NS                     (0x42930000u)
  /** Peripheral HSP__LPSPI_3 base pointer */
  #define HSP__LPSPI_3                             ((LPSPI_Type *)HSP__LPSPI_3_BASE)
  /** Peripheral HSP__LPSPI_3 base pointer */
  #define HSP__LPSPI_3_NS                          ((LPSPI_Type *)HSP__LPSPI_3_BASE_NS)
  /** Peripheral HSP__LPSPI_4 base address */
  #define HSP__LPSPI_4_BASE                        (0x52940000u)
  /** Peripheral HSP__LPSPI_4 base address */
  #define HSP__LPSPI_4_BASE_NS                     (0x42940000u)
  /** Peripheral HSP__LPSPI_4 base pointer */
  #define HSP__LPSPI_4                             ((LPSPI_Type *)HSP__LPSPI_4_BASE)
  /** Peripheral HSP__LPSPI_4 base pointer */
  #define HSP__LPSPI_4_NS                          ((LPSPI_Type *)HSP__LPSPI_4_BASE_NS)
  /** Peripheral WAKE__LPSPI base address */
  #define WAKE__LPSPI_BASE                         (0x561E0000u)
  /** Peripheral WAKE__LPSPI base address */
  #define WAKE__LPSPI_BASE_NS                      (0x461E0000u)
  /** Peripheral WAKE__LPSPI base pointer */
  #define WAKE__LPSPI                              ((LPSPI_Type *)WAKE__LPSPI_BASE)
  /** Peripheral WAKE__LPSPI base pointer */
  #define WAKE__LPSPI_NS                           ((LPSPI_Type *)WAKE__LPSPI_BASE_NS)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { HSP__LPSPI_0_BASE, HSP__LPSPI_1_BASE, HSP__LPSPI_2_BASE, HSP__LPSPI_3_BASE, HSP__LPSPI_4_BASE, WAKE__LPSPI_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { HSP__LPSPI_0, HSP__LPSPI_1, HSP__LPSPI_2, HSP__LPSPI_3, HSP__LPSPI_4, WAKE__LPSPI }
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS_NS                      { HSP__LPSPI_0_BASE_NS, HSP__LPSPI_1_BASE_NS, HSP__LPSPI_2_BASE_NS, HSP__LPSPI_3_BASE_NS, HSP__LPSPI_4_BASE_NS, WAKE__LPSPI_BASE_NS }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS_NS                       { HSP__LPSPI_0_NS, HSP__LPSPI_1_NS, HSP__LPSPI_2_NS, HSP__LPSPI_3_NS, HSP__LPSPI_4_NS, WAKE__LPSPI_NS }
#else
  /** Peripheral HSP__LPSPI_0 base address */
  #define HSP__LPSPI_0_BASE                        (0x42160000u)
  /** Peripheral HSP__LPSPI_0 base pointer */
  #define HSP__LPSPI_0                             ((LPSPI_Type *)HSP__LPSPI_0_BASE)
  /** Peripheral HSP__LPSPI_1 base address */
  #define HSP__LPSPI_1_BASE                        (0x42170000u)
  /** Peripheral HSP__LPSPI_1 base pointer */
  #define HSP__LPSPI_1                             ((LPSPI_Type *)HSP__LPSPI_1_BASE)
  /** Peripheral HSP__LPSPI_2 base address */
  #define HSP__LPSPI_2_BASE                        (0x42180000u)
  /** Peripheral HSP__LPSPI_2 base pointer */
  #define HSP__LPSPI_2                             ((LPSPI_Type *)HSP__LPSPI_2_BASE)
  /** Peripheral HSP__LPSPI_3 base address */
  #define HSP__LPSPI_3_BASE                        (0x42930000u)
  /** Peripheral HSP__LPSPI_3 base pointer */
  #define HSP__LPSPI_3                             ((LPSPI_Type *)HSP__LPSPI_3_BASE)
  /** Peripheral HSP__LPSPI_4 base address */
  #define HSP__LPSPI_4_BASE                        (0x42940000u)
  /** Peripheral HSP__LPSPI_4 base pointer */
  #define HSP__LPSPI_4                             ((LPSPI_Type *)HSP__LPSPI_4_BASE)
  /** Peripheral WAKE__LPSPI base address */
  #define WAKE__LPSPI_BASE                         (0x461E0000u)
  /** Peripheral WAKE__LPSPI base pointer */
  #define WAKE__LPSPI                              ((LPSPI_Type *)WAKE__LPSPI_BASE)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { HSP__LPSPI_0_BASE, HSP__LPSPI_1_BASE, HSP__LPSPI_2_BASE, HSP__LPSPI_3_BASE, HSP__LPSPI_4_BASE, WAKE__LPSPI_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { HSP__LPSPI_0, HSP__LPSPI_1, HSP__LPSPI_2, HSP__LPSPI_3, HSP__LPSPI_4, WAKE__LPSPI }
#endif
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { HSP_LPSPI0_IRQn, HSP_LPSPI1_IRQn, HSP_LPSPI2_IRQn, HSP_LPSPI3_IRQn, HSP_LPSPI4_IRQn, WAKE_LPSPI_IRQn }

/* LPTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VBAT__LPTMR base address */
  #define VBAT__LPTMR_BASE                         (0x56330000u)
  /** Peripheral VBAT__LPTMR base address */
  #define VBAT__LPTMR_BASE_NS                      (0x46330000u)
  /** Peripheral VBAT__LPTMR base pointer */
  #define VBAT__LPTMR                              ((LPTMR_Type *)VBAT__LPTMR_BASE)
  /** Peripheral VBAT__LPTMR base pointer */
  #define VBAT__LPTMR_NS                           ((LPTMR_Type *)VBAT__LPTMR_BASE_NS)
  /** Peripheral WAKE__LPTMR_0 base address */
  #define WAKE__LPTMR_0_BASE                       (0x56130000u)
  /** Peripheral WAKE__LPTMR_0 base address */
  #define WAKE__LPTMR_0_BASE_NS                    (0x46130000u)
  /** Peripheral WAKE__LPTMR_0 base pointer */
  #define WAKE__LPTMR_0                            ((LPTMR_Type *)WAKE__LPTMR_0_BASE)
  /** Peripheral WAKE__LPTMR_0 base pointer */
  #define WAKE__LPTMR_0_NS                         ((LPTMR_Type *)WAKE__LPTMR_0_BASE_NS)
  /** Peripheral WAKE__LPTMR_1 base address */
  #define WAKE__LPTMR_1_BASE                       (0x56140000u)
  /** Peripheral WAKE__LPTMR_1 base address */
  #define WAKE__LPTMR_1_BASE_NS                    (0x46140000u)
  /** Peripheral WAKE__LPTMR_1 base pointer */
  #define WAKE__LPTMR_1                            ((LPTMR_Type *)WAKE__LPTMR_1_BASE)
  /** Peripheral WAKE__LPTMR_1 base pointer */
  #define WAKE__LPTMR_1_NS                         ((LPTMR_Type *)WAKE__LPTMR_1_BASE_NS)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { VBAT__LPTMR_BASE, WAKE__LPTMR_0_BASE, WAKE__LPTMR_1_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { VBAT__LPTMR, WAKE__LPTMR_0, WAKE__LPTMR_1 }
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS_NS                      { VBAT__LPTMR_BASE_NS, WAKE__LPTMR_0_BASE_NS, WAKE__LPTMR_1_BASE_NS }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS_NS                       { VBAT__LPTMR_NS, WAKE__LPTMR_0_NS, WAKE__LPTMR_1_NS }
#else
  /** Peripheral VBAT__LPTMR base address */
  #define VBAT__LPTMR_BASE                         (0x46330000u)
  /** Peripheral VBAT__LPTMR base pointer */
  #define VBAT__LPTMR                              ((LPTMR_Type *)VBAT__LPTMR_BASE)
  /** Peripheral WAKE__LPTMR_0 base address */
  #define WAKE__LPTMR_0_BASE                       (0x46130000u)
  /** Peripheral WAKE__LPTMR_0 base pointer */
  #define WAKE__LPTMR_0                            ((LPTMR_Type *)WAKE__LPTMR_0_BASE)
  /** Peripheral WAKE__LPTMR_1 base address */
  #define WAKE__LPTMR_1_BASE                       (0x46140000u)
  /** Peripheral WAKE__LPTMR_1 base pointer */
  #define WAKE__LPTMR_1                            ((LPTMR_Type *)WAKE__LPTMR_1_BASE)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { VBAT__LPTMR_BASE, WAKE__LPTMR_0_BASE, WAKE__LPTMR_1_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { VBAT__LPTMR, WAKE__LPTMR_0, WAKE__LPTMR_1 }
#endif
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { VBAT_LPTMR_IRQn, WAKE_LPTMR0_IRQn, WAKE_LPTMR1_IRQn }

/* LPUART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__LPUART_0 base address */
  #define HSP__LPUART_0_BASE                       (0x52190000u)
  /** Peripheral HSP__LPUART_0 base address */
  #define HSP__LPUART_0_BASE_NS                    (0x42190000u)
  /** Peripheral HSP__LPUART_0 base pointer */
  #define HSP__LPUART_0                            ((LPUART_Type *)HSP__LPUART_0_BASE)
  /** Peripheral HSP__LPUART_0 base pointer */
  #define HSP__LPUART_0_NS                         ((LPUART_Type *)HSP__LPUART_0_BASE_NS)
  /** Peripheral HSP__LPUART_1 base address */
  #define HSP__LPUART_1_BASE                       (0x521A0000u)
  /** Peripheral HSP__LPUART_1 base address */
  #define HSP__LPUART_1_BASE_NS                    (0x421A0000u)
  /** Peripheral HSP__LPUART_1 base pointer */
  #define HSP__LPUART_1                            ((LPUART_Type *)HSP__LPUART_1_BASE)
  /** Peripheral HSP__LPUART_1 base pointer */
  #define HSP__LPUART_1_NS                         ((LPUART_Type *)HSP__LPUART_1_BASE_NS)
  /** Peripheral HSP__LPUART_2 base address */
  #define HSP__LPUART_2_BASE                       (0x521B0000u)
  /** Peripheral HSP__LPUART_2 base address */
  #define HSP__LPUART_2_BASE_NS                    (0x421B0000u)
  /** Peripheral HSP__LPUART_2 base pointer */
  #define HSP__LPUART_2                            ((LPUART_Type *)HSP__LPUART_2_BASE)
  /** Peripheral HSP__LPUART_2 base pointer */
  #define HSP__LPUART_2_NS                         ((LPUART_Type *)HSP__LPUART_2_BASE_NS)
  /** Peripheral HSP__LPUART_3 base address */
  #define HSP__LPUART_3_BASE                       (0x52950000u)
  /** Peripheral HSP__LPUART_3 base address */
  #define HSP__LPUART_3_BASE_NS                    (0x42950000u)
  /** Peripheral HSP__LPUART_3 base pointer */
  #define HSP__LPUART_3                            ((LPUART_Type *)HSP__LPUART_3_BASE)
  /** Peripheral HSP__LPUART_3 base pointer */
  #define HSP__LPUART_3_NS                         ((LPUART_Type *)HSP__LPUART_3_BASE_NS)
  /** Peripheral HSP__LPUART_4 base address */
  #define HSP__LPUART_4_BASE                       (0x52960000u)
  /** Peripheral HSP__LPUART_4 base address */
  #define HSP__LPUART_4_BASE_NS                    (0x42960000u)
  /** Peripheral HSP__LPUART_4 base pointer */
  #define HSP__LPUART_4                            ((LPUART_Type *)HSP__LPUART_4_BASE)
  /** Peripheral HSP__LPUART_4 base pointer */
  #define HSP__LPUART_4_NS                         ((LPUART_Type *)HSP__LPUART_4_BASE_NS)
  /** Peripheral HSP__LPUART_5 base address */
  #define HSP__LPUART_5_BASE                       (0x52970000u)
  /** Peripheral HSP__LPUART_5 base address */
  #define HSP__LPUART_5_BASE_NS                    (0x42970000u)
  /** Peripheral HSP__LPUART_5 base pointer */
  #define HSP__LPUART_5                            ((LPUART_Type *)HSP__LPUART_5_BASE)
  /** Peripheral HSP__LPUART_5 base pointer */
  #define HSP__LPUART_5_NS                         ((LPUART_Type *)HSP__LPUART_5_BASE_NS)
  /** Peripheral WAKE__LPUART_0 base address */
  #define WAKE__LPUART_0_BASE                      (0x561F0000u)
  /** Peripheral WAKE__LPUART_0 base address */
  #define WAKE__LPUART_0_BASE_NS                   (0x461F0000u)
  /** Peripheral WAKE__LPUART_0 base pointer */
  #define WAKE__LPUART_0                           ((LPUART_Type *)WAKE__LPUART_0_BASE)
  /** Peripheral WAKE__LPUART_0 base pointer */
  #define WAKE__LPUART_0_NS                        ((LPUART_Type *)WAKE__LPUART_0_BASE_NS)
  /** Peripheral WAKE__LPUART_1 base address */
  #define WAKE__LPUART_1_BASE                      (0x56200000u)
  /** Peripheral WAKE__LPUART_1 base address */
  #define WAKE__LPUART_1_BASE_NS                   (0x46200000u)
  /** Peripheral WAKE__LPUART_1 base pointer */
  #define WAKE__LPUART_1                           ((LPUART_Type *)WAKE__LPUART_1_BASE)
  /** Peripheral WAKE__LPUART_1 base pointer */
  #define WAKE__LPUART_1_NS                        ((LPUART_Type *)WAKE__LPUART_1_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { HSP__LPUART_0_BASE, HSP__LPUART_1_BASE, HSP__LPUART_2_BASE, HSP__LPUART_3_BASE, HSP__LPUART_4_BASE, HSP__LPUART_5_BASE, WAKE__LPUART_0_BASE, WAKE__LPUART_1_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { HSP__LPUART_0, HSP__LPUART_1, HSP__LPUART_2, HSP__LPUART_3, HSP__LPUART_4, HSP__LPUART_5, WAKE__LPUART_0, WAKE__LPUART_1 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { HSP__LPUART_0_BASE_NS, HSP__LPUART_1_BASE_NS, HSP__LPUART_2_BASE_NS, HSP__LPUART_3_BASE_NS, HSP__LPUART_4_BASE_NS, HSP__LPUART_5_BASE_NS, WAKE__LPUART_0_BASE_NS, WAKE__LPUART_1_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { HSP__LPUART_0_NS, HSP__LPUART_1_NS, HSP__LPUART_2_NS, HSP__LPUART_3_NS, HSP__LPUART_4_NS, HSP__LPUART_5_NS, WAKE__LPUART_0_NS, WAKE__LPUART_1_NS }
#else
  /** Peripheral HSP__LPUART_0 base address */
  #define HSP__LPUART_0_BASE                       (0x42190000u)
  /** Peripheral HSP__LPUART_0 base pointer */
  #define HSP__LPUART_0                            ((LPUART_Type *)HSP__LPUART_0_BASE)
  /** Peripheral HSP__LPUART_1 base address */
  #define HSP__LPUART_1_BASE                       (0x421A0000u)
  /** Peripheral HSP__LPUART_1 base pointer */
  #define HSP__LPUART_1                            ((LPUART_Type *)HSP__LPUART_1_BASE)
  /** Peripheral HSP__LPUART_2 base address */
  #define HSP__LPUART_2_BASE                       (0x421B0000u)
  /** Peripheral HSP__LPUART_2 base pointer */
  #define HSP__LPUART_2                            ((LPUART_Type *)HSP__LPUART_2_BASE)
  /** Peripheral HSP__LPUART_3 base address */
  #define HSP__LPUART_3_BASE                       (0x42950000u)
  /** Peripheral HSP__LPUART_3 base pointer */
  #define HSP__LPUART_3                            ((LPUART_Type *)HSP__LPUART_3_BASE)
  /** Peripheral HSP__LPUART_4 base address */
  #define HSP__LPUART_4_BASE                       (0x42960000u)
  /** Peripheral HSP__LPUART_4 base pointer */
  #define HSP__LPUART_4                            ((LPUART_Type *)HSP__LPUART_4_BASE)
  /** Peripheral HSP__LPUART_5 base address */
  #define HSP__LPUART_5_BASE                       (0x42970000u)
  /** Peripheral HSP__LPUART_5 base pointer */
  #define HSP__LPUART_5                            ((LPUART_Type *)HSP__LPUART_5_BASE)
  /** Peripheral WAKE__LPUART_0 base address */
  #define WAKE__LPUART_0_BASE                      (0x461F0000u)
  /** Peripheral WAKE__LPUART_0 base pointer */
  #define WAKE__LPUART_0                           ((LPUART_Type *)WAKE__LPUART_0_BASE)
  /** Peripheral WAKE__LPUART_1 base address */
  #define WAKE__LPUART_1_BASE                      (0x46200000u)
  /** Peripheral WAKE__LPUART_1 base pointer */
  #define WAKE__LPUART_1                           ((LPUART_Type *)WAKE__LPUART_1_BASE)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { HSP__LPUART_0_BASE, HSP__LPUART_1_BASE, HSP__LPUART_2_BASE, HSP__LPUART_3_BASE, HSP__LPUART_4_BASE, HSP__LPUART_5_BASE, WAKE__LPUART_0_BASE, WAKE__LPUART_1_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { HSP__LPUART_0, HSP__LPUART_1, HSP__LPUART_2, HSP__LPUART_3, HSP__LPUART_4, HSP__LPUART_5, WAKE__LPUART_0, WAKE__LPUART_1 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { HSP_LPUART0_IRQn, HSP_LPUART1_IRQn, HSP_LPUART2_IRQn, HSP_LPUART3_IRQn, HSP_LPUART4_IRQn, HSP_LPUART5_IRQn, WAKE_LPUART0_IRQn, WAKE_LPUART1_IRQn }

/* MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMPT__CM85_MCM base address */
  #define CMPT__CM85_MCM_BASE                      (0xF0050000u)
  /** Peripheral CMPT__CM85_MCM base address */
  #define CMPT__CM85_MCM_BASE_NS                   (0xE0050000u)
  /** Peripheral CMPT__CM85_MCM base pointer */
  #define CMPT__CM85_MCM                           ((MCM_Type *)CMPT__CM85_MCM_BASE)
  /** Peripheral CMPT__CM85_MCM base pointer */
  #define CMPT__CM85_MCM_NS                        ((MCM_Type *)CMPT__CM85_MCM_BASE_NS)
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS                           { CMPT__CM85_MCM_BASE }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS                            { CMPT__CM85_MCM }
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS_NS                        { CMPT__CM85_MCM_BASE_NS }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS_NS                         { CMPT__CM85_MCM_NS }
#else
  /** Peripheral CMPT__CM85_MCM base address */
  #define CMPT__CM85_MCM_BASE                      (0xE0050000u)
  /** Peripheral CMPT__CM85_MCM base pointer */
  #define CMPT__CM85_MCM                           ((MCM_Type *)CMPT__CM85_MCM_BASE)
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS                           { CMPT__CM85_MCM_BASE }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS                            { CMPT__CM85_MCM }
#endif

/* MEMCON_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON__MEMCON_GLOBAL base address */
  #define SYSCON__MEMCON_GLOBAL_BASE               (0x50560000u)
  /** Peripheral SYSCON__MEMCON_GLOBAL base address */
  #define SYSCON__MEMCON_GLOBAL_BASE_NS            (0x40560000u)
  /** Peripheral SYSCON__MEMCON_GLOBAL base pointer */
  #define SYSCON__MEMCON_GLOBAL                    ((MEMCON_GLOBAL_Type *)SYSCON__MEMCON_GLOBAL_BASE)
  /** Peripheral SYSCON__MEMCON_GLOBAL base pointer */
  #define SYSCON__MEMCON_GLOBAL_NS                 ((MEMCON_GLOBAL_Type *)SYSCON__MEMCON_GLOBAL_BASE_NS)
  /** Array initializer of MEMCON_GLOBAL peripheral base addresses */
  #define MEMCON_GLOBAL_BASE_ADDRS                 { SYSCON__MEMCON_GLOBAL_BASE }
  /** Array initializer of MEMCON_GLOBAL peripheral base pointers */
  #define MEMCON_GLOBAL_BASE_PTRS                  { SYSCON__MEMCON_GLOBAL }
  /** Array initializer of MEMCON_GLOBAL peripheral base addresses */
  #define MEMCON_GLOBAL_BASE_ADDRS_NS              { SYSCON__MEMCON_GLOBAL_BASE_NS }
  /** Array initializer of MEMCON_GLOBAL peripheral base pointers */
  #define MEMCON_GLOBAL_BASE_PTRS_NS               { SYSCON__MEMCON_GLOBAL_NS }
#else
  /** Peripheral SYSCON__MEMCON_GLOBAL base address */
  #define SYSCON__MEMCON_GLOBAL_BASE               (0x40560000u)
  /** Peripheral SYSCON__MEMCON_GLOBAL base pointer */
  #define SYSCON__MEMCON_GLOBAL                    ((MEMCON_GLOBAL_Type *)SYSCON__MEMCON_GLOBAL_BASE)
  /** Array initializer of MEMCON_GLOBAL peripheral base addresses */
  #define MEMCON_GLOBAL_BASE_ADDRS                 { SYSCON__MEMCON_GLOBAL_BASE }
  /** Array initializer of MEMCON_GLOBAL peripheral base pointers */
  #define MEMCON_GLOBAL_BASE_PTRS                  { SYSCON__MEMCON_GLOBAL }
#endif

/* MEMCON_SLICE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON__MEMCON_S0 base address */
  #define SYSCON__MEMCON_S0_BASE                   (0x50561000u)
  /** Peripheral SYSCON__MEMCON_S0 base address */
  #define SYSCON__MEMCON_S0_BASE_NS                (0x40561000u)
  /** Peripheral SYSCON__MEMCON_S0 base pointer */
  #define SYSCON__MEMCON_S0                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S0_BASE)
  /** Peripheral SYSCON__MEMCON_S0 base pointer */
  #define SYSCON__MEMCON_S0_NS                     ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S0_BASE_NS)
  /** Peripheral SYSCON__MEMCON_S1 base address */
  #define SYSCON__MEMCON_S1_BASE                   (0x50562000u)
  /** Peripheral SYSCON__MEMCON_S1 base address */
  #define SYSCON__MEMCON_S1_BASE_NS                (0x40562000u)
  /** Peripheral SYSCON__MEMCON_S1 base pointer */
  #define SYSCON__MEMCON_S1                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S1_BASE)
  /** Peripheral SYSCON__MEMCON_S1 base pointer */
  #define SYSCON__MEMCON_S1_NS                     ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S1_BASE_NS)
  /** Peripheral SYSCON__MEMCON_S2 base address */
  #define SYSCON__MEMCON_S2_BASE                   (0x50563000u)
  /** Peripheral SYSCON__MEMCON_S2 base address */
  #define SYSCON__MEMCON_S2_BASE_NS                (0x40563000u)
  /** Peripheral SYSCON__MEMCON_S2 base pointer */
  #define SYSCON__MEMCON_S2                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S2_BASE)
  /** Peripheral SYSCON__MEMCON_S2 base pointer */
  #define SYSCON__MEMCON_S2_NS                     ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S2_BASE_NS)
  /** Peripheral SYSCON__MEMCON_S3 base address */
  #define SYSCON__MEMCON_S3_BASE                   (0x50564000u)
  /** Peripheral SYSCON__MEMCON_S3 base address */
  #define SYSCON__MEMCON_S3_BASE_NS                (0x40564000u)
  /** Peripheral SYSCON__MEMCON_S3 base pointer */
  #define SYSCON__MEMCON_S3                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S3_BASE)
  /** Peripheral SYSCON__MEMCON_S3 base pointer */
  #define SYSCON__MEMCON_S3_NS                     ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S3_BASE_NS)
  /** Peripheral SYSCON__MEMCON_S4 base address */
  #define SYSCON__MEMCON_S4_BASE                   (0x50565000u)
  /** Peripheral SYSCON__MEMCON_S4 base address */
  #define SYSCON__MEMCON_S4_BASE_NS                (0x40565000u)
  /** Peripheral SYSCON__MEMCON_S4 base pointer */
  #define SYSCON__MEMCON_S4                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S4_BASE)
  /** Peripheral SYSCON__MEMCON_S4 base pointer */
  #define SYSCON__MEMCON_S4_NS                     ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S4_BASE_NS)
  /** Peripheral SYSCON__MEMCON_S5 base address */
  #define SYSCON__MEMCON_S5_BASE                   (0x50566000u)
  /** Peripheral SYSCON__MEMCON_S5 base address */
  #define SYSCON__MEMCON_S5_BASE_NS                (0x40566000u)
  /** Peripheral SYSCON__MEMCON_S5 base pointer */
  #define SYSCON__MEMCON_S5                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S5_BASE)
  /** Peripheral SYSCON__MEMCON_S5 base pointer */
  #define SYSCON__MEMCON_S5_NS                     ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S5_BASE_NS)
  /** Peripheral SYSCON__MEMCON_S6 base address */
  #define SYSCON__MEMCON_S6_BASE                   (0x50567000u)
  /** Peripheral SYSCON__MEMCON_S6 base address */
  #define SYSCON__MEMCON_S6_BASE_NS                (0x40567000u)
  /** Peripheral SYSCON__MEMCON_S6 base pointer */
  #define SYSCON__MEMCON_S6                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S6_BASE)
  /** Peripheral SYSCON__MEMCON_S6 base pointer */
  #define SYSCON__MEMCON_S6_NS                     ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S6_BASE_NS)
  /** Peripheral SYSCON__MEMCON_S7 base address */
  #define SYSCON__MEMCON_S7_BASE                   (0x50568000u)
  /** Peripheral SYSCON__MEMCON_S7 base address */
  #define SYSCON__MEMCON_S7_BASE_NS                (0x40568000u)
  /** Peripheral SYSCON__MEMCON_S7 base pointer */
  #define SYSCON__MEMCON_S7                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S7_BASE)
  /** Peripheral SYSCON__MEMCON_S7 base pointer */
  #define SYSCON__MEMCON_S7_NS                     ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S7_BASE_NS)
  /** Peripheral SYSCON__MEMCON_S8 base address */
  #define SYSCON__MEMCON_S8_BASE                   (0x50569000u)
  /** Peripheral SYSCON__MEMCON_S8 base address */
  #define SYSCON__MEMCON_S8_BASE_NS                (0x40569000u)
  /** Peripheral SYSCON__MEMCON_S8 base pointer */
  #define SYSCON__MEMCON_S8                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S8_BASE)
  /** Peripheral SYSCON__MEMCON_S8 base pointer */
  #define SYSCON__MEMCON_S8_NS                     ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S8_BASE_NS)
  /** Peripheral SYSCON__MEMCON_S9 base address */
  #define SYSCON__MEMCON_S9_BASE                   (0x5056A000u)
  /** Peripheral SYSCON__MEMCON_S9 base address */
  #define SYSCON__MEMCON_S9_BASE_NS                (0x4056A000u)
  /** Peripheral SYSCON__MEMCON_S9 base pointer */
  #define SYSCON__MEMCON_S9                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S9_BASE)
  /** Peripheral SYSCON__MEMCON_S9 base pointer */
  #define SYSCON__MEMCON_S9_NS                     ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S9_BASE_NS)
  /** Peripheral SYSCON__MEMCON_S10 base address */
  #define SYSCON__MEMCON_S10_BASE                  (0x5056B000u)
  /** Peripheral SYSCON__MEMCON_S10 base address */
  #define SYSCON__MEMCON_S10_BASE_NS               (0x4056B000u)
  /** Peripheral SYSCON__MEMCON_S10 base pointer */
  #define SYSCON__MEMCON_S10                       ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S10_BASE)
  /** Peripheral SYSCON__MEMCON_S10 base pointer */
  #define SYSCON__MEMCON_S10_NS                    ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S10_BASE_NS)
  /** Peripheral SYSCON__MEMCON_S11 base address */
  #define SYSCON__MEMCON_S11_BASE                  (0x5056C000u)
  /** Peripheral SYSCON__MEMCON_S11 base address */
  #define SYSCON__MEMCON_S11_BASE_NS               (0x4056C000u)
  /** Peripheral SYSCON__MEMCON_S11 base pointer */
  #define SYSCON__MEMCON_S11                       ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S11_BASE)
  /** Peripheral SYSCON__MEMCON_S11 base pointer */
  #define SYSCON__MEMCON_S11_NS                    ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S11_BASE_NS)
  /** Array initializer of MEMCON_SLICE peripheral base addresses */
  #define MEMCON_SLICE_BASE_ADDRS                  { SYSCON__MEMCON_S0_BASE, SYSCON__MEMCON_S1_BASE, SYSCON__MEMCON_S2_BASE, SYSCON__MEMCON_S3_BASE, SYSCON__MEMCON_S4_BASE, SYSCON__MEMCON_S5_BASE, SYSCON__MEMCON_S6_BASE, SYSCON__MEMCON_S7_BASE, SYSCON__MEMCON_S8_BASE, SYSCON__MEMCON_S9_BASE, SYSCON__MEMCON_S10_BASE, SYSCON__MEMCON_S11_BASE }
  /** Array initializer of MEMCON_SLICE peripheral base pointers */
  #define MEMCON_SLICE_BASE_PTRS                   { SYSCON__MEMCON_S0, SYSCON__MEMCON_S1, SYSCON__MEMCON_S2, SYSCON__MEMCON_S3, SYSCON__MEMCON_S4, SYSCON__MEMCON_S5, SYSCON__MEMCON_S6, SYSCON__MEMCON_S7, SYSCON__MEMCON_S8, SYSCON__MEMCON_S9, SYSCON__MEMCON_S10, SYSCON__MEMCON_S11 }
  /** Array initializer of MEMCON_SLICE peripheral base addresses */
  #define MEMCON_SLICE_BASE_ADDRS_NS               { SYSCON__MEMCON_S0_BASE_NS, SYSCON__MEMCON_S1_BASE_NS, SYSCON__MEMCON_S2_BASE_NS, SYSCON__MEMCON_S3_BASE_NS, SYSCON__MEMCON_S4_BASE_NS, SYSCON__MEMCON_S5_BASE_NS, SYSCON__MEMCON_S6_BASE_NS, SYSCON__MEMCON_S7_BASE_NS, SYSCON__MEMCON_S8_BASE_NS, SYSCON__MEMCON_S9_BASE_NS, SYSCON__MEMCON_S10_BASE_NS, SYSCON__MEMCON_S11_BASE_NS }
  /** Array initializer of MEMCON_SLICE peripheral base pointers */
  #define MEMCON_SLICE_BASE_PTRS_NS                { SYSCON__MEMCON_S0_NS, SYSCON__MEMCON_S1_NS, SYSCON__MEMCON_S2_NS, SYSCON__MEMCON_S3_NS, SYSCON__MEMCON_S4_NS, SYSCON__MEMCON_S5_NS, SYSCON__MEMCON_S6_NS, SYSCON__MEMCON_S7_NS, SYSCON__MEMCON_S8_NS, SYSCON__MEMCON_S9_NS, SYSCON__MEMCON_S10_NS, SYSCON__MEMCON_S11_NS }
#else
  /** Peripheral SYSCON__MEMCON_S0 base address */
  #define SYSCON__MEMCON_S0_BASE                   (0x40561000u)
  /** Peripheral SYSCON__MEMCON_S0 base pointer */
  #define SYSCON__MEMCON_S0                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S0_BASE)
  /** Peripheral SYSCON__MEMCON_S1 base address */
  #define SYSCON__MEMCON_S1_BASE                   (0x40562000u)
  /** Peripheral SYSCON__MEMCON_S1 base pointer */
  #define SYSCON__MEMCON_S1                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S1_BASE)
  /** Peripheral SYSCON__MEMCON_S2 base address */
  #define SYSCON__MEMCON_S2_BASE                   (0x40563000u)
  /** Peripheral SYSCON__MEMCON_S2 base pointer */
  #define SYSCON__MEMCON_S2                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S2_BASE)
  /** Peripheral SYSCON__MEMCON_S3 base address */
  #define SYSCON__MEMCON_S3_BASE                   (0x40564000u)
  /** Peripheral SYSCON__MEMCON_S3 base pointer */
  #define SYSCON__MEMCON_S3                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S3_BASE)
  /** Peripheral SYSCON__MEMCON_S4 base address */
  #define SYSCON__MEMCON_S4_BASE                   (0x40565000u)
  /** Peripheral SYSCON__MEMCON_S4 base pointer */
  #define SYSCON__MEMCON_S4                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S4_BASE)
  /** Peripheral SYSCON__MEMCON_S5 base address */
  #define SYSCON__MEMCON_S5_BASE                   (0x40566000u)
  /** Peripheral SYSCON__MEMCON_S5 base pointer */
  #define SYSCON__MEMCON_S5                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S5_BASE)
  /** Peripheral SYSCON__MEMCON_S6 base address */
  #define SYSCON__MEMCON_S6_BASE                   (0x40567000u)
  /** Peripheral SYSCON__MEMCON_S6 base pointer */
  #define SYSCON__MEMCON_S6                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S6_BASE)
  /** Peripheral SYSCON__MEMCON_S7 base address */
  #define SYSCON__MEMCON_S7_BASE                   (0x40568000u)
  /** Peripheral SYSCON__MEMCON_S7 base pointer */
  #define SYSCON__MEMCON_S7                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S7_BASE)
  /** Peripheral SYSCON__MEMCON_S8 base address */
  #define SYSCON__MEMCON_S8_BASE                   (0x40569000u)
  /** Peripheral SYSCON__MEMCON_S8 base pointer */
  #define SYSCON__MEMCON_S8                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S8_BASE)
  /** Peripheral SYSCON__MEMCON_S9 base address */
  #define SYSCON__MEMCON_S9_BASE                   (0x4056A000u)
  /** Peripheral SYSCON__MEMCON_S9 base pointer */
  #define SYSCON__MEMCON_S9                        ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S9_BASE)
  /** Peripheral SYSCON__MEMCON_S10 base address */
  #define SYSCON__MEMCON_S10_BASE                  (0x4056B000u)
  /** Peripheral SYSCON__MEMCON_S10 base pointer */
  #define SYSCON__MEMCON_S10                       ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S10_BASE)
  /** Peripheral SYSCON__MEMCON_S11 base address */
  #define SYSCON__MEMCON_S11_BASE                  (0x4056C000u)
  /** Peripheral SYSCON__MEMCON_S11 base pointer */
  #define SYSCON__MEMCON_S11                       ((MEMCON_SLICE_Type *)SYSCON__MEMCON_S11_BASE)
  /** Array initializer of MEMCON_SLICE peripheral base addresses */
  #define MEMCON_SLICE_BASE_ADDRS                  { SYSCON__MEMCON_S0_BASE, SYSCON__MEMCON_S1_BASE, SYSCON__MEMCON_S2_BASE, SYSCON__MEMCON_S3_BASE, SYSCON__MEMCON_S4_BASE, SYSCON__MEMCON_S5_BASE, SYSCON__MEMCON_S6_BASE, SYSCON__MEMCON_S7_BASE, SYSCON__MEMCON_S8_BASE, SYSCON__MEMCON_S9_BASE, SYSCON__MEMCON_S10_BASE, SYSCON__MEMCON_S11_BASE }
  /** Array initializer of MEMCON_SLICE peripheral base pointers */
  #define MEMCON_SLICE_BASE_PTRS                   { SYSCON__MEMCON_S0, SYSCON__MEMCON_S1, SYSCON__MEMCON_S2, SYSCON__MEMCON_S3, SYSCON__MEMCON_S4, SYSCON__MEMCON_S5, SYSCON__MEMCON_S6, SYSCON__MEMCON_S7, SYSCON__MEMCON_S8, SYSCON__MEMCON_S9, SYSCON__MEMCON_S10, SYSCON__MEMCON_S11 }
#endif

/* MMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MAIN__MMU base address */
  #define MAIN__MMU_BASE                           (0x50490000u)
  /** Peripheral MAIN__MMU base address */
  #define MAIN__MMU_BASE_NS                        (0x40490000u)
  /** Peripheral MAIN__MMU base pointer */
  #define MAIN__MMU                                ((MMU_Type *)MAIN__MMU_BASE)
  /** Peripheral MAIN__MMU base pointer */
  #define MAIN__MMU_NS                             ((MMU_Type *)MAIN__MMU_BASE_NS)
  /** Array initializer of MMU peripheral base addresses */
  #define MMU_BASE_ADDRS                           { MAIN__MMU_BASE }
  /** Array initializer of MMU peripheral base pointers */
  #define MMU_BASE_PTRS                            { MAIN__MMU }
  /** Array initializer of MMU peripheral base addresses */
  #define MMU_BASE_ADDRS_NS                        { MAIN__MMU_BASE_NS }
  /** Array initializer of MMU peripheral base pointers */
  #define MMU_BASE_PTRS_NS                         { MAIN__MMU_NS }
#else
  /** Peripheral MAIN__MMU base address */
  #define MAIN__MMU_BASE                           (0x40490000u)
  /** Peripheral MAIN__MMU base pointer */
  #define MAIN__MMU                                ((MMU_Type *)MAIN__MMU_BASE)
  /** Array initializer of MMU peripheral base addresses */
  #define MMU_BASE_ADDRS                           { MAIN__MMU_BASE }
  /** Array initializer of MMU peripheral base pointers */
  #define MMU_BASE_PTRS                            { MAIN__MMU }
#endif
/** Interrupt vectors for the MMU peripheral type */
#define MMU_IRQS                                 { MAIN_MMU_IRQn }

/* MODCON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO__MODCON base address */
  #define AUDIO__MODCON_BASE                       (0x58000000u)
  /** Peripheral AUDIO__MODCON base address */
  #define AUDIO__MODCON_BASE_NS                    (0x48000000u)
  /** Peripheral AUDIO__MODCON base pointer */
  #define AUDIO__MODCON                            ((MODCON_Type *)AUDIO__MODCON_BASE)
  /** Peripheral AUDIO__MODCON base pointer */
  #define AUDIO__MODCON_NS                         ((MODCON_Type *)AUDIO__MODCON_BASE_NS)
  /** Peripheral CMPT__MODCON base address */
  #define CMPT__MODCON_BASE                        (0x54000000u)
  /** Peripheral CMPT__MODCON base address */
  #define CMPT__MODCON_BASE_NS                     (0x44000000u)
  /** Peripheral CMPT__MODCON base pointer */
  #define CMPT__MODCON                             ((MODCON_Type *)CMPT__MODCON_BASE)
  /** Peripheral CMPT__MODCON base pointer */
  #define CMPT__MODCON_NS                          ((MODCON_Type *)CMPT__MODCON_BASE_NS)
  /** Peripheral COMM__MODCON base address */
  #define COMM__MODCON_BASE                        (0x5A000000u)
  /** Peripheral COMM__MODCON base address */
  #define COMM__MODCON_BASE_NS                     (0x4A000000u)
  /** Peripheral COMM__MODCON base pointer */
  #define COMM__MODCON                             ((MODCON_Type *)COMM__MODCON_BASE)
  /** Peripheral COMM__MODCON base pointer */
  #define COMM__MODCON_NS                          ((MODCON_Type *)COMM__MODCON_BASE_NS)
  /** Peripheral MAIN__MODCON base address */
  #define MAIN__MODCON_BASE                        (0x50000000u)
  /** Peripheral MAIN__MODCON base address */
  #define MAIN__MODCON_BASE_NS                     (0x40000000u)
  /** Peripheral MAIN__MODCON base pointer */
  #define MAIN__MODCON                             ((MODCON_Type *)MAIN__MODCON_BASE)
  /** Peripheral MAIN__MODCON base pointer */
  #define MAIN__MODCON_NS                          ((MODCON_Type *)MAIN__MODCON_BASE_NS)
  /** Peripheral MEDIA__MODCON base address */
  #define MEDIA__MODCON_BASE                       (0x5C000000u)
  /** Peripheral MEDIA__MODCON base address */
  #define MEDIA__MODCON_BASE_NS                    (0x4C000000u)
  /** Peripheral MEDIA__MODCON base pointer */
  #define MEDIA__MODCON                            ((MODCON_Type *)MEDIA__MODCON_BASE)
  /** Peripheral MEDIA__MODCON base pointer */
  #define MEDIA__MODCON_NS                         ((MODCON_Type *)MEDIA__MODCON_BASE_NS)
  /** Peripheral WAKE__MODCON base address */
  #define WAKE__MODCON_BASE                        (0x56000000u)
  /** Peripheral WAKE__MODCON base address */
  #define WAKE__MODCON_BASE_NS                     (0x46000000u)
  /** Peripheral WAKE__MODCON base pointer */
  #define WAKE__MODCON                             ((MODCON_Type *)WAKE__MODCON_BASE)
  /** Peripheral WAKE__MODCON base pointer */
  #define WAKE__MODCON_NS                          ((MODCON_Type *)WAKE__MODCON_BASE_NS)
  /** Array initializer of MODCON peripheral base addresses */
  #define MODCON_BASE_ADDRS                        { AUDIO__MODCON_BASE, CMPT__MODCON_BASE, COMM__MODCON_BASE, MAIN__MODCON_BASE, MEDIA__MODCON_BASE, WAKE__MODCON_BASE }
  /** Array initializer of MODCON peripheral base pointers */
  #define MODCON_BASE_PTRS                         { AUDIO__MODCON, CMPT__MODCON, COMM__MODCON, MAIN__MODCON, MEDIA__MODCON, WAKE__MODCON }
  /** Array initializer of MODCON peripheral base addresses */
  #define MODCON_BASE_ADDRS_NS                     { AUDIO__MODCON_BASE_NS, CMPT__MODCON_BASE_NS, COMM__MODCON_BASE_NS, MAIN__MODCON_BASE_NS, MEDIA__MODCON_BASE_NS, WAKE__MODCON_BASE_NS }
  /** Array initializer of MODCON peripheral base pointers */
  #define MODCON_BASE_PTRS_NS                      { AUDIO__MODCON_NS, CMPT__MODCON_NS, COMM__MODCON_NS, MAIN__MODCON_NS, MEDIA__MODCON_NS, WAKE__MODCON_NS }
#else
  /** Peripheral AUDIO__MODCON base address */
  #define AUDIO__MODCON_BASE                       (0x48000000u)
  /** Peripheral AUDIO__MODCON base pointer */
  #define AUDIO__MODCON                            ((MODCON_Type *)AUDIO__MODCON_BASE)
  /** Peripheral CMPT__MODCON base address */
  #define CMPT__MODCON_BASE                        (0x44000000u)
  /** Peripheral CMPT__MODCON base pointer */
  #define CMPT__MODCON                             ((MODCON_Type *)CMPT__MODCON_BASE)
  /** Peripheral COMM__MODCON base address */
  #define COMM__MODCON_BASE                        (0x4A000000u)
  /** Peripheral COMM__MODCON base pointer */
  #define COMM__MODCON                             ((MODCON_Type *)COMM__MODCON_BASE)
  /** Peripheral MAIN__MODCON base address */
  #define MAIN__MODCON_BASE                        (0x40000000u)
  /** Peripheral MAIN__MODCON base pointer */
  #define MAIN__MODCON                             ((MODCON_Type *)MAIN__MODCON_BASE)
  /** Peripheral MEDIA__MODCON base address */
  #define MEDIA__MODCON_BASE                       (0x4C000000u)
  /** Peripheral MEDIA__MODCON base pointer */
  #define MEDIA__MODCON                            ((MODCON_Type *)MEDIA__MODCON_BASE)
  /** Peripheral WAKE__MODCON base address */
  #define WAKE__MODCON_BASE                        (0x46000000u)
  /** Peripheral WAKE__MODCON base pointer */
  #define WAKE__MODCON                             ((MODCON_Type *)WAKE__MODCON_BASE)
  /** Array initializer of MODCON peripheral base addresses */
  #define MODCON_BASE_ADDRS                        { AUDIO__MODCON_BASE, CMPT__MODCON_BASE, COMM__MODCON_BASE, MAIN__MODCON_BASE, MEDIA__MODCON_BASE, WAKE__MODCON_BASE }
  /** Array initializer of MODCON peripheral base pointers */
  #define MODCON_BASE_PTRS                         { AUDIO__MODCON, CMPT__MODCON, COMM__MODCON, MAIN__MODCON, MEDIA__MODCON, WAKE__MODCON }
#endif

/* NIC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMPT__NIC base address */
  #define CMPT__NIC_BASE                           (0x54700000u)
  /** Peripheral CMPT__NIC base address */
  #define CMPT__NIC_BASE_NS                        (0x44700000u)
  /** Peripheral CMPT__NIC base pointer */
  #define CMPT__NIC                                ((NIC_Type *)CMPT__NIC_BASE)
  /** Peripheral CMPT__NIC base pointer */
  #define CMPT__NIC_NS                             ((NIC_Type *)CMPT__NIC_BASE_NS)
  /** Peripheral COMM__NIC base address */
  #define COMM__NIC_BASE                           (0x5A700000u)
  /** Peripheral COMM__NIC base address */
  #define COMM__NIC_BASE_NS                        (0x4A700000u)
  /** Peripheral COMM__NIC base pointer */
  #define COMM__NIC                                ((NIC_Type *)COMM__NIC_BASE)
  /** Peripheral COMM__NIC base pointer */
  #define COMM__NIC_NS                             ((NIC_Type *)COMM__NIC_BASE_NS)
  /** Peripheral MAIN__NIC base address */
  #define MAIN__NIC_BASE                           (0x50700000u)
  /** Peripheral MAIN__NIC base address */
  #define MAIN__NIC_BASE_NS                        (0x40700000u)
  /** Peripheral MAIN__NIC base pointer */
  #define MAIN__NIC                                ((NIC_Type *)MAIN__NIC_BASE)
  /** Peripheral MAIN__NIC base pointer */
  #define MAIN__NIC_NS                             ((NIC_Type *)MAIN__NIC_BASE_NS)
  /** Peripheral MEDIA__NIC base address */
  #define MEDIA__NIC_BASE                          (0x5C700000u)
  /** Peripheral MEDIA__NIC base address */
  #define MEDIA__NIC_BASE_NS                       (0x4C700000u)
  /** Peripheral MEDIA__NIC base pointer */
  #define MEDIA__NIC                               ((NIC_Type *)MEDIA__NIC_BASE)
  /** Peripheral MEDIA__NIC base pointer */
  #define MEDIA__NIC_NS                            ((NIC_Type *)MEDIA__NIC_BASE_NS)
  /** Array initializer of NIC peripheral base addresses */
  #define NIC_BASE_ADDRS                           { CMPT__NIC_BASE, COMM__NIC_BASE, MAIN__NIC_BASE, MEDIA__NIC_BASE }
  /** Array initializer of NIC peripheral base pointers */
  #define NIC_BASE_PTRS                            { CMPT__NIC, COMM__NIC, MAIN__NIC, MEDIA__NIC }
  /** Array initializer of NIC peripheral base addresses */
  #define NIC_BASE_ADDRS_NS                        { CMPT__NIC_BASE_NS, COMM__NIC_BASE_NS, MAIN__NIC_BASE_NS, MEDIA__NIC_BASE_NS }
  /** Array initializer of NIC peripheral base pointers */
  #define NIC_BASE_PTRS_NS                         { CMPT__NIC_NS, COMM__NIC_NS, MAIN__NIC_NS, MEDIA__NIC_NS }
#else
  /** Peripheral CMPT__NIC base address */
  #define CMPT__NIC_BASE                           (0x44700000u)
  /** Peripheral CMPT__NIC base pointer */
  #define CMPT__NIC                                ((NIC_Type *)CMPT__NIC_BASE)
  /** Peripheral COMM__NIC base address */
  #define COMM__NIC_BASE                           (0x4A700000u)
  /** Peripheral COMM__NIC base pointer */
  #define COMM__NIC                                ((NIC_Type *)COMM__NIC_BASE)
  /** Peripheral MAIN__NIC base address */
  #define MAIN__NIC_BASE                           (0x40700000u)
  /** Peripheral MAIN__NIC base pointer */
  #define MAIN__NIC                                ((NIC_Type *)MAIN__NIC_BASE)
  /** Peripheral MEDIA__NIC base address */
  #define MEDIA__NIC_BASE                          (0x4C700000u)
  /** Peripheral MEDIA__NIC base pointer */
  #define MEDIA__NIC                               ((NIC_Type *)MEDIA__NIC_BASE)
  /** Array initializer of NIC peripheral base addresses */
  #define NIC_BASE_ADDRS                           { CMPT__NIC_BASE, COMM__NIC_BASE, MAIN__NIC_BASE, MEDIA__NIC_BASE }
  /** Array initializer of NIC peripheral base pointers */
  #define NIC_BASE_PTRS                            { CMPT__NIC, COMM__NIC, MAIN__NIC, MEDIA__NIC }
#endif

/* NPU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMPT__NPU base address */
  #define CMPT__NPU_BASE                           (0x40900000u)
  /** Peripheral CMPT__NPU base address */
  #define CMPT__NPU_BASE_NS                        (0x30900000u)
  /** Peripheral CMPT__NPU base pointer */
  #define CMPT__NPU                                ((NPU_Type *)CMPT__NPU_BASE)
  /** Peripheral CMPT__NPU base pointer */
  #define CMPT__NPU_NS                             ((NPU_Type *)CMPT__NPU_BASE_NS)
  /** Array initializer of NPU peripheral base addresses */
  #define NPU_BASE_ADDRS                           { CMPT__NPU_BASE }
  /** Array initializer of NPU peripheral base pointers */
  #define NPU_BASE_PTRS                            { CMPT__NPU }
  /** Array initializer of NPU peripheral base addresses */
  #define NPU_BASE_ADDRS_NS                        { CMPT__NPU_BASE_NS }
  /** Array initializer of NPU peripheral base pointers */
  #define NPU_BASE_PTRS_NS                         { CMPT__NPU_NS }
#else
  /** Peripheral CMPT__NPU base address */
  #define CMPT__NPU_BASE                           (0x30900000u)
  /** Peripheral CMPT__NPU base pointer */
  #define CMPT__NPU                                ((NPU_Type *)CMPT__NPU_BASE)
  /** Array initializer of NPU peripheral base addresses */
  #define NPU_BASE_ADDRS                           { CMPT__NPU_BASE }
  /** Array initializer of NPU peripheral base pointers */
  #define NPU_BASE_PTRS                            { CMPT__NPU }
#endif

/* PDCON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON__PDCON base address */
  #define SYSCON__PDCON_BASE                       (0x50550000u)
  /** Peripheral SYSCON__PDCON base address */
  #define SYSCON__PDCON_BASE_NS                    (0x40550000u)
  /** Peripheral SYSCON__PDCON base pointer */
  #define SYSCON__PDCON                            ((PDCON_Type *)SYSCON__PDCON_BASE)
  /** Peripheral SYSCON__PDCON base pointer */
  #define SYSCON__PDCON_NS                         ((PDCON_Type *)SYSCON__PDCON_BASE_NS)
  /** Array initializer of PDCON peripheral base addresses */
  #define PDCON_BASE_ADDRS                         { SYSCON__PDCON_BASE }
  /** Array initializer of PDCON peripheral base pointers */
  #define PDCON_BASE_PTRS                          { SYSCON__PDCON }
  /** Array initializer of PDCON peripheral base addresses */
  #define PDCON_BASE_ADDRS_NS                      { SYSCON__PDCON_BASE_NS }
  /** Array initializer of PDCON peripheral base pointers */
  #define PDCON_BASE_PTRS_NS                       { SYSCON__PDCON_NS }
#else
  /** Peripheral SYSCON__PDCON base address */
  #define SYSCON__PDCON_BASE                       (0x40550000u)
  /** Peripheral SYSCON__PDCON base pointer */
  #define SYSCON__PDCON                            ((PDCON_Type *)SYSCON__PDCON_BASE)
  /** Array initializer of PDCON peripheral base addresses */
  #define PDCON_BASE_ADDRS                         { SYSCON__PDCON_BASE }
  /** Array initializer of PDCON peripheral base pointers */
  #define PDCON_BASE_PTRS                          { SYSCON__PDCON }
#endif

/* PDM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO__MICFIL base address */
  #define AUDIO__MICFIL_BASE                       (0x58080000u)
  /** Peripheral AUDIO__MICFIL base address */
  #define AUDIO__MICFIL_BASE_NS                    (0x48080000u)
  /** Peripheral AUDIO__MICFIL base pointer */
  #define AUDIO__MICFIL                            ((PDM_Type *)AUDIO__MICFIL_BASE)
  /** Peripheral AUDIO__MICFIL base pointer */
  #define AUDIO__MICFIL_NS                         ((PDM_Type *)AUDIO__MICFIL_BASE_NS)
  /** Peripheral WAKE__MICFIL base address */
  #define WAKE__MICFIL_BASE                        (0x560A0000u)
  /** Peripheral WAKE__MICFIL base address */
  #define WAKE__MICFIL_BASE_NS                     (0x460A0000u)
  /** Peripheral WAKE__MICFIL base pointer */
  #define WAKE__MICFIL                             ((PDM_Type *)WAKE__MICFIL_BASE)
  /** Peripheral WAKE__MICFIL base pointer */
  #define WAKE__MICFIL_NS                          ((PDM_Type *)WAKE__MICFIL_BASE_NS)
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS                           { AUDIO__MICFIL_BASE, WAKE__MICFIL_BASE }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS                            { AUDIO__MICFIL, WAKE__MICFIL }
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS_NS                        { AUDIO__MICFIL_BASE_NS, WAKE__MICFIL_BASE_NS }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS_NS                         { AUDIO__MICFIL_NS, WAKE__MICFIL_NS }
#else
  /** Peripheral AUDIO__MICFIL base address */
  #define AUDIO__MICFIL_BASE                       (0x48080000u)
  /** Peripheral AUDIO__MICFIL base pointer */
  #define AUDIO__MICFIL                            ((PDM_Type *)AUDIO__MICFIL_BASE)
  /** Peripheral WAKE__MICFIL base address */
  #define WAKE__MICFIL_BASE                        (0x460A0000u)
  /** Peripheral WAKE__MICFIL base pointer */
  #define WAKE__MICFIL                             ((PDM_Type *)WAKE__MICFIL_BASE)
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS                           { AUDIO__MICFIL_BASE, WAKE__MICFIL_BASE }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS                            { AUDIO__MICFIL, WAKE__MICFIL }
#endif
/** Interrupt vectors for the PDM peripheral type */
#define PDM_Event_IRQS                           { AUDIO_PDM_EVENT_IRQn, WAKE_PDM_EVENT_IRQn }
#define PDM_Error_IRQS                           { AUDIO_PDM_ERROR_IRQn, WAKE_PDM_ERROR_IRQn }
#define PDM_HWVAD_Event_IRQS                     { NotAvail_IRQn, WAKE_PDM_HWVAD_EVENT_IRQn }
#define PDM_HWVAD_Error_IRQS                     { NotAvail_IRQn, WAKE_PDM_HWVAD_ERROR_IRQn }

/* PMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON__PMU base address */
  #define SYSCON__PMU_BASE                         (0x50520000u)
  /** Peripheral SYSCON__PMU base address */
  #define SYSCON__PMU_BASE_NS                      (0x40520000u)
  /** Peripheral SYSCON__PMU base pointer */
  #define SYSCON__PMU                              ((PMU_Type *)SYSCON__PMU_BASE)
  /** Peripheral SYSCON__PMU base pointer */
  #define SYSCON__PMU_NS                           ((PMU_Type *)SYSCON__PMU_BASE_NS)
  /** Array initializer of PMU peripheral base addresses */
  #define PMU_BASE_ADDRS                           { SYSCON__PMU_BASE }
  /** Array initializer of PMU peripheral base pointers */
  #define PMU_BASE_PTRS                            { SYSCON__PMU }
  /** Array initializer of PMU peripheral base addresses */
  #define PMU_BASE_ADDRS_NS                        { SYSCON__PMU_BASE_NS }
  /** Array initializer of PMU peripheral base pointers */
  #define PMU_BASE_PTRS_NS                         { SYSCON__PMU_NS }
#else
  /** Peripheral SYSCON__PMU base address */
  #define SYSCON__PMU_BASE                         (0x40520000u)
  /** Peripheral SYSCON__PMU base pointer */
  #define SYSCON__PMU                              ((PMU_Type *)SYSCON__PMU_BASE)
  /** Array initializer of PMU peripheral base addresses */
  #define PMU_BASE_ADDRS                           { SYSCON__PMU_BASE }
  /** Array initializer of PMU peripheral base pointers */
  #define PMU_BASE_PTRS                            { SYSCON__PMU }
#endif

/* POWERCON_CMC_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON__POWERCON_CMC0_CTRL base address */
  #define SYSCON__POWERCON_CMC0_CTRL_BASE          (0x50540800u)
  /** Peripheral SYSCON__POWERCON_CMC0_CTRL base address */
  #define SYSCON__POWERCON_CMC0_CTRL_BASE_NS       (0x40540800u)
  /** Peripheral SYSCON__POWERCON_CMC0_CTRL base pointer */
  #define SYSCON__POWERCON_CMC0_CTRL               ((POWERCON_CMC_CTRL_Type *)SYSCON__POWERCON_CMC0_CTRL_BASE)
  /** Peripheral SYSCON__POWERCON_CMC0_CTRL base pointer */
  #define SYSCON__POWERCON_CMC0_CTRL_NS            ((POWERCON_CMC_CTRL_Type *)SYSCON__POWERCON_CMC0_CTRL_BASE_NS)
  /** Peripheral SYSCON__POWERCON_CMC1_CTRL base address */
  #define SYSCON__POWERCON_CMC1_CTRL_BASE          (0x50540C00u)
  /** Peripheral SYSCON__POWERCON_CMC1_CTRL base address */
  #define SYSCON__POWERCON_CMC1_CTRL_BASE_NS       (0x40540C00u)
  /** Peripheral SYSCON__POWERCON_CMC1_CTRL base pointer */
  #define SYSCON__POWERCON_CMC1_CTRL               ((POWERCON_CMC_CTRL_Type *)SYSCON__POWERCON_CMC1_CTRL_BASE)
  /** Peripheral SYSCON__POWERCON_CMC1_CTRL base pointer */
  #define SYSCON__POWERCON_CMC1_CTRL_NS            ((POWERCON_CMC_CTRL_Type *)SYSCON__POWERCON_CMC1_CTRL_BASE_NS)
  /** Peripheral SYSCON__POWERCON_CMC2_CTRL base address */
  #define SYSCON__POWERCON_CMC2_CTRL_BASE          (0x50541000u)
  /** Peripheral SYSCON__POWERCON_CMC2_CTRL base address */
  #define SYSCON__POWERCON_CMC2_CTRL_BASE_NS       (0x40541000u)
  /** Peripheral SYSCON__POWERCON_CMC2_CTRL base pointer */
  #define SYSCON__POWERCON_CMC2_CTRL               ((POWERCON_CMC_CTRL_Type *)SYSCON__POWERCON_CMC2_CTRL_BASE)
  /** Peripheral SYSCON__POWERCON_CMC2_CTRL base pointer */
  #define SYSCON__POWERCON_CMC2_CTRL_NS            ((POWERCON_CMC_CTRL_Type *)SYSCON__POWERCON_CMC2_CTRL_BASE_NS)
  /** Array initializer of POWERCON_CMC_CTRL peripheral base addresses */
  #define POWERCON_CMC_CTRL_BASE_ADDRS             { SYSCON__POWERCON_CMC0_CTRL_BASE, SYSCON__POWERCON_CMC1_CTRL_BASE, SYSCON__POWERCON_CMC2_CTRL_BASE }
  /** Array initializer of POWERCON_CMC_CTRL peripheral base pointers */
  #define POWERCON_CMC_CTRL_BASE_PTRS              { SYSCON__POWERCON_CMC0_CTRL, SYSCON__POWERCON_CMC1_CTRL, SYSCON__POWERCON_CMC2_CTRL }
  /** Array initializer of POWERCON_CMC_CTRL peripheral base addresses */
  #define POWERCON_CMC_CTRL_BASE_ADDRS_NS          { SYSCON__POWERCON_CMC0_CTRL_BASE_NS, SYSCON__POWERCON_CMC1_CTRL_BASE_NS, SYSCON__POWERCON_CMC2_CTRL_BASE_NS }
  /** Array initializer of POWERCON_CMC_CTRL peripheral base pointers */
  #define POWERCON_CMC_CTRL_BASE_PTRS_NS           { SYSCON__POWERCON_CMC0_CTRL_NS, SYSCON__POWERCON_CMC1_CTRL_NS, SYSCON__POWERCON_CMC2_CTRL_NS }
#else
  /** Peripheral SYSCON__POWERCON_CMC0_CTRL base address */
  #define SYSCON__POWERCON_CMC0_CTRL_BASE          (0x40540800u)
  /** Peripheral SYSCON__POWERCON_CMC0_CTRL base pointer */
  #define SYSCON__POWERCON_CMC0_CTRL               ((POWERCON_CMC_CTRL_Type *)SYSCON__POWERCON_CMC0_CTRL_BASE)
  /** Peripheral SYSCON__POWERCON_CMC1_CTRL base address */
  #define SYSCON__POWERCON_CMC1_CTRL_BASE          (0x40540C00u)
  /** Peripheral SYSCON__POWERCON_CMC1_CTRL base pointer */
  #define SYSCON__POWERCON_CMC1_CTRL               ((POWERCON_CMC_CTRL_Type *)SYSCON__POWERCON_CMC1_CTRL_BASE)
  /** Peripheral SYSCON__POWERCON_CMC2_CTRL base address */
  #define SYSCON__POWERCON_CMC2_CTRL_BASE          (0x40541000u)
  /** Peripheral SYSCON__POWERCON_CMC2_CTRL base pointer */
  #define SYSCON__POWERCON_CMC2_CTRL               ((POWERCON_CMC_CTRL_Type *)SYSCON__POWERCON_CMC2_CTRL_BASE)
  /** Array initializer of POWERCON_CMC_CTRL peripheral base addresses */
  #define POWERCON_CMC_CTRL_BASE_ADDRS             { SYSCON__POWERCON_CMC0_CTRL_BASE, SYSCON__POWERCON_CMC1_CTRL_BASE, SYSCON__POWERCON_CMC2_CTRL_BASE }
  /** Array initializer of POWERCON_CMC_CTRL peripheral base pointers */
  #define POWERCON_CMC_CTRL_BASE_PTRS              { SYSCON__POWERCON_CMC0_CTRL, SYSCON__POWERCON_CMC1_CTRL, SYSCON__POWERCON_CMC2_CTRL }
#endif

/* POWERCON_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON__POWERCON_GLOBAL base address */
  #define SYSCON__POWERCON_GLOBAL_BASE             (0x50540000u)
  /** Peripheral SYSCON__POWERCON_GLOBAL base address */
  #define SYSCON__POWERCON_GLOBAL_BASE_NS          (0x40540000u)
  /** Peripheral SYSCON__POWERCON_GLOBAL base pointer */
  #define SYSCON__POWERCON_GLOBAL                  ((POWERCON_GLOBAL_Type *)SYSCON__POWERCON_GLOBAL_BASE)
  /** Peripheral SYSCON__POWERCON_GLOBAL base pointer */
  #define SYSCON__POWERCON_GLOBAL_NS               ((POWERCON_GLOBAL_Type *)SYSCON__POWERCON_GLOBAL_BASE_NS)
  /** Array initializer of POWERCON_GLOBAL peripheral base addresses */
  #define POWERCON_GLOBAL_BASE_ADDRS               { SYSCON__POWERCON_GLOBAL_BASE }
  /** Array initializer of POWERCON_GLOBAL peripheral base pointers */
  #define POWERCON_GLOBAL_BASE_PTRS                { SYSCON__POWERCON_GLOBAL }
  /** Array initializer of POWERCON_GLOBAL peripheral base addresses */
  #define POWERCON_GLOBAL_BASE_ADDRS_NS            { SYSCON__POWERCON_GLOBAL_BASE_NS }
  /** Array initializer of POWERCON_GLOBAL peripheral base pointers */
  #define POWERCON_GLOBAL_BASE_PTRS_NS             { SYSCON__POWERCON_GLOBAL_NS }
#else
  /** Peripheral SYSCON__POWERCON_GLOBAL base address */
  #define SYSCON__POWERCON_GLOBAL_BASE             (0x40540000u)
  /** Peripheral SYSCON__POWERCON_GLOBAL base pointer */
  #define SYSCON__POWERCON_GLOBAL                  ((POWERCON_GLOBAL_Type *)SYSCON__POWERCON_GLOBAL_BASE)
  /** Array initializer of POWERCON_GLOBAL peripheral base addresses */
  #define POWERCON_GLOBAL_BASE_ADDRS               { SYSCON__POWERCON_GLOBAL_BASE }
  /** Array initializer of POWERCON_GLOBAL peripheral base pointers */
  #define POWERCON_GLOBAL_BASE_PTRS                { SYSCON__POWERCON_GLOBAL }
#endif

/* POWERCON_SOC_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON__POWERCON_SOC_CTRL base address */
  #define SYSCON__POWERCON_SOC_CTRL_BASE           (0x50548000u)
  /** Peripheral SYSCON__POWERCON_SOC_CTRL base address */
  #define SYSCON__POWERCON_SOC_CTRL_BASE_NS        (0x40548000u)
  /** Peripheral SYSCON__POWERCON_SOC_CTRL base pointer */
  #define SYSCON__POWERCON_SOC_CTRL                ((POWERCON_SOC_CTRL_Type *)SYSCON__POWERCON_SOC_CTRL_BASE)
  /** Peripheral SYSCON__POWERCON_SOC_CTRL base pointer */
  #define SYSCON__POWERCON_SOC_CTRL_NS             ((POWERCON_SOC_CTRL_Type *)SYSCON__POWERCON_SOC_CTRL_BASE_NS)
  /** Array initializer of POWERCON_SOC_CTRL peripheral base addresses */
  #define POWERCON_SOC_CTRL_BASE_ADDRS             { SYSCON__POWERCON_SOC_CTRL_BASE }
  /** Array initializer of POWERCON_SOC_CTRL peripheral base pointers */
  #define POWERCON_SOC_CTRL_BASE_PTRS              { SYSCON__POWERCON_SOC_CTRL }
  /** Array initializer of POWERCON_SOC_CTRL peripheral base addresses */
  #define POWERCON_SOC_CTRL_BASE_ADDRS_NS          { SYSCON__POWERCON_SOC_CTRL_BASE_NS }
  /** Array initializer of POWERCON_SOC_CTRL peripheral base pointers */
  #define POWERCON_SOC_CTRL_BASE_PTRS_NS           { SYSCON__POWERCON_SOC_CTRL_NS }
#else
  /** Peripheral SYSCON__POWERCON_SOC_CTRL base address */
  #define SYSCON__POWERCON_SOC_CTRL_BASE           (0x40548000u)
  /** Peripheral SYSCON__POWERCON_SOC_CTRL base pointer */
  #define SYSCON__POWERCON_SOC_CTRL                ((POWERCON_SOC_CTRL_Type *)SYSCON__POWERCON_SOC_CTRL_BASE)
  /** Array initializer of POWERCON_SOC_CTRL peripheral base addresses */
  #define POWERCON_SOC_CTRL_BASE_ADDRS             { SYSCON__POWERCON_SOC_CTRL_BASE }
  /** Array initializer of POWERCON_SOC_CTRL peripheral base pointers */
  #define POWERCON_SOC_CTRL_BASE_PTRS              { SYSCON__POWERCON_SOC_CTRL }
#endif

/* POWERCON_SYS_SLEEP_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON__POWERCON_SYS_SLEEP_CTRL base address */
  #define SYSCON__POWERCON_SYS_SLEEP_CTRL_BASE     (0x50540400u)
  /** Peripheral SYSCON__POWERCON_SYS_SLEEP_CTRL base address */
  #define SYSCON__POWERCON_SYS_SLEEP_CTRL_BASE_NS  (0x40540400u)
  /** Peripheral SYSCON__POWERCON_SYS_SLEEP_CTRL base pointer */
  #define SYSCON__POWERCON_SYS_SLEEP_CTRL          ((POWERCON_SYS_SLEEP_CTRL_Type *)SYSCON__POWERCON_SYS_SLEEP_CTRL_BASE)
  /** Peripheral SYSCON__POWERCON_SYS_SLEEP_CTRL base pointer */
  #define SYSCON__POWERCON_SYS_SLEEP_CTRL_NS       ((POWERCON_SYS_SLEEP_CTRL_Type *)SYSCON__POWERCON_SYS_SLEEP_CTRL_BASE_NS)
  /** Array initializer of POWERCON_SYS_SLEEP_CTRL peripheral base addresses */
  #define POWERCON_SYS_SLEEP_CTRL_BASE_ADDRS       { SYSCON__POWERCON_SYS_SLEEP_CTRL_BASE }
  /** Array initializer of POWERCON_SYS_SLEEP_CTRL peripheral base pointers */
  #define POWERCON_SYS_SLEEP_CTRL_BASE_PTRS        { SYSCON__POWERCON_SYS_SLEEP_CTRL }
  /** Array initializer of POWERCON_SYS_SLEEP_CTRL peripheral base addresses */
  #define POWERCON_SYS_SLEEP_CTRL_BASE_ADDRS_NS    { SYSCON__POWERCON_SYS_SLEEP_CTRL_BASE_NS }
  /** Array initializer of POWERCON_SYS_SLEEP_CTRL peripheral base pointers */
  #define POWERCON_SYS_SLEEP_CTRL_BASE_PTRS_NS     { SYSCON__POWERCON_SYS_SLEEP_CTRL_NS }
#else
  /** Peripheral SYSCON__POWERCON_SYS_SLEEP_CTRL base address */
  #define SYSCON__POWERCON_SYS_SLEEP_CTRL_BASE     (0x40540400u)
  /** Peripheral SYSCON__POWERCON_SYS_SLEEP_CTRL base pointer */
  #define SYSCON__POWERCON_SYS_SLEEP_CTRL          ((POWERCON_SYS_SLEEP_CTRL_Type *)SYSCON__POWERCON_SYS_SLEEP_CTRL_BASE)
  /** Array initializer of POWERCON_SYS_SLEEP_CTRL peripheral base addresses */
  #define POWERCON_SYS_SLEEP_CTRL_BASE_ADDRS       { SYSCON__POWERCON_SYS_SLEEP_CTRL_BASE }
  /** Array initializer of POWERCON_SYS_SLEEP_CTRL peripheral base pointers */
  #define POWERCON_SYS_SLEEP_CTRL_BASE_PTRS        { SYSCON__POWERCON_SYS_SLEEP_CTRL }
#endif

/* PWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__FLEXPWM_0 base address */
  #define HSP__FLEXPWM_0_BASE                      (0x52080000u)
  /** Peripheral HSP__FLEXPWM_0 base address */
  #define HSP__FLEXPWM_0_BASE_NS                   (0x42080000u)
  /** Peripheral HSP__FLEXPWM_0 base pointer */
  #define HSP__FLEXPWM_0                           ((PWM_Type *)HSP__FLEXPWM_0_BASE)
  /** Peripheral HSP__FLEXPWM_0 base pointer */
  #define HSP__FLEXPWM_0_NS                        ((PWM_Type *)HSP__FLEXPWM_0_BASE_NS)
  /** Peripheral HSP__FLEXPWM_1 base address */
  #define HSP__FLEXPWM_1_BASE                      (0x52090000u)
  /** Peripheral HSP__FLEXPWM_1 base address */
  #define HSP__FLEXPWM_1_BASE_NS                   (0x42090000u)
  /** Peripheral HSP__FLEXPWM_1 base pointer */
  #define HSP__FLEXPWM_1                           ((PWM_Type *)HSP__FLEXPWM_1_BASE)
  /** Peripheral HSP__FLEXPWM_1 base pointer */
  #define HSP__FLEXPWM_1_NS                        ((PWM_Type *)HSP__FLEXPWM_1_BASE_NS)
  /** Peripheral HSP__FLEXPWM_2 base address */
  #define HSP__FLEXPWM_2_BASE                      (0x52870000u)
  /** Peripheral HSP__FLEXPWM_2 base address */
  #define HSP__FLEXPWM_2_BASE_NS                   (0x42870000u)
  /** Peripheral HSP__FLEXPWM_2 base pointer */
  #define HSP__FLEXPWM_2                           ((PWM_Type *)HSP__FLEXPWM_2_BASE)
  /** Peripheral HSP__FLEXPWM_2 base pointer */
  #define HSP__FLEXPWM_2_NS                        ((PWM_Type *)HSP__FLEXPWM_2_BASE_NS)
  /** Peripheral HSP__FLEXPWM_3 base address */
  #define HSP__FLEXPWM_3_BASE                      (0x52880000u)
  /** Peripheral HSP__FLEXPWM_3 base address */
  #define HSP__FLEXPWM_3_BASE_NS                   (0x42880000u)
  /** Peripheral HSP__FLEXPWM_3 base pointer */
  #define HSP__FLEXPWM_3                           ((PWM_Type *)HSP__FLEXPWM_3_BASE)
  /** Peripheral HSP__FLEXPWM_3 base pointer */
  #define HSP__FLEXPWM_3_NS                        ((PWM_Type *)HSP__FLEXPWM_3_BASE_NS)
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS                           { HSP__FLEXPWM_0_BASE, HSP__FLEXPWM_1_BASE, HSP__FLEXPWM_2_BASE, HSP__FLEXPWM_3_BASE }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS                            { HSP__FLEXPWM_0, HSP__FLEXPWM_1, HSP__FLEXPWM_2, HSP__FLEXPWM_3 }
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS_NS                        { HSP__FLEXPWM_0_BASE_NS, HSP__FLEXPWM_1_BASE_NS, HSP__FLEXPWM_2_BASE_NS, HSP__FLEXPWM_3_BASE_NS }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS_NS                         { HSP__FLEXPWM_0_NS, HSP__FLEXPWM_1_NS, HSP__FLEXPWM_2_NS, HSP__FLEXPWM_3_NS }
#else
  /** Peripheral HSP__FLEXPWM_0 base address */
  #define HSP__FLEXPWM_0_BASE                      (0x42080000u)
  /** Peripheral HSP__FLEXPWM_0 base pointer */
  #define HSP__FLEXPWM_0                           ((PWM_Type *)HSP__FLEXPWM_0_BASE)
  /** Peripheral HSP__FLEXPWM_1 base address */
  #define HSP__FLEXPWM_1_BASE                      (0x42090000u)
  /** Peripheral HSP__FLEXPWM_1 base pointer */
  #define HSP__FLEXPWM_1                           ((PWM_Type *)HSP__FLEXPWM_1_BASE)
  /** Peripheral HSP__FLEXPWM_2 base address */
  #define HSP__FLEXPWM_2_BASE                      (0x42870000u)
  /** Peripheral HSP__FLEXPWM_2 base pointer */
  #define HSP__FLEXPWM_2                           ((PWM_Type *)HSP__FLEXPWM_2_BASE)
  /** Peripheral HSP__FLEXPWM_3 base address */
  #define HSP__FLEXPWM_3_BASE                      (0x42880000u)
  /** Peripheral HSP__FLEXPWM_3 base pointer */
  #define HSP__FLEXPWM_3                           ((PWM_Type *)HSP__FLEXPWM_3_BASE)
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS                           { HSP__FLEXPWM_0_BASE, HSP__FLEXPWM_1_BASE, HSP__FLEXPWM_2_BASE, HSP__FLEXPWM_3_BASE }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS                            { HSP__FLEXPWM_0, HSP__FLEXPWM_1, HSP__FLEXPWM_2, HSP__FLEXPWM_3 }
#endif
/** Interrupt vectors for the PWM peripheral type */
#define PWM_CMP_IRQS                             { { HSP_EFLEXPWM0_CH0_IRQn, HSP_EFLEXPWM0_CH1_IRQn, HSP_EFLEXPWM0_CH2_IRQn, HSP_EFLEXPWM0_CH3_IRQn }, { HSP_EFLEXPWM1_CH0_IRQn, HSP_EFLEXPWM1_CH1_IRQn, HSP_EFLEXPWM1_CH2_IRQn, HSP_EFLEXPWM1_CH3_IRQn }, { HSP_EFLEXPWM2_CH0_IRQn, HSP_EFLEXPWM2_CH1_IRQn, HSP_EFLEXPWM2_CH2_IRQn, HSP_EFLEXPWM2_CH3_IRQn }, { HSP_EFLEXPWM3_CH0_IRQn, HSP_EFLEXPWM3_CH1_IRQn, HSP_EFLEXPWM3_CH2_IRQn, HSP_EFLEXPWM3_CH3_IRQn } }
#define PWM_RELOAD_IRQS                          { { HSP_EFLEXPWM0_CH0_IRQn, HSP_EFLEXPWM0_CH1_IRQn, HSP_EFLEXPWM0_CH2_IRQn, HSP_EFLEXPWM0_CH3_IRQn }, { HSP_EFLEXPWM1_CH0_IRQn, HSP_EFLEXPWM1_CH1_IRQn, HSP_EFLEXPWM1_CH2_IRQn, HSP_EFLEXPWM1_CH3_IRQn }, { HSP_EFLEXPWM2_CH0_IRQn, HSP_EFLEXPWM2_CH1_IRQn, HSP_EFLEXPWM2_CH2_IRQn, HSP_EFLEXPWM2_CH3_IRQn }, { HSP_EFLEXPWM3_CH0_IRQn, HSP_EFLEXPWM3_CH1_IRQn, HSP_EFLEXPWM3_CH2_IRQn, HSP_EFLEXPWM3_CH3_IRQn } }
#define PWM_CAPTURE_IRQS                         { { HSP_EFLEXPWM0_CH0_IRQn, HSP_EFLEXPWM0_CH1_IRQn, HSP_EFLEXPWM0_CH2_IRQn, HSP_EFLEXPWM0_CH3_IRQn }, { HSP_EFLEXPWM1_CH0_IRQn, HSP_EFLEXPWM1_CH1_IRQn, HSP_EFLEXPWM1_CH2_IRQn, HSP_EFLEXPWM1_CH3_IRQn }, { HSP_EFLEXPWM2_CH0_IRQn, HSP_EFLEXPWM2_CH1_IRQn, HSP_EFLEXPWM2_CH2_IRQn, HSP_EFLEXPWM2_CH3_IRQn }, { HSP_EFLEXPWM3_CH0_IRQn, HSP_EFLEXPWM3_CH1_IRQn, HSP_EFLEXPWM3_CH2_IRQn, HSP_EFLEXPWM3_CH3_IRQn } }
#define PWM_FAULT_IRQS                           { HSP_EFLEXPWM0_ERROR_IRQn, HSP_EFLEXPWM1_ERROR_IRQn, HSP_EFLEXPWM2_ERROR_IRQn, HSP_EFLEXPWM3_ERROR_IRQn }

/* REFORMATTER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MEDIA__REFORMATTER base address */
  #define MEDIA__REFORMATTER_BASE                  (0x5C0F0000u)
  /** Peripheral MEDIA__REFORMATTER base address */
  #define MEDIA__REFORMATTER_BASE_NS               (0x4C0F0000u)
  /** Peripheral MEDIA__REFORMATTER base pointer */
  #define MEDIA__REFORMATTER                       ((REFORMATTER_Type *)MEDIA__REFORMATTER_BASE)
  /** Peripheral MEDIA__REFORMATTER base pointer */
  #define MEDIA__REFORMATTER_NS                    ((REFORMATTER_Type *)MEDIA__REFORMATTER_BASE_NS)
  /** Array initializer of REFORMATTER peripheral base addresses */
  #define REFORMATTER_BASE_ADDRS                   { MEDIA__REFORMATTER_BASE }
  /** Array initializer of REFORMATTER peripheral base pointers */
  #define REFORMATTER_BASE_PTRS                    { MEDIA__REFORMATTER }
  /** Array initializer of REFORMATTER peripheral base addresses */
  #define REFORMATTER_BASE_ADDRS_NS                { MEDIA__REFORMATTER_BASE_NS }
  /** Array initializer of REFORMATTER peripheral base pointers */
  #define REFORMATTER_BASE_PTRS_NS                 { MEDIA__REFORMATTER_NS }
#else
  /** Peripheral MEDIA__REFORMATTER base address */
  #define MEDIA__REFORMATTER_BASE                  (0x4C0F0000u)
  /** Peripheral MEDIA__REFORMATTER base pointer */
  #define MEDIA__REFORMATTER                       ((REFORMATTER_Type *)MEDIA__REFORMATTER_BASE)
  /** Array initializer of REFORMATTER peripheral base addresses */
  #define REFORMATTER_BASE_ADDRS                   { MEDIA__REFORMATTER_BASE }
  /** Array initializer of REFORMATTER peripheral base pointers */
  #define REFORMATTER_BASE_PTRS                    { MEDIA__REFORMATTER }
#endif

/* RESETCON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYSCON__RESETCON base address */
  #define SYSCON__RESETCON_BASE                    (0x50530000u)
  /** Peripheral SYSCON__RESETCON base address */
  #define SYSCON__RESETCON_BASE_NS                 (0x40530000u)
  /** Peripheral SYSCON__RESETCON base pointer */
  #define SYSCON__RESETCON                         ((RESETCON_Type *)SYSCON__RESETCON_BASE)
  /** Peripheral SYSCON__RESETCON base pointer */
  #define SYSCON__RESETCON_NS                      ((RESETCON_Type *)SYSCON__RESETCON_BASE_NS)
  /** Array initializer of RESETCON peripheral base addresses */
  #define RESETCON_BASE_ADDRS                      { SYSCON__RESETCON_BASE }
  /** Array initializer of RESETCON peripheral base pointers */
  #define RESETCON_BASE_PTRS                       { SYSCON__RESETCON }
  /** Array initializer of RESETCON peripheral base addresses */
  #define RESETCON_BASE_ADDRS_NS                   { SYSCON__RESETCON_BASE_NS }
  /** Array initializer of RESETCON peripheral base pointers */
  #define RESETCON_BASE_PTRS_NS                    { SYSCON__RESETCON_NS }
#else
  /** Peripheral SYSCON__RESETCON base address */
  #define SYSCON__RESETCON_BASE                    (0x40530000u)
  /** Peripheral SYSCON__RESETCON base pointer */
  #define SYSCON__RESETCON                         ((RESETCON_Type *)SYSCON__RESETCON_BASE)
  /** Array initializer of RESETCON peripheral base addresses */
  #define RESETCON_BASE_ADDRS                      { SYSCON__RESETCON_BASE }
  /** Array initializer of RESETCON peripheral base pointers */
  #define RESETCON_BASE_PTRS                       { SYSCON__RESETCON }
#endif

/* ROMCP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMPT__ROMCP base address */
  #define CMPT__ROMCP_BASE                         (0x541B0000u)
  /** Peripheral CMPT__ROMCP base address */
  #define CMPT__ROMCP_BASE_NS                      (0x441B0000u)
  /** Peripheral CMPT__ROMCP base pointer */
  #define CMPT__ROMCP                              ((ROMCP_Type *)CMPT__ROMCP_BASE)
  /** Peripheral CMPT__ROMCP base pointer */
  #define CMPT__ROMCP_NS                           ((ROMCP_Type *)CMPT__ROMCP_BASE_NS)
  /** Array initializer of ROMCP peripheral base addresses */
  #define ROMCP_BASE_ADDRS                         { CMPT__ROMCP_BASE }
  /** Array initializer of ROMCP peripheral base pointers */
  #define ROMCP_BASE_PTRS                          { CMPT__ROMCP }
  /** Array initializer of ROMCP peripheral base addresses */
  #define ROMCP_BASE_ADDRS_NS                      { CMPT__ROMCP_BASE_NS }
  /** Array initializer of ROMCP peripheral base pointers */
  #define ROMCP_BASE_PTRS_NS                       { CMPT__ROMCP_NS }
#else
  /** Peripheral CMPT__ROMCP base address */
  #define CMPT__ROMCP_BASE                         (0x441B0000u)
  /** Peripheral CMPT__ROMCP base pointer */
  #define CMPT__ROMCP                              ((ROMCP_Type *)CMPT__ROMCP_BASE)
  /** Array initializer of ROMCP peripheral base addresses */
  #define ROMCP_BASE_ADDRS                         { CMPT__ROMCP_BASE }
  /** Array initializer of ROMCP peripheral base pointers */
  #define ROMCP_BASE_PTRS                          { CMPT__ROMCP }
#endif

/* RTC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VBAT__RTC base address */
  #define VBAT__RTC_BASE                           (0x56340000u)
  /** Peripheral VBAT__RTC base address */
  #define VBAT__RTC_BASE_NS                        (0x46340000u)
  /** Peripheral VBAT__RTC base pointer */
  #define VBAT__RTC                                ((RTC_Type *)VBAT__RTC_BASE)
  /** Peripheral VBAT__RTC base pointer */
  #define VBAT__RTC_NS                             ((RTC_Type *)VBAT__RTC_BASE_NS)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { VBAT__RTC_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { VBAT__RTC }
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS_NS                        { VBAT__RTC_BASE_NS }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS_NS                         { VBAT__RTC_NS }
#else
  /** Peripheral VBAT__RTC base address */
  #define VBAT__RTC_BASE                           (0x46340000u)
  /** Peripheral VBAT__RTC base pointer */
  #define VBAT__RTC                                ((RTC_Type *)VBAT__RTC_BASE)
  /** Array initializer of RTC peripheral base addresses */
  #define RTC_BASE_ADDRS                           { VBAT__RTC_BASE }
  /** Array initializer of RTC peripheral base pointers */
  #define RTC_BASE_PTRS                            { VBAT__RTC }
#endif
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { VBAT_RTC_IRQn }

/* S3MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MAIN__SENTMU0_SENTMUA base address */
  #define MAIN__SENTMU0_SENTMUA_BASE               (0x50610000u)
  /** Peripheral MAIN__SENTMU0_SENTMUA base address */
  #define MAIN__SENTMU0_SENTMUA_BASE_NS            (0x40610000u)
  /** Peripheral MAIN__SENTMU0_SENTMUA base pointer */
  #define MAIN__SENTMU0_SENTMUA                    ((S3MU_Type *)MAIN__SENTMU0_SENTMUA_BASE)
  /** Peripheral MAIN__SENTMU0_SENTMUA base pointer */
  #define MAIN__SENTMU0_SENTMUA_NS                 ((S3MU_Type *)MAIN__SENTMU0_SENTMUA_BASE_NS)
  /** Peripheral MAIN__SENTMU1_SENTMUA base address */
  #define MAIN__SENTMU1_SENTMUA_BASE               (0x50620000u)
  /** Peripheral MAIN__SENTMU1_SENTMUA base address */
  #define MAIN__SENTMU1_SENTMUA_BASE_NS            (0x40620000u)
  /** Peripheral MAIN__SENTMU1_SENTMUA base pointer */
  #define MAIN__SENTMU1_SENTMUA                    ((S3MU_Type *)MAIN__SENTMU1_SENTMUA_BASE)
  /** Peripheral MAIN__SENTMU1_SENTMUA base pointer */
  #define MAIN__SENTMU1_SENTMUA_NS                 ((S3MU_Type *)MAIN__SENTMU1_SENTMUA_BASE_NS)
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS                          { MAIN__SENTMU0_SENTMUA_BASE, MAIN__SENTMU1_SENTMUA_BASE }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS                           { MAIN__SENTMU0_SENTMUA, MAIN__SENTMU1_SENTMUA }
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS_NS                       { MAIN__SENTMU0_SENTMUA_BASE_NS, MAIN__SENTMU1_SENTMUA_BASE_NS }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS_NS                        { MAIN__SENTMU0_SENTMUA_NS, MAIN__SENTMU1_SENTMUA_NS }
#else
  /** Peripheral MAIN__SENTMU0_SENTMUA base address */
  #define MAIN__SENTMU0_SENTMUA_BASE               (0x40610000u)
  /** Peripheral MAIN__SENTMU0_SENTMUA base pointer */
  #define MAIN__SENTMU0_SENTMUA                    ((S3MU_Type *)MAIN__SENTMU0_SENTMUA_BASE)
  /** Peripheral MAIN__SENTMU1_SENTMUA base address */
  #define MAIN__SENTMU1_SENTMUA_BASE               (0x40620000u)
  /** Peripheral MAIN__SENTMU1_SENTMUA base pointer */
  #define MAIN__SENTMU1_SENTMUA                    ((S3MU_Type *)MAIN__SENTMU1_SENTMUA_BASE)
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS                          { MAIN__SENTMU0_SENTMUA_BASE, MAIN__SENTMU1_SENTMUA_BASE }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS                           { MAIN__SENTMU0_SENTMUA, MAIN__SENTMU1_SENTMUA }
#endif

/* SINC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__SINC_0 base address */
  #define HSP__SINC_0_BASE                         (0x520E0000u)
  /** Peripheral HSP__SINC_0 base address */
  #define HSP__SINC_0_BASE_NS                      (0x420E0000u)
  /** Peripheral HSP__SINC_0 base pointer */
  #define HSP__SINC_0                              ((SINC_Type *)HSP__SINC_0_BASE)
  /** Peripheral HSP__SINC_0 base pointer */
  #define HSP__SINC_0_NS                           ((SINC_Type *)HSP__SINC_0_BASE_NS)
  /** Peripheral HSP__SINC_1 base address */
  #define HSP__SINC_1_BASE                         (0x528E0000u)
  /** Peripheral HSP__SINC_1 base address */
  #define HSP__SINC_1_BASE_NS                      (0x428E0000u)
  /** Peripheral HSP__SINC_1 base pointer */
  #define HSP__SINC_1                              ((SINC_Type *)HSP__SINC_1_BASE)
  /** Peripheral HSP__SINC_1 base pointer */
  #define HSP__SINC_1_NS                           ((SINC_Type *)HSP__SINC_1_BASE_NS)
  /** Array initializer of SINC peripheral base addresses */
  #define SINC_BASE_ADDRS                          { HSP__SINC_0_BASE, HSP__SINC_1_BASE }
  /** Array initializer of SINC peripheral base pointers */
  #define SINC_BASE_PTRS                           { HSP__SINC_0, HSP__SINC_1 }
  /** Array initializer of SINC peripheral base addresses */
  #define SINC_BASE_ADDRS_NS                       { HSP__SINC_0_BASE_NS, HSP__SINC_1_BASE_NS }
  /** Array initializer of SINC peripheral base pointers */
  #define SINC_BASE_PTRS_NS                        { HSP__SINC_0_NS, HSP__SINC_1_NS }
#else
  /** Peripheral HSP__SINC_0 base address */
  #define HSP__SINC_0_BASE                         (0x420E0000u)
  /** Peripheral HSP__SINC_0 base pointer */
  #define HSP__SINC_0                              ((SINC_Type *)HSP__SINC_0_BASE)
  /** Peripheral HSP__SINC_1 base address */
  #define HSP__SINC_1_BASE                         (0x428E0000u)
  /** Peripheral HSP__SINC_1 base pointer */
  #define HSP__SINC_1                              ((SINC_Type *)HSP__SINC_1_BASE)
  /** Array initializer of SINC peripheral base addresses */
  #define SINC_BASE_ADDRS                          { HSP__SINC_0_BASE, HSP__SINC_1_BASE }
  /** Array initializer of SINC peripheral base pointers */
  #define SINC_BASE_PTRS                           { HSP__SINC_0, HSP__SINC_1 }
#endif
/** Interrupt vectors for the SINC peripheral type */
#define SINC_IRQS                                { { HSP_SINC0_CH0_IRQn, HSP_SINC0_CH1_IRQn, HSP_SINC0_CH2_IRQn, HSP_SINC0_CH3_IRQn }, { HSP_SINC1_CH0_IRQn, HSP_SINC1_CH1_IRQn, HSP_SINC1_CH2_IRQn, HSP_SINC1_CH3_IRQn } }

/* SRAM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VBAT__SRAM base address */
  #define VBAT__SRAM_BASE                          (0x56300000u)
  /** Peripheral VBAT__SRAM base address */
  #define VBAT__SRAM_BASE_NS                       (0x46300000u)
  /** Peripheral VBAT__SRAM base pointer */
  #define VBAT__SRAM                               ((SRAM_Type *)VBAT__SRAM_BASE)
  /** Peripheral VBAT__SRAM base pointer */
  #define VBAT__SRAM_NS                            ((SRAM_Type *)VBAT__SRAM_BASE_NS)
  /** Array initializer of SRAM peripheral base addresses */
  #define SRAM_BASE_ADDRS                          { VBAT__SRAM_BASE }
  /** Array initializer of SRAM peripheral base pointers */
  #define SRAM_BASE_PTRS                           { VBAT__SRAM }
  /** Array initializer of SRAM peripheral base addresses */
  #define SRAM_BASE_ADDRS_NS                       { VBAT__SRAM_BASE_NS }
  /** Array initializer of SRAM peripheral base pointers */
  #define SRAM_BASE_PTRS_NS                        { VBAT__SRAM_NS }
#else
  /** Peripheral VBAT__SRAM base address */
  #define VBAT__SRAM_BASE                          (0x46300000u)
  /** Peripheral VBAT__SRAM base pointer */
  #define VBAT__SRAM                               ((SRAM_Type *)VBAT__SRAM_BASE)
  /** Array initializer of SRAM peripheral base addresses */
  #define SRAM_BASE_ADDRS                          { VBAT__SRAM_BASE }
  /** Array initializer of SRAM peripheral base pointers */
  #define SRAM_BASE_PTRS                           { VBAT__SRAM }
#endif

/* SRAMCTL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMPT__SRAMCTL_0 base address */
  #define CMPT__SRAMCTL_0_BASE                     (0x54080000u)
  /** Peripheral CMPT__SRAMCTL_0 base address */
  #define CMPT__SRAMCTL_0_BASE_NS                  (0x44080000u)
  /** Peripheral CMPT__SRAMCTL_0 base pointer */
  #define CMPT__SRAMCTL_0                          ((SRAMCTL_Type *)CMPT__SRAMCTL_0_BASE)
  /** Peripheral CMPT__SRAMCTL_0 base pointer */
  #define CMPT__SRAMCTL_0_NS                       ((SRAMCTL_Type *)CMPT__SRAMCTL_0_BASE_NS)
  /** Peripheral CMPT__SRAMCTL_1 base address */
  #define CMPT__SRAMCTL_1_BASE                     (0x54090000u)
  /** Peripheral CMPT__SRAMCTL_1 base address */
  #define CMPT__SRAMCTL_1_BASE_NS                  (0x44090000u)
  /** Peripheral CMPT__SRAMCTL_1 base pointer */
  #define CMPT__SRAMCTL_1                          ((SRAMCTL_Type *)CMPT__SRAMCTL_1_BASE)
  /** Peripheral CMPT__SRAMCTL_1 base pointer */
  #define CMPT__SRAMCTL_1_NS                       ((SRAMCTL_Type *)CMPT__SRAMCTL_1_BASE_NS)
  /** Peripheral CMPT__SRAMCTL_2 base address */
  #define CMPT__SRAMCTL_2_BASE                     (0x540A0000u)
  /** Peripheral CMPT__SRAMCTL_2 base address */
  #define CMPT__SRAMCTL_2_BASE_NS                  (0x440A0000u)
  /** Peripheral CMPT__SRAMCTL_2 base pointer */
  #define CMPT__SRAMCTL_2                          ((SRAMCTL_Type *)CMPT__SRAMCTL_2_BASE)
  /** Peripheral CMPT__SRAMCTL_2 base pointer */
  #define CMPT__SRAMCTL_2_NS                       ((SRAMCTL_Type *)CMPT__SRAMCTL_2_BASE_NS)
  /** Array initializer of SRAMCTL peripheral base addresses */
  #define SRAMCTL_BASE_ADDRS                       { CMPT__SRAMCTL_0_BASE, CMPT__SRAMCTL_1_BASE, CMPT__SRAMCTL_2_BASE }
  /** Array initializer of SRAMCTL peripheral base pointers */
  #define SRAMCTL_BASE_PTRS                        { CMPT__SRAMCTL_0, CMPT__SRAMCTL_1, CMPT__SRAMCTL_2 }
  /** Array initializer of SRAMCTL peripheral base addresses */
  #define SRAMCTL_BASE_ADDRS_NS                    { CMPT__SRAMCTL_0_BASE_NS, CMPT__SRAMCTL_1_BASE_NS, CMPT__SRAMCTL_2_BASE_NS }
  /** Array initializer of SRAMCTL peripheral base pointers */
  #define SRAMCTL_BASE_PTRS_NS                     { CMPT__SRAMCTL_0_NS, CMPT__SRAMCTL_1_NS, CMPT__SRAMCTL_2_NS }
#else
  /** Peripheral CMPT__SRAMCTL_0 base address */
  #define CMPT__SRAMCTL_0_BASE                     (0x44080000u)
  /** Peripheral CMPT__SRAMCTL_0 base pointer */
  #define CMPT__SRAMCTL_0                          ((SRAMCTL_Type *)CMPT__SRAMCTL_0_BASE)
  /** Peripheral CMPT__SRAMCTL_1 base address */
  #define CMPT__SRAMCTL_1_BASE                     (0x44090000u)
  /** Peripheral CMPT__SRAMCTL_1 base pointer */
  #define CMPT__SRAMCTL_1                          ((SRAMCTL_Type *)CMPT__SRAMCTL_1_BASE)
  /** Peripheral CMPT__SRAMCTL_2 base address */
  #define CMPT__SRAMCTL_2_BASE                     (0x440A0000u)
  /** Peripheral CMPT__SRAMCTL_2 base pointer */
  #define CMPT__SRAMCTL_2                          ((SRAMCTL_Type *)CMPT__SRAMCTL_2_BASE)
  /** Array initializer of SRAMCTL peripheral base addresses */
  #define SRAMCTL_BASE_ADDRS                       { CMPT__SRAMCTL_0_BASE, CMPT__SRAMCTL_1_BASE, CMPT__SRAMCTL_2_BASE }
  /** Array initializer of SRAMCTL peripheral base pointers */
  #define SRAMCTL_BASE_PTRS                        { CMPT__SRAMCTL_0, CMPT__SRAMCTL_1, CMPT__SRAMCTL_2 }
#endif

/* STM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__STM base address */
  #define HSP__STM_BASE                            (0x529B0000u)
  /** Peripheral HSP__STM base address */
  #define HSP__STM_BASE_NS                         (0x429B0000u)
  /** Peripheral HSP__STM base pointer */
  #define HSP__STM                                 ((STM_Type *)HSP__STM_BASE)
  /** Peripheral HSP__STM base pointer */
  #define HSP__STM_NS                              ((STM_Type *)HSP__STM_BASE_NS)
  /** Array initializer of STM peripheral base addresses */
  #define STM_BASE_ADDRS                           { HSP__STM_BASE }
  /** Array initializer of STM peripheral base pointers */
  #define STM_BASE_PTRS                            { HSP__STM }
  /** Array initializer of STM peripheral base addresses */
  #define STM_BASE_ADDRS_NS                        { HSP__STM_BASE_NS }
  /** Array initializer of STM peripheral base pointers */
  #define STM_BASE_PTRS_NS                         { HSP__STM_NS }
#else
  /** Peripheral HSP__STM base address */
  #define HSP__STM_BASE                            (0x429B0000u)
  /** Peripheral HSP__STM base pointer */
  #define HSP__STM                                 ((STM_Type *)HSP__STM_BASE)
  /** Array initializer of STM peripheral base addresses */
  #define STM_BASE_ADDRS                           { HSP__STM_BASE }
  /** Array initializer of STM peripheral base pointers */
  #define STM_BASE_PTRS                            { HSP__STM }
#endif
/** Interrupt vectors for the STM peripheral type */
#define STM_IRQS                                 { HSP_STM_IRQn }

/* SWT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKE__SWT_0 base address */
  #define WAKE__SWT_0_BASE                         (0x56160000u)
  /** Peripheral WAKE__SWT_0 base address */
  #define WAKE__SWT_0_BASE_NS                      (0x46160000u)
  /** Peripheral WAKE__SWT_0 base pointer */
  #define WAKE__SWT_0                              ((SWT_Type *)WAKE__SWT_0_BASE)
  /** Peripheral WAKE__SWT_0 base pointer */
  #define WAKE__SWT_0_NS                           ((SWT_Type *)WAKE__SWT_0_BASE_NS)
  /** Peripheral WAKE__SWT_1 base address */
  #define WAKE__SWT_1_BASE                         (0x56170000u)
  /** Peripheral WAKE__SWT_1 base address */
  #define WAKE__SWT_1_BASE_NS                      (0x46170000u)
  /** Peripheral WAKE__SWT_1 base pointer */
  #define WAKE__SWT_1                              ((SWT_Type *)WAKE__SWT_1_BASE)
  /** Peripheral WAKE__SWT_1 base pointer */
  #define WAKE__SWT_1_NS                           ((SWT_Type *)WAKE__SWT_1_BASE_NS)
  /** Array initializer of SWT peripheral base addresses */
  #define SWT_BASE_ADDRS                           { WAKE__SWT_0_BASE, WAKE__SWT_1_BASE }
  /** Array initializer of SWT peripheral base pointers */
  #define SWT_BASE_PTRS                            { WAKE__SWT_0, WAKE__SWT_1 }
  /** Array initializer of SWT peripheral base addresses */
  #define SWT_BASE_ADDRS_NS                        { WAKE__SWT_0_BASE_NS, WAKE__SWT_1_BASE_NS }
  /** Array initializer of SWT peripheral base pointers */
  #define SWT_BASE_PTRS_NS                         { WAKE__SWT_0_NS, WAKE__SWT_1_NS }
#else
  /** Peripheral WAKE__SWT_0 base address */
  #define WAKE__SWT_0_BASE                         (0x46160000u)
  /** Peripheral WAKE__SWT_0 base pointer */
  #define WAKE__SWT_0                              ((SWT_Type *)WAKE__SWT_0_BASE)
  /** Peripheral WAKE__SWT_1 base address */
  #define WAKE__SWT_1_BASE                         (0x46170000u)
  /** Peripheral WAKE__SWT_1 base pointer */
  #define WAKE__SWT_1                              ((SWT_Type *)WAKE__SWT_1_BASE)
  /** Array initializer of SWT peripheral base addresses */
  #define SWT_BASE_ADDRS                           { WAKE__SWT_0_BASE, WAKE__SWT_1_BASE }
  /** Array initializer of SWT peripheral base pointers */
  #define SWT_BASE_PTRS                            { WAKE__SWT_0, WAKE__SWT_1 }
#endif
/** Interrupt vectors for the SWT peripheral type */
#define SWT_IRQS                                 { WAKE_SWT0_IRQn, WAKE_SWT1_IRQn }

/* TENBASET_PHY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral COMM__TENBASET_PHY_0 base address */
  #define COMM__TENBASET_PHY_0_BASE                (0x5A100000u)
  /** Peripheral COMM__TENBASET_PHY_0 base address */
  #define COMM__TENBASET_PHY_0_BASE_NS             (0x4A100000u)
  /** Peripheral COMM__TENBASET_PHY_0 base pointer */
  #define COMM__TENBASET_PHY_0                     ((TENBASET_PHY_Type *)COMM__TENBASET_PHY_0_BASE)
  /** Peripheral COMM__TENBASET_PHY_0 base pointer */
  #define COMM__TENBASET_PHY_0_NS                  ((TENBASET_PHY_Type *)COMM__TENBASET_PHY_0_BASE_NS)
  /** Peripheral COMM__TENBASET_PHY_1 base address */
  #define COMM__TENBASET_PHY_1_BASE                (0x5A110000u)
  /** Peripheral COMM__TENBASET_PHY_1 base address */
  #define COMM__TENBASET_PHY_1_BASE_NS             (0x4A110000u)
  /** Peripheral COMM__TENBASET_PHY_1 base pointer */
  #define COMM__TENBASET_PHY_1                     ((TENBASET_PHY_Type *)COMM__TENBASET_PHY_1_BASE)
  /** Peripheral COMM__TENBASET_PHY_1 base pointer */
  #define COMM__TENBASET_PHY_1_NS                  ((TENBASET_PHY_Type *)COMM__TENBASET_PHY_1_BASE_NS)
  /** Array initializer of TENBASET_PHY peripheral base addresses */
  #define TENBASET_PHY_BASE_ADDRS                  { COMM__TENBASET_PHY_0_BASE, COMM__TENBASET_PHY_1_BASE }
  /** Array initializer of TENBASET_PHY peripheral base pointers */
  #define TENBASET_PHY_BASE_PTRS                   { COMM__TENBASET_PHY_0, COMM__TENBASET_PHY_1 }
  /** Array initializer of TENBASET_PHY peripheral base addresses */
  #define TENBASET_PHY_BASE_ADDRS_NS               { COMM__TENBASET_PHY_0_BASE_NS, COMM__TENBASET_PHY_1_BASE_NS }
  /** Array initializer of TENBASET_PHY peripheral base pointers */
  #define TENBASET_PHY_BASE_PTRS_NS                { COMM__TENBASET_PHY_0_NS, COMM__TENBASET_PHY_1_NS }
#else
  /** Peripheral COMM__TENBASET_PHY_0 base address */
  #define COMM__TENBASET_PHY_0_BASE                (0x4A100000u)
  /** Peripheral COMM__TENBASET_PHY_0 base pointer */
  #define COMM__TENBASET_PHY_0                     ((TENBASET_PHY_Type *)COMM__TENBASET_PHY_0_BASE)
  /** Peripheral COMM__TENBASET_PHY_1 base address */
  #define COMM__TENBASET_PHY_1_BASE                (0x4A110000u)
  /** Peripheral COMM__TENBASET_PHY_1 base pointer */
  #define COMM__TENBASET_PHY_1                     ((TENBASET_PHY_Type *)COMM__TENBASET_PHY_1_BASE)
  /** Array initializer of TENBASET_PHY peripheral base addresses */
  #define TENBASET_PHY_BASE_ADDRS                  { COMM__TENBASET_PHY_0_BASE, COMM__TENBASET_PHY_1_BASE }
  /** Array initializer of TENBASET_PHY peripheral base pointers */
  #define TENBASET_PHY_BASE_PTRS                   { COMM__TENBASET_PHY_0, COMM__TENBASET_PHY_1 }
#endif

/* TINGPU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MEDIA__TINGPU base address */
  #define MEDIA__TINGPU_BASE                       (0x5C0E0000u)
  /** Peripheral MEDIA__TINGPU base address */
  #define MEDIA__TINGPU_BASE_NS                    (0x4C0E0000u)
  /** Peripheral MEDIA__TINGPU base pointer */
  #define MEDIA__TINGPU                            ((TINGPU_Type *)MEDIA__TINGPU_BASE)
  /** Peripheral MEDIA__TINGPU base pointer */
  #define MEDIA__TINGPU_NS                         ((TINGPU_Type *)MEDIA__TINGPU_BASE_NS)
  /** Array initializer of TINGPU peripheral base addresses */
  #define TINGPU_BASE_ADDRS                        { MEDIA__TINGPU_BASE }
  /** Array initializer of TINGPU peripheral base pointers */
  #define TINGPU_BASE_PTRS                         { MEDIA__TINGPU }
  /** Array initializer of TINGPU peripheral base addresses */
  #define TINGPU_BASE_ADDRS_NS                     { MEDIA__TINGPU_BASE_NS }
  /** Array initializer of TINGPU peripheral base pointers */
  #define TINGPU_BASE_PTRS_NS                      { MEDIA__TINGPU_NS }
#else
  /** Peripheral MEDIA__TINGPU base address */
  #define MEDIA__TINGPU_BASE                       (0x4C0E0000u)
  /** Peripheral MEDIA__TINGPU base pointer */
  #define MEDIA__TINGPU                            ((TINGPU_Type *)MEDIA__TINGPU_BASE)
  /** Array initializer of TINGPU peripheral base addresses */
  #define TINGPU_BASE_ADDRS                        { MEDIA__TINGPU_BASE }
  /** Array initializer of TINGPU peripheral base pointers */
  #define TINGPU_BASE_PTRS                         { MEDIA__TINGPU }
#endif

/* TMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__QTMR_0 base address */
  #define HSP__QTMR_0_BASE                         (0x521E0000u)
  /** Peripheral HSP__QTMR_0 base address */
  #define HSP__QTMR_0_BASE_NS                      (0x421E0000u)
  /** Peripheral HSP__QTMR_0 base pointer */
  #define HSP__QTMR_0                              ((TMR_Type *)HSP__QTMR_0_BASE)
  /** Peripheral HSP__QTMR_0 base pointer */
  #define HSP__QTMR_0_NS                           ((TMR_Type *)HSP__QTMR_0_BASE_NS)
  /** Peripheral HSP__QTMR_1 base address */
  #define HSP__QTMR_1_BASE                         (0x521F0000u)
  /** Peripheral HSP__QTMR_1 base address */
  #define HSP__QTMR_1_BASE_NS                      (0x421F0000u)
  /** Peripheral HSP__QTMR_1 base pointer */
  #define HSP__QTMR_1                              ((TMR_Type *)HSP__QTMR_1_BASE)
  /** Peripheral HSP__QTMR_1 base pointer */
  #define HSP__QTMR_1_NS                           ((TMR_Type *)HSP__QTMR_1_BASE_NS)
  /** Peripheral HSP__QTMR_2 base address */
  #define HSP__QTMR_2_BASE                         (0x529E0000u)
  /** Peripheral HSP__QTMR_2 base address */
  #define HSP__QTMR_2_BASE_NS                      (0x429E0000u)
  /** Peripheral HSP__QTMR_2 base pointer */
  #define HSP__QTMR_2                              ((TMR_Type *)HSP__QTMR_2_BASE)
  /** Peripheral HSP__QTMR_2 base pointer */
  #define HSP__QTMR_2_NS                           ((TMR_Type *)HSP__QTMR_2_BASE_NS)
  /** Peripheral HSP__QTMR_3 base address */
  #define HSP__QTMR_3_BASE                         (0x529F0000u)
  /** Peripheral HSP__QTMR_3 base address */
  #define HSP__QTMR_3_BASE_NS                      (0x429F0000u)
  /** Peripheral HSP__QTMR_3 base pointer */
  #define HSP__QTMR_3                              ((TMR_Type *)HSP__QTMR_3_BASE)
  /** Peripheral HSP__QTMR_3 base pointer */
  #define HSP__QTMR_3_NS                           ((TMR_Type *)HSP__QTMR_3_BASE_NS)
  /** Array initializer of TMR peripheral base addresses */
  #define TMR_BASE_ADDRS                           { HSP__QTMR_0_BASE, HSP__QTMR_1_BASE, HSP__QTMR_2_BASE, HSP__QTMR_3_BASE }
  /** Array initializer of TMR peripheral base pointers */
  #define TMR_BASE_PTRS                            { HSP__QTMR_0, HSP__QTMR_1, HSP__QTMR_2, HSP__QTMR_3 }
  /** Array initializer of TMR peripheral base addresses */
  #define TMR_BASE_ADDRS_NS                        { HSP__QTMR_0_BASE_NS, HSP__QTMR_1_BASE_NS, HSP__QTMR_2_BASE_NS, HSP__QTMR_3_BASE_NS }
  /** Array initializer of TMR peripheral base pointers */
  #define TMR_BASE_PTRS_NS                         { HSP__QTMR_0_NS, HSP__QTMR_1_NS, HSP__QTMR_2_NS, HSP__QTMR_3_NS }
#else
  /** Peripheral HSP__QTMR_0 base address */
  #define HSP__QTMR_0_BASE                         (0x421E0000u)
  /** Peripheral HSP__QTMR_0 base pointer */
  #define HSP__QTMR_0                              ((TMR_Type *)HSP__QTMR_0_BASE)
  /** Peripheral HSP__QTMR_1 base address */
  #define HSP__QTMR_1_BASE                         (0x421F0000u)
  /** Peripheral HSP__QTMR_1 base pointer */
  #define HSP__QTMR_1                              ((TMR_Type *)HSP__QTMR_1_BASE)
  /** Peripheral HSP__QTMR_2 base address */
  #define HSP__QTMR_2_BASE                         (0x429E0000u)
  /** Peripheral HSP__QTMR_2 base pointer */
  #define HSP__QTMR_2                              ((TMR_Type *)HSP__QTMR_2_BASE)
  /** Peripheral HSP__QTMR_3 base address */
  #define HSP__QTMR_3_BASE                         (0x429F0000u)
  /** Peripheral HSP__QTMR_3 base pointer */
  #define HSP__QTMR_3                              ((TMR_Type *)HSP__QTMR_3_BASE)
  /** Array initializer of TMR peripheral base addresses */
  #define TMR_BASE_ADDRS                           { HSP__QTMR_0_BASE, HSP__QTMR_1_BASE, HSP__QTMR_2_BASE, HSP__QTMR_3_BASE }
  /** Array initializer of TMR peripheral base pointers */
  #define TMR_BASE_PTRS                            { HSP__QTMR_0, HSP__QTMR_1, HSP__QTMR_2, HSP__QTMR_3 }
#endif
/** Interrupt vectors for the TMR peripheral type */
#define TMR_IRQS                                 { HSP_QTMR0_IRQn, HSP_QTMR1_IRQn, HSP_QTMR2_IRQn, HSP_QTMR3_IRQn }

/* TPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__TPM_0 base address */
  #define HSP__TPM_0_BASE                          (0x520A0000u)
  /** Peripheral HSP__TPM_0 base address */
  #define HSP__TPM_0_BASE_NS                       (0x420A0000u)
  /** Peripheral HSP__TPM_0 base pointer */
  #define HSP__TPM_0                               ((TPM_Type *)HSP__TPM_0_BASE)
  /** Peripheral HSP__TPM_0 base pointer */
  #define HSP__TPM_0_NS                            ((TPM_Type *)HSP__TPM_0_BASE_NS)
  /** Peripheral HSP__TPM_1 base address */
  #define HSP__TPM_1_BASE                          (0x520A4000u)
  /** Peripheral HSP__TPM_1 base address */
  #define HSP__TPM_1_BASE_NS                       (0x420A4000u)
  /** Peripheral HSP__TPM_1 base pointer */
  #define HSP__TPM_1                               ((TPM_Type *)HSP__TPM_1_BASE)
  /** Peripheral HSP__TPM_1 base pointer */
  #define HSP__TPM_1_NS                            ((TPM_Type *)HSP__TPM_1_BASE_NS)
  /** Peripheral HSP__TPM_2 base address */
  #define HSP__TPM_2_BASE                          (0x520A8000u)
  /** Peripheral HSP__TPM_2 base address */
  #define HSP__TPM_2_BASE_NS                       (0x420A8000u)
  /** Peripheral HSP__TPM_2 base pointer */
  #define HSP__TPM_2                               ((TPM_Type *)HSP__TPM_2_BASE)
  /** Peripheral HSP__TPM_2 base pointer */
  #define HSP__TPM_2_NS                            ((TPM_Type *)HSP__TPM_2_BASE_NS)
  /** Peripheral HSP__TPM_3 base address */
  #define HSP__TPM_3_BASE                          (0x520AC000u)
  /** Peripheral HSP__TPM_3 base address */
  #define HSP__TPM_3_BASE_NS                       (0x420AC000u)
  /** Peripheral HSP__TPM_3 base pointer */
  #define HSP__TPM_3                               ((TPM_Type *)HSP__TPM_3_BASE)
  /** Peripheral HSP__TPM_3 base pointer */
  #define HSP__TPM_3_NS                            ((TPM_Type *)HSP__TPM_3_BASE_NS)
  /** Peripheral WAKE__TPM_0 base address */
  #define WAKE__TPM_0_BASE                         (0x56150000u)
  /** Peripheral WAKE__TPM_0 base address */
  #define WAKE__TPM_0_BASE_NS                      (0x46150000u)
  /** Peripheral WAKE__TPM_0 base pointer */
  #define WAKE__TPM_0                              ((TPM_Type *)WAKE__TPM_0_BASE)
  /** Peripheral WAKE__TPM_0 base pointer */
  #define WAKE__TPM_0_NS                           ((TPM_Type *)WAKE__TPM_0_BASE_NS)
  /** Peripheral WAKE__TPM_1 base address */
  #define WAKE__TPM_1_BASE                         (0x56154000u)
  /** Peripheral WAKE__TPM_1 base address */
  #define WAKE__TPM_1_BASE_NS                      (0x46154000u)
  /** Peripheral WAKE__TPM_1 base pointer */
  #define WAKE__TPM_1                              ((TPM_Type *)WAKE__TPM_1_BASE)
  /** Peripheral WAKE__TPM_1 base pointer */
  #define WAKE__TPM_1_NS                           ((TPM_Type *)WAKE__TPM_1_BASE_NS)
  /** Peripheral WAKE__TPM_2 base address */
  #define WAKE__TPM_2_BASE                         (0x56158000u)
  /** Peripheral WAKE__TPM_2 base address */
  #define WAKE__TPM_2_BASE_NS                      (0x46158000u)
  /** Peripheral WAKE__TPM_2 base pointer */
  #define WAKE__TPM_2                              ((TPM_Type *)WAKE__TPM_2_BASE)
  /** Peripheral WAKE__TPM_2 base pointer */
  #define WAKE__TPM_2_NS                           ((TPM_Type *)WAKE__TPM_2_BASE_NS)
  /** Peripheral WAKE__TPM_3 base address */
  #define WAKE__TPM_3_BASE                         (0x5615C000u)
  /** Peripheral WAKE__TPM_3 base address */
  #define WAKE__TPM_3_BASE_NS                      (0x4615C000u)
  /** Peripheral WAKE__TPM_3 base pointer */
  #define WAKE__TPM_3                              ((TPM_Type *)WAKE__TPM_3_BASE)
  /** Peripheral WAKE__TPM_3 base pointer */
  #define WAKE__TPM_3_NS                           ((TPM_Type *)WAKE__TPM_3_BASE_NS)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { HSP__TPM_0_BASE, HSP__TPM_1_BASE, HSP__TPM_2_BASE, HSP__TPM_3_BASE, WAKE__TPM_0_BASE, WAKE__TPM_1_BASE, WAKE__TPM_2_BASE, WAKE__TPM_3_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { HSP__TPM_0, HSP__TPM_1, HSP__TPM_2, HSP__TPM_3, WAKE__TPM_0, WAKE__TPM_1, WAKE__TPM_2, WAKE__TPM_3 }
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS_NS                        { HSP__TPM_0_BASE_NS, HSP__TPM_1_BASE_NS, HSP__TPM_2_BASE_NS, HSP__TPM_3_BASE_NS, WAKE__TPM_0_BASE_NS, WAKE__TPM_1_BASE_NS, WAKE__TPM_2_BASE_NS, WAKE__TPM_3_BASE_NS }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS_NS                         { HSP__TPM_0_NS, HSP__TPM_1_NS, HSP__TPM_2_NS, HSP__TPM_3_NS, WAKE__TPM_0_NS, WAKE__TPM_1_NS, WAKE__TPM_2_NS, WAKE__TPM_3_NS }
#else
  /** Peripheral HSP__TPM_0 base address */
  #define HSP__TPM_0_BASE                          (0x420A0000u)
  /** Peripheral HSP__TPM_0 base pointer */
  #define HSP__TPM_0                               ((TPM_Type *)HSP__TPM_0_BASE)
  /** Peripheral HSP__TPM_1 base address */
  #define HSP__TPM_1_BASE                          (0x420A4000u)
  /** Peripheral HSP__TPM_1 base pointer */
  #define HSP__TPM_1                               ((TPM_Type *)HSP__TPM_1_BASE)
  /** Peripheral HSP__TPM_2 base address */
  #define HSP__TPM_2_BASE                          (0x420A8000u)
  /** Peripheral HSP__TPM_2 base pointer */
  #define HSP__TPM_2                               ((TPM_Type *)HSP__TPM_2_BASE)
  /** Peripheral HSP__TPM_3 base address */
  #define HSP__TPM_3_BASE                          (0x420AC000u)
  /** Peripheral HSP__TPM_3 base pointer */
  #define HSP__TPM_3                               ((TPM_Type *)HSP__TPM_3_BASE)
  /** Peripheral WAKE__TPM_0 base address */
  #define WAKE__TPM_0_BASE                         (0x46150000u)
  /** Peripheral WAKE__TPM_0 base pointer */
  #define WAKE__TPM_0                              ((TPM_Type *)WAKE__TPM_0_BASE)
  /** Peripheral WAKE__TPM_1 base address */
  #define WAKE__TPM_1_BASE                         (0x46154000u)
  /** Peripheral WAKE__TPM_1 base pointer */
  #define WAKE__TPM_1                              ((TPM_Type *)WAKE__TPM_1_BASE)
  /** Peripheral WAKE__TPM_2 base address */
  #define WAKE__TPM_2_BASE                         (0x46158000u)
  /** Peripheral WAKE__TPM_2 base pointer */
  #define WAKE__TPM_2                              ((TPM_Type *)WAKE__TPM_2_BASE)
  /** Peripheral WAKE__TPM_3 base address */
  #define WAKE__TPM_3_BASE                         (0x4615C000u)
  /** Peripheral WAKE__TPM_3 base pointer */
  #define WAKE__TPM_3                              ((TPM_Type *)WAKE__TPM_3_BASE)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { HSP__TPM_0_BASE, HSP__TPM_1_BASE, HSP__TPM_2_BASE, HSP__TPM_3_BASE, WAKE__TPM_0_BASE, WAKE__TPM_1_BASE, WAKE__TPM_2_BASE, WAKE__TPM_3_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { HSP__TPM_0, HSP__TPM_1, HSP__TPM_2, HSP__TPM_3, WAKE__TPM_0, WAKE__TPM_1, WAKE__TPM_2, WAKE__TPM_3 }
#endif
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { HSP_QTPM0_IRQn, HSP_QTPM1_IRQn, HSP_QTPM2_IRQn, HSP_QTPM3_IRQn, WAKE_QTPM0_IRQn, WAKE_QTPM1_IRQn, WAKE_QTPM2_IRQn, WAKE_QTPM3_IRQn }

/* TRDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO__TRDC base address */
  #define AUDIO__TRDC_BASE                         (0x58040000u)
  /** Peripheral AUDIO__TRDC base address */
  #define AUDIO__TRDC_BASE_NS                      (0x48040000u)
  /** Peripheral AUDIO__TRDC base pointer */
  #define AUDIO__TRDC                              ((TRDC_Type *)AUDIO__TRDC_BASE)
  /** Peripheral AUDIO__TRDC base pointer */
  #define AUDIO__TRDC_NS                           ((TRDC_Type *)AUDIO__TRDC_BASE_NS)
  /** Peripheral COMM__TRDC base address */
  #define COMM__TRDC_BASE                          (0x5A040000u)
  /** Peripheral COMM__TRDC base address */
  #define COMM__TRDC_BASE_NS                       (0x4A040000u)
  /** Peripheral COMM__TRDC base pointer */
  #define COMM__TRDC                               ((TRDC_Type *)COMM__TRDC_BASE)
  /** Peripheral COMM__TRDC base pointer */
  #define COMM__TRDC_NS                            ((TRDC_Type *)COMM__TRDC_BASE_NS)
  /** Peripheral MAIN__TRDC base address */
  #define MAIN__TRDC_BASE                          (0x50040000u)
  /** Peripheral MAIN__TRDC base address */
  #define MAIN__TRDC_BASE_NS                       (0x40040000u)
  /** Peripheral MAIN__TRDC base pointer */
  #define MAIN__TRDC                               ((TRDC_Type *)MAIN__TRDC_BASE)
  /** Peripheral MAIN__TRDC base pointer */
  #define MAIN__TRDC_NS                            ((TRDC_Type *)MAIN__TRDC_BASE_NS)
  /** Peripheral MEDIA__TRDC base address */
  #define MEDIA__TRDC_BASE                         (0x5C040000u)
  /** Peripheral MEDIA__TRDC base address */
  #define MEDIA__TRDC_BASE_NS                      (0x4C040000u)
  /** Peripheral MEDIA__TRDC base pointer */
  #define MEDIA__TRDC                              ((TRDC_Type *)MEDIA__TRDC_BASE)
  /** Peripheral MEDIA__TRDC base pointer */
  #define MEDIA__TRDC_NS                           ((TRDC_Type *)MEDIA__TRDC_BASE_NS)
  /** Peripheral WAKE__TRDC base address */
  #define WAKE__TRDC_BASE                          (0x56040000u)
  /** Peripheral WAKE__TRDC base address */
  #define WAKE__TRDC_BASE_NS                       (0x46040000u)
  /** Peripheral WAKE__TRDC base pointer */
  #define WAKE__TRDC                               ((TRDC_Type *)WAKE__TRDC_BASE)
  /** Peripheral WAKE__TRDC base pointer */
  #define WAKE__TRDC_NS                            ((TRDC_Type *)WAKE__TRDC_BASE_NS)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { AUDIO__TRDC_BASE, COMM__TRDC_BASE, MAIN__TRDC_BASE, MEDIA__TRDC_BASE, WAKE__TRDC_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { AUDIO__TRDC, COMM__TRDC, MAIN__TRDC, MEDIA__TRDC, WAKE__TRDC }
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS_NS                       { AUDIO__TRDC_BASE_NS, COMM__TRDC_BASE_NS, MAIN__TRDC_BASE_NS, MEDIA__TRDC_BASE_NS, WAKE__TRDC_BASE_NS }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS_NS                        { AUDIO__TRDC_NS, COMM__TRDC_NS, MAIN__TRDC_NS, MEDIA__TRDC_NS, WAKE__TRDC_NS }
#else
  /** Peripheral AUDIO__TRDC base address */
  #define AUDIO__TRDC_BASE                         (0x48040000u)
  /** Peripheral AUDIO__TRDC base pointer */
  #define AUDIO__TRDC                              ((TRDC_Type *)AUDIO__TRDC_BASE)
  /** Peripheral COMM__TRDC base address */
  #define COMM__TRDC_BASE                          (0x4A040000u)
  /** Peripheral COMM__TRDC base pointer */
  #define COMM__TRDC                               ((TRDC_Type *)COMM__TRDC_BASE)
  /** Peripheral MAIN__TRDC base address */
  #define MAIN__TRDC_BASE                          (0x40040000u)
  /** Peripheral MAIN__TRDC base pointer */
  #define MAIN__TRDC                               ((TRDC_Type *)MAIN__TRDC_BASE)
  /** Peripheral MEDIA__TRDC base address */
  #define MEDIA__TRDC_BASE                         (0x4C040000u)
  /** Peripheral MEDIA__TRDC base pointer */
  #define MEDIA__TRDC                              ((TRDC_Type *)MEDIA__TRDC_BASE)
  /** Peripheral WAKE__TRDC base address */
  #define WAKE__TRDC_BASE                          (0x46040000u)
  /** Peripheral WAKE__TRDC base pointer */
  #define WAKE__TRDC                               ((TRDC_Type *)WAKE__TRDC_BASE)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { AUDIO__TRDC_BASE, COMM__TRDC_BASE, MAIN__TRDC_BASE, MEDIA__TRDC_BASE, WAKE__TRDC_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { AUDIO__TRDC, COMM__TRDC, MAIN__TRDC, MEDIA__TRDC, WAKE__TRDC }
#endif
/** Interrupt vectors for the TRDC peripheral type */
#define TRDC_IRQS                                { AUDIO_TRDC_IRQn, COMM_TRDC_IRQn, MAIN_TRDC_IRQn, MEDIA_TRDC_IRQn, WAKE_TRDC_IRQn }

/* TRDC_CMPT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CMPT__TRDC base address */
  #define CMPT__TRDC_BASE                          (0x54040000u)
  /** Peripheral CMPT__TRDC base address */
  #define CMPT__TRDC_BASE_NS                       (0x44040000u)
  /** Peripheral CMPT__TRDC base pointer */
  #define CMPT__TRDC                               ((TRDC_CMPT_Type *)CMPT__TRDC_BASE)
  /** Peripheral CMPT__TRDC base pointer */
  #define CMPT__TRDC_NS                            ((TRDC_CMPT_Type *)CMPT__TRDC_BASE_NS)
  /** Array initializer of TRDC_CMPT peripheral base addresses */
  #define TRDC_CMPT_BASE_ADDRS                     { CMPT__TRDC_BASE }
  /** Array initializer of TRDC_CMPT peripheral base pointers */
  #define TRDC_CMPT_BASE_PTRS                      { CMPT__TRDC }
  /** Array initializer of TRDC_CMPT peripheral base addresses */
  #define TRDC_CMPT_BASE_ADDRS_NS                  { CMPT__TRDC_BASE_NS }
  /** Array initializer of TRDC_CMPT peripheral base pointers */
  #define TRDC_CMPT_BASE_PTRS_NS                   { CMPT__TRDC_NS }
#else
  /** Peripheral CMPT__TRDC base address */
  #define CMPT__TRDC_BASE                          (0x44040000u)
  /** Peripheral CMPT__TRDC base pointer */
  #define CMPT__TRDC                               ((TRDC_CMPT_Type *)CMPT__TRDC_BASE)
  /** Array initializer of TRDC_CMPT peripheral base addresses */
  #define TRDC_CMPT_BASE_ADDRS                     { CMPT__TRDC_BASE }
  /** Array initializer of TRDC_CMPT peripheral base pointers */
  #define TRDC_CMPT_BASE_PTRS                      { CMPT__TRDC }
#endif

/* TRGSYNC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__TRGSYNC_0 base address */
  #define HSP__TRGSYNC_0_BASE                      (0x52990000u)
  /** Peripheral HSP__TRGSYNC_0 base address */
  #define HSP__TRGSYNC_0_BASE_NS                   (0x42990000u)
  /** Peripheral HSP__TRGSYNC_0 base pointer */
  #define HSP__TRGSYNC_0                           ((TRGSYNC_Type *)HSP__TRGSYNC_0_BASE)
  /** Peripheral HSP__TRGSYNC_0 base pointer */
  #define HSP__TRGSYNC_0_NS                        ((TRGSYNC_Type *)HSP__TRGSYNC_0_BASE_NS)
  /** Peripheral HSP__TRGSYNC_1 base address */
  #define HSP__TRGSYNC_1_BASE                      (0x529A0000u)
  /** Peripheral HSP__TRGSYNC_1 base address */
  #define HSP__TRGSYNC_1_BASE_NS                   (0x429A0000u)
  /** Peripheral HSP__TRGSYNC_1 base pointer */
  #define HSP__TRGSYNC_1                           ((TRGSYNC_Type *)HSP__TRGSYNC_1_BASE)
  /** Peripheral HSP__TRGSYNC_1 base pointer */
  #define HSP__TRGSYNC_1_NS                        ((TRGSYNC_Type *)HSP__TRGSYNC_1_BASE_NS)
  /** Peripheral WAKE__TRGSYNC base address */
  #define WAKE__TRGSYNC_BASE                       (0x560C0000u)
  /** Peripheral WAKE__TRGSYNC base address */
  #define WAKE__TRGSYNC_BASE_NS                    (0x460C0000u)
  /** Peripheral WAKE__TRGSYNC base pointer */
  #define WAKE__TRGSYNC                            ((TRGSYNC_Type *)WAKE__TRGSYNC_BASE)
  /** Peripheral WAKE__TRGSYNC base pointer */
  #define WAKE__TRGSYNC_NS                         ((TRGSYNC_Type *)WAKE__TRGSYNC_BASE_NS)
  /** Array initializer of TRGSYNC peripheral base addresses */
  #define TRGSYNC_BASE_ADDRS                       { HSP__TRGSYNC_0_BASE, HSP__TRGSYNC_1_BASE, WAKE__TRGSYNC_BASE }
  /** Array initializer of TRGSYNC peripheral base pointers */
  #define TRGSYNC_BASE_PTRS                        { HSP__TRGSYNC_0, HSP__TRGSYNC_1, WAKE__TRGSYNC }
  /** Array initializer of TRGSYNC peripheral base addresses */
  #define TRGSYNC_BASE_ADDRS_NS                    { HSP__TRGSYNC_0_BASE_NS, HSP__TRGSYNC_1_BASE_NS, WAKE__TRGSYNC_BASE_NS }
  /** Array initializer of TRGSYNC peripheral base pointers */
  #define TRGSYNC_BASE_PTRS_NS                     { HSP__TRGSYNC_0_NS, HSP__TRGSYNC_1_NS, WAKE__TRGSYNC_NS }
#else
  /** Peripheral HSP__TRGSYNC_0 base address */
  #define HSP__TRGSYNC_0_BASE                      (0x42990000u)
  /** Peripheral HSP__TRGSYNC_0 base pointer */
  #define HSP__TRGSYNC_0                           ((TRGSYNC_Type *)HSP__TRGSYNC_0_BASE)
  /** Peripheral HSP__TRGSYNC_1 base address */
  #define HSP__TRGSYNC_1_BASE                      (0x429A0000u)
  /** Peripheral HSP__TRGSYNC_1 base pointer */
  #define HSP__TRGSYNC_1                           ((TRGSYNC_Type *)HSP__TRGSYNC_1_BASE)
  /** Peripheral WAKE__TRGSYNC base address */
  #define WAKE__TRGSYNC_BASE                       (0x460C0000u)
  /** Peripheral WAKE__TRGSYNC base pointer */
  #define WAKE__TRGSYNC                            ((TRGSYNC_Type *)WAKE__TRGSYNC_BASE)
  /** Array initializer of TRGSYNC peripheral base addresses */
  #define TRGSYNC_BASE_ADDRS                       { HSP__TRGSYNC_0_BASE, HSP__TRGSYNC_1_BASE, WAKE__TRGSYNC_BASE }
  /** Array initializer of TRGSYNC peripheral base pointers */
  #define TRGSYNC_BASE_PTRS                        { HSP__TRGSYNC_0, HSP__TRGSYNC_1, WAKE__TRGSYNC }
#endif

/* USB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral COMM__USBFS base address */
  #define COMM__USBFS_BASE                         (0x5A0B0000u)
  /** Peripheral COMM__USBFS base address */
  #define COMM__USBFS_BASE_NS                      (0x4A0B0000u)
  /** Peripheral COMM__USBFS base pointer */
  #define COMM__USBFS                              ((USB_Type *)COMM__USBFS_BASE)
  /** Peripheral COMM__USBFS base pointer */
  #define COMM__USBFS_NS                           ((USB_Type *)COMM__USBFS_BASE_NS)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { COMM__USBFS_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { COMM__USBFS }
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS_NS                        { COMM__USBFS_BASE_NS }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS_NS                         { COMM__USBFS_NS }
#else
  /** Peripheral COMM__USBFS base address */
  #define COMM__USBFS_BASE                         (0x4A0B0000u)
  /** Peripheral COMM__USBFS base pointer */
  #define COMM__USBFS                              ((USB_Type *)COMM__USBFS_BASE)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { COMM__USBFS_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { COMM__USBFS }
#endif
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { COMM_USB1_IRQn }
/* Backward compatibility */
#define USBFS_IRQS                               USB_IRQS
#define USBFS_IRQHandler                         COMM_USB1_IRQHandler


/* USBHS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral COMM__USBC base address */
  #define COMM__USBC_BASE                          (0x5A0A0000u)
  /** Peripheral COMM__USBC base address */
  #define COMM__USBC_BASE_NS                       (0x4A0A0000u)
  /** Peripheral COMM__USBC base pointer */
  #define COMM__USBC                               ((USBHS_Type *)COMM__USBC_BASE)
  /** Peripheral COMM__USBC base pointer */
  #define COMM__USBC_NS                            ((USBHS_Type *)COMM__USBC_BASE_NS)
  /** Array initializer of USBHS peripheral base addresses */
  #define USBHS_BASE_ADDRS                         { COMM__USBC_BASE }
  /** Array initializer of USBHS peripheral base pointers */
  #define USBHS_BASE_PTRS                          { COMM__USBC }
  /** Array initializer of USBHS peripheral base addresses */
  #define USBHS_BASE_ADDRS_NS                      { COMM__USBC_BASE_NS }
  /** Array initializer of USBHS peripheral base pointers */
  #define USBHS_BASE_PTRS_NS                       { COMM__USBC_NS }
#else
  /** Peripheral COMM__USBC base address */
  #define COMM__USBC_BASE                          (0x4A0A0000u)
  /** Peripheral COMM__USBC base pointer */
  #define COMM__USBC                               ((USBHS_Type *)COMM__USBC_BASE)
  /** Array initializer of USBHS peripheral base addresses */
  #define USBHS_BASE_ADDRS                         { COMM__USBC_BASE }
  /** Array initializer of USBHS peripheral base pointers */
  #define USBHS_BASE_PTRS                          { COMM__USBC }
#endif
/** Interrupt vectors for the USBHS peripheral type */
#define USBHS_IRQS                               { COMM_USB0_IRQn }

/* USBHSDCD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral COMM__USBDCD base address */
  #define COMM__USBDCD_BASE                        (0x5A0F0800u)
  /** Peripheral COMM__USBDCD base address */
  #define COMM__USBDCD_BASE_NS                     (0x4A0F0800u)
  /** Peripheral COMM__USBDCD base pointer */
  #define COMM__USBDCD                             ((USBHSDCD_Type *)COMM__USBDCD_BASE)
  /** Peripheral COMM__USBDCD base pointer */
  #define COMM__USBDCD_NS                          ((USBHSDCD_Type *)COMM__USBDCD_BASE_NS)
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS                      { COMM__USBDCD_BASE }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS                       { COMM__USBDCD }
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS_NS                   { COMM__USBDCD_BASE_NS }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS_NS                    { COMM__USBDCD_NS }
#else
  /** Peripheral COMM__USBDCD base address */
  #define COMM__USBDCD_BASE                        (0x4A0F0800u)
  /** Peripheral COMM__USBDCD base pointer */
  #define COMM__USBDCD                             ((USBHSDCD_Type *)COMM__USBDCD_BASE)
  /** Array initializer of USBHSDCD peripheral base addresses */
  #define USBHSDCD_BASE_ADDRS                      { COMM__USBDCD_BASE }
  /** Array initializer of USBHSDCD peripheral base pointers */
  #define USBHSDCD_BASE_PTRS                       { COMM__USBDCD }
#endif
/* Backward compatibility */
#define USBHSDCD_IRQS                              USBPHY_IRQS
#define USBHSDCD_STACK_BASE_ADDRS                  { COMM__USBDCD_BASE }


/* USBNC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral COMM__USBNC base address */
  #define COMM__USBNC_BASE                         (0x5A0A0200u)
  /** Peripheral COMM__USBNC base address */
  #define COMM__USBNC_BASE_NS                      (0x4A0A0200u)
  /** Peripheral COMM__USBNC base pointer */
  #define COMM__USBNC                              ((USBNC_Type *)COMM__USBNC_BASE)
  /** Peripheral COMM__USBNC base pointer */
  #define COMM__USBNC_NS                           ((USBNC_Type *)COMM__USBNC_BASE_NS)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { COMM__USBNC_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { COMM__USBNC }
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS_NS                      { COMM__USBNC_BASE_NS }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS_NS                       { COMM__USBNC_NS }
#else
  /** Peripheral COMM__USBNC base address */
  #define COMM__USBNC_BASE                         (0x4A0A0200u)
  /** Peripheral COMM__USBNC base pointer */
  #define COMM__USBNC                              ((USBNC_Type *)COMM__USBNC_BASE)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { COMM__USBNC_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { COMM__USBNC }
#endif
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
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN_MASK     USBNC_CTRL1_REMOTE_WAKEUP_EN_MASK
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN_SHIFT     USBNC_CTRL1_REMOTE_WAKEUP_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_REMOTE_WAKEUP_EN(x)     USBNC_CTRL1_REMOTE_WAKEUP_EN(x)
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_MASK     USBNC_CTRL1_WKUP_DPDM_EN_MASK
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_SHIFT     USBNC_CTRL1_WKUP_DPDM_EN_SHIFT
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN(x)     USBNC_CTRL1_WKUP_DPDM_EN(x)
#define USBNC_USB_OTGn_CTRL_WIR_MASK     USBNC_CTRL1_WIR_MASK
#define USBNC_USB_OTGn_CTRL_WIR_SHIFT     USBNC_CTRL1_WIR_SHIFT
#define USBNC_USB_OTGn_CTRL_WIR(x)     USBNC_CTRL1_WIR(x)
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
#define USBNC_STACK_BASE_ADDRS                { COMM__USBNC_BASE }
#define USBNC_STACK_BASE_ADDRS_NS             { COMM__USBNC_BASE_NS }
#else
#define USBNC_STACK_BASE_ADDRS                { COMM__USBNC_BASE }
#endif


/* USBPHY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral COMM__USBPHY base address */
  #define COMM__USBPHY_BASE                        (0x5A0F0000u)
  /** Peripheral COMM__USBPHY base address */
  #define COMM__USBPHY_BASE_NS                     (0x4A0F0000u)
  /** Peripheral COMM__USBPHY base pointer */
  #define COMM__USBPHY                             ((USBPHY_Type *)COMM__USBPHY_BASE)
  /** Peripheral COMM__USBPHY base pointer */
  #define COMM__USBPHY_NS                          ((USBPHY_Type *)COMM__USBPHY_BASE_NS)
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS                        { COMM__USBPHY_BASE }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS                         { COMM__USBPHY }
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS_NS                     { COMM__USBPHY_BASE_NS }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS_NS                      { COMM__USBPHY_NS }
#else
  /** Peripheral COMM__USBPHY base address */
  #define COMM__USBPHY_BASE                        (0x4A0F0000u)
  /** Peripheral COMM__USBPHY base pointer */
  #define COMM__USBPHY                             ((USBPHY_Type *)COMM__USBPHY_BASE)
  /** Array initializer of USBPHY peripheral base addresses */
  #define USBPHY_BASE_ADDRS                        { COMM__USBPHY_BASE }
  /** Array initializer of USBPHY peripheral base pointers */
  #define USBPHY_BASE_PTRS                         { COMM__USBPHY }
#endif
/** Interrupt vectors for the USBPHY peripheral type */
#define USBPHY_IRQS                              { COMM_USBPHY_IRQn }
/* Backward compatibility */
#define USBPHY_TX_TXCAL45DM_MASK            USBPHY_TX_TXCAL45DN_MASK
#define USBPHY_TX_TXCAL45DM_SHIFT           USBPHY_TX_TXCAL45DN_SHIFT
#define USBPHY_TX_TXCAL45DM(x)              USBPHY_TX_TXCAL45DN(x)
#define USBPHY_IRQHandler                   COMM_USBPHY_IRQHandler

#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
#define USBPHY_STACK_BASE_ADDRS             { COMM__USBPHY_BASE }
#define USBPHY_STACK_BASE_ADDRS_NS          { COMM__USBPHY_BASE_NS }
#else
#define USBPHY_STACK_BASE_ADDRS             { COMM__USBPHY_BASE }
#endif


/* USDHC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral COMM__USDHC_0 base address */
  #define COMM__USDHC_0_BASE                       (0x5A080000u)
  /** Peripheral COMM__USDHC_0 base address */
  #define COMM__USDHC_0_BASE_NS                    (0x4A080000u)
  /** Peripheral COMM__USDHC_0 base pointer */
  #define COMM__USDHC_0                            ((USDHC_Type *)COMM__USDHC_0_BASE)
  /** Peripheral COMM__USDHC_0 base pointer */
  #define COMM__USDHC_0_NS                         ((USDHC_Type *)COMM__USDHC_0_BASE_NS)
  /** Peripheral COMM__USDHC_1 base address */
  #define COMM__USDHC_1_BASE                       (0x5A090000u)
  /** Peripheral COMM__USDHC_1 base address */
  #define COMM__USDHC_1_BASE_NS                    (0x4A090000u)
  /** Peripheral COMM__USDHC_1 base pointer */
  #define COMM__USDHC_1                            ((USDHC_Type *)COMM__USDHC_1_BASE)
  /** Peripheral COMM__USDHC_1 base pointer */
  #define COMM__USDHC_1_NS                         ((USDHC_Type *)COMM__USDHC_1_BASE_NS)
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS                         { COMM__USDHC_0_BASE, COMM__USDHC_1_BASE }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS                          { COMM__USDHC_0, COMM__USDHC_1 }
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS_NS                      { COMM__USDHC_0_BASE_NS, COMM__USDHC_1_BASE_NS }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS_NS                       { COMM__USDHC_0_NS, COMM__USDHC_1_NS }
#else
  /** Peripheral COMM__USDHC_0 base address */
  #define COMM__USDHC_0_BASE                       (0x4A080000u)
  /** Peripheral COMM__USDHC_0 base pointer */
  #define COMM__USDHC_0                            ((USDHC_Type *)COMM__USDHC_0_BASE)
  /** Peripheral COMM__USDHC_1 base address */
  #define COMM__USDHC_1_BASE                       (0x4A090000u)
  /** Peripheral COMM__USDHC_1 base pointer */
  #define COMM__USDHC_1                            ((USDHC_Type *)COMM__USDHC_1_BASE)
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS                         { COMM__USDHC_0_BASE, COMM__USDHC_1_BASE }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS                          { COMM__USDHC_0, COMM__USDHC_1 }
#endif
/** Interrupt vectors for the USDHC peripheral type */
#define USDHC_IRQS                               { COMM_USDHC0_IRQn, COMM_USDHC1_IRQn }

/* VBATCON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VBAT__VBATCON base address */
  #define VBAT__VBATCON_BASE                       (0x56370000u)
  /** Peripheral VBAT__VBATCON base address */
  #define VBAT__VBATCON_BASE_NS                    (0x46370000u)
  /** Peripheral VBAT__VBATCON base pointer */
  #define VBAT__VBATCON                            ((VBATCON_Type *)VBAT__VBATCON_BASE)
  /** Peripheral VBAT__VBATCON base pointer */
  #define VBAT__VBATCON_NS                         ((VBATCON_Type *)VBAT__VBATCON_BASE_NS)
  /** Array initializer of VBATCON peripheral base addresses */
  #define VBATCON_BASE_ADDRS                       { VBAT__VBATCON_BASE }
  /** Array initializer of VBATCON peripheral base pointers */
  #define VBATCON_BASE_PTRS                        { VBAT__VBATCON }
  /** Array initializer of VBATCON peripheral base addresses */
  #define VBATCON_BASE_ADDRS_NS                    { VBAT__VBATCON_BASE_NS }
  /** Array initializer of VBATCON peripheral base pointers */
  #define VBATCON_BASE_PTRS_NS                     { VBAT__VBATCON_NS }
#else
  /** Peripheral VBAT__VBATCON base address */
  #define VBAT__VBATCON_BASE                       (0x46370000u)
  /** Peripheral VBAT__VBATCON base pointer */
  #define VBAT__VBATCON                            ((VBATCON_Type *)VBAT__VBATCON_BASE)
  /** Array initializer of VBATCON peripheral base addresses */
  #define VBATCON_BASE_ADDRS                       { VBAT__VBATCON_BASE }
  /** Array initializer of VBATCON peripheral base pointers */
  #define VBATCON_BASE_PTRS                        { VBAT__VBATCON }
#endif

/* XBAR0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AUDIO__XBAR base address */
  #define AUDIO__XBAR_BASE                         (0x58160000u)
  /** Peripheral AUDIO__XBAR base address */
  #define AUDIO__XBAR_BASE_NS                      (0x48160000u)
  /** Peripheral AUDIO__XBAR base pointer */
  #define AUDIO__XBAR                              ((XBAR0_Type *)AUDIO__XBAR_BASE)
  /** Peripheral AUDIO__XBAR base pointer */
  #define AUDIO__XBAR_NS                           ((XBAR0_Type *)AUDIO__XBAR_BASE_NS)
  /** Array initializer of XBAR0 peripheral base addresses */
  #define XBAR0_BASE_ADDRS                         { AUDIO__XBAR_BASE }
  /** Array initializer of XBAR0 peripheral base pointers */
  #define XBAR0_BASE_PTRS                          { AUDIO__XBAR }
  /** Array initializer of XBAR0 peripheral base addresses */
  #define XBAR0_BASE_ADDRS_NS                      { AUDIO__XBAR_BASE_NS }
  /** Array initializer of XBAR0 peripheral base pointers */
  #define XBAR0_BASE_PTRS_NS                       { AUDIO__XBAR_NS }
#else
  /** Peripheral AUDIO__XBAR base address */
  #define AUDIO__XBAR_BASE                         (0x48160000u)
  /** Peripheral AUDIO__XBAR base pointer */
  #define AUDIO__XBAR                              ((XBAR0_Type *)AUDIO__XBAR_BASE)
  /** Array initializer of XBAR0 peripheral base addresses */
  #define XBAR0_BASE_ADDRS                         { AUDIO__XBAR_BASE }
  /** Array initializer of XBAR0 peripheral base pointers */
  #define XBAR0_BASE_PTRS                          { AUDIO__XBAR }
#endif

/* XBAR1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__XBAR_0 base address */
  #define HSP__XBAR_0_BASE                         (0x52820000u)
  /** Peripheral HSP__XBAR_0 base address */
  #define HSP__XBAR_0_BASE_NS                      (0x42820000u)
  /** Peripheral HSP__XBAR_0 base pointer */
  #define HSP__XBAR_0                              ((XBAR1_Type *)HSP__XBAR_0_BASE)
  /** Peripheral HSP__XBAR_0 base pointer */
  #define HSP__XBAR_0_NS                           ((XBAR1_Type *)HSP__XBAR_0_BASE_NS)
  /** Array initializer of XBAR1 peripheral base addresses */
  #define XBAR1_BASE_ADDRS                         { HSP__XBAR_0_BASE }
  /** Array initializer of XBAR1 peripheral base pointers */
  #define XBAR1_BASE_PTRS                          { HSP__XBAR_0 }
  /** Array initializer of XBAR1 peripheral base addresses */
  #define XBAR1_BASE_ADDRS_NS                      { HSP__XBAR_0_BASE_NS }
  /** Array initializer of XBAR1 peripheral base pointers */
  #define XBAR1_BASE_PTRS_NS                       { HSP__XBAR_0_NS }
#else
  /** Peripheral HSP__XBAR_0 base address */
  #define HSP__XBAR_0_BASE                         (0x42820000u)
  /** Peripheral HSP__XBAR_0 base pointer */
  #define HSP__XBAR_0                              ((XBAR1_Type *)HSP__XBAR_0_BASE)
  /** Array initializer of XBAR1 peripheral base addresses */
  #define XBAR1_BASE_ADDRS                         { HSP__XBAR_0_BASE }
  /** Array initializer of XBAR1 peripheral base pointers */
  #define XBAR1_BASE_PTRS                          { HSP__XBAR_0 }
#endif

/* XBAR2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__XBAR_1 base address */
  #define HSP__XBAR_1_BASE                         (0x52830000u)
  /** Peripheral HSP__XBAR_1 base address */
  #define HSP__XBAR_1_BASE_NS                      (0x42830000u)
  /** Peripheral HSP__XBAR_1 base pointer */
  #define HSP__XBAR_1                              ((XBAR2_Type *)HSP__XBAR_1_BASE)
  /** Peripheral HSP__XBAR_1 base pointer */
  #define HSP__XBAR_1_NS                           ((XBAR2_Type *)HSP__XBAR_1_BASE_NS)
  /** Array initializer of XBAR2 peripheral base addresses */
  #define XBAR2_BASE_ADDRS                         { HSP__XBAR_1_BASE }
  /** Array initializer of XBAR2 peripheral base pointers */
  #define XBAR2_BASE_PTRS                          { HSP__XBAR_1 }
  /** Array initializer of XBAR2 peripheral base addresses */
  #define XBAR2_BASE_ADDRS_NS                      { HSP__XBAR_1_BASE_NS }
  /** Array initializer of XBAR2 peripheral base pointers */
  #define XBAR2_BASE_PTRS_NS                       { HSP__XBAR_1_NS }
#else
  /** Peripheral HSP__XBAR_1 base address */
  #define HSP__XBAR_1_BASE                         (0x42830000u)
  /** Peripheral HSP__XBAR_1 base pointer */
  #define HSP__XBAR_1                              ((XBAR2_Type *)HSP__XBAR_1_BASE)
  /** Array initializer of XBAR2 peripheral base addresses */
  #define XBAR2_BASE_ADDRS                         { HSP__XBAR_1_BASE }
  /** Array initializer of XBAR2 peripheral base pointers */
  #define XBAR2_BASE_PTRS                          { HSP__XBAR_1 }
#endif

/* XBAR3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSP__XBAR_2 base address */
  #define HSP__XBAR_2_BASE                         (0x52840000u)
  /** Peripheral HSP__XBAR_2 base address */
  #define HSP__XBAR_2_BASE_NS                      (0x42840000u)
  /** Peripheral HSP__XBAR_2 base pointer */
  #define HSP__XBAR_2                              ((XBAR3_Type *)HSP__XBAR_2_BASE)
  /** Peripheral HSP__XBAR_2 base pointer */
  #define HSP__XBAR_2_NS                           ((XBAR3_Type *)HSP__XBAR_2_BASE_NS)
  /** Array initializer of XBAR3 peripheral base addresses */
  #define XBAR3_BASE_ADDRS                         { HSP__XBAR_2_BASE }
  /** Array initializer of XBAR3 peripheral base pointers */
  #define XBAR3_BASE_PTRS                          { HSP__XBAR_2 }
  /** Array initializer of XBAR3 peripheral base addresses */
  #define XBAR3_BASE_ADDRS_NS                      { HSP__XBAR_2_BASE_NS }
  /** Array initializer of XBAR3 peripheral base pointers */
  #define XBAR3_BASE_PTRS_NS                       { HSP__XBAR_2_NS }
#else
  /** Peripheral HSP__XBAR_2 base address */
  #define HSP__XBAR_2_BASE                         (0x42840000u)
  /** Peripheral HSP__XBAR_2 base pointer */
  #define HSP__XBAR_2                              ((XBAR3_Type *)HSP__XBAR_2_BASE)
  /** Array initializer of XBAR3 peripheral base addresses */
  #define XBAR3_BASE_ADDRS                         { HSP__XBAR_2_BASE }
  /** Array initializer of XBAR3 peripheral base pointers */
  #define XBAR3_BASE_PTRS                          { HSP__XBAR_2 }
#endif

/* XBAR4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKE__XBAR base address */
  #define WAKE__XBAR_BASE                          (0x560B0000u)
  /** Peripheral WAKE__XBAR base address */
  #define WAKE__XBAR_BASE_NS                       (0x460B0000u)
  /** Peripheral WAKE__XBAR base pointer */
  #define WAKE__XBAR                               ((XBAR4_Type *)WAKE__XBAR_BASE)
  /** Peripheral WAKE__XBAR base pointer */
  #define WAKE__XBAR_NS                            ((XBAR4_Type *)WAKE__XBAR_BASE_NS)
  /** Array initializer of XBAR4 peripheral base addresses */
  #define XBAR4_BASE_ADDRS                         { WAKE__XBAR_BASE }
  /** Array initializer of XBAR4 peripheral base pointers */
  #define XBAR4_BASE_PTRS                          { WAKE__XBAR }
  /** Array initializer of XBAR4 peripheral base addresses */
  #define XBAR4_BASE_ADDRS_NS                      { WAKE__XBAR_BASE_NS }
  /** Array initializer of XBAR4 peripheral base pointers */
  #define XBAR4_BASE_PTRS_NS                       { WAKE__XBAR_NS }
#else
  /** Peripheral WAKE__XBAR base address */
  #define WAKE__XBAR_BASE                          (0x460B0000u)
  /** Peripheral WAKE__XBAR base pointer */
  #define WAKE__XBAR                               ((XBAR4_Type *)WAKE__XBAR_BASE)
  /** Array initializer of XBAR4 peripheral base addresses */
  #define XBAR4_BASE_ADDRS                         { WAKE__XBAR_BASE }
  /** Array initializer of XBAR4 peripheral base pointers */
  #define XBAR4_BASE_PTRS                          { WAKE__XBAR }
#endif

/* XSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MAIN__XSPI_0 base address */
  #define MAIN__XSPI_0_BASE                        (0x50460000u)
  /** Peripheral MAIN__XSPI_0 base address */
  #define MAIN__XSPI_0_BASE_NS                     (0x40460000u)
  /** Peripheral MAIN__XSPI_0 base pointer */
  #define MAIN__XSPI_0                             ((XSPI_Type *)MAIN__XSPI_0_BASE)
  /** Peripheral MAIN__XSPI_0 base pointer */
  #define MAIN__XSPI_0_NS                          ((XSPI_Type *)MAIN__XSPI_0_BASE_NS)
  /** Peripheral MAIN__XSPI_1 base address */
  #define MAIN__XSPI_1_BASE                        (0x50470000u)
  /** Peripheral MAIN__XSPI_1 base address */
  #define MAIN__XSPI_1_BASE_NS                     (0x40470000u)
  /** Peripheral MAIN__XSPI_1 base pointer */
  #define MAIN__XSPI_1                             ((XSPI_Type *)MAIN__XSPI_1_BASE)
  /** Peripheral MAIN__XSPI_1 base pointer */
  #define MAIN__XSPI_1_NS                          ((XSPI_Type *)MAIN__XSPI_1_BASE_NS)
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS                          { MAIN__XSPI_0_BASE, MAIN__XSPI_1_BASE }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS                           { MAIN__XSPI_0, MAIN__XSPI_1 }
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS_NS                       { MAIN__XSPI_0_BASE_NS, MAIN__XSPI_1_BASE_NS }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS_NS                        { MAIN__XSPI_0_NS, MAIN__XSPI_1_NS }
#else
  /** Peripheral MAIN__XSPI_0 base address */
  #define MAIN__XSPI_0_BASE                        (0x40460000u)
  /** Peripheral MAIN__XSPI_0 base pointer */
  #define MAIN__XSPI_0                             ((XSPI_Type *)MAIN__XSPI_0_BASE)
  /** Peripheral MAIN__XSPI_1 base address */
  #define MAIN__XSPI_1_BASE                        (0x40470000u)
  /** Peripheral MAIN__XSPI_1 base pointer */
  #define MAIN__XSPI_1                             ((XSPI_Type *)MAIN__XSPI_1_BASE)
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS                          { MAIN__XSPI_0_BASE, MAIN__XSPI_1_BASE }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS                           { MAIN__XSPI_0, MAIN__XSPI_1 }
#endif
/** Interrupt vectors for the XSPI peripheral type */
#define XSPI_IRQS                                { MAIN_XSPI0_IRQn, MAIN_XSPI1_IRQn }
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /* XSPI AMBA address. */
  #define XSPI0_AMBA_BASE      (0x70000000u)
  #define XSPI1_AMBA_BASE      (0x90000000u)
  #define XSPI0_AMBA_BASE_NS   (0x60000000u)
  #define XSPI1_AMBA_BASE_NS   (0x80000000u)
  #define XSPI_AMBA_BASES      {0x70000000u, 0x90000000u}
  #define XSPI_AMBA_BASES_NS   {0x60000000u, 0x80000000u}
#else
  /* XSPI AMBA address. */
  #define XSPI0_AMBA_BASE      (0x60000000u)
  #define XSPI1_AMBA_BASE      (0x80000000u)
  #define XSPI_AMBA_BASES      {0x60000000u, 0x80000000u}
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

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* MIMXRT2661_COMMON_H_ */

