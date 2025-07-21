/*
** ###################################################################
**     Processors:          MIMXRT1015CAF4A
**                          MIMXRT1015CAF4B
**                          MIMXRT1015DAF5A
**                          MIMXRT1015DAF5B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XBARA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2018-11-05)
**         Initial version.
**     - rev. 1.0 (2019-01-18)
**         Rev.0 Header GA
**     - rev. 1.1 (2019-02-20)
**         Update register SRC_SRSR's bitfield LOCKUP_SYSRESETREQ to LOCKUP.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1015RM Rev.1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_XBARA.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XBARA
 *
 * CMSIS Peripheral Access Layer for XBARA
 */

#if !defined(PERI_XBARA_H_)
#define PERI_XBARA_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1015CAF4A) || defined(CPU_MIMXRT1015CAF4B) || defined(CPU_MIMXRT1015DAF5A) || defined(CPU_MIMXRT1015DAF5B))
#include "MIMXRT1015_COMMON.h"
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
    kXBARA1_InputRESERVED11         = 11|0x100U,   /**< XBARA_IN11 input is reserved. */
    kXBARA1_InputRESERVED12         = 12|0x100U,   /**< XBARA_IN12 input is reserved. */
    kXBARA1_InputRESERVED13         = 13|0x100U,   /**< XBARA_IN13 input is reserved. */
    kXBARA1_InputRESERVED14         = 14|0x100U,   /**< XBARA_IN14 input is reserved. */
    kXBARA1_InputRESERVED15         = 15|0x100U,   /**< XBARA_IN15 input is reserved. */
    kXBARA1_InputIomuxXbarInout16   = 16|0x100U,   /**< IOMUX_XBAR_INOUT16 output assigned to XBARA_IN16 input. */
    kXBARA1_InputIomuxXbarInout17   = 17|0x100U,   /**< IOMUX_XBAR_INOUT17 output assigned to XBARA_IN17 input. */
    kXBARA1_InputRESERVED18         = 18|0x100U,   /**< XBARA_IN18 input is reserved. */
    kXBARA1_InputRESERVED19         = 19|0x100U,   /**< XBARA_IN19 input is reserved. */
    kXBARA1_InputRESERVED20         = 20|0x100U,   /**< XBARA_IN20 input is reserved. */
    kXBARA1_InputRESERVED21         = 21|0x100U,   /**< XBARA_IN21 input is reserved. */
    kXBARA1_InputRESERVED22         = 22|0x100U,   /**< XBARA_IN22 input is reserved. */
    kXBARA1_InputRESERVED23         = 23|0x100U,   /**< XBARA_IN23 input is reserved. */
    kXBARA1_InputRESERVED24         = 24|0x100U,   /**< XBARA_IN24 input is reserved. */
    kXBARA1_InputRESERVED25         = 25|0x100U,   /**< XBARA_IN25 input is reserved. */
    kXBARA1_InputRESERVED26         = 26|0x100U,   /**< XBARA_IN26 input is reserved. */
    kXBARA1_InputRESERVED27         = 27|0x100U,   /**< XBARA_IN27 input is reserved. */
    kXBARA1_InputRESERVED28         = 28|0x100U,   /**< XBARA_IN28 input is reserved. */
    kXBARA1_InputRESERVED29         = 29|0x100U,   /**< XBARA_IN29 input is reserved. */
    kXBARA1_InputRESERVED30         = 30|0x100U,   /**< XBARA_IN30 input is reserved. */
    kXBARA1_InputRESERVED31         = 31|0x100U,   /**< XBARA_IN31 input is reserved. */
    kXBARA1_InputQtimer1Tmr0        = 32|0x100U,   /**< QTIMER1_TMR0 output assigned to XBARA_IN32 input. */
    kXBARA1_InputQtimer1Tmr1        = 33|0x100U,   /**< QTIMER1_TMR1 output assigned to XBARA_IN33 input. */
    kXBARA1_InputQtimer1Tmr2        = 34|0x100U,   /**< QTIMER1_TMR2 output assigned to XBARA_IN34 input. */
    kXBARA1_InputQtimer1Tmr3        = 35|0x100U,   /**< QTIMER1_TMR3 output assigned to XBARA_IN35 input. */
    kXBARA1_InputRESERVED36         = 36|0x100U,   /**< XBARA_IN36 input is reserved. */
    kXBARA1_InputRESERVED37         = 37|0x100U,   /**< XBARA_IN37 input is reserved. */
    kXBARA1_InputRESERVED38         = 38|0x100U,   /**< XBARA_IN38 input is reserved. */
    kXBARA1_InputRESERVED39         = 39|0x100U,   /**< XBARA_IN39 input is reserved. */
    kXBARA1_InputFlexpwm1Pwm1OutTrig01 = 40|0x100U, /**< FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBARA_IN40 input. */
    kXBARA1_InputFlexpwm1Pwm2OutTrig01 = 41|0x100U, /**< FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBARA_IN41 input. */
    kXBARA1_InputFlexpwm1Pwm3OutTrig01 = 42|0x100U, /**< FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBARA_IN42 input. */
    kXBARA1_InputFlexpwm1Pwm4OutTrig01 = 43|0x100U, /**< FLEXPWM1_PWM4_OUT_TRIG0_1 output assigned to XBARA_IN43 input. */
    kXBARA1_InputRESERVED44         = 44|0x100U,   /**< XBARA_IN44 input is reserved. */
    kXBARA1_InputRESERVED45         = 45|0x100U,   /**< XBARA_IN45 input is reserved. */
    kXBARA1_InputRESERVED46         = 46|0x100U,   /**< XBARA_IN46 input is reserved. */
    kXBARA1_InputRESERVED47         = 47|0x100U,   /**< XBARA_IN47 input is reserved. */
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
    kXBARA1_InputRESERVED61         = 61|0x100U,   /**< XBARA_IN61 input is reserved. */
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
    kXBARB2_InputRESERVED6          = 6|0x200U,    /**< XBARB_IN6 input is reserved. */
    kXBARB2_InputRESERVED7          = 7|0x200U,    /**< XBARB_IN7 input is reserved. */
    kXBARB2_InputRESERVED8          = 8|0x200U,    /**< XBARB_IN8 input is reserved. */
    kXBARB2_InputRESERVED9          = 9|0x200U,    /**< XBARB_IN9 input is reserved. */
    kXBARB2_InputRESERVED10         = 10|0x200U,   /**< XBARB_IN10 input is reserved. */
    kXBARB2_InputRESERVED11         = 11|0x200U,   /**< XBARB_IN11 input is reserved. */
    kXBARB2_InputQtimer1Tmr0        = 12|0x200U,   /**< QTIMER1_TMR0 output assigned to XBARB_IN12 input. */
    kXBARB2_InputQtimer1Tmr1        = 13|0x200U,   /**< QTIMER1_TMR1 output assigned to XBARB_IN13 input. */
    kXBARB2_InputQtimer1Tmr2        = 14|0x200U,   /**< QTIMER1_TMR2 output assigned to XBARB_IN14 input. */
    kXBARB2_InputQtimer1Tmr3        = 15|0x200U,   /**< QTIMER1_TMR3 output assigned to XBARB_IN15 input. */
    kXBARB2_InputRESERVED16         = 16|0x200U,   /**< XBARB_IN16 input is reserved. */
    kXBARB2_InputRESERVED17         = 17|0x200U,   /**< XBARB_IN17 input is reserved. */
    kXBARB2_InputRESERVED18         = 18|0x200U,   /**< XBARB_IN18 input is reserved. */
    kXBARB2_InputRESERVED19         = 19|0x200U,   /**< XBARB_IN19 input is reserved. */
    kXBARB2_InputFlexpwm1Pwm1OutTrig01 = 20|0x200U, /**< FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBARB_IN20 input. */
    kXBARB2_InputFlexpwm1Pwm2OutTrig01 = 21|0x200U, /**< FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBARB_IN21 input. */
    kXBARB2_InputFlexpwm1Pwm3OutTrig01 = 22|0x200U, /**< FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBARB_IN22 input. */
    kXBARB2_InputFlexpwm1Pwm4OutTrig01 = 23|0x200U, /**< FLEXPWM1_PWM4_OUT_TRIG0_1 output assigned to XBARB_IN23 input. */
    kXBARB2_InputRESERVED24         = 24|0x200U,   /**< XBARB_IN24 input is reserved. */
    kXBARB2_InputRESERVED25         = 25|0x200U,   /**< XBARB_IN25 input is reserved. */
    kXBARB2_InputRESERVED26         = 26|0x200U,   /**< XBARB_IN26 input is reserved. */
    kXBARB2_InputRESERVED27         = 27|0x200U,   /**< XBARB_IN27 input is reserved. */
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
    kXBARB2_InputRESERVED47         = 47|0x200U,   /**< XBARB_IN47 input is reserved. */
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
    kXBARA1_OutputRESERVED0         = 0|0x100U,    /**< XBARA_OUT0 output is reserved. */
    kXBARA1_OutputRESERVED1         = 1|0x100U,    /**< XBARA_OUT1 output is reserved. */
    kXBARA1_OutputRESERVED2         = 2|0x100U,    /**< XBARA_OUT2 output is reserved. */
    kXBARA1_OutputRESERVED3         = 3|0x100U,    /**< XBARA_OUT3 output is reserved. */
    kXBARA1_OutputRESERVED4         = 4|0x100U,    /**< XBARA_OUT4 output is reserved. */
    kXBARA1_OutputRESERVED5         = 5|0x100U,    /**< XBARA_OUT5 output is reserved. */
    kXBARA1_OutputRESERVED6         = 6|0x100U,    /**< XBARA_OUT6 output is reserved. */
    kXBARA1_OutputRESERVED7         = 7|0x100U,    /**< XBARA_OUT7 output is reserved. */
    kXBARA1_OutputRESERVED8         = 8|0x100U,    /**< XBARA_OUT8 output is reserved. */
    kXBARA1_OutputRESERVED9         = 9|0x100U,    /**< XBARA_OUT9 output is reserved. */
    kXBARA1_OutputRESERVED10        = 10|0x100U,   /**< XBARA_OUT10 output is reserved. */
    kXBARA1_OutputRESERVED11        = 11|0x100U,   /**< XBARA_OUT11 output is reserved. */
    kXBARA1_OutputRESERVED12        = 12|0x100U,   /**< XBARA_OUT12 output is reserved. */
    kXBARA1_OutputRESERVED13        = 13|0x100U,   /**< XBARA_OUT13 output is reserved. */
    kXBARA1_OutputRESERVED14        = 14|0x100U,   /**< XBARA_OUT14 output is reserved. */
    kXBARA1_OutputRESERVED15        = 15|0x100U,   /**< XBARA_OUT15 output is reserved. */
    kXBARA1_OutputRESERVED16        = 16|0x100U,   /**< XBARA_OUT16 output is reserved. */
    kXBARA1_OutputRESERVED17        = 17|0x100U,   /**< XBARA_OUT17 output is reserved. */
    kXBARA1_OutputRESERVED18        = 18|0x100U,   /**< XBARA_OUT18 output is reserved. */
    kXBARA1_OutputRESERVED19        = 19|0x100U,   /**< XBARA_OUT19 output is reserved. */
    kXBARA1_OutputRESERVED20        = 20|0x100U,   /**< XBARA_OUT20 output is reserved. */
    kXBARA1_OutputRESERVED21        = 21|0x100U,   /**< XBARA_OUT21 output is reserved. */
    kXBARA1_OutputRESERVED22        = 22|0x100U,   /**< XBARA_OUT22 output is reserved. */
    kXBARA1_OutputRESERVED23        = 23|0x100U,   /**< XBARA_OUT23 output is reserved. */
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
    kXBARA1_OutputFlexpwm1Fault2    = 37|0x100U,   /**< XBARA_OUT37 output assigned to FLEXPWM1_FAULT2 */
    kXBARA1_OutputFlexpwm1Fault3    = 38|0x100U,   /**< XBARA_OUT38 output assigned to FLEXPWM1_FAULT3 */
    kXBARA1_OutputFlexpwm1ExtForce  = 39|0x100U,   /**< XBARA_OUT39 output assigned to FLEXPWM1_EXT_FORCE */
    kXBARA1_OutputRESERVED40        = 40|0x100U,   /**< XBARA_OUT40 output is reserved. */
    kXBARA1_OutputRESERVED41        = 41|0x100U,   /**< XBARA_OUT41 output is reserved. */
    kXBARA1_OutputRESERVED42        = 42|0x100U,   /**< XBARA_OUT42 output is reserved. */
    kXBARA1_OutputRESERVED43        = 43|0x100U,   /**< XBARA_OUT43 output is reserved. */
    kXBARA1_OutputRESERVED44        = 44|0x100U,   /**< XBARA_OUT44 output is reserved. */
    kXBARA1_OutputRESERVED45        = 45|0x100U,   /**< XBARA_OUT45 output is reserved. */
    kXBARA1_OutputRESERVED46        = 46|0x100U,   /**< XBARA_OUT46 output is reserved. */
    kXBARA1_OutputRESERVED47        = 47|0x100U,   /**< XBARA_OUT47 output is reserved. */
    kXBARA1_OutputRESERVED48        = 48|0x100U,   /**< XBARA_OUT48 output is reserved. */
    kXBARA1_OutputRESERVED49        = 49|0x100U,   /**< XBARA_OUT49 output is reserved. */
    kXBARA1_OutputRESERVED50        = 50|0x100U,   /**< XBARA_OUT50 output is reserved. */
    kXBARA1_OutputRESERVED51        = 51|0x100U,   /**< XBARA_OUT51 output is reserved. */
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
    kXBARA1_OutputRESERVED71        = 71|0x100U,   /**< XBARA_OUT71 output is reserved. */
    kXBARA1_OutputRESERVED72        = 72|0x100U,   /**< XBARA_OUT72 output is reserved. */
    kXBARA1_OutputRESERVED73        = 73|0x100U,   /**< XBARA_OUT73 output is reserved. */
    kXBARA1_OutputRESERVED74        = 74|0x100U,   /**< XBARA_OUT74 output is reserved. */
    kXBARA1_OutputRESERVED75        = 75|0x100U,   /**< XBARA_OUT75 output is reserved. */
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
    kXBARA1_OutputRESERVED90        = 90|0x100U,   /**< XBARA_OUT90 output is reserved. */
    kXBARA1_OutputRESERVED91        = 91|0x100U,   /**< XBARA_OUT91 output is reserved. */
    kXBARA1_OutputRESERVED92        = 92|0x100U,   /**< XBARA_OUT92 output is reserved. */
    kXBARA1_OutputRESERVED93        = 93|0x100U,   /**< XBARA_OUT93 output is reserved. */
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
    kXBARA1_OutputRESERVED113       = 113|0x100U,  /**< XBARA_OUT113 output is reserved. */
    kXBARA1_OutputRESERVED114       = 114|0x100U,  /**< XBARA_OUT114 output is reserved. */
    kXBARA1_OutputLpspi1TrgInput    = 115|0x100U,  /**< XBARA_OUT115 output assigned to LPSPI1_TRG_INPUT */
    kXBARA1_OutputLpspi2TrgInput    = 116|0x100U,  /**< XBARA_OUT116 output assigned to LPSPI2_TRG_INPUT */
    kXBARA1_OutputRESERVED117       = 117|0x100U,  /**< XBARA_OUT117 output is reserved. */
    kXBARA1_OutputRESERVED118       = 118|0x100U,  /**< XBARA_OUT118 output is reserved. */
    kXBARA1_OutputLpuart1TrgInput   = 119|0x100U,  /**< XBARA_OUT119 output assigned to LPUART1_TRG_INPUT */
    kXBARA1_OutputLpuart2TrgInput   = 120|0x100U,  /**< XBARA_OUT120 output assigned to LPUART2_TRG_INPUT */
    kXBARA1_OutputLpuart3TrgInput   = 121|0x100U,  /**< XBARA_OUT121 output assigned to LPUART3_TRG_INPUT */
    kXBARA1_OutputLpuart4TrgInput   = 122|0x100U,  /**< XBARA_OUT122 output assigned to LPUART4_TRG_INPUT */
    kXBARA1_OutputRESERVED123       = 123|0x100U,  /**< XBARA_OUT123 output is reserved. */
    kXBARA1_OutputRESERVED124       = 124|0x100U,  /**< XBARA_OUT124 output is reserved. */
    kXBARA1_OutputRESERVED125       = 125|0x100U,  /**< XBARA_OUT125 output is reserved. */
    kXBARA1_OutputRESERVED126       = 126|0x100U,  /**< XBARA_OUT126 output is reserved. */
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
   -- XBARA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARA_Peripheral_Access_Layer XBARA Peripheral Access Layer
 * @{
 */

/** XBARA - Register Layout Typedef */
typedef struct {
  __IO uint16_t SEL0;                              /**< Crossbar A Select Register 0, offset: 0x0 */
  __IO uint16_t SEL1;                              /**< Crossbar A Select Register 1, offset: 0x2 */
  __IO uint16_t SEL2;                              /**< Crossbar A Select Register 2, offset: 0x4 */
  __IO uint16_t SEL3;                              /**< Crossbar A Select Register 3, offset: 0x6 */
  __IO uint16_t SEL4;                              /**< Crossbar A Select Register 4, offset: 0x8 */
  __IO uint16_t SEL5;                              /**< Crossbar A Select Register 5, offset: 0xA */
  __IO uint16_t SEL6;                              /**< Crossbar A Select Register 6, offset: 0xC */
  __IO uint16_t SEL7;                              /**< Crossbar A Select Register 7, offset: 0xE */
  __IO uint16_t SEL8;                              /**< Crossbar A Select Register 8, offset: 0x10 */
  __IO uint16_t SEL9;                              /**< Crossbar A Select Register 9, offset: 0x12 */
  __IO uint16_t SEL10;                             /**< Crossbar A Select Register 10, offset: 0x14 */
  __IO uint16_t SEL11;                             /**< Crossbar A Select Register 11, offset: 0x16 */
  __IO uint16_t SEL12;                             /**< Crossbar A Select Register 12, offset: 0x18 */
  __IO uint16_t SEL13;                             /**< Crossbar A Select Register 13, offset: 0x1A */
  __IO uint16_t SEL14;                             /**< Crossbar A Select Register 14, offset: 0x1C */
  __IO uint16_t SEL15;                             /**< Crossbar A Select Register 15, offset: 0x1E */
  __IO uint16_t SEL16;                             /**< Crossbar A Select Register 16, offset: 0x20 */
  __IO uint16_t SEL17;                             /**< Crossbar A Select Register 17, offset: 0x22 */
  __IO uint16_t SEL18;                             /**< Crossbar A Select Register 18, offset: 0x24 */
  __IO uint16_t SEL19;                             /**< Crossbar A Select Register 19, offset: 0x26 */
  __IO uint16_t SEL20;                             /**< Crossbar A Select Register 20, offset: 0x28 */
  __IO uint16_t SEL21;                             /**< Crossbar A Select Register 21, offset: 0x2A */
  __IO uint16_t SEL22;                             /**< Crossbar A Select Register 22, offset: 0x2C */
  __IO uint16_t SEL23;                             /**< Crossbar A Select Register 23, offset: 0x2E */
  __IO uint16_t SEL24;                             /**< Crossbar A Select Register 24, offset: 0x30 */
  __IO uint16_t SEL25;                             /**< Crossbar A Select Register 25, offset: 0x32 */
  __IO uint16_t SEL26;                             /**< Crossbar A Select Register 26, offset: 0x34 */
  __IO uint16_t SEL27;                             /**< Crossbar A Select Register 27, offset: 0x36 */
  __IO uint16_t SEL28;                             /**< Crossbar A Select Register 28, offset: 0x38 */
  __IO uint16_t SEL29;                             /**< Crossbar A Select Register 29, offset: 0x3A */
  __IO uint16_t SEL30;                             /**< Crossbar A Select Register 30, offset: 0x3C */
  __IO uint16_t SEL31;                             /**< Crossbar A Select Register 31, offset: 0x3E */
  __IO uint16_t SEL32;                             /**< Crossbar A Select Register 32, offset: 0x40 */
  __IO uint16_t SEL33;                             /**< Crossbar A Select Register 33, offset: 0x42 */
  __IO uint16_t SEL34;                             /**< Crossbar A Select Register 34, offset: 0x44 */
  __IO uint16_t SEL35;                             /**< Crossbar A Select Register 35, offset: 0x46 */
  __IO uint16_t SEL36;                             /**< Crossbar A Select Register 36, offset: 0x48 */
  __IO uint16_t SEL37;                             /**< Crossbar A Select Register 37, offset: 0x4A */
  __IO uint16_t SEL38;                             /**< Crossbar A Select Register 38, offset: 0x4C */
  __IO uint16_t SEL39;                             /**< Crossbar A Select Register 39, offset: 0x4E */
  __IO uint16_t SEL40;                             /**< Crossbar A Select Register 40, offset: 0x50 */
  __IO uint16_t SEL41;                             /**< Crossbar A Select Register 41, offset: 0x52 */
  __IO uint16_t SEL42;                             /**< Crossbar A Select Register 42, offset: 0x54 */
  __IO uint16_t SEL43;                             /**< Crossbar A Select Register 43, offset: 0x56 */
  __IO uint16_t SEL44;                             /**< Crossbar A Select Register 44, offset: 0x58 */
  __IO uint16_t SEL45;                             /**< Crossbar A Select Register 45, offset: 0x5A */
  __IO uint16_t SEL46;                             /**< Crossbar A Select Register 46, offset: 0x5C */
  __IO uint16_t SEL47;                             /**< Crossbar A Select Register 47, offset: 0x5E */
  __IO uint16_t SEL48;                             /**< Crossbar A Select Register 48, offset: 0x60 */
  __IO uint16_t SEL49;                             /**< Crossbar A Select Register 49, offset: 0x62 */
  __IO uint16_t SEL50;                             /**< Crossbar A Select Register 50, offset: 0x64 */
  __IO uint16_t SEL51;                             /**< Crossbar A Select Register 51, offset: 0x66 */
  __IO uint16_t SEL52;                             /**< Crossbar A Select Register 52, offset: 0x68 */
  __IO uint16_t SEL53;                             /**< Crossbar A Select Register 53, offset: 0x6A */
  __IO uint16_t SEL54;                             /**< Crossbar A Select Register 54, offset: 0x6C */
  __IO uint16_t SEL55;                             /**< Crossbar A Select Register 55, offset: 0x6E */
  __IO uint16_t SEL56;                             /**< Crossbar A Select Register 56, offset: 0x70 */
  __IO uint16_t SEL57;                             /**< Crossbar A Select Register 57, offset: 0x72 */
  __IO uint16_t SEL58;                             /**< Crossbar A Select Register 58, offset: 0x74 */
  __IO uint16_t SEL59;                             /**< Crossbar A Select Register 59, offset: 0x76 */
  __IO uint16_t SEL60;                             /**< Crossbar A Select Register 60, offset: 0x78 */
  __IO uint16_t SEL61;                             /**< Crossbar A Select Register 61, offset: 0x7A */
  __IO uint16_t SEL62;                             /**< Crossbar A Select Register 62, offset: 0x7C */
  __IO uint16_t SEL63;                             /**< Crossbar A Select Register 63, offset: 0x7E */
  __IO uint16_t SEL64;                             /**< Crossbar A Select Register 64, offset: 0x80 */
  __IO uint16_t SEL65;                             /**< Crossbar A Select Register 65, offset: 0x82 */
  __IO uint16_t CTRL0;                             /**< Crossbar A Control Register 0, offset: 0x84 */
  __IO uint16_t CTRL1;                             /**< Crossbar A Control Register 1, offset: 0x86 */
} XBARA_Type;

/* ----------------------------------------------------------------------------
   -- XBARA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARA_Register_Masks XBARA Register Masks
 * @{
 */

/*! @name SEL0 - Crossbar A Select Register 0 */
/*! @{ */

#define XBARA_SEL0_SEL0_MASK                     (0x7FU)
#define XBARA_SEL0_SEL0_SHIFT                    (0U)
#define XBARA_SEL0_SEL0(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL0_SEL0_SHIFT)) & XBARA_SEL0_SEL0_MASK)

#define XBARA_SEL0_SEL1_MASK                     (0x7F00U)
#define XBARA_SEL0_SEL1_SHIFT                    (8U)
#define XBARA_SEL0_SEL1(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL0_SEL1_SHIFT)) & XBARA_SEL0_SEL1_MASK)
/*! @} */

/*! @name SEL1 - Crossbar A Select Register 1 */
/*! @{ */

#define XBARA_SEL1_SEL2_MASK                     (0x7FU)
#define XBARA_SEL1_SEL2_SHIFT                    (0U)
#define XBARA_SEL1_SEL2(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL1_SEL2_SHIFT)) & XBARA_SEL1_SEL2_MASK)

#define XBARA_SEL1_SEL3_MASK                     (0x7F00U)
#define XBARA_SEL1_SEL3_SHIFT                    (8U)
#define XBARA_SEL1_SEL3(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL1_SEL3_SHIFT)) & XBARA_SEL1_SEL3_MASK)
/*! @} */

/*! @name SEL2 - Crossbar A Select Register 2 */
/*! @{ */

#define XBARA_SEL2_SEL4_MASK                     (0x7FU)
#define XBARA_SEL2_SEL4_SHIFT                    (0U)
#define XBARA_SEL2_SEL4(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL2_SEL4_SHIFT)) & XBARA_SEL2_SEL4_MASK)

#define XBARA_SEL2_SEL5_MASK                     (0x7F00U)
#define XBARA_SEL2_SEL5_SHIFT                    (8U)
#define XBARA_SEL2_SEL5(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL2_SEL5_SHIFT)) & XBARA_SEL2_SEL5_MASK)
/*! @} */

/*! @name SEL3 - Crossbar A Select Register 3 */
/*! @{ */

#define XBARA_SEL3_SEL6_MASK                     (0x7FU)
#define XBARA_SEL3_SEL6_SHIFT                    (0U)
#define XBARA_SEL3_SEL6(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL3_SEL6_SHIFT)) & XBARA_SEL3_SEL6_MASK)

#define XBARA_SEL3_SEL7_MASK                     (0x7F00U)
#define XBARA_SEL3_SEL7_SHIFT                    (8U)
#define XBARA_SEL3_SEL7(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL3_SEL7_SHIFT)) & XBARA_SEL3_SEL7_MASK)
/*! @} */

/*! @name SEL4 - Crossbar A Select Register 4 */
/*! @{ */

#define XBARA_SEL4_SEL8_MASK                     (0x7FU)
#define XBARA_SEL4_SEL8_SHIFT                    (0U)
#define XBARA_SEL4_SEL8(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL4_SEL8_SHIFT)) & XBARA_SEL4_SEL8_MASK)

#define XBARA_SEL4_SEL9_MASK                     (0x7F00U)
#define XBARA_SEL4_SEL9_SHIFT                    (8U)
#define XBARA_SEL4_SEL9(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL4_SEL9_SHIFT)) & XBARA_SEL4_SEL9_MASK)
/*! @} */

/*! @name SEL5 - Crossbar A Select Register 5 */
/*! @{ */

#define XBARA_SEL5_SEL10_MASK                    (0x7FU)
#define XBARA_SEL5_SEL10_SHIFT                   (0U)
#define XBARA_SEL5_SEL10(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL5_SEL10_SHIFT)) & XBARA_SEL5_SEL10_MASK)

#define XBARA_SEL5_SEL11_MASK                    (0x7F00U)
#define XBARA_SEL5_SEL11_SHIFT                   (8U)
#define XBARA_SEL5_SEL11(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL5_SEL11_SHIFT)) & XBARA_SEL5_SEL11_MASK)
/*! @} */

/*! @name SEL6 - Crossbar A Select Register 6 */
/*! @{ */

#define XBARA_SEL6_SEL12_MASK                    (0x7FU)
#define XBARA_SEL6_SEL12_SHIFT                   (0U)
#define XBARA_SEL6_SEL12(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL6_SEL12_SHIFT)) & XBARA_SEL6_SEL12_MASK)

#define XBARA_SEL6_SEL13_MASK                    (0x7F00U)
#define XBARA_SEL6_SEL13_SHIFT                   (8U)
#define XBARA_SEL6_SEL13(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL6_SEL13_SHIFT)) & XBARA_SEL6_SEL13_MASK)
/*! @} */

/*! @name SEL7 - Crossbar A Select Register 7 */
/*! @{ */

#define XBARA_SEL7_SEL14_MASK                    (0x7FU)
#define XBARA_SEL7_SEL14_SHIFT                   (0U)
#define XBARA_SEL7_SEL14(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL7_SEL14_SHIFT)) & XBARA_SEL7_SEL14_MASK)

#define XBARA_SEL7_SEL15_MASK                    (0x7F00U)
#define XBARA_SEL7_SEL15_SHIFT                   (8U)
#define XBARA_SEL7_SEL15(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL7_SEL15_SHIFT)) & XBARA_SEL7_SEL15_MASK)
/*! @} */

/*! @name SEL8 - Crossbar A Select Register 8 */
/*! @{ */

#define XBARA_SEL8_SEL16_MASK                    (0x7FU)
#define XBARA_SEL8_SEL16_SHIFT                   (0U)
#define XBARA_SEL8_SEL16(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL8_SEL16_SHIFT)) & XBARA_SEL8_SEL16_MASK)

#define XBARA_SEL8_SEL17_MASK                    (0x7F00U)
#define XBARA_SEL8_SEL17_SHIFT                   (8U)
#define XBARA_SEL8_SEL17(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL8_SEL17_SHIFT)) & XBARA_SEL8_SEL17_MASK)
/*! @} */

/*! @name SEL9 - Crossbar A Select Register 9 */
/*! @{ */

#define XBARA_SEL9_SEL18_MASK                    (0x7FU)
#define XBARA_SEL9_SEL18_SHIFT                   (0U)
#define XBARA_SEL9_SEL18(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL9_SEL18_SHIFT)) & XBARA_SEL9_SEL18_MASK)

#define XBARA_SEL9_SEL19_MASK                    (0x7F00U)
#define XBARA_SEL9_SEL19_SHIFT                   (8U)
#define XBARA_SEL9_SEL19(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL9_SEL19_SHIFT)) & XBARA_SEL9_SEL19_MASK)
/*! @} */

/*! @name SEL10 - Crossbar A Select Register 10 */
/*! @{ */

#define XBARA_SEL10_SEL20_MASK                   (0x7FU)
#define XBARA_SEL10_SEL20_SHIFT                  (0U)
#define XBARA_SEL10_SEL20(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL10_SEL20_SHIFT)) & XBARA_SEL10_SEL20_MASK)

#define XBARA_SEL10_SEL21_MASK                   (0x7F00U)
#define XBARA_SEL10_SEL21_SHIFT                  (8U)
#define XBARA_SEL10_SEL21(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL10_SEL21_SHIFT)) & XBARA_SEL10_SEL21_MASK)
/*! @} */

/*! @name SEL11 - Crossbar A Select Register 11 */
/*! @{ */

#define XBARA_SEL11_SEL22_MASK                   (0x7FU)
#define XBARA_SEL11_SEL22_SHIFT                  (0U)
#define XBARA_SEL11_SEL22(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL11_SEL22_SHIFT)) & XBARA_SEL11_SEL22_MASK)

#define XBARA_SEL11_SEL23_MASK                   (0x7F00U)
#define XBARA_SEL11_SEL23_SHIFT                  (8U)
#define XBARA_SEL11_SEL23(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL11_SEL23_SHIFT)) & XBARA_SEL11_SEL23_MASK)
/*! @} */

/*! @name SEL12 - Crossbar A Select Register 12 */
/*! @{ */

#define XBARA_SEL12_SEL24_MASK                   (0x7FU)
#define XBARA_SEL12_SEL24_SHIFT                  (0U)
#define XBARA_SEL12_SEL24(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL12_SEL24_SHIFT)) & XBARA_SEL12_SEL24_MASK)

#define XBARA_SEL12_SEL25_MASK                   (0x7F00U)
#define XBARA_SEL12_SEL25_SHIFT                  (8U)
#define XBARA_SEL12_SEL25(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL12_SEL25_SHIFT)) & XBARA_SEL12_SEL25_MASK)
/*! @} */

/*! @name SEL13 - Crossbar A Select Register 13 */
/*! @{ */

#define XBARA_SEL13_SEL26_MASK                   (0x7FU)
#define XBARA_SEL13_SEL26_SHIFT                  (0U)
#define XBARA_SEL13_SEL26(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL13_SEL26_SHIFT)) & XBARA_SEL13_SEL26_MASK)

#define XBARA_SEL13_SEL27_MASK                   (0x7F00U)
#define XBARA_SEL13_SEL27_SHIFT                  (8U)
#define XBARA_SEL13_SEL27(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL13_SEL27_SHIFT)) & XBARA_SEL13_SEL27_MASK)
/*! @} */

/*! @name SEL14 - Crossbar A Select Register 14 */
/*! @{ */

#define XBARA_SEL14_SEL28_MASK                   (0x7FU)
#define XBARA_SEL14_SEL28_SHIFT                  (0U)
#define XBARA_SEL14_SEL28(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL14_SEL28_SHIFT)) & XBARA_SEL14_SEL28_MASK)

#define XBARA_SEL14_SEL29_MASK                   (0x7F00U)
#define XBARA_SEL14_SEL29_SHIFT                  (8U)
#define XBARA_SEL14_SEL29(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL14_SEL29_SHIFT)) & XBARA_SEL14_SEL29_MASK)
/*! @} */

/*! @name SEL15 - Crossbar A Select Register 15 */
/*! @{ */

#define XBARA_SEL15_SEL30_MASK                   (0x7FU)
#define XBARA_SEL15_SEL30_SHIFT                  (0U)
#define XBARA_SEL15_SEL30(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL15_SEL30_SHIFT)) & XBARA_SEL15_SEL30_MASK)

#define XBARA_SEL15_SEL31_MASK                   (0x7F00U)
#define XBARA_SEL15_SEL31_SHIFT                  (8U)
#define XBARA_SEL15_SEL31(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL15_SEL31_SHIFT)) & XBARA_SEL15_SEL31_MASK)
/*! @} */

/*! @name SEL16 - Crossbar A Select Register 16 */
/*! @{ */

#define XBARA_SEL16_SEL32_MASK                   (0x7FU)
#define XBARA_SEL16_SEL32_SHIFT                  (0U)
#define XBARA_SEL16_SEL32(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL16_SEL32_SHIFT)) & XBARA_SEL16_SEL32_MASK)

#define XBARA_SEL16_SEL33_MASK                   (0x7F00U)
#define XBARA_SEL16_SEL33_SHIFT                  (8U)
#define XBARA_SEL16_SEL33(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL16_SEL33_SHIFT)) & XBARA_SEL16_SEL33_MASK)
/*! @} */

/*! @name SEL17 - Crossbar A Select Register 17 */
/*! @{ */

#define XBARA_SEL17_SEL34_MASK                   (0x7FU)
#define XBARA_SEL17_SEL34_SHIFT                  (0U)
#define XBARA_SEL17_SEL34(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL17_SEL34_SHIFT)) & XBARA_SEL17_SEL34_MASK)

#define XBARA_SEL17_SEL35_MASK                   (0x7F00U)
#define XBARA_SEL17_SEL35_SHIFT                  (8U)
#define XBARA_SEL17_SEL35(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL17_SEL35_SHIFT)) & XBARA_SEL17_SEL35_MASK)
/*! @} */

/*! @name SEL18 - Crossbar A Select Register 18 */
/*! @{ */

#define XBARA_SEL18_SEL36_MASK                   (0x7FU)
#define XBARA_SEL18_SEL36_SHIFT                  (0U)
#define XBARA_SEL18_SEL36(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL18_SEL36_SHIFT)) & XBARA_SEL18_SEL36_MASK)

#define XBARA_SEL18_SEL37_MASK                   (0x7F00U)
#define XBARA_SEL18_SEL37_SHIFT                  (8U)
#define XBARA_SEL18_SEL37(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL18_SEL37_SHIFT)) & XBARA_SEL18_SEL37_MASK)
/*! @} */

/*! @name SEL19 - Crossbar A Select Register 19 */
/*! @{ */

#define XBARA_SEL19_SEL38_MASK                   (0x7FU)
#define XBARA_SEL19_SEL38_SHIFT                  (0U)
#define XBARA_SEL19_SEL38(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL19_SEL38_SHIFT)) & XBARA_SEL19_SEL38_MASK)

#define XBARA_SEL19_SEL39_MASK                   (0x7F00U)
#define XBARA_SEL19_SEL39_SHIFT                  (8U)
#define XBARA_SEL19_SEL39(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL19_SEL39_SHIFT)) & XBARA_SEL19_SEL39_MASK)
/*! @} */

/*! @name SEL20 - Crossbar A Select Register 20 */
/*! @{ */

#define XBARA_SEL20_SEL40_MASK                   (0x7FU)
#define XBARA_SEL20_SEL40_SHIFT                  (0U)
#define XBARA_SEL20_SEL40(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL20_SEL40_SHIFT)) & XBARA_SEL20_SEL40_MASK)

#define XBARA_SEL20_SEL41_MASK                   (0x7F00U)
#define XBARA_SEL20_SEL41_SHIFT                  (8U)
#define XBARA_SEL20_SEL41(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL20_SEL41_SHIFT)) & XBARA_SEL20_SEL41_MASK)
/*! @} */

/*! @name SEL21 - Crossbar A Select Register 21 */
/*! @{ */

#define XBARA_SEL21_SEL42_MASK                   (0x7FU)
#define XBARA_SEL21_SEL42_SHIFT                  (0U)
#define XBARA_SEL21_SEL42(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL21_SEL42_SHIFT)) & XBARA_SEL21_SEL42_MASK)

#define XBARA_SEL21_SEL43_MASK                   (0x7F00U)
#define XBARA_SEL21_SEL43_SHIFT                  (8U)
#define XBARA_SEL21_SEL43(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL21_SEL43_SHIFT)) & XBARA_SEL21_SEL43_MASK)
/*! @} */

/*! @name SEL22 - Crossbar A Select Register 22 */
/*! @{ */

#define XBARA_SEL22_SEL44_MASK                   (0x7FU)
#define XBARA_SEL22_SEL44_SHIFT                  (0U)
#define XBARA_SEL22_SEL44(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL22_SEL44_SHIFT)) & XBARA_SEL22_SEL44_MASK)

#define XBARA_SEL22_SEL45_MASK                   (0x7F00U)
#define XBARA_SEL22_SEL45_SHIFT                  (8U)
#define XBARA_SEL22_SEL45(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL22_SEL45_SHIFT)) & XBARA_SEL22_SEL45_MASK)
/*! @} */

/*! @name SEL23 - Crossbar A Select Register 23 */
/*! @{ */

#define XBARA_SEL23_SEL46_MASK                   (0x7FU)
#define XBARA_SEL23_SEL46_SHIFT                  (0U)
#define XBARA_SEL23_SEL46(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL23_SEL46_SHIFT)) & XBARA_SEL23_SEL46_MASK)

#define XBARA_SEL23_SEL47_MASK                   (0x7F00U)
#define XBARA_SEL23_SEL47_SHIFT                  (8U)
#define XBARA_SEL23_SEL47(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL23_SEL47_SHIFT)) & XBARA_SEL23_SEL47_MASK)
/*! @} */

/*! @name SEL24 - Crossbar A Select Register 24 */
/*! @{ */

#define XBARA_SEL24_SEL48_MASK                   (0x7FU)
#define XBARA_SEL24_SEL48_SHIFT                  (0U)
#define XBARA_SEL24_SEL48(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL24_SEL48_SHIFT)) & XBARA_SEL24_SEL48_MASK)

#define XBARA_SEL24_SEL49_MASK                   (0x7F00U)
#define XBARA_SEL24_SEL49_SHIFT                  (8U)
#define XBARA_SEL24_SEL49(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL24_SEL49_SHIFT)) & XBARA_SEL24_SEL49_MASK)
/*! @} */

/*! @name SEL25 - Crossbar A Select Register 25 */
/*! @{ */

#define XBARA_SEL25_SEL50_MASK                   (0x7FU)
#define XBARA_SEL25_SEL50_SHIFT                  (0U)
#define XBARA_SEL25_SEL50(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL25_SEL50_SHIFT)) & XBARA_SEL25_SEL50_MASK)

#define XBARA_SEL25_SEL51_MASK                   (0x7F00U)
#define XBARA_SEL25_SEL51_SHIFT                  (8U)
#define XBARA_SEL25_SEL51(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL25_SEL51_SHIFT)) & XBARA_SEL25_SEL51_MASK)
/*! @} */

/*! @name SEL26 - Crossbar A Select Register 26 */
/*! @{ */

#define XBARA_SEL26_SEL52_MASK                   (0x7FU)
#define XBARA_SEL26_SEL52_SHIFT                  (0U)
#define XBARA_SEL26_SEL52(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL26_SEL52_SHIFT)) & XBARA_SEL26_SEL52_MASK)

#define XBARA_SEL26_SEL53_MASK                   (0x7F00U)
#define XBARA_SEL26_SEL53_SHIFT                  (8U)
#define XBARA_SEL26_SEL53(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL26_SEL53_SHIFT)) & XBARA_SEL26_SEL53_MASK)
/*! @} */

/*! @name SEL27 - Crossbar A Select Register 27 */
/*! @{ */

#define XBARA_SEL27_SEL54_MASK                   (0x7FU)
#define XBARA_SEL27_SEL54_SHIFT                  (0U)
#define XBARA_SEL27_SEL54(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL27_SEL54_SHIFT)) & XBARA_SEL27_SEL54_MASK)

#define XBARA_SEL27_SEL55_MASK                   (0x7F00U)
#define XBARA_SEL27_SEL55_SHIFT                  (8U)
#define XBARA_SEL27_SEL55(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL27_SEL55_SHIFT)) & XBARA_SEL27_SEL55_MASK)
/*! @} */

/*! @name SEL28 - Crossbar A Select Register 28 */
/*! @{ */

#define XBARA_SEL28_SEL56_MASK                   (0x7FU)
#define XBARA_SEL28_SEL56_SHIFT                  (0U)
#define XBARA_SEL28_SEL56(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL28_SEL56_SHIFT)) & XBARA_SEL28_SEL56_MASK)

#define XBARA_SEL28_SEL57_MASK                   (0x7F00U)
#define XBARA_SEL28_SEL57_SHIFT                  (8U)
#define XBARA_SEL28_SEL57(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL28_SEL57_SHIFT)) & XBARA_SEL28_SEL57_MASK)
/*! @} */

/*! @name SEL29 - Crossbar A Select Register 29 */
/*! @{ */

#define XBARA_SEL29_SEL58_MASK                   (0x7FU)
#define XBARA_SEL29_SEL58_SHIFT                  (0U)
#define XBARA_SEL29_SEL58(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL29_SEL58_SHIFT)) & XBARA_SEL29_SEL58_MASK)

#define XBARA_SEL29_SEL59_MASK                   (0x7F00U)
#define XBARA_SEL29_SEL59_SHIFT                  (8U)
#define XBARA_SEL29_SEL59(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL29_SEL59_SHIFT)) & XBARA_SEL29_SEL59_MASK)
/*! @} */

/*! @name SEL30 - Crossbar A Select Register 30 */
/*! @{ */

#define XBARA_SEL30_SEL60_MASK                   (0x7FU)
#define XBARA_SEL30_SEL60_SHIFT                  (0U)
#define XBARA_SEL30_SEL60(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL30_SEL60_SHIFT)) & XBARA_SEL30_SEL60_MASK)

#define XBARA_SEL30_SEL61_MASK                   (0x7F00U)
#define XBARA_SEL30_SEL61_SHIFT                  (8U)
#define XBARA_SEL30_SEL61(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL30_SEL61_SHIFT)) & XBARA_SEL30_SEL61_MASK)
/*! @} */

/*! @name SEL31 - Crossbar A Select Register 31 */
/*! @{ */

#define XBARA_SEL31_SEL62_MASK                   (0x7FU)
#define XBARA_SEL31_SEL62_SHIFT                  (0U)
#define XBARA_SEL31_SEL62(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL31_SEL62_SHIFT)) & XBARA_SEL31_SEL62_MASK)

#define XBARA_SEL31_SEL63_MASK                   (0x7F00U)
#define XBARA_SEL31_SEL63_SHIFT                  (8U)
#define XBARA_SEL31_SEL63(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL31_SEL63_SHIFT)) & XBARA_SEL31_SEL63_MASK)
/*! @} */

/*! @name SEL32 - Crossbar A Select Register 32 */
/*! @{ */

#define XBARA_SEL32_SEL64_MASK                   (0x7FU)
#define XBARA_SEL32_SEL64_SHIFT                  (0U)
#define XBARA_SEL32_SEL64(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL32_SEL64_SHIFT)) & XBARA_SEL32_SEL64_MASK)

#define XBARA_SEL32_SEL65_MASK                   (0x7F00U)
#define XBARA_SEL32_SEL65_SHIFT                  (8U)
#define XBARA_SEL32_SEL65(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL32_SEL65_SHIFT)) & XBARA_SEL32_SEL65_MASK)
/*! @} */

/*! @name SEL33 - Crossbar A Select Register 33 */
/*! @{ */

#define XBARA_SEL33_SEL66_MASK                   (0x7FU)
#define XBARA_SEL33_SEL66_SHIFT                  (0U)
#define XBARA_SEL33_SEL66(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL33_SEL66_SHIFT)) & XBARA_SEL33_SEL66_MASK)

#define XBARA_SEL33_SEL67_MASK                   (0x7F00U)
#define XBARA_SEL33_SEL67_SHIFT                  (8U)
#define XBARA_SEL33_SEL67(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL33_SEL67_SHIFT)) & XBARA_SEL33_SEL67_MASK)
/*! @} */

/*! @name SEL34 - Crossbar A Select Register 34 */
/*! @{ */

#define XBARA_SEL34_SEL68_MASK                   (0x7FU)
#define XBARA_SEL34_SEL68_SHIFT                  (0U)
#define XBARA_SEL34_SEL68(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL34_SEL68_SHIFT)) & XBARA_SEL34_SEL68_MASK)

#define XBARA_SEL34_SEL69_MASK                   (0x7F00U)
#define XBARA_SEL34_SEL69_SHIFT                  (8U)
#define XBARA_SEL34_SEL69(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL34_SEL69_SHIFT)) & XBARA_SEL34_SEL69_MASK)
/*! @} */

/*! @name SEL35 - Crossbar A Select Register 35 */
/*! @{ */

#define XBARA_SEL35_SEL70_MASK                   (0x7FU)
#define XBARA_SEL35_SEL70_SHIFT                  (0U)
#define XBARA_SEL35_SEL70(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL35_SEL70_SHIFT)) & XBARA_SEL35_SEL70_MASK)

#define XBARA_SEL35_SEL71_MASK                   (0x7F00U)
#define XBARA_SEL35_SEL71_SHIFT                  (8U)
#define XBARA_SEL35_SEL71(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL35_SEL71_SHIFT)) & XBARA_SEL35_SEL71_MASK)
/*! @} */

/*! @name SEL36 - Crossbar A Select Register 36 */
/*! @{ */

#define XBARA_SEL36_SEL72_MASK                   (0x7FU)
#define XBARA_SEL36_SEL72_SHIFT                  (0U)
#define XBARA_SEL36_SEL72(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL36_SEL72_SHIFT)) & XBARA_SEL36_SEL72_MASK)

#define XBARA_SEL36_SEL73_MASK                   (0x7F00U)
#define XBARA_SEL36_SEL73_SHIFT                  (8U)
#define XBARA_SEL36_SEL73(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL36_SEL73_SHIFT)) & XBARA_SEL36_SEL73_MASK)
/*! @} */

/*! @name SEL37 - Crossbar A Select Register 37 */
/*! @{ */

#define XBARA_SEL37_SEL74_MASK                   (0x7FU)
#define XBARA_SEL37_SEL74_SHIFT                  (0U)
#define XBARA_SEL37_SEL74(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL37_SEL74_SHIFT)) & XBARA_SEL37_SEL74_MASK)

#define XBARA_SEL37_SEL75_MASK                   (0x7F00U)
#define XBARA_SEL37_SEL75_SHIFT                  (8U)
#define XBARA_SEL37_SEL75(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL37_SEL75_SHIFT)) & XBARA_SEL37_SEL75_MASK)
/*! @} */

/*! @name SEL38 - Crossbar A Select Register 38 */
/*! @{ */

#define XBARA_SEL38_SEL76_MASK                   (0x7FU)
#define XBARA_SEL38_SEL76_SHIFT                  (0U)
#define XBARA_SEL38_SEL76(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL38_SEL76_SHIFT)) & XBARA_SEL38_SEL76_MASK)

#define XBARA_SEL38_SEL77_MASK                   (0x7F00U)
#define XBARA_SEL38_SEL77_SHIFT                  (8U)
#define XBARA_SEL38_SEL77(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL38_SEL77_SHIFT)) & XBARA_SEL38_SEL77_MASK)
/*! @} */

/*! @name SEL39 - Crossbar A Select Register 39 */
/*! @{ */

#define XBARA_SEL39_SEL78_MASK                   (0x7FU)
#define XBARA_SEL39_SEL78_SHIFT                  (0U)
#define XBARA_SEL39_SEL78(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL39_SEL78_SHIFT)) & XBARA_SEL39_SEL78_MASK)

#define XBARA_SEL39_SEL79_MASK                   (0x7F00U)
#define XBARA_SEL39_SEL79_SHIFT                  (8U)
#define XBARA_SEL39_SEL79(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL39_SEL79_SHIFT)) & XBARA_SEL39_SEL79_MASK)
/*! @} */

/*! @name SEL40 - Crossbar A Select Register 40 */
/*! @{ */

#define XBARA_SEL40_SEL80_MASK                   (0x7FU)
#define XBARA_SEL40_SEL80_SHIFT                  (0U)
#define XBARA_SEL40_SEL80(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL40_SEL80_SHIFT)) & XBARA_SEL40_SEL80_MASK)

#define XBARA_SEL40_SEL81_MASK                   (0x7F00U)
#define XBARA_SEL40_SEL81_SHIFT                  (8U)
#define XBARA_SEL40_SEL81(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL40_SEL81_SHIFT)) & XBARA_SEL40_SEL81_MASK)
/*! @} */

/*! @name SEL41 - Crossbar A Select Register 41 */
/*! @{ */

#define XBARA_SEL41_SEL82_MASK                   (0x7FU)
#define XBARA_SEL41_SEL82_SHIFT                  (0U)
#define XBARA_SEL41_SEL82(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL41_SEL82_SHIFT)) & XBARA_SEL41_SEL82_MASK)

#define XBARA_SEL41_SEL83_MASK                   (0x7F00U)
#define XBARA_SEL41_SEL83_SHIFT                  (8U)
#define XBARA_SEL41_SEL83(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL41_SEL83_SHIFT)) & XBARA_SEL41_SEL83_MASK)
/*! @} */

/*! @name SEL42 - Crossbar A Select Register 42 */
/*! @{ */

#define XBARA_SEL42_SEL84_MASK                   (0x7FU)
#define XBARA_SEL42_SEL84_SHIFT                  (0U)
#define XBARA_SEL42_SEL84(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL42_SEL84_SHIFT)) & XBARA_SEL42_SEL84_MASK)

#define XBARA_SEL42_SEL85_MASK                   (0x7F00U)
#define XBARA_SEL42_SEL85_SHIFT                  (8U)
#define XBARA_SEL42_SEL85(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL42_SEL85_SHIFT)) & XBARA_SEL42_SEL85_MASK)
/*! @} */

/*! @name SEL43 - Crossbar A Select Register 43 */
/*! @{ */

#define XBARA_SEL43_SEL86_MASK                   (0x7FU)
#define XBARA_SEL43_SEL86_SHIFT                  (0U)
#define XBARA_SEL43_SEL86(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL43_SEL86_SHIFT)) & XBARA_SEL43_SEL86_MASK)

#define XBARA_SEL43_SEL87_MASK                   (0x7F00U)
#define XBARA_SEL43_SEL87_SHIFT                  (8U)
#define XBARA_SEL43_SEL87(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL43_SEL87_SHIFT)) & XBARA_SEL43_SEL87_MASK)
/*! @} */

/*! @name SEL44 - Crossbar A Select Register 44 */
/*! @{ */

#define XBARA_SEL44_SEL88_MASK                   (0x7FU)
#define XBARA_SEL44_SEL88_SHIFT                  (0U)
#define XBARA_SEL44_SEL88(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL44_SEL88_SHIFT)) & XBARA_SEL44_SEL88_MASK)

#define XBARA_SEL44_SEL89_MASK                   (0x7F00U)
#define XBARA_SEL44_SEL89_SHIFT                  (8U)
#define XBARA_SEL44_SEL89(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL44_SEL89_SHIFT)) & XBARA_SEL44_SEL89_MASK)
/*! @} */

/*! @name SEL45 - Crossbar A Select Register 45 */
/*! @{ */

#define XBARA_SEL45_SEL90_MASK                   (0x7FU)
#define XBARA_SEL45_SEL90_SHIFT                  (0U)
#define XBARA_SEL45_SEL90(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL45_SEL90_SHIFT)) & XBARA_SEL45_SEL90_MASK)

#define XBARA_SEL45_SEL91_MASK                   (0x7F00U)
#define XBARA_SEL45_SEL91_SHIFT                  (8U)
#define XBARA_SEL45_SEL91(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL45_SEL91_SHIFT)) & XBARA_SEL45_SEL91_MASK)
/*! @} */

/*! @name SEL46 - Crossbar A Select Register 46 */
/*! @{ */

#define XBARA_SEL46_SEL92_MASK                   (0x7FU)
#define XBARA_SEL46_SEL92_SHIFT                  (0U)
#define XBARA_SEL46_SEL92(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL46_SEL92_SHIFT)) & XBARA_SEL46_SEL92_MASK)

#define XBARA_SEL46_SEL93_MASK                   (0x7F00U)
#define XBARA_SEL46_SEL93_SHIFT                  (8U)
#define XBARA_SEL46_SEL93(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL46_SEL93_SHIFT)) & XBARA_SEL46_SEL93_MASK)
/*! @} */

/*! @name SEL47 - Crossbar A Select Register 47 */
/*! @{ */

#define XBARA_SEL47_SEL94_MASK                   (0x7FU)
#define XBARA_SEL47_SEL94_SHIFT                  (0U)
#define XBARA_SEL47_SEL94(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL47_SEL94_SHIFT)) & XBARA_SEL47_SEL94_MASK)

#define XBARA_SEL47_SEL95_MASK                   (0x7F00U)
#define XBARA_SEL47_SEL95_SHIFT                  (8U)
#define XBARA_SEL47_SEL95(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL47_SEL95_SHIFT)) & XBARA_SEL47_SEL95_MASK)
/*! @} */

/*! @name SEL48 - Crossbar A Select Register 48 */
/*! @{ */

#define XBARA_SEL48_SEL96_MASK                   (0x7FU)
#define XBARA_SEL48_SEL96_SHIFT                  (0U)
#define XBARA_SEL48_SEL96(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL48_SEL96_SHIFT)) & XBARA_SEL48_SEL96_MASK)

#define XBARA_SEL48_SEL97_MASK                   (0x7F00U)
#define XBARA_SEL48_SEL97_SHIFT                  (8U)
#define XBARA_SEL48_SEL97(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL48_SEL97_SHIFT)) & XBARA_SEL48_SEL97_MASK)
/*! @} */

/*! @name SEL49 - Crossbar A Select Register 49 */
/*! @{ */

#define XBARA_SEL49_SEL98_MASK                   (0x7FU)
#define XBARA_SEL49_SEL98_SHIFT                  (0U)
#define XBARA_SEL49_SEL98(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL49_SEL98_SHIFT)) & XBARA_SEL49_SEL98_MASK)

#define XBARA_SEL49_SEL99_MASK                   (0x7F00U)
#define XBARA_SEL49_SEL99_SHIFT                  (8U)
#define XBARA_SEL49_SEL99(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL49_SEL99_SHIFT)) & XBARA_SEL49_SEL99_MASK)
/*! @} */

/*! @name SEL50 - Crossbar A Select Register 50 */
/*! @{ */

#define XBARA_SEL50_SEL100_MASK                  (0x7FU)
#define XBARA_SEL50_SEL100_SHIFT                 (0U)
#define XBARA_SEL50_SEL100(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL50_SEL100_SHIFT)) & XBARA_SEL50_SEL100_MASK)

#define XBARA_SEL50_SEL101_MASK                  (0x7F00U)
#define XBARA_SEL50_SEL101_SHIFT                 (8U)
#define XBARA_SEL50_SEL101(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL50_SEL101_SHIFT)) & XBARA_SEL50_SEL101_MASK)
/*! @} */

/*! @name SEL51 - Crossbar A Select Register 51 */
/*! @{ */

#define XBARA_SEL51_SEL102_MASK                  (0x7FU)
#define XBARA_SEL51_SEL102_SHIFT                 (0U)
#define XBARA_SEL51_SEL102(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL51_SEL102_SHIFT)) & XBARA_SEL51_SEL102_MASK)

#define XBARA_SEL51_SEL103_MASK                  (0x7F00U)
#define XBARA_SEL51_SEL103_SHIFT                 (8U)
#define XBARA_SEL51_SEL103(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL51_SEL103_SHIFT)) & XBARA_SEL51_SEL103_MASK)
/*! @} */

/*! @name SEL52 - Crossbar A Select Register 52 */
/*! @{ */

#define XBARA_SEL52_SEL104_MASK                  (0x7FU)
#define XBARA_SEL52_SEL104_SHIFT                 (0U)
#define XBARA_SEL52_SEL104(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL52_SEL104_SHIFT)) & XBARA_SEL52_SEL104_MASK)

#define XBARA_SEL52_SEL105_MASK                  (0x7F00U)
#define XBARA_SEL52_SEL105_SHIFT                 (8U)
#define XBARA_SEL52_SEL105(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL52_SEL105_SHIFT)) & XBARA_SEL52_SEL105_MASK)
/*! @} */

/*! @name SEL53 - Crossbar A Select Register 53 */
/*! @{ */

#define XBARA_SEL53_SEL106_MASK                  (0x7FU)
#define XBARA_SEL53_SEL106_SHIFT                 (0U)
#define XBARA_SEL53_SEL106(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL53_SEL106_SHIFT)) & XBARA_SEL53_SEL106_MASK)

#define XBARA_SEL53_SEL107_MASK                  (0x7F00U)
#define XBARA_SEL53_SEL107_SHIFT                 (8U)
#define XBARA_SEL53_SEL107(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL53_SEL107_SHIFT)) & XBARA_SEL53_SEL107_MASK)
/*! @} */

/*! @name SEL54 - Crossbar A Select Register 54 */
/*! @{ */

#define XBARA_SEL54_SEL108_MASK                  (0x7FU)
#define XBARA_SEL54_SEL108_SHIFT                 (0U)
#define XBARA_SEL54_SEL108(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL54_SEL108_SHIFT)) & XBARA_SEL54_SEL108_MASK)

#define XBARA_SEL54_SEL109_MASK                  (0x7F00U)
#define XBARA_SEL54_SEL109_SHIFT                 (8U)
#define XBARA_SEL54_SEL109(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL54_SEL109_SHIFT)) & XBARA_SEL54_SEL109_MASK)
/*! @} */

/*! @name SEL55 - Crossbar A Select Register 55 */
/*! @{ */

#define XBARA_SEL55_SEL110_MASK                  (0x7FU)
#define XBARA_SEL55_SEL110_SHIFT                 (0U)
#define XBARA_SEL55_SEL110(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL55_SEL110_SHIFT)) & XBARA_SEL55_SEL110_MASK)

#define XBARA_SEL55_SEL111_MASK                  (0x7F00U)
#define XBARA_SEL55_SEL111_SHIFT                 (8U)
#define XBARA_SEL55_SEL111(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL55_SEL111_SHIFT)) & XBARA_SEL55_SEL111_MASK)
/*! @} */

/*! @name SEL56 - Crossbar A Select Register 56 */
/*! @{ */

#define XBARA_SEL56_SEL112_MASK                  (0x7FU)
#define XBARA_SEL56_SEL112_SHIFT                 (0U)
#define XBARA_SEL56_SEL112(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL56_SEL112_SHIFT)) & XBARA_SEL56_SEL112_MASK)

#define XBARA_SEL56_SEL113_MASK                  (0x7F00U)
#define XBARA_SEL56_SEL113_SHIFT                 (8U)
#define XBARA_SEL56_SEL113(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL56_SEL113_SHIFT)) & XBARA_SEL56_SEL113_MASK)
/*! @} */

/*! @name SEL57 - Crossbar A Select Register 57 */
/*! @{ */

#define XBARA_SEL57_SEL114_MASK                  (0x7FU)
#define XBARA_SEL57_SEL114_SHIFT                 (0U)
#define XBARA_SEL57_SEL114(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL57_SEL114_SHIFT)) & XBARA_SEL57_SEL114_MASK)

#define XBARA_SEL57_SEL115_MASK                  (0x7F00U)
#define XBARA_SEL57_SEL115_SHIFT                 (8U)
#define XBARA_SEL57_SEL115(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL57_SEL115_SHIFT)) & XBARA_SEL57_SEL115_MASK)
/*! @} */

/*! @name SEL58 - Crossbar A Select Register 58 */
/*! @{ */

#define XBARA_SEL58_SEL116_MASK                  (0x7FU)
#define XBARA_SEL58_SEL116_SHIFT                 (0U)
#define XBARA_SEL58_SEL116(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL58_SEL116_SHIFT)) & XBARA_SEL58_SEL116_MASK)

#define XBARA_SEL58_SEL117_MASK                  (0x7F00U)
#define XBARA_SEL58_SEL117_SHIFT                 (8U)
#define XBARA_SEL58_SEL117(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL58_SEL117_SHIFT)) & XBARA_SEL58_SEL117_MASK)
/*! @} */

/*! @name SEL59 - Crossbar A Select Register 59 */
/*! @{ */

#define XBARA_SEL59_SEL118_MASK                  (0x7FU)
#define XBARA_SEL59_SEL118_SHIFT                 (0U)
#define XBARA_SEL59_SEL118(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL59_SEL118_SHIFT)) & XBARA_SEL59_SEL118_MASK)

#define XBARA_SEL59_SEL119_MASK                  (0x7F00U)
#define XBARA_SEL59_SEL119_SHIFT                 (8U)
#define XBARA_SEL59_SEL119(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL59_SEL119_SHIFT)) & XBARA_SEL59_SEL119_MASK)
/*! @} */

/*! @name SEL60 - Crossbar A Select Register 60 */
/*! @{ */

#define XBARA_SEL60_SEL120_MASK                  (0x7FU)
#define XBARA_SEL60_SEL120_SHIFT                 (0U)
#define XBARA_SEL60_SEL120(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL60_SEL120_SHIFT)) & XBARA_SEL60_SEL120_MASK)

#define XBARA_SEL60_SEL121_MASK                  (0x7F00U)
#define XBARA_SEL60_SEL121_SHIFT                 (8U)
#define XBARA_SEL60_SEL121(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL60_SEL121_SHIFT)) & XBARA_SEL60_SEL121_MASK)
/*! @} */

/*! @name SEL61 - Crossbar A Select Register 61 */
/*! @{ */

#define XBARA_SEL61_SEL122_MASK                  (0x7FU)
#define XBARA_SEL61_SEL122_SHIFT                 (0U)
#define XBARA_SEL61_SEL122(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL61_SEL122_SHIFT)) & XBARA_SEL61_SEL122_MASK)

#define XBARA_SEL61_SEL123_MASK                  (0x7F00U)
#define XBARA_SEL61_SEL123_SHIFT                 (8U)
#define XBARA_SEL61_SEL123(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL61_SEL123_SHIFT)) & XBARA_SEL61_SEL123_MASK)
/*! @} */

/*! @name SEL62 - Crossbar A Select Register 62 */
/*! @{ */

#define XBARA_SEL62_SEL124_MASK                  (0x7FU)
#define XBARA_SEL62_SEL124_SHIFT                 (0U)
#define XBARA_SEL62_SEL124(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL62_SEL124_SHIFT)) & XBARA_SEL62_SEL124_MASK)

#define XBARA_SEL62_SEL125_MASK                  (0x7F00U)
#define XBARA_SEL62_SEL125_SHIFT                 (8U)
#define XBARA_SEL62_SEL125(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL62_SEL125_SHIFT)) & XBARA_SEL62_SEL125_MASK)
/*! @} */

/*! @name SEL63 - Crossbar A Select Register 63 */
/*! @{ */

#define XBARA_SEL63_SEL126_MASK                  (0x7FU)
#define XBARA_SEL63_SEL126_SHIFT                 (0U)
#define XBARA_SEL63_SEL126(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL63_SEL126_SHIFT)) & XBARA_SEL63_SEL126_MASK)

#define XBARA_SEL63_SEL127_MASK                  (0x7F00U)
#define XBARA_SEL63_SEL127_SHIFT                 (8U)
#define XBARA_SEL63_SEL127(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL63_SEL127_SHIFT)) & XBARA_SEL63_SEL127_MASK)
/*! @} */

/*! @name SEL64 - Crossbar A Select Register 64 */
/*! @{ */

#define XBARA_SEL64_SEL128_MASK                  (0x7FU)
#define XBARA_SEL64_SEL128_SHIFT                 (0U)
#define XBARA_SEL64_SEL128(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL64_SEL128_SHIFT)) & XBARA_SEL64_SEL128_MASK)

#define XBARA_SEL64_SEL129_MASK                  (0x7F00U)
#define XBARA_SEL64_SEL129_SHIFT                 (8U)
#define XBARA_SEL64_SEL129(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL64_SEL129_SHIFT)) & XBARA_SEL64_SEL129_MASK)
/*! @} */

/*! @name SEL65 - Crossbar A Select Register 65 */
/*! @{ */

#define XBARA_SEL65_SEL130_MASK                  (0x7FU)
#define XBARA_SEL65_SEL130_SHIFT                 (0U)
#define XBARA_SEL65_SEL130(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL65_SEL130_SHIFT)) & XBARA_SEL65_SEL130_MASK)

#define XBARA_SEL65_SEL131_MASK                  (0x7F00U)
#define XBARA_SEL65_SEL131_SHIFT                 (8U)
#define XBARA_SEL65_SEL131(x)                    (((uint16_t)(((uint16_t)(x)) << XBARA_SEL65_SEL131_SHIFT)) & XBARA_SEL65_SEL131_MASK)
/*! @} */

/*! @name CTRL0 - Crossbar A Control Register 0 */
/*! @{ */

#define XBARA_CTRL0_DEN0_MASK                    (0x1U)
#define XBARA_CTRL0_DEN0_SHIFT                   (0U)
/*! DEN0 - DMA Enable for XBAR_OUT0
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBARA_CTRL0_DEN0(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_DEN0_SHIFT)) & XBARA_CTRL0_DEN0_MASK)

#define XBARA_CTRL0_IEN0_MASK                    (0x2U)
#define XBARA_CTRL0_IEN0_SHIFT                   (1U)
/*! IEN0 - Interrupt Enable for XBAR_OUT0
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBARA_CTRL0_IEN0(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_IEN0_SHIFT)) & XBARA_CTRL0_IEN0_MASK)

#define XBARA_CTRL0_EDGE0_MASK                   (0xCU)
#define XBARA_CTRL0_EDGE0_SHIFT                  (2U)
/*! EDGE0 - Active edge for edge detection on XBAR_OUT0
 *  0b00..STS0 never asserts
 *  0b01..STS0 asserts on rising edges of XBAR_OUT0
 *  0b10..STS0 asserts on falling edges of XBAR_OUT0
 *  0b11..STS0 asserts on rising and falling edges of XBAR_OUT0
 */
#define XBARA_CTRL0_EDGE0(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_EDGE0_SHIFT)) & XBARA_CTRL0_EDGE0_MASK)

#define XBARA_CTRL0_STS0_MASK                    (0x10U)
#define XBARA_CTRL0_STS0_SHIFT                   (4U)
/*! STS0 - Edge detection status for XBAR_OUT0
 *  0b0..Active edge not yet detected on XBAR_OUT0
 *  0b1..Active edge detected on XBAR_OUT0
 */
#define XBARA_CTRL0_STS0(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_STS0_SHIFT)) & XBARA_CTRL0_STS0_MASK)

#define XBARA_CTRL0_DEN1_MASK                    (0x100U)
#define XBARA_CTRL0_DEN1_SHIFT                   (8U)
/*! DEN1 - DMA Enable for XBAR_OUT1
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBARA_CTRL0_DEN1(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_DEN1_SHIFT)) & XBARA_CTRL0_DEN1_MASK)

#define XBARA_CTRL0_IEN1_MASK                    (0x200U)
#define XBARA_CTRL0_IEN1_SHIFT                   (9U)
/*! IEN1 - Interrupt Enable for XBAR_OUT1
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBARA_CTRL0_IEN1(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_IEN1_SHIFT)) & XBARA_CTRL0_IEN1_MASK)

#define XBARA_CTRL0_EDGE1_MASK                   (0xC00U)
#define XBARA_CTRL0_EDGE1_SHIFT                  (10U)
/*! EDGE1 - Active edge for edge detection on XBAR_OUT1
 *  0b00..STS1 never asserts
 *  0b01..STS1 asserts on rising edges of XBAR_OUT1
 *  0b10..STS1 asserts on falling edges of XBAR_OUT1
 *  0b11..STS1 asserts on rising and falling edges of XBAR_OUT1
 */
#define XBARA_CTRL0_EDGE1(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_EDGE1_SHIFT)) & XBARA_CTRL0_EDGE1_MASK)

#define XBARA_CTRL0_STS1_MASK                    (0x1000U)
#define XBARA_CTRL0_STS1_SHIFT                   (12U)
/*! STS1 - Edge detection status for XBAR_OUT1
 *  0b0..Active edge not yet detected on XBAR_OUT1
 *  0b1..Active edge detected on XBAR_OUT1
 */
#define XBARA_CTRL0_STS1(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_STS1_SHIFT)) & XBARA_CTRL0_STS1_MASK)
/*! @} */

/*! @name CTRL1 - Crossbar A Control Register 1 */
/*! @{ */

#define XBARA_CTRL1_DEN2_MASK                    (0x1U)
#define XBARA_CTRL1_DEN2_SHIFT                   (0U)
/*! DEN2 - DMA Enable for XBAR_OUT2
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBARA_CTRL1_DEN2(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_DEN2_SHIFT)) & XBARA_CTRL1_DEN2_MASK)

#define XBARA_CTRL1_IEN2_MASK                    (0x2U)
#define XBARA_CTRL1_IEN2_SHIFT                   (1U)
/*! IEN2 - Interrupt Enable for XBAR_OUT2
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBARA_CTRL1_IEN2(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_IEN2_SHIFT)) & XBARA_CTRL1_IEN2_MASK)

#define XBARA_CTRL1_EDGE2_MASK                   (0xCU)
#define XBARA_CTRL1_EDGE2_SHIFT                  (2U)
/*! EDGE2 - Active edge for edge detection on XBAR_OUT2
 *  0b00..STS2 never asserts
 *  0b01..STS2 asserts on rising edges of XBAR_OUT2
 *  0b10..STS2 asserts on falling edges of XBAR_OUT2
 *  0b11..STS2 asserts on rising and falling edges of XBAR_OUT2
 */
#define XBARA_CTRL1_EDGE2(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_EDGE2_SHIFT)) & XBARA_CTRL1_EDGE2_MASK)

#define XBARA_CTRL1_STS2_MASK                    (0x10U)
#define XBARA_CTRL1_STS2_SHIFT                   (4U)
/*! STS2 - Edge detection status for XBAR_OUT2
 *  0b0..Active edge not yet detected on XBAR_OUT2
 *  0b1..Active edge detected on XBAR_OUT2
 */
#define XBARA_CTRL1_STS2(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_STS2_SHIFT)) & XBARA_CTRL1_STS2_MASK)

#define XBARA_CTRL1_DEN3_MASK                    (0x100U)
#define XBARA_CTRL1_DEN3_SHIFT                   (8U)
/*! DEN3 - DMA Enable for XBAR_OUT3
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBARA_CTRL1_DEN3(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_DEN3_SHIFT)) & XBARA_CTRL1_DEN3_MASK)

#define XBARA_CTRL1_IEN3_MASK                    (0x200U)
#define XBARA_CTRL1_IEN3_SHIFT                   (9U)
/*! IEN3 - Interrupt Enable for XBAR_OUT3
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBARA_CTRL1_IEN3(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_IEN3_SHIFT)) & XBARA_CTRL1_IEN3_MASK)

#define XBARA_CTRL1_EDGE3_MASK                   (0xC00U)
#define XBARA_CTRL1_EDGE3_SHIFT                  (10U)
/*! EDGE3 - Active edge for edge detection on XBAR_OUT3
 *  0b00..STS3 never asserts
 *  0b01..STS3 asserts on rising edges of XBAR_OUT3
 *  0b10..STS3 asserts on falling edges of XBAR_OUT3
 *  0b11..STS3 asserts on rising and falling edges of XBAR_OUT3
 */
#define XBARA_CTRL1_EDGE3(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_EDGE3_SHIFT)) & XBARA_CTRL1_EDGE3_MASK)

#define XBARA_CTRL1_STS3_MASK                    (0x1000U)
#define XBARA_CTRL1_STS3_SHIFT                   (12U)
/*! STS3 - Edge detection status for XBAR_OUT3
 *  0b0..Active edge not yet detected on XBAR_OUT3
 *  0b1..Active edge detected on XBAR_OUT3
 */
#define XBARA_CTRL1_STS3(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_STS3_SHIFT)) & XBARA_CTRL1_STS3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XBARA_Register_Masks */


/*!
 * @}
 */ /* end of group XBARA_Peripheral_Access_Layer */


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


#endif  /* PERI_XBARA_H_ */

