/*
** ###################################################################
**     Processors:          MIMXRT1064CVJ5A
**                          MIMXRT1064CVJ5B
**                          MIMXRT1064CVL5A
**                          MIMXRT1064CVL5B
**                          MIMXRT1064DVJ6A
**                          MIMXRT1064DVJ6B
**                          MIMXRT1064DVL6A
**                          MIMXRT1064DVL6B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 0.1 (2018-06-22)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1064RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1064RM Rev.0.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1064RM Rev.2.
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

#if (defined(CPU_MIMXRT1064CVJ5A) || defined(CPU_MIMXRT1064CVJ5B) || defined(CPU_MIMXRT1064CVL5A) || defined(CPU_MIMXRT1064CVL5B) || defined(CPU_MIMXRT1064DVJ6A) || defined(CPU_MIMXRT1064DVJ6B) || defined(CPU_MIMXRT1064DVL6A) || defined(CPU_MIMXRT1064DVL6B))
#include "MIMXRT1064_COMMON.h"
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
    kXBARA1_InputLogicLow           = 0|0x100U,    /**< LOGIC_LOW output assigned to XBARA1_IN0 input. */
    kXBARA1_InputLogicHigh          = 1|0x100U,    /**< LOGIC_HIGH output assigned to XBARA1_IN1 input. */
    kXBARA1_InputIomuxXbarIn02      = 2|0x100U,    /**< IOMUX_XBAR_IN02 output assigned to XBARA1_IN2 input. */
    kXBARA1_InputIomuxXbarIn03      = 3|0x100U,    /**< IOMUX_XBAR_IN03 output assigned to XBARA1_IN3 input. */
    kXBARA1_InputIomuxXbarInout04   = 4|0x100U,    /**< IOMUX_XBAR_INOUT04 output assigned to XBARA1_IN4 input. */
    kXBARA1_InputIomuxXbarInout05   = 5|0x100U,    /**< IOMUX_XBAR_INOUT05 output assigned to XBARA1_IN5 input. */
    kXBARA1_InputIomuxXbarInout06   = 6|0x100U,    /**< IOMUX_XBAR_INOUT06 output assigned to XBARA1_IN6 input. */
    kXBARA1_InputIomuxXbarInout07   = 7|0x100U,    /**< IOMUX_XBAR_INOUT07 output assigned to XBARA1_IN7 input. */
    kXBARA1_InputIomuxXbarInout08   = 8|0x100U,    /**< IOMUX_XBAR_INOUT08 output assigned to XBARA1_IN8 input. */
    kXBARA1_InputIomuxXbarInout09   = 9|0x100U,    /**< IOMUX_XBAR_INOUT09 output assigned to XBARA1_IN9 input. */
    kXBARA1_InputIomuxXbarInout10   = 10|0x100U,   /**< IOMUX_XBAR_INOUT10 output assigned to XBARA1_IN10 input. */
    kXBARA1_InputIomuxXbarInout11   = 11|0x100U,   /**< IOMUX_XBAR_INOUT11 output assigned to XBARA1_IN11 input. */
    kXBARA1_InputIomuxXbarInout12   = 12|0x100U,   /**< IOMUX_XBAR_INOUT12 output assigned to XBARA1_IN12 input. */
    kXBARA1_InputIomuxXbarInout13   = 13|0x100U,   /**< IOMUX_XBAR_INOUT13 output assigned to XBARA1_IN13 input. */
    kXBARA1_InputIomuxXbarInout14   = 14|0x100U,   /**< IOMUX_XBAR_INOUT14 output assigned to XBARA1_IN14 input. */
    kXBARA1_InputIomuxXbarInout15   = 15|0x100U,   /**< IOMUX_XBAR_INOUT15 output assigned to XBARA1_IN15 input. */
    kXBARA1_InputIomuxXbarInout16   = 16|0x100U,   /**< IOMUX_XBAR_INOUT16 output assigned to XBARA1_IN16 input. */
    kXBARA1_InputIomuxXbarInout17   = 17|0x100U,   /**< IOMUX_XBAR_INOUT17 output assigned to XBARA1_IN17 input. */
    kXBARA1_InputIomuxXbarInout18   = 18|0x100U,   /**< IOMUX_XBAR_INOUT18 output assigned to XBARA1_IN18 input. */
    kXBARA1_InputIomuxXbarInout19   = 19|0x100U,   /**< IOMUX_XBAR_INOUT19 output assigned to XBARA1_IN19 input. */
    kXBARA1_InputIomuxXbarIn20      = 20|0x100U,   /**< IOMUX_XBAR_IN20 output assigned to XBARA1_IN20 input. */
    kXBARA1_InputIomuxXbarIn21      = 21|0x100U,   /**< IOMUX_XBAR_IN21 output assigned to XBARA1_IN21 input. */
    kXBARA1_InputIomuxXbarIn22      = 22|0x100U,   /**< IOMUX_XBAR_IN22 output assigned to XBARA1_IN22 input. */
    kXBARA1_InputIomuxXbarIn23      = 23|0x100U,   /**< IOMUX_XBAR_IN23 output assigned to XBARA1_IN23 input. */
    kXBARA1_InputIomuxXbarIn24      = 24|0x100U,   /**< IOMUX_XBAR_IN24 output assigned to XBARA1_IN24 input. */
    kXBARA1_InputIomuxXbarIn25      = 25|0x100U,   /**< IOMUX_XBAR_IN25 output assigned to XBARA1_IN25 input. */
    kXBARA1_InputAcmp1Out           = 26|0x100U,   /**< ACMP1_OUT output assigned to XBARA1_IN26 input. */
    kXBARA1_InputAcmp2Out           = 27|0x100U,   /**< ACMP2_OUT output assigned to XBARA1_IN27 input. */
    kXBARA1_InputAcmp3Out           = 28|0x100U,   /**< ACMP3_OUT output assigned to XBARA1_IN28 input. */
    kXBARA1_InputAcmp4Out           = 29|0x100U,   /**< ACMP4_OUT output assigned to XBARA1_IN29 input. */
    kXBARA1_InputRESERVED30         = 30|0x100U,   /**< XBARA1_IN30 input is reserved. */
    kXBARA1_InputRESERVED31         = 31|0x100U,   /**< XBARA1_IN31 input is reserved. */
    kXBARA1_InputQtimer3Tmr0Output  = 32|0x100U,   /**< QTIMER3_TMR0_OUTPUT output assigned to XBARA1_IN32 input. */
    kXBARA1_InputQtimer3Tmr1Output  = 33|0x100U,   /**< QTIMER3_TMR1_OUTPUT output assigned to XBARA1_IN33 input. */
    kXBARA1_InputQtimer3Tmr2Output  = 34|0x100U,   /**< QTIMER3_TMR2_OUTPUT output assigned to XBARA1_IN34 input. */
    kXBARA1_InputQtimer3Tmr3Output  = 35|0x100U,   /**< QTIMER3_TMR3_OUTPUT output assigned to XBARA1_IN35 input. */
    kXBARA1_InputQtimer4Tmr0Output  = 36|0x100U,   /**< QTIMER4_TMR0_OUTPUT output assigned to XBARA1_IN36 input. */
    kXBARA1_InputQtimer4Tmr1Output  = 37|0x100U,   /**< QTIMER4_TMR1_OUTPUT output assigned to XBARA1_IN37 input. */
    kXBARA1_InputQtimer4Tmr2Output  = 38|0x100U,   /**< QTIMER4_TMR2_OUTPUT output assigned to XBARA1_IN38 input. */
    kXBARA1_InputQtimer4Tmr3Output  = 39|0x100U,   /**< QTIMER4_TMR3_OUTPUT output assigned to XBARA1_IN39 input. */
    kXBARA1_InputFlexpwm1Pwm1OutTrig01 = 40|0x100U, /**< FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBARA1_IN40 input. */
    kXBARA1_InputFlexpwm1Pwm2OutTrig01 = 41|0x100U, /**< FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBARA1_IN41 input. */
    kXBARA1_InputFlexpwm1Pwm3OutTrig01 = 42|0x100U, /**< FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBARA1_IN42 input. */
    kXBARA1_InputFlexpwm1Pwm4OutTrig01 = 43|0x100U, /**< FLEXPWM1_PWM4_OUT_TRIG0_1 output assigned to XBARA1_IN43 input. */
    kXBARA1_InputFlexpwm2Pwm1OutTrig01 = 44|0x100U, /**< FLEXPWM2_PWM1_OUT_TRIG0_1 output assigned to XBARA1_IN44 input. */
    kXBARA1_InputFlexpwm2Pwm2OutTrig01 = 45|0x100U, /**< FLEXPWM2_PWM2_OUT_TRIG0_1 output assigned to XBARA1_IN45 input. */
    kXBARA1_InputFlexpwm2Pwm3OutTrig01 = 46|0x100U, /**< FLEXPWM2_PWM3_OUT_TRIG0_1 output assigned to XBARA1_IN46 input. */
    kXBARA1_InputFlexpwm2Pwm4OutTrig01 = 47|0x100U, /**< FLEXPWM2_PWM4_OUT_TRIG0_1 output assigned to XBARA1_IN47 input. */
    kXBARA1_InputFlexpwm3Pwm1OutTrig01 = 48|0x100U, /**< FLEXPWM3_PWM1_OUT_TRIG0_1 output assigned to XBARA1_IN48 input. */
    kXBARA1_InputFlexpwm3Pwm2OutTrig01 = 49|0x100U, /**< FLEXPWM3_PWM2_OUT_TRIG0_1 output assigned to XBARA1_IN49 input. */
    kXBARA1_InputFlexpwm3Pwm3OutTrig01 = 50|0x100U, /**< FLEXPWM3_PWM3_OUT_TRIG0_1 output assigned to XBARA1_IN50 input. */
    kXBARA1_InputFlexpwm3Pwm4OutTrig01 = 51|0x100U, /**< FLEXPWM3_PWM4_OUT_TRIG0_1 output assigned to XBARA1_IN51 input. */
    kXBARA1_InputFlexpwm4Pwm1OutTrig01 = 52|0x100U, /**< FLEXPWM4_PWM1_OUT_TRIG0_1 output assigned to XBARA1_IN52 input. */
    kXBARA1_InputFlexpwm4Pwm2OutTrig01 = 53|0x100U, /**< FLEXPWM4_PWM2_OUT_TRIG0_1 output assigned to XBARA1_IN53 input. */
    kXBARA1_InputFlexpwm4Pwm3OutTrig01 = 54|0x100U, /**< FLEXPWM4_PWM3_OUT_TRIG0_1 output assigned to XBARA1_IN54 input. */
    kXBARA1_InputFlexpwm4Pwm4OutTrig01 = 55|0x100U, /**< FLEXPWM4_PWM4_OUT_TRIG0_1 output assigned to XBARA1_IN55 input. */
    kXBARA1_InputPitTrigger0        = 56|0x100U,   /**< PIT_TRIGGER0 output assigned to XBARA1_IN56 input. */
    kXBARA1_InputPitTrigger1        = 57|0x100U,   /**< PIT_TRIGGER1 output assigned to XBARA1_IN57 input. */
    kXBARA1_InputPitTrigger2        = 58|0x100U,   /**< PIT_TRIGGER2 output assigned to XBARA1_IN58 input. */
    kXBARA1_InputPitTrigger3        = 59|0x100U,   /**< PIT_TRIGGER3 output assigned to XBARA1_IN59 input. */
    kXBARA1_InputEnc1PosMatch       = 60|0x100U,   /**< ENC1_POS_MATCH output assigned to XBARA1_IN60 input. */
    kXBARA1_InputEnc2PosMatch       = 61|0x100U,   /**< ENC2_POS_MATCH output assigned to XBARA1_IN61 input. */
    kXBARA1_InputEnc3PosMatch       = 62|0x100U,   /**< ENC3_POS_MATCH output assigned to XBARA1_IN62 input. */
    kXBARA1_InputEnc4PosMatch       = 63|0x100U,   /**< ENC4_POS_MATCH output assigned to XBARA1_IN63 input. */
    kXBARA1_InputDmaDone0           = 64|0x100U,   /**< DMA_DONE0 output assigned to XBARA1_IN64 input. */
    kXBARA1_InputDmaDone1           = 65|0x100U,   /**< DMA_DONE1 output assigned to XBARA1_IN65 input. */
    kXBARA1_InputDmaDone2           = 66|0x100U,   /**< DMA_DONE2 output assigned to XBARA1_IN66 input. */
    kXBARA1_InputDmaDone3           = 67|0x100U,   /**< DMA_DONE3 output assigned to XBARA1_IN67 input. */
    kXBARA1_InputDmaDone4           = 68|0x100U,   /**< DMA_DONE4 output assigned to XBARA1_IN68 input. */
    kXBARA1_InputDmaDone5           = 69|0x100U,   /**< DMA_DONE5 output assigned to XBARA1_IN69 input. */
    kXBARA1_InputDmaDone6           = 70|0x100U,   /**< DMA_DONE6 output assigned to XBARA1_IN70 input. */
    kXBARA1_InputDmaDone7           = 71|0x100U,   /**< DMA_DONE7 output assigned to XBARA1_IN71 input. */
    kXBARA1_InputAoi1Out0           = 72|0x100U,   /**< AOI1_OUT0 output assigned to XBARA1_IN72 input. */
    kXBARA1_InputAoi1Out1           = 73|0x100U,   /**< AOI1_OUT1 output assigned to XBARA1_IN73 input. */
    kXBARA1_InputAoi1Out2           = 74|0x100U,   /**< AOI1_OUT2 output assigned to XBARA1_IN74 input. */
    kXBARA1_InputAoi1Out3           = 75|0x100U,   /**< AOI1_OUT3 output assigned to XBARA1_IN75 input. */
    kXBARA1_InputAoi2Out0           = 76|0x100U,   /**< AOI2_OUT0 output assigned to XBARA1_IN76 input. */
    kXBARA1_InputAoi2Out1           = 77|0x100U,   /**< AOI2_OUT1 output assigned to XBARA1_IN77 input. */
    kXBARA1_InputAoi2Out2           = 78|0x100U,   /**< AOI2_OUT2 output assigned to XBARA1_IN78 input. */
    kXBARA1_InputAoi2Out3           = 79|0x100U,   /**< AOI2_OUT3 output assigned to XBARA1_IN79 input. */
    kXBARA1_InputAdcEtcXbar0Coco0   = 80|0x100U,   /**< ADC_ETC_XBAR0_COCO0 output assigned to XBARA1_IN80 input. */
    kXBARA1_InputAdcEtcXbar0Coco1   = 81|0x100U,   /**< ADC_ETC_XBAR0_COCO1 output assigned to XBARA1_IN81 input. */
    kXBARA1_InputAdcEtcXbar0Coco2   = 82|0x100U,   /**< ADC_ETC_XBAR0_COCO2 output assigned to XBARA1_IN82 input. */
    kXBARA1_InputAdcEtcXbar0Coco3   = 83|0x100U,   /**< ADC_ETC_XBAR0_COCO3 output assigned to XBARA1_IN83 input. */
    kXBARA1_InputAdcEtcXbar1Coco0   = 84|0x100U,   /**< ADC_ETC_XBAR1_COCO0 output assigned to XBARA1_IN84 input. */
    kXBARA1_InputAdcEtcXbar1Coco1   = 85|0x100U,   /**< ADC_ETC_XBAR1_COCO1 output assigned to XBARA1_IN85 input. */
    kXBARA1_InputAdcEtcXbar1Coco2   = 86|0x100U,   /**< ADC_ETC_XBAR1_COCO2 output assigned to XBARA1_IN86 input. */
    kXBARA1_InputAdcEtcXbar1Coco3   = 87|0x100U,   /**< ADC_ETC_XBAR1_COCO3 output assigned to XBARA1_IN87 input. */
    kXBARB2_InputLogicLow           = 0|0x200U,    /**< LOGIC_LOW output assigned to XBARB2_IN0 input. */
    kXBARB2_InputLogicHigh          = 1|0x200U,    /**< LOGIC_HIGH output assigned to XBARB2_IN1 input. */
    kXBARB2_InputRESERVED2          = 2|0x200U,    /**< XBARB2_IN2 input is reserved. */
    kXBARB2_InputRESERVED3          = 3|0x200U,    /**< XBARB2_IN3 input is reserved. */
    kXBARB2_InputRESERVED4          = 4|0x200U,    /**< XBARB2_IN4 input is reserved. */
    kXBARB2_InputRESERVED5          = 5|0x200U,    /**< XBARB2_IN5 input is reserved. */
    kXBARB2_InputAcmp1Out           = 6|0x200U,    /**< ACMP1_OUT output assigned to XBARB2_IN6 input. */
    kXBARB2_InputAcmp2Out           = 7|0x200U,    /**< ACMP2_OUT output assigned to XBARB2_IN7 input. */
    kXBARB2_InputAcmp3Out           = 8|0x200U,    /**< ACMP3_OUT output assigned to XBARB2_IN8 input. */
    kXBARB2_InputAcmp4Out           = 9|0x200U,    /**< ACMP4_OUT output assigned to XBARB2_IN9 input. */
    kXBARB2_InputRESERVED10         = 10|0x200U,   /**< XBARB2_IN10 input is reserved. */
    kXBARB2_InputRESERVED11         = 11|0x200U,   /**< XBARB2_IN11 input is reserved. */
    kXBARB2_InputQtimer3Tmr0Output  = 12|0x200U,   /**< QTIMER3_TMR0_OUTPUT output assigned to XBARB2_IN12 input. */
    kXBARB2_InputQtimer3Tmr1Output  = 13|0x200U,   /**< QTIMER3_TMR1_OUTPUT output assigned to XBARB2_IN13 input. */
    kXBARB2_InputQtimer3Tmr2Output  = 14|0x200U,   /**< QTIMER3_TMR2_OUTPUT output assigned to XBARB2_IN14 input. */
    kXBARB2_InputQtimer3Tmr3Output  = 15|0x200U,   /**< QTIMER3_TMR3_OUTPUT output assigned to XBARB2_IN15 input. */
    kXBARB2_InputQtimer4Tmr0Output  = 16|0x200U,   /**< QTIMER4_TMR0_OUTPUT output assigned to XBARB2_IN16 input. */
    kXBARB2_InputQtimer4Tmr1Output  = 17|0x200U,   /**< QTIMER4_TMR1_OUTPUT output assigned to XBARB2_IN17 input. */
    kXBARB2_InputQtimer4Tmr2Output  = 18|0x200U,   /**< QTIMER4_TMR2_OUTPUT output assigned to XBARB2_IN18 input. */
    kXBARB2_InputQtimer4Tmr3Output  = 19|0x200U,   /**< QTIMER4_TMR3_OUTPUT output assigned to XBARB2_IN19 input. */
    kXBARB2_InputFlexpwm1Pwm1OutTrig01 = 20|0x200U, /**< FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBARB2_IN20 input. */
    kXBARB2_InputFlexpwm1Pwm2OutTrig01 = 21|0x200U, /**< FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBARB2_IN21 input. */
    kXBARB2_InputFlexpwm1Pwm3OutTrig01 = 22|0x200U, /**< FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBARB2_IN22 input. */
    kXBARB2_InputFlexpwm1Pwm4OutTrig01 = 23|0x200U, /**< FLEXPWM1_PWM4_OUT_TRIG0_1 output assigned to XBARB2_IN23 input. */
    kXBARB2_InputFlexpwm2Pwm1OutTrig01 = 24|0x200U, /**< FLEXPWM2_PWM1_OUT_TRIG0_1 output assigned to XBARB2_IN24 input. */
    kXBARB2_InputFlexpwm2Pwm2OutTrig01 = 25|0x200U, /**< FLEXPWM2_PWM2_OUT_TRIG0_1 output assigned to XBARB2_IN25 input. */
    kXBARB2_InputFlexpwm2Pwm3OutTrig01 = 26|0x200U, /**< FLEXPWM2_PWM3_OUT_TRIG0_1 output assigned to XBARB2_IN26 input. */
    kXBARB2_InputFlexpwm2Pwm4OutTrig01 = 27|0x200U, /**< FLEXPWM2_PWM4_OUT_TRIG0_1 output assigned to XBARB2_IN27 input. */
    kXBARB2_InputFlexpwm3Pwm1OutTrig01 = 28|0x200U, /**< FLEXPWM3_PWM1_OUT_TRIG0_1 output assigned to XBARB2_IN28 input. */
    kXBARB2_InputFlexpwm3Pwm2OutTrig01 = 29|0x200U, /**< FLEXPWM3_PWM2_OUT_TRIG0_1 output assigned to XBARB2_IN29 input. */
    kXBARB2_InputFlexpwm3Pwm3OutTrig01 = 30|0x200U, /**< FLEXPWM3_PWM3_OUT_TRIG0_1 output assigned to XBARB2_IN30 input. */
    kXBARB2_InputFlexpwm3Pwm4OutTrig01 = 31|0x200U, /**< FLEXPWM3_PWM4_OUT_TRIG0_1 output assigned to XBARB2_IN31 input. */
    kXBARB2_InputFlexpwm4Pwm1OutTrig01 = 32|0x200U, /**< FLEXPWM4_PWM1_OUT_TRIG0_1 output assigned to XBARB2_IN32 input. */
    kXBARB2_InputFlexpwm4Pwm2OutTrig01 = 33|0x200U, /**< FLEXPWM4_PWM2_OUT_TRIG0_1 output assigned to XBARB2_IN33 input. */
    kXBARB2_InputFlexpwm4Pwm3OutTrig01 = 34|0x200U, /**< FLEXPWM4_PWM3_OUT_TRIG0_1 output assigned to XBARB2_IN34 input. */
    kXBARB2_InputFlexpwm4Pwm4OutTrig01 = 35|0x200U, /**< FLEXPWM4_PWM4_OUT_TRIG0_1 output assigned to XBARB2_IN35 input. */
    kXBARB2_InputPitTrigger0        = 36|0x200U,   /**< PIT_TRIGGER0 output assigned to XBARB2_IN36 input. */
    kXBARB2_InputPitTrigger1        = 37|0x200U,   /**< PIT_TRIGGER1 output assigned to XBARB2_IN37 input. */
    kXBARB2_InputAdcEtcXbar0Coco0   = 38|0x200U,   /**< ADC_ETC_XBAR0_COCO0 output assigned to XBARB2_IN38 input. */
    kXBARB2_InputAdcEtcXbar0Coco1   = 39|0x200U,   /**< ADC_ETC_XBAR0_COCO1 output assigned to XBARB2_IN39 input. */
    kXBARB2_InputAdcEtcXbar0Coco2   = 40|0x200U,   /**< ADC_ETC_XBAR0_COCO2 output assigned to XBARB2_IN40 input. */
    kXBARB2_InputAdcEtcXbar0Coco3   = 41|0x200U,   /**< ADC_ETC_XBAR0_COCO3 output assigned to XBARB2_IN41 input. */
    kXBARB2_InputAdcEtcXbar1Coco0   = 42|0x200U,   /**< ADC_ETC_XBAR1_COCO0 output assigned to XBARB2_IN42 input. */
    kXBARB2_InputAdcEtcXbar1Coco1   = 43|0x200U,   /**< ADC_ETC_XBAR1_COCO1 output assigned to XBARB2_IN43 input. */
    kXBARB2_InputAdcEtcXbar1Coco2   = 44|0x200U,   /**< ADC_ETC_XBAR1_COCO2 output assigned to XBARB2_IN44 input. */
    kXBARB2_InputAdcEtcXbar1Coco3   = 45|0x200U,   /**< ADC_ETC_XBAR1_COCO3 output assigned to XBARB2_IN45 input. */
    kXBARB2_InputEnc1PosMatch       = 46|0x200U,   /**< ENC1_POS_MATCH output assigned to XBARB2_IN46 input. */
    kXBARB2_InputEnc2PosMatch       = 47|0x200U,   /**< ENC2_POS_MATCH output assigned to XBARB2_IN47 input. */
    kXBARB2_InputEnc3PosMatch       = 48|0x200U,   /**< ENC3_POS_MATCH output assigned to XBARB2_IN48 input. */
    kXBARB2_InputEnc4PosMatch       = 49|0x200U,   /**< ENC4_POS_MATCH output assigned to XBARB2_IN49 input. */
    kXBARB2_InputDmaDone0           = 50|0x200U,   /**< DMA_DONE0 output assigned to XBARB2_IN50 input. */
    kXBARB2_InputDmaDone1           = 51|0x200U,   /**< DMA_DONE1 output assigned to XBARB2_IN51 input. */
    kXBARB2_InputDmaDone2           = 52|0x200U,   /**< DMA_DONE2 output assigned to XBARB2_IN52 input. */
    kXBARB2_InputDmaDone3           = 53|0x200U,   /**< DMA_DONE3 output assigned to XBARB2_IN53 input. */
    kXBARB2_InputDmaDone4           = 54|0x200U,   /**< DMA_DONE4 output assigned to XBARB2_IN54 input. */
    kXBARB2_InputDmaDone5           = 55|0x200U,   /**< DMA_DONE5 output assigned to XBARB2_IN55 input. */
    kXBARB2_InputDmaDone6           = 56|0x200U,   /**< DMA_DONE6 output assigned to XBARB2_IN56 input. */
    kXBARB2_InputDmaDone7           = 57|0x200U,   /**< DMA_DONE7 output assigned to XBARB2_IN57 input. */
    kXBARB3_InputLogicLow           = 0|0x300U,    /**< LOGIC_LOW output assigned to XBARB3_IN0 input. */
    kXBARB3_InputLogicHigh          = 1|0x300U,    /**< LOGIC_HIGH output assigned to XBARB3_IN1 input. */
    kXBARB3_InputRESERVED2          = 2|0x300U,    /**< XBARB3_IN2 input is reserved. */
    kXBARB3_InputRESERVED3          = 3|0x300U,    /**< XBARB3_IN3 input is reserved. */
    kXBARB3_InputRESERVED4          = 4|0x300U,    /**< XBARB3_IN4 input is reserved. */
    kXBARB3_InputRESERVED5          = 5|0x300U,    /**< XBARB3_IN5 input is reserved. */
    kXBARB3_InputAcmp1Out           = 6|0x300U,    /**< ACMP1_OUT output assigned to XBARB3_IN6 input. */
    kXBARB3_InputAcmp2Out           = 7|0x300U,    /**< ACMP2_OUT output assigned to XBARB3_IN7 input. */
    kXBARB3_InputAcmp3Out           = 8|0x300U,    /**< ACMP3_OUT output assigned to XBARB3_IN8 input. */
    kXBARB3_InputAcmp4Out           = 9|0x300U,    /**< ACMP4_OUT output assigned to XBARB3_IN9 input. */
    kXBARB3_InputRESERVED10         = 10|0x300U,   /**< XBARB3_IN10 input is reserved. */
    kXBARB3_InputRESERVED11         = 11|0x300U,   /**< XBARB3_IN11 input is reserved. */
    kXBARB3_InputQtimer3Tmr0Output  = 12|0x300U,   /**< QTIMER3_TMR0_OUTPUT output assigned to XBARB3_IN12 input. */
    kXBARB3_InputQtimer3Tmr1Output  = 13|0x300U,   /**< QTIMER3_TMR1_OUTPUT output assigned to XBARB3_IN13 input. */
    kXBARB3_InputQtimer3Tmr2Output  = 14|0x300U,   /**< QTIMER3_TMR2_OUTPUT output assigned to XBARB3_IN14 input. */
    kXBARB3_InputQtimer3Tmr3Output  = 15|0x300U,   /**< QTIMER3_TMR3_OUTPUT output assigned to XBARB3_IN15 input. */
    kXBARB3_InputQtimer4Tmr0Output  = 16|0x300U,   /**< QTIMER4_TMR0_OUTPUT output assigned to XBARB3_IN16 input. */
    kXBARB3_InputQtimer4Tmr1Output  = 17|0x300U,   /**< QTIMER4_TMR1_OUTPUT output assigned to XBARB3_IN17 input. */
    kXBARB3_InputQtimer4Tmr2Output  = 18|0x300U,   /**< QTIMER4_TMR2_OUTPUT output assigned to XBARB3_IN18 input. */
    kXBARB3_InputQtimer4Tmr3Output  = 19|0x300U,   /**< QTIMER4_TMR3_OUTPUT output assigned to XBARB3_IN19 input. */
    kXBARB3_InputFlexpwm1Pwm1OutTrig01 = 20|0x300U, /**< FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBARB3_IN20 input. */
    kXBARB3_InputFlexpwm1Pwm2OutTrig01 = 21|0x300U, /**< FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBARB3_IN21 input. */
    kXBARB3_InputFlexpwm1Pwm3OutTrig01 = 22|0x300U, /**< FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBARB3_IN22 input. */
    kXBARB3_InputFlexpwm1Pwm4OutTrig01 = 23|0x300U, /**< FLEXPWM1_PWM4_OUT_TRIG0_1 output assigned to XBARB3_IN23 input. */
    kXBARB3_InputFlexpwm2Pwm1OutTrig01 = 24|0x300U, /**< FLEXPWM2_PWM1_OUT_TRIG0_1 output assigned to XBARB3_IN24 input. */
    kXBARB3_InputFlexpwm2Pwm2OutTrig01 = 25|0x300U, /**< FLEXPWM2_PWM2_OUT_TRIG0_1 output assigned to XBARB3_IN25 input. */
    kXBARB3_InputFlexpwm2Pwm3OutTrig01 = 26|0x300U, /**< FLEXPWM2_PWM3_OUT_TRIG0_1 output assigned to XBARB3_IN26 input. */
    kXBARB3_InputFlexpwm2Pwm4OutTrig01 = 27|0x300U, /**< FLEXPWM2_PWM4_OUT_TRIG0_1 output assigned to XBARB3_IN27 input. */
    kXBARB3_InputFlexpwm3Pwm1OutTrig01 = 28|0x300U, /**< FLEXPWM3_PWM1_OUT_TRIG0_1 output assigned to XBARB3_IN28 input. */
    kXBARB3_InputFlexpwm3Pwm2OutTrig01 = 29|0x300U, /**< FLEXPWM3_PWM2_OUT_TRIG0_1 output assigned to XBARB3_IN29 input. */
    kXBARB3_InputFlexpwm3Pwm3OutTrig01 = 30|0x300U, /**< FLEXPWM3_PWM3_OUT_TRIG0_1 output assigned to XBARB3_IN30 input. */
    kXBARB3_InputFlexpwm3Pwm4OutTrig01 = 31|0x300U, /**< FLEXPWM3_PWM4_OUT_TRIG0_1 output assigned to XBARB3_IN31 input. */
    kXBARB3_InputFlexpwm4Pwm1OutTrig01 = 32|0x300U, /**< FLEXPWM4_PWM1_OUT_TRIG0_1 output assigned to XBARB3_IN32 input. */
    kXBARB3_InputFlexpwm4Pwm2OutTrig01 = 33|0x300U, /**< FLEXPWM4_PWM2_OUT_TRIG0_1 output assigned to XBARB3_IN33 input. */
    kXBARB3_InputFlexpwm4Pwm3OutTrig01 = 34|0x300U, /**< FLEXPWM4_PWM3_OUT_TRIG0_1 output assigned to XBARB3_IN34 input. */
    kXBARB3_InputFlexpwm4Pwm4OutTrig01 = 35|0x300U, /**< FLEXPWM4_PWM4_OUT_TRIG0_1 output assigned to XBARB3_IN35 input. */
    kXBARB3_InputPitTrigger0        = 36|0x300U,   /**< PIT_TRIGGER0 output assigned to XBARB3_IN36 input. */
    kXBARB3_InputPitTrigger1        = 37|0x300U,   /**< PIT_TRIGGER1 output assigned to XBARB3_IN37 input. */
    kXBARB3_InputAdcEtcXbar0Coco0   = 38|0x300U,   /**< ADC_ETC_XBAR0_COCO0 output assigned to XBARB3_IN38 input. */
    kXBARB3_InputAdcEtcXbar0Coco1   = 39|0x300U,   /**< ADC_ETC_XBAR0_COCO1 output assigned to XBARB3_IN39 input. */
    kXBARB3_InputAdcEtcXbar0Coco2   = 40|0x300U,   /**< ADC_ETC_XBAR0_COCO2 output assigned to XBARB3_IN40 input. */
    kXBARB3_InputAdcEtcXbar0Coco3   = 41|0x300U,   /**< ADC_ETC_XBAR0_COCO3 output assigned to XBARB3_IN41 input. */
    kXBARB3_InputAdcEtcXbar1Coco0   = 42|0x300U,   /**< ADC_ETC_XBAR1_COCO0 output assigned to XBARB3_IN42 input. */
    kXBARB3_InputAdcEtcXbar1Coco1   = 43|0x300U,   /**< ADC_ETC_XBAR1_COCO1 output assigned to XBARB3_IN43 input. */
    kXBARB3_InputAdcEtcXbar1Coco2   = 44|0x300U,   /**< ADC_ETC_XBAR1_COCO2 output assigned to XBARB3_IN44 input. */
    kXBARB3_InputAdcEtcXbar1Coco3   = 45|0x300U,   /**< ADC_ETC_XBAR1_COCO3 output assigned to XBARB3_IN45 input. */
    kXBARB3_InputEnc1PosMatch       = 46|0x300U,   /**< ENC1_POS_MATCH output assigned to XBARB3_IN46 input. */
    kXBARB3_InputEnc2PosMatch       = 47|0x300U,   /**< ENC2_POS_MATCH output assigned to XBARB3_IN47 input. */
    kXBARB3_InputEnc3PosMatch       = 48|0x300U,   /**< ENC3_POS_MATCH output assigned to XBARB3_IN48 input. */
    kXBARB3_InputEnc4PosMatch       = 49|0x300U,   /**< ENC4_POS_MATCH output assigned to XBARB3_IN49 input. */
    kXBARB3_InputDmaDone0           = 50|0x300U,   /**< DMA_DONE0 output assigned to XBARB3_IN50 input. */
    kXBARB3_InputDmaDone1           = 51|0x300U,   /**< DMA_DONE1 output assigned to XBARB3_IN51 input. */
    kXBARB3_InputDmaDone2           = 52|0x300U,   /**< DMA_DONE2 output assigned to XBARB3_IN52 input. */
    kXBARB3_InputDmaDone3           = 53|0x300U,   /**< DMA_DONE3 output assigned to XBARB3_IN53 input. */
    kXBARB3_InputDmaDone4           = 54|0x300U,   /**< DMA_DONE4 output assigned to XBARB3_IN54 input. */
    kXBARB3_InputDmaDone5           = 55|0x300U,   /**< DMA_DONE5 output assigned to XBARB3_IN55 input. */
    kXBARB3_InputDmaDone6           = 56|0x300U,   /**< DMA_DONE6 output assigned to XBARB3_IN56 input. */
    kXBARB3_InputDmaDone7           = 57|0x300U,   /**< DMA_DONE7 output assigned to XBARB3_IN57 input. */
} xbar_input_signal_t;
#endif /* XBAR_INPUT_SIGNAL_T_ */

#if !defined(XBAR_OUTPUT_SIGNAL_T_)
#define XBAR_OUTPUT_SIGNAL_T_
typedef enum _xbar_output_signal
{
    kXBARA1_OutputDmaChMuxReq30     = 0|0x100U,    /**< XBARA1_OUT0 output assigned to DMA_CH_MUX_REQ30 */
    kXBARA1_OutputDmaChMuxReq31     = 1|0x100U,    /**< XBARA1_OUT1 output assigned to DMA_CH_MUX_REQ31 */
    kXBARA1_OutputDmaChMuxReq94     = 2|0x100U,    /**< XBARA1_OUT2 output assigned to DMA_CH_MUX_REQ94 */
    kXBARA1_OutputDmaChMuxReq95     = 3|0x100U,    /**< XBARA1_OUT3 output assigned to DMA_CH_MUX_REQ95 */
    kXBARA1_OutputIomuxXbarInout04  = 4|0x100U,    /**< XBARA1_OUT4 output assigned to IOMUX_XBAR_INOUT04 */
    kXBARA1_OutputIomuxXbarInout05  = 5|0x100U,    /**< XBARA1_OUT5 output assigned to IOMUX_XBAR_INOUT05 */
    kXBARA1_OutputIomuxXbarInout06  = 6|0x100U,    /**< XBARA1_OUT6 output assigned to IOMUX_XBAR_INOUT06 */
    kXBARA1_OutputIomuxXbarInout07  = 7|0x100U,    /**< XBARA1_OUT7 output assigned to IOMUX_XBAR_INOUT07 */
    kXBARA1_OutputIomuxXbarInout08  = 8|0x100U,    /**< XBARA1_OUT8 output assigned to IOMUX_XBAR_INOUT08 */
    kXBARA1_OutputIomuxXbarInout09  = 9|0x100U,    /**< XBARA1_OUT9 output assigned to IOMUX_XBAR_INOUT09 */
    kXBARA1_OutputIomuxXbarInout10  = 10|0x100U,   /**< XBARA1_OUT10 output assigned to IOMUX_XBAR_INOUT10 */
    kXBARA1_OutputIomuxXbarInout11  = 11|0x100U,   /**< XBARA1_OUT11 output assigned to IOMUX_XBAR_INOUT11 */
    kXBARA1_OutputIomuxXbarInout12  = 12|0x100U,   /**< XBARA1_OUT12 output assigned to IOMUX_XBAR_INOUT12 */
    kXBARA1_OutputIomuxXbarInout13  = 13|0x100U,   /**< XBARA1_OUT13 output assigned to IOMUX_XBAR_INOUT13 */
    kXBARA1_OutputIomuxXbarInout14  = 14|0x100U,   /**< XBARA1_OUT14 output assigned to IOMUX_XBAR_INOUT14 */
    kXBARA1_OutputIomuxXbarInout15  = 15|0x100U,   /**< XBARA1_OUT15 output assigned to IOMUX_XBAR_INOUT15 */
    kXBARA1_OutputIomuxXbarInout16  = 16|0x100U,   /**< XBARA1_OUT16 output assigned to IOMUX_XBAR_INOUT16 */
    kXBARA1_OutputIomuxXbarInout17  = 17|0x100U,   /**< XBARA1_OUT17 output assigned to IOMUX_XBAR_INOUT17 */
    kXBARA1_OutputIomuxXbarInout18  = 18|0x100U,   /**< XBARA1_OUT18 output assigned to IOMUX_XBAR_INOUT18 */
    kXBARA1_OutputIomuxXbarInout19  = 19|0x100U,   /**< XBARA1_OUT19 output assigned to IOMUX_XBAR_INOUT19 */
    kXBARA1_OutputAcmp1Sample       = 20|0x100U,   /**< XBARA1_OUT20 output assigned to ACMP1_SAMPLE */
    kXBARA1_OutputAcmp2Sample       = 21|0x100U,   /**< XBARA1_OUT21 output assigned to ACMP2_SAMPLE */
    kXBARA1_OutputAcmp3Sample       = 22|0x100U,   /**< XBARA1_OUT22 output assigned to ACMP3_SAMPLE */
    kXBARA1_OutputAcmp4Sample       = 23|0x100U,   /**< XBARA1_OUT23 output assigned to ACMP4_SAMPLE */
    kXBARA1_OutputRESERVED24        = 24|0x100U,   /**< XBARA1_OUT24 output is reserved. */
    kXBARA1_OutputRESERVED25        = 25|0x100U,   /**< XBARA1_OUT25 output is reserved. */
    kXBARA1_OutputFlexpwm1Exta0     = 26|0x100U,   /**< XBARA1_OUT26 output assigned to FLEXPWM1_EXTA0 */
    kXBARA1_OutputFlexpwm1Exta1     = 27|0x100U,   /**< XBARA1_OUT27 output assigned to FLEXPWM1_EXTA1 */
    kXBARA1_OutputFlexpwm1Exta2     = 28|0x100U,   /**< XBARA1_OUT28 output assigned to FLEXPWM1_EXTA2 */
    kXBARA1_OutputFlexpwm1Exta3     = 29|0x100U,   /**< XBARA1_OUT29 output assigned to FLEXPWM1_EXTA3 */
    kXBARA1_OutputFlexpwm1ExtSync0  = 30|0x100U,   /**< XBARA1_OUT30 output assigned to FLEXPWM1_EXT_SYNC0 */
    kXBARA1_OutputFlexpwm1ExtSync1  = 31|0x100U,   /**< XBARA1_OUT31 output assigned to FLEXPWM1_EXT_SYNC1 */
    kXBARA1_OutputFlexpwm1ExtSync2  = 32|0x100U,   /**< XBARA1_OUT32 output assigned to FLEXPWM1_EXT_SYNC2 */
    kXBARA1_OutputFlexpwm1ExtSync3  = 33|0x100U,   /**< XBARA1_OUT33 output assigned to FLEXPWM1_EXT_SYNC3 */
    kXBARA1_OutputFlexpwm1ExtClk    = 34|0x100U,   /**< XBARA1_OUT34 output assigned to FLEXPWM1_EXT_CLK */
    kXBARA1_OutputFlexpwm1Fault0    = 35|0x100U,   /**< XBARA1_OUT35 output assigned to FLEXPWM1_FAULT0 */
    kXBARA1_OutputFlexpwm1Fault1    = 36|0x100U,   /**< XBARA1_OUT36 output assigned to FLEXPWM1_FAULT1 */
    kXBARA1_OutputFlexpwm1234Fault2 = 37|0x100U,   /**< XBARA1_OUT37 output assigned to FLEXPWM1_2_3_4_FAULT2 */
    kXBARA1_OutputFlexpwm1234Fault3 = 38|0x100U,   /**< XBARA1_OUT38 output assigned to FLEXPWM1_2_3_4_FAULT3 */
    kXBARA1_OutputFlexpwm1ExtForce  = 39|0x100U,   /**< XBARA1_OUT39 output assigned to FLEXPWM1_EXT_FORCE */
    kXBARA1_OutputFlexpwm234Exta0   = 40|0x100U,   /**< XBARA1_OUT40 output assigned to FLEXPWM2_3_4_EXTA0 */
    kXBARA1_OutputFlexpwm234Exta1   = 41|0x100U,   /**< XBARA1_OUT41 output assigned to FLEXPWM2_3_4_EXTA1 */
    kXBARA1_OutputFlexpwm234Exta2   = 42|0x100U,   /**< XBARA1_OUT42 output assigned to FLEXPWM2_3_4_EXTA2 */
    kXBARA1_OutputFlexpwm234Exta3   = 43|0x100U,   /**< XBARA1_OUT43 output assigned to FLEXPWM2_3_4_EXTA3 */
    kXBARA1_OutputFlexpwm2ExtSync0  = 44|0x100U,   /**< XBARA1_OUT44 output assigned to FLEXPWM2_EXT_SYNC0 */
    kXBARA1_OutputFlexpwm2ExtSync1  = 45|0x100U,   /**< XBARA1_OUT45 output assigned to FLEXPWM2_EXT_SYNC1 */
    kXBARA1_OutputFlexpwm2ExtSync2  = 46|0x100U,   /**< XBARA1_OUT46 output assigned to FLEXPWM2_EXT_SYNC2 */
    kXBARA1_OutputFlexpwm2ExtSync3  = 47|0x100U,   /**< XBARA1_OUT47 output assigned to FLEXPWM2_EXT_SYNC3 */
    kXBARA1_OutputFlexpwm234ExtClk  = 48|0x100U,   /**< XBARA1_OUT48 output assigned to FLEXPWM2_3_4_EXT_CLK */
    kXBARA1_OutputFlexpwm2Fault0    = 49|0x100U,   /**< XBARA1_OUT49 output assigned to FLEXPWM2_FAULT0 */
    kXBARA1_OutputFlexpwm2Fault1    = 50|0x100U,   /**< XBARA1_OUT50 output assigned to FLEXPWM2_FAULT1 */
    kXBARA1_OutputFlexpwm2ExtForce  = 51|0x100U,   /**< XBARA1_OUT51 output assigned to FLEXPWM2_EXT_FORCE */
    kXBARA1_OutputFlexpwm3ExtSync0  = 52|0x100U,   /**< XBARA1_OUT52 output assigned to FLEXPWM3_EXT_SYNC0 */
    kXBARA1_OutputFlexpwm3ExtSync1  = 53|0x100U,   /**< XBARA1_OUT53 output assigned to FLEXPWM3_EXT_SYNC1 */
    kXBARA1_OutputFlexpwm3ExtSync2  = 54|0x100U,   /**< XBARA1_OUT54 output assigned to FLEXPWM3_EXT_SYNC2 */
    kXBARA1_OutputFlexpwm3ExtSync3  = 55|0x100U,   /**< XBARA1_OUT55 output assigned to FLEXPWM3_EXT_SYNC3 */
    kXBARA1_OutputFlexpwm3Fault0    = 56|0x100U,   /**< XBARA1_OUT56 output assigned to FLEXPWM3_FAULT0 */
    kXBARA1_OutputFlexpwm3Fault1    = 57|0x100U,   /**< XBARA1_OUT57 output assigned to FLEXPWM3_FAULT1 */
    kXBARA1_OutputFlexpwm3ExtForce  = 58|0x100U,   /**< XBARA1_OUT58 output assigned to FLEXPWM3_EXT_FORCE */
    kXBARA1_OutputFlexpwm4ExtSync0  = 59|0x100U,   /**< XBARA1_OUT59 output assigned to FLEXPWM4_EXT_SYNC0 */
    kXBARA1_OutputFlexpwm4ExtSync1  = 60|0x100U,   /**< XBARA1_OUT60 output assigned to FLEXPWM4_EXT_SYNC1 */
    kXBARA1_OutputFlexpwm4ExtSync2  = 61|0x100U,   /**< XBARA1_OUT61 output assigned to FLEXPWM4_EXT_SYNC2 */
    kXBARA1_OutputFlexpwm4ExtSync3  = 62|0x100U,   /**< XBARA1_OUT62 output assigned to FLEXPWM4_EXT_SYNC3 */
    kXBARA1_OutputFlexpwm4Fault0    = 63|0x100U,   /**< XBARA1_OUT63 output assigned to FLEXPWM4_FAULT0 */
    kXBARA1_OutputFlexpwm4Fault1    = 64|0x100U,   /**< XBARA1_OUT64 output assigned to FLEXPWM4_FAULT1 */
    kXBARA1_OutputFlexpwm4ExtForce  = 65|0x100U,   /**< XBARA1_OUT65 output assigned to FLEXPWM4_EXT_FORCE */
    kXBARA1_OutputEnc1PhaseAInput   = 66|0x100U,   /**< XBARA1_OUT66 output assigned to ENC1_PHASE_A_INPUT */
    kXBARA1_OutputEnc1PhaseBInput   = 67|0x100U,   /**< XBARA1_OUT67 output assigned to ENC1_PHASE_B_INPUT */
    kXBARA1_OutputEnc1Index         = 68|0x100U,   /**< XBARA1_OUT68 output assigned to ENC1_INDEX */
    kXBARA1_OutputEnc1Home          = 69|0x100U,   /**< XBARA1_OUT69 output assigned to ENC1_HOME */
    kXBARA1_OutputEnc1Trigger       = 70|0x100U,   /**< XBARA1_OUT70 output assigned to ENC1_TRIGGER */
    kXBARA1_OutputEnc2PhaseAInput   = 71|0x100U,   /**< XBARA1_OUT71 output assigned to ENC2_PHASE_A_INPUT */
    kXBARA1_OutputEnc2PhaseBInput   = 72|0x100U,   /**< XBARA1_OUT72 output assigned to ENC2_PHASE_B_INPUT */
    kXBARA1_OutputEnc2Index         = 73|0x100U,   /**< XBARA1_OUT73 output assigned to ENC2_INDEX */
    kXBARA1_OutputEnc2Home          = 74|0x100U,   /**< XBARA1_OUT74 output assigned to ENC2_HOME */
    kXBARA1_OutputEnc2Trigger       = 75|0x100U,   /**< XBARA1_OUT75 output assigned to ENC2_TRIGGER */
    kXBARA1_OutputEnc3PhaseAInput   = 76|0x100U,   /**< XBARA1_OUT76 output assigned to ENC3_PHASE_A_INPUT */
    kXBARA1_OutputEnc3PhaseBInput   = 77|0x100U,   /**< XBARA1_OUT77 output assigned to ENC3_PHASE_B_INPUT */
    kXBARA1_OutputEnc3Index         = 78|0x100U,   /**< XBARA1_OUT78 output assigned to ENC3_INDEX */
    kXBARA1_OutputEnc3Home          = 79|0x100U,   /**< XBARA1_OUT79 output assigned to ENC3_HOME */
    kXBARA1_OutputEnc3Trigger       = 80|0x100U,   /**< XBARA1_OUT80 output assigned to ENC3_TRIGGER */
    kXBARA1_OutputEnc4PhaseAInput   = 81|0x100U,   /**< XBARA1_OUT81 output assigned to ENC4_PHASE_A_INPUT */
    kXBARA1_OutputEnc4PhaseBInput   = 82|0x100U,   /**< XBARA1_OUT82 output assigned to ENC4_PHASE_B_INPUT */
    kXBARA1_OutputEnc4Index         = 83|0x100U,   /**< XBARA1_OUT83 output assigned to ENC4_INDEX */
    kXBARA1_OutputEnc4Home          = 84|0x100U,   /**< XBARA1_OUT84 output assigned to ENC4_HOME */
    kXBARA1_OutputEnc4Trigger       = 85|0x100U,   /**< XBARA1_OUT85 output assigned to ENC4_TRIGGER */
    kXBARA1_OutputQtimer1Tmr0Input  = 86|0x100U,   /**< XBARA1_OUT86 output assigned to QTIMER1_TMR0_INPUT */
    kXBARA1_OutputQtimer1Tmr1Input  = 87|0x100U,   /**< XBARA1_OUT87 output assigned to QTIMER1_TMR1_INPUT */
    kXBARA1_OutputQtimer1Tmr2Input  = 88|0x100U,   /**< XBARA1_OUT88 output assigned to QTIMER1_TMR2_INPUT */
    kXBARA1_OutputQtimer1Tmr3Input  = 89|0x100U,   /**< XBARA1_OUT89 output assigned to QTIMER1_TMR3_INPUT */
    kXBARA1_OutputQtimer2Tmr0Input  = 90|0x100U,   /**< XBARA1_OUT90 output assigned to QTIMER2_TMR0_INPUT */
    kXBARA1_OutputQtimer2Tmr1Input  = 91|0x100U,   /**< XBARA1_OUT91 output assigned to QTIMER2_TMR1_INPUT */
    kXBARA1_OutputQtimer2Tmr2Input  = 92|0x100U,   /**< XBARA1_OUT92 output assigned to QTIMER2_TMR2_INPUT */
    kXBARA1_OutputQtimer2Tmr3Input  = 93|0x100U,   /**< XBARA1_OUT93 output assigned to QTIMER2_TMR3_INPUT */
    kXBARA1_OutputQtimer3Tmr0Input  = 94|0x100U,   /**< XBARA1_OUT94 output assigned to QTIMER3_TMR0_INPUT */
    kXBARA1_OutputQtimer3Tmr1Input  = 95|0x100U,   /**< XBARA1_OUT95 output assigned to QTIMER3_TMR1_INPUT */
    kXBARA1_OutputQtimer3Tmr2Input  = 96|0x100U,   /**< XBARA1_OUT96 output assigned to QTIMER3_TMR2_INPUT */
    kXBARA1_OutputQtimer3Tmr3Input  = 97|0x100U,   /**< XBARA1_OUT97 output assigned to QTIMER3_TMR3_INPUT */
    kXBARA1_OutputQtimer4Tmr0Input  = 98|0x100U,   /**< XBARA1_OUT98 output assigned to QTIMER4_TMR0_INPUT */
    kXBARA1_OutputQtimer4Tmr1Input  = 99|0x100U,   /**< XBARA1_OUT99 output assigned to QTIMER4_TMR1_INPUT */
    kXBARA1_OutputQtimer4Tmr2Input  = 100|0x100U,  /**< XBARA1_OUT100 output assigned to QTIMER4_TMR2_INPUT */
    kXBARA1_OutputQtimer4Tmr3Input  = 101|0x100U,  /**< XBARA1_OUT101 output assigned to QTIMER4_TMR3_INPUT */
    kXBARA1_OutputEwmEwmIn          = 102|0x100U,  /**< XBARA1_OUT102 output assigned to EWM_EWM_IN */
    kXBARA1_OutputAdcEtcXbar0Trig0  = 103|0x100U,  /**< XBARA1_OUT103 output assigned to ADC_ETC_XBAR0_TRIG0 */
    kXBARA1_OutputAdcEtcXbar0Trig1  = 104|0x100U,  /**< XBARA1_OUT104 output assigned to ADC_ETC_XBAR0_TRIG1 */
    kXBARA1_OutputAdcEtcXbar0Trig2  = 105|0x100U,  /**< XBARA1_OUT105 output assigned to ADC_ETC_XBAR0_TRIG2 */
    kXBARA1_OutputAdcEtcXbar0Trig3  = 106|0x100U,  /**< XBARA1_OUT106 output assigned to ADC_ETC_XBAR0_TRIG3 */
    kXBARA1_OutputAdcEtcXbar1Trig0  = 107|0x100U,  /**< XBARA1_OUT107 output assigned to ADC_ETC_XBAR1_TRIG0 */
    kXBARA1_OutputAdcEtcXbar1Trig1  = 108|0x100U,  /**< XBARA1_OUT108 output assigned to ADC_ETC_XBAR1_TRIG1 */
    kXBARA1_OutputAdcEtcXbar1Trig2  = 109|0x100U,  /**< XBARA1_OUT109 output assigned to ADC_ETC_XBAR1_TRIG2 */
    kXBARA1_OutputAdcEtcXbar1Trig3  = 110|0x100U,  /**< XBARA1_OUT110 output assigned to ADC_ETC_XBAR1_TRIG3 */
    kXBARA1_OutputLpi2c1TrgInput    = 111|0x100U,  /**< XBARA1_OUT111 output assigned to LPI2C1_TRG_INPUT */
    kXBARA1_OutputLpi2c2TrgInput    = 112|0x100U,  /**< XBARA1_OUT112 output assigned to LPI2C2_TRG_INPUT */
    kXBARA1_OutputLpi2c3TrgInput    = 113|0x100U,  /**< XBARA1_OUT113 output assigned to LPI2C3_TRG_INPUT */
    kXBARA1_OutputLpi2c4TrgInput    = 114|0x100U,  /**< XBARA1_OUT114 output assigned to LPI2C4_TRG_INPUT */
    kXBARA1_OutputLpspi1TrgInput    = 115|0x100U,  /**< XBARA1_OUT115 output assigned to LPSPI1_TRG_INPUT */
    kXBARA1_OutputLpspi2TrgInput    = 116|0x100U,  /**< XBARA1_OUT116 output assigned to LPSPI2_TRG_INPUT */
    kXBARA1_OutputLpspi3TrgInput    = 117|0x100U,  /**< XBARA1_OUT117 output assigned to LPSPI3_TRG_INPUT */
    kXBARA1_OutputLpspi4TrgInput    = 118|0x100U,  /**< XBARA1_OUT118 output assigned to LPSPI4_TRG_INPUT */
    kXBARA1_OutputLpuart1TrgInput   = 119|0x100U,  /**< XBARA1_OUT119 output assigned to LPUART1_TRG_INPUT */
    kXBARA1_OutputLpuart2TrgInput   = 120|0x100U,  /**< XBARA1_OUT120 output assigned to LPUART2_TRG_INPUT */
    kXBARA1_OutputLpuart3TrgInput   = 121|0x100U,  /**< XBARA1_OUT121 output assigned to LPUART3_TRG_INPUT */
    kXBARA1_OutputLpuart4TrgInput   = 122|0x100U,  /**< XBARA1_OUT122 output assigned to LPUART4_TRG_INPUT */
    kXBARA1_OutputLpuart5TrgInput   = 123|0x100U,  /**< XBARA1_OUT123 output assigned to LPUART5_TRG_INPUT */
    kXBARA1_OutputLpuart6TrgInput   = 124|0x100U,  /**< XBARA1_OUT124 output assigned to LPUART6_TRG_INPUT */
    kXBARA1_OutputLpuart7TrgInput   = 125|0x100U,  /**< XBARA1_OUT125 output assigned to LPUART7_TRG_INPUT */
    kXBARA1_OutputLpuart8TrgInput   = 126|0x100U,  /**< XBARA1_OUT126 output assigned to LPUART8_TRG_INPUT */
    kXBARA1_OutputFlexio1TriggerIn0 = 127|0x100U,  /**< XBARA1_OUT127 output assigned to FLEXIO1_TRIGGER_IN0 */
    kXBARA1_OutputFlexio1TriggerIn1 = 128|0x100U,  /**< XBARA1_OUT128 output assigned to FLEXIO1_TRIGGER_IN1 */
    kXBARA1_OutputFlexio2TriggerIn0 = 129|0x100U,  /**< XBARA1_OUT129 output assigned to FLEXIO2_TRIGGER_IN0 */
    kXBARA1_OutputFlexio2TriggerIn1 = 130|0x100U,  /**< XBARA1_OUT130 output assigned to FLEXIO2_TRIGGER_IN1 */
    kXBARB2_OutputAoi1In00          = 0|0x200U,    /**< XBARB2_OUT0 output assigned to AOI1_IN00 */
    kXBARB2_OutputAoi1In01          = 1|0x200U,    /**< XBARB2_OUT1 output assigned to AOI1_IN01 */
    kXBARB2_OutputAoi1In02          = 2|0x200U,    /**< XBARB2_OUT2 output assigned to AOI1_IN02 */
    kXBARB2_OutputAoi1In03          = 3|0x200U,    /**< XBARB2_OUT3 output assigned to AOI1_IN03 */
    kXBARB2_OutputAoi1In04          = 4|0x200U,    /**< XBARB2_OUT4 output assigned to AOI1_IN04 */
    kXBARB2_OutputAoi1In05          = 5|0x200U,    /**< XBARB2_OUT5 output assigned to AOI1_IN05 */
    kXBARB2_OutputAoi1In06          = 6|0x200U,    /**< XBARB2_OUT6 output assigned to AOI1_IN06 */
    kXBARB2_OutputAoi1In07          = 7|0x200U,    /**< XBARB2_OUT7 output assigned to AOI1_IN07 */
    kXBARB2_OutputAoi1In08          = 8|0x200U,    /**< XBARB2_OUT8 output assigned to AOI1_IN08 */
    kXBARB2_OutputAoi1In09          = 9|0x200U,    /**< XBARB2_OUT9 output assigned to AOI1_IN09 */
    kXBARB2_OutputAoi1In10          = 10|0x200U,   /**< XBARB2_OUT10 output assigned to AOI1_IN10 */
    kXBARB2_OutputAoi1In11          = 11|0x200U,   /**< XBARB2_OUT11 output assigned to AOI1_IN11 */
    kXBARB2_OutputAoi1In12          = 12|0x200U,   /**< XBARB2_OUT12 output assigned to AOI1_IN12 */
    kXBARB2_OutputAoi1In13          = 13|0x200U,   /**< XBARB2_OUT13 output assigned to AOI1_IN13 */
    kXBARB2_OutputAoi1In14          = 14|0x200U,   /**< XBARB2_OUT14 output assigned to AOI1_IN14 */
    kXBARB2_OutputAoi1In15          = 15|0x200U,   /**< XBARB2_OUT15 output assigned to AOI1_IN15 */
    kXBARB3_OutputAoi2In00          = 0|0x300U,    /**< XBARB3_OUT0 output assigned to AOI2_IN00 */
    kXBARB3_OutputAoi2In01          = 1|0x300U,    /**< XBARB3_OUT1 output assigned to AOI2_IN01 */
    kXBARB3_OutputAoi2In02          = 2|0x300U,    /**< XBARB3_OUT2 output assigned to AOI2_IN02 */
    kXBARB3_OutputAoi2In03          = 3|0x300U,    /**< XBARB3_OUT3 output assigned to AOI2_IN03 */
    kXBARB3_OutputAoi2In04          = 4|0x300U,    /**< XBARB3_OUT4 output assigned to AOI2_IN04 */
    kXBARB3_OutputAoi2In05          = 5|0x300U,    /**< XBARB3_OUT5 output assigned to AOI2_IN05 */
    kXBARB3_OutputAoi2In06          = 6|0x300U,    /**< XBARB3_OUT6 output assigned to AOI2_IN06 */
    kXBARB3_OutputAoi2In07          = 7|0x300U,    /**< XBARB3_OUT7 output assigned to AOI2_IN07 */
    kXBARB3_OutputAoi2In08          = 8|0x300U,    /**< XBARB3_OUT8 output assigned to AOI2_IN08 */
    kXBARB3_OutputAoi2In09          = 9|0x300U,    /**< XBARB3_OUT9 output assigned to AOI2_IN09 */
    kXBARB3_OutputAoi2In10          = 10|0x300U,   /**< XBARB3_OUT10 output assigned to AOI2_IN10 */
    kXBARB3_OutputAoi2In11          = 11|0x300U,   /**< XBARB3_OUT11 output assigned to AOI2_IN11 */
    kXBARB3_OutputAoi2In12          = 12|0x300U,   /**< XBARB3_OUT12 output assigned to AOI2_IN12 */
    kXBARB3_OutputAoi2In13          = 13|0x300U,   /**< XBARB3_OUT13 output assigned to AOI2_IN13 */
    kXBARB3_OutputAoi2In14          = 14|0x300U,   /**< XBARB3_OUT14 output assigned to AOI2_IN14 */
    kXBARB3_OutputAoi2In15          = 15|0x300U,   /**< XBARB3_OUT15 output assigned to AOI2_IN15 */
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

