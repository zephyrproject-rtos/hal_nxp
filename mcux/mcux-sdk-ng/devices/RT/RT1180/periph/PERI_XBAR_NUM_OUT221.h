/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181XVP2B
**                          MIMXRT1182CVP2B
**                          MIMXRT1182XVP2B
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**
**     Version:             rev. 2.0, 2024-01-18
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XBAR_NUM_OUT221
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
 * @file XBAR_NUM_OUT221.h
 * @version 2.0
 * @date 2024-01-18
 * @brief CMSIS Peripheral Access Layer for XBAR_NUM_OUT221
 *
 * CMSIS Peripheral Access Layer for XBAR_NUM_OUT221
 */

#if !defined(XBAR_NUM_OUT221_H_)
#define XBAR_NUM_OUT221_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181XVP2B))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182XVP2B))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(XBAR_INPUT_SIGNAL_T_)
#define XBAR_INPUT_SIGNAL_T_
typedef enum _xbar_input_signal
{
    kXBAR1_InputLogicLow            = 0|0x10000U,  /**< LOGIC_LOW output assigned to XBAR1_IN0 input. */
    kXBAR1_InputLogicHigh           = 1|0x10000U,  /**< LOGIC_HIGH output assigned to XBAR1_IN1 input. */
    kXBAR1_InputLogicLow1           = 2|0x10000U,  /**< LOGIC_LOW1 output assigned to XBAR1_IN2 input. */
    kXBAR1_InputLogicHigh1          = 3|0x10000U,  /**< LOGIC_HIGH1 output assigned to XBAR1_IN3 input. */
    kXBAR1_InputIomuxXbarInout04    = 4|0x10000U,  /**< IOMUX_XBAR_INOUT04 output assigned to XBAR1_IN4 input. */
    kXBAR1_InputIomuxXbarInout05    = 5|0x10000U,  /**< IOMUX_XBAR_INOUT05 output assigned to XBAR1_IN5 input. */
    kXBAR1_InputIomuxXbarInout06    = 6|0x10000U,  /**< IOMUX_XBAR_INOUT06 output assigned to XBAR1_IN6 input. */
    kXBAR1_InputIomuxXbarInout07    = 7|0x10000U,  /**< IOMUX_XBAR_INOUT07 output assigned to XBAR1_IN7 input. */
    kXBAR1_InputIomuxXbarInout08    = 8|0x10000U,  /**< IOMUX_XBAR_INOUT08 output assigned to XBAR1_IN8 input. */
    kXBAR1_InputIomuxXbarInout09    = 9|0x10000U,  /**< IOMUX_XBAR_INOUT09 output assigned to XBAR1_IN9 input. */
    kXBAR1_InputIomuxXbarInout10    = 10|0x10000U, /**< IOMUX_XBAR_INOUT10 output assigned to XBAR1_IN10 input. */
    kXBAR1_InputIomuxXbarInout11    = 11|0x10000U, /**< IOMUX_XBAR_INOUT11 output assigned to XBAR1_IN11 input. */
    kXBAR1_InputIomuxXbarInout12    = 12|0x10000U, /**< IOMUX_XBAR_INOUT12 output assigned to XBAR1_IN12 input. */
    kXBAR1_InputIomuxXbarInout13    = 13|0x10000U, /**< IOMUX_XBAR_INOUT13 output assigned to XBAR1_IN13 input. */
    kXBAR1_InputIomuxXbarInout14    = 14|0x10000U, /**< IOMUX_XBAR_INOUT14 output assigned to XBAR1_IN14 input. */
    kXBAR1_InputIomuxXbarInout15    = 15|0x10000U, /**< IOMUX_XBAR_INOUT15 output assigned to XBAR1_IN15 input. */
    kXBAR1_InputIomuxXbarInout16    = 16|0x10000U, /**< IOMUX_XBAR_INOUT16 output assigned to XBAR1_IN16 input. */
    kXBAR1_InputIomuxXbarInout17    = 17|0x10000U, /**< IOMUX_XBAR_INOUT17 output assigned to XBAR1_IN17 input. */
    kXBAR1_InputIomuxXbarInout18    = 18|0x10000U, /**< IOMUX_XBAR_INOUT18 output assigned to XBAR1_IN18 input. */
    kXBAR1_InputIomuxXbarInout19    = 19|0x10000U, /**< IOMUX_XBAR_INOUT19 output assigned to XBAR1_IN19 input. */
    kXBAR1_InputIomuxXbarInout20    = 20|0x10000U, /**< IOMUX_XBAR_INOUT20 output assigned to XBAR1_IN20 input. */
    kXBAR1_InputIomuxXbarInout21    = 21|0x10000U, /**< IOMUX_XBAR_INOUT21 output assigned to XBAR1_IN21 input. */
    kXBAR1_InputIomuxXbarInout22    = 22|0x10000U, /**< IOMUX_XBAR_INOUT22 output assigned to XBAR1_IN22 input. */
    kXBAR1_InputIomuxXbarInout23    = 23|0x10000U, /**< IOMUX_XBAR_INOUT23 output assigned to XBAR1_IN23 input. */
    kXBAR1_InputIomuxXbarInout24    = 24|0x10000U, /**< IOMUX_XBAR_INOUT24 output assigned to XBAR1_IN24 input. */
    kXBAR1_InputIomuxXbarInout25    = 25|0x10000U, /**< IOMUX_XBAR_INOUT25 output assigned to XBAR1_IN25 input. */
    kXBAR1_InputIomuxXbarInout26    = 26|0x10000U, /**< IOMUX_XBAR_INOUT26 output assigned to XBAR1_IN26 input. */
    kXBAR1_InputIomuxXbarInout27    = 27|0x10000U, /**< IOMUX_XBAR_INOUT27 output assigned to XBAR1_IN27 input. */
    kXBAR1_InputIomuxXbarInout28    = 28|0x10000U, /**< IOMUX_XBAR_INOUT28 output assigned to XBAR1_IN28 input. */
    kXBAR1_InputIomuxXbarInout29    = 29|0x10000U, /**< IOMUX_XBAR_INOUT29 output assigned to XBAR1_IN29 input. */
    kXBAR1_InputIomuxXbarInout30    = 30|0x10000U, /**< IOMUX_XBAR_INOUT30 output assigned to XBAR1_IN30 input. */
    kXBAR1_InputIomuxXbarInout31    = 31|0x10000U, /**< IOMUX_XBAR_INOUT31 output assigned to XBAR1_IN31 input. */
    kXBAR1_InputIomuxXbarInout32    = 32|0x10000U, /**< IOMUX_XBAR_INOUT32 output assigned to XBAR1_IN32 input. */
    kXBAR1_InputIomuxXbarInout33    = 33|0x10000U, /**< IOMUX_XBAR_INOUT33 output assigned to XBAR1_IN33 input. */
    kXBAR1_InputIomuxXbarInout34    = 34|0x10000U, /**< IOMUX_XBAR_INOUT34 output assigned to XBAR1_IN34 input. */
    kXBAR1_InputIomuxXbarInout35    = 35|0x10000U, /**< IOMUX_XBAR_INOUT35 output assigned to XBAR1_IN35 input. */
    kXBAR1_InputIomuxXbarInout36    = 36|0x10000U, /**< IOMUX_XBAR_INOUT36 output assigned to XBAR1_IN36 input. */
    kXBAR1_InputIomuxXbarInout37    = 37|0x10000U, /**< IOMUX_XBAR_INOUT37 output assigned to XBAR1_IN37 input. */
    kXBAR1_InputAcmp1Out            = 38|0x10000U, /**< ACMP1_OUT output assigned to XBAR1_IN38 input. */
    kXBAR1_InputAcmp2Out            = 39|0x10000U, /**< ACMP2_OUT output assigned to XBAR1_IN39 input. */
    kXBAR1_InputAcmp3Out            = 40|0x10000U, /**< ACMP3_OUT output assigned to XBAR1_IN40 input. */
    kXBAR1_InputAcmp4Out            = 41|0x10000U, /**< ACMP4_OUT output assigned to XBAR1_IN41 input. */
    kXBAR1_InputQtimer1Timer0       = 42|0x10000U, /**< QTIMER1_TIMER0 output assigned to XBAR1_IN42 input. */
    kXBAR1_InputQtimer1Timer1       = 43|0x10000U, /**< QTIMER1_TIMER1 output assigned to XBAR1_IN43 input. */
    kXBAR1_InputQtimer1Timer2       = 44|0x10000U, /**< QTIMER1_TIMER2 output assigned to XBAR1_IN44 input. */
    kXBAR1_InputQtimer1Timer3       = 45|0x10000U, /**< QTIMER1_TIMER3 output assigned to XBAR1_IN45 input. */
    kXBAR1_InputQtimer2Timer0       = 46|0x10000U, /**< QTIMER2_TIMER0 output assigned to XBAR1_IN46 input. */
    kXBAR1_InputQtimer2Timer1       = 47|0x10000U, /**< QTIMER2_TIMER1 output assigned to XBAR1_IN47 input. */
    kXBAR1_InputQtimer2Timer2       = 48|0x10000U, /**< QTIMER2_TIMER2 output assigned to XBAR1_IN48 input. */
    kXBAR1_InputQtimer2Timer3       = 49|0x10000U, /**< QTIMER2_TIMER3 output assigned to XBAR1_IN49 input. */
    kXBAR1_InputQtimer3Timer0       = 50|0x10000U, /**< QTIMER3_TIMER0 output assigned to XBAR1_IN50 input. */
    kXBAR1_InputQtimer3Timer1       = 51|0x10000U, /**< QTIMER3_TIMER1 output assigned to XBAR1_IN51 input. */
    kXBAR1_InputQtimer3Timer2       = 52|0x10000U, /**< QTIMER3_TIMER2 output assigned to XBAR1_IN52 input. */
    kXBAR1_InputQtimer3Timer3       = 53|0x10000U, /**< QTIMER3_TIMER3 output assigned to XBAR1_IN53 input. */
    kXBAR1_InputQtimer4Timer0       = 54|0x10000U, /**< QTIMER4_TIMER0 output assigned to XBAR1_IN54 input. */
    kXBAR1_InputQtimer4Timer1       = 55|0x10000U, /**< QTIMER4_TIMER1 output assigned to XBAR1_IN55 input. */
    kXBAR1_InputQtimer4Timer2       = 56|0x10000U, /**< QTIMER4_TIMER2 output assigned to XBAR1_IN56 input. */
    kXBAR1_InputQtimer4Timer3       = 57|0x10000U, /**< QTIMER4_TIMER3 output assigned to XBAR1_IN57 input. */
    kXBAR1_InputQtimer5Timer0       = 58|0x10000U, /**< QTIMER5_TIMER0 output assigned to XBAR1_IN58 input. */
    kXBAR1_InputQtimer5Timer1       = 59|0x10000U, /**< QTIMER5_TIMER1 output assigned to XBAR1_IN59 input. */
    kXBAR1_InputQtimer5Timer2       = 60|0x10000U, /**< QTIMER5_TIMER2 output assigned to XBAR1_IN60 input. */
    kXBAR1_InputQtimer5Timer3       = 61|0x10000U, /**< QTIMER5_TIMER3 output assigned to XBAR1_IN61 input. */
    kXBAR1_InputQtimer6Timer0       = 62|0x10000U, /**< QTIMER6_TIMER0 output assigned to XBAR1_IN62 input. */
    kXBAR1_InputQtimer6Timer1       = 63|0x10000U, /**< QTIMER6_TIMER1 output assigned to XBAR1_IN63 input. */
    kXBAR1_InputQtimer6Timer2       = 64|0x10000U, /**< QTIMER6_TIMER2 output assigned to XBAR1_IN64 input. */
    kXBAR1_InputQtimer6Timer3       = 65|0x10000U, /**< QTIMER6_TIMER3 output assigned to XBAR1_IN65 input. */
    kXBAR1_InputQtimer7Timer0       = 66|0x10000U, /**< QTIMER7_TIMER0 output assigned to XBAR1_IN66 input. */
    kXBAR1_InputQtimer7Timer1       = 67|0x10000U, /**< QTIMER7_TIMER1 output assigned to XBAR1_IN67 input. */
    kXBAR1_InputQtimer7Timer2       = 68|0x10000U, /**< QTIMER7_TIMER2 output assigned to XBAR1_IN68 input. */
    kXBAR1_InputQtimer7Timer3       = 69|0x10000U, /**< QTIMER7_TIMER3 output assigned to XBAR1_IN69 input. */
    kXBAR1_InputQtimer8Timer0       = 70|0x10000U, /**< QTIMER8_TIMER0 output assigned to XBAR1_IN70 input. */
    kXBAR1_InputQtimer8Timer1       = 71|0x10000U, /**< QTIMER8_TIMER1 output assigned to XBAR1_IN71 input. */
    kXBAR1_InputQtimer8Timer2       = 72|0x10000U, /**< QTIMER8_TIMER2 output assigned to XBAR1_IN72 input. */
    kXBAR1_InputQtimer8Timer3       = 73|0x10000U, /**< QTIMER8_TIMER3 output assigned to XBAR1_IN73 input. */
    kXBAR1_InputFlexpwm1Pwm0OutTrig0 = 74|0x10000U, /**< FLEXPWM1_PWM0_OUT_TRIG0 output assigned to XBAR1_IN74 input. */
    kXBAR1_InputFlexpwm1Pwm0OutTrig1 = 75|0x10000U, /**< FLEXPWM1_PWM0_OUT_TRIG1 output assigned to XBAR1_IN75 input. */
    kXBAR1_InputFlexpwm1Pwm1OutTrig0 = 76|0x10000U, /**< FLEXPWM1_PWM1_OUT_TRIG0 output assigned to XBAR1_IN76 input. */
    kXBAR1_InputFlexpwm1Pwm1OutTrig1 = 77|0x10000U, /**< FLEXPWM1_PWM1_OUT_TRIG1 output assigned to XBAR1_IN77 input. */
    kXBAR1_InputFlexpwm1Pwm2OutTrig0 = 78|0x10000U, /**< FLEXPWM1_PWM2_OUT_TRIG0 output assigned to XBAR1_IN78 input. */
    kXBAR1_InputFlexpwm1Pwm2OutTrig1 = 79|0x10000U, /**< FLEXPWM1_PWM2_OUT_TRIG1 output assigned to XBAR1_IN79 input. */
    kXBAR1_InputFlexpwm1Pwm3OutTrig0 = 80|0x10000U, /**< FLEXPWM1_PWM3_OUT_TRIG0 output assigned to XBAR1_IN80 input. */
    kXBAR1_InputFlexpwm1Pwm3OutTrig1 = 81|0x10000U, /**< FLEXPWM1_PWM3_OUT_TRIG1 output assigned to XBAR1_IN81 input. */
    kXBAR1_InputFlexpwm2Pwm0OutTrig01 = 82|0x10000U, /**< FLEXPWM2_PWM0_OUT_TRIG0_1 output assigned to XBAR1_IN82 input. */
    kXBAR1_InputFlexpwm2Pwm1OutTrig01 = 83|0x10000U, /**< FLEXPWM2_PWM1_OUT_TRIG0_1 output assigned to XBAR1_IN83 input. */
    kXBAR1_InputFlexpwm2Pwm2OutTrig01 = 84|0x10000U, /**< FLEXPWM2_PWM2_OUT_TRIG0_1 output assigned to XBAR1_IN84 input. */
    kXBAR1_InputFlexpwm2Pwm3OutTrig01 = 85|0x10000U, /**< FLEXPWM2_PWM3_OUT_TRIG0_1 output assigned to XBAR1_IN85 input. */
    kXBAR1_InputFlexpwm3Pwm0OutTrig01 = 86|0x10000U, /**< FLEXPWM3_PWM0_OUT_TRIG0_1 output assigned to XBAR1_IN86 input. */
    kXBAR1_InputFlexpwm3Pwm1OutTrig01 = 87|0x10000U, /**< FLEXPWM3_PWM1_OUT_TRIG0_1 output assigned to XBAR1_IN87 input. */
    kXBAR1_InputFlexpwm3Pwm2OutTrig01 = 88|0x10000U, /**< FLEXPWM3_PWM2_OUT_TRIG0_1 output assigned to XBAR1_IN88 input. */
    kXBAR1_InputFlexpwm3Pwm3OutTrig01 = 89|0x10000U, /**< FLEXPWM3_PWM3_OUT_TRIG0_1 output assigned to XBAR1_IN89 input. */
    kXBAR1_InputFlexpwm4Pwm0OutTrig01 = 90|0x10000U, /**< FLEXPWM4_PWM0_OUT_TRIG0_1 output assigned to XBAR1_IN90 input. */
    kXBAR1_InputFlexpwm4Pwm1OutTrig01 = 91|0x10000U, /**< FLEXPWM4_PWM1_OUT_TRIG0_1 output assigned to XBAR1_IN91 input. */
    kXBAR1_InputFlexpwm4Pwm2OutTrig01 = 92|0x10000U, /**< FLEXPWM4_PWM2_OUT_TRIG0_1 output assigned to XBAR1_IN92 input. */
    kXBAR1_InputFlexpwm4Pwm3OutTrig01 = 93|0x10000U, /**< FLEXPWM4_PWM3_OUT_TRIG0_1 output assigned to XBAR1_IN93 input. */
    kXBAR1_InputPit1Trigger0        = 94|0x10000U, /**< PIT1_TRIGGER0 output assigned to XBAR1_IN94 input. */
    kXBAR1_InputPit1Trigger1        = 95|0x10000U, /**< PIT1_TRIGGER1 output assigned to XBAR1_IN95 input. */
    kXBAR1_InputPit1Trigger2        = 96|0x10000U, /**< PIT1_TRIGGER2 output assigned to XBAR1_IN96 input. */
    kXBAR1_InputPit1Trigger3        = 97|0x10000U, /**< PIT1_TRIGGER3 output assigned to XBAR1_IN97 input. */
    kXBAR1_InputPit2Trigger0        = 98|0x10000U, /**< PIT2_TRIGGER0 output assigned to XBAR1_IN98 input. */
    kXBAR1_InputPit2Trigger1        = 99|0x10000U, /**< PIT2_TRIGGER1 output assigned to XBAR1_IN99 input. */
    kXBAR1_InputPit2Trigger2        = 100|0x10000U, /**< PIT2_TRIGGER2 output assigned to XBAR1_IN100 input. */
    kXBAR1_InputPit2Trigger3        = 101|0x10000U, /**< PIT2_TRIGGER3 output assigned to XBAR1_IN101 input. */
    kXBAR1_InputPit3Trigger0        = 102|0x10000U, /**< PIT3_TRIGGER0 output assigned to XBAR1_IN102 input. */
    kXBAR1_InputPit3Trigger1        = 103|0x10000U, /**< PIT3_TRIGGER1 output assigned to XBAR1_IN103 input. */
    kXBAR1_InputPit3Trigger2        = 104|0x10000U, /**< PIT3_TRIGGER2 output assigned to XBAR1_IN104 input. */
    kXBAR1_InputPit3Trigger3        = 105|0x10000U, /**< PIT3_TRIGGER3 output assigned to XBAR1_IN105 input. */
    kXBAR1_InputTriggerSyncOut0     = 106|0x10000U, /**< TRIGGER_SYNC_OUT0 output assigned to XBAR1_IN106 input. */
    kXBAR1_InputTriggerSyncOut1     = 107|0x10000U, /**< TRIGGER_SYNC_OUT1 output assigned to XBAR1_IN107 input. */
    kXBAR1_InputTriggerSyncOut2     = 108|0x10000U, /**< TRIGGER_SYNC_OUT2 output assigned to XBAR1_IN108 input. */
    kXBAR1_InputTriggerSyncOut3     = 109|0x10000U, /**< TRIGGER_SYNC_OUT3 output assigned to XBAR1_IN109 input. */
    kXBAR1_InputDma4TriggerOut0     = 110|0x10000U, /**< DMA4_TRIGGER_OUT0 output assigned to XBAR1_IN110 input. */
    kXBAR1_InputDma4TriggerOut1     = 111|0x10000U, /**< DMA4_TRIGGER_OUT1 output assigned to XBAR1_IN111 input. */
    kXBAR1_InputDma4TriggerOut2     = 112|0x10000U, /**< DMA4_TRIGGER_OUT2 output assigned to XBAR1_IN112 input. */
    kXBAR1_InputDma4TriggerOut3     = 113|0x10000U, /**< DMA4_TRIGGER_OUT3 output assigned to XBAR1_IN113 input. */
    kXBAR1_InputDma4TriggerOut4     = 114|0x10000U, /**< DMA4_TRIGGER_OUT4 output assigned to XBAR1_IN114 input. */
    kXBAR1_InputDma4TriggerOut5     = 115|0x10000U, /**< DMA4_TRIGGER_OUT5 output assigned to XBAR1_IN115 input. */
    kXBAR1_InputDma4TriggerOut6     = 116|0x10000U, /**< DMA4_TRIGGER_OUT6 output assigned to XBAR1_IN116 input. */
    kXBAR1_InputDma4TriggerOut7     = 117|0x10000U, /**< DMA4_TRIGGER_OUT7 output assigned to XBAR1_IN117 input. */
    kXBAR1_InputDma3TriggerOut0     = 118|0x10000U, /**< DMA3_TRIGGER_OUT0 output assigned to XBAR1_IN118 input. */
    kXBAR1_InputDma3TriggerOut1     = 119|0x10000U, /**< DMA3_TRIGGER_OUT1 output assigned to XBAR1_IN119 input. */
    kXBAR1_InputDma3TriggerOut2     = 120|0x10000U, /**< DMA3_TRIGGER_OUT2 output assigned to XBAR1_IN120 input. */
    kXBAR1_InputDma3TriggerOut3     = 121|0x10000U, /**< DMA3_TRIGGER_OUT3 output assigned to XBAR1_IN121 input. */
    kXBAR1_InputDma3TriggerOut4     = 122|0x10000U, /**< DMA3_TRIGGER_OUT4 output assigned to XBAR1_IN122 input. */
    kXBAR1_InputDma3TriggerOut5     = 123|0x10000U, /**< DMA3_TRIGGER_OUT5 output assigned to XBAR1_IN123 input. */
    kXBAR1_InputDma3TriggerOut6     = 124|0x10000U, /**< DMA3_TRIGGER_OUT6 output assigned to XBAR1_IN124 input. */
    kXBAR1_InputDma3TriggerOut7     = 125|0x10000U, /**< DMA3_TRIGGER_OUT7 output assigned to XBAR1_IN125 input. */
    kXBAR1_InputAdc1TcompPulse0     = 126|0x10000U, /**< ADC1_TCOMP_PULSE0 output assigned to XBAR1_IN126 input. */
    kXBAR1_InputAdc1TcompPulse1     = 127|0x10000U, /**< ADC1_TCOMP_PULSE1 output assigned to XBAR1_IN127 input. */
    kXBAR1_InputAdc1TcompPulse2     = 128|0x10000U, /**< ADC1_TCOMP_PULSE2 output assigned to XBAR1_IN128 input. */
    kXBAR1_InputAdc1TcompPulse3     = 129|0x10000U, /**< ADC1_TCOMP_PULSE3 output assigned to XBAR1_IN129 input. */
    kXBAR1_InputAdc1TcompPulse4     = 130|0x10000U, /**< ADC1_TCOMP_PULSE4 output assigned to XBAR1_IN130 input. */
    kXBAR1_InputAdc1TcompPulse5     = 131|0x10000U, /**< ADC1_TCOMP_PULSE5 output assigned to XBAR1_IN131 input. */
    kXBAR1_InputAdc1TcompPulse6     = 132|0x10000U, /**< ADC1_TCOMP_PULSE6 output assigned to XBAR1_IN132 input. */
    kXBAR1_InputAdc1TcompPulse7     = 133|0x10000U, /**< ADC1_TCOMP_PULSE7 output assigned to XBAR1_IN133 input. */
    kXBAR1_InputAdc2TcompPulse0     = 134|0x10000U, /**< ADC2_TCOMP_PULSE0 output assigned to XBAR1_IN134 input. */
    kXBAR1_InputAdc2TcompPulse1     = 135|0x10000U, /**< ADC2_TCOMP_PULSE1 output assigned to XBAR1_IN135 input. */
    kXBAR1_InputAdc2TcompPulse2     = 136|0x10000U, /**< ADC2_TCOMP_PULSE2 output assigned to XBAR1_IN136 input. */
    kXBAR1_InputAdc2TcompPulse3     = 137|0x10000U, /**< ADC2_TCOMP_PULSE3 output assigned to XBAR1_IN137 input. */
    kXBAR1_InputAdc2TcompPulse4     = 138|0x10000U, /**< ADC2_TCOMP_PULSE4 output assigned to XBAR1_IN138 input. */
    kXBAR1_InputAdc2TcompPulse5     = 139|0x10000U, /**< ADC2_TCOMP_PULSE5 output assigned to XBAR1_IN139 input. */
    kXBAR1_InputAdc2TcompPulse6     = 140|0x10000U, /**< ADC2_TCOMP_PULSE6 output assigned to XBAR1_IN140 input. */
    kXBAR1_InputAdc2TcompPulse7     = 141|0x10000U, /**< ADC2_TCOMP_PULSE7 output assigned to XBAR1_IN141 input. */
    kXBAR1_InputTpm1ChTrigger0      = 142|0x10000U, /**< TPM1_CH_TRIGGER0 output assigned to XBAR1_IN142 input. */
    kXBAR1_InputTpm1ChTrigger1      = 143|0x10000U, /**< TPM1_CH_TRIGGER1 output assigned to XBAR1_IN143 input. */
    kXBAR1_InputTpm1ChTrigger2      = 144|0x10000U, /**< TPM1_CH_TRIGGER2 output assigned to XBAR1_IN144 input. */
    kXBAR1_InputTpm1ChTrigger3      = 145|0x10000U, /**< TPM1_CH_TRIGGER3 output assigned to XBAR1_IN145 input. */
    kXBAR1_InputTpm1Trigger         = 146|0x10000U, /**< TPM1_TRIGGER output assigned to XBAR1_IN146 input. */
    kXBAR1_InputTpm2ChTrigger0      = 147|0x10000U, /**< TPM2_CH_TRIGGER0 output assigned to XBAR1_IN147 input. */
    kXBAR1_InputTpm2ChTrigger1      = 148|0x10000U, /**< TPM2_CH_TRIGGER1 output assigned to XBAR1_IN148 input. */
    kXBAR1_InputTpm2ChTrigger2      = 149|0x10000U, /**< TPM2_CH_TRIGGER2 output assigned to XBAR1_IN149 input. */
    kXBAR1_InputTpm2ChTrigger3      = 150|0x10000U, /**< TPM2_CH_TRIGGER3 output assigned to XBAR1_IN150 input. */
    kXBAR1_InputTpm2Trigger         = 151|0x10000U, /**< TPM2_TRIGGER output assigned to XBAR1_IN151 input. */
    kXBAR1_InputTpm3ChTrigger0      = 152|0x10000U, /**< TPM3_CH_TRIGGER0 output assigned to XBAR1_IN152 input. */
    kXBAR1_InputTpm3ChTrigger1      = 153|0x10000U, /**< TPM3_CH_TRIGGER1 output assigned to XBAR1_IN153 input. */
    kXBAR1_InputTpm3ChTrigger2      = 154|0x10000U, /**< TPM3_CH_TRIGGER2 output assigned to XBAR1_IN154 input. */
    kXBAR1_InputTpm3ChTrigger3      = 155|0x10000U, /**< TPM3_CH_TRIGGER3 output assigned to XBAR1_IN155 input. */
    kXBAR1_InputTpm3Trigger         = 156|0x10000U, /**< TPM3_TRIGGER output assigned to XBAR1_IN156 input. */
    kXBAR1_InputTpm4ChTrigger0      = 157|0x10000U, /**< TPM4_CH_TRIGGER0 output assigned to XBAR1_IN157 input. */
    kXBAR1_InputTpm4ChTrigger1      = 158|0x10000U, /**< TPM4_CH_TRIGGER1 output assigned to XBAR1_IN158 input. */
    kXBAR1_InputTpm4ChTrigger2      = 159|0x10000U, /**< TPM4_CH_TRIGGER2 output assigned to XBAR1_IN159 input. */
    kXBAR1_InputTpm4ChTrigger3      = 160|0x10000U, /**< TPM4_CH_TRIGGER3 output assigned to XBAR1_IN160 input. */
    kXBAR1_InputTpm4Trigger         = 161|0x10000U, /**< TPM4_TRIGGER output assigned to XBAR1_IN161 input. */
    kXBAR1_InputTpm5ChTrigger0      = 162|0x10000U, /**< TPM5_CH_TRIGGER0 output assigned to XBAR1_IN162 input. */
    kXBAR1_InputTpm5ChTrigger1      = 163|0x10000U, /**< TPM5_CH_TRIGGER1 output assigned to XBAR1_IN163 input. */
    kXBAR1_InputTpm5ChTrigger2      = 164|0x10000U, /**< TPM5_CH_TRIGGER2 output assigned to XBAR1_IN164 input. */
    kXBAR1_InputTpm5ChTrigger3      = 165|0x10000U, /**< TPM5_CH_TRIGGER3 output assigned to XBAR1_IN165 input. */
    kXBAR1_InputTpm5Trigger         = 166|0x10000U, /**< TPM5_TRIGGER output assigned to XBAR1_IN166 input. */
    kXBAR1_InputTpm6ChTrigger0      = 167|0x10000U, /**< TPM6_CH_TRIGGER0 output assigned to XBAR1_IN167 input. */
    kXBAR1_InputTpm6ChTrigger1      = 168|0x10000U, /**< TPM6_CH_TRIGGER1 output assigned to XBAR1_IN168 input. */
    kXBAR1_InputTpm6ChTrigger2      = 169|0x10000U, /**< TPM6_CH_TRIGGER2 output assigned to XBAR1_IN169 input. */
    kXBAR1_InputTpm6ChTrigger3      = 170|0x10000U, /**< TPM6_CH_TRIGGER3 output assigned to XBAR1_IN170 input. */
    kXBAR1_InputTpm6Trigger         = 171|0x10000U, /**< TPM6_TRIGGER output assigned to XBAR1_IN171 input. */
    kXBAR1_InputLptmr1TriggerDelay  = 172|0x10000U, /**< LPTMR1_TRIGGER_DELAY output assigned to XBAR1_IN172 input. */
    kXBAR1_InputLptmr2TriggerDelay  = 173|0x10000U, /**< LPTMR2_TRIGGER_DELAY output assigned to XBAR1_IN173 input. */
    kXBAR1_InputLptmr3TriggerDelay  = 174|0x10000U, /**< LPTMR3_TRIGGER_DELAY output assigned to XBAR1_IN174 input. */
    kXBAR1_InputNetcTmrPp1          = 175|0x10000U, /**< NETC_TMR_PP1 output assigned to XBAR1_IN175 input. */
    kXBAR1_InputNetcTmrPp2          = 176|0x10000U, /**< NETC_TMR_PP2 output assigned to XBAR1_IN176 input. */
    kXBAR1_InputNetcTmrPp3          = 177|0x10000U, /**< NETC_TMR_PP3 output assigned to XBAR1_IN177 input. */
    kXBAR1_InputSinc1IppDoBreak0    = 178|0x10000U, /**< SINC1_IPP_DO_BREAK0 output assigned to XBAR1_IN178 input. */
    kXBAR1_InputSinc1IppDoBreak1    = 179|0x10000U, /**< SINC1_IPP_DO_BREAK1 output assigned to XBAR1_IN179 input. */
    kXBAR1_InputSinc1IppDoBreak2    = 180|0x10000U, /**< SINC1_IPP_DO_BREAK2 output assigned to XBAR1_IN180 input. */
    kXBAR1_InputSinc1IppDoBreak3    = 181|0x10000U, /**< SINC1_IPP_DO_BREAK3 output assigned to XBAR1_IN181 input. */
    kXBAR1_InputSinc2IppDoBreak0    = 182|0x10000U, /**< SINC2_IPP_DO_BREAK0 output assigned to XBAR1_IN182 input. */
    kXBAR1_InputSinc2IppDoBreak1    = 183|0x10000U, /**< SINC2_IPP_DO_BREAK1 output assigned to XBAR1_IN183 input. */
    kXBAR1_InputSinc2IppDoBreak2    = 184|0x10000U, /**< SINC2_IPP_DO_BREAK2 output assigned to XBAR1_IN184 input. */
    kXBAR1_InputSinc2IppDoBreak3    = 185|0x10000U, /**< SINC2_IPP_DO_BREAK3 output assigned to XBAR1_IN185 input. */
    kXBAR1_InputSinc3IppDoBreak0    = 186|0x10000U, /**< SINC3_IPP_DO_BREAK0 output assigned to XBAR1_IN186 input. */
    kXBAR1_InputSinc3IppDoBreak1    = 187|0x10000U, /**< SINC3_IPP_DO_BREAK1 output assigned to XBAR1_IN187 input. */
    kXBAR1_InputSinc3IppDoBreak2    = 188|0x10000U, /**< SINC3_IPP_DO_BREAK2 output assigned to XBAR1_IN188 input. */
    kXBAR1_InputSinc3IppDoBreak3    = 189|0x10000U, /**< SINC3_IPP_DO_BREAK3 output assigned to XBAR1_IN189 input. */
    kXBAR1_InputAoi1Out0            = 190|0x10000U, /**< AOI1_OUT0 output assigned to XBAR1_IN190 input. */
    kXBAR1_InputAoi1Out1            = 191|0x10000U, /**< AOI1_OUT1 output assigned to XBAR1_IN191 input. */
    kXBAR1_InputAoi1Out2            = 192|0x10000U, /**< AOI1_OUT2 output assigned to XBAR1_IN192 input. */
    kXBAR1_InputAoi1Out3            = 193|0x10000U, /**< AOI1_OUT3 output assigned to XBAR1_IN193 input. */
    kXBAR1_InputAoi2Out0            = 194|0x10000U, /**< AOI2_OUT0 output assigned to XBAR1_IN194 input. */
    kXBAR1_InputAoi2Out1            = 195|0x10000U, /**< AOI2_OUT1 output assigned to XBAR1_IN195 input. */
    kXBAR1_InputAoi2Out2            = 196|0x10000U, /**< AOI2_OUT2 output assigned to XBAR1_IN196 input. */
    kXBAR1_InputAoi2Out3            = 197|0x10000U, /**< AOI2_OUT3 output assigned to XBAR1_IN197 input. */
    kXBAR1_InputTriggerSyncOut4     = 198|0x10000U, /**< TRIGGER_SYNC_OUT4 output assigned to XBAR1_IN198 input. */
    kXBAR1_InputTriggerSyncOut5     = 199|0x10000U, /**< TRIGGER_SYNC_OUT5 output assigned to XBAR1_IN199 input. */
    kXBAR1_InputTriggerSyncOut6     = 200|0x10000U, /**< TRIGGER_SYNC_OUT6 output assigned to XBAR1_IN200 input. */
    kXBAR1_InputTriggerSyncOut7     = 201|0x10000U, /**< TRIGGER_SYNC_OUT7 output assigned to XBAR1_IN201 input. */
    kXBAR1_InputRESERVED202         = 202|0x10000U, /**< XBAR1_IN202 input is reserved. */
    kXBAR1_InputRESERVED203         = 203|0x10000U, /**< XBAR1_IN203 input is reserved. */
    kXBAR1_InputRESERVED204         = 204|0x10000U, /**< XBAR1_IN204 input is reserved. */
    kXBAR1_InputRESERVED205         = 205|0x10000U, /**< XBAR1_IN205 input is reserved. */
    kXBAR1_InputAoi3Out0            = 206|0x10000U, /**< AOI3_OUT0 output assigned to XBAR1_IN206 input. */
    kXBAR1_InputAoi3Out1            = 207|0x10000U, /**< AOI3_OUT1 output assigned to XBAR1_IN207 input. */
    kXBAR1_InputAoi3Out2            = 208|0x10000U, /**< AOI3_OUT2 output assigned to XBAR1_IN208 input. */
    kXBAR1_InputAoi3Out3            = 209|0x10000U, /**< AOI3_OUT3 output assigned to XBAR1_IN209 input. */
    kXBAR1_InputAoi4Out0            = 210|0x10000U, /**< AOI4_OUT0 output assigned to XBAR1_IN210 input. */
    kXBAR1_InputAoi4Out1            = 211|0x10000U, /**< AOI4_OUT1 output assigned to XBAR1_IN211 input. */
    kXBAR1_InputAoi4Out2            = 212|0x10000U, /**< AOI4_OUT2 output assigned to XBAR1_IN212 input. */
    kXBAR1_InputAoi4Out3            = 213|0x10000U, /**< AOI4_OUT3 output assigned to XBAR1_IN213 input. */
    kXBAR1_InputEcatSyncOut0        = 214|0x10000U, /**< ECAT_SYNC_OUT0 output assigned to XBAR1_IN214 input. */
    kXBAR1_InputEcatSyncOut1        = 215|0x10000U, /**< ECAT_SYNC_OUT1 output assigned to XBAR1_IN215 input. */
    kXBAR2_InputLogicLow            = 0|0x20000U,  /**< LOGIC_LOW output assigned to XBAR2_IN0 input. */
    kXBAR2_InputLogicHigh           = 1|0x20000U,  /**< LOGIC_HIGH output assigned to XBAR2_IN1 input. */
    kXBAR2_InputLogicLow1           = 2|0x20000U,  /**< LOGIC_LOW1 output assigned to XBAR2_IN2 input. */
    kXBAR2_InputLogicHigh1          = 3|0x20000U,  /**< LOGIC_HIGH1 output assigned to XBAR2_IN3 input. */
    kXBAR2_InputAcmp1Out            = 4|0x20000U,  /**< ACMP1_OUT output assigned to XBAR2_IN4 input. */
    kXBAR2_InputAcmp2Out            = 5|0x20000U,  /**< ACMP2_OUT output assigned to XBAR2_IN5 input. */
    kXBAR2_InputAcmp3Out            = 6|0x20000U,  /**< ACMP3_OUT output assigned to XBAR2_IN6 input. */
    kXBAR2_InputAcmp4Out            = 7|0x20000U,  /**< ACMP4_OUT output assigned to XBAR2_IN7 input. */
    kXBAR2_InputQtimer1Timer0       = 8|0x20000U,  /**< QTIMER1_TIMER0 output assigned to XBAR2_IN8 input. */
    kXBAR2_InputQtimer1Timer1       = 9|0x20000U,  /**< QTIMER1_TIMER1 output assigned to XBAR2_IN9 input. */
    kXBAR2_InputQtimer1Timer2       = 10|0x20000U, /**< QTIMER1_TIMER2 output assigned to XBAR2_IN10 input. */
    kXBAR2_InputQtimer1Timer3       = 11|0x20000U, /**< QTIMER1_TIMER3 output assigned to XBAR2_IN11 input. */
    kXBAR2_InputQtimer2Timer0       = 12|0x20000U, /**< QTIMER2_TIMER0 output assigned to XBAR2_IN12 input. */
    kXBAR2_InputQtimer2Timer1       = 13|0x20000U, /**< QTIMER2_TIMER1 output assigned to XBAR2_IN13 input. */
    kXBAR2_InputQtimer2Timer2       = 14|0x20000U, /**< QTIMER2_TIMER2 output assigned to XBAR2_IN14 input. */
    kXBAR2_InputQtimer2Timer3       = 15|0x20000U, /**< QTIMER2_TIMER3 output assigned to XBAR2_IN15 input. */
    kXBAR2_InputQtimer3Timer0       = 16|0x20000U, /**< QTIMER3_TIMER0 output assigned to XBAR2_IN16 input. */
    kXBAR2_InputQtimer3Timer1       = 17|0x20000U, /**< QTIMER3_TIMER1 output assigned to XBAR2_IN17 input. */
    kXBAR2_InputQtimer3Timer2       = 18|0x20000U, /**< QTIMER3_TIMER2 output assigned to XBAR2_IN18 input. */
    kXBAR2_InputQtimer3Timer3       = 19|0x20000U, /**< QTIMER3_TIMER3 output assigned to XBAR2_IN19 input. */
    kXBAR2_InputQtimer4Timer0       = 20|0x20000U, /**< QTIMER4_TIMER0 output assigned to XBAR2_IN20 input. */
    kXBAR2_InputQtimer4Timer1       = 21|0x20000U, /**< QTIMER4_TIMER1 output assigned to XBAR2_IN21 input. */
    kXBAR2_InputQtimer4Timer2       = 22|0x20000U, /**< QTIMER4_TIMER2 output assigned to XBAR2_IN22 input. */
    kXBAR2_InputQtimer4Timer3       = 23|0x20000U, /**< QTIMER4_TIMER3 output assigned to XBAR2_IN23 input. */
    kXBAR2_InputQtimer5Timer0       = 24|0x20000U, /**< QTIMER5_TIMER0 output assigned to XBAR2_IN24 input. */
    kXBAR2_InputQtimer5Timer1       = 25|0x20000U, /**< QTIMER5_TIMER1 output assigned to XBAR2_IN25 input. */
    kXBAR2_InputQtimer5Timer2       = 26|0x20000U, /**< QTIMER5_TIMER2 output assigned to XBAR2_IN26 input. */
    kXBAR2_InputQtimer5Timer3       = 27|0x20000U, /**< QTIMER5_TIMER3 output assigned to XBAR2_IN27 input. */
    kXBAR2_InputQtimer6Timer0       = 28|0x20000U, /**< QTIMER6_TIMER0 output assigned to XBAR2_IN28 input. */
    kXBAR2_InputQtimer6Timer1       = 29|0x20000U, /**< QTIMER6_TIMER1 output assigned to XBAR2_IN29 input. */
    kXBAR2_InputQtimer6Timer2       = 30|0x20000U, /**< QTIMER6_TIMER2 output assigned to XBAR2_IN30 input. */
    kXBAR2_InputQtimer6Timer3       = 31|0x20000U, /**< QTIMER6_TIMER3 output assigned to XBAR2_IN31 input. */
    kXBAR2_InputQtimer7Timer0       = 32|0x20000U, /**< QTIMER7_TIMER0 output assigned to XBAR2_IN32 input. */
    kXBAR2_InputQtimer7Timer1       = 33|0x20000U, /**< QTIMER7_TIMER1 output assigned to XBAR2_IN33 input. */
    kXBAR2_InputQtimer7Timer2       = 34|0x20000U, /**< QTIMER7_TIMER2 output assigned to XBAR2_IN34 input. */
    kXBAR2_InputQtimer7Timer3       = 35|0x20000U, /**< QTIMER7_TIMER3 output assigned to XBAR2_IN35 input. */
    kXBAR2_InputQtimer8Timer0       = 36|0x20000U, /**< QTIMER8_TIMER0 output assigned to XBAR2_IN36 input. */
    kXBAR2_InputQtimer8Timer1       = 37|0x20000U, /**< QTIMER8_TIMER1 output assigned to XBAR2_IN37 input. */
    kXBAR2_InputQtimer8Timer2       = 38|0x20000U, /**< QTIMER8_TIMER2 output assigned to XBAR2_IN38 input. */
    kXBAR2_InputQtimer8Timer3       = 39|0x20000U, /**< QTIMER8_TIMER3 output assigned to XBAR2_IN39 input. */
    kXBAR2_InputFlexpwm1Pwm0OutTrig01 = 40|0x20000U, /**< FLEXPWM1_PWM0_OUT_TRIG0_1 output assigned to XBAR2_IN40 input. */
    kXBAR2_InputFlexpwm1Pwm1OutTrig01 = 41|0x20000U, /**< FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBAR2_IN41 input. */
    kXBAR2_InputFlexpwm1Pwm2OutTrig01 = 42|0x20000U, /**< FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBAR2_IN42 input. */
    kXBAR2_InputFlexpwm1Pwm3OutTrig01 = 43|0x20000U, /**< FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBAR2_IN43 input. */
    kXBAR2_InputFlexpwm2Pwm0OutTrig01 = 44|0x20000U, /**< FLEXPWM2_PWM0_OUT_TRIG0_1 output assigned to XBAR2_IN44 input. */
    kXBAR2_InputFlexpwm2Pwm1OutTrig01 = 45|0x20000U, /**< FLEXPWM2_PWM1_OUT_TRIG0_1 output assigned to XBAR2_IN45 input. */
    kXBAR2_InputFlexpwm2Pwm2OutTrig01 = 46|0x20000U, /**< FLEXPWM2_PWM2_OUT_TRIG0_1 output assigned to XBAR2_IN46 input. */
    kXBAR2_InputFlexpwm2Pwm3OutTrig01 = 47|0x20000U, /**< FLEXPWM2_PWM3_OUT_TRIG0_1 output assigned to XBAR2_IN47 input. */
    kXBAR2_InputFlexpwm3Pwm0OutTrig01 = 48|0x20000U, /**< FLEXPWM3_PWM0_OUT_TRIG0_1 output assigned to XBAR2_IN48 input. */
    kXBAR2_InputFlexpwm3Pwm1OutTrig01 = 49|0x20000U, /**< FLEXPWM3_PWM1_OUT_TRIG0_1 output assigned to XBAR2_IN49 input. */
    kXBAR2_InputFlexpwm3Pwm2OutTrig01 = 50|0x20000U, /**< FLEXPWM3_PWM2_OUT_TRIG0_1 output assigned to XBAR2_IN50 input. */
    kXBAR2_InputFlexpwm3Pwm3OutTrig01 = 51|0x20000U, /**< FLEXPWM3_PWM3_OUT_TRIG0_1 output assigned to XBAR2_IN51 input. */
    kXBAR2_InputFlexpwm4Pwm0OutTrig01 = 52|0x20000U, /**< FLEXPWM4_PWM0_OUT_TRIG0_1 output assigned to XBAR2_IN52 input. */
    kXBAR2_InputFlexpwm4Pwm1OutTrig01 = 53|0x20000U, /**< FLEXPWM4_PWM1_OUT_TRIG0_1 output assigned to XBAR2_IN53 input. */
    kXBAR2_InputFlexpwm4Pwm2OutTrig01 = 54|0x20000U, /**< FLEXPWM4_PWM2_OUT_TRIG0_1 output assigned to XBAR2_IN54 input. */
    kXBAR2_InputFlexpwm4Pwm3OutTrig01 = 55|0x20000U, /**< FLEXPWM4_PWM3_OUT_TRIG0_1 output assigned to XBAR2_IN55 input. */
    kXBAR2_InputPit1Trigger0        = 56|0x20000U, /**< PIT1_TRIGGER0 output assigned to XBAR2_IN56 input. */
    kXBAR2_InputPit1Trigger1        = 57|0x20000U, /**< PIT1_TRIGGER1 output assigned to XBAR2_IN57 input. */
    kXBAR2_InputPit1Trigger2        = 58|0x20000U, /**< PIT1_TRIGGER2 output assigned to XBAR2_IN58 input. */
    kXBAR2_InputPit1Trigger3        = 59|0x20000U, /**< PIT1_TRIGGER3 output assigned to XBAR2_IN59 input. */
    kXBAR2_InputPit2Trigger0        = 60|0x20000U, /**< PIT2_TRIGGER0 output assigned to XBAR2_IN60 input. */
    kXBAR2_InputPit2Trigger1        = 61|0x20000U, /**< PIT2_TRIGGER1 output assigned to XBAR2_IN61 input. */
    kXBAR2_InputPit2Trigger2        = 62|0x20000U, /**< PIT2_TRIGGER2 output assigned to XBAR2_IN62 input. */
    kXBAR2_InputPit2Trigger3        = 63|0x20000U, /**< PIT2_TRIGGER3 output assigned to XBAR2_IN63 input. */
    kXBAR2_InputPit3Trigger0        = 64|0x20000U, /**< PIT3_TRIGGER0 output assigned to XBAR2_IN64 input. */
    kXBAR2_InputPit3Trigger1        = 65|0x20000U, /**< PIT3_TRIGGER1 output assigned to XBAR2_IN65 input. */
    kXBAR2_InputPit3Trigger2        = 66|0x20000U, /**< PIT3_TRIGGER2 output assigned to XBAR2_IN66 input. */
    kXBAR2_InputPit3Trigger3        = 67|0x20000U, /**< PIT3_TRIGGER3 output assigned to XBAR2_IN67 input. */
    kXBAR2_InputSinc1PulseTrigger0  = 68|0x20000U, /**< SINC1_PULSE_TRIGGER0 output assigned to XBAR2_IN68 input. */
    kXBAR2_InputSinc1PulseTrigger1  = 69|0x20000U, /**< SINC1_PULSE_TRIGGER1 output assigned to XBAR2_IN69 input. */
    kXBAR2_InputSinc1PulseTrigger2  = 70|0x20000U, /**< SINC1_PULSE_TRIGGER2 output assigned to XBAR2_IN70 input. */
    kXBAR2_InputSinc1PulseTrigger3  = 71|0x20000U, /**< SINC1_PULSE_TRIGGER3 output assigned to XBAR2_IN71 input. */
    kXBAR2_InputDma4TriggerOut0     = 72|0x20000U, /**< DMA4_TRIGGER_OUT0 output assigned to XBAR2_IN72 input. */
    kXBAR2_InputDma4TriggerOut1     = 73|0x20000U, /**< DMA4_TRIGGER_OUT1 output assigned to XBAR2_IN73 input. */
    kXBAR2_InputDma4TriggerOut2     = 74|0x20000U, /**< DMA4_TRIGGER_OUT2 output assigned to XBAR2_IN74 input. */
    kXBAR2_InputDma4TriggerOut3     = 75|0x20000U, /**< DMA4_TRIGGER_OUT3 output assigned to XBAR2_IN75 input. */
    kXBAR2_InputDma4TriggerOut4     = 76|0x20000U, /**< DMA4_TRIGGER_OUT4 output assigned to XBAR2_IN76 input. */
    kXBAR2_InputDma4TriggerOut5     = 77|0x20000U, /**< DMA4_TRIGGER_OUT5 output assigned to XBAR2_IN77 input. */
    kXBAR2_InputDma4TriggerOut6     = 78|0x20000U, /**< DMA4_TRIGGER_OUT6 output assigned to XBAR2_IN78 input. */
    kXBAR2_InputDma4TriggerOut7     = 79|0x20000U, /**< DMA4_TRIGGER_OUT7 output assigned to XBAR2_IN79 input. */
    kXBAR2_InputDma3TriggerOut0     = 80|0x20000U, /**< DMA3_TRIGGER_OUT0 output assigned to XBAR2_IN80 input. */
    kXBAR2_InputDma3TriggerOut1     = 81|0x20000U, /**< DMA3_TRIGGER_OUT1 output assigned to XBAR2_IN81 input. */
    kXBAR2_InputDma3TriggerOut2     = 82|0x20000U, /**< DMA3_TRIGGER_OUT2 output assigned to XBAR2_IN82 input. */
    kXBAR2_InputDma3TriggerOut3     = 83|0x20000U, /**< DMA3_TRIGGER_OUT3 output assigned to XBAR2_IN83 input. */
    kXBAR2_InputDma3TriggerOut4     = 84|0x20000U, /**< DMA3_TRIGGER_OUT4 output assigned to XBAR2_IN84 input. */
    kXBAR2_InputDma3TriggerOut5     = 85|0x20000U, /**< DMA3_TRIGGER_OUT5 output assigned to XBAR2_IN85 input. */
    kXBAR2_InputDma3TriggerOut6     = 86|0x20000U, /**< DMA3_TRIGGER_OUT6 output assigned to XBAR2_IN86 input. */
    kXBAR2_InputDma3TriggerOut7     = 87|0x20000U, /**< DMA3_TRIGGER_OUT7 output assigned to XBAR2_IN87 input. */
    kXBAR2_InputAdc1TcompPulse0     = 88|0x20000U, /**< ADC1_TCOMP_PULSE0 output assigned to XBAR2_IN88 input. */
    kXBAR2_InputAdc1TcompPulse1     = 89|0x20000U, /**< ADC1_TCOMP_PULSE1 output assigned to XBAR2_IN89 input. */
    kXBAR2_InputAdc1TcompPulse2     = 90|0x20000U, /**< ADC1_TCOMP_PULSE2 output assigned to XBAR2_IN90 input. */
    kXBAR2_InputAdc1TcompPulse3     = 91|0x20000U, /**< ADC1_TCOMP_PULSE3 output assigned to XBAR2_IN91 input. */
    kXBAR2_InputAdc1TcompPulse4     = 92|0x20000U, /**< ADC1_TCOMP_PULSE4 output assigned to XBAR2_IN92 input. */
    kXBAR2_InputAdc1TcompPulse5     = 93|0x20000U, /**< ADC1_TCOMP_PULSE5 output assigned to XBAR2_IN93 input. */
    kXBAR2_InputAdc1TcompPulse6     = 94|0x20000U, /**< ADC1_TCOMP_PULSE6 output assigned to XBAR2_IN94 input. */
    kXBAR2_InputAdc1TcompPulse7     = 95|0x20000U, /**< ADC1_TCOMP_PULSE7 output assigned to XBAR2_IN95 input. */
    kXBAR2_InputAdc2TcompPulse0     = 96|0x20000U, /**< ADC2_TCOMP_PULSE0 output assigned to XBAR2_IN96 input. */
    kXBAR2_InputAdc2TcompPulse1     = 97|0x20000U, /**< ADC2_TCOMP_PULSE1 output assigned to XBAR2_IN97 input. */
    kXBAR2_InputAdc2TcompPulse2     = 98|0x20000U, /**< ADC2_TCOMP_PULSE2 output assigned to XBAR2_IN98 input. */
    kXBAR2_InputAdc2TcompPulse3     = 99|0x20000U, /**< ADC2_TCOMP_PULSE3 output assigned to XBAR2_IN99 input. */
    kXBAR2_InputAdc2TcompPulse4     = 100|0x20000U, /**< ADC2_TCOMP_PULSE4 output assigned to XBAR2_IN100 input. */
    kXBAR2_InputAdc2TcompPulse5     = 101|0x20000U, /**< ADC2_TCOMP_PULSE5 output assigned to XBAR2_IN101 input. */
    kXBAR2_InputAdc2TcompPulse6     = 102|0x20000U, /**< ADC2_TCOMP_PULSE6 output assigned to XBAR2_IN102 input. */
    kXBAR2_InputAdc2TcompPulse7     = 103|0x20000U, /**< ADC2_TCOMP_PULSE7 output assigned to XBAR2_IN103 input. */
    kXBAR2_InputTpm1ChTrigger0      = 104|0x20000U, /**< TPM1_CH_TRIGGER0 output assigned to XBAR2_IN104 input. */
    kXBAR2_InputTpm1ChTrigger1      = 105|0x20000U, /**< TPM1_CH_TRIGGER1 output assigned to XBAR2_IN105 input. */
    kXBAR2_InputTpm1ChTrigger2      = 106|0x20000U, /**< TPM1_CH_TRIGGER2 output assigned to XBAR2_IN106 input. */
    kXBAR2_InputTpm1ChTrigger3      = 107|0x20000U, /**< TPM1_CH_TRIGGER3 output assigned to XBAR2_IN107 input. */
    kXBAR2_InputTpm1Trigger         = 108|0x20000U, /**< TPM1_TRIGGER output assigned to XBAR2_IN108 input. */
    kXBAR2_InputTpm2ChTrigger0      = 109|0x20000U, /**< TPM2_CH_TRIGGER0 output assigned to XBAR2_IN109 input. */
    kXBAR2_InputTpm2ChTrigger1      = 110|0x20000U, /**< TPM2_CH_TRIGGER1 output assigned to XBAR2_IN110 input. */
    kXBAR2_InputTpm2ChTrigger2      = 111|0x20000U, /**< TPM2_CH_TRIGGER2 output assigned to XBAR2_IN111 input. */
    kXBAR2_InputTpm2ChTrigger3      = 112|0x20000U, /**< TPM2_CH_TRIGGER3 output assigned to XBAR2_IN112 input. */
    kXBAR2_InputTpm2Trigger         = 113|0x20000U, /**< TPM2_TRIGGER output assigned to XBAR2_IN113 input. */
    kXBAR2_InputTpm3ChTrigger0      = 114|0x20000U, /**< TPM3_CH_TRIGGER0 output assigned to XBAR2_IN114 input. */
    kXBAR2_InputTpm3ChTrigger1      = 115|0x20000U, /**< TPM3_CH_TRIGGER1 output assigned to XBAR2_IN115 input. */
    kXBAR2_InputTpm3ChTrigger2      = 116|0x20000U, /**< TPM3_CH_TRIGGER2 output assigned to XBAR2_IN116 input. */
    kXBAR2_InputTpm3ChTrigger3      = 117|0x20000U, /**< TPM3_CH_TRIGGER3 output assigned to XBAR2_IN117 input. */
    kXBAR2_InputTpm3Trigger         = 118|0x20000U, /**< TPM3_TRIGGER output assigned to XBAR2_IN118 input. */
    kXBAR2_InputTpm4ChTrigger0      = 119|0x20000U, /**< TPM4_CH_TRIGGER0 output assigned to XBAR2_IN119 input. */
    kXBAR2_InputTpm4ChTrigger1      = 120|0x20000U, /**< TPM4_CH_TRIGGER1 output assigned to XBAR2_IN120 input. */
    kXBAR2_InputTpm4ChTrigger2      = 121|0x20000U, /**< TPM4_CH_TRIGGER2 output assigned to XBAR2_IN121 input. */
    kXBAR2_InputTpm4ChTrigger3      = 122|0x20000U, /**< TPM4_CH_TRIGGER3 output assigned to XBAR2_IN122 input. */
    kXBAR2_InputTpm4Trigger         = 123|0x20000U, /**< TPM4_TRIGGER output assigned to XBAR2_IN123 input. */
    kXBAR2_InputTpm5ChTrigger0      = 124|0x20000U, /**< TPM5_CH_TRIGGER0 output assigned to XBAR2_IN124 input. */
    kXBAR2_InputTpm5ChTrigger1      = 125|0x20000U, /**< TPM5_CH_TRIGGER1 output assigned to XBAR2_IN125 input. */
    kXBAR2_InputTpm5ChTrigger2      = 126|0x20000U, /**< TPM5_CH_TRIGGER2 output assigned to XBAR2_IN126 input. */
    kXBAR2_InputTpm5ChTrigger3      = 127|0x20000U, /**< TPM5_CH_TRIGGER3 output assigned to XBAR2_IN127 input. */
    kXBAR2_InputTpm5Trigger         = 128|0x20000U, /**< TPM5_TRIGGER output assigned to XBAR2_IN128 input. */
    kXBAR2_InputTpm6ChTrigger0      = 129|0x20000U, /**< TPM6_CH_TRIGGER0 output assigned to XBAR2_IN129 input. */
    kXBAR2_InputTpm6ChTrigger1      = 130|0x20000U, /**< TPM6_CH_TRIGGER1 output assigned to XBAR2_IN130 input. */
    kXBAR2_InputTpm6ChTrigger2      = 131|0x20000U, /**< TPM6_CH_TRIGGER2 output assigned to XBAR2_IN131 input. */
    kXBAR2_InputTpm6ChTrigger3      = 132|0x20000U, /**< TPM6_CH_TRIGGER3 output assigned to XBAR2_IN132 input. */
    kXBAR2_InputTpm6Trigger         = 133|0x20000U, /**< TPM6_TRIGGER output assigned to XBAR2_IN133 input. */
    kXBAR2_InputLptmr1TriggerDelay  = 134|0x20000U, /**< LPTMR1_TRIGGER_DELAY output assigned to XBAR2_IN134 input. */
    kXBAR2_InputLptmr2TriggerDelay  = 135|0x20000U, /**< LPTMR2_TRIGGER_DELAY output assigned to XBAR2_IN135 input. */
    kXBAR2_InputLptmr3TriggerDelay  = 136|0x20000U, /**< LPTMR3_TRIGGER_DELAY output assigned to XBAR2_IN136 input. */
    kXBAR2_InputNetcTmrPp1          = 137|0x20000U, /**< NETC_TMR_PP1 output assigned to XBAR2_IN137 input. */
    kXBAR2_InputNetcTmrPp2          = 138|0x20000U, /**< NETC_TMR_PP2 output assigned to XBAR2_IN138 input. */
    kXBAR2_InputNetcTmrPp3          = 139|0x20000U, /**< NETC_TMR_PP3 output assigned to XBAR2_IN139 input. */
    kXBAR2_InputSinc1IppDoBreak0    = 140|0x20000U, /**< SINC1_IPP_DO_BREAK0 output assigned to XBAR2_IN140 input. */
    kXBAR2_InputSinc1IppDoBreak1    = 141|0x20000U, /**< SINC1_IPP_DO_BREAK1 output assigned to XBAR2_IN141 input. */
    kXBAR2_InputSinc1IppDoBreak2    = 142|0x20000U, /**< SINC1_IPP_DO_BREAK2 output assigned to XBAR2_IN142 input. */
    kXBAR2_InputSinc1IppDoBreak3    = 143|0x20000U, /**< SINC1_IPP_DO_BREAK3 output assigned to XBAR2_IN143 input. */
    kXBAR2_InputSinc2IppDoBreak0    = 144|0x20000U, /**< SINC2_IPP_DO_BREAK0 output assigned to XBAR2_IN144 input. */
    kXBAR2_InputSinc2IppDoBreak1    = 145|0x20000U, /**< SINC2_IPP_DO_BREAK1 output assigned to XBAR2_IN145 input. */
    kXBAR2_InputSinc2IppDoBreak2    = 146|0x20000U, /**< SINC2_IPP_DO_BREAK2 output assigned to XBAR2_IN146 input. */
    kXBAR2_InputSinc2IppDoBreak3    = 147|0x20000U, /**< SINC2_IPP_DO_BREAK3 output assigned to XBAR2_IN147 input. */
    kXBAR2_InputSinc3IppDoBreak0    = 148|0x20000U, /**< SINC3_IPP_DO_BREAK0 output assigned to XBAR2_IN148 input. */
    kXBAR2_InputSinc3IppDoBreak1    = 149|0x20000U, /**< SINC3_IPP_DO_BREAK1 output assigned to XBAR2_IN149 input. */
    kXBAR2_InputSinc3IppDoBreak2    = 150|0x20000U, /**< SINC3_IPP_DO_BREAK2 output assigned to XBAR2_IN150 input. */
    kXBAR2_InputSinc3IppDoBreak3    = 151|0x20000U, /**< SINC3_IPP_DO_BREAK3 output assigned to XBAR2_IN151 input. */
    kXBAR2_InputRESERVED152         = 152|0x20000U, /**< XBAR2_IN152 input is reserved. */
    kXBAR2_InputRESERVED153         = 153|0x20000U, /**< XBAR2_IN153 input is reserved. */
    kXBAR2_InputRESERVED154         = 154|0x20000U, /**< XBAR2_IN154 input is reserved. */
    kXBAR2_InputRESERVED155         = 155|0x20000U, /**< XBAR2_IN155 input is reserved. */
    kXBAR2_InputEqdc1PosMatch0      = 156|0x20000U, /**< EQDC1_POS_MATCH0 output assigned to XBAR2_IN156 input. */
    kXBAR2_InputEqdc1PosMatch1      = 157|0x20000U, /**< EQDC1_POS_MATCH1 output assigned to XBAR2_IN157 input. */
    kXBAR2_InputEqdc1PosMatch2      = 158|0x20000U, /**< EQDC1_POS_MATCH2 output assigned to XBAR2_IN158 input. */
    kXBAR2_InputEqdc1PosMatch3      = 159|0x20000U, /**< EQDC1_POS_MATCH3 output assigned to XBAR2_IN159 input. */
    kXBAR2_InputEqdc1CompFlg0       = 160|0x20000U, /**< EQDC1_COMP_FLG0 output assigned to XBAR2_IN160 input. */
    kXBAR2_InputEqdc1CompFlg1       = 161|0x20000U, /**< EQDC1_COMP_FLG1 output assigned to XBAR2_IN161 input. */
    kXBAR2_InputEqdc1CompFlg2       = 162|0x20000U, /**< EQDC1_COMP_FLG2 output assigned to XBAR2_IN162 input. */
    kXBAR2_InputEqdc1CompFlg3       = 163|0x20000U, /**< EQDC1_COMP_FLG3 output assigned to XBAR2_IN163 input. */
    kXBAR2_InputEqdc1CntDn          = 164|0x20000U, /**< EQDC1_CNT_DN output assigned to XBAR2_IN164 input. */
    kXBAR2_InputEqdc1CntUp          = 165|0x20000U, /**< EQDC1_CNT_UP output assigned to XBAR2_IN165 input. */
    kXBAR2_InputEqdc1CntDir         = 166|0x20000U, /**< EQDC1_CNT_DIR output assigned to XBAR2_IN166 input. */
    kXBAR2_InputEqdc3PosMatch0      = 167|0x20000U, /**< EQDC3_POS_MATCH0 output assigned to XBAR2_IN167 input. */
    kXBAR2_InputEqdc3PosMatch1      = 168|0x20000U, /**< EQDC3_POS_MATCH1 output assigned to XBAR2_IN168 input. */
    kXBAR2_InputEqdc3PosMatch2      = 169|0x20000U, /**< EQDC3_POS_MATCH2 output assigned to XBAR2_IN169 input. */
    kXBAR2_InputEqdc3PosMatch3      = 170|0x20000U, /**< EQDC3_POS_MATCH3 output assigned to XBAR2_IN170 input. */
    kXBAR2_InputEqdc3CompFlg0       = 171|0x20000U, /**< EQDC3_COMP_FLG0 output assigned to XBAR2_IN171 input. */
    kXBAR2_InputEqdc3CompFlg1       = 172|0x20000U, /**< EQDC3_COMP_FLG1 output assigned to XBAR2_IN172 input. */
    kXBAR2_InputEqdc3CompFlg2       = 173|0x20000U, /**< EQDC3_COMP_FLG2 output assigned to XBAR2_IN173 input. */
    kXBAR2_InputEqdc3CompFlg3       = 174|0x20000U, /**< EQDC3_COMP_FLG3 output assigned to XBAR2_IN174 input. */
    kXBAR2_InputEqdc3CntDn          = 175|0x20000U, /**< EQDC3_CNT_DN output assigned to XBAR2_IN175 input. */
    kXBAR2_InputEqdc3CntUp          = 176|0x20000U, /**< EQDC3_CNT_UP output assigned to XBAR2_IN176 input. */
    kXBAR2_InputEqdc3CntDir         = 177|0x20000U, /**< EQDC3_CNT_DIR output assigned to XBAR2_IN177 input. */
    kXBAR3_InputLogicLow            = 0|0x30000U,  /**< LOGIC_LOW output assigned to XBAR3_IN0 input. */
    kXBAR3_InputLogicHigh           = 1|0x30000U,  /**< LOGIC_HIGH output assigned to XBAR3_IN1 input. */
    kXBAR3_InputLogicLow1           = 2|0x30000U,  /**< LOGIC_LOW1 output assigned to XBAR3_IN2 input. */
    kXBAR3_InputLogicHigh1          = 3|0x30000U,  /**< LOGIC_HIGH1 output assigned to XBAR3_IN3 input. */
    kXBAR3_InputAcmp1Out            = 4|0x30000U,  /**< ACMP1_OUT output assigned to XBAR3_IN4 input. */
    kXBAR3_InputAcmp2Out            = 5|0x30000U,  /**< ACMP2_OUT output assigned to XBAR3_IN5 input. */
    kXBAR3_InputAcmp3Out            = 6|0x30000U,  /**< ACMP3_OUT output assigned to XBAR3_IN6 input. */
    kXBAR3_InputAcmp4Out            = 7|0x30000U,  /**< ACMP4_OUT output assigned to XBAR3_IN7 input. */
    kXBAR3_InputQtimer1Timer0       = 8|0x30000U,  /**< QTIMER1_TIMER0 output assigned to XBAR3_IN8 input. */
    kXBAR3_InputQtimer1Timer1       = 9|0x30000U,  /**< QTIMER1_TIMER1 output assigned to XBAR3_IN9 input. */
    kXBAR3_InputQtimer1Timer2       = 10|0x30000U, /**< QTIMER1_TIMER2 output assigned to XBAR3_IN10 input. */
    kXBAR3_InputQtimer1Timer3       = 11|0x30000U, /**< QTIMER1_TIMER3 output assigned to XBAR3_IN11 input. */
    kXBAR3_InputQtimer2Timer0       = 12|0x30000U, /**< QTIMER2_TIMER0 output assigned to XBAR3_IN12 input. */
    kXBAR3_InputQtimer2Timer1       = 13|0x30000U, /**< QTIMER2_TIMER1 output assigned to XBAR3_IN13 input. */
    kXBAR3_InputQtimer2Timer2       = 14|0x30000U, /**< QTIMER2_TIMER2 output assigned to XBAR3_IN14 input. */
    kXBAR3_InputQtimer2Timer3       = 15|0x30000U, /**< QTIMER2_TIMER3 output assigned to XBAR3_IN15 input. */
    kXBAR3_InputQtimer3Timer0       = 16|0x30000U, /**< QTIMER3_TIMER0 output assigned to XBAR3_IN16 input. */
    kXBAR3_InputQtimer3Timer1       = 17|0x30000U, /**< QTIMER3_TIMER1 output assigned to XBAR3_IN17 input. */
    kXBAR3_InputQtimer3Timer2       = 18|0x30000U, /**< QTIMER3_TIMER2 output assigned to XBAR3_IN18 input. */
    kXBAR3_InputQtimer3Timer3       = 19|0x30000U, /**< QTIMER3_TIMER3 output assigned to XBAR3_IN19 input. */
    kXBAR3_InputQtimer4Timer0       = 20|0x30000U, /**< QTIMER4_TIMER0 output assigned to XBAR3_IN20 input. */
    kXBAR3_InputQtimer4Timer1       = 21|0x30000U, /**< QTIMER4_TIMER1 output assigned to XBAR3_IN21 input. */
    kXBAR3_InputQtimer4Timer2       = 22|0x30000U, /**< QTIMER4_TIMER2 output assigned to XBAR3_IN22 input. */
    kXBAR3_InputQtimer4Timer3       = 23|0x30000U, /**< QTIMER4_TIMER3 output assigned to XBAR3_IN23 input. */
    kXBAR3_InputQtimer5Timer0       = 24|0x30000U, /**< QTIMER5_TIMER0 output assigned to XBAR3_IN24 input. */
    kXBAR3_InputQtimer5Timer1       = 25|0x30000U, /**< QTIMER5_TIMER1 output assigned to XBAR3_IN25 input. */
    kXBAR3_InputQtimer5Timer2       = 26|0x30000U, /**< QTIMER5_TIMER2 output assigned to XBAR3_IN26 input. */
    kXBAR3_InputQtimer5Timer3       = 27|0x30000U, /**< QTIMER5_TIMER3 output assigned to XBAR3_IN27 input. */
    kXBAR3_InputQtimer6Timer0       = 28|0x30000U, /**< QTIMER6_TIMER0 output assigned to XBAR3_IN28 input. */
    kXBAR3_InputQtimer6Timer1       = 29|0x30000U, /**< QTIMER6_TIMER1 output assigned to XBAR3_IN29 input. */
    kXBAR3_InputQtimer6Timer2       = 30|0x30000U, /**< QTIMER6_TIMER2 output assigned to XBAR3_IN30 input. */
    kXBAR3_InputQtimer6Timer3       = 31|0x30000U, /**< QTIMER6_TIMER3 output assigned to XBAR3_IN31 input. */
    kXBAR3_InputQtimer7Timer0       = 32|0x30000U, /**< QTIMER7_TIMER0 output assigned to XBAR3_IN32 input. */
    kXBAR3_InputQtimer7Timer1       = 33|0x30000U, /**< QTIMER7_TIMER1 output assigned to XBAR3_IN33 input. */
    kXBAR3_InputQtimer7Timer2       = 34|0x30000U, /**< QTIMER7_TIMER2 output assigned to XBAR3_IN34 input. */
    kXBAR3_InputQtimer7Timer3       = 35|0x30000U, /**< QTIMER7_TIMER3 output assigned to XBAR3_IN35 input. */
    kXBAR3_InputQtimer8Timer0       = 36|0x30000U, /**< QTIMER8_TIMER0 output assigned to XBAR3_IN36 input. */
    kXBAR3_InputQtimer8Timer1       = 37|0x30000U, /**< QTIMER8_TIMER1 output assigned to XBAR3_IN37 input. */
    kXBAR3_InputQtimer8Timer2       = 38|0x30000U, /**< QTIMER8_TIMER2 output assigned to XBAR3_IN38 input. */
    kXBAR3_InputQtimer8Timer3       = 39|0x30000U, /**< QTIMER8_TIMER3 output assigned to XBAR3_IN39 input. */
    kXBAR3_InputFlexpwm1Pwm0OutTrig01 = 40|0x30000U, /**< FLEXPWM1_PWM0_OUT_TRIG0_1 output assigned to XBAR3_IN40 input. */
    kXBAR3_InputFlexpwm1Pwm1OutTrig01 = 41|0x30000U, /**< FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBAR3_IN41 input. */
    kXBAR3_InputFlexpwm1Pwm2OutTrig01 = 42|0x30000U, /**< FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBAR3_IN42 input. */
    kXBAR3_InputFlexpwm1Pwm3OutTrig01 = 43|0x30000U, /**< FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBAR3_IN43 input. */
    kXBAR3_InputFlexpwm2Pwm0OutTrig01 = 44|0x30000U, /**< FLEXPWM2_PWM0_OUT_TRIG0_1 output assigned to XBAR3_IN44 input. */
    kXBAR3_InputFlexpwm2Pwm1OutTrig01 = 45|0x30000U, /**< FLEXPWM2_PWM1_OUT_TRIG0_1 output assigned to XBAR3_IN45 input. */
    kXBAR3_InputFlexpwm2Pwm2OutTrig01 = 46|0x30000U, /**< FLEXPWM2_PWM2_OUT_TRIG0_1 output assigned to XBAR3_IN46 input. */
    kXBAR3_InputFlexpwm2Pwm3OutTrig01 = 47|0x30000U, /**< FLEXPWM2_PWM3_OUT_TRIG0_1 output assigned to XBAR3_IN47 input. */
    kXBAR3_InputFlexpwm3Pwm0OutTrig01 = 48|0x30000U, /**< FLEXPWM3_PWM0_OUT_TRIG0_1 output assigned to XBAR3_IN48 input. */
    kXBAR3_InputFlexpwm3Pwm1OutTrig01 = 49|0x30000U, /**< FLEXPWM3_PWM1_OUT_TRIG0_1 output assigned to XBAR3_IN49 input. */
    kXBAR3_InputFlexpwm3Pwm2OutTrig01 = 50|0x30000U, /**< FLEXPWM3_PWM2_OUT_TRIG0_1 output assigned to XBAR3_IN50 input. */
    kXBAR3_InputFlexpwm3Pwm3OutTrig01 = 51|0x30000U, /**< FLEXPWM3_PWM3_OUT_TRIG0_1 output assigned to XBAR3_IN51 input. */
    kXBAR3_InputFlexpwm4Pwm0OutTrig01 = 52|0x30000U, /**< FLEXPWM4_PWM0_OUT_TRIG0_1 output assigned to XBAR3_IN52 input. */
    kXBAR3_InputFlexpwm4Pwm1OutTrig01 = 53|0x30000U, /**< FLEXPWM4_PWM1_OUT_TRIG0_1 output assigned to XBAR3_IN53 input. */
    kXBAR3_InputFlexpwm4Pwm2OutTrig01 = 54|0x30000U, /**< FLEXPWM4_PWM2_OUT_TRIG0_1 output assigned to XBAR3_IN54 input. */
    kXBAR3_InputFlexpwm4Pwm3OutTrig01 = 55|0x30000U, /**< FLEXPWM4_PWM3_OUT_TRIG0_1 output assigned to XBAR3_IN55 input. */
    kXBAR3_InputPit1Trigger0        = 56|0x30000U, /**< PIT1_TRIGGER0 output assigned to XBAR3_IN56 input. */
    kXBAR3_InputPit1Trigger1        = 57|0x30000U, /**< PIT1_TRIGGER1 output assigned to XBAR3_IN57 input. */
    kXBAR3_InputPit1Trigger2        = 58|0x30000U, /**< PIT1_TRIGGER2 output assigned to XBAR3_IN58 input. */
    kXBAR3_InputPit1Trigger3        = 59|0x30000U, /**< PIT1_TRIGGER3 output assigned to XBAR3_IN59 input. */
    kXBAR3_InputPit2Trigger0        = 60|0x30000U, /**< PIT2_TRIGGER0 output assigned to XBAR3_IN60 input. */
    kXBAR3_InputPit2Trigger1        = 61|0x30000U, /**< PIT2_TRIGGER1 output assigned to XBAR3_IN61 input. */
    kXBAR3_InputPit2Trigger2        = 62|0x30000U, /**< PIT2_TRIGGER2 output assigned to XBAR3_IN62 input. */
    kXBAR3_InputPit2Trigger3        = 63|0x30000U, /**< PIT2_TRIGGER3 output assigned to XBAR3_IN63 input. */
    kXBAR3_InputPit3Trigger0        = 64|0x30000U, /**< PIT3_TRIGGER0 output assigned to XBAR3_IN64 input. */
    kXBAR3_InputPit3Trigger1        = 65|0x30000U, /**< PIT3_TRIGGER1 output assigned to XBAR3_IN65 input. */
    kXBAR3_InputPit3Trigger2        = 66|0x30000U, /**< PIT3_TRIGGER2 output assigned to XBAR3_IN66 input. */
    kXBAR3_InputPit3Trigger3        = 67|0x30000U, /**< PIT3_TRIGGER3 output assigned to XBAR3_IN67 input. */
    kXBAR3_InputSinc2PulseTrigger0  = 68|0x30000U, /**< SINC2_PULSE_TRIGGER0 output assigned to XBAR3_IN68 input. */
    kXBAR3_InputSinc2PulseTrigger1  = 69|0x30000U, /**< SINC2_PULSE_TRIGGER1 output assigned to XBAR3_IN69 input. */
    kXBAR3_InputSinc2PulseTrigger2  = 70|0x30000U, /**< SINC2_PULSE_TRIGGER2 output assigned to XBAR3_IN70 input. */
    kXBAR3_InputSinc2PulseTrigger3  = 71|0x30000U, /**< SINC2_PULSE_TRIGGER3 output assigned to XBAR3_IN71 input. */
    kXBAR3_InputDma4TriggerOut0     = 72|0x30000U, /**< DMA4_TRIGGER_OUT0 output assigned to XBAR3_IN72 input. */
    kXBAR3_InputDma4TriggerOut1     = 73|0x30000U, /**< DMA4_TRIGGER_OUT1 output assigned to XBAR3_IN73 input. */
    kXBAR3_InputDma4TriggerOut2     = 74|0x30000U, /**< DMA4_TRIGGER_OUT2 output assigned to XBAR3_IN74 input. */
    kXBAR3_InputDma4TriggerOut3     = 75|0x30000U, /**< DMA4_TRIGGER_OUT3 output assigned to XBAR3_IN75 input. */
    kXBAR3_InputDma4TriggerOut4     = 76|0x30000U, /**< DMA4_TRIGGER_OUT4 output assigned to XBAR3_IN76 input. */
    kXBAR3_InputDma4TriggerOut5     = 77|0x30000U, /**< DMA4_TRIGGER_OUT5 output assigned to XBAR3_IN77 input. */
    kXBAR3_InputDma4TriggerOut6     = 78|0x30000U, /**< DMA4_TRIGGER_OUT6 output assigned to XBAR3_IN78 input. */
    kXBAR3_InputDma4TriggerOut7     = 79|0x30000U, /**< DMA4_TRIGGER_OUT7 output assigned to XBAR3_IN79 input. */
    kXBAR3_InputDma3TriggerOut0     = 80|0x30000U, /**< DMA3_TRIGGER_OUT0 output assigned to XBAR3_IN80 input. */
    kXBAR3_InputDma3TriggerOut1     = 81|0x30000U, /**< DMA3_TRIGGER_OUT1 output assigned to XBAR3_IN81 input. */
    kXBAR3_InputDma3TriggerOut2     = 82|0x30000U, /**< DMA3_TRIGGER_OUT2 output assigned to XBAR3_IN82 input. */
    kXBAR3_InputDma3TriggerOut3     = 83|0x30000U, /**< DMA3_TRIGGER_OUT3 output assigned to XBAR3_IN83 input. */
    kXBAR3_InputDma3TriggerOut4     = 84|0x30000U, /**< DMA3_TRIGGER_OUT4 output assigned to XBAR3_IN84 input. */
    kXBAR3_InputDma3TriggerOut5     = 85|0x30000U, /**< DMA3_TRIGGER_OUT5 output assigned to XBAR3_IN85 input. */
    kXBAR3_InputDma3TriggerOut6     = 86|0x30000U, /**< DMA3_TRIGGER_OUT6 output assigned to XBAR3_IN86 input. */
    kXBAR3_InputDma3TriggerOut7     = 87|0x30000U, /**< DMA3_TRIGGER_OUT7 output assigned to XBAR3_IN87 input. */
    kXBAR3_InputAdc1TcompPulse0     = 88|0x30000U, /**< ADC1_TCOMP_PULSE0 output assigned to XBAR3_IN88 input. */
    kXBAR3_InputAdc1TcompPulse1     = 89|0x30000U, /**< ADC1_TCOMP_PULSE1 output assigned to XBAR3_IN89 input. */
    kXBAR3_InputAdc1TcompPulse2     = 90|0x30000U, /**< ADC1_TCOMP_PULSE2 output assigned to XBAR3_IN90 input. */
    kXBAR3_InputAdc1TcompPulse3     = 91|0x30000U, /**< ADC1_TCOMP_PULSE3 output assigned to XBAR3_IN91 input. */
    kXBAR3_InputAdc1TcompPulse4     = 92|0x30000U, /**< ADC1_TCOMP_PULSE4 output assigned to XBAR3_IN92 input. */
    kXBAR3_InputAdc1TcompPulse5     = 93|0x30000U, /**< ADC1_TCOMP_PULSE5 output assigned to XBAR3_IN93 input. */
    kXBAR3_InputAdc1TcompPulse6     = 94|0x30000U, /**< ADC1_TCOMP_PULSE6 output assigned to XBAR3_IN94 input. */
    kXBAR3_InputAdc1TcompPulse7     = 95|0x30000U, /**< ADC1_TCOMP_PULSE7 output assigned to XBAR3_IN95 input. */
    kXBAR3_InputAdc2TcompPulse0     = 96|0x30000U, /**< ADC2_TCOMP_PULSE0 output assigned to XBAR3_IN96 input. */
    kXBAR3_InputAdc2TcompPulse1     = 97|0x30000U, /**< ADC2_TCOMP_PULSE1 output assigned to XBAR3_IN97 input. */
    kXBAR3_InputAdc2TcompPulse2     = 98|0x30000U, /**< ADC2_TCOMP_PULSE2 output assigned to XBAR3_IN98 input. */
    kXBAR3_InputAdc2TcompPulse3     = 99|0x30000U, /**< ADC2_TCOMP_PULSE3 output assigned to XBAR3_IN99 input. */
    kXBAR3_InputAdc2TcompPulse4     = 100|0x30000U, /**< ADC2_TCOMP_PULSE4 output assigned to XBAR3_IN100 input. */
    kXBAR3_InputAdc2TcompPulse5     = 101|0x30000U, /**< ADC2_TCOMP_PULSE5 output assigned to XBAR3_IN101 input. */
    kXBAR3_InputAdc2TcompPulse6     = 102|0x30000U, /**< ADC2_TCOMP_PULSE6 output assigned to XBAR3_IN102 input. */
    kXBAR3_InputAdc2TcompPulse7     = 103|0x30000U, /**< ADC2_TCOMP_PULSE7 output assigned to XBAR3_IN103 input. */
    kXBAR3_InputTpm1ChTrigger0      = 104|0x30000U, /**< TPM1_CH_TRIGGER0 output assigned to XBAR3_IN104 input. */
    kXBAR3_InputTpm1ChTrigger1      = 105|0x30000U, /**< TPM1_CH_TRIGGER1 output assigned to XBAR3_IN105 input. */
    kXBAR3_InputTpm1ChTrigger2      = 106|0x30000U, /**< TPM1_CH_TRIGGER2 output assigned to XBAR3_IN106 input. */
    kXBAR3_InputTpm1ChTrigger3      = 107|0x30000U, /**< TPM1_CH_TRIGGER3 output assigned to XBAR3_IN107 input. */
    kXBAR3_InputTpm1Trigger         = 108|0x30000U, /**< TPM1_TRIGGER output assigned to XBAR3_IN108 input. */
    kXBAR3_InputTpm2ChTrigger0      = 109|0x30000U, /**< TPM2_CH_TRIGGER0 output assigned to XBAR3_IN109 input. */
    kXBAR3_InputTpm2ChTrigger1      = 110|0x30000U, /**< TPM2_CH_TRIGGER1 output assigned to XBAR3_IN110 input. */
    kXBAR3_InputTpm2ChTrigger2      = 111|0x30000U, /**< TPM2_CH_TRIGGER2 output assigned to XBAR3_IN111 input. */
    kXBAR3_InputTpm2ChTrigger3      = 112|0x30000U, /**< TPM2_CH_TRIGGER3 output assigned to XBAR3_IN112 input. */
    kXBAR3_InputTpm2Trigger         = 113|0x30000U, /**< TPM2_TRIGGER output assigned to XBAR3_IN113 input. */
    kXBAR3_InputTpm3ChTrigger0      = 114|0x30000U, /**< TPM3_CH_TRIGGER0 output assigned to XBAR3_IN114 input. */
    kXBAR3_InputTpm3ChTrigger1      = 115|0x30000U, /**< TPM3_CH_TRIGGER1 output assigned to XBAR3_IN115 input. */
    kXBAR3_InputTpm3ChTrigger2      = 116|0x30000U, /**< TPM3_CH_TRIGGER2 output assigned to XBAR3_IN116 input. */
    kXBAR3_InputTpm3ChTrigger3      = 117|0x30000U, /**< TPM3_CH_TRIGGER3 output assigned to XBAR3_IN117 input. */
    kXBAR3_InputTpm3Trigger         = 118|0x30000U, /**< TPM3_TRIGGER output assigned to XBAR3_IN118 input. */
    kXBAR3_InputTpm4ChTrigger0      = 119|0x30000U, /**< TPM4_CH_TRIGGER0 output assigned to XBAR3_IN119 input. */
    kXBAR3_InputTpm4ChTrigger1      = 120|0x30000U, /**< TPM4_CH_TRIGGER1 output assigned to XBAR3_IN120 input. */
    kXBAR3_InputTpm4ChTrigger2      = 121|0x30000U, /**< TPM4_CH_TRIGGER2 output assigned to XBAR3_IN121 input. */
    kXBAR3_InputTpm4ChTrigger3      = 122|0x30000U, /**< TPM4_CH_TRIGGER3 output assigned to XBAR3_IN122 input. */
    kXBAR3_InputTpm4Trigger         = 123|0x30000U, /**< TPM4_TRIGGER output assigned to XBAR3_IN123 input. */
    kXBAR3_InputTpm5ChTrigger0      = 124|0x30000U, /**< TPM5_CH_TRIGGER0 output assigned to XBAR3_IN124 input. */
    kXBAR3_InputTpm5ChTrigger1      = 125|0x30000U, /**< TPM5_CH_TRIGGER1 output assigned to XBAR3_IN125 input. */
    kXBAR3_InputTpm5ChTrigger2      = 126|0x30000U, /**< TPM5_CH_TRIGGER2 output assigned to XBAR3_IN126 input. */
    kXBAR3_InputTpm5ChTrigger3      = 127|0x30000U, /**< TPM5_CH_TRIGGER3 output assigned to XBAR3_IN127 input. */
    kXBAR3_InputTpm5Trigger         = 128|0x30000U, /**< TPM5_TRIGGER output assigned to XBAR3_IN128 input. */
    kXBAR3_InputTpm6ChTrigger0      = 129|0x30000U, /**< TPM6_CH_TRIGGER0 output assigned to XBAR3_IN129 input. */
    kXBAR3_InputTpm6ChTrigger1      = 130|0x30000U, /**< TPM6_CH_TRIGGER1 output assigned to XBAR3_IN130 input. */
    kXBAR3_InputTpm6ChTrigger2      = 131|0x30000U, /**< TPM6_CH_TRIGGER2 output assigned to XBAR3_IN131 input. */
    kXBAR3_InputTpm6ChTrigger3      = 132|0x30000U, /**< TPM6_CH_TRIGGER3 output assigned to XBAR3_IN132 input. */
    kXBAR3_InputTpm6Trigger         = 133|0x30000U, /**< TPM6_TRIGGER output assigned to XBAR3_IN133 input. */
    kXBAR3_InputLptmr1TriggerDelay  = 134|0x30000U, /**< LPTMR1_TRIGGER_DELAY output assigned to XBAR3_IN134 input. */
    kXBAR3_InputLptmr2TriggerDelay  = 135|0x30000U, /**< LPTMR2_TRIGGER_DELAY output assigned to XBAR3_IN135 input. */
    kXBAR3_InputLptmr3TriggerDelay  = 136|0x30000U, /**< LPTMR3_TRIGGER_DELAY output assigned to XBAR3_IN136 input. */
    kXBAR3_InputNetcTmrPp1          = 137|0x30000U, /**< NETC_TMR_PP1 output assigned to XBAR3_IN137 input. */
    kXBAR3_InputNetcTmrPp2          = 138|0x30000U, /**< NETC_TMR_PP2 output assigned to XBAR3_IN138 input. */
    kXBAR3_InputNetcTmrPp3          = 139|0x30000U, /**< NETC_TMR_PP3 output assigned to XBAR3_IN139 input. */
    kXBAR3_InputSinc1IppDoBreak0    = 140|0x30000U, /**< SINC1_IPP_DO_BREAK0 output assigned to XBAR3_IN140 input. */
    kXBAR3_InputSinc1IppDoBreak1    = 141|0x30000U, /**< SINC1_IPP_DO_BREAK1 output assigned to XBAR3_IN141 input. */
    kXBAR3_InputSinc1IppDoBreak2    = 142|0x30000U, /**< SINC1_IPP_DO_BREAK2 output assigned to XBAR3_IN142 input. */
    kXBAR3_InputSinc1IppDoBreak3    = 143|0x30000U, /**< SINC1_IPP_DO_BREAK3 output assigned to XBAR3_IN143 input. */
    kXBAR3_InputSinc2IppDoBreak0    = 144|0x30000U, /**< SINC2_IPP_DO_BREAK0 output assigned to XBAR3_IN144 input. */
    kXBAR3_InputSinc2IppDoBreak1    = 145|0x30000U, /**< SINC2_IPP_DO_BREAK1 output assigned to XBAR3_IN145 input. */
    kXBAR3_InputSinc2IppDoBreak2    = 146|0x30000U, /**< SINC2_IPP_DO_BREAK2 output assigned to XBAR3_IN146 input. */
    kXBAR3_InputSinc2IppDoBreak3    = 147|0x30000U, /**< SINC2_IPP_DO_BREAK3 output assigned to XBAR3_IN147 input. */
    kXBAR3_InputSinc3IppDoBreak0    = 148|0x30000U, /**< SINC3_IPP_DO_BREAK0 output assigned to XBAR3_IN148 input. */
    kXBAR3_InputSinc3IppDoBreak1    = 149|0x30000U, /**< SINC3_IPP_DO_BREAK1 output assigned to XBAR3_IN149 input. */
    kXBAR3_InputSinc3IppDoBreak2    = 150|0x30000U, /**< SINC3_IPP_DO_BREAK2 output assigned to XBAR3_IN150 input. */
    kXBAR3_InputSinc3IppDoBreak3    = 151|0x30000U, /**< SINC3_IPP_DO_BREAK3 output assigned to XBAR3_IN151 input. */
    kXBAR3_InputRESERVED152         = 152|0x30000U, /**< XBAR3_IN152 input is reserved. */
    kXBAR3_InputRESERVED153         = 153|0x30000U, /**< XBAR3_IN153 input is reserved. */
    kXBAR3_InputRESERVED154         = 154|0x30000U, /**< XBAR3_IN154 input is reserved. */
    kXBAR3_InputRESERVED155         = 155|0x30000U, /**< XBAR3_IN155 input is reserved. */
    kXBAR3_InputEqdc2PosMatch0      = 156|0x30000U, /**< EQDC2_POS_MATCH0 output assigned to XBAR3_IN156 input. */
    kXBAR3_InputEqdc2PosMatch1      = 157|0x30000U, /**< EQDC2_POS_MATCH1 output assigned to XBAR3_IN157 input. */
    kXBAR3_InputEqdc2PosMatch2      = 158|0x30000U, /**< EQDC2_POS_MATCH2 output assigned to XBAR3_IN158 input. */
    kXBAR3_InputEqdc2PosMatch3      = 159|0x30000U, /**< EQDC2_POS_MATCH3 output assigned to XBAR3_IN159 input. */
    kXBAR3_InputEqdc2CompFlg0       = 160|0x30000U, /**< EQDC2_COMP_FLG0 output assigned to XBAR3_IN160 input. */
    kXBAR3_InputEqdc2CompFlg1       = 161|0x30000U, /**< EQDC2_COMP_FLG1 output assigned to XBAR3_IN161 input. */
    kXBAR3_InputEqdc2CompFlg2       = 162|0x30000U, /**< EQDC2_COMP_FLG2 output assigned to XBAR3_IN162 input. */
    kXBAR3_InputEqdc2CompFlg3       = 163|0x30000U, /**< EQDC2_COMP_FLG3 output assigned to XBAR3_IN163 input. */
    kXBAR3_InputEqdc2CntDn          = 164|0x30000U, /**< EQDC2_CNT_DN output assigned to XBAR3_IN164 input. */
    kXBAR3_InputEqdc2CntUp          = 165|0x30000U, /**< EQDC2_CNT_UP output assigned to XBAR3_IN165 input. */
    kXBAR3_InputEqdc2CntDir         = 166|0x30000U, /**< EQDC2_CNT_DIR output assigned to XBAR3_IN166 input. */
    kXBAR3_InputEqdc4PosMatch0      = 167|0x30000U, /**< EQDC4_POS_MATCH0 output assigned to XBAR3_IN167 input. */
    kXBAR3_InputEqdc4PosMatch1      = 168|0x30000U, /**< EQDC4_POS_MATCH1 output assigned to XBAR3_IN168 input. */
    kXBAR3_InputEqdc4PosMatch2      = 169|0x30000U, /**< EQDC4_POS_MATCH2 output assigned to XBAR3_IN169 input. */
    kXBAR3_InputEqdc4PosMatch3      = 170|0x30000U, /**< EQDC4_POS_MATCH3 output assigned to XBAR3_IN170 input. */
    kXBAR3_InputEqdc4CompFlg0       = 171|0x30000U, /**< EQDC4_COMP_FLG0 output assigned to XBAR3_IN171 input. */
    kXBAR3_InputEqdc4CompFlg1       = 172|0x30000U, /**< EQDC4_COMP_FLG1 output assigned to XBAR3_IN172 input. */
    kXBAR3_InputEqdc4CompFlg2       = 173|0x30000U, /**< EQDC4_COMP_FLG2 output assigned to XBAR3_IN173 input. */
    kXBAR3_InputEqdc4CompFlg3       = 174|0x30000U, /**< EQDC4_COMP_FLG3 output assigned to XBAR3_IN174 input. */
    kXBAR3_InputEqdc4CntDn          = 175|0x30000U, /**< EQDC4_CNT_DN output assigned to XBAR3_IN175 input. */
    kXBAR3_InputEqdc4CntUp          = 176|0x30000U, /**< EQDC4_CNT_UP output assigned to XBAR3_IN176 input. */
    kXBAR3_InputEqdc4CntDir         = 177|0x30000U, /**< EQDC4_CNT_DIR output assigned to XBAR3_IN177 input. */
} xbar_input_signal_t;
#endif /* XBAR_INPUT_SIGNAL_T_ */

#if !defined(XBAR_OUTPUT_SIGNAL_T_)
#define XBAR_OUTPUT_SIGNAL_T_
typedef enum _xbar_output_signal
{
    kXBAR1_OutputDma4MuxReq154      = 0|0x10000U,  /**< XBAR1_OUT0 output assigned to DMA4_MUX_REQ154 */
    kXBAR1_OutputDma4MuxReq155      = 1|0x10000U,  /**< XBAR1_OUT1 output assigned to DMA4_MUX_REQ155 */
    kXBAR1_OutputDma4MuxReq156      = 2|0x10000U,  /**< XBAR1_OUT2 output assigned to DMA4_MUX_REQ156 */
    kXBAR1_OutputDma4MuxReq157      = 3|0x10000U,  /**< XBAR1_OUT3 output assigned to DMA4_MUX_REQ157 */
    kXBAR1_OutputIomuxXbarInout04   = 4|0x10000U,  /**< XBAR1_OUT4 output assigned to IOMUX_XBAR_INOUT04 */
    kXBAR1_OutputIomuxXbarInout05   = 5|0x10000U,  /**< XBAR1_OUT5 output assigned to IOMUX_XBAR_INOUT05 */
    kXBAR1_OutputIomuxXbarInout06   = 6|0x10000U,  /**< XBAR1_OUT6 output assigned to IOMUX_XBAR_INOUT06 */
    kXBAR1_OutputIomuxXbarInout07   = 7|0x10000U,  /**< XBAR1_OUT7 output assigned to IOMUX_XBAR_INOUT07 */
    kXBAR1_OutputIomuxXbarInout08   = 8|0x10000U,  /**< XBAR1_OUT8 output assigned to IOMUX_XBAR_INOUT08 */
    kXBAR1_OutputIomuxXbarInout09   = 9|0x10000U,  /**< XBAR1_OUT9 output assigned to IOMUX_XBAR_INOUT09 */
    kXBAR1_OutputIomuxXbarInout10   = 10|0x10000U, /**< XBAR1_OUT10 output assigned to IOMUX_XBAR_INOUT10 */
    kXBAR1_OutputIomuxXbarInout11   = 11|0x10000U, /**< XBAR1_OUT11 output assigned to IOMUX_XBAR_INOUT11 */
    kXBAR1_OutputIomuxXbarInout12   = 12|0x10000U, /**< XBAR1_OUT12 output assigned to IOMUX_XBAR_INOUT12 */
    kXBAR1_OutputIomuxXbarInout13   = 13|0x10000U, /**< XBAR1_OUT13 output assigned to IOMUX_XBAR_INOUT13 */
    kXBAR1_OutputIomuxXbarInout14   = 14|0x10000U, /**< XBAR1_OUT14 output assigned to IOMUX_XBAR_INOUT14 */
    kXBAR1_OutputIomuxXbarInout15   = 15|0x10000U, /**< XBAR1_OUT15 output assigned to IOMUX_XBAR_INOUT15 */
    kXBAR1_OutputIomuxXbarInout16   = 16|0x10000U, /**< XBAR1_OUT16 output assigned to IOMUX_XBAR_INOUT16 */
    kXBAR1_OutputIomuxXbarInout17   = 17|0x10000U, /**< XBAR1_OUT17 output assigned to IOMUX_XBAR_INOUT17 */
    kXBAR1_OutputIomuxXbarInout18   = 18|0x10000U, /**< XBAR1_OUT18 output assigned to IOMUX_XBAR_INOUT18 */
    kXBAR1_OutputIomuxXbarInout19   = 19|0x10000U, /**< XBAR1_OUT19 output assigned to IOMUX_XBAR_INOUT19 */
    kXBAR1_OutputIomuxXbarInout20   = 20|0x10000U, /**< XBAR1_OUT20 output assigned to IOMUX_XBAR_INOUT20 */
    kXBAR1_OutputIomuxXbarInout21   = 21|0x10000U, /**< XBAR1_OUT21 output assigned to IOMUX_XBAR_INOUT21 */
    kXBAR1_OutputIomuxXbarInout22   = 22|0x10000U, /**< XBAR1_OUT22 output assigned to IOMUX_XBAR_INOUT22 */
    kXBAR1_OutputIomuxXbarInout23   = 23|0x10000U, /**< XBAR1_OUT23 output assigned to IOMUX_XBAR_INOUT23 */
    kXBAR1_OutputIomuxXbarInout24   = 24|0x10000U, /**< XBAR1_OUT24 output assigned to IOMUX_XBAR_INOUT24 */
    kXBAR1_OutputIomuxXbarInout25   = 25|0x10000U, /**< XBAR1_OUT25 output assigned to IOMUX_XBAR_INOUT25 */
    kXBAR1_OutputIomuxXbarInout26   = 26|0x10000U, /**< XBAR1_OUT26 output assigned to IOMUX_XBAR_INOUT26 */
    kXBAR1_OutputIomuxXbarInout27   = 27|0x10000U, /**< XBAR1_OUT27 output assigned to IOMUX_XBAR_INOUT27 */
    kXBAR1_OutputIomuxXbarInout28   = 28|0x10000U, /**< XBAR1_OUT28 output assigned to IOMUX_XBAR_INOUT28 */
    kXBAR1_OutputIomuxXbarInout29   = 29|0x10000U, /**< XBAR1_OUT29 output assigned to IOMUX_XBAR_INOUT29 */
    kXBAR1_OutputTriggerSyncIn0     = 30|0x10000U, /**< XBAR1_OUT30 output assigned to TRIGGER_SYNC_IN0 */
    kXBAR1_OutputTriggerSyncIn1     = 31|0x10000U, /**< XBAR1_OUT31 output assigned to TRIGGER_SYNC_IN1 */
    kXBAR1_OutputTriggerSyncIn2     = 32|0x10000U, /**< XBAR1_OUT32 output assigned to TRIGGER_SYNC_IN2 */
    kXBAR1_OutputTriggerSyncIn3     = 33|0x10000U, /**< XBAR1_OUT33 output assigned to TRIGGER_SYNC_IN3 */
    kXBAR1_OutputTriggerSyncIn4     = 34|0x10000U, /**< XBAR1_OUT34 output assigned to TRIGGER_SYNC_IN4 */
    kXBAR1_OutputTriggerSyncIn5     = 35|0x10000U, /**< XBAR1_OUT35 output assigned to TRIGGER_SYNC_IN5 */
    kXBAR1_OutputTriggerSyncIn6     = 36|0x10000U, /**< XBAR1_OUT36 output assigned to TRIGGER_SYNC_IN6 */
    kXBAR1_OutputTriggerSyncIn7     = 37|0x10000U, /**< XBAR1_OUT37 output assigned to TRIGGER_SYNC_IN7 */
    kXBAR1_OutputAcmp1Sample        = 38|0x10000U, /**< XBAR1_OUT38 output assigned to ACMP1_SAMPLE */
    kXBAR1_OutputAcmp2Sample        = 39|0x10000U, /**< XBAR1_OUT39 output assigned to ACMP2_SAMPLE */
    kXBAR1_OutputAcmp3Sample        = 40|0x10000U, /**< XBAR1_OUT40 output assigned to ACMP3_SAMPLE */
    kXBAR1_OutputAcmp4Sample        = 41|0x10000U, /**< XBAR1_OUT41 output assigned to ACMP4_SAMPLE */
    kXBAR1_OutputFlexpwm1Exta0      = 42|0x10000U, /**< XBAR1_OUT42 output assigned to FLEXPWM1_EXTA0 */
    kXBAR1_OutputFlexpwm1Exta1      = 43|0x10000U, /**< XBAR1_OUT43 output assigned to FLEXPWM1_EXTA1 */
    kXBAR1_OutputFlexpwm1Exta2      = 44|0x10000U, /**< XBAR1_OUT44 output assigned to FLEXPWM1_EXTA2 */
    kXBAR1_OutputFlexpwm1Exta3      = 45|0x10000U, /**< XBAR1_OUT45 output assigned to FLEXPWM1_EXTA3 */
    kXBAR1_OutputFlexpwm1ExtSync0   = 46|0x10000U, /**< XBAR1_OUT46 output assigned to FLEXPWM1_EXT_SYNC0 */
    kXBAR1_OutputFlexpwm1ExtSync1   = 47|0x10000U, /**< XBAR1_OUT47 output assigned to FLEXPWM1_EXT_SYNC1 */
    kXBAR1_OutputFlexpwm1ExtSync2   = 48|0x10000U, /**< XBAR1_OUT48 output assigned to FLEXPWM1_EXT_SYNC2 */
    kXBAR1_OutputFlexpwm1ExtSync3   = 49|0x10000U, /**< XBAR1_OUT49 output assigned to FLEXPWM1_EXT_SYNC3 */
    kXBAR1_OutputFlexpwm1ExtClk     = 50|0x10000U, /**< XBAR1_OUT50 output assigned to FLEXPWM1_EXT_CLK */
    kXBAR1_OutputFlexpwm1Fault0     = 51|0x10000U, /**< XBAR1_OUT51 output assigned to FLEXPWM1_FAULT0 */
    kXBAR1_OutputFlexpwm1Fault1     = 52|0x10000U, /**< XBAR1_OUT52 output assigned to FLEXPWM1_FAULT1 */
    kXBAR1_OutputFlexpwm1234Fault2  = 53|0x10000U, /**< XBAR1_OUT53 output assigned to FLEXPWM1_2_3_4_FAULT2 */
    kXBAR1_OutputFlexpwm1234Fault3  = 54|0x10000U, /**< XBAR1_OUT54 output assigned to FLEXPWM1_2_3_4_FAULT3 */
    kXBAR1_OutputFlexpwm1ExtForce   = 55|0x10000U, /**< XBAR1_OUT55 output assigned to FLEXPWM1_EXT_FORCE */
    kXBAR1_OutputFlexpwm2Exta0      = 56|0x10000U, /**< XBAR1_OUT56 output assigned to FLEXPWM2_EXTA0 */
    kXBAR1_OutputFlexpwm2Exta1      = 57|0x10000U, /**< XBAR1_OUT57 output assigned to FLEXPWM2_EXTA1 */
    kXBAR1_OutputFlexpwm2Exta2      = 58|0x10000U, /**< XBAR1_OUT58 output assigned to FLEXPWM2_EXTA2 */
    kXBAR1_OutputFlexpwm2Exta3      = 59|0x10000U, /**< XBAR1_OUT59 output assigned to FLEXPWM2_EXTA3 */
    kXBAR1_OutputFlexpwm2ExtSync0   = 60|0x10000U, /**< XBAR1_OUT60 output assigned to FLEXPWM2_EXT_SYNC0 */
    kXBAR1_OutputFlexpwm2ExtSync1   = 61|0x10000U, /**< XBAR1_OUT61 output assigned to FLEXPWM2_EXT_SYNC1 */
    kXBAR1_OutputFlexpwm2ExtSync2   = 62|0x10000U, /**< XBAR1_OUT62 output assigned to FLEXPWM2_EXT_SYNC2 */
    kXBAR1_OutputFlexpwm2ExtSync3   = 63|0x10000U, /**< XBAR1_OUT63 output assigned to FLEXPWM2_EXT_SYNC3 */
    kXBAR1_OutputFlexpwm2ExtClk     = 64|0x10000U, /**< XBAR1_OUT64 output assigned to FLEXPWM2_EXT_CLK */
    kXBAR1_OutputFlexpwm2Fault0     = 65|0x10000U, /**< XBAR1_OUT65 output assigned to FLEXPWM2_FAULT0 */
    kXBAR1_OutputFlexpwm2Fault1     = 66|0x10000U, /**< XBAR1_OUT66 output assigned to FLEXPWM2_FAULT1 */
    kXBAR1_OutputFlexpwm2ExtForce   = 67|0x10000U, /**< XBAR1_OUT67 output assigned to FLEXPWM2_EXT_FORCE */
    kXBAR1_OutputFlexpwm34Exta0     = 68|0x10000U, /**< XBAR1_OUT68 output assigned to FLEXPWM3_4_EXTA0 */
    kXBAR1_OutputFlexpwm34Exta1     = 69|0x10000U, /**< XBAR1_OUT69 output assigned to FLEXPWM3_4_EXTA1 */
    kXBAR1_OutputFlexpwm34Exta2     = 70|0x10000U, /**< XBAR1_OUT70 output assigned to FLEXPWM3_4_EXTA2 */
    kXBAR1_OutputFlexpwm34Exta3     = 71|0x10000U, /**< XBAR1_OUT71 output assigned to FLEXPWM3_4_EXTA3 */
    kXBAR1_OutputFlexpwm34ExtClk    = 72|0x10000U, /**< XBAR1_OUT72 output assigned to FLEXPWM3_4_EXT_CLK */
    kXBAR1_OutputFlexpwm3ExtSync0   = 73|0x10000U, /**< XBAR1_OUT73 output assigned to FLEXPWM3_EXT_SYNC0 */
    kXBAR1_OutputFlexpwm3ExtSync1   = 74|0x10000U, /**< XBAR1_OUT74 output assigned to FLEXPWM3_EXT_SYNC1 */
    kXBAR1_OutputFlexpwm3ExtSync2   = 75|0x10000U, /**< XBAR1_OUT75 output assigned to FLEXPWM3_EXT_SYNC2 */
    kXBAR1_OutputFlexpwm3ExtSync3   = 76|0x10000U, /**< XBAR1_OUT76 output assigned to FLEXPWM3_EXT_SYNC3 */
    kXBAR1_OutputFlexpwm3Fault0     = 77|0x10000U, /**< XBAR1_OUT77 output assigned to FLEXPWM3_FAULT0 */
    kXBAR1_OutputFlexpwm3Fault1     = 78|0x10000U, /**< XBAR1_OUT78 output assigned to FLEXPWM3_FAULT1 */
    kXBAR1_OutputFlexpwm3ExtForce   = 79|0x10000U, /**< XBAR1_OUT79 output assigned to FLEXPWM3_EXT_FORCE */
    kXBAR1_OutputFlexpwm4ExtSync0   = 80|0x10000U, /**< XBAR1_OUT80 output assigned to FLEXPWM4_EXT_SYNC0 */
    kXBAR1_OutputFlexpwm4ExtSync1   = 81|0x10000U, /**< XBAR1_OUT81 output assigned to FLEXPWM4_EXT_SYNC1 */
    kXBAR1_OutputFlexpwm4ExtSync2   = 82|0x10000U, /**< XBAR1_OUT82 output assigned to FLEXPWM4_EXT_SYNC2 */
    kXBAR1_OutputFlexpwm4ExtSync3   = 83|0x10000U, /**< XBAR1_OUT83 output assigned to FLEXPWM4_EXT_SYNC3 */
    kXBAR1_OutputFlexpwm4Fault0     = 84|0x10000U, /**< XBAR1_OUT84 output assigned to FLEXPWM4_FAULT0 */
    kXBAR1_OutputFlexpwm4Fault1     = 85|0x10000U, /**< XBAR1_OUT85 output assigned to FLEXPWM4_FAULT1 */
    kXBAR1_OutputFlexpwm4ExtForce   = 86|0x10000U, /**< XBAR1_OUT86 output assigned to FLEXPWM4_EXT_FORCE */
    kXBAR1_OutputEqdc1Phasea        = 87|0x10000U, /**< XBAR1_OUT87 output assigned to EQDC1_PHASEA */
    kXBAR1_OutputEqdc1Phaseb        = 88|0x10000U, /**< XBAR1_OUT88 output assigned to EQDC1_PHASEB */
    kXBAR1_OutputEqdc1Index         = 89|0x10000U, /**< XBAR1_OUT89 output assigned to EQDC1_INDEX */
    kXBAR1_OutputEqdc1Home          = 90|0x10000U, /**< XBAR1_OUT90 output assigned to EQDC1_HOME */
    kXBAR1_OutputEqdc1Trigger       = 91|0x10000U, /**< XBAR1_OUT91 output assigned to EQDC1_TRIGGER */
    kXBAR1_OutputEqdc2Phasea        = 92|0x10000U, /**< XBAR1_OUT92 output assigned to EQDC2_PHASEA */
    kXBAR1_OutputEqdc2Phaseb        = 93|0x10000U, /**< XBAR1_OUT93 output assigned to EQDC2_PHASEB */
    kXBAR1_OutputEqdc2Index         = 94|0x10000U, /**< XBAR1_OUT94 output assigned to EQDC2_INDEX */
    kXBAR1_OutputEqdc2Home          = 95|0x10000U, /**< XBAR1_OUT95 output assigned to EQDC2_HOME */
    kXBAR1_OutputEqdc2Trigger       = 96|0x10000U, /**< XBAR1_OUT96 output assigned to EQDC2_TRIGGER */
    kXBAR1_OutputEqdc3Phasea        = 97|0x10000U, /**< XBAR1_OUT97 output assigned to EQDC3_PHASEA */
    kXBAR1_OutputEqdc3Phaseb        = 98|0x10000U, /**< XBAR1_OUT98 output assigned to EQDC3_PHASEB */
    kXBAR1_OutputEqdc3Index         = 99|0x10000U, /**< XBAR1_OUT99 output assigned to EQDC3_INDEX */
    kXBAR1_OutputEqdc3Home          = 100|0x10000U, /**< XBAR1_OUT100 output assigned to EQDC3_HOME */
    kXBAR1_OutputEqdc3Trigger       = 101|0x10000U, /**< XBAR1_OUT101 output assigned to EQDC3_TRIGGER */
    kXBAR1_OutputEqdc4Phasea        = 102|0x10000U, /**< XBAR1_OUT102 output assigned to EQDC4_PHASEA */
    kXBAR1_OutputEqdc4Phaseb        = 103|0x10000U, /**< XBAR1_OUT103 output assigned to EQDC4_PHASEB */
    kXBAR1_OutputEqdc4Index         = 104|0x10000U, /**< XBAR1_OUT104 output assigned to EQDC4_INDEX */
    kXBAR1_OutputEqdc4Home          = 105|0x10000U, /**< XBAR1_OUT105 output assigned to EQDC4_HOME */
    kXBAR1_OutputEqdc4Trigger       = 106|0x10000U, /**< XBAR1_OUT106 output assigned to EQDC4_TRIGGER */
    kXBAR1_OutputQtimer1Timer0      = 107|0x10000U, /**< XBAR1_OUT107 output assigned to QTIMER1_TIMER0 */
    kXBAR1_OutputQtimer1Timer1      = 108|0x10000U, /**< XBAR1_OUT108 output assigned to QTIMER1_TIMER1 */
    kXBAR1_OutputQtimer1Timer2      = 109|0x10000U, /**< XBAR1_OUT109 output assigned to QTIMER1_TIMER2 */
    kXBAR1_OutputQtimer1Timer3      = 110|0x10000U, /**< XBAR1_OUT110 output assigned to QTIMER1_TIMER3 */
    kXBAR1_OutputQtimer2Timer0      = 111|0x10000U, /**< XBAR1_OUT111 output assigned to QTIMER2_TIMER0 */
    kXBAR1_OutputQtimer2Timer1      = 112|0x10000U, /**< XBAR1_OUT112 output assigned to QTIMER2_TIMER1 */
    kXBAR1_OutputQtimer2Timer2      = 113|0x10000U, /**< XBAR1_OUT113 output assigned to QTIMER2_TIMER2 */
    kXBAR1_OutputQtimer2Timer3      = 114|0x10000U, /**< XBAR1_OUT114 output assigned to QTIMER2_TIMER3 */
    kXBAR1_OutputQtimer3Timer0      = 115|0x10000U, /**< XBAR1_OUT115 output assigned to QTIMER3_TIMER0 */
    kXBAR1_OutputQtimer3Timer1      = 116|0x10000U, /**< XBAR1_OUT116 output assigned to QTIMER3_TIMER1 */
    kXBAR1_OutputQtimer3Timer2      = 117|0x10000U, /**< XBAR1_OUT117 output assigned to QTIMER3_TIMER2 */
    kXBAR1_OutputQtimer3Timer3      = 118|0x10000U, /**< XBAR1_OUT118 output assigned to QTIMER3_TIMER3 */
    kXBAR1_OutputQtimer4Timer0      = 119|0x10000U, /**< XBAR1_OUT119 output assigned to QTIMER4_TIMER0 */
    kXBAR1_OutputQtimer4Timer1      = 120|0x10000U, /**< XBAR1_OUT120 output assigned to QTIMER4_TIMER1 */
    kXBAR1_OutputQtimer4Timer2      = 121|0x10000U, /**< XBAR1_OUT121 output assigned to QTIMER4_TIMER2 */
    kXBAR1_OutputQtimer4Timer3      = 122|0x10000U, /**< XBAR1_OUT122 output assigned to QTIMER4_TIMER3 */
    kXBAR1_OutputQtimer5Timer0      = 123|0x10000U, /**< XBAR1_OUT123 output assigned to QTIMER5_TIMER0 */
    kXBAR1_OutputQtimer5Timer1      = 124|0x10000U, /**< XBAR1_OUT124 output assigned to QTIMER5_TIMER1 */
    kXBAR1_OutputQtimer5Timer2      = 125|0x10000U, /**< XBAR1_OUT125 output assigned to QTIMER5_TIMER2 */
    kXBAR1_OutputQtimer5Timer3      = 126|0x10000U, /**< XBAR1_OUT126 output assigned to QTIMER5_TIMER3 */
    kXBAR1_OutputQtimer6Timer0      = 127|0x10000U, /**< XBAR1_OUT127 output assigned to QTIMER6_TIMER0 */
    kXBAR1_OutputQtimer6Timer1      = 128|0x10000U, /**< XBAR1_OUT128 output assigned to QTIMER6_TIMER1 */
    kXBAR1_OutputQtimer6Timer2      = 129|0x10000U, /**< XBAR1_OUT129 output assigned to QTIMER6_TIMER2 */
    kXBAR1_OutputQtimer6Timer3      = 130|0x10000U, /**< XBAR1_OUT130 output assigned to QTIMER6_TIMER3 */
    kXBAR1_OutputQtimer7Timer0      = 131|0x10000U, /**< XBAR1_OUT131 output assigned to QTIMER7_TIMER0 */
    kXBAR1_OutputQtimer7Timer1      = 132|0x10000U, /**< XBAR1_OUT132 output assigned to QTIMER7_TIMER1 */
    kXBAR1_OutputQtimer7Timer2      = 133|0x10000U, /**< XBAR1_OUT133 output assigned to QTIMER7_TIMER2 */
    kXBAR1_OutputQtimer7Timer3      = 134|0x10000U, /**< XBAR1_OUT134 output assigned to QTIMER7_TIMER3 */
    kXBAR1_OutputQtimer8Timer0      = 135|0x10000U, /**< XBAR1_OUT135 output assigned to QTIMER8_TIMER0 */
    kXBAR1_OutputQtimer8Timer1      = 136|0x10000U, /**< XBAR1_OUT136 output assigned to QTIMER8_TIMER1 */
    kXBAR1_OutputQtimer8Timer2      = 137|0x10000U, /**< XBAR1_OUT137 output assigned to QTIMER8_TIMER2 */
    kXBAR1_OutputQtimer8Timer3      = 138|0x10000U, /**< XBAR1_OUT138 output assigned to QTIMER8_TIMER3 */
    kXBAR1_OutputEwmIn              = 139|0x10000U, /**< XBAR1_OUT139 output assigned to EWM_IN */
    kXBAR1_OutputAdc12HwTrig0       = 140|0x10000U, /**< XBAR1_OUT140 output assigned to ADC1_2_HW_TRIG0 */
    kXBAR1_OutputAdc12HwTrig1       = 141|0x10000U, /**< XBAR1_OUT141 output assigned to ADC1_2_HW_TRIG1 */
    kXBAR1_OutputAdc12HwTrig2       = 142|0x10000U, /**< XBAR1_OUT142 output assigned to ADC1_2_HW_TRIG2 */
    kXBAR1_OutputAdc12HwTrig3       = 143|0x10000U, /**< XBAR1_OUT143 output assigned to ADC1_2_HW_TRIG3 */
    kXBAR1_OutputAdc12HwTrig4       = 144|0x10000U, /**< XBAR1_OUT144 output assigned to ADC1_2_HW_TRIG4 */
    kXBAR1_OutputAdc12HwTrig5       = 145|0x10000U, /**< XBAR1_OUT145 output assigned to ADC1_2_HW_TRIG5 */
    kXBAR1_OutputAdc12HwTrig6       = 146|0x10000U, /**< XBAR1_OUT146 output assigned to ADC1_2_HW_TRIG6 */
    kXBAR1_OutputAdc12HwTrig7       = 147|0x10000U, /**< XBAR1_OUT147 output assigned to ADC1_2_HW_TRIG7 */
    kXBAR1_OutputSinc123ExtTrig0    = 148|0x10000U, /**< XBAR1_OUT148 output assigned to SINC1_2_3_EXT_TRIG0 */
    kXBAR1_OutputSinc123ExtTrig1    = 149|0x10000U, /**< XBAR1_OUT149 output assigned to SINC1_2_3_EXT_TRIG1 */
    kXBAR1_OutputSinc123ExtTrig2    = 150|0x10000U, /**< XBAR1_OUT150 output assigned to SINC1_2_3_EXT_TRIG2 */
    kXBAR1_OutputSinc123ExtTrig3    = 151|0x10000U, /**< XBAR1_OUT151 output assigned to SINC1_2_3_EXT_TRIG3 */
    kXBAR1_OutputFlexio1TrigIn0     = 152|0x10000U, /**< XBAR1_OUT152 output assigned to FLEXIO1_TRIG_IN0 */
    kXBAR1_OutputFlexio1TrigIn1     = 153|0x10000U, /**< XBAR1_OUT153 output assigned to FLEXIO1_TRIG_IN1 */
    kXBAR1_OutputFlexio2TrigIn0     = 154|0x10000U, /**< XBAR1_OUT154 output assigned to FLEXIO2_TRIG_IN0 */
    kXBAR1_OutputFlexio2TrigIn1     = 155|0x10000U, /**< XBAR1_OUT155 output assigned to FLEXIO2_TRIG_IN1 */
    kXBAR1_OutputLpi2c1TrigIn       = 156|0x10000U, /**< XBAR1_OUT156 output assigned to LPI2C1_TRIG_IN */
    kXBAR1_OutputLpi2c2TrigIn       = 157|0x10000U, /**< XBAR1_OUT157 output assigned to LPI2C2_TRIG_IN */
    kXBAR1_OutputLpi2c3TrigIn       = 158|0x10000U, /**< XBAR1_OUT158 output assigned to LPI2C3_TRIG_IN */
    kXBAR1_OutputLpi2c4TrigIn       = 159|0x10000U, /**< XBAR1_OUT159 output assigned to LPI2C4_TRIG_IN */
    kXBAR1_OutputLpi2c5TrigIn       = 160|0x10000U, /**< XBAR1_OUT160 output assigned to LPI2C5_TRIG_IN */
    kXBAR1_OutputLpi2c6TrigIn       = 161|0x10000U, /**< XBAR1_OUT161 output assigned to LPI2C6_TRIG_IN */
    kXBAR1_OutputLpspi1TrigIn       = 162|0x10000U, /**< XBAR1_OUT162 output assigned to LPSPI1_TRIG_IN */
    kXBAR1_OutputLpspi2TrigIn       = 163|0x10000U, /**< XBAR1_OUT163 output assigned to LPSPI2_TRIG_IN */
    kXBAR1_OutputLpspi3TrigIn       = 164|0x10000U, /**< XBAR1_OUT164 output assigned to LPSPI3_TRIG_IN */
    kXBAR1_OutputLpspi4TrigIn       = 165|0x10000U, /**< XBAR1_OUT165 output assigned to LPSPI4_TRIG_IN */
    kXBAR1_OutputLpspi5TrigIn       = 166|0x10000U, /**< XBAR1_OUT166 output assigned to LPSPI5_TRIG_IN */
    kXBAR1_OutputLpspi6TrigIn       = 167|0x10000U, /**< XBAR1_OUT167 output assigned to LPSPI6_TRIG_IN */
    kXBAR1_OutputLpuart1TrigIn      = 168|0x10000U, /**< XBAR1_OUT168 output assigned to LPUART1_TRIG_IN */
    kXBAR1_OutputLpuart2TrigIn      = 169|0x10000U, /**< XBAR1_OUT169 output assigned to LPUART2_TRIG_IN */
    kXBAR1_OutputLpuart3TrigIn      = 170|0x10000U, /**< XBAR1_OUT170 output assigned to LPUART3_TRIG_IN */
    kXBAR1_OutputLpuart4TrigIn      = 171|0x10000U, /**< XBAR1_OUT171 output assigned to LPUART4_TRIG_IN */
    kXBAR1_OutputLpuart5TrigIn      = 172|0x10000U, /**< XBAR1_OUT172 output assigned to LPUART5_TRIG_IN */
    kXBAR1_OutputLpuart6TrigIn      = 173|0x10000U, /**< XBAR1_OUT173 output assigned to LPUART6_TRIG_IN */
    kXBAR1_OutputLpuart7TrigIn      = 174|0x10000U, /**< XBAR1_OUT174 output assigned to LPUART7_TRIG_IN */
    kXBAR1_OutputLpuart8TrigIn      = 175|0x10000U, /**< XBAR1_OUT175 output assigned to LPUART8_TRIG_IN */
    kXBAR1_OutputLpuart9TrigIn      = 176|0x10000U, /**< XBAR1_OUT176 output assigned to LPUART9_TRIG_IN */
    kXBAR1_OutputLpuart10TrigIn     = 177|0x10000U, /**< XBAR1_OUT177 output assigned to LPUART10_TRIG_IN */
    kXBAR1_OutputLpuart11TrigIn     = 178|0x10000U, /**< XBAR1_OUT178 output assigned to LPUART11_TRIG_IN */
    kXBAR1_OutputLpuart12TrigIn     = 179|0x10000U, /**< XBAR1_OUT179 output assigned to LPUART12_TRIG_IN */
    kXBAR1_OutputLpit123TrigIn0     = 180|0x10000U, /**< XBAR1_OUT180 output assigned to LPIT1_2_3_TRIG_IN0 */
    kXBAR1_OutputLpit123TrigIn1     = 181|0x10000U, /**< XBAR1_OUT181 output assigned to LPIT1_2_3_TRIG_IN1 */
    kXBAR1_OutputLpit123TrigIn2     = 182|0x10000U, /**< XBAR1_OUT182 output assigned to LPIT1_2_3_TRIG_IN2 */
    kXBAR1_OutputLpit123TrigIn3     = 183|0x10000U, /**< XBAR1_OUT183 output assigned to LPIT1_2_3_TRIG_IN3 */
    kXBAR1_OutputTpm123TrigIn0      = 184|0x10000U, /**< XBAR1_OUT184 output assigned to TPM1_2_3_TRIG_IN0 */
    kXBAR1_OutputTpm1TrigIn1        = 185|0x10000U, /**< XBAR1_OUT185 output assigned to TPM1_TRIG_IN1 */
    kXBAR1_OutputTpm2TrigIn1        = 186|0x10000U, /**< XBAR1_OUT186 output assigned to TPM2_TRIG_IN1 */
    kXBAR1_OutputTpm3TrigIn1        = 187|0x10000U, /**< XBAR1_OUT187 output assigned to TPM3_TRIG_IN1 */
    kXBAR1_OutputTpm123TrigIn2      = 188|0x10000U, /**< XBAR1_OUT188 output assigned to TPM1_2_3_TRIG_IN2 */
    kXBAR1_OutputTpm1TrigIn3        = 189|0x10000U, /**< XBAR1_OUT189 output assigned to TPM1_TRIG_IN3 */
    kXBAR1_OutputTpm2TrigIn3        = 190|0x10000U, /**< XBAR1_OUT190 output assigned to TPM2_TRIG_IN3 */
    kXBAR1_OutputTpm3TrigIn3        = 191|0x10000U, /**< XBAR1_OUT191 output assigned to TPM3_TRIG_IN3 */
    kXBAR1_OutputTpm456TrigIn0      = 192|0x10000U, /**< XBAR1_OUT192 output assigned to TPM4_5_6_TRIG_IN0 */
    kXBAR1_OutputTpm4TrigIn1        = 193|0x10000U, /**< XBAR1_OUT193 output assigned to TPM4_TRIG_IN1 */
    kXBAR1_OutputTpm5TrigIn1        = 194|0x10000U, /**< XBAR1_OUT194 output assigned to TPM5_TRIG_IN1 */
    kXBAR1_OutputTpm6TrigIn1        = 195|0x10000U, /**< XBAR1_OUT195 output assigned to TPM6_TRIG_IN1 */
    kXBAR1_OutputTpm456TrigIn2      = 196|0x10000U, /**< XBAR1_OUT196 output assigned to TPM4_5_6_TRIG_IN2 */
    kXBAR1_OutputTpm4TrigIn3        = 197|0x10000U, /**< XBAR1_OUT197 output assigned to TPM4_TRIG_IN3 */
    kXBAR1_OutputTpm5TrigIn3        = 198|0x10000U, /**< XBAR1_OUT198 output assigned to TPM5_TRIG_IN3 */
    kXBAR1_OutputTpm6TrigIn3        = 199|0x10000U, /**< XBAR1_OUT199 output assigned to TPM6_TRIG_IN3 */
    kXBAR1_OutputNetcTmrTrig1       = 200|0x10000U, /**< XBAR1_OUT200 output assigned to NETC_TMR_TRIG1 */
    kXBAR1_OutputNetcTmrTrig2       = 201|0x10000U, /**< XBAR1_OUT201 output assigned to NETC_TMR_TRIG2 */
    kXBAR1_OutputRESERVED202        = 202|0x10000U, /**< XBAR1_OUT202 output is reserved. */
    kXBAR1_OutputRESERVED203        = 203|0x10000U, /**< XBAR1_OUT203 output is reserved. */
    kXBAR1_OutputRESERVED204        = 204|0x10000U, /**< XBAR1_OUT204 output is reserved. */
    kXBAR1_OutputRESERVED205        = 205|0x10000U, /**< XBAR1_OUT205 output is reserved. */
    kXBAR1_OutputEqdc1Icap1         = 206|0x10000U, /**< XBAR1_OUT206 output assigned to EQDC1_ICAP1 */
    kXBAR1_OutputEqdc1Icap2         = 207|0x10000U, /**< XBAR1_OUT207 output assigned to EQDC1_ICAP2 */
    kXBAR1_OutputEqdc1Icap3         = 208|0x10000U, /**< XBAR1_OUT208 output assigned to EQDC1_ICAP3 */
    kXBAR1_OutputEqdc2Icap1         = 209|0x10000U, /**< XBAR1_OUT209 output assigned to EQDC2_ICAP1 */
    kXBAR1_OutputEqdc2Icap2         = 210|0x10000U, /**< XBAR1_OUT210 output assigned to EQDC2_ICAP2 */
    kXBAR1_OutputEqdc2Icap3         = 211|0x10000U, /**< XBAR1_OUT211 output assigned to EQDC2_ICAP3 */
    kXBAR1_OutputEqdc3Icap1         = 212|0x10000U, /**< XBAR1_OUT212 output assigned to EQDC3_ICAP1 */
    kXBAR1_OutputEqdc3Icap2         = 213|0x10000U, /**< XBAR1_OUT213 output assigned to EQDC3_ICAP2 */
    kXBAR1_OutputEqdc3Icap3         = 214|0x10000U, /**< XBAR1_OUT214 output assigned to EQDC3_ICAP3 */
    kXBAR1_OutputEqdc4Icap1         = 215|0x10000U, /**< XBAR1_OUT215 output assigned to EQDC4_ICAP1 */
    kXBAR1_OutputEqdc4Icap2         = 216|0x10000U, /**< XBAR1_OUT216 output assigned to EQDC4_ICAP2 */
    kXBAR1_OutputEqdc4Icap3         = 217|0x10000U, /**< XBAR1_OUT217 output assigned to EQDC4_ICAP3 */
    kXBAR1_OutputEcatLatchIn0       = 218|0x10000U, /**< XBAR1_OUT218 output assigned to ECAT_LATCH_IN0 */
    kXBAR1_OutputEcatLatchIn1       = 219|0x10000U, /**< XBAR1_OUT219 output assigned to ECAT_LATCH_IN1 */
    kXBAR1_OutputDutClk             = 220|0x10000U, /**< XBAR1_OUT220 output assigned to DUT_CLK */
    kXBAR2_OutputAoi1In00           = 0|0x20000U,  /**< XBAR2_OUT0 output assigned to AOI1_IN00 */
    kXBAR2_OutputAoi1In01           = 1|0x20000U,  /**< XBAR2_OUT1 output assigned to AOI1_IN01 */
    kXBAR2_OutputAoi1In02           = 2|0x20000U,  /**< XBAR2_OUT2 output assigned to AOI1_IN02 */
    kXBAR2_OutputAoi1In03           = 3|0x20000U,  /**< XBAR2_OUT3 output assigned to AOI1_IN03 */
    kXBAR2_OutputAoi1In04           = 4|0x20000U,  /**< XBAR2_OUT4 output assigned to AOI1_IN04 */
    kXBAR2_OutputAoi1In05           = 5|0x20000U,  /**< XBAR2_OUT5 output assigned to AOI1_IN05 */
    kXBAR2_OutputAoi1In06           = 6|0x20000U,  /**< XBAR2_OUT6 output assigned to AOI1_IN06 */
    kXBAR2_OutputAoi1In07           = 7|0x20000U,  /**< XBAR2_OUT7 output assigned to AOI1_IN07 */
    kXBAR2_OutputAoi1In08           = 8|0x20000U,  /**< XBAR2_OUT8 output assigned to AOI1_IN08 */
    kXBAR2_OutputAoi1In09           = 9|0x20000U,  /**< XBAR2_OUT9 output assigned to AOI1_IN09 */
    kXBAR2_OutputAoi1In10           = 10|0x20000U, /**< XBAR2_OUT10 output assigned to AOI1_IN10 */
    kXBAR2_OutputAoi1In11           = 11|0x20000U, /**< XBAR2_OUT11 output assigned to AOI1_IN11 */
    kXBAR2_OutputAoi1In12           = 12|0x20000U, /**< XBAR2_OUT12 output assigned to AOI1_IN12 */
    kXBAR2_OutputAoi1In13           = 13|0x20000U, /**< XBAR2_OUT13 output assigned to AOI1_IN13 */
    kXBAR2_OutputAoi1In14           = 14|0x20000U, /**< XBAR2_OUT14 output assigned to AOI1_IN14 */
    kXBAR2_OutputAoi1In15           = 15|0x20000U, /**< XBAR2_OUT15 output assigned to AOI1_IN15 */
    kXBAR2_OutputAoi3In00           = 16|0x20000U, /**< XBAR2_OUT16 output assigned to AOI3_IN00 */
    kXBAR2_OutputAoi3In01           = 17|0x20000U, /**< XBAR2_OUT17 output assigned to AOI3_IN01 */
    kXBAR2_OutputAoi3In02           = 18|0x20000U, /**< XBAR2_OUT18 output assigned to AOI3_IN02 */
    kXBAR2_OutputAoi3In03           = 19|0x20000U, /**< XBAR2_OUT19 output assigned to AOI3_IN03 */
    kXBAR2_OutputAoi3In04           = 20|0x20000U, /**< XBAR2_OUT20 output assigned to AOI3_IN04 */
    kXBAR2_OutputAoi3In05           = 21|0x20000U, /**< XBAR2_OUT21 output assigned to AOI3_IN05 */
    kXBAR2_OutputAoi3In06           = 22|0x20000U, /**< XBAR2_OUT22 output assigned to AOI3_IN06 */
    kXBAR2_OutputAoi3In07           = 23|0x20000U, /**< XBAR2_OUT23 output assigned to AOI3_IN07 */
    kXBAR2_OutputAoi3In08           = 24|0x20000U, /**< XBAR2_OUT24 output assigned to AOI3_IN08 */
    kXBAR2_OutputAoi3In09           = 25|0x20000U, /**< XBAR2_OUT25 output assigned to AOI3_IN09 */
    kXBAR2_OutputAoi3In10           = 26|0x20000U, /**< XBAR2_OUT26 output assigned to AOI3_IN10 */
    kXBAR2_OutputAoi3In11           = 27|0x20000U, /**< XBAR2_OUT27 output assigned to AOI3_IN11 */
    kXBAR2_OutputAoi3In12           = 28|0x20000U, /**< XBAR2_OUT28 output assigned to AOI3_IN12 */
    kXBAR2_OutputAoi3In13           = 29|0x20000U, /**< XBAR2_OUT29 output assigned to AOI3_IN13 */
    kXBAR2_OutputAoi3In14           = 30|0x20000U, /**< XBAR2_OUT30 output assigned to AOI3_IN14 */
    kXBAR2_OutputAoi3In15           = 31|0x20000U, /**< XBAR2_OUT31 output assigned to AOI3_IN15 */
    kXBAR3_OutputAoi2In00           = 0|0x30000U,  /**< XBAR3_OUT0 output assigned to AOI2_IN00 */
    kXBAR3_OutputAoi2In01           = 1|0x30000U,  /**< XBAR3_OUT1 output assigned to AOI2_IN01 */
    kXBAR3_OutputAoi2In02           = 2|0x30000U,  /**< XBAR3_OUT2 output assigned to AOI2_IN02 */
    kXBAR3_OutputAoi2In03           = 3|0x30000U,  /**< XBAR3_OUT3 output assigned to AOI2_IN03 */
    kXBAR3_OutputAoi2In04           = 4|0x30000U,  /**< XBAR3_OUT4 output assigned to AOI2_IN04 */
    kXBAR3_OutputAoi2In05           = 5|0x30000U,  /**< XBAR3_OUT5 output assigned to AOI2_IN05 */
    kXBAR3_OutputAoi2In06           = 6|0x30000U,  /**< XBAR3_OUT6 output assigned to AOI2_IN06 */
    kXBAR3_OutputAoi2In07           = 7|0x30000U,  /**< XBAR3_OUT7 output assigned to AOI2_IN07 */
    kXBAR3_OutputAoi2In08           = 8|0x30000U,  /**< XBAR3_OUT8 output assigned to AOI2_IN08 */
    kXBAR3_OutputAoi2In09           = 9|0x30000U,  /**< XBAR3_OUT9 output assigned to AOI2_IN09 */
    kXBAR3_OutputAoi2In10           = 10|0x30000U, /**< XBAR3_OUT10 output assigned to AOI2_IN10 */
    kXBAR3_OutputAoi2In11           = 11|0x30000U, /**< XBAR3_OUT11 output assigned to AOI2_IN11 */
    kXBAR3_OutputAoi2In12           = 12|0x30000U, /**< XBAR3_OUT12 output assigned to AOI2_IN12 */
    kXBAR3_OutputAoi2In13           = 13|0x30000U, /**< XBAR3_OUT13 output assigned to AOI2_IN13 */
    kXBAR3_OutputAoi2In14           = 14|0x30000U, /**< XBAR3_OUT14 output assigned to AOI2_IN14 */
    kXBAR3_OutputAoi2In15           = 15|0x30000U, /**< XBAR3_OUT15 output assigned to AOI2_IN15 */
    kXBAR3_OutputAoi4In00           = 16|0x30000U, /**< XBAR3_OUT16 output assigned to AOI4_IN00 */
    kXBAR3_OutputAoi4In01           = 17|0x30000U, /**< XBAR3_OUT17 output assigned to AOI4_IN01 */
    kXBAR3_OutputAoi4In02           = 18|0x30000U, /**< XBAR3_OUT18 output assigned to AOI4_IN02 */
    kXBAR3_OutputAoi4In03           = 19|0x30000U, /**< XBAR3_OUT19 output assigned to AOI4_IN03 */
    kXBAR3_OutputAoi4In04           = 20|0x30000U, /**< XBAR3_OUT20 output assigned to AOI4_IN04 */
    kXBAR3_OutputAoi4In05           = 21|0x30000U, /**< XBAR3_OUT21 output assigned to AOI4_IN05 */
    kXBAR3_OutputAoi4In06           = 22|0x30000U, /**< XBAR3_OUT22 output assigned to AOI4_IN06 */
    kXBAR3_OutputAoi4In07           = 23|0x30000U, /**< XBAR3_OUT23 output assigned to AOI4_IN07 */
    kXBAR3_OutputAoi4In08           = 24|0x30000U, /**< XBAR3_OUT24 output assigned to AOI4_IN08 */
    kXBAR3_OutputAoi4In09           = 25|0x30000U, /**< XBAR3_OUT25 output assigned to AOI4_IN09 */
    kXBAR3_OutputAoi4In10           = 26|0x30000U, /**< XBAR3_OUT26 output assigned to AOI4_IN10 */
    kXBAR3_OutputAoi4In11           = 27|0x30000U, /**< XBAR3_OUT27 output assigned to AOI4_IN11 */
    kXBAR3_OutputAoi4In12           = 28|0x30000U, /**< XBAR3_OUT28 output assigned to AOI4_IN12 */
    kXBAR3_OutputAoi4In13           = 29|0x30000U, /**< XBAR3_OUT29 output assigned to AOI4_IN13 */
    kXBAR3_OutputAoi4In14           = 30|0x30000U, /**< XBAR3_OUT30 output assigned to AOI4_IN14 */
    kXBAR3_OutputAoi4In15           = 31|0x30000U, /**< XBAR3_OUT31 output assigned to AOI4_IN15 */
} xbar_output_signal_t;
#endif /* XBAR_OUTPUT_SIGNAL_T_ */


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
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- XBAR_NUM_OUT221 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_NUM_OUT221_Peripheral_Access_Layer XBAR_NUM_OUT221 Peripheral Access Layer
 * @{
 */

/** XBAR_NUM_OUT221 - Size of Registers Arrays */
#define XBAR_NUM_OUT221_SEL_COUNT                 111u
#define XBAR_NUM_OUT221_CTRL_COUNT                2u

/** XBAR_NUM_OUT221 - Register Layout Typedef */
typedef struct {
  __IO uint16_t SEL[XBAR_NUM_OUT221_SEL_COUNT];    /**< Crossbar Select Register, array offset: 0x0, array step: 0x2 */
  __IO uint16_t CTRL[XBAR_NUM_OUT221_CTRL_COUNT];  /**< Crossbar Control Register, array offset: 0xDE, array step: 0x2 */
} XBAR_NUM_OUT221_Type;

/* ----------------------------------------------------------------------------
   -- XBAR_NUM_OUT221 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_NUM_OUT221_Register_Masks XBAR_NUM_OUT221 Register Masks
 * @{
 */

/*! @name SEL - Crossbar Select Register */
/*! @{ */

#define XBAR_NUM_OUT221_SEL_SEL0_MASK            (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL0_SHIFT           (0U)
/*! SEL0 - SEL0 */
#define XBAR_NUM_OUT221_SEL_SEL0(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL0_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL0_MASK)

#define XBAR_NUM_OUT221_SEL_SEL2_MASK            (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL2_SHIFT           (0U)
/*! SEL2 - SEL2 */
#define XBAR_NUM_OUT221_SEL_SEL2(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL2_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL2_MASK)

#define XBAR_NUM_OUT221_SEL_SEL4_MASK            (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL4_SHIFT           (0U)
/*! SEL4 - SEL4 */
#define XBAR_NUM_OUT221_SEL_SEL4(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL4_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL4_MASK)

#define XBAR_NUM_OUT221_SEL_SEL6_MASK            (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL6_SHIFT           (0U)
/*! SEL6 - SEL6 */
#define XBAR_NUM_OUT221_SEL_SEL6(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL6_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL6_MASK)

#define XBAR_NUM_OUT221_SEL_SEL8_MASK            (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL8_SHIFT           (0U)
/*! SEL8 - SEL8 */
#define XBAR_NUM_OUT221_SEL_SEL8(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL8_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL8_MASK)

#define XBAR_NUM_OUT221_SEL_SEL10_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL10_SHIFT          (0U)
/*! SEL10 - SEL10 */
#define XBAR_NUM_OUT221_SEL_SEL10(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL10_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL10_MASK)

#define XBAR_NUM_OUT221_SEL_SEL12_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL12_SHIFT          (0U)
/*! SEL12 - SEL12 */
#define XBAR_NUM_OUT221_SEL_SEL12(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL12_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL12_MASK)

#define XBAR_NUM_OUT221_SEL_SEL14_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL14_SHIFT          (0U)
/*! SEL14 - SEL14 */
#define XBAR_NUM_OUT221_SEL_SEL14(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL14_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL14_MASK)

#define XBAR_NUM_OUT221_SEL_SEL16_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL16_SHIFT          (0U)
/*! SEL16 - SEL16 */
#define XBAR_NUM_OUT221_SEL_SEL16(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL16_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL16_MASK)

#define XBAR_NUM_OUT221_SEL_SEL18_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL18_SHIFT          (0U)
/*! SEL18 - SEL18 */
#define XBAR_NUM_OUT221_SEL_SEL18(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL18_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL18_MASK)

#define XBAR_NUM_OUT221_SEL_SEL20_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL20_SHIFT          (0U)
/*! SEL20 - SEL20 */
#define XBAR_NUM_OUT221_SEL_SEL20(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL20_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL20_MASK)

#define XBAR_NUM_OUT221_SEL_SEL22_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL22_SHIFT          (0U)
/*! SEL22 - SEL22 */
#define XBAR_NUM_OUT221_SEL_SEL22(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL22_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL22_MASK)

#define XBAR_NUM_OUT221_SEL_SEL24_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL24_SHIFT          (0U)
/*! SEL24 - SEL24 */
#define XBAR_NUM_OUT221_SEL_SEL24(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL24_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL24_MASK)

#define XBAR_NUM_OUT221_SEL_SEL26_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL26_SHIFT          (0U)
/*! SEL26 - SEL26 */
#define XBAR_NUM_OUT221_SEL_SEL26(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL26_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL26_MASK)

#define XBAR_NUM_OUT221_SEL_SEL28_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL28_SHIFT          (0U)
/*! SEL28 - SEL28 */
#define XBAR_NUM_OUT221_SEL_SEL28(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL28_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL28_MASK)

#define XBAR_NUM_OUT221_SEL_SEL30_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL30_SHIFT          (0U)
/*! SEL30 - SEL30 */
#define XBAR_NUM_OUT221_SEL_SEL30(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL30_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL30_MASK)

#define XBAR_NUM_OUT221_SEL_SEL32_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL32_SHIFT          (0U)
/*! SEL32 - SEL32 */
#define XBAR_NUM_OUT221_SEL_SEL32(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL32_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL32_MASK)

#define XBAR_NUM_OUT221_SEL_SEL34_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL34_SHIFT          (0U)
/*! SEL34 - SEL34 */
#define XBAR_NUM_OUT221_SEL_SEL34(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL34_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL34_MASK)

#define XBAR_NUM_OUT221_SEL_SEL36_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL36_SHIFT          (0U)
/*! SEL36 - SEL36 */
#define XBAR_NUM_OUT221_SEL_SEL36(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL36_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL36_MASK)

#define XBAR_NUM_OUT221_SEL_SEL38_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL38_SHIFT          (0U)
/*! SEL38 - SEL38 */
#define XBAR_NUM_OUT221_SEL_SEL38(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL38_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL38_MASK)

#define XBAR_NUM_OUT221_SEL_SEL40_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL40_SHIFT          (0U)
/*! SEL40 - SEL40 */
#define XBAR_NUM_OUT221_SEL_SEL40(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL40_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL40_MASK)

#define XBAR_NUM_OUT221_SEL_SEL42_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL42_SHIFT          (0U)
/*! SEL42 - SEL42 */
#define XBAR_NUM_OUT221_SEL_SEL42(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL42_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL42_MASK)

#define XBAR_NUM_OUT221_SEL_SEL44_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL44_SHIFT          (0U)
/*! SEL44 - SEL44 */
#define XBAR_NUM_OUT221_SEL_SEL44(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL44_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL44_MASK)

#define XBAR_NUM_OUT221_SEL_SEL46_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL46_SHIFT          (0U)
/*! SEL46 - SEL46 */
#define XBAR_NUM_OUT221_SEL_SEL46(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL46_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL46_MASK)

#define XBAR_NUM_OUT221_SEL_SEL48_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL48_SHIFT          (0U)
/*! SEL48 - SEL48 */
#define XBAR_NUM_OUT221_SEL_SEL48(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL48_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL48_MASK)

#define XBAR_NUM_OUT221_SEL_SEL50_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL50_SHIFT          (0U)
/*! SEL50 - SEL50 */
#define XBAR_NUM_OUT221_SEL_SEL50(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL50_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL50_MASK)

#define XBAR_NUM_OUT221_SEL_SEL52_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL52_SHIFT          (0U)
/*! SEL52 - SEL52 */
#define XBAR_NUM_OUT221_SEL_SEL52(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL52_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL52_MASK)

#define XBAR_NUM_OUT221_SEL_SEL54_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL54_SHIFT          (0U)
/*! SEL54 - SEL54 */
#define XBAR_NUM_OUT221_SEL_SEL54(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL54_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL54_MASK)

#define XBAR_NUM_OUT221_SEL_SEL56_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL56_SHIFT          (0U)
/*! SEL56 - SEL56 */
#define XBAR_NUM_OUT221_SEL_SEL56(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL56_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL56_MASK)

#define XBAR_NUM_OUT221_SEL_SEL58_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL58_SHIFT          (0U)
/*! SEL58 - SEL58 */
#define XBAR_NUM_OUT221_SEL_SEL58(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL58_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL58_MASK)

#define XBAR_NUM_OUT221_SEL_SEL60_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL60_SHIFT          (0U)
/*! SEL60 - SEL60 */
#define XBAR_NUM_OUT221_SEL_SEL60(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL60_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL60_MASK)

#define XBAR_NUM_OUT221_SEL_SEL62_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL62_SHIFT          (0U)
/*! SEL62 - SEL62 */
#define XBAR_NUM_OUT221_SEL_SEL62(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL62_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL62_MASK)

#define XBAR_NUM_OUT221_SEL_SEL64_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL64_SHIFT          (0U)
/*! SEL64 - SEL64 */
#define XBAR_NUM_OUT221_SEL_SEL64(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL64_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL64_MASK)

#define XBAR_NUM_OUT221_SEL_SEL66_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL66_SHIFT          (0U)
/*! SEL66 - SEL66 */
#define XBAR_NUM_OUT221_SEL_SEL66(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL66_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL66_MASK)

#define XBAR_NUM_OUT221_SEL_SEL68_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL68_SHIFT          (0U)
/*! SEL68 - SEL68 */
#define XBAR_NUM_OUT221_SEL_SEL68(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL68_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL68_MASK)

#define XBAR_NUM_OUT221_SEL_SEL70_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL70_SHIFT          (0U)
/*! SEL70 - SEL70 */
#define XBAR_NUM_OUT221_SEL_SEL70(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL70_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL70_MASK)

#define XBAR_NUM_OUT221_SEL_SEL72_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL72_SHIFT          (0U)
/*! SEL72 - SEL72 */
#define XBAR_NUM_OUT221_SEL_SEL72(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL72_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL72_MASK)

#define XBAR_NUM_OUT221_SEL_SEL74_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL74_SHIFT          (0U)
/*! SEL74 - SEL74 */
#define XBAR_NUM_OUT221_SEL_SEL74(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL74_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL74_MASK)

#define XBAR_NUM_OUT221_SEL_SEL76_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL76_SHIFT          (0U)
/*! SEL76 - SEL76 */
#define XBAR_NUM_OUT221_SEL_SEL76(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL76_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL76_MASK)

#define XBAR_NUM_OUT221_SEL_SEL78_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL78_SHIFT          (0U)
/*! SEL78 - SEL78 */
#define XBAR_NUM_OUT221_SEL_SEL78(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL78_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL78_MASK)

#define XBAR_NUM_OUT221_SEL_SEL80_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL80_SHIFT          (0U)
/*! SEL80 - SEL80 */
#define XBAR_NUM_OUT221_SEL_SEL80(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL80_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL80_MASK)

#define XBAR_NUM_OUT221_SEL_SEL82_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL82_SHIFT          (0U)
/*! SEL82 - SEL82 */
#define XBAR_NUM_OUT221_SEL_SEL82(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL82_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL82_MASK)

#define XBAR_NUM_OUT221_SEL_SEL84_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL84_SHIFT          (0U)
/*! SEL84 - SEL84 */
#define XBAR_NUM_OUT221_SEL_SEL84(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL84_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL84_MASK)

#define XBAR_NUM_OUT221_SEL_SEL86_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL86_SHIFT          (0U)
/*! SEL86 - SEL86 */
#define XBAR_NUM_OUT221_SEL_SEL86(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL86_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL86_MASK)

#define XBAR_NUM_OUT221_SEL_SEL88_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL88_SHIFT          (0U)
/*! SEL88 - SEL88 */
#define XBAR_NUM_OUT221_SEL_SEL88(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL88_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL88_MASK)

#define XBAR_NUM_OUT221_SEL_SEL90_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL90_SHIFT          (0U)
/*! SEL90 - SEL90 */
#define XBAR_NUM_OUT221_SEL_SEL90(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL90_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL90_MASK)

#define XBAR_NUM_OUT221_SEL_SEL92_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL92_SHIFT          (0U)
/*! SEL92 - SEL92 */
#define XBAR_NUM_OUT221_SEL_SEL92(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL92_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL92_MASK)

#define XBAR_NUM_OUT221_SEL_SEL94_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL94_SHIFT          (0U)
/*! SEL94 - SEL94 */
#define XBAR_NUM_OUT221_SEL_SEL94(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL94_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL94_MASK)

#define XBAR_NUM_OUT221_SEL_SEL96_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL96_SHIFT          (0U)
/*! SEL96 - SEL96 */
#define XBAR_NUM_OUT221_SEL_SEL96(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL96_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL96_MASK)

#define XBAR_NUM_OUT221_SEL_SEL98_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL98_SHIFT          (0U)
/*! SEL98 - SEL98 */
#define XBAR_NUM_OUT221_SEL_SEL98(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL98_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL98_MASK)

#define XBAR_NUM_OUT221_SEL_SEL100_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL100_SHIFT         (0U)
/*! SEL100 - SEL100 */
#define XBAR_NUM_OUT221_SEL_SEL100(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL100_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL100_MASK)

#define XBAR_NUM_OUT221_SEL_SEL102_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL102_SHIFT         (0U)
/*! SEL102 - SEL102 */
#define XBAR_NUM_OUT221_SEL_SEL102(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL102_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL102_MASK)

#define XBAR_NUM_OUT221_SEL_SEL104_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL104_SHIFT         (0U)
/*! SEL104 - SEL104 */
#define XBAR_NUM_OUT221_SEL_SEL104(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL104_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL104_MASK)

#define XBAR_NUM_OUT221_SEL_SEL106_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL106_SHIFT         (0U)
/*! SEL106 - SEL106 */
#define XBAR_NUM_OUT221_SEL_SEL106(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL106_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL106_MASK)

#define XBAR_NUM_OUT221_SEL_SEL108_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL108_SHIFT         (0U)
/*! SEL108 - SEL108 */
#define XBAR_NUM_OUT221_SEL_SEL108(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL108_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL108_MASK)

#define XBAR_NUM_OUT221_SEL_SEL110_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL110_SHIFT         (0U)
/*! SEL110 - SEL110 */
#define XBAR_NUM_OUT221_SEL_SEL110(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL110_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL110_MASK)

#define XBAR_NUM_OUT221_SEL_SEL112_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL112_SHIFT         (0U)
/*! SEL112 - SEL112 */
#define XBAR_NUM_OUT221_SEL_SEL112(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL112_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL112_MASK)

#define XBAR_NUM_OUT221_SEL_SEL114_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL114_SHIFT         (0U)
/*! SEL114 - SEL114 */
#define XBAR_NUM_OUT221_SEL_SEL114(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL114_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL114_MASK)

#define XBAR_NUM_OUT221_SEL_SEL116_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL116_SHIFT         (0U)
/*! SEL116 - SEL116 */
#define XBAR_NUM_OUT221_SEL_SEL116(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL116_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL116_MASK)

#define XBAR_NUM_OUT221_SEL_SEL118_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL118_SHIFT         (0U)
/*! SEL118 - SEL118 */
#define XBAR_NUM_OUT221_SEL_SEL118(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL118_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL118_MASK)

#define XBAR_NUM_OUT221_SEL_SEL120_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL120_SHIFT         (0U)
/*! SEL120 - SEL120 */
#define XBAR_NUM_OUT221_SEL_SEL120(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL120_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL120_MASK)

#define XBAR_NUM_OUT221_SEL_SEL122_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL122_SHIFT         (0U)
/*! SEL122 - SEL122 */
#define XBAR_NUM_OUT221_SEL_SEL122(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL122_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL122_MASK)

#define XBAR_NUM_OUT221_SEL_SEL124_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL124_SHIFT         (0U)
/*! SEL124 - SEL124 */
#define XBAR_NUM_OUT221_SEL_SEL124(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL124_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL124_MASK)

#define XBAR_NUM_OUT221_SEL_SEL126_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL126_SHIFT         (0U)
/*! SEL126 - SEL126 */
#define XBAR_NUM_OUT221_SEL_SEL126(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL126_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL126_MASK)

#define XBAR_NUM_OUT221_SEL_SEL128_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL128_SHIFT         (0U)
/*! SEL128 - SEL128 */
#define XBAR_NUM_OUT221_SEL_SEL128(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL128_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL128_MASK)

#define XBAR_NUM_OUT221_SEL_SEL130_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL130_SHIFT         (0U)
/*! SEL130 - SEL130 */
#define XBAR_NUM_OUT221_SEL_SEL130(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL130_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL130_MASK)

#define XBAR_NUM_OUT221_SEL_SEL132_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL132_SHIFT         (0U)
/*! SEL132 - SEL132 */
#define XBAR_NUM_OUT221_SEL_SEL132(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL132_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL132_MASK)

#define XBAR_NUM_OUT221_SEL_SEL134_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL134_SHIFT         (0U)
/*! SEL134 - SEL134 */
#define XBAR_NUM_OUT221_SEL_SEL134(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL134_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL134_MASK)

#define XBAR_NUM_OUT221_SEL_SEL136_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL136_SHIFT         (0U)
/*! SEL136 - SEL136 */
#define XBAR_NUM_OUT221_SEL_SEL136(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL136_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL136_MASK)

#define XBAR_NUM_OUT221_SEL_SEL138_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL138_SHIFT         (0U)
/*! SEL138 - SEL138 */
#define XBAR_NUM_OUT221_SEL_SEL138(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL138_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL138_MASK)

#define XBAR_NUM_OUT221_SEL_SEL140_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL140_SHIFT         (0U)
/*! SEL140 - SEL140 */
#define XBAR_NUM_OUT221_SEL_SEL140(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL140_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL140_MASK)

#define XBAR_NUM_OUT221_SEL_SEL142_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL142_SHIFT         (0U)
/*! SEL142 - SEL142 */
#define XBAR_NUM_OUT221_SEL_SEL142(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL142_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL142_MASK)

#define XBAR_NUM_OUT221_SEL_SEL144_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL144_SHIFT         (0U)
/*! SEL144 - SEL144 */
#define XBAR_NUM_OUT221_SEL_SEL144(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL144_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL144_MASK)

#define XBAR_NUM_OUT221_SEL_SEL146_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL146_SHIFT         (0U)
/*! SEL146 - SEL146 */
#define XBAR_NUM_OUT221_SEL_SEL146(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL146_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL146_MASK)

#define XBAR_NUM_OUT221_SEL_SEL148_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL148_SHIFT         (0U)
/*! SEL148 - SEL148 */
#define XBAR_NUM_OUT221_SEL_SEL148(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL148_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL148_MASK)

#define XBAR_NUM_OUT221_SEL_SEL150_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL150_SHIFT         (0U)
/*! SEL150 - SEL150 */
#define XBAR_NUM_OUT221_SEL_SEL150(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL150_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL150_MASK)

#define XBAR_NUM_OUT221_SEL_SEL152_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL152_SHIFT         (0U)
/*! SEL152 - SEL152 */
#define XBAR_NUM_OUT221_SEL_SEL152(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL152_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL152_MASK)

#define XBAR_NUM_OUT221_SEL_SEL154_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL154_SHIFT         (0U)
/*! SEL154 - SEL154 */
#define XBAR_NUM_OUT221_SEL_SEL154(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL154_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL154_MASK)

#define XBAR_NUM_OUT221_SEL_SEL156_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL156_SHIFT         (0U)
/*! SEL156 - SEL156 */
#define XBAR_NUM_OUT221_SEL_SEL156(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL156_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL156_MASK)

#define XBAR_NUM_OUT221_SEL_SEL158_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL158_SHIFT         (0U)
/*! SEL158 - SEL158 */
#define XBAR_NUM_OUT221_SEL_SEL158(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL158_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL158_MASK)

#define XBAR_NUM_OUT221_SEL_SEL160_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL160_SHIFT         (0U)
/*! SEL160 - SEL160 */
#define XBAR_NUM_OUT221_SEL_SEL160(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL160_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL160_MASK)

#define XBAR_NUM_OUT221_SEL_SEL162_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL162_SHIFT         (0U)
/*! SEL162 - SEL162 */
#define XBAR_NUM_OUT221_SEL_SEL162(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL162_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL162_MASK)

#define XBAR_NUM_OUT221_SEL_SEL164_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL164_SHIFT         (0U)
/*! SEL164 - SEL164 */
#define XBAR_NUM_OUT221_SEL_SEL164(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL164_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL164_MASK)

#define XBAR_NUM_OUT221_SEL_SEL166_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL166_SHIFT         (0U)
/*! SEL166 - SEL166 */
#define XBAR_NUM_OUT221_SEL_SEL166(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL166_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL166_MASK)

#define XBAR_NUM_OUT221_SEL_SEL168_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL168_SHIFT         (0U)
/*! SEL168 - SEL168 */
#define XBAR_NUM_OUT221_SEL_SEL168(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL168_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL168_MASK)

#define XBAR_NUM_OUT221_SEL_SEL170_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL170_SHIFT         (0U)
/*! SEL170 - SEL170 */
#define XBAR_NUM_OUT221_SEL_SEL170(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL170_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL170_MASK)

#define XBAR_NUM_OUT221_SEL_SEL172_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL172_SHIFT         (0U)
/*! SEL172 - SEL172 */
#define XBAR_NUM_OUT221_SEL_SEL172(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL172_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL172_MASK)

#define XBAR_NUM_OUT221_SEL_SEL174_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL174_SHIFT         (0U)
/*! SEL174 - SEL174 */
#define XBAR_NUM_OUT221_SEL_SEL174(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL174_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL174_MASK)

#define XBAR_NUM_OUT221_SEL_SEL176_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL176_SHIFT         (0U)
/*! SEL176 - SEL176 */
#define XBAR_NUM_OUT221_SEL_SEL176(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL176_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL176_MASK)

#define XBAR_NUM_OUT221_SEL_SEL178_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL178_SHIFT         (0U)
/*! SEL178 - SEL178 */
#define XBAR_NUM_OUT221_SEL_SEL178(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL178_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL178_MASK)

#define XBAR_NUM_OUT221_SEL_SEL180_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL180_SHIFT         (0U)
/*! SEL180 - SEL180 */
#define XBAR_NUM_OUT221_SEL_SEL180(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL180_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL180_MASK)

#define XBAR_NUM_OUT221_SEL_SEL182_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL182_SHIFT         (0U)
/*! SEL182 - SEL182 */
#define XBAR_NUM_OUT221_SEL_SEL182(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL182_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL182_MASK)

#define XBAR_NUM_OUT221_SEL_SEL184_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL184_SHIFT         (0U)
/*! SEL184 - SEL184 */
#define XBAR_NUM_OUT221_SEL_SEL184(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL184_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL184_MASK)

#define XBAR_NUM_OUT221_SEL_SEL186_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL186_SHIFT         (0U)
/*! SEL186 - SEL186 */
#define XBAR_NUM_OUT221_SEL_SEL186(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL186_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL186_MASK)

#define XBAR_NUM_OUT221_SEL_SEL188_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL188_SHIFT         (0U)
/*! SEL188 - SEL188 */
#define XBAR_NUM_OUT221_SEL_SEL188(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL188_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL188_MASK)

#define XBAR_NUM_OUT221_SEL_SEL190_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL190_SHIFT         (0U)
/*! SEL190 - SEL190 */
#define XBAR_NUM_OUT221_SEL_SEL190(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL190_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL190_MASK)

#define XBAR_NUM_OUT221_SEL_SEL192_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL192_SHIFT         (0U)
/*! SEL192 - SEL192 */
#define XBAR_NUM_OUT221_SEL_SEL192(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL192_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL192_MASK)

#define XBAR_NUM_OUT221_SEL_SEL194_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL194_SHIFT         (0U)
/*! SEL194 - SEL194 */
#define XBAR_NUM_OUT221_SEL_SEL194(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL194_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL194_MASK)

#define XBAR_NUM_OUT221_SEL_SEL196_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL196_SHIFT         (0U)
/*! SEL196 - SEL196 */
#define XBAR_NUM_OUT221_SEL_SEL196(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL196_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL196_MASK)

#define XBAR_NUM_OUT221_SEL_SEL198_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL198_SHIFT         (0U)
/*! SEL198 - SEL198 */
#define XBAR_NUM_OUT221_SEL_SEL198(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL198_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL198_MASK)

#define XBAR_NUM_OUT221_SEL_SEL200_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL200_SHIFT         (0U)
/*! SEL200 - SEL200 */
#define XBAR_NUM_OUT221_SEL_SEL200(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL200_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL200_MASK)

#define XBAR_NUM_OUT221_SEL_SEL202_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL202_SHIFT         (0U)
/*! SEL202 - SEL202 */
#define XBAR_NUM_OUT221_SEL_SEL202(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL202_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL202_MASK)

#define XBAR_NUM_OUT221_SEL_SEL204_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL204_SHIFT         (0U)
/*! SEL204 - SEL204 */
#define XBAR_NUM_OUT221_SEL_SEL204(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL204_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL204_MASK)

#define XBAR_NUM_OUT221_SEL_SEL206_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL206_SHIFT         (0U)
/*! SEL206 - SEL206 */
#define XBAR_NUM_OUT221_SEL_SEL206(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL206_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL206_MASK)

#define XBAR_NUM_OUT221_SEL_SEL208_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL208_SHIFT         (0U)
/*! SEL208 - SEL208 */
#define XBAR_NUM_OUT221_SEL_SEL208(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL208_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL208_MASK)

#define XBAR_NUM_OUT221_SEL_SEL210_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL210_SHIFT         (0U)
/*! SEL210 - SEL210 */
#define XBAR_NUM_OUT221_SEL_SEL210(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL210_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL210_MASK)

#define XBAR_NUM_OUT221_SEL_SEL212_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL212_SHIFT         (0U)
/*! SEL212 - SEL212 */
#define XBAR_NUM_OUT221_SEL_SEL212(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL212_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL212_MASK)

#define XBAR_NUM_OUT221_SEL_SEL214_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL214_SHIFT         (0U)
/*! SEL214 - SEL214 */
#define XBAR_NUM_OUT221_SEL_SEL214(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL214_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL214_MASK)

#define XBAR_NUM_OUT221_SEL_SEL216_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL216_SHIFT         (0U)
/*! SEL216 - SEL216 */
#define XBAR_NUM_OUT221_SEL_SEL216(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL216_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL216_MASK)

#define XBAR_NUM_OUT221_SEL_SEL218_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL218_SHIFT         (0U)
/*! SEL218 - SEL218 */
#define XBAR_NUM_OUT221_SEL_SEL218(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL218_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL218_MASK)

#define XBAR_NUM_OUT221_SEL_SEL220_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL220_SHIFT         (0U)
/*! SEL220 - SEL220 */
#define XBAR_NUM_OUT221_SEL_SEL220(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL220_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL220_MASK)

#define XBAR_NUM_OUT221_SEL_SEL1_MASK            (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL1_SHIFT           (8U)
/*! SEL1 - SEL1 */
#define XBAR_NUM_OUT221_SEL_SEL1(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL1_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL1_MASK)

#define XBAR_NUM_OUT221_SEL_SEL3_MASK            (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL3_SHIFT           (8U)
/*! SEL3 - SEL3 */
#define XBAR_NUM_OUT221_SEL_SEL3(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL3_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL3_MASK)

#define XBAR_NUM_OUT221_SEL_SEL5_MASK            (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL5_SHIFT           (8U)
/*! SEL5 - SEL5 */
#define XBAR_NUM_OUT221_SEL_SEL5(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL5_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL5_MASK)

#define XBAR_NUM_OUT221_SEL_SEL7_MASK            (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL7_SHIFT           (8U)
/*! SEL7 - SEL7 */
#define XBAR_NUM_OUT221_SEL_SEL7(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL7_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL7_MASK)

#define XBAR_NUM_OUT221_SEL_SEL9_MASK            (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL9_SHIFT           (8U)
/*! SEL9 - SEL9 */
#define XBAR_NUM_OUT221_SEL_SEL9(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL9_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL9_MASK)

#define XBAR_NUM_OUT221_SEL_SEL11_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL11_SHIFT          (8U)
/*! SEL11 - SEL11 */
#define XBAR_NUM_OUT221_SEL_SEL11(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL11_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL11_MASK)

#define XBAR_NUM_OUT221_SEL_SEL13_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL13_SHIFT          (8U)
/*! SEL13 - SEL13 */
#define XBAR_NUM_OUT221_SEL_SEL13(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL13_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL13_MASK)

#define XBAR_NUM_OUT221_SEL_SEL15_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL15_SHIFT          (8U)
/*! SEL15 - SEL15 */
#define XBAR_NUM_OUT221_SEL_SEL15(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL15_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL15_MASK)

#define XBAR_NUM_OUT221_SEL_SEL17_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL17_SHIFT          (8U)
/*! SEL17 - SEL17 */
#define XBAR_NUM_OUT221_SEL_SEL17(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL17_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL17_MASK)

#define XBAR_NUM_OUT221_SEL_SEL19_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL19_SHIFT          (8U)
/*! SEL19 - SEL19 */
#define XBAR_NUM_OUT221_SEL_SEL19(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL19_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL19_MASK)

#define XBAR_NUM_OUT221_SEL_SEL21_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL21_SHIFT          (8U)
/*! SEL21 - SEL21 */
#define XBAR_NUM_OUT221_SEL_SEL21(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL21_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL21_MASK)

#define XBAR_NUM_OUT221_SEL_SEL23_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL23_SHIFT          (8U)
/*! SEL23 - SEL23 */
#define XBAR_NUM_OUT221_SEL_SEL23(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL23_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL23_MASK)

#define XBAR_NUM_OUT221_SEL_SEL25_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL25_SHIFT          (8U)
/*! SEL25 - SEL25 */
#define XBAR_NUM_OUT221_SEL_SEL25(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL25_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL25_MASK)

#define XBAR_NUM_OUT221_SEL_SEL27_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL27_SHIFT          (8U)
/*! SEL27 - SEL27 */
#define XBAR_NUM_OUT221_SEL_SEL27(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL27_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL27_MASK)

#define XBAR_NUM_OUT221_SEL_SEL29_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL29_SHIFT          (8U)
/*! SEL29 - SEL29 */
#define XBAR_NUM_OUT221_SEL_SEL29(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL29_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL29_MASK)

#define XBAR_NUM_OUT221_SEL_SEL31_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL31_SHIFT          (8U)
/*! SEL31 - SEL31 */
#define XBAR_NUM_OUT221_SEL_SEL31(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL31_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL31_MASK)

#define XBAR_NUM_OUT221_SEL_SEL33_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL33_SHIFT          (8U)
/*! SEL33 - SEL33 */
#define XBAR_NUM_OUT221_SEL_SEL33(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL33_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL33_MASK)

#define XBAR_NUM_OUT221_SEL_SEL35_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL35_SHIFT          (8U)
/*! SEL35 - SEL35 */
#define XBAR_NUM_OUT221_SEL_SEL35(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL35_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL35_MASK)

#define XBAR_NUM_OUT221_SEL_SEL37_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL37_SHIFT          (8U)
/*! SEL37 - SEL37 */
#define XBAR_NUM_OUT221_SEL_SEL37(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL37_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL37_MASK)

#define XBAR_NUM_OUT221_SEL_SEL39_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL39_SHIFT          (8U)
/*! SEL39 - SEL39 */
#define XBAR_NUM_OUT221_SEL_SEL39(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL39_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL39_MASK)

#define XBAR_NUM_OUT221_SEL_SEL41_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL41_SHIFT          (8U)
/*! SEL41 - SEL41 */
#define XBAR_NUM_OUT221_SEL_SEL41(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL41_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL41_MASK)

#define XBAR_NUM_OUT221_SEL_SEL43_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL43_SHIFT          (8U)
/*! SEL43 - SEL43 */
#define XBAR_NUM_OUT221_SEL_SEL43(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL43_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL43_MASK)

#define XBAR_NUM_OUT221_SEL_SEL45_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL45_SHIFT          (8U)
/*! SEL45 - SEL45 */
#define XBAR_NUM_OUT221_SEL_SEL45(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL45_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL45_MASK)

#define XBAR_NUM_OUT221_SEL_SEL47_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL47_SHIFT          (8U)
/*! SEL47 - SEL47 */
#define XBAR_NUM_OUT221_SEL_SEL47(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL47_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL47_MASK)

#define XBAR_NUM_OUT221_SEL_SEL49_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL49_SHIFT          (8U)
/*! SEL49 - SEL49 */
#define XBAR_NUM_OUT221_SEL_SEL49(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL49_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL49_MASK)

#define XBAR_NUM_OUT221_SEL_SEL51_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL51_SHIFT          (8U)
/*! SEL51 - SEL51 */
#define XBAR_NUM_OUT221_SEL_SEL51(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL51_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL51_MASK)

#define XBAR_NUM_OUT221_SEL_SEL53_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL53_SHIFT          (8U)
/*! SEL53 - SEL53 */
#define XBAR_NUM_OUT221_SEL_SEL53(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL53_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL53_MASK)

#define XBAR_NUM_OUT221_SEL_SEL55_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL55_SHIFT          (8U)
/*! SEL55 - SEL55 */
#define XBAR_NUM_OUT221_SEL_SEL55(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL55_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL55_MASK)

#define XBAR_NUM_OUT221_SEL_SEL57_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL57_SHIFT          (8U)
/*! SEL57 - SEL57 */
#define XBAR_NUM_OUT221_SEL_SEL57(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL57_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL57_MASK)

#define XBAR_NUM_OUT221_SEL_SEL59_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL59_SHIFT          (8U)
/*! SEL59 - SEL59 */
#define XBAR_NUM_OUT221_SEL_SEL59(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL59_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL59_MASK)

#define XBAR_NUM_OUT221_SEL_SEL61_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL61_SHIFT          (8U)
/*! SEL61 - SEL61 */
#define XBAR_NUM_OUT221_SEL_SEL61(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL61_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL61_MASK)

#define XBAR_NUM_OUT221_SEL_SEL63_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL63_SHIFT          (8U)
/*! SEL63 - SEL63 */
#define XBAR_NUM_OUT221_SEL_SEL63(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL63_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL63_MASK)

#define XBAR_NUM_OUT221_SEL_SEL65_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL65_SHIFT          (8U)
/*! SEL65 - SEL65 */
#define XBAR_NUM_OUT221_SEL_SEL65(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL65_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL65_MASK)

#define XBAR_NUM_OUT221_SEL_SEL67_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL67_SHIFT          (8U)
/*! SEL67 - SEL67 */
#define XBAR_NUM_OUT221_SEL_SEL67(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL67_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL67_MASK)

#define XBAR_NUM_OUT221_SEL_SEL69_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL69_SHIFT          (8U)
/*! SEL69 - SEL69 */
#define XBAR_NUM_OUT221_SEL_SEL69(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL69_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL69_MASK)

#define XBAR_NUM_OUT221_SEL_SEL71_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL71_SHIFT          (8U)
/*! SEL71 - SEL71 */
#define XBAR_NUM_OUT221_SEL_SEL71(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL71_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL71_MASK)

#define XBAR_NUM_OUT221_SEL_SEL73_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL73_SHIFT          (8U)
/*! SEL73 - SEL73 */
#define XBAR_NUM_OUT221_SEL_SEL73(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL73_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL73_MASK)

#define XBAR_NUM_OUT221_SEL_SEL75_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL75_SHIFT          (8U)
/*! SEL75 - SEL75 */
#define XBAR_NUM_OUT221_SEL_SEL75(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL75_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL75_MASK)

#define XBAR_NUM_OUT221_SEL_SEL77_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL77_SHIFT          (8U)
/*! SEL77 - SEL77 */
#define XBAR_NUM_OUT221_SEL_SEL77(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL77_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL77_MASK)

#define XBAR_NUM_OUT221_SEL_SEL79_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL79_SHIFT          (8U)
/*! SEL79 - SEL79 */
#define XBAR_NUM_OUT221_SEL_SEL79(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL79_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL79_MASK)

#define XBAR_NUM_OUT221_SEL_SEL81_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL81_SHIFT          (8U)
/*! SEL81 - SEL81 */
#define XBAR_NUM_OUT221_SEL_SEL81(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL81_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL81_MASK)

#define XBAR_NUM_OUT221_SEL_SEL83_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL83_SHIFT          (8U)
/*! SEL83 - SEL83 */
#define XBAR_NUM_OUT221_SEL_SEL83(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL83_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL83_MASK)

#define XBAR_NUM_OUT221_SEL_SEL85_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL85_SHIFT          (8U)
/*! SEL85 - SEL85 */
#define XBAR_NUM_OUT221_SEL_SEL85(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL85_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL85_MASK)

#define XBAR_NUM_OUT221_SEL_SEL87_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL87_SHIFT          (8U)
/*! SEL87 - SEL87 */
#define XBAR_NUM_OUT221_SEL_SEL87(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL87_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL87_MASK)

#define XBAR_NUM_OUT221_SEL_SEL89_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL89_SHIFT          (8U)
/*! SEL89 - SEL89 */
#define XBAR_NUM_OUT221_SEL_SEL89(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL89_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL89_MASK)

#define XBAR_NUM_OUT221_SEL_SEL91_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL91_SHIFT          (8U)
/*! SEL91 - SEL91 */
#define XBAR_NUM_OUT221_SEL_SEL91(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL91_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL91_MASK)

#define XBAR_NUM_OUT221_SEL_SEL93_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL93_SHIFT          (8U)
/*! SEL93 - SEL93 */
#define XBAR_NUM_OUT221_SEL_SEL93(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL93_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL93_MASK)

#define XBAR_NUM_OUT221_SEL_SEL95_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL95_SHIFT          (8U)
/*! SEL95 - SEL95 */
#define XBAR_NUM_OUT221_SEL_SEL95(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL95_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL95_MASK)

#define XBAR_NUM_OUT221_SEL_SEL97_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL97_SHIFT          (8U)
/*! SEL97 - SEL97 */
#define XBAR_NUM_OUT221_SEL_SEL97(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL97_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL97_MASK)

#define XBAR_NUM_OUT221_SEL_SEL99_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL99_SHIFT          (8U)
/*! SEL99 - SEL99 */
#define XBAR_NUM_OUT221_SEL_SEL99(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL99_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL99_MASK)

#define XBAR_NUM_OUT221_SEL_SEL101_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL101_SHIFT         (8U)
/*! SEL101 - SEL101 */
#define XBAR_NUM_OUT221_SEL_SEL101(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL101_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL101_MASK)

#define XBAR_NUM_OUT221_SEL_SEL103_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL103_SHIFT         (8U)
/*! SEL103 - SEL103 */
#define XBAR_NUM_OUT221_SEL_SEL103(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL103_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL103_MASK)

#define XBAR_NUM_OUT221_SEL_SEL105_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL105_SHIFT         (8U)
/*! SEL105 - SEL105 */
#define XBAR_NUM_OUT221_SEL_SEL105(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL105_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL105_MASK)

#define XBAR_NUM_OUT221_SEL_SEL107_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL107_SHIFT         (8U)
/*! SEL107 - SEL107 */
#define XBAR_NUM_OUT221_SEL_SEL107(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL107_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL107_MASK)

#define XBAR_NUM_OUT221_SEL_SEL109_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL109_SHIFT         (8U)
/*! SEL109 - SEL109 */
#define XBAR_NUM_OUT221_SEL_SEL109(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL109_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL109_MASK)

#define XBAR_NUM_OUT221_SEL_SEL111_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL111_SHIFT         (8U)
/*! SEL111 - SEL111 */
#define XBAR_NUM_OUT221_SEL_SEL111(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL111_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL111_MASK)

#define XBAR_NUM_OUT221_SEL_SEL113_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL113_SHIFT         (8U)
/*! SEL113 - SEL113 */
#define XBAR_NUM_OUT221_SEL_SEL113(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL113_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL113_MASK)

#define XBAR_NUM_OUT221_SEL_SEL115_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL115_SHIFT         (8U)
/*! SEL115 - SEL115 */
#define XBAR_NUM_OUT221_SEL_SEL115(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL115_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL115_MASK)

#define XBAR_NUM_OUT221_SEL_SEL117_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL117_SHIFT         (8U)
/*! SEL117 - SEL117 */
#define XBAR_NUM_OUT221_SEL_SEL117(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL117_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL117_MASK)

#define XBAR_NUM_OUT221_SEL_SEL119_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL119_SHIFT         (8U)
/*! SEL119 - SEL119 */
#define XBAR_NUM_OUT221_SEL_SEL119(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL119_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL119_MASK)

#define XBAR_NUM_OUT221_SEL_SEL121_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL121_SHIFT         (8U)
/*! SEL121 - SEL121 */
#define XBAR_NUM_OUT221_SEL_SEL121(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL121_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL121_MASK)

#define XBAR_NUM_OUT221_SEL_SEL123_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL123_SHIFT         (8U)
/*! SEL123 - SEL123 */
#define XBAR_NUM_OUT221_SEL_SEL123(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL123_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL123_MASK)

#define XBAR_NUM_OUT221_SEL_SEL125_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL125_SHIFT         (8U)
/*! SEL125 - SEL125 */
#define XBAR_NUM_OUT221_SEL_SEL125(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL125_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL125_MASK)

#define XBAR_NUM_OUT221_SEL_SEL127_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL127_SHIFT         (8U)
/*! SEL127 - SEL127 */
#define XBAR_NUM_OUT221_SEL_SEL127(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL127_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL127_MASK)

#define XBAR_NUM_OUT221_SEL_SEL129_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL129_SHIFT         (8U)
/*! SEL129 - SEL129 */
#define XBAR_NUM_OUT221_SEL_SEL129(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL129_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL129_MASK)

#define XBAR_NUM_OUT221_SEL_SEL131_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL131_SHIFT         (8U)
/*! SEL131 - SEL131 */
#define XBAR_NUM_OUT221_SEL_SEL131(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL131_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL131_MASK)

#define XBAR_NUM_OUT221_SEL_SEL133_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL133_SHIFT         (8U)
/*! SEL133 - SEL133 */
#define XBAR_NUM_OUT221_SEL_SEL133(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL133_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL133_MASK)

#define XBAR_NUM_OUT221_SEL_SEL135_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL135_SHIFT         (8U)
/*! SEL135 - SEL135 */
#define XBAR_NUM_OUT221_SEL_SEL135(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL135_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL135_MASK)

#define XBAR_NUM_OUT221_SEL_SEL137_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL137_SHIFT         (8U)
/*! SEL137 - SEL137 */
#define XBAR_NUM_OUT221_SEL_SEL137(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL137_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL137_MASK)

#define XBAR_NUM_OUT221_SEL_SEL139_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL139_SHIFT         (8U)
/*! SEL139 - SEL139 */
#define XBAR_NUM_OUT221_SEL_SEL139(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL139_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL139_MASK)

#define XBAR_NUM_OUT221_SEL_SEL141_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL141_SHIFT         (8U)
/*! SEL141 - SEL141 */
#define XBAR_NUM_OUT221_SEL_SEL141(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL141_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL141_MASK)

#define XBAR_NUM_OUT221_SEL_SEL143_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL143_SHIFT         (8U)
/*! SEL143 - SEL143 */
#define XBAR_NUM_OUT221_SEL_SEL143(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL143_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL143_MASK)

#define XBAR_NUM_OUT221_SEL_SEL145_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL145_SHIFT         (8U)
/*! SEL145 - SEL145 */
#define XBAR_NUM_OUT221_SEL_SEL145(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL145_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL145_MASK)

#define XBAR_NUM_OUT221_SEL_SEL147_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL147_SHIFT         (8U)
/*! SEL147 - SEL147 */
#define XBAR_NUM_OUT221_SEL_SEL147(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL147_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL147_MASK)

#define XBAR_NUM_OUT221_SEL_SEL149_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL149_SHIFT         (8U)
/*! SEL149 - SEL149 */
#define XBAR_NUM_OUT221_SEL_SEL149(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL149_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL149_MASK)

#define XBAR_NUM_OUT221_SEL_SEL151_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL151_SHIFT         (8U)
/*! SEL151 - SEL151 */
#define XBAR_NUM_OUT221_SEL_SEL151(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL151_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL151_MASK)

#define XBAR_NUM_OUT221_SEL_SEL153_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL153_SHIFT         (8U)
/*! SEL153 - SEL153 */
#define XBAR_NUM_OUT221_SEL_SEL153(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL153_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL153_MASK)

#define XBAR_NUM_OUT221_SEL_SEL155_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL155_SHIFT         (8U)
/*! SEL155 - SEL155 */
#define XBAR_NUM_OUT221_SEL_SEL155(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL155_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL155_MASK)

#define XBAR_NUM_OUT221_SEL_SEL157_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL157_SHIFT         (8U)
/*! SEL157 - SEL157 */
#define XBAR_NUM_OUT221_SEL_SEL157(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL157_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL157_MASK)

#define XBAR_NUM_OUT221_SEL_SEL159_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL159_SHIFT         (8U)
/*! SEL159 - SEL159 */
#define XBAR_NUM_OUT221_SEL_SEL159(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL159_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL159_MASK)

#define XBAR_NUM_OUT221_SEL_SEL161_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL161_SHIFT         (8U)
/*! SEL161 - SEL161 */
#define XBAR_NUM_OUT221_SEL_SEL161(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL161_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL161_MASK)

#define XBAR_NUM_OUT221_SEL_SEL163_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL163_SHIFT         (8U)
/*! SEL163 - SEL163 */
#define XBAR_NUM_OUT221_SEL_SEL163(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL163_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL163_MASK)

#define XBAR_NUM_OUT221_SEL_SEL165_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL165_SHIFT         (8U)
/*! SEL165 - SEL165 */
#define XBAR_NUM_OUT221_SEL_SEL165(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL165_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL165_MASK)

#define XBAR_NUM_OUT221_SEL_SEL167_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL167_SHIFT         (8U)
/*! SEL167 - SEL167 */
#define XBAR_NUM_OUT221_SEL_SEL167(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL167_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL167_MASK)

#define XBAR_NUM_OUT221_SEL_SEL169_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL169_SHIFT         (8U)
/*! SEL169 - SEL169 */
#define XBAR_NUM_OUT221_SEL_SEL169(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL169_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL169_MASK)

#define XBAR_NUM_OUT221_SEL_SEL171_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL171_SHIFT         (8U)
/*! SEL171 - SEL171 */
#define XBAR_NUM_OUT221_SEL_SEL171(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL171_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL171_MASK)

#define XBAR_NUM_OUT221_SEL_SEL173_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL173_SHIFT         (8U)
/*! SEL173 - SEL173 */
#define XBAR_NUM_OUT221_SEL_SEL173(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL173_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL173_MASK)

#define XBAR_NUM_OUT221_SEL_SEL175_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL175_SHIFT         (8U)
/*! SEL175 - SEL175 */
#define XBAR_NUM_OUT221_SEL_SEL175(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL175_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL175_MASK)

#define XBAR_NUM_OUT221_SEL_SEL177_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL177_SHIFT         (8U)
/*! SEL177 - SEL177 */
#define XBAR_NUM_OUT221_SEL_SEL177(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL177_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL177_MASK)

#define XBAR_NUM_OUT221_SEL_SEL179_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL179_SHIFT         (8U)
/*! SEL179 - SEL179 */
#define XBAR_NUM_OUT221_SEL_SEL179(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL179_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL179_MASK)

#define XBAR_NUM_OUT221_SEL_SEL181_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL181_SHIFT         (8U)
/*! SEL181 - SEL181 */
#define XBAR_NUM_OUT221_SEL_SEL181(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL181_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL181_MASK)

#define XBAR_NUM_OUT221_SEL_SEL183_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL183_SHIFT         (8U)
/*! SEL183 - SEL183 */
#define XBAR_NUM_OUT221_SEL_SEL183(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL183_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL183_MASK)

#define XBAR_NUM_OUT221_SEL_SEL185_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL185_SHIFT         (8U)
/*! SEL185 - SEL185 */
#define XBAR_NUM_OUT221_SEL_SEL185(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL185_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL185_MASK)

#define XBAR_NUM_OUT221_SEL_SEL187_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL187_SHIFT         (8U)
/*! SEL187 - SEL187 */
#define XBAR_NUM_OUT221_SEL_SEL187(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL187_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL187_MASK)

#define XBAR_NUM_OUT221_SEL_SEL189_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL189_SHIFT         (8U)
/*! SEL189 - SEL189 */
#define XBAR_NUM_OUT221_SEL_SEL189(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL189_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL189_MASK)

#define XBAR_NUM_OUT221_SEL_SEL191_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL191_SHIFT         (8U)
/*! SEL191 - SEL191 */
#define XBAR_NUM_OUT221_SEL_SEL191(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL191_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL191_MASK)

#define XBAR_NUM_OUT221_SEL_SEL193_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL193_SHIFT         (8U)
/*! SEL193 - SEL193 */
#define XBAR_NUM_OUT221_SEL_SEL193(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL193_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL193_MASK)

#define XBAR_NUM_OUT221_SEL_SEL195_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL195_SHIFT         (8U)
/*! SEL195 - SEL195 */
#define XBAR_NUM_OUT221_SEL_SEL195(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL195_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL195_MASK)

#define XBAR_NUM_OUT221_SEL_SEL197_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL197_SHIFT         (8U)
/*! SEL197 - SEL197 */
#define XBAR_NUM_OUT221_SEL_SEL197(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL197_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL197_MASK)

#define XBAR_NUM_OUT221_SEL_SEL199_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL199_SHIFT         (8U)
/*! SEL199 - SEL199 */
#define XBAR_NUM_OUT221_SEL_SEL199(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL199_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL199_MASK)

#define XBAR_NUM_OUT221_SEL_SEL201_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL201_SHIFT         (8U)
/*! SEL201 - SEL201 */
#define XBAR_NUM_OUT221_SEL_SEL201(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL201_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL201_MASK)

#define XBAR_NUM_OUT221_SEL_SEL203_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL203_SHIFT         (8U)
/*! SEL203 - SEL203 */
#define XBAR_NUM_OUT221_SEL_SEL203(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL203_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL203_MASK)

#define XBAR_NUM_OUT221_SEL_SEL205_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL205_SHIFT         (8U)
/*! SEL205 - SEL205 */
#define XBAR_NUM_OUT221_SEL_SEL205(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL205_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL205_MASK)

#define XBAR_NUM_OUT221_SEL_SEL207_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL207_SHIFT         (8U)
/*! SEL207 - SEL207 */
#define XBAR_NUM_OUT221_SEL_SEL207(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL207_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL207_MASK)

#define XBAR_NUM_OUT221_SEL_SEL209_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL209_SHIFT         (8U)
/*! SEL209 - SEL209 */
#define XBAR_NUM_OUT221_SEL_SEL209(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL209_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL209_MASK)

#define XBAR_NUM_OUT221_SEL_SEL211_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL211_SHIFT         (8U)
/*! SEL211 - SEL211 */
#define XBAR_NUM_OUT221_SEL_SEL211(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL211_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL211_MASK)

#define XBAR_NUM_OUT221_SEL_SEL213_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL213_SHIFT         (8U)
/*! SEL213 - SEL213 */
#define XBAR_NUM_OUT221_SEL_SEL213(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL213_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL213_MASK)

#define XBAR_NUM_OUT221_SEL_SEL215_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL215_SHIFT         (8U)
/*! SEL215 - SEL215 */
#define XBAR_NUM_OUT221_SEL_SEL215(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL215_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL215_MASK)

#define XBAR_NUM_OUT221_SEL_SEL217_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL217_SHIFT         (8U)
/*! SEL217 - SEL217 */
#define XBAR_NUM_OUT221_SEL_SEL217(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL217_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL217_MASK)

#define XBAR_NUM_OUT221_SEL_SEL219_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL219_SHIFT         (8U)
/*! SEL219 - SEL219 */
#define XBAR_NUM_OUT221_SEL_SEL219(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL219_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL219_MASK)
/*! @} */

/*! @name CTRL - Crossbar Control Register */
/*! @{ */

#define XBAR_NUM_OUT221_CTRL_DEN0_MASK           (0x1U)
#define XBAR_NUM_OUT221_CTRL_DEN0_SHIFT          (0U)
/*! DEN0 - DMA Enable for XBAR_OUT0
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_NUM_OUT221_CTRL_DEN0(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_DEN0_SHIFT)) & XBAR_NUM_OUT221_CTRL_DEN0_MASK)

#define XBAR_NUM_OUT221_CTRL_DEN2_MASK           (0x1U)
#define XBAR_NUM_OUT221_CTRL_DEN2_SHIFT          (0U)
/*! DEN2 - DMA Enable for XBAR_OUT2
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_NUM_OUT221_CTRL_DEN2(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_DEN2_SHIFT)) & XBAR_NUM_OUT221_CTRL_DEN2_MASK)

#define XBAR_NUM_OUT221_CTRL_IEN0_MASK           (0x2U)
#define XBAR_NUM_OUT221_CTRL_IEN0_SHIFT          (1U)
/*! IEN0 - Interrupt Enable for XBAR_OUT0
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_NUM_OUT221_CTRL_IEN0(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_IEN0_SHIFT)) & XBAR_NUM_OUT221_CTRL_IEN0_MASK)

#define XBAR_NUM_OUT221_CTRL_IEN2_MASK           (0x2U)
#define XBAR_NUM_OUT221_CTRL_IEN2_SHIFT          (1U)
/*! IEN2 - Interrupt Enable for XBAR_OUT2
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_NUM_OUT221_CTRL_IEN2(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_IEN2_SHIFT)) & XBAR_NUM_OUT221_CTRL_IEN2_MASK)

#define XBAR_NUM_OUT221_CTRL_EDGE0_MASK          (0xCU)
#define XBAR_NUM_OUT221_CTRL_EDGE0_SHIFT         (2U)
/*! EDGE0 - Active edge for edge detection on XBAR_OUT0
 *  0b00..STS0 never asserts
 *  0b01..STS0 asserts on rising edges of XBAR_OUT0
 *  0b10..STS0 asserts on falling edges of XBAR_OUT0
 *  0b11..STS0 asserts on rising and falling edges of XBAR_OUT0
 */
#define XBAR_NUM_OUT221_CTRL_EDGE0(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_EDGE0_SHIFT)) & XBAR_NUM_OUT221_CTRL_EDGE0_MASK)

#define XBAR_NUM_OUT221_CTRL_EDGE2_MASK          (0xCU)
#define XBAR_NUM_OUT221_CTRL_EDGE2_SHIFT         (2U)
/*! EDGE2 - Active edge for edge detection on XBAR_OUT2
 *  0b00..STS2 never asserts
 *  0b01..STS2 asserts on rising edges of XBAR_OUT2
 *  0b10..STS2 asserts on falling edges of XBAR_OUT2
 *  0b11..STS2 asserts on rising and falling edges of XBAR_OUT2
 */
#define XBAR_NUM_OUT221_CTRL_EDGE2(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_EDGE2_SHIFT)) & XBAR_NUM_OUT221_CTRL_EDGE2_MASK)

#define XBAR_NUM_OUT221_CTRL_STS0_MASK           (0x10U)
#define XBAR_NUM_OUT221_CTRL_STS0_SHIFT          (4U)
/*! STS0 - Edge detection status for XBAR_OUT0
 *  0b0..Active edge not yet detected on XBAR_OUT0
 *  0b1..Active edge detected on XBAR_OUT0
 */
#define XBAR_NUM_OUT221_CTRL_STS0(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_STS0_SHIFT)) & XBAR_NUM_OUT221_CTRL_STS0_MASK)

#define XBAR_NUM_OUT221_CTRL_STS2_MASK           (0x10U)
#define XBAR_NUM_OUT221_CTRL_STS2_SHIFT          (4U)
/*! STS2 - Edge detection status for XBAR_OUT2
 *  0b0..Active edge not yet detected on XBAR_OUT2
 *  0b1..Active edge detected on XBAR_OUT2
 */
#define XBAR_NUM_OUT221_CTRL_STS2(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_STS2_SHIFT)) & XBAR_NUM_OUT221_CTRL_STS2_MASK)

#define XBAR_NUM_OUT221_CTRL_DEN1_MASK           (0x100U)
#define XBAR_NUM_OUT221_CTRL_DEN1_SHIFT          (8U)
/*! DEN1 - DMA Enable for XBAR_OUT1
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_NUM_OUT221_CTRL_DEN1(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_DEN1_SHIFT)) & XBAR_NUM_OUT221_CTRL_DEN1_MASK)

#define XBAR_NUM_OUT221_CTRL_DEN3_MASK           (0x100U)
#define XBAR_NUM_OUT221_CTRL_DEN3_SHIFT          (8U)
/*! DEN3 - DMA Enable for XBAR_OUT3
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_NUM_OUT221_CTRL_DEN3(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_DEN3_SHIFT)) & XBAR_NUM_OUT221_CTRL_DEN3_MASK)

#define XBAR_NUM_OUT221_CTRL_IEN1_MASK           (0x200U)
#define XBAR_NUM_OUT221_CTRL_IEN1_SHIFT          (9U)
/*! IEN1 - Interrupt Enable for XBAR_OUT1
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_NUM_OUT221_CTRL_IEN1(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_IEN1_SHIFT)) & XBAR_NUM_OUT221_CTRL_IEN1_MASK)

#define XBAR_NUM_OUT221_CTRL_IEN3_MASK           (0x200U)
#define XBAR_NUM_OUT221_CTRL_IEN3_SHIFT          (9U)
/*! IEN3 - Interrupt Enable for XBAR_OUT3
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_NUM_OUT221_CTRL_IEN3(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_IEN3_SHIFT)) & XBAR_NUM_OUT221_CTRL_IEN3_MASK)

#define XBAR_NUM_OUT221_CTRL_EDGE1_MASK          (0xC00U)
#define XBAR_NUM_OUT221_CTRL_EDGE1_SHIFT         (10U)
/*! EDGE1 - Active edge for edge detection on XBAR_OUT1
 *  0b00..STS1 never asserts
 *  0b01..STS1 asserts on rising edges of XBAR_OUT1
 *  0b10..STS1 asserts on falling edges of XBAR_OUT1
 *  0b11..STS1 asserts on rising and falling edges of XBAR_OUT1
 */
#define XBAR_NUM_OUT221_CTRL_EDGE1(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_EDGE1_SHIFT)) & XBAR_NUM_OUT221_CTRL_EDGE1_MASK)

#define XBAR_NUM_OUT221_CTRL_EDGE3_MASK          (0xC00U)
#define XBAR_NUM_OUT221_CTRL_EDGE3_SHIFT         (10U)
/*! EDGE3 - Active edge for edge detection on XBAR_OUT3
 *  0b00..STS3 never asserts
 *  0b01..STS3 asserts on rising edges of XBAR_OUT3
 *  0b10..STS3 asserts on falling edges of XBAR_OUT3
 *  0b11..STS3 asserts on rising and falling edges of XBAR_OUT3
 */
#define XBAR_NUM_OUT221_CTRL_EDGE3(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_EDGE3_SHIFT)) & XBAR_NUM_OUT221_CTRL_EDGE3_MASK)

#define XBAR_NUM_OUT221_CTRL_STS1_MASK           (0x1000U)
#define XBAR_NUM_OUT221_CTRL_STS1_SHIFT          (12U)
/*! STS1 - Edge detection status for XBAR_OUT1
 *  0b0..Active edge not yet detected on XBAR_OUT1
 *  0b1..Active edge detected on XBAR_OUT1
 */
#define XBAR_NUM_OUT221_CTRL_STS1(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_STS1_SHIFT)) & XBAR_NUM_OUT221_CTRL_STS1_MASK)

#define XBAR_NUM_OUT221_CTRL_STS3_MASK           (0x1000U)
#define XBAR_NUM_OUT221_CTRL_STS3_SHIFT          (12U)
/*! STS3 - Edge detection status for XBAR_OUT3
 *  0b0..Active edge not yet detected on XBAR_OUT3
 *  0b1..Active edge detected on XBAR_OUT3
 */
#define XBAR_NUM_OUT221_CTRL_STS3(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_STS3_SHIFT)) & XBAR_NUM_OUT221_CTRL_STS3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XBAR_NUM_OUT221_Register_Masks */


/*!
 * @}
 */ /* end of group XBAR_NUM_OUT221_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
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


#endif  /* XBAR_NUM_OUT221_H_ */

