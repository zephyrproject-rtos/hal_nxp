/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XBAR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2014-10-17)
**         Initial version.
**     - rev. 1.1 (2015-01-27)
**         Update according to reference manual rev. 1, RC.
**     - rev. 1.2 (2015-03-06)
**         Update according to reference manual rev. 1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_XBAR.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XBAR
 *
 * CMSIS Peripheral Access Layer for XBAR
 */

#if !defined(PERI_XBAR_H_)
#define PERI_XBAR_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKM34Z256VLL7) || defined(CPU_MKM34Z256VLQ7))
#include "MKM34Z7_COMMON.h"
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
    kXBAR_InputVdd                  = 0|0x100U,    /**< Logic 1 (VDD) output assigned to XBAR_IN0 input. */
    kXBAR_InputVss                  = 1|0x100U,    /**< Logic 0 (VSS) output assigned to XBAR_IN1 input. */
    kXBAR_InputAfeClock             = 2|0x100U,    /**< AFE modulator clock output output assigned to XBAR_IN2 input. */
    kXBAR_InputAfeMod0DataOutput    = 3|0x100U,    /**< AFE modulator 0 data output output assigned to XBAR_IN3 input. */
    kXBAR_InputLptmr0Output         = 4|0x100U,    /**< LPTimer Output output assigned to XBAR_IN4 input. */
    kXBAR_InputClockOutput          = 5|0x100U,    /**< Clock Output output assigned to XBAR_IN5 input. */
    kXBAR_InputTmrCh0Output         = 6|0x100U,    /**< Quad Timer channel 0 output output assigned to XBAR_IN6 input. */
    kXBAR_InputTmrCh1Output         = 7|0x100U,    /**< Quad Timer channel 1 output output assigned to XBAR_IN7 input. */
    kXBAR_InputTmrCh2Output         = 8|0x100U,    /**< Quad Timer channel 2 output output assigned to XBAR_IN8 input. */
    kXBAR_InputTmrCh3Output         = 9|0x100U,    /**< Quad Timer channel 3 output output assigned to XBAR_IN9 input. */
    kXBAR_InputRtcClockOutput       = 10|0x100U,   /**< iRTC Clock Output output assigned to XBAR_IN10 input. */
    kXBAR_InputCmp0Output           = 11|0x100U,   /**< CMP0 Output output assigned to XBAR_IN11 input. */
    kXBAR_InputCmp1Output           = 12|0x100U,   /**< CMP1 Output output assigned to XBAR_IN12 input. */
    kXBAR_InputRtcAlarmOutput       = 13|0x100U,   /**< iRTC Alarm Output output assigned to XBAR_IN13 input. */
    kXBAR_InputUartTxOutput         = 14|0x100U,   /**< UART TX Output (after modulation) output assigned to XBAR_IN14 input. */
    kXBAR_InputEwmOutput            = 15|0x100U,   /**< EWM Output (EWM_OUT) output assigned to XBAR_IN15 input. */
    kXBAR_InputPit0Tif0             = 16|0x100U,   /**< PIT 0 Timer Interrupt Flag 0 (Timeout 0) output assigned to XBAR_IN16 input. */
    kXBAR_InputXbarIn0              = 17|0x100U,   /**< XBAR Input pin 0 output assigned to XBAR_IN17 input. */
    kXBAR_InputXbarIn1              = 18|0x100U,   /**< XBAR Input pin 1 output assigned to XBAR_IN18 input. */
    kXBAR_InputXbarIn2              = 19|0x100U,   /**< XBAR Input pin 2 output assigned to XBAR_IN19 input. */
    kXBAR_InputXbarIn3              = 20|0x100U,   /**< XBAR Input pin 3 output assigned to XBAR_IN20 input. */
    kXBAR_InputXbarIn4              = 21|0x100U,   /**< XBAR Input pin 4 output assigned to XBAR_IN21 input. */
    kXBAR_InputXbarIn5              = 22|0x100U,   /**< XBAR Input pin 5 output assigned to XBAR_IN22 input. */
    kXBAR_InputXbarIn6              = 23|0x100U,   /**< XBAR Input pin 6 output assigned to XBAR_IN23 input. */
    kXBAR_InputXbarIn7              = 24|0x100U,   /**< XBAR Input pin 7 output assigned to XBAR_IN24 input. */
    kXBAR_InputXbarIn8              = 25|0x100U,   /**< XBAR Input pin 8 output assigned to XBAR_IN25 input. */
    kXBAR_InputAdcCocoFlag          = 26|0x100U,   /**< ORed conversion complete flag for all SAR ADC channels output assigned to XBAR_IN26 input. */
    kXBAR_InputAfeAllCocFlag        = 27|0x100U,   /**< ORed conversion complete flag for all AFE channels output assigned to XBAR_IN27 input. */
    kXBAR_InputAfeCh0CocFlag        = 28|0x100U,   /**< AFE Channel 0 conversion complete output assigned to XBAR_IN28 input. */
    kXBAR_InputAfeCh1CocFlag        = 29|0x100U,   /**< AFE Channel 1 conversion complete output assigned to XBAR_IN29 input. */
    kXBAR_InputAfeCh2CocFlag        = 30|0x100U,   /**< AFE Channel 2 conversion complete output assigned to XBAR_IN30 input. */
    kXBAR_InputAfeCh3CocFlag        = 31|0x100U,   /**< AFE Channel 3 conversion complete output assigned to XBAR_IN31 input. */
    kXBAR_InputDmaDoneSignal        = 32|0x100U,   /**< DMA Done Signal output assigned to XBAR_IN32 input. */
    kXBAR_InputXbarIn9              = 33|0x100U,   /**< XBAR Input pin 9 output assigned to XBAR_IN33 input. */
    kXBAR_InputXbarIn10             = 34|0x100U,   /**< XBAR Input pin 10 output assigned to XBAR_IN34 input. */
    kXBAR_InputCmp2Output           = 35|0x100U,   /**< CMP2 Output output assigned to XBAR_IN35 input. */
    kXBAR_InputPit0Tif1             = 36|0x100U,   /**< PIT 0 Timer Interrupt Flag 1 (Timeout 1) output assigned to XBAR_IN36 input. */
    kXBAR_InputPit1Tif0             = 37|0x100U,   /**< PIT 1 Timer Interrupt Flag 0 (Timeout 0) output assigned to XBAR_IN37 input. */
    kXBAR_InputPit1Tif1             = 38|0x100U,   /**< PIT 1 Timer Interrupt Flag 1 (Timeout 1) output assigned to XBAR_IN38 input. */
    kXBAR_InputAfeMod1DataOutput    = 39|0x100U,   /**< AFE modulator 1 data output output assigned to XBAR_IN39 input. */
    kXBAR_InputAfeMod2DataOutput    = 40|0x100U,   /**< AFE modulator 2 data output output assigned to XBAR_IN40 input. */
    kXBAR_InputAfeMod3DataOutput    = 41|0x100U,   /**< AFE modulator 3 data output output assigned to XBAR_IN41 input. */
    kXBAR_InputAdcCocoA             = 42|0x100U,   /**< SAR ADC conversion complete A output assigned to XBAR_IN42 input. */
    kXBAR_InputAdcCocoB             = 43|0x100U,   /**< SAR ADC conversion complete B output assigned to XBAR_IN43 input. */
    kXBAR_InputAdcCocoC             = 44|0x100U,   /**< SAR ADC conversion complete C output assigned to XBAR_IN44 input. */
    kXBAR_InputAdcCocoD             = 45|0x100U,   /**< SAR ADC conversion complete D output assigned to XBAR_IN45 input. */
    kXBAR_InputPdb0Ch0Pretrigger0   = 46|0x100U,   /**< PDB0 CH0 Pre-trigger 0 output assigned to XBAR_IN46 input. */
    kXBAR_InputPdb0Ch0Pretrigger1   = 47|0x100U,   /**< PDB0 CH0 Pre-trigger 1 output assigned to XBAR_IN47 input. */
    kXBAR_InputPdb0Ch0Pretrigger2   = 48|0x100U,   /**< PDB0 CH0 Pre-trigger 2 output assigned to XBAR_IN48 input. */
    kXBAR_InputPdb0Ch0Pretrigger3   = 49|0x100U,   /**< PDB0 CH0 Pre-trigger 3 output assigned to XBAR_IN49 input. */
    kXBAR_InputPdb0Ch0Trigger       = 50|0x100U,   /**< PDB0 CH0 Trigger output assigned to XBAR_IN50 input. */
    kXBAR_InputPdb0PulseOut0        = 51|0x100U,   /**< PDB0 Pulse-Out 0 output assigned to XBAR_IN51 input. */
} xbar_input_signal_t;
#endif /* XBAR_INPUT_SIGNAL_T_ */

#if !defined(XBAR_OUTPUT_SIGNAL_T_)
#define XBAR_OUTPUT_SIGNAL_T_
typedef enum _xbar_output_signal
{
    kXBAR_OutputXbDmaInt0           = 0|0x100U,    /**< XBAR_OUT0 output assigned to XBAR DMA request or Interrupt 0 */
    kXBAR_OutputXbDmaInt1           = 1|0x100U,    /**< XBAR_OUT1 output assigned to XBAR DMA request or Interrupt 1 */
    kXBAR_OutputXbDmaInt2           = 2|0x100U,    /**< XBAR_OUT2 output assigned to XBAR DMA request or Interrupt 2 */
    kXBAR_OutputXbDmaInt3           = 3|0x100U,    /**< XBAR_OUT3 output assigned to XBAR DMA request or Interrupt 3 */
    kXBAR_OutputCmp2SampleWinInput  = 4|0x100U,    /**< XBAR_OUT4 output assigned to CMP2 Sample Window input */
    kXBAR_OutputTmrCh0SecInput      = 5|0x100U,    /**< XBAR_OUT5 output assigned to Quad Timer channel 0 secondary input */
    kXBAR_OutputTmrCh1SecInput      = 6|0x100U,    /**< XBAR_OUT6 output assigned to Quad Timer channel 1 secondary input */
    kXBAR_OutputTmrCh2SecInput      = 7|0x100U,    /**< XBAR_OUT7 output assigned to Quad Timer channel 2 secondary input */
    kXBAR_OutputTmrCh3SecInput      = 8|0x100U,    /**< XBAR_OUT8 output assigned to Quad Timer channel 3 secondary input */
    kXBAR_OutputTmrClockInput1      = 9|0x100U,    /**< XBAR_OUT9 output assigned to Quad Timer primary clock input 1 */
    kXBAR_OutputTmrClockInput2      = 10|0x100U,   /**< XBAR_OUT10 output assigned to Quad Timer primary clock input 2 */
    kXBAR_OutputCmp0SampleWinInput  = 11|0x100U,   /**< XBAR_OUT11 output assigned to CMP0 Sample Window input */
    kXBAR_OutputCmp1SampleWinInput  = 12|0x100U,   /**< XBAR_OUT12 output assigned to CMP1 Sample Window input */
    kXBAR_OutputUartRxInput         = 13|0x100U,   /**< XBAR_OUT13 output assigned to UART Rx IrDA Input */
    kXBAR_OutputUartTxModCarrier    = 14|0x100U,   /**< XBAR_OUT14 output assigned to SIM UART Tx IrDA Modulator Carrier Input */
    kXBAR_OutputAdcTrgA             = 15|0x100U,   /**< XBAR_OUT15 output assigned to SAR ADC trigger select A pulse */
    kXBAR_OutputAdcTrgB             = 16|0x100U,   /**< XBAR_OUT16 output assigned to SAR ADC trigger select B pulse */
    kXBAR_OutputXbOut0              = 17|0x100U,   /**< XBAR_OUT17 output assigned to XBAR Output pin 0 */
    kXBAR_OutputXbOut1              = 18|0x100U,   /**< XBAR_OUT18 output assigned to XBAR Output pin 1 */
    kXBAR_OutputXbOut2              = 19|0x100U,   /**< XBAR_OUT19 output assigned to XBAR Output pin 2 */
    kXBAR_OutputXbOut3              = 20|0x100U,   /**< XBAR_OUT20 output assigned to XBAR Output pin 3 */
    kXBAR_OutputXbOut4              = 21|0x100U,   /**< XBAR_OUT21 output assigned to XBAR Output pin 4 */
    kXBAR_OutputXbOut5              = 22|0x100U,   /**< XBAR_OUT22 output assigned to XBAR Output pin 5 */
    kXBAR_OutputXbOut6              = 23|0x100U,   /**< XBAR_OUT23 output assigned to XBAR Output pin 6 */
    kXBAR_OutputXbOut7              = 24|0x100U,   /**< XBAR_OUT24 output assigned to XBAR Output pin 7 */
    kXBAR_OutputXbOut8              = 25|0x100U,   /**< XBAR_OUT25 output assigned to XBAR Output pin 8 */
    kXBAR_OutputAdcTrgC             = 26|0x100U,   /**< XBAR_OUT26 output assigned to SAR ADC trigger select C pulse */
    kXBAR_OutputAdcTrgD             = 27|0x100U,   /**< XBAR_OUT27 output assigned to SAR ADC trigger select D pulse */
    kXBAR_OutputAfeCh0Trg           = 28|0x100U,   /**< XBAR_OUT28 output assigned to AFE Channel 0 Trigger */
    kXBAR_OutputAfeCh1Trg           = 29|0x100U,   /**< XBAR_OUT29 output assigned to AFE Channel 1 Trigger */
    kXBAR_OutputAfeCh2Trg           = 30|0x100U,   /**< XBAR_OUT30 output assigned to AFE Channel 2 Trigger */
    kXBAR_OutputAfeCh3Trg           = 31|0x100U,   /**< XBAR_OUT31 output assigned to AFE Channel 3 Trigger */
    kXBAR_OutputEwmIn               = 32|0x100U,   /**< XBAR_OUT32 output assigned to EWM input (EWM_IN) */
    kXBAR_OutputXbOut9              = 33|0x100U,   /**< XBAR_OUT33 output assigned to XBAR Output pin 9 */
    kXBAR_OutputXbOut10             = 34|0x100U,   /**< XBAR_OUT34 output assigned to XBAR Output pin 10 */
    kXBAR_OutputPdb0PreTrigger0Ack  = 35|0x100U,   /**< XBAR_OUT35 output assigned to PDB0 Pre-trigger0 B2B Ack */
    kXBAR_OutputPdb0PreTrigger1Ack  = 36|0x100U,   /**< XBAR_OUT36 output assigned to PDB0 Pre-trigger1 B2B Ack */
    kXBAR_OutputPdb0PreTrigger2Ack  = 37|0x100U,   /**< XBAR_OUT37 output assigned to PDB0 Pre-trigger2 B2B Ack */
    kXBAR_OutputPdb0PreTrigger3Ack  = 38|0x100U,   /**< XBAR_OUT38 output assigned to PDB0 Pre-trigger3 B2B Ack */
    kXBAR_OutputPdb0TriggerInput    = 39|0x100U,   /**< XBAR_OUT39 output assigned to PDB0 Trigger Input */
    kXBAR_OutputAfeCh0ExmodData     = 40|0x100U,   /**< XBAR_OUT40 output assigned to External modulator data input for AFE Channel 0 */
    kXBAR_OutputAfeCh1ExmodData     = 41|0x100U,   /**< XBAR_OUT41 output assigned to External modulator data input for AFE Channel 1 */
    kXBAR_OutputAfeCh2ExmodData     = 42|0x100U,   /**< XBAR_OUT42 output assigned to External modulator data input for AFE Channel 2 */
    kXBAR_OutputAfeCh3ExmodData     = 43|0x100U,   /**< XBAR_OUT43 output assigned to External modulator data input for AFE Channel 3 */
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
   -- XBAR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_Peripheral_Access_Layer XBAR Peripheral Access Layer
 * @{
 */

/** XBAR - Register Layout Typedef */
typedef struct {
  __IO uint16_t SEL0;                              /**< Crossbar Select Register 0, offset: 0x0 */
  __IO uint16_t SEL1;                              /**< Crossbar Select Register 1, offset: 0x2 */
  __IO uint16_t SEL2;                              /**< Crossbar Select Register 2, offset: 0x4 */
  __IO uint16_t SEL3;                              /**< Crossbar Select Register 3, offset: 0x6 */
  __IO uint16_t SEL4;                              /**< Crossbar Select Register 4, offset: 0x8 */
  __IO uint16_t SEL5;                              /**< Crossbar Select Register 5, offset: 0xA */
  __IO uint16_t SEL6;                              /**< Crossbar Select Register 6, offset: 0xC */
  __IO uint16_t SEL7;                              /**< Crossbar Select Register 7, offset: 0xE */
  __IO uint16_t SEL8;                              /**< Crossbar Select Register 8, offset: 0x10 */
  __IO uint16_t SEL9;                              /**< Crossbar Select Register 9, offset: 0x12 */
  __IO uint16_t SEL10;                             /**< Crossbar Select Register 10, offset: 0x14 */
  __IO uint16_t SEL11;                             /**< Crossbar Select Register 11, offset: 0x16 */
  __IO uint16_t SEL12;                             /**< Crossbar Select Register 12, offset: 0x18 */
  __IO uint16_t SEL13;                             /**< Crossbar Select Register 13, offset: 0x1A */
  __IO uint16_t SEL14;                             /**< Crossbar Select Register 14, offset: 0x1C */
  __IO uint16_t SEL15;                             /**< Crossbar Select Register 15, offset: 0x1E */
  __IO uint16_t SEL16;                             /**< Crossbar Select Register 16, offset: 0x20 */
  __IO uint16_t SEL17;                             /**< Crossbar Select Register 17, offset: 0x22 */
  __IO uint16_t SEL18;                             /**< Crossbar Select Register 18, offset: 0x24 */
  __IO uint16_t SEL19;                             /**< Crossbar Select Register 19, offset: 0x26 */
  __IO uint16_t SEL20;                             /**< Crossbar Select Register 20, offset: 0x28 */
  __IO uint16_t SEL21;                             /**< Crossbar Select Register 21, offset: 0x2A */
  __IO uint16_t CTRL0;                             /**< Crossbar Control Register 0, offset: 0x2C */
  __IO uint16_t CTRL1;                             /**< Crossbar Control Register 1, offset: 0x2E */
} XBAR_Type;

/* ----------------------------------------------------------------------------
   -- XBAR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_Register_Masks XBAR Register Masks
 * @{
 */

/*! @name SEL0 - Crossbar Select Register 0 */
/*! @{ */

#define XBAR_SEL0_SEL0_MASK                      (0x3FU)
#define XBAR_SEL0_SEL0_SHIFT                     (0U)
/*! SEL0
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL0_SEL0(x)                        (((uint16_t)(((uint16_t)(x)) << XBAR_SEL0_SEL0_SHIFT)) & XBAR_SEL0_SEL0_MASK)

#define XBAR_SEL0_SEL1_MASK                      (0x3F00U)
#define XBAR_SEL0_SEL1_SHIFT                     (8U)
/*! SEL1
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL0_SEL1(x)                        (((uint16_t)(((uint16_t)(x)) << XBAR_SEL0_SEL1_SHIFT)) & XBAR_SEL0_SEL1_MASK)
/*! @} */

/*! @name SEL1 - Crossbar Select Register 1 */
/*! @{ */

#define XBAR_SEL1_SEL2_MASK                      (0x3FU)
#define XBAR_SEL1_SEL2_SHIFT                     (0U)
/*! SEL2
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL1_SEL2(x)                        (((uint16_t)(((uint16_t)(x)) << XBAR_SEL1_SEL2_SHIFT)) & XBAR_SEL1_SEL2_MASK)

#define XBAR_SEL1_SEL3_MASK                      (0x3F00U)
#define XBAR_SEL1_SEL3_SHIFT                     (8U)
/*! SEL3
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL1_SEL3(x)                        (((uint16_t)(((uint16_t)(x)) << XBAR_SEL1_SEL3_SHIFT)) & XBAR_SEL1_SEL3_MASK)
/*! @} */

/*! @name SEL2 - Crossbar Select Register 2 */
/*! @{ */

#define XBAR_SEL2_SEL4_MASK                      (0x3FU)
#define XBAR_SEL2_SEL4_SHIFT                     (0U)
/*! SEL4
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL2_SEL4(x)                        (((uint16_t)(((uint16_t)(x)) << XBAR_SEL2_SEL4_SHIFT)) & XBAR_SEL2_SEL4_MASK)

#define XBAR_SEL2_SEL5_MASK                      (0x3F00U)
#define XBAR_SEL2_SEL5_SHIFT                     (8U)
/*! SEL5
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL2_SEL5(x)                        (((uint16_t)(((uint16_t)(x)) << XBAR_SEL2_SEL5_SHIFT)) & XBAR_SEL2_SEL5_MASK)
/*! @} */

/*! @name SEL3 - Crossbar Select Register 3 */
/*! @{ */

#define XBAR_SEL3_SEL6_MASK                      (0x3FU)
#define XBAR_SEL3_SEL6_SHIFT                     (0U)
/*! SEL6
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL3_SEL6(x)                        (((uint16_t)(((uint16_t)(x)) << XBAR_SEL3_SEL6_SHIFT)) & XBAR_SEL3_SEL6_MASK)

#define XBAR_SEL3_SEL7_MASK                      (0x3F00U)
#define XBAR_SEL3_SEL7_SHIFT                     (8U)
/*! SEL7
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL3_SEL7(x)                        (((uint16_t)(((uint16_t)(x)) << XBAR_SEL3_SEL7_SHIFT)) & XBAR_SEL3_SEL7_MASK)
/*! @} */

/*! @name SEL4 - Crossbar Select Register 4 */
/*! @{ */

#define XBAR_SEL4_SEL8_MASK                      (0x3FU)
#define XBAR_SEL4_SEL8_SHIFT                     (0U)
/*! SEL8
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL4_SEL8(x)                        (((uint16_t)(((uint16_t)(x)) << XBAR_SEL4_SEL8_SHIFT)) & XBAR_SEL4_SEL8_MASK)

#define XBAR_SEL4_SEL9_MASK                      (0x3F00U)
#define XBAR_SEL4_SEL9_SHIFT                     (8U)
/*! SEL9
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL4_SEL9(x)                        (((uint16_t)(((uint16_t)(x)) << XBAR_SEL4_SEL9_SHIFT)) & XBAR_SEL4_SEL9_MASK)
/*! @} */

/*! @name SEL5 - Crossbar Select Register 5 */
/*! @{ */

#define XBAR_SEL5_SEL10_MASK                     (0x3FU)
#define XBAR_SEL5_SEL10_SHIFT                    (0U)
/*! SEL10
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL5_SEL10(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_SEL5_SEL10_SHIFT)) & XBAR_SEL5_SEL10_MASK)

#define XBAR_SEL5_SEL11_MASK                     (0x3F00U)
#define XBAR_SEL5_SEL11_SHIFT                    (8U)
/*! SEL11
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL5_SEL11(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_SEL5_SEL11_SHIFT)) & XBAR_SEL5_SEL11_MASK)
/*! @} */

/*! @name SEL6 - Crossbar Select Register 6 */
/*! @{ */

#define XBAR_SEL6_SEL12_MASK                     (0x3FU)
#define XBAR_SEL6_SEL12_SHIFT                    (0U)
/*! SEL12
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL6_SEL12(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_SEL6_SEL12_SHIFT)) & XBAR_SEL6_SEL12_MASK)

#define XBAR_SEL6_SEL13_MASK                     (0x3F00U)
#define XBAR_SEL6_SEL13_SHIFT                    (8U)
/*! SEL13
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL6_SEL13(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_SEL6_SEL13_SHIFT)) & XBAR_SEL6_SEL13_MASK)
/*! @} */

/*! @name SEL7 - Crossbar Select Register 7 */
/*! @{ */

#define XBAR_SEL7_SEL14_MASK                     (0x3FU)
#define XBAR_SEL7_SEL14_SHIFT                    (0U)
/*! SEL14
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL7_SEL14(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_SEL7_SEL14_SHIFT)) & XBAR_SEL7_SEL14_MASK)

#define XBAR_SEL7_SEL15_MASK                     (0x3F00U)
#define XBAR_SEL7_SEL15_SHIFT                    (8U)
/*! SEL15
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL7_SEL15(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_SEL7_SEL15_SHIFT)) & XBAR_SEL7_SEL15_MASK)
/*! @} */

/*! @name SEL8 - Crossbar Select Register 8 */
/*! @{ */

#define XBAR_SEL8_SEL16_MASK                     (0x3FU)
#define XBAR_SEL8_SEL16_SHIFT                    (0U)
/*! SEL16
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL8_SEL16(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_SEL8_SEL16_SHIFT)) & XBAR_SEL8_SEL16_MASK)

#define XBAR_SEL8_SEL17_MASK                     (0x3F00U)
#define XBAR_SEL8_SEL17_SHIFT                    (8U)
/*! SEL17
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL8_SEL17(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_SEL8_SEL17_SHIFT)) & XBAR_SEL8_SEL17_MASK)
/*! @} */

/*! @name SEL9 - Crossbar Select Register 9 */
/*! @{ */

#define XBAR_SEL9_SEL18_MASK                     (0x3FU)
#define XBAR_SEL9_SEL18_SHIFT                    (0U)
/*! SEL18
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL9_SEL18(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_SEL9_SEL18_SHIFT)) & XBAR_SEL9_SEL18_MASK)

#define XBAR_SEL9_SEL19_MASK                     (0x3F00U)
#define XBAR_SEL9_SEL19_SHIFT                    (8U)
/*! SEL19
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL9_SEL19(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_SEL9_SEL19_SHIFT)) & XBAR_SEL9_SEL19_MASK)
/*! @} */

/*! @name SEL10 - Crossbar Select Register 10 */
/*! @{ */

#define XBAR_SEL10_SEL20_MASK                    (0x3FU)
#define XBAR_SEL10_SEL20_SHIFT                   (0U)
/*! SEL20
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL10_SEL20(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL10_SEL20_SHIFT)) & XBAR_SEL10_SEL20_MASK)

#define XBAR_SEL10_SEL21_MASK                    (0x3F00U)
#define XBAR_SEL10_SEL21_SHIFT                   (8U)
/*! SEL21
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL10_SEL21(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL10_SEL21_SHIFT)) & XBAR_SEL10_SEL21_MASK)
/*! @} */

/*! @name SEL11 - Crossbar Select Register 11 */
/*! @{ */

#define XBAR_SEL11_SEL22_MASK                    (0x3FU)
#define XBAR_SEL11_SEL22_SHIFT                   (0U)
/*! SEL22
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL11_SEL22(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL11_SEL22_SHIFT)) & XBAR_SEL11_SEL22_MASK)

#define XBAR_SEL11_SEL23_MASK                    (0x3F00U)
#define XBAR_SEL11_SEL23_SHIFT                   (8U)
/*! SEL23
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL11_SEL23(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL11_SEL23_SHIFT)) & XBAR_SEL11_SEL23_MASK)
/*! @} */

/*! @name SEL12 - Crossbar Select Register 12 */
/*! @{ */

#define XBAR_SEL12_SEL24_MASK                    (0x3FU)
#define XBAR_SEL12_SEL24_SHIFT                   (0U)
/*! SEL24
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL12_SEL24(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL12_SEL24_SHIFT)) & XBAR_SEL12_SEL24_MASK)

#define XBAR_SEL12_SEL25_MASK                    (0x3F00U)
#define XBAR_SEL12_SEL25_SHIFT                   (8U)
/*! SEL25
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL12_SEL25(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL12_SEL25_SHIFT)) & XBAR_SEL12_SEL25_MASK)
/*! @} */

/*! @name SEL13 - Crossbar Select Register 13 */
/*! @{ */

#define XBAR_SEL13_SEL26_MASK                    (0x3FU)
#define XBAR_SEL13_SEL26_SHIFT                   (0U)
/*! SEL26
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL13_SEL26(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL13_SEL26_SHIFT)) & XBAR_SEL13_SEL26_MASK)

#define XBAR_SEL13_SEL27_MASK                    (0x3F00U)
#define XBAR_SEL13_SEL27_SHIFT                   (8U)
/*! SEL27
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL13_SEL27(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL13_SEL27_SHIFT)) & XBAR_SEL13_SEL27_MASK)
/*! @} */

/*! @name SEL14 - Crossbar Select Register 14 */
/*! @{ */

#define XBAR_SEL14_SEL28_MASK                    (0x3FU)
#define XBAR_SEL14_SEL28_SHIFT                   (0U)
/*! SEL28
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL14_SEL28(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL14_SEL28_SHIFT)) & XBAR_SEL14_SEL28_MASK)

#define XBAR_SEL14_SEL29_MASK                    (0x3F00U)
#define XBAR_SEL14_SEL29_SHIFT                   (8U)
/*! SEL29
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL14_SEL29(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL14_SEL29_SHIFT)) & XBAR_SEL14_SEL29_MASK)
/*! @} */

/*! @name SEL15 - Crossbar Select Register 15 */
/*! @{ */

#define XBAR_SEL15_SEL30_MASK                    (0x3FU)
#define XBAR_SEL15_SEL30_SHIFT                   (0U)
/*! SEL30
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL15_SEL30(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL15_SEL30_SHIFT)) & XBAR_SEL15_SEL30_MASK)

#define XBAR_SEL15_SEL31_MASK                    (0x3F00U)
#define XBAR_SEL15_SEL31_SHIFT                   (8U)
/*! SEL31
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL15_SEL31(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL15_SEL31_SHIFT)) & XBAR_SEL15_SEL31_MASK)
/*! @} */

/*! @name SEL16 - Crossbar Select Register 16 */
/*! @{ */

#define XBAR_SEL16_SEL32_MASK                    (0x3FU)
#define XBAR_SEL16_SEL32_SHIFT                   (0U)
/*! SEL32
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL16_SEL32(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL16_SEL32_SHIFT)) & XBAR_SEL16_SEL32_MASK)

#define XBAR_SEL16_SEL33_MASK                    (0x3F00U)
#define XBAR_SEL16_SEL33_SHIFT                   (8U)
/*! SEL33
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL16_SEL33(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL16_SEL33_SHIFT)) & XBAR_SEL16_SEL33_MASK)
/*! @} */

/*! @name SEL17 - Crossbar Select Register 17 */
/*! @{ */

#define XBAR_SEL17_SEL34_MASK                    (0x3FU)
#define XBAR_SEL17_SEL34_SHIFT                   (0U)
/*! SEL34
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL17_SEL34(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL17_SEL34_SHIFT)) & XBAR_SEL17_SEL34_MASK)

#define XBAR_SEL17_SEL35_MASK                    (0x3F00U)
#define XBAR_SEL17_SEL35_SHIFT                   (8U)
/*! SEL35
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL17_SEL35(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL17_SEL35_SHIFT)) & XBAR_SEL17_SEL35_MASK)
/*! @} */

/*! @name SEL18 - Crossbar Select Register 18 */
/*! @{ */

#define XBAR_SEL18_SEL36_MASK                    (0x3FU)
#define XBAR_SEL18_SEL36_SHIFT                   (0U)
/*! SEL36
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL18_SEL36(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL18_SEL36_SHIFT)) & XBAR_SEL18_SEL36_MASK)

#define XBAR_SEL18_SEL37_MASK                    (0x3F00U)
#define XBAR_SEL18_SEL37_SHIFT                   (8U)
/*! SEL37
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL18_SEL37(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL18_SEL37_SHIFT)) & XBAR_SEL18_SEL37_MASK)
/*! @} */

/*! @name SEL19 - Crossbar Select Register 19 */
/*! @{ */

#define XBAR_SEL19_SEL38_MASK                    (0x3FU)
#define XBAR_SEL19_SEL38_SHIFT                   (0U)
/*! SEL38
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL19_SEL38(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL19_SEL38_SHIFT)) & XBAR_SEL19_SEL38_MASK)

#define XBAR_SEL19_SEL39_MASK                    (0x3F00U)
#define XBAR_SEL19_SEL39_SHIFT                   (8U)
/*! SEL39
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL19_SEL39(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL19_SEL39_SHIFT)) & XBAR_SEL19_SEL39_MASK)
/*! @} */

/*! @name SEL20 - Crossbar Select Register 20 */
/*! @{ */

#define XBAR_SEL20_SEL40_MASK                    (0x3FU)
#define XBAR_SEL20_SEL40_SHIFT                   (0U)
/*! SEL40
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL20_SEL40(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL20_SEL40_SHIFT)) & XBAR_SEL20_SEL40_MASK)

#define XBAR_SEL20_SEL41_MASK                    (0x3F00U)
#define XBAR_SEL20_SEL41_SHIFT                   (8U)
/*! SEL41
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL20_SEL41(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL20_SEL41_SHIFT)) & XBAR_SEL20_SEL41_MASK)
/*! @} */

/*! @name SEL21 - Crossbar Select Register 21 */
/*! @{ */

#define XBAR_SEL21_SEL42_MASK                    (0x3FU)
#define XBAR_SEL21_SEL42_SHIFT                   (0U)
/*! SEL42
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL21_SEL42(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL21_SEL42_SHIFT)) & XBAR_SEL21_SEL42_MASK)

#define XBAR_SEL21_SEL43_MASK                    (0x3F00U)
#define XBAR_SEL21_SEL43_SHIFT                   (8U)
/*! SEL43
 *  0b000000..Logic 1 (VDD)
 *  0b000001..Logic 0 (VSS)
 *  0b000010..AFE modulator clock output
 *  0b000011..AFE modulator 0 data output
 *  0b000100..LPTimer Output
 *  0b000101..Clock Output
 *  0b000110..Quad Timer channel 0 output
 *  0b000111..Quad Timer channel 1 output
 *  0b001000..Quad Timer channel 2 output
 *  0b001001..Quad Timer channel 3 output
 *  0b001010..iRTC Clock Output
 *  0b001011..CMP0 Output
 *  0b001100..CMP1 Output
 *  0b001101..iRTC Alarm Output
 *  0b001110..UART TX Output (after modulation)
 *  0b001111..EWM Output (EWM_OUT)
 *  0b010000..PIT 0 Timer Interrupt Flag 0 (Timeout 0)
 *  0b010001..XBAR Input pin 0
 *  0b010010..XBAR Input pin 1
 *  0b010011..XBAR Input pin 2
 *  0b010100..XBAR Input pin 3
 *  0b010101..XBAR Input pin 4
 *  0b010110..XBAR Input pin 5
 *  0b010111..XBAR Input pin 6
 *  0b011000..XBAR Input pin 7
 *  0b011001..XBAR Input pin 8
 *  0b011010..ORed conversion complete flag for all SAR ADC channels
 *  0b011011..ORed conversion complete flag for all AFE channels
 *  0b011100..AFE Channel 0 conversion complete
 *  0b011101..AFE Channel 1 conversion complete
 *  0b011110..AFE Channel 2 conversion complete
 *  0b011111..AFE Channel 3 conversion complete
 *  0b100000..DMA Done Signal
 *  0b100001..XBAR Input pin 9
 *  0b100010..XBAR Input pin 10
 *  0b100011..CMP2 Output
 *  0b100100..PIT 0 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100101..PIT 1 Timer Interrupt Flag 0 (Timeout 0)
 *  0b100110..PIT 1 Timer Interrupt Flag 1 (Timeout 1)
 *  0b100111..AFE modulator 1 data output
 *  0b101000..AFE modulator 2 data output
 *  0b101001..AFE modulator 3 data output
 *  0b101010..SAR ADC conversion complete A
 *  0b101011..SAR ADC conversion complete B
 *  0b101100..SAR ADC conversion complete C
 *  0b101101..SAR ADC conversion complete D
 *  0b101110..PDB0 CH0 Pre-trigger 0
 *  0b101111..PDB0 CH0 Pre-trigger 1
 *  0b110000..PDB0 CH0 Pre-trigger 2
 *  0b110001..PDB0 CH0 Pre-trigger 3
 *  0b110010..PDB0 CH0 Trigger
 *  0b110011..PDB0 Pulse-Out 0
 */
#define XBAR_SEL21_SEL43(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_SEL21_SEL43_SHIFT)) & XBAR_SEL21_SEL43_MASK)
/*! @} */

/*! @name CTRL0 - Crossbar Control Register 0 */
/*! @{ */

#define XBAR_CTRL0_DEN0_MASK                     (0x1U)
#define XBAR_CTRL0_DEN0_SHIFT                    (0U)
/*! DEN0 - DMA Enable for XBAR_OUT0
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_CTRL0_DEN0(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL0_DEN0_SHIFT)) & XBAR_CTRL0_DEN0_MASK)

#define XBAR_CTRL0_IEN0_MASK                     (0x2U)
#define XBAR_CTRL0_IEN0_SHIFT                    (1U)
/*! IEN0 - Interrupt Enable for XBAR_OUT0
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_CTRL0_IEN0(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL0_IEN0_SHIFT)) & XBAR_CTRL0_IEN0_MASK)

#define XBAR_CTRL0_EDGE0_MASK                    (0xCU)
#define XBAR_CTRL0_EDGE0_SHIFT                   (2U)
/*! EDGE0 - Active edge for edge detection on XBAR_OUT0
 *  0b00..STS0 never asserts
 *  0b01..STS0 asserts on rising edges of XBAR_OUT0
 *  0b10..STS0 asserts on falling edges of XBAR_OUT0
 *  0b11..STS0 asserts on rising and falling edges of XBAR_OUT0
 */
#define XBAR_CTRL0_EDGE0(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL0_EDGE0_SHIFT)) & XBAR_CTRL0_EDGE0_MASK)

#define XBAR_CTRL0_STS0_MASK                     (0x10U)
#define XBAR_CTRL0_STS0_SHIFT                    (4U)
/*! STS0 - Edge detection status for XBAR_OUT0
 *  0b0..Active edge not yet detected on XBAR_OUT0
 *  0b1..Active edge detected on XBAR_OUT0
 */
#define XBAR_CTRL0_STS0(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL0_STS0_SHIFT)) & XBAR_CTRL0_STS0_MASK)

#define XBAR_CTRL0_DEN1_MASK                     (0x100U)
#define XBAR_CTRL0_DEN1_SHIFT                    (8U)
/*! DEN1 - DMA Enable for XBAR_OUT1
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_CTRL0_DEN1(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL0_DEN1_SHIFT)) & XBAR_CTRL0_DEN1_MASK)

#define XBAR_CTRL0_IEN1_MASK                     (0x200U)
#define XBAR_CTRL0_IEN1_SHIFT                    (9U)
/*! IEN1 - Interrupt Enable for XBAR_OUT1
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_CTRL0_IEN1(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL0_IEN1_SHIFT)) & XBAR_CTRL0_IEN1_MASK)

#define XBAR_CTRL0_EDGE1_MASK                    (0xC00U)
#define XBAR_CTRL0_EDGE1_SHIFT                   (10U)
/*! EDGE1 - Active edge for edge detection on XBAR_OUT1
 *  0b00..STS1 never asserts
 *  0b01..STS1 asserts on rising edges of XBAR_OUT1
 *  0b10..STS1 asserts on falling edges of XBAR_OUT1
 *  0b11..STS1 asserts on rising and falling edges of XBAR_OUT1
 */
#define XBAR_CTRL0_EDGE1(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL0_EDGE1_SHIFT)) & XBAR_CTRL0_EDGE1_MASK)

#define XBAR_CTRL0_STS1_MASK                     (0x1000U)
#define XBAR_CTRL0_STS1_SHIFT                    (12U)
/*! STS1 - Edge detection status for XBAR_OUT1
 *  0b0..Active edge not yet detected on XBAR_OUT1
 *  0b1..Active edge detected on XBAR_OUT1
 */
#define XBAR_CTRL0_STS1(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL0_STS1_SHIFT)) & XBAR_CTRL0_STS1_MASK)
/*! @} */

/*! @name CTRL1 - Crossbar Control Register 1 */
/*! @{ */

#define XBAR_CTRL1_DEN2_MASK                     (0x1U)
#define XBAR_CTRL1_DEN2_SHIFT                    (0U)
/*! DEN2 - DMA Enable for XBAR_OUT2
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_CTRL1_DEN2(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL1_DEN2_SHIFT)) & XBAR_CTRL1_DEN2_MASK)

#define XBAR_CTRL1_IEN2_MASK                     (0x2U)
#define XBAR_CTRL1_IEN2_SHIFT                    (1U)
/*! IEN2 - Interrupt Enable for XBAR_OUT2
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_CTRL1_IEN2(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL1_IEN2_SHIFT)) & XBAR_CTRL1_IEN2_MASK)

#define XBAR_CTRL1_EDGE2_MASK                    (0xCU)
#define XBAR_CTRL1_EDGE2_SHIFT                   (2U)
/*! EDGE2 - Active edge for edge detection on XBAR_OUT2
 *  0b00..STS2 never asserts
 *  0b01..STS2 asserts on rising edges of XBAR_OUT2
 *  0b10..STS2 asserts on falling edges of XBAR_OUT2
 *  0b11..STS2 asserts on rising and falling edges of XBAR_OUT2
 */
#define XBAR_CTRL1_EDGE2(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL1_EDGE2_SHIFT)) & XBAR_CTRL1_EDGE2_MASK)

#define XBAR_CTRL1_STS2_MASK                     (0x10U)
#define XBAR_CTRL1_STS2_SHIFT                    (4U)
/*! STS2 - Edge detection status for XBAR_OUT2
 *  0b0..Active edge not yet detected on XBAR_OUT2
 *  0b1..Active edge detected on XBAR_OUT2
 */
#define XBAR_CTRL1_STS2(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL1_STS2_SHIFT)) & XBAR_CTRL1_STS2_MASK)

#define XBAR_CTRL1_DEN3_MASK                     (0x100U)
#define XBAR_CTRL1_DEN3_SHIFT                    (8U)
/*! DEN3 - DMA Enable for XBAR_OUT3
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_CTRL1_DEN3(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL1_DEN3_SHIFT)) & XBAR_CTRL1_DEN3_MASK)

#define XBAR_CTRL1_IEN3_MASK                     (0x200U)
#define XBAR_CTRL1_IEN3_SHIFT                    (9U)
/*! IEN3 - Interrupt Enable for XBAR_OUT3
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_CTRL1_IEN3(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL1_IEN3_SHIFT)) & XBAR_CTRL1_IEN3_MASK)

#define XBAR_CTRL1_EDGE3_MASK                    (0xC00U)
#define XBAR_CTRL1_EDGE3_SHIFT                   (10U)
/*! EDGE3 - Active edge for edge detection on XBAR_OUT3
 *  0b00..STS3 never asserts
 *  0b01..STS3 asserts on rising edges of XBAR_OUT3
 *  0b10..STS3 asserts on falling edges of XBAR_OUT3
 *  0b11..STS3 asserts on rising and falling edges of XBAR_OUT3
 */
#define XBAR_CTRL1_EDGE3(x)                      (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL1_EDGE3_SHIFT)) & XBAR_CTRL1_EDGE3_MASK)

#define XBAR_CTRL1_STS3_MASK                     (0x1000U)
#define XBAR_CTRL1_STS3_SHIFT                    (12U)
/*! STS3 - Edge detection status for XBAR_OUT3
 *  0b0..Active edge not yet detected on XBAR_OUT3
 *  0b1..Active edge detected on XBAR_OUT3
 */
#define XBAR_CTRL1_STS3(x)                       (((uint16_t)(((uint16_t)(x)) << XBAR_CTRL1_STS3_SHIFT)) & XBAR_CTRL1_STS3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XBAR_Register_Masks */


/*!
 * @}
 */ /* end of group XBAR_Peripheral_Access_Layer */


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


#endif  /* PERI_XBAR_H_ */

