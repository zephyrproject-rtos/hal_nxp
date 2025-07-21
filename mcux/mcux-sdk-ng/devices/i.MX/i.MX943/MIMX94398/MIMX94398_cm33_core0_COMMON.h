/*
** ###################################################################
**     Processors:          MIMX94398AVKE_cm33_core0
**                          MIMX94398AVKJ_cm33_core0
**                          MIMX94398AVKM_cm33_core0
**                          MIMX94398AVME_cm33_core0
**                          MIMX94398AVMJ_cm33_core0
**                          MIMX94398AVMM_cm33_core0
**                          MIMX94398CVKE_cm33_core0
**                          MIMX94398CVKJ_cm33_core0
**                          MIMX94398CVKM_cm33_core0
**                          MIMX94398CVME_cm33_core0
**                          MIMX94398CVMJ_cm33_core0
**                          MIMX94398CVMM_cm33_core0
**                          MIMX94398DVKE_cm33_core0
**                          MIMX94398DVKJ_cm33_core0
**                          MIMX94398DVKM_cm33_core0
**                          MIMX94398DVME_cm33_core0
**                          MIMX94398DVMJ_cm33_core0
**                          MIMX94398DVMM_cm33_core0
**                          MIMX94398XVKE_cm33_core0
**                          MIMX94398XVKJ_cm33_core0
**                          MIMX94398XVKM_cm33_core0
**                          MIMX94398XVME_cm33_core0
**                          MIMX94398XVMJ_cm33_core0
**                          MIMX94398XVMM_cm33_core0
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    iMX943RM rev1 draftK
**     Version:             rev. 1.0, 2023-11-01
**     Build:               b250115
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX94398_cm33_core0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
 * @file MIMX94398_cm33_core0_COMMON.h
 * @version 1.0
 * @date 2023-11-01
 * @brief CMSIS Peripheral Access Layer for MIMX94398_cm33_core0
 *
 * CMSIS Peripheral Access Layer for MIMX94398_cm33_core0
 */

#if !defined(MIMX94398_CM33_CORE0_COMMON_H_)
#define MIMX94398_CM33_CORE0_COMMON_H_           /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 807                /**< Number of interrupts in the Vector table */

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
  Reserved16_IRQn              = 0,                /**< Reserved interrupt */
  Reserved17_IRQn              = 1,                /**< DAP interrupt */
  Reserved18_IRQn              = 2,                /**< CTI trigger outputs from CM7 platform */
  Reserved19_IRQn              = 3,                /**< CTI trigger outputs from CM33 platform */
  Reserved20_IRQn              = 4,                /**< CTI trigger outputs from CA55 platform */
  Reserved21_IRQn              = 5,                /**< Performance Unit Interrupts from CA55 platform */
  Reserved22_IRQn              = 6,                /**< ECC error from CA55 platform cache */
  Reserved23_IRQn              = 7,                /**< 1-bit or 2-bit ECC or Parity error from CA55 platform cache */
  Reserved24_IRQn              = 8,                /**< CTI trigger outputs from CM7_1 platform */
  Reserved25_IRQn              = 9,                /**< CTI trigger outputs from CM33_sync platform */
  CAN1_IRQn                    = 10,               /**< CAN1 interrupt */
  CAN1_ERROR_IRQn              = 11,               /**< CAN1 error interrupt */
  GPIO1_INT0_IRQn              = 12,               /**< General Purpose Input/Output 1 interrupt 0 */
  GPIO1_INT1_IRQn              = 13,               /**< General Purpose Input/Output 1 interrupt 1 */
  I3C1_IRQn                    = 14,               /**< Improved Inter-Integrated Circuit 1 interrupt */
  LPI2C1_IRQn                  = 15,               /**< Low Power Inter-Integrated Circuit module 1 */
  LPI2C2_IRQn                  = 16,               /**< Low Power Inter-Integrated Circuit module 2 */
  LPIT1_IRQn                   = 17,               /**< Low Power Periodic Interrupt Timer 1 */
  LPSPI1_IRQn                  = 18,               /**< Low Power Serial Peripheral Interface 1 */
  LPSPI2_IRQn                  = 19,               /**< Low Power Serial Peripheral Interface 2 */
  LPTMR1_IRQn                  = 20,               /**< Low Power Timer 1 */
  LPUART1_IRQn                 = 21,               /**< Low Power UART 1 */
  LPUART2_IRQn                 = 22,               /**< Low Power UART 2 */
  Reserved39_IRQn              = 23,               /**< AONMIX Sentinel MU0 SideA interrupt */
  Reserved40_IRQn              = 24,               /**< AONMIX Sentinel MU1 SideA interrupt */
  Reserved41_IRQn              = 25,               /**< AONMIX Sentinel MU2 SideA interrupt */
  Reserved42_IRQn              = 26,               /**< AONMIX Sentinel MU3 SideA interrupt */
  Reserved43_IRQn              = 27,               /**< AONMIX Sentinel MU4 SideA interrupt */
  Reserved44_IRQn              = 28,               /**< AONMIX Sentinel MU5 SideA interrupt */
  Reserved45_IRQn              = 29,               /**< AONMIX Sentinel MU6 SideA interrupt */
  Reserved46_IRQn              = 30,               /**< AONMIX Sentinel MU7 SideA interrupt */
  Reserved47_IRQn              = 31,               /**< AONMIX Sentinel MU8 SideA interrupt */
  V2X_FH_APCH0_IRQn            = 32,               /**< V2X-FH MU APCH0 (APP0) interrupt */
  V2X_FH_APHSM1_IRQn           = 33,               /**< V2X-FH MU APHSM1 (HSM1) interrupt */
  TPM1_IRQn                    = 34,               /**< Timer PWM module 1 */
  TPM2_IRQn                    = 35,               /**< Timer PWM module 2 */
  WDOG1_IRQn                   = 36,               /**< Watchdog 1 Interrupt */
  WDOG2_IRQn                   = 37,               /**< Watchdog 2 Interrupt */
  SAI1_IRQn                    = 38,               /**< Serial Audio Interface 1 */
  GPT1_IRQn                    = 39,               /**< AONMIX GPT1 */
  CAN2_IRQn                    = 40,               /**< WAKEUPMIX CAN2 interrupt */
  CAN2_ERROR_IRQn              = 41,               /**< WAKEUPMIX CAN2 error interrupt */
  CAN3_IRQn                    = 42,               /**< WAKEUPMIX CAN3 interrupt */
  CAN3_ERROR_IRQn              = 43,               /**< WAKEUPMIX CAN3 error interrupt */
  CAN4_IRQn                    = 44,               /**< WAKEUPMIX CAN4 interrupt */
  CAN4_ERROR_IRQn              = 45,               /**< WAKEUPMIX CAN4 error interrupt */
  CAN5_IRQn                    = 46,               /**< WAKEUPMIX CAN5 interrupt */
  CAN5_ERROR_IRQn              = 47,               /**< WAKEUPMIX CAN5 error interrupt */
  FLEXIO1_IRQn                 = 48,               /**< WAKEUPMIX Flexible IO 1 interrupt */
  FLEXIO2_IRQn                 = 49,               /**< WAKEUPMIX Flexible IO 2 interrupt */
  FLEXIO3_IRQn                 = 50,               /**< NETCMIX Flexible IO 3 interrupt */
  FLEXIO4_IRQn                 = 51,               /**< NETCMIX Flexible IO 4 interrupt */
  Reserved68_IRQn              = 52,               /**< Earlier assigned for WAKEUPMIX XSPI1 interrupt */
  Reserved69_IRQn              = 53,               /**< Earlier assigned for WAKEUPMIX XSPI2 interrupt */
  GPIO2_INT0_IRQn              = 54,               /**< WAKEUPMIX General Purpose Input/Output 2 interrupt 0 */
  GPIO2_INT1_IRQn              = 55,               /**< WAKEUPMIX General Purpose Input/Output 2 interrupt 1 */
  GPIO3_INT0_IRQn              = 56,               /**< WAKEUPMIX General Purpose Input/Output 3 interrupt 0 */
  GPIO3_INT1_IRQn              = 57,               /**< WAKEUPMIX General Purpose Input/Output 3 interrupt 1 */
  GPIO4_INT0_IRQn              = 58,               /**< WAKEUPMIX General Purpose Input/Output 4 interrupt 0 */
  GPIO4_INT1_IRQn              = 59,               /**< WAKEUPMIX General Purpose Input/Output 4 interrupt 1 */
  GPIO5_INT0_IRQn              = 60,               /**< WAKEUPMIX General Purpose Input/Output 5 interrupt 0 */
  GPIO5_INT1_IRQn              = 61,               /**< WAKEUPMIX General Purpose Input/Output 5 interrupt 1 */
  GPIO6_INT0_IRQn              = 62,               /**< WAKEUPMIX General Purpose Input/Output 6 interrupt 0 */
  GPIO6_INT1_IRQn              = 63,               /**< WAKEUPMIX General Purpose Input/Output 6 interrupt 1 */
  GPIO7_INT0_IRQn              = 64,               /**< WAKEUPMIX General Purpose Input/Output 7 interrupt 0 */
  GPIO7_INT1_IRQn              = 65,               /**< WAKEUPMIX General Purpose Input/Output 7 interrupt 1 */
  I3C2_IRQn                    = 66,               /**< WAKEUPMIX Improved Inter-Integrated Circuit 2 interrupt */
  LPI2C3_IRQn                  = 67,               /**< WAKEUPMIX Low Power Inter-Integrated Circuit module 3 */
  LPI2C4_IRQn                  = 68,               /**< WAKEUPMIX Low Power Inter-Integrated Circuit module 4 */
  LPIT2_IRQn                   = 69,               /**< WAKEUPMIX Low Power Periodic Interrupt Timer 2 */
  LPIT3_IRQn                   = 70,               /**< WAKEUPMIX Low Power Periodic Interrupt Timer 3 */
  LPSPI3_IRQn                  = 71,               /**< WAKEUPMIX Low Power Serial Peripheral Interface 3 */
  LPSPI4_IRQn                  = 72,               /**< WAKEUPMIX Low Power Serial Peripheral Interface 4 */
  LPTMR2_IRQn                  = 73,               /**< WAKEUPMIX Low Power Timer 2 */
  LPUART3_IRQn                 = 74,               /**< WAKEUPMIX Low Power UART 3 */
  LPUART4_IRQn                 = 75,               /**< WAKEUPMIX Low Power UART 4 */
  LPUART5_IRQn                 = 76,               /**< WAKEUPMIX Low Power UART 5 */
  LPUART6_IRQn                 = 77,               /**< WAKEUPMIX Low Power UART 6 */
  LPUART7_IRQn                 = 78,               /**< WAKEUPMIX Low Power UART 7 */
  LPUART8_IRQn                 = 79,               /**< WAKEUPMIX Low Power UART 8 */
  LPUART9_IRQn                 = 80,               /**< WAKEUPMIX Low Power UART 9 */
  LPUART10_IRQn                = 81,               /**< WAKEUPMIX Low Power UART 10 */
  LPUART11_IRQn                = 82,               /**< WAKEUPMIX Low Power UART 11 */
  LPUART12_IRQn                = 83,               /**< WAKEUPMIX Low Power UART 12 */
  BBNSM_IRQn                   = 84,               /**< BBNSM Non-Secure interrupt */
  SYSCTR1_IRQn                 = 85,               /**< AONMIX System Counter compare interrupt */
  TPM3_IRQn                    = 86,               /**< WAKEUPMIX Timer PWM module 3 */
  TPM4_IRQn                    = 87,               /**< WAKEUPMIX Timer PWM module 4 */
  TPM5_IRQn                    = 88,               /**< WAKEUPMIX Timer PWM module 5 */
  TPM6_IRQn                    = 89,               /**< WAKEUPMIX Timer PWM module 6 */
  WDOG3_IRQn                   = 90,               /**< WAKEUPMIX Watchdog 3 Interrupt */
  WDOG4_IRQn                   = 91,               /**< WAKEUPMIX Watchdog 4 Interrupt */
  WDOG5_IRQn                   = 92,               /**< WAKEUPMIX Watchdog 5 Interrupt */
  WDOG6_IRQn                   = 93,               /**< WAKEUPMIX Watchdog 6 Interrupt */
  WDOG7_IRQn                   = 94,               /**< NETCMIX Watchdog 7 Interrupt */
  WDOG8_IRQn                   = 95,               /**< NETCMIX Watchdog 8 Interrupt */
  USDHC1_IRQn                  = 96,               /**< MEGAMIX uSDHC1 Enhanced SDHC Interrupt Request */
  USDHC2_IRQn                  = 97,               /**< MEGAMIX uSDHC2 Enhanced SDHC Interrupt Request */
  EDMA2_ERROR_IRQn             = 98,               /**< WAKEUPMIX EDMA2 error interrupt */
  Reserved115_IRQn             = 99,               /**< JTAGSW DAP MDM-AP SRC reset source */
  Reserved116_IRQn             = 100,              /**< JTAGC SRC reset source (the JTAGC used for boundary scan, not JTAGC used for password authentication) */
  SAI2_IRQn                    = 101,              /**< WAKEUPMIX SAI2 interrupt */
  SAI3_IRQn                    = 102,              /**< WAKEUPMIX SAI3 interrupt */
  SAI4_IRQn                    = 103,              /**< WAKEUPMIX SAI4 interrupt */
  LPSPI5_IRQn                  = 104,              /**< WAKEUPMIX LPSPI5 interrupt */
  LPSPI6_IRQn                  = 105,              /**< WAKEUPMIX LPSPI6 interrupt */
  LPSPI7_IRQn                  = 106,              /**< WAKEUPMIX LPSPI7 interrupt */
  LPSPI8_IRQn                  = 107,              /**< WAKEUPMIX LPSPI8 interrupt */
  LPI2C5_IRQn                  = 108,              /**< WAKEUPMIX LPI2C5 interrupt */
  LPI2C6_IRQn                  = 109,              /**< WAKEUPMIX LPI2C6 interrupt */
  LPI2C7_IRQn                  = 110,              /**< WAKEUPMIX LPI2C7 interrupt */
  LPI2C8_IRQn                  = 111,              /**< WAKEUPMIX LPI2C8 interrupt */
  PDM_HWVAD_ERROR_IRQn         = 112,              /**< WAKEUPMIX PDM interrupt(hwvad err) */
  PDM_HWVAD_EVENT_IRQn         = 113,              /**< WAKEUPMIX PDM interrupt(hwvad event) */
  PDM_ERROR_IRQn               = 114,              /**< WAKEUPMIX PDM interrupt(mic err) */
  PDM_EVENT_IRQn               = 115,              /**< WAKEUPMIX PDM interrupt(mic event) */
  USDHC3_IRQn                  = 116,              /**< MEGAMIX uSDHC3 Enhanced SDHC Interrupt Request */
  ADC_ER_IRQn                  = 117,              /**< WAKEUPMIX ADC1 interrupt(er) */
  ADC_WD_IRQn                  = 118,              /**< WAKEUPMIX ADC1 interrupt(wd) */
  ADC_EOC_IRQn                 = 119,              /**< WAKEUPMIX ADC1 interrupt(eoc) */
  Reserved136_IRQn             = 120,              /**< I3C1 wakeup irq after double sync */
  Reserved137_IRQn             = 121,              /**< I3C2 wakeup irq after double sync */
  MU5_A_IRQn                   = 122,              /**< AONMIX MU5 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU6_A_IRQn                   = 123,              /**< AONMIX MU6 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU7_A_IRQn                   = 124,              /**< AONMIX MU7 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU10_B_IRQn                  = 125,              /**< WAKEUPMIX MU10 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU11_B_IRQn                  = 126,              /**< WAKEUPMIX MU11 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU12_A_IRQn                  = 127,              /**< WAKEUPMIX MU12 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU13_A_IRQn                  = 128,              /**< WAKEUPMIX MU13 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU18_A_IRQn                  = 129,              /**< WAKEUPMIX MU18 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU18_B_IRQn                  = 130,              /**< WAKEUPMIX MU18 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU_E1_A_IRQn                 = 131,              /**< NETCMIX MU E1 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_E2_A_IRQn                 = 132,              /**< NETCMIX MU E2 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_E3_A_IRQn                 = 133,              /**< NETCMIX MU E3 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_E4_A_IRQn                 = 134,              /**< NETCMIX MU E4 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  XSPI_SLV_IRQn                = 135,              /**< WAKEUPMIX XSPI Responder */
  FCCU_INT0_IRQn               = 136,              /**< AONMIX FCCU Interrupt Reaction 0 */
  FCCU_INT1_IRQn               = 137,              /**< AONMIX FCCU Interrupt Reaction 1 */
  FCCU_INT2_IRQn               = 138,              /**< AONMIX FCCU Interrupt Reaction 2 */
  FCCU_INT3_IRQn               = 139,              /**< AONMIX FCCU Interrupt Reaction 3(new interrupt for CM33_sync) */
  FCCU_INT4_IRQn               = 140,              /**< AONMIX FCCU Interrupt Reaction 4(new interrupt for CM7_1) */
  STCU_IRQn                    = 141,              /**< AONMIX STCU Selftest end Interrupt */
  XBAR1_CH0_CH1_IRQn           = 142,              /**< XBAR1 interrupt 0 and 1 */
  XBAR1_CH2_CH3_IRQn           = 143,              /**< XBAR1 interrupt 2 and 3 */
  GPT2_IRQn                    = 144,              /**< WAKEUPMIX GPT2 interrupt */
  GPT3_IRQn                    = 145,              /**< WAKEUPMIX GPT3 interrupt */
  GPT4_IRQn                    = 146,              /**< WAKEUPMIX GPT4 interrupt */
  Reserved163_IRQn             = 147,              /**< Endat2_1 interrupt/Hiperface1-DSL interrupt for safe events logged in EVENT_S register/Endat3 interrupt for background communication */
  Reserved164_IRQn             = 148,              /**< Hiperface1-DSL interrupt for events logged in EVENT_H or EVENT_L register/Endat3 interrupt */
  Reserved165_IRQn             = 149,              /**< Endat2_2  interrupt/Hiperface2-DSL interrupt for safe events logged in EVENT_S register/Biss interrupt for start of frame transmission */
  Reserved166_IRQn             = 150,              /**< Hiperface2-DSL interrupt for events logged in EVENT_H or EVENT_L register/Biss interrupt for end of frame transmission */
  Reserved167_IRQn             = 151,              /**< Flexpwm1(reload error, fault condition) */
  Reserved168_IRQn             = 152,              /**< Flexpwm1(capt0, comp0, reload0) */
  Reserved169_IRQn             = 153,              /**< Flexpwm1(capt1, comp1, reload1) */
  Reserved170_IRQn             = 154,              /**< Flexpwm1(capt2, comp2, reload2) */
  Reserved171_IRQn             = 155,              /**< Flexpwm1(capt3, comp3, reload3) */
  Reserved172_IRQn             = 156,              /**< Flexpwm2(reload error, fault condition) */
  Reserved173_IRQn             = 157,              /**< Flexpwm2(capt0, comp0, reload0) */
  Reserved174_IRQn             = 158,              /**< Flexpwm2(capt1, comp1, reload1) */
  Reserved175_IRQn             = 159,              /**< Flexpwm2(capt2, comp2, reload2) */
  Reserved176_IRQn             = 160,              /**< Flexpwm2(capt3, comp3, reload3) */
  Reserved177_IRQn             = 161,              /**< Flexpwm3(reload error, fault condition) */
  Reserved178_IRQn             = 162,              /**< Flexpwm3(capt0, comp0, reload0) */
  Reserved179_IRQn             = 163,              /**< Flexpwm3(capt1, comp1, reload1) */
  Reserved180_IRQn             = 164,              /**< Flexpwm3(capt2, comp2, reload2) */
  Reserved181_IRQn             = 165,              /**< Flexpwm3(capt3, comp3, reload3) */
  Reserved182_IRQn             = 166,              /**< Flexpwm4(reload error, fault condition) */
  Reserved183_IRQn             = 167,              /**< Flexpwm4(capt0, comp0, reload0) */
  Reserved184_IRQn             = 168,              /**< Flexpwm4(capt1, comp1, reload1) */
  Reserved185_IRQn             = 169,              /**< Flexpwm4(capt2, comp2, reload2) */
  Reserved186_IRQn             = 170,              /**< Flexpwm4(capt3, comp3, reload3) */
  ENC1_IRQn                    = 171,              /**< Quad dec1 interrupt */
  ENC2_IRQn                    = 172,              /**< Quad dec2 interrupt */
  ENC3_IRQn                    = 173,              /**< Quad dec3 interrupt */
  ENC4_IRQn                    = 174,              /**< Quad dec4 interrupt */
  EWM_IRQn                     = 175,              /**< Ewm out interrupt */
  Reserved192_IRQn             = 176,              /**< Ethercat interrupt(PDI_OPB) */
  Reserved193_IRQn             = 177,              /**< Ethercat interrupt(RESET_OUT) */
  Reserved194_IRQn             = 178,              /**< Ethercat interrupt(SYNC_OUT0) */
  Reserved195_IRQn             = 179,              /**< Ethercat interrupt(SYNC_OUT1) */
  USB1_IRQn                    = 180,              /**< USB-1(USB 3.0 Controller) interrupt */
  USB2_IRQn                    = 181,              /**< USB-2(USB 2.0 Controller) interrupt */
  SINC1_CH0_IRQn               = 182,              /**< SINC Filter1(sinc filter glue1) Channel 0 interrupt */
  SINC1_CH1_IRQn               = 183,              /**< SINC Filter1(sinc filter glue1) Channel 1 interrupt */
  SINC1_CH2_IRQn               = 184,              /**< SINC Filter1(sinc filter glue1) Channel 2 interrupt */
  SINC1_CH3_IRQn               = 185,              /**< SINC Filter1(sinc filter glue1) Channel 3 interrupt */
  SINC2_CH0_IRQn               = 186,              /**< SINC Filter2(sinc filter glue2) Channel 0 interrupt */
  SINC2_CH1_IRQn               = 187,              /**< SINC Filter2(sinc filter glue2) Channel 1 interrupt */
  SINC2_CH2_IRQn               = 188,              /**< SINC Filter2(sinc filter glue2) Channel 2 interrupt */
  SINC2_CH3_IRQn               = 189,              /**< SINC Filter2(sinc filter glue2) Channel 3 interrupt */
  SINC3_CH0_IRQn               = 190,              /**< SINC Filter3(sinc filter glue3 Channel 0 interrupt */
  SINC3_CH1_IRQn               = 191,              /**< SINC Filter3(sinc filter glue3) Channel 1 interrupt */
  SINC3_CH2_IRQn               = 192,              /**< SINC Filter3(sinc filter glue3) Channel 2 interrupt */
  SINC3_CH3_IRQn               = 193,              /**< SINC Filter3(sinc filter glue3) Channel 3 interrupt */
  SINC4_CH0_IRQn               = 194,              /**< SINC Filter4(sinc filter glue4 Channel 0 interrupt */
  SINC4_CH1_IRQn               = 195,              /**< SINC Filter4(sinc filter glue4) Channel 1 interrupt */
  SINC4_CH2_IRQn               = 196,              /**< SINC Filter4(sinc filter glue4) Channel 2 interrupt */
  SINC4_CH3_IRQn               = 197,              /**< SINC Filter4(sinc filter glue4) Channel 3 interrupt */
  TMR1_IRQn                    = 198,              /**< QTIMER1 interrupt */
  TMR2_IRQn                    = 199,              /**< QTIMER2 interrupt */
  TMR3_IRQn                    = 200,              /**< QTIMER3 interrupt */
  TMR4_IRQn                    = 201,              /**< QTIMER4 interrupt */
  TMR5_IRQn                    = 202,              /**< QTIMER5 interrupt */
  TMR6_IRQn                    = 203,              /**< QTIMER6 interrupt */
  TMR7_IRQn                    = 204,              /**< QTIMER7 interrupt */
  TMR8_IRQn                    = 205,              /**< QTIMER8 interrupt */
  EDMA4_ERROR_IRQn             = 206,              /**< EDMA4 error interrupt */
  Reserved223_IRQn             = 207,              /**< Anamix Gllitch Detector output (da_ip_voltage_glitch_detector_cln16ffc). It's a latch signal. It can be cleared. */
  Reserved224_IRQn             = 208,              /**< Anamix VDET output (da_ip_vdetect_c16ffc). Detects high threshold on Core supply. It's a latch signal. It can be cleared. */
  Reserved225_IRQn             = 209,              /**< Anamix VDET output (da_ip_vdetect_c16ffc). Detects Low threshold on Core supply. It's a latch signal. It can be cleared */
  Reserved226_IRQn             = 210,              /**< LPCG Timeout interrupt generated by CCGR (CCM) */
  Reserved227_IRQn             = 211,              /**< Reserved227 */
  Reserved228_IRQn             = 212,              /**< Reserved228 */
  Reserved229_IRQn             = 213,              /**< Reserved229 */
  Reserved230_IRQn             = 214,              /**< Reserved230 */
  Reserved231_IRQn             = 215,              /**< Reserved231 */
  Reserved232_IRQn             = 216,              /**< Reserved232 */
  Reserved233_IRQn             = 217,              /**< Reserved233 */
  Reserved234_IRQn             = 218,              /**< Reserved234 */
  Reserved235_IRQn             = 219,              /**< Reserved235 */
  Reserved236_IRQn             = 220,              /**< Reserved236 */
  Reserved237_IRQn             = 221,              /**< Reserved237 */
  Reserved238_IRQn             = 222,              /**< Reserved238 */
  Reserved239_IRQn             = 223,              /**< Reserved239 */
  IRQSTEERM33_CH0_IRQn         = 224,              /**< IRQSTEERM33 output channel 0 interrupt */
  IRQSTEERM33_CH1_IRQn         = 225,              /**< IRQSTEERM33 output channel 1 interrupt */
  IRQSTEERM33_CH2_IRQn         = 226,              /**< IRQSTEERM33 output channel 2 interrupt */
  IRQSTEERM33_CH3_IRQn         = 227,              /**< IRQSTEERM33 output channel 3 interrupt */
  IRQSTEERM33_CH4_IRQn         = 228,              /**< IRQSTEERM33 output channel 4 interrupt */
  IRQSTEERM33_CH5_IRQn         = 229,              /**< IRQSTEERM33 output channel 5 interrupt */
  EDMA1_CH0_IRQn               = 230,              /**< WAKEUPMIX EDMA1 channel 0 interrupt */
  EDMA1_CH1_IRQn               = 231,              /**< WAKEUPMIX EDMA1 channel 1 interrupt */
  EDMA1_CH2_IRQn               = 232,              /**< WAKEUPMIX EDMA1 channel 2 interrupt */
  EDMA1_CH3_IRQn               = 233,              /**< WAKEUPMIX EDMA1 channel 3 interrupt */
  EDMA1_CH4_IRQn               = 234,              /**< WAKEUPMIX EDMA1 channel 4 interrupt */
  EDMA1_CH5_IRQn               = 235,              /**< WAKEUPMIX EDMA1 channel 5 interrupt */
  EDMA1_CH6_IRQn               = 236,              /**< WAKEUPMIX EDMA1 channel 6 interrupt */
  EDMA1_CH7_IRQn               = 237,              /**< WAKEUPMIX EDMA1 channel 7 interrupt */
  EDMA1_CH8_IRQn               = 238,              /**< WAKEUPMIX EDMA1 channel 8 interrupt */
  EDMA1_CH9_IRQn               = 239,              /**< WAKEUPMIX EDMA1 channel 9 interrupt */
  EDMA1_CH10_IRQn              = 240,              /**< WAKEUPMIX EDMA1 channel 10 interrupt */
  EDMA1_CH11_IRQn              = 241,              /**< WAKEUPMIX EDMA1 channel 11 interrupt */
  EDMA1_CH12_IRQn              = 242,              /**< WAKEUPMIX EDMA1 channel 12 interrupt */
  EDMA1_CH13_IRQn              = 243,              /**< WAKEUPMIX EDMA1 channel 13 interrupt */
  EDMA1_CH14_IRQn              = 244,              /**< WAKEUPMIX EDMA1 channel 14 interrupt */
  EDMA1_CH15_IRQn              = 245,              /**< WAKEUPMIX EDMA1 channel 15 interrupt */
  EDMA1_CH16_IRQn              = 246,              /**< WAKEUPMIX EDMA1 channel 16 interrupt */
  EDMA1_CH17_IRQn              = 247,              /**< WAKEUPMIX EDMA1 channel 17 interrupt */
  EDMA1_CH18_IRQn              = 248,              /**< WAKEUPMIX EDMA1 channel 18 interrupt */
  EDMA1_CH19_IRQn              = 249,              /**< WAKEUPMIX EDMA1 channel 19 interrupt */
  EDMA1_CH20_IRQn              = 250,              /**< WAKEUPMIX EDMA1 channel 20 interrupt */
  EDMA1_CH21_IRQn              = 251,              /**< WAKEUPMIX EDMA1 channel 21 interrupt */
  EDMA1_CH22_IRQn              = 252,              /**< WAKEUPMIX EDMA1 channel 22 interrupt */
  EDMA1_CH23_IRQn              = 253,              /**< WAKEUPMIX EDMA1 channel 23 interrupt */
  EDMA1_CH24_IRQn              = 254,              /**< WAKEUPMIX EDMA1 channel 24 interrupt */
  EDMA1_CH25_IRQn              = 255,              /**< WAKEUPMIX EDMA1 channel 25 interrupt */
  EDMA1_CH26_IRQn              = 256,              /**< WAKEUPMIX EDMA1 channel 26 interrupt */
  EDMA1_CH27_IRQn              = 257,              /**< WAKEUPMIX EDMA1 channel 27 interrupt */
  EDMA1_CH28_IRQn              = 258,              /**< WAKEUPMIX EDMA1 channel 28 interrupt */
  EDMA1_CH29_IRQn              = 259,              /**< WAKEUPMIX EDMA1 channel 29 interrupt */
  EDMA1_CH30_IRQn              = 260,              /**< WAKEUPMIX EDMA1 channel 30 interrupt */
  EDMA1_CH31_IRQn              = 261,              /**< WAKEUPMIX EDMA1 channel 31 interrupt */
  MU1_A_IRQn                   = 262,              /**< AONMIX MU1 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU1_B_IRQn                   = 263,              /**< AONMIX MU1 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU2_A_IRQn                   = 264,              /**< AONMIX MU2 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU2_B_IRQn                   = 265,              /**< AONMIX MU2 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU3_A_IRQn                   = 266,              /**< AONMIX MU3 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU3_B_IRQn                   = 267,              /**< AONMIX MU3 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU4_A_IRQn                   = 268,              /**< AONMIX MU4 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU4_B_IRQn                   = 269,              /**< AONMIX MU4 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU5_B_IRQn                   = 270,              /**< AONMIX MU5 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU6_B_IRQn                   = 271,              /**< AONMIX MU6 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU7_B_IRQn                   = 272,              /**< AONMIX MU7 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU8_A_IRQn                   = 273,              /**< AONMIX MU8 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU8_B_IRQn                   = 274,              /**< AONMIX MU8 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU9_A_IRQn                   = 275,              /**< AONMIX MU9 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU9_B_IRQn                   = 276,              /**< AONMIX MU9 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU10_A_IRQn                  = 277,              /**< WAKEUPMIX MU10 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU11_A_IRQn                  = 278,              /**< WAKEUPMIX MU11 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU12_B_IRQn                  = 279,              /**< WAKEUPMIX MU12 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU13_B_IRQn                  = 280,              /**< WAKEUPMIX MU13 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU14_A_IRQn                  = 281,              /**< WAKEUPMIX MU14 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU14_B_IRQn                  = 282,              /**< WAKEUPMIX MU14 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU15_A_IRQn                  = 283,              /**< WAKEUPMIX MU15 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU15_B_IRQn                  = 284,              /**< WAKEUPMIX MU15 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU16_A_IRQn                  = 285,              /**< WAKEUPMIX MU16 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU16_B_IRQn                  = 286,              /**< WAKEUPMIX MU16 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU17_A_IRQn                  = 287,              /**< WAKEUPMIX MU17 Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU17_B_IRQn                  = 288,              /**< WAKEUPMIX MU17 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU_E1_B_IRQn                 = 289,              /**< NETCMIX MU E1 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU_E2_B_IRQn                 = 290,              /**< NETCMIX MU E2 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU_E3_B_IRQn                 = 291,              /**< NETCMIX MU E3 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU_E4_B_IRQn                 = 292,              /**< NETCMIX MU E4 Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MSGINTR1_IRQn                = 293,              /**< MSGINTR Instance 1 Interrupt */
  MSGINTR2_IRQn                = 294,              /**< MSGINTR Instance 2 Interrupt */
  MSGINTR3_IRQn                = 295,              /**< MSGINTR Instance 3 Interrupt */
  MSGINTR4_IRQn                = 296,              /**< MSGINTR Instance 4 Interrupt */
  MSGINTR5_IRQn                = 297,              /**< MSGINTR Instance 5 Interrupt */
  MSGINTR6_IRQn                = 298,              /**< MSGINTR Instance 6 Interrupt */
  MSGINTR7_IRQn                = 299,              /**< MSGINTR Instance 7 Interrupt */
  MSGINTR8_IRQn                = 300,              /**< MSGINTR Instance 8 Interrupt */
  V2X_FH_MU_APCH1_IRQn         = 301,              /**< V2X-FH MU APCH1 (APP1) interrupt */
  V2X_FH_MU_APHSM2_IRQn        = 302,              /**< V2X-FH MU APHSM2 (HSM2) interrupt */
  Reserved319_IRQn             = 303,              /**< Sentinel Group 1 reset source if no s500 reference clock is detected.  Output synchronized to 32khz clk. New signal name for i.MX943 is s4v1_fdet0_tclk_err_irq. (Cause Reset) */
  Reserved320_IRQn             = 304,              /**< Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk the S500 clock. New signal name for i.MX943 is s4v1_fdet2_tclk_err_irq.  (Reset Request in CM33 domain) */
  Reserved321_IRQn             = 305,              /**< Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk. New signal name for i.MX943 is s4v1_fdet3_tclk_err_irq */
  Reserved322_IRQn             = 306,              /**< Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to S500 clock domain. New signal name for i.MX943 is s4v1_fdet1_tclk_err_irq */
  Reserved323_IRQn             = 307,              /**< s500 glue logic IRQ */
  GPC_SM_REQ_IRQn              = 308,              /**< SRC/GPC Low Power Handshake Gasket interrupt request for system management */
  EDMA1_ERROR_IRQn             = 309,              /**< AONMIX EDMA1 error interrupt */
  Reserved326_IRQn             = 310,              /**< AONMIX TRDC transfer error interrupt */
  Reserved327_IRQn             = 311,              /**< WAKEUPMIX TRDC-MGR1 transfer error interrupt */
  Reserved328_IRQn             = 312,              /**< MEGAMIX TRDC transfer error interrupt */
  Reserved329_IRQn             = 313,              /**< NOCMIX TRDC transfer error interrupt */
  Reserved330_IRQn             = 314,              /**< DISPLAYMIX TRDC transfer error interrupt */
  Reserved331_IRQn             = 315,              /**< NETCMIX TRDC/NET_M33_Sync Platform transfer error interrupt */
  Reserved332_IRQn             = 316,              /**< HSIOMIX TRDC transfer error interrupt */
  Reserved333_IRQn             = 317,              /**< WAKEUPMIX TRDC-MGR2 transfer error interrupt */
  Reserved334_IRQn             = 318,              /**< AONMIX ERM Single bit corrected ECC error */
  Reserved335_IRQn             = 319,              /**< M7MIX0 ERM Single bit corrected ECC error */
  Reserved336_IRQn             = 320,              /**< M7MIX1 ERM Single bit corrected ECC error */
  Reserved337_IRQn             = 321,              /**< WAKEUPMIX ERM Single bit corrected ECC error */
  Reserved338_IRQn             = 322,              /**< NPUMIX ERM Single bit corrected ECC error */
  Reserved339_IRQn             = 323,              /**< NETCMIX ERM Single bit corrected ECC error */
  Reserved340_IRQn             = 324,              /**< OCRAM ECC multi bit error */
  Reserved341_IRQn             = 325,              /**< AONMIX MTR Master error interrupt */
  EDMA3_ERROR_IRQn             = 326,              /**< EDMA3 DMA error interrupt */
  Reserved343_IRQn             = 327,              /**< AONMIX M33 PS Tag/Data parity error */
  M33_TCM_ERROR_IRQn           = 328,              /**< AONMIX M33 TCM error interrupt */
  Reserved345_IRQn             = 329,              /**< M7MIX ECC multi bit error */
  Reserved346_IRQn             = 330,              /**< NETCMIX M33 PS Tag/Data parity error */
  M33_SYNC_TCM_ERROR_IRQn      = 331,              /**< NETCMIX M33 TCM error interrupt */
  ONE_POINT_FIVE_MB_OCRAM_ERROR_IRQn = 332,        /**< NETCMIX 1.5MB OCSRAM Error interrupt */
  Reserved349_IRQn             = 333,              /**< M7MIX1 ECC Multi-bit error */
  GIC700_FAULT_IRQn            = 334,              /**< GIC700 Fault(Uncorrectable ECC errors) */
  M33_MCM_IRQn                 = 335,              /**< CM33 MCM interrupt */
  M33_SYNC_MCM_IRQn            = 336,              /**< CM33_sync MCM interrupt */
  ONE_POINT_FIVE_MB_SRAM_MCM_IRQn = 337,           /**< NETCMIX 1.5MB SRAM MCM interrupt */
  M7MIX0_MCM_IRQn              = 338,              /**< M7MIX0 MCM interrupt */
  M7MIX1_MCM_IRQn              = 339,              /**< M7MIX1 MCM interrupt */
  OCRAM_ECC_SINGLE_BIT_ERROR_IRQn = 340,           /**< OCRAM ECC single bit error */
  GIC700_ERROR_IRQn            = 341,              /**< GIC700 Error(Correctable ECC errors) */
  SFA_IRQn                     = 342,              /**< ANAMIX SFA(Signal Frequency Analyzer) interrupt */
  TMPSNS_THR1_IRQn             = 343,              /**< ANAMIX TempSensor non-secure interrupt from Threshold 1 */
  TMPSNS_THR2_IRQn             = 344,              /**< ANAMIX TempSensor non-secure interrupt from Threshold 2 */
  Reserved361_IRQn             = 345,              /**< ANAMIX TempSensor non-secure data ready interrupt */
  Reserved362_IRQn             = 346,              /**< CORTEXAMIX TempSensor non-secure interrupt from Threshold 1 */
  Reserved363_IRQn             = 347,              /**< CORTEXAMIX TempSensor non-secure interrupt from Threshold 2 */
  Reserved364_IRQn             = 348,              /**< CORTEXAMIX TempSensor non-secure data ready interrupt */
  CM33_0_SYSRESETREQ_IRQn      = 349,              /**< AONMIX CM33 SYSREQRST SRC reset source */
  CM33_0_LOCKUP_IRQn           = 350,              /**< AONMIX CM33 LOCKUP SRC reset source */
  CM7_0_SYSRESETREQ_IRQn       = 351,              /**< CM7_0 SYSREQRST SRC reset source */
  CM7_0_LOCKUP_IRQn            = 352,              /**< CM7_0 LOCKUP SRC reset source */
  CM33_1_SYSRESETREQ_IRQn      = 353,              /**< NETCMIX CM33_sync SYSREQRST SRC reset source */
  CM33_1_LOCKUP_IRQn           = 354,              /**< NETCMIX CM33_sync LOCKUP SRC reset source */
  CM7_1_SYSRESETREQ_IRQn       = 355,              /**< CM7_1 SYSREQRST SRC reset source */
  CM7_1_LOCKUP_IRQn            = 356,              /**< CM7_1 LOCKUP SRC reset source */
  SOC_RESET_WO_NETC_IRQn       = 357,              /**< SoC reset without netc interrupt */
  Reserved374_IRQn             = 358,              /**< NETC iEPRC PCI INT (one per each of two RC-EC, first one) */
  Reserved375_IRQn             = 359,              /**< NETC iEPRC PCI INT (one per each of two RC-EC, second one) */
  PCIE1_INTA_IRQn              = 360,              /**< PCIe Controller 1 INTA */
  PCIE1_INTB_IRQn              = 361,              /**< PCIe Controller 1 INTB */
  PCIE1_INTC_IRQn              = 362,              /**< PCIe Controller 1 INTC */
  PCIE1_INTD_IRQn              = 363,              /**< PCIe Controller 1 INTD */
  Reserved380_IRQn             = 364,              /**< PCIe 1 miscellaneous interrupts/PCIe MSI reception interrupt for RC mode/PCIe Link reset request interrupt */
  Reserved381_IRQn             = 365,              /**< PCIe Controller 1 EDMA channel interrupt */
  PCIE2_INTA_IRQn              = 366,              /**< PCIe Controller 2 INTA */
  PCIE2_INTB_IRQn              = 367,              /**< PCIe Controller 2 INTB */
  PCIE2_INTC_IRQn              = 368,              /**< PCIe Controller 2 INTC */
  PCIE2_INTD_IRQn              = 369,              /**< PCIe Controller 2 INTD */
  Reserved386_IRQn             = 370,              /**< PCIe 2 miscellaneous interrupts/PCIe MSI reception interrupt for RC mode/PCIe Link reset request interrupt */
  Reserved387_IRQn             = 371,              /**< PCIe Controller 2 EDMA channel interrupt */
  Reserved388_IRQn             = 372,              /**< NPUMIX Wakeup interrupt from CLKREQ#, WAKEUP#, BEACON_DET */
  NPUMIX_FUNC_IRQn             = 373,              /**< NPUMIX Functional interrupt */
  Reserved390_IRQn             = 374,              /**< DRAM controller Performance Monitor Interrupt */
  Reserved391_IRQn             = 375,              /**< DRAM controller Critical Interrupt */
  Reserved392_IRQn             = 376,              /**< DRAM Phy Critical Interrupt 0~15 */
  DCIF_CPU_DOMAIN0_IRQn        = 377,              /**< DISPLAYMIX DCIF: Interrupt output for CPU domain0 (Controlled by common registers group) */
  DCIF_CPU_DOMAIN1_IRQn        = 378,              /**< DISPLAYMIX DCIF: Interrupt output for CPU domain1 (Controlled by background layer registers group) */
  DCIF_CPU_DOMAIN2_IRQn        = 379,              /**< DISPLAYMIX DCIF: Interrupt output for CPU domain2 (Controlled by foreground layer registers group) */
  Reserved396_IRQn             = 380,              /**< Reserved */
  Reserved397_IRQn             = 381,              /**< Reserved */
  PXP_0_IRQn                   = 382,              /**< DISPLAYMIX PXP interrupt 0 */
  PXP_1_IRQn                   = 383,              /**< DISPLAYMIX PXP interrupt 1 */
  Reserved400_IRQn             = 384,              /**< V2X-FH MU APSHE (SHE) A_TX/A_RX interrupt */
  Reserved401_IRQn             = 385,              /**< V2X-FH MU SCU/APDEBUG (DEBUG) B_TX/B_RX interrupt */
  Reserved402_IRQn             = 386,              /**< USB-1 (USB 3.0) Wake-up Interrupt */
  Reserved403_IRQn             = 387,              /**< USB-2 (USB 2.0) Wake-up Interrupt */
  Reserved404_IRQn             = 388,              /**< GIC700 PMU Counter Overflow */
  Reserved405_IRQn             = 389,              /**< Reserved */
  XSPI1_IRQn                   = 390,              /**< xspi1 all interrupts ORed output for EENV0 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV0/xspi1 arbitration win interrupt for EENV0/xspi1 FlashA error interrupt for EENV0 */
  Reserved407_IRQn             = 391,              /**< xspi1 all interrupts ORed output for EENV1 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV1/xspi1 arbitration lock timeout interrupt for EENV1/xspi1 arbitration win interrupt for EENV1/xspi1 FlashA error interrupt for EENV1 */
  Reserved408_IRQn             = 392,              /**< xspi1 all interrupts ORed output for EENV2 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV2/        xspi1 arbitration win interrupt for EENV2/xspi1 FlashA error interrupt for EENV2 */
  Reserved409_IRQn             = 393,              /**< xspi1 all interrupts ORed output for EENV3 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV3/xspi1 arbitration win interrupt for EENV3/xspi1 FlashA error interrupt for EENV3 */
  Reserved410_IRQn             = 394,              /**< xspi1 all interrupts ORed output for EENV4 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV4/xspi1 arbitration win interrupt for EENV4/xspi1 FlashA error interrupt for EENV4 */
  XSPI2_IRQn                   = 395,              /**< xspi2 all interrupts ORed output for EENV0 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV0/xspi2 arbitration lock timeout interrupt for EENV0/xspi2 arbitration win interrupt for EENV0/xspi2 FlashA error interrupt for EENV0 */
  Reserved412_IRQn             = 396,              /**< xspi2 all interrupts ORed output for EENV1 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV1/xspi2 arbitration lock timeout interrupt for EENV1/xspi2 arbitration win interrupt for EENV1/xspi2 FlashA error interrupt for EENV1 */
  Reserved413_IRQn             = 397,              /**< xspi2 all interrupts ORed output for EENV2 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV2/xspi2 arbitration win interrupt for EENV2/xspi2 FlashA error interrupt for EENV2 */
  Reserved414_IRQn             = 398,              /**< xspi2 all interrupts ORed output for EENV3 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV3/xspi2 arbitration win interrupt for EENV3/xspi2 FlashA error interrupt for EENV3 */
  Reserved415_IRQn             = 399,              /**< xspi2 all interrupts ORed output for EENV4 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV4/xspi2 arbitration win interrupt for EENV4/xspi2 FlashA error interrupt for EENV4 */
  Reserved416_IRQn             = 400,              /**< Reserved */
  Reserved417_IRQn             = 401,              /**< Reserved */
  Reserved418_IRQn             = 402,              /**< Reserved */
  Reserved419_IRQn             = 403,              /**< Reserved */
  Reserved420_IRQn             = 404,              /**< Reserved */
  Reserved421_IRQn             = 405,              /**< Reserved */
  Reserved422_IRQn             = 406,              /**< Global fault event Module=NETC IRQ=406 */
  EDMA2_CH0_IRQn               = 407,              /**< WAKEUPMIX EDMA2 channel 0 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[0] - inputs[0]) IRQ=407 */
  EDMA2_CH1_IRQn               = 408,              /**< WAKEUPMIX EDMA2 channel 1 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[1] - inputs[1]) IRQ=408 */
  EDMA2_CH2_IRQn               = 409,              /**< WAKEUPMIX EDMA2 channel 2 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[2] - inputs[2]) IRQ=409 */
  EDMA2_CH3_IRQn               = 410,              /**< WAKEUPMIX EDMA2 channel 3 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[3] - inputs[3]) IRQ=410 */
  EDMA2_CH4_IRQn               = 411,              /**< WAKEUPMIX EDMA2 channel 4 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[4] - inputs[4]) IRQ=411 */
  EDMA2_CH5_IRQn               = 412,              /**< WAKEUPMIX EDMA2 channel 5 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[5] - inputs[5]) IRQ=412 */
  EDMA2_CH6_IRQn               = 413,              /**< WAKEUPMIX EDMA2 channel 6 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[6] - inputs[6]) IRQ=413 */
  EDMA2_CH7_IRQn               = 414,              /**< WAKEUPMIX EDMA2 channel 7 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[7] - inputs[7]) IRQ=414 */
  EDMA2_CH8_IRQn               = 415,              /**< WAKEUPMIX EDMA2 channel 8 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[8] - inputs[8]) IRQ=415 */
  EDMA2_CH9_IRQn               = 416,              /**< WAKEUPMIX EDMA2 channel 9 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[9] - inputs[9]) IRQ=416 */
  EDMA2_CH10_IRQn              = 417,              /**< WAKEUPMIX EDMA2 channel 10 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[10] - inputs[10]) IRQ=417 */
  EDMA2_CH11_IRQn              = 418,              /**< WAKEUPMIX EDMA2 channel 11 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[11] - inputs[11]) IRQ=418 */
  EDMA2_CH12_IRQn              = 419,              /**< WAKEUPMIX EDMA2 channel 12 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[12] - inputs[12]) IRQ=419 */
  EDMA2_CH13_IRQn              = 420,              /**< WAKEUPMIX EDMA2 channel 13 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[13] - inputs[13]) IRQ=420 */
  EDMA2_CH14_IRQn              = 421,              /**< WAKEUPMIX EDMA2 channel 14 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[14] - inputs[14]) IRQ=421 */
  EDMA2_CH15_IRQn              = 422,              /**< WAKEUPMIX EDMA2 channel 15 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[15] - inputs[15]) IRQ=422 */
  EDMA2_CH16_IRQn              = 423,              /**< WAKEUPMIX EDMA2 channel 16 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[16] - inputs[16]) IRQ=423 */
  EDMA2_CH17_IRQn              = 424,              /**< WAKEUPMIX EDMA2 channel 17 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[17] - inputs[17]) IRQ=424 */
  EDMA2_CH18_IRQn              = 425,              /**< WAKEUPMIX EDMA2 channel 18 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[18] - inputs[18]) IRQ=425 */
  EDMA2_CH19_IRQn              = 426,              /**< WAKEUPMIX EDMA2 channel 19 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[19] - inputs[19]) IRQ=426 */
  EDMA2_CH20_IRQn              = 427,              /**< WAKEUPMIX EDMA2 channel 20 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[20] - inputs[20]) IRQ=427 */
  EDMA2_CH21_IRQn              = 428,              /**< WAKEUPMIX EDMA2 channel 21 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[21] - inputs[21]) IRQ=428 */
  EDMA2_CH22_IRQn              = 429,              /**< WAKEUPMIX EDMA2 channel 22 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[22] - inputs[22]) IRQ=429 */
  EDMA2_CH23_IRQn              = 430,              /**< WAKEUPMIX EDMA2 channel 23 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[23] - inputs[23]) IRQ=430 */
  EDMA2_CH24_IRQn              = 431,              /**< WAKEUPMIX EDMA2 channel 24 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[24] - inputs[24]) IRQ=431 */
  EDMA2_CH25_IRQn              = 432,              /**< WAKEUPMIX EDMA2 channel 25 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[25] - inputs[25]) IRQ=432 */
  EDMA2_CH26_IRQn              = 433,              /**< WAKEUPMIX EDMA2 channel 26 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[26] - inputs[26]) IRQ=433 */
  EDMA2_CH27_IRQn              = 434,              /**< WAKEUPMIX EDMA2 channel 27 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[27] - inputs[27]) IRQ=434 */
  EDMA2_CH28_IRQn              = 435,              /**< WAKEUPMIX EDMA2 channel 28 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[28] - inputs[28]) IRQ=435 */
  EDMA2_CH29_IRQn              = 436,              /**< WAKEUPMIX EDMA2 channel 29 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[29] - inputs[29]) IRQ=436 */
  EDMA2_CH30_IRQn              = 437,              /**< WAKEUPMIX EDMA2 channel 30 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[30] - inputs[30]) IRQ=437 */
  EDMA2_CH31_IRQn              = 438,              /**< WAKEUPMIX EDMA2 channel 31 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[31] - inputs[31]) IRQ=438 */
  Reserved455_IRQn             = 439,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[32]) IRQ=439 */
  Reserved456_IRQn             = 440,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[33]) IRQ=440 */
  Reserved457_IRQn             = 441,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[34]) IRQ=441 */
  Reserved458_IRQn             = 442,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[35]) IRQ=442 */
  Reserved459_IRQn             = 443,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[36]) IRQ=443 */
  Reserved460_IRQn             = 444,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[37]) IRQ=444 */
  Reserved461_IRQn             = 445,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[38]) IRQ=445 */
  Reserved462_IRQn             = 446,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[39]) IRQ=446 */
  Reserved463_IRQn             = 447,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[40]) IRQ=447 */
  Reserved464_IRQn             = 448,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[41]) IRQ=448 */
  Reserved465_IRQn             = 449,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[42]) IRQ=449 */
  Reserved466_IRQn             = 450,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[43]) IRQ=450 */
  Reserved467_IRQn             = 451,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[44]) IRQ=451 */
  Reserved468_IRQn             = 452,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[45]) IRQ=452 */
  Reserved469_IRQn             = 453,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[46]) IRQ=453 */
  Reserved470_IRQn             = 454,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[47]) IRQ=454 */
  Reserved471_IRQn             = 455,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[48]) IRQ=455 */
  Reserved472_IRQn             = 456,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[49]) IRQ=456 */
  Reserved473_IRQn             = 457,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[50]) IRQ=457 */
  Reserved474_IRQn             = 458,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[51]) IRQ=458 */
  Reserved475_IRQn             = 459,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[52]) IRQ=459 */
  Reserved476_IRQn             = 460,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[53]) IRQ=460 */
  Reserved477_IRQn             = 461,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[54]) IRQ=461 */
  Reserved478_IRQn             = 462,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[55]) IRQ=462 */
  Reserved479_IRQn             = 463,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[56]) IRQ=463 */
  Reserved480_IRQn             = 464,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[57]) IRQ=464 */
  Reserved481_IRQn             = 465,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[58]) IRQ=465 */
  Reserved482_IRQn             = 466,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[59]) IRQ=466 */
  Reserved483_IRQn             = 467,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[60]) IRQ=467 */
  Reserved484_IRQn             = 468,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[61]) IRQ=468 */
  Reserved485_IRQn             = 469,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[62]) IRQ=469 */
  Reserved486_IRQn             = 470,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[63]) IRQ=470 */
  EDMA2_CH32_IRQn              = 471,              /**< WAKEUPMIX EDMA2 channel 32 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[0] - inputs[64]) IRQ=471 */
  EDMA2_CH33_IRQn              = 472,              /**< WAKEUPMIX EDMA2 channel 33 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[1] - inputs[65]) IRQ=472 */
  EDMA2_CH34_IRQn              = 473,              /**< WAKEUPMIX EDMA2 channel 34 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[2] - inputs[66]) IRQ=473 */
  EDMA2_CH35_IRQn              = 474,              /**< WAKEUPMIX EDMA2 channel 35 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[3] - inputs[67]) IRQ=474 */
  EDMA2_CH36_IRQn              = 475,              /**< WAKEUPMIX EDMA2 channel 36 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[4] - inputs[68]) IRQ=475 */
  EDMA2_CH37_IRQn              = 476,              /**< WAKEUPMIX EDMA2 channel 37 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[5] - inputs[69]) IRQ=476 */
  EDMA2_CH38_IRQn              = 477,              /**< WAKEUPMIX EDMA2 channel 38 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[6] - inputs[70]) IRQ=477 */
  EDMA2_CH39_IRQn              = 478,              /**< WAKEUPMIX EDMA2 channel 39 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[7] - inputs[71]) IRQ=478 */
  EDMA2_CH40_IRQn              = 479,              /**< WAKEUPMIX EDMA2 channel 40 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[8] - inputs[72]) IRQ=479 */
  EDMA2_CH41_IRQn              = 480,              /**< WAKEUPMIX EDMA2 channel 41 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[9] - inputs[73]) IRQ=480 */
  EDMA2_CH42_IRQn              = 481,              /**< WAKEUPMIX EDMA2 channel 42 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[10] - inputs[74]) IRQ=481 */
  EDMA2_CH43_IRQn              = 482,              /**< WAKEUPMIX EDMA2 channel 43 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[11] - inputs[75]) IRQ=482 */
  EDMA2_CH44_IRQn              = 483,              /**< WAKEUPMIX EDMA2 channel 44 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[12] - inputs[76]) IRQ=483 */
  EDMA2_CH45_IRQn              = 484,              /**< WAKEUPMIX EDMA2 channel 45 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[13] - inputs[77]) IRQ=484 */
  EDMA2_CH46_IRQn              = 485,              /**< WAKEUPMIX EDMA2 channel 46 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[14] - inputs[78]) IRQ=485 */
  EDMA2_CH47_IRQn              = 486,              /**< WAKEUPMIX EDMA2 channel 47 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[15] - inputs[79]) IRQ=486 */
  EDMA2_CH48_IRQn              = 487,              /**< WAKEUPMIX EDMA2 channel 48 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[16] - inputs[80]) IRQ=487 */
  EDMA2_CH49_IRQn              = 488,              /**< WAKEUPMIX EDMA2 channel 49 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[17] - inputs[81]) IRQ=488 */
  EDMA2_CH50_IRQn              = 489,              /**< WAKEUPMIX EDMA2 channel 50 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[18] - inputs[82]) IRQ=489 */
  EDMA2_CH51_IRQn              = 490,              /**< WAKEUPMIX EDMA2 channel 51 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[19] - inputs[83]) IRQ=490 */
  EDMA2_CH52_IRQn              = 491,              /**< WAKEUPMIX EDMA2 channel 52 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[20] - inputs[84]) IRQ=491 */
  EDMA2_CH53_IRQn              = 492,              /**< WAKEUPMIX EDMA2 channel 53 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[21] - inputs[85]) IRQ=492 */
  EDMA2_CH54_IRQn              = 493,              /**< WAKEUPMIX EDMA2 channel 54 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[22] - inputs[86]) IRQ=493 */
  EDMA2_CH55_IRQn              = 494,              /**< WAKEUPMIX EDMA2 channel 55 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[23] - inputs[87]) IRQ=494 */
  EDMA2_CH56_IRQn              = 495,              /**< WAKEUPMIX EDMA2 channel 56 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[24] - inputs[88]) IRQ=495 */
  EDMA2_CH57_IRQn              = 496,              /**< WAKEUPMIX EDMA2 channel 57 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[25] - inputs[89]) IRQ=496 */
  EDMA2_CH58_IRQn              = 497,              /**< WAKEUPMIX EDMA2 channel 58 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[26] - inputs[90]) IRQ=497 */
  EDMA2_CH59_IRQn              = 498,              /**< WAKEUPMIX EDMA2 channel 59 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[27] - inputs[91]) IRQ=498 */
  EDMA2_CH60_IRQn              = 499,              /**< WAKEUPMIX EDMA2 channel 60 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[28] - inputs[92]) IRQ=499 */
  EDMA2_CH61_IRQn              = 500,              /**< WAKEUPMIX EDMA2 channel 61 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[29] - inputs[93]) IRQ=500 */
  EDMA2_CH62_IRQn              = 501,              /**< WAKEUPMIX EDMA2 channel 62 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[30] - inputs[94]) IRQ=501 */
  EDMA2_CH63_IRQn              = 502,              /**< WAKEUPMIX EDMA2 channel 63 interrupt Module=EDMA2 IRQSTEERM33 extend(bitoffset[31] - inputs[95]) IRQ=502 */
  Reserved519_IRQn             = 503,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[96]) IRQ=503 */
  Reserved520_IRQn             = 504,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[97]) IRQ=504 */
  Reserved521_IRQn             = 505,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[98]) IRQ=505 */
  Reserved522_IRQn             = 506,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[99]) IRQ=506 */
  Reserved523_IRQn             = 507,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[100]) IRQ=507 */
  Reserved524_IRQn             = 508,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[101]) IRQ=508 */
  Reserved525_IRQn             = 509,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[102]) IRQ=509 */
  Reserved526_IRQn             = 510,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[103]) IRQ=510 */
  Reserved527_IRQn             = 511,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[104]) IRQ=511 */
  Reserved528_IRQn             = 512,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[105]) IRQ=512 */
  Reserved529_IRQn             = 513,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[106]) IRQ=513 */
  Reserved530_IRQn             = 514,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[107]) IRQ=514 */
  Reserved531_IRQn             = 515,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[108]) IRQ=515 */
  Reserved532_IRQn             = 516,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[109]) IRQ=516 */
  Reserved533_IRQn             = 517,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[110]) IRQ=517 */
  Reserved534_IRQn             = 518,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[111]) IRQ=518 */
  Reserved535_IRQn             = 519,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[112]) IRQ=519 */
  Reserved536_IRQn             = 520,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[113]) IRQ=520 */
  Reserved537_IRQn             = 521,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[114]) IRQ=521 */
  Reserved538_IRQn             = 522,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[115]) IRQ=522 */
  Reserved539_IRQn             = 523,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[116]) IRQ=523 */
  Reserved540_IRQn             = 524,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[117]) IRQ=524 */
  Reserved541_IRQn             = 525,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[118]) IRQ=525 */
  Reserved542_IRQn             = 526,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[119]) IRQ=526 */
  Reserved543_IRQn             = 527,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[120]) IRQ=527 */
  Reserved544_IRQn             = 528,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[121]) IRQ=528 */
  Reserved545_IRQn             = 529,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[122]) IRQ=529 */
  Reserved546_IRQn             = 530,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[123]) IRQ=530 */
  Reserved547_IRQn             = 531,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[124]) IRQ=531 */
  Reserved548_IRQn             = 532,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[125]) IRQ=532 */
  Reserved549_IRQn             = 533,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[126]) IRQ=533 */
  Reserved550_IRQn             = 534,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[127]) IRQ=534 */
  EDMA4_CH0_IRQn               = 535,              /**< WAKEUPMIX EDMA4 channel 0 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[0] - inputs[128]) IRQ=535 */
  EDMA4_CH1_IRQn               = 536,              /**< WAKEUPMIX EDMA4 channel 1 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[1] - inputs[129]) IRQ=536 */
  EDMA4_CH2_IRQn               = 537,              /**< WAKEUPMIX EDMA4 channel 2 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[2] - inputs[130]) IRQ=537 */
  EDMA4_CH3_IRQn               = 538,              /**< WAKEUPMIX EDMA4 channel 3 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[3] - inputs[131]) IRQ=538 */
  EDMA4_CH4_IRQn               = 539,              /**< WAKEUPMIX EDMA4 channel 4 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[4] - inputs[132]) IRQ=539 */
  EDMA4_CH5_IRQn               = 540,              /**< WAKEUPMIX EDMA4 channel 5 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[5] - inputs[133]) IRQ=540 */
  EDMA4_CH6_IRQn               = 541,              /**< WAKEUPMIX EDMA4 channel 6 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[6] - inputs[134]) IRQ=541 */
  EDMA4_CH7_IRQn               = 542,              /**< WAKEUPMIX EDMA4 channel 7 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[7] - inputs[135]) IRQ=542 */
  EDMA4_CH8_IRQn               = 543,              /**< WAKEUPMIX EDMA4 channel 8 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[8] - inputs[136]) IRQ=543 */
  EDMA4_CH9_IRQn               = 544,              /**< WAKEUPMIX EDMA4 channel 9 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[9] - inputs[137]) IRQ=544 */
  EDMA4_CH10_IRQn              = 545,              /**< WAKEUPMIX EDMA4 channel 10 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[10] - inputs[138]) IRQ=545 */
  EDMA4_CH11_IRQn              = 546,              /**< WAKEUPMIX EDMA4 channel 11 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[11] - inputs[139]) IRQ=546 */
  EDMA4_CH12_IRQn              = 547,              /**< WAKEUPMIX EDMA4 channel 12 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[12] - inputs[140]) IRQ=547 */
  EDMA4_CH13_IRQn              = 548,              /**< WAKEUPMIX EDMA4 channel 13 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[13] - inputs[141]) IRQ=548 */
  EDMA4_CH14_IRQn              = 549,              /**< WAKEUPMIX EDMA4 channel 14 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[14] - inputs[142]) IRQ=549 */
  EDMA4_CH15_IRQn              = 550,              /**< WAKEUPMIX EDMA4 channel 15 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[15] - inputs[143]) IRQ=550 */
  EDMA4_CH16_IRQn              = 551,              /**< WAKEUPMIX EDMA4 channel 16 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[16] - inputs[144]) IRQ=551 */
  EDMA4_CH17_IRQn              = 552,              /**< WAKEUPMIX EDMA4 channel 17 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[17] - inputs[145]) IRQ=552 */
  EDMA4_CH18_IRQn              = 553,              /**< WAKEUPMIX EDMA4 channel 18 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[18] - inputs[146]) IRQ=553 */
  EDMA4_CH19_IRQn              = 554,              /**< WAKEUPMIX EDMA4 channel 19 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[19] - inputs[147]) IRQ=554 */
  EDMA4_CH20_IRQn              = 555,              /**< WAKEUPMIX EDMA4 channel 20 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[20] - inputs[148]) IRQ=555 */
  EDMA4_CH21_IRQn              = 556,              /**< WAKEUPMIX EDMA4 channel 21 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[21] - inputs[149]) IRQ=556 */
  EDMA4_CH22_IRQn              = 557,              /**< WAKEUPMIX EDMA4 channel 22 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[22] - inputs[150]) IRQ=557 */
  EDMA4_CH23_IRQn              = 558,              /**< WAKEUPMIX EDMA4 channel 23 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[23] - inputs[151]) IRQ=558 */
  EDMA4_CH24_IRQn              = 559,              /**< WAKEUPMIX EDMA4 channel 24 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[24] - inputs[152]) IRQ=559 */
  EDMA4_CH25_IRQn              = 560,              /**< WAKEUPMIX EDMA4 channel 25 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[25] - inputs[153]) IRQ=560 */
  EDMA4_CH26_IRQn              = 561,              /**< WAKEUPMIX EDMA4 channel 26 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[26] - inputs[154]) IRQ=561 */
  EDMA4_CH27_IRQn              = 562,              /**< WAKEUPMIX EDMA4 channel 27 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[27] - inputs[155]) IRQ=562 */
  EDMA4_CH28_IRQn              = 563,              /**< WAKEUPMIX EDMA4 channel 28 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[28] - inputs[156]) IRQ=563 */
  EDMA4_CH29_IRQn              = 564,              /**< WAKEUPMIX EDMA4 channel 29 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[29] - inputs[157]) IRQ=564 */
  EDMA4_CH30_IRQn              = 565,              /**< WAKEUPMIX EDMA4 channel 30 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[30] - inputs[158]) IRQ=565 */
  EDMA4_CH31_IRQn              = 566,              /**< WAKEUPMIX EDMA4 channel 31 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[31] - inputs[159]) IRQ=566 */
  Reserved583_IRQn             = 567,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[160]) IRQ=567 */
  Reserved584_IRQn             = 568,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[161]) IRQ=568 */
  Reserved585_IRQn             = 569,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[162]) IRQ=569 */
  Reserved586_IRQn             = 570,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[163]) IRQ=570 */
  Reserved587_IRQn             = 571,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[164]) IRQ=571 */
  Reserved588_IRQn             = 572,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[165]) IRQ=572 */
  Reserved589_IRQn             = 573,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[166]) IRQ=573 */
  Reserved590_IRQn             = 574,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[167]) IRQ=574 */
  Reserved591_IRQn             = 575,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[168]) IRQ=575 */
  Reserved592_IRQn             = 576,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[169]) IRQ=576 */
  Reserved593_IRQn             = 577,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[170]) IRQ=577 */
  Reserved594_IRQn             = 578,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[171]) IRQ=578 */
  Reserved595_IRQn             = 579,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[172]) IRQ=579 */
  Reserved596_IRQn             = 580,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[173]) IRQ=580 */
  Reserved597_IRQn             = 581,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[174]) IRQ=581 */
  Reserved598_IRQn             = 582,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[175]) IRQ=582 */
  Reserved599_IRQn             = 583,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[176]) IRQ=583 */
  Reserved600_IRQn             = 584,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[177]) IRQ=584 */
  Reserved601_IRQn             = 585,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[178]) IRQ=585 */
  Reserved602_IRQn             = 586,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[179]) IRQ=586 */
  Reserved603_IRQn             = 587,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[180]) IRQ=587 */
  Reserved604_IRQn             = 588,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[181]) IRQ=588 */
  Reserved605_IRQn             = 589,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[182]) IRQ=589 */
  Reserved606_IRQn             = 590,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[183]) IRQ=590 */
  Reserved607_IRQn             = 591,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[184]) IRQ=591 */
  Reserved608_IRQn             = 592,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[185]) IRQ=592 */
  Reserved609_IRQn             = 593,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[186]) IRQ=593 */
  Reserved610_IRQn             = 594,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[187]) IRQ=594 */
  Reserved611_IRQn             = 595,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[188]) IRQ=595 */
  Reserved612_IRQn             = 596,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[189]) IRQ=596 */
  Reserved613_IRQn             = 597,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[190]) IRQ=597 */
  Reserved614_IRQn             = 598,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[191]) IRQ=598 */
  EDMA4_CH32_IRQn              = 599,              /**< WAKEUPMIX EDMA4 channel 32 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[0] - inputs[192]) IRQ=599 */
  EDMA4_CH33_IRQn              = 600,              /**< WAKEUPMIX EDMA4 channel 33 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[1] - inputs[193]) IRQ=600 */
  EDMA4_CH34_IRQn              = 601,              /**< WAKEUPMIX EDMA4 channel 34 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[2] - inputs[194]) IRQ=601 */
  EDMA4_CH35_IRQn              = 602,              /**< WAKEUPMIX EDMA4 channel 35 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[3] - inputs[195]) IRQ=602 */
  EDMA4_CH36_IRQn              = 603,              /**< WAKEUPMIX EDMA4 channel 36 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[4] - inputs[196]) IRQ=603 */
  EDMA4_CH37_IRQn              = 604,              /**< WAKEUPMIX EDMA4 channel 37 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[5] - inputs[197]) IRQ=604 */
  EDMA4_CH38_IRQn              = 605,              /**< WAKEUPMIX EDMA4 channel 38 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[6] - inputs[198]) IRQ=605 */
  EDMA4_CH39_IRQn              = 606,              /**< WAKEUPMIX EDMA4 channel 39 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[7] - inputs[199]) IRQ=606 */
  EDMA4_CH40_IRQn              = 607,              /**< WAKEUPMIX EDMA4 channel 40 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[8] - inputs[200]) IRQ=607 */
  EDMA4_CH41_IRQn              = 608,              /**< WAKEUPMIX EDMA4 channel 41 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[9] - inputs[201]) IRQ=608 */
  EDMA4_CH42_IRQn              = 609,              /**< WAKEUPMIX EDMA4 channel 42 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[10] - inputs[202]) IRQ=609 */
  EDMA4_CH43_IRQn              = 610,              /**< WAKEUPMIX EDMA4 channel 43 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[11] - inputs[203]) IRQ=610 */
  EDMA4_CH44_IRQn              = 611,              /**< WAKEUPMIX EDMA4 channel 44 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[12] - inputs[204]) IRQ=611 */
  EDMA4_CH45_IRQn              = 612,              /**< WAKEUPMIX EDMA4 channel 45 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[13] - inputs[205]) IRQ=612 */
  EDMA4_CH46_IRQn              = 613,              /**< WAKEUPMIX EDMA4 channel 46 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[14] - inputs[206]) IRQ=613 */
  EDMA4_CH47_IRQn              = 614,              /**< WAKEUPMIX EDMA4 channel 47 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[15] - inputs[207]) IRQ=614 */
  EDMA4_CH48_IRQn              = 615,              /**< WAKEUPMIX EDMA4 channel 48 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[16] - inputs[208]) IRQ=615 */
  EDMA4_CH49_IRQn              = 616,              /**< WAKEUPMIX EDMA4 channel 49 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[17] - inputs[209]) IRQ=616 */
  EDMA4_CH50_IRQn              = 617,              /**< WAKEUPMIX EDMA4 channel 50 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[18] - inputs[210]) IRQ=617 */
  EDMA4_CH51_IRQn              = 618,              /**< WAKEUPMIX EDMA4 channel 51 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[19] - inputs[211]) IRQ=618 */
  EDMA4_CH52_IRQn              = 619,              /**< WAKEUPMIX EDMA4 channel 52 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[20] - inputs[212]) IRQ=619 */
  EDMA4_CH53_IRQn              = 620,              /**< WAKEUPMIX EDMA4 channel 53 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[21] - inputs[213]) IRQ=620 */
  EDMA4_CH54_IRQn              = 621,              /**< WAKEUPMIX EDMA4 channel 54 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[22] - inputs[214]) IRQ=621 */
  EDMA4_CH55_IRQn              = 622,              /**< WAKEUPMIX EDMA4 channel 55 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[23] - inputs[215]) IRQ=622 */
  EDMA4_CH56_IRQn              = 623,              /**< WAKEUPMIX EDMA4 channel 56 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[24] - inputs[216]) IRQ=623 */
  EDMA4_CH57_IRQn              = 624,              /**< WAKEUPMIX EDMA4 channel 57 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[25] - inputs[217]) IRQ=624 */
  EDMA4_CH58_IRQn              = 625,              /**< WAKEUPMIX EDMA4 channel 58 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[26] - inputs[218]) IRQ=625 */
  EDMA4_CH59_IRQn              = 626,              /**< WAKEUPMIX EDMA4 channel 59 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[27] - inputs[219]) IRQ=626 */
  EDMA4_CH60_IRQn              = 627,              /**< WAKEUPMIX EDMA4 channel 60 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[28] - inputs[220]) IRQ=627 */
  EDMA4_CH61_IRQn              = 628,              /**< WAKEUPMIX EDMA4 channel 61 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[29] - inputs[221]) IRQ=628 */
  EDMA4_CH62_IRQn              = 629,              /**< WAKEUPMIX EDMA4 channel 62 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[30] - inputs[222]) IRQ=629 */
  EDMA4_CH63_IRQn              = 630,              /**< WAKEUPMIX EDMA4 channel 63 interrupt Module=EDMA4 IRQSTEERM33 extend(bitoffset[31] - inputs[223]) IRQ=630 */
  Reserved647_IRQn             = 631,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[224]) IRQ=631 */
  Reserved648_IRQn             = 632,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[225]) IRQ=632 */
  Reserved649_IRQn             = 633,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[226]) IRQ=633 */
  Reserved650_IRQn             = 634,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[227]) IRQ=634 */
  Reserved651_IRQn             = 635,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[228]) IRQ=635 */
  Reserved652_IRQn             = 636,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[229]) IRQ=636 */
  Reserved653_IRQn             = 637,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[230]) IRQ=637 */
  Reserved654_IRQn             = 638,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[231]) IRQ=638 */
  Reserved655_IRQn             = 639,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[232]) IRQ=639 */
  Reserved656_IRQn             = 640,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[233]) IRQ=640 */
  Reserved657_IRQn             = 641,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[234]) IRQ=641 */
  Reserved658_IRQn             = 642,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[235]) IRQ=642 */
  Reserved659_IRQn             = 643,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[236]) IRQ=643 */
  Reserved660_IRQn             = 644,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[237]) IRQ=644 */
  Reserved661_IRQn             = 645,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[238]) IRQ=645 */
  Reserved662_IRQn             = 646,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[239]) IRQ=646 */
  Reserved663_IRQn             = 647,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[240]) IRQ=647 */
  Reserved664_IRQn             = 648,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[241]) IRQ=648 */
  Reserved665_IRQn             = 649,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[242]) IRQ=649 */
  Reserved666_IRQn             = 650,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[243]) IRQ=650 */
  Reserved667_IRQn             = 651,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[244]) IRQ=651 */
  Reserved668_IRQn             = 652,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[245]) IRQ=652 */
  Reserved669_IRQn             = 653,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[246]) IRQ=653 */
  Reserved670_IRQn             = 654,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[247]) IRQ=654 */
  Reserved671_IRQn             = 655,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[248]) IRQ=655 */
  Reserved672_IRQn             = 656,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[249]) IRQ=656 */
  Reserved673_IRQn             = 657,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[250]) IRQ=657 */
  Reserved674_IRQn             = 658,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[251]) IRQ=658 */
  Reserved675_IRQn             = 659,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[252]) IRQ=659 */
  Reserved676_IRQn             = 660,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[253]) IRQ=660 */
  Reserved677_IRQn             = 661,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[254]) IRQ=661 */
  Reserved678_IRQn             = 662,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[255]) IRQ=662 */
  EDMA3_CH0_IRQn               = 663,              /**< WAKEUPMIX ACP EDMA channel 0 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[0] - inputs[256]) IRQ=663 */
  EDMA3_CH1_IRQn               = 664,              /**< WAKEUPMIX ACP EDMA channel 1 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[1] - inputs[257]) IRQ=664 */
  EDMA3_CH2_IRQn               = 665,              /**< WAKEUPMIX ACP EDMA channel 2 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[2] - inputs[258]) IRQ=665 */
  EDMA3_CH3_IRQn               = 666,              /**< WAKEUPMIX ACP EDMA channel 3 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[3] - inputs[259]) IRQ=666 */
  EDMA3_CH4_IRQn               = 667,              /**< WAKEUPMIX ACP EDMA channel 4 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[4] - inputs[260]) IRQ=667 */
  EDMA3_CH5_IRQn               = 668,              /**< WAKEUPMIX ACP EDMA channel 5 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[5] - inputs[261]) IRQ=668 */
  EDMA3_CH6_IRQn               = 669,              /**< WAKEUPMIX ACP EDMA channel 6 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[6] - inputs[262]) IRQ=669 */
  EDMA3_CH7_IRQn               = 670,              /**< WAKEUPMIX ACP EDMA channel 7 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[7] - inputs[263]) IRQ=670 */
  EDMA3_CH8_IRQn               = 671,              /**< WAKEUPMIX ACP EDMA channel 8 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[8] - inputs[264]) IRQ=671 */
  EDMA3_CH9_IRQn               = 672,              /**< WAKEUPMIX ACP EDMA channel 9 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[9] - inputs[265]) IRQ=672 */
  EDMA3_CH10_IRQn              = 673,              /**< WAKEUPMIX ACP EDMA channel 10 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[10] - inputs[266]) IRQ=673 */
  EDMA3_CH11_IRQn              = 674,              /**< WAKEUPMIX ACP EDMA channel 11 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[11] - inputs[267]) IRQ=674 */
  EDMA3_CH12_IRQn              = 675,              /**< WAKEUPMIX ACP EDMA channel 12 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[12] - inputs[268]) IRQ=675 */
  EDMA3_CH13_IRQn              = 676,              /**< WAKEUPMIX ACP EDMA channel 13 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[13] - inputs[269]) IRQ=676 */
  EDMA3_CH14_IRQn              = 677,              /**< WAKEUPMIX ACP EDMA channel 14 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[14] - inputs[270]) IRQ=677 */
  EDMA3_CH15_IRQn              = 678,              /**< WAKEUPMIX ACP EDMA channel 15 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[15] - inputs[271]) IRQ=678 */
  EDMA3_CH16_IRQn              = 679,              /**< WAKEUPMIX ACP EDMA channel 16 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[16] - inputs[272]) IRQ=679 */
  EDMA3_CH17_IRQn              = 680,              /**< WAKEUPMIX ACP EDMA channel 17 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[17] - inputs[273]) IRQ=680 */
  EDMA3_CH18_IRQn              = 681,              /**< WAKEUPMIX ACP EDMA channel 18 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[18] - inputs[274]) IRQ=681 */
  EDMA3_CH19_IRQn              = 682,              /**< WAKEUPMIX ACP EDMA channel 19 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[19] - inputs[275]) IRQ=682 */
  EDMA3_CH20_IRQn              = 683,              /**< WAKEUPMIX ACP EDMA channel 20 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[20] - inputs[276]) IRQ=683 */
  EDMA3_CH21_IRQn              = 684,              /**< WAKEUPMIX ACP EDMA channel 21 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[21] - inputs[277]) IRQ=684 */
  EDMA3_CH22_IRQn              = 685,              /**< WAKEUPMIX ACP EDMA channel 22 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[22] - inputs[278]) IRQ=685 */
  EDMA3_CH23_IRQn              = 686,              /**< WAKEUPMIX ACP EDMA channel 23 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[23] - inputs[279]) IRQ=686 */
  EDMA3_CH24_IRQn              = 687,              /**< WAKEUPMIX ACP EDMA channel 24 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[24] - inputs[280]) IRQ=687 */
  EDMA3_CH25_IRQn              = 688,              /**< WAKEUPMIX ACP EDMA channel 25 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[25] - inputs[281]) IRQ=688 */
  EDMA3_CH26_IRQn              = 689,              /**< WAKEUPMIX ACP EDMA channel 26 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[26] - inputs[282]) IRQ=689 */
  EDMA3_CH27_IRQn              = 690,              /**< WAKEUPMIX ACP EDMA channel 27 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[27] - inputs[283]) IRQ=690 */
  EDMA3_CH28_IRQn              = 691,              /**< WAKEUPMIX ACP EDMA channel 28 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[28] - inputs[284]) IRQ=691 */
  EDMA3_CH29_IRQn              = 692,              /**< WAKEUPMIX ACP EDMA channel 29 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[29] - inputs[285]) IRQ=692 */
  EDMA3_CH30_IRQn              = 693,              /**< WAKEUPMIX ACP EDMA channel 30 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[30] - inputs[286]) IRQ=693 */
  EDMA3_CH31_IRQn              = 694,              /**< WAKEUPMIX ACP EDMA channel 31 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[31] - inputs[287]) IRQ=694 */
  Reserved711_IRQn             = 695,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[288]) IRQ=695 */
  Reserved712_IRQn             = 696,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[289]) IRQ=696 */
  Reserved713_IRQn             = 697,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[290]) IRQ=697 */
  Reserved714_IRQn             = 698,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[291]) IRQ=698 */
  Reserved715_IRQn             = 699,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[292]) IRQ=699 */
  Reserved716_IRQn             = 700,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[293]) IRQ=700 */
  Reserved717_IRQn             = 701,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[294]) IRQ=701 */
  Reserved718_IRQn             = 702,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[295]) IRQ=702 */
  Reserved719_IRQn             = 703,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[296]) IRQ=703 */
  Reserved720_IRQn             = 704,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[297]) IRQ=704 */
  Reserved721_IRQn             = 705,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[298]) IRQ=705 */
  Reserved722_IRQn             = 706,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[299]) IRQ=706 */
  Reserved723_IRQn             = 707,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[300]) IRQ=707 */
  Reserved724_IRQn             = 708,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[301]) IRQ=708 */
  Reserved725_IRQn             = 709,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[302]) IRQ=709 */
  Reserved726_IRQn             = 710,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[303]) IRQ=710 */
  Reserved727_IRQn             = 711,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[304]) IRQ=711 */
  Reserved728_IRQn             = 712,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[305]) IRQ=712 */
  Reserved729_IRQn             = 713,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[306]) IRQ=713 */
  Reserved730_IRQn             = 714,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[307]) IRQ=714 */
  Reserved731_IRQn             = 715,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[308]) IRQ=715 */
  Reserved732_IRQn             = 716,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[309]) IRQ=716 */
  Reserved733_IRQn             = 717,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[310]) IRQ=717 */
  Reserved734_IRQn             = 718,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[311]) IRQ=718 */
  Reserved735_IRQn             = 719,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[312]) IRQ=719 */
  Reserved736_IRQn             = 720,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[313]) IRQ=720 */
  Reserved737_IRQn             = 721,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[314]) IRQ=721 */
  Reserved738_IRQn             = 722,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[315]) IRQ=722 */
  Reserved739_IRQn             = 723,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[316]) IRQ=723 */
  Reserved740_IRQn             = 724,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[317]) IRQ=724 */
  Reserved741_IRQn             = 725,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[318]) IRQ=725 */
  Reserved742_IRQn             = 726,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[319]) IRQ=726 */
  EDMA3_CH32_IRQn              = 727,              /**<  WAKEUPMIX ACP EDMA channel 32 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[0] - inputs[320]) IRQ=727 */
  EDMA3_CH33_IRQn              = 728,              /**<  WAKEUPMIX ACP EDMA channel 33 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[1] - inputs[321]) IRQ=728 */
  EDMA3_CH34_IRQn              = 729,              /**<  WAKEUPMIX ACP EDMA channel 34 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[2] - inputs[322]) IRQ=729 */
  EDMA3_CH35_IRQn              = 730,              /**<  WAKEUPMIX ACP EDMA channel 35 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[3] - inputs[323]) IRQ=730 */
  EDMA3_CH36_IRQn              = 731,              /**<  WAKEUPMIX ACP EDMA channel 36 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[4] - inputs[324]) IRQ=731 */
  EDMA3_CH37_IRQn              = 732,              /**<  WAKEUPMIX ACP EDMA channel 37 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[5] - inputs[325]) IRQ=732 */
  EDMA3_CH38_IRQn              = 733,              /**<  WAKEUPMIX ACP EDMA channel 38 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[6] - inputs[326]) IRQ=733 */
  EDMA3_CH39_IRQn              = 734,              /**<  WAKEUPMIX ACP EDMA channel 39 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[7] - inputs[327]) IRQ=734 */
  EDMA3_CH40_IRQn              = 735,              /**<  WAKEUPMIX ACP EDMA channel 40 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[8] - inputs[328]) IRQ=735 */
  EDMA3_CH41_IRQn              = 736,              /**<  WAKEUPMIX ACP EDMA channel 41 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[9] - inputs[329]) IRQ=736 */
  EDMA3_CH42_IRQn              = 737,              /**<  WAKEUPMIX ACP EDMA channel 42 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[10] - inputs[330]) IRQ=737 */
  EDMA3_CH43_IRQn              = 738,              /**<  WAKEUPMIX ACP EDMA channel 43 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[11] - inputs[331]) IRQ=738 */
  EDMA3_CH44_IRQn              = 739,              /**<  WAKEUPMIX ACP EDMA channel 44 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[12] - inputs[332]) IRQ=739 */
  EDMA3_CH45_IRQn              = 740,              /**<  WAKEUPMIX ACP EDMA channel 45 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[13] - inputs[333]) IRQ=740 */
  EDMA3_CH46_IRQn              = 741,              /**<  WAKEUPMIX ACP EDMA channel 46 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[14] - inputs[334]) IRQ=741 */
  EDMA3_CH47_IRQn              = 742,              /**<  WAKEUPMIX ACP EDMA channel 47 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[15] - inputs[335]) IRQ=742 */
  EDMA3_CH48_IRQn              = 743,              /**<  WAKEUPMIX ACP EDMA channel 48 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[16] - inputs[336]) IRQ=743 */
  EDMA3_CH49_IRQn              = 744,              /**<  WAKEUPMIX ACP EDMA channel 49 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[17] - inputs[337]) IRQ=744 */
  EDMA3_CH50_IRQn              = 745,              /**<  WAKEUPMIX ACP EDMA channel 50 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[18] - inputs[338]) IRQ=745 */
  EDMA3_CH51_IRQn              = 746,              /**<  WAKEUPMIX ACP EDMA channel 51 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[19] - inputs[339]) IRQ=746 */
  EDMA3_CH52_IRQn              = 747,              /**<  WAKEUPMIX ACP EDMA channel 52 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[20] - inputs[340]) IRQ=747 */
  EDMA3_CH53_IRQn              = 748,              /**<  WAKEUPMIX ACP EDMA channel 53 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[21] - inputs[341]) IRQ=748 */
  EDMA3_CH54_IRQn              = 749,              /**<  WAKEUPMIX ACP EDMA channel 54 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[22] - inputs[342]) IRQ=749 */
  EDMA3_CH55_IRQn              = 750,              /**<  WAKEUPMIX ACP EDMA channel 55 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[23] - inputs[343]) IRQ=750 */
  EDMA3_CH56_IRQn              = 751,              /**<  WAKEUPMIX ACP EDMA channel 56 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[24] - inputs[344]) IRQ=751 */
  EDMA3_CH57_IRQn              = 752,              /**<  WAKEUPMIX ACP EDMA channel 57 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[25] - inputs[345]) IRQ=752 */
  EDMA3_CH58_IRQn              = 753,              /**<  WAKEUPMIX ACP EDMA channel 58 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[26] - inputs[346]) IRQ=753 */
  EDMA3_CH59_IRQn              = 754,              /**<  WAKEUPMIX ACP EDMA channel 59 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[27] - inputs[347]) IRQ=754 */
  EDMA3_CH60_IRQn              = 755,              /**<  WAKEUPMIX ACP EDMA channel 60 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[28] - inputs[348]) IRQ=755 */
  EDMA3_CH61_IRQn              = 756,              /**<  WAKEUPMIX ACP EDMA channel 61 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[29] - inputs[349]) IRQ=756 */
  EDMA3_CH62_IRQn              = 757,              /**<  WAKEUPMIX ACP EDMA channel 62 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[30] - inputs[350]) IRQ=757 */
  EDMA3_CH63_IRQn              = 758,              /**<  WAKEUPMIX ACP EDMA channel 63 interrupt Module=EDMA3 IRQSTEERM33 extend(bitoffset[31] - inputs[351]) IRQ=758 */
  Reserved775_IRQn             = 759,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[32] - inputs[352]) IRQ=759 */
  Reserved776_IRQn             = 760,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[33] - inputs[353]) IRQ=760 */
  Reserved777_IRQn             = 761,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[34] - inputs[354]) IRQ=761 */
  Reserved778_IRQn             = 762,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[35] - inputs[355]) IRQ=762 */
  Reserved779_IRQn             = 763,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[36] - inputs[356]) IRQ=763 */
  Reserved780_IRQn             = 764,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[37] - inputs[357]) IRQ=764 */
  Reserved781_IRQn             = 765,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[38] - inputs[358]) IRQ=765 */
  Reserved782_IRQn             = 766,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[39] - inputs[359]) IRQ=766 */
  Reserved783_IRQn             = 767,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[40] - inputs[360]) IRQ=767 */
  Reserved784_IRQn             = 768,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[41] - inputs[361]) IRQ=768 */
  Reserved785_IRQn             = 769,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[42] - inputs[362]) IRQ=769 */
  Reserved786_IRQn             = 770,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[43] - inputs[363]) IRQ=770 */
  Reserved787_IRQn             = 771,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[44] - inputs[364]) IRQ=771 */
  Reserved788_IRQn             = 772,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[45] - inputs[365]) IRQ=772 */
  Reserved789_IRQn             = 773,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[46] - inputs[366]) IRQ=773 */
  Reserved790_IRQn             = 774,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[47] - inputs[367]) IRQ=774 */
  Reserved791_IRQn             = 775,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[48] - inputs[368]) IRQ=775 */
  Reserved792_IRQn             = 776,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[49] - inputs[369]) IRQ=776 */
  Reserved793_IRQn             = 777,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[50] - inputs[370]) IRQ=777 */
  Reserved794_IRQn             = 778,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[51] - inputs[371]) IRQ=778 */
  Reserved795_IRQn             = 779,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[52] - inputs[372]) IRQ=779 */
  Reserved796_IRQn             = 780,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[53] - inputs[373]) IRQ=780 */
  Reserved797_IRQn             = 781,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[54] - inputs[374]) IRQ=781 */
  Reserved798_IRQn             = 782,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[55] - inputs[375]) IRQ=782 */
  Reserved799_IRQn             = 783,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[56] - inputs[376]) IRQ=783 */
  Reserved800_IRQn             = 784,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[57] - inputs[377]) IRQ=784 */
  Reserved801_IRQn             = 785,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[58] - inputs[378]) IRQ=785 */
  Reserved802_IRQn             = 786,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[59] - inputs[379]) IRQ=786 */
  Reserved803_IRQn             = 787,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[60] - inputs[380]) IRQ=787 */
  Reserved804_IRQn             = 788,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[61] - inputs[381]) IRQ=788 */
  Reserved805_IRQn             = 789,              /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[62] - inputs[382]) IRQ=789 */
  Reserved806_IRQn             = 790               /**< Reserved interrupt Module=Reserved IRQSTEERM33 extend(bitoffset[63] - inputs[383]) IRQ=790 */
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
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */
#define __DSP_PRESENT                  1         /**< Defines if Armv8-M Mainline core supports DSP instructions */
#define __SAUREGION_PRESENT            1         /**< Defines if an SAU is present or not */

#include "core_cm33.h"                 /* Core Peripheral Access Layer */
#include "system_MIMX94398_cm33_core0.h" /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMX94398_cm33_core0_SERIES
#define MIMX94398_cm33_core0_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMX94398_cm33_core0_features.h"

/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADC base address */
  #define ADC_BASE                                 (0x54530000u)
  /** Peripheral ADC base address */
  #define ADC_BASE_NS                              (0x44530000u)
  /** Peripheral ADC base pointer */
  #define ADC                                      ((ADC_Type *)ADC_BASE)
  /** Peripheral ADC base pointer */
  #define ADC_NS                                   ((ADC_Type *)ADC_BASE_NS)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC }
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS_NS                        { ADC_BASE_NS }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS_NS                         { ADC_NS }
#else
  /** Peripheral ADC base address */
  #define ADC_BASE                                 (0x44530000u)
  /** Peripheral ADC base pointer */
  #define ADC                                      ((ADC_Type *)ADC_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC }
#endif

/* ANALOG_AGDET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANALOG__AGDET base address */
  #define ANALOG__AGDET_BASE                       (0x54487000u)
  /** Peripheral ANALOG__AGDET base address */
  #define ANALOG__AGDET_BASE_NS                    (0x44487000u)
  /** Peripheral ANALOG__AGDET base pointer */
  #define ANALOG__AGDET                            ((ANALOG_AGDET_Type *)ANALOG__AGDET_BASE)
  /** Peripheral ANALOG__AGDET base pointer */
  #define ANALOG__AGDET_NS                         ((ANALOG_AGDET_Type *)ANALOG__AGDET_BASE_NS)
  /** Array initializer of ANALOG_AGDET peripheral base addresses */
  #define ANALOG_AGDET_BASE_ADDRS                  { ANALOG__AGDET_BASE }
  /** Array initializer of ANALOG_AGDET peripheral base pointers */
  #define ANALOG_AGDET_BASE_PTRS                   { ANALOG__AGDET }
  /** Array initializer of ANALOG_AGDET peripheral base addresses */
  #define ANALOG_AGDET_BASE_ADDRS_NS               { ANALOG__AGDET_BASE_NS }
  /** Array initializer of ANALOG_AGDET peripheral base pointers */
  #define ANALOG_AGDET_BASE_PTRS_NS                { ANALOG__AGDET_NS }
#else
  /** Peripheral ANALOG__AGDET base address */
  #define ANALOG__AGDET_BASE                       (0x44487000u)
  /** Peripheral ANALOG__AGDET base pointer */
  #define ANALOG__AGDET                            ((ANALOG_AGDET_Type *)ANALOG__AGDET_BASE)
  /** Array initializer of ANALOG_AGDET peripheral base addresses */
  #define ANALOG_AGDET_BASE_ADDRS                  { ANALOG__AGDET_BASE }
  /** Array initializer of ANALOG_AGDET peripheral base pointers */
  #define ANALOG_AGDET_BASE_PTRS                   { ANALOG__AGDET }
#endif

/* ANALOG_CMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANALOG__CMU0 base address */
  #define ANALOG__CMU0_BASE                        (0x54670000u)
  /** Peripheral ANALOG__CMU0 base address */
  #define ANALOG__CMU0_BASE_NS                     (0x44670000u)
  /** Peripheral ANALOG__CMU0 base pointer */
  #define ANALOG__CMU0                             ((ANALOG_CMU_Type *)ANALOG__CMU0_BASE)
  /** Peripheral ANALOG__CMU0 base pointer */
  #define ANALOG__CMU0_NS                          ((ANALOG_CMU_Type *)ANALOG__CMU0_BASE_NS)
  /** Array initializer of ANALOG_CMU peripheral base addresses */
  #define ANALOG_CMU_BASE_ADDRS                    { ANALOG__CMU0_BASE }
  /** Array initializer of ANALOG_CMU peripheral base pointers */
  #define ANALOG_CMU_BASE_PTRS                     { ANALOG__CMU0 }
  /** Array initializer of ANALOG_CMU peripheral base addresses */
  #define ANALOG_CMU_BASE_ADDRS_NS                 { ANALOG__CMU0_BASE_NS }
  /** Array initializer of ANALOG_CMU peripheral base pointers */
  #define ANALOG_CMU_BASE_PTRS_NS                  { ANALOG__CMU0_NS }
#else
  /** Peripheral ANALOG__CMU0 base address */
  #define ANALOG__CMU0_BASE                        (0x44670000u)
  /** Peripheral ANALOG__CMU0 base pointer */
  #define ANALOG__CMU0                             ((ANALOG_CMU_Type *)ANALOG__CMU0_BASE)
  /** Array initializer of ANALOG_CMU peripheral base addresses */
  #define ANALOG_CMU_BASE_ADDRS                    { ANALOG__CMU0_BASE }
  /** Array initializer of ANALOG_CMU peripheral base pointers */
  #define ANALOG_CMU_BASE_PTRS                     { ANALOG__CMU0 }
#endif

/* ANALOG_PMRO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANALOG__PMRO base address */
  #define ANALOG__PMRO_BASE                        (0x54484000u)
  /** Peripheral ANALOG__PMRO base address */
  #define ANALOG__PMRO_BASE_NS                     (0x44484000u)
  /** Peripheral ANALOG__PMRO base pointer */
  #define ANALOG__PMRO                             ((ANALOG_PMRO_Type *)ANALOG__PMRO_BASE)
  /** Peripheral ANALOG__PMRO base pointer */
  #define ANALOG__PMRO_NS                          ((ANALOG_PMRO_Type *)ANALOG__PMRO_BASE_NS)
  /** Array initializer of ANALOG_PMRO peripheral base addresses */
  #define ANALOG_PMRO_BASE_ADDRS                   { ANALOG__PMRO_BASE }
  /** Array initializer of ANALOG_PMRO peripheral base pointers */
  #define ANALOG_PMRO_BASE_PTRS                    { ANALOG__PMRO }
  /** Array initializer of ANALOG_PMRO peripheral base addresses */
  #define ANALOG_PMRO_BASE_ADDRS_NS                { ANALOG__PMRO_BASE_NS }
  /** Array initializer of ANALOG_PMRO peripheral base pointers */
  #define ANALOG_PMRO_BASE_PTRS_NS                 { ANALOG__PMRO_NS }
#else
  /** Peripheral ANALOG__PMRO base address */
  #define ANALOG__PMRO_BASE                        (0x44484000u)
  /** Peripheral ANALOG__PMRO base pointer */
  #define ANALOG__PMRO                             ((ANALOG_PMRO_Type *)ANALOG__PMRO_BASE)
  /** Array initializer of ANALOG_PMRO peripheral base addresses */
  #define ANALOG_PMRO_BASE_ADDRS                   { ANALOG__PMRO_BASE }
  /** Array initializer of ANALOG_PMRO peripheral base pointers */
  #define ANALOG_PMRO_BASE_PTRS                    { ANALOG__PMRO }
#endif

/* ANALOG_SFA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANALOG__SFA base address */
  #define ANALOG__SFA_BASE                         (0x54483000u)
  /** Peripheral ANALOG__SFA base address */
  #define ANALOG__SFA_BASE_NS                      (0x44483000u)
  /** Peripheral ANALOG__SFA base pointer */
  #define ANALOG__SFA                              ((ANALOG_SFA_Type *)ANALOG__SFA_BASE)
  /** Peripheral ANALOG__SFA base pointer */
  #define ANALOG__SFA_NS                           ((ANALOG_SFA_Type *)ANALOG__SFA_BASE_NS)
  /** Array initializer of ANALOG_SFA peripheral base addresses */
  #define ANALOG_SFA_BASE_ADDRS                    { ANALOG__SFA_BASE }
  /** Array initializer of ANALOG_SFA peripheral base pointers */
  #define ANALOG_SFA_BASE_PTRS                     { ANALOG__SFA }
  /** Array initializer of ANALOG_SFA peripheral base addresses */
  #define ANALOG_SFA_BASE_ADDRS_NS                 { ANALOG__SFA_BASE_NS }
  /** Array initializer of ANALOG_SFA peripheral base pointers */
  #define ANALOG_SFA_BASE_PTRS_NS                  { ANALOG__SFA_NS }
#else
  /** Peripheral ANALOG__SFA base address */
  #define ANALOG__SFA_BASE                         (0x44483000u)
  /** Peripheral ANALOG__SFA base pointer */
  #define ANALOG__SFA                              ((ANALOG_SFA_Type *)ANALOG__SFA_BASE)
  /** Array initializer of ANALOG_SFA peripheral base addresses */
  #define ANALOG_SFA_BASE_ADDRS                    { ANALOG__SFA_BASE }
  /** Array initializer of ANALOG_SFA peripheral base pointers */
  #define ANALOG_SFA_BASE_PTRS                     { ANALOG__SFA }
#endif

/* ANALOG_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANALOG__TCU base address */
  #define ANALOG__TCU_BASE                         (0x544C0000u)
  /** Peripheral ANALOG__TCU base address */
  #define ANALOG__TCU_BASE_NS                      (0x444C0000u)
  /** Peripheral ANALOG__TCU base pointer */
  #define ANALOG__TCU                              ((ANALOG_TCU_Type *)ANALOG__TCU_BASE)
  /** Peripheral ANALOG__TCU base pointer */
  #define ANALOG__TCU_NS                           ((ANALOG_TCU_Type *)ANALOG__TCU_BASE_NS)
  /** Array initializer of ANALOG_TCU peripheral base addresses */
  #define ANALOG_TCU_BASE_ADDRS                    { ANALOG__TCU_BASE }
  /** Array initializer of ANALOG_TCU peripheral base pointers */
  #define ANALOG_TCU_BASE_PTRS                     { ANALOG__TCU }
  /** Array initializer of ANALOG_TCU peripheral base addresses */
  #define ANALOG_TCU_BASE_ADDRS_NS                 { ANALOG__TCU_BASE_NS }
  /** Array initializer of ANALOG_TCU peripheral base pointers */
  #define ANALOG_TCU_BASE_PTRS_NS                  { ANALOG__TCU_NS }
#else
  /** Peripheral ANALOG__TCU base address */
  #define ANALOG__TCU_BASE                         (0x444C0000u)
  /** Peripheral ANALOG__TCU base pointer */
  #define ANALOG__TCU                              ((ANALOG_TCU_Type *)ANALOG__TCU_BASE)
  /** Array initializer of ANALOG_TCU peripheral base addresses */
  #define ANALOG_TCU_BASE_ADDRS                    { ANALOG__TCU_BASE }
  /** Array initializer of ANALOG_TCU peripheral base pointers */
  #define ANALOG_TCU_BASE_PTRS                     { ANALOG__TCU }
#endif

/* ANALOG_VDET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANALOG__VDET base address */
  #define ANALOG__VDET_BASE                        (0x54486000u)
  /** Peripheral ANALOG__VDET base address */
  #define ANALOG__VDET_BASE_NS                     (0x44486000u)
  /** Peripheral ANALOG__VDET base pointer */
  #define ANALOG__VDET                             ((ANALOG_VDET_Type *)ANALOG__VDET_BASE)
  /** Peripheral ANALOG__VDET base pointer */
  #define ANALOG__VDET_NS                          ((ANALOG_VDET_Type *)ANALOG__VDET_BASE_NS)
  /** Array initializer of ANALOG_VDET peripheral base addresses */
  #define ANALOG_VDET_BASE_ADDRS                   { ANALOG__VDET_BASE }
  /** Array initializer of ANALOG_VDET peripheral base pointers */
  #define ANALOG_VDET_BASE_PTRS                    { ANALOG__VDET }
  /** Array initializer of ANALOG_VDET peripheral base addresses */
  #define ANALOG_VDET_BASE_ADDRS_NS                { ANALOG__VDET_BASE_NS }
  /** Array initializer of ANALOG_VDET peripheral base pointers */
  #define ANALOG_VDET_BASE_PTRS_NS                 { ANALOG__VDET_NS }
#else
  /** Peripheral ANALOG__VDET base address */
  #define ANALOG__VDET_BASE                        (0x44486000u)
  /** Peripheral ANALOG__VDET base pointer */
  #define ANALOG__VDET                             ((ANALOG_VDET_Type *)ANALOG__VDET_BASE)
  /** Array initializer of ANALOG_VDET peripheral base addresses */
  #define ANALOG_VDET_BASE_ADDRS                   { ANALOG__VDET_BASE }
  /** Array initializer of ANALOG_VDET peripheral base pointers */
  #define ANALOG_VDET_BASE_PTRS                    { ANALOG__VDET }
#endif

/* AOI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AOI1 base address */
  #define AOI1_BASE                                (0x52840000u)
  /** Peripheral AOI1 base address */
  #define AOI1_BASE_NS                             (0x42840000u)
  /** Peripheral AOI1 base pointer */
  #define AOI1                                     ((AOI_Type *)AOI1_BASE)
  /** Peripheral AOI1 base pointer */
  #define AOI1_NS                                  ((AOI_Type *)AOI1_BASE_NS)
  /** Peripheral AOI2 base address */
  #define AOI2_BASE                                (0x52844000u)
  /** Peripheral AOI2 base address */
  #define AOI2_BASE_NS                             (0x42844000u)
  /** Peripheral AOI2 base pointer */
  #define AOI2                                     ((AOI_Type *)AOI2_BASE)
  /** Peripheral AOI2 base pointer */
  #define AOI2_NS                                  ((AOI_Type *)AOI2_BASE_NS)
  /** Peripheral AOI3 base address */
  #define AOI3_BASE                                (0x52848000u)
  /** Peripheral AOI3 base address */
  #define AOI3_BASE_NS                             (0x42848000u)
  /** Peripheral AOI3 base pointer */
  #define AOI3                                     ((AOI_Type *)AOI3_BASE)
  /** Peripheral AOI3 base pointer */
  #define AOI3_NS                                  ((AOI_Type *)AOI3_BASE_NS)
  /** Peripheral AOI4 base address */
  #define AOI4_BASE                                (0x5284C000u)
  /** Peripheral AOI4 base address */
  #define AOI4_BASE_NS                             (0x4284C000u)
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
#endif

/* AON_CMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__CMUA1 base address */
  #define AON__CMUA1_BASE                          (0x54540000u)
  /** Peripheral AON__CMUA1 base address */
  #define AON__CMUA1_BASE_NS                       (0x44540000u)
  /** Peripheral AON__CMUA1 base pointer */
  #define AON__CMUA1                               ((AON_CMU_Type *)AON__CMUA1_BASE)
  /** Peripheral AON__CMUA1 base pointer */
  #define AON__CMUA1_NS                            ((AON_CMU_Type *)AON__CMUA1_BASE_NS)
  /** Peripheral AON__CMUA2 base address */
  #define AON__CMUA2_BASE                          (0x54650000u)
  /** Peripheral AON__CMUA2 base address */
  #define AON__CMUA2_BASE_NS                       (0x44650000u)
  /** Peripheral AON__CMUA2 base pointer */
  #define AON__CMUA2                               ((AON_CMU_Type *)AON__CMUA2_BASE)
  /** Peripheral AON__CMUA2 base pointer */
  #define AON__CMUA2_NS                            ((AON_CMU_Type *)AON__CMUA2_BASE_NS)
  /** Array initializer of AON_CMU peripheral base addresses */
  #define AON_CMU_BASE_ADDRS                       { AON__CMUA1_BASE, AON__CMUA2_BASE }
  /** Array initializer of AON_CMU peripheral base pointers */
  #define AON_CMU_BASE_PTRS                        { AON__CMUA1, AON__CMUA2 }
  /** Array initializer of AON_CMU peripheral base addresses */
  #define AON_CMU_BASE_ADDRS_NS                    { AON__CMUA1_BASE_NS, AON__CMUA2_BASE_NS }
  /** Array initializer of AON_CMU peripheral base pointers */
  #define AON_CMU_BASE_PTRS_NS                     { AON__CMUA1_NS, AON__CMUA2_NS }
#else
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
#endif

/* AON_CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__CRCA base address */
  #define AON__CRCA_BASE                           (0x54660000u)
  /** Peripheral AON__CRCA base address */
  #define AON__CRCA_BASE_NS                        (0x44660000u)
  /** Peripheral AON__CRCA base pointer */
  #define AON__CRCA                                ((AON_CRC_Type *)AON__CRCA_BASE)
  /** Peripheral AON__CRCA base pointer */
  #define AON__CRCA_NS                             ((AON_CRC_Type *)AON__CRCA_BASE_NS)
  /** Array initializer of AON_CRC peripheral base addresses */
  #define AON_CRC_BASE_ADDRS                       { AON__CRCA_BASE }
  /** Array initializer of AON_CRC peripheral base pointers */
  #define AON_CRC_BASE_PTRS                        { AON__CRCA }
  /** Array initializer of AON_CRC peripheral base addresses */
  #define AON_CRC_BASE_ADDRS_NS                    { AON__CRCA_BASE_NS }
  /** Array initializer of AON_CRC peripheral base pointers */
  #define AON_CRC_BASE_PTRS_NS                     { AON__CRCA_NS }
#else
  /** Peripheral AON__CRCA base address */
  #define AON__CRCA_BASE                           (0x44660000u)
  /** Peripheral AON__CRCA base pointer */
  #define AON__CRCA                                ((AON_CRC_Type *)AON__CRCA_BASE)
  /** Array initializer of AON_CRC peripheral base addresses */
  #define AON_CRC_BASE_ADDRS                       { AON__CRCA_BASE }
  /** Array initializer of AON_CRC peripheral base pointers */
  #define AON_CRC_BASE_PTRS                        { AON__CRCA }
#endif

/* AON_CSTCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__CSTCU base address */
  #define AON__CSTCU_BASE                          (0x54590000u)
  /** Peripheral AON__CSTCU base address */
  #define AON__CSTCU_BASE_NS                       (0x44590000u)
  /** Peripheral AON__CSTCU base pointer */
  #define AON__CSTCU                               ((AON_CSTCU_Type *)AON__CSTCU_BASE)
  /** Peripheral AON__CSTCU base pointer */
  #define AON__CSTCU_NS                            ((AON_CSTCU_Type *)AON__CSTCU_BASE_NS)
  /** Array initializer of AON_CSTCU peripheral base addresses */
  #define AON_CSTCU_BASE_ADDRS                     { AON__CSTCU_BASE }
  /** Array initializer of AON_CSTCU peripheral base pointers */
  #define AON_CSTCU_BASE_PTRS                      { AON__CSTCU }
  /** Array initializer of AON_CSTCU peripheral base addresses */
  #define AON_CSTCU_BASE_ADDRS_NS                  { AON__CSTCU_BASE_NS }
  /** Array initializer of AON_CSTCU peripheral base pointers */
  #define AON_CSTCU_BASE_PTRS_NS                   { AON__CSTCU_NS }
#else
  /** Peripheral AON__CSTCU base address */
  #define AON__CSTCU_BASE                          (0x44590000u)
  /** Peripheral AON__CSTCU base pointer */
  #define AON__CSTCU                               ((AON_CSTCU_Type *)AON__CSTCU_BASE)
  /** Array initializer of AON_CSTCU peripheral base addresses */
  #define AON_CSTCU_BASE_ADDRS                     { AON__CSTCU_BASE }
  /** Array initializer of AON_CSTCU peripheral base pointers */
  #define AON_CSTCU_BASE_PTRS                      { AON__CSTCU }
#endif

/* AON_EIM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__EIMA base address */
  #define AON__EIMA_BASE                           (0x54550000u)
  /** Peripheral AON__EIMA base address */
  #define AON__EIMA_BASE_NS                        (0x44550000u)
  /** Peripheral AON__EIMA base pointer */
  #define AON__EIMA                                ((AON_EIM_Type *)AON__EIMA_BASE)
  /** Peripheral AON__EIMA base pointer */
  #define AON__EIMA_NS                             ((AON_EIM_Type *)AON__EIMA_BASE_NS)
  /** Array initializer of AON_EIM peripheral base addresses */
  #define AON_EIM_BASE_ADDRS                       { AON__EIMA_BASE }
  /** Array initializer of AON_EIM peripheral base pointers */
  #define AON_EIM_BASE_PTRS                        { AON__EIMA }
  /** Array initializer of AON_EIM peripheral base addresses */
  #define AON_EIM_BASE_ADDRS_NS                    { AON__EIMA_BASE_NS }
  /** Array initializer of AON_EIM peripheral base pointers */
  #define AON_EIM_BASE_PTRS_NS                     { AON__EIMA_NS }
#else
  /** Peripheral AON__EIMA base address */
  #define AON__EIMA_BASE                           (0x44550000u)
  /** Peripheral AON__EIMA base pointer */
  #define AON__EIMA                                ((AON_EIM_Type *)AON__EIMA_BASE)
  /** Array initializer of AON_EIM peripheral base addresses */
  #define AON_EIM_BASE_ADDRS                       { AON__EIMA_BASE }
  /** Array initializer of AON_EIM peripheral base pointers */
  #define AON_EIM_BASE_PTRS                        { AON__EIMA }
#endif

/* AON_FCCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__FCCU base address */
  #define AON__FCCU_BASE                           (0x54570000u)
  /** Peripheral AON__FCCU base address */
  #define AON__FCCU_BASE_NS                        (0x44570000u)
  /** Peripheral AON__FCCU base pointer */
  #define AON__FCCU                                ((AON_FCCU_Type *)AON__FCCU_BASE)
  /** Peripheral AON__FCCU base pointer */
  #define AON__FCCU_NS                             ((AON_FCCU_Type *)AON__FCCU_BASE_NS)
  /** Array initializer of AON_FCCU peripheral base addresses */
  #define AON_FCCU_BASE_ADDRS                      { AON__FCCU_BASE }
  /** Array initializer of AON_FCCU peripheral base pointers */
  #define AON_FCCU_BASE_PTRS                       { AON__FCCU }
  /** Array initializer of AON_FCCU peripheral base addresses */
  #define AON_FCCU_BASE_ADDRS_NS                   { AON__FCCU_BASE_NS }
  /** Array initializer of AON_FCCU peripheral base pointers */
  #define AON_FCCU_BASE_PTRS_NS                    { AON__FCCU_NS }
#else
  /** Peripheral AON__FCCU base address */
  #define AON__FCCU_BASE                           (0x44570000u)
  /** Peripheral AON__FCCU base pointer */
  #define AON__FCCU                                ((AON_FCCU_Type *)AON__FCCU_BASE)
  /** Array initializer of AON_FCCU peripheral base addresses */
  #define AON_FCCU_BASE_ADDRS                      { AON__FCCU_BASE }
  /** Array initializer of AON_FCCU peripheral base pointers */
  #define AON_FCCU_BASE_PTRS                       { AON__FCCU }
#endif

/* AON_INTM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__INTM base address */
  #define AON__INTM_BASE                           (0x54580000u)
  /** Peripheral AON__INTM base address */
  #define AON__INTM_BASE_NS                        (0x44580000u)
  /** Peripheral AON__INTM base pointer */
  #define AON__INTM                                ((AON_INTM_Type *)AON__INTM_BASE)
  /** Peripheral AON__INTM base pointer */
  #define AON__INTM_NS                             ((AON_INTM_Type *)AON__INTM_BASE_NS)
  /** Array initializer of AON_INTM peripheral base addresses */
  #define AON_INTM_BASE_ADDRS                      { AON__INTM_BASE }
  /** Array initializer of AON_INTM peripheral base pointers */
  #define AON_INTM_BASE_PTRS                       { AON__INTM }
  /** Array initializer of AON_INTM peripheral base addresses */
  #define AON_INTM_BASE_ADDRS_NS                   { AON__INTM_BASE_NS }
  /** Array initializer of AON_INTM peripheral base pointers */
  #define AON_INTM_BASE_PTRS_NS                    { AON__INTM_NS }
#else
  /** Peripheral AON__INTM base address */
  #define AON__INTM_BASE                           (0x44580000u)
  /** Peripheral AON__INTM base pointer */
  #define AON__INTM                                ((AON_INTM_Type *)AON__INTM_BASE)
  /** Array initializer of AON_INTM peripheral base addresses */
  #define AON_INTM_BASE_ADDRS                      { AON__INTM_BASE }
  /** Array initializer of AON_INTM peripheral base pointers */
  #define AON_INTM_BASE_PTRS                       { AON__INTM }
#endif

/* AON_LSTCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__LSTCUA base address */
  #define AON__LSTCUA_BASE                         (0x545A0000u)
  /** Peripheral AON__LSTCUA base address */
  #define AON__LSTCUA_BASE_NS                      (0x445A0000u)
  /** Peripheral AON__LSTCUA base pointer */
  #define AON__LSTCUA                              ((AON_LSTCU_Type *)AON__LSTCUA_BASE)
  /** Peripheral AON__LSTCUA base pointer */
  #define AON__LSTCUA_NS                           ((AON_LSTCU_Type *)AON__LSTCUA_BASE_NS)
  /** Array initializer of AON_LSTCU peripheral base addresses */
  #define AON_LSTCU_BASE_ADDRS                     { AON__LSTCUA_BASE }
  /** Array initializer of AON_LSTCU peripheral base pointers */
  #define AON_LSTCU_BASE_PTRS                      { AON__LSTCUA }
  /** Array initializer of AON_LSTCU peripheral base addresses */
  #define AON_LSTCU_BASE_ADDRS_NS                  { AON__LSTCUA_BASE_NS }
  /** Array initializer of AON_LSTCU peripheral base pointers */
  #define AON_LSTCU_BASE_PTRS_NS                   { AON__LSTCUA_NS }
#else
  /** Peripheral AON__LSTCUA base address */
  #define AON__LSTCUA_BASE                         (0x445A0000u)
  /** Peripheral AON__LSTCUA base pointer */
  #define AON__LSTCUA                              ((AON_LSTCU_Type *)AON__LSTCUA_BASE)
  /** Array initializer of AON_LSTCU peripheral base addresses */
  #define AON_LSTCU_BASE_ADDRS                     { AON__LSTCUA_BASE }
  /** Array initializer of AON_LSTCU peripheral base pointers */
  #define AON_LSTCU_BASE_PTRS                      { AON__LSTCUA }
#endif

/* AON_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__MCM base address */
  #define AON__MCM_BASE                            (0xF0080000u)
  /** Peripheral AON__MCM base address */
  #define AON__MCM_BASE_NS                         (0xE0080000u)
  /** Peripheral AON__MCM base pointer */
  #define AON__MCM                                 ((AON_MCM_Type *)AON__MCM_BASE)
  /** Peripheral AON__MCM base pointer */
  #define AON__MCM_NS                              ((AON_MCM_Type *)AON__MCM_BASE_NS)
  /** Array initializer of AON_MCM peripheral base addresses */
  #define AON_MCM_BASE_ADDRS                       { AON__MCM_BASE }
  /** Array initializer of AON_MCM peripheral base pointers */
  #define AON_MCM_BASE_PTRS                        { AON__MCM }
  /** Array initializer of AON_MCM peripheral base addresses */
  #define AON_MCM_BASE_ADDRS_NS                    { AON__MCM_BASE_NS }
  /** Array initializer of AON_MCM peripheral base pointers */
  #define AON_MCM_BASE_PTRS_NS                     { AON__MCM_NS }
#else
  /** Peripheral AON__MCM base address */
  #define AON__MCM_BASE                            (0xE0080000u)
  /** Peripheral AON__MCM base pointer */
  #define AON__MCM                                 ((AON_MCM_Type *)AON__MCM_BASE)
  /** Array initializer of AON_MCM peripheral base addresses */
  #define AON_MCM_BASE_ADDRS                       { AON__MCM_BASE }
  /** Array initializer of AON_MCM peripheral base pointers */
  #define AON_MCM_BASE_PTRS                        { AON__MCM }
#endif

/* AON_SYSPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__M33_PCF1 base address */
  #define AON__M33_PCF1_BASE                       (0x543E0000u)
  /** Peripheral AON__M33_PCF1 base address */
  #define AON__M33_PCF1_BASE_NS                    (0x443E0000u)
  /** Peripheral AON__M33_PCF1 base pointer */
  #define AON__M33_PCF1                            ((AON_SYSPM_Type *)AON__M33_PCF1_BASE)
  /** Peripheral AON__M33_PCF1 base pointer */
  #define AON__M33_PCF1_NS                         ((AON_SYSPM_Type *)AON__M33_PCF1_BASE_NS)
  /** Peripheral AON__M33_PSF1 base address */
  #define AON__M33_PSF1_BASE                       (0x543F0000u)
  /** Peripheral AON__M33_PSF1 base address */
  #define AON__M33_PSF1_BASE_NS                    (0x443F0000u)
  /** Peripheral AON__M33_PSF1 base pointer */
  #define AON__M33_PSF1                            ((AON_SYSPM_Type *)AON__M33_PSF1_BASE)
  /** Peripheral AON__M33_PSF1 base pointer */
  #define AON__M33_PSF1_NS                         ((AON_SYSPM_Type *)AON__M33_PSF1_BASE_NS)
  /** Array initializer of AON_SYSPM peripheral base addresses */
  #define AON_SYSPM_BASE_ADDRS                     { AON__M33_PCF1_BASE, AON__M33_PSF1_BASE }
  /** Array initializer of AON_SYSPM peripheral base pointers */
  #define AON_SYSPM_BASE_PTRS                      { AON__M33_PCF1, AON__M33_PSF1 }
  /** Array initializer of AON_SYSPM peripheral base addresses */
  #define AON_SYSPM_BASE_ADDRS_NS                  { AON__M33_PCF1_BASE_NS, AON__M33_PSF1_BASE_NS }
  /** Array initializer of AON_SYSPM peripheral base pointers */
  #define AON_SYSPM_BASE_PTRS_NS                   { AON__M33_PCF1_NS, AON__M33_PSF1_NS }
#else
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
#endif

/* AON_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__TCU base address */
  #define AON__TCU_BASE                            (0x544B0000u)
  /** Peripheral AON__TCU base address */
  #define AON__TCU_BASE_NS                         (0x444B0000u)
  /** Peripheral AON__TCU base pointer */
  #define AON__TCU                                 ((AON_TCU_Type *)AON__TCU_BASE)
  /** Peripheral AON__TCU base pointer */
  #define AON__TCU_NS                              ((AON_TCU_Type *)AON__TCU_BASE_NS)
  /** Array initializer of AON_TCU peripheral base addresses */
  #define AON_TCU_BASE_ADDRS                       { AON__TCU_BASE }
  /** Array initializer of AON_TCU peripheral base pointers */
  #define AON_TCU_BASE_PTRS                        { AON__TCU }
  /** Array initializer of AON_TCU peripheral base addresses */
  #define AON_TCU_BASE_ADDRS_NS                    { AON__TCU_BASE_NS }
  /** Array initializer of AON_TCU peripheral base pointers */
  #define AON_TCU_BASE_PTRS_NS                     { AON__TCU_NS }
#else
  /** Peripheral AON__TCU base address */
  #define AON__TCU_BASE                            (0x444B0000u)
  /** Peripheral AON__TCU base pointer */
  #define AON__TCU                                 ((AON_TCU_Type *)AON__TCU_BASE)
  /** Array initializer of AON_TCU peripheral base addresses */
  #define AON_TCU_BASE_ADDRS                       { AON__TCU_BASE }
  /** Array initializer of AON_TCU peripheral base pointers */
  #define AON_TCU_BASE_PTRS                        { AON__TCU }
#endif

/* AON_TRDC_MGR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__TRDC_MGR base address */
  #define AON__TRDC_MGR_BASE                       (0x54270000u)
  /** Peripheral AON__TRDC_MGR base address */
  #define AON__TRDC_MGR_BASE_NS                    (0x44270000u)
  /** Peripheral AON__TRDC_MGR base pointer */
  #define AON__TRDC_MGR                            ((AON_TRDC_MGR_Type *)AON__TRDC_MGR_BASE)
  /** Peripheral AON__TRDC_MGR base pointer */
  #define AON__TRDC_MGR_NS                         ((AON_TRDC_MGR_Type *)AON__TRDC_MGR_BASE_NS)
  /** Array initializer of AON_TRDC_MGR peripheral base addresses */
  #define AON_TRDC_MGR_BASE_ADDRS                  { AON__TRDC_MGR_BASE }
  /** Array initializer of AON_TRDC_MGR peripheral base pointers */
  #define AON_TRDC_MGR_BASE_PTRS                   { AON__TRDC_MGR }
  /** Array initializer of AON_TRDC_MGR peripheral base addresses */
  #define AON_TRDC_MGR_BASE_ADDRS_NS               { AON__TRDC_MGR_BASE_NS }
  /** Array initializer of AON_TRDC_MGR peripheral base pointers */
  #define AON_TRDC_MGR_BASE_PTRS_NS                { AON__TRDC_MGR_NS }
#else
  /** Peripheral AON__TRDC_MGR base address */
  #define AON__TRDC_MGR_BASE                       (0x44270000u)
  /** Peripheral AON__TRDC_MGR base pointer */
  #define AON__TRDC_MGR                            ((AON_TRDC_MGR_Type *)AON__TRDC_MGR_BASE)
  /** Array initializer of AON_TRDC_MGR peripheral base addresses */
  #define AON_TRDC_MGR_BASE_ADDRS                  { AON__TRDC_MGR_BASE }
  /** Array initializer of AON_TRDC_MGR peripheral base pointers */
  #define AON_TRDC_MGR_BASE_PTRS                   { AON__TRDC_MGR }
#endif

/* ARDB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__XSPI1__ARDB base address */
  #define WAKEUP__XSPI1__ARDB_BASE                 (0x52B90000u)
  /** Peripheral WAKEUP__XSPI1__ARDB base address */
  #define WAKEUP__XSPI1__ARDB_BASE_NS              (0x42B90000u)
  /** Peripheral WAKEUP__XSPI1__ARDB base pointer */
  #define WAKEUP__XSPI1__ARDB                      ((ARDB_Type *)WAKEUP__XSPI1__ARDB_BASE)
  /** Peripheral WAKEUP__XSPI1__ARDB base pointer */
  #define WAKEUP__XSPI1__ARDB_NS                   ((ARDB_Type *)WAKEUP__XSPI1__ARDB_BASE_NS)
  /** Peripheral WAKEUP__XSPI2__ARDB base address */
  #define WAKEUP__XSPI2__ARDB_BASE                 (0x52BE0000u)
  /** Peripheral WAKEUP__XSPI2__ARDB base address */
  #define WAKEUP__XSPI2__ARDB_BASE_NS              (0x42BE0000u)
  /** Peripheral WAKEUP__XSPI2__ARDB base pointer */
  #define WAKEUP__XSPI2__ARDB                      ((ARDB_Type *)WAKEUP__XSPI2__ARDB_BASE)
  /** Peripheral WAKEUP__XSPI2__ARDB base pointer */
  #define WAKEUP__XSPI2__ARDB_NS                   ((ARDB_Type *)WAKEUP__XSPI2__ARDB_BASE_NS)
  /** Array initializer of ARDB peripheral base addresses */
  #define ARDB_BASE_ADDRS                          { WAKEUP__XSPI1__ARDB_BASE, WAKEUP__XSPI2__ARDB_BASE }
  /** Array initializer of ARDB peripheral base pointers */
  #define ARDB_BASE_PTRS                           { WAKEUP__XSPI1__ARDB, WAKEUP__XSPI2__ARDB }
  /** Array initializer of ARDB peripheral base addresses */
  #define ARDB_BASE_ADDRS_NS                       { WAKEUP__XSPI1__ARDB_BASE_NS, WAKEUP__XSPI2__ARDB_BASE_NS }
  /** Array initializer of ARDB peripheral base pointers */
  #define ARDB_BASE_PTRS_NS                        { WAKEUP__XSPI1__ARDB_NS, WAKEUP__XSPI2__ARDB_NS }
#else
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
#endif

/* ATU_USB2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__ATU_USB2 base address */
  #define HSIO__ATU_USB2_BASE                      (0x5C070000u)
  /** Peripheral HSIO__ATU_USB2 base address */
  #define HSIO__ATU_USB2_BASE_NS                   (0x4C070000u)
  /** Peripheral HSIO__ATU_USB2 base pointer */
  #define HSIO__ATU_USB2                           ((ATU_USB2_Type *)HSIO__ATU_USB2_BASE)
  /** Peripheral HSIO__ATU_USB2 base pointer */
  #define HSIO__ATU_USB2_NS                        ((ATU_USB2_Type *)HSIO__ATU_USB2_BASE_NS)
  /** Array initializer of ATU_USB2 peripheral base addresses */
  #define ATU_USB2_BASE_ADDRS                      { HSIO__ATU_USB2_BASE }
  /** Array initializer of ATU_USB2 peripheral base pointers */
  #define ATU_USB2_BASE_PTRS                       { HSIO__ATU_USB2 }
  /** Array initializer of ATU_USB2 peripheral base addresses */
  #define ATU_USB2_BASE_ADDRS_NS                   { HSIO__ATU_USB2_BASE_NS }
  /** Array initializer of ATU_USB2 peripheral base pointers */
  #define ATU_USB2_BASE_PTRS_NS                    { HSIO__ATU_USB2_NS }
#else
  /** Peripheral HSIO__ATU_USB2 base address */
  #define HSIO__ATU_USB2_BASE                      (0x4C070000u)
  /** Peripheral HSIO__ATU_USB2 base pointer */
  #define HSIO__ATU_USB2                           ((ATU_USB2_Type *)HSIO__ATU_USB2_BASE)
  /** Array initializer of ATU_USB2 peripheral base addresses */
  #define ATU_USB2_BASE_ADDRS                      { HSIO__ATU_USB2_BASE }
  /** Array initializer of ATU_USB2 peripheral base pointers */
  #define ATU_USB2_BASE_PTRS                       { HSIO__ATU_USB2 }
#endif

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

/* BBSM_BLK_CTRL_BBSMMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_BBSMMIX base address */
  #define BLK_CTRL_BBSMMIX_BASE                    (0x54410000u)
  /** Peripheral BLK_CTRL_BBSMMIX base address */
  #define BLK_CTRL_BBSMMIX_BASE_NS                 (0x44410000u)
  /** Peripheral BLK_CTRL_BBSMMIX base pointer */
  #define BLK_CTRL_BBSMMIX                         ((BBSM_BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BASE)
  /** Peripheral BLK_CTRL_BBSMMIX base pointer */
  #define BLK_CTRL_BBSMMIX_NS                      ((BBSM_BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BASE_NS)
  /** Array initializer of BBSM_BLK_CTRL_BBSMMIX peripheral base addresses */
  #define BBSM_BLK_CTRL_BBSMMIX_BASE_ADDRS         { BLK_CTRL_BBSMMIX_BASE }
  /** Array initializer of BBSM_BLK_CTRL_BBSMMIX peripheral base pointers */
  #define BBSM_BLK_CTRL_BBSMMIX_BASE_PTRS          { BLK_CTRL_BBSMMIX }
  /** Array initializer of BBSM_BLK_CTRL_BBSMMIX peripheral base addresses */
  #define BBSM_BLK_CTRL_BBSMMIX_BASE_ADDRS_NS      { BLK_CTRL_BBSMMIX_BASE_NS }
  /** Array initializer of BBSM_BLK_CTRL_BBSMMIX peripheral base pointers */
  #define BBSM_BLK_CTRL_BBSMMIX_BASE_PTRS_NS       { BLK_CTRL_BBSMMIX_NS }
#else
  /** Peripheral BLK_CTRL_BBSMMIX base address */
  #define BLK_CTRL_BBSMMIX_BASE                    (0x44410000u)
  /** Peripheral BLK_CTRL_BBSMMIX base pointer */
  #define BLK_CTRL_BBSMMIX                         ((BBSM_BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BASE)
  /** Array initializer of BBSM_BLK_CTRL_BBSMMIX peripheral base addresses */
  #define BBSM_BLK_CTRL_BBSMMIX_BASE_ADDRS         { BLK_CTRL_BBSMMIX_BASE }
  /** Array initializer of BBSM_BLK_CTRL_BBSMMIX peripheral base pointers */
  #define BBSM_BLK_CTRL_BBSMMIX_BASE_PTRS          { BLK_CTRL_BBSMMIX }
#endif

/* BBSM_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BBSM__TCU_BBSMMIX base address */
  #define BBSM__TCU_BBSMMIX_BASE                   (0x544E0000u)
  /** Peripheral BBSM__TCU_BBSMMIX base address */
  #define BBSM__TCU_BBSMMIX_BASE_NS                (0x444E0000u)
  /** Peripheral BBSM__TCU_BBSMMIX base pointer */
  #define BBSM__TCU_BBSMMIX                        ((BBSM_TCU_Type *)BBSM__TCU_BBSMMIX_BASE)
  /** Peripheral BBSM__TCU_BBSMMIX base pointer */
  #define BBSM__TCU_BBSMMIX_NS                     ((BBSM_TCU_Type *)BBSM__TCU_BBSMMIX_BASE_NS)
  /** Array initializer of BBSM_TCU peripheral base addresses */
  #define BBSM_TCU_BASE_ADDRS                      { BBSM__TCU_BBSMMIX_BASE }
  /** Array initializer of BBSM_TCU peripheral base pointers */
  #define BBSM_TCU_BASE_PTRS                       { BBSM__TCU_BBSMMIX }
  /** Array initializer of BBSM_TCU peripheral base addresses */
  #define BBSM_TCU_BASE_ADDRS_NS                   { BBSM__TCU_BBSMMIX_BASE_NS }
  /** Array initializer of BBSM_TCU peripheral base pointers */
  #define BBSM_TCU_BASE_PTRS_NS                    { BBSM__TCU_BBSMMIX_NS }
#else
  /** Peripheral BBSM__TCU_BBSMMIX base address */
  #define BBSM__TCU_BBSMMIX_BASE                   (0x444E0000u)
  /** Peripheral BBSM__TCU_BBSMMIX base pointer */
  #define BBSM__TCU_BBSMMIX                        ((BBSM_TCU_Type *)BBSM__TCU_BBSMMIX_BASE)
  /** Array initializer of BBSM_TCU peripheral base addresses */
  #define BBSM_TCU_BASE_ADDRS                      { BBSM__TCU_BBSMMIX_BASE }
  /** Array initializer of BBSM_TCU peripheral base pointers */
  #define BBSM_TCU_BASE_PTRS                       { BBSM__TCU_BBSMMIX }
#endif

/* BISS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BISS1 base address */
  #define BISS1_BASE                               (0x52CE0000u)
  /** Peripheral BISS1 base address */
  #define BISS1_BASE_NS                            (0x42CE0000u)
  /** Peripheral BISS1 base pointer */
  #define BISS1                                    ((BISS_Type *)BISS1_BASE)
  /** Peripheral BISS1 base pointer */
  #define BISS1_NS                                 ((BISS_Type *)BISS1_BASE_NS)
  /** Array initializer of BISS peripheral base addresses */
  #define BISS_BASE_ADDRS                          { BISS1_BASE }
  /** Array initializer of BISS peripheral base pointers */
  #define BISS_BASE_PTRS                           { BISS1 }
  /** Array initializer of BISS peripheral base addresses */
  #define BISS_BASE_ADDRS_NS                       { BISS1_BASE_NS }
  /** Array initializer of BISS peripheral base pointers */
  #define BISS_BASE_PTRS_NS                        { BISS1_NS }
#else
  /** Peripheral BISS1 base address */
  #define BISS1_BASE                               (0x42CE0000u)
  /** Peripheral BISS1 base pointer */
  #define BISS1                                    ((BISS_Type *)BISS1_BASE)
  /** Array initializer of BISS peripheral base addresses */
  #define BISS_BASE_ADDRS                          { BISS1_BASE }
  /** Array initializer of BISS peripheral base pointers */
  #define BISS_BASE_PTRS                           { BISS1 }
#endif

/* BLK_CTRL_NETCMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_NETCMIX base address */
  #define BLK_CTRL_NETCMIX_BASE                    (0x5C810000u)
  /** Peripheral BLK_CTRL_NETCMIX base address */
  #define BLK_CTRL_NETCMIX_BASE_NS                 (0x4C810000u)
  /** Peripheral BLK_CTRL_NETCMIX base pointer */
  #define BLK_CTRL_NETCMIX                         ((BLK_CTRL_NETCMIX_Type *)BLK_CTRL_NETCMIX_BASE)
  /** Peripheral BLK_CTRL_NETCMIX base pointer */
  #define BLK_CTRL_NETCMIX_NS                      ((BLK_CTRL_NETCMIX_Type *)BLK_CTRL_NETCMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base addresses */
  #define BLK_CTRL_NETCMIX_BASE_ADDRS              { BLK_CTRL_NETCMIX_BASE }
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base pointers */
  #define BLK_CTRL_NETCMIX_BASE_PTRS               { BLK_CTRL_NETCMIX }
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base addresses */
  #define BLK_CTRL_NETCMIX_BASE_ADDRS_NS           { BLK_CTRL_NETCMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base pointers */
  #define BLK_CTRL_NETCMIX_BASE_PTRS_NS            { BLK_CTRL_NETCMIX_NS }
#else
  /** Peripheral BLK_CTRL_NETCMIX base address */
  #define BLK_CTRL_NETCMIX_BASE                    (0x4C810000u)
  /** Peripheral BLK_CTRL_NETCMIX base pointer */
  #define BLK_CTRL_NETCMIX                         ((BLK_CTRL_NETCMIX_Type *)BLK_CTRL_NETCMIX_BASE)
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base addresses */
  #define BLK_CTRL_NETCMIX_BASE_ADDRS              { BLK_CTRL_NETCMIX_BASE }
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base pointers */
  #define BLK_CTRL_NETCMIX_BASE_PTRS               { BLK_CTRL_NETCMIX }
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
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base address */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE (0x54401000u)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base address */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE_NS (0x44401000u)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base pointer */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM ((CACHE_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base pointer */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_NS ((CACHE_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE_NS)
  /** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base address */
  #define NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE (0x5D1A1000u)
  /** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base address */
  #define NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE_NS (0x4D1A1000u)
  /** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base pointer */
  #define NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM ((CACHE_ECC_MCM_Type *)NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE)
  /** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base pointer */
  #define NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_NS ((CACHE_ECC_MCM_Type *)NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE_NS)
  /** Array initializer of CACHE_ECC_MCM peripheral base addresses */
  #define CACHE_ECC_MCM_BASE_ADDRS                 { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE, NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE }
  /** Array initializer of CACHE_ECC_MCM peripheral base pointers */
  #define CACHE_ECC_MCM_BASE_PTRS                  { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM, NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM }
  /** Array initializer of CACHE_ECC_MCM peripheral base addresses */
  #define CACHE_ECC_MCM_BASE_ADDRS_NS              { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE_NS, NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE_NS }
  /** Array initializer of CACHE_ECC_MCM peripheral base pointers */
  #define CACHE_ECC_MCM_BASE_PTRS_NS               { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_NS, NETC__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_NS }
#else
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
#endif

/* CAMERA_ATU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__ATU base address */
  #define DISPLAY__ATU_BASE                        (0x5B060000u)
  /** Peripheral DISPLAY__ATU base address */
  #define DISPLAY__ATU_BASE_NS                     (0x4B060000u)
  /** Peripheral DISPLAY__ATU base pointer */
  #define DISPLAY__ATU                             ((CAMERA_ATU_Type *)DISPLAY__ATU_BASE)
  /** Peripheral DISPLAY__ATU base pointer */
  #define DISPLAY__ATU_NS                          ((CAMERA_ATU_Type *)DISPLAY__ATU_BASE_NS)
  /** Array initializer of CAMERA_ATU peripheral base addresses */
  #define CAMERA_ATU_BASE_ADDRS                    { DISPLAY__ATU_BASE }
  /** Array initializer of CAMERA_ATU peripheral base pointers */
  #define CAMERA_ATU_BASE_PTRS                     { DISPLAY__ATU }
  /** Array initializer of CAMERA_ATU peripheral base addresses */
  #define CAMERA_ATU_BASE_ADDRS_NS                 { DISPLAY__ATU_BASE_NS }
  /** Array initializer of CAMERA_ATU peripheral base pointers */
  #define CAMERA_ATU_BASE_PTRS_NS                  { DISPLAY__ATU_NS }
#else
  /** Peripheral DISPLAY__ATU base address */
  #define DISPLAY__ATU_BASE                        (0x4B060000u)
  /** Peripheral DISPLAY__ATU base pointer */
  #define DISPLAY__ATU                             ((CAMERA_ATU_Type *)DISPLAY__ATU_BASE)
  /** Array initializer of CAMERA_ATU peripheral base addresses */
  #define CAMERA_ATU_BASE_ADDRS                    { DISPLAY__ATU_BASE }
  /** Array initializer of CAMERA_ATU peripheral base pointers */
  #define CAMERA_ATU_BASE_PTRS                     { DISPLAY__ATU }
#endif

/* CAMIX_BLK_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_CAMIX base address */
  #define BLK_CTRL_CAMIX_BASE                      (0x5A410000u)
  /** Peripheral BLK_CTRL_CAMIX base address */
  #define BLK_CTRL_CAMIX_BASE_NS                   (0x4A410000u)
  /** Peripheral BLK_CTRL_CAMIX base pointer */
  #define BLK_CTRL_CAMIX                           ((CAMIX_BLK_CTRL_Type *)BLK_CTRL_CAMIX_BASE)
  /** Peripheral BLK_CTRL_CAMIX base pointer */
  #define BLK_CTRL_CAMIX_NS                        ((CAMIX_BLK_CTRL_Type *)BLK_CTRL_CAMIX_BASE_NS)
  /** Array initializer of CAMIX_BLK_CTRL peripheral base addresses */
  #define CAMIX_BLK_CTRL_BASE_ADDRS                { BLK_CTRL_CAMIX_BASE }
  /** Array initializer of CAMIX_BLK_CTRL peripheral base pointers */
  #define CAMIX_BLK_CTRL_BASE_PTRS                 { BLK_CTRL_CAMIX }
  /** Array initializer of CAMIX_BLK_CTRL peripheral base addresses */
  #define CAMIX_BLK_CTRL_BASE_ADDRS_NS             { BLK_CTRL_CAMIX_BASE_NS }
  /** Array initializer of CAMIX_BLK_CTRL peripheral base pointers */
  #define CAMIX_BLK_CTRL_BASE_PTRS_NS              { BLK_CTRL_CAMIX_NS }
#else
  /** Peripheral BLK_CTRL_CAMIX base address */
  #define BLK_CTRL_CAMIX_BASE                      (0x4A410000u)
  /** Peripheral BLK_CTRL_CAMIX base pointer */
  #define BLK_CTRL_CAMIX                           ((CAMIX_BLK_CTRL_Type *)BLK_CTRL_CAMIX_BASE)
  /** Array initializer of CAMIX_BLK_CTRL peripheral base addresses */
  #define CAMIX_BLK_CTRL_BASE_ADDRS                { BLK_CTRL_CAMIX_BASE }
  /** Array initializer of CAMIX_BLK_CTRL peripheral base pointers */
  #define CAMIX_BLK_CTRL_BASE_PTRS                 { BLK_CTRL_CAMIX }
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
  /** Peripheral CAN3 base address */
  #define CAN3_BASE                                (0x525E0000u)
  /** Peripheral CAN3 base address */
  #define CAN3_BASE_NS                             (0x425E0000u)
  /** Peripheral CAN3 base pointer */
  #define CAN3                                     ((CAN_Type *)CAN3_BASE)
  /** Peripheral CAN3 base pointer */
  #define CAN3_NS                                  ((CAN_Type *)CAN3_BASE_NS)
  /** Peripheral CAN4 base address */
  #define CAN4_BASE                                (0x525F0000u)
  /** Peripheral CAN4 base address */
  #define CAN4_BASE_NS                             (0x425F0000u)
  /** Peripheral CAN4 base pointer */
  #define CAN4                                     ((CAN_Type *)CAN4_BASE)
  /** Peripheral CAN4 base pointer */
  #define CAN4_NS                                  ((CAN_Type *)CAN4_BASE_NS)
  /** Peripheral CAN5 base address */
  #define CAN5_BASE                                (0x52600000u)
  /** Peripheral CAN5 base address */
  #define CAN5_BASE_NS                             (0x42600000u)
  /** Peripheral CAN5 base pointer */
  #define CAN5                                     ((CAN_Type *)CAN5_BASE)
  /** Peripheral CAN5 base pointer */
  #define CAN5_NS                                  ((CAN_Type *)CAN5_BASE_NS)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { 0u, CAN1_BASE, CAN2_BASE, CAN3_BASE, CAN4_BASE, CAN5_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { (CAN_Type *)0u, CAN1, CAN2, CAN3, CAN4, CAN5 }
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS_NS                        { 0u, CAN1_BASE_NS, CAN2_BASE_NS, CAN3_BASE_NS, CAN4_BASE_NS, CAN5_BASE_NS }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS_NS                         { (CAN_Type *)0u, CAN1_NS, CAN2_NS, CAN3_NS, CAN4_NS, CAN5_NS }
#else
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
#endif
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn, CAN4_IRQn, CAN5_IRQn }
#define CAN_Tx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn, CAN4_IRQn, CAN5_IRQn }
#define CAN_Wake_Up_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn, CAN4_IRQn, CAN5_IRQn }
#define CAN_Error_IRQS                           { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn, CAN4_IRQn, CAN5_IRQn }
#define CAN_Bus_Off_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn, CAN4_IRQn, CAN5_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { NotAvail_IRQn, CAN1_IRQn, CAN1_IRQn, CAN2_IRQn, CAN2_IRQn, CAN3_IRQn, CAN3_IRQn, CAN4_IRQn, CAN4_IRQn, CAN5_IRQn, CAN5_IRQn }

/* CCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE                            (0x54450000u)
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE_NS                         (0x44450000u)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL                                 ((CCM_Type *)CCM_CTRL_BASE)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL_NS                              ((CCM_Type *)CCM_CTRL_BASE_NS)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { CCM_CTRL_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { CCM_CTRL }
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS_NS                        { CCM_CTRL_BASE_NS }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS_NS                         { CCM_CTRL_NS }
#else
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE                            (0x44450000u)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL                                 ((CCM_Type *)CCM_CTRL_BASE)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { CCM_CTRL_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { CCM_CTRL }
#endif

/* CCMSRCGPC_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CCMSRCGPC__TCU base address */
  #define CCMSRCGPC__TCU_BASE                      (0x544D0000u)
  /** Peripheral CCMSRCGPC__TCU base address */
  #define CCMSRCGPC__TCU_BASE_NS                   (0x444D0000u)
  /** Peripheral CCMSRCGPC__TCU base pointer */
  #define CCMSRCGPC__TCU                           ((CCMSRCGPC_TCU_Type *)CCMSRCGPC__TCU_BASE)
  /** Peripheral CCMSRCGPC__TCU base pointer */
  #define CCMSRCGPC__TCU_NS                        ((CCMSRCGPC_TCU_Type *)CCMSRCGPC__TCU_BASE_NS)
  /** Array initializer of CCMSRCGPC_TCU peripheral base addresses */
  #define CCMSRCGPC_TCU_BASE_ADDRS                 { CCMSRCGPC__TCU_BASE }
  /** Array initializer of CCMSRCGPC_TCU peripheral base pointers */
  #define CCMSRCGPC_TCU_BASE_PTRS                  { CCMSRCGPC__TCU }
  /** Array initializer of CCMSRCGPC_TCU peripheral base addresses */
  #define CCMSRCGPC_TCU_BASE_ADDRS_NS              { CCMSRCGPC__TCU_BASE_NS }
  /** Array initializer of CCMSRCGPC_TCU peripheral base pointers */
  #define CCMSRCGPC_TCU_BASE_PTRS_NS               { CCMSRCGPC__TCU_NS }
#else
  /** Peripheral CCMSRCGPC__TCU base address */
  #define CCMSRCGPC__TCU_BASE                      (0x444D0000u)
  /** Peripheral CCMSRCGPC__TCU base pointer */
  #define CCMSRCGPC__TCU                           ((CCMSRCGPC_TCU_Type *)CCMSRCGPC__TCU_BASE)
  /** Array initializer of CCMSRCGPC_TCU peripheral base addresses */
  #define CCMSRCGPC_TCU_BASE_ADDRS                 { CCMSRCGPC__TCU_BASE }
  /** Array initializer of CCMSRCGPC_TCU peripheral base pointers */
  #define CCMSRCGPC_TCU_BASE_PTRS                  { CCMSRCGPC__TCU }
#endif

/* CORTEXA_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CORTEXA__TCU base address */
  #define CORTEXA__TCU_BASE                        (0x5A400000u)
  /** Peripheral CORTEXA__TCU base address */
  #define CORTEXA__TCU_BASE_NS                     (0x4A400000u)
  /** Peripheral CORTEXA__TCU base pointer */
  #define CORTEXA__TCU                             ((CORTEXA_TCU_Type *)CORTEXA__TCU_BASE)
  /** Peripheral CORTEXA__TCU base pointer */
  #define CORTEXA__TCU_NS                          ((CORTEXA_TCU_Type *)CORTEXA__TCU_BASE_NS)
  /** Array initializer of CORTEXA_TCU peripheral base addresses */
  #define CORTEXA_TCU_BASE_ADDRS                   { CORTEXA__TCU_BASE }
  /** Array initializer of CORTEXA_TCU peripheral base pointers */
  #define CORTEXA_TCU_BASE_PTRS                    { CORTEXA__TCU }
  /** Array initializer of CORTEXA_TCU peripheral base addresses */
  #define CORTEXA_TCU_BASE_ADDRS_NS                { CORTEXA__TCU_BASE_NS }
  /** Array initializer of CORTEXA_TCU peripheral base pointers */
  #define CORTEXA_TCU_BASE_PTRS_NS                 { CORTEXA__TCU_NS }
#else
  /** Peripheral CORTEXA__TCU base address */
  #define CORTEXA__TCU_BASE                        (0x4A400000u)
  /** Peripheral CORTEXA__TCU base pointer */
  #define CORTEXA__TCU                             ((CORTEXA_TCU_Type *)CORTEXA__TCU_BASE)
  /** Array initializer of CORTEXA_TCU peripheral base addresses */
  #define CORTEXA_TCU_BASE_ADDRS                   { CORTEXA__TCU_BASE }
  /** Array initializer of CORTEXA_TCU peripheral base pointers */
  #define CORTEXA_TCU_BASE_PTRS                    { CORTEXA__TCU }
#endif

/* DCIF - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DCIF base address */
  #define DCIF_BASE                                (0x5B120000u)
  /** Peripheral DCIF base address */
  #define DCIF_BASE_NS                             (0x4B120000u)
  /** Peripheral DCIF base pointer */
  #define DCIF                                     ((DCIF_Type *)DCIF_BASE)
  /** Peripheral DCIF base pointer */
  #define DCIF_NS                                  ((DCIF_Type *)DCIF_BASE_NS)
  /** Array initializer of DCIF peripheral base addresses */
  #define DCIF_BASE_ADDRS                          { DCIF_BASE }
  /** Array initializer of DCIF peripheral base pointers */
  #define DCIF_BASE_PTRS                           { DCIF }
  /** Array initializer of DCIF peripheral base addresses */
  #define DCIF_BASE_ADDRS_NS                       { DCIF_BASE_NS }
  /** Array initializer of DCIF peripheral base pointers */
  #define DCIF_BASE_PTRS_NS                        { DCIF_NS }
#else
  /** Peripheral DCIF base address */
  #define DCIF_BASE                                (0x4B120000u)
  /** Peripheral DCIF base pointer */
  #define DCIF                                     ((DCIF_Type *)DCIF_BASE)
  /** Array initializer of DCIF peripheral base addresses */
  #define DCIF_BASE_ADDRS                          { DCIF_BASE }
  /** Array initializer of DCIF peripheral base pointers */
  #define DCIF_BASE_PTRS                           { DCIF }
#endif

/* DDR_BLK_CTRL_DDRMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_DDRMIX base address */
  #define BLK_CTRL_DDRMIX_BASE                     (0x5E010000u)
  /** Peripheral BLK_CTRL_DDRMIX base address */
  #define BLK_CTRL_DDRMIX_BASE_NS                  (0x4E010000u)
  /** Peripheral BLK_CTRL_DDRMIX base pointer */
  #define BLK_CTRL_DDRMIX                          ((DDR_BLK_CTRL_DDRMIX_Type *)BLK_CTRL_DDRMIX_BASE)
  /** Peripheral BLK_CTRL_DDRMIX base pointer */
  #define BLK_CTRL_DDRMIX_NS                       ((DDR_BLK_CTRL_DDRMIX_Type *)BLK_CTRL_DDRMIX_BASE_NS)
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base addresses */
  #define DDR_BLK_CTRL_DDRMIX_BASE_ADDRS           { BLK_CTRL_DDRMIX_BASE }
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base pointers */
  #define DDR_BLK_CTRL_DDRMIX_BASE_PTRS            { BLK_CTRL_DDRMIX }
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base addresses */
  #define DDR_BLK_CTRL_DDRMIX_BASE_ADDRS_NS        { BLK_CTRL_DDRMIX_BASE_NS }
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base pointers */
  #define DDR_BLK_CTRL_DDRMIX_BASE_PTRS_NS         { BLK_CTRL_DDRMIX_NS }
#else
  /** Peripheral BLK_CTRL_DDRMIX base address */
  #define BLK_CTRL_DDRMIX_BASE                     (0x4E010000u)
  /** Peripheral BLK_CTRL_DDRMIX base pointer */
  #define BLK_CTRL_DDRMIX                          ((DDR_BLK_CTRL_DDRMIX_Type *)BLK_CTRL_DDRMIX_BASE)
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base addresses */
  #define DDR_BLK_CTRL_DDRMIX_BASE_ADDRS           { BLK_CTRL_DDRMIX_BASE }
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base pointers */
  #define DDR_BLK_CTRL_DDRMIX_BASE_PTRS            { BLK_CTRL_DDRMIX }
#endif

/* DDR_CMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DDRC__CMU_1 base address */
  #define DDRC__CMU_1_BASE                         (0x5E060000u)
  /** Peripheral DDRC__CMU_1 base address */
  #define DDRC__CMU_1_BASE_NS                      (0x4E060000u)
  /** Peripheral DDRC__CMU_1 base pointer */
  #define DDRC__CMU_1                              ((DDR_CMU_Type *)DDRC__CMU_1_BASE)
  /** Peripheral DDRC__CMU_1 base pointer */
  #define DDRC__CMU_1_NS                           ((DDR_CMU_Type *)DDRC__CMU_1_BASE_NS)
  /** Peripheral DDRC__CMU_2 base address */
  #define DDRC__CMU_2_BASE                         (0x5E070000u)
  /** Peripheral DDRC__CMU_2 base address */
  #define DDRC__CMU_2_BASE_NS                      (0x4E070000u)
  /** Peripheral DDRC__CMU_2 base pointer */
  #define DDRC__CMU_2                              ((DDR_CMU_Type *)DDRC__CMU_2_BASE)
  /** Peripheral DDRC__CMU_2 base pointer */
  #define DDRC__CMU_2_NS                           ((DDR_CMU_Type *)DDRC__CMU_2_BASE_NS)
  /** Array initializer of DDR_CMU peripheral base addresses */
  #define DDR_CMU_BASE_ADDRS                       { DDRC__CMU_1_BASE, DDRC__CMU_2_BASE }
  /** Array initializer of DDR_CMU peripheral base pointers */
  #define DDR_CMU_BASE_PTRS                        { DDRC__CMU_1, DDRC__CMU_2 }
  /** Array initializer of DDR_CMU peripheral base addresses */
  #define DDR_CMU_BASE_ADDRS_NS                    { DDRC__CMU_1_BASE_NS, DDRC__CMU_2_BASE_NS }
  /** Array initializer of DDR_CMU peripheral base pointers */
  #define DDR_CMU_BASE_PTRS_NS                     { DDRC__CMU_1_NS, DDRC__CMU_2_NS }
#else
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
#endif

/* DDR_DDRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DDRC base address */
  #define DDRC_BASE                                (0x5E080000u)
  /** Peripheral DDRC base address */
  #define DDRC_BASE_NS                             (0x4E080000u)
  /** Peripheral DDRC base pointer */
  #define DDRC                                     ((DDR_DDRC_Type *)DDRC_BASE)
  /** Peripheral DDRC base pointer */
  #define DDRC_NS                                  ((DDR_DDRC_Type *)DDRC_BASE_NS)
  /** Array initializer of DDR_DDRC peripheral base addresses */
  #define DDR_DDRC_BASE_ADDRS                      { DDRC_BASE }
  /** Array initializer of DDR_DDRC peripheral base pointers */
  #define DDR_DDRC_BASE_PTRS                       { DDRC }
  /** Array initializer of DDR_DDRC peripheral base addresses */
  #define DDR_DDRC_BASE_ADDRS_NS                   { DDRC_BASE_NS }
  /** Array initializer of DDR_DDRC peripheral base pointers */
  #define DDR_DDRC_BASE_PTRS_NS                    { DDRC_NS }
#else
  /** Peripheral DDRC base address */
  #define DDRC_BASE                                (0x4E080000u)
  /** Peripheral DDRC base pointer */
  #define DDRC                                     ((DDR_DDRC_Type *)DDRC_BASE)
  /** Array initializer of DDR_DDRC peripheral base addresses */
  #define DDR_DDRC_BASE_ADDRS                      { DDRC_BASE }
  /** Array initializer of DDR_DDRC peripheral base pointers */
  #define DDR_DDRC_BASE_PTRS                       { DDRC }
#endif

/* DDR_LSTCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DDRC__LSTCU base address */
  #define DDRC__LSTCU_BASE                         (0x5E050000u)
  /** Peripheral DDRC__LSTCU base address */
  #define DDRC__LSTCU_BASE_NS                      (0x4E050000u)
  /** Peripheral DDRC__LSTCU base pointer */
  #define DDRC__LSTCU                              ((DDR_LSTCU_Type *)DDRC__LSTCU_BASE)
  /** Peripheral DDRC__LSTCU base pointer */
  #define DDRC__LSTCU_NS                           ((DDR_LSTCU_Type *)DDRC__LSTCU_BASE_NS)
  /** Array initializer of DDR_LSTCU peripheral base addresses */
  #define DDR_LSTCU_BASE_ADDRS                     { DDRC__LSTCU_BASE }
  /** Array initializer of DDR_LSTCU peripheral base pointers */
  #define DDR_LSTCU_BASE_PTRS                      { DDRC__LSTCU }
  /** Array initializer of DDR_LSTCU peripheral base addresses */
  #define DDR_LSTCU_BASE_ADDRS_NS                  { DDRC__LSTCU_BASE_NS }
  /** Array initializer of DDR_LSTCU peripheral base pointers */
  #define DDR_LSTCU_BASE_PTRS_NS                   { DDRC__LSTCU_NS }
#else
  /** Peripheral DDRC__LSTCU base address */
  #define DDRC__LSTCU_BASE                         (0x4E050000u)
  /** Peripheral DDRC__LSTCU base pointer */
  #define DDRC__LSTCU                              ((DDR_LSTCU_Type *)DDRC__LSTCU_BASE)
  /** Array initializer of DDR_LSTCU peripheral base addresses */
  #define DDR_LSTCU_BASE_ADDRS                     { DDRC__LSTCU_BASE }
  /** Array initializer of DDR_LSTCU peripheral base pointers */
  #define DDR_LSTCU_BASE_PTRS                      { DDRC__LSTCU }
#endif

/* DDR_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DDRC__TCU base address */
  #define DDRC__TCU_BASE                           (0x5E000000u)
  /** Peripheral DDRC__TCU base address */
  #define DDRC__TCU_BASE_NS                        (0x4E000000u)
  /** Peripheral DDRC__TCU base pointer */
  #define DDRC__TCU                                ((DDR_TCU_Type *)DDRC__TCU_BASE)
  /** Peripheral DDRC__TCU base pointer */
  #define DDRC__TCU_NS                             ((DDR_TCU_Type *)DDRC__TCU_BASE_NS)
  /** Array initializer of DDR_TCU peripheral base addresses */
  #define DDR_TCU_BASE_ADDRS                       { DDRC__TCU_BASE }
  /** Array initializer of DDR_TCU peripheral base pointers */
  #define DDR_TCU_BASE_PTRS                        { DDRC__TCU }
  /** Array initializer of DDR_TCU peripheral base addresses */
  #define DDR_TCU_BASE_ADDRS_NS                    { DDRC__TCU_BASE_NS }
  /** Array initializer of DDR_TCU peripheral base pointers */
  #define DDR_TCU_BASE_PTRS_NS                     { DDRC__TCU_NS }
#else
  /** Peripheral DDRC__TCU base address */
  #define DDRC__TCU_BASE                           (0x4E000000u)
  /** Peripheral DDRC__TCU base pointer */
  #define DDRC__TCU                                ((DDR_TCU_Type *)DDRC__TCU_BASE)
  /** Array initializer of DDR_TCU peripheral base addresses */
  #define DDR_TCU_BASE_ADDRS                       { DDRC__TCU_BASE }
  /** Array initializer of DDR_TCU peripheral base pointers */
  #define DDR_TCU_BASE_PTRS                        { DDRC__TCU }
#endif

/* DISPLAY_BLK_CTRL_DISPLAYMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_DISPLAYMIX base address */
  #define BLK_CTRL_DISPLAYMIX_BASE                 (0x5B010000u)
  /** Peripheral BLK_CTRL_DISPLAYMIX base address */
  #define BLK_CTRL_DISPLAYMIX_BASE_NS              (0x4B010000u)
  /** Peripheral BLK_CTRL_DISPLAYMIX base pointer */
  #define BLK_CTRL_DISPLAYMIX                      ((DISPLAY_BLK_CTRL_DISPLAYMIX_Type *)BLK_CTRL_DISPLAYMIX_BASE)
  /** Peripheral BLK_CTRL_DISPLAYMIX base pointer */
  #define BLK_CTRL_DISPLAYMIX_NS                   ((DISPLAY_BLK_CTRL_DISPLAYMIX_Type *)BLK_CTRL_DISPLAYMIX_BASE_NS)
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base addresses */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_ADDRS   { BLK_CTRL_DISPLAYMIX_BASE }
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base pointers */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_PTRS    { BLK_CTRL_DISPLAYMIX }
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base addresses */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_ADDRS_NS { BLK_CTRL_DISPLAYMIX_BASE_NS }
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base pointers */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_PTRS_NS { BLK_CTRL_DISPLAYMIX_NS }
#else
  /** Peripheral BLK_CTRL_DISPLAYMIX base address */
  #define BLK_CTRL_DISPLAYMIX_BASE                 (0x4B010000u)
  /** Peripheral BLK_CTRL_DISPLAYMIX base pointer */
  #define BLK_CTRL_DISPLAYMIX                      ((DISPLAY_BLK_CTRL_DISPLAYMIX_Type *)BLK_CTRL_DISPLAYMIX_BASE)
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base addresses */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_ADDRS   { BLK_CTRL_DISPLAYMIX_BASE }
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base pointers */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_PTRS    { BLK_CTRL_DISPLAYMIX }
#endif

/* DISPLAY_BLK_CTRL_LVDS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_LVDS base address */
  #define BLK_CTRL_LVDS_BASE                       (0x5B0C0000u)
  /** Peripheral BLK_CTRL_LVDS base address */
  #define BLK_CTRL_LVDS_BASE_NS                    (0x4B0C0000u)
  /** Peripheral BLK_CTRL_LVDS base pointer */
  #define BLK_CTRL_LVDS                            ((DISPLAY_BLK_CTRL_LVDS_Type *)BLK_CTRL_LVDS_BASE)
  /** Peripheral BLK_CTRL_LVDS base pointer */
  #define BLK_CTRL_LVDS_NS                         ((DISPLAY_BLK_CTRL_LVDS_Type *)BLK_CTRL_LVDS_BASE_NS)
  /** Array initializer of DISPLAY_BLK_CTRL_LVDS peripheral base addresses */
  #define DISPLAY_BLK_CTRL_LVDS_BASE_ADDRS         { BLK_CTRL_LVDS_BASE }
  /** Array initializer of DISPLAY_BLK_CTRL_LVDS peripheral base pointers */
  #define DISPLAY_BLK_CTRL_LVDS_BASE_PTRS          { BLK_CTRL_LVDS }
  /** Array initializer of DISPLAY_BLK_CTRL_LVDS peripheral base addresses */
  #define DISPLAY_BLK_CTRL_LVDS_BASE_ADDRS_NS      { BLK_CTRL_LVDS_BASE_NS }
  /** Array initializer of DISPLAY_BLK_CTRL_LVDS peripheral base pointers */
  #define DISPLAY_BLK_CTRL_LVDS_BASE_PTRS_NS       { BLK_CTRL_LVDS_NS }
#else
  /** Peripheral BLK_CTRL_LVDS base address */
  #define BLK_CTRL_LVDS_BASE                       (0x4B0C0000u)
  /** Peripheral BLK_CTRL_LVDS base pointer */
  #define BLK_CTRL_LVDS                            ((DISPLAY_BLK_CTRL_LVDS_Type *)BLK_CTRL_LVDS_BASE)
  /** Array initializer of DISPLAY_BLK_CTRL_LVDS peripheral base addresses */
  #define DISPLAY_BLK_CTRL_LVDS_BASE_ADDRS         { BLK_CTRL_LVDS_BASE }
  /** Array initializer of DISPLAY_BLK_CTRL_LVDS peripheral base pointers */
  #define DISPLAY_BLK_CTRL_LVDS_BASE_PTRS          { BLK_CTRL_LVDS }
#endif

/* DISPLAY_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__TCU base address */
  #define DISPLAY__TCU_BASE                        (0x5B000000u)
  /** Peripheral DISPLAY__TCU base address */
  #define DISPLAY__TCU_BASE_NS                     (0x4B000000u)
  /** Peripheral DISPLAY__TCU base pointer */
  #define DISPLAY__TCU                             ((DISPLAY_TCU_Type *)DISPLAY__TCU_BASE)
  /** Peripheral DISPLAY__TCU base pointer */
  #define DISPLAY__TCU_NS                          ((DISPLAY_TCU_Type *)DISPLAY__TCU_BASE_NS)
  /** Array initializer of DISPLAY_TCU peripheral base addresses */
  #define DISPLAY_TCU_BASE_ADDRS                   { DISPLAY__TCU_BASE }
  /** Array initializer of DISPLAY_TCU peripheral base pointers */
  #define DISPLAY_TCU_BASE_PTRS                    { DISPLAY__TCU }
  /** Array initializer of DISPLAY_TCU peripheral base addresses */
  #define DISPLAY_TCU_BASE_ADDRS_NS                { DISPLAY__TCU_BASE_NS }
  /** Array initializer of DISPLAY_TCU peripheral base pointers */
  #define DISPLAY_TCU_BASE_PTRS_NS                 { DISPLAY__TCU_NS }
#else
  /** Peripheral DISPLAY__TCU base address */
  #define DISPLAY__TCU_BASE                        (0x4B000000u)
  /** Peripheral DISPLAY__TCU base pointer */
  #define DISPLAY__TCU                             ((DISPLAY_TCU_Type *)DISPLAY__TCU_BASE)
  /** Array initializer of DISPLAY_TCU peripheral base addresses */
  #define DISPLAY_TCU_BASE_ADDRS                   { DISPLAY__TCU_BASE }
  /** Array initializer of DISPLAY_TCU peripheral base pointers */
  #define DISPLAY_TCU_BASE_PTRS                    { DISPLAY__TCU }
#endif

/* DISPLAY_TRDC_MGR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__TRDC_MGR_D base address */
  #define DISPLAY__TRDC_MGR_D_BASE                 (0x5B040000u)
  /** Peripheral DISPLAY__TRDC_MGR_D base address */
  #define DISPLAY__TRDC_MGR_D_BASE_NS              (0x4B040000u)
  /** Peripheral DISPLAY__TRDC_MGR_D base pointer */
  #define DISPLAY__TRDC_MGR_D                      ((DISPLAY_TRDC_MGR_Type *)DISPLAY__TRDC_MGR_D_BASE)
  /** Peripheral DISPLAY__TRDC_MGR_D base pointer */
  #define DISPLAY__TRDC_MGR_D_NS                   ((DISPLAY_TRDC_MGR_Type *)DISPLAY__TRDC_MGR_D_BASE_NS)
  /** Array initializer of DISPLAY_TRDC_MGR peripheral base addresses */
  #define DISPLAY_TRDC_MGR_BASE_ADDRS              { DISPLAY__TRDC_MGR_D_BASE }
  /** Array initializer of DISPLAY_TRDC_MGR peripheral base pointers */
  #define DISPLAY_TRDC_MGR_BASE_PTRS               { DISPLAY__TRDC_MGR_D }
  /** Array initializer of DISPLAY_TRDC_MGR peripheral base addresses */
  #define DISPLAY_TRDC_MGR_BASE_ADDRS_NS           { DISPLAY__TRDC_MGR_D_BASE_NS }
  /** Array initializer of DISPLAY_TRDC_MGR peripheral base pointers */
  #define DISPLAY_TRDC_MGR_BASE_PTRS_NS            { DISPLAY__TRDC_MGR_D_NS }
#else
  /** Peripheral DISPLAY__TRDC_MGR_D base address */
  #define DISPLAY__TRDC_MGR_D_BASE                 (0x4B040000u)
  /** Peripheral DISPLAY__TRDC_MGR_D base pointer */
  #define DISPLAY__TRDC_MGR_D                      ((DISPLAY_TRDC_MGR_Type *)DISPLAY__TRDC_MGR_D_BASE)
  /** Array initializer of DISPLAY_TRDC_MGR peripheral base addresses */
  #define DISPLAY_TRDC_MGR_BASE_ADDRS              { DISPLAY__TRDC_MGR_D_BASE }
  /** Array initializer of DISPLAY_TRDC_MGR peripheral base pointers */
  #define DISPLAY_TRDC_MGR_BASE_PTRS               { DISPLAY__TRDC_MGR_D }
#endif

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EDMA1 base address */
  #define EDMA1_BASE                               (0x54000000u)
  /** Peripheral EDMA1 base address */
  #define EDMA1_BASE_NS                            (0x44000000u)
  /** Peripheral EDMA1 base pointer */
  #define EDMA1                                    ((DMA_Type *)EDMA1_BASE)
  /** Peripheral EDMA1 base pointer */
  #define EDMA1_NS                                 ((DMA_Type *)EDMA1_BASE_NS)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { EDMA1_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { EDMA1 }
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS_NS                        { EDMA1_BASE_NS }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS_NS                         { EDMA1_NS }
#else
  /** Peripheral EDMA1 base address */
  #define EDMA1_BASE                               (0x44000000u)
  /** Peripheral EDMA1 base pointer */
  #define EDMA1                                    ((DMA_Type *)EDMA1_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { EDMA1_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { EDMA1 }
#endif

/* DMA5 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EDMA2 base address */
  #define EDMA2_BASE                               (0x52000000u)
  /** Peripheral EDMA2 base address */
  #define EDMA2_BASE_NS                            (0x42000000u)
  /** Peripheral EDMA2 base pointer */
  #define EDMA2                                    ((DMA5_Type *)EDMA2_BASE)
  /** Peripheral EDMA2 base pointer */
  #define EDMA2_NS                                 ((DMA5_Type *)EDMA2_BASE_NS)
  /** Peripheral EDMA3 base address */
  #define EDMA3_BASE                               (0x52210000u)
  /** Peripheral EDMA3 base address */
  #define EDMA3_BASE_NS                            (0x42210000u)
  /** Peripheral EDMA3 base pointer */
  #define EDMA3                                    ((DMA5_Type *)EDMA3_BASE)
  /** Peripheral EDMA3 base pointer */
  #define EDMA3_NS                                 ((DMA5_Type *)EDMA3_BASE_NS)
  /** Peripheral EDMA4 base address */
  #define EDMA4_BASE                               (0x52DF0000u)
  /** Peripheral EDMA4 base address */
  #define EDMA4_BASE_NS                            (0x42DF0000u)
  /** Peripheral EDMA4 base pointer */
  #define EDMA4                                    ((DMA5_Type *)EDMA4_BASE)
  /** Peripheral EDMA4 base pointer */
  #define EDMA4_NS                                 ((DMA5_Type *)EDMA4_BASE_NS)
  /** Array initializer of DMA5 peripheral base addresses */
  #define DMA5_BASE_ADDRS                          { 0u, 0u, EDMA2_BASE, EDMA3_BASE, EDMA4_BASE }
  /** Array initializer of DMA5 peripheral base pointers */
  #define DMA5_BASE_PTRS                           { (DMA5_Type *)0u, (DMA5_Type *)0u, EDMA2, EDMA3, EDMA4 }
  /** Array initializer of DMA5 peripheral base addresses */
  #define DMA5_BASE_ADDRS_NS                       { 0u, 0u, EDMA2_BASE_NS, EDMA3_BASE_NS, EDMA4_BASE_NS }
  /** Array initializer of DMA5 peripheral base pointers */
  #define DMA5_BASE_PTRS_NS                        { (DMA5_Type *)0u, (DMA5_Type *)0u, EDMA2_NS, EDMA3_NS, EDMA4_NS }
#else
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
#endif

/* DWC_usb3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__USB_3_01__USB3 base address */
  #define HSIO__USB_3_01__USB3_BASE                (0x5C100000u)
  /** Peripheral HSIO__USB_3_01__USB3 base address */
  #define HSIO__USB_3_01__USB3_BASE_NS             (0x4C100000u)
  /** Peripheral HSIO__USB_3_01__USB3 base pointer */
  #define HSIO__USB_3_01__USB3                     ((DWC_usb3_Type *)HSIO__USB_3_01__USB3_BASE)
  /** Peripheral HSIO__USB_3_01__USB3 base pointer */
  #define HSIO__USB_3_01__USB3_NS                  ((DWC_usb3_Type *)HSIO__USB_3_01__USB3_BASE_NS)
  /** Array initializer of DWC_usb3 peripheral base addresses */
  #define DWC_usb3_BASE_ADDRS                      { HSIO__USB_3_01__USB3_BASE }
  /** Array initializer of DWC_usb3 peripheral base pointers */
  #define DWC_usb3_BASE_PTRS                       { HSIO__USB_3_01__USB3 }
  /** Array initializer of DWC_usb3 peripheral base addresses */
  #define DWC_usb3_BASE_ADDRS_NS                   { HSIO__USB_3_01__USB3_BASE_NS }
  /** Array initializer of DWC_usb3 peripheral base pointers */
  #define DWC_usb3_BASE_PTRS_NS                    { HSIO__USB_3_01__USB3_NS }
#else
  /** Peripheral HSIO__USB_3_01__USB3 base address */
  #define HSIO__USB_3_01__USB3_BASE                (0x4C100000u)
  /** Peripheral HSIO__USB_3_01__USB3 base pointer */
  #define HSIO__USB_3_01__USB3                     ((DWC_usb3_Type *)HSIO__USB_3_01__USB3_BASE)
  /** Array initializer of DWC_usb3 peripheral base addresses */
  #define DWC_usb3_BASE_ADDRS                      { HSIO__USB_3_01__USB3_BASE }
  /** Array initializer of DWC_usb3 peripheral base pointers */
  #define DWC_usb3_BASE_PTRS                       { HSIO__USB_3_01__USB3 }
#endif

/* ECAT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ETHERCAT base address */
  #define ETHERCAT_BASE                            (0x5CF80000u)
  /** Peripheral ETHERCAT base address */
  #define ETHERCAT_BASE_NS                         (0x4CF80000u)
  /** Peripheral ETHERCAT base pointer */
  #define ETHERCAT                                 ((ECAT_Type *)ETHERCAT_BASE)
  /** Peripheral ETHERCAT base pointer */
  #define ETHERCAT_NS                              ((ECAT_Type *)ETHERCAT_BASE_NS)
  /** Array initializer of ECAT peripheral base addresses */
  #define ECAT_BASE_ADDRS                          { ETHERCAT_BASE }
  /** Array initializer of ECAT peripheral base pointers */
  #define ECAT_BASE_PTRS                           { ETHERCAT }
  /** Array initializer of ECAT peripheral base addresses */
  #define ECAT_BASE_ADDRS_NS                       { ETHERCAT_BASE_NS }
  /** Array initializer of ECAT peripheral base pointers */
  #define ECAT_BASE_PTRS_NS                        { ETHERCAT_NS }
#else
  /** Peripheral ETHERCAT base address */
  #define ETHERCAT_BASE                            (0x4CF80000u)
  /** Peripheral ETHERCAT base pointer */
  #define ETHERCAT                                 ((ECAT_Type *)ETHERCAT_BASE)
  /** Array initializer of ECAT peripheral base addresses */
  #define ECAT_BASE_ADDRS                          { ETHERCAT_BASE }
  /** Array initializer of ECAT peripheral base pointers */
  #define ECAT_BASE_PTRS                           { ETHERCAT }
#endif

/* ENDAT2P2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENDAT2P2_1 base address */
  #define ENDAT2P2_1_BASE                          (0x52CB0000u)
  /** Peripheral ENDAT2P2_1 base address */
  #define ENDAT2P2_1_BASE_NS                       (0x42CB0000u)
  /** Peripheral ENDAT2P2_1 base pointer */
  #define ENDAT2P2_1                               ((ENDAT2P2_Type *)ENDAT2P2_1_BASE)
  /** Peripheral ENDAT2P2_1 base pointer */
  #define ENDAT2P2_1_NS                            ((ENDAT2P2_Type *)ENDAT2P2_1_BASE_NS)
  /** Peripheral ENDAT2P2_2 base address */
  #define ENDAT2P2_2_BASE                          (0x52CC0000u)
  /** Peripheral ENDAT2P2_2 base address */
  #define ENDAT2P2_2_BASE_NS                       (0x42CC0000u)
  /** Peripheral ENDAT2P2_2 base pointer */
  #define ENDAT2P2_2                               ((ENDAT2P2_Type *)ENDAT2P2_2_BASE)
  /** Peripheral ENDAT2P2_2 base pointer */
  #define ENDAT2P2_2_NS                            ((ENDAT2P2_Type *)ENDAT2P2_2_BASE_NS)
  /** Array initializer of ENDAT2P2 peripheral base addresses */
  #define ENDAT2P2_BASE_ADDRS                      { ENDAT2P2_1_BASE, ENDAT2P2_2_BASE }
  /** Array initializer of ENDAT2P2 peripheral base pointers */
  #define ENDAT2P2_BASE_PTRS                       { ENDAT2P2_1, ENDAT2P2_2 }
  /** Array initializer of ENDAT2P2 peripheral base addresses */
  #define ENDAT2P2_BASE_ADDRS_NS                   { ENDAT2P2_1_BASE_NS, ENDAT2P2_2_BASE_NS }
  /** Array initializer of ENDAT2P2 peripheral base pointers */
  #define ENDAT2P2_BASE_PTRS_NS                    { ENDAT2P2_1_NS, ENDAT2P2_2_NS }
#else
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
#endif

/* ENDAT3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENDAT3 base address */
  #define ENDAT3_BASE                              (0x52CD0000u)
  /** Peripheral ENDAT3 base address */
  #define ENDAT3_BASE_NS                           (0x42CD0000u)
  /** Peripheral ENDAT3 base pointer */
  #define ENDAT3                                   ((ENDAT3_Type *)ENDAT3_BASE)
  /** Peripheral ENDAT3 base pointer */
  #define ENDAT3_NS                                ((ENDAT3_Type *)ENDAT3_BASE_NS)
  /** Array initializer of ENDAT3 peripheral base addresses */
  #define ENDAT3_BASE_ADDRS                        { ENDAT3_BASE }
  /** Array initializer of ENDAT3 peripheral base pointers */
  #define ENDAT3_BASE_PTRS                         { ENDAT3 }
  /** Array initializer of ENDAT3 peripheral base addresses */
  #define ENDAT3_BASE_ADDRS_NS                     { ENDAT3_BASE_NS }
  /** Array initializer of ENDAT3 peripheral base pointers */
  #define ENDAT3_BASE_PTRS_NS                      { ENDAT3_NS }
#else
  /** Peripheral ENDAT3 base address */
  #define ENDAT3_BASE                              (0x42CD0000u)
  /** Peripheral ENDAT3 base pointer */
  #define ENDAT3                                   ((ENDAT3_Type *)ENDAT3_BASE)
  /** Array initializer of ENDAT3 peripheral base addresses */
  #define ENDAT3_BASE_ADDRS                        { ENDAT3_BASE }
  /** Array initializer of ENDAT3 peripheral base pointers */
  #define ENDAT3_BASE_PTRS                         { ENDAT3 }
#endif

/* ENETC_COMMON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE (0x5CD51000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE_NS (0x4CD51000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON ((ENETC_COMMON_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_NS ((ENETC_COMMON_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE_NS)
  /** Array initializer of ENETC_COMMON peripheral base addresses */
  #define ENETC_COMMON_BASE_ADDRS                  { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE }
  /** Array initializer of ENETC_COMMON peripheral base pointers */
  #define ENETC_COMMON_BASE_PTRS                   { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON }
  /** Array initializer of ENETC_COMMON peripheral base addresses */
  #define ENETC_COMMON_BASE_ADDRS_NS               { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE_NS }
  /** Array initializer of ENETC_COMMON peripheral base pointers */
  #define ENETC_COMMON_BASE_PTRS_NS                { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_NS }
#else
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE (0x4CD51000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON ((ENETC_COMMON_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE)
  /** Array initializer of ENETC_COMMON peripheral base addresses */
  #define ENETC_COMMON_BASE_ADDRS                  { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON_BASE }
  /** Array initializer of ENETC_COMMON peripheral base pointers */
  #define ENETC_COMMON_BASE_PTRS                   { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_COMMON }
#endif

/* ENETC_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EMDIO_GLOBAL base address */
  #define EMDIO_GLOBAL_BASE                        (0x5CDF0000u)
  /** Peripheral EMDIO_GLOBAL base address */
  #define EMDIO_GLOBAL_BASE_NS                     (0x4CDF0000u)
  /** Peripheral EMDIO_GLOBAL base pointer */
  #define EMDIO_GLOBAL                             ((ENETC_GLOBAL_Type *)EMDIO_GLOBAL_BASE)
  /** Peripheral EMDIO_GLOBAL base pointer */
  #define EMDIO_GLOBAL_NS                          ((ENETC_GLOBAL_Type *)EMDIO_GLOBAL_BASE_NS)
  /** Peripheral ENETC0_GLOBAL base address */
  #define ENETC0_GLOBAL_BASE                       (0x5CCA0000u)
  /** Peripheral ENETC0_GLOBAL base address */
  #define ENETC0_GLOBAL_BASE_NS                    (0x4CCA0000u)
  /** Peripheral ENETC0_GLOBAL base pointer */
  #define ENETC0_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC0_GLOBAL_BASE)
  /** Peripheral ENETC0_GLOBAL base pointer */
  #define ENETC0_GLOBAL_NS                         ((ENETC_GLOBAL_Type *)ENETC0_GLOBAL_BASE_NS)
  /** Peripheral ENETC1_GLOBAL base address */
  #define ENETC1_GLOBAL_BASE                       (0x5CCE0000u)
  /** Peripheral ENETC1_GLOBAL base address */
  #define ENETC1_GLOBAL_BASE_NS                    (0x4CCE0000u)
  /** Peripheral ENETC1_GLOBAL base pointer */
  #define ENETC1_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC1_GLOBAL_BASE)
  /** Peripheral ENETC1_GLOBAL base pointer */
  #define ENETC1_GLOBAL_NS                         ((ENETC_GLOBAL_Type *)ENETC1_GLOBAL_BASE_NS)
  /** Peripheral ENETC2_GLOBAL base address */
  #define ENETC2_GLOBAL_BASE                       (0x5CD20000u)
  /** Peripheral ENETC2_GLOBAL base address */
  #define ENETC2_GLOBAL_BASE_NS                    (0x4CD20000u)
  /** Peripheral ENETC2_GLOBAL base pointer */
  #define ENETC2_GLOBAL                            ((ENETC_GLOBAL_Type *)ENETC2_GLOBAL_BASE)
  /** Peripheral ENETC2_GLOBAL base pointer */
  #define ENETC2_GLOBAL_NS                         ((ENETC_GLOBAL_Type *)ENETC2_GLOBAL_BASE_NS)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL_BASE (0x5CD60000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL_BASE_NS (0x4CD60000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL ((ENETC_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL_NS ((ENETC_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL_BASE_NS)
  /** Peripheral TMR0_GLOBAL base address */
  #define TMR0_GLOBAL_BASE                         (0x5CD90000u)
  /** Peripheral TMR0_GLOBAL base address */
  #define TMR0_GLOBAL_BASE_NS                      (0x4CD90000u)
  /** Peripheral TMR0_GLOBAL base pointer */
  #define TMR0_GLOBAL                              ((ENETC_GLOBAL_Type *)TMR0_GLOBAL_BASE)
  /** Peripheral TMR0_GLOBAL base pointer */
  #define TMR0_GLOBAL_NS                           ((ENETC_GLOBAL_Type *)TMR0_GLOBAL_BASE_NS)
  /** Array initializer of ENETC_GLOBAL peripheral base addresses */
  #define ENETC_GLOBAL_BASE_ADDRS                  { EMDIO_GLOBAL_BASE, ENETC0_GLOBAL_BASE, ENETC1_GLOBAL_BASE, ENETC2_GLOBAL_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL_BASE, TMR0_GLOBAL_BASE }
  /** Array initializer of ENETC_GLOBAL peripheral base pointers */
  #define ENETC_GLOBAL_BASE_PTRS                   { EMDIO_GLOBAL, ENETC0_GLOBAL, ENETC1_GLOBAL, ENETC2_GLOBAL, NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL, TMR0_GLOBAL }
  /** Array initializer of ENETC_GLOBAL peripheral base addresses */
  #define ENETC_GLOBAL_BASE_ADDRS_NS               { EMDIO_GLOBAL_BASE_NS, ENETC0_GLOBAL_BASE_NS, ENETC1_GLOBAL_BASE_NS, ENETC2_GLOBAL_BASE_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL_BASE_NS, TMR0_GLOBAL_BASE_NS }
  /** Array initializer of ENETC_GLOBAL peripheral base pointers */
  #define ENETC_GLOBAL_BASE_PTRS_NS                { EMDIO_GLOBAL_NS, ENETC0_GLOBAL_NS, ENETC1_GLOBAL_NS, ENETC2_GLOBAL_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_GLOBAL_NS, TMR0_GLOBAL_NS }
#else
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
#endif

/* ENETC_PCI_TYPE0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EMDIO0_PCI_HDR_TYPE0 base address */
  #define EMDIO0_PCI_HDR_TYPE0_BASE                (0x5CBC0000u)
  /** Peripheral EMDIO0_PCI_HDR_TYPE0 base address */
  #define EMDIO0_PCI_HDR_TYPE0_BASE_NS             (0x4CBC0000u)
  /** Peripheral EMDIO0_PCI_HDR_TYPE0 base pointer */
  #define EMDIO0_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)EMDIO0_PCI_HDR_TYPE0_BASE)
  /** Peripheral EMDIO0_PCI_HDR_TYPE0 base pointer */
  #define EMDIO0_PCI_HDR_TYPE0_NS                  ((ENETC_PCI_TYPE0_Type *)EMDIO0_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral ENETC0_PCI_HDR_TYPE0 base address */
  #define ENETC0_PCI_HDR_TYPE0_BASE                (0x5CB00000u)
  /** Peripheral ENETC0_PCI_HDR_TYPE0 base address */
  #define ENETC0_PCI_HDR_TYPE0_BASE_NS             (0x4CB00000u)
  /** Peripheral ENETC0_PCI_HDR_TYPE0 base pointer */
  #define ENETC0_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)ENETC0_PCI_HDR_TYPE0_BASE)
  /** Peripheral ENETC0_PCI_HDR_TYPE0 base pointer */
  #define ENETC0_PCI_HDR_TYPE0_NS                  ((ENETC_PCI_TYPE0_Type *)ENETC0_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral ENETC1_PCI_HDR_TYPE0 base address */
  #define ENETC1_PCI_HDR_TYPE0_BASE                (0x5CB40000u)
  /** Peripheral ENETC1_PCI_HDR_TYPE0 base address */
  #define ENETC1_PCI_HDR_TYPE0_BASE_NS             (0x4CB40000u)
  /** Peripheral ENETC1_PCI_HDR_TYPE0 base pointer */
  #define ENETC1_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)ENETC1_PCI_HDR_TYPE0_BASE)
  /** Peripheral ENETC1_PCI_HDR_TYPE0 base pointer */
  #define ENETC1_PCI_HDR_TYPE0_NS                  ((ENETC_PCI_TYPE0_Type *)ENETC1_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral ENETC2_PCI_HDR_TYPE0 base address */
  #define ENETC2_PCI_HDR_TYPE0_BASE                (0x5CB80000u)
  /** Peripheral ENETC2_PCI_HDR_TYPE0 base address */
  #define ENETC2_PCI_HDR_TYPE0_BASE_NS             (0x4CB80000u)
  /** Peripheral ENETC2_PCI_HDR_TYPE0 base pointer */
  #define ENETC2_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)ENETC2_PCI_HDR_TYPE0_BASE)
  /** Peripheral ENETC2_PCI_HDR_TYPE0 base pointer */
  #define ENETC2_PCI_HDR_TYPE0_NS                  ((ENETC_PCI_TYPE0_Type *)ENETC2_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral ENETC3_PCI_HDR_TYPE0 base address */
  #define ENETC3_PCI_HDR_TYPE0_BASE                (0x5CA00000u)
  /** Peripheral ENETC3_PCI_HDR_TYPE0 base address */
  #define ENETC3_PCI_HDR_TYPE0_BASE_NS             (0x4CA00000u)
  /** Peripheral ENETC3_PCI_HDR_TYPE0 base pointer */
  #define ENETC3_PCI_HDR_TYPE0                     ((ENETC_PCI_TYPE0_Type *)ENETC3_PCI_HDR_TYPE0_BASE)
  /** Peripheral ENETC3_PCI_HDR_TYPE0 base pointer */
  #define ENETC3_PCI_HDR_TYPE0_NS                  ((ENETC_PCI_TYPE0_Type *)ENETC3_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral SW0_PCI_HDR_TYPE0 base address */
  #define SW0_PCI_HDR_TYPE0_BASE                   (0x5CA02000u)
  /** Peripheral SW0_PCI_HDR_TYPE0 base address */
  #define SW0_PCI_HDR_TYPE0_BASE_NS                (0x4CA02000u)
  /** Peripheral SW0_PCI_HDR_TYPE0 base pointer */
  #define SW0_PCI_HDR_TYPE0                        ((ENETC_PCI_TYPE0_Type *)SW0_PCI_HDR_TYPE0_BASE)
  /** Peripheral SW0_PCI_HDR_TYPE0 base pointer */
  #define SW0_PCI_HDR_TYPE0_NS                     ((ENETC_PCI_TYPE0_Type *)SW0_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral TMR0_PCI_HDR_TYPE0 base address */
  #define TMR0_PCI_HDR_TYPE0_BASE                  (0x5CA01000u)
  /** Peripheral TMR0_PCI_HDR_TYPE0 base address */
  #define TMR0_PCI_HDR_TYPE0_BASE_NS               (0x4CA01000u)
  /** Peripheral TMR0_PCI_HDR_TYPE0 base pointer */
  #define TMR0_PCI_HDR_TYPE0                       ((ENETC_PCI_TYPE0_Type *)TMR0_PCI_HDR_TYPE0_BASE)
  /** Peripheral TMR0_PCI_HDR_TYPE0 base pointer */
  #define TMR0_PCI_HDR_TYPE0_NS                    ((ENETC_PCI_TYPE0_Type *)TMR0_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of ENETC_PCI_TYPE0 peripheral base addresses */
  #define ENETC_PCI_TYPE0_BASE_ADDRS               { EMDIO0_PCI_HDR_TYPE0_BASE, ENETC0_PCI_HDR_TYPE0_BASE, ENETC1_PCI_HDR_TYPE0_BASE, ENETC2_PCI_HDR_TYPE0_BASE, ENETC3_PCI_HDR_TYPE0_BASE, SW0_PCI_HDR_TYPE0_BASE, TMR0_PCI_HDR_TYPE0_BASE }
  /** Array initializer of ENETC_PCI_TYPE0 peripheral base pointers */
  #define ENETC_PCI_TYPE0_BASE_PTRS                { EMDIO0_PCI_HDR_TYPE0, ENETC0_PCI_HDR_TYPE0, ENETC1_PCI_HDR_TYPE0, ENETC2_PCI_HDR_TYPE0, ENETC3_PCI_HDR_TYPE0, SW0_PCI_HDR_TYPE0, TMR0_PCI_HDR_TYPE0 }
  /** Array initializer of ENETC_PCI_TYPE0 peripheral base addresses */
  #define ENETC_PCI_TYPE0_BASE_ADDRS_NS            { EMDIO0_PCI_HDR_TYPE0_BASE_NS, ENETC0_PCI_HDR_TYPE0_BASE_NS, ENETC1_PCI_HDR_TYPE0_BASE_NS, ENETC2_PCI_HDR_TYPE0_BASE_NS, ENETC3_PCI_HDR_TYPE0_BASE_NS, SW0_PCI_HDR_TYPE0_BASE_NS, TMR0_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of ENETC_PCI_TYPE0 peripheral base pointers */
  #define ENETC_PCI_TYPE0_BASE_PTRS_NS             { EMDIO0_PCI_HDR_TYPE0_NS, ENETC0_PCI_HDR_TYPE0_NS, ENETC1_PCI_HDR_TYPE0_NS, ENETC2_PCI_HDR_TYPE0_NS, ENETC3_PCI_HDR_TYPE0_NS, SW0_PCI_HDR_TYPE0_NS, TMR0_PCI_HDR_TYPE0_NS }
#else
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
#endif

/* ENETC_PF_EMDIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EMDIO_BASE base address */
  #define EMDIO_BASE_BASE                          (0x5CDE0000u)
  /** Peripheral EMDIO_BASE base address */
  #define EMDIO_BASE_BASE_NS                       (0x4CDE0000u)
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
  #define EMDIO_BASE_BASE                          (0x4CDE0000u)
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
  #define TMR0_BASE_BASE                           (0x5CD80000u)
  /** Peripheral TMR0_BASE base address */
  #define TMR0_BASE_BASE_NS                        (0x4CD80000u)
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
  #define TMR0_BASE_BASE                           (0x4CD80000u)
  /** Peripheral TMR0_BASE base pointer */
  #define TMR0_BASE                                ((ENETC_PF_TMR_Type *)TMR0_BASE_BASE)
  /** Array initializer of ENETC_PF_TMR peripheral base addresses */
  #define ENETC_PF_TMR_BASE_ADDRS                  { TMR0_BASE_BASE }
  /** Array initializer of ENETC_PF_TMR peripheral base pointers */
  #define ENETC_PF_TMR_BASE_PTRS                   { TMR0_BASE }
#endif

/* ENETC_PORT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE (0x5CD54000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE_NS (0x4CD54000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT ((ENETC_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_NS ((ENETC_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE_NS)
  /** Array initializer of ENETC_PORT peripheral base addresses */
  #define ENETC_PORT_BASE_ADDRS                    { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE }
  /** Array initializer of ENETC_PORT peripheral base pointers */
  #define ENETC_PORT_BASE_PTRS                     { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT }
  /** Array initializer of ENETC_PORT peripheral base addresses */
  #define ENETC_PORT_BASE_ADDRS_NS                 { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE_NS }
  /** Array initializer of ENETC_PORT peripheral base pointers */
  #define ENETC_PORT_BASE_PTRS_NS                  { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_NS }
#else
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE (0x4CD54000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT ((ENETC_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE)
  /** Array initializer of ENETC_PORT peripheral base addresses */
  #define ENETC_PORT_BASE_ADDRS                    { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT_BASE }
  /** Array initializer of ENETC_PORT peripheral base pointers */
  #define ENETC_PORT_BASE_PTRS                     { NETC__ECAM_PCI_EMDIO0_BAR_0__ENETC3_PORT }
#endif

/* ENETC_SI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENETC0_PSI base address */
  #define ENETC0_PSI_BASE                          (0x5CC80000u)
  /** Peripheral ENETC0_PSI base address */
  #define ENETC0_PSI_BASE_NS                       (0x4CC80000u)
  /** Peripheral ENETC0_PSI base pointer */
  #define ENETC0_PSI                               ((ENETC_SI_Type *)ENETC0_PSI_BASE)
  /** Peripheral ENETC0_PSI base pointer */
  #define ENETC0_PSI_NS                            ((ENETC_SI_Type *)ENETC0_PSI_BASE_NS)
  /** Peripheral ENETC1_PSI base address */
  #define ENETC1_PSI_BASE                          (0x5CCC0000u)
  /** Peripheral ENETC1_PSI base address */
  #define ENETC1_PSI_BASE_NS                       (0x4CCC0000u)
  /** Peripheral ENETC1_PSI base pointer */
  #define ENETC1_PSI                               ((ENETC_SI_Type *)ENETC1_PSI_BASE)
  /** Peripheral ENETC1_PSI base pointer */
  #define ENETC1_PSI_NS                            ((ENETC_SI_Type *)ENETC1_PSI_BASE_NS)
  /** Peripheral ENETC2_PSI base address */
  #define ENETC2_PSI_BASE                          (0x5CD00000u)
  /** Peripheral ENETC2_PSI base address */
  #define ENETC2_PSI_BASE_NS                       (0x4CD00000u)
  /** Peripheral ENETC2_PSI base pointer */
  #define ENETC2_PSI                               ((ENETC_SI_Type *)ENETC2_PSI_BASE)
  /** Peripheral ENETC2_PSI base pointer */
  #define ENETC2_PSI_NS                            ((ENETC_SI_Type *)ENETC2_PSI_BASE_NS)
  /** Peripheral ENETC3_PSI base address */
  #define ENETC3_PSI_BASE                          (0x5CD40000u)
  /** Peripheral ENETC3_PSI base address */
  #define ENETC3_PSI_BASE_NS                       (0x4CD40000u)
  /** Peripheral ENETC3_PSI base pointer */
  #define ENETC3_PSI                               ((ENETC_SI_Type *)ENETC3_PSI_BASE)
  /** Peripheral ENETC3_PSI base pointer */
  #define ENETC3_PSI_NS                            ((ENETC_SI_Type *)ENETC3_PSI_BASE_NS)
  /** Peripheral ENETC_VSI0 base address */
  #define ENETC_VSI0_BASE                          (0x5CE50000u)
  /** Peripheral ENETC_VSI0 base address */
  #define ENETC_VSI0_BASE_NS                       (0x4CE50000u)
  /** Peripheral ENETC_VSI0 base pointer */
  #define ENETC_VSI0                               ((ENETC_SI_Type *)ENETC_VSI0_BASE)
  /** Peripheral ENETC_VSI0 base pointer */
  #define ENETC_VSI0_NS                            ((ENETC_SI_Type *)ENETC_VSI0_BASE_NS)
  /** Peripheral ENETC_VSI1 base address */
  #define ENETC_VSI1_BASE                          (0x5CE60000u)
  /** Peripheral ENETC_VSI1 base address */
  #define ENETC_VSI1_BASE_NS                       (0x4CE60000u)
  /** Peripheral ENETC_VSI1 base pointer */
  #define ENETC_VSI1                               ((ENETC_SI_Type *)ENETC_VSI1_BASE)
  /** Peripheral ENETC_VSI1 base pointer */
  #define ENETC_VSI1_NS                            ((ENETC_SI_Type *)ENETC_VSI1_BASE_NS)
  /** Peripheral ENETC_VSI2 base address */
  #define ENETC_VSI2_BASE                          (0x5CE70000u)
  /** Peripheral ENETC_VSI2 base address */
  #define ENETC_VSI2_BASE_NS                       (0x4CE70000u)
  /** Peripheral ENETC_VSI2 base pointer */
  #define ENETC_VSI2                               ((ENETC_SI_Type *)ENETC_VSI2_BASE)
  /** Peripheral ENETC_VSI2 base pointer */
  #define ENETC_VSI2_NS                            ((ENETC_SI_Type *)ENETC_VSI2_BASE_NS)
  /** Array initializer of ENETC_SI peripheral base addresses */
  #define ENETC_SI_BASE_ADDRS                      { ENETC0_PSI_BASE, ENETC1_PSI_BASE, ENETC2_PSI_BASE, ENETC3_PSI_BASE, ENETC_VSI0_BASE, ENETC_VSI1_BASE, ENETC_VSI2_BASE }
  /** Array initializer of ENETC_SI peripheral base pointers */
  #define ENETC_SI_BASE_PTRS                       { ENETC0_PSI, ENETC1_PSI, ENETC2_PSI, ENETC3_PSI, ENETC_VSI0, ENETC_VSI1, ENETC_VSI2 }
  /** Array initializer of ENETC_SI peripheral base addresses */
  #define ENETC_SI_BASE_ADDRS_NS                   { ENETC0_PSI_BASE_NS, ENETC1_PSI_BASE_NS, ENETC2_PSI_BASE_NS, ENETC3_PSI_BASE_NS, ENETC_VSI0_BASE_NS, ENETC_VSI1_BASE_NS, ENETC_VSI2_BASE_NS }
  /** Array initializer of ENETC_SI peripheral base pointers */
  #define ENETC_SI_BASE_PTRS_NS                    { ENETC0_PSI_NS, ENETC1_PSI_NS, ENETC2_PSI_NS, ENETC3_PSI_NS, ENETC_VSI0_NS, ENETC_VSI1_NS, ENETC_VSI2_NS }
#else
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
#endif

/* ENETC_VF_PCI_TYPE0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC_VF1_PCI_HDR_TYPE0 base address */
  #define NETC_VF1_PCI_HDR_TYPE0_BASE              (0x5CA40000u)
  /** Peripheral NETC_VF1_PCI_HDR_TYPE0 base address */
  #define NETC_VF1_PCI_HDR_TYPE0_BASE_NS           (0x4CA40000u)
  /** Peripheral NETC_VF1_PCI_HDR_TYPE0 base pointer */
  #define NETC_VF1_PCI_HDR_TYPE0                   ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF1_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC_VF1_PCI_HDR_TYPE0 base pointer */
  #define NETC_VF1_PCI_HDR_TYPE0_NS                ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF1_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral NETC_VF2_PCI_HDR_TYPE0 base address */
  #define NETC_VF2_PCI_HDR_TYPE0_BASE              (0x5CA80000u)
  /** Peripheral NETC_VF2_PCI_HDR_TYPE0 base address */
  #define NETC_VF2_PCI_HDR_TYPE0_BASE_NS           (0x4CA80000u)
  /** Peripheral NETC_VF2_PCI_HDR_TYPE0 base pointer */
  #define NETC_VF2_PCI_HDR_TYPE0                   ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF2_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC_VF2_PCI_HDR_TYPE0 base pointer */
  #define NETC_VF2_PCI_HDR_TYPE0_NS                ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF2_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral NETC_VF3_PCI_HDR_TYPE0 base address */
  #define NETC_VF3_PCI_HDR_TYPE0_BASE              (0x5CAC0000u)
  /** Peripheral NETC_VF3_PCI_HDR_TYPE0 base address */
  #define NETC_VF3_PCI_HDR_TYPE0_BASE_NS           (0x4CAC0000u)
  /** Peripheral NETC_VF3_PCI_HDR_TYPE0 base pointer */
  #define NETC_VF3_PCI_HDR_TYPE0                   ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF3_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC_VF3_PCI_HDR_TYPE0 base pointer */
  #define NETC_VF3_PCI_HDR_TYPE0_NS                ((ENETC_VF_PCI_TYPE0_Type *)NETC_VF3_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base addresses */
  #define ENETC_VF_PCI_TYPE0_BASE_ADDRS            { NETC_VF1_PCI_HDR_TYPE0_BASE, NETC_VF2_PCI_HDR_TYPE0_BASE, NETC_VF3_PCI_HDR_TYPE0_BASE }
  /** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base pointers */
  #define ENETC_VF_PCI_TYPE0_BASE_PTRS             { NETC_VF1_PCI_HDR_TYPE0, NETC_VF2_PCI_HDR_TYPE0, NETC_VF3_PCI_HDR_TYPE0 }
  /** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base addresses */
  #define ENETC_VF_PCI_TYPE0_BASE_ADDRS_NS         { NETC_VF1_PCI_HDR_TYPE0_BASE_NS, NETC_VF2_PCI_HDR_TYPE0_BASE_NS, NETC_VF3_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of ENETC_VF_PCI_TYPE0 peripheral base pointers */
  #define ENETC_VF_PCI_TYPE0_BASE_PTRS_NS          { NETC_VF1_PCI_HDR_TYPE0_NS, NETC_VF2_PCI_HDR_TYPE0_NS, NETC_VF3_PCI_HDR_TYPE0_NS }
#else
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
#endif

/* ENET_PHY_CTRL_EX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENET_PHY_CTRL_EX base address */
  #define ENET_PHY_CTRL_EX_BASE                    (0x10C00000u)
  /** Peripheral ENET_PHY_CTRL_EX base address */
  #define ENET_PHY_CTRL_EX_BASE_NS                 (0xC00000u)
  /** Peripheral ENET_PHY_CTRL_EX base pointer */
  #define ENET_PHY_CTRL_EX                         ((ENET_PHY_CTRL_EX_Type *)ENET_PHY_CTRL_EX_BASE)
  /** Peripheral ENET_PHY_CTRL_EX base pointer */
  #define ENET_PHY_CTRL_EX_NS                      ((ENET_PHY_CTRL_EX_Type *)ENET_PHY_CTRL_EX_BASE_NS)
  /** Array initializer of ENET_PHY_CTRL_EX peripheral base addresses */
  #define ENET_PHY_CTRL_EX_BASE_ADDRS              { ENET_PHY_CTRL_EX_BASE }
  /** Array initializer of ENET_PHY_CTRL_EX peripheral base pointers */
  #define ENET_PHY_CTRL_EX_BASE_PTRS               { ENET_PHY_CTRL_EX }
  /** Array initializer of ENET_PHY_CTRL_EX peripheral base addresses */
  #define ENET_PHY_CTRL_EX_BASE_ADDRS_NS           { ENET_PHY_CTRL_EX_BASE_NS }
  /** Array initializer of ENET_PHY_CTRL_EX peripheral base pointers */
  #define ENET_PHY_CTRL_EX_BASE_PTRS_NS            { ENET_PHY_CTRL_EX_NS }
#else
  /** Peripheral ENET_PHY_CTRL_EX base address */
  #define ENET_PHY_CTRL_EX_BASE                    (0xC00000u)
  /** Peripheral ENET_PHY_CTRL_EX base pointer */
  #define ENET_PHY_CTRL_EX                         ((ENET_PHY_CTRL_EX_Type *)ENET_PHY_CTRL_EX_BASE)
  /** Array initializer of ENET_PHY_CTRL_EX peripheral base addresses */
  #define ENET_PHY_CTRL_EX_BASE_ADDRS              { ENET_PHY_CTRL_EX_BASE }
  /** Array initializer of ENET_PHY_CTRL_EX peripheral base pointers */
  #define ENET_PHY_CTRL_EX_BASE_PTRS               { ENET_PHY_CTRL_EX }
#endif

/* ENET_PHY_MAC_ADAPTER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENET_PHY_MAC_ADAPTER base address */
  #define ENET_PHY_MAC_ADAPTER_BASE                (0x103E0000u)
  /** Peripheral ENET_PHY_MAC_ADAPTER base address */
  #define ENET_PHY_MAC_ADAPTER_BASE_NS             (0x3E0000u)
  /** Peripheral ENET_PHY_MAC_ADAPTER base pointer */
  #define ENET_PHY_MAC_ADAPTER                     ((ENET_PHY_MAC_ADAPTER_Type *)ENET_PHY_MAC_ADAPTER_BASE)
  /** Peripheral ENET_PHY_MAC_ADAPTER base pointer */
  #define ENET_PHY_MAC_ADAPTER_NS                  ((ENET_PHY_MAC_ADAPTER_Type *)ENET_PHY_MAC_ADAPTER_BASE_NS)
  /** Array initializer of ENET_PHY_MAC_ADAPTER peripheral base addresses */
  #define ENET_PHY_MAC_ADAPTER_BASE_ADDRS          { ENET_PHY_MAC_ADAPTER_BASE }
  /** Array initializer of ENET_PHY_MAC_ADAPTER peripheral base pointers */
  #define ENET_PHY_MAC_ADAPTER_BASE_PTRS           { ENET_PHY_MAC_ADAPTER }
  /** Array initializer of ENET_PHY_MAC_ADAPTER peripheral base addresses */
  #define ENET_PHY_MAC_ADAPTER_BASE_ADDRS_NS       { ENET_PHY_MAC_ADAPTER_BASE_NS }
  /** Array initializer of ENET_PHY_MAC_ADAPTER peripheral base pointers */
  #define ENET_PHY_MAC_ADAPTER_BASE_PTRS_NS        { ENET_PHY_MAC_ADAPTER_NS }
#else
  /** Peripheral ENET_PHY_MAC_ADAPTER base address */
  #define ENET_PHY_MAC_ADAPTER_BASE                (0x3E0000u)
  /** Peripheral ENET_PHY_MAC_ADAPTER base pointer */
  #define ENET_PHY_MAC_ADAPTER                     ((ENET_PHY_MAC_ADAPTER_Type *)ENET_PHY_MAC_ADAPTER_BASE)
  /** Array initializer of ENET_PHY_MAC_ADAPTER peripheral base addresses */
  #define ENET_PHY_MAC_ADAPTER_BASE_ADDRS          { ENET_PHY_MAC_ADAPTER_BASE }
  /** Array initializer of ENET_PHY_MAC_ADAPTER peripheral base pointers */
  #define ENET_PHY_MAC_ADAPTER_BASE_PTRS           { ENET_PHY_MAC_ADAPTER }
#endif

/* EQDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EQDC1 base address */
  #define EQDC1_BASE                               (0x529E0000u)
  /** Peripheral EQDC1 base address */
  #define EQDC1_BASE_NS                            (0x429E0000u)
  /** Peripheral EQDC1 base pointer */
  #define EQDC1                                    ((EQDC_Type *)EQDC1_BASE)
  /** Peripheral EQDC1 base pointer */
  #define EQDC1_NS                                 ((EQDC_Type *)EQDC1_BASE_NS)
  /** Peripheral EQDC2 base address */
  #define EQDC2_BASE                               (0x529F0000u)
  /** Peripheral EQDC2 base address */
  #define EQDC2_BASE_NS                            (0x429F0000u)
  /** Peripheral EQDC2 base pointer */
  #define EQDC2                                    ((EQDC_Type *)EQDC2_BASE)
  /** Peripheral EQDC2 base pointer */
  #define EQDC2_NS                                 ((EQDC_Type *)EQDC2_BASE_NS)
  /** Peripheral EQDC3 base address */
  #define EQDC3_BASE                               (0x52A00000u)
  /** Peripheral EQDC3 base address */
  #define EQDC3_BASE_NS                            (0x42A00000u)
  /** Peripheral EQDC3 base pointer */
  #define EQDC3                                    ((EQDC_Type *)EQDC3_BASE)
  /** Peripheral EQDC3 base pointer */
  #define EQDC3_NS                                 ((EQDC_Type *)EQDC3_BASE_NS)
  /** Peripheral EQDC4 base address */
  #define EQDC4_BASE                               (0x52A10000u)
  /** Peripheral EQDC4 base address */
  #define EQDC4_BASE_NS                            (0x42A10000u)
  /** Peripheral EQDC4 base pointer */
  #define EQDC4                                    ((EQDC_Type *)EQDC4_BASE)
  /** Peripheral EQDC4 base pointer */
  #define EQDC4_NS                                 ((EQDC_Type *)EQDC4_BASE_NS)
  /** Array initializer of EQDC peripheral base addresses */
  #define EQDC_BASE_ADDRS                          { EQDC1_BASE, EQDC2_BASE, EQDC3_BASE, EQDC4_BASE }
  /** Array initializer of EQDC peripheral base pointers */
  #define EQDC_BASE_PTRS                           { EQDC1, EQDC2, EQDC3, EQDC4 }
  /** Array initializer of EQDC peripheral base addresses */
  #define EQDC_BASE_ADDRS_NS                       { EQDC1_BASE_NS, EQDC2_BASE_NS, EQDC3_BASE_NS, EQDC4_BASE_NS }
  /** Array initializer of EQDC peripheral base pointers */
  #define EQDC_BASE_PTRS_NS                        { EQDC1_NS, EQDC2_NS, EQDC3_NS, EQDC4_NS }
#else
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
#endif

/* EWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EWM base address */
  #define EWM_BASE                                 (0x52950000u)
  /** Peripheral EWM base address */
  #define EWM_BASE_NS                              (0x42950000u)
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
  #define EWM_BASE                                 (0x42950000u)
  /** Peripheral EWM base pointer */
  #define EWM                                      ((EWM_Type *)EWM_BASE)
  /** Array initializer of EWM peripheral base addresses */
  #define EWM_BASE_ADDRS                           { EWM_BASE }
  /** Array initializer of EWM peripheral base pointers */
  #define EWM_BASE_PTRS                            { EWM }
#endif

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
  /** Peripheral FLEXIO3 base address */
  #define FLEXIO3_BASE                             (0x5D100000u)
  /** Peripheral FLEXIO3 base address */
  #define FLEXIO3_BASE_NS                          (0x4D100000u)
  /** Peripheral FLEXIO3 base pointer */
  #define FLEXIO3                                  ((FLEXIO_Type *)FLEXIO3_BASE)
  /** Peripheral FLEXIO3 base pointer */
  #define FLEXIO3_NS                               ((FLEXIO_Type *)FLEXIO3_BASE_NS)
  /** Peripheral FLEXIO4 base address */
  #define FLEXIO4_BASE                             (0x5D110000u)
  /** Peripheral FLEXIO4 base address */
  #define FLEXIO4_BASE_NS                          (0x4D110000u)
  /** Peripheral FLEXIO4 base pointer */
  #define FLEXIO4                                  ((FLEXIO_Type *)FLEXIO4_BASE)
  /** Peripheral FLEXIO4 base pointer */
  #define FLEXIO4_NS                               ((FLEXIO_Type *)FLEXIO4_BASE_NS)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE, FLEXIO2_BASE, FLEXIO3_BASE, FLEXIO4_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1, FLEXIO2, FLEXIO3, FLEXIO4 }
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS_NS                     { 0u, FLEXIO1_BASE_NS, FLEXIO2_BASE_NS, FLEXIO3_BASE_NS, FLEXIO4_BASE_NS }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS_NS                      { (FLEXIO_Type *)0u, FLEXIO1_NS, FLEXIO2_NS, FLEXIO3_NS, FLEXIO4_NS }
#else
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
#endif
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { NotAvail_IRQn, FLEXIO1_IRQn, FLEXIO2_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* FRO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FRO base address */
  #define FRO_BASE                                 (0x54485000u)
  /** Peripheral FRO base address */
  #define FRO_BASE_NS                              (0x44485000u)
  /** Peripheral FRO base pointer */
  #define FRO                                      ((FRO_Type *)FRO_BASE)
  /** Peripheral FRO base pointer */
  #define FRO_NS                                   ((FRO_Type *)FRO_BASE_NS)
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS                           { FRO_BASE }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS                            { FRO }
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS_NS                        { FRO_BASE_NS }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS_NS                         { FRO_NS }
#else
  /** Peripheral FRO base address */
  #define FRO_BASE                                 (0x44485000u)
  /** Peripheral FRO base pointer */
  #define FRO                                      ((FRO_Type *)FRO_BASE)
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS                           { FRO_BASE }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS                            { FRO }
#endif

/* GLITCHFILTER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__GLITCHFILTER__IGF base address */
  #define AON__GLITCHFILTER__IGF_BASE              (0x546E0000u)
  /** Peripheral AON__GLITCHFILTER__IGF base address */
  #define AON__GLITCHFILTER__IGF_BASE_NS           (0x446E0000u)
  /** Peripheral AON__GLITCHFILTER__IGF base pointer */
  #define AON__GLITCHFILTER__IGF                   ((GLITCHFILTER_Type *)AON__GLITCHFILTER__IGF_BASE)
  /** Peripheral AON__GLITCHFILTER__IGF base pointer */
  #define AON__GLITCHFILTER__IGF_NS                ((GLITCHFILTER_Type *)AON__GLITCHFILTER__IGF_BASE_NS)
  /** Array initializer of GLITCHFILTER peripheral base addresses */
  #define GLITCHFILTER_BASE_ADDRS                  { AON__GLITCHFILTER__IGF_BASE }
  /** Array initializer of GLITCHFILTER peripheral base pointers */
  #define GLITCHFILTER_BASE_PTRS                   { AON__GLITCHFILTER__IGF }
  /** Array initializer of GLITCHFILTER peripheral base addresses */
  #define GLITCHFILTER_BASE_ADDRS_NS               { AON__GLITCHFILTER__IGF_BASE_NS }
  /** Array initializer of GLITCHFILTER peripheral base pointers */
  #define GLITCHFILTER_BASE_PTRS_NS                { AON__GLITCHFILTER__IGF_NS }
#else
  /** Peripheral AON__GLITCHFILTER__IGF base address */
  #define AON__GLITCHFILTER__IGF_BASE              (0x446E0000u)
  /** Peripheral AON__GLITCHFILTER__IGF base pointer */
  #define AON__GLITCHFILTER__IGF                   ((GLITCHFILTER_Type *)AON__GLITCHFILTER__IGF_BASE)
  /** Array initializer of GLITCHFILTER peripheral base addresses */
  #define GLITCHFILTER_BASE_ADDRS                  { AON__GLITCHFILTER__IGF_BASE }
  /** Array initializer of GLITCHFILTER peripheral base pointers */
  #define GLITCHFILTER_BASE_PTRS                   { AON__GLITCHFILTER__IGF }
#endif

/* GPC_CPU_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_0 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE     (0x54471000u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_0 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE_NS  (0x44471000u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_0 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_0          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_0 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_0_NS       ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE_NS)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_1 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE     (0x54471800u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_1 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE_NS  (0x44471800u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_1 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_1          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_1 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_1_NS       ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE_NS)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_2 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE     (0x54472000u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_2 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE_NS  (0x44472000u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_2 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_2          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_2 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_2_NS       ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE_NS)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_3 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE     (0x54472800u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_3 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE_NS  (0x44472800u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_3 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_3          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_3 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_3_NS       ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE_NS)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE (0x54473000u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE_NS (0x44473000u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER    ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_NS ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE_NS)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE        (0x54470800u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE_NS     (0x44470800u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM7             ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM7_NS          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE_NS)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7_2 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM7_2_BASE      (0x54473800u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7_2 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM7_2_BASE_NS   (0x44473800u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7_2 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM7_2           ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CM7_2_BASE)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7_2 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM7_2_NS        ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CM7_2_BASE_NS)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM33 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE       (0x54470000u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM33 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE_NS    (0x44470000u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM33 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM33            ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM33 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_CM33_NS         ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE_NS)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33_BASE  (0x54474000u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33 base address */
  #define CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33_BASE_NS (0x44474000u)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33       ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33_BASE)
  /** Peripheral CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33 base pointer */
  #define CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33_NS    ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33_BASE_NS)
  /** Array initializer of GPC_CPU_CTRL peripheral base addresses */
  #define GPC_CPU_CTRL_BASE_ADDRS                  { CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE, CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE, CCMSRCGPC__GPC__GPC_CTRL_CM7_2_BASE, CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE, CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33_BASE }
  /** Array initializer of GPC_CPU_CTRL peripheral base pointers */
  #define GPC_CPU_CTRL_BASE_PTRS                   { CCMSRCGPC__GPC__GPC_CTRL_CA55_0, CCMSRCGPC__GPC__GPC_CTRL_CA55_1, CCMSRCGPC__GPC__GPC_CTRL_CA55_2, CCMSRCGPC__GPC__GPC_CTRL_CA55_3, CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER, CCMSRCGPC__GPC__GPC_CTRL_CM7, CCMSRCGPC__GPC__GPC_CTRL_CM7_2, CCMSRCGPC__GPC__GPC_CTRL_CM33, CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33 }
  /** Array initializer of GPC_CPU_CTRL peripheral base addresses */
  #define GPC_CPU_CTRL_BASE_ADDRS_NS               { CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE_NS, CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE_NS, CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE_NS, CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE_NS, CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE_NS, CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE_NS, CCMSRCGPC__GPC__GPC_CTRL_CM7_2_BASE_NS, CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE_NS, CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33_BASE_NS }
  /** Array initializer of GPC_CPU_CTRL peripheral base pointers */
  #define GPC_CPU_CTRL_BASE_PTRS_NS                { CCMSRCGPC__GPC__GPC_CTRL_CA55_0_NS, CCMSRCGPC__GPC__GPC_CTRL_CA55_1_NS, CCMSRCGPC__GPC__GPC_CTRL_CA55_2_NS, CCMSRCGPC__GPC__GPC_CTRL_CA55_3_NS, CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_NS, CCMSRCGPC__GPC__GPC_CTRL_CM7_NS, CCMSRCGPC__GPC__GPC_CTRL_CM7_2_NS, CCMSRCGPC__GPC__GPC_CTRL_CM33_NS, CCMSRCGPC__GPC__GPC_CTRL_NETC_CM33_NS }
#else
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
#endif

/* GPC_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPC_GLOBAL base address */
  #define GPC_GLOBAL_BASE                          (0x54474800u)
  /** Peripheral GPC_GLOBAL base address */
  #define GPC_GLOBAL_BASE_NS                       (0x44474800u)
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
  #define GPC_GLOBAL_BASE                          (0x44474800u)
  /** Peripheral GPC_GLOBAL base pointer */
  #define GPC_GLOBAL                               ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE)
  /** Array initializer of GPC_GLOBAL peripheral base addresses */
  #define GPC_GLOBAL_BASE_ADDRS                    { GPC_GLOBAL_BASE }
  /** Array initializer of GPC_GLOBAL peripheral base pointers */
  #define GPC_GLOBAL_BASE_PTRS                     { GPC_GLOBAL }
#endif

/* GPT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPT1 base address */
  #define GPT1_BASE                                (0x546F0000u)
  /** Peripheral GPT1 base address */
  #define GPT1_BASE_NS                             (0x446F0000u)
  /** Peripheral GPT1 base pointer */
  #define GPT1                                     ((GPT_Type *)GPT1_BASE)
  /** Peripheral GPT1 base pointer */
  #define GPT1_NS                                  ((GPT_Type *)GPT1_BASE_NS)
  /** Array initializer of GPT peripheral base addresses */
  #define GPT_BASE_ADDRS                           { GPT1_BASE }
  /** Array initializer of GPT peripheral base pointers */
  #define GPT_BASE_PTRS                            { GPT1 }
  /** Array initializer of GPT peripheral base addresses */
  #define GPT_BASE_ADDRS_NS                        { GPT1_BASE_NS }
  /** Array initializer of GPT peripheral base pointers */
  #define GPT_BASE_PTRS_NS                         { GPT1_NS }
#else
  /** Peripheral GPT1 base address */
  #define GPT1_BASE                                (0x446F0000u)
  /** Peripheral GPT1 base pointer */
  #define GPT1                                     ((GPT_Type *)GPT1_BASE)
  /** Array initializer of GPT peripheral base addresses */
  #define GPT_BASE_ADDRS                           { GPT1_BASE }
  /** Array initializer of GPT peripheral base pointers */
  #define GPT_BASE_PTRS                            { GPT1 }
#endif

/* HIPERFACE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HIPERFACE1 base address */
  #define HIPERFACE1_BASE                          (0x52CF0000u)
  /** Peripheral HIPERFACE1 base address */
  #define HIPERFACE1_BASE_NS                       (0x42CF0000u)
  /** Peripheral HIPERFACE1 base pointer */
  #define HIPERFACE1                               ((HIPERFACE_Type *)HIPERFACE1_BASE)
  /** Peripheral HIPERFACE1 base pointer */
  #define HIPERFACE1_NS                            ((HIPERFACE_Type *)HIPERFACE1_BASE_NS)
  /** Peripheral HIPERFACE2 base address */
  #define HIPERFACE2_BASE                          (0x52D20000u)
  /** Peripheral HIPERFACE2 base address */
  #define HIPERFACE2_BASE_NS                       (0x42D20000u)
  /** Peripheral HIPERFACE2 base pointer */
  #define HIPERFACE2                               ((HIPERFACE_Type *)HIPERFACE2_BASE)
  /** Peripheral HIPERFACE2 base pointer */
  #define HIPERFACE2_NS                            ((HIPERFACE_Type *)HIPERFACE2_BASE_NS)
  /** Array initializer of HIPERFACE peripheral base addresses */
  #define HIPERFACE_BASE_ADDRS                     { HIPERFACE1_BASE, HIPERFACE2_BASE }
  /** Array initializer of HIPERFACE peripheral base pointers */
  #define HIPERFACE_BASE_PTRS                      { HIPERFACE1, HIPERFACE2 }
  /** Array initializer of HIPERFACE peripheral base addresses */
  #define HIPERFACE_BASE_ADDRS_NS                  { HIPERFACE1_BASE_NS, HIPERFACE2_BASE_NS }
  /** Array initializer of HIPERFACE peripheral base pointers */
  #define HIPERFACE_BASE_PTRS_NS                   { HIPERFACE1_NS, HIPERFACE2_NS }
#else
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
#endif

/* HSIO_BLK_CTRL_HSIOMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_HSIOMIX base address */
  #define BLK_CTRL_HSIOMIX_BASE                    (0x5C010000u)
  /** Peripheral BLK_CTRL_HSIOMIX base address */
  #define BLK_CTRL_HSIOMIX_BASE_NS                 (0x4C010000u)
  /** Peripheral BLK_CTRL_HSIOMIX base pointer */
  #define BLK_CTRL_HSIOMIX                         ((HSIO_BLK_CTRL_HSIOMIX_Type *)BLK_CTRL_HSIOMIX_BASE)
  /** Peripheral BLK_CTRL_HSIOMIX base pointer */
  #define BLK_CTRL_HSIOMIX_NS                      ((HSIO_BLK_CTRL_HSIOMIX_Type *)BLK_CTRL_HSIOMIX_BASE_NS)
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base addresses */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_ADDRS         { BLK_CTRL_HSIOMIX_BASE }
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base pointers */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_PTRS          { BLK_CTRL_HSIOMIX }
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base addresses */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_ADDRS_NS      { BLK_CTRL_HSIOMIX_BASE_NS }
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base pointers */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_PTRS_NS       { BLK_CTRL_HSIOMIX_NS }
#else
  /** Peripheral BLK_CTRL_HSIOMIX base address */
  #define BLK_CTRL_HSIOMIX_BASE                    (0x4C010000u)
  /** Peripheral BLK_CTRL_HSIOMIX base pointer */
  #define BLK_CTRL_HSIOMIX                         ((HSIO_BLK_CTRL_HSIOMIX_Type *)BLK_CTRL_HSIOMIX_BASE)
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base addresses */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_ADDRS         { BLK_CTRL_HSIOMIX_BASE }
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base pointers */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_PTRS          { BLK_CTRL_HSIOMIX }
#endif

/* HSIO_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__TCU base address */
  #define HSIO__TCU_BASE                           (0x5C000000u)
  /** Peripheral HSIO__TCU base address */
  #define HSIO__TCU_BASE_NS                        (0x4C000000u)
  /** Peripheral HSIO__TCU base pointer */
  #define HSIO__TCU                                ((HSIO_TCU_Type *)HSIO__TCU_BASE)
  /** Peripheral HSIO__TCU base pointer */
  #define HSIO__TCU_NS                             ((HSIO_TCU_Type *)HSIO__TCU_BASE_NS)
  /** Array initializer of HSIO_TCU peripheral base addresses */
  #define HSIO_TCU_BASE_ADDRS                      { HSIO__TCU_BASE }
  /** Array initializer of HSIO_TCU peripheral base pointers */
  #define HSIO_TCU_BASE_PTRS                       { HSIO__TCU }
  /** Array initializer of HSIO_TCU peripheral base addresses */
  #define HSIO_TCU_BASE_ADDRS_NS                   { HSIO__TCU_BASE_NS }
  /** Array initializer of HSIO_TCU peripheral base pointers */
  #define HSIO_TCU_BASE_PTRS_NS                    { HSIO__TCU_NS }
#else
  /** Peripheral HSIO__TCU base address */
  #define HSIO__TCU_BASE                           (0x4C000000u)
  /** Peripheral HSIO__TCU base pointer */
  #define HSIO__TCU                                ((HSIO_TCU_Type *)HSIO__TCU_BASE)
  /** Array initializer of HSIO_TCU peripheral base addresses */
  #define HSIO_TCU_BASE_ADDRS                      { HSIO__TCU_BASE }
  /** Array initializer of HSIO_TCU peripheral base pointers */
  #define HSIO_TCU_BASE_PTRS                       { HSIO__TCU }
#endif

/* HSIO_TRDC_MGR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__TRDC_MGR_HSIOMIX base address */
  #define HSIO__TRDC_MGR_HSIOMIX_BASE              (0x5C040000u)
  /** Peripheral HSIO__TRDC_MGR_HSIOMIX base address */
  #define HSIO__TRDC_MGR_HSIOMIX_BASE_NS           (0x4C040000u)
  /** Peripheral HSIO__TRDC_MGR_HSIOMIX base pointer */
  #define HSIO__TRDC_MGR_HSIOMIX                   ((HSIO_TRDC_MGR_Type *)HSIO__TRDC_MGR_HSIOMIX_BASE)
  /** Peripheral HSIO__TRDC_MGR_HSIOMIX base pointer */
  #define HSIO__TRDC_MGR_HSIOMIX_NS                ((HSIO_TRDC_MGR_Type *)HSIO__TRDC_MGR_HSIOMIX_BASE_NS)
  /** Array initializer of HSIO_TRDC_MGR peripheral base addresses */
  #define HSIO_TRDC_MGR_BASE_ADDRS                 { HSIO__TRDC_MGR_HSIOMIX_BASE }
  /** Array initializer of HSIO_TRDC_MGR peripheral base pointers */
  #define HSIO_TRDC_MGR_BASE_PTRS                  { HSIO__TRDC_MGR_HSIOMIX }
  /** Array initializer of HSIO_TRDC_MGR peripheral base addresses */
  #define HSIO_TRDC_MGR_BASE_ADDRS_NS              { HSIO__TRDC_MGR_HSIOMIX_BASE_NS }
  /** Array initializer of HSIO_TRDC_MGR peripheral base pointers */
  #define HSIO_TRDC_MGR_BASE_PTRS_NS               { HSIO__TRDC_MGR_HSIOMIX_NS }
#else
  /** Peripheral HSIO__TRDC_MGR_HSIOMIX base address */
  #define HSIO__TRDC_MGR_HSIOMIX_BASE              (0x4C040000u)
  /** Peripheral HSIO__TRDC_MGR_HSIOMIX base pointer */
  #define HSIO__TRDC_MGR_HSIOMIX                   ((HSIO_TRDC_MGR_Type *)HSIO__TRDC_MGR_HSIOMIX_BASE)
  /** Array initializer of HSIO_TRDC_MGR peripheral base addresses */
  #define HSIO_TRDC_MGR_BASE_ADDRS                 { HSIO__TRDC_MGR_HSIOMIX_BASE }
  /** Array initializer of HSIO_TRDC_MGR peripheral base pointers */
  #define HSIO_TRDC_MGR_BASE_PTRS                  { HSIO__TRDC_MGR_HSIOMIX }
#endif

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
  /** Peripheral SAI3 base address */
  #define SAI3_BASE                                (0x52660000u)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE_NS                             (0x42660000u)
  /** Peripheral SAI3 base pointer */
  #define SAI3                                     ((I2S_Type *)SAI3_BASE)
  /** Peripheral SAI3 base pointer */
  #define SAI3_NS                                  ((I2S_Type *)SAI3_BASE_NS)
  /** Peripheral SAI4 base address */
  #define SAI4_BASE                                (0x52670000u)
  /** Peripheral SAI4 base address */
  #define SAI4_BASE_NS                             (0x42670000u)
  /** Peripheral SAI4 base pointer */
  #define SAI4                                     ((I2S_Type *)SAI4_BASE)
  /** Peripheral SAI4 base pointer */
  #define SAI4_NS                                  ((I2S_Type *)SAI4_BASE_NS)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, 0u, SAI3_BASE, SAI4_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, (I2S_Type *)0u, SAI3, SAI4 }
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS_NS                        { 0u, SAI1_BASE_NS, 0u, SAI3_BASE_NS, SAI4_BASE_NS }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS_NS                         { (I2S_Type *)0u, SAI1_NS, (I2S_Type *)0u, SAI3_NS, SAI4_NS }
#else
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
#endif
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, NotAvail_IRQn, SAI3_IRQn, SAI4_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, NotAvail_IRQn, SAI3_IRQn, SAI4_IRQn }

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

/* IOMUXC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOMUXC base address */
  #define IOMUXC_BASE                              (0x543C0000u)
  /** Peripheral IOMUXC base address */
  #define IOMUXC_BASE_NS                           (0x443C0000u)
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
  #define IOMUXC_BASE                              (0x443C0000u)
  /** Peripheral IOMUXC base pointer */
  #define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
  /** Array initializer of IOMUXC peripheral base addresses */
  #define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
  /** Array initializer of IOMUXC peripheral base pointers */
  #define IOMUXC_BASE_PTRS                         { IOMUXC }
#endif

/* IOMUXC_GPR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOMUXC_GPR base address */
  #define IOMUXC_GPR_BASE                          (0x543D0000u)
  /** Peripheral IOMUXC_GPR base address */
  #define IOMUXC_GPR_BASE_NS                       (0x443D0000u)
  /** Peripheral IOMUXC_GPR base pointer */
  #define IOMUXC_GPR                               ((IOMUXC_GPR_Type *)IOMUXC_GPR_BASE)
  /** Peripheral IOMUXC_GPR base pointer */
  #define IOMUXC_GPR_NS                            ((IOMUXC_GPR_Type *)IOMUXC_GPR_BASE_NS)
  /** Array initializer of IOMUXC_GPR peripheral base addresses */
  #define IOMUXC_GPR_BASE_ADDRS                    { IOMUXC_GPR_BASE }
  /** Array initializer of IOMUXC_GPR peripheral base pointers */
  #define IOMUXC_GPR_BASE_PTRS                     { IOMUXC_GPR }
  /** Array initializer of IOMUXC_GPR peripheral base addresses */
  #define IOMUXC_GPR_BASE_ADDRS_NS                 { IOMUXC_GPR_BASE_NS }
  /** Array initializer of IOMUXC_GPR peripheral base pointers */
  #define IOMUXC_GPR_BASE_PTRS_NS                  { IOMUXC_GPR_NS }
#else
  /** Peripheral IOMUXC_GPR base address */
  #define IOMUXC_GPR_BASE                          (0x443D0000u)
  /** Peripheral IOMUXC_GPR base pointer */
  #define IOMUXC_GPR                               ((IOMUXC_GPR_Type *)IOMUXC_GPR_BASE)
  /** Array initializer of IOMUXC_GPR peripheral base addresses */
  #define IOMUXC_GPR_BASE_ADDRS                    { IOMUXC_GPR_BASE }
  /** Array initializer of IOMUXC_GPR peripheral base pointers */
  #define IOMUXC_GPR_BASE_PTRS                     { IOMUXC_GPR }
#endif

/* IRQSTEER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IRQSTEERM33 base address */
  #define IRQSTEERM33_BASE                         (0x54760000u)
  /** Peripheral IRQSTEERM33 base address */
  #define IRQSTEERM33_BASE_NS                      (0x44760000u)
  /** Peripheral IRQSTEERM33 base pointer */
  #define IRQSTEERM33                              ((IRQSTEER_Type *)IRQSTEERM33_BASE)
  /** Peripheral IRQSTEERM33 base pointer */
  #define IRQSTEERM33_NS                           ((IRQSTEER_Type *)IRQSTEERM33_BASE_NS)
  /** Array initializer of IRQSTEER peripheral base addresses */
  #define IRQSTEER_BASE_ADDRS                      { IRQSTEERM33_BASE }
  /** Array initializer of IRQSTEER peripheral base pointers */
  #define IRQSTEER_BASE_PTRS                       { IRQSTEERM33 }
  /** Array initializer of IRQSTEER peripheral base addresses */
  #define IRQSTEER_BASE_ADDRS_NS                   { IRQSTEERM33_BASE_NS }
  /** Array initializer of IRQSTEER peripheral base pointers */
  #define IRQSTEER_BASE_PTRS_NS                    { IRQSTEERM33_NS }
#else
  /** Peripheral IRQSTEERM33 base address */
  #define IRQSTEERM33_BASE                         (0x44760000u)
  /** Peripheral IRQSTEERM33 base pointer */
  #define IRQSTEERM33                              ((IRQSTEER_Type *)IRQSTEERM33_BASE)
  /** Array initializer of IRQSTEER peripheral base addresses */
  #define IRQSTEER_BASE_ADDRS                      { IRQSTEERM33_BASE }
  /** Array initializer of IRQSTEER peripheral base pointers */
  #define IRQSTEER_BASE_PTRS                       { IRQSTEERM33 }
#endif

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
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE                              (0x52540000u)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE_NS                           (0x42540000u)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4_NS                                ((LPI2C_Type *)LPI2C4_BASE_NS)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE                              (0x526B0000u)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE_NS                           (0x426B0000u)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5_NS                                ((LPI2C_Type *)LPI2C5_BASE_NS)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE                              (0x526C0000u)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE_NS                           (0x426C0000u)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6_NS                                ((LPI2C_Type *)LPI2C6_BASE_NS)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE                              (0x526D0000u)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE_NS                           (0x426D0000u)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7_NS                                ((LPI2C_Type *)LPI2C7_BASE_NS)
  /** Peripheral LPI2C8 base address */
  #define LPI2C8_BASE                              (0x526E0000u)
  /** Peripheral LPI2C8 base address */
  #define LPI2C8_BASE_NS                           (0x426E0000u)
  /** Peripheral LPI2C8 base pointer */
  #define LPI2C8                                   ((LPI2C_Type *)LPI2C8_BASE)
  /** Peripheral LPI2C8 base pointer */
  #define LPI2C8_NS                                ((LPI2C_Type *)LPI2C8_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE, LPI2C8_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7, LPI2C8 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { 0u, LPI2C1_BASE_NS, LPI2C2_BASE_NS, LPI2C3_BASE_NS, LPI2C4_BASE_NS, LPI2C5_BASE_NS, LPI2C6_BASE_NS, LPI2C7_BASE_NS, LPI2C8_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { (LPI2C_Type *)0u, LPI2C1_NS, LPI2C2_NS, LPI2C3_NS, LPI2C4_NS, LPI2C5_NS, LPI2C6_NS, LPI2C7_NS, LPI2C8_NS }
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
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn, LPI2C4_IRQn, LPI2C5_IRQn, LPI2C6_IRQn, LPI2C7_IRQn, LPI2C8_IRQn }

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
  #define LPIT3_BASE                               (0x527F0000u)
  /** Peripheral LPIT3 base address */
  #define LPIT3_BASE_NS                            (0x427F0000u)
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
  #define LPIT3_BASE                               (0x427F0000u)
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
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE                              (0x526F0000u)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE_NS                           (0x426F0000u)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5_NS                                ((LPSPI_Type *)LPSPI5_BASE_NS)
  /** Peripheral LPSPI6 base address */
  #define LPSPI6_BASE                              (0x52700000u)
  /** Peripheral LPSPI6 base address */
  #define LPSPI6_BASE_NS                           (0x42700000u)
  /** Peripheral LPSPI6 base pointer */
  #define LPSPI6                                   ((LPSPI_Type *)LPSPI6_BASE)
  /** Peripheral LPSPI6 base pointer */
  #define LPSPI6_NS                                ((LPSPI_Type *)LPSPI6_BASE_NS)
  /** Peripheral LPSPI7 base address */
  #define LPSPI7_BASE                              (0x52710000u)
  /** Peripheral LPSPI7 base address */
  #define LPSPI7_BASE_NS                           (0x42710000u)
  /** Peripheral LPSPI7 base pointer */
  #define LPSPI7                                   ((LPSPI_Type *)LPSPI7_BASE)
  /** Peripheral LPSPI7 base pointer */
  #define LPSPI7_NS                                ((LPSPI_Type *)LPSPI7_BASE_NS)
  /** Peripheral LPSPI8 base address */
  #define LPSPI8_BASE                              (0x52720000u)
  /** Peripheral LPSPI8 base address */
  #define LPSPI8_BASE_NS                           (0x42720000u)
  /** Peripheral LPSPI8 base pointer */
  #define LPSPI8                                   ((LPSPI_Type *)LPSPI8_BASE)
  /** Peripheral LPSPI8 base pointer */
  #define LPSPI8_NS                                ((LPSPI_Type *)LPSPI8_BASE_NS)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE, LPSPI6_BASE, LPSPI7_BASE, LPSPI8_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5, LPSPI6, LPSPI7, LPSPI8 }
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS_NS                      { 0u, LPSPI1_BASE_NS, LPSPI2_BASE_NS, LPSPI3_BASE_NS, LPSPI4_BASE_NS, LPSPI5_BASE_NS, LPSPI6_BASE_NS, LPSPI7_BASE_NS, LPSPI8_BASE_NS }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS_NS                       { (LPSPI_Type *)0u, LPSPI1_NS, LPSPI2_NS, LPSPI3_NS, LPSPI4_NS, LPSPI5_NS, LPSPI6_NS, LPSPI7_NS, LPSPI8_NS }
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
#endif
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, LPSPI4_IRQn, LPSPI5_IRQn, LPSPI6_IRQn, LPSPI7_IRQn, LPSPI8_IRQn }

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
  /** Peripheral LPTMR2 base address */
  #define LPTMR2_BASE                              (0x524D0000u)
  /** Peripheral LPTMR2 base address */
  #define LPTMR2_BASE_NS                           (0x424D0000u)
  /** Peripheral LPTMR2 base pointer */
  #define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
  /** Peripheral LPTMR2 base pointer */
  #define LPTMR2_NS                                ((LPTMR_Type *)LPTMR2_BASE_NS)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { 0u, LPTMR1_BASE, LPTMR2_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { (LPTMR_Type *)0u, LPTMR1, LPTMR2 }
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS_NS                      { 0u, LPTMR1_BASE_NS, LPTMR2_BASE_NS }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS_NS                       { (LPTMR_Type *)0u, LPTMR1_NS, LPTMR2_NS }
#else
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
#endif
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { NotAvail_IRQn, LPTMR1_IRQn, LPTMR2_IRQn }

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
  #define LPUART7_BASE                             (0x52690000u)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE_NS                          (0x42690000u)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7_NS                               ((LPUART_Type *)LPUART7_BASE_NS)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE                             (0x526A0000u)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE_NS                          (0x426A0000u)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8_NS                               ((LPUART_Type *)LPUART8_BASE_NS)
  /** Peripheral LPUART9 base address */
  #define LPUART9_BASE                             (0x52A50000u)
  /** Peripheral LPUART9 base address */
  #define LPUART9_BASE_NS                          (0x42A50000u)
  /** Peripheral LPUART9 base pointer */
  #define LPUART9                                  ((LPUART_Type *)LPUART9_BASE)
  /** Peripheral LPUART9 base pointer */
  #define LPUART9_NS                               ((LPUART_Type *)LPUART9_BASE_NS)
  /** Peripheral LPUART10 base address */
  #define LPUART10_BASE                            (0x52A60000u)
  /** Peripheral LPUART10 base address */
  #define LPUART10_BASE_NS                         (0x42A60000u)
  /** Peripheral LPUART10 base pointer */
  #define LPUART10                                 ((LPUART_Type *)LPUART10_BASE)
  /** Peripheral LPUART10 base pointer */
  #define LPUART10_NS                              ((LPUART_Type *)LPUART10_BASE_NS)
  /** Peripheral LPUART11 base address */
  #define LPUART11_BASE                            (0x52A70000u)
  /** Peripheral LPUART11 base address */
  #define LPUART11_BASE_NS                         (0x42A70000u)
  /** Peripheral LPUART11 base pointer */
  #define LPUART11                                 ((LPUART_Type *)LPUART11_BASE)
  /** Peripheral LPUART11 base pointer */
  #define LPUART11_NS                              ((LPUART_Type *)LPUART11_BASE_NS)
  /** Peripheral LPUART12 base address */
  #define LPUART12_BASE                            (0x52A80000u)
  /** Peripheral LPUART12 base address */
  #define LPUART12_BASE_NS                         (0x42A80000u)
  /** Peripheral LPUART12 base pointer */
  #define LPUART12                                 ((LPUART_Type *)LPUART12_BASE)
  /** Peripheral LPUART12 base pointer */
  #define LPUART12_NS                              ((LPUART_Type *)LPUART12_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE, LPUART9_BASE, LPUART10_BASE, LPUART11_BASE, LPUART12_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8, LPUART9, LPUART10, LPUART11, LPUART12 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { 0u, LPUART1_BASE_NS, LPUART2_BASE_NS, LPUART3_BASE_NS, LPUART4_BASE_NS, LPUART5_BASE_NS, LPUART6_BASE_NS, LPUART7_BASE_NS, LPUART8_BASE_NS, LPUART9_BASE_NS, LPUART10_BASE_NS, LPUART11_BASE_NS, LPUART12_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { (LPUART_Type *)0u, LPUART1_NS, LPUART2_NS, LPUART3_NS, LPUART4_NS, LPUART5_NS, LPUART6_NS, LPUART7_NS, LPUART8_NS, LPUART9_NS, LPUART10_NS, LPUART11_NS, LPUART12_NS }
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
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, LPUART9_IRQn, LPUART10_IRQn, LPUART11_IRQn, LPUART12_IRQn }

/* M7_A7_APB_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral M7_1__A7_APB_MCM1 base address */
  #define M7_1__A7_APB_MCM1_BASE                   (0x59CA0000u)
  /** Peripheral M7_1__A7_APB_MCM1 base address */
  #define M7_1__A7_APB_MCM1_BASE_NS                (0x49CA0000u)
  /** Peripheral M7_1__A7_APB_MCM1 base pointer */
  #define M7_1__A7_APB_MCM1                        ((M7_A7_APB_MCM_Type *)M7_1__A7_APB_MCM1_BASE)
  /** Peripheral M7_1__A7_APB_MCM1 base pointer */
  #define M7_1__A7_APB_MCM1_NS                     ((M7_A7_APB_MCM_Type *)M7_1__A7_APB_MCM1_BASE_NS)
  /** Peripheral M7__A7_APB_MCM1 base address */
  #define M7__A7_APB_MCM1_BASE                     (0x5A0A0000u)
  /** Peripheral M7__A7_APB_MCM1 base address */
  #define M7__A7_APB_MCM1_BASE_NS                  (0x4A0A0000u)
  /** Peripheral M7__A7_APB_MCM1 base pointer */
  #define M7__A7_APB_MCM1                          ((M7_A7_APB_MCM_Type *)M7__A7_APB_MCM1_BASE)
  /** Peripheral M7__A7_APB_MCM1 base pointer */
  #define M7__A7_APB_MCM1_NS                       ((M7_A7_APB_MCM_Type *)M7__A7_APB_MCM1_BASE_NS)
  /** Array initializer of M7_A7_APB_MCM peripheral base addresses */
  #define M7_A7_APB_MCM_BASE_ADDRS                 { M7_1__A7_APB_MCM1_BASE, M7__A7_APB_MCM1_BASE }
  /** Array initializer of M7_A7_APB_MCM peripheral base pointers */
  #define M7_A7_APB_MCM_BASE_PTRS                  { M7_1__A7_APB_MCM1, M7__A7_APB_MCM1 }
  /** Array initializer of M7_A7_APB_MCM peripheral base addresses */
  #define M7_A7_APB_MCM_BASE_ADDRS_NS              { M7_1__A7_APB_MCM1_BASE_NS, M7__A7_APB_MCM1_BASE_NS }
  /** Array initializer of M7_A7_APB_MCM peripheral base pointers */
  #define M7_A7_APB_MCM_BASE_PTRS_NS               { M7_1__A7_APB_MCM1_NS, M7__A7_APB_MCM1_NS }
#else
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
#endif

/* M7_CMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral M7_1__CMU_M0 base address */
  #define M7_1__CMU_M0_BASE                        (0x59C80000u)
  /** Peripheral M7_1__CMU_M0 base address */
  #define M7_1__CMU_M0_BASE_NS                     (0x49C80000u)
  /** Peripheral M7_1__CMU_M0 base pointer */
  #define M7_1__CMU_M0                             ((M7_CMU_Type *)M7_1__CMU_M0_BASE)
  /** Peripheral M7_1__CMU_M0 base pointer */
  #define M7_1__CMU_M0_NS                          ((M7_CMU_Type *)M7_1__CMU_M0_BASE_NS)
  /** Peripheral M7_1__CMU_M1 base address */
  #define M7_1__CMU_M1_BASE                        (0x59C90000u)
  /** Peripheral M7_1__CMU_M1 base address */
  #define M7_1__CMU_M1_BASE_NS                     (0x49C90000u)
  /** Peripheral M7_1__CMU_M1 base pointer */
  #define M7_1__CMU_M1                             ((M7_CMU_Type *)M7_1__CMU_M1_BASE)
  /** Peripheral M7_1__CMU_M1 base pointer */
  #define M7_1__CMU_M1_NS                          ((M7_CMU_Type *)M7_1__CMU_M1_BASE_NS)
  /** Peripheral M7__CMU_M0 base address */
  #define M7__CMU_M0_BASE                          (0x5A080000u)
  /** Peripheral M7__CMU_M0 base address */
  #define M7__CMU_M0_BASE_NS                       (0x4A080000u)
  /** Peripheral M7__CMU_M0 base pointer */
  #define M7__CMU_M0                               ((M7_CMU_Type *)M7__CMU_M0_BASE)
  /** Peripheral M7__CMU_M0 base pointer */
  #define M7__CMU_M0_NS                            ((M7_CMU_Type *)M7__CMU_M0_BASE_NS)
  /** Peripheral M7__CMU_M1 base address */
  #define M7__CMU_M1_BASE                          (0x5A090000u)
  /** Peripheral M7__CMU_M1 base address */
  #define M7__CMU_M1_BASE_NS                       (0x4A090000u)
  /** Peripheral M7__CMU_M1 base pointer */
  #define M7__CMU_M1                               ((M7_CMU_Type *)M7__CMU_M1_BASE)
  /** Peripheral M7__CMU_M1 base pointer */
  #define M7__CMU_M1_NS                            ((M7_CMU_Type *)M7__CMU_M1_BASE_NS)
  /** Array initializer of M7_CMU peripheral base addresses */
  #define M7_CMU_BASE_ADDRS                        { M7_1__CMU_M0_BASE, M7_1__CMU_M1_BASE, M7__CMU_M0_BASE, M7__CMU_M1_BASE }
  /** Array initializer of M7_CMU peripheral base pointers */
  #define M7_CMU_BASE_PTRS                         { M7_1__CMU_M0, M7_1__CMU_M1, M7__CMU_M0, M7__CMU_M1 }
  /** Array initializer of M7_CMU peripheral base addresses */
  #define M7_CMU_BASE_ADDRS_NS                     { M7_1__CMU_M0_BASE_NS, M7_1__CMU_M1_BASE_NS, M7__CMU_M0_BASE_NS, M7__CMU_M1_BASE_NS }
  /** Array initializer of M7_CMU peripheral base pointers */
  #define M7_CMU_BASE_PTRS_NS                      { M7_1__CMU_M0_NS, M7_1__CMU_M1_NS, M7__CMU_M0_NS, M7__CMU_M1_NS }
#else
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
#endif

/* M7_EIM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral M7_1__EIM base address */
  #define M7_1__EIM_BASE                           (0x59C60000u)
  /** Peripheral M7_1__EIM base address */
  #define M7_1__EIM_BASE_NS                        (0x49C60000u)
  /** Peripheral M7_1__EIM base pointer */
  #define M7_1__EIM                                ((M7_EIM_Type *)M7_1__EIM_BASE)
  /** Peripheral M7_1__EIM base pointer */
  #define M7_1__EIM_NS                             ((M7_EIM_Type *)M7_1__EIM_BASE_NS)
  /** Peripheral M7__EIM base address */
  #define M7__EIM_BASE                             (0x5A060000u)
  /** Peripheral M7__EIM base address */
  #define M7__EIM_BASE_NS                          (0x4A060000u)
  /** Peripheral M7__EIM base pointer */
  #define M7__EIM                                  ((M7_EIM_Type *)M7__EIM_BASE)
  /** Peripheral M7__EIM base pointer */
  #define M7__EIM_NS                               ((M7_EIM_Type *)M7__EIM_BASE_NS)
  /** Array initializer of M7_EIM peripheral base addresses */
  #define M7_EIM_BASE_ADDRS                        { M7_1__EIM_BASE, M7__EIM_BASE }
  /** Array initializer of M7_EIM peripheral base pointers */
  #define M7_EIM_BASE_PTRS                         { M7_1__EIM, M7__EIM }
  /** Array initializer of M7_EIM peripheral base addresses */
  #define M7_EIM_BASE_ADDRS_NS                     { M7_1__EIM_BASE_NS, M7__EIM_BASE_NS }
  /** Array initializer of M7_EIM peripheral base pointers */
  #define M7_EIM_BASE_PTRS_NS                      { M7_1__EIM_NS, M7__EIM_NS }
#else
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
#endif

/* M7_ERM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral M7_1__ERM base address */
  #define M7_1__ERM_BASE                           (0x59C70000u)
  /** Peripheral M7_1__ERM base address */
  #define M7_1__ERM_BASE_NS                        (0x49C70000u)
  /** Peripheral M7_1__ERM base pointer */
  #define M7_1__ERM                                ((M7_ERM_Type *)M7_1__ERM_BASE)
  /** Peripheral M7_1__ERM base pointer */
  #define M7_1__ERM_NS                             ((M7_ERM_Type *)M7_1__ERM_BASE_NS)
  /** Peripheral M7__ERM base address */
  #define M7__ERM_BASE                             (0x5A070000u)
  /** Peripheral M7__ERM base address */
  #define M7__ERM_BASE_NS                          (0x4A070000u)
  /** Peripheral M7__ERM base pointer */
  #define M7__ERM                                  ((M7_ERM_Type *)M7__ERM_BASE)
  /** Peripheral M7__ERM base pointer */
  #define M7__ERM_NS                               ((M7_ERM_Type *)M7__ERM_BASE_NS)
  /** Array initializer of M7_ERM peripheral base addresses */
  #define M7_ERM_BASE_ADDRS                        { M7_1__ERM_BASE, M7__ERM_BASE }
  /** Array initializer of M7_ERM peripheral base pointers */
  #define M7_ERM_BASE_PTRS                         { M7_1__ERM, M7__ERM }
  /** Array initializer of M7_ERM peripheral base addresses */
  #define M7_ERM_BASE_ADDRS_NS                     { M7_1__ERM_BASE_NS, M7__ERM_BASE_NS }
  /** Array initializer of M7_ERM peripheral base pointers */
  #define M7_ERM_BASE_PTRS_NS                      { M7_1__ERM_NS, M7__ERM_NS }
#else
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
#endif

/* M7_LSTCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral M7_1__LSTCU_M7MIX base address */
  #define M7_1__LSTCU_M7MIX_BASE                   (0x59C50000u)
  /** Peripheral M7_1__LSTCU_M7MIX base address */
  #define M7_1__LSTCU_M7MIX_BASE_NS                (0x49C50000u)
  /** Peripheral M7_1__LSTCU_M7MIX base pointer */
  #define M7_1__LSTCU_M7MIX                        ((M7_LSTCU_Type *)M7_1__LSTCU_M7MIX_BASE)
  /** Peripheral M7_1__LSTCU_M7MIX base pointer */
  #define M7_1__LSTCU_M7MIX_NS                     ((M7_LSTCU_Type *)M7_1__LSTCU_M7MIX_BASE_NS)
  /** Peripheral M7__LSTCU_M7MIX base address */
  #define M7__LSTCU_M7MIX_BASE                     (0x5A050000u)
  /** Peripheral M7__LSTCU_M7MIX base address */
  #define M7__LSTCU_M7MIX_BASE_NS                  (0x4A050000u)
  /** Peripheral M7__LSTCU_M7MIX base pointer */
  #define M7__LSTCU_M7MIX                          ((M7_LSTCU_Type *)M7__LSTCU_M7MIX_BASE)
  /** Peripheral M7__LSTCU_M7MIX base pointer */
  #define M7__LSTCU_M7MIX_NS                       ((M7_LSTCU_Type *)M7__LSTCU_M7MIX_BASE_NS)
  /** Array initializer of M7_LSTCU peripheral base addresses */
  #define M7_LSTCU_BASE_ADDRS                      { M7_1__LSTCU_M7MIX_BASE, M7__LSTCU_M7MIX_BASE }
  /** Array initializer of M7_LSTCU peripheral base pointers */
  #define M7_LSTCU_BASE_PTRS                       { M7_1__LSTCU_M7MIX, M7__LSTCU_M7MIX }
  /** Array initializer of M7_LSTCU peripheral base addresses */
  #define M7_LSTCU_BASE_ADDRS_NS                   { M7_1__LSTCU_M7MIX_BASE_NS, M7__LSTCU_M7MIX_BASE_NS }
  /** Array initializer of M7_LSTCU peripheral base pointers */
  #define M7_LSTCU_BASE_PTRS_NS                    { M7_1__LSTCU_M7MIX_NS, M7__LSTCU_M7MIX_NS }
#else
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
#endif

/* M7_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral M7_1__TCU base address */
  #define M7_1__TCU_BASE                           (0x59C00000u)
  /** Peripheral M7_1__TCU base address */
  #define M7_1__TCU_BASE_NS                        (0x49C00000u)
  /** Peripheral M7_1__TCU base pointer */
  #define M7_1__TCU                                ((M7_TCU_Type *)M7_1__TCU_BASE)
  /** Peripheral M7_1__TCU base pointer */
  #define M7_1__TCU_NS                             ((M7_TCU_Type *)M7_1__TCU_BASE_NS)
  /** Peripheral M7__TCU base address */
  #define M7__TCU_BASE                             (0x5A000000u)
  /** Peripheral M7__TCU base address */
  #define M7__TCU_BASE_NS                          (0x4A000000u)
  /** Peripheral M7__TCU base pointer */
  #define M7__TCU                                  ((M7_TCU_Type *)M7__TCU_BASE)
  /** Peripheral M7__TCU base pointer */
  #define M7__TCU_NS                               ((M7_TCU_Type *)M7__TCU_BASE_NS)
  /** Array initializer of M7_TCU peripheral base addresses */
  #define M7_TCU_BASE_ADDRS                        { M7_1__TCU_BASE, M7__TCU_BASE }
  /** Array initializer of M7_TCU peripheral base pointers */
  #define M7_TCU_BASE_PTRS                         { M7_1__TCU, M7__TCU }
  /** Array initializer of M7_TCU peripheral base addresses */
  #define M7_TCU_BASE_ADDRS_NS                     { M7_1__TCU_BASE_NS, M7__TCU_BASE_NS }
  /** Array initializer of M7_TCU peripheral base pointers */
  #define M7_TCU_BASE_PTRS_NS                      { M7_1__TCU_NS, M7__TCU_NS }
#else
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
#endif

/* MSGINTR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MSGINTR1 base address */
  #define MSGINTR1_BASE                            (0x52C30000u)
  /** Peripheral MSGINTR1 base address */
  #define MSGINTR1_BASE_NS                         (0x42C30000u)
  /** Peripheral MSGINTR1 base pointer */
  #define MSGINTR1                                 ((MSGINTR_Type *)MSGINTR1_BASE)
  /** Peripheral MSGINTR1 base pointer */
  #define MSGINTR1_NS                              ((MSGINTR_Type *)MSGINTR1_BASE_NS)
  /** Peripheral MSGINTR2 base address */
  #define MSGINTR2_BASE                            (0x52C40000u)
  /** Peripheral MSGINTR2 base address */
  #define MSGINTR2_BASE_NS                         (0x42C40000u)
  /** Peripheral MSGINTR2 base pointer */
  #define MSGINTR2                                 ((MSGINTR_Type *)MSGINTR2_BASE)
  /** Peripheral MSGINTR2 base pointer */
  #define MSGINTR2_NS                              ((MSGINTR_Type *)MSGINTR2_BASE_NS)
  /** Peripheral MSGINTR3 base address */
  #define MSGINTR3_BASE                            (0x52C50000u)
  /** Peripheral MSGINTR3 base address */
  #define MSGINTR3_BASE_NS                         (0x42C50000u)
  /** Peripheral MSGINTR3 base pointer */
  #define MSGINTR3                                 ((MSGINTR_Type *)MSGINTR3_BASE)
  /** Peripheral MSGINTR3 base pointer */
  #define MSGINTR3_NS                              ((MSGINTR_Type *)MSGINTR3_BASE_NS)
  /** Peripheral MSGINTR4 base address */
  #define MSGINTR4_BASE                            (0x52C60000u)
  /** Peripheral MSGINTR4 base address */
  #define MSGINTR4_BASE_NS                         (0x42C60000u)
  /** Peripheral MSGINTR4 base pointer */
  #define MSGINTR4                                 ((MSGINTR_Type *)MSGINTR4_BASE)
  /** Peripheral MSGINTR4 base pointer */
  #define MSGINTR4_NS                              ((MSGINTR_Type *)MSGINTR4_BASE_NS)
  /** Peripheral MSGINTR5 base address */
  #define MSGINTR5_BASE                            (0x52C70000u)
  /** Peripheral MSGINTR5 base address */
  #define MSGINTR5_BASE_NS                         (0x42C70000u)
  /** Peripheral MSGINTR5 base pointer */
  #define MSGINTR5                                 ((MSGINTR_Type *)MSGINTR5_BASE)
  /** Peripheral MSGINTR5 base pointer */
  #define MSGINTR5_NS                              ((MSGINTR_Type *)MSGINTR5_BASE_NS)
  /** Peripheral MSGINTR6 base address */
  #define MSGINTR6_BASE                            (0x52C80000u)
  /** Peripheral MSGINTR6 base address */
  #define MSGINTR6_BASE_NS                         (0x42C80000u)
  /** Peripheral MSGINTR6 base pointer */
  #define MSGINTR6                                 ((MSGINTR_Type *)MSGINTR6_BASE)
  /** Peripheral MSGINTR6 base pointer */
  #define MSGINTR6_NS                              ((MSGINTR_Type *)MSGINTR6_BASE_NS)
  /** Peripheral MSGINTR7 base address */
  #define MSGINTR7_BASE                            (0x52C90000u)
  /** Peripheral MSGINTR7 base address */
  #define MSGINTR7_BASE_NS                         (0x42C90000u)
  /** Peripheral MSGINTR7 base pointer */
  #define MSGINTR7                                 ((MSGINTR_Type *)MSGINTR7_BASE)
  /** Peripheral MSGINTR7 base pointer */
  #define MSGINTR7_NS                              ((MSGINTR_Type *)MSGINTR7_BASE_NS)
  /** Peripheral MSGINTR8 base address */
  #define MSGINTR8_BASE                            (0x52CA0000u)
  /** Peripheral MSGINTR8 base address */
  #define MSGINTR8_BASE_NS                         (0x42CA0000u)
  /** Peripheral MSGINTR8 base pointer */
  #define MSGINTR8                                 ((MSGINTR_Type *)MSGINTR8_BASE)
  /** Peripheral MSGINTR8 base pointer */
  #define MSGINTR8_NS                              ((MSGINTR_Type *)MSGINTR8_BASE_NS)
  /** Array initializer of MSGINTR peripheral base addresses */
  #define MSGINTR_BASE_ADDRS                       { 0u, MSGINTR1_BASE, MSGINTR2_BASE, MSGINTR3_BASE, MSGINTR4_BASE, MSGINTR5_BASE, MSGINTR6_BASE, MSGINTR7_BASE, MSGINTR8_BASE }
  /** Array initializer of MSGINTR peripheral base pointers */
  #define MSGINTR_BASE_PTRS                        { (MSGINTR_Type *)0u, MSGINTR1, MSGINTR2, MSGINTR3, MSGINTR4, MSGINTR5, MSGINTR6, MSGINTR7, MSGINTR8 }
  /** Array initializer of MSGINTR peripheral base addresses */
  #define MSGINTR_BASE_ADDRS_NS                    { 0u, MSGINTR1_BASE_NS, MSGINTR2_BASE_NS, MSGINTR3_BASE_NS, MSGINTR4_BASE_NS, MSGINTR5_BASE_NS, MSGINTR6_BASE_NS, MSGINTR7_BASE_NS, MSGINTR8_BASE_NS }
  /** Array initializer of MSGINTR peripheral base pointers */
  #define MSGINTR_BASE_PTRS_NS                     { (MSGINTR_Type *)0u, MSGINTR1_NS, MSGINTR2_NS, MSGINTR3_NS, MSGINTR4_NS, MSGINTR5_NS, MSGINTR6_NS, MSGINTR7_NS, MSGINTR8_NS }
#else
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
  /** Peripheral MU1_MUB base address */
  #define MU1_MUB_BASE                             (0x54230000u)
  /** Peripheral MU1_MUB base address */
  #define MU1_MUB_BASE_NS                          (0x44230000u)
  /** Peripheral MU1_MUB base pointer */
  #define MU1_MUB                                  ((MU_Type *)MU1_MUB_BASE)
  /** Peripheral MU1_MUB base pointer */
  #define MU1_MUB_NS                               ((MU_Type *)MU1_MUB_BASE_NS)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE                             (0x545B0000u)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE_NS                          (0x445B0000u)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA                                  ((MU_Type *)MU2_MUA_BASE)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA_NS                               ((MU_Type *)MU2_MUA_BASE_NS)
  /** Peripheral MU2_MUB base address */
  #define MU2_MUB_BASE                             (0x545C0000u)
  /** Peripheral MU2_MUB base address */
  #define MU2_MUB_BASE_NS                          (0x445C0000u)
  /** Peripheral MU2_MUB base pointer */
  #define MU2_MUB                                  ((MU_Type *)MU2_MUB_BASE)
  /** Peripheral MU2_MUB base pointer */
  #define MU2_MUB_NS                               ((MU_Type *)MU2_MUB_BASE_NS)
  /** Peripheral MU3_MUA base address */
  #define MU3_MUA_BASE                             (0x545D0000u)
  /** Peripheral MU3_MUA base address */
  #define MU3_MUA_BASE_NS                          (0x445D0000u)
  /** Peripheral MU3_MUA base pointer */
  #define MU3_MUA                                  ((MU_Type *)MU3_MUA_BASE)
  /** Peripheral MU3_MUA base pointer */
  #define MU3_MUA_NS                               ((MU_Type *)MU3_MUA_BASE_NS)
  /** Peripheral MU3_MUB base address */
  #define MU3_MUB_BASE                             (0x545E0000u)
  /** Peripheral MU3_MUB base address */
  #define MU3_MUB_BASE_NS                          (0x445E0000u)
  /** Peripheral MU3_MUB base pointer */
  #define MU3_MUB                                  ((MU_Type *)MU3_MUB_BASE)
  /** Peripheral MU3_MUB base pointer */
  #define MU3_MUB_NS                               ((MU_Type *)MU3_MUB_BASE_NS)
  /** Peripheral MU4_MUA base address */
  #define MU4_MUA_BASE                             (0x545F0000u)
  /** Peripheral MU4_MUA base address */
  #define MU4_MUA_BASE_NS                          (0x445F0000u)
  /** Peripheral MU4_MUA base pointer */
  #define MU4_MUA                                  ((MU_Type *)MU4_MUA_BASE)
  /** Peripheral MU4_MUA base pointer */
  #define MU4_MUA_NS                               ((MU_Type *)MU4_MUA_BASE_NS)
  /** Peripheral MU4_MUB base address */
  #define MU4_MUB_BASE                             (0x54600000u)
  /** Peripheral MU4_MUB base address */
  #define MU4_MUB_BASE_NS                          (0x44600000u)
  /** Peripheral MU4_MUB base pointer */
  #define MU4_MUB                                  ((MU_Type *)MU4_MUB_BASE)
  /** Peripheral MU4_MUB base pointer */
  #define MU4_MUB_NS                               ((MU_Type *)MU4_MUB_BASE_NS)
  /** Peripheral MU5_MUA base address */
  #define MU5_MUA_BASE                             (0x54610000u)
  /** Peripheral MU5_MUA base address */
  #define MU5_MUA_BASE_NS                          (0x44610000u)
  /** Peripheral MU5_MUA base pointer */
  #define MU5_MUA                                  ((MU_Type *)MU5_MUA_BASE)
  /** Peripheral MU5_MUA base pointer */
  #define MU5_MUA_NS                               ((MU_Type *)MU5_MUA_BASE_NS)
  /** Peripheral MU5_MUB base address */
  #define MU5_MUB_BASE                             (0x54620000u)
  /** Peripheral MU5_MUB base address */
  #define MU5_MUB_BASE_NS                          (0x44620000u)
  /** Peripheral MU5_MUB base pointer */
  #define MU5_MUB                                  ((MU_Type *)MU5_MUB_BASE)
  /** Peripheral MU5_MUB base pointer */
  #define MU5_MUB_NS                               ((MU_Type *)MU5_MUB_BASE_NS)
  /** Peripheral MU6_MUA base address */
  #define MU6_MUA_BASE                             (0x54630000u)
  /** Peripheral MU6_MUA base address */
  #define MU6_MUA_BASE_NS                          (0x44630000u)
  /** Peripheral MU6_MUA base pointer */
  #define MU6_MUA                                  ((MU_Type *)MU6_MUA_BASE)
  /** Peripheral MU6_MUA base pointer */
  #define MU6_MUA_NS                               ((MU_Type *)MU6_MUA_BASE_NS)
  /** Peripheral MU6_MUB base address */
  #define MU6_MUB_BASE                             (0x54640000u)
  /** Peripheral MU6_MUB base address */
  #define MU6_MUB_BASE_NS                          (0x44640000u)
  /** Peripheral MU6_MUB base pointer */
  #define MU6_MUB                                  ((MU_Type *)MU6_MUB_BASE)
  /** Peripheral MU6_MUB base pointer */
  #define MU6_MUB_NS                               ((MU_Type *)MU6_MUB_BASE_NS)
  /** Peripheral MU7_MUA base address */
  #define MU7_MUA_BASE                             (0x54700000u)
  /** Peripheral MU7_MUA base address */
  #define MU7_MUA_BASE_NS                          (0x44700000u)
  /** Peripheral MU7_MUA base pointer */
  #define MU7_MUA                                  ((MU_Type *)MU7_MUA_BASE)
  /** Peripheral MU7_MUA base pointer */
  #define MU7_MUA_NS                               ((MU_Type *)MU7_MUA_BASE_NS)
  /** Peripheral MU7_MUB base address */
  #define MU7_MUB_BASE                             (0x54710000u)
  /** Peripheral MU7_MUB base address */
  #define MU7_MUB_BASE_NS                          (0x44710000u)
  /** Peripheral MU7_MUB base pointer */
  #define MU7_MUB                                  ((MU_Type *)MU7_MUB_BASE)
  /** Peripheral MU7_MUB base pointer */
  #define MU7_MUB_NS                               ((MU_Type *)MU7_MUB_BASE_NS)
  /** Peripheral MU8_MUA base address */
  #define MU8_MUA_BASE                             (0x54720000u)
  /** Peripheral MU8_MUA base address */
  #define MU8_MUA_BASE_NS                          (0x44720000u)
  /** Peripheral MU8_MUA base pointer */
  #define MU8_MUA                                  ((MU_Type *)MU8_MUA_BASE)
  /** Peripheral MU8_MUA base pointer */
  #define MU8_MUA_NS                               ((MU_Type *)MU8_MUA_BASE_NS)
  /** Peripheral MU8_MUB base address */
  #define MU8_MUB_BASE                             (0x54730000u)
  /** Peripheral MU8_MUB base address */
  #define MU8_MUB_BASE_NS                          (0x44730000u)
  /** Peripheral MU8_MUB base pointer */
  #define MU8_MUB                                  ((MU_Type *)MU8_MUB_BASE)
  /** Peripheral MU8_MUB base pointer */
  #define MU8_MUB_NS                               ((MU_Type *)MU8_MUB_BASE_NS)
  /** Peripheral MU9_MUA base address */
  #define MU9_MUA_BASE                             (0x54740000u)
  /** Peripheral MU9_MUA base address */
  #define MU9_MUA_BASE_NS                          (0x44740000u)
  /** Peripheral MU9_MUA base pointer */
  #define MU9_MUA                                  ((MU_Type *)MU9_MUA_BASE)
  /** Peripheral MU9_MUA base pointer */
  #define MU9_MUA_NS                               ((MU_Type *)MU9_MUA_BASE_NS)
  /** Peripheral MU9_MUB base address */
  #define MU9_MUB_BASE                             (0x54750000u)
  /** Peripheral MU9_MUB base address */
  #define MU9_MUB_BASE_NS                          (0x44750000u)
  /** Peripheral MU9_MUB base pointer */
  #define MU9_MUB                                  ((MU_Type *)MU9_MUB_BASE)
  /** Peripheral MU9_MUB base pointer */
  #define MU9_MUB_NS                               ((MU_Type *)MU9_MUB_BASE_NS)
  /** Peripheral NETC__MUA1__MUA base address */
  #define NETC__MUA1__MUA_BASE                     (0x5D120000u)
  /** Peripheral NETC__MUA1__MUA base address */
  #define NETC__MUA1__MUA_BASE_NS                  (0x4D120000u)
  /** Peripheral NETC__MUA1__MUA base pointer */
  #define NETC__MUA1__MUA                          ((MU_Type *)NETC__MUA1__MUA_BASE)
  /** Peripheral NETC__MUA1__MUA base pointer */
  #define NETC__MUA1__MUA_NS                       ((MU_Type *)NETC__MUA1__MUA_BASE_NS)
  /** Peripheral NETC__MUA1__MUB base address */
  #define NETC__MUA1__MUB_BASE                     (0x5D130000u)
  /** Peripheral NETC__MUA1__MUB base address */
  #define NETC__MUA1__MUB_BASE_NS                  (0x4D130000u)
  /** Peripheral NETC__MUA1__MUB base pointer */
  #define NETC__MUA1__MUB                          ((MU_Type *)NETC__MUA1__MUB_BASE)
  /** Peripheral NETC__MUA1__MUB base pointer */
  #define NETC__MUA1__MUB_NS                       ((MU_Type *)NETC__MUA1__MUB_BASE_NS)
  /** Peripheral NETC__MUA2__MUA base address */
  #define NETC__MUA2__MUA_BASE                     (0x5D140000u)
  /** Peripheral NETC__MUA2__MUA base address */
  #define NETC__MUA2__MUA_BASE_NS                  (0x4D140000u)
  /** Peripheral NETC__MUA2__MUA base pointer */
  #define NETC__MUA2__MUA                          ((MU_Type *)NETC__MUA2__MUA_BASE)
  /** Peripheral NETC__MUA2__MUA base pointer */
  #define NETC__MUA2__MUA_NS                       ((MU_Type *)NETC__MUA2__MUA_BASE_NS)
  /** Peripheral NETC__MUA2__MUB base address */
  #define NETC__MUA2__MUB_BASE                     (0x5D150000u)
  /** Peripheral NETC__MUA2__MUB base address */
  #define NETC__MUA2__MUB_BASE_NS                  (0x4D150000u)
  /** Peripheral NETC__MUA2__MUB base pointer */
  #define NETC__MUA2__MUB                          ((MU_Type *)NETC__MUA2__MUB_BASE)
  /** Peripheral NETC__MUA2__MUB base pointer */
  #define NETC__MUA2__MUB_NS                       ((MU_Type *)NETC__MUA2__MUB_BASE_NS)
  /** Peripheral NETC__MUA3__MUA base address */
  #define NETC__MUA3__MUA_BASE                     (0x5D160000u)
  /** Peripheral NETC__MUA3__MUA base address */
  #define NETC__MUA3__MUA_BASE_NS                  (0x4D160000u)
  /** Peripheral NETC__MUA3__MUA base pointer */
  #define NETC__MUA3__MUA                          ((MU_Type *)NETC__MUA3__MUA_BASE)
  /** Peripheral NETC__MUA3__MUA base pointer */
  #define NETC__MUA3__MUA_NS                       ((MU_Type *)NETC__MUA3__MUA_BASE_NS)
  /** Peripheral NETC__MUA3__MUB base address */
  #define NETC__MUA3__MUB_BASE                     (0x5D170000u)
  /** Peripheral NETC__MUA3__MUB base address */
  #define NETC__MUA3__MUB_BASE_NS                  (0x4D170000u)
  /** Peripheral NETC__MUA3__MUB base pointer */
  #define NETC__MUA3__MUB                          ((MU_Type *)NETC__MUA3__MUB_BASE)
  /** Peripheral NETC__MUA3__MUB base pointer */
  #define NETC__MUA3__MUB_NS                       ((MU_Type *)NETC__MUA3__MUB_BASE_NS)
  /** Peripheral NETC__MUA4__MUA base address */
  #define NETC__MUA4__MUA_BASE                     (0x5D180000u)
  /** Peripheral NETC__MUA4__MUA base address */
  #define NETC__MUA4__MUA_BASE_NS                  (0x4D180000u)
  /** Peripheral NETC__MUA4__MUA base pointer */
  #define NETC__MUA4__MUA                          ((MU_Type *)NETC__MUA4__MUA_BASE)
  /** Peripheral NETC__MUA4__MUA base pointer */
  #define NETC__MUA4__MUA_NS                       ((MU_Type *)NETC__MUA4__MUA_BASE_NS)
  /** Peripheral NETC__MUA4__MUB base address */
  #define NETC__MUA4__MUB_BASE                     (0x5D190000u)
  /** Peripheral NETC__MUA4__MUB base address */
  #define NETC__MUA4__MUB_BASE_NS                  (0x4D190000u)
  /** Peripheral NETC__MUA4__MUB base pointer */
  #define NETC__MUA4__MUB                          ((MU_Type *)NETC__MUA4__MUB_BASE)
  /** Peripheral NETC__MUA4__MUB base pointer */
  #define NETC__MUA4__MUB_NS                       ((MU_Type *)NETC__MUA4__MUB_BASE_NS)
  /** Peripheral WAKEUP__MUI_A10__MUA base address */
  #define WAKEUP__MUI_A10__MUA_BASE                (0x52430000u)
  /** Peripheral WAKEUP__MUI_A10__MUA base address */
  #define WAKEUP__MUI_A10__MUA_BASE_NS             (0x42430000u)
  /** Peripheral WAKEUP__MUI_A10__MUA base pointer */
  #define WAKEUP__MUI_A10__MUA                     ((MU_Type *)WAKEUP__MUI_A10__MUA_BASE)
  /** Peripheral WAKEUP__MUI_A10__MUA base pointer */
  #define WAKEUP__MUI_A10__MUA_NS                  ((MU_Type *)WAKEUP__MUI_A10__MUA_BASE_NS)
  /** Peripheral WAKEUP__MUI_A10__MUB base address */
  #define WAKEUP__MUI_A10__MUB_BASE                (0x52440000u)
  /** Peripheral WAKEUP__MUI_A10__MUB base address */
  #define WAKEUP__MUI_A10__MUB_BASE_NS             (0x42440000u)
  /** Peripheral WAKEUP__MUI_A10__MUB base pointer */
  #define WAKEUP__MUI_A10__MUB                     ((MU_Type *)WAKEUP__MUI_A10__MUB_BASE)
  /** Peripheral WAKEUP__MUI_A10__MUB base pointer */
  #define WAKEUP__MUI_A10__MUB_NS                  ((MU_Type *)WAKEUP__MUI_A10__MUB_BASE_NS)
  /** Peripheral WAKEUP__MUI_A11__MUA base address */
  #define WAKEUP__MUI_A11__MUA_BASE                (0x52730000u)
  /** Peripheral WAKEUP__MUI_A11__MUA base address */
  #define WAKEUP__MUI_A11__MUA_BASE_NS             (0x42730000u)
  /** Peripheral WAKEUP__MUI_A11__MUA base pointer */
  #define WAKEUP__MUI_A11__MUA                     ((MU_Type *)WAKEUP__MUI_A11__MUA_BASE)
  /** Peripheral WAKEUP__MUI_A11__MUA base pointer */
  #define WAKEUP__MUI_A11__MUA_NS                  ((MU_Type *)WAKEUP__MUI_A11__MUA_BASE_NS)
  /** Peripheral WAKEUP__MUI_A11__MUB base address */
  #define WAKEUP__MUI_A11__MUB_BASE                (0x52740000u)
  /** Peripheral WAKEUP__MUI_A11__MUB base address */
  #define WAKEUP__MUI_A11__MUB_BASE_NS             (0x42740000u)
  /** Peripheral WAKEUP__MUI_A11__MUB base pointer */
  #define WAKEUP__MUI_A11__MUB                     ((MU_Type *)WAKEUP__MUI_A11__MUB_BASE)
  /** Peripheral WAKEUP__MUI_A11__MUB base pointer */
  #define WAKEUP__MUI_A11__MUB_NS                  ((MU_Type *)WAKEUP__MUI_A11__MUB_BASE_NS)
  /** Peripheral WAKEUP__MUI_A12__MUA base address */
  #define WAKEUP__MUI_A12__MUA_BASE                (0x52AB0000u)
  /** Peripheral WAKEUP__MUI_A12__MUA base address */
  #define WAKEUP__MUI_A12__MUA_BASE_NS             (0x42AB0000u)
  /** Peripheral WAKEUP__MUI_A12__MUA base pointer */
  #define WAKEUP__MUI_A12__MUA                     ((MU_Type *)WAKEUP__MUI_A12__MUA_BASE)
  /** Peripheral WAKEUP__MUI_A12__MUA base pointer */
  #define WAKEUP__MUI_A12__MUA_NS                  ((MU_Type *)WAKEUP__MUI_A12__MUA_BASE_NS)
  /** Peripheral WAKEUP__MUI_A12__MUB base address */
  #define WAKEUP__MUI_A12__MUB_BASE                (0x52AC0000u)
  /** Peripheral WAKEUP__MUI_A12__MUB base address */
  #define WAKEUP__MUI_A12__MUB_BASE_NS             (0x42AC0000u)
  /** Peripheral WAKEUP__MUI_A12__MUB base pointer */
  #define WAKEUP__MUI_A12__MUB                     ((MU_Type *)WAKEUP__MUI_A12__MUB_BASE)
  /** Peripheral WAKEUP__MUI_A12__MUB base pointer */
  #define WAKEUP__MUI_A12__MUB_NS                  ((MU_Type *)WAKEUP__MUI_A12__MUB_BASE_NS)
  /** Peripheral WAKEUP__MUI_A13__MUA base address */
  #define WAKEUP__MUI_A13__MUA_BASE                (0x52AD0000u)
  /** Peripheral WAKEUP__MUI_A13__MUA base address */
  #define WAKEUP__MUI_A13__MUA_BASE_NS             (0x42AD0000u)
  /** Peripheral WAKEUP__MUI_A13__MUA base pointer */
  #define WAKEUP__MUI_A13__MUA                     ((MU_Type *)WAKEUP__MUI_A13__MUA_BASE)
  /** Peripheral WAKEUP__MUI_A13__MUA base pointer */
  #define WAKEUP__MUI_A13__MUA_NS                  ((MU_Type *)WAKEUP__MUI_A13__MUA_BASE_NS)
  /** Peripheral WAKEUP__MUI_A13__MUB base address */
  #define WAKEUP__MUI_A13__MUB_BASE                (0x52AE0000u)
  /** Peripheral WAKEUP__MUI_A13__MUB base address */
  #define WAKEUP__MUI_A13__MUB_BASE_NS             (0x42AE0000u)
  /** Peripheral WAKEUP__MUI_A13__MUB base pointer */
  #define WAKEUP__MUI_A13__MUB                     ((MU_Type *)WAKEUP__MUI_A13__MUB_BASE)
  /** Peripheral WAKEUP__MUI_A13__MUB base pointer */
  #define WAKEUP__MUI_A13__MUB_NS                  ((MU_Type *)WAKEUP__MUI_A13__MUB_BASE_NS)
  /** Peripheral WAKEUP__MUI_A14__MUA base address */
  #define WAKEUP__MUI_A14__MUA_BASE                (0x52AF0000u)
  /** Peripheral WAKEUP__MUI_A14__MUA base address */
  #define WAKEUP__MUI_A14__MUA_BASE_NS             (0x42AF0000u)
  /** Peripheral WAKEUP__MUI_A14__MUA base pointer */
  #define WAKEUP__MUI_A14__MUA                     ((MU_Type *)WAKEUP__MUI_A14__MUA_BASE)
  /** Peripheral WAKEUP__MUI_A14__MUA base pointer */
  #define WAKEUP__MUI_A14__MUA_NS                  ((MU_Type *)WAKEUP__MUI_A14__MUA_BASE_NS)
  /** Peripheral WAKEUP__MUI_A14__MUB base address */
  #define WAKEUP__MUI_A14__MUB_BASE                (0x52B00000u)
  /** Peripheral WAKEUP__MUI_A14__MUB base address */
  #define WAKEUP__MUI_A14__MUB_BASE_NS             (0x42B00000u)
  /** Peripheral WAKEUP__MUI_A14__MUB base pointer */
  #define WAKEUP__MUI_A14__MUB                     ((MU_Type *)WAKEUP__MUI_A14__MUB_BASE)
  /** Peripheral WAKEUP__MUI_A14__MUB base pointer */
  #define WAKEUP__MUI_A14__MUB_NS                  ((MU_Type *)WAKEUP__MUI_A14__MUB_BASE_NS)
  /** Peripheral WAKEUP__MUI_A15__MUA base address */
  #define WAKEUP__MUI_A15__MUA_BASE                (0x52B10000u)
  /** Peripheral WAKEUP__MUI_A15__MUA base address */
  #define WAKEUP__MUI_A15__MUA_BASE_NS             (0x42B10000u)
  /** Peripheral WAKEUP__MUI_A15__MUA base pointer */
  #define WAKEUP__MUI_A15__MUA                     ((MU_Type *)WAKEUP__MUI_A15__MUA_BASE)
  /** Peripheral WAKEUP__MUI_A15__MUA base pointer */
  #define WAKEUP__MUI_A15__MUA_NS                  ((MU_Type *)WAKEUP__MUI_A15__MUA_BASE_NS)
  /** Peripheral WAKEUP__MUI_A15__MUB base address */
  #define WAKEUP__MUI_A15__MUB_BASE                (0x52B20000u)
  /** Peripheral WAKEUP__MUI_A15__MUB base address */
  #define WAKEUP__MUI_A15__MUB_BASE_NS             (0x42B20000u)
  /** Peripheral WAKEUP__MUI_A15__MUB base pointer */
  #define WAKEUP__MUI_A15__MUB                     ((MU_Type *)WAKEUP__MUI_A15__MUB_BASE)
  /** Peripheral WAKEUP__MUI_A15__MUB base pointer */
  #define WAKEUP__MUI_A15__MUB_NS                  ((MU_Type *)WAKEUP__MUI_A15__MUB_BASE_NS)
  /** Peripheral WAKEUP__MUI_A16__MUA base address */
  #define WAKEUP__MUI_A16__MUA_BASE                (0x52B30000u)
  /** Peripheral WAKEUP__MUI_A16__MUA base address */
  #define WAKEUP__MUI_A16__MUA_BASE_NS             (0x42B30000u)
  /** Peripheral WAKEUP__MUI_A16__MUA base pointer */
  #define WAKEUP__MUI_A16__MUA                     ((MU_Type *)WAKEUP__MUI_A16__MUA_BASE)
  /** Peripheral WAKEUP__MUI_A16__MUA base pointer */
  #define WAKEUP__MUI_A16__MUA_NS                  ((MU_Type *)WAKEUP__MUI_A16__MUA_BASE_NS)
  /** Peripheral WAKEUP__MUI_A16__MUB base address */
  #define WAKEUP__MUI_A16__MUB_BASE                (0x52B40000u)
  /** Peripheral WAKEUP__MUI_A16__MUB base address */
  #define WAKEUP__MUI_A16__MUB_BASE_NS             (0x42B40000u)
  /** Peripheral WAKEUP__MUI_A16__MUB base pointer */
  #define WAKEUP__MUI_A16__MUB                     ((MU_Type *)WAKEUP__MUI_A16__MUB_BASE)
  /** Peripheral WAKEUP__MUI_A16__MUB base pointer */
  #define WAKEUP__MUI_A16__MUB_NS                  ((MU_Type *)WAKEUP__MUI_A16__MUB_BASE_NS)
  /** Peripheral WAKEUP__MUI_A17__MUA base address */
  #define WAKEUP__MUI_A17__MUA_BASE                (0x52B50000u)
  /** Peripheral WAKEUP__MUI_A17__MUA base address */
  #define WAKEUP__MUI_A17__MUA_BASE_NS             (0x42B50000u)
  /** Peripheral WAKEUP__MUI_A17__MUA base pointer */
  #define WAKEUP__MUI_A17__MUA                     ((MU_Type *)WAKEUP__MUI_A17__MUA_BASE)
  /** Peripheral WAKEUP__MUI_A17__MUA base pointer */
  #define WAKEUP__MUI_A17__MUA_NS                  ((MU_Type *)WAKEUP__MUI_A17__MUA_BASE_NS)
  /** Peripheral WAKEUP__MUI_A17__MUB base address */
  #define WAKEUP__MUI_A17__MUB_BASE                (0x52B60000u)
  /** Peripheral WAKEUP__MUI_A17__MUB base address */
  #define WAKEUP__MUI_A17__MUB_BASE_NS             (0x42B60000u)
  /** Peripheral WAKEUP__MUI_A17__MUB base pointer */
  #define WAKEUP__MUI_A17__MUB                     ((MU_Type *)WAKEUP__MUI_A17__MUB_BASE)
  /** Peripheral WAKEUP__MUI_A17__MUB base pointer */
  #define WAKEUP__MUI_A17__MUB_NS                  ((MU_Type *)WAKEUP__MUI_A17__MUB_BASE_NS)
  /** Peripheral WAKEUP__MUI_A18__MUA base address */
  #define WAKEUP__MUI_A18__MUA_BASE                (0x52B70000u)
  /** Peripheral WAKEUP__MUI_A18__MUA base address */
  #define WAKEUP__MUI_A18__MUA_BASE_NS             (0x42B70000u)
  /** Peripheral WAKEUP__MUI_A18__MUA base pointer */
  #define WAKEUP__MUI_A18__MUA                     ((MU_Type *)WAKEUP__MUI_A18__MUA_BASE)
  /** Peripheral WAKEUP__MUI_A18__MUA base pointer */
  #define WAKEUP__MUI_A18__MUA_NS                  ((MU_Type *)WAKEUP__MUI_A18__MUA_BASE_NS)
  /** Peripheral WAKEUP__MUI_A18__MUB base address */
  #define WAKEUP__MUI_A18__MUB_BASE                (0x52B80000u)
  /** Peripheral WAKEUP__MUI_A18__MUB base address */
  #define WAKEUP__MUI_A18__MUB_BASE_NS             (0x42B80000u)
  /** Peripheral WAKEUP__MUI_A18__MUB base pointer */
  #define WAKEUP__MUI_A18__MUB                     ((MU_Type *)WAKEUP__MUI_A18__MUB_BASE)
  /** Peripheral WAKEUP__MUI_A18__MUB base pointer */
  #define WAKEUP__MUI_A18__MUB_NS                  ((MU_Type *)WAKEUP__MUI_A18__MUB_BASE_NS)
  /** Peripheral WAKEUP__V2X__MU0__MUA base address */
  #define WAKEUP__V2X__MU0__MUA_BASE               (0x97300000u)
  /** Peripheral WAKEUP__V2X__MU0__MUA base address */
  #define WAKEUP__V2X__MU0__MUA_BASE_NS            (0x87300000u)
  /** Peripheral WAKEUP__V2X__MU0__MUA base pointer */
  #define WAKEUP__V2X__MU0__MUA                    ((MU_Type *)WAKEUP__V2X__MU0__MUA_BASE)
  /** Peripheral WAKEUP__V2X__MU0__MUA base pointer */
  #define WAKEUP__V2X__MU0__MUA_NS                 ((MU_Type *)WAKEUP__V2X__MU0__MUA_BASE_NS)
  /** Peripheral WAKEUP__V2X__MU1__MUA base address */
  #define WAKEUP__V2X__MU1__MUA_BASE               (0x97310000u)
  /** Peripheral WAKEUP__V2X__MU1__MUA base address */
  #define WAKEUP__V2X__MU1__MUA_BASE_NS            (0x87310000u)
  /** Peripheral WAKEUP__V2X__MU1__MUA base pointer */
  #define WAKEUP__V2X__MU1__MUA                    ((MU_Type *)WAKEUP__V2X__MU1__MUA_BASE)
  /** Peripheral WAKEUP__V2X__MU1__MUA base pointer */
  #define WAKEUP__V2X__MU1__MUA_NS                 ((MU_Type *)WAKEUP__V2X__MU1__MUA_BASE_NS)
  /** Peripheral WAKEUP__V2X__MU2__MUA base address */
  #define WAKEUP__V2X__MU2__MUA_BASE               (0x97320000u)
  /** Peripheral WAKEUP__V2X__MU2__MUA base address */
  #define WAKEUP__V2X__MU2__MUA_BASE_NS            (0x87320000u)
  /** Peripheral WAKEUP__V2X__MU2__MUA base pointer */
  #define WAKEUP__V2X__MU2__MUA                    ((MU_Type *)WAKEUP__V2X__MU2__MUA_BASE)
  /** Peripheral WAKEUP__V2X__MU2__MUA base pointer */
  #define WAKEUP__V2X__MU2__MUA_NS                 ((MU_Type *)WAKEUP__V2X__MU2__MUA_BASE_NS)
  /** Peripheral WAKEUP__V2X__MU3__MUA base address */
  #define WAKEUP__V2X__MU3__MUA_BASE               (0x97330000u)
  /** Peripheral WAKEUP__V2X__MU3__MUA base address */
  #define WAKEUP__V2X__MU3__MUA_BASE_NS            (0x87330000u)
  /** Peripheral WAKEUP__V2X__MU3__MUA base pointer */
  #define WAKEUP__V2X__MU3__MUA                    ((MU_Type *)WAKEUP__V2X__MU3__MUA_BASE)
  /** Peripheral WAKEUP__V2X__MU3__MUA base pointer */
  #define WAKEUP__V2X__MU3__MUA_NS                 ((MU_Type *)WAKEUP__V2X__MU3__MUA_BASE_NS)
  /** Peripheral WAKEUP__V2X__MU4__MUA base address */
  #define WAKEUP__V2X__MU4__MUA_BASE               (0x97340000u)
  /** Peripheral WAKEUP__V2X__MU4__MUA base address */
  #define WAKEUP__V2X__MU4__MUA_BASE_NS            (0x87340000u)
  /** Peripheral WAKEUP__V2X__MU4__MUA base pointer */
  #define WAKEUP__V2X__MU4__MUA                    ((MU_Type *)WAKEUP__V2X__MU4__MUA_BASE)
  /** Peripheral WAKEUP__V2X__MU4__MUA base pointer */
  #define WAKEUP__V2X__MU4__MUA_NS                 ((MU_Type *)WAKEUP__V2X__MU4__MUA_BASE_NS)
  /** Peripheral WAKEUP__V2X__MU5__MUB base address */
  #define WAKEUP__V2X__MU5__MUB_BASE               (0x97358000u)
  /** Peripheral WAKEUP__V2X__MU5__MUB base address */
  #define WAKEUP__V2X__MU5__MUB_BASE_NS            (0x87358000u)
  /** Peripheral WAKEUP__V2X__MU5__MUB base pointer */
  #define WAKEUP__V2X__MU5__MUB                    ((MU_Type *)WAKEUP__V2X__MU5__MUB_BASE)
  /** Peripheral WAKEUP__V2X__MU5__MUB base pointer */
  #define WAKEUP__V2X__MU5__MUB_NS                 ((MU_Type *)WAKEUP__V2X__MU5__MUB_BASE_NS)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU1_MUA_BASE, MU1_MUB_BASE, MU2_MUA_BASE, MU2_MUB_BASE, MU3_MUA_BASE, MU3_MUB_BASE, MU4_MUA_BASE, MU4_MUB_BASE, MU5_MUA_BASE, MU5_MUB_BASE, MU6_MUA_BASE, MU6_MUB_BASE, MU7_MUA_BASE, MU7_MUB_BASE, MU8_MUA_BASE, MU8_MUB_BASE, MU9_MUA_BASE, MU9_MUB_BASE, NETC__MUA1__MUA_BASE, NETC__MUA1__MUB_BASE, NETC__MUA2__MUA_BASE, NETC__MUA2__MUB_BASE, NETC__MUA3__MUA_BASE, NETC__MUA3__MUB_BASE, NETC__MUA4__MUA_BASE, NETC__MUA4__MUB_BASE, WAKEUP__MUI_A10__MUA_BASE, WAKEUP__MUI_A10__MUB_BASE, WAKEUP__MUI_A11__MUA_BASE, WAKEUP__MUI_A11__MUB_BASE, WAKEUP__MUI_A12__MUA_BASE, WAKEUP__MUI_A12__MUB_BASE, WAKEUP__MUI_A13__MUA_BASE, WAKEUP__MUI_A13__MUB_BASE, WAKEUP__MUI_A14__MUA_BASE, WAKEUP__MUI_A14__MUB_BASE, WAKEUP__MUI_A15__MUA_BASE, WAKEUP__MUI_A15__MUB_BASE, WAKEUP__MUI_A16__MUA_BASE, WAKEUP__MUI_A16__MUB_BASE, WAKEUP__MUI_A17__MUA_BASE, WAKEUP__MUI_A17__MUB_BASE, WAKEUP__MUI_A18__MUA_BASE, WAKEUP__MUI_A18__MUB_BASE, WAKEUP__V2X__MU0__MUA_BASE, WAKEUP__V2X__MU1__MUA_BASE, WAKEUP__V2X__MU2__MUA_BASE, WAKEUP__V2X__MU3__MUA_BASE, WAKEUP__V2X__MU4__MUA_BASE, WAKEUP__V2X__MU5__MUB_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU1_MUA, MU1_MUB, MU2_MUA, MU2_MUB, MU3_MUA, MU3_MUB, MU4_MUA, MU4_MUB, MU5_MUA, MU5_MUB, MU6_MUA, MU6_MUB, MU7_MUA, MU7_MUB, MU8_MUA, MU8_MUB, MU9_MUA, MU9_MUB, NETC__MUA1__MUA, NETC__MUA1__MUB, NETC__MUA2__MUA, NETC__MUA2__MUB, NETC__MUA3__MUA, NETC__MUA3__MUB, NETC__MUA4__MUA, NETC__MUA4__MUB, WAKEUP__MUI_A10__MUA, WAKEUP__MUI_A10__MUB, WAKEUP__MUI_A11__MUA, WAKEUP__MUI_A11__MUB, WAKEUP__MUI_A12__MUA, WAKEUP__MUI_A12__MUB, WAKEUP__MUI_A13__MUA, WAKEUP__MUI_A13__MUB, WAKEUP__MUI_A14__MUA, WAKEUP__MUI_A14__MUB, WAKEUP__MUI_A15__MUA, WAKEUP__MUI_A15__MUB, WAKEUP__MUI_A16__MUA, WAKEUP__MUI_A16__MUB, WAKEUP__MUI_A17__MUA, WAKEUP__MUI_A17__MUB, WAKEUP__MUI_A18__MUA, WAKEUP__MUI_A18__MUB, WAKEUP__V2X__MU0__MUA, WAKEUP__V2X__MU1__MUA, WAKEUP__V2X__MU2__MUA, WAKEUP__V2X__MU3__MUA, WAKEUP__V2X__MU4__MUA, WAKEUP__V2X__MU5__MUB }
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS_NS                         { MU1_MUA_BASE_NS, MU1_MUB_BASE_NS, MU2_MUA_BASE_NS, MU2_MUB_BASE_NS, MU3_MUA_BASE_NS, MU3_MUB_BASE_NS, MU4_MUA_BASE_NS, MU4_MUB_BASE_NS, MU5_MUA_BASE_NS, MU5_MUB_BASE_NS, MU6_MUA_BASE_NS, MU6_MUB_BASE_NS, MU7_MUA_BASE_NS, MU7_MUB_BASE_NS, MU8_MUA_BASE_NS, MU8_MUB_BASE_NS, MU9_MUA_BASE_NS, MU9_MUB_BASE_NS, NETC__MUA1__MUA_BASE_NS, NETC__MUA1__MUB_BASE_NS, NETC__MUA2__MUA_BASE_NS, NETC__MUA2__MUB_BASE_NS, NETC__MUA3__MUA_BASE_NS, NETC__MUA3__MUB_BASE_NS, NETC__MUA4__MUA_BASE_NS, NETC__MUA4__MUB_BASE_NS, WAKEUP__MUI_A10__MUA_BASE_NS, WAKEUP__MUI_A10__MUB_BASE_NS, WAKEUP__MUI_A11__MUA_BASE_NS, WAKEUP__MUI_A11__MUB_BASE_NS, WAKEUP__MUI_A12__MUA_BASE_NS, WAKEUP__MUI_A12__MUB_BASE_NS, WAKEUP__MUI_A13__MUA_BASE_NS, WAKEUP__MUI_A13__MUB_BASE_NS, WAKEUP__MUI_A14__MUA_BASE_NS, WAKEUP__MUI_A14__MUB_BASE_NS, WAKEUP__MUI_A15__MUA_BASE_NS, WAKEUP__MUI_A15__MUB_BASE_NS, WAKEUP__MUI_A16__MUA_BASE_NS, WAKEUP__MUI_A16__MUB_BASE_NS, WAKEUP__MUI_A17__MUA_BASE_NS, WAKEUP__MUI_A17__MUB_BASE_NS, WAKEUP__MUI_A18__MUA_BASE_NS, WAKEUP__MUI_A18__MUB_BASE_NS, WAKEUP__V2X__MU0__MUA_BASE_NS, WAKEUP__V2X__MU1__MUA_BASE_NS, WAKEUP__V2X__MU2__MUA_BASE_NS, WAKEUP__V2X__MU3__MUA_BASE_NS, WAKEUP__V2X__MU4__MUA_BASE_NS, WAKEUP__V2X__MU5__MUB_BASE_NS }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS_NS                          { MU1_MUA_NS, MU1_MUB_NS, MU2_MUA_NS, MU2_MUB_NS, MU3_MUA_NS, MU3_MUB_NS, MU4_MUA_NS, MU4_MUB_NS, MU5_MUA_NS, MU5_MUB_NS, MU6_MUA_NS, MU6_MUB_NS, MU7_MUA_NS, MU7_MUB_NS, MU8_MUA_NS, MU8_MUB_NS, MU9_MUA_NS, MU9_MUB_NS, NETC__MUA1__MUA_NS, NETC__MUA1__MUB_NS, NETC__MUA2__MUA_NS, NETC__MUA2__MUB_NS, NETC__MUA3__MUA_NS, NETC__MUA3__MUB_NS, NETC__MUA4__MUA_NS, NETC__MUA4__MUB_NS, WAKEUP__MUI_A10__MUA_NS, WAKEUP__MUI_A10__MUB_NS, WAKEUP__MUI_A11__MUA_NS, WAKEUP__MUI_A11__MUB_NS, WAKEUP__MUI_A12__MUA_NS, WAKEUP__MUI_A12__MUB_NS, WAKEUP__MUI_A13__MUA_NS, WAKEUP__MUI_A13__MUB_NS, WAKEUP__MUI_A14__MUA_NS, WAKEUP__MUI_A14__MUB_NS, WAKEUP__MUI_A15__MUA_NS, WAKEUP__MUI_A15__MUB_NS, WAKEUP__MUI_A16__MUA_NS, WAKEUP__MUI_A16__MUB_NS, WAKEUP__MUI_A17__MUA_NS, WAKEUP__MUI_A17__MUB_NS, WAKEUP__MUI_A18__MUA_NS, WAKEUP__MUI_A18__MUB_NS, WAKEUP__V2X__MU0__MUA_NS, WAKEUP__V2X__MU1__MUA_NS, WAKEUP__V2X__MU2__MUA_NS, WAKEUP__V2X__MU3__MUA_NS, WAKEUP__V2X__MU4__MUA_NS, WAKEUP__V2X__MU5__MUB_NS }
#else
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
#endif
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU1_A_IRQn, MU1_B_IRQn, MU2_A_IRQn, MU2_B_IRQn, MU3_A_IRQn, MU3_B_IRQn, MU4_A_IRQn, MU4_B_IRQn, MU5_A_IRQn, MU5_B_IRQn, MU6_A_IRQn, MU6_B_IRQn, MU7_A_IRQn, MU7_B_IRQn, MU8_A_IRQn, MU8_B_IRQn, MU9_A_IRQn, MU9_B_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }

/* NECTMIX_CM33_AIPS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__CM33_PCF1 base address */
  #define NETC__CM33_PCF1_BASE                     (0x5D1B0000u)
  /** Peripheral NETC__CM33_PCF1 base address */
  #define NETC__CM33_PCF1_BASE_NS                  (0x4D1B0000u)
  /** Peripheral NETC__CM33_PCF1 base pointer */
  #define NETC__CM33_PCF1                          ((NECTMIX_CM33_AIPS_Type *)NETC__CM33_PCF1_BASE)
  /** Peripheral NETC__CM33_PCF1 base pointer */
  #define NETC__CM33_PCF1_NS                       ((NECTMIX_CM33_AIPS_Type *)NETC__CM33_PCF1_BASE_NS)
  /** Peripheral NETC__CM33_PSF1 base address */
  #define NETC__CM33_PSF1_BASE                     (0x5D1C0000u)
  /** Peripheral NETC__CM33_PSF1 base address */
  #define NETC__CM33_PSF1_BASE_NS                  (0x4D1C0000u)
  /** Peripheral NETC__CM33_PSF1 base pointer */
  #define NETC__CM33_PSF1                          ((NECTMIX_CM33_AIPS_Type *)NETC__CM33_PSF1_BASE)
  /** Peripheral NETC__CM33_PSF1 base pointer */
  #define NETC__CM33_PSF1_NS                       ((NECTMIX_CM33_AIPS_Type *)NETC__CM33_PSF1_BASE_NS)
  /** Array initializer of NECTMIX_CM33_AIPS peripheral base addresses */
  #define NECTMIX_CM33_AIPS_BASE_ADDRS             { NETC__CM33_PCF1_BASE, NETC__CM33_PSF1_BASE }
  /** Array initializer of NECTMIX_CM33_AIPS peripheral base pointers */
  #define NECTMIX_CM33_AIPS_BASE_PTRS              { NETC__CM33_PCF1, NETC__CM33_PSF1 }
  /** Array initializer of NECTMIX_CM33_AIPS peripheral base addresses */
  #define NECTMIX_CM33_AIPS_BASE_ADDRS_NS          { NETC__CM33_PCF1_BASE_NS, NETC__CM33_PSF1_BASE_NS }
  /** Array initializer of NECTMIX_CM33_AIPS peripheral base pointers */
  #define NECTMIX_CM33_AIPS_BASE_PTRS_NS           { NETC__CM33_PCF1_NS, NETC__CM33_PSF1_NS }
#else
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
#endif

/* NETC_CMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__CMU base address */
  #define NETC__CMU_BASE                           (0x5D080000u)
  /** Peripheral NETC__CMU base address */
  #define NETC__CMU_BASE_NS                        (0x4D080000u)
  /** Peripheral NETC__CMU base pointer */
  #define NETC__CMU                                ((NETC_CMU_Type *)NETC__CMU_BASE)
  /** Peripheral NETC__CMU base pointer */
  #define NETC__CMU_NS                             ((NETC_CMU_Type *)NETC__CMU_BASE_NS)
  /** Array initializer of NETC_CMU peripheral base addresses */
  #define NETC_CMU_BASE_ADDRS                      { NETC__CMU_BASE }
  /** Array initializer of NETC_CMU peripheral base pointers */
  #define NETC_CMU_BASE_PTRS                       { NETC__CMU }
  /** Array initializer of NETC_CMU peripheral base addresses */
  #define NETC_CMU_BASE_ADDRS_NS                   { NETC__CMU_BASE_NS }
  /** Array initializer of NETC_CMU peripheral base pointers */
  #define NETC_CMU_BASE_PTRS_NS                    { NETC__CMU_NS }
#else
  /** Peripheral NETC__CMU base address */
  #define NETC__CMU_BASE                           (0x4D080000u)
  /** Peripheral NETC__CMU base pointer */
  #define NETC__CMU                                ((NETC_CMU_Type *)NETC__CMU_BASE)
  /** Array initializer of NETC_CMU peripheral base addresses */
  #define NETC_CMU_BASE_ADDRS                      { NETC__CMU_BASE }
  /** Array initializer of NETC_CMU peripheral base pointers */
  #define NETC_CMU_BASE_PTRS                       { NETC__CMU }
#endif

/* NETC_EIM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__EIM base address */
  #define NETC__EIM_BASE                           (0x5D070000u)
  /** Peripheral NETC__EIM base address */
  #define NETC__EIM_BASE_NS                        (0x4D070000u)
  /** Peripheral NETC__EIM base pointer */
  #define NETC__EIM                                ((NETC_EIM_Type *)NETC__EIM_BASE)
  /** Peripheral NETC__EIM base pointer */
  #define NETC__EIM_NS                             ((NETC_EIM_Type *)NETC__EIM_BASE_NS)
  /** Array initializer of NETC_EIM peripheral base addresses */
  #define NETC_EIM_BASE_ADDRS                      { NETC__EIM_BASE }
  /** Array initializer of NETC_EIM peripheral base pointers */
  #define NETC_EIM_BASE_PTRS                       { NETC__EIM }
  /** Array initializer of NETC_EIM peripheral base addresses */
  #define NETC_EIM_BASE_ADDRS_NS                   { NETC__EIM_BASE_NS }
  /** Array initializer of NETC_EIM peripheral base pointers */
  #define NETC_EIM_BASE_PTRS_NS                    { NETC__EIM_NS }
#else
  /** Peripheral NETC__EIM base address */
  #define NETC__EIM_BASE                           (0x4D070000u)
  /** Peripheral NETC__EIM base pointer */
  #define NETC__EIM                                ((NETC_EIM_Type *)NETC__EIM_BASE)
  /** Array initializer of NETC_EIM peripheral base addresses */
  #define NETC_EIM_BASE_ADDRS                      { NETC__EIM_BASE }
  /** Array initializer of NETC_EIM peripheral base pointers */
  #define NETC_EIM_BASE_PTRS                       { NETC__EIM }
#endif

/* NETC_ENETC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENETC0_BASE base address */
  #define ENETC0_BASE_BASE                         (0x5CC90000u)
  /** Peripheral ENETC0_BASE base address */
  #define ENETC0_BASE_BASE_NS                      (0x4CC90000u)
  /** Peripheral ENETC0_BASE base pointer */
  #define ENETC0_BASE                              ((NETC_ENETC_Type *)ENETC0_BASE_BASE)
  /** Peripheral ENETC0_BASE base pointer */
  #define ENETC0_BASE_NS                           ((NETC_ENETC_Type *)ENETC0_BASE_BASE_NS)
  /** Peripheral ENETC1_BASE base address */
  #define ENETC1_BASE_BASE                         (0x5CCD0000u)
  /** Peripheral ENETC1_BASE base address */
  #define ENETC1_BASE_BASE_NS                      (0x4CCD0000u)
  /** Peripheral ENETC1_BASE base pointer */
  #define ENETC1_BASE                              ((NETC_ENETC_Type *)ENETC1_BASE_BASE)
  /** Peripheral ENETC1_BASE base pointer */
  #define ENETC1_BASE_NS                           ((NETC_ENETC_Type *)ENETC1_BASE_BASE_NS)
  /** Peripheral ENETC2_BASE base address */
  #define ENETC2_BASE_BASE                         (0x5CD10000u)
  /** Peripheral ENETC2_BASE base address */
  #define ENETC2_BASE_BASE_NS                      (0x4CD10000u)
  /** Peripheral ENETC2_BASE base pointer */
  #define ENETC2_BASE                              ((NETC_ENETC_Type *)ENETC2_BASE_BASE)
  /** Peripheral ENETC2_BASE base pointer */
  #define ENETC2_BASE_NS                           ((NETC_ENETC_Type *)ENETC2_BASE_BASE_NS)
  /** Peripheral ENETC3_BASE base address */
  #define ENETC3_BASE_BASE                         (0x5CD50000u)
  /** Peripheral ENETC3_BASE base address */
  #define ENETC3_BASE_BASE_NS                      (0x4CD50000u)
  /** Peripheral ENETC3_BASE base pointer */
  #define ENETC3_BASE                              ((NETC_ENETC_Type *)ENETC3_BASE_BASE)
  /** Peripheral ENETC3_BASE base pointer */
  #define ENETC3_BASE_NS                           ((NETC_ENETC_Type *)ENETC3_BASE_BASE_NS)
  /** Array initializer of NETC_ENETC peripheral base addresses */
  #define NETC_ENETC_BASE_ADDRS                    { ENETC0_BASE_BASE, ENETC1_BASE_BASE, ENETC2_BASE_BASE, ENETC3_BASE_BASE }
  /** Array initializer of NETC_ENETC peripheral base pointers */
  #define NETC_ENETC_BASE_PTRS                     { ENETC0_BASE, ENETC1_BASE, ENETC2_BASE, ENETC3_BASE }
  /** Array initializer of NETC_ENETC peripheral base addresses */
  #define NETC_ENETC_BASE_ADDRS_NS                 { ENETC0_BASE_BASE_NS, ENETC1_BASE_BASE_NS, ENETC2_BASE_BASE_NS, ENETC3_BASE_BASE_NS }
  /** Array initializer of NETC_ENETC peripheral base pointers */
  #define NETC_ENETC_BASE_PTRS_NS                  { ENETC0_BASE_NS, ENETC1_BASE_NS, ENETC2_BASE_NS, ENETC3_BASE_NS }
#else
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
#endif

/* NETC_ERM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__ERM base address */
  #define NETC__ERM_BASE                           (0x5D060000u)
  /** Peripheral NETC__ERM base address */
  #define NETC__ERM_BASE_NS                        (0x4D060000u)
  /** Peripheral NETC__ERM base pointer */
  #define NETC__ERM                                ((NETC_ERM_Type *)NETC__ERM_BASE)
  /** Peripheral NETC__ERM base pointer */
  #define NETC__ERM_NS                             ((NETC_ERM_Type *)NETC__ERM_BASE_NS)
  /** Array initializer of NETC_ERM peripheral base addresses */
  #define NETC_ERM_BASE_ADDRS                      { NETC__ERM_BASE }
  /** Array initializer of NETC_ERM peripheral base pointers */
  #define NETC_ERM_BASE_PTRS                       { NETC__ERM }
  /** Array initializer of NETC_ERM peripheral base addresses */
  #define NETC_ERM_BASE_ADDRS_NS                   { NETC__ERM_BASE_NS }
  /** Array initializer of NETC_ERM peripheral base pointers */
  #define NETC_ERM_BASE_PTRS_NS                    { NETC__ERM_NS }
#else
  /** Peripheral NETC__ERM base address */
  #define NETC__ERM_BASE                           (0x4D060000u)
  /** Peripheral NETC__ERM base pointer */
  #define NETC__ERM                                ((NETC_ERM_Type *)NETC__ERM_BASE)
  /** Array initializer of NETC_ERM peripheral base addresses */
  #define NETC_ERM_BASE_ADDRS                      { NETC__ERM_BASE }
  /** Array initializer of NETC_ERM peripheral base pointers */
  #define NETC_ERM_BASE_PTRS                       { NETC__ERM }
#endif

/* NETC_ETH_LINK - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENETC0_ETH_MAC_PORT base address */
  #define ENETC0_ETH_MAC_PORT_BASE                 (0x5CC95000u)
  /** Peripheral ENETC0_ETH_MAC_PORT base address */
  #define ENETC0_ETH_MAC_PORT_BASE_NS              (0x4CC95000u)
  /** Peripheral ENETC0_ETH_MAC_PORT base pointer */
  #define ENETC0_ETH_MAC_PORT                      ((NETC_ETH_LINK_Type *)ENETC0_ETH_MAC_PORT_BASE)
  /** Peripheral ENETC0_ETH_MAC_PORT base pointer */
  #define ENETC0_ETH_MAC_PORT_NS                   ((NETC_ETH_LINK_Type *)ENETC0_ETH_MAC_PORT_BASE_NS)
  /** Peripheral ENETC1_ETH_MAC_PORT base address */
  #define ENETC1_ETH_MAC_PORT_BASE                 (0x5CCD5000u)
  /** Peripheral ENETC1_ETH_MAC_PORT base address */
  #define ENETC1_ETH_MAC_PORT_BASE_NS              (0x4CCD5000u)
  /** Peripheral ENETC1_ETH_MAC_PORT base pointer */
  #define ENETC1_ETH_MAC_PORT                      ((NETC_ETH_LINK_Type *)ENETC1_ETH_MAC_PORT_BASE)
  /** Peripheral ENETC1_ETH_MAC_PORT base pointer */
  #define ENETC1_ETH_MAC_PORT_NS                   ((NETC_ETH_LINK_Type *)ENETC1_ETH_MAC_PORT_BASE_NS)
  /** Peripheral ENETC2_ETH_MAC_PORT base address */
  #define ENETC2_ETH_MAC_PORT_BASE                 (0x5CD15000u)
  /** Peripheral ENETC2_ETH_MAC_PORT base address */
  #define ENETC2_ETH_MAC_PORT_BASE_NS              (0x4CD15000u)
  /** Peripheral ENETC2_ETH_MAC_PORT base pointer */
  #define ENETC2_ETH_MAC_PORT                      ((NETC_ETH_LINK_Type *)ENETC2_ETH_MAC_PORT_BASE)
  /** Peripheral ENETC2_ETH_MAC_PORT base pointer */
  #define ENETC2_ETH_MAC_PORT_NS                   ((NETC_ETH_LINK_Type *)ENETC2_ETH_MAC_PORT_BASE_NS)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0_BASE (0x5CC05000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0_BASE_NS (0x4CC05000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0 ((NETC_ETH_LINK_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0_NS ((NETC_ETH_LINK_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0_BASE_NS)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1_BASE (0x5CC09000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1_BASE_NS (0x4CC09000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1 ((NETC_ETH_LINK_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1_NS ((NETC_ETH_LINK_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1_BASE_NS)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2_BASE (0x5CC0D000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2_BASE_NS (0x4CC0D000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2 ((NETC_ETH_LINK_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2_NS ((NETC_ETH_LINK_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2_BASE_NS)
  /** Array initializer of NETC_ETH_LINK peripheral base addresses */
  #define NETC_ETH_LINK_BASE_ADDRS                 { ENETC0_ETH_MAC_PORT_BASE, ENETC1_ETH_MAC_PORT_BASE, ENETC2_ETH_MAC_PORT_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2_BASE }
  /** Array initializer of NETC_ETH_LINK peripheral base pointers */
  #define NETC_ETH_LINK_BASE_PTRS                  { ENETC0_ETH_MAC_PORT, ENETC1_ETH_MAC_PORT, ENETC2_ETH_MAC_PORT, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2 }
  /** Array initializer of NETC_ETH_LINK peripheral base addresses */
  #define NETC_ETH_LINK_BASE_ADDRS_NS              { ENETC0_ETH_MAC_PORT_BASE_NS, ENETC1_ETH_MAC_PORT_BASE_NS, ENETC2_ETH_MAC_PORT_BASE_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0_BASE_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1_BASE_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2_BASE_NS }
  /** Array initializer of NETC_ETH_LINK peripheral base pointers */
  #define NETC_ETH_LINK_BASE_PTRS_NS               { ENETC0_ETH_MAC_PORT_NS, ENETC1_ETH_MAC_PORT_NS, ENETC2_ETH_MAC_PORT_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT0_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT1_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_ETH_MAC_PORT2_NS }
#else
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
#endif

/* NETC_IERB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC_IERB base address */
  #define NETC_IERB_BASE                           (0x5CEB0000u)
  /** Peripheral NETC_IERB base address */
  #define NETC_IERB_BASE_NS                        (0x4CEB0000u)
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
  #define NETC_IERB_BASE                           (0x4CEB0000u)
  /** Peripheral NETC_IERB base pointer */
  #define NETC_IERB                                ((NETC_IERB_Type *)NETC_IERB_BASE)
  /** Array initializer of NETC_IERB peripheral base addresses */
  #define NETC_IERB_BASE_ADDRS                     { NETC_IERB_BASE }
  /** Array initializer of NETC_IERB peripheral base pointers */
  #define NETC_IERB_BASE_PTRS                      { NETC_IERB }
#endif

/* NETC_LSTCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__LSTCU base address */
  #define NETC__LSTCU_BASE                         (0x5D090000u)
  /** Peripheral NETC__LSTCU base address */
  #define NETC__LSTCU_BASE_NS                      (0x4D090000u)
  /** Peripheral NETC__LSTCU base pointer */
  #define NETC__LSTCU                              ((NETC_LSTCU_Type *)NETC__LSTCU_BASE)
  /** Peripheral NETC__LSTCU base pointer */
  #define NETC__LSTCU_NS                           ((NETC_LSTCU_Type *)NETC__LSTCU_BASE_NS)
  /** Array initializer of NETC_LSTCU peripheral base addresses */
  #define NETC_LSTCU_BASE_ADDRS                    { NETC__LSTCU_BASE }
  /** Array initializer of NETC_LSTCU peripheral base pointers */
  #define NETC_LSTCU_BASE_PTRS                     { NETC__LSTCU }
  /** Array initializer of NETC_LSTCU peripheral base addresses */
  #define NETC_LSTCU_BASE_ADDRS_NS                 { NETC__LSTCU_BASE_NS }
  /** Array initializer of NETC_LSTCU peripheral base pointers */
  #define NETC_LSTCU_BASE_PTRS_NS                  { NETC__LSTCU_NS }
#else
  /** Peripheral NETC__LSTCU base address */
  #define NETC__LSTCU_BASE                         (0x4D090000u)
  /** Peripheral NETC__LSTCU base pointer */
  #define NETC__LSTCU                              ((NETC_LSTCU_Type *)NETC__LSTCU_BASE)
  /** Array initializer of NETC_LSTCU peripheral base addresses */
  #define NETC_LSTCU_BASE_ADDRS                    { NETC__LSTCU_BASE }
  /** Array initializer of NETC_LSTCU peripheral base pointers */
  #define NETC_LSTCU_BASE_PTRS                     { NETC__LSTCU }
#endif

/* NETC_MAX_CORE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__AXBS_MAX_CORE base address */
  #define NETC__AXBS_MAX_CORE_BASE                 (0x5D1D0000u)
  /** Peripheral NETC__AXBS_MAX_CORE base address */
  #define NETC__AXBS_MAX_CORE_BASE_NS              (0x4D1D0000u)
  /** Peripheral NETC__AXBS_MAX_CORE base pointer */
  #define NETC__AXBS_MAX_CORE                      ((NETC_MAX_CORE_Type *)NETC__AXBS_MAX_CORE_BASE)
  /** Peripheral NETC__AXBS_MAX_CORE base pointer */
  #define NETC__AXBS_MAX_CORE_NS                   ((NETC_MAX_CORE_Type *)NETC__AXBS_MAX_CORE_BASE_NS)
  /** Array initializer of NETC_MAX_CORE peripheral base addresses */
  #define NETC_MAX_CORE_BASE_ADDRS                 { NETC__AXBS_MAX_CORE_BASE }
  /** Array initializer of NETC_MAX_CORE peripheral base pointers */
  #define NETC_MAX_CORE_BASE_PTRS                  { NETC__AXBS_MAX_CORE }
  /** Array initializer of NETC_MAX_CORE peripheral base addresses */
  #define NETC_MAX_CORE_BASE_ADDRS_NS              { NETC__AXBS_MAX_CORE_BASE_NS }
  /** Array initializer of NETC_MAX_CORE peripheral base pointers */
  #define NETC_MAX_CORE_BASE_PTRS_NS               { NETC__AXBS_MAX_CORE_NS }
#else
  /** Peripheral NETC__AXBS_MAX_CORE base address */
  #define NETC__AXBS_MAX_CORE_BASE                 (0x4D1D0000u)
  /** Peripheral NETC__AXBS_MAX_CORE base pointer */
  #define NETC__AXBS_MAX_CORE                      ((NETC_MAX_CORE_Type *)NETC__AXBS_MAX_CORE_BASE)
  /** Array initializer of NETC_MAX_CORE peripheral base addresses */
  #define NETC_MAX_CORE_BASE_ADDRS                 { NETC__AXBS_MAX_CORE_BASE }
  /** Array initializer of NETC_MAX_CORE peripheral base pointers */
  #define NETC_MAX_CORE_BASE_PTRS                  { NETC__AXBS_MAX_CORE }
#endif

/* NETC_OCSRAM_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__OCRAM_MCM base address */
  #define NETC__OCRAM_MCM_BASE                     (0x5D0B0000u)
  /** Peripheral NETC__OCRAM_MCM base address */
  #define NETC__OCRAM_MCM_BASE_NS                  (0x4D0B0000u)
  /** Peripheral NETC__OCRAM_MCM base pointer */
  #define NETC__OCRAM_MCM                          ((NETC_OCSRAM_MCM_Type *)NETC__OCRAM_MCM_BASE)
  /** Peripheral NETC__OCRAM_MCM base pointer */
  #define NETC__OCRAM_MCM_NS                       ((NETC_OCSRAM_MCM_Type *)NETC__OCRAM_MCM_BASE_NS)
  /** Array initializer of NETC_OCSRAM_MCM peripheral base addresses */
  #define NETC_OCSRAM_MCM_BASE_ADDRS               { NETC__OCRAM_MCM_BASE }
  /** Array initializer of NETC_OCSRAM_MCM peripheral base pointers */
  #define NETC_OCSRAM_MCM_BASE_PTRS                { NETC__OCRAM_MCM }
  /** Array initializer of NETC_OCSRAM_MCM peripheral base addresses */
  #define NETC_OCSRAM_MCM_BASE_ADDRS_NS            { NETC__OCRAM_MCM_BASE_NS }
  /** Array initializer of NETC_OCSRAM_MCM peripheral base pointers */
  #define NETC_OCSRAM_MCM_BASE_PTRS_NS             { NETC__OCRAM_MCM_NS }
#else
  /** Peripheral NETC__OCRAM_MCM base address */
  #define NETC__OCRAM_MCM_BASE                     (0x4D0B0000u)
  /** Peripheral NETC__OCRAM_MCM base pointer */
  #define NETC__OCRAM_MCM                          ((NETC_OCSRAM_MCM_Type *)NETC__OCRAM_MCM_BASE)
  /** Array initializer of NETC_OCSRAM_MCM peripheral base addresses */
  #define NETC_OCSRAM_MCM_BASE_ADDRS               { NETC__OCRAM_MCM_BASE }
  /** Array initializer of NETC_OCSRAM_MCM peripheral base pointers */
  #define NETC_OCSRAM_MCM_BASE_PTRS                { NETC__OCRAM_MCM }
#endif

/* NETC_PORT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENETC0_PORT base address */
  #define ENETC0_PORT_BASE                         (0x5CC94000u)
  /** Peripheral ENETC0_PORT base address */
  #define ENETC0_PORT_BASE_NS                      (0x4CC94000u)
  /** Peripheral ENETC0_PORT base pointer */
  #define ENETC0_PORT                              ((NETC_PORT_Type *)ENETC0_PORT_BASE)
  /** Peripheral ENETC0_PORT base pointer */
  #define ENETC0_PORT_NS                           ((NETC_PORT_Type *)ENETC0_PORT_BASE_NS)
  /** Peripheral ENETC1_PORT base address */
  #define ENETC1_PORT_BASE                         (0x5CCD4000u)
  /** Peripheral ENETC1_PORT base address */
  #define ENETC1_PORT_BASE_NS                      (0x4CCD4000u)
  /** Peripheral ENETC1_PORT base pointer */
  #define ENETC1_PORT                              ((NETC_PORT_Type *)ENETC1_PORT_BASE)
  /** Peripheral ENETC1_PORT base pointer */
  #define ENETC1_PORT_NS                           ((NETC_PORT_Type *)ENETC1_PORT_BASE_NS)
  /** Peripheral ENETC2_PORT base address */
  #define ENETC2_PORT_BASE                         (0x5CD14000u)
  /** Peripheral ENETC2_PORT base address */
  #define ENETC2_PORT_BASE_NS                      (0x4CD14000u)
  /** Peripheral ENETC2_PORT base pointer */
  #define ENETC2_PORT                              ((NETC_PORT_Type *)ENETC2_PORT_BASE)
  /** Peripheral ENETC2_PORT base pointer */
  #define ENETC2_PORT_NS                           ((NETC_PORT_Type *)ENETC2_PORT_BASE_NS)
  /** Peripheral SW0_PORT0 base address */
  #define SW0_PORT0_BASE                           (0x5CC04000u)
  /** Peripheral SW0_PORT0 base address */
  #define SW0_PORT0_BASE_NS                        (0x4CC04000u)
  /** Peripheral SW0_PORT0 base pointer */
  #define SW0_PORT0                                ((NETC_PORT_Type *)SW0_PORT0_BASE)
  /** Peripheral SW0_PORT0 base pointer */
  #define SW0_PORT0_NS                             ((NETC_PORT_Type *)SW0_PORT0_BASE_NS)
  /** Peripheral SW0_PORT1 base address */
  #define SW0_PORT1_BASE                           (0x5CC08000u)
  /** Peripheral SW0_PORT1 base address */
  #define SW0_PORT1_BASE_NS                        (0x4CC08000u)
  /** Peripheral SW0_PORT1 base pointer */
  #define SW0_PORT1                                ((NETC_PORT_Type *)SW0_PORT1_BASE)
  /** Peripheral SW0_PORT1 base pointer */
  #define SW0_PORT1_NS                             ((NETC_PORT_Type *)SW0_PORT1_BASE_NS)
  /** Peripheral SW0_PORT2 base address */
  #define SW0_PORT2_BASE                           (0x5CC0C000u)
  /** Peripheral SW0_PORT2 base address */
  #define SW0_PORT2_BASE_NS                        (0x4CC0C000u)
  /** Peripheral SW0_PORT2 base pointer */
  #define SW0_PORT2                                ((NETC_PORT_Type *)SW0_PORT2_BASE)
  /** Peripheral SW0_PORT2 base pointer */
  #define SW0_PORT2_NS                             ((NETC_PORT_Type *)SW0_PORT2_BASE_NS)
  /** Array initializer of NETC_PORT peripheral base addresses */
  #define NETC_PORT_BASE_ADDRS                     { ENETC0_PORT_BASE, ENETC1_PORT_BASE, ENETC2_PORT_BASE, SW0_PORT0_BASE, SW0_PORT1_BASE, SW0_PORT2_BASE }
  /** Array initializer of NETC_PORT peripheral base pointers */
  #define NETC_PORT_BASE_PTRS                      { ENETC0_PORT, ENETC1_PORT, ENETC2_PORT, SW0_PORT0, SW0_PORT1, SW0_PORT2 }
  /** Array initializer of NETC_PORT peripheral base addresses */
  #define NETC_PORT_BASE_ADDRS_NS                  { ENETC0_PORT_BASE_NS, ENETC1_PORT_BASE_NS, ENETC2_PORT_BASE_NS, SW0_PORT0_BASE_NS, SW0_PORT1_BASE_NS, SW0_PORT2_BASE_NS }
  /** Array initializer of NETC_PORT peripheral base pointers */
  #define NETC_PORT_BASE_PTRS_NS                   { ENETC0_PORT_NS, ENETC1_PORT_NS, ENETC2_PORT_NS, SW0_PORT0_NS, SW0_PORT1_NS, SW0_PORT2_NS }
#else
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
#endif

/* NETC_PRIV - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC_PRIV base address */
  #define NETC_PRIV_BASE                           (0x5CEC0000u)
  /** Peripheral NETC_PRIV base address */
  #define NETC_PRIV_BASE_NS                        (0x4CEC0000u)
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
  #define NETC_PRIV_BASE                           (0x4CEC0000u)
  /** Peripheral NETC_PRIV base pointer */
  #define NETC_PRIV                                ((NETC_PRIV_Type *)NETC_PRIV_BASE)
  /** Array initializer of NETC_PRIV peripheral base addresses */
  #define NETC_PRIV_BASE_ADDRS                     { NETC_PRIV_BASE }
  /** Array initializer of NETC_PRIV peripheral base pointers */
  #define NETC_PRIV_BASE_PTRS                      { NETC_PRIV }
#endif

/* NETC_PSEUDO_LINK - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ENETC3_PSEUDO_MAC_PORT base address */
  #define ENETC3_PSEUDO_MAC_PORT_BASE              (0x5CD55000u)
  /** Peripheral ENETC3_PSEUDO_MAC_PORT base address */
  #define ENETC3_PSEUDO_MAC_PORT_BASE_NS           (0x4CD55000u)
  /** Peripheral ENETC3_PSEUDO_MAC_PORT base pointer */
  #define ENETC3_PSEUDO_MAC_PORT                   ((NETC_PSEUDO_LINK_Type *)ENETC3_PSEUDO_MAC_PORT_BASE)
  /** Peripheral ENETC3_PSEUDO_MAC_PORT base pointer */
  #define ENETC3_PSEUDO_MAC_PORT_NS                ((NETC_PSEUDO_LINK_Type *)ENETC3_PSEUDO_MAC_PORT_BASE_NS)
  /** Array initializer of NETC_PSEUDO_LINK peripheral base addresses */
  #define NETC_PSEUDO_LINK_BASE_ADDRS              { ENETC3_PSEUDO_MAC_PORT_BASE }
  /** Array initializer of NETC_PSEUDO_LINK peripheral base pointers */
  #define NETC_PSEUDO_LINK_BASE_PTRS               { ENETC3_PSEUDO_MAC_PORT }
  /** Array initializer of NETC_PSEUDO_LINK peripheral base addresses */
  #define NETC_PSEUDO_LINK_BASE_ADDRS_NS           { ENETC3_PSEUDO_MAC_PORT_BASE_NS }
  /** Array initializer of NETC_PSEUDO_LINK peripheral base pointers */
  #define NETC_PSEUDO_LINK_BASE_PTRS_NS            { ENETC3_PSEUDO_MAC_PORT_NS }
#else
  /** Peripheral ENETC3_PSEUDO_MAC_PORT base address */
  #define ENETC3_PSEUDO_MAC_PORT_BASE              (0x4CD55000u)
  /** Peripheral ENETC3_PSEUDO_MAC_PORT base pointer */
  #define ENETC3_PSEUDO_MAC_PORT                   ((NETC_PSEUDO_LINK_Type *)ENETC3_PSEUDO_MAC_PORT_BASE)
  /** Array initializer of NETC_PSEUDO_LINK peripheral base addresses */
  #define NETC_PSEUDO_LINK_BASE_ADDRS              { ENETC3_PSEUDO_MAC_PORT_BASE }
  /** Array initializer of NETC_PSEUDO_LINK peripheral base pointers */
  #define NETC_PSEUDO_LINK_BASE_PTRS               { ENETC3_PSEUDO_MAC_PORT }
#endif

/* NETC_SW - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SW0_BASE base address */
  #define SW0_BASE_BASE                            (0x5CC00000u)
  /** Peripheral SW0_BASE base address */
  #define SW0_BASE_BASE_NS                         (0x4CC00000u)
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
  #define SW0_BASE_BASE                            (0x4CC00000u)
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
  #define ENETC0_COMMON_BASE                       (0x5CC91000u)
  /** Peripheral ENETC0_COMMON base address */
  #define ENETC0_COMMON_BASE_NS                    (0x4CC91000u)
  /** Peripheral ENETC0_COMMON base pointer */
  #define ENETC0_COMMON                            ((NETC_SW_ENETC_Type *)ENETC0_COMMON_BASE)
  /** Peripheral ENETC0_COMMON base pointer */
  #define ENETC0_COMMON_NS                         ((NETC_SW_ENETC_Type *)ENETC0_COMMON_BASE_NS)
  /** Peripheral ENETC1_COMMON base address */
  #define ENETC1_COMMON_BASE                       (0x5CCD1000u)
  /** Peripheral ENETC1_COMMON base address */
  #define ENETC1_COMMON_BASE_NS                    (0x4CCD1000u)
  /** Peripheral ENETC1_COMMON base pointer */
  #define ENETC1_COMMON                            ((NETC_SW_ENETC_Type *)ENETC1_COMMON_BASE)
  /** Peripheral ENETC1_COMMON base pointer */
  #define ENETC1_COMMON_NS                         ((NETC_SW_ENETC_Type *)ENETC1_COMMON_BASE_NS)
  /** Peripheral ENETC2_COMMON base address */
  #define ENETC2_COMMON_BASE                       (0x5CD11000u)
  /** Peripheral ENETC2_COMMON base address */
  #define ENETC2_COMMON_BASE_NS                    (0x4CD11000u)
  /** Peripheral ENETC2_COMMON base pointer */
  #define ENETC2_COMMON                            ((NETC_SW_ENETC_Type *)ENETC2_COMMON_BASE)
  /** Peripheral ENETC2_COMMON base pointer */
  #define ENETC2_COMMON_NS                         ((NETC_SW_ENETC_Type *)ENETC2_COMMON_BASE_NS)
  /** Peripheral SW0_COMMON base address */
  #define SW0_COMMON_BASE                          (0x5CC01000u)
  /** Peripheral SW0_COMMON base address */
  #define SW0_COMMON_BASE_NS                       (0x4CC01000u)
  /** Peripheral SW0_COMMON base pointer */
  #define SW0_COMMON                               ((NETC_SW_ENETC_Type *)SW0_COMMON_BASE)
  /** Peripheral SW0_COMMON base pointer */
  #define SW0_COMMON_NS                            ((NETC_SW_ENETC_Type *)SW0_COMMON_BASE_NS)
  /** Array initializer of NETC_SW_ENETC peripheral base addresses */
  #define NETC_SW_ENETC_BASE_ADDRS                 { ENETC0_COMMON_BASE, ENETC1_COMMON_BASE, ENETC2_COMMON_BASE, SW0_COMMON_BASE }
  /** Array initializer of NETC_SW_ENETC peripheral base pointers */
  #define NETC_SW_ENETC_BASE_PTRS                  { ENETC0_COMMON, ENETC1_COMMON, ENETC2_COMMON, SW0_COMMON }
  /** Array initializer of NETC_SW_ENETC peripheral base addresses */
  #define NETC_SW_ENETC_BASE_ADDRS_NS              { ENETC0_COMMON_BASE_NS, ENETC1_COMMON_BASE_NS, ENETC2_COMMON_BASE_NS, SW0_COMMON_BASE_NS }
  /** Array initializer of NETC_SW_ENETC peripheral base pointers */
  #define NETC_SW_ENETC_BASE_PTRS_NS               { ENETC0_COMMON_NS, ENETC1_COMMON_NS, ENETC2_COMMON_NS, SW0_COMMON_NS }
#else
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
#endif

/* NETC_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__TCU base address */
  #define NETC__TCU_BASE                           (0x5C800000u)
  /** Peripheral NETC__TCU base address */
  #define NETC__TCU_BASE_NS                        (0x4C800000u)
  /** Peripheral NETC__TCU base pointer */
  #define NETC__TCU                                ((NETC_TCU_Type *)NETC__TCU_BASE)
  /** Peripheral NETC__TCU base pointer */
  #define NETC__TCU_NS                             ((NETC_TCU_Type *)NETC__TCU_BASE_NS)
  /** Array initializer of NETC_TCU peripheral base addresses */
  #define NETC_TCU_BASE_ADDRS                      { NETC__TCU_BASE }
  /** Array initializer of NETC_TCU peripheral base pointers */
  #define NETC_TCU_BASE_PTRS                       { NETC__TCU }
  /** Array initializer of NETC_TCU peripheral base addresses */
  #define NETC_TCU_BASE_ADDRS_NS                   { NETC__TCU_BASE_NS }
  /** Array initializer of NETC_TCU peripheral base pointers */
  #define NETC_TCU_BASE_PTRS_NS                    { NETC__TCU_NS }
#else
  /** Peripheral NETC__TCU base address */
  #define NETC__TCU_BASE                           (0x4C800000u)
  /** Peripheral NETC__TCU base pointer */
  #define NETC__TCU                                ((NETC_TCU_Type *)NETC__TCU_BASE)
  /** Array initializer of NETC_TCU peripheral base addresses */
  #define NETC_TCU_BASE_ADDRS                      { NETC__TCU_BASE }
  /** Array initializer of NETC_TCU peripheral base pointers */
  #define NETC_TCU_BASE_PTRS                       { NETC__TCU }
#endif

/* NETC_TCU_CM33 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__TCU_CM33 base address */
  #define NETC__TCU_CM33_BASE                      (0x5D000000u)
  /** Peripheral NETC__TCU_CM33 base address */
  #define NETC__TCU_CM33_BASE_NS                   (0x4D000000u)
  /** Peripheral NETC__TCU_CM33 base pointer */
  #define NETC__TCU_CM33                           ((NETC_TCU_CM33_Type *)NETC__TCU_CM33_BASE)
  /** Peripheral NETC__TCU_CM33 base pointer */
  #define NETC__TCU_CM33_NS                        ((NETC_TCU_CM33_Type *)NETC__TCU_CM33_BASE_NS)
  /** Array initializer of NETC_TCU_CM33 peripheral base addresses */
  #define NETC_TCU_CM33_BASE_ADDRS                 { NETC__TCU_CM33_BASE }
  /** Array initializer of NETC_TCU_CM33 peripheral base pointers */
  #define NETC_TCU_CM33_BASE_PTRS                  { NETC__TCU_CM33 }
  /** Array initializer of NETC_TCU_CM33 peripheral base addresses */
  #define NETC_TCU_CM33_BASE_ADDRS_NS              { NETC__TCU_CM33_BASE_NS }
  /** Array initializer of NETC_TCU_CM33 peripheral base pointers */
  #define NETC_TCU_CM33_BASE_PTRS_NS               { NETC__TCU_CM33_NS }
#else
  /** Peripheral NETC__TCU_CM33 base address */
  #define NETC__TCU_CM33_BASE                      (0x4D000000u)
  /** Peripheral NETC__TCU_CM33 base pointer */
  #define NETC__TCU_CM33                           ((NETC_TCU_CM33_Type *)NETC__TCU_CM33_BASE)
  /** Array initializer of NETC_TCU_CM33 peripheral base addresses */
  #define NETC_TCU_CM33_BASE_ADDRS                 { NETC__TCU_CM33_BASE }
  /** Array initializer of NETC_TCU_CM33 peripheral base pointers */
  #define NETC_TCU_CM33_BASE_PTRS                  { NETC__TCU_CM33 }
#endif

/* NETC_TMR_BASE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE_BASE (0x5CDA0000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE_BASE_NS (0x4CDA0000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE   ((NETC_TMR_BASE_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE_NS ((NETC_TMR_BASE_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE_BASE_NS)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE_BASE (0x5CDC0000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE_BASE_NS (0x4CDC0000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE   ((NETC_TMR_BASE_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE_NS ((NETC_TMR_BASE_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE_BASE_NS)
  /** Array initializer of NETC_TMR_BASE peripheral base addresses */
  #define NETC_TMR_BASE_BASE_ADDRS                 { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE_BASE }
  /** Array initializer of NETC_TMR_BASE peripheral base pointers */
  #define NETC_TMR_BASE_BASE_PTRS                  { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE }
  /** Array initializer of NETC_TMR_BASE peripheral base addresses */
  #define NETC_TMR_BASE_BASE_ADDRS_NS              { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE_BASE_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE_BASE_NS }
  /** Array initializer of NETC_TMR_BASE peripheral base pointers */
  #define NETC_TMR_BASE_BASE_PTRS_NS               { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_BASE_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_BASE_NS }
#else
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
#endif

/* NETC_TRDC_MGR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__TRDC_MGRE base address */
  #define NETC__TRDC_MGRE_BASE                     (0x5C840000u)
  /** Peripheral NETC__TRDC_MGRE base address */
  #define NETC__TRDC_MGRE_BASE_NS                  (0x4C840000u)
  /** Peripheral NETC__TRDC_MGRE base pointer */
  #define NETC__TRDC_MGRE                          ((NETC_TRDC_MGR_Type *)NETC__TRDC_MGRE_BASE)
  /** Peripheral NETC__TRDC_MGRE base pointer */
  #define NETC__TRDC_MGRE_NS                       ((NETC_TRDC_MGR_Type *)NETC__TRDC_MGRE_BASE_NS)
  /** Array initializer of NETC_TRDC_MGR peripheral base addresses */
  #define NETC_TRDC_MGR_BASE_ADDRS                 { NETC__TRDC_MGRE_BASE }
  /** Array initializer of NETC_TRDC_MGR peripheral base pointers */
  #define NETC_TRDC_MGR_BASE_PTRS                  { NETC__TRDC_MGRE }
  /** Array initializer of NETC_TRDC_MGR peripheral base addresses */
  #define NETC_TRDC_MGR_BASE_ADDRS_NS              { NETC__TRDC_MGRE_BASE_NS }
  /** Array initializer of NETC_TRDC_MGR peripheral base pointers */
  #define NETC_TRDC_MGR_BASE_PTRS_NS               { NETC__TRDC_MGRE_NS }
#else
  /** Peripheral NETC__TRDC_MGRE base address */
  #define NETC__TRDC_MGRE_BASE                     (0x4C840000u)
  /** Peripheral NETC__TRDC_MGRE base pointer */
  #define NETC__TRDC_MGRE                          ((NETC_TRDC_MGR_Type *)NETC__TRDC_MGRE_BASE)
  /** Array initializer of NETC_TRDC_MGR peripheral base addresses */
  #define NETC_TRDC_MGR_BASE_ADDRS                 { NETC__TRDC_MGRE_BASE }
  /** Array initializer of NETC_TRDC_MGR peripheral base pointers */
  #define NETC_TRDC_MGR_BASE_PTRS                  { NETC__TRDC_MGRE }
#endif

/* NETC_TRDC_MGR_CM33 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__TRDC_MGRE_CM33 base address */
  #define NETC__TRDC_MGRE_CM33_BASE                (0x5D040000u)
  /** Peripheral NETC__TRDC_MGRE_CM33 base address */
  #define NETC__TRDC_MGRE_CM33_BASE_NS             (0x4D040000u)
  /** Peripheral NETC__TRDC_MGRE_CM33 base pointer */
  #define NETC__TRDC_MGRE_CM33                     ((NETC_TRDC_MGR_CM33_Type *)NETC__TRDC_MGRE_CM33_BASE)
  /** Peripheral NETC__TRDC_MGRE_CM33 base pointer */
  #define NETC__TRDC_MGRE_CM33_NS                  ((NETC_TRDC_MGR_CM33_Type *)NETC__TRDC_MGRE_CM33_BASE_NS)
  /** Array initializer of NETC_TRDC_MGR_CM33 peripheral base addresses */
  #define NETC_TRDC_MGR_CM33_BASE_ADDRS            { NETC__TRDC_MGRE_CM33_BASE }
  /** Array initializer of NETC_TRDC_MGR_CM33 peripheral base pointers */
  #define NETC_TRDC_MGR_CM33_BASE_PTRS             { NETC__TRDC_MGRE_CM33 }
  /** Array initializer of NETC_TRDC_MGR_CM33 peripheral base addresses */
  #define NETC_TRDC_MGR_CM33_BASE_ADDRS_NS         { NETC__TRDC_MGRE_CM33_BASE_NS }
  /** Array initializer of NETC_TRDC_MGR_CM33 peripheral base pointers */
  #define NETC_TRDC_MGR_CM33_BASE_PTRS_NS          { NETC__TRDC_MGRE_CM33_NS }
#else
  /** Peripheral NETC__TRDC_MGRE_CM33 base address */
  #define NETC__TRDC_MGRE_CM33_BASE                (0x4D040000u)
  /** Peripheral NETC__TRDC_MGRE_CM33 base pointer */
  #define NETC__TRDC_MGRE_CM33                     ((NETC_TRDC_MGR_CM33_Type *)NETC__TRDC_MGRE_CM33_BASE)
  /** Array initializer of NETC_TRDC_MGR_CM33 peripheral base addresses */
  #define NETC_TRDC_MGR_CM33_BASE_ADDRS            { NETC__TRDC_MGRE_CM33_BASE }
  /** Array initializer of NETC_TRDC_MGR_CM33 peripheral base pointers */
  #define NETC_TRDC_MGR_CM33_BASE_PTRS             { NETC__TRDC_MGRE_CM33 }
#endif

/* NEUTRON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON0__NEUTRON base address */
  #define NPU__NEUTRON_NPU__NEUTRON0__NEUTRON_BASE (0x5ABC0000u)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON0__NEUTRON base address */
  #define NPU__NEUTRON_NPU__NEUTRON0__NEUTRON_BASE_NS (0x4ABC0000u)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON0__NEUTRON base pointer */
  #define NPU__NEUTRON_NPU__NEUTRON0__NEUTRON      ((NEUTRON_Type *)NPU__NEUTRON_NPU__NEUTRON0__NEUTRON_BASE)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON0__NEUTRON base pointer */
  #define NPU__NEUTRON_NPU__NEUTRON0__NEUTRON_NS   ((NEUTRON_Type *)NPU__NEUTRON_NPU__NEUTRON0__NEUTRON_BASE_NS)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON base address */
  #define NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON_BASE (0x5ABC4000u)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON base address */
  #define NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON_BASE_NS (0x4ABC4000u)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON base pointer */
  #define NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON ((NEUTRON_Type *)NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON_BASE)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON base pointer */
  #define NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON_NS ((NEUTRON_Type *)NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON_BASE_NS)
  /** Array initializer of NEUTRON peripheral base addresses */
  #define NEUTRON_BASE_ADDRS                       { NPU__NEUTRON_NPU__NEUTRON0__NEUTRON_BASE, NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON_BASE }
  /** Array initializer of NEUTRON peripheral base pointers */
  #define NEUTRON_BASE_PTRS                        { NPU__NEUTRON_NPU__NEUTRON0__NEUTRON, NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON }
  /** Array initializer of NEUTRON peripheral base addresses */
  #define NEUTRON_BASE_ADDRS_NS                    { NPU__NEUTRON_NPU__NEUTRON0__NEUTRON_BASE_NS, NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON_BASE_NS }
  /** Array initializer of NEUTRON peripheral base pointers */
  #define NEUTRON_BASE_PTRS_NS                     { NPU__NEUTRON_NPU__NEUTRON0__NEUTRON_NS, NPU__NEUTRON_NPU__NEUTRON_GANGED__NEUTRON_NS }
#else
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
#endif

/* NOC_BLK_CTRL_NOCMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_NOCMIX base address */
  #define BLK_CTRL_NOCMIX_BASE                     (0x59000000u)
  /** Peripheral BLK_CTRL_NOCMIX base address */
  #define BLK_CTRL_NOCMIX_BASE_NS                  (0x49000000u)
  /** Peripheral BLK_CTRL_NOCMIX base pointer */
  #define BLK_CTRL_NOCMIX                          ((NOC_BLK_CTRL_NOCMIX_Type *)BLK_CTRL_NOCMIX_BASE)
  /** Peripheral BLK_CTRL_NOCMIX base pointer */
  #define BLK_CTRL_NOCMIX_NS                       ((NOC_BLK_CTRL_NOCMIX_Type *)BLK_CTRL_NOCMIX_BASE_NS)
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base addresses */
  #define NOC_BLK_CTRL_NOCMIX_BASE_ADDRS           { BLK_CTRL_NOCMIX_BASE }
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base pointers */
  #define NOC_BLK_CTRL_NOCMIX_BASE_PTRS            { BLK_CTRL_NOCMIX }
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base addresses */
  #define NOC_BLK_CTRL_NOCMIX_BASE_ADDRS_NS        { BLK_CTRL_NOCMIX_BASE_NS }
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base pointers */
  #define NOC_BLK_CTRL_NOCMIX_BASE_PTRS_NS         { BLK_CTRL_NOCMIX_NS }
#else
  /** Peripheral BLK_CTRL_NOCMIX base address */
  #define BLK_CTRL_NOCMIX_BASE                     (0x49000000u)
  /** Peripheral BLK_CTRL_NOCMIX base pointer */
  #define BLK_CTRL_NOCMIX                          ((NOC_BLK_CTRL_NOCMIX_Type *)BLK_CTRL_NOCMIX_BASE)
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base addresses */
  #define NOC_BLK_CTRL_NOCMIX_BASE_ADDRS           { BLK_CTRL_NOCMIX_BASE }
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base pointers */
  #define NOC_BLK_CTRL_NOCMIX_BASE_PTRS            { BLK_CTRL_NOCMIX }
#endif

/* NOC_CMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__CMU_N0 base address */
  #define NOC__CMU_N0_BASE                         (0x59070000u)
  /** Peripheral NOC__CMU_N0 base address */
  #define NOC__CMU_N0_BASE_NS                      (0x49070000u)
  /** Peripheral NOC__CMU_N0 base pointer */
  #define NOC__CMU_N0                              ((NOC_CMU_Type *)NOC__CMU_N0_BASE)
  /** Peripheral NOC__CMU_N0 base pointer */
  #define NOC__CMU_N0_NS                           ((NOC_CMU_Type *)NOC__CMU_N0_BASE_NS)
  /** Peripheral NOC__CMU_N1 base address */
  #define NOC__CMU_N1_BASE                         (0x59080000u)
  /** Peripheral NOC__CMU_N1 base address */
  #define NOC__CMU_N1_BASE_NS                      (0x49080000u)
  /** Peripheral NOC__CMU_N1 base pointer */
  #define NOC__CMU_N1                              ((NOC_CMU_Type *)NOC__CMU_N1_BASE)
  /** Peripheral NOC__CMU_N1 base pointer */
  #define NOC__CMU_N1_NS                           ((NOC_CMU_Type *)NOC__CMU_N1_BASE_NS)
  /** Array initializer of NOC_CMU peripheral base addresses */
  #define NOC_CMU_BASE_ADDRS                       { NOC__CMU_N0_BASE, NOC__CMU_N1_BASE }
  /** Array initializer of NOC_CMU peripheral base pointers */
  #define NOC_CMU_BASE_PTRS                        { NOC__CMU_N0, NOC__CMU_N1 }
  /** Array initializer of NOC_CMU peripheral base addresses */
  #define NOC_CMU_BASE_ADDRS_NS                    { NOC__CMU_N0_BASE_NS, NOC__CMU_N1_BASE_NS }
  /** Array initializer of NOC_CMU peripheral base pointers */
  #define NOC_CMU_BASE_PTRS_NS                     { NOC__CMU_N0_NS, NOC__CMU_N1_NS }
#else
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
#endif

/* NOC_EIM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__EIMN base address */
  #define NOC__EIMN_BASE                           (0x59210000u)
  /** Peripheral NOC__EIMN base address */
  #define NOC__EIMN_BASE_NS                        (0x49210000u)
  /** Peripheral NOC__EIMN base pointer */
  #define NOC__EIMN                                ((NOC_EIM_Type *)NOC__EIMN_BASE)
  /** Peripheral NOC__EIMN base pointer */
  #define NOC__EIMN_NS                             ((NOC_EIM_Type *)NOC__EIMN_BASE_NS)
  /** Array initializer of NOC_EIM peripheral base addresses */
  #define NOC_EIM_BASE_ADDRS                       { NOC__EIMN_BASE }
  /** Array initializer of NOC_EIM peripheral base pointers */
  #define NOC_EIM_BASE_PTRS                        { NOC__EIMN }
  /** Array initializer of NOC_EIM peripheral base addresses */
  #define NOC_EIM_BASE_ADDRS_NS                    { NOC__EIMN_BASE_NS }
  /** Array initializer of NOC_EIM peripheral base pointers */
  #define NOC_EIM_BASE_PTRS_NS                     { NOC__EIMN_NS }
#else
  /** Peripheral NOC__EIMN base address */
  #define NOC__EIMN_BASE                           (0x49210000u)
  /** Peripheral NOC__EIMN base pointer */
  #define NOC__EIMN                                ((NOC_EIM_Type *)NOC__EIMN_BASE)
  /** Array initializer of NOC_EIM peripheral base addresses */
  #define NOC_EIM_BASE_ADDRS                       { NOC__EIMN_BASE }
  /** Array initializer of NOC_EIM peripheral base pointers */
  #define NOC_EIM_BASE_PTRS                        { NOC__EIMN }
#endif

/* NOC_GICA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICA base address */
  #define NOC__GIC__GICA_BASE                      (0x58010000u)
  /** Peripheral NOC__GIC__GICA base address */
  #define NOC__GIC__GICA_BASE_NS                   (0x48010000u)
  /** Peripheral NOC__GIC__GICA base pointer */
  #define NOC__GIC__GICA                           ((NOC_GICA_Type *)NOC__GIC__GICA_BASE)
  /** Peripheral NOC__GIC__GICA base pointer */
  #define NOC__GIC__GICA_NS                        ((NOC_GICA_Type *)NOC__GIC__GICA_BASE_NS)
  /** Array initializer of NOC_GICA peripheral base addresses */
  #define NOC_GICA_BASE_ADDRS                      { NOC__GIC__GICA_BASE }
  /** Array initializer of NOC_GICA peripheral base pointers */
  #define NOC_GICA_BASE_PTRS                       { NOC__GIC__GICA }
  /** Array initializer of NOC_GICA peripheral base addresses */
  #define NOC_GICA_BASE_ADDRS_NS                   { NOC__GIC__GICA_BASE_NS }
  /** Array initializer of NOC_GICA peripheral base pointers */
  #define NOC_GICA_BASE_PTRS_NS                    { NOC__GIC__GICA_NS }
#else
  /** Peripheral NOC__GIC__GICA base address */
  #define NOC__GIC__GICA_BASE                      (0x48010000u)
  /** Peripheral NOC__GIC__GICA base pointer */
  #define NOC__GIC__GICA                           ((NOC_GICA_Type *)NOC__GIC__GICA_BASE)
  /** Array initializer of NOC_GICA peripheral base addresses */
  #define NOC_GICA_BASE_ADDRS                      { NOC__GIC__GICA_BASE }
  /** Array initializer of NOC_GICA peripheral base pointers */
  #define NOC_GICA_BASE_PTRS                       { NOC__GIC__GICA }
#endif

/* NOC_GICD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICD base address */
  #define NOC__GIC__GICD_BASE                      (0x58000000u)
  /** Peripheral NOC__GIC__GICD base address */
  #define NOC__GIC__GICD_BASE_NS                   (0x48000000u)
  /** Peripheral NOC__GIC__GICD base pointer */
  #define NOC__GIC__GICD                           ((NOC_GICD_Type *)NOC__GIC__GICD_BASE)
  /** Peripheral NOC__GIC__GICD base pointer */
  #define NOC__GIC__GICD_NS                        ((NOC_GICD_Type *)NOC__GIC__GICD_BASE_NS)
  /** Array initializer of NOC_GICD peripheral base addresses */
  #define NOC_GICD_BASE_ADDRS                      { NOC__GIC__GICD_BASE }
  /** Array initializer of NOC_GICD peripheral base pointers */
  #define NOC_GICD_BASE_PTRS                       { NOC__GIC__GICD }
  /** Array initializer of NOC_GICD peripheral base addresses */
  #define NOC_GICD_BASE_ADDRS_NS                   { NOC__GIC__GICD_BASE_NS }
  /** Array initializer of NOC_GICD peripheral base pointers */
  #define NOC_GICD_BASE_PTRS_NS                    { NOC__GIC__GICD_NS }
#else
  /** Peripheral NOC__GIC__GICD base address */
  #define NOC__GIC__GICD_BASE                      (0x48000000u)
  /** Peripheral NOC__GIC__GICD base pointer */
  #define NOC__GIC__GICD                           ((NOC_GICD_Type *)NOC__GIC__GICD_BASE)
  /** Array initializer of NOC_GICD peripheral base addresses */
  #define NOC_GICD_BASE_ADDRS                      { NOC__GIC__GICD_BASE }
  /** Array initializer of NOC_GICD peripheral base pointers */
  #define NOC_GICD_BASE_PTRS                       { NOC__GIC__GICD }
#endif

/* NOC_GICDA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICDA base address */
  #define NOC__GIC__GICDA_BASE                     (0x580E0000u)
  /** Peripheral NOC__GIC__GICDA base address */
  #define NOC__GIC__GICDA_BASE_NS                  (0x480E0000u)
  /** Peripheral NOC__GIC__GICDA base pointer */
  #define NOC__GIC__GICDA                          ((NOC_GICDA_Type *)NOC__GIC__GICDA_BASE)
  /** Peripheral NOC__GIC__GICDA base pointer */
  #define NOC__GIC__GICDA_NS                       ((NOC_GICDA_Type *)NOC__GIC__GICDA_BASE_NS)
  /** Array initializer of NOC_GICDA peripheral base addresses */
  #define NOC_GICDA_BASE_ADDRS                     { NOC__GIC__GICDA_BASE }
  /** Array initializer of NOC_GICDA peripheral base pointers */
  #define NOC_GICDA_BASE_PTRS                      { NOC__GIC__GICDA }
  /** Array initializer of NOC_GICDA peripheral base addresses */
  #define NOC_GICDA_BASE_ADDRS_NS                  { NOC__GIC__GICDA_BASE_NS }
  /** Array initializer of NOC_GICDA peripheral base pointers */
  #define NOC_GICDA_BASE_PTRS_NS                   { NOC__GIC__GICDA_NS }
#else
  /** Peripheral NOC__GIC__GICDA base address */
  #define NOC__GIC__GICDA_BASE                     (0x480E0000u)
  /** Peripheral NOC__GIC__GICDA base pointer */
  #define NOC__GIC__GICDA                          ((NOC_GICDA_Type *)NOC__GIC__GICDA_BASE)
  /** Array initializer of NOC_GICDA peripheral base addresses */
  #define NOC_GICDA_BASE_ADDRS                     { NOC__GIC__GICDA_BASE }
  /** Array initializer of NOC_GICDA peripheral base pointers */
  #define NOC_GICDA_BASE_PTRS                      { NOC__GIC__GICDA }
#endif

/* NOC_GICP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICP base address */
  #define NOC__GIC__GICP_BASE                      (0x58030000u)
  /** Peripheral NOC__GIC__GICP base address */
  #define NOC__GIC__GICP_BASE_NS                   (0x48030000u)
  /** Peripheral NOC__GIC__GICP base pointer */
  #define NOC__GIC__GICP                           ((NOC_GICP_Type *)NOC__GIC__GICP_BASE)
  /** Peripheral NOC__GIC__GICP base pointer */
  #define NOC__GIC__GICP_NS                        ((NOC_GICP_Type *)NOC__GIC__GICP_BASE_NS)
  /** Array initializer of NOC_GICP peripheral base addresses */
  #define NOC_GICP_BASE_ADDRS                      { NOC__GIC__GICP_BASE }
  /** Array initializer of NOC_GICP peripheral base pointers */
  #define NOC_GICP_BASE_PTRS                       { NOC__GIC__GICP }
  /** Array initializer of NOC_GICP peripheral base addresses */
  #define NOC_GICP_BASE_ADDRS_NS                   { NOC__GIC__GICP_BASE_NS }
  /** Array initializer of NOC_GICP peripheral base pointers */
  #define NOC_GICP_BASE_PTRS_NS                    { NOC__GIC__GICP_NS }
#else
  /** Peripheral NOC__GIC__GICP base address */
  #define NOC__GIC__GICP_BASE                      (0x48030000u)
  /** Peripheral NOC__GIC__GICP base pointer */
  #define NOC__GIC__GICP                           ((NOC_GICP_Type *)NOC__GIC__GICP_BASE)
  /** Array initializer of NOC_GICP peripheral base addresses */
  #define NOC_GICP_BASE_ADDRS                      { NOC__GIC__GICP_BASE }
  /** Array initializer of NOC_GICP peripheral base pointers */
  #define NOC_GICP_BASE_PTRS                       { NOC__GIC__GICP }
#endif

/* NOC_GICRlpi0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICRLPI0 base address */
  #define NOC__GIC__GICRLPI0_BASE                  (0x58060000u)
  /** Peripheral NOC__GIC__GICRLPI0 base address */
  #define NOC__GIC__GICRLPI0_BASE_NS               (0x48060000u)
  /** Peripheral NOC__GIC__GICRLPI0 base pointer */
  #define NOC__GIC__GICRLPI0                       ((NOC_GICRlpi0_Type *)NOC__GIC__GICRLPI0_BASE)
  /** Peripheral NOC__GIC__GICRLPI0 base pointer */
  #define NOC__GIC__GICRLPI0_NS                    ((NOC_GICRlpi0_Type *)NOC__GIC__GICRLPI0_BASE_NS)
  /** Array initializer of NOC_GICRlpi0 peripheral base addresses */
  #define NOC_GICRlpi0_BASE_ADDRS                  { NOC__GIC__GICRLPI0_BASE }
  /** Array initializer of NOC_GICRlpi0 peripheral base pointers */
  #define NOC_GICRlpi0_BASE_PTRS                   { NOC__GIC__GICRLPI0 }
  /** Array initializer of NOC_GICRlpi0 peripheral base addresses */
  #define NOC_GICRlpi0_BASE_ADDRS_NS               { NOC__GIC__GICRLPI0_BASE_NS }
  /** Array initializer of NOC_GICRlpi0 peripheral base pointers */
  #define NOC_GICRlpi0_BASE_PTRS_NS                { NOC__GIC__GICRLPI0_NS }
#else
  /** Peripheral NOC__GIC__GICRLPI0 base address */
  #define NOC__GIC__GICRLPI0_BASE                  (0x48060000u)
  /** Peripheral NOC__GIC__GICRLPI0 base pointer */
  #define NOC__GIC__GICRLPI0                       ((NOC_GICRlpi0_Type *)NOC__GIC__GICRLPI0_BASE)
  /** Array initializer of NOC_GICRlpi0 peripheral base addresses */
  #define NOC_GICRlpi0_BASE_ADDRS                  { NOC__GIC__GICRLPI0_BASE }
  /** Array initializer of NOC_GICRlpi0 peripheral base pointers */
  #define NOC_GICRlpi0_BASE_PTRS                   { NOC__GIC__GICRLPI0 }
#endif

/* NOC_GICRlpi1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICRLPI1 base address */
  #define NOC__GIC__GICRLPI1_BASE                  (0x58080000u)
  /** Peripheral NOC__GIC__GICRLPI1 base address */
  #define NOC__GIC__GICRLPI1_BASE_NS               (0x48080000u)
  /** Peripheral NOC__GIC__GICRLPI1 base pointer */
  #define NOC__GIC__GICRLPI1                       ((NOC_GICRlpi1_Type *)NOC__GIC__GICRLPI1_BASE)
  /** Peripheral NOC__GIC__GICRLPI1 base pointer */
  #define NOC__GIC__GICRLPI1_NS                    ((NOC_GICRlpi1_Type *)NOC__GIC__GICRLPI1_BASE_NS)
  /** Array initializer of NOC_GICRlpi1 peripheral base addresses */
  #define NOC_GICRlpi1_BASE_ADDRS                  { NOC__GIC__GICRLPI1_BASE }
  /** Array initializer of NOC_GICRlpi1 peripheral base pointers */
  #define NOC_GICRlpi1_BASE_PTRS                   { NOC__GIC__GICRLPI1 }
  /** Array initializer of NOC_GICRlpi1 peripheral base addresses */
  #define NOC_GICRlpi1_BASE_ADDRS_NS               { NOC__GIC__GICRLPI1_BASE_NS }
  /** Array initializer of NOC_GICRlpi1 peripheral base pointers */
  #define NOC_GICRlpi1_BASE_PTRS_NS                { NOC__GIC__GICRLPI1_NS }
#else
  /** Peripheral NOC__GIC__GICRLPI1 base address */
  #define NOC__GIC__GICRLPI1_BASE                  (0x48080000u)
  /** Peripheral NOC__GIC__GICRLPI1 base pointer */
  #define NOC__GIC__GICRLPI1                       ((NOC_GICRlpi1_Type *)NOC__GIC__GICRLPI1_BASE)
  /** Array initializer of NOC_GICRlpi1 peripheral base addresses */
  #define NOC_GICRlpi1_BASE_ADDRS                  { NOC__GIC__GICRLPI1_BASE }
  /** Array initializer of NOC_GICRlpi1 peripheral base pointers */
  #define NOC_GICRlpi1_BASE_PTRS                   { NOC__GIC__GICRLPI1 }
#endif

/* NOC_GICRlpi2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICRLPI2 base address */
  #define NOC__GIC__GICRLPI2_BASE                  (0x580A0000u)
  /** Peripheral NOC__GIC__GICRLPI2 base address */
  #define NOC__GIC__GICRLPI2_BASE_NS               (0x480A0000u)
  /** Peripheral NOC__GIC__GICRLPI2 base pointer */
  #define NOC__GIC__GICRLPI2                       ((NOC_GICRlpi2_Type *)NOC__GIC__GICRLPI2_BASE)
  /** Peripheral NOC__GIC__GICRLPI2 base pointer */
  #define NOC__GIC__GICRLPI2_NS                    ((NOC_GICRlpi2_Type *)NOC__GIC__GICRLPI2_BASE_NS)
  /** Array initializer of NOC_GICRlpi2 peripheral base addresses */
  #define NOC_GICRlpi2_BASE_ADDRS                  { NOC__GIC__GICRLPI2_BASE }
  /** Array initializer of NOC_GICRlpi2 peripheral base pointers */
  #define NOC_GICRlpi2_BASE_PTRS                   { NOC__GIC__GICRLPI2 }
  /** Array initializer of NOC_GICRlpi2 peripheral base addresses */
  #define NOC_GICRlpi2_BASE_ADDRS_NS               { NOC__GIC__GICRLPI2_BASE_NS }
  /** Array initializer of NOC_GICRlpi2 peripheral base pointers */
  #define NOC_GICRlpi2_BASE_PTRS_NS                { NOC__GIC__GICRLPI2_NS }
#else
  /** Peripheral NOC__GIC__GICRLPI2 base address */
  #define NOC__GIC__GICRLPI2_BASE                  (0x480A0000u)
  /** Peripheral NOC__GIC__GICRLPI2 base pointer */
  #define NOC__GIC__GICRLPI2                       ((NOC_GICRlpi2_Type *)NOC__GIC__GICRLPI2_BASE)
  /** Array initializer of NOC_GICRlpi2 peripheral base addresses */
  #define NOC_GICRlpi2_BASE_ADDRS                  { NOC__GIC__GICRLPI2_BASE }
  /** Array initializer of NOC_GICRlpi2 peripheral base pointers */
  #define NOC_GICRlpi2_BASE_PTRS                   { NOC__GIC__GICRLPI2 }
#endif

/* NOC_GICRlpi3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICRLPI3 base address */
  #define NOC__GIC__GICRLPI3_BASE                  (0x580C0000u)
  /** Peripheral NOC__GIC__GICRLPI3 base address */
  #define NOC__GIC__GICRLPI3_BASE_NS               (0x480C0000u)
  /** Peripheral NOC__GIC__GICRLPI3 base pointer */
  #define NOC__GIC__GICRLPI3                       ((NOC_GICRlpi3_Type *)NOC__GIC__GICRLPI3_BASE)
  /** Peripheral NOC__GIC__GICRLPI3 base pointer */
  #define NOC__GIC__GICRLPI3_NS                    ((NOC_GICRlpi3_Type *)NOC__GIC__GICRLPI3_BASE_NS)
  /** Array initializer of NOC_GICRlpi3 peripheral base addresses */
  #define NOC_GICRlpi3_BASE_ADDRS                  { NOC__GIC__GICRLPI3_BASE }
  /** Array initializer of NOC_GICRlpi3 peripheral base pointers */
  #define NOC_GICRlpi3_BASE_PTRS                   { NOC__GIC__GICRLPI3 }
  /** Array initializer of NOC_GICRlpi3 peripheral base addresses */
  #define NOC_GICRlpi3_BASE_ADDRS_NS               { NOC__GIC__GICRLPI3_BASE_NS }
  /** Array initializer of NOC_GICRlpi3 peripheral base pointers */
  #define NOC_GICRlpi3_BASE_PTRS_NS                { NOC__GIC__GICRLPI3_NS }
#else
  /** Peripheral NOC__GIC__GICRLPI3 base address */
  #define NOC__GIC__GICRLPI3_BASE                  (0x480C0000u)
  /** Peripheral NOC__GIC__GICRLPI3 base pointer */
  #define NOC__GIC__GICRLPI3                       ((NOC_GICRlpi3_Type *)NOC__GIC__GICRLPI3_BASE)
  /** Array initializer of NOC_GICRlpi3 peripheral base addresses */
  #define NOC_GICRlpi3_BASE_ADDRS                  { NOC__GIC__GICRLPI3_BASE }
  /** Array initializer of NOC_GICRlpi3 peripheral base pointers */
  #define NOC_GICRlpi3_BASE_PTRS                   { NOC__GIC__GICRLPI3 }
#endif

/* NOC_GICRsgi0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICRSGI0 base address */
  #define NOC__GIC__GICRSGI0_BASE                  (0x58070000u)
  /** Peripheral NOC__GIC__GICRSGI0 base address */
  #define NOC__GIC__GICRSGI0_BASE_NS               (0x48070000u)
  /** Peripheral NOC__GIC__GICRSGI0 base pointer */
  #define NOC__GIC__GICRSGI0                       ((NOC_GICRsgi0_Type *)NOC__GIC__GICRSGI0_BASE)
  /** Peripheral NOC__GIC__GICRSGI0 base pointer */
  #define NOC__GIC__GICRSGI0_NS                    ((NOC_GICRsgi0_Type *)NOC__GIC__GICRSGI0_BASE_NS)
  /** Array initializer of NOC_GICRsgi0 peripheral base addresses */
  #define NOC_GICRsgi0_BASE_ADDRS                  { NOC__GIC__GICRSGI0_BASE }
  /** Array initializer of NOC_GICRsgi0 peripheral base pointers */
  #define NOC_GICRsgi0_BASE_PTRS                   { NOC__GIC__GICRSGI0 }
  /** Array initializer of NOC_GICRsgi0 peripheral base addresses */
  #define NOC_GICRsgi0_BASE_ADDRS_NS               { NOC__GIC__GICRSGI0_BASE_NS }
  /** Array initializer of NOC_GICRsgi0 peripheral base pointers */
  #define NOC_GICRsgi0_BASE_PTRS_NS                { NOC__GIC__GICRSGI0_NS }
#else
  /** Peripheral NOC__GIC__GICRSGI0 base address */
  #define NOC__GIC__GICRSGI0_BASE                  (0x48070000u)
  /** Peripheral NOC__GIC__GICRSGI0 base pointer */
  #define NOC__GIC__GICRSGI0                       ((NOC_GICRsgi0_Type *)NOC__GIC__GICRSGI0_BASE)
  /** Array initializer of NOC_GICRsgi0 peripheral base addresses */
  #define NOC_GICRsgi0_BASE_ADDRS                  { NOC__GIC__GICRSGI0_BASE }
  /** Array initializer of NOC_GICRsgi0 peripheral base pointers */
  #define NOC_GICRsgi0_BASE_PTRS                   { NOC__GIC__GICRSGI0 }
#endif

/* NOC_GICRsgi2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICRSGI2 base address */
  #define NOC__GIC__GICRSGI2_BASE                  (0x580B0000u)
  /** Peripheral NOC__GIC__GICRSGI2 base address */
  #define NOC__GIC__GICRSGI2_BASE_NS               (0x480B0000u)
  /** Peripheral NOC__GIC__GICRSGI2 base pointer */
  #define NOC__GIC__GICRSGI2                       ((NOC_GICRsgi2_Type *)NOC__GIC__GICRSGI2_BASE)
  /** Peripheral NOC__GIC__GICRSGI2 base pointer */
  #define NOC__GIC__GICRSGI2_NS                    ((NOC_GICRsgi2_Type *)NOC__GIC__GICRSGI2_BASE_NS)
  /** Array initializer of NOC_GICRsgi2 peripheral base addresses */
  #define NOC_GICRsgi2_BASE_ADDRS                  { NOC__GIC__GICRSGI2_BASE }
  /** Array initializer of NOC_GICRsgi2 peripheral base pointers */
  #define NOC_GICRsgi2_BASE_PTRS                   { NOC__GIC__GICRSGI2 }
  /** Array initializer of NOC_GICRsgi2 peripheral base addresses */
  #define NOC_GICRsgi2_BASE_ADDRS_NS               { NOC__GIC__GICRSGI2_BASE_NS }
  /** Array initializer of NOC_GICRsgi2 peripheral base pointers */
  #define NOC_GICRsgi2_BASE_PTRS_NS                { NOC__GIC__GICRSGI2_NS }
#else
  /** Peripheral NOC__GIC__GICRSGI2 base address */
  #define NOC__GIC__GICRSGI2_BASE                  (0x480B0000u)
  /** Peripheral NOC__GIC__GICRSGI2 base pointer */
  #define NOC__GIC__GICRSGI2                       ((NOC_GICRsgi2_Type *)NOC__GIC__GICRSGI2_BASE)
  /** Array initializer of NOC_GICRsgi2 peripheral base addresses */
  #define NOC_GICRsgi2_BASE_ADDRS                  { NOC__GIC__GICRSGI2_BASE }
  /** Array initializer of NOC_GICRsgi2 peripheral base pointers */
  #define NOC_GICRsgi2_BASE_PTRS                   { NOC__GIC__GICRSGI2 }
#endif

/* NOC_GICRsgi3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICRSGI3 base address */
  #define NOC__GIC__GICRSGI3_BASE                  (0x580D0000u)
  /** Peripheral NOC__GIC__GICRSGI3 base address */
  #define NOC__GIC__GICRSGI3_BASE_NS               (0x480D0000u)
  /** Peripheral NOC__GIC__GICRSGI3 base pointer */
  #define NOC__GIC__GICRSGI3                       ((NOC_GICRsgi3_Type *)NOC__GIC__GICRSGI3_BASE)
  /** Peripheral NOC__GIC__GICRSGI3 base pointer */
  #define NOC__GIC__GICRSGI3_NS                    ((NOC_GICRsgi3_Type *)NOC__GIC__GICRSGI3_BASE_NS)
  /** Array initializer of NOC_GICRsgi3 peripheral base addresses */
  #define NOC_GICRsgi3_BASE_ADDRS                  { NOC__GIC__GICRSGI3_BASE }
  /** Array initializer of NOC_GICRsgi3 peripheral base pointers */
  #define NOC_GICRsgi3_BASE_PTRS                   { NOC__GIC__GICRSGI3 }
  /** Array initializer of NOC_GICRsgi3 peripheral base addresses */
  #define NOC_GICRsgi3_BASE_ADDRS_NS               { NOC__GIC__GICRSGI3_BASE_NS }
  /** Array initializer of NOC_GICRsgi3 peripheral base pointers */
  #define NOC_GICRsgi3_BASE_PTRS_NS                { NOC__GIC__GICRSGI3_NS }
#else
  /** Peripheral NOC__GIC__GICRSGI3 base address */
  #define NOC__GIC__GICRSGI3_BASE                  (0x480D0000u)
  /** Peripheral NOC__GIC__GICRSGI3 base pointer */
  #define NOC__GIC__GICRSGI3                       ((NOC_GICRsgi3_Type *)NOC__GIC__GICRSGI3_BASE)
  /** Array initializer of NOC_GICRsgi3 peripheral base addresses */
  #define NOC_GICRsgi3_BASE_ADDRS                  { NOC__GIC__GICRSGI3_BASE }
  /** Array initializer of NOC_GICRsgi3 peripheral base pointers */
  #define NOC_GICRsgi3_BASE_PTRS                   { NOC__GIC__GICRSGI3 }
#endif

/* NOC_GICRsgil - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICRSGI1 base address */
  #define NOC__GIC__GICRSGI1_BASE                  (0x58090000u)
  /** Peripheral NOC__GIC__GICRSGI1 base address */
  #define NOC__GIC__GICRSGI1_BASE_NS               (0x48090000u)
  /** Peripheral NOC__GIC__GICRSGI1 base pointer */
  #define NOC__GIC__GICRSGI1                       ((NOC_GICRsgil_Type *)NOC__GIC__GICRSGI1_BASE)
  /** Peripheral NOC__GIC__GICRSGI1 base pointer */
  #define NOC__GIC__GICRSGI1_NS                    ((NOC_GICRsgil_Type *)NOC__GIC__GICRSGI1_BASE_NS)
  /** Array initializer of NOC_GICRsgil peripheral base addresses */
  #define NOC_GICRsgil_BASE_ADDRS                  { NOC__GIC__GICRSGI1_BASE }
  /** Array initializer of NOC_GICRsgil peripheral base pointers */
  #define NOC_GICRsgil_BASE_PTRS                   { NOC__GIC__GICRSGI1 }
  /** Array initializer of NOC_GICRsgil peripheral base addresses */
  #define NOC_GICRsgil_BASE_ADDRS_NS               { NOC__GIC__GICRSGI1_BASE_NS }
  /** Array initializer of NOC_GICRsgil peripheral base pointers */
  #define NOC_GICRsgil_BASE_PTRS_NS                { NOC__GIC__GICRSGI1_NS }
#else
  /** Peripheral NOC__GIC__GICRSGI1 base address */
  #define NOC__GIC__GICRSGI1_BASE                  (0x48090000u)
  /** Peripheral NOC__GIC__GICRSGI1 base pointer */
  #define NOC__GIC__GICRSGI1                       ((NOC_GICRsgil_Type *)NOC__GIC__GICRSGI1_BASE)
  /** Array initializer of NOC_GICRsgil peripheral base addresses */
  #define NOC_GICRsgil_BASE_ADDRS                  { NOC__GIC__GICRSGI1_BASE }
  /** Array initializer of NOC_GICRsgil peripheral base pointers */
  #define NOC_GICRsgil_BASE_PTRS                   { NOC__GIC__GICRSGI1 }
#endif

/* NOC_GICT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GICT base address */
  #define NOC__GIC__GICT_BASE                      (0x58020000u)
  /** Peripheral NOC__GIC__GICT base address */
  #define NOC__GIC__GICT_BASE_NS                   (0x48020000u)
  /** Peripheral NOC__GIC__GICT base pointer */
  #define NOC__GIC__GICT                           ((NOC_GICT_Type *)NOC__GIC__GICT_BASE)
  /** Peripheral NOC__GIC__GICT base pointer */
  #define NOC__GIC__GICT_NS                        ((NOC_GICT_Type *)NOC__GIC__GICT_BASE_NS)
  /** Array initializer of NOC_GICT peripheral base addresses */
  #define NOC_GICT_BASE_ADDRS                      { NOC__GIC__GICT_BASE }
  /** Array initializer of NOC_GICT peripheral base pointers */
  #define NOC_GICT_BASE_PTRS                       { NOC__GIC__GICT }
  /** Array initializer of NOC_GICT peripheral base addresses */
  #define NOC_GICT_BASE_ADDRS_NS                   { NOC__GIC__GICT_BASE_NS }
  /** Array initializer of NOC_GICT peripheral base pointers */
  #define NOC_GICT_BASE_PTRS_NS                    { NOC__GIC__GICT_NS }
#else
  /** Peripheral NOC__GIC__GICT base address */
  #define NOC__GIC__GICT_BASE                      (0x48020000u)
  /** Peripheral NOC__GIC__GICT base pointer */
  #define NOC__GIC__GICT                           ((NOC_GICT_Type *)NOC__GIC__GICT_BASE)
  /** Array initializer of NOC_GICT peripheral base addresses */
  #define NOC_GICT_BASE_ADDRS                      { NOC__GIC__GICT_BASE }
  /** Array initializer of NOC_GICT peripheral base pointers */
  #define NOC_GICT_BASE_PTRS                       { NOC__GIC__GICT }
#endif

/* NOC_GITS0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GITS0 base address */
  #define NOC__GIC__GITS0_BASE                     (0x58040000u)
  /** Peripheral NOC__GIC__GITS0 base address */
  #define NOC__GIC__GITS0_BASE_NS                  (0x48040000u)
  /** Peripheral NOC__GIC__GITS0 base pointer */
  #define NOC__GIC__GITS0                          ((NOC_GITS0_Type *)NOC__GIC__GITS0_BASE)
  /** Peripheral NOC__GIC__GITS0 base pointer */
  #define NOC__GIC__GITS0_NS                       ((NOC_GITS0_Type *)NOC__GIC__GITS0_BASE_NS)
  /** Array initializer of NOC_GITS0 peripheral base addresses */
  #define NOC_GITS0_BASE_ADDRS                     { NOC__GIC__GITS0_BASE }
  /** Array initializer of NOC_GITS0 peripheral base pointers */
  #define NOC_GITS0_BASE_PTRS                      { NOC__GIC__GITS0 }
  /** Array initializer of NOC_GITS0 peripheral base addresses */
  #define NOC_GITS0_BASE_ADDRS_NS                  { NOC__GIC__GITS0_BASE_NS }
  /** Array initializer of NOC_GITS0 peripheral base pointers */
  #define NOC_GITS0_BASE_PTRS_NS                   { NOC__GIC__GITS0_NS }
#else
  /** Peripheral NOC__GIC__GITS0 base address */
  #define NOC__GIC__GITS0_BASE                     (0x48040000u)
  /** Peripheral NOC__GIC__GITS0 base pointer */
  #define NOC__GIC__GITS0                          ((NOC_GITS0_Type *)NOC__GIC__GITS0_BASE)
  /** Array initializer of NOC_GITS0 peripheral base addresses */
  #define NOC_GITS0_BASE_ADDRS                     { NOC__GIC__GITS0_BASE }
  /** Array initializer of NOC_GITS0 peripheral base pointers */
  #define NOC_GITS0_BASE_PTRS                      { NOC__GIC__GITS0 }
#endif

/* NOC_GITS0translater - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GIC__GITS0TRANSLATER base address */
  #define NOC__GIC__GITS0TRANSLATER_BASE           (0x58050000u)
  /** Peripheral NOC__GIC__GITS0TRANSLATER base address */
  #define NOC__GIC__GITS0TRANSLATER_BASE_NS        (0x48050000u)
  /** Peripheral NOC__GIC__GITS0TRANSLATER base pointer */
  #define NOC__GIC__GITS0TRANSLATER                ((NOC_GITS0translater_Type *)NOC__GIC__GITS0TRANSLATER_BASE)
  /** Peripheral NOC__GIC__GITS0TRANSLATER base pointer */
  #define NOC__GIC__GITS0TRANSLATER_NS             ((NOC_GITS0translater_Type *)NOC__GIC__GITS0TRANSLATER_BASE_NS)
  /** Array initializer of NOC_GITS0translater peripheral base addresses */
  #define NOC_GITS0translater_BASE_ADDRS           { NOC__GIC__GITS0TRANSLATER_BASE }
  /** Array initializer of NOC_GITS0translater peripheral base pointers */
  #define NOC_GITS0translater_BASE_PTRS            { NOC__GIC__GITS0TRANSLATER }
  /** Array initializer of NOC_GITS0translater peripheral base addresses */
  #define NOC_GITS0translater_BASE_ADDRS_NS        { NOC__GIC__GITS0TRANSLATER_BASE_NS }
  /** Array initializer of NOC_GITS0translater peripheral base pointers */
  #define NOC_GITS0translater_BASE_PTRS_NS         { NOC__GIC__GITS0TRANSLATER_NS }
#else
  /** Peripheral NOC__GIC__GITS0TRANSLATER base address */
  #define NOC__GIC__GITS0TRANSLATER_BASE           (0x48050000u)
  /** Peripheral NOC__GIC__GITS0TRANSLATER base pointer */
  #define NOC__GIC__GITS0TRANSLATER                ((NOC_GITS0translater_Type *)NOC__GIC__GITS0TRANSLATER_BASE)
  /** Array initializer of NOC_GITS0translater peripheral base addresses */
  #define NOC_GITS0translater_BASE_ADDRS           { NOC__GIC__GITS0TRANSLATER_BASE }
  /** Array initializer of NOC_GITS0translater peripheral base pointers */
  #define NOC_GITS0translater_BASE_PTRS            { NOC__GIC__GITS0TRANSLATER }
#endif

/* NOC_I_LCDIF_rd_I_main_QosG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR base address */
  #define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE (0x5B151000u)
  /** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR base address */
  #define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE_NS (0x4B151000u)
  /** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR base pointer */
  #define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR ((NOC_I_LCDIF_rd_I_main_QosG_Type *)DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR base pointer */
  #define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_NS ((NOC_I_LCDIF_rd_I_main_QosG_Type *)DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_I_LCDIF_rd_I_main_QosG peripheral base addresses */
  #define NOC_I_LCDIF_rd_I_main_QosG_BASE_ADDRS    { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_I_LCDIF_rd_I_main_QosG peripheral base pointers */
  #define NOC_I_LCDIF_rd_I_main_QosG_BASE_PTRS     { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_I_LCDIF_rd_I_main_QosG peripheral base addresses */
  #define NOC_I_LCDIF_rd_I_main_QosG_BASE_ADDRS_NS { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_I_LCDIF_rd_I_main_QosG peripheral base pointers */
  #define NOC_I_LCDIF_rd_I_main_QosG_BASE_PTRS_NS  { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR base address */
  #define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE (0x4B151000u)
  /** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR base pointer */
  #define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR ((NOC_I_LCDIF_rd_I_main_QosG_Type *)DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_I_LCDIF_rd_I_main_QosG peripheral base addresses */
  #define NOC_I_LCDIF_rd_I_main_QosG_BASE_ADDRS    { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_I_LCDIF_rd_I_main_QosG peripheral base pointers */
  #define NOC_I_LCDIF_rd_I_main_QosG_BASE_PTRS     { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_QOSGENERATOR }
#endif

/* NOC_I_LCDIF_rd_I_main_TranStatFltr - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER base
   * address */
  #define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x5B151180u)
  /** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER base
   * address */
  #define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x4B151180u)
  /** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER base
   * pointer */
  #define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_I_LCDIF_rd_I_main_TranStatFltr_Type *)DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER base
   * pointer */
  #define DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER_NS ((NOC_I_LCDIF_rd_I_main_TranStatFltr_Type *)DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of NOC_I_LCDIF_rd_I_main_TranStatFltr peripheral base
   * addresses */
  #define NOC_I_LCDIF_rd_I_main_TranStatFltr_BASE_ADDRS { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of NOC_I_LCDIF_rd_I_main_TranStatFltr peripheral base
   * pointers */
  #define NOC_I_LCDIF_rd_I_main_TranStatFltr_BASE_PTRS { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of NOC_I_LCDIF_rd_I_main_TranStatFltr peripheral base
   * addresses */
  #define NOC_I_LCDIF_rd_I_main_TranStatFltr_BASE_ADDRS_NS { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of NOC_I_LCDIF_rd_I_main_TranStatFltr peripheral base
   * pointers */
  #define NOC_I_LCDIF_rd_I_main_TranStatFltr_BASE_PTRS_NS { DISPLAY__GPV__I_LCDIF_RD_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* NOC_I_PXP_rd_I_main_QosG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR base address */
  #define DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE (0x5B151080u)
  /** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR base address */
  #define DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE_NS (0x4B151080u)
  /** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR base pointer */
  #define DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR ((NOC_I_PXP_rd_I_main_QosG_Type *)DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR base pointer */
  #define DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_NS ((NOC_I_PXP_rd_I_main_QosG_Type *)DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_I_PXP_rd_I_main_QosG peripheral base addresses */
  #define NOC_I_PXP_rd_I_main_QosG_BASE_ADDRS      { DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_I_PXP_rd_I_main_QosG peripheral base pointers */
  #define NOC_I_PXP_rd_I_main_QosG_BASE_PTRS       { DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_I_PXP_rd_I_main_QosG peripheral base addresses */
  #define NOC_I_PXP_rd_I_main_QosG_BASE_ADDRS_NS   { DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_I_PXP_rd_I_main_QosG peripheral base pointers */
  #define NOC_I_PXP_rd_I_main_QosG_BASE_PTRS_NS    { DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR base address */
  #define DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE (0x4B151080u)
  /** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR base pointer */
  #define DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR ((NOC_I_PXP_rd_I_main_QosG_Type *)DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_I_PXP_rd_I_main_QosG peripheral base addresses */
  #define NOC_I_PXP_rd_I_main_QosG_BASE_ADDRS      { DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_I_PXP_rd_I_main_QosG peripheral base pointers */
  #define NOC_I_PXP_rd_I_main_QosG_BASE_PTRS       { DISPLAY__GPV__I_PXP_RD_I_MAIN_QOSGENERATOR }
#endif

/* NOC_I_PXP_rd_I_main_TranStatFltr - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER base address
   * */
  #define DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x5B151200u)
  /** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER base address
   * */
  #define DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x4B151200u)
  /** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer
   * */
  #define DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_I_PXP_rd_I_main_TranStatFltr_Type *)DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer
   * */
  #define DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER_NS ((NOC_I_PXP_rd_I_main_TranStatFltr_Type *)DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of NOC_I_PXP_rd_I_main_TranStatFltr peripheral base
   * addresses */
  #define NOC_I_PXP_rd_I_main_TranStatFltr_BASE_ADDRS { DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of NOC_I_PXP_rd_I_main_TranStatFltr peripheral base
   * pointers */
  #define NOC_I_PXP_rd_I_main_TranStatFltr_BASE_PTRS { DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of NOC_I_PXP_rd_I_main_TranStatFltr peripheral base
   * addresses */
  #define NOC_I_PXP_rd_I_main_TranStatFltr_BASE_ADDRS_NS { DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of NOC_I_PXP_rd_I_main_TranStatFltr peripheral base
   * pointers */
  #define NOC_I_PXP_rd_I_main_TranStatFltr_BASE_PTRS_NS { DISPLAY__GPV__I_PXP_RD_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* NOC_I_PXP_wr_I_main_QosG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR base address */
  #define DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE (0x5B151100u)
  /** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR base address */
  #define DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE_NS (0x4B151100u)
  /** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR base pointer */
  #define DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR ((NOC_I_PXP_wr_I_main_QosG_Type *)DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR base pointer */
  #define DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_NS ((NOC_I_PXP_wr_I_main_QosG_Type *)DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_I_PXP_wr_I_main_QosG peripheral base addresses */
  #define NOC_I_PXP_wr_I_main_QosG_BASE_ADDRS      { DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_I_PXP_wr_I_main_QosG peripheral base pointers */
  #define NOC_I_PXP_wr_I_main_QosG_BASE_PTRS       { DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_I_PXP_wr_I_main_QosG peripheral base addresses */
  #define NOC_I_PXP_wr_I_main_QosG_BASE_ADDRS_NS   { DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_I_PXP_wr_I_main_QosG peripheral base pointers */
  #define NOC_I_PXP_wr_I_main_QosG_BASE_PTRS_NS    { DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR base address */
  #define DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE (0x4B151100u)
  /** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR base pointer */
  #define DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR ((NOC_I_PXP_wr_I_main_QosG_Type *)DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_I_PXP_wr_I_main_QosG peripheral base addresses */
  #define NOC_I_PXP_wr_I_main_QosG_BASE_ADDRS      { DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_I_PXP_wr_I_main_QosG peripheral base pointers */
  #define NOC_I_PXP_wr_I_main_QosG_BASE_PTRS       { DISPLAY__GPV__I_PXP_WR_I_MAIN_QOSGENERATOR }
#endif

/* NOC_I_PXP_wr_I_main_TranStatFltr - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER base address
   * */
  #define DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x5B151280u)
  /** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER base address
   * */
  #define DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x4B151280u)
  /** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer
   * */
  #define DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER ((NOC_I_PXP_wr_I_main_TranStatFltr_Type *)DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer
   * */
  #define DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER_NS ((NOC_I_PXP_wr_I_main_TranStatFltr_Type *)DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of NOC_I_PXP_wr_I_main_TranStatFltr peripheral base
   * addresses */
  #define NOC_I_PXP_wr_I_main_TranStatFltr_BASE_ADDRS { DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of NOC_I_PXP_wr_I_main_TranStatFltr peripheral base
   * pointers */
  #define NOC_I_PXP_wr_I_main_TranStatFltr_BASE_PTRS { DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of NOC_I_PXP_wr_I_main_TranStatFltr peripheral base
   * addresses */
  #define NOC_I_PXP_wr_I_main_TranStatFltr_BASE_ADDRS_NS { DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of NOC_I_PXP_wr_I_main_TranStatFltr peripheral base
   * pointers */
  #define NOC_I_PXP_wr_I_main_TranStatFltr_BASE_PTRS_NS { DISPLAY__GPV__I_PXP_WR_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* NOC_LSTCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__LSTCUN base address */
  #define NOC__LSTCUN_BASE                         (0x590B0000u)
  /** Peripheral NOC__LSTCUN base address */
  #define NOC__LSTCUN_BASE_NS                      (0x490B0000u)
  /** Peripheral NOC__LSTCUN base pointer */
  #define NOC__LSTCUN                              ((NOC_LSTCU_Type *)NOC__LSTCUN_BASE)
  /** Peripheral NOC__LSTCUN base pointer */
  #define NOC__LSTCUN_NS                           ((NOC_LSTCU_Type *)NOC__LSTCUN_BASE_NS)
  /** Array initializer of NOC_LSTCU peripheral base addresses */
  #define NOC_LSTCU_BASE_ADDRS                     { NOC__LSTCUN_BASE }
  /** Array initializer of NOC_LSTCU peripheral base pointers */
  #define NOC_LSTCU_BASE_PTRS                      { NOC__LSTCUN }
  /** Array initializer of NOC_LSTCU peripheral base addresses */
  #define NOC_LSTCU_BASE_ADDRS_NS                  { NOC__LSTCUN_BASE_NS }
  /** Array initializer of NOC_LSTCU peripheral base pointers */
  #define NOC_LSTCU_BASE_PTRS_NS                   { NOC__LSTCUN_NS }
#else
  /** Peripheral NOC__LSTCUN base address */
  #define NOC__LSTCUN_BASE                         (0x490B0000u)
  /** Peripheral NOC__LSTCUN base pointer */
  #define NOC__LSTCUN                              ((NOC_LSTCU_Type *)NOC__LSTCUN_BASE)
  /** Array initializer of NOC_LSTCU peripheral base addresses */
  #define NOC_LSTCU_BASE_ADDRS                     { NOC__LSTCUN_BASE }
  /** Array initializer of NOC_LSTCU peripheral base pointers */
  #define NOC_LSTCU_BASE_PTRS                      { NOC__LSTCUN }
#endif

/* NOC_Probe_LCDIF_rd_main_Probe - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE base address */
  #define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE_BASE (0x5B150400u)
  /** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE base address */
  #define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE_BASE_NS (0x4B150400u)
  /** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE base pointer */
  #define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE  ((NOC_Probe_LCDIF_rd_main_Probe_Type *)DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE_BASE)
  /** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE base pointer */
  #define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE_NS ((NOC_Probe_LCDIF_rd_main_Probe_Type *)DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE_BASE_NS)
  /** Array initializer of NOC_Probe_LCDIF_rd_main_Probe peripheral base addresses
   * */
  #define NOC_Probe_LCDIF_rd_main_Probe_BASE_ADDRS { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_LCDIF_rd_main_Probe peripheral base pointers
   * */
  #define NOC_Probe_LCDIF_rd_main_Probe_BASE_PTRS  { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE }
  /** Array initializer of NOC_Probe_LCDIF_rd_main_Probe peripheral base addresses
   * */
  #define NOC_Probe_LCDIF_rd_main_Probe_BASE_ADDRS_NS { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE_BASE_NS }
  /** Array initializer of NOC_Probe_LCDIF_rd_main_Probe peripheral base pointers
   * */
  #define NOC_Probe_LCDIF_rd_main_Probe_BASE_PTRS_NS { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_PROBE_NS }
#else
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
#endif

/* NOC_Probe_LCDIF_rd_main_TrStProf - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER base
   * address */
  #define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER_BASE (0x5B151300u)
  /** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER base
   * address */
  #define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER_BASE_NS (0x4B151300u)
  /** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER base
   * pointer */
  #define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_LCDIF_rd_main_TrStProf_Type *)DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER_BASE)
  /** Peripheral DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER base
   * pointer */
  #define DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER_NS ((NOC_Probe_LCDIF_rd_main_TrStProf_Type *)DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER_BASE_NS)
  /** Array initializer of NOC_Probe_LCDIF_rd_main_TrStProf peripheral base
   * addresses */
  #define NOC_Probe_LCDIF_rd_main_TrStProf_BASE_ADDRS { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER_BASE }
  /** Array initializer of NOC_Probe_LCDIF_rd_main_TrStProf peripheral base
   * pointers */
  #define NOC_Probe_LCDIF_rd_main_TrStProf_BASE_PTRS { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER }
  /** Array initializer of NOC_Probe_LCDIF_rd_main_TrStProf peripheral base
   * addresses */
  #define NOC_Probe_LCDIF_rd_main_TrStProf_BASE_ADDRS_NS { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER_BASE_NS }
  /** Array initializer of NOC_Probe_LCDIF_rd_main_TrStProf peripheral base
   * pointers */
  #define NOC_Probe_LCDIF_rd_main_TrStProf_BASE_PTRS_NS { DISPLAY__GPV__PROBE_LCDIF_RD_MAIN_TRANSACTIONSTATPROFILER_NS }
#else
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
#endif

/* NOC_Probe_PXP_rd_main_Probe - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE base address */
  #define DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE (0x5B150800u)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE base address */
  #define DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE_NS (0x4B150800u)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE base pointer */
  #define DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE    ((NOC_Probe_PXP_rd_main_Probe_Type *)DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE base pointer */
  #define DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_NS ((NOC_Probe_PXP_rd_main_Probe_Type *)DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE_NS)
  /** Array initializer of NOC_Probe_PXP_rd_main_Probe peripheral base addresses */
  #define NOC_Probe_PXP_rd_main_Probe_BASE_ADDRS   { DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_PXP_rd_main_Probe peripheral base pointers */
  #define NOC_Probe_PXP_rd_main_Probe_BASE_PTRS    { DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE }
  /** Array initializer of NOC_Probe_PXP_rd_main_Probe peripheral base addresses */
  #define NOC_Probe_PXP_rd_main_Probe_BASE_ADDRS_NS { DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE_NS }
  /** Array initializer of NOC_Probe_PXP_rd_main_Probe peripheral base pointers */
  #define NOC_Probe_PXP_rd_main_Probe_BASE_PTRS_NS { DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_NS }
#else
  /** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE base address */
  #define DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE (0x4B150800u)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE base pointer */
  #define DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE    ((NOC_Probe_PXP_rd_main_Probe_Type *)DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE)
  /** Array initializer of NOC_Probe_PXP_rd_main_Probe peripheral base addresses */
  #define NOC_Probe_PXP_rd_main_Probe_BASE_ADDRS   { DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_PXP_rd_main_Probe peripheral base pointers */
  #define NOC_Probe_PXP_rd_main_Probe_BASE_PTRS    { DISPLAY__GPV__PROBE_PXP_RD_MAIN_PROBE }
#endif

/* NOC_Probe_PXP_rd_main_TrStProf - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER base
   * address */
  #define DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER_BASE (0x5B151380u)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER base
   * address */
  #define DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER_BASE_NS (0x4B151380u)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER base
   * pointer */
  #define DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_PXP_rd_main_TrStProf_Type *)DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER_BASE)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER base
   * pointer */
  #define DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER_NS ((NOC_Probe_PXP_rd_main_TrStProf_Type *)DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER_BASE_NS)
  /** Array initializer of NOC_Probe_PXP_rd_main_TrStProf peripheral base
   * addresses */
  #define NOC_Probe_PXP_rd_main_TrStProf_BASE_ADDRS { DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER_BASE }
  /** Array initializer of NOC_Probe_PXP_rd_main_TrStProf peripheral base pointers
   * */
  #define NOC_Probe_PXP_rd_main_TrStProf_BASE_PTRS { DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER }
  /** Array initializer of NOC_Probe_PXP_rd_main_TrStProf peripheral base
   * addresses */
  #define NOC_Probe_PXP_rd_main_TrStProf_BASE_ADDRS_NS { DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER_BASE_NS }
  /** Array initializer of NOC_Probe_PXP_rd_main_TrStProf peripheral base pointers
   * */
  #define NOC_Probe_PXP_rd_main_TrStProf_BASE_PTRS_NS { DISPLAY__GPV__PROBE_PXP_RD_MAIN_TRANSACTIONSTATPROFILER_NS }
#else
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
#endif

/* NOC_Probe_PXP_wr_main_Probe - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE base address */
  #define DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE (0x5B150C00u)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE base address */
  #define DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE_NS (0x4B150C00u)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE base pointer */
  #define DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE    ((NOC_Probe_PXP_wr_main_Probe_Type *)DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE base pointer */
  #define DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_NS ((NOC_Probe_PXP_wr_main_Probe_Type *)DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE_NS)
  /** Array initializer of NOC_Probe_PXP_wr_main_Probe peripheral base addresses */
  #define NOC_Probe_PXP_wr_main_Probe_BASE_ADDRS   { DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_PXP_wr_main_Probe peripheral base pointers */
  #define NOC_Probe_PXP_wr_main_Probe_BASE_PTRS    { DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE }
  /** Array initializer of NOC_Probe_PXP_wr_main_Probe peripheral base addresses */
  #define NOC_Probe_PXP_wr_main_Probe_BASE_ADDRS_NS { DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE_NS }
  /** Array initializer of NOC_Probe_PXP_wr_main_Probe peripheral base pointers */
  #define NOC_Probe_PXP_wr_main_Probe_BASE_PTRS_NS { DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_NS }
#else
  /** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE base address */
  #define DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE (0x4B150C00u)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE base pointer */
  #define DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE    ((NOC_Probe_PXP_wr_main_Probe_Type *)DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE)
  /** Array initializer of NOC_Probe_PXP_wr_main_Probe peripheral base addresses */
  #define NOC_Probe_PXP_wr_main_Probe_BASE_ADDRS   { DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_PXP_wr_main_Probe peripheral base pointers */
  #define NOC_Probe_PXP_wr_main_Probe_BASE_PTRS    { DISPLAY__GPV__PROBE_PXP_WR_MAIN_PROBE }
#endif

/* NOC_Probe_PXP_wr_main_TrStProf - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER base
   * address */
  #define DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER_BASE (0x5B151400u)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER base
   * address */
  #define DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER_BASE_NS (0x4B151400u)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER base
   * pointer */
  #define DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_PXP_wr_main_TrStProf_Type *)DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER_BASE)
  /** Peripheral DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER base
   * pointer */
  #define DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER_NS ((NOC_Probe_PXP_wr_main_TrStProf_Type *)DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER_BASE_NS)
  /** Array initializer of NOC_Probe_PXP_wr_main_TrStProf peripheral base
   * addresses */
  #define NOC_Probe_PXP_wr_main_TrStProf_BASE_ADDRS { DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER_BASE }
  /** Array initializer of NOC_Probe_PXP_wr_main_TrStProf peripheral base pointers
   * */
  #define NOC_Probe_PXP_wr_main_TrStProf_BASE_PTRS { DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER }
  /** Array initializer of NOC_Probe_PXP_wr_main_TrStProf peripheral base
   * addresses */
  #define NOC_Probe_PXP_wr_main_TrStProf_BASE_ADDRS_NS { DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER_BASE_NS }
  /** Array initializer of NOC_Probe_PXP_wr_main_TrStProf peripheral base pointers
   * */
  #define NOC_Probe_PXP_wr_main_TrStProf_BASE_PTRS_NS { DISPLAY__GPV__PROBE_PXP_WR_MAIN_TRANSACTIONSTATPROFILER_NS }
#else
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
#endif

/* NOC_Probe_m_e_0_main_Probe - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE    (0x59060000u)
  /** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE_NS (0x49060000u)
  /** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_0_MAIN_PROBE         ((NOC_Probe_m_e_0_main_Probe_Type *)NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE)
  /** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_0_MAIN_PROBE_NS      ((NOC_Probe_m_e_0_main_Probe_Type *)NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE_NS)
  /** Array initializer of NOC_Probe_m_e_0_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_0_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_m_e_0_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_0_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_0_MAIN_PROBE }
  /** Array initializer of NOC_Probe_m_e_0_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_0_main_Probe_BASE_ADDRS_NS { NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE_NS }
  /** Array initializer of NOC_Probe_m_e_0_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_0_main_Probe_BASE_PTRS_NS  { NOC__GPV__PROBE_M_E_0_MAIN_PROBE_NS }
#else
  /** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE    (0x49060000u)
  /** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_0_MAIN_PROBE         ((NOC_Probe_m_e_0_main_Probe_Type *)NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE)
  /** Array initializer of NOC_Probe_m_e_0_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_0_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_0_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_m_e_0_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_0_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_0_MAIN_PROBE }
#endif

/* NOC_Probe_m_e_0_main_TranStatProf - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER base address */
  #define NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER_BASE (0x59063980u)
  /** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER base address */
  #define NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER_BASE_NS (0x49063980u)
  /** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER base pointer */
  #define NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_m_e_0_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER_BASE)
  /** Peripheral NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER base pointer */
  #define NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER_NS ((NOC_Probe_m_e_0_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER_BASE_NS)
  /** Array initializer of NOC_Probe_m_e_0_main_TranStatProf peripheral base
   * addresses */
  #define NOC_Probe_m_e_0_main_TranStatProf_BASE_ADDRS { NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER_BASE }
  /** Array initializer of NOC_Probe_m_e_0_main_TranStatProf peripheral base
   * pointers */
  #define NOC_Probe_m_e_0_main_TranStatProf_BASE_PTRS { NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER }
  /** Array initializer of NOC_Probe_m_e_0_main_TranStatProf peripheral base
   * addresses */
  #define NOC_Probe_m_e_0_main_TranStatProf_BASE_ADDRS_NS { NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER_BASE_NS }
  /** Array initializer of NOC_Probe_m_e_0_main_TranStatProf peripheral base
   * pointers */
  #define NOC_Probe_m_e_0_main_TranStatProf_BASE_PTRS_NS { NOC__GPV__PROBE_M_E_0_MAIN_TRANSACTIONSTATPROFILER_NS }
#else
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
#endif

/* NOC_Probe_m_e_3_main_Probe - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE    (0x59060400u)
  /** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE_NS (0x49060400u)
  /** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_3_MAIN_PROBE         ((NOC_Probe_m_e_3_main_Probe_Type *)NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE)
  /** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_3_MAIN_PROBE_NS      ((NOC_Probe_m_e_3_main_Probe_Type *)NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE_NS)
  /** Array initializer of NOC_Probe_m_e_3_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_3_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_m_e_3_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_3_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_3_MAIN_PROBE }
  /** Array initializer of NOC_Probe_m_e_3_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_3_main_Probe_BASE_ADDRS_NS { NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE_NS }
  /** Array initializer of NOC_Probe_m_e_3_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_3_main_Probe_BASE_PTRS_NS  { NOC__GPV__PROBE_M_E_3_MAIN_PROBE_NS }
#else
  /** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE    (0x49060400u)
  /** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_3_MAIN_PROBE         ((NOC_Probe_m_e_3_main_Probe_Type *)NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE)
  /** Array initializer of NOC_Probe_m_e_3_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_3_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_3_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_m_e_3_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_3_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_3_MAIN_PROBE }
#endif

/* NOC_Probe_m_e_3_main_TranStatProf - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER base address */
  #define NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER_BASE (0x59063A00u)
  /** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER base address */
  #define NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER_BASE_NS (0x49063A00u)
  /** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER base pointer */
  #define NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_m_e_3_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER_BASE)
  /** Peripheral NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER base pointer */
  #define NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER_NS ((NOC_Probe_m_e_3_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER_BASE_NS)
  /** Array initializer of NOC_Probe_m_e_3_main_TranStatProf peripheral base
   * addresses */
  #define NOC_Probe_m_e_3_main_TranStatProf_BASE_ADDRS { NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER_BASE }
  /** Array initializer of NOC_Probe_m_e_3_main_TranStatProf peripheral base
   * pointers */
  #define NOC_Probe_m_e_3_main_TranStatProf_BASE_PTRS { NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER }
  /** Array initializer of NOC_Probe_m_e_3_main_TranStatProf peripheral base
   * addresses */
  #define NOC_Probe_m_e_3_main_TranStatProf_BASE_ADDRS_NS { NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER_BASE_NS }
  /** Array initializer of NOC_Probe_m_e_3_main_TranStatProf peripheral base
   * pointers */
  #define NOC_Probe_m_e_3_main_TranStatProf_BASE_PTRS_NS { NOC__GPV__PROBE_M_E_3_MAIN_TRANSACTIONSTATPROFILER_NS }
#else
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
#endif

/* NOC_Probe_m_e_6_main_Probe - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE    (0x59061000u)
  /** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE_NS (0x49061000u)
  /** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_6_MAIN_PROBE         ((NOC_Probe_m_e_6_main_Probe_Type *)NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE)
  /** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_6_MAIN_PROBE_NS      ((NOC_Probe_m_e_6_main_Probe_Type *)NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE_NS)
  /** Array initializer of NOC_Probe_m_e_6_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_6_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_m_e_6_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_6_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_6_MAIN_PROBE }
  /** Array initializer of NOC_Probe_m_e_6_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_6_main_Probe_BASE_ADDRS_NS { NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE_NS }
  /** Array initializer of NOC_Probe_m_e_6_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_6_main_Probe_BASE_PTRS_NS  { NOC__GPV__PROBE_M_E_6_MAIN_PROBE_NS }
#else
  /** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE    (0x49061000u)
  /** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_6_MAIN_PROBE         ((NOC_Probe_m_e_6_main_Probe_Type *)NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE)
  /** Array initializer of NOC_Probe_m_e_6_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_6_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_6_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_m_e_6_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_6_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_6_MAIN_PROBE }
#endif

/* NOC_Probe_m_e_6_main_TranStatProf - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER base address */
  #define NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER_BASE (0x59063B80u)
  /** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER base address */
  #define NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER_BASE_NS (0x49063B80u)
  /** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER base pointer */
  #define NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_m_e_6_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER_BASE)
  /** Peripheral NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER base pointer */
  #define NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER_NS ((NOC_Probe_m_e_6_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER_BASE_NS)
  /** Array initializer of NOC_Probe_m_e_6_main_TranStatProf peripheral base
   * addresses */
  #define NOC_Probe_m_e_6_main_TranStatProf_BASE_ADDRS { NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER_BASE }
  /** Array initializer of NOC_Probe_m_e_6_main_TranStatProf peripheral base
   * pointers */
  #define NOC_Probe_m_e_6_main_TranStatProf_BASE_PTRS { NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER }
  /** Array initializer of NOC_Probe_m_e_6_main_TranStatProf peripheral base
   * addresses */
  #define NOC_Probe_m_e_6_main_TranStatProf_BASE_ADDRS_NS { NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER_BASE_NS }
  /** Array initializer of NOC_Probe_m_e_6_main_TranStatProf peripheral base
   * pointers */
  #define NOC_Probe_m_e_6_main_TranStatProf_BASE_PTRS_NS { NOC__GPV__PROBE_M_E_6_MAIN_TRANSACTIONSTATPROFILER_NS }
#else
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
#endif

/* NOC_Probe_m_e_7_main_Probe - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE    (0x59061400u)
  /** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE_NS (0x49061400u)
  /** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_7_MAIN_PROBE         ((NOC_Probe_m_e_7_main_Probe_Type *)NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE)
  /** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_7_MAIN_PROBE_NS      ((NOC_Probe_m_e_7_main_Probe_Type *)NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE_NS)
  /** Array initializer of NOC_Probe_m_e_7_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_7_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_m_e_7_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_7_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_7_MAIN_PROBE }
  /** Array initializer of NOC_Probe_m_e_7_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_7_main_Probe_BASE_ADDRS_NS { NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE_NS }
  /** Array initializer of NOC_Probe_m_e_7_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_7_main_Probe_BASE_PTRS_NS  { NOC__GPV__PROBE_M_E_7_MAIN_PROBE_NS }
#else
  /** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE    (0x49061400u)
  /** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_7_MAIN_PROBE         ((NOC_Probe_m_e_7_main_Probe_Type *)NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE)
  /** Array initializer of NOC_Probe_m_e_7_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_7_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_7_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_m_e_7_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_7_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_7_MAIN_PROBE }
#endif

/* NOC_Probe_m_e_7_main_TranStatProf - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER base address */
  #define NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER_BASE (0x59063C00u)
  /** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER base address */
  #define NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER_BASE_NS (0x49063C00u)
  /** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER base pointer */
  #define NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_m_e_7_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER_BASE)
  /** Peripheral NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER base pointer */
  #define NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER_NS ((NOC_Probe_m_e_7_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER_BASE_NS)
  /** Array initializer of NOC_Probe_m_e_7_main_TranStatProf peripheral base
   * addresses */
  #define NOC_Probe_m_e_7_main_TranStatProf_BASE_ADDRS { NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER_BASE }
  /** Array initializer of NOC_Probe_m_e_7_main_TranStatProf peripheral base
   * pointers */
  #define NOC_Probe_m_e_7_main_TranStatProf_BASE_PTRS { NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER }
  /** Array initializer of NOC_Probe_m_e_7_main_TranStatProf peripheral base
   * addresses */
  #define NOC_Probe_m_e_7_main_TranStatProf_BASE_ADDRS_NS { NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER_BASE_NS }
  /** Array initializer of NOC_Probe_m_e_7_main_TranStatProf peripheral base
   * pointers */
  #define NOC_Probe_m_e_7_main_TranStatProf_BASE_PTRS_NS { NOC__GPV__PROBE_M_E_7_MAIN_TRANSACTIONSTATPROFILER_NS }
#else
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
#endif

/* NOC_Probe_m_e_9_main_Probe - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE    (0x59061800u)
  /** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE_NS (0x49061800u)
  /** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_9_MAIN_PROBE         ((NOC_Probe_m_e_9_main_Probe_Type *)NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE)
  /** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_9_MAIN_PROBE_NS      ((NOC_Probe_m_e_9_main_Probe_Type *)NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE_NS)
  /** Array initializer of NOC_Probe_m_e_9_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_9_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_m_e_9_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_9_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_9_MAIN_PROBE }
  /** Array initializer of NOC_Probe_m_e_9_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_9_main_Probe_BASE_ADDRS_NS { NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE_NS }
  /** Array initializer of NOC_Probe_m_e_9_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_9_main_Probe_BASE_PTRS_NS  { NOC__GPV__PROBE_M_E_9_MAIN_PROBE_NS }
#else
  /** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_PROBE base address */
  #define NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE    (0x49061800u)
  /** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_PROBE base pointer */
  #define NOC__GPV__PROBE_M_E_9_MAIN_PROBE         ((NOC_Probe_m_e_9_main_Probe_Type *)NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE)
  /** Array initializer of NOC_Probe_m_e_9_main_Probe peripheral base addresses */
  #define NOC_Probe_m_e_9_main_Probe_BASE_ADDRS    { NOC__GPV__PROBE_M_E_9_MAIN_PROBE_BASE }
  /** Array initializer of NOC_Probe_m_e_9_main_Probe peripheral base pointers */
  #define NOC_Probe_m_e_9_main_Probe_BASE_PTRS     { NOC__GPV__PROBE_M_E_9_MAIN_PROBE }
#endif

/* NOC_Probe_m_e_9_main_TranStatProf - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER base address */
  #define NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER_BASE (0x59063C80u)
  /** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER base address */
  #define NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER_BASE_NS (0x49063C80u)
  /** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER base pointer */
  #define NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER ((NOC_Probe_m_e_9_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER_BASE)
  /** Peripheral NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER base pointer */
  #define NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER_NS ((NOC_Probe_m_e_9_main_TranStatProf_Type *)NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER_BASE_NS)
  /** Array initializer of NOC_Probe_m_e_9_main_TranStatProf peripheral base
   * addresses */
  #define NOC_Probe_m_e_9_main_TranStatProf_BASE_ADDRS { NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER_BASE }
  /** Array initializer of NOC_Probe_m_e_9_main_TranStatProf peripheral base
   * pointers */
  #define NOC_Probe_m_e_9_main_TranStatProf_BASE_PTRS { NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER }
  /** Array initializer of NOC_Probe_m_e_9_main_TranStatProf peripheral base
   * addresses */
  #define NOC_Probe_m_e_9_main_TranStatProf_BASE_ADDRS_NS { NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER_BASE_NS }
  /** Array initializer of NOC_Probe_m_e_9_main_TranStatProf peripheral base
   * pointers */
  #define NOC_Probe_m_e_9_main_TranStatProf_BASE_PTRS_NS { NOC__GPV__PROBE_M_E_9_MAIN_TRANSACTIONSTATPROFILER_NS }
#else
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
#endif

/* NOC_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__TCU base address */
  #define NOC__TCU_BASE                            (0x59040000u)
  /** Peripheral NOC__TCU base address */
  #define NOC__TCU_BASE_NS                         (0x49040000u)
  /** Peripheral NOC__TCU base pointer */
  #define NOC__TCU                                 ((NOC_TCU_Type *)NOC__TCU_BASE)
  /** Peripheral NOC__TCU base pointer */
  #define NOC__TCU_NS                              ((NOC_TCU_Type *)NOC__TCU_BASE_NS)
  /** Array initializer of NOC_TCU peripheral base addresses */
  #define NOC_TCU_BASE_ADDRS                       { NOC__TCU_BASE }
  /** Array initializer of NOC_TCU peripheral base pointers */
  #define NOC_TCU_BASE_PTRS                        { NOC__TCU }
  /** Array initializer of NOC_TCU peripheral base addresses */
  #define NOC_TCU_BASE_ADDRS_NS                    { NOC__TCU_BASE_NS }
  /** Array initializer of NOC_TCU peripheral base pointers */
  #define NOC_TCU_BASE_PTRS_NS                     { NOC__TCU_NS }
#else
  /** Peripheral NOC__TCU base address */
  #define NOC__TCU_BASE                            (0x49040000u)
  /** Peripheral NOC__TCU base pointer */
  #define NOC__TCU                                 ((NOC_TCU_Type *)NOC__TCU_BASE)
  /** Array initializer of NOC_TCU peripheral base addresses */
  #define NOC_TCU_BASE_ADDRS                       { NOC__TCU_BASE }
  /** Array initializer of NOC_TCU peripheral base pointers */
  #define NOC_TCU_BASE_PTRS                        { NOC__TCU }
#endif

/* NOC_TRDC_MGR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__TRDC_MGRN base address */
  #define NOC__TRDC_MGRN_BASE                      (0x59010000u)
  /** Peripheral NOC__TRDC_MGRN base address */
  #define NOC__TRDC_MGRN_BASE_NS                   (0x49010000u)
  /** Peripheral NOC__TRDC_MGRN base pointer */
  #define NOC__TRDC_MGRN                           ((NOC_TRDC_MGR_Type *)NOC__TRDC_MGRN_BASE)
  /** Peripheral NOC__TRDC_MGRN base pointer */
  #define NOC__TRDC_MGRN_NS                        ((NOC_TRDC_MGR_Type *)NOC__TRDC_MGRN_BASE_NS)
  /** Array initializer of NOC_TRDC_MGR peripheral base addresses */
  #define NOC_TRDC_MGR_BASE_ADDRS                  { NOC__TRDC_MGRN_BASE }
  /** Array initializer of NOC_TRDC_MGR peripheral base pointers */
  #define NOC_TRDC_MGR_BASE_PTRS                   { NOC__TRDC_MGRN }
  /** Array initializer of NOC_TRDC_MGR peripheral base addresses */
  #define NOC_TRDC_MGR_BASE_ADDRS_NS               { NOC__TRDC_MGRN_BASE_NS }
  /** Array initializer of NOC_TRDC_MGR peripheral base pointers */
  #define NOC_TRDC_MGR_BASE_PTRS_NS                { NOC__TRDC_MGRN_NS }
#else
  /** Peripheral NOC__TRDC_MGRN base address */
  #define NOC__TRDC_MGRN_BASE                      (0x49010000u)
  /** Peripheral NOC__TRDC_MGRN base pointer */
  #define NOC__TRDC_MGRN                           ((NOC_TRDC_MGR_Type *)NOC__TRDC_MGRN_BASE)
  /** Array initializer of NOC_TRDC_MGR peripheral base addresses */
  #define NOC_TRDC_MGR_BASE_ADDRS                  { NOC__TRDC_MGRN_BASE }
  /** Array initializer of NOC_TRDC_MGR peripheral base pointers */
  #define NOC_TRDC_MGR_BASE_PTRS                   { NOC__TRDC_MGRN }
#endif

/* NOC_always_on_main_ResFaultCntr - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER base address */
  #define NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER_BASE (0x59063080u)
  /** Peripheral NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER base address */
  #define NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER_BASE_NS (0x49063080u)
  /** Peripheral NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER base pointer */
  #define NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER ((NOC_always_on_main_ResFaultCntr_Type *)NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER_BASE)
  /** Peripheral NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER base pointer */
  #define NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER_NS ((NOC_always_on_main_ResFaultCntr_Type *)NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER_BASE_NS)
  /** Array initializer of NOC_always_on_main_ResFaultCntr peripheral base
   * addresses */
  #define NOC_always_on_main_ResFaultCntr_BASE_ADDRS { NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER_BASE }
  /** Array initializer of NOC_always_on_main_ResFaultCntr peripheral base
   * pointers */
  #define NOC_always_on_main_ResFaultCntr_BASE_PTRS { NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER }
  /** Array initializer of NOC_always_on_main_ResFaultCntr peripheral base
   * addresses */
  #define NOC_always_on_main_ResFaultCntr_BASE_ADDRS_NS { NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER_BASE_NS }
  /** Array initializer of NOC_always_on_main_ResFaultCntr peripheral base
   * pointers */
  #define NOC_always_on_main_ResFaultCntr_BASE_PTRS_NS { NOC__GPV__ALWAYS_ON_MAIN_RESILIENCEFAULTCONTROLLER_NS }
#else
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
#endif

/* NOC_m_e_0_rd_I_m_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE (0x59062400u)
  /** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE_NS (0x49062400u)
  /** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_0_rd_I_m_QosGen_Type *)NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_0_rd_I_m_QosGen_Type *)NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_0_rd_I_m_QosGen peripheral base addresses */
  #define NOC_m_e_0_rd_I_m_QosGen_BASE_ADDRS       { NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_0_rd_I_m_QosGen peripheral base pointers */
  #define NOC_m_e_0_rd_I_m_QosGen_BASE_PTRS        { NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_0_rd_I_m_QosGen peripheral base addresses */
  #define NOC_m_e_0_rd_I_m_QosGen_BASE_ADDRS_NS    { NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_0_rd_I_m_QosGen peripheral base pointers */
  #define NOC_m_e_0_rd_I_m_QosGen_BASE_PTRS_NS     { NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE (0x49062400u)
  /** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_0_rd_I_m_QosGen_Type *)NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_0_rd_I_m_QosGen peripheral base addresses */
  #define NOC_m_e_0_rd_I_m_QosGen_BASE_ADDRS       { NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_0_rd_I_m_QosGen peripheral base pointers */
  #define NOC_m_e_0_rd_I_m_QosGen_BASE_PTRS        { NOC__GPV__M_E_0_RD_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_0_rd_I_main_TranStatFilt - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x59063100u)
  /** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x49063100u)
  /** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_0_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER_NS ((NOC_m_e_0_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of NOC_m_e_0_rd_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_0_rd_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of NOC_m_e_0_rd_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_0_rd_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of NOC_m_e_0_rd_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_0_rd_I_main_TranStatFilt_BASE_ADDRS_NS { NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of NOC_m_e_0_rd_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_0_rd_I_main_TranStatFilt_BASE_PTRS_NS { NOC__GPV__M_E_0_RD_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* NOC_m_e_0_wr_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE (0x59062480u)
  /** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE_NS (0x49062480u)
  /** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_0_wr_I_main_QosGen_Type *)NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_0_wr_I_main_QosGen_Type *)NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_0_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_0_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_0_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_0_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_0_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_0_wr_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_0_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_0_wr_I_main_QosGen_BASE_PTRS_NS  { NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE (0x49062480u)
  /** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_0_wr_I_main_QosGen_Type *)NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_0_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_0_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_0_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_0_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_0_WR_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_0_wr_I_main_TranStatFilt - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x59063180u)
  /** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x49063180u)
  /** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_0_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER_NS ((NOC_m_e_0_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of NOC_m_e_0_wr_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_0_wr_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of NOC_m_e_0_wr_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_0_wr_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of NOC_m_e_0_wr_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_0_wr_I_main_TranStatFilt_BASE_ADDRS_NS { NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of NOC_m_e_0_wr_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_0_wr_I_main_TranStatFilt_BASE_PTRS_NS { NOC__GPV__M_E_0_WR_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* NOC_m_e_1a_rd_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE (0x59062500u)
  /** Peripheral NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE_NS (0x49062500u)
  /** Peripheral NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR  ((NOC_m_e_1a_rd_I_main_QosGen_Type *)NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_1a_rd_I_main_QosGen_Type *)NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_1a_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1a_rd_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_1a_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1a_rd_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_1a_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1a_rd_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_1a_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1a_rd_I_main_QosGen_BASE_PTRS_NS { NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE (0x49062500u)
  /** Peripheral NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR  ((NOC_m_e_1a_rd_I_main_QosGen_Type *)NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_1a_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1a_rd_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_1a_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1a_rd_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1A_RD_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_1a_wr_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE (0x59062580u)
  /** Peripheral NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE_NS (0x49062580u)
  /** Peripheral NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR  ((NOC_m_e_1a_wr_I_main_QosGen_Type *)NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_1a_wr_I_main_QosGen_Type *)NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_1a_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1a_wr_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_1a_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1a_wr_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_1a_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1a_wr_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_1a_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1a_wr_I_main_QosGen_BASE_PTRS_NS { NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE (0x49062580u)
  /** Peripheral NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR  ((NOC_m_e_1a_wr_I_main_QosGen_Type *)NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_1a_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1a_wr_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_1a_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1a_wr_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1A_WR_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_1b_rd_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE (0x59062600u)
  /** Peripheral NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE_NS (0x49062600u)
  /** Peripheral NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR  ((NOC_m_e_1b_rd_I_main_QosGen_Type *)NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_1b_rd_I_main_QosGen_Type *)NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_1b_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1b_rd_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_1b_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1b_rd_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_1b_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1b_rd_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_1b_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1b_rd_I_main_QosGen_BASE_PTRS_NS { NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE (0x49062600u)
  /** Peripheral NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR  ((NOC_m_e_1b_rd_I_main_QosGen_Type *)NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_1b_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1b_rd_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_1b_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1b_rd_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1B_RD_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_1b_wr_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE (0x59062680u)
  /** Peripheral NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE_NS (0x49062680u)
  /** Peripheral NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR  ((NOC_m_e_1b_wr_I_main_QosGen_Type *)NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_1b_wr_I_main_QosGen_Type *)NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_1b_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1b_wr_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_1b_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1b_wr_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_1b_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1b_wr_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_1b_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1b_wr_I_main_QosGen_BASE_PTRS_NS { NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE (0x49062680u)
  /** Peripheral NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR  ((NOC_m_e_1b_wr_I_main_QosGen_Type *)NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_1b_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_1b_wr_I_main_QosGen_BASE_ADDRS   { NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_1b_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_1b_wr_I_main_QosGen_BASE_PTRS    { NOC__GPV__M_E_1B_WR_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_3_rd_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE (0x59062800u)
  /** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE_NS (0x49062800u)
  /** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_3_rd_I_main_QosGen_Type *)NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_3_rd_I_main_QosGen_Type *)NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_3_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_3_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_3_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_3_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_3_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_3_rd_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_3_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_3_rd_I_main_QosGen_BASE_PTRS_NS  { NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE (0x49062800u)
  /** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_3_rd_I_main_QosGen_Type *)NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_3_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_3_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_3_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_3_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_3_RD_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_3_rd_I_main_TranStatFilt - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x59063200u)
  /** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x49063200u)
  /** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_3_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER_NS ((NOC_m_e_3_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of NOC_m_e_3_rd_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_3_rd_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of NOC_m_e_3_rd_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_3_rd_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of NOC_m_e_3_rd_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_3_rd_I_main_TranStatFilt_BASE_ADDRS_NS { NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of NOC_m_e_3_rd_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_3_rd_I_main_TranStatFilt_BASE_PTRS_NS { NOC__GPV__M_E_3_RD_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* NOC_m_e_3_wr_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE (0x59062880u)
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE_NS (0x49062880u)
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_3_wr_I_main_QosGen_Type *)NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_3_wr_I_main_QosGen_Type *)NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_3_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_3_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_3_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_3_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_3_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_3_wr_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_3_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_3_wr_I_main_QosGen_BASE_PTRS_NS  { NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE (0x49062880u)
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_3_wr_I_main_QosGen_Type *)NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_3_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_3_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_3_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_3_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_3_WR_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_6_rd_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE (0x59062B00u)
  /** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE_NS (0x49062B00u)
  /** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_6_rd_I_main_QosGen_Type *)NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_6_rd_I_main_QosGen_Type *)NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_6_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_6_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_6_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_6_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_6_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_6_rd_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_6_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_6_rd_I_main_QosGen_BASE_PTRS_NS  { NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE (0x49062B00u)
  /** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_6_rd_I_main_QosGen_Type *)NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_6_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_6_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_6_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_6_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_6_RD_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_6_rd_I_main_TranStatFilt - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x59063500u)
  /** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x49063500u)
  /** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_6_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER_NS ((NOC_m_e_6_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of NOC_m_e_6_rd_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_6_rd_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of NOC_m_e_6_rd_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_6_rd_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of NOC_m_e_6_rd_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_6_rd_I_main_TranStatFilt_BASE_ADDRS_NS { NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of NOC_m_e_6_rd_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_6_rd_I_main_TranStatFilt_BASE_PTRS_NS { NOC__GPV__M_E_6_RD_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* NOC_m_e_6_wr_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE (0x59062B80u)
  /** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE_NS (0x49062B80u)
  /** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_6_wr_I_main_QosGen_Type *)NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_6_wr_I_main_QosGen_Type *)NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_6_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_6_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_6_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_6_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_6_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_6_wr_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_6_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_6_wr_I_main_QosGen_BASE_PTRS_NS  { NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE (0x49062B80u)
  /** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_6_wr_I_main_QosGen_Type *)NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_6_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_6_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_6_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_6_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_6_WR_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_6_wr_I_main_TranStatFilt - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x59063580u)
  /** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x49063580u)
  /** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_6_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER_NS ((NOC_m_e_6_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of NOC_m_e_6_wr_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_6_wr_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of NOC_m_e_6_wr_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_6_wr_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of NOC_m_e_6_wr_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_6_wr_I_main_TranStatFilt_BASE_ADDRS_NS { NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of NOC_m_e_6_wr_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_6_wr_I_main_TranStatFilt_BASE_PTRS_NS { NOC__GPV__M_E_6_WR_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* NOC_m_e_7_rd_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE (0x59062C00u)
  /** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE_NS (0x49062C00u)
  /** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_7_rd_I_main_QosGen_Type *)NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_7_rd_I_main_QosGen_Type *)NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_7_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_7_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_7_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_7_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_7_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_7_rd_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_7_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_7_rd_I_main_QosGen_BASE_PTRS_NS  { NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE (0x49062C00u)
  /** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_7_rd_I_main_QosGen_Type *)NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_7_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_7_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_7_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_7_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_7_RD_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_7_rd_I_main_TranStatFilt - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x59063600u)
  /** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x49063600u)
  /** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_7_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER_NS ((NOC_m_e_7_rd_I_main_TranStatFilt_Type *)NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of NOC_m_e_7_rd_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_7_rd_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of NOC_m_e_7_rd_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_7_rd_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of NOC_m_e_7_rd_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_7_rd_I_main_TranStatFilt_BASE_ADDRS_NS { NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of NOC_m_e_7_rd_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_7_rd_I_main_TranStatFilt_BASE_PTRS_NS { NOC__GPV__M_E_7_RD_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* NOC_m_e_7_wr_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE (0x59062D80u)
  /** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE_NS (0x49062D80u)
  /** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_7_wr_I_main_QosGen_Type *)NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_7_wr_I_main_QosGen_Type *)NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_7_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_7_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_7_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_7_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_7_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_7_wr_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_7_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_7_wr_I_main_QosGen_BASE_PTRS_NS  { NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE (0x49062D80u)
  /** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_7_wr_I_main_QosGen_Type *)NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_7_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_7_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_7_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_7_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_7_WR_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_7_wr_I_main_TranStatFilt - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x59063680u)
  /** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x49063680u)
  /** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_7_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER_NS ((NOC_m_e_7_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of NOC_m_e_7_wr_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_7_wr_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of NOC_m_e_7_wr_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_7_wr_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of NOC_m_e_7_wr_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_7_wr_I_main_TranStatFilt_BASE_ADDRS_NS { NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of NOC_m_e_7_wr_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_7_wr_I_main_TranStatFilt_BASE_PTRS_NS { NOC__GPV__M_E_7_WR_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* NOC_m_e_9_rd_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE (0x59062E00u)
  /** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE_NS (0x49062E00u)
  /** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_9_rd_I_main_QosGen_Type *)NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_9_rd_I_main_QosGen_Type *)NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_9_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_9_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_9_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_9_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_9_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_9_rd_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_9_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_9_rd_I_main_QosGen_BASE_PTRS_NS  { NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE (0x49062E00u)
  /** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR   ((NOC_m_e_9_rd_I_main_QosGen_Type *)NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_9_rd_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_9_rd_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_9_rd_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_9_rd_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_9_RD_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_9_wr_I_main_QosGen - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE (0x59062E80u)
  /** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE_NS (0x49062E80u)
  /** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_9_wr_I_main_QosGen_Type *)NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_NS ((NOC_m_e_9_wr_I_main_QosGen_Type *)NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE_NS)
  /** Array initializer of NOC_m_e_9_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_9_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_9_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_9_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR }
  /** Array initializer of NOC_m_e_9_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_9_wr_I_main_QosGen_BASE_ADDRS_NS { NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE_NS }
  /** Array initializer of NOC_m_e_9_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_9_wr_I_main_QosGen_BASE_PTRS_NS  { NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_NS }
#else
  /** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR base address */
  #define NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE (0x49062E80u)
  /** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR base pointer */
  #define NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR   ((NOC_m_e_9_wr_I_main_QosGen_Type *)NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE)
  /** Array initializer of NOC_m_e_9_wr_I_main_QosGen peripheral base addresses */
  #define NOC_m_e_9_wr_I_main_QosGen_BASE_ADDRS    { NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR_BASE }
  /** Array initializer of NOC_m_e_9_wr_I_main_QosGen peripheral base pointers */
  #define NOC_m_e_9_wr_I_main_QosGen_BASE_PTRS     { NOC__GPV__M_E_9_WR_I_MAIN_QOSGENERATOR }
#endif

/* NOC_m_e_9_wr_I_main_TranStatFilt - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x59063780u)
  /** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x49063780u)
  /** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER ((NOC_m_e_9_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER_NS ((NOC_m_e_9_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of NOC_m_e_9_wr_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_9_wr_I_main_TranStatFilt_BASE_ADDRS { NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of NOC_m_e_9_wr_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_9_wr_I_main_TranStatFilt_BASE_PTRS { NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of NOC_m_e_9_wr_I_main_TranStatFilt peripheral base
   * addresses */
  #define NOC_m_e_9_wr_I_main_TranStatFilt_BASE_ADDRS_NS { NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of NOC_m_e_9_wr_I_main_TranStatFilt peripheral base
   * pointers */
  #define NOC_m_e_9_wr_I_main_TranStatFilt_BASE_PTRS_NS { NOC__GPV__M_E_9_WR_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* NPU_EIM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NPU__EIM_NPUMIX base address */
  #define NPU__EIM_NPUMIX_BASE                     (0x5A860000u)
  /** Peripheral NPU__EIM_NPUMIX base address */
  #define NPU__EIM_NPUMIX_BASE_NS                  (0x4A860000u)
  /** Peripheral NPU__EIM_NPUMIX base pointer */
  #define NPU__EIM_NPUMIX                          ((NPU_EIM_Type *)NPU__EIM_NPUMIX_BASE)
  /** Peripheral NPU__EIM_NPUMIX base pointer */
  #define NPU__EIM_NPUMIX_NS                       ((NPU_EIM_Type *)NPU__EIM_NPUMIX_BASE_NS)
  /** Array initializer of NPU_EIM peripheral base addresses */
  #define NPU_EIM_BASE_ADDRS                       { NPU__EIM_NPUMIX_BASE }
  /** Array initializer of NPU_EIM peripheral base pointers */
  #define NPU_EIM_BASE_PTRS                        { NPU__EIM_NPUMIX }
  /** Array initializer of NPU_EIM peripheral base addresses */
  #define NPU_EIM_BASE_ADDRS_NS                    { NPU__EIM_NPUMIX_BASE_NS }
  /** Array initializer of NPU_EIM peripheral base pointers */
  #define NPU_EIM_BASE_PTRS_NS                     { NPU__EIM_NPUMIX_NS }
#else
  /** Peripheral NPU__EIM_NPUMIX base address */
  #define NPU__EIM_NPUMIX_BASE                     (0x4A860000u)
  /** Peripheral NPU__EIM_NPUMIX base pointer */
  #define NPU__EIM_NPUMIX                          ((NPU_EIM_Type *)NPU__EIM_NPUMIX_BASE)
  /** Array initializer of NPU_EIM peripheral base addresses */
  #define NPU_EIM_BASE_ADDRS                       { NPU__EIM_NPUMIX_BASE }
  /** Array initializer of NPU_EIM peripheral base pointers */
  #define NPU_EIM_BASE_PTRS                        { NPU__EIM_NPUMIX }
#endif

/* NPU_LSTCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NPU__LSTCU_NPUMIX base address */
  #define NPU__LSTCU_NPUMIX_BASE                   (0x5A850000u)
  /** Peripheral NPU__LSTCU_NPUMIX base address */
  #define NPU__LSTCU_NPUMIX_BASE_NS                (0x4A850000u)
  /** Peripheral NPU__LSTCU_NPUMIX base pointer */
  #define NPU__LSTCU_NPUMIX                        ((NPU_LSTCU_Type *)NPU__LSTCU_NPUMIX_BASE)
  /** Peripheral NPU__LSTCU_NPUMIX base pointer */
  #define NPU__LSTCU_NPUMIX_NS                     ((NPU_LSTCU_Type *)NPU__LSTCU_NPUMIX_BASE_NS)
  /** Array initializer of NPU_LSTCU peripheral base addresses */
  #define NPU_LSTCU_BASE_ADDRS                     { NPU__LSTCU_NPUMIX_BASE }
  /** Array initializer of NPU_LSTCU peripheral base pointers */
  #define NPU_LSTCU_BASE_PTRS                      { NPU__LSTCU_NPUMIX }
  /** Array initializer of NPU_LSTCU peripheral base addresses */
  #define NPU_LSTCU_BASE_ADDRS_NS                  { NPU__LSTCU_NPUMIX_BASE_NS }
  /** Array initializer of NPU_LSTCU peripheral base pointers */
  #define NPU_LSTCU_BASE_PTRS_NS                   { NPU__LSTCU_NPUMIX_NS }
#else
  /** Peripheral NPU__LSTCU_NPUMIX base address */
  #define NPU__LSTCU_NPUMIX_BASE                   (0x4A850000u)
  /** Peripheral NPU__LSTCU_NPUMIX base pointer */
  #define NPU__LSTCU_NPUMIX                        ((NPU_LSTCU_Type *)NPU__LSTCU_NPUMIX_BASE)
  /** Array initializer of NPU_LSTCU peripheral base addresses */
  #define NPU_LSTCU_BASE_ADDRS                     { NPU__LSTCU_NPUMIX_BASE }
  /** Array initializer of NPU_LSTCU peripheral base pointers */
  #define NPU_LSTCU_BASE_PTRS                      { NPU__LSTCU_NPUMIX }
#endif

/* NPU_TCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NPU__TCU base address */
  #define NPU__TCU_BASE                            (0x5A800000u)
  /** Peripheral NPU__TCU base address */
  #define NPU__TCU_BASE_NS                         (0x4A800000u)
  /** Peripheral NPU__TCU base pointer */
  #define NPU__TCU                                 ((NPU_TCU_Type *)NPU__TCU_BASE)
  /** Peripheral NPU__TCU base pointer */
  #define NPU__TCU_NS                              ((NPU_TCU_Type *)NPU__TCU_BASE_NS)
  /** Array initializer of NPU_TCU peripheral base addresses */
  #define NPU_TCU_BASE_ADDRS                       { NPU__TCU_BASE }
  /** Array initializer of NPU_TCU peripheral base pointers */
  #define NPU_TCU_BASE_PTRS                        { NPU__TCU }
  /** Array initializer of NPU_TCU peripheral base addresses */
  #define NPU_TCU_BASE_ADDRS_NS                    { NPU__TCU_BASE_NS }
  /** Array initializer of NPU_TCU peripheral base pointers */
  #define NPU_TCU_BASE_PTRS_NS                     { NPU__TCU_NS }
#else
  /** Peripheral NPU__TCU base address */
  #define NPU__TCU_BASE                            (0x4A800000u)
  /** Peripheral NPU__TCU base pointer */
  #define NPU__TCU                                 ((NPU_TCU_Type *)NPU__TCU_BASE)
  /** Array initializer of NPU_TCU peripheral base addresses */
  #define NPU_TCU_BASE_ADDRS                       { NPU__TCU_BASE }
  /** Array initializer of NPU_TCU peripheral base pointers */
  #define NPU_TCU_BASE_PTRS                        { NPU__TCU }
#endif

/* OSC24M - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OSC24M base address */
  #define OSC24M_BASE                              (0x54480000u)
  /** Peripheral OSC24M base address */
  #define OSC24M_BASE_NS                           (0x44480000u)
  /** Peripheral OSC24M base pointer */
  #define OSC24M                                   ((OSC24M_Type *)OSC24M_BASE)
  /** Peripheral OSC24M base pointer */
  #define OSC24M_NS                                ((OSC24M_Type *)OSC24M_BASE_NS)
  /** Array initializer of OSC24M peripheral base addresses */
  #define OSC24M_BASE_ADDRS                        { OSC24M_BASE }
  /** Array initializer of OSC24M peripheral base pointers */
  #define OSC24M_BASE_PTRS                         { OSC24M }
  /** Array initializer of OSC24M peripheral base addresses */
  #define OSC24M_BASE_ADDRS_NS                     { OSC24M_BASE_NS }
  /** Array initializer of OSC24M peripheral base pointers */
  #define OSC24M_BASE_PTRS_NS                      { OSC24M_NS }
#else
  /** Peripheral OSC24M base address */
  #define OSC24M_BASE                              (0x44480000u)
  /** Peripheral OSC24M base pointer */
  #define OSC24M                                   ((OSC24M_Type *)OSC24M_BASE)
  /** Array initializer of OSC24M peripheral base addresses */
  #define OSC24M_BASE_ADDRS                        { OSC24M_BASE }
  /** Array initializer of OSC24M peripheral base pointers */
  #define OSC24M_BASE_PTRS                         { OSC24M }
#endif

/* PCIE_DMA_IATU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE1__PCIE_DMA_IATU base address */
  #define HSIO__PCIE1__PCIE_DMA_IATU_BASE          (0x5C360000u)
  /** Peripheral HSIO__PCIE1__PCIE_DMA_IATU base address */
  #define HSIO__PCIE1__PCIE_DMA_IATU_BASE_NS       (0x4C360000u)
  /** Peripheral HSIO__PCIE1__PCIE_DMA_IATU base pointer */
  #define HSIO__PCIE1__PCIE_DMA_IATU               ((PCIE_DMA_IATU_Type *)HSIO__PCIE1__PCIE_DMA_IATU_BASE)
  /** Peripheral HSIO__PCIE1__PCIE_DMA_IATU base pointer */
  #define HSIO__PCIE1__PCIE_DMA_IATU_NS            ((PCIE_DMA_IATU_Type *)HSIO__PCIE1__PCIE_DMA_IATU_BASE_NS)
  /** Peripheral HSIO__PCIE2__PCIE_DMA_IATU base address */
  #define HSIO__PCIE2__PCIE_DMA_IATU_BASE          (0x5C3E0000u)
  /** Peripheral HSIO__PCIE2__PCIE_DMA_IATU base address */
  #define HSIO__PCIE2__PCIE_DMA_IATU_BASE_NS       (0x4C3E0000u)
  /** Peripheral HSIO__PCIE2__PCIE_DMA_IATU base pointer */
  #define HSIO__PCIE2__PCIE_DMA_IATU               ((PCIE_DMA_IATU_Type *)HSIO__PCIE2__PCIE_DMA_IATU_BASE)
  /** Peripheral HSIO__PCIE2__PCIE_DMA_IATU base pointer */
  #define HSIO__PCIE2__PCIE_DMA_IATU_NS            ((PCIE_DMA_IATU_Type *)HSIO__PCIE2__PCIE_DMA_IATU_BASE_NS)
  /** Array initializer of PCIE_DMA_IATU peripheral base addresses */
  #define PCIE_DMA_IATU_BASE_ADDRS                 { HSIO__PCIE1__PCIE_DMA_IATU_BASE, HSIO__PCIE2__PCIE_DMA_IATU_BASE }
  /** Array initializer of PCIE_DMA_IATU peripheral base pointers */
  #define PCIE_DMA_IATU_BASE_PTRS                  { HSIO__PCIE1__PCIE_DMA_IATU, HSIO__PCIE2__PCIE_DMA_IATU }
  /** Array initializer of PCIE_DMA_IATU peripheral base addresses */
  #define PCIE_DMA_IATU_BASE_ADDRS_NS              { HSIO__PCIE1__PCIE_DMA_IATU_BASE_NS, HSIO__PCIE2__PCIE_DMA_IATU_BASE_NS }
  /** Array initializer of PCIE_DMA_IATU peripheral base pointers */
  #define PCIE_DMA_IATU_BASE_PTRS_NS               { HSIO__PCIE1__PCIE_DMA_IATU_NS, HSIO__PCIE2__PCIE_DMA_IATU_NS }
#else
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
#endif

/* PCIE_EP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE1__PCIE_EP base address */
  #define HSIO__PCIE1__PCIE_EP_BASE                (0x5C300000u)
  /** Peripheral HSIO__PCIE1__PCIE_EP base address */
  #define HSIO__PCIE1__PCIE_EP_BASE_NS             (0x4C300000u)
  /** Peripheral HSIO__PCIE1__PCIE_EP base pointer */
  #define HSIO__PCIE1__PCIE_EP                     ((PCIE_EP_Type *)HSIO__PCIE1__PCIE_EP_BASE)
  /** Peripheral HSIO__PCIE1__PCIE_EP base pointer */
  #define HSIO__PCIE1__PCIE_EP_NS                  ((PCIE_EP_Type *)HSIO__PCIE1__PCIE_EP_BASE_NS)
  /** Peripheral HSIO__PCIE2__PCIE_EP base address */
  #define HSIO__PCIE2__PCIE_EP_BASE                (0x5C380000u)
  /** Peripheral HSIO__PCIE2__PCIE_EP base address */
  #define HSIO__PCIE2__PCIE_EP_BASE_NS             (0x4C380000u)
  /** Peripheral HSIO__PCIE2__PCIE_EP base pointer */
  #define HSIO__PCIE2__PCIE_EP                     ((PCIE_EP_Type *)HSIO__PCIE2__PCIE_EP_BASE)
  /** Peripheral HSIO__PCIE2__PCIE_EP base pointer */
  #define HSIO__PCIE2__PCIE_EP_NS                  ((PCIE_EP_Type *)HSIO__PCIE2__PCIE_EP_BASE_NS)
  /** Array initializer of PCIE_EP peripheral base addresses */
  #define PCIE_EP_BASE_ADDRS                       { HSIO__PCIE1__PCIE_EP_BASE, HSIO__PCIE2__PCIE_EP_BASE }
  /** Array initializer of PCIE_EP peripheral base pointers */
  #define PCIE_EP_BASE_PTRS                        { HSIO__PCIE1__PCIE_EP, HSIO__PCIE2__PCIE_EP }
  /** Array initializer of PCIE_EP peripheral base addresses */
  #define PCIE_EP_BASE_ADDRS_NS                    { HSIO__PCIE1__PCIE_EP_BASE_NS, HSIO__PCIE2__PCIE_EP_BASE_NS }
  /** Array initializer of PCIE_EP peripheral base pointers */
  #define PCIE_EP_BASE_PTRS_NS                     { HSIO__PCIE1__PCIE_EP_NS, HSIO__PCIE2__PCIE_EP_NS }
#else
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
#endif

/* PCIE_RC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE1__PCIE_RC base address */
  #define HSIO__PCIE1__PCIE_RC_BASE                (0x5C300000u)
  /** Peripheral HSIO__PCIE1__PCIE_RC base address */
  #define HSIO__PCIE1__PCIE_RC_BASE_NS             (0x4C300000u)
  /** Peripheral HSIO__PCIE1__PCIE_RC base pointer */
  #define HSIO__PCIE1__PCIE_RC                     ((PCIE_RC_Type *)HSIO__PCIE1__PCIE_RC_BASE)
  /** Peripheral HSIO__PCIE1__PCIE_RC base pointer */
  #define HSIO__PCIE1__PCIE_RC_NS                  ((PCIE_RC_Type *)HSIO__PCIE1__PCIE_RC_BASE_NS)
  /** Peripheral HSIO__PCIE2__PCIE_RC base address */
  #define HSIO__PCIE2__PCIE_RC_BASE                (0x5C380000u)
  /** Peripheral HSIO__PCIE2__PCIE_RC base address */
  #define HSIO__PCIE2__PCIE_RC_BASE_NS             (0x4C380000u)
  /** Peripheral HSIO__PCIE2__PCIE_RC base pointer */
  #define HSIO__PCIE2__PCIE_RC                     ((PCIE_RC_Type *)HSIO__PCIE2__PCIE_RC_BASE)
  /** Peripheral HSIO__PCIE2__PCIE_RC base pointer */
  #define HSIO__PCIE2__PCIE_RC_NS                  ((PCIE_RC_Type *)HSIO__PCIE2__PCIE_RC_BASE_NS)
  /** Array initializer of PCIE_RC peripheral base addresses */
  #define PCIE_RC_BASE_ADDRS                       { HSIO__PCIE1__PCIE_RC_BASE, HSIO__PCIE2__PCIE_RC_BASE }
  /** Array initializer of PCIE_RC peripheral base pointers */
  #define PCIE_RC_BASE_PTRS                        { HSIO__PCIE1__PCIE_RC, HSIO__PCIE2__PCIE_RC }
  /** Array initializer of PCIE_RC peripheral base addresses */
  #define PCIE_RC_BASE_ADDRS_NS                    { HSIO__PCIE1__PCIE_RC_BASE_NS, HSIO__PCIE2__PCIE_RC_BASE_NS }
  /** Array initializer of PCIE_RC peripheral base pointers */
  #define PCIE_RC_BASE_PTRS_NS                     { HSIO__PCIE1__PCIE_RC_NS, HSIO__PCIE2__PCIE_RC_NS }
#else
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
#endif

/* PCIE_SHADOW_EP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE1__PCIE_SHADOW_EP base address */
  #define HSIO__PCIE1__PCIE_SHADOW_EP_BASE         (0x5C320000u)
  /** Peripheral HSIO__PCIE1__PCIE_SHADOW_EP base address */
  #define HSIO__PCIE1__PCIE_SHADOW_EP_BASE_NS      (0x4C320000u)
  /** Peripheral HSIO__PCIE1__PCIE_SHADOW_EP base pointer */
  #define HSIO__PCIE1__PCIE_SHADOW_EP              ((PCIE_SHADOW_EP_Type *)HSIO__PCIE1__PCIE_SHADOW_EP_BASE)
  /** Peripheral HSIO__PCIE1__PCIE_SHADOW_EP base pointer */
  #define HSIO__PCIE1__PCIE_SHADOW_EP_NS           ((PCIE_SHADOW_EP_Type *)HSIO__PCIE1__PCIE_SHADOW_EP_BASE_NS)
  /** Peripheral HSIO__PCIE2__PCIE_SHADOW_EP base address */
  #define HSIO__PCIE2__PCIE_SHADOW_EP_BASE         (0x5C3A0000u)
  /** Peripheral HSIO__PCIE2__PCIE_SHADOW_EP base address */
  #define HSIO__PCIE2__PCIE_SHADOW_EP_BASE_NS      (0x4C3A0000u)
  /** Peripheral HSIO__PCIE2__PCIE_SHADOW_EP base pointer */
  #define HSIO__PCIE2__PCIE_SHADOW_EP              ((PCIE_SHADOW_EP_Type *)HSIO__PCIE2__PCIE_SHADOW_EP_BASE)
  /** Peripheral HSIO__PCIE2__PCIE_SHADOW_EP base pointer */
  #define HSIO__PCIE2__PCIE_SHADOW_EP_NS           ((PCIE_SHADOW_EP_Type *)HSIO__PCIE2__PCIE_SHADOW_EP_BASE_NS)
  /** Array initializer of PCIE_SHADOW_EP peripheral base addresses */
  #define PCIE_SHADOW_EP_BASE_ADDRS                { HSIO__PCIE1__PCIE_SHADOW_EP_BASE, HSIO__PCIE2__PCIE_SHADOW_EP_BASE }
  /** Array initializer of PCIE_SHADOW_EP peripheral base pointers */
  #define PCIE_SHADOW_EP_BASE_PTRS                 { HSIO__PCIE1__PCIE_SHADOW_EP, HSIO__PCIE2__PCIE_SHADOW_EP }
  /** Array initializer of PCIE_SHADOW_EP peripheral base addresses */
  #define PCIE_SHADOW_EP_BASE_ADDRS_NS             { HSIO__PCIE1__PCIE_SHADOW_EP_BASE_NS, HSIO__PCIE2__PCIE_SHADOW_EP_BASE_NS }
  /** Array initializer of PCIE_SHADOW_EP peripheral base pointers */
  #define PCIE_SHADOW_EP_BASE_PTRS_NS              { HSIO__PCIE1__PCIE_SHADOW_EP_NS, HSIO__PCIE2__PCIE_SHADOW_EP_NS }
#else
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
#endif

/* PDM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PDM base address */
  #define PDM_BASE                                 (0x54520000u)
  /** Peripheral PDM base address */
  #define PDM_BASE_NS                              (0x44520000u)
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
  #define PDM_BASE                                 (0x44520000u)
  /** Peripheral PDM base pointer */
  #define PDM                                      ((PDM_Type *)PDM_BASE)
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS                           { PDM_BASE }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS                            { PDM }
#endif

/* PLL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYS_PLL1 base address */
  #define SYS_PLL1_BASE                            (0x54481000u)
  /** Peripheral SYS_PLL1 base address */
  #define SYS_PLL1_BASE_NS                         (0x44481000u)
  /** Peripheral SYS_PLL1 base pointer */
  #define SYS_PLL1                                 ((PLL_Type *)SYS_PLL1_BASE)
  /** Peripheral SYS_PLL1 base pointer */
  #define SYS_PLL1_NS                              ((PLL_Type *)SYS_PLL1_BASE_NS)
  /** Peripheral AUDIO_PLL1 base address */
  #define AUDIO_PLL1_BASE                          (0x54481100u)
  /** Peripheral AUDIO_PLL1 base address */
  #define AUDIO_PLL1_BASE_NS                       (0x44481100u)
  /** Peripheral AUDIO_PLL1 base pointer */
  #define AUDIO_PLL1                               ((PLL_Type *)AUDIO_PLL1_BASE)
  /** Peripheral AUDIO_PLL1 base pointer */
  #define AUDIO_PLL1_NS                            ((PLL_Type *)AUDIO_PLL1_BASE_NS)
  /** Peripheral AUDIO_PLL2 base address */
  #define AUDIO_PLL2_BASE                          (0x54481200u)
  /** Peripheral AUDIO_PLL2 base address */
  #define AUDIO_PLL2_BASE_NS                       (0x44481200u)
  /** Peripheral AUDIO_PLL2 base pointer */
  #define AUDIO_PLL2                               ((PLL_Type *)AUDIO_PLL2_BASE)
  /** Peripheral AUDIO_PLL2 base pointer */
  #define AUDIO_PLL2_NS                            ((PLL_Type *)AUDIO_PLL2_BASE_NS)
  /** Peripheral ENCODER_PLL base address */
  #define ENCODER_PLL_BASE                         (0x54481300u)
  /** Peripheral ENCODER_PLL base address */
  #define ENCODER_PLL_BASE_NS                      (0x44481300u)
  /** Peripheral ENCODER_PLL base pointer */
  #define ENCODER_PLL                              ((PLL_Type *)ENCODER_PLL_BASE)
  /** Peripheral ENCODER_PLL base pointer */
  #define ENCODER_PLL_NS                           ((PLL_Type *)ENCODER_PLL_BASE_NS)
  /** Peripheral ARM_PLL base address */
  #define ARM_PLL_BASE                             (0x54481600u)
  /** Peripheral ARM_PLL base address */
  #define ARM_PLL_BASE_NS                          (0x44481600u)
  /** Peripheral ARM_PLL base pointer */
  #define ARM_PLL                                  ((PLL_Type *)ARM_PLL_BASE)
  /** Peripheral ARM_PLL base pointer */
  #define ARM_PLL_NS                               ((PLL_Type *)ARM_PLL_BASE_NS)
  /** Peripheral DRAM_PLL base address */
  #define DRAM_PLL_BASE                            (0x54481700u)
  /** Peripheral DRAM_PLL base address */
  #define DRAM_PLL_BASE_NS                         (0x44481700u)
  /** Peripheral DRAM_PLL base pointer */
  #define DRAM_PLL                                 ((PLL_Type *)DRAM_PLL_BASE)
  /** Peripheral DRAM_PLL base pointer */
  #define DRAM_PLL_NS                              ((PLL_Type *)DRAM_PLL_BASE_NS)
  /** Peripheral HSIO_PLL base address */
  #define HSIO_PLL_BASE                            (0x54481800u)
  /** Peripheral HSIO_PLL base address */
  #define HSIO_PLL_BASE_NS                         (0x44481800u)
  /** Peripheral HSIO_PLL base pointer */
  #define HSIO_PLL                                 ((PLL_Type *)HSIO_PLL_BASE)
  /** Peripheral HSIO_PLL base pointer */
  #define HSIO_PLL_NS                              ((PLL_Type *)HSIO_PLL_BASE_NS)
  /** Peripheral LDB_PLL base address */
  #define LDB_PLL_BASE                             (0x54481900u)
  /** Peripheral LDB_PLL base address */
  #define LDB_PLL_BASE_NS                          (0x44481900u)
  /** Peripheral LDB_PLL base pointer */
  #define LDB_PLL                                  ((PLL_Type *)LDB_PLL_BASE)
  /** Peripheral LDB_PLL base pointer */
  #define LDB_PLL_NS                               ((PLL_Type *)LDB_PLL_BASE_NS)
  /** Array initializer of PLL peripheral base addresses */
  #define PLL_BASE_ADDRS                           { SYS_PLL1_BASE, AUDIO_PLL1_BASE, AUDIO_PLL2_BASE, ENCODER_PLL_BASE, ARM_PLL_BASE, DRAM_PLL_BASE, HSIO_PLL_BASE, LDB_PLL_BASE }
  /** Array initializer of PLL peripheral base pointers */
  #define PLL_BASE_PTRS                            { SYS_PLL1, AUDIO_PLL1, AUDIO_PLL2, ENCODER_PLL, ARM_PLL, DRAM_PLL, HSIO_PLL, LDB_PLL }
  /** Array initializer of PLL peripheral base addresses */
  #define PLL_BASE_ADDRS_NS                        { SYS_PLL1_BASE_NS, AUDIO_PLL1_BASE_NS, AUDIO_PLL2_BASE_NS, ENCODER_PLL_BASE_NS, ARM_PLL_BASE_NS, DRAM_PLL_BASE_NS, HSIO_PLL_BASE_NS, LDB_PLL_BASE_NS }
  /** Array initializer of PLL peripheral base pointers */
  #define PLL_BASE_PTRS_NS                         { SYS_PLL1_NS, AUDIO_PLL1_NS, AUDIO_PLL2_NS, ENCODER_PLL_NS, ARM_PLL_NS, DRAM_PLL_NS, HSIO_PLL_NS, LDB_PLL_NS }
#else
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
#endif

/* PWM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PWM1 base address */
  #define PWM1_BASE                                (0x529A0000u)
  /** Peripheral PWM1 base address */
  #define PWM1_BASE_NS                             (0x429A0000u)
  /** Peripheral PWM1 base pointer */
  #define PWM1                                     ((PWM_Type *)PWM1_BASE)
  /** Peripheral PWM1 base pointer */
  #define PWM1_NS                                  ((PWM_Type *)PWM1_BASE_NS)
  /** Peripheral PWM2 base address */
  #define PWM2_BASE                                (0x529B0000u)
  /** Peripheral PWM2 base address */
  #define PWM2_BASE_NS                             (0x429B0000u)
  /** Peripheral PWM2 base pointer */
  #define PWM2                                     ((PWM_Type *)PWM2_BASE)
  /** Peripheral PWM2 base pointer */
  #define PWM2_NS                                  ((PWM_Type *)PWM2_BASE_NS)
  /** Peripheral PWM3 base address */
  #define PWM3_BASE                                (0x529C0000u)
  /** Peripheral PWM3 base address */
  #define PWM3_BASE_NS                             (0x429C0000u)
  /** Peripheral PWM3 base pointer */
  #define PWM3                                     ((PWM_Type *)PWM3_BASE)
  /** Peripheral PWM3 base pointer */
  #define PWM3_NS                                  ((PWM_Type *)PWM3_BASE_NS)
  /** Peripheral PWM4 base address */
  #define PWM4_BASE                                (0x529D0000u)
  /** Peripheral PWM4 base address */
  #define PWM4_BASE_NS                             (0x429D0000u)
  /** Peripheral PWM4 base pointer */
  #define PWM4                                     ((PWM_Type *)PWM4_BASE)
  /** Peripheral PWM4 base pointer */
  #define PWM4_NS                                  ((PWM_Type *)PWM4_BASE_NS)
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS                           { 0u, PWM1_BASE, PWM2_BASE, PWM3_BASE, PWM4_BASE }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS                            { (PWM_Type *)0u, PWM1, PWM2, PWM3, PWM4 }
  /** Array initializer of PWM peripheral base addresses */
  #define PWM_BASE_ADDRS_NS                        { 0u, PWM1_BASE_NS, PWM2_BASE_NS, PWM3_BASE_NS, PWM4_BASE_NS }
  /** Array initializer of PWM peripheral base pointers */
  #define PWM_BASE_PTRS_NS                         { (PWM_Type *)0u, PWM1_NS, PWM2_NS, PWM3_NS, PWM4_NS }
#else
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
#endif

/* PXP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PXP base address */
  #define PXP_BASE                                 (0x5B110000u)
  /** Peripheral PXP base address */
  #define PXP_BASE_NS                              (0x4B110000u)
  /** Peripheral PXP base pointer */
  #define PXP                                      ((PXP_Type *)PXP_BASE)
  /** Peripheral PXP base pointer */
  #define PXP_NS                                   ((PXP_Type *)PXP_BASE_NS)
  /** Array initializer of PXP peripheral base addresses */
  #define PXP_BASE_ADDRS                           { PXP_BASE }
  /** Array initializer of PXP peripheral base pointers */
  #define PXP_BASE_PTRS                            { PXP }
  /** Array initializer of PXP peripheral base addresses */
  #define PXP_BASE_ADDRS_NS                        { PXP_BASE_NS }
  /** Array initializer of PXP peripheral base pointers */
  #define PXP_BASE_PTRS_NS                         { PXP_NS }
#else
  /** Peripheral PXP base address */
  #define PXP_BASE                                 (0x4B110000u)
  /** Peripheral PXP base pointer */
  #define PXP                                      ((PXP_Type *)PXP_BASE)
  /** Array initializer of PXP peripheral base addresses */
  #define PXP_BASE_ADDRS                           { PXP_BASE }
  /** Array initializer of PXP peripheral base pointers */
  #define PXP_BASE_PTRS                            { PXP }
#endif

/* RGPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE                               (0x57400000u)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE_NS                            (0x47400000u)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1                                    ((RGPIO_Type *)GPIO1_BASE)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1_NS                                 ((RGPIO_Type *)GPIO1_BASE_NS)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE                               (0x53810000u)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE_NS                            (0x43810000u)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2                                    ((RGPIO_Type *)GPIO2_BASE)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2_NS                                 ((RGPIO_Type *)GPIO2_BASE_NS)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE                               (0x53820000u)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE_NS                            (0x43820000u)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3                                    ((RGPIO_Type *)GPIO3_BASE)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3_NS                                 ((RGPIO_Type *)GPIO3_BASE_NS)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE                               (0x53840000u)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE_NS                            (0x43840000u)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4                                    ((RGPIO_Type *)GPIO4_BASE)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4_NS                                 ((RGPIO_Type *)GPIO4_BASE_NS)
  /** Peripheral GPIO5 base address */
  #define GPIO5_BASE                               (0x53850000u)
  /** Peripheral GPIO5 base address */
  #define GPIO5_BASE_NS                            (0x43850000u)
  /** Peripheral GPIO5 base pointer */
  #define GPIO5                                    ((RGPIO_Type *)GPIO5_BASE)
  /** Peripheral GPIO5 base pointer */
  #define GPIO5_NS                                 ((RGPIO_Type *)GPIO5_BASE_NS)
  /** Peripheral GPIO6 base address */
  #define GPIO6_BASE                               (0x53860000u)
  /** Peripheral GPIO6 base address */
  #define GPIO6_BASE_NS                            (0x43860000u)
  /** Peripheral GPIO6 base pointer */
  #define GPIO6                                    ((RGPIO_Type *)GPIO6_BASE)
  /** Peripheral GPIO6 base pointer */
  #define GPIO6_NS                                 ((RGPIO_Type *)GPIO6_BASE_NS)
  /** Peripheral GPIO7 base address */
  #define GPIO7_BASE                               (0x53870000u)
  /** Peripheral GPIO7 base address */
  #define GPIO7_BASE_NS                            (0x43870000u)
  /** Peripheral GPIO7 base pointer */
  #define GPIO7                                    ((RGPIO_Type *)GPIO7_BASE)
  /** Peripheral GPIO7 base pointer */
  #define GPIO7_NS                                 ((RGPIO_Type *)GPIO7_BASE_NS)
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS                         { 0u, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE, GPIO6_BASE, GPIO7_BASE }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS                          { (RGPIO_Type *)0u, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5, GPIO6, GPIO7 }
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS_NS                      { 0u, GPIO1_BASE_NS, GPIO2_BASE_NS, GPIO3_BASE_NS, GPIO4_BASE_NS, GPIO5_BASE_NS, GPIO6_BASE_NS, GPIO7_BASE_NS }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS_NS                       { (RGPIO_Type *)0u, GPIO1_NS, GPIO2_NS, GPIO3_NS, GPIO4_NS, GPIO5_NS, GPIO6_NS, GPIO7_NS }
#else
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
#endif
/** Interrupt vectors for the RGPIO peripheral type */
#define RGPIO_IRQS                               { NotAvail_IRQn, GPIO1_INT0_IRQn, GPIO2_INT0_IRQn, GPIO3_INT0_IRQn, GPIO4_INT0_IRQn, GPIO5_INT0_IRQn, GPIO6_INT0_IRQn, GPIO7_INT0_IRQn }

/* S3MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ELE_MU0_MUA base address */
  #define ELE_MU0_MUA_BASE                         (0x57520000u)
  /** Peripheral ELE_MU0_MUA base address */
  #define ELE_MU0_MUA_BASE_NS                      (0x47520000u)
  /** Peripheral ELE_MU0_MUA base pointer */
  #define ELE_MU0_MUA                              ((S3MU_Type *)ELE_MU0_MUA_BASE)
  /** Peripheral ELE_MU0_MUA base pointer */
  #define ELE_MU0_MUA_NS                           ((S3MU_Type *)ELE_MU0_MUA_BASE_NS)
  /** Peripheral ELE_MU1_MUA base address */
  #define ELE_MU1_MUA_BASE                         (0x57530000u)
  /** Peripheral ELE_MU1_MUA base address */
  #define ELE_MU1_MUA_BASE_NS                      (0x47530000u)
  /** Peripheral ELE_MU1_MUA base pointer */
  #define ELE_MU1_MUA                              ((S3MU_Type *)ELE_MU1_MUA_BASE)
  /** Peripheral ELE_MU1_MUA base pointer */
  #define ELE_MU1_MUA_NS                           ((S3MU_Type *)ELE_MU1_MUA_BASE_NS)
  /** Peripheral ELE_MU2_MUA base address */
  #define ELE_MU2_MUA_BASE                         (0x57540000u)
  /** Peripheral ELE_MU2_MUA base address */
  #define ELE_MU2_MUA_BASE_NS                      (0x47540000u)
  /** Peripheral ELE_MU2_MUA base pointer */
  #define ELE_MU2_MUA                              ((S3MU_Type *)ELE_MU2_MUA_BASE)
  /** Peripheral ELE_MU2_MUA base pointer */
  #define ELE_MU2_MUA_NS                           ((S3MU_Type *)ELE_MU2_MUA_BASE_NS)
  /** Peripheral ELE_MU3_MUA base address */
  #define ELE_MU3_MUA_BASE                         (0x57550000u)
  /** Peripheral ELE_MU3_MUA base address */
  #define ELE_MU3_MUA_BASE_NS                      (0x47550000u)
  /** Peripheral ELE_MU3_MUA base pointer */
  #define ELE_MU3_MUA                              ((S3MU_Type *)ELE_MU3_MUA_BASE)
  /** Peripheral ELE_MU3_MUA base pointer */
  #define ELE_MU3_MUA_NS                           ((S3MU_Type *)ELE_MU3_MUA_BASE_NS)
  /** Peripheral ELE_MU4_MUA base address */
  #define ELE_MU4_MUA_BASE                         (0x57560000u)
  /** Peripheral ELE_MU4_MUA base address */
  #define ELE_MU4_MUA_BASE_NS                      (0x47560000u)
  /** Peripheral ELE_MU4_MUA base pointer */
  #define ELE_MU4_MUA                              ((S3MU_Type *)ELE_MU4_MUA_BASE)
  /** Peripheral ELE_MU4_MUA base pointer */
  #define ELE_MU4_MUA_NS                           ((S3MU_Type *)ELE_MU4_MUA_BASE_NS)
  /** Peripheral ELE_MU5_MUA base address */
  #define ELE_MU5_MUA_BASE                         (0x57570000u)
  /** Peripheral ELE_MU5_MUA base address */
  #define ELE_MU5_MUA_BASE_NS                      (0x47570000u)
  /** Peripheral ELE_MU5_MUA base pointer */
  #define ELE_MU5_MUA                              ((S3MU_Type *)ELE_MU5_MUA_BASE)
  /** Peripheral ELE_MU5_MUA base pointer */
  #define ELE_MU5_MUA_NS                           ((S3MU_Type *)ELE_MU5_MUA_BASE_NS)
  /** Peripheral ELE_MU6_MUA base address */
  #define ELE_MU6_MUA_BASE                         (0x57580000u)
  /** Peripheral ELE_MU6_MUA base address */
  #define ELE_MU6_MUA_BASE_NS                      (0x47580000u)
  /** Peripheral ELE_MU6_MUA base pointer */
  #define ELE_MU6_MUA                              ((S3MU_Type *)ELE_MU6_MUA_BASE)
  /** Peripheral ELE_MU6_MUA base pointer */
  #define ELE_MU6_MUA_NS                           ((S3MU_Type *)ELE_MU6_MUA_BASE_NS)
  /** Peripheral ELE_MU7_MUA base address */
  #define ELE_MU7_MUA_BASE                         (0x57590000u)
  /** Peripheral ELE_MU7_MUA base address */
  #define ELE_MU7_MUA_BASE_NS                      (0x47590000u)
  /** Peripheral ELE_MU7_MUA base pointer */
  #define ELE_MU7_MUA                              ((S3MU_Type *)ELE_MU7_MUA_BASE)
  /** Peripheral ELE_MU7_MUA base pointer */
  #define ELE_MU7_MUA_NS                           ((S3MU_Type *)ELE_MU7_MUA_BASE_NS)
  /** Peripheral ELE_MU8_MUA base address */
  #define ELE_MU8_MUA_BASE                         (0x575A0000u)
  /** Peripheral ELE_MU8_MUA base address */
  #define ELE_MU8_MUA_BASE_NS                      (0x475A0000u)
  /** Peripheral ELE_MU8_MUA base pointer */
  #define ELE_MU8_MUA                              ((S3MU_Type *)ELE_MU8_MUA_BASE)
  /** Peripheral ELE_MU8_MUA base pointer */
  #define ELE_MU8_MUA_NS                           ((S3MU_Type *)ELE_MU8_MUA_BASE_NS)
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS                          { ELE_MU0_MUA_BASE, ELE_MU1_MUA_BASE, ELE_MU2_MUA_BASE, ELE_MU3_MUA_BASE, ELE_MU4_MUA_BASE, ELE_MU5_MUA_BASE, ELE_MU6_MUA_BASE, ELE_MU7_MUA_BASE, ELE_MU8_MUA_BASE }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS                           { ELE_MU0_MUA, ELE_MU1_MUA, ELE_MU2_MUA, ELE_MU3_MUA, ELE_MU4_MUA, ELE_MU5_MUA, ELE_MU6_MUA, ELE_MU7_MUA, ELE_MU8_MUA }
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS_NS                       { ELE_MU0_MUA_BASE_NS, ELE_MU1_MUA_BASE_NS, ELE_MU2_MUA_BASE_NS, ELE_MU3_MUA_BASE_NS, ELE_MU4_MUA_BASE_NS, ELE_MU5_MUA_BASE_NS, ELE_MU6_MUA_BASE_NS, ELE_MU7_MUA_BASE_NS, ELE_MU8_MUA_BASE_NS }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS_NS                        { ELE_MU0_MUA_NS, ELE_MU1_MUA_NS, ELE_MU2_MUA_NS, ELE_MU3_MUA_NS, ELE_MU4_MUA_NS, ELE_MU5_MUA_NS, ELE_MU6_MUA_NS, ELE_MU7_MUA_NS, ELE_MU8_MUA_NS }
#else
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
#endif

/* SEMA42 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SEMA42_1 base address */
  #define SEMA42_1_BASE                            (0x54260000u)
  /** Peripheral SEMA42_1 base address */
  #define SEMA42_1_BASE_NS                         (0x44260000u)
  /** Peripheral SEMA42_1 base pointer */
  #define SEMA42_1                                 ((SEMA42_Type *)SEMA42_1_BASE)
  /** Peripheral SEMA42_1 base pointer */
  #define SEMA42_1_NS                              ((SEMA42_Type *)SEMA42_1_BASE_NS)
  /** Peripheral SEMA42_2 base address */
  #define SEMA42_2_BASE                            (0x52450000u)
  /** Peripheral SEMA42_2 base address */
  #define SEMA42_2_BASE_NS                         (0x42450000u)
  /** Peripheral SEMA42_2 base pointer */
  #define SEMA42_2                                 ((SEMA42_Type *)SEMA42_2_BASE)
  /** Peripheral SEMA42_2 base pointer */
  #define SEMA42_2_NS                              ((SEMA42_Type *)SEMA42_2_BASE_NS)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { 0u, SEMA42_1_BASE, SEMA42_2_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { (SEMA42_Type *)0u, SEMA42_1, SEMA42_2 }
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS_NS                     { 0u, SEMA42_1_BASE_NS, SEMA42_2_BASE_NS }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS_NS                      { (SEMA42_Type *)0u, SEMA42_1_NS, SEMA42_2_NS }
#else
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
#endif

/* SINC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SINC1 base address */
  #define SINC1_BASE                               (0x52960000u)
  /** Peripheral SINC1 base address */
  #define SINC1_BASE_NS                            (0x42960000u)
  /** Peripheral SINC1 base pointer */
  #define SINC1                                    ((SINC_Type *)SINC1_BASE)
  /** Peripheral SINC1 base pointer */
  #define SINC1_NS                                 ((SINC_Type *)SINC1_BASE_NS)
  /** Peripheral SINC2 base address */
  #define SINC2_BASE                               (0x52970000u)
  /** Peripheral SINC2 base address */
  #define SINC2_BASE_NS                            (0x42970000u)
  /** Peripheral SINC2 base pointer */
  #define SINC2                                    ((SINC_Type *)SINC2_BASE)
  /** Peripheral SINC2 base pointer */
  #define SINC2_NS                                 ((SINC_Type *)SINC2_BASE_NS)
  /** Peripheral SINC3 base address */
  #define SINC3_BASE                               (0x52980000u)
  /** Peripheral SINC3 base address */
  #define SINC3_BASE_NS                            (0x42980000u)
  /** Peripheral SINC3 base pointer */
  #define SINC3                                    ((SINC_Type *)SINC3_BASE)
  /** Peripheral SINC3 base pointer */
  #define SINC3_NS                                 ((SINC_Type *)SINC3_BASE_NS)
  /** Peripheral SINC4 base address */
  #define SINC4_BASE                               (0x52990000u)
  /** Peripheral SINC4 base address */
  #define SINC4_BASE_NS                            (0x42990000u)
  /** Peripheral SINC4 base pointer */
  #define SINC4                                    ((SINC_Type *)SINC4_BASE)
  /** Peripheral SINC4 base pointer */
  #define SINC4_NS                                 ((SINC_Type *)SINC4_BASE_NS)
  /** Array initializer of SINC peripheral base addresses */
  #define SINC_BASE_ADDRS                          { 0u, SINC1_BASE, SINC2_BASE, SINC3_BASE, SINC4_BASE }
  /** Array initializer of SINC peripheral base pointers */
  #define SINC_BASE_PTRS                           { (SINC_Type *)0u, SINC1, SINC2, SINC3, SINC4 }
  /** Array initializer of SINC peripheral base addresses */
  #define SINC_BASE_ADDRS_NS                       { 0u, SINC1_BASE_NS, SINC2_BASE_NS, SINC3_BASE_NS, SINC4_BASE_NS }
  /** Array initializer of SINC peripheral base pointers */
  #define SINC_BASE_PTRS_NS                        { (SINC_Type *)0u, SINC1_NS, SINC2_NS, SINC3_NS, SINC4_NS }
#else
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
#endif

/* SRAMCTL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SRAMCTL base address */
  #define SRAMCTL_BASE                             (0x590A0000u)
  /** Peripheral SRAMCTL base address */
  #define SRAMCTL_BASE_NS                          (0x490A0000u)
  /** Peripheral SRAMCTL base pointer */
  #define SRAMCTL                                  ((SRAMCTL_Type *)SRAMCTL_BASE)
  /** Peripheral SRAMCTL base pointer */
  #define SRAMCTL_NS                               ((SRAMCTL_Type *)SRAMCTL_BASE_NS)
  /** Array initializer of SRAMCTL peripheral base addresses */
  #define SRAMCTL_BASE_ADDRS                       { SRAMCTL_BASE }
  /** Array initializer of SRAMCTL peripheral base pointers */
  #define SRAMCTL_BASE_PTRS                        { SRAMCTL }
  /** Array initializer of SRAMCTL peripheral base addresses */
  #define SRAMCTL_BASE_ADDRS_NS                    { SRAMCTL_BASE_NS }
  /** Array initializer of SRAMCTL peripheral base pointers */
  #define SRAMCTL_BASE_PTRS_NS                     { SRAMCTL_NS }
#else
  /** Peripheral SRAMCTL base address */
  #define SRAMCTL_BASE                             (0x490A0000u)
  /** Peripheral SRAMCTL base pointer */
  #define SRAMCTL                                  ((SRAMCTL_Type *)SRAMCTL_BASE)
  /** Array initializer of SRAMCTL peripheral base addresses */
  #define SRAMCTL_BASE_ADDRS                       { SRAMCTL_BASE }
  /** Array initializer of SRAMCTL peripheral base pointers */
  #define SRAMCTL_BASE_PTRS                        { SRAMCTL }
#endif

/* SRC_GEN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SRC_GEN base address */
  #define SRC_GEN_BASE                             (0x54460000u)
  /** Peripheral SRC_GEN base address */
  #define SRC_GEN_BASE_NS                          (0x44460000u)
  /** Peripheral SRC_GEN base pointer */
  #define SRC_GEN                                  ((SRC_GEN_Type *)SRC_GEN_BASE)
  /** Peripheral SRC_GEN base pointer */
  #define SRC_GEN_NS                               ((SRC_GEN_Type *)SRC_GEN_BASE_NS)
  /** Array initializer of SRC_GEN peripheral base addresses */
  #define SRC_GEN_BASE_ADDRS                       { SRC_GEN_BASE }
  /** Array initializer of SRC_GEN peripheral base pointers */
  #define SRC_GEN_BASE_PTRS                        { SRC_GEN }
  /** Array initializer of SRC_GEN peripheral base addresses */
  #define SRC_GEN_BASE_ADDRS_NS                    { SRC_GEN_BASE_NS }
  /** Array initializer of SRC_GEN peripheral base pointers */
  #define SRC_GEN_BASE_PTRS_NS                     { SRC_GEN_NS }
#else
  /** Peripheral SRC_GEN base address */
  #define SRC_GEN_BASE                             (0x44460000u)
  /** Peripheral SRC_GEN base pointer */
  #define SRC_GEN                                  ((SRC_GEN_Type *)SRC_GEN_BASE)
  /** Array initializer of SRC_GEN peripheral base addresses */
  #define SRC_GEN_BASE_ADDRS                       { SRC_GEN_BASE }
  /** Array initializer of SRC_GEN peripheral base pointers */
  #define SRC_GEN_BASE_PTRS                        { SRC_GEN }
#endif

/* SRC_MEM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE     (0x54460900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE_NS  (0x44460900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_AONMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_AONMIX_MEM_NS       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE (0x54461900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE_NS (0x44461900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE (0x54461D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE_NS (0x44461D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE (0x54462100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE_NS (0x44462100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE (0x54462500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE_NS (0x44462500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE (0x54462900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE_NS (0x44462900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE (0x54462920u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE_NS (0x44462920u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE     (0x54462D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE_NS  (0x44462D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_NS       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE (0x54463100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE_NS (0x44463100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_NS   ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE    (0x54463900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE_NS (0x44463900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_NS      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE      (0x54463500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE_NS   (0x44463500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_M7MIX_MEM           ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_M7MIX_MEM_NS        ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M72MIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_M72MIX_MEM_BASE     (0x54461100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M72MIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_M72MIX_MEM_BASE_NS  (0x44461100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M72MIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_M72MIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_M72MIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M72MIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_M72MIX_MEM_NS       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_M72MIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE    (0x54464100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE_NS (0x44464100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_NS      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base address */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE    (0x54464500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base address */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE_NS (0x44464500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base pointer */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base pointer */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_NS      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base address */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE    (0x54464520u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base address */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE_NS (0x44464520u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base pointer */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base pointer */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_NS      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE     (0x54464900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE_NS  (0x44464900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_NS       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE  (0x54464D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE_NS (0x44464D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_NS    ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE_NS)
  /** Array initializer of SRC_MEM peripheral base addresses */
  #define SRC_MEM_BASE_ADDRS                       { CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_M72MIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE }
  /** Array initializer of SRC_MEM peripheral base pointers */
  #define SRC_MEM_BASE_PTRS                        { CCMSRCGPC__SRC__XSPR_AONMIX_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM, CCMSRCGPC__SRC__XSPR_M7MIX_MEM, CCMSRCGPC__SRC__XSPR_M72MIX_MEM, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM }
  /** Array initializer of SRC_MEM peripheral base addresses */
  #define SRC_MEM_BASE_ADDRS_NS                    { CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE_NS, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_M72MIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE_NS, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE_NS, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE_NS }
  /** Array initializer of SRC_MEM peripheral base pointers */
  #define SRC_MEM_BASE_PTRS_NS                     { CCMSRCGPC__SRC__XSPR_AONMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_NS, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_M7MIX_MEM_NS, CCMSRCGPC__SRC__XSPR_M72MIX_MEM_NS, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_NS, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_NS, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_NS }
#else
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
#endif

/* SRC_XSPR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SRC_XSPR_ANAMIX base address */
  #define SRC_XSPR_ANAMIX_BASE                     (0x54460400u)
  /** Peripheral SRC_XSPR_ANAMIX base address */
  #define SRC_XSPR_ANAMIX_BASE_NS                  (0x44460400u)
  /** Peripheral SRC_XSPR_ANAMIX base pointer */
  #define SRC_XSPR_ANAMIX                          ((SRC_XSPR_Type *)SRC_XSPR_ANAMIX_BASE)
  /** Peripheral SRC_XSPR_ANAMIX base pointer */
  #define SRC_XSPR_ANAMIX_NS                       ((SRC_XSPR_Type *)SRC_XSPR_ANAMIX_BASE_NS)
  /** Peripheral SRC_XSPR_AONMIX base address */
  #define SRC_XSPR_AONMIX_BASE                     (0x54460800u)
  /** Peripheral SRC_XSPR_AONMIX base address */
  #define SRC_XSPR_AONMIX_BASE_NS                  (0x44460800u)
  /** Peripheral SRC_XSPR_AONMIX base pointer */
  #define SRC_XSPR_AONMIX                          ((SRC_XSPR_Type *)SRC_XSPR_AONMIX_BASE)
  /** Peripheral SRC_XSPR_AONMIX base pointer */
  #define SRC_XSPR_AONMIX_NS                       ((SRC_XSPR_Type *)SRC_XSPR_AONMIX_BASE_NS)
  /** Peripheral SRC_XSPR_BBSMMIX base address */
  #define SRC_XSPR_BBSMMIX_BASE                    (0x54460C00u)
  /** Peripheral SRC_XSPR_BBSMMIX base address */
  #define SRC_XSPR_BBSMMIX_BASE_NS                 (0x44460C00u)
  /** Peripheral SRC_XSPR_BBSMMIX base pointer */
  #define SRC_XSPR_BBSMMIX                         ((SRC_XSPR_Type *)SRC_XSPR_BBSMMIX_BASE)
  /** Peripheral SRC_XSPR_BBSMMIX base pointer */
  #define SRC_XSPR_BBSMMIX_NS                      ((SRC_XSPR_Type *)SRC_XSPR_BBSMMIX_BASE_NS)
  /** Peripheral SRC_XSPR_CCMSRCGPCMIX base address */
  #define SRC_XSPR_CCMSRCGPCMIX_BASE               (0x54461400u)
  /** Peripheral SRC_XSPR_CCMSRCGPCMIX base address */
  #define SRC_XSPR_CCMSRCGPCMIX_BASE_NS            (0x44461400u)
  /** Peripheral SRC_XSPR_CCMSRCGPCMIX base pointer */
  #define SRC_XSPR_CCMSRCGPCMIX                    ((SRC_XSPR_Type *)SRC_XSPR_CCMSRCGPCMIX_BASE)
  /** Peripheral SRC_XSPR_CCMSRCGPCMIX base pointer */
  #define SRC_XSPR_CCMSRCGPCMIX_NS                 ((SRC_XSPR_Type *)SRC_XSPR_CCMSRCGPCMIX_BASE_NS)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base address */
  #define SRC_XSPR_CORTEXMIX_CORE0_BASE            (0x54461800u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base address */
  #define SRC_XSPR_CORTEXMIX_CORE0_BASE_NS         (0x44461800u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE0                 ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE0_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE0_NS              ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE0_BASE_NS)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base address */
  #define SRC_XSPR_CORTEXMIX_CORE1_BASE            (0x54461C00u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base address */
  #define SRC_XSPR_CORTEXMIX_CORE1_BASE_NS         (0x44461C00u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE1                 ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE1_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE1_NS              ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE1_BASE_NS)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base address */
  #define SRC_XSPR_CORTEXMIX_CORE2_BASE            (0x54462000u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base address */
  #define SRC_XSPR_CORTEXMIX_CORE2_BASE_NS         (0x44462000u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE2                 ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE2_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE2_NS              ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE2_BASE_NS)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base address */
  #define SRC_XSPR_CORTEXMIX_CORE3_BASE            (0x54462400u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base address */
  #define SRC_XSPR_CORTEXMIX_CORE3_BASE_NS         (0x44462400u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE3                 ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE3_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE3_NS              ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE3_BASE_NS)
  /** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base address */
  #define SRC_XSPR_CORTEXMIX_PLATFORM_BASE         (0x54462800u)
  /** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base address */
  #define SRC_XSPR_CORTEXMIX_PLATFORM_BASE_NS      (0x44462800u)
  /** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base pointer */
  #define SRC_XSPR_CORTEXMIX_PLATFORM              ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_PLATFORM_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base pointer */
  #define SRC_XSPR_CORTEXMIX_PLATFORM_NS           ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_PLATFORM_BASE_NS)
  /** Peripheral SRC_XSPR_DDRMIX base address */
  #define SRC_XSPR_DDRMIX_BASE                     (0x54462C00u)
  /** Peripheral SRC_XSPR_DDRMIX base address */
  #define SRC_XSPR_DDRMIX_BASE_NS                  (0x44462C00u)
  /** Peripheral SRC_XSPR_DDRMIX base pointer */
  #define SRC_XSPR_DDRMIX                          ((SRC_XSPR_Type *)SRC_XSPR_DDRMIX_BASE)
  /** Peripheral SRC_XSPR_DDRMIX base pointer */
  #define SRC_XSPR_DDRMIX_NS                       ((SRC_XSPR_Type *)SRC_XSPR_DDRMIX_BASE_NS)
  /** Peripheral SRC_XSPR_DISPLAYMIX base address */
  #define SRC_XSPR_DISPLAYMIX_BASE                 (0x54463000u)
  /** Peripheral SRC_XSPR_DISPLAYMIX base address */
  #define SRC_XSPR_DISPLAYMIX_BASE_NS              (0x44463000u)
  /** Peripheral SRC_XSPR_DISPLAYMIX base pointer */
  #define SRC_XSPR_DISPLAYMIX                      ((SRC_XSPR_Type *)SRC_XSPR_DISPLAYMIX_BASE)
  /** Peripheral SRC_XSPR_DISPLAYMIX base pointer */
  #define SRC_XSPR_DISPLAYMIX_NS                   ((SRC_XSPR_Type *)SRC_XSPR_DISPLAYMIX_BASE_NS)
  /** Peripheral SRC_XSPR_HSIOMIX_TOP base address */
  #define SRC_XSPR_HSIOMIX_TOP_BASE                (0x54463800u)
  /** Peripheral SRC_XSPR_HSIOMIX_TOP base address */
  #define SRC_XSPR_HSIOMIX_TOP_BASE_NS             (0x44463800u)
  /** Peripheral SRC_XSPR_HSIOMIX_TOP base pointer */
  #define SRC_XSPR_HSIOMIX_TOP                     ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_TOP_BASE)
  /** Peripheral SRC_XSPR_HSIOMIX_TOP base pointer */
  #define SRC_XSPR_HSIOMIX_TOP_NS                  ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_TOP_BASE_NS)
  /** Peripheral SRC_XSPR_HSIOMIX_WAON base address */
  #define SRC_XSPR_HSIOMIX_WAON_BASE               (0x54463C00u)
  /** Peripheral SRC_XSPR_HSIOMIX_WAON base address */
  #define SRC_XSPR_HSIOMIX_WAON_BASE_NS            (0x44463C00u)
  /** Peripheral SRC_XSPR_HSIOMIX_WAON base pointer */
  #define SRC_XSPR_HSIOMIX_WAON                    ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_WAON_BASE)
  /** Peripheral SRC_XSPR_HSIOMIX_WAON base pointer */
  #define SRC_XSPR_HSIOMIX_WAON_NS                 ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_WAON_BASE_NS)
  /** Peripheral SRC_XSPR_M70MIX base address */
  #define SRC_XSPR_M70MIX_BASE                     (0x54463400u)
  /** Peripheral SRC_XSPR_M70MIX base address */
  #define SRC_XSPR_M70MIX_BASE_NS                  (0x44463400u)
  /** Peripheral SRC_XSPR_M70MIX base pointer */
  #define SRC_XSPR_M70MIX                          ((SRC_XSPR_Type *)SRC_XSPR_M70MIX_BASE)
  /** Peripheral SRC_XSPR_M70MIX base pointer */
  #define SRC_XSPR_M70MIX_NS                       ((SRC_XSPR_Type *)SRC_XSPR_M70MIX_BASE_NS)
  /** Peripheral SRC_XSPR_M71MIX base address */
  #define SRC_XSPR_M71MIX_BASE                     (0x54461000u)
  /** Peripheral SRC_XSPR_M71MIX base address */
  #define SRC_XSPR_M71MIX_BASE_NS                  (0x44461000u)
  /** Peripheral SRC_XSPR_M71MIX base pointer */
  #define SRC_XSPR_M71MIX                          ((SRC_XSPR_Type *)SRC_XSPR_M71MIX_BASE)
  /** Peripheral SRC_XSPR_M71MIX base pointer */
  #define SRC_XSPR_M71MIX_NS                       ((SRC_XSPR_Type *)SRC_XSPR_M71MIX_BASE_NS)
  /** Peripheral SRC_XSPR_NETCMIX base address */
  #define SRC_XSPR_NETCMIX_BASE                    (0x54464000u)
  /** Peripheral SRC_XSPR_NETCMIX base address */
  #define SRC_XSPR_NETCMIX_BASE_NS                 (0x44464000u)
  /** Peripheral SRC_XSPR_NETCMIX base pointer */
  #define SRC_XSPR_NETCMIX                         ((SRC_XSPR_Type *)SRC_XSPR_NETCMIX_BASE)
  /** Peripheral SRC_XSPR_NETCMIX base pointer */
  #define SRC_XSPR_NETCMIX_NS                      ((SRC_XSPR_Type *)SRC_XSPR_NETCMIX_BASE_NS)
  /** Peripheral SRC_XSPR_NOCMIX base address */
  #define SRC_XSPR_NOCMIX_BASE                     (0x54464400u)
  /** Peripheral SRC_XSPR_NOCMIX base address */
  #define SRC_XSPR_NOCMIX_BASE_NS                  (0x44464400u)
  /** Peripheral SRC_XSPR_NOCMIX base pointer */
  #define SRC_XSPR_NOCMIX                          ((SRC_XSPR_Type *)SRC_XSPR_NOCMIX_BASE)
  /** Peripheral SRC_XSPR_NOCMIX base pointer */
  #define SRC_XSPR_NOCMIX_NS                       ((SRC_XSPR_Type *)SRC_XSPR_NOCMIX_BASE_NS)
  /** Peripheral SRC_XSPR_NPUMIX base address */
  #define SRC_XSPR_NPUMIX_BASE                     (0x54464800u)
  /** Peripheral SRC_XSPR_NPUMIX base address */
  #define SRC_XSPR_NPUMIX_BASE_NS                  (0x44464800u)
  /** Peripheral SRC_XSPR_NPUMIX base pointer */
  #define SRC_XSPR_NPUMIX                          ((SRC_XSPR_Type *)SRC_XSPR_NPUMIX_BASE)
  /** Peripheral SRC_XSPR_NPUMIX base pointer */
  #define SRC_XSPR_NPUMIX_NS                       ((SRC_XSPR_Type *)SRC_XSPR_NPUMIX_BASE_NS)
  /** Peripheral SRC_XSPR_WAKEUPMIX base address */
  #define SRC_XSPR_WAKEUPMIX_BASE                  (0x54464C00u)
  /** Peripheral SRC_XSPR_WAKEUPMIX base address */
  #define SRC_XSPR_WAKEUPMIX_BASE_NS               (0x44464C00u)
  /** Peripheral SRC_XSPR_WAKEUPMIX base pointer */
  #define SRC_XSPR_WAKEUPMIX                       ((SRC_XSPR_Type *)SRC_XSPR_WAKEUPMIX_BASE)
  /** Peripheral SRC_XSPR_WAKEUPMIX base pointer */
  #define SRC_XSPR_WAKEUPMIX_NS                    ((SRC_XSPR_Type *)SRC_XSPR_WAKEUPMIX_BASE_NS)
  /** Array initializer of SRC_XSPR peripheral base addresses */
  #define SRC_XSPR_BASE_ADDRS                      { SRC_XSPR_ANAMIX_BASE, SRC_XSPR_AONMIX_BASE, SRC_XSPR_BBSMMIX_BASE, SRC_XSPR_CCMSRCGPCMIX_BASE, SRC_XSPR_CORTEXMIX_CORE0_BASE, SRC_XSPR_CORTEXMIX_CORE1_BASE, SRC_XSPR_CORTEXMIX_CORE2_BASE, SRC_XSPR_CORTEXMIX_CORE3_BASE, SRC_XSPR_CORTEXMIX_PLATFORM_BASE, SRC_XSPR_DDRMIX_BASE, SRC_XSPR_DISPLAYMIX_BASE, SRC_XSPR_HSIOMIX_TOP_BASE, SRC_XSPR_HSIOMIX_WAON_BASE, SRC_XSPR_M70MIX_BASE, SRC_XSPR_M71MIX_BASE, SRC_XSPR_NETCMIX_BASE, SRC_XSPR_NOCMIX_BASE, SRC_XSPR_NPUMIX_BASE, SRC_XSPR_WAKEUPMIX_BASE }
  /** Array initializer of SRC_XSPR peripheral base pointers */
  #define SRC_XSPR_BASE_PTRS                       { SRC_XSPR_ANAMIX, SRC_XSPR_AONMIX, SRC_XSPR_BBSMMIX, SRC_XSPR_CCMSRCGPCMIX, SRC_XSPR_CORTEXMIX_CORE0, SRC_XSPR_CORTEXMIX_CORE1, SRC_XSPR_CORTEXMIX_CORE2, SRC_XSPR_CORTEXMIX_CORE3, SRC_XSPR_CORTEXMIX_PLATFORM, SRC_XSPR_DDRMIX, SRC_XSPR_DISPLAYMIX, SRC_XSPR_HSIOMIX_TOP, SRC_XSPR_HSIOMIX_WAON, SRC_XSPR_M70MIX, SRC_XSPR_M71MIX, SRC_XSPR_NETCMIX, SRC_XSPR_NOCMIX, SRC_XSPR_NPUMIX, SRC_XSPR_WAKEUPMIX }
  /** Array initializer of SRC_XSPR peripheral base addresses */
  #define SRC_XSPR_BASE_ADDRS_NS                   { SRC_XSPR_ANAMIX_BASE_NS, SRC_XSPR_AONMIX_BASE_NS, SRC_XSPR_BBSMMIX_BASE_NS, SRC_XSPR_CCMSRCGPCMIX_BASE_NS, SRC_XSPR_CORTEXMIX_CORE0_BASE_NS, SRC_XSPR_CORTEXMIX_CORE1_BASE_NS, SRC_XSPR_CORTEXMIX_CORE2_BASE_NS, SRC_XSPR_CORTEXMIX_CORE3_BASE_NS, SRC_XSPR_CORTEXMIX_PLATFORM_BASE_NS, SRC_XSPR_DDRMIX_BASE_NS, SRC_XSPR_DISPLAYMIX_BASE_NS, SRC_XSPR_HSIOMIX_TOP_BASE_NS, SRC_XSPR_HSIOMIX_WAON_BASE_NS, SRC_XSPR_M70MIX_BASE_NS, SRC_XSPR_M71MIX_BASE_NS, SRC_XSPR_NETCMIX_BASE_NS, SRC_XSPR_NOCMIX_BASE_NS, SRC_XSPR_NPUMIX_BASE_NS, SRC_XSPR_WAKEUPMIX_BASE_NS }
  /** Array initializer of SRC_XSPR peripheral base pointers */
  #define SRC_XSPR_BASE_PTRS_NS                    { SRC_XSPR_ANAMIX_NS, SRC_XSPR_AONMIX_NS, SRC_XSPR_BBSMMIX_NS, SRC_XSPR_CCMSRCGPCMIX_NS, SRC_XSPR_CORTEXMIX_CORE0_NS, SRC_XSPR_CORTEXMIX_CORE1_NS, SRC_XSPR_CORTEXMIX_CORE2_NS, SRC_XSPR_CORTEXMIX_CORE3_NS, SRC_XSPR_CORTEXMIX_PLATFORM_NS, SRC_XSPR_DDRMIX_NS, SRC_XSPR_DISPLAYMIX_NS, SRC_XSPR_HSIOMIX_TOP_NS, SRC_XSPR_HSIOMIX_WAON_NS, SRC_XSPR_M70MIX_NS, SRC_XSPR_M71MIX_NS, SRC_XSPR_NETCMIX_NS, SRC_XSPR_NOCMIX_NS, SRC_XSPR_NPUMIX_NS, SRC_XSPR_WAKEUPMIX_NS }
#else
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
#endif

/* SW_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE (0x5CC70000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE_NS (0x4CC70000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL  ((SW_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_NS ((SW_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE_NS)
  /** Array initializer of SW_GLOBAL peripheral base addresses */
  #define SW_GLOBAL_BASE_ADDRS                     { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE }
  /** Array initializer of SW_GLOBAL peripheral base pointers */
  #define SW_GLOBAL_BASE_PTRS                      { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL }
  /** Array initializer of SW_GLOBAL peripheral base addresses */
  #define SW_GLOBAL_BASE_ADDRS_NS                  { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE_NS }
  /** Array initializer of SW_GLOBAL peripheral base pointers */
  #define SW_GLOBAL_BASE_PTRS_NS                   { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_NS }
#else
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE (0x4CC70000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL  ((SW_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE)
  /** Array initializer of SW_GLOBAL peripheral base addresses */
  #define SW_GLOBAL_BASE_ADDRS                     { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL_BASE }
  /** Array initializer of SW_GLOBAL peripheral base pointers */
  #define SW_GLOBAL_BASE_PTRS                      { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_GLOBAL }
#endif

/* SW_PORT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE (0x5CC10000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE_NS (0x4CC10000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3   ((SW_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_NS ((SW_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE_NS)
  /** Array initializer of SW_PORT peripheral base addresses */
  #define SW_PORT_BASE_ADDRS                       { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE }
  /** Array initializer of SW_PORT peripheral base pointers */
  #define SW_PORT_BASE_PTRS                        { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3 }
  /** Array initializer of SW_PORT peripheral base addresses */
  #define SW_PORT_BASE_ADDRS_NS                    { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE_NS }
  /** Array initializer of SW_PORT peripheral base pointers */
  #define SW_PORT_BASE_PTRS_NS                     { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_NS }
#else
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE (0x4CC10000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3   ((SW_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE)
  /** Array initializer of SW_PORT peripheral base addresses */
  #define SW_PORT_BASE_ADDRS                       { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3_BASE }
  /** Array initializer of SW_PORT peripheral base pointers */
  #define SW_PORT_BASE_PTRS                        { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PORT3 }
#endif

/* SW_PSEUDO_MAC_PORT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE (0x5CC11000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE_NS (0x4CC11000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 ((SW_PSEUDO_MAC_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_NS ((SW_PSEUDO_MAC_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE_NS)
  /** Array initializer of SW_PSEUDO_MAC_PORT peripheral base addresses */
  #define SW_PSEUDO_MAC_PORT_BASE_ADDRS            { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE }
  /** Array initializer of SW_PSEUDO_MAC_PORT peripheral base pointers */
  #define SW_PSEUDO_MAC_PORT_BASE_PTRS             { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 }
  /** Array initializer of SW_PSEUDO_MAC_PORT peripheral base addresses */
  #define SW_PSEUDO_MAC_PORT_BASE_ADDRS_NS         { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE_NS }
  /** Array initializer of SW_PSEUDO_MAC_PORT peripheral base pointers */
  #define SW_PSEUDO_MAC_PORT_BASE_PTRS_NS          { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_NS }
#else
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE (0x4CC11000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 ((SW_PSEUDO_MAC_PORT_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE)
  /** Array initializer of SW_PSEUDO_MAC_PORT peripheral base addresses */
  #define SW_PSEUDO_MAC_PORT_BASE_ADDRS            { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3_BASE }
  /** Array initializer of SW_PSEUDO_MAC_PORT peripheral base pointers */
  #define SW_PSEUDO_MAC_PORT_BASE_PTRS             { NETC__ECAM_PCI_EMDIO0_BAR_0__SW0_PSEUDO_MAC_PORT3 }
#endif

/* SYS_CTR_COMPARE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base address */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE_BASE      (0x542A0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base address */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE_BASE_NS   (0x442A0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base pointer */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE           ((SYS_CTR_COMPARE_Type *)AON__SYS_CTR1__SYS_CTR_COMPARE_BASE)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base pointer */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE_NS        ((SYS_CTR_COMPARE_Type *)AON__SYS_CTR1__SYS_CTR_COMPARE_BASE_NS)
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS               { AON__SYS_CTR1__SYS_CTR_COMPARE_BASE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS                { AON__SYS_CTR1__SYS_CTR_COMPARE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS_NS            { AON__SYS_CTR1__SYS_CTR_COMPARE_BASE_NS }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS_NS             { AON__SYS_CTR1__SYS_CTR_COMPARE_NS }
#else
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base address */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE_BASE      (0x442A0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base pointer */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE           ((SYS_CTR_COMPARE_Type *)AON__SYS_CTR1__SYS_CTR_COMPARE_BASE)
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS               { AON__SYS_CTR1__SYS_CTR_COMPARE_BASE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS                { AON__SYS_CTR1__SYS_CTR_COMPARE }
#endif

/* SYS_CTR_CONTROL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__SYS_CTR1__SYS_CTR_CONTROL base address */
  #define AON__SYS_CTR1__SYS_CTR_CONTROL_BASE      (0x54290000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_CONTROL base address */
  #define AON__SYS_CTR1__SYS_CTR_CONTROL_BASE_NS   (0x44290000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_CONTROL base pointer */
  #define AON__SYS_CTR1__SYS_CTR_CONTROL           ((SYS_CTR_CONTROL_Type *)AON__SYS_CTR1__SYS_CTR_CONTROL_BASE)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_CONTROL base pointer */
  #define AON__SYS_CTR1__SYS_CTR_CONTROL_NS        ((SYS_CTR_CONTROL_Type *)AON__SYS_CTR1__SYS_CTR_CONTROL_BASE_NS)
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS               { AON__SYS_CTR1__SYS_CTR_CONTROL_BASE }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS                { AON__SYS_CTR1__SYS_CTR_CONTROL }
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS_NS            { AON__SYS_CTR1__SYS_CTR_CONTROL_BASE_NS }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS_NS             { AON__SYS_CTR1__SYS_CTR_CONTROL_NS }
#else
  /** Peripheral AON__SYS_CTR1__SYS_CTR_CONTROL base address */
  #define AON__SYS_CTR1__SYS_CTR_CONTROL_BASE      (0x44290000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_CONTROL base pointer */
  #define AON__SYS_CTR1__SYS_CTR_CONTROL           ((SYS_CTR_CONTROL_Type *)AON__SYS_CTR1__SYS_CTR_CONTROL_BASE)
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS               { AON__SYS_CTR1__SYS_CTR_CONTROL_BASE }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS                { AON__SYS_CTR1__SYS_CTR_CONTROL }
#endif

/* SYS_CTR_READ - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base address */
  #define AON__SYS_CTR1__SYS_CTR_READ_BASE         (0x542B0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base address */
  #define AON__SYS_CTR1__SYS_CTR_READ_BASE_NS      (0x442B0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base pointer */
  #define AON__SYS_CTR1__SYS_CTR_READ              ((SYS_CTR_READ_Type *)AON__SYS_CTR1__SYS_CTR_READ_BASE)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base pointer */
  #define AON__SYS_CTR1__SYS_CTR_READ_NS           ((SYS_CTR_READ_Type *)AON__SYS_CTR1__SYS_CTR_READ_BASE_NS)
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS                  { AON__SYS_CTR1__SYS_CTR_READ_BASE }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS                   { AON__SYS_CTR1__SYS_CTR_READ }
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS_NS               { AON__SYS_CTR1__SYS_CTR_READ_BASE_NS }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS_NS                { AON__SYS_CTR1__SYS_CTR_READ_NS }
#else
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base address */
  #define AON__SYS_CTR1__SYS_CTR_READ_BASE         (0x442B0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base pointer */
  #define AON__SYS_CTR1__SYS_CTR_READ              ((SYS_CTR_READ_Type *)AON__SYS_CTR1__SYS_CTR_READ_BASE)
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS                  { AON__SYS_CTR1__SYS_CTR_READ_BASE }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS                   { AON__SYS_CTR1__SYS_CTR_READ }
#endif

/* SerDes_SS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE1__SERDES_SS base address */
  #define HSIO__PCIE1__SERDES_SS_BASE              (0x5C340000u)
  /** Peripheral HSIO__PCIE1__SERDES_SS base address */
  #define HSIO__PCIE1__SERDES_SS_BASE_NS           (0x4C340000u)
  /** Peripheral HSIO__PCIE1__SERDES_SS base pointer */
  #define HSIO__PCIE1__SERDES_SS                   ((SerDes_SS_Type *)HSIO__PCIE1__SERDES_SS_BASE)
  /** Peripheral HSIO__PCIE1__SERDES_SS base pointer */
  #define HSIO__PCIE1__SERDES_SS_NS                ((SerDes_SS_Type *)HSIO__PCIE1__SERDES_SS_BASE_NS)
  /** Peripheral HSIO__PCIE2__SERDES_SS base address */
  #define HSIO__PCIE2__SERDES_SS_BASE              (0x5C3C0000u)
  /** Peripheral HSIO__PCIE2__SERDES_SS base address */
  #define HSIO__PCIE2__SERDES_SS_BASE_NS           (0x4C3C0000u)
  /** Peripheral HSIO__PCIE2__SERDES_SS base pointer */
  #define HSIO__PCIE2__SERDES_SS                   ((SerDes_SS_Type *)HSIO__PCIE2__SERDES_SS_BASE)
  /** Peripheral HSIO__PCIE2__SERDES_SS base pointer */
  #define HSIO__PCIE2__SERDES_SS_NS                ((SerDes_SS_Type *)HSIO__PCIE2__SERDES_SS_BASE_NS)
  /** Array initializer of SerDes_SS peripheral base addresses */
  #define SerDes_SS_BASE_ADDRS                     { HSIO__PCIE1__SERDES_SS_BASE, HSIO__PCIE2__SERDES_SS_BASE }
  /** Array initializer of SerDes_SS peripheral base pointers */
  #define SerDes_SS_BASE_PTRS                      { HSIO__PCIE1__SERDES_SS, HSIO__PCIE2__SERDES_SS }
  /** Array initializer of SerDes_SS peripheral base addresses */
  #define SerDes_SS_BASE_ADDRS_NS                  { HSIO__PCIE1__SERDES_SS_BASE_NS, HSIO__PCIE2__SERDES_SS_BASE_NS }
  /** Array initializer of SerDes_SS peripheral base pointers */
  #define SerDes_SS_BASE_PTRS_NS                   { HSIO__PCIE1__SERDES_SS_NS, HSIO__PCIE2__SERDES_SS_NS }
#else
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
#endif

/* TCM_ECC_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base address */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE (0x54420000u)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base address */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE_NS (0x44420000u)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base pointer */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM   ((TCM_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base pointer */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_NS ((TCM_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE_NS)
  /** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base address */
  #define NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE (0x5D0A0000u)
  /** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base address */
  #define NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE_NS (0x4D0A0000u)
  /** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base pointer */
  #define NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM  ((TCM_ECC_MCM_Type *)NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE)
  /** Peripheral NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base pointer */
  #define NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_NS ((TCM_ECC_MCM_Type *)NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE_NS)
  /** Array initializer of TCM_ECC_MCM peripheral base addresses */
  #define TCM_ECC_MCM_BASE_ADDRS                   { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE, NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE }
  /** Array initializer of TCM_ECC_MCM peripheral base pointers */
  #define TCM_ECC_MCM_BASE_PTRS                    { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM, NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM }
  /** Array initializer of TCM_ECC_MCM peripheral base addresses */
  #define TCM_ECC_MCM_BASE_ADDRS_NS                { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE_NS, NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE_NS }
  /** Array initializer of TCM_ECC_MCM peripheral base pointers */
  #define TCM_ECC_MCM_BASE_PTRS_NS                 { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_NS, NETC__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_NS }
#else
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
#endif

/* TMPSNS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CORTEXA__TMPSNS base address */
  #define CORTEXA__TMPSNS_BASE                     (0x5A440000u)
  /** Peripheral CORTEXA__TMPSNS base address */
  #define CORTEXA__TMPSNS_BASE_NS                  (0x4A440000u)
  /** Peripheral CORTEXA__TMPSNS base pointer */
  #define CORTEXA__TMPSNS                          ((TMPSNS_Type *)CORTEXA__TMPSNS_BASE)
  /** Peripheral CORTEXA__TMPSNS base pointer */
  #define CORTEXA__TMPSNS_NS                       ((TMPSNS_Type *)CORTEXA__TMPSNS_BASE_NS)
  /** Peripheral TMPSNS base address */
  #define TMPSNS_BASE                              (0x54482000u)
  /** Peripheral TMPSNS base address */
  #define TMPSNS_BASE_NS                           (0x44482000u)
  /** Peripheral TMPSNS base pointer */
  #define TMPSNS                                   ((TMPSNS_Type *)TMPSNS_BASE)
  /** Peripheral TMPSNS base pointer */
  #define TMPSNS_NS                                ((TMPSNS_Type *)TMPSNS_BASE_NS)
  /** Array initializer of TMPSNS peripheral base addresses */
  #define TMPSNS_BASE_ADDRS                        { CORTEXA__TMPSNS_BASE, TMPSNS_BASE }
  /** Array initializer of TMPSNS peripheral base pointers */
  #define TMPSNS_BASE_PTRS                         { CORTEXA__TMPSNS, TMPSNS }
  /** Array initializer of TMPSNS peripheral base addresses */
  #define TMPSNS_BASE_ADDRS_NS                     { CORTEXA__TMPSNS_BASE_NS, TMPSNS_BASE_NS }
  /** Array initializer of TMPSNS peripheral base pointers */
  #define TMPSNS_BASE_PTRS_NS                      { CORTEXA__TMPSNS_NS, TMPSNS_NS }
#else
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
#endif

/* TMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TMR1 base address */
  #define TMR1_BASE                                (0x528D0000u)
  /** Peripheral TMR1 base address */
  #define TMR1_BASE_NS                             (0x428D0000u)
  /** Peripheral TMR1 base pointer */
  #define TMR1                                     ((TMR_Type *)TMR1_BASE)
  /** Peripheral TMR1 base pointer */
  #define TMR1_NS                                  ((TMR_Type *)TMR1_BASE_NS)
  /** Peripheral TMR2 base address */
  #define TMR2_BASE                                (0x528E0000u)
  /** Peripheral TMR2 base address */
  #define TMR2_BASE_NS                             (0x428E0000u)
  /** Peripheral TMR2 base pointer */
  #define TMR2                                     ((TMR_Type *)TMR2_BASE)
  /** Peripheral TMR2 base pointer */
  #define TMR2_NS                                  ((TMR_Type *)TMR2_BASE_NS)
  /** Peripheral TMR3 base address */
  #define TMR3_BASE                                (0x528F0000u)
  /** Peripheral TMR3 base address */
  #define TMR3_BASE_NS                             (0x428F0000u)
  /** Peripheral TMR3 base pointer */
  #define TMR3                                     ((TMR_Type *)TMR3_BASE)
  /** Peripheral TMR3 base pointer */
  #define TMR3_NS                                  ((TMR_Type *)TMR3_BASE_NS)
  /** Peripheral TMR4 base address */
  #define TMR4_BASE                                (0x52900000u)
  /** Peripheral TMR4 base address */
  #define TMR4_BASE_NS                             (0x42900000u)
  /** Peripheral TMR4 base pointer */
  #define TMR4                                     ((TMR_Type *)TMR4_BASE)
  /** Peripheral TMR4 base pointer */
  #define TMR4_NS                                  ((TMR_Type *)TMR4_BASE_NS)
  /** Peripheral TMR5 base address */
  #define TMR5_BASE                                (0x52910000u)
  /** Peripheral TMR5 base address */
  #define TMR5_BASE_NS                             (0x42910000u)
  /** Peripheral TMR5 base pointer */
  #define TMR5                                     ((TMR_Type *)TMR5_BASE)
  /** Peripheral TMR5 base pointer */
  #define TMR5_NS                                  ((TMR_Type *)TMR5_BASE_NS)
  /** Peripheral TMR6 base address */
  #define TMR6_BASE                                (0x52920000u)
  /** Peripheral TMR6 base address */
  #define TMR6_BASE_NS                             (0x42920000u)
  /** Peripheral TMR6 base pointer */
  #define TMR6                                     ((TMR_Type *)TMR6_BASE)
  /** Peripheral TMR6 base pointer */
  #define TMR6_NS                                  ((TMR_Type *)TMR6_BASE_NS)
  /** Peripheral TMR7 base address */
  #define TMR7_BASE                                (0x52930000u)
  /** Peripheral TMR7 base address */
  #define TMR7_BASE_NS                             (0x42930000u)
  /** Peripheral TMR7 base pointer */
  #define TMR7                                     ((TMR_Type *)TMR7_BASE)
  /** Peripheral TMR7 base pointer */
  #define TMR7_NS                                  ((TMR_Type *)TMR7_BASE_NS)
  /** Peripheral TMR8 base address */
  #define TMR8_BASE                                (0x52940000u)
  /** Peripheral TMR8 base address */
  #define TMR8_BASE_NS                             (0x42940000u)
  /** Peripheral TMR8 base pointer */
  #define TMR8                                     ((TMR_Type *)TMR8_BASE)
  /** Peripheral TMR8 base pointer */
  #define TMR8_NS                                  ((TMR_Type *)TMR8_BASE_NS)
  /** Array initializer of TMR peripheral base addresses */
  #define TMR_BASE_ADDRS                           { TMR1_BASE, TMR2_BASE, TMR3_BASE, TMR4_BASE, TMR5_BASE, TMR6_BASE, TMR7_BASE, TMR8_BASE }
  /** Array initializer of TMR peripheral base pointers */
  #define TMR_BASE_PTRS                            { TMR1, TMR2, TMR3, TMR4, TMR5, TMR6, TMR7, TMR8 }
  /** Array initializer of TMR peripheral base addresses */
  #define TMR_BASE_ADDRS_NS                        { TMR1_BASE_NS, TMR2_BASE_NS, TMR3_BASE_NS, TMR4_BASE_NS, TMR5_BASE_NS, TMR6_BASE_NS, TMR7_BASE_NS, TMR8_BASE_NS }
  /** Array initializer of TMR peripheral base pointers */
  #define TMR_BASE_PTRS_NS                         { TMR1_NS, TMR2_NS, TMR3_NS, TMR4_NS, TMR5_NS, TMR6_NS, TMR7_NS, TMR8_NS }
#else
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
#endif

/* TMR_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL_BASE (0x5CDB0000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL_BASE_NS (0x4CDB0000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL ((TMR_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL_NS ((TMR_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL_BASE_NS)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL_BASE (0x5CDD0000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL_BASE_NS (0x4CDD0000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL ((TMR_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL_NS ((TMR_GLOBAL_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL_BASE_NS)
  /** Array initializer of TMR_GLOBAL peripheral base addresses */
  #define TMR_GLOBAL_BASE_ADDRS                    { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL_BASE }
  /** Array initializer of TMR_GLOBAL peripheral base pointers */
  #define TMR_GLOBAL_BASE_PTRS                     { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL }
  /** Array initializer of TMR_GLOBAL peripheral base addresses */
  #define TMR_GLOBAL_BASE_ADDRS_NS                 { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL_BASE_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL_BASE_NS }
  /** Array initializer of TMR_GLOBAL peripheral base pointers */
  #define TMR_GLOBAL_BASE_PTRS_NS                  { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_GLOBAL_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_GLOBAL_NS }
#else
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
#endif

/* TMR_PCI_HDR_TYPE0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0_BASE (0x5CB01000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0_BASE_NS (0x4CB01000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0 ((TMR_PCI_HDR_TYPE0_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0_NS ((TMR_PCI_HDR_TYPE0_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0_BASE (0x5CB81000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0 base address */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0_BASE_NS (0x4CB81000u)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0 ((TMR_PCI_HDR_TYPE0_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0 base pointer */
  #define NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0_NS ((TMR_PCI_HDR_TYPE0_Type *)NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base addresses */
  #define TMR_PCI_HDR_TYPE0_BASE_ADDRS             { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0_BASE, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0_BASE }
  /** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base pointers */
  #define TMR_PCI_HDR_TYPE0_BASE_PTRS              { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0 }
  /** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base addresses */
  #define TMR_PCI_HDR_TYPE0_BASE_ADDRS_NS          { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0_BASE_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base pointers */
  #define TMR_PCI_HDR_TYPE0_BASE_PTRS_NS           { NETC__ECAM_PCI_EMDIO0_BAR_0__TMR1_PCI_HDR_TYPE0_NS, NETC__ECAM_PCI_EMDIO0_BAR_0__TMR2_PCI_HDR_TYPE0_NS }
#else
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
#endif

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
  /** Peripheral TPM4 base address */
  #define TPM4_BASE                                (0x524F0000u)
  /** Peripheral TPM4 base address */
  #define TPM4_BASE_NS                             (0x424F0000u)
  /** Peripheral TPM4 base pointer */
  #define TPM4                                     ((TPM_Type *)TPM4_BASE)
  /** Peripheral TPM4 base pointer */
  #define TPM4_NS                                  ((TPM_Type *)TPM4_BASE_NS)
  /** Peripheral TPM5 base address */
  #define TPM5_BASE                                (0x52500000u)
  /** Peripheral TPM5 base address */
  #define TPM5_BASE_NS                             (0x42500000u)
  /** Peripheral TPM5 base pointer */
  #define TPM5                                     ((TPM_Type *)TPM5_BASE)
  /** Peripheral TPM5 base pointer */
  #define TPM5_NS                                  ((TPM_Type *)TPM5_BASE_NS)
  /** Peripheral TPM6 base address */
  #define TPM6_BASE                                (0x52510000u)
  /** Peripheral TPM6 base address */
  #define TPM6_BASE_NS                             (0x42510000u)
  /** Peripheral TPM6 base pointer */
  #define TPM6                                     ((TPM_Type *)TPM6_BASE)
  /** Peripheral TPM6 base pointer */
  #define TPM6_NS                                  ((TPM_Type *)TPM6_BASE_NS)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { 0u, TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { (TPM_Type *)0u, TPM1, TPM2, TPM3, TPM4, TPM5, TPM6 }
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS_NS                        { 0u, TPM1_BASE_NS, TPM2_BASE_NS, TPM3_BASE_NS, TPM4_BASE_NS, TPM5_BASE_NS, TPM6_BASE_NS }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS_NS                         { (TPM_Type *)0u, TPM1_NS, TPM2_NS, TPM3_NS, TPM4_NS, TPM5_NS, TPM6_NS }
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
#endif
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { NotAvail_IRQn, TPM1_IRQn, TPM2_IRQn, TPM3_IRQn, TPM4_IRQn, TPM5_IRQn, TPM6_IRQn }

/* TRDC_MGR_WKUP1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__TRDC_MGR_WKUP1 base address */
  #define WAKEUP__TRDC_MGR_WKUP1_BASE              (0x52460000u)
  /** Peripheral WAKEUP__TRDC_MGR_WKUP1 base address */
  #define WAKEUP__TRDC_MGR_WKUP1_BASE_NS           (0x42460000u)
  /** Peripheral WAKEUP__TRDC_MGR_WKUP1 base pointer */
  #define WAKEUP__TRDC_MGR_WKUP1                   ((TRDC_MGR_WKUP1_Type *)WAKEUP__TRDC_MGR_WKUP1_BASE)
  /** Peripheral WAKEUP__TRDC_MGR_WKUP1 base pointer */
  #define WAKEUP__TRDC_MGR_WKUP1_NS                ((TRDC_MGR_WKUP1_Type *)WAKEUP__TRDC_MGR_WKUP1_BASE_NS)
  /** Array initializer of TRDC_MGR_WKUP1 peripheral base addresses */
  #define TRDC_MGR_WKUP1_BASE_ADDRS                { WAKEUP__TRDC_MGR_WKUP1_BASE }
  /** Array initializer of TRDC_MGR_WKUP1 peripheral base pointers */
  #define TRDC_MGR_WKUP1_BASE_PTRS                 { WAKEUP__TRDC_MGR_WKUP1 }
  /** Array initializer of TRDC_MGR_WKUP1 peripheral base addresses */
  #define TRDC_MGR_WKUP1_BASE_ADDRS_NS             { WAKEUP__TRDC_MGR_WKUP1_BASE_NS }
  /** Array initializer of TRDC_MGR_WKUP1 peripheral base pointers */
  #define TRDC_MGR_WKUP1_BASE_PTRS_NS              { WAKEUP__TRDC_MGR_WKUP1_NS }
#else
  /** Peripheral WAKEUP__TRDC_MGR_WKUP1 base address */
  #define WAKEUP__TRDC_MGR_WKUP1_BASE              (0x42460000u)
  /** Peripheral WAKEUP__TRDC_MGR_WKUP1 base pointer */
  #define WAKEUP__TRDC_MGR_WKUP1                   ((TRDC_MGR_WKUP1_Type *)WAKEUP__TRDC_MGR_WKUP1_BASE)
  /** Array initializer of TRDC_MGR_WKUP1 peripheral base addresses */
  #define TRDC_MGR_WKUP1_BASE_ADDRS                { WAKEUP__TRDC_MGR_WKUP1_BASE }
  /** Array initializer of TRDC_MGR_WKUP1 peripheral base pointers */
  #define TRDC_MGR_WKUP1_BASE_PTRS                 { WAKEUP__TRDC_MGR_WKUP1 }
#endif

/* TRDC_MGR_WKUP2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__TRDC_MGR_WKUP2 base address */
  #define WAKEUP__TRDC_MGR_WKUP2_BASE              (0x52800000u)
  /** Peripheral WAKEUP__TRDC_MGR_WKUP2 base address */
  #define WAKEUP__TRDC_MGR_WKUP2_BASE_NS           (0x42800000u)
  /** Peripheral WAKEUP__TRDC_MGR_WKUP2 base pointer */
  #define WAKEUP__TRDC_MGR_WKUP2                   ((TRDC_MGR_WKUP2_Type *)WAKEUP__TRDC_MGR_WKUP2_BASE)
  /** Peripheral WAKEUP__TRDC_MGR_WKUP2 base pointer */
  #define WAKEUP__TRDC_MGR_WKUP2_NS                ((TRDC_MGR_WKUP2_Type *)WAKEUP__TRDC_MGR_WKUP2_BASE_NS)
  /** Array initializer of TRDC_MGR_WKUP2 peripheral base addresses */
  #define TRDC_MGR_WKUP2_BASE_ADDRS                { WAKEUP__TRDC_MGR_WKUP2_BASE }
  /** Array initializer of TRDC_MGR_WKUP2 peripheral base pointers */
  #define TRDC_MGR_WKUP2_BASE_PTRS                 { WAKEUP__TRDC_MGR_WKUP2 }
  /** Array initializer of TRDC_MGR_WKUP2 peripheral base addresses */
  #define TRDC_MGR_WKUP2_BASE_ADDRS_NS             { WAKEUP__TRDC_MGR_WKUP2_BASE_NS }
  /** Array initializer of TRDC_MGR_WKUP2 peripheral base pointers */
  #define TRDC_MGR_WKUP2_BASE_PTRS_NS              { WAKEUP__TRDC_MGR_WKUP2_NS }
#else
  /** Peripheral WAKEUP__TRDC_MGR_WKUP2 base address */
  #define WAKEUP__TRDC_MGR_WKUP2_BASE              (0x42800000u)
  /** Peripheral WAKEUP__TRDC_MGR_WKUP2 base pointer */
  #define WAKEUP__TRDC_MGR_WKUP2                   ((TRDC_MGR_WKUP2_Type *)WAKEUP__TRDC_MGR_WKUP2_BASE)
  /** Array initializer of TRDC_MGR_WKUP2 peripheral base addresses */
  #define TRDC_MGR_WKUP2_BASE_ADDRS                { WAKEUP__TRDC_MGR_WKUP2_BASE }
  /** Array initializer of TRDC_MGR_WKUP2 peripheral base pointers */
  #define TRDC_MGR_WKUP2_BASE_PTRS                 { WAKEUP__TRDC_MGR_WKUP2 }
#endif

/* TSTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TSTMR1_A base address */
  #define TSTMR1_A_BASE                            (0x542C0000u)
  /** Peripheral TSTMR1_A base address */
  #define TSTMR1_A_BASE_NS                         (0x442C0000u)
  /** Peripheral TSTMR1_A base pointer */
  #define TSTMR1_A                                 ((TSTMR_Type *)TSTMR1_A_BASE)
  /** Peripheral TSTMR1_A base pointer */
  #define TSTMR1_A_NS                              ((TSTMR_Type *)TSTMR1_A_BASE_NS)
  /** Peripheral TSTMR2_A base address */
  #define TSTMR2_A_BASE                            (0x52480000u)
  /** Peripheral TSTMR2_A base address */
  #define TSTMR2_A_BASE_NS                         (0x42480000u)
  /** Peripheral TSTMR2_A base pointer */
  #define TSTMR2_A                                 ((TSTMR_Type *)TSTMR2_A_BASE)
  /** Peripheral TSTMR2_A base pointer */
  #define TSTMR2_A_NS                              ((TSTMR_Type *)TSTMR2_A_BASE_NS)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { TSTMR1_A_BASE, TSTMR2_A_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { TSTMR1_A, TSTMR2_A }
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS_NS                      { TSTMR1_A_BASE_NS, TSTMR2_A_BASE_NS }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS_NS                       { TSTMR1_A_NS, TSTMR2_A_NS }
#else
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
#endif

/* USB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__USB_2_0__USB_OTG1 base address */
  #define HSIO__USB_2_0__USB_OTG1_BASE             (0x5C200000u)
  /** Peripheral HSIO__USB_2_0__USB_OTG1 base address */
  #define HSIO__USB_2_0__USB_OTG1_BASE_NS          (0x4C200000u)
  /** Peripheral HSIO__USB_2_0__USB_OTG1 base pointer */
  #define HSIO__USB_2_0__USB_OTG1                  ((USB_Type *)HSIO__USB_2_0__USB_OTG1_BASE)
  /** Peripheral HSIO__USB_2_0__USB_OTG1 base pointer */
  #define HSIO__USB_2_0__USB_OTG1_NS               ((USB_Type *)HSIO__USB_2_0__USB_OTG1_BASE_NS)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { HSIO__USB_2_0__USB_OTG1_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { HSIO__USB_2_0__USB_OTG1 }
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS_NS                        { HSIO__USB_2_0__USB_OTG1_BASE_NS }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS_NS                         { HSIO__USB_2_0__USB_OTG1_NS }
#else
  /** Peripheral HSIO__USB_2_0__USB_OTG1 base address */
  #define HSIO__USB_2_0__USB_OTG1_BASE             (0x4C200000u)
  /** Peripheral HSIO__USB_2_0__USB_OTG1 base pointer */
  #define HSIO__USB_2_0__USB_OTG1                  ((USB_Type *)HSIO__USB_2_0__USB_OTG1_BASE)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { HSIO__USB_2_0__USB_OTG1_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { HSIO__USB_2_0__USB_OTG1 }
#endif

/* USB3_GLUE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__USB_3_01__GLUE base address */
  #define HSIO__USB_3_01__GLUE_BASE                (0x5C1F0000u)
  /** Peripheral HSIO__USB_3_01__GLUE base address */
  #define HSIO__USB_3_01__GLUE_BASE_NS             (0x4C1F0000u)
  /** Peripheral HSIO__USB_3_01__GLUE base pointer */
  #define HSIO__USB_3_01__GLUE                     ((USB3_GLUE_Type *)HSIO__USB_3_01__GLUE_BASE)
  /** Peripheral HSIO__USB_3_01__GLUE base pointer */
  #define HSIO__USB_3_01__GLUE_NS                  ((USB3_GLUE_Type *)HSIO__USB_3_01__GLUE_BASE_NS)
  /** Array initializer of USB3_GLUE peripheral base addresses */
  #define USB3_GLUE_BASE_ADDRS                     { HSIO__USB_3_01__GLUE_BASE }
  /** Array initializer of USB3_GLUE peripheral base pointers */
  #define USB3_GLUE_BASE_PTRS                      { HSIO__USB_3_01__GLUE }
  /** Array initializer of USB3_GLUE peripheral base addresses */
  #define USB3_GLUE_BASE_ADDRS_NS                  { HSIO__USB_3_01__GLUE_BASE_NS }
  /** Array initializer of USB3_GLUE peripheral base pointers */
  #define USB3_GLUE_BASE_PTRS_NS                   { HSIO__USB_3_01__GLUE_NS }
#else
  /** Peripheral HSIO__USB_3_01__GLUE base address */
  #define HSIO__USB_3_01__GLUE_BASE                (0x4C1F0000u)
  /** Peripheral HSIO__USB_3_01__GLUE base pointer */
  #define HSIO__USB_3_01__GLUE                     ((USB3_GLUE_Type *)HSIO__USB_3_01__GLUE_BASE)
  /** Array initializer of USB3_GLUE peripheral base addresses */
  #define USB3_GLUE_BASE_ADDRS                     { HSIO__USB_3_01__GLUE_BASE }
  /** Array initializer of USB3_GLUE peripheral base pointers */
  #define USB3_GLUE_BASE_PTRS                      { HSIO__USB_3_01__GLUE }
#endif

/* USB3_PHY_TCA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__USB_3_0_PHY__TCA base address */
  #define HSIO__USB_3_0_PHY__TCA_BASE              (0x5C1FC000u)
  /** Peripheral HSIO__USB_3_0_PHY__TCA base address */
  #define HSIO__USB_3_0_PHY__TCA_BASE_NS           (0x4C1FC000u)
  /** Peripheral HSIO__USB_3_0_PHY__TCA base pointer */
  #define HSIO__USB_3_0_PHY__TCA                   ((USB3_PHY_TCA_Type *)HSIO__USB_3_0_PHY__TCA_BASE)
  /** Peripheral HSIO__USB_3_0_PHY__TCA base pointer */
  #define HSIO__USB_3_0_PHY__TCA_NS                ((USB3_PHY_TCA_Type *)HSIO__USB_3_0_PHY__TCA_BASE_NS)
  /** Array initializer of USB3_PHY_TCA peripheral base addresses */
  #define USB3_PHY_TCA_BASE_ADDRS                  { HSIO__USB_3_0_PHY__TCA_BASE }
  /** Array initializer of USB3_PHY_TCA peripheral base pointers */
  #define USB3_PHY_TCA_BASE_PTRS                   { HSIO__USB_3_0_PHY__TCA }
  /** Array initializer of USB3_PHY_TCA peripheral base addresses */
  #define USB3_PHY_TCA_BASE_ADDRS_NS               { HSIO__USB_3_0_PHY__TCA_BASE_NS }
  /** Array initializer of USB3_PHY_TCA peripheral base pointers */
  #define USB3_PHY_TCA_BASE_PTRS_NS                { HSIO__USB_3_0_PHY__TCA_NS }
#else
  /** Peripheral HSIO__USB_3_0_PHY__TCA base address */
  #define HSIO__USB_3_0_PHY__TCA_BASE              (0x4C1FC000u)
  /** Peripheral HSIO__USB_3_0_PHY__TCA base pointer */
  #define HSIO__USB_3_0_PHY__TCA                   ((USB3_PHY_TCA_Type *)HSIO__USB_3_0_PHY__TCA_BASE)
  /** Array initializer of USB3_PHY_TCA peripheral base addresses */
  #define USB3_PHY_TCA_BASE_ADDRS                  { HSIO__USB_3_0_PHY__TCA_BASE }
  /** Array initializer of USB3_PHY_TCA peripheral base pointers */
  #define USB3_PHY_TCA_BASE_PTRS                   { HSIO__USB_3_0_PHY__TCA }
#endif

/* USBNC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__USB_2_0__USBNC_OTG1 base address */
  #define HSIO__USB_2_0__USBNC_OTG1_BASE           (0x5C200200u)
  /** Peripheral HSIO__USB_2_0__USBNC_OTG1 base address */
  #define HSIO__USB_2_0__USBNC_OTG1_BASE_NS        (0x4C200200u)
  /** Peripheral HSIO__USB_2_0__USBNC_OTG1 base pointer */
  #define HSIO__USB_2_0__USBNC_OTG1                ((USBNC_Type *)HSIO__USB_2_0__USBNC_OTG1_BASE)
  /** Peripheral HSIO__USB_2_0__USBNC_OTG1 base pointer */
  #define HSIO__USB_2_0__USBNC_OTG1_NS             ((USBNC_Type *)HSIO__USB_2_0__USBNC_OTG1_BASE_NS)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { HSIO__USB_2_0__USBNC_OTG1_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { HSIO__USB_2_0__USBNC_OTG1 }
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS_NS                      { HSIO__USB_2_0__USBNC_OTG1_BASE_NS }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS_NS                       { HSIO__USB_2_0__USBNC_OTG1_NS }
#else
  /** Peripheral HSIO__USB_2_0__USBNC_OTG1 base address */
  #define HSIO__USB_2_0__USBNC_OTG1_BASE           (0x4C200200u)
  /** Peripheral HSIO__USB_2_0__USBNC_OTG1 base pointer */
  #define HSIO__USB_2_0__USBNC_OTG1                ((USBNC_Type *)HSIO__USB_2_0__USBNC_OTG1_BASE)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { HSIO__USB_2_0__USBNC_OTG1_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { HSIO__USB_2_0__USBNC_OTG1 }
#endif

/* WAKEUP_ATU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__ATUA base address */
  #define WAKEUP__ATUA_BASE                        (0x52760000u)
  /** Peripheral WAKEUP__ATUA base address */
  #define WAKEUP__ATUA_BASE_NS                     (0x42760000u)
  /** Peripheral WAKEUP__ATUA base pointer */
  #define WAKEUP__ATUA                             ((WAKEUP_ATU_Type *)WAKEUP__ATUA_BASE)
  /** Peripheral WAKEUP__ATUA base pointer */
  #define WAKEUP__ATUA_NS                          ((WAKEUP_ATU_Type *)WAKEUP__ATUA_BASE_NS)
  /** Peripheral WAKEUP__ATUM base address */
  #define WAKEUP__ATUM_BASE                        (0x52770000u)
  /** Peripheral WAKEUP__ATUM base address */
  #define WAKEUP__ATUM_BASE_NS                     (0x42770000u)
  /** Peripheral WAKEUP__ATUM base pointer */
  #define WAKEUP__ATUM                             ((WAKEUP_ATU_Type *)WAKEUP__ATUM_BASE)
  /** Peripheral WAKEUP__ATUM base pointer */
  #define WAKEUP__ATUM_NS                          ((WAKEUP_ATU_Type *)WAKEUP__ATUM_BASE_NS)
  /** Peripheral WAKEUP__ATUM33 base address */
  #define WAKEUP__ATUM33_BASE                      (0x527D0000u)
  /** Peripheral WAKEUP__ATUM33 base address */
  #define WAKEUP__ATUM33_BASE_NS                   (0x427D0000u)
  /** Peripheral WAKEUP__ATUM33 base pointer */
  #define WAKEUP__ATUM33                           ((WAKEUP_ATU_Type *)WAKEUP__ATUM33_BASE)
  /** Peripheral WAKEUP__ATUM33 base pointer */
  #define WAKEUP__ATUM33_NS                        ((WAKEUP_ATU_Type *)WAKEUP__ATUM33_BASE_NS)
  /** Peripheral WAKEUP__ATU_M70 base address */
  #define WAKEUP__ATU_M70_BASE                     (0x52A90000u)
  /** Peripheral WAKEUP__ATU_M70 base address */
  #define WAKEUP__ATU_M70_BASE_NS                  (0x42A90000u)
  /** Peripheral WAKEUP__ATU_M70 base pointer */
  #define WAKEUP__ATU_M70                          ((WAKEUP_ATU_Type *)WAKEUP__ATU_M70_BASE)
  /** Peripheral WAKEUP__ATU_M70 base pointer */
  #define WAKEUP__ATU_M70_NS                       ((WAKEUP_ATU_Type *)WAKEUP__ATU_M70_BASE_NS)
  /** Peripheral WAKEUP__ATU_M71 base address */
  #define WAKEUP__ATU_M71_BASE                     (0x52AA0000u)
  /** Peripheral WAKEUP__ATU_M71 base address */
  #define WAKEUP__ATU_M71_BASE_NS                  (0x42AA0000u)
  /** Peripheral WAKEUP__ATU_M71 base pointer */
  #define WAKEUP__ATU_M71                          ((WAKEUP_ATU_Type *)WAKEUP__ATU_M71_BASE)
  /** Peripheral WAKEUP__ATU_M71 base pointer */
  #define WAKEUP__ATU_M71_NS                       ((WAKEUP_ATU_Type *)WAKEUP__ATU_M71_BASE_NS)
  /** Peripheral WAKEUP__AUDIO_XCVR base address */
  #define WAKEUP__AUDIO_XCVR_BASE                  (0x52680000u)
  /** Peripheral WAKEUP__AUDIO_XCVR base address */
  #define WAKEUP__AUDIO_XCVR_BASE_NS               (0x42680000u)
  /** Peripheral WAKEUP__AUDIO_XCVR base pointer */
  #define WAKEUP__AUDIO_XCVR                       ((WAKEUP_ATU_Type *)WAKEUP__AUDIO_XCVR_BASE)
  /** Peripheral WAKEUP__AUDIO_XCVR base pointer */
  #define WAKEUP__AUDIO_XCVR_NS                    ((WAKEUP_ATU_Type *)WAKEUP__AUDIO_XCVR_BASE_NS)
  /** Array initializer of WAKEUP_ATU peripheral base addresses */
  #define WAKEUP_ATU_BASE_ADDRS                    { WAKEUP__ATUA_BASE, WAKEUP__ATUM_BASE, WAKEUP__ATUM33_BASE, WAKEUP__ATU_M70_BASE, WAKEUP__ATU_M71_BASE, WAKEUP__AUDIO_XCVR_BASE }
  /** Array initializer of WAKEUP_ATU peripheral base pointers */
  #define WAKEUP_ATU_BASE_PTRS                     { WAKEUP__ATUA, WAKEUP__ATUM, WAKEUP__ATUM33, WAKEUP__ATU_M70, WAKEUP__ATU_M71, WAKEUP__AUDIO_XCVR }
  /** Array initializer of WAKEUP_ATU peripheral base addresses */
  #define WAKEUP_ATU_BASE_ADDRS_NS                 { WAKEUP__ATUA_BASE_NS, WAKEUP__ATUM_BASE_NS, WAKEUP__ATUM33_BASE_NS, WAKEUP__ATU_M70_BASE_NS, WAKEUP__ATU_M71_BASE_NS, WAKEUP__AUDIO_XCVR_BASE_NS }
  /** Array initializer of WAKEUP_ATU peripheral base pointers */
  #define WAKEUP_ATU_BASE_PTRS_NS                  { WAKEUP__ATUA_NS, WAKEUP__ATUM_NS, WAKEUP__ATUM33_NS, WAKEUP__ATU_M70_NS, WAKEUP__ATU_M71_NS, WAKEUP__AUDIO_XCVR_NS }
#else
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
#endif

/* WAKEUP_CMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__CMU1 base address */
  #define WAKEUP__CMU1_BASE                        (0x52750000u)
  /** Peripheral WAKEUP__CMU1 base address */
  #define WAKEUP__CMU1_BASE_NS                     (0x42750000u)
  /** Peripheral WAKEUP__CMU1 base pointer */
  #define WAKEUP__CMU1                             ((WAKEUP_CMU_Type *)WAKEUP__CMU1_BASE)
  /** Peripheral WAKEUP__CMU1 base pointer */
  #define WAKEUP__CMU1_NS                          ((WAKEUP_CMU_Type *)WAKEUP__CMU1_BASE_NS)
  /** Peripheral WAKEUP__CMU2 base address */
  #define WAKEUP__CMU2_BASE                        (0x527A0000u)
  /** Peripheral WAKEUP__CMU2 base address */
  #define WAKEUP__CMU2_BASE_NS                     (0x427A0000u)
  /** Peripheral WAKEUP__CMU2 base pointer */
  #define WAKEUP__CMU2                             ((WAKEUP_CMU_Type *)WAKEUP__CMU2_BASE)
  /** Peripheral WAKEUP__CMU2 base pointer */
  #define WAKEUP__CMU2_NS                          ((WAKEUP_CMU_Type *)WAKEUP__CMU2_BASE_NS)
  /** Array initializer of WAKEUP_CMU peripheral base addresses */
  #define WAKEUP_CMU_BASE_ADDRS                    { WAKEUP__CMU1_BASE, WAKEUP__CMU2_BASE }
  /** Array initializer of WAKEUP_CMU peripheral base pointers */
  #define WAKEUP_CMU_BASE_PTRS                     { WAKEUP__CMU1, WAKEUP__CMU2 }
  /** Array initializer of WAKEUP_CMU peripheral base addresses */
  #define WAKEUP_CMU_BASE_ADDRS_NS                 { WAKEUP__CMU1_BASE_NS, WAKEUP__CMU2_BASE_NS }
  /** Array initializer of WAKEUP_CMU peripheral base pointers */
  #define WAKEUP_CMU_BASE_PTRS_NS                  { WAKEUP__CMU1_NS, WAKEUP__CMU2_NS }
#else
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
#endif

/* WAKEUP_DMA_CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__DMA_CRC2 base address */
  #define WAKEUP__DMA_CRC2_BASE                    (0x527B0000u)
  /** Peripheral WAKEUP__DMA_CRC2 base address */
  #define WAKEUP__DMA_CRC2_BASE_NS                 (0x427B0000u)
  /** Peripheral WAKEUP__DMA_CRC2 base pointer */
  #define WAKEUP__DMA_CRC2                         ((WAKEUP_DMA_CRC_Type *)WAKEUP__DMA_CRC2_BASE)
  /** Peripheral WAKEUP__DMA_CRC2 base pointer */
  #define WAKEUP__DMA_CRC2_NS                      ((WAKEUP_DMA_CRC_Type *)WAKEUP__DMA_CRC2_BASE_NS)
  /** Peripheral WAKEUP__DMA_CRC4 base address */
  #define WAKEUP__DMA_CRC4_BASE                    (0x527C0000u)
  /** Peripheral WAKEUP__DMA_CRC4 base address */
  #define WAKEUP__DMA_CRC4_BASE_NS                 (0x427C0000u)
  /** Peripheral WAKEUP__DMA_CRC4 base pointer */
  #define WAKEUP__DMA_CRC4                         ((WAKEUP_DMA_CRC_Type *)WAKEUP__DMA_CRC4_BASE)
  /** Peripheral WAKEUP__DMA_CRC4 base pointer */
  #define WAKEUP__DMA_CRC4_NS                      ((WAKEUP_DMA_CRC_Type *)WAKEUP__DMA_CRC4_BASE_NS)
  /** Array initializer of WAKEUP_DMA_CRC peripheral base addresses */
  #define WAKEUP_DMA_CRC_BASE_ADDRS                { WAKEUP__DMA_CRC2_BASE, WAKEUP__DMA_CRC4_BASE }
  /** Array initializer of WAKEUP_DMA_CRC peripheral base pointers */
  #define WAKEUP_DMA_CRC_BASE_PTRS                 { WAKEUP__DMA_CRC2, WAKEUP__DMA_CRC4 }
  /** Array initializer of WAKEUP_DMA_CRC peripheral base addresses */
  #define WAKEUP_DMA_CRC_BASE_ADDRS_NS             { WAKEUP__DMA_CRC2_BASE_NS, WAKEUP__DMA_CRC4_BASE_NS }
  /** Array initializer of WAKEUP_DMA_CRC peripheral base pointers */
  #define WAKEUP_DMA_CRC_BASE_PTRS_NS              { WAKEUP__DMA_CRC2_NS, WAKEUP__DMA_CRC4_NS }
#else
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
#endif

/* WAKEUP_EIM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__EIM base address */
  #define WAKEUP__EIM_BASE                         (0x52780000u)
  /** Peripheral WAKEUP__EIM base address */
  #define WAKEUP__EIM_BASE_NS                      (0x42780000u)
  /** Peripheral WAKEUP__EIM base pointer */
  #define WAKEUP__EIM                              ((WAKEUP_EIM_Type *)WAKEUP__EIM_BASE)
  /** Peripheral WAKEUP__EIM base pointer */
  #define WAKEUP__EIM_NS                           ((WAKEUP_EIM_Type *)WAKEUP__EIM_BASE_NS)
  /** Array initializer of WAKEUP_EIM peripheral base addresses */
  #define WAKEUP_EIM_BASE_ADDRS                    { WAKEUP__EIM_BASE }
  /** Array initializer of WAKEUP_EIM peripheral base pointers */
  #define WAKEUP_EIM_BASE_PTRS                     { WAKEUP__EIM }
  /** Array initializer of WAKEUP_EIM peripheral base addresses */
  #define WAKEUP_EIM_BASE_ADDRS_NS                 { WAKEUP__EIM_BASE_NS }
  /** Array initializer of WAKEUP_EIM peripheral base pointers */
  #define WAKEUP_EIM_BASE_PTRS_NS                  { WAKEUP__EIM_NS }
#else
  /** Peripheral WAKEUP__EIM base address */
  #define WAKEUP__EIM_BASE                         (0x42780000u)
  /** Peripheral WAKEUP__EIM base pointer */
  #define WAKEUP__EIM                              ((WAKEUP_EIM_Type *)WAKEUP__EIM_BASE)
  /** Array initializer of WAKEUP_EIM peripheral base addresses */
  #define WAKEUP_EIM_BASE_ADDRS                    { WAKEUP__EIM_BASE }
  /** Array initializer of WAKEUP_EIM peripheral base pointers */
  #define WAKEUP_EIM_BASE_PTRS                     { WAKEUP__EIM }
#endif

/* WAKEUP_ERM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__ERM base address */
  #define WAKEUP__ERM_BASE                         (0x52790000u)
  /** Peripheral WAKEUP__ERM base address */
  #define WAKEUP__ERM_BASE_NS                      (0x42790000u)
  /** Peripheral WAKEUP__ERM base pointer */
  #define WAKEUP__ERM                              ((WAKEUP_ERM_Type *)WAKEUP__ERM_BASE)
  /** Peripheral WAKEUP__ERM base pointer */
  #define WAKEUP__ERM_NS                           ((WAKEUP_ERM_Type *)WAKEUP__ERM_BASE_NS)
  /** Array initializer of WAKEUP_ERM peripheral base addresses */
  #define WAKEUP_ERM_BASE_ADDRS                    { WAKEUP__ERM_BASE }
  /** Array initializer of WAKEUP_ERM peripheral base pointers */
  #define WAKEUP_ERM_BASE_PTRS                     { WAKEUP__ERM }
  /** Array initializer of WAKEUP_ERM peripheral base addresses */
  #define WAKEUP_ERM_BASE_ADDRS_NS                 { WAKEUP__ERM_BASE_NS }
  /** Array initializer of WAKEUP_ERM peripheral base pointers */
  #define WAKEUP_ERM_BASE_PTRS_NS                  { WAKEUP__ERM_NS }
#else
  /** Peripheral WAKEUP__ERM base address */
  #define WAKEUP__ERM_BASE                         (0x42790000u)
  /** Peripheral WAKEUP__ERM base pointer */
  #define WAKEUP__ERM                              ((WAKEUP_ERM_Type *)WAKEUP__ERM_BASE)
  /** Array initializer of WAKEUP_ERM peripheral base addresses */
  #define WAKEUP_ERM_BASE_ADDRS                    { WAKEUP__ERM_BASE }
  /** Array initializer of WAKEUP_ERM peripheral base pointers */
  #define WAKEUP_ERM_BASE_PTRS                     { WAKEUP__ERM }
#endif

/* WAKEUP_GPT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPT2 base address */
  #define GPT2_BASE                                (0x528A0000u)
  /** Peripheral GPT2 base address */
  #define GPT2_BASE_NS                             (0x428A0000u)
  /** Peripheral GPT2 base pointer */
  #define GPT2                                     ((WAKEUP_GPT_Type *)GPT2_BASE)
  /** Peripheral GPT2 base pointer */
  #define GPT2_NS                                  ((WAKEUP_GPT_Type *)GPT2_BASE_NS)
  /** Peripheral GPT3 base address */
  #define GPT3_BASE                                (0x528B0000u)
  /** Peripheral GPT3 base address */
  #define GPT3_BASE_NS                             (0x428B0000u)
  /** Peripheral GPT3 base pointer */
  #define GPT3                                     ((WAKEUP_GPT_Type *)GPT3_BASE)
  /** Peripheral GPT3 base pointer */
  #define GPT3_NS                                  ((WAKEUP_GPT_Type *)GPT3_BASE_NS)
  /** Peripheral GPT4 base address */
  #define GPT4_BASE                                (0x528C0000u)
  /** Peripheral GPT4 base address */
  #define GPT4_BASE_NS                             (0x428C0000u)
  /** Peripheral GPT4 base pointer */
  #define GPT4                                     ((WAKEUP_GPT_Type *)GPT4_BASE)
  /** Peripheral GPT4 base pointer */
  #define GPT4_NS                                  ((WAKEUP_GPT_Type *)GPT4_BASE_NS)
  /** Array initializer of WAKEUP_GPT peripheral base addresses */
  #define WAKEUP_GPT_BASE_ADDRS                    { 0u, 0u, GPT2_BASE, GPT3_BASE, GPT4_BASE }
  /** Array initializer of WAKEUP_GPT peripheral base pointers */
  #define WAKEUP_GPT_BASE_PTRS                     { (WAKEUP_GPT_Type *)0u, (WAKEUP_GPT_Type *)0u, GPT2, GPT3, GPT4 }
  /** Array initializer of WAKEUP_GPT peripheral base addresses */
  #define WAKEUP_GPT_BASE_ADDRS_NS                 { 0u, 0u, GPT2_BASE_NS, GPT3_BASE_NS, GPT4_BASE_NS }
  /** Array initializer of WAKEUP_GPT peripheral base pointers */
  #define WAKEUP_GPT_BASE_PTRS_NS                  { (WAKEUP_GPT_Type *)0u, (WAKEUP_GPT_Type *)0u, GPT2_NS, GPT3_NS, GPT4_NS }
#else
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
#endif

/* WAKEUP_SAI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__SAI2 base address */
  #define WAKEUP__SAI2_BASE                        (0x52650000u)
  /** Peripheral WAKEUP__SAI2 base address */
  #define WAKEUP__SAI2_BASE_NS                     (0x42650000u)
  /** Peripheral WAKEUP__SAI2 base pointer */
  #define WAKEUP__SAI2                             ((WAKEUP_SAI_Type *)WAKEUP__SAI2_BASE)
  /** Peripheral WAKEUP__SAI2 base pointer */
  #define WAKEUP__SAI2_NS                          ((WAKEUP_SAI_Type *)WAKEUP__SAI2_BASE_NS)
  /** Array initializer of WAKEUP_SAI peripheral base addresses */
  #define WAKEUP_SAI_BASE_ADDRS                    { WAKEUP__SAI2_BASE }
  /** Array initializer of WAKEUP_SAI peripheral base pointers */
  #define WAKEUP_SAI_BASE_PTRS                     { WAKEUP__SAI2 }
  /** Array initializer of WAKEUP_SAI peripheral base addresses */
  #define WAKEUP_SAI_BASE_ADDRS_NS                 { WAKEUP__SAI2_BASE_NS }
  /** Array initializer of WAKEUP_SAI peripheral base pointers */
  #define WAKEUP_SAI_BASE_PTRS_NS                  { WAKEUP__SAI2_NS }
#else
  /** Peripheral WAKEUP__SAI2 base address */
  #define WAKEUP__SAI2_BASE                        (0x42650000u)
  /** Peripheral WAKEUP__SAI2 base pointer */
  #define WAKEUP__SAI2                             ((WAKEUP_SAI_Type *)WAKEUP__SAI2_BASE)
  /** Array initializer of WAKEUP_SAI peripheral base addresses */
  #define WAKEUP_SAI_BASE_ADDRS                    { WAKEUP__SAI2_BASE }
  /** Array initializer of WAKEUP_SAI peripheral base pointers */
  #define WAKEUP_SAI_BASE_PTRS                     { WAKEUP__SAI2 }
#endif

/* WAKEUP_TCW - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__TCW base address */
  #define WAKEUP__TCW_BASE                         (0x52620000u)
  /** Peripheral WAKEUP__TCW base address */
  #define WAKEUP__TCW_BASE_NS                      (0x42620000u)
  /** Peripheral WAKEUP__TCW base pointer */
  #define WAKEUP__TCW                              ((WAKEUP_TCW_Type *)WAKEUP__TCW_BASE)
  /** Peripheral WAKEUP__TCW base pointer */
  #define WAKEUP__TCW_NS                           ((WAKEUP_TCW_Type *)WAKEUP__TCW_BASE_NS)
  /** Array initializer of WAKEUP_TCW peripheral base addresses */
  #define WAKEUP_TCW_BASE_ADDRS                    { WAKEUP__TCW_BASE }
  /** Array initializer of WAKEUP_TCW peripheral base pointers */
  #define WAKEUP_TCW_BASE_PTRS                     { WAKEUP__TCW }
  /** Array initializer of WAKEUP_TCW peripheral base addresses */
  #define WAKEUP_TCW_BASE_ADDRS_NS                 { WAKEUP__TCW_BASE_NS }
  /** Array initializer of WAKEUP_TCW peripheral base pointers */
  #define WAKEUP_TCW_BASE_PTRS_NS                  { WAKEUP__TCW_NS }
#else
  /** Peripheral WAKEUP__TCW base address */
  #define WAKEUP__TCW_BASE                         (0x42620000u)
  /** Peripheral WAKEUP__TCW base pointer */
  #define WAKEUP__TCW                              ((WAKEUP_TCW_Type *)WAKEUP__TCW_BASE)
  /** Array initializer of WAKEUP_TCW peripheral base addresses */
  #define WAKEUP_TCW_BASE_ADDRS                    { WAKEUP__TCW_BASE }
  /** Array initializer of WAKEUP_TCW peripheral base pointers */
  #define WAKEUP_TCW_BASE_PTRS                     { WAKEUP__TCW }
#endif

/* WAKEUP_TRDC_MGR_MEGA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__TRDC_MGR_MEGA base address */
  #define WAKEUP__TRDC_MGR_MEGA_BASE               (0x52810000u)
  /** Peripheral WAKEUP__TRDC_MGR_MEGA base address */
  #define WAKEUP__TRDC_MGR_MEGA_BASE_NS            (0x42810000u)
  /** Peripheral WAKEUP__TRDC_MGR_MEGA base pointer */
  #define WAKEUP__TRDC_MGR_MEGA                    ((WAKEUP_TRDC_MGR_MEGA_Type *)WAKEUP__TRDC_MGR_MEGA_BASE)
  /** Peripheral WAKEUP__TRDC_MGR_MEGA base pointer */
  #define WAKEUP__TRDC_MGR_MEGA_NS                 ((WAKEUP_TRDC_MGR_MEGA_Type *)WAKEUP__TRDC_MGR_MEGA_BASE_NS)
  /** Array initializer of WAKEUP_TRDC_MGR_MEGA peripheral base addresses */
  #define WAKEUP_TRDC_MGR_MEGA_BASE_ADDRS          { WAKEUP__TRDC_MGR_MEGA_BASE }
  /** Array initializer of WAKEUP_TRDC_MGR_MEGA peripheral base pointers */
  #define WAKEUP_TRDC_MGR_MEGA_BASE_PTRS           { WAKEUP__TRDC_MGR_MEGA }
  /** Array initializer of WAKEUP_TRDC_MGR_MEGA peripheral base addresses */
  #define WAKEUP_TRDC_MGR_MEGA_BASE_ADDRS_NS       { WAKEUP__TRDC_MGR_MEGA_BASE_NS }
  /** Array initializer of WAKEUP_TRDC_MGR_MEGA peripheral base pointers */
  #define WAKEUP_TRDC_MGR_MEGA_BASE_PTRS_NS        { WAKEUP__TRDC_MGR_MEGA_NS }
#else
  /** Peripheral WAKEUP__TRDC_MGR_MEGA base address */
  #define WAKEUP__TRDC_MGR_MEGA_BASE               (0x42810000u)
  /** Peripheral WAKEUP__TRDC_MGR_MEGA base pointer */
  #define WAKEUP__TRDC_MGR_MEGA                    ((WAKEUP_TRDC_MGR_MEGA_Type *)WAKEUP__TRDC_MGR_MEGA_BASE)
  /** Array initializer of WAKEUP_TRDC_MGR_MEGA peripheral base addresses */
  #define WAKEUP_TRDC_MGR_MEGA_BASE_ADDRS          { WAKEUP__TRDC_MGR_MEGA_BASE }
  /** Array initializer of WAKEUP_TRDC_MGR_MEGA peripheral base pointers */
  #define WAKEUP_TRDC_MGR_MEGA_BASE_PTRS           { WAKEUP__TRDC_MGR_MEGA }
#endif

/* WAKEUP_USDHC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__USDHC1 base address */
  #define WAKEUP__USDHC1_BASE                      (0x52850000u)
  /** Peripheral WAKEUP__USDHC1 base address */
  #define WAKEUP__USDHC1_BASE_NS                   (0x42850000u)
  /** Peripheral WAKEUP__USDHC1 base pointer */
  #define WAKEUP__USDHC1                           ((WAKEUP_USDHC_Type *)WAKEUP__USDHC1_BASE)
  /** Peripheral WAKEUP__USDHC1 base pointer */
  #define WAKEUP__USDHC1_NS                        ((WAKEUP_USDHC_Type *)WAKEUP__USDHC1_BASE_NS)
  /** Peripheral WAKEUP__USDHC2 base address */
  #define WAKEUP__USDHC2_BASE                      (0x52860000u)
  /** Peripheral WAKEUP__USDHC2 base address */
  #define WAKEUP__USDHC2_BASE_NS                   (0x42860000u)
  /** Peripheral WAKEUP__USDHC2 base pointer */
  #define WAKEUP__USDHC2                           ((WAKEUP_USDHC_Type *)WAKEUP__USDHC2_BASE)
  /** Peripheral WAKEUP__USDHC2 base pointer */
  #define WAKEUP__USDHC2_NS                        ((WAKEUP_USDHC_Type *)WAKEUP__USDHC2_BASE_NS)
  /** Peripheral WAKEUP__USDHC3 base address */
  #define WAKEUP__USDHC3_BASE                      (0x52880000u)
  /** Peripheral WAKEUP__USDHC3 base address */
  #define WAKEUP__USDHC3_BASE_NS                   (0x42880000u)
  /** Peripheral WAKEUP__USDHC3 base pointer */
  #define WAKEUP__USDHC3                           ((WAKEUP_USDHC_Type *)WAKEUP__USDHC3_BASE)
  /** Peripheral WAKEUP__USDHC3 base pointer */
  #define WAKEUP__USDHC3_NS                        ((WAKEUP_USDHC_Type *)WAKEUP__USDHC3_BASE_NS)
  /** Array initializer of WAKEUP_USDHC peripheral base addresses */
  #define WAKEUP_USDHC_BASE_ADDRS                  { WAKEUP__USDHC1_BASE, WAKEUP__USDHC2_BASE, WAKEUP__USDHC3_BASE }
  /** Array initializer of WAKEUP_USDHC peripheral base pointers */
  #define WAKEUP_USDHC_BASE_PTRS                   { WAKEUP__USDHC1, WAKEUP__USDHC2, WAKEUP__USDHC3 }
  /** Array initializer of WAKEUP_USDHC peripheral base addresses */
  #define WAKEUP_USDHC_BASE_ADDRS_NS               { WAKEUP__USDHC1_BASE_NS, WAKEUP__USDHC2_BASE_NS, WAKEUP__USDHC3_BASE_NS }
  /** Array initializer of WAKEUP_USDHC peripheral base pointers */
  #define WAKEUP_USDHC_BASE_PTRS_NS                { WAKEUP__USDHC1_NS, WAKEUP__USDHC2_NS, WAKEUP__USDHC3_NS }
#else
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
#endif

/* WAKEUP_XSPI_RESPONDER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__XSPI_RESPONDER base address */
  #define WAKEUP__XSPI_RESPONDER_BASE              (0x52890000u)
  /** Peripheral WAKEUP__XSPI_RESPONDER base address */
  #define WAKEUP__XSPI_RESPONDER_BASE_NS           (0x42890000u)
  /** Peripheral WAKEUP__XSPI_RESPONDER base pointer */
  #define WAKEUP__XSPI_RESPONDER                   ((WAKEUP_XSPI_RESPONDER_Type *)WAKEUP__XSPI_RESPONDER_BASE)
  /** Peripheral WAKEUP__XSPI_RESPONDER base pointer */
  #define WAKEUP__XSPI_RESPONDER_NS                ((WAKEUP_XSPI_RESPONDER_Type *)WAKEUP__XSPI_RESPONDER_BASE_NS)
  /** Array initializer of WAKEUP_XSPI_RESPONDER peripheral base addresses */
  #define WAKEUP_XSPI_RESPONDER_BASE_ADDRS         { WAKEUP__XSPI_RESPONDER_BASE }
  /** Array initializer of WAKEUP_XSPI_RESPONDER peripheral base pointers */
  #define WAKEUP_XSPI_RESPONDER_BASE_PTRS          { WAKEUP__XSPI_RESPONDER }
  /** Array initializer of WAKEUP_XSPI_RESPONDER peripheral base addresses */
  #define WAKEUP_XSPI_RESPONDER_BASE_ADDRS_NS      { WAKEUP__XSPI_RESPONDER_BASE_NS }
  /** Array initializer of WAKEUP_XSPI_RESPONDER peripheral base pointers */
  #define WAKEUP_XSPI_RESPONDER_BASE_PTRS_NS       { WAKEUP__XSPI_RESPONDER_NS }
#else
  /** Peripheral WAKEUP__XSPI_RESPONDER base address */
  #define WAKEUP__XSPI_RESPONDER_BASE              (0x42890000u)
  /** Peripheral WAKEUP__XSPI_RESPONDER base pointer */
  #define WAKEUP__XSPI_RESPONDER                   ((WAKEUP_XSPI_RESPONDER_Type *)WAKEUP__XSPI_RESPONDER_BASE)
  /** Array initializer of WAKEUP_XSPI_RESPONDER peripheral base addresses */
  #define WAKEUP_XSPI_RESPONDER_BASE_ADDRS         { WAKEUP__XSPI_RESPONDER_BASE }
  /** Array initializer of WAKEUP_XSPI_RESPONDER peripheral base pointers */
  #define WAKEUP_XSPI_RESPONDER_BASE_PTRS          { WAKEUP__XSPI_RESPONDER }
#endif

/* WDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE                               (0x542D0000u)
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE_NS                            (0x442D0000u)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1_NS                                 ((WDOG_Type *)WDOG1_BASE_NS)
  /** Peripheral WDOG2 base address */
  #define WDOG2_BASE                               (0x542E0000u)
  /** Peripheral WDOG2 base address */
  #define WDOG2_BASE_NS                            (0x442E0000u)
  /** Peripheral WDOG2 base pointer */
  #define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
  /** Peripheral WDOG2 base pointer */
  #define WDOG2_NS                                 ((WDOG_Type *)WDOG2_BASE_NS)
  /** Peripheral WDOG3 base address */
  #define WDOG3_BASE                               (0x59220000u)
  /** Peripheral WDOG3 base address */
  #define WDOG3_BASE_NS                            (0x49220000u)
  /** Peripheral WDOG3 base pointer */
  #define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
  /** Peripheral WDOG3 base pointer */
  #define WDOG3_NS                                 ((WDOG_Type *)WDOG3_BASE_NS)
  /** Peripheral WDOG4 base address */
  #define WDOG4_BASE                               (0x59230000u)
  /** Peripheral WDOG4 base address */
  #define WDOG4_BASE_NS                            (0x49230000u)
  /** Peripheral WDOG4 base pointer */
  #define WDOG4                                    ((WDOG_Type *)WDOG4_BASE)
  /** Peripheral WDOG4 base pointer */
  #define WDOG4_NS                                 ((WDOG_Type *)WDOG4_BASE_NS)
  /** Peripheral WDOG5 base address */
  #define WDOG5_BASE                               (0x524B0000u)
  /** Peripheral WDOG5 base address */
  #define WDOG5_BASE_NS                            (0x424B0000u)
  /** Peripheral WDOG5 base pointer */
  #define WDOG5                                    ((WDOG_Type *)WDOG5_BASE)
  /** Peripheral WDOG5 base pointer */
  #define WDOG5_NS                                 ((WDOG_Type *)WDOG5_BASE_NS)
  /** Peripheral WDOG6 base address */
  #define WDOG6_BASE                               (0x527E0000u)
  /** Peripheral WDOG6 base address */
  #define WDOG6_BASE_NS                            (0x427E0000u)
  /** Peripheral WDOG6 base pointer */
  #define WDOG6                                    ((WDOG_Type *)WDOG6_BASE)
  /** Peripheral WDOG6 base pointer */
  #define WDOG6_NS                                 ((WDOG_Type *)WDOG6_BASE_NS)
  /** Peripheral WDOG7 base address */
  #define WDOG7_BASE                               (0x5D0E0000u)
  /** Peripheral WDOG7 base address */
  #define WDOG7_BASE_NS                            (0x4D0E0000u)
  /** Peripheral WDOG7 base pointer */
  #define WDOG7                                    ((WDOG_Type *)WDOG7_BASE)
  /** Peripheral WDOG7 base pointer */
  #define WDOG7_NS                                 ((WDOG_Type *)WDOG7_BASE_NS)
  /** Peripheral WDOG8 base address */
  #define WDOG8_BASE                               (0x5D0F0000u)
  /** Peripheral WDOG8 base address */
  #define WDOG8_BASE_NS                            (0x4D0F0000u)
  /** Peripheral WDOG8 base pointer */
  #define WDOG8                                    ((WDOG_Type *)WDOG8_BASE)
  /** Peripheral WDOG8 base pointer */
  #define WDOG8_NS                                 ((WDOG_Type *)WDOG8_BASE_NS)
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS                          { WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE, WDOG6_BASE, WDOG7_BASE, WDOG8_BASE }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS                           { WDOG1, WDOG2, WDOG3, WDOG4, WDOG5, WDOG6, WDOG7, WDOG8 }
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS_NS                       { WDOG1_BASE_NS, WDOG2_BASE_NS, WDOG3_BASE_NS, WDOG4_BASE_NS, WDOG5_BASE_NS, WDOG6_BASE_NS, WDOG7_BASE_NS, WDOG8_BASE_NS }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS_NS                        { WDOG1_NS, WDOG2_NS, WDOG3_NS, WDOG4_NS, WDOG5_NS, WDOG6_NS, WDOG7_NS, WDOG8_NS }
#else
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
#endif

/* XBAR1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XBAR1 base address */
  #define XBAR1_BASE                               (0x52A20000u)
  /** Peripheral XBAR1 base address */
  #define XBAR1_BASE_NS                            (0x42A20000u)
  /** Peripheral XBAR1 base pointer */
  #define XBAR1                                    ((XBAR1_Type *)XBAR1_BASE)
  /** Peripheral XBAR1 base pointer */
  #define XBAR1_NS                                 ((XBAR1_Type *)XBAR1_BASE_NS)
  /** Array initializer of XBAR1 peripheral base addresses */
  #define XBAR1_BASE_ADDRS                         { XBAR1_BASE }
  /** Array initializer of XBAR1 peripheral base pointers */
  #define XBAR1_BASE_PTRS                          { XBAR1 }
  /** Array initializer of XBAR1 peripheral base addresses */
  #define XBAR1_BASE_ADDRS_NS                      { XBAR1_BASE_NS }
  /** Array initializer of XBAR1 peripheral base pointers */
  #define XBAR1_BASE_PTRS_NS                       { XBAR1_NS }
#else
  /** Peripheral XBAR1 base address */
  #define XBAR1_BASE                               (0x42A20000u)
  /** Peripheral XBAR1 base pointer */
  #define XBAR1                                    ((XBAR1_Type *)XBAR1_BASE)
  /** Array initializer of XBAR1 peripheral base addresses */
  #define XBAR1_BASE_ADDRS                         { XBAR1_BASE }
  /** Array initializer of XBAR1 peripheral base pointers */
  #define XBAR1_BASE_PTRS                          { XBAR1 }
#endif

/* XBAR2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XBAR2 base address */
  #define XBAR2_BASE                               (0x52A30000u)
  /** Peripheral XBAR2 base address */
  #define XBAR2_BASE_NS                            (0x42A30000u)
  /** Peripheral XBAR2 base pointer */
  #define XBAR2                                    ((XBAR2_Type *)XBAR2_BASE)
  /** Peripheral XBAR2 base pointer */
  #define XBAR2_NS                                 ((XBAR2_Type *)XBAR2_BASE_NS)
  /** Array initializer of XBAR2 peripheral base addresses */
  #define XBAR2_BASE_ADDRS                         { XBAR2_BASE }
  /** Array initializer of XBAR2 peripheral base pointers */
  #define XBAR2_BASE_PTRS                          { XBAR2 }
  /** Array initializer of XBAR2 peripheral base addresses */
  #define XBAR2_BASE_ADDRS_NS                      { XBAR2_BASE_NS }
  /** Array initializer of XBAR2 peripheral base pointers */
  #define XBAR2_BASE_PTRS_NS                       { XBAR2_NS }
#else
  /** Peripheral XBAR2 base address */
  #define XBAR2_BASE                               (0x42A30000u)
  /** Peripheral XBAR2 base pointer */
  #define XBAR2                                    ((XBAR2_Type *)XBAR2_BASE)
  /** Array initializer of XBAR2 peripheral base addresses */
  #define XBAR2_BASE_ADDRS                         { XBAR2_BASE }
  /** Array initializer of XBAR2 peripheral base pointers */
  #define XBAR2_BASE_PTRS                          { XBAR2 }
#endif

/* XBAR3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XBAR3 base address */
  #define XBAR3_BASE                               (0x52A40000u)
  /** Peripheral XBAR3 base address */
  #define XBAR3_BASE_NS                            (0x42A40000u)
  /** Peripheral XBAR3 base pointer */
  #define XBAR3                                    ((XBAR3_Type *)XBAR3_BASE)
  /** Peripheral XBAR3 base pointer */
  #define XBAR3_NS                                 ((XBAR3_Type *)XBAR3_BASE_NS)
  /** Array initializer of XBAR3 peripheral base addresses */
  #define XBAR3_BASE_ADDRS                         { XBAR3_BASE }
  /** Array initializer of XBAR3 peripheral base pointers */
  #define XBAR3_BASE_PTRS                          { XBAR3 }
  /** Array initializer of XBAR3 peripheral base addresses */
  #define XBAR3_BASE_ADDRS_NS                      { XBAR3_BASE_NS }
  /** Array initializer of XBAR3 peripheral base pointers */
  #define XBAR3_BASE_PTRS_NS                       { XBAR3_NS }
#else
  /** Peripheral XBAR3 base address */
  #define XBAR3_BASE                               (0x42A40000u)
  /** Peripheral XBAR3 base pointer */
  #define XBAR3                                    ((XBAR3_Type *)XBAR3_BASE)
  /** Array initializer of XBAR3 peripheral base addresses */
  #define XBAR3_BASE_ADDRS                         { XBAR3_BASE }
  /** Array initializer of XBAR3 peripheral base pointers */
  #define XBAR3_BASE_PTRS                          { XBAR3 }
#endif
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
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (300000000UL)


/* XCACHE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral M33_CACHE_CTRLPC base address */
  #define M33_CACHE_CTRLPC_BASE                    (0x54400000u)
  /** Peripheral M33_CACHE_CTRLPC base address */
  #define M33_CACHE_CTRLPC_BASE_NS                 (0x44400000u)
  /** Peripheral M33_CACHE_CTRLPC base pointer */
  #define M33_CACHE_CTRLPC                         ((XCACHE_Type *)M33_CACHE_CTRLPC_BASE)
  /** Peripheral M33_CACHE_CTRLPC base pointer */
  #define M33_CACHE_CTRLPC_NS                      ((XCACHE_Type *)M33_CACHE_CTRLPC_BASE_NS)
  /** Peripheral M33_CACHE_CTRLPS base address */
  #define M33_CACHE_CTRLPS_BASE                    (0x54400800u)
  /** Peripheral M33_CACHE_CTRLPS base address */
  #define M33_CACHE_CTRLPS_BASE_NS                 (0x44400800u)
  /** Peripheral M33_CACHE_CTRLPS base pointer */
  #define M33_CACHE_CTRLPS                         ((XCACHE_Type *)M33_CACHE_CTRLPS_BASE)
  /** Peripheral M33_CACHE_CTRLPS base pointer */
  #define M33_CACHE_CTRLPS_NS                      ((XCACHE_Type *)M33_CACHE_CTRLPS_BASE_NS)
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS                        { M33_CACHE_CTRLPC_BASE, M33_CACHE_CTRLPS_BASE }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS                         { M33_CACHE_CTRLPC, M33_CACHE_CTRLPS }
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS_NS                     { M33_CACHE_CTRLPC_BASE_NS, M33_CACHE_CTRLPS_BASE_NS }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS_NS                      { M33_CACHE_CTRLPC_NS, M33_CACHE_CTRLPS_NS }
#else
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
#endif
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** XCACHE physical memory base address */
  #define XCACHE_PHYMEM_BASES                { 0x1FFC0000u, 0x38000000u }
  /** XCACHE physical memory size */
  #define XCACHE_PHYMEM_SIZES                { 0x00040000u, 0x08000000u }
  /** XCACHE physical memory base address */
  #define XCACHE_PHYMEM_BASES_NS             { 0x0FFC0000u, 0x28000000u }
  /** XCACHE physical memory size */
  #define XCACHE_PHYMEM_SIZES_NS             { 0x00040000u, 0x08000000u }
#else
  /** XCACHE physical memory base address */
  #define XCACHE_PHYMEM_BASES                { 0x0FFC0000u, 0x28000000u }
  /** XCACHE physical memory size */
  #define XCACHE_PHYMEM_SIZES                { 0x00040000u, 0x08000000u }
#endif


/* XSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XSPI1 base address */
  #define XSPI1_BASE                               (0x52B90000u)
  /** Peripheral XSPI1 base address */
  #define XSPI1_BASE_NS                            (0x42B90000u)
  /** Peripheral XSPI1 base pointer */
  #define XSPI1                                    ((XSPI_Type *)XSPI1_BASE)
  /** Peripheral XSPI1 base pointer */
  #define XSPI1_NS                                 ((XSPI_Type *)XSPI1_BASE_NS)
  /** Peripheral XSPI2 base address */
  #define XSPI2_BASE                               (0x52BE0000u)
  /** Peripheral XSPI2 base address */
  #define XSPI2_BASE_NS                            (0x42BE0000u)
  /** Peripheral XSPI2 base pointer */
  #define XSPI2                                    ((XSPI_Type *)XSPI2_BASE)
  /** Peripheral XSPI2 base pointer */
  #define XSPI2_NS                                 ((XSPI_Type *)XSPI2_BASE_NS)
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS                          { 0u, XSPI1_BASE, XSPI2_BASE }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS                           { (XSPI_Type *)0u, XSPI1, XSPI2 }
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS_NS                       { 0u, XSPI1_BASE_NS, XSPI2_BASE_NS }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS_NS                        { (XSPI_Type *)0u, XSPI1_NS, XSPI2_NS }
#else
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
#endif
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
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base address */
  #define NETC__IEPRC_1__IEPRC_IERB_BASE           (0x5C8A0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base address */
  #define NETC__IEPRC_1__IEPRC_IERB_BASE_NS        (0x4C8A0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base pointer */
  #define NETC__IEPRC_1__IEPRC_IERB                ((ieprc_ierb_Type *)NETC__IEPRC_1__IEPRC_IERB_BASE)
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base pointer */
  #define NETC__IEPRC_1__IEPRC_IERB_NS             ((ieprc_ierb_Type *)NETC__IEPRC_1__IEPRC_IERB_BASE_NS)
  /** Array initializer of ieprc_ierb peripheral base addresses */
  #define ieprc_ierb_BASE_ADDRS                    { NETC__IEPRC_1__IEPRC_IERB_BASE }
  /** Array initializer of ieprc_ierb peripheral base pointers */
  #define ieprc_ierb_BASE_PTRS                     { NETC__IEPRC_1__IEPRC_IERB }
  /** Array initializer of ieprc_ierb peripheral base addresses */
  #define ieprc_ierb_BASE_ADDRS_NS                 { NETC__IEPRC_1__IEPRC_IERB_BASE_NS }
  /** Array initializer of ieprc_ierb peripheral base pointers */
  #define ieprc_ierb_BASE_PTRS_NS                  { NETC__IEPRC_1__IEPRC_IERB_NS }
#else
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base address */
  #define NETC__IEPRC_1__IEPRC_IERB_BASE           (0x4C8A0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base pointer */
  #define NETC__IEPRC_1__IEPRC_IERB                ((ieprc_ierb_Type *)NETC__IEPRC_1__IEPRC_IERB_BASE)
  /** Array initializer of ieprc_ierb peripheral base addresses */
  #define ieprc_ierb_BASE_ADDRS                    { NETC__IEPRC_1__IEPRC_IERB_BASE }
  /** Array initializer of ieprc_ierb peripheral base pointers */
  #define ieprc_ierb_BASE_PTRS                     { NETC__IEPRC_1__IEPRC_IERB }
#endif

/* ieprc_pci - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base address */
  #define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE (0x5CA08000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base address */
  #define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE_NS (0x4CA08000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_NS ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base address */
  #define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE (0x5CB08000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base address */
  #define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE_NS (0x4CB08000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_NS ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of ieprc_pci peripheral base addresses */
  #define ieprc_pci_BASE_ADDRS                     { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE }
  /** Array initializer of ieprc_pci peripheral base pointers */
  #define ieprc_pci_BASE_PTRS                      { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 }
  /** Array initializer of ieprc_pci peripheral base addresses */
  #define ieprc_pci_BASE_ADDRS_NS                  { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE_NS, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of ieprc_pci peripheral base pointers */
  #define ieprc_pci_BASE_PTRS_NS                   { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_NS, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_NS }
#else
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
#endif

/* ieprc_prb - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base address */
  #define NETC__IEPRC_1__IEPRC_PRB_BASE            (0x5C8B0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base address */
  #define NETC__IEPRC_1__IEPRC_PRB_BASE_NS         (0x4C8B0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base pointer */
  #define NETC__IEPRC_1__IEPRC_PRB                 ((ieprc_prb_Type *)NETC__IEPRC_1__IEPRC_PRB_BASE)
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base pointer */
  #define NETC__IEPRC_1__IEPRC_PRB_NS              ((ieprc_prb_Type *)NETC__IEPRC_1__IEPRC_PRB_BASE_NS)
  /** Array initializer of ieprc_prb peripheral base addresses */
  #define ieprc_prb_BASE_ADDRS                     { NETC__IEPRC_1__IEPRC_PRB_BASE }
  /** Array initializer of ieprc_prb peripheral base pointers */
  #define ieprc_prb_BASE_PTRS                      { NETC__IEPRC_1__IEPRC_PRB }
  /** Array initializer of ieprc_prb peripheral base addresses */
  #define ieprc_prb_BASE_ADDRS_NS                  { NETC__IEPRC_1__IEPRC_PRB_BASE_NS }
  /** Array initializer of ieprc_prb peripheral base pointers */
  #define ieprc_prb_BASE_PTRS_NS                   { NETC__IEPRC_1__IEPRC_PRB_NS }
#else
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base address */
  #define NETC__IEPRC_1__IEPRC_PRB_BASE            (0x4C8B0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base pointer */
  #define NETC__IEPRC_1__IEPRC_PRB                 ((ieprc_prb_Type *)NETC__IEPRC_1__IEPRC_PRB_BASE)
  /** Array initializer of ieprc_prb peripheral base addresses */
  #define ieprc_prb_BASE_ADDRS                     { NETC__IEPRC_1__IEPRC_PRB_BASE }
  /** Array initializer of ieprc_prb peripheral base pointers */
  #define ieprc_prb_BASE_PTRS                      { NETC__IEPRC_1__IEPRC_PRB }
#endif

/* m_e_3_wr_I_main_TranStatFilt - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x59063280u)
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x49063280u)
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER ((m_e_3_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_NS ((m_e_3_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of m_e_3_wr_I_main_TranStatFilt peripheral base addresses
   * */
  #define m_e_3_wr_I_main_TranStatFilt_BASE_ADDRS  { NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of m_e_3_wr_I_main_TranStatFilt peripheral base pointers */
  #define m_e_3_wr_I_main_TranStatFilt_BASE_PTRS   { NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of m_e_3_wr_I_main_TranStatFilt peripheral base addresses
   * */
  #define m_e_3_wr_I_main_TranStatFilt_BASE_ADDRS_NS { NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of m_e_3_wr_I_main_TranStatFilt peripheral base pointers */
  #define m_e_3_wr_I_main_TranStatFilt_BASE_PTRS_NS { NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x49063280u)
  /** Peripheral NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER ((m_e_3_wr_I_main_TranStatFilt_Type *)NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Array initializer of m_e_3_wr_I_main_TranStatFilt peripheral base addresses
   * */
  #define m_e_3_wr_I_main_TranStatFilt_BASE_ADDRS  { NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of m_e_3_wr_I_main_TranStatFilt peripheral base pointers */
  #define m_e_3_wr_I_main_TranStatFilt_BASE_PTRS   { NOC__GPV__M_E_3_WR_I_MAIN_TRANSACTIONSTATFILTER }
#endif

/* m_e_9_rd_I_main_TransactionStatFilter - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE (0x59063700u)
  /** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER base address */
  #define NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS (0x49063700u)
  /** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER ((m_e_9_rd_I_main_TransactionStatFilter_Type *)NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE)
  /** Peripheral NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER base pointer */
  #define NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER_NS ((m_e_9_rd_I_main_TransactionStatFilter_Type *)NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS)
  /** Array initializer of m_e_9_rd_I_main_TransactionStatFilter peripheral base
   * addresses */
  #define m_e_9_rd_I_main_TransactionStatFilter_BASE_ADDRS { NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE }
  /** Array initializer of m_e_9_rd_I_main_TransactionStatFilter peripheral base
   * pointers */
  #define m_e_9_rd_I_main_TransactionStatFilter_BASE_PTRS { NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER }
  /** Array initializer of m_e_9_rd_I_main_TransactionStatFilter peripheral base
   * addresses */
  #define m_e_9_rd_I_main_TransactionStatFilter_BASE_ADDRS_NS { NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER_BASE_NS }
  /** Array initializer of m_e_9_rd_I_main_TransactionStatFilter peripheral base
   * pointers */
  #define m_e_9_rd_I_main_TransactionStatFilter_BASE_PTRS_NS { NOC__GPV__M_E_9_RD_I_MAIN_TRANSACTIONSTATFILTER_NS }
#else
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
#endif

/* neutrons - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC base address */
  #define NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC_BASE (0x5AC00000u)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC base address */
  #define NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC_BASE_NS (0x4AC00000u)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC base pointer */
  #define NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC     ((neutrons_Type *)NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC_BASE)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC base pointer */
  #define NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC_NS  ((neutrons_Type *)NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC_BASE_NS)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV base address */
  #define NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV_BASE (0x5AB80000u)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV base address */
  #define NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV_BASE_NS (0x4AB80000u)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV base pointer */
  #define NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV      ((neutrons_Type *)NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV_BASE)
  /** Peripheral NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV base pointer */
  #define NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV_NS   ((neutrons_Type *)NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV_BASE_NS)
  /** Array initializer of neutrons peripheral base addresses */
  #define neutrons_BASE_ADDRS                      { NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC_BASE, NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV_BASE }
  /** Array initializer of neutrons peripheral base pointers */
  #define neutrons_BASE_PTRS                       { NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC, NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV }
  /** Array initializer of neutrons peripheral base addresses */
  #define neutrons_BASE_ADDRS_NS                   { NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC_BASE_NS, NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV_BASE_NS }
  /** Array initializer of neutrons peripheral base pointers */
  #define neutrons_BASE_PTRS_NS                    { NPU__NEUTRON_NPU__NEUTRON_S__MMR_SOC_NS, NPU__NEUTRON_NPU__NEUTRON_S__MMR_ZV_NS }
#else
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


#endif  /* MIMX94398_CM33_CORE0_COMMON_H_ */
