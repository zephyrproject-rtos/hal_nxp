/*
** ###################################################################
**     Processors:          MCXC352GAMFM
**                          MCXC352GAMFT
**                          MCXC352MLF
**
**     Compilers:
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    MCXCP048M096F3RM, Rev 1 Draft D
**     Version:             rev. 1.0, 2025-11-26
**     Build:               b260826
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCXC352
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-11-26)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MCXC352_COMMON.h
 * @version 1.0
 * @date 2025-11-26
 * @brief CMSIS Peripheral Access Layer for MCXC352
 *
 * CMSIS Peripheral Access Layer for MCXC352
 */

#if !defined(MCXC352_COMMON_H_)
#define MCXC352_COMMON_H_                        /**< Symbol preventing repeated inclusion */

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
    kXBAR0 = 1,
} xbar_instance_t;
#define XBAR_INFO \
    { \
        { \
            (volatile uint32_t *)XBAR0_BASE, 0x0U, XBAR_SEL_COUNT, 0x104U, XBAR_CTRL_COUNT \
        }, \
    }



/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 124                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M23 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M23 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M23 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M23 System Tick Interrupt */

  /* Device specific interrupts */
  Reserved16_IRQn              = 0,                /**< Reserved interrupt 16 */
  CMC_IRQn                     = 1,                /**< Core Mode Controller interrupt */
  DMA_CH0_IRQn                 = 2,                /**< DMA3_0_CH0 error or transfer complete */
  DMA_CH1_IRQn                 = 3,                /**< DMA3_0_CH1 error or transfer complete */
  DMA_CH2_IRQn                 = 4,                /**< DMA3_0_CH2 error or transfer complete */
  DMA_CH3_IRQn                 = 5,                /**< DMA3_0_CH3 error or transfer complete */
  Reserved22_IRQn              = 6,                /**< Reserved interrupt 22 */
  Reserved23_IRQn              = 7,                /**< Reserved interrupt 23 */
  Reserved24_IRQn              = 8,                /**< Reserved interrupt 24 */
  Reserved25_IRQn              = 9,                /**< Reserved interrupt 25 */
  ERM0_SINGLE_BIT_IRQn         = 10,               /**< ERM Single Bit error interrupt */
  ERM0_MULTI_BIT_IRQn          = 11,               /**< ERM Multi Bit error interrupt */
  FMU0_IRQn                    = 12,               /**< Flash Management Unit interrupt */
  Reserved29_IRQn              = 13,               /**< Reserved interrupt 29 */
  MBC0_IRQn                    = 14,               /**< MBC secure violation interrupt */
  SCG0_IRQn                    = 15,               /**< System Clock Generator interrupt */
  SPC0_IRQn                    = 16,               /**< System Power Controller interrupt */
  Reserved33_IRQn              = 17,               /**< Reserved interrupt 33 */
  WUU0_IRQn                    = 18,               /**< Wake Up Unit interrupt */
  Reserved35_IRQn              = 19,               /**< Reserved interrupt 35 */
  Reserved36_IRQn              = 20,               /**< Reserved interrupt 36 */
  Reserved37_IRQn              = 21,               /**< Reserved interrupt 37 */
  Reserved38_IRQn              = 22,               /**< Reserved interrupt 38 */
  Reserved39_IRQn              = 23,               /**< Reserved interrupt 39 */
  Reserved40_IRQn              = 24,               /**< Reserved interrupt 40 */
  Reserved41_IRQn              = 25,               /**< Reserved interrupt 41 */
  LPI2C0_IRQn                  = 26,               /**< Low-Power Inter Integrated Circuit 0 interrupt */
  LPI2C1_IRQn                  = 27,               /**< Low-Power Inter Integrated Circuit 1 interrupt */
  LPSPI0_IRQn                  = 28,               /**< Low-Power Serial Peripheral Interface 0 interrupt */
  Reserved45_IRQn              = 29,               /**< Reserved interrupt 45 */
  Reserved46_IRQn              = 30,               /**< Reserved interrupt 46 */
  LPUART0_IRQn                 = 31,               /**< Low-Power Universal Asynchronous Receive/Transmit 0 interrupt */
  LPUART1_IRQn                 = 32,               /**< Low-Power Universal Asynchronous Receive/Transmit 1 interrupt */
  Reserved49_IRQn              = 33,               /**< Reserved interrupt 49 */
  Reserved50_IRQn              = 34,               /**< Reserved interrupt 50 */
  Reserved51_IRQn              = 35,               /**< Reserved interrupt 51 */
  Reserved52_IRQn              = 36,               /**< Reserved interrupt 52 */
  Reserved53_IRQn              = 37,               /**< Reserved interrupt 53 */
  Reserved54_IRQn              = 38,               /**< Reserved interrupt 54 */
  FTM0_OVERFLOW_IRQn           = 39,               /**< FlexTimer overflow interrupt */
  FTM0_CH0_IRQn                = 40,               /**< FlexTimer channel 0 interrupt */
  FTM0_CH1_IRQn                = 41,               /**< FlexTimer channel 1 interrupt */
  Reserved58_IRQn              = 42,               /**< Reserved interrupt 58 */
  Reserved59_IRQn              = 43,               /**< Reserved interrupt 59 */
  FLEXPWM0_RELOAD_ERROR_IRQn   = 44,               /**< FlexPWM0_reload_error interrupt */
  FLEXPWM0_FAULT_IRQn          = 45,               /**< FlexPWM0_fault interrupt */
  FLEXPWM0_SUBMODULE0_IRQn     = 46,               /**< FlexPWM0 Submodule 0 capture/compare/reload interrupt */
  FLEXPWM0_SUBMODULE1_IRQn     = 47,               /**< FlexPWM0 Submodule 1 capture/compare/reload interrupt */
  FLEXPWM0_SUBMODULE2_IRQn     = 48,               /**< FlexPWM0 Submodule 2 capture/compare/reload interrupt */
  FLEXPWM0_SUBMODULE3_IRQn     = 49,               /**< FlexPWM0 Submodule 3 capture/compare/reload interrupt */
  QTMR0_CH0_IRQn               = 50,               /**< Quad-Timer Channel 0 interrupt */
  QTMR0_CH1_IRQn               = 51,               /**< Quad-Timer Channel 1 interrupt */
  QTMR0_CH2_IRQn               = 52,               /**< Quad-Timer Channel 2 interrupt */
  QTMR0_CH3_IRQn               = 53,               /**< Quad-Timer Channel 3 interrupt */
  FREQME0_IRQn                 = 54,               /**< Frequency Measurement interrupt */
  Reserved71_IRQn              = 55,               /**< Reserved interrupt 71 */
  PIT0_IRQn                    = 56,               /**< Programmable Interval Timer interrupt */
  VBAT0_IRQn                   = 57,               /**< VBAT OSC32K Ready Interrupt */
  Reserved74_IRQn              = 58,               /**< Reserved interrupt 74 */
  Reserved75_IRQn              = 59,               /**< Reserved interrupt 75 */
  WWDT0_IRQn                   = 60,               /**< Windowed Watchdog Timer 0 interrupt */
  ADC0_STATE_IRQn              = 61,               /**< Analog-to-Digital Converter states interrupt */
  ADC0_A_IRQn                  = 62,               /**< Analog-to-Digital Converter A done interrupt */
  ADC0_B_IRQn                  = 63,               /**< Analog-to-Digital Converter B done interrupt */
  CMP0_IRQn                    = 64,               /**< Comparator 0 interrupt */
  CMP1_IRQn                    = 65,               /**< Comparator 1 interrupt */
  Reserved82_IRQn              = 66,               /**< Reserved interrupt 82 */
  Reserved83_IRQn              = 67,               /**< Reserved interrupt 83 */
  PHD0_PHASEA_IRQn             = 68,               /**< Phase Detection phase A interrupt */
  PHD0_PHASEb_IRQn             = 69,               /**< Phase Detection phase B interrupt */
  PHD0_PHASEC_IRQn             = 70,               /**< Phase Detection phase C interrupt */
  GPIO0_IRQn                   = 71,               /**< General Purpose Input/Output 0 interrupt */
  GPIO1_IRQn                   = 72,               /**< General Purpose Input/Output 1 interrupt */
  GPIO2_IRQn                   = 73,               /**< General Purpose Input/Output 2 interrupt */
  GPIO3_IRQn                   = 74,               /**< General Purpose Input/Output 3 interrupt */
  Reserved91_IRQn              = 75,               /**< Reserved interrupt 91 */
  Reserved92_IRQn              = 76,               /**< Reserved interrupt 92 */
  Reserved93_IRQn              = 77,               /**< Reserved interrupt 93 */
  Reserved94_IRQn              = 78,               /**< Reserved interrupt 94 */
  PWT0_OVERFLOW_IRQn           = 79,               /**< Pulse Width Timer 0 overflow interrupt */
  PWT0_READY_IRQn              = 80,               /**< Pulse Width Timer 0 data ready interrupt */
  PWT1_OVERFLOW_IRQn           = 81,               /**< Pulse Width Timer 1 overflow interrupt */
  PWT1_READY_IRQn              = 82,               /**< Pulse Width Timer 1 data ready interrupt */
  XBAR0_IRQ0_IRQn              = 83,               /**< XBAR INT_REQ 0 */
  XBAR0_IRQ1_IRQn              = 84,               /**< XBAR INT_REQ 1 */
  XBAR0_IRQ2_IRQn              = 85,               /**< XBAR INT_REQ 2 */
  XBAR0_IRQ3_IRQn              = 86,               /**< XBAR INT_REQ 3 */
  Reserved103_IRQn             = 87,               /**< Reserved interrupt 103 */
  Reserved104_IRQn             = 88,               /**< Reserved interrupt 104 */
  Reserved105_IRQn             = 89,               /**< Reserved interrupt 105 */
  Reserved106_IRQn             = 90,               /**< Reserved interrupt 106 */
  Reserved107_IRQn             = 91,               /**< Reserved interrupt 107 */
  Reserved108_IRQn             = 92,               /**< Reserved interrupt 108 */
  Reserved109_IRQn             = 93,               /**< Reserved interrupt 109 */
  Reserved110_IRQn             = 94,               /**< Reserved interrupt 110 */
  Reserved111_IRQn             = 95,               /**< Reserved interrupt 111 */
  Reserved112_IRQn             = 96,               /**< Reserved interrupt 112 */
  Reserved113_IRQn             = 97,               /**< Reserved interrupt 113 */
  Reserved114_IRQn             = 98,               /**< Reserved interrupt 114 */
  Reserved115_IRQn             = 99,               /**< Reserved interrupt 115 */
  Reserved116_IRQn             = 100,              /**< Reserved interrupt 116 */
  Reserved117_IRQn             = 101,              /**< Reserved interrupt 117 */
  Reserved118_IRQn             = 102,              /**< Reserved interrupt 118 */
  Reserved119_IRQn             = 103,              /**< Reserved interrupt 119 */
  Reserved120_IRQn             = 104,              /**< Reserved interrupt 120 */
  Reserved121_IRQn             = 105,              /**< Reserved interrupt 121 */
  Reserved122_IRQn             = 106,              /**< Reserved interrupt 122 */
  MAU_IRQn                     = 107               /**< MAU interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M23 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M23 Core Configuration
 * @{
 */

#define __CM23_REV                     0x0200    /**< Core revision r2p0 */
#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if VTOR is present or not */
#define __NVIC_PRIO_BITS               2         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __SAUREGION_PRESENT            0         /**< Defines if an SAU is present or not */

#include "core_cm23.h"                 /* Core Peripheral Access Layer */
#include "system_MCXC352.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MCXC352_SERIES
#define MCXC352_SERIES
#endif
/* CPU specific feature definitions */
#include "MCXC352_features.h"

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup eim_memory_channel_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the eim_memory_channel
 *
 *
 * Defines the structure for the EIM resource collections.
 */
typedef enum _eim_memory_channel
{
    kEIM_MemoryChannelRAMA0         = 0U,          /**< Memory RAMA0 */
} eim_memory_channel_t;

/* @} */

/*!
 * @addtogroup eim_error_injection_channel_enab_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the eim_error_injection_channel_enable
 *
 *
 * Defines the structure for the EIM error injection resource collections.
 */
typedef enum _eim_error_injection_channel_enab
{
    kEIM_MemoryChannelRAMAEnable    = 0x80000000U, /**< Memory channel 0(RAMA0) error injection enable */
} eim_error_injection_channel_enab_t;

/* @} */

/*!
 * @addtogroup erm_memory_channel_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the erm_memory_channel
 *
 *
 * Defines the structure for the ERM resource collections.
 */
typedef enum _erm_memory_channel
{
    kERM_MemoryChannelRAMA0         = 0U,          /**< Memory RAMA0 */
    kERM_MemoryChannelFLASH         = 1U,          /**< Memory FLASH */
} erm_memory_channel_t;

/* @} */

/*!
 * @addtogroup freqme_reference_clock_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the freqme_reference_clock
 *
 *
 * Defines the structure for the FREQME reference clock source selection.
 */
typedef enum _freqme_reference_clock
{
    kFREQME_RefClkIn                = 1U,          /**< Clock from CLKIN pin */
    kFREQME_RefFroOsc12M            = 2U,          /**< FRO 12MHz oscillator */
    kFREQME_RefFroHfDiv             = 3U,          /**< FRO high frequency divided clock */
    kFREQME_RefClk16K1              = 5U,          /**< 16KHz clock */
    kFREQME_RefSlowClk              = 6U,          /**< Slow clock */
    kFREQME_RefFreqmeClkIn0         = 7U,          /**< FREQME clock input 0 */
    kFREQME_RefFreqmeClkIn1         = 8U,          /**< FREQME clock input 1 */
    kFREQME_RefAoi0Out0             = 9U,          /**< AOI0 output 0 */
    kFREQME_RefAoi0Out1             = 10U,         /**< AOI0 output 1 */
    kFREQME_RefPwm0Sm0OutTrig0      = 11U,         /**< PWM0 submodule 0 output trigger 0 */
    kFREQME_RefPwm0Sm0OutTrig1      = 12U,         /**< PWM0 submodule 0 output trigger 1 */
    kFREQME_RefPwm0Sm1OutTrig0      = 13U,         /**< PWM0 submodule 1 output trigger 0 */
    kFREQME_RefPwm0Sm1OutTrig1      = 14U,         /**< PWM0 submodule 1 output trigger 1 */
    kFREQME_RefPwm0Sm2OutTrig0      = 15U,         /**< PWM0 submodule 2 output trigger 0 */
    kFREQME_RefPwm0Sm2OutTrig1      = 16U,         /**< PWM0 submodule 2 output trigger 1 */
    kFREQME_RefPwm0Sm3OutTrig0      = 17U,         /**< PWM0 submodule 3 output trigger 0 */
    kFREQME_RefPwm0Sm3OutTrig1      = 18U,         /**< PWM0 submodule 3 output trigger 1 */
} freqme_reference_clock_t;

/* @} */

/*!
 * @addtogroup freqme_target_clock_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the freqme_target_clock
 *
 *
 * Defines the structure for the FREQME target clock source selection.
 */
typedef enum _freqme_target_clock
{
    kFREQME_TarClkIn                = 1U,          /**< Clock from CLKIN pin */
    kFREQME_TarFroOsc12M            = 2U,          /**< FRO 12MHz oscillator */
    kFREQME_TarFroHfDiv             = 3U,          /**< FRO high frequency divided clock */
    kFREQME_TarClk16K1              = 5U,          /**< 16KHz clock */
    kFREQME_TarSlowClk              = 6U,          /**< Slow clock */
    kFREQME_TarFreqmeClkIn0         = 7U,          /**< FREQME clock input 0 */
    kFREQME_TarFreqmeClkIn1         = 8U,          /**< FREQME clock input 1 */
    kFREQME_TarAoi0Out0             = 9U,          /**< AOI0 output 0 */
    kFREQME_TarAoi0Out1             = 10U,         /**< AOI0 output 1 */
    kFREQME_TarPwm0Sm0OutTrig0      = 11U,         /**< PWM0 submodule 0 output trigger 0 */
    kFREQME_TarPwm0Sm0OutTrig1      = 12U,         /**< PWM0 submodule 0 output trigger 1 */
    kFREQME_TarPwm0Sm1OutTrig0      = 13U,         /**< PWM0 submodule 1 output trigger 0 */
    kFREQME_TarPwm0Sm1OutTrig1      = 14U,         /**< PWM0 submodule 1 output trigger 1 */
    kFREQME_TarPwm0Sm2OutTrig0      = 15U,         /**< PWM0 submodule 2 output trigger 0 */
    kFREQME_TarPwm0Sm2OutTrig1      = 16U,         /**< PWM0 submodule 2 output trigger 1 */
    kFREQME_TarPwm0Sm3OutTrig0      = 17U,         /**< PWM0 submodule 3 output trigger 0 */
    kFREQME_TarPwm0Sm3OutTrig1      = 18U,         /**< PWM0 submodule 3 output trigger 1 */
} freqme_target_clock_t;

/* @} */

typedef enum _xbar_input_signal
{
    kXBAR0_InputLogicLow            = 0|0x10000U,  /**< LOGIC_LOW output assigned to XBAR0_IN0 input. */
    kXBAR0_InputLogicHigh           = 1|0x10000U,  /**< LOGIC_HIGH output assigned to XBAR0_IN1 input. */
    kXBAR0_InputIomuxXbarIn2        = 2|0x10000U,  /**< IOMUX_XBAR_IN2 output assigned to XBAR0_IN2 input. */
    kXBAR0_InputIomuxXbarIn3        = 3|0x10000U,  /**< IOMUX_XBAR_IN3 output assigned to XBAR0_IN3 input. */
    kXBAR0_InputIomuxXbarIn4        = 4|0x10000U,  /**< IOMUX_XBAR_IN4 output assigned to XBAR0_IN4 input. */
    kXBAR0_InputIomuxXbarIn5        = 5|0x10000U,  /**< IOMUX_XBAR_IN5 output assigned to XBAR0_IN5 input. */
    kXBAR0_InputIomuxXbarIn6        = 6|0x10000U,  /**< IOMUX_XBAR_IN6 output assigned to XBAR0_IN6 input. */
    kXBAR0_InputIomuxXbarIn7        = 7|0x10000U,  /**< IOMUX_XBAR_IN7 output assigned to XBAR0_IN7 input. */
    kXBAR0_InputIomuxXbarIn8        = 8|0x10000U,  /**< IOMUX_XBAR_IN8 output assigned to XBAR0_IN8 input. */
    kXBAR0_InputIomuxXbarIn9        = 9|0x10000U,  /**< IOMUX_XBAR_IN9 output assigned to XBAR0_IN9 input. */
    kXBAR0_InputPwmSm0MuxTrigger0   = 10|0x10000U, /**< PWM_SM0_MUX_TRIGGER0 output assigned to XBAR0_IN10 input. */
    kXBAR0_InputPwmSm0MuxTrigger1   = 11|0x10000U, /**< PWM_SM0_MUX_TRIGGER1 output assigned to XBAR0_IN11 input. */
    kXBAR0_InputPwmSm1MuxTrigger0   = 12|0x10000U, /**< PWM_SM1_MUX_TRIGGER0 output assigned to XBAR0_IN12 input. */
    kXBAR0_InputPwmSm1MuxTrigger1   = 13|0x10000U, /**< PWM_SM1_MUX_TRIGGER1 output assigned to XBAR0_IN13 input. */
    kXBAR0_InputPwmSm2MuxTrigger0   = 14|0x10000U, /**< PWM_SM2_MUX_TRIGGER0 output assigned to XBAR0_IN14 input. */
    kXBAR0_InputPwmSm2MuxTrigger1   = 15|0x10000U, /**< PWM_SM2_MUX_TRIGGER1 output assigned to XBAR0_IN15 input. */
    kXBAR0_InputPwmSm3MuxTrigger0   = 16|0x10000U, /**< PWM_SM3_MUX_TRIGGER0 output assigned to XBAR0_IN16 input. */
    kXBAR0_InputPwmSm3MuxTrigger1   = 17|0x10000U, /**< PWM_SM3_MUX_TRIGGER1 output assigned to XBAR0_IN17 input. */
    kXBAR0_InputPwmSm0OutTrigger0   = 18|0x10000U, /**< PWM_SM0_OUT_TRIGGER0 output assigned to XBAR0_IN18 input. */
    kXBAR0_InputPwmSm0OutTrigger1   = 19|0x10000U, /**< PWM_SM0_OUT_TRIGGER1 output assigned to XBAR0_IN19 input. */
    kXBAR0_InputPwmSm3OutTrigger0   = 20|0x10000U, /**< PWM_SM3_OUT_TRIGGER0 output assigned to XBAR0_IN20 input. */
    kXBAR0_InputPwmSm3OutTrigger1   = 21|0x10000U, /**< PWM_SM3_OUT_TRIGGER1 output assigned to XBAR0_IN21 input. */
    kXBAR0_InputQtmrTmr0Out         = 22|0x10000U, /**< QTMR_TMR0_OUT output assigned to XBAR0_IN22 input. */
    kXBAR0_InputQtmrTmr1Out         = 23|0x10000U, /**< QTMR_TMR1_OUT output assigned to XBAR0_IN23 input. */
    kXBAR0_InputQtmrTmr2Out         = 24|0x10000U, /**< QTMR_TMR2_OUT output assigned to XBAR0_IN24 input. */
    kXBAR0_InputQtmrTmr3Out         = 25|0x10000U, /**< QTMR_TMR3_OUT output assigned to XBAR0_IN25 input. */
    kXBAR0_InputFtmCh0Out           = 26|0x10000U, /**< FTM_CH0_OUT output assigned to XBAR0_IN26 input. */
    kXBAR0_InputFtmCh1Out           = 27|0x10000U, /**< FTM_CH1_OUT output assigned to XBAR0_IN27 input. */
    kXBAR0_InputPitSyncOut          = 28|0x10000U, /**< PIT_SYNC_OUT output assigned to XBAR0_IN28 input. */
    kXBAR0_InputPhdCmp0Out          = 29|0x10000U, /**< PHD_CMP0_OUT output assigned to XBAR0_IN29 input. */
    kXBAR0_InputPhdCmp1Out          = 30|0x10000U, /**< PHD_CMP1_OUT output assigned to XBAR0_IN30 input. */
    kXBAR0_InputPhdCmp2Out          = 31|0x10000U, /**< PHD_CMP2_OUT output assigned to XBAR0_IN31 input. */
    kXBAR0_InputCmp0Out             = 32|0x10000U, /**< CMP0_OUT output assigned to XBAR0_IN32 input. */
    kXBAR0_InputCmp1Out             = 33|0x10000U, /**< CMP1_OUT output assigned to XBAR0_IN33 input. */
    kXBAR0_InputAoiSm0Out           = 34|0x10000U, /**< AOI_SM0_OUT output assigned to XBAR0_IN34 input. */
    kXBAR0_InputAoiSm1Out           = 35|0x10000U, /**< AOI_SM1_OUT output assigned to XBAR0_IN35 input. */
    kXBAR0_InputAoiSm2Out           = 36|0x10000U, /**< AOI_SM2_OUT output assigned to XBAR0_IN36 input. */
    kXBAR0_InputAoiSm3Out           = 37|0x10000U, /**< AOI_SM3_OUT output assigned to XBAR0_IN37 input. */
} xbar_input_signal_t;

typedef enum _xbar_output_signal
{
    kXBAR0_OutputXbarDmaInt0        = 0|0x10000U,  /**< XBAR0_OUT0 output assigned to XBAR_DMA_INT0 */
    kXBAR0_OutputXbarDmaInt1        = 1|0x10000U,  /**< XBAR0_OUT1 output assigned to XBAR_DMA_INT1 */
    kXBAR0_OutputXbarDmaInt2        = 2|0x10000U,  /**< XBAR0_OUT2 output assigned to XBAR_DMA_INT2 */
    kXBAR0_OutputXbarDmaInt3        = 3|0x10000U,  /**< XBAR0_OUT3 output assigned to XBAR_DMA_INT3 */
    kXBAR0_OutputIomuxXbarOut4      = 4|0x10000U,  /**< XBAR0_OUT4 output assigned to IOMUX_XBAR_OUT4 */
    kXBAR0_OutputIomuxXbarOut5      = 5|0x10000U,  /**< XBAR0_OUT5 output assigned to IOMUX_XBAR_OUT5 */
    kXBAR0_OutputIomuxXbarOut6      = 6|0x10000U,  /**< XBAR0_OUT6 output assigned to IOMUX_XBAR_OUT6 */
    kXBAR0_OutputIomuxXbarOut7      = 7|0x10000U,  /**< XBAR0_OUT7 output assigned to IOMUX_XBAR_OUT7 */
    kXBAR0_OutputIomuxXbarOut8      = 8|0x10000U,  /**< XBAR0_OUT8 output assigned to IOMUX_XBAR_OUT8 */
    kXBAR0_OutputIomuxXbarOut9      = 9|0x10000U,  /**< XBAR0_OUT9 output assigned to IOMUX_XBAR_OUT9 */
    kXBAR0_OutputIomuxXbarOut10     = 10|0x10000U, /**< XBAR0_OUT10 output assigned to IOMUX_XBAR_OUT10 */
    kXBAR0_OutputIomuxXbarOut11     = 11|0x10000U, /**< XBAR0_OUT11 output assigned to IOMUX_XBAR_OUT11 */
    kXBAR0_OutputPwmSm0ExtSync      = 12|0x10000U, /**< XBAR0_OUT12 output assigned to PWM_SM0_EXT_SYNC */
    kXBAR0_OutputPwmSm1ExtSync      = 13|0x10000U, /**< XBAR0_OUT13 output assigned to PWM_SM1_EXT_SYNC */
    kXBAR0_OutputPwmSm2ExtSync      = 14|0x10000U, /**< XBAR0_OUT14 output assigned to PWM_SM2_EXT_SYNC */
    kXBAR0_OutputPwmSm3ExtSync      = 15|0x10000U, /**< XBAR0_OUT15 output assigned to PWM_SM3_EXT_SYNC */
    kXBAR0_OutputPwmExtForce        = 16|0x10000U, /**< XBAR0_OUT16 output assigned to PWM_EXT_FORCE */
    kXBAR0_OutputPwmExtClk          = 17|0x10000U, /**< XBAR0_OUT17 output assigned to PWM_EXT_CLK */
    kXBAR0_OutputPwmSm0Exta         = 18|0x10000U, /**< XBAR0_OUT18 output assigned to PWM_SM0_EXTA */
    kXBAR0_OutputPwmSm1Exta         = 19|0x10000U, /**< XBAR0_OUT19 output assigned to PWM_SM1_EXTA */
    kXBAR0_OutputPwmSm2Exta         = 20|0x10000U, /**< XBAR0_OUT20 output assigned to PWM_SM2_EXTA */
    kXBAR0_OutputPwmSm3Exta         = 21|0x10000U, /**< XBAR0_OUT21 output assigned to PWM_SM3_EXTA */
    kXBAR0_OutputPwmFault0          = 22|0x10000U, /**< XBAR0_OUT22 output assigned to PWM_FAULT0 */
    kXBAR0_OutputPwmFault1          = 23|0x10000U, /**< XBAR0_OUT23 output assigned to PWM_FAULT1 */
    kXBAR0_OutputPwmFault2          = 24|0x10000U, /**< XBAR0_OUT24 output assigned to PWM_FAULT2 */
    kXBAR0_OutputPwmFault3          = 25|0x10000U, /**< XBAR0_OUT25 output assigned to PWM_FAULT3 */
    kXBAR0_OutputQtmrTmr0In         = 26|0x10000U, /**< XBAR0_OUT26 output assigned to QTMR_TMR0_IN */
    kXBAR0_OutputQtmrTmr1In         = 27|0x10000U, /**< XBAR0_OUT27 output assigned to QTMR_TMR1_IN */
    kXBAR0_OutputQtmrTmr2In         = 28|0x10000U, /**< XBAR0_OUT28 output assigned to QTMR_TMR2_IN */
    kXBAR0_OutputQtmrTmr3In         = 29|0x10000U, /**< XBAR0_OUT29 output assigned to QTMR_TMR3_IN */
    kXBAR0_OutputFtmCh0In           = 30|0x10000U, /**< XBAR0_OUT30 output assigned to FTM_CH0_IN */
    kXBAR0_OutputFtmCh1In           = 31|0x10000U, /**< XBAR0_OUT31 output assigned to FTM_CH1_IN */
    kXBAR0_OutputPitPreset          = 32|0x10000U, /**< XBAR0_OUT32 output assigned to PIT_PRESET */
    kXBAR0_OutputPwt0In1            = 33|0x10000U, /**< XBAR0_OUT33 output assigned to PWT0_IN1 */
    kXBAR0_OutputPwt1In1            = 34|0x10000U, /**< XBAR0_OUT34 output assigned to PWT1_IN1 */
    kXBAR0_OutputPhdCmp0Win         = 35|0x10000U, /**< XBAR0_OUT35 output assigned to PHD_CMP0_WIN */
    kXBAR0_OutputPhdCmp1Win         = 36|0x10000U, /**< XBAR0_OUT36 output assigned to PHD_CMP1_WIN */
    kXBAR0_OutputPhdCmp2Win         = 37|0x10000U, /**< XBAR0_OUT37 output assigned to PHD_CMP2_WIN */
    kXBAR0_OutputCmp0Win            = 38|0x10000U, /**< XBAR0_OUT38 output assigned to CMP0_WIN */
    kXBAR0_OutputCmp1Win            = 39|0x10000U, /**< XBAR0_OUT39 output assigned to CMP1_WIN */
    kXBAR0_OutputCmp0Trig           = 40|0x10000U, /**< XBAR0_OUT40 output assigned to CMP0_TRIG */
    kXBAR0_OutputCmp1Trig           = 41|0x10000U, /**< XBAR0_OUT41 output assigned to CMP1_TRIG */
    kXBAR0_OutputAdcaTrig           = 42|0x10000U, /**< XBAR0_OUT42 output assigned to ADCA_TRIG */
    kXBAR0_OutputAdcbTrig           = 43|0x10000U, /**< XBAR0_OUT43 output assigned to ADCB_TRIG */
    kXBAR0_OutputAoiSm0InputA       = 44|0x10000U, /**< XBAR0_OUT44 output assigned to AOI_SM0_INPUT_A */
    kXBAR0_OutputAoiSm0InputB       = 45|0x10000U, /**< XBAR0_OUT45 output assigned to AOI_SM0_INPUT_B */
    kXBAR0_OutputAoiSm0InputC       = 46|0x10000U, /**< XBAR0_OUT46 output assigned to AOI_SM0_INPUT_C */
    kXBAR0_OutputAoiSm0InputD       = 47|0x10000U, /**< XBAR0_OUT47 output assigned to AOI_SM0_INPUT_D */
    kXBAR0_OutputAoiSm1InputA       = 48|0x10000U, /**< XBAR0_OUT48 output assigned to AOI_SM1_INPUT_A */
    kXBAR0_OutputAoiSm1InputB       = 49|0x10000U, /**< XBAR0_OUT49 output assigned to AOI_SM1_INPUT_B */
    kXBAR0_OutputAoiSm1InputC       = 50|0x10000U, /**< XBAR0_OUT50 output assigned to AOI_SM1_INPUT_C */
    kXBAR0_OutputAoiSm1InputD       = 51|0x10000U, /**< XBAR0_OUT51 output assigned to AOI_SM1_INPUT_D */
    kXBAR0_OutputAoiSm2InputA       = 52|0x10000U, /**< XBAR0_OUT52 output assigned to AOI_SM2_INPUT_A */
    kXBAR0_OutputAoiSm2InputB       = 53|0x10000U, /**< XBAR0_OUT53 output assigned to AOI_SM2_INPUT_B */
    kXBAR0_OutputAoiSm2InputC       = 54|0x10000U, /**< XBAR0_OUT54 output assigned to AOI_SM2_INPUT_C */
    kXBAR0_OutputAoiSm2InputD       = 55|0x10000U, /**< XBAR0_OUT55 output assigned to AOI_SM2_INPUT_D */
    kXBAR0_OutputAoiSm3InputA       = 56|0x10000U, /**< XBAR0_OUT56 output assigned to AOI_SM3_INPUT_A */
    kXBAR0_OutputAoiSm3InputB       = 57|0x10000U, /**< XBAR0_OUT57 output assigned to AOI_SM3_INPUT_B */
    kXBAR0_OutputAoiSm3InputC       = 58|0x10000U, /**< XBAR0_OUT58 output assigned to AOI_SM3_INPUT_C */
    kXBAR0_OutputAoiSm3InputD       = 59|0x10000U, /**< XBAR0_OUT59 output assigned to AOI_SM3_INPUT_D */
    kXBAR0_OutputLpuart0TrigInput   = 60|0x10000U, /**< XBAR0_OUT60 output assigned to LPUART0_TRIG_INPUT */
    kXBAR0_OutputLpuart1TrigInput   = 61|0x10000U, /**< XBAR0_OUT61 output assigned to LPUART1_TRIG_INPUT */
    kXBAR0_OutputLpi2c0TrigInput    = 62|0x10000U, /**< XBAR0_OUT62 output assigned to LPI2C0_TRIG_INPUT */
    kXBAR0_OutputLpi2c1TrigInput    = 63|0x10000U, /**< XBAR0_OUT63 output assigned to LPI2C1_TRIG_INPUT */
    kXBAR0_OutputLpspi0TrigInput    = 64|0x10000U, /**< XBAR0_OUT64 output assigned to LPSPI0_TRIG_INPUT */
} xbar_output_signal_t;


/*!
 * @}
 */ /* end of group Mapping_Information */


/* AOI - Peripheral instance base addresses */
/** Peripheral AOI0 base address */
#define AOI0_BASE                                (0x40018000u)
/** Peripheral AOI0 base pointer */
#define AOI0                                     ((AOI_Type *)AOI0_BASE)
/** Array initializer of AOI peripheral base addresses */
#define AOI_BASE_ADDRS                           { AOI0_BASE }
/** Array initializer of AOI peripheral base pointers */
#define AOI_BASE_PTRS                            { AOI0 }

/* CMC - Peripheral instance base addresses */
/** Peripheral CMC base address */
#define CMC_BASE                                 (0x4000B000u)
/** Peripheral CMC base pointer */
#define CMC                                      ((CMC_Type *)CMC_BASE)
/** Array initializer of CMC peripheral base addresses */
#define CMC_BASE_ADDRS                           { CMC_BASE }
/** Array initializer of CMC peripheral base pointers */
#define CMC_BASE_PTRS                            { CMC }
/** Interrupt vectors for the CMC peripheral type */
#define CMC_IRQS                                 { CMC_IRQn }

/* CRC - Peripheral instance base addresses */
/** Peripheral CRC0 base address */
#define CRC0_BASE                                (0x4000A000u)
/** Peripheral CRC0 base pointer */
#define CRC0                                     ((CRC_Type *)CRC0_BASE)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC0_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC0 }

/* DADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x4002F000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((DADC_Type *)ADC0_BASE)
/** Array initializer of DADC peripheral base addresses */
#define DADC_BASE_ADDRS                          { ADC0_BASE }
/** Array initializer of DADC peripheral base pointers */
#define DADC_BASE_PTRS                           { ADC0 }

/* DEBUGMAILBOX - Peripheral instance base addresses */
/** Peripheral DBGMAILBOX base address */
#define DBGMAILBOX_BASE                          (0x40100000u)
/** Peripheral DBGMAILBOX base pointer */
#define DBGMAILBOX                               ((DEBUGMAILBOX_Type *)DBGMAILBOX_BASE)
/** Array initializer of DEBUGMAILBOX peripheral base addresses */
#define DEBUGMAILBOX_BASE_ADDRS                  { DBGMAILBOX_BASE }
/** Array initializer of DEBUGMAILBOX peripheral base pointers */
#define DEBUGMAILBOX_BASE_PTRS                   { DBGMAILBOX }

/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x40000000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           { DMA0_BASE }
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            { DMA0 }
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { DMA_CH0_IRQn, DMA_CH1_IRQn, DMA_CH2_IRQn, DMA_CH3_IRQn } }
#define DMA_ERROR_IRQS                           { { DMA_CH0_IRQn, DMA_CH1_IRQn, DMA_CH2_IRQn, DMA_CH3_IRQn } }

/* EIM - Peripheral instance base addresses */
/** Peripheral EIM0 base address */
#define EIM0_BASE                                (0x4000C000u)
/** Peripheral EIM0 base pointer */
#define EIM0                                     ((EIM_Type *)EIM0_BASE)
/** Array initializer of EIM peripheral base addresses */
#define EIM_BASE_ADDRS                           { EIM0_BASE }
/** Array initializer of EIM peripheral base pointers */
#define EIM_BASE_PTRS                            { EIM0 }

/* ERM - Peripheral instance base addresses */
/** Peripheral ERM0 base address */
#define ERM0_BASE                                (0x4000D000u)
/** Peripheral ERM0 base pointer */
#define ERM0                                     ((ERM_Type *)ERM0_BASE)
/** Array initializer of ERM peripheral base addresses */
#define ERM_BASE_ADDRS                           { ERM0_BASE }
/** Array initializer of ERM peripheral base pointers */
#define ERM_BASE_PTRS                            { ERM0 }

/* FMU - Peripheral instance base addresses */
/** Peripheral FMU0 base address */
#define FMU0_BASE                                (0x40015000u)
/** Peripheral FMU0 base pointer */
#define FMU0                                     ((FMU_Type *)FMU0_BASE)
/** Array initializer of FMU peripheral base addresses */
#define FMU_BASE_ADDRS                           { FMU0_BASE }
/** Array initializer of FMU peripheral base pointers */
#define FMU_BASE_PTRS                            { FMU0 }
/** Interrupt vectors for the FMU peripheral type */
#define FMU_IRQS                                 { FMU0_IRQn }

/* FMUTEST - Peripheral instance base addresses */
/** Peripheral FMU0TEST base address */
#define FMU0TEST_BASE                            (0x40016000u)
/** Peripheral FMU0TEST base pointer */
#define FMU0TEST                                 ((FMUTEST_Type *)FMU0TEST_BASE)
/** Array initializer of FMUTEST peripheral base addresses */
#define FMUTEST_BASE_ADDRS                       { FMU0TEST_BASE }
/** Array initializer of FMUTEST peripheral base pointers */
#define FMUTEST_BASE_PTRS                        { FMU0TEST }

/* FREQME - Peripheral instance base addresses */
/** Peripheral FREQME0 base address */
#define FREQME0_BASE                             (0x40009000u)
/** Peripheral FREQME0 base pointer */
#define FREQME0                                  ((FREQME_Type *)FREQME0_BASE)
/** Array initializer of FREQME peripheral base addresses */
#define FREQME_BASE_ADDRS                        { FREQME0_BASE }
/** Array initializer of FREQME peripheral base pointers */
#define FREQME_BASE_PTRS                         { FREQME0 }
/** Interrupt vectors for the FREQME peripheral type */
#define FREQME_IRQS                              { FREQME0_IRQn }

/* FTM - Peripheral instance base addresses */
/** Peripheral FTM0 base address */
#define FTM0_BASE                                (0x4002A000u)
/** Peripheral FTM0 base pointer */
#define FTM0                                     ((FTM_Type *)FTM0_BASE)
/** Array initializer of FTM peripheral base addresses */
#define FTM_BASE_ADDRS                           { FTM0_BASE }
/** Array initializer of FTM peripheral base pointers */
#define FTM_BASE_PTRS                            { FTM0 }

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO0 base address */
#define GPIO0_BASE                               (0x40073000u)
/** Peripheral GPIO0 base pointer */
#define GPIO0                                    ((GPIO_Type *)GPIO0_BASE)
/** Peripheral GPIO1 base address */
#define GPIO1_BASE                               (0x40074000u)
/** Peripheral GPIO1 base pointer */
#define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
/** Peripheral GPIO2 base address */
#define GPIO2_BASE                               (0x40075000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO3 base address */
#define GPIO3_BASE                               (0x40076000u)
/** Peripheral GPIO3 base pointer */
#define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIO0_BASE, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIO0, GPIO1, GPIO2, GPIO3 }
/** Interrupt vectors for the GPIO peripheral type */
#define GPIO_IRQS                                { GPIO0_IRQn, GPIO1_IRQn, GPIO2_IRQn, GPIO3_IRQn }

/* HSCMP - Peripheral instance base addresses */
/** Peripheral CMP0 base address */
#define CMP0_BASE                                (0x40031000u)
/** Peripheral CMP0 base pointer */
#define CMP0                                     ((HSCMP_Type *)CMP0_BASE)
/** Peripheral CMP1 base address */
#define CMP1_BASE                                (0x40032000u)
/** Peripheral CMP1 base pointer */
#define CMP1                                     ((HSCMP_Type *)CMP1_BASE)
/** Array initializer of HSCMP peripheral base addresses */
#define HSCMP_BASE_ADDRS                         { CMP0_BASE, CMP1_BASE }
/** Array initializer of HSCMP peripheral base pointers */
#define HSCMP_BASE_PTRS                          { CMP0, CMP1 }
/** Interrupt vectors for the HSCMP peripheral type */
#define HSCMP_IRQS                               { CMP0_IRQn, CMP1_IRQn }

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x4001A000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x4001B000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1 }
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_IRQn, LPI2C1_IRQn }

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x4001C000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0 }
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn }

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x4001F000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x40020000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1 }
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_IRQn, LPUART1_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_IRQn, LPUART1_IRQn }

/* MAU - Peripheral instance base addresses */
/** Peripheral MAU0 base address */
#define MAU0_BASE                                (0x40101000u)
/** Peripheral MAU0 base pointer */
#define MAU0                                     ((MAU_Type *)MAU0_BASE)
/** Array initializer of MAU peripheral base addresses */
#define MAU_BASE_ADDRS                           { MAU0_BASE }
/** Array initializer of MAU peripheral base pointers */
#define MAU_BASE_PTRS                            { MAU0 }

/* MRCC - Peripheral instance base addresses */
/** Peripheral MRCC base address */
#define MRCC_BASE                                (0x40011800u)
/** Peripheral MRCC base pointer */
#define MRCC                                     ((MRCC_Type *)MRCC_BASE)
/** Array initializer of MRCC peripheral base addresses */
#define MRCC_BASE_ADDRS                          { MRCC_BASE }
/** Array initializer of MRCC peripheral base pointers */
#define MRCC_BASE_PTRS                           { MRCC }

/* OPAMP - Peripheral instance base addresses */
/** Peripheral OPAMP0 base address */
#define OPAMP0_BASE                              (0x40037000u)
/** Peripheral OPAMP0 base pointer */
#define OPAMP0                                   ((OPAMP_Type *)OPAMP0_BASE)
/** Array initializer of OPAMP peripheral base addresses */
#define OPAMP_BASE_ADDRS                         { OPAMP0_BASE }
/** Array initializer of OPAMP peripheral base pointers */
#define OPAMP_BASE_PTRS                          { OPAMP0 }

/* PHD - Peripheral instance base addresses */
/** Peripheral PHD0 base address */
#define PHD0_BASE                                (0x40036000u)
/** Peripheral PHD0 base pointer */
#define PHD0                                     ((PHD_Type *)PHD0_BASE)
/** Array initializer of PHD peripheral base addresses */
#define PHD_BASE_ADDRS                           { PHD0_BASE }
/** Array initializer of PHD peripheral base pointers */
#define PHD_BASE_PTRS                            { PHD0 }

/* PIT - Peripheral instance base addresses */
/** Peripheral PIT0 base address */
#define PIT0_BASE                                (0x4002D000u)
/** Peripheral PIT0 base pointer */
#define PIT0                                     ((PIT_Type *)PIT0_BASE)
/** Array initializer of PIT peripheral base addresses */
#define PIT_BASE_ADDRS                           { PIT0_BASE }
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            { PIT0 }

/* PORT - Peripheral instance base addresses */
/** Peripheral PORT0 base address */
#define PORT0_BASE                               (0x4003C000u)
/** Peripheral PORT0 base pointer */
#define PORT0                                    ((PORT_Type *)PORT0_BASE)
/** Peripheral PORT1 base address */
#define PORT1_BASE                               (0x4003D000u)
/** Peripheral PORT1 base pointer */
#define PORT1                                    ((PORT_Type *)PORT1_BASE)
/** Peripheral PORT2 base address */
#define PORT2_BASE                               (0x4003E000u)
/** Peripheral PORT2 base pointer */
#define PORT2                                    ((PORT_Type *)PORT2_BASE)
/** Peripheral PORT3 base address */
#define PORT3_BASE                               (0x4003F000u)
/** Peripheral PORT3 base pointer */
#define PORT3                                    ((PORT_Type *)PORT3_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORT0_BASE, PORT1_BASE, PORT2_BASE, PORT3_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORT0, PORT1, PORT2, PORT3 }

/* PWM - Peripheral instance base addresses */
/** Peripheral FLEXPWM0 base address */
#define FLEXPWM0_BASE                            (0x40029000u)
/** Peripheral FLEXPWM0 base pointer */
#define FLEXPWM0                                 ((PWM_Type *)FLEXPWM0_BASE)
/** Array initializer of PWM peripheral base addresses */
#define PWM_BASE_ADDRS                           { FLEXPWM0_BASE }
/** Array initializer of PWM peripheral base pointers */
#define PWM_BASE_PTRS                            { FLEXPWM0 }
/** Interrupt vectors for the PWM peripheral type */
#define PWM_CMP_IRQS                             { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn, FLEXPWM0_SUBMODULE3_IRQn } }
#define PWM_RELOAD_IRQS                          { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn, FLEXPWM0_SUBMODULE3_IRQn } }
#define PWM_CAPTURE_IRQS                         { { FLEXPWM0_SUBMODULE0_IRQn, FLEXPWM0_SUBMODULE1_IRQn, FLEXPWM0_SUBMODULE2_IRQn, FLEXPWM0_SUBMODULE3_IRQn } }
#define PWM_FAULT_IRQS                           { FLEXPWM0_FAULT_IRQn }
#define PWM_RELOAD_ERROR_IRQS                    { FLEXPWM0_RELOAD_ERROR_IRQn }

/* PWT - Peripheral instance base addresses */
/** Peripheral PWT0 base address */
#define PWT0_BASE                                (0x4002B000u)
/** Peripheral PWT0 base pointer */
#define PWT0                                     ((PWT_Type *)PWT0_BASE)
/** Peripheral PWT1 base address */
#define PWT1_BASE                                (0x4002C000u)
/** Peripheral PWT1 base pointer */
#define PWT1                                     ((PWT_Type *)PWT1_BASE)
/** Array initializer of PWT peripheral base addresses */
#define PWT_BASE_ADDRS                           { PWT0_BASE, PWT1_BASE }
/** Array initializer of PWT peripheral base pointers */
#define PWT_BASE_PTRS                            { PWT0, PWT1 }

/* SCG - Peripheral instance base addresses */
/** Peripheral SCG0 base address */
#define SCG0_BASE                                (0x4000F000u)
/** Peripheral SCG0 base pointer */
#define SCG0                                     ((SCG_Type *)SCG0_BASE)
/** Array initializer of SCG peripheral base addresses */
#define SCG_BASE_ADDRS                           { SCG0_BASE }
/** Array initializer of SCG peripheral base pointers */
#define SCG_BASE_PTRS                            { SCG0 }
/** Interrupt vectors for the SCG peripheral type */
#define SCG_IRQS                                 { SCG0_IRQn }

/* SECCON - Peripheral instance base addresses */
/** Peripheral SECCON base address */
#define SECCON_BASE                              (0x40068000u)
/** Peripheral SECCON base pointer */
#define SECCON                                   ((SECCON_Type *)SECCON_BASE)
/** Array initializer of SECCON peripheral base addresses */
#define SECCON_BASE_ADDRS                        { SECCON_BASE }
/** Array initializer of SECCON peripheral base pointers */
#define SECCON_BASE_PTRS                         { SECCON }

/* SPC - Peripheral instance base addresses */
/** Peripheral SPC0 base address */
#define SPC0_BASE                                (0x40010000u)
/** Peripheral SPC0 base pointer */
#define SPC0                                     ((SPC_Type *)SPC0_BASE)
/** Array initializer of SPC peripheral base addresses */
#define SPC_BASE_ADDRS                           { SPC0_BASE }
/** Array initializer of SPC peripheral base pointers */
#define SPC_BASE_PTRS                            { SPC0 }

/* SYSCON - Peripheral instance base addresses */
/** Peripheral SYSCON base address */
#define SYSCON_BASE                              (0x40011000u)
/** Peripheral SYSCON base pointer */
#define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
/** Array initializer of SYSCON peripheral base addresses */
#define SYSCON_BASE_ADDRS                        { SYSCON_BASE }
/** Array initializer of SYSCON peripheral base pointers */
#define SYSCON_BASE_PTRS                         { SYSCON }

/* TMR - Peripheral instance base addresses */
/** Peripheral QTMR0 base address */
#define QTMR0_BASE                               (0x40028000u)
/** Peripheral QTMR0 base pointer */
#define QTMR0                                    ((TMR_Type *)QTMR0_BASE)
/** Array initializer of TMR peripheral base addresses */
#define TMR_BASE_ADDRS                           { QTMR0_BASE }
/** Array initializer of TMR peripheral base pointers */
#define TMR_BASE_PTRS                            { QTMR0 }

/* TRDC - Peripheral instance base addresses */
/** Peripheral MBC base address */
#define MBC_BASE                                 (0x4000E000u)
/** Peripheral MBC base pointer */
#define MBC                                      ((TRDC_Type *)MBC_BASE)
/** Array initializer of TRDC peripheral base addresses */
#define TRDC_BASE_ADDRS                          { MBC_BASE }
/** Array initializer of TRDC peripheral base pointers */
#define TRDC_BASE_PTRS                           { MBC }
/** Interrupt vectors for the TRDC peripheral type */
#define TRDC_IRQS                                { MBC0_IRQn }

/* VBAT - Peripheral instance base addresses */
/** Peripheral VBAT0 base address */
#define VBAT0_BASE                               (0x40013000u)
/** Peripheral VBAT0 base pointer */
#define VBAT0                                    ((VBAT_Type *)VBAT0_BASE)
/** Array initializer of VBAT peripheral base addresses */
#define VBAT_BASE_ADDRS                          { VBAT0_BASE }
/** Array initializer of VBAT peripheral base pointers */
#define VBAT_BASE_PTRS                           { VBAT0 }

/* WUU - Peripheral instance base addresses */
/** Peripheral WUU0 base address */
#define WUU0_BASE                                (0x40012000u)
/** Peripheral WUU0 base pointer */
#define WUU0                                     ((WUU_Type *)WUU0_BASE)
/** Array initializer of WUU peripheral base addresses */
#define WUU_BASE_ADDRS                           { WUU0_BASE }
/** Array initializer of WUU peripheral base pointers */
#define WUU_BASE_PTRS                            { WUU0 }
/** Interrupt vectors for the WUU peripheral type */
#define WUU_IRQS                                 { WUU0_IRQn }

/* WWDT - Peripheral instance base addresses */
/** Peripheral WWDT0 base address */
#define WWDT0_BASE                               (0x40067000u)
/** Peripheral WWDT0 base pointer */
#define WWDT0                                    ((WWDT_Type *)WWDT0_BASE)
/** Array initializer of WWDT peripheral base addresses */
#define WWDT_BASE_ADDRS                          { WWDT0_BASE }
/** Array initializer of WWDT peripheral base pointers */
#define WWDT_BASE_PTRS                           { WWDT0 }
/** Interrupt vectors for the WWDT peripheral type */
#define WWDT_IRQS                                { WWDT0_IRQn }

/* XBAR - Peripheral instance base addresses */
/** Peripheral XBAR0 base address */
#define XBAR0_BASE                               (0x40017000u)
/** Peripheral XBAR0 base pointer */
#define XBAR0                                    ((XBAR_Type *)XBAR0_BASE)
/** Array initializer of XBAR peripheral base addresses */
#define XBAR_BASE_ADDRS                          { XBAR0_BASE }
/** Array initializer of XBAR peripheral base pointers */
#define XBAR_BASE_PTRS                           { XBAR0 }

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


#endif  /* MCXC352_COMMON_H_ */

