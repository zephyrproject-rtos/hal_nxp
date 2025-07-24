/*
** ###################################################################
**     Processors:          MIMXRT1021CAF4A
**                          MIMXRT1021CAF4B
**                          MIMXRT1021CAG4A
**                          MIMXRT1021CAG4B
**                          MIMXRT1021DAF5A
**                          MIMXRT1021DAF5B
**                          MIMXRT1021DAG5A
**                          MIMXRT1021DAG5B
**                          MIMXRT1024CAG4A
**                          MIMXRT1024CAG4B
**                          MIMXRT1024DAG5A
**                          MIMXRT1024DAG5B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XBARB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-11-06)
**         Initial version.
**     - rev. 1.0 (2018-11-27)
**         Update header files to align with IMXRT1020RM Rev.1.
**     - rev. 1.1 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1020RM Rev.2.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_XBARB.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XBARB
 *
 * CMSIS Peripheral Access Layer for XBARB
 */

#if !defined(PERI_XBARB_H_)
#define PERI_XBARB_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1021CAF4A) || defined(CPU_MIMXRT1021CAF4B) || defined(CPU_MIMXRT1021CAG4A) || defined(CPU_MIMXRT1021CAG4B) || defined(CPU_MIMXRT1021DAF5A) || defined(CPU_MIMXRT1021DAF5B) || defined(CPU_MIMXRT1021DAG5A) || defined(CPU_MIMXRT1021DAG5B))
#include "MIMXRT1021_COMMON.h"
#elif (defined(CPU_MIMXRT1024CAG4A) || defined(CPU_MIMXRT1024CAG4B) || defined(CPU_MIMXRT1024DAG5A) || defined(CPU_MIMXRT1024DAG5B))
#include "MIMXRT1024_COMMON.h"
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
    kXBARA1_InputLogicLow           = 0|0x100U,    /**< LOGIC_LOW output assigned to XBARA_IN0 input. */
    kXBARA1_InputLogicHigh          = 1|0x100U,    /**< LOGIC_HIGH output assigned to XBARA_IN1 input. */
    kXBARA1_InputRESERVED2          = 2|0x100U,    /**< XBARA_IN2 input is reserved. */
    kXBARA1_InputRESERVED3          = 3|0x100U,    /**< XBARA_IN3 input is reserved. */
    kXBARA1_InputIomuxXbarInout04   = 4|0x100U,    /**< IOMUX_XBAR_INOUT04 output assigned to XBARA_IN4 input. */
    kXBARA1_InputIomuxXbarInout05   = 5|0x100U,    /**< IOMUX_XBAR_INOUT05 output assigned to XBARA_IN5 input. */
    kXBARA1_InputIomuxXbarInout06   = 6|0x100U,    /**< IOMUX_XBAR_INOUT06 output assigned to XBARA_IN6 input. */
    kXBARA1_InputIomuxXbarInout07   = 7|0x100U,    /**< IOMUX_XBAR_INOUT07 output assigned to XBARA_IN7 input. */
    kXBARA1_InputIomuxXbarInout08   = 8|0x100U,    /**< IOMUX_XBAR_INOUT08 output assigned to XBARA_IN8 input. */
    kXBARA1_InputIomuxXbarInout09   = 9|0x100U,    /**< IOMUX_XBAR_INOUT09 output assigned to XBARA_IN9 input. */
    kXBARA1_InputIomuxXbarInout10   = 10|0x100U,   /**< IOMUX_XBAR_INOUT10 output assigned to XBARA_IN10 input. */
    kXBARA1_InputIomuxXbarInout11   = 11|0x100U,   /**< IOMUX_XBAR_INOUT11 output assigned to XBARA_IN11 input. */
    kXBARA1_InputIomuxXbarInout12   = 12|0x100U,   /**< IOMUX_XBAR_INOUT12 output assigned to XBARA_IN12 input. */
    kXBARA1_InputIomuxXbarInout13   = 13|0x100U,   /**< IOMUX_XBAR_INOUT13 output assigned to XBARA_IN13 input. */
    kXBARA1_InputIomuxXbarInout14   = 14|0x100U,   /**< IOMUX_XBAR_INOUT14 output assigned to XBARA_IN14 input. */
    kXBARA1_InputIomuxXbarInout15   = 15|0x100U,   /**< IOMUX_XBAR_INOUT15 output assigned to XBARA_IN15 input. */
    kXBARA1_InputIomuxXbarInout16   = 16|0x100U,   /**< IOMUX_XBAR_INOUT16 output assigned to XBARA_IN16 input. */
    kXBARA1_InputIomuxXbarInout17   = 17|0x100U,   /**< IOMUX_XBAR_INOUT17 output assigned to XBARA_IN17 input. */
    kXBARA1_InputIomuxXbarInout18   = 18|0x100U,   /**< IOMUX_XBAR_INOUT18 output assigned to XBARA_IN18 input. */
    kXBARA1_InputIomuxXbarInout19   = 19|0x100U,   /**< IOMUX_XBAR_INOUT19 output assigned to XBARA_IN19 input. */
    kXBARA1_InputRESERVED20         = 20|0x100U,   /**< XBARA_IN20 input is reserved. */
    kXBARA1_InputRESERVED21         = 21|0x100U,   /**< XBARA_IN21 input is reserved. */
    kXBARA1_InputRESERVED22         = 22|0x100U,   /**< XBARA_IN22 input is reserved. */
    kXBARA1_InputRESERVED23         = 23|0x100U,   /**< XBARA_IN23 input is reserved. */
    kXBARA1_InputRESERVED24         = 24|0x100U,   /**< XBARA_IN24 input is reserved. */
    kXBARA1_InputRESERVED25         = 25|0x100U,   /**< XBARA_IN25 input is reserved. */
    kXBARA1_InputAcmp1Out           = 26|0x100U,   /**< ACMP1_OUT output assigned to XBARA_IN26 input. */
    kXBARA1_InputAcmp2Out           = 27|0x100U,   /**< ACMP2_OUT output assigned to XBARA_IN27 input. */
    kXBARA1_InputAcmp3Out           = 28|0x100U,   /**< ACMP3_OUT output assigned to XBARA_IN28 input. */
    kXBARA1_InputAcmp4Out           = 29|0x100U,   /**< ACMP4_OUT output assigned to XBARA_IN29 input. */
    kXBARA1_InputRESERVED30         = 30|0x100U,   /**< XBARA_IN30 input is reserved. */
    kXBARA1_InputRESERVED31         = 31|0x100U,   /**< XBARA_IN31 input is reserved. */
    kXBARA1_InputQtimer1Tmr0        = 32|0x100U,   /**< QTIMER1_TMR0 output assigned to XBARA_IN32 input. */
    kXBARA1_InputQtimer1Tmr1        = 33|0x100U,   /**< QTIMER1_TMR1 output assigned to XBARA_IN33 input. */
    kXBARA1_InputQtimer1Tmr2        = 34|0x100U,   /**< QTIMER1_TMR2 output assigned to XBARA_IN34 input. */
    kXBARA1_InputQtimer1Tmr3        = 35|0x100U,   /**< QTIMER1_TMR3 output assigned to XBARA_IN35 input. */
    kXBARA1_InputQtimer2Tmr0        = 36|0x100U,   /**< QTIMER2_TMR0 output assigned to XBARA_IN36 input. */
    kXBARA1_InputQtimer2Tmr1        = 37|0x100U,   /**< QTIMER2_TMR1 output assigned to XBARA_IN37 input. */
    kXBARA1_InputQtimer2Tmr2        = 38|0x100U,   /**< QTIMER2_TMR2 output assigned to XBARA_IN38 input. */
    kXBARA1_InputQtimer2Tmr3        = 39|0x100U,   /**< QTIMER2_TMR3 output assigned to XBARA_IN39 input. */
    kXBARA1_InputFlexpwm1Pwm1OutTrig01 = 40|0x100U, /**< FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBARA_IN40 input. */
    kXBARA1_InputFlexpwm1Pwm2OutTrig01 = 41|0x100U, /**< FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBARA_IN41 input. */
    kXBARA1_InputFlexpwm1Pwm3OutTrig01 = 42|0x100U, /**< FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBARA_IN42 input. */
    kXBARA1_InputFlexpwm1Pwm4OutTrig01 = 43|0x100U, /**< FLEXPWM1_PWM4_OUT_TRIG0_1 output assigned to XBARA_IN43 input. */
    kXBARA1_InputFlexpwm2Pwm1OutTrig01 = 44|0x100U, /**< FLEXPWM2_PWM1_OUT_TRIG0_1 output assigned to XBARA_IN44 input. */
    kXBARA1_InputFlexpwm2Pwm2OutTrig01 = 45|0x100U, /**< FLEXPWM2_PWM2_OUT_TRIG0_1 output assigned to XBARA_IN45 input. */
    kXBARA1_InputFlexpwm2Pwm3OutTrig01 = 46|0x100U, /**< FLEXPWM2_PWM3_OUT_TRIG0_1 output assigned to XBARA_IN46 input. */
    kXBARA1_InputFlexpwm2Pwm4OutTrig01 = 47|0x100U, /**< FLEXPWM2_PWM4_OUT_TRIG0_1 output assigned to XBARA_IN47 input. */
    kXBARA1_InputRESERVED48         = 48|0x100U,   /**< XBARA_IN48 input is reserved. */
    kXBARA1_InputRESERVED49         = 49|0x100U,   /**< XBARA_IN49 input is reserved. */
    kXBARA1_InputRESERVED50         = 50|0x100U,   /**< XBARA_IN50 input is reserved. */
    kXBARA1_InputRESERVED51         = 51|0x100U,   /**< XBARA_IN51 input is reserved. */
    kXBARA1_InputRESERVED52         = 52|0x100U,   /**< XBARA_IN52 input is reserved. */
    kXBARA1_InputRESERVED53         = 53|0x100U,   /**< XBARA_IN53 input is reserved. */
    kXBARA1_InputRESERVED54         = 54|0x100U,   /**< XBARA_IN54 input is reserved. */
    kXBARA1_InputRESERVED55         = 55|0x100U,   /**< XBARA_IN55 input is reserved. */
    kXBARA1_InputPitTrigger0        = 56|0x100U,   /**< PIT_TRIGGER0 output assigned to XBARA_IN56 input. */
    kXBARA1_InputPitTrigger1        = 57|0x100U,   /**< PIT_TRIGGER1 output assigned to XBARA_IN57 input. */
    kXBARA1_InputPitTrigger2        = 58|0x100U,   /**< PIT_TRIGGER2 output assigned to XBARA_IN58 input. */
    kXBARA1_InputPitTrigger3        = 59|0x100U,   /**< PIT_TRIGGER3 output assigned to XBARA_IN59 input. */
    kXBARA1_InputEnc1PosMatch       = 60|0x100U,   /**< ENC1_POS_MATCH output assigned to XBARA_IN60 input. */
    kXBARA1_InputEnc2PosMatch       = 61|0x100U,   /**< ENC2_POS_MATCH output assigned to XBARA_IN61 input. */
    kXBARA1_InputRESERVED62         = 62|0x100U,   /**< XBARA_IN62 input is reserved. */
    kXBARA1_InputRESERVED63         = 63|0x100U,   /**< XBARA_IN63 input is reserved. */
    kXBARA1_InputDmaDone0           = 64|0x100U,   /**< DMA_DONE0 output assigned to XBARA_IN64 input. */
    kXBARA1_InputDmaDone1           = 65|0x100U,   /**< DMA_DONE1 output assigned to XBARA_IN65 input. */
    kXBARA1_InputDmaDone2           = 66|0x100U,   /**< DMA_DONE2 output assigned to XBARA_IN66 input. */
    kXBARA1_InputDmaDone3           = 67|0x100U,   /**< DMA_DONE3 output assigned to XBARA_IN67 input. */
    kXBARA1_InputDmaDone4           = 68|0x100U,   /**< DMA_DONE4 output assigned to XBARA_IN68 input. */
    kXBARA1_InputDmaDone5           = 69|0x100U,   /**< DMA_DONE5 output assigned to XBARA_IN69 input. */
    kXBARA1_InputDmaDone6           = 70|0x100U,   /**< DMA_DONE6 output assigned to XBARA_IN70 input. */
    kXBARA1_InputDmaDone7           = 71|0x100U,   /**< DMA_DONE7 output assigned to XBARA_IN71 input. */
    kXBARA1_InputAoi1Out0           = 72|0x100U,   /**< AOI1_OUT0 output assigned to XBARA_IN72 input. */
    kXBARA1_InputAoi1Out1           = 73|0x100U,   /**< AOI1_OUT1 output assigned to XBARA_IN73 input. */
    kXBARA1_InputAoi1Out2           = 74|0x100U,   /**< AOI1_OUT2 output assigned to XBARA_IN74 input. */
    kXBARA1_InputAoi1Out3           = 75|0x100U,   /**< AOI1_OUT3 output assigned to XBARA_IN75 input. */
    kXBARA1_InputRESERVED76         = 76|0x100U,   /**< XBARA_IN76 input is reserved. */
    kXBARA1_InputRESERVED77         = 77|0x100U,   /**< XBARA_IN77 input is reserved. */
    kXBARA1_InputRESERVED78         = 78|0x100U,   /**< XBARA_IN78 input is reserved. */
    kXBARA1_InputRESERVED79         = 79|0x100U,   /**< XBARA_IN79 input is reserved. */
    kXBARA1_InputAdcEtc0Coco0       = 80|0x100U,   /**< ADC_ETC0_COCO0 output assigned to XBARA_IN80 input. */
    kXBARA1_InputAdcEtc0Coco1       = 81|0x100U,   /**< ADC_ETC0_COCO1 output assigned to XBARA_IN81 input. */
    kXBARA1_InputAdcEtc0Coco2       = 82|0x100U,   /**< ADC_ETC0_COCO2 output assigned to XBARA_IN82 input. */
    kXBARA1_InputAdcEtc0Coco3       = 83|0x100U,   /**< ADC_ETC0_COCO3 output assigned to XBARA_IN83 input. */
    kXBARA1_InputAdcEtc1Coco0       = 84|0x100U,   /**< ADC_ETC1_COCO0 output assigned to XBARA_IN84 input. */
    kXBARA1_InputAdcEtc1Coco1       = 85|0x100U,   /**< ADC_ETC1_COCO1 output assigned to XBARA_IN85 input. */
    kXBARA1_InputAdcEtc1Coco2       = 86|0x100U,   /**< ADC_ETC1_COCO2 output assigned to XBARA_IN86 input. */
    kXBARA1_InputAdcEtc1Coco3       = 87|0x100U,   /**< ADC_ETC1_COCO3 output assigned to XBARA_IN87 input. */
    kXBARB2_InputLogicLow           = 0|0x200U,    /**< LOGIC_LOW output assigned to XBARB_IN0 input. */
    kXBARB2_InputLogicHigh          = 1|0x200U,    /**< LOGIC_HIGH output assigned to XBARB_IN1 input. */
    kXBARB2_InputRESERVED2          = 2|0x200U,    /**< XBARB_IN2 input is reserved. */
    kXBARB2_InputRESERVED3          = 3|0x200U,    /**< XBARB_IN3 input is reserved. */
    kXBARB2_InputRESERVED4          = 4|0x200U,    /**< XBARB_IN4 input is reserved. */
    kXBARB2_InputRESERVED5          = 5|0x200U,    /**< XBARB_IN5 input is reserved. */
    kXBARB2_InputAcmp1Out           = 6|0x200U,    /**< ACMP1_OUT output assigned to XBARB_IN6 input. */
    kXBARB2_InputAcmp2Out           = 7|0x200U,    /**< ACMP2_OUT output assigned to XBARB_IN7 input. */
    kXBARB2_InputAcmp3Out           = 8|0x200U,    /**< ACMP3_OUT output assigned to XBARB_IN8 input. */
    kXBARB2_InputAcmp4Out           = 9|0x200U,    /**< ACMP4_OUT output assigned to XBARB_IN9 input. */
    kXBARB2_InputRESERVED10         = 10|0x200U,   /**< XBARB_IN10 input is reserved. */
    kXBARB2_InputRESERVED11         = 11|0x200U,   /**< XBARB_IN11 input is reserved. */
    kXBARB2_InputQtimer1Tmr0        = 12|0x200U,   /**< QTIMER1_TMR0 output assigned to XBARB_IN12 input. */
    kXBARB2_InputQtimer1Tmr1        = 13|0x200U,   /**< QTIMER1_TMR1 output assigned to XBARB_IN13 input. */
    kXBARB2_InputQtimer1Tmr2        = 14|0x200U,   /**< QTIMER1_TMR2 output assigned to XBARB_IN14 input. */
    kXBARB2_InputQtimer1Tmr3        = 15|0x200U,   /**< QTIMER1_TMR3 output assigned to XBARB_IN15 input. */
    kXBARB2_InputQtimer2Tmr0        = 16|0x200U,   /**< QTIMER2_TMR0 output assigned to XBARB_IN16 input. */
    kXBARB2_InputQtimer2Tmr1        = 17|0x200U,   /**< QTIMER2_TMR1 output assigned to XBARB_IN17 input. */
    kXBARB2_InputQtimer2Tmr2        = 18|0x200U,   /**< QTIMER2_TMR2 output assigned to XBARB_IN18 input. */
    kXBARB2_InputQtimer2Tmr3        = 19|0x200U,   /**< QTIMER2_TMR3 output assigned to XBARB_IN19 input. */
    kXBARB2_InputFlexpwm1Pwm1OutTrig01 = 20|0x200U, /**< FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBARB_IN20 input. */
    kXBARB2_InputFlexpwm1Pwm2OutTrig01 = 21|0x200U, /**< FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBARB_IN21 input. */
    kXBARB2_InputFlexpwm1Pwm3OutTrig01 = 22|0x200U, /**< FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBARB_IN22 input. */
    kXBARB2_InputFlexpwm1Pwm4OutTrig01 = 23|0x200U, /**< FLEXPWM1_PWM4_OUT_TRIG0_1 output assigned to XBARB_IN23 input. */
    kXBARB2_InputFlexpwm2Pwm1OutTrig01 = 24|0x200U, /**< FLEXPWM2_PWM1_OUT_TRIG0_1 output assigned to XBARB_IN24 input. */
    kXBARB2_InputFlexpwm2Pwm2OutTrig01 = 25|0x200U, /**< FLEXPWM2_PWM2_OUT_TRIG0_1 output assigned to XBARB_IN25 input. */
    kXBARB2_InputFlexpwm2Pwm3OutTrig01 = 26|0x200U, /**< FLEXPWM2_PWM3_OUT_TRIG0_1 output assigned to XBARB_IN26 input. */
    kXBARB2_InputFlexpwm2Pwm4OutTrig01 = 27|0x200U, /**< FLEXPWM2_PWM4_OUT_TRIG0_1 output assigned to XBARB_IN27 input. */
    kXBARB2_InputRESERVED28         = 28|0x200U,   /**< XBARB_IN28 input is reserved. */
    kXBARB2_InputRESERVED29         = 29|0x200U,   /**< XBARB_IN29 input is reserved. */
    kXBARB2_InputRESERVED30         = 30|0x200U,   /**< XBARB_IN30 input is reserved. */
    kXBARB2_InputRESERVED31         = 31|0x200U,   /**< XBARB_IN31 input is reserved. */
    kXBARB2_InputRESERVED32         = 32|0x200U,   /**< XBARB_IN32 input is reserved. */
    kXBARB2_InputRESERVED33         = 33|0x200U,   /**< XBARB_IN33 input is reserved. */
    kXBARB2_InputRESERVED34         = 34|0x200U,   /**< XBARB_IN34 input is reserved. */
    kXBARB2_InputRESERVED35         = 35|0x200U,   /**< XBARB_IN35 input is reserved. */
    kXBARB2_InputPitTrigger0        = 36|0x200U,   /**< PIT_TRIGGER0 output assigned to XBARB_IN36 input. */
    kXBARB2_InputPitTrigger1        = 37|0x200U,   /**< PIT_TRIGGER1 output assigned to XBARB_IN37 input. */
    kXBARB2_InputAdcEtc0Coco0       = 38|0x200U,   /**< ADC_ETC0_COCO0 output assigned to XBARB_IN38 input. */
    kXBARB2_InputAdcEtc0Coco1       = 39|0x200U,   /**< ADC_ETC0_COCO1 output assigned to XBARB_IN39 input. */
    kXBARB2_InputAdcEtc0Coco2       = 40|0x200U,   /**< ADC_ETC0_COCO2 output assigned to XBARB_IN40 input. */
    kXBARB2_InputAdcEtc0Coco3       = 41|0x200U,   /**< ADC_ETC0_COCO3 output assigned to XBARB_IN41 input. */
    kXBARB2_InputAdcEtc1Coco0       = 42|0x200U,   /**< ADC_ETC1_COCO0 output assigned to XBARB_IN42 input. */
    kXBARB2_InputAdcEtc1Coco1       = 43|0x200U,   /**< ADC_ETC1_COCO1 output assigned to XBARB_IN43 input. */
    kXBARB2_InputAdcEtc1Coco2       = 44|0x200U,   /**< ADC_ETC1_COCO2 output assigned to XBARB_IN44 input. */
    kXBARB2_InputAdcEtc1Coco3       = 45|0x200U,   /**< ADC_ETC1_COCO3 output assigned to XBARB_IN45 input. */
    kXBARB2_InputEnc1PosMatch       = 46|0x200U,   /**< ENC1_POS_MATCH output assigned to XBARB_IN46 input. */
    kXBARB2_InputEnc2PosMatch       = 47|0x200U,   /**< ENC2_POS_MATCH output assigned to XBARB_IN47 input. */
    kXBARB2_InputRESERVED48         = 48|0x200U,   /**< XBARB_IN48 input is reserved. */
    kXBARB2_InputRESERVED49         = 49|0x200U,   /**< XBARB_IN49 input is reserved. */
    kXBARB2_InputDmaDone0           = 50|0x200U,   /**< DMA_DONE0 output assigned to XBARB_IN50 input. */
    kXBARB2_InputDmaDone1           = 51|0x200U,   /**< DMA_DONE1 output assigned to XBARB_IN51 input. */
    kXBARB2_InputDmaDone2           = 52|0x200U,   /**< DMA_DONE2 output assigned to XBARB_IN52 input. */
    kXBARB2_InputDmaDone3           = 53|0x200U,   /**< DMA_DONE3 output assigned to XBARB_IN53 input. */
    kXBARB2_InputDmaDone4           = 54|0x200U,   /**< DMA_DONE4 output assigned to XBARB_IN54 input. */
    kXBARB2_InputDmaDone5           = 55|0x200U,   /**< DMA_DONE5 output assigned to XBARB_IN55 input. */
    kXBARB2_InputDmaDone6           = 56|0x200U,   /**< DMA_DONE6 output assigned to XBARB_IN56 input. */
    kXBARB2_InputDmaDone7           = 57|0x200U,   /**< DMA_DONE7 output assigned to XBARB_IN57 input. */
} xbar_input_signal_t;
#endif /* XBAR_INPUT_SIGNAL_T_ */

#if !defined(XBAR_OUTPUT_SIGNAL_T_)
#define XBAR_OUTPUT_SIGNAL_T_
typedef enum _xbar_output_signal
{
    kXBARA1_OutputDmaChMuxReq30     = 0|0x100U,    /**< XBARA_OUT0 output assigned to DMA_CH_MUX_REQ30 */
    kXBARA1_OutputDmaChMuxReq31     = 1|0x100U,    /**< XBARA_OUT1 output assigned to DMA_CH_MUX_REQ31 */
    kXBARA1_OutputDmaChMuxReq94     = 2|0x100U,    /**< XBARA_OUT2 output assigned to DMA_CH_MUX_REQ94 */
    kXBARA1_OutputDmaChMuxReq95     = 3|0x100U,    /**< XBARA_OUT3 output assigned to DMA_CH_MUX_REQ95 */
    kXBARA1_OutputIomuxXbarInout04  = 4|0x100U,    /**< XBARA_OUT4 output assigned to IOMUX_XBAR_INOUT04 */
    kXBARA1_OutputIomuxXbarInout05  = 5|0x100U,    /**< XBARA_OUT5 output assigned to IOMUX_XBAR_INOUT05 */
    kXBARA1_OutputIomuxXbarInout06  = 6|0x100U,    /**< XBARA_OUT6 output assigned to IOMUX_XBAR_INOUT06 */
    kXBARA1_OutputIomuxXbarInout07  = 7|0x100U,    /**< XBARA_OUT7 output assigned to IOMUX_XBAR_INOUT07 */
    kXBARA1_OutputIomuxXbarInout08  = 8|0x100U,    /**< XBARA_OUT8 output assigned to IOMUX_XBAR_INOUT08 */
    kXBARA1_OutputIomuxXbarInout09  = 9|0x100U,    /**< XBARA_OUT9 output assigned to IOMUX_XBAR_INOUT09 */
    kXBARA1_OutputIomuxXbarInout10  = 10|0x100U,   /**< XBARA_OUT10 output assigned to IOMUX_XBAR_INOUT10 */
    kXBARA1_OutputIomuxXbarInout11  = 11|0x100U,   /**< XBARA_OUT11 output assigned to IOMUX_XBAR_INOUT11 */
    kXBARA1_OutputIomuxXbarInout12  = 12|0x100U,   /**< XBARA_OUT12 output assigned to IOMUX_XBAR_INOUT12 */
    kXBARA1_OutputIomuxXbarInout13  = 13|0x100U,   /**< XBARA_OUT13 output assigned to IOMUX_XBAR_INOUT13 */
    kXBARA1_OutputIomuxXbarInout14  = 14|0x100U,   /**< XBARA_OUT14 output assigned to IOMUX_XBAR_INOUT14 */
    kXBARA1_OutputIomuxXbarInout15  = 15|0x100U,   /**< XBARA_OUT15 output assigned to IOMUX_XBAR_INOUT15 */
    kXBARA1_OutputIomuxXbarInout16  = 16|0x100U,   /**< XBARA_OUT16 output assigned to IOMUX_XBAR_INOUT16 */
    kXBARA1_OutputIomuxXbarInout17  = 17|0x100U,   /**< XBARA_OUT17 output assigned to IOMUX_XBAR_INOUT17 */
    kXBARA1_OutputIomuxXbarInout18  = 18|0x100U,   /**< XBARA_OUT18 output assigned to IOMUX_XBAR_INOUT18 */
    kXBARA1_OutputIomuxXbarInout19  = 19|0x100U,   /**< XBARA_OUT19 output assigned to IOMUX_XBAR_INOUT19 */
    kXBARA1_OutputAcmp1Sample       = 20|0x100U,   /**< XBARA_OUT20 output assigned to ACMP1_SAMPLE */
    kXBARA1_OutputAcmp2Sample       = 21|0x100U,   /**< XBARA_OUT21 output assigned to ACMP2_SAMPLE */
    kXBARA1_OutputAcmp3Sample       = 22|0x100U,   /**< XBARA_OUT22 output assigned to ACMP3_SAMPLE */
    kXBARA1_OutputAcmp4Sample       = 23|0x100U,   /**< XBARA_OUT23 output assigned to ACMP4_SAMPLE */
    kXBARA1_OutputRESERVED24        = 24|0x100U,   /**< XBARA_OUT24 output is reserved. */
    kXBARA1_OutputRESERVED25        = 25|0x100U,   /**< XBARA_OUT25 output is reserved. */
    kXBARA1_OutputFlexpwm1Exta0     = 26|0x100U,   /**< XBARA_OUT26 output assigned to FLEXPWM1_EXTA0 */
    kXBARA1_OutputFlexpwm1Exta1     = 27|0x100U,   /**< XBARA_OUT27 output assigned to FLEXPWM1_EXTA1 */
    kXBARA1_OutputFlexpwm1Exta2     = 28|0x100U,   /**< XBARA_OUT28 output assigned to FLEXPWM1_EXTA2 */
    kXBARA1_OutputFlexpwm1Exta3     = 29|0x100U,   /**< XBARA_OUT29 output assigned to FLEXPWM1_EXTA3 */
    kXBARA1_OutputFlexpwm1ExtSync0  = 30|0x100U,   /**< XBARA_OUT30 output assigned to FLEXPWM1_EXT_SYNC0 */
    kXBARA1_OutputFlexpwm1ExtSync1  = 31|0x100U,   /**< XBARA_OUT31 output assigned to FLEXPWM1_EXT_SYNC1 */
    kXBARA1_OutputFlexpwm1ExtSync2  = 32|0x100U,   /**< XBARA_OUT32 output assigned to FLEXPWM1_EXT_SYNC2 */
    kXBARA1_OutputFlexpwm1ExtSync3  = 33|0x100U,   /**< XBARA_OUT33 output assigned to FLEXPWM1_EXT_SYNC3 */
    kXBARA1_OutputFlexpwm1ExtClk    = 34|0x100U,   /**< XBARA_OUT34 output assigned to FLEXPWM1_EXT_CLK */
    kXBARA1_OutputFlexpwm1Fault0    = 35|0x100U,   /**< XBARA_OUT35 output assigned to FLEXPWM1_FAULT0 */
    kXBARA1_OutputFlexpwm1Fault1    = 36|0x100U,   /**< XBARA_OUT36 output assigned to FLEXPWM1_FAULT1 */
    kXBARA1_OutputFlexpwm12Fault2   = 37|0x100U,   /**< XBARA_OUT37 output assigned to FLEXPWM1_2_FAULT2 */
    kXBARA1_OutputFlexpwm12Fault3   = 38|0x100U,   /**< XBARA_OUT38 output assigned to FLEXPWM1_2_FAULT3 */
    kXBARA1_OutputFlexpwm1ExtForce  = 39|0x100U,   /**< XBARA_OUT39 output assigned to FLEXPWM1_EXT_FORCE */
    kXBARA1_OutputFlexpwm2Exta0     = 40|0x100U,   /**< XBARA_OUT40 output assigned to FLEXPWM2_EXTA0 */
    kXBARA1_OutputFlexpwm2Exta1     = 41|0x100U,   /**< XBARA_OUT41 output assigned to FLEXPWM2_EXTA1 */
    kXBARA1_OutputFlexpwm2Exta2     = 42|0x100U,   /**< XBARA_OUT42 output assigned to FLEXPWM2_EXTA2 */
    kXBARA1_OutputFlexpwm2Exta3     = 43|0x100U,   /**< XBARA_OUT43 output assigned to FLEXPWM2_EXTA3 */
    kXBARA1_OutputFlexpwm2ExtSync0  = 44|0x100U,   /**< XBARA_OUT44 output assigned to FLEXPWM2_EXT_SYNC0 */
    kXBARA1_OutputFlexpwm2ExtSync1  = 45|0x100U,   /**< XBARA_OUT45 output assigned to FLEXPWM2_EXT_SYNC1 */
    kXBARA1_OutputFlexpwm2ExtSync2  = 46|0x100U,   /**< XBARA_OUT46 output assigned to FLEXPWM2_EXT_SYNC2 */
    kXBARA1_OutputFlexpwm2ExtSync3  = 47|0x100U,   /**< XBARA_OUT47 output assigned to FLEXPWM2_EXT_SYNC3 */
    kXBARA1_OutputFlexpwm2ExtClk    = 48|0x100U,   /**< XBARA_OUT48 output assigned to FLEXPWM2_EXT_CLK */
    kXBARA1_OutputFlexpwm2Fault0    = 49|0x100U,   /**< XBARA_OUT49 output assigned to FLEXPWM2_FAULT0 */
    kXBARA1_OutputFlexpwm2Fault1    = 50|0x100U,   /**< XBARA_OUT50 output assigned to FLEXPWM2_FAULT1 */
    kXBARA1_OutputFlexpwm2ExtForce  = 51|0x100U,   /**< XBARA_OUT51 output assigned to FLEXPWM2_EXT_FORCE */
    kXBARA1_OutputRESERVED52        = 52|0x100U,   /**< XBARA_OUT52 output is reserved. */
    kXBARA1_OutputRESERVED53        = 53|0x100U,   /**< XBARA_OUT53 output is reserved. */
    kXBARA1_OutputRESERVED54        = 54|0x100U,   /**< XBARA_OUT54 output is reserved. */
    kXBARA1_OutputRESERVED55        = 55|0x100U,   /**< XBARA_OUT55 output is reserved. */
    kXBARA1_OutputRESERVED56        = 56|0x100U,   /**< XBARA_OUT56 output is reserved. */
    kXBARA1_OutputRESERVED57        = 57|0x100U,   /**< XBARA_OUT57 output is reserved. */
    kXBARA1_OutputRESERVED58        = 58|0x100U,   /**< XBARA_OUT58 output is reserved. */
    kXBARA1_OutputRESERVED59        = 59|0x100U,   /**< XBARA_OUT59 output is reserved. */
    kXBARA1_OutputRESERVED60        = 60|0x100U,   /**< XBARA_OUT60 output is reserved. */
    kXBARA1_OutputRESERVED61        = 61|0x100U,   /**< XBARA_OUT61 output is reserved. */
    kXBARA1_OutputRESERVED62        = 62|0x100U,   /**< XBARA_OUT62 output is reserved. */
    kXBARA1_OutputRESERVED63        = 63|0x100U,   /**< XBARA_OUT63 output is reserved. */
    kXBARA1_OutputRESERVED64        = 64|0x100U,   /**< XBARA_OUT64 output is reserved. */
    kXBARA1_OutputRESERVED65        = 65|0x100U,   /**< XBARA_OUT65 output is reserved. */
    kXBARA1_OutputEnc1PhaseAInput   = 66|0x100U,   /**< XBARA_OUT66 output assigned to ENC1_PHASE_A_INPUT */
    kXBARA1_OutputEnc1PhaseBInput   = 67|0x100U,   /**< XBARA_OUT67 output assigned to ENC1_PHASE_B_INPUT */
    kXBARA1_OutputEnc1Index         = 68|0x100U,   /**< XBARA_OUT68 output assigned to ENC1_INDEX */
    kXBARA1_OutputEnc1Home          = 69|0x100U,   /**< XBARA_OUT69 output assigned to ENC1_HOME */
    kXBARA1_OutputEnc1Trigger       = 70|0x100U,   /**< XBARA_OUT70 output assigned to ENC1_TRIGGER */
    kXBARA1_OutputEnc2PhaseAInput   = 71|0x100U,   /**< XBARA_OUT71 output assigned to ENC2_PHASE_A_INPUT */
    kXBARA1_OutputEnc2PhaseBInput   = 72|0x100U,   /**< XBARA_OUT72 output assigned to ENC2_PHASE_B_INPUT */
    kXBARA1_OutputEnc2Index         = 73|0x100U,   /**< XBARA_OUT73 output assigned to ENC2_INDEX */
    kXBARA1_OutputEnc2Home          = 74|0x100U,   /**< XBARA_OUT74 output assigned to ENC2_HOME */
    kXBARA1_OutputEnc2Trigger       = 75|0x100U,   /**< XBARA_OUT75 output assigned to ENC2_TRIGGER */
    kXBARA1_OutputRESERVED76        = 76|0x100U,   /**< XBARA_OUT76 output is reserved. */
    kXBARA1_OutputRESERVED77        = 77|0x100U,   /**< XBARA_OUT77 output is reserved. */
    kXBARA1_OutputRESERVED78        = 78|0x100U,   /**< XBARA_OUT78 output is reserved. */
    kXBARA1_OutputRESERVED79        = 79|0x100U,   /**< XBARA_OUT79 output is reserved. */
    kXBARA1_OutputRESERVED80        = 80|0x100U,   /**< XBARA_OUT80 output is reserved. */
    kXBARA1_OutputRESERVED81        = 81|0x100U,   /**< XBARA_OUT81 output is reserved. */
    kXBARA1_OutputRESERVED82        = 82|0x100U,   /**< XBARA_OUT82 output is reserved. */
    kXBARA1_OutputRESERVED83        = 83|0x100U,   /**< XBARA_OUT83 output is reserved. */
    kXBARA1_OutputRESERVED84        = 84|0x100U,   /**< XBARA_OUT84 output is reserved. */
    kXBARA1_OutputRESERVED85        = 85|0x100U,   /**< XBARA_OUT85 output is reserved. */
    kXBARA1_OutputQtimer1Tmr0       = 86|0x100U,   /**< XBARA_OUT86 output assigned to QTIMER1_TMR0 */
    kXBARA1_OutputQtimer1Tmr1       = 87|0x100U,   /**< XBARA_OUT87 output assigned to QTIMER1_TMR1 */
    kXBARA1_OutputQtimer1Tmr2       = 88|0x100U,   /**< XBARA_OUT88 output assigned to QTIMER1_TMR2 */
    kXBARA1_OutputQtimer1Tmr3       = 89|0x100U,   /**< XBARA_OUT89 output assigned to QTIMER1_TMR3 */
    kXBARA1_OutputQtimer2Tmr0       = 90|0x100U,   /**< XBARA_OUT90 output assigned to QTIMER2_TMR0 */
    kXBARA1_OutputQtimer2Tmr1       = 91|0x100U,   /**< XBARA_OUT91 output assigned to QTIMER2_TMR1 */
    kXBARA1_OutputQtimer2Tmr2       = 92|0x100U,   /**< XBARA_OUT92 output assigned to QTIMER2_TMR2 */
    kXBARA1_OutputQtimer2Tmr3       = 93|0x100U,   /**< XBARA_OUT93 output assigned to QTIMER2_TMR3 */
    kXBARA1_OutputRESERVED94        = 94|0x100U,   /**< XBARA_OUT94 output is reserved. */
    kXBARA1_OutputRESERVED95        = 95|0x100U,   /**< XBARA_OUT95 output is reserved. */
    kXBARA1_OutputRESERVED96        = 96|0x100U,   /**< XBARA_OUT96 output is reserved. */
    kXBARA1_OutputRESERVED97        = 97|0x100U,   /**< XBARA_OUT97 output is reserved. */
    kXBARA1_OutputRESERVED98        = 98|0x100U,   /**< XBARA_OUT98 output is reserved. */
    kXBARA1_OutputRESERVED99        = 99|0x100U,   /**< XBARA_OUT99 output is reserved. */
    kXBARA1_OutputRESERVED100       = 100|0x100U,  /**< XBARA_OUT100 output is reserved. */
    kXBARA1_OutputRESERVED101       = 101|0x100U,  /**< XBARA_OUT101 output is reserved. */
    kXBARA1_OutputEwmEwmIn          = 102|0x100U,  /**< XBARA_OUT102 output assigned to EWM_EWM_IN */
    kXBARA1_OutputAdcEtcTrig00      = 103|0x100U,  /**< XBARA_OUT103 output assigned to ADC_ETC_TRIG00 */
    kXBARA1_OutputAdcEtcTrig01      = 104|0x100U,  /**< XBARA_OUT104 output assigned to ADC_ETC_TRIG01 */
    kXBARA1_OutputAdcEtcTrig02      = 105|0x100U,  /**< XBARA_OUT105 output assigned to ADC_ETC_TRIG02 */
    kXBARA1_OutputAdcEtcTrig03      = 106|0x100U,  /**< XBARA_OUT106 output assigned to ADC_ETC_TRIG03 */
    kXBARA1_OutputAdcEtcTrig10      = 107|0x100U,  /**< XBARA_OUT107 output assigned to ADC_ETC_TRIG10 */
    kXBARA1_OutputAdcEtcTrig11      = 108|0x100U,  /**< XBARA_OUT108 output assigned to ADC_ETC_TRIG11 */
    kXBARA1_OutputAdcEtcTrig12      = 109|0x100U,  /**< XBARA_OUT109 output assigned to ADC_ETC_TRIG12 */
    kXBARA1_OutputAdcEtcTrig13      = 110|0x100U,  /**< XBARA_OUT110 output assigned to ADC_ETC_TRIG13 */
    kXBARA1_OutputLpi2c1TrgInput    = 111|0x100U,  /**< XBARA_OUT111 output assigned to LPI2C1_TRG_INPUT */
    kXBARA1_OutputLpi2c2TrgInput    = 112|0x100U,  /**< XBARA_OUT112 output assigned to LPI2C2_TRG_INPUT */
    kXBARA1_OutputLpi2c3TrgInput    = 113|0x100U,  /**< XBARA_OUT113 output assigned to LPI2C3_TRG_INPUT */
    kXBARA1_OutputLpi2c4TrgInput    = 114|0x100U,  /**< XBARA_OUT114 output assigned to LPI2C4_TRG_INPUT */
    kXBARA1_OutputLpspi1TrgInput    = 115|0x100U,  /**< XBARA_OUT115 output assigned to LPSPI1_TRG_INPUT */
    kXBARA1_OutputLpspi2TrgInput    = 116|0x100U,  /**< XBARA_OUT116 output assigned to LPSPI2_TRG_INPUT */
    kXBARA1_OutputLpspi3TrgInput    = 117|0x100U,  /**< XBARA_OUT117 output assigned to LPSPI3_TRG_INPUT */
    kXBARA1_OutputLpspi4TrgInput    = 118|0x100U,  /**< XBARA_OUT118 output assigned to LPSPI4_TRG_INPUT */
    kXBARA1_OutputLpuart1TrgInput   = 119|0x100U,  /**< XBARA_OUT119 output assigned to LPUART1_TRG_INPUT */
    kXBARA1_OutputLpuart2TrgInput   = 120|0x100U,  /**< XBARA_OUT120 output assigned to LPUART2_TRG_INPUT */
    kXBARA1_OutputLpuart3TrgInput   = 121|0x100U,  /**< XBARA_OUT121 output assigned to LPUART3_TRG_INPUT */
    kXBARA1_OutputLpuart4TrgInput   = 122|0x100U,  /**< XBARA_OUT122 output assigned to LPUART4_TRG_INPUT */
    kXBARA1_OutputLpuart5TrgInput   = 123|0x100U,  /**< XBARA_OUT123 output assigned to LPUART5_TRG_INPUT */
    kXBARA1_OutputLpuart6TrgInput   = 124|0x100U,  /**< XBARA_OUT124 output assigned to LPUART6_TRG_INPUT */
    kXBARA1_OutputLpuart7TrgInput   = 125|0x100U,  /**< XBARA_OUT125 output assigned to LPUART7_TRG_INPUT */
    kXBARA1_OutputLpuart8TrgInput   = 126|0x100U,  /**< XBARA_OUT126 output assigned to LPUART8_TRG_INPUT */
    kXBARA1_OutputFlexio1TriggerIn0 = 127|0x100U,  /**< XBARA_OUT127 output assigned to FLEXIO1_TRIGGER_IN0 */
    kXBARA1_OutputFlexio1TriggerIn1 = 128|0x100U,  /**< XBARA_OUT128 output assigned to FLEXIO1_TRIGGER_IN1 */
    kXBARA1_OutputRESERVED129       = 129|0x100U,  /**< XBARA_OUT129 output is reserved. */
    kXBARA1_OutputRESERVED130       = 130|0x100U,  /**< XBARA_OUT130 output is reserved. */
    kXBARA1_OutputRESERVED131       = 131|0x100U,  /**< XBARA_OUT131 output is reserved. */
    kXBARB2_OutputAoi1In00          = 0|0x200U,    /**< XBARB_OUT0 output assigned to AOI1_IN00 */
    kXBARB2_OutputAoi1In01          = 1|0x200U,    /**< XBARB_OUT1 output assigned to AOI1_IN01 */
    kXBARB2_OutputAoi1In02          = 2|0x200U,    /**< XBARB_OUT2 output assigned to AOI1_IN02 */
    kXBARB2_OutputAoi1In03          = 3|0x200U,    /**< XBARB_OUT3 output assigned to AOI1_IN03 */
    kXBARB2_OutputAoi1In04          = 4|0x200U,    /**< XBARB_OUT4 output assigned to AOI1_IN04 */
    kXBARB2_OutputAoi1In05          = 5|0x200U,    /**< XBARB_OUT5 output assigned to AOI1_IN05 */
    kXBARB2_OutputAoi1In06          = 6|0x200U,    /**< XBARB_OUT6 output assigned to AOI1_IN06 */
    kXBARB2_OutputAoi1In07          = 7|0x200U,    /**< XBARB_OUT7 output assigned to AOI1_IN07 */
    kXBARB2_OutputAoi1In08          = 8|0x200U,    /**< XBARB_OUT8 output assigned to AOI1_IN08 */
    kXBARB2_OutputAoi1In09          = 9|0x200U,    /**< XBARB_OUT9 output assigned to AOI1_IN09 */
    kXBARB2_OutputAoi1In10          = 10|0x200U,   /**< XBARB_OUT10 output assigned to AOI1_IN10 */
    kXBARB2_OutputAoi1In11          = 11|0x200U,   /**< XBARB_OUT11 output assigned to AOI1_IN11 */
    kXBARB2_OutputAoi1In12          = 12|0x200U,   /**< XBARB_OUT12 output assigned to AOI1_IN12 */
    kXBARB2_OutputAoi1In13          = 13|0x200U,   /**< XBARB_OUT13 output assigned to AOI1_IN13 */
    kXBARB2_OutputAoi1In14          = 14|0x200U,   /**< XBARB_OUT14 output assigned to AOI1_IN14 */
    kXBARB2_OutputAoi1In15          = 15|0x200U,   /**< XBARB_OUT15 output assigned to AOI1_IN15 */
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- XBARB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARB_Peripheral_Access_Layer XBARB Peripheral Access Layer
 * @{
 */

/** XBARB - Register Layout Typedef */
typedef struct {
  __IO uint16_t SEL0;                              /**< Crossbar B Select Register 0, offset: 0x0 */
  __IO uint16_t SEL1;                              /**< Crossbar B Select Register 1, offset: 0x2 */
  __IO uint16_t SEL2;                              /**< Crossbar B Select Register 2, offset: 0x4 */
  __IO uint16_t SEL3;                              /**< Crossbar B Select Register 3, offset: 0x6 */
  __IO uint16_t SEL4;                              /**< Crossbar B Select Register 4, offset: 0x8 */
  __IO uint16_t SEL5;                              /**< Crossbar B Select Register 5, offset: 0xA */
  __IO uint16_t SEL6;                              /**< Crossbar B Select Register 6, offset: 0xC */
  __IO uint16_t SEL7;                              /**< Crossbar B Select Register 7, offset: 0xE */
} XBARB_Type;

/* ----------------------------------------------------------------------------
   -- XBARB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARB_Register_Masks XBARB Register Masks
 * @{
 */

/*! @name SEL0 - Crossbar B Select Register 0 */
/*! @{ */

#define XBARB_SEL0_SEL0_MASK                     (0x3FU)
#define XBARB_SEL0_SEL0_SHIFT                    (0U)
#define XBARB_SEL0_SEL0(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL0_SEL0_SHIFT)) & XBARB_SEL0_SEL0_MASK)

#define XBARB_SEL0_SEL1_MASK                     (0x3F00U)
#define XBARB_SEL0_SEL1_SHIFT                    (8U)
#define XBARB_SEL0_SEL1(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL0_SEL1_SHIFT)) & XBARB_SEL0_SEL1_MASK)
/*! @} */

/*! @name SEL1 - Crossbar B Select Register 1 */
/*! @{ */

#define XBARB_SEL1_SEL2_MASK                     (0x3FU)
#define XBARB_SEL1_SEL2_SHIFT                    (0U)
#define XBARB_SEL1_SEL2(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL1_SEL2_SHIFT)) & XBARB_SEL1_SEL2_MASK)

#define XBARB_SEL1_SEL3_MASK                     (0x3F00U)
#define XBARB_SEL1_SEL3_SHIFT                    (8U)
#define XBARB_SEL1_SEL3(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL1_SEL3_SHIFT)) & XBARB_SEL1_SEL3_MASK)
/*! @} */

/*! @name SEL2 - Crossbar B Select Register 2 */
/*! @{ */

#define XBARB_SEL2_SEL4_MASK                     (0x3FU)
#define XBARB_SEL2_SEL4_SHIFT                    (0U)
#define XBARB_SEL2_SEL4(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL2_SEL4_SHIFT)) & XBARB_SEL2_SEL4_MASK)

#define XBARB_SEL2_SEL5_MASK                     (0x3F00U)
#define XBARB_SEL2_SEL5_SHIFT                    (8U)
#define XBARB_SEL2_SEL5(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL2_SEL5_SHIFT)) & XBARB_SEL2_SEL5_MASK)
/*! @} */

/*! @name SEL3 - Crossbar B Select Register 3 */
/*! @{ */

#define XBARB_SEL3_SEL6_MASK                     (0x3FU)
#define XBARB_SEL3_SEL6_SHIFT                    (0U)
#define XBARB_SEL3_SEL6(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL3_SEL6_SHIFT)) & XBARB_SEL3_SEL6_MASK)

#define XBARB_SEL3_SEL7_MASK                     (0x3F00U)
#define XBARB_SEL3_SEL7_SHIFT                    (8U)
#define XBARB_SEL3_SEL7(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL3_SEL7_SHIFT)) & XBARB_SEL3_SEL7_MASK)
/*! @} */

/*! @name SEL4 - Crossbar B Select Register 4 */
/*! @{ */

#define XBARB_SEL4_SEL8_MASK                     (0x3FU)
#define XBARB_SEL4_SEL8_SHIFT                    (0U)
#define XBARB_SEL4_SEL8(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL4_SEL8_SHIFT)) & XBARB_SEL4_SEL8_MASK)

#define XBARB_SEL4_SEL9_MASK                     (0x3F00U)
#define XBARB_SEL4_SEL9_SHIFT                    (8U)
#define XBARB_SEL4_SEL9(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL4_SEL9_SHIFT)) & XBARB_SEL4_SEL9_MASK)
/*! @} */

/*! @name SEL5 - Crossbar B Select Register 5 */
/*! @{ */

#define XBARB_SEL5_SEL10_MASK                    (0x3FU)
#define XBARB_SEL5_SEL10_SHIFT                   (0U)
#define XBARB_SEL5_SEL10(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL5_SEL10_SHIFT)) & XBARB_SEL5_SEL10_MASK)

#define XBARB_SEL5_SEL11_MASK                    (0x3F00U)
#define XBARB_SEL5_SEL11_SHIFT                   (8U)
#define XBARB_SEL5_SEL11(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL5_SEL11_SHIFT)) & XBARB_SEL5_SEL11_MASK)
/*! @} */

/*! @name SEL6 - Crossbar B Select Register 6 */
/*! @{ */

#define XBARB_SEL6_SEL12_MASK                    (0x3FU)
#define XBARB_SEL6_SEL12_SHIFT                   (0U)
#define XBARB_SEL6_SEL12(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL6_SEL12_SHIFT)) & XBARB_SEL6_SEL12_MASK)

#define XBARB_SEL6_SEL13_MASK                    (0x3F00U)
#define XBARB_SEL6_SEL13_SHIFT                   (8U)
#define XBARB_SEL6_SEL13(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL6_SEL13_SHIFT)) & XBARB_SEL6_SEL13_MASK)
/*! @} */

/*! @name SEL7 - Crossbar B Select Register 7 */
/*! @{ */

#define XBARB_SEL7_SEL14_MASK                    (0x3FU)
#define XBARB_SEL7_SEL14_SHIFT                   (0U)
#define XBARB_SEL7_SEL14(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL7_SEL14_SHIFT)) & XBARB_SEL7_SEL14_MASK)

#define XBARB_SEL7_SEL15_MASK                    (0x3F00U)
#define XBARB_SEL7_SEL15_SHIFT                   (8U)
#define XBARB_SEL7_SEL15(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL7_SEL15_SHIFT)) & XBARB_SEL7_SEL15_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XBARB_Register_Masks */


/*!
 * @}
 */ /* end of group XBARB_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_XBARB_H_ */

