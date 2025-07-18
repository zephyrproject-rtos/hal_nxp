/*
** ###################################################################
**     Processors:          MIMXRT1011CAE4A
**                          MIMXRT1011DAE5A
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
**     - rev. 0.1 (2019-02-14)
**         Initial version.
**     - rev. 1.0 (2019-08-01)
**         Rev.0 Header GA
**     - rev. 1.1 (2019-08-06)
**         Update header files to align with IMXRT1010RM Rev.B.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1010RM Rev.1.
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

#if (defined(CPU_MIMXRT1011CAE4A) || defined(CPU_MIMXRT1011DAE5A))
#include "MIMXRT1011_COMMON.h"
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
    kXBARA1_InputRESERVED0          = 0|0x100U,    /**< XBARA_IN0 input is reserved. */
    kXBARA1_InputLogicHigh          = 1|0x100U,    /**< LOGIC_HIGH output assigned to XBARA_IN1 input. */
    kXBARA1_InputIomuxXbarInout02   = 2|0x100U,    /**< IOMUX_XBAR_INOUT02 output assigned to XBARA_IN2 input. */
    kXBARA1_InputIomuxXbarInout03   = 3|0x100U,    /**< IOMUX_XBAR_INOUT03 output assigned to XBARA_IN3 input. */
    kXBARA1_InputFlexpwm1Pwm1OutTrig01 = 4|0x100U, /**< FLEXPWM1_PWM1_OUT_TRIG0_1 output assigned to XBARA_IN4 input. */
    kXBARA1_InputFlexpwm1Pwm2OutTrig01 = 5|0x100U, /**< FLEXPWM1_PWM2_OUT_TRIG0_1 output assigned to XBARA_IN5 input. */
    kXBARA1_InputFlexpwm1Pwm3OutTrig01 = 6|0x100U, /**< FLEXPWM1_PWM3_OUT_TRIG0_1 output assigned to XBARA_IN6 input. */
    kXBARA1_InputFlexpwm1Pwm4OutTrig01 = 7|0x100U, /**< FLEXPWM1_PWM4_OUT_TRIG0_1 output assigned to XBARA_IN7 input. */
    kXBARA1_InputPitTrigger0        = 8|0x100U,    /**< PIT_TRIGGER0 output assigned to XBARA_IN8 input. */
    kXBARA1_InputPitTrigger1        = 9|0x100U,    /**< PIT_TRIGGER1 output assigned to XBARA_IN9 input. */
    kXBARA1_InputPitTrigger2        = 10|0x100U,   /**< PIT_TRIGGER2 output assigned to XBARA_IN10 input. */
    kXBARA1_InputPitTrigger3        = 11|0x100U,   /**< PIT_TRIGGER3 output assigned to XBARA_IN11 input. */
    kXBARA1_InputDmaDone0           = 12|0x100U,   /**< DMA_DONE0 output assigned to XBARA_IN12 input. */
    kXBARA1_InputDmaDone1           = 13|0x100U,   /**< DMA_DONE1 output assigned to XBARA_IN13 input. */
    kXBARA1_InputDmaDone2           = 14|0x100U,   /**< DMA_DONE2 output assigned to XBARA_IN14 input. */
    kXBARA1_InputDmaDone3           = 15|0x100U,   /**< DMA_DONE3 output assigned to XBARA_IN15 input. */
    kXBARA1_InputDmaDone4           = 16|0x100U,   /**< DMA_DONE4 output assigned to XBARA_IN16 input. */
    kXBARA1_InputDmaDone5           = 17|0x100U,   /**< DMA_DONE5 output assigned to XBARA_IN17 input. */
    kXBARA1_InputDmaDone6           = 18|0x100U,   /**< DMA_DONE6 output assigned to XBARA_IN18 input. */
    kXBARA1_InputDmaDone7           = 19|0x100U,   /**< DMA_DONE7 output assigned to XBARA_IN19 input. */
    kXBARA1_InputAoi1Out0           = 20|0x100U,   /**< AOI1_OUT0 output assigned to XBARA_IN20 input. */
    kXBARA1_InputAoi1Out1           = 21|0x100U,   /**< AOI1_OUT1 output assigned to XBARA_IN21 input. */
    kXBARA1_InputAoi1Out2           = 22|0x100U,   /**< AOI1_OUT2 output assigned to XBARA_IN22 input. */
    kXBARA1_InputAoi1Out3           = 23|0x100U,   /**< AOI1_OUT3 output assigned to XBARA_IN23 input. */
    kXBARA1_InputAdcEtc0Coco0       = 24|0x100U,   /**< ADC_ETC0_COCO0 output assigned to XBARA_IN24 input. */
    kXBARA1_InputAdcEtc0Coco1       = 25|0x100U,   /**< ADC_ETC0_COCO1 output assigned to XBARA_IN25 input. */
    kXBARA1_InputAdcEtc0Coco2       = 26|0x100U,   /**< ADC_ETC0_COCO2 output assigned to XBARA_IN26 input. */
    kXBARA1_InputAdcEtc0Coco3       = 27|0x100U,   /**< ADC_ETC0_COCO3 output assigned to XBARA_IN27 input. */
} xbar_input_signal_t;
#endif /* XBAR_INPUT_SIGNAL_T_ */

#if !defined(XBAR_OUTPUT_SIGNAL_T_)
#define XBAR_OUTPUT_SIGNAL_T_
typedef enum _xbar_output_signal
{
    kXBARA1_OutputFlexio1TriggerIn0 = 0|0x100U,    /**< XBARA_OUT0 output assigned to FLEXIO1_TRIGGER_IN0 */
    kXBARA1_OutputFlexio1TriggerIn1 = 1|0x100U,    /**< XBARA_OUT1 output assigned to FLEXIO1_TRIGGER_IN1 */
    kXBARA1_OutputIomuxXbarInout02  = 2|0x100U,    /**< XBARA_OUT2 output assigned to IOMUX_XBAR_INOUT02 */
    kXBARA1_OutputIomuxXbarInout03  = 3|0x100U,    /**< XBARA_OUT3 output assigned to IOMUX_XBAR_INOUT03 */
    kXBARA1_OutputFlexpwm1Exta0     = 4|0x100U,    /**< XBARA_OUT4 output assigned to FLEXPWM1_EXTA0 */
    kXBARA1_OutputFlexpwm1Exta1     = 5|0x100U,    /**< XBARA_OUT5 output assigned to FLEXPWM1_EXTA1 */
    kXBARA1_OutputFlexpwm1Exta2     = 6|0x100U,    /**< XBARA_OUT6 output assigned to FLEXPWM1_EXTA2 */
    kXBARA1_OutputFlexpwm1Exta3     = 7|0x100U,    /**< XBARA_OUT7 output assigned to FLEXPWM1_EXTA3 */
    kXBARA1_OutputFlexpwm1ExtSync0  = 8|0x100U,    /**< XBARA_OUT8 output assigned to FLEXPWM1_EXT_SYNC0 */
    kXBARA1_OutputFlexpwm1ExtSync1  = 9|0x100U,    /**< XBARA_OUT9 output assigned to FLEXPWM1_EXT_SYNC1 */
    kXBARA1_OutputFlexpwm1ExtSync2  = 10|0x100U,   /**< XBARA_OUT10 output assigned to FLEXPWM1_EXT_SYNC2 */
    kXBARA1_OutputFlexpwm1ExtSync3  = 11|0x100U,   /**< XBARA_OUT11 output assigned to FLEXPWM1_EXT_SYNC3 */
    kXBARA1_OutputFlexpwm1ExtClk    = 12|0x100U,   /**< XBARA_OUT12 output assigned to FLEXPWM1_EXT_CLK */
    kXBARA1_OutputFlexpwm1Fault0    = 13|0x100U,   /**< XBARA_OUT13 output assigned to FLEXPWM1_FAULT0 */
    kXBARA1_OutputFlexpwm1Fault1    = 14|0x100U,   /**< XBARA_OUT14 output assigned to FLEXPWM1_FAULT1 */
    kXBARA1_OutputFlexpwm1Fault2    = 15|0x100U,   /**< XBARA_OUT15 output assigned to FLEXPWM1_FAULT2 */
    kXBARA1_OutputFlexpwm1Fault3    = 16|0x100U,   /**< XBARA_OUT16 output assigned to FLEXPWM1_FAULT3 */
    kXBARA1_OutputFlexpwm1ExtForce  = 17|0x100U,   /**< XBARA_OUT17 output assigned to FLEXPWM1_EXT_FORCE */
    kXBARA1_OutputEwmEwmIn          = 18|0x100U,   /**< XBARA_OUT18 output assigned to EWM_EWM_IN */
    kXBARA1_OutputAdcEtcTrig00      = 19|0x100U,   /**< XBARA_OUT19 output assigned to ADC_ETC_TRIG00 */
    kXBARA1_OutputAdcEtcTrig01      = 20|0x100U,   /**< XBARA_OUT20 output assigned to ADC_ETC_TRIG01 */
    kXBARA1_OutputAdcEtcTrig02      = 21|0x100U,   /**< XBARA_OUT21 output assigned to ADC_ETC_TRIG02 */
    kXBARA1_OutputAdcEtcTrig03      = 22|0x100U,   /**< XBARA_OUT22 output assigned to ADC_ETC_TRIG03 */
    kXBARA1_OutputLpi2c1TrgInput    = 23|0x100U,   /**< XBARA_OUT23 output assigned to LPI2C1_TRG_INPUT */
    kXBARA1_OutputLpi2c2TrgInput    = 24|0x100U,   /**< XBARA_OUT24 output assigned to LPI2C2_TRG_INPUT */
    kXBARA1_OutputLpspi1TrgInput    = 25|0x100U,   /**< XBARA_OUT25 output assigned to LPSPI1_TRG_INPUT */
    kXBARA1_OutputLpspi2TrgInput    = 26|0x100U,   /**< XBARA_OUT26 output assigned to LPSPI2_TRG_INPUT */
    kXBARA1_OutputLpuart1TrgInput   = 27|0x100U,   /**< XBARA_OUT27 output assigned to LPUART1_TRG_INPUT */
    kXBARA1_OutputLpuart2TrgInput   = 28|0x100U,   /**< XBARA_OUT28 output assigned to LPUART2_TRG_INPUT */
    kXBARA1_OutputLpuart3TrgInput   = 29|0x100U,   /**< XBARA_OUT29 output assigned to LPUART3_TRG_INPUT */
    kXBARA1_OutputLpuart4TrgInput   = 30|0x100U,   /**< XBARA_OUT30 output assigned to LPUART4_TRG_INPUT */
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

